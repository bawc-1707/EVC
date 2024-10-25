#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(const QString uidt, const QString date,QWidget *parent)
    : QMainWindow(parent)
    , mainwindow(new Ui::MainWindow)
    , menuwindow(nullptr)
    , notion(nullptr)
    , UID(uidt)
    , date(date)
{
    mainwindow->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);
    showFullScreen();

    mainwindow->timeEdit->setReadOnly(true);
    mainwindow->timeEdit->setFocusPolicy(Qt::NoFocus);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/pi/app/Database/nfc_database.db");
    if(!db.open()){
        qDebug() << "Can't connect with database:" << db.lastError();
        return;
    }

    nfc_init(&context);
    if(context == nullptr){
        qDebug() << "Khong the khoi tao nfc" << Qt::endl;
        return;
    }
    pnd = nfc_open(context, nullptr);
    if(pnd == nullptr){
        qDebug() << "Khong the mo thiet bi nfc" << Qt::endl;
        return;
    }
    if(nfc_initiator_init(pnd) < 0){
        nfc_close(pnd);
        nfc_exit(context);
        qDebug() << "Khong the khoi tao thiet bi nfc" << Qt::endl;
        return;
    }

    serial = new QSerialPort(this);
    serial->setPortName("/dev/ttyAMA0");
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    if(!serial->open(QIODevice::ReadWrite)){
        qDebug() << "Khong the mo serialport" << Qt::endl;
    }
    mainwindow->Buttonstop->setEnabled(false);
    mainwindow->Buttonstart->setEnabled(true);
    mainwindow->Buttonuptime->setEnabled(true);
    mainwindow->Buttondowntime->setEnabled(true);
    mainwindow->ButtonBack->setEnabled(true);
    mainwindow->Buttonmenu->setEnabled(true);
    timer = new QTimer(this);
    timer1 = new QTimer(this);
    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(mainwindow->Buttonuptime, &QPushButton::clicked, this, &MainWindow::uptime);
    connect(mainwindow->Buttondowntime, &QPushButton::clicked, this, &MainWindow::downtime);
    connect(mainwindow->ButtonBack, &QPushButton::clicked, this, &MainWindow::backdisplay);
    connect(mainwindow->Buttonmenu, &QPushButton::clicked, this, &MainWindow::clickedmenu);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateCoutdown);
    connect(timer1, &QTimer::timeout, this, &MainWindow::sendREADsignal);
    timer1->start(1000);
}

MainWindow::~MainWindow()
{
    if(serial->isOpen()){
        delete serial;
    }
    nfc_close(pnd);
    nfc_exit(context);
    delete mainwindow;
}

void MainWindow::backdisplay(){
    qDebug() << "Tro ve displayscreen";
    emit backscreen();
}

void MainWindow::sendSignal(const QString &signal){
    if(serial->isOpen()){
        serial->write(signal.toUtf8());
    }
    else {
        qDebug() << "Cong serial khong mo" << Qt::endl;
    }
}

void MainWindow::sendREADsignal(){
    sendSignal("READ0");
}


void MainWindow::on_Buttonstart_clicked()
{

    mainwindow->Buttonstop->setEnabled(true);
    mainwindow->Buttonstart->setEnabled(false);
    mainwindow->Buttonuptime->setEnabled(false);
    mainwindow->Buttondowntime->setEnabled(false);
    mainwindow->ButtonBack->setEnabled(false);
    mainwindow->Buttonmenu->setEnabled(false);
    QTime currenttime = mainwindow->timeEdit->time();
    if(currenttime == QTime(0, 0, 0) ){
        sendSignal("ON000");
    }
    else{
        sendSignal("ON000");
        startCoutdown();
    }
}

void MainWindow::startCoutdown(){
    timer->start(1000);
}

void MainWindow::updateCoutdown(){
    QTime currenttime = mainwindow->timeEdit->time();
    if(currenttime == QTime(0, 0, 0) ){
        timer->stop();
        sendSignal("OFF00");
        addhistorydata(UID, date, kWh);
    }
    else{
        currenttime = currenttime.addSecs(-1);
        mainwindow->timeEdit->setTime(currenttime);
    }
}

void MainWindow::on_Buttonstop_clicked()
{
    QTime currenttime = mainwindow->timeEdit->time();
    if(currenttime != QTime(0, 0, 0)){
        notion = new Notion(this);

        notion->setModal(true);
        notion->show();

        notion->notionchecknfc();
        NFCWorker *worker = new NFCWorker(pnd);
        QThread *thread = new QThread;
        connect(worker, &NFCWorker::nfcDetected, this, &MainWindow::handleDetected);
        connect(thread, &QThread::finished, worker, &NFCWorker::deleteLater);
        connect(thread, &QThread::finished, thread, &QThread::deleteLater);
        worker->moveToThread(thread);
        connect(thread, &QThread::started, worker, &NFCWorker::checkNfc);
        thread->start();
    }else{
        kWh = static_cast<float>(mainwindow->NumberkWh->value());
        sendSignal("OFF00");
        addhistorydata(UID, date, kWh);
    }
    mainwindow->Buttonstop->setEnabled(false);
    mainwindow->Buttonstart->setEnabled(true);
    mainwindow->Buttonuptime->setEnabled(true);
    mainwindow->Buttondowntime->setEnabled(true);
    mainwindow->ButtonBack->setEnabled(true);
    mainwindow->Buttonmenu->setEnabled(true);
}

