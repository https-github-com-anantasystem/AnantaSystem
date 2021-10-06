#include "moreinformation.h"
#include "ui_moreinformation.h"

moreinformation::moreinformation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::moreinformation)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

moreinformation::~moreinformation()
{
    delete ui;
}
