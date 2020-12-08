precision mediump float;
varying vec4 vColor;
varying vec2 vTexCoord;
uniform sampler2D v3d_BaseTex;

void main ()
{
    gl_FragColor = texture2D(v3d_BaseTex, vTexCoord); 

    if (gl_FragColor.a == 0.0)
    {
        discard;
    }

    gl_FragColor.r = 0.5 + (gl_FragColor.r * 0.5);
    gl_FragColor.g = 0.0;
    gl_FragColor.b = 0.0;
    gl_FragColor.rgb *= gl_FragColor.a; //PARGB when using v3d_BaseTex
}
