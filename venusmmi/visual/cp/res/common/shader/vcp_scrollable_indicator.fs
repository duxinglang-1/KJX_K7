precision mediump float;

// built-in uniforms
uniform sampler2D v3d_BaseTex;

uniform vec3 color;

varying vec2 vTexCoord;



void main()
{
	gl_FragColor.rgb = color;
	gl_FragColor.a = texture2D(v3d_BaseTex, vec2(vTexCoord.x , 1.0 - vTexCoord.y)).a;	
	gl_FragColor.rgb *= gl_FragColor.a; //PARGB when using v3d_BaseTex
	
}
