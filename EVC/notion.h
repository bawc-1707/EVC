#ifndef NOTION_H
#define NOTION_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class Notion;
}

class Notion : public QDialog
{
    Q_OBJECT

public:
    explicit Notion(QWidget *parent = nullptr);
    ~Notion();

public slots:
    void notionchecknfc();
    void notionwrongnfc();
    void notionavaliablenfc();
    void notionaddnfc();
    void notionpermission();
    void notiondisconnect();

private:
    Ui::Notion *notion;
    QTimer *timer;
};

#endif // NOTION_H
