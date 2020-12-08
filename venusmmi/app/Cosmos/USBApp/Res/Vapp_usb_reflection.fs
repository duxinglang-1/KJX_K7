precision mediump float;

varying vec4 vColor;
varying vec2 vTexCoord;
uniform sampler2D v3d_BaseTex;

void main()
{  
    gl_FragColor = vColor * texture2D(v3d_BaseTex, vec2(vTexCoord.x, 1.0 - vTexCoord.y));
    gl_FragColor.a = gl_FragColor.a * (0.5 - (1.0 - vTexCoord.y));
}

