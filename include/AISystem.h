#pragma once
#include <iostream>
#include "Entity.h"
#include "HealthComponent.h"
#include "PositionComponent.h"

class AISystem
{
private:
    std::vector<Entity> m_entities;
public:
    void addEntity(Entity e) { m_entities.push_back(e); }
    void update(){
        
    
        for(Entity& t_e : m_entities)
        {
            for(Component* t_c : t_e.m_getComponent()){

                HealthComponent* m_healthComp{dynamic_cast<HealthComponent*>(t_c)};
                if(m_healthComp)
                {
                   std::cout << "Component: " << m_healthComp->m_id << " Health: " << m_healthComp->getHealth() << std::endl;
                }
                
                PositionComponent* m_positionComp{dynamic_cast<PositionComponent*>(t_c)};
                if(m_positionComp)
                {
                    std::cout << "Component: " << m_positionComp->m_id << " Position X: " << m_positionComp->getPositionX() << " Position Y: " << m_positionComp->getPositionY()  << std::endl;
                }
            }
        }
        
        //std::cout << "AISystem Update" << std::endl;
        }
};
