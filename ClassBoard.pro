QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


# windeployqt D:\Qt\build-ClassBoard-Desktop_x86_windows_msvc2019_pe_32bit-Release\release\ClassBoard.exe


RC_ICONS = icon.ico
#程序版本
VERSION = 0.1.4.230619
#程序说明
QMAKE_TARGET_DESCRIPTION = "Class Board For Seewo"
#程序名称
QMAKE_TARGET_PRODUCT = "Class Board"
#程序语言
#0x0800代表和系统当前语言一致
RC_LANG = 0x0800


SOURCES += \
    aboutdialog.cpp \
    class_schedule.cpp \
    counterw.cpp \
    deskform.cpp \
    setting_win.cpp \
    timetable.cpp \
    win32mod.cpp \
    main.cpp

HEADERS += \
    aboutdialog.h \
    class_schedule.h \
    counterw.h \
    deskform.h \
    setting_win.h \
    timetable.h \
    win32mod.h

FORMS += \
    aboutdialog.ui \
    class_schedule.ui \
    counterw.ui \
    deskform.ui \
    setting_win.ui \
    timetable.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    cb4s.qrc

DISTFILES += \
    .gitignore
