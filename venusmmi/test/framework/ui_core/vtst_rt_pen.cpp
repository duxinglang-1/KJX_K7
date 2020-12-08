/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vtst_rt_pen.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for Pen Events
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

#include "vtst_rt_main.h"
#include "vfx_input_event.h"
#include "vfx_datatype.h"
#include "vfx_text_frame.h"
#include "vfx_frame.h"
#include "vfx_string.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_basic_type.h"
#include "vfx_font_desc.h"
#include "vrt_datatype.h"
#include "vfx_pen.h"
#include "vfx_app_cat_scr.h"
#include "vfx_control.h"
#include "vfx_signal.h"


/***************************************************************************** 
 * Local Function
 *****************************************************************************/

static const VfxWChar *vfxRtPenGetPenEventTypeName(VfxPenEventTypeEnum type)
{
    const VfxWChar *str;
    switch (type)
    {
        case VFX_PEN_EVENT_TYPE_UNKNOWN:
            str = (const VfxWChar *)L"Unknown";
            break;
            
        case VFX_PEN_EVENT_TYPE_DOWN:
            str = (const VfxWChar *)L"Pen Down";
            break;
            
        case VFX_PEN_EVENT_TYPE_LONG_TAP:
            str = (const VfxWChar *)L"Long Tap";
            break;

        case VFX_PEN_EVENT_TYPE_MOVE:
            str = (const VfxWChar *)L"Pen Move";
            break;

        case VFX_PEN_EVENT_TYPE_UP:
            str = (const VfxWChar *)L"Pen Up";
            break;
            
        case VFX_PEN_EVENT_TYPE_ABORT:
            str = (const VfxWChar *)L"Pen Abort";
            break;

        case VFX_PEN_EVENT_TYPE_STROKE_DOWN:
            str = (const VfxWChar *)L"Stroke Down";
            break;

        case VFX_PEN_EVENT_TYPE_STROKE_MOVE:
            str = (const VfxWChar *)L"Stroke Move";
            break;

        case VFX_PEN_EVENT_TYPE_STROKE_UP:
            str = (const VfxWChar *)L"Stroke Up";
            break;

        default:
            str = (const VfxWChar *)L"ERROR!";
            break;
    }

    return str;
}


/***************************************************************************** 
 * Pen Test Implementation
 *****************************************************************************/

class VtstRtPen : public VtstRtScr
{
private:
    enum
    {
        MAX_POINT_COUNT = 50
    };
    
    VfxTextFrame   *m_text1;
    VfxTextFrame   *m_text2;
    VfxFrame       *m_area;
    VfxPenStrokePoint m_strokePoint[10];

    VfxPoint        m_point[MAX_POINT_COUNT];
    VfxS32          m_pointCount;

// Constructor / Destructor
public:
    VtstRtPen() : 
        m_text1(NULL), 
        m_text2(NULL), 
        m_area(NULL),
        m_pointCount(0)
    {
    }
    
// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Pen Test"));

        VFX_OBJ_CREATE(m_text1, VfxTextFrame, this);
        m_text1->setPos(VfxPoint(10, 40));
        m_text1->setString(VFX_WSTR("---"));

        VFX_OBJ_CREATE(m_text2, VfxTextFrame, this);
        m_text2->setPos(VfxPoint(10, 60));
        m_text2->setFont(VFX_FONT_DESC_SMALL);
        m_text2->setString(VFX_WSTR("---"));
        
