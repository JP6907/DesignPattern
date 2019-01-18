//
// Created by zjp on 19-1-15.
//
/**
 * 简单工厂模式
 */
#include <cmath>
#include <iostream>
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

//现金收费工厂类
class CashFactory{
public:
    static CashSuper* createCashAccept(string type){
        if(type.compare("正常收费")==0){
            return new CashNormal;
        }else if(type.compare("满300减100")){
            return new CashReturn(300,100);
        }else if(type.compare("打8折")){
            return new CashRebate(0.8);
        }else{
            return nullptr;
        }
    }
};

int main(){
    double result = 0;
    CashSuper* cs = CashFactory::createCashAccept("正常收费");
    result = cs->acceptCash(100);
    cout << result << endl;

    cs = CashFactory::createCashAccept("满300减100");
    result = cs->acceptCash(300);
    cout << result << endl;

    cs = CashFactory::createCashAccept("打8折");
    result = cs->acceptCash(300);
    cout << result << endl;

    return 0;
}