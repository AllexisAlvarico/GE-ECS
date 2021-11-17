#include <iostream>
#include "Component.h"

class HealthComponent : public Component
{
public:
    HealthComponent(std::string t_name, int t_health) : Component(t_name),m_health(t_health){}
    int getHealth() {return m_health;}
    void setHealth(int t_health){this->m_health = t_health;}
private:
    int m_health;
};