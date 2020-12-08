// attributes
attribute vec2 v3d_Position;

// varyings
varying vec2 vTexCoord;
varying vec3 vNormal;
varying vec3 vLightDir;


// built-in uniforms
uniform vec2 v3d_Scale;
uniform vec2 v3d_Bias;
uniform ivec2 v3d_TessellationLevel;
uniform ivec2 v3d_ViewportSize;
uniform ivec2 v3d_Anchor;
uniform ivec2 v3d_BaseTexSize;
uniform mat4 v3d_ScreenRotateMatrix;

// custom uniforms
uniform float theta;
uniform float rho;

const float A =-50.0;
const float pi = 3.14159265359;

void main()
{
	// 3d transform
	vec2 size = vec2(v3d_ViewportSize);
	
	float imx = float(v3d_BaseTexSize.x);
  float imy = float(v3d_BaseTexSize.y);

	// texture coordiante
	vTexCoord = v3d_Position / vec2(v3d_TessellationLevel);

	vec3 pos = vec3(v3d_Position * v3d_Scale + v3d_Bias, 0.0);
	pos.y = size.y - pos.y; //flip model
	
	vec2 anchor = vec2(float(v3d_Anchor.x) + imx, size.y - float(v3d_Anchor.y) - imy);	
	pos.xy -= anchor; 


	float sin_theta = sin(theta);
	float cos_theta = cos(theta);
	
	float AA;
	float R;	
	float r;
	float beta;
	float sin_beta;
	float cos_beta;
	vec3 center;
	vec3 u;
	
	vec3 lightpos = vec3(0.0,0.0,700);
	

	AA = -A;
	R = sqrt((pos.x-AA) * (pos.x-AA) + (pos.y) * (pos.y));	
	r = R * sin_theta;
	beta = asin((pos.y) / R) / sin_theta;
	sin_beta = sin(beta);
	cos_beta = cos(beta);
	pos.y  = r * sin_beta ;
	pos.x  = AA - R + r * (1.0 - cos_beta) * sin_theta;
	pos.z  = r * (1.0 - cos_beta) * cos_theta;
	
	
	u = normalize(vec3(-R + r*sin_theta,0.0,r*cos_theta));
	center = R / cos_theta * u + vec3(AA, 0, 0.0);
	
	float sin_rho = sin(-rho);
	float cos_rho = cos(-rho);	
	
	pos.y  = (pos.y * cos_rho + pos.z * sin_rho);	
	pos.z  = (-pos.y * sin_rho + pos.z * cos_rho);
	center.y  = (center.y * cos_rho + center.z * sin_rho);	
	center.z  = (-center.y * sin_rho + center.z * cos_rho);		

	lightpos.xy = vec2(0.0, imy/2.0); 	
	vLightDir = lightpos - pos; 
	
	if(cos_theta<=0.001)
  		vNormal = vec3(0,0,1);
  else  	
  		vNormal = center - pos ;
	
	pos.xy += anchor;		
	gl_Position = vec4(pos,1.0);
	
	gl_Position.x = (pos.x * 2.0 - size.x) / size.x;
  gl_Position.y = (pos.y * 2.0 - size.y) / size.y;
  gl_Position.z = - (pos.z) / size.y;
	
	gl_Position = v3d_ScreenRotateMatrix * gl_Position;
}
