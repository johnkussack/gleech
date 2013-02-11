#ifndef SOUNDMANAGER__H
#define SOUNDMANAGER__H

#include <iostream>
#include <stdlib.h>

#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

using namespace std;

class SoundManager{

    public:

        SoundManager();
        virtual ~SoundManager();

        void open(char*  path);
        void play();
        void stop();
        void release();
        bool playing();

    private:

        Mix_Music *music;
        SDL_Surface *screen;
        SDL_Event event;

        int audio_rate;
        Uint16 audio_format;
        int audio_channels;
        int audio_buffers;


};


#endif
