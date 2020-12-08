/*uniform ivec2 uViewportSize;

attribute vec4 aPosition;
varying vec4 vColor;


void main() 
{  
	float t = float(uViewportSize.x);                      
   vColor = vec4(1.0f,t,0.0f,1.0f);  
   gl_Position = aPosition;  
}                           
 
 */

 
 
// const
const float pi = 3.14159265359;
float fovy = pi / 6.0;
float n = 10.0;
float f = 2000.0;



uniform ivec2 uViewportSize;
//uniform ivec2 uFrameSize;
uniform ivec2 uViewport;
uniform ivec2 uFrameAnchor;

varying vec2 vTexCoord;
//varying vec4 vColor;

attribute vec2 aTexCoord;
attribute vec4 aPosition;



void main()
{


  	 
  
    
  gl_Position = aPosition;
	vTexCoord = aTexCoord; 
  
  
   
     // 3d transform
  	 vec2 size = vec2(uViewportSize);  
  	 vec2 anchor = vec2(uFrameAnchor);
  	 
	gl_Position.x = ((gl_Position.x - anchor.x)*2.0 - size.x) / size.x;  	 
  gl_Position.y = ((gl_Position.y - anchor.y)*2.0 - size.y) / size.y;	 
  	 
  
  /*  float h = tan(fovy / 2.0);
    float w = h * size.x / size.y;
    float d = f - n;
    vec4 eyepos = vec4(0,0,size.y / 2.0 / h,1);
    
    
    mat4 proj = mat4(1.0);
    proj[0][0] = 1.0 / w;
    proj[1][1] = 1.0 / h;
    proj[2][2] = -(n + f) / d;
    proj[3][3] = 0.0;
    proj[2][3] = -1.0;
    proj[3][2] = -2.0*n*f / d;
	
	
	  mat4 model = mat4(1.0);
    //model[3][0] = -size.x / 2.0;
    //model[3][1] = -size.y / 2.0;
    model[3][0] = float(-uFrameSize.x + uFrameAnchor.x) / 2.0;
    model[3][1] = float(-uFrameSize.y + uFrameAnchor.y) / 2.0;
  
    mat4 view = mat4(1.0);		
    view[3] = -eyepos;
    view[3][3] = 1;  
   
    
	 gl_Position = proj * view *  model * gl_Position;

  // vColor = vec4(1.0f,0.0f,0.0f,1.0f);  	*/
   
}
