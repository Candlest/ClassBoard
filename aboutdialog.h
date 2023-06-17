#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
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
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QPainter>
#include <QMouseEvent>

namespace Ui {
class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = nullptr);
    ~AboutDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AboutDialog *ui;
};

#endif // ABOUTDIALOG_H
