#pragma once
#include <iostream>
#include <SDL.h>

struct Component
{
    /* data */
    Component();
    Component(std::string t_name) { m_id = t_name;}
    virtual void setName(std::string t_name) = 0;
    std::string m_id;
};
