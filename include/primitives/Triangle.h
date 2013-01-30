#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <primitives/Primitive.h>

class Triangle: public Primitive
{

public:
    Triangle();
    virtual ~Triangle();

    void Create(Shader* _shader);
    void Render(GLuint MatrixID,GLfloat* MVP);

};

#endif // TRIANGLE_H
