#include <sound/soundManager.h>

SoundManager::SoundManager(){

}

SoundManager::~SoundManager(){

}

void SoundManager::open(char* path){
    if (!music.openFromFile(path)){
        cout<<"Couldn't load the sound file: "<<path<<endl;
    }else{
        cout<<"Loaded sound file: "<<path<<endl;
    }

}

void SoundManager::play(){
    music.play();
}

void SoundManager::stop(){
    music.stop();
}


bool SoundManager::playing(){
    return music.getStatus() == sf::Music::Playing;
}
