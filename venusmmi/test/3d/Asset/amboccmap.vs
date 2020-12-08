
uniform vec3 uLightPos;

// built-in uniforms

uniform vec4 v3d_PositionScale;
uniform vec4 v3d_PositionBias;
uniform vec4 v3d_TexCoordScale;
uniform vec4 v3d_TexCoordBias;
uniform vec4 v3d_TexCoord1Scale;
uniform vec4 v3d_TexCoord1Bias;

uniform mat4 v3d_MVPMatrix;
uniform mat4 v3d_MVMatrix;
uniform mat4 v3d_ViewMatrix;
uniform mat3 v3d_NormalMatrix;

// attribute and varying

attribute vec4 v3d_Position;
attribute vec3 v3d_Normal;
attribute vec2 v3d_TexCoord;
attribute vec2 v3d_TexCoord1;

varying vec3 vLight;
varying vec3 vView;
varying vec3 vNormal;
varying vec2 vTexCoord;
varying vec2 vAmbCoord;

void main()
{
    vec4 position = v3d_Position * v3d_PositionScale + v3d_PositionBias;

    // projective
    gl_Position = v3d_MVPMatrix * position;
    vTexCoord = v3d_TexCoord * v3d_TexCoordScale.xy + v3d_TexCoordBias.xy;
    vAmbCoord = v3d_TexCoord1 * v3d_TexCoord1Scale.xy + v3d_TexCoord1Bias.xy;

    // lighting in world space
    vec3 vPos = (v3d_MVMatrix * position).xyz;
    vLight = (v3d_ViewMatrix * vec4(uLightPos, 1.0)).xyz;
    vLight = vLight - vPos;
    vView = -vPos;
    vNormal = normalize(v3d_NormalMatrix * v3d_Normal);
}

