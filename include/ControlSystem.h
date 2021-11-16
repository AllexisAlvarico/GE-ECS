#pragma once
#include <iostream>
#include "Entity.h"

class ControlSystem
{
private:
    /* data */
public:
    ControlSystem();
    void update(){std::cout << "ControlSystem Update" << std::endl;}
};
