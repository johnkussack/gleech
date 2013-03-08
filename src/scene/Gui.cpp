
#include <scene/Gui.h>

Gui::Gui(Globals* glb) {
    globals = glb;
    enabled = true;
    
    chatting = false;
    trapKeys = false;
    
    chatPointer = 0;
    
}

Gui::~Gui() {
    
    
}

void Gui::init(){
    font = al_load_ttf_font("/root/workspace/gleechA/resources/MonospaceTypewriter.ttf",20,0 );
    fontTitle = al_load_ttf_font("/root/workspace/gleechA/resources/Control Freak.ttf",60,0 );

    if (!font || !fontTitle){
      cout<<"[GUI] WARNING!!! System font not operative"<<endl;
      enabled = false;
    }
}

void Gui::draw(){
    if(!enabled){
        return;
    }
     
    al_draw_text(fontTitle, al_map_rgb(125,255,125), 0, 10,ALLEGRO_ALIGN_LEFT, globals->GUITITLE.c_str());
    al_draw_text(font, al_map_rgb(125,255,125),0, (globals->APPHEIGHT-30),ALLEGRO_ALIGN_LEFT, (const char*)chatBuffer);

    glm::vec3 pos = globals->camera->getPosition();
    
    // Draw Coordinates on the GUI
    buffer.str("");
    buffer<<"X: "<<pos.x<< " Y: " << pos.y <<" Z: "<<pos.z;
    
    al_draw_text(font, al_map_rgb(125,255,125), globals->APPWIDTH-200, (globals->APPHEIGHT-30),ALLEGRO_ALIGN_CENTRE, buffer.str().c_str());
        
}

bool Gui::handleKeyEvent(ALLEGRO_EVENT* ev){
    
    switch(ev->keyboard.keycode){
        case ALLEGRO_KEY_ESCAPE:
            chatting = false;
            trapKeys = false;
            chatPointer = 0;
            chatBuffer[0] = 0;
            break;
            
        case ALLEGRO_KEY_ENTER:
            chatting = !chatting;
            if (chatting == false){
                chatPointer = 0;
                chatBuffer[0] = 0;
                trapKeys = false;
            }else{
                trapKeys = true;
            }
            return true;
            
            break;
        
        default:
            if(chatting){
                //cout<<"Got Keypress GUI: "<<ev->keyboard.unichar<<endl;
                if(ev->keyboard.unichar>0){
                    
                    if(ev->keyboard.unichar==8){
                        chatPointer--;
                        chatBuffer[chatPointer] = 0;
                        if(chatPointer<0){
                            chatPointer = 0;
                        }
                    }else{
                        if(chatPointer<254){
                            chatBuffer[chatPointer] = ev->keyboard.unichar;
                            chatPointer++;
                            chatBuffer[chatPointer] = 0;
                        }
                    }
                    
                }
                return true;
            }
            else{
                return false;
            }
        break;
        
    }
    
    return false;
}

bool Gui::trappingKeys(){
    return trapKeys;
}