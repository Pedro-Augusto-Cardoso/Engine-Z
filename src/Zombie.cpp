// This guy is merely a placeholder for the time being. Always useful for testing animations. 
#include "Zombie.h"


// #include "GameObject.h"

Zombie::Zombie(GameObject& associated) : Component(associated){
    // std::cout << "Construtor do zumbi começou" << std::endl;
    SpriteRenderer* renderer = new SpriteRenderer(associated, "./res/Recursos/img/Enemy.png", 3, 2);
    // std::cout << "stop1" << std::endl;
    renderer->SetFrame(1);
    // std::cout << "stop2" << std::endl;
    associated.AddComponent(renderer);
    // std::cout << "stop3" << std::endl;
    hitpoints = 100;
    // std::cout << "Construtor do zumbi foi" << std::endl;
}

void Zombie::Damage(int damage){
    this->hitpoints -= damage;
    std::cout << "Damaged. New hp: " << hitpoints << std::endl;
    if(hitpoints <= 0){
        dynamic_cast<SpriteRenderer*>(associated.GetComponent("SpriteRenderer"))->SetFrame(5);
        std::cout << "ded" << std::endl;
    }
}

void Zombie::Update(float dt){
    Damage(1);
}

void Zombie::Render(){}

bool Zombie::Is(std::string type){
    return type == "Zombie";
}