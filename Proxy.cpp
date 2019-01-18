//
// Created by zjp on 19-1-16.
//
/**
 * 代理模式
 */

#include <iostream>
using namespace std;

//代理接口
class ISubject{
public:
    virtual void request() = 0;
};

//真实实体
class RealSubject : public ISubject{
public:
    void request(){
        cout << "The real request from real subject!" << endl;
    }
};

//代理类
class Proxy: public ISubject{
private:
    RealSubject* realSubject;
public:
    void request(){
        if(realSubject == nullptr)
            realSubject = new RealSubject();
        realSubject->request();
    }
};

int main(){
    Proxy* proxy = new Proxy();
    proxy->request();
    return 0;
}




