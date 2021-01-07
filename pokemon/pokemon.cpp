#include "pokemon.h"
#include<cstring>
using namespace std;

Skill *skill[30] = { nullptr }; //技能库
bool fff[30] = { 0 };

void Skill_initialization()
{
    if (skill[0] == nullptr)
    {

        skill[0] = new feiyekuaidao;
        skill[1] = new riguangshu;
        skill[2] = new dufen;
        skill[3] = new tenbian;
        skill[4] = new feiyefengbao;
        skill[5] = new tiantianxiangqi;
        skill[6] = new xuli;
        skill[7] = new baiwandunzhongquan;
        skill[8] = new fenlu;
        skill[9] = new yaosui;
        skill[10] = new zhongta;
        skill[11] = new jizhangqixi;
        skill[12] = new chiersheng;
        skill[13] = new guiji;
        skill[14] = new liliangbaoshi;
        skill[15] = new shuaida;
        skill[16] = new lianxuquan;
        skill[17] = new dengyan;
        skill[18] = new Tiewei;
        skill[19] = new Dianguangyishan;
        skill[20] = new Penshehuoyan;
        skill[21] = new Huohua;
        skill[22] = new Huoyanxuanwo;
        skill[23] = new Paomoguangxian;
        skill[24] = new Shuiqiang;
        skill[25] = new Shuipao;
        skill[26] = new Suorukezhong;
        skill[27] = new Chonglang;
        skill[28] = new Ronyanfengbao;
        skill[29] = new Dazibaoyan;
    }
}

Pokemon::Pokemon(string s, int a, int h, int at, int d, int n) :number(n), attribute(a), HP(h), attack(at), defense(d) //名字，属性，生命，攻击，防御，编号
{
    hp = HP;
    status = timer = 0;
    attackbuff = attackdebuff = defensebuff = defensedebuff = 0;
    Tattackbuff = Tattackdebuff = Tdefensebuff = Tdefensedebuff = 0;
    pp[0] = pp[1] = pp[2] = pp[3] = 0;
    name = s;
    for (int i = 0; i < 30; i++) fff[i] = 1;
    Skill_initialization();
    for (int i = 0; i < 4; i++)
    {
        while (1)
        {

            int t = rand() % 30;
            if ((fff[t]) && ((skill[t]->getattribute() == attribute) || (skill[t]->getattribute() == 0)))
            {
                sk[i] = skill[t];
                pp[i] = sk[i]->getpp();
                fff[t] = 0;
                break;
            }
        }
    }
}

void Pokemon::reply()
{
    hp = HP;
    status = timer = 0;
    attackbuff = attackdebuff = defensebuff = defensedebuff = 0;
    Tattackbuff = Tattackdebuff = Tdefensebuff = Tdefensedebuff = 0;
    for (int i = 0; i < 4; i++) pp[i] = sk[i]->getpp();
}

void Pokemon::injured(int h) { hp = hp - h < 0 ? 0 : hp - h; }

string Pokemon::check()
{
    string c = "";
    if (Tattackbuff)
    {
        --Tattackbuff;
        if (!Tattackbuff) attackbuff = 0;
    }
    if (Tattackdebuff)
    {
        --Tattackdebuff;
        if (!Tattackdebuff) attackdebuff = 0;
    }
    if (Tdefensebuff)
    {
        --Tdefensebuff;
        if (!Tdefensebuff) defensebuff = 0;
    }
    if (Tdefensedebuff)
    {
        --Tdefensedebuff;
        if (!Tdefensedebuff) defensedebuff = 0;
    }
    if (timer)
    {
        if (status == 1)
        {
            int s = HP / 16;
            c += name + "受到中毒伤害" + to_string(s) + "点\n";
            hp = hp - s < 0 ? 0 : hp - s;
        }
        else if (status == 2)
        {
            int s = HP / 16;
            c += name + "受到灼烧伤害" + to_string(s) + "点\n";
            hp = hp - s < 0 ? 0 : hp - s;
        }
        else if (status == 3)
        {
            int s = rand() % 101;
            if (s % 4 == 0) return "-1";
        }
        timer--;
        if (!timer) status = 0;
    }
    return c;
}

