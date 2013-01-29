#version 150 core

//NEW TUT
in vec3 fragmentColor;
out vec3 color;

void main(void){
	// interpolated between all 3 surrounding vertices
	color = fragmentColor;
}