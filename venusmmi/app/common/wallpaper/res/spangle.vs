uniform vec2 uFrameSize;
uniform vec2 uFrameAnchor;
attribute vec3 aPosition;
attribute vec2 aTexCoord;
varying vec2 vTexCoord;
void main()
{
   vTexCoord = aTexCoord;
   gl_Position.x = aPosition.x;
   gl_Position.y = aPosition.y;
   gl_Position.z = 0.0;
   gl_Position.w = 1.0;
}