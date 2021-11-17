#pragma once
#include <iostream>
#include "Entity.h"

class AISystem
{
private:
    /* data */
public:
    AISystem(/* args */);
    void update(){std::cout << "AISystem Update" << std::endl;}
};
