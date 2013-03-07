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
        
    public:
        Gui(Globals* _glb);
        virtual ~Gui();
        
        void init();
        
        void draw();
    

};

#endif	/* GUI_H */

