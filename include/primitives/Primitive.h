#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <glincludes.h>
#include <stdio.h>
#include <string.h>

class Primitive{

    protected:




    public:
        Primitive();
        virtual ~Primitive();

        GLfloat* pVertices;
        GLfloat* pColors;
        GLfloat* pTexturesUV;
        GLfloat* pNormals;

        int TRIANGLE_INDEX_COUNT;

        int verticesCount;
        int colorsCount;
        int texturesUVCount;
        // TODO NORMALS???

        int pSceneOffset;
};

#endif // PRIMITIVE_H
