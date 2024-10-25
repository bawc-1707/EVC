#include "information.h"
#include "ui_information.h"

Information::Information(QWidget *parent) :
    QMainWindow(parent),
    information(new Ui::Information)
{
    information->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);
    showFullScreen();
    connect(information->ButtonBack, &QPushButton::clicked, this, &Information::backmenu);
}

Information::~Information()
{
    delete information;
}

void Information::backmenu(){
    emit backscreen();
}
