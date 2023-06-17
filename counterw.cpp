#include "counterw.h"
#include "ui_counterw.h"

counterw::counterw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::counterw)
{
    ui->setupUi(this);
    initTimer();
    translucentBg();
}

counterw::~counterw()
{
    delete ui;
}

void counterw::translucentBg()
{
    //桌面穿透
    setAttribute(Qt::WA_TransparentForMouseEvents, true);
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);

    //设置到正上方
    QRect screenRect = QGuiApplication::primaryScreen()->geometry();
    int screenW = screenRect.width();
    int screenH = screenRect.height();
    qDebug()<<screenW<<screenH;

    this->move(((screenW-this->width()))/2,0);


    setWindowFlags(Qt::SubWindow|Qt::FramelessWindowHint); /* 注意：如果单纯开启窗口透明层效果，在Windows系统中必须设置, 其他系统可忽略。*/
    setAttribute(Qt::WA_TranslucentBackground);
}

void counterw::paintEvent(QPaintEvent *)
{
    /*From https://cloud.tencent.com/developer/article/1546015*/
    QPainter painter(this);
    /* 0x20为透明层颜色，可自定义设置为0x0到0xff */
    painter.fillRect(this->rect(), QColor(0, 0, 0, 0x0));
}

void counterw::initTimer()
{
    //初始化QTimer
    bgTimer = new QTimer(this);
    //实现槽函数
    connect(bgTimer, SIGNAL(timeout()), this, SLOT(setTime()));
    bgTimer->start(100); //1000 = 1s
}

void counterw::setTime()
{
    QDateTime begin_time = QDateTime::currentDateTime();
    QDateTime end_time = QDateTime::fromString("2024-06-07 09:00:00", "yyyy-MM-dd hh:mm:ss");

    QTime m_time;
    m_time.setHMS(0, 0, 0, 0);                                       //初始化数据，时 分 秒 毫秒
    qDebug() << m_time.addSecs(begin_time.secsTo(end_time)).toString("hh");//计算时间差(秒)，将时间差加入m_time，格式化输出
    qDebug() << begin_time.daysTo(end_time) << begin_time.toLocalTime().toString(u8"yyyy年MM月dd日 hh:mm:ss");
    this->ui->l_now->setText(QString(u8R"(<html><head/><body><p align="center"><span style=" font-size:36pt;">现在是</span><span style=" font-size:48pt; font-weight:700;">%1</span></p><p align="center"><span style=" font-size:36pt;">距离高考还有</span><span style=" font-size:48pt; font-weight:700;">%2</span><span style=" font-size:36pt;">天</span><span style=" font-size:48pt; font-weight:700;">%3</span><span style=" font-size:36pt;">小时</span></p></body></html>)"
                              ).arg(begin_time.toLocalTime().toString(u8"yyyy年MM月dd日 hh:mm:ss")).arg(begin_time.daysTo(end_time)).arg(m_time.addSecs(begin_time.secsTo(end_time)).toString("hh")));
}
