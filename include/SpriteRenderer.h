// #include <Component.h>
#include <State.h>
// #include <Game.h>

class SpriteRenderer : public Component{
    private:
        Sprite sprite;
    public:
        SpriteRenderer(GameObject& associated) : Component(associated) {};
        SpriteRenderer(GameObject& associated, std::string file, int frameCountW = 1, int frameCountH = 1);
        void Open(std::string file);
        void SetFrameCount(int frameCountW, int frameCountH);
        void Update(float dt);
        void Render();
        bool Is(std::string type);
        void SetFrame(int frame);
};