int Pokemon::gethp() { return hp; }

string Pokemon::getname()
{
    string s = name;
    if (attribute == 1) s += " 草";
    else if (attribute == 2) s += " 水";
    else if (attribute == 3) s += " 火";
    else if (attribute == 0) s += " 普通";
    return s;
}

int Pokemon::getpp(int x) { return pp[x]; }

int Pokemon::getattribute() { return attribute; }

int Pokemon::getattack() { return attack + (int)(attackbuff * (double)attack) - (int)(attackdebuff * (double)attack); }

int Pokemon::getdefense() { return defense + (int)(defensebuff * (double)defense) - (int)(defensedebuff * (double)defense); }

int Pokemon::getHP() { return HP; }

string Pokemon::getstatus()
{
    if (status == 1) return "中毒";
    else if (status == 2) return "烧伤";
    else if (status == 3) return "麻痹";
    else return "";
}

string Pokemon::changestatus(int x)
{
    string s = "";
    if (status == 0)
    {
        status = x;
        if (status == 1) s = name + "中毒了\n";
        else if (status == 2) s = name + "烧伤了\n";
        else if (status == 3) s = name + "麻痹了\n";
        timer = 4;
    }
    return s;
}

string Pokemon::replyhp(double x)
{
    int h = (int)(HP * x);
    hp = hp + h > HP ? HP : hp + h;
    return name + "回复了" + to_string(h) + "点生命\n";
}

string Pokemon::Dattackbuff(double d)
{
    if (attackbuff != 0.0) return name + "的攻击已经不能在上升\n";
    else
    {
        attackbuff = d;
        Tattackbuff = 4;
        return name + "的攻击上升了\n";
    }
}

string Pokemon::Dattackdebuff(double d)
{
    if (attackdebuff != 0.0) return name + "的攻击已经不能在下降\n";
    else
    {
        attackdebuff = d;
        Tattackdebuff = 4;
        return name + "的攻击下降了\n";
    }
}

string Pokemon::Ddefensebuff(double d)
{
    if (defensebuff != 0.0) return name + "的防御已经不能在上升\n";
    else
    {
        defensebuff = d;
        Tdefensebuff = 4;
        return name + "的防御上升了\n";
    }
}

int Pokemon::getnumber() { return number; }
void Pokemon::delpp(int x) { pp[x]--; }

string Pokemon::Ddefensedebuff(double d)
{
    if (defensedebuff != 0.0) return name + "的防御已经不能在下降\n";
    else
    {
        defensedebuff = d;
        Tdefensedebuff = 4;
        return name + "的防御下降了\n";
    }
}

Skill* Pokemon::getSkill(int x) { return sk[x]; }

string Pokemon::getn()
{
    return name;
}

Pokemon::~Pokemon() {}

Skill::Skill(string c, string s, int a, int p, int h, int x) :attribute(a), power(p), hitrate(h), pp(x) //名字，描述，属性，威力，命中率，使用次数
{
    name = c;
    description = s;
}

string Skill::getn()
{
    return name;
}

string Skill::getname()
{
    string s = name;
    if (attribute == 1) s += " 草";
    else if (attribute == 2) s += " 水";
    else if (attribute == 3) s += " 火";
    else if (attribute == 0) s += " 普通";
    return s;
}

int Skill::getattribute() { return attribute; }

int Skill::getpp() { return pp; }

int Skill::getpower() { return power; }

int Skill::gethitrate() { return hitrate; }

string Skill::getdescription() { return description; }

Skill::~Skill() {}

miaowahua::miaowahua() :Pokemon("妙蛙花", 1, 270, 209, 171, 0)
{
    attack += rand() % 31 + 1;
    defense += rand() % 31 + 1;
    HP += rand() % 31 + 1;
    hp = HP;
}

miaowahua::~miaowahua() {}

dashihua::dashihua() :Pokemon("大食花", 1, 270, 215, 155, 1)
{
    HP += rand() % 31 + 1;
    attack += rand() % 31 + 1;
    defense += rand() % 31 + 1;
    hp = HP;
}

dashihua::~dashihua() {}