        VFX_OBJ_CREATE(m_area, VfxFrame, this);
        m_area->setRect(VfxRect(50, 150, 100, 100));
        m_area->setBorderColor(VFX_COLOR_GREEN);
        m_area->setBorderWidth(1);
    }

    virtual VfxBool onPenInput(VfxPenEvent &event)
    {
        m_text1->setString(VFX_WSTR_STATIC(vfxRtPenGetPenEventTypeName(event.type)));
        
        switch (event.type)
        {
            case VFX_PEN_EVENT_TYPE_UNKNOWN:
                m_text1->setColor(VFX_COLOR_GREY);
                break;
                
            case VFX_PEN_EVENT_TYPE_DOWN:
            case VFX_PEN_EVENT_TYPE_MOVE:
            case VFX_PEN_EVENT_TYPE_UP:
            case VFX_PEN_EVENT_TYPE_ABORT:
                m_text1->setColor(VFX_COLOR_WHITE);

                // Update point array
                if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
                {
                    m_pointCount = 0;
                }
                if (m_pointCount < MAX_POINT_COUNT)
                {
                    m_point[m_pointCount] = event.pos;
                    m_pointCount++;
                    
                    invalidate();
                }
                break;

            case VFX_PEN_EVENT_TYPE_STROKE_DOWN:
            case VFX_PEN_EVENT_TYPE_STROKE_MOVE:
            case VFX_PEN_EVENT_TYPE_STROKE_UP:
                m_text1->setColor(VFX_COLOR_GREEN);
                break;

            default:
                m_text1->setColor(VFX_COLOR_RED);
                break;
        }

        VfxWString str;
        str.format("(%3d,%3d) T:%d", 
            event.pos.x, 
            event.pos.y, 
            event.timeStamp);
        m_text2->setString(str);

        return VFX_TRUE;
    }

    virtual void onDraw(VfxDrawContext &dc)
    {
        dc.setStrokeColor(VFX_COLOR_WHITE);
        dc.setFillColor(VFX_COLOR_GREEN);

        VfxS32 i;
        for (i = 0; i < m_pointCount - 1; i++)
        {
            dc.fillRect(m_point[i].x - 1, m_point[i].y - 1, 3, 3);
        }
        for (i = 1; i < m_pointCount - 1; i++)
        {
            dc.drawLine(m_point[i], m_point[i - 1]);
        }

        if (m_pointCount > 2)
        {
            dc.setStrokeColor(VFX_COLOR_RED);
            dc.setFillColor(VFX_COLOR_RED);
            dc.drawLine(m_point[m_pointCount - 2], m_point[m_pointCount - 1]);
        }
    }

    virtual int start()
    {
        VfxPenStrokeHandWritingRegion area;
        area.x1 = 50;
        area.x2 = 150;
        area.y1 = 150;
        area.y2 = 250;

        VfxPen *penService = VFX_OBJ_GET_INSTANCE(VfxPen);
        penService->startCaptureStrokes(this, m_strokePoint, 10, &area, 1);
        
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Does it work?"));
        return -1;
    }

    virtual void end()
    {
        VfxPen *penService = VFX_OBJ_GET_INSTANCE(VfxPen);
        penService->stopCaptureStrokes(this);
    }
};


