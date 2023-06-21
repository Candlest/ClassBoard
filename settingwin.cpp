#include "settingwin.h"
#include "ui_settingwin.h"

SettingWin::SettingWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingWin)
{
    ui->setupUi(this);
    setWindowFlag(Qt::CustomizeWindowHint);
    setWindowTitle(u8"设置（尚未完成）");
}

SettingWin::~SettingWin()
{
    delete ui;
}
