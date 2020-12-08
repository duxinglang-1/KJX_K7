
precision mediump float;

uniform sampler2D uDiffuseSampler;
uniform vec4 uDiffuse;      // diffuse color
uniform float uAmbient;     // ambient intensity
uniform bool uSpecular;     // specular enable
uniform float uShininess;   // specular power

// built-in uniforms

uniform float v3d_Opacity;

// varying

varying vec3 vLight;
varying vec3 vView;
varying vec3 vNormal;

void main()
{
    vec3 light = normalize(vLight);
    vec3 view = normalize(vView);
    vec3 normal = normalize(vNormal);

    // color
    gl_FragColor = uDiffuse;

    // ambient + diffuse
    gl_FragColor.rgb *= min(1.0, uAmbient + max(0.0, dot(normal, light)));

    // specular
    gl_FragColor.rgb += float(uSpecular) * pow(max(0.0, dot(view, reflect(-light, normal))), uShininess);

    // opacity
    gl_FragColor.a *= v3d_Opacity;
}

