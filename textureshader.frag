#version 150 core


in vec2 interpolatedFragmentUV;
out vec3 color;

uniform sampler2D myTextureSampler;

void main(){
	color = texture2D(myTextureSampler, interpolatedFragmentUV).rgb;
}