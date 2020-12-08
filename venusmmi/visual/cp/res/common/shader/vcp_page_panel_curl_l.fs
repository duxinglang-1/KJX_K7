precision mediump float;

// varyings
varying vec2 vTexCoord;
varying vec3 vNormal;
varying vec3 vLightDir;

uniform sampler2D baseTex;


const float amb = 0.5; 
const float diff = 0.5; 

void main()
{
  
 	vec3 light = normalize(vLightDir); 
 	vec3 normal = normalize(vNormal);
 	float diffusefract = max( abs(dot(light,normal)) , 0.0); 

	
	gl_FragColor = texture2D(baseTex, vec2(vTexCoord.x, 1.0 - vTexCoord.y/2.0 ));

	gl_FragColor.rgb *= (amb + diff * diffusefract);	
	
	
}

