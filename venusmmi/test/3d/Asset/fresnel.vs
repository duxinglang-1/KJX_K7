
// built-in uniforms

uniform vec4 v3d_PositionScale;
uniform vec4 v3d_PositionBias;

uniform mat4 v3d_MVPMatrix;
uniform mat4 v3d_MVMatrix;
uniform mat3 v3d_NormalMatrix;

// attribute and varying

attribute vec4 v3d_Position;
attribute vec3 v3d_Normal;

varying vec3 vView;
varying vec3 vNormal;

void main()
{
    vec4 position = v3d_Position * v3d_PositionScale + v3d_PositionBias;

    // projective
    gl_Position = v3d_MVPMatrix * position;

    // environment in view space
    vec3 vPos = (v3d_MVMatrix * position).xyz;
    vView = -vPos;
    vNormal = normalize(v3d_NormalMatrix * v3d_Normal);
}

