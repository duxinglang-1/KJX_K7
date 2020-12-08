
precision mediump float;

// built-in uniforms

uniform float v3d_Opacity;

// varying

varying vec2 vTexCoord;

void main()
{
    // texcoord
    if (abs(dot(floor(mod(vTexCoord * 10.0, 2.0)), vec2(1.0))) == 1.0)
        discard;

    // color
    gl_FragColor = vec4(1.0);

    // opacity
    gl_FragColor.a *= v3d_Opacity;
}

