#include "mainwindow.h"
#include "choosedialog.h"
#include "chooseenedialog.h"
#include "introenedialog.h"
#include "introducedialog.h"
#include "insteaddialog.h"
#include "intromydialog.h"
#include "battledialog.h"
#include "fightdialog.h"
#include <QApplication>
#include <time.h>
using namespace std;

int main(int argc, char *argv[])
{
    srand((unsigned)time(nullptr));
    QApplication a(argc, argv);
    MainWindow w;
    ChooseDialog choose_Dialog;
    IntroduceDialog Introduce_Dialog;
    FightDialog fight_dialog;
    BattleDialog battle_dialog;
    ChooseeneDialog choose_ene_dialog;
    introeneDialog intro_ene_dialog;
    InsteadDialog instead_dialog;
    intromyDialog intro_my_dialog;
    w.setWindowTitle(QObject::tr("Pokemon 战斗工厂"));
    choose_Dialog.setWindowTitle(QObject::tr("Pokemon 战斗工厂"));
    Introduce_Dialog.setWindowTitle(QObject::tr("Pokemon 战斗工厂"));
    fight_dialog.setWindowTitle(QObject::tr("Pokemon 战斗工厂"));
    battle_dialog.setWindowTitle(QObject::tr("Pokemon 战斗工厂"));
    choose_ene_dialog.setWindowTitle(QObject::tr("Pokemon 战斗工厂"));
    intro_ene_dialog.setWindowTitle(QObject::tr("Pokemon 战斗工厂"));
    instead_dialog.setWindowTitle(QObject::tr("Pokemon 战斗工厂"));
    intro_my_dialog.setWindowTitle(QObject::tr("Pokemon 战斗工厂"));
    w.show();
    QObject::connect(&w,SIGNAL(showchoosedialog()),&choose_Dialog,SLOT(receive_make_ChooseDialog()));
    QObject::connect(&choose_Dialog,SIGNAL(showintroducedialog(Pokemon*, int, int)),&Introduce_Dialog,SLOT(receivemake_IntroduceDialog(Pokemon*, int, int)));
    QObject::connect(&Introduce_Dialog,SIGNAL(show_choosedialog()),&choose_Dialog,SLOT(receivemake_ChooseDialog()));
    QObject::connect(&Introduce_Dialog,SIGNAL(choosepokemon(int)),&choose_Dialog,SLOT(hide_ChooseDialog(int)));
    QObject::connect(&Introduce_Dialog,SIGNAL(sendpokemon(Pokemon*, int)),&fight_dialog,SLOT(addmypokemon(Pokemon*, int)));
    QObject::connect(&choose_Dialog,SIGNAL(startfirst()),&fight_dialog,SLOT(startshow()));
    QObject::connect(&choose_Dialog,SIGNAL(initializationenemy()),&fight_dialog,SLOT(initialization()));
    QObject::connect(&fight_dialog,SIGNAL(sendpokemon(Pokemon*)),&battle_dialog,SLOT(receivemypokemon(Pokemon*)));
    QObject::connect(&fight_dialog,SIGNAL(sendenemypokemon(Pokemon*)),&battle_dialog,SLOT(receiveenemypokemon(Pokemon*)));
    QObject::connect(&fight_dialog,SIGNAL(showbattle(int)),&battle_dialog,SLOT(startbattle(int)));
    QObject::connect(&fight_dialog,SIGNAL(fail()),&w,SLOT(re_show()));
    QObject::connect(&battle_dialog,SIGNAL(choose_enemypokemon(Pokemon*)),&fight_dialog,SLOT(cenemypokemon(Pokemon*)));
    QObject::connect(&battle_dialog,SIGNAL(choose_mypokemon()),&fight_dialog,SLOT(re_show()));
    QObject::connect(&fight_dialog,SIGNAL(continuebattle()),&battle_dialog,SLOT(continue_battle()));
    QObject::connect(&fight_dialog,SIGNAL(win()),&w,SLOT(re_show()));
    QObject::connect(&fight_dialog,SIGNAL(win()),&battle_dialog,SLOT(next_hide()));
    QObject::connect(&fight_dialog,SIGNAL(fail()),&battle_dialog,SLOT(next_hide()));
    QObject::connect(&fight_dialog,SIGNAL(next_close()),&battle_dialog,SLOT(next_hide()));
    QObject::connect(&fight_dialog,SIGNAL(next_choose(Pokemon*, Pokemon*, Pokemon*)),&choose_ene_dialog,SLOT(ene_show(Pokemon*, Pokemon*, Pokemon*)));
    QObject::connect(&choose_ene_dialog,SIGNAL(send_reply()),&fight_dialog,SLOT(reply()));
    QObject::connect(&intro_ene_dialog,SIGNAL(show_chooseenedialog()),&choose_ene_dialog,SLOT(reshow()));
    QObject::connect(&choose_ene_dialog,SIGNAL(show_ene(Pokemon*)),&intro_ene_dialog,SLOT(receive_ene(Pokemon*)));
    QObject::connect(&intro_ene_dialog,SIGNAL(send_my()),&fight_dialog,SLOT(start_instead()));
    QObject::connect(&intro_ene_dialog,SIGNAL(send_ene(Pokemon*)),&instead_dialog,SLOT(receive_ene(Pokemon*)));
    QObject::connect(&fight_dialog,SIGNAL(next_instead(Pokemon*, Pokemon*, Pokemon*)),&instead_dialog,SLOT(start_instead(Pokemon*, Pokemon*, Pokemon*)));
    QObject::connect(&instead_dialog,SIGNAL(send_choose(Pokemon*, Pokemon*, int)),&intro_my_dialog,SLOT(receive_my(Pokemon*, Pokemon*, int)));
    QObject::connect(&intro_my_dialog,SIGNAL(instead_reshow()),&instead_dialog,SLOT(re_show()));
    QObject::connect(&intro_my_dialog,SIGNAL(send_choose(int, Pokemon*)),&fight_dialog,SLOT(receive_choose(int, Pokemon*)));
    return a.exec();
}
