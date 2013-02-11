#include <primitives/Mesh.h>

Mesh::Mesh(): Primitive(){

    // Define Mesh vertices (36* 3float)

pushVector3(vertices, 1.12807524204,0.907885968685,-2.56966948509);
pushVector3(vertices, 0.907885968685,-2.56966948509,65.7459640503);
pushVector3(vertices, -0.22293227911,0.489403069019,-0.843081176281);


    // All colors are red, so doing it that way in a loop

    for(int i = 0;i<vertices->size()/3;i++){
        pushVector3(colors,1.0f,0.0f,0.0f);
    }

    // All 6 faces have the same UV map (repeating the texture, so loop)
    // Bottom face will be reversed if looking from below!!!

    for (int i = 0;i<vertices->size()/3; i++){
        pushVector2(texturesUv, 1.0f,1.0f);
        pushVector2(texturesUv, 0.0f, 1.0f);
        pushVector2(texturesUv, 0.0f, 0.0f);
        pushVector2(texturesUv, 1.0f, 1.0f);
        pushVector2(texturesUv, 0.0f, 0.0f);
        pushVector2(texturesUv, 1.0f, 0.0f);
    }

}

Mesh::~Mesh(){



}


