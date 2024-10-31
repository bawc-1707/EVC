#ifndef UI_LISTCARD_H
#define UI_LISTCARD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListCard
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *ButtonBack;
    QPushButton *ButtonRemove;
    QPushButton *ButtonADD;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *UID_3;
    QLineEdit *lineEditUID4;
    QLabel *UID_4;
    QLineEdit *lineEditUID1;
    QLabel *UID_7;
    QLabel *UID_9;
    QLineEdit *lineEditUID2;
    QLabel *UID_6;
    QLabel *UID_2;
    QLineEdit *lineEditUID6;
    QLineEdit *lineEditUID3;
    QLabel *UID_1;
    QLineEdit *lineEditUID5;
    QLabel *UID_8;
    QLabel *UID_5;
    QLineEdit *lineEditUID7;
    QLineEdit *lineEditUID8;
    QLineEdit *lineEditUID9;

    void setupUi(QMainWindow *ListCard)
    {
        if (ListCard->objectName().isEmpty())
            ListCard->setObjectName("ListCard");
        ListCard->resize(480, 320);
        centralwidget = new QWidget(ListCard);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 480, 320));
        label->setPixmap(QPixmap(QString::fromUtf8("/home/pi/app/Picture/Displayscreen.jpg")));
        ButtonBack = new QPushButton(centralwidget);
        ButtonBack->setObjectName("ButtonBack");
        ButtonBack->setGeometry(QRect(0, 0, 40, 40));
        QIcon icon;
        icon.addFile(QString::fromUtf8("/home/pi/app/Picture/go-back.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonBack->setIcon(icon);
        ButtonBack->setIconSize(QSize(40, 40));
        ButtonRemove = new QPushButton(centralwidget);
        ButtonRemove->setObjectName("ButtonRemove");
        ButtonRemove->setGeometry(QRect(320, 240, 60, 60));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("/home/pi/app/Picture/remove-card.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonRemove->setIcon(icon1);
        ButtonRemove->setIconSize(QSize(70, 70));
        ButtonADD = new QPushButton(centralwidget);
        ButtonADD->setObjectName("ButtonADD");
        ButtonADD->setGeometry(QRect(100, 240, 60, 60));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("/home/pi/app/Picture/add-card.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonADD->setIcon(icon2);
        ButtonADD->setIconSize(QSize(70, 70));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 50, 481, 181));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        UID_3 = new QLabel(gridLayoutWidget);
        UID_3->setObjectName("UID_3");
        QFont font;
        font.setFamilies({QString::fromUtf8("Quicksand")});
        font.setBold(true);
        UID_3->setFont(font);

        gridLayout->addWidget(UID_3, 2, 0, 1, 1);

        lineEditUID4 = new QLineEdit(gridLayoutWidget);
        lineEditUID4->setObjectName("lineEditUID4");

        gridLayout->addWidget(lineEditUID4, 0, 3, 1, 1);

        UID_4 = new QLabel(gridLayoutWidget);
        UID_4->setObjectName("UID_4");
        UID_4->setFont(font);

        gridLayout->addWidget(UID_4, 0, 2, 1, 1);

        lineEditUID1 = new QLineEdit(gridLayoutWidget);
        lineEditUID1->setObjectName("lineEditUID1");

        gridLayout->addWidget(lineEditUID1, 0, 1, 1, 1);

        UID_7 = new QLabel(gridLayoutWidget);
        UID_7->setObjectName("UID_7");
        UID_7->setFont(font);

        gridLayout->addWidget(UID_7, 0, 4, 1, 1);

        UID_9 = new QLabel(gridLayoutWidget);
        UID_9->setObjectName("UID_9");
        UID_9->setFont(font);

        gridLayout->addWidget(UID_9, 2, 4, 1, 1);

        lineEditUID2 = new QLineEdit(gridLayoutWidget);
        lineEditUID2->setObjectName("lineEditUID2");

        gridLayout->addWidget(lineEditUID2, 1, 1, 1, 1);

        UID_6 = new QLabel(gridLayoutWidget);
        UID_6->setObjectName("UID_6");
        UID_6->setFont(font);

        gridLayout->addWidget(UID_6, 2, 2, 1, 1);

        UID_2 = new QLabel(gridLayoutWidget);
        UID_2->setObjectName("UID_2");
        UID_2->setFont(font);

        gridLayout->addWidget(UID_2, 1, 0, 1, 1);

        lineEditUID6 = new QLineEdit(gridLayoutWidget);
        lineEditUID6->setObjectName("lineEditUID6");

        gridLayout->addWidget(lineEditUID6, 2, 3, 1, 1);

        lineEditUID3 = new QLineEdit(gridLayoutWidget);
        lineEditUID3->setObjectName("lineEditUID3");

        gridLayout->addWidget(lineEditUID3, 2, 1, 1, 1);

        UID_1 = new QLabel(gridLayoutWidget);
        UID_1->setObjectName("UID_1");
        UID_1->setFont(font);

        gridLayout->addWidget(UID_1, 0, 0, 1, 1);

        lineEditUID5 = new QLineEdit(gridLayoutWidget);
        lineEditUID5->setObjectName("lineEditUID5");

        gridLayout->addWidget(lineEditUID5, 1, 3, 1, 1);

        UID_8 = new QLabel(gridLayoutWidget);
        UID_8->setObjectName("UID_8");
        UID_8->setFont(font);

        gridLayout->addWidget(UID_8, 1, 4, 1, 1);

        UID_5 = new QLabel(gridLayoutWidget);
        UID_5->setObjectName("UID_5");
        UID_5->setFont(font);

        gridLayout->addWidget(UID_5, 1, 2, 1, 1);

        lineEditUID7 = new QLineEdit(gridLayoutWidget);
        lineEditUID7->setObjectName("lineEditUID7");

        gridLayout->addWidget(lineEditUID7, 0, 5, 1, 1);

        lineEditUID8 = new QLineEdit(gridLayoutWidget);
        lineEditUID8->setObjectName("lineEditUID8");

        gridLayout->addWidget(lineEditUID8, 1, 5, 1, 1);

        lineEditUID9 = new QLineEdit(gridLayoutWidget);
        lineEditUID9->setObjectName("lineEditUID9");

        gridLayout->addWidget(lineEditUID9, 2, 5, 1, 1);

        ListCard->setCentralWidget(centralwidget);

        retranslateUi(ListCard);

        QMetaObject::connectSlotsByName(ListCard);
    } // setupUi

    void retranslateUi(QMainWindow *ListCard)
    {
        ListCard->setWindowTitle(QCoreApplication::translate("ListCard", "MainWindow", nullptr));
        label->setText(QString());
        ButtonBack->setText(QString());
        ButtonRemove->setText(QString());
        ButtonADD->setText(QString());
        UID_3->setText(QCoreApplication::translate("ListCard", "uid 3", nullptr));
        UID_4->setText(QCoreApplication::translate("ListCard", "uid 4", nullptr));
        UID_7->setText(QCoreApplication::translate("ListCard", "uid 7", nullptr));
        UID_9->setText(QCoreApplication::translate("ListCard", "uid 9", nullptr));
        UID_6->setText(QCoreApplication::translate("ListCard", "uid 6", nullptr));
        UID_2->setText(QCoreApplication::translate("ListCard", "uid 2", nullptr));
        UID_1->setText(QCoreApplication::translate("ListCard", "uid 1", nullptr));
        UID_8->setText(QCoreApplication::translate("ListCard", "uid 8", nullptr));
        UID_5->setText(QCoreApplication::translate("ListCard", "uid 5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListCard: public Ui_ListCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTCARD_H
