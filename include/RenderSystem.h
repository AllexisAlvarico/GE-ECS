#pragma once
#include <iostream>
#include "Entity.h"

class RenderSystem
{
private:
    /* data */
public:
    RenderSystem(/* args */);
    void update(){std::cout << "RenderSystem Update" << std::endl;}
};