#ifndef COUNTERW_H
#define COUNTERW_H

#include <QWidget>
#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <QObject>
#include <QPainter>
#include <QScreen>

namespace Ui {
class counterw;
}

class counterw : public QWidget
{
    Q_OBJECT

public:
    explicit counterw(QWidget *parent = nullptr);
    ~counterw();
    void initTimer();
    QDateTime dt;
private slots:
    void setTime();
private:
    void translucentBg();
    Ui::counterw *ui;
    QTimer *bgTimer;
protected:
    //将窗口设置为随着窗口变化而变化
    //virtual void resizeEvent(QResizeEvent *event) override;
    virtual void paintEvent(QPaintEvent *) override;
};

#endif // COUNTERW_H
