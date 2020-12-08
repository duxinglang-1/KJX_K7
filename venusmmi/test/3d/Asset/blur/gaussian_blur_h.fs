precision mediump float;
varying vec4 vColor;
varying vec2 vTexCoord;
uniform sampler2D v3d_BaseTex;
uniform ivec2 v3d_BaseTexSize;
uniform float v3d_FpeUser0;
void main()
{
	float blurSize = 1.0 * v3d_FpeUser0 / float(v3d_BaseTexSize.x);
	gl_FragColor = texture2D(v3d_BaseTex, vec2(vTexCoord.x - 4.0*blurSize, vTexCoord.y)) * 0.05;
	gl_FragColor += texture2D(v3d_BaseTex, vec2(vTexCoord.x - 3.0*blurSize, vTexCoord.y)) * 0.09;
	gl_FragColor += texture2D(v3d_BaseTex, vec2(vTexCoord.x - 2.0*blurSize, vTexCoord.y)) * 0.12;
	gl_FragColor += texture2D(v3d_BaseTex, vec2(vTexCoord.x - blurSize, vTexCoord.y)) * 0.15;
	gl_FragColor += texture2D(v3d_BaseTex, vec2(vTexCoord.x, vTexCoord.y)) * 0.16;
	gl_FragColor += texture2D(v3d_BaseTex, vec2(vTexCoord.x + blurSize, vTexCoord.y)) * 0.15;
	gl_FragColor += texture2D(v3d_BaseTex, vec2(vTexCoord.x + 2.0*blurSize, vTexCoord.y)) * 0.12;
	gl_FragColor += texture2D(v3d_BaseTex, vec2(vTexCoord.x + 3.0*blurSize, vTexCoord.y)) * 0.09;
	gl_FragColor += texture2D(v3d_BaseTex, vec2(vTexCoord.x + 4.0*blurSize, vTexCoord.y)) * 0.05;
	gl_FragColor *= vColor;
}
               