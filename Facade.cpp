//
// Created by zjp on 19-1-16.
//
/**
 * 外观模式
 */
#include <iostream>
using namespace std;

class SubsystemOne{
public:
    void method1(){
        cout << "子系统方法一" << endl;
    }
};

class SubsystemTwo{
public:
    void method2(){
        cout << "子系统方法二" << endl;
    }
};

class SubsystemThree{
public:
    void method3(){
        cout << "子系统方法三" << endl;
    }
};

class Facde{
private:
    SubsystemOne* one;
    SubsystemTwo* two;
    SubsystemThree* three;
public:
    Facde(){
        one = new SubsystemOne();
        two = new SubsystemTwo();
        three = new SubsystemThree();
    }

    void MethodA(){
        cout << "方法组A:" << endl;
        one->method1();
        two->method2();
    }

    void MethodB(){
        cout << "方法组B:" << endl;
        one->method1();
        three->method3();
    }
};

int main(){
    Facde* facde = new Facde();
    facde->MethodA();
    facde->MethodB();

    return 0;
}