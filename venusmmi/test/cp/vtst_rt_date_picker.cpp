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
 *  vtst_rt_date_picker.cpp
 *
 * Project:
 * --------
 *  Venus Regression Test for Date picker
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
#include "vcp_date_picker.h"
#include "vtst_rt_main.h"
#include "vcp_button.h"


#ifdef __AFX_RT_TEST__

#ifdef __MMI_MAINLCD_480X800__
    #define DPICKER_SCR_WIDTH           480
    #define DPICKER_SCR_HEIGHT          800
    #define DPICKER_SCR_BUTTON_HEIGHT   30  
#elif defined(__MMI_MAINLCD_320X480__)
    #define DPICKER_SCR_WIDTH           320
    #define DPICKER_SCR_HEIGHT          480
    #define DPICKER_SCR_BUTTON_HEIGHT   30  
#elif defined(__MMI_MAINLCD_240X400__)
    #define DPICKER_SCR_WIDTH           240
    #define DPICKER_SCR_HEIGHT          400
    #define DPICKER_SCR_BUTTON_HEIGHT   20  
#elif defined(__MMI_MAINLCD_240X320__)
    #define DPICKER_SCR_WIDTH           240
    #define DPICKER_SCR_HEIGHT          320
    #define DPICKER_SCR_BUTTON_HEIGHT   20  
#else 
    #define DPICKER_SCR_WIDTH           240
    #define DPICKER_SCR_HEIGHT          320
    #define DPICKER_SCR_BUTTON_HEIGHT   20  
#endif



class VtstRtDatePickerScr : public VtstRtScr
{
public:
    typedef VtstRtDatePickerScr Self;
    typedef VtstRtScr   Super;

// Variable
public:
    VcpDatePicker      *m_dpicker;
    VcpButton *m_resetBut;
    VcpButton *m_showBut;

// Constructor / Destructor
public:
    VtstRtDatePickerScr() : m_dpicker(NULL){}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("Picker Test"));

        VFX_OBJ_CREATE(m_dpicker, VcpDatePicker, this);
        m_dpicker->setPos(VfxPoint(0, 50));

        VfxS32 x, y, w, h;
        x = 0;
        y = m_dpicker->getPos().y + m_dpicker->getSize().height + 5;
        w = DPICKER_SCR_WIDTH/2;
        h = DPICKER_SCR_BUTTON_HEIGHT;

        VFX_OBJ_CREATE(m_resetBut, VcpButton, this);
        m_resetBut->setText(VFX_WSTR("Reset date"));
        m_resetBut->setPos(x, y);
        m_resetBut->setSize(w, h);
        m_resetBut->m_signalClicked.connect(this, &VtstRtDatePickerScr::onButtonClicked);
        m_resetBut->setId('RSET');

        x += w;

        VFX_OBJ_CREATE(m_showBut, VcpButton, this);
        m_showBut->setText(VFX_WSTR("Show date"));
        m_showBut->setPos(x, y);
        m_showBut->setSize(w, h);
        m_showBut->m_signalClicked.connect(this, &VtstRtDatePickerScr::onButtonClicked);
        m_showBut->setId('SHOW');


    }

    void onButtonClicked(VfxObject* sender, VfxId buttonId)
    {
        switch(buttonId)
        {
        
            case 'RSET':
            {
                VcpDatePickerStruct ddate;
                ddate.year = 2005;
                ddate.month = 1;
                ddate.day = 1;
                m_dpicker->setDate(ddate);
                break;
            }
            case 'SHOW':
            {
                VcpDatePickerStruct ddate = m_dpicker->getDate();
                VfxU16 y = ddate.year;
                VfxU8 m = ddate.month;
                VfxU8 d = ddate.day;

                VfxFrame *f;
                VFX_OBJ_CREATE(f,VfxFrame,this);
                f->setPos(0, m_dpicker->getPos().y + m_dpicker->getSize().height + 5 + DPICKER_SCR_BUTTON_HEIGHT + 5);
                f->setBounds(0, 0, DPICKER_SCR_WIDTH, 20);
                f->setBgColor(VFX_COLOR_YELLOW);

                VfxWString temp;
                temp.format("Date : %02d-%02d-%04d", m, d, y);
                
                VfxTextFrame *t;
                VFX_OBJ_CREATE(t,VfxTextFrame,f);
                t->setPos(50, 0);
                t->setString(temp);
                t->setBgColor(VFX_COLOR_YELLOW);
                t->setColor(VFX_COLOR_BLUE);
                t->setBorderColor(VFX_COLOR_GREEN);
                
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

VtstTestResultEnum vtst_rt_date_picker(VfxU32 param)
{
    VFX_UNUSED(param);
    VTST_START_SCRN(VtstRtDatePickerScr);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__
