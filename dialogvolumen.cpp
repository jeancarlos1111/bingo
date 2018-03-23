#include "dialogvolumen.h"
#include "ui_dialogvolumen.h"

DialogVolumen::DialogVolumen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogVolumen)
{
    ui->setupUi(this);
}

DialogVolumen::~DialogVolumen()
{
    delete ui;
}
