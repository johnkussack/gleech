#version 150 core

in vec3 vertexPosition_modelspace;
uniform mat4 MVP;
out vec3 fragmentColor;

layout(location = 1) in vec3 vertexColor;

void main(void){
	
	vec4 v = vec4(vertexPosition_modelspace,1); // Transform an homogeneous 4D vector, remember ?
	gl_Position = MVP * v;
	
	fragmentColor = vertexColor;
	
}