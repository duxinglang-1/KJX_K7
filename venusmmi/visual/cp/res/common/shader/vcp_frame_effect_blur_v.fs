precision mediump float;
varying vec4 vColor;
varying vec2 vTexCoord;
uniform sampler2D baseTex;
uniform sampler2D frameTex;

uniform ivec2 v3d_BaseTexSize;
uniform float v3d_FpeUser0;
uniform float darkness;

void main()
{
		float blurSize = 1.0 * v3d_FpeUser0 / float(v3d_BaseTexSize.y);				
				
		float factor[5];
		
		factor[0] =  0.16; 
		factor[1] =  0.22; 
		factor[2] =  0.24; 
		factor[3] =  0.22; 
		factor[4] =  0.16;
		
		for (float i = 0.0; i < 5.0; ++i)
		{				
				gl_FragColor += texture2D(baseTex, vec2(vTexCoord.x, vTexCoord.y + (i - 2.0) * 2.0 * blurSize)) * factor[int(i)];
		}		

		gl_FragColor = mix(texture2D(frameTex,vTexCoord), gl_FragColor, v3d_FpeUser0);	
		gl_FragColor.rgb *= (1.0 - v3d_FpeUser0* darkness);	
}

