#include "mmi_features.h"
#ifdef __MMI_VUI_SCREEN_LOCK_STEAM__

#include "vfx_uc_include.h"

#include "vfx_primitive_frame.h"

#include "gles2\gl2.h"


#define NUM_SLICES 20
#define BUFFER_SIZE 9
#define CONTROL_SIZE 2


class Stack
{
public:
    Stack()
    {
        m_top = -1;
    }
    ~Stack(){}

    void push(VfxFloat x, VfxFloat y)
    {
        m_top = (m_top + 1) % BUFFER_SIZE;        
        m_buffer[m_top].x = x;
        m_buffer[m_top].y = y;
        
    };
    void erase(){
        m_top = -1;
    }
    VfxS32 size()
    {
        return m_top + 1;
    }    
    VfxFPoint back(){
        if(m_top>=0)
            return m_buffer[m_top];
        else
            return VFX_FPOINT_ZERO;
                
    }
    VfxFPoint get(VfxS32 idx)
    {
        idx %= BUFFER_SIZE;
        if (idx>=0 && idx <= m_top)
        {
           return m_buffer[idx];
        }
        else
        {
            return VFX_FPOINT_ZERO;
        }        
    }

private:
    VfxFPoint m_buffer[BUFFER_SIZE];    
    VfxS32 m_top;

    
};



class Stroke
{


public:
    Stroke();
    ~Stroke();
    
    void add(VfxFloat x0, VfxFloat y0,VfxFloat x1, VfxFloat y1);  
    
    void render();
    
    VfxFloat m_radius;    
    VfxS32 m_vertexPosIndx;
    VfxS32 m_vertexTexIndx;
    GLfloat m_vvCap[22*3];
    GLfloat m_ttCap[22*2];
    GLfloat m_vvCurve[BUFFER_SIZE*6];
    GLfloat m_ttCurve[BUFFER_SIZE*4];  


private:
    void forceRecompute();

    void drawCap(const VfxFPoint& p0, VfxFloat dx, VfxFloat dy, VfxFloat texU, VfxFloat texV);
    void drawThickCurve(Stack* curve, VfxFloat radius, VfxBool cap=true);
    void subdivide(Stack* inputCurve, Stack* outputCurve);
    void computeLimitCurve();

    
    VfxFPoint m_control[CONTROL_SIZE];
    Stack m_limit;
    Stack m_temp;
    
    VfxBool m_computed;
    VfxS32 m_numLevels;

    VfxFloat m_z;

    VfxBool m_useTexture;
    VfxBool m_addControl;
};

#endif /* MMI_VUI_SCREEN_LOCK_STEAM*/
