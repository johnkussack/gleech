#ifndef MODELDATABASE_H
#define	MODELDATABASE_H

#include <glincludes.h>
#include <primitives/IndexedModel.h>
#include <map>

using namespace std;

class ModelDatabase {
    
    private:
        vector<IndexedModel*> models;
        map<string, int> modelReferences;

    public:
        ModelDatabase();
        virtual ~ModelDatabase();
        
        int isKnownModel(string _path);
        
        int addModel(IndexedModel* _model, string _path);
        IndexedModel* getModel(int _index);

};

#endif	/* MODELDATABASE_H */

