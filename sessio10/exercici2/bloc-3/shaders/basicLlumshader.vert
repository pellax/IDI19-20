#version 330 core

in vec3 vertex;
in vec3 normal;

in vec3 matamb;
in vec3 matdiff;
in vec3 matspec;
in float matshin;

//out vec3 matamb1;
//out vec3 matdiff1;
//out vec3 matspec1;
//out float matshin1;
out vec3 NormSCO;
out vec4 vertexSCO;
out vec3 matamb2;
out vec3 matdiff2;
out vec3 matspec2;
out float matshin2;
uniform mat3 NormalMatrix;
uniform mat4 proj;
uniform mat4 view;
uniform mat4 TG;

// Valors per als components que necessitem dels focus de llum
// per exercicis 1,2, 3
//vec3 colFocus = vec3(0.8, 0.8, 0.8);
vec3 llumAmbient = vec3(0.2, 0.2, 0.2);

//vec3 posFocus = vec3(1, 1, 1);  // en SCA inicial
//vec3 posFocus =vec3 (1,0,-1);  //per exercici 4

//aqui passo en SCO
uniform vec3 posFoc;
uniform vec3 colFoc;

void main()
{
    // Calcul de vectors per Lambert i Phong, NormSCO, L en SCO)
    //mat3 NormalMatrix= inverse (transpose (mat3 (view*TG)));
    NormSCO= normalize(NormalMatrix*normal);
    vertexSCO= view*TG* vec4(vertex,1.0);

    gl_Position = proj * view * TG * vec4 (vertex, 1.0);
    //out matambient;
    //out matdiff;
    //out matspec;
    //out matshin;
    matamb2 = matamb;
    matdiff2=matdiff;
    matspec2=matspec;
    matshin2=matshin;

}
