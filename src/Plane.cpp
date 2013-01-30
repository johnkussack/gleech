#include <primitives/Plane.h>

Plane::Plane(){

    GLfloat localVert[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f
    };

    GLfloat localColor [] = {
        1.0f,0.0f,0.0f,
        1.0f,0.0f,0.0f,
        1.0f,0.0f,0.0f,
        1.0f,0.0f,0.0f,
        1.0f,0.0f,0.0f,
        1.0f,0.0f,0.0f,
        1.0f,0.0f,0.0f,
        1.0f,0.0f,0.0f,
        1.0f,0.0f,0.0f
    }; //PURE RED

    GLfloat localUV[]={
        0.000005,-0.004081,
        0.000925,0.294922,
        0.300783,0.294922,
        0.902339,-0.004081,
        0.601561,0.294922,
        0.901419,0.294922,
    };

    verticesCount = 9;
    colorsCount = 9;
    texturesUVCount = 2;

    memcpy(vertices, localVert, verticesCount*sizeof(GLfloat));
    pVertices = &vertices[0]; // SET IT

    memcpy(colors, localColor, colorsCount*sizeof(GLfloat));
    pColors = &colors[0]; // SET IT

    memcpy(textureUv, localUV, texturesUVCount*sizeof(GLfloat));
    pTexturesUV = &textureUv[0]; // SET IT

    TRIANGLE_INDEX_COUNT = 1*3;
}

Plane::~Plane()
{
    //dtor
}
