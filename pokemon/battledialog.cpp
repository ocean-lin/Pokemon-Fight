#include "battledialog.h"
#include "ui_battledialog.h"

BattleDialog::BattleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BattleDialog)
{
    t_1 = new QTimer(this);
    t_1->stop();
    connect(t_1, SIGNAL(timeout()), this, SLOT(update_Blood_strip_1()));
    t_2 = new QTimer(this);
    t_2->stop();
    connect(t_2, SIGNAL(timeout()), this, SLOT(update_Blood_strip_2()));
    t_3 = new QTimer(this);
    t_3->stop();
    connect(t_3, SIGNAL(timeout()), this, SLOT(update_Blood_strip_3()));
    p = new QMediaPlayer;
    music_list = new QMediaPlaylist;
    ui->setupUi(this);
}

void BattleDialog::update_Blood_strip_1()
{
    if (my->gethp() < ui->progressBar->value())
    {
        int s = ui->progressBar->value();
        s--;
        ui->progressBar->setValue(s);
    }
    else if (my->gethp() > ui->progressBar->value())
    {
        int s = ui->progressBar->value();
        s++;
        ui->progressBar->setValue(s);
    }
    if (enemy->gethp() < ui->progressBar_2->value())
    {
        int s = ui->progressBar_2->value();
        s--;
        ui->progressBar_2->setValue(s);
    }
    else if (enemy->gethp() > ui->progressBar_2->value())
    {
        int s = ui->progressBar_2->value();
        s++;
        ui->progressBar_2->setValue(s);
    }
    if ((my->gethp() == ui->progressBar->value()) && (enemy->gethp() == ui->progressBar_2->value()) && (f_1))
    {
        t_1->stop();
        f_1 = 0;
        if ((my->gethp() == 0) && (flag_1))
        {
            flag_1 = 0;
            ui->textBrowser->moveCursor(QTextCursor::End);
            ui->textBrowser->insertPlainText(QString::fromStdString("你的" + my->getn() + "失去了战斗力\n"));
            this->update();
            this->hide();
            emit choose_mypokemon();
        }
        if ((enemy->gethp() == 0) && (flag_2))
        {
            flag_2 = 0;
            ui->textBrowser->moveCursor(QTextCursor::End);
            ui->textBrowser->insertPlainText(QString::fromStdString(npc[xy] + "的" + enemy->getn() + "失去了战斗力\n"));
            emit choose_enemypokemon(my);
            ui->textBrowser->moveCursor(QTextCursor::End);
            ui->textBrowser->insertPlainText(QString::fromStdString(npc[xy] + "派出了" + enemy->getn() + "\n"));
            ui->label_6->setStyleSheet(flont_image[enemy->getnumber()]);
            ui->label_2->setStyleSheet(attribute[enemy->getattribute()] + "font: 75 12pt \"微软雅黑\";color: rgb(255, 255, 255);");
            ui->label_2->setText(QString::fromStdString(enemy->getname()));
            ui->label_3->setText(QString::fromStdString(enemy->getstatus()));
            ui->progressBar_2->setMaximum(enemy->getHP());
            ui->progressBar_2->setValue(enemy->gethp());
            this->update();
        }
        this->update();
        enemyfight();
    }
    this->update();
}

void BattleDialog::update_Blood_strip_2()
{
    if (my->gethp() < ui->progressBar->value())
    {
        int s = ui->progressBar->value();
        s--;
        ui->progressBar->setValue(s);
    }
    else if (my->gethp() > ui->progressBar->value())
    {
        int s = ui->progressBar->value();
        s++;
        ui->progressBar->setValue(s);
    }
    if (enemy->gethp() < ui->progressBar_2->value())
    {
        int s = ui->progressBar_2->value();
        s--;
        ui->progressBar_2->setValue(s);
    }
    else if (enemy->gethp() > ui->progressBar_2->value())
    {
        int s = ui->progressBar_2->value();
        s++;
        ui->progressBar_2->setValue(s);
    }
    if ((my->gethp() == ui->progressBar->value()) && (enemy->gethp() == ui->progressBar_2->value()) && (f_2))
    {
        t_2->stop();
        f_2 = 0;
        if ((my->gethp() == 0) && (flag_1))
        {
            flag_1 = 0;
            ui->textBrowser->moveCursor(QTextCursor::End);
            ui->textBrowser->insertPlainText(QString::fromStdString("你的" + my->getn() + "失去了战斗力\n"));
            this->update();
            this->hide();
            emit choose_mypokemon();
        }
        if ((enemy->gethp() == 0) && (flag_2))
        {
            flag_2 = 0;
            ui->textBrowser->moveCursor(QTextCursor::End);
            ui->textBrowser->insertPlainText(QString::fromStdString(npc[xy] + "的" + enemy->getn() + "失去了战斗力\n"));
            emit choose_enemypokemon(my);
            ui->textBrowser->moveCursor(QTextCursor::End);
            ui->textBrowser->insertPlainText(QString::fromStdString(npc[xy] + "派出了" + enemy->getn() + "\n"));
            ui->label_6->setStyleSheet(flont_image[enemy->getnumber()]);
            ui->label_2->setStyleSheet(attribute[enemy->getattribute()] + "font: 75 12pt \"微软雅黑\";color: rgb(255, 255, 255);");
            ui->label_2->setText(QString::fromStdString(enemy->getname()));
            ui->label_3->setText(QString::fromStdString(enemy->getstatus()));
            ui->progressBar_2->setMaximum(enemy->getHP());
            ui->progressBar_2->setValue(enemy->gethp());
            this->update();
        }
        myfight();
        this->update();
    }
    this->update();
}

