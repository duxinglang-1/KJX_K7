precision mediump float;

// varyings
varying vec2 vTexCoord;

// custom textures
uniform sampler2D u_texFrom;
uniform sampler2D u_texTo;
uniform sampler2D u_texMask;
uniform float u_effectTime;

void main()
{
    vec4 ca = texture2D(u_texFrom, vTexCoord);
    vec4 cb = texture2D(u_texTo, vTexCoord);
    vec4 m = texture2D(u_texMask, vTexCoord);
    float k = clamp((u_effectTime - m.r) * 33.0, 0.0, 1.0);
    gl_FragColor = mix(ca, cb, vec4(k));
    gl_FragColor.a = 1.0;
}

