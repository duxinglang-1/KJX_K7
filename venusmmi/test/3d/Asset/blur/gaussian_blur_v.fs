precision mediump float;
varying vec4 vColor;
varying vec2 vTexCoord;
uniform sampler2D baseTex;
uniform ivec2 v3d_BaseTexSize;
uniform float v3d_FpeUser0;
void main()
{
	float blurSize = 1.0 * v3d_FpeUser0 / float(v3d_BaseTexSize.y);
	gl_FragColor = texture2D(baseTex, vec2(vTexCoord.x, vTexCoord.y - 4.0*blurSize)) * 0.05;
	gl_FragColor += texture2D(baseTex, vec2(vTexCoord.x, vTexCoord.y - 3.0*blurSize)) * 0.09;
	gl_FragColor += texture2D(baseTex, vec2(vTexCoord.x, vTexCoord.y - 2.0*blurSize)) * 0.12;
	gl_FragColor += texture2D(baseTex, vec2(vTexCoord.x, vTexCoord.y - blurSize)) * 0.15;
	gl_FragColor += texture2D(baseTex, vec2(vTexCoord.x, vTexCoord.y)) * 0.16;
	gl_FragColor += texture2D(baseTex, vec2(vTexCoord.x, vTexCoord.y + blurSize)) * 0.15;
	gl_FragColor += texture2D(baseTex, vec2(vTexCoord.x, vTexCoord.y + 2.0*blurSize)) * 0.12;
	gl_FragColor += texture2D(baseTex, vec2(vTexCoord.x, vTexCoord.y + 3.0*blurSize)) * 0.09;
	gl_FragColor += texture2D(baseTex, vec2(vTexCoord.x, vTexCoord.y + 4.0*blurSize)) * 0.05;
}


