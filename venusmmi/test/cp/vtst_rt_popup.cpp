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
 *  vtst_rt_popup.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for Auto-Animation
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
#include "vcp_popup.h"
#include "vfx_datatype.h"
#include "vfx_base_popup.h"
#include "vfx_frame.h"
#include "vfx_control.h"
#include "vfx_string.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_input_event.h"
#include "vcp_frame_effect_type.h"
#include "vfx_text_frame.h"
#include "vfx_image_src.h"
#include "vfx_app_cat_scr.h"

/***************************************************************************** 
 * Auto Animation Test Implementation
 *****************************************************************************/
// shell test bed
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*****************************************************************************
 * Test for VcpConfirmPopup
 *****************************************************************************/
#ifdef __MMI_MAINLCD_480X800__
    #define CPOP_SCR_WIDTH           480
    #define CPOP_SCR_HEIGHT          800
    #define CPOP_SCR_BUTTON_HEIGHT   30  
#elif defined(__MMI_MAINLCD_320X480__)
    #define CPOP_SCR_WIDTH           320
    #define CPOP_SCR_HEIGHT          480
    #define CPOP_SCR_BUTTON_HEIGHT   30  
#elif defined(__MMI_MAINLCD_240X400__)
    #define CPOP_SCR_WIDTH           240
    #define CPOP_SCR_HEIGHT          400
    #define CPOP_SCR_BUTTON_HEIGHT   20  
#elif defined(__MMI_MAINLCD_240X320__)
    #define CPOP_SCR_WIDTH           240
    #define CPOP_SCR_HEIGHT          320
    #define CPOP_SCR_BUTTON_HEIGHT   20  
#else 
    #define CPOP_SCR_WIDTH           240
    #define CPOP_SCR_HEIGHT          320
    #define CPOP_SCR_BUTTON_HEIGHT   20  
#endif

