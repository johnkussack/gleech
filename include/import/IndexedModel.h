#ifndef INDEXEDMODEL_H
#define INDEXEDMODEL_H

#include <iostream>
#include <algorithm>    // std::max
#include <glincludes.h>
#include <primitives/ModelVertex.h>

using namespace std;

class ModelMesh{

    protected:
        GLuint elementBuffer;
        GLuint modelVbo[3];
        GLuint texture;

        vector<GLuint> indices;
        vector<ModelVertex*> vertices; // Interleaved

    public:

        ModelMesh();

        virtual ~ModelMesh();

        vector<GLuint>* getIndices();
        vector<ModelVertex*>* getVertices();

        // VBOS & ElementBuffer
        GLuint getElementBuffer();
        GLuint* getVbos();

         // Texturing

        void setTexture(GLuint _texture);
        GLuint getTexture();
        GLuint getTextureId();

        void addVertex(ModelVertex* _vert);

        void addIndex(unsigned int _index);

        void initVao();

};

class IndexedModel{

    protected:

        vector<ModelMesh*> meshes;
        ModelMesh* currMesh;

        glm::vec3 scale;
        glm::vec3 rotation;
        glm::vec3 translation;

        glm::mat4 modelMatrix;

        void recalculateModelMatrix();

    public:
        IndexedModel();
        virtual ~IndexedModel();

        void addMesh();
        void initVao();

        ModelMesh* getCurrentMesh();

        int getModelMeshCount();
        ModelMesh* getModelMesh(int _index);

        void setTexture(int meshIndex, GLuint _texture);

        void setScale(glm::vec3 _scale);
        void setRotation(glm::vec3 _rotation);
        void setTranslation(glm::vec3 _translation);
        glm::mat4 getModelMatrix();

};

#endif // INDEXEDMODEL_H
