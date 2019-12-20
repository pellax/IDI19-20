#version 330 core

out vec4 FragColor;
in vec3 fcolor;
/*void main() {
rloat radio=sqrt(pow(gl_Fragcoord.x - 354,2)+pow(gl_FragCoord.y);

if (reste >= 0 && reste <= 10) 
discard;  

 if(gl_FragCoord.x <= 360 && gl_FragCoord.y >= 354)

{  

    FragColor = vec4(1, 0, 0, 1);
} 
   if(gl_FragCoord.x <= 360 && gl_FragCoord.y < 354)
{ 
       FragColor = vec4(1, 1, 0, 1);
} 
   if(gl_FragCoord.x > 360 && gl_FragCoord.y >=354)
{ 
       FragColor = vec4(0, 0, 1, 1);
} 
   if(gl_FragCoord.x > 360 && gl_FragCoord.y < 354)
{ 
       FragColor = vec4(0, 1, 0, 1);
}
}
*/
void main(){
float radio=sqrt(pow(gl_FragCoord.x - 354,2)+pow(gl_FragCoord.y-354,2));

if (radio <= 75) 
discard;  

FragColor =vec4(fcolor,1) ;

}
