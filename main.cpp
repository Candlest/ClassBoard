#include "deskform.h"
#include "counterw.h"
#include "class_schedule.h"
#include "aboutdialog.h"
#include <QApplication>
#include <QLocale>
<<<<<<< HEAD
#include <QTranslator>
=======
>>>>>>> master

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

<<<<<<< HEAD
//    /*Add i18n Supports, if possible...*/
//    QTranslator translator;
//    const QStringList uiLanguages = QLocale::system().uiLanguages();
//    for (const QString &locale : uiLanguages) {
//        const QString baseName = "ClassBoard4Seewo_" + QLocale(locale).name();
//        if (translator.load(":/i18n/" + baseName)) {
//            a.installTranslator(&translator);
//            break;
//        }
//    }
=======
    //    /*Add i18n Supports, if possible...*/
    //    QTranslator translator;
    //    const QStringList uiLanguages = QLocale::system().uiLanguages();
    //    for (const QString &locale : uiLanguages) {
    //        const QString baseName = "ClassBoard4Seewo_" + QLocale(locale).name();
    //        if (translator.load(":/i18n/" + baseName)) {
    //            a.installTranslator(&translator);
    //            break;
    //        }
    //    }
>>>>>>> master

    //设置中文字体
    a.setFont(QFont("Microsoft Yahei", 11));
    //设置中文编码
<<<<<<< HEAD
//#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
//#if _MSC_VER
//    QTextCodec *codec = QTextCodec::codecForName("GBK");
//#else
//    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
//#endif
//    QTextCodec::setCodecForLocale(codec);
//    QTextCodec::setCodecForCStrings(codec);
//    QTextCodec::setCodecForTr(codec);
//#else
//    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
//    QTextCodec::setCodecForLocale(codec);
//#endif
=======
    //#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
    //#if _MSC_VER
    //    QTextCodec *codec = QTextCodec::codecForName("GBK");
    //#else
    //    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    //#endif
    //    QTextCodec::setCodecForLocale(codec);
    //    QTextCodec::setCodecForCStrings(codec);
    //    QTextCodec::setCodecForTr(codec);
    //#else
    //    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    //    QTextCodec::setCodecForLocale(codec);
    //#endif
>>>>>>> master

    deskform w;
    w.show();
    return a.exec();
}
