// input of vertex shader
attribute vec2 v3d_Position;
attribute vec2 v3d_TexCoord;
attribute vec4 v3d_Color;

// output of vertex shader
varying vec4 vColor;
varying vec2 vTexCoord;

// built-in uniforms
uniform vec2 v3d_Scale;
uniform vec2 v3d_Bias;
uniform ivec2 v3d_ViewportSize;
uniform ivec2 v3d_Anchor;
uniform mat4 v3d_ScreenRotateMatrix;

// uniforms
uniform float u_Rotation;
uniform float u_Scale;


void main()
{
    vColor = v3d_Color;
    vTexCoord = v3d_TexCoord;

    vec2 size = vec2(v3d_ViewportSize);
    vec2 pos = v3d_Position * v3d_Scale + v3d_Bias;

    pos -= vec2(v3d_Anchor);

    vec2 pos1 = pos;
    pos1.x = u_Scale * (cos(u_Rotation) * pos.x - sin(u_Rotation) * pos.y);
    pos1.y = u_Scale * (sin(u_Rotation) * pos.x + cos(u_Rotation) * pos.y);
    pos1 += vec2(v3d_Anchor);

    // to clip space
    gl_Position.x = (pos1.x * 2.0 - size.x) / size.x;
    gl_Position.y = (size.y - pos1.y * 2.0) / size.y;
    gl_Position.zw = vec2(0.0, 1.0);

    gl_Position = v3d_ScreenRotateMatrix * gl_Position;
}

