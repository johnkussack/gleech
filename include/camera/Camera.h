#ifndef CAMERA_H
#define CAMERA_H


#include <glincludes.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera{

    private:

        float horizontalAngle;
        float verticalAngle;

        float initialFoV;
        float speed;
        float mouseSpeed;
        double lastTime;

        bool dragging;
        double dragTime;
        float dragX;
        float dragY;



    public:

        glm::vec3 position;

        Camera();

        void KeyMovement();
        void GetVP(glm::mat4* V,glm::mat4*P);

        virtual ~Camera();



};

#endif // CAMERA_H
