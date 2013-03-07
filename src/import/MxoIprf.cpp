
#include <import/MxoIprf.h>

#include "import/BinaryWalker.h"

MxoIprf::MxoIprf(string _path){
    path = _path;
}

MxoIprf::~MxoIprf() {
}

bool MxoIprf::Parse(){

    if(b.loadData(path)){
        b.seekToStr("MESH");

        model = new IndexedModel();
        
        bool parsing = true;
        
        while (parsing){
            
            
            int meshLength = b.getInt32();
            b.seek(4); // Ignore size
            
            string meshData = b.getBlob(meshLength);
            
            if(meshLength>=0x100){
                model->addMesh();
                bm.setData(meshData);
                
                bm.seek(4); //size not wanted
		bm.seek(4); //info not wanted
		bm.seek(4); // should be FFFFFFFF
		bm.seek(4); //size not wanted
		unsigned int verticesCount = bm.getInt32();
		unsigned int triangleCount = bm.getInt32();
		unsigned int unknown = bm.getInt32();

                for(unsigned int i = 0;i<verticesCount;i++){
                    ModelVertex* vert = new ModelVertex();
                    vert->coords.x = -1 * bm.getFloat() / 100.0;
                    vert->coords.y = bm.getFloat() / 100.0;
                    vert->coords.z = bm.getFloat() /100.0;

                    vert->normal.x = bm.getFloat(); // NORMALS
                    vert->normal.y = bm.getFloat();
                    vert->normal.z = bm.getFloat();

                    vert->color.x = 1.0f;
                    vert->color.y = 0.0f;
                    vert->color.z = 0.0f;

                    if(unknown==0x33){
                        bm.seek(8);
                    }
                    
                    vert->uvCoords.x = bm.getFloat();
                    vert->uvCoords.y = (1.0f - bm.getFloat()); // Reverse DDS V from directX to openGL

                    // ADD vertex to current mesh
                    (model->getCurrentMesh())->addVertex(vert);
                }
                
                for(unsigned int i = 0;i<triangleCount;i++){
                    (model->getCurrentMesh())->addIndex(bm.getInt16());
                    (model->getCurrentMesh())->addIndex(bm.getInt16());
                    (model->getCurrentMesh())->addIndex(bm.getInt16());
                }
				
            }
            
            string check = b.getBlob(4);
            if (check!="MESH"){
                parsing = false;
            }
            

        }

        // INIT THE MODEL
        model->initVao();

        return true;
    }else{
        cout<<"[ERROR] Could not load MXO Prop: "<<path<<endl;
        return false;
    }
}
