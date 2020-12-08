
precision mediump float;

varying vec4 vColor;
varying vec3 vNormal;
varying vec3 vLight;
varying vec3 vPosition;

const float specularPower = 10.0;

void main()
{
	vec3 normal = normalize(vNormal);
	vec3 light = normalize(vLight);
	float diffuse = max(0.0, dot(light, normal));
	vec3 reflect = reflect(-light, normal);
	float specular = max(0.0, dot(normalize(-vPosition), reflect));
	gl_FragColor = vColor;
	gl_FragColor.rgb *= (diffuse + pow(specular, specularPower));
}

