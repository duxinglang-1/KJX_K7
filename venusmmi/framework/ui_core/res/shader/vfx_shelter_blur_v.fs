precision mediump float;         
varying vec2 vTexCoord;          
uniform sampler2D uBaseTex;      
uniform sampler2D uFrameTex;     
uniform ivec2 uBaseTexSize;      
uniform float uLevel;            
uniform float uDarkness;         
void main()                      
{                                  
   	float blurSize = uLevel / float(uBaseTexSize.y);  
		float factor[5];
		
		factor[0] =  0.16; 
		factor[1] =  0.22; 
		factor[2] =  0.24; 
		factor[3] =  0.22; 
		factor[4] =  0.16;
		
		for (float i = 0.0; i < 5.0; ++i)
		{				
				gl_FragColor += texture2D(uBaseTex, vec2(vTexCoord.x, vTexCoord.y + (i - 2.0) * 2.0 * blurSize)) * factor[int(i)];
		}		

    gl_FragColor = mix(texture2D(uFrameTex,vTexCoord), gl_FragColor, uLevel);            
    gl_FragColor.rgb *= (1.0 - uLevel * uDarkness);                      
                     
}     
