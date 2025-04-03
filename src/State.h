#include <bits/stdc++.h>

class State{
    private:
        Sprite bg;
        // Music music;
        bool quitRequested;
    public:
        State();
        bool QuitRequested();
        void Update(float dt);
        void Render();

};