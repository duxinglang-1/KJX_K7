// attribute
attribute vec2 aPosition;

void main()
{
    // we expect aPosition forms a rectange from (-1, -1) to (1, 1)
    gl_Position = vec4(aPosition, 0, 1);
}
