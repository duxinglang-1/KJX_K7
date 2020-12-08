
precision mediump float;
#define pi 3.141592653589793238462643383279

// uniform
uniform sampler2D u_StartPic;
uniform float u_RippleTime;
uniform float u_TransPic;

// built-in uniform
uniform sampler2D v3d_BaseTex;
uniform float v3d_Opacity;
uniform ivec2 v3d_BaseTexSize;

// varying
varying vec2 vTexCoord;

void main()
{
    const float lengthFactor = 30.0;
    const float timeFactor = 6.0 * 2.0 * pi + 1.0;
    const float devScaleFactor = 0.3;
    const float normalScaleFactor = 0.3;
    const vec3 light = normalize(vec3(0.0, -1.0, 1.0) );
    const vec2 center = vec2(0.5, 0.5);
    float diffuseBase = 1.0 / dot(vec3(0.0, 0.0, 1.0), light);

    vec2 cPos = vTexCoord - center;
    cPos.y *= float(v3d_BaseTexSize.y) / float(v3d_BaseTexSize.x);
    float cLength = length(cPos);
    if (cLength == 0.0)
    {
        cPos = vec2(0.0, 0.05);
    }

    float ripple = cLength * lengthFactor - u_RippleTime * timeFactor;
    float scale = exp(-cLength * cLength * 4.0) * atan (cLength * 2.0) * (1.0 - abs(2.0 * (u_RippleTime - 0.5) ) ) / pi;

    float deviation = cos(ripple) * devScaleFactor;
    deviation = deviation * scale;

    float normFactor = sin(ripple) * normalScaleFactor;
    normFactor = normFactor * scale;
    vec3 normalRipple = normalize(vec3(normalize(cPos) * normFactor, 1.0) );
    float diffuse = dot(normalRipple, light) * diffuseBase;

    vec2 uv = vTexCoord + cPos * deviation;

    vec3 color = diffuse * (u_TransPic * texture2D(v3d_BaseTex, uv).rgb + (1.0 - u_TransPic) * texture2D(u_StartPic, uv).rgb);

    gl_FragColor.rgb = color;
    gl_FragColor.a = 1.0;
}

