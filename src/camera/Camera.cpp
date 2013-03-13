#include <camera/Camera.h>

Camera::Camera(){

    //horizontalAngle = 3.14f;
    horizontalAngle = 0.0f;
    verticalAngle = 0.0f;

    position = glm::vec3( -160, 7, 50 );

    initialFoV = 45.0f;

    speed = 3.0f/20 ; // 3 units
    mouseSpeed = 0.5f /2500;

    width = 800;
    height = 600;
    
    radians = 2*3.141516;
    
}

Camera::~Camera(){
}

void Camera::setResolution(int _w, int _h){
    width = _w;
    height = _h;
}

void Camera::GetVP(glm::mat4* V,glm::mat4*P){

        
        horizontalAngle -= mouseDx/width * radians;
        verticalAngle -= mouseDy/height * radians;
        
        // Limit to 180 degrees
        if(verticalAngle<-radians/4) {verticalAngle = -radians/4;}
        if(verticalAngle>radians/4) {verticalAngle = radians/4;}
        
    	// Up vector
	glm::vec3 up(0,1,0);

	// Direction : Spherical coordinates to Cartesian coordinates conversion
	glm::vec3 direction(
		cos(verticalAngle) * sin(horizontalAngle),
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle)
	);
	glm::vec3 right = glm::cross( direction, up );

	position += direction * fordwardSpeed;
        position-= direction * backwardSpeed;;
        
        position += right * rightSpeed;
        position -= right * leftSpeed;

	float FoV = 45;

        *P = glm::perspective(FoV, 4.0f / 3.0f, 0.1f, 100.0f);

        *V  = glm::lookAt(
            position,           // Camera is here
            position+direction, // and looks here : at the same position, plus "direction"
            up                  // Head is up (set to 0,-1,0 to look upside-down)
        );


}


void Camera::goForward(){
    fordwardSpeed = speed;
}

void Camera::goBackward(){
    backwardSpeed = speed;
}

void Camera::goLeft(){
    leftSpeed = speed;
}

void Camera::goRight(){
    rightSpeed = speed;
}

void Camera::stopForward(){
    fordwardSpeed = 0;
}

void Camera::stopBackward(){
    backwardSpeed = 0;
}

void Camera::stopLeft(){
    leftSpeed = 0;
}

void Camera::stopRight(){
    rightSpeed = 0;
}

void Camera::dragMouse(int dx, int dy){
    mouseDx = dx;
    mouseDy = dy;
}

glm::vec3 Camera::getPosition(){
    return position;
}
