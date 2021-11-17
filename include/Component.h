#pragma once
#include <iostream>
#include <SDL.h>

struct Component
{
    Component(std::string t_name) { m_id = t_name;}
    virtual std::string setName(std::string t_name) { return m_id = t_name; };
    std::string m_id;
};
