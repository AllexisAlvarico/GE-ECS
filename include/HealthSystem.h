#pragma once
#include <iostream>
#include "Entity.h"

class HealthSystem
{
private:
    std::vector<Entity> m_entities;
public:
    void addEntity(Entity t_e){}
    void update(){std::cout << "HealthSystem Update" << std::endl;}
};

