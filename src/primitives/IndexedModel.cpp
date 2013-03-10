#include <primitives/IndexedModel.h>

/******************/
/* MODEL MESH  */
/******************/
ModelMesh::ModelMesh(){
    texture = 0;
    
}

ModelMesh::~ModelMesh() {
    indices.clear();

    glDeleteBuffers(1,&elementBuffer);
    glDeleteBuffers(3,&modelVbo[0]);

    // delete vertices
    for (unsigned int i=0;i<vertices.size();i++){
        delete vertices.at(i);
    }
    vertices.clear();
}

vector<GLuint>* ModelMesh::getIndices() { return &indices; }
vector<ModelVertex*>* ModelMesh::getVertices(){return &vertices; }

GLuint ModelMesh::getElementBuffer(){ return elementBuffer;}
GLuint* ModelMesh::getVbos(){ return &modelVbo[0];}

void ModelMesh::setTexture(GLuint _texture) { texture = _texture;}
GLuint ModelMesh::getTexture() {return texture;}

void ModelMesh::addVertex(ModelVertex* _vert) {
    vertices.push_back(_vert);
}

void ModelMesh::addIndex(unsigned int _index){
    indices.push_back(_index);
}

void ModelMesh::initVao(){

    glGenBuffers(3, &modelVbo[0]);

    vector<GLfloat> _tVertices;
    vector<GLfloat> _colors;
    vector<GLfloat> _uvCoords;

    for(unsigned int i = 0;i<vertices.size();i++){
        ModelVertex* v = vertices.at(i);
        _tVertices.push_back(v->coords.x);
        _tVertices.push_back(v->coords.y);
        _tVertices.push_back(v->coords.z);
        _colors.push_back(v->color.x);
        _colors.push_back(v->color.y);
        _colors.push_back(v->color.z);
        //TODO: ADD ALPHA
        _uvCoords.push_back(v->uvCoords.x);
        _uvCoords.push_back(v->uvCoords.y);


    }

    glBindBuffer(GL_ARRAY_BUFFER, modelVbo[0]);
    glBufferData(GL_ARRAY_BUFFER, _tVertices.size()*sizeof(GLfloat),&(_tVertices.at(0)), GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, modelVbo[1]);
    //if(texture==0){
    //    glBufferData(GL_ARRAY_BUFFER, _colors.size()*sizeof(GLfloat),&(_colors.at(0)), GL_STATIC_DRAW);
    //}
    //else{
        glBufferData(GL_ARRAY_BUFFER, _uvCoords.size()*sizeof(GLfloat),&(_uvCoords.at(0)), GL_STATIC_DRAW);
    //}


    glGenBuffers(1, &elementBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &(indices.at(0)), GL_STATIC_DRAW);


    /*cout<<"## Sanity check ##"<<endl;
    cout<<"Vertices"<<_tVertices.size()<<endl;
    cout<<"COLORS: "<<_colors.size()<<endl;
    cout<<"UVs: "<<_uvCoords.size()<<endl;*/

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}




/******************/
/* INDEXED MODEL  */
/******************/




IndexedModel::IndexedModel(){
}

IndexedModel::~IndexedModel(){

    for(unsigned int i = 0; i<meshes.size();i++){
        delete meshes.at(i);
    }
    meshes.clear();

}

ModelMesh* IndexedModel::getCurrentMesh(){
    return currMesh;
}

int IndexedModel::getModelMeshCount() {
    return meshes.size();
}

ModelMesh* IndexedModel::getModelMesh(int _index) {
    return meshes.at(_index);
}

void IndexedModel::setTexture(int _index, GLuint _texture){
    meshes[_index]->setTexture(_texture);
}

void IndexedModel::addMesh(){
    currMesh = new ModelMesh();
    meshes.push_back(currMesh);
}

void IndexedModel::initVao(){

    for(unsigned int i = 0;i<meshes.size();i++){
        ModelMesh* m = meshes.at(i);
        m->initVao();
    }


}
