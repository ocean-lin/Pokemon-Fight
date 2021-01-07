#ifndef INSTEADDIALOG_H
#define INSTEADDIALOG_H

#include <QDialog>
#include "pokemon.h"

namespace Ui {
class InsteadDialog;
}

class InsteadDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InsteadDialog(QWidget *parent = nullptr);
    ~InsteadDialog();

private slots:
    void receive_ene(Pokemon*);
    void start_instead(Pokemon*, Pokemon*, Pokemon*);
    void re_show();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

signals:
    void send_choose(Pokemon*, Pokemon*, int);

private:
    Ui::InsteadDialog *ui;
    QString attribute[4] = {"border-image: url(:/new/prefix1/normal.png);","border-image: url(:/new/prefix1/strawberry.png);","border-image: url(:/new/prefix1/water.png);","border-image: url(:/new/prefix1/fire.png);"};
    Pokemon *ene, *my[3];
};

#endif // INSTEADDIALOG_H
