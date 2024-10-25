#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include "information.h"
#include "listcard.h"
#include "history.h"

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();
public slots:
    void backmainwindow();
    void openInformation();
    void openListCard();
    void openHistory();
    void handlebackmenu();
signals:
    void backscreen();
private slots:

private:
    Ui::MenuWindow *menuwindow;
    Information *information;
    ListCard *listcard;
    History *history;
};

#endif // MENUWINDOW_H