void BattleDialog::update_Blood_strip_3()
{
    if (my->gethp() < ui->progressBar->value())
    {
        int s = ui->progressBar->value();
        s--;
        ui->progressBar->setValue(s);
    }
    else if (my->gethp() > ui->progressBar->value())
    {
        int s = ui->progressBar->value();
        s++;
        ui->progressBar->setValue(s);
    }
    if (enemy->gethp() < ui->progressBar_2->value())
    {
        int s = ui->progressBar_2->value();
        s--;
        ui->progressBar_2->setValue(s);
    }
    else if (enemy->gethp() > ui->progressBar_2->value())
    {
        int s = ui->progressBar_2->value();
        s++;
        ui->progressBar_2->setValue(s);
    }
    if ((my->gethp() == ui->progressBar->value()) && (enemy->gethp() == ui->progressBar_2->value()) && (f_3))
    {
        f_3 = 0;
        t_3->stop();
        if ((my->gethp() == 0) && (flag_1))
        {
            flag_1 = 0;
            ui->textBrowser->moveCursor(QTextCursor::End);
            ui->textBrowser->insertPlainText(QString::fromStdString("你的" + my->getn() + "失去了战斗力\n"));
            this->update();
            this->hide();
            emit choose_mypokemon();
        }
        if ((enemy->gethp() == 0) && (flag_2))
        {
            flag_2 = 0;
            ui->textBrowser->moveCursor(QTextCursor::End);
            ui->textBrowser->insertPlainText(QString::fromStdString(npc[xy] + "的" + enemy->getn() + "失去了战斗力\n"));
            emit choose_enemypokemon(my);
            ui->textBrowser->moveCursor(QTextCursor::End);
            ui->textBrowser->insertPlainText(QString::fromStdString(npc[xy] + "派出了" + enemy->getn() + "\n"));
            ui->label_6->setStyleSheet(flont_image[enemy->getnumber()]);
            ui->label_2->setStyleSheet(attribute[enemy->getattribute()] + "font: 75 12pt \"微软雅黑\";color: rgb(255, 255, 255);");
            ui->label_2->setText(QString::fromStdString(enemy->getname()));
            ui->label_3->setText(QString::fromStdString(enemy->getstatus()));
            ui->progressBar_2->setMaximum(enemy->getHP());
            ui->progressBar_2->setValue(enemy->gethp());
            this->update();
            myfight();
        }
        this->update();
    }
    this->update();
}

BattleDialog::~BattleDialog()
{
    delete ui;
}

void BattleDialog::receivemypokemon(Pokemon *p)
{
    my = p;
}

void BattleDialog::receiveenemypokemon(Pokemon *p)
{
    enemy = p;
}

void BattleDialog::next_hide()
{
    p->stop();
    this->close();
}

