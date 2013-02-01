#include <primitives/Primitive.h>

Primitive::Primitive(){
    vertices = new vector<GLfloat>();
    colors= new vector<GLfloat>();
    texturesUv= new vector<GLfloat>();
    normals = new vector<GLfloat>();
}

Primitive::~Primitive(){
    vertices->clear();
    colors->clear();
    texturesUv->clear();
    normals->clear();

    delete vertices;
    delete colors;
    delete texturesUv;
    delete normals;

}
