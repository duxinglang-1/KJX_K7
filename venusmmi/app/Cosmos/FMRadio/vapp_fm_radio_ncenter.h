/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   vapp_fm_radio_ncenter.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  FM Radio NCenter header file
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_FM_RADIO_NCENTER_H__
#define __VAPP_FM_RADIO_NCENTER_H__

#include "MMI_features.h"

#if defined(__MMI_NCENTER_SUPPORT__)

#ifdef __cplusplus
extern "C"
{
#endif
#include "mmi_cb_mgr_gprot.h"
#ifdef __cplusplus
}
#endif

#include "vsrv_notification.h"
#include "vsrv_ncenter.h"
#include "vcp_include.h"
#include "../cosmos/Widget/vapp_widget_fm_radio.h"

/***************************************************************************** 
 * Pre-declaration
 *****************************************************************************/

/***************************************************************************** 
 * Class VappFmRadioNCell    
 *****************************************************************************/
class VappFmRadioNCell : public VsrvNCell
{
    VFX_DECLARE_CLASS(VappFmRadioNCell);        

// Constants
public:

    enum NCellSizeEnum
    {
        FM_NCELL_WIDTH = VAPP_NCENTER_ONGOING_CELL_WIDTH,
    #ifdef __MMI_MAINLCD_480X800__
        FM_NCELL_HEIGHT = 167
    #elif __MMI_MAINLCD_320X480__
        FM_NCELL_HEIGHT = 101
    #else // __MMI_MAINLCD_240X320__ || __MMI_MAINLCD_240X400__
        FM_NCELL_HEIGHT = 93 
    #endif
    };
    
// Override
public:
    // create your UI
    virtual void onCreateView(void* viewData, VfxU32 viewDataSize); 

    // close your UI
    virtual void onCloseView();    
    
    // process your intent
    virtual void onProcessIntent(VsrvNotification* noti, VsrvNIntent intent, void* viewData, VfxU32 viewDataSize);    
    
// Method
public:
    // close FM Radio NCell
    void onCloseButtonClicked(VfxObject* sender, VfxId id);

// Variable
private:    
    VappWidgetFmRadioPanel *m_fmPanel;
    VcpImageButton         *m_closeButton;
};

#endif /* defined(__MMI_NCENTER_SUPPORT__) */
#endif /*__VAPP_FM_RADIO_NCENTER_H__*/
