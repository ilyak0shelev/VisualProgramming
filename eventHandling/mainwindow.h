#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QKeyEvent>
#include <QString>
#include <QGridLayout>
#include <QTimer>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void slotTimerAlarm();
    void keyPressEvent(QKeyEvent *e);

private:
    Ui::MainWindow *ui;
    QLabel *label;
    QString text = "";
    QGridLayout *main_box;
    QTimer *timer;
};
#endif // MAINWINDOW_H
