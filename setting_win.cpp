#include "setting_win.h"
#include "ui_setting_win.h"

#include <QDebug>

Setting_Win::Setting_Win(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Setting_Win)
{
    ui->setupUi(this);
    initConfigs();
}

Setting_Win::~Setting_Win()
{
    delete settings;
    delete ui;
}

void Setting_Win::initConfigs()
{
    qDebug() << "init Settings";
    settings = new QSettings("./settings.conf", QSettings::IniFormat);

//    if (!settings->contains("Background/PicDir")){
//        //create new
//        settings->setValue("Background/PicDir", "./Background_Set/");
//        settings->setValue("Background/Mode", "1");
//        settings->setValue("GK_Counter/Date", "2024-06-07 09:00:00");
//        settings->setValue("Kits/BackgroundTrans", QColor(0, 0, 0, 0x00));
//        settings->setValue("Tray/ShowKits", true);
//        settings->sync();
//    }

    qDebug() << settings->value("GK_Counter/Date").toString();
    ui->dateTimeEdit->setDateTime(QDateTime::fromString(settings->value("GK_Counter/Date").toString(), "yyyy-MM-dd hh:mm:ss"));
}

void Setting_Win::on_changeGKDT_clicked()
{
    settings->setValue("GK_Counter/Date", ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss"));
    settings->sync();
}

