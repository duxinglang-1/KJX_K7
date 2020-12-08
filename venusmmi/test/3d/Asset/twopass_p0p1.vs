
// built-in uniforms

uniform vec4 v3d_PositionScale;
uniform vec4 v3d_PositionBias;
uniform vec4 v3d_TexCoordScale;
uniform vec4 v3d_TexCoordBias;

uniform mat4 v3d_MVPMatrix;

// attribute and varying

attribute vec4 v3d_Position;
attribute vec2 v3d_TexCoord;

varying vec2 vTexCoord;

void main()
{
    vec4 position = v3d_Position * v3d_PositionScale + v3d_PositionBias;

    // projective
    gl_Position = v3d_MVPMatrix * position;
    vTexCoord = v3d_TexCoord * v3d_TexCoordScale.xy + v3d_TexCoordBias.xy;
}

