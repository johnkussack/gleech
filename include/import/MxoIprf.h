
#ifndef MXOIPRF_H
#define	MXOIPRF_H

#include <import/BinaryWalker.h>
#include <import/IndexedModel.h>

using namespace std;

class MxoIprf {
    
    protected:
        string path;
        BinaryWalker b;
        BinaryWalker bm;
        
        vector<string> textures;

        IndexedModel* model;
    
    public:
        MxoIprf(string _path);
        virtual ~MxoIprf();

        bool Parse();
        IndexedModel* getModel() {return model;}

};


#endif	/* MXOIPRF_H */

