#include <Game.h>

Sprite::Sprite(){
    texture = nullptr;
}

Sprite::Sprite(std::string file, int frameCountW = 1, int frameCountH = 1){
    texture = nullptr;
    this->frameCountH = frameCountH;
    this->frameCountW = frameCountW;
    Open(file);
}

Sprite::~Sprite(){
    SDL_DestroyTexture(texture);
}

void Sprite::Open(std::string file){
    if(IsOpen()){
        SDL_DestroyTexture(texture);
    }

    char tab2[1024];
    strcpy(tab2, file.c_str());
    this->texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), tab2);

    if(this->texture == nullptr){
        std::cout << "Erro carregando imagem." << std::endl;
        std::cout << SDL_GetError() << std::endl;
    }

    SDL_QueryTexture(this->texture, nullptr, nullptr, &width, &height);
}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::Render(int x, int y, int w, int h){
    // Game g = Game::GetInstance();
    SetClip(x, y, w, h);
    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &clipRect);
}

void Sprite::SetFrame(int frame){
    int x, y;
    int index = (int)(frameCountW/frame);
    int col = (int)remainder(frameCountW, frame);
    x = index*this->GetWidth();
    y = col*this->GetHeight();
    SetClip(x, y, this->GetWidth(), this->GetHeight());
}

void Sprite::SetFrameCount(int frameCountW, int frameCountH){
    this->frameCountH = frameCountH;
    this->frameCountW = frameCountW;
}

int Sprite::GetHeight(){
    return (int)(height/frameCountH);
}

int Sprite::GetWidth(){
    return (int)(width/frameCountW);
}

bool Sprite::IsOpen(){
    return texture != nullptr;
}