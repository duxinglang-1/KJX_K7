
precision mediump float;

varying vec4 vPosition;
varying vec4 vColor;

uniform vec3 u_FadeDir;
uniform vec3 u_FadeCoef;

void main()
{
	float fading = dot(vPosition.xyz, u_FadeDir);
	fading = clamp(pow(u_FadeCoef.x - u_FadeCoef.y * fading, u_FadeCoef.z), 0.0, 1.0);

    gl_FragColor = vColor;
	gl_FragColor.a *= fading;
}
