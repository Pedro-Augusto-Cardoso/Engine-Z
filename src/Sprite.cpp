#include <Game.h>

Sprite::Sprite(){
    texture = nullptr;
}

Sprite::Sprite(std::string file, int frameCountW, int frameCountH){
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
        std::cout << "Deleted texture." << std::endl;
    }

    char tab2[1024];
    strcpy(tab2, file.c_str());
    texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), tab2);
    // std::cout << Game::GetInstance().GetRenderer() << std::endl;

    if(this->texture == nullptr){
        std::cout << "Erro carregando imagem." << std::endl;
        // std::cout << SDL_GetError() << std::endl;
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::Render(int x, int y, int w, int h){
    if (this->texture == nullptr) {
        std::cout << "Render called on sprite with no loaded texture!" << std::endl;
        return;
    }
    SDL_Rect* where = new SDL_Rect();
    where->x = x;
    where->y = y;
    where->w = this->GetWidth();
    where->h = this->GetHeight();
    clipRect.w = this->GetWidth();
    clipRect.h = this->GetHeight();
    int result = SDL_RenderCopy(Game::GetInstance().GetRenderer(), this->texture, &clipRect, where);
    // std::cout << Game::GetInstance().GetRenderer() << std::endl;
    if(result < 0){
        std::cout << SDL_GetError() << std::endl;
    }
    delete where;
    // std::cout << clipRect.x << " " << clipRect.y << " " << clipRect.w << " " << clipRect.h << std::endl;
    // std::cout << x << " " << y << " " << w << " " << h << std::endl;
}

void Sprite::SetFrame(int frame){
    // frame--;
    int x, y;
    int index = (frame)%frameCountW;
    int col = (int)std::ceil((frame-1)/(frameCountW));
    if(col < 0){
        col = 0;
    }
    x = (index)*this->GetWidth();
    y = (col)*this->GetHeight();
    SetClip(x, y, this->GetWidth(), this->GetHeight());
    // std::cout << "at " << x << " " << y << std::endl;
    // std::cout << "frame with index " << index << " and column " << col << std::endl;
    // std::cout << GetHeight() << std::endl;
    // std::cout << GetWidth() << std::endl;
}

void Sprite::SetFrameCount(int frameCountW, int frameCountH){
    this->frameCountH = frameCountH;
    this->frameCountW = frameCountW;
}

int Sprite::GetHeight(){
    // std::cout << height << std::endl;
    return (int)(height/frameCountH);
}

int Sprite::GetWidth(){
    // std::cout << width << std::endl;
    return (int)(width/frameCountW);
}

bool Sprite::IsOpen(){
    return texture != nullptr;
}