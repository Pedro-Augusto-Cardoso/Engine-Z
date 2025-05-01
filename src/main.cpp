#include <Game.h>

int main(int argc, char **argv){
    Game game = Game::GetInstance();
    while(!game.GetState().QuitRequested()){
        game.Run();
    }
    return 0;
}