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
 *  vtst_rt_time_picker.cpp
 *
 * Project:
 * --------
 *  Venus Regression Test for Time picker
 *
 * Description:
 * ------------
 *  
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vcp_time_picker.h"
#include "vtst_rt_main.h"
#include "vcp_button.h"

#ifdef __AFX_RT_TEST__

#ifdef __MMI_MAINLCD_480X800__
    #define TPICKER_SCR_WIDTH           480
    #define TPICKER_SCR_HEIGHT          800
    #define TPICKER_SCR_BUTTON_HEIGHT   30  
#elif defined(__MMI_MAINLCD_320X480__)
    #define TPICKER_SCR_WIDTH           320
    #define TPICKER_SCR_HEIGHT          480
    #define TPICKER_SCR_BUTTON_HEIGHT   30  
#elif defined(__MMI_MAINLCD_240X400__)
    #define TPICKER_SCR_WIDTH           240
    #define TPICKER_SCR_HEIGHT          400
    #define TPICKER_SCR_BUTTON_HEIGHT   20  
#elif defined(__MMI_MAINLCD_240X320__)
    #define TPICKER_SCR_WIDTH           240
    #define TPICKER_SCR_HEIGHT          320
    #define TPICKER_SCR_BUTTON_HEIGHT   20  
#else 
    #define TPICKER_SCR_WIDTH           240
    #define TPICKER_SCR_HEIGHT          320
    #define TPICKER_SCR_BUTTON_HEIGHT   20  
#endif


class VtstRtTimePickerScr : public VtstRtScr
{
public:
    typedef VtstRtTimePickerScr Self;
    typedef VtstRtScr   Super;

// Variable
public:
    VcpTimePicker      *m_tpicker;
    VcpButton *m_resetBut;
    VcpButton *m_showBut;
    VcpButton *m_changeBut;

// Constructor / Destructor
public:
    VtstRtTimePickerScr() : m_tpicker(NULL){}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("Picker Test"));

        VFX_OBJ_CREATE(m_tpicker, VcpTimePicker, this);
        m_tpicker->setPos(VfxPoint(0, 50));
        m_tpicker->setIs24HourView(VFX_FALSE);

        VfxS32 x, y, w, h;
        x = 0;
        y = m_tpicker->getPos().y + m_tpicker->getSize().height + 5;
        w = TPICKER_SCR_WIDTH/3;
        h = TPICKER_SCR_BUTTON_HEIGHT;

        VFX_OBJ_CREATE(m_resetBut, VcpButton, this);
        m_resetBut->setText(VFX_WSTR("Reset time"));
        m_resetBut->setPos(x, y);
        m_resetBut->setSize(w, h);
        m_resetBut->m_signalClicked.connect(this, &VtstRtTimePickerScr::onButtonClicked);
        m_resetBut->setId('RSET');

        x += w;

        VFX_OBJ_CREATE(m_showBut, VcpButton, this);
        m_showBut->setText(VFX_WSTR("Show time"));
        m_showBut->setPos(x, y);
        m_showBut->setSize(w, h);
        m_showBut->m_signalClicked.connect(this, &VtstRtTimePickerScr::onButtonClicked);
        m_showBut->setId('SHOW');

        x += w;

        VFX_OBJ_CREATE(m_changeBut, VcpButton, this);
        m_changeBut->setText(VFX_WSTR("Change mode"));
        m_changeBut->setPos(x, y);
        m_changeBut->setSize(w, h);
        m_changeBut->m_signalClicked.connect(this, &VtstRtTimePickerScr::onButtonClicked);
        m_changeBut->setId('MODE');
    }


    void onButtonClicked(VfxObject* sender, VfxId buttonId)
    {
        switch(buttonId)
        {
        
            case 'RSET':
            {
                VcpTimePickerStruct ttime;
                ttime.hour = 0;
                ttime.minute = 0;
                m_tpicker->setTime(ttime);
                break;
            }
            case 'SHOW':
            {
                VcpTimePickerStruct time = m_tpicker->getTime();
                VfxU8 h = time.hour;
                VfxU8 m = time.minute;

                VfxFrame *f;
                VFX_OBJ_CREATE(f,VfxFrame,this);
                f->setPos(0, m_tpicker->getPos().y + m_tpicker->getSize().height + 5 + TPICKER_SCR_BUTTON_HEIGHT + 5);
                f->setBounds(0, 0, TPICKER_SCR_WIDTH, 20);
                f->setBgColor(VFX_COLOR_YELLOW);

                VfxWString temp;
                temp.format("Time : %02d:%02d %s", (h == 0 || h == 12) ? 12 : (h % 12), m, (h < 12) ? "AM" : "PM");

                VfxTextFrame *t;
                VFX_OBJ_CREATE(t,VfxTextFrame,f);
                t->setPos(10, 0);
                t->setString(temp);
                t->setBgColor(VFX_COLOR_YELLOW);
                t->setColor(VFX_COLOR_BLUE);
                t->setBorderColor(VFX_COLOR_GREEN);
                
                break;
            }
            case 'MODE':
            {
                m_tpicker->setIs24HourView(!m_tpicker->getIs24HourView());
                break;
            }
            
            default:
                    {}
        }
    }
    virtual VfxBool onKeyInput(VfxKeyEvent &event)
    {
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
            if (event.keyCode == VFX_KEY_CODE_1)
            {
            }
            
        }
        return VtstRtScr::onKeyInput(event);
    }

    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {  
        //return param.rotateTo;
    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    virtual int start()
    {      
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        VFX_UNUSED(idx);
        confirm(VFX_WSTR("Does it work?"));
        return -1;
    }
};

VtstTestResultEnum vtst_rt_time_picker(VfxU32 param)
{
    VFX_UNUSED(param);
    VTST_START_SCRN(VtstRtTimePickerScr);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__
