#include "addcity.h"
#include "ui_addcity.h"

addcity::addcity(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addcity)
{
    ui->setupUi(this);
}

addcity::~addcity()
{
    delete ui;
}
