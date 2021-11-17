#pragma once
#include <iostream>
#include "Entity.h"
#include "HealthComponent.h"

class HealthSystem
{
private:
    std::vector<Entity> m_entities;
public:
    void addEntity(Entity t_e){m_entities.push_back(t_e);}
    void update(){

        for(Entity& t_e : m_entities)
        {
            for(Component* t_c : t_e.m_getComponent()){

                HealthComponent* m_healthComp{dynamic_cast<HealthComponent*>(t_c)};
                if(m_healthComp)
                {
                    std::cout << "Component: " << m_healthComp->m_id << "Health: " << m_healthComp->getHealth() << std::endl;
                }
            }
        }
        //std::cout << "HealthSystem Update" << std::endl;
    }
};

   