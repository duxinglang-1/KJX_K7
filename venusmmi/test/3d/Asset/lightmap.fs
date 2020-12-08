
precision mediump float;

uniform sampler2D uDiffuseSampler;
uniform sampler2D uLightSampler;

// built-in uniforms

uniform float v3d_Opacity;

// varying

varying vec2 vTexCoord;
varying vec2 vLightCoord;

void main()
{
    // texture
    gl_FragColor = texture2D(uDiffuseSampler, vTexCoord);

    // lightmap
    gl_FragColor *= texture2D(uLightSampler, vLightCoord);

    // opacity
    gl_FragColor.a *= v3d_Opacity;
}

