
#include <scene/Gui.h>

Gui::Gui(Globals* glb) {
    globals = glb;
    enabled = true;
    
   
    
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
     
    al_draw_text(fontTitle, al_map_rgb(125,255,125), 170, 10,ALLEGRO_ALIGN_CENTRE, globals->GUITITLE.c_str());
    al_draw_text(font, al_map_rgb(125,255,125), 60, (globals->APPHEIGHT-30),ALLEGRO_ALIGN_CENTRE, "Ready...");

    glm::vec3 pos = globals->camera->getPosition();
    
    // Draw Coordinates on the GUI
    buffer.str("");
    buffer<<"X: "<<pos.x<< " Y: " << pos.y <<" Z: "<<pos.z;
    
    al_draw_text(font, al_map_rgb(125,255,125), globals->APPWIDTH-200, (globals->APPHEIGHT-30),ALLEGRO_ALIGN_CENTRE, buffer.str().c_str());
           
    
}