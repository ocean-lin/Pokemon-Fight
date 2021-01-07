#ifndef CHOOSEENEDIALOG_H
#define CHOOSEENEDIALOG_H

#include <QDialog>
#include <QDebug>
#include <cstring>
#include <QMessageBox>
#include "pokemon.h"

namespace Ui {
class ChooseeneDialog;
}

class ChooseeneDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseeneDialog(QWidget *parent = nullptr);
    ~ChooseeneDialog();

private slots:
    void ene_show(Pokemon*, Pokemon*, Pokemon*);
    void on_pushButton_4_clicked();
    void reshow();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

signals:
    void send_reply();
    void show_ene(Pokemon*);

private:
    Ui::ChooseeneDialog *ui;
    QString attribute[4] = {"border-image: url(:/new/prefix1/normal.png);","border-image: url(:/new/prefix1/strawberry.png);","border-image: url(:/new/prefix1/water.png);","border-image: url(:/new/prefix1/fire.png);"};
    Pokemon *ene[3];
};

#endif // CHOOSEENEDIALOG_H
