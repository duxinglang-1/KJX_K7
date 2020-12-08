attribute vec2 aPosition;
uniform float bgOffsetX;
uniform float bgWidth;
varying vec2 v_texCoord;
void main()
{
    // we expect aPosition forms a rectange from (-1, -1) to (1, 1)
    gl_Position = vec4(aPosition, 0, 1);
    v_texCoord = aPosition;
    v_texCoord += vec2(1.0, 1.0);
    v_texCoord.x *= bgWidth / 2.0;
    v_texCoord.y *= 0.5;
    v_texCoord.x -= bgOffsetX;
    v_texCoord.y = 1.0 - v_texCoord.y;
}
