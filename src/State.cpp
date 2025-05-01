#include <State.h>
// #include "SpriteRenderer.h"

State::State(){
    quitRequested = false;
    GameObject* z = new GameObject();
    z->box.x = 600;
    z->box.y = 450;
    z->AddComponent(new Zombie(*z));
    GameObject* bg = new GameObject();
    bg->box.x = 0;
    bg->box.y = 0;
    bg->AddComponent(new SpriteRenderer(*bg, BACKGROUND_PATH));
    AddObject(bg);
    AddObject(z); // Add zombie later so he appears on top
}

State::~State(){
    objectArray.clear();
}

void State::Update(float dt){
    for(int i = 0; i < objectArray.size(); i++){
        objectArray[i]->Update(dt);
    }
    for(int i = 0; i < objectArray.size(); i++){
        if(objectArray[i]->IsDead()){
            objectArray.erase(objectArray.begin()+i);
        }
    }
    if(SDL_QuitRequested()){
        this->quitRequested = true;
        std::cout << "Saindo." << std::endl; 
    }
}

void State::LoadAssets(){
    // bg.Open();
}

void State::Render(){
    // bg.Render(0, 0);
    for(int i = 0; i < objectArray.size(); i++){
        // std::cout << objectArray.size() << std::endl;
        objectArray[i]->Render();
    }
}

void State::AddObject(GameObject* go){
    objectArray.emplace_back(std::unique_ptr<GameObject>(go));
}

bool State::QuitRequested(){
    return quitRequested;
}

