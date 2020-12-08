
precision mediump float;

uniform samplerCube uEnvSampler;
uniform float uETA;     // ratio of refractive indices
uniform float uRC;      // constant reflection coefficient
uniform vec4 uGlass;    // glass color and opacity

// built-in uniforms

uniform float v3d_Opacity;

// varying

varying vec3 vView;
varying vec3 vNormal;

vec2 windowglass(vec3 I, vec3 N, float eta, float rc)
{
    // front-and-back reflective and see-through refractive coefficients
    float cosi = dot(N, I);
    if (cosi > 0.0)     // reverse side
    {
        N = -N;
        cosi = -cosi;
    }
    float cost2 = 1.0 - eta * eta * (1.0 - cosi * cosi);
    vec2 rt = vec2(1.0, 0.0);
    if (rc < 1.0 && cost2 > 0.0)    // not total reflection
    {
        float cost = sqrt(cost2);
        float rs = (eta * cosi + cost) / (eta * cosi - cost);
        rs *= rs;
        float rp = (eta * cost + cosi) / (eta * cost - cosi);
        rp *= rp;

        float r = min((rs + rp) / 2.0 + rc, 1.0);
        float t2 = 1.0 - r;
        t2 *= t2;
        rt = vec2(r + r * t2, t2);
    }
    return rt;
}

void main()
{
    vec3 view = normalize(vView);
    vec3 normal = normalize(vNormal);

    // glass coefficients
    vec2 rt = windowglass(-view, normal, uETA, uRC);

    // reflection
    vec3 refl = reflect(-view, normal);
    gl_FragColor = textureCube(uEnvSampler, refl) * rt.x;

    // glass color
    gl_FragColor += uGlass.a * uGlass;

    // background alpha
    gl_FragColor.a = rt.y - uGlass.a;

    // opacity
    gl_FragColor.rgb *= v3d_Opacity;
    gl_FragColor.a = 1.0 - (1.0 - gl_FragColor.a) * v3d_Opacity;
}

