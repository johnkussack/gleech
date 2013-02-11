#include <sound/soundManager.h>

SoundManager::SoundManager(){
    audio_rate = 22050;
    audio_format = AUDIO_S16; /* 16-bit stereo */
    audio_channels = 2;
    audio_buffers = 4096;

    SDL_Init(SDL_INIT_AUDIO);

    if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers)) {
        printf("Unable to open audio!\n");
        exit(1);
    }

    Mix_QuerySpec(&audio_rate, &audio_format, &audio_channels);

    music = NULL;
}

SoundManager::~SoundManager(){
    release();
    Mix_CloseAudio();
    SDL_Quit();
}

void SoundManager::open(char* path){
    if(music!=NULL) { release(); }

    printf("Loading %s\n",path);
    music = Mix_LoadMUS(path);

}

void SoundManager::play(){
    Mix_PlayMusic(music, 0);
}

void SoundManager::stop(){
    Mix_HaltMusic();
}

void SoundManager::release(){
    Mix_FreeMusic(music);
    music = NULL;
}

bool SoundManager::playing(){
    return Mix_PlayingMusic() == 0 ? false : true;
}
