// input of vertex shader
attribute vec2 v3d_Position;
attribute vec2 v3d_TexCoord;
attribute vec4 v3d_Color;
// output of vertex shader
varying vec4 vColor;
varying vec2 vTexCoord;

varying vec3 vPosition;
varying vec3 vCenter;
varying float x;

// built-in uniforms
uniform ivec2 v3d_ViewportSize;
uniform vec2 v3d_Scale;
uniform vec2 v3d_Bias;
uniform float v3d_PosZ;
uniform mat4 v3d_ScreenRotateMatrix;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projectView;
uniform float u_startTime;
uniform float u_endTime;

uniform bool uFlip;

// const
float pi = 3.14159265359;

void main()
{    
    // directly pass to fragment shader
    vColor = v3d_Color;
    vTexCoord = v3d_TexCoord;
    if (!uFlip)
    {
        vTexCoord.y = 1.0 - vTexCoord.y;
    }
    
    vec2 size = vec2(v3d_ViewportSize);
    // scale and bias
    vec2 pos = v3d_Position * v3d_Scale + v3d_Bias;
    // to clip space
    
    gl_Position.x = pos.x;
    gl_Position.y = pos.y;
    gl_Position.zw = vec2(0.0, 1.0); 

    //float x;
    
    if (v3d_PosZ <= u_startTime)
    {
        x = 0.0;
    }
    else if (v3d_PosZ > u_startTime && v3d_PosZ < u_endTime)
    {
        x = (v3d_PosZ - u_startTime)/(u_endTime - u_startTime);
    }
    else
    {
        x = 1.0;
    }
    
    mat4 rotate = mat4(1.0);
    rotate[0][0] = cos(-pi * x);
    rotate[2][2] = cos(-pi * x);
    rotate[2][0] = sin(-pi * x);
    rotate[0][2] = -sin(-pi * x);
    
    mat4 temp1 = rotate * u_model;
    mat4 temp2 = u_view * temp1;
    
    vec4 tempPos;
    tempPos = temp2 * gl_Position;
    
    vPosition = tempPos.xyz;
    
    gl_Position = u_projectView * temp1 * gl_Position;
   
    vec4 tempCenter;
    if (x > 0.5)
    {
        tempCenter = vec4(size.x / 2.0, size.y / 2.0, -size.x / 2.0, 1);
    }
    else
    {
        tempCenter = vec4(size.x / 2.0, size.y / 2.0, size.x / 2.0, 1);
    }
    tempCenter = temp2 * tempCenter;  
    vCenter = tempCenter.xyz;
    
    gl_Position = v3d_ScreenRotateMatrix * gl_Position;
}



