#pragma once
#include <iostream>
#include "Component.h"
#include "Vector2f.h"

class PositionComponent : public Component
{
private:
    Vector2f m_position;
public:
    PositionComponent(std::string t_name,float t_x, float t_y) : Component(t_name),
    m_position{t_x,t_y}{}

    float& getPositionX() {return m_position.m_x;}
    float& getPositionY() {return m_position.m_y;}
};
