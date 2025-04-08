#include <Game.h>

int main(int argc, char **argv){
    Game game = Game::GetInstance();
    std::cout << SDL_GetError() << std::endl;
    return 0;
}