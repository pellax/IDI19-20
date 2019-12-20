#version 330 core

in vec3 fcolor;

out vec4 FragColor;

void main() {
float reste = int(gl_FragCoord.y)%4;
if(gl_FragCoord.y >=480 && reste > 0 )

	discard;
	


FragColor = vec4(fcolor, 1);
}

