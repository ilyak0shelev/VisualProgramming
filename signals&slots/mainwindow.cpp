#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QApplication>
#include <QGridLayout>
#include <QTimer>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    main_box = new QGridLayout(this);
    label = new QLabel(text, this);
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label->setStyleSheet("font-size: 16px");
    label->setWordWrap(true);

    main_box->addWidget(label, 0, 0, 1, 1);
    ui->centralwidget->setLayout(main_box);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
    timer->start(1000);
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    QString oldText = label->text();
    int key = event->key();

    switch (key) {
        case Qt::Key_Backspace:
            label->setText(oldText.left(oldText.length()-1));
            break;
        case Qt::Key_Tab:
            label->setText((oldText + "    "));
            break;
        case Qt::Key_Return:
            label->setText(oldText + '\n');
            break;
        default:
            label->setText(oldText + event->text());
            break;
    }
}

void MainWindow::slotTimerAlarm()
{
    this->setWindowTitle(QTime::currentTime().toString("hh:mm:ss"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
