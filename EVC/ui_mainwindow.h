#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *labelVa;
    QLabel *labelVb;
    QLabel *labelVc;
    QLabel *labelIa;
    QLabel *labelIb;
    QLabel *labelIc;
    QLabel *labelP;
    QLCDNumber *NumberVa;
    QLCDNumber *NumberVb;
    QLCDNumber *NumberVc;
    QLCDNumber *NumberIa;
    QLCDNumber *NumberIb;
    QLCDNumber *NumberIc;
    QLCDNumber *NumberP;
    QPushButton *Buttonchange;
    QPushButton *Buttonstop;
    QPushButton *Buttonmenu;
    QLCDNumber *NumberkWh;
    QLabel *labelkWh;
    QPushButton *Buttonuptime;
    QPushButton *Buttondowntime;
    QTimeEdit *timeEdit;
    QPushButton *ButtonBack;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(480, 320);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 480, 320));
        label->setPixmap(QPixmap(QString::fromUtf8("/home/pi/app/Picture/DISPLAY.jpg")));
        label->setScaledContents(true);
        labelVa = new QLabel(centralwidget);
        labelVa->setObjectName("labelVa");
        labelVa->setGeometry(QRect(120, 50, 30, 30));
        labelVb = new QLabel(centralwidget);
        labelVb->setObjectName("labelVb");
        labelVb->setGeometry(QRect(120, 90, 30, 30));
        labelVc = new QLabel(centralwidget);
        labelVc->setObjectName("labelVc");
        labelVc->setGeometry(QRect(120, 130, 30, 30));
        labelIa = new QLabel(centralwidget);
        labelIa->setObjectName("labelIa");
        labelIa->setGeometry(QRect(410, 50, 30, 30));
        labelIb = new QLabel(centralwidget);
        labelIb->setObjectName("labelIb");
        labelIb->setGeometry(QRect(410, 90, 30, 30));
        labelIc = new QLabel(centralwidget);
        labelIc->setObjectName("labelIc");
        labelIc->setGeometry(QRect(410, 130, 30, 30));
        labelP = new QLabel(centralwidget);
        labelP->setObjectName("labelP");
        labelP->setGeometry(QRect(120, 170, 30, 30));
        NumberVa = new QLCDNumber(centralwidget);
        NumberVa->setObjectName("NumberVa");
        NumberVa->setGeometry(QRect(40, 50, 80, 30));
        NumberVb = new QLCDNumber(centralwidget);
        NumberVb->setObjectName("NumberVb");
        NumberVb->setGeometry(QRect(40, 90, 80, 30));
        NumberVc = new QLCDNumber(centralwidget);
        NumberVc->setObjectName("NumberVc");
        NumberVc->setGeometry(QRect(40, 130, 80, 30));
        NumberIa = new QLCDNumber(centralwidget);
        NumberIa->setObjectName("NumberIa");
        NumberIa->setGeometry(QRect(330, 50, 80, 30));
        NumberIb = new QLCDNumber(centralwidget);
        NumberIb->setObjectName("NumberIb");
        NumberIb->setGeometry(QRect(330, 90, 80, 30));
        NumberIc = new QLCDNumber(centralwidget);
        NumberIc->setObjectName("NumberIc");
        NumberIc->setGeometry(QRect(330, 130, 80, 30));
        NumberP = new QLCDNumber(centralwidget);
        NumberP->setObjectName("NumberP");
        NumberP->setGeometry(QRect(40, 170, 80, 30));
        Buttonchange = new QPushButton(centralwidget);
        Buttonchange->setObjectName("Buttonchange");
        Buttonchange->setGeometry(QRect(48, 230, 60, 60));
        QIcon icon;
        icon.addFile(QString::fromUtf8("/home/pi/app/Picture/icon-start.png"), QSize(), QIcon::Normal, QIcon::Off);
        Buttonchange->setIcon(icon);
        Buttonchange->setIconSize(QSize(70, 70));
        Buttonstop = new QPushButton(centralwidget);
        Buttonstop->setObjectName("Buttonstop");
        Buttonstop->setGeometry(QRect(372, 230, 60, 60));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("/home/pi/app/Picture/icon-stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        Buttonstop->setIcon(icon1);
        Buttonstop->setIconSize(QSize(60, 60));
        Buttonmenu = new QPushButton(centralwidget);
        Buttonmenu->setObjectName("Buttonmenu");
        Buttonmenu->setGeometry(QRect(440, 0, 40, 40));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("/home/pi/app/Picture/icon-menu.png"), QSize(), QIcon::Normal, QIcon::Off);
        Buttonmenu->setIcon(icon2);
        Buttonmenu->setIconSize(QSize(30, 30));
        NumberkWh = new QLCDNumber(centralwidget);
        NumberkWh->setObjectName("NumberkWh");
        NumberkWh->setGeometry(QRect(330, 170, 80, 30));
        labelkWh = new QLabel(centralwidget);
        labelkWh->setObjectName("labelkWh");
        labelkWh->setGeometry(QRect(410, 170, 60, 30));
        Buttonuptime = new QPushButton(centralwidget);
        Buttonuptime->setObjectName("Buttonuptime");
        Buttonuptime->setGeometry(QRect(156, 230, 60, 60));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("/home/pi/app/Picture/up-time.png"), QSize(), QIcon::Normal, QIcon::Off);
        Buttonuptime->setIcon(icon3);
        Buttonuptime->setIconSize(QSize(90, 90));
        Buttondowntime = new QPushButton(centralwidget);
        Buttondowntime->setObjectName("Buttondowntime");
        Buttondowntime->setGeometry(QRect(264, 230, 60, 60));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("/home/pi/app/Picture/down-time.png"), QSize(), QIcon::Normal, QIcon::Off);
        Buttondowntime->setIcon(icon4);
        Buttondowntime->setIconSize(QSize(90, 90));
        timeEdit = new QTimeEdit(centralwidget);
        timeEdit->setObjectName("timeEdit");
        timeEdit->setGeometry(QRect(185, 40, 110, 30));
        QFont font;
        font.setPointSize(14);
        timeEdit->setFont(font);
        ButtonBack = new QPushButton(centralwidget);
        ButtonBack->setObjectName("ButtonBack");
        ButtonBack->setGeometry(QRect(0, 0, 40, 40));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("/home/pi/app/Picture/go-back.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonBack->setIcon(icon5);
        ButtonBack->setIconSize(QSize(40, 40));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        labelVa->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:20pt; color:#00ff00;\">V</span></p></body></html>", nullptr));
        labelVb->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:20pt; color:#00ff00;\">V</span></p></body></html>", nullptr));
        labelVc->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:20pt; color:#00ff00;\">V</span></p></body></html>", nullptr));
        labelIa->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:20pt; color:#00ff00;\">A</span></p></body></html>", nullptr));
        labelIb->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:20pt; color:#00ff00;\">A</span></p></body></html>", nullptr));
        labelIc->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:20pt; color:#00ff00;\">A</span></p></body></html>", nullptr));
        labelP->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:20pt; color:#00ff00;\">W</span></p></body></html>", nullptr));
        Buttonchange->setText(QString());
        Buttonstop->setText(QString());
        Buttonmenu->setText(QString());
        labelkWh->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:20pt; color:#00ff00;\">kWh</span></p></body></html>", nullptr));
        Buttonuptime->setText(QString());
        Buttondowntime->setText(QString());
        timeEdit->setDisplayFormat(QCoreApplication::translate("MainWindow", "HH:mm:ss", nullptr));
        ButtonBack->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
