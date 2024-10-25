#include "notion.h"
#include "ui_notion.h"

Notion::Notion(QWidget *parent) :
    QDialog(parent),
    notion(new Ui::Notion)
{
    notion->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->move(147, 130);
    setModal(true);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Notion::close);
}

Notion::~Notion()
{
    delete notion;
}

void Notion::notionchecknfc()
{
    notion->label_2->setText("Hãy quẹt thẻ NFC");
    notion->label_2->setAlignment(Qt::AlignCenter);


}

void Notion::notionwrongnfc()
{
    notion->label_2->setText("Thẻ NFC không hợp lệ");
    notion->label_2->setAlignment(Qt::AlignCenter);

    if(timer->isActive()){
        timer->stop();
    }
    timer->start(5000);
}

void Notion::notionavaliablenfc()
{
    notion->label_2->setText("Thẻ NFC đã tồn tại trong bộ nhớ");
    notion->label_2->setAlignment(Qt::AlignCenter);

    if(timer->isActive()){
        timer->stop();
    }
    timer->start(5000);
}

void Notion::notionaddnfc()
{
    notion->label_2->setText("Thẻ NFC đã được thêm vào bộ nhớ");
    notion->label_2->setAlignment(Qt::AlignCenter);

    if(timer->isActive()){
        timer->stop();
    }
    timer->start(5000);
}
