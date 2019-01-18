cmake_minimum_required(VERSION 3.12)
project(DesignPattern)

set(CMAKE_CXX_STANDARD 14)

#add_executable(DesignPattern main.cpp)

add_executable(SimpleFactory SimpleFactory.cpp)
add_executable(Strategy Strategy.cpp)
add_executable(Strategy_Cash Strategy_Cash.cpp)
add_executable(Decorator Decorator.cpp)
add_executable(Decotator_Coffee Decotator_Coffee.cpp)
add_executable(Proxy Proxy.cpp)
add_executable(Factory Factory.cpp)
add_executable(Templet Templet.cpp)
add_executable(Facade Facade.cpp)
add_executable(Builder Builder.cpp)
add_executable(Observer Observer.cpp)
add_executable(AbstractFactory AbstractFactory.cpp)