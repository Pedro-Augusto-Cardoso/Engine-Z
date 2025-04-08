#include <Music.h>

Music::Music(){
    music=nullptr;
}

Music::Music(std::string file){
    Open(file);
}

void Music::Play(int times){
    Mix_PlayMusic(music, times);
}

void Music::Stop(int msToStop){
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(std::string file){
    char tab2[1024];
    strcpy(tab2, file.c_str());
    music = Mix_LoadMUS(tab2);

    if(music == nullptr){
        std::cout << "Musica nula." << std::endl;
        std::cout << SDL_GetError() << std::endl;
    }
}

bool Music::IsOpen(){
    return music != nullptr;
}

Music::~Music(){
    Stop();
    Mix_FreeMusic(music);
}