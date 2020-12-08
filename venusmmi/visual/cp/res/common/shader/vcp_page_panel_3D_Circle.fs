precision mediump float;

varying vec2 vTexCoord;
varying vec3 vCenter;

uniform sampler2D v3d_BaseTex;
uniform ivec2 v3d_BaseTexSize;
uniform ivec2 v3d_ViewportSize;
uniform float v3d_FpeUser0;

uniform float u_minR;
uniform float u_maxR;

uniform sampler2D u_frame1;
uniform sampler2D u_frame2;
uniform float u_ratio;

varying vec3 vPosition;
varying float x;

void main()
{
    float shiftX = (vTexCoord.x - 0.5) ;
    float shiftY = (vTexCoord.y - 0.5) * u_ratio;
    float R = shiftX * shiftX + shiftY * shiftY;
    
    if (R < u_minR  || R > u_maxR)
    {
        discard;
    }
    else
    {
        vec3 normal = normalize(vPosition - vCenter);
        vec3 light = vec3(0.0, 0.0, 1.0);
            
        float diffuse = max(0.0, dot(light, normal));
              
        if (x > 0.5)
        {
            gl_FragColor = texture2D(u_frame2, vec2(1.0 - vTexCoord.x, vTexCoord.y));
        }
        else
        {
            gl_FragColor = texture2D(u_frame1, vec2(vTexCoord.x, vTexCoord.y));  
        }
        
        diffuse = 0.5 + 0.5 * (diffuse); 
        
        if (v3d_FpeUser0 < 0.3)
        {
             gl_FragColor.rgb *= 1.0 + (diffuse - 1.0) * v3d_FpeUser0 * 3.333;
        }
        else if (v3d_FpeUser0 > 0.9)
        {
             gl_FragColor.rgb *= ((1.0 - diffuse) * v3d_FpeUser0 - 0.9 + diffuse) * 10.0;
        }
        else
        {
            gl_FragColor.rgb *= diffuse;
        }
    }
}
               