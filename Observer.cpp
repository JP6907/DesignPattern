//
// Created by zjp on 19-1-17.
//
/**
 * 观察者模式
 */
#include <list>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//抽象观察者
class Observer{
public:
    virtual void update() = 0;
};

//抽象通知者
class Subject{
private:
    list<Observer*> observers;
public:
    void attach(Observer* observer){
        observers.push_back(observer);
    }
    void detach(Observer* observer){
        observers.remove(observer);
    }
    void notify(){
        for(Observer* o:observers)
            o->update();
    }
};

//具体通知者
class ConcreteSubject : public Subject{
private:
    string subjectState;
public:
    string getSubjectState(){
        return this->subjectState;
    }
    void setSubjectState(string subjectState){
        this->subjectState = subjectState;
    }
};

//具体观察者
class ConcreteObserver : public Observer{
private:
    string name;
    string observerState;
    ConcreteSubject* concreteSubject;
public:
    ConcreteObserver(ConcreteSubject* concreteSubject,string name){
        this->name = name;
        this->concreteSubject = concreteSubject;
    }
    void update(){
        this->observerState = concreteSubject->getSubjectState();
        cout << "观察者" << this->name << "的新状态是" << this->observerState << endl;
    }
};

int main(){
    ConcreteSubject* s = new ConcreteSubject();
    s->attach(new ConcreteObserver(s,"X"));
    s->attach(new ConcreteObserver(s,"Y"));
    s->attach(new ConcreteObserver(s,"Z"));

    s->setSubjectState("ABC");
    s->notify();

    return 0;
}

