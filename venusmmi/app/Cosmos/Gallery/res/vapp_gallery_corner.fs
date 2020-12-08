precision mediump float;

uniform sampler2D uDiffuseSampler;
varying vec2 v_texCoord;

void main()
{
    vec4 maskColor = texture2D(uDiffuseSampler, v_texCoord);
    if(maskColor.x == 0.0)
        discard;
        
    gl_FragColor = vec4(0, 0, 0, maskColor.x);
}

