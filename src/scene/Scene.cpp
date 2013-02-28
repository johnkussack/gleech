#include <scene/Scene.h>


Scene::Scene(Globals* _glb){
    glb = _glb;
}

Scene::~Scene(){

    for(unsigned int i = 0;i<items.size();i++){
        delete items[i];
    }

    for(unsigned int i = 0;i<itemsTextured.size();i++){
        delete itemsTextured[i];
    }

    for(unsigned int i = 0;i<models.size();i++){
        delete models[i];
    }

    items.clear();
    itemsTextured.clear();
    models.clear();

}


void Scene::setup(GLuint* _vboSolid,  GLuint* _vboTextured){
    vboSolid[0] = _vboSolid[0];
    vboSolid[1] = _vboSolid[1];
    vboSolid[2] = _vboSolid[2];

    vboText[0] = _vboTextured[0];
    vboText[1] = _vboTextured[1];
    vboText[2] = _vboTextured[2];

}

void Scene::pushItem(SceneItem* _newItem){
    if(_newItem->getTexture()==0){
        items.push_back(_newItem);
        printf("[Scene] Added solid item\n");
    }else{
        itemsTextured.push_back(_newItem);
        printf("[Scene] Added textured item\n");
    }

}

void Scene::pushModel(IndexedModel* _newModel){
    models.push_back(_newModel);
    cout<<"[Scene] Added new model (ptr "<<_newModel<<") Meshes inside: " <<_newModel->getModelMeshCount()<<endl;
}



void Scene::render(){

    glm::mat4 V;glm::mat4 P;
    glm::mat4 MVP;
    GLuint MatrixID;

    glb->camera->GetVP(&V,&P);

    glm::mat4 M(1.0f);
    
    //////RENDER MODELS


    glb->textureShader->bind(); // Bind our shader

    glActiveTexture(GL_TEXTURE0);

    for(unsigned int i=0;i<models.size();i++){

        IndexedModel * m = models[i];

        MVP = P*V*m->getModelMatrix();
        MatrixID = glGetUniformLocation(glb->textureShader->id(), "MVP");
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

        for(int j=0;j<m->getModelMeshCount();j++){

            ModelMesh* mm = m->getModelMesh(j);

            ////////////////
            if(i>1){
                glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
                glBindTexture(GL_TEXTURE_2D, mm->getTexture());

            }else{
                glBindTexture(GL_TEXTURE_2D, mm->getTexture());

            }
            

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

            if(i>1){
                glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
            }

        }

    }

    glb->textureShader->unbind();


    //////



    /**** Render SOLID ****/
    glb->solidShader->bind(); // Bind our shader

        glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, vboSolid[0]);
		glVertexAttribPointer(	0,	3,	GL_FLOAT,GL_FALSE,	0,	(void*)0 );

		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, vboSolid[1]);
		glVertexAttribPointer(	1,	3,	GL_FLOAT,GL_FALSE,	0,	(void*)0 );


		for(unsigned int i=0;i<items.size();i++){
		    SceneItem* t = items[i];

            MVP = P*V*t->GetModelMatrix();
		    MatrixID = glGetUniformLocation(glb->solidShader->id(), "MVP");

            glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

            glDrawArrays(GL_TRIANGLES,t->getOffset(), t->getVerticesCount());
		}



        glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

    glb->solidShader->unbind();


    /**** Render TEXTURED ****/

    glb->textureShader->bind(); // Bind our shader

        glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vboText[0]);
		glVertexAttribPointer(	0,	3,	GL_FLOAT,GL_FALSE,	0,	(void*)0 );


		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, vboText[1]);
		glVertexAttribPointer(	1,	2,	GL_FLOAT,GL_FALSE,	0,	(void*)0 );


		for(unsigned int i=0;i<itemsTextured.size();i++){
		    SceneItem* t = itemsTextured[i];


		    MVP = P*V*t->GetModelMatrix();
		    MatrixID = glGetUniformLocation(glb->textureShader->id(), "MVP");

            glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

            ////////////////
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, t->getTexture());
            //glUniform1i(t->getTextureId(), 0);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            ////////////////


            glDrawArrays(GL_TRIANGLES, t->getOffset(), t->getVerticesCount());
	}



        glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

    glb->textureShader->unbind();

    // Disable any binding, so SFML doesnt yell
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


    if (!glb->soundMan->playing()){
        glb->soundMan->play();
    }



}
