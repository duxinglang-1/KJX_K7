precision mediump float;

uniform sampler2D uDiffuseSampler;
uniform float v3d_Opacity;
varying vec2 vTexCoord;

void main()
{
		gl_FragColor = v3d_Opacity * texture2D(uDiffuseSampler, vec2(vTexCoord.x, 1.0 - vTexCoord.y));
}


