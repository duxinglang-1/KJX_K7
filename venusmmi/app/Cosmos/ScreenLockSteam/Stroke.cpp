#include "mmi_features.h"
#ifdef __MMI_VUI_SCREEN_LOCK_STEAM__

#include "stdlib.h"

#include "Stroke.h"



#define M_PI 3.14159265359

Stroke::Stroke()
{   
  m_computed = GL_FALSE;

  m_useTexture = VFX_FALSE;

  m_numLevels = 3;
  m_addControl = VFX_FALSE;
  m_radius = 1;

  m_z = 0;

}


Stroke::~Stroke()
{
}

void Stroke::add(VfxFloat x0, VfxFloat y0, VfxFloat x1, VfxFloat y1)
{
      m_control[0].x = x0;
      m_control[0].y = y0;      
      m_control[1].x = x1;
      m_control[1].y = y1;
      m_computed = VFX_FALSE;
      m_addControl = VFX_TRUE;


}


void Stroke::forceRecompute()
{
  m_computed = false;
}


void Stroke::drawCap(const VfxFPoint & p0, VfxFloat dx, VfxFloat dy,
             VfxFloat texU, VfxFloat texV)
{

  memset(m_vvCap, 0, sizeof(GLfloat) * 22 * 3);
  memset(m_ttCap, 0, sizeof(GLfloat) * 22 * 2);


  GLfloat theta = atan2f(-dy,-dx); //(dx,dy) is unit length

  m_vvCap[0] = p0.x;
  m_vvCap[1] = p0.y;
  
  m_ttCap[0] = 0.5;
  m_ttCap[1] = 0;


  m_vvCap[3] = -m_radius*dx + m_vvCap[0];
  m_vvCap[4] = -m_radius*dy + m_vvCap[1];

  //tt[2] = 0;
  //tt[3] = 0.5;

  for(GLint i=1;i<=NUM_SLICES-1;i++)
    {
      GLfloat dx1 = cosf(theta + i * M_PI / NUM_SLICES);
      GLfloat dy1 = sinf(theta + i * M_PI / NUM_SLICES);

      m_vvCap[(i + 1) * 3 + 0] = m_radius * dx1 + m_vvCap[0];
      m_vvCap[(i + 1) * 3 + 1] = m_radius * dy1 + m_vvCap[1];

        //tt[(i + 1) * 2 + 0] = 0;
        //tt[(i + 1) * 2 + 1] = 0.5;
    }

   m_vvCap[21 * 3 + 0] = m_radius * dx + m_vvCap[0];
   m_vvCap[21 * 3 + 1] = m_radius * dy + m_vvCap[1];

   //tt[21 * 2 + + 0] = 0;
   //tt[21 * 2 + 1] = 0.5;

   glVertexAttribPointer(m_vertexPosIndx, 3, GL_FLOAT, GL_FALSE, 0, m_vvCap);
   glEnableVertexAttribArray(m_vertexPosIndx);
   glVertexAttribPointer(m_vertexTexIndx, 2, GL_FLOAT, GL_FALSE, 0, m_ttCap);
   glEnableVertexAttribArray(m_vertexTexIndx);

   glDrawArrays(GL_TRIANGLE_FAN, 0, 22);   
   glDisableVertexAttribArray ( m_vertexPosIndx );
   glDisableVertexAttribArray ( m_vertexTexIndx );
    
}

