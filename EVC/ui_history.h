#ifndef UI_HISTORY_H
#define UI_HISTORY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_History
{
public:
    QWidget *centralwidget;
    QPushButton *ButtonBack;
    QTableWidget *tableWidget;

    void setupUi(QMainWindow *History)
    {
        if (History->objectName().isEmpty())
            History->setObjectName("History");
        History->resize(480, 320);
        centralwidget = new QWidget(History);
        centralwidget->setObjectName("centralwidget");
        ButtonBack = new QPushButton(centralwidget);
        ButtonBack->setObjectName("ButtonBack");
        ButtonBack->setGeometry(QRect(0, 0, 40, 40));
        QIcon icon;
        icon.addFile(QString::fromUtf8("/home/pi/app/Picture/go-back.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonBack->setIcon(icon);
        ButtonBack->setIconSize(QSize(40, 40));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget->rowCount() < 90)
            tableWidget->setRowCount(90);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 50, 480, 270));
        tableWidget->setRowCount(90);
        tableWidget->setColumnCount(3);
        tableWidget->horizontalHeader()->setDefaultSectionSize(145);
        History->setCentralWidget(centralwidget);

        retranslateUi(History);

        QMetaObject::connectSlotsByName(History);
    } // setupUi

    void retranslateUi(QMainWindow *History)
    {
        History->setWindowTitle(QCoreApplication::translate("History", "MainWindow", nullptr));
        ButtonBack->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("History", "UID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("History", "Date of charging", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("History", "kWh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class History: public Ui_History {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORY_H
