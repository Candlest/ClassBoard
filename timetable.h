#ifndef TIMETABLE_H
#define TIMETABLE_H

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
class TimeTable;
}

class TimeTable : public QWidget
{
    Q_OBJECT

public:
    explicit TimeTable(QWidget *parent = nullptr);
    ~TimeTable();
//    void initTimer();
//private slots:
//    void setTime();
private:
    Ui::TimeTable *ui;
    QTimer *bgTimer;
    QStringList tableList;
    void translucentBg();
    bool TimeTable::read();
    void initLables();
//    void delLables();
protected:
    //将窗口设置为随着窗口变化而变化
    //virtual void resizeEvent(QResizeEvent *event) override;
    virtual void paintEvent(QPaintEvent *) override;
};

#endif // TIMETABLE_H
