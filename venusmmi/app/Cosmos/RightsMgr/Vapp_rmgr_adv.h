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
 *  Vapp_rmgr_adv.h
 *
 * Project:
 * --------
 *  VenusMMI
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
 *          HISTORY
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
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/


extern "C"
{
//#include "CommonScreens.h"
#include "GlobalDefs.h"
//#include "Drm_gprot.h"
}

#include "MMI_features.h" 
#include "vadp_mmi_frm.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"

#ifdef __MMI_RMGR__


class VfxAdvPage:public VfxPage
{
	VFX_DECLARE_CLASS(VfxAdvPage);
	void onSwitchVisibility(VcpFormItemSwitchCell* sender, VfxId id, VfxBool bState);

public:
      VfxSignal2 <VfxObject*, VfxBool> m_signalSwitchChanged;
	  	VcpFormItemSwitchCell *sc_cell;
#ifdef __DRM_SUPPORT_SCAN_DISK__		
	VcpFormItemSwitchCell *sd_cell;
#endif
protected:
	virtual void onInit();
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
};

#if defined(__MMI_MAINLCD_320X480__)
    #define VAPP_RMGR_SC_SWITCH_BUTTON_X 256
	#define VAPP_RMGR_SC_SWITCH_BUTTON_Y 13
    #define VAPP_RMGR_SD_SWITCH_BUTTON_X 256
	#define VAPP_RMGR_SD_SWITCH_BUTTON_Y 60
#elif (__MMI_MAINLCD_480X800__)
	#define VAPP_RMGR_SC_SWITCH_BUTTON_X 388
	#define VAPP_RMGR_SC_SWITCH_BUTTON_Y 22
	#define VAPP_RMGR_SD_SWITCH_BUTTON_X 388
	#define VAPP_RMGR_SD_SWITCH_BUTTON_Y 110
#elif (__MMI_MAINLCD_240X320__)
    #define VAPP_RMGR_SC_SWITCH_BUTTON_X 180
	#define VAPP_RMGR_SC_SWITCH_BUTTON_Y 13
	#define VAPP_RMGR_SD_SWITCH_BUTTON_X 180
	#define VAPP_RMGR_SD_SWITCH_BUTTON_Y 58
#elif (__MMI_MAINLCD_240X400__)
    #define VAPP_RMGR_SC_SWITCH_BUTTON_X 180
	#define VAPP_RMGR_SC_SWITCH_BUTTON_Y 13
	#define VAPP_RMGR_SD_SWITCH_BUTTON_X 180
	#define VAPP_RMGR_SD_SWITCH_BUTTON_Y 65
#else
	#define VAPP_RMGR_SC_SWITCH_BUTTON_X 250
	#define VAPP_RMGR_SC_SWITCH_BUTTON_Y 15
	#define VAPP_RMGR_SD_SWITCH_BUTTON_X 250
	#define VAPP_RMGR_SD_SWITCH_BUTTON_Y 60

#endif
#endif /* __MMI_RMGR__ */
