#ifndef CHOOSEDIALOG_H
#define CHOOSEDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMessageBox>
#include "pokemon.h"

namespace Ui {
class ChooseDialog;
}

class ChooseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseDialog(QWidget *parent = nullptr);
    ~ChooseDialog();

private slots:
    void receivemake_ChooseDialog();
    void receive_make_ChooseDialog();
    void hide_ChooseDialog(int);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

signals:
    void showintroducedialog(Pokemon*, int, int);
    void startfirst();
    void initializationenemy();

private:
    Ui::ChooseDialog *ui;
    Pokemon *choose[5];
    QMediaPlayer *p;
    QMediaPlaylist *music_list;
    QString attribute[4] = {"border-image: url(:/new/prefix1/normal.png);","border-image: url(:/new/prefix1/strawberry.png);","border-image: url(:/new/prefix1/water.png);","border-image: url(:/new/prefix1/fire.png);"};
    int n;
};

#endif // CHOOSEDIALOG_H
