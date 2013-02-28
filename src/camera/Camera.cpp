#include <camera/Camera.h>

Camera::Camera()
{

    horizontalAngle = 3.14f;

    verticalAngle = 0.0f;

    position = glm::vec3( 0, 2, 5 );

    initialFoV = 45.0f;

    speed = 3.0f /2000; // 3 units / second
    mouseSpeed = 0.5f /2000;



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


	//if(lastTime==-1) { lastTime =(clock.restart()); }

	// Compute time difference between current and last frame

	float deltaTime = (clock.restart()).asMilliseconds();

	// Get mouse position
	int xpos, ypos;
	sf::Vector2i globalPosition = sf::Mouse::getPosition();

    xpos = globalPosition.x;
    ypos = globalPosition.y;
    ///TODO: global to local

    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
        if (!dragging){
            dragging = true;
            dragX = xpos;
            dragY = ypos;
        }
        else{
            float dragDeltaTime = (clock.restart()).asMilliseconds();
            horizontalAngle += mouseSpeed * dragDeltaTime * float(dragX - xpos );
            verticalAngle   += mouseSpeed * dragDeltaTime * float(dragY - ypos );
        }
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
	    if(sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)){
	        float sp = speed * 2;
	        position += (direction * deltaTime * sp);
	    }else{
            position += direction * deltaTime * speed;
	    }
    }

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		position -= direction * deltaTime * speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		position += right * deltaTime * speed;

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		position -= right * deltaTime * speed;
	}


	float FoV = 45;

    *P = glm::perspective(FoV, 4.0f / 3.0f, 0.1f, 100.0f);

	*V       = glm::lookAt(
                position,           // Camera is here
                position+direction, // and looks here : at the same position, plus "direction"
                up                  // Head is up (set to 0,-1,0 to look upside-down)
           );


}
