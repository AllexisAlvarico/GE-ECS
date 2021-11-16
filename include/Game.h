#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <string>

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
};