#include <primitives/Cube.h>

Cube::Cube(): Primitive(){

    // Define cube vertices (36* 3float)

    pushVector3(vertices, 0.5f, 0.5f, 0.5f);
    pushVector3(vertices, -0.5f, 0.5f, 0.5f);
    pushVector3(vertices, -0.5f, -0.5f, 0.5f);
    pushVector3(vertices, 0.5f, 0.5f, 0.5f);
    pushVector3(vertices, -0.5f, -0.5f, 0.5f);
    pushVector3(vertices, 0.5f, -0.5f, 0.5f);
    pushVector3(vertices, 0.5f, 0.5f, -0.5f);
    pushVector3(vertices, 0.5f, 0.5f, 0.5f);
    pushVector3(vertices, 0.5f, -0.5f, 0.5f);
    pushVector3(vertices, 0.5f, 0.5f, -0.5f);
    pushVector3(vertices, 0.5f, -0.5f, 0.5f);
    pushVector3(vertices, 0.5f, -0.5f, -0.5f);
    pushVector3(vertices, -0.5f, 0.5f, 0.5f);
    pushVector3(vertices, -0.5f, 0.5f, -0.5f);
    pushVector3(vertices, -0.5f, -0.5f, -0.5f);
    pushVector3(vertices, -0.5f, 0.5f, 0.5f);
    pushVector3(vertices, -0.5f, -0.5f, -0.5f);
    pushVector3(vertices, -0.5f, -0.5f, 0.5f);
    pushVector3(vertices, -0.5f, 0.5f, -0.5f);
    pushVector3(vertices, 0.5f, 0.5f, -0.5f);
    pushVector3(vertices, 0.5f, -0.5f, -0.5f);
    pushVector3(vertices, -0.5f, 0.5f, -0.5f);
    pushVector3(vertices, 0.5f, -0.5f, -0.5f);
    pushVector3(vertices, -0.5f, -0.5f, -0.5f);
    pushVector3(vertices, 0.5f, 0.5f, -0.5f);
    pushVector3(vertices, -0.5f, 0.5f, -0.5f);
    pushVector3(vertices, -0.5f, 0.5f, 0.5f);
    pushVector3(vertices, 0.5f, 0.5f, -0.5f);
    pushVector3(vertices, -0.5f, 0.5f, 0.5f);
    pushVector3(vertices, 0.5f, 0.5f, 0.5f);
    pushVector3(vertices, 0.5f, -0.5f, -0.5f);
    pushVector3(vertices, -0.5f, -0.5f, -0.5f);
    pushVector3(vertices, -0.5f, -0.5f, 0.5f);
    pushVector3(vertices, 0.5f, -0.5f, -0.5f);
    pushVector3(vertices, -0.5f, -0.5f, 0.5f);
    pushVector3(vertices, 0.5f, -0.5f, 0.5f);

    // All colors are red, so doing it that way in a loop

    for(int i = 0;i<vertices->size()/3;i++){
        pushVector3(colors,1.0f,0.0f,0.0f);
    }

    // All 6 faces have the same UV map (repeating the texture, so loop)
    // Bottom face will be reversed if looking from below!!!

    for (int i = 0;i<6; i++){
        pushVector2(texturesUv, 1.0f,1.0f);
        pushVector2(texturesUv, 0.0f, 1.0f);
        pushVector2(texturesUv, 0.0f, 0.0f);
        pushVector2(texturesUv, 1.0f, 1.0f);
        pushVector2(texturesUv, 0.0f, 0.0f);
        pushVector2(texturesUv, 1.0f, 0.0f);
    }

}

Cube::~Cube(){



}


