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
 *  vtst_rt_loading_popup.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for VcpLoadingPopup
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
#include "vcp_loading_popup.h"
#include "vcp_button.h"
#include "GlobalResDef.h"

/***************************************************************************** 
 * Control Test Implementation
 *****************************************************************************/

class VtstRtLoadingPopup: public VtstRtScr
{ 
// Variable
public:
	VcpLoadingPopup *m_startInd;
    VfxTimer *m_timer;
    VcpButton *m_launchButton;

// Constructor / Destructor
public:
    VtstRtLoadingPopup()
    {
    }
    
    void onInit()
    {
        VtstRtScr::onInit();     
        setBgColor(VFX_COLOR_WHITE);
        
        VFX_OBJ_CREATE(m_startInd, VcpLoadingPopup, this);
        m_startInd->setIcon(VfxImageSrc(IMG_GLOBAL_L1));
        
        VFX_OBJ_CREATE(m_launchButton, VcpButton, this);
        m_launchButton->setAnchor(0.5, 0.0);
        m_launchButton->setPos(getSize().width/2, 50);
        m_launchButton->setSize(200, 70);
        m_launchButton->setText(VFX_WSTR("Launch me"));
        m_launchButton->m_signalClicked.connect(this, &VtstRtLoadingPopup::onLaunch);
        
        VFX_OBJ_CREATE(m_timer, VfxTimer, this);
        m_timer->setStartDelay(5000);
        m_timer->m_signalTick.connect(this, &VtstRtLoadingPopup::onTimerCallBack);
    }

    void onLaunch(VfxObject *btn, VfxId id)
    {
        m_startInd->show(VFX_TRUE);
        m_timer->start();
    }

    void onTimerCallBack(VfxTimer *tm)
    {
        m_startInd->hide(VFX_TRUE);
        m_timer->stop();
    }

   virtual VfxS32 phase(VfxS32 idx)
    {
        setTitle(VFX_WSTR("Loading Popup Test"));
        confirm(VFX_WSTR("Result is correct?"));
        
        return -1;
    }

    virtual VfxS32 start() {return 1;}
};

VtstTestResultEnum vtst_rt_loading_popup(VfxU32 param)
{
    VTST_START_SCRN(VtstRtLoadingPopup);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__






