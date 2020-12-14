#include "sculptordialog.h"
#include "ui_sculptordialog.h"

SculptorDialog::SculptorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SculptorDialog)
{
    ui->setupUi(this);
    ui->SliderDimX->setMaximum(100);
    ui->SliderDimY->setMaximum(100);
    ui->SliderDimZ->setMaximum(100);
}

SculptorDialog::~SculptorDialog()
{
    delete ui;
}

int SculptorDialog::getX()
{
    ui->SliderDimX->value();
}

int SculptorDialog::getY()
{
    ui->SliderDimY->value();
}

int SculptorDialog::getZ()
{
   ui->SliderDimZ->value();
}
