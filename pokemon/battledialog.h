#ifndef BATTLEDIALOG_H
#define BATTLEDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMessageBox>
#include <QTimer>
#include "pokemon.h"

namespace Ui {
class BattleDialog;
}

class BattleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BattleDialog(QWidget *parent = nullptr);
    ~BattleDialog();

private slots:
    void receivemypokemon(Pokemon*);
    void receiveenemypokemon(Pokemon*);
    void next_hide();
    void startbattle(int);
    void continue_battle();
    void enemyfight();
    void myfight();
    void update_Blood_strip_1();
    void update_Blood_strip_2();
    void update_Blood_strip_3();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

signals:
    void choose_mypokemon();
    void choose_enemypokemon(Pokemon*);

private:
    Ui::BattleDialog *ui;
    Pokemon *my, *enemy;
    QTimer *t_1, *t_2, *t_3;
    bool flag_1, flag_2, f_3, f_2, f_1;
    QMediaPlayer *p;
    int xy;
    QMediaPlaylist *music_list;
    QString flont_image[17] = {"border-image: url(:/new/prefix1/003.PNG);","border-image: url(:/new/prefix1/071.png);","border-image: url(:/new/prefix1/103.png);","border-image: url(:/new/prefix1/020.png);","border-image: url(:/new/prefix1/053.png);","border-image: url(:/new/prefix1/115.png);","border-image: url(:/new/prefix1/006.png);","border-image: url(:/new/prefix1/078.png);","border-image: url(:/new/prefix1/038.png);","border-image: url(:/new/prefix1/009.png);","border-image: url(:/new/prefix1/121.png);","border-image: url(:/new/prefix1/062.png);","border-image: url(:/new/prefix1/143.png);","border-image: url(:/new/prefix1/254.png);","border-image: url(:/new/prefix1/257.png);","border-image: url(:/new/prefix1/260.png);","border-image: url(:/new/prefix1/342.png);"};
    QString back_image[17] = {"border-image: url(:/new/prefix1/003back.png);","border-image: url(:/new/prefix1/071back.png);","border-image: url(:/new/prefix1/103back.png);","border-image: url(:/new/prefix1/020back.png);","border-image: url(:/new/prefix1/053back.png);","border-image: url(:/new/prefix1/115back .png);","border-image: url(:/new/prefix1/006back.png);","border-image: url(:/new/prefix1/078back.png);","border-image: url(:/new/prefix1/038back.png);","border-image: url(:/new/prefix1/009back.png);","border-image: url(:/new/prefix1/121back.png);","border-image: url(:/new/prefix1/062back.png);","border-image: url(:/new/prefix1/143back.png);","border-image: url(:/new/prefix1/254back.png);","border-image: url(:/new/prefix1/257back.png);","border-image: url(:/new/prefix1/260back.png);","border-image: url(:/new/prefix1/342back.png);"};
    QString attribute[4] = {"border-image: url(:/new/prefix1/normal.png);","border-image: url(:/new/prefix1/strawberry.png);","border-image: url(:/new/prefix1/water.png);","border-image: url(:/new/prefix1/fire.png);"};
    QString fightmusic[20] = {"qrc:/new/prefix1/chi.mp3","qrc:/new/prefix1/pipixia.mp3","qrc:/new/prefix1/jin.mp3","qrc:/new/prefix1/lubi.mp3","qrc:/new/prefix1/gaiyamengde.mp3","qrc:/new/prefix1/black.mp3","qrc:/new/prefix1/lakezi.mp3","qrc:/new/prefix1/aikesi.mp3","qrc:/new/prefix1/miaomiao.mp3","qrc:/new/prefix1/du.mp3","qrc:/new/prefix1/dawu.mp3","qrc:/new/prefix1/zhulan.mp3","qrc:/new/prefix1/adaike.mp3","qrc:/new/prefix1/ailisi.mp3","qrc:/new/prefix1/kalunai.mp3","qrc:/new/prefix1/kukuyi.mp3","qrc:/new/prefix1/rocketteam.mp3","qrc:/new/prefix1/xiaozhi.mp3","qrc:/new/prefix1/chaomeng.mp3","qrc:/new/prefix1/lv.mp3"};
};

#endif // BATTLEDIALOG_H
