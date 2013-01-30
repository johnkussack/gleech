#ifndef PLANE_H
#define PLANE_H

#include <primitives/Primitive.h>

class Plane : public Primitive{

    private:
        GLfloat vertices[9];
        GLfloat colors[27];
        GLfloat textureUv[12];


    public:
        Plane();
        virtual ~Plane();


};

#endif // PLANE_H
