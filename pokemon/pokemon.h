#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <iostream>
using namespace std;

const string npc[20] = { "赤爷","皮皮曾","阿金","路比","戴亚蒙德","布莱克","拉克兹","艾克斯","喵喵","冠军渡","冠军大吾","冠军竹兰","冠军阿戴克","冠军艾莉丝","冠军卡露乃","库库伊博士","武藏&小次郎","阿罗拉小智","超梦","绿" };
extern bool fff[30];

class Pokemon;
class Skill;
extern Skill *skill[30];

class Pokemon
{
protected:
    string name; //名字
    Skill *sk[4]; //技能栏
    int pp[4]; //技能当前剩余使用次数
    int number; //编号
    int attribute, HP, hp, status, timer, attack, defense; //属性，生命，当前生命，状态，状态倒计时，攻击力，防御力
    double attackbuff, attackdebuff, defensebuff, defensedebuff; //攻击上升百分比，攻击下降百分比，防御上升百分比，防御下降百分比
    int Tattackbuff, Tattackdebuff, Tdefensebuff, Tdefensedebuff; //buff剩余时间
public:
    Pokemon(string, int, int, int, int, int);
    void injured(int); //受伤
    int getnumber();
    string check(); //检查当前状态
    string changestatus(int); //改变状态
    string replyhp(double); //回血
    string Dattackbuff(double); //攻击上升
    string Dattackdebuff(double); //攻击下降
    string Ddefensebuff(double); //防御上升
    string Ddefensedebuff(double); //防御下降
    void reply(); //全回复
    void delpp(int);
    string getstatus();
    int getHP();
    Skill* getSkill(int);
    string getname();
    string getn();
    int getpp(int);
    int getattribute();
    int gethp();
    int getattack();
    int getdefense();
    virtual ~Pokemon();
};

class Skill
{
protected:
    string name, description; //名字，描述
    int attribute, power, hitrate, pp; //属性，威力，命中率，使用次数
public:
    Skill(string, string, int, int, int, int);
    virtual string hurt(Pokemon *, Pokemon *) = 0; //攻击方式
    int getattribute();
    int getpp();
    int getpower();
    int gethitrate();
    string getname();
    string getn();
    string getdescription();
    virtual ~Skill();
};

class miaowahua :public Pokemon
{
public:
    miaowahua();
    ~miaowahua();
};

class dashihua :public Pokemon
{
public:
    dashihua();
    ~dashihua();
};

class yedanshu :public Pokemon
{
public:
    yedanshu();
    ~yedanshu();
};

class lada :public Pokemon
{
public:
    lada();
    ~lada();
};

class maolaoda :public Pokemon
{
public:
    maolaoda();
    ~maolaoda();
};

class daishou :public Pokemon
{
public:
    daishou();
    ~daishou();
};

class Penhuolong :public Pokemon
{
public:
    Penhuolong();
    ~Penhuolong();
};

class Lieyanma :public Pokemon
{
public:
    Lieyanma();
    ~Lieyanma();
};

class Jiuwei :public Pokemon
{
public:
    Jiuwei();
    ~Jiuwei();
};

class Shuijiangui :public Pokemon
{
public:
    Shuijiangui();
    ~Shuijiangui();
};

class Baoshihaixing :public Pokemon
{
public:
    Baoshihaixing();
    ~Baoshihaixing();
};

class Wenxiangyongshi :public Pokemon
{
public:
    Wenxiangyongshi();
    ~Wenxiangyongshi();
};

class kabishou :public Pokemon
{
public:
    kabishou();
    ~kabishou();
};

class xiyiwang :public Pokemon
{
public:
    xiyiwang();
    ~xiyiwang();
};

class huoyanji :public Pokemon
{
public:
    huoyanji();
    ~huoyanji();
};

class juzhaoguai :public Pokemon
{
public:
    juzhaoguai();
    ~juzhaoguai();
};

class feiyekuaidao :public Skill
{
public:
    feiyekuaidao();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class riguangshu :public Skill
{
public:
    riguangshu();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class dufen :public Skill
{
public:
    dufen();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class tenbian :public Skill
{
public:
    tenbian();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class feiyefengbao :public Skill
{
public:
    feiyefengbao();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class tiantianxiangqi :public Skill
{
public:
    tiantianxiangqi();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class xuli :public Skill
{
public:
    xuli();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class baiwandunzhongquan :public Skill
{
public:
    baiwandunzhongquan();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class fenlu :public Skill
{
public:
    fenlu();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class yaosui :public Skill
{
public:
    yaosui();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class zhongta :public Skill
{
public:
    zhongta();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class jizhangqixi :public Skill
{
public:
    jizhangqixi();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class chiersheng :public Skill
{
public:
    chiersheng();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class guiji :public Skill
{
public:
    guiji();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class liliangbaoshi :public Skill
{
public:
    liliangbaoshi();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class shuaida :public Skill
{
public:
    shuaida();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class lianxuquan :public Skill
{
public:
    lianxuquan();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class dengyan :public Skill
{
public:
    dengyan();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class Tiewei :public Skill
{
public:
    Tiewei();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class Dianguangyishan :public Skill
{
public:
    Dianguangyishan();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class Penshehuoyan :public Skill
{
public:
    Penshehuoyan();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class Huohua :public Skill
{
public:
    Huohua();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class Dazibaoyan :public Skill
{
public:
    Dazibaoyan();
    string hurt(Pokemon*p1, Pokemon*p2);
};

class Huoyanxuanwo :public Skill
{
public:
    Huoyanxuanwo();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class Paomoguangxian :public Skill
{
public:
    Paomoguangxian();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class Shuiqiang :public Skill
{
public:
    Shuiqiang();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class Shuipao :public Skill
{
public:
    Shuipao();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class Ronyanfengbao :public Skill
{
public:
    Ronyanfengbao();
    string hurt(Pokemon*p1, Pokemon*p2);
};

class Suorukezhong :public Skill
{
public:
    Suorukezhong();
    string hurt(Pokemon*p1, Pokemon*p2);
};

class Chonglang :public Skill
{
public:
    Chonglang();
    string hurt(Pokemon*p1, Pokemon*p2);
};

void Skill_initialization(); //技能初始化

Pokemon* randpokemon(); //随机生成宝可梦

class huangjinpipixia :public Pokemon
{
public:
    huangjinpipixia();
    ~huangjinpipixia();
};

class xianyutuchi1 :public Skill
{
public:
    xianyutuchi1();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class moyu :public Skill
{
public:
    moyu();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class fanshengyiji :public Skill
{
public:
    fanshengyiji();
    string hurt(Pokemon *p1, Pokemon *p2);
};

class duoyuyiji :public Skill
{
public:
    duoyuyiji();
    string hurt(Pokemon *p1, Pokemon *p2);
};

#endif // POKEMON_H
