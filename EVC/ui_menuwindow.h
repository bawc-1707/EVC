#ifndef UI_MENUWINDOW_H
#define UI_MENUWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *ButtonHistory;
    QPushButton *ButtonBack;
    QPushButton *ButtonList_UID;
    QPushButton *ButtonInformation;

    void setupUi(QMainWindow *MenuWindow)
    {
        if (MenuWindow->objectName().isEmpty())
            MenuWindow->setObjectName("MenuWindow");
        MenuWindow->resize(480, 320);
        centralwidget = new QWidget(MenuWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 480, 320));
        label->setPixmap(QPixmap(QString::fromUtf8("/home/pi/app/Picture/Displayscreen.jpg")));
        ButtonHistory = new QPushButton(centralwidget);
        ButtonHistory->setObjectName("ButtonHistory");
        ButtonHistory->setGeometry(QRect(170, 140, 140, 60));
        QFont font;
        font.setFamilies({QString::fromUtf8("URW Bookman [urw]")});
        font.setPointSize(14);
        font.setBold(true);
        ButtonHistory->setFont(font);
        ButtonBack = new QPushButton(centralwidget);
        ButtonBack->setObjectName("ButtonBack");
        ButtonBack->setGeometry(QRect(0, 0, 40, 40));
        QIcon icon;
        icon.addFile(QString::fromUtf8("/home/pi/app/Picture/go-back.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonBack->setIcon(icon);
        ButtonBack->setIconSize(QSize(40, 40));
        ButtonList_UID = new QPushButton(centralwidget);
        ButtonList_UID->setObjectName("ButtonList_UID");
        ButtonList_UID->setGeometry(QRect(170, 40, 140, 60));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("URW Bookman")});
        font1.setPointSize(14);
        font1.setBold(true);
        ButtonList_UID->setFont(font1);
        ButtonList_UID->setIconSize(QSize(0, 0));
        ButtonInformation = new QPushButton(centralwidget);
        ButtonInformation->setObjectName("ButtonInformation");
        ButtonInformation->setGeometry(QRect(170, 240, 140, 60));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("URW Bookman [urw]")});
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setItalic(false);
        ButtonInformation->setFont(font2);
        MenuWindow->setCentralWidget(centralwidget);

        retranslateUi(MenuWindow);

        QMetaObject::connectSlotsByName(MenuWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MenuWindow)
    {
        MenuWindow->setWindowTitle(QCoreApplication::translate("MenuWindow", "MainWindow", nullptr));
        label->setText(QString());
        ButtonHistory->setText(QCoreApplication::translate("MenuWindow", "History", nullptr));
        ButtonBack->setText(QString());
        ButtonList_UID->setText(QCoreApplication::translate("MenuWindow", "List UID card", nullptr));
        ButtonInformation->setText(QCoreApplication::translate("MenuWindow", "Information", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuWindow: public Ui_MenuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWINDOW_H
