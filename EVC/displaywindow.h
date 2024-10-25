#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDateTime>
#include "nfcworker.h"
#include <QThread>
#include "notion.h"

namespace Ui {
class DisplayWindow;
}

class DisplayWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DisplayWindow(QWidget *parent = nullptr);
    ~DisplayWindow();
public slots:
    void handlebackdisplay();
private:
    Ui::DisplayWindow *displaywindow;
    MainWindow *mainwindow;
    QSqlDatabase db;

    nfc_device *pnd;
    nfc_context *context;

    bool isUidValid(const QString &uid);
    void openmainwindow(const QString &uid, const QString &date);
    void addhistorydata(const QString &uid, const QString &date);
    void handleNFCDetected(const QString &uid);
    void checknfc();
};

#endif // DISPLAYWINDOW_H