void BattleDialog::startbattle(int x)
{
    xy = x;
    ui->pushButton->setEnabled(1);
    ui->pushButton_2->setEnabled(1);
    ui->pushButton_3->setEnabled(1);
    ui->pushButton_4->setEnabled(1);
    music_list->clear();
    music_list->addMedia(QUrl(fightmusic[x]));
    music_list->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    p->setPlaylist(music_list);
    p->play();
    flag_1 = flag_2 = f_3 = f_2 = f_1 = 1;
    ui->textBrowser->clear();
    ui->textBrowser->insertPlainText(QString::fromStdString("你派出了" + my->getn() + "\n"));
    ui->textBrowser->moveCursor(QTextCursor::End);
    ui->textBrowser->insertPlainText(QString::fromStdString(npc[xy] + "派出了" + enemy->getn() + "\n"));
    ui->label->setText(QString::fromStdString(my->getname()));
    ui->label->setStyleSheet(attribute[my->getattribute()] + "font: 75 12pt \"微软雅黑\";color: rgb(255, 255, 255);");
    ui->label_4->setText(QString::fromStdString(my->getstatus()));
    ui->pushButton->setText(QString::fromStdString(my->getSkill(0)->getname()) + tr("  pp ") + QString::number(my->getpp(0)) + tr("\n威力 ") + QString::number(my->getSkill(0)->getpower()) + tr("  命中率 ") + QString::number(my->getSkill(0)->gethitrate()) + tr("%"));
    ui->pushButton_2->setText(QString::fromStdString(my->getSkill(1)->getname()) + tr("  pp ") + QString::number(my->getpp(1)) + tr("\n威力 ") + QString::number(my->getSkill(1)->getpower()) + tr("  命中率 ") + QString::number(my->getSkill(1)->gethitrate()) + tr("%"));
    ui->pushButton_3->setText(QString::fromStdString(my->getSkill(2)->getname()) + tr("  pp ") + QString::number(my->getpp(2)) + tr("\n威力 ") + QString::number(my->getSkill(2)->getpower()) + tr("  命中率 ") + QString::number(my->getSkill(2)->gethitrate()) + tr("%"));
    ui->pushButton_4->setText(QString::fromStdString(my->getSkill(3)->getname()) + tr("  pp ") + QString::number(my->getpp(3)) + tr("\n威力 ") + QString::number(my->getSkill(3)->getpower()) + tr("  命中率 ") + QString::number(my->getSkill(3)->gethitrate()) + tr("%"));
    ui->progressBar->setMaximum(my->getHP());
    ui->progressBar->setValue(my->gethp());
    ui->label_2->setText(QString::fromStdString(enemy->getname()));
    ui->label_2->setStyleSheet(attribute[enemy->getattribute()] + "font: 75 12pt \"微软雅黑\";color: rgb(255, 255, 255);");
    ui->label_3->setText(QString::fromStdString(enemy->getstatus()));
    ui->progressBar_2->setMaximum(enemy->getHP());
    ui->progressBar_2->setValue(enemy->gethp());
    ui->label_5->setStyleSheet(back_image[my->getnumber()]);
    ui->label_6->setStyleSheet(flont_image[enemy->getnumber()]);
    ui->label_7->setText(QString::number(my->gethp()) + tr("/") + QString::number(my->getHP()));
    this->show();
}

void BattleDialog::on_pushButton_clicked()
{
    if (my->getpp(0))
    {
        f_2 = 1;
        my->delpp(0);
        ui->textBrowser->moveCursor(QTextCursor::End);
        ui->textBrowser->insertPlainText(QString::fromStdString(my->getn() + "使用了" + my->getSkill(0)->getn() + "\n"));
        ui->textBrowser->moveCursor(QTextCursor::End);
        ui->textBrowser->insertPlainText(QString::fromStdString(my->getSkill(0)->hurt(my, enemy)));
        ui->label_4->setText(QString::fromStdString(my->getstatus()));
        ui->pushButton->setText(QString::fromStdString(my->getSkill(0)->getname()) + tr("  pp ") + QString::number(my->getpp(0)) + tr("\n威力 ") + QString::number(my->getSkill(0)->getpower()) + tr("  命中率 ") + QString::number(my->getSkill(0)->gethitrate()) + tr("%"));
        ui->label_3->setText(QString::fromStdString(enemy->getstatus()));
        ui->label_7->setText(QString::number(my->gethp()) + tr("/") + QString::number(my->getHP()));
        ui->pushButton->setEnabled(0);
        ui->pushButton_2->setEnabled(0);
        ui->pushButton_3->setEnabled(0);
        ui->pushButton_4->setEnabled(0);
        this->update();
        t_1->start(15);
    }
}

