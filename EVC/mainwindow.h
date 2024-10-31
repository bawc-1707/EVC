#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QLCDNumber>
#include <QTimer>
#include <QTime>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QScreen>
#include "nfcworker.h"
#include <QThread>
#include "menuwindow.h"
#include "notion.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QString uidt, const QString date ,QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void handleMenuClose();
    void handleCheckNFC(const QString &uid);
    void handleNFCdetected(const QString &uid);
    void handleDetected(const QString &uid);
    void backdisplay();
    void clickedmenu();
private slots:
    void readData();

    void on_Buttonstop_clicked();

signals:
    void backscreen();
private:
    Ui::MainWindow *mainwindow;
    MenuWindow *menuwindow;
    Notion *notion;
    QSerialPort *serial;
    QString UID;
    QString date;
    QTimer *timer;
    float kWh;
    nfc_device *pnd;
    nfc_context *context;
    bool ispermission;

    bool isUidValid(const QString &uid);
    void sendSignal(const QString &signal);
    void uptime();
    void downtime();
    void startCoutdown();
    void updateCoutdown();
    void addhistorydata(const QString &uid, const QString &date, float kWh);
    void handleReadData(QString dataStr);
    void handleSendAmpe();
    void handleCheckPermission(QString dataStr);
    void handleDisconnect();
    void sendAmpe();
};

#endif // MAINWINDOW_H
