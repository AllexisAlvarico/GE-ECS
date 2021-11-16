#pragma once
#include <iostream>
#include <cstdint>
#include <vector>
#include "Component.h"

class Entity
{
public:
    Entity();
    void addComponent() {};
    void removeComponent(){};
    std::vector<Component> m_getComponent(){return m_component;};
    
private:
    int m_id;
    std::vector<Component> m_component;
};
