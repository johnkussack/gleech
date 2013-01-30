#ifndef CAMERACONTROLS_H
#define CAMERACONTROLS_H

#include <glincludes.h>

class CameraControls
{

    private:
        glm::vec3 position;

        // horizontal angle : toward -Z
        float horizontalAngle;
        // vertical angle : 0, look at the horizon
        float verticalAngle;
        // Initial Field of View
        float initialFoV;

        float speed;
        float mouseSpeed;

        double lastTime;

    public:

        glm::mat4 ProjectionMatrix;
        glm::mat4 ViewMatrix;

        CameraControls();
        virtual ~CameraControls();

        void processInputs();


};

#endif // CAMERACONTROLS_H
