#include <primitives/Primitive.h>

Primitive::Primitive(){

}

Primitive::~Primitive(){
    vertices.clear();
}

void Primitive::pushVertex(ModelVertex* v){
    vertices.push_back(v);
}


ModelVertex* Primitive::getVertex(int _index){
    return vertices[_index];
}

int Primitive::getVerticesCount(){
    return vertices.size();
}
