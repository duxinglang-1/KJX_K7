
attribute vec4 v3d_Position;
attribute vec3 v3d_Normal;
attribute vec4 v3d_Color;

varying vec4 vColor;
varying vec3 vNormal;
varying vec3 vLight;
varying vec3 vPosition;

uniform vec4 v3d_PositionScale;
uniform vec4 v3d_PositionBias;

uniform mat4 v3d_ProjectMatrix;
uniform mat4 v3d_MVMatrix;
uniform mat3 v3d_NormalMatrix;
uniform vec3 u_LightPos;
uniform vec4 u_LightColor;
uniform float u_LightIntensity;

void main()
{
	gl_Position = v3d_MVMatrix * (v3d_Position * v3d_PositionScale + v3d_PositionBias);
	vPosition = gl_Position.xyz;
	gl_Position = v3d_ProjectMatrix * gl_Position;

	vNormal = v3d_NormalMatrix * v3d_Normal;
	vLight = normalize(u_LightPos - vPosition);
	vColor = v3d_Color * u_LightColor * u_LightIntensity;
}



