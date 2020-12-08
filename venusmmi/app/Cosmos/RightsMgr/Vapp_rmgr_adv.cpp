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
 *  Vapp_rmgr_adv.cpp
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Advanced options screen of Rights Manager
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
 * removed!
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
#include "Drm_gprot.h"
#include "Drm_def.h"
#include "GlobalConstants.h"
#include "RightsMgrProt.h"
#include "Vapp_rmgr_cntx.h"
#include "Drm_memory.h"
}

#ifdef __MMI_RMGR__

#include "MMI_features.h" 
#include "vadp_mmi_frm.h"
#include "vfx_uc_include.h"
extern "C"
{
//#include "CommonScreens.h"
#include "GlobalDefs.h"
#include "Drm_gprot.h"
#include "Drm_def.h"
#include "GlobalConstants.h"
#include "RightsMgrProt.h"
#include "Vapp_rmgr_cntx.h"
#include "Drm_memory.h"
#include "FileManagerDef.h"
#include "FileManagerGprot.h"
#include "Vapp_rmgr_service.h"
#include "TimerEvents.h"
}

#include "MMI_features.h" 
#include "vadp_mmi_frm.h"
#include "vfx_uc_include.h"
#include "vcp_text_view.h"
#include "vcp_app_scr.h"
#include "vcp_include.h"
#include "ui_core\mvc\vfx_mmi.h"
#include "vtst_rt_main.h"
#include "vcp_status_icon_bar.h"
#include "vcp_page_panel.h"
#include "vcp_list_menu.h"
#include "vcp_popup.h"
#include "vcp_image_button.h"
#include "vcp_form.h"
#include "vapp_rmgr_util.h"
#include "Vapp_rmgr_adv.h"
#include "mmi_rp_vapp_rmgr_def.h"

#ifdef __DRM_SUPPORT_SCAN_DISK__
	extern "C" void mmi_rmgr_toggle_scan_disk();
#endif



	extern "C" void mmi_rmgr_db_chk_toggle();

VcpSegmentButton *sc_butt, *sd_butt;
VFX_IMPLEMENT_CLASS("VfxAdvPage",VfxAdvPage,VfxPage);

U8 rmgr_vfx_spc_tgl;
U8 vapp_rmgr_space_chk_user=1;


enum ScanDiskbutton
{
	SPACE_CHK_OFF,
	SPACE_CHK_ON,
	SCAN_DISK_OFF,
	SCAN_DISK_ON
};

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
		#ifdef __DRM_MTK__
/* under construction !*/
    #if defined(MAX_DRM_DB_SIZE) && defined(__FS_QM_SUPPORT__) && (MAX_DRM_DB_SIZE != 0)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else /* defined(MAX_DRM_DB_SIZE) && defined(__FS_QM_SUPPORT__) && (MAX_DRM_DB_SIZE != 0) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(MAX_DRM_DB_SIZE) && defined(__FS_QM_SUPPORT__) && (MAX_DRM_DB_SIZE != 0) */ 
/* under construction !*/
    #else /* __DRM_MTK__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __DRM_SUPPORT_SCAN_DISK__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __DRM_SUPPORT_SCAN_DISK__
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __DRM_SUPPORT_SCAN_DISK__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __DRM_SUPPORT_SCAN_DISK__
/* under construction !*/
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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


void VfxAdvPage::onInit()
{
	VfxPage::onInit();
	//setBgcolor(VFX_COLOR_WHITE);
	VcpForm *adv_form;

	
	VcpTitleBar *m_title;
	VFX_OBJ_CREATE(m_title, VcpTitleBar, this);
	m_title->setPos(VfxPoint(VAPP_RMGR_POS_TITLE_X,VAPP_RMGR_POS_TITLE_Y));
	m_title->setTitle(VFX_WSTR_RES(STR_ID_RMGR_ADVANCED));
	m_title->setTitleStyle(VCP_TITLE_BAR_STYLE_BASE);
	setTopBar(m_title);
 

	 VFX_OBJ_CREATE(adv_form, VcpForm, this);
     adv_form->setSize(getSize());

	  	VFX_OBJ_CREATE(sc_cell, VcpFormItemSwitchCell, adv_form);
    	sc_cell->setMainText(VFX_WSTR_RES(STR_ID_RMGR_SPACE_CHECK));
    	//sc_cell->setAccessory(VCPFORM_NEXT_ITEM_ICON);
        //sc_cell->m_signalTap.connect(this, &VtstSampleSettingMainPage::onButtonClicked);
		sc_cell->m_signalSwitchChangeReq.connect(this, &VfxAdvPage::onSwitchVisibility);
        adv_form->addItem(sc_cell,0);

#ifdef __DRM_SUPPORT_SCAN_DISK__
	    VFX_OBJ_CREATE(sd_cell, VcpFormItemSwitchCell, adv_form);
    	sd_cell->setMainText(VFX_WSTR_RES(STR_ID_RMGR_SCAN_DISK));
    	//sd_cell->setAccessory(VCPFORM_NEXT_ITEM_ICON);
        //sd_cell->m_signalTap.connect(this, &VtstSampleSettingMainPage::onButtonClicked);
		sd_cell->m_signalSwitchChangeReq.connect(this, &VfxAdvPage::onSwitchVisibility);
        adv_form->addItem(sd_cell,1);
#endif // __DRM_SUPPORT_SCAN_DISK__    

U8 rmgr_vfx_spc_tgl=vapp_get_rmgr_spc();
       if(rmgr_vfx_spc_tgl)
   {
       sc_cell->setSwitchStatus(VFX_TRUE);
   }
   else
   {
		 sc_cell->setSwitchStatus(VFX_FALSE);
   }


#ifdef __DRM_SUPPORT_SCAN_DISK__

     if (mmi_rmgr_p->allow_scan_disk == MMI_TRUE)
  {
		 sd_cell->setSwitchStatus(VFX_TRUE);
  }
  else
    {
       sd_cell->setSwitchStatus(VFX_FALSE);
   }
  #endif  // __DRM_SUPPORT_SCAN_DISK__
}

	

void VfxAdvPage::onSwitchVisibility(VcpFormItemSwitchCell* sender, VfxId id, VfxBool bState)
{
	if(!id)
{
	 mmi_rmgr_db_chk_toggle();
        sc_cell->setSwitchStatus(!sc_cell->getSwitchStatus());
}
#ifdef __DRM_SUPPORT_SCAN_DISK__	
	else 
{
	sd_cell->setSwitchStatus(!sd_cell->getSwitchStatus());
#ifdef __DRM_SUPPORT_SCAN_DISK__
	             vapp_rmgr_set_del_item(VFX_TRUE);
		      	 mmi_rmgr_toggle_scan_disk();
#endif
	}
#endif  //__DRM_SUPPORT_SCAN_DISK__
}



/**************** for scan-disk ***************************/


#endif /* __MMI_RMGR__*/
