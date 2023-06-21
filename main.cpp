#include "deskform.h"
#include "counterw.h"
#include "class_schedule.h"
#include "aboutdialog.h"
#include "timetable.h"
#include "setting_win.h"
#include <QApplication>
#include <QLocale>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //a.setFont(QFont("Microsoft Yahei", 11));

    //Setting_Win *df = new Setting_Win();
    deskform *df = new deskform();
    df->show();

    return a.exec();
}
