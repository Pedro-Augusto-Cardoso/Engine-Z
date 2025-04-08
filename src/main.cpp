#include <Game.h>

int main(int argc, char **argv){
    Game game = Game::GetInstance();
    // game =
    // game.Run();
    // game->Run();
    std::cout << SDL_GetError() << std::endl;
    // std::cout << << std::endl;
    while(true){
        game.Run();
    }
    return 0;
}