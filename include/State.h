#include <bits/stdc++.h>
#include <Music.h>

class GameObject;

class State{
    private:
        Sprite bg;
        Music music;
        bool quitRequested;
        std::vector<std::unique_ptr<GameObject>> objectArray;
    public:
        State();
        ~State();
        void AddObject(GameObject * go);
        bool QuitRequested();
        void LoadAssets();
        void Update(float dt);
        void Render();

};