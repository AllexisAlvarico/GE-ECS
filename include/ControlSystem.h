#pragma once
#include <iostream>
#include "Entity.h"
#include "InputComponent.h"
#include "PositionComponent.h"

class ControlSystem
{
private:
    std::vector<Entity> m_entities;
    PositionComponent* m_objectPosition;
public:
    void addEntity(Entity t_e) {m_entities.push_back(t_e);}
    void update(){
        for(Entity& t_e : m_entities){
            for(Component* t_c : t_e.m_getComponent()){

                PositionComponent* m_positionComp{dynamic_cast<PositionComponent*>(t_c)};
                if(m_positionComp)
                {
                    m_objectPosition = m_positionComp;
                }
                
                InputComponent* m_inputComp{dynamic_cast<InputComponent*>(t_c)};

                if(m_inputComp && m_objectPosition)
                {
                    if(m_inputComp->inputKey(SDL_SCANCODE_RIGHT))
                    {
                        m_objectPosition->getPositionX() += 10.0f;
                    }
                    if(m_inputComp->inputKey(SDL_SCANCODE_LEFT))
                    {
                        m_objectPosition->getPositionX() -= 10.0f;
                    }
                    if(m_inputComp->inputKey(SDL_SCANCODE_UP))
                    {
                        m_objectPosition->getPositionY() -= 10.0f;
                    }
                    if(m_inputComp->inputKey(SDL_SCANCODE_DOWN))
                    {
                        m_objectPosition->getPositionY() += 10.0f;
                    }
                }


            }
        }
        //std::cout << "HealthSystem Update" << std::endl;
    }
};
