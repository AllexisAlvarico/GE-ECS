#pragma once
#include <iostream>
#include <cstdint>
#include <vector>
#include "Component.h"

class Entity
{
public:
    Entity();
    void addComponent(Component* t_c) { m_component.push_back(t_c);};
    void removeComponent(Component* t_c){
        m_component.erase(std::remove_if(m_component.begin(), m_component.end(),
        [&](const auto& component){
            return component->name() == c->name();
        }),m_component.end());
    }
    std::vector<Component*>& m_getComponent(){return m_component;};
    
private:
    int m_id;
    std::vector<Component*> m_component;
};
