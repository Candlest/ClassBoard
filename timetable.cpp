#include "timetable.h"
#include "ui_timetable.h"

TimeTable::TimeTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimeTable)
{
    ui->setupUi(this);
    //initTimer();
    translucentBg();
    read();
    initLables();
}

TimeTable::~TimeTable()
{
    delete ui;
}

void TimeTable::translucentBg()
{
    //桌面穿透
    setAttribute(Qt::WA_TransparentForMouseEvents, true);
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);

    //设置到右下方
    QRect screenRect = QGuiApplication::primaryScreen()->geometry();
    int screenW = screenRect.width();
    int screenH = screenRect.height();
    qDebug()<<screenW<<screenH;

    this->move(((screenW-this->width())) - 400,(screenH-this->height())/2);


    setWindowFlags(Qt::SubWindow|Qt::FramelessWindowHint); /* 注意：如果单纯开启窗口透明层效果，在Windows系统中必须设置, 其他系统可忽略。*/
    setAttribute(Qt::WA_TranslucentBackground);
}

void TimeTable::paintEvent(QPaintEvent *)
{
    /*From https://cloud.tencent.com/developer/article/1546015*/
    QPainter painter(this);
    /* 0x20为透明层颜色，可自定义设置为0x0到0xff */
    painter.fillRect(this->rect(), QColor(0, 0, 0, 0x0));
}

//void TimeTable::initTimer()
//{
//    //初始化QTimer
//    bgTimer = new QTimer(this);
//    //实现槽函数
//    connect(bgTimer, SIGNAL(timeout()), this, SLOT(setTime()));
//    //bgTimer->start(100); //1000 = 1s
//}

//void TimeTable::setTime()
//{
//    /*TO DO*/
//}

bool TimeTable::read(){
    //Read ./djr.csv

    QFile file("./djr.csv");
    //QFile file(R"(D:\Qt\build-ClassBoard-Desktop_x86_windows_msvc2019_pe_32bit-Release\release\djr.csv)");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"OPEN FILE FAILED";
        QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("丢失djr.csv文件"));
    }
    QTextStream * out = new QTextStream(&file);//文本流
    QStringList tempOption = out->readAll().split("\n");//每行以\n区分
    for(int i = 0 ; i < tempOption.count() ; i++)
    {
        QStringList tempbar = tempOption.at(i).split(",");//一行中的单元格以，区分
        tableList.append(tempbar); //两个两个读取，注意表头不读
    }
    qDebug()<<"OPEN FILE";
    return false;
}

void TimeTable::initLables()
{
    int num = tableList.count()/2; //明确有几行
    QString p_n = u8R"(<p><span style=" font-size:36pt; font-weight:700; color:#ffffff;">%1</span></p>)";
    QString p_d = u8R"(<p><span style=" font-size:28pt; font-weight:700; color:#ffffff;">剩余 </span><span style=" font-size:36pt; font-weight:700; color:#ffffff;">%1</span><span style=" font-size:28pt; font-weight:700; color:#ffffff;">天</span></p>)";
    QString l_r, l_l;
    for(int i =1; i<num;i++){
        l_l.append(p_n.arg(tableList[i*2+0].simplified()));
        qDebug() << tableList[i*2+0] << tableList[i*2+1].simplified();
//        QDateTime begin_time = QDateTime::currentDateTime();
//        QDateTime end_time = QDateTime::fromString(tableList[i*2+1], "yyyy-MM-dd");
//        //l_l.append(QString("%1").arg(begin_time.daysTo(end_time)));
        l_r.append(p_d.arg(QDateTime::currentDateTime().daysTo(QDateTime::fromString(tableList[i*2+1].simplified(), "yyyy-MM-dd"))));
        //l_l.append(begin_time.daysTo(end_time)));
    }//第一行不读
    //l_r.append('<p>');
    //加载
    ui->label_l->setText(ui->label_l->text().arg(l_l));
    ui->label_r->setText(ui->label_r->text().arg(l_r));
}
