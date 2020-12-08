
precision mediump float;

uniform samplerCube uEnvSampler;
uniform float uETA; // ratio of refractive indices
uniform float uRC;  // constant reflection coefficient

// built-in uniforms

uniform float v3d_Opacity;

// varying

varying vec3 vView;
varying vec3 vNormal;

vec4 fresnel_refract(vec3 I, vec3 N, float eta, float rc)
{
    // refraction and reflection coefficient
    float cosi = dot(N, I);
    if (cosi > 0.0)     // reverse side
    {
        N = -N;
        cosi = -cosi;
        eta = 1.0 / eta;
    }
    float cost2 = 1.0 - eta * eta * (1.0 - cosi * cosi);
    vec4 refr = vec4(0.0, 0.0, 0.0, 1.0);
    if (rc < 1.0 && cost2 > 0.0)    // not total reflection
    {
        float cost = sqrt(cost2);
        float rd = eta * cosi + cost;
        float rs = rd / (eta * cosi - cost);
        rs *= rs;
        float rp = (eta * cost + cosi) / (eta * cost - cosi);
        rp *= rp;

        refr = vec4(eta * I - rd * N, min((rs + rp) / 2.0 + rc, 1.0));
    }
    return refr;
}

void main()
{
    vec3 view = normalize(vView);
    vec3 normal = normalize(vNormal);

    // reflection
    vec3 refl = reflect(-view, normal);

    // refraction and reflection coefficient
    vec4 refr = fresnel_refract(-view, normal, uETA, uRC);
    /*
    // refraction
    vec4 refr;
    refr.xyz = refract(-view, normal, uETA);

    // reflection coefficient
    float rc = (uETA - 1.0) / (uETA + 1.0);
    refr.w = min((rc * rc) + uRC, 1.0);
    */

    gl_FragColor = textureCube(uEnvSampler, refl);
    gl_FragColor = mix(textureCube(uEnvSampler, refr.xyz), gl_FragColor, refr.w);

    // opacity
    gl_FragColor.a *= v3d_Opacity;
}