yedanshu::yedanshu() :Pokemon("椰蛋树", 1, 300, 175, 185, 2)
{
    HP += rand() % 31 + 1;
    attack += rand() % 31 + 1;
    defense += rand() % 31 + 1;
    hp = HP;
}

yedanshu::~yedanshu() {}

lada::lada() :Pokemon("拉达", 0, 220, 201, 155, 3)
{
    HP += rand() % 31 + 1;
    attack += rand() % 31 + 1;
    defense += rand() % 31 + 1;
    hp = HP;
}

lada::~lada() {}

maolaoda::maolaoda() :Pokemon("猫老大", 0, 240, 175, 175, 4)
{
    HP += rand() % 31 + 1;
    attack += rand() % 31 + 1;
    defense += rand() % 31 + 1;
    hp = HP;
}

maolaoda::~maolaoda() {}

daishou::daishou() :Pokemon("袋兽", 0, 320, 195, 165, 5)
{
    HP += rand() % 31 + 1;
    hp = HP;
    attack += rand() % 31 + 1;
    defense += rand() % 31 + 1;
}

daishou::~daishou() {}

Penhuolong::Penhuolong() :Pokemon("喷火龙", 3, 266, 210, 175, 6)
{
    attack += rand() % 31 + 1;
    defense += rand() % 31 + 1;
    HP += rand() % 31 + 1;
    hp = HP;
}

Penhuolong::~Penhuolong() {}

Lieyanma::Lieyanma() :Pokemon("烈焰马", 3, 240, 215, 155, 7)
{
    attack += rand() % 31 + 1;
    defense += rand() % 31 + 1;
    HP += rand() % 31 + 1;
    hp = HP;
}

Lieyanma::~Lieyanma() {}

Jiuwei::Jiuwei() :Pokemon("九尾", 3, 256, 195, 185, 8)
{
    attack += rand() % 31 + 1;
    defense += rand() % 31 + 1;
    HP += rand() % 31 + 1;
    hp = HP;
}

Jiuwei::~Jiuwei() {}

Shuijiangui::Shuijiangui() :Pokemon("水箭龟", 2, 278, 181, 215, 9)
{
    attack += rand() % 31 + 1;
    defense += rand() % 31 + 1;
    HP += rand() % 31 + 1;
    hp = HP;
}

Shuijiangui::~Shuijiangui() {}

Baoshihaixing::Baoshihaixing() :Pokemon("宝石海星", 2, 220, 175, 185, 10)
{
    HP += rand() % 31 + 1;
    hp = HP;
    attack += rand() % 31 + 1;
    defense += rand() % 31 + 1;
}

Baoshihaixing::~Baoshihaixing() {}

Wenxiangyongshi::Wenxiangyongshi() :Pokemon("蚊香泳士", 2, 290, 195, 195, 11)
{
    attack += rand() % 31 + 1;
    defense += rand() % 31 + 1;
    HP += rand() % 31 + 1;
    hp = HP;
}

Wenxiangyongshi::~Wenxiangyongshi() {}

kabishou::kabishou() :Pokemon("卡比兽", 0, 430, 225, 135, 12)
{
    attack += rand() % 31 + 1;
    defense += rand() % 31 + 1;
    HP += rand() % 31 + 1;
    hp = HP;
}

kabishou::~kabishou() {}

xiyiwang::xiyiwang() :Pokemon("蜥蜴王", 1, 250, 200, 175, 13)
{
    attack += rand() % 31 + 1;
    defense += rand() % 31 + 1;
    HP += rand() % 31 + 1;
    hp = HP;
}

xiyiwang::~xiyiwang() {}

huoyanji::huoyanji() :Pokemon("火焰鸡", 3, 270, 245, 145, 14)
{
    attack += rand() % 31 + 1;
    defense += rand() % 31 + 1;
    HP += rand() % 31 + 1;
    hp = HP;
}

huoyanji::~huoyanji() {}

juzhaoguai::juzhaoguai() :Pokemon("巨沼怪", 2, 310, 215, 175, 15)
{
    attack += rand() % 31 + 1;
    defense += rand() % 31 + 1;
    HP += rand() % 31 + 1;
    hp = HP;
}

