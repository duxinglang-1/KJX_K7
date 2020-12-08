
uniform float u_time;
uniform mat4 v3d_MVPMatrix;

const float c_pointSize = 40.0;

attribute float a_lifetime;
attribute vec3 a_startPosition;
attribute vec3 a_endPosition;

varying float v_lifetime;

void main()
{
	float time = mod(u_time, 1.0);
	gl_Position = v3d_MVPMatrix * vec4(a_startPosition + (time * a_endPosition), 1.0);

	v_lifetime = 1.0 - ( time / a_lifetime );
	v_lifetime = clamp ( v_lifetime, 0.0, 1.0 );
	gl_PointSize = ( v_lifetime * v_lifetime ) * c_pointSize;
}

