#ifndef __MODELVERTES__
#define __MODELVERTES__

#include <glincludes.h>

class ModelVertex{

    public:
        glm::vec3 coords;
        glm::vec4 color;
        glm::vec3 normal;
        glm::vec2 uvCoords;


        ModelVertex();

        ModelVertex(float x,float y,float z, float c1,float c2,float c3,float n1, float n2,float n3, float uv1,float uv2);

        virtual ~ModelVertex();

};

#endif