void BattleDialog::on_pushButton_2_clicked()
{
    if (my->getpp(1))
    {
        f_2 = 1;
        my->delpp(1);
        ui->textBrowser->moveCursor(QTextCursor::End);
        ui->textBrowser->insertPlainText(QString::fromStdString(my->getn() + "使用了" + my->getSkill(1)->getn() + "\n"));
        ui->textBrowser->moveCursor(QTextCursor::End);
        ui->textBrowser->insertPlainText(QString::fromStdString(my->getSkill(1)->hurt(my, enemy)));
        ui->label_4->setText(QString::fromStdString(my->getstatus()));
        ui->pushButton_2->setText(QString::fromStdString(my->getSkill(1)->getname()) + tr("  pp ") + QString::number(my->getpp(1)) + tr("\n威力 ") + QString::number(my->getSkill(1)->getpower()) + tr("  命中率 ") + QString::number(my->getSkill(1)->gethitrate()) + tr("%"));
        ui->label_3->setText(QString::fromStdString(enemy->getstatus()));
        ui->label_7->setText(QString::number(my->gethp()) + tr("/") + QString::number(my->getHP()));
        ui->pushButton->setEnabled(0);
        ui->pushButton_2->setEnabled(0);
        ui->pushButton_3->setEnabled(0);
        ui->pushButton_4->setEnabled(0);
        this->update();
        t_1->start(15);
    }
}

void BattleDialog::on_pushButton_3_clicked()
{
    if (my->getpp(2))
    {
        f_2 = 1;
        my->delpp(2);
        ui->textBrowser->moveCursor(QTextCursor::End);
        ui->textBrowser->insertPlainText(QString::fromStdString(my->getn() + "使用了" + my->getSkill(2)->getn() + "\n"));
        ui->textBrowser->moveCursor(QTextCursor::End);
        ui->textBrowser->insertPlainText(QString::fromStdString(my->getSkill(2)->hurt(my, enemy)));
        ui->label_4->setText(QString::fromStdString(my->getstatus()));
        ui->pushButton_3->setText(QString::fromStdString(my->getSkill(2)->getname()) + tr("  pp ") + QString::number(my->getpp(2)) + tr("\n威力 ") + QString::number(my->getSkill(2)->getpower()) + tr("  命中率 ") + QString::number(my->getSkill(2)->gethitrate()) + tr("%"));
        ui->label_3->setText(QString::fromStdString(enemy->getstatus()));
        ui->label_7->setText(QString::number(my->gethp()) + tr("/") + QString::number(my->getHP()));
        ui->pushButton->setEnabled(0);
        ui->pushButton_2->setEnabled(0);
        ui->pushButton_3->setEnabled(0);
        ui->pushButton_4->setEnabled(0);
        this->update();
        t_1->start(15);
    }
}

void BattleDialog::on_pushButton_4_clicked()
{
    if (my->getpp(3))
    {
        f_2 = 1;
        my->delpp(3);
        ui->textBrowser->moveCursor(QTextCursor::End);
        ui->textBrowser->insertPlainText(QString::fromStdString(my->getn() + "使用了" + my->getSkill(3)->getn() + "\n"));
        ui->textBrowser->moveCursor(QTextCursor::End);
        ui->textBrowser->insertPlainText(QString::fromStdString(my->getSkill(3)->hurt(my, enemy)));
        ui->pushButton_4->setText(QString::fromStdString(my->getSkill(3)->getname()) + tr("  pp ") + QString::number(my->getpp(3)) + tr("\n威力 ") + QString::number(my->getSkill(3)->getpower()) + tr("  命中率 ") + QString::number(my->getSkill(3)->gethitrate()) + tr("%"));
        ui->label_4->setText(QString::fromStdString(my->getstatus()));
        ui->label_3->setText(QString::fromStdString(enemy->getstatus()));
        ui->label_7->setText(QString::number(my->gethp()) + tr("/") + QString::number(my->getHP()));
        ui->pushButton->setEnabled(0);
        ui->pushButton_2->setEnabled(0);
        ui->pushButton_3->setEnabled(0);
        ui->pushButton_4->setEnabled(0);
        this->update();
        t_1->start(15);
    }
}

