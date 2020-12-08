

attribute vec4 v3d_Position;
attribute vec3 v3d_Normal;
attribute vec2 v3d_TexCoord;
attribute vec4 v3d_Color;

varying vec4 vColor;
varying vec2 vTexCoord;

uniform vec4 v3d_PositionScale;
uniform vec4 v3d_PositionBias;
uniform vec4 v3d_TexCoordScale;
uniform vec4 v3d_TexCoordBias;
uniform mat4 v3d_MVPMatrix;
uniform mat3 v3d_NormalMatrix;
uniform mat4 uTextureMatrix;
uniform float v3d_Opacity;

void main()                      
{
	gl_Position = v3d_MVPMatrix * (v3d_Position * v3d_PositionScale + v3d_PositionBias); 
	
	vTexCoord = (uTextureMatrix * (vec4(v3d_TexCoord, 0.0, 1.0) * v3d_TexCoordScale + v3d_TexCoordBias)).xy;

	vColor = vec4(v3d_Color.rgb * dot(v3d_NormalMatrix * v3d_Normal, vec3(0.0, 0.0, 1.0)), v3d_Color.a * v3d_Opacity);
}

        