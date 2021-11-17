#include "../include/Game.h"

Game::Game() :
    m_gameIsRunning{ false }
{
    SDL_Init(SDL_INIT_VIDEO);
    m_window = SDL_CreateWindow("ECS window", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN); // sets the window property

    //player Data
    m_list.push_back(new HealthComponent{"Player ", 100});
    m_list.push_back(new PositionComponent{"Player ", 20.0f,20.0f});
    m_list.push_back(new InputComponent("Player input"));

    //Villan Data
    m_list.push_back(new HealthComponent{"Villan ", 200});
    m_list.push_back(new PositionComponent{"Villan ", 50.0f,50.0f});

    //Cortana Data
    m_list.push_back(new HealthComponent{"Cortana ", 250});
    m_list.push_back(new PositionComponent{"Cortana ", 150.0f,200.0f});

    //Dinky Di Data
    m_list.push_back(new PositionComponent{"Dinky Di ", 300.0f,500.0f});


    //player's component
    m_player.addComponent(m_list.at(0));
    m_player.addComponent(m_list.at(1));
    m_player.addComponent(m_list.at(2));

    //Villan Data
    m_villan.addComponent(m_list.at(3));
    m_villan.addComponent(m_list.at(4));

    //Cortana Data
    m_cortana.addComponent(m_list.at(5));
    m_cortana.addComponent(m_list.at(6));

    //Dinky Di Data
    m_dinkyDi.addComponent(m_list.at(7));

    //Systems setup
    m_healthSys.addEntity(m_player);
    m_healthSys.addEntity(m_villan);
    m_healthSys.addEntity(m_cortana);

    m_ControlSys.addEntity(m_player);

    m_AISys.addEntity(m_villan);
    m_AISys.addEntity(m_cortana);
    m_AISys.addEntity(m_dinkyDi);

}
    
Game::~Game()
{
    cleanUp();
}
    
void Game::run()
{
    m_gameIsRunning = true;
    SDL_Event e;

    while (m_gameIsRunning)
    {
        processEvents(e);
        update();
        render();
    }
    cleanUp();
}

void Game::processEvents(SDL_Event e)
{
    while(SDL_PollEvent(&e) != 0) // checks for any activity
    {
        if(e.type == SDL_QUIT){ //if the user press the window X button
            m_gameIsRunning = false;
        }
        
        if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
        {
            m_gameIsRunning = false;
        }

    }
    //std::cout << "Processing Events" << std::endl;
}

void Game::update()
{
    m_healthSys.update();
    m_ControlSys.update();
    m_AISys.update();


    //std::cout << "Updating" << std::endl;
}

void Game::render()
{
    //std::cout << "Rendering" << std::endl;
}

void Game::cleanUp()
{
    SDL_DestroyWindow( m_window );
    //Quit SDL subsystems

    //Destroy window
    for (Component* c : m_list)
    {
        delete c;
    }
    m_list.clear();
    SDL_Quit();
}