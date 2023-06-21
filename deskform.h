#ifndef DESKFORM_H
#define DESKFORM_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QObject>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QPixmap>
#include <QScreen>
#include <QTimer>
#include <QtGlobal>
#include <QProcess>
#include <QRandomGenerator>
#include <QSettings>

#include "counterw.h"
#include "class_schedule.h"
#include "win32mod.h"
#include "aboutdialog.h"
#include "timetable.h"
#include "settingwin.h"

namespace Ui {
class deskform;
}

class deskform : public QWidget
{
    Q_OBJECT

public:
    explicit deskform(QWidget *parent = nullptr);
    ~deskform();

public:
    QSystemTrayIcon tray;
    void initTray();
    void initImages();
    void initBackground(QString);
    void initTimer();
    void initKits();
    void initArgs();
    void initSettings();

private slots:
    void on_a_about_triggered();

    void on_a_exit_triggered();

    void on_a_setting_triggered();

    void on_a_gk_triggered();

    void on_a_restart_triggered();

    void on_a_class_triggered();

    void on_a_count_small_triggered();

private:
    Ui::deskform *ui;
    QStringList images;
    QTimer *bgTimer;
    counterw *gkw;
    Class_Schedule *csw;
    AboutDialog *ab;
    TimeTable *tt;
    SettingWin *sw;

public:
    QString PicDir;

protected:
    //将窗口设置为随着窗口变化而变化
    virtual void resizeEvent(QResizeEvent *event) override;
};

#endif // DESKFORM_H
