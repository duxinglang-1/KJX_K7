
precision mediump float;

// built-in uniform
uniform float v3d_Opacity;

// uniform
uniform float u_EffectFactor;
uniform sampler2D u_texture;

// varying
varying vec4 vColor;
varying vec2 vTexCoord;

void main()
{
    vec4 color = texture2D(u_texture, vTexCoord);
    color *= u_EffectFactor;
    gl_FragColor.r = color.r;
    gl_FragColor.g = color.g;
    gl_FragColor.b = color.b;
    gl_FragColor.a = min(color.a, color.b);
}


