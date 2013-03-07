
#ifndef MXOEPRF_H
#define	MXOEPRF_H

#include <import/BinaryWalker.h>
#include <import/IndexedModel.h>

using namespace std;

class MxoEprf {
    
    protected:
        string path;
        BinaryWalker b;
        BinaryWalker bm;

        
        vector<string> textures;

        IndexedModel* model;
    
    public:
        MxoEprf(string _path);
        virtual ~MxoEprf();

        bool Parse();
        IndexedModel* getModel() {return model;}

};


#endif	/* MXOEPRF_H */

