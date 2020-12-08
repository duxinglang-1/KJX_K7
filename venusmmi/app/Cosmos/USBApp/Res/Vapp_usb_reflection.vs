attribute vec2 v3d_Position;
attribute vec2 v3d_TexCoord;
attribute vec4 v3d_Color;

varying vec4 vColor;
varying vec2 vTexCoord;

uniform ivec2 v3d_ViewportSize;
uniform vec2 v3d_Scale;
uniform vec2 v3d_Bias;
uniform ivec2 v3d_BaseTexSize;

void main()
{
    vColor = v3d_Color;
    vTexCoord = v3d_TexCoord;
    vec2 size = vec2(v3d_ViewportSize);
    vec2 pos = v3d_Position * v3d_Scale + v3d_Bias;
    pos.y += float(v3d_BaseTexSize.y);
    gl_Position.x = (pos.x * 2.0 - size.x) / size.x;
    gl_Position.y = (size.y - pos.y * 2.0) / size.y;
    gl_Position.zw = vec2(0.0, 1.0);
}



