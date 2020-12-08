precision mediump float;

varying vec4 vColor;
varying vec2 vTexCoord;

uniform sampler2D v3d_BaseTex;

void main()
{
	gl_FragColor = vColor * texture2D(v3d_BaseTex, vTexCoord);
}

