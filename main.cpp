#include "deskform.h"
#include "counterw.h"
#include "class_schedule.h"
#include "aboutdialog.h"
#include "timetable.h"
#include <QApplication>
#include <QLocale>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setFont(QFont("Microsoft Yahei", 11));

    deskform w;
    w.show();
    return a.exec();
}