juzhaoguai::~juzhaoguai() {}

feiyekuaidao::feiyekuaidao() :Skill("飞叶快刀", "攻击目标造成伤害,30%概率造成\n伤害比普通招式高20%", 1, 55, 95, 25) {};

string feiyekuaidao::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int t = rand() % 100 + 1;
    int h = (int)((100 * 0.4 + 2) * 55 * p1->getattack() / p2->getdefense() / 50 + 2) * 220 / 255;
    if (t <= 30) h = (int)(h * 1.2);
    t = rand() % 100 + 1;
    if (t <= 95)
    {
        if (p2->getattribute() == 2) h *= 2;
        else if (p2->getattribute() == 3) h /= 2;
        p2->injured(h);
        s = p2->getn() + "受到了" + to_string(h) + "点伤害\n";
    }
    else s += p2->getn() + "闪避了\n";
    return s;
}

riguangshu::riguangshu() :Skill("日光束", "使用日光束的宝可梦在攻击后攻击\n防御均下降30%", 1, 150, 100, 5) {};

string riguangshu::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int h = (int)((100 * 0.4 + 2) * 200 * p1->getattack() / p2->getdefense() / 50 + 2) * 220 / 255;
    if (p2->getattribute() == 2) h *= 2;
    else if (p2->getattribute() == 3) h /= 2;
    p2->injured(h);
    s = p2->getn() + "受到了" + to_string(h) + "点伤害\n";
    s += p1->Dattackdebuff(0.3);
    s += p1->Ddefensedebuff(0.3);
    return s;
}

dufen::dufen() :Skill("毒粉", "毒粉会使目标陷入中毒状态", 1, 0, 75, 35) {};

string dufen::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int t = rand() % 100 + 1;
    if (t <= 75) s += p2->changestatus(1);
    else s += p2->getn() + "闪避了\n";
    return s;
}

tenbian::tenbian() :Skill("藤鞭", "攻击目标造成伤害", 1, 45, 100, 25) {};

string tenbian::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int h = (int)((100 * 0.4 + 2) * 45 * p1->getattack() / p2->getdefense() / 50 + 2) * 220 / 255;
    if (p2->getattribute() == 2) h *= 2;
    else if (p2->getattribute() == 3) h /= 2;
    p2->injured(h);
    s = p2->getn() + "受到了" + to_string(h) + "点伤害\n";
    return s;
}

feiyefengbao::feiyefengbao() :Skill("飞叶风暴", "攻击目标造成伤害并且自身攻击\n下降30%", 1, 130, 90, 5) {};

string feiyefengbao::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int t = rand() % 100 + 1;
    int h = (int)((100 * 0.4 + 2) * 130 * p1->getattack() / p2->getdefense() / 50 + 2) * 220 / 255;
    if (t <= 90)
    {
        if (p2->getattribute() == 2) h *= 2;
        else if (p2->getattribute() == 3) h /= 2;
        p2->injured(h);
        s = p2->getn() + "受到了" + to_string(h) + "点伤害\n";
        s += p1->Dattackdebuff(0.3);
    }
    else s += p2->getn() + "闪避了\n";
    return s;
}

tiantianxiangqi::tiantianxiangqi() :Skill("甜甜香气", "大概率使敌人麻痹", 1, 0, 75, 10) {};

string tiantianxiangqi::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int t = rand() % 100 + 1;
    if (t <= 75) s += p2->changestatus(3);
    else s += p2->getn() + "闪避了\n";
    return s;
}

xuli::xuli() :Skill("蓄力", "令使用者的防御攻击提升20%", 0, 0, 10, 5) {};

string xuli::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    s += p1->Dattackbuff(0.2);
    s += p1->Ddefensebuff(0.2);
    return s;
}

fenlu::fenlu() :Skill("愤怒", "攻击目标造成伤害并提高自身攻\n击20%", 0, 20, 100, 20) {};

