#ifndef GUI_H
#define	GUI_H

#include <Globals.h>
#include <sstream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>


class Gui {
    private:
        Globals* globals;
        bool enabled;
        stringstream buffer;
        ALLEGRO_FONT *font;
        ALLEGRO_FONT *fontTitle;
        
        bool chatting;
        bool trapKeys;
        
        char chatBuffer[255];
        int chatPointer;
        
    public:
        Gui(Globals* _glb);
        virtual ~Gui();
        
        void init();
        
        void draw();
        
        bool handleKeyEvent(ALLEGRO_EVENT* ev);
        bool trappingKeys();
    

};

#endif	/* GUI_H */

