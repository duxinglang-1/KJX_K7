// attributes
attribute vec2 v3d_Position;
attribute vec4 v3d_Color;

// varyings
varying vec2 vTexCoord;
varying vec4 vColor;
varying vec4 vPos;

// built-in uniforms
uniform vec2 v3d_Scale;
uniform vec2 v3d_Bias;
uniform ivec2 v3d_TessellationLevel;
uniform ivec2 v3d_ViewportSize;

// custom uniforms
uniform float A;
uniform float theta;
uniform float rho;

// const
float pi = 3.14159265359;
float fovy = pi / 6.0;
float n = 10.0;
float f = 2000.0;

void main()
{
	// texture coordiante
	vTexCoord = v3d_Position / vec2(v3d_TessellationLevel);

	vec3 pos = vec3(v3d_Position * v3d_Scale + v3d_Bias, 1.0);

	// deform                       
	float sin_theta = sin(theta);
	float cos_theta = cos(theta);
	float R = sqrt(pos.x * pos.x + (pos.y - A) * (pos.y - A));
	float r = R * sin_theta;
	float beta = asin(pos.x / R) / sin_theta;
	float sin_beta = sin(beta);
	float cos_beta = cos(beta);
	pos.x  = r * sin(beta);
	pos.y  = R + A - r * (1.0 - cos_beta) * sin_theta;
	pos.z  = r * (1.0 - cos_beta) * cos_theta;

	float sin_rho = sin(rho);
	float cos_rho = cos(rho);
	gl_Position.x  = (pos.x * cos_rho - pos.z * sin_rho);
	gl_Position.y  = pos.y;
	gl_Position.z  = (pos.x * sin_rho + pos.z * cos_rho);
	gl_Position.w  = 1.0;
	
	// 3d transform
	vec2 size = vec2(v3d_ViewportSize);
	float h = tan(fovy / 2.0);
	float w = h * size.x / size.y;
	float d = f - n;
	mat4 proj = mat4(1.0);
	proj[0][0] = 1.0 / w;
	proj[1][1] = 1.0 / h;
	proj[2][2] = -(n + f) / d;
	proj[3][3] = 0.0;
	proj[2][3] = -1.0;
	proj[3][2] = -2.0*n*f / d;
	mat4 view = mat4(1.0);
	view[3][0] = -size.x / 2.0;
	view[3][1] = -size.y / 2.0;
	view[3][2] = -size.y / 2.0 / h;
	gl_Position = proj * view * gl_Position;

	// lightting 
	float l = -sin_beta * sin_rho * cos_theta + cos_rho * (1.0 + (cos_beta - 1.0) * cos_theta * cos_theta);
	vColor = vec4(clamp(abs(l) * 3.0, 0.5, 1.0));
}

