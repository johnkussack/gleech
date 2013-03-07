#include <controls/Controls.h>


Controls::Controls(Globals* _glb){
    globals = _glb;
    handleMouseLook = false;
}

Controls::~Controls(){

}

void Controls::onKeyDown(int keycode){
    switch(keycode){
        case ALLEGRO_KEY_UP:
            globals->camera->goForward();
            break;
        case ALLEGRO_KEY_DOWN:
            globals->camera->goBackward();
            break;
        case ALLEGRO_KEY_LEFT:
            globals->camera->goLeft();
            break;
        case ALLEGRO_KEY_RIGHT:
            globals->camera->goRight();
            break;
    }
}

void Controls::onKeyUp(int keycode){
    switch(keycode){
        case ALLEGRO_KEY_UP:
            globals->camera->stopForward();
            break;
        case ALLEGRO_KEY_DOWN:
            globals->camera->stopBackward();
            break;
        case ALLEGRO_KEY_LEFT:
            globals->camera->stopLeft();
            break;
        case ALLEGRO_KEY_RIGHT:
            globals->camera->stopRight();
            break;
    }
}

void Controls::onMouseClickDown(int button){
    if (button == 2){
        handleMouseLook=true;
    }
}

void Controls::onMouseClickUp(int button){
    if (button == 2){
        handleMouseLook=false;
        globals->camera->dragMouse(0,0);
    }
}

void Controls::onMouseMove(ALLEGRO_EVENT ev){
    if (handleMouseLook){
        globals->camera->dragMouse(ev.mouse.dx,ev.mouse.dy);
    }
}
