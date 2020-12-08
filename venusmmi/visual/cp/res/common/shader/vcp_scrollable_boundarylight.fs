precision mediump float;

// built-in uniforms
uniform float v3d_Opacity;


uniform sampler2D baseTex;
uniform int direction;


varying vec2 vTexCoord;
varying vec4 vColor;


void main()
{
	
	if(vColor.r == 0.0 && vColor.g == 0.0 && vColor.b == 0.0 && vColor.a == 0.0)
	{
		if(direction == 1)				
			gl_FragColor = texture2D(baseTex, vec2( vTexCoord.y, 1.0 - vTexCoord.x));
		else if(direction == 2)
			gl_FragColor = texture2D(baseTex, vec2( vTexCoord.x, 1.0 - vTexCoord.y));		
		else if(direction == 3)
			gl_FragColor = texture2D(baseTex, vec2( vTexCoord.y, vTexCoord.x));
		else		
			gl_FragColor = texture2D(baseTex, vec2( vTexCoord.x, vTexCoord.y));	
		
		gl_FragColor.a *= v3d_Opacity;		
	}
	else
	{
		gl_FragColor = vColor;
	
		if(direction == 1)
			gl_FragColor.a = v3d_Opacity * texture2D(baseTex, vec2(vTexCoord.y , 1.0 - vTexCoord.x)).a;
		else if(direction == 2)
			gl_FragColor.a = v3d_Opacity * texture2D(baseTex, vec2(vTexCoord.x , 1.0 - vTexCoord.y)).a;
		else if(direction == 3)
			gl_FragColor.a = v3d_Opacity * texture2D(baseTex, vec2(vTexCoord.y , vTexCoord.x)).a;
		else
			gl_FragColor.a = v3d_Opacity *texture2D(baseTex, vec2(vTexCoord.x , vTexCoord.y)).a;	
	}
}
