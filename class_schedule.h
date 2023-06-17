#ifndef CLASS_SCHEDULE_H
#define CLASS_SCHEDULE_H

#include <QWidget>
#include <QDebug>
#include <QObject>
#include <QPainter>
#include <QScreen>
#include <QTimer>
#include <QDateTime>
#include <QIODevice>
#include <QMessageBox>
#include <QFile>

namespace Ui {
class Class_Schedule;
}

class Class_Schedule : public QWidget
{
    Q_OBJECT

public:
    explicit Class_Schedule(QWidget *parent = nullptr);
    ~Class_Schedule();
    void initTimer();
private slots:
    void drawSchedule();
private:
    void translucentBg();
    void initSchedule();
    QTimer *bgTimer;
    Ui::Class_Schedule *ui;
protected:
    //将窗口设置为随着窗口变化而变化
    //virtual void resizeEvent(QResizeEvent *event) override;
    virtual void paintEvent(QPaintEvent *) override;

private:
    bool read();
    QString choose();
    QStringList tod;
};

#endif // CLASS_SCHEDULE_H
