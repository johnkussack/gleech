#include <primitives/Cube.h>

Cube::Cube(): Primitive(){


    pushVertex(new ModelVertex(0.5f, 0.5f, 0.5f,1.0f,0.0f,0.0f,0,0,0,1.0f,1.0f));
    pushVertex(new ModelVertex(-0.5f, 0.5f, 0.5f,1.0f,0.0f,0.0f,0,0,0,0.0f, 1.0f));
    pushVertex(new ModelVertex(-0.5f, -0.5f, 0.5f,1.0f,0.0f,0.0f,0,0,0,0.0f, 0.0f));
    pushVertex(new ModelVertex(0.5f, 0.5f, 0.5f,1.0f,0.0f,0.0f,0,0,0,1.0f, 1.0f));
    pushVertex(new ModelVertex(-0.5f, -0.5f, 0.5f,1.0f,0.0f,0.0f,0,0,0,0.0f, 0.0f));
    pushVertex(new ModelVertex(0.5f, -0.5f, 0.5f,1.0f,0.0f,0.0f,0,0,0,1.0f, 0.0f));
    pushVertex(new ModelVertex(0.5f, 0.5f, -0.5f,1.0f,0.0f,0.0f,0,0,0,1.0f,1.0f));
    pushVertex(new ModelVertex(0.5f, 0.5f, 0.5f,1.0f,0.0f,0.0f,0,0,0,0.0f, 1.0f));
    pushVertex(new ModelVertex(0.5f, -0.5f, 0.5f,1.0f,0.0f,0.0f,0,0,0,0.0f, 0.0f));
    pushVertex(new ModelVertex(0.5f, 0.5f, -0.5f,1.0f,0.0f,0.0f,0,0,0,1.0f, 1.0f));
    pushVertex(new ModelVertex(0.5f, -0.5f, 0.5f,1.0f,0.0f,0.0f,0,0,0,0.0f, 0.0f));
    pushVertex(new ModelVertex(0.5f, -0.5f, -0.5f,1.0f,0.0f,0.0f,0,0,0,1.0f, 0.0f));
    pushVertex(new ModelVertex(-0.5f, 0.5f, 0.5f,1.0f,0.0f,0.0f,0,0,0,1.0f,1.0f));
    pushVertex(new ModelVertex(-0.5f, 0.5f, -0.5f,1.0f,0.0f,0.0f,0,0,0,0.0f, 1.0f));
    pushVertex(new ModelVertex(-0.5f, -0.5f, -0.5f,1.0f,0.0f,0.0f,0,0,0,0.0f, 0.0f));
    pushVertex(new ModelVertex(-0.5f, 0.5f, 0.5f,1.0f,0.0f,0.0f,0,0,0,1.0f, 1.0f));
    pushVertex(new ModelVertex(-0.5f, -0.5f, -0.5f,1.0f,0.0f,0.0f,0,0,0,0.0f, 0.0f));
    pushVertex(new ModelVertex(-0.5f, -0.5f, 0.5f,1.0f,0.0f,0.0f,0,0,0,1.0f, 0.0f));
    pushVertex(new ModelVertex(-0.5f, 0.5f, -0.5f,1.0f,0.0f,0.0f,0,0,0,1.0f,1.0f));
    pushVertex(new ModelVertex(0.5f, 0.5f, -0.5f,1.0f,0.0f,0.0f,0,0,0,0.0f, 1.0f));
    pushVertex(new ModelVertex(0.5f, -0.5f, -0.5f,1.0f,0.0f,0.0f,0,0,0,0.0f, 0.0f));
    pushVertex(new ModelVertex(-0.5f, 0.5f, -0.5f,1.0f,0.0f,0.0f,0,0,0,1.0f, 1.0f));
    pushVertex(new ModelVertex(0.5f, -0.5f, -0.5f,1.0f,0.0f,0.0f,0,0,0,0.0f, 0.0f));
    pushVertex(new ModelVertex(-0.5f, -0.5f, -0.5f,1.0f,0.0f,0.0f,0,0,0,1.0f, 0.0f));
    pushVertex(new ModelVertex(0.5f, 0.5f, -0.5f,1.0f,0.0f,0.0f,0,0,0,1.0f,1.0f));
    pushVertex(new ModelVertex(-0.5f, 0.5f, -0.5f,1.0f,0.0f,0.0f,0,0,0,0.0f, 1.0f));
    pushVertex(new ModelVertex(-0.5f, 0.5f, 0.5f,1.0f,0.0f,0.0f,0,0,0,0.0f, 0.0f));
    pushVertex(new ModelVertex(0.5f, 0.5f, -0.5f,1.0f,0.0f,0.0f,0,0,0,1.0f, 1.0f));
    pushVertex(new ModelVertex(-0.5f, 0.5f, 0.5f,1.0f,0.0f,0.0f,0,0,0,0.0f, 0.0f));
    pushVertex(new ModelVertex(0.5f, 0.5f, 0.5f,1.0f,0.0f,0.0f,0,0,0,1.0f, 0.0f));
    pushVertex(new ModelVertex(0.5f, -0.5f, -0.5f,1.0f,0.0f,0.0f,0,0,0,1.0f,1.0f));
    pushVertex(new ModelVertex(-0.5f, -0.5f, -0.5f,1.0f,0.0f,0.0f,0,0,0,0.0f, 1.0f));
    pushVertex(new ModelVertex(-0.5f, -0.5f, 0.5f,1.0f,0.0f,0.0f,0,0,0,0.0f, 0.0f));
    pushVertex(new ModelVertex(0.5f, -0.5f, -0.5f,1.0f,0.0f,0.0f,0,0,0,1.0f, 1.0f));
    pushVertex(new ModelVertex(-0.5f, -0.5f, 0.5f,1.0f,0.0f,0.0f,0,0,0,0.0f, 0.0f));
    pushVertex(new ModelVertex(0.5f, -0.5f, 0.5f,1.0f,0.0f,0.0f,0,0,0,1.0f, 0.0f));

}

Cube::~Cube(){



}


