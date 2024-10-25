#include "displaywindow.h"
#include "ui_displaywindow.h"

DisplayWindow::DisplayWindow(QWidget *parent) :
    QMainWindow(parent),
    displaywindow(new Ui::DisplayWindow),
    mainwindow(nullptr)
{
    displaywindow->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);
    showFullScreen();

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/pi/app/Database/nfc_database.db");
    if(!db.open()){
        qDebug() << "Can't connect with database:" << db.lastError();
        return;
    }

    checknfc();
}

DisplayWindow::~DisplayWindow()
{
    db.close();// Xóa thread an toàn
    nfc_close(pnd);
    nfc_exit(context);
    delete displaywindow;
}

void DisplayWindow::openmainwindow(const QString &uid, const QString &date){

    mainwindow = new MainWindow(uid, date);
    mainwindow->show();
    connect(mainwindow, &MainWindow::backscreen, this, &DisplayWindow::handlebackdisplay);
    this->close();

}

void DisplayWindow::checknfc(){
    NFCWorker *worker = new NFCWorker(pnd);
    QThread *thread = new QThread(this);
    worker->moveToThread(thread);
    connect(worker, &NFCWorker::nfcDetected, this, &DisplayWindow::handleNFCDetected);
    connect(thread, &QThread::finished, worker, &NFCWorker::deleteLater);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);
    connect(thread, &QThread::started, worker, &NFCWorker::checkNfc);
    thread->start();
}

void DisplayWindow::handlebackdisplay(){
    checknfc();
    this->show();
    delete mainwindow;
    mainwindow = nullptr;
}

void DisplayWindow::handleNFCDetected(const QString &uid){
    if(isUidValid(uid)){
        if(!mainwindow){
            QDateTime current = QDateTime::currentDateTime();
            QString date = current.toString("dd/MM/yyyy:HH:mm");
            addhistorydata(uid,date);
            openmainwindow(uid,date);
            qDebug() << "Mo man hinh chinh" << Qt::endl;
        }else{
            qDebug() << "Man hinh chinh da mo";
        }
    }
    else{
        Notion *notion = new Notion(this);
        notion->setModal(true);
        notion->show();
        notion->notionwrongnfc();
        checknfc();
        qDebug() << "The NFC khong hop le" << Qt::endl;
    }
}

bool DisplayWindow::isUidValid(const QString &uid){
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

void DisplayWindow::addhistorydata(const QString &uid, const QString &date){
    QSqlQuery query;
    QString createTable = R"(
        CREATE TABLE IF NOT EXISTS history (
            UID TEXT NOT NULL,
            date TEXT NOT NULL,
            kWh REAL NOT NULL
        )
    )";
    if (!query.exec(createTable)) {
        qDebug() << "Không thể tạo bảng: " << query.lastError() << Qt::endl;
        return;
    }
    query.prepare("INSERT INTO history (UID, date, kWh) VALUES (:uid, :date, :kWh)");
    query.bindValue(":uid", uid);
    query.bindValue(":date", date);
    query.bindValue(":kWh", 0);
    if(!query.exec()){
        qDebug() << "Loi khi them du lieu vao bang" << query.lastError() << Qt::endl;
    }
    else {
        qDebug() << "Them du lieu vao bang thanh cong";
    }
}