void MainWindow::handleDetected(const QString &uid){
    if (isUidValid(uid)) {
        float kWh = static_cast<float>(mainwindow->NumberkWh->value());
        notion->close();
        sendSignal("OFF00");
        addhistorydata(uid, date, kWh);
        qDebug() << "Dung qua trinh tuc thoi" << Qt::endl;

        QTime currenttime = QTime(0, 0, 0);
        mainwindow->timeEdit->setTime(currenttime);
    } else {
        notion->notionwrongnfc();
        qDebug() << "The NFC khong hop le";
    }
}

bool MainWindow::isUidValid(const QString &uid){
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM nfc_data WHERE uid = :uid");
    query.bindValue(":uid", uid);
    if(query.exec()){
        if(query.next()){
            int count = query.value(0).toInt();
            return (count > 0);
        }
    }
    else {
        qDebug() << "Loi truy cap co so du lieu: " << query.lastError();
    }
    return false;
}

void MainWindow::readData(){

        QByteArray data = serial->readAll();

        QString dataStr = QString::fromUtf8(data).trimmed();
        QStringList values = dataStr.split(',', Qt::SkipEmptyParts);


        if (values.size() == 8) {
            bool conversionOk = true;
            double displayValues[8];

            for (int i = 0; i < 8; ++i) {
                displayValues[i] = values[i].toDouble(&conversionOk);
                if (!conversionOk) {
                    qDebug() << "Loi chuyen doi du lieu:" << values[i];
                    return;
                }
            }

            mainwindow->NumberVa->display(displayValues[0]);
            mainwindow->NumberVb->display(displayValues[1]);
            mainwindow->NumberVc->display(displayValues[2]);
            mainwindow->NumberIa->display(displayValues[3]);
            mainwindow->NumberIb->display(displayValues[4]);
            mainwindow->NumberIc->display(displayValues[5]);
            mainwindow->NumberP->display(displayValues[6]);
            mainwindow->NumberkWh->display(displayValues[7]);

        } else {
            qDebug() << "Du lieu khong du hoac khong hop le:" << dataStr;
        }
}
void MainWindow::clickedmenu()
{
    notion = new Notion(this);
    notion->setModal(true);
    notion->show();

    notion->notionchecknfc();
    qDebug() << "Nut nhan menu";

    QThread *nfcthread = new QThread;
    NFCWorker *nfcworker = new NFCWorker(pnd);
    connect(nfcworker, &NFCWorker::nfcDetected, this, &MainWindow::handleNFCdetected);
    connect(nfcthread, &QThread::finished, nfcworker, &NFCWorker::deleteLater);
    connect(nfcthread, &QThread::finished, nfcthread, &QThread::deleteLater);
    nfcworker->moveToThread(nfcthread);
    connect(nfcthread, &QThread::started, nfcworker, &NFCWorker::checkNfc);
    nfcthread->start();
}

void MainWindow::handleNFCdetected(const QString &uid) {
    if (isUidValid(uid)) {
        if (!menuwindow) {
            menuwindow = new MenuWindow;
            menuwindow->show();
            connect(menuwindow, &MenuWindow::backscreen, this, &MainWindow::handleMenuClose);
            notion->close();
            this->close();
            qDebug() << "Mo menu";
        }
    } else {
        notion->notionwrongnfc();
        qDebug() << "The NFC khong hop le";
    }
}

void MainWindow::handleMenuClose(){
    this->show();
    delete menuwindow;
    menuwindow = nullptr;
}

void MainWindow::addhistorydata(const QString &uid, const QString &date, float kWh){
    QSqlQuery query;
    query.prepare("UPDATE history SET kWh = :kWh WHERE UID = :uid AND date = :date");
    query.bindValue(":uid", uid);
    query.bindValue(":date", date);
    query.bindValue(":kWh", kWh);
    if(!query.exec()){
        qDebug() << "Loi khi them du lieu vao bang" << query.lastError() << Qt::endl;
    }
    else {
        qDebug() << "Them du lieu vao bang thanh cong";
    }
}

void MainWindow::uptime(){
    QTime currenttime = mainwindow->timeEdit->time();
    currenttime = currenttime.addSecs(15*60);
    mainwindow->timeEdit->setTime(currenttime);
}

void MainWindow::downtime(){
    QTime currenttime = mainwindow->timeEdit->time();
    int totalSeconds = currenttime.hour()*3600 + currenttime.minute()*60 + currenttime.second();
    if(totalSeconds > 15*60 ){
        currenttime = currenttime.addSecs(-15*60);
    }
    else{
        currenttime.setHMS(0, 0, 0);
    }
    mainwindow->timeEdit->setTime(currenttime);
}
