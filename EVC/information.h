#ifndef INFORMATION_H
#define INFORMATION_H

#include <QMainWindow>

namespace Ui {
class Information;
}

class Information : public QMainWindow
{
    Q_OBJECT

public:
    explicit Information(QWidget *parent = nullptr);
    ~Information();
public slots:
    void backmenu();
signals:
    void backscreen();
private:
    Ui::Information *information;
};

#endif // INFORMATION_H
