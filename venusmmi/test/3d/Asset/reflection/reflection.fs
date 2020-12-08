
precision mediump float;

varying vec3 vReflect;

uniform samplerCube u_CubeTex;

void main()
{
	gl_FragColor = textureCube(u_CubeTex, normalize(vReflect));
}
