#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QListWidget>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui->setupUi(this);

    QGridLayout *main_box = new QGridLayout(this);
    main_box->setSpacing(3);

    QLineEdit *display = new QLineEdit(this);
    display->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(15);

    QPushButton *zero = new QPushButton("0", this);
    zero->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    zero->setStyleSheet("QPushButton{border-radius: 10px; font: bold 14px; background-color: #8B8A8A}"
                                   "QPushButton:hover{background: #A9A4A4;}"
                                   "QPushButton:pressed{background: #A9A4A4; border-width: 1px; border-style: solid; border-radius: 10px; border-color: #CECBCB}"
                        );

    QPushButton *dot = new QPushButton(".", this);
    dot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    dot->setStyleSheet("QPushButton{border-radius: 10px; font: bold 14px; background-color: #8B8A8A}"
                                   "QPushButton:hover{background: #A9A4A4;}"
                                   "QPushButton:pressed{background: #A9A4A4; border-width: 1px; border-style: solid; border-radius: 10px; border-color: #CECBCB}"
                       );

    QPushButton *resultBt = new QPushButton("=", this);
    resultBt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    resultBt->setStyleSheet("QPushButton{border-radius: 10px; font: bold 14px; background-color: #4351D0}"
                            "QPushButton:hover{background: #3748DE;}"
                            "QPushButton:pressed{background: #3748DE; border-width: 1px; border-style: solid; border-radius: 10px; border-color: #D4D8FD}"
                            );

    QList<QString> valuesDigits(
                    { "1", "2", "3",
                      "4", "5", "6",
                      "7", "8", "9"
                    });

    QPushButton *digitButtons[9];
        for (int i=0; i<valuesDigits.length(); i++){
            digitButtons[i] = new QPushButton();
            digitButtons[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
            digitButtons[i]->setText(valuesDigits[i]);
            digitButtons[i]->setStyleSheet("QPushButton{border-radius: 10px; font: bold 14px; background-color: #8B8A8A}"
                                           "QPushButton:hover{background: #A9A4A4;}"
                                           "QPushButton:pressed{background: #A9A4A4; border-width: 1px; border-style: solid; border-radius: 10px; border-color: #CECBCB}"
                                           );

        }

    int pos = 0;
    for (int i = 4; i > 1; i--) {
        for (int j = 0; j < 3; j++) {
            digitButtons[pos]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            main_box->addWidget(digitButtons[pos], i, j);
            pos++;
            }
        }

    QList<QString> operands(
                    { "/", "*",
                      "-", "+"
                    });

    QPushButton *operandsButtons[4];
    for (int i=0; i<operands.length(); i++){
        operandsButtons[i] = new QPushButton();
        operandsButtons[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        operandsButtons[i]->setText(operands[i]);
        operandsButtons[i]->setStyleSheet("QPushButton{border-radius: 10px; font: bold 14px; background-color: #F2B355}"
                                           "QPushButton:hover{background: #E99922;}"
                                           "QPushButton:pressed{background: #E99922; border-width: 1px; border-style: solid; border-radius: 10px; border-color: #FAE9CF}"
                                           );
    }

    pos = 0;
    for (int i = 2; i < 6; i++) {
        operandsButtons[pos]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        main_box->addWidget(operandsButtons[pos], i, 3);
        pos++;
    }

    QList<QString> extraOperands(
                    { "x^y", "srqt",
                      "x!", "ln",
                      "sin", "cos",
                      "tg", "ctg"
                    });

    QPushButton *extraOperandsButtons[8];
    for (int i=0; i<extraOperands.length(); i++){
        extraOperandsButtons[i] = new QPushButton();
        extraOperandsButtons[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        extraOperandsButtons[i]->setText(extraOperands[i]);
        extraOperandsButtons[i]->setStyleSheet("QPushButton{border-radius: 10px; font: bold 14px; background-color: #E99922}"
                                           "QPushButton:hover{background: #F2B355;}"
                                           "QPushButton:pressed{background: #F2B355; border-width: 1px; border-style: solid; border-radius: 10px; border-color: #FAE9CF}"
                                           );
    }

    pos = 0;
    for (int i = 2; i < 6; i++) {
        for (int j = 4; j < 6; j++) {
            extraOperandsButtons[pos]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            main_box->addWidget(extraOperandsButtons[pos], i, j);
            pos++;
        }
    }

    QPushButton *backspase = new QPushButton("С", this);
    backspase->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    backspase->setStyleSheet("QPushButton{border-radius: 10px; font: bold 14px; background-color: #FF5656}"
                            "QPushButton:hover{background: #FD2E2E;}"
                            "QPushButton:pressed{background: #FD2E2E; border-width: 1px; border-style: solid; border-radius: 10px; border-color: #FF9999}"
                            );

    QPushButton *CABt = new QPushButton("СA", this);
    CABt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    CABt->setStyleSheet("QPushButton{border-radius: 10px; font: bold 14px; background-color: #FD2E2E}"
                            "QPushButton:hover{background: #FF5656;}"
                            "QPushButton:pressed{background: #FF5656; border-width: 1px; border-style: solid; border-radius: 10px; border-color: #FF9999}"
                            );

    QPushButton *leftBkt = new QPushButton("(", this);
    leftBkt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    leftBkt->setStyleSheet("QPushButton{border-radius: 10px; font: bold 14px; background-color: #8B8A8A}"
                            "QPushButton:hover{background: #A9A4A4;}"
                            "QPushButton:pressed{background: #A9A4A4; border-width: 1px; border-style: solid; border-radius: 10px; border-color: #CECBCB}"
                            );

    QPushButton *rightBkt = new QPushButton(")", this);
    rightBkt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    rightBkt->setStyleSheet("QPushButton{border-radius: 10px; font: bold 14px; background-color: #8B8A8A}"
                            "QPushButton:hover{background: #A9A4A4;}"
                            "QPushButton:pressed{background: #A9A4A4; border-width: 1px; border-style: solid; border-radius: 10px; border-color: #CECBCB}"
                            );

    QPushButton *prikol = new QPushButton("^__^;D:3", this);
    prikol->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    prikol->setStyleSheet("QPushButton{border-radius: 10px; font: bold 10px; background-color: #FF9DFB}"
                          "QPushButton:hover{background: #FAB6F8;}"
                          "QPushButton:pressed{background: #FAB6F8; border-width: 1px; border-style: solid; border-radius: 10px; border-color: #FADAF9}"
                          );

    main_box->addWidget(display, 0, 0, 1, 6);
    main_box->addWidget(zero, 5, 0);
    main_box->addWidget(dot, 5, 1);
    main_box->addWidget(resultBt, 5, 2);
    main_box->addWidget(backspase, 1, 3);
    main_box->addWidget(CABt, 1, 4, 1, 2);
    main_box->addWidget(leftBkt, 1, 1);
    main_box->addWidget(rightBkt, 1, 2);
    main_box->addWidget(prikol, 1, 0);
    ui->centralwidget->setLayout(main_box);
}

MainWindow::~MainWindow()
{
    delete ui;
}

