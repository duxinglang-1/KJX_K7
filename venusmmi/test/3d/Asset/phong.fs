
precision mediump float;

uniform sampler2D uDiffuseSampler;
uniform float uAmbient;     // ambient intensity
uniform vec3 uDiffuse;      // diffuse intensity
uniform vec3 uSpecular;     // specular intensity
uniform float uShininess;   // specular power

// built-in uniforms

uniform float v3d_Opacity;

// varying

varying vec3 vLight;
varying vec3 vView;
varying vec3 vNormal;
varying vec2 vTexCoord;

void main()
{
    vec3 light = normalize(vLight);
    vec3 view = normalize(vView);
    vec3 normal = normalize(vNormal);

    // texture
    gl_FragColor = texture2D(uDiffuseSampler, vTexCoord);

    // ambient + diffuse
    gl_FragColor.rgb *= uDiffuse * min(1.0, uAmbient + max(0.0, dot(normal, light)));

    // specular
    gl_FragColor.rgb += uSpecular * pow(max(0.0, dot(view, reflect(-light, normal))), uShininess);

    // opacity
    gl_FragColor.a *= v3d_Opacity;
}

