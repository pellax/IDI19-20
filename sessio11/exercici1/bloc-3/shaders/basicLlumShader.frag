#version 330 core

in vec3 fcolor;
out vec4 FragColor;
in vec3 NormSCO;
in vec4 vertexSCO;
in vec3 matamb2;
in vec3 matdiff2;
in vec3 matspec2;
in float matshin2;
uniform vec3 colFoc;
uniform vec3 posFoc;
vec3 llumAmbient = vec3(0.2, 0.2, 0.2);
vec3 Lambert (vec3 NormSCO, vec3 L) 
{
    // S'assumeix que els vectors que es reben com a paràmetres estan normalitzats

    // Inicialitzem color a component ambient
    vec3 colRes = llumAmbient * matamb2;

    // Afegim component difusa, si n'hi ha
    if (dot (L, NormSCO) > 0)
     // colRes = colRes + colFocus * matdiff * dot (L, NormSCO);
    	colRes = colRes + colFoc * matdiff2 * dot(L, NormSCO);
	return (colRes);
}
vec3 Phong (vec3 NormSCO, vec3 L, vec4 vertSCO) 
{
    // Els vectors estan normalitzats

    // Inicialitzem color a Lambert
    vec3 colRes = Lambert (NormSCO, L);

    // Calculem R i V
    if ((dot(NormSCO,L) < 0) || (matshin2 == 0))
      return colRes;  // no hi ha component especular

    vec3 R = reflect(-L, NormSCO); // equival a: 2.0*dot(NormSCO,L)*NormSCO - L;
    vec3 V = normalize(-vertSCO.xyz); // perquè la càmera està a (0,0,0) en SCO

    if (dot(R, V) < 0)
      return colRes;  // no hi ha component especular
    
    float shine = pow(max(0.0, dot(R, V)), matshin2);
    return(colRes + matspec2 * colFoc * shine);  
 // return (colRes + matspec * colFocus * shine); 
}
void main()

{	vec3 NormSCO2 = normalize(NormSCO);
 //   vec4 vertexSCO2 = normalize(vertexSCO);
    vec4 focusSCO = vec4(posFoc,1.0); 
   // vec4 focusSCO = vec4(posFoc,1.0);
    vec3 LSCO = normalize(focusSCO.xyz-vertexSCO.xyz);
    vec3 fcolor2 = Phong(NormSCO2,LSCO,normalize(vertexSCO));
	FragColor = vec4(fcolor2,1);	
}
