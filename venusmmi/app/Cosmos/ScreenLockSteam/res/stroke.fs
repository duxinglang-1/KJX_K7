precision mediump float;
//precision highp sampler2D;

uniform sampler2D uTexture;
uniform sampler2D uTextureLevel;
uniform int uBackground;
uniform float uConstAlpha;
uniform int uNeedsFogUp;
varying vec2 vTexCoord;

void main() 
{                                          
    gl_FragColor = texture2D(uTexture, vTexCoord);         
    //gl_FragColor.rgb = vec3(1.0,1.0,1.0);         
    if(uBackground==1 && uNeedsFogUp==1)
    	gl_FragColor.g = clamp(gl_FragColor.g - uConstAlpha - texture2D(uTextureLevel, vec2(vTexCoord.x,1.0-vTexCoord.y)).g*0.01,0.0,1.0);
    	
    //gl_FragColor = texture2D(uTexture, vec2(vTexCoord.x,vTexCoord.x));                     
    //gl_FragColor = vec4(vTexCoord.y,vTexCoord.y,vTexCoord.y,1);                     
    //gl_FragColor = vec4(1.0f,0.0f,0.0f,1.0f);                     
    //gl_FragColor = vColor;                     
}                                         
