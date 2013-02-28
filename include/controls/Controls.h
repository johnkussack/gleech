#ifndef CONTROLS_H
#define CONTROLS_H

#include <glincludes.h>

class Controls{

    private:
        bool mouseRDown;
        bool mouseLDown;
        double deltaTime;

    public:
        Controls();
        virtual ~Controls();

        void GLFWCALL OnMousePos(int mouseX, int mouseY);
        void GLFWCALL OnMouseClick(int mouseX, int mouseY);
        void GLFWCALL OnKeyCallback(int key, int action);

    protected:

};

#endif
