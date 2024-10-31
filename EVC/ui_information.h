#ifndef UI_INFORMATION_H
#define UI_INFORMATION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Information
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *ButtonBack;

    void setupUi(QMainWindow *Information)
    {
        if (Information->objectName().isEmpty())
            Information->setObjectName("Information");
        Information->resize(480, 320);
        centralwidget = new QWidget(Information);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 60, 400, 90));
        QFont font;
        font.setFamilies({QString::fromUtf8("URW Bookman [urw]")});
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 160, 400, 30));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("URW Bookman [urw]")});
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(true);
        label_2->setFont(font1);
        ButtonBack = new QPushButton(centralwidget);
        ButtonBack->setObjectName("ButtonBack");
        ButtonBack->setGeometry(QRect(0, 0, 40, 40));
        QIcon icon;
        icon.addFile(QString::fromUtf8("/home/pi/app/Picture/go-back.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonBack->setIcon(icon);
        ButtonBack->setIconSize(QSize(40, 40));
        Information->setCentralWidget(centralwidget);

        retranslateUi(Information);

        QMetaObject::connectSlotsByName(Information);
    } // setupUi

    void retranslateUi(QMainWindow *Information)
    {
        Information->setWindowTitle(QCoreApplication::translate("Information", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("Information", "<html><head/><body><p align=\"center\">Thi\341\272\277t b\341\273\213 \304\221\306\260\341\273\243c thi\341\272\277t k\341\272\277 </p><p align=\"center\">v\303\240 s\341\272\243n xu\341\272\245t b\341\273\237i</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Information", "<html><head/><body><p>C\303\264ng ty c\341\273\225 ph\341\272\247n chuy\341\273\203n \304\221\341\273\225i n\304\203ng l\306\260\341\273\243ng xanh</p></body></html>", nullptr));
        ButtonBack->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Information: public Ui_Information {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFORMATION_H
