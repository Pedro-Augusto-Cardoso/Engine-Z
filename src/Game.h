#include <SDL.h>
#include <bits/stdc++.h>
#include <State.h>

class Game{
    private:
        std::string title;
        int width;
        int height;
        static Game* instance;
        SDL_Window* window;
        SDL_Renderer* renderer;
        State* state;
        Game(std::string title, int width, int height);
    public:
        ~Game();
        void Run();
        SDL_Renderer* GetRenderer();
        State& GetState();
        Game& GetInstance();
};