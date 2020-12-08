precision mediump float;           
varying vec2 vTexCoord;            
uniform sampler2D uTexture;        

uniform sampler2D uTextureStroke;
uniform int uIsInit;  
void main()                        
{                                  
   gl_FragColor = texture2D(uTexture, vec2(vTexCoord.x,1.0-vTexCoord.y)); 
   if(uIsInit == 1)
   {
      gl_FragColor.a = 0.9;
   }
   else
   {
      gl_FragColor.a = clamp(0.9 - texture2D(uTextureStroke, vTexCoord).g,0.0,1.0);
   }
}                          

