#ifndef HISTORY_H
#define HISTORY_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QList>
#include <QTableWidgetItem>

namespace Ui {
class History;
}
struct HistoryData
{
    QString uid;
    QString date;
    double kWh;
};
class History : public QMainWindow
{
    Q_OBJECT

public:
    explicit History(QWidget *parent = nullptr);
    ~History();
    QList<HistoryData> fetchHistoryData();
    void populatetable(const QList<HistoryData> &historyList);
public slots:
    void backmenu();
signals:
    void backscreen();
private:
    Ui::History *history;
};

#endif // HISTORY_H
