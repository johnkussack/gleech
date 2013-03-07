#include <App.h>

#define ERRMSG(WINTIT,CONTTIT,MESSAGE) al_show_native_message_box(al_get_current_display(), WINTIT, CONTTIT, MESSAGE,  NULL, ALLEGRO_MESSAGEBOX_ERROR)



App::App(Globals* _glb,Scene* _scn, Controls* _ctrl) {
    globals = _glb;
    scene = _scn;
    controls = _ctrl;
    MODE3D = GL_FILL;
    gui = new Gui(_glb);
}

App::~App() {
    if(timer!=NULL)
        al_destroy_timer(timer); 
    if(display!=NULL)
        al_destroy_display(display);
    if(event_queue!=NULL)
        al_destroy_event_queue(event_queue);
}

bool App::init(){

    if(!al_init()) {       
        ERRMSG("Error during Init!", "Ooops", "The Allegro library could not be init!");
    }
    
    al_set_new_display_flags(ALLEGRO_OPENGL | ALLEGRO_OPENGL_3_0);
    display = al_create_display(globals->APPWIDTH, globals->APPHEIGHT);
    
    if(!display) {
        ERRMSG("Error during Init!", "Ooops","Could not init an Allegro Display!");
      return false;
    }
    
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon();// initialize the ttf (True Type Font) addon
    
    // GLEW initialization
    glewExperimental=true; // Needed in core profile
    if (glewInit() != GLEW_OK) {
        ERRMSG("Error during Init!", "Ooops", "The GLEW library could not be init (old hardware?)!");
        return false;
    }
    
    FPS = 60;
    timer = al_create_timer(1.0 / FPS);
    if(!timer){
        ERRMSG("Error during Init!", "Ooops", "Could not init timers!");
        return false;
    }
    
    if(!al_install_keyboard()) {
        ERRMSG("Error during Init!", "Ooops", "Could not init the keyboard handler!");
        return false;
    }
    
    if(!al_install_mouse()) {
         ERRMSG("Error during Init!", "Ooops", "Could not init the mouse handler!");
        return false;
    }
    
    event_queue = al_create_event_queue();
    if(!event_queue) {
        ERRMSG("Error during Init!", "Ooops", "Could not init the event queue!");
        return false;
    }
    
    gui->init();
 
    return true;
}

void App::run(){
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());

    al_clear_to_color(al_map_rgb(50,10,70));

    al_start_timer(timer);
    ALLEGRO_EVENT ev;
 
    while(1){
   
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_TIMER) {
           redraw = true;
           
        }
        else{ 
            if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                break;
            }
            else{
                //Key Events
                if(ev.type == ALLEGRO_EVENT_KEY_DOWN){ 
                    controls->onKeyDown(ev.keyboard.keycode);
                }
                
                if(ev.type == ALLEGRO_EVENT_KEY_UP){ 
                    
                    if(ev.keyboard.keycode == ALLEGRO_KEY_W){
                        MODE3D = GL_LINE;
                    }
                    
                    if(ev.keyboard.keycode == ALLEGRO_KEY_S){
                        MODE3D = GL_FILL;
                    }
                    
                    if(ev.keyboard.keycode == ALLEGRO_KEY_F12){
                        //GET CODE FOR SCREENSHOT
                    }
                    else{
                        controls->onKeyUp(ev.keyboard.keycode);
                    }
                }
                
                // Mouse Events
                if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
                    controls->onMouseClickDown(ev.mouse.button);
                }
                
                if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                    controls->onMouseClickUp(ev.mouse.button);
                }
                
                if(ev.type == ALLEGRO_EVENT_MOUSE_AXES || ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {
                    controls->onMouseMove(ev);
                }
            }
        }

        if(redraw && al_is_event_queue_empty(event_queue)) {
           redraw = false;
           
           // Draw 3D
           glEnable(GL_DEPTH_TEST);
           glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
           glLoadIdentity();

           glPolygonMode( GL_FRONT_AND_BACK, MODE3D);
           
           scene->render();
           glDisable(GL_DEPTH_TEST);
           
           glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
           // Draw 2D GUI
           gui->draw();

           al_flip_display();
        }
    }

   al_destroy_timer(timer); timer=NULL;
   al_destroy_display(display); display = NULL;
   al_destroy_event_queue(event_queue); event_queue = NULL;
}




