#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <glincludes.h>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

class Primitive{

    protected:

        vector<GLfloat>* vertices;
        vector<GLfloat>* colors;
        vector<GLfloat>* texturesUv;
        vector<GLfloat>* normals;


        // values are casted, so compiler doesnt yell about GLfloat != float

        void pushVector3(vector<GLfloat>* store,float a,  float b, float c){
            store->push_back((GLfloat)a);
            store->push_back((GLfloat)b);
            store->push_back((GLfloat)c);
        }


        void pushVector2(vector<GLfloat>* store, float a, float b){
            store->push_back((GLfloat)a);
            store->push_back((GLfloat)b);
        }


    public:
        Primitive();
        virtual ~Primitive();

        int sceneOffset;

        vector<GLfloat>* getVertices() { return vertices; }
        vector<GLfloat>* getColors() { return colors; }
        vector<GLfloat>* getTexturesUv() { return texturesUv; }
        vector<GLfloat>* getNormals() { return normals; }
        int getHumanVertexCount() {return vertices->size()/3;}


};

#endif // PRIMITIVE_H
