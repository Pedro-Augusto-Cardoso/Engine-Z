// #include "SpriteRenderer.h"
#include <bits/stdc++.h>
// #include "Component.h"
#include "SpriteRenderer.h"
#include "GameObject.h"

class GameObject;

class Zombie : public virtual Component {
private:
    int hitpoints;
public:
    Zombie(GameObject& associated);
    void Damage(int damage);
    void Render();
    bool Is(std::string type);
    void Update(float dt);
};
