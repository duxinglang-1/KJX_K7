
precision mediump float;

uniform sampler2D uDiffuseSampler;

// built-in uniforms

uniform float v3d_Opacity;

// varying

varying vec4 vColor;
varying vec2 vTexCoord;

void main()
{
    // texture
    gl_FragColor = texture2D(uDiffuseSampler, vTexCoord);

    // color
    gl_FragColor *= vColor;

    // opacity
    gl_FragColor.a *= v3d_Opacity;
}

