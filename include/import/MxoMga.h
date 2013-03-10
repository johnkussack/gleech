#ifndef MXOMGA_H
#define MXOMGA_H

#include <import/BinaryWalker.h>
#include <primitives/IndexedModel.h>

class MxoMga{

    protected:
        string path;
        BinaryWalker b;
        BinaryWalker bM;


        vector<GLfloat> dims;
        vector<string> textures;

        IndexedModel* model;

    public:
        MxoMga(string _path);
        virtual ~MxoMga();

        bool Parse();
        IndexedModel* getModel() {return model;}

};

#endif // MXOMGA_H
