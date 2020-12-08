precision mediump float;           
varying vec2 vTexCoord;            
uniform sampler2D uTexture;        
void main()                        
{                                  
   gl_FragColor = texture2D(uTexture, vec2(vTexCoord.x,1.0-vTexCoord.y)); 
   
}                          

