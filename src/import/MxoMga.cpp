#include <import/MxoMga.h>

MxoMga::MxoMga(string _path){
   path = _path;
}

MxoMga::~MxoMga(){

}

bool MxoMga::Parse(){

    if(b.loadData(path)){

        model = new IndexedModel();

        b.seek(0x11); // DUNNO THIS HEADER YET!

        while(!b.reachedEnd()){

            if(b.bytesRemaining()<=10){ // DOH!
                break;
            }

            string header = b.getBlob(6); // Header
            unsigned long objectLength = b.getInt32();
            string objData = b.getBlob(objectLength);

            bM.setData(objData);

            unsigned int verticesCount = bM.getInt32();
            unsigned int triangleCount = bM.getInt32();

            model->addMesh();

            unsigned int unknownIndex = bM.getInt32();
            unsigned int unknownIndex2 = bM.getInt32();
            unsigned long blobToSkip = 0;
            unsigned long vertexRemaining = 0;
            string stuff;

            switch(unknownIndex){
                case 1:
                    vertexRemaining = 0;
                    bM.seek(4);
                    blobToSkip = unknownIndex2*16;
                    bM.seek(blobToSkip);
                break;
                case 2:
                    vertexRemaining = 4;
                    bM.seek(5);
                    blobToSkip = 13;
                    bM.seek(blobToSkip);
                break;

                case 3:
                    vertexRemaining = 16;
                    bM.seek(4);
                    blobToSkip = unknownIndex2*7;
                    bM.seek(blobToSkip);
                break;

                case 4:
                    vertexRemaining = 12;

                    switch (unknownIndex2){
                        case 3:
                            bM.seek(5);
                            blobToSkip = unknownIndex2*28;
                            break;
                        case 2:
                            blobToSkip = 18;
                            break;
                        default:
                            cout<<"Not known SUBindex before vertices data:"<<unknownIndex<<" pos:"<<bM.getOffset()<<" "<<b.getOffset()<<endl;
                            exit(1);
                            break;
                    }
                    stuff = bM.getBlob(blobToSkip);

                    if(stuff.find((unsigned char)0x33) !=string::npos){
                        vertexRemaining = 20;
                    }
                break;

                case 6:
                    vertexRemaining = 16;
                    bM.seek(5);
                    blobToSkip = unknownIndex2*16;
                    bM.seek(blobToSkip);
                break;

                default:
                    cout<<"Not known index before vertices data:"<<unknownIndex<<" pos:"<<bM.getOffset()<<" "<<b.getOffset()<<endl;
                    exit(1);
                break;


            }

            for(unsigned int i = 0;i<verticesCount;i++){

                ModelVertex* vert = new ModelVertex();

                vert->coords.x = bM.getFloat();
                vert->coords.y = bM.getFloat();
                vert->coords.z = bM.getFloat();



                bool sanity = true;


                if (
                    (vert->coords.x <0 && vert->coords.x >-0.000005) || (vert->coords.x >0 && vert->coords.x <0.000005) ||
                    (vert->coords.y <0 && vert->coords.y >-0.000005) || (vert->coords.y >0 && vert->coords.y <0.000005) ||
                    (vert->coords.z <0 && vert->coords.z >-0.000005) || (vert->coords.z >0 && vert->coords.z <0.000005)
                    ){
                    sanity = false;
                }


                if (!sanity){
                    cout<<"### VERTEX SANITY NOT PASSED ###"<<endl;
                    cout<<"Check: "<<i<<" of "<<verticesCount<<"vertices"<<endl;
                    cout<<"Vertex info not known:"<<vertexRemaining<<endl;
                    cout<<"Check: "<<vert->coords.x<<" "<<vert->coords.y<<" "<<vert->coords.z <<endl;
                    cout<<"Check: "<<" "<<unknownIndex<<" "<<unknownIndex2<<" "<<blobToSkip<<endl;
                    cout<<"Check: "<<" "<<b.getOffset()-objectLength<<" "<<"BM OFFSET"<<" "<<bM.getOffset()-12<<" "<<"MIX"<<" "<<b.getOffset()-objectLength+bM.getOffset()-12<<endl;
                    exit(1);
                }

                vert->coords.x = -1 * vert->coords.x / 100.0;
                vert->coords.y = vert->coords.y / 100.0;
                vert->coords.z = vert->coords.z / 100.0;


                vert->normal.x = bM.getFloat(); // NORMALS
                vert->normal.y = bM.getFloat();
                vert->normal.z = bM.getFloat();

                if(vertexRemaining!=0){
                    bM.seek(12);
                }

                vert->uvCoords.x = bM.getFloat();
                vert->uvCoords.y = (1.0f - bM.getFloat()); // Reverse DDS V from directX to openGL


                //########## SKIP REST HERE
                if (vertexRemaining != 0){
                    bM.seek(vertexRemaining-12);
                }
                //########## SKIP REST HERE END

                vert->color.x = 1.0f;
                vert->color.y = 0.0f;
                vert->color.z = 0.0f;

                model->getCurrentMesh()->addVertex(vert);

            }

            for(unsigned int i = 0;i<triangleCount;i++){
                unsigned short t1 = bM.getInt16();
                unsigned short t2 = bM.getInt16();
                unsigned short t3 = bM.getInt16();

                bool sanity = true;

                if( t1<0 || t1 >verticesCount || t2<0 || t2 > verticesCount || t3<0 || t3>verticesCount){
                    sanity = false;
                }

                if (!sanity){
                    cout<<"### INDEX SANITY NOT PASSED ###"<<endl;
                    cout<<"Check: "<<t1<<" "<<t2<<" "<<t3<<endl;
                    cout<<"Check: "<<" "<<unknownIndex<<" "<<unknownIndex2<<" "<<blobToSkip<<endl;
                    cout<<"Check: "<<" "<<b.getOffset()-objectLength<<" "<<"BM OFFSET"<<" "<<bM.getOffset()<<" "<<"MIX"<<" "<<b.getOffset()-objectLength+bM.getOffset()<<endl;
                    exit(1);
                }

                model->getCurrentMesh()->addIndex(t1);
                model->getCurrentMesh()->addIndex(t2);
                model->getCurrentMesh()->addIndex(t3);

            }

        }
        model->initVao();
        return true;
    }else{
        cout<<"[ERROR] Could not load MXO MGA: "<<path<<endl;
        return false;
    }
}

