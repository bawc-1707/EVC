#ifndef UI_DISPLAYWINDOW_H
#define UI_DISPLAYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DisplayWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_2;
    QLabel *label;

    void setupUi(QMainWindow *DisplayWindow)
    {
        if (DisplayWindow->objectName().isEmpty())
            DisplayWindow->setObjectName("DisplayWindow");
        DisplayWindow->resize(480, 320);
        centralwidget = new QWidget(DisplayWindow);
        centralwidget->setObjectName("centralwidget");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 480, 320));
        label_2->setPixmap(QPixmap(QString::fromUtf8("/home/pi/app/Picture/Displayscreen.jpg")));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 120, 480, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("URW Bookman [urw]")});
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        DisplayWindow->setCentralWidget(centralwidget);

        retranslateUi(DisplayWindow);

        QMetaObject::connectSlotsByName(DisplayWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DisplayWindow)
    {
        DisplayWindow->setWindowTitle(QCoreApplication::translate("DisplayWindow", "MainWindow", nullptr));
        label_2->setText(QString());
        label->setText(QCoreApplication::translate("DisplayWindow", "<html><head/><body><p align=\"center\">Xin m\341\273\235i qu\341\272\271t th\341\272\273 \304\221\341\273\203 s\341\273\255 d\341\273\245ng</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DisplayWindow: public Ui_DisplayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYWINDOW_H
