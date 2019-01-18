//
// Created by zjp on 19-1-18.
//
/**
 * 抽象工厂模式
 */
#include <string>
#include <iostream>
using namespace std;

class User{
public:
    string name;
};
class Department{
public:
    string name;
};

//抽象操作类
class IUser{
public:
    virtual void insert(User* user) = 0;
};
class IDepartment{
public:
    virtual void insert(Department* department) = 0;
};

//具体操作类的两种实现方式
class SqlServerUser : public IUser{
public:
    void insert(User* user){
        cout << "在SQL Server中给User插入一条记录" << endl;
    }
};
class AccessUser : public IUser{
public:
    void insert(User* user){
        cout << "在Assess中给User插入一条记录" << endl;
    }
};

class SqlServerDepartment : public IDepartment{
public:
    void insert(Department* department){
        cout << "在SqlServer中给Department插入一条记录" << endl;
    }
};
class AssessDepartment : public IDepartment{
public:
    void insert(Department* department){
        cout << "在Assess中给Department插入一条记录" << endl;
    }
};

//抽象工厂接口
class IFactory{
public:
    virtual IUser* createIUser() = 0;
    virtual IDepartment* createIDepartment() = 0;
};

//具体工厂实现
class SqlServerFactory : public IFactory{
public:
    IUser* createIUser(){
        return new SqlServerUser();
    }
    IDepartment* createIDepartment(){
        return new SqlServerDepartment();
    }
};

class AccessFactory : public IFactory{
public:
    IUser* createIUser(){
        return new AccessUser();
    }
    IDepartment* createIDepartment(){
        return new AssessDepartment();
    }
};


int main(){
    User* user = new User();
    Department* department = new Department();

    //IFactory* factory = new SqlServerFactory();
    IFactory* factory = new AccessFactory();
    IUser* iu = factory->createIUser();
    iu->insert(user);

    IDepartment* id = factory->createIDepartment();
    id->insert(department);

    return 0;
}