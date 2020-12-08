
attribute vec4 v3d_Position;

uniform vec4 v3d_PositionScale;
uniform vec4 v3d_PositionBias;
uniform mat4 v3d_ModelMatrix;
uniform mat4 v3d_VPMatrix;
uniform mat4 v3d_ScreenRotateMatrix;

uniform vec3 u_LightPos;

// floor Z-value
uniform float u_floorZ;

void main()
{
	vec3 l = u_LightPos;
	vec3 n = vec3(0.0, 0.0, 1.0);
	float d = u_floorZ;
	float nl = dot(n, l);
	mat4 ShadowMatrix;
	ShadowMatrix[0] = vec4(nl+d-l.x*n.x,     -l.y*n.x,     -l.z*n.x, -n.x);
	ShadowMatrix[1] = vec4(    -l.x*n.y, nl+d-l.y*n.y,     -l.z*n.y, -n.y);
	ShadowMatrix[2] = vec4(    -l.x*n.z,     -l.y*n.z, nl+d-l.z*n.z, -n.z);
	ShadowMatrix[3] = vec4(      -l.x*d,       -l.y*d,       -l.z*d,   nl);
	gl_Position = v3d_VPMatrix * ShadowMatrix * v3d_ModelMatrix * (v3d_Position * v3d_PositionScale + v3d_PositionBias);
	gl_Position = v3d_ScreenRotateMatrix * gl_Position;
}


