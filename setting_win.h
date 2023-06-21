#ifndef SETTING_WIN_H
#define SETTING_WIN_H

#include <QMainWindow>
#include <QSettings>

namespace Ui {
class Setting_Win;
}

class Setting_Win : public QMainWindow
{
    Q_OBJECT

public:
    explicit Setting_Win(QWidget *parent = nullptr);
    ~Setting_Win();

private slots:
    void on_changeGKDT_clicked();

private:
    void initConfigs();
    Ui::Setting_Win *ui;
    QSettings *settings;
};

#endif // SETTING_WIN_H
