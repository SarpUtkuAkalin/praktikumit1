#ifndef ADDCITY_H
#define ADDCITY_H

#include <QDialog>

namespace Ui {
class addcity;
}

class addcity : public QDialog
{
    Q_OBJECT

public:
    explicit addcity(QWidget *parent = nullptr);
    ~addcity();

private:
    Ui::addcity *ui;
};

#endif // ADDCITY_H
