//
// Created by zjp on 19-1-15.
//
/**
 * 装饰模式
 * https://blog.csdn.net/yongh701/article/details/49080311
 * 2012年上半年软件设计师的软考题
 * 某咖啡店当卖咖啡时，可以根据顾客的要求在其中加入各种配料，咖啡店会根据所加入的配料来计算费用。咖啡店所供应的咖啡及配料的种类和价格如下表所示。
 * 咖啡有两种：蒸馏咖啡Espresso 25元/杯，深度烘焙咖啡DarkRoast 20元/杯
 * 可以在咖啡里面加配料：摩卡Mocha 10元/份，奶泡Whip 8元/份
 * 现采用装饰器模式Decorator模式来实现计算费用的功能
 */
#include <iostream>
#include <cstring>
using namespace std;

//定义商品价格
const int ESPRESSO_PRICE = 25;
const int DARKROAST_PRICE = 20;
const int MOCHA_PRICE = 10;
const int WHIP_PRICE = 8;

class Beverage{
protected:
    string description;
public:
    virtual string getDescription(){//virtual不能省，否则找不到上一级Beverage
        return description;
    }
    virtual int cost() = 0;
};

class CondimentDecorater : public Beverage{//配料
protected:
    Beverage* beverage; //指针用于回溯已经存在的内容
public:
    ///构造函数不会被继承
//    CondimentDecorater(Beverage* beverage){
//        this->beverage = beverage;
//    }
//    virtual string getDescription(){
//        return beverage->getDescription();
//    }
//    virtual int cost(){
//        return beverage->cost();
//    }
};

//两种咖啡，构造函数都没有Beverage* beverage参数，只能作为基础，不能作为叠加上去的条件
class Espresso : public Beverage{
public:
    Espresso(){
        description = "Espresso";
    }
    int cost(){
        return ESPRESSO_PRICE;
    }
};

class DarkRoast : public Beverage{
public:
    DarkRoast(){
        description = "DarkRoast";
    }
    int cost(){
        return DARKROAST_PRICE;
    }
};

//两种装饰类，构造函数有Beverage* beverage参数
class Mocha : public CondimentDecorater{
public:
    Mocha(Beverage* beverage){
        this->beverage = beverage;
    }
    string getDescription(){
        return beverage->getDescription() + ",Mocha";
    }
    int cost(){
        return MOCHA_PRICE + beverage->cost();
    }
};

class Whip : public CondimentDecorater{
public:
    Whip(Beverage* beverage){
        this->beverage = beverage;
    }
    string getDescription(){
        return beverage->getDescription() + ",Whip";
    }
    int cost(){
        return WHIP_PRICE + beverage->cost();
    }
};

int main(){
    Beverage* beverage = new DarkRoast();
    beverage = new Mocha(beverage);
    beverage = new Whip(beverage);
    cout << beverage->getDescription() << " ￥" << beverage->cost() << endl;
    return 0;
}