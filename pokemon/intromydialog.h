﻿#ifndef INTROMYDIALOG_H
#define INTROMYDIALOG_H

#include <QDialog>
#include <QTimer>
#include "pokemon.h"

namespace Ui {
class intromyDialog;
}

class intromyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit intromyDialog(QWidget *parent = nullptr);
    ~intromyDialog();

private slots:
    void receive_my(Pokemon*, Pokemon*, int);
    void on_pushButton_clicked();
    void update_pokemon_move();
    void on_pushButton_2_clicked();

signals:
    void instead_reshow();
    void send_choose(int, Pokemon*);

private:
    Ui::intromyDialog *ui;
    Pokemon *xi, *yi;
    QString attribute[4] = {"border-image: url(:/new/prefix1/normal.png);","border-image: url(:/new/prefix1/strawberry.png);","border-image: url(:/new/prefix1/water.png);","border-image: url(:/new/prefix1/fire.png);"};
    QString pokemon_move[17][4] = {{"border-image: url(:/new/prefix1/003s_00.png);","border-image: url(:/new/prefix1/003s_01.png);","border-image: url(:/new/prefix1/003s_02.png);","border-image: url(:/new/prefix1/003s_03.png);"},{"border-image: url(:/new/prefix1/071s_00.png);","border-image: url(:/new/prefix1/071s_01.png);","border-image: url(:/new/prefix1/071s_02.png);","border-image: url(:/new/prefix1/071s_03.png);"},{"border-image: url(:/new/prefix1/103s_00.png);","border-image: url(:/new/prefix1/103s_01.png);","border-image: url(:/new/prefix1/103s_02.png);","border-image: url(:/new/prefix1/103s_03.png);"},{"border-image: url(:/new/prefix1/020s_00.png);","border-image: url(:/new/prefix1/020s_01.png);","border-image: url(:/new/prefix1/020s_02.png);","border-image: url(:/new/prefix1/020s_03.png);"},{"border-image: url(:/new/prefix1/053s_00.png);","border-image: url(:/new/prefix1/053s_01.png);","border-image: url(:/new/prefix1/053s_02.png);","border-image: url(:/new/prefix1/053s_03.png);"},{"border-image: url(:/new/prefix1/115s_00.png);","border-image: url(:/new/prefix1/115s_01.png);","border-image: url(:/new/prefix1/115s_02.png);","border-image: url(:/new/prefix1/115s_03.png);"},{"border-image: url(:/new/prefix1/006s_00.png);","border-image: url(:/new/prefix1/006s_01.png);","border-image: url(:/new/prefix1/006s_02.png);","border-image: url(:/new/prefix1/006s_03.png);"},{"border-image: url(:/new/prefix1/078s_00.png);","border-image: url(:/new/prefix1/078s_01.png);","border-image: url(:/new/prefix1/078s_02.png);","border-image: url(:/new/prefix1/078s_03.png);"},{"border-image: url(:/new/prefix1/038s_00.png);","border-image: url(:/new/prefix1/038s_01.png);","border-image: url(:/new/prefix1/038s_02.png);","border-image: url(:/new/prefix1/038s_03.png);"},{"border-image: url(:/new/prefix1/009s_00.png);","border-image: url(:/new/prefix1/009s_01.png);","border-image: url(:/new/prefix1/009s_02.png);","border-image: url(:/new/prefix1/009s_03.png);"},{"border-image: url(:/new/prefix1/121s_00.png);","border-image: url(:/new/prefix1/121s_01.png);","border-image: url(:/new/prefix1/121s_02.png);","border-image: url(:/new/prefix1/121s_03.png);"},{"border-image: url(:/new/prefix1/062s_00.png);","border-image: url(:/new/prefix1/062s_01.png);","border-image: url(:/new/prefix1/062s_02.png);","border-image: url(:/new/prefix1/062s_03.png);"},{"border-image: url(:/new/prefix1/143s_00.png);","border-image: url(:/new/prefix1/143s_01.png);","border-image: url(:/new/prefix1/143s_02.png);","border-image: url(:/new/prefix1/143s_03.png);"},{"border-image: url(:/new/prefix1/254s_00.png);","border-image: url(:/new/prefix1/254s_01.png);","border-image: url(:/new/prefix1/254s_02.png);","border-image: url(:/new/prefix1/254s_03.png);"},{"border-image: url(:/new/prefix1/257s_00.png);","border-image: url(:/new/prefix1/257s_01.png);","border-image: url(:/new/prefix1/257s_02.png);","border-image: url(:/new/prefix1/257s_03.png);"},{"border-image: url(:/new/prefix1/260s_00.png);","border-image: url(:/new/prefix1/260s_01.png);","border-image: url(:/new/prefix1/260s_02.png);","border-image: url(:/new/prefix1/260s_03.png);"},{"border-image: url(:/new/prefix1/342s_00.png);","border-image: url(:/new/prefix1/342s_01.png);","border-image: url(:/new/prefix1/342s_02.png);","border-image: url(:/new/prefix1/342s_03.png);"}};
    int m, f;
    QTimer *t;
};

#endif // INTROMYDIALOG_H
