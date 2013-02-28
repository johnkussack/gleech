#ifndef SOUNDMANAGER__H
#define SOUNDMANAGER__H

#include <iostream>
#include <stdlib.h>

#include <SFML/Audio.hpp>

using namespace std;

class SoundManager{

    public:

        SoundManager();
        virtual ~SoundManager();

        void open(char*  path);
        void play();
        void stop();
        bool playing();

    private:

       sf::Music music;


};


#endif
