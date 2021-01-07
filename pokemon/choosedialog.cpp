#include "choosedialog.h"
#include "ui_choosedialog.h"

ChooseDialog::ChooseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseDialog)
{
    p = new QMediaPlayer;
    music_list = new QMediaPlaylist;
    music_list->addMedia(QUrl("qrc:/new/prefix1/bgm.mp3"));
    music_list->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    p->setPlaylist(music_list);
    ui->setupUi(this);
}

ChooseDialog::~ChooseDialog()
{
    delete ui;
}

void ChooseDialog::receive_make_ChooseDialog()
{
    n = 0;
    for (int i = 0; i < 5; i++) choose[i] = randpokemon();
    ui->pushButton->setStyleSheet(attribute[choose[0]->getattribute()] + "font: 75 12pt \"微软雅黑\";color: rgb(255, 255, 255);");
    ui->pushButton->setText(QString::fromStdString(choose[0]->getname()));
    ui->pushButton->show();
    ui->pushButton_2->setStyleSheet(attribute[choose[1]->getattribute()] + "font: 75 12pt \"微软雅黑\";color: rgb(255, 255, 255);");
    ui->pushButton_2->setText(QString::fromStdString(choose[1]->getname()));
    ui->pushButton_2->show();
    ui->pushButton_3->setStyleSheet(attribute[choose[2]->getattribute()] + "font: 75 12pt \"微软雅黑\";color: rgb(255, 255, 255);");
    ui->pushButton_3->setText(QString::fromStdString(choose[2]->getname()));
    ui->pushButton_3->show();
    ui->pushButton_4->setStyleSheet(attribute[choose[3]->getattribute()] + "font: 75 12pt \"微软雅黑\";color: rgb(255, 255, 255);");
    ui->pushButton_4->setText(QString::fromStdString(choose[3]->getname()));
    ui->pushButton_4->show();
    ui->pushButton_5->setStyleSheet(attribute[choose[4]->getattribute()] + "font: 75 12pt \"微软雅黑\";color: rgb(255, 255, 255);");
    ui->pushButton_5->setText(QString::fromStdString(choose[4]->getname()));
    ui->pushButton_5->show();
    p->play();
    this->show();
}

void ChooseDialog::receivemake_ChooseDialog()
{
    this->show();
}

void ChooseDialog::on_pushButton_clicked()
{
    this->hide();
    emit showintroducedialog(choose[0], n, 0);
}

void ChooseDialog::on_pushButton_2_clicked()
{
    this->hide();
    emit showintroducedialog(choose[1], n, 1);
}

void ChooseDialog::on_pushButton_3_clicked()
{
    this->hide();
    emit showintroducedialog(choose[2], n, 2);
}

void ChooseDialog::on_pushButton_4_clicked()
{
    this->hide();
    emit showintroducedialog(choose[3], n, 3);
}

void ChooseDialog::on_pushButton_5_clicked()
{
    this->hide();
    emit showintroducedialog(choose[4], n, 4);
}

void ChooseDialog::hide_ChooseDialog(int x)
{
    if (x == 0) ui->pushButton->hide();
    else if (x == 1) ui->pushButton_2->hide();
    else if (x == 2) ui->pushButton_3->hide();
    else if (x == 3) ui->pushButton_4->hide();
    else if (x == 4) ui->pushButton_5->hide();
    ++n;
    if (n < 3) this->show();
    else
    {
        p->stop();
        emit initializationenemy();
        emit startfirst();
    }
}
