#include <primitives/Plane.h>

Plane::Plane(){

    // Define plane (6vertices)

    pushVertex(new ModelVertex(0.5f, 0.0f, -0.5f,  0.0f,0.0f,1.0f,  0,0,0, 16.0f,16.0f));
    pushVertex(new ModelVertex(-0.5f, 0.0f, -0.5f,  0.0f,0.0f,1.0f,  0,0,0, 0.0f, 16.0f));
    pushVertex(new ModelVertex(-0.5f, 0.0f, 0.5f,  0.0f,0.0f,1.0f,  0,0,0, 0.0f, 0.0f));

    pushVertex(new ModelVertex(0.5f, 0.0f, -0.5f,  0.0f,0.0f,1.0f,  0,0,0, 16.0f,16.0f));
    pushVertex(new ModelVertex(-0.5f, 0.0f, 0.5f,  0.0f,0.0f,1.0f,  0,0,0, 0.0f, 0.0f));
    pushVertex(new ModelVertex(0.5f, 0.0f, 0.5f,  0.0f,0.0f,1.0f,  0,0,0,  16.0f, 0.0f));

}

Plane::~Plane(){
    //dtor
}
