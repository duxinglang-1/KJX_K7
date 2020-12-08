precision mediump float;

varying vec2 vTexCoord;
varying vec3 vCenter;

uniform sampler2D v3d_BaseTex;
uniform ivec2 v3d_BaseTexSize;
uniform ivec2 v3d_ViewportSize;
uniform float v3d_FpeUser0;

uniform float u_minR;
uniform float u_maxR;

varying vec3 vPosition;

void main()
{
    float ratio = float(v3d_BaseTexSize.y)/float(v3d_BaseTexSize.x);
    float shiftX = (vTexCoord.x - 0.5) ;
    float shiftY = (vTexCoord.y - 0.5) * ratio;
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
              
        gl_FragColor = texture2D(v3d_BaseTex, vec2(vTexCoord.x, vTexCoord.y));  
        
        if (v3d_FpeUser0 < 0.3)
        {
             gl_FragColor.rgb *= 1.0 * (0.3 - v3d_FpeUser0) / 0.3 + v3d_FpeUser0 /0.3 * (0.5 + 0.5 * (diffuse));
        }
        else if (v3d_FpeUser0 > 0.9)
        {
             gl_FragColor.rgb *= 1.0 * (v3d_FpeUser0 - 0.9) * 10.0 + (0.1 - (v3d_FpeUser0 - 0.9)) * 10.0 * (0.5 + 0.5 * (diffuse));
        }
        else
        {
            gl_FragColor.rgb *= 0.5 + 0.5 * (diffuse);
        }
    }
}
               