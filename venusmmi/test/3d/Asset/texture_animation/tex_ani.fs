
precision mediump float;

varying vec4 vColor;
varying vec2 vTexCoord;

uniform sampler2D tex;

void main()
{
	gl_FragColor = vColor * texture2D(tex, vTexCoord);
}

