#include <camera/Camera.h>

Camera::Camera()
{

    horizontalAngle = 3.14f;

    verticalAngle = 0.0f;

    position = glm::vec3( 0, 2, 5 );

    initialFoV = 45.0f;

    speed = 3.0f; // 3 units / second
    mouseSpeed = 0.5f;

    Camera::lastTime = -1; // INIT

}

Camera::~Camera()
{
    //dtor
}

void Camera::KeyMovement(){
    // Move forward

    /*if(lastTime==-1) { lastTime = glfwGetTime(); }


	// Compute time difference between current and last frame
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);

    	// Up vector
	glm::vec3 up(0,1,0);

	// Direction : Spherical coordinates to Cartesian coordinates conversion
	glm::vec3 direction(
		cos(verticalAngle) * sin(horizontalAngle),
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle)
	);

	// Right vector
	glm::vec3 right = glm::cross( direction, up );


	if (glfwGetKey( GLFW_KEY_UP ) == GLFW_PRESS){
		position += direction * deltaTime * speed;

	}
	// Move backward
	if (glfwGetKey( GLFW_KEY_DOWN ) == GLFW_PRESS){
		position -= direction * deltaTime * speed;

	}
	// Strafe right
	if (glfwGetKey( GLFW_KEY_RIGHT ) == GLFW_PRESS){
		position += right * deltaTime * speed;

	}
	// Strafe left
	if (glfwGetKey( GLFW_KEY_LEFT ) == GLFW_PRESS){
		position -= right * deltaTime * speed;
	}

	//lastTime = currentTime;*/

}



void Camera::GetVP(glm::mat4* V,glm::mat4*P){


	if(lastTime==-1) { lastTime = glfwGetTime(); }

	// Compute time difference between current and last frame
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);

	// Get mouse position
	int xpos, ypos;
	glfwGetMousePos(&xpos, &ypos);

	// Reset mouse position for next frame
	//glfwSetMousePos(1024/2, 738/2);

   if(glfwGetMouseButton(GLFW_MOUSE_BUTTON_2) == GLFW_PRESS){

        if (!dragging){
            dragging = true;
            dragTime = currentTime;
            dragX = xpos;
            dragY = ypos;
        }
        else{
            float dragDeltaTime = float(currentTime-dragTime);
            horizontalAngle += mouseSpeed/20 * dragDeltaTime * float(dragX - xpos );
            verticalAngle   += mouseSpeed/20 * dragDeltaTime * float(dragY - ypos );
            dragTime = currentTime;
        }

	// Compute new orientation

    }else{
        dragging = false;
    }

    	// Up vector
	glm::vec3 up(0,1,0);

	// Direction : Spherical coordinates to Cartesian coordinates conversion
	glm::vec3 direction(
		cos(verticalAngle) * sin(horizontalAngle),
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle)
	);
	glm::vec3 right = glm::cross( direction, up );


	if (glfwGetKey( GLFW_KEY_UP ) == GLFW_PRESS){
		position += direction * deltaTime * speed;

	}
	// Move backward
	if (glfwGetKey( GLFW_KEY_DOWN ) == GLFW_PRESS){
		position -= direction * deltaTime * speed;

	}
	// Strafe right
	if (glfwGetKey( GLFW_KEY_RIGHT ) == GLFW_PRESS){
		position += right * deltaTime * speed;

	}
	// Strafe left
	if (glfwGetKey( GLFW_KEY_LEFT ) == GLFW_PRESS){
		position -= right * deltaTime * speed;
	}


	float FoV = 45;

	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
    *P = glm::perspective(FoV, 4.0f / 3.0f, 0.1f, 100.0f);
	// Camera matrix



	*V       = glm::lookAt(
                position,           // Camera is here
                position+direction, // and looks here : at the same position, plus "direction"
                up                  // Head is up (set to 0,-1,0 to look upside-down)
           );


    lastTime = currentTime;
}
