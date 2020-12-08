
attribute vec4 v3d_Position;
attribute vec3 v3d_Normal;

uniform vec4 v3d_PositionScale;
uniform vec4 v3d_PositionBias;

uniform mat4 v3d_MVPMatrix;
uniform mat4 v3d_MVMatrix;
uniform mat3 v3d_NormalMatrix;

varying vec3 vReflect;

void main()
{
	vec4 pos = v3d_Position * v3d_PositionScale + v3d_PositionBias;
	gl_Position = v3d_MVPMatrix * pos;
	
	// to view space
	pos = v3d_MVMatrix * pos;
	vec3 normal = v3d_NormalMatrix * v3d_Normal;
	vReflect = reflect(normalize(pos.xyz), normalize(normal));
}

