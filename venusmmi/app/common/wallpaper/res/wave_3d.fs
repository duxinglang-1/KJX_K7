precision mediump float;

// uniform
//uniform sampler2D v3d_BaseTex;
uniform sampler2D s_texture;
uniform sampler2D s_baseTex;

// varying
varying vec2 vTexCoord;

const vec2 size = vec2(0.25, 0.0);
const vec3 light = normalize(vec3(0.0, 0.5, 1.0) );

void display(float value)
{
    gl_FragColor.r = value;
    gl_FragColor.g = value;
    gl_FragColor.b = value;
    gl_FragColor.a = 1.0;
}

void main()
{
    vec4 diff = texture2D(s_texture, vTexCoord) - 0.5;
    //display(diff.x + 0.5);
    //return;

    vec3 va = vec3(size.xy, diff.r);
    vec3 vb = vec3(size.yx, diff.a);
    vec3 normal = normalize(cross(va, vb) );

    float diffuse = dot(normal, light) / dot(vec3(0.0, 0.0, 1.0), light);
    diffuse = max(0.0, diffuse);

    vec2 displacedCoord = vTexCoord;
    displacedCoord -= normal.xy / 8.0;
    
    vec4 color = diffuse * texture2D(s_baseTex, displacedCoord);
    float specular2 = 1.0 - dot(vec3(0.0, 0.0, 1.0), reflect(-light, normal) );
    if (specular2 < 0.015)
    {
        //color *= 1.2 / (0.02 - specular2);
        //color *= 1.5;
        color += 1.0;
    }
    gl_FragColor = color;
}

