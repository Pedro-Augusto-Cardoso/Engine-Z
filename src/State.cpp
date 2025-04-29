#include <State.h>
// #include <GameObject.h>

State::State(){
    bg.Open(BACKGROUND_PATH);
    quitRequested = false;
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
    for(int i = 0; i < objectArray.size(); i++)
        objectArray[i]->Render();
}

void State::AddObject(GameObject* go){
    objectArray.emplace_back(go);
}

bool State::QuitRequested(){
    return quitRequested;
}

