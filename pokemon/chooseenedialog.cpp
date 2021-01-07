#include "chooseenedialog.h"
#include "ui_chooseenedialog.h"

ChooseeneDialog::ChooseeneDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseeneDialog)
{
    ui->setupUi(this);
}

ChooseeneDialog::~ChooseeneDialog()
{
    delete ui;
}

void ChooseeneDialog::ene_show(Pokemon *x, Pokemon *y, Pokemon *z)
{
    ene[0] = x;
    ene[1] = y;
    ene[2] = z;
    ui->pushButton->setStyleSheet(attribute[x->getattribute()] + "font: 75 12pt \"微软雅黑\";color: rgb(255, 255, 255);");
    ui->pushButton->setText(QString::fromStdString(x->getname()));
    ui->pushButton_2->setStyleSheet(attribute[y->getattribute()] + "font: 75 12pt \"微软雅黑\";color: rgb(255, 255, 255);");
    ui->pushButton_2->setText(QString::fromStdString(y->getname()));
    ui->pushButton_3->setStyleSheet(attribute[z->getattribute()] + "font: 75 12pt \"微软雅黑\";color: rgb(255, 255, 255);");
    ui->pushButton_3->setText(QString::fromStdString(z->getname()));
    this->show();
}

void ChooseeneDialog::on_pushButton_4_clicked()
{
    this->close();
    emit send_reply();
}

void ChooseeneDialog::reshow()
{
    this->show();
}

void ChooseeneDialog::on_pushButton_clicked()
{
    this->close();
    emit show_ene(ene[0]);
}

void ChooseeneDialog::on_pushButton_2_clicked()
{
    this->close();
    emit show_ene(ene[1]);
}

void ChooseeneDialog::on_pushButton_3_clicked()
{
    this->close();
    emit show_ene(ene[2]);
}
