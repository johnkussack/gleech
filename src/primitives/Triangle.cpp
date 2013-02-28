#include <primitives/Triangle.h>

Triangle::Triangle(){

    // Define 3 vertices
    pushVertex(new ModelVertex(-1.0f, -1.0f, 0.0f,  0.0f,1.0f,0.0f,  0,0,0, 0.0f,0.0f));
    pushVertex(new ModelVertex(1.0f, -1.0f, 0.0f,   0.0f,1.0f,0.0f,  0,0,0, 0.0f, 1.0f));
    pushVertex(new ModelVertex(0.0f, 1.0f, 0.0f,  0.0f,1.0f,0.0f,    0,0,0, 0.5f, 1.0f));

}

Triangle::~Triangle(){

}