string fenlu::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int h = (int)((100 * 0.4 + 2) * 20 * p1->getattack() / p2->getdefense() / 50 + 2) * 220 / 255;
    p2->injured(h);
    s = p2->getn() + "受到了" + to_string(h) + "点伤害\n";
    s += p1->Dattackbuff(0.2);
    return s;
}

baiwandunzhongquan::baiwandunzhongquan() :Skill("百万吨重拳", "攻击目标造成伤害", 0, 80, 85, 20) {};

string baiwandunzhongquan::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int t = rand() % 100 + 1;
    int h = (int)((100 * 0.4 + 2) * 80 * p1->getattack() / p2->getdefense() / 50 + 2) * 220 / 255;
    if (t <= 85)
    {
        p2->injured(h);
        s = p2->getn() + "受到了" + to_string(h) + "点伤害\n";
    }
    else s += p2->getn() + "闪避了\n";
    return s;
}

yaosui::yaosui() :Skill("咬碎", "攻击目标造成伤害，20%几率令目标\n的防御降低10%", 0, 80, 100, 15) {};

string yaosui::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int h = (int)((100 * 0.4 + 2) * 80 * p1->getattack() / p2->getdefense() / 50 + 2) * 220 / 255;
    p2->injured(h);
    s = p2->getn() + "受到了" + to_string(h) + "点伤害\n";
    int t = rand() % 100 + 1;
    if (t <= 20) s += p2->Ddefensedebuff(0.1);
    return s;
}

zhongta::zhongta() :Skill("重踏", "攻击目标造成伤害，令目标的防御\n降低10%", 0, 70, 100, 20) {};

string zhongta::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int h = (int)((100 * 0.4 + 2) * 70 * p1->getattack() / p2->getdefense() / 50 + 2) * 220 / 255;
    p2->injured(h);
    s = p2->getn() + "受到了" + to_string(h) + "点伤害\n";
    s += p2->Ddefensedebuff(0.1);
    return s;
}

jizhangqixi::jizhangqixi() :Skill("击掌奇袭", "攻击目标造成伤害", 0, 100, 75, 10) {};

string jizhangqixi::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int t = rand() % 100 + 1;
    int h = (int)((100 * 0.4 + 2) * 100 * p1->getattack() / p2->getdefense() / 50 + 2) * 220 / 255;
    if (t <= 75)
    {
        p2->injured(h);
        s = p2->getn() + "受到了" + to_string(h) + "点伤害\n";
    }
    else s += p2->getn() + "闪避了\n";
    return s;
}

chiersheng::chiersheng() :Skill("刺耳声", "令目标的防御降低30%", 0, 0, 100, 10) {};

string chiersheng::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    s += p2->Ddefensedebuff(0.3);
    return s;
}

guiji::guiji() :Skill("诡计", "令使用者的攻击提升30%", 0, 0, 100, 8) {};

string guiji::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    s += p1->Dattackbuff(0.3);
    return s;
}

liliangbaoshi::liliangbaoshi() :Skill("力量宝石", "攻击目标造成伤害", 0, 80, 100, 20) {};

string liliangbaoshi::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int h = (int)((100 * 0.4 + 2) * 80 * p1->getattack() / p2->getdefense() / 50 + 2) * 220 / 255;
    p2->injured(h);
    s = p2->getn() + "受到了" + to_string(h) + "点伤害\n";
    return s;
}

shuaida::shuaida() :Skill("摔打", "攻击目标造成伤害", 0, 90, 75, 15) {};

string shuaida::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int t = rand() % 100 + 1;
    int h = (int)((100 * 0.4 + 2) * 90 * p1->getattack() / p2->getdefense() / 50 + 2) * 220 / 255;
    if (t <= 75)
    {
        p2->injured(h);
        s = p2->getn() + "受到了" + to_string(h) + "点伤害\n";
    }
    else s += p2->getn() + "闪避了\n";
    return s;
}

lianxuquan::lianxuquan() :Skill("连续拳", "多次攻击目标造成伤害", 0, 25, 85, 20) {};

