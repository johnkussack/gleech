#ifndef APP_H
#define	APP_H

#include <Globals.h>
#include <scene/Scene.h>
#include <scene/Gui.h>
#include <controls/Controls.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class App {
    
    private:
        
        Globals* globals;
        Scene* scene;
        Controls* controls;
        Gui* gui;
        
        float FPS; // Set FPS
        ALLEGRO_DISPLAY *display;
        ALLEGRO_EVENT_QUEUE *event_queue ;
        ALLEGRO_TIMER *timer;

        bool redraw;
        
        unsigned int MODE3D;
        
    public:
        App(Globals* _glb,Scene* _scn, Controls* _ctrl);
        virtual ~App();
    
        bool init();
    
        void run();
   

};

#endif	/* APP_H */

