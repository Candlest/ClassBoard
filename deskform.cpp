#include "deskform.h"
#include "ui_deskform.h"

deskform::deskform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deskform)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::SubWindow|Qt::FramelessWindowHint);
    this->move(0,0);
    //this->setWindowState(Qt::WindowMaximized);
    SetParent((HWND)this->winId(),GetWorkerW());


    initTray();
    initArgs();
    initImages();
    initBackground(images[QRandomGenerator::global()->bounded(images.length()-1)]);
    initTimer();
    initKits();
}

void deskform::initArgs(){
    QStringList args = qApp->arguments();
    if(args.count()>1)//存在时
    {
        tray.showMessage(QString::fromLocal8Bit("Class Borad"),
                         QString::fromLocal8Bit("重载成功"),
                         QIcon(":/mwin/trayicon"),
                         3000
                         );
    }
    else
    {
        tray.showMessage(QString::fromLocal8Bit("Class Borad"),
                         QString::fromLocal8Bit("欢迎使用Class Borad~"),
                         QIcon(":/mwin/trayicon"),
                         3000
                         );
    }
}

void deskform::initKits()
{
    gkw = new counterw();
    gkw->show();
    csw = new Class_Schedule();
    csw->show();
    tt = new TimeTable();
    tt->show();
}

void deskform::initTimer()
{
    //初始化QTimer
    bgTimer = new QTimer(this);
    //实现槽函数 Lambda表达式yyds
    connect(bgTimer, &QTimer::timeout, [=]{
        /*抽一张壁纸*/
        initBackground(images[QRandomGenerator::global()->bounded(images.length()-1)]);
    });

    bgTimer->start(1000*30); //1000 = 1s
}

void deskform::initBackground(QString fn = QString("飞飞母校.jpg")) /*初始化背景| 重新绘制*/
{
    qDebug() <<fn;
    //this->setStyleSheet("background-color:black;");
    //this->setStyleSheet("border-image:url(./Background_Set/飞飞母校.jpg);");

    //ui->l_bg = new QLabel(this);
    //this->setCentralWidget(ui->l_bg);


    QRect screenRect = QGuiApplication::primaryScreen()->geometry();
    double screenW = screenRect.width();
    double screenH = screenRect.height();
    qDebug()<<screenW<<screenH;

    this->resize(QSize(screenW,screenH));

    QPixmap pix(QString::fromLocal8Bit("./Background_Set/%1").arg(fn));

    QImage image=pix.toImage();/*开始取色*/
    QPalette palette;
    palette.setColor(QPalette::Background, image.pixel(5,5));
    this->setAutoFillBackground(true);
    this->setPalette(palette);

    double PicW = pix.width();
    double PicH = pix.height();
    qDebug()<<PicW<<PicH;
    /*
     * 实现等比缩放
     * 图片大小: m*n
     * 桌面大小: 1920*1080
     *
     * 目标:
     * m' = m*(1080/n)
     * n' = n*(1080/n)
     *
     *
    */
    QPixmap fitpixmap = pix.scaled(PicW*double(screenH/PicH), screenH, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    qDebug()<<PicW*double(screenH/PicH)<<screenH;
    ui->l_bg->setPixmap(fitpixmap);
    ui->l_bg->setAlignment(Qt::AlignCenter);
    //ui->l_bg->setScaledContents(true);
}

void deskform::initImages()
{ /*读入图片文件夹*/
    /* this block is FROM https://zhuanlan.zhihu.com/p/345341049 */
    QDir directory("./Background_Set");
    images = directory.entryList(QStringList() << "*.jpg" << "*.JPG" << "*.png" << "*.PNG" << "*.jpeg" << "*.JPEG", QDir::Files);
    foreach(QString filename, images) {
        qDebug() << filename; //TEST
    }
}

void deskform::initTray() /*初始化托盘*/
{
    //tray
    QIcon qi = QIcon(":/mwin/trayicon");
    tray.setIcon(qi);
    tray.show();
    tray.setToolTip(QString::fromLocal8Bit("Class Board"));

    //menu
    //以后可以设置icon -- done 2023年6月17日

    QMenu *menu = new QMenu();
    menu->addAction(ui->a_gk);
    menu->addAction(ui->a_class);
    menu->addAction(ui->a_count_small);
    menu->addSeparator();
    menu->addAction(ui->a_about);
    menu->addAction(ui->a_setting);
    menu->addAction(ui->a_restart);
    menu->addAction(ui->a_exit);
    tray.setContextMenu(menu);
}

deskform::~deskform()
{
    tray.hide();
    delete ui;
}

void deskform::on_a_about_triggered()
{
    ab = new AboutDialog();
    ab->show();
}

void deskform::on_a_exit_triggered()
{
    gkw->close();
    csw->close();
    qApp->exit();
    this->close();
}

void deskform::resizeEvent(QResizeEvent *event)
{
    ui->l_bg->resize(this->size());
}

void deskform::on_a_setting_triggered()/*设置*/
{
    sw = new SettingWin(this);
    sw->show();
}


void deskform::on_a_gk_triggered()
{
    if(!ui->a_gk->isChecked()){
        gkw->hide();
    }
    else{
        gkw->show();
    }
}



void deskform::on_a_class_triggered()
{
    if(!ui->a_class->isChecked()){
        csw->hide();
    }
    else{
        csw->show();
    }
}

void deskform::on_a_restart_triggered()
{
    //qApp->closeAllWindows();
    QProcess::startDetached(qApp->applicationFilePath(), QStringList("restart"));
    qApp->exit();
}


void deskform::on_a_count_small_triggered()
{
    if(!ui->a_count_small->isChecked()){
        tt->hide();
    }
    else{
        tt->show();
    }
}

