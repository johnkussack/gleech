#ifndef SOUNDMANAGER__H
#define SOUNDMANAGER__H

#include <iostream>
#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

using namespace std;

class SoundManager{

    
    private:

        vector<ALLEGRO_SAMPLE *> sounds;
        unsigned int soundIndex;
    
    public:
        
        SoundManager();
        virtual ~SoundManager();

        void open(char*  path);
        void play();
        void stop();
        bool playing();

    


};


#endif
