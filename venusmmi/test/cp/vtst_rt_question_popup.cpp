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
 *  vtst_rt_question_popup.cpp
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
#include "vtst_rt_main.h"
#include "vcp_popup.h"
#if defined(__AFX_RT_TEST__) && defined(__MMI_VUI_COSMOS_CP__)
#include "vcp_res.h"


/*****************************************************************************
 * Test for VcpConfirmPopup
 *****************************************************************************/
#ifdef __MMI_MAINLCD_480X800__
    #define QPOP_SCR_WIDTH           480
    #define QPOP_SCR_HEIGHT          800
    #define QPOP_SCR_BUTTON_HEIGHT   30  
#elif defined(__MMI_MAINLCD_320X480__)
    #define QPOP_SCR_WIDTH           320
    #define QPOP_SCR_HEIGHT          480
    #define QPOP_SCR_BUTTON_HEIGHT   30  
#elif defined(__MMI_MAINLCD_240X400__)
    #define QPOP_SCR_WIDTH           240
    #define QPOP_SCR_HEIGHT          400
    #define QPOP_SCR_BUTTON_HEIGHT   20  
#elif defined(__MMI_MAINLCD_240X320__)
    #define QPOP_SCR_WIDTH           240
    #define QPOP_SCR_HEIGHT          320
    #define QPOP_SCR_BUTTON_HEIGHT   20  
#else 
    #define QPOP_SCR_WIDTH           240
    #define QPOP_SCR_HEIGHT          320
    #define QPOP_SCR_BUTTON_HEIGHT   20  
#endif


/*****************************************************************************
 * Test for VcpQuestionPopup
 *****************************************************************************/

