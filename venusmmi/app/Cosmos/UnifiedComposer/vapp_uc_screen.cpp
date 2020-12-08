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
 *  vapp_uc_screen.cpp
 *
 * Project:
 * --------
 *  Venus Golden Sample : UC
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
#include "MMI_features.h" 
#include "vapp_msg_features.h"

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
#include "vfx_uc_include.h"
#include "vcp_form.h"
#include "vcp_tabctrl_page.h"
#include "vcp_navi_title_bar.h"

#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vcp_popup.h"
#include "vcp_form.h"
#include "vcp_button_util.h"
#include "vapp_uc_gprot.h"
#include "vapp_uc_prot.h"
#include "mmi_rp_vapp_unifiedcomposer_def.h"
#include "..\..\xml\vfx_xml_loader.h"  // For XML
#include "vapp_text_template_scrn.h"
#include "vapp_mms_gprot.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "vapp_uc_emontics.h"
#ifdef __MMI_EMAIL__
#include "..\Email\vapp_email_composer.h"
#include "..\Email\vapp_email_msg_view.h"
#endif
#include "..\Contact\ContactCore\vapp_contact_entry.h"
#if defined(__MMI_VCARD__)
#include "..\Contact\ContactCore\vapp_contact_vcard.h"  //Vcard CUI interface, will be changed once vcard moves the prototypes to CUI interface folder (10.52)
#endif
#include "mmi_features_camcorder.h"
#include "vapp_cal_view_detail_ext_gprot.h"
#ifdef __MMI_VUI_COSMOS_CP__
#include "mmi_rp_app_cosmos_global_def.h"
#endif
/*kuldeep_gplus*/
#include "vapp_sim_setting_gprot.h"
#ifdef __MMI_USB_SUPPORT__
#include "mmi_rp_app_usbsrv_def.h"
#endif


extern "C"
{
	#include "wapadp.h"
	#include "app_mine.h"
	#include "MmsSrvGprot.h"
	#include "UcSrvGprot.h"
    #include "UcSrvIprot.h"
	#include "FileMgr.h"
	#include "FileMgrCUIGProt.h"
	#include "UCMGProt.h"
	#include "UcmSrvGprot.h"
	#include "..\interface\cui\vcui_soundrec_gprot.h"
	#include "..\interface\cui\vcui_gallery_gprot.h"
	#include "..\interface\cui\vapp_fmgr_cui_gprot.h"
	#include "..\interface\cui\vcui_music_player_gprot.h"
	#include "..\interface\cui\vcui_phb_gprot.h"
	#include "..\interface\cui\vcui_camco_gprot.h"
	#include "vcui_cal_list_gprot.h" 
	//#include "..\interface\cui\vapp_bookmark_cui_gprot.h"
	#include "vcui_bookmark_gprot.h"
	#include "custom_phb_config.h"
	#include "PhbSrvGprot.h"  //temp include 
	#include "CustMenuRes.h"
	#include "app_asyncfile.h"
	#include "DtcntSrvGprot.h"

    #include "SimCtrlSrvGprot.h"
    #include "ModeSwitchSrvGProt.h"
}



/*****************************************************************************
 * Macro Implementation
 *****************************************************************************/
#define VAPP_UC_TWO_ITEM_MARGIN_LARGE VCPFRM_SIDE_MARGIN_LARGE
#define VAPP_UC_TWO_ITEM_MARGIN_SMALL VCPFRM_SIDE_MARGIN_SMALL
#define VAPP_UC_LEFT_MARGIN (VCPFRM_INDENT_L1 + VCPFRM_INDENT_L2)
#define VAPP_UC_ITEM_HORZ_GAP VCPFRM_ITEM_HORZ_GAP
#define VAPP_UC_STANDARD_BTN_HEIGHT VCPFRM_STANDARD_BTN_HEIGHT

#if defined(__MMI_MAINLCD_320X480__)
#define VAPP_UC_MSG_VIEW_CONT_LINE_HEIGHT                     36
#elif defined(__MMI_MAINLCD_480X800__)
#define VAPP_UC_MSG_VIEW_CONT_LINE_HEIGHT                     60
#else
#define VAPP_UC_MSG_VIEW_CONT_LINE_HEIGHT                     32
#endif

extern U8 initial_launch_mode;
#ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__
extern VappUcAppDataAfterSerialize g_uc_app_data_serialized[MAX_UC_INSTANCES]; 
#endif

#ifndef MMS_SUPPORT

#include "FileMgrSrvGProt.h"
#include "FileMgrType.h"
/*****************************************************************************
 * FUNCTION
 *  mma_uc_set_file_mgr_filter_for_image
 * DESCRIPTION
 *  Set the image filter
 * PARAMETERS
 *  filter      [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_uc_set_file_mgr_filter_for_image(FMGR_FILTER *filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(filter);

    FMGR_FILTER_SET(filter, FMGR_TYPE_BMP);
    FMGR_FILTER_SET(filter, FMGR_TYPE_GIF);
    FMGR_FILTER_SET(filter, FMGR_TYPE_WBM);
    FMGR_FILTER_SET(filter, FMGR_TYPE_WBMP);
#ifdef GDI_USING_PNG
    FMGR_FILTER_SET(filter, FMGR_TYPE_PNG);
#endif 
#ifdef JPG_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_JPG);
    FMGR_FILTER_SET(filter, FMGR_TYPE_JPEG);
#endif /* JPG_DECODE */ 
#ifdef SVG_SUPPORT
    FMGR_FILTER_SET(filter, FMGR_TYPE_SVG);
#endif 

    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
}

static void mma_uc_set_file_mgr_filter_for_audio(FMGR_FILTER *filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(filter);

    FMGR_FILTER_SET(filter, FMGR_TYPE_IMY);
    FMGR_FILTER_SET(filter, FMGR_TYPE_MID);
    FMGR_FILTER_SET(filter, FMGR_TYPE_MIDI);
    FMGR_FILTER_SET(filter, FMGR_TYPE_WAV);
    FMGR_FILTER_SET(filter, FMGR_TYPE_AMR);
    // FMGR_FILTER_SET(filter, FMGR_TYPE_VM);   /* cannot get duration */
#ifdef AAC_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_AAC);
#endif 
#ifdef DAF_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_DAF);
#endif 
    
#ifdef  __RM_DEC_SUPPORT__
   FMGR_FILTER_SET(filter, FMGR_TYPE_RA); 
#endif
#ifdef AMRWB_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_AWB);
#endif 
#ifndef __CPU_ARM7TDMI__ /* MT6205B */
    FMGR_FILTER_SET(filter, FMGR_TYPE_AIF);
    FMGR_FILTER_SET(filter, FMGR_TYPE_AIFF);
    FMGR_FILTER_SET(filter, FMGR_TYPE_AIFC);
    FMGR_FILTER_SET(filter, FMGR_TYPE_AU);
    FMGR_FILTER_SET(filter, FMGR_TYPE_SND);
#endif /* __CPU_ARM7TDMI__ *//* MT6205B */ 
#if defined(M4A_DECODE)
    FMGR_FILTER_SET(filter, FMGR_TYPE_M4A);
#endif 
#if defined(EXT_AUDIO_CHIP) || defined(MMF_DECODE)
    FMGR_FILTER_SET(filter, FMGR_TYPE_MMF);
#endif 
#ifdef WMA_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_WMA);
#endif 
#ifdef MUSICAM_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_MP2);
#endif 

#if !defined (MP4_DECODE) && defined(__MMI_PURE_AUDIO__)
    FMGR_FILTER_SET(filter, FMGR_TYPE_3GP);
    FMGR_FILTER_SET(filter, FMGR_TYPE_MP4);
    FMGR_FILTER_SET(filter, FMGR_TYPE_3G2);
#endif
#ifdef __APE_DECODE__
	    FMGR_FILTER_SET(filter, FMGR_TYPE_APE);
#endif

    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
}
static void mma_uc_set_file_mgr_filter_for_video(FMGR_FILTER *filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(filter);
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
#ifdef MP4_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_3GP);
    FMGR_FILTER_SET(filter, FMGR_TYPE_MP4);
    FMGR_FILTER_SET(filter, FMGR_TYPE_3G2);
#endif /* MP4_DECODE */ 
#ifdef __RM_DEC_SUPPORT__
    FMGR_FILTER_SET(filter, FMGR_TYPE_RV);
    FMGR_FILTER_SET(filter, FMGR_TYPE_RM);
    FMGR_FILTER_SET(filter, FMGR_TYPE_RMVB);
#endif /* __RM_DEC_SUPPORT__ */ 

#ifdef __FLV_FILE_FORMAT_SUPPORT__
	 FMGR_FILTER_SET(filter, FMGR_TYPE_FLV); 				/*!< F4A Audio */
	 FMGR_FILTER_SET(filter, FMGR_TYPE_F4V);
#endif


#ifdef MJPG_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_AVI);
#endif 
#endif
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
}


/*****************************************************************************
 * FUNCTION
 *  mma_uc_set_file_mgr_filter_for_attachment
 * DESCRIPTION
 *  Set the attachment filter
 * PARAMETERS
 *  filter      [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_uc_set_file_mgr_filter_for_attachment(FMGR_FILTER *filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(filter);

    FMGR_FILTER_SET_ALL(filter);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
    FMGR_FILTER_CLEAR(filter, FMGR_TYPE_DM);
}
/*****************************************************************************
 * FUNCTION
 *  mma_uc_set_file_mgr_filter
 * DESCRIPTION
 *  Get free file space
 * PARAMETERS
 *  filter                      [IN]         
 *  media_type_to_insert        [IN]        
 * RETURNS
 *  free space(?)
 *****************************************************************************/
void mma_uc_set_file_mgr_filter(void *filter, mma_uc_filter_mode_enum media_type_to_insert)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (media_type_to_insert)
    {
        case MMA_UC_FILTER_MODE_IMAGE_OPEN_MODE:
        case MMA_UC_FILTER_MODE_IMAGE_RESTRICTED_MODE:
			mma_uc_set_file_mgr_filter_for_image((FMGR_FILTER*) filter);
            break;

        case MMA_UC_FILTER_MODE_AUDIO_OPEN_MODE:
        case MMA_UC_FILTER_MODE_AUDIO_RESTRICTED_MODE:
			mma_uc_set_file_mgr_filter_for_audio((FMGR_FILTER*) filter);
            break;

        case MMA_UC_FILTER_MODE_VIDEO_OPEN_MODE:
        case MMA_UC_FILTER_MODE_VIDEO_RESTRICTED_MODE:
			mma_uc_set_file_mgr_filter_for_video((FMGR_FILTER*) filter);
            break;

        case MMA_UC_FILTER_MODE_ATTACHMENT_OPEN_MODE:
        case MMA_UC_FILTER_MODE_ATTACHMENT_RESTRICTED_MODE:
			mma_uc_set_file_mgr_filter_for_attachment((FMGR_FILTER*) filter);
            break;

        case MMA_UC_FILTER_MODE_TEXT_OPEN_MODE:
        case MMA_UC_FILTER_MODE_TEXT_RESTRICTED_MODE:
            break;
    }

    return;
}

#endif

/***************************************************************************** 
 * Class VtstSampleAddContactHeaderItem
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappUCMediaItem", VappUCMediaItem, VfxControl);

VFX_IMPLEMENT_CLASS("VappUCSlideBarItem", VappUCSlideBarItem, VfxControl);


void VappUCSlideBarItem::onInit()
{
	VfxSize parentSize;

	VfxControl::onInit();
	if (m_parentPageSize.width > 0 &&  m_parentPageSize.height > 0)
	{
		parentSize = m_parentPageSize;
	}
	else
	{
		vrt_size_struct mainScreenSize;
		vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
		parentSize.width = mainScreenSize.width;
		parentSize.height = mainScreenSize.height;
	}

	 setSize((parentSize.width), VAPP_UC_STANDARD_BTN_HEIGHT + (2 * VCPFRM_ITEM_HORZ_GAP));
    //setSize((VcpForm *)(getParent())->getSize()->width, VAPP_UC_STANDARD_BTN_HEIGHT + (2 * GAP));

    VfxS32 x = VAPP_UC_LEFT_MARGIN;
    VfxS32 y = VCPFRM_ITEM_HORZ_GAP;

    // create button image
    VFX_OBJ_CREATE(btn, VcpButton, this);
    btn->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    btn->setImage(VcpStateImage(IMG_COSMOS_BUTTON_ARROW_LEFT));
    btn->setIsAutoResized(VFX_FALSE, 0, 0);
    btn->setAnchor(0, 0);
    btn->setPos(x, y);
	btn->setSize(VAPP_UC_STANDARD_BTN_HEIGHT, VAPP_UC_STANDARD_BTN_HEIGHT);
	/*for rotation*/
	btn->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
						VFX_FRAME_ALIGNER_MODE_NONE, 
						VFX_FRAME_ALIGNER_MODE_NONE,
						VFX_FRAME_ALIGNER_MODE_NONE);


	x += btn->getSize().width + VAPP_UC_TWO_ITEM_MARGIN_SMALL;
    y = VCPFRM_ITEM_HORZ_GAP * 2;

    // create last name text
    VFX_OBJ_CREATE(m_title, VfxTextFrame, this);
  //  m_title->setString(VFX_WSTR("Media Name"));
    m_title->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
	//m_title->setAnchor(0, 0.5);
	 m_title->setPos(x, y);
	m_title->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VCPFRM_FONT_SIZE_3)));
	m_title->setSize( (parentSize.width) - (VAPP_UC_LEFT_MARGIN*2 + VAPP_UC_STANDARD_BTN_HEIGHT*3 + VAPP_UC_TWO_ITEM_MARGIN_SMALL), m_title->getSize().height);
    m_title->setAutoResized(VFX_FALSE);
	m_title->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
	/*for rotation*/
	m_title->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
						VFX_FRAME_ALIGNER_MODE_NONE, 
						VFX_FRAME_ALIGNER_MODE_SIDE,
						VFX_FRAME_ALIGNER_MODE_NONE);

    x = getSize().width - VAPP_UC_LEFT_MARGIN;
    y = VCPFRM_ITEM_HORZ_GAP;

	// create edit button

    VFX_OBJ_CREATE(btn1, VcpButton, this);
    btn1->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    btn1->setImage(VcpStateImage(IMG_COSMOS_BUTTON_ARROW_RIGHT));
    btn1->setIsAutoResized(VFX_FALSE, 0, 0);
    btn1->setAnchor(0, 0);
    btn1->setPos(x - VAPP_UC_STANDARD_BTN_HEIGHT, y);
    btn1->setSize(VAPP_UC_STANDARD_BTN_HEIGHT, VAPP_UC_STANDARD_BTN_HEIGHT);

	/*for rotation*/
	btn1->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE, 
						VFX_FRAME_ALIGNER_MODE_NONE, 
						VFX_FRAME_ALIGNER_MODE_SIDE,
						VFX_FRAME_ALIGNER_MODE_NONE);

    // create edit button
    VFX_OBJ_CREATE(btn2, VcpButton, this);
    btn2->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    btn2->setImage(VcpStateImage(IMG_ID_VAPP_UC_OPTION_ID));
    btn2->setIsAutoResized(VFX_FALSE, 0, 0);
    btn2->setAnchor(0, 0);
    btn2->setPos(x - (btn1->getSize().width * 2) - VAPP_UC_TWO_ITEM_MARGIN_SMALL, y);
    btn2->setSize(VAPP_UC_STANDARD_BTN_HEIGHT, VAPP_UC_STANDARD_BTN_HEIGHT);
    btn2->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE, 
				    VFX_FRAME_ALIGNER_MODE_NONE, 
				    VFX_FRAME_ALIGNER_MODE_SIDE,
				    VFX_FRAME_ALIGNER_MODE_NONE);
}


void VappUCSlideBarItem::setText(const VfxWString& string)
{
    m_title->setString(string);
    checkUpdate();
}

void VappUCSlideBarItem::onUpdate()
{
    // TODO: resize both text
}


VFX_IMPLEMENT_CLASS("VappUCSingleAttachmentButtonItem", VappUCSingleAttachmentButtonItem, VfxControl);


void VappUCSingleAttachmentButtonItem::onInit()
{
    VfxSize parentSize;
	VfxS32 tempHeight = 0;
	VfxControl::onInit();

    
    VappUCMainScr* scr  = VFX_OBJ_DYNAMIC_CAST(VfxMainScr::findMainScr((VfxFrame*)getParent()), VappUCMainScr); 
    
	if (scr != NULL)
	{
		VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
        app->ucSetRefMediaCount();
    }

	if (m_parentPageSize.width > 0 &&  m_parentPageSize.height > 0)
	{
		parentSize = m_parentPageSize;
	}
	else
	{
		vrt_size_struct mainScreenSize;
		vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
		parentSize.width = mainScreenSize.width;
		parentSize.height = mainScreenSize.height;
	}



  //  setAnchor( 0, 0);
    setPos(0, 0);
    setSize(parentSize.width, (VAPP_UC_STANDARD_BTN_HEIGHT + VCPFRM_ITEM_HORZ_GAP));

	if(need_gap)
	{
		tempHeight = VCPFRM_ITEM_HORZ_GAP;
	}

    VFX_OBJ_CREATE(m_title, VcpButton, this);
    m_title->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY_LEFT);
  //  m_title->setStyle(VCP_BUTTON_STYLE_NORMAL);
 //   m_title->setSize(getSize().width - (VAPP_UC_STANDARD_BTN_HEIGHT + VCPFRM_LEFT_INDENT_L1 + VCPFRM_LEFT_INDENT_L2 + (VAPP_UC_TWO_ITEM_MARGIN_SMALL * 2)), VAPP_UC_STANDARD_BTN_HEIGHT);
	   m_title->setSize(getSize().width - (VAPP_UC_STANDARD_BTN_HEIGHT + (VAPP_UC_LEFT_MARGIN*2) + (VAPP_UC_TWO_ITEM_MARGIN_SMALL)), VAPP_UC_STANDARD_BTN_HEIGHT);
    m_title->setId(VAPP_UC_ATTACHMENT_PREVIEW_BTN_ID);
    m_title->setPos(VAPP_UC_LEFT_MARGIN, tempHeight);
    m_title->m_signalClicked.connect(this, &VappUCSingleAttachmentButtonItem::ucPreviewRemoveSingleAttachment);
	m_title->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_NONE, 
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_NONE);

    
    VcpCancelButton* btn;
    VFX_OBJ_CREATE(btn, VcpCancelButton, this);
    btn->setSize(VAPP_UC_STANDARD_BTN_HEIGHT, VAPP_UC_STANDARD_BTN_HEIGHT);
    btn->setPos( getSize().width - (btn->getSize().width + VAPP_UC_LEFT_MARGIN), tempHeight);     
    btn->m_signalClicked.connect(this, &VappUCSingleAttachmentButtonItem::ucPreviewRemoveSingleAttachment);
    btn->setId(VAPP_UC_ATTACHMENT_REMOVE_BTN_ID);
  
	btn->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE, 
        VFX_FRAME_ALIGNER_MODE_NONE, 
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_NONE);
}


void VappUCSingleAttachmentButtonItem::ucPreviewRemoveSingleAttachment(VfxObject*sender, VfxId btnId)
{
	
    VappUCMainScr* scr  = VFX_OBJ_DYNAMIC_CAST(VfxMainScr::findMainScr((VfxFrame*)getParent()), VappUCMainScr); 
	if (scr != NULL)
	{
		VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
		if (btnId == VAPP_UC_ATTACHMENT_REMOVE_BTN_ID)
		{
			app->VappUCRemoveAttachment(0);
			scr->connectOnPage();
		}
		else if (btnId == VAPP_UC_ATTACHMENT_PREVIEW_BTN_ID)
		{
		   scr->VappUCPreviewAttachment(0);
		}
	}
	else
	{
		ASSERT(0);
	}
}
void VappUCSingleAttachmentButtonItem::onButtonClicked(VfxObject* obj, VfxId id)
{

}
void VappUCSingleAttachmentButtonItem::setText(const VfxWString& string)
{
    m_title->setText(string);
    checkUpdate();
}

void VappUCSingleAttachmentButtonItem::onUpdate()
{
    // TODO: resize both text
}


VFX_IMPLEMENT_CLASS("VappUCAttachmentButtonItem", VappUCAttachmentButtonItem, VfxControl);


void VappUCAttachmentButtonItem::onInit()
{
    VfxSize parentSize;
	VfxS32 tempHeight = 0;

	if (m_parentPageSize.width > 0 &&  m_parentPageSize.height > 0)
	{
		parentSize = m_parentPageSize;
	}
	else
	{
		vrt_size_struct mainScreenSize;
		vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
		parentSize.width = mainScreenSize.width;
		parentSize.height = mainScreenSize.height;

	}

    VfxControl::onInit();
    if (need_gap)
	{
		tempHeight = VCPFRM_ITEM_HORZ_GAP;
	}
    setAnchor(0.5, 0);
    setPos(m_parentPageSize.width/ 2, 0);
    setSize((parentSize.width /*- (VAPP_UC_TWO_ITEM_MARGIN_SMALL * 2)*/), (VAPP_UC_STANDARD_BTN_HEIGHT + VCPFRM_ITEM_HORZ_GAP));

    // create arrow button as base
    VFX_OBJ_CREATE(btn, VcpArrowButton, this);
    btn->setAnchor(0, 0);
  //  btn->setStyle(VCP_BUTTON_STYLE_NORMAL);
    btn->setSize((parentSize.width - (VAPP_UC_LEFT_MARGIN * 2)), VAPP_UC_STANDARD_BTN_HEIGHT);
    btn->setPos(VAPP_UC_LEFT_MARGIN, tempHeight);

	btn->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
					VFX_FRAME_ALIGNER_MODE_NONE, 
					VFX_FRAME_ALIGNER_MODE_SIDE,
					VFX_FRAME_ALIGNER_MODE_NONE);
}


void VappUCAttachmentButtonItem::setText(const VfxWString& string)
{
	btn->setText(string);    
    checkUpdate();
}


void VappUCAttachmentButtonItem::setHint(const VfxWString& string)
{
//    m_hint->setString(string);
 //   checkUpdate();
}

void VappUCAttachmentButtonItem::onButtonClicked(VfxObject* obj, VfxId id)
{
	//VAppUcAttachmentlistPage *attachmentPage;
	//VFX_OBJ_CREATE(attachmentPage, VAppUcAttachmentlistPage, getParent());
//	getMainScr()->pushPage(0, attachmentPage);
}

void VappUCAttachmentButtonItem::onUpdate()
{
    // TODO: resize both text
}

void VappUCMediaItem::onInit()
{
	VfxSize parentSize;

	VfxControl::onInit();
	if (m_parentPageSize.width > 0 &&  m_parentPageSize.height > 0)
	{
		parentSize = m_parentPageSize;
	}
	else
	{
		vrt_size_struct mainScreenSize;
		vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
		parentSize.width = mainScreenSize.width;
		parentSize.height = mainScreenSize.height;
	}

    setSize(parentSize.width /*- (VAPP_UC_TWO_ITEM_MARGIN_SMALL * 2))*/, (VAPP_UC_STANDARD_BTN_HEIGHT + VCPFRM_ITEM_HORZ_GAP * 3));

    VFX_OBJ_CREATE(m_MediaBase, VcpButton, this);
    m_MediaBase->setSize(getSize().width - (VAPP_UC_LEFT_MARGIN * 2), VAPP_UC_STANDARD_BTN_HEIGHT + VCPFRM_ITEM_HORZ_GAP * 2);
    m_MediaBase->setPos(VAPP_UC_LEFT_MARGIN, 0);
	
	/*for rotation*/

	m_MediaBase->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_NONE, 
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_NONE);

    VfxS32 x = VCPFRM_ITEM_HORZ_GAP;
    VfxS32 y = VCPFRM_ITEM_HORZ_GAP;

    VfxWString itemText;
    VFX_OBJ_CREATE(img, VfxImageFrame, m_MediaBase);
    if (m_object && (m_type == SRV_UC_OBJECT_TYPE_IMAGE))
    {
        if(m_object->drm_type == MMA_DRM_NONE || m_object->drm_type == MMA_DRM_SD)
        {
            img->setPath(m_filePath);
        }
        else
        {
    #ifdef __DRM_SUPPORT__
            img->setResId(IMG_ID_VAPP_UC_DRM_DEFAULT_ID);
    #endif
        }
        img->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
    }
    else if (m_type == SRV_UC_OBJECT_TYPE_AUDIO)
    {
        img->setResId(IMG_ID_VAPP_UC_AUDIO_FILE_ID);
    }
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
    else if (m_type == SRV_UC_OBJECT_TYPE_VIDEO)
    {
        img->setResId(IMG_ID_VAPP_UC_VIDEOFILE__ID);
    }
#endif    
    else  if(m_type == SRV_UC_OBJECT_TYPE_ATTACHMENT)
    {
       /* This is case when VCard & VCalendar come as attachment in SMS. So, them as inline */
       /* Will update the resource ID later */
       img->setResId(vapp_get_icon_according_to_media_type((VfxWChar*)m_object->file_name_ucs));
    }
    // create thumbnail image
    {
        img->setPos(x, y);
        img->setBounds(VfxRect(0, 0, VAPP_UC_STANDARD_BTN_HEIGHT, VAPP_UC_STANDARD_BTN_HEIGHT));
        img->setSize(VAPP_UC_STANDARD_BTN_HEIGHT, VAPP_UC_STANDARD_BTN_HEIGHT);
			/*for rotation*/ 
		img->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
								VFX_FRAME_ALIGNER_MODE_NONE, 
								VFX_FRAME_ALIGNER_MODE_NONE,
								VFX_FRAME_ALIGNER_MODE_NONE);
    }
    x += img->getSize().width + GAP;
    y = VCPFRM_ITEM_HORZ_GAP;

    // create last name text
    VFX_OBJ_CREATE(fileName, VfxTextFrame, m_MediaBase);
    fileName->setString(itemText.loadFromMem((VfxWChar*)m_object->file_name_ucs));
	fileName->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VCPFRM_FONT_SIZE_3)));
    fileName->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
    fileName->setPos(x, y);

    y += fileName->getSize().height + VCPFRM_SIDE_MARGIN_SMALL;
	fileName->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
	fileName->setSize(m_MediaBase->getSize().width - x - VAPP_UC_LEFT_MARGIN/*fileName->getSize().width*/,  fileName->getSize().height);
				/*for rotation*/ 
	fileName->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
								VFX_FRAME_ALIGNER_MODE_NONE, 
								VFX_FRAME_ALIGNER_MODE_SIDE,
								VFX_FRAME_ALIGNER_MODE_NONE);

    // create title text
    {
        U16 text_buffer[50] = {0,};
        VFX_OBJ_CREATE(sizeText, VfxTextFrame, m_MediaBase);
        ucGetSizeStringFromByteCount(m_object->size, text_buffer);
        sizeText->setString(itemText.loadFromMem(text_buffer));//%dBytes",object->size));//getFileSizeString());U32 file_size = applib_get_file_size((kal_wchar*) file_path);
        sizeText->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB));
        sizeText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VCPFRM_FONT_SIZE_1)));
        sizeText->setPos(x, y);
		/*for rotation*/
		sizeText->setSize(sizeText->getSize().width, sizeText->getSize().height);
		sizeText->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
								VFX_FRAME_ALIGNER_MODE_NONE, 
								VFX_FRAME_ALIGNER_MODE_SIDE,
								VFX_FRAME_ALIGNER_MODE_NONE);
    }
    x = getSize().width - VCPFRM_ITEM_HORZ_GAP;
    y = getSize().height - VCPFRM_ITEM_HORZ_GAP;
}

VFX_IMPLEMENT_CLASS("VappComposerMainPage", VappComposerMainPage, VfxPage);
void VappComposerMainPage::onExit(VfxBool isBackward)
{
    VfxPage::onExit(isBackward);
    if( NULL != composer_form)
        composer_form->setIsAnimEnabled(VFX_FALSE);
}

void VappComposerMainPage::onEntered()
{
    VfxPage::onEntered();
    if( NULL != composer_form)
        composer_form->setIsAnimEnabled(VFX_TRUE);

    if( VFX_TRUE == isNeedUpdate)
    {
        drawWithData();
        isNeedUpdate = VFX_FALSE;
    }
}

void VappComposerMainPage::onEnter(VfxBool isBackward)
{
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
	VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);

    VfxPage::onEnter(isBackward);       

    if(app->main->active_app_flag)
    {
        app->ucSelectObjectFromFmToInsertWarningModeCheck( (U16*)app->m_service_cntxt->main->file_path, app->main->is_short);
        //m_signalConnectOnFileSelection.postEmit();
        scr->connectOnFileSelection();
		app->main->active_app_flag = VFX_FALSE;
    }
	onEntertoggleString();
    attachmentPage = NULL;
}

void VappComposerMainPage::onEntertoggleString(void)
{
VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
	VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
	if ((this->getRotate() == VFX_SCR_ROTATE_TYPE_LANDSCAPE ||
		this->getRotate() == VFX_SCR_ROTATE_TYPE_270 ||
		 this->getRotate() == VFX_SCR_ROTATE_TYPE_90))
	{
        toggleBar(VFX_PAGE_BAR_LOCATION_TOP, VFX_FALSE);
	    #ifdef __MMI_EMAIL__
          if (app->m_service_cntxt->msg_type->MMS_edit_mode != SRV_UC_MMS_EDIT_MODE_EMAIL)
	    #endif/*__MMI_EMAIL__*/
          {
			if(vappUcGetValidSimInfo())
			{
				U16 text_buffer[50] = {0,};
				VfxWString itemText;
				app->ucGetComposerSendString(text_buffer);
				if(m_functionBarToFrame)
				{
				  m_functionBarToFrame->changeItem(ID_TOOLBAR_SEND, itemText.loadFromMem((VfxWChar*)text_buffer));
				}
            #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__    
				if(m_functionBarCcFrame)
				{
				  m_functionBarCcFrame->changeItem(ID_TOOLBAR_SEND, itemText.loadFromMem((VfxWChar*)text_buffer));
				}
				if(m_functionBarBccFrame)
				{
				  m_functionBarBccFrame->changeItem(ID_TOOLBAR_SEND, itemText.loadFromMem((VfxWChar*)text_buffer));
				}
            #endif
				if(m_functionBarSubjectFrame)
				{
				  m_functionBarSubjectFrame->changeItem(ID_TOOLBAR_SEND, itemText.loadFromMem((VfxWChar*)text_buffer));
				}
				if(m_functionBarFrame)
				{
				  m_functionBarFrame->changeItem(ID_TOOLBAR_SEND, itemText.loadFromMem((VfxWChar*)text_buffer));
				}
			}
		 }
	}
	else
	{
		toggleBar(VFX_PAGE_BAR_LOCATION_TOP, VFX_TRUE);		
	}
}

void VappComposerMainPage::onRotate(const VfxScreenRotateParam &param)
{
	VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
	VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
	if (param.rotateTo == VFX_SCR_ROTATE_TYPE_LANDSCAPE ||
		param.rotateTo == VFX_SCR_ROTATE_TYPE_270 ||
        param.rotateTo == VFX_SCR_ROTATE_TYPE_90)
	{
        toggleBar(VFX_PAGE_BAR_LOCATION_TOP, VFX_FALSE);
	    #ifdef __MMI_EMAIL__
          if (app->m_service_cntxt->msg_type->MMS_edit_mode != SRV_UC_MMS_EDIT_MODE_EMAIL)
	    #endif/*__MMI_EMAIL__*/
          {
			if(vappUcGetValidSimInfo())
			{
				U16 text_buffer[50] = {0,};
				VfxWString itemText;
				app->ucGetComposerSendString(text_buffer);
				if(m_functionBarToFrame)
				{
			      m_functionBarToFrame->changeItem(ID_TOOLBAR_SEND, itemText.loadFromMem((VfxWChar*)text_buffer));
				}
            #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__        
				if(m_functionBarCcFrame)
				{
				  m_functionBarCcFrame->changeItem(ID_TOOLBAR_SEND, itemText.loadFromMem((VfxWChar*)text_buffer));
				}
				if(m_functionBarBccFrame)
				{
				  m_functionBarBccFrame->changeItem(ID_TOOLBAR_SEND, itemText.loadFromMem((VfxWChar*)text_buffer));
				}
            #endif    
				if(m_functionBarSubjectFrame)
				{
				  m_functionBarSubjectFrame->changeItem(ID_TOOLBAR_SEND, itemText.loadFromMem((VfxWChar*)text_buffer));
				}
				if(m_functionBarFrame)
				{
				  m_functionBarFrame->changeItem(ID_TOOLBAR_SEND, itemText.loadFromMem((VfxWChar*)text_buffer));
				}
		    }
		  }

	}
	else
	{
		toggleBar(VFX_PAGE_BAR_LOCATION_TOP, VFX_TRUE);
        #ifdef __MMI_EMAIL__
        if (app->m_service_cntxt->msg_type->MMS_edit_mode != SRV_UC_MMS_EDIT_MODE_EMAIL)
        #endif/*__MMI_EMAIL__*/       
		{
		   if(vappUcGetValidSimInfo())
		   {
			if(m_functionBarToFrame)
			{
		      m_functionBarToFrame->changeItem(ID_TOOLBAR_SEND, VFX_WSTR_RES(STR_GLOBAL_SEND));
			}
        #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__
			if(m_functionBarCcFrame)
			{
			  m_functionBarCcFrame->changeItem(ID_TOOLBAR_SEND, VFX_WSTR_RES(STR_GLOBAL_SEND));
			}
			if(m_functionBarBccFrame)
			{
			  m_functionBarBccFrame->changeItem(ID_TOOLBAR_SEND, VFX_WSTR_RES(STR_GLOBAL_SEND));
			}
        #endif    
			if(m_functionBarSubjectFrame)
			{
			  m_functionBarSubjectFrame->changeItem(ID_TOOLBAR_SEND, VFX_WSTR_RES(STR_GLOBAL_SEND));
			}
			if(m_functionBarFrame)
			{
			  m_functionBarFrame->changeItem(ID_TOOLBAR_SEND, VFX_WSTR_RES(STR_GLOBAL_SEND));
			}
		   }
		} 
	}
}

void VappComposerMainPage::setBounds(const VfxRect &value)
{
	VfxPage::setBounds(value);
	if (composer_form != NULL)
	{
		VfxSize size = getSize();
		
		composer_form->setPos(0, 0);
		composer_form->setSize(size.width, size.height);
		if (m_contactlist != NULL && m_BackUpitemsAlraedyDraw != 0)
		{
			VfxSize itemSIze;	
			if ((m_itemsAlraedyDraw & ID_RECIPIENT_TO) && m_contactSelectorTo)
			{
				itemSIze = m_contactSelectorTo->getSize();

			}
        #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__    
			else if ((m_itemsAlraedyDraw & ID_RECIPIENT_CC) && m_contactSelectorCc)
			{
				
				itemSIze = m_contactSelectorCc->getSize();
			}
			else if ((m_itemsAlraedyDraw & ID_RECIPIENT_BCC) && m_contactSelectorBcc)
			{
				
				itemSIze = m_contactSelectorBcc->getSize();
			}
        #endif    
			else
			{
				itemSIze.width = 0;
				itemSIze.height = 0;

			}

			VfxSize controlSize;

			controlSize.width = size.width;
			controlSize.height = size.height - itemSIze.height - composer_form->getContentTopGap();
			m_contactlist->setSize(controlSize.width, controlSize.height);
			

			VcpFormItemBase *item = composer_form->getItem(ID_CONTACT_SELECTOR_LIST_MENU);
			if (item)
			{
				item->setHeight(controlSize.height);
			}
		}
	

       if(m_contactSelectorTo)
       {
		   			/*for rotation*/
			m_contactSelectorTo->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
											VFX_FRAME_ALIGNER_MODE_NONE, 
											VFX_FRAME_ALIGNER_MODE_SIDE,
											VFX_FRAME_ALIGNER_MODE_NONE);
           m_contactSelectorTo->checkUpdate();
       }
   #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__    
	   if(this->m_contactSelectorCc)
       {
           this->m_contactSelectorCc->checkUpdate();
       }
	   if(this->m_contactSelectorBcc)
       {
           this->m_contactSelectorBcc->checkUpdate();
       }
   #endif
	   if(textEditorBody)
	   {
			vrt_size_struct mainScreenSize;
			vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
			textEditorBody->setAutoResized(VFX_TRUE);
	   }
	}
}

void VappComposerMainPage::deactivateEditor(void)
{
	if(highlightedEditor && highlightedEditor->isValid())
	{
		highlightedEditor->deactivate();
	}
	highlightedEditor = NULL;
}

VfxId VappComposerMainPage::VappUcGetPositionToInsert(VfxId itemID)
{
	switch(itemID)
		{
		#ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__ 
			case ID_RECIPIENT_CC:
				if(m_contactSelectorBcc)
				{
					return ID_RECIPIENT_BCC;
				}
			case ID_RECIPIENT_BCC:
				if(textEditorSubject)
				{
					return ID_SUBJECT;
				}
		#endif        
			case ID_SUBJECT:
				if(slideBar)
				{
					return ID_INLINE_SLIDE_BAR;
				}
			case ID_INLINE_SLIDE_BAR:
				if(composer_media1)
				{
					return ID_INLINE_MEDIA_1;
				}
			case ID_INLINE_MEDIA_1:
				if(composer_media2)
				{
					return ID_INLINE_MEDIA_2;
				}
			case ID_INLINE_MEDIA_2:
				if(textEditorBody)
				{
					return ID_BODY_TEXT;
				}
			case ID_BODY_TEXT:
				if(attachmentList || attachmentList1)
				{
					return ID_MULTI_ATTACHMENT;
				}
			case ID_MULTI_ATTACHMENT:
				if(composerHintTxt)
				{
					return ID_INLINE_MSG_HINT;
				}
				else
				{
					return 0;
				}
		}
		return 0;
}

void VappComposerMainPage::removeObjectFromPage(VfxS32 pageItem)
{
	composer_form->removeItem(pageItem);
    switch(pageItem)
    {
        case ID_RECIPIENT_TO:
			 // VFX_OBJ_CLOSE(m_contactSelectorTo);  //Rahul Added to Fix Leak, will be removed once Rorm hanlde this at its end*/			
            m_contactSelectorTo  = NULL;
			m_itemsAlraedyDraw &=   ~ID_RECIPIENT_TO;
			m_functionBarToFrame = NULL;
            return;
    #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__ 
        case ID_RECIPIENT_CC:
			// VFX_OBJ_CLOSE(m_contactSelectorCc);
		    m_contactSelectorCc  = NULL;
			m_itemsAlraedyDraw &=   ~ID_RECIPIENT_CC;
			m_functionBarCcFrame = NULL;
		    return;

        case ID_RECIPIENT_BCC:
			// VFX_OBJ_CLOSE(m_contactSelectorBcc);
		    m_contactSelectorBcc = NULL;
			m_itemsAlraedyDraw &=   ~ID_RECIPIENT_BCC;
			m_functionBarBccFrame  = NULL;
		    return;
    #endif
        case ID_SUBJECT:
			//  VFX_OBJ_CLOSE(textEditorSubject);
            textEditorSubject = NULL;
			m_itemsAlraedyDraw &=   ~ID_SUBJECT;
			m_functionBarSubjectFrame = NULL;
		    return;

	    case ID_INLINE_SLIDE_BAR:
		  //  VFX_OBJ_CLOSE(slideBar);
			slideBar = NULL;
			m_itemsAlraedyDraw &=   ~ID_INLINE_SLIDE_BAR;
		    return;

	    case ID_INLINE_MEDIA_1:
			// VFX_OBJ_CLOSE(composer_media1);
		    composer_media1 = NULL;
			m_itemsAlraedyDraw &=   ~ID_INLINE_MEDIA_1;
		    return;

	    case ID_INLINE_MEDIA_2:
			// VFX_OBJ_CLOSE(composer_media2);
		    composer_media2 = NULL;
			m_itemsAlraedyDraw &=   ~ID_INLINE_MEDIA_2;
            return;
	    case ID_BODY_TEXT:
			// VFX_OBJ_CLOSE(textEditorBody);
		    textEditorBody = NULL;
			m_itemsAlraedyDraw &=   ~ID_BODY_TEXT;
			m_functionBarFrame = NULL;
		    return;

        case ID_MULTI_ATTACHMENT:
       //     if(attachmentList)
		//	 VFX_OBJ_CLOSE(attachmentList);
        //    if(attachmentList1)
		//	 VFX_OBJ_CLOSE(attachmentList1);
		     attachmentList = NULL;
            attachmentList1 = NULL;
			m_itemsAlraedyDraw &=   ~ID_MULTI_ATTACHMENT;
		    return;

        case ID_INLINE_MSG_HINT:
		//	 VFX_OBJ_CLOSE(composerHintTxt);			
            composerHintTxt = NULL;
			m_itemsAlraedyDraw &=   ~ID_INLINE_MSG_HINT;
            return;
    }
   // if()
}
void VappComposerMainPage::removeButtonBar(void)
{
    VFX_OBJ_CLOSE(composerToolbar);
    composerToolbar = NULL;
}

VfxBool VappComposerMainPage::isSendButtonAvailable(void)
{
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);

    if ( !vappUcFlightModecheck())
    {
        if( !((vappUcGetValidSimInfo() & ~(vappUcGetInvalidSimInfo())) & app->m_service_cntxt->send_info->send_sim_id) &&
		    !((vappUcGetAllSimCount() == 1) && !(vappUcGetValidSimInfo() == vappUcGetClosedSimInfo()) && (app->operation_type == UC_OPERATION_REPLY || app->operation_type == UC_OPERATION_REPLY_BY_SMS ||
		    app->operation_type == UC_OPERATION_REPLY_BY_MMS ||app->operation_type == UC_OPERATION_REPLY_ALL||app->main->msg_operation == UC_OPERATION_REPLY ||
		    app->main->msg_operation == UC_OPERATION_REPLY_BY_SMS ||app->main->msg_operation == UC_OPERATION_REPLY_BY_MMS ||
		    app->main->msg_operation == UC_OPERATION_REPLY_ALL|| initial_launch_mode == UC_LAUNCH_MODE_INSERT || initial_launch_mode == UC_LAUNCH_MODE_EMOTICON) && !(app->m_service_cntxt->send_info->send_sim_id & vappUcGetValidSimInfo())))	    
        {
            return VFX_FALSE;
        }
        else
        {
            return VFX_TRUE;
        }
    }
    else
    {
        if( vappUcGetValidSimInfo() & app->m_service_cntxt->send_info->send_sim_id )
            return VFX_TRUE;
        else    
            return VFX_FALSE; 
    }
}

void VappComposerMainPage::updateButtonBar(void)
{
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
    if(composerToolbar != NULL)
    {
     //   removeButtonBar();
		if((m_toolBarItemOn & TOOLBAR_SEND) == TOOLBAR_SEND)
		{
			composerToolbar->removeItem(ID_TOOLBAR_SEND);
		}
		if((m_toolBarItemOn & TOOLBAR_SWITCH_SIM) == TOOLBAR_SWITCH_SIM)
		{
			composerToolbar->removeItem(ID_TOOLBAR_SWITCH_SIM);
		}
		if((m_toolBarItemOn & TOOLBAR_INSERT) == TOOLBAR_INSERT)
		{
			composerToolbar->removeItem(ID_TOOLBAR_INSERT);
		}
		if((m_toolBarItemOn & TOOLBAR_SAVE) == TOOLBAR_SAVE)
		{
			composerToolbar->removeItem(ID_TOOLBAR_SAVE);
		}
		if((m_toolBarItemOn & TOOLBAR_REMOVE_SUBJECT) == TOOLBAR_REMOVE_SUBJECT)
		{
			composerToolbar->removeItem(ID_TOOLBAR_REMOVE_SUBJECT);
		}
		if((m_toolBarItemOn & TOOLBAR_ADD_SUBJECT) == TOOLBAR_ADD_SUBJECT)
		{
			composerToolbar->removeItem(ID_TOOLBAR_ADD_SUBJECT);
		}
    #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__     
		if((m_toolBarItemOn & TOOLBAR_CCBCC) == TOOLBAR_CCBCC)
		{
			composerToolbar->removeItem(ID_TOOLBAR_CCBCC);
		}
    #endif    
    #ifdef __MMI_COSMOS_UC_MMS_PREVIEW_SUPPORT__    
		if((m_toolBarItemOn & TOOLBAR_PREVIEW) == TOOLBAR_PREVIEW)
		{
			composerToolbar->removeItem(ID_TOOLBAR_PREVIEW);
		}
    #endif    
		if((m_toolBarItemOn & TOOLBAR_CANCEL) == TOOLBAR_CANCEL)
		{
			composerToolbar->removeItem(ID_TOOLBAR_CANCEL);
		}
		if((m_toolBarItemOn & TOOLBAR_SAVE_AS) == TOOLBAR_SAVE_AS)
		{
			composerToolbar->removeItem(ID_TOOLBAR_SAVE_AS);
		}
		m_toolBarItemOn = 0;
    }
	else
	{
		VFX_OBJ_CREATE(composerToolbar,VcpToolBar,this);  //Should not use XML mechanism here
	}
    if((app->operation_type == UC_OPERATION_WRITE_NEW_SMS_TEMPLATE) ||
        (app->operation_type == UC_OPERATION_EDIT_SMS_TEMPLATE))
    {
    /* Wrap this compile option inside the "if" sentence to avoid if-else mis-match */
    #ifdef __MMI_MESSAGES_TEMPLATE__
        composerToolbar->addItem(ID_TOOLBAR_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE), IMG_ID_VAPP_UC_SAVE_AS_ID);
        composerToolbar->addItem(ID_TOOLBAR_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), IMG_ID_VAPP_UC_CANCEL_ID);
		m_toolBarItemOn |= TOOLBAR_SAVE;
		m_toolBarItemOn |= TOOLBAR_CANCEL;
    #endif    
    }
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__    
    else if((app->operation_type == UC_OPERATION_WRITE_NEW_MMS_TEMPLATE) ||
        (app->operation_type == UC_OPERATION_EDIT_MMS_TEMPLATE))
    {
        composerToolbar->addItem(ID_TOOLBAR_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE), IMG_ID_VAPP_UC_SAVE_AS_ID);
        composerToolbar->addItem(ID_TOOLBAR_INSERT, VFX_WSTR_RES(STR_ID_VAPP_UC_INSERT_ID), IMG_ID_VAPP_UC_INSERT_ID); // add tool bar "cancel" button
		m_toolBarItemOn |= TOOLBAR_SAVE;
		m_toolBarItemOn |= TOOLBAR_INSERT;
        if( (m_itemForceOn & ID_SUBJECT) == ID_SUBJECT)
        {
            composerToolbar->addItem(ID_TOOLBAR_REMOVE_SUBJECT, VFX_WSTR_RES(STR_ID_VAPP_UC_REMOVE_SUBJECT_ID), IMG_ID_VAPP_UC_REMOVE_SUBJECT_ID);       // add tool bar "save" button
			m_toolBarItemOn |= TOOLBAR_REMOVE_SUBJECT;
        }
        else
        {
            composerToolbar->addItem(ID_TOOLBAR_ADD_SUBJECT, VFX_WSTR_RES(STR_ID_VAPP_UC_ADD_SUBJECT_ID), IMG_ID_VAPP_UC_ADD_SUBJECT_ID);       // add tool bar "save" button    
			m_toolBarItemOn |= TOOLBAR_ADD_SUBJECT;
        }
        composerToolbar->addItem(ID_TOOLBAR_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), IMG_ID_VAPP_UC_CANCEL_ID);
		m_toolBarItemOn |= TOOLBAR_CANCEL;
    }
#endif    
    else if((app->operation_type == UC_OPERATION_SEND_VCARD_AS_SMS) ||
        (app->operation_type == UC_OPERATION_SEND_VCALENDAR_AS_SMS))
    {
    #if defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__)
        composerToolbar->addItem(ID_TOOLBAR_SEND, VFX_WSTR_RES(STR_GLOBAL_SEND), IMG_ID_VAPP_UC_SEND_ID);       // add tool bar "Send" button
		m_toolBarItemOn |= TOOLBAR_SEND;
        //if (vappUcGetValidSimInfo() == vappUcGetInvalidSimInfo())kuldeep_gplus
		if (!isSendButtonAvailable())	
        {
            composerToolbar->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
        }
    #if (MMI_MAX_SIM_NUM >= 2)
        if (vappUcGetAllSimCount() >=2)
        {
            composerToolbar->addItem(ID_TOOLBAR_SWITCH_SIM, VFX_WSTR_RES(STR_ID_VAPP_UC_SWITCH_SIM_ID), IMG_ID_VAPP_UC_SWITCH_SIM_ID); // add tool bar "Switch sim" button
			m_toolBarItemOn |= TOOLBAR_SWITCH_SIM;
        }
    #endif
    #endif
    }
    #ifdef __MMI_EMAIL__
    else if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
    {
        composerToolbar->addItem(ID_TOOLBAR_SEND, VFX_WSTR_RES(STR_GLOBAL_SEND), IMG_ID_VAPP_UC_SEND_ID);       // add tool bar "Send" button
		m_toolBarItemOn |= TOOLBAR_SEND;
		if(!(VappEmailComp::isSendButtonAvailable()))
		{
			//if ((vappUcGetValidSimInfo() ==vappUcGetInvalidSimInfo()) && !vappUcFlightModecheck())kuldeep_gplus
			if(!((vappUcGetValidSimInfo() & ~(vappUcGetInvalidSimInfo())) & app->m_service_cntxt->send_info->send_sim_id))
			{
				composerToolbar->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
			}
		}

        composerToolbar->addItem(ID_TOOLBAR_INSERT, VFX_WSTR_RES(STR_ID_VAPP_UC_INSERT_ID), IMG_ID_VAPP_UC_INSERT_ID); // add tool bar "cancel" button
		m_toolBarItemOn |= TOOLBAR_INSERT;
		composerToolbar->addItem(ID_TOOLBAR_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE), IMG_ID_VAPP_UC_SAVE_AS_ID);
		m_toolBarItemOn |= TOOLBAR_SAVE;
    #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__     
		composerToolbar->addItem(ID_TOOLBAR_CCBCC, VFX_WSTR_RES(STR_ID_VAPP_UC_CCBCC), IMG_ID_VAPP_UC_ADD_CCBCC_ID);       // add tool bar "save" button
		m_toolBarItemOn |= TOOLBAR_CCBCC;
    #endif    
    }
    #endif
    else
    {
        composerToolbar->addItem(ID_TOOLBAR_SEND, VFX_WSTR_RES(STR_GLOBAL_SEND), IMG_ID_VAPP_UC_SEND_ID);       // add tool bar "save" button    
		m_toolBarItemOn |= TOOLBAR_SEND;
        //if (vappUcGetValidSimInfo() == vappUcGetInvalidSimInfo())kuldeep_gplus
		if (!isSendButtonAvailable())
        {
            composerToolbar->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
        }
    #if (MMI_MAX_SIM_NUM >= 2)
        if (vappUcGetAllSimCount() >= 2)
        {
            composerToolbar->addItem(ID_TOOLBAR_SWITCH_SIM, VFX_WSTR_RES(STR_ID_VAPP_UC_SWITCH_SIM_ID), IMG_ID_VAPP_UC_SWITCH_SIM_ID); // add tool bar "Switch sim" button
			m_toolBarItemOn |= TOOLBAR_SWITCH_SIM;
        }
    #endif

		if (app->m_service_cntxt->msg_type->MMS_edit_mode != SRV_UC_MMS_EDIT_MODE_LEMEI_MMS)
		{
        #if (MMI_MAX_SIM_NUM >= 2)
            if (vappUcGetValidSimInfo() == (SRV_UC_SIM_ID_GSM_SIM1 | SRV_UC_SIM_ID_GSM_SIM2))
            {
                composerToolbar->addItem(ID_TOOLBAR_SWITCH_SIM, VFX_WSTR_RES(STR_ID_VAPP_UC_SWITCH_SIM_ID), IMG_ID_VAPP_UC_SWITCH_SIM_ID); // add tool bar "Switch sim" button
			    m_toolBarItemOn |= TOOLBAR_SWITCH_SIM;
            }
        #endif
            composerToolbar->addItem(ID_TOOLBAR_SAVE_AS, VFX_WSTR_RES(STR_GLOBAL_SAVE), IMG_ID_VAPP_UC_SAVE_AS_ID); // add tool bar "cancel" button
		    m_toolBarItemOn |= TOOLBAR_SAVE_AS;
            composerToolbar->addItem(ID_TOOLBAR_INSERT, VFX_WSTR_RES(STR_ID_VAPP_UC_INSERT_ID), IMG_ID_VAPP_UC_INSERT_ID); // add tool bar "cancel" button
		    m_toolBarItemOn |= TOOLBAR_INSERT;
        }
        if (app->m_service_cntxt->msg_type->caller_specific_msg_type != SRV_UC_MSG_TYPE_SMS_ONLY)
		{
			if (app->m_service_cntxt->msg_type->MMS_edit_mode != SRV_UC_MMS_EDIT_MODE_LEMEI_MMS)
			{
	            if( (m_itemForceOn & ID_SUBJECT) == ID_SUBJECT)
                {
                    composerToolbar->addItem(ID_TOOLBAR_REMOVE_SUBJECT, VFX_WSTR_RES(STR_ID_VAPP_UC_REMOVE_SUBJECT_ID), IMG_ID_VAPP_UC_REMOVE_SUBJECT_ID);       // add tool bar "save" button
				    m_toolBarItemOn |= TOOLBAR_REMOVE_SUBJECT;
                }
                else
                {
                    composerToolbar->addItem(ID_TOOLBAR_ADD_SUBJECT, VFX_WSTR_RES(STR_ID_VAPP_UC_ADD_SUBJECT_ID), IMG_ID_VAPP_UC_ADD_SUBJECT_ID);       // add tool bar "save" button    
				    m_toolBarItemOn |= TOOLBAR_ADD_SUBJECT;
                }
    #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__ 
                if (app->m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER || 
                    app->m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER ||
                    app->m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_DEFAULT)
                {
                    composerToolbar->addItem(ID_TOOLBAR_CCBCC, VFX_WSTR_RES(STR_ID_VAPP_UC_CCBCC), IMG_ID_VAPP_UC_ADD_CCBCC_ID);       // add tool bar "save" button
				    m_toolBarItemOn |= TOOLBAR_CCBCC;
                }
     #endif           
            }
        #ifdef __MMI_COSMOS_UC_MMS_PREVIEW_SUPPORT__
            if (app->m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
            {
                composerToolbar->addItem(ID_TOOLBAR_PREVIEW, VFX_WSTR_RES(STR_GLOBAL_PREVIEW), IMG_ID_VAPP_UC_PREVIEW_ID); // add tool bar "cancel" button
				m_toolBarItemOn |= TOOLBAR_PREVIEW;
            }
        #endif
		}
    }
    composerToolbar->m_signalButtonTap.connect(this, &VappComposerMainPage::onToolBarClick);          // connect tool bar signal
    setBottomBar(composerToolbar);

    if( app->main->busy_getting_data )
    {
        composerToolbar->setIsUnhittable(VFX_TRUE);
    }
    else
    {
        composerToolbar->setIsUnhittable(VFX_FALSE);
    }
}

void VappComposerMainPage::csToOnSearchButtonClicked()
{
    // click the search button, goto phonebook
	/*TODO:: RahulFirst do the validation here, if it is possible to add the recipient, if no then display the pop-up here only*/
	VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);

	if (app->m_service_cntxt->msg->to_num >= app->vappUcGetMaxRecipientCount())
	{
		mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_RECIPIENT_NUMBER_EXCEED_ID)).getBuf());
		return;
	}
	app->setContactInsertType((U8)SRV_UC_ADDRESS_GROUP_TYPE_TO);	
	app->m_pbInsertState = UC_PB_CUI_STATE_INSERT_ADDRESS;

    if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
    {
       scr->ucOpenPhoneBook(VFX_TRUE, MMI_PHB_CONTACT_FIELD_EMAIL);
    }
    else if (app->m_service_cntxt->msg_type->caller_specific_msg_type == SRV_UC_MSG_TYPE_SMS_ONLY)
    {
       scr->ucOpenPhoneBook(VFX_TRUE,  MMI_PHB_CONTACT_FIELD_NUMBER);
    }
    else
    {
       scr->ucOpenPhoneBook(VFX_TRUE, (MMI_PHB_CONTACT_FIELD_NUMBER | MMI_PHB_CONTACT_FIELD_EMAIL));
    }
    restoreControls();
}

#ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__
void VappComposerMainPage::csBCCOnSearchButtonClicked()
{
	/*TODO:: RahulFirst do the validation here, if it is possible to add the recipient, if no then display the pop-up here only*/
	VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
	
	if (app->m_service_cntxt->msg->to_num >= app->vappUcGetMaxRecipientCount())
	{
		mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_RECIPIENT_NUMBER_EXCEED_ID)).getBuf());
		return;
	}

	app->setContactInsertType((U8)SRV_UC_ADDRESS_GROUP_TYPE_BCC);
	app->m_pbInsertState = UC_PB_CUI_STATE_INSERT_ADDRESS;

    if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
    {
       scr->ucOpenPhoneBook(VFX_TRUE, MMI_PHB_CONTACT_FIELD_EMAIL);
    }
    else if (app->m_service_cntxt->msg_type->caller_specific_msg_type == SRV_UC_MSG_TYPE_SMS_ONLY)
    {
       scr->ucOpenPhoneBook(VFX_TRUE,  MMI_PHB_CONTACT_FIELD_NUMBER);
    }
    else
    {
       scr->ucOpenPhoneBook(VFX_TRUE, (MMI_PHB_CONTACT_FIELD_NUMBER | MMI_PHB_CONTACT_FIELD_EMAIL));
    }
    restoreControls();
}

void VappComposerMainPage::csCCOnSearchButtonClicked()
{
	/*TODO:: RahulFirst do the validation here, if it is possible to add the recipient, if no then display the pop-up here only*/
	VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
	
	if (app->m_service_cntxt->msg->to_num >= app->vappUcGetMaxRecipientCount())
	{
		mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_RECIPIENT_NUMBER_EXCEED_ID)).getBuf());
		return;
	}

	app->setContactInsertType((U8)SRV_UC_ADDRESS_GROUP_TYPE_CC);

	app->m_pbInsertState = UC_PB_CUI_STATE_INSERT_ADDRESS;

	 if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
    {
       scr->ucOpenPhoneBook(VFX_TRUE, MMI_PHB_CONTACT_FIELD_EMAIL);
    }
    else if (app->m_service_cntxt->msg_type->caller_specific_msg_type == SRV_UC_MSG_TYPE_SMS_ONLY)
    {
       scr->ucOpenPhoneBook(VFX_TRUE,  MMI_PHB_CONTACT_FIELD_NUMBER);
    }
    else
    {
       scr->ucOpenPhoneBook(VFX_TRUE, (MMI_PHB_CONTACT_FIELD_NUMBER | MMI_PHB_CONTACT_FIELD_EMAIL));
    }
    restoreControls();
}
#endif

void VappComposerMainPage::csOnRcipientHeightChange(VfxFrame *f, const VfxRect &r)
{
    if(r.size != f->getSize())
    {
        frame_part1->setHeight(f->getSize().height);
        //frame_part1->setHeight(m_contactSelectorTo->getSize().height);
    }
	if(highlightedEditor && (highlightedEditor == textEditorSubject))
	{
		composer_form->scrollItemToView(ID_SUBJECT, VCPFORM_SCROLL_TOP);
	}
}


void VappComposerMainPage::hideUnhideControls(VfxU32 ids, VfxBool isHide)
{
	VcpFormItemBase *item = NULL;
	VfxU32 temp = 1;

	while (temp <= ID_CONTACT_SELECTOR_LIST_MENU)
	{
		if ((ids & temp) ==   temp)
		{
			item = composer_form->getItem(temp);
			if (item)
			{
				item->setIsHidden(isHide);
			}
			item = NULL;
		}
		temp = temp << 1;
   }
}

void VappComposerMainPage::onPhbSearchContactListUpdate(VfxU32 count)
{
	VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);	
	VfxS32 itemInFocus = 0;
	VcpContactSelector *selectedCs = NULL;

	switch (app->getContactInsertType())
	{
		case SRV_UC_ADDRESS_GROUP_TYPE_TO:
			{
				itemInFocus = ID_RECIPIENT_TO;
				selectedCs = m_contactSelectorTo;
			}
			break;
            
    #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__
		case SRV_UC_ADDRESS_GROUP_TYPE_CC:
			{
				itemInFocus = ID_RECIPIENT_CC;
				selectedCs = m_contactSelectorCc;
			}
			break;

		case SRV_UC_ADDRESS_GROUP_TYPE_BCC:
			{
				itemInFocus = ID_RECIPIENT_BCC;
				selectedCs = m_contactSelectorBcc;
			}
			break;
    #endif
    
		default:
			ASSERT(0);
	}

	if (count == 0)
	{
		if (m_BackUpitemsAlraedyDraw != 0)
		{
			VfxU32 item = 0;
			this->hideUnhideControls(ID_CONTACT_SELECTOR_LIST_MENU , VFX_TRUE);
			this->hideUnhideControls(m_BackUpitemsAlraedyDraw , VFX_FALSE);
        #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__    
			item = (m_itemsAlraedyDraw & (ID_RECIPIENT_TO | ID_RECIPIENT_CC |ID_RECIPIENT_BCC));
        #else
            item = (m_itemsAlraedyDraw & (ID_RECIPIENT_TO));
        #endif
			m_itemsAlraedyDraw = m_BackUpitemsAlraedyDraw;
			m_BackUpitemsAlraedyDraw = 0;
			selectedCs->hideContact(VFX_FALSE);
			composer_form->scrollItemToView(item, VCPFORM_SCROLL_BOTTOM);			
		}
	}
	else
	{
		if (!(m_itemsAlraedyDraw & ID_CONTACT_SELECTOR_LIST_MENU) && (m_contactlist && m_contactlist->isMenuListActivated()))
		{
			/*If meulist is not drawn draw it now*/
			this->m_contactlist->setTappedHandler(this, &VappComposerMainPage::onTapItem);
			this->hideUnhideControls((m_itemsAlraedyDraw & ~itemInFocus), VFX_TRUE);
			this->hideUnhideControls(ID_CONTACT_SELECTOR_LIST_MENU, VFX_FALSE);
			m_BackUpitemsAlraedyDraw = m_itemsAlraedyDraw;
			m_itemsAlraedyDraw = itemInFocus | ID_CONTACT_SELECTOR_LIST_MENU;

			selectedCs->hideContact(VFX_TRUE);


			VfxSize controlSize;
			VfxSize formSize = composer_form->getSize();
			VfxSize itemSize = composer_form->getItem(itemInFocus)->getSize();

			controlSize.width = formSize.width;
			controlSize.height = formSize.height - itemSize.height - composer_form->getContentTopGap();
			m_contactlist->setSize(controlSize.width, controlSize.height);
			

			VcpFormItemBase *item = composer_form->getItem(ID_CONTACT_SELECTOR_LIST_MENU);
			if (item)
			{
				item->setHeight(controlSize.height);
			}
		}
	}
}
void VappComposerMainPage::csOnTextChanged(VcpContactSelector *cs, VfxWChar *text)
{
	VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);	
    VfxWString itemText;
	VfxS32 itemInFocus = 0;
    // inputbox text changed, search in phonebook and update list
	
   // cs->hideContact(VFX_TRUE);
	if (cs ==   m_contactSelectorTo)
	{
		itemInFocus = ID_RECIPIENT_TO;
		app->setContactInsertType((U8)SRV_UC_ADDRESS_GROUP_TYPE_TO);
	}
 #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__    
	else if (cs == m_contactSelectorCc)
	{
		itemInFocus = ID_RECIPIENT_CC;
		app->setContactInsertType((U8)SRV_UC_ADDRESS_GROUP_TYPE_CC);
	}
	else if (cs == m_contactSelectorBcc)
	{
		itemInFocus = ID_RECIPIENT_BCC;
		app->setContactInsertType((U8)SRV_UC_ADDRESS_GROUP_TYPE_BCC);

	}
 #endif    
	else
	{
	  ASSERT(0);
	}
	if (vfx_sys_wcslen(text) == 0)
	{
		/*No Text so show all control*/
		if (m_BackUpitemsAlraedyDraw)
		{
			VfxU32 item = 0;
			this->hideUnhideControls(ID_CONTACT_SELECTOR_LIST_MENU , VFX_TRUE);
			this->hideUnhideControls(m_BackUpitemsAlraedyDraw , VFX_FALSE);
        #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__    
			item = (m_itemsAlraedyDraw & (ID_RECIPIENT_TO | ID_RECIPIENT_CC |ID_RECIPIENT_BCC));
        #else
            item = (m_itemsAlraedyDraw & (ID_RECIPIENT_TO));
        #endif
			m_itemsAlraedyDraw = m_BackUpitemsAlraedyDraw;
			m_BackUpitemsAlraedyDraw = 0;

			composer_form->removeItem(ID_CONTACT_SELECTOR_LIST_MENU);			
			composer_form->scrollItemToView(item, VCPFORM_SCROLL_BOTTOM);	
			m_contactlist = NULL;
		}
        cs->hideContact(VFX_FALSE);
        cs->getInputbox()->setEnterKeyEnabled(VFX_FALSE);
	}
	else if (m_contactlist == NULL)
	{
		VfxWString itemText;
		VcpFormItemCustomFrame *frame_part = NULL;
		VcpFormItemBase *selectedItem = composer_form->getItem(itemInFocus);

		VfxSize formSize = composer_form->getSize();
		VfxSize ItemSize = selectedItem->getSize();
		VfxSize controlSize;

		controlSize.width = formSize.width;
		controlSize.height = formSize.height - ItemSize.height - composer_form->getContentTopGap();
	
		controlSize.height = (controlSize.height >= 0)? controlSize.height: 0;
		VFX_OBJ_CREATE(frame_part, VcpFormItemCustomFrame, composer_form);
		VFX_OBJ_CREATE_EX(m_contactlist, VappUcContactList, frame_part, (vfx_sys_wcslen(text)));
		/*for rotation*/
		m_contactlist->setSize(controlSize.width, controlSize.height);
		m_contactlist->m_signalListUpdated.connect(this, &VappComposerMainPage::onPhbSearchContactListUpdate);
		
		itemText.loadFromMem((VfxWChar *)text);
#ifdef __MMI_EMAIL__
		if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
		{
			m_contactlist->setAlignField(MMI_PHB_CONTACT_FIELD_EMAIL);
		}
		else
#endif
		if (app->m_service_cntxt->msg_type->caller_specific_msg_type == SRV_UC_MSG_TYPE_SMS_ONLY)
		{
		   m_contactlist->setAlignField(MMI_PHB_CONTACT_FIELD_NUMBER);
		}
		else
		{
			m_contactlist->setAlignField(MMI_PHB_CONTACT_FIELD_NUMBER | MMI_PHB_CONTACT_FIELD_EMAIL);
		}
	//	m_contactlist->setSearchString(itemText);			
	//	m_contactlist->getList();
#ifdef __MMI_EMAIL__
		if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
		{
			m_contactlist->updateHintList(text);
		}
		else
#endif
		{
			m_contactlist->setSearchString(itemText);			
			m_contactlist->getList();
		}
		
		//m_contactlist->m_menulist->m_signalItemTapped.connect(this, &VappComposerMainPage::onTapItem);		
		frame_part->setHeight(controlSize.height);
		frame_part->attachCustomFrame(m_contactlist);
		composer_form->addItem(frame_part, ID_CONTACT_SELECTOR_LIST_MENU);
		frame_part->setIsHidden(VFX_TRUE);
        cs->getInputbox()->setEnterKeyEnabled(VFX_TRUE);
		this->m_contactlist->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
						VFX_FRAME_ALIGNER_MODE_NONE, 
						VFX_FRAME_ALIGNER_MODE_SIDE,
						VFX_FRAME_ALIGNER_MODE_NONE);
	}
	else
	{
		m_contactlist->updateHintList(text);
        cs->getInputbox()->setEnterKeyEnabled(VFX_TRUE);
	}

}

VfxBool VappComposerMainPage::onRecipientCharInput(VcpContactSelector* recipientHead, VfxWChar *text)
{
		VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
		VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
	
		if (app->m_service_cntxt->msg->to_num >= app->vappUcGetMaxRecipientCount())
		{
			mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_RECIPIENT_NUMBER_EXCEED_ID)).getBuf());
			return VFX_FALSE;
		}

        if(text[0] == 10)
        {
            VcpTextEditor* r_editor = NULL;
            VfxWChar *addressString = NULL;
            VfxWString itemText;

            r_editor = recipientHead->getInputbox();
            addressString = r_editor->getText();
            if(vfx_sys_wcslen(addressString) != 0)
            {
                if (vapp_uc_is_ascii_string((S8*) addressString) && srv_uc_is_phone_number_valid((PS8)addressString))
                {
                    #ifdef __MMI_EMAIL__
                    if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
                    {
                        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_INVALID_RECIPIENT)).getBuf());
                    }
                    else
                    #endif
                    //need add
                    {
                        recipientHead->add(VFX_WSTR_EMPTY, itemText.loadFromMem((VfxWChar *)addressString), VFX_WSTR_EMPTY);
                        r_editor->deleteAll();
						r_editor->setEnterKeyEnabled(VFX_FALSE);
                        recipientHead->hideContact(VFX_FALSE);
                        recipientHead->checkUpdate();
			            restoreControls();
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
                    }
                }
                else if(app->m_service_cntxt->msg_type->caller_specific_msg_type != SRV_UC_MSG_TYPE_SMS_ONLY && srv_uc_is_email_addr_valid((U8*)addressString))
                {
                    recipientHead->add(VFX_WSTR_EMPTY,VFX_WSTR_EMPTY, itemText.loadFromMem((VfxWChar *)addressString));
                #ifdef __MMI_EMAIL__
                    if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
		            {
			            VappEmailComp::addRecentContact((WCHAR*) addressString);
		            }
                #endif
                    r_editor->deleteAll();
					r_editor->setEnterKeyEnabled(VFX_FALSE);
                    recipientHead->hideContact(VFX_FALSE);
                    recipientHead->checkUpdate();
			        restoreControls();
                }
                else
                {
                    mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_INVALID_RECIPIENT)).getBuf());
                }
            }
            return VFX_FALSE;
        }
        return VFX_TRUE;
}

void VappComposerMainPage::onToRCharInput(VfxWChar *text, VfxS32 curPos, VcpTextChangeEnum type, VfxBool *ret)
{
    if (type == VCP_TEXT_CHANGE_INSERT_CHAR)
    {
        *ret = onRecipientCharInput(m_contactSelectorTo, text);
    }
}

void VappComposerMainPage::onRecipientEditorActivated(VcpContactSelector* recipientHead, VcpTextEditor *editor, VfxBool activated)
{
	if (recipientHead == NULL)
	{
		return;
	}
    if (activated)
    {
       //check if need to use
		highlightedEditor = editor;
    }
    else
    {
        VcpTextEditor* r_editor = editor;//NULL;
        VfxWChar *addressString = NULL;
        VfxWString itemText;
        VfxS32 length = 0;
		VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
		VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);

        addressString = r_editor->getText();
        length = vfx_sys_wcslen(addressString);

        if(length != 0)
        {
          if(length == 1 && addressString[0] == 10)
 //         if(length == 1 && mmi_ucs2chr((PS8)addressString, 10) != NULL)
          {
             //skip
          }
          else
          {
            // if(length == 1 && mmi_ucs2chr((PS8)addressString, 10) != NULL)
             //need add
             if (vapp_uc_is_ascii_string((S8*) addressString) && srv_uc_is_phone_number_valid((PS8)addressString))
             {
                #ifdef __MMI_EMAIL__
                if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
                {
                    mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_INVALID_RECIPIENT)).getBuf());
                }
                else
                #endif
				if(app->recipientCheckMsgSize((VfxWChar *)addressString))
                {
                    recipientHead->add(VFX_WSTR_EMPTY, itemText.loadFromMem((VfxWChar *)addressString), VFX_WSTR_EMPTY);
                }
             }
             else if(app->m_service_cntxt->msg_type->caller_specific_msg_type != SRV_UC_MSG_TYPE_SMS_ONLY && srv_uc_is_email_addr_valid((U8*)addressString))
             {
        #ifdef __MMI_EMAIL__
		          if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
		          {
		              VappEmailComp::addRecentContact((WCHAR*) addressString);
	                   recipientHead->add(VFX_WSTR_EMPTY,VFX_WSTR_EMPTY, itemText.loadFromMem((VfxWChar *)addressString));
		          }
			      else
        #endif
			      if(app->recipientCheckMsgSize((VfxWChar *)addressString))
			      {
	                 recipientHead->add(VFX_WSTR_EMPTY,VFX_WSTR_EMPTY, itemText.loadFromMem((VfxWChar *)addressString));
			      }
			 }
             else
             {
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_INVALID_RECIPIENT)).getBuf());
             }
          }
        }
	if(m_contactlist && m_contactlist->isMenuListActivated())
	{
	    /*Restore the controls*/		
	    restoreControls();
	}
        r_editor->deleteAll();
		r_editor->setEnterKeyEnabled(VFX_FALSE);
    }
}
void VappComposerMainPage::onToEditorActivated(VcpTextEditor *editor, VfxBool activated)
{
    onRecipientEditorActivated(m_contactSelectorTo, editor, activated);
    return;
}


void VappComposerMainPage::onRecipientMoreButtonClicked(VcpContactSelector* obj)
{
  // obj->getInputbox()->deactivate();
	onRecipientEditorActivated(obj, obj->getInputbox(), VFX_TRUE);
	VFX_OBJ_CREATE_EX(recipientListPage, VAppUcRecipientlistPage, getMainScr(), (obj));
	getMainScr()->pushPage(0, recipientListPage);
}

void VappComposerMainPage::insertContactSelector(void)
{
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);

#if defined(__MMI_MESSAGES_TEMPLATE__) || defined(__MMI_MMS_TEMPLATE_SUPPORT__)
    if((app->operation_type != UC_OPERATION_WRITE_NEW_SMS_TEMPLATE) &&
        (app->operation_type != UC_OPERATION_EDIT_SMS_TEMPLATE) && 
        (app->operation_type != UC_OPERATION_WRITE_NEW_MMS_TEMPLATE) &&
        (app->operation_type != UC_OPERATION_EDIT_MMS_TEMPLATE))
#endif            
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
    
        VfxS32 xPos, yPos;
        xPos = VAPP_UC_LEFT_MARGIN;
        yPos = 0;
        if(m_contactSelectorTo!= NULL)
        {
    	#ifdef __MMI_EMAIL__
			if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
			{
				if(VappEmailComp::isSendButtonAvailable())	
				{
					//just skip
				}
				else
				{
					if ((vappUcGetValidSimInfo() == vappUcGetInvalidSimInfo())&& !vappUcFlightModecheck())
					{
						m_functionBarToFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
					}
				}
			}
			else
    	#endif
			//if (vappUcGetValidSimInfo() == vappUcGetInvalidSimInfo())kuldeep_gplus
			if (!isSendButtonAvailable())
			{
				m_functionBarToFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
			}
            else
            {
                m_functionBarToFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_FALSE);
            }
            
        }
        else
        {
            VcpTextEditor* r_editor = NULL;
     
            VFX_OBJ_CREATE(frame_part1, VcpFormItemCustomFrame, composer_form);
            VFX_OBJ_CREATE(m_contactSelectorTo, VcpContactSelector, frame_part1);
            m_contactSelectorTo->setPos(xPos, yPos);
            m_contactSelectorTo->setBounds(VfxRect(0, 0, (mainScreenSize.width - 2 * VAPP_UC_LEFT_MARGIN), VCP_CONTACT_SELECTOR_INPUTBOX_HEIGHT + VCP_CONTACT_SELECTOR_TOP_GAP + VCP_CONTACT_SELECTOR_BUTTOM_GAP));

        
            // set hint text
            m_contactSelectorTo->setHintText(VFX_WSTR_RES(STR_ID_VAPP_UC_TO_AS_HINT));
         
            // Add contact
            srv_uc_addr_struct *temp_address = app->m_service_cntxt->msg->to_head;
           while (temp_address)
            {
                VfxWString itemText;
                if(temp_address->group == SRV_UC_ADDRESS_GROUP_TYPE_TO)
                {
                    U16 recipient_name[(SRV_UC_MAX_EMAIL_LEN + 2) * ENCODING_LENGTH] = {};
        
                    memset(app->done->to, 0, (SRV_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);

		            if(temp_address->type == SRV_UC_ADDRESS_TYPE_PHONE_NUMBER)
		            {
                        mmi_asc_n_to_ucs2((S8*) app->done->to, (S8*)temp_address->addr, strlen((char*)temp_address->addr));
                        srv_phb_get_name_by_number((U16 *)app->done->to, recipient_name, SRV_UC_MAX_EMAIL_LEN);
                        if(mmi_ucs2strlen((S8*) recipient_name) == 0)
                        {
                            m_contactSelectorTo->add(VFX_WSTR_EMPTY, itemText.loadFromMem((VfxWChar *)app->done->to), VFX_WSTR_EMPTY);
                        }
                        else
                        {
                            m_contactSelectorTo->add(itemText.loadFromMem((VfxWChar *)recipient_name), itemText.loadFromMem((VfxWChar *)app->done->to), VFX_WSTR_EMPTY);
                        }
		            }
		            else if(temp_address->type == SRV_UC_ADDRESS_TYPE_EMAIL)
		            {
                        mmi_ucs2ncpy((S8*) app->done->to, (S8*) temp_address->addr, mmi_ucs2strlen((S8*) temp_address->addr));
                     //   if(mmi_ucs2strlen((S8*) recipient_name) == 0)
                        {
                            m_contactSelectorTo->add(VFX_WSTR_EMPTY, VFX_WSTR_EMPTY, itemText.loadFromMem((VfxWChar *)app->done->to));
                        }
                     //   else
                        {
                       //     m_contactSelectorTo->add(itemText.loadFromMem((VfxWChar *)recipient_name), VFX_WSTR_EMPTY, itemText.loadFromMem((VfxWChar *)app->done->to));
                        }
		            }
		            else
		            {
			            ASSERT(0);
		            }
                }
               temp_address = temp_address->next;
           }

           // connect signal
            r_editor = m_contactSelectorTo->getInputbox();
            r_editor->setText(VFX_WSTR_EMPTY, SRV_UC_MAX_EMAIL_LEN);
            #ifdef __MMI_EMAIL__
            if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
            {
				  r_editor->setIME(IMM_INPUT_TYPE_EMAIL|IMM_INPUT_TYPE_SENTENCE, IME_SETTING_FLAG_NONE);
            }
            #endif
			VFX_OBJ_CREATE(m_functionBarToFrame, VcpFunctionBar, this);
			m_functionBarToFrame->addItem(ID_TOOLBAR_PREV,VFX_WSTR_RES(STR_GLOBAL_PREV));
			m_functionBarToFrame->addItem(ID_TOOLBAR_NEXT,VFX_WSTR_RES(STR_GLOBAL_NEXT));
			if(getItemToHilight(m_contactSelectorTo, ID_TOOLBAR_PREV) == NULL)
			{
				m_functionBarToFrame->setDisableItem(ID_TOOLBAR_PREV, VFX_TRUE);
			}
			if(getItemToHilight(m_contactSelectorTo, ID_TOOLBAR_NEXT) == NULL)
			{
				m_functionBarToFrame->setDisableItem(ID_TOOLBAR_NEXT, VFX_TRUE);
			}
            #ifdef __MMI_EMAIL__
            if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
            {
				m_functionBarToFrame->addItem(ID_TOOLBAR_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE));
			}
			#endif
			m_functionBarToFrame->addItem(ID_TOOLBAR_SEND,VFX_WSTR_RES(STR_GLOBAL_SEND));
			m_functionBarToFrame->setItemSpecial(ID_TOOLBAR_SEND);
			onEntertoggleString();
	#ifdef __MMI_EMAIL__
			if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
			{
				if(VappEmailComp::isSendButtonAvailable())	
				{
					//just skip
				}
				else
				{
					if ((vappUcGetValidSimInfo() == vappUcGetInvalidSimInfo())&& !vappUcFlightModecheck())
					{
						m_functionBarToFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
					}
				}
			}
			else
	#endif
			//if (vappUcGetValidSimInfo() == vappUcGetInvalidSimInfo())kuldeep_gplus
			if (!isSendButtonAvailable())
			{
				m_functionBarToFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
			}
			r_editor->setFunctionBar(m_functionBarToFrame);
			m_functionBarToFrame->m_signalButtonTap.connect(this, &VappComposerMainPage::onToolBarClick);

            r_editor->m_signalBeforeChange.connect(this, &VappComposerMainPage::onToRCharInput); /* connect the signal of any text changed in recipient */
            r_editor->setEnterKeyStyle(IME_VK_ENTER_KEY_STYLE_DONE);
            r_editor->setEnterKeyEnabled(VFX_FALSE);
            r_editor->m_signalEnterKeyClicked.connect(this, &VappComposerMainPage::onToEnterKeyClicked);
            r_editor->m_signalActivated.connect(this, &VappComposerMainPage::onToEditorActivated);
            m_contactSelectorTo->m_signalSearchButtonClicked.connect(this, &VappComposerMainPage::csToOnSearchButtonClicked);
            m_contactSelectorTo->m_signalTextChanged.connect(this, &VappComposerMainPage::csOnTextChanged);
            m_contactSelectorTo->m_signalBoundsChanged.connect(this,&VappComposerMainPage::csOnRcipientHeightChange);
            m_contactSelectorTo->m_signalContactChanged.connect(this, &VappComposerMainPage::onContactListUpdate);       /* connect the signal of any text changed */
            m_contactSelectorTo->m_signalMoreButtonClicked.connect(this, &VappComposerMainPage::onRecipientMoreButtonClicked);

        
            // Adding to form
            frame_part1->setHeight(m_contactSelectorTo->getSize().height);
            frame_part1->attachCustomFrame(m_contactSelectorTo);
            composer_form->addItem(frame_part1, ID_RECIPIENT_TO);
			m_itemsAlraedyDraw |=   ID_RECIPIENT_TO; //Rahul Added
        }
    }
}

#ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__
void VappComposerMainPage::csOnCcRcipientHeightChange(VfxFrame *f, const VfxRect &r)
{
    if(r.size != f->getSize())
    {
        frame_part2->setHeight(f->getSize().height);
        //frame_part1->setHeight(m_contactSelectorTo->getSize().height);
    }
}

void VappComposerMainPage::csOnCcTextChanged(VcpContactSelector *cs, VfxWChar *text)
{
    //VfxS32 length = 0;
    //VfxWString itemText;
    // inputbox text changed, search in phonebook and update list
    m_contactSelectorCc->hideContact(VFX_TRUE);

    // search in phonebook and display reslut list
    // TODO:
}

void VappComposerMainPage::onCcRCharInput(VfxWChar *text, VfxS32 curPos, VcpTextChangeEnum type, VfxBool *ret)
{
    if (type == VCP_TEXT_CHANGE_INSERT_CHAR)
    {
        *ret = onRecipientCharInput(m_contactSelectorCc, text);
    }
}

void VappComposerMainPage::onCcEditorActivated(VcpTextEditor *editor, VfxBool activated)
{
    onRecipientEditorActivated(m_contactSelectorCc, editor, activated);
    return;
}


void VappComposerMainPage::insertContactSelectorCc(void)
{
    VfxBool need_to_show_cc = VFX_FALSE;
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
            
	if(need_to_show_cc || ((m_itemForceOn & ID_RECIPIENT_CC) == ID_RECIPIENT_CC))
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        VfxS32 xPos, yPos;
        xPos = VAPP_UC_LEFT_MARGIN;
        yPos = 0;
        if(m_contactSelectorCc!= NULL)
        {
        #ifdef __MMI_EMAIL__
			if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
			{
				if(VappEmailComp::isSendButtonAvailable())	
				{
					//just skip
				}
				else
				{
					if ((vappUcGetValidSimInfo() == vappUcGetInvalidSimInfo())&& !vappUcFlightModecheck())
					{
						m_functionBarToFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
					}
				}
			}
			else
    	#endif
			//if (vappUcGetValidSimInfo() == vappUcGetInvalidSimInfo())kuldeep_gplus
			if (!isSendButtonAvailable())
			{
				m_functionBarCcFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
			}
            else
            {
                m_functionBarCcFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_FALSE);
            }
        }
        else
        {
            VcpTextEditor* r_editor = NULL;

            VFX_OBJ_CREATE(frame_part2, VcpFormItemCustomFrame, composer_form);
            VFX_OBJ_CREATE(m_contactSelectorCc, VcpContactSelector, frame_part2);
            m_contactSelectorCc->setPos(xPos, yPos);
            m_contactSelectorCc->setBounds(VfxRect(0, 0, (mainScreenSize.width - 2 * VAPP_UC_LEFT_MARGIN), VCP_CONTACT_SELECTOR_INPUTBOX_HEIGHT + VCP_CONTACT_SELECTOR_TOP_GAP + VCP_CONTACT_SELECTOR_BUTTOM_GAP));
			m_contactSelectorCc->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
											VFX_FRAME_ALIGNER_MODE_NONE, 
											VFX_FRAME_ALIGNER_MODE_SIDE,
											VFX_FRAME_ALIGNER_MODE_NONE);

            // set hint text
            m_contactSelectorCc->setHintText(VFX_WSTR_RES(STR_ID_VAPP_UC_CC_AS_HINT));
         
            // Add contact
            srv_uc_addr_struct *temp_address = app->m_service_cntxt->msg->to_head;
           while (temp_address)
            {
                VfxWString itemText;
                if(temp_address->group == SRV_UC_ADDRESS_GROUP_TYPE_CC)
                {
                    U16 recipient_name[(SRV_UC_MAX_EMAIL_LEN + 2) * ENCODING_LENGTH] = {};

                    memset(app->done->to, 0, (SRV_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);
		            if(temp_address->type == SRV_UC_ADDRESS_TYPE_PHONE_NUMBER)
		            {
			            mmi_asc_n_to_ucs2((S8*) app->done->to, (S8*)temp_address->addr, strlen((char*)temp_address->addr));
                        srv_phb_get_name_by_number((U16 *)app->done->to, recipient_name, SRV_UC_MAX_EMAIL_LEN);
                        if(mmi_ucs2strlen((S8*) recipient_name) == 0)
                        {
                            m_contactSelectorCc->add(VFX_WSTR_EMPTY, itemText.loadFromMem((VfxWChar *)app->done->to), VFX_WSTR_EMPTY);
                        }
                        else
                        {
                            m_contactSelectorCc->add(itemText.loadFromMem((VfxWChar *)recipient_name), itemText.loadFromMem((VfxWChar *)app->done->to), VFX_WSTR_EMPTY);
                        }
		            }
		            else if(temp_address->type == SRV_UC_ADDRESS_TYPE_EMAIL)
		            {
                        mmi_ucs2ncpy((S8*) app->done->to, (S8*) temp_address->addr, mmi_ucs2strlen((S8*) temp_address->addr));
                     //   if(mmi_ucs2strlen((S8*) recipient_name) == 0)
                        {
                            m_contactSelectorCc->add(VFX_WSTR_EMPTY, VFX_WSTR_EMPTY, itemText.loadFromMem((VfxWChar *)app->done->to));
                        }
                     //   else
                        {
                       //     m_contactSelectorCc->add(itemText.loadFromMem((VfxWChar *)recipient_name), VFX_WSTR_EMPTY, itemText.loadFromMem((VfxWChar *)app->done->to));
                        }
		            }
		            else
		            {
			            ASSERT(0);
		            }
                }
               temp_address = temp_address->next;
           }

           // connect signal
            r_editor = m_contactSelectorCc->getInputbox();
            r_editor->setText(VFX_WSTR_EMPTY, SRV_UC_MAX_EMAIL_LEN);
            #ifdef __MMI_EMAIL__
            if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
            {
				  r_editor->setIME(IMM_INPUT_TYPE_EMAIL|IMM_INPUT_TYPE_SENTENCE, IME_SETTING_FLAG_NONE);
            }
            #endif
			VFX_OBJ_CREATE(m_functionBarCcFrame, VcpFunctionBar, this);
			m_functionBarCcFrame->addItem(ID_TOOLBAR_PREV,VFX_WSTR_RES(STR_GLOBAL_PREV));
			m_functionBarCcFrame->addItem(ID_TOOLBAR_NEXT,VFX_WSTR_RES(STR_GLOBAL_NEXT));
			if(getItemToHilight(m_contactSelectorCc, ID_TOOLBAR_PREV) == NULL)
			{
				m_functionBarCcFrame->setDisableItem(ID_TOOLBAR_PREV, VFX_TRUE);
			}
			if(getItemToHilight(m_contactSelectorCc, ID_TOOLBAR_NEXT) == NULL)
			{
				m_functionBarCcFrame->setDisableItem(ID_TOOLBAR_NEXT, VFX_TRUE);
			}
            #ifdef __MMI_EMAIL__
            if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
            {
				m_functionBarCcFrame->addItem(ID_TOOLBAR_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE));
			}
			#endif
			m_functionBarCcFrame->addItem(ID_TOOLBAR_SEND,VFX_WSTR_RES(STR_GLOBAL_SEND));
			m_functionBarCcFrame->setItemSpecial(ID_TOOLBAR_SEND);
            onEntertoggleString();
	#ifdef __MMI_EMAIL__
			if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
			{
				if(VappEmailComp::isSendButtonAvailable())	
				{
					//just skip
				}
				else
				{
					if ((vappUcGetValidSimInfo() == vappUcGetInvalidSimInfo())&& !vappUcFlightModecheck())
					{
						m_functionBarToFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
					}
				}
			}
			else
	#endif
			//if (vappUcGetValidSimInfo() == vappUcGetInvalidSimInfo())kuldeep_gplus
			if (!isSendButtonAvailable())
			{
				m_functionBarCcFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
			}
			r_editor->setFunctionBar(m_functionBarCcFrame);
			m_functionBarCcFrame->m_signalButtonTap.connect(this, &VappComposerMainPage::onToolBarClick);

            r_editor->m_signalBeforeChange.connect(this, &VappComposerMainPage::onCcRCharInput); /* connect the signal of any text changed in recipient */
            r_editor->setEnterKeyStyle(IME_VK_ENTER_KEY_STYLE_DONE);
			r_editor->setEnterKeyEnabled(VFX_FALSE);
            r_editor->m_signalEnterKeyClicked.connect(this, &VappComposerMainPage::onCcEnterKeyClicked);
            r_editor->m_signalActivated.connect(this, &VappComposerMainPage::onCcEditorActivated);
            m_contactSelectorCc->m_signalSearchButtonClicked.connect(this, &VappComposerMainPage::csCCOnSearchButtonClicked);
            m_contactSelectorCc->m_signalTextChanged.connect(this, &VappComposerMainPage::csOnTextChanged);
            m_contactSelectorCc->m_signalBoundsChanged.connect(this,&VappComposerMainPage::csOnCcRcipientHeightChange);
            m_contactSelectorCc->m_signalContactChanged.connect(this, &VappComposerMainPage::onContactListUpdate);       /* connect the signal of any text changed */
			m_contactSelectorCc->m_signalMoreButtonClicked.connect(this, &VappComposerMainPage::onRecipientMoreButtonClicked);

            frame_part2->setHeight(m_contactSelectorCc->getSize().height);
            frame_part2->attachCustomFrame(m_contactSelectorCc);
	        if(VappUcGetPositionToInsert(ID_RECIPIENT_CC) == 0)
	        {
		        composer_form->addItem(frame_part2, ID_RECIPIENT_CC);
	        }
	        else
	        {
		        composer_form->insertItem(frame_part2, VappUcGetPositionToInsert(ID_RECIPIENT_CC), ID_RECIPIENT_CC);	
	        }
			m_itemsAlraedyDraw |=  ID_RECIPIENT_CC;	
        }
    }
}

void VappComposerMainPage::csOnBccRcipientHeightChange(VfxFrame *f, const VfxRect &r)
{
    if(r.size != f->getSize())
    {
        frame_part3->setHeight(f->getSize().height);
        //frame_part1->setHeight(m_contactSelectorTo->getSize().height);
    }
}


void VappComposerMainPage::onBccRCharInput(VfxWChar *text, VfxS32 curPos, VcpTextChangeEnum type, VfxBool *ret)
{
    if (type == VCP_TEXT_CHANGE_INSERT_CHAR)
    {
        *ret = onRecipientCharInput(m_contactSelectorBcc, text);
    }
}

void VappComposerMainPage::onBccEditorActivated(VcpTextEditor *editor, VfxBool activated)
{
    onRecipientEditorActivated(m_contactSelectorBcc, editor, activated);
    return;
}
#endif /* #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__ */

void VappComposerMainPage::onRecipientEnterKeyClicked(VcpContactSelector* recipientHead)
{
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
    VcpTextEditor* r_editor = NULL;
    VfxWChar *addressString = NULL;
    VfxWString itemText;

	if (app->m_service_cntxt->msg->to_num >= app->vappUcGetMaxRecipientCount())
	{
		mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_RECIPIENT_NUMBER_EXCEED_ID)).getBuf());
		return;
	}


    r_editor = recipientHead->getInputbox();
    addressString = r_editor->getText();
    if(vfx_sys_wcslen(addressString) != 0)
    {
        if (vapp_uc_is_ascii_string((S8*) addressString) && srv_uc_is_phone_number_valid((PS8)addressString))
        {
            #ifdef __MMI_EMAIL__
            if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
            {
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_INVALID_RECIPIENT)).getBuf());
            }
            else
            #endif
            
			if(mmi_ucs2strlen((S8*)addressString) > SRV_UC_MAX_PHONE_NUMBER_LEN)
			{
				mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_NUMBER_LENGTH_EXCEED_ID)).getBuf());
			    					
			}
			else if(app->recipientCheckMsgSize((VfxWChar *)addressString))
            {
                recipientHead->add(VFX_WSTR_EMPTY, itemText.loadFromMem((VfxWChar *)addressString), VFX_WSTR_EMPTY);
                r_editor->deleteAll();
				r_editor->setEnterKeyEnabled(VFX_FALSE);
                recipientHead->hideContact(VFX_FALSE);
                recipientHead->checkUpdate();
                restoreControls();
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            }
        }
        else if(app->m_service_cntxt->msg_type->caller_specific_msg_type != SRV_UC_MSG_TYPE_SMS_ONLY && srv_uc_is_email_addr_valid((U8*)addressString))
        {
            recipientHead->add(VFX_WSTR_EMPTY,VFX_WSTR_EMPTY, itemText.loadFromMem((VfxWChar *)addressString));
    #ifdef __MMI_EMAIL__
	    if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
	    {
		    VappEmailComp::addRecentContact((WCHAR*) addressString);
	    }
    #endif
		 if(app->recipientCheckMsgSize((VfxWChar *)addressString))
		 {
            r_editor->deleteAll();
			r_editor->setEnterKeyEnabled(VFX_FALSE);
            recipientHead->hideContact(VFX_FALSE);
            recipientHead->checkUpdate();
            restoreControls();
		  }
        }
        else
        {
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_INVALID_RECIPIENT)).getBuf());
        }
    }
}

void VappComposerMainPage::onToEnterKeyClicked(VcpTextEditor *editor, IMEVKEnterKeyStyleEnum enterKeyStyle)
{
    onRecipientEnterKeyClicked(m_contactSelectorTo);
}

#ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__
void VappComposerMainPage::onCcEnterKeyClicked(VcpTextEditor *editor, IMEVKEnterKeyStyleEnum enterKeyStyle)
{
    onRecipientEnterKeyClicked(m_contactSelectorCc);
}


void VappComposerMainPage::onBccEnterKeyClicked(VcpTextEditor *editor, IMEVKEnterKeyStyleEnum enterKeyStyle)
{
    onRecipientEnterKeyClicked(m_contactSelectorBcc);
}


void VappComposerMainPage::insertContactSelectorBcc(void)
{
    VfxBool need_to_show_bcc = VFX_FALSE;
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
            
	if(need_to_show_bcc || ((m_itemForceOn & ID_RECIPIENT_BCC) == ID_RECIPIENT_BCC))
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        VfxS32 xPos, yPos;
        xPos = VAPP_UC_LEFT_MARGIN;
        yPos = 0;
        if(m_contactSelectorBcc!= NULL)
        {
        #ifdef __MMI_EMAIL__
            if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
            {
                if(VappEmailComp::isSendButtonAvailable())  
                {
                    //just skip
                }
                else
                {
                    if ((vappUcGetValidSimInfo() == vappUcGetInvalidSimInfo()) && !vappUcFlightModecheck())
                    {
                        m_functionBarToFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
                    }
                }
            }
            else
    #endif
            //if (vappUcGetValidSimInfo() == vappUcGetInvalidSimInfo())kuldeep_gplus
            if (!isSendButtonAvailable())
            {
                m_functionBarBccFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
            }
            else
            {
                m_functionBarBccFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_FALSE);
            }
        }
        else
        {
            VcpTextEditor* r_editor = NULL;

            VFX_OBJ_CREATE(frame_part3, VcpFormItemCustomFrame, composer_form);
            VFX_OBJ_CREATE(m_contactSelectorBcc, VcpContactSelector, frame_part3);
            m_contactSelectorBcc->setPos(xPos, yPos);
            m_contactSelectorBcc->setBounds(VfxRect(0, 0, (mainScreenSize.width - 2 * VAPP_UC_LEFT_MARGIN), VCP_CONTACT_SELECTOR_INPUTBOX_HEIGHT + VCP_CONTACT_SELECTOR_TOP_GAP + VCP_CONTACT_SELECTOR_BUTTOM_GAP));
			m_contactSelectorBcc->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
											VFX_FRAME_ALIGNER_MODE_NONE, 
											VFX_FRAME_ALIGNER_MODE_SIDE,
											VFX_FRAME_ALIGNER_MODE_NONE);
            // set hint text
            m_contactSelectorBcc->setHintText(VFX_WSTR_RES(STR_ID_VAPP_UC_BCC_AS_HINT));
         
            // Add contact
            srv_uc_addr_struct *temp_address = app->m_service_cntxt->msg->to_head;
           while (temp_address)
            {
                VfxWString itemText;
                if(temp_address->group == SRV_UC_ADDRESS_GROUP_TYPE_BCC)
                {
                    U16 recipient_name[(SRV_UC_MAX_EMAIL_LEN + 2) * ENCODING_LENGTH] = {};

                    memset(app->done->to, 0, (SRV_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);
		            if(temp_address->type == SRV_UC_ADDRESS_TYPE_PHONE_NUMBER)
		            {
			            mmi_asc_n_to_ucs2((S8*) app->done->to, (S8*)temp_address->addr, strlen((char*)temp_address->addr));
                        srv_phb_get_name_by_number((U16 *)app->done->to, recipient_name, SRV_UC_MAX_EMAIL_LEN);
                        if(mmi_ucs2strlen((S8*) recipient_name) == 0)
                        {
                            m_contactSelectorBcc->add(VFX_WSTR_EMPTY, itemText.loadFromMem((VfxWChar *)app->done->to), VFX_WSTR_EMPTY);
                        }
                        else
                        {
                            m_contactSelectorBcc->add(itemText.loadFromMem((VfxWChar *)recipient_name), itemText.loadFromMem((VfxWChar *)app->done->to), VFX_WSTR_EMPTY);
                        }
		            }
		            else if(temp_address->type == SRV_UC_ADDRESS_TYPE_EMAIL)
		            {
                        mmi_ucs2ncpy((S8*) app->done->to, (S8*) temp_address->addr, mmi_ucs2strlen((S8*) temp_address->addr));
                     //   if(mmi_ucs2strlen((S8*) recipient_name) == 0)
                        {
                            m_contactSelectorBcc->add(VFX_WSTR_EMPTY, VFX_WSTR_EMPTY, itemText.loadFromMem((VfxWChar *)app->done->to));
                        }
                     //   else
                        {
                       //     m_contactSelectorBcc->add(itemText.loadFromMem((VfxWChar *)recipient_name), VFX_WSTR_EMPTY, itemText.loadFromMem((VfxWChar *)app->done->to));
                        }
		            }
		            else
		            {
			            ASSERT(0);
		            }
                }
               temp_address = temp_address->next;
           }

           // connect signal
            r_editor = m_contactSelectorBcc->getInputbox();
            r_editor->setText(VFX_WSTR_EMPTY, SRV_UC_MAX_EMAIL_LEN);
            #ifdef __MMI_EMAIL__
            if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
            {
				  r_editor->setIME(IMM_INPUT_TYPE_EMAIL|IMM_INPUT_TYPE_SENTENCE, IME_SETTING_FLAG_NONE);
            }
            #endif
			VFX_OBJ_CREATE(m_functionBarBccFrame, VcpFunctionBar, this);
			m_functionBarBccFrame->addItem(ID_TOOLBAR_PREV,VFX_WSTR_RES(STR_GLOBAL_PREV));
			m_functionBarBccFrame->addItem(ID_TOOLBAR_NEXT,VFX_WSTR_RES(STR_GLOBAL_NEXT));
			if(getItemToHilight(m_contactSelectorBcc, ID_TOOLBAR_PREV) == NULL)
			{
				m_functionBarBccFrame->setDisableItem(ID_TOOLBAR_PREV, VFX_TRUE);
			}
			if(getItemToHilight(m_contactSelectorBcc, ID_TOOLBAR_NEXT) == NULL)
			{
				m_functionBarBccFrame->setDisableItem(ID_TOOLBAR_NEXT, VFX_TRUE);
			}
            #ifdef __MMI_EMAIL__
            if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
            {
				m_functionBarBccFrame->addItem(ID_TOOLBAR_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE));
			}
			#endif
			m_functionBarBccFrame->addItem(ID_TOOLBAR_SEND,VFX_WSTR_RES(STR_GLOBAL_SEND));
			m_functionBarBccFrame->setItemSpecial(ID_TOOLBAR_SEND);
			onEntertoggleString();
	#ifdef __MMI_EMAIL__
			if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
			{
				if(VappEmailComp::isSendButtonAvailable())	
				{
					//just skip
				}
				else
				{
					if ((vappUcGetValidSimInfo() == vappUcGetInvalidSimInfo()) && !vappUcFlightModecheck())
					{
						m_functionBarToFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
					}
				}
			}
			else
	#endif
			//if (vappUcGetValidSimInfo() == vappUcGetInvalidSimInfo())kuldeep_gplus
			if (!isSendButtonAvailable())
			{
				m_functionBarBccFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
			}
			r_editor->setFunctionBar(m_functionBarBccFrame);
			m_functionBarBccFrame->m_signalButtonTap.connect(this, &VappComposerMainPage::onToolBarClick);

            r_editor->m_signalBeforeChange.connect(this, &VappComposerMainPage::onBccRCharInput); /* connect the signal of any text changed in recipient */
            r_editor->setEnterKeyStyle(IME_VK_ENTER_KEY_STYLE_DONE);
			r_editor->setEnterKeyEnabled(VFX_FALSE);
            r_editor->m_signalEnterKeyClicked.connect(this, &VappComposerMainPage::onBccEnterKeyClicked);
            r_editor->m_signalActivated.connect(this, &VappComposerMainPage::onBccEditorActivated);
            m_contactSelectorBcc->m_signalSearchButtonClicked.connect(this, &VappComposerMainPage::csBCCOnSearchButtonClicked);
            m_contactSelectorBcc->m_signalTextChanged.connect(this, &VappComposerMainPage::csOnTextChanged);
            m_contactSelectorBcc->m_signalBoundsChanged.connect(this,&VappComposerMainPage::csOnBccRcipientHeightChange);
            m_contactSelectorBcc->m_signalContactChanged.connect(this, &VappComposerMainPage::onContactListUpdate);       /* connect the signal of any text changed */
            m_contactSelectorBcc->m_signalMoreButtonClicked.connect(this, &VappComposerMainPage::onRecipientMoreButtonClicked);


            frame_part3->setHeight(m_contactSelectorBcc->getSize().height);
            frame_part3->attachCustomFrame(m_contactSelectorBcc);
	        if(VappUcGetPositionToInsert(ID_RECIPIENT_BCC) == 0)
	        {
		        composer_form->addItem(frame_part3, ID_RECIPIENT_BCC);
	        }
	        else
	        {
		        composer_form->insertItem(frame_part3, VappUcGetPositionToInsert(ID_RECIPIENT_BCC), ID_RECIPIENT_BCC);
	        }
			m_itemsAlraedyDraw |=  ID_RECIPIENT_BCC;
        }
    }
}
#endif

void VappComposerMainPage::insertSubjectItem(void)
{
    MMI_BOOL need_to_show_subject;
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);

	if(app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_LEMEI_MMS)
	{
		if( (m_itemForceOn & ID_SUBJECT) == ID_SUBJECT)
		{
			m_itemForceOn |= ~ID_SUBJECT;
			app->main->m_itemForceOn |= ~UC_SUBJECT;		
		}
		return;
	}
    if (mmi_ucs2strlen((S8*) app->m_service_cntxt->msg->subject) >0)
    {
		if( !((m_itemForceOn & ID_SUBJECT) == ID_SUBJECT))
		{
			m_itemForceOn |= ID_SUBJECT;
			app->main->m_itemForceOn |= UC_SUBJECT;		
		}
	    need_to_show_subject = MMI_TRUE;
    }
    else
    {
	    need_to_show_subject = MMI_FALSE;
    }

    if(m_BackUpitemsAlraedyDraw == 0 && (need_to_show_subject || ((m_itemForceOn & ID_SUBJECT) == ID_SUBJECT)))
    {
        if(textEditorSubject)
        {
           textEditorSubject->setText(srv_uc_get_subject(app->main->instance), app->vappUcGetMaxSubjectLength(), VFX_TRUE);
           frame_part4->setIsHidden(VFX_FALSE);

       	#ifdef __MMI_EMAIL__
			if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
			{
				if(VappEmailComp::isSendButtonAvailable())	
				{
					//just skip
				}
				else
				{
					if ((vappUcGetValidSimInfo() == vappUcGetInvalidSimInfo())&& !vappUcFlightModecheck())
					{
						m_functionBarToFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
					}
				}
			}
			else
        #endif
			//if (vappUcGetValidSimInfo() == vappUcGetInvalidSimInfo())kuldeep_gplus
			if (!isSendButtonAvailable())
			{
				m_functionBarSubjectFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
			}
            else
            {
                m_functionBarSubjectFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_FALSE);
            }
                
        }
        else
        {
           VfxWString text;

           VFX_OBJ_CREATE(frame_part4, VcpFormItemCustomFrame, composer_form);
           VFX_OBJ_CREATE(textEditorSubject, VcpTextEditor , frame_part4);
           textEditorSubject->setSize(composer_form->getSize().width - (2 * VAPP_UC_LEFT_MARGIN), VAPP_UC_STANDARD_BTN_HEIGHT);
           textEditorSubject->setPos(VAPP_UC_LEFT_MARGIN, 0);
			/*For screen rotation*/
		   textEditorSubject->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
											VFX_FRAME_ALIGNER_MODE_NONE, 
											VFX_FRAME_ALIGNER_MODE_SIDE,
											VFX_FRAME_ALIGNER_MODE_NONE);
		   						
			#ifdef __OP01__
				textEditorSubject->setText(srv_uc_get_subject(app->main->instance), app->vappUcGetMaxSubjectLength(), VFX_TRUE,VCP_TEXT_ENCODING_UTF8);
			#else
				textEditorSubject->setText(srv_uc_get_subject(app->main->instance), app->vappUcGetMaxSubjectLength(), VFX_TRUE);
			#endif
           textEditorSubject->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);

		   textEditorSubject->setHint(VFX_WSTR_RES(STR_ID_VAPP_UC_TXT_EDITOR_SUBJECT_HINT_ID));           
           frame_part4->attachCustomFrame(textEditorSubject);
           frame_part4->setHeight(VAPP_UC_STANDARD_BTN_HEIGHT + VCPFRM_ITEM_HORZ_GAP);
            textEditorSubject->setEnterKeyStyle(IME_VK_ENTER_KEY_STYLE_DONE);
            textEditorSubject->setEnterKeyEnabled(VFX_TRUE);
            textEditorSubject->m_signalEnterKeyClicked.connect(this, &VappComposerMainPage::onSubjectEnterKeyClicked);
           textEditorSubject->m_signalBeforeChange.connect(this, &VappComposerMainPage::onSubjectCharInput); /* connect the signal of any text changed */
           textEditorSubject->m_signalTextChanged.connect(this, &VappComposerMainPage::onSubjectTextChanged); /* connect the signal of any text changed */
            textEditorSubject->m_signalActivated.connect(this, &VappComposerMainPage::onSubjectActivated);

			VFX_OBJ_CREATE(m_functionBarSubjectFrame, VcpFunctionBar, this);
			m_functionBarSubjectFrame->addItem(ID_TOOLBAR_PREV,VFX_WSTR_RES(STR_GLOBAL_PREV));
			m_functionBarSubjectFrame->addItem(ID_TOOLBAR_NEXT,VFX_WSTR_RES(STR_GLOBAL_NEXT));
			if(getItemToHilight(textEditorSubject, ID_TOOLBAR_PREV) == NULL)
			{
				m_functionBarSubjectFrame->setDisableItem(ID_TOOLBAR_PREV, VFX_TRUE);
			}
			if(getItemToHilight(textEditorSubject, ID_TOOLBAR_NEXT) == NULL)
			{
				m_functionBarSubjectFrame->setDisableItem(ID_TOOLBAR_NEXT, VFX_TRUE);
			}
            #ifdef __MMI_EMAIL__
            if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
            {
				m_functionBarSubjectFrame->addItem(ID_TOOLBAR_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE));
			}
			#endif
            #if defined(__MMI_MESSAGES_TEMPLATE__) || defined(__MMI_MMS_TEMPLATE_SUPPORT__)
			if((app->operation_type == UC_OPERATION_WRITE_NEW_SMS_TEMPLATE) ||
				(app->operation_type == UC_OPERATION_EDIT_SMS_TEMPLATE) ||
				(app->operation_type == UC_OPERATION_WRITE_NEW_MMS_TEMPLATE) ||
				(app->operation_type == UC_OPERATION_EDIT_MMS_TEMPLATE))
			{
				m_functionBarSubjectFrame->addItem(ID_TOOLBAR_SAVE,VFX_WSTR_RES(STR_GLOBAL_SAVE));
				m_functionBarSubjectFrame->setItemSpecial(ID_TOOLBAR_SAVE);
			}
			else
            #endif    
            {
			m_functionBarSubjectFrame->addItem(ID_TOOLBAR_SEND,VFX_WSTR_RES(STR_GLOBAL_SEND));
			m_functionBarSubjectFrame->setItemSpecial(ID_TOOLBAR_SEND);
			onEntertoggleString();

	#ifdef __MMI_EMAIL__
				if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
				{
					if(VappEmailComp::isSendButtonAvailable())	
					{
						//just skip
					}
					else
					{
						if ((vappUcGetValidSimInfo() == vappUcGetInvalidSimInfo())&& !vappUcFlightModecheck())
						{
							m_functionBarToFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
						}
					}
				}
				else
	#endif
				//if (vappUcGetValidSimInfo() == vappUcGetInvalidSimInfo())kuldeep_gplus
				if (!isSendButtonAvailable())
				{
					m_functionBarSubjectFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
				}
			}
			textEditorSubject->setFunctionBar(m_functionBarSubjectFrame);
			m_functionBarSubjectFrame->m_signalButtonTap.connect(this, &VappComposerMainPage::onToolBarClick);

           if(VappUcGetPositionToInsert(ID_SUBJECT) == 0)
           {
              composer_form->addItem(frame_part4, ID_SUBJECT);
           }
           else
           {
              composer_form->insertItem(frame_part4, VappUcGetPositionToInsert(ID_SUBJECT), ID_SUBJECT);
           }
		   m_itemsAlraedyDraw |=  ID_SUBJECT;
        }
    }
    else if(textEditorSubject)
    {
       frame_part4->setIsHidden(VFX_TRUE);
    }
}

void VappComposerMainPage::insertSlideBarItem(void)
{
    if(slideBar!= NULL)
    {
        removeObjectFromPage(ID_INLINE_SLIDE_BAR);
        slideBar = NULL;
    }
 //   else
    {
        VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
        VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
        if (app->m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER
            && app->m_service_cntxt->msg->msg_body.slide_no > 1)
        {
            U16 text_buffer[50] = {0,};
            //U16 temp_UCS2_buffer[50] = {0,};
            VfxWString itemText;
            //VcpFormItemCustomFrame *frame_part5;

            VFX_OBJ_CREATE(frame_part5, VcpFormItemCustomFrame, composer_form);
            VFX_OBJ_CREATE_EX(slideBar, VappUCSlideBarItem, frame_part5, (this->getSize()));

            app->ucGetMmsSlideBarText(text_buffer);
            slideBar->setText(itemText.loadFromMem((VfxWChar*)text_buffer));
			/*for screen rotation*/ 
			slideBar->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
										VFX_FRAME_ALIGNER_MODE_NONE, 
										VFX_FRAME_ALIGNER_MODE_SIDE,
										VFX_FRAME_ALIGNER_MODE_NONE);
            frame_part5->attachCustomFrame(slideBar);
            if(VappUcGetPositionToInsert(ID_INLINE_SLIDE_BAR) == 0)
            {
              composer_form->addItem(frame_part5, ID_INLINE_SLIDE_BAR);
            }
            else
            {
              composer_form->insertItem(frame_part5, VappUcGetPositionToInsert(ID_INLINE_SLIDE_BAR), ID_INLINE_SLIDE_BAR);
            }
			m_itemsAlraedyDraw |=  ID_INLINE_SLIDE_BAR;
            slideBar->getOptionButton()->m_signalClicked.connect(this, &VappComposerMainPage::onSlideBarOptionClick);
            slideBar->getLeftArrowButton()->m_signalClicked.connect(this, &VappComposerMainPage::onSlideBarLeftArrowClick);
            slideBar->getRightArrowButton()->m_signalClicked.connect(this, &VappComposerMainPage::onSlideBarRightArrowClick);
        }
    }
}
void VappComposerMainPage::insertMediaItem(void)
{
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);

    if(composer_media1!= NULL)
    {
        removeObjectFromPage(ID_INLINE_MEDIA_1);
        composer_media1 = NULL;
    }
    if(composer_media2!= NULL)
    {
        removeObjectFromPage(ID_INLINE_MEDIA_2);
        composer_media2 = NULL;
    }

    if(app->m_service_cntxt->msg == NULL)
    {
        return;
    }

    if(app->m_service_cntxt->msg->msg_body.curr_slide->img.object)
    {
       // VcpFormItemCustomFrame *frame_part6;
        U8 virtual_file_name[(SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH];
		FS_HANDLE file_handle = 0;
        app->ucGenerateFilePath(app->m_service_cntxt->msg->msg_body.curr_slide->img.object, virtual_file_name);
		file_handle = app->m_service_cntxt->main->file_handle;
		app->m_service_cntxt->main->file_handle = 0;
        VFX_OBJ_CREATE(frame_part6, VcpFormItemCustomFrame, composer_form);
        VFX_OBJ_CREATE_EX(composer_media1, VappUCMediaItem, frame_part6, (app->m_service_cntxt->msg->msg_body.curr_slide->img.object, SRV_UC_OBJECT_TYPE_IMAGE, virtual_file_name, this->getSize()));
		composer_media1->m_fileHandle = file_handle;
		frame_part6->attachCustomFrame(composer_media1);
        if(VappUcGetPositionToInsert(ID_INLINE_MEDIA_1) == 0)
	    {
		    composer_form->addItem(frame_part6, ID_INLINE_MEDIA_1);
	    }
	    else
	    {
		    composer_form->insertItem(frame_part6, VappUcGetPositionToInsert(ID_INLINE_MEDIA_1), ID_INLINE_MEDIA_1);
	    }

        if(VFX_FALSE == m_isBlockDeactivateEditor)
        {
		    deactivateEditor();
        }
		composer_form->scrollItemToView(ID_INLINE_MEDIA_1, VCPFORM_SCROLL_CENTER);
		m_itemsAlraedyDraw |=  ID_INLINE_MEDIA_1;
       composer_media1->m_MediaBase->m_signalClicked.connect(composer_media1, &VappUCMediaItem::onMediaBarClick);
	   /*for rotation*/
	   composer_media1->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
							VFX_FRAME_ALIGNER_MODE_NONE, 
							VFX_FRAME_ALIGNER_MODE_SIDE,
							VFX_FRAME_ALIGNER_MODE_NONE);
    }
    if((app->m_service_cntxt->msg->msg_body.curr_slide->aud.object || app->m_service_cntxt->msg->msg_body.curr_slide->vid.object) ||
         (app->operation_type == UC_OPERATION_SEND_VCARD_AS_SMS) ||
         (app->operation_type == UC_OPERATION_SEND_VCALENDAR_AS_SMS))
    {
        mma_mms_object_struct *object = NULL;
        srv_uc_object_type type = SRV_UC_OBJECT_TYPE_AUDIO;
        if(app->m_service_cntxt->msg->msg_body.curr_slide->aud.object)
        {
           object = app->m_service_cntxt->msg->msg_body.curr_slide->aud.object;
           type = SRV_UC_OBJECT_TYPE_AUDIO;
        }
    #ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
        else if(app->m_service_cntxt->msg->msg_body.curr_slide->vid.object)
        {
           object = app->m_service_cntxt->msg->msg_body.curr_slide->vid.object;
           type = SRV_UC_OBJECT_TYPE_VIDEO;     
        }
    #endif
        else
        #if defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__)
            if((app->operation_type == UC_OPERATION_SEND_VCARD_AS_SMS) ||
            (app->operation_type == UC_OPERATION_SEND_VCALENDAR_AS_SMS))
            {
                if(app->m_service_cntxt->msg->msg_body.attachment)
                {
                    mma_mms_attachment_info_struct* attach_obj;
                    attach_obj = srv_uc_get_attachment_by_index(app->main->instance, 0);
                    object =  attach_obj->object;
                    type = SRV_UC_OBJECT_TYPE_ATTACHMENT;
                }
                else
                {
                    return;
                }
            }
            else
        #endif    
        {
           return;
        }
       // VcpFormItemCustomFrame *frame_part7;

        VFX_OBJ_CREATE(frame_part7, VcpFormItemCustomFrame, composer_form);
        VFX_OBJ_CREATE_EX(composer_media2, VappUCMediaItem, frame_part7, (object, type, NULL, this->getSize()));
        frame_part7->attachCustomFrame(composer_media2);
	    if(VappUcGetPositionToInsert(ID_INLINE_MEDIA_2) == 0)
	    {
		    composer_form->addItem(frame_part7, ID_INLINE_MEDIA_2);
	    }
	    else
	    {
		    composer_form->insertItem(frame_part7, VappUcGetPositionToInsert(ID_INLINE_MEDIA_2), ID_INLINE_MEDIA_2);
	    }

        if(VFX_FALSE == m_isBlockDeactivateEditor)
		{
		    deactivateEditor();
        }

        // Do not scroll when there are two items when switching silde to prevend slide bar been moved out of user's view
       if( VFX_FALSE == m_isBlockDeactivateEditor || composer_media1 == NULL)
              composer_form->scrollItemToView(ID_INLINE_MEDIA_2, VCPFORM_SCROLL_CENTER);

       composer_media2->m_MediaBase->m_signalClicked.connect(composer_media2, &VappUCMediaItem::onMediaBarClick);
	   	   /*for rotation*/
	   composer_media2->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
							VFX_FRAME_ALIGNER_MODE_NONE, 
							VFX_FRAME_ALIGNER_MODE_SIDE,
							VFX_FRAME_ALIGNER_MODE_NONE);
	   m_itemsAlraedyDraw |=  ID_INLINE_MEDIA_2;
    }
}

void VappComposerMainPage::onSubjectActivated(VcpTextEditor *editor, VfxBool activated)
{
    if(activated)
	{
		highlightedEditor = editor;
	}
}
void VappComposerMainPage::onTextBodyEditorActivated(VcpTextEditor *editor, VfxBool activated)
{
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);

    if(activated)
	{
		highlightedEditor = textEditorBody;
	}
	else if(app->m_service_cntxt->send_info->action == SRV_UC_ACTION_IDLE)
	{
		app->m_service_cntxt->main->current_text_file_save_result = app->ucHandleTextInCurrentSlide(); /* we can force call too. But put here to see switchSlide call as generic. *///vikas
		if(app->m_service_cntxt->main->current_text_file_save_result != FS_NO_ERROR)
		{
			app->m_service_cntxt->msg->msg_body.curr_slide->txt.utf8_msg_len = 0 ;
		}
	}
    return;
}

void VappComposerMainPage::insertTextStringOneGo(VfxWChar *string, VfxBool isReplace)
{
	VfxU16 length =  mmi_ucs2strlen((S8*) string);
	VfxU32 ret = 1;
	if (isReplace)
	{
		this->textEditorBody->deleteAll();
	}

    if (string != NULL)
    {
		VfxS32 cursorCurrentPos = 0;
		VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
		VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
		VappUcTextInfoStruct new_text_info = {0,};
		VfxBool result = VFX_TRUE;

	    app->ucGetTextInfoForBuffer(&new_text_info, (U8*)(string));
        new_text_info.char_count += app->m_service_cntxt->msg->msg_body.curr_slide->txt.char_count;
        new_text_info.utf8_msg_len += app->m_service_cntxt->msg->msg_body.curr_slide->txt.utf8_msg_len;
        new_text_info.extension_char_count += app->m_service_cntxt->msg->msg_body.curr_slide->txt.extension_char_count;
        new_text_info.UCS2_count += app->m_service_cntxt->msg->msg_body.curr_slide->txt.UCS2_count;

	    result = app->ucCharInputHandler(&new_text_info);
		if(result)
	    {
		    ret = this->textEditorBody->insertText(string);
	    }
		else
		{
		    for(VfxU16 index = 0; index < length && ret ; index++)
			{
				ret = this->textEditorBody->insertText(*(string + index));
			}		
		}
		cursorCurrentPos = textEditorBody->getCursorIndex();
		cursorIndexToHeighlight = cursorCurrentPos;
    }
}

void VappComposerMainPage::insertTextString(VfxWChar *string, VfxBool isReplace)
{
	VfxU16 length =  mmi_ucs2strlen((S8*) string);
	VfxU32 ret = 1;
	if (isReplace)
	{
		this->textEditorBody->deleteAll();
	}

    if (string != NULL)
    {
		VfxS32 cursorCurrentPos = 0;
	    for(VfxU16 index = 0; index < length && ret ; index++)
	    {
		    ret = this->textEditorBody->insertText(*(string + index));
	    }
		cursorCurrentPos = textEditorBody->getCursorIndex();
		cursorIndexToHeighlight = cursorCurrentPos;
    }
}

void VappComposerMainPage::csOnBodyTextHeightChange(VfxFrame *f, const VfxRect &r)
{
    if(r.size != f->getSize())
    {
        frame_part8->setHeight(f->getSize().height + VCPFRM_ITEM_HORZ_GAP/2);
    }
}


void VappComposerMainPage::insertTextBodyEditor(void)
{
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
	VfxS32 text_limit = 2048;

#ifdef __MMI_EMAIL__
	if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
	{
		text_limit = UC_EMAIL_MAX_TEXT_CHAR_COUNT;
	}
	else
#endif
	{
		text_limit = UC_MMS_MAX_TEXT_CHAR_COUNT;			
	}
    if(textEditorBody!= NULL)
    {
    //    removeObjectFromPage(ID_BODY_TEXT);
    //    textEditorBody = NULL;
		#ifdef __MMI_EMAIL__
		if (!(app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL && app->main->select_media_opt == UC_MEDIA_OPT_INSERT))
		#endif
        textEditorBody->setText((VfxWChar*)app->m_service_cntxt->main->text_buffer, app->main->max_text_limit ? app->main->max_text_limit : text_limit, VFX_TRUE);

    #ifdef __MMI_EMAIL__
		if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
		{
			if(VappEmailComp::isSendButtonAvailable())	
			{
				//just skip
			}
			else
			{
				if ((vappUcGetValidSimInfo() == vappUcGetInvalidSimInfo() )&& !vappUcFlightModecheck())
				{
					m_functionBarToFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
				}
			}
		}
		else
    #endif
		    //if (vappUcGetValidSimInfo() == vappUcGetInvalidSimInfo())kuldeep_gplus
			if (!isSendButtonAvailable())
		    {
			    m_functionBarFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
		    }
            else
            {
                m_functionBarFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_FALSE);
            }
    }
    else
    {
       // VcpFormItemCustomFrame *frame_part8;

        if(!((app->operation_type == UC_OPERATION_SEND_VCARD_AS_SMS) ||
                 (app->operation_type == UC_OPERATION_SEND_VCALENDAR_AS_SMS)))
        {
			vrt_size_struct mainScreenSize;
			vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

            VFX_OBJ_CREATE(frame_part8, VcpFormItemCustomFrame, composer_form);
            // disable cache mode.          
            frame_part8->setCacheMode(VFX_CACHE_MODE_PREVENT);

            VFX_OBJ_CREATE(textEditorBody, VcpTextEditor , frame_part8);

            textEditorBody->setSize(composer_form->getSize().width - (2 * VAPP_UC_LEFT_MARGIN), mainScreenSize.height / 2);
            textEditorBody->setPos(VAPP_UC_LEFT_MARGIN, 0);
			textEditorBody->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
						VFX_FRAME_ALIGNER_MODE_NONE, 
						VFX_FRAME_ALIGNER_MODE_SIDE,
						VFX_FRAME_ALIGNER_MODE_NONE);
            textEditorBody->setText((VfxWChar*)app->m_service_cntxt->main->text_buffer, app->main->max_text_limit ? app->main->max_text_limit : text_limit, VFX_TRUE);
            textEditorBody->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
			textEditorBody->setHint(VFX_WSTR_RES(STR_ID_VAPP_UC_TXT_EDITOR_HINT_ID));
			textEditorBody->setAutoResized(VFX_TRUE);

            // set theme color
            textEditorBody->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
            textEditorBody->setColor(VCP_TEXT_HINT_TEXT_COLOR, VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB));
            textEditorBody->setColor(VCP_TEXT_UNDERLINE_COLOR, VFX_COLOR_RES(CLR_COSMOS_TEXT_LINK));
			/*set the Max Line no */
			textEditorBody->setMaxLineNum(5000);

			VFX_OBJ_CREATE(m_functionBarFrame, VcpFunctionBar, this);
			#if defined(__MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__)		
			m_functionBarFrame->addItem(ID_COMMAND_INSERT_EMOTICON, IMG_ID_VAPP_UC_EMOTIC_1_ID);//VFX_WSTR_RES(STR_ID_VAPP_UC_EMOTICON));
			#endif
            #ifdef __MMI_EMAIL__
            if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
            {
				m_functionBarFrame->addItem(ID_TOOLBAR_INSERT, VFX_WSTR_RES(STR_ID_VAPP_UC_INSERT_ID));
				m_functionBarFrame->addItem(ID_TOOLBAR_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE));
			}
			else
			#endif
			{
            #if defined(__MMI_MESSAGES_TEMPLATE__)  
				m_functionBarFrame->addItem(ID_COMMAND_INSERT_TEMPLATE, VFX_WSTR_RES(STR_ID_VAPP_UC_TEXT_TEMPLATE_ID));
            #endif
				if(app->m_service_cntxt->msg_type->MMS_edit_mode != SRV_UC_MMS_EDIT_MODE_LEMEI_MMS)
				{
					m_functionBarFrame->addItem(ID_TOOLBAR_INSERT, VFX_WSTR_RES(STR_ID_VAPP_UC_INSERT_ID));
				}
			}
            #if defined(__MMI_MESSAGES_TEMPLATE__) || defined(__MMI_MMS_TEMPLATE_SUPPORT__)
			if((app->operation_type == UC_OPERATION_WRITE_NEW_SMS_TEMPLATE) ||
				(app->operation_type == UC_OPERATION_EDIT_SMS_TEMPLATE) ||
				(app->operation_type == UC_OPERATION_WRITE_NEW_MMS_TEMPLATE) ||
				(app->operation_type == UC_OPERATION_EDIT_MMS_TEMPLATE))
			{
				m_functionBarFrame->addItem(ID_TOOLBAR_SAVE,VFX_WSTR_RES(STR_GLOBAL_SAVE));
				m_functionBarFrame->setItemSpecial(ID_TOOLBAR_SAVE);
			}
			else
            #endif    
            {
			    m_functionBarFrame->addItem(ID_TOOLBAR_SEND,VFX_WSTR_RES(STR_GLOBAL_SEND));
			    m_functionBarFrame->setItemSpecial(ID_TOOLBAR_SEND);
				onEntertoggleString();
	#ifdef __MMI_EMAIL__
			if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
			{
				if(VappEmailComp::isSendButtonAvailable())	
				{
					//just skip
				}
				else
				{
					if ((vappUcGetValidSimInfo() == vappUcGetInvalidSimInfo() )&& !vappUcFlightModecheck())
					{
						m_functionBarToFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
					}
				}
			}
			else
	#endif
			    //if (vappUcGetValidSimInfo() == vappUcGetInvalidSimInfo())kuldeep_gplus
				if (!isSendButtonAvailable())
			    {
				    m_functionBarFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
			    }
            }
			textEditorBody->setFunctionBar(m_functionBarFrame);
			m_functionBarFrame->m_signalButtonTap.connect(this, &VappComposerMainPage::onToolBarClick);

	        textEditorBody->m_signalTextChanged.connect(this, &VappComposerMainPage::onBodyTextChanged); /* connect the signal of any text changed */
            textEditorBody->m_signalBeforeChange.connect(this, &VappComposerMainPage::onCharInput); /* connect the signal of any text changed */
			textEditorBody->m_signalActivated.connect(this, &VappComposerMainPage::onTextBodyEditorActivated);
			textEditorBody->m_signalBoundsChanged.connect(this,&VappComposerMainPage::csOnBodyTextHeightChange);
			#if defined(__MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__)		
			textEditorBody->setIconMode(VFX_TRUE, textIconTable, UC_EMOTICON_ICON_COUNT);
			#endif
            textEditorBody->disableBackground(VFX_TRUE);
            textEditorBody->setUnderline(VFX_TRUE);
  		    textEditorBody->setMinLineHeight(VAPP_UC_MSG_VIEW_CONT_LINE_HEIGHT);
            frame_part8->attachCustomFrame(textEditorBody);
			textEditorBody->forceUpdate();
            frame_part8->setHeight((textEditorBody->getSize().height) + VCPFRM_ITEM_HORZ_GAP);

	        if(VappUcGetPositionToInsert(ID_BODY_TEXT) == 0)
	        {
		        composer_form->addItem(frame_part8, ID_BODY_TEXT);
	        }
	        else
	        {
		        composer_form->insertItem(frame_part8, VappUcGetPositionToInsert(ID_BODY_TEXT), ID_BODY_TEXT);
	        }
			m_itemsAlraedyDraw |=  ID_BODY_TEXT;
        }
		onFirstEnterSetDefaultActive();
    }
}


void VappComposerMainPage::insertAttachment(void)
{
    if(attachmentList!= NULL)
    {
        removeObjectFromPage(ID_MULTI_ATTACHMENT);
        attachmentList = NULL;
    }
    if(attachmentList1!= NULL)
    {
        removeObjectFromPage(ID_MULTI_ATTACHMENT);
        attachmentList1 = NULL;
    }
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
	VfxBool gap_needed = VFX_FALSE;
	VfxS32 attachmentCount = app->m_service_cntxt->msg->msg_body.total_attach_no;

	if(attachmentCount > 1)
	{
        // VcpFormItemCustomFrame *frame_part9;
        U16 text_buffer[50] = {0,};
        VfxWString itemText;
        app->ucGetAttachmentString(text_buffer);

        VFX_OBJ_CREATE(frame_part9, VcpFormItemCustomFrame, composer_form);
        VFX_OBJ_CREATE_EX(attachmentList, VappUCAttachmentButtonItem, frame_part9, (this->getSize(), gap_needed));
        attachmentList->btn->m_signalClicked.connect(this, &VappComposerMainPage::onattachmentButtonClicked);
        attachmentList->setText(itemText.loadFromMem((VfxWChar*)text_buffer));//VFX_WSTR("2 Attachment (100 Kb)"));
       // attachmentList->setHint(VFX_WSTR("List"));
		/*For Rotation*/
		attachmentList->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
							VFX_FRAME_ALIGNER_MODE_NONE, 
							VFX_FRAME_ALIGNER_MODE_SIDE,
							VFX_FRAME_ALIGNER_MODE_NONE);
        frame_part9->attachCustomFrame(attachmentList);
        if(VappUcGetPositionToInsert(ID_MULTI_ATTACHMENT) == 0)
        {
           composer_form->addItem(frame_part9, ID_MULTI_ATTACHMENT);
        }
        else
        {
           composer_form->insertItem(frame_part9, VappUcGetPositionToInsert(ID_MULTI_ATTACHMENT), ID_MULTI_ATTACHMENT);
        }
        if(VFX_FALSE == m_isBlockDeactivateEditor)
        {
           deactivateEditor();
        }
		composer_form->scrollItemToView(ID_MULTI_ATTACHMENT, VCPFORM_SCROLL_CENTER);
		m_itemsAlraedyDraw |=  ID_MULTI_ATTACHMENT;
	}
	else if (attachmentCount == 1 && !((app->operation_type == UC_OPERATION_SEND_VCARD_AS_SMS) ||
             (app->operation_type == UC_OPERATION_SEND_VCALENDAR_AS_SMS)))
	{
        // create single attachment item
        // VcpFormItemCustomFrame *frame_part10;
		U16 text_buffer[ ((SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH) ] = {0,};
        VfxWString itemText;
        app->ucGetAttachmentString(text_buffer);

        VFX_OBJ_CREATE(frame_part10, VcpFormItemCustomFrame, composer_form);
        VFX_OBJ_CREATE_EX(attachmentList1, VappUCSingleAttachmentButtonItem, frame_part10, (this->getSize(), gap_needed));
        attachmentList1->setText(itemText.loadFromMem((VfxWChar*)text_buffer));
		attachmentList1->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
							VFX_FRAME_ALIGNER_MODE_NONE, 
							VFX_FRAME_ALIGNER_MODE_SIDE,
							VFX_FRAME_ALIGNER_MODE_NONE);

        frame_part10->attachCustomFrame(attachmentList1);
        if(VappUcGetPositionToInsert(ID_MULTI_ATTACHMENT) == 0)
        {
           composer_form->addItem(frame_part10, ID_MULTI_ATTACHMENT);
        }
        else
        {
           composer_form->insertItem(frame_part10, VappUcGetPositionToInsert(ID_MULTI_ATTACHMENT), ID_MULTI_ATTACHMENT);
        }
        if(VFX_FALSE == m_isBlockDeactivateEditor)
        {
           deactivateEditor();
        }
		composer_form->scrollItemToView(ID_MULTI_ATTACHMENT, VCPFORM_SCROLL_CENTER);
		m_itemsAlraedyDraw |=  ID_MULTI_ATTACHMENT;
	}
	else
	{
		// No Need Any Draw. No attachment.
	}
}
void VappComposerMainPage::updateBottomMsgHint(void)
{
    U16 text_buffer[50] = {0,};
    VfxWString itemText;
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);

    #ifdef __MMI_EMAIL__
    if (app->m_service_cntxt->msg_type->MMS_edit_mode != SRV_UC_MMS_EDIT_MODE_EMAIL)
    #endif
    {
		if(m_BackUpitemsAlraedyDraw != 0)
		{
			m_BackUpitemsAlraedyDraw |= ID_INLINE_MSG_HINT ;
		}
        if(composerHintTxt!= NULL)
        {
       //     removeObjectFromPage(ID_INLINE_MSG_HINT);
        //    composerHintTxt = NULL;
           if (app->m_service_cntxt->msg_type->curr_msg_type != SRV_UC_MSG_TYPE_MMS_PREFER)
           {
               frame_part11->setIsHidden(VFX_TRUE);
				m_itemsAlraedyDraw &= ~ID_INLINE_MSG_HINT;
           }
           else
           {
                app->ucGetMmsHintBarText(text_buffer);
                composerHintTxt->setString(itemText.loadFromMem((VfxWChar*)text_buffer));
                frame_part11->setIsHidden(VFX_FALSE);
				m_itemsAlraedyDraw |= ID_INLINE_MSG_HINT;
           }
        }
        else
        {
            if (app->m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
            {
               // VcpFormItemCustomFrame *frame_part11;

                VFX_OBJ_CREATE(frame_part11, VcpFormItemCustomFrame, composer_form);
                VFX_OBJ_CREATE(composerHintTxt, VfxTextFrame, frame_part11);
                app->ucGetMmsHintBarText(text_buffer);
                composerHintTxt->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VCPFRM_FONT_SIZE_1)));
				composerHintTxt->setAutoResized(VFX_TRUE);
                //composerHintTxt->setSize(composer_form->getSize().width - (VAPP_UC_LEFT_MARGIN * 2), FONT_MEDIUM + VCPFRM_ITEM_HORZ_GAP);
                composerHintTxt->setString(itemText.loadFromMem((VfxWChar*)text_buffer));
				composerHintTxt->setAnchor(1,0);
                composerHintTxt->setPos(composer_form->getSize().width - VAPP_UC_LEFT_MARGIN, 0);
                composerHintTxt->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB));
                composerHintTxt->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);
			    composerHintTxt->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE,
                                    VFX_FRAME_ALIGNER_MODE_NONE,
                                    VFX_FRAME_ALIGNER_MODE_SIDE,
                                    VFX_FRAME_ALIGNER_MODE_NONE);
                frame_part11->attachCustomFrame(composerHintTxt);
                frame_part11->setHeight(composerHintTxt->getSize().height);
	            composer_form->addItem(frame_part11, ID_INLINE_MSG_HINT);
                composerHintTxt->setAutoResized(VFX_FALSE);
                composerHintTxt->setSize(composer_form->getSize().width - (VAPP_UC_LEFT_MARGIN * 2), composerHintTxt->getSize().height);
				if (m_BackUpitemsAlraedyDraw)
				{
					frame_part11->setIsHidden(VFX_TRUE);
				}
				m_itemsAlraedyDraw |=  ID_INLINE_MSG_HINT;
			}
        }
    }
}

void VappComposerMainPage::onBack(void)
{
	VcpContactSelector* recipientHead= m_contactSelectorTo;
	VcpTextEditor* r_editor = NULL;
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);

	srv_uc_address_group_type_enum type = (srv_uc_address_group_type_enum)app->getContactInsertType();
	switch(type)
	{
	case SRV_UC_ADDRESS_GROUP_TYPE_TO:
		recipientHead = m_contactSelectorTo;
		break;
        
#ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__
	case SRV_UC_ADDRESS_GROUP_TYPE_CC:
		recipientHead = m_contactSelectorCc;
		break;

	case SRV_UC_ADDRESS_GROUP_TYPE_BCC:
		recipientHead = m_contactSelectorBcc;
		break;
#endif        
	}
	if(recipientHead)
	{
		r_editor = recipientHead->getInputbox();
		r_editor->deleteAll();
		r_editor->setEnterKeyEnabled(VFX_FALSE);
	}

    if( NULL != composer_form)
        composer_form->setIsAnimEnabled(VFX_FALSE);
        
	app->main->skip_save_on_deinit = VFX_FALSE;
	VfxPage::onBack();
}

void VappComposerMainPage::onattachmentButtonClicked(VfxObject* obj, VfxId id)
{
	VFX_OBJ_CREATE(attachmentPage, VAppUcAttachmentlistPage, getMainScr());
	getMainScr()->pushPage(0, attachmentPage);
}


/*****************************************************************************
 * Class VtstNaviAppScr implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappUCMainScr", VappUCMainScr, VfxMainScr);

VappUCMainScr::VappUCMainScr():
    m_isScreenEntered (VFX_FALSE)
{
}

void VappUCMainScr::on1stReady()
{
    VfxMainScr::on1stReady();
    VcuiUcMainCui *mainApp = (VcuiUcMainCui *)getParent();
    this->m_app_data = mainApp->m_app_data;
    
    VFX_OBJ_CREATE(composer_page, VappComposerMainPage, this);
	pushPage(VAPP_UC_PAGE_ID_COMPOSER_PAGE, composer_page);

	if (mainApp->m_app_data->main->launch_mode == UC_LAUNCH_MODE_INSERT)
	{
     #ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__
        if(  mainApp->m_isInRestore == VFX_FALSE )
     #endif       
        {
		mainApp->m_app_data->ucSetInsertMenu();
		VappTestInsertMenuListPage *insertMenuPage;
		    VFX_OBJ_CREATE(insertMenuPage, VappTestInsertMenuListPage, this);
		    pushPage(VAPP_UC_PAGE_ID_INSERT_MENU_ITEM_PAGE, insertMenuPage);
        }
	}	
}

//W1203_UI_PERFORMANCE_BEGIN
void VappUCMainScr::on2ndReady()
{
    VfxMainScr::on2ndReady();

    m_isScreenEntered = VFX_TRUE;
    
    VFX_ASSERT(composer_page != NULL);

    if(this->m_app_data->m_useSecondStage == VFX_TRUE)
        composer_page->updateView(VFX_TRUE);
    else
        composer_page->setAutoActivated();
}
//W1203_UI_PERFORMANCE_END

void VappUCMainScr::onQueryRotateEx(VfxScreenRotateParam &param)
{
    // do nothing
}

VfxBool VappUCMainScr::vappUcCloseCui(void)
{
    switch(m_app_data->main->cui_type)
    {
        case UC_CUI_MUSIC_PLAYER:
            vcui_music_player_close(m_app_data->main->cui_gid);
            break;
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
    #ifdef __MMI_COSMOS_UC_VIDEO_PREVIEW_SUPPORT__
        case UC_CUI_VIDEO_PLAYER:
            vcui_gallery_close(m_app_data->main->cui_gid);
            break;
    #endif
#endif    
        case UC_CUI_IMAGE_VIEWER:
            vcui_gallery_close(m_app_data->main->cui_gid);
            break;
#ifdef __MMI_SOUNDREC_CUI__
        case UC_CUI_SOUND_RECORDER:
            vcui_soundrec_close(m_app_data->main->cui_gid);
            break;
#endif
#if (!defined(__LOW_COST_SUPPORT_COMMON__))
        case UC_CUI_CAMERA:
                vcui_standard_camera_close(m_app_data->main->cui_gid);
            break;
#endif
#if (!defined(__LOW_COST_SUPPORT_COMMON__))
        case UC_CUI_CAMCORDER:
                vcui_standard_recorder_close(m_app_data->main->cui_gid);
            //vcui_camcorder_close(m_app_data->main->cui_gid);
            break;
#endif
        case UC_CUI_GALLERY_IMG_PCKR:
    #ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__             
        case UC_CUI_GALLERY_VIDEO_PCKR:
    #endif        
            vcui_gallery_close(m_app_data->main->cui_gid);
            break;
    #if defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__) && defined(BROWSER_SUPPORT)        
        case UC_CUI_SELECT_BOOKMARK:
            vcui_bkm_sel_bkm_close(m_app_data->main->cui_gid);
            break;
    #endif        
        case UC_CUI_FILE_SELECTOR:
            vcui_file_selector_close(m_app_data->main->cui_gid);
            break;
        case UC_CUI_PREVIEW_MMS:
            {
#ifdef __MMI_MMS_2__
                cui_vapp_mms_preview_mms_close(m_app_data->main->cui_gid);
#endif
                if(this->isValid())
                {
	                m_app_data->m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
	                if (m_app_data->m_service_cntxt->send_info->new_msg_id)
	                {
		                m_app_data->ucClearMsgBearer(SRV_UC_MSG_TYPE_MMS_PREFER);
	                }
                }
            }
            break;
    #ifdef __MMI_VCARD__		
        case UC_CUI_PREVIEW_VCARD:
            vcui_vcard_close(m_app_data->main->cui_gid);
            break;
    #endif /* __MMI_VCARD__  */
	
    #ifdef __MMI_VCALENDAR__		
        case UC_CUI_PREVIEW_VCALENDAR:
            break;
    #endif /* __MMI_VCALENDAR__ */        
        case UC_CUI_PHB_LIST:
            vcui_phb_list_close(m_app_data->main->cui_gid);
            break;

    #ifdef __MMI_VCALENDAR__ 
        case UC_CUI_CAL_LIST:
            vcui_cal_list_close(m_app_data->main->cui_gid);
            break;
    #endif /* __MMI_VCALENDAR__ */  
        default :
            break;
    }
    if(this->isValid())
    {
        m_app_data->main->cui_gid = GRP_ID_INVALID;
        m_app_data->main->cui_type = UC_CUI_NONE;
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

void VappUCMainScr::refreshPageOnSdPlugOut(VfxBool close_cui, VfxBool attach_removed)
{
	VappUcAppData* app = (VappUcAppData*)(this->m_app_data);
    VfxBool sanity_check = VFX_TRUE;

	if(!vappUcCheckAppSanity((void *)app))
	{
		return;
	}
    if (close_cui && m_app_data->main->cui_gid != GRP_ID_INVALID)
    {
        sanity_check = vappUcCloseCui();
        close_cui = VFX_FALSE;
    }

    if(sanity_check)
    {
        composer_page->drawWithData();
        if(attach_removed && composer_page->attachmentPage)
        {
            if(m_app_data->m_service_cntxt->msg->msg_body.attachment)
            {
                /* Refresh */
                m_app_data->ucGetAttachmentItemList(composer_page->attachmentPage->m_listMenuContentProviderForAttachment->attachmentList, 
                                                        composer_page->attachmentPage->m_listMenuContentProviderForAttachment->m_attachmentSizeList, 
                                                        &composer_page->attachmentPage->m_listMenuContentProviderForAttachment->attachmentCount);
		        composer_page->attachmentPage->attahmentList->setContentProvider(composer_page->attachmentPage->m_listMenuContentProviderForAttachment);
                composer_page->attachmentPage->attahmentList->updateAllItems();
            }
            else
            {
                /* Pop page */
                popPage();
            }
        }
    }
}

void VappUCMainScr::displayPopup( WCHAR* title, 
    	mmi_nmgr_balloon_type_enum event_type)
{
    mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, event_type, (WCHAR*)title);
}

void VappUCMainScr::terminateApp(void)
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_TERMINATE_APP);
	VappUcAppData* app = (VappUcAppData*)(this->m_app_data);

	app->main->skip_save_on_deinit = VFX_TRUE;
    VfxAppLauncher::terminate(getApp()->getGroupId());
}

void VappUCMainScr::ucPlayAudioFile(const WCHAR* filename, const WCHAR* filepath)
{
	VappUcAppData* app = (VappUcAppData*)(this->m_app_data);
#ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__
        if( vapp_uc_check_serialize_support_cui(UC_CUI_MUSIC_PLAYER) )
        {
            VappOpenVideoPlayerParam param;
            param.instance = app->main->instance;
            param.parent_gid = getApp()->getGroupId(); 
            param.filepath = filepath;
            param.filename = filename; 
        
            m_app_data->vappUcSetSerialize(param.instance,param.parent_gid);
            getApp()->serialize((void*)UC_CUI_MUSIC_PLAYER, VFX_TRUE, 
                                vapp_uc_open_audio_player_cui, &param, sizeof(param), vapp_uc_proxy_proc);
        }
        else
#endif /* __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__ */
        {
            app->main->cui_gid = vcui_music_player_create(getApp()->getGroupId(), filepath);

            if (app->main->cui_gid > 0)
            {
             vfxSetCuiCallerScr(app->main->cui_gid, this);
             vcui_music_player_run(app->main->cui_gid);
             vcui_music_player_set_title(app->main->cui_gid, filename);
             app->main->cui_type = UC_CUI_MUSIC_PLAYER;
            }
        }
}

#ifdef __MMI_VCALENDAR__
void VappUCMainScr::ucPreviewVcalendar(const WCHAR* filename, const WCHAR* filepath)
{
	FS_HANDLE fileHandle = 0;
	S32 fileSize = 0;
	U16 error_str_id = STR_ID_VAPP_UC_FILE_EMPTY_ID;
	fileSize = applib_get_file_size((kal_wchar*)filepath);

	if (fileSize > 0)
	{
		fileHandle = FS_Open(filepath, FS_READ_ONLY);
		if (fileHandle > 0)
		{
			char *buff = NULL;
			UINT bytes_read = 0;

			VFX_ALLOC_MEM(buff, (fileSize + 2), this);			
			FS_Read(fileHandle, buff, fileSize, &bytes_read);
			vapp_cal_view_detail_from_message_launch(buff, fileSize);
			VFX_FREE_MEM(buff);

			FS_Close(fileHandle);
			return;
		}
	}
	fileHandle = FS_Open(filepath, FS_READ_ONLY);
	if (fileHandle <= 0)
	{
		error_str_id = srv_fmgr_fs_error_get_string(fileHandle);
	}
	mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
		(WCHAR*)VFX_WSTR_RES(error_str_id).getBuf());
}
#endif /* __MMI_VCALENDAR__ */

#if defined(__MMI_VCARD__)
void VappUCMainScr::ucPreviewVcard(const WCHAR* filename, const WCHAR* filepath)
{
	VappUcAppData* app = (VappUcAppData*)(this->m_app_data);

	app->main->cui_gid = vcui_vcard_create(getApp()->getGroupId());

	 if (app->main->cui_gid > 0)
	 {
		vfxSetCuiCallerScr(app->main->cui_gid, this);
		vcui_vcard_set_path(app->main->cui_gid, const_cast<WCHAR*>(filepath));
		vcui_vcard_run(app->main->cui_gid);
        app->main->cui_type = UC_CUI_PREVIEW_VCARD;
	 }

}
#endif

#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
#ifdef __MMI_COSMOS_UC_VIDEO_PREVIEW_SUPPORT__
void VappUCMainScr::ucPlayVideoFile(const WCHAR* filename, const WCHAR* filepath)
{
    VappUcAppData* app = (VappUcAppData*)(this->m_app_data);

#ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__
    if( vapp_uc_check_serialize_support_cui(UC_CUI_VIDEO_PLAYER) )
    {
        VappOpenVideoPlayerParam param;
        param.instance = app->main->instance;
        param.parent_gid = getApp()->getGroupId();
        param.filepath = filepath;
        param.filename = filename;    
        m_app_data->vappUcSetSerialize(param.instance,param.parent_gid);
        getApp()->serialize((void*)UC_CUI_VIDEO_PLAYER, VFX_TRUE, 
                            vapp_uc_open_video_player_cui, &param, sizeof(param), vapp_uc_proxy_proc);
    }
    else
#endif /* __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__ */
    {
    	app->main->cui_gid = vcui_gallery_video_player_create(getApp()->getGroupId(), filepath);

    	 if (app->main->cui_gid > 0)
    	 {
    		 vfxSetCuiCallerScr(app->main->cui_gid, this);
    		 /*check for setting the title*/
             vcui_gallery_set_title_str_ptr(app->main->cui_gid, filename);
    		 vcui_gallery_run(app->main->cui_gid);
             app->main->cui_type = UC_CUI_VIDEO_PLAYER;
    	 }
    }

}
#endif /* __MMI_COSMOS_UC_VIDEO_PREVIEW_SUPPORT__ */
#endif /*  #ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__  */

void VappUCMainScr::ucOpenImageViewer(const WCHAR* filename, const WCHAR* filepath)
{
	VappUcAppData* app = (VappUcAppData*)(this->m_app_data);

	app->main->cui_gid = vcui_gallery_image_viewer_create(getApp()->getGroupId(), filepath);

	 if (app->main->cui_gid > 0)
	 {
		 vfxSetCuiCallerScr(app->main->cui_gid, this);
		 /*check for setting the title*/
         vcui_gallery_set_title_str_ptr(app->main->cui_gid,filename);
		 vcui_gallery_run(app->main->cui_gid);
         app->main->cui_type = UC_CUI_IMAGE_VIEWER;
	 }


}
void VappUCMainScr::ucEnterMultimediaApp(void)
{

#if (!defined(__LOW_COST_SUPPORT_COMMON__) || defined(__MMI_SOUNDREC_CUI__) )	
    VappUcAppData* app = (VappUcAppData*)(this->m_app_data);

#ifdef __MMI_SOUNDREC_CUI__
	if (app->main->highlighted_object_type == SRV_UC_OBJECT_TYPE_AUDIO &&
		app->main->select_media_opt == UC_MEDIA_OPT_INSERT)
	{	
		app->main->cui_gid = vcui_soundrec_create(getApp()->getGroupId());
		if (app->main->cui_gid > 0)
		{
			vfxSetCuiCallerScr(app->main->cui_gid, this);
			/* Set size limit to 300k */
			app->available_size = app->getMaxMediaFileSizeAllowed(SRV_UC_OBJECT_TYPE_VIDEO);
            if((VfxU32)app->available_size < (VfxU32)1)
            {
                    app->available_size = 1 ;
            }
			vcui_soundrec_set_record_size(app->main->cui_gid, app->available_size);
			vcui_soundrec_run(app->main->cui_gid);
            app->main->cui_type = UC_CUI_SOUND_RECORDER;
		}

	}
	
#endif /* __MMI_SOUNDREC_CUI__ */ 
#if (!defined(__LOW_COST_SUPPORT_COMMON__))
        if(app->main->highlighted_object_type == SRV_UC_OBJECT_TYPE_IMAGE &&
				app->main->select_media_opt == UC_MEDIA_OPT_INSERT)
	{
		vcui_camco_err_code_enum errCode = VCUI_CAMCO_ERR_NONE;
		vcui_camco_param_struct param;
            if ((errCode = vcui_standard_camera_launchable_check())== VCUI_CAMCO_ERR_NONE)
            {
                    vcui_standard_camera_struct_init (&param);
                    app->main->cui_gid = vcui_standard_camera_create (getApp()->getGroupId(), &param);
            
                    if (app->main->cui_gid > 0)
                    {
                            vfxSetCuiCallerScr(app->main->cui_gid, this);
                            vcui_standard_camera_run(app->main->cui_gid);
							app->main->cui_type =  UC_CUI_CAMERA;
                    }
            }
		    else
		    {
			    //seems Camcoder not ready 
			    mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
				    (WCHAR*)VFX_WSTR_RES(vcui_standard_camera_get_err_string(errCode)).getBuf());
		    }
	}
	
#endif /* (!defined(__LOW_COST_SUPPORT_COMMON__)) */

#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
#if (!defined(__LOW_COST_SUPPORT_COMMON__))
	if(app->main->highlighted_object_type == SRV_UC_OBJECT_TYPE_VIDEO &&
				app->main->select_media_opt == UC_MEDIA_OPT_INSERT)
	{
		    vcui_camco_err_code_enum errCode = VCUI_CAMCO_ERR_NONE;
			vcui_camco_param_struct param;
//			vcui_camco_setting_limit_struct* temp_limit;
			//VFX_SYS_ALLOC_MEM(app->g_settingLimitation ,sizeof(vcui_camco_setting_limit_struct));
			//temp_limit = (vcui_camco_setting_limit_struct*)app->g_settingLimitation ;

            if ((errCode = vcui_standard_recorder_launchable_check())== VCUI_CAMCO_ERR_NONE)
            {
                    vcui_standard_recorder_struct_init (&param);
                    app->available_size = (app->getMaxMediaFileSizeAllowed(SRV_UC_OBJECT_TYPE_VIDEO))/1024;
                    if((VfxU32)app->available_size < (VfxU32)1)
                    {
                            app->available_size = 1 ;
                    }
                    vcui_standard_recorder_recsize(app->available_size);
                    app->main->cui_gid = vcui_standard_recorder_create (getApp()->getGroupId(), &param);

                    if (app->main->cui_gid > 0)
                    {
                            vfxSetCuiCallerScr(app->main->cui_gid, this);
                            vcui_standard_recorder_run(app->main->cui_gid);
                            app->main->cui_type = UC_CUI_CAMCORDER;
                    }
            }
		    else
		    {
			    //seems Camcoder not ready 
			    mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
				    (WCHAR*)VFX_WSTR_RES(vcui_standard_recorder_get_err_string(errCode)).getBuf());
		    }
    }
#endif /* (!defined(__LOW_COST_SUPPORT_COMMON__)) */ 
#endif /* #ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__ */

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
    #endif
#ifdef __MMI_EMAIL__
    if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
    {
		app->main->highlighted_object_type = SRV_UC_OBJECT_TYPE_ATTACHMENT;        
    }        
#endif
#endif
}


void VappUCMainScr::vappUcOnConfirm(VfxObject* obj, VfxId id)
{
	VfxBool input =  (id == VCP_CONFIRM_POPUP_BUTTON_YES) ? VFX_TRUE : VFX_FALSE;
    VappUcAppData* app = (VappUcAppData*)(m_app_data);
    if(app && app->main->confirm_handler)
    {
        app->main->confirm_handler(input, (void *)app);
    }
    //if(input)
    {
        connectOnPage();
    }
}

void VappUCMainScr::vappUcShowConfirm(VfxU16 str_id)
{
    VcpConfirmPopup *confirm;
    VFX_OBJ_CREATE(confirm, VcpConfirmPopup, this);
    confirm->setInfoType(VCP_POPUP_TYPE_QUESTION);
    VfxWString txt(str_id);
    confirm->setText(txt);
    confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
    confirm->setCustomButton(
                VfxWString(STR_ID_VAPP_UC_CONTINUE), 
                VfxWString(STR_GLOBAL_CANCEL), 
                VCP_POPUP_BUTTON_TYPE_NORMAL, 
                VCP_POPUP_BUTTON_TYPE_CANCEL);
    confirm->m_signalButtonClicked.connect(this, &VappUCMainScr::vappUcOnConfirm);
    confirm->setAutoDestory(VFX_TRUE);
    confirm->show(VFX_TRUE);
    return;
}


void VappUCMainScr::vappUcOnSendConfirm(VfxObject* obj, VfxId id)
{
	VfxBool input =  (id == VCP_CONFIRM_POPUP_BUTTON_YES) ? VFX_TRUE : VFX_FALSE;

	if(input == VFX_TRUE)
	{
		composer_page->onSelectingSend();
	}

	return;
}

//response of continue or cancel on sim swithcing
void VappUCMainScr::vappOnSimSwapConfirm(VfxObject* obj, VfxId id)
{
   VfxBool input =  (id == VCP_CONFIRM_POPUP_BUTTON_YES) ? VFX_TRUE : VFX_FALSE;

	if(input == VFX_TRUE)
	{
		VappUcAppData* app = (VappUcAppData*)(this->m_app_data);
		app->m_service_cntxt->send_info->send_sim_id = (srv_uc_sim_id)(vappUcGetValidSimInfo()) ;
		/*title should be updated according to new SIM */
        U16 text_buffer[50] = {0,};
        VfxWString itemText;
        app->ucGetComposerTitleString(text_buffer);
        composer_page->SetTitleAfterSend(text_buffer);
        composer_page->onEntertoggleString();
		#ifdef __MMI_EMAIL__
		if (app->m_service_cntxt->msg_type->MMS_edit_mode != SRV_UC_MMS_EDIT_MODE_EMAIL)
		#endif
		composer_page->UpdateSendButtonOnSwithSim();
		if(!(app->m_service_cntxt->send_info->send_sim_id & vappUcGetBlockedSimInfo())) /*available sim is blocked*/
		{
			composer_page->validSimSend();
		}
		else if(app->m_service_cntxt->send_info->send_sim_id & vappUcGetBlockedSimInfo())
		{
			if(app->m_service_cntxt->send_info->send_sim_id == SRV_UC_SIM_ID_GSM_SIM1)
			{
				mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_BLOCKED_SIM1_ID)).getBuf());
			}
			else if(app->m_service_cntxt->send_info->send_sim_id == SRV_UC_SIM_ID_GSM_SIM2)
			{
				mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_BLOCKED_SIM2_ID)).getBuf());
			}
			else if(app->m_service_cntxt->send_info->send_sim_id == SRV_UC_SIM_ID_GSM_SIM3)
			{
				mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_BLOCKED_SIM3_ID)).getBuf());
			}
			else if(app->m_service_cntxt->send_info->send_sim_id == SRV_UC_SIM_ID_GSM_SIM4)
			{
				mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_BLOCKED_SIM4_ID)).getBuf());
			}
			else
			{
				MMI_ASSERT(0);
			}
		}
	}	
	return;
}
// sim is valid , direct send
void VappComposerMainPage::validSimSend(void)
{
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);

    deactivateEditor();

    VFX_OBJ_CREATE(m_popup,VcpIndicatorPopup,this);
    m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    m_popup->setText(VFX_WSTR_RES(STR_GLOBAL_SENDING));
    m_popup->setAutoDestory(VFX_FALSE);
    m_popup->show(VFX_TRUE);

    app->m_signalConnectToCloseProgress.connect(getMainScr(), &VappUCMainScr::connectToCloseProgress);
    app->m_signalConnectOnError.connect(getMainScr(), &VappUCMainScr::connectToClose);

	app->sendMessage();
}
void VappComposerMainPage::SetTitleAfterSend(U16* text_buffer)
{
	VfxWString itemText;
	composerTitleBar->setTitle(itemText.loadFromMem((VfxWChar*)text_buffer));
}
void VappUCMainScr::vappUcShowSendConfirm(VfxWChar* text_buffer)
{
    VcpConfirmPopup *confirm;
    VFX_OBJ_CREATE(confirm, VcpConfirmPopup, this);
    confirm->setInfoType(VCP_POPUP_TYPE_QUESTION);
    VfxWString itemText;
    confirm->setText(itemText.loadFromMem((VfxWChar*)text_buffer));
    confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
    confirm->setCustomButton(
                VfxWString(STR_ID_VAPP_UC_CONTINUE), 
                VfxWString(STR_GLOBAL_CANCEL), 
                VCP_POPUP_BUTTON_TYPE_NORMAL, 
                VCP_POPUP_BUTTON_TYPE_CANCEL);
    confirm->m_signalButtonClicked.connect(this, &VappUCMainScr::vappUcOnSendConfirm);
    confirm->setAutoDestory(VFX_TRUE);
    confirm->show(VFX_TRUE);
    return;
}
// confirmation screen for sim Switching
void VappUCMainScr::vappUcShowSimSwapConfirm(U16* text_buffer)
{
    VcpConfirmPopup *confirm;
    VFX_OBJ_CREATE(confirm, VcpConfirmPopup, this);
    confirm->setInfoType(VCP_POPUP_TYPE_QUESTION);
    VfxWString itemText;
    confirm->setText(itemText.loadFromMem((VfxWChar*)text_buffer));
    confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
    confirm->setCustomButton(
                VfxWString(STR_ID_VAPP_UC_CONTINUE), 
                VfxWString(STR_GLOBAL_CANCEL), 
                VCP_POPUP_BUTTON_TYPE_NORMAL, 
                VCP_POPUP_BUTTON_TYPE_CANCEL);
    confirm->m_signalButtonClicked.connect(this, &VappUCMainScr::vappOnSimSwapConfirm);
    confirm->setAutoDestory(VFX_TRUE);
    confirm->show(VFX_TRUE);
    return;
}

#ifdef __MMI_COSMOS_UC_MMS_PREVIEW_SUPPORT__ 
void VappUCMainScr::ucPreviewMms(void)
{
#ifdef __MMI_MMS_2__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VappUcAppData* app = (VappUcAppData*)(this->m_app_data);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__
    if( vapp_uc_check_serialize_support_cui(UC_CUI_PREVIEW_MMS) )
    {
        VappOpenVideoPlayerParam param;
        param.instance = app->main->instance;
        param.parent_gid = getApp()->getGroupId();    
        m_app_data->vappUcSetSerialize(param.instance,param.parent_gid);
        getApp()->serialize((void*)UC_CUI_PREVIEW_MMS, VFX_TRUE, 
                            vapp_uc_open_mms_preview_cui, &param, sizeof(param), vapp_uc_proxy_proc);
    }
    else
#endif /* __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__ */
    {  
        app->main->cui_gid = GRP_ID_INVALID;
        app->main->cui_gid = cui_vapp_mms_preview_mms_create(getApp()->getGroupId(), app->m_service_cntxt->send_info->new_msg_id);
        if(app->main->cui_gid != GRP_ID_INVALID)
        {
    		vfxSetCuiCallerScr(app->main->cui_gid, this);
    		cui_vapp_mms_preview_mms_run(app->main->cui_gid);
            app->main->cui_type = UC_CUI_PREVIEW_MMS;
        }
    }


#endif
}
#endif /* __MMI_COSMOS_UC_MMS_PREVIEW_SUPPORT__  */

#if defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__) && defined(BROWSER_SUPPORT)
void VappUCMainScr::ucSelectBookMark()
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
  	VappUcAppData* app = (VappUcAppData*)(this->m_app_data);

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	app->main->cui_gid = vcui_bkm_sel_bkm_create(getApp()->getGroupId());

	 if (app->main->cui_gid > 0)
	 {
		vfxSetCuiCallerScr(app->main->cui_gid, this);
		vcui_bkm_sel_bkm_run(app->main->cui_gid);
        app->main->cui_type = UC_CUI_SELECT_BOOKMARK;
	 }

	 #ifndef BROWSER_SUPPORT
		else
		{
			mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_GLOBAL_NOT_SUPPORTED)).getBuf());
		}
	#endif
}
#endif

#ifdef __MMI_VCALENDAR__
void VappUCMainScr::ucOpenCalenderList(VfxU32  type)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	VappUcAppData* app = (VappUcAppData*)(this->m_app_data);

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	app->main->cui_gid = vcui_cal_list_create(getApp()->getGroupId(), (vcui_cal_list_type_enum)type);

	if (app->main->cui_gid > 0)
	{
		vfxSetCuiCallerScr(app->main->cui_gid, this);	
		vcui_cal_list_run(app->main->cui_gid);
        app->main->cui_type = UC_CUI_CAL_LIST;
	}
}
#endif /* __MMI_VCALENDAR__ */


void VappUCMainScr::ucOpenPhoneBook(VfxBool isMultiSelect, VfxU32 mode)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
  	VappUcAppData* app = (VappUcAppData*)(this->m_app_data);

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	app->main->cui_gid = vcui_phb_list_create(getApp()->getGroupId());

	 if (app->main->cui_gid > 0)
	 {
       
       vcui_phb_list_set_req_field(app->main->cui_gid, mode);			 
		
		 if (!isMultiSelect)
		 {
			 vcui_phb_list_set_req_count(app->main->cui_gid, 1);			 
		 }
		 else
		 {
			vcui_phb_list_set_req_count(app->main->cui_gid, (app->vappUcGetMaxRecipientCount() - app->m_service_cntxt->msg->to_num));
		 }

		 vfxSetCuiCallerScr(app->main->cui_gid, this);
		 if(app->m_pbInsertState == UC_PB_CUI_STATE_INSERT_ADDRESS)
		{
		 vcui_phb_list_set_title_str(app->main->cui_gid ,STR_ID_VAPP_UC_ADD_RECIPIENT);
		}
     #ifdef __MMI_VCARD__    
		else if (app->m_pbInsertState == UC_PB_CUI_STATE_INSERT_VCARD)
		{
         vcui_phb_list_set_title_str(app->main->cui_gid ,STR_ID_VAPP_UC_INSERT_VCARD);
		}
     #endif   
		 vcui_phb_list_run(app->main->cui_gid);
         app->main->cui_type = UC_CUI_PHB_LIST;
	 }
}

#ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__

VfxBool VcuiUcMainCui::onProcBeforeRestore(VappUcCuiResult *cui_result)
{
    VappUcAppData* app = (VappUcAppData*)(this->m_app_data);
    VfxBool close_uc = VFX_FALSE;

    
    if( cui_result->event_wait_to_proc == VFX_TRUE )
    {      
        cui_result->event_wait_to_proc = VFX_FALSE;
        close_uc = cui_result->close_uc;    
        switch(cui_result->event.evt_id)
        {
            case EVT_ID_SRV_SMS_DEL_MSG:
                break;
            case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
                vfxPostInvoke0(app, &VappUcAppData::vappUcSdPlugInHdlr);  
                break;
            case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
                vfxPostInvoke0(app, &VappUcAppData::vappUcSdPlugOutHdlr);   
                break;
            case EVT_ID_SRV_SIM_CTRL_UNAVAILABLE:
                break;
            case EVT_ID_SRV_SIM_CTRL_AVAILABLE:           
                break;
        #ifdef __MMI_USB_SUPPORT__
            case EVT_ID_USB_ENTER_MS_MODE:
                vfxPostInvoke0(app, &VappUcAppData::vappUcUsbMsModePlugInHdlr);  
                break;
        #endif
            case EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED:
                break;
            case EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY:
                break;
            case EVT_ID_SRV_MMS_MMA_TERMINATE:
                break;    
            default:
                cui_result->event_wait_to_proc = VFX_TRUE;
                break;
        }
    }
    
    return close_uc;
}

void VcuiUcMainCui::onProcAfterRestore(VappUcCuiResult *cui_result)
{
    VappUcAppData* app = (VappUcAppData*)(this->m_app_data);
    VappUCMainScr *main_scr = (VappUCMainScr*)(this->m_scr);
    
    if( cui_result->event_wait_to_proc == VFX_TRUE )
    {
        switch(cui_result->event.evt_id)
        {
            case EVT_ID_VCUI_GALLERY_CLOSE_GID: /*Event from Gallery*/
            {   
                    
                if (app->main->select_media_opt != UC_MEDIA_OPT_NONE)
                {
                    if (cui_result->result == VCUI_GALLERY_RESULT_OK)
                    {                 
                        main_scr->ucAddObjectFromAppSelectionProcess((PU16)cui_result->path_buffer, 0);
                    }
                }
            }        
                break;
            case EVT_ID_CLOSE_MMS_PREVIEW:
                if (app->main->cui_gid != GRP_ID_INVALID)
                {
    		        app->m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
    		        if (app->m_service_cntxt->send_info->new_msg_id)
    		        {
    			        app->ucClearMsgBearer(SRV_UC_MSG_TYPE_MMS_PREFER);
    		        }
                    app->main->cui_gid = GRP_ID_INVALID;
                    app->main->cui_type = UC_CUI_NONE;

                    cui_result->deinit_preview = VFX_FALSE;
                }
                break;
            
            case EVT_ID_GROUP_DEINIT:
                // free resource if required
                break;
            default:
                break;
        }
        cui_result->event_wait_to_proc = VFX_FALSE;
    }
    
    
    if (cui_result->deinit_preview == VFX_TRUE)
    {
        app->m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
        app->send_info->abort = UC_ABORT_NONE;
        if (app->m_service_cntxt->send_info->new_msg_id)
        {
            app->ucDeleteMmsReq(app->m_service_cntxt->send_info->new_msg_id, app->send_info->new_msg_storage);
            app->m_service_cntxt->send_info->new_msg_id = 0;
        }
    }
    
    	if (cui_result->isSuccess == VFX_TRUE && cui_result->close_uc == VFX_FALSE)
    	{
    		if (app->main->launch_mode == UC_LAUNCH_MODE_INSERT)
    		{
    			if(mmi_ucs2strlen((S8*)app->m_service_cntxt->main->text_buffer) > 0 )
    			{
    				main_scr->getComposerPage()->setTextBodyeditorActiveOnPage();
    			}
                app->main->launch_mode = UC_LAUNCH_MODE_NONE;
    		}
    	}

    	if(cui_result->need_set_active_vk == VFX_TRUE && cui_result->close_uc == VFX_FALSE)
    	{
    		main_scr->getComposerPage()->setTextBodyeditorActiveOnPage();
    	}

    if (app->main->cui_gid != GRP_ID_INVALID)
    {
        main_scr->vappUcCloseCui();
    }
        
    m_isInRestore = VFX_FALSE;
    return;
}

VfxBool vapp_uc_check_serialize_support_cui(VappUcCuiTypeEnum cui_type)
{
    if( 
    #ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
        cui_type == UC_CUI_VIDEO_PLAYER ||
    #endif    
        cui_type == UC_CUI_GALLERY_IMG_PCKR ||
    #ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
        cui_type == UC_CUI_GALLERY_VIDEO_PCKR ||
    #endif    
        cui_type == UC_CUI_PREVIEW_MMS ||
        cui_type == UC_CUI_MUSIC_PLAYER)
    {
        return VFX_TRUE;
    }
    else
        return VFX_FALSE;
  
}

void vapp_uc_close_serialize_support_cui(VappUcCuiTypeEnum cui_type, mmi_id cui_gid)
{
    if( vapp_uc_check_serialize_support_cui(cui_type) == VFX_FALSE )
    {
        return;
    }
  
    switch(cui_type)
    {
    #ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
        case UC_CUI_VIDEO_PLAYER:
            vcui_gallery_close(cui_gid);
            break;
    #endif        
        case UC_CUI_GALLERY_IMG_PCKR:
    #ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__        
        case UC_CUI_GALLERY_VIDEO_PCKR:
    #endif
            vcui_gallery_close(cui_gid);
            break;
        
        case UC_CUI_PREVIEW_MMS:
        {
        #ifdef __MMI_MMS_2__
            cui_vapp_mms_preview_mms_close(cui_gid);
        #endif
            break;
        }    
        default :
            break;
    }    
}

mmi_ret vapp_uc_static_event_handler(mmi_event_struct *evt, VfxBool is_need_close_uc)
{
    VappUcAppDataAfterSerialize* app ;
    U32 instance;
    VfxBool close_uc = VFX_FALSE;
    VfxBool deinit_preview = VFX_FALSE;
    VfxBool close_cui = VFX_FALSE;
    VfxBool attach_removed = VFX_FALSE;
        
      

    for(instance=0;instance<MAX_UC_INSTANCES;instance++)
    {
        app = &(g_uc_app_data_serialized[instance]);
        if(app->is_serialized )
        {                 
            switch(evt->evt_id)
            {
                case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
                {
                    vappUcCheckIfNeedCloseUcOnSdPlugOut(&close_uc, &deinit_preview, app->m_service_cntxt, app->send_info );
                    if(deinit_preview)
                        app->send_info->abort = UC_ABORT_NONE;
                    vappUcHandleObjOnSdPlugOut(app->m_service_cntxt, app->main, &attach_removed, &close_cui);
                    vappUcChangeMsgTypeIfNeeded(app->m_service_cntxt, app->main);
                #ifdef __MMI_MMS_2__
                    if (app->m_service_cntxt->send_info->action == SRV_UC_ACTION_PREVIEW
                        && app->m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                    {
                    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
                        if(!deinit_preview)
                    #endif
                        {
                            deinit_preview = VFX_TRUE;
                        }
                    }
                #endif /* __MMI_MMS_2__ */ 

                    if(deinit_preview || attach_removed)
                    {
                        close_cui = VFX_TRUE;
                    }
                    if(close_cui && app->m_service_cntxt->send_info->action == SRV_UC_ACTION_PREVIEW)
                    {
                        deinit_preview = VFX_TRUE;
                    }
        
                }
                    break;
            #ifdef __MMI_USB_SUPPORT__
                case EVT_ID_USB_ENTER_MS_MODE:
                {
                    close_uc = VFX_TRUE;
                    close_cui = VFX_TRUE;
                    deinit_preview = VFX_TRUE;           
                }
                    break;
            #endif
                default :
                    break;
            }
            
            if( (close_cui == VFX_TRUE || close_uc == VFX_TRUE ) && (app->main->cui_gid != GRP_ID_INVALID) )
            {
                memset( &(app->cui_result), 0, sizeof(VappUcCuiResult));
                app->cui_result.isSuccess = VFX_FALSE;
                app->cui_result.need_set_active_vk = VFX_FALSE;
                app->cui_result.event_wait_to_proc = VFX_TRUE;      
                memcpy( &(app->cui_result.event), evt, sizeof(mmi_event_struct) ); 
                app->cui_result.result = 0; // no need in static event handler
                app->cui_result.close_uc = close_uc;
                app->cui_result.deinit_preview = deinit_preview;

                app->is_closing_cui = VFX_TRUE;
                vapp_uc_close_serialize_support_cui(app->main->cui_type, app->main->cui_gid);
                app->main->cui_gid = GRP_ID_INVALID;
                app->main->cui_type = UC_CUI_NONE; 
            }
        }
    }
    return MMI_RET_OK;
}

mmi_ret vapp_uc_music_player_cui_handler(mmi_event_struct *evt)
{
    VappUcAppDataAfterSerialize* app ;
    mmi_group_event_struct *galleryEvt = (mmi_group_event_struct*)evt;
    mmi_id cui_id = galleryEvt->sender_id;
    U32 instance;
    
    for(instance=0;instance<MAX_UC_INSTANCES;instance++)
    {
        app = &(g_uc_app_data_serialized[instance]);
        if(app->is_serialized && app->main->cui_gid  == cui_id)
        {                 
            break ;
        }
    }
    if( instance == MAX_UC_INSTANCES)
    {
        MMI_ASSERT(0);
        return MMI_RET_ERR; 
    }
    
    memset( &(app->cui_result), 0, sizeof(VappUcCuiResult));
    app->cui_result.isSuccess = VFX_TRUE;
    app->cui_result.need_set_active_vk = VFX_FALSE;
    app->cui_result.event_wait_to_proc = VFX_FALSE;      
    memcpy( &(app->cui_result.event), evt, sizeof(mmi_event_struct) ); 
    app->cui_result.result = 0;
    app->cui_result.close_uc = VFX_FALSE;
    app->cui_result.deinit_preview = VFX_FALSE;

    app->is_closing_cui = VFX_TRUE;
    vcui_music_player_close(app->main->cui_gid);
    app->main->cui_gid = GRP_ID_INVALID;
    app->main->cui_type = UC_CUI_NONE;

     return MMI_RET_OK; 
}

mmi_ret vapp_uc_gallery_cui_handler(mmi_event_struct *evt)
{
    VappUcAppDataAfterSerialize* app ;
    vcui_gallery_evt_struct *galleryEvt = (vcui_gallery_evt_struct*)evt;
    mmi_id cui_id = galleryEvt->sender_id;
    U32 instance;
    
    for(instance=0;instance<MAX_UC_INSTANCES;instance++)
    {
        app = &(g_uc_app_data_serialized[instance]);
        if(app->is_serialized && app->main->cui_gid  == cui_id)
        {                 
            break ;
        }
    }
    if( instance == MAX_UC_INSTANCES)
    {
        MMI_ASSERT(0);
        return MMI_RET_ERR; 
    }
    
    memset( &(app->cui_result), 0, sizeof(VappUcCuiResult));
    app->cui_result.isSuccess = VFX_FALSE;
    app->cui_result.need_set_active_vk = VFX_FALSE;
    app->cui_result.event_wait_to_proc = VFX_TRUE;      
    memcpy( &(app->cui_result.event), evt, sizeof(mmi_event_struct) ); 
    app->cui_result.result = (S32)galleryEvt->result;
    app->cui_result.close_uc = VFX_FALSE;
    app->cui_result.deinit_preview = VFX_FALSE;
        
    if (app->main->select_media_opt != UC_MEDIA_OPT_NONE)
    {
        if (galleryEvt->result == VCUI_GALLERY_RESULT_OK)
        {
            U32 buff_size = VappUcCuiResultSize; //(SRV_FMGR_PATH_MAX_LEN + 1 ) * sizeof(WCHAR);
            vcui_gallery_picker_get_single_path(app->main->cui_gid, app->cui_result.path_buffer, &buff_size);                      
            app->cui_result.isSuccess = VFX_TRUE;                     
        }
    }
    
    app->is_closing_cui = VFX_TRUE;
    vapp_uc_close_serialize_support_cui(app->main->cui_type, app->main->cui_gid);
    app->main->cui_gid = GRP_ID_INVALID;
    app->main->cui_type = UC_CUI_NONE;
    return MMI_RET_OK;
}

mmi_ret vapp_uc_mms_preview_handler(mmi_event_struct *evt)
{

    VappUcAppDataAfterSerialize* app ;
    cui_vapp_mms_preview_evt_struct *mmsPreviewEvt = (cui_vapp_mms_preview_evt_struct*)evt;
    mmi_id cui_id = mmsPreviewEvt->sender_id;
    U32 instance;
    
    for(instance=0;instance<MAX_UC_INSTANCES;instance++)
    {
        app = &(g_uc_app_data_serialized[instance]);
        if(app->is_serialized && app->main->cui_gid  == cui_id)
        {                 
            break ;
        }
    }
    if( instance == MAX_UC_INSTANCES)
    {
        /*  mms preview cui will send this event twice, and when the second event comes
            the previous serializd UC has been restored already, so we need to ignore 
            the second event, because it's nonsense
        */
        //MMI_ASSERT(0);
        return MMI_RET_ERR; 
    }
    
    memset( &(app->cui_result), 0, sizeof(VappUcCuiResult));
    app->cui_result.isSuccess = VFX_FALSE;
    app->cui_result.need_set_active_vk = VFX_FALSE;
    app->cui_result.event_wait_to_proc = VFX_TRUE;      
    memcpy( &(app->cui_result.event), evt, sizeof(mmi_event_struct) ); 
    app->cui_result.result = 0;  // no need in mms preview handler
    app->cui_result.close_uc = VFX_FALSE;
    app->cui_result.deinit_preview = VFX_FALSE;

    if (app->main->cui_gid != GRP_ID_INVALID) 
    {
        app->is_closing_cui = VFX_TRUE;
        vapp_uc_close_serialize_support_cui(UC_CUI_PREVIEW_MMS, app->main->cui_gid);
        app->cui_result.deinit_preview = VFX_TRUE;
    }

    return MMI_RET_OK;
}

mmi_ret vapp_uc_deinit_in_serialize(VappUcAppDataAfterSerialize* app)
{
    VappUcAppData m_app_data;

    if(app)
        {
            if (app->m_service_cntxt->send_info->new_msg_id)
            {
                vappUcClearMsgBearer(app->m_service_cntxt, app->send_info, SRV_UC_MSG_TYPE_MMS_PREFER);
            }
    #ifdef __MMI_EMAIL__
            if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
            {
                cui_msgcomposer_evt_struct evt;
                MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_UC_EMAILCOMPOSER_CLOSE, app->group_id);
                mmi_frm_group_post_to_caller(app->group_id, (mmi_group_event_struct*)&evt);
            }
            else
    #endif /* __MMI_EMAIL__ */
            if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_LEMEI_MMS)
            {
                cui_msgcomposer_evt_struct evt;
                MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_UC_LEMEICOMPOSER_CLOSE, app->group_id);
                mmi_frm_group_post_to_caller(app->group_id, (mmi_group_event_struct*)&evt);
            }
            else
            {

                cui_msgcomposer_evt_struct evt;
                MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_UC_MSGCOMPOSER_CLOSE, app->group_id);
                mmi_frm_group_post_to_caller(app->group_id, (mmi_group_event_struct*)&evt);
            }
           
            vappUcResetApp(app->main, app->send_info, app->m_service_cntxt);
            srv_uc_delete(app->main->instance);
            vappUcResetAppDataByInstance(app->main->instance);
            vadpAsmFree(app->group_id, app->archive_data.p_vapp_uc_asm);
         
            vappUcResetSerialize(app->main->instance);
            app->is_serialized = VFX_FALSE;
            app->group_id = GRP_ID_INVALID;
            
    }
    return MMI_RET_OK;
}

mmi_ret vapp_uc_deinit_handler(mmi_event_struct *evt)
{  
    VappUcAppDataAfterSerialize* app=NULL;
    U32 instance=0;
    vfx_app_serialize_evt_struct* serialize_evt = (vfx_app_serialize_evt_struct*)evt;
    VappUcAppArchive *ucArchive;
    U32 sizeVappUcAppArchive;
       
    if (serialize_evt->serializeData != NULL && serialize_evt->serializeDataSize != 0)
    {
        ucArchive = (VappUcAppArchive *) (serialize_evt->serializeData);
        sizeVappUcAppArchive= (U32) (serialize_evt->serializeDataSize); 
        VFX_ASSERT(sizeVappUcAppArchive == sizeof(VappUcAppArchive));
        instance = ucArchive->instance;
        app = ucArchive->app; 
    }
    else
    {
        return MMI_RET_OK;
    }
    
    VFX_ASSERT(instance < MAX_UC_INSTANCES);
    VFX_ASSERT(app != NULL);
    VFX_ASSERT(app == &(g_uc_app_data_serialized[instance]) );

    if( app->is_serialized )
    {
        vapp_uc_deinit_in_serialize(app);
        return MMI_RET_OK;
    }
    else
    {
        return MMI_RET_OK;
    }
}    

mmi_ret vapp_uc_check_is_ready_to_restore(mmi_event_struct *evt)
{
    VappUcAppDataAfterSerialize* app=NULL;
    U32 instance=0;
    vfx_app_serialize_evt_struct* serialize_evt = (vfx_app_serialize_evt_struct*)evt;
    VappUcAppArchive *ucArchive;
    U32 sizeVappUcAppArchive;
    
    if (serialize_evt->serializeData != NULL && serialize_evt->serializeDataSize != 0)
    {
        ucArchive = (VappUcAppArchive *) (serialize_evt->serializeData);
        sizeVappUcAppArchive= (U32) (serialize_evt->serializeDataSize); 
        VFX_ASSERT(sizeVappUcAppArchive == sizeof(VappUcAppArchive));
        instance = ucArchive->instance;
        app = ucArchive->app; 
    }
    else
    {
        return MMI_RET_OK;
    }

    
    VFX_ASSERT(instance < MAX_UC_INSTANCES);
    VFX_ASSERT(app != NULL);
    VFX_ASSERT(app == &(g_uc_app_data_serialized[instance]) );

    if( app->is_serialized && app->is_closing_cui == VFX_FALSE)
    {
        return MMI_RET_ERR;
    }
    else
    {
        return MMI_RET_OK;
    }
    
}
    
mmi_ret vapp_uc_proxy_proc(mmi_event_struct *evt)
{
    mmi_ret ret = MMI_RET_OK;
    VfxBool is_need_close_uc = VFX_FALSE;


    switch(evt->evt_id)
    {
        case EVT_ID_VCUI_MUSIC_PLAYER_CLOSE:
            ret = vapp_uc_music_player_cui_handler(evt);
            break;
        case EVT_ID_VCUI_GALLERY_CLOSE_GID:
            ret = vapp_uc_gallery_cui_handler(evt);    
            break;
        case EVT_ID_CLOSE_MMS_PREVIEW:
            ret = vapp_uc_mms_preview_handler(evt);
            break;
        case EVT_ID_GROUP_DEINIT:
            ret = vapp_uc_deinit_handler(evt);
            break;
        case EVT_ID_GROUP_ACTIVE:
            break;
        case EVT_ID_GROUP_FOCUSED:
            ret = vapp_uc_check_is_ready_to_restore(evt);
            break;
        case EVT_ID_SRV_SMS_DEL_MSG:
            break;
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
            ret = vapp_uc_static_event_handler(evt,is_need_close_uc);
            break; 
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
            ret = vapp_uc_static_event_handler(evt,is_need_close_uc);
            break; 
        case EVT_ID_SRV_SIM_CTRL_UNAVAILABLE:
            break;
        case EVT_ID_SRV_SIM_CTRL_AVAILABLE:           
            break;
    #ifdef __MMI_USB_SUPPORT__
        case EVT_ID_USB_ENTER_MS_MODE:
            ret = vapp_uc_static_event_handler(evt,is_need_close_uc);            
            break;
    #endif
        case EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED:
            break;
        case EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY:
            break;
        case EVT_ID_SRV_MMS_MMA_TERMINATE:
            ret = vapp_uc_static_event_handler(evt,is_need_close_uc);
            break;    
        default:
            break;
    }
    
    return ret;
}

void vapp_uc_open_audio_player_cui(void *arg, VfxU32 argSize)
{
    VFX_ASSERT(argSize == sizeof(VappOpenVideoPlayerParam));
    VappOpenVideoPlayerParam *param = (VappOpenVideoPlayerParam*)arg;
    const WCHAR* filename = param->filename; 
    const WCHAR* filepath = param->filepath;
    
    VappUcAppDataAfterSerialize* app ;    
    MMI_ASSERT(g_uc_app_data_serialized[param->instance].is_serialized != VFX_FALSE);
    app = &(g_uc_app_data_serialized[param->instance]);
    
    app->main->cui_gid = vcui_music_player_create(param->parent_gid, filepath);

    if (app->main->cui_gid != GRP_ID_INVALID)
    {
        //vfxSetCuiCallerScr(app->main->cui_gid, this);
        mmi_frm_group_set_caller_proc(app->main->cui_gid, vapp_uc_proxy_proc, NULL);
        vcui_music_player_run(app->main->cui_gid);
        vcui_music_player_set_title(app->main->cui_gid, filename);
        app->main->cui_type = UC_CUI_MUSIC_PLAYER;
    }
}

void vapp_uc_open_mms_preview_cui(void *arg, VfxU32 argSize)
{
    VFX_ASSERT(argSize == sizeof(VappOpenVideoPlayerParam));
    VappOpenVideoPlayerParam *param = (VappOpenVideoPlayerParam*)arg;
    
    VappUcAppDataAfterSerialize* app ;    
    MMI_ASSERT(g_uc_app_data_serialized[param->instance].is_serialized != VFX_FALSE);
    app = &(g_uc_app_data_serialized[param->instance]);
    

    app->main->cui_gid = GRP_ID_INVALID;
    app->main->cui_gid = cui_vapp_mms_preview_mms_create(param->parent_gid, app->m_service_cntxt->send_info->new_msg_id);
    if(app->main->cui_gid != GRP_ID_INVALID)
    {
        //vfxSetCuiCallerScr(app->main->cui_gid, this);
        mmi_frm_group_set_caller_proc(app->main->cui_gid, vapp_uc_proxy_proc, NULL);
        cui_vapp_mms_preview_mms_run(app->main->cui_gid);
        app->main->cui_type = UC_CUI_PREVIEW_MMS;
    }

}


#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
void vapp_uc_open_video_player_cui(void *arg, VfxU32 argSize)
{
    VFX_ASSERT(argSize == sizeof(VappOpenVideoPlayerParam));
    VappOpenVideoPlayerParam *param = (VappOpenVideoPlayerParam*)arg;
    const WCHAR* filename = param->filename; 
    const WCHAR* filepath = param->filepath;

    VappUcAppDataAfterSerialize* app ;    
    MMI_ASSERT(g_uc_app_data_serialized[param->instance].is_serialized != VFX_FALSE);
    app = &(g_uc_app_data_serialized[param->instance]);

    app->main->cui_gid = vcui_gallery_video_player_create(param->parent_gid, filepath);

    if (app->main->cui_gid > 0)
    {
     //vfxSetCuiCallerScr(app->main->cui_gid, this);
     mmi_frm_group_set_caller_proc(app->main->cui_gid, vapp_uc_proxy_proc, NULL);
     
     /*check for setting the title*/
     vcui_gallery_set_title_str_ptr(app->main->cui_gid, filename);
     vcui_gallery_run(app->main->cui_gid);
     app->main->cui_type = UC_CUI_VIDEO_PLAYER;
    }
}
#endif /* #ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__ */

void vapp_uc_open_gallery_cui(void *arg, VfxU32 argSize)
{
    VFX_ASSERT(argSize == sizeof(VappOpenGalleryParam));
    VappOpenGalleryParam *param = (VappOpenGalleryParam*)arg;
    VappUcAppDataAfterSerialize* app ;
    FMGR_FILTER filter;
    
    MMI_ASSERT(g_uc_app_data_serialized[param->instance].is_serialized != VFX_FALSE);
    app = &(g_uc_app_data_serialized[param->instance]);
    
       switch (app->main->highlighted_object_type)
        {
            case SRV_UC_OBJECT_TYPE_IMAGE:
            {
                if (app->m_service_cntxt->mms_info->creation_mode == MMA_CREATION_MODE_RESTRICTED)
                {
                    mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_IMAGE_RESTRICTED_MODE);
                    /* mmi_uc_set_file_mgr_filter(&filter, MMA_OPEN_RESTRICTED_IMAGE_TYPES); */
                }
                else
                {
                    mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_IMAGE_OPEN_MODE);
                    /* mmi_uc_set_file_mgr_filter(&filter, MMA_OPEN_IMAGE_TYPES); */
                }
                app->main->cui_gid = vcui_gallery_image_picker_create(param->parent_gid, MMI_FALSE, &filter);
                if (app->main->cui_gid)
                {
                    app->main->cui_type = UC_CUI_GALLERY_IMG_PCKR;
                }
            }
                break;
    
            
        #ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
            case SRV_UC_OBJECT_TYPE_VIDEO:
            {
                if (app->m_service_cntxt->mms_info->creation_mode == MMA_CREATION_MODE_RESTRICTED)
                {
                    mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_VIDEO_RESTRICTED_MODE);
                    /* mmi_uc_set_file_mgr_filter(&filter, MMA_OPEN_RESTRICTED_VIDEO_TYPES); */
                }
                else
                {
                    mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_VIDEO_OPEN_MODE);
                    /* mmi_uc_set_file_mgr_filter(&filter, MMA_OPEN_VIDEO_TYPES); */
                }
                app->main->cui_gid = vcui_gallery_video_picker_create(param->parent_gid, MMI_FALSE, &filter); 
                if (app->main->cui_gid)
                {
                    app->main->cui_type = UC_CUI_GALLERY_VIDEO_PCKR;
                }
                                                        
            }
                break;
        #endif
            
    
            default:
            {
                MMI_ASSERT(0);
            }
                break;
        }

        if (app->main->cui_gid)
        {
            //vfxSetCuiCallerScr(app->main->cui_gid, this);
            mmi_frm_group_set_caller_proc(app->main->cui_gid, vapp_uc_proxy_proc, NULL);
            vcui_gallery_run(app->main->cui_gid);   
        }

    #ifdef __MMI_EMAIL__
        if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
        {
            app->main->highlighted_object_type = SRV_UC_OBJECT_TYPE_ATTACHMENT;        
        }
    #endif
    
}
#endif /* __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__ */


void VappUCMainScr::ucOpenGallery(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
	VappUcAppData* app = (VappUcAppData*)(this->m_app_data);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    app->main->cui_gid = GRP_ID_INVALID;  

    switch (app->main->highlighted_object_type)
    {
        case SRV_UC_OBJECT_TYPE_IMAGE:
        {
        #ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__
            if( vapp_uc_check_serialize_support_cui(UC_CUI_GALLERY_IMG_PCKR) == VFX_TRUE )
            {
                VappOpenGalleryParam param;
                param.instance = app->main->instance;
                param.multi_select = MMI_FALSE;
                param.parent_gid = getApp()->getGroupId();

                m_app_data->vappUcSetSerialize(param.instance,param.parent_gid);
                getApp()->serialize((void*)UC_CUI_GALLERY_IMG_PCKR, VFX_TRUE, 
                                    vapp_uc_open_gallery_cui,&param, sizeof(param), vapp_uc_proxy_proc);
                return ;
            }
            else
        #endif /* __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__ */
            {
                if (app->m_service_cntxt->mms_info->creation_mode == MMA_CREATION_MODE_RESTRICTED)
                {
                    mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_IMAGE_RESTRICTED_MODE);
                    /* mmi_uc_set_file_mgr_filter(&filter, MMA_OPEN_RESTRICTED_IMAGE_TYPES); */
                }
                else
                {
                    mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_IMAGE_OPEN_MODE);
                    /* mmi_uc_set_file_mgr_filter(&filter, MMA_OPEN_IMAGE_TYPES); */
                }
    			app->main->cui_gid = vcui_gallery_image_picker_create(getApp()->getGroupId(), MMI_FALSE, &filter);
                if (app->main->cui_gid)
                {
                    app->main->cui_type = UC_CUI_GALLERY_IMG_PCKR;
                }
            }
        }
            break;
			
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__            
        case SRV_UC_OBJECT_TYPE_VIDEO:
#ifdef __MMI_COSMOS_UC_GALLERY_VIDEO_PICKER_SUPPORT__            
        {
        #ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__
            if( vapp_uc_check_serialize_support_cui(UC_CUI_GALLERY_VIDEO_PCKR) == VFX_TRUE )
            {        
                VappOpenGalleryParam param;
                param.instance = app->main->instance;
                param.multi_select = MMI_FALSE;
                param.parent_gid = getApp()->getGroupId();

                m_app_data->vappUcSetSerialize(param.instance,param.parent_gid);
                getApp()->serialize((void*)UC_CUI_GALLERY_VIDEO_PCKR, VFX_TRUE, 
                    vapp_uc_open_gallery_cui,&param, sizeof(param), vapp_uc_proxy_proc);
                return;
            }
            else
       #endif  /* __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__ */
            {
               if (app->m_service_cntxt->mms_info->creation_mode == MMA_CREATION_MODE_RESTRICTED)
               {
                   mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_VIDEO_RESTRICTED_MODE);
                   /* mmi_uc_set_file_mgr_filter(&filter, MMA_OPEN_RESTRICTED_VIDEO_TYPES); */
               }
               else
               {
                   mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_VIDEO_OPEN_MODE);
                   /* mmi_uc_set_file_mgr_filter(&filter, MMA_OPEN_VIDEO_TYPES); */
               }
               app->main->cui_gid = vcui_gallery_video_picker_create(getApp()->getGroupId(), MMI_FALSE, &filter); 
               if (app->main->cui_gid)
               {
                   app->main->cui_type = UC_CUI_GALLERY_VIDEO_PCKR;
               }

            }
       
        }
#else /* __MMI_COSMOS_UC_GALLERY_VIDEO_PICKER_SUPPORT__  */
        {
            if (app->m_service_cntxt->mms_info->creation_mode == MMA_CREATION_MODE_RESTRICTED)
            {
                mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_VIDEO_RESTRICTED_MODE);
                /* mmi_uc_set_file_mgr_filter(&filter, MMA_OPEN_RESTRICTED_AUDIO_TYPES); */
            }
            else
            {
                mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_VIDEO_OPEN_MODE);
                /* mmi_uc_set_file_mgr_filter(&filter, MMA_OPEN_AUDIO_TYPES); */
            }
			app->main->cui_gid = vcui_file_selector_create(getApp()->getGroupId(), (WCHAR*)L"root", &filter,
															VCUI_FILE_SELECTOR_STYLE_FILE_ONLY, CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FILE);
            if (app->main->cui_gid)
            {
                app->main->cui_type = UC_CUI_FILE_SELECTOR;
            }
        }


#endif /* __MMI_COSMOS_UC_GALLERY_VIDEO_PICKER_SUPPORT__  */
            break ;
#endif /* #ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__ */

        case SRV_UC_OBJECT_TYPE_AUDIO:
        {
            if (app->m_service_cntxt->mms_info->creation_mode == MMA_CREATION_MODE_RESTRICTED)
            {
                mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_AUDIO_RESTRICTED_MODE);
                /* mmi_uc_set_file_mgr_filter(&filter, MMA_OPEN_RESTRICTED_AUDIO_TYPES); */
            }
            else
            {
                mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_AUDIO_OPEN_MODE);
                /* mmi_uc_set_file_mgr_filter(&filter, MMA_OPEN_AUDIO_TYPES); */
            }
			app->main->cui_gid = vcui_file_selector_create(getApp()->getGroupId(), (WCHAR*)L"root", &filter,
															VCUI_FILE_SELECTOR_STYLE_FILE_ONLY, CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FILE);
            if (app->main->cui_gid)
            {
                app->main->cui_type = UC_CUI_FILE_SELECTOR;
            }
        }
            break;

        case SRV_UC_OBJECT_TYPE_ATTACHMENT:
        {
            if (app->m_service_cntxt->mms_info->creation_mode == MMA_CREATION_MODE_RESTRICTED)
            {
                mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_ATTACHMENT_RESTRICTED_MODE);
                /* mmi_uc_set_file_mgr_filter(&filter, MMA_OPEN_RESTRICTED_ATTACHMENT_TYPES); */
            }
            else
            {
                mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_ATTACHMENT_OPEN_MODE);
                /* mmi_uc_set_file_mgr_filter_all(&filter); */
            }
			app->main->cui_gid = vcui_file_selector_create(getApp()->getGroupId(), (WCHAR*)L"root", &filter,
									VCUI_FILE_SELECTOR_STYLE_FILE_ONLY, CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FILE);
            if (app->main->cui_gid)
            {
                app->main->cui_type = UC_CUI_FILE_SELECTOR;
            }
        }
            break;

        default:
        {
            MMI_ASSERT(0);
        }
            break;
    }
#if 1   //Gallery not supported
        if (app->main->cui_gid)
        {
            vfxSetCuiCallerScr(app->main->cui_gid, this);
    
            if (app->main->highlighted_object_type == SRV_UC_OBJECT_TYPE_AUDIO 
                || app->main->highlighted_object_type == SRV_UC_OBJECT_TYPE_ATTACHMENT
        #ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__    
            #ifndef __MMI_COSMOS_UC_GALLERY_VIDEO_PICKER_SUPPORT__  
                || app->main->highlighted_object_type == SRV_UC_OBJECT_TYPE_VIDEO
            #endif
        #endif
                )
            {
    
                vcui_file_selector_run(app->main->cui_gid);
            }
            else
            {
                vcui_gallery_run(app->main->cui_gid);
            }
        }
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
    #ifdef __MMI_EMAIL__
            if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
            {
                app->main->highlighted_object_type = SRV_UC_OBJECT_TYPE_ATTACHMENT;        
            }
    #endif

}

void VappUCMainScr::VappUCPreviewAttachment(VfxId index)
{
	VappUcAppData* app = (VappUcAppData*)(this->m_app_data);
	mma_mms_attachment_info_struct *attachment_media = NULL;
	mma_mms_slide_ref_object_struct *ref = NULL;
	applib_mime_type_struct *mime = NULL;
	U16* filePath = NULL;
	U16* fileName = NULL;
	VfxBool isFilePathVirtual = VFX_FALSE;

   /* List == ref list + attachment list */
    /* 1. REF */
    if (index < app->m_service_cntxt->msg->msg_body.total_ref_no)
    {
        /* selected object in the list is ref object */
        ref = srv_uc_get_ref_by_index(app->main->instance, index);
        /* because ref, could be multiple refereced */

		ASSERT(ref != NULL);

			fileName = ref->object->file_name_ucs;
			if (ref->object->is_virtual_file)
			{
				U16 length = (SRV_FMGR_PATH_MAX_LEN+ 1) * ENCODING_LENGTH;
				VFX_SYS_ALLOC_MEM(filePath,  length);
				app->ucGenerateFilePath(ref->object, (U8*)filePath);
				isFilePathVirtual = VFX_TRUE;
			}
			else
			{
				filePath = ref->object->file_path_ucs;
			}
    }
   /* 2. Attachment */
    else
    {
        /* selected object in the list is attach object */

       attachment_media = srv_uc_get_attachment_by_index(
                                                app->main->instance,
                                                (U16) (index - app->m_service_cntxt->msg->msg_body.total_ref_no));

		ASSERT(attachment_media != NULL);

		fileName = attachment_media->object->file_name_ucs;
		if (attachment_media->object->is_virtual_file)
		{
			U16 length = (SRV_FMGR_PATH_MAX_LEN+ 1) * ENCODING_LENGTH;
			VFX_SYS_ALLOC_MEM(filePath,  length);
			app->ucGenerateFilePath(attachment_media->object, (U8*)filePath);
			isFilePathVirtual = VFX_TRUE;
		}
		else
		{
			filePath = attachment_media->object->file_path_ucs;
		}
    }

    mime = applib_mime_get_file_type(fileName);
	if (mime != NULL)
	{
		switch (mime->mime_type)
		{
		case MIME_TYPE_TEXT:
			/*Launch ebook reader*/
			mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_UNSUPPORTED_MEDIA)).getBuf());
			break;
		case MIME_TYPE_IMAGE:
				this->ucOpenImageViewer(fileName , filePath);
			/*Launch Image Viewer*/
			break;
		case MIME_TYPE_AUDIO:
			this->ucPlayAudioFile(fileName, filePath);
			/*Launch Audio Player*/
			break;
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
    #ifdef __MMI_COSMOS_UC_VIDEO_PREVIEW_SUPPORT__  
		case MIME_TYPE_VIDEO:
			this->ucPlayVideoFile(fileName, filePath);
			/*Launch Video Player*/
			break;
    #endif
#endif    
		case MIME_TYPE_APPLICATION:
			{
#if defined(__MMI_VCARD__)
				if (mime->mime_subtype == MIME_SUBTYPE_XVCARD ||
					mime->mime_subtype == MIME_SUBTYPE_VCARD)
				{
					//Vcard
					this->ucPreviewVcard(fileName, filePath);
					break;
				}
#endif

#ifdef __MMI_VCALENDAR__
				if (mime->mime_subtype == MIME_SUBTYPE_XVCALENDAR ||
					mime->mime_subtype == MIME_SUBTYPE_HBSVCS ||
					mime->mime_subtype == MIME_SUBTYPE_CALENDAR)
				{
					//Vcard
					this->ucPreviewVcalendar(fileName, filePath);
					break;
				}
#endif                
			mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_UNSUPPORTED_MEDIA)).getBuf());
			}
			break;
		default:
			/*check for vcard and vcalendar and do the respective handling here*/
			mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_UNSUPPORTED_MEDIA)).getBuf());
			break;
		}
	}
	else
	{
		mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_UNSUPPORTED_MEDIA)).getBuf());	
	}
	if (isFilePathVirtual)
	{
		VFX_SYS_FREE_MEM(filePath);
	}
}
void  VappComposerMainPage::insertAddressItem(VfxU32 groupType, const VfxWChar *name, const VfxWChar *address, VfxU32 addressType)
{
	VfxWString itemText;

    if (groupType == SRV_UC_ADDRESS_GROUP_TYPE_TO)
	{
		if (addressType == SRV_UC_ADDRESS_TYPE_PHONE_NUMBER)
		{
			m_contactSelectorTo->add(itemText.loadFromMem((VfxWChar *)name), itemText.loadFromMem((VfxWChar *)address), VFX_WSTR_EMPTY);
		}
		else
		{
		   m_contactSelectorTo->add(itemText.loadFromMem((VfxWChar *)name), VFX_WSTR_EMPTY, itemText.loadFromMem((VfxWChar *)address));
		}
        this->m_contactSelectorTo->getInputbox()->deleteAll();
		m_contactSelectorTo->getInputbox()->setEnterKeyEnabled(VFX_FALSE);
	}
#ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__    
	else if (groupType == SRV_UC_ADDRESS_GROUP_TYPE_CC)
	{
		if (addressType == SRV_UC_ADDRESS_TYPE_PHONE_NUMBER)
		{
			m_contactSelectorCc->add(itemText.loadFromMem((VfxWChar *)name), itemText.loadFromMem((VfxWChar *)address), VFX_WSTR_EMPTY);
		}
		else
		{
			m_contactSelectorCc->add(itemText.loadFromMem((VfxWChar *)name), VFX_WSTR_EMPTY, itemText.loadFromMem((VfxWChar *)address));
		}
        this->m_contactSelectorCc->getInputbox()->deleteAll();
		m_contactSelectorCc->getInputbox()->setEnterKeyEnabled(VFX_FALSE);
	}
	else if (groupType == SRV_UC_ADDRESS_GROUP_TYPE_BCC)
	{
		if (addressType == SRV_UC_ADDRESS_TYPE_PHONE_NUMBER)
		{
			m_contactSelectorBcc->add(itemText.loadFromMem((VfxWChar *)name), itemText.loadFromMem((VfxWChar *)address), VFX_WSTR_EMPTY);
		}
		else
		{
			m_contactSelectorBcc->add(itemText.loadFromMem((VfxWChar *)name), VFX_WSTR_EMPTY, itemText.loadFromMem((VfxWChar *)address));
		}
	   this->m_contactSelectorBcc->getInputbox()->deleteAll();
	   m_contactSelectorBcc->getInputbox()->setEnterKeyEnabled(VFX_FALSE);
	}
#endif    
	else
	{
		ASSERT(0);
	}

#ifdef __MMI_EMAIL__
	VappUcAppData* app = (VappUcAppData*)(((VappUCMainScr*)getMainScr())->m_app_data);
	if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
	{
		VappEmailComp::addRecentContact((WCHAR*) address);
	}
#endif

}

void VappComposerMainPage::setTextBodyeditorActiveOnPage(void)
{
	if(textEditorBody)
	{
		if(cursorIndexToHeighlight != 0)
		{
			textEditorBody->setCursorIndex( cursorIndexToHeighlight);
			cursorIndexToHeighlight = 0;
		}
		 vfxPostInvoke1(textEditorBody, &VcpTextEditor::activate, VFX_TRUE);
	}
	//	textEditorBody->setAutoActivated(VFX_TRUE);
}


void VappUCMainScr::ucHandleAddressCallback(VfxU16 cnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VappUcAppData* app = (VappUcAppData*)(this->m_app_data);
    VfxU16 string_id = 0;
    VfxU32 count = 0;
    BOOL result = MMI_TRUE;    
 //   MMI_BOOL invalid_num = MMI_FALSE, invalid_email = MMI_FALSE, long_num = MMI_FALSE, long_email = MMI_FALSE;
    MMI_BOOL invalid_address = MMI_FALSE;
	VfxU16 buffLen = 0;
	VfxWChar *buff = NULL;
	VfxWChar *recipientName = NULL;
	srv_uc_address_type_enum addrType = SRV_UC_ADDRESS_TYPE_TOTAL_NUM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
	buffLen = (((SRV_UC_MAX_EMAIL_LEN  > SRV_UC_MAX_PHONE_NUMBER_LEN) ? SRV_UC_MAX_EMAIL_LEN : SRV_UC_MAX_PHONE_NUMBER_LEN) + 1 )* ENCODING_LENGTH;

	VFX_SYS_ALLOC_MEM(buff, buffLen);
	VFX_SYS_ALLOC_MEM(recipientName, buffLen);

    for (VfxU32 index = 0 ; index < cnt; index++)
    {
		//Check if MAX count is already reached, if so display the popup and return
		if (app->m_service_cntxt->msg->to_num >= app->vappUcGetMaxRecipientCount())
        {
           mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_RECIPIENT_NUMBER_EXCEED_ID)).getBuf());
			VFX_SYS_FREE_MEM(buff);
			VFX_SYS_FREE_MEM(recipientName);
            return;
        }
		//Get the data from the phonebook
		memset(buff, 0, buffLen);
		vcui_phb_list_get_selected_contact_data_by_index(app->main->cui_gid, buff , buffLen , index);

		if (vapp_uc_is_ascii_string((S8*) buff) && srv_uc_is_phone_number_valid((S8*)buff))
		{
			//Phone Number
			//this->done->state = MMI_UC_DONE_STATE_ADD_NUMBER;

			if (mmi_ucs2strlen((S8*)buff) > SRV_UC_MAX_PHONE_NUMBER_LEN)
			{
				invalid_address = MMI_TRUE;
				count++;
				continue;
			}
			addrType = SRV_UC_ADDRESS_TYPE_PHONE_NUMBER;
		}
		else if (srv_uc_is_email_addr_valid((U8*)buff))
		{
			//Email
			//this->done->state = MMI_UC_DONE_STATE_ADD_EMAIL;
			addrType = SRV_UC_ADDRESS_TYPE_EMAIL;
		}
		else
		{
			invalid_address = MMI_TRUE;
			count++;
			continue;
		}
#ifdef __MMI_EMAIL__  /*No need to check the msg size limitation in case of Email*/
    if (app->m_service_cntxt->msg_type->MMS_edit_mode != SRV_UC_MMS_EDIT_MODE_EMAIL)
#endif /*__MMI_EMAIL__*/
    {
#ifdef __MMI_MMS_2__

		if (app->m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
        {
            /* Check if the msg size exceeds the MMS limitation */
            VfxU32 addr_size = mma_uc_calc_header_attribute_size(MMA_HEADER_ADDRESS, (const kal_wchar*)buff);
            MMI_BOOL fail_in_restricted_size_check = MMI_FALSE;

            if (srv_uc_check_if_exceed_MMS_size_limitation
                (app->main->instance, addr_size + app->m_service_cntxt->msg->msg_size, &fail_in_restricted_size_check))
            {
                if (fail_in_restricted_size_check)
				{
					mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, 
							(WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_UC_RESTRICTED_MODE_MSG_SIZE_EXCEED_ID).getBuf());
					
				}
				else
				{
					mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, 
							(WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_UC_MSG_SIZE_EXCEED_ID).getBuf());
					
				}

				VFX_SYS_FREE_MEM(buff);
				VFX_SYS_FREE_MEM(recipientName);
                return;
            }
		}
#endif
	}
		result = srv_uc_add_address(
                 app->main->instance,
                 (U8*)buff,
                 addrType,
                 (srv_uc_address_group_type_enum)app->getContactInsertType());

		MMI_ASSERT(result);

		/*Now add the address in contact selector*/
		memset(recipientName, 0, buffLen);
		vcui_phb_list_get_selected_contact_name_by_index(app->main->cui_gid, recipientName, buffLen, index);
		if (mmi_ucs2strlen((CHAR*)recipientName) > 0)
		{
			this->composer_page->insertAddressItem(app->getContactInsertType(), recipientName, buff, addrType);
		}
		else
		{
			this->composer_page->insertAddressItem(app->getContactInsertType(), VFX_WSTR_EMPTY, buff, addrType);
		}

        app->send_info->change_in_recipient_list = TRUE;
       /* this->done->current_addr_index = this->m_service_cntxt->to_num + MMI_UC_ADD_RECIPIENT_TOTAL
               - mmi_uc_get_number_of_options_omitted() - 1;    */
       if (app->m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
        {
            app->m_service_cntxt->main->mode = SRV_UC_FORWARD_WITH_EDIT_MODE;
        }
		srv_uc_update_msg_size(app->main->instance);
	}
      
 
	if (invalid_address)
    {
		/*TODO: Rahul Currently there is only one string for invalid recipients
		Need to discuss with vikas to decide the correct string*/
        if (cnt == 1)
        {
            string_id = STR_ID_VAPP_UC_INVALID_RECIPIENT;
        }  
        else
        {
		#ifdef __MMI_EMAIL__
			if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
			{
					string_id = STR_ID_VAPP_UC_INVALID_ADDRESSES_REMOVED;
			}
			else
		#endif
			{
					string_id = STR_ID_VAPP_UC_INVALID_RECIPIENTS_REMOVED;
			}
		}
    }
  
    if (string_id)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, 
							(WCHAR*)VFX_WSTR_RES(string_id).getBuf());
    }
	
	VFX_SYS_FREE_MEM(buff);
	VFX_SYS_FREE_MEM(recipientName);
}

void VappUCMainScr::ucAddObjectFromAppSelectionProcess(U16 *filePath, S32 is_short)
{
   	VappUcAppData* app = (VappUcAppData*)(this->m_app_data);
#ifdef __MMI_EMAIL__
    if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL && filePath)
    {
        VFX_OBJ_CREATE(composer_page->m_popup,VcpIndicatorPopup,this);
        composer_page->m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
        composer_page->m_popup->setText(VFX_WSTR_RES(STR_ID_VAPP_UC_INSERTING));
        composer_page->m_popup->setAutoDestory(VFX_FALSE);
        composer_page->m_popup->show(VFX_TRUE);
    }
#endif
    app->m_signalConnectOnFileSelection.connect(this, &VappUCMainScr::connectOnFileSelection);
    app->ucAddObjectFromAppSelection(filePath, is_short);
}

mmi_ret VappUCMainScr::onProc(mmi_event_struct *evt)
{

   	VappUcAppData* app = (VappUcAppData*)(this->m_app_data);
	VfxBool isSuccess = VFX_FALSE;
	VfxBool need_set_active_vk = VFX_FALSE;

	switch (evt->evt_id)
	{
        case EVT_ID_CUI_VAPP_MEM_FREE_ASM:
            if (app->main->cui_gid != GRP_ID_INVALID)
            {
#ifdef __MMI_MMS_2__
                cui_vapp_mms_preview_mms_close(app->main->cui_gid);
#endif
		        app->m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
		        if (app->m_service_cntxt->send_info->new_msg_id)
		        {
			        app->ucClearMsgBearer(SRV_UC_MSG_TYPE_MMS_PREFER);
		        }
                app->main->cui_gid = GRP_ID_INVALID;
                app->main->cui_type = UC_CUI_NONE;
            }
            break;
	case EVT_ID_CUI_PHB_LIST_RESULT:
		if (app->main->cui_gid != GRP_ID_INVALID)
		{
			vcui_phb_list_result_event_struct *phBookEvt = (vcui_phb_list_result_event_struct*)evt;

			if (phBookEvt->result > 0)
			{
#if defined(__MMI_VCARD__)
				if (app->m_pbInsertState == UC_PB_CUI_STATE_INSERT_VCARD)
				{
					//Insert Vcard case
					VfxWChar *folderName = NULL;
					VfxWChar *recipienName = NULL;
					VfxU16 recipientNameLen = 0;
					VfxU16 folderNameLen = 0;
					VfxU16 count = 0;
                    VfxS32 phbError = 0;
                    VfxBool ext_added = VFX_FALSE;


					VFX_SYS_ALLOC_MEM(folderName, MMA_MAX_EXTERNAL_FILE_PATH_LEN);
					memset(folderName, 0x0, MMA_MAX_EXTERNAL_FILE_PATH_LEN);

					VFX_SYS_ALLOC_MEM(recipienName, (MMI_PHB_NAME_LENGTH + 10 + 2) * ENCODING_LENGTH);
					
					vcui_phb_list_get_selected_contact_name(app->main->cui_gid, recipienName, (MMI_PHB_NAME_LENGTH + 1) * ENCODING_LENGTH);
					recipientNameLen = mmi_ucs2strlen((CHAR*)recipienName);
                    mmi_ucs2cat((CHAR*)recipienName, (CHAR*)VFX_WSTR(".vcf").getBuf());
                    ext_added = VFX_TRUE;
					if(recipientNameLen == 0 || srv_fmgr_path_is_filename_valid(recipienName) == MMI_FALSE)
					{
					    memset(recipienName, 0x0, (MMI_PHB_NAME_LENGTH + 2) * ENCODING_LENGTH);
                        mmi_ucs2cat((CHAR*)recipienName, (PS8) GetString(STR_ID_VAPP_UC_UNNAMED));
                        ext_added = VFX_FALSE;
					}

					memset(folderName, 0x0, MMA_MAX_EXTERNAL_FILE_PATH_LEN);

					kal_wsprintf(
						(kal_uint16*) folderName,
						"%c:\\%s%03d\\",
						SRV_UC_FOLDER_DRV,
						SRV_UC_FOLDER_NAME,
						app->main->instance);

					recipientNameLen = mmi_ucs2strlen((CHAR*)recipienName);
					folderNameLen = mmi_ucs2strlen((CHAR*)folderName);

					if (folderNameLen + recipientNameLen + 10 > MMA_MAX_EXTERNAL_FILE_PATH_LEN)
					{
					  recipientNameLen =  MMA_MAX_EXTERNAL_FILE_PATH_LEN -	folderNameLen - 10;
					}
					
					mmi_ucs2ncat((CHAR*)folderName, (CHAR*)recipienName, recipientNameLen);
                    if(ext_added == VFX_FALSE)
                    {
					    mmi_ucs2cat((CHAR*)folderName, (CHAR*)VFX_WSTR(".vcf").getBuf());
                    }
					while (FS_GetAttributes((PU16) folderName) >= 0)
					{
						/*Path already exists*/
						VfxU8 offset = 0;
						count++;
						folderNameLen = mmi_ucs2strlen((CHAR*)folderName);
						offset = folderNameLen >= MMA_MAX_EXTERNAL_FILE_PATH_LEN ? 8 : 4;
						if (count > 1)
						{
							offset+= 3;
						}
						folderName[folderNameLen - offset] = '\0';
	
						kal_wsprintf(
						(kal_uint16*) folderName + (folderNameLen - offset) ,
						"(%d).vcf",
						count);
					}

                    phbError = srv_contact_build_vcard(folderName, vcui_phb_list_get_contact_id(app->main->cui_gid), MMI_FALSE, 0 /*VCARD_VERSION_2_1*/);
					if ( phbError == 0 /*VCARD_NO_ERROR*/)
					{
                          ucAddObjectFromAppSelectionProcess((PU16)folderName, 0);
						//app->ucSelectObjectFromFmToInsertWarningModeCheck((PU16)folderName, 0);
					   // this->connectOnPage();
						//need_set_active_vk = VFX_TRUE;
						//getComposerPage()->setTextBodyeditorActiveOnPage();
					}
                    else if(phbError < 0)
                    {
                        VfxU16 fs_error_string = 0;
                        fs_error_string = srv_fmgr_fs_error_get_string(phbError);
	                    mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
		                    (WCHAR*)VFX_WSTR_RES(fs_error_string).getBuf());
                    }
					else
					{
                        /* if greater then 0 it should be vcard_error_enum. Can add accordingly error later.*/
						mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_UC_FAILED_TO_ADD_ATTACHMENT_ID).getBuf());
					}
					VFX_SYS_FREE_MEM(folderName);
					VFX_SYS_FREE_MEM(recipienName);
				}
				else
#endif
				if (app->m_pbInsertState == UC_PB_CUI_STATE_INSERT_PHONE_NUM ||
					app->m_pbInsertState == UC_PB_CUI_STATE_INSERT_PHONE_NAME ||
					app->m_pbInsertState == UC_PB_CUI_STATE_INSERT_PHONE_NAME_AND_NUM)
				{
				   //Insert Number
					VfxWChar *buff = NULL;	
					VfxU16 buffLen = (((SRV_UC_MAX_EMAIL_LEN  > SRV_UC_MAX_PHONE_NUMBER_LEN) ? 
										SRV_UC_MAX_EMAIL_LEN : SRV_UC_MAX_PHONE_NUMBER_LEN) + 1 )* ENCODING_LENGTH;
					VfxU16 len1 = 0, len2 = 0;

					
					if ( app->m_pbInsertState == UC_PB_CUI_STATE_INSERT_PHONE_NUM)
					{
					  VFX_SYS_ALLOC_MEM(buff, buffLen);
					  vcui_phb_list_get_selected_contact_data_by_index(app->main->cui_gid, buff , buffLen , 0);
					}
					else if(app->m_pbInsertState == UC_PB_CUI_STATE_INSERT_PHONE_NAME)
					{
					   VFX_SYS_ALLOC_MEM(buff, buffLen);					
					   vcui_phb_list_get_selected_contact_name_by_index(app->main->cui_gid, buff, buffLen, 0);
					}
                    else
                    {
                       /* bufflen should be the total length of name and number and two blanks which will stand 4 bytes */ 
                       buffLen = buffLen*2+4;
                       VFX_SYS_ALLOC_MEM(buff, buffLen);
                       vcui_phb_list_get_selected_contact_name_by_index(app->main->cui_gid, buff, buffLen, 0);
                       len1 = vfx_sys_wcslen((const VfxWChar*)buff);
                       if(len1>0)
                       {
                           mmi_ucs2cat((CHAR*)buff, (CHAR*)VFX_WSTR(" ").getBuf()); 
                           len1 = vfx_sys_wcslen((const VfxWChar*)buff);
                       }
                       vcui_phb_list_get_selected_contact_data_by_index(app->main->cui_gid, buff + len1 , buffLen - len1 , 0);
                       len2 = vfx_sys_wcslen((const VfxWChar*)buff);
                       if(len2>len1)
                       {
                           mmi_ucs2cat((CHAR*)buff, (CHAR*)VFX_WSTR(" ").getBuf()); 
                       }
                    }

                    
					if (app->main->launch_mode == UC_LAUNCH_MODE_INSERT)
					{
						this->composer_page->insertTextString((VfxWChar*)buff, VFX_FALSE);
                        app->main->launch_mode = UC_LAUNCH_MODE_NONE;
					}
					else
					{
						this->composer_page->insertTextString((VfxWChar*)buff, VFX_FALSE);
					}
					need_set_active_vk = VFX_TRUE;
				    //getComposerPage()->setTextBodyeditorActiveOnPage();
					VFX_SYS_FREE_MEM(buff);				

				}
				else if (app->m_pbInsertState == UC_PB_CUI_STATE_INSERT_ADDRESS)
				{
					//select contact case
					VfxU8 contactInsertType =   app->getContactInsertType();
					if (contactInsertType == SRV_UC_ADDRESS_GROUP_TYPE_TO
					#ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__    
						|| contactInsertType == SRV_UC_ADDRESS_GROUP_TYPE_CC
						|| contactInsertType == SRV_UC_ADDRESS_GROUP_TYPE_BCC
					#endif	
						)
					{
						this->ucHandleAddressCallback(phBookEvt->select_count);
					}
					else
					{
						ASSERT(0); // Check Why control is coming here
					}
				}

			}
			vcui_phb_list_close(app->main->cui_gid);
            app->main->cui_gid = GRP_ID_INVALID;
            app->main->cui_type = UC_CUI_NONE;
			
		}

		 break;
#if (!defined(__LOW_COST_SUPPORT_COMMON__))	
		case VCUI_CAMCO_EVENT_RESULT_SUCCESS:
			{
				vcui_camco_event_struct *camCoEvt = (vcui_camco_event_struct*)evt;
			/*	if(app->g_settingLimitation)
				{
					VFX_SYS_FREE_MEM(app->g_settingLimitation);
					app->g_settingLimitation = NULL ;
				}*/
				if (camCoEvt->errCode == VCUI_CAMCO_ERR_NONE)
				{
					//assuming success case
                    ucAddObjectFromAppSelectionProcess((PU16)camCoEvt->filePath, 0);
					//app->ucSelectObjectFromFmToInsertWarningModeCheck((PU16)camCoEvt->filePath, 0);
					//this->connectOnPage();
					//need_set_active_vk = VFX_TRUE;
                   // getComposerPage()->setTextBodyeditorActiveOnPage();
				}
				else
				{
				    if(app->main->cui_type == UC_CUI_CAMERA)
				    {   
				        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
						(WCHAR*)VFX_WSTR_RES(vcui_standard_camera_get_err_string(camCoEvt->errCode)).getBuf());	
				    }
				    else if(app->main->cui_type == UC_CUI_CAMCORDER)
				    {
				        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
						(WCHAR*)VFX_WSTR_RES(vcui_standard_recorder_get_err_string(camCoEvt->errCode)).getBuf());					    
				    }
				}
                
                if(app->main->cui_type == UC_CUI_CAMERA)
                {
                    vcui_standard_camera_close(m_app_data->main->cui_gid);
                }
                else if(app->main->cui_type == UC_CUI_CAMCORDER)
                {
                    vcui_standard_recorder_close(m_app_data->main->cui_gid);
				   // vcui_camcorder_close(app->main->cui_gid);
                }
                app->main->cui_gid = GRP_ID_INVALID;
                app->main->cui_type = UC_CUI_NONE;
				isSuccess = VFX_TRUE;
			}
			break;
		case VCUI_CAMCO_EVENT_RESULT_FAILED:
			{
				vcui_camco_event_struct *camCoEvt = (vcui_camco_event_struct*)evt;
				if (camCoEvt->errCode != VCUI_CAMCO_ERR_NONE)
				{
				    if(app->main->cui_type == UC_CUI_CAMERA)
				    {   
				    mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
                                    (WCHAR*)VFX_WSTR_RES(vcui_standard_camera_get_err_string(camCoEvt->errCode)).getBuf());
				    }
				    else if(app->main->cui_type == UC_CUI_CAMCORDER)
				    {
				    mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
                                    (WCHAR*)VFX_WSTR_RES(vcui_standard_recorder_get_err_string(camCoEvt->errCode)).getBuf());
				    }
				}
                if(app->main->cui_type == UC_CUI_CAMERA)
                {
                    vcui_standard_camera_close(m_app_data->main->cui_gid);
                }
                else if(app->main->cui_type == UC_CUI_CAMCORDER)
                {
                    vcui_standard_recorder_close(m_app_data->main->cui_gid);
				   // vcui_camcorder_close(app->main->cui_gid);
                }
				//vcui_camcorder_close(app->main->cui_gid);
                app->main->cui_gid = GRP_ID_INVALID;
                app->main->cui_type = UC_CUI_NONE;
			}
			break;
#endif
        case EVT_ID_CLOSE_MMS_PREVIEW:
            if (app->main->cui_gid != GRP_ID_INVALID)
            {
#ifdef __MMI_MMS_2__
                cui_vapp_mms_preview_mms_close(app->main->cui_gid);
#endif
		        app->m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
		        if (app->m_service_cntxt->send_info->new_msg_id)
		        {
			        app->ucClearMsgBearer(SRV_UC_MSG_TYPE_MMS_PREFER);
		        }
                app->main->cui_gid = GRP_ID_INVALID;
                app->main->cui_type = UC_CUI_NONE;
            }
            break;

#ifdef __MMI_SOUNDREC_CUI__
		case EVT_ID_VCUI_SOUNDREC_RESULT:/*Event from Sound recorder*/
			{
				vcui_soundrec_evt_struct *soundRecEvt = (vcui_soundrec_evt_struct*)evt;
				if (soundRecEvt->result > 0)
				{
					/*Success Handling*/
                    ucAddObjectFromAppSelectionProcess((PU16)soundRecEvt->file_path, 0);
					//app->ucSelectObjectFromFmToInsertWarningModeCheck((PU16)soundRecEvt->file_path, 0);
					vcui_soundrec_close(app->main->cui_gid);
                    //this->connectOnPage();
					//need_set_active_vk = VFX_TRUE;
                   // getComposerPage()->setTextBodyeditorActiveOnPage();
					isSuccess = VFX_TRUE;
				}
                else if (soundRecEvt->result == 0)
				{
					/*Cancel Handling*/
                    ucAddObjectFromAppSelectionProcess(NULL, 0);
					//app->ucSelectObjectFromFmToInsertWarningModeCheck(NULL, 0);
					vcui_soundrec_close(app->main->cui_gid);

				}
                else 
				{
					/*Error handling*/
					vcui_soundrec_close(app->main->cui_gid);
				}
                app->main->cui_gid = GRP_ID_INVALID;
                app->main->cui_type = UC_CUI_NONE;
			}
			break;
#endif /* __MMI_SOUNDREC_CUI__ */

		case EVT_ID_VCUI_MUSIC_PLAYER_CLOSE:  /*Event from Music Player*/
			{
				vcui_music_player_close(app->main->cui_gid);
                app->main->cui_gid = GRP_ID_INVALID;
                app->main->cui_type = UC_CUI_NONE;
			}
            break;

		case EVT_ID_VCUI_GALLERY_CLOSE_GID: /*Event from Gallery*/
			{
				vcui_gallery_evt_struct *galleryEvt = (vcui_gallery_evt_struct*)evt;
				if (app->main->select_media_opt != UC_MEDIA_OPT_NONE)
				{
					if (galleryEvt->result == VCUI_GALLERY_RESULT_OK)
					{
						WCHAR* path_buffer  = NULL;
						U32 buff_size = (SRV_FMGR_PATH_MAX_LEN + 1 ) * sizeof(WCHAR);

						VFX_SYS_ALLOC_MEM(path_buffer, buff_size);
						vcui_gallery_picker_get_single_path(app->main->cui_gid, path_buffer, &buff_size);
						//app->m_signalConnectOnPage.connect(this, &VappUCMainScr::connectOnPage);
                        ucAddObjectFromAppSelectionProcess((PU16)path_buffer, 0);
						//app->ucSelectObjectFromFmToInsertWarningModeCheck((PU16)path_buffer, 0);				
						VFX_SYS_FREE_MEM(path_buffer);
						//this->connectOnPage();
                       // getComposerPage()->setTextBodyeditorActiveOnPage();
						isSuccess = VFX_TRUE;
					//	need_set_active_vk = VFX_TRUE;
					}
				}
				vcui_gallery_close(app->main->cui_gid);
                app->main->cui_gid = GRP_ID_INVALID;
                app->main->cui_type = UC_CUI_NONE;
			}
			break;
          
    #if defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__) && defined(BROWSER_SUPPORT)
		case EVT_ID_VCUI_BKM_SEL_BKM_RESULT:
			{
				vcui_bkm_sel_bkm_result_evt_struct *bookMarkEvt = (vcui_bkm_sel_bkm_result_evt_struct*)evt;
				if (bookMarkEvt->selected_utf8_url != NULL)
				{
					U32 buffer_count = (VCUI_BKM_MAX_URL_LEN < SRV_UC_MAX_CHAR_NUM_IN_ONE_SLIDE)? VCUI_BKM_MAX_URL_LEN: SRV_UC_MAX_CHAR_NUM_IN_ONE_SLIDE;
					U16 chars_num = mmi_chset_utf8_strlen((const kal_uint8*)((S8*) bookMarkEvt->selected_utf8_url));
					U8 *ucs2_buffer = NULL;//kal_adm_alloc(g_uc_p->main->mem_pool_id, (buffer_count << 1 + 1) * ENCODING_LENGTH);
						VFX_SYS_ALLOC_MEM(ucs2_buffer, ((buffer_count << 1) + 1) * ENCODING_LENGTH);
					memset(ucs2_buffer, 0x00, ((buffer_count << 1) + 1) * ENCODING_LENGTH);
					if ((strlen((const char*)bookMarkEvt->selected_utf8_url) != chars_num))
					{
						mmi_chset_utf8_to_ucs2_string(
							(kal_uint8*) ucs2_buffer,
							(kal_int32) ((buffer_count << 1) + 1),
							(kal_uint8*) bookMarkEvt->selected_utf8_url);
					}
					else
					{
						mmi_asc_n_to_ucs2((S8*) ucs2_buffer, (S8*) bookMarkEvt->selected_utf8_url, buffer_count);
					}
					chars_num = mmi_ucs2strlen((S8*) ucs2_buffer);
					if (app->main->launch_mode == UC_LAUNCH_MODE_INSERT)
					{
						this->composer_page->insertTextStringOneGo((VfxWChar*)ucs2_buffer, VFX_FALSE);
                        app->main->launch_mode = UC_LAUNCH_MODE_NONE;
					}
					else
					{
						this->composer_page->insertTextStringOneGo((VfxWChar*)ucs2_buffer, VFX_FALSE);
					}
					VFX_SYS_FREE_MEM(ucs2_buffer);
					need_set_active_vk = VFX_TRUE;
					//getComposerPage()->setTextBodyeditorActiveOnPage();
				}
				vcui_bkm_sel_bkm_close(app->main->cui_gid);
                app->main->cui_gid = GRP_ID_INVALID;
                app->main->cui_type = UC_CUI_NONE;
			}
			break;       
		case EVT_ID_VCUI_BKM_ADD_BKM_CLOSE:
			vcui_bkm_sel_bkm_close(app->main->cui_gid);
            app->main->cui_gid = GRP_ID_INVALID;
            app->main->cui_type = UC_CUI_NONE;
			break;
      #endif
      
#if defined(__MMI_VCALENDAR__)
		case EVT_ID_CUI_CAL_ITEM_SELECTED:
			{
				WCHAR* fileNamePtr = NULL;
				WCHAR* filePath = NULL;
				VfxU8 count = 0;
				vcui_cal_list_result_struct *calEvt = (vcui_cal_list_result_struct*)evt;
				BYTE *RecursiveStack = (BYTE*)OslMalloc (2048);

				fileNamePtr = srv_fmgr_path_get_filename_ptr(calEvt->path);

				VFX_SYS_ALLOC_MEM(filePath, (MMA_MAX_EXTERNAL_FILE_PATH_LEN + 1) * ENCODING_LENGTH);
				memset(filePath, 0x0, MMA_MAX_EXTERNAL_FILE_PATH_LEN);										
				kal_wsprintf(
						(kal_uint16*) filePath,
						"%c:\\%s%03d\\",
						SRV_UC_FOLDER_DRV,
						SRV_UC_FOLDER_NAME,
						app->main->instance);
				mmi_ucs2cat((CHAR*)filePath, (CHAR*)fileNamePtr);

				while (FS_GetAttributes((PU16) filePath) >= 0)
				{
					/*Path already exists*/
					VfxU8 offset = 0;
					VfxU8 pathLen = mmi_ucs2strlen((CHAR*)filePath);
					count++;					
					offset = pathLen >= MMA_MAX_EXTERNAL_FILE_PATH_LEN ? 8 : 4;
					if (count > 1)
					{
						offset+= 3;
					}
					filePath[pathLen - offset] = '\0';

					kal_wsprintf(
					(kal_uint16*) filePath + (pathLen - offset) ,
					"(%d).vcs",
					count);
				}

				if (FS_Move(calEvt->path, (U16*) filePath, FS_MOVE_KILL | FS_MOVE_OVERWRITE, NULL, RecursiveStack, 2048) < 0)
				{
					OslMfree(RecursiveStack);
					//Move Failed display the error.
					mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_UC_FAILED_TO_ADD_ATTACHMENT_ID).getBuf());
				}
				else
				{
					OslMfree(RecursiveStack);
                    ucAddObjectFromAppSelectionProcess((PU16)filePath, 0);
					//app->ucSelectObjectFromFmToInsertWarningModeCheck((PU16)filePath, 0);
					VFX_SYS_FREE_MEM(filePath);
					//this->connectOnPage();
					//need_set_active_vk = VFX_TRUE;
					//getComposerPage()->setTextBodyeditorActiveOnPage();
					isSuccess = VFX_TRUE;
				}
				vcui_cal_list_close(app->main->cui_gid);
                app->main->cui_gid = GRP_ID_INVALID;
                app->main->cui_type = UC_CUI_NONE;

			}
			break;
#endif /* __MMI_VCALENDAR__ */


		case EVT_ID_VCUI_FILE_SELECTOR_RESULT: /*evrnt from file manager*/
			vcui_file_selector_result_event_struct *fmgrEvt = (vcui_file_selector_result_event_struct*)evt;

			if (fmgrEvt->result > 0)
			{
				srv_fmgr_fileinfo_struct info = {0,};
				WCHAR* path_buffer  = NULL;
				U32 buff_size = (SRV_FMGR_PATH_MAX_LEN + 1 ) * sizeof(WCHAR);

				VFX_SYS_ALLOC_MEM(path_buffer, (SRV_FMGR_PATH_MAX_LEN + 1 ) * sizeof(WCHAR));
				vcui_file_selector_get_selected_filepath(app->main->cui_gid, &info, path_buffer, buff_size);
                ucAddObjectFromAppSelectionProcess((PU16)path_buffer, 0);
				//app->ucSelectObjectFromFmToInsertWarningModeCheck((PU16)path_buffer, 0);
				vcui_file_selector_close(app->main->cui_gid);
				VFX_SYS_FREE_MEM(path_buffer);
				//this->connectOnPage();
				//getComposerPage()->setTextBodyeditorActiveOnPage();
			//	need_set_active_vk = VFX_TRUE;
				isSuccess = VFX_TRUE;
			}
            else  if (fmgrEvt->result == 0)
			{
				vcui_file_selector_close(app->main->cui_gid);
			}
            else
			{
				vcui_file_selector_close(app->main->cui_gid);

			}
            app->main->cui_gid = GRP_ID_INVALID;
            app->main->cui_type = UC_CUI_NONE;

			break;
	}

	if (isSuccess == VFX_TRUE)
	{
		
		if (app->main->launch_mode == UC_LAUNCH_MODE_INSERT)
		{
	//		this->composer_page->insertTextString(NULL, VFX_TRUE);
			if(mmi_ucs2strlen((S8*)app->m_service_cntxt->main->text_buffer) > 0 )
			{
				getComposerPage()->setTextBodyeditorActiveOnPage();
			}
            app->main->launch_mode = UC_LAUNCH_MODE_NONE;
		}
	}
	if(need_set_active_vk)
	{
		getComposerPage()->setTextBodyeditorActiveOnPage();
	}
	

    return VfxMainScr::onProc(evt);
}

void VappComposerMainPage::setForceDataToRender(void)
{
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);

	srv_uc_addr_struct *temp_add = app->m_service_cntxt->msg->to_head;
	while (temp_add)
    {
    #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__
        if (temp_add->group == SRV_UC_ADDRESS_GROUP_TYPE_CC)
        {
            app->main->m_itemForceOn |=  ID_RECIPIENT_CC;
        }
        else if (temp_add->group == SRV_UC_ADDRESS_GROUP_TYPE_BCC)
        {
            app->main->m_itemForceOn |=  ID_RECIPIENT_BCC;
        }
    #endif    
        temp_add = temp_add->next;
    }	
#ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__    
	if((app->main->m_itemForceOn & UC_RECIPIENT_CC) == UC_RECIPIENT_CC)
	{
		m_itemForceOn |=  ID_RECIPIENT_CC;	
	}
	if((app->main->m_itemForceOn & UC_RECIPIENT_BCC) == UC_RECIPIENT_BCC)
	{
		m_itemForceOn |=  ID_RECIPIENT_BCC;	
	}
#endif
	if((app->main->m_itemForceOn & UC_SUBJECT) == UC_SUBJECT || (mmi_ucs2strlen((S8*) app->m_service_cntxt->msg->subject) >0))
	{
		m_itemForceOn |=  ID_SUBJECT;
		app->main->m_itemForceOn |= UC_SUBJECT;		
	}
}
void VappComposerMainPage::drawWithData()
{
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
	
	app->main->busy_getting_data = 0;
    if(m_popup)
    {
        if (m_popup->isValid())
		{
            VFX_OBJ_CLOSE(m_popup);
		}
        m_popup = NULL;
    }
    if(m_loading)
    {
        if (m_loading->isValid())
		{
			m_loading->stop();
		}
        m_loading = NULL;
    }

	if(app->m_service_cntxt->msg_type->MMS_edit_mode != SRV_UC_MMS_EDIT_MODE_LEMEI_MMS)
	{
		setForceDataToRender();
	}

    if( scr->m_isScreenEntered == VFX_TRUE )
    {
    // create input box
	    insertContactSelector();
    #ifdef __MMI_EMAIL__
        if (app->m_service_cntxt->msg_type->MMS_edit_mode != SRV_UC_MMS_EDIT_MODE_EMAIL)
    #endif
        {
	        updateBottomMsgHint();
        }
	    insertTextBodyEditor();
	    insertAttachment();
    #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__    
	    insertContactSelectorCc();
	    insertContactSelectorBcc();
    #endif    
	    insertSubjectItem();
    #ifdef __MMI_EMAIL__
        if (app->m_service_cntxt->msg_type->MMS_edit_mode != SRV_UC_MMS_EDIT_MODE_EMAIL)
    #endif
        {
	        insertSlideBarItem();
	        insertMediaItem();
        }
    }

	    // create tool bar
        updateButtonBar();
        resetAllFunctionBar();
       if(!(
    #ifdef __MMI_MESSAGES_TEMPLATE__    
           (app->operation_type == UC_OPERATION_WRITE_NEW_SMS_TEMPLATE) 
        || (app->operation_type == UC_OPERATION_EDIT_SMS_TEMPLATE)
    #else
        VFX_FALSE // to avoid grammer error 
    #endif
    #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
        || (app->operation_type == UC_OPERATION_WRITE_NEW_MMS_TEMPLATE) 
        || (app->operation_type == UC_OPERATION_EDIT_MMS_TEMPLATE)
    #endif    
    #ifdef __MMI_EMAIL__
        || (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
    #endif
		))
        {
			/*kuldeep_gplus*/
		    U16 text_buffer[50] = {0,};
            VfxWString itemText;
			if(app->main->msg_operation == UC_OPERATION_EDIT_EXISTED_MSG)
			{
				if(app->m_service_cntxt->msg->to_head && app->m_service_cntxt->msg->to_head->type == SRV_UC_ADDRESS_TYPE_PHONE_NUMBER)
				{
					mmi_sim_enum sim_id = MMI_SIM_NONE;
					U32 size = ((mmi_chset_utf8_strlen(app->m_service_cntxt->msg->to_head->addr))+1)*ENCODING_LENGTH;
					U16* temp_addr = (U16*)OslMalloc(size);
					memset(temp_addr, 0x0 ,size);
					mmi_chset_utf8_to_ucs2_string((kal_uint8 *)temp_addr,(kal_int32)size,(kal_uint8 *)app->m_service_cntxt->msg->to_head->addr);
					
					srv_phb_get_preferred_sim( (U16 *)temp_addr,
					MMI_PHB_INVALID_CONTACT_ID,
					SRV_PHB_NUMBER_OP_TYPE_MESSAGE,
					&sim_id);

					OslMfree(temp_addr);
					if(sim_id > MMI_SIM_NONE && sim_id < MMI_SIM_END_OF_ENUM && 
					(app->main->launch_mode == UC_LAUNCH_MODE_NONE))
					{
						app->taken_pref_phb_sim = VFX_TRUE ;
						if(vappUcGetValidSimInfo() & vappUcConvertMmiSimIdToUc(sim_id))
						{
							app->m_service_cntxt->send_info->send_sim_id = vappUcConvertMmiSimIdToUc(sim_id);
						}
					}
				}
			}
            app->ucGetComposerTitleString(text_buffer);
            composerTitleBar->setTitle(itemText.loadFromMem((VfxWChar*)text_buffer));
        }
}

void VappComposerMainPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
    // do nothing
}
void VappComposerMainPage::restoreControls()
{
	VfxU32 item = 0;
	if (m_BackUpitemsAlraedyDraw)
	{
		composer_form->removeItem(ID_CONTACT_SELECTOR_LIST_MENU);
		//VFX_OBJ_CLOSE(m_contactlist);
		m_contactlist = NULL;

		this->hideUnhideControls(m_BackUpitemsAlraedyDraw , VFX_FALSE);
		{
			if ((m_itemsAlraedyDraw & ID_RECIPIENT_TO) && m_contactSelectorTo)
			{
				item = ID_RECIPIENT_TO;

			}
        #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__    
			else if ((m_itemsAlraedyDraw & ID_RECIPIENT_CC) && m_contactSelectorCc)
			{
				
				item = ID_RECIPIENT_CC;
			}
			else if ((m_itemsAlraedyDraw & ID_RECIPIENT_BCC) && m_contactSelectorBcc)
			{
				
				item = ID_RECIPIENT_BCC;
			}
        #endif    
		}
		m_itemsAlraedyDraw = m_BackUpitemsAlraedyDraw;
	/*reset Backup*/
		m_BackUpitemsAlraedyDraw = 0;
		composer_form->scrollItemToView(item, VCPFORM_SCROLL_BOTTOM);
	}

}
void VappComposerMainPage::onTapItem(VcpListMenu *listMenu, VfxU32 itemIndex)
{
	VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
	VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
	VfxWChar *buff = NULL;
	VcpContactSelector *focusedItem = NULL;
	VappContactEmail Email;
	VappContactNumber num;

	srv_uc_address_type_enum addrType = SRV_UC_ADDRESS_TYPE_TOTAL_NUM;
	ContactList* contactList = this->m_contactlist->getContactList();

		switch (app->getContactInsertType())
		{
			case SRV_UC_ADDRESS_GROUP_TYPE_TO:
				focusedItem = m_contactSelectorTo;
			break;
        #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__
			case SRV_UC_ADDRESS_GROUP_TYPE_CC:
				focusedItem = m_contactSelectorCc;
			break;

			case SRV_UC_ADDRESS_GROUP_TYPE_BCC:
				focusedItem = m_contactSelectorBcc;
			break;
        #endif
			default:
				break;
		}

#ifdef __MMI_EMAIL__
	if (this->m_contactlist->getContactListType() == VappUcContactList::ENUM_VAPP_UC_CONTACTLIST_TYPE_EMAIL)
	{
		VcpTextEditor* r_editor = focusedItem->getInputbox();
		VfxWChar *txtBuff =  r_editor->getText();
		VfxWChar* startPos = (VfxWChar*)mmi_ucs2str((CHAR*)txtBuff, (CHAR*)"@");

		if (startPos != NULL)
		{
			WCHAR address[200];
			VfxWChar *tempTxtBuff = NULL;
			VfxWString itemText;
			VfxWString domaintext;
			VfxS32 offset = startPos - txtBuff;		
				
			VappEmailComp::queryRecentContact(itemIndex , address, startPos + 1);			
			
			VFX_SYS_ALLOC_MEM(tempTxtBuff, (offset + 2) * ENCODING_LENGTH);
			mmi_ucs2ncpy((CHAR*)tempTxtBuff,(CHAR*)txtBuff, offset + 1);


			domaintext.loadFromMem(address);
			itemText.loadFromMem(tempTxtBuff);
			itemText += domaintext;
	        if (itemText.getLength() > SRV_UC_MAX_EMAIL_LEN)
			{
				mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_ADDR_LENGTH_EXCEED_ID)).getBuf());
				VFX_SYS_FREE_MEM(tempTxtBuff);
				return;
			}
		    if(!srv_uc_is_email_addr_valid((U8*)itemText.getBuf()))
		    {
			    mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_GLOBAL_INVALID_RECIPIENTS)).getBuf());
			    return;
		    }
			focusedItem->add(VFX_WSTR_EMPTY, VFX_WSTR_EMPTY, itemText);

    #ifdef __MMI_EMAIL__
		    if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
		    {
			    VappEmailComp::addRecentContact((WCHAR*) itemText.getBuf());
		    }
    #endif							 
		    r_editor->deleteAll();
			r_editor->setEnterKeyEnabled(VFX_FALSE);
            VFX_SYS_FREE_MEM(tempTxtBuff);
		}
	}
	else
#endif
	{
	    ContactEntry entry(contactList->getId(itemIndex));
        VfxU32 type = contactList->getType(itemIndex);
        VfxU32 subId = contactList->getSubId(itemIndex);
        switch(type)
        {
		    case MMI_PHB_CONTACT_FIELD_ID_NUMBER:
			{
			    num = entry.getNumberById(subId);
			    buff = num.getBuf();
			    addrType =	SRV_UC_ADDRESS_TYPE_PHONE_NUMBER;
			    if(!vapp_uc_is_ascii_string((S8*) buff) && srv_uc_is_phone_number_valid((PS8)buff))
			    {
				    mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_INVALID_RECIPIENT)).getBuf());
				    return;
			    }
				else if(mmi_ucs2strlen((S8*)buff) > SRV_UC_MAX_PHONE_NUMBER_LEN)
				{
					mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_NUMBER_LENGTH_EXCEED_ID)).getBuf());
				    return;					
				}
			    break;
		    }
		    case MMI_PHB_CONTACT_FIELD_ID_EMAIL:
            {
			    Email = entry.getEmailById(subId);
		        buff = Email.getBuf();
			    addrType =	SRV_UC_ADDRESS_TYPE_EMAIL;
			    if(!srv_uc_is_email_addr_valid((U8*)buff))
			    {
				    mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_INVALID_RECIPIENT)).getBuf());
				    return;
			    }
				else if(mmi_ucs2strlen((S8*)buff) > SRV_UC_MAX_EMAIL_LEN)
				{
					mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_ADDR_LENGTH_EXCEED_ID)).getBuf());
					return;

				}
			    break;
             }
	    }
        VappContactName contactName = entry.getName();
        if (mmi_ucs2strlen((CHAR*)contactName.getString().getBuf()) > 0)
        {
            this->insertAddressItem(app->getContactInsertType(), contactName.getString().getBuf(), buff, addrType);
        }
        else
        {
            this->insertAddressItem(app->getContactInsertType(), VFX_WSTR_EMPTY, buff, addrType);
        }
      }
	 if (focusedItem)
	 {
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
		{
			focusedItem->getInputbox()->setAutoActivated(VFX_TRUE);
			highlightedEditor = focusedItem->getInputbox();
		}
		focusedItem->hideContact(VFX_FALSE);
	 }
	this->restoreControls();
}

void VappComposerMainPage::onFirstEnterSetDefaultActive()
{
	 if (m_contactSelectorTo)
	 {
		if(m_contactSelectorTo->getContactCount() >0)
		{
			if(textEditorBody)
			{
			//	textEditorBody->activate();
				textEditorBody->setAutoActivated(VFX_TRUE);
				highlightedEditor = textEditorBody;
			}
		}
		else
		{
			//m_contactSelectorTo->getInputbox()->activate();
			m_contactSelectorTo->getInputbox()->setAutoActivated(VFX_TRUE);
			highlightedEditor = m_contactSelectorTo->getInputbox();
		}
	 }
     else if(textEditorBody)
     {
        textEditorBody->setAutoActivated(VFX_TRUE);
		highlightedEditor = textEditorBody;
     }
}

VfxBool VappComposerMainPage::onKeyInput(VfxKeyEvent& event)
{
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
	if(app->main->busy_getting_data == 1)
	{
		return VFX_TRUE;
	}
	return VfxPage::onKeyInput(event);
}

void VappComposerMainPage::onInit()
{
    VfxPage::onInit();
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
	
	VfxXmlLoader::loadBegin(this, VENUS_COMPOSER_MAIN_PAGE);

	composer_form = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("composer_form")), VcpForm);
    // call base class
    // create title bar
	composer_form->setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));  //Because Form now has set the background color as grey
	composerTitleBar =	VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("composerTitleBar")), VcpTitleBar);
	composerTitleBar->setTitleStyle(VCP_TITLE_BAR_STYLE_BASE);   //Currently this is not supported in XML
	//composerTitleBar->testSetTranslucent(VFX_TRUE);
	composer_form->setSize(getSize().width, getSize().height);
    
        VfxXmlLoader::loadEnd();

  #if defined(__MMI_MESSAGES_TEMPLATE__) || defined(__MMI_MMS_TEMPLATE_SUPPORT__)
    if((app->operation_type == UC_OPERATION_WRITE_NEW_SMS_TEMPLATE) || 
        (app->operation_type == UC_OPERATION_EDIT_SMS_TEMPLATE) ||
        (app->operation_type == UC_OPERATION_WRITE_NEW_MMS_TEMPLATE) ||
        (app->operation_type == UC_OPERATION_EDIT_MMS_TEMPLATE))
    {
        /* Update the title text to "New Template" */ 
        composerTitleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_UC_NEW_TEMPLATE_ID));
    }
  #else
    if(VFX_FALSE){} // to avoid if-else mis-match
  #endif
  #ifdef __MMI_EMAIL__
    else if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
    {
       VfxWString text1, text2;
//	   VfxS32 remain_width = 0;
       VappEmailComp::queryTitle(text1, text2, app->main->callback_para);
       //text1 += text2;
       composerTitleBar->setTitle(text2);
	   //composerTitleBar->setTitle(text1);	// set title text
#if 0
/* under construction !*/
/* under construction !*/
#endif
        m_itemForceOn |= ID_SUBJECT;
        app->main->m_itemForceOn |= UC_SUBJECT;
		composerTitleBar->setSize( getSize().width, composerTitleBar->getSize().height);
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
#endif
    }
  #endif
    else
    {
        U16 text_buffer[50] = {0,};
        VfxWString itemText;
		/*kuldeep_gplus*/
		if(!(app->operation_type == UC_OPERATION_REPLY ||app->operation_type == UC_OPERATION_REPLY_BY_SMS ||
			app->operation_type == UC_OPERATION_REPLY_BY_MMS ||app->operation_type == UC_OPERATION_REPLY_ALL )
			&& !(app->main->msg_operation == UC_OPERATION_REPLY ||app->main->msg_operation == UC_OPERATION_REPLY_BY_SMS ||
			app->main->msg_operation == UC_OPERATION_REPLY_BY_MMS ||app->main->msg_operation == UC_OPERATION_REPLY_ALL )
			&& (app->main->launch_mode == UC_LAUNCH_MODE_NONE) && !(app->taken_pref_phb_sim))
		{
			VcuiUcMainCui*  ucApp = (VcuiUcMainCui*)app->m_parent;
			if((app->nvram_sim_id & vappUcGetValidSimInfo()) && !(ucApp->m_isInRestore))
			{
				app->m_service_cntxt->send_info->send_sim_id = app->nvram_sim_id ;
			}
		}
		/*On init show Title with SIM only when Actual SIM known*/
		if(app->main->msg_operation == UC_OPERATION_WRITE_NEW_MSG &&  /*SMS edit/reply/forward handle but not for MMS*/
		!(app->operation_type == UC_OPERATION_REPLY ||app->operation_type == UC_OPERATION_REPLY_ALL 
		||app->operation_type ==  UC_OPERATION_FORWARD ||app->operation_type == UC_OPERATION_EDIT_EXISTED_MSG))
		{
			app->ucGetComposerTitleString(text_buffer);
			composerTitleBar->setTitle(itemText.loadFromMem((VfxWChar*)text_buffer));
		}
		else
		{
			composerTitleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_UC_WRITE_MSG_ID));	// set title text
		}
    }
/*    VfxImageFrame *titleIcon;
    titleIcon = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("titleIcon")), VfxImageFrame);    
    titleIcon->setPos(composer_form->getSize().width - VCPFRM_ITEM_HORZ_GAP - VAPP_UC_STANDARD_BTN_HEIGHT, 0);
    titleIcon->setSize(20, 20);*/
	/*
    titleIcon->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                VFX_FRAME_ALIGNER_MODE_SIDE,
                                VFX_FRAME_ALIGNER_MODE_SIDE,
                                VFX_FRAME_ALIGNER_MODE_SIDE);
								*/

    setTopBar(composerTitleBar);	// set as top bar of current page
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    app->m_signalPopup.connect(getMainScr(), &VappUCMainScr::displayPopup);
    app->m_signalRefreshPage.connect(getMainScr(), &VappUCMainScr::refreshPageOnSdPlugOut);
    if(app->main->busy_getting_data)
    {
        VFX_OBJ_CREATE(m_loading, VcpActivityIndicator, this);
        m_loading->setHiddenWhenStopped(VFX_TRUE);
		m_loading->setPos(getSize().width/2 - m_loading->getSize().width/2, getSize().height/2 - m_loading->getSize().height/2);
		m_loading->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_MID, 
                        VFX_FRAME_ALIGNER_MODE_MID, 
                        VFX_FRAME_ALIGNER_MODE_MID, 
                        VFX_FRAME_ALIGNER_MODE_MID);

        m_loading->start();

  /*      VFX_OBJ_CREATE(m_popup,VcpIndicatorPopup,this);
        m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
        m_popup->setText(VFX_WSTR_RES(STR_GLOBAL_PLEASE_WAIT));
        m_popup->setAutoDestory(VFX_FALSE);
        m_popup->show(VFX_TRUE);*/
        app->m_signalConnectOnError.connect(getMainScr(), &VappUCMainScr::connectToClose);
        app->m_signalConnectOnPage.connect(getMainScr(), &VappUCMainScr::connectOnPage);
    }
    else if(app->main->confirm_handler)
    {
        app->m_signalConnectOnError.connect(getMainScr(), &VappUCMainScr::connectToClose);
        app->m_signalConnectOnPage.connect(scr, &VappUCMainScr::connectOnPage);
    }

    if( app->m_useSecondStage == VFX_FALSE)
        updateView(VFX_FALSE);
            
//W1203_UI_PERFORMANCE_BEGIN
    // create tool bar
    m_itemForceOn = app->main->m_itemForceOn;
    updateButtonBar();

    mmi_frm_cb_reg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, &VappComposerMainPage::onSimSrvEvtCb, getObjHandle());

}

void VappComposerMainPage:: onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, &VappComposerMainPage::onSimSrvEvtCb, getObjHandle());
    VfxPage::onDeinit();
}

mmi_ret VappComposerMainPage::onSimSrvEvtCb(mmi_event_struct * param)
{
    VappComposerMainPage *self = (VappComposerMainPage *)VfxObject::handleToObject((VfxObjHandle)param->user_data);

    if (self)
    {
        if (self->isKindOf(VFX_OBJ_CLASS_INFO(VappComposerMainPage)))
        {
            VappUCMainScr* scr = (VappUCMainScr*)(self->getMainScr());
            VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);    
            switch (param->evt_id)
            {
                case EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY:
                    if(app->main->busy_getting_data == 0)
                    {
                        if( app->main->cui_gid == GRP_ID_INVALID )
                            self->drawWithData();
                        else
                            self->isNeedUpdate = VFX_TRUE;
                    }
                    break;

                default:
                    break;
            }
        }
    }

    return MMI_RET_OK;
}

void VappComposerMainPage::updateView(VfxBool isSetAutoActivated)
{
	VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
	VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);

    if ((!app->main->busy_getting_data) && (!app->main->confirm_handler))
    {
  #ifdef __MMI_EMAIL__
		/* We can put it seperate also but need flag to set rest so checked here. */
    if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
    {
    #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__    
		if( VappEmailComp::queryShowCcBcc(app->main->callback_para))
		{
			m_itemForceOn |= ID_RECIPIENT_BCC;
			app->main->m_itemForceOn |= UC_RECIPIENT_BCC;
			m_itemForceOn |= ID_RECIPIENT_CC;
			app->main->m_itemForceOn |= UC_RECIPIENT_CC;
		}
    #endif    
	}
#endif
		if(app->m_service_cntxt->msg_type->MMS_edit_mode != SRV_UC_MMS_EDIT_MODE_LEMEI_MMS)
		{
			setForceDataToRender();
		}
    // create input box
	    insertContactSelector();
    #ifdef __MMI_EMAIL__
        if (app->m_service_cntxt->msg_type->MMS_edit_mode != SRV_UC_MMS_EDIT_MODE_EMAIL)
    #endif
	        updateBottomMsgHint();
	    insertTextBodyEditor();
	    insertAttachment();
    #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__    
	    insertContactSelectorCc();
	    insertContactSelectorBcc();
    #endif    
	    insertSubjectItem();
    #ifdef __MMI_EMAIL__
        if (app->m_service_cntxt->msg_type->MMS_edit_mode != SRV_UC_MMS_EDIT_MODE_EMAIL)
    #endif
        {
	        insertSlideBarItem();
	        insertMediaItem();
        }
	    // create tool bar
        //updateButtonBar();
//W1203_UI_PERFORMANCE_END
		resetAllFunctionBar();
    }

    if(isSetAutoActivated)
    {
	    setAutoActivated(); 
    }
}

void VappComposerMainPage::setAutoActivated()
{
    if (m_contactSelectorTo)
    {
       if(m_contactSelectorTo->getContactCount() >0)
       {
           if(textEditorBody)
           {
           //  textEditorBody->activate();
               textEditorBody->setAutoActivated(VFX_TRUE);
               highlightedEditor = textEditorBody;
           }
       }
       else
       {
           //m_contactSelectorTo->getInputbox()->activate();
           m_contactSelectorTo->getInputbox()->setAutoActivated(VFX_TRUE);
           highlightedEditor = m_contactSelectorTo->getInputbox();
       }
    }
    else if(textEditorBody)
    {
       textEditorBody->setAutoActivated(VFX_TRUE);
       highlightedEditor = textEditorBody;
    }
}

void VappComposerMainPage::setEditorActivated()
{
    if (m_contactSelectorTo)
    {
       if(m_contactSelectorTo->getContactCount() >0)
       {
           if(textEditorBody)
           {
               textEditorBody->activate();
               //textEditorBody->setAutoActivated(VFX_TRUE);
               highlightedEditor = textEditorBody;
           }
       }
       else
       {
           m_contactSelectorTo->getInputbox()->activate();
           //m_contactSelectorTo->getInputbox()->setAutoActivated(VFX_TRUE);
           highlightedEditor = m_contactSelectorTo->getInputbox();
       }
    }
    else if(textEditorBody)
    {
        textEditorBody->activate();
       //textEditorBody->setAutoActivated(VFX_TRUE);
       highlightedEditor = textEditorBody;
    }
}


VcpButton* VappUCSlideBarItem::getOptionButton(void)
{
	return btn2;
}
VcpButton* VappUCSlideBarItem::getLeftArrowButton(void)
{
	return btn;
}
VcpButton* VappUCSlideBarItem::getRightArrowButton(void)
{
	return btn1;
}

void VappComposerMainPage::onSlideBarOptionClick(VfxObject* obj, VfxId id)
{
#ifdef __MMI_MMS_2__
    VFX_OBJ_CREATE(m_commandPopup, VcpCommandPopup, findScreen());
    m_commandPopup->setText(VFX_WSTR_RES(STR_GLOBAL_OPTIONS));

    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
	if (app->m_service_cntxt->msg->msg_body.slide_no > 1)
	{
		m_commandPopup->addItem(ID_COMMAND_REMOVE_SLIDE, VFX_WSTR_RES(STR_ID_VAPP_UC_REMOVE_SLIDE_ID));
	}
	if(app->m_service_cntxt->msg->msg_body.slide_no < SRV_UC_MAX_MMS_SLIDE_NUM)
	{
		m_commandPopup->addItem(ID_COMMAND_ADD_SLIDE, VFX_WSTR_RES(STR_ID_VAPP_UC_ADD_SLIDE_ID));
	}
    m_commandPopup->addItem(0xFFFF, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
    
   // m_commandPopup->m_signalButtonClicked.connect(this, &VappUCSlideBarItem::onSlideBarOptionMenuClick);
    m_commandPopup->m_signalButtonClicked.connect(this, &VappComposerMainPage::onToolBarClick); 
    m_commandPopup->setAutoDestory(VFX_TRUE);
    m_commandPopup->show(VFX_TRUE);
#endif
}
void VappComposerMainPage::onSlideBarLeftArrowClick(VfxObject* obj, VfxId id)
{
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
    app->ucEntryPreviousSlide();
    removeObjectFromPage(ID_INLINE_SLIDE_BAR);

    m_isBlockDeactivateEditor = VFX_TRUE;
    drawWithData();
    m_isBlockDeactivateEditor = VFX_FALSE;

    if(highlightedEditor && (highlightedEditor == textEditorBody))
    {
         textEditorBody->setCursorIndex(0);
    }
}
void VappComposerMainPage::onSlideBarRightArrowClick(VfxObject* obj, VfxId id)
{
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
    app->ucEntryNextSlide();

    removeObjectFromPage(ID_INLINE_SLIDE_BAR);

    m_isBlockDeactivateEditor = VFX_TRUE;  
    drawWithData();
    m_isBlockDeactivateEditor = VFX_FALSE; 

    if(highlightedEditor && (highlightedEditor == textEditorBody))
    {
        textEditorBody->setCursorIndex(0);
    }   
}
void VappUCSlideBarItem::onSlideBarOptionMenuClick(VfxObject* obj, VfxId id)
{
    switch(id)
    {
		case VappUCSlideBarItem::ID_COMMAND_ADD_SLIDE:
			//mmi_uc_entry_insert_slide();
			//removeObjectFromPage(ID_INLINE_SLIDE_BAR);
			//insertSlideBarItem();
			break;

		case VappUCSlideBarItem::ID_COMMAND_REMOVE_SLIDE:
			//mmi_uc_entry_delete_slide();
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
#endif
			break;

		default:
			break;

	}		

}

void VappComposerMainPage::onSubjectEnterKeyClicked(VcpTextEditor *editor, IMEVKEnterKeyStyleEnum enterKeyStyle)
{
	if(textEditorBody)
     {
        textEditorBody->activate();//setAutoActivated(VFX_TRUE);
		highlightedEditor = textEditorBody;
     }
}


void VappComposerMainPage::onSubjectCharInput(VfxWChar *text, VfxS32 curPos, VcpTextChangeEnum type, VfxBool *ret)
{
    if (type == VCP_TEXT_CHANGE_INSERT_CHAR)
    {
#ifdef __MMI_MMS_2__
		U32 size = 0;
        VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
        VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
		
		#ifdef __MMI_EMAIL__
		if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
		{
			*ret = VFX_TRUE;
			return;
		}
		#endif

		size = mma_uc_calc_header_attribute_size(MMA_HEADER_SUBJECT, (kal_wchar*) text);
//		mmi_ucs2strlen((S8*) app->m_service_cntxt->msg->subject)
		if(size + app->m_service_cntxt->msg->msg_size > app->m_service_cntxt->mms_info->max_mms_size)
		{
			*ret = VFX_FALSE;
		}
		else
#endif
		{
			*ret = VFX_TRUE;		
		}
    }
}

void VappComposerMainPage::onSubjectTextChanged(VcpTextEditor *editor)
{
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
  //  srv_uc_set_subject( app->main->instance,(S8*)textEditorBody->getText());
  if (app->m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
  {
      app->m_service_cntxt->main->mode = SRV_UC_FORWARD_WITH_EDIT_MODE;
  }

    srv_uc_update_msg_size(app->main->instance);
    updateBottomMsgHint();
}

void VappComposerMainPage::onCharInput(VfxWChar *text, VfxS32 curPos, VcpTextChangeEnum type, VfxBool *ret)
{
	VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
	VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
#ifdef __MMI_EMAIL__
	if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
	{
		*ret = VFX_TRUE;
        return;
	}
#endif

#ifdef __MMI_MESSAGES_TEMPLATE__
	if(app->operation_type == UC_OPERATION_WRITE_NEW_SMS_TEMPLATE ||
		app->operation_type == UC_OPERATION_EDIT_SMS_TEMPLATE)
	{
			*ret = VFX_TRUE;
			return;
	}
#endif    
    if (type == VCP_TEXT_CHANGE_INSERT_CHAR)
    {
	    VappUcTextInfoStruct new_text_info = {0,};
        BOOL result = TRUE;

	    app->ucGetTextInfoForBuffer(&new_text_info, (U8*)text);
        new_text_info.char_count += app->m_service_cntxt->msg->msg_body.curr_slide->txt.char_count;
        new_text_info.utf8_msg_len += app->m_service_cntxt->msg->msg_body.curr_slide->txt.utf8_msg_len;
        new_text_info.extension_char_count += app->m_service_cntxt->msg->msg_body.curr_slide->txt.extension_char_count;
        new_text_info.UCS2_count += app->m_service_cntxt->msg->msg_body.curr_slide->txt.UCS2_count;

	    result = app->ucCharInputHandler(&new_text_info);
		if(result)
		{
		       app->m_service_cntxt->msg->msg_body.curr_slide->txt.char_count = new_text_info.char_count;
               app->m_service_cntxt->msg->msg_body.curr_slide->txt.utf8_msg_len = new_text_info.utf8_msg_len;
               app->m_service_cntxt->msg->msg_body.curr_slide->txt.extension_char_count = new_text_info.extension_char_count;
               app->m_service_cntxt->msg->msg_body.curr_slide->txt.UCS2_count = new_text_info.UCS2_count;

				if (app->m_service_cntxt->msg->msg_body.curr_slide->txt.char_count == 1)
				{
					if (app->m_service_cntxt->msg->msg_body.curr_slide)
					{
						app->m_service_cntxt->main->current_text_file_save_result = srv_uc_handle_text_in_current_slide(app->main->instance);
					}
					/* actually, srv_uc_exit_write_msg */
					/* Tricky: because before return WGUI_UCE_TEXT_CHANGE_ALLOWED, editor will not copy string to dst:m_service_cntxt->main->text_buffer
					   so, when srv_uc_save_buffer_to_file is called, no character will be saved to uc txt file, and obj size will not be updated.
					   When wap call calculate api, use the obj->size, will use the wrong error -- */
					if (app->m_service_cntxt->msg->msg_body.curr_slide->txt.char_count == 1) /* only for add characters */
					{
						if (app->m_service_cntxt->main->current_text_file_save_result == FS_NO_ERROR)
						{
							app->m_service_cntxt->msg->msg_body.curr_slide->txt.object->size =
								app->m_service_cntxt->msg->msg_body.curr_slide->txt.utf8_msg_len;
						}
						else
						{
							result = VFX_FALSE;
						}
					}
				}
			//	app->ucTextChangeHandler(&new_text_info);
		}
        *ret = (result)? VFX_TRUE: VFX_FALSE;
    }
}


void VappUCMainScr::udateMessageSize(void)
{
    m_app_data->ucHandleTextInCurrentSlide(); /* we can force call too. But put here to see switchSlide call as generic. *///vikas
    if (m_app_data->m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
    {
        m_app_data->m_service_cntxt->main->mode = SRV_UC_FORWARD_WITH_EDIT_MODE;
    }

    srv_uc_update_msg_size(m_app_data->main->instance);
 //   updateBottomMsgHint();
}


void VappComposerMainPage::onBodyTextChanged(VcpTextEditor *editor)
{
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
	VappUcTextInfoStruct new_text_info = {0,};
//    mmi_ucs2ncpy((S8*)app->m_service_cntxt->main->text_buffer, (S8*)textEditorBody->getText(), 2048);
   // app->m_service_cntxt->main->text_buffer[] = (U8*)textEditorBody->getText();
	app->ucGetTextInfoForBuffer(&new_text_info, (U8*)app->m_service_cntxt->main->text_buffer);
	app->ucTextChangeHandler(&new_text_info);
 //   srv_uc_update_msg_size(app->main->instance);

   if( textEditorBody->m_editing->m_batchEdit > 0)
   {
        app->batchEdit = VFX_TRUE;
   }
   else
   {
        app->batchEdit = VFX_FALSE;
   }
   
   if(app->changeMsgTypeIfNeeded())
   {
        updateButtonBar();
   }
   updateBottomMsgHint();

 //   if (!validationContent(string))
    {
  //     ErrorHandling();
    }
}

void VappComposerMainPage::getRecipientFromBufferByGroup(VcpContactSelector* recipientContacts)
{
    VfxS32 rCount = 0, count = 0;
    VcpContact *contact;
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);


	if(recipientContacts == m_contactSelectorTo)
	{
		app->done->current_addr_type = SRV_UC_ADDRESS_GROUP_TYPE_TO;
	}
#ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__    
	else if(recipientContacts == m_contactSelectorCc)
	{
		app->done->current_addr_type = SRV_UC_ADDRESS_GROUP_TYPE_CC;		
	}
	else if(recipientContacts == m_contactSelectorBcc)
	{
		app->done->current_addr_type = SRV_UC_ADDRESS_GROUP_TYPE_BCC;		
	}
#endif
	app->ucRemoveRecipientByGroup(app->done->current_addr_type);
    if(recipientContacts)
    {
        rCount = recipientContacts->getContactCount();
        if(rCount > 0)
        {
            contact = recipientContacts->getContactList();

            for (count = 0; (count< (S32)app->vappUcGetMaxRecipientCount()) && (count < rCount); count++)
            {
                if(!contact->m_phoneNumber.isEmpty())
                {
                    mmi_ucs2ncpy((S8*)app->done->to, (S8*)contact->m_phoneNumber.getBuf(), contact->m_phoneNumber.getLength());
                    if (vapp_uc_is_ascii_string((S8*) app->done->to) && srv_uc_is_phone_number_valid((S8*) app->done->to))
                    {
                        (MMI_BOOL)srv_uc_add_address(
                                    app->main->instance,
                                    app->done->to,
                                    SRV_UC_ADDRESS_TYPE_PHONE_NUMBER,
                                    app->done->current_addr_type);                
						/*get the prefered sim from PHB for contact*/
						/*kuldeep_gplus*/
						if(app->taken_pref_phb_sim == VFX_FALSE)
						{
							mmi_sim_enum sim_id = MMI_SIM_NONE;
							srv_phb_get_preferred_sim( (U16 *)contact->m_phoneNumber.getBuf(),
							MMI_PHB_INVALID_CONTACT_ID,
							SRV_PHB_NUMBER_OP_TYPE_MESSAGE,
							&sim_id);

							if(sim_id > MMI_SIM_NONE && sim_id < MMI_SIM_END_OF_ENUM && 
							 (app->main->launch_mode == UC_LAUNCH_MODE_NONE) && (vappUcConvertMmiSimIdToUc(sim_id) & vappUcGetValidSimInfo()))
							{
								U16 text_buffer[50] = {0,};
								VfxWString itemText;
								app->m_service_cntxt->send_info->send_sim_id = vappUcConvertMmiSimIdToUc(sim_id);
								app->ucGetComposerTitleString(text_buffer);
								composerTitleBar->setTitle(itemText.loadFromMem((VfxWChar*)text_buffer));
								UpdateSendButtonOnSwithSim();
								app->taken_pref_phb_sim = VFX_TRUE ;
							}
						}
                    }
                }
                else if(!contact->m_email.isEmpty())
                {
                    mmi_ucs2ncpy((S8*)app->done->to, (S8*)contact->m_email.getBuf(), contact->m_email.getLength());
                    if(srv_uc_is_email_addr_valid(app->done->to))
                    {
                        (MMI_BOOL)srv_uc_add_address(
                                    app->main->instance,
                                    app->done->to,
                                    SRV_UC_ADDRESS_TYPE_EMAIL,
                                    app->done->current_addr_type);                       
                    }
                }
                contact = contact->getNext();
            }
        }
    }
    scr->udateMessageSize();
}

void VappComposerMainPage::getRecipientFromBuffer()
{
    VfxS32 rCount = 0, count = 0;
    VcpContact *contact;
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);

    srv_uc_delete_all_addr(app->main->instance);

    if(m_contactSelectorTo)
    {
        rCount = m_contactSelectorTo->getContactCount();
        if(rCount > 0)
        {
            contact = m_contactSelectorTo->getContactList();
            app->done->current_addr_type = SRV_UC_ADDRESS_GROUP_TYPE_TO;

            for (count = 0; (count< (S32)app->vappUcGetMaxRecipientCount()) && (count < rCount); count++)
            {
                if(!contact->m_phoneNumber.isEmpty())
                {
                    mmi_ucs2ncpy((S8*)app->done->to, (S8*)contact->m_phoneNumber.getBuf(), contact->m_phoneNumber.getLength());
                    if (vapp_uc_is_ascii_string((S8*) app->done->to) && srv_uc_is_phone_number_valid((S8*) app->done->to))
                    {
                        (MMI_BOOL)srv_uc_add_address(
                                    app->main->instance,
                                    app->done->to,
                                    SRV_UC_ADDRESS_TYPE_PHONE_NUMBER,
                                    app->done->current_addr_type);                
                    }
                }
                else if(!contact->m_email.isEmpty())
                {
                    mmi_ucs2ncpy((S8*)app->done->to, (S8*)contact->m_email.getBuf(), contact->m_email.getLength());
                    if(srv_uc_is_email_addr_valid(app->done->to))
                    {
                        (MMI_BOOL)srv_uc_add_address(
                                    app->main->instance,
                                    app->done->to,
                                    SRV_UC_ADDRESS_TYPE_EMAIL,
                                    app->done->current_addr_type);                       
                    }
                }
                contact = contact->getNext();
            }
        }
    }
#ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__    
    if(m_contactSelectorCc)
    {
        rCount = m_contactSelectorCc->getContactCount();
        if(rCount > 0)
        {
            contact = m_contactSelectorCc->getContactList();
            app->done->current_addr_type = SRV_UC_ADDRESS_GROUP_TYPE_CC;

            for (count = 0; (count< (S32)app->vappUcGetMaxRecipientCount()) && (count < rCount); count++)
            {
                if(!contact->m_phoneNumber.isEmpty())
                {
                    mmi_ucs2ncpy((S8*)app->done->to, (S8*)contact->m_phoneNumber.getBuf(), contact->m_phoneNumber.getLength());
                    if (vapp_uc_is_ascii_string((S8*) app->done->to) && srv_uc_is_phone_number_valid((S8*) app->done->to))
                    {
                        (MMI_BOOL)srv_uc_add_address(
                                    app->main->instance,
                                    app->done->to,
                                    SRV_UC_ADDRESS_TYPE_PHONE_NUMBER,
                                    app->done->current_addr_type);                
                    }
                }
                else if(!contact->m_email.isEmpty())
                {
                    mmi_ucs2ncpy((S8*)app->done->to, (S8*)contact->m_email.getBuf(), contact->m_email.getLength());
                    if(srv_uc_is_email_addr_valid(app->done->to))
                    {
                        (MMI_BOOL)srv_uc_add_address(
                                    app->main->instance,
                                    app->done->to,
                                    SRV_UC_ADDRESS_TYPE_EMAIL,
                                    app->done->current_addr_type);                       
                    }
                }
                contact = contact->getNext();
            }
        }
    }
    if(m_contactSelectorBcc)
    {
        rCount = m_contactSelectorBcc->getContactCount();
        if(rCount > 0)
        {
            contact = m_contactSelectorBcc->getContactList();
            app->done->current_addr_type = SRV_UC_ADDRESS_GROUP_TYPE_BCC;

            for (count = 0; (count< (S32)app->vappUcGetMaxRecipientCount()) && (count < rCount); count++)
            {
                if(!contact->m_phoneNumber.isEmpty())
                {
                    mmi_ucs2ncpy((S8*)app->done->to, (S8*)contact->m_phoneNumber.getBuf(), contact->m_phoneNumber.getLength());
                    if (vapp_uc_is_ascii_string((S8*) app->done->to) && srv_uc_is_phone_number_valid((S8*) app->done->to))
                    {
                        (MMI_BOOL)srv_uc_add_address(
                                    app->main->instance,
                                    app->done->to,
                                    SRV_UC_ADDRESS_TYPE_PHONE_NUMBER,
                                    app->done->current_addr_type);                
                    }
                }
                else if(!contact->m_email.isEmpty())
                {
                    mmi_ucs2ncpy((S8*)app->done->to, (S8*)contact->m_email.getBuf(), contact->m_email.getLength());
                    if(srv_uc_is_email_addr_valid(app->done->to))
                    {
                        (MMI_BOOL)srv_uc_add_address(
                                    app->main->instance,
                                    app->done->to,
                                    SRV_UC_ADDRESS_TYPE_EMAIL,
                                    app->done->current_addr_type);                       
                    }
                }
                contact = contact->getNext();
            }
        }
    }
 #endif   
    scr->udateMessageSize();
}

void VappComposerMainPage::onSelectingSend(void)
{
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
	U16 errorStringId = 0;

    VappUcTextInfoStruct new_text_info = {0,};

    getRecipientFromBuffer();
    app->ucGetTextInfoForBuffer(&new_text_info, (U8*)app->m_service_cntxt->main->text_buffer);
    app->ucTextChangeHandler(&new_text_info);
    app->ucHandleTextInCurrentSlide();
	errorStringId = app->preCheckSendMessage();
	if( errorStringId != 0)
	{
		mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(errorStringId)).getBuf());
        app->m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
		return;
	}
	if(vappUcFlightModecheck() && app->m_service_cntxt->msg_type->MMS_edit_mode != SRV_UC_MMS_EDIT_MODE_EMAIL )
	{
		mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_FLIGHT_MODE)).getBuf());
	    return;
	}
	else if(app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
	{
            if(vappUcFlightModecheck() && 
                srv_dtcnt_wlan_status() == SRV_DTCNT_WLAN_STATUS_INACTIVE) //WiFi can turn on in flight mode) 
            {
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_FLIGHT_MODE)).getBuf());
                return;
            }   
            validSimSend();
	}
	else if(!(app->m_service_cntxt->send_info->send_sim_id & (vappUcGetValidSimInfo()))) //Send is enable because of reply case but SIM is not present kuldeep_gplus
	{
		U16 text_buffer[200] = {0,};
		VfxWString itemText;
		scr->vappUcGetSimSwapTitle(text_buffer);
		scr->vappUcShowSimSwapConfirm(text_buffer);
	}
	else
	{
		validSimSend();
	}
}
void VappUCMainScr::vappUcGetSimSwapTitle(U16* text_buffer)
{
	if(m_app_data->m_service_cntxt->send_info->send_sim_id == SRV_UC_SIM_ID_GSM_SIM1)
	{
		mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_1));
	}
	else if(m_app_data->m_service_cntxt->send_info->send_sim_id == SRV_UC_SIM_ID_GSM_SIM2)
	{
		mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_2));
	}
	else if(m_app_data->m_service_cntxt->send_info->send_sim_id == SRV_UC_SIM_ID_GSM_SIM3)
	{
		mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_3));
	}
	else
	{
		mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_4));
	}
	mmi_ucs2cat((PS8) text_buffer, (PS8) L" "); 
	mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_ID_VAPP_UC_UNAVAILABLE_TRFR_TO_ID));
	mmi_ucs2cat((PS8) text_buffer, (PS8) L" "); 
	if(vappUcGetValidSimInfo() & SRV_UC_SIM_ID_GSM_SIM1)
	{
		mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_1));
	}
	else if(vappUcGetValidSimInfo() & SRV_UC_SIM_ID_GSM_SIM2)
	{
		mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_2));
	}
	else if(vappUcGetValidSimInfo() & SRV_UC_SIM_ID_GSM_SIM3)
	{
		mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_3));
	}
	else
	{
		mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_4));
	}
	mmi_ucs2cat((PS8) text_buffer, (PS8) L" "); 
	mmi_ucs2cat((PS8) text_buffer, (PS8) L"?"); 
}
VfxBool VappComposerMainPage::addPendingRecipientEntry()
{
	VcpContactSelector* recipientHead= m_contactSelectorTo;
	VcpTextEditor* r_editor = NULL;
	VfxWChar *addressString = NULL;
	VfxWString itemText;
	VfxS32 length = 0;
	VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
	VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
	VfxBool needConfirmScreen = VFX_FALSE;

	srv_uc_address_group_type_enum type = (srv_uc_address_group_type_enum)app->getContactInsertType();
	switch(type)
	{
	case SRV_UC_ADDRESS_GROUP_TYPE_TO:
		recipientHead = m_contactSelectorTo;
		break;
#ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__
	case SRV_UC_ADDRESS_GROUP_TYPE_CC:
		recipientHead = m_contactSelectorCc;
		break;

	case SRV_UC_ADDRESS_GROUP_TYPE_BCC:
		recipientHead = m_contactSelectorBcc;
		break;
#endif        
        
	}

	if(recipientHead)
	{
			r_editor = recipientHead->getInputbox();
			addressString = r_editor->getText();
			length = vfx_sys_wcslen(addressString);

			if(length != 0)
			{
			  if(length == 1 && addressString[0] == 10)
	 //         if(length == 1 && mmi_ucs2chr((PS8)addressString, 10) != NULL)
			  {
				 //skip
			  }
			  else
			  {
				// if(length == 1 && mmi_ucs2chr((PS8)addressString, 10) != NULL)
				 //need add
				 if (vapp_uc_is_ascii_string((S8*) addressString) && srv_uc_is_phone_number_valid((PS8)addressString))
				 {
					#ifdef __MMI_EMAIL__
					if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
					{
						mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_INVALID_RECIPIENT)).getBuf());
					}
					else
					#endif
					{
						recipientHead->add(VFX_WSTR_EMPTY, itemText.loadFromMem((VfxWChar *)addressString), VFX_WSTR_EMPTY);
					}
				 }
				 else if(app->m_service_cntxt->msg_type->caller_specific_msg_type != SRV_UC_MSG_TYPE_SMS_ONLY && srv_uc_is_email_addr_valid((U8*)addressString))
				 {
					 srv_uc_msg_type_enum type_before = app->m_service_cntxt->msg_type->curr_msg_type;

					 recipientHead->add(VFX_WSTR_EMPTY,VFX_WSTR_EMPTY, itemText.loadFromMem((VfxWChar *)addressString));
        #ifdef __MMI_EMAIL__
					if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
					{
						VappEmailComp::addRecentContact((WCHAR*) addressString);
					}
        #endif

					#ifdef __MMI_EMAIL__
					if (app->m_service_cntxt->msg_type->MMS_edit_mode != SRV_UC_MMS_EDIT_MODE_EMAIL)
					#endif
					{
						if(type_before == SRV_UC_MSG_TYPE_SMS_PREFER && app->m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
						{
							needConfirmScreen = VFX_TRUE;
						}
					}
				 }
				 else
				 {
					mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_INVALID_RECIPIENT)).getBuf());
				 }
			  }
			}
			r_editor->deleteAll();
			r_editor->setEnterKeyEnabled(VFX_FALSE);
	}
	return needConfirmScreen;
}

#if defined(__MMI_MESSAGES_TEMPLATE__)  
void VappComposerMainPage::onSmsTemplateClicked(VfxObject * obj, VfxWString templateString, VfxU16 templateId)
{
    VappTextTemplateListPage *page;
    page = (VappTextTemplateListPage *)obj;

	// Insert text
	insertTextString((VfxWChar*)templateString.getBuf());
    // close page 
    page->closePage();
}
#endif

VfxObject * VappComposerMainPage::getNextHighlightPosition(VfxId itemID, VfxId moveSide)
{
	if(moveSide == ID_TOOLBAR_NEXT)
	{
		switch(itemID)
			{
	        #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__    
					case ID_RECIPIENT_TO:
					if(m_contactSelectorCc)
					{
						return (VfxObject *)m_contactSelectorCc->getInputbox();
					}
				case ID_RECIPIENT_CC:
					if(m_contactSelectorBcc)
					{
						return (VfxObject *)m_contactSelectorBcc->getInputbox();
					}
				case ID_RECIPIENT_BCC:
					if(textEditorSubject)
					{
						return (VfxObject *)textEditorSubject;
					}
             #else
                    case ID_RECIPIENT_TO:
                    if(textEditorSubject)
					{
						return (VfxObject *)textEditorSubject;
					}    
             #endif
				case ID_SUBJECT:
					if(textEditorBody)
					{
						return (VfxObject *)textEditorBody;
					}
				case ID_BODY_TEXT:
					{
						return (VfxObject *)NULL;
					}
				/*	if(m_contactSelectorTo)
					{
						if(itemID == ID_RECIPIENT_TO)
						{
							return (VfxObject *)NULL;
						}
						return (VfxObject *)m_contactSelectorTo->getInputbox();
					}*/
			}
	}
	else
	{
		switch(itemID)
			{
				case ID_BODY_TEXT:
					if(textEditorSubject)
					{
						return (VfxObject *)textEditorSubject;
					}
            #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__         
				case ID_SUBJECT:
					if(m_contactSelectorBcc)
					{
						return (VfxObject *)m_contactSelectorBcc->getInputbox();
					}
				case ID_RECIPIENT_BCC:
					if(m_contactSelectorCc)
					{
						return (VfxObject *)m_contactSelectorCc->getInputbox();
					}
				case ID_RECIPIENT_CC:
					if(m_contactSelectorTo)
					{
						return (VfxObject *)m_contactSelectorTo->getInputbox();
					}
             #else
                case ID_SUBJECT:
                    if(m_contactSelectorTo)
					{
						return (VfxObject *)m_contactSelectorTo->getInputbox();
					}                    
             #endif
				case ID_RECIPIENT_TO:
				/*	if(textEditorBody)
					{
						if(itemID == ID_BODY_TEXT)
						{
								return (VfxObject *)NULL;
						}
						return (VfxObject *)textEditorBody;
					}*/
					{
						return (VfxObject *)NULL;
					}
			}	
	}
		return (VfxObject *)NULL;
}

void VappComposerMainPage::resetAllFunctionBar(void)
{
	resetFunctionBar(m_contactSelectorTo);
#ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__     
	resetFunctionBar(m_contactSelectorCc);
	resetFunctionBar(m_contactSelectorBcc);
#endif    
	resetFunctionBar(textEditorSubject);
	resetFunctionBar(textEditorBody);
	resetFunctionBar(textEditorBody);
}

void VappComposerMainPage::resetFunctionBar(VfxObject* obj)
{
	VcpFunctionBar* function_bar = NULL;
	if(obj)
	{
		if(obj == m_contactSelectorTo)
		{
			function_bar = m_functionBarToFrame;
		}
    #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__     
		else if(obj == m_contactSelectorCc)
		{
			function_bar = m_functionBarCcFrame;
		}
		else if(obj == m_contactSelectorBcc)
		{
			function_bar = m_functionBarBccFrame;
		}
    #endif
		else if(obj == textEditorSubject)
		{
			function_bar = m_functionBarSubjectFrame;
		}
		else if(obj == textEditorBody)
		{
			function_bar = m_functionBarFrame;
		}
		else
		{
			return;
		}
	}
	else
	{
		return;
	}

	if(getItemToHilight(obj, ID_TOOLBAR_PREV) == NULL)
	{
		function_bar->setDisableItem(ID_TOOLBAR_PREV, VFX_TRUE);
	}
	else
	{
		function_bar->setDisableItem(ID_TOOLBAR_PREV, VFX_FALSE);
	}
	if(getItemToHilight(obj, ID_TOOLBAR_NEXT) == NULL)
	{
		function_bar->setDisableItem(ID_TOOLBAR_NEXT, VFX_TRUE);
	}
	else
	{
		function_bar->setDisableItem(ID_TOOLBAR_NEXT, VFX_FALSE);
	}
}


VcpTextEditor* VappComposerMainPage::getNextEditorFromFunctionBar(VcpFunctionBar* function_bar, VfxId moveSide)
{
	if(function_bar == NULL)
	{
		return NULL;
	}
	if( function_bar == m_functionBarFrame)
	{
		return (VcpTextEditor*)getNextHighlightPosition(ID_BODY_TEXT, moveSide);
	}
	else if(function_bar == m_functionBarSubjectFrame)
	{
		return (VcpTextEditor*)getNextHighlightPosition(ID_SUBJECT, moveSide);	
	}
#ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__     
	else if(function_bar == m_functionBarBccFrame)
	{
		return (VcpTextEditor*)getNextHighlightPosition(ID_RECIPIENT_BCC, moveSide);	
	}
	else if(function_bar == m_functionBarCcFrame)
	{
		return (VcpTextEditor*)getNextHighlightPosition(ID_RECIPIENT_CC, moveSide);
	}
#endif    
	else if(function_bar == m_functionBarToFrame)
	{
		return (VcpTextEditor*)getNextHighlightPosition(ID_RECIPIENT_TO, moveSide);	
	}
	else
	{
		return (VcpTextEditor*)NULL;
	}
}



VfxObject* VappComposerMainPage::getItemToHilight(VfxObject* obj, VfxId id)
{
	if(obj == m_contactSelectorTo)
	{
		return getNextHighlightPosition(ID_RECIPIENT_TO, id);
	}
#ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__     
	else if(obj == m_contactSelectorCc)
	{
		return getNextHighlightPosition(ID_RECIPIENT_CC, id);
	}
	else if( obj == m_contactSelectorBcc)
	{
		return getNextHighlightPosition(ID_RECIPIENT_BCC, id);
	}
#endif    
	else if( obj == textEditorSubject)
	{
		return getNextHighlightPosition(ID_SUBJECT, id);
	}
	else if(obj == textEditorBody)
	{
		return getNextHighlightPosition(ID_BODY_TEXT, id);
	}
	return NULL;
}
/*kuldeep_gplus*/
void VappComposerMainPage::UpdateSendButtonOnSwithSim(void)
{
	VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
	VfxBool isSendPresent_to = VFX_FALSE ;
#ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__     
	VfxBool isSendPresent_cc = VFX_FALSE ;
	VfxBool isSendPresent_bcc = VFX_FALSE ;
#endif    
	VfxBool isSendPresent_textbody = VFX_FALSE ;
	VfxBool isSendPresent_subject = VFX_FALSE ;
	//VfxBool isSendPresent_buttonbar = VFX_FALSE ;

	if(m_functionBarToFrame)
	{
		isSendPresent_to  = m_functionBarToFrame->removeItem(ID_TOOLBAR_SEND);
	}
 #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__    
	if(m_functionBarCcFrame)
	{
		 isSendPresent_cc  = m_functionBarCcFrame->removeItem(ID_TOOLBAR_SEND);
	}
	if(m_functionBarBccFrame)
	{
		isSendPresent_bcc = m_functionBarBccFrame->removeItem(ID_TOOLBAR_SEND);
	}
 #endif    
	if(m_functionBarFrame)
	{
		 isSendPresent_textbody = m_functionBarFrame->removeItem(ID_TOOLBAR_SEND);
	}
	if(m_functionBarSubjectFrame)
	{
		 isSendPresent_subject = m_functionBarSubjectFrame->removeItem(ID_TOOLBAR_SEND);
	}
	/*if(composerToolbar)
	{
		 isSendPresent_buttonbar = composerToolbar->removeItem(ID_TOOLBAR_SEND);
	}*/
	if(isSendPresent_to)
	{
		m_functionBarToFrame->addItem(ID_TOOLBAR_SEND,VFX_WSTR_RES(STR_GLOBAL_SEND));
		m_functionBarToFrame->setItemSpecial(ID_TOOLBAR_SEND);
		onEntertoggleString();
		if (!isSendButtonAvailable())
		{
			m_functionBarToFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
		}
	}
#ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__  	
	if(m_functionBarCcFrame && isSendPresent_cc)
	{
		m_functionBarCcFrame->addItem(ID_TOOLBAR_SEND,VFX_WSTR_RES(STR_GLOBAL_SEND));
		m_functionBarCcFrame->setItemSpecial(ID_TOOLBAR_SEND);
		onEntertoggleString();
		if (!isSendButtonAvailable())
		{
			m_functionBarCcFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
		}
	}
	
	if(m_functionBarBccFrame && isSendPresent_bcc)
	{
		m_functionBarBccFrame->addItem(ID_TOOLBAR_SEND,VFX_WSTR_RES(STR_GLOBAL_SEND));
		m_functionBarBccFrame->setItemSpecial(ID_TOOLBAR_SEND);
		onEntertoggleString();
		if (!isSendButtonAvailable())
		{
			m_functionBarBccFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
		}
	}
#endif	
	if(m_functionBarFrame && isSendPresent_textbody)
	{
		m_functionBarFrame->addItem(ID_TOOLBAR_SEND,VFX_WSTR_RES(STR_GLOBAL_SEND));
		m_functionBarFrame->setItemSpecial(ID_TOOLBAR_SEND);
		onEntertoggleString();
        if (!isSendButtonAvailable())
        {
			m_functionBarFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
		}
	}
	
	if(m_functionBarSubjectFrame && isSendPresent_subject)
	{
		m_functionBarSubjectFrame->addItem(ID_TOOLBAR_SEND,VFX_WSTR_RES(STR_GLOBAL_SEND));
		m_functionBarSubjectFrame->setItemSpecial(ID_TOOLBAR_SEND);
		onEntertoggleString();
		if (!isSendButtonAvailable())
		{
			m_functionBarSubjectFrame->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
		}
	}
	
	if(composerToolbar)
	{
       /* composerToolbar->addItem(ID_TOOLBAR_SEND, VFX_WSTR_RES(STR_GLOBAL_SEND), IMG_ID_VAPP_UC_SEND_ID);       // add tool bar "Send" button
		m_toolBarItemOn |= TOOLBAR_SEND;
		if(!((vappUcGetValidSimInfo() & ~(vappUcGetInvalidSimInfo())) & app->m_service_cntxt->send_info->send_sim_id))
		{
			composerToolbar->setDisableItem(ID_TOOLBAR_SEND, VFX_TRUE);
		}*/
		updateButtonBar();
	}
}

void VappComposerMainPage::GetSwitchSimString(U16* text_buffer)
{
	VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);

	VfxWString SimTitle = vapp_sim_settings_get_sim_name_with_sim_id(
						  vappUcConvertUCSimIdToMmi(app->m_service_cntxt->send_info->send_sim_id));
	mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_ID_VAPP_UC_SWITCHED_TO));
	mmi_ucs2cat((PS8) text_buffer, (PS8) L" ");
	mmi_ucs2cat((PS8) text_buffer, (PS8)((SimTitle).getBuf()));
}

void VappComposerMainPage::onToolBarClick(VfxObject* obj, VfxId id)
{
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
	
	if(!vappUcCheckAppSanity((void *)app))
	{
		return;
	}

    if( app->main->busy_getting_data)
        return ;

	app->m_service_cntxt->main->current_text_file_save_result = app->ucHandleTextInCurrentSlide(); /* we can force call too. But put here to see switchSlide call as generic. *///vikas
	if(app->m_service_cntxt->main->current_text_file_save_result != FS_NO_ERROR &&
       (id != VappComposerMainPage::ID_TOOLBAR_CANCEL))
	{
        if( (app->m_service_cntxt->main->current_text_file_save_result == FS_DISK_FULL) &&
            (app->m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER ||
             app->m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_ONLY) &&
            (id == ID_TOOLBAR_SEND || id == ID_TOOLBAR_SWITCH_SIM || id == ID_TOOLBAR_SAVE ||
             id == ID_TOOLBAR_SAVE_AS || id == ID_TOOLBAR_SWITCH_SIM1 || id == ID_TOOLBAR_SWITCH_SIM2 ||
             id == ID_TOOLBAR_SWITCH_SIM3 || id == ID_TOOLBAR_SWITCH_SIM4 || id == ID_TOOLBAR_QUERY_SIM1 ||
             id == ID_TOOLBAR_QUERY_SIM2 || id == ID_TOOLBAR_QUERY_SIM3 || id == ID_TOOLBAR_QUERY_SIM4 ||
             id == ID_COMMAND_SAVE_AS_DRAFT || id == ID_COMMAND_SAVE_AS_TEMPLATE || id == ID_TOOLBAR_REMOVE_SUBJECT ||
             id == ID_COMMAND_REMOVE_CC || id == ID_COMMAND_REMOVE_BCC)
          )
        {
            //ignore the FS_DISK_FULL error when compose a sms
        }
        else
        {        
            VfxU16 fs_error_string = 0;
    		fs_error_string = srv_fmgr_fs_error_get_string(app->m_service_cntxt->main->current_text_file_save_result);
    		mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
    		(WCHAR*)VFX_WSTR_RES(fs_error_string).getBuf());
    		return ;
        }
	}
	restoreControls();
    switch(id)
    {
	case VappComposerMainPage::ID_TOOLBAR_SEND:
         {
			if(addPendingRecipientEntry())
			{
				scr->vappUcShowSendConfirm((VfxWChar*)VFX_WSTR_RES(STR_ID_VAPP_UC_SEND_CONT_ID).getBuf());//STR_ID_VAPP_UC_SEND_CONT_ID
			}
			else
			{
				onSelectingSend();
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
         }
		 break;
#if (MMI_MAX_SIM_NUM >= 2)
	case VappComposerMainPage::ID_TOOLBAR_SWITCH_SIM1:
        {
            U16 text_buffer[50] = {0,};
			U16 sim_buffer[50] = {0,};
            VfxWString itemText;
            app->m_service_cntxt->send_info->send_sim_id = SRV_UC_SIM_ID_GSM_SIM1;
            app->ucGetComposerTitleString(text_buffer);
            composerTitleBar->setTitle(itemText.loadFromMem((VfxWChar*)text_buffer));
	        onEntertoggleString();
			#ifdef __MMI_EMAIL__
			if (app->m_service_cntxt->msg_type->MMS_edit_mode != SRV_UC_MMS_EDIT_MODE_EMAIL)
			#endif
			UpdateSendButtonOnSwithSim();
			GetSwitchSimString(sim_buffer);
            //mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_UC_USING_SIM1_ID).getBuf());
			mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO,
			(WCHAR*)(sim_buffer));
        }
        break;
	case VappComposerMainPage::ID_TOOLBAR_SWITCH_SIM2:
        {
            U16 text_buffer[50] = {0,};
			U16 sim_buffer[50] = {0,};
            VfxWString itemText;
            app->m_service_cntxt->send_info->send_sim_id = SRV_UC_SIM_ID_GSM_SIM2;
            app->ucGetComposerTitleString(text_buffer);
            composerTitleBar->setTitle(itemText.loadFromMem((VfxWChar*)text_buffer));
	        onEntertoggleString();
			#ifdef __MMI_EMAIL__
			if (app->m_service_cntxt->msg_type->MMS_edit_mode != SRV_UC_MMS_EDIT_MODE_EMAIL)
			#endif
			UpdateSendButtonOnSwithSim();
			GetSwitchSimString(sim_buffer);
            //mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_UC_USING_SIM2_ID).getBuf());
			mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO,
			(WCHAR*)(sim_buffer));
        }
        break;
	case VappComposerMainPage::ID_TOOLBAR_SWITCH_SIM3:
        {
            U16 text_buffer[50] = {0,};
			U16 sim_buffer[50] = {0,};
            VfxWString itemText;
            app->m_service_cntxt->send_info->send_sim_id = SRV_UC_SIM_ID_GSM_SIM3;
            app->ucGetComposerTitleString(text_buffer);
            composerTitleBar->setTitle(itemText.loadFromMem((VfxWChar*)text_buffer));
	        onEntertoggleString();
			#ifdef __MMI_EMAIL__
			if (app->m_service_cntxt->msg_type->MMS_edit_mode != SRV_UC_MMS_EDIT_MODE_EMAIL)
			#endif
			UpdateSendButtonOnSwithSim();
			GetSwitchSimString(sim_buffer);
            //mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_UC_USING_SIM3_ID).getBuf());
			mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO,
			(WCHAR*)(sim_buffer));
        }
        break;
	case VappComposerMainPage::ID_TOOLBAR_SWITCH_SIM4:
        {
            U16 text_buffer[50] = {0,};
			U16 sim_buffer[50] = {0,};
            VfxWString itemText;
            app->m_service_cntxt->send_info->send_sim_id = SRV_UC_SIM_ID_GSM_SIM4;
            app->ucGetComposerTitleString(text_buffer);
            composerTitleBar->setTitle(itemText.loadFromMem((VfxWChar*)text_buffer));
	        onEntertoggleString();
			#ifdef __MMI_EMAIL__
			if (app->m_service_cntxt->msg_type->MMS_edit_mode != SRV_UC_MMS_EDIT_MODE_EMAIL)
			#endif
			UpdateSendButtonOnSwithSim();
			GetSwitchSimString(sim_buffer);
            //mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_UC_USING_SIM4_ID).getBuf());
			mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO,
			(WCHAR*)(sim_buffer));
        }
        break;
    case VappComposerMainPage::ID_TOOLBAR_QUERY_SIM1:
        {
            U16 text_buffer[50] = {0,};
            VfxWString itemText;
            app->m_service_cntxt->send_info->send_sim_id = SRV_UC_SIM_ID_GSM_SIM1;
            app->ucGetComposerTitleString(text_buffer);
            composerTitleBar->setTitle(itemText.loadFromMem((VfxWChar*)text_buffer));
	        onEntertoggleString();
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_UC_USING_SIM1_ID).getBuf());
            validSimSend();
        }
        break;

    case VappComposerMainPage::ID_TOOLBAR_QUERY_SIM2:
        {
            U16 text_buffer[50] = {0,};
            VfxWString itemText;
            app->m_service_cntxt->send_info->send_sim_id = SRV_UC_SIM_ID_GSM_SIM2;
            app->ucGetComposerTitleString(text_buffer);
            composerTitleBar->setTitle(itemText.loadFromMem((VfxWChar*)text_buffer));
	        onEntertoggleString();
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_UC_USING_SIM2_ID).getBuf());
            validSimSend();
        }
        break;

    case VappComposerMainPage::ID_TOOLBAR_QUERY_SIM3:
        {
            U16 text_buffer[50] = {0,};
            VfxWString itemText;
            app->m_service_cntxt->send_info->send_sim_id = SRV_UC_SIM_ID_GSM_SIM3;
            app->ucGetComposerTitleString(text_buffer);
            composerTitleBar->setTitle(itemText.loadFromMem((VfxWChar*)text_buffer));
	        onEntertoggleString();
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_UC_USING_SIM3_ID).getBuf());
            validSimSend();
        }
        break;

    case VappComposerMainPage::ID_TOOLBAR_QUERY_SIM4:
        {
            U16 text_buffer[50] = {0,};
            VfxWString itemText;
            app->m_service_cntxt->send_info->send_sim_id = SRV_UC_SIM_ID_GSM_SIM4;
            app->ucGetComposerTitleString(text_buffer);
            composerTitleBar->setTitle(itemText.loadFromMem((VfxWChar*)text_buffer));
	        onEntertoggleString();
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_UC_USING_SIM4_ID).getBuf());
            validSimSend();
        }
        break;
#endif
#if (MMI_MAX_SIM_NUM >= 2)
	case VappComposerMainPage::ID_TOOLBAR_SWITCH_SIM:
        {
            U16 text_buffer[50] = {0,};
            VfxWString itemText;
			//U16 sim_count = vappUcGetValidSimInfo() ;
#if (MMI_MAX_SIM_NUM >= 3)
			/*TODO : temp_done*/
            //if((sim_count != 3) && (sim_count != 5) && (sim_count != 6) && (sim_count != 9) && (sim_count != 10) && (sim_count != 12))
			if((vappUcGetAllSimCount() > 2) ||
				((vappUcGetAllSimCount() == 2) && !(app->m_service_cntxt->send_info->send_sim_id & vappUcGetValidSimInfo())))
            {
			    VFX_OBJ_CREATE(m_commandPopup, VcpCommandPopup, this);
			    m_commandPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_UC_SWITCH_SIM_ID));
                if((vappUcGetValidSimInfo() & SRV_UC_SIM_ID_GSM_SIM1) && app->m_service_cntxt->send_info->send_sim_id != SRV_UC_SIM_ID_GSM_SIM1)
                {
                    vappUcGetSimNameString(SRV_UC_SIM_ID_GSM_SIM1, text_buffer);
                    itemText.loadFromMem((VfxWChar*)text_buffer);
			        m_commandPopup->addItem(VappComposerMainPage::ID_TOOLBAR_SWITCH_SIM1, itemText);
                }
                if((vappUcGetValidSimInfo() & SRV_UC_SIM_ID_GSM_SIM2) && app->m_service_cntxt->send_info->send_sim_id != SRV_UC_SIM_ID_GSM_SIM2)
                {
                    memset(text_buffer, 0, 50);
                   vappUcGetSimNameString(SRV_UC_SIM_ID_GSM_SIM2, text_buffer);
                    itemText.loadFromMem((VfxWChar*)text_buffer);
			        m_commandPopup->addItem(VappComposerMainPage::ID_TOOLBAR_SWITCH_SIM2, itemText);
                }
                if((vappUcGetValidSimInfo() & SRV_UC_SIM_ID_GSM_SIM3) && app->m_service_cntxt->send_info->send_sim_id != SRV_UC_SIM_ID_GSM_SIM3)
                {
                    memset(text_buffer, 0, 50);
                   vappUcGetSimNameString(SRV_UC_SIM_ID_GSM_SIM3, text_buffer);
                    itemText.loadFromMem((VfxWChar*)text_buffer);
			        m_commandPopup->addItem(VappComposerMainPage::ID_TOOLBAR_SWITCH_SIM3, itemText);
                }
                if((vappUcGetValidSimInfo() & SRV_UC_SIM_ID_GSM_SIM4) && app->m_service_cntxt->send_info->send_sim_id != SRV_UC_SIM_ID_GSM_SIM4)
                {
                    memset(text_buffer, 0, 50);
                   vappUcGetSimNameString(SRV_UC_SIM_ID_GSM_SIM4, text_buffer);
                    itemText.loadFromMem((VfxWChar*)text_buffer);
			        m_commandPopup->addItem(VappComposerMainPage::ID_TOOLBAR_SWITCH_SIM4, itemText);
                }
                m_commandPopup->addItem(0xFFFF, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);	    	
                m_commandPopup->setAutoDestory(VFX_TRUE);
                m_commandPopup->m_signalButtonClicked.connect(this, &VappComposerMainPage::onToolBarClick); 
                m_commandPopup->show(VFX_TRUE);
                break;
            }
            else
#endif
            {
				U16 sim_buffer[50] = {0,};

		       /* if(app->m_service_cntxt->send_info->send_sim_id == SRV_UC_SIM_ID_GSM_SIM1)
		    {
              //  composerTitleBar->onUpdate();
                app->m_service_cntxt->send_info->send_sim_id = SRV_UC_SIM_ID_GSM_SIM2;
                app->ucGetComposerTitleString(text_buffer);
                composerTitleBar->setTitle(itemText.loadFromMem((VfxWChar*)text_buffer));
				onEntertoggleString();
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_UC_USING_SIM2_ID).getBuf());
		    }
		    else if (app->m_service_cntxt->send_info->send_sim_id == SRV_UC_SIM_ID_GSM_SIM2)
		    {
               //  composerTitleBar->onUpdate();
                app->m_service_cntxt->send_info->send_sim_id = SRV_UC_SIM_ID_GSM_SIM1;
                app->ucGetComposerTitleString(text_buffer);
                composerTitleBar->setTitle(itemText.loadFromMem((VfxWChar*)text_buffer));
                onEntertoggleString();
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_UC_USING_SIM1_ID).getBuf());
		        }*/
				
				/*Do the new handleing here when twosim other then SIM1 and SIM2 present*/
				app->m_service_cntxt->send_info->send_sim_id = (srv_uc_sim_id)(vappUcGetValidSimInfo() & ~(U32)app->m_service_cntxt->send_info->send_sim_id) ;
                app->ucGetComposerTitleString(text_buffer);
                composerTitleBar->setTitle(itemText.loadFromMem((VfxWChar*)text_buffer));
			    onEntertoggleString();
				/*if(app->m_service_cntxt->send_info->send_sim_id == SRV_UC_SIM_ID_GSM_SIM1)
				{
					mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_UC_USING_SIM1_ID).getBuf());
				}
				else if(app->m_service_cntxt->send_info->send_sim_id == SRV_UC_SIM_ID_GSM_SIM2)
				{
					mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_UC_USING_SIM2_ID).getBuf());
				}
				else if(app->m_service_cntxt->send_info->send_sim_id == SRV_UC_SIM_ID_GSM_SIM3)
				{
					mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_UC_USING_SIM3_ID).getBuf());
				}
				else if(app->m_service_cntxt->send_info->send_sim_id == SRV_UC_SIM_ID_GSM_SIM4)
				{
					mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_UC_USING_SIM4_ID).getBuf());
				}*/
				UpdateSendButtonOnSwithSim();
				GetSwitchSimString(sim_buffer);
				//mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_UC_USING_SIM1_ID).getBuf());
				mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO,
				(WCHAR*)(sim_buffer));
            }
        }
		break;
#endif
	case VappComposerMainPage::ID_TOOLBAR_SAVE_AS:
    case VappComposerMainPage::ID_TOOLBAR_SAVE:
		{
        #if defined(__MMI_MESSAGES_TEMPLATE__) || defined(__MMI_MMS_TEMPLATE_SUPPORT__)    
            if((app->operation_type != UC_OPERATION_WRITE_NEW_SMS_TEMPLATE) &&
                (app->operation_type != UC_OPERATION_EDIT_SMS_TEMPLATE) && 
                (app->operation_type != UC_OPERATION_WRITE_NEW_MMS_TEMPLATE) &&
                (app->operation_type != UC_OPERATION_EDIT_MMS_TEMPLATE)
				)
		#endif		
            {
				addPendingRecipientEntry();
			    VFX_OBJ_CREATE(m_popup,VcpIndicatorPopup,this);
                m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
                m_popup->setText(VFX_WSTR_RES(STR_GLOBAL_SAVING));
                m_popup->setAutoDestory(VFX_FALSE);
                m_popup->show(VFX_TRUE);


				VappUcTextInfoStruct new_text_info = {0,};
				app->ucGetTextInfoForBuffer(&new_text_info, (U8*)app->m_service_cntxt->main->text_buffer);
				app->ucTextChangeHandler(&new_text_info);
				app->ucHandleTextInCurrentSlide();
				app->m_signalConnectOnError.connect(getMainScr(), &VappUCMainScr::connectToClose);
                app->m_signalConnectToCloseProgress.connect(getMainScr(), &VappUCMainScr::connectToCloseProgress);
				getRecipientFromBuffer();
				app->m_service_cntxt->send_info->action = SRV_UC_ACTION_SAVE;
				app->saveMessage();
			}
        #if defined(__MMI_MESSAGES_TEMPLATE__) || defined(__MMI_MMS_TEMPLATE_SUPPORT__)
            else
            {
			    VFX_OBJ_CREATE(m_popup,VcpIndicatorPopup,this);
                m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
                m_popup->setText(VFX_WSTR_RES(STR_GLOBAL_SAVING));
                m_popup->setAutoDestory(VFX_FALSE);
                m_popup->show(VFX_TRUE);
    
                VappUcTextInfoStruct new_text_info = {0,};
                app->ucGetTextInfoForBuffer(&new_text_info, (U8*)app->m_service_cntxt->main->text_buffer);
                app->ucTextChangeHandler(&new_text_info);
                app->ucHandleTextInCurrentSlide();
                app->m_signalConnectOnError.connect(getMainScr(), &VappUCMainScr::connectToClose);
                app->m_signalConnectToCloseProgress.connect(getMainScr(), &VappUCMainScr::connectToCloseProgress);
                /* Ashok added: Update the UC state as EDIT existing msg in place of default write new msg */
                if(app->operation_type == UC_OPERATION_EDIT_MMS_TEMPLATE)
                {
                    /* this state check will be used when get the save rsp form UMMS, to delete the old template */
                    app->m_service_cntxt->main->state = SRV_UC_STATE_EDIT_EXISTED_MSG;
                }
                app->m_service_cntxt->send_info->action = SRV_UC_ACTION_SAVE_AS_TEMPLATE;
                app->saveMessage();
            }
        #endif    
			break;
		}
	case VappComposerMainPage::ID_TOOLBAR_INSERT:
        {
            VappTestInsertMenuListPage *insertMenuPage;
            app->ucSetInsertMenu();
			app->main->launch_mode = UC_LAUNCH_MODE_NONE;
            VFX_OBJ_CREATE(insertMenuPage, VappTestInsertMenuListPage, getMainScr());
            getMainScr()->pushPage(0, insertMenuPage);
            if (app->m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
            {
                app->m_service_cntxt->main->mode = SRV_UC_FORWARD_WITH_EDIT_MODE;
            }
			 srv_uc_update_msg_size(app->main->instance);
           // insertMenuPage->m_signalConenctOnPage.connect(getMainScr(), &VappUCMainScr::connectOnPage);
			break;
        }
	case VappComposerMainPage::ID_TOOLBAR_ADD_SUBJECT:
		{
            m_itemForceOn |= ID_SUBJECT;
            app->main->m_itemForceOn |= UC_SUBJECT;
    #ifdef __MMI_EMAIL__
        if (app->m_service_cntxt->msg_type->MMS_edit_mode != SRV_UC_MMS_EDIT_MODE_EMAIL)
    #endif
            app->changeMsgTypeIfNeeded();
          //  app->ucChangeMsgTypeToMms();
            insertSubjectItem();
            updateButtonBar();
            updateBottomMsgHint();
            if (textEditorSubject)
            {
				textEditorSubject->activate();
				highlightedEditor = textEditorSubject;
            }
		}
			break;
	case VappComposerMainPage::ID_TOOLBAR_REMOVE_SUBJECT:
		{
            m_itemForceOn &= ~ID_SUBJECT;
            app->main->m_itemForceOn &= ~UC_SUBJECT;
            memset(app->m_service_cntxt->msg->subject, 0, sizeof(app->m_service_cntxt->msg->subject));
            app->changeMsgTypeIfNeeded();
            if (app->m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
            {
                app->m_service_cntxt->main->mode = SRV_UC_FORWARD_WITH_EDIT_MODE;
            }            
            srv_uc_update_msg_size(app->main->instance);
            removeObjectFromPage(ID_SUBJECT);
            updateBottomMsgHint();
			updateButtonBar();
			setEditorActivated();
		}
			break;
#ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__              
	case VappComposerMainPage::ID_TOOLBAR_CCBCC:
		{
			VFX_OBJ_CREATE(m_commandPopup, VcpCommandPopup, this);
			m_commandPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_UC_CCBCC));
            if((m_itemForceOn & ID_RECIPIENT_CC) == ID_RECIPIENT_CC)
            {
			    m_commandPopup->addItem(VappComposerMainPage::ID_COMMAND_REMOVE_CC, VFX_WSTR_RES(STR_ID_VAPP_UC_REMOVE_CC));
            }
            else
            {
 			    m_commandPopup->addItem(VappComposerMainPage::ID_COMMAND_ADD_CC, VFX_WSTR_RES(STR_ID_VAPP_UC_ADD_CC));           
            }
            if((m_itemForceOn & ID_RECIPIENT_BCC) == ID_RECIPIENT_BCC)
            {
			    m_commandPopup->addItem(VappComposerMainPage::ID_COMMAND_REMOVE_BCC, VFX_WSTR_RES(STR_ID_VAPP_UC_REMOVE_BCC));
            }
            else
            {
 			    m_commandPopup->addItem(VappComposerMainPage::ID_COMMAND_ADD_BCC, VFX_WSTR_RES(STR_ID_VAPP_UC_ADD_BCC));
            }
            m_commandPopup->addItem(0xFFFF, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);	    	
            m_commandPopup->setAutoDestory(VFX_TRUE);
            m_commandPopup->m_signalButtonClicked.connect(this, &VappComposerMainPage::onToolBarClick); 
            m_commandPopup->show(VFX_TRUE);
			 // Progress Indicator
       //     getMainScr()->pushPage(VFX_ID_NULL, page);
		}
		break;
#endif

#ifdef __MMI_COSMOS_UC_MMS_PREVIEW_SUPPORT__        
	case VappComposerMainPage::ID_TOOLBAR_PREVIEW:
        {
			VFX_OBJ_CREATE(m_popup,VcpIndicatorPopup,this);
            m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
            m_popup->setText(VFX_WSTR_RES(STR_GLOBAL_PLEASE_WAIT));
            m_popup->setAutoDestory(VFX_FALSE);
            m_popup->show(VFX_TRUE);

            VappUcTextInfoStruct new_text_info = {0,};
            app->ucGetTextInfoForBuffer(&new_text_info, (U8*)app->m_service_cntxt->main->text_buffer);
            app->ucTextChangeHandler(&new_text_info);
            app->ucHandleTextInCurrentSlide();
            app->m_signalConnectToCloseProgress.connect(getMainScr(), &VappUCMainScr::connectToCloseProgress);
            getRecipientFromBuffer();
            app->m_signalPreview.connect(getMainScr(), &VappUCMainScr::ucPreviewMms);
            app->previewMessage();
        }
        break;
#endif

#if defined(__MMI_VCARD__)  
	case VappComposerMainPage::ID_TOOLBAR_ADD_VCARD:
		{
			/*Launch Phone book to select the vcard contact*/
			VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
			VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
			VfxId  pageId = scr->getTopPageId(); 
			//app->m_signalConnectOnPage.connect(getMainScr(), &VappUCMainScr::connectOnPage);

			app->main->highlighted_object_type = SRV_UC_OBJECT_TYPE_ATTACHMENT;
			app->m_pbInsertState = UC_PB_CUI_STATE_INSERT_VCARD;						

			scr->ucOpenPhoneBook(VFX_FALSE, MMI_PHB_CONTACT_FIELD_NAME | MMI_PHB_CONTACT_FIELD_NUMBER | MMI_PHB_CONTACT_FIELD_EMAIL);
			scr->closePage(pageId);
		}

        
        break;
#endif

#ifdef __MMI_VCALENDAR__
	case VappComposerMainPage::ID_TOOLBAR_ADD_VTASK:		
        {
			VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
			VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
			VfxId  pageId = scr->getTopPageId(); 

			app->main->highlighted_object_type = SRV_UC_OBJECT_TYPE_ATTACHMENT;
			app->m_pbInsertState = UC_VCAL_CUI_STATE_INSERT_TASK;						
			
			scr->ucOpenCalenderList(VCUI_CAL_LIST_TASK);
			scr->closePage(pageId);
		}			
        break;
#endif /* __MMI_VCALENDAR__ */

#ifdef __MMI_VCALENDAR__
	case VappComposerMainPage::ID_TOOLBAR_ADD_VEVENT:
		{
			VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
			VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
			VfxId  pageId = scr->getTopPageId(); 

			app->main->highlighted_object_type = SRV_UC_OBJECT_TYPE_ATTACHMENT;
			app->m_pbInsertState = UC_VCAL_CUI_STATE_INSERT_EVENT;						
			
			scr->ucOpenCalenderList(VCUI_CAL_LIST_CALENDAR);
			scr->closePage(pageId);
			break;
		}
#endif /* __MMI_VCALENDAR__ */

    case VappComposerMainPage::ID_TOOLBAR_ADD_FILE:
		{
			VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
			VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
			VfxId  pageId = scr->getTopPageId(); 
			//scr->popPage();
			//getMainScr()->popPage();
			//app->m_signalConnectOnPage.connect(getMainScr(), &VappUCMainScr::connectOnPage);
			app->main->highlighted_object_type = SRV_UC_OBJECT_TYPE_ATTACHMENT;
			app->main->select_media_opt = UC_MEDIA_OPT_INSERT;
			scr->ucOpenGallery();
			scr->closePage(pageId);
		}
        break;

    case VappComposerMainPage::ID_TOOLBAR_CLEAR_ALL:
        // remove attachment list
        getMainScr()->popPage();
        break;

	case VappComposerMainPage::ID_COMMAND_ADD_SLIDE:
		app->ucEntryInsertSlide();
        //getMainScr()->popPage();
        app->changeMsgTypeIfNeeded();
		removeObjectFromPage(ID_INLINE_SLIDE_BAR);
        drawWithData();
		//insertSlideBarItem();
       // updateBottomMsgHint();
        if (textEditorBody)
        {
			textEditorBody->setAutoActivated(VFX_TRUE);
			highlightedEditor = textEditorBody;
        }
		break;

	case VappComposerMainPage::ID_COMMAND_REMOVE_SLIDE:
		app->ucEntryDeleteSlide();
		removeObjectFromPage(ID_INLINE_SLIDE_BAR);
		//insertSlideBarItem();
        drawWithData();
		break;
        
#ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__  
	case VappComposerMainPage::ID_COMMAND_ADD_CC:
        m_itemForceOn |= ID_RECIPIENT_CC;
        app->main->m_itemForceOn |= UC_RECIPIENT_CC;
        app->changeMsgTypeIfNeeded();
        insertContactSelectorCc();
        updateBottomMsgHint();
        updateButtonBar();
        if (m_contactSelectorCc)
        {
			m_contactSelectorCc->getInputbox()->activate();
			highlightedEditor = m_contactSelectorCc->getInputbox();
        }
        break;

	case VappComposerMainPage::ID_COMMAND_ADD_BCC:
        m_itemForceOn |= ID_RECIPIENT_BCC;
        app->main->m_itemForceOn |= UC_RECIPIENT_BCC;
        app->changeMsgTypeIfNeeded();
        insertContactSelectorBcc();
        updateBottomMsgHint();
        updateButtonBar();
        if (m_contactSelectorBcc)
        {
			m_contactSelectorBcc->getInputbox()->activate();
			highlightedEditor = m_contactSelectorBcc->getInputbox();
        }
		break;

	case VappComposerMainPage::ID_COMMAND_REMOVE_CC:
		m_itemForceOn &= ~ID_RECIPIENT_CC;
        app->main->m_itemForceOn &=~UC_RECIPIENT_CC;
        app->ucRemoveRecipientByGroup(SRV_UC_ADDRESS_GROUP_TYPE_CC);
	   if(app->changeMsgTypeIfNeeded())
	   {
			updateBottomMsgHint();
			updateButtonBar();
	   }
		removeObjectFromPage(ID_RECIPIENT_CC);
        setEditorActivated();
		break;

	case VappComposerMainPage::ID_COMMAND_REMOVE_BCC:
		m_itemForceOn &= ~ID_RECIPIENT_BCC;
        app->main->m_itemForceOn &= ~UC_RECIPIENT_BCC;
        app->ucRemoveRecipientByGroup(SRV_UC_ADDRESS_GROUP_TYPE_BCC);
	   if(app->changeMsgTypeIfNeeded())
	   {
			updateBottomMsgHint();
			updateButtonBar();
	   }
		removeObjectFromPage(ID_RECIPIENT_BCC);
        setEditorActivated();
		break;
#endif
	case VappComposerMainPage::ID_COMMAND_SELECT_PICTURE_FROM_GALLERY:
		{
			VfxId  pageId = scr->getTopPageId(); 
			//scr->popPage();
		//	app->m_signalConnectOnPage.connect(scr, &VappUCMainScr::connectOnPage);
			app->main->highlighted_object_type = SRV_UC_OBJECT_TYPE_IMAGE;
			app->main->select_media_opt = UC_MEDIA_OPT_INSERT;
			scr->ucOpenGallery();
#ifndef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__
			scr->closePage(pageId);
#endif
		}
		break;
		
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
	case VappComposerMainPage::ID_COMMAND_SELECT_VIDEO_FROM_GALLERY:
		{
			VfxId  pageId = scr->getTopPageId(); 
				//scr->popPage(
			//app->m_signalConnectOnPage.connect(scr, &VappUCMainScr::connectOnPage);
			app->main->highlighted_object_type = SRV_UC_OBJECT_TYPE_VIDEO;
			app->main->select_media_opt = UC_MEDIA_OPT_INSERT;
			scr->ucOpenGallery();
        #if !defined(__MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__) || !defined(__MMI_COSMOS_UC_GALLERY_VIDEO_PICKER_SUPPORT__)
            scr->closePage(pageId);
        #endif

		}
		break;
#endif /* #ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__ */

	case VappComposerMainPage::ID_COMMAND_SELECT_AUDIO_FROM_GALLERY:
		{
			VfxId  pageId = scr->getTopPageId(); 
			//scr->popPage(
			//app->m_signalConnectOnPage.connect(scr, &VappUCMainScr::connectOnPage);
			app->main->highlighted_object_type = SRV_UC_OBJECT_TYPE_AUDIO;
			app->main->select_media_opt = UC_MEDIA_OPT_INSERT;
			scr->ucOpenGallery();
			scr->closePage(pageId);
		}
		break;

#ifdef __MMI_CAMCORDER__
	case VappComposerMainPage::ID_COMMAND_TAKE_PICTURE:
#ifdef __MMI_UCM__
	//	if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
		{
	//		mmi_ucm_app_entry_error_message();
		}
	//	else
#endif /* __MMI_UCM__ */  
		{
			VfxId  pageId = scr->getTopPageId();
			app->main->highlighted_object_type = SRV_UC_OBJECT_TYPE_IMAGE;
			app->main->select_media_opt = UC_MEDIA_OPT_INSERT;
		//	app->m_signalConnectOnPage.connect(getMainScr(), &VappUCMainScr::connectOnPage);
			scr->ucEnterMultimediaApp();
			scr->closePage(pageId);
		}
		break;
#endif

#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
#if defined(__MMI_CAMCORDER__)
	case VappComposerMainPage::ID_COMMAND_TAKE_VIDEO:

#ifdef __MMI_UCM__
	//	if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
		{
	//		mmi_ucm_app_entry_error_message();
		}
	//	else
#endif /* __MMI_UCM__ */  
		{
			VfxId  pageId = scr->getTopPageId();
			app->main->highlighted_object_type = SRV_UC_OBJECT_TYPE_VIDEO;
			app->main->select_media_opt = UC_MEDIA_OPT_INSERT;
		//	app->m_signalConnectOnPage.connect(getMainScr(), &VappUCMainScr::connectOnPage);
			scr->ucEnterMultimediaApp();
			scr->closePage(pageId);
		}
		break;
#endif
#endif

#ifdef __MMI_SOUND_RECORDER__
	case VappComposerMainPage::ID_COMMAND_TAKE_AUDIO:
		{
			VfxId  pageId = scr->getTopPageId(); 
		    app->main->highlighted_object_type = SRV_UC_OBJECT_TYPE_AUDIO;
		    app->main->select_media_opt = UC_MEDIA_OPT_INSERT;
    #ifdef __MMI_UCM__
	    //	if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
		    {
	    //		mmi_ucm_app_entry_error_message();
		    }
	    //	else
    #endif /* __MMI_UCM__ */  
		    {
			    scr->ucEnterMultimediaApp();
		    }
			scr->closePage(pageId);
        }
		break;
#endif
    case VappComposerMainPage::ID_COMMAND_SAVE_AS_DRAFT:
  #if defined(__MMI_MESSAGES_TEMPLATE__) || defined(__MMI_MMS_TEMPLATE_SUPPORT__)    
    case VappComposerMainPage::ID_COMMAND_SAVE_AS_TEMPLATE:
  #endif      
        {
            //srv_uc_action_type_enum action = SRV_UC_ACTION_SAVE;
            VFX_OBJ_CREATE(m_popup,VcpIndicatorPopup,this);
            m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
            m_popup->setText(VFX_WSTR_RES(STR_GLOBAL_SAVING));
            m_popup->setAutoDestory(VFX_FALSE);
            m_popup->show(VFX_TRUE);

			VappUcTextInfoStruct new_text_info = {0,};
			app->ucGetTextInfoForBuffer(&new_text_info, (U8*)app->m_service_cntxt->main->text_buffer);
			app->ucTextChangeHandler(&new_text_info);
			app->ucHandleTextInCurrentSlide();
            app->m_signalConnectToCloseProgress.connect(getMainScr(), &VappUCMainScr::connectToCloseProgress);
            app->m_signalConnectOnError.connect(getMainScr(), &VappUCMainScr::connectToClose);
          #if defined(__MMI_MESSAGES_TEMPLATE__) || defined(__MMI_MMS_TEMPLATE_SUPPORT__)   
            if(id == ID_COMMAND_SAVE_AS_DRAFT)
          #endif  
            {
                /* In template, do not save the recipient data */
                getRecipientFromBuffer();
                app->m_service_cntxt->send_info->action = SRV_UC_ACTION_SAVE;
            }
          #if defined(__MMI_MESSAGES_TEMPLATE__) || defined(__MMI_MMS_TEMPLATE_SUPPORT__) 
            else
            {
                srv_uc_delete_all_addr(app->main->instance);
                //app->m_service_cntxt->main->action = SRV_UC_ACTION_SAVE_AS_TEMPLATE;
                app->m_service_cntxt->send_info->action = SRV_UC_ACTION_SAVE_AS_TEMPLATE;
            }
          #endif  
			app->saveMessage();
        break;
        }
#if defined(__MMI_MESSAGES_TEMPLATE__)    
	case VappComposerMainPage::ID_COMMAND_INSERT_TEMPLATE:
		{
			VappTextTemplateListPage *templatePage = NULL;
			VFX_OBJ_CREATE(templatePage, VappTextTemplateListPage, this);
            templatePage->m_signalTemplateTapped.connect(this, &VappComposerMainPage::onSmsTemplateClicked);
			getMainScr()->pushPage(0, templatePage);
		break;
		}
#endif
#if defined(__MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__)
	case VappComposerMainPage::ID_COMMAND_INSERT_EMOTICON:
		{
            VappUcEmoticon *emoticonPage = NULL;
            VFX_OBJ_CREATE_EX(emoticonPage, VappUcEmoticon, this, (IMG_ID_VAPP_UC_EMOTIC_1_ID, UC_EMOTICON_ICON_COUNT, textIconTable));
 			emoticonPage->m_signalcallback.connect(this, &VappComposerMainPage::onEmoticonSelect);
            emoticonPage->show(VFX_TRUE);
		break;
		}
#endif
    case VappComposerMainPage::ID_TOOLBAR_CANCEL:
        {
			app->main->skip_save_on_deinit = VFX_TRUE;
            getMainScr()->popPage();
            break;
        }
	case ID_TOOLBAR_PREV:
	case ID_TOOLBAR_NEXT:
		{
			VcpTextEditor* h_editor = NULL;
			VcpFunctionBar*  functionBar = (VcpFunctionBar*)obj;
			h_editor = getNextEditorFromFunctionBar(functionBar, id);
			if(h_editor)
			{
				h_editor->activate();
				highlightedEditor = h_editor;
			}
			break;
		}
    default:
            break;
    }
}

#if defined(__MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__)
void VappComposerMainPage::onEmoticonSelect(VfxObject *object, VfxU32 index)
{
	// Insert text
	if (index <= UC_EMOTICON_ICON_COUNT)
	{
		VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
		VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
		VappUcTextInfoStruct new_text_info = {0,};
		VfxBool result = VFX_TRUE;

	    app->ucGetTextInfoForBuffer(&new_text_info, (U8*)(textIconTable[index].text));
        new_text_info.char_count += app->m_service_cntxt->msg->msg_body.curr_slide->txt.char_count;
        new_text_info.utf8_msg_len += app->m_service_cntxt->msg->msg_body.curr_slide->txt.utf8_msg_len;
        new_text_info.extension_char_count += app->m_service_cntxt->msg->msg_body.curr_slide->txt.extension_char_count;
        new_text_info.UCS2_count += app->m_service_cntxt->msg->msg_body.curr_slide->txt.UCS2_count;

	    result = app->ucCharInputHandler(&new_text_info);
       
//		app->vappUcGetMaxTextCharCount();
		if(result)
		{
            textEditorBody->disableAutoCap();
		    insertTextStringOneGo((WCHAR*)(textIconTable[index].text), VFX_FALSE);
		}
		else
		{
			mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_GLOBAL_NOT_ENOUGH_MEMORY)).getBuf());		
		}
	}
}
#endif
/*****************************************************************************
 * Class VcuiUcMainCui implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VcuiUcMainCui", VcuiUcMainCui, VfxCui);

extern VappUcContainerStruct g_app;

void VcuiUcMainCui::onRun(void* args, VfxU32 argSize)
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_ON_RUN);
    VfxApp::onRun(args, argSize);
	temp_flag = g_app.temp_flag; /* To be removed on 11.05 */
	g_app.temp_flag = VFX_FALSE;
    if(handleData(args, argSize))
    {
        VFX_OBJ_CREATE(m_scr, VappUCMainScr, this);
        m_scr->show();
        m_app_data->m_signalShowConfirm.connect(m_scr, &VappUCMainScr::vappUcShowConfirm);
        if(m_app_data->main->confirm_handler)
        {
            m_app_data->m_signalShowConfirm.postEmit(STR_ID_VAPP_UC_WARNING_MODE_CONFIRM);
        }
    }
}

#ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__  

void VcuiUcMainCui::onGroupInactive()
{
    VFX_ASSERT(m_app_data != NULL);
    
/*    if( m_app_data->main->cui_type == UC_CUI_GALLERY_IMG_PCKR ||
        m_app_data->main->cui_type == UC_CUI_GALLERY_VIDEO_PCKR ||
        m_app_data->main->cui_type == UC_CUI_VIDEO_PLAYER
      )
    {
        VfxApp::serialize();
    } */
    
    VfxApp::onGroupInactive();
}

void VcuiUcMainCui::onSerialize(void *hint, VfxArchive &archive)
{
    handleDataOnSerialize(hint, archive);
}

void VcuiUcMainCui::onRestore(VfxArchive &archive)
{
    VfxBool close_uc;
    
    m_isInRestore = VFX_TRUE;
        
    if(handleDataOnRestore(archive))
    {
        VappUcAppDataAfterSerialize *app = &(g_uc_app_data_serialized[m_app_data->main->instance]);
        close_uc = onProcBeforeRestore( &(app->cui_result) );

        if( close_uc == VFX_FALSE )
        {
            VFX_OBJ_CREATE(m_scr, VappUCMainScr, this);
            m_scr->show();
            m_app_data->m_signalShowConfirm.connect(m_scr, &VappUCMainScr::vappUcShowConfirm);
            if(m_app_data->main->confirm_handler)
            {
                m_app_data->m_signalShowConfirm.postEmit(STR_ID_VAPP_UC_WARNING_MODE_CONFIRM);
            }

            vfxPostInvoke1(this, &VcuiUcMainCui::onProcAfterRestore, &(app->cui_result) ); 
        }
    }

   
    
}
#endif /* __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__ */  


/*****************************************************************************
 * Global Function
 *****************************************************************************/
/*
VtstTestResultEnum vtst_UC_Main_entry(VfxU32 param)
{
    VFX_UNUSED(param);
    VfxAppLauncher::launchWithAsmSize(
        APP1_BASE,
        VFX_OBJ_CLASS_INFO(VcuiUcMainCui),
        GRP_ID_ROOT, 204800 * 1,
        NULL, 0);
   return VTST_TR_OK;
} */

extern "C" VappUcEntryStruct* dummy_get_entry_struct(U32 msg_id, U16 msg_type, vappUcMsgOperationEnum operation)
{
    VappUcEntryStruct *data;
    VFX_SYS_ALLOC_MEM(data, sizeof(VappUcEntryStruct));
    memset(data, 0, sizeof(VappUcEntryStruct));
    data->msg_id = msg_id;
    data->info_type = (srv_uc_info_type_enum)msg_type;
    data->operation = operation;
    return data;
}


extern "C" VappUcEntryStruct* dummy_get_entry_struct_from_with_content_api(srv_uc_state_enum type, void *start_data)
{
    VappUcEntryStruct *new_data;
    vapp_uc_entry_write_struct *data = (vapp_uc_entry_write_struct *)start_data;
    VFX_SYS_ALLOC_MEM(new_data, sizeof(VappUcEntryStruct));
    memset(new_data, 0, sizeof(VappUcEntryStruct));
    new_data->type = type;
    new_data->info_type = (srv_uc_info_type_enum)data->msg_type;

    U32 flie_path_len = mmi_ucs2strlen((S8*) data->file_path);
    VFX_SYS_ALLOC_MEM(new_data->file_path, (flie_path_len + 1) * ENCODING_LENGTH);
    mmi_ucs2ncpy((S8*) new_data->file_path, (S8*) data->file_path, flie_path_len);
    return new_data;
}

extern "C" VappUcEntryStruct* dummy_get_entry_struct_from_uc_maunch_api(srv_uc_start_struct *msg_req)
{
    VappUcEntryStruct *data;
    VFX_SYS_ALLOC_MEM(data, sizeof(VappUcEntryStruct));
    memset(data, 0, sizeof(VappUcEntryStruct));
    
    data->app_id = msg_req->app_id;          /* Application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
    data->mode = msg_req->mode;            /* mma_app_mode_enum */
    data->msg_id = msg_req->msg_id;         /* msg id */
    data->edit_mode = msg_req->edit_mode;       /* srv_uc_MMS_edit_mode_enum */
    data->sim_id = (srv_uc_sim_id)msg_req->sim_id;          /* srv_uc_sim_id */
    data->curr_storage = msg_req->curr_storage;    /* message stored on? */
    data->info_type = SRV_UC_INFO_TYPE_MMS;

    return data;
}

extern "C" void dummy_free_entry_struct(VappUcEntryStruct *data)
{
    VFX_SYS_FREE_MEM(data);
}


VfxBool VappAttachmentInfoListMenuContentProvider::getItemText(
    VfxU32 index,                    
    VcpListMenuFieldEnum fieldType,  
    VfxWString &text,                
    VcpListMenuTextColorEnum &color  
    )
{
    if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        //text = VFX_WSTR("Did you see this by chance");
        text = VFX_WSTR_MEM((const VfxWChar *)m_attachmentSizeList[index]);
        color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
    }
	else if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
		text = VFX_WSTR_MEM((const VfxWChar *)attachmentList[index]);
    }

	return VFX_TRUE;
}

VfxBool VappAttachmentInfoListMenuContentProvider::getItemImage(
    VfxU32 index,                    
    VcpListMenuFieldEnum fieldType,  
    VfxImageSrc &image         
    ) 
{
    if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL ||
           fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED ||
           fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT) 
           // For VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, 
           // to set different images for disabled and highlight states if need,
           // in this sample, just set same images as normal state
    {
            image.setResId(IMG_ID_VAPP_UC_BTN_DELETE);
            return VFX_TRUE; // Required if set the image successfully
    }
    if (fieldType == VCP_LIST_MENU_FIELD_ICON)
    {
		if(appModeEmail)
		{
			image.setResId(srv_fmgr_types_get_icon(srv_fmgr_types_find_type_by_filename_str((VfxWChar*)attachmentList[index]), NULL, SRV_FMGR_TYPES_ICON_LARGE));
		}
		else
		{
            image.setResId(vapp_get_icon_according_to_media_type((VfxWChar *)attachmentList[index]));
		}
    }

   return VFX_TRUE;
}

VfxU32 VappAttachmentInfoListMenuContentProvider::getCount() const 
{
	return attachmentCount;
}

VFX_IMPLEMENT_CLASS("VAppUcAttachmentlistPage", VAppUcAttachmentlistPage, VfxPage);

VappAttachmentInfoListMenuContentProvider::VappAttachmentInfoListMenuContentProvider()
{
    memset(attachmentList, 0, sizeof(attachmentList));
    memset(m_attachmentSizeList, 0, sizeof(m_attachmentSizeList));
   // VfxWChar tempList[3][255] = {0,};
    //vapp_uc_frm_get_attachment_item_list(attachmentList, m_attachmentSizeList);
	//vfx_sys_wcscpy((VfxWChar*)&(attachmentList[0][0]), (VfxWChar*)tempList[0]);
	//vfx_sys_wcscpy((VfxWChar*)&(attachmentList[1][0]), (VfxWChar*)tempList[1]);
	//vfx_sys_wcscpy((VfxWChar*)&(attachmentList[2][0]), (VfxWChar*)tempList[2]);
	attachmentCount = 0;
}

void VAppUcAttachmentlistPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
    // do nothing
}

void VAppUcAttachmentlistPage::setBounds(const VfxRect &value)
{
	VfxPage::setBounds(value);
	if (attahmentList)
	{
		this->attahmentList->setSize(value.size.width, value.size.height);
	}
}
void VAppUcAttachmentlistPage::onEnter(VfxBool isbackward)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

void VAppUcAttachmentlistPage::onDeleteTab( VcpListMenu *lst, VfxU32 index)
{
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);

    app->VappUCRemoveAttachment(index);
    app->ucGetAttachmentItemList(m_listMenuContentProviderForAttachment->attachmentList, m_listMenuContentProviderForAttachment->m_attachmentSizeList, &m_listMenuContentProviderForAttachment->attachmentCount);
    if (m_listMenuContentProviderForAttachment->attachmentCount > 0)
    {
	    
        VcpToolBar* attachmentToolBar = VFX_OBJ_DYNAMIC_CAST(this->getBar(VFX_PAGE_BAR_LOCATION_BOTTOM), VcpToolBar); 

		attahmentList->setContentProvider(m_listMenuContentProviderForAttachment);
	    attahmentList->updateAllItems();
	    scr->getComposerPage()->insertAttachment();
		/*Enable toolbar botton*/
		if (attachmentToolBar != NULL)
		{
			attachmentToolBar->setDisableItem(VappComposerMainPage::ID_TOOLBAR_ADD_ATTACHMENTS, VFX_FALSE);
		}	
    }
    else
    {
	    scr->getComposerPage()->insertAttachment();
	    scr->getComposerPage()->updateBottomMsgHint();
	    scr->getComposerPage()->updateButtonBar();
       scr->popPage();
    }
}
void VAppUcAttachmentlistPage::onInit()
{
	VfxPage::onInit(); 

	VcpTitleBar* titleBar;
    VcpToolBar* attachmentToolBar;

	VfxXmlLoader::loadBegin(this, VENUS_COMPOSER_ATTACHMENT_LIST_PAGE);

    titleBar = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("titleBar")), VcpTitleBar); 
    titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_UC_ATTACHMENT_LIST_ID));    // set title text
    setTopBar(titleBar); 

    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
	attahmentList = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("attahmentList")), VcpListMenu);

	attahmentList->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
								VFX_FRAME_ALIGNER_MODE_NONE, 
								VFX_FRAME_ALIGNER_MODE_NONE,
								VFX_FRAME_ALIGNER_MODE_NONE);


	VFX_OBJ_CREATE(m_listMenuContentProviderForAttachment, VappAttachmentInfoListMenuContentProvider, attahmentList);
    app->ucGetAttachmentItemList(m_listMenuContentProviderForAttachment->attachmentList, m_listMenuContentProviderForAttachment->m_attachmentSizeList, &m_listMenuContentProviderForAttachment->attachmentCount);
 #ifdef __MMI_EMAIL__
   if (app->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
    {
		m_listMenuContentProviderForAttachment->appModeEmail = VFX_TRUE;
    }
   else
#endif
   {
		m_listMenuContentProviderForAttachment->appModeEmail = VFX_FALSE;
   }
    attahmentList->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_FALSE); // Set command button control mode
    attahmentList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT); // Set command button control mode

    // Conncect the required signal
    attahmentList->m_signalCmdButtonClicked.connect(this, &VAppUcAttachmentlistPage::onDeleteTab); // For the command button click
	 attahmentList->setContentProvider(m_listMenuContentProviderForAttachment);
	 attahmentList->m_signalItemTapped.connect(this, &VAppUcAttachmentlistPage::onTap);
    VFX_OBJ_CREATE(attachmentToolBar,VcpToolBar,this);
    attachmentToolBar->addItem(VappComposerMainPage::ID_TOOLBAR_ADD_ATTACHMENTS, VFX_WSTR_RES(STR_ID_VAPP_UC_ADD_ATTACHMENTS_ID	), IMG_ID_VAPP_UC_ADD_FILE_ID); // add tool bar "cancel" button

	if (app->m_service_cntxt->msg->msg_body.total_attach_no == app->vappUcGetMaxAttachemntCount())
	{
		attachmentToolBar->setDisableItem(VappComposerMainPage::ID_TOOLBAR_ADD_ATTACHMENTS, VFX_TRUE);
	}
    //attachmentToolBar->m_signalButtonTap.connect(scr->getComposerPage(), &VappComposerMainPage::onToolBarClick);          // connect tool bar signal
    attachmentToolBar->m_signalButtonTap.connect(this, &VAppUcAttachmentlistPage::onToolBarClick);          // connect tool bar signal
    
    setBottomBar(attachmentToolBar);

    VfxXmlLoader::loadEnd();
}


void VAppUcAttachmentlistPage::onToolBarClick(VfxObject* obj, VfxId id)
{
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    switch(id)
    {
    case VappComposerMainPage::ID_TOOLBAR_ADD_ATTACHMENTS:
    {
        VcpCommandPopup *m_commandPopup;
        VFX_OBJ_CREATE(m_commandPopup, VcpCommandPopup, this);
        m_commandPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_UC_ADD_ATTACHMENTS_ID));
#if defined(__MMI_VCARD__)
        m_commandPopup->addItem(VappComposerMainPage::ID_TOOLBAR_ADD_VCARD, VFX_WSTR_RES(STR_ID_VAPP_UC_VCARD));
#endif
#if defined(__MMI_VCALENDAR__)
        m_commandPopup->addItem(VappComposerMainPage::ID_TOOLBAR_ADD_VEVENT, VFX_WSTR_RES(STR_ID_VAPP_UC_VEVENT)); 
        m_commandPopup->addItem(VappComposerMainPage::ID_TOOLBAR_ADD_VTASK, VFX_WSTR_RES(STR_ID_VAPP_UC_VTASK)); 
#endif        
        m_commandPopup->addItem(VappComposerMainPage::ID_TOOLBAR_ADD_FILE, VFX_WSTR_RES(STR_ID_VAPP_UC_FILE));
        m_commandPopup->addItem(0xFFFF, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);         
    
        m_commandPopup->setAutoDestory(VFX_TRUE);
        m_commandPopup->m_signalButtonClicked.connect(scr->getComposerPage(), &VappComposerMainPage::onToolBarClick); 
        m_commandPopup->show(VFX_TRUE);
    }
        break;

    default:
        break;
    }
}
    

VfxBool VAppUcAttachmentlistPage::onKeyInput(VfxKeyEvent& event)
{
	if(event.keyCode == VFX_KEY_CODE_RSK && event.type == VFX_KEY_EVENT_TYPE_DOWN)
	{
		getMainScr()->popPage();
		return VFX_TRUE;
	}
	return VfxPage::onKeyInput(event);
}

void VAppUcAttachmentlistPage::onTap(VcpListMenu *listMenu, VfxU32 itemIndex)
{
	VappUCMainScr* scr = (VappUCMainScr*)getMainScr();

    scr->VappUCPreviewAttachment(itemIndex);
}

VappTestInsertMenuListPage::VappTestInsertMenuListPage():m_list(NULL)
{
    VfxU16 itemGStrList[20] = {0,};
    VfxU16 itemGIDList[20] = {0,};
    VfxU16 itemStrList[20] = {0,};
    VfxU16 itemIDList[20] = {0,};
	VfxU16 numChild = 0;
    S32 countG = 0, countM = 0, count = 0;

    memset(numberInsertGroups, 0, sizeof(numberInsertGroups));//[] = {0,};
    memset(strMenu, 0, sizeof(strMenu));//[][]= {0,};
    memset(strInsertGroups, 0, sizeof(strInsertGroups));//[][] = {0,};
    m_insert_group_count = 0;


    GetSequenceStringIds_Ext(MENU_ID_VUC_OPT_INSERT, itemGStrList);
    GetSequenceItemIds_Ext(MENU_ID_VUC_OPT_INSERT, itemGIDList);

    for(countG = 0; countG< GetNumOfChild_Ext(MENU_ID_VUC_OPT_INSERT); countG++)
    {
        GetSequenceStringIds_Ext(itemGIDList[countG], itemStrList);
        GetSequenceItemIds_Ext(itemGIDList[countG], itemIDList);
		numChild = GetNumOfChild_Ext(itemGIDList[countG]);
        for(countM = 0; countM< numChild; countM++)
        {			
            strMenu[count][0] = itemIDList[countM];
            strMenu[count][1] = itemStrList[countM];
            strInsertGroups[m_insert_group_count][1] = itemGStrList[countG];
            strInsertGroups[m_insert_group_count][0] = itemGIDList[countG];
            
            count++;
        }

		if(numChild > 0)
		{
			numberInsertGroups[m_insert_group_count] = numChild;
			m_insert_group_count++;			  
		}
    }
}

VFX_IMPLEMENT_CLASS("VappTestInsertMenuListPage", VappTestInsertMenuListPage, VfxPage);

void VappTestInsertMenuListPage::onInit()
{
	VcpTitleBar *titleBar = NULL;
    VfxPage::onInit();

// Load group list menu form xml
	VfxXmlLoader::loadBegin(this, VENUS_COMPOSER_INSERT_MENU_LIST_PAGE);
	
	titleBar = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("menutitleBar")), VcpTitleBar);
    setTopBar(titleBar);
	m_list = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("m_list")), VcpGroupListMenu);
	
   m_list->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
               VFX_FRAME_ALIGNER_MODE_NONE,
               VFX_FRAME_ALIGNER_MODE_SIDE,
               VFX_FRAME_ALIGNER_MODE_NONE);
    
	VfxXmlLoader::loadEnd();

	setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN)); 

    
    m_list->setContentProvider(this);

	m_list->m_signalItemTapped.connect(this, &VappTestInsertMenuListPage::OnListFocused);
	VfxKeypad::registerHandler(VFX_KEY_CODE_RSK, this);
}

void VappTestInsertMenuListPage::setBounds(const VfxRect &value)
{
	VfxPage::setBounds(value);
	if (m_list)
	{
		this->m_list->setSize(value.size.width, value.size.height);
	}
}

void VappTestInsertMenuListPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
    // do nothing
}


VfxBool VappTestInsertMenuListPage::onKeyInput(VfxKeyEvent& event)
{
	if(event.keyCode == VFX_KEY_CODE_RSK && event.type == VFX_KEY_EVENT_TYPE_DOWN)
	{
		getMainScr()->popPage();
		return VFX_TRUE;
	}
	return VfxPage::onKeyInput(event);
}

void VappTestInsertMenuListPage::OnListFocused(VcpGroupListMenu * sender, // Sender
        VcpMenuPos new_pos        // Current focus list item index
		)
{
	if(sender == m_list)
	{
		if(new_pos.pos!=0xffffffff)
		{
		    VfxS32 number = 0, index;
			VappUCMainScr* scr = (VappUCMainScr*)getMainScr();

		    for(index = 0; index <new_pos.group; index++)
			    number += numberInsertGroups[index];
			switch(strMenu[number+new_pos.pos][0])
            {
#if (defined(__MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__))	
				case MENU_ID_VUC_OPT_INSERT_EMOTICON:
                    {						
						VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
						VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
						VfxId  pageId = scr->getTopPageId(); 
						scr->getComposerPage()->onToolBarClick(NULL, VappComposerMainPage::ID_COMMAND_INSERT_EMOTICON);

						scr->closePage(pageId);
                    }
					break;
#endif /* __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__ */
#if defined(__MMI_MESSAGES_TEMPLATE__)                      
				case MENU_ID_VUC_OPT_INSERT_TEMPLATE:
                    {						
						VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
						VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
						VfxId  pageId = scr->getTopPageId(); 
						scr->closePage(pageId);
						scr->getComposerPage()->onToolBarClick(NULL, VappComposerMainPage::ID_COMMAND_INSERT_TEMPLATE);

						//scr->closePage(pageId);
                    }
					break;
#endif /* __MMI_MESSAGES_TEMPLATE__ */
#if (!defined(__LOW_COST_SUPPORT_COMMON__))
	            case MENU_ID_VUC_OPT_IMAGE_OPTIONS:
				{
					VcpCommandPopup *m_commandPopup;
					VFX_OBJ_CREATE(m_commandPopup, VcpCommandPopup, findScreen());
					m_commandPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_UC_ADD_PICTURE_ID));
					m_commandPopup->addItem(VappComposerMainPage::ID_COMMAND_SELECT_PICTURE_FROM_GALLERY, VFX_WSTR_RES(STR_ID_VAPP_UC_ADD_MY_PICTURES_ID));
#ifdef __MMI_CAMCORDER__
					m_commandPopup->addItem(VappComposerMainPage::ID_COMMAND_TAKE_PICTURE, VFX_WSTR_RES(STR_ID_VAPP_UC_TAKE_PICTURE_ID));
#endif
					m_commandPopup->addItem(0xFFFF, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
        			
					m_commandPopup->m_signalButtonClicked.connect(scr->getComposerPage(), &VappComposerMainPage::onToolBarClick); 
					m_commandPopup->setAutoDestory(VFX_TRUE);
					m_commandPopup->show(VFX_TRUE);
				}
				break;
#else

		        case MENU_ID_VUC_OPT_INSERT_IMAGE:
				{
						VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
						VfxId  pageId = scr->getTopPageId(); 
						scr->getComposerPage()->onToolBarClick(NULL, VappComposerMainPage::ID_COMMAND_SELECT_PICTURE_FROM_GALLERY);
				#ifndef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__
						scr->closePage(pageId);
				#endif

				}
			    break;
#endif

#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
#if (!defined(__LOW_COST_SUPPORT_COMMON__))    	
		        case MENU_ID_VUC_OPT_VIDEO_OPTIONS:
				{
					VcpCommandPopup *m_commandPopup;
					VFX_OBJ_CREATE(m_commandPopup, VcpCommandPopup, findScreen());
					m_commandPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_UC_ADD_VIDEO_ID));

                #ifdef __MMI_COSMOS_UC_GALLERY_VIDEO_PICKER_SUPPORT__	
					m_commandPopup->addItem(VappComposerMainPage::ID_COMMAND_SELECT_VIDEO_FROM_GALLERY, VFX_WSTR_RES(STR_ID_VAPP_UC_ADD_MY_VIDEOS_ID));
                #else
                    m_commandPopup->addItem(VappComposerMainPage::ID_COMMAND_SELECT_VIDEO_FROM_GALLERY, VFX_WSTR_RES(STR_ID_VAPP_UC_ADD_VIDEOS_FROM_FMGR_ID));
                #endif


#ifdef __MMI_CAMCORDER__
					m_commandPopup->addItem(VappComposerMainPage::ID_COMMAND_TAKE_VIDEO, VFX_WSTR_RES(STR_ID_VAPP_UC_RECORD_VIDEO_ID));
#endif
					m_commandPopup->addItem(0xFFFF, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
        			
					m_commandPopup->m_signalButtonClicked.connect(scr->getComposerPage(), &VappComposerMainPage::onToolBarClick); 
					m_commandPopup->setAutoDestory(VFX_TRUE);
					m_commandPopup->show(VFX_TRUE);
				}
					break;
#else
		        case MENU_ID_VUC_OPT_INSERT_VIDEO:
				{
						VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
						VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
						VfxId  pageId = scr->getTopPageId(); 
						scr->getComposerPage()->onToolBarClick(NULL, VappComposerMainPage::ID_COMMAND_SELECT_VIDEO_FROM_GALLERY);
    				#if !defined(__MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__) || !defined(__MMI_COSMOS_UC_GALLERY_VIDEO_PICKER_SUPPORT__)
                        scr->closePage(pageId);
    				#endif

				}
			    break;
#endif /*  __LOW_COST_SUPPORT_COMMON__ */
#endif /* #ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__ */

#ifdef __MMI_SOUNDREC_CUI__
		        case MENU_ID_VUC_OPT_AUDIO_OPTIONS:
				{
					VcpCommandPopup *m_commandPopup;
					VFX_OBJ_CREATE(m_commandPopup, VcpCommandPopup, findScreen());
					m_commandPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_UC_ADD_SOUND_ID));
					m_commandPopup->addItem(VappComposerMainPage::ID_COMMAND_SELECT_AUDIO_FROM_GALLERY, VFX_WSTR_RES(STR_ID_VAPP_UC_ADD_MY_SOUNDS_ID));
					m_commandPopup->addItem(VappComposerMainPage::ID_COMMAND_TAKE_AUDIO, VFX_WSTR_RES(STR_ID_VAPP_UC_RECORD_SOUND_ID));
					m_commandPopup->addItem(0xFFFF, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
        		
					m_commandPopup->m_signalButtonClicked.connect(scr->getComposerPage(), &VappComposerMainPage::onToolBarClick); 
					m_commandPopup->setAutoDestory(VFX_TRUE);
					m_commandPopup->show(VFX_TRUE);
				}
			    break;
#else /* __MMI_SOUNDREC_CUI__ */
		        case MENU_ID_VUC_OPT_INSERT_AUDIO:
				{
    				VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
    				VfxId  pageId = scr->getTopPageId(); 
    				scr->getComposerPage()->onToolBarClick(NULL, VappComposerMainPage::ID_COMMAND_SELECT_AUDIO_FROM_GALLERY);

    				scr->closePage(pageId);
				}
			    break;
#endif /* __MMI_SOUNDREC_CUI__ */
#if defined(__MMI_VCARD__)
                case MENU_ID_VUC_INSERT_VCARD:
                    {
						/*Launch Phone book to select the vcard contact*/
						VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
						VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
						VfxId  pageId = scr->getTopPageId(); 
						//app->m_signalConnectOnPage.connect(getMainScr(), &VappUCMainScr::connectOnPage);

						app->main->highlighted_object_type = SRV_UC_OBJECT_TYPE_ATTACHMENT;
						app->m_pbInsertState = UC_PB_CUI_STATE_INSERT_VCARD;						
						
						scr->ucOpenPhoneBook(VFX_FALSE, MMI_PHB_CONTACT_FIELD_NAME | MMI_PHB_CONTACT_FIELD_NUMBER | MMI_PHB_CONTACT_FIELD_EMAIL);
						scr->closePage(pageId);
                    }
                    break;
#endif

#ifdef __MMI_VCALENDAR__
                case MENU_ID_VUC_INSERT_VTASK:
					{					
						VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
						VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
						VfxId  pageId = scr->getTopPageId(); 

						app->main->highlighted_object_type = SRV_UC_OBJECT_TYPE_ATTACHMENT;
						app->m_pbInsertState = UC_VCAL_CUI_STATE_INSERT_TASK;						
						
						scr->ucOpenCalenderList(VCUI_CAL_LIST_TASK);
						scr->closePage(pageId);
					}
					break;
#endif /* __MMI_VCALENDAR__ */

#ifdef __MMI_VCALENDAR__
				case MENU_ID_VUC_INSERT_VEVENT:
                    {						
						VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
						VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
						VfxId  pageId = scr->getTopPageId(); 

						app->main->highlighted_object_type = SRV_UC_OBJECT_TYPE_ATTACHMENT;
						app->m_pbInsertState = UC_VCAL_CUI_STATE_INSERT_EVENT;						
						
						scr->ucOpenCalenderList(VCUI_CAL_LIST_CALENDAR);
						scr->closePage(pageId);
                    }
					break;
#endif /* __MMI_VCALENDAR__ */

                case MENU_ID_VUC_INSERT_FILE:
                    {
                            VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
                            VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
							VfxId  pageId = scr->getTopPageId(); 
                            app->main->highlighted_object_type = SRV_UC_OBJECT_TYPE_ATTACHMENT;
                            app->main->select_media_opt = UC_MEDIA_OPT_INSERT;
                            scr->ucOpenGallery();
							scr->closePage(pageId);
                    }
                    break;
					
			#ifdef __MMI_COSMOS_UC_INSERT_PHONE_NAME_ADD_SUPPORT__
            #if 0
/* under construction !*/
/* under construction !*/
            #endif        
                case MENU_ID_VUC_OPT_INSERT_PHB_NAME_AND_NUM:
				{

					VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
					VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
					VfxId  pageId = scr->getTopPageId(); 
					
					app->main->highlighted_object_type = SRV_UC_OBJECT_TYPE_TEXT;
					if (strMenu[number+new_pos.pos][0] == MENU_ID_VUC_OPT_INSERT_PHB_NAME_AND_NUM)
					{
						app->m_pbInsertState = UC_PB_CUI_STATE_INSERT_PHONE_NAME_AND_NUM;   // Should use some other variable
                        scr->ucOpenPhoneBook(VFX_FALSE, MMI_PHB_CONTACT_FIELD_NAME | MMI_PHB_CONTACT_FIELD_NUMBER);
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
/* under construction !*/
/* under construction !*/
                    #endif
					
					scr->closePage(pageId);
					break;
				}
			#endif	/* __MMI_COSMOS_UC_INSERT_PHONE_NAME_ADD_SUPPORT__ */

            #if defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__) && defined(BROWSER_SUPPORT)
                 case MENU_ID_VUC_OPT_INSERT_BOOKMARK:
                    {

                        VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
						VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
						VfxId  pageId = scr->getTopPageId(); 
						//app->m_signalConnectOnPage.connect(getMainScr(), &VappUCMainScr::connectOnPage);
						app->main->highlighted_object_type = SRV_UC_OBJECT_TYPE_TEXT;

						scr->ucSelectBookMark();
						scr->closePage(pageId);

                    }
                    break;
             #endif       
		        case MENU_ID_VUC_OPT_SLIDE_INSERT:
                    {
                        VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
                        VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
		                app->ucEntryInsertSlide();
                        scr->udateMessageSize();
                        getMainScr()->popPage();
                        app->changeMsgTypeIfNeeded();
						scr->connectOnPage();
                    }
                    break;
			}
		}
	}
}


VfxBool VappTestInsertMenuListPage::hasGroupHeader(VfxS32 group) const
{
#if (defined(__MMI_MESSAGES_TEMPLATE__) || defined(__MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__))
	if(group == 0)
	{
		return VFX_FALSE;
	}
	else
#endif
	{
		return VFX_TRUE;
	}
}


VfxBool VappTestInsertMenuListPage::getItemText(
    VcpMenuPos pos,                    // // [IN] the position of item
    VcpListMenuFieldEnum fieldType,    // [IN] the type of the field in the cell
    VfxWString &text,                  // [OUT] the text resource
    VcpListMenuTextColorEnum &color   // [OUT] the text color
    )
{
	if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
	{
		VfxS32 number = 0, index;
		for(index = 0; index <pos.group; index++)
			number += numberInsertGroups[index];
		text.loadFromRes(strMenu[number+pos.pos][1]);
	}
	else if(fieldType == VCP_LIST_MENU_FIELD_GROUP_HEADER_TEXT)
	{
		text.loadFromRes(strInsertGroups[pos.group][1]);
	}
    color = VCP_LIST_MENU_TEXT_COLOR_HIGHLIGHT;

	return VFX_TRUE;
}

// Get the item count of the a group
VfxU32 VappTestInsertMenuListPage::getCount(VfxU32 group) const
{
	return numberInsertGroups[group];
}

// Get the group count of the lis menu
VfxU32 VappTestInsertMenuListPage::getGroupCount() const
{
    return m_insert_group_count;//VAPP_INSERT_GROUP_NUMBER;
}
void VappUCMediaItem::VappUClaunchMediaApp(void)
{
	
	
    VappUCMainScr* scr = VFX_OBJ_DYNAMIC_CAST(VfxMainScr::findMainScr((VfxFrame*)getParent()), VappUCMainScr); 

    VfxBool is_virtual_file;
    if( this->m_object->is_virtual_file )
        is_virtual_file = VFX_TRUE;
    else
        is_virtual_file = VFX_FALSE;

	if (scr != NULL)
	{

		VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
		U16* filePath = NULL;

		if (is_virtual_file)
		{
			U16 length = (SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH;
			VFX_SYS_ALLOC_MEM(filePath,  length);
			app->ucGenerateFilePath(this->m_object, (U8*)filePath);
		}
		else
		{
			filePath = this->m_object->file_path_ucs;
		}

		switch (this->m_type)
		{
		case SRV_UC_OBJECT_TYPE_IMAGE:
			app->main->select_media_opt = UC_MEDIA_OPT_NONE;
			scr->ucOpenImageViewer(this->m_object->file_name_ucs, filePath);

			break;
		case SRV_UC_OBJECT_TYPE_AUDIO:
			scr->ucPlayAudioFile(this->m_object->file_name_ucs, filePath);
			break;
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
    #ifdef __MMI_COSMOS_UC_VIDEO_PREVIEW_SUPPORT__ 
		case SRV_UC_OBJECT_TYPE_VIDEO:
			app->main->select_media_opt = UC_MEDIA_OPT_NONE;
			scr->ucPlayVideoFile(this->m_object->file_name_ucs, filePath);
			break;
    #endif
#endif
		case SRV_UC_OBJECT_TYPE_TEXT:
			break;
		case SRV_UC_OBJECT_TYPE_ATTACHMENT:
			break;
		case SRV_UC_OBJECT_TYPE_REF:
			break;
		default:
			break;

		}

		if (is_virtual_file)
		{
			VFX_SYS_FREE_MEM(filePath);
		}
	}
	else
	{
		ASSERT(0);
	}
}

void VappUCMediaItem::onMediaBarClick(VfxObject* obj, VfxId id)
{
    
    VappUCMainScr* scr = VFX_OBJ_DYNAMIC_CAST(VfxMainScr::findMainScr((VfxFrame*)getParent()), VappUCMainScr); 
    VfxBool is_virtual_file;
    if( this->m_object->is_virtual_file )
        is_virtual_file = VFX_TRUE;
    else
        is_virtual_file = VFX_FALSE;

	if (scr->m_app_data->operation_type == UC_OPERATION_SEND_VCARD_AS_SMS ||
		scr->m_app_data->operation_type == UC_OPERATION_SEND_VCALENDAR_AS_SMS ||
		(scr->m_app_data->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_LEMEI_MMS))
	{
		U16* filePath = NULL;
		applib_mime_type_struct *mime = NULL;
		VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);

		if (is_virtual_file)
		{
			U16 length = (SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH;
			VFX_SYS_ALLOC_MEM(filePath,  length);
			app->ucGenerateFilePath(this->m_object, (U8*)filePath);
		}
		else
		{
			filePath = this->m_object->file_path_ucs;
		}

		mime = applib_mime_get_file_type(this->m_object->file_name_ucs);	

		if (mime != NULL )
		{
#ifdef __MMI_VCALENDAR__
			if (mime->mime_subtype == MIME_SUBTYPE_XVCALENDAR ||
					mime->mime_subtype == MIME_SUBTYPE_HBSVCS ||
					mime->mime_subtype == MIME_SUBTYPE_CALENDAR)
				{
					//Vcalendar
					scr->ucPreviewVcalendar(this->m_object->file_name_ucs, filePath);
				}
            else
#endif /* __MMI_VCALENDAR__ */
            {
#if defined(__MMI_VCARD__)		
    		    if (mime->mime_subtype == MIME_SUBTYPE_XVCARD ||
    				mime->mime_subtype == MIME_SUBTYPE_VCARD)
    			{
    				//Vcard
    				scr->ucPreviewVcard(this->m_object->file_name_ucs, filePath);
    			}
                else                     
#endif
                {
        			if(scr->m_app_data->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_LEMEI_MMS)
        			{
        				VappUClaunchMediaApp();
        			}
                }
            }
		}
		if (is_virtual_file)
		{
			VFX_SYS_FREE_MEM(filePath);
		}
	}
	else
	{
        VcpCommandPopup *atachMentOptionPopUp = NULL;
        VfxWString title;
        VappUCMediaItem* tempObj = (VappUCMediaItem*)obj->getParent();
    
        title.loadFromMem(tempObj->m_object->file_name_ucs);
    
        VFX_OBJ_CREATE(atachMentOptionPopUp, VcpCommandPopup, this);
        atachMentOptionPopUp->setText(title);
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
#if (!defined( __MMI_COSMOS_UC_VIDEO_PREVIEW_SUPPORT__))
    if( this->m_type != SRV_UC_OBJECT_TYPE_VIDEO)
#endif
#endif
    {
        atachMentOptionPopUp->addItem(VAPP_UC_MEDIA_PREVIEW_OPTION_ID, VFX_WSTR_RES(STR_GLOBAL_PREVIEW));
    }
        atachMentOptionPopUp->addItem(VAPP_UC_MEDIA_REMOVE_OPTION_ID, VFX_WSTR_RES(STR_GLOBAL_REMOVE));
        atachMentOptionPopUp->addItem(0xFFFF, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
    
        atachMentOptionPopUp->setAutoDestory(VFX_TRUE);
        atachMentOptionPopUp->m_signalButtonClicked.connect(this, &VappUCMediaItem::onClickCmdBtn);
        atachMentOptionPopUp->show(VFX_TRUE);
    }

    return;
}

void VappUCMediaItem::onClickCmdBtn(VfxObject *obj, VfxId index)
{
	
	
    VappUCMainScr* scr = VFX_OBJ_DYNAMIC_CAST(VfxMainScr::findMainScr((VfxFrame*)getParent()), VappUCMainScr); 
	if (scr != NULL)
	{
		VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
	    
		switch (index)
		{
			case VAPP_UC_MEDIA_PREVIEW_OPTION_ID:
				this->VappUClaunchMediaApp();
				break;
			case VAPP_UC_MEDIA_REMOVE_OPTION_ID:
				app->VappUCRemoveMedia(this->m_object);
				scr->connectOnPage();
			case VAPP_UC_MEDIA_CANCEL_OPTION_ID:
				break;
			default:
				break;
		}
	}
	else
	{
		ASSERT(0);
	}

}

void VappComposerMainPage::onContactListUpdate(VcpContactSelector *obj, VcpContactChangedEnum type)
{
    if(type == VCP_CONTACT_CHANGED_ADD || type == VCP_CONTACT_CHANGED_DELETE)
    {
	    
        VappUCMainScr* scr = VFX_OBJ_DYNAMIC_CAST(VfxMainScr::findMainScr((VfxFrame*)getParent()), VappUCMainScr); 
		if ( scr != NULL)
		{
			VappUcAppData* app = (VappUcAppData*)(scr->m_app_data);
            MMI_BOOL need_update_button_bar = MMI_FALSE;

			// Change UI and context
			getRecipientFromBufferByGroup(obj);
			need_update_button_bar = app->changeMsgTypeIfNeeded();
            if (app->m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
            {
                app->m_service_cntxt->main->mode = SRV_UC_FORWARD_WITH_EDIT_MODE;
            }            
			srv_uc_update_msg_size(app->main->instance);
		    updateBottomMsgHint();
            if(need_update_button_bar)
            {
                updateButtonBar();
            }
		}
		else
		{
			ASSERT(0);
		}
    }

}

VFX_IMPLEMENT_CLASS("VAppUcRecipientlistPage", VAppUcRecipientlistPage, VfxPage);

VappRecipientListContentProvider::VappRecipientListContentProvider()
{
	recipientCount = 0;
}

VfxBool VappRecipientListContentProvider::getItemText(
     VfxU32 index,                    
     VcpListMenuFieldEnum fieldType,  
     VfxWString &text,                
     VcpListMenuTextColorEnum &color  
     )
 {
         if(recipientCount > 0)
         {
             VcpContact *contact;
             VfxS32 count = 0;
			 VfxS32 max_Count = m_contactSelector->getContactCount();
             U16 string[100] = {0,};

             contact = m_contactSelector->getContactList();

             for (count = 0; (count< max_Count) && ((U32)count < index); count++)
             {
               contact = contact->getNext();
             }
             if(count == index && contact != NULL)
             {
                 if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
                 {
                     if(!contact->m_name.isEmpty())
                     {
                       mmi_ucs2ncpy((S8*)string, (S8*)contact->m_name.getBuf(), contact->m_name.getLength());
                     }
					 else
					 {
						mmi_ucs2cat((S8*)string, (PS8) GetString(STR_ID_VAPP_UC_UNNAMED));
					 }
					 /*
                     else if(!contact->m_phoneNumber.isEmpty())
                      {
                        mmi_ucs2ncpy((S8*)string, (S8*)contact->m_phoneNumber.getBuf(), contact->m_phoneNumber.getLength());
                      }
                      else if(!contact->m_email.isEmpty())
                      {
                        mmi_ucs2ncpy((S8*)string, (S8*)contact->m_email.getBuf(), contact->m_email.getLength());
                      }*/
                     text = VFX_WSTR_MEM((const VfxWChar *)string);
                  }
                           
                  if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
                  {
					//  if(!contact->m_name.isEmpty())
					  {
						  if(!contact->m_phoneNumber.isEmpty())
						  {
							mmi_ucs2ncpy((S8*)string, (S8*)contact->m_phoneNumber.getBuf(), contact->m_phoneNumber.getLength());
						  }
						  else if(!contact->m_email.isEmpty())
						  {
							mmi_ucs2ncpy((S8*)string, (S8*)contact->m_email.getBuf(), contact->m_email.getLength());
						  }
					  }
                     text = VFX_WSTR_MEM((const VfxWChar *)string);
                     color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
                  }
             }
         }
	return VFX_TRUE;
}

VfxBool VappRecipientListContentProvider::getItemImage(
     VfxU32 index,                    
     VcpListMenuFieldEnum fieldType,  
     VfxImageSrc &image         
     ) 
{
     if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL ||
            fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED ||
            fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT) 
            // For VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, 
            // to set different images for disabled and highlight states if need,
            // in this sample, just set same images as normal state
     {
             image.setResId(IMG_ID_VAPP_UC_BTN_DELETE);
             return VFX_TRUE; // Required if set the image successfully
     }
    return VFX_TRUE;
}

VfxU32 VappRecipientListContentProvider::getCount() const 
{
	return recipientCount;
}

void VAppUcRecipientlistPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
    // do nothing
}

void VAppUcRecipientlistPage::setBounds(const VfxRect &value)
{
	VfxPage::setBounds(value);
	if (recipientListPage)
	{
		this->recipientListPage->setSize(value.size.width, value.size.height);
	}
}
void VAppUcRecipientlistPage::onEnter(VfxBool isbackward)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

void VAppUcRecipientlistPage::onDeleteTab( VcpListMenu *lst, VfxU32 index)
{
    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();

    m_listContentProviderForRecipientList->m_contactSelector->remove(index);
    m_listContentProviderForRecipientList->recipientCount = m_contactSelector->getContactCount();
    if (m_listContentProviderForRecipientList->recipientCount > 0)
    {
	    recipientListPage->setContentProvider(m_listContentProviderForRecipientList);
	    this->recipientListPage->updateAllItems();
    }
    else
    {
        scr->getComposerPage()->updateBottomMsgHint();
        scr->getComposerPage()->updateButtonBar();
        scr->popPage();
    }
}

void VAppUcRecipientlistPage::onInit()
{
	VfxPage::onInit(); 

	VcpTitleBar* titleBar;
	VfxXmlLoader::loadBegin(this, VENUS_COMPOSER_RECIPIENT_LIST_PAGE);

    titleBar = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("titleBar")), VcpTitleBar); 
    titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_UC_RECIPIENTS_ID));    // set title text
    setTopBar(titleBar); 

    VappUCMainScr* scr = (VappUCMainScr*)getMainScr();
	recipientListPage = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("recipientList")), VcpListMenu);
	VFX_OBJ_CREATE(m_listContentProviderForRecipientList, VappRecipientListContentProvider, this);

    if(m_contactSelector)
    {
        m_listContentProviderForRecipientList->recipientCount = m_contactSelector->getContactCount();
        m_listContentProviderForRecipientList->m_contactSelector = m_contactSelector;
    }
    recipientListPage->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_FALSE); // Set command button control mode
    recipientListPage->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT); // Set command button control mode
	recipientListPage->setItemHighlightHidden(VFX_TRUE);
    
	// Conncect the required signal
    recipientListPage->m_signalCmdButtonClicked.connect(this, &VAppUcRecipientlistPage::onDeleteTab); // For the command button click
	recipientListPage->setContentProvider(m_listContentProviderForRecipientList);
    VfxXmlLoader::loadEnd();
}


VfxBool VAppUcRecipientlistPage::onKeyInput(VfxKeyEvent& event)
{
	if(event.keyCode == VFX_KEY_CODE_RSK && event.type == VFX_KEY_EVENT_TYPE_DOWN)
	{
		getMainScr()->popPage();
		return VFX_TRUE;
	}
	return VfxPage::onKeyInput(event);
}


extern "C" U32 vapp_get_icon_according_to_media_type( VfxWChar* file_name)
{
	applib_mime_type_struct *mime = NULL;

	mime = applib_mime_get_file_type(file_name);
	if (mime != NULL)
	{
		switch (mime->mime_type)
		{
		case MIME_TYPE_TEXT:
			/*Launch ebook reader*/
            return (U32)IMG_ID_VAPP_UC_TEXT_FILE_ID;

		case MIME_TYPE_IMAGE:
				return (U32)IMG_ID_VAPP_UC_IMAGE_FILE_ID;

		case MIME_TYPE_AUDIO:
			return (U32)IMG_ID_VAPP_UC_AUDIO_FILE_ID;
    #ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
		case MIME_TYPE_VIDEO:
			return (U32)IMG_ID_VAPP_UC_VIDEOFILE__ID;
    #endif        
		case MIME_TYPE_APPLICATION:
        #if defined(__MMI_VCARD__)    
            if(mime->mime_subtype == MIME_SUBTYPE_XVCARD)
            {
			    return (U32)IMG_ID_VAPP_UC_VCARD_FILE_ID;
            }
        #endif
        #if defined(__MMI_VCALENDAR__)
            if(mime->mime_subtype == MIME_SUBTYPE_XVCALENDAR)
            {
			    return (U32)IMG_ID_VAPP_UC_VCALENDAR_FILE_ID;            
            }
        #endif    	
		default:
			/*check for vcard and vcalendar and do the respective handling here*/
			return (U32)IMG_ID_VAPP_UC_UNKNOWN_FILE_ID;
		}
	}
    else
    {
       return (U32)IMG_ID_VAPP_UC_UNKNOWN_FILE_ID;
    }
}

#endif /* #if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) */
