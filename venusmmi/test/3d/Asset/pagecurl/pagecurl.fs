precision mediump float;

// varyings
varying vec2 vTexCoord;
varying vec4 vColor;

// built-in uniforms
uniform sampler2D v3d_BaseTex;

void main()
{
	gl_FragColor = vColor * texture2D(v3d_BaseTex, vTexCoord);
}