class VtstRtQuestionPopup : public VtstRtScr
{
// Variable
public:
    VcpPopupTypeEnum m_alertType;
    VcpConfirmPopupButtonSetEnum m_buttonSet;
    VfxS32           m_count;
    VcpQuestionPopup  *m_questionPopup;
    VcpButton        *m_rotateButton;
    VcpButton        *m_changeIconButton;
    VcpButton        *m_changeButtonButton;
    VcpButton        *m_showButton;
    VfxS32            m_rotateIndex;

// Constructor / Destructor
public:
    VtstRtQuestionPopup() :
      m_alertType(VCP_POPUP_TYPE_FAILURE),
      m_buttonSet(VCP_CONFIRM_BUTTON_SET_OK),
      m_count(1),
      m_rotateIndex(0){}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("VcpQuestionPopup Test"));

        VfxS32 x, y, w, h;
        x = 10;
        y = 50;
        w = QPOP_SCR_WIDTH - 20;
        h = QPOP_SCR_BUTTON_HEIGHT;

        VFX_OBJ_CREATE(m_rotateButton, VcpButton, this);
        m_rotateButton->setText(VFX_WSTR("rotate"));
        m_rotateButton->setPos(x, y);
        m_rotateButton->setSize(w, h);
        m_rotateButton->setId('Rota');
        m_rotateButton->m_signalClicked.connect(this, &VtstRtQuestionPopup::onButtonClick);

        y += QPOP_SCR_BUTTON_HEIGHT;

        VFX_OBJ_CREATE(m_changeIconButton, VcpButton, this);
        m_changeIconButton->setText(VFX_WSTR("Change text"));
        m_changeIconButton->setPos(x, y);
        m_changeIconButton->setSize(w, h);
        m_changeIconButton->setId('Icon');
        m_changeIconButton->m_signalClicked.connect(this, &VtstRtQuestionPopup::onButtonClick);
        
        y += QPOP_SCR_BUTTON_HEIGHT;

        VFX_OBJ_CREATE(m_changeButtonButton, VcpButton, this);
        m_changeButtonButton->setText(VFX_WSTR("Change Button"));
        m_changeButtonButton->setPos(x, y);
        m_changeButtonButton->setSize(w, h);
        m_changeButtonButton->setId('Butt');
        m_changeButtonButton->m_signalClicked.connect(this, &VtstRtQuestionPopup::onButtonClick);

        y += QPOP_SCR_BUTTON_HEIGHT;

        VFX_OBJ_CREATE(m_showButton, VcpButton, this);
        m_showButton->setText(VFX_WSTR("Show"));
        m_showButton->setPos(x, y);
        m_showButton->setSize(w, h);
        m_showButton->setId('Show');
        m_showButton->m_signalClicked.connect(this, &VtstRtQuestionPopup::onButtonClick);



        VFX_OBJ_CREATE(m_questionPopup, VcpQuestionPopup, this);
        //m_questionPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
        m_questionPopup->setText(VFX_WSTR("call 2"));
        m_questionPopup->addItem('Viki', VFX_WSTR("Viki"));
        m_questionPopup->setAutoDestory(VFX_FALSE);
        
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
                        //m_questionPopup->setInfoType(m_alertType);
                        m_questionPopup->setText(VFX_WSTR("FAIL!!!!"));
                    }
                    else if (m_alertType == VCP_POPUP_TYPE_INFO)
                    {
                        //m_questionPopup->setInfoType(m_alertType);
                        m_questionPopup->setText(VFX_WSTR("GOOD JOB!"));
                    }
                    else if (m_alertType == VCP_POPUP_TYPE_WARNING)
                    {
                        //m_questionPopup->setInfoType(m_alertType);
                        m_questionPopup->setText(VFX_WSTR("System overheat!?"));
                    }
                    else if (m_alertType == VCP_POPUP_TYPE_SUCCESS)
                    {
                        //m_questionPopup->setInfoType(m_alertType);
                        m_questionPopup->setText(VFX_WSTR("Venus MP pass~~\noh yeah"));
                    }
                    else if (m_alertType == VCP_POPUP_TYPE_PROGRESS)
                    {
                        //m_questionPopup->setInfoType(m_alertType);
                        m_questionPopup->setText(VFX_WSTR("Running please wait. If you don't we, you will get some trouble"));
                    }
                    else if (m_alertType == VCP_POPUP_TYPE_QUESTION)
                    {
                        //m_questionPopup->setInfoType(m_alertType);
                        m_questionPopup->setText(VFX_WSTR("Are you sure? Yes, I am show. the sure is not the show. You spell wrong. Your English should be improved. La La La"));
                    }
                }
                break;

            case 'Butt':
                {
                    if (m_count == 0)
                    {
                        m_questionPopup->addItem('Viki', VFX_WSTR("Viki"));
                    }
                    if (m_count == 1)
                    {
                        m_questionPopup->addItem('Leon', VFX_WSTR("Leona"));
                        m_questionPopup->disableItem('Leon');
                    }
                    if (m_count == 2)
                    {
                        m_questionPopup->addItem('Stel', VFX_WSTR("Stella"), VCP_POPUP_BUTTON_TYPE_WARNING);
                    }
                    if (m_count == 3)
                    {
                        m_questionPopup->addItem('Juli', VFX_WSTR("Julie"), VCP_POPUP_BUTTON_TYPE_WARNING);
                        m_questionPopup->disableItem('Juli');
                    }
                    if (m_count == 4)
                    {
                        m_questionPopup->addItem('Moll',VFX_WSTR("Mollie"), VCP_POPUP_BUTTON_TYPE_CANCEL);
                    }
                    if (m_count == 5)
                    {
                        m_questionPopup->addItem('Glor', VFX_WSTR("Glory"), VCP_POPUP_BUTTON_TYPE_CANCEL);
                        m_questionPopup->disableItem('Glor');
                        m_questionPopup->enableItem('Juli');
                    }
                    if (m_count == 6)
                    {
                        m_questionPopup->addItem('Anku', VFX_WSTR("Ankur"), VCP_POPUP_BUTTON_TYPE_CANCEL);
                    }
                    
                    m_count ++;
                    m_count%=VCP_QUESTION_POPUP_BUTTON_MAX_COUNT;
                }
                break;

            case 'Show':
                m_questionPopup->show(VFX_TRUE);
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
            confirm(VFX_WSTR("Question popup OK?"));
            return -1;
        }
        return VTST_RT_END_TESTCASE;
    }
};

VtstTestResultEnum vtst_rt_question_Popup(VfxU32 param)
{
    VTST_START_SCRN(VtstRtQuestionPopup);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

