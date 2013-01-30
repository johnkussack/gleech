#include <camera/CameraControls.h>

CameraControls::CameraControls(){
    position = glm::vec3( 0, 0, 5 );
    horizontalAngle = 3.14f;
    verticalAngle = 0.0f;
    initialFoV = 45.0f;
    speed = 3.0f;
    mouseSpeed = 0.05f;
    lastTime = glfwGetTime();
}

CameraControls::~CameraControls(){
    //dtor
}


void CameraControls::processInputs(){

    double currentTime = glfwGetTime();
    float deltaTime = float(currentTime - lastTime);

    float FoV = initialFoV - 5 * glfwGetMouseWheel();

    // Get mouse position
    int xpos, ypos;
    glfwGetMousePos(&xpos, &ypos);

    // Compute new orientation
    horizontalAngle += mouseSpeed * deltaTime * float(1024/2 - xpos );
    verticalAngle   += mouseSpeed * deltaTime * float( 768/2 - ypos );

    // Reset mouse position for next frame
    glfwSetMousePos(1024/2, 768/2);

    // Direction : Spherical coordinates to Cartesian coordinates conversion
    glm::vec3 direction(
        cos(verticalAngle) * sin(horizontalAngle),
        sin(verticalAngle),
        cos(verticalAngle) * cos(horizontalAngle)
    );

    // Right vector
    glm::vec3 right = glm::vec3(
        sin(horizontalAngle - 3.14f/2.0f),
        0,
        cos(horizontalAngle - 3.14f/2.0f)
    );


    // Up vector : perpendicular to both direction and right
    glm::vec3 up = glm::cross( right, direction );


    // Move forward
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




    // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
    //ProjectionMatrix = glm::perspective(FoV, 4.0f / 3.0f, 0.1f, 100.0f);

    ProjectionMatrix=glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 15.0f);

    // Camera matrix
    ViewMatrix       = glm::lookAt(
        position,           // Camera is here
        position+direction, // and looks here : at the same position, plus "direction"
        up                  // Head is up (set to 0,-1,0 to look upside-down)
    );

    lastTime = currentTime; // Save curr time as last for next iteration

}
