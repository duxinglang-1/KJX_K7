precision mediump float;

varying vec4 vColor;
varying vec2 vTexCoord;

uniform sampler2D v3d_BaseTex;
uniform sampler2D blingTex;
uniform ivec2 v3d_BaseTexSize;

uniform float offset;
uniform float shear;
uniform float blingwidth;
uniform float bright;


void main()
{	
		
	float pos;	
	
	if (shear > 0.0)
	{
		pos = offset * ( float(v3d_BaseTexSize.y) + blingwidth + shear ) + float(vTexCoord.x) * shear - blingwidth - shear ;			
	}
	else
	{
		pos = offset * ( float(v3d_BaseTexSize.y) + blingwidth - shear ) + float(vTexCoord.x) * shear - blingwidth ;			
	}	
		
	float length = vTexCoord.y * float(v3d_BaseTexSize.y) - pos;	
	gl_FragColor = texture2D(v3d_BaseTex, vTexCoord);
	
	if ( length > 0.0 && length <= blingwidth )
	{				
	  vec3 color = bright * 0.996078 * texture2D(blingTex, vec2(0.0, length / blingwidth)).rgb;			  	  	  
	  gl_FragColor.rgb *= (vec3(1.0) + color);					
	}
	

}
               