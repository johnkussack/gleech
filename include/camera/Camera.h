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
        
        // Speeds on keyboard
        float fordwardSpeed;
        float backwardSpeed;
        
        float rightSpeed;
        float leftSpeed;

        // Mouse Diffs
        float mouseDx;
        float mouseDy;
        
        // Resolutions
        int width;
        int height;
        
        float radians;

    public:

        glm::vec3 position;

        Camera();

        void GetVP(glm::mat4* V,glm::mat4*P);

        virtual ~Camera();
        
        void setResolution(int _w,int _h);
        
        void goForward();
        void goBackward();
        void goLeft();
        void goRight();
        
        void stopForward();
        void stopBackward();
        void stopLeft();
        void stopRight();

        void dragMouse(int dx, int dy);
        
        glm::vec3 getPosition();
        

};

#endif // CAMERA_H
