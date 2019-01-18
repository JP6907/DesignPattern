//
// Created by zjp on 19-1-15.
//
/**
 * 策略模式
 */
#include <iostream>
using namespace std;

//抽象算法类
class Strategy{
public:
    virtual void AlgorithmInterface() = 0;
};

//具体算法A
class ConcreteStrategyA : public Strategy{
public:
    void AlgorithmInterface() {
        cout << "算法A实现" << endl;
    }
};

//具体算法B
class ConcreteStrategyB : public Strategy{
public:
    void AlgorithmInterface(){
        cout << "算法B实现" << endl;
    }
};

//上下文,维护Strategy
class Context{
private:
    Strategy* strategy;
public:
    Context(Strategy* _strategy){
        strategy = _strategy;
    }
    //上下文接口
    void ContextInterface(){
        strategy->AlgorithmInterface();
    }
};

int main(){
    Context* context = new Context(new ConcreteStrategyA());
    context->ContextInterface();

    context = new Context(new ConcreteStrategyB());
    context->ContextInterface();

}