class VtstRtConfirmPopup : public VtstRtScr
{
// Variable
public:
    VcpPopupTypeEnum m_alertType;
    VcpConfirmPopupButtonSetEnum m_buttonSet;
    VfxS32           m_count;
    VcpConfirmPopup  *m_confirmPopup;
    VcpButton        *m_rotateButton;
    VcpButton        *m_changeIconButton;
    VcpButton        *m_changeButtonButton;
    VcpButton        *m_showButton;
    VfxS32            m_rotateIndex;

// Constructor / Destructor
public:
    VtstRtConfirmPopup() :
      m_alertType(VCP_POPUP_TYPE_FAILURE),
      m_buttonSet(VCP_CONFIRM_BUTTON_SET_OK),
      m_count(0),
      m_rotateIndex(0){}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("VcpConfirmPopup Test"));

        VfxS32 x, y, w, h;
        x = 10;
        y = 50;
        w = CPOP_SCR_WIDTH - 20;
        h = CPOP_SCR_BUTTON_HEIGHT;
        
        VFX_OBJ_CREATE(m_rotateButton, VcpButton, this);
        m_rotateButton->setText(VFX_WSTR("rotate"));
        m_rotateButton->setPos(x, y);
        m_rotateButton->setSize(w, h);
        m_rotateButton->setId('Rota');
        m_rotateButton->m_signalClicked.connect(this, &VtstRtConfirmPopup::onButtonClick);

        y += CPOP_SCR_BUTTON_HEIGHT;

        VFX_OBJ_CREATE(m_changeIconButton, VcpButton, this);
        m_changeIconButton->setText(VFX_WSTR("Change Icon"));
        m_changeIconButton->setPos(x, y);
        m_changeIconButton->setSize(w, h);
        m_changeIconButton->setId('Icon');
        m_changeIconButton->m_signalClicked.connect(this, &VtstRtConfirmPopup::onButtonClick);
        
        y += CPOP_SCR_BUTTON_HEIGHT;

        VFX_OBJ_CREATE(m_changeButtonButton, VcpButton, this);
        m_changeButtonButton->setText(VFX_WSTR("Change Button"));
        m_changeButtonButton->setPos(x, y);
        m_changeButtonButton->setSize(w, h);
        m_changeButtonButton->setId('Butt');
        m_changeButtonButton->m_signalClicked.connect(this, &VtstRtConfirmPopup::onButtonClick);

        y += CPOP_SCR_BUTTON_HEIGHT;

        VFX_OBJ_CREATE(m_showButton, VcpButton, this);
        m_showButton->setText(VFX_WSTR("Show"));
        m_showButton->setPos(x, y);
        m_showButton->setSize(w, h);
        m_showButton->setId('Show');
        m_showButton->m_signalClicked.connect(this, &VtstRtConfirmPopup::onButtonClick);

        VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
        m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
        m_confirmPopup->setText(VFX_WSTR("Incorrect Password"));
        m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        m_confirmPopup->setAutoDestory(VFX_FALSE);
        
    }

    void onButtonClick(VfxObject* sender, VfxId id)
    {
        switch (id)
        {
             case 'Rota':
                {
                    m_rotateIndex ++;
                    m_rotateIndex %= 4;

                    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);

                    if (m_rotateIndex == 0)
                    {
                        topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_0);
                    }
                    else if  (m_rotateIndex == 1)
                    {
                        topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_90);
                    }
                    else if  (m_rotateIndex == 2)
                    {
                        topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_180);
                    }
                    else if  (m_rotateIndex == 3)
                    {
                        topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270);
                    }
                }
                break;
            case 'Icon':
                {
                    VfxS32 temp2 = (VfxS32)m_alertType;
                    temp2 ++;
                    m_alertType = (VcpPopupTypeEnum)temp2;
                    if (m_alertType == VCP_POPUP_TYPE_END_OF_ENUM)
                    {
                        m_alertType = VCP_POPUP_TYPE_FAILURE;
                    }
                    
                    if (m_alertType == VCP_POPUP_TYPE_FAILURE)
                    {
                        m_confirmPopup->setInfoType(m_alertType);
                        m_confirmPopup->setText(VFX_WSTR("FAIL!!!!"));
                    }
                    else if (m_alertType == VCP_POPUP_TYPE_INFO)
                    {
                        m_confirmPopup->setInfoType(m_alertType);
                        m_confirmPopup->setText(VFX_WSTR("GOOD JOB!"));
                    }
                    else if (m_alertType == VCP_POPUP_TYPE_WARNING)
                    {
                        m_confirmPopup->setInfoType(m_alertType);
                        m_confirmPopup->setText(VFX_WSTR("System overheat!?"));
                    }
                    else if (m_alertType == VCP_POPUP_TYPE_SUCCESS)
                    {
                        m_confirmPopup->setInfoType(m_alertType);
                        m_confirmPopup->setText(VFX_WSTR("Venus MP pass~~\noh yeah"));
                    }
                    else if (m_alertType == VCP_POPUP_TYPE_PROGRESS)
                    {
                        m_confirmPopup->setInfoType(m_alertType);
                        m_confirmPopup->setText(VFX_WSTR("Running please wait. If you don't we, you will get some trouble"));
                    }
                    else if (m_alertType == VCP_POPUP_TYPE_QUESTION)
                    {
                        m_confirmPopup->setInfoType(m_alertType);
                        m_confirmPopup->setText(VFX_WSTR("Are you sure? Yes, I am show. the sure is not the show. You spell wrong. Your English should be improved. La La La"));
                    }
                }
                break;

            case 'Butt':
                {
                    VfxS32 temp2 = (VfxS32)m_buttonSet;
                    temp2 ++;
                    m_buttonSet = (VcpConfirmPopupButtonSetEnum)temp2;
                    //m_transitionType ++;
                    if (m_buttonSet == VCP_CONFIRM_BUTTON_SET_END_OF_ENUM)
                    {
                        m_buttonSet = VCP_CONFIRM_BUTTON_SET_OK;
                    }
                    
                    if (m_buttonSet == VCP_CONFIRM_BUTTON_SET_OK)
                    {
                        m_confirmPopup->setButtonSet(m_buttonSet);
                    }
                    else if (m_buttonSet == VCP_CONFIRM_BUTTON_SET_CANCEL)
                    {
                        m_confirmPopup->setButtonSet(m_buttonSet);
                    }
                    else if (m_buttonSet == VCP_CONFIRM_BUTTON_SET_YES_NO)
                    {
                        m_confirmPopup->setButtonSet(m_buttonSet);
                    }
                    else if (m_buttonSet == VCP_CONFIRM_BUTTON_SET_USER_DEFINE)
                    {
                        m_confirmPopup->setButtonSet(m_buttonSet);
                        m_confirmPopup->setCustomButton(VFX_WSTR("Coffee") , VFX_WSTR("Tea"), VCP_POPUP_BUTTON_TYPE_NORMAL, VCP_POPUP_BUTTON_TYPE_CANCEL);
                    }
                }
                break;

            case 'Show':
                m_confirmPopup->show(VFX_TRUE);
                break;
            default:
                break;
        }
    }

    virtual void onQueryRotateEx(const VfxScreenRotateParam &param)
    {  
    }

    virtual int start()
    {      
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        if (idx == 0)
        {
            confirm(VFX_WSTR("Confirm popup OK?"));
            return -1;
        }
        return VTST_RT_END_TESTCASE;
    }
};


