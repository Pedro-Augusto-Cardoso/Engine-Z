#include<bits/stdc++.h>

class GameObject;

class Component{
    protected:
        GameObject& associated;
    public:
        Component(GameObject& associated);
        virtual void Update(float dt);
        virtual void Render();
        virtual bool Is(std::string type);
};
