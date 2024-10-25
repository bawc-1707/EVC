#include "listcard.h"
#include "ui_listcard.h"
#include <QDebug>

QString selectUID;

ListCard::ListCard(QWidget *parent) :
    QMainWindow(parent),
    listcard(new Ui::ListCard)
{
    listcard->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);
    showFullScreen();

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/pi/app/Database/nfc_database.db");
    if(!db.open()){
        qDebug() << "Can't connect with database:" << db.lastError();
        return;
    }

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ListCard::updateUIDfields);
    timer->start(5000);

    updateUIDfields();
    connect(qApp, &QApplication::focusChanged, this, &ListCard::onfocusChanged);
    connect(listcard->ButtonBack, &QPushButton::clicked, this, &ListCard::backmenu);
    connect(listcard->ButtonADD, &QPushButton::clicked, this, &ListCard::addnfccard);
}

ListCard::~ListCard()
{
    db.close();
    nfc_close(pnd);
    nfc_exit(context);
    delete listcard;
}

void ListCard::onfocusChanged(QWidget *oldWidget, QWidget *newWidget){
    if(QLineEdit *lineEdit = qobject_cast<QLineEdit *>(newWidget)){
        QString objName = lineEdit->objectName();
        if(objName.startsWith("lineEditUID")){
            selectUID = lineEdit->text();
            qDebug() << "Da chon UID:" << selectUID;
        }
    }
}

void ListCard::backmenu(){
    disconnect(qApp, &QApplication::focusChanged, this, &ListCard::onfocusChanged);
    emit backscreen();
}

void ListCard::updateUIDfields(){
    QSqlQuery query;
    query.exec("SELECT uid FROM nfc_data LIMIT 9");

    int index = 1;
    while (query.next() && index <= 9) {
        QString uid = query.value(0).toString();
        QLineEdit *lineEdit = findChild<QLineEdit *>(QString("lineEditUID%1").arg(index));
        if (lineEdit) {
            lineEdit->setText(uid);
        }
        index++;
    }
    while (index <= 9) {
    QLineEdit *lineEdit = findChild<QLineEdit *>(QString("lineEditUID%1").arg(index));
    if (lineEdit) {
        lineEdit->clear();
    }
    index++;
    }
}

void ListCard::addnfccard()
{
    notion = new Notion(this);
    notion->show();
    notion->notionchecknfc();
    qDebug() << "Nut nhan add";

    QThread *nfcthread = new QThread;
    NFCWorker *nfcworker = new NFCWorker(pnd);
    connect(nfcworker, &NFCWorker::nfcDetected, this, &ListCard::handleNFCDetected);
    connect(nfcthread, &QThread::finished, nfcworker, &NFCWorker::deleteLater);
    connect(nfcthread, &QThread::finished, nfcthread, &QThread::deleteLater);
    nfcworker->moveToThread(nfcthread);
    connect(nfcthread, &QThread::started, nfcworker, &NFCWorker::checkNfc);
    nfcthread->start();
}

void ListCard::handleNFCDetected(const QString &uid){
    if(isUidValid(uid)){
        notion->notionavaliablenfc();
        qDebug() << "UID đã tồn tại trong kho lưu trữ." << Qt::endl;
    }
    else{
        notion->notionaddnfc();
        save_to_database(uid);
    }

}

bool ListCard::isUidValid(const QString &uid){
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

void ListCard::save_to_database(const QString &uid){
    QSqlQuery query;
    QString createTable = R"(
        CREATE TABLE IF NOT EXISTS nfc_data (
            tên TEXT,
            UID TEXT PRIMARY KEY
        )
    )";
    if (!query.exec(createTable)) {
        qDebug() << "Không thể tạo bảng: " << query.lastError() << Qt::endl;
        return;
    }

    QString sql = QString("INSERT INTO nfc_data (tên, UID) VALUES ('unknown', '%1');").arg(uid);
    if (!query.exec(sql)) {
        qDebug() << "Lỗi khi chèn dữ liệu: " << query.lastError() << Qt::endl;
    } else {
        qDebug() << "Dữ liệu được lưu thành công!" << Qt::endl;
    }
}

void ListCard::on_ButtonRemove_clicked()
{
    if(selectUID.isEmpty()){
        qDebug() << "Warning! No UID selected";
        return;
    }
    QSqlQuery query;
    query.prepare("DELETE FROM nfc_data WHERE UID = :uid");
    query.bindValue(":uid", selectUID);

    if (!query.exec()) {
        qDebug() << "Loi khi xoa du lieu" << query.lastError() << Qt::endl;
    } else {
        qDebug() << "Du lieu da duoc xoa" << Qt::endl;
    }
}

