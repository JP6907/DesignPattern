//
// Created by zjp on 19-1-15.
//
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

//现金收费抽象类
class CashSuper{
public:
    virtual double acceptCash(double money) = 0;
};

//正常收费子类
class CashNormal : public CashSuper{
public:
    double acceptCash(double money){
        return money;
    }
};

//打折收费子类
class CashRebate : public CashSuper{
private:
    double moneyRebae = 1.0;

public:
    CashRebate(double _moneyRebate){
        this->moneyRebae = _moneyRebate;
    }
    double acceptCash(double money){
        return money*moneyRebae;
    }
};

//返利收费子类
class CashReturn : public CashSuper{
private:
    double moneyCondition = 0.0;
    double moneyReturn = 0.0;

public:
    CashReturn(double _moneyCondition,double _moneyReturn){
        this->moneyCondition = _moneyCondition;
        this->moneyReturn = _moneyReturn;
    }
    double acceptCash(double money){
        double result = money;
        if(money>=moneyCondition)
            result = money - floor(money/moneyCondition)*moneyReturn;
        return result;
    }
};

class CashContext{
private:
    CashSuper* cs;
public:
    CashContext(CashSuper* csuper){
        this->cs = csuper;
    }
    double getResult(double money){
        return this->cs->acceptCash(money);
    }
};

//策略和简单厂结合
//客户端只需要认识CashContext一个类，使得收费算法彻底和客户端分离
//简单工厂模式需要Factory和CashSuper两个类
class CashContextFactory{
private:
    CashSuper* cs = nullptr;
public:
    CashContextFactory(string type){
        if(type.compare("正常收费")==0){
            cs = new CashNormal();
        }else if(type.compare("满300减100")==0){
            cs = new CashReturn(300,100);
        }else if(type.compare("打8折")==0){
            cs = new CashRebate(0.8);
        }
    }
    double getResult(double money){
        return cs->acceptCash(money);
    }
};

int main(){
    CashContext* cs = new CashContext(new CashNormal());
    double result = cs->getResult(100);
    cout << result << endl;

    cs = new CashContext(new CashRebate(0.8));
    result = cs->getResult(100);
    cout << result << endl;

    cs = new CashContext(new CashReturn(300,100));
    result = cs->getResult(300);
    cout << result << endl;

    CashContextFactory* csf = new CashContextFactory("正常收费");
    result = csf->getResult(100);
    cout << result << endl;

    csf = new CashContextFactory("满300减100");
    result = csf->getResult(300);
    cout << result << endl;

    csf = new CashContextFactory("打8折");
    result = csf->getResult(100);
    cout << result << endl;

    return 0;
}