string lianxuquan::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int t = rand() % 100 + 1;
    int h = (int)((100 * 0.4 + 2) * 25 * p1->getattack() / p2->getdefense() / 50 + 2) * 220 / 255;
    if (t <= 85)
    {
        p2->injured(h);
        s += p2->getn() + "受到了" + to_string(h) + "点伤害\n";
        p2->injured(h);
        s += p2->getn() + "受到了" + to_string(h) + "点伤害\n";
        p2->injured(h);
        s += p2->getn() + "受到了" + to_string(h) + "点伤害\n";
    }
    else s += p2->getn() + "闪避了\n";
    return s;
}

dengyan::dengyan() :Skill("瞪眼", "令目标的防御降低20%", 0, 0, 85, 10) {};

string dengyan::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int t = rand() % 100 + 1;
    if (t <= 85) s += p2->Ddefensedebuff(0.2);
    else s += p2->getn() + "闪避了\n";
    return s;
}

Tiewei::Tiewei() :Skill("铁尾", "使用坚硬的尾巴摔打对手进行攻击，10%\n会降低对手的防御", 0, 100, 75, 15) {}

string Tiewei::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int t = rand() % 100 + 1;
    int h = (int)((100 * 0.4 + 2) * 100 * p1->getattack() / p2->getdefense() / 50 + 2) * 220 / 255;
    if (t <= 75)
    {
        p2->injured(h);
        s = p2->getn() + "受到了" + to_string(h) + "点伤害\n";
        if (t <= 10) s += p2->Ddefensedebuff(0.1);
    }
    else s += p2->getn() + "闪避了\n";
    return s;
}

Dianguangyishan::Dianguangyishan() :Skill("电光一闪", "以迅雷不及掩耳之势扑向对手造\n成一定伤害", 0, 40, 100, 30) {}

string Dianguangyishan::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int h = (int)((100 * 0.4 + 2) * 40 * p1->getattack() / p2->getdefense() / 50 + 2) * 220 / 255;
    p2->injured(h);
    s = p2->getn() + "受到了" + to_string(h) + "点伤害\n";
    return s;
}

Penshehuoyan::Penshehuoyan() :Skill("喷射火焰", "向对手发射烈焰进行攻击,有时会让\n对手陷入灼伤状态", 3, 90, 100, 15) {}

string Penshehuoyan::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int t = rand() % 100 + 1;
    int h = (int)((100 * 0.4 + 2) * 90 * p1->getattack() / p2->getdefense() / 50 + 2) * 220 / 255;
    if (p2->getattribute() == 1) h *= 2;
    else if (p2->getattribute() == 2) h /= 2;
    p2->injured(h);
    s = p2->getn() + "受到了" + to_string(h) + "点伤害\n";
    if (t <= 10) s += p2->changestatus(2);
    return s;
}

Dazibaoyan::Dazibaoyan() :Skill("大字爆炎", "用大字形状的火焰烧尽对手，有时会让\n对手陷入灼伤状态。", 3, 110, 85, 5) {}

string Dazibaoyan::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int h = (int)((100 * 0.4 + 2) * 110 * p1->getattack() / p2->getdefense() / 50 + 2) * 220 / 255;
    int t = rand() % 100 + 1;
    if (t <= 85)
    {
        if (p2->getattribute() == 1) h *= 2;
        else if (p2->getattribute() == 2) h /= 2;
        p2->injured(h);
        s += p2->getn() + "受到了" + to_string(h) + "点伤害\n";
        if (t <= 10) s += p2->changestatus(2);
    }
    else s = p2->getn() + "闪避了\n";
    return s;
}

Huohua::Huohua() :Skill("火花", "向对手发射小型火焰进行攻击,有时会\n让对手陷入灼伤状态", 3, 40, 100, 25) {}

string Huohua::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int t = rand() % 100 + 1;
    int h = (int)((100 * 0.4 + 2) * 40 * p1->getattack() / p2->getdefense() / 50 + 2) * 220 / 255;
    if (p2->getattribute() == 1) h *= 2;
    else if (p2->getattribute() == 2) h /= 2;
    p2->injured(h);
    s = p2->getn() + "受到了" + to_string(h) + "点伤害\n";
    if (t <= 10) s += p2->changestatus(2);
    return s;
}

