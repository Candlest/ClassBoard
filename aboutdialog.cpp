#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint |
                   Qt::WindowMinimizeButtonHint |
                   Qt::WindowMaximizeButtonHint);
//    QPixmap pix(":/mwin/trayicon");
//    ui->label->setPixmap(pix.scaled(50,50));
//    ui->label->setAlignment(Qt::AlignCenter);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::on_pushButton_clicked()
{
    this->hide();
}
