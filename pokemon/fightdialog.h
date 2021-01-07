#ifndef FIGHTDIALOG_H
#define FIGHTDIALOG_H

#include <QDialog>
#include <QDebug>
#include <cstring>
#include <QMessageBox>
#include "pokemon.h"

namespace Ui {
class FightDialog;
}

class FightDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FightDialog(QWidget *parent = nullptr);
    ~FightDialog();

private slots:
    void addmypokemon(Pokemon*, int);
    void startshow();
    void initialization();
    void re_show();
    void reply();
    void start_instead();
    void cenemypokemon(Pokemon*);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void receive_choose(int, Pokemon*);

signals:
    void fail();
    void win();
    void next_choose(Pokemon*, Pokemon*, Pokemon*);
    void next_instead(Pokemon*, Pokemon*, Pokemon*);
    void next_close();
    void sendpokemon(Pokemon*);
    void sendenemypokemon(Pokemon*);
    void showbattle(int);
    void continuebattle();

private:
    Ui::FightDialog *ui;
    Pokemon *mypokemon[3], *enemypokemon[3];
    bool fa[20];
    QString attribute[4] = {"border-image: url(:/new/prefix1/normal.png);","border-image: url(:/new/prefix1/strawberry.png);","border-image: url(:/new/prefix1/water.png);","border-image: url(:/new/prefix1/fire.png);"};
    int x, m, l, r;
};

#endif // FIGHTDIALOG_H