void BattleDialog::enemyfight()
{
    flag_2 = 1;
    f_1 = 1;
    f_3 = 1;
    string c = enemy->check();
    if (c == "-1")
    {
        ui->textBrowser->moveCursor(QTextCursor::End);
        ui->textBrowser->insertPlainText(QString::fromStdString(npc[xy] + "的" + enemy->getn() + "被麻痹了，该回合不能行动\n"));
        this->update();
        myfight();
    }
    else
    {
        ui->textBrowser->moveCursor(QTextCursor::End);
        ui->textBrowser->insertPlainText(QString::fromStdString(c));
        this->update();
        t_3->start(15);
        if (enemy->gethp() != 0)
        {
            int k = rand() % 4;
            while (enemy->getpp(k) == 0) k = rand() % 4;
            enemy->delpp(k);
            ui->textBrowser->moveCursor(QTextCursor::End);
            ui->textBrowser->insertPlainText(QString::fromStdString(enemy->getn() + "使用了" + enemy->getSkill(k)->getn() + "\n"));
            ui->textBrowser->moveCursor(QTextCursor::End);
            ui->textBrowser->insertPlainText(QString::fromStdString(enemy->getSkill(k)->hurt(enemy, my)));
            ui->label_4->setText(QString::fromStdString(my->getstatus()));
            ui->label_3->setText(QString::fromStdString(enemy->getstatus()));
            ui->label_7->setText(QString::number(my->gethp()) + tr("/") + QString::number(my->getHP()));
            this->update();
            t_2->start(15);
        }
    }
}

void BattleDialog::myfight()
{
    f_3 = 1;
    ui->pushButton->setEnabled(1);
    ui->pushButton_2->setEnabled(1);
    ui->pushButton_3->setEnabled(1);
    ui->pushButton_4->setEnabled(1);
    this->update();
    string c = my->check();
    if (c == "-1")
    {
        ui->textBrowser->moveCursor(QTextCursor::End);
        ui->textBrowser->insertPlainText(QString::fromStdString("你的" + my->getn() + "被麻痹了，该回合不能行动\n"));
        this->update();
        enemyfight();
    }
    else
    {
        ui->textBrowser->moveCursor(QTextCursor::End);
        ui->textBrowser->insertPlainText(QString::fromStdString(c));
        ui->label_7->setText(QString::number(my->gethp()) + tr("/") + QString::number(my->getHP()));
        this->update();
        t_3->start(15);
    }
}

void BattleDialog::continue_battle()
{
    flag_1 = 1;
    f_3 = 1;
    f_2 = 1;
    f_1 = 1;
    ui->pushButton->setEnabled(1);
    ui->pushButton_2->setEnabled(1);
    ui->pushButton_3->setEnabled(1);
    ui->pushButton_4->setEnabled(1);
    ui->textBrowser->moveCursor(QTextCursor::End);
    ui->textBrowser->insertPlainText(QString::fromStdString("你派出了" + my->getn() + "\n"));
    ui->label->setStyleSheet(attribute[my->getattribute()] + "font: 75 12pt \"微软雅黑\";color: rgb(255, 255, 255);");
    ui->label->setText(QString::fromStdString(my->getname()));
    ui->label_4->setText(QString::fromStdString(my->getstatus()));
    ui->pushButton->setText(QString::fromStdString(my->getSkill(0)->getname()) + tr("  pp ") + QString::number(my->getpp(0)) + tr("\n威力 ") + QString::number(my->getSkill(0)->getpower()) + tr("  命中率 ") + QString::number(my->getSkill(0)->gethitrate()) + tr("%"));
    ui->pushButton_2->setText(QString::fromStdString(my->getSkill(1)->getname()) + tr("  pp ") + QString::number(my->getpp(1)) + tr("\n威力 ") + QString::number(my->getSkill(1)->getpower()) + tr("  命中率 ") + QString::number(my->getSkill(1)->gethitrate()) + tr("%"));
    ui->pushButton_3->setText(QString::fromStdString(my->getSkill(2)->getname()) + tr("  pp ") + QString::number(my->getpp(2)) + tr("\n威力 ") + QString::number(my->getSkill(2)->getpower()) + tr("  命中率 ") + QString::number(my->getSkill(2)->gethitrate()) + tr("%"));
    ui->pushButton_4->setText(QString::fromStdString(my->getSkill(3)->getname()) + tr("  pp ") + QString::number(my->getpp(3)) + tr("\n威力 ") + QString::number(my->getSkill(3)->getpower()) + tr("  命中率 ") + QString::number(my->getSkill(3)->gethitrate()) + tr("%"));
    ui->progressBar->setMaximum(my->getHP());
    ui->progressBar->setValue(my->gethp());
    ui->label_2->setText(QString::fromStdString(enemy->getname()));
    ui->label_3->setText(QString::fromStdString(enemy->getstatus()));
    ui->progressBar_2->setMaximum(enemy->getHP());
    ui->progressBar_2->setValue(enemy->gethp());
    ui->label_7->setText(QString::number(my->gethp()) + tr("/") + QString::number(my->getHP()));
    ui->label_5->setStyleSheet(back_image[my->getnumber()]);
    this->show();
}
