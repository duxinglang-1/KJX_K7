
uniform vec3 uLightPos;

// built-in uniforms

uniform vec4 v3d_PositionScale;
uniform vec4 v3d_PositionBias;
uniform vec4 v3d_TexCoordScale;
uniform vec4 v3d_TexCoordBias;

uniform mat4 v3d_MVPMatrix;
uniform mat4 v3d_MVMatrix;
uniform mat4 v3d_ViewMatrix;
uniform mat3 v3d_NormalMatrix;

// attribute and varying

attribute vec4 v3d_Position;
attribute vec3 v3d_Normal;
attribute vec2 v3d_TexCoord;
attribute vec3 v3d_Tangent;

varying vec2 vTexCoord;
varying vec3 vLight;
varying vec3 vView;

void main()
{
    vec4 position = v3d_Position * v3d_PositionScale + v3d_PositionBias;

    // projective
    gl_Position = v3d_MVPMatrix * position;
    vTexCoord = v3d_TexCoord * v3d_TexCoordScale.xy + v3d_TexCoordBias.xy;

    // lighting in world space
    vec3 vPos = (v3d_MVMatrix * position).xyz;
    vLight = (v3d_ViewMatrix * vec4(uLightPos, 1.0)).xyz;
    vec3 binormal = cross(v3d_Normal, v3d_Tangent);
    //vec3 normal = cross(v3d_Tangent, v3d_Binormal);
    //vec3 tangent = cross(v3d_Binormal, v3d_Normal);
    mat3 viewToTex = v3d_NormalMatrix * mat3(   // FIXME verify this tangent space matrix
        v3d_Tangent,
        binormal,
        v3d_Normal
    );
    /*
    mat3 viewToTex = v3d_NormalMatrix, mat3(
        binormal,   // Z-UP? TC Y-UP?
        v3d_Tangent,
        v3d_Normal
    );
    */
    vLight = (vLight - vPos) * viewToTex;
    vView = -vPos * viewToTex;
}