VtstTestResultEnum vtst_rt_pen(VfxU32 param)
{
    VTST_START_SCRN(VtstRtPen);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * Pen Event Routing Test Implementation
 *****************************************************************************/

class VtstRtPenRouteControl : public VfxControl
{
    VfxWString  m_name;
    VfxTextFrame *m_text;
    
// Constructor / Destructor
public:
    VtstRtPenRouteControl(const VfxWString &name, VfxTextFrame *text) :
        m_name(name),
        m_text(text)
    {
    }

    virtual VfxBool onPenInput(VfxPenEvent &event)
    {
        m_text->setString(m_name);
        m_text->setColor(getBgColor());
        return VFX_TRUE;
    }
};


class VtstRtPenRoute : public VtstRtScr
{
// Variable
public:
    VfxTextFrame            *m_text;
    VfxTextFrame            *m_text2;
    VtstRtPenRouteControl   *m_control1;
    VtstRtPenRouteControl   *m_control2;
    VtstRtPenRouteControl   *m_control3;
    VtstRtPenRouteControl   *m_control4;

// Constructor / Destructor
public:
    VtstRtPenRoute() : 
        m_text(NULL), 
        m_text2(NULL),
        m_control1(NULL),
        m_control2(NULL),
        m_control3(NULL),
        m_control4(NULL)
    {
    }
    
// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Pen Event Routing"));

        VFX_OBJ_CREATE(m_text, VfxTextFrame, this);
        m_text->setPos(VfxPoint(10, 40));
        m_text->setString(VFX_WSTR("---"));

        VFX_OBJ_CREATE(m_text2, VfxTextFrame, this);
        m_text2->setPos(VfxPoint(10, 60));
        m_text2->setString(VFX_WSTR("---"));

        VFX_OBJ_CREATE_EX(m_control1, VtstRtPenRouteControl, this, (VFX_WSTR("Green"), m_text));
        m_control1->setRect(VfxRect(10, 100, 150, 150));
        m_control1->setBgColor(VFX_COLOR_GREEN);
        
        VFX_OBJ_CREATE_EX(m_control2, VtstRtPenRouteControl, m_control1, (VFX_WSTR("Yellow"), m_text));
        m_control2->setRect(VfxRect(30, 40, 60, 60));
        m_control2->setBgColor(VFX_COLOR_YELLOW);

        VFX_OBJ_CREATE_EX(m_control3, VtstRtPenRouteControl, m_control1, (VFX_WSTR("Red"), m_text));
        m_control3->setRect(VfxRect(70, 20, 60, 60));
        m_control3->setBgColor(VFX_COLOR_RED);

        VFX_OBJ_CREATE_EX(m_control4, VtstRtPenRouteControl, m_control1, (VFX_WSTR("White"), m_text));
        m_control4->setRect(VfxRect(50, 60, 60, 60));
        m_control4->setBgColor(VFX_COLOR_WHITE);
        m_control4->setOpacity(0.5);
        m_control4->setIsUnhittable(VFX_TRUE);

        VfxPen *pen = VFX_OBJ_GET_INSTANCE(VfxPen);
        pen->m_signalEventProcessed.connect(this, &VtstRtPenRoute::onPenEventProcessed);
    }

    virtual void onDeinit()
    {
        VfxPen *pen = VFX_OBJ_GET_INSTANCE(VfxPen);
        pen->m_signalEventProcessed.disconnect(this, &VtstRtPenRoute::onPenEventProcessed);

        VtstRtScr::onDeinit();
    }

    void onPenEventProcessed(VfxPenEvent &event, VfxControl *handledControl)
    {
        if (handledControl == NULL)
        {
            m_text2->setString(VFX_WSTR("NULL"));
            m_text2->setColor(VFX_COLOR_RED);
        }
        else if (handledControl == this)
        {
            m_text2->setString(VFX_WSTR("Screen"));
            m_text2->setColor(VFX_COLOR_GREY);
        }
        else
        {
            m_text2->setString(VFX_WSTR("Control"));
            m_text2->setColor(handledControl->getBgColor());
        }
    }

    virtual VfxBool onPenInput(VfxPenEvent &event)
    {
        m_text->setString(VFX_WSTR("Screen"));        
        return VFX_TRUE;
    }

    virtual int start()
    {
        return 1;
    }
    
    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Does it work?"));
        return -1;
    }
};


