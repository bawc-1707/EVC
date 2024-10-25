#include "menuwindow.h"
#include "ui_menuwindow.h"

MenuWindow::MenuWindow(QWidget *parent) :
    QMainWindow(parent),
    menuwindow(new Ui::MenuWindow),
    information(nullptr),
    listcard(nullptr),
    history(nullptr)
{
    menuwindow->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);
    showFullScreen();

    connect(menuwindow->ButtonBack, &QPushButton::clicked, this, &MenuWindow::backmainwindow);
    connect(menuwindow->ButtonHistory, &QPushButton::clicked, this, &MenuWindow::openHistory);
    connect(menuwindow->ButtonInformation, &QPushButton::clicked, this, &MenuWindow::openInformation);
    connect(menuwindow->ButtonList_UID, &QPushButton::clicked, this, &MenuWindow::openListCard);
}

MenuWindow::~MenuWindow()
{
    delete menuwindow;
}

void MenuWindow::openInformation(){
    if(!information){
        information = new Information;
        information->show();
        connect(information, &Information::backscreen, this, &MenuWindow::handlebackmenu);
        this->close();
    }
}

void MenuWindow::openListCard(){
    if(!listcard){
        listcard = new ListCard;
        listcard->show();
        connect(listcard, &ListCard::backscreen, this, &MenuWindow::handlebackmenu);
        this->close();
    }
}

void MenuWindow::openHistory(){
    if(!history){
        history = new History;
        history->show();
        connect(history, &History::backscreen, this, &MenuWindow::handlebackmenu);
        this->close();
    }
}

void MenuWindow::backmainwindow(){
    emit backscreen();
}

void MenuWindow::handlebackmenu(){
    if(information){
        this->show();
        delete information;
        information = nullptr;
    }
    if(listcard){
        this->show();
        delete listcard;
        listcard = nullptr;
    }
    if(history){
        this->show();
        delete history;
        history = nullptr;
    }
}