void Stroke::drawThickCurve(Stack *curve, VfxFloat radius, VfxBool cap)
{


  /*if (m_useTexture)
    glEnable(GL_TEXTURE_2D);
  else
    glDisable(GL_TEXTURE_2D);
  */
  
  VfxS32 i=0;
  VfxFloat dx,dy,mag;
  VfxFPoint p0;
  VfxFPoint p1;
  VfxFPoint p2;

  if (curve->size()==0)
    return;

  p0 = curve->get(0);

  if (curve->size() == 1)
    {   

      return;
    }

  p1 = curve->get(1);

  dx = p1.y - p0.y;
  dy = p0.x - p1.x;

  mag = sqrt(dx*dx + dy*dy);

  dx /= mag;
  dy /= mag;

  VfxFloat textureU = 0.1;
  VfxFloat textureV = 0.1;


  if (cap)
    drawCap(p0, dx, dy,textureU,textureV);
    
  memset(m_vvCurve, 0, sizeof(GLfloat) * BUFFER_SIZE * 6);
  memset(m_ttCurve, 0, sizeof(GLfloat) * BUFFER_SIZE * 4);


  m_vvCurve[0] = p0.x + radius * dx;
  m_vvCurve[1] = p0.y + radius * dy;

  m_vvCurve[3] = p0.x - radius * dx;
  m_vvCurve[4] = p0.y - radius * dy;

  m_ttCurve[2] = 1;


  VfxFloat dist;

  for(i=1;i<curve->size()-1;i++)
    {
      p0 = curve->get(i-1);
      p1 = curve->get(i);
      p2 = curve->get(i+1);

      dx = p2.y - p0.y;
      dy = p0.x - p2.x;

      mag = sqrtf(dx*dx + dy*dy);

      dx /= mag;
      dy /= mag;

      //dist = sqrt((p1.x-p0.x)*(p1.x-p0.x)+(p1.y-p0.y)*(p1.y-p0.y));
      //textureU += ufreq * dist;


      m_vvCurve[i*6 + 0] = p1.x + radius * dx;
      m_vvCurve[i*6 + 1] = p1.y + radius * dy;
      
      m_vvCurve[i*6 + 3] = p1.x - radius * dx;
      m_vvCurve[i*6 + 4] = p1.y - radius * dy;

      m_ttCurve[i*4 + 2] = 1;
      
    }

  p0 = curve->get(curve->size()-2);
  p1 = curve->get(curve->size()-1);
    
  dx = p1.y - p0.y;
  dy = p0.x - p1.x;
    
  mag = sqrtf(dx*dx + dy*dy);

  dx /= mag;
  dy /= mag;
      
//  textureU += 0.1 *mag;

  
  m_vvCurve[BUFFER_SIZE*6 - 6] = p1.x + radius * dx;
  m_vvCurve[BUFFER_SIZE*6 - 5] = p1.y + radius * dy;

  m_vvCurve[BUFFER_SIZE*6 - 3] = p1.x - radius * dx;
  m_vvCurve[BUFFER_SIZE*6 - 2] = p1.y - radius * dy;

  m_ttCurve[BUFFER_SIZE*4 - 2] = 1;
  
 
   glVertexAttribPointer(m_vertexPosIndx, 3, GL_FLOAT, GL_FALSE, 0, m_vvCurve);
   glEnableVertexAttribArray(m_vertexPosIndx);

    glVertexAttribPointer(m_vertexTexIndx, 2, GL_FLOAT, GL_FALSE, 0, m_ttCurve);
   glEnableVertexAttribArray(m_vertexTexIndx);

   glDrawArrays(GL_TRIANGLE_STRIP, 0, BUFFER_SIZE*2);   
   glDisableVertexAttribArray ( m_vertexPosIndx ); 
   glDisableVertexAttribArray ( m_vertexTexIndx );



  if (cap)
    {
      drawCap(p1, -dx, -dy,textureU,textureV);
    }

}



void Stroke::render()
{
  if (m_addControl)  
  {
      if (!m_computed)
      {
         computeLimitCurve();
         m_computed = VFX_TRUE;
      }      
      drawThickCurve(&m_limit,m_radius);
      m_addControl = VFX_FALSE;
  }  
}



void Stroke::subdivide(Stack* inputCurve, Stack* outputCurve)
{ 
  outputCurve->erase();

  VfxFPoint pi0;
  VfxFPoint pi1;
  VfxFPoint pi2;
  VfxFPoint pi3;

  if (inputCurve->size() == 1)
  {
      pi0 = inputCurve->get(0);
      outputCurve->push(pi0.x,pi0.y);
      
      return;
  }

   if (inputCurve->size() == 2)
    {
      pi0 = inputCurve->get(0);
      pi1 = inputCurve->get(1);
    
      outputCurve->push(pi0.x,pi0.y);
      outputCurve->push((pi0.x+pi1.x)/2,(pi0.y+pi1.y)/2);
      outputCurve->push(pi1.x,pi1.y);   
      return;
    }

    pi0 = inputCurve->get(0); 
    pi1 = inputCurve->get(1); 
    VfxFPoint piminus1(2 * pi0.x - pi1.x, 2 * pi0.y - pi1.y);  
    pi0 = inputCurve->get(inputCurve->size()-1); 
    pi1 = inputCurve->get(inputCurve->size()-2); 
    VfxFPoint piplus1(2 * pi0.x - pi1.x, 2 * pi0.y - pi1.y);    
    for(VfxS32 i = 0; i < inputCurve->size() - 1; i++) 
    {     
        pi0 = i==0 ? piminus1 : inputCurve->get(i-1);   
        pi1 = inputCurve->get(i);    
        pi2 = inputCurve->get(i+1);  
        pi3 = i==inputCurve->size()-2 ? piplus1:inputCurve->get(i+2);  
        outputCurve->push(pi1.x, pi1.y);  
        outputCurve->push((-pi0.x + 9*pi1.x + 9*pi2.x - pi3.x)/16, (-pi0.y + 9*pi1.y + 9*pi2.y - pi3.y)/16);   
    } 
    pi0 = inputCurve->back(); 
    outputCurve->push(pi0.x,pi0.y);



}

void Stroke::computeLimitCurve()
{
  //    printf("Computing limit curve.  Input length = %d\n",control.count);

  m_temp.erase();
  m_temp.push(m_control[0].x, m_control[0].y);
  m_temp.push(m_control[1].x, m_control[1].y);
  subdivide(&m_temp, &m_limit);

  //    limit->print();
  //    printf(" count = %d\n",limit->size());

  for(int i=0;i<m_numLevels/2;i++)
    {
      subdivide(&m_limit,&m_temp);
      subdivide(&m_temp,&m_limit);
    }
}
#endif /* __MMI_VUI_SCREEN_LOCK_STEAM__*/