Ronyanfengbao::Ronyanfengbao() :Skill("熔岩风暴", "将对手困在熊熊燃烧的火焰中进行\n攻击", 3, 100, 75, 5) {}

string Ronyanfengbao::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int h = (int)((100 * 0.4 + 2) * 100 * p1->getattack() / p2->getdefense() / 50 + 2) * 220 / 255;
    int t = rand() % 100 + 1;
    if (t <= 75)
    {
        if (p2->getattribute() == 1) h *= 2;
        else if (p2->getattribute() == 2) h /= 2;
        p2->injured(h);
        s = p2->getn() + "受到了" + to_string(h) + "点伤害\n";
    }
    else s = p2->getn() + "闪避了\n";
    return s;
}

Huoyanxuanwo::Huoyanxuanwo() :Skill("火焰漩涡", "将对手困在激烈的火焰旋涡中，在４\n回合内进行攻击。", 3, 35, 85, 15) {}

string Huoyanxuanwo::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int t = rand() % 100 + 1;
    int h = (int)((100 * 0.4 + 2) * 35 * p1->getattack() / p2->getdefense() / 50 + 2) * 220 / 255;
    if (t <= 85)
    {
        if (p2->getattribute() == 1) h *= 2;
        else if (p2->getattribute() == 2) h /= 2;
        p2->injured(h);
        s = p2->getn() + "受到了" + to_string(h) + "点伤害\n";
        s += p2->changestatus(2);
    }
    else s = p2->getn() + "闪避了\n";
    return s;
}

Paomoguangxian::Paomoguangxian() :Skill("泡沫光线", "向对手猛烈地喷射泡沫进行攻击", 2, 65, 100, 20) {}

string Paomoguangxian::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int h = (int)((100 * 0.4 + 2) * 65 * p1->getattack() / p2->getdefense() / 50 + 2) * 220 / 255;
    if (p2->getattribute() == 3) h *= 2;
    else if (p2->getattribute() == 1)  h /= 2;
    p2->injured(h);
    s = p2->getn() + "受到了" + to_string(h) + "点伤害\n";
    return s;
}

Shuiqiang::Shuiqiang() :Skill("水枪", "向对手猛烈地喷射水流进行攻击", 2, 40, 100, 25) {}

string Shuiqiang::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int h = (int)((100 * 0.4 + 2) * 40 * p1->getattack() / p2->getdefense() / 50 + 2) * 220 / 255;
    if (p2->getattribute() == 3) h *= 2;
    else if (p2->getattribute() == 1)  h /= 2;
    p2->injured(h);
    s += p2->getn() + "受到了" + to_string(h) + "点伤害\n";
    return s;
}

Suorukezhong::Suorukezhong() :Skill("缩入壳中", "缩入壳里保护身体，从而提高自己\n的防御", 2, 0, 100, 40) {}
string Suorukezhong::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    s += p1->Ddefensebuff(0.3);
    return s;
}

Chonglang::Chonglang() :Skill("冲浪", "利用大浪攻击自己周围所有的宝可梦", 2, 90, 100, 15) {}

string Chonglang::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int h = (int)((100 * 0.4 + 2) * 90 * p1->getattack() / p2->getdefense() / 50 + 2) * 220 / 255;
    if (p2->getattribute() == 3) h *= 2;
    else if (p2->getattribute() == 1)  h /= 2;
    p2->injured(h);
    s = p2->getn() + "受到了" + to_string(h) + "点伤害\n";
    return s;
}

Shuipao::Shuipao() :Skill("水炮", "向对手猛烈地喷射大量水流进行攻击,\n有%33.3的概率使对方防御减少%15", 2, 120, 80, 5) {}

string Shuipao::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int t = rand() % 100 + 1;
    int h = (int)((100 * 0.4 + 2) * 110 * p1->getattack() / p2->getdefense() / 50 + 2) * 220 / 255;
    if (t <= 80)
    {
        if (p2->getattribute() == 3) h *= 2;
        else if (p2->getattribute() == 1)  h /= 2;
        p2->injured(h);
        s += p2->getn() + "受到了" + to_string(h) + "点伤害\n";
        if (t <= 33) s += p2->Ddefensedebuff(0.15);
    }
    else s += p2->getn() + "闪避了\n";
    return s;
}

