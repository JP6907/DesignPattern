//
// Created by zjp on 19-1-16.
//
/**
 * 模板方法模式
 */
#include <iostream>
using namespace std;

class AbstractClass{
protected:
    //定义抽象方法，子类中实现
    virtual void PrimitiveOperation1() = 0;
    virtual void PrimitiveOperation2() = 0;
public:
    //模板方法，给出了实际的逻辑框架
    void TemplateMethod(){
        PrimitiveOperation1();
        PrimitiveOperation2();
        cout << "template method end" << endl;
    }
};

class ConcreteClassA : public AbstractClass{
protected:
    void PrimitiveOperation1(){
        cout << "具体类A方法1实现" << endl;
    }
    void PrimitiveOperation2(){
        cout << "具体类A方法2实现" << endl;
    }
};

class ConcreteClassB : public AbstractClass{
protected:
    void PrimitiveOperation1(){
        cout << "具体类B方法1实现" << endl;
    }
    void PrimitiveOperation2(){
        cout << "具体类B方法2实现" << endl;
    }
};

int main(){
    AbstractClass* ac;
    ac = new ConcreteClassA();
    ac->TemplateMethod();

    ac = new ConcreteClassB();
    ac->TemplateMethod();

    return 0;
}