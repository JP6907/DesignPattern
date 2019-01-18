//
// Created by zjp on 19-1-17.
//
/**
 * 建造者模式
 */
#include <vector>
#include <string>
#include <iostream>
using namespace std;

//产品类，由多个部件组成
class Product{
private:
    vector<string> parts;
public:
    void add(string part){
        parts.push_back(part);
    }
    void show(){
        cout << "产品创建: ";
        for(string part:parts){
            cout << part << " ";
        }
        cout << endl;
    }
};

//抽象建造者类
class Builder{
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual Product* getProduct() = 0;
};

//具体建造者
class ConcreteBuilder1 : public Builder{
private:
    Product* product;
public:
    ConcreteBuilder1(){
        product = new Product();
    }
    void buildPartA(){
        product->add("部件1A");
    }
    void buildPartB(){
        product->add("部件1B");
    }
    Product* getProduct(){
        return product;
    }
};
class ConcreteBuilder2 : public Builder{
private:
    Product* product;
public:
    ConcreteBuilder2(){
        product = new Product();
    }
    void buildPartA(){
        product->add("部件2A");
    }
    void buildPartB(){
        product->add("部件2B");
    }
    Product* getProduct(){
        return product;
    }
};

//指挥者类
class Director{
public:
    void construct(Builder* builder){
        builder->buildPartA();
        builder->buildPartB();
    }
};

int main(){
    Director* director = new Director();
    Builder* b1 = new ConcreteBuilder1();
    Builder* b2 = new ConcreteBuilder2();

    director->construct(b1);
    Product* p1 = b1->getProduct();
    p1->show();

    director->construct(b2);
    Product* p2 = b2->getProduct();
    p2->show();

    return 0;
}