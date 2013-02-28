#include <primitives/ModelVertex.h>

ModelVertex::ModelVertex(){

}

ModelVertex::ModelVertex(float x,float y,float z, float c1,float c2,float c3,float n1, float n2,float n3, float uv1,float uv2){
    coords = glm::vec3(x,y,z);
    color = glm::vec4(c1,c2,c3,0);
    normal = glm::vec3(n1,n2,n3);
    uvCoords = glm::vec2(uv1,uv2);
}

ModelVertex::~ModelVertex(){

}
