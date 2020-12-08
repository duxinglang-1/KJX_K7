/*****************************************************************************
*  Copyright Statement: 
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vcp_loading_popup.cpp
 *
 * Project:
 * --------
 *  COSMOS
 *
 * Description:
 * ------------
 *  App startup loading popup
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_loading_popup.h"
#include "vfx_frame.h"
#include "vfx_control.h"
#include "vfx_primitive_frame.h"
#include "vcp_activity_indicator.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifdef __MTK_TARGET__
	//#define __MAUI_SOFTWARE_LA__
#endif // __MTK_TARGET__
#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif 

/***************************************************************************** 
 * Class VcpSliderBarThumb
 *****************************************************************************/
 VFX_IMPLEMENT_CLASS("VcpLoadingPopup", VcpLoadingPopup, VfxBasePopup);

 VcpLoadingPopup::VcpLoadingPopup() :  
          m_actInd(NULL),     
          m_centerIcon(NULL)
    {
    }

 void VcpLoadingPopup::onInit()
 {
 
#if defined(__MAUI_SOFTWARE_LA__)
	 SLA_CustomLogging("LpI", SA_start); 
#endif	
     VfxBasePopup::onInit();

     setSize(VCP_LOADING_POPUP_DIAMETER, VCP_LOADING_POPUP_DIAMETER);     
     setAutoAnimate(VFX_TRUE);

     VFX_OBJ_CREATE(m_actInd, VcpActivityIndicator, this);
     m_actInd->setAnchor(0.5, 0.5);
     m_actInd->setPos(getSize().width/2, getSize().height/2);
     m_actInd->setSize(VCP_LOADING_POPUP_DIAMETER, VCP_LOADING_POPUP_DIAMETER);     
#if defined(__MAUI_SOFTWARE_LA__)
	 SLA_CustomLogging("LpI", SA_stop); 
#endif		 
 }
 
 void VcpLoadingPopup::setIcon(VfxImageSrc centerImg)
 {
    if(!m_centerIcon)
    {
        VFX_OBJ_CREATE(m_centerIcon, VfxImageFrame, this);
        m_centerIcon->setAnchor(0.5, 0.5);
        m_centerIcon->setPos(getSize().width/2, getSize().height/2);
        m_centerIcon->setSize(VCP_LOADING_POPUP_DIAMETER, VCP_LOADING_POPUP_DIAMETER);
    }
    m_centerIcon->setImgContent(centerImg);
 }

 void VcpLoadingPopup::onEnter()
 {
     VfxBasePopup::onEnter();
     setHidden(VFX_FALSE);
     bringToFront();
     m_actInd->start();
 }

 void VcpLoadingPopup::onExit()
 {
     m_actInd->stop();
     setHidden(VFX_TRUE);
     VfxBasePopup::onExit();
 }

 VfxBool VcpLoadingPopup::onPenInput(VfxPenEvent &event)
{
    return VFX_TRUE;
}
