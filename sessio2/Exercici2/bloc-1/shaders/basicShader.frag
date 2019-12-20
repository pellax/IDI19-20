#version 330 core

out vec4 FragColor;

void main() {
//float reste =mod(gl_FragCoord.y,20);
float reste = mod(gl_FragCoord.y,4);
//if (reste >= 0 && reste <= 10) 
if (reste == 0)
discard;  

 if(gl_FragCoord.x <= 360 && gl_FragCoord.y >= 240)

{  

    FragColor = vec4(1, 0, 0, 1);
} 
   if(gl_FragCoord.x <= 360 && gl_FragCoord.y <240)
{ 
       FragColor = vec4(1, 1, 0, 1);
} 
   if(gl_FragCoord.x > 360 && gl_FragCoord.y >=240)
{ 
       FragColor = vec4(0, 0, 1, 1);
} 
   if(gl_FragCoord.x > 360 && gl_FragCoord.y < 240)
{ 
       FragColor = vec4(0, 1, 0, 1);
}
}

