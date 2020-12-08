precision mediump float;

varying vec4 vColor;
varying vec2 vTexCoord;
uniform sampler2D v3d_BaseTex;
uniform ivec2 v3d_BaseTexSize;
uniform float offset;
uniform float offset2;
uniform float intensity;
uniform sampler2D u_blingPic;

float blingEffect()
{
    float shear = float(v3d_BaseTexSize.y) * 2.0;
    float blingWidth = float(v3d_BaseTexSize.x) * 0.3;
    float end = float(v3d_BaseTexSize.x) + 4.0 * blingWidth + shear;
    float start = -2.0 * blingWidth;
    float pos = (offset * end - vTexCoord.y * shear) + start;

    float length1 = vTexCoord.x * float(v3d_BaseTexSize.x) - pos;
    length1 = abs(length1) / blingWidth;

    return 1.0 + texture2D(u_blingPic, vec2(length1, 0.5)).a;
}

void main()
{
    vec4 color = texture2D(v3d_BaseTex, vec2(vTexCoord.x, vTexCoord.y));
    color.rgb *= blingEffect();
    gl_FragColor = color;
}

