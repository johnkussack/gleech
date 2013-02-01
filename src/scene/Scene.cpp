#include <scene/Scene.h>


Scene::Scene(){


}

Scene::~Scene(){

    for(unsigned int i = 0;i<items.size();i++){
        delete items[i];
    }

    for(unsigned int i = 0;i<itemsTextured.size();i++){
        delete itemsTextured[i];
    }


}


void Scene::setup(GLuint _vaoSolid,GLuint* _vboSolid, GLuint _vaoTextured, GLuint* _vboTextured, Shader* _shader, Shader* _shaderT){
    vaoSolid = _vaoSolid;
    vboSolid[0] = _vboSolid[0];
    vboSolid[1] = _vboSolid[1];
    vboSolid[2] = _vboSolid[2];

    vaoText = _vaoTextured;
    vboText[0] = _vboTextured[0];
    vboText[1] = _vboTextured[1];
    vboText[2] = _vboTextured[2];

    shader = _shader;
    shaderTextures = _shaderT;
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

void Scene::renderTest(){

    shader->bind(); // Bind our shader

        // Get a handle for our "MVP" uniform.
        // Only at initialisation time.

        // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
        glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
        // Camera matrix
        glm::mat4 View = glm::lookAt(
            glm::vec3(4,3,3), // Camera is at (4,3,3), in World Space
            glm::vec3(0,0,0), // and looks at the origin
            glm::vec3(0,1,0) // Head is up (set to 0,-1,0 to look upside-down)
        );

        // Model matrix : an identity matrix (model will be at the origin)
        glm::mat4 Model = glm::mat4(1.0f); // Changes for each model !
        // Our ModelViewProjection : multiplication of our 3 matrices
        glm::mat4 MVP = Projection * View * Model; // Remember, matrix multiplication is the other way around
        GLuint MatrixID = glGetUniformLocation(shader->id(), "MVP");

        // Send our transformation to the currently bound shader,
        // in the "MVP" uniform
        // For each model you render, since the MVP will be different (at least the M part)
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

        // DRAW VBAO contents



        //glBindVertexArray(vaoSolid); // Bind our Vertex Array Object

        glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vboSolid[0]);
		glVertexAttribPointer(
			0,                  // attribute
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);

		// 2nd attribute buffer : UVs
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, vboSolid[1]);
		glVertexAttribPointer(
			1,                                // attribute
			3,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);

        glDrawArrays(GL_TRIANGLES, 9, 36); // Draw our square
        //glBindVertexArray(0); // Unbind our Vertex Array Object
        glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
        // DRAW END


    shader->unbind(); // Unbind our shader
}


void Scene::render(){


    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


    /**** Process Keyboard and mouse inputs ****/
    glm::mat4 MVP = getMatrixFromInputs();

    /**** Render SOLID ****/
    shader->bind(); // Bind our shader

        GLuint MatrixID = glGetUniformLocation(shader->id(), "MVP");
        glUseProgram(shader->id());

		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

        glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, vboSolid[0]);
		glVertexAttribPointer(	0,	3,	GL_FLOAT,GL_FALSE,	0,	(void*)0 );

		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, vboSolid[1]);
		glVertexAttribPointer(	1,	3,	GL_FLOAT,GL_FALSE,	0,	(void*)0 );

		for(unsigned int i=0;i<items.size();i++){
		    SceneItem* t = items[i];
            glDrawArrays(GL_TRIANGLES,t->getOffset(), t->getVerticesCount());
		}


        glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

    shader->unbind();


    /**** Render TEXTURED ****/

    MVP = getMatrixFromInputs();

    shaderTextures->bind(); // Bind our shader

         MatrixID = glGetUniformLocation(shaderTextures->id(), "MVP");
        glUseProgram(shaderTextures->id());



		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);


        glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, vboText[0]);
		glVertexAttribPointer(	0,	3,	GL_FLOAT,GL_FALSE,	0,	(void*)0 );

		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, vboText[1]);
		glVertexAttribPointer(	1,	2,	GL_FLOAT,GL_FALSE,	0,	(void*)0 );

		for(unsigned int i=0;i<itemsTextured.size();i++){
		    SceneItem* t = itemsTextured[i];
            glDrawArrays(GL_TRIANGLES, t->getOffset(), t->getVerticesCount());
		}


        glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

    shaderTextures->unbind();



}
