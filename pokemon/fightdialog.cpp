#include "fightdialog.h"
#include "ui_fightdialog.h"

FightDialog::FightDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FightDialog)
{
    ui->setupUi(this);
}

FightDialog::~FightDialog()
{
    delete ui;
}

void FightDialog::addmypokemon(Pokemon *x,int n)
{
    mypokemon[n] = x;
}

void FightDialog::initialization()
{
    memset(fa, 0, sizeof(fa));
    m = 0;
}

void FightDialog::startshow()
{
    m++;
    l = r = 0;
    x = rand() % 21;
    while (fa[x]) x = rand() % 21;
    for (int j = 0; j < 3; j++) enemypokemon[j] = randpokemon();
    if (x == 1)
    {
        delete enemypokemon[0];
        enemypokemon[0] = new huangjinpipixia;
    }
    fa[x] = 1;
    int flag = QMessageBox::information(nullptr,tr("提示"),tr("第")+ QString::number(m,10,0) +tr("名对手是") + QString::fromStdString(npc[x]),QMessageBox::Ok);
    if (flag == QMessageBox::Ok) qDebug() << tr("提示");
    ui->label->setText(tr("请选择您的首发pokemon"));
    ui->pushButton->setStyleSheet(attribute[mypokemon[0]->getattribute()] + "font: 75 12pt \"微软雅黑\";color: rgb(255, 255, 255);");
    ui->pushButton->setText(QString::fromStdString(mypokemon[0]->getname()));
    ui->pushButton->show();
    ui->pushButton_2->setStyleSheet(attribute[mypokemon[1]->getattribute()] + "font: 75 12pt \"微软雅黑\";color: rgb(255, 255, 255);");
    ui->pushButton_2->setText(QString::fromStdString(mypokemon[1]->getname()));
    ui->pushButton_2->show();
    ui->pushButton_3->setStyleSheet(attribute[mypokemon[2]->getattribute()] + "font: 75 12pt \"微软雅黑\";color: rgb(255, 255, 255);");
    ui->pushButton_3->setText(QString::fromStdString(mypokemon[2]->getname()));
    ui->pushButton_3->show();
    this->show();
}


void FightDialog::on_pushButton_clicked()
{
    l++;
    emit sendpokemon(mypokemon[0]);
    ui->pushButton->hide();
    this->hide();
    if (l == 1)
    {
        cenemypokemon(mypokemon[0]);
        emit showbattle(x);
    }
    else
    {
        emit continuebattle();
    }
}

void FightDialog::cenemypokemon(Pokemon *p)
{
    r++;
    if (r <= 3)
    {
        int q = 0;
        for (int i = 0; i < 3; i++) if (enemypokemon[i]->gethp()!= 0) q = i;
        if (p->getattribute() != 0)
        {
            for (int i = 0; i < 3; i++)
                if ((p->getattribute() == 1) && (enemypokemon[i]->getattribute() != 2) && (enemypokemon[i]->gethp() != 0))
                {
                    q = i;
                    break;
                }
                else if ((p->getattribute() == 2) && (enemypokemon[i]->getattribute() != 3) && (enemypokemon[i]->gethp() != 0))
                {
                    q = i;
                    break;
                }
                else if ((p->getattribute() == 3) && (enemypokemon[i]->getattribute() != 1) && (enemypokemon[i]->gethp() != 0))
                {
                    q = i;
                    break;
                }
            for (int i = 0; i < 3; i++)
                if ((p->getattribute() == 1) && (enemypokemon[i]->getattribute() == 3) && (enemypokemon[i]->gethp() != 0))
                {
                    q = i;
                    break;
                }
                else if((p->getattribute() == 2) && (enemypokemon[i]->getattribute() == 1) && (enemypokemon[i]->gethp() != 0))
                {
                    q = i;
                    break;
                }
                else if ((p->getattribute() == 3) && (enemypokemon[i]->getattribute() == 2) && (enemypokemon[i]->gethp() != 0))
                {
                    q = i;
                    break;
                }
        }
        emit sendenemypokemon(enemypokemon[q]);
    }
    else if (m < 5)
    {
        emit next_close();
        emit next_choose(enemypokemon[0],enemypokemon[1],enemypokemon[2]);
    }
    else if (m==5)
    {
        this->close();
        int flag = QMessageBox::information(nullptr,tr("提示"),tr("恭喜你获得游戏的胜利！！！"),QMessageBox::Ok);
        if (flag == QMessageBox::Ok) qDebug() << tr("提示");
        emit win();
    }
}

void FightDialog::on_pushButton_2_clicked()
{
    l++;
    emit sendpokemon(mypokemon[1]);
    ui->pushButton_2->hide();
    this->hide();
    if (l == 1)
    {
        cenemypokemon(mypokemon[1]);
        emit showbattle(x);
    }
    else
    {
        emit continuebattle();
    }
}

void FightDialog::on_pushButton_3_clicked()
{
    l++;
    emit sendpokemon(mypokemon[2]);
    ui->pushButton_3->hide();
    this->hide();
    if (l == 1)
    {
        cenemypokemon(mypokemon[2]);
        emit showbattle(x);
    }
    else
    {
        emit continuebattle();
    }
}

void FightDialog::re_show()
{
    if (l < 3)
    {
        ui->label->setText(tr("请选择您的下一只pokemon"));
        this->show();
    }
    else
    {
        this->close();
        int flag = QMessageBox::information(nullptr,tr("提示"),tr("你失败了，请下次再挑战"),QMessageBox::Ok);
        if (flag == QMessageBox::Ok) qDebug() << tr("提示");
        emit fail();
    }
}

void FightDialog::reply()
{
    for (int i = 0; i < 3; i++) mypokemon[i]->reply();
    startshow();
}

void FightDialog::start_instead()
{
    emit next_instead(mypokemon[0],mypokemon[1],mypokemon[2]);
}

void FightDialog::receive_choose(int g, Pokemon *h)
{
    mypokemon[g] = h;
    reply();
}
