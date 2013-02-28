#ifndef MXOPROP_H
#define MXOPROP_H

#include <import/BinaryWalker.h>
#include <import/IndexedModel.h>
#include <zlib.h>

using namespace std;

class MxoProp{
    protected:
        string path;
        BinaryWalker b;
        BinaryWalker bm;


        vector<GLfloat> dims;
        vector<string> textures;

        IndexedModel* model;


    public:
        MxoProp(string _path);
        virtual ~MxoProp();

        bool Parse();
        IndexedModel* getModel() {return model;}

};

#endif // MXOPROP_H