VtstTestResultEnum vtst_rt_confirm_Popup(VfxU32 param)
{
    VTST_START_SCRN(VtstRtConfirmPopup);
    return VTST_TR_OK;
}

/*****************************************************************************
 * Test for VcpCommandPopup
 *****************************************************************************/

class VtstRtCommandPopup : public VtstRtScr
{
// Variable
public:
    VcpPopupTypeEnum m_alertType;
    VcpConfirmPopupButtonSetEnum m_buttonSet;
    VfxS32           m_count;
    VcpCommandPopup  *m_commandPopup;
    VcpButton        *m_rotateButton;
    VcpButton        *m_changeIconButton;
    VcpButton        *m_changeButtonButton;
    VcpButton        *m_showButton;
    VfxS32            m_rotateIndex;

// Constructor / Destructor
public:
    VtstRtCommandPopup() :
      m_alertType(VCP_POPUP_TYPE_FAILURE),
      m_buttonSet(VCP_CONFIRM_BUTTON_SET_OK),
      m_count(1),
      m_rotateIndex(0){}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("VcpCommandPopup Test"));

        VfxS32 x, y, w, h;
        x = 10;
        y = 50;
        w = CPOP_SCR_WIDTH - 20;
        h = CPOP_SCR_BUTTON_HEIGHT;

        VFX_OBJ_CREATE(m_rotateButton, VcpButton, this);
        m_rotateButton->setText(VFX_WSTR("rotate"));
        m_rotateButton->setPos(x, y);
        m_rotateButton->setSize(w, h);
        m_rotateButton->setId('Rota');
        m_rotateButton->m_signalClicked.connect(this, &VtstRtCommandPopup::onButtonClick);

        y += CPOP_SCR_BUTTON_HEIGHT;

        VFX_OBJ_CREATE(m_changeIconButton, VcpButton, this);
        m_changeIconButton->setText(VFX_WSTR("Change text"));
        m_changeIconButton->setPos(x, y);
        m_changeIconButton->setSize(w, h);
        m_changeIconButton->setId('Icon');
        m_changeIconButton->m_signalClicked.connect(this, &VtstRtCommandPopup::onButtonClick);
        
        y += CPOP_SCR_BUTTON_HEIGHT;

        VFX_OBJ_CREATE(m_changeButtonButton, VcpButton, this);
        m_changeButtonButton->setText(VFX_WSTR("Change Button"));
        m_changeButtonButton->setPos(x, y);
        m_changeButtonButton->setSize(w, h);
        m_changeButtonButton->setId('Butt');
        m_changeButtonButton->m_signalClicked.connect(this, &VtstRtCommandPopup::onButtonClick);

        y += CPOP_SCR_BUTTON_HEIGHT;

        VFX_OBJ_CREATE(m_showButton, VcpButton, this);
        m_showButton->setText(VFX_WSTR("Show"));
        m_showButton->setPos(x, y);
        m_showButton->setSize(w, h);
        m_showButton->setId('Show');
        m_showButton->m_signalClicked.connect(this, &VtstRtCommandPopup::onButtonClick);



        VFX_OBJ_CREATE(m_commandPopup, VcpCommandPopup, this);
        m_commandPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
        m_commandPopup->setText(VFX_WSTR("call 2"));
        m_commandPopup->addItem('Viki', VFX_WSTR("Viki"));
        m_commandPopup->setAutoDestory(VFX_FALSE);
        
    }

    void onButtonClick(VfxObject* sender, VfxId id)
    {
        switch (id)
        {
             case 'Rota':
                {
                    m_rotateIndex ++;
                    m_rotateIndex %= 4;

                    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);

                    if (m_rotateIndex == 0)
                    {
                        topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_0);
                    }
                    else if  (m_rotateIndex == 1)
                    {
                        topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_90);
                    }
                    else if  (m_rotateIndex == 2)
                    {
                        topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_180);
                    }
                    else if  (m_rotateIndex == 3)
                    {
                        topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270);
                    }
                }
                break;
            case 'Icon':
                {
                    VfxS32 temp2 = (VfxS32)m_alertType;
                    temp2 ++;
                    m_alertType = (VcpPopupTypeEnum)temp2;
                    if (m_alertType == VCP_POPUP_TYPE_END_OF_ENUM)
                    {
                        m_alertType = VCP_POPUP_TYPE_FAILURE;
                    }
                    
                    if (m_alertType == VCP_POPUP_TYPE_FAILURE)
                    {
                        //m_commandPopup->setInfoType(m_alertType);
                        m_commandPopup->setText(VFX_WSTR("FAIL!!!!"));
                    }
                    else if (m_alertType == VCP_POPUP_TYPE_INFO)
                    {
                        //m_commandPopup->setInfoType(m_alertType);
                        m_commandPopup->setText(VFX_WSTR("GOOD JOB!"));
                    }
                    else if (m_alertType == VCP_POPUP_TYPE_WARNING)
                    {
                        //m_commandPopup->setInfoType(m_alertType);
                        m_commandPopup->setText(VFX_WSTR("System overheat!?"));
                    }
                    else if (m_alertType == VCP_POPUP_TYPE_SUCCESS)
                    {
                        //m_commandPopup->setInfoType(m_alertType);
                        m_commandPopup->setText(VFX_WSTR("Venus MP pass~~\noh yeah"));
                    }
                    else if (m_alertType == VCP_POPUP_TYPE_PROGRESS)
                    {
                        //m_commandPopup->setInfoType(m_alertType);
                        m_commandPopup->setText(VFX_WSTR("Running please wait. If you don't we, you will get some trouble"));
                    }
                    else if (m_alertType == VCP_POPUP_TYPE_QUESTION)
                    {
                        //m_commandPopup->setInfoType(m_alertType);
                        m_commandPopup->setText(VFX_WSTR("Are you sure? Yes, I am show. the sure is not the show. You spell wrong. Your English should be improved. La La La"));
                    }
                }
                break;

            case 'Butt':
                {
                    if (m_count == 0)
                    {
                        m_commandPopup->addItem('Viki', VFX_WSTR("Viki"));
                    }
                    if (m_count == 1)
                    {
                        m_commandPopup->addItem('Leon', VFX_WSTR("Leona"));
                        m_commandPopup->disableItem('Leon');
                    }
                    if (m_count == 2)
                    {
                        m_commandPopup->addItem('Stel', VFX_WSTR("Stella"), VCP_POPUP_BUTTON_TYPE_WARNING);
                    }
                    if (m_count == 3)
                    {
                        m_commandPopup->addItem('Juli', VFX_WSTR("Julie"), VCP_POPUP_BUTTON_TYPE_WARNING);
                        m_commandPopup->disableItem('Juli');
                    }
                    if (m_count == 4)
                    {
                        m_commandPopup->addItem('Moll',VFX_WSTR("Mollie"), VCP_POPUP_BUTTON_TYPE_CANCEL);
                    }
                    if (m_count == 5)
                    {
                        m_commandPopup->addItem('Glor', VFX_WSTR("Glory"), VCP_POPUP_BUTTON_TYPE_CANCEL);
                        m_commandPopup->disableItem('Glor');
                        m_commandPopup->enableItem('Juli');
                    }
                    if (m_count == 6)
                    {
                        m_commandPopup->addItem('Anku', VFX_WSTR("Ankur"), VCP_POPUP_BUTTON_TYPE_CANCEL);
                    }
                    
                    m_count ++;
                    m_count%=VCP_COMMAND_POPUP_BUTTON_MAX_COUNT;
                }
                break;

            case 'Show':
                m_commandPopup->show(VFX_TRUE);
                break;
            default:
                break;
        }
    }

    virtual void onQueryRotateEx(const VfxScreenRotateParam &param)
    {  
    }

    virtual int start()
    {      
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        if (idx == 0)
        {
            confirm(VFX_WSTR("Command popup OK?"));
            return -1;
        }
        return VTST_RT_END_TESTCASE;
    }
};

