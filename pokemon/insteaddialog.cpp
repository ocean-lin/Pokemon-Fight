#include "insteaddialog.h"
#include "ui_insteaddialog.h"

InsteadDialog::InsteadDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsteadDialog)
{
    ui->setupUi(this);
}

InsteadDialog::~InsteadDialog()
{
    delete ui;
}

void InsteadDialog::receive_ene(Pokemon *x)
{
    ene = x;
}

void InsteadDialog::start_instead(Pokemon *x, Pokemon *y, Pokemon *z)
{
    my[0] = x;
    my[1] = y;
    my[2] = z;
    ui->pushButton->setStyleSheet(attribute[x->getattribute()] + "font: 75 12pt \"微软雅黑\";color: rgb(255, 255, 255);");
    ui->pushButton->setText(QString::fromStdString(x->getname()));
    ui->pushButton_2->setStyleSheet(attribute[y->getattribute()] + "font: 75 12pt \"微软雅黑\";color: rgb(255, 255, 255);");
    ui->pushButton_2->setText(QString::fromStdString(y->getname()));
    ui->pushButton_3->setStyleSheet(attribute[z->getattribute()] + "font: 75 12pt \"微软雅黑\";color: rgb(255, 255, 255);");
    ui->pushButton_3->setText(QString::fromStdString(z->getname()));
    this->show();
}

void InsteadDialog::on_pushButton_clicked()
{
    this->close();
    emit send_choose(my[0], ene, 0);
}

void InsteadDialog::on_pushButton_2_clicked()
{
    this->close();
    emit send_choose(my[1], ene, 1);
}

void InsteadDialog::on_pushButton_3_clicked()
{
    this->close();
    emit send_choose(my[2], ene, 2);
}

void InsteadDialog::re_show()
{
    this->show();
}
