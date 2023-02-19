#pragma once
#include"gameobject.h"
//these functions help us dynamically create game objects

class factory {
public:
    virtual gameObject* create(int x, int y, int d) = 0;
};

class CarFactory :public factory {
public:
    car* create(int x, int y, int d) { return new car(x, y, d); }
};
