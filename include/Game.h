#include <Music.h>

#define TITLE "Title"
#define WIDTH 1200
#define HEIGHT 900

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
        static Game& GetInstance();
};