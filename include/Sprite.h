#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <bits/stdc++.h>

#define BACKGROUND_PATH "./res/Recursos/img/Background.png"
#define TITLE "Title"
#define WIDTH 1200
#define HEIGHT 900

class Sprite{
    private:
        SDL_Texture* texture;
        int width;
        int height;
        SDL_Rect clipRect;
        int frameCountH;
        int frameCountW;
    public:
        Sprite();
        // Sprite(std::string file);
        Sprite(std::string file, int frameCountW = 1, int frameCountH = 1);
        ~Sprite();
        void Open(std::string file);
        void SetClip(int x, int y, int w, int h);
        void Render(int x, int y, int w, int h);
        void SetFrame(int frame);
        void SetFrameCount(int frameCountW, int frameCountH);
        int GetWidth();
        int GetHeight();
        bool IsOpen();
};