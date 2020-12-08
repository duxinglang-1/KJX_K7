precision mediump float;

uniform sampler2D uBgTex;
varying vec2 v_texCoord;

void main()
{
    vec4 bgColor = texture2D(uBgTex, v_texCoord);
    gl_FragColor = bgColor;
}

