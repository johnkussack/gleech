#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <iostream>
#include <vector>
#include <glincludes.h>
#include <primitives/ModelVertex.h>



using namespace std;

class Primitive{

    protected:

        vector<ModelVertex*> vertices;
        void pushVertex(ModelVertex* v);

    public:
        Primitive();
        virtual ~Primitive();

        int sceneOffset;

        ModelVertex* getVertex(int _index);
        int getVerticesCount();

};

#endif // PRIMITIVE_H
