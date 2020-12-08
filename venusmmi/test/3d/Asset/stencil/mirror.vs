
attribute vec4 v3d_Position;
attribute vec3 v3d_Normal;
attribute vec4 v3d_Color;

varying vec4 vPosition;
varying vec4 vColor;

uniform vec4 v3d_PositionScale;
uniform vec4 v3d_PositionBias;
uniform mat4 v3d_ModelMatrix;
uniform mat4 v3d_VPMatrix;
uniform mat3 v3d_NormalMatrix;
uniform float v3d_Opacity;

uniform vec3 u_ReflNormal;

void main()
{
	vPosition = v3d_ModelMatrix * (v3d_Position * v3d_PositionScale + v3d_PositionBias);
	vPosition = vec4(reflect(vPosition.xyz, u_ReflNormal), vPosition.w);
    gl_Position = v3d_VPMatrix * vPosition;
    vColor = vec4(vec3(dot(normalize(v3d_NormalMatrix * v3d_Normal), vec3(0.0, 0.0, 1.0))), v3d_Opacity);
}
