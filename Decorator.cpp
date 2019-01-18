//
// Created by zjp on 19-1-15.
//
/**
 * 装饰模式
 */
#include <cstring>
#include <iostream>
using namespace std;

class Person{
private:
    string name;
public:
    Person(){};
    Person(string name){
        this->name = name;
    }

    virtual void show(){
        cout << "装扮的" << this->name;
    }
};

//Decotare
class Finery : public Person{
protected:
    Person* component;
public:
    void decorate(Person* component){
        this->component = component;
    }
    void show(){
        component->show();
    }
};

//Concrete Decorate
class TShirts : public Finery{
public:
    void show(){
        cout << "大T恤" << endl;
        Finery::show();
    }
};
class BigTrouser : public Finery{
public:
    void show(){
        cout << "垮裤" << endl;
        Finery::show();
    }
};
class Coat : public Finery{
public:
    void show(){
        cout << "大衣" << endl;
        Finery::show();
    }
};
class Shoes : public Finery{
public:
    void show(){
        cout << "鞋子" << endl;
        Finery::show();
    }
};

int main(){
    Person* p = new Person("Jack");

    TShirts* tShirts = new TShirts();
    BigTrouser* bigTrouser = new BigTrouser();
    Coat* coat = new Coat();
    Shoes* shoes = new Shoes();

    cout << "第一种装扮:" << endl;
    tShirts->decorate(p);
    bigTrouser->decorate(tShirts);
    bigTrouser->show();

    cout << "第二种装扮:" << endl;
    coat->decorate(p);
    shoes->decorate(coat);
    shoes->show();


    return 0;
}