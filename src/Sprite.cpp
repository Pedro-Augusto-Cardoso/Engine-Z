#include <Game.h>

Sprite::Sprite(){
    texture = nullptr;
}

Sprite::Sprite(std::string file){
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite(){
    SDL_DestroyTexture(texture);
}

void Sprite::Open(std::string file){
    if(texture != nullptr){
        SDL_DestroyTexture(texture);
    }

    char tab2[1024];
    strcpy(tab2, file.c_str());
    texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), tab2);

    if(texture == nullptr){
        std::cout << "Erro carregando imagem." << std::endl;
        std::cout << SDL_GetError() << std::endl;
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::Render(int x, int y){
    Game g = Game::GetInstance();
    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &clipRect);
}

int Sprite::GetHeight(){
    return height;
}

int Sprite::GetWidth(){
    return width;
}

bool Sprite::IsOpen(){
    return texture != nullptr;
}