#include "history.h"
#include "ui_history.h"

History::History(QWidget *parent) :
    QMainWindow(parent),
    history(new Ui::History)
{
    history->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);
    showFullScreen();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/pi/app/Database/nfc_database.db");
    if(!db.open()){
        qDebug() << "Can't connect with database:" << db.lastError();
        return;
    }
    QList<HistoryData> historyList = fetchHistoryData();
    populatetable(historyList);
    connect(history->ButtonBack, &QPushButton::clicked, this, &History::backmenu);
}

History::~History()
{
    delete history;
    this->close();
}

QList<HistoryData> History::fetchHistoryData() {
    QList<HistoryData> historyList;
    QSqlQuery query("SELECT UID, date, kWh FROM history");

    while (query.next()) {
        HistoryData data;
        data.uid = query.value(0).toString();
        data.date = query.value(1).toString();
        data.kWh = query.value(2).toDouble();
        historyList.append(data);
    }
    return historyList;
}

void History::populatetable(const QList<HistoryData> &historyList) {
    history->tableWidget->setRowCount(historyList.size());  // Đặt số dòng bằng số phần tử trong historyList

    // Lặp qua danh sách và thêm từng giá trị vào bảng
    for (int i = 0; i < historyList.size(); ++i) {
        const HistoryData &data = historyList.at(i);

        history->tableWidget->setItem(i, 0, new QTableWidgetItem(data.uid));
        history->tableWidget->setItem(i, 1, new QTableWidgetItem(data.date));
        history->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(data.kWh)));
    }
}

void History::backmenu(){
    emit backscreen();
}
