#include <import/MxoProp.h>

MxoProp::MxoProp(string _path){
    path = _path;
}

MxoProp::~MxoProp(){


}

bool MxoProp::Parse(){

    if(b.loadData(path)){
        b.seekToStr("DIMS");

        // Skip length
        b.seek(8);

        // Get Bounding Box
        for(int i = 0;i<6;i++){
            dims.push_back(b.getFloat());
        }

        // Skip to texture info
        b.seek(12);

        unsigned int textureCount = b.getInt32();
        for(unsigned int i = 0;i<textureCount;i++){
            textures.push_back(b.getBlob(4));
        }

        // Skip MESH+pointer
        b.seek(8);


        model = new IndexedModel();

        unsigned int meshCount = b.getInt32();

        for(unsigned int i = 0;i<meshCount;i++){

            model->addMesh();

            b.seek(4); // Skip SMSH
            unsigned int meshWHOLEDATASize = b.getInt32();
            b.seek(4); // Skip data

            // We will ignore this blob for now
            string meshBlob = b.getBlob(0x20);

            // Prepare to do zlib.uncompress(MESHCHUNK)
            unsigned long zlibBufferSize = (unsigned long) b.getInt32();
            unsigned char* zlibBuffer = new unsigned char[zlibBufferSize];

            unsigned int meshZlibSize = b.getInt32();
            string meshZlibBlob = b.getBlob(meshZlibSize);


            uncompress((Bytef *)zlibBuffer, &zlibBufferSize,  (Bytef *)meshZlibBlob.c_str(), meshZlibSize);

            // Gather meshData
            string meshData;

            for(unsigned int j = 0;j<zlibBufferSize;j++){
                meshData+=zlibBuffer[j];
            }

            delete zlibBuffer;

            // Prepare another binaryWalker
            bm.setData(meshData);

            unsigned int meshChunkLength = bm.getInt32();
            unsigned int meshVerticesCount = bm.getInt32();
            bm.seek(8); // say...say my name... little little love....


            for(unsigned int j = 0;j<meshVerticesCount;j++){

                // Mesh creation
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

            }

            while(bm.getOffset()!=meshChunkLength+4){
                unsigned short index = bm.getInt16();
                 (model->getCurrentMesh())->addIndex(index);
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
