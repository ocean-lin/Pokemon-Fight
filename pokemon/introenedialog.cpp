#include "introenedialog.h"
#include "ui_introenedialog.h"

introeneDialog::introeneDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::introeneDialog)
{
    t = new QTimer(this);
    t->stop();
    connect(t, SIGNAL(timeout()), this, SLOT(update_pokemon_move()));
    ui->setupUi(this);
}

introeneDialog::~introeneDialog()
{
    delete ui;
}

void introeneDialog::update_pokemon_move()
{
    f = (f + 1) % 4;
    ui->label_5->setStyleSheet(pokemon_move[xi->getnumber()][f]);
    this->update();
}

void introeneDialog::on_pushButton_clicked()
{
    this->close();
    emit show_chooseenedialog();
}

void introeneDialog::receive_ene(Pokemon *x)
{
    xi = x;
    f = 0;
    ui->label_5->setStyleSheet(pokemon_move[x->getnumber()][f]);
    t->start(250);
    ui->label->setStyleSheet(attribute[x->getattribute()] + "font: 75 12pt \"微软雅黑\";color: rgb(255, 255, 255);");
    ui->label->setText(QString::fromStdString(x->getname()));
    ui->label_2->setText(tr("HP ") + QString::number(x->getHP(),10,0) + tr("/") + QString::number(x->getHP(),10,0));
    ui->label_3->setText(tr("攻击力 ") + QString::number(x->getattack(),10,0));
    ui->label_4->setText(tr("防御力 ") + QString::number(x->getdefense(),10,0));
    ui->label_7->setStyleSheet(attribute[x->getSkill(0)->getattribute()] + "font: 75 12pt \"微软雅黑\";color: rgb(255, 255, 255);");
    ui->label_7->setText(QString::fromStdString(x->getSkill(0)->getname()));
    ui->label_8->setText(tr("pp ") + QString::number(x->getSkill(0)->getpp()) + tr("  威力 ") + QString::number(x->getSkill(0)->getpower()) + tr("  命中率 ") + QString::number(x->getSkill(0)->gethitrate()) + tr("%"));
    ui->label_9->setText(QString::fromStdString(x->getSkill(0)->getdescription()));
    ui->label_10->setStyleSheet(attribute[x->getSkill(1)->getattribute()] + "font: 75 12pt \"微软雅黑\";color: rgb(255, 255, 255);");
    ui->label_10->setText(QString::fromStdString(x->getSkill(1)->getname()));
    ui->label_11->setText(tr("pp ") + QString::number(x->getSkill(1)->getpp()) + tr("  威力 ") + QString::number(x->getSkill(1)->getpower()) + tr("  命中率 ") + QString::number(x->getSkill(1)->gethitrate()) + tr("%"));
    ui->label_12->setText(QString::fromStdString(x->getSkill(1)->getdescription()));
    ui->label_13->setStyleSheet(attribute[x->getSkill(2)->getattribute()] + "font: 75 12pt \"微软雅黑\";color: rgb(255, 255, 255);");
    ui->label_13->setText(QString::fromStdString(x->getSkill(2)->getname()));
    ui->label_14->setText(tr("pp ") + QString::number(x->getSkill(2)->getpp()) + tr("  威力 ") + QString::number(x->getSkill(2)->getpower()) + tr("  命中率 ") + QString::number(x->getSkill(2)->gethitrate()) + tr("%"));
    ui->label_15->setText(QString::fromStdString(x->getSkill(2)->getdescription()));
    ui->label_16->setStyleSheet(attribute[x->getSkill(3)->getattribute()] + "font: 75 12pt \"微软雅黑\";color: rgb(255, 255, 255);");
    ui->label_16->setText(QString::fromStdString(x->getSkill(3)->getname()));
    ui->label_17->setText(tr("pp ") + QString::number(x->getSkill(3)->getpp()) + tr("  威力 ") + QString::number(x->getSkill(3)->getpower()) + tr("  命中率 ") + QString::number(x->getSkill(3)->gethitrate()) + tr("%"));
    ui->label_18->setText(QString::fromStdString(x->getSkill(3)->getdescription()));
    this->show();
}

void introeneDialog::on_pushButton_2_clicked()
{
    emit send_my();
    emit send_ene(xi);
    this->close();
}
