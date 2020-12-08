
precision mediump float;

// built-in uniforms

uniform float v3d_Opacity;

// varying

varying vec2 vTexCoord;

void main()
{
    // texcoord
    if (abs(mod(dot(vTexCoord, vec2(1.0)) * 10.0, 2.0)) < 1.0)
        discard;

    // color
    gl_FragColor = vec4(0.0, 0.0, 0.0, 1.0);

    // opacity
    gl_FragColor.a *= v3d_Opacity;
}

