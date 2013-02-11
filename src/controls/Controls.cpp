
#include <controls/Controls.h>

Controls::Controls(Camera* _cam){
    cam = _cam;
}

Controls::~Controls(){

}


void GLFWCALL Controls::OnMousePos(int mouseX, int mouseY){

    //DO STUFF

}

void GLFWCALL Controls::OnMouseClick(int mouseX, int mouseY){

    //DO STUFF

}

void GLFWCALL Controls::OnKeyCallback(int key, int action){
    cam->KeyMovement();
}
