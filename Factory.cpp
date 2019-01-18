//
// Created by zjp on 19-1-16.
//
/**
 * 简单工厂 vs 工厂方法
 */
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Operation{
public:
    double numberA;
    double numberB;
    virtual double getResult() = 0;
};

class OperationAdd : public Operation{
    double getResult(){
        return this->numberA + this->numberB;
    }
};

class OperationSub : public Operation{
public:
    double getResult(){
        return this->numberA - this->numberB;
    }
};

class OperaionMul : public Operation{
public:
    double getResult(){
        return this->numberA * this->numberB;
    }
};

///简单工厂模式
class OperationFactory{
public:
    static Operation* createOperation(string operateType){
        Operation* oper = nullptr;
        if(operateType.compare("+")==0)
            oper = new OperationAdd();
        else if(operateType.compare("-")==0)
            oper = new OperationSub();
        else if(operateType.compare("*")==0)
            oper = new OperaionMul();
        return oper;
    }
};

///工厂方法
class IFactory{
public:
    virtual Operation* createOperation() = 0;
};
class AddFactory : public IFactory{
public:
    Operation* createOperation(){
        return new OperationAdd();
    }
};
class SubFactory : public IFactory{
public:
    Operation* createOperation(){
        return new OperationSub();
    }
};
class MulFactory : public IFactory{
public:
    Operation* createOperation(){
        return new OperaionMul();
    }
};

int main(){
    ///简单工厂
    Operation* oper = nullptr;
    oper = OperationFactory::createOperation("+");
    oper->numberA = 2;
    oper->numberB = 3;
    cout << oper->getResult() << endl;

    oper = OperationFactory::createOperation("-");
    oper->numberA = 2;
    oper->numberB = 3;
    cout << oper->getResult() << endl;

    oper = OperationFactory::createOperation("*");
    oper->numberA = 2;
    oper->numberB = 3;
    cout << oper->getResult() << endl;

    ///工厂方法
    IFactory* operFactory = new AddFactory();
    oper = operFactory->createOperation();
    oper->numberA = 2;
    oper->numberB = 3;
    cout << oper->getResult() << endl;

    operFactory = new SubFactory();
    oper = operFactory->createOperation();
    oper->numberA = 2;
    oper->numberB = 3;
    cout << oper->getResult() << endl;

    operFactory = new MulFactory();
    oper = operFactory->createOperation();
    oper->numberA = 2;
    oper->numberB = 3;
    cout << oper->getResult() << endl;

    return 0;
}