Pokemon* randpokemon()
{
    int x = rand() % 16;
    Pokemon *a = nullptr;
    if (x == 0) a = new miaowahua;
    else if(x == 1) a = new dashihua;
    else if (x == 2) a = new yedanshu;
    else if (x == 3) a = new lada;
    else if (x == 4) a = new maolaoda;
    else if (x == 5) a = new daishou;
    else if (x == 6) a = new Penhuolong;
    else if (x == 7) a = new Jiuwei;
    else if (x == 8) a = new Lieyanma;
    else if (x == 9) a = new Shuijiangui;
    else if (x == 10) a = new Baoshihaixing;
    else if (x == 11) a = new Wenxiangyongshi;
    else if (x == 12) a = new kabishou;
    else if (x == 13) a = new xiyiwang;
    else if (x == 14) a = new huoyanji;
    else if (x == 15) a = new juzhaoguai;
    return a;
}

huangjinpipixia::huangjinpipixia() :Pokemon("黄金皮皮虾", 2, 322, 185, 265, 16)
{
    HP += rand() % 31 + 1;
    attack += rand() % 31 + 1;
    defense += rand() % 31 + 1;
    hp = HP;
    sk[0] = new xianyutuchi1;
    pp[0] = sk[0]->getpp();
    sk[1] = new duoyuyiji;
    pp[1] = sk[1]->getpp();
    sk[2] = new fanshengyiji;
    pp[2] = sk[2]->getpp();
    sk[3] = new moyu;
    pp[3] = sk[3]->getpp();
}

huangjinpipixia::~huangjinpipixia() {}

xianyutuchi1::xianyutuchi1() :Skill("咸鱼突刺一式", "说出来你可能不信，是咸鱼先动\n的手", 2, 66, 100, 15) {};

string xianyutuchi1::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int h = (int)((100 * 0.4 + 2) * 66 * p1->getattack() / p2->getdefense() / 50 + 2) * 220 / 255;
    if (p2->getattribute() == 3) h *= 2;
    else if (p2->getattribute() == 1)  h /= 2;
    p2->injured(h);
    s = p2->getn() + "受到了" + to_string(h) + "点伤害\n";
    return s;
}

moyu::moyu() :Skill("摸鱼", "乘对方不注意稍微摸鱼一把，使自身\n回复1/2的血量，但会使自己被麻痹", 2, 0, 100, 5) {};

string moyu::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    s += p1->changestatus(3);
    s += p1->replyhp(0.5);
    return s;
}

duoyuyiji::duoyuyiji() :Skill("多鱼一击", "扔出多余的鱼，对敌方造成2次伤害", 2, 60, 70, 20) {};

string duoyuyiji::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int h = (int)((100 * 0.4 + 2) * 60 * p1->getattack() / p2->getdefense() / 50 + 2) * 220 / 255;
    int t = rand() % 100 + 1;
    if (t <= 70)
    {
        if (p2->getattribute() == 3) h *= 2;
        else if (p2->getattribute() == 1)  h /= 2;
        p2->injured(h);
        s = p2->getn() + "受到了" + to_string(h) + "点伤害\n";
        p2->injured(h);
        s += p2->getn() + "受到了" + to_string(h) + "点伤害\n";
    }
    else s += p2->getn() + "闪避了\n";
    return s;
}

fanshengyiji::fanshengyiji() :Skill("翻身一击", "翻身大倒苦水，对敌方造成大量伤\n害，并使对方愤怒并提高对方10%\n攻击", 2, 100, 100, 15) {};

string fanshengyiji::hurt(Pokemon *p1, Pokemon *p2)
{
    string s = "";
    int h = (int)((100 * 0.4 + 2) * 100 * p1->getattack() / p2->getdefense() / 50 + 2) * 220 / 255;
    if (p2->getattribute() == 3) h *= 2;
    else if (p2->getattribute() == 1)  h /= 2;
    p2->injured(h);
    s = p2->getn() + "受到了" + to_string(h) + "点伤害\n";
    s += p2->Dattackbuff(0.1);
    return s;
}
