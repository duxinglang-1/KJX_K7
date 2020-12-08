uniform ivec2 uViewportSize;  
uniform ivec2 uFrameAnchor; 
varying vec2 vTexCoord;     
attribute vec2 aTexCoord;   
attribute vec4 aPosition;   
void main()                 
{                           
   gl_Position = aPosition; 
   vTexCoord = aTexCoord;   
   vec2 size = vec2(uViewportSize); 
   vec2 anchor = vec2(uFrameAnchor);
   gl_Position.x = ((gl_Position.x - anchor.x)*2.0 - size.x) / size.x;     
   gl_Position.y = ((gl_Position.y - anchor.y)*2.0 - size.y) / size.y;	   
}                                            
  