VtstTestResultEnum vtst_rt_pen_route(VfxU32 param)
{
    VTST_START_SCRN(VtstRtPenRoute);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * Pen Delayed Event Test Implementation
 *****************************************************************************/

class VtstRtPenDelayControl : public VfxControl
{
    VfxTextFrame *m_text;
    VfxTimer *m_timer;
    
// Constructor / Destructor
public:
    VtstRtPenDelayControl() : 
        m_text(NULL)
    {
    }

    virtual void onInit()
    {
        VfxControl::onInit();

        setBgColor(VFX_COLOR_YELLOW);
        setSize(100, 100);
        setAnchor(0.5f, 0.5f);

        VFX_OBJ_CREATE(m_timer, VfxTimer, this);
        m_timer->setStartDelay(300);
        m_timer->m_signalTick.connect(this, &VtstRtPenDelayControl::onTimerTick);
    }

    virtual VfxBool onPenInput(VfxPenEvent &event)
    {
        switch (event.type)
        {
            case VFX_PEN_EVENT_TYPE_DOWN:
                setBgColor(VFX_COLOR_RED);
                m_timer->stop();
                break;
                
            case VFX_PEN_EVENT_TYPE_UP:
                setBgColor(VFX_COLOR_GREEN);
                m_timer->start();
                break;

            case VFX_PEN_EVENT_TYPE_ABORT:
                setBgColor(VFX_COLOR_YELLOW);
                m_timer->stop();
                break;
        }        
        
        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->mustShowNextFrame();
        
        return VFX_TRUE;
    }

    void onTimerTick(VfxTimer *source)
    {
        setBgColor(VFX_COLOR_YELLOW);
    }
};


class VtstRtPenDelay : public VtstRtScr
{
// Variable
public:
    VtstRtPenDelayControl *m_control;
    VfxTimer *m_timer;
    VfxBool m_isCapturing;
    VfxBool m_sureDragging;

// Constructor / Destructor
public:
    VtstRtPenDelay() : 
        m_control(NULL), 
        m_timer(NULL),
        m_isCapturing(VFX_FALSE),
        m_sureDragging(VFX_FALSE)
    {
    }
    
// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Pen Event Delay"));

        VFX_OBJ_CREATE(m_control, VtstRtPenDelayControl, this);
        m_control->setPos(VfxPoint(150, 150));

        VFX_OBJ_CREATE(m_timer, VfxTimer, this);
        m_timer->setStartDelay(150);
        m_timer->m_signalTick.connect(this, &VtstRtPenDelay::onTimerTick);
    }

    void onTimerTick(VfxTimer *source)
    {
        VfxPen *penSrv = VFX_OBJ_GET_INSTANCE(VfxPen);
        penSrv->resumeDelayedEvent();
    }

    virtual VfxBool onPreviewPenInput(VfxPenEvent &event)
    {
        if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
        {
            if (!m_isCapturing)
            {
                VfxPen *penSrv = VFX_OBJ_GET_INSTANCE(VfxPen);
                penSrv->delayEvent(this, event);

                m_timer->start();
                m_sureDragging = VFX_FALSE;
            }
            else
            {
                m_sureDragging = VFX_TRUE;
                m_isCapturing = VFX_FALSE;
            }
        }
        else if (event.type == VFX_PEN_EVENT_TYPE_MOVE)
        {
            m_control->setPos(event.getRelPos(this));

            if (!m_sureDragging)
            {
                VfxS32 diffX = event.pos.x - event.downPos.x;
                VfxS32 diffY = event.pos.y - event.downPos.y;
                if (diffX * diffX + diffY * diffY > 20 * 20)
                {
                    if (m_timer->getIsEnabled())
                    {
                        m_timer->stop();
                        m_sureDragging = VFX_TRUE;
                    }
                    else
                    {
                        m_isCapturing = VFX_TRUE;
                        capture();
                        return VFX_TRUE;
                    }
                }
            }
        }
        else if (event.type == VFX_PEN_EVENT_TYPE_UP)
        {
            if (m_timer->getIsEnabled())
            {
                m_timer->stop();
                
                VfxPen *penSrv = VFX_OBJ_GET_INSTANCE(VfxPen);
                penSrv->resumeDelayedEvent();
            }
        }
        else if (event.type == VFX_PEN_EVENT_TYPE_ABORT)
        {
            m_timer->stop();
        }        
        
        return VtstRtScr::onPreviewPenInput(event);
    }
    
    virtual int start()
    {
        return 1;
    }
    
    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Does it work?"));
        return -1;
    }
};


VtstTestResultEnum vtst_rt_pen_delay(VfxU32 param)
{
    VTST_START_SCRN(VtstRtPenDelay);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

