#include <SDL_mixer.h>
#include <SDL_image.h>
#include <Game.h>

Game& Game::GetInstance(){
    if(instance == nullptr){
        instance=this;

        int init_SDL = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
        if(init_SDL){
            std::cout << "Erro inicializando SDL." << std::endl;
            std::cout << SDL_GetError << std::endl;
        }

        int init_IMG = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
        if(init_IMG){
            std::cout << "Erro inicializando imagem." << std::endl;
            std::cout << SDL_GetError << std::endl;
        }

        int OpenAudio_Mix = Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
        if(OpenAudio_Mix){
            std::cout << "Erro inicializando audio." << std::endl;
            std::cout << SDL_GetError << std::endl;
        }

        this->window = SDL_CreateWindow("Teste", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
        this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE | SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

    }
    return *instance;
}

Game::~Game(){
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

State& Game::GetState(){
    return *state;
}

SDL_Renderer* Game::GetRenderer(){
    return renderer;
}

void Game::Run(){
    state->Update(0);
    state->Render();
    SDL_RenderPresent(renderer);
    SDL_Delay(33);
}

