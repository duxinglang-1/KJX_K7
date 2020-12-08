
precision mediump float;

uniform sampler2D uDiffuseSampler;
uniform sampler2D uBumpSampler;
uniform float uBumpHeight;  // bump height
uniform float uAmbient;     // ambient intensity
uniform vec3 uDiffuse;      // diffuse intensity
uniform vec3 uSpecular;     // specular intensity
uniform float uShininess;   // specular power

// built-in uniforms

uniform float v3d_Opacity;

// varying

varying vec2 vTexCoord;
varying vec3 vLight;
varying vec3 vView;

void main()
{
    vec3 light = normalize(vLight);
    vec3 view = normalize(vView);
    vec3 normal = texture2D(uBumpSampler, vTexCoord).xyz * 2.0 - 1.0;
    normal = normalize(normal * vec3(-uBumpHeight, uBumpHeight, 1.0));

    // texture
    gl_FragColor = texture2D(uDiffuseSampler, vTexCoord);

    // ambient + diffuse
    float diffuse = dot(normal, light);
    gl_FragColor.rgb *= uDiffuse * min(1.0, uAmbient + max(0.0, diffuse));

    // specular
    float specular = pow(max(0.0, dot(view, reflect(-light, normal))), uShininess);
    // if not back-light. light.z == dot(face_normal, light)
    gl_FragColor.rgb += uSpecular * specular * float(diffuse > -light.z);

    // opacity
    gl_FragColor.a *= v3d_Opacity;
}

