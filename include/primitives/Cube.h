#ifndef CUBE_H
#define CUBE_H

#include <primitives/Primitive.h>

class Cube :public Primitive{

    protected:

        GLfloat vertices[108];
        GLfloat colors[108];
        GLfloat textureUv[72];

    public:
        Cube();
        virtual ~Cube();


};

#endif // CUBE_H
