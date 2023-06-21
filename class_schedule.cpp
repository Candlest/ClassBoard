#include "class_schedule.h"
#include "ui_class_schedule.h"

Class_Schedule::Class_Schedule(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Class_Schedule)
{
    ui->setupUi(this);
    initTimer();
    translucentBg();
    if(read()){
        initSchedule();
    }
}

Class_Schedule::~Class_Schedule()
{
    delete ui;
}

void Class_Schedule::translucentBg()
{
    //桌面穿透
    setAttribute(Qt::WA_TransparentForMouseEvents, true);
    setWindowFlags(Qt::SubWindow|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);

    //设置到右中方
    QRect screenRect = QGuiApplication::primaryScreen()->geometry();
    int screenW = screenRect.width();
    int screenH = screenRect.height();
    qDebug()<<screenW<<screenH;

    this->move(((screenW-this->width())),(screenH-this->height())/2);


    setWindowFlag(Qt::FramelessWindowHint); /* 注意：如果单纯开启窗口透明层效果，在Windows系统中必须设置, 其他系统可忽略。*/
    setAttribute(Qt::WA_TranslucentBackground);
}

void Class_Schedule::paintEvent(QPaintEvent *)
{
    /*From https://cloud.tencent.com/developer/article/1546015*/
    QPainter painter(this);
    /* 0x20为透明层颜色，可自定义设置为0x0到0xff */
    painter.fillRect(this->rect(), QColor(0, 0, 0, 0x0));
}

void Class_Schedule::initTimer()
{
    //初始化QTimer
    bgTimer = new QTimer(this);
    //实现槽函数
    connect(bgTimer, SIGNAL(timeout()), this, SLOT(drawSchedule()));
    bgTimer->start(1000*60*5); //1000 = 1s| 5min
}

void Class_Schedule::drawSchedule()
{

}

void Class_Schedule::initSchedule()
{
    /*循环加入
     * day
    */
    QString temp;
    for(int i = 1 ; i < tod.count() ; i++){
        temp = ui->label->text();
        ui->label->setText(temp.arg(this->tod[i].simplified()));
        qDebug()<<temp;
    }
}

bool Class_Schedule::read(){
    //Read ./kb.csv

    QFile file("./kb.csv");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"OPEN FILE FAILED";
        QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("丢失kb.csv文件"));
    }
    QTextStream * out = new QTextStream(&file);//文本流
    QStringList tempOption = out->readAll().split("\n");//每行以\n区分
    for(int i = 0 ; i < tempOption.count() ; i++)
    {
        QStringList tempbar = tempOption.at(i).split(",");//一行中的单元格以，区分
        qDebug() << tempbar[0] << QDateTime::currentDateTime().toLocalTime().toString("ddd");
        if(tempbar[0] == QDateTime::currentDateTime().toLocalTime().toString("ddd")){
            tod = tempbar;
            qDebug() << "Found";
            return true;
        }
    }
    return false;
}
