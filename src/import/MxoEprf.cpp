
#include <import/MxoEprf.h>

#include "import/BinaryWalker.h"

MxoEprf::MxoEprf(string _path){
    path = _path;
}

MxoEprf::~MxoEprf() {
}

bool MxoEprf::Parse(){

    if(b.loadData(path)){
        b.seekToStr("MESH");

        model = new IndexedModel();
        
        bool parsing = true;
        
        //LOCALS
        float minX = 0;
        float minZ = 0;
        float maxX = 0;
        float maxZ = 0;
        float minY = 0;
        float maxY = 0;
        
        while (parsing){
            
            
            int meshLength = b.getInt32();
            b.seek(4); // Ignore size
            
            string meshData = b.getBlob(meshLength);
            
            if(meshLength>=100){
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

                    vert->uvCoords.x = bm.getFloat();
                    vert->uvCoords.y = (1.0f - bm.getFloat()); // Reverse DDS V from directX to openGL

                    // ADD vertex to current mesh
                    (model->getCurrentMesh())->addVertex(vert);
                    
                    // Force bounding limit checks
                    if (vert->coords.x>maxX){
                        maxX = vert->coords.x;
                    }

                    if (vert->coords.z>maxZ){
                        maxZ = vert->coords.z;
                    }
                    

                    if (vert->coords.x<minX){
                        minX = vert->coords.x;
                    }

                    if (vert->coords.z<minZ){
                        minZ = vert->coords.z;
                    }
                    
                    // Y axis
                    if (vert->coords.y<minY){
                        minY = vert->coords.y;
                    }

                    if (vert->coords.y>maxY){
                        maxY = vert->coords.y;
                    }
                    
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
        
        // Parse the boundaries (not zero centering check in)
        
        float limitZ = abs(round(minZ));
        float limitX = abs(round(maxX));
        
        if (limitZ == 0 && limitX==0){
            glm::vec3 center(-(minX-maxX)/2,(maxY-minY)/2,-(maxZ-minZ)/2);
            model->setCenter(center);
            model->setZeroCentered(false);
            //cout<<"MXO EPRF DEBUG: "<<minX<<" "<<limitZ<<" "<<limitX<<" "<<maxZ<<" "<<((limitZ==0 && limitX==0)?"YES":"NO")<<endl;
            cout<<"MXO EPRF: Adjunsting center, EPRF is not zero centered, is zero origin"<<endl;
                
        }
        

        return true;
    }else{
        cout<<"[ERROR] Could not load MXO Prop: "<<path<<endl;
        return false;
    }
}
