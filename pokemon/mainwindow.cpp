#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    p = new QMediaPlayer;
    music_list = new QMediaPlaylist;
    music_list->addMedia(QUrl("qrc:/new/prefix1/bgm.mp3"));
    music_list->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    p->setPlaylist(music_list);
    p->play();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    p->stop();
    this->close();
}

void MainWindow::on_pushButton_clicked()
{
    int flag = QMessageBox::information(nullptr,tr("玩法提示"),tr("游戏一开始，你可以从五只随机的pokemon中选择三只，之后有五名实力强劲的对手，每当你战胜一名对手后，你可以选择对方的一只pokemon更换掉自己手上的一只pokemon，战胜所有人你将获得游戏的胜利"),QMessageBox::Ok);
    if (flag == QMessageBox::Ok) qDebug() << tr("提示");
    p->stop();
    this->hide();
    emit showchoosedialog();
}

void MainWindow::re_show()
{
    p->play();
    this->show();
}