VtstTestResultEnum vtst_rt_command_Popup(VfxU32 param)
{
    VTST_START_SCRN(VtstRtCommandPopup);
    return VTST_TR_OK;
}


#if defined(__MMI_VUI_COSMOS_CP__)
/*****************************************************************************
 * Test for VcpMoreCommandPopup
 *****************************************************************************/

class VtstRtMoreCommandPopup : public VtstRtScr
{
// Variable
public:
    VfxFrame         *m_frame1;
    VfxFrame         *m_frame2;
    VfxControl       *m_control1;
    VcpPopupTypeEnum m_alertType;
    VcpConfirmPopupButtonSetEnum m_buttonSet;
    VfxS32           m_count;
    VcpMoreCommandPopup  *m_moreCommandPopup;
    VcpButton        *m_rotateButton;
    VcpButton        *m_changeIconButton;
    VcpButton        *m_changeButtonButton;
    VcpButton        *m_showButton;
    VfxS32            m_rotateIndex;

// Constructor / Destructor
public:
    VtstRtMoreCommandPopup() :
      m_frame1(NULL),
      m_frame2(NULL),
      m_control1(NULL),
      m_alertType(VCP_POPUP_TYPE_FAILURE),
      m_buttonSet(VCP_CONFIRM_BUTTON_SET_OK),
      m_count(1),
      m_rotateIndex(0){}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("VcpMoreCommandPopup Test"));
        
        // create some background
        VFX_OBJ_CREATE(m_frame1, VfxFrame, this);
        m_frame1->setPos(20, 40);
        m_frame1->setBounds(VfxRect(0, 0, 200, 200));
        m_frame1->setIsCached(VFX_TRUE);
        m_frame1->setIsOpaque(VFX_TRUE);
        m_frame1->setBgColor(VFX_COLOR_GREEN);

        VFX_OBJ_CREATE(m_frame2, VfxFrame, this);
        m_frame2->setPos(20, 260);
        m_frame2->setBounds(VfxRect(0, 0, 80, 60));
        m_frame2->setIsCached(VFX_TRUE);
        m_frame2->setIsOpaque(VFX_TRUE);
        m_frame2->setBgColor(VFX_COLOR_GREY);

        VFX_OBJ_CREATE(m_control1, VfxControl, this);
        m_control1->setPos(140, 260);
        m_control1->setBounds(VfxRect(0, 0, 80, 60));
        m_control1->setIsCached(VFX_TRUE);
        m_control1->setIsOpaque(VFX_TRUE);
        m_control1->setBgColor(VFX_COLOR_TEAL);


        VfxS32 x, y, w, h;
        x = 10;
        y = 50;
        w = CPOP_SCR_WIDTH - 20;
        h = CPOP_SCR_BUTTON_HEIGHT;
        
        VFX_OBJ_CREATE(m_rotateButton, VcpButton, this);
        m_rotateButton->setText(VFX_WSTR("rotate"));
        m_rotateButton->setPos(x, y);
        m_rotateButton->setSize(w, h);
        m_rotateButton->setId('Rota');
        m_rotateButton->m_signalClicked.connect(this, &VtstRtMoreCommandPopup::onButtonClick);

        y += CPOP_SCR_BUTTON_HEIGHT;

        VFX_OBJ_CREATE(m_changeButtonButton, VcpButton, this);
        m_changeButtonButton->setText(VFX_WSTR("Change Button"));
        m_changeButtonButton->setPos(x, y);
        m_changeButtonButton->setSize(w, h);
        m_changeButtonButton->setId('Butt');
        m_changeButtonButton->m_signalClicked.connect(this, &VtstRtMoreCommandPopup::onButtonClick);

        y += CPOP_SCR_BUTTON_HEIGHT;

        VFX_OBJ_CREATE(m_showButton, VcpButton, this);
        m_showButton->setText(VFX_WSTR("Show"));
        m_showButton->setPos(x, y);
        m_showButton->setSize(w, h);
        m_showButton->setId('Show');
        m_showButton->m_signalClicked.connect(this, &VtstRtMoreCommandPopup::onButtonClick);

        VFX_OBJ_CREATE(m_moreCommandPopup, VcpMoreCommandPopup, this);

        m_moreCommandPopup->addItem('Viki', VFX_WSTR("Viki"));
        m_moreCommandPopup->setAutoDestory(VFX_FALSE);
    }

    void onButtonClick(VfxObject* sender, VfxId id)
    {
        switch (id)
        {
             case 'Rota':
                {
                    m_rotateIndex ++;
                    m_rotateIndex %= 4;

                    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);

                    if (m_rotateIndex == 0)
                    {
                        topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_0);
                    }
                    else if  (m_rotateIndex == 1)
                    {
                        topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_90);
                    }
                    else if  (m_rotateIndex == 2)
                    {
                        topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_180);
                    }
                    else if  (m_rotateIndex == 3)
                    {
                        topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270);
                    }
                }
                break;
            case 'Icon':
               
                break;

            case 'Butt':
                {
                    if (m_count == 0)
                    {
                        m_moreCommandPopup->addItem('Viki', VFX_WSTR("Viki"));
                    }
                    if (m_count == 1)
                    {
                        m_moreCommandPopup->addItem('Leon', VFX_WSTR("Leona"));
                        m_moreCommandPopup->disableItem('Leon');
                    }
                    if (m_count == 2)
                    {
                        m_moreCommandPopup->addItem('Stel', VFX_WSTR("Stella"), VCP_POPUP_BUTTON_TYPE_WARNING);
                    }
                    if (m_count == 3)
                    {
                        m_moreCommandPopup->addItem('Juli', VFX_WSTR("Julie"), VCP_POPUP_BUTTON_TYPE_WARNING);
                        m_moreCommandPopup->disableItem('Juli');
                    }
                    if (m_count == 4)
                    {
                        m_moreCommandPopup->addItem('Moll',VFX_WSTR("Mollie"), VCP_POPUP_BUTTON_TYPE_CANCEL);
                    }
                    if (m_count == 5)
                    {
                        m_moreCommandPopup->addItem('Glor', VFX_WSTR("Glory"), VCP_POPUP_BUTTON_TYPE_CANCEL);
                        m_moreCommandPopup->disableItem('Glor');
                    }
                    
                    m_count ++;
                    m_count%=6;
                }
                break;

            case 'Show':
                m_moreCommandPopup->show(VFX_TRUE);
                break;
            default:
                break;
        }
    }

    virtual void onQueryRotateEx(const VfxScreenRotateParam &param)
    {  
    }

    virtual int start()
    {      
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        if (idx == 0)
        {
            confirm(VFX_WSTR("More Command popup OK?"));
            return -1;
        }
        return VTST_RT_END_TESTCASE;
    }
};

