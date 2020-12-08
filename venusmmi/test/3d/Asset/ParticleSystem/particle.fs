
precision mediump float;

uniform vec4 u_color;
uniform sampler2D s_texture;

varying float v_lifetime;

void main()
{
	gl_FragColor = u_color * vec4(texture2D( s_texture, gl_PointCoord ).rgb, 1.0);
	gl_FragColor.a *= v_lifetime;
}

