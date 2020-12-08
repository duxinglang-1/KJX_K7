precision mediump float;
varying vec4 vColor;
varying vec2 vTexCoord;
uniform sampler2D baseTex;
uniform ivec2 v3d_BaseTexSize;
uniform float v3d_FpeUser0;


void main()
{
	float blurSize = 1.0 * v3d_FpeUser0 / float(v3d_BaseTexSize.x);
	float factor[5];	
	factor[0] =  0.16; 
	factor[1] =  0.22; 
	factor[2] =  0.24; 
	factor[3] =  0.22; 
	factor[4] =  0.16;
	
	for (float i = 0.0; i < 5.0; ++i)
	{			
			gl_FragColor += texture2D(baseTex, vec2(vTexCoord.x + (i - 2.0) * 2.0 * blurSize, vTexCoord.y)) * factor[int(i)];
	}		
}
