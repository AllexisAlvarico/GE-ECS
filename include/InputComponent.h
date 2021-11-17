#pragma once
#include <iostream>
#include "Component.h"


class InputComponent : public Component
{
private:
    const Uint8* m_keys{SDL_GetKeyboardState(nullptr)};
public:
    InputComponent(std::string t_name) : Component(t_name){};

    const Uint8 inputKey(SDL_Scancode t_code) {return m_keys[t_code];}
};