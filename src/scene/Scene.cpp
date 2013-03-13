#include <scene/Scene.h>


Scene::Scene(Globals* _glb){
    glb = _glb;
}

Scene::~Scene(){

    for(unsigned int i = 0;i<items.size();i++){
        delete items[i];
    }

    items.clear();

}

void Scene::pushItem(SceneItem* _item){
    items.push_back(_item);
    //cout<<"[Scene] Added new model (ptr "<<_item->getModel()<<") Meshes inside: " <<_item->getModel()->getModelMeshCount()<<endl;
}


void Scene::render(){

    glm::mat4 V;glm::mat4 P;
    glm::mat4 MVP;
    GLuint MatrixID;
    
    glm::mat4 M(1.0f);
    
    glb->camera->GetVP(&V,&P);

    //////RENDER MODELS

    glb->textureShader->bind(); // Bind our shader

    glActiveTexture(GL_TEXTURE0);

    for(unsigned int i=0;i<items.size();i++){

        SceneItem* si = items[i];
        IndexedModel * m = si->getModel();

        MVP = P*V*si->getModelMatrix();
        MatrixID = glGetUniformLocation(glb->textureShader->id(), "MVP");
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

        for(int j=0;j<m->getModelMeshCount();j++){

            ModelMesh* mm = m->getModelMesh(j);

            ////////////////

            glBindTexture(GL_TEXTURE_2D, mm->getTexture());

            ////////////////

            glEnableVertexAttribArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, mm->getVbos()[0]);
            glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

            glEnableVertexAttribArray(1);
            glBindBuffer(GL_ARRAY_BUFFER, mm->getVbos()[1]);
            glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,0,(void*)0);

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mm->getElementBuffer());
            glDrawElements(GL_TRIANGLES, mm->getIndices()->size(), GL_UNSIGNED_INT, 0);

            glDisableVertexAttribArray(1);
            glDisableVertexAttribArray(0);

        }

    }

    glb->textureShader->unbind();

    // Disable bindings
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


}
