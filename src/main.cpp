#include <Game.h>

int main(int argc, char **argv){
    Game game = Game::GetInstance();
    while(true){
        game.Run();
    }
    return 0;
}