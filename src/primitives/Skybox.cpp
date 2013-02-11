#include <primitives/Skybox.h>

Skybox::Skybox(): Primitive(){

    // Define Skybox vertices (36* 3float)

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




    // Front face

    float modifiersX[6] = {0.75f,0.5f,0.0f,0.25f,0.25f,0.25f};
    float modifiersY[6] = {0.33f,0.33f,0.33f,0.33f,0.66f,0.0f};

    for (int i = 0;i<6; i++){

        float minx = 0.0f +modifiersX[i]; float maxx =0.25f+modifiersX[i];
        float miny = 0.0f+modifiersY[i]; float maxy =0.33f+modifiersY[i];

        pushVector2(texturesUv, maxx,maxy);
        pushVector2(texturesUv, minx,maxy);
        pushVector2(texturesUv, minx,miny);

        pushVector2(texturesUv, maxx,maxy);
        pushVector2(texturesUv, minx,miny);
        pushVector2(texturesUv, maxx,miny);
    }

}

Skybox::~Skybox(){



}


