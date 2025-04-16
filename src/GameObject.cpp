#include <GameObject.h>
#include <Component.h>

GameObject::GameObject(){
    isDead = false;
}

GameObject::~GameObject(){
    int vsize = components.size();
    for(int i = vsize-1; i >= 0; i--){
        delete components[i];
    }
    components.clear();
}

void GameObject::Update(float dt){
    int vsize = components.size();
    for(int i = 0; i < vsize; i++){
        components[i]->Update(dt);
    }
}

void GameObject::Render(){
    int vsize = components.size();
    for(int i = 0; i < vsize; i++){
        components[i]->Render();
    }
}

bool GameObject::IsDead(){
    return isDead;
}

void GameObject::RequestDelete(){
    isDead = true;
}

void GameObject::AddComponent(Component* cpt){
    components.push_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt){
    components.erase(std::remove(components.begin(), components.end(), cpt), components.end());
}

Component * GameObject::GetComponent(std::string type){
    for(int i = 0; i < components.size(); i++){
        if(components[i]->Is(type)){
            return components[i];
        }
    }
    return nullptr;
}