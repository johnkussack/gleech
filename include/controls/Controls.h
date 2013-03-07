#ifndef CONTROLS_H
#define CONTROLS_H

#include <glincludes.h>
#include <Globals.h>
#include <allegro5/allegro.h>

class Controls{

    private:
        
        Globals* globals;
        
        bool handleMouseLook;

    public:
        Controls(Globals* _glb);
        virtual ~Controls();

        void onKeyDown(int keycode);
        void onKeyUp(int keycode);
        
        void onMouseClickDown(int button);
        void onMouseClickUp(int button);
        void onMouseMove(ALLEGRO_EVENT ev);
        

};

#endif
