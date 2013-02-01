#include <primitives/Plane.h>

Plane::Plane(){

    // Define plane vertices (6 * 3float)

    pushVector3(vertices, 5.0f, -1.0f, -5.0f);
    pushVector3(vertices, -5.0f, -1.0f, -5.0f);
    pushVector3(vertices, -5.0f, -1.0f, 5.0f);

    pushVector3(vertices, 5.0f, -1.0f, -5.0f);
    pushVector3(vertices, -5.0f, -1.0f, 5.0f);
    pushVector3(vertices, 5.0f, -1.0f, 5.0f);


    // All colors are blue, so doing it that way in a loop

    for(int i = 0;i<vertices->size()/3;i++){
        pushVector3(colors,0.0f,0.0f,1.0f);
    }

    //1 face only
    pushVector2(texturesUv, 1.0f,1.0f);
    pushVector2(texturesUv, 0.0f, 1.0f);
    pushVector2(texturesUv, 0.0f, 0.0f);

    pushVector2(texturesUv, 1.0f, 1.0f);
    pushVector2(texturesUv, 0.0f, 0.0f);
    pushVector2(texturesUv, 1.0f, 0.0f);


}

Plane::~Plane(){
    //dtor
}
