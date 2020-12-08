
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
    float factor = u_EffectFactor * 1.3;
    color.r = pow(1.0 / (1.0 - color.r), factor) - 1.0;
    color.g = pow(1.0 / (1.0 - color.g), factor) - 1.0;
    color.b = pow(1.0 / (1.0 - color.b), factor) - 1.0;
    gl_FragColor.r = color.r;
    gl_FragColor.g = color.g;
    gl_FragColor.b = color.b;
    gl_FragColor.a = color.a;
    return;
}

