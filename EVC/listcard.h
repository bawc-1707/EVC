#ifndef LISTCARD_H
#define LISTCARD_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <nfc/nfc.h>
#include <nfc/nfc-types.h>
#include <QTimer>
#include <QApplication>
#include "nfcworker.h"
#include "notion.h"
#include <QThread>


namespace Ui {
class ListCard;
}

class ListCard : public QMainWindow
{
    Q_OBJECT

public:
    explicit ListCard(QWidget *parent = nullptr);
    ~ListCard();
public slots:
    void backmenu();
signals:
    void backscreen();
private slots:
    void onfocusChanged(QWidget *oldWidget, QWidget *newWidget);

    void on_ButtonRemove_clicked();

private:
    Ui::ListCard *listcard;
    QSqlDatabase db;


    nfc_device *pnd;
    nfc_context *context;
    Notion *notion;

    void handleNFCDetected(const QString &uid);
    bool isUidValid(const QString &uid);
    void save_to_database(const QString &uid);
    void updateUIDfields();
    void addnfccard();
};

#endif // LISTCARD_H
