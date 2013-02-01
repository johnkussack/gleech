#include <primitives/Triangle.h>

Triangle::Triangle(){

    // Define 3 vertices
    pushVector3(vertices, -1.0f, -1.0f, 0.0f);
    pushVector3(vertices,  1.0f, -1.0f, 0.0f);
    pushVector3(vertices,  0.0f, 1.0f, 0.0f);

    // All colors are green
    pushVector3(colors,0.0f,1.0f,0.0f);
    pushVector3(colors,0.0f,1.0f,0.0f);
    pushVector3(colors,0.0f,1.0f,0.0f);


    //1 face only
    pushVector2(texturesUv, 0.0f,0.0f);
    pushVector2(texturesUv, 0.0f, 1.0f);
    pushVector2(texturesUv, 0.5f, 1.0f);


}

Triangle::~Triangle(){

}
