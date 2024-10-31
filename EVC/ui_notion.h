#ifndef UI_NOTION_H
#define UI_NOTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Notion
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Notion)
    {
        if (Notion->objectName().isEmpty())
            Notion->setObjectName("Notion");
        Notion->resize(180, 90);
        label = new QLabel(Notion);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 180, 90));
        label->setPixmap(QPixmap(QString::fromUtf8("/home/pi/app/Picture/Displayscreen.jpg")));
        label_2 = new QLabel(Notion);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 35, 180, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("FreeSerif")});
        font.setPointSize(10);
        font.setBold(true);
        label_2->setFont(font);

        retranslateUi(Notion);

        QMetaObject::connectSlotsByName(Notion);
    } // setupUi

    void retranslateUi(QDialog *Notion)
    {
        Notion->setWindowTitle(QCoreApplication::translate("Notion", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("Notion", "Th\341\272\273 NFC \304\221\303\243 t\341\273\223n t\341\272\241i trong b\341\273\231 nh\341\273\233", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Notion: public Ui_Notion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTION_H
