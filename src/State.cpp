#include <State.h>

State::State(){
    bg.Open(BACKGROUND_PATH);
    quitRequested = false;
}

void State::Update(float dt){
    if(SDL_QuitRequested()){
        this->quitRequested = true;
    }
}

void State::LoadAssets(){
    // bg.Open();
}

void State::Render(){
    bg.Render(0, 0);
}

bool State::QuitRequested(){
    return quitRequested;
}