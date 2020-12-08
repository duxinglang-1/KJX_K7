// attribute
attribute vec2 a_vertexScreenPos;

varying vec2 v_texCoord;

void main()
{
    // we expect a_vertexScreenPos forms a rectange from (-1, -1) to (1, 1)
    gl_Position = vec4(a_vertexScreenPos, 0, 1);
    // convert the position to texture coordinate
    v_texCoord = (a_vertexScreenPos / 2.0);
    v_texCoord.x += 0.5;
    v_texCoord.y += 0.5;
}