VtstTestResultEnum vtst_rt_more_command_Popup(VfxU32 param)
{
    VTST_START_SCRN(VtstRtMoreCommandPopup);
    return VTST_TR_OK;
}


/*****************************************************************************
 * Test for VcpSelectPopup
 *****************************************************************************/

class VtstRtSelectPopup : public VtstRtScr
{
// Variable
public:
    VfxFrame         *m_frame1;
    VfxFrame         *m_frame2;
    VfxControl       *m_control1;
    VcpSelectPopupTypeEnum m_type;
    VcpConfirmPopupButtonSetEnum m_buttonSet;
    VfxS32           m_count;
    VcpSelectPopup   *m_selectPopup;
    VcpButton        *m_rotateButton;
    VcpButton        *m_changeIconButton;
    VcpButton        *m_changeButtonButton;
    VcpButton        *m_showButton;
    VfxTextFrame     *m_selectResult;
    VfxBool           m_clickOk;
    VfxS32            m_rotateIndex;

// Constructor / Destructor
public:
    VtstRtSelectPopup() :
      m_frame1(NULL),
      m_frame2(NULL),
      m_control1(NULL),
      m_type(VCP_SELECT_POPUP_BUTTON_TYPE_QUICK),
      m_buttonSet(VCP_CONFIRM_BUTTON_SET_OK),
      m_count(1),
      m_clickOk(VFX_FALSE),
      m_rotateIndex(0)
      {}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("VcpSelectPopup Test"));
        
        // create some background
        VFX_OBJ_CREATE(m_frame1, VfxFrame, this);
        m_frame1->setPos(20, 40);
        m_frame1->setBounds(VfxRect(0, 0, 200, 200));
        m_frame1->setIsCached(VFX_TRUE);
        m_frame1->setIsOpaque(VFX_TRUE);
        m_frame1->setBgColor(VFX_COLOR_GREEN);

        VFX_OBJ_CREATE(m_frame2, VfxFrame, this);
        m_frame2->setPos(20, 260);
        m_frame2->setBounds(VfxRect(0, 0, 80, 60));
        m_frame2->setIsCached(VFX_TRUE);
        m_frame2->setIsOpaque(VFX_TRUE);
        m_frame2->setBgColor(VFX_COLOR_GREY);

        VFX_OBJ_CREATE(m_control1, VfxControl, this);
        m_control1->setPos(140, 260);
        m_control1->setBounds(VfxRect(0, 0, 80, 60));
        m_control1->setIsCached(VFX_TRUE);
        m_control1->setIsOpaque(VFX_TRUE);
        m_control1->setBgColor(VFX_COLOR_TEAL);

        VfxS32 x, y, w, h;
        x = 10;
        y = 50;
        w = CPOP_SCR_WIDTH - 20;
        h = CPOP_SCR_BUTTON_HEIGHT;

        VFX_OBJ_CREATE(m_rotateButton, VcpButton, this);
        m_rotateButton->setText(VFX_WSTR("rotate"));
        m_rotateButton->setPos(x, y);
        m_rotateButton->setSize(w, h);
        m_rotateButton->setId('Rota');
        m_rotateButton->m_signalClicked.connect(this, &VtstRtSelectPopup::onButtonClick);

        y += CPOP_SCR_BUTTON_HEIGHT;

        VFX_OBJ_CREATE(m_changeIconButton, VcpButton, this);
        m_changeIconButton->setText(VFX_WSTR("Change type"));
        m_changeIconButton->setPos(x, y);
        m_changeIconButton->setSize(w, h);
        m_changeIconButton->setId('Icon');
        m_changeIconButton->m_signalClicked.connect(this, &VtstRtSelectPopup::onButtonClick);
        
        y += CPOP_SCR_BUTTON_HEIGHT;

        VFX_OBJ_CREATE(m_changeButtonButton, VcpButton, this);
        m_changeButtonButton->setText(VFX_WSTR("Change Button"));
        m_changeButtonButton->setPos(x, y);
        m_changeButtonButton->setSize(w, h);
        m_changeButtonButton->setId('Butt');
        m_changeButtonButton->m_signalClicked.connect(this, &VtstRtSelectPopup::onButtonClick);

        y += CPOP_SCR_BUTTON_HEIGHT;

        VFX_OBJ_CREATE(m_showButton, VcpButton, this);
        m_showButton->setText(VFX_WSTR("Show"));
        m_showButton->setPos(x, y);
        m_showButton->setSize(w, h);
        m_showButton->setId('Show');
        m_showButton->m_signalClicked.connect(this, &VtstRtSelectPopup::onButtonClick);


        VFX_OBJ_CREATE(m_selectPopup, VcpSelectPopup, this);
        m_selectPopup->setText(VFX_WSTR("call 2"));
        m_selectPopup->addItem('Viki', VFX_WSTR("Viki"));
        m_selectPopup->setAutoDestory(VFX_FALSE);
        m_selectPopup->m_signalPopupState.connect(this, &VtstRtSelectPopup::onPopupStateChanged);
        m_selectPopup->m_signalButtonClicked.connect(this, &VtstRtSelectPopup::onPopupButtonClicked);

        VFX_OBJ_CREATE(m_selectResult, VfxTextFrame, this);
        m_selectResult->setPos(20, 100);
        m_selectResult->setBounds(0, 0, 240, 30);
        m_selectResult->setBgColor(VFX_COLOR_BLACK);
        m_selectResult->setString(VFX_WSTR("Hi Hi"));
        /*
        VfxFrame *tempFrame;

        VFX_OBJ_CREATE(tempFrame, VfxFrame, this);
        tempFrame->setPos(20, 200);
        tempFrame->setBounds(0, 0, 240, 30);
        tempFrame->setBgColor(VFX_COLOR_BLACK);
        */
        
        
    }

    void onPopupButtonClicked(VfxObject* obj, VfxId buttonId)
    {
        if (buttonId == VCP_SELECT_POPUP_BUTTON_OK)
        {
            m_clickOk = VFX_TRUE;
        }
        else
        {
            m_clickOk = VFX_FALSE;
        }
    }

    void onPopupStateChanged(VfxBasePopup* popup, VfxBasePopupStateEnum state)
    {
        if (state == VFX_BASE_POPUP_AFTER_END_ANIMATION)
        {
            VcpSelectPopup *selectPopup = (VcpSelectPopup *)popup;
            VcpSelectPopupTypeEnum type = selectPopup->getType();

            if (type == VCP_SELECT_POPUP_BUTTON_TYPE_SINGLE || type == VCP_SELECT_POPUP_BUTTON_TYPE_MULTI)
            {
                if (m_clickOk == VFX_FALSE)
                {
                    return;
                }
            }

            if (type == VCP_SELECT_POPUP_BUTTON_TYPE_SINGLE || type == VCP_SELECT_POPUP_BUTTON_TYPE_QUICK)
            {
                switch (selectPopup->getFirstSeletedId())
                {
                    case 'Viki' :
                        m_selectResult->setString(VFX_WSTR("Viki is good"));
                        break;
                    case 'Leon' :
                        m_selectResult->setString(VFX_WSTR("Leona is good"));
                        break;
                    case 'Stel' :
                        m_selectResult->setString(VFX_WSTR("Stella is good"));
                        break;
                    case 'Juli' :
                        m_selectResult->setString(VFX_WSTR("Julie is good"));
                        break;
                    case 'Moll' :
                        m_selectResult->setString(VFX_WSTR("Mollie is good"));
                        break;
                    case 'Glor' :
                        m_selectResult->setString(VFX_WSTR("Glory is good"));
                        break;
                }
            }
            else
            {
                VfxWString string;
                VfxS32 i;
                for (i = selectPopup->getFirstSeletedIndex(); i != -1; i = selectPopup->getNextSelectedIndex(i))
                {
                    switch (selectPopup->getIdbyIndex(i))
                    {
                        case 'Viki' :
                            string += VFX_WSTR("Viki,");
                            break;
                        case 'Leon' :
                            string += VFX_WSTR("Leona,");
                            break;
                        case 'Stel' :
                            string += VFX_WSTR("Stella,");
                            break;
                        case 'Juli' :
                            string += VFX_WSTR("Julie,");
                            break;
                        case 'Moll' :
                            string += VFX_WSTR("Mollie,");
                            break;
                        case 'Glor' :
                            string += VFX_WSTR("Glory,");
                            break;
                    }
                }

                string += VFX_WSTR("are good.");
                m_selectResult->setString(string);
            }
            
        }
    }
    

    void onButtonClick(VfxObject* sender, VfxId id)
    {
        switch (id)
        {
            case 'Rota':
                {
                    m_rotateIndex ++;
                    m_rotateIndex %= 4;

                    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);

                    if (m_rotateIndex == 0)
                    {
                        topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_0);
                    }
                    else if  (m_rotateIndex == 1)
                    {
                        topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_90);
                    }
                    else if  (m_rotateIndex == 2)
                    {
                        topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_180);
                    }
                    else if  (m_rotateIndex == 3)
                    {
                        topLevel->setScreenRotateType(VFX_SCR_ROTATE_TYPE_270);
                    }
                }
                break;
            case 'Icon':
                {
                    VfxS32 temp2 = (VfxS32)m_type;
                    temp2 ++;
                    m_type = (VcpSelectPopupTypeEnum)temp2;
                    if (m_type == VCP_SELECT_POPUP_BUTTON_TYPE_END_OF_ENUM)
                    {
                        m_type = VCP_SELECT_POPUP_BUTTON_TYPE_QUICK;
                    }
                    
                    if (m_type == VCP_SELECT_POPUP_BUTTON_TYPE_QUICK)
                    {
                        //m_commandPopup->setInfoType(m_alertType);
                        m_selectPopup->setType(m_type);
                    }
                    else if (m_type == VCP_SELECT_POPUP_BUTTON_TYPE_SINGLE)
                    {
                        //m_commandPopup->setInfoType(m_alertType);
                        m_selectPopup->setType(m_type);
                    }
                    else if (m_type == VCP_SELECT_POPUP_BUTTON_TYPE_MULTI)
                    {
                        //m_commandPopup->setInfoType(m_alertType);
                        m_selectPopup->setType(m_type);
                    }
                }
                break;

            case 'Butt':
                {
                    if (m_count == 0)
                    {
                        m_selectPopup->addItem('Viki', VFX_WSTR("Viki"));
                    }
                    if (m_count == 1)
                    {
                        m_selectPopup->addItem('Leon', VFX_WSTR("Leona"), VFX_TRUE);
                        //m_selectPopup->disableItem('Leon');
                    }
                    if (m_count == 2)
                    {
                        m_selectPopup->addItem('Stel', VFX_WSTR("Stella"));
                    }
                    if (m_count == 3)
                    {
                        m_selectPopup->addItem('Juli', VFX_WSTR("Julie"));
                        //m_selectPopup->disableItem('Juli');
                    }
                    if (m_count == 4)
                    {
                        m_selectPopup->addItem('Moll',VFX_WSTR("Mollie"));
                    }
                    if (m_count == 5)
                    {
                        m_selectPopup->addItem('Glor', VFX_WSTR("Glory"));
                        //m_selectPopup->disableItem('Glor');
                    }
                    
                    m_count ++;
                    m_count%=6;
                }
                break;

            case 'Show':
                m_selectPopup->show(VFX_TRUE);
                break;
            default:
                break;
        }
    }

    virtual void onQueryRotateEx(const VfxScreenRotateParam &param)
    {  
    }

    virtual int start()
    {      
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        if (idx == 0)
        {
            confirm(VFX_WSTR("Select popup OK?"));
            return -1;
        }
        return VTST_RT_END_TESTCASE;
    }
};

VtstTestResultEnum vtst_rt_select_Popup(VfxU32 param)
{
    VTST_START_SCRN(VtstRtSelectPopup);
    return VTST_TR_OK;
}

#endif

#endif // __AFX_RT_TEST__

