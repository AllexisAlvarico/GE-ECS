#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include "HealthSystem.h"
#include "ControlSystem.h"
#include "AISystem.h"
#include "Entity.h"

class Game
{
public:

    Game();
    ~Game();
    void run();

private:

    void processEvents(SDL_Event e);
    void update();
    void render();
    void cleanUp();

    bool m_gameIsRunning;
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;

    HealthSystem m_healthSys;
    ControlSystem m_ControlSys;
    AISystem m_AISys;

    Entity m_player;
    Entity m_villan;
    Entity m_cortana;
    Entity m_dinkyDi;

    std::vector<Component*> m_list;
    
};