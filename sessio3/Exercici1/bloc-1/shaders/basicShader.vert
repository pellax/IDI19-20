#version 330 core

in vec3 vertex;
in vec3 colors;
uniform float val;
out vec3 fcolor;
void main()  {
   gl_Position =vec4 (vertex * val, 1.0);
   fcolor = colors;
}
