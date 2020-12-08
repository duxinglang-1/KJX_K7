/*  Copyright Statement:
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
 *  vapp_fmgr.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h" 
#include "vcp_include.h"
#include "vcp_menu_popup.h"
#include "vcp_photo_border_frame.h"
#include "vcp_async_image_frame.h"
#include "vapp_fmgr.h"
#include "vapp_fmgr_cui_gprot.h"
#include "vapp_fmgr_cui_prot.h"
#include "vapp_fmgr_cp.h"
#include "app_str.h"
#include "app_datetime.h"
#include "mmi_rp_vapp_fmgr_def.h"
#include "mmi_rp_srv_venus_component_list_menu_def.h"
#include "vtst_rt_main.h"
#include "vcp_popup.h"
#ifdef __MMI_USB_SUPPORT__
#include "vapp_usb_gprot.h"
#include "mmi_rp_vapp_usbmmi_def.h"
#endif
#ifdef __MMI_OPP_SUPPORT__
#include "vapp_bt_send_gprot.h"
#endif

#include "ui_core\base\vfx_datatype.h"
#include "ui_core\base\vfx_base.h"
#include "vfx_adp_device.h"

#include "vapp_uc_gprot.h"
#include "vapp_fmgr_gprot.h"
#include "mmi_rp_app_cosmos_global_def.h"

#ifdef __MMI_FMGR_FORMAT_WITH_PHONE_LOCK_CONFIRM__
#include "vcui_secset_gprot.h"
#endif
#include "vfx_app.h"
/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
#include "MMI_include.h"

#include "FileMgrSrvGProt.h"	

#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"
#include "RightsMgrGProt.h"
#include "Drm_errcode.h"
#endif

/* Include header files for file detail */
#include "gdi_include.h"
#include "mdi_video.h"
#include "mdi_audio.h"
#include "mdi_datatype.h"

//#ifdef __MMI_BROWSER_2__
//include "BrowserSrvProts.h"
//#endif
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif

#include "custmenures.h"

#include "GpioSrvGprot.h"

#ifdef __MMI_EMAIL__
#include "emailappgprot.h"
#endif

#ifdef __DM_LAWMO_SUPPORT__
#include "DmSrvGprot.h"
#endif

#ifdef __cplusplus
}
#endif

#ifdef __MTK_TARGET__
#define __VAPP_FMGR_DIR_CTRL__
#endif
/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifdef __MMI_OPP_SUPPORT__
#define VAPP_FMGRI_BT_MAX_NUM VAPP_BTSENDING_MAX_OBJ
#else
#define VAPP_FMGRI_BT_MAX_NUM 0
#endif

#define MAX_TIME_TEXT_LEN 50
/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
extern "C"
{
static MMI_ID vapp_fmgr_launch_int(const WCHAR* rootPath, FMGR_FILTER* filter)
{
	vapp_fmgr_launch_args arg;
	memset(&arg, 0, sizeof(vapp_fmgr_launch_args));

    /* Check if it is usb storage mode */
#ifdef __MMI_USB_SUPPORT__	
	if (srv_usb_is_in_mass_storage_mode())
	{
        vapp_usb_unavailable_popup(0);		
		return GRP_ID_INVALID;
	}
#endif	
	arg.app_type = VappFmgrInstance::VAPP_FMGR_TYPE_APP;

    app_ucs2_strcpy((kal_int8*)arg.file_path, (const kal_int8*)rootPath);
    memcpy(&arg.filter_type, filter, sizeof(FMGR_FILTER));
		
    return VfxAppLauncher::launch( 
        VAPP_FMGR,
        VFX_OBJ_CLASS_INFO(VappFmgrApp),
        GRP_ID_ROOT,
        &arg,
        sizeof(vapp_fmgr_launch_args));
}
// For other App launch fmgr app
mmi_id vapp_fmgr_launch_by_app(const WCHAR* rootPath, FMGR_FILTER* filter)
{
    return vapp_fmgr_launch_int(rootPath, filter);
}

MMI_ID vapp_fmgr_launch(void)
{
    FMGR_FILTER filter;
    FMGR_FILTER_SET_ALL(&filter);
    return vapp_fmgr_launch_int((WCHAR *)L"root", &filter);
}

mmi_ret vapp_fmgr_proc(mmi_event_struct *in)
{
    return MMI_RET_DONT_CARE;
}

}

#ifdef __AFX_RT_TEST__
VtstTestResultEnum vtst_fmgr_testbed_launch(VfxU32 param)
{
	vapp_fmgr_launch_args arg;

	VFX_UNUSED(param);
	
	memset(&arg, 0, sizeof(vapp_fmgr_launch_args));

	app_ucs2_strncpy((kal_int8*)arg.file_path, (const kal_int8*)L"root", sizeof(arg.file_path));
	arg.app_type = VappFmgrInstance::VAPP_FMGR_TYPE_APP;
	FMGR_FILTER_SET_ALL(&arg.filter_type);
		
    VfxAppLauncher::launch( 
        VAPP_FMGR,
        VFX_OBJ_CLASS_INFO(VappFmgrApp),
        GRP_ID_ROOT,
        &arg,
        sizeof(vapp_fmgr_launch_args));

	return VTST_TR_OK;
}
#endif

VFX_IMPLEMENT_CLASS("VappFmgrApp", VappFmgrApp, VfxCui);

void VappFmgrApp::onInit()
{
	VfxCui::onInit();
	
	m_instance = NULL;
}

void VappFmgrApp::onRun(void * args, VfxU32 argSize)
{
    VfxCui::onRun(args, argSize);
    
    VFX_ASSERT(NULL != args);

    vapp_fmgr_launch_args *arg = (vapp_fmgr_launch_args*)args;
    if (VappFmgrInstance::VAPP_FMGR_TYPE_APP == arg->app_type)
    {
        VappFmgrMainScr *scr;
        VFX_OBJ_CREATE(scr, VappFmgrMainScr, this);

        VappFmgrInstance *instance;
        VFX_OBJ_CREATE(instance, VappFmgrMain, scr);
        instance->setGid(getGroupId());
        instance->setFilter(arg->filter_type);
        
        VfxU32 page_id = VappFmgrPage::VAPP_FMGR_DRAW_NORMAL_LIST_PAGE;
        instance->setDisplayStyle(page_id);
        instance->createFSDataObj(VFX_TRUE, getGroupId());

        scr->setCallerInstance(instance);
        instance->setFilePath(arg->file_path);
        instance->setInstancyType(arg->app_type);

        /* Check if it is root */
        if (instance->isFilePathRoot())
        {
        #ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
            VappFmgrDrvTabPage *tabctrlpage;
            VFX_OBJ_CREATE_EX(tabctrlpage, VappFmgrDrvTabPage, scr, (instance));
            tabctrlpage->setInstance(instance);
            tabctrlpage->setCurrTab(SRV_FMGR_DRV_PHONE_TYPE+1);
            tabctrlpage->m_signalTabSwitched.connect(instance, &VappFmgrInstance::onDrvTabSwitch);
            instance->setTabCtrlPageObj((VcpTabCtrlPage*)tabctrlpage);
            instance->setFilePath((VfxWChar*)srv_fmgr_drv_get_path_by_type(SRV_FMGR_DRV_PHONE_TYPE));
            scr->pushPage((VappFmgrPage::VAPP_FMGR_DRAW_DRV_TABCTRL_PAGE+1), tabctrlpage);

            instance->setDisplayStyle(VappFmgrPage::VAPP_FMGR_DRAW_DRV_PHONE_PAGE);
        #else
            VappFmgrPage *page;
            VFX_OBJ_CREATE_EX(page, VappFmgrPage, scr, (VappFmgrPage::VAPP_FMGR_DRAW_DRV_MEM_PAGE, instance));
            scr->pushPage((VappFmgrPage::VAPP_FMGR_DRAW_DRV_MEM_PAGE+1), page);
            page->m_signalGetOptMenuItem.connect(instance, &VappFmgrInstance::getOptionItem);
            page->m_signalGetTitleStrAndIcn.connect(instance, &VappFmgrInstance::getTitleStrAndIcn);
            page->m_signalGetOptMenuItem.connect(instance, &VappFmgrMain::getOptionItem);
            page->updatePageOptionMenu(instance, 0);
        #endif
        }
        else
        {
            VappFmgrPage *page;
            VFX_OBJ_CREATE_EX(page, VappFmgrPage, scr, (page_id, instance));
            scr->pushPage((page_id+1), page);

            page->m_signalGetOptMenuItem.connect(instance, &VappFmgrInstance::getOptionItem);
            page->m_signalGetTitleStrAndIcn.connect(instance, &VappFmgrInstance::getTitleStrAndIcn);
            instance->setDisplayStyle(VappFmgrPage::VAPP_FMGR_DRAW_NORMAL_LIST_PAGE);
        }

        instance->setTitleIconId(arg->title_icon_id);
        instance->setTitleStrId(arg->title_str_id);
        instance->setDrvType(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
        instance->setCurIndex(0);

        m_instance = (VfxObject*)instance;

        scr->show();
    }
}

mmi_ret VappFmgrApp::onProc(mmi_event_struct *evt)
{
	if (m_instance != NULL)
	{
		VappFmgrInstance *instance = (VappFmgrInstance*)m_instance;
		return instance->callProc(evt);
	}

	return MMI_RET_OK;
}

void VappFmgrApp::onGroupInactive()
{
    VappFmgrCui* cui = (VappFmgrCui*)this;
    if (cui != NULL && !cui->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrCui)))
    {
        /* App should use app's animation */
        vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_APP, VFX_FALSE, VFX_SCR_TRANSIT_PRIORITY_USER);
    }
    else
    {
        VfxCui::onGroupInactive();
    }
}

VfxAppCloseAnswerEnum VappFmgrApp::onProcessClose(VfxAppCloseOption options)
{
    if (options & VFX_APP_CLOSE_OPTION_NO_FLAG)
    {
        if (m_instance != NULL && m_instance->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrInstance)))
        {
            VappFmgrInstance* instance = (VappFmgrInstance*)m_instance;
            if (instance->getOperationObj() != NULL && instance->getOperationObj()->getAction() == VAPP_FMGR_ACTION_FORMAT && 
                instance->getOperationObj()->getOngoing())
            {
                return VFX_APP_CLOSE_ANSWER_NO;
            }
        }
    }

    return VfxApp::onProcessClose(options);
}

void VappFmgrApp::setInstance(VfxObject* instance)
{
	m_instance = instance;
}

VfxObject* VappFmgrApp::getInstance() const
{
	return m_instance;
}

VFX_IMPLEMENT_CLASS("VappFmgrInstance", VappFmgrInstance, VfxControl);

/* instance list */
VfxU8                  VappFmgrInstance::instance_num = 0;
VappFmgrInstance*      VappFmgrInstance::Head = NULL;
VappFmgrInstance*      VappFmgrInstance::Tail = NULL;
VappFmgrInstance*      VappFmgrInstance::NextNotify = NULL;

void VappFmgrInstance::onInit()
{
	VfxControl::onInit();

	Next = NULL;
    Prev = NULL;
    m_id = 0;
	m_context = this;
        m_fsdata = NULL;
	m_action = NULL;
	m_ms = NULL;
	m_listmenu = NULL;
	m_glist = NULL;
	m_page = NULL;
	m_tabctrlpage = NULL;
	m_flag = 0;
	m_system_folder_properity = NULL;

	m_sf_index = -1;
	m_sf_job_id = 0;

	m_disable_update = VFX_FALSE;
	
	m_delay_event = NULL;

	m_group_pos.group = 0;
	m_group_pos.pos = -1;

    memset(search_filename, 0, VENUS_FMGR_FILENAME_BUF_LEN);
    search_instance_id = 0;
    search_for_new_folder = VFX_FALSE;

    m_show_pop = NULL;
    m_errHandle = VFX_TRUE;
    m_isGroupListMenu = VFX_TRUE;
	//VfxU8 num = getInstanceNum();

	//VFX_ASSERT(num <= VENUS_MMI_FMGR_INSTANCE_MAX_NUM);
}

void VappFmgrInstance::onDeinit()
{
    if (getInstanceNum() == 0)
    {
        setHeadInstancePtr(NULL);
        setTailInstancePtr(NULL);
    }

    if (m_fsdata != NULL)
    {
        if (this == m_fsdata->getCallerInstance())
        {            
            m_fsdata->setCallerInstance(NULL);
        }
        VFX_OBJ_CLOSE(m_fsdata);
    }

    if (m_listmenu != NULL)
    {
        m_listmenu->setContentProvider(NULL);
    }

    if (m_glist != NULL)
    {
        m_glist->setContentProvider(NULL);
    }


    VFX_OBJ_CLOSE(m_action);
    VFX_OBJ_CLOSE(m_ms);
    VFX_FREE_MEM(m_system_folder_properity);
    VFX_FREE_MEM(m_delay_event);

    VfxControl::onDeinit();
}

void VappFmgrInstance::onHandleEventPlugIn(mmi_event_struct *param)
{
    srv_fmgr_notification_dev_plug_event_struct *evt = (srv_fmgr_notification_dev_plug_event_struct*)param;
    const VfxU8 curDrvLetter = (VfxU8)m_file_path.getBuf()[0];
    
    for (VfxU32 i = 0; i < evt->count; i++)
    {
        if (evt->drv_letters[i] != curDrvLetter)
            continue;

        // the drv is plugged in. so refresh it
        // Destroy empty file list handle first
        if (m_file_path.getLength() == 3)
        {
            if (m_fsdata != NULL)
            {
                m_fsdata->releaseCurrCallerFSData(this);
            }

            if (m_sf_job_id != 0)
            {
                if (srv_fmgr_async_abort(m_sf_job_id, MMI_FALSE) == MMI_TRUE)
                {
                    m_sf_cancel = VFX_TRUE;
                }
            }
            else
            {
                m_sf_index = 0;
                VfxS32 fs_ret = prepareSystemFolders();

                if (fs_ret == VAPP_FMGRI_ERROR_PREPARE_SYSTEM_FOLDER_COMPLETE ||
                    fs_ret == FS_MSDC_MOUNT_ERROR)
                {
                    /* prepare system folder flow done. */
                    m_sf_index = 0;
                    refreshMenu(VENUS_FMGRI_INDEX_NOT_CHANGE);
                }
            }
        }
        break;
    }
}

mmi_ret VappFmgrInstance::onProc(mmi_event_struct *param)
{
    if (param->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT||
        param->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN)
    {
        srv_fmgr_notification_dev_plug_event_struct *evt = (srv_fmgr_notification_dev_plug_event_struct*)param;
		
		for (VfxU32 i = 0; i < evt->count; i++)
        {
            /* Change tab name to default string "memory card" */
            changeTabName((srv_fmgr_drv_type_enum)srv_fmgr_drv_get_type(evt->drv_letters[i]));
        }
    }

    return MMI_RET_OK;
}

void VappFmgrInstance::changeTabName(srv_fmgr_drv_type_enum drv_type)
{
#ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
    VfxMainScr *scr = VfxMainScr::findMainScr((VfxFrame*)this);
    if (scr == NULL || drv_type != SRV_FMGR_DRV_CARD_TYPE)
        return ;
    
    // Currently support single memory card
    VfxU8 drv_letter = srv_fmgr_drv_get_letter_by_type(drv_type);
    VfxS8 drv_name[80];

    if (srv_fmgr_drv_get_name(drv_letter, (WCHAR*)drv_name, 80) == 0)
    {
        VappFmgrStorageReport *ctrl_page = (VappFmgrStorageReport*)scr->getPage(VappFmgrPage::VAPP_FMGR_DRAW_STORAGE_REPORT+1);
        if (ctrl_page != NULL && ctrl_page->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrStorageReport)))
        {
            ctrl_page->changeTab((drv_type+1), (VfxWChar*)drv_name);
        }

        VappFmgrDrvTabPage *drv_page = (VappFmgrDrvTabPage*)scr->getPage(VappFmgrPage::VAPP_FMGR_DRAW_DRV_TABCTRL_PAGE+1);
        if (drv_page != NULL && drv_page->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrDrvTabPage)))
        {
            drv_page->changeTab((drv_type+1), (VfxWChar*)drv_name);
        }
    }
#endif
}

VfxBool VappFmgrInstance::isInstanceIdValid(VfxU8 instance_id) const
{
    if (instance_id > 0 && instance_id <= VENUS_MMI_FMGR_INSTANCE_MAX_NUM)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

VfxS32 VappFmgrInstance::setFilePath(VfxWChar *path)
{
	if (app_ucs2_strlen((const kal_int8*)path) > SRV_FMGR_PATH_MAX_LEN)
	{
		return FS_PATH_OVER_LEN_ERROR;
	}

    m_file_path.loadFromMem(path);

	return FS_NO_ERROR;
}

VfxWString VappFmgrInstance::getFilePath() const
{
    return m_file_path;
}

void VappFmgrInstance::setTitleIconId(VfxU16 icon_id)
{
	title_icon_id = icon_id;
}

void VappFmgrInstance::setTitleStrId(VfxU16 str_id)
{
	title_str_id = str_id;
}

void VappFmgrInstance::setFilter(FMGR_FILTER filter)
{
	filter_type = filter;
}

void VappFmgrInstance::setFlag(VfxU32 flag)
{
	m_flag = flag;
}

void VappFmgrInstance::addFlag(VfxU32 flag)
{
    m_flag |= flag;    
}

void VappFmgrInstance::setCustData(VfxU32 c_data)
{
	cust_data = c_data;
}

void VappFmgrInstance::setInstancyType(VfxU8 instance_type)
{
	m_instance_type= instance_type;
}

void VappFmgrInstance::setPageObj(VfxPage *page)
{
	m_page = page;
}

void VappFmgrInstance::setTabCtrlPageObj(VcpTabCtrlPage *tabctrlpage)
{
	m_tabctrlpage = tabctrlpage;
}

void VappFmgrInstance::addFmgrInstance(VappFmgrInstance* instance)
{
    VappFmgrInstance* tail = VappFmgrInstance::getTailInstancePtr();
    VappFmgrInstance* head = VappFmgrInstance::getHeadInstancePtr();

    if (head == NULL && tail == NULL)
    {
        VappFmgrInstance::setHeadInstancePtr(instance);
        VappFmgrInstance::setTailInstancePtr(instance);	
        instance->Prev = NULL;
        instance->Next = NULL;
    }
    else if (tail != NULL && tail->Next == NULL)
    {
        instance->Prev = tail;
        tail->Next = instance;
        instance->Next = NULL;
        VappFmgrInstance::setTailInstancePtr(instance);
    }
    else
    {
        // The case should not happen
        VFX_ASSERT(0);
    }

    VappFmgrInstance::increaseInstanceNum();
    setInstanceId(getInstanceNum());
}

void VappFmgrInstance::removeFmgrInstance(VappFmgrInstance* instance)
{
    if (!isInstanceIdValid(instance->m_id))
        return ;

    VappFmgrInstance *next = instance->Next;
    VappFmgrInstance *prev = instance->Prev;

    if (next != NULL)
    {
        next->Prev = prev;
    }

    if (prev != NULL)
    {
        prev->Next = next;
    }

    NextNotify = next;

    if (instance == VappFmgrInstance::getHeadInstancePtr())
    {
        VappFmgrInstance::setHeadInstancePtr(next);
    }

    if (instance == VappFmgrInstance::getTailInstancePtr())
    {
        VappFmgrInstance::setTailInstancePtr(prev);
    }

    VappFmgrInstance::decreaseInstanceNum();
}

VappFmgrInstance* VappFmgrInstance::getNextInstance(void)
{
	return Next;
}

VappFmgrInstance* VappFmgrInstance::getPrevInstance(void)
{
	return Prev;
}
    
VfxS32 VappFmgrInstance::asyncLoadFileList(VfxBool checkDirty)
{
    // async load file list
    VAPP_FMGR_TRACE1(TRC_VAPP_FMGR_INSTANCE_ASYNC_LIST, "[VAPPFMGR]asyncloadlist, checkDirty %d", checkDirty);
    
    if (m_fsdata == NULL)
    {
        VFX_OBJ_CREATE(m_fsdata, VappFmgrFSData, this);
    }

    VfxS32 result = m_fsdata->asyncLoadFileList(this,
                                vapp_fmgr_load_response_callback(this, &VappFmgrInstance::onLoadRspCB),
                                vapp_fmgr_load_progress_callback(this, &VappFmgrInstance::onLoadProgressCB),
                                VappFmgrInstance::getSearchFilename(this->m_id),
                                checkDirty);

    return result;
}

VfxBool VappFmgrInstance::isFilePathRoot(void) const
{	
	if (m_file_path == VAPP_FMGR_PATH_ROOT)
	{
		return VFX_TRUE;
	}
	else
	{
		return VFX_FALSE;
	}
}

VfxBool VappFmgrInstance::isFilePathDrv(void) const
{	
	if (m_file_path.getLength() == 3)
	{
		return VFX_TRUE;
	}
	else
	{
		return VFX_FALSE;
	}
}

VfxS32 VappFmgrInstance::composeFilePath(VfxWString &path, VfxS8 *file_name, VfxBool add_end_slash)
{	
    return composeFilePath(NULL, VAPP_FMGR_FILE_PATH_LEN, path, file_name, add_end_slash);
}

VfxS32 VappFmgrInstance::composeFilePath(VfxS8* buffer, VfxS32 buffer_size, VfxWString& path, VfxS8* file_name, VfxBool add_end_slash)
{
    if (path.isNull())
    {
        return FS_PATH_NOT_FOUND;
    }

    VfxS32 bufLen = buffer_size / ENCODING_LENGTH;
    if (bufLen > 0)
    {
        --bufLen;  // reserve for '\0'
    }

    // check the path length
    VfxBool addSlash = VFX_FALSE;
    VfxWChar *temp = (VfxWChar*)path.getBuf();
    VfxS32 pathLen = path.getLength();    
    if (temp[pathLen - 1] != '\\' && pathLen < bufLen)
    {
        ++pathLen;
        addSlash = VFX_TRUE;
    }

    if (file_name != NULL)
    {
        pathLen += app_ucs2_strlen((const kal_int8*)file_name);
    }

    if (add_end_slash)
    {
        ++pathLen;
    }

    if (pathLen > bufLen)
        return FS_PATH_OVER_LEN_ERROR;

    // cat path and file name
    VfxWString tmp_path(temp);
    VfxWString tempObj;

    if (addSlash)
    {
        tmp_path += tempObj.format("\\");
    }

    tmp_path += tempObj.loadFromMem((VfxWChar*)file_name);

    if (add_end_slash)
    {
        tmp_path += tempObj.format("\\");
    }

    if (buffer != NULL)
    {
        memset(buffer, 0, buffer_size);
        app_ucs2_strncpy((kal_int8*)buffer, (const kal_int8*)tmp_path.getBuf(), bufLen);
    }
    else
    {
        path = tmp_path;
    }

    return FS_NO_ERROR;
}

VfxBool VappFmgrInstance::isComposeFilePathOverLen(VfxWString& path, VfxS8* file_name, VfxBool add_end_slash)
{
    VfxS32 pathLen = 0;

    if (!path.isNull())
    {
        VfxS8 *temp = (VfxS8*)path.getBuf();
        pathLen = path.getLength();

        if (temp[(pathLen-1)*ENCODING_LENGTH] != '\\' && pathLen < SRV_FMGR_PATH_MAX_LEN)
        {
            ++pathLen;
        }
    }

    if (file_name != NULL)
    {
        pathLen += app_ucs2_strlen((const kal_int8*)file_name);
    }

    if (add_end_slash)
    {
        ++pathLen;
    }

    if (pathLen > SRV_FMGR_PATH_MAX_LEN)
    {
        return  VFX_TRUE;
    }

    return VFX_FALSE;
}

void VappFmgrInstance::createFSDataObj(VfxBool prepare_buffer, VfxS32 app_id)
{
    if (m_fsdata != 0)
        return ;

    VFX_OBJ_CREATE(m_fsdata, VappFmgrFSData, this);
    if (prepare_buffer)
    {
        m_fsdata->prepareFileListBuffer(app_id);
    }
}

void VappFmgrInstance::releaseFSDataObj(void)
{	
    if (m_fsdata != NULL )
    {
        m_fsdata->clearFileListData(this);
    }
}

VappFmgrFSData* VappFmgrInstance::getFSDataObj(void) const
{
	return m_fsdata;
}

VappFmgrGeneralOperation* VappFmgrInstance::getOperationObj(void) const
{
	return m_action;
}

void VappFmgrInstance::setPrepareSystemFolderIndex(VfxS8 index)
{
	m_sf_index = index;
}

VfxS8 VappFmgrInstance::getPrepareSystemFolderIndex(void) const
{
	return m_sf_index;
}

SRV_FMGR_FILELIST_HANDLE VappFmgrInstance::getFileListHdle(void)
{
    return (m_fsdata != NULL? m_fsdata->getFileListHdlr() : 0);
}

void VappFmgrInstance::setCurIndex(VfxS32 cur_index)
{
	m_cur_index = cur_index;
}

VfxS32 VappFmgrInstance::getCurIndex(void) const
{
	return m_cur_index;
}
    
void VappFmgrInstance::refreshMenu(VfxS32 new_index, VfxS32 fs_error)
{	
    VAPP_FMGR_TRACE3(TRC_VAPP_FMGR_INSTANCE_REFRESH_MENU, "[VAPPFMGR]refresh menu, index %d, err_code %d, display_style %d", new_index, fs_error, m_display_style);
    // Update m_cur_index
    if (new_index >= 0)
    {
        m_cur_index = new_index;
    }
    else if (new_index == VENUS_FMGRI_INDEX_TO_FIRST_POS)
    {        
        m_cur_index = 0;
    }

    VfxS32 subFileFolderNum;
    if (new_index == VENUS_FMGRI_INDEX_ERROR_CODE)
    {
        subFileFolderNum = fs_error;
    }
    else
    {
        // Check multi option file list status
        VfxBool checkDirty = VFX_TRUE;

        if (m_action != NULL)
        {
            // File operation is ongoing;
            // Not need to refresh file list in the case
            if (m_action->isShowProcessing())
            {                
                checkDirty = VFX_FALSE;
            }
            // Check err
            // Filelist will be refreshed after user check error popup if err
            if (m_action->getErrorCode() < 0)
            {                
                return;
            }
        }

        if (checkDirty)
        {
            if (m_fsdata != NULL && srv_fmgr_filelist_is_dirty(m_fsdata->getFileListHdlr()) == VFX_TRUE)
            {
                error_handler(VAPP_FMGRI_ERROR_FILE_LIST_IS_DIRTY);
            }
        }

        // Refresh
        subFileFolderNum = asyncLoadFileList(checkDirty);

        if (subFileFolderNum < 0 && subFileFolderNum != SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY && subFileFolderNum != SRV_FMGR_FILELIST_ERROR_FILE_READY)
        {
            if (!error_handler(subFileFolderNum))
            {
                return;
            }
        }
    }

    // Update FsData count
    VFX_ASSERT(m_fsdata != 0);
    m_fsdata->setCount(subFileFolderNum);

    if (m_page != NULL && m_page->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrPage)))
    {
        VappFmgrPage *page = (VappFmgrPage*)m_page;
    #if !defined(__COSMOS_SLIM_FMGR_MT6260__)
        if (page->getPageId() == VappFmgrPage::VAPP_FMGR_DRAW_FILE_DETAIL_PAGE)
        {
            VappFmgrFileDetail *detail = (VappFmgrFileDetail*)page;
            detail->unhideFileNameEditBtn();
            page->updatePage(this, VappFmgrPage::VAPP_FMGR_DRAW_FILE_DETAIL_PAGE, m_cur_index, VFX_TRUE);
        }
        else
    #endif // #if !defined(__COSMOS_SLIM_FMGR_MT6260__)    
        {
            page->updatePage(this, m_display_style, m_cur_index, VFX_TRUE);
        }
    }
}

void VappFmgrInstance::onActionRsp(VfxObject* obj, VfxS32 error_code, VfxBool no_on_confirm)
{
}

void VappFmgrInstance::onClickUpButton(VfxObject* obj, VfxId button_id)
{
    if (m_page != NULL)
    {
        VappFmgrPage *page = (VappFmgrPage*)m_page;
        const VfxU32 page_id = page->getPageId();
        // For media picker
        if (page_id >= VappFmgrPage::VAPP_FMGR_DRAW_NORMAL_LIST_PAGE &&
            page_id <= VappFmgrPage::VAPP_FMGR_DRAW_MEDIA_PICKER_LAST_PAGE)
        {
            VAPP_FMGR_TRACE0(TRC_VAPP_FMGR_ONCLICKBACK, "[VAPPFMGR]onClickUpButton, set page exit flag");
            page->setExit();
        }

        page->closePage();
        m_page = NULL;
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
}

void VappFmgrInstance::onClickCmdButton(VcpListMenu *listmenu, VfxU32 index)
{
}

void VappFmgrInstance::onClickGroupCmdButton(VcpGroupListMenu *listmenu, VcpMenuPos pos)
{
}

void VappFmgrInstance::onClickToolBarButton(VfxObject* obj, VfxId button_id)
{	
}

void VappFmgrInstance::getTitleStrAndIcn(VfxWString &main_str, VfxU32 title_element, VfxU16 &icon_id)
{
    VfxBool isPageRestore = VFX_FALSE;
    VappFmgrPage *page = (VappFmgrPage*)m_page;
    
    if (page != NULL)
    {
        isPageRestore = page->checkPageRestore();
    }

#ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
    if (m_file_path.getLength() == 3)
    {
        // root dir page
        // only update title bar and icon
        VfxWChar *name;
        VFX_ALLOC_MEM(name, VENUS_FMGR_FILENAME_BUF_LEN, this);
        if (srv_fmgr_drv_get_name((U8)m_file_path.getBuf()[0], (WCHAR*)name, VENUS_FMGR_FILENAME_BUF_LEN) == 0)
        {
            main_str.loadFromMem(name);
            VfxS32 drv_type = srv_fmgr_drv_get_type((U8)m_file_path.getBuf()[0]);
            if (drv_type < SRV_FMGR_DRV_CARD_TYPE)
            {
                icon_id = IMG_ID_VAPP_FMGR_TAB_PHONE_ICN;
            }
            else
            {
                icon_id = IMG_ID_VAPP_FMGR_TAB_CARD_ICN;
            }
        }
        VFX_FREE_MEM(name);
    }
    else
#endif
    {
        // Normal folder page
        // title cell main str
        if (title_element == VappFmgrPage::VAPP_FMGR_PAGE_TITLE_CELL_MAIN_STR)
        {
            getTitleCellMainString(main_str, isPageRestore);
        }
        // title cell sub str
        else if (title_element == VappFmgrPage::VAPP_FMGR_PAGE_TITLE_CELL_SUB_STR)
        {
            if (isPageRestore)
            {
                main_str.loadFromRes(STR_GLOBAL_LOADING);
            }
            else
            {
                getTitleCellSubString(main_str);
            }
        }
        // title bar sting
        else if (title_element == VappFmgrPage::VAPP_FMGR_PAGE_TITLE_BAR_MAIN_STR)
        {
            switch (m_display_style)
            {
                case VappFmgrPage::VAPP_FMGR_DRAW_FOLDER_SELECT_PAGE:
                    main_str.loadFromRes(STR_ID_VAPP_FMGR_FOLDER_SELECTOR_TITLE);
                    break;
                case VappFmgrPage::VAPP_FMGR_DRAW_SINGLE_FILE_SELECT_PAGE:
                    main_str.loadFromRes(STR_ID_VAPP_FMGR_FILE_SELECTOR_TITLE);
                    break;
                case VappFmgrPage::VAPP_FMGR_DRAW_FOLDER_BROWSER_LAUNCH_PAGE:
                    main_str.loadFromRes(STR_ID_VAPP_FMGR_APP_TITLE);
                    break;
                case VappFmgrPage::VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE:
                    main_str.loadFromRes(m_ms_title_id);
                    break;
                default:
                    main_str.loadFromRes(STR_ID_VAPP_FMGR_APP_TITLE);
                    break;
            }
        }
        // title cell up button
        else if (title_element == VappFmgrPage::VAPP_FMGR_PAGE_TITLE_CELL_UP_BUTTON)
        {
            switch (m_display_style)
            {
                case VappFmgrPage::VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE:
                    icon_id = 0;
                    break;
                default:
                    icon_id = 1;
                    break;
            }
        }
        // icon_id = srv_fmgr_types_get_icon(FMGR_TYPE_FOLDER, NULL, SRV_FMGR_TYPES_ICON_LARGE);
    }
}

void VappFmgrInstance::resetOptMenu(VfxU16 opt_menu_id)
{
    VfxU16 count = GetNumOfChild(opt_menu_id);

    while(count > 0)
    {
        mmi_frm_unhide_menu_item(GetSeqItemId(opt_menu_id, (U16)(count-1)));
        --count;
    }
}

void VappFmgrInstance::getOptionItem(VfxU32 page_id, VfxU16 &opt_menu_id, VfxU16 &opt_menu_num)
{
}

VfxBool VappFmgrInstance::isMenuItemDisable(VfxU32 page_id, VfxU16 &opt_menu_id)
{
    if (m_fsdata == NULL)
        return VFX_FALSE;

    VappFmgrPage *page = (VappFmgrPage*)m_page;
    // Disable all items when page is onRestore
    if (page->checkPageRestore())
    {
        return VFX_TRUE;
    }

    // Skip file list handle checking in drive phone page because there is no file list handle in drive phone page
    // Skip file list handle checking in storage report 
    SRV_FMGR_FILELIST_HANDLE hdlr = m_fsdata->getFileListHdlr();
    VfxS32 pageId = page->getPageId();
    if (pageId != VappFmgrPage::VAPP_FMGR_DRAW_DRV_PHONE_PAGE &&
        pageId != VappFmgrPage::VAPP_FMGR_DRAW_STORAGE_DETAIL_MEM_PAGE &&
        pageId != VappFmgrPage::VAPP_FMGR_DRAW_STORAGE_DETAIL_PHONE_PAGE &&
        pageId != VappFmgrPage::VAPP_FMGR_DRAW_FILE_DETAIL_PAGE)
    {
        // Disable all items when ready to enter a page
        if (hdlr == 0 && opt_menu_id != MENU_ID_FMGR_CANCEL)
        {
            return VFX_TRUE;
        }
    }

    srv_fmgr_filelist_state_enum state = srv_fmgr_filelist_get_state(hdlr);
    if (state == SRV_FMGR_FILELIST_STATE_REFRESHING ||
        state == SRV_FMGR_FILELIST_STATE_LOADING)
    {
        return VFX_TRUE;
    }

    return VFX_FALSE;
}

#ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
void VappFmgrInstance::onDrvTabSwitch(VfxObject *obj, VfxId tab_id)
{
    if (tab_id > 0)
    {
        m_file_path.format("%c:\\", srv_fmgr_drv_get_letter_by_type((srv_fmgr_drv_type_enum)(tab_id - 1)));
    }
}
#endif

void VappFmgrInstance::setGid(mmi_id gid)
{
	m_gid = gid;
}

void VappFmgrInstance::setDisplayStyle(VfxU32 display_style)
{
	m_display_style = display_style;
}

VfxU32 VappFmgrInstance::GetDisplayStyle(void) const
{
	return m_display_style;
}

void VappFmgrInstance::onLoadRspCB(VfxObject *obj, VfxS32 result, VfxS32 search_index)
{
    VappFmgrInstance *instance = VFX_OBJ_DYNAMIC_CAST(obj, VappFmgrInstance);

    if (instance == NULL || instance != this)
        return ;
    
    // Close loading frame
    VappFmgrPage* page = (VappFmgrPage*)m_page;
    if (page != NULL && page->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrPage)))
    {
        page->closeLoadingIndicator();
    }
    
    // Todo: if FMGR is not active, do not have to show file list
    m_disable_update = VFX_FALSE;

    VfxS32 refreshStartIdx;

    VAPP_FMGR_TRACE3(TRC_VAPP_FMGR_ONLOADRSP, "[VAPPFMGR]onLoadRspCB refresh menu, group %d, result %d, search_index %d", m_gid, result, search_index);
    if(result < 0)
    {
        // Error case
        // Do nothing when user abort refresh file list
        if (result != FS_ABORTED_ERROR && error_handler(result))
        {
            m_fsdata->createEmptyFileListHdlr(this);
            refreshStartIdx = VENUS_FMGRI_INDEX_ERROR_CODE;
        }
        else
        {
            return ;
        }
    }
    else
    {                
        // Enter real explorer
        if (search_index != -1)
        {
            refreshStartIdx = search_index;
        }
        else
        {
            refreshStartIdx = VENUS_FMGRI_INDEX_NOT_CHANGE;
        }
    }
    
    refreshMenu(refreshStartIdx, result);
}

void VappFmgrInstance::onLoadProgressCB(VfxObject *obj, VfxS32 total_count, VfxS32 progress_count)
{
    VappFmgrInstance *instance = VFX_OBJ_DYNAMIC_CAST(obj, VappFmgrInstance);

    if ((instance == NULL || instance != this)
        || !(progress_count > 0 && progress_count < total_count)
        || m_disable_update)
        return ;

    /* Todo: if FMGR is not active, do not have to show file list */
    if (m_fsdata == NULL)
        return ;
    
    m_fsdata->setCount(progress_count);
    
    VappFmgrPage* page = (VappFmgrPage*)m_page;
    // For root dir case
    if (m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_DRV_MEM_PAGE ||
    m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_DRV_PHONE_PAGE)
    {
        if (m_glist == NULL)
        {
            if (page != NULL &&
            page->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrPage)) &&
            page->getPageId() != VappFmgrPage::VAPP_FMGR_DRAW_FILE_DETAIL_PAGE)
            {
                page->updatePage(this, m_display_style, m_cur_index, VFX_TRUE);
            }
        }
        else
        {
            m_glist->updateAllItems();
        }
    }
    // For normal list page case
    else if (m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_NORMAL_LIST_PAGE)
    {
        if (m_listmenu == NULL)
        {
            if (page != NULL &&
            page->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrPage)))
            {
                page->updatePage(this, page->getPageId(), m_cur_index, VFX_TRUE);
            }
        }
        else
        {
            m_listmenu->updateAllItems();
        }
    }
}

void VappFmgrInstance::onTapListMenuItem(VcpListMenu *sender, VfxU32 index)
{	
}

void VappFmgrInstance::onTapGroupListMenuItem(VcpGroupListMenu *listmenu, VcpMenuPos pos)
{
}

void VappFmgrInstance::onPopupStateChange(VfxBasePopup* obj,  VfxBasePopupStateEnum state)
{
    m_flag &= ~VAPP_FMGR_IFLAG_WAIT_POPUP;
}

void VappFmgrInstance::onClickConfirmButton(VfxObject* obj, VfxId id)
{
}

void VappFmgrInstance::setMenu(VcpListMenu *listmenu)
{
	if (m_listmenu != NULL)
	{
		m_listmenu->m_signalViewScrollStart.connect(this, &VappFmgrInstance::onViewScrollStart);
		m_listmenu->m_signalViewScrollEnd.connect(this, &VappFmgrInstance::onViewScrollEnd);
		m_listmenu->setIsNoDisableCheckForTouch(VFX_TRUE);
        m_isGroupListMenu = VFX_FALSE;
	}
}

void VappFmgrInstance::setMenu(VcpGroupListMenu *menu)
{
	if (m_glist != NULL)
	{
		m_glist->m_signalViewScrollStart.connect(this, &VappFmgrInstance::onViewScrollStart);
		m_glist->m_signalViewScrollEnd.connect(this, &VappFmgrInstance::onViewScrollEnd);
		m_glist->setIsNoDisableCheckForTouch(VFX_TRUE);
        m_isGroupListMenu = VFX_TRUE;
	}
}

VfxBool VappFmgrInstance::_getItemTextForNormal(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString & text)
{
    // For normal page
    VAPP_FMGR_FILE_INFO_STRUCT *file_info;
    VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
    VfxS32 fs_ret = m_fsdata->getFileInfo(this, index, file_info);
    if (fs_ret < 0)
    {
        VFX_FREE_MEM(file_info);
        m_fsdata->setLoadFileIndex(index);
        error_handler(fs_ret);
        return VFX_FALSE;
    }
    // Main text case, hidden ext name for .mp3
    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        if (file_info->file_type == FMGR_TYPE_DAF)
        {
            VfxU8 *buffer;
            VFX_ALLOC_MEM(buffer, VAPP_FMGR_FILE_PATH_LEN, this);
            app_ucs2_strncpy((kal_int8*)buffer, (const kal_int8*)file_info->file_name, SRV_FMGR_PATH_MAX_LEN);
            srv_fmgr_path_hide_extension((WCHAR*)buffer);
            text.loadFromMem((const VfxWChar*)buffer);
            VFX_FREE_MEM(buffer);
        }
        else
        {
            text.loadFromMem((const VfxWChar *)file_info->file_name);
        }
    }
    // Sub text1 case, file size, but not for FOLDER
    else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        if (file_info->attribute& FS_ATTR_DIR)
        {
            VFX_FREE_MEM(file_info);
            return VFX_FALSE;
        }
        else
        {
            getSizeString(text, file_info->file_size);
        }
    }

    VFX_FREE_MEM(file_info);
    if (fieldType == VCP_LIST_MENU_FIELD_TEXT || fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
        return VFX_TRUE;
    else
        return VFX_FALSE;
}

VfxBool VappFmgrInstance::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString & text, VcpListMenuTextColorEnum & color)
{
    if (m_fsdata == 0)
        return VFX_FALSE;

    // For root dir case.
    // Only have Group header and/or main text.
    if (m_file_path.getLength() == 3)
    {
        // Group header case
        if (fieldType == VCP_LIST_MENU_FIELD_GROUP_HEADER_TEXT)
        {
            text.loadFromRes(STR_ID_VAPP_FMGR_HEADER_SYSTEM);
        }
        // Main text case
        else if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
        {
            text.loadFromRes(g_def_folder_table[index].str_id);
        }
        else
        {
            return VFX_FALSE;
        }
        return VFX_TRUE;
    }
    else
    {
        return _getItemTextForNormal(index, fieldType, text);
    }
}

VfxBool VappFmgrInstance::getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc & image)
{	
    if (m_fsdata == 0)
        return VFX_FALSE;

    // Icon
    if (fieldType == VCP_LIST_MENU_FIELD_ICON)
    {
        VAPP_FMGR_FILE_INFO_STRUCT *file_info;
        VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
        VfxS32 fs_ret = m_fsdata->getFileInfo(this, index, file_info);
        if (fs_ret < 0)
        {
            VFX_FREE_MEM(file_info);
            m_fsdata->setLoadFileIndex(index);
            error_handler(fs_ret);
            return VFX_FALSE;
        }

        image.setResId(srv_fmgr_types_get_icon(file_info->file_type, NULL, SRV_FMGR_TYPES_ICON_LARGE));
        VFX_FREE_MEM(file_info);
        return VFX_TRUE;
    }
#if !defined(__COSMOS_SLIM_FMGR_MT6260__)
    // CMD button
    else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL ||
            fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_PRESSED ||
            fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED ||
            fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT)
    {
        image.setResId(IMG_ID_VAPP_FMGR_DETAIL_INFO);
        return VFX_TRUE;
    }
#endif // #if !defined(__COSMOS_SLIM_FMGR_MT6260__)
    else
    {
        return VFX_FALSE;
    }
}

void VappFmgrInstance::closeItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc Image)
{
}

VfxU32 VappFmgrInstance::getCount() const
{	
    if (m_fsdata == NULL)
	{
		return 0;
	}

    VfxS32 count = m_fsdata->getCount();
    return (count>0? count : 0);
}

VfxU32 VappFmgrInstance::getCount(VfxU32 group) const
{
    if (m_fsdata == NULL)
    {
        return 0;
    }

    VfxS32 count;
    if (group == 0)    // 1st group
    {
        if (m_file_path.getLength() == 3)   // System folders num for Root Dir
        {
            count = g_def_folder_table_size;
        }
        else                                // count for normal page
        {
            count = m_fsdata->getCount();
        }
    }
    else    // 2nd group
    {
        count = m_fsdata->getCountWithoutSF();
    }

    return (count>0? count : 0);
}

VfxU32 VappFmgrInstance::getGroupCount() const
{
    VfxS32 drv_type = srv_fmgr_drv_get_type((U8)m_file_path.getBuf()[0]);
    if (drv_type != SRV_FMGR_DRV_PHONE_TYPE && m_fsdata->getCountWithoutSF() != 0)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

VfxBool VappFmgrInstance::hasGroupHeader(VfxS32 group) const 
{
    if(m_display_style != VappFmgrPage::VAPP_FMGR_DRAW_DRV_PHONE_PAGE &&
        m_display_style != VappFmgrPage::VAPP_FMGR_DRAW_DRV_MEM_PAGE)
    {
        return VFX_FALSE;
    }
    else
    {
        return VFX_TRUE;
    }
}

VfxBool VappFmgrInstance::getItemText(
        VcpMenuPos pos,                  // [IN] the position of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        )
{
    if(!m_isGroupListMenu)
    {
        return getItemText(pos.pos, fieldType, text, color);
    }

    if (m_fsdata == 0)
        return VFX_FALSE;

    VfxS32 index = pos.pos;

    // First group of Rood dir
    if (m_file_path.getLength() == 3 && pos.group == 0)
    {
        // Group header text
        if (fieldType == VCP_LIST_MENU_FIELD_GROUP_HEADER_TEXT)
        {
            text.loadFromRes(STR_ID_VAPP_FMGR_HEADER_SYSTEM);
        }
        // Main text
        else if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
        {
            text.loadFromRes(g_def_folder_table[index].str_id);
        }
        else
        {
            return VFX_FALSE;
        }
        
        return VFX_TRUE;
    }
    else
    {
        // 2nd group header text of Root dir
        if (fieldType == VCP_LIST_MENU_FIELD_GROUP_HEADER_TEXT)
        {
            text.loadFromRes(STR_ID_VAPP_FMGR_HEADER_USERDEFINE);
            return VFX_TRUE;
        }
        else
        {
            return _getItemTextForNormal(index, fieldType, text);
        }
    }
}

VfxBool VappFmgrInstance::getItemImage(
        VcpMenuPos pos,                  // [IN] the position of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        )
{
    if (m_fsdata == 0)
        return VFX_FALSE;

    if(!m_isGroupListMenu)
    {
        return getItemImage(pos.pos, fieldType, image);
    }

    // For Root dir 1st group
    if (m_file_path.getLength() == 3 && pos.group == 0)
    {
        if (fieldType == VCP_LIST_MENU_FIELD_ICON)
        {
            image.setResId(g_def_folder_table[pos.pos].icon_id);
            return VFX_TRUE;
        }
#if !defined(__COSMOS_SLIM_FMGR_MT6260__)
        else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL ||
            fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_PRESSED ||
            fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED ||
            fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT)
        {
            image.setResId(IMG_ID_VAPP_FMGR_DETAIL_INFO);
            return VFX_TRUE;
        }
#endif // !defined(__COSMOS_SLIM_FMGR_MT6260__)
        else
        {
            return VFX_FALSE;
        }
    }
    else
    {
        // For normal page case, or Root dir 2nd group
        return getItemImage(pos.pos, fieldType, image);
    }
}

VcpListMenuItemStateEnum VappFmgrInstance::getItemState(VfxU32 index) const
{	
	return VCP_LIST_MENU_ITEM_STATE_NONE;
}

VfxBool VappFmgrInstance::swapItem(VfxU32 index1, VfxU32 index2)
{
	return VFX_TRUE;
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
VfxBool VappFmgrInstance::getItemIsDisabled(VfxU32 index) const
{
    VfxBool result = m_context->isDisabled(0, index);

    VAPP_FMGR_TRACE2(TRC_VAPP_FMGR_INSTANCE_ITEMISDISABLED, "[VAPPFMGR] item index %d is disabled? %d", index, result);
    return result;
}

VfxBool VappFmgrInstance::getItemIsDisabled(VcpMenuPos pos) const
{
    if(!m_isGroupListMenu)
    {
        return getItemIsDisabled(pos.pos);
    }

    VfxBool result = VFX_FALSE;

    if (pos.group > 0)
    {
        result = m_context->isDisabled(0, pos.pos);
    }

    VAPP_FMGR_TRACE3(TRC_VAPP_FMGR_INSTANCE_GROUPITEMISDISABLED, "[VAPPFMGR] item group %d pos %d is disabled? %d", pos.group, pos.pos, result);
    return result;
}

VfxBool VappFmgrInstance::isDisabled(VfxU32 flag, VfxS32 index)
{
    VfxBool result = VFX_FALSE;
    VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;

    do {
        if (m_fsdata != NULL)
        {
            VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), m_context);
            VfxS32 fs_ret = m_fsdata->getFileInfo(m_context, index, file_info);
            if (fs_ret < 0)
            {
                if (fs_ret == FS_FILE_NOT_FOUND)
                {
                    result = VFX_TRUE;
                }
                else
                {
                    result = VFX_FALSE;
                }
                break;
            }

            if (flag & VAPP_FMGRI_CHECK_IS_FOLDER)
            {
                if (file_info->attribute & FS_ATTR_DIR)
                {
                    result = VFX_TRUE;
                    break;
                }
            }

            if (m_context->isComposeFilePathOverLen(m_context->m_file_path, file_info->file_name, VFX_FALSE))
            {
                if (flag & VAPP_FMGRI_CHECK_PATH_OVER_LENGTH)
                {
                    /* If file path length > 259, return true */
                    result = VFX_TRUE;
                }
                break;
            }
        }

    #ifdef __DRM_SUPPORT__
        if (flag & VAPP_FMGRI_CHECK_DRM_SEND_PERMISSION)
        {
            /* If it is operation "Share", to check DRM send permission */
            VfxS8 *buffer;
            VFX_ALLOC_MEM(buffer, VAPP_FMGR_FILE_PATH_LEN, m_context);
            memset(buffer, 0, VAPP_FMGR_FILE_PATH_LEN);

            if (m_context->composeFilePath(buffer, VAPP_FMGR_FILE_PATH_LEN, m_context->m_file_path, file_info->file_name, VFX_FALSE) < 0)
            {
                VFX_FREE_MEM(buffer);
                break;
            }

            VfxS32 fs_ret = mmi_rmgr_check_forward((WCHAR*)buffer);
            VFX_FREE_MEM(buffer);
            if (fs_ret >= 0 && (!(fs_ret & MMI_RMGR_USAGE_SEND)))
            {
                result = VFX_TRUE;
                break;
            }
        }
    #endif
    } while(0);

    VFX_FREE_MEM(file_info);

    return result;
}

void VappFmgrInstance::getTitleCellMainString(VfxWString &main_str, VfxBool isPageRestore)
{
    VfxWChar *name;

    if (isPageRestore)
    {
        VfxS8 *buffer;
        VFX_ALLOC_MEM(buffer, VAPP_FMGR_FILE_PATH_LEN, this);
        memset(buffer, 0, VAPP_FMGR_FILE_PATH_LEN);
        app_ucs2_strncpy((kal_int8*)buffer, (const kal_int8*)m_file_path.getBuf(), SRV_FMGR_PATH_MAX_LEN);
        // Get the parent folder
        srv_fmgr_path_remove_filename((WCHAR*)buffer);
        if (app_ucs2_strlen(buffer) > 3)
        {
            const VfxU16 str_id = isSystemFolder((VfxS8*)buffer);
            if (str_id != 0)
            {
                main_str.loadFromRes(str_id);
            }
            else
            {
                srv_fmgr_path_remove_slash((WCHAR*)buffer);
                name = srv_fmgr_path_get_filename_ptr((WCHAR*)buffer);
                main_str.loadFromMem((const VfxWChar*)name);
            }
        }

        VFX_FREE_MEM(buffer);
    }
    else
    {
        const VfxU16 str_id = isSystemFolder((VfxS8*)m_file_path.getBuf());
        if (str_id != 0)
        {
            main_str.loadFromRes(str_id);
        }        
        else
        {
            name = srv_fmgr_path_get_filename_ptr((WCHAR*)m_file_path.getBuf());
            VfxS32 strlen = app_ucs2_strlen((const kal_int8*)name);
            
            VfxWChar *tmp;
            VFX_ALLOC_MEM(tmp, (strlen+1)*sizeof(VfxWChar), this);            
            memcpy(tmp, name, strlen*sizeof(VfxWChar));
            if (tmp[strlen-1] == '\\')
            {
                tmp[strlen-1] = 0;
            }
            main_str.loadFromMem((const VfxWChar*)tmp);
            VFX_FREE_MEM(tmp);
        }
    }
}

void VappFmgrInstance::getTitleCellSubString(VfxWString &main_str)
{
    /* loading, empty or files and folders number */
    if (m_fsdata == NULL)
        return;

    srv_fmgr_filelist_state_enum state = srv_fmgr_filelist_get_state(m_fsdata->getFileListHdlr());
    if (state == SRV_FMGR_FILELIST_STATE_REFRESHING ||
        state == SRV_FMGR_FILELIST_STATE_LOADING)
    {
        main_str.loadFromRes(STR_GLOBAL_LOADING);
    }
    else
    {
        const VfxS32 count = m_fsdata->getCount();
        if (count < 0)
        {
            /* loading or error display */
            main_str.loadFromRes(STR_GLOBAL_LOADING);
        }
        else if (count == 0)
        {
            main_str.loadFromRes(STR_ID_VAPP_FMGR_NO_DATA);
        }
        else
        {
            const VfxS32 filecount = m_fsdata->getFileCount();
            const VfxS32 foldercount = m_fsdata->getFolderCount();
            VfxWString temStr;
            
            if (foldercount > 0)
            {
                main_str.format("%d ", foldercount);
                
                VfxId folderId = (foldercount == 1)? STR_ID_VAPP_FMGR_FOLDER : STR_ID_VAPP_FMGR_FOLDERS;
                main_str += temStr.loadFromRes(folderId);
            }

            if (filecount > 0) 
            {
                main_str += temStr.format(" %d ", filecount);

                VfxId fileId = (filecount == 1)? STR_ID_VAPP_FMGR_FILE : STR_ID_VAPP_FMGR_FILES;
                main_str += temStr.loadFromRes(fileId);
            }
        }
    }
}

void VappFmgrInstance::releaseListMenu(void)
{
	if (m_listmenu != NULL)
	{
		m_listmenu->setContentProvider(NULL);
		m_listmenu = NULL;
	}

	if (m_glist != NULL)
	{
		m_glist->setContentProvider(NULL);
		m_glist = NULL;
	}
}

VfxBool VappFmgrInstance::showPopupEx(VfxU16 str_id, VcpPopupTypeEnum popup_type, VcpConfirmPopupButtonSetEnum button_set)
{
	return showPopup(str_id, popup_type, button_set);
}

VcpMenuPos VappFmgrInstance::getGroupPos(void)
{
	return m_group_pos;
}

void VappFmgrInstance::resetDisableUpdate(void)
{
    m_disable_update = VFX_FALSE;
}

VfxBool VappFmgrInstance::showPopup(VfxU16 str_id, VcpPopupTypeEnum popup_type, VcpConfirmPopupButtonSetEnum button_set, 
                                    VfxU16 button_str1_id, VfxU16 button_str2_id)
{
    if (m_flag & VAPP_FMGR_IFLAG_WAIT_POPUP)
    {
        return VFX_FALSE;
    }

    VcpConfirmPopup *popup;
    VFX_OBJ_CREATE(popup, VcpConfirmPopup, findScreen());
    
    popup->setInfoType(popup_type);
    popup->setAutoDestory(VFX_TRUE);
    popup->setText(str_id);
    popup->setButtonSet(button_set);    
    popup->m_signalPopupState.connect(this, &VappFmgrInstance::onPopupStateChange);
    if (button_set == VCP_CONFIRM_BUTTON_SET_YES_NO)
    {
        popup->m_signalButtonClicked.connect(this, &VappFmgrInstance::onClickConfirmButton);
    }
    else if (button_set == VCP_CONFIRM_BUTTON_SET_USER_DEFINE)
    {
        /* The case only for sharing multi files via BT currently */
        popup->m_signalButtonClicked.connect(this, &VappFmgrInstance::onClickConfirmButton);
        popup->setCustomButton(button_str1_id, button_str2_id, VCP_POPUP_BUTTON_TYPE_NORMAL, VCP_POPUP_BUTTON_TYPE_CANCEL);
        m_show_pop = popup;
    }
    popup->show(VFX_TRUE);

    m_flag |= VAPP_FMGR_IFLAG_WAIT_POPUP;

    return VFX_TRUE;
}

VfxBool VappFmgrInstance::error_handler(VfxS32 error_code, VfxS32 line)
{
    VAPP_FMGR_TRACE2(TRC_VAPP_FMGR_INSTANCE_ERR, "[VAPPFMGR]instance error handler, err_code %d, line %d", error_code, line);

    switch (error_code)
    {
        case SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY:
        {
            if (!m_errHandle)
            {
                break;
            }
            VfxS32 srv_ret = 0;
            if (m_fsdata != NULL)
            {
                srv_ret = m_fsdata->asyncLoadFileList(this,
                                                vapp_fmgr_load_response_callback(this, &VappFmgrInstance::onLoadRspCB),
                                                vapp_fmgr_load_progress_callback(this, &VappFmgrInstance::onLoadProgressCB),
                                                NULL);
            }

            if (srv_ret == SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY)
            {
                VappFmgrPage* page = (VappFmgrPage*)m_page;
                if (page != NULL && page->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrPage)))
                {
                    page->showLoadingIndicator(); 
                }
            }
        }
        break;

        // Dirty, do nothing
        case VAPP_FMGRI_ERROR_FILE_LIST_IS_DIRTY:
        // File list is loading so do nothing
        case SRV_FMGR_FILELIST_ERROR_BUSY:
            break;
        default:
            showPopup(srv_fmgr_fs_error_get_string(error_code), VCP_POPUP_TYPE_FAILURE);
            break;
    }

    return VFX_FALSE;
}

void VappFmgrInstance::onViewScrollStart(VcpBaseListMenu *menu)
{
	if (m_listmenu != NULL || m_glist != NULL)
	{
		m_disable_update = VFX_TRUE;
	}
}

void VappFmgrInstance::onViewScrollEnd(VcpBaseListMenu *menu)
{
	if (m_listmenu != NULL || m_glist != NULL)
	{
		m_disable_update = VFX_FALSE;
	}
}

void VappFmgrInstance::getSizeString(VfxWString &text, VfxU64 total_size)
{
    static const VfxChar unitChar[] = {"BKMG"};
    
    // Get the large unint: G, M, K?
    VfxU32 i = 0;
    VfxU64 unit = 1;
    while (total_size >= (unit << 10) && i < 4)
    {
        unit <<= 10;
        ++i;
    }

    VfxU64 uTotal = (VfxU64)(((VfxFloat)total_size/unit)*100);
    VfxU64 remainder = uTotal%100;

    text.format("%d",(uTotal/100));
    VfxWString tempStr((const VfxWChar *)" ");

    if (remainder > 0)
    {
        tempStr.format(".%02d ", remainder);
    }

    text += tempStr;
    text += tempStr.format("%c",unitChar[i]);
    if (i > 0)
    {
        text += tempStr.format("B");
    }
}

void VappFmgrInstance::getDateTimeString(VfxWString &text, MYTIME* date_time)
{
    if (date_time != NULL)
    {
        applib_time_struct dateTime;
        memset(&dateTime, 0, sizeof(applib_time_struct));

        dateTime.nYear = date_time->nYear;
        dateTime.nMonth= date_time->nMonth;
        dateTime.nDay = date_time->nDay;
        dateTime.nHour= date_time->nHour;
        dateTime.nMin = date_time->nMin;
        dateTime.nSec = date_time->nSec;
        
        VfxDateTime dt_obj;
        dt_obj.setDateTime(&dateTime);

        VfxS8 buffer[MAX_TIME_TEXT_LEN*sizeof(VfxWChar)];
        memset(&buffer, 0, MAX_TIME_TEXT_LEN*sizeof(VfxWChar));
        
        dt_obj.getDateTimeString((VFX_DATE_TIME_DATE_YEAR | VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY | 
                                  VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE), 
                                (VfxWChar*)buffer, MAX_TIME_TEXT_LEN);

        text.loadFromMem((const VfxWChar*)&buffer);
    }
}

void VappFmgrInstance::enterFolder(VfxS8 *name)
{
    VAPP_FMGR_TRACE1(TRC_VAPP_FMGR_ENTERFOLDER, "[VAPPFMGR]enterFolder, current display %d", m_display_style);

    // fill the sub folder path to m_file_path from name
    const VfxS32 len = app_ucs2_strlen((const kal_int8*)name);
    VfxBool add_end_slash = VFX_TRUE;

    if (len > 0 && ((VfxWChar*)name)[(len - 1)] == L'\\')
    {
        add_end_slash = VFX_FALSE;
    }
    
    VfxS8 *buffer;
    VFX_ALLOC_MEM(buffer, VAPP_FMGR_FILE_PATH_LEN, this);
    memset(buffer, 0, VAPP_FMGR_FILE_PATH_LEN);
    if (composeFilePath(buffer, VAPP_FMGR_FILE_PATH_LEN, m_file_path, name, add_end_slash) < 0)
    {
        VFX_FREE_MEM(buffer);
        showPopup(srv_fmgr_fs_error_get_string(FS_PATH_OVER_LEN_ERROR), VCP_POPUP_TYPE_FAILURE);
        return ;
    }
    m_file_path.loadFromMem((const VfxWChar*)buffer);
    VFX_FREE_MEM(buffer);

    // Empty current file list.
    releaseFSDataObj();

    // Save current page state.
    VappFmgrPage *page = (VappFmgrPage*)m_page;
    if (page != NULL && page->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrPage)))
    {
        VAPP_FMGR_TRACE1(TRC_VAPP_FMGR_ENTERFOLDER_CURPAGEID, "[VAPPFMGR]current page id %d", page->getPageId());

        VcpBaseMenuViewState history;

        memset(&history, 0, sizeof(VcpBaseMenuViewState));

        if (m_listmenu != NULL)
        {
            m_listmenu->getViewState(&history);
            page->setMenuViewState(&history);
        }
        else if (m_glist != NULL)
        {
            m_glist->getViewState(&history);
            page->setMenuViewState(&history);
        }

        /* Set restore flage */
        if (m_display_style != VappFmgrPage::VAPP_FMGR_DRAW_DRV_PHONE_PAGE &&
            m_display_style != VappFmgrPage::VAPP_FMGR_DRAW_DRV_MEM_PAGE)
        {
            page->setPageRestore(VFX_TRUE);
        }
    }

    releaseListMenu();
    //resetSystemFolderProperity();

    // Get next level page ID and display style
    VfxMainScr *scr = page->getMainScr();
    VfxId pageId = m_page->getId();

    if (m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_DRV_PHONE_PAGE ||
        m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_DRV_MEM_PAGE)
    {
        VAPP_FMGR_TRACE0(TRC_VAPP_FMGR_ROOT2FOLDER, "[VAPPFMGR]root enter folder");

        if (m_instance_type == VAPP_FMGR_TYPE_APP)
        {
            m_display_style = VappFmgrPage::VAPP_FMGR_DRAW_NORMAL_LIST_PAGE;
            pageId = VappFmgrPage::VAPP_FMGR_DRAW_NORMAL_LIST_PAGE;
        }
        else if (m_instance_type == VAPP_FMGR2_TYPE_FILE_SELECTOR)
        {
            m_display_style = VappFmgrPage::VAPP_FMGR_DRAW_SINGLE_FILE_SELECT_PAGE;
            pageId = VappFmgrPage::VAPP_FMGR_DRAW_SINGLE_FILE_SELECT_PAGE;
        }
        else if (m_instance_type == VAPP_FMGR2_TYPE_FOLDER_SELECTOR)
        {
            m_display_style = VappFmgrPage::VAPP_FMGR_DRAW_FOLDER_SELECT_PAGE;
            pageId = VappFmgrPage::VAPP_FMGR_DRAW_FOLDER_SELECT_PAGE;
        }			
        // For media picker
        else if (m_instance_type == VAPP_FMGR2_TYPE_MEDIA_PICKER)
        {
            m_display_style = VappFmgrPage::VAPP_FMGR_DRAW_MEDIA_PICKER_PAGE;
            pageId = VappFmgrPage::VAPP_FMGR_DRAW_MEDIA_PICKER_PAGE;
        }
    }
    #if !defined(__COSMOS_SLIM_FMGR_MT6260__)
    else if (pageId == (VappFmgrPage::VAPP_FMGR_DRAW_FILE_DETAIL_PAGE + 1))
    {
        /* Current page is detail information */
        VAPP_FMGR_TRACE0(TRC_VAPP_FMGR_2DETAIL, "[VAPPFMGR]enter detail page");
        VappFmgrFileDetail* info_page = (VappFmgrFileDetail*)m_page;
        pageId = info_page->getFolderViewerPageId() + 1;
    }
    #endif // #if !defined(__COSMOS_SLIM_FMGR_MT6260__)
    else
    {
        VAPP_FMGR_TRACE0(TRC_VAPP_FMGR_FOLDER2FOLDER, "[VAPPFMGR]folder enter folder");
    }
    
    // Create next level folder page and update it.
    VappFmgrPage* nextLevelPage;
    VFX_OBJ_CREATE_EX(nextLevelPage, VappFmgrPage, scr, (pageId, this));
    ++pageId;

    nextLevelPage->m_signalGetTitleStrAndIcn.connect(this, &VappFmgrInstance::getTitleStrAndIcn);
    nextLevelPage->m_signalGetOptMenuItem.connect(this, &VappFmgrInstance::getOptionItem);
    nextLevelPage->updatePage(this, m_display_style, m_cur_index, VFX_TRUE);
    scr->pushPage(pageId, nextLevelPage);
}

void VappFmgrInstance::exitFolder(void)
{
    VfxS32 fs_ret = FS_NO_ERROR;
    const VfxU32 len = m_file_path.getLength();

    // If len == 3, it means drv tab switch, we only release FSdata object
    VAPP_FMGR_TRACE1(TRC_VAPP_FMGR_EXITFOLDER, "[VAPPFMGR]exitFolder, len %d", len);
    if (len > 3)
    {
        const VfxWChar* curFilePath = m_file_path.getBuf();
        
        // Set current seacher file name
        setSearchFilename(m_id, (VfxS8*)srv_fmgr_path_get_filename_ptr((WCHAR*)curFilePath) );

        // Set up level folder name to m_file_path
        const VfxS32 pos = srv_fmgr_path_get_filename_pos((const WCHAR*)curFilePath);
        if (pos < 3)
        {
            fs_ret = FS_PARAM_ERROR;
        }
        else
        {
            VfxWChar *tmp_path;
            VFX_ALLOC_MEM(tmp_path, sizeof(VfxWChar)*(pos+1), this);
            app_ucs2_strncpy((kal_int8*)tmp_path, (const kal_int8*)curFilePath, pos);
            m_file_path.loadFromMem(tmp_path);
            VFX_FREE_MEM(tmp_path);
        }
    }
    else if (len < 3)
    {
        fs_ret = FS_PARAM_ERROR;
    }

    if (fs_ret < 0)
    {
        setSearchFilename(m_id, NULL);
        error_handler(fs_ret);
    }
    else
    {
        /* Refresh file list */
        releaseFSDataObj();
        releaseListMenu();

        const VfxS32 upPathLen = m_file_path.getLength();
        if (upPathLen == 3)
        {
            /* Back to drv tab page */
            VfxU32 drv_type = srv_fmgr_drv_get_type((VfxU8)m_file_path.getBuf()[0]);

            if (drv_type == SRV_FMGR_DRV_PHONE_TYPE)
            {
                m_display_style = VappFmgrPage::VAPP_FMGR_DRAW_DRV_PHONE_PAGE;
            }
            else if (drv_type == SRV_FMGR_DRV_CARD_TYPE)
            {
                m_display_style = VappFmgrPage::VAPP_FMGR_DRAW_DRV_MEM_PAGE;
            }
        }
        else if (upPathLen > 3)
        {
        /* Back to up level  */

        /* Do not have to create page of up level because we implement onSerialize */
        }
    }
}

void VappFmgrInstance::backRoot(void)
{
    VAPP_FMGR_TRACE0(TRC_VAPP_FMGR_BACK2ROOT, "[VAPPFMGR]backRoot");

    if (isFilePathRoot() || m_file_path.getLength() <= 3)
        return ;

    // Set the start page and end page id, so that these pages can be closed.
    VfxU32 end_page_id = 0;
    VappFmgrPage *page = (VappFmgrPage*)m_page;
    
    if (page != NULL)
    {
        end_page_id = page->getPageId(); 
    #if !defined(__COSMOS_SLIM_FMGR_MT6260__)
        if (end_page_id == VappFmgrPage::VAPP_FMGR_DRAW_FILE_DETAIL_PAGE)
        {
            VappFmgrFileDetail* tmp_page = (VappFmgrFileDetail*)page;
            end_page_id = tmp_page->getFolderViewerPageId();
        }
    #endif // #if !defined(__COSMOS_SLIM_FMGR_MT6260__)
    }

    // Close pages.
    VfxMainScr *scr = VfxMainScr::findMainScr(this);
    if (scr != NULL)
    {
        if (end_page_id == 0)
        {
            end_page_id = scr->getTopPageId();
            end_page_id--;
        }

        VfxS32 start_page_id = m_display_style;
        if (m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE)
        {
            start_page_id = VappFmgrPage::VAPP_FMGR_DRAW_NORMAL_LIST_PAGE;
        }
        VAPP_FMGR_TRACE2(TRC_VAPP_FMGR_BACK2ROOT_START_END, "[VAPPFMGR]backRoot, start %d, end %d", start_page_id, end_page_id);

        start_page_id++;
        if (end_page_id == VappFmgrPage::VAPP_FMGR_DRAW_DRV_TABCTRL_PAGE)
        {
            VAPP_FMGR_TRACE2(TRC_VAPP_FMGR_CLOSE_PAGE, "[VAPPFMGR]close page, m_id %d, line %d", start_page_id, __LINE__);
            scr->closePage(start_page_id);
        }
        else
        {
            end_page_id++;
            for (VfxS32 i = start_page_id; i <= end_page_id; i++)
            {
                VAPP_FMGR_TRACE2(TRC_VAPP_FMGR_CLOSE_PAGE, "[VAPPFMGR]close page, m_id %d, line %d", i, __LINE__);
                scr->closePage(i);
            }
        }
    }

    // Update current m_file_path.
    VfxWChar *tmp_path;
    VFX_ALLOC_MEM(tmp_path, sizeof(VfxWChar)*4, this);
    memset(tmp_path, 0, sizeof(VfxWChar)*4);
    app_ucs2_strncpy((kal_int8*)tmp_path, (const kal_int8*)m_file_path.getBuf(), 3);
    m_file_path.loadFromMem(tmp_path); 
    VFX_FREE_MEM(tmp_path);

    // Empty current file list
    releaseFSDataObj();
    releaseListMenu();

    // Back to drv tab page
    VfxU32 drv_type = srv_fmgr_drv_get_type((VfxU8)m_file_path.getBuf()[0]);

    if (drv_type == SRV_FMGR_DRV_PHONE_TYPE)
    {
        m_display_style = VappFmgrPage::VAPP_FMGR_DRAW_DRV_PHONE_PAGE;
    }
    else if (drv_type == SRV_FMGR_DRV_CARD_TYPE)
    {
        m_display_style = VappFmgrPage::VAPP_FMGR_DRAW_DRV_MEM_PAGE;
    }
}

VfxS32 VappFmgrInstance::prepareSystemFolders()	
{
    // Error check.
    if (m_sf_index < 0 || m_sf_index > g_def_folder_table_size || m_sf_job_id > 0)
    {
        return VAPP_FMGRI_ERROR_PREPARE_SYSTEM_FOLDER_ERROR;
    }

    if (m_sf_index == g_def_folder_table_size)
    {
        return VAPP_FMGRI_ERROR_PREPARE_SYSTEM_FOLDER_COMPLETE;
    }

    if (m_display_style != VappFmgrPage::VAPP_FMGR_DRAW_DRV_PHONE_PAGE &&
    m_display_style != VappFmgrPage::VAPP_FMGR_DRAW_DRV_MEM_PAGE)
    {
        return VAPP_FMGRI_ERROR_PREPARE_SYSTEM_FOLDER_ERROR;
    }

    // Not in Root dir.
    if (m_file_path.getLength() > 3)
    {
        return FS_PATH_OVER_LEN_ERROR;
    }

    // Check the driver is prepared.
    VfxS32 fs_ret = FS_GetDevStatus((VfxU8)m_file_path.getBuf()[0], FS_MOUNT_STATE_ENUM);
    if (fs_ret != FS_NO_ERROR)
    {
        return fs_ret;
    }

    if (m_sf_index == 0)
    {
        // If file list handle is dirty, we have to reset system folder properity array
        if (m_fsdata != NULL)
        {
            SRV_FMGR_FILELIST_HANDLE file_handle = m_fsdata->getFileListHdlr();

            if (file_handle == 0 || srv_fmgr_filelist_is_dirty(file_handle))
            {
                resetSystemFolderProperity();
            }
        }
    }

    // Create system folders */
    m_sf_job_id = 0;
    m_sf_cancel = VFX_FALSE;

    VfxS8 *folder_path;
    VFX_ALLOC_MEM(folder_path, VAPP_FMGR_FILE_PATH_LEN, this);

    do {
        fs_ret = composeFilePath(folder_path, VAPP_FMGR_FILE_PATH_LEN, m_file_path, (VfxS8*)g_def_folder_table[m_sf_index].path, VFX_FALSE);
        if (fs_ret < 0)
        {
            break;
        }

        fs_ret = srv_fmgr_async_create_folder((const WCHAR*)folder_path, 0, vapp_fmgr_async_create_folder_result_proc, getObjHandle());
        if (fs_ret >= 0)
        {
            m_sf_job_id = fs_ret;
            break;
        }
        else if (fs_ret == FS_FILE_EXISTS)
        {
            // Todo: We should un-hide system folder */
            FS_SetAttributes((const WCHAR*)folder_path, FS_ATTR_DIR);
            setSystemFolderProperityExist(m_sf_index, 0);
            fs_ret = 0; 
        }
        else 
        {
            setSystemFolderProperityExist(m_sf_index, fs_ret);
            fs_ret = 0;
        }

        m_sf_index++;
    } while(m_sf_index < g_def_folder_table_size);

    if (m_sf_index == g_def_folder_table_size)
    {
        fs_ret = VAPP_FMGRI_ERROR_PREPARE_SYSTEM_FOLDER_COMPLETE;
    }

    if (folder_path != NULL)
    {
        VFX_FREE_MEM(folder_path);
    }

    return fs_ret;
}

void VappFmgrInstance::setCreateSystemFolderJobId(VfxS32 job_id)
{
	m_sf_job_id = job_id;
}

VfxS32 VappFmgrInstance::getCreateSystemFolderJobId(void) const
{
	return m_sf_job_id;
}

void VappFmgrInstance::resetSystemFolderProperity(void)
{
    if (m_system_folder_properity == NULL)
        return ;

    for (VfxS32 idx = 0; idx < g_def_folder_table_size; ++idx)
    {
        m_system_folder_properity[idx].exist = -1;
        m_system_folder_properity[idx].index = -1;

        m_system_folder_offset[idx] = -1;
    }
}

void VappFmgrInstance::setSystemFolderProperityExist(VfxU8 i, VfxS32 exist)
{
	if (m_system_folder_properity != NULL)
	{
		m_system_folder_properity[i].exist = exist;
	}
}

void VappFmgrInstance::setSystemFolderProperityIndex(VfxU8 i, VfxS32 index)
{
	if (m_system_folder_properity != NULL)
	{
		m_system_folder_properity[i].index = index;
	}
}

VfxS32 VappFmgrInstance::getSystemFolderProperityExist(VfxU8 i)
{
	if (m_system_folder_properity != NULL)
	{
		return m_system_folder_properity[i].exist;
	}

	return -2;
}

VfxS32 VappFmgrInstance::getSystemFolderProperityIndex(VfxU8 i)
{
	if (m_system_folder_properity != NULL)
	{
		return m_system_folder_properity[i].index;
	}

	return -1;
}

VfxU16 VappFmgrInstance::isSystemFolder(VfxS8 *folder_name, VfxBool name_only)
{
    // Error check
    if (folder_name == NULL)
    {
        return 0;
    }

    VfxS32 drv_type = srv_fmgr_drv_get_type((U8)folder_name[0]);

    if (!name_only && drv_type != SRV_FMGR_DRV_PHONE_TYPE && drv_type != SRV_FMGR_DRV_CARD_TYPE)
    {
        return 0;
    }

    const VfxS8* folderNamePtr = name_only? folder_name : folder_name + 3 * ENCODING_LENGTH;
    VfxS8* defFolderPtr;
    VfxU16 result = 0;
    for (VfxS32 idx = 0; idx < g_def_folder_table_size; ++idx)
    {
        defFolderPtr = (VfxS8 *)g_def_folder_table[idx].path;
        const VfxS32 len = app_ucs2_strlen((const kal_int8*)folderNamePtr);

        if (app_ucs2_strnicmp((const kal_int8*)folderNamePtr, (const kal_int8*)defFolderPtr, len) == 0
            && defFolderPtr[len*ENCODING_LENGTH] == 0
            && defFolderPtr[len*ENCODING_LENGTH+1] == 0)
        {
            result =  g_def_folder_table[idx].str_id;
            break;
        }
    }
    
    return result;
}

void VappFmgrInstance::setSystemFolderOffset(VfxU8 i, VfxS32 index)
{
	m_system_folder_offset[i] = index;
}

VfxS32 VappFmgrInstance::getSystemFolderOffset(VfxU8 i) const
{
	return m_system_folder_offset[i];
}

mmi_ret VappFmgrInstance::callProc(mmi_event_struct *param)
{
	return onProc(param);
}

void VappFmgrInstance::callbackApp(mmi_group_event_struct *evt)
{
    VAPP_FMGR_TRACE2(TRC_VAPP_FMGR_CALLBACKAPP, "[VAPPFMGR] callback app, sender %d, evt id %d", evt->sender_id, evt->evt_id);
    
	if (m_flag & VAPP_FMGR_IFLAG_WAIT_POPUP)
	{
		if (evt != NULL && m_delay_event == NULL)
		{
			VFX_ALLOC_MEM(m_delay_event, evt->size, this);
			memcpy(m_delay_event, evt, evt->size);
		}
	}
	else
	{
		VfxCui *app = (VfxCui*)VfxApp::getObject(m_gid);
		if (app != NULL)
		{
			app->postToCaller(evt);
		}
	}
}

VFX_IMPLEMENT_CLASS("VappFmgrFSData", VappFmgrFSData, VfxObject);

void VappFmgrFSData::onInit(void)
{
	VfxObject::onInit();

	//load_rsp_cb = NULL;
	//load_progress_cb = NULL;
	
    file_list_hdl = 0;
	m_file_list_parent = 0;
	
    //file_list_lock = VFX_FALSE;

    load_file_index = -1;	

	m_count = -1;
	m_system_folder_count = 0;

	m_file_count = 0;
	m_folder_count = 0;

	m_filelist_buffer = NULL;
	m_filelist_buffer_size = 0;
	m_app_id = 0;
}	

void VappFmgrFSData::onDeinit(void)
{	
    //load_rsp_cb = NULL;
    //load_progress_cb = NULL;

    if (file_list_hdl != 0 && m_file_list_parent == 0)
    {
#ifdef __VAPP_FMGR_DIR_CTRL__
    /* Unlock dir cache slot */
    if (caller_instance != NULL)
    {
        FS_HANDLE fh;
        fh = FS_Open((WCHAR*)caller_instance->getFilePath().getBuf(), FS_READ_ONLY | FS_OPEN_SHARED | FS_OPEN_DIR);
        if(fh >= 0)
        {
            FS_DirCtrl(fh, FS_DIRCTRL_DATA_UNLOCK, NULL);
            FS_Close(fh);
        }
    }
#endif
    srv_fmgr_filelist_destroy(file_list_hdl);
    }

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    if (m_filelist_buffer != NULL)
    {
        applib_asm_free_r(m_app_id, m_filelist_buffer);
    }
    VfxObject::onDeinit();
}	

mmi_ret VappFmgrFSData::onLoadFileListResult(mmi_event_struct *param)
{
	return 0;
}

VfxBool VappFmgrFSData::IsCurrCallerInstance(VappFmgrInstance *instance) const
{
    if (instance == getCallerInstance())
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

void VappFmgrFSData::setLoadRspCB(vapp_fmgr_load_response_callback cb)
{
	load_rsp_cb = cb;
}

vapp_fmgr_load_response_callback VappFmgrFSData::getLoadRspCB(void) const
{
	return load_rsp_cb;
}

void VappFmgrFSData::setLoadProgressCB(vapp_fmgr_load_progress_callback cb)
{
	load_progress_cb = cb;
}

vapp_fmgr_load_progress_callback VappFmgrFSData::getLoadProgressCB(void) const
{
	return load_progress_cb;
}

void VappFmgrFSData::setCallerInstance(VappFmgrInstance *instance)
{	
	caller_instance = instance;
}

VappFmgrInstance* VappFmgrFSData::getCallerInstance(void) const
{
	return caller_instance;
}

#ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
VfxS32 VappFmgrFSData::refreshDrvList(VappFmgrInstance *instance)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxS32 i;
    VfxS32 drive_count;
    SRV_FMGR_DRVLIST_HANDLE drvlist_hdl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drvlist_hdl = srv_fmgr_drivelist_create((srv_fmgr_drivelist_type_enum)instance->drv_type);

    for (i = 0; i < srv_fmgr_drivelist_count(drvlist_hdl); i++)
    {
        if (srv_fmgr_drv_is_busy(srv_fmgr_drivelist_get_drv_letter(drvlist_hdl, i)) == MMI_TRUE)
        {
            drive_count = FS_DEVICE_BUSY;
            goto end_fill_drive_data;
        }
    }

#ifdef __FMGR_CUSTOM_ROOT_SUPPORT__
    drive_count = mmi_fmgri_instance_cr_get_count(instance->m_id, drvlist_hdl);
    if (drive_count < 0)
    {
        drive_count = srv_fmgr_drivelist_count(drvlist_hdl);
    }
#else /* __FMGR_CUSTOM_ROOT_SUPPORT__ */
    drive_count = srv_fmgr_drivelist_count(drvlist_hdl);
#endif /* __FMGR_CUSTOM_ROOT_SUPPORT__ */

end_fill_drive_data:
   
    //FMGR_TRACE1(TRC_MMI_FMGR_33247DD07BDB40CFABB799255EC13A3A, "[MMIFMGR] > FSData > mmi_fmgr_fsdata_instance_refresh_drive_list > count=%d\n", drive_count);
    srv_fmgr_drivelist_destroy(drvlist_hdl);

    return drive_count;    
}
#endif
	
VfxS32 VappFmgrFSData::asyncLoadFileList(VappFmgrInstance* instance,
                             vapp_fmgr_load_response_callback load_rsp_cb,
                             vapp_fmgr_load_progress_callback load_progress_cb,
                             VfxS8* highlight_filename,
                             VfxBool checkDirty)
{
    #ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
        // Show drv list or my favorite list for Root Dir.
        if (instance->isFilePathRoot())
        {
            return refreshDrvList(instance);
        }
    #endif

    // On drv phone page
    if (instance->m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_DRV_PHONE_PAGE)
    {
        return g_def_folder_table_size;
    }

    // Release instance fsData if instance is changed or filelist is dirty
    if  (checkDirty &&
        (srv_fmgr_filelist_is_dirty(file_list_hdl) == MMI_TRUE) &&
        (srv_fmgr_filelist_get_state(file_list_hdl) != SRV_FMGR_FILELIST_STATE_REFRESHING) &&
        (srv_fmgr_filelist_get_state(file_list_hdl) != SRV_FMGR_FILELIST_STATE_LOADING))
    {
        releaseCurrCallerFSData(getCallerInstance());
    }
    setCallerInstance(instance);

    VfxS32 result = 0;

    do {
        // Create new file list handle if need
        if (file_list_hdl == 0)
        {
            if (m_filelist_buffer)
            {
                memset(m_filelist_buffer, 0, m_filelist_buffer_size);
            }
            result = srv_fmgr_folder_filelist_create((const WCHAR *)(instance->m_file_path.getBuf()),
                                                    &instance->filter_type,
                                                    srv_fmgr_sort_get(),
                                                    m_filelist_buffer, m_filelist_buffer_size,
                                                    &file_list_hdl);
            if (result < 0 )
            {
                goto error_loading;
            }
        }

        switch (srv_fmgr_filelist_get_state(file_list_hdl))
        {
            case SRV_FMGR_FILELIST_STATE_INIT:
            {
                VfxS32 flag = SRV_FMGR_FILELIST_REFRESH_PROGRESS_ON;

                if (highlight_filename != NULL && app_ucs2_strlen((const kal_int8*)highlight_filename) > 0)
                {
                    flag = SRV_FMGR_FILELIST_REFRESH_PROGRESS_OFF;
                }

                if (srv_fmgr_filelist_refresh(file_list_hdl,
                                            (const WCHAR *)highlight_filename,
                                            0,
                                            flag,
                                            vapp_fmgr_fsdata_onload_result_proc,
                                            instance->getObjHandle()) < 0)
                {
                    goto error_loading;
                }
                setLoadRspCB(load_rsp_cb);
                setLoadProgressCB(load_progress_cb);
                resetLoadFileIndex();
                result = SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY;
                break;
            }

            case SRV_FMGR_FILELIST_STATE_REFRESHING:
            case SRV_FMGR_FILELIST_STATE_LOADING:
                result = SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY;
                break;

            case SRV_FMGR_FILELIST_STATE_READY:
                if ((srv_fmgr_filelist_get_capability(file_list_hdl) == SRV_FMGR_FILELIST_CAP_LOAD_ON_DEMAND) &&
                    (load_file_index != -1))
                {
                    VfxS32 load_file_result = srv_fmgr_filelist_load_file(file_list_hdl, 
                                                                    load_file_index,
                                                                    vapp_fmgr_fsdata_onload_result_proc, 
                                                                    instance->getObjHandle());

                    if (load_file_result != SRV_FMGR_FILELIST_ERROR_FILE_READY)
                    {
                        if (load_file_result < 0)
                        {
                            goto error_loading;
                        }
                        setLoadRspCB(load_rsp_cb);
                        setLoadProgressCB(load_progress_cb);
                        resetLoadFileIndex();
                        result = SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY;
                        break;
                    }
                    resetLoadFileIndex();
                }

                // File list is ready, return file/folder count
                result = srv_fmgr_filelist_count(file_list_hdl);
#ifdef __FMGR_HYPERLINK_SUPPORT__
                result += mmi_fmgri_instance_get_hyperlink_count(instance->m_id);
#endif /* __FMGR_HYPERLINK_SUPPORT__ */
                break;

            default:
                result = 0;
                break;
        }

    error_loading:

        if (result < 0 && result != SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY)
        {
            releaseCurrCallerFSData(instance);
        }
    } while (0);
    return result;
}

VfxS32 VappFmgrFSData::createFileListHdlr(void)
{
    VappFmgrInstance * instance = getCallerInstance();

    return srv_fmgr_folder_filelist_create((const WCHAR*)instance->m_file_path,
                                            &instance->filter_type,
                                            srv_fmgr_sort_get(),
                                            NULL, 0,
                                            &file_list_hdl);
}

void VappFmgrFSData::setFileListHdle(SRV_FMGR_FILELIST_HANDLE hdle)
{
	file_list_hdl = hdle;
}

SRV_FMGR_FILELIST_HANDLE VappFmgrFSData::getFileListHdlr(void) const
{
	return file_list_hdl;
}

VfxS32 VappFmgrFSData::createEmptyFileListHdlr(VappFmgrInstance* instance)
{
    if (!IsCurrCallerInstance(instance))
    {
        return VAPP_FMGR_ERROR_INVALID_PARAM;
    }

    srv_fmgr_filelist_destroy(file_list_hdl);

    VfxS32 fs_ret = srv_fmgr_empty_filelist_create(&file_list_hdl);
    if (fs_ret < 0)
    {
        VFX_ASSERT(0);
    }

    return fs_ret;
}

void VappFmgrFSData::clearFileListData(VappFmgrInstance *instance)
{
    if (instance != NULL && m_file_list_parent == 0)
    {
        VappFmgrFSData *obj = instance->getFSDataObj();

        srv_fmgr_filelist_destroy(file_list_hdl);
        file_list_hdl = 0;

        //setFileListLock(VFX_FALSE);
        //file_list_lock = VFX_FALSE;
        load_file_index = -1;

        m_count = -1;
        m_system_folder_count = 0;

        m_file_count = 0;
        m_folder_count = 0;
    }
}

void VappFmgrFSData::releaseCurrCallerFSData(VappFmgrInstance *instance)
{
    if (instance != NULL)
    {
        VappFmgrFSData *obj = instance->getFSDataObj();

        srv_fmgr_filelist_destroy(obj->file_list_hdl);
        obj->file_list_hdl = 0;

        //obj->setFileListLock(VFX_FALSE);
        //obj->file_list_lock = VFX_FALSE;
    }

    setCallerInstance(NULL);
}

void VappFmgrFSData::setFileListParent(mmi_id parent_id)
{
	m_file_list_parent = parent_id;
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
#endif
void VappFmgrFSData::setLoadFileIndex(VfxS32 file_idx)
{
    if (load_file_index == -1)
    {
	    load_file_index = file_idx;
    }
}

void VappFmgrFSData::resetLoadFileIndex(void)
{
    load_file_index = -1;
}


VfxS32 VappFmgrFSData::getLoadFileIndex(void) const
{
	return load_file_index;
}

VfxS32 VappFmgrFSData::getFileInfo(VappFmgrInstance* instance, VfxS32 index, VAPP_FMGR_FILE_INFO_STRUCT *file_info)
{
    if (index < 0 || file_info == NULL)
    {
        return VAPP_FMGR_ERROR_INVALID_PARAM;
    }

    memset(file_info, 0 , sizeof(VAPP_FMGR_FILE_INFO_STRUCT));

    // Map the fileIdx and the system file index
    VfxS32 new_index = index;
    if (instance->GetDisplayStyle() == VappFmgrPage::VAPP_FMGR_DRAW_DRV_MEM_PAGE)
    {
        VfxS32 idx = 0;
        while(idx < g_def_folder_table_size)
        {
            if (instance->getSystemFolderOffset(idx) == -1 || new_index < instance->getSystemFolderOffset(idx))
            {
                new_index = index + idx;
                break;
            }
            ++idx;
        }

        if (idx == g_def_folder_table_size)
        {
            new_index = index+idx;
        }
    }

    srv_fmgr_fileinfo_struct srv_file_info;
    memset(&srv_file_info, 0, sizeof(srv_fmgr_fileinfo_struct));
    
    VfxS32 fs_ret = srv_fmgr_filelist_get_fileinfo(file_list_hdl, new_index, &srv_file_info);

    if (fs_ret < 0)
    {
        if (fs_ret == SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY)
        {
            // Need to load the target file in mmi_fmgri_fsdata_instance_load_data_async
            setLoadFileIndex(index);
        }
        return fs_ret;
    }
    
    file_info->file_type = (filetypes_file_type_enum)srv_file_info.type;
    file_info->attribute = srv_file_info.attribute;
    file_info->file_size = srv_file_info.size;
    memcpy((void*)&file_info->time, (const void*)&srv_file_info.datetime, sizeof(MYTIME));
    memcpy((void*)&file_info->created_time, (const void*)&srv_file_info.created_datetime, sizeof(MYTIME));
    memset(file_info->file_name, 0, VENUS_FMGR_FILENAME_BUF_LEN);
    srv_fmgr_filelist_get_filename(file_list_hdl, new_index, (WCHAR*)file_info->file_name, VENUS_FMGR_FILENAME_BUF_LEN);
    if (!(file_info->attribute & FS_ATTR_DIR))
    {
        memcpy((void*)file_info->file_ext, (void*)srv_fmgr_types_get_extension_ucs2(srv_fmgr_types_find_type_by_filename_str((const WCHAR*)file_info->file_name)), VENUS_FMGR_FILEEXT_BUF_LEN_RESERVED);
    }

    return fs_ret;
}

VfxS32 VappFmgrFSData::getDrvInfo(VappFmgrInstance* instance, VfxS32 index, vapp_fmgr_drive_info_struct *drv_info)
{
    if (!drv_info)
    {
        return VAPP_FMGR_ERROR_INVALID_PARAM;
    }
    
    memset(drv_info, 0, sizeof(vapp_fmgr_drive_info_struct));

    SRV_FMGR_DRVLIST_HANDLE drvlist_hdl = srv_fmgr_drivelist_create((srv_fmgr_drivelist_type_enum)instance->drv_type);
    drv_info->drv_type = srv_fmgr_drv_get_type(srv_fmgr_drivelist_get_drv_letter(drvlist_hdl, index));
    srv_fmgr_drivelist_destroy(drvlist_hdl);

    if(drv_info->drv_type < 0)
    {
        return FS_DRIVE_NOT_FOUND;
    }
    else
    {
        memcpy((void*)drv_info->drv_path, (const void*) srv_fmgr_drv_get_path_by_type((srv_fmgr_drv_type_enum)drv_info->drv_type), (SRV_FMGR_DRV_MAX_NAME_LEN + 1));
        return FS_NO_ERROR;
    }
}

VfxS32 VappFmgrFSData::getDrvCount(VappFmgrInstance* instance)
{
    SRV_FMGR_DRVLIST_HANDLE drvlist_hdl = srv_fmgr_drivelist_create((srv_fmgr_drivelist_type_enum)instance->drv_type);
    VfxS32 drv_count = srv_fmgr_drivelist_count(drvlist_hdl);

    srv_fmgr_drivelist_destroy(drvlist_hdl);

    return drv_count;
}

void VappFmgrFSData::setCount(VfxS32 count)
{
	m_count = count;
}

VfxS32 VappFmgrFSData::getCount(void) const
{
	return m_count;
}

VfxS32 VappFmgrFSData::getCountWithoutSF(void) const
{
	return (m_count - m_system_folder_count);
}

void VappFmgrFSData::setSystemFolderCount(VfxS32 count)
{
	m_system_folder_count = count;
}

VfxS32 VappFmgrFSData::getSystemFolderCount(void) const
{
	return m_system_folder_count;
}
		
void   VappFmgrFSData::setFileCount(VfxS32 count)
{
	m_file_count = count;
}

VfxS32 VappFmgrFSData::getFileCount(void) const
{
	return m_file_count;
}

void VappFmgrFSData::setFolderCount(VfxS32 count)
{
	m_folder_count = count;
}

VfxS32 VappFmgrFSData::getFolderCount(void) const
{
	return m_folder_count;
}

void VappFmgrFSData::prepareFileListBuffer(VfxS32 app_id)
{
	if (m_filelist_buffer == NULL)
	{
		m_app_id = app_id;
		m_filelist_buffer_size = SRV_FMGR_FOLDER_FILELIST_MEM_SIZE;
		m_filelist_buffer = (U8*)applib_asm_alloc_r(m_app_id, SRV_FMGR_FOLDER_FILELIST_MEM_SIZE);
		memset(m_filelist_buffer, 0, m_filelist_buffer_size);
	}
}

VFX_IMPLEMENT_CLASS("VappFmgrMain", VappFmgrMain, VappFmgrInstance);

void VappFmgrMain::onInit()
{
    VappFmgrInstance::onInit();

    VFX_ALLOC_MEM(m_system_folder_properity, sizeof(vapp_fmgr_system_folder_properity_struct)*g_def_folder_table_size, this);

    resetSystemFolderProperity();

    m_fs_id = GRP_ID_INVALID;
    m_opt_menu = NULL;
    m_selected_index = -1;
    m_selected_pos.group = -1;
    m_selected_pos.pos = -1;
    m_file_action = 0;
    //m_my_action = VFX_FALSE;
    #if defined(__COSMOS_SLIM_FMGR_MT6260__)
        mStorageReportPop = NULL;
    #endif
    this->addFmgrInstance(this);	
}

void VappFmgrMain::onDeinit()
{
	this->removeFmgrInstance(this);

	/* clear App instance object */
	VappFmgrApp *app = (VappFmgrApp*)VfxApp::getObject(m_gid);
	if (app != NULL)
	{
		app->setInstance(NULL);
	}
	
	VappFmgrInstance::onDeinit();
}

VfxBool VappFmgrMain::isCurDrvInflunced(mmi_event_struct *evt)
{
    srv_fmgr_notification_dev_plug_event_struct *plugInEvt = (srv_fmgr_notification_dev_plug_event_struct*)evt;
    const VfxChar curDrvLetter = (VfxChar)m_file_path.getBuf()[0];    

    for (VfxU32 idx = 0; idx < plugInEvt->count; ++idx)
    {
       if (plugInEvt->drv_letters[idx] == curDrvLetter)
        return VFX_TRUE;
    }
    
    return VFX_FALSE;
}

mmi_ret VappFmgrMain::callProc(mmi_event_struct *param)
{
	return onProc(param);
}

void VappFmgrMain::exitCurApp()
{
    VfxApp *app = VfxApp::getObject(m_gid);
    if (app != NULL)
    {
        app->exit();
    }
}
mmi_ret VappFmgrMain::onProc(mmi_event_struct *param)
{
    VAPP_FMGR_TRACE1(TRC_VAPP_FMGR_MAIN_ONPROC, "[VAPPFMGR] main onProc, evt id %d", param->evt_id);

    mmi_ret ret = VappFmgrInstance::onProc(param);

    if (ret != MMI_RET_OK)
    {
        return ret;
    }

    // Selecte Mode
    if (m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE)
    {
        return onMarkSeveralProc(param);
    }

    // Single file case
    switch (param->evt_id)
    {
    #ifdef __MMI_USB_SUPPORT__
        case EVT_ID_USB_ENTER_MS_MODE:
            exitCurApp();
            break;
    #endif
    
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        {
            srv_fmgr_notification_dev_plug_event_struct *evt = (srv_fmgr_notification_dev_plug_event_struct*)param;

            VfxU32 action = 0;
            if (m_action != NULL)
            {
                action = m_action->getAction();
            }

            const VfxU8 curDrvLetter = (VfxU8)m_file_path.getBuf()[0];
            for (VfxS32 idx = 0; idx < evt->count; ++idx)
            {          
                if (evt->drv_letters[idx] != curDrvLetter)
                    continue;
                
                // Close long tap menu popup, and popup which would like to check in card event
                VFX_OBJ_CLOSE(m_opt_menu);
                VFX_OBJ_CLOSE(m_show_pop);
            #if defined(__COSMOS_SLIM_FMGR_MT6260__)
                VFX_OBJ_CLOSE(mStorageReportPop);
            #endif


                // Close filename editor, and action if waitting for confirm
                if (m_action != NULL)
                {
                    if (action == VAPP_FMGR_ACTION_RENAME_FILE
                       || action == VAPP_FMGR_ACTION_RENAME_FOLDER
                       || action == VAPP_FMGR_ACTION_CREATE_FOLDER)
                    {
                        VFX_OBJ_CLOSE(m_action);
                    }
                    else if (m_action->getWaitConfirm() || m_action->isShowCommandPopup())
                    {
                        VFX_OBJ_CLOSE(m_action);
                    }
                }

                // Close folder selector
                if (m_fs_id != GRP_ID_INVALID)
                {
                    vcui_folder_selector_close(m_fs_id);
                    m_fs_id = GRP_ID_INVALID;
                }

                // refresh it if on Mem Root Dir, Or back root.
                if (m_file_path.getLength() == 3)
                {
                    refreshMenu(VENUS_FMGRI_INDEX_ERROR_CODE, FS_MSDC_MOUNT_ERROR);
                }
                else
                {
                    backRoot();
                }
                
            #if !defined(__COSMOS_SLIM_FMGR_MT6260__)
                // Close file detail.
                closeFileDetailPage();
            #endif //#if !defined(__COSMOS_SLIM_FMGR_MT6260__)
                break;
            }

        #ifndef __MMI_SLIM_FILE_MANAGER__
            // Close rename drive popup 
            if (m_action != NULL && action == VAPP_FMGR_ACTION_RENAME_DRIVE)
            {
                VFX_OBJ_CLOSE(m_action);
            }
        #endif // __MMI_SLIM_FILE_MANAGER__

            if (m_action != NULL && action == VAPP_FMGR_ACTION_FORMAT)
            {
            #ifdef __MMI_FMGR_FORMAT_WITH_PHONE_LOCK_CONFIRM__
                m_action->closeVerifyCui();
            #endif
                m_action->m_signalActionRsp.emit(m_action, FS_NO_ERROR, VFX_TRUE);
            }
            // Close storage report
            closeStorageReport();
            break;
        }

        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
        {
            VappFmgrPage *page = (VappFmgrPage*)m_page;
            if (page != NULL && page->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrPage)) &&
                page->getPageId() == VappFmgrPage::VAPP_FMGR_DRAW_STORAGE_DETAIL_MEM_PAGE)
            {
                closeStorageReport();
            }

            if ( isCurDrvInflunced(param) )
            {
                m_group_pos = VcpMenuPos(0,-1);
                m_selected_pos.invalid();
            }

            onHandleEventPlugIn(param);
            break;
        }

        case EVT_ID_VCUI_FOLDER_SELECTOR_RESULT:
        {
            vcui_folder_selector_result_event_struct *evt = (vcui_folder_selector_result_event_struct*)param;
            if (evt->result == 1)
            {
                VfxS8 *path;
                VFX_ALLOC_MEM(path, VAPP_FMGR_FILE_PATH_LEN, this);
                memset(path, 0, VAPP_FMGR_FILE_PATH_LEN);
                VfxS32 retId = vcui_folder_selector_get_selected_filepath(evt->sender_id, NULL, (WCHAR*)path, VAPP_FMGR_FILE_PATH_LEN);
                vcui_folder_selector_close(evt->sender_id);
                m_fs_id = GRP_ID_INVALID;

                if (retId >= 0)
                {
                    selectFolderDone((VfxWChar*)path);
                }
                else
                {
                    showPopup(srv_fmgr_fs_error_get_string(retId), VCP_POPUP_TYPE_FAILURE);
                }
                VFX_FREE_MEM(path);
            }
            else
            {
                vcui_folder_selector_close(evt->sender_id);
                m_fs_id = GRP_ID_INVALID;
            }
            break;
        }

        case EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION:
        {
            srv_fmgr_notification_adv_action_event_struct *evt = (srv_fmgr_notification_adv_action_event_struct*)param;

            if (evt->state != SRV_FMGR_NOTIFICATION_STATE_QUERY)
                break;

            switch (evt->action)
            {
                case SRV_FMGR_NOTIFICATION_ACTION_MOVE:
                case SRV_FMGR_NOTIFICATION_ACTION_COPY:
                {
                    // Src folder and dst folder can not be the same
                    const VfxS32 path_len = app_ucs2_strlen((const kal_int8*)evt->src_filepath);
                    if (evt->src_fileinfo.attribute & FS_ATTR_DIR
                    && app_ucs2_strncmp((const kal_int8*)evt->src_filepath, (const kal_int8*)evt->dest_filepath, path_len) == 0 
                    && evt->dest_filepath[path_len] == '\\')
                    {
                        return MMI_RET_ERR;
                    }
                }
                
            #if !defined(__COSMOS_SLIM_FMGR_MT6260__)
                case SRV_FMGR_NOTIFICATION_ACTION_DELETE:
                {
                    VappFmgrPage* page = (VappFmgrPage*)m_page;
                    if (page != NULL && 
                        (page->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrFileDetail)) 
                #ifndef __MMI_SLIM_FILE_MANAGER__
                        || page->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrFolderDetail))
                #endif
                        ))
                    {
                        VappFmgrFileDetail* detail_page = (VappFmgrFileDetail*)page;
                        if (app_ucs2_strcmp((const kal_int8*)evt->src_filepath, (const kal_int8*)detail_page->getPath()) == 0)
                        {
                            VfxS32 action = m_action ? m_action->getAction() : 0;
                            // If the query caused from myself, we will allow it
                            if (m_action == NULL || 
                                !(action == VAPP_FMGR_ACTION_DELETE_FOLDER || action == VAPP_FMGR_ACTION_DELETE_SINGLE)
                                || !m_action->getOngoing())
                            {                                
                                return MMI_RET_ERR;
                            }
                        }
                    }
                }
                break;
            #endif // #if !defined(__COSMOS_SLIM_FMGR_MT6260__)
            };
            break;
        }

    #ifdef __MMI_FMGR_FORMAT_WITH_PHONE_LOCK_CONFIRM__                    
        case EVT_ID_VCUI_VERIFY_RESULT:
        case EVT_ID_VCUI_VERIFY_CANCEL:
        {
            mmi_id callerId;
            VfxBool isSuccess;
            if (param->evt_id == EVT_ID_VCUI_VERIFY_RESULT)
            {
                vcui_verify_result_evt_struct *evt = (vcui_verify_result_evt_struct*)param; 
                callerId = evt->sender_id;
                isSuccess = evt->success;
            }
            else
            {
                vcui_verify_cancel_evt_struct *evt = (vcui_verify_cancel_evt_struct*)param;
                callerId = evt->sender_id;
                isSuccess = VFX_FALSE;
            }

            if (m_action != NULL)
            {
                m_action->closeVerifyCui();
                m_action->doFormatEx(isSuccess);                            
            }
            else
            {
                vcui_verify_close(callerId);
            }
            break;
        }
    #endif                    
        default:
            break;
    }

return ret;
}

mmi_ret VappFmgrMain::onMarkSeveralProc(mmi_event_struct *param)
{
    mmi_ret ret = MMI_RET_OK;

    switch (param->evt_id)
    {
#ifdef __MMI_USB_SUPPORT__
    case EVT_ID_USB_ENTER_MS_MODE:
        exitCurApp();
        break;
#endif
    case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
    {
        if (m_action != NULL && m_action->getErrorCode() >= FS_NO_ERROR && !m_action->getWaitConfirm())
        {
            break;
        } 
        
        srv_fmgr_notification_dev_plug_event_struct *evt = (srv_fmgr_notification_dev_plug_event_struct*)param;
        const VfxU8 curDrvLetter = (VfxU8)m_file_path.getBuf()[0];
        for (VfxS32 i = 0; i < evt->count; i++)
        {     
            if (evt->drv_letters[i] != curDrvLetter)
                continue;
            
            // Close mark several, and popup which would like to check in card event
            VFX_OBJ_CLOSE(m_ms);
            VFX_OBJ_CLOSE(m_show_pop);

            // Close folder selector
            if (m_fs_id != GRP_ID_INVALID)
            {
                vcui_folder_selector_close(m_fs_id);
                m_fs_id = GRP_ID_INVALID;
            }

            // If action is waitting for confirm, close it
            if (m_action != NULL && m_action->getWaitConfirm())
            {
                VFX_OBJ_CLOSE(m_action);
            }

            // Back root
            backRoot();
            break;
        }
        break;     
    }

    case EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION:
    {
        // Do not allow to move/delete/rename/create
        srv_fmgr_notification_adv_action_event_struct *evt = (srv_fmgr_notification_adv_action_event_struct*)param;
        if (evt->state != SRV_FMGR_NOTIFICATION_STATE_QUERY)
            break;

        VfxWChar* dstPath = (VfxWChar*)evt->src_filepath;

        if (dstPath != NULL)
        {
            VfxS32 curPathLen = m_file_path.getLength();
            if (m_file_path.getBuf()[(curPathLen-1)] == '\\')
            {
                --curPathLen;
            }
            // Can not create folder in where created folder is same as current file
            if (evt->action == SRV_FMGR_NOTIFICATION_ACTION_CREATE_FOLDER)
            {
                VfxS32 createdPathLen = srv_fmgr_path_get_filename_pos((const WCHAR*)dstPath);
                if (dstPath[(createdPathLen-1)] == '\\')
                {
                    --createdPathLen;
                }

                if (createdPathLen == curPathLen
                    && app_ucs2_strncmp((const kal_int8*)m_file_path.getBuf(), (const kal_int8*)dstPath, curPathLen) == 0
                    && dstPath[curPathLen] == '\\')
                {
                    return MMI_RET_ERR;
                }
            }
        }

        // for copy/move, dst should not be src
        if (evt->action == SRV_FMGR_NOTIFICATION_ACTION_MOVE ||
            evt->action == SRV_FMGR_NOTIFICATION_ACTION_COPY)
        {
            const VfxS32 dstPathLen = app_ucs2_strlen((const kal_int8*)evt->src_filepath);
            if (evt->src_fileinfo.attribute & FS_ATTR_DIR
                && app_ucs2_strncmp((const kal_int8*)evt->src_filepath, (const kal_int8*)evt->dest_filepath, dstPathLen) == 0 &&
                evt->dest_filepath[dstPathLen] == '\\')
            {
                return MMI_RET_ERR;
            }
        }
        break;
    }

    case EVT_ID_VCUI_FOLDER_SELECTOR_RESULT:
    {
        vcui_folder_selector_result_event_struct *evt = (vcui_folder_selector_result_event_struct*)param;
        if (evt->result == 1)
        {
            VfxS8 *path;
            VFX_ALLOC_MEM(path, VAPP_FMGR_FILE_PATH_LEN, this);
            VfxS32 result = vcui_folder_selector_get_selected_filepath(evt->sender_id, NULL, (WCHAR*)path, VAPP_FMGR_FILE_PATH_LEN);
            vcui_folder_selector_close(evt->sender_id);

            if (result >= 0)
            {
                // Got folder path
                m_selected_path.loadFromMem((VfxWChar*)path);
                selectFolderDone((VfxWChar*)path);
            }
            else
            {
                closeMarkSeveral();
                showPopup(srv_fmgr_fs_error_get_string(result), VCP_POPUP_TYPE_FAILURE);
            }
            VFX_FREE_MEM(path);
        }
        else
        {
            vcui_folder_selector_close(evt->sender_id);
        }
        m_fs_id = GRP_ID_INVALID;
        break;
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
/* under construction !*/
/* under construction !*/
#endif
    case EVT_ID_VCUI_FOLDER_SELECTOR_ENABLE_CREATE_FOLDER:
    {
        vcui_folder_selector_query_event_struct *evt = (vcui_folder_selector_query_event_struct*)param;

        if (evt->path != NULL && app_ucs2_strcmp((kal_int8*)evt->path, (const kal_int8*)m_file_path.getBuf()) == 0)
        {
            ret = MMI_RET_ERR;
        }
        break;
    }

    default:
        ret = VappFmgrInstance::onProc(param);
        break;
    }

    return ret;
}

void VappFmgrMain::doFileListDirtyErrorHandle(void)
{
    // Close folder selector
    if (m_fs_id != GRP_ID_INVALID)
    {
        vcui_folder_selector_close(m_fs_id);
        m_fs_id = GRP_ID_INVALID;
    }

    // Close BT 50 files limitation query popup
        VFX_OBJ_CLOSE(m_show_pop);

    // If action is waitting for confirm, close it
    if (m_action != NULL && m_action->getWaitConfirm())
    {
        VFX_OBJ_CLOSE(m_action);
    }
    
    showPopup(STR_ID_VAPP_FMGR_FILE_LIST_IS_DIRTY, VCP_POPUP_TYPE_WARNING);
}

VfxBool VappFmgrMain::error_handler(VfxS32 error_code, VfxS32 line)
{
    VfxBool result = VFX_FALSE;

    VAPP_FMGR_TRACE3(TRC_VAPP_FMGR_MAIN_ERR, "[VAPPFMGR]main error handler, err_code %d, line %d, display_style %d", error_code, line, m_display_style);

    switch (error_code)
    {
        case VAPP_FMGRI_ERROR_FILE_LIST_IS_DIRTY:
        {
            if (m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE)
            {
                closeMarkSeveral();
                doFileListDirtyErrorHandle();
            }
            else
            {
                VfxBool doErrorHandle = VFX_FALSE;
                if (m_opt_menu != NULL || m_show_pop != NULL || m_fs_id != GRP_ID_INVALID || (m_action != NULL && m_action->getWaitConfirm()))
                {
                    doErrorHandle = VFX_TRUE;
                }
                VappFmgrPage* page = (VappFmgrPage*)m_page;
                if (doErrorHandle && page != NULL && page->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrPage)) && 
                    (page->getPageId() >= VappFmgrPage::VAPP_FMGR_DRAW_NORMAL_LIST_PAGE && page->getPageId() <= VappFmgrPage::VAPP_FMGR_DRAW_NORMAL_LIST_LAST_PAGE))
                {
                    // Close long tap option, In page is in file list
                    VFX_OBJ_CLOSE(m_opt_menu);
                    doFileListDirtyErrorHandle();
                }
            }
            break;
        }

        case SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY:
        case SRV_FMGR_FILELIST_ERROR_BUSY:
            result = VappFmgrInstance::error_handler(error_code);
            break;
            
        case FS_MSDC_MOUNT_ERROR:
        case FS_MSDC_READ_SECTOR_ERROR:
        case FS_MSDC_WRITE_SECTOR_ERROR:
        case FS_MSDC_DISCARD_SECTOR_ERROR:
        case FS_MSDC_PRESNET_NOT_READY:
        case FS_MSDC_NOT_PRESENT:
        case FS_DRIVE_NOT_READY:
        case FS_FILE_NOT_FOUND:
            result = VFX_TRUE;
            break;

        case FS_MEDIA_CHANGED:
        case VAPP_FMGR_ERROR_EMPTY:
        case FS_DRIVE_NOT_FOUND:
            if (isFilePathRoot())
            {
    #ifdef __FS_CARD_SUPPORT__
            showPopup(STR_GLOBAL_INSERT_MEMORY_CARD, VCP_POPUP_TYPE_FAILURE);
    #else /* __FS_CARD_SUPPORT__ */
            showPopup(STR_ID_VAPP_FMGR_NO_AVAILABLE_STORAGE, VCP_POPUP_TYPE_FAILURE);
    #endif /* __FS_CARD_SUPPORT__ */
            }
            else
            {
                result = VFX_TRUE;
            }
            break;
            
        default:
            // Popup error
            showPopup(srv_fmgr_fs_error_get_string(error_code), VCP_POPUP_TYPE_FAILURE);
            break;
    }

    return result;
}

VfxS32 VappFmgrMain::launchFileTypeHandler(VAPP_FMGR_FILE_INFO_STRUCT *file_info)
{
    if (file_info == NULL)
        return VAPP_FMGRI_ERROR_PARAM_ERROR;

    filetypes_file_type_enum file_type = file_info->file_type;
    VfxS32 opt_menu = srv_fmgr_types_get_option_menu(file_type, NULL, 0);

    if (GetNumOfChild(opt_menu) == 0)
        return FS_NO_ERROR;

    // Get first child menu item to launch
    VfxS8 *buffer;
    VFX_ALLOC_MEM(buffer, VAPP_FMGR_FILE_PATH_LEN, this);

    VfxS32 fs_ret = composeFilePath(buffer, VAPP_FMGR_FILE_PATH_LEN, m_file_path, file_info->file_name, VFX_FALSE);
    if (fs_ret < 0)
    {
        VFX_FREE_MEM(buffer);
        showPopup(srv_fmgr_fs_error_get_string(fs_ret), VCP_POPUP_TYPE_FAILURE);
        return fs_ret;
    }

    const VfxU16 fileGroup = srv_fmgr_types_find_group_by_type(file_type);
    // base quota shrink when launch video, image, vxp, vpp
#ifdef __MMI_SLIM_FILE_MANAGER__
    if (fileGroup == FMGR_GROUP_VIDEO               //video
        || fileGroup == FMGR_GROUP_IMAGE            //image
#ifndef __MMI_MRE_DISABLE_FMGR__                    //mre
        || file_type == FMGR_TYPE_VXP               //vxp
        || file_type == FMGR_TYPE_VPP               //vpp
#endif
        )
    {
        mmi_id groupId = getGroupId();
        if (groupId == mmi_frm_get_root_app(groupId))
        {
            VfxU32 expUsedSize = mmi_res_get_app_heap_size(groupId) + VAPP_FMGR_IMAGE_DETAIL_THUMB_MEMORY_SIZE+SRV_FMGR_FOLDER_FILELIST_MEM_SIZE;
            mmi_frm_asm_base_shrink_size(groupId, expUsedSize);
        }
    }
#endif

    fs_ret = srv_fmgr_types_launch_option((const WCHAR*)buffer, GetSeqItemId(opt_menu, 0));

    if (fs_ret > 0)
    {        
        if (fileGroup == FMGR_GROUP_IMAGE || fileGroup == FMGR_GROUP_VIDEO)
        {
            setErrHandle(VFX_FALSE);
        }
        /* Launch app successfully so abort loading file list */
        /* Keep file name for highlight when back to fmgr */
        setSearchFilename(m_id, file_info->file_name);
        VappFmgrFSData* fsData = getFSDataObj();
        if (fsData != NULL)
        {
            srv_fmgr_filelist_abort(fsData->getFileListHdlr());
        }
    }
    VFX_FREE_MEM(buffer); 

    return fs_ret;
}

void VappFmgrMain::closeAction(void)
{
    VFX_OBJ_CLOSE(m_action);
}

void VappFmgrMain::closeActionEx(void)
{
    closeAction();
}

void VappFmgrMain::onActionRsp(VfxObject* obj, VfxS32 error_code, VfxBool no_on_confirm)
{
    if (m_action != (VappFmgrGeneralOperation*)obj)
        return ;
    
    if (m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE)
    {
        onActionMarkSeveralRsp(obj, error_code, no_on_confirm);
        return ;
    }

    if (m_ms != NULL)
        return ;

    // Single file operation
    if (no_on_confirm == VFX_TRUE)
    {
        // User press No on confirm popup
        VFX_OBJ_CLOSE(m_action);
        return ;
    }

    if (error_code == FS_NO_ERROR)
    {
        VfxBool need_refresh_menu = VFX_TRUE;
        VfxS32 refresh_type = VENUS_FMGRI_INDEX_NOT_CHANGE;

        switch (m_action->getAction())
        {
        #if !defined(__COSMOS_SLIM_FMGR_MT6260__)
            case VAPP_FMGR_ACTION_SORT:
                refresh_type = VENUS_FMGRI_INDEX_TO_FIRST_POS;
                break;
        #endif //  !defined(__COSMOS_SLIM_FMGR_MT6260__)
            case VAPP_FMGR_ACTION_DELETE_SINGLE:
            case VAPP_FMGR_ACTION_MOVE:
            case VAPP_FMGR_ACTION_RENAME_FILE:
            case VAPP_FMGR_ACTION_RENAME_FOLDER:
            case VAPP_FMGR_ACTION_COPY:
        #if !defined(__COSMOS_SLIM_FMGR_MT6260__)
                // Close detail information
                closeFileDetailPage();
        #endif
                break;
            case VAPP_FMGR_ACTION_FORMAT:                
        #if !defined(__COSMOS_SLIM_FMGR_MT6260__)
                // onEntered of drive page will be triggered. We can let onEntered to do refresh. 
                need_refresh_menu = VFX_FALSE;
                closeStorageReport();                
                changeTabName(SRV_FMGR_DRV_CARD_TYPE);
        #endif        
                break;
        #ifndef __MMI_SLIM_FILE_MANAGER__
            case VAPP_FMGR_ACTION_RENAME_DRIVE:
                need_refresh_menu = VFX_FALSE;
                changeTabName(SRV_FMGR_DRV_CARD_TYPE);
                break;
        #endif //__MMI_SLIM_FILE_MANAGER__
            default:
                break;
        }

        VFX_OBJ_CLOSE(m_action);

        if (need_refresh_menu)
        {
            if (m_display_style != VappFmgrPage::VAPP_FMGR_DRAW_DRV_MEM_PAGE)
                refreshMenu(refresh_type);

            // File operation from long tap option. If mem card list is dirty, reset default folder properity
            m_sf_index = 0;
            VfxS32 fs_ret = prepareSystemFolders();

            if (fs_ret == VAPP_FMGRI_ERROR_PREPARE_SYSTEM_FOLDER_COMPLETE ||
            fs_ret == FS_MSDC_MOUNT_ERROR)
            {
                // prepare system folder flow done.
                m_sf_index = 0;;
                if (fs_ret == VAPP_FMGRI_ERROR_PREPARE_SYSTEM_FOLDER_COMPLETE)
                {
                    refreshMenu(VENUS_FMGRI_INDEX_NOT_CHANGE);
                }
                else
                {
                    refreshMenu(VENUS_FMGRI_INDEX_ERROR_CODE, FS_MSDC_MOUNT_ERROR);
                }
            }
        }
    }
    else
    {
        // Show error message if action is rename or create folder
        const VfxU32 action  = m_action->getAction();
        if (action == VAPP_FMGR_ACTION_RENAME_DRIVE ||
            action == VAPP_FMGR_ACTION_RENAME_FILE ||
            action == VAPP_FMGR_ACTION_RENAME_FOLDER ||
            action == VAPP_FMGR_ACTION_CREATE_FOLDER)
        {
            showPopup(srv_fmgr_fs_error_get_string(error_code), VCP_POPUP_TYPE_FAILURE);
        }

        VFX_OBJ_CLOSE(m_action);

        VappFmgrPage* page = (VappFmgrPage*)m_page;
        if (m_page != NULL)
        {
            const VfxU16 page_id = page->getPageId();

            if (page_id == VappFmgrPage::VAPP_FMGR_DRAW_DRV_PHONE_PAGE ||
                page_id == VappFmgrPage::VAPP_FMGR_DRAW_DRV_MEM_PAGE ||
                page_id == VappFmgrPage::VAPP_FMGR_DRAW_FOLDER_BROWSER_LAUNCH_PAGE ||
                (page_id >= VappFmgrPage::VAPP_FMGR_DRAW_NORMAL_LIST_PAGE && page_id <= VappFmgrPage::VAPP_FMGR_DRAW_NORMAL_LIST_LAST_PAGE))
            {
                // Refresh menu if it is file list page currently
                refreshMenu(VENUS_FMGRI_INDEX_NOT_CHANGE);
            }
        }
    }
}

void VappFmgrMain::onActionMarkSeveralRsp(VfxObject* obj, VfxS32 error_code, VfxBool no_on_confirm)
{
    if (m_ms == NULL)
        return;

    if (no_on_confirm == VFX_TRUE)
    {
        // User press No on confirm popup
        VFX_OBJ_CLOSE(m_action);
        return;
    }

    if (error_code < FS_NO_ERROR)
    {
        VAPP_FMGR_TRACE1(TRC_VAPP_FMGR_ACTION_MS_RSP, "[VAPPFMGR]onActionMarkSeveralRsp, error code %d", error_code);
        closeMarkSeveral();

        if (error_code == FS_MEDIA_CHANGED ||
            (error_code <= FS_MSDC_MOUNT_ERROR && error_code >= FS_MSDC_NOT_PRESENT))
        {
            VfxU8 drv_letter = (VfxU8)m_action->getSrcPath().getBuf()[0];

            if (srv_fmgr_drv_get_type((U8)drv_letter) == SRV_FMGR_DRV_CARD_TYPE)
            {
                backRoot();
            }
        }
        
        VFX_OBJ_CLOSE(m_action);
        refreshMenu(VENUS_FMGRI_INDEX_NOT_CHANGE);
    }
    else
    {
        VfxS8 *buffer = NULL;
        VfxS8 *marked_file_name;
        VfxBool isfolder = VFX_FALSE;
        VfxS32 fs_ret = 0;

        m_ms->pop(this);
        VFX_ALLOC_MEM(marked_file_name, VENUS_FMGR_FILENAME_BUF_LEN, this);
        if (m_ms->getCount() > 0 &&
            (fs_ret = m_ms->top(this, marked_file_name, VENUS_FMGR_FILENAME_BUF_LEN_RESERVED, NULL, &isfolder)) == VappFmgrMultiSelect::VAPP_FMGR_MSA_ERROR_NONE)
        {
            // Next one
            VFX_ALLOC_MEM(buffer, VAPP_FMGR_FILE_PATH_LEN, this);
            fs_ret = composeFilePath(buffer, VAPP_FMGR_FILE_PATH_LEN, m_file_path, marked_file_name, VFX_FALSE);
            if (fs_ret < 0)
            {
                VFX_FREE_MEM(marked_file_name);
                VFX_FREE_MEM(buffer);
                VFX_OBJ_CLOSE(m_action);

                closeMarkSeveral();
                showPopup(srv_fmgr_fs_error_get_string(fs_ret), VCP_POPUP_TYPE_FAILURE);
                refreshMenu(VENUS_FMGRI_INDEX_NOT_CHANGE);
                return;
            }

            if (isfolder)
            {
                // cate complete dst path
                VfxS8 *path;
                VFX_ALLOC_MEM(path, VAPP_FMGR_FILE_PATH_LEN, this);
                VfxWString tmp = m_action->getSelectedPath();
                fs_ret = composeFilePath(path, VAPP_FMGR_FILE_PATH_LEN, tmp, marked_file_name, VFX_FALSE);
                if (fs_ret < 0)
                {
                    VFX_FREE_MEM(path);
                    VFX_FREE_MEM(marked_file_name);
                    VFX_FREE_MEM(buffer);
                    VFX_OBJ_CLOSE(m_action);
                    closeMarkSeveral();

                    showPopup(srv_fmgr_fs_error_get_string(fs_ret), VCP_POPUP_TYPE_FAILURE);
                    refreshMenu(VENUS_FMGRI_INDEX_NOT_CHANGE);
                    return;
                }

                if ((m_action->getAction() == VAPP_FMGR_ACTION_MARK_COPY || m_action->getAction() == VAPP_FMGR_ACTION_MARK_MOVE) 
                    && app_ucs2_strcmp((const kal_int8*)buffer, (const kal_int8*)path) == 0)
                {
                    VFX_FREE_MEM(path);
                    VFX_FREE_MEM(marked_file_name);
                    VFX_FREE_MEM(buffer);
                    VFX_OBJ_CLOSE(m_action);
                    closeMarkSeveral();
                    showPopup(srv_fmgr_fs_error_get_string(FS_FILE_EXISTS), VCP_POPUP_TYPE_FAILURE);
                    refreshMenu(VENUS_FMGRI_INDEX_NOT_CHANGE);
                    return;
                }
                
                m_action->setDstPath(path);
                VFX_FREE_MEM(path);
            }

            VFX_FREE_MEM(marked_file_name);

            if (isfolder)
            {
                srv_fmgr_fileinfo_struct srv_info;
                srv_info.attribute = FS_ATTR_DIR;
                srv_info.size = 0;
                m_action->setSrcFileInfo(&srv_info);
            }
            m_action->setSrcPath(buffer);
            m_action->run();
        }
        else
        {
            if (fs_ret < 0)
            {
                // show error
                m_action->closeProcessing_ex();
                m_action->showActionResult(srv_fmgr_fs_error_get_string(fs_ret), VFX_FALSE, fs_ret, VFX_FALSE);
            }
            else
            {
                // No more marked item
                VFX_FREE_MEM(marked_file_name);
                VFX_FREE_MEM(buffer);
                VFX_OBJ_CLOSE(m_action);

                closeMarkSeveral();
                refreshMenu(VENUS_FMGRI_INDEX_NOT_CHANGE);
            }
        }

        VFX_FREE_MEM(marked_file_name);
        VFX_FREE_MEM(buffer);
    }
}

void VappFmgrMain::showLongTapOption(VfxS8* file_name, VfxBool isfolder)
{
    // touch feedback before popup long tap option menu
	vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
	
	VFX_OBJ_CREATE(m_opt_menu, VcpMenuPopup, this);

	m_opt_menu->setTitle((VfxWChar*)file_name);

	VcpMenuPopupItem *item;
	item = m_opt_menu->createMenuItem(MENU_ID_FMGR_OPTION_RENAME, STR_GLOBAL_RENAME);
	m_opt_menu->insertItem(NULL, NULL, item);
		
	if (!isfolder && !isComposeFilePathOverLen(m_file_path, file_name, VFX_FALSE))
	{
		item = m_opt_menu->createMenuItem(MENU_ID_FMGR_OPTION_SHARE_SINGLE, STR_GLOBAL_SHARE);
		m_opt_menu->insertItem(NULL, NULL, item);		
	}
	item = m_opt_menu->createMenuItem(MENU_ID_FMGR_OPTION_DELETE_SINGLE, STR_GLOBAL_DELETE);
	m_opt_menu->insertItem(NULL, NULL, item);
	
	m_opt_menu->m_signalMenuCallback.connect(this, &VappFmgrMain::onClickMenuPopup);
	
	m_opt_menu->showMenu();
}

void VappFmgrMain::onLongTapListMenuItem(VcpListMenu *listmenu, VfxU32 index)
{
    if (m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE)
        return ;
    
    srv_fmgr_fileinfo_struct file_info;

    // Reset select group and index
    m_selected_pos.invalid();
    m_selected_index = -1;
    
    VFX_ASSERT(getFSDataObj() != NULL);

    SRV_FMGR_FILELIST_HANDLE fileListHdlr = getFSDataObj()->getFileListHdlr();
    srv_fmgr_filelist_state_enum state = srv_fmgr_filelist_get_state(fileListHdlr);
    if (state != SRV_FMGR_FILELIST_STATE_READY ||
        m_instance_type == VappFmgrInstance::VAPP_FMGR2_TYPE_FOLDER_BROWSER)
    {
        return;
    }

    memset(&file_info, 0, sizeof(srv_fmgr_fileinfo_struct));
    VfxS32 fs_ret = srv_fmgr_filelist_get_fileinfo(fileListHdlr, index, &file_info);
    if (fs_ret < 0)
    {
        error_handler(fs_ret);
        return;
    }
    VfxS8 *buffer;
    VFX_ALLOC_MEM(buffer, VAPP_FMGR_FILE_PATH_LEN, this);
    memset(buffer, 0, VAPP_FMGR_FILE_PATH_LEN);
    fs_ret = srv_fmgr_filelist_get_filename(fileListHdlr, index, (WCHAR*)buffer, VAPP_FMGR_FILE_PATH_LEN);
    if (fs_ret < 0)
    {
        showPopup(srv_fmgr_fs_error_get_string(fs_ret), VCP_POPUP_TYPE_FAILURE);
        VFX_FREE_MEM(buffer);
        return;
    }

    m_selected_index = index;
    showLongTapOption(buffer, (file_info.attribute & FS_ATTR_DIR)? VFX_TRUE : VFX_FALSE);

    VFX_FREE_MEM(buffer);
}

void VappFmgrMain::onLongTapGroupListMenuItem(VcpGroupListMenu *listmenu, VcpMenuPos pos)
{
    if (pos.group <= 0)
        return ;

    VfxS32 index = pos.pos;
    VAPP_FMGR_FILE_INFO_STRUCT *file_info;

    /* Reset select group and index */
    m_selected_pos.invalid();
    m_selected_index = -1;
    VappFmgrFSData* fsData = getFSDataObj();
    VFX_ASSERT(fsData != NULL);

    srv_fmgr_filelist_state_enum state = srv_fmgr_filelist_get_state(fsData->getFileListHdlr());
    if (state != SRV_FMGR_FILELIST_STATE_READY ||
        m_instance_type == VappFmgrInstance::VAPP_FMGR2_TYPE_FOLDER_BROWSER)
    {
        return;
    }

    VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
    memset(file_info, 0, sizeof(VAPP_FMGR_FILE_INFO_STRUCT));
    VfxS32 fs_ret = fsData->getFileInfo(this, index, file_info);
    if (fs_ret < 0)
    {
        showPopup(srv_fmgr_fs_error_get_string(fs_ret), VCP_POPUP_TYPE_FAILURE);
        VFX_FREE_MEM(file_info);
        return;
    }

    m_selected_pos = pos;
    showLongTapOption(file_info->file_name, (file_info->attribute & FS_ATTR_DIR)? VFX_TRUE : VFX_FALSE);
    VFX_FREE_MEM(file_info);
}

void VappFmgrMain::onTapListMenuItem(VcpListMenu *listmenu, VfxU32 index)
{
    if (m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE)
    {
        onTapMarkSeveralListMenuItem(listmenu, index);
        return ;
    }

    if (getFSDataObj() == NULL)
        return ;
    
    VAPP_FMGR_FILE_INFO_STRUCT *file_info;
    VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
    VfxS32 fs_ret = getFSDataObj()->getFileInfo(this, index, file_info);

    if (fs_ret < 0)
    {
        VFX_FREE_MEM(file_info);
        showPopup(srv_fmgr_fs_error_get_string(fs_ret), VCP_POPUP_TYPE_FAILURE);
        return ;
    }

    m_cur_index = index;

    if (file_info->attribute & FS_ATTR_DIR)
    {
        m_display_style = VappFmgrPage::VAPP_FMGR_DRAW_NORMAL_LIST_PAGE;
        enterFolder(file_info->file_name);
    }
    else
    {
        launchFileTypeHandler(file_info);
    }
    VFX_FREE_MEM(file_info);
}

void VappFmgrMain::onTapMarkSeveralListMenuItem(VcpListMenu *listmenu, VfxU32 index)
{
    VappFmgrFSData* fsData = getFSDataObj();
    if (fsData == NULL)
        return ;
    
    VAPP_FMGR_FILE_INFO_STRUCT *file_info;
    do {        
        VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
        fsData->getFileInfo(this, index, file_info);

        if (m_ms == NULL)
        {
            VFX_OBJ_CREATE(m_ms, VappFmgrMultiSelect, this);
            m_ms->createMSA(fsData->getCount());
        }

        // Multi-select case
        VfxS16 idx = m_ms->isMarked(this, index);
        if (idx != VappFmgrMultiSelect::VAPP_FMGR_MSA_ERROR_FILE_NOT_FOUND)
        {
            m_ms->remove_by_array_idx(this, idx);
            if (m_ms->getCount() == 0 || (m_ms->getAllowToMarkCount() - m_ms->getCount()) == 1)
            {
                // update option menu
                if (m_page != NULL)
                {
                    VappFmgrPage *page = (VappFmgrPage*)m_page;
                    page->updatePageOptionMenu(this, m_display_style);
                }
            }
        }
        else
        {
            VfxS8 flag = 0;
            if (m_ms->isProtectedFile((VfxWChar*)file_info->file_name))
            {
                m_ms->setSendableFlag(&flag);
            }

            if (file_info->attribute & FS_ATTR_DIR)
            {
                m_ms->setFolderFlag(&flag);
            }

            if (m_ms->add(this, index, flag) < 0)
            {
                // error handling
                break;
            }

            const VfxS32 marked_count = m_ms->getCount();
            if (marked_count == 1 || marked_count == m_ms->getAllowToMarkCount())
            {
                // update option menu
                if (m_page != NULL)
                {
                    VappFmgrPage *page = (VappFmgrPage*)m_page;
                    page->updatePageOptionMenu(this, m_display_style);
                }
            }
        }
    } while(0);

    VFX_FREE_MEM(file_info);
}

void VappFmgrMain::onTapGroupListMenuItem(VcpGroupListMenu *listmenu, VcpMenuPos pos)
{
    VAPP_FMGR_TRACE2(TRC_VAPP_FMGR_ONTAPGROUPLISTITEM, "[VAPPFMGR]onTapGroupListMenuItem, group %d, pos %d", pos.group, pos.pos);
    if (getFSDataObj() == NULL || pos.pos < 0)
        return ;
    
    const VfxS32 index = pos.pos;
    // System folder
    if (pos.group == 0 )
    {
        if (m_system_folder_properity[index].exist < 0)
        {
            showPopup(srv_fmgr_fs_error_get_string(FS_PATH_NOT_FOUND), VCP_POPUP_TYPE_FAILURE);
            return ;
        }

        m_group_pos = pos;
        enterFolder((VfxS8*)g_def_folder_table[index].path);
    }
    // User defined
    else if (pos.group == 1)
    {
        VAPP_FMGR_FILE_INFO_STRUCT *file_info;
        VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
        VfxS32 fs_ret = getFSDataObj()->getFileInfo(this, index, file_info);

        if (fs_ret < 0)
        {
            showPopup(srv_fmgr_fs_error_get_string(fs_ret), VCP_POPUP_TYPE_FAILURE);
            VFX_FREE_MEM(file_info);
            return;
        }

        m_group_pos = pos;

        if (file_info->attribute & FS_ATTR_DIR)
        {
            enterFolder(file_info->file_name);
        }
        else
        {
            launchFileTypeHandler(file_info);
        }
        VFX_FREE_MEM(file_info);
    }
}

void VappFmgrMain::onClickMenuPopup(VcpMenuPopup* opt_menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem* item)
{
	if (event == VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
	{
		onClickToolBarButton(this, item->getId());
	}
}

// TODO:
#if defined(__COSMOS_SLIM_FMGR_MT6260__)
void VappFmgrMain::onStorageBtnClicked(VfxObject* obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
       onClickToolBarButton(obj, MENU_ID_FMGR_OPTION_FORMAT_CARD);
    }
    mStorageReportPop = NULL;
}

void VappFmgrMain::storageReportPopup(VfxId drvId)
{
    VfxU8 drv_letter = srv_fmgr_drv_get_letter_by_type((srv_fmgr_drv_type_enum)(drvId-1));
    VfxS32 fsRet = FS_GetDevStatus(drv_letter, FS_MOUNT_STATE_ENUM);
    if (fsRet != FS_NO_ERROR)
        return ;
        
    VfxU64 disk_total_space;
    VfxU64 disk_free_space;
    srv_fmgr_drv_get_size(drv_letter, &disk_total_space, &disk_free_space);
    
    VfxWString textTotal;
    VfxWString textFree;
    getSizeString(textTotal, disk_total_space);
    getSizeString(textFree, disk_free_space);

    // Total
    VfxWString report(STR_ID_VAPP_FMGR_TOTAL);
    VfxWString temp((const VfxWChar*)L": ");
    report += temp;
    report += textTotal;

    // Free
    report += temp.format("\n");
    report += temp.loadFromRes(STR_ID_VAPP_FMGR_FREE);
    report += temp.format(": ");
    report += textFree; 

    VcpConfirmPopup *popup;
    VFX_OBJ_CREATE(popup, VcpConfirmPopup, findScreen());
    
    popup->setInfoType(VCP_POPUP_TYPE_INFO);
    popup->setAutoDestory(VFX_TRUE);
    popup->setText(report);
    popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);    
    //popup->m_signalPopupState.connect(this, &VappFmgrInstance::onPopupStateChange);

    /* The case only for sharing multi files via BT currently */
    popup->m_signalButtonClicked.connect(this, &VappFmgrMain::onStorageBtnClicked);
    popup->setCustomButton(STR_ID_VAPP_FMGR_OPTION_FORMAT, STR_GLOBAL_CLOSE, VCP_POPUP_BUTTON_TYPE_NORMAL, VCP_POPUP_BUTTON_TYPE_CANCEL);
    mStorageReportPop = popup;

    popup->show(VFX_TRUE);
}
#endif

void VappFmgrMain::onClickToolBarButton(VfxObject* obj, VfxId button_id)
{
    VfxU16 err_str = 0;
    VfxS8 *buffer = NULL;
    VfxS32 fs_ret = 0, index = -1;
    VcpPopupTypeEnum popup_type = VCP_POPUP_TYPE_FAILURE;
    VfxWString action_file_path;
    VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;
    VappFmgrFSData *fsdata = getFSDataObj();

    if (m_action == NULL)
    {
        if (m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE)
        {
            onClickMarkSeveralToolBarButton(obj, button_id);
        }
        else
        {
            switch (button_id)
            {
                case MENU_ID_FMGR_STORAGE_REPORT:
                {
                    // Storage report
                    VfxId default_tab_id = SRV_FMGR_DRV_PHONE_TYPE+1;
                    if (m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_DRV_MEM_PAGE)
                    {
                        default_tab_id = SRV_FMGR_DRV_CARD_TYPE+1;
                    }
                    
                    VfxMainScr *scr = VfxMainScr::findMainScr((VfxFrame*)m_page);
                #ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
                    VappFmgrStorageReport *tabctrlpage;
                    VFX_OBJ_CREATE_EX(tabctrlpage, VappFmgrStorageReport, scr, (default_tab_id, this));
                    tabctrlpage->setInstance(this);
                    tabctrlpage->setCurrTab(default_tab_id);
                    scr->pushPage((VappFmgrPage::VAPP_FMGR_DRAW_STORAGE_REPORT+1), tabctrlpage);                        
                #else
                    #if !defined(__COSMOS_SLIM_FMGR_MT6260__)
                    VappFmgrStorageDetail *page;
                    VFX_OBJ_CREATE_EX(page, VappFmgrStorageDetail, this, (VappFmgrPage::VAPP_FMGR_DRAW_STORAGE_DETAIL_MEM_PAGE, this));
                    page->drawInit(SRV_FMGR_DRV_CARD_TYPE+1);

                    page->m_signalGetOptMenuItem.connect(this, &VappFmgrMain::getOptionItem);
                    page->m_signalGetTitleStrAndIcn.connect(this, &VappFmgrMain::getTitleStrAndIcn);
                    page->updatePageOptionMenu(this, 10);
                    scr->pushPage((VappFmgrPage::VAPP_FMGR_DRAW_STORAGE_DETAIL_MEM_PAGE+1), page);
                    #else
                        // TODO:
                        // Popup up a pop. to give the memory usage.
                        storageReportPopup(default_tab_id);
                    #endif
                #endif
                    break;
                }

            case MENU_ID_FMGR_OPTION_FORMAT_PHONE:
            case MENU_ID_FMGR_OPTION_FORMAT_CARD:
            {
                // Format
                VFX_OBJ_CREATE(m_action, VappFmgrGeneralOperation, this);
                m_action->setCallerGroupId(m_gid);
                m_action->setAction(VAPP_FMGR_ACTION_FORMAT);

                srv_fmgr_drv_type_enum srcDrv = SRV_FMGR_DRV_PHONE_TYPE;                
                if (button_id != MENU_ID_FMGR_OPTION_FORMAT_PHONE)
                {
                    srcDrv = SRV_FMGR_DRV_CARD_TYPE;
                }
                
                m_action->setSrcDrv(srcDrv);
                m_action->m_signalActionRsp.connect(this, &VappFmgrMain::onActionRsp);
                fs_ret = m_action->run();
                break;
            }
        #if !defined(__COSMOS_SLIM_FMGR_MT6260__)
            case MENU_ID_FMGR_OPTION_OPEN:
                {
                // Click from detail information

                do {
                    // System folder group = 0, userdefined group = 1
                    // And else group = -1, but the selected index should be valid
                    if (m_selected_pos.group == 0)
                    {
                        fs_ret = m_system_folder_properity[m_selected_pos.pos].exist;
                        if (fs_ret < 0)
                        {
                            break;
                        }

                        enterFolder((VfxS8*)g_def_folder_table[m_selected_pos.pos].path);
                        // Close detail information
                        closeFileDetailPage();
                        break;
                    }
                    else if (m_selected_pos.group == 1)
                    {
                        index = m_selected_pos.pos;
                    }
                    else
                    {
                        index = m_selected_index;
                    }

                    if (index < 0)
                    {
                        fs_ret = FS_PARAM_ERROR;
                        break;
                    }

                    // Get file info
                    VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
                    if (fsdata != NULL)
                    {
                        fs_ret = fsdata->getFileInfo(this, index, file_info);
                        if (fs_ret < 0)
                        {
                            break;
                        }
                    }

                    if (file_info->attribute & FS_ATTR_DIR)
                    {
                        // enter folder
                        enterFolder(file_info->file_name);
                    }
                    else
                    {
                        /* launch file type app */
                        launchFileTypeHandler(file_info);
                    }

                    // Close detail information
                    closeFileDetailPage();
                } while(0);

                VFX_FREE_MEM(file_info);

                if (fs_ret < 0)
                {
                    showPopup(srv_fmgr_fs_error_get_string(fs_ret), VCP_POPUP_TYPE_FAILURE);
                }
                break;
            }
        #endif // #if !defined(__COSMOS_SLIM_FMGR_MT6260__)
            case MENU_ID_FMGR_OPTION_DELETE_SINGLE:
            {
                do {
                    // System defined folder can not be delete
                    if (m_selected_pos.group == 0)
                    {
                        break;
                    }
                    else if (m_selected_pos.group == 1)
                    {
                        index = m_selected_pos.pos;
                    }
                    else
                    {
                        index = m_selected_index;
                    }

                    if (index < 0)
                    {
                        fs_ret = FS_PARAM_ERROR;
                        break;
                    }

                    // Get file info
                    VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
                    if (fsdata != NULL)
                    {
                        fs_ret = fsdata->getFileInfo(this, index, file_info);
                        if (fs_ret < 0)
                        {
                            break;
                        }
                    }

                    VFX_ALLOC_MEM(buffer, VAPP_FMGR_FILE_PATH_LEN, this);
                    fs_ret = composeFilePath(buffer, VAPP_FMGR_FILE_PATH_LEN, m_file_path, file_info->file_name, VFX_FALSE);
                    if (fs_ret < 0)
                    {
                        break;
                    }

                    VFX_OBJ_CREATE(m_action, VappFmgrGeneralOperation, this);
                    m_action->setCallerGroupId(m_gid);
                    m_action->setAction(VAPP_FMGR_ACTION_DELETE_SINGLE);
                    m_action->setSrcPath(buffer);
                    m_action->m_signalActionRsp.connect(this, &VappFmgrMain::onActionRsp);
                    m_action->setCanCancel(VFX_FALSE);
                    fs_ret = m_action->run();
                } while(0);

                if (fs_ret < 0)
                {
                    showPopup(srv_fmgr_fs_error_get_string(fs_ret), VCP_POPUP_TYPE_FAILURE);
                }
                break;
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
            case MENU_ID_FMGR_OPTION_COPY_TO:
            case MENU_ID_FMGR_OPTION_MOVE_TO:
            {
                m_fs_id = vcui_folder_selector_create(m_gid, (const WCHAR*)L"root", VCUI_FOLDER_SELECTOR_STYLE_WRITE, VCUI_FOLDER_SELECTOR_OPT_FIXED_PATH_ON);
                if (m_fs_id != GRP_ID_INVALID)
                {
                    if (button_id == MENU_ID_FMGR_OPTION_COPY_TO)
                    {
                        m_file_action = VAPP_FMGR_ACTION_COPY;
                    }
                    else
                    {
                        m_file_action = VAPP_FMGR_ACTION_MOVE;
                    }
                    vcui_folder_selector_run(m_fs_id);
                }
                break;
            }

            case MENU_ID_FMGR_OPTION_COPY:
            case MENU_ID_FMGR_OPTION_MOVE:
            case MENU_ID_FMGR_OPTION_DELETE:
            case MENU_ID_FMGR_OPTION_SHARE:
            {
                VfxU16 opt_menu = MENU_ID_FMGR_OPTION_MULTI_SELECT;
                resetOptMenu(opt_menu);
                const VfxU16 opt_menu_num = GetNumOfChild(opt_menu);

                for (VfxU16 i = 2; i < opt_menu_num-1; ++i)
                {
                    // skip Select all(0), Unselect all(1) and cancel(last)
                    VfxU16 child_id = GetSeqItemId(opt_menu, i);
                    if (child_id != button_id)
                    {
                        mmi_frm_hide_menu_item(child_id);
                    }
                }

                m_opt_menu_id = opt_menu;
                m_ms_title_id = GetStringIdOfItem(button_id);

                if (m_listmenu != NULL)
                {
                    m_display_style = VappFmgrPage::VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE;
                    m_listmenu->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_TRUE);
                    m_listmenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL, VFX_FALSE);

                    // Update title and option menu
                    VappFmgrPage* page = (VappFmgrPage*)m_page;
                    if (page != NULL && page->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrPage)))
                    {
                        page->updatePageTitle(this, m_display_style);
                        VfxU16 removed_opt_menu = MENU_ID_FMGR_GEN_OPTIONS;
                        page->removeAllButtonsFromToolbar(removed_opt_menu);
                        page->updatePageOptionMenu(this, m_display_style);
                    }

                    if (m_ms == NULL)
                    {
                        VFX_OBJ_CREATE(m_ms, VappFmgrMultiSelect, this);

                        if (fsdata != NULL )
                        {
                            m_ms->createMSA(fsdata->getCount());
                            if (button_id == MENU_ID_FMGR_OPTION_SHARE)
                            {
                                m_ms->setAllowToMarkCount(fsdata->getFileCount());
                            }
                            else
                            {
                                m_ms->setAllowToMarkCount(fsdata->getCount());
                            }
                        }
                    }
                #ifdef __VAPP_FMGR_DIR_CTRL__
                    // lock dir cache
                    FS_HANDLE fh;
                    fh = FS_Open((WCHAR*)m_file_path.getBuf(), FS_READ_ONLY | FS_OPEN_SHARED | FS_OPEN_DIR);
                    if(fh >= 0)
                    {
                        FS_DirCtrl(fh, FS_DIRCTRL_DATA_LOCK, NULL);
                        FS_Close(fh);
                    }
                #endif
                }
                break;
            }

#if defined( __FS_SORT_SUPPORT__) && !defined(__COSMOS_SLIM_FMGR_MT6260__)
            case MENU_ID_FMGR_OPTION_SORT:
            {
                if (fsdata != NULL)
                {
                    VFX_OBJ_CREATE(m_action, VappFmgrGeneralOperation, this);
                    m_action->setCallerGroupId(m_gid);
                    m_action->setAction(VAPP_FMGR_ACTION_SORT);
                    m_action->setDeleteFilterType(&filter_type);
                    m_action->setFileListHdle(fsdata->getFileListHdlr());
                    m_action->m_signalActionRsp.connect(this, &VappFmgrMain::onActionRsp);
                    m_action->run();
                }
            }
            break;
#endif // #if defined( __FS_SORT_SUPPORT__) && !defined(__COSMOS_SLIM_FMGR_MT6260__)
            case MENU_ID_FMGR_OPTION_NEW_FOLDER:
                VFX_OBJ_CREATE(m_action, VappFmgrGeneralOperation, this);
                m_action->setCallerInstanceId(m_id);
                m_action->setCallerGroupId(m_gid);
                m_action->setAction(VAPP_FMGR_ACTION_CREATE_FOLDER);
                m_action->setSrcPath(m_file_path);
                m_action->m_signalActionRsp.connect(this, &VappFmgrMain::onActionRsp);
                fs_ret = m_action->run();
                break;
            case MENU_ID_FMGR_OPTION_RENAME:
            {
                do {
                    // System folder cannot be rename.
                    if (m_selected_pos.group == 0)
                    {
                        break;
                    }
                    else if (m_selected_pos.group == 1)
                    {
                        index = m_selected_pos.pos;
                    }
                    else
                    {
                        index = m_selected_index;
                    }

                    if (index < 0)
                    {
                        fs_ret = FS_PARAM_ERROR;
                        break;
                    }

                    // Get file info
                    VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
                    if (fsdata != NULL)
                    {
                        fs_ret = fsdata->getFileInfo(this, index, file_info);
                        if (fs_ret < 0)
                        {
                            break;
                        }
                    }
                    VfxBool add_end_slash = VFX_FALSE;
                    VfxU32 action = VAPP_FMGR_ACTION_RENAME_FILE;
                    if (file_info->attribute & FS_ATTR_DIR)
                    {
                        action = VAPP_FMGR_ACTION_RENAME_FOLDER;
                    }

                    if (isComposeFilePathOverLen(m_file_path, file_info->file_name, add_end_slash))
                    {
                        fs_ret = FS_PATH_OVER_LEN_ERROR;
                        break;
                    }

                    VFX_OBJ_CREATE(m_action, VappFmgrGeneralOperation, this);
                    m_action->setCallerGroupId(m_gid);
                    m_action->setAction(action);
                    m_action->setSrcPath(m_file_path);
                    m_action->setFilename(file_info->file_name);
                    m_action->m_signalActionRsp.connect(this, &VappFmgrMain::onActionRsp);
                    m_action->setCanCancel(VFX_TRUE);
                    fs_ret = m_action->run();
                } while(0);

                VFX_FREE_MEM(file_info);

                if (fs_ret < 0)
                {
                    showPopup(srv_fmgr_fs_error_get_string(fs_ret), VCP_POPUP_TYPE_FAILURE);
                }
                break;
            }

#ifndef __MMI_SLIM_FILE_MANAGER__
            case MENU_ID_FMGR_OPTION_RENAME_DRIVE:
            {
                VfxU8 drv_letter = srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE);
                VfxWChar drv_name[40];

                fs_ret = srv_fmgr_drv_get_name(drv_letter, (WCHAR*)drv_name, sizeof(VfxWChar)*40);
                if (fs_ret == 0)
                {
                    VFX_OBJ_CREATE(m_action, VappFmgrGeneralOperation, this);
                    m_action->setCallerGroupId(m_gid);
                    m_action->setAction(VAPP_FMGR_ACTION_RENAME_DRIVE);
                    m_action->setFilename((VfxS8*)drv_name);
                    m_action->setSrcDrv(SRV_FMGR_DRV_CARD_TYPE);
                    m_action->m_signalActionRsp.connect(this, &VappFmgrMain::onActionRsp);
                    fs_ret = m_action->run();
                }
                break;
            }
#endif // __MMI_SLIM_FILE_MANAGER__
            case MENU_ID_FMGR_OPTION_SHARE_SINGLE:
            {                        
                if (fsdata != NULL)
                {
                    // System folder cannot be shared.
                    if (m_selected_pos.group == 0)
                    {
                        break;
                    }
                    else if (m_selected_pos.group == 1)
                    {
                        index = m_selected_pos.pos;
                    }
                    else
                    {
                        index = m_selected_index;
                    }

                    if (index < 0)
                    {
                        fs_ret = FS_PARAM_ERROR;
                        break;
                    }

                    // Get file info
                    VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
                    if (fsdata != NULL)
                    {
                        fs_ret = fsdata->getFileInfo(this, index, file_info);
                        if (fs_ret < 0)
                        {
                            break;
                        }

                        if (file_info->attribute & FS_ATTR_DIR)
                        {
                            fs_ret = FS_PARAM_ERROR;
                            break;
                        }
                    }

                    VFX_ALLOC_MEM(buffer, VAPP_FMGR_FILE_PATH_LEN, this);
                    if (composeFilePath(buffer, VAPP_FMGR_FILE_PATH_LEN, m_file_path, file_info->file_name, VFX_FALSE))
                    {
                        err_str = STR_ID_VAPP_FMGR_DRM_AND_PATH_OVER_LEN_FAIL;
                        popup_type = VCP_POPUP_TYPE_INFO;
                        break;
                    }

                // Check DRM permission
        #ifdef __DRM_SUPPORT__
                    fs_ret = mmi_rmgr_check_forward((WCHAR*)buffer);

                    if (fs_ret >= 0 && (!(fs_ret & MMI_RMGR_USAGE_SEND)))
                    {
                        err_str = STR_ID_VAPP_FMGR_DRM_AND_PATH_OVER_LEN_FAIL;
                        popup_type = VCP_POPUP_TYPE_INFO;
                        break;
                    }
        #endif

                    VFX_OBJ_CREATE(m_action, VappFmgrGeneralOperation, this);
                    m_action->setCallerGroupId(m_gid);
                    m_action->setAction(VAPP_FMGR_ACTION_SHARE_SINGLE);
                    m_action->setSrcPath(buffer);
                    m_action->m_signalActionRsp.connect(this, &VappFmgrMain::onActionRsp);
                    m_action->run();
                }
                break;
            }

            default:
                break;
            };
        }
    }

        VFX_FREE_MEM(buffer);
        VFX_FREE_MEM(file_info);

    if (fs_ret < 0 || err_str > 0)
    {
        if (err_str == 0)
        {
            err_str = srv_fmgr_fs_error_get_string(fs_ret);
        }
        if (err_str == STR_ID_VAPP_FMGR_DRM_AND_PATH_OVER_LEN_FAIL)
        {
            /* Use balloon */
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)GetString(STR_ID_VAPP_FMGR_DRM_AND_PATH_OVER_LEN_FAIL));
        }
        else
        {
            showPopup(err_str, popup_type);
        }
    }    
}

void VappFmgrMain::onClickMarkSeveralToolBarButton(VfxObject* obj, VfxId button_id)
{
	VfxS8   *marked_file_name = NULL;
	VfxWString action_file_path;
	
	if (m_action == NULL)
	{		
		switch (button_id)
		{
			case MENU_ID_FMGR_OPTION_SELECT_ALL:
				{
					VappFmgrFSData *fsdata = getFSDataObj();
					if (fsdata != NULL)
					{
						if (m_ms == NULL)
						{					
							VFX_OBJ_CREATE(m_ms, VappFmgrMultiSelect, this);
							m_ms->createMSA(fsdata->getCount());
						}
						
						if (m_ms != NULL)
						{
						    VfxS32 selected_num = 0, start = 0;
                            
						    if (m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE 
                                && m_ms_title_id == GetStringIdOfItem(MENU_ID_FMGR_OPTION_SHARE))
                			{                				                                
                                selected_num = fsdata->getFileCount();

                                start = fsdata->getFolderCount();
                			}
                            else
                            {
    							selected_num = fsdata->getCount();
                            }

                            m_ms->Selectall(selected_num, start);
							VappFmgrPage *page = NULL;
			
							if (m_page != NULL)
							{
								page = (VappFmgrPage*)m_page;
								page->updatePage(this, page->getPageId(), m_cur_index, VFX_TRUE);
							}
						}
					}
				}
				break;			
			case MENU_ID_FMGR_CANCEL:
				{					
					/* Set list menu style as normal list */
					closeMarkSeveral();
				}
				break;
			case MENU_ID_FMGR_OPTION_UNSELECT_ALL:
				if (m_ms != NULL)
				{
					m_ms->remove_all(this);
					VappFmgrPage *page = NULL;
	
					if (m_page != NULL)
					{
						page = (VappFmgrPage*)m_page;
						page->updatePage(this, page->getPageId(), m_cur_index, VFX_TRUE);
					}
				}
				break;
			case MENU_ID_FMGR_OPTION_DELETE:	
				{
					if (m_ms != NULL)
					{
						VfxS32 fs_ret = 0;
						
						VFX_ALLOC_MEM(marked_file_name, VENUS_FMGR_FILENAME_BUF_LEN, this);
                        memset(marked_file_name, 0, VENUS_FMGR_FILENAME_BUF_LEN);
						if ((fs_ret = m_ms->top(this, marked_file_name, VENUS_FMGR_FILENAME_BUF_LEN_RESERVED)) == VappFmgrMultiSelect::VAPP_FMGR_MSA_ERROR_NONE)
						{
							action_file_path = this->m_file_path;
							if (composeFilePath(action_file_path, marked_file_name, VFX_FALSE) < 0)
							{
								VFX_FREE_MEM(marked_file_name);
								marked_file_name = NULL;

                                closeMarkSeveral();

                                showPopup(srv_fmgr_fs_error_get_string(FS_PATH_OVER_LEN_ERROR), VCP_POPUP_TYPE_FAILURE);

								return;
							}
							
							VFX_FREE_MEM(marked_file_name);
							marked_file_name = NULL;
							
							VFX_OBJ_CREATE(m_action, VappFmgrGeneralOperation, this);
							m_action->setCallerGroupId(m_gid);
							m_action->setAction(VAPP_FMGR_ACTION_MARK_DELETE);				
							m_action->m_signalActionRsp.connect(this, &VappFmgrMain::onActionRsp);						
							m_action->setSrcPath(action_file_path);
							m_action->setSelectedPath((VfxS8*)this->m_file_path.getBuf());
							m_action->setMaxCount(m_ms->getCount());
                            m_action->setCanCancel((m_ms->getCount() > 1)? VFX_TRUE:VFX_FALSE);
							m_action->run();
						}
						else
						{
							/* show error popup */
							showPopup(srv_fmgr_fs_error_get_string(fs_ret), VCP_POPUP_TYPE_FAILURE);
						}

						if (marked_file_name != NULL)
						{
							VFX_FREE_MEM(marked_file_name);
						}
					}
				}
				break;
			case MENU_ID_FMGR_OPTION_COPY:
			case MENU_ID_FMGR_OPTION_MOVE:
				m_fs_id = vcui_folder_selector_create(m_gid, (const WCHAR*)L"root", VCUI_FOLDER_SELECTOR_STYLE_WRITE, VCUI_FOLDER_SELECTOR_OPT_FIXED_PATH_ON);
				if (m_fs_id != GRP_ID_INVALID)
				{
					if (button_id == MENU_ID_FMGR_OPTION_COPY)
					{
						m_file_action = VAPP_FMGR_ACTION_MARK_COPY;
					}
					else
					{
						m_file_action = VAPP_FMGR_ACTION_MARK_MOVE;
					}
					vcui_folder_selector_run(m_fs_id);
				}
				/*
				FMGR_FILTER temp_filter;
				FMGR_FILTER_INIT(&temp_filter);
				srv_fmgr_types_filter_set_group(&temp_filter, FMGR_GROUP_IMAGE);
				vcui_folder_browser_launch(m_gid, (const WCHAR*)L"D:\\Images\\", &temp_filter);
				*/
                /*
				FMGR_FILTER temp_filter;
				FMGR_FILTER_INIT(&temp_filter);
				srv_fmgr_types_filter_set_group(&temp_filter, FMGR_GROUP_AUDIO);
				FMGR_FILTER_SET(&temp_filter, FMGR_TYPE_FOLDER);
				cui_id = vcui_file_selector_create(m_gid, (const WCHAR*)L"root", &temp_filter, VCUI_FILE_SELECTOR_STYLE_FILE_ONLY, VCUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_ALL|VCUI_FILE_SELECTOR_OPT_AUDIO_PREVIEW_ON);
				if (cui_id != GRP_ID_INVALID)
				{
					m_file_action = VAPP_FMGR_ACTION_MARK_COPY;
					vcui_file_selector_run(cui_id);
				}
				*/
				break;
            case MENU_ID_FMGR_OPTION_SHARE:
            #ifdef __MMI_OPP_SUPPORT__                
                if (m_ms != NULL)
				{
				    if (m_ms->getCount() > VAPP_FMGRI_BT_MAX_NUM)
                    {            
			    	    showPopup(STR_ID_VAPP_FMGR_MORE_THAN_BT_LIMIT_CONTINUE, VCP_POPUP_TYPE_WARNING, VCP_CONFIRM_BUTTON_SET_USER_DEFINE, STR_GLOBAL_SHARE, STR_GLOBAL_CANCEL);
                    }
                    else
                    {
                        multiShareAsBT();
                    }
				}
            #endif
                break;
			default:
				break;
		};
	}
}

#ifdef __MMI_OPP_SUPPORT__
void VappFmgrMain::multiShareAsBT()
{
        VfxS8   *marked_file_name = NULL;
        VfxS8 *pArray = NULL;
        VFX_ALLOC_MEM(pArray, VAPP_FMGRI_BT_MAX_NUM*VAPP_FMGR_FILE_PATH_LEN, this);
        memset(pArray, 0, VAPP_FMGRI_BT_MAX_NUM*VAPP_FMGR_FILE_PATH_LEN);
        
        VfxS8* wArray[VAPP_FMGRI_BT_MAX_NUM];
        VfxU32 i = 0;
        for (i = 0; i < VAPP_FMGRI_BT_MAX_NUM; i++)
        {
            wArray[i] = pArray + VAPP_FMGR_FILE_PATH_LEN*i;
        }

        /* copy path */
        VfxU32 base_count = m_ms->getCount();
        if (base_count > VAPP_FMGRI_BT_MAX_NUM)
        {
            base_count = VAPP_FMGRI_BT_MAX_NUM;
        }
        i = 0;
        
  		VFX_ALLOC_MEM(marked_file_name, VENUS_FMGR_FILENAME_BUF_LEN, this);
        
		while (m_ms->top(this, marked_file_name, VENUS_FMGR_FILENAME_BUF_LEN_RESERVED) == VappFmgrMultiSelect::VAPP_FMGR_MSA_ERROR_NONE 
               && i < VAPP_FMGRI_BT_MAX_NUM)
		{
			if (composeFilePath(wArray[i], VAPP_FMGR_FILE_PATH_LEN, m_file_path, marked_file_name, VFX_FALSE) < 0)
			{
			    memset(wArray[i], 0, VAPP_FMGR_FILE_PATH_LEN);
                m_ms->pop(this);
				continue;
			}
			
			/* Check DRM permission */
        #ifdef __DRM_SUPPORT__            			
			VfxS32 fs_ret = mmi_rmgr_check_forward((WCHAR*)wArray[i]);
            
			if (fs_ret >= 0 && (!(fs_ret & MMI_RMGR_USAGE_SEND)))
          	{
          	    memset(wArray[i], 0, VAPP_FMGR_FILE_PATH_LEN);
                m_ms->pop(this);
              	continue;
          	}
        #endif                        

            m_ms->pop(this);
            
            i++;
		}

        if (base_count != i)
        {
            /* Show error balloon */
        showPopup(STR_ID_VAPP_FMGR_DRM_AND_PATH_OVER_LEN_FAIL, VCP_POPUP_TYPE_INFO);
        }
        
        if (i > 0)
        {
            vapp_bt_send_app_info app_info;
            memset(&app_info, 0, sizeof(vapp_bt_send_app_info));
            app_info.group_id = m_gid;
            
            vapp_bt_send_obj(&app_info, VAPP_BT_SEND_NONE, i, (WCHAR**)wArray);
            
        }

        VFX_FREE_MEM(pArray);
        
		if (marked_file_name != NULL)
		{
			VFX_FREE_MEM(marked_file_name);
		}

        closeMarkSeveral();
}
#endif

void VappFmgrMain::onClickConfirmButton(VfxObject* obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
#ifdef __MMI_OPP_SUPPORT__    
        multiShareAsBT();
#endif        
    }
    else if (id == VCP_CONFIRM_POPUP_BUTTON_USER_2)
    {
        // User wouldn't like to do BT send so close multi option
        closeMarkSeveral();
    }
}

VfxS32 VappFmgrMain::selectFolderDone(VfxWChar* path)
{
	VfxS32 fs_ret = 0;
	
	if (m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE)
	{
		fs_ret = selectMarkSeveralFolderDone(path);

		if (fs_ret < 0)
		{
			closeMarkSeveral();

            if (fs_ret == VAPP_FMGRI_ERROR_FILE_LIST_IS_DIRTY)
            {
                showPopup(STR_ID_VAPP_FMGR_FILE_LIST_IS_DIRTY, VCP_POPUP_TYPE_WARNING);
            }
            else
            {
			    showPopup(srv_fmgr_fs_error_get_string(fs_ret), VCP_POPUP_TYPE_FAILURE);
            }
		}
	}
	else
	{
	    VfxBool isFolder = VFX_FALSE;
		VfxS8 *buffer = NULL;
		VfxS32 index = -1;
		VfxWString action_file_path;
		VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;
			
		if (path != NULL)
		{				
			switch (m_file_action)
			{
				case VAPP_FMGR_ACTION_COPY:
				case VAPP_FMGR_ACTION_MOVE:					
					/* Get file info */
					do {
						if (m_selected_pos.group == 0)
						{
							/* System folder should not do any file operation from file manager */						
							break;
						}
						else if (m_selected_pos.group == 1)
						{
							index = m_selected_pos.pos;
						}
						else
						{
							index = m_selected_index;
						}

						if (index < 0)
						{
							fs_ret = VAPP_FMGRI_ERROR_PARAM_ERROR;
							break;
						}

						/* Get file info */
						VappFmgrFSData *fsdata = getFSDataObj();
						if (fsdata != NULL)
						{
							VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
							fs_ret = fsdata->getFileInfo(this, index, file_info);
							if (fs_ret < 0)
							{
								break;
							}
						}


						if (file_info != NULL)
						{
							VFX_ALLOC_MEM(buffer, VAPP_FMGR_FILE_PATH_LEN, this);							
							fs_ret = composeFilePath(buffer, VAPP_FMGR_FILE_PATH_LEN, m_file_path, file_info->file_name, VFX_FALSE);
							if (fs_ret < 0)
							{
								break;
							}

							/* Check if selected folder and src folder is the same or not */
							VfxS32 len = app_ucs2_strlen((const kal_int8*)path);
							if (path[len-1] == '\\')
							{
								len--;
							}
							if (len <= SRV_FMGR_PATH_MAX_LEN&&
								(app_ucs2_strncmp((const kal_int8*)buffer, (const kal_int8*)path, len) == 0) &&
								buffer[len*ENCODING_LENGTH] == 0 &&
								buffer[len*ENCODING_LENGTH+1] == 0)
							{
								fs_ret = FS_ACCESS_DENIED;
								break;
							}
							
							if (file_info->attribute & FS_ATTR_DIR)
							{
								/* cate complete dst path */
								VfxWString dst_path(path);
								fs_ret = composeFilePath((VfxS8*)path, VAPP_FMGR_FILE_PATH_LEN, dst_path, file_info->file_name, VFX_FALSE);
								if (fs_ret < 0)
								{
									break;
								}

                                if (app_ucs2_strcmp((const kal_int8*)buffer, (const kal_int8*)path) == 0)
                                {
                                    fs_ret = FS_FILE_EXISTS;
                                    break;
                                }

                                isFolder = VFX_TRUE;
							}
							
							VFX_OBJ_CREATE(m_action, VappFmgrGeneralOperation, this);
							m_action->setCallerGroupId(m_gid);
							m_action->setAction(m_file_action);
                            if (isFolder)
                            {
                                srv_fmgr_fileinfo_struct srv_info;
                                srv_info.attribute = file_info->attribute;
                                srv_info.size = 0;
                                m_action->setSrcFileInfo(&srv_info);
                            }
							m_action->setSrcPath(buffer);
							m_action->setDstPath((VfxS8*)path);
							m_action->m_signalActionRsp.connect(this, &VappFmgrMain::onActionRsp);
							m_action->setCanCancel(isFolder? VFX_TRUE : VFX_FALSE);
							m_action->run();
						}
					} while(0);

					if (buffer != NULL)
					{
						VFX_FREE_MEM(buffer);
					}
					
					if (file_info != NULL)
					{
						VFX_FREE_MEM(file_info);
					}

					if (fs_ret < 0)
					{
						showPopup(srv_fmgr_fs_error_get_string(fs_ret), VCP_POPUP_TYPE_FAILURE);
					}
					break;
			}
		}
		else
		{
			fs_ret = FS_PATH_NOT_FOUND;
		}	
	}

	return fs_ret;
}

VfxBool VappFmgrMain::hideSelectAll(void)
{
    if (m_ms != NULL && m_ms->getCount() > 0 &&
        m_ms->getCount() == m_ms->getAllowToMarkCount())
    {
        return VFX_TRUE;
    }

	return VFX_FALSE;
}

VfxS32 VappFmgrMain::selectMarkSeveralFolderDone(VfxWChar* path)
{
	VfxS32 ret = 0;
	VfxS8 *marked_file_name = NULL;
	VfxWString action_file_path;

	do {
		if (path != NULL)
		{
			/* Check if file list handle is ok or not */
			SRV_FMGR_FILELIST_HANDLE hdle = getFileListHdle();
			if (srv_fmgr_filelist_is_dirty(hdle))
			{
				ret = VAPP_FMGRI_ERROR_FILE_LIST_IS_DIRTY;
                break;
			}
			
			if (srv_fmgr_filelist_is_dirty(hdle) == MMI_TRUE ||
		        srv_fmgr_filelist_get_state(hdle) != SRV_FMGR_FILELIST_STATE_READY)
			{
			    VAPP_FMGR_TRACE0(TRC_VAPP_FMGR_FILELISTDIRTY, "[VAPPFMGR]After select folder complete, file list is dirty");
				ret = FS_PARAM_ERROR;
				break;
			}
			
			switch (m_file_action)
			{
				case VAPP_FMGR_ACTION_MARK_COPY:
				case VAPP_FMGR_ACTION_MARK_MOVE:
					if (m_ms != NULL)
					{
						VfxS8 flag = 0;
                        VfxS8 *buffer = NULL;
						VfxBool isfolder = VFX_FALSE;
						
						VFX_ALLOC_MEM(marked_file_name, VENUS_FMGR_FILENAME_BUF_LEN, this);
						if (m_ms->top(this, marked_file_name, VENUS_FMGR_FILENAME_BUF_LEN_RESERVED, &flag, &isfolder) == VappFmgrMultiSelect::VAPP_FMGR_MSA_ERROR_NONE)
						{
						    VFX_ALLOC_MEM(buffer, VAPP_FMGR_FILE_PATH_LEN, this);
                            memset(buffer, 0, VAPP_FMGR_FILE_PATH_LEN);
                            
							ret = composeFilePath(buffer, VAPP_FMGR_FILE_PATH_LEN, m_file_path, marked_file_name, VFX_FALSE);
							if (ret < 0)
							{
								VFX_FREE_MEM(marked_file_name);
                                VFX_FREE_MEM(buffer);
								marked_file_name = NULL;								
								return FS_PATH_OVER_LEN_ERROR;
							}							
							
							VfxWString dst_path(path);
							if (isfolder)
							{
								/* cate complete dst path */								
								ret = composeFilePath((VfxS8*)path, VAPP_FMGR_FILE_PATH_LEN, dst_path, marked_file_name, VFX_FALSE);
								if (ret < 0)
								{
									VFX_FREE_MEM(marked_file_name);
                                    VFX_FREE_MEM(buffer);
									marked_file_name = NULL;
									return ret;
								}

                                if (app_ucs2_strcmp((const kal_int8*)buffer, (const kal_int8*)path) == 0)
                                {
                                    VFX_FREE_MEM(marked_file_name);
                                    VFX_FREE_MEM(buffer);
									marked_file_name = NULL;
                                    return FS_FILE_EXISTS;
                                }
							}
                            else
                            {
                                /* File case. Check if src and dst are the same */
                                VfxS32 len = app_ucs2_strlen((const kal_int8*)path);
                                if (path[len-1] == '\\')
                                {
                                    len--;
                                }
                                VfxS32 src_path_len = m_file_path.getLength();
                                src_path_len--;
                                
                                if ((src_path_len == len) && app_ucs2_strcmp((const kal_int8*)m_file_path.getBuf(), (const kal_int8*)path) == 0)
                                {
                                    VFX_FREE_MEM(marked_file_name);
                                    VFX_FREE_MEM(buffer);
									marked_file_name = NULL;
                                    return FS_FILE_EXISTS;
                                }
                            }
							
							VFX_FREE_MEM(marked_file_name);
							marked_file_name = NULL;							
							
							VFX_OBJ_CREATE(m_action, VappFmgrGeneralOperation, this);
							m_action->setCallerGroupId(m_gid);
							if (m_file_action == VAPP_FMGR_ACTION_MARK_COPY)
							{
								m_action->setAction(VAPP_FMGR_ACTION_MARK_COPY);
							}
							else
							{
								m_action->setAction(VAPP_FMGR_ACTION_MARK_MOVE);
							}
							m_action->m_signalActionRsp.connect(this, &VappFmgrMain::onActionRsp);
                            if (isfolder)
                            {
                                srv_fmgr_fileinfo_struct srv_info;
                                srv_info.attribute = FS_ATTR_DIR;
                                srv_info.size = 0;
                                m_action->setSrcFileInfo(&srv_info);
                            }
							m_action->setSrcPath(buffer);
							m_action->setSelectedPath((VfxS8*)dst_path.getBuf());
							m_action->setDstPath((VfxS8*)path);
							m_action->setCanCancel(VFX_TRUE);
							m_action->setMaxCount(m_ms->getCount());
							m_action->run();
						}

						if (marked_file_name != NULL)
						{
							VFX_FREE_MEM(marked_file_name);
						}					

                        if (buffer != NULL)
                        {
                            VFX_FREE_MEM(buffer);
                        }
					}
					break;
			}
		}
		else
		{
			ret = FS_PATH_NOT_FOUND;
		}
	} while(0);

	return ret;
}

#if !defined(__COSMOS_SLIM_FMGR_MT6260__)
VfxU32 VappFmgrMain::closeFileDetailPage(void)
{
	VfxU32 pre_page_id = 0;
	
	VappFmgrFileDetail *page = (VappFmgrFileDetail*)m_page;
	if (page != NULL &&
		page->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrFileDetail)) &&
		page->getPageId() == VappFmgrPage::VAPP_FMGR_DRAW_FILE_DETAIL_PAGE)
	{	
		pre_page_id = page->getFolderViewerPageId();
		m_page = NULL;
	}

	VfxMainScr *scr = VfxMainScr::findMainScr((VfxFrame*)this);

    VAPP_FMGR_TRACE2(TRC_VAPP_FMGR_CLOSE_PAGE, "[VAPPFMGR]close page, m_id %d, line %d", (VappFmgrPage::VAPP_FMGR_DRAW_FILE_DETAIL_PAGE+1), __LINE__);
	scr->closePage(VappFmgrPage::VAPP_FMGR_DRAW_FILE_DETAIL_PAGE+1);

	return pre_page_id;
}
#endif
void VappFmgrMain::closeStorageReport(void)
{
	VappFmgrPage *page = (VappFmgrPage*)m_page;
	if (page != NULL &&
		page->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrPage)) &&
		(page->getPageId() == VappFmgrPage::VAPP_FMGR_DRAW_STORAGE_DETAIL_PHONE_PAGE ||
		 page->getPageId() == VappFmgrPage::VAPP_FMGR_DRAW_STORAGE_DETAIL_MEM_PAGE))
	{				
		m_page = NULL;
	}

	VfxMainScr *scr = VfxMainScr::findMainScr((VfxFrame*)this);

    VAPP_FMGR_TRACE2(TRC_VAPP_FMGR_CLOSE_PAGE, "[VAPPFMGR]close page, m_id %d, line %d", (VappFmgrPage::VAPP_FMGR_DRAW_STORAGE_REPORT+1), __LINE__);
#ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
	scr->closePage(VappFmgrPage::VAPP_FMGR_DRAW_STORAGE_REPORT+1);
#else
    scr->closePage(VappFmgrPage::VAPP_FMGR_DRAW_STORAGE_DETAIL_MEM_PAGE+1);
#endif
}

void VappFmgrMain::closeMarkSeveral(void)
{
	/* Close Mark Several Page */
	m_display_style = VappFmgrPage::VAPP_FMGR_DRAW_NORMAL_LIST_PAGE;
	
	if (m_listmenu != NULL)
	{		
		m_listmenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
		m_listmenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON);
		/* Update title and option menu */
		VappFmgrPage* page = (VappFmgrPage*)m_page;
		if (page != NULL && page->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrPage)))
		{
			page->updatePageTitle(this, m_display_style);
			VfxU16 removed_opt_menu = MENU_ID_FMGR_OPTION_MULTI_SELECT;
			page->removeAllButtonsFromToolbar(removed_opt_menu);
			page->updatePageOptionMenu(this, m_display_style);
        }

        #ifdef __VAPP_FMGR_DIR_CTRL__
        /* Unlock dir cache slot */
        FS_HANDLE fh;
        fh = FS_Open((WCHAR*)m_file_path.getBuf(), FS_READ_ONLY | FS_OPEN_SHARED | FS_OPEN_DIR);
        if(fh >= 0)
        {
            FS_DirCtrl(fh, FS_DIRCTRL_DATA_UNLOCK, NULL);
            FS_Close(fh);
        }
        #endif
	}

		VFX_OBJ_CLOSE(m_ms);
}

void VappFmgrMain::closeMarkSeveralEx(void)
{
	closeMarkSeveral();
}

void VappFmgrMain::setMenu(VcpListMenu *listmenu)
{
	m_listmenu = listmenu;
	m_listmenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT);
	if (m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE)
	{
		m_listmenu->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_TRUE);
	}
	else
	{		
    #if !defined (__COSMOS_SLIM_FMGR_MT6260__)
		m_listmenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_FALSE);
        m_listmenu->m_signalCmdButtonClicked.connect(this, &VappFmgrMain::onClickCmdButton);
    #else
        m_listmenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL, VFX_FALSE);
    #endif // #if !defined (__COSMOS_SLIM_FMGR_MT6260__)
	}
	m_listmenu->m_signalItemTapped.connect(this, &VappFmgrMain::onTapListMenuItem);
	//m_listmenu->m_signalCmdButtonClicked.connect(this, &VappFmgrMain::onClickCmdButton);
	m_listmenu->m_signalItemLongTapped.connect(this, &VappFmgrMain::onLongTapListMenuItem);

	/* Connect signal of view start and end */
	VappFmgrInstance::setMenu(listmenu);
}

void VappFmgrMain::setMenu(VcpGroupListMenu *listmenu)
{
	m_glist = listmenu;
	m_glist->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT);
#if !defined (__COSMOS_SLIM_FMGR_MT6260__)
	m_glist->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_FALSE);
    m_glist->m_signalCmdButtonClicked.connect(this, &VappFmgrMain::onClickGroupCmdButton);
#else
    m_glist->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL, VFX_FALSE);
#endif
	m_glist->m_signalItemTapped.connect(this, &VappFmgrMain::onTapGroupListMenuItem);
	//m_glist->m_signalCmdButtonClicked.connect(this, &VappFmgrMain::onClickGroupCmdButton);
	m_glist->m_signalItemLongTapped.connect(this, &VappFmgrMain::onLongTapGroupListMenuItem);

	/* Connect signal of view start and end */
	VappFmgrInstance::setMenu(listmenu);
}

VfxBool VappFmgrMain::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString & text, VcpListMenuTextColorEnum & color)
{
    return VappFmgrInstance::getItemText(index, fieldType, text, color);
}

VfxBool VappFmgrMain::getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc & image)
{	
    return VappFmgrInstance::getItemImage(index, fieldType, image);
}

void VappFmgrMain::closeItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc Image)
{
	VappFmgrInstance::closeItemImage(index, fieldType, Image);
}

VfxU32 VappFmgrMain::getCount() const
{	
    return VappFmgrInstance::getCount();
}

VcpListMenuItemStateEnum VappFmgrMain::getItemState(VfxU32 index) const
{
    VcpListMenuItemStateEnum ret = VCP_LIST_MENU_ITEM_STATE_UNSELECTED;

    if (m_context == NULL)
        return ret;

    if (m_ms != NULL &&
        m_ms->isMarked(m_context, index) >= VappFmgrMultiSelect::VAPP_FMGR_MSA_ERROR_NONE)
    {
        ret = VCP_LIST_MENU_ITEM_STATE_SELECTED;

        // Folder item can not be shared.
        if (m_ms_title_id == GetStringIdOfItem(MENU_ID_FMGR_OPTION_SHARE)
            && m_context->isDisabled(VAPP_FMGRI_CHECK_IS_FOLDER, index))
        {
            ret = VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }
    }

    return ret;
}

VfxBool VappFmgrMain::getItemIsDisabled(
        VfxU32 index       // [IN] the index of item
        ) const
{
    if (m_display_style != VappFmgrPage::VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE)
        return VFX_FALSE;

    VfxU32 flag = 0;
    if (m_ms_title_id == GetStringIdOfItem(MENU_ID_FMGR_OPTION_SHARE))
    {
        flag = VAPP_FMGRI_CHECK_IS_FOLDER;
    }

    return m_context->isDisabled(flag, index);
}

void VappFmgrMain::getOptionItem(VfxU32 page_id, VfxU16 &opt_menu_id, VfxU16 &opt_menu_num)
{	
	if (m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE)
	{
		getMarkSeveralOptionItem(page_id, opt_menu_id, opt_menu_num);
	}
	else
	{
		VfxU16 opt_menu = 0;
			
		if (page_id == VappFmgrPage::VAPP_FMGR_DRAW_DRV_PHONE_PAGE ||
			page_id == VappFmgrPage::VAPP_FMGR_DRAW_DRV_MEM_PAGE)
		{
			/* Drv tab page */
			opt_menu = MENU_ID_FMGR_OPTION_DRV;
			resetOptMenu(opt_menu);

            //mmi_frm_hide_menu_item(MENU_ID_FMGR_PORTABLE_DISK);
		}
		else if (page_id >= VappFmgrPage::VAPP_FMGR_DRAW_NORMAL_LIST_PAGE &&
			     page_id <= VappFmgrPage::VAPP_FMGR_DRAW_NORMAL_LIST_LAST_PAGE)
		{
			/* General option case */		
			opt_menu = MENU_ID_FMGR_GEN_OPTIONS;
			resetOptMenu(opt_menu);			
		}
    #if !defined(__COSMOS_SLIM_FMGR_MT6260__)
		else if (page_id == VappFmgrPage::VAPP_FMGR_DRAW_FILE_DETAIL_PAGE)
		{
			opt_menu = MENU_ID_FMGR_SINGLE_GEN_OPTIONS;
			resetOptMenu(opt_menu);

            if (m_selected_pos.group == 0)
            {
                VfxU16 opt_num = GetNumOfChild(opt_menu);

                for (VfxS32 i = 1;i < opt_num; i++)
                {
                    /* Default folder only support menu item "Open" */
                    VfxU16 child_id = GetSeqItemId(opt_menu, i);
                    if (child_id != MENU_ID_FMGR_OPTION_OPEN)
                    {
                        mmi_frm_hide_menu_item(child_id);
                    }
                }
            }
            
            VfxS32 index = -1;
            if (m_selected_index != -1)
            {
                index = m_selected_index;
            }
            else if (m_selected_pos.group == 1 && m_selected_pos.pos != -1)
            {
                index = m_selected_pos.pos;
            }

            if (index >= 0)
            {
                VappFmgrFSData* fsdata = getFSDataObj();
                if (fsdata != NULL)
                {
                    VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;
                    VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
                    memset(file_info, 0, sizeof(VAPP_FMGR_FILE_INFO_STRUCT));
                    fsdata->getFileInfo(this, index, file_info);
                    if (file_info->attribute & FS_ATTR_DIR)
                    {
                        mmi_frm_hide_menu_item(MENU_ID_FMGR_OPTION_SHARE_SINGLE);
                    }
                    VFX_FREE_MEM(file_info);
                }
            }
            
		}
    #endif // #if !defined(__COSMOS_SLIM_FMGR_MT6260__)
		else if (page_id == VappFmgrPage::VAPP_FMGR_DRAW_STORAGE_DETAIL_PHONE_PAGE ||
			     page_id == VappFmgrPage::VAPP_FMGR_DRAW_STORAGE_DETAIL_MEM_PAGE)
		{
			opt_menu = MENU_ID_FMGR_OPTION_STORAGE_REPORT;
			resetOptMenu(opt_menu);

			if (page_id == VappFmgrPage::VAPP_FMGR_DRAW_STORAGE_DETAIL_PHONE_PAGE)
			{
				mmi_frm_hide_menu_item(MENU_ID_FMGR_OPTION_RENAME_DRIVE);
				mmi_frm_hide_menu_item(MENU_ID_FMGR_OPTION_FORMAT_CARD);
			}
			else
            {
            #ifdef __MMI_SLIM_FILE_MANAGER__
                mmi_frm_hide_menu_item(MENU_ID_FMGR_OPTION_RENAME_DRIVE);
            #endif
                mmi_frm_hide_menu_item(MENU_ID_FMGR_OPTION_FORMAT_PHONE);
            }
		}

		opt_menu_id = opt_menu;

		opt_menu_num = GetNumOfChild_Ext(opt_menu_id);
	}
}

VfxBool VappFmgrMain::isMenuItemDisable(VfxU32 page_id, VfxU16 &opt_menu_id)
{
    if (m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE)
    {
        return isMarkSeveralMenuItemDisable(page_id, opt_menu_id);
    }

    VfxBool result = VappFmgrInstance::isMenuItemDisable(page_id, opt_menu_id);
    if (result == VFX_FALSE)
    {
        VappFmgrFSData *fsdata = getFSDataObj();
        if (fsdata != NULL)
        {
            if (fsdata->getCount() <= 0 && opt_menu_id != MENU_ID_FMGR_OPTION_NEW_FOLDER)
            {
                return VFX_TRUE;
            }

            /* If file counts > FS_MAX_SORT_ENTRY, disable multi files operation */
            if (fsdata->getCount() > (FS_SORT_MAX_ENTRY) &&
                (opt_menu_id == MENU_ID_FMGR_OPTION_SHARE
                || opt_menu_id == MENU_ID_FMGR_OPTION_DELETE
                || opt_menu_id == MENU_ID_FMGR_OPTION_COPY
                || opt_menu_id == MENU_ID_FMGR_OPTION_MOVE
            #if defined( __FS_SORT_SUPPORT__) && !defined(__COSMOS_SLIM_FMGR_MT6260__)
                || opt_menu_id == MENU_ID_FMGR_OPTION_SORT
            #endif // #if defined( __FS_SORT_SUPPORT__) && !defined(__COSMOS_SLIM_FMGR_MT6260__)
            ))
            {
                return VFX_TRUE;
            }
        }

        // Disable "Share" if BT send is not supported
        if (opt_menu_id == MENU_ID_FMGR_OPTION_SHARE)
        {
        #ifndef __MMI_OPP_SUPPORT__
            return VFX_TRUE;
        #endif
        }
        
    #if !defined(__COSMOS_SLIM_FMGR_MT6260__)
        // File detail
        if (page_id == VappFmgrPage::VAPP_FMGR_DRAW_FILE_DETAIL_PAGE)
        {
            // If file path is more than 259, disable all menu item in detail information page
            VfxS32 fs_ret = 0;
            VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;

            if (fsdata != NULL &&  m_selected_index >= 0 
                || (m_selected_pos.group == 1 && m_selected_pos.pos >= 0))
            {
                VfxS32 index = -1;
                if (m_selected_index >= 0)
                {
                    index = m_selected_index;
                }
                else if (m_selected_pos.group == 1 && m_selected_pos.pos >= 0)
                {
                    index = m_selected_pos.pos;
                }

                if (index >= 0)
                {
                    VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
                    memset(file_info, 0, sizeof(VAPP_FMGR_FILE_INFO_STRUCT));
                    fs_ret = fsdata->getFileInfo(this, index, file_info);
                }
            }

            if (fs_ret == FS_NO_ERROR && file_info != NULL)
            {
                filetypes_file_type_enum file_type = srv_fmgr_types_find_type_by_filename_str((const WCHAR*)file_info->file_name);

                if (!(file_info->attribute & FS_ATTR_DIR) && file_type == FMGR_TYPE_UNKNOWN && opt_menu_id == MENU_ID_FMGR_OPTION_OPEN)
                {
                    VFX_FREE_MEM(file_info);
                    return VFX_TRUE;
                }

                if (isComposeFilePathOverLen(m_file_path, (VfxS8*) file_info->file_name, VFX_FALSE))
                {            
                    VFX_FREE_MEM(file_info);
                    return VFX_TRUE;
                }
            }
        #ifndef __MMI_SLIM_FILE_MANAGER__
            VappFmgrFolderDetail* page = (VappFmgrFolderDetail*)m_page;
            if (page != NULL && page->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrFolderDetail)) && page->getWorkStatus()
                && (opt_menu_id == MENU_ID_FMGR_OPTION_DELETE_SINGLE || opt_menu_id == MENU_ID_FMGR_OPTION_COPY_TO || opt_menu_id == MENU_ID_FMGR_OPTION_MOVE_TO))
            {
                VFX_FREE_MEM(file_info);
                return VFX_TRUE;
            }
        #endif
            if (file_info != NULL)
            {
                VFX_FREE_MEM(file_info);
            }
        }
        // Phone Driver storage report
        else if (page_id == VappFmgrPage::VAPP_FMGR_DRAW_STORAGE_DETAIL_PHONE_PAGE)
        {
            // Disable option before to query categories information complete
            VappFmgrStorageDetail* page = (VappFmgrStorageDetail*)m_page;
            if (page != NULL && page->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrStorageDetail)) && !page->getDone())
            {
                return VFX_TRUE;
            }
        }
        // Memory storage report
        else if (page_id == VappFmgrPage::VAPP_FMGR_DRAW_STORAGE_DETAIL_MEM_PAGE)
        {
            VfxS32 fs_ret = 0;
            VappFmgrStorageDetail* page = (VappFmgrStorageDetail*)m_page;
            if (page != NULL && page->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrStorageDetail)))
            {
                fs_ret = page->getErrorCode();
            }

            if (fs_ret < 0)
            {
                return VFX_TRUE;
            }
            VfxU8 drv_letter = srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE);

            if (FS_GetDevStatus(drv_letter, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
            {
                // drive is not prepared
                return VFX_TRUE;
            }

            // Disable option before to query categories information complete
            if (!page->getDone())
            {
                return VFX_TRUE;
            }
        }
    #endif // !defined(__COSMOS_SLIM_FMGR_MT6260__)
        return VFX_FALSE;
    }

    return result;
}

void VappFmgrMain::getMarkSeveralOptionItem(VfxU32 page_id, VfxU16 &opt_menu_id, VfxU16 &opt_menu_num)
{	
    if (hideSelectAll())
    {
        mmi_frm_unhide_menu_item(MENU_ID_FMGR_OPTION_UNSELECT_ALL);
        mmi_frm_hide_menu_item(MENU_ID_FMGR_OPTION_SELECT_ALL);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_FMGR_OPTION_SELECT_ALL);
        mmi_frm_hide_menu_item(MENU_ID_FMGR_OPTION_UNSELECT_ALL);
    }

    // For media picker
    mmi_frm_hide_menu_item(MENU_ID_FMGR_OPTION_ADD);
    opt_menu_id = m_opt_menu_id;
    opt_menu_num = GetNumOfChild_Ext(m_opt_menu_id);
}

VfxBool VappFmgrMain::isMarkSeveralMenuItemDisable(VfxU32 page_id, VfxU16 &opt_menu_id)
{
    VfxBool result = VappFmgrInstance::isMenuItemDisable(page_id, opt_menu_id);

    if (result == VFX_FALSE)
    {
        /* Disable action menu item if there is no marked item */
        if (opt_menu_id != MENU_ID_FMGR_OPTION_SELECT_ALL &&
            opt_menu_id != MENU_ID_FMGR_OPTION_UNSELECT_ALL &&
            opt_menu_id != MENU_ID_FMGR_CANCEL &&
            (m_ms == NULL || (m_ms != NULL && m_ms->getCount() == 0)))
        {
            return VFX_TRUE;
        }

        /* Check all folders case for "Share" */
        if (m_ms_title_id == GetStringIdOfItem(MENU_ID_FMGR_OPTION_SHARE) && opt_menu_id == MENU_ID_FMGR_OPTION_SELECT_ALL)
        {
            VappFmgrFSData *fsdata = getFSDataObj();
            if (fsdata != NULL && (fsdata->getCount() == fsdata->getFolderCount()))
            {
                return VFX_TRUE;
            }
        }
    }

    return result;
}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if !defined (__COSMOS_SLIM_FMGR_MT6260__)
VfxS32 VappFmgrMain::handleClickCmdButton(VfxS32 index, VfxS32 group)
{
	VfxS32 fs_ret = 0;
	VappFmgrFSData *fsdata = getFSDataObj();
	VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;

	m_selected_index = -1;
	m_selected_pos.group = -1;
	m_selected_pos.pos = -1;
	
	if (fsdata != NULL)
	{
		do {
			VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
			fs_ret = fsdata->getFileInfo(this, index, file_info);

			if (fs_ret < 0)
			{
				break;
			}

			if (m_page == NULL)
			{
				fs_ret = FS_PARAM_ERROR;
				break;
			}

            if (group == -1)
            {
			m_selected_index = index;
            }
            else
            {
                m_selected_pos.group = group;
			    m_selected_pos.pos = index;
            }
			
			VfxMainScr *scr = VfxMainScr::findMainScr((VfxFrame*)m_page);
			if (scr != NULL)
			{
				/* Close previous detail information screen first */
                VAPP_FMGR_TRACE2(TRC_VAPP_FMGR_CLOSE_PAGE, "[VAPPFMGR]close page, m_id %d, line %d", (VappFmgrPage::VAPP_FMGR_DRAW_FILE_DETAIL_PAGE+1), __LINE__);
				scr->closePage((VappFmgrPage::VAPP_FMGR_DRAW_FILE_DETAIL_PAGE+1));
				
                VappFmgrPage* cur_page = (VappFmgrPage*)m_page;
				VappFmgrFileDetail *page = NULL;
            #ifndef __MMI_SLIM_FILE_MANAGER__
                if (file_info->attribute & FS_ATTR_DIR)
                {
                    VappFmgrFolderDetail *fd_page = NULL;
                    VFX_OBJ_CREATE_EX(fd_page, VappFmgrFolderDetail, scr, (VappFmgrPage::VAPP_FMGR_DRAW_FILE_DETAIL_PAGE, this, file_info));
                    page = (VappFmgrFileDetail*)fd_page;
                }
                else
            #endif
                {
					VFX_OBJ_CREATE_EX(page, VappFmgrFileDetail, scr, (VappFmgrPage::VAPP_FMGR_DRAW_FILE_DETAIL_PAGE, this, file_info));
                }
                
				fs_ret = page->setPath(m_file_path, file_info);
				if (fs_ret < 0)
				{
					VFX_OBJ_CLOSE(page);
					showPopup(srv_fmgr_fs_error_get_string(fs_ret), VCP_POPUP_TYPE_FAILURE);
					break;
				}
				page->setHideEditButton(VFX_FALSE);
				page->setFolderViewerPageId(cur_page->getPageId());
				page->m_signalGetOptMenuItem.connect(this, &VappFmgrMain::getOptionItem);
				page->updatePage(this, VappFmgrPage::VAPP_FMGR_DRAW_FILE_DETAIL_PAGE, index, VFX_TRUE);

				scr->pushPage((VappFmgrPage::VAPP_FMGR_DRAW_FILE_DETAIL_PAGE+1), (VfxPage*)page);
			}
		} while(0);
		
		VFX_FREE_MEM(file_info);
	}

    return fs_ret;
}

void VappFmgrMain::onClickCmdButton(VcpListMenu *listmenu, VfxU32 index)
{
	VfxS32 fs_ret = handleClickCmdButton(index);

		if (fs_ret < 0)
		{
			showPopup(srv_fmgr_fs_error_get_string(fs_ret), VCP_POPUP_TYPE_FAILURE);
		}
	}

void VappFmgrMain::onClickGroupCmdButton(VcpGroupListMenu *listmenu, VcpMenuPos pos)
{
	VfxS8 *buffer = NULL;
	VfxS32 fs_ret = 0, index = pos.pos;
	VappFmgrFSData *fsdata = getFSDataObj();
	VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;

	m_selected_index = -1;
	m_selected_pos.group = -1;
	m_selected_pos.pos = -1;

    VAPP_FMGR_TRACE2(TRC_VAPP_FMGR_ONCLICKGROUPCMDBUTTON, "[VAPPFMGR]onClickGroupCmdButton, group %d, pos %d", pos.group, pos.pos);
	if (pos.group == 0)
	{
		/* System folder */
		do {
			fs_ret = m_system_folder_properity[index].exist;
			if (fs_ret < 0)
			{
				/* error handling */
				showPopup(srv_fmgr_fs_error_get_string(FS_PATH_NOT_FOUND), VCP_POPUP_TYPE_FAILURE);
				break;
			}

			if (m_page == NULL)
			{
				fs_ret = FS_PARAM_ERROR;
				break;
			}

			
			VFX_ALLOC_MEM(buffer, VAPP_FMGR_FILE_PATH_LEN, this);
			fs_ret = composeFilePath(buffer, VAPP_FMGR_FILE_PATH_LEN, m_file_path, (VfxS8*)g_def_folder_table[index].path, VFX_FALSE);
			if (fs_ret < 0)
			{
				break;
			}
			
			VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);

			SRV_FMGR_FILEINFO_HANDLE fileinfo_hdl;
			srv_fmgr_fileinfo_struct srv_file_info;
			
			fs_ret = srv_fmgr_fileinfo_create((WCHAR *)buffer, &fileinfo_hdl);
		    if (fs_ret < 0)
		    {
		        break;
		    }

		    srv_fmgr_fileinfo_get_info(fileinfo_hdl, &srv_file_info);
		    srv_fmgr_fileinfo_destroy(fileinfo_hdl);

			file_info->file_type = (filetypes_file_type_enum)srv_file_info.type;
	        file_info->attribute = srv_file_info.attribute;
	        file_info->file_size = srv_file_info.size;
	        memcpy((void*)&file_info->time, (const void*)&srv_file_info.datetime, sizeof(MYTIME));
            memcpy((void*)&file_info->created_time, (const void*)&srv_file_info.created_datetime, sizeof(MYTIME)); 
	        memset(file_info->file_name, 0, VENUS_FMGR_FILENAME_BUF_LEN);
			VfxS32 len = app_ucs2_strlen((const kal_int8*)g_def_folder_table[index].path);
			memcpy(file_info->file_name, g_def_folder_table[index].path, (len-1)*ENCODING_LENGTH);
	        memcpy((void*)file_info->file_ext, (void*)srv_fmgr_types_get_extension_ucs2(srv_fmgr_types_find_type_by_filename_str((const WCHAR*)file_info->file_name)), VENUS_FMGR_FILEEXT_BUF_LEN_RESERVED);

			m_selected_pos = pos;
			m_group_pos = pos;
			
			VfxMainScr *scr = VfxMainScr::findMainScr((VfxFrame*)m_page);
			if (scr != NULL)
			{
				/* Close previous detail information screen first */
                VAPP_FMGR_TRACE2(TRC_VAPP_FMGR_CLOSE_PAGE, "[VAPPFMGR]close page, m_id %d, line %d", (VappFmgrPage::VAPP_FMGR_DRAW_FILE_DETAIL_PAGE+1), __LINE__);
				scr->closePage((VappFmgrPage::VAPP_FMGR_DRAW_FILE_DETAIL_PAGE+1));
		    #ifndef __MMI_SLIM_FILE_MANAGER__
				VappFmgrFolderDetail *page = NULL;
                VFX_OBJ_CREATE_EX(page, VappFmgrFolderDetail, scr, (VappFmgrPage::VAPP_FMGR_DRAW_FILE_DETAIL_PAGE, this, file_info));
            #else
                VappFmgrFileDetail *page = NULL;
                VFX_OBJ_CREATE_EX(page, VappFmgrFileDetail, scr, (VappFmgrPage::VAPP_FMGR_DRAW_FILE_DETAIL_PAGE, this, file_info));
            #endif
                fs_ret = page->setPath(m_file_path, file_info);
				if (fs_ret < 0)
				{
					VFX_OBJ_CLOSE(page);
					showPopup(srv_fmgr_fs_error_get_string(fs_ret), VCP_POPUP_TYPE_FAILURE);
					break;
				}
                    
				page->m_signalGetOptMenuItem.connect(this, &VappFmgrMain::getOptionItem);
				page->updatePage(this, VappFmgrPage::VAPP_FMGR_DRAW_FILE_DETAIL_PAGE, index, VFX_TRUE);

				scr->pushPage((VappFmgrPage::VAPP_FMGR_DRAW_FILE_DETAIL_PAGE+1), (VfxPage*)page);
			}
		} while(0);

		if (buffer != NULL)
		{
			VFX_FREE_MEM(buffer);
		}

        if (file_info != NULL)
        {
		    VFX_FREE_MEM(file_info);
        }
	}
	else
	{
	    fs_ret = handleClickCmdButton(index, pos.group);
	}

	if (fs_ret < 0)
	{
		showPopup(srv_fmgr_fs_error_get_string(fs_ret), VCP_POPUP_TYPE_FAILURE);
	}
}
#endif // #if !defined(__COSMOS_SLIM_FMGR_MT6260__)
VFX_IMPLEMENT_CLASS("VappFmgrMainScr", VappFmgrMainScr, VfxMainScr);
void VappFmgrMainScr::onInit()
{
	VfxMainScr::onInit();

	m_instance = NULL;
#ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
	m_tabctrlpage = NULL;
#endif
	m_popup = NULL;
}

void VappFmgrMainScr::onAfterInit()
{
	VfxMainScr::onAfterInit();
}

void VappFmgrMainScr::onObjectNotify(VfxId id, void* userData)
{
    switch(id)
    {
        case VFX_OBJECT_NOTIFY_ID_AFTER_INIT:
            onAfterInit();
            return;
        default:
            VfxMainScr::onObjectNotify(id, userData);
    }
}

void VappFmgrMainScr::onDeinit()
{
    VfxId i = getBottomPageId();
    VfxPage *page_obj = NULL;
    VappFmgrPage *page = NULL;
#ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
    VappFmgrDrvTabPage *drv_page = NULL;
#endif
    
    while (i != VFX_ID_NULL)
    {        
        page_obj = getPage(i);
        if (page_obj != NULL)            
        {
            if (page_obj->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrPage)))
            {
                page = (VappFmgrPage*)page_obj;
                page->setInstance(NULL);
            }
        #ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
            else if (page_obj->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrDrvTabPage)))
            {
                drv_page = (VappFmgrDrvTabPage*)page_obj;
                drv_page->setInstance(NULL);
                drv_page->closeChildPage();
            }
        #endif
        }

        i = getNextPageId(i);
    }
    
	if (m_instance != NULL)
	{
	    m_instance->setPageObj(NULL);
		VFX_OBJ_CLOSE(m_instance);
		m_instance = NULL;
	}
#ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
	if (m_tabctrlpage != NULL)
	{
		VFX_OBJ_CLOSE(m_tabctrlpage);
		m_tabctrlpage = NULL;
	}
#endif
	VfxMainScr::onDeinit();
}

void VappFmgrMainScr::showPopup(mmi_id parent_id, VfxU16 str_id, VcpPopupTypeEnum popup_type)
{
	if (m_popup == NULL)
	{
		VFX_OBJ_CREATE(m_popup, VcpConfirmPopup, this);	
		m_popup->setInfoType(popup_type);
		m_popup->setAutoDestory(VFX_TRUE);
		m_popup->setText(str_id);
		m_popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
		m_popup->m_signalPopupState.connect(this, &VappFmgrMainScr::onPopupStateChange);
		m_popup->show(VFX_TRUE);

		m_groupid = parent_id;
	}
}

void VappFmgrMainScr::onPopupStateChange(VfxBasePopup* obj,  VfxBasePopupStateEnum state)
{
	if (m_popup == obj)
	{
		switch (state)
		{
			case VFX_BASE_POPUP_AFTER_END_ANIMATION:
				/* Close app */
				VfxApp *app = VfxApp::getObject(m_groupid);
				if (app != NULL)
				{
					app->exit();
				}
				break;
		}
	}
}

void VappFmgrMainScr::setCallerInstance(VappFmgrInstance * instance)
{
    m_instance = instance;
}

VappFmgrInstance* VappFmgrMainScr::getCallerInstance(void)
{
    return m_instance;
}

#ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
VappFmgrDrvTabPage *VappFmgrMainScr::getTabCtrlPageObj(void)
{
	return m_tabctrlpage;
}
#endif

#if !defined(__COSMOS_SLIM_FMGR_MT6260__)
class VappFmgrAsyncPhotoBorder : public VcpPhotoBorderFrame
{
    VFX_DECLARE_CLASS(VappFmgrAsyncPhotoBorder);
public:
    VappFmgrAsyncPhotoBorder();
    VappFmgrAsyncPhotoBorder(const VfxWChar* filename, VfxS32 previewImageId, VfxSize size);
    VcpAsyncImageFrame* getAsyncImage();
    
protected:    
    virtual void onInit();
    
private:
    VfxS32 m_previewImageId;
    VfxSize m_size;
    VfxWString m_filename;
    VcpAsyncImageFrame *m_asyncImage;
};

VFX_IMPLEMENT_CLASS("VappFmgrAsyncPhotoBorder", VappFmgrAsyncPhotoBorder, VcpPhotoBorderFrame);

VappFmgrAsyncPhotoBorder::VappFmgrAsyncPhotoBorder() :
m_previewImageId(0), m_size(VfxSize(0, 0))
{
}

VappFmgrAsyncPhotoBorder::VappFmgrAsyncPhotoBorder(const VfxWChar* filename, VfxS32 previewImageId, VfxSize size) :
m_previewImageId(previewImageId), m_size(size), m_filename(filename)
{
}

void VappFmgrAsyncPhotoBorder::onInit()
{
    VcpPhotoBorderFrame::onInit();

    VFX_OBJ_CREATE_EX(m_asyncImage, VcpAsyncImageFrame, this, (m_filename, m_previewImageId, m_size));
    setImageFrame(m_asyncImage);
}

VcpAsyncImageFrame* VappFmgrAsyncPhotoBorder::getAsyncImage()
{
    return m_asyncImage;
}

class VappFmgrDetailCell : public VcpFormItemBase
{
    VFX_DECLARE_CLASS(VappFmgrDetailCell);
#if !defined(__COSMOS_SLIM_FMGR_MT6260__)
    friend class VappFmgrFileDetail;
#endif // #if !defined(__COSMOS_SLIM_FMGR_MT6260__)
#ifndef __MMI_SLIM_FILE_MANAGER__
    friend class VappFmgrFolderDetail;
#endif
    
public:
    VappFmgrDetailCell();
    VappFmgrDetailCell(VfxBool firstCell);
        
    void setMainText(const VfxWString &textStr) {m_txt->setString(textStr);}
    void setMainText(const VfxWChar* text)  {m_txt->setString(text);}
    void setMainText(const VfxResId textId){m_txt->setString(textId);}

    void setSubText(const VfxWString &text);
    void setSubUrlText(const VfxWString &text, VfxS8 *path);
    void setThumb(VfxS8* path);
    void hideEditButton(VfxBool hidden);
    VcpImageButton *getEditorButton();
// Override
protected:
    virtual void onInit();
    virtual void onUpdate();

    void onHandleGdiResult(GDI_RESULT result);
    void onClickHyperLink(VcpTextView *view, VfxWString url);
// Implementation
private:
    enum
    {
    #ifdef __MMI_MAINLCD_480X800__
        ITEM_WIDTH  = 480,
        ITEM_HEIGHT = 63,
        GAP         = 14,
        CELL_GAP    = 18,
        EDITOR_GAP  = 14,
        EDITOR_SIZE = 59,
        TXT_Y       = 18,
        TXT_Y_GAP   = 0,

		TEXT_WIDTH = 200,
		TEXT_HEIGHT = 15,

        THUMB_Y_GAP = 18,
        THUMB_WIDTH = 350,
        THUMB_HEIGHT = 226,

        MAIN_FONT_SIZE = 30,
        SUB_FONT_SIZE = 26,
    #elif __MMI_MAINLCD_320X480__
        ITEM_WIDTH  = 320,
        ITEM_HEIGHT = 63,
        GAP         = 8,
        CELL_GAP    = 10,
        EDITOR_GAP  = 10,
        EDITOR_SIZE = 36,
        TXT_Y       = 18,
        TXT_Y_GAP   = 0,

		TEXT_WIDTH = 200,
		TEXT_HEIGHT = 15,

        THUMB_Y_GAP = 8,
        THUMB_WIDTH = 207,
        THUMB_HEIGHT = 155,

        MAIN_FONT_SIZE = 20,
        SUB_FONT_SIZE = 16,
    #else
        ITEM_WIDTH  = 240,
        ITEM_HEIGHT = 63,
        GAP         = 5,
        CELL_GAP    = 6,
        EDITOR_GAP  = 5,
        EDITOR_SIZE = 30,
        TXT_Y       = 3,
        TXT_Y_GAP   = 0,

		TEXT_WIDTH = 200,
		TEXT_HEIGHT = 15,

        THUMB_Y_GAP = 6,
        THUMB_WIDTH = 176,
        THUMB_HEIGHT = 132,

        MAIN_FONT_SIZE = 16,
        SUB_FONT_SIZE = 14,
    #endif
        MAIN_TEXT_HEIGHT = MAIN_FONT_SIZE+2,
        SUB_TEXT_HEIGHT = SUB_FONT_SIZE+2
    };

    #define MAIN_TEXT_COLOR VfxColor(255, 21, 21, 21)
    #define SUB_TEXT_COLOR VfxColor(255, 80, 80, 80)

    VfxBool m_firstCell;
	VfxTextFrame *m_txt;
	VfxTextFrame *m_txt_sub;
    VcpTextView  *m_url_txt;
    VappFmgrAsyncPhotoBorder *m_photo;
	VcpImageButton *m_btn;
};


VFX_IMPLEMENT_CLASS("VappFmgrDetailCell", VappFmgrDetailCell, VcpFormItemBase);

VappFmgrDetailCell::VappFmgrDetailCell() :
m_firstCell(VFX_FALSE)
{
}

VappFmgrDetailCell::VappFmgrDetailCell(VfxBool firstCell) :
m_firstCell(firstCell)
{
}

void VappFmgrDetailCell::onInit()
{
    VcpFormItemBase::onInit();

	m_txt = NULL;
	m_txt_sub = NULL;
	m_btn = NULL;
	m_photo = NULL;       

	/* set background color */
	setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
	
    VfxS32 x = GAP;
    VfxS32 y = CELL_GAP;
    const VfxS32 cellWidth = getSize().width;
    if (m_firstCell)
    {
        y = (GAP - VCPFRM_ITEM_HORZ_GAP_1);
    }

    // create main text
    VFX_OBJ_CREATE(m_txt, VfxTextFrame, this);
    m_txt->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
	m_txt->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(MAIN_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
    m_txt->setPos(x, y);
	m_txt->setSize(cellWidth-(EDITOR_SIZE+2*GAP+EDITOR_GAP), MAIN_TEXT_HEIGHT);
    m_txt->setAutoResized(VFX_FALSE);
	m_txt->forceUpdate();	    

    // create edit button, default is hidden.    
    VFX_OBJ_CREATE(m_btn, VcpImageButton, this);
    VcpStateImage     imgList;
    imgList.setImage(
        VfxImageSrc(IMG_ID_VAPP_FMGR_RENAME_ICON_N),
        VfxImageSrc(IMG_ID_VAPP_FMGR_RENAME_ICON_P),
        VfxImageSrc(0),
        VfxImageSrc(0));
    m_btn->setImage(imgList);    
    m_btn->setAnchor(1.0, 0);
    
    x = cellWidth - GAP;
    m_btn->setPos(x, y);
    m_btn->setSize(EDITOR_SIZE, EDITOR_SIZE);
	m_btn->setHidden(VFX_TRUE);
	m_btn->setId(MENU_ID_FMGR_OPTION_RENAME);    

    VfxS32 height = GAP + m_btn->getSize().height + SUB_TEXT_HEIGHT;
    setSize(cellWidth, GAP + m_btn->getSize().height + SUB_TEXT_HEIGHT);
    setHeight(height);
}

void VappFmgrDetailCell::onUpdate()
{
    if (m_btn && !m_btn->getHidden())
    {
        VfxS32 x = getSize().width - GAP;
        VfxS32 y = m_btn->getPos().y;
        
        m_btn->setPos(x, y);
    }
    if (m_txt_sub)
    {
        m_txt_sub->setSize((getSize().width-(m_btn->getSize().width+2*GAP+EDITOR_GAP)), SUB_TEXT_HEIGHT);
        m_txt_sub->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
    }
    VcpFormItemBase::onUpdate();    
}

void VappFmgrDetailCell::onHandleGdiResult(GDI_RESULT result)
{
    if (result != GDI_SUCCEED && m_photo != NULL)
    {
        /* Set unknown file */
        m_photo->getAsyncImage()->setImgContent(VfxImageSrc(IMG_ID_VAPP_GALLERY_SHT_UNKNOWN_FORMAT_ICON));
    }
    m_photo->checkUpdate();
    m_photo->forceUpdate();
}

void VappFmgrDetailCell::onClickHyperLink(VcpTextView *view, VfxWString url)
{
    if (view != NULL && view == m_url_txt)
    {
        /* Get right object */
#ifdef __DRM_SUPPORT__
        mmi_rmgr_status_enum rmgr_ret = (mmi_rmgr_status_enum)mmi_rmgr_check_rights_by_path(
                                                (U16*)url.getBuf(), 
                                                DRM_PERMISSION_ALL, 
                                                IMG_ID_VAPP_FMGR_MAINMENU_ICN, 
                                                NULL);

        if (rmgr_ret == MMI_RMGR_STATUS_REQUEST_RIGHTS)
        {
            mmi_rmgr_request_rights_confirm();
        }
#endif
    }
}

void VappFmgrDetailCell::setSubText(const VfxWString &text)
{
	// create sub text
    VfxS32 t_dis = m_firstCell? (GAP - VCPFRM_ITEM_HORZ_GAP_1) : CELL_GAP;

	if (m_txt_sub == NULL)
	{
		VfxS32 x = GAP, y = t_dis + m_txt->getSize().height + TXT_Y_GAP;
	    VFX_OBJ_CREATE(m_txt_sub, VfxTextFrame, this);
	    m_txt_sub->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB));

	    m_txt_sub->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(SUB_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
	    m_txt_sub->setPos(x, y);
		m_txt_sub->setLineMode(VfxTextFrame::LINE_MODE_MULTI);        
		m_txt_sub->setSize((getSize().width-(m_btn->getSize().width+2*GAP+EDITOR_GAP)), SUB_TEXT_HEIGHT);
	}
	m_txt_sub->setString(text);
	m_txt_sub->forceUpdate();
    
    VfxS32 tmp = t_dis + m_txt_sub->getSize().height + m_txt->getSize().height + TXT_Y_GAP;
    VfxS32 height = 0;
    if (!m_btn->getHidden())
    {
        height = (t_dis + m_btn->getSize().height);
        if (height < tmp)
        {
            height = tmp;
        }
    }
    else
    {
        height = tmp;
    }

    setHeight(height);
}

void VappFmgrDetailCell::setSubUrlText(const VfxWString &text, VfxS8 *path)
{
	// create sub text
	VfxFontDesc textFont = VFX_FONT_RES(VCP_FNT_TEXT_VIEW_TXT);
    textFont.attr |= VFX_FONT_DESC_ATTR_UNDERLINE;
    textFont.size = VFX_FONT_DESC_VF_SIZE(SUB_FONT_SIZE);
    
	if (m_txt_sub == NULL)
	{
		VfxS32 x = GAP, y = GAP + m_txt->getSize().height + TXT_Y_GAP;
	    VFX_OBJ_CREATE(m_url_txt, VcpTextView, this);
	    
	    m_url_txt->setPos(x, y);
        m_url_txt->setSize((ITEM_WIDTH-(m_btn->getSize().width+2*GAP+EDITOR_GAP)), (SUB_FONT_SIZE+4));
	}
	m_url_txt->setText(text);
    if (path != NULL)
    {
        m_url_txt->setHyperLink(0, text.getLength(), VFX_WSTR_MEM((VfxWChar*)path), &textFont);
        m_url_txt->m_signalHyperLinkClicked.connect(this, &VappFmgrDetailCell::onClickHyperLink);
    }
	m_url_txt->forceUpdate();
    
    
    VfxS32 height = (m_url_txt->getSize().height+ GAP + m_txt->getSize().height + TXT_Y_GAP);
    
	setSize(ITEM_WIDTH, height);
    setHeight(height);
}

void VappFmgrDetailCell::setThumb(VfxS8* path)
{
	if (path != NULL)
	{
        VfxS32 t_dis = m_firstCell? (GAP - VCPFRM_ITEM_HORZ_GAP_1) : CELL_GAP;
		if (m_photo == NULL)
		{
			VfxS32 x = ITEM_WIDTH/2, y = t_dis + THUMB_Y_GAP + m_txt->getSize().height;
            VfxSize size(THUMB_WIDTH, THUMB_HEIGHT);
            
		    VFX_OBJ_CREATE_EX(m_photo, VappFmgrAsyncPhotoBorder, this, ((VfxWChar*)path, IMG_ID_VAPP_GALLERY_SHT_LOADING_ICON, size));
		    m_photo->setAnchor(0.5, 0);
		    m_photo->setPos(x, y);
            m_photo->setMaxSize(size);
			m_photo->setPlacement(VCP_PHOTO_BORDER_FRAME_PLACEMENT_FIT_MAX_SIZE);
            m_photo->getAsyncImage()->m_gdiResultCallback.connect(this, &VappFmgrDetailCell::onHandleGdiResult);            
		}

        VfxS32 height = (t_dis + THUMB_Y_GAP + m_txt->getSize().height + TXT_Y_GAP + THUMB_HEIGHT);
    
    	setSize(ITEM_WIDTH, height);
        setHeight(height);
	}
}

void VappFmgrDetailCell::hideEditButton(VfxBool hidden)
{
	m_btn->setHidden(hidden);
}

VcpImageButton *VappFmgrDetailCell::getEditorButton()
{
	return m_btn;
}

VFX_IMPLEMENT_CLASS("VappFmgrFileDetail", VappFmgrFileDetail, VappFmgrPage);

void VappFmgrFileDetail::onInit()
{
    VappFmgrPage::onInit(); // call base class

	m_create_img_frame = VFX_FALSE;
	m_hide_editbutton = VFX_TRUE;
	m_error_code = 0;
	m_folder_viewer_pageid = 0;
	m_path = NULL;
}

void VappFmgrFileDetail::onDeinit()
{
	if (m_path != NULL)
	{
		VFX_FREE_MEM(m_path);		
	}

    if (m_file_info != NULL)
    {
        VFX_FREE_MEM(m_file_info);
    }
    
	VappFmgrPage::onDeinit();
}

void VappFmgrFileDetail::onEntered()
{
	VappFmgrPage::onEntered();
	
#if !defined(__MMI_SLIM_FILE_MANAGER__)	
	if (m_create_img_frame)
	{
		drawImgDetail();
		m_create_img_frame = VFX_FALSE;
	}
#endif // #if !defined(__MMI_SLIM_FILE_MANAGER__)
}

void VappFmgrFileDetail::setHideEditButton(VfxBool hide_editbutton)
{
	m_hide_editbutton = hide_editbutton;
}

void VappFmgrFileDetail::unhideFileNameEditBtn(void)
{
    if (m_form != NULL)
    {
        VappFmgrDetailCell *cell = (VappFmgrDetailCell*)m_form->getItem(ITEM_GEN_NAME);
        if (cell != NULL && m_instance != NULL)
        {
            m_hide_editbutton = VFX_FALSE;
            cell->m_btn->setHidden(m_hide_editbutton);
            cell->m_btn->m_signalClicked.connect(m_instance, &VappFmgrMain::onClickToolBarButton);

            VfxS32 t_dis = cell->m_firstCell? (VappFmgrDetailCell::GAP - VCPFRM_ITEM_HORZ_GAP_1) : VappFmgrDetailCell::CELL_GAP;
            VfxS32 tmp = t_dis + cell->m_txt_sub->getSize().height + cell->m_txt->getSize().height + VappFmgrDetailCell::TXT_Y_GAP;
            VfxS32 height = 0;
            
            height = (t_dis + cell->m_btn->getSize().height);
            if (height < tmp)
            {
                height = tmp;
            }
            
        	cell->setSize(VappFmgrDetailCell::ITEM_WIDTH, height);
            cell->setHeight(height);
        }
    }
}

VAPP_FMGR_FILE_INFO_STRUCT* VappFmgrFileDetail::getFileInfo(void)
{
	return m_file_info;
}

void VappFmgrFileDetail::setFileInfo(VAPP_FMGR_FILE_INFO_STRUCT* file_info)
{
    VFX_ALLOC_MEM(m_file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
    memset(m_file_info, 0, sizeof(VAPP_FMGR_FILE_INFO_STRUCT));
    memcpy(m_file_info, file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT));
}

VfxS32 VappFmgrFileDetail::setPath(VfxWString &path, VAPP_FMGR_FILE_INFO_STRUCT* file_info)
{
	if (path.isNull() || path.isEmpty() || file_info == NULL)
	{
		m_error_code = FS_PARAM_ERROR;
		return FS_PARAM_ERROR;
	}

	if (path.getLength()+app_ucs2_strlen((const kal_int8*)file_info->file_name) <= SRV_FMGR_PATH_MAX_LEN)
	{
		VFX_ALLOC_MEM(m_path, VAPP_FMGR_FILE_PATH_LEN, this);
		memset(m_path, 0, VAPP_FMGR_FILE_PATH_LEN);

		app_ucs2_strcpy((kal_int8*)m_path, (const kal_int8*)path.getBuf());
		app_ucs2_strcat((kal_int8*)m_path, (const kal_int8*)file_info->file_name);		
	}
	else
	{
		m_error_code = FS_PATH_OVER_LEN_ERROR;
		/* Do not return the error code in order to show general information */
		//return FS_PATH_OVER_LEN_ERROR;
	}
	

	return FS_NO_ERROR;
}

VfxS8* VappFmgrFileDetail::getPath(void)
{
	return m_path;
}

void VappFmgrFileDetail::setFolderViewerPageId(VfxU32 page_id)
{
	m_folder_viewer_pageid = page_id;
}

VfxU32 VappFmgrFileDetail::getFolderViewerPageId()
{
	return m_folder_viewer_pageid;
}

#if !defined(__MMI_SLIM_FILE_MANAGER__)
void VappFmgrFileDetail::createImgDetail()
{
	if (m_path != NULL)
	{
		/* According to file type to show information */
        m_form->addCaption(STR_ID_VAPP_FMGR_DEATIL_EXTRA_INFO);

		/* Add width */
		VappFmgrDetailCell *img_cell = NULL;
		VFX_OBJ_CREATE_EX(img_cell, VappFmgrDetailCell, this, (VFX_TRUE));		
		img_cell->setMainText(STR_ID_VAPP_FMGR_DETAIL_IMG_WIDTH);
		img_cell->setSubText(VfxWString().format("%d", 0));
		m_form->addItem(img_cell, ITEM_IMG_WIDTH);

		/* Add height */
		VFX_OBJ_CREATE(img_cell, VappFmgrDetailCell, this);
		img_cell->setMainText(STR_ID_VAPP_FMGR_DETAIL_IMG_HEIGHT);
		img_cell->setSubText(VfxWString().format("%d", 0));	
		m_form->addItem(img_cell, ITEM_IMG_HEIGHT);

		m_create_img_frame = VFX_TRUE;
	}
}

void VappFmgrFileDetail::drawImgDetail()
{
	if (m_path != NULL && m_form != NULL)
	{
		VfxS32 width = 0, height = 0;
		GDI_RESULT gdi_ret = 0;
		
		gdi_ret = gdi_image_get_dimension_file((CHAR*)m_path, &width, &height);
		if (gdi_ret < 0)
		{
			width = height = 0;
		}

		/* Update width */
		VappFmgrDetailCell *img_cell = NULL;
		img_cell = (VappFmgrDetailCell*)m_form->getItem(ITEM_IMG_WIDTH);
		if (img_cell != NULL)
		{
			img_cell->setSubText(VfxWString().format("%d", width));
		}

		img_cell = (VappFmgrDetailCell*)m_form->getItem(ITEM_IMG_HEIGHT);
		if (img_cell != NULL)
		{
			img_cell->setSubText(VfxWString().format("%d", height));
		}

        if (gdi_ret == 0)
        {
    		VFX_OBJ_CREATE(img_cell, VappFmgrDetailCell, this);
    		img_cell->setMainText(STR_ID_VAPP_FMGR_DETAIL_IMG_PREVIEW);
    		img_cell->setThumb(m_path);
    		m_form->addItem(img_cell, ITEM_IMG_PREVIEW);
        }
	}
}

void VappFmgrFileDetail::drawAudDetail()
{
	if (m_path != NULL)
	{
	    /* According to file type to show information */
        m_form->addCaption(STR_ID_VAPP_FMGR_DEATIL_EXTRA_INFO);
        
		VfxU16 cur = 0;
		VfxU32 time = 0;
		mdi_result mdi_ret = 0;
		VfxU16 units[3];
		VfxWString time_str;
				
		mdi_ret = mdi_audio_get_duration((void*)m_path, &time);
		if (mdi_ret != 0)
		{
			time = 0;
			time_str = VfxWString().format("%d", 0);
		}
		else
		{
			cur = time/1000;
			units[0] = cur/3600; /* hr */
			if (units[0] > 0)
			{
				time_str = VfxWString().format("%d:", units[0]);
			}
			cur = cur%3600;
			units[1] = cur/60;
			if (time_str.getLength() > 0)
			{
			    if (units[1] < 10)
                    time_str += VfxWString().format("0%d:", units[1]);
                else
				    time_str += VfxWString().format("%d:", units[1]);
			}
			else
			{
				time_str = VfxWString().format("%d:", units[1]);
			}
			units[2] = cur%60;
			if (time_str.getLength() > 0)
			{
			    if (units[2] < 10)
                    time_str += VfxWString().format("0%d", units[2]);
                else
				    time_str += VfxWString().format("%d", units[2]);
			}
			else
			{
				time_str = VfxWString().format("%d", units[2]);
			}
		}
		/* Show detail */
		VappFmgrDetailCell *aud_cell = NULL;
		VFX_OBJ_CREATE_EX(aud_cell, VappFmgrDetailCell, this, (VFX_TRUE));		
		aud_cell->setMainText(STR_ID_VAPP_FMGR_DETAIL_AUD_DURATION);
		aud_cell->setSubText(time_str);
		m_form->addItem(aud_cell, ITEM_AUD_DURATION);
		
		audInfoStruct audio_info;

		mdi_ret = mdi_audio_mma_get_audio_info(m_instance->getGroupId(), (kal_wchar*)m_path, MMA_TYPE_UNKNOWN, NULL, 0, &audio_info);
        VAPP_FMGR_TRACE1(TRC_VAPP_FMGR_AUDIO_DETAIL, "[VAPPFMGR]Audio detail, mdi_result %d", mdi_ret);
		if (mdi_ret == 0)
		{
			VfxU32 bitrate = audio_info.bitRate;
			VfxU32 samplerate = audio_info.sampleRate;
			
			bitrate = bitrate/1000;
			samplerate = samplerate/1000;

            VappFmgrDetailCell *aud_cell_br = NULL;
    		VappFmgrDetailCell *aud_cell_sr = NULL;
    		
    		VFX_OBJ_CREATE(aud_cell_br, VappFmgrDetailCell, this);		
    		aud_cell_br->setMainText(STR_ID_VAPP_FMGR_DETAIL_AUD_BITRATE);
            aud_cell_br->setSubText(VfxWString().format("%d kbps", bitrate));
    		m_form->addItem(aud_cell_br, ITEM_AUD_BITRATE);

    		VFX_OBJ_CREATE(aud_cell_sr, VappFmgrDetailCell, this);		
    		aud_cell_sr->setMainText(STR_ID_VAPP_FMGR_DETAIL_AUD_SAMPLE_RATE);
			aud_cell_sr->setSubText(VfxWString().format("%d kHz", samplerate));
    		m_form->addItem(aud_cell_sr, ITEM_AUD_SAMPLE_RATE);
		}
	}
}

void VappFmgrFileDetail::drawVdoDetail(void)
{
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
	if (m_path != NULL)
	{
	    /* According to file type to show information */
        m_form->addCaption(STR_ID_VAPP_FMGR_DEATIL_EXTRA_INFO);
        
		VfxU16 cur = 0, width = 0, height = 0;
		VfxU32 time = 0;
		MDI_RESULT mdi_ret = 0;
		VfxU16 units[3];
		VfxWString time_str;
		mdi_video_info_struct *info = NULL;

		VFX_ALLOC_MEM(info, sizeof(mdi_video_info_struct), this);
		memset(info, 0, sizeof(mdi_video_info_struct));
		mmi_id appId = getApp()->getGroupId();
		mdi_ret = mdi_video_ply_open_clip_file((const U16)appId, (const CHAR*)m_path, info);
		if (mdi_ret < 0)
		{
			time_str = VfxWString().format("%d", 0);
		}
		else
		{
			width = info->width;
			height = info->height;
			time = info->total_time_duration;
			cur = time/1000;
			units[0] = cur/3600; /* hr */
			if (units[0] > 0)
			{
				time_str = VfxWString().format("%d:", units[0]);
			}
			cur = cur%3600;
			units[1] = cur/60;
			if (time_str.getLength() > 0)
			{
				time_str += VfxWString().format("%d:", units[1]);
			}
			else
			{
				time_str = VfxWString().format("%d:", units[1]);
			}
			units[2] = cur%60;
			if (time_str.getLength() > 0)
			{
				time_str += VfxWString().format("%d", units[2]);
			}
			else
			{
				time_str = VfxWString().format("%d", units[2]);
			}
		}
		/* Show detail */
		VappFmgrDetailCell *vdo_cell = NULL;
		
		VFX_OBJ_CREATE_EX(vdo_cell, VappFmgrDetailCell, this, (VFX_TRUE));		
		vdo_cell->setMainText(STR_ID_VAPP_FMGR_DETAIL_VDO_WIDTH);
		vdo_cell->setSubText(VfxWString().format("%d px", width));
		m_form->addItem(vdo_cell, ITEM_VDO_WIDTH);

		VFX_OBJ_CREATE(vdo_cell, VappFmgrDetailCell, this);		
		vdo_cell->setMainText(STR_ID_VAPP_FMGR_DETAIL_VDO_HEIGHT);
		vdo_cell->setSubText(VfxWString().format("%d px", height));
		m_form->addItem(vdo_cell, ITEM_VDO_WIDTH);
		
		VFX_OBJ_CREATE(vdo_cell, VappFmgrDetailCell, this);		
		vdo_cell->setMainText(STR_ID_VAPP_FMGR_DETAIL_VDO_DURATION);
		vdo_cell->setSubText(time_str);
		m_form->addItem(vdo_cell, ITEM_VDO_DURATION);			
	}
#endif	
}

void VappFmgrFileDetail::drawBookmarkDetail()
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif // #if !defined(__MMI_SLIM_FILE_MANAGER__)

void VappFmgrFileDetail::drawFileDetail()
{
	if (m_form == NULL && m_file_info != NULL)
	{
		VFX_OBJ_CREATE(m_form, VcpForm, this);
        m_form->setContentTopGap(VCPFRM_ITEM_HORZ_GAP_1);
	    m_form->setSize(getParentControl()->getSize().width, getParentControl()->getSize().height);
        
		m_form->setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));		

		VappFmgrDetailCell *cell;
		VFX_OBJ_CREATE_EX(cell, VappFmgrDetailCell, m_form, (VFX_TRUE));
        cell->hideEditButton(m_hide_editbutton);
		cell->setMainText(STR_ID_VAPP_FMGR_DETAIL_NAME);
		if (m_file_info != NULL)
		{
		    if (!(m_file_info->attribute & FS_ATTR_DIR))
            {      
    		    VfxS8 *buffer = NULL;
                VFX_ALLOC_MEM(buffer, VAPP_FMGR_FILE_PATH_LEN, this);
                memset(buffer, 0, VAPP_FMGR_FILE_PATH_LEN);
                app_ucs2_strncpy((kal_int8*)buffer, (const kal_int8*)m_file_info->file_name, SRV_FMGR_PATH_MAX_LEN);

                VfxS32 pos = srv_fmgr_path_get_extension_pos((const WCHAR*)buffer);

                if (pos > 0)
                {
                    buffer[(pos-1)*ENCODING_LENGTH] = 0;
                }

                cell->setSubText(VFX_WSTR_MEM((VfxWChar*)buffer));

                VFX_FREE_MEM(buffer);
            }
            else
            {
                VfxWString folder_name;
                if (m_instance != NULL && m_instance->getFilePath().getLength() == 3)
                {
            folder_name.loadFromMem((const VfxWChar*)m_file_info->file_name);
                    folder_name += VFX_WSTR("\\");
                    VfxU16 str_id = m_instance->isSystemFolder((VfxS8*)folder_name.getBuf(), VFX_TRUE);
                    if (str_id > 0)
                    {
                folder_name.loadFromRes(str_id);
                    }
                    else
                    {
                folder_name.loadFromMem((VfxWChar*)m_file_info->file_name);
                    }
                }
                else
                {
            folder_name.loadFromMem((VfxWChar*)m_file_info->file_name);
                }
			    cell->setSubText(folder_name);
            }
		}
		if (m_hide_editbutton == VFX_FALSE)
		{
			/* Connect signal click */
			if (m_error_code < 0)
			{
				cell->getEditorButton()->setIsDisabled(VFX_TRUE);
			}
			else
			{
				cell->getEditorButton()->m_signalClicked.connect(m_instance, &VappFmgrMain::onClickToolBarButton);
			}
		}
		m_form->addItem(cell, ITEM_GEN_NAME);

		VFX_OBJ_CREATE(cell, VappFmgrDetailCell, m_form);
		cell->setMainText(STR_ID_VAPP_FMGR_DETAIL_TYPE);
		filetypes_file_type_enum file_type = FMGR_TYPE_UNKNOWN;
		if (m_file_info != NULL)
		{
			file_type = m_file_info->file_type;
			if (file_type == FMGR_TYPE_FOLDER)
			{
				cell->setSubText(VFX_WSTR_RES(STR_ID_VAPP_FMGR_FOLDER));
			}
            else if (file_type == FMGR_TYPE_UNKNOWN)
            {
                cell->setSubText(VFX_WSTR_RES(STR_GLOBAL_UNSUPPORTED_FORMAT));
            }
#if !defined(__MMI_SHOW_DAF_FILE_EXT__)            
            else if (file_type == FMGR_TYPE_DAF ||
                     file_type == FMGR_TYPE_MP2)
            {
                cell->setSubText(VFX_WSTR_RES(STR_ID_VAPP_FMGR_DAF));
            }
#endif            
			else
			{
				VfxWChar * ext = (VfxWChar*)srv_fmgr_types_get_extension_ucs2(file_type);
				cell->setSubText(VFX_WSTR_MEM(ext));
			}
		}
		m_form->addItem(cell, ITEM_GEN_TYPE);

        VfxWString text;
#ifndef __MMI_SLIM_FILE_MANAGER__
		VFX_OBJ_CREATE(cell, VappFmgrDetailCell, m_form);
		cell->setMainText(STR_ID_VAPP_FMGR_DETAIL_SIZE);
		if (m_file_info != NULL)
		{			
			m_instance->getSizeString(text, m_file_info->file_size);
			cell->setSubText(text);

            if (m_file_info->attribute & FS_ATTR_DIR)
            {
                VappFmgrFolderDetail *fd = (VappFmgrFolderDetail*)this;
                if (fd->queryFirst() > 0)
                {
                    VappFmgrDetailCell *tmp_cell = (VappFmgrDetailCell*)m_form->getItem(ITEM_GEN_NAME);
                    tmp_cell->m_btn->setIsDisabled(VFX_TRUE);
                }
            }
		}
		m_form->addItem(cell, ITEM_GEN_SIZE);
#else
        if (m_file_info != NULL && !(m_file_info->attribute & FS_ATTR_DIR))
		{
		    VFX_OBJ_CREATE(cell, VappFmgrDetailCell, m_form);
		    cell->setMainText(STR_ID_VAPP_FMGR_DETAIL_SIZE);

            m_instance->getSizeString(text, m_file_info->file_size);
			cell->setSubText(text);

            m_form->addItem(cell, ITEM_GEN_SIZE);
        }
#endif
		if (m_file_info != NULL)
		{
			VFX_OBJ_CREATE(cell, VappFmgrDetailCell, m_form);
			cell->setMainText(STR_ID_VAPP_FMGR_DETAIL_CREATED_TIME);

			m_instance->getDateTimeString(text, &m_file_info->created_time);
			cell->setSubText(text);
			
		    m_form->addItem(cell, ITEM_GEN_CREATE_TIME);
		}

        if (m_file_info != NULL && !(m_file_info->attribute & FS_ATTR_DIR))
		{
    		VFX_OBJ_CREATE(cell, VappFmgrDetailCell, m_form);
    		cell->setMainText(STR_ID_VAPP_FMGR_DETAIL_MODIFIED_TIME);
		
            m_instance->getDateTimeString(text, &m_file_info->time);
			cell->setSubText(text);
    		m_form->addItem(cell, ITEM_GEN_MODIFIED_TIME);
        }
        /* Copy right */
#ifdef __DRM_SUPPORT__
        if (m_error_code == 0 && m_file_info != NULL && (!(m_file_info->attribute & FS_ATTR_DIR)))
        {
            VFX_OBJ_CREATE(cell, VappFmgrDetailCell, m_form);
    		cell->setMainText(STR_ID_VAPP_FMGR_DETAIL_COPYRIGHT);

            if (DRM_is_drm_file(NULL, (kal_wchar*)m_path) == KAL_TRUE)
            {
                FS_HANDLE handle;
                mmi_rmgr_status_enum rmgr_ret = MMI_RMGR_STATUS_OK;
                
                handle = DRM_open_file((kal_wchar*)m_path, FS_READ_ONLY, DRM_PERMISSION_ALL);
                if (handle >= DRM_RESULT_OK)
                {
                    rmgr_ret = (mmi_rmgr_status_enum)mmi_rmgr_extend_rights_internal_mod(
                                                                    handle, 
                                                                    DRM_PERMISSION_ALL, 
                                                                    IMG_ID_VAPP_FMGR_MAINMENU_ICN);

                    DRM_close_file(handle);

                }
                
                if (rmgr_ret == MMI_RMGR_STATUS_REQUEST_RIGHTS)
                {
                    cell->setSubUrlText(VFX_WSTR_RES(STR_ID_VAPP_FMGR_DETAIL_DOWNLOAD_LICENSE), m_path);
                }
                else
                {
                    cell->setSubText(VFX_WSTR_RES(STR_ID_VAPP_FMGR_DETAIL_PROTECTED));
                }
                m_form->addItem(cell, ITEM_GEN_COPY_RIGHT);
                return;
            }
            else
            {
                cell->setSubText(VFX_WSTR_RES(STR_ID_VAPP_FMGR_DETAIL_NOT_PROTECTED));
                m_form->addItem(cell, ITEM_GEN_COPY_RIGHT);
            }
        }
#endif
#if !defined(__MMI_SLIM_FILE_MANAGER__)
		if (m_error_code < 0)
		{
	  		/* According to file type to show information */
            cell->setHeight(cell->getSize().height+VappFmgrDetailCell::CELL_GAP);
            m_form->addCaption(STR_ID_VAPP_FMGR_DEATIL_EXTRA_INFO);
            
			VFX_OBJ_CREATE(cell, VappFmgrDetailCell, m_form);
			cell->setMainText(srv_fmgr_fs_error_get_string(m_error_code));
			m_form->addItem(cell, ITEM_EXTRA_ERROR);
		}
		else
		{
			if (file_type == FMGR_TYPE_URL)
			{
				drawBookmarkDetail();
			}
			else
			{
				filetypes_group_type_enum group_type = srv_fmgr_types_find_group_by_type(file_type);
				switch (group_type)
				{
					case FMGR_GROUP_IMAGE:
						{
                            cell->setHeight(cell->getSize().height+VappFmgrDetailCell::CELL_GAP);
							createImgDetail();
						}
						break;
					case FMGR_GROUP_AUDIO:
						{
                            cell->setHeight(cell->getSize().height+VappFmgrDetailCell::CELL_GAP);
							drawAudDetail();
						}
						break;
                    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                    #endif
					default:
						break;
				};
			}
		}
        #endif // !defined(__MMI_SLIM_FILE_MANAGER__)
		//m_form->addItem(VfxId itemId, VfxFrame * item, VcpFormItemTypeEnum itemType)
	}
}
#endif // #if !defined(__COSMOS_SLIM_FMGR_MT6260__)
#ifndef __MMI_SLIM_FILE_MANAGER__
VFX_IMPLEMENT_CLASS("VappFmgrFolderDetail", VappFmgrFolderDetail, VappFmgrFileDetail);

void VappFmgrFolderDetail::onInit()
{
    VappFmgrFileDetail::onInit(); // call base class  

    m_working = VFX_FALSE;
    m_jobid = 0;
    m_cancel = VFX_FALSE;
}

void VappFmgrFolderDetail::onDeinit()
{	
    if (!m_cancel && m_jobid > 0)
    {
        if (srv_fmgr_async_abort(m_jobid, MMI_FALSE) == MMI_TRUE)
		{
			m_cancel = VFX_TRUE;
		}
    }
    
	VappFmgrFileDetail::onDeinit();
}

VfxS32 VappFmgrFolderDetail::queryFirst()
{	
	VfxS32 fs_ret = 0;	
	
	fs_ret = srv_fmgr_fs_path_exist((const WCHAR*)m_path);
	if (fs_ret == 0)
	{
		fs_ret = srv_fmgr_async_get_folder_size((const WCHAR*)m_path, SRV_FMGR_ASYNC_FLAG_NEED_PROGRESS, vapp_fmgr_async_get_single_folder_size_result_proc, m_instance->getObjHandle());
		if (fs_ret > 0)
		{
		    m_jobid = fs_ret;
            m_working = VFX_TRUE;
		}
	}
    
	return fs_ret;
}

void VappFmgrFolderDetail::setWorkStatus(VfxBool work)
{
    m_working = work;
}

VfxBool VappFmgrFolderDetail::getWorkStatus()
{
    return m_working;
}

VfxS32 VappFmgrFolderDetail::getDisplayStyle()
{
    return DISPLAY_STYLE;
}

void VappFmgrFolderDetail::disableEdit(VfxBool disable)
{
    VappFmgrDetailCell* cell = (VappFmgrDetailCell*)m_form->getItem(VappFmgrFileDetail::ITEM_GEN_NAME);
    cell->getEditorButton()->setIsDisabled(disable);
}

VfxS32 VappFmgrFolderDetail::queryUpdate(VfxS32 job_id, VfxU64 folder_size)
{
	VfxS32 fs_ret = 0;
	
	if (job_id != m_jobid)
	{
		fs_ret = VAPP_FMGRI_ERROR_FOLDER_DETAIL_JOBID_ERROR;
		return fs_ret;	
	}
	else
	{
		if (m_form != NULL)
        {      
    		VappFmgrDetailCell* cell =  (VappFmgrDetailCell*)m_form->getItem(ITEM_GEN_SIZE);
    		if (cell != NULL)
    		{
    			VfxWString text;
    			m_instance->getSizeString(text, folder_size);
    			cell->setSubText(text);			
    		}
        }
        
		if (m_cancel)
		{
			m_cancel = VFX_FALSE;
			m_jobid = 0;
            fs_ret = FS_ABORTED_ERROR;			
			return fs_ret;
		}		
	}

	return fs_ret;
}
#endif

VFX_IMPLEMENT_CLASS("VappFmgrTitleCell", VappFmgrTitleCell, VfxControl);


void VappFmgrTitleCell::onInit()
{
    VfxControl::onInit();

    m_bg = NULL;
            
	setBounds(VfxRect(0, 0, ITEM_WIDTH, ITEM_HEIGHT));

    VFX_OBJ_CREATE(m_bg, VfxFrame, this);
    m_bg->setBounds(VfxRect(0, 0, ITEM_WIDTH, ITEM_HEIGHT));
    m_bg->setImgContent(VfxImageSrc(IMG_ID_VAPP_FMGR_PARENT_FOLDER_BG));
    m_bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	
	VfxS32 x = 0, y = 0;   
	
    /* create main text */
    VFX_OBJ_CREATE(m_txt, VfxTextFrame, m_bg);
    m_txt->setColor(VFX_COLOR_RES(CLR_ID_VAPP_FMGR_TITLE_MAIN_TXT));
	m_txt->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(MAIN_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
	m_txt->setSize(TEXT_WIDTH, MAIN_TEXT_HEIGHT);
    m_txt->setAutoResized(VFX_FALSE);
    m_txt->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
	m_txt->forceUpdate();
        
    /* create sub text */
    VFX_OBJ_CREATE(m_txt_sub, VfxTextFrame, m_bg);
    m_txt_sub->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(SUB_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));    
	m_txt_sub->setSize(TEXT_WIDTH, SUB_TEXT_HEIGHT);
    m_txt_sub->setAutoResized(VFX_FALSE);
	m_txt_sub->setString(STR_GLOBAL_LOADING);
    m_txt_sub->setColor(VFX_COLOR_RES(CLR_ID_VAPP_FMGR_TITLE_SUB_TXT));
    m_txt_sub->forceUpdate();

    x = TEXT_LSIDE_ALIGN;
    y = (ITEM_HEIGHT-(m_txt->getSize().height+m_txt_sub->getSize().height+TXT_Y_GAP))/2;

    m_txt->setPos(x, y);
    
    y += m_txt->getSize().height + TXT_Y_GAP;
    
    m_txt_sub->setPos(x, y);
    
    /* create back button */
    VFX_OBJ_CREATE(m_btn, VcpImageButton, m_bg);
    VcpStateImage     imgList;
    imgList.setImage(
        VfxImageSrc(IMG_ID_VAPP_FMGR_BACK_N),
        VfxImageSrc(IMG_ID_VAPP_FMGR_BACK_P),
        VfxImageSrc(0),
        VfxImageSrc(0));
    m_btn->setImage(imgList);
    //m_btn->setIsStretchMode(VFX_TRUE);    
    m_btn->setSize(BACK_ICON_WIDTH, BACK_ICON_HEIGHT);
    m_btn->setAnchor(1.0, 0.5);

    x = ITEM_WIDTH - ICON_RSIDE_ALIGN;
    y = ITEM_HEIGHT/2;
    m_btn->setPos(x, y);
}

void VappFmgrTitleCell::setMainText(VfxWString &text)
{
	m_txt->setString(text);
}

void VappFmgrTitleCell::setSubText(VfxWString &text)
{
	m_txt_sub->setString(text);	
}

void VappFmgrTitleCell::setImage(VfxU16 res_id)	
{
	m_img->setResId(res_id);
}

void VappFmgrTitleCell::reLayout(VfxS32 width, VfxS32 height)
{
    if (m_bg != NULL)
    {
        m_bg->setSize(width, height);
    }
    
    if (m_btn != NULL && m_btn->getHidden() == VFX_FALSE)
    {
        VfxS32 x = width - ICON_RSIDE_ALIGN;
        VfxS32 y = ITEM_HEIGHT/2;
        m_btn->setPos(x, y);
    }

    VfxS32 n_title_cell_text_width = width - 3*TEXT_LSIDE_ALIGN-BACK_ICON_WIDTH;
	
	if (m_txt != NULL)
	{
		m_txt->setSize(n_title_cell_text_width, MAIN_TEXT_HEIGHT);
	}

	if (m_txt_sub != NULL)
	{
		m_txt_sub->setSize(n_title_cell_text_width, MAIN_TEXT_HEIGHT);
	}

    setSize(width, height);
}

VcpImageButton *VappFmgrTitleCell::getUpButton()
{
	return m_btn;
}

VFX_IMPLEMENT_CLASS("VappFmgrPage", VappFmgrPage, VfxPage);

void VappFmgrPage::onInit()
{
    VfxPage::onInit(); // call base class	

	//setSize(320, 480);
	//setBounds(VfxRect(0, 0, 320, 480));

    m_exit = VFX_FALSE;
    m_restore = VFX_FALSE;
    m_pFolder = NULL;
	m_context = this;
	m_listmenu = NULL;
	m_glist = NULL;
	m_toolbar = NULL;
	m_titlebar = NULL;
	m_form = NULL;
	m_textframe = NULL;
	m_first_cell = NULL;
	m_focus_timer = NULL;
	m_menu_view_state = NULL;

    m_loading = NULL;
#ifdef __VAPP_FMGR_NO_PUBLIC_DRIVE__
    drawTitleBar(m_instance);
#endif
	if (m_toolbar == NULL)
	{
		VFX_OBJ_CREATE(m_toolbar, VcpToolBar, this);
	}	
	
	setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));	
}

void VappFmgrPage::onDeinit()
{
    closeLoadingIndicator();
    
	if (m_instance != NULL && m_instance->getPageObj() == this)
	{
		m_instance->setPageObj(NULL);
	}

	if (m_focus_timer != NULL)
	{
		m_focus_timer->stop();
		VFX_OBJ_CLOSE(m_focus_timer);
	}

	if (m_menu_view_state != NULL)
	{
		VFX_FREE_MEM(m_menu_view_state);
	}

    if (m_pFolder != NULL)
    {
        VFX_FREE_MEM(m_pFolder);
    }
    
	VfxPage::onDeinit();
}

void VappFmgrPage::onEnter(VfxBool isBackward)
{
	/* If page id is drv phone or drv mem, update file path here */
    VfxPage::onEnter(isBackward);

    VAPP_FMGR_TRACE2(TRC_VAPP_FMGR_PAGE_ONENTER, "[VAPPFMGR]page onEnter page id %d, m_instance 0x%08X", m_pageId, m_instance);
	if (m_instance != NULL)
	{		
		if (m_pageId == VAPP_FMGR_DRAW_DRV_PHONE_PAGE ||
			m_pageId == VAPP_FMGR_DRAW_DRV_MEM_PAGE)
		{
			VfxWChar *path = NULL;
			VfxWString tmp;

			if (m_pageId == VAPP_FMGR_DRAW_DRV_PHONE_PAGE)
			{
				tmp = VfxWString().format("%c", srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_PHONE_TYPE));
				m_instance->setDisplayStyle(VappFmgrPage::VAPP_FMGR_DRAW_DRV_PHONE_PAGE);
			}
			else
			{
				tmp = VfxWString().format("%c", srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE));
				m_instance->setDisplayStyle(VappFmgrPage::VAPP_FMGR_DRAW_DRV_MEM_PAGE);
			}
			tmp += VFX_WSTR(":\\");

			VFX_ALLOC_MEM(path, sizeof(VfxWChar)*5, this);
			app_ucs2_strncpy((kal_int8*)path, (const kal_int8*)tmp.getBuf(), 5);
			m_instance->setFilePath(path);
			VFX_FREE_MEM(path);

			setInstance(m_instance);
			m_instance->setPageObj(this);
		}
	}
}
	
void VappFmgrPage::onEntered()
{
    m_instance->setErrHandle(VFX_TRUE);
    VAPP_FMGR_TRACE0(TRC_VAPP_FMGR_PAGE_ONENTERED, "[VAPPFMGR]page onEntered");
	if (m_instance != NULL && m_pageId <= VAPP_FMGR_DRAW_FOLDER_BROWSER_LAUNCH_PAGE)
	{
	    m_instance->resetDisableUpdate();
        m_signalGetOptMenuItem.disconnect(m_instance, &VappFmgrInstance::getOptionItem);
		m_signalGetOptMenuItem.connect(m_instance, &VappFmgrInstance::getOptionItem);
        m_signalGetTitleStrAndIcn.disconnect(m_instance, &VappFmgrInstance::getTitleStrAndIcn);
		m_signalGetTitleStrAndIcn.connect(m_instance, &VappFmgrInstance::getTitleStrAndIcn);

		if (m_pageId == VAPP_FMGR_DRAW_DRV_PHONE_PAGE ||
			m_pageId == VAPP_FMGR_DRAW_DRV_MEM_PAGE)
		{
			if (m_instance->getCreateSystemFolderJobId() != 0)
			{
				if (srv_fmgr_async_abort(m_instance->getCreateSystemFolderJobId(), MMI_FALSE) == MMI_TRUE)
				{
					m_instance->setCreateSystemFolderJobCancel(VFX_TRUE);
					m_instance->setPrepareSystemFolderIndex(0);
				}
			}
			else
			{
				m_instance->setPrepareSystemFolderIndex(0);
				VfxS32 fs_ret = m_instance->prepareSystemFolders();

				if (fs_ret == VAPP_FMGRI_ERROR_PREPARE_SYSTEM_FOLDER_COMPLETE ||
					fs_ret == FS_MSDC_MOUNT_ERROR)
				{
					/* prepare system folder flow done. */
					m_instance->setPrepareSystemFolderIndex(0);
					if (fs_ret == VAPP_FMGRI_ERROR_PREPARE_SYSTEM_FOLDER_COMPLETE)
					{
						m_instance->refreshMenu(VENUS_FMGRI_INDEX_NOT_CHANGE);
					}
					else
					{
						m_instance->refreshMenu(VENUS_FMGRI_INDEX_ERROR_CODE, FS_MSDC_MOUNT_ERROR);
					}
				}
				else if (fs_ret > 0)
				{
					/* Sent FMT create folder request in function prepareSystemFolders,
					   so draw loading here. */
					updatePage(m_instance, m_pageId, 0, VFX_TRUE, VFX_TRUE);
				}
			}
		}
		else
		{
			m_instance->refreshMenu(VENUS_FMGRI_INDEX_NOT_CHANGE);
		}
	}
}

void VappFmgrPage::onExit(VfxBool isBackward)
{
    VAPP_FMGR_TRACE2(TRC_VAPP_FMGR_PAGE_ONEXIT, "[VAPPFMGR]page onExit page id %d, m_exit %d", m_pageId, m_exit);

    if (m_exit)
    {
    /* Page is exiting because back to up level */
    if (m_instance != NULL && 
    (m_pageId >= VAPP_FMGR_DRAW_NORMAL_LIST_PAGE && 
    m_pageId <= VAPP_FMGR_DRAW_MEDIA_PICKER_LAST_PAGE))     // For media picker
    {
    m_instance->exitFolder();
    }
    }

    VfxPage::onExit(isBackward);
}


void VappFmgrPage::onBack()
{
    VAPP_FMGR_TRACE1(TRC_VAPP_FMGR_PAGE_ONBACK, "[VAPPFMGR]page onBack page id %d", m_pageId);
    
    if (m_instance == NULL)
    {
        VfxPage::onBack();
    }    

		VfxU8 instance_type = m_instance->getInstanceType();
		
    switch(instance_type) 
    {
        case VappFmgrInstance::VAPP_FMGR_TYPE_APP:
        {
            if (m_instance->GetDisplayStyle() == VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE)
            {
                VappFmgrMain* instance = (VappFmgrMain*)m_instance;
                instance->closeMarkSeveralEx();
            }
            else
            {
                /* Page is exiting because back to up level */
                if (m_pageId >= VAPP_FMGR_DRAW_NORMAL_LIST_PAGE &&
                    m_pageId <= VAPP_FMGR_DRAW_MEDIA_PICKER_LAST_PAGE)     // For media picker
                {
                    setExit();
                }
                VfxPage::onBack();
            }
            break;
        }

        case VappFmgrInstance::VAPP_FMGR2_TYPE_FILE_SELECTOR:
        {
            VappFmgrFileSelectorCUI* instance = (VappFmgrFileSelectorCUI*)m_instance;
            instance->leaveFolderEx(0);
            break;
        }

        case VappFmgrInstance::VAPP_FMGR2_TYPE_FOLDER_SELECTOR:
        {
            VappFmgrFolderSelectorCUI* instance = (VappFmgrFolderSelectorCUI*)m_instance;
            instance->leaveFolderEx(0);
            break;
        }

        case VappFmgrInstance::VAPP_FMGR2_TYPE_FOLDER_BROWSER:
        {
            if (m_pageId == VappFmgrPage::VAPP_FMGR_DRAW_FOLDER_BROWSER_LAUNCH_PAGE)
            {
                VappFmgrFolderBrowserLaunch* instance = (VappFmgrFolderBrowserLaunch*)m_instance;

                if (m_instance->GetDisplayStyle() == VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE)
                {
                    instance->closeMarkSeveralEx();
                }
                else
                {
                    instance->leaveFolderEx(0);
                }
            }
            else
            {
                VfxPage::onBack();
            }
            break;
        }
        // For media picker
        case VappFmgrInstance::VAPP_FMGR2_TYPE_MEDIA_PICKER:
        {
            VappFmgrMediaPickerCUI* instance = (VappFmgrMediaPickerCUI*)m_instance;

            if (m_instance->GetDisplayStyle() == VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE)
            {
                instance->closeMarkSeveral();
            }
            else
            {
                instance->leaveFolderEx(0);
            }
            break;
        }
        default:
            VfxPage::onBack();
            break;
    };
}

void VappFmgrPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
    /* Only file selector CUI support rotation */
    VappFmgrFileSelectorCUI *instance = (VappFmgrFileSelectorCUI*)m_instance;
    
    if (instance != NULL && 
        (instance->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrFileSelectorCUI)) 
         || instance->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrFolderSelectorCUI))))
    {
      	if(param.rotateTo == VFX_SCR_ROTATE_TYPE_0 || param.rotateTo == VFX_SCR_ROTATE_TYPE_270 || param.rotateTo == VFX_SCR_ROTATE_TYPE_90) 
    	{
    				
    	}
    	else
    	{
    		param.rotateTo = VFX_SCR_ROTATE_TYPE_NORMAL;
        }
    }
}

void VappFmgrPage::onRotate(const VfxScreenRotateParam &param)
{
    /* Only file selector CUI support rotation */
    VappFmgrFileSelectorCUI *instance = (VappFmgrFileSelectorCUI*)m_instance;
    
    if (instance != NULL && instance->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrFileSelectorCUI)))
    {
        VfxRect rect = getRect();
    }
}
    
VfxBool VappFmgrPage::onSerialize(VfxArchive & ar)
{
	if (m_pageId >= VAPP_FMGR_DRAW_NORMAL_LIST_PAGE && 		
		m_pageId <= VAPP_FMGR_DRAW_FOLDER_BROWSER_LAUNCH_PAGE)
	{
	    if (m_pFolder != NULL)
        {   
    	    /* Save parent folder length */
    	    VfxS32 len = (app_ucs2_strlen((const kal_int8*)m_pFolder)+1)*ENCODING_LENGTH;
            if (len > VAPP_FMGR_FILE_PATH_LEN)
            {
                len = VAPP_FMGR_FILE_PATH_LEN;
            }
            ar.writeU32((VfxU32)len);
            /* Save parent folder name */
    	    ar.write(m_pFolder, len);
        }
        else
        {
            ar.writeU32(0);
        }
	    ar.writeU32((VfxU32)m_restore);
		ar.writeU32((VfxU32)m_instance);
		ar.writeU32(m_pageId);
        if (m_instance != NULL)
        {
            VfxS32 index = m_instance->getCurIndex();
            if (index < 0)
            {
                index = 0;
            }
            
            ar.writeU32((VfxU32)index);
        }
        
		if (m_menu_view_state != NULL)
		{
			/* Save list menu archive */			
			ar.write((VfxU8 *)m_menu_view_state, sizeof(VcpBaseMenuViewState));
		}
        else
        {
            VcpBaseMenuViewState history;
            memset(&history, 0, sizeof(VcpBaseMenuViewState));            
                
            if (m_listmenu != NULL)
            {
                m_listmenu->getViewState(&history);
            }
            else if (m_glist != NULL)
            {
                m_glist->getViewState(&history);
            }

            history.focusGroup = -1;
            history.focusPos = -1;

            ar.write((VfxU8 *)&history, sizeof(VcpBaseMenuViewState));
        }
        
		return VFX_TRUE;
	}

	return VFX_FALSE;
}

void VappFmgrPage::onRestore(VfxArchive & ar)
{
    if (m_pFolder != NULL)
    {
        VFX_FREE_MEM(m_pFolder);
    }

    /* Read parent folder length */
    VfxS32 len = (VfxS32)ar.readU32();
    if (len > 0)
    {
        VFX_ASSERT(len <= VAPP_FMGR_FILE_PATH_LEN);
        VFX_ALLOC_MEM(m_pFolder, len, this);
        memset(m_pFolder, 0, len);        
        ar.read(m_pFolder, len);
    }
    m_restore = (VfxBool)ar.readU32();
	m_instance = (VappFmgrInstance*)ar.readU32();
	m_pageId = ar.readU32();
    VfxS32 index = -1;
    if (m_instance != NULL)
    {
        index = (VfxU32)ar.readU32();
        m_instance->setCurIndex(index);
    }   	

	if (m_menu_view_state == NULL)
	{
		VFX_ALLOC_MEM(m_menu_view_state, sizeof(VcpBaseMenuViewState), this);
		memset(m_menu_view_state, 0, sizeof(VcpBaseMenuViewState));

		ar.read((VfxU8 *)m_menu_view_state, sizeof(VcpBaseMenuViewState));
	}

    
	m_instance->setPageObj(this);

	m_signalGetTitleStrAndIcn.connect(m_instance, &VappFmgrInstance::getTitleStrAndIcn);
    m_signalGetOptMenuItem.connect(m_instance, &VappFmgrInstance::getOptionItem);

	VfxBool draw_loading = VFX_FALSE;
	if (m_pageId >= VAPP_FMGR_DRAW_NORMAL_LIST_PAGE && m_pageId <= VAPP_FMGR_DRAW_FOLDER_BROWSER_LAUNCH_PAGE)
	{
		draw_loading = VFX_TRUE;
	}
	updatePage(m_instance, m_pageId, index, VFX_TRUE, draw_loading);
    m_restore = VFX_FALSE;
}

void VappFmgrPage::onListFocusChange(VcpListMenu *list, // Sender
        VfxU32 index,        // Current focus list item index
        VfxU32 pre_index)
{
	if (list == m_listmenu && m_focus_timer != NULL)
	{
		m_focus_timer->stop();
	}
}

void VappFmgrPage::onTimeUp(VfxTimer* timer)
{
	if (timer == m_focus_timer)
	{
		if (m_listmenu != NULL)
		{
			m_listmenu->getLayout()->clearFocusItem();
		}
	}
}

void VappFmgrPage::setBounds(const VfxRect &value)
{	
	VfxSize size = getSize();
	VfxS32 list_width = size.width, list_height = size.height;

	if (size.width != 0 && size.height != 0)
	{
		if (size.width != value.getWidth() ||
			size.height != value.getHeight())
		{
			list_width = value.getWidth();
			list_height = value.getHeight();
		}

		if (m_form != NULL && m_form->getHidden() == VFX_FALSE)
		{
			m_form->setBounds(VfxRect(0,
									  0,
								      list_width,
								      list_height));
		}
		
		if (m_textframe != NULL && m_textframe->getHidden() == VFX_FALSE)
		{			
			VfxS32 x = (VfxS32)(list_width/2), y = (VfxS32)(list_height/2);
			m_textframe->setAnchor(0.5, 0.5);
			m_textframe->setPos(x, y);
			m_textframe->setBounds(VfxRect(0,
										   0,
										   list_width,
										   80));
		}

        if (m_first_cell != NULL && m_first_cell->getHidden() == VFX_FALSE)
        {
            m_first_cell->reLayout(list_width, m_first_cell->getSize().height);
        }
        
		if (m_listmenu != NULL)
		{
			if (m_first_cell!= NULL)
			{
				m_listmenu->setBounds(VfxRect(value.getX(), 
											   value.getY(),
											   list_width,
											   list_height - m_first_cell->getSize().height));
			}
			else
			{
				m_listmenu->setBounds(VfxRect(value.getX(), 
											   value.getY(),
											   list_width,
											   list_height));
			}
		}
		else if (m_glist != NULL)
		{
			if (m_first_cell!= NULL)
			{
				m_glist->setBounds(VfxRect(value.getX(), 
											   value.getY(),
											   list_width,
											   list_height - m_first_cell->getSize().height));
			}
			else
			{
				m_glist->setBounds(VfxRect(value.getX(), 
											   value.getY(),
											   list_width,
											   list_height));
			}
		}
	}

	if (size.width != value.getWidth() ||
		size.height != value.getHeight())
	{
		VfxPage::setBounds(value);
	}
}

void VappFmgrPage::setTextFrame(VfxTextFrame* textframe)
{
	m_textframe = textframe;
}

VfxTextFrame* VappFmgrPage::getTextFrame(void)
{
	return m_textframe;
}

void VappFmgrPage::setInstance(VappFmgrInstance *instance)
{
	m_instance = instance;
}

void VappFmgrPage::setPageId(VfxU32 pageId)
{
	m_pageId = pageId;
}

VfxU32 VappFmgrPage::getPageId(void) const
{
	return m_pageId;
}

VfxU32 VappFmgrPage::convertPageIdToCPTabIndex(VfxU32 page_id)
{
    VfxU32 table_index = 0;
    if (page_id <= VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE || page_id >= VAPP_FMGR_DRAW_FOLDER_BROWSER_LAUNCH_PAGE)
    {
        table_index = page_id;
    }
    // normal list page
    else if (page_id <= VAPP_FMGR_DRAW_NORMAL_LIST_LAST_PAGE)
    {
        table_index = VAPP_FMGR_DRAW_NORMAL_LIST_PAGE;
    }
    // file selector
    else if (page_id <= VAPP_FMGR_DRAW_SINGLE_FILE_SELECT_LAST_PAGE)
    {
        table_index = VAPP_FMGR_DRAW_SINGLE_FILE_SELECT_PAGE;
    }
    // multi file selector
    else if (page_id <= VAPP_FMGR_DRAW_MULTI_FILE_SELECT_LAST_PAGE)
    {
        table_index = VAPP_FMGR_DRAW_MULTI_FILE_SELECT_PAGE;
    }
    // folder selector
    else if (page_id <= VAPP_FMGR_DRAW_FOLDER_SELECT_LAST_PAGE)
    {
        table_index = VAPP_FMGR_DRAW_FOLDER_SELECT_PAGE;
    }
    // For media picker
    else if(page_id <= VAPP_FMGR_DRAW_MEDIA_PICKER_LAST_PAGE)
    {
        table_index = VAPP_FMGR_DRAW_MEDIA_PICKER_PAGE;
    }
    // media picker
    if (table_index > VAPP_FMGR_DRAW_MEDIA_PICKER_LAST_PAGE)
    {
        table_index -= (VAPP_FMGR_DRAW_MEDIA_PICKER_LAST_PAGE - VAPP_FMGR_DRAW_MEDIA_PICKER_PAGE);
    }
    // folder selector
    if (table_index > VAPP_FMGR_DRAW_FOLDER_SELECT_LAST_PAGE)
    {
        table_index -= (VAPP_FMGR_DRAW_FOLDER_SELECT_LAST_PAGE - VAPP_FMGR_DRAW_FOLDER_SELECT_PAGE);
    }
    // multi file selector
    if (table_index > VAPP_FMGR_DRAW_MULTI_FILE_SELECT_LAST_PAGE)
    {
        table_index -= (VAPP_FMGR_DRAW_MULTI_FILE_SELECT_LAST_PAGE - VAPP_FMGR_DRAW_MULTI_FILE_SELECT_PAGE);
    }
    // file selector
    if (table_index > VAPP_FMGR_DRAW_SINGLE_FILE_SELECT_LAST_PAGE)
    {
        table_index -= (VAPP_FMGR_DRAW_SINGLE_FILE_SELECT_LAST_PAGE - VAPP_FMGR_DRAW_SINGLE_FILE_SELECT_PAGE);
    }
    // normal list
    if (table_index > VAPP_FMGR_DRAW_NORMAL_LIST_LAST_PAGE)
    {
        table_index -= (VAPP_FMGR_DRAW_NORMAL_LIST_LAST_PAGE - VAPP_FMGR_DRAW_NORMAL_LIST_PAGE);
    }
    return table_index;
}
		
void VappFmgrPage::updatePage(VfxObject *obj, VfxU32 page_id, VfxS32 cur_index, VfxBool list_reset, VfxBool draw_loading)
{
	if (page_id > VAPP_FMGR_DRAW_STORAGE_DETAIL_MEM_PAGE)
	{
		return;
	}

	VfxU32 table_index = convertPageIdToCPTabIndex(page_id);

    // according to page cp table index, update related part
	VFX_ASSERT(table_index < m_page_cp_table_size);
	
	if (m_page_cp_table[table_index].titlebar)
	{
		drawTitleBar(obj);
	}

	if (m_page_cp_table[table_index].titlecell)
	{
		drawTitleCell(obj, draw_loading);
	}

	if (m_page_cp_table[table_index].body && !m_restore)
	{
		updatePageBody(obj, table_index, cur_index, list_reset, draw_loading);
	}

	if (m_page_cp_table[table_index].toolbar)
	{
		drawToolBar(obj);
	}

	setBounds(VfxRect(0, 0, getSize().width, getSize().height));	
}

void VappFmgrPage::updatePageTitle(VfxObject *obj, VfxId page_id)
{
	if (page_id > VAPP_FMGR_DRAW_STORAGE_DETAIL_MEM_PAGE)
	{
		return;
	}

	if (m_page_cp_table[page_id].titlebar)
	{
		drawTitleBar(obj);
	}

	if (m_page_cp_table[page_id].titlecell)
	{
		drawTitleCell(obj);
	}
}

void VappFmgrPage::updatePageBody(VfxObject *obj, VfxId page_id, VfxS32 cur_index, VfxBool list_reset, VfxBool draw_loading)
{
	if (page_id > VAPP_FMGR_DRAW_STORAGE_DETAIL_MEM_PAGE)
	{
		return;
	}

	if (m_page_cp_table[page_id].body)
	{
		VappFmgrInstance *instance = (VappFmgrInstance*)obj;

		if (instance != NULL &&
			instance->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrInstance)))
		{
			if (m_textframe != NULL)
			{
				m_textframe->setHidden(VFX_TRUE);
			}
			
			if (m_pageId < VAPP_FMGR_DRAW_FILE_DETAIL_PAGE)
			{
				VappFmgrFSData *fsdata = instance->getFSDataObj();
				if (fsdata != NULL)
				{
					VfxS32 count = fsdata->getCount();
					VfxU32 style = 0;
					
                    if (draw_loading)
					{
						/* update page at onRestore */
						style = VAPP_FMGR_LOADING;

						cur_index = SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY;
					}
					else if (count < 0)
					{
						/* Loading or error handling*/
						style = VAPP_FMGR_LOADING;

						cur_index = count;
					}
					else if (count > 0)
					{
						if (m_pageId == VAPP_FMGR_DRAW_DRV_PHONE_PAGE ||
							m_pageId == VAPP_FMGR_DRAW_DRV_MEM_PAGE)
						{
							style = VAPP_FMGR_LIST_GROUP;
						}
						else if (m_pageId == VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE)
						{
							style = VAPP_FMGR_LIST_MULTI_SELECT_FOR_MARK_SEVERAL;
						}
						else if (m_pageId >= VAPP_FMGR_DRAW_NORMAL_LIST_PAGE && page_id <= VAPP_FMGR_DRAW_NORMAL_LIST_LAST_PAGE ||
                                 m_pageId == VAPP_FMGR_DRAW_FOLDER_BROWSER_LAUNCH_PAGE)
						{
							style = VAPP_FMGR_LIST_NORMAL;
						}
						else if (m_pageId >= VAPP_FMGR_DRAW_SINGLE_FILE_SELECT_PAGE && page_id <= VAPP_FMGR_DRAW_SINGLE_FILE_SELECT_LAST_PAGE)
						{
							style = VAPP_FMGR_LIST_SINGLE_FILE_SELECT;
						}
						else if (m_pageId >= VAPP_FMGR_DRAW_MULTI_FILE_SELECT_PAGE && page_id <= VAPP_FMGR_DRAW_MULTI_FILE_SELECT_LAST_PAGE)
						{
							style = VAPP_FMGR_LIST_MULTI_SELECT;
						}
						else if (m_pageId >= VAPP_FMGR_DRAW_FOLDER_SELECT_PAGE && page_id <= VAPP_FMGR_DRAW_FOLDER_SELECT_LAST_PAGE)
						{
							style = VAPP_FMGR_LIST_SINGLE_FOLDER_SELECT;
						}
					}
					else
					{
						/* empty */
						style = VAPP_FMGR_EMPTY;
					}
					drawPageBody(obj, style, cur_index, list_reset);
				}				
			}
			else if (m_pageId == VAPP_FMGR_DRAW_FILE_DETAIL_PAGE)
			{
				drawFileDetail();
			}
			else if (m_pageId == VAPP_FMGR_DRAW_STORAGE_DETAIL_PHONE_PAGE ||
				     m_pageId == VAPP_FMGR_DRAW_STORAGE_DETAIL_MEM_PAGE)
			{
				drawStorageDetail();
			}
		}
	}
}

void VappFmgrPage::updatePageOptionMenu(VfxObject *obj, VfxId page_id)
{
	if (m_page_cp_table[page_id].toolbar)
	{
		drawToolBar(obj);
	}
}
		
void VappFmgrPage::removeAllButtonsFromToolbar(VfxU16 &opt_menu_id)
{
	if (m_toolbar != NULL)
	{
		VfxU16 child_id = 0, opt_menu_num = GetNumOfChild(opt_menu_id), i = 0;
		
		for (i = 0; i < opt_menu_num; i++)
		{
			child_id = GetSeqItemId(opt_menu_id, (U16)i);
			m_toolbar->removeItem(child_id);
		}
	}
}

void VappFmgrPage::startNewFolderHiiteAnim(VfxS32 cur_index)
{
	if (m_listmenu != NULL)
	{		
		m_listmenu->setVisibleMenuRegion(cur_index, -1, VFX_TRUE);
	}
}

void VappFmgrPage::setMenuViewState(VcpBaseMenuViewState* history)
{
	if (m_menu_view_state != NULL)
	{		
		VFX_FREE_MEM(m_menu_view_state);
		m_menu_view_state = NULL;
	}

    VFX_ALLOC_MEM(m_menu_view_state, sizeof(VcpBaseMenuViewState), this);
    memcpy(m_menu_view_state, history, sizeof(VcpBaseMenuViewState));
}

void VappFmgrPage::resetMenuViewState(void)
{
	if (m_menu_view_state != NULL)
	{		
		VFX_FREE_MEM(m_menu_view_state);
		m_menu_view_state = NULL;
	}
}

void VappFmgrPage::showLoadingIndicator(void)
{
    if (m_loading == NULL)
    {
        VFX_OBJ_CREATE(m_loading, VcpActivityIndicator, this);
        m_loading->setSize(VfxSize(30,30));
        m_loading->setAnchor(0.5, 0.5);
        m_loading->setHiddenWhenStopped(VFX_TRUE);
        m_loading->setPos(getSize().width / 2, getSize().height / 2);
        m_loading->start();

        getMainScr()->setIsDisabled(VFX_TRUE);
    }
}

void VappFmgrPage::closeLoadingIndicator(void)
{
    if (m_loading != NULL)
    {
        VFX_OBJ_CLOSE(m_loading);
        if (getMainScr()->getIsDisabled())
        {
            getMainScr()->setIsDisabled(VFX_FALSE);
        }
    }    
}

void VappFmgrPage::setExit(void)
{
    m_exit = VFX_TRUE;
}

VfxBool VappFmgrPage::getExit(void)
{
    return m_exit;
}

void VappFmgrPage::setPageRestore(VfxBool restore)
{
    m_restore = restore;
}

VfxBool VappFmgrPage::checkPageRestore()
{
    return m_restore;
}

void VappFmgrPage::closePage()
{
	VfxMainScr *scr = getMainScr();
	if (scr != NULL)
	{
	    VAPP_FMGR_TRACE2(TRC_VAPP_FMGR_CLOSE_PAGE, "[VAPPFMGR]close page, m_id %d, line %d", (m_pageId+1), __LINE__);
		scr->closePage(m_pageId+1);
	}
}

void VappFmgrPage::popPage()
{
	VfxMainScr *scr = getMainScr();
	scr->popPage();
}

void VappFmgrPage::pushPage(VfxId id, VfxPage * p)
{
	VfxMainScr *scr = getMainScr();
	if (scr != NULL)
	{
		scr->pushPage(id, p);
	}
}

void VappFmgrPage::closePage(VfxId page_id)
{
	VfxMainScr *scr = getMainScr();
    VAPP_FMGR_TRACE2(TRC_VAPP_FMGR_CLOSE_PAGE, "[VAPPFMGR]close page, m_id %d, line %d", page_id, __LINE__);
	scr->closePage(page_id);
}

void VappFmgrPage::onUpdatePage(VfxObject *obj, VfxU32 style, VfxU32 cp, VfxS32 cur_index, VfxBool list_reset)
{

	VappFmgrInstance *instance = (VappFmgrInstance*)obj;

	if (m_popup != NULL)
	{
		VFX_OBJ_CLOSE(m_popup);
		m_popup = NULL;
	}
	
	if (instance != NULL)
	{
		if (cp & VAPP_FMGR_UPDATE_PAGE_ALL)
		{
			drawAllPage(obj, style, cur_index, list_reset);
		}
		else
		{			
			if (cp & VAPP_FMGR_UPDATE_PAGE_TITLEBAR)
			{
				drawTitleBar(obj);
			}
			
			if (cp & VAPP_FMGR_UPDATE_PAGE_BODY)
			{
				drawPageBody(obj, style, cur_index, list_reset);
			}

			if (cp & VAPP_FMGR_UPDATE_PAGE_TOOLBAR)
			{
				drawToolBar(obj);
			}

			if (cp & VAPP_FMGR_UPDATE_PAGE_FIRSTCELL)
			{
				drawTitleCell(obj);
			}			
		}

		//VfxFrameAligner::alignChildFrames(this);
		setBounds(VfxRect(0, 0, getSize().width, getSize().height));
	}
}

void VappFmgrPage::drawPageBody(VfxObject *obj, VfxU32 style, VfxS32 cur_index, VfxBool list_reset)
{
	if (style <= VAPP_FMGR_LIST_MULTI_SELECT)
	{
		drawListPage(obj, style, cur_index, list_reset);
	}
	else if (style == VAPP_FMGR_FILE_DETAIL)					
	{
		drawFileDetail();
	}
	else if (style == VAPP_FMGR_LOADING)
	{
		/* error handling or loading */
		drawLoadingPage(list_reset, cur_index);
	}
	else if (style == VAPP_FMGR_EMPTY)
	{
		/* empty case */
		drawEmptyPage(obj);	
	}
	else if (style == VAPP_FMGR_LIST_GROUP)
	{
		drawGroupListPage(obj, style, cur_index, list_reset);
	}
}

void VappFmgrPage::drawListPage(VfxObject *obj, VfxU32 style, VfxS32 cur_index, VfxBool list_reset)
{
	VappFmgrInstance* instance = (VappFmgrInstance*)obj;	

    VAPP_FMGR_TRACE0(TRC_VAPP_FMGR_PAGE_DRAWLISTPAGE, "[VAPPFMGR]drawListPage");
    
	if (m_listmenu == NULL)
	{
		VFX_OBJ_CREATE(m_listmenu, VcpListMenu, this);							
		m_listmenu->setContentProvider(instance);		
	}
	else
	{		
		if (m_listmenu->getContentProvider() == NULL)
		{
			m_listmenu->setContentProvider(instance);			
		}
		m_listmenu->setHidden(VFX_FALSE);		
		m_listmenu->updateAllItems();		
	}

    if (m_menu_view_state != NULL && cur_index >= 0)
    {   
	    m_menu_view_state->focusPos = cur_index;
        m_listmenu->setViewState(m_menu_view_state);
        resetMenuViewState();
    }
    
	if (cur_index >= 0 && m_instance != NULL && app_ucs2_strlen(m_instance->getSearchFilename(instance->getInstanceId())) > 0)
	{
		/* Reset search file name */
		m_instance->setSearchFilename(m_instance->getInstanceId(), NULL);
        m_instance->setCurIndex(-1);
	}
	
	if (m_first_cell != NULL)
	{
		m_listmenu->setPos(VfxPoint(0, VappFmgrTitleCell::ITEM_HEIGHT));
	}
}

void VappFmgrPage::drawGroupListPage(VfxObject *obj, VfxU32 style,  VfxS32 cur_index, VfxBool list_reset)
{
	VappFmgrInstance* instance = (VappFmgrInstance*)obj;	
    VAPP_FMGR_TRACE0(TRC_VAPP_FMGR_PAGE_DRAWGROUPLISTPAGE, "[VAPPFMGR]drawGroupListPage");
    
	if (m_glist == NULL)
	{
		VFX_OBJ_CREATE(m_glist, VcpGroupListMenu, this);		
		m_glist->setContentProvider(instance);
	}
	else
	{		
		if (m_glist->getContentProvider() == NULL)
		{
			m_glist->setContentProvider(instance);			
		}
		m_glist->setHidden(VFX_FALSE);		
		m_glist->updateAllItems();		
	}

    if (m_instance != NULL)
    {
        VcpMenuPos pos = m_instance->getGroupPos();

        if (m_menu_view_state != NULL && pos.group >= 0 && pos.pos >= 0)
        {
            m_menu_view_state->focusPos = m_instance->getGroupPos().pos;
            m_glist->setViewState(m_menu_view_state);
            resetMenuViewState();
        }
        
    	if (pos.group >= 0 && pos.pos >= 0 && app_ucs2_strlen(m_instance->getSearchFilename(m_instance->getInstanceId())) > 0)
    	{    		               		
    		/* Reset search file name */
    		m_instance->setSearchFilename(instance->getInstanceId(), NULL);
            m_instance->setCurIndex(-1);
    	}
    }
    
	if (m_first_cell != NULL)
	{
		m_glist->setPos(VfxPoint(0, VappFmgrTitleCell::ITEM_HEIGHT));
	}
}

void VappFmgrPage::drawTitleBar(VfxObject *obj)
{
	if (m_titlebar == NULL)
	{
		VFX_OBJ_CREATE(m_titlebar, VcpTitleBar, this);
		m_titlebar->setTitleStyle(VCP_TITLE_BAR_STYLE_BASE);
		m_titlebar->setTitle(STR_ID_VAPP_FMGR_APP_TITLE);
		setTopBar(m_titlebar);
	}

	VfxU16 title_icn = 0;
	VfxWString title;
#if !defined(__COSMOS_SLIM_FMGR_MT6260__)
	if (m_pageId != VAPP_FMGR_DRAW_FILE_DETAIL_PAGE)
#endif // #if !defined(__COSMOS_SLIM_FMGR_MT6260__)
	{				
		if (m_instance)
	{				
		m_instance->getTitleStrAndIcn(title, VAPP_FMGR_PAGE_TITLE_BAR_MAIN_STR, title_icn);
	}
	}
#if !defined(__COSMOS_SLIM_FMGR_MT6260__)
	else
	{
	    VappFmgrFileDetail *page = (VappFmgrFileDetail*)this;
        VAPP_FMGR_FILE_INFO_STRUCT* file_info = page->getFileInfo();
        if (file_info != NULL)
        {
            if (file_info->attribute & FS_ATTR_DIR)
            {
		        title.loadFromRes(STR_ID_VAPP_FMGR_DETAIL_FOLDER_TITLE);
            }
            else
            {
                title.loadFromRes(STR_ID_VAPP_FMGR_DETAIL_FILE_TITLE);
            }
        }
	}
#endif // #if !defined(__COSMOS_SLIM_FMGR_MT6260__)
	if (m_titlebar->getTitle() != title)
	{
		m_titlebar->setTitle(title);
	}
	m_titlebar->setHidden(VFX_FALSE);	
}

void VappFmgrPage::drawTitleCell(VfxObject *obj, VfxBool draw_loading)
{
	VappFmgrInstance* instance = (VappFmgrInstance*)obj;
	VfxU16 title_icn;
	VfxWString title, sub_title;
	
	if (m_first_cell == NULL)
	{
		VFX_OBJ_CREATE(m_first_cell, VappFmgrTitleCell, this);		
	}

    if (m_pFolder == NULL)
    {
	    m_signalGetTitleStrAndIcn.emit(title, VAPP_FMGR_PAGE_TITLE_CELL_MAIN_STR, title_icn);
        
        VFX_ALLOC_MEM(m_pFolder, VAPP_FMGR_FILE_PATH_LEN, this);
        memset(m_pFolder, 0, VAPP_FMGR_FILE_PATH_LEN);
        app_ucs2_strncpy((kal_int8*)m_pFolder, (const kal_int8*)title.getBuf(), SRV_FMGR_PATH_MAX_LEN);
    }
    else
    {
        title.loadFromMem((VfxWChar*)m_pFolder);
    }
    
	m_first_cell->setMainText(title);

	if (draw_loading)
	{
		/* draw at onRestore */
		title.loadFromRes(STR_GLOBAL_LOADING);
	}
	else
	{
		m_signalGetTitleStrAndIcn.emit(title, VAPP_FMGR_PAGE_TITLE_CELL_SUB_STR, title_icn);
	}
	m_first_cell->setSubText(title);
	m_signalGetTitleStrAndIcn.emit(title, VAPP_FMGR_PAGE_TITLE_CELL_UP_BUTTON, title_icn);
	if (title_icn != 0)
	{
        m_first_cell->getUpButton()->m_signalClicked.disconnect(instance, &VappFmgrInstance::onClickUpButton);
		m_first_cell->getUpButton()->setIsDisabled(VFX_FALSE);
		m_first_cell->getUpButton()->m_signalClicked.connect(instance, &VappFmgrInstance::onClickUpButton);
	}
	else
	{
		m_first_cell->getUpButton()->setIsDisabled(VFX_TRUE);
	}
}

void VappFmgrPage::drawAllPage(VfxObject *obj, VfxU32 style, VfxS32 cur_index, VfxBool list_reset)
{
	drawTitleBar(obj);
	
	drawPageBody(obj, style, cur_index, list_reset);
	
	drawToolBar(obj);
}

void VappFmgrPage::drawLoadingPage(VfxBool list_reset, VfxS32 fs_error)
{
    if (m_pageId == VAPP_FMGR_DRAW_DRV_PHONE_PAGE ||
		m_pageId == VAPP_FMGR_DRAW_DRV_MEM_PAGE ||
		m_pageId == VAPP_FMGR_DRAW_STORAGE_DETAIL_PHONE_PAGE ||
		m_pageId == VAPP_FMGR_DRAW_STORAGE_DETAIL_MEM_PAGE)
	{
		VfxU16 str_id;

		if (m_textframe == NULL)
		{
			VFX_OBJ_CREATE(m_textframe, VfxTextFrame, this);
			m_textframe->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_EMPTY));
            m_textframe->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(TEXT_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
		}
		else
		{
			m_textframe->setHidden(VFX_FALSE);
		}


		if (fs_error == SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY)
		{
			/* String id of loading */
			str_id = STR_GLOBAL_LOADING;
		}
		else
		{
		    /* Reset view state */            
            if (m_listmenu != NULL)
        	{
        	    m_listmenu->resetAllItems(VFX_FALSE);
        	}
        	else if (m_glist != NULL)
        	{
        	    m_glist->resetAllItems(VFX_FALSE);
        	}
            
			if (fs_error == FS_DRIVE_NOT_FOUND ||
				(fs_error <= FS_MSDC_MOUNT_ERROR && fs_error >= FS_MSDC_NOT_PRESENT) ||
				fs_error == FS_MEDIA_CHANGED ||
				fs_error == FS_DRIVE_NOT_READY)
			{
				/* No memory card */
				str_id = STR_GLOBAL_INSERT_MEMORY_CARD;                                                
			}
			else
			{
				str_id = srv_fmgr_fs_error_get_string(fs_error);
			}
		}

		m_textframe->setString(str_id);
	}
    
	if (m_listmenu != NULL)
	{
		m_listmenu->setHidden(VFX_TRUE);
		m_listmenu->setContentProvider(NULL);
		if (list_reset)
		{
			m_listmenu->updateAllItems();
		}		
	}
	else if (m_glist != NULL)
	{
		m_glist->setHidden(VFX_TRUE);
		m_glist->setContentProvider(NULL);
		if (list_reset)
		{
			m_glist->updateAllItems();
		}		
	}
    
}

void VappFmgrPage::drawEmptyPage(VfxObject *obj)
{
	if (m_listmenu != NULL)
	{
		m_listmenu->setHidden(VFX_TRUE);
	}	
}

void VappFmgrPage::drawToolBar(VfxObject *obj)
{
	//m_signalSetToolBar.emit(this, m_toolbar);
	VfxU16 opt_menu = 0, opt_menu_num = 0;
	VappFmgrInstance* instance = (VappFmgrInstance*)obj;	
	
	m_signalGetOptMenuItem.emit(m_pageId, opt_menu, opt_menu_num);

	if (opt_menu_num == 0)
	{
		/* No option menu item */
		if (m_toolbar != NULL)
		{
			removeAllButtonsFromToolbar(opt_menu);
		}
		
		return;
	}	
	
	if (m_toolbar == NULL)
	{
		VFX_OBJ_CREATE(m_toolbar, VcpToolBar, this);
	}	
	else
	{
		removeAllButtonsFromToolbar(opt_menu);
	}
	
	for (VfxS32 i = 0; i < opt_menu_num; i++)
	{
		VfxU16 child_id = GetSeqItemId_Ext(opt_menu, (U16)i);
		VfxU16 img_id = GetImageIdOfItem(child_id);
		if (img_id == 0)
		{
			img_id = (IMG_GLOBAL_L1+i);
		}
		m_toolbar->addItem(child_id, GetStringIdOfItem(child_id), img_id);

		/* Disable items if it should be */
		if (instance->isMenuItemDisable(m_pageId, child_id))
		{
			m_toolbar->setDisableItem(child_id, VFX_TRUE);
		}
		else
		{
			m_toolbar->setDisableItem(child_id, VFX_FALSE);
		}
	}

	
	m_toolbar->m_signalButtonTap.connect(obj, &VappFmgrInstance::onClickToolBarButton);
	m_toolbar->setHidden(VFX_FALSE);
    setBottomBar(m_toolbar);
}

void VappFmgrPage::popupError(VfxObject *obj, VfxS32 error)
{
	if (m_popup == NULL)
	{
		VFX_OBJ_CREATE(m_popup, VcpCommandPopup, getMainScr());
		m_popup->setInfoType(VCP_POPUP_TYPE_INFO);
		m_popup->setText(VFX_WSTR("Loading..."));
		m_popup->show(VFX_TRUE);
	}
}

VcpToolBar* VappFmgrPage::getToolBarObj(void)
{
	return m_toolbar;
}

VappFmgrTitleCell *VappFmgrPage::getFirstCell(void)
{
	return m_first_cell;
}
/*
VFX_IMPLEMENT_CLASS("VappFmgrPagePanel", VappFmgrPagePanel, VcpPagePanel);

void VappFmgrPagePanel::onInit()
{
    VcpPagePanel::onInit(); // call base class	
}
*/

#ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
VFX_IMPLEMENT_CLASS("VappFmgrDrvTabPage", VappFmgrDrvTabPage, VcpTabCtrlPage);

VappFmgrDrvTabPage::VappFmgrDrvTabPage() :
m_instance(NULL)
{
}

VappFmgrDrvTabPage::VappFmgrDrvTabPage(VappFmgrInstance* instance) :
m_instance(instance)
{
}
    

void VappFmgrDrvTabPage::onInit()
{
    VcpTabCtrlPage::onInit(); // call base class
    
	m_phone_page = NULL;
	m_mem_page = NULL;

	VfxU16 icon_id = IMG_NONE;
	VappFmgrMainScr *obj = (VappFmgrMainScr*)getMainScr();
	VappFmgrInstance *instance = obj->getCallerInstance();
	VappFmgrFSData *fsdata = instance->getFSDataObj();
	VfxS32 i = 0, drv_count = 0, fs_ret = 0;
	vapp_fmgr_drive_info_struct drv_info;
	VfxS8 drv_name[40];
	
	if (fsdata != NULL)
	{
		/* get drive count to add tab */
		drv_count = fsdata->getDrvCount(instance);

		for (i = 0; i < drv_count; i++)
		{
			fs_ret = fsdata->getDrvInfo(instance, i, &drv_info);
			if (fs_ret >= 0 
                && (drv_info.drv_type == SRV_FMGR_DRV_PHONE_TYPE || drv_info.drv_type == SRV_FMGR_DRV_CARD_TYPE))
			{
				if (drv_info.drv_type < SRV_FMGR_DRV_CARD_TYPE)
			    {
			        icon_id = IMG_ID_VAPP_FMGR_TAB_PHONE_ICN;
			    }
			    else
			    {
			        icon_id = IMG_ID_VAPP_FMGR_TAB_CARD_ICN;
			    }

                VfxWString text;
				//srv_fmgr_drv_get_name(drv_info.drv_path[0], (WCHAR*)drv_name, 40);
				if (i == 0)
                {
                    text.loadFromRes(STR_GLOBAL_PHONE);
                }
                else
                {
    				fs_ret = 0;
    				//fs_ret = srv_fmgri_drv_get_volume_name(drv_info.drv_path[0], (WCHAR*)drv_name, 40);
    				fs_ret = srv_fmgr_drv_get_name(drv_info.drv_path[0], (WCHAR*)drv_name, 40);
                    if (fs_ret >= 0)
                    {
                        text.loadFromMem((VfxWChar*)drv_name);
                    }
                    else
                    {
                        text.loadFromRes(STR_GLOBAL_MEMORY_CARD);
                    }
                }
								
				addTab((drv_info.drv_type +1 ), text, VcpStateImage(icon_id));
			}
		}
		
	}
}

void VappFmgrDrvTabPage::onDeinit()
{
    if (m_phone_page != NULL)
	{		
		m_phone_page->setInstance(NULL);			
	}
    if (m_mem_page != NULL)
    {
        m_mem_page->setInstance(NULL);
    }
	VcpTabCtrlPage::onDeinit();
}

void VappFmgrDrvTabPage::onTabSwitching(VfxId tabId)
{
    if (m_instance != NULL)
    {
        VfxWString path = m_instance->getFilePath();
        if (path != VAPP_FMGR_PATH_ROOT)
        {
            VfxS32 drv_type = srv_fmgr_drv_get_type((U8)path.getBuf()[0]);

            if (drv_type != (VfxS32)(tabId-1))
            {
            	/* Drv tab switch */
            	m_instance->exitFolder();
            }
        }
    }	 
}

void VappFmgrDrvTabPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
    /* Only file selector CUI support rotation */
    VappFmgrFileSelectorCUI *instance = (VappFmgrFileSelectorCUI*)m_instance;
    
    if (instance != NULL && 
        (instance->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrFileSelectorCUI))
        || instance->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrFolderSelectorCUI))))
    {
      	if(param.rotateTo == VFX_SCR_ROTATE_TYPE_0 || param.rotateTo == VFX_SCR_ROTATE_TYPE_270 || param.rotateTo == VFX_SCR_ROTATE_TYPE_90) 
    	{
    				
    	}
    	else
    	{
    		param.rotateTo = VFX_SCR_ROTATE_TYPE_NORMAL;
        }
    }
}

VfxPage* VappFmgrDrvTabPage::onCreateTabPage(VfxId tabId)
{	
	if (tabId == SRV_FMGR_DRV_PHONE_TYPE + 1)
	{
		if (m_phone_page == NULL)
		{
			VFX_OBJ_CREATE_EX(m_phone_page, VappFmgrPage, getMainScr(), (VappFmgrPage::VAPP_FMGR_DRAW_DRV_PHONE_PAGE, m_instance));
		}

		if (m_instance != NULL)
		{
			m_phone_page->m_signalGetOptMenuItem.connect(m_instance, &VappFmgrMain::getOptionItem);
            m_phone_page->updatePageOptionMenu(m_instance, VappFmgrDrvTabPage::PHONE_STYLE_ID);
		}
		return m_phone_page;
	}
	else if	(tabId == SRV_FMGR_DRV_CARD_TYPE + 1)
	{
		if (m_mem_page == NULL)
		{
			VFX_OBJ_CREATE_EX(m_mem_page, VappFmgrPage, getMainScr(), (VappFmgrPage::VAPP_FMGR_DRAW_DRV_MEM_PAGE, m_instance));
		}

		if (m_instance != NULL)
		{
            m_mem_page->m_signalGetOptMenuItem.connect(m_instance, &VappFmgrMain::getOptionItem);
            m_mem_page->updatePageOptionMenu(m_instance, VappFmgrDrvTabPage::CARD_STYLE_ID);
		}
		
		return m_mem_page;
	}
	else
	{
		VFX_DEV_ASSERT(0);
	}
	
	return NULL;
}

VappFmgrPage* VappFmgrDrvTabPage::getPage(VfxId tabId)
{
	if (tabId == SRV_FMGR_DRV_PHONE_TYPE + 1)
	{		
		return m_phone_page;
	}
	else if (tabId == SRV_FMGR_DRV_CARD_TYPE + 1)
	{		
		//return m_mem_page;
		return m_phone_page;
	}

	return NULL;
}

void VappFmgrDrvTabPage::setInstance(VappFmgrInstance* instance)
{
	m_instance = instance;

    if (m_phone_page != NULL)
	{		
		m_phone_page->setInstance(instance);			
	}
    if (m_mem_page != NULL)
    {
        m_mem_page->setInstance(instance);
    }
}

void VappFmgrDrvTabPage::closeChildPage(void)
{
    if (m_phone_page != NULL)
	{		
		VFX_OBJ_CLOSE(m_phone_page);
        m_phone_page = NULL;
	}
    if (m_mem_page != NULL)
    {
        VFX_OBJ_CLOSE(m_mem_page);
        m_mem_page = NULL;
    }    
}
#endif
#if !defined(__COSMOS_SLIM_FMGR_MT6260__)
VFX_IMPLEMENT_CLASS("VappFmgrStorageCapacityItem", VappFmgrStorageCapacityItem, VcpFormItemBase);

void VappFmgrStorageCapacityItem::onInit()
{
	VcpFormItemBase::onInit();

	setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
	setSize(ITEM_WIDTH, ITEM_HEIGHT);

	VFX_OBJ_CREATE(m_panel, VfxFrame, this);
	m_panel->setSize(IMG_WIDTH, ICON_HEIGHT);
	m_panel->setAnchor(0.5, 0.5);
    m_panel->setPos(ITEM_WIDTH/2, ITEM_HEIGHT/2);
	
	VfxU32 i = 0, x = 0, y = 0;
	for (i = 0; i < NUM_OF_ICON; i++)
	{
		VFX_OBJ_CREATE(m_storage_usage[i], VfxFrame, m_panel);
		m_storage_usage[i]->setBounds(VfxRect(0, 0, ICON_WIDTH, ICON_HEIGHT));
        m_storage_usage[i]->setPos(x, y);
		m_storage_usage[i]->setImgContent(VfxImageSrc(IMG_ID_VAPP_FMGR_STORAGE_REPORT_BAR_BG));
        m_storage_usage[i]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
		x += ICON_WIDTH;
	}
		
	m_panel->setHidden(VFX_TRUE);

    setHeight(ITEM_HEIGHT);
}

void VappFmgrStorageCapacityItem::setUsedSize(VfxFloat percentage)
{
	if (percentage >=0 && percentage <= 1)
	{
		m_panel->setHidden(VFX_FALSE);

		/* Show icon according to storage usage */
		VfxU16 img_id = 0;
		if (percentage < 0.5)
		{
			/* Low */
			img_id = IMG_ID_VAPP_FMGR_STORAGE_REPORT_BAR_LOW;
		}
		else if (percentage >= 0.5 && percentage < 0.8)
		{
			/* Mid */
			img_id = IMG_ID_VAPP_FMGR_STORAGE_REPORT_BAR_MID;
		}
		else
		{
			/* High */
			img_id = IMG_ID_VAPP_FMGR_STORAGE_REPORT_BAR_HIGH;
		}
				
		VfxS32 count = (VfxS32)(NUM_OF_ICON*percentage+0.5), i = 0;
		for (i = 0; i < count; i++)
		{
			if (m_storage_usage[i] != NULL)
			{
				m_storage_usage[i]->setImgContent(VfxImageSrc(img_id));
			}
		}
	}
}

VFX_IMPLEMENT_CLASS("VappFmgrStorageDetailItem", VappFmgrStorageDetailItem, VcpFormItemBase);

void VappFmgrStorageDetailItem::onInit()
{
	VcpFormItemBase::onInit();

	setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
	setSize(ITEM_WIDTH, ITEM_HEIGHT);
	
	m_category = NULL;
	m_size = NULL;
	m_percentage = NULL;

	VfxS32 x = LRGAP;
    VfxS32 y = CATE_TGAP;    

    // create main text
    VFX_OBJ_CREATE(m_category, VfxTextFrame, this);
    m_category->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
    m_category->setPos(x, y);
    m_category->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(MAIN_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
	m_category->setSize(CATE_WIDTH, CATE_HEIGHT);
    m_category->forceUpdate();
    
    y += m_category->getSize().height + SIZE_TGAP;

    // create sub text    
    VFX_OBJ_CREATE(m_size, VfxTextFrame, this);    
    m_size->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
    m_size->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(SUB_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
    m_size->setPos(x, y);
	m_size->setSize(SIZE_WIDTH, SIZE_HEIGHT);
    m_size->forceUpdate();
    
    setHeight(ITEM_HEIGHT);
}

void VappFmgrStorageDetailItem::setCategory(VfxU16 str_id)
{
	if (m_category != NULL)
	{
		m_category->setString(str_id);
	}
}

void VappFmgrStorageDetailItem::setSizeString(const VfxWChar *size)
{
	if (m_size != NULL)
	{
		m_size->setString(size);
	}
}

void VappFmgrStorageDetailItem::setPercentage(VfxFloat percentage)
{
	if (percentage < 1)
	{
		VfxU16 new_value = 0, pre = 0, post = 0;
		new_value = (VfxU16)(percentage*1000);
		pre = new_value/10;
		post = new_value%10;
		if (m_percentage == NULL)
		{
			VFX_OBJ_CREATE(m_percentage, VfxTextFrame, this);
		}
		
		VfxS32 x = ITEM_WIDTH - LRGAP;
		VfxS32 y = ITEM_HEIGHT/2;
		
		m_percentage->setString(VfxWString().format("(%d.%d%%)",pre, post));
		m_percentage->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
        m_percentage->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(MAIN_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
        m_percentage->setAnchor(1.0, 0.5);
	    m_percentage->setPos(x, y);
		m_percentage->setSize(PER_WIDTH, PER_HEIGHT);
	}
}

void VappFmgrStorageDetailItem::setPercentage(VfxWString &text)
{
	if (m_percentage == NULL)
	{
		VFX_OBJ_CREATE(m_percentage, VfxTextFrame, this);
	}
	
	VfxS32 x = ITEM_WIDTH - LRGAP;
    VfxS32 y = ITEM_HEIGHT/2;

	VfxWString tmp = VFX_WSTR("(");
	tmp += text;
	tmp += VFX_WSTR(")");
	m_percentage->setString(tmp);
	m_percentage->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
    m_percentage->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(MAIN_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
    m_percentage->setAnchor(1.0, 0.5);
    m_percentage->setPos(x, y);
	m_percentage->setSize(PER_WIDTH, PER_HEIGHT);
}

VFX_IMPLEMENT_CLASS("VappFmgrStorageDetail", VappFmgrStorageDetail, VappFmgrPage);

void VappFmgrStorageDetail::onInit()
{
    VappFmgrPage::onInit(); // call base class

#ifndef __MMI_SLIM_FILE_MANAGER__
    m_done = VFX_FALSE;
    m_error_code = 0;
	m_sr = NULL;
	m_total_size = 0;
	m_free_size = 0;
	m_capacity = NULL;
    m_total = NULL;
    m_free = NULL;
	m_cur_index = 0;
	m_sys_count = 0;
    m_sys_contents = NULL;

	VfxS8 i = 0;
	for (i = 0; i < g_def_folder_table_size; i++)
	{
    	m_def_contents[i] = NULL;
	}
#else
    m_done = VFX_TRUE;
    m_error_code = 0;
    m_total_size = 0;
	m_free_size = 0;
	m_capacity = NULL;
    m_total = NULL;
    m_free = NULL;
#endif
}

#ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
void VappFmgrStorageDetail::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);
    if (m_pageId == VappFmgrPage::VAPP_FMGR_DRAW_STORAGE_DETAIL_MEM_PAGE && m_form != NULL)
    {
        VfxS32 fs_ret = FS_GetDevStatus(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE), FS_MOUNT_STATE_ENUM);
		VAPP_FMGR_TRACE1(TRC_VAPP_FMGR_SS_ONENTER, "[VAPPFMGR] drawStorageDetail - onEnter FS_GetDevStatus %d", fs_ret);
		if (fs_ret != FS_NO_ERROR)
        {
            /* Memory card is not ready */
            m_form->setHidden(VFX_TRUE);
        }
        else
        {
            m_form->setHidden(VFX_FALSE);
        }
    }
}
#endif

void VappFmgrStorageDetail::onEntered()
{
	if (m_instance != NULL)
	{
		m_instance->setPageObj((VfxPage*)this);
#ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
        VappFmgrStorageReport *sr = (VappFmgrStorageReport*)m_sr;
        if (sr != NULL && sr->isEntered())
        {
			VAPP_FMGR_TRACE1(TRC_VAPP_FMGR_SS_ONENTERED, "[VAPPFMGR] drawStorageDetail - onEntered pageid %d", m_pageId);
		    updatePage(m_instance, m_pageId, -1, VFX_TRUE);
        }
#else
        VAPP_FMGR_TRACE1(TRC_VAPP_FMGR_SS_ONENTERED, "[VAPPFMGR] drawStorageDetail - onEntered pageid %d", m_pageId);
		updatePage(m_instance, m_pageId, -1, VFX_TRUE);
#endif
	}
}

#ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
void VappFmgrStorageDetail::onExit(VfxBool isBackward)
{
	VappFmgrStorageReport *sr = (VappFmgrStorageReport*)m_sr;
	if (sr != NULL && sr->m_jobid > 0)
	{
		srv_fmgr_async_abort(sr->m_jobid, MMI_FALSE);
		sr->m_cancel = VFX_TRUE;
	}	
}
#endif
    
#ifndef __MMI_SLIM_FILE_MANAGER__
VfxS32 VappFmgrStorageDetail::queryFirst()
{
	VfxS8 index = 0;
	VfxS8 *buffer = NULL;
	VfxS32 fs_ret = 0, drv_len = 3;	

	if (m_cur_index < m_sys_count)
	{
		/* get folder path from system folder */
	}
	else
	{
		/* get folder path from default folder */
		index = m_cur_index - m_sys_count;
		
		VFX_ALLOC_MEM(buffer, VAPP_FMGR_FILE_PATH_LEN, this);
		if (m_pageId == VAPP_FMGR_DRAW_STORAGE_DETAIL_PHONE_PAGE)
		{			
			app_ucs2_strncpy((kal_int8*)buffer, (const kal_int8*)srv_fmgr_drv_get_path_by_type(SRV_FMGR_DRV_PHONE_TYPE), SRV_FMGR_PATH_MAX_LEN);			
		}
		else if (m_pageId == VAPP_FMGR_DRAW_STORAGE_DETAIL_MEM_PAGE)
		{
			app_ucs2_strncpy((kal_int8*)buffer, (const kal_int8*)srv_fmgr_drv_get_path_by_type(SRV_FMGR_DRV_CARD_TYPE), SRV_FMGR_PATH_MAX_LEN);
		}
		else
		{
			VFX_ASSERT(0);
		}

		VfxWString text;
		while (index < g_def_folder_table_size)
		{
		    buffer[drv_len*ENCODING_LENGTH] = 0;
            buffer[drv_len*ENCODING_LENGTH+1] = 0;
            
			app_ucs2_strcat((kal_int8*)buffer, (const kal_int8*)g_def_folder_table[index].path);
			
			fs_ret = srv_fmgr_fs_path_exist((const WCHAR*)buffer);
			if (fs_ret == 0)
			{
				fs_ret = srv_fmgr_async_get_folder_size((const WCHAR*)buffer, SRV_FMGR_ASYNC_FLAG_NEED_PROGRESS, vapp_fmgr_async_get_folder_size_result_proc, m_instance->getObjHandle());
				if (fs_ret > 0)
				{
				#ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
					VappFmgrStorageReport *sr = (VappFmgrStorageReport*)m_sr;
					if (sr != NULL)
					{
						sr->m_jobid = fs_ret;
					}
                                #endif
					break;
				}
			}

			/* If the path does not exist or get folder size fail, display 0 immediately then to do next one */
			VappFmgrStorageDetailItem* cell =  (VappFmgrStorageDetailItem*)m_form->getItem(ITEM_DEF_BEGIN+index);
			if (cell != NULL)
			{						
				m_instance->getSizeString(text, 0);
				cell->setSizeString(text);
				cell->setPercentage(0);
			}

			m_cur_index++;
			index = m_cur_index - m_sys_count;				
		}

		if (index == g_def_folder_table_size)
		{
		    m_done = VFX_TRUE;
			fs_ret = VAPP_FMGRI_ERROR_STORAGE_REPORT_COMPLELE;
		}
	}
		
	if (buffer != NULL)
	{
		VFX_FREE_MEM(buffer);
	}
	return fs_ret;
}

VfxS32 VappFmgrStorageDetail::queryUpdate(VfxS32 job_id, VfxU64 folder_size, VfxS32 result)
{
	VfxId id = 0;
	VfxS32 fs_ret = 0;
#ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
	if (m_sr == NULL)
	{
		fs_ret = VAPP_FMGRI_ERROR_PARAM_ERROR;
		return fs_ret;
	}

	VappFmgrStorageReport *sr = (VappFmgrStorageReport*)m_sr;
	if (job_id != sr->m_jobid)
	{
		fs_ret = VAPP_FMGRI_ERROR_STORAGE_REPORT_JOBID_ERROR;
		return fs_ret;	
	}
	else
	{
        if (sr->m_cancel)
		{
			sr->m_cancel = VFX_FALSE;
			sr->m_jobid = 0;
			if (sr->m_close == VFX_TRUE)
			{
				fs_ret = FS_ABORTED_ERROR;
			}
			else
			{
				fs_ret = VAPP_FMGRI_ERROR_STORAGE_REPORT_SWITCH;
			}
			return fs_ret;
		}
		else
		{
			fs_ret = VAPP_FMGRI_ERROR_STORAGE_REPORT_GO_ON;
		}

		if (m_cur_index < m_sys_count)
		{
			/* get folder path from system folder */
			id = ITEM_SYS_BEGIN + m_cur_index;
		}
		else
		{
			id = ITEM_DEF_BEGIN + (m_cur_index - m_sys_count);
		}

        if (result >= 0)
        {
            /* Only update when result >= 0 */
    		VappFmgrStorageDetailItem* cell =  (VappFmgrStorageDetailItem*)m_form->getItem(id);
    		if (cell != NULL)
    		{
    			VfxWString text;
    			m_instance->getSizeString(text, folder_size);
    			cell->setSizeString(text);
    			VfxFloat percentage = 0;
    			if (m_total_size > 0)
    			{
    				percentage = (VfxFloat)folder_size/(VfxFloat)m_total_size;
    			}
    			cell->setPercentage(percentage);
    		}
        }
	}
#else
    if (m_cur_index < m_sys_count)
	{
		/* get folder path from system folder */
		id = ITEM_SYS_BEGIN + m_cur_index;
	}
	else
	{
		id = ITEM_DEF_BEGIN + (m_cur_index - m_sys_count);
	}

    if (result >= 0)
    {
        /* Only update when result >= 0 */
		VappFmgrStorageDetailItem* cell =  (VappFmgrStorageDetailItem*)m_form->getItem(id);
		if (cell != NULL)
		{
			VfxWString text;
			m_instance->getSizeString(text, folder_size);
			cell->setSizeString(text);
			VfxFloat percentage = 0;
			if (m_total_size > 0)
			{
				percentage = (VfxFloat)folder_size/(VfxFloat)m_total_size;
			}
			cell->setPercentage(percentage);
		}
    }
#endif
	return fs_ret;
}

VfxS32 VappFmgrStorageDetail::queryNext()
{
	VfxS8 index = 0;
	VfxS8 *buffer = NULL;
	VfxS32 fs_ret = 0, drv_len = 3;
	
	if (m_cur_index < m_sys_count)
	{
		/* get folder path from system folder */
	}
	else
	{
		/* get folder path from default folder */
		index = m_cur_index - m_sys_count;
		
		VFX_ALLOC_MEM(buffer, VAPP_FMGR_FILE_PATH_LEN, this);
		if (m_pageId == VAPP_FMGR_DRAW_STORAGE_DETAIL_PHONE_PAGE)
		{			
			app_ucs2_strncpy((kal_int8*)buffer, (const kal_int8*)srv_fmgr_drv_get_path_by_type(SRV_FMGR_DRV_PHONE_TYPE), SRV_FMGR_PATH_MAX_LEN);			
		}
		else if (m_pageId == VAPP_FMGR_DRAW_STORAGE_DETAIL_MEM_PAGE)
		{
			app_ucs2_strncpy((kal_int8*)buffer, (const kal_int8*)srv_fmgr_drv_get_path_by_type(SRV_FMGR_DRV_CARD_TYPE), SRV_FMGR_PATH_MAX_LEN);
		}
		else
		{
			VFX_ASSERT(0);
		}

		VfxWString text;
		while (index < g_def_folder_table_size)
		{
		    buffer[drv_len*ENCODING_LENGTH] = 0;
            buffer[drv_len*ENCODING_LENGTH+1] = 0;
			app_ucs2_strcat((kal_int8*)buffer, (const kal_int8*)g_def_folder_table[index].path);
			
			fs_ret = srv_fmgr_fs_path_exist((const WCHAR*)buffer);
			if (fs_ret == 0)
			{
				fs_ret = srv_fmgr_async_get_folder_size((const WCHAR*)buffer, SRV_FMGR_ASYNC_FLAG_NEED_PROGRESS, vapp_fmgr_async_get_folder_size_result_proc, m_instance->getObjHandle());
				if (fs_ret > 0)
				{
				#ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
					VappFmgrStorageReport *sr = (VappFmgrStorageReport*)m_sr;
					if (sr != NULL)
					{
						sr->m_jobid = fs_ret;
					}
                #endif
					break;
				}
			}

			/* If the path does not exist or get folder size fail, display 0 immediately then to do next one */
			VappFmgrStorageDetailItem* cell =  (VappFmgrStorageDetailItem*)m_form->getItem(ITEM_DEF_BEGIN+index);
			if (cell != NULL)
			{						
				m_instance->getSizeString(text, 0);
				cell->setSizeString(text);
				cell->setPercentage(0);
			}

			m_cur_index++;
			index = m_cur_index - m_sys_count;				
		}

		if (index == g_def_folder_table_size)
		{
		    m_done = VFX_TRUE;
			fs_ret = VAPP_FMGRI_ERROR_STORAGE_REPORT_COMPLELE;
		}
	}

	if (buffer != NULL)
	{
		VFX_FREE_MEM(buffer);
	}
	return fs_ret;
}

void VappFmgrStorageDetail::prepareNext()
{
#ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
	if (m_sr != NULL)
	{
		VappFmgrStorageReport *sr = (VappFmgrStorageReport*)m_sr;
		sr->m_jobid = 0;
	}
#endif
	m_cur_index++;
}
#endif

VfxS32 VappFmgrStorageDetail::getErrorCode()
{
    return m_error_code;
}

VfxBool VappFmgrStorageDetail::getDone()
{
    return m_done;
}

void VappFmgrStorageDetail::drawInit(VfxId tab_id)
{			
	/* Get totoal and free size */
	if (tab_id > 0)
	{
		VfxU8 drv_type = tab_id-1;
		
		if (m_form == NULL)
		{
			VFX_OBJ_CREATE(m_form, VcpForm, this);
		}

        if (drv_type == SRV_FMGR_DRV_CARD_TYPE)
        {
            VfxS32 fs_ret = FS_GetDevStatus(srv_fmgr_drv_get_letter_by_type((srv_fmgr_drv_type_enum)drv_type), FS_MOUNT_STATE_ENUM);
    		if (fs_ret != FS_NO_ERROR)
            {
                /* Memory card is not ready */
                m_form->setHidden(VFX_TRUE);
            }
        }
		m_form->setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
	
		/* Capacity */		
		VFX_OBJ_CREATE(m_capacity, VappFmgrStorageCapacityItem, m_form);		
		m_capacity->setUsedSize(0);
		m_form->addItem(m_capacity, ITEM_CAPACITY);		

		/* Seperate line */
		m_form->insertSeparator(ITEM_CAPACITY);
		
		/* Total */
		VFX_OBJ_CREATE(m_total, VappFmgrStorageDetailItem, m_form);
		m_total->setCategory(STR_ID_VAPP_FMGR_TOTAL);
		VfxWString text;
		m_instance->getSizeString(text, 0);
		m_total->setSizeString(text.getBuf());
		m_form->addItem(m_total, ITEM_TOTAL);

		/* Seperate line */
		m_form->insertSeparator(ITEM_TOTAL);
		
		/* Free */
		VFX_OBJ_CREATE(m_free, VappFmgrStorageDetailItem, m_form);
		m_free->setCategory(STR_ID_VAPP_FMGR_FREE);
		m_instance->getSizeString(text, 0);
		m_free->setSizeString(text.getBuf());		
		m_free->setPercentage(0);
		m_form->addItem(m_free, ITEM_FREE);

		/* Seperate line */
		m_form->insertSeparator(ITEM_FREE);
#ifndef __MMI_SLIM_FILE_MANAGER__
		/* System category */
		/* Default category */
		drawDefCategory();		
#endif
	}
}

void VappFmgrStorageDetail::drawSysCategory()
{
}

#ifndef __MMI_SLIM_FILE_MANAGER__
void VappFmgrStorageDetail::drawDefCategory()
{
	VfxU8 def_index = 0;
	VfxWString loading(STR_GLOBAL_LOADING);
	VfxWString size = VFX_WSTR("0B");
	
	/* item 1 */
	for (def_index = 0; def_index < g_def_folder_table_size; def_index++)
	{
		if (m_def_contents[def_index] == NULL)
		{
			VFX_OBJ_CREATE(m_def_contents[def_index], VappFmgrStorageDetailItem, m_form);
		}
		
		m_def_contents[def_index]->setCategory(g_def_folder_table[def_index].str_id);
		m_def_contents[def_index]->setSizeString(size);
		m_def_contents[def_index]->setPercentage(loading);
		m_form->addItem(m_def_contents[def_index], ITEM_DEF_BEGIN + def_index);

		/* Seperate line */
		m_form->insertSeparator(ITEM_DEF_BEGIN + def_index);
	}	
}
#endif

void VappFmgrStorageDetail::drawStorageDetail()
{
    VfxU32 drv_type = SRV_FMGR_DRV_CARD_TYPE;   
    #ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
	if (NULL == m_sr)
        return ;
	
		VappFmgrStorageReport *sr = (VappFmgrStorageReport*)m_sr;
    drv_type = sr->getCurrTab() - 1;
    #endif
    
		VfxU8 drv_letter = srv_fmgr_drv_get_letter_by_type((srv_fmgr_drv_type_enum)drv_type);
		VfxU64 disk_total_space = 0, disk_free_space = 0;	
		VfxFloat percentage = 0;
		
	VfxS32 fs_ret = FS_GetDevStatus(drv_letter, FS_MOUNT_STATE_ENUM);
		if (fs_ret != FS_NO_ERROR || m_error_code != FS_NO_ERROR)
		{
			/* drive is not prepared */
            if (m_error_code == FS_NO_ERROR)
            {
                /* Keep the status for tab switch */
                m_error_code = fs_ret;
            }

            fs_ret = m_error_code;
		    drawLoadingPage(VFX_FALSE, fs_ret);

			if (m_form != NULL)
			{
				m_form->setHidden(VFX_TRUE);
			}
		}
		else
		{	
			/* Get storage information */
			if (m_total_size == 0)
			{
				fs_ret = srv_fmgr_drv_get_size(drv_letter, &disk_total_space, &disk_free_space);

				m_total_size = disk_total_space;
				m_free_size = disk_free_space;
			}
			/* Set capactiy bar */
			if (m_total_size == 0 || m_total_size < m_free_size)
			{
				percentage = 0;
			}
			else
			{
				percentage = (VfxFloat)(m_total_size - m_free_size)/(VfxFloat)m_total_size;
			}
			m_capacity->setUsedSize(percentage);

			/* Set total */
			VfxWString text;
			m_instance->getSizeString(text, m_total_size);
			m_total->setSizeString(text.getBuf());

			/* Set free */
			m_instance->getSizeString(text, m_free_size);
			m_free->setSizeString(text.getBuf());
			if (m_total_size == 0)
			{
				percentage = 0;
			}
			else
			{
				percentage = (VfxFloat)m_free_size/(VfxFloat)m_total_size;
			}
			m_free->setPercentage(percentage);
			
			if (m_form != NULL)
			{
				m_form->setHidden(VFX_FALSE);
			}			
        #if !defined( __MMI_SLIM_FILE_MANAGER__ ) && !defined(__VAPP_FMGR_NO_PUBLIC_DRIVE__)
			if (sr->m_jobid> 0)
			{
				/* cancel it */
				if (srv_fmgr_async_abort(sr->m_jobid, MMI_FALSE) == VFX_TRUE)
				{
					sr->m_cancel = VFX_TRUE;
				}
			}
			else
			{
				if (m_cur_index == 0)
				{
					fs_ret = queryFirst();
				}
				else
				{
					fs_ret = queryNext();
				}
			}
        #endif
		}
	}
#endif // __COSMOS_SLIM_FMGR_MT6260__

#ifndef __VAPP_FMGR_NO_PUBLIC_DRIVE__
VFX_IMPLEMENT_CLASS("VappFmgrStorageReport", VappFmgrStorageReport, VcpTabCtrlPage);

VappFmgrStorageReport::VappFmgrStorageReport() :
    m_default_tab((SRV_FMGR_DRV_PHONE_TYPE+1)),
	m_close(VFX_FALSE),
	m_cancel(VFX_FALSE), 
	m_jobid(0), 
	m_instance(NULL),
    m_phone_page(NULL),
    m_mem_page(NULL)
{
}
VappFmgrStorageReport::VappFmgrStorageReport(const VfxId default_tab, VappFmgrInstance *instance) :
    m_default_tab(default_tab),
	m_close(VFX_FALSE),
	m_cancel(VFX_FALSE), 
	m_jobid(0), 
	m_instance(instance),
    m_phone_page(NULL),
    m_mem_page(NULL)
{
}
    

void VappFmgrStorageReport::onInit()
{
    VcpTabCtrlPage::onInit(); // call base class

    m_entered = VFX_FALSE;

	VfxU16 icon_id = IMG_NONE;
	VappFmgrMainScr *obj = (VappFmgrMainScr*)getMainScr();
	VappFmgrInstance *instance = obj->getCallerInstance();
	VappFmgrFSData *fsdata = instance->getFSDataObj();
	VfxS32 i = 0, drv_count = 0, fs_ret = 0;
	vapp_fmgr_drive_info_struct drv_info;
	VfxS8 drv_name[40];
	
	if (fsdata != NULL)
	{
		/* get drive count to add tab */
		drv_count = fsdata->getDrvCount(instance);

		for (i = 0; i < drv_count; i++)
		{
			fs_ret = fsdata->getDrvInfo(instance, i, &drv_info);
			if (fs_ret >= 0
                && (drv_info.drv_type == SRV_FMGR_DRV_PHONE_TYPE || drv_info.drv_type == SRV_FMGR_DRV_CARD_TYPE))
			{
				if (drv_info.drv_type < SRV_FMGR_DRV_CARD_TYPE)
			    {
			        icon_id = IMG_ID_VAPP_FMGR_TAB_PHONE_ICN;
			    }
			    else
			    {
			        icon_id = IMG_ID_VAPP_FMGR_TAB_CARD_ICN;
			    }

				VfxWString text(STR_GLOBAL_PHONE);
                if (i != 0)
                {
    				fs_ret = 0;
    				//fs_ret = srv_fmgri_drv_get_volume_name(drv_info.drv_path[0], (WCHAR*)drv_name, 40);
    				fs_ret = srv_fmgr_drv_get_name(drv_info.drv_path[0], (WCHAR*)drv_name, 40);
                    if (fs_ret >= 0)
                    {
                        text.loadFromMem((VfxWChar*)drv_name);
                    }
                    else
                    {
                        text.loadFromRes(STR_GLOBAL_MEMORY_CARD);
                    }
                }
				
				addTab((drv_info.drv_type+1), text, VcpStateImage(icon_id));

                if ((drv_info.drv_type+1) == m_default_tab)
                {
                    setCurrTab(m_default_tab);
                }
			}
		}
		
	}
}

void VappFmgrStorageReport::onEntered()
{
    VappFmgrPage* page = (VappFmgrPage*)getTabPage(getCurrTab());
    if (page != NULL && m_instance != NULL && !m_entered)
    {
        page->updatePage(m_instance, page->getPageId(), -1, VFX_TRUE);
    }
    
    m_entered = VFX_TRUE;
}

void VappFmgrStorageReport::onDeinit()
{
    m_instance = NULL;
    
	VcpTabCtrlPage::onDeinit();
}

void VappFmgrStorageReport::onExit(VfxBool isBackward)
{
	if (m_jobid > 0)
	{
		/* cancel it */
		if (srv_fmgr_async_abort(m_jobid, MMI_FALSE) == VFX_TRUE)
		{
			m_cancel = VFX_TRUE;
		}
	}
	m_close = VFX_TRUE;
}

VfxPage* VappFmgrStorageReport::onCreateTabPage(VfxId tabId)
{
	if (tabId == (SRV_FMGR_DRV_PHONE_TYPE+1))
	{
		if (m_phone_page == NULL)
		{
			VFX_OBJ_CREATE_EX(m_phone_page, VappFmgrStorageDetail, this, (VappFmgrPage::VAPP_FMGR_DRAW_STORAGE_DETAIL_PHONE_PAGE, m_instance));
		}

		m_phone_page->drawInit(tabId);		
		if (m_instance != NULL)
		{
			m_phone_page->m_signalGetOptMenuItem.connect(m_instance, &VappFmgrMain::getOptionItem);
            m_phone_page->updatePageOptionMenu(m_instance, VappFmgrStorageDetail::PHONE_STYLE_ID);
		}
		m_phone_page->m_sr = (VfxObject*)this;
		return m_phone_page;
	}
	else if (tabId == (SRV_FMGR_DRV_CARD_TYPE+1))
	{
		if (m_mem_page == NULL)
		{
			VFX_OBJ_CREATE_EX(m_mem_page, VappFmgrStorageDetail, this, (VappFmgrPage::VAPP_FMGR_DRAW_STORAGE_DETAIL_MEM_PAGE, m_instance));
		}

		m_mem_page->drawInit(tabId);		
		if (m_instance != NULL)
		{
			m_mem_page->m_signalGetOptMenuItem.connect(m_instance, &VappFmgrMain::getOptionItem);
            m_mem_page->updatePageOptionMenu(m_instance, VappFmgrStorageDetail::CARD_STYLE_ID);
		}
		m_mem_page->m_sr = (VfxObject*)this;
		return m_mem_page;
	}
	return NULL;
}

void VappFmgrStorageReport::setInstance(VappFmgrInstance *instance)
{
	m_instance = instance;
	if (m_phone_page != NULL)
	{
		m_phone_page->setInstance(m_instance);
        m_phone_page->m_signalGetOptMenuItem.disconnect(m_instance, &VappFmgrMain::getOptionItem);
        m_phone_page->m_signalGetOptMenuItem.connect(m_instance, &VappFmgrMain::getOptionItem);
	}

	if (m_mem_page != NULL)
	{
		m_mem_page->setInstance(m_instance);
        m_mem_page->m_signalGetOptMenuItem.disconnect(m_instance, &VappFmgrMain::getOptionItem);
        m_mem_page->m_signalGetOptMenuItem.connect(m_instance, &VappFmgrMain::getOptionItem);
	}

    VappFmgrPage* page = (VappFmgrPage*)getTabPage(getCurrTab());
    if (page != NULL && page->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrPage)))
    {
        instance->setPageObj((VfxPage*)page);
    }
}

VfxBool VappFmgrStorageReport::isEntered(void)
{
    return m_entered;
}
#endif

VFX_IMPLEMENT_CLASS("VappFmgrGeneralOperation", VappFmgrGeneralOperation, VfxControl);

void VappFmgrGeneralOperation::onInit()
{
	VfxControl::onInit();

	m_caller_instance_id = 0;
	m_caller_group_id = GRP_ID_INVALID;
	m_cui_id = GRP_ID_INVALID;
    
	m_can_cancel = VFX_FALSE;
	m_allow_popup = VFX_TRUE;
	m_async_fs_aborting = VFX_FALSE;
	m_ongoing = VFX_FALSE;
    m_clicked = VFX_FALSE;
    m_waitconfirm = VFX_FALSE;
	m_action = VAPP_FMGR_ACTION_NONE;
	m_job_id = 0;
	m_filename = NULL;
	m_ext = NULL;
	m_processing = NULL;
	m_file_info = NULL;
	m_src_drv = -1;
	m_dst_drv = -1;
	m_progressed = 0;
	m_max_count = 0;
	m_del_filter = NULL;

	m_filename_input = NULL;
	m_pop = NULL;
    m_confirm = NULL;
    m_opt_menu = NULL;
    
	m_error_code = 0;
	m_pressed_cancel = VFX_FALSE;
}

void VappFmgrGeneralOperation::onDeinit()
{
    if (m_job_id >= 0)
    {
        if (srv_fmgr_async_abort(m_job_id, MMI_FALSE) == MMI_TRUE)
        {
            m_async_fs_aborting = MMI_TRUE;
        }
    }
    
	m_can_cancel = VFX_FALSE;
	m_action = VAPP_FMGR_ACTION_NONE;
	m_dst_drv = SRV_FMGR_DRV_PHONE_TYPE;
	if (m_processing != NULL)
	{
		VFX_OBJ_CLOSE(m_processing);
		m_processing = NULL;
	}

	if (m_filename != NULL)
	{
		VFX_FREE_MEM(m_filename);
	}
	
	if (m_filename_input != NULL)
	{
		VFX_OBJ_CLOSE(m_filename_input);
		m_filename_input = NULL;
	}

    if (m_file_info != NULL)
    {
        VFX_FREE_MEM(m_file_info);
    }

    if (m_confirm != NULL)
    {
        VFX_OBJ_CLOSE(m_confirm);
    }
	VfxControl::onDeinit();
}

void VappFmgrGeneralOperation::setCallerInstanceId(VfxU8 instance_id)
{
	m_caller_instance_id = instance_id;
}

void VappFmgrGeneralOperation::setCallerGroupId(mmi_id group_id)
{
	m_caller_group_id = group_id;
}

VfxBool VappFmgrGeneralOperation::getOngoing(void) const
{
	return m_ongoing;
}

void VappFmgrGeneralOperation::resetOngoing(void)
{
	m_ongoing = VFX_FALSE;
}

void VappFmgrGeneralOperation::setCanCancel(VfxBool can)
{
	m_can_cancel = can;
}

VfxBool VappFmgrGeneralOperation::getCanCancel(void)
{
	return m_can_cancel;
}

void VappFmgrGeneralOperation::setAllowPopup(VfxBool allow)
{
	m_allow_popup = allow;
}

VfxBool VappFmgrGeneralOperation::getAllowPopup(void)
{
	return m_allow_popup;
}

void VappFmgrGeneralOperation::setAborting(VfxBool aborting)
{
	m_async_fs_aborting = aborting;
}

VfxBool VappFmgrGeneralOperation::getAborting(void)
{
	return m_async_fs_aborting;
}

void VappFmgrGeneralOperation::setAction(VfxU32 action)
{
	m_action = action;
}

VfxU32 VappFmgrGeneralOperation::getAction(void) const
{
	return m_action;
}

void VappFmgrGeneralOperation::setJobId(VfxS32 job_id)
{
	m_job_id = job_id;
}

VfxS32 VappFmgrGeneralOperation::getJobId(void)
{
	return m_job_id;
}

void VappFmgrGeneralOperation::setProgressed(VfxS32 progressed)
{
	m_progressed = progressed;
}

VfxS32 VappFmgrGeneralOperation::getProgressed(void)
{
	return m_progressed;
}
		
void VappFmgrGeneralOperation::setMaxCount(VfxS32 max_count, VfxBool disp_only)
{
	m_disp_count = max_count;
	if (!disp_only)
	{
		m_max_count = max_count;
	}
}

VfxS32 VappFmgrGeneralOperation::getMaxCount(void)
{
	return m_max_count;
}

VfxBool VappFmgrGeneralOperation::isRemainder(VfxS32 count)
{
	VAPP_FMGR_TRACE2(TRC_VAPP_FMGR_OP_ISREMAINDER, "[VAPPFMGR]isRemainder processed %d, total %d", count, m_disp_count);
	return (count == m_disp_count)? VFX_FALSE : VFX_TRUE;
}

void VappFmgrGeneralOperation::setSrcPath(VfxWString &src)
{
	m_src_path = src;
}

void VappFmgrGeneralOperation::setSrcPath(VfxS8 *src)
{
	m_src_path.loadFromMem((VfxWChar*)src);
}

VfxWString& VappFmgrGeneralOperation::getSrcPath(void)
{
	return m_src_path;
}

void VappFmgrGeneralOperation::setFilename(VfxS8 *filename)
{
	if (filename != NULL)
	{
		if (m_filename == NULL)
		{
			VFX_ALLOC_MEM(m_filename, VENUS_FMGR_FILENAME_BUF_LEN, this);
			memset(m_filename, 0, VENUS_FMGR_FILENAME_BUF_LEN);
		}
		app_ucs2_strncpy(m_filename, filename, SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
	}

    if (m_action == VAPP_FMGR_ACTION_RENAME_FILE)
    {
    	/* To cut extension name if it exists and save to m_ext */
    	#ifdef __MMI_SHOW_FILE_EXT__
        m_ext = (VfxS8*)srv_fmgr_path_get_extension_ptr((WCHAR*)m_filename);
        
        if (m_ext != NULL)
        {
            *(m_ext - 2) = 0;		        
        }
        else
        {
            m_ext = NULL;
        }
    	#endif /* __MMI_SHOW_FILE_EXT__ */
    }
}

void VappFmgrGeneralOperation::setDstPath(VfxS8 *dst)
{
	srv_fmgr_drv_type_enum drv_type;
	
	m_dst_path.loadFromMem((VfxWChar*)dst);

	drv_type = (srv_fmgr_drv_type_enum)srv_fmgr_drv_get_type((VfxU8)m_dst_path.getBuf()[0]);
	setDstDrv(drv_type);
}

void VappFmgrGeneralOperation::setDstPath(VfxWString &dst)
{
	srv_fmgr_drv_type_enum drv_type;
	
	m_dst_path.loadFromMem(dst.getBuf());

	drv_type = (srv_fmgr_drv_type_enum)srv_fmgr_drv_get_type((VfxU8)m_dst_path.getBuf()[0]);
	setDstDrv(drv_type);
}

VfxWString& VappFmgrGeneralOperation::getDstPath(void) 
{
	return m_dst_path;
}

void VappFmgrGeneralOperation::setSrcDrv(srv_fmgr_drv_type_enum src_drv)
{
	m_src_drv = src_drv;
}

void VappFmgrGeneralOperation::setDstDrv(srv_fmgr_drv_type_enum dst_drv, VfxBool to_default)
{
	m_dst_drv = dst_drv;
}

VfxS32 VappFmgrGeneralOperation::getDstDrv(void)
{
	return m_dst_drv;
}

void VappFmgrGeneralOperation::setSelectedPath(VfxS8* path)
{
	if (path != NULL)
	{
		m_selected_path.loadFromMem((VfxWChar*)path);
	}
}

VfxWString VappFmgrGeneralOperation::getSelectedPath()
{
	return m_selected_path;
}

void VappFmgrGeneralOperation::setSrcFileInfo(srv_fmgr_fileinfo_struct* file_info)
{
    if (m_file_info == NULL)
    {
        VFX_ALLOC_MEM(m_file_info, sizeof(srv_fmgr_fileinfo_struct), this);
    }

    memset(m_file_info, 0, sizeof(srv_fmgr_fileinfo_struct));
    memcpy(m_file_info, file_info, sizeof(srv_fmgr_fileinfo_struct));
}

srv_fmgr_fileinfo_struct* VappFmgrGeneralOperation::getSrcFileInfo(void)
{
	return m_file_info;
}

void VappFmgrGeneralOperation::setDeleteFilterType(FMGR_FILTER* filter)
{
	m_del_filter = filter;
}

FMGR_FILTER* VappFmgrGeneralOperation::getDeleteFilterType(void)
{
	return m_del_filter;
}

void VappFmgrGeneralOperation::setFileListHdle(SRV_FMGR_FILELIST_HANDLE filelist_hdl)
{
	m_filelist_hdl = filelist_hdl;
}

VfxS32 VappFmgrGeneralOperation::run()
{
    VfxS32 action = getAction();
    VfxS32 fs_ret = FS_NO_ERROR;

    switch (action)
    {
        case VAPP_FMGR_ACTION_DELETE_SINGLE:
        case VAPP_FMGR_ACTION_DELETE_FOLDER:
        {
            fs_ret = actionDelete();
        }
        break;
        case VAPP_FMGR_ACTION_MARK_DELETE:
        {
            fs_ret = actionMultiSelectDelete();
        }
        break;
        case VAPP_FMGR_ACTION_COPY:
        {
            fs_ret = actionCopy();
        }
        break;
        case VAPP_FMGR_ACTION_MARK_COPY:
        {
            fs_ret = actionCopy();
        }
        break;
        case VAPP_FMGR_ACTION_MOVE:
        {
            fs_ret = actionMove();
        }
        break;
        case VAPP_FMGR_ACTION_MARK_MOVE:
        {
            fs_ret = actionMove();
        }
        break;
        case VAPP_FMGR_ACTION_FORMAT:
        {
            fs_ret = actionFormat();
        }
        break;
    #if defined( __FS_SORT_SUPPORT__) && !defined(__COSMOS_SLIM_FMGR_MT6260__)

        case VAPP_FMGR_ACTION_SORT:
        {
            fs_ret = actionSort();
        }
        break;
    #endif // #if defined( __FS_SORT_SUPPORT__) && !defined(__COSMOS_SLIM_FMGR_MT6260__)
        case VAPP_FMGR_ACTION_CREATE_FOLDER:
        {
            fs_ret = actionCreateFolder();
        }
        break;
        case VAPP_FMGR_ACTION_SHARE_SINGLE:
        {
            // for modification on UE enhancement.
            VfxS32 shareItemsNum = 0;
        #ifdef __MMI_EMAIL__
            ++shareItemsNum;
        #endif  // __MMI_EMAIL__

        #ifdef __MMI_MMS_2__
            #ifndef __MMI_MESSAGE_SLIM__
                ++shareItemsNum;
            #else
                if (srv_fmgr_types_find_group_by_filename_str(m_src_path.getBuf()) != FMGR_GROUP_VIDEO)
                {
                    ++shareItemsNum;
                }
            #endif //__MMI_MESSAGE_SLIM__
        #endif //__MMI_MMS_2__

            if (shareItemsNum > 0)
            {
                fs_ret = actionShareSingle();
            }
            else
            {
                onClickToShareAsBT();
            }
            break;
        }

        case VAPP_FMGR_ACTION_RENAME_FILE:
        case VAPP_FMGR_ACTION_RENAME_FOLDER:
        {
            fs_ret = actionRename();
        }
        break;
    #ifndef __MMI_SLIM_FILE_MANAGER__
        case VAPP_FMGR_ACTION_RENAME_DRIVE:
        {
            fs_ret = actionRenameDrive();
        }
        break;
    #endif //__MMI_SLIM_FILE_MANAGER__
        default:
            VFX_ASSERT(0);
            break;
    }

    return fs_ret;
}

void VappFmgrGeneralOperation::onClickToDelete(void)
{
	VfxS32 fs_ret = FS_NO_ERROR;
    mmi_proc_func callback;

	do {
		if (m_src_path.isEmpty() || m_src_path.isNull())
		{
			fs_ret = FS_PARAM_ERROR;
			break;			
		}

		if (m_action == VAPP_FMGR_ACTION_DELETE_FOLDER ||
			m_action == VAPP_FMGR_ACTION_DELETE_SINGLE)
		{
			callback = vapp_fmgr_action_single_result_proc;
	}
	else
	{
            callback = vapp_fmgr_action_multiple_result_proc;
}
		m_ongoing = VFX_TRUE;
		fs_ret = srv_fmgr_async_delete((WCHAR*)getSrcPath().getBuf(),
								0,
								callback,
								getObjHandle());
	} while(0);
	
	if (fs_ret >= 0)
	{
		setJobId(fs_ret);
		showProcessing();
	}
	else
	{
		showActionResult(srv_fmgr_fs_error_get_string(fs_ret), VFX_FALSE, fs_ret, VFX_FALSE);
	}
}

void VappFmgrGeneralOperation::onClickToFormat(void)
{
	VfxS32 fs_ret = FS_NO_ERROR;

	do {
		VfxU8 drv_letter = 0;
		if (m_src_drv >= 0)
		{
			drv_letter = srv_fmgr_drv_get_letter_by_type((srv_fmgr_drv_type_enum)m_src_drv);
		}
		else if (!m_src_path.isNull() && !m_src_path.isEmpty())
		{
			drv_letter = (VfxU8)m_src_path.getBuf()[0];
		}
		else
		{
			fs_ret = FS_PARAM_ERROR;
			break;
		}
		
		m_ongoing = VFX_TRUE;
		fs_ret = srv_fmgr_async_format(drv_letter, 0, vapp_fmgr_action_single_result_proc, getObjHandle());
	} while(0);

	if (fs_ret > 0)
	{
		setJobId(fs_ret);
        showProcessing();
	}
	else
	{
		/* Access Denied */
        showActionResult(srv_fmgr_fs_error_get_string(fs_ret), VFX_FALSE, fs_ret, VFX_FALSE);
	}    	
}

#if defined( __FS_SORT_SUPPORT__) && !defined(__COSMOS_SLIM_FMGR_MT6260__)
void VappFmgrGeneralOperation::onClickToSetSort(VfxId id)
{
	VfxU32 old_sort_option, new_sort_option = FS_NO_SORT;
	
	switch (id)
    {
        case MENU_ID_FMGR_SORT_NAME:
        {
            new_sort_option = FS_SORT_NAME;
            break;
        }
        case MENU_ID_FMGR_SORT_TYPE:
        {
            new_sort_option = FS_SORT_TYPE;            
            break;
        }
        case MENU_ID_FMGR_SORT_TIME:
        {
            new_sort_option = FS_SORT_TIME;            
            break;
        }
        case MENU_ID_FMGR_SORT_SIZE:
        {
            new_sort_option = FS_SORT_SIZE;            
            break;
        }        
        default:
            VFX_ASSERT(0);
            break;
    }

    /* If sort_option is not changed, return */
    old_sort_option = srv_fmgr_sort_get();
    if (old_sort_option == new_sort_option)
    {
        m_error_code = FS_NO_ERROR;
        m_pressed_cancel = VFX_TRUE;
        return;
    }

    srv_fmgr_sort_set(new_sort_option);
    srv_fmgr_filelist_set_setting(m_filelist_hdl,
        m_del_filter,
        new_sort_option);
    
    m_error_code = FS_NO_ERROR;
    m_pressed_cancel = VFX_FALSE;
}
#endif //#if defined( __FS_SORT_SUPPORT__) && !defined(__COSMOS_SLIM_FMGR_MT6260__)

void VappFmgrGeneralOperation::onClickToCreateFolder(const VfxWString &name)
{
	VfxS32 fs_ret = 0;

	do {
		if (name.isEmpty() || name.isNull())
		{
			fs_ret = FS_INVALID_FILENAME;
			break;
		}
		
		VfxS8 *buffer = NULL;
		VFX_ALLOC_MEM(buffer, VAPP_FMGR_FILE_PATH_LEN, this);
		memset(buffer, 0, VAPP_FMGR_FILE_PATH_LEN);
		
		fs_ret = composeFilePath(buffer, VAPP_FMGR_FILE_PATH_LEN, m_src_path, (VfxS8*)name.getBuf(), VFX_TRUE);	
		if (fs_ret < 0)
		{
			VFX_FREE_MEM(buffer);
			break;
		}

		VfxS32 len = app_ucs2_strlen(buffer);
		
		if (buffer[(len-1)*ENCODING_LENGTH] == '\\' &&
			buffer[(len-1)*ENCODING_LENGTH+1] == 0)
		{
			buffer[(len-1)*ENCODING_LENGTH] = 0;
		}
		fs_ret = srv_fmgr_fs_create_folder((WCHAR*) buffer);

		VFX_FREE_MEM(buffer);	    	    
	} while(0);	

	if (fs_ret == 0)
	{
		if (m_caller_group_id > 0)
		{
		    VappFmgrApp* app = (VappFmgrApp*)VfxApp::getObject(m_caller_group_id);
            if (app != NULL && app->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrApp)))
            {
                VappFmgrInstance* instance = (VappFmgrInstance*)app->getInstance();
                if (instance != NULL && instance->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrInstance)))
                {
        			instance->setSearchFilename(m_caller_instance_id, (VfxS8*)name.getBuf());
        			instance->setSearchForNewFolder(m_caller_instance_id, VFX_TRUE);
                }
            }
		}
		m_signalActionRsp.emit(this, FS_NO_ERROR, VFX_FALSE);
	}
	else
	{
		m_signalActionRsp.emit(this, fs_ret, VFX_FALSE);
	}
}

void VappFmgrGeneralOperation::onClickToRename(const VfxWString &name)
{
	VfxS32 fs_ret = 0;

	do {
		if (name.isEmpty() || name.isNull())
		{
			fs_ret = FS_INVALID_FILENAME;
			break;
		}
		
		VfxS8 *buffer = NULL, *src_buffer = NULL;
		VFX_ALLOC_MEM(buffer, VAPP_FMGR_FILE_PATH_LEN, this);
		memset(buffer, 0, VAPP_FMGR_FILE_PATH_LEN);
		VFX_ALLOC_MEM(src_buffer, VAPP_FMGR_FILE_PATH_LEN, this);
		memset(src_buffer, 0, VAPP_FMGR_FILE_PATH_LEN);

		if (m_action == VAPP_FMGR_ACTION_RENAME_FOLDER)
		{
			fs_ret = composeFilePath(buffer, VAPP_FMGR_FILE_PATH_LEN, m_src_path, (VfxS8*)name.getBuf(), VFX_TRUE);
		}
		else
		{
			fs_ret = composeFilePath(buffer, VAPP_FMGR_FILE_PATH_LEN, m_src_path, (VfxS8*)name.getBuf(), VFX_FALSE);			
		}
		if (fs_ret < 0)
		{
			VFX_FREE_MEM(buffer);
			VFX_FREE_MEM(src_buffer);
			break;
		}

		/* add extension name to src filename */
		if (m_action == VAPP_FMGR_ACTION_RENAME_FILE && m_ext != NULL)
		{
			*(m_ext - 2) = '.';
		}
		
		fs_ret = composeFilePath(src_buffer, VAPP_FMGR_FILE_PATH_LEN, m_src_path, (VfxS8*)m_filename, VFX_FALSE);
		if (fs_ret < 0)
		{
			VFX_FREE_MEM(buffer);
			VFX_FREE_MEM(src_buffer);
			break;
		}
		
		VfxS32 len = app_ucs2_strlen(buffer);

		if (m_action == VAPP_FMGR_ACTION_RENAME_FOLDER)
		{
			if (buffer[(len-1)*ENCODING_LENGTH] == '\\' &&
				buffer[(len-1)*ENCODING_LENGTH+1] == 0)
			{
				buffer[(len-1)*ENCODING_LENGTH] = 0;
			}
		}
		else
		{
			if (m_ext != NULL)
			{
				/* add extension name to new filename */
				if (len <= SRV_FMGR_PATH_MAX_LEN - (1 + app_ucs2_strlen(m_ext)))
				{
					app_ucs2_strcat((kal_int8*)buffer, (const kal_int8*)".");
					app_ucs2_strcat((kal_int8*)buffer, (const kal_int8*)m_ext);
				}
			}
		}
		fs_ret = srv_fmgr_fs_rename((const WCHAR*)src_buffer, (WCHAR*) buffer);

		VFX_FREE_MEM(buffer);
		VFX_FREE_MEM(src_buffer);
	} while(0);	

	m_signalActionRsp.emit(this, fs_ret, VFX_FALSE);
}

#ifndef __MMI_SLIM_FILE_MANAGER__
void VappFmgrGeneralOperation::onClickToRenameDrive(const VfxWString &name)
{
	VfxWChar *drv_path = NULL;
	VfxS32 fs_ret = FS_NO_ERROR;
	
	do {
		if (name.isEmpty() || name.isNull())
		{
			fs_ret = FS_INVALID_FILENAME;
			break;
		}
		
		drv_path = (VfxWChar*)srv_fmgr_drv_get_path_by_type((srv_fmgr_drv_type_enum)m_src_drv);

        if (drv_path != NULL)
        {            
            fs_ret = FS_SetVolumeLabel((U16*)drv_path, (U16*)name.getBuf());
        }
		
		
	} while(0);

    m_signalActionRsp.emit(this, fs_ret, VFX_FALSE);
}
#endif // __MMI_SLIM_FILE_MANAGER__

#ifdef __MMI_MMS_2__
void VappFmgrGeneralOperation::onClickToShareAsMMS(void)
{
    m_error_code = FS_NO_ERROR;
    m_pressed_cancel = VFX_FALSE;
    
    VappUcEntryStruct data;
    memset(&data, 0, sizeof(VappUcEntryStruct));

    data.media_num = 1;
    data.file_path = (VfxU8*)m_src_path.getBuf();
    data.info_type = SRV_UC_INFO_TYPE_MMS;
    
    VfxBool result = vappUcAppLauncher(&data);
    m_signalActionRsp.emit(this, m_error_code, m_pressed_cancel);
}
#endif

void VappFmgrGeneralOperation::onClickToShareAsEmail(void)
{
    m_error_code = FS_NO_ERROR;
    m_pressed_cancel = VFX_FALSE;
    
#ifdef __MMI_EMAIL__
    mmi_email_app_send_attch((const char*)m_src_path.getBuf());
    m_signalActionRsp.emit(this, m_error_code, m_pressed_cancel);
#endif
}

void VappFmgrGeneralOperation::onClickToShareAsBT(void)
{
#ifdef __MMI_OPP_SUPPORT__
    m_error_code = FS_NO_ERROR;
    m_pressed_cancel = VFX_FALSE;
    vapp_bt_send_app_info app_info;
    memset(&app_info, 0, sizeof(vapp_bt_send_app_info));
    app_info.group_id = m_caller_group_id;

    VfxWChar* wArray[1];

    wArray[0] = (VfxWChar*)m_src_path.getBuf();
    vapp_bt_send_obj(&app_info, VAPP_BT_SEND_NONE, 1, (WCHAR**)wArray);
    m_signalActionRsp.emit(this, m_error_code, m_pressed_cancel);
#endif    
}

void VappFmgrGeneralOperation::onClickInputButton(VfxObject* sender, VcpInputPopupButtonEnum button_id)
{
	if (m_filename_input != NULL)
	{
		if (button_id == VCP_INPUT_POPUP_BTN_OK)
		{
			VfxS32 fs_ret = m_filename_input->isValidFilePath();			
			if (fs_ret < 0)
			{
				if (fs_ret == FS_FILE_EXISTS && (m_action == VAPP_FMGR_ACTION_RENAME_FILE || m_action == VAPP_FMGR_ACTION_RENAME_FOLDER))
				{
					if (app_ucs2_strncmp((const kal_int8*)m_filename, (const kal_int8*)m_filename_input->getText().getBuf(), (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1)) == 0)
					{
						/* Filename is the original one */
						m_signalActionRsp.emit(this, FS_NO_ERROR, VFX_TRUE);
						return;
					}

                    /* Check if new name and original name are different with some lower or upper case char */
                    VfxS8 *lw_buff_o = NULL, *lw_buff_n = NULL;
                    VFX_ALLOC_MEM(lw_buff_o, VAPP_FMGR_FILE_PATH_LEN, this);
                    memset(lw_buff_o, 0, VAPP_FMGR_FILE_PATH_LEN);
                    app_ucs2_strncpy((kal_int8*)lw_buff_o, (const kal_int8*)m_filename, SRV_FMGR_PATH_MAX_LEN);
                    app_ucs2_strlwr((kal_int8*)lw_buff_o);
                    VFX_ALLOC_MEM(lw_buff_n, VAPP_FMGR_FILE_PATH_LEN, this);
                    memset(lw_buff_n, 0, VAPP_FMGR_FILE_PATH_LEN);
                    app_ucs2_strncpy((kal_int8*)lw_buff_n, (const kal_int8*)m_filename_input->getText().getBuf(), SRV_FMGR_PATH_MAX_LEN);
                    app_ucs2_strlwr((kal_int8*)lw_buff_n);

                    if (app_ucs2_strncmp((const kal_int8*)lw_buff_o, (const kal_int8*)lw_buff_n, (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1)) != 0)
					{
						/* Filename is not the original one */
						m_filename_input->setErrorText(srv_fmgr_fs_error_get_string(fs_ret));
                        VFX_FREE_MEM(lw_buff_o);
                        VFX_FREE_MEM(lw_buff_n);
						return;
					}

                    VFX_FREE_MEM(lw_buff_o);
                    VFX_FREE_MEM(lw_buff_n);
				}
                else
                {
                    m_filename_input->setErrorText(srv_fmgr_fs_error_get_string(fs_ret));
                    return;
                }
			}
            #ifndef __MMI_SLIM_FILE_MANAGER__
            if (m_action == VAPP_FMGR_ACTION_RENAME_DRIVE)
            {
                onClickToRenameDrive(m_filename_input->getText());
            }
            else
            #endif // __MMI_SLIM_FILE_MANAGER__
			{				
				/* Name is valid */
				if (m_action == VAPP_FMGR_ACTION_CREATE_FOLDER)
				{
					onClickToCreateFolder(m_filename_input->getText());
				}
				else if (m_action == VAPP_FMGR_ACTION_RENAME_FILE ||
					     m_action == VAPP_FMGR_ACTION_RENAME_FOLDER)
				{
					onClickToRename(m_filename_input->getText());
				}
			}
		}
		else if (button_id == VCP_INPUT_POPUP_BTN_CANCEL)
		{
			m_signalActionRsp.emit(this, FS_NO_ERROR, VFX_TRUE);
		}
	}
}

void VappFmgrGeneralOperation::onClickButton(VfxObject* obj, VfxId id)
{
	VfxS32 fs_ret = FS_NO_ERROR;

    m_waitconfirm = VFX_FALSE;
    
	switch (id)
	{
		case VCP_CONFIRM_POPUP_BUTTON_YES:            
			break;
		case VCP_CONFIRM_POPUP_BUTTON_NO:
        case VCP_CONFIRM_POPUP_BUTTON_USER_2:
            {
			    m_signalActionRsp.emit(this, fs_ret, VFX_TRUE);
            }
			break;
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
            {
                if (m_action == VAPP_FMGR_ACTION_FORMAT)
    			{
    			    onClickToFormat();                    
    			}
                else if (m_action == VAPP_FMGR_ACTION_DELETE_FOLDER ||
                         m_action == VAPP_FMGR_ACTION_DELETE_SINGLE ||
                         m_action == VAPP_FMGR_ACTION_MARK_DELETE)
    			{
    				onClickToDelete();
    			}
            }
            break;
#if defined( __FS_SORT_SUPPORT__) && !defined(__COSMOS_SLIM_FMGR_MT6260__)

		case MENU_ID_FMGR_SORT_NAME:
		case MENU_ID_FMGR_SORT_TYPE:
		case MENU_ID_FMGR_SORT_TIME:
		case MENU_ID_FMGR_SORT_SIZE:
            {
                if (m_opt_menu != NULL)
                {
                    m_clicked = VFX_TRUE;
                }
			    onClickToSetSort(id);
            }
			break;
#endif // #if defined( __FS_SORT_SUPPORT__) && !defined(__COSMOS_SLIM_FMGR_MT6260__)
	#ifdef __MMI_MMS_2__
        case MENU_ID_FILE_TYPE_SHARE_AS_MMS:
            {
                if (m_opt_menu != NULL)
                {
                    m_clicked = VFX_TRUE;
                }
                onClickToShareAsMMS();
            }
            break;
	#endif
    #ifdef __MMI_EMAIL__
        case MENU_ID_FILE_TYPE_SHARE_AS_EMAIL:
            {
                if (m_opt_menu != NULL)
                {
                    m_clicked = VFX_TRUE;
                }
                onClickToShareAsEmail();
            }
            break;
    #endif
        case MENU_ID_FILE_TYPE_SHARE_AS_BT:
            {
                if (m_opt_menu != NULL)
                {
                    m_clicked = VFX_TRUE;
                }
                onClickToShareAsBT();
            }
            break;
		case MENU_ID_FMGR_CANCEL:
            {
                if (m_opt_menu != NULL)
                {
                    m_clicked = VFX_TRUE;
                }
			    m_signalActionRsp.emit(this, fs_ret, VFX_TRUE);
            }
			break;
        default:
            {
                m_signalActionRsp.emit(this, fs_ret, VFX_TRUE);
            }
            break;
    }
}

void VappFmgrGeneralOperation::onClickProcessingCancel(VfxObject* obj, VfxFloat processing)
{
	if (m_action == VAPP_FMGR_ACTION_NONE ||
		m_async_fs_aborting == VFX_TRUE)
	{
		return;
	}

	VAPP_FMGR_TRACE1(TRC_VAPP_FMGR_OP_CLICKCANCEL, "[VAPPFMGR]click cancel processing job %d", m_job_id);
	srv_fmgr_async_abort(m_job_id, MMI_FALSE);

	m_async_fs_aborting = MMI_TRUE;
}

void VappFmgrGeneralOperation::onPopupStateChange(VfxBasePopup* obj,  VfxBasePopupStateEnum state)
{
    if (obj != m_opt_menu || !m_clicked )
    return;

    if (VFX_BASE_POPUP_AFTER_END_ANIMATION == state)
    {
        if (m_action != VAPP_FMGR_ACTION_SHARE_SINGLE)
        {
	    m_signalActionRsp.emit(this, m_error_code, m_pressed_cancel);
        }
    }
}

VfxBool VappFmgrGeneralOperation::changeErrorStr(VfxS32 error_code)
{
    VfxS8 i = 0;
    VfxBool result = VFX_TRUE;
    
    for (i = 0; i < a_known_fs_size; i++)
    {
        if (error_code == a_known_fs[i])
        {
            /* Don't change the error string */
            result = VFX_FALSE;
            break;
        }
    }

    return result;
}

VfxS32 VappFmgrGeneralOperation::getErrorStrId(VfxS32 error_code)
{
    if (error_code >= 0)
    {
        return 0;
    }

    VfxS32 str_id = 0;
    VfxBool result = changeErrorStr(error_code);
    
    if (result)
    {
        /* In copy, move and delete case, we will simplize error string */
        switch(m_action)
        {
            case VAPP_FMGR_ACTION_COPY:
            case VAPP_FMGR_ACTION_MARK_COPY:
                {
                    /* copy fail */
                    str_id = STR_ID_VAPP_FMGR_FAILED_TO_COPY;
                }
                break;
            case VAPP_FMGR_ACTION_MOVE:
            case VAPP_FMGR_ACTION_MARK_MOVE:
                {
                    /* move fail */
                    str_id = STR_ID_VAPP_FMGR_FAILED_TO_MOVE;
                }
                break;
            case VAPP_FMGR_ACTION_DELETE_SINGLE:
            case VAPP_FMGR_ACTION_DELETE_FOLDER:
            case VAPP_FMGR_ACTION_MARK_DELETE:
                {
                    /* delete fail */
                    str_id = STR_ID_VAPP_FMGR_FAILED_TO_DELETE;
                }
                break;
            case VAPP_FMGR_ACTION_FORMAT:
                {
                    /* format fail */
                    str_id = STR_ID_VAPP_FMGR_FAILED_TO_FORMAT;
                }
                break;
            default:
                {
                    str_id = srv_fmgr_fs_error_get_string(error_code);
                }
                break;
        }
    }
    else
    {
        str_id = srv_fmgr_fs_error_get_string(error_code);
    }

    VAPP_FMGR_TRACE3(TRC_VAPP_FMGR_OP_GETERRORSTR, "[VAPPFMGR]OP error string, action %d, change %d, error_code %d", m_action, result, error_code);
    return str_id;
}

void VappFmgrGeneralOperation::showActionResult(VfxS32 str_id, VfxBool succ, VfxS32 error_code, VfxBool pressed_cancel, VfxBool notify_caller)
{
    VAPP_FMGR_TRACE2(TRC_VAPP_FMGR_OP_SHOWRESULT, "[VAPPFMGR]OP show result, err_code %d, press cancel %d", error_code, pressed_cancel);
	if (getAllowPopup() && m_pop == NULL)
	{
		VFX_OBJ_CREATE(m_pop, VcpConfirmPopup, findScreen());
		if (succ)
		{
			m_pop->setInfoType(VCP_POPUP_TYPE_SUCCESS);
		}
		else
		{
			m_pop->setInfoType(VCP_POPUP_TYPE_FAILURE);
		}
		m_pop->setAutoDestory(VFX_TRUE);

        VfxS32 new_str_id = getErrorStrId(error_code);
        if (new_str_id == 0)
        {
            new_str_id = str_id;
        }
		m_pop->setText(new_str_id);
        
		m_pop->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
		m_pop->show(VFX_TRUE);
        
		if (notify_caller)
		{
			m_pop->m_signalButtonClicked.connect(this, &VappFmgrGeneralOperation::onClickConfirmButton);

			m_error_code = error_code;
			m_pressed_cancel = pressed_cancel;
		}
	}
}

void VappFmgrGeneralOperation::onClickConfirmButton(VfxObject * sender,VfxId id)
{
    if (sender != m_pop)
        return ;

    if (VCP_CONFIRM_POPUP_BUTTON_OK == id || VCP_POPUP_BUTTON_NO_PRESSED == id)
    {
        if (m_action != VAPP_FMGR_ACTION_SHARE_SINGLE)
        {
	        m_signalActionRsp.emit(this, m_error_code, m_pressed_cancel);
        }
    }
}

void VappFmgrGeneralOperation::closeProcessing_ex(void)
{
	closeProcessing();
}

void VappFmgrGeneralOperation::updateProcessing_ex(void)
{
	updateProgress();
}

#ifdef __MMI_FMGR_FORMAT_WITH_PHONE_LOCK_CONFIRM__
void VappFmgrGeneralOperation::doFormatEx(VfxBool success)
{
    if (success)
    {
        onClickToFormat();
    }
    else
    {
        m_signalActionRsp.emit(this, FS_NO_ERROR, VFX_TRUE);
    }
}

void VappFmgrGeneralOperation::closeVerifyCui(void)
{
    if (m_cui_id != GRP_ID_INVALID)
    {
        vcui_verify_close(m_cui_id);
        m_cui_id = GRP_ID_INVALID;
    }
}
#endif

VfxS32 VappFmgrGeneralOperation::getErrorCode(void)
{
    VAPP_FMGR_TRACE1(TRC_VAPP_FMGR_OP_GETERRORCODE, "[VAPPFMGR]OP get error code %d", m_error_code);
    return m_error_code;
}

void VappFmgrGeneralOperation::showConfirm(VfxWString &description)
{
	VFX_OBJ_CREATE(m_confirm, VcpConfirmPopup, findScreen());
	m_confirm->setInfoType(VCP_POPUP_TYPE_WARNING);
	m_confirm->setAutoDestory(VFX_TRUE);
	m_confirm->setText(description);
    if (m_action == VAPP_FMGR_ACTION_FORMAT)
    {
    	m_confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
        m_confirm->setCustomButton(STR_ID_VAPP_FMGR_OPTION_FORMAT, STR_GLOBAL_CANCEL,
                                VCP_POPUP_BUTTON_TYPE_WARNING, VCP_POPUP_BUTTON_TYPE_CANCEL);
    }
    else if (m_action == VAPP_FMGR_ACTION_DELETE_SINGLE ||
             m_action == VAPP_FMGR_ACTION_DELETE_FOLDER ||
             m_action == VAPP_FMGR_ACTION_MARK_DELETE)
    {
        m_confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
        m_confirm->setCustomButton(STR_GLOBAL_DELETE, STR_GLOBAL_CANCEL,
                                VCP_POPUP_BUTTON_TYPE_WARNING, VCP_POPUP_BUTTON_TYPE_CANCEL);
    }
    else
    {
        m_confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
    }
	m_confirm->m_signalButtonClicked.connect(this, &VappFmgrGeneralOperation::onClickButton);
	m_confirm->show(VFX_TRUE);

    m_waitconfirm = VFX_TRUE;
}

VfxBool VappFmgrGeneralOperation::getWaitConfirm()
{
    return m_waitconfirm;
}

VfxBool VappFmgrGeneralOperation::isShowProcessing()
{
    VfxBool result = m_processing != NULL? VFX_TRUE : VFX_FALSE;
    VAPP_FMGR_TRACE1(TRC_VAPP_FMGR_OP_ISSHOWPROCESSING, "[VAPPFMGR]OP is show processing %d", result);
    return result;
}

VfxBool VappFmgrGeneralOperation::isShowCommandPopup()
{
    return m_opt_menu != NULL? VFX_TRUE : VFX_FALSE;
}
void VappFmgrGeneralOperation::showProcessing()
{
	if (getAllowPopup() && m_processing == NULL)
	{
		VFX_OBJ_CREATE(m_processing, VcpIndicatorPopup, findScreen());
		

		if (m_max_count > 0)
		{
			if (getCanCancel())
			{
				m_processing->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON);
				m_processing->m_signalCanceled.connect(this, &VappFmgrGeneralOperation::onClickProcessingCancel);
			}
			else
			{
				m_processing->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS);				
			}
			m_processing->setMaxProgress(1.0f);			
			m_processing->setProgress((VfxFloat)m_progressed / m_max_count);
			m_processing->setText(VfxWString().format("%d / %d", m_progressed, m_max_count));
		}
		else
		{
			if (getCanCancel())
			{
				m_processing->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
				m_processing->m_signalCanceled.connect(this, &VappFmgrGeneralOperation::onClickProcessingCancel);
			}
			else
			{
				m_processing->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);				
			}

            VfxWString text;

            switch (m_action)
            {
                case VAPP_FMGR_ACTION_DELETE_FOLDER:
                case VAPP_FMGR_ACTION_DELETE_SINGLE:
                case VAPP_FMGR_ACTION_MARK_DELETE:
                    text.loadFromRes(STR_GLOBAL_DELETING);
                    break;
                case VAPP_FMGR_ACTION_COPY:
                case VAPP_FMGR_ACTION_MARK_COPY:
                    text.loadFromRes(STR_GLOBAL_COPYING);
                    break;
                case VAPP_FMGR_ACTION_MOVE:
                case VAPP_FMGR_ACTION_MARK_MOVE:
                    text.loadFromRes(STR_GLOBAL_MOVING);
                    break;
                case VAPP_FMGR_ACTION_FORMAT:
                    text.loadFromRes(STR_ID_VAPP_FMGR_FORMATING);
                    break;
                default:
                    text = VFX_WSTR("Processing...");
                    break;
                    
            };
			m_processing->setText(text);
		}
		m_processing->setAutoDestory(VFX_FALSE);
		m_processing->show(VFX_TRUE);
	}
}

void VappFmgrGeneralOperation::updateProgress()
{
	if (getAllowPopup() && m_processing != NULL)
	{
        m_progressed++;
		if (m_processing->getInfoType() == VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON ||
			m_processing->getInfoType() == VCP_INDICATOR_POPUP_STYLE_PROGRESS)
		{
			m_processing->setProgress((VfxFloat)m_progressed / m_max_count);
			m_processing->setText(VfxWString().format("%d / %d", m_progressed, m_max_count));
			m_processing->show(VFX_TRUE);
		}
	}
}

void VappFmgrGeneralOperation::closeProcessing(void)
{
	if (m_processing != NULL)
	{
		VFX_OBJ_CLOSE(m_processing);
		m_processing = NULL;
	}
}

VfxS32 VappFmgrGeneralOperation::composeFilePath(VfxS8* buffer, VfxS32 buffer_size, VfxWString& path, VfxS8* file_name, VfxBool add_end_slash)
{
	VfxBool slash = VFX_FALSE;
	VfxS32 fs_ret = FS_NO_ERROR, len = 0, buffer_char_size = buffer_size/ENCODING_LENGTH;
	VfxWChar *temp = NULL;

	buffer_char_size--;  /* reserve for '\0' */
	
	do {
		if (buffer == NULL || buffer_char_size < 1)
		{
			fs_ret = FS_PARAM_ERROR;
			break;
		}

		if (!path.isNull())
		{
			len = path.getLength();

			temp = (VfxWChar*)path.getBuf();

			if (temp[(len-1)] != '\\' &&
				len < buffer_char_size)
			{
				len++;
				slash = VFX_TRUE;
			}
		}
		else
		{
			fs_ret = FS_PATH_NOT_FOUND;
			break;
		}

		if (file_name != NULL)
		{
			len += app_ucs2_strlen((const kal_int8*)file_name);
		}

		if (add_end_slash)
		{
			len++;			
		}
		
		if (len <= buffer_char_size)
		{
			VfxWString tmp_path(temp);
			
			if (slash)
			{
				tmp_path += VFX_WSTR("\\");
			}
			
			tmp_path += VFX_WSTR_MEM((VfxWChar*)file_name);
			if (add_end_slash)
			{
				tmp_path += VFX_WSTR("\\");
			}

			app_ucs2_strncpy((kal_int8*)buffer, (const kal_int8*)tmp_path.getBuf(), buffer_char_size);
		}
		else
		{
			fs_ret = FS_PATH_OVER_LEN_ERROR;
		}
	} while(0);

	return fs_ret;
}

VfxS32 VappFmgrGeneralOperation::composeFilePath(VfxWString &path, VfxS8 *file_name, VfxBool add_slash)
{	
	VfxBool slash = VFX_FALSE;
	VfxS32 len = 0, result = 0;
	VfxS8 *temp = NULL;

	do {
		if (!path.isNull())
		{
			len = path.getLength();

			temp = (VfxS8*)path.getBuf();

			if (temp[(len-1)*ENCODING_LENGTH] != '\\' &&
				temp[(len-1)*ENCODING_LENGTH] != 0 &&
				len < SRV_FMGR_PATH_MAX_LEN)
			{
				len++;
				slash = VFX_TRUE;
			}
		}

		if (file_name != NULL)
		{
			len += app_ucs2_strlen((const kal_int8*)file_name);
		}

		if (add_slash)
		{
			len++;			
		}
		
		if (len <= SRV_FMGR_PATH_MAX_LEN)
		{
			if (slash)
			{
				path += VFX_WSTR("\\");
			}
			
			path += VFX_WSTR_MEM((VfxWChar*)file_name);

			if (add_slash)
			{
				path += VFX_WSTR("\\");
			}
		}
		else
		{
			result = FS_PATH_OVER_LEN_ERROR;
		}
	} while(0);

	return result;
}

VfxS32 VappFmgrGeneralOperation::checkSrcDstPath()
{
	VfxS32 fs_ret = FS_NO_ERROR;
	VfxWString dstPath;
	srv_fmgr_fileinfo_struct *file_info = getSrcFileInfo();
	
	do {
		if (m_src_path.isNull() || m_src_path.isEmpty())
		{
			fs_ret = FS_PARAM_ERROR;
			break;
		}
		
		if (m_dst_path.isNull() || m_dst_path.isEmpty())			 
		{
			fs_ret = FS_PARAM_ERROR;
			break;		
		}		

        if (file_info == NULL || (file_info != NULL && !(file_info->attribute & FS_ATTR_DIR)))
        {
    		dstPath = m_dst_path;
    		fs_ret = composeFilePath(dstPath, (VfxS8*)srv_fmgr_path_get_filename_ptr((WCHAR*)m_src_path.getBuf()), VFX_FALSE);
    		if (fs_ret < 0)
    		{
    			break;
    		}
        }

		if (dstPath == m_src_path)
		{
			fs_ret = FS_FILE_EXISTS;
			break;
		}
	} while(0);

	return fs_ret;
}

VfxS32 VappFmgrGeneralOperation::checkAvailableSpace()
{
	VfxU8 drv_letter = srv_fmgr_drv_get_letter_by_type((srv_fmgr_drv_type_enum)getDstDrv());
	VfxS32 fs_ret = FS_NO_ERROR;
	SRV_FMGR_FILEINFO_HANDLE file_handle;
	
	if (getSrcFileInfo() == NULL)
	{
		srv_fmgr_fileinfo_create((WCHAR *)getSrcPath().getBuf(), &file_handle);
	    fs_ret = srv_fmgr_drv_check_free_size(drv_letter, (U64)srv_fmgr_fileinfo_get_size(file_handle));
	    srv_fmgr_fileinfo_destroy(file_handle);
	}
	else
	{
		fs_ret = srv_fmgr_drv_check_free_size(drv_letter, (U64)getSrcFileInfo()->size);
	}

	return fs_ret;
}

VfxS32 VappFmgrGeneralOperation::actionDelete()
{
	VfxS32 action = getAction();
	VfxWString text;

	if (action == VAPP_FMGR_ACTION_DELETE_SINGLE ||
		action == VAPP_FMGR_ACTION_DELETE_FOLDER)
	{
		text.loadFromRes(STR_ID_VAPP_FMGR_DELETE_THE_FILE_Q);
		text += VFX_WSTR("?");
	}

	if (m_progressed == 0)
	{
		showConfirm(text);
	}
	
	return FS_NO_ERROR;
}

VfxS32 VappFmgrGeneralOperation::actionCopy(void)
{
	VfxS32 fs_ret = FS_NO_ERROR;
	mmi_proc_func callback;
	do {
		
		fs_ret = checkSrcDstPath();
		if (fs_ret < 0)
		{
			break;
		}
		
		fs_ret = checkAvailableSpace();
		if (fs_ret < 0)
		{
			break;
		}
        if (m_action == VAPP_FMGR_ACTION_COPY)
        {
            callback = vapp_fmgr_action_single_result_proc;
        }
        else
        {
            callback = vapp_fmgr_action_multiple_result_proc;
        }
		m_ongoing = VFX_TRUE;
		fs_ret = srv_fmgr_async_copy((WCHAR *)m_src_path.getBuf(), 
                            (WCHAR *) m_dst_path.getBuf(),
                            0,
                            callback,
                            getObjHandle());		
		
	} while(0);

	if (fs_ret >= 0)
	{
		setJobId(fs_ret);
        showProcessing();
	}
	else
	{
		showActionResult(srv_fmgr_fs_error_get_string(fs_ret), VFX_FALSE, fs_ret, VFX_FALSE);
	}
	return fs_ret;
}

VfxS32 VappFmgrGeneralOperation::actionMove(void)
{
	VfxS32 fs_ret = FS_NO_ERROR;
	mmi_proc_func callback;
	do {		
		fs_ret = checkSrcDstPath();
		if (fs_ret < 0)
		{
			break;
		}

		if (m_src_path.getBuf()[0] != srv_fmgr_drv_get_letter_by_type((srv_fmgr_drv_type_enum)getDstDrv()))
		{
			fs_ret = checkAvailableSpace();
			if (fs_ret < 0)
			{
				break;
			}
		}
        if (m_action == VAPP_FMGR_ACTION_MOVE)
        {
            callback = vapp_fmgr_action_single_result_proc;
        }
        else
        {
            callback = vapp_fmgr_action_multiple_result_proc;
        }
		m_ongoing = VFX_TRUE;
		fs_ret = srv_fmgr_async_move((WCHAR *)m_src_path.getBuf(), 
                            (WCHAR *) m_dst_path.getBuf(),
                            0,
                            callback,
                            getObjHandle());		
		
	} while(0);

	if (fs_ret >= 0)
	{
		setJobId(fs_ret);
        showProcessing();
	}
	else
	{
		showActionResult(srv_fmgr_fs_error_get_string(fs_ret), VFX_FALSE, fs_ret, VFX_FALSE);
	}
	return fs_ret;
}

VfxS32 VappFmgrGeneralOperation::actionMultiSelectDelete(void)
{
	VfxWString text;
	
	if (m_progressed == 0)
	{
		text.loadFromRes(STR_ID_VAPP_FMGR_DELETE_SELECT_FILES_Q);
		text += VfxWString().format("(%d)", m_disp_count);
		text += VFX_WSTR("?");
	
		showConfirm(text);
	}
	else
	{
		onClickToDelete();
	}
	
	return FS_NO_ERROR;
}


VfxS32 VappFmgrGeneralOperation::actionFormat(void)
{
	VfxU16 str_id = 0;
	VfxWString str;
#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) || defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_IME_MEMORY_CARD_SUPPORT__) || defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
    srv_fmgr_drv_type_enum drv = (srv_fmgr_drv_type_enum)m_src_drv;
    if (drv == SRV_FMGR_DRV_CARD_TYPE)
    {
        str_id = STR_ID_VAPP_FMGR_FORMAT_REBOOT_HINT;
    }
#else
#if (!defined(APP_STORAGE_IN_SYS_DRV)) && defined(__MMI_EMAIL__)
    str_id = STR_ID_VAPP_FMGR_OPTION_FORMAT;
#else /* (!defined(APP_STORAGE_IN_SYS_DRV)) && defined(__MMI_EMAIL__) */
    str_id = STR_ID_VAPP_FMGR_OPTION_FORMAT;
#endif /* (!defined(APP_STORAGE_IN_SYS_DRV)) && defined(__MMI_EMAIL__) */
#endif
	str.loadFromRes(str_id);
    str += VFX_WSTR("?");

#ifdef __MMI_FMGR_FORMAT_WITH_PHONE_LOCK_CONFIRM__
    m_cui_id = vcui_verify_create(m_caller_group_id, VCUI_VERIFY_TYPE_PHONE_PASSWORD);
    if (m_cui_id != GRP_ID_INVALID)
    {
        vcui_verify_run(m_cui_id);
    }
#else
	showConfirm(str);
#endif		

	return FS_NO_ERROR;
}

#if defined( __FS_SORT_SUPPORT__) && !defined(__COSMOS_SLIM_FMGR_MT6260__)
VfxS32 VappFmgrGeneralOperation::actionSort(void)
{	
	VfxU32 disable_item = 0;
	VfxU8 i = 0;

	VFX_OBJ_CREATE(m_opt_menu, VcpCommandPopup, this);

	m_opt_menu->setText(STR_GLOBAL_SORT);
	
	switch (srv_fmgr_sort_get())
	{
		case FS_SORT_NAME:
			disable_item = MENU_ID_FMGR_SORT_NAME;
			break;
		case FS_SORT_SIZE:
			disable_item = MENU_ID_FMGR_SORT_SIZE;
			break;
		case FS_SORT_TYPE:
			disable_item = MENU_ID_FMGR_SORT_TYPE;
			break;
		case FS_SORT_TIME:
			disable_item = MENU_ID_FMGR_SORT_TIME;
			break;				        
	}

    VfxU16 menu_id = MENU_ID_FMGR_SORT_NAME;
	for (i = 0; i < 4; i++)
	{
	    menu_id = MENU_ID_FMGR_SORT_NAME+i;
		m_opt_menu->addItem(menu_id, GetStringIdOfItem(menu_id), VCP_POPUP_BUTTON_TYPE_NORMAL);
	}

	m_opt_menu->addItem(MENU_ID_FMGR_CANCEL, STR_GLOBAL_CANCEL, VCP_POPUP_BUTTON_TYPE_CANCEL);

	if (disable_item != 0)
	{
		m_opt_menu->disableItem(disable_item);
	}

	m_opt_menu->m_signalButtonClicked.connect(this, &VappFmgrGeneralOperation::onClickButton);
    m_opt_menu->m_signalPopupState.connect(this, &VappFmgrGeneralOperation::onPopupStateChange);
	m_opt_menu->setAutoDestory(VFX_FALSE);
	m_opt_menu->show(VFX_TRUE);

	return FS_NO_ERROR;
}
#endif // #if defined( __FS_SORT_SUPPORT__) && !defined(__COSMOS_SLIM_FMGR_MT6260__)

VfxS32 VappFmgrGeneralOperation::actionShareSingle(void)
{
    VFX_OBJ_CREATE(m_opt_menu, VcpCommandPopup, this);

    m_opt_menu->setText(STR_GLOBAL_SHARE);
#ifdef __MMI_MMS_2__
    VfxBool isMMSShare = VFX_TRUE;
#ifdef __MMI_MESSAGE_SLIM__
    if (srv_fmgr_types_find_group_by_filename_str(m_src_path.getBuf()) == FMGR_GROUP_VIDEO)
    {
        isMMSShare = VFX_FALSE;
    }
#endif // defined(__MMI_MESSAGE_SLIM__)
    if (isMMSShare == VFX_TRUE)
    {
        m_opt_menu->addItem(MENU_ID_FILE_TYPE_SHARE_AS_MMS, GetStringIdOfItem(MENU_ID_FILE_TYPE_SHARE_AS_MMS), VCP_POPUP_BUTTON_TYPE_NORMAL);
    }
#endif

#ifdef __MMI_EMAIL__
    m_opt_menu->addItem(MENU_ID_FILE_TYPE_SHARE_AS_EMAIL, GetStringIdOfItem(MENU_ID_FILE_TYPE_SHARE_AS_EMAIL), VCP_POPUP_BUTTON_TYPE_NORMAL);
#endif
#ifdef __MMI_OPP_SUPPORT__    
    m_opt_menu->addItem(MENU_ID_FILE_TYPE_SHARE_AS_BT, GetStringIdOfItem(MENU_ID_FILE_TYPE_SHARE_AS_BT), VCP_POPUP_BUTTON_TYPE_NORMAL);
#endif
    m_opt_menu->addItem(MENU_ID_FMGR_CANCEL, STR_GLOBAL_CANCEL, VCP_POPUP_BUTTON_TYPE_CANCEL);

    m_opt_menu->m_signalButtonClicked.connect(this, &VappFmgrGeneralOperation::onClickButton);
    m_opt_menu->m_signalPopupState.connect(this, &VappFmgrGeneralOperation::onPopupStateChange);
    m_opt_menu->setAutoDestory(VFX_FALSE);
    m_opt_menu->show(VFX_TRUE);

    return FS_NO_ERROR;
}

VfxS32 VappFmgrGeneralOperation::actionCreateFolder(void)
{
	if (m_filename_input == NULL)
	{
		VFX_OBJ_CREATE(m_filename_input, VappFileNameEditorPopup, findScreen());
		m_filename_input->setPath(m_src_path);
		m_filename_input->setTitle(STR_ID_VAPP_FMGR_OPTION_NEW_FOLDER);
		m_filename_input->setText(STR_ID_VAPP_FMGR_NAME_NEW_FOLDER, SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
		m_filename_input->getInputbox()->setHighlight(0, m_filename_input->getText().getLength());
		m_filename_input->m_signalButtonClicked.connect(this, &VappFmgrGeneralOperation::onClickInputButton);
		m_filename_input->show(VFX_TRUE);
	}

	return FS_NO_ERROR;
}

#ifndef __MMI_SLIM_FILE_MANAGER__
VfxS32 VappFmgrGeneralOperation::actionRenameDrive(void)
{
	VfxS32 maxLen = SRV_FMGR_DRV_MAX_VOLUME_SIZE - 1;
	
	if (m_filename != NULL && m_src_drv != -1)
	{		
		VFX_OBJ_CREATE(m_filename_input, VappFileNameEditorPopup, findScreen());
		m_filename_input->setTitle(STR_GLOBAL_RENAME);
        m_filename_input->setIsVolumeLabel(VFX_TRUE);
        /* Use TextEditor's setText API to set ENCODING method*/
        m_filename_input->getInputbox()->setText((VfxWChar*)m_filename, maxLen, VFX_FALSE, VCP_TEXT_ENCODING_ASCII);
		m_filename_input->getInputbox()->setHighlight(0, m_filename_input->getText().getLength());
		m_filename_input->m_signalButtonClicked.connect(this, &VappFmgrGeneralOperation::onClickInputButton);
		m_filename_input->show(VFX_TRUE);
	}

	return FS_NO_ERROR;
}
#endif // __MMI_SLIM_FILE_MANAGER__

VfxS32 VappFmgrGeneralOperation::actionRename(void)
{
	VfxS32 maxLen = 0;
	
	if (m_filename_input == NULL && m_filename != NULL)
	{
		if (m_action == VAPP_FMGR_ACTION_RENAME_FILE)
		{
			maxLen = SRV_FMGR_PATH_MAX_FILE_BASENAME_LEN;
		}
		else if (m_action == VAPP_FMGR_ACTION_RENAME_FOLDER)
		{
			maxLen = SRV_FMGR_PATH_MAX_FILE_NAME_LEN;
		}
		VFX_OBJ_CREATE(m_filename_input, VappFileNameEditorPopup, findScreen());
		m_filename_input->setPath(m_src_path);
		m_filename_input->setTitle(STR_GLOBAL_RENAME);
		m_filename_input->setText((VfxWChar*)m_filename, maxLen);
		m_filename_input->getInputbox()->setHighlight(0, m_filename_input->getText().getLength());
		if (m_ext != NULL)
		{
			m_filename_input->setExt(m_ext);
		}
		m_filename_input->m_signalButtonClicked.connect(this, &VappFmgrGeneralOperation::onClickInputButton);
		m_filename_input->show(VFX_TRUE);
	}

	return FS_NO_ERROR;
}

VFX_IMPLEMENT_CLASS("VappFmgrMultiSelect", VappFmgrMultiSelect, VfxControl);

void VappFmgrMultiSelect::onInit(void)
{
	VfxControl::onInit();

	m_count = 0;
	m_max_mark_item_count = 0;	
	m_folder_count = 0;
	m_used = 0;
	m_sort_option = FS_SORT_NAME;		
	m_can_selectall = VFX_FALSE;
	m_select_all = VFX_FALSE;
		
	m_nameArray_ptr = NULL;
	m_nameArray = NULL;
	m_timeArray = NULL;
	m_sizeArray = NULL;
	m_flagArray = NULL;
	m_indexArray = NULL;
	
	VfxObject *obj = getParent();
	if (obj != NULL && obj->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrInstance)))
	{
		m_signalCallerChanged.emit(m_current_caller);
		m_current_caller = obj;	
	}
}

void VappFmgrMultiSelect::onDeinit(void)
{
	if (m_nameArray_ptr != NULL)
	{
		VFX_FREE_MEM(m_nameArray_ptr);	
	}
	if (m_nameArray != NULL)
	{
		VFX_FREE_MEM(m_nameArray);	
	}
	if (m_timeArray != NULL)
	{
		VFX_FREE_MEM(m_timeArray);	
	}
	if (m_sizeArray != NULL)
	{
		VFX_FREE_MEM(m_sizeArray);	
	}
	if (m_flagArray != NULL)
	{
		VFX_FREE_MEM(m_flagArray);	
	}
	if (m_indexArray != NULL)
	{
		VFX_FREE_MEM(m_indexArray);	
	}
	
	VfxControl::onDeinit();
}

void VappFmgrMultiSelect::setSrcPath(VfxWString &path)
{
	m_path.loadFromMem(path.getBuf());
}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
void VappFmgrMultiSelect::setCount(VfxU16 count)
{
	m_count = count;
}

VfxU16 VappFmgrMultiSelect::getCount(void) const
{
	return m_count;
}


VfxS32 VappFmgrMultiSelect::add(VfxObject* obj, VfxWChar *name, VfxU32 size, MYTIME* time, VfxS8 flag)
{
	VfxS16 i = 0;
	VfxS32 ret = VAPP_FMGR_MSA_ERROR_NONE;
	VfxS32 cmp_result = 0;
	VfxU32 time_value = 0;
	VfxWChar* name_ptr = NULL;

	do {
		if (obj == m_current_caller)
		{						
			/* Look for name in name array */
			time_value = convertMYTIME(time);
			
			for (i = 0; i < m_count; i++)
			{			
				if (app_ucs2_strcmp((VfxS8*)name, (VfxS8*)m_nameArray_ptr[i]) == 0)
				{
					/* Got it */
					ret = i;
					break;
				}

				/* "<" : ascending order  0 -> 1 -> 2 -> 3
		         * ">" : descending order 3 -> 2 -> 1 -> 0
		         */
		    #ifdef __FS_SORT_SUPPORT__

				if ((flag & VAPP_FMGRI_MSA_FOLDER && !(m_flagArray[i] & VAPP_FMGRI_MSA_FOLDER)) ||
					(!(flag & VAPP_FMGRI_MSA_FOLDER) && m_flagArray[i] & VAPP_FMGRI_MSA_FOLDER))
				{
					continue;
				}
				
				switch (m_sort_option)
		        {
		            case FS_SORT_NAME:
		            default:
		                cmp_result = FS_SortCompareFileName((WCHAR*)name, (WCHAR*)m_nameArray_ptr[i]);
		                break;

		            case FS_SORT_TYPE:
		                cmp_result = FS_SortCompareFileType((WCHAR*)name, (WCHAR*)m_nameArray_ptr[i]);
		                break;

		            case FS_SORT_SIZE:
		                if (m_sizeArray[i] != size)
		                {
		                    cmp_result = (m_sizeArray[i] < size) ? 1 : -1;
		                }
		                break;

		            case FS_SORT_TIME:
		                if (m_timeArray[i] != time_value)
		                {
		                    cmp_result = (m_timeArray[i] < time_value) ? 1 : -1;
		                }
		                break;
		        }
			#endif

				if (cmp_result > 0)
		        {
		            ret = i;
		            break;
		        }
			}

			if (m_count == m_max_mark_item_count)
			{
				ret = VAPP_FMGR_MSA_ERROR_OVER_MAX;
				break;
			}
			
			/* Add */
			if (m_count > 0)
			{
				name_ptr = m_nameArray_ptr[m_count];
				
				for ( i = m_count - 1; i >= ret; i--)
				{
					/* Shift */
					m_nameArray_ptr[i+1] = m_nameArray_ptr[i];
					m_sizeArray[i+1] = m_sizeArray[i];
					m_timeArray[i+1] = m_timeArray[i];
					m_flagArray[i+1] = m_flagArray[i];
				}

				m_nameArray_ptr[ret] = name_ptr;
			}
			
			app_ucs2_strncpy((VfxS8*)m_nameArray_ptr[ret], (VfxS8*)name, app_ucs2_strlen((VfxS8*)name));
			m_sizeArray[ret] = size;
			m_timeArray[ret] = time_value;
			m_flagArray[ret] = flag;
			m_count++;

			ret = VAPP_FMGR_MSA_ERROR_NONE;
		}
		else
		{
			ret = VAPP_FMGR_MSA_ERROR_NOT_CALLER;
		}
	}while(0);

	return ret;
}

VfxS32 VappFmgrMultiSelect::remove(VfxObject* obj, VfxWChar* name)
{
	VfxU16 i = 0;
	VfxS32 ret = VAPP_FMGR_MSA_ERROR_NONE;

	do {
		if (obj == m_current_caller)
		{
			for (i = 0; i < m_count; i++)
			{			
				if (app_ucs2_strcmp((VfxS8*)name, (VfxS8*)m_nameArray_ptr[i]) == 0)
				{
					/* Got it */					
					break;
				}
			}

			if (i == m_count)
			{
				ret = VAPP_FMGR_MSA_ERROR_FILE_NOT_FOUND;
			}

			ret = remove_by_idx(obj, i);
		}
		else
		{
			ret = VAPP_FMGR_MSA_ERROR_NOT_CALLER;
		}
	} while(0);

	return ret;	
}

VfxS32 VappFmgrMultiSelect::remove_by_idx(VfxObject* obj, VfxU16 index)
{
	VfxU16 i = 0;
	VfxS32 ret = VAPP_FMGR_MSA_ERROR_NONE;
	VfxWChar *tmp_name = NULL;
	do {
		if (index >= m_count)
	    {
	        ret = VAPP_FMGR_MSA_ERROR_FILE_NOT_FOUND;
			break;
	    }
	    i = index;

		tmp_name = m_nameArray_ptr[i];

	    /* Shift entry */
	    for ( ; i < m_count - 1; i++)
	    {
	        m_nameArray_ptr[i] = m_nameArray_ptr[i+1];
	        m_sizeArray[i] = m_sizeArray[i+1];
	        m_timeArray[i] = m_timeArray[i+1];
	        m_flagArray[i] = m_flagArray[i+1];
	    }
	   
	    m_nameArray_ptr[i] = tmp_name;
	    SET_UCS2STR_EMPTY(m_nameArray_ptr[i]);
	    m_sizeArray[i] = 0;
	    m_timeArray[i] = 0;
	    m_flagArray[i] = 0;
	    m_count--;
	}while(0);

	return ret;
}

VfxS16 VappFmgrMultiSelect::isMarked(VfxObject* obj, VfxWChar* name)
{
	VfxU16 i = 0;
	VfxS16 ret = VAPP_FMGR_MSA_ERROR_FILE_NOT_FOUND;

	do {
		if (obj == m_current_caller)		
		{
			for (i = 0; i < m_count; i++)
			{			
				if (app_ucs2_strcmp((VfxS8*)name, (VfxS8*)m_nameArray_ptr[i]) == 0)
				{
					/* Got it */
					ret = i;
					break;
				}
			}
		}
		else
		{
			ret = VAPP_FMGR_MSA_ERROR_NOT_CALLER;
		}
	} while(0);

	return ret;	
}

VfxS32 VappFmgrMultiSelect::add(VfxObject* obj, VfxS32 index, VfxU8 flag)
{
	VfxS32 ret = VAPP_FMGR_MSA_ERROR_NONE;
	
	do {
		if (obj == m_current_caller)
		{
			if (m_indexArray == NULL)
			{
				VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;
				VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
				if (getFileInfo(obj, index, file_info) < 0)
				{
					ret = VAPP_FMGR_MSA_ERROR_FILE_NOT_FOUND;
					VFX_FREE_MEM(file_info);					
					break;
				}
				
				ret = add(obj, (VfxWChar*)file_info->file_name, file_info->file_size, &file_info->time, flag);
				VFX_FREE_MEM(file_info);
			}
			else
			{
				/* Look for index in index array */
                VfxS32 idx = 0;
                for (; idx < m_count; ++idx)
                {
                    if (index == m_indexArray[idx])
                    {
                        ret = idx;
                        break;
                    }

                #ifdef __FS_SORT_SUPPORT__
                    if (index < m_indexArray[idx])
                    {
                        ret = idx;
			            break;
					}
				#endif					
				}

				if (m_count == m_max_mark_item_count)
				{
					ret = VAPP_FMGR_MSA_ERROR_OVER_MAX;
					break;
				}
				
				/* Add */
                if (idx == m_count)
                {
                    ret = idx;
                }

				if (m_count > 0 && ret != m_count)
				{
				    VfxS32 *index_ptr_new = m_indexArray+(ret+1), *index_ptr_old = m_indexArray+ret;
				    VfxS32 *tmpBuff1 = NULL;
                    VFX_ALLOC_MEM(tmpBuff1, sizeof(VfxS32)*(m_count-ret), this);
                    memcpy(tmpBuff1, index_ptr_old, sizeof(VfxS32)*(m_count-ret));
					memcpy(index_ptr_new, tmpBuff1, sizeof(VfxS32)*(m_count-ret));
                    VFX_FREE_MEM(tmpBuff1);
                    
                    VfxS8 *flag_ptr_new = m_flagArray+(ret+1), *flag_ptr_old = m_flagArray+ret;
                    VfxS8 *tmpBuff2 = NULL;
                    VFX_ALLOC_MEM(tmpBuff2, sizeof(VfxS8)*(m_count-ret), this);
                    memcpy(tmpBuff2, flag_ptr_old, sizeof(VfxS8)*(m_count-ret));
                    memcpy(flag_ptr_new, tmpBuff2, sizeof(VfxS8)*(m_count-ret));
                    VFX_FREE_MEM(tmpBuff2);
				}

				m_indexArray[ret] = index;
				m_flagArray[ret] = flag;
				m_count++;

				if (m_flagArray[ret] & VAPP_FMGRI_MSA_FOLDER)
			    {
			        /* increase folder count */				
					m_folder_count++;
			    }
				
				ret = VAPP_FMGR_MSA_ERROR_NONE;
			}
		}
		else
		{
			ret = VAPP_FMGR_MSA_ERROR_NOT_CALLER;
		}
	}while(0);
	
	return ret;
}

VfxS32 VappFmgrMultiSelect::remove(VfxObject* obj, VfxS32 index)
{
	VfxU16 i = 0;
	VfxS32 ret = VAPP_FMGR_MSA_ERROR_NONE;

	do {
		if (obj == m_current_caller)
		{
			if (m_indexArray == NULL)
			{
				VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;
				VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
				if (getFileInfo(obj, index, file_info) < 0)
				{
					ret = VAPP_FMGR_MSA_ERROR_FILE_NOT_FOUND;
					VFX_FREE_MEM(file_info);					
					break;
				}
				
				ret = remove(obj, (VfxWChar*)file_info->file_name);
				VFX_FREE_MEM(file_info);
			}
			else
			{
				for (i = 0; i < m_count; i++)
				{			
					if (index == m_indexArray[i])
					{
						/* Got it */					
						break;
					}
				}

				if (i == m_count)
				{
					ret = VAPP_FMGR_MSA_ERROR_FILE_NOT_FOUND;
				}

				ret = remove_by_array_idx(obj, i);
			}
		}
		else
		{
			ret = VAPP_FMGR_MSA_ERROR_NOT_CALLER;
		}
	} while(0);

	return ret;	
}

VfxS32 VappFmgrMultiSelect::remove_by_array_idx(VfxObject* obj, VfxS32 idx)
{
	VfxS32 ret = VAPP_FMGR_MSA_ERROR_NONE;

	do {
		if (idx < 0 || idx >= m_count)
	    {
	        ret = VAPP_FMGR_MSA_ERROR_FILE_NOT_FOUND;
			break;
	    }
		
		if (obj == m_current_caller)
		{
			if (m_flagArray[idx] & VAPP_FMGRI_MSA_FOLDER)
		    {
		        /* decrease folder count */
				if (m_folder_count > 0)
				{
					m_folder_count--;
				}
		    }
			
			m_indexArray[idx] = -1;
			m_flagArray[idx] = 0;

            VfxS32 index_size = sizeof(VfxS32)*(m_count-idx-1);
            if (index_size > 0)
            {
                VfxS32 *index_ptr_new = m_indexArray+idx, *index_ptr_old = m_indexArray+(idx+1);
		        VfxS32 *tmpBuff1 = NULL;
                VFX_ALLOC_MEM(tmpBuff1, index_size, this);
                memcpy(tmpBuff1, index_ptr_old, index_size);
			    memcpy(index_ptr_new, tmpBuff1, index_size);
                VFX_FREE_MEM(tmpBuff1);
                
                VfxS8 *flag_ptr_new = m_flagArray+idx, *flag_ptr_old = m_flagArray+(idx+1);
                VfxS8 *tmpBuff2 = NULL;
                VfxS32 flag_size = sizeof(VfxS8)*(m_count-idx-1);
                VFX_ALLOC_MEM(tmpBuff2, flag_size, this);
                memcpy(tmpBuff2, flag_ptr_old, flag_size);
                memcpy(flag_ptr_new, tmpBuff2, flag_size);
                VFX_FREE_MEM(tmpBuff2);           			
            }
			m_count--;
		}
		else
		{
			ret = VAPP_FMGR_MSA_ERROR_NOT_CALLER;
		}
	}while(0);
	
	return ret;
}

VfxS32 VappFmgrMultiSelect::remove_all(VfxObject* obj)
{
	VfxU16 i = 0;
	VfxS32 ret = VAPP_FMGR_MSA_ERROR_NONE;
	
	if (obj == m_current_caller)
	{
		if (m_nameArray_ptr != NULL)
		{
			memset(m_nameArray_ptr, 0, m_max_mark_item_count*sizeof(VfxWChar*));		
		}

		if (m_nameArray != NULL)
		{
			memset(m_nameArray, 0, m_max_mark_item_count*sizeof(VfxWChar)*VENUS_FMGR_FILENAME_BUF_LEN);
		}

		if (m_nameArray != NULL && m_nameArray_ptr != NULL)
		{
			for (i = 0; i < m_max_mark_item_count; i++)
			{
				m_nameArray_ptr[i] = m_nameArray + sizeof(VfxWChar)*VENUS_FMGR_FILENAME_BUF_LEN*i; 
			}		
		}

		if (m_sizeArray != NULL)
		{
			memset(m_sizeArray, 0, m_max_mark_item_count*sizeof(VfxU32));
		}

		if (m_timeArray != NULL)
		{
			memset(m_timeArray, 0, m_max_mark_item_count*sizeof(VfxU32));	
		}

		if (m_flagArray != NULL)
		{
			memset(m_flagArray, 0, m_max_mark_item_count*sizeof(VfxS8));
		}

		if (m_indexArray != NULL)
		{
			memset(m_indexArray, -1, m_max_mark_item_count*sizeof(VfxS32));
		}
		
		m_count = 0;
		m_used = 0;
        m_select_all = VFX_FALSE;
	}
	else
	{
		ret = VAPP_FMGR_MSA_ERROR_NOT_CALLER;
	}

	return ret;
}

VfxS16 VappFmgrMultiSelect::isMarked(VfxObject* obj, VfxS32 index)
{
	VfxU16 i = 0;
	VfxS16 ret = VAPP_FMGR_MSA_ERROR_FILE_NOT_FOUND;

	do {
		if (obj == m_current_caller)		
		{
			if (m_count == 0)
			{
				ret = VAPP_FMGR_MSA_ERROR_FILE_NOT_FOUND;
				break;
			}
			
			if (m_indexArray == NULL)
			{
				VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;
				VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
				if (getFileInfo(obj, index, file_info) < 0)
				{
					ret = VAPP_FMGR_MSA_ERROR_FILE_NOT_FOUND;
					VFX_FREE_MEM(file_info);					
					break;
				}
				
				ret = isMarked(obj, (VfxWChar*)file_info->file_name);
				VFX_FREE_MEM(file_info);
			}
			else
			{
				for (i = 0; i < m_count; i++)
				{			
					if (index == m_indexArray[i])
					{
						/* Got it */
						ret = i;
						break;
					}
				}
			}
		}
		else
		{
			ret = VAPP_FMGR_MSA_ERROR_NOT_CALLER;
		}
	} while(0);

	return ret;	
}

VfxS32 VappFmgrMultiSelect::pop(VfxObject* obj)
{
	VfxS32 ret = VAPP_FMGR_MSA_ERROR_NONE;

	if (obj == m_current_caller)
	{
		if (m_count > 0)
		{
			m_count--;

		    if (m_flagArray[m_count] & VAPP_FMGRI_MSA_FOLDER)
		    {
		        /* decrease folder count */
				if (m_folder_count > 0)
				{
					m_folder_count--;
				}
		    }

			if (m_indexArray == NULL)
			{
				SET_UCS2STR_EMPTY(m_nameArray_ptr[m_count]);
			    m_sizeArray[m_count] = 0;
			    m_timeArray[m_count] = 0;		    
			}
			else
			{
			    m_indexArray[m_count]= -1;
			}
		    m_flagArray[m_count] = 0;
		}
	}
	else
	{
		ret = VAPP_FMGR_MSA_ERROR_NOT_CALLER;
	}
	
	return ret;
}

VfxS32 VappFmgrMultiSelect::top(VfxObject* obj, VfxS8 *name_buffer, VfxS32 buffer_size, VfxS8 *flag, VfxBool *isfolder)
{
	VfxS32 index = -1;
	VfxS16 ret = VAPP_FMGR_MSA_ERROR_NONE;
	VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;
	
	do {
		if (obj == m_current_caller)		
		{
			if (name_buffer == NULL || buffer_size == 0)
			{
				ret = VAPP_FMGR_MSA_ERROR_NO_NAMEBUFFER;
				break;
			}

            memset(name_buffer, 0, buffer_size);
            
			if (m_count <= 0)
			{
				ret = FS_FILE_NOT_FOUND;
				break;
			}

			if (flag != NULL)
			{
				(*flag) = m_flagArray[m_count-1];
			}
			
			if (m_indexArray == NULL)
			{
				memcpy(name_buffer, (VfxS8*)m_nameArray_ptr[m_count-1], buffer_size);
			}
			else
			{
				/* Get file info */
				VappFmgrInstance *instance = (VappFmgrInstance*)obj;
				VappFmgrFSData *fsdata = instance->getFSDataObj();
				if (fsdata == NULL)
				{
					ret = VAPP_FMGR_MSA_ERROR_NO_FSOBJ;
					break;
				}

				index = m_count-1;
				if (index < 0)
				{
					ret = FS_FILE_NOT_FOUND;				
					break;
				}
				
				VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
                memset(file_info, 0, sizeof(VAPP_FMGR_FILE_INFO_STRUCT));
                ret = fsdata->getFileInfo(instance, m_indexArray[index], file_info);
				if (ret != FS_NO_ERROR)
				{
					break;
				}

				memcpy(name_buffer, (VfxS8*)file_info->file_name, buffer_size);

				if (isfolder != NULL)
				{
					(*isfolder) = (file_info->attribute & FS_ATTR_DIR)? VFX_TRUE : VFX_FALSE;
				}
			}
		}
		else
		{
			ret = VAPP_FMGR_MSA_ERROR_NOT_CALLER;
		}
	} while(0);

	if (file_info != NULL)
	{
		VFX_FREE_MEM(file_info);
	}
	
	return ret;
}

VfxBool VappFmgrMultiSelect::isProtectedFile(VfxWChar* name)
{
	VfxBool ret = VFX_FALSE;

	do {
		if (name == NULL)
		{
			break;
		}
		
		if (m_path.isNull() || m_path.isEmpty())
		{
			break;
		}

		if (!srv_fmgr_fs_path_exist(m_path.getBuf()))
		{
			break;
		}

		m_path += VFX_WSTR_MEM(name);

		ret = isProtectedFile(m_path);

		srv_fmgr_path_remove_filename((WCHAR*)m_path.getBuf());
	} while(0);

	return ret;
}

VfxBool VappFmgrMultiSelect::isProtectedFile(VfxWString& file_path)
{
	VfxBool ret = VFX_FALSE;
#ifdef __DRM_SUPPORT__
    VfxS32 fwd_rule = mmi_rmgr_check_forward((VfxU16*)file_path.getBuf());
    if (fwd_rule >= 0 && !(fwd_rule & MMI_RMGR_USAGE_SEND))
    {
        ret = VFX_TRUE;
    }
#endif
	return ret;
}

void VappFmgrMultiSelect::setSendableFlag(VfxS8 *flag, VfxBool remove)
{
	if (flag != NULL)
	{
		if (remove)
		{
			(*flag) &= ~VAPP_FMGRI_MSA_SENDABLE;
		}
		else
		{
			(*flag) |= VAPP_FMGRI_MSA_SENDABLE;
		}
	}
}

VfxBool VappFmgrMultiSelect::isSetSendableFlag(VfxS8 flag)
{
	if (flag & VAPP_FMGRI_MSA_SENDABLE)
	{
		return VFX_TRUE;
	}
	else
	{
		return VFX_FALSE;
	}
}

void VappFmgrMultiSelect::setFolderFlag(VfxS8 *flag, VfxBool remove)
{
	if (flag != NULL)
	{
		if (remove)
		{
			(*flag) &= ~VAPP_FMGRI_MSA_FOLDER;
		}
		else
		{
			(*flag) |= VAPP_FMGRI_MSA_FOLDER;
		}
	}
}

VfxBool VappFmgrMultiSelect::isSetFolderFlag(VfxS8 flag)
{
	if (flag & VAPP_FMGRI_MSA_FOLDER)
	{
		return VFX_TRUE;
	}
	else
	{
		return VFX_FALSE;
	}
}

void VappFmgrMultiSelect::setProcessedFlag(VfxS8 *flag, VfxBool remove)
{
	if (flag != NULL)
	{
		if (remove)
		{
			(*flag) &= ~VAPP_FMGRI_MSA_PROCESSED;
		}
		else
		{
			(*flag) |= VAPP_FMGRI_MSA_PROCESSED;
		}
	}
}

VfxBool VappFmgrMultiSelect::isSetProcessedFlag(VfxS8 flag)
{
	if (flag & VAPP_FMGRI_MSA_PROCESSED)
	{
		return VFX_TRUE;
	}
	else
	{
		return VFX_FALSE;
	}
}

void VappFmgrMultiSelect::Selectall(VfxS32 count, VfxS32 start)
{
	if (m_indexArray != NULL)
	{
		if (count > m_max_mark_item_count)
		{
			VFX_ASSERT(0);
		}
		
		VfxS32 i = 0;
		
		for (i = 0; i < count;i++)
		{
			m_indexArray[i] = start+i;
		}

		m_count = count;

		m_select_all = VFX_TRUE;
	}	
}

void VappFmgrMultiSelect::Unselectall(void)
{
	if (m_indexArray != NULL)
	{
		memset(m_indexArray, -1, sizeof(VfxS32)*m_max_mark_item_count);

		m_count = 0;

		m_select_all = VFX_FALSE;
	}
}

void VappFmgrMultiSelect::setSelectallFlag(VfxBool select_all)
{
	m_select_all = select_all;
}

VfxBool VappFmgrMultiSelect::getSelectAllFlag() const
{
    return m_select_all;
}

VfxBool VappFmgrMultiSelect::isCallerFmgrInstance()
{
	VappFmgrInstance *instance = (VappFmgrInstance*)m_current_caller;

	if (instance != NULL && instance->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrInstance)))
	{
		return VFX_TRUE;
	}
	else
	{
		return VFX_FALSE;
	}
}

VfxU32 VappFmgrMultiSelect::convertMYTIME(MYTIME * mytime)
{
	return 0xFFFFFFFF - (((mytime->nYear-1980)*12*31*24*60*60) +
                          (mytime->nMonth*31*24*60*60) +
                          (mytime->nDay*24*60*60) +
                          (mytime->nHour*60*60) +
                          (mytime->nMin*60) +
                          (mytime->nSec));
}

VfxS32 VappFmgrMultiSelect::getFileInfo(VfxObject *obj, VfxS32 index, VAPP_FMGR_FILE_INFO_STRUCT *file_info)
{
	VfxS32 fs_ret = FS_NO_ERROR;

	do {
		if (file_info == NULL)
		{
			fs_ret = FS_PARAM_ERROR;
			break;
		}

		VappFmgrInstance *instance = (VappFmgrInstance*)obj;
		VappFmgrFSData *fsdata = instance->getFSDataObj();

		if (fsdata != NULL)
		{
			fs_ret = fsdata->getFileInfo(instance, index, file_info);			
		}
		
	}while(0);

	return fs_ret;
}

void VappFmgrMultiSelect::setAllowToMarkCount(VfxU32 allow_to_mark_count)
{
    m_allow_to_mark_count = allow_to_mark_count;
}

VfxU32 VappFmgrMultiSelect::getAllowToMarkCount()
{
    return m_allow_to_mark_count;
}

void VappFmgrMultiSelect::createMSA(VfxS32 total_file_num)
{
	#ifdef __FS_SORT_SUPPORT__
		if (total_file_num <= VAPP_FMGR_MAX_MARK_ITEM)
		{
			m_max_mark_item_count = VAPP_FMGR_MAX_MARK_ITEM_FOR_INDEX;
			m_can_selectall = VFX_TRUE;
		}
		else
	#endif
		{
			m_max_mark_item_count = VAPP_FMGR_MAX_MARK_ITEM_FOR_NAME;
			m_can_selectall = VFX_FALSE;
		}
	
	do {
		VFX_ALLOC_MEM(m_flagArray, m_max_mark_item_count*sizeof(VfxS8), this);
		memset(m_flagArray, 0, m_max_mark_item_count*sizeof(VfxS8));
			
	#ifdef __FS_SORT_SUPPORT__
		if (m_max_mark_item_count != VAPP_FMGR_MAX_MARK_ITEM_FOR_NAME)
		{
			VFX_ALLOC_MEM(m_indexArray, m_max_mark_item_count*sizeof(VfxS32), this);
			memset(m_indexArray, -1, m_max_mark_item_count*sizeof(VfxS32));
			break;
		}
	#endif
		VFX_ALLOC_MEM(m_nameArray_ptr, m_max_mark_item_count*sizeof(VfxWChar*), this);
		memset(m_nameArray_ptr, 0, m_max_mark_item_count*sizeof(VfxWChar*));
		VFX_ALLOC_MEM(m_nameArray, m_max_mark_item_count*sizeof(VfxWChar)*VENUS_FMGR_FILENAME_BUF_LEN, this);
		memset(m_nameArray, 0, m_max_mark_item_count*sizeof(VfxWChar)*VENUS_FMGR_FILENAME_BUF_LEN);
		VfxU16 i = 0;
		for (i = 0; i < m_max_mark_item_count; i++)
		{
			m_nameArray_ptr[i] = m_nameArray + sizeof(VfxWChar)*m_max_mark_item_count*i; 
		}
		VFX_ALLOC_MEM(m_sizeArray, m_max_mark_item_count*sizeof(VfxU32), this);
		memset(m_sizeArray, 0, m_max_mark_item_count*sizeof(VfxU32));
		VFX_ALLOC_MEM(m_timeArray, m_max_mark_item_count*sizeof(VfxU32), this);
		memset(m_timeArray, 0, m_max_mark_item_count*sizeof(VfxU32));			
		
	} while(0);
}

static void vapp_fmgri_look_for_system_folder(VappFmgrInstance *instance, VappFmgrFSData *obj, VfxS32 count)
{
	VfxS32 i = 0, k = 0;
	VfxS32 max = -1;
	VfxS8 buffer[VENUS_FMGR_FILENAME_BUF_LEN];
    VfxS8 *buffer2 = NULL;
	VfxS32 sort[g_def_folder_table_size];				
	VfxS32 pre_count = obj->getCount(), j = 0;
	
	if (pre_count <= 0)
	{
		pre_count = 0;
	}

	for (i = 0; i < g_def_folder_table_size; i++)
	{
		sort[i] = -1;
	}
	
	VfxS32 len = 0;
    
    VFX_ALLOC_MEM(buffer2, VENUS_FMGR_FILENAME_BUF_LEN, instance);
    
	for (i = 0; i < g_def_folder_table_size; i++)
	{
		len = app_ucs2_strlen((const kal_int8*)g_def_folder_table[i].path);
        if (g_def_folder_table[i].path[len-1] == '\\')
        {
            len--;
        }
        memset(buffer, 0, VENUS_FMGR_FILENAME_BUF_LEN);
        app_ucs2_strncpy((kal_int8*)buffer2, (const kal_int8*)g_def_folder_table[i].path, len);
		app_ucs2_strlwr((kal_int8*)buffer2);
        
		if (instance->getSystemFolderProperityExist(i) == 0)
		{
            if (instance->getSystemFolderProperityIndex(i) == -1)
            {
			    for (j = pre_count; j < count; j++)
			    {
				    if (srv_fmgr_filelist_get_filename(obj->getFileListHdlr(), j, (WCHAR*)buffer, VENUS_FMGR_FILENAME_BUF_LEN) == 0)
				    {
				        app_ucs2_strlwr((kal_int8*)buffer);
                        
					    if (app_ucs2_strncmp((const kal_int8*)buffer2, (const kal_int8*)buffer, len) == 0 &&
						    buffer[len*ENCODING_LENGTH] == 0 &&
						    buffer[len*ENCODING_LENGTH+1] == 0)
					    {
						    instance->setSystemFolderProperityIndex(i, j);
						    sort[k] = j;
						    k++;
						    break;
					    }
				    }
			    }
            }
            else
            {
                sort[k] = instance->getSystemFolderProperityIndex(i);
                k++;
            }
		}
	}					

    VFX_FREE_MEM(buffer2);
    
	if (k > 0)
	{
		for (i = (k - 1); i > 0; i--)
		{
			for (j = 0 ; j <= (i - 1); j++)
			{
				if (sort[i] < sort[j])
				{
					max = sort[i];
					sort[i] = sort[j];
					sort[j] = max;
				}
			}
		}

		for (i = 0; i < k; i++)
		{
			instance->setSystemFolderOffset(i, sort[i]-i);
		}
		
		VfxU32 temp_count = 0;
		for (i = 0; i < g_def_folder_table_size; i++)
		{
			if (instance->getSystemFolderProperityExist(i) == 0)	
			{
				if (instance->getSystemFolderProperityIndex(i) != -1 &&
					(count-1) >=  instance->getSystemFolderProperityIndex(i))
				{
					temp_count++;
				}
			}
		}

		obj->setSystemFolderCount(temp_count);
	}
}

mmi_ret vapp_fmgr_fsdata_onload_result_proc(mmi_event_struct *param)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_filelist_refresh_result_event_struct* rsp_evt;
    srv_fmgr_filelist_refresh_progress_event_struct* progress_evt;
    srv_fmgr_filelist_load_result_event_struct* load_evt;
	
	vapp_fmgr_load_response_callback load_rsp_cb;
	vapp_fmgr_load_progress_callback load_progress_cb;
	
    S32 result = 0, highlight_index = 0;
    U32 count;
#ifdef __FMGR_HYPERLINK_SUPPORT__
    U32 link_count;
#endif
    U32 complete_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	do {
		/* Get FMGR instance and FSData*/
		VappFmgrInstance *instance = NULL;
		VappFmgrFSData *obj = NULL;

		instance = (VappFmgrInstance*)VfxObject::handleToObject((VfxObjHandle)param->user_data);
			if (instance == NULL)
			{
				break;
			}

			obj = instance->getFSDataObj();
			if (obj == NULL)
			{
				break;
			}
			
			load_rsp_cb = obj->getLoadRspCB();
			load_progress_cb = obj->getLoadProgressCB();			
		
	    switch (param->evt_id)
	    {
	        case EVT_ID_SRV_FMGR_FILELIST_REFRESH_RESULT:

	            rsp_evt = (srv_fmgr_filelist_refresh_result_event_struct*)param;
	            //FMGR_ASSERT(rsp_evt->result <= 0);

	            if(rsp_evt->result == 0)
	            {
	                /* Load file success */
	                count = rsp_evt->total_count;
	                highlight_index = rsp_evt->search_index;

					/* Look for system folders */				
					if (instance->GetDisplayStyle() == VappFmgrPage::VAPP_FMGR_DRAW_DRV_MEM_PAGE &&
						count > 0)
					{					
						vapp_fmgri_look_for_system_folder(instance, obj, count);
					}
					
	            #ifdef __FMGR_HYPERLINK_SUPPORT__
	                link_count = mmi_fmgri_instance_get_hyperlink_count(instance->getInstanceId());
	                count += link_count;
	                if (highlight_index != -1)
	                {
	                    /* Search index found */
	                    highlight_index += link_count;
	                }
	            #endif /* __FMGR_HYPERLINK_SUPPORT__ */

                    obj->setFolderCount(rsp_evt->number_of_folder);
                    obj->setFileCount(count - rsp_evt->number_of_folder);
	                result = count;
	            }
	            else
	            {
	                /* Load file fail */
	                result = rsp_evt->result;
	            }

	            load_rsp_cb.invoke(instance, result, highlight_index);
	            break;

	        case EVT_ID_SRV_FMGR_FILELIST_REFRESH_PROGRESS:

	            progress_evt = (srv_fmgr_filelist_refresh_progress_event_struct*)param;
	            //FMGR_ASSERT(progress_evt->total_count >= 0);
				
	            count = progress_evt->total_count;
	            complete_count = progress_evt->completed_count;

				/* Look for system folders */				
				if (instance->GetDisplayStyle() == VappFmgrPage::VAPP_FMGR_DRAW_DRV_MEM_PAGE &&
					count > 0)
				{					
					vapp_fmgri_look_for_system_folder(instance, obj, complete_count);
				}
	        #ifdef __FMGR_HYPERLINK_SUPPORT__
	            link_count = mmi_fmgri_instance_get_hyperlink_count(instance->getInstanceId());
	            count += link_count;
	            complete_count += link_count;
	        #endif /* __FMGR_HYPERLINK_SUPPORT__ */

	            load_progress_cb.invoke(instance, count, complete_count);
	            break;

	        case EVT_ID_SRV_FMGR_FILELIST_LOAD_RESULT:

	            load_evt = (srv_fmgr_filelist_load_result_event_struct*)param;
	            //FMGR_ASSERT(load_evt->result <= 0);

	            if(load_evt->result == 0)
	            {
	                /* Load file success */
	                count = srv_fmgr_filelist_count(obj->getFileListHdlr());
	            #ifdef __FMGR_HYPERLINK_SUPPORT__
	                count += mmi_fmgri_instance_get_hyperlink_count(instance->getInstanceId());
	            #endif /* __FMGR_HYPERLINK_SUPPORT__ */
	                result = count;
	            }
	            else
	            {
	                /* Load file fail */
	                result = load_evt->result;
	            }

	            load_rsp_cb.invoke(instance, result, VENUS_FMGRI_INDEX_NOT_CHANGE);
	            break;

	        default:
	             //FMGR_ASSERT(0);
	             break;
	    }
	} while(0);
	return MMI_RET_OK;
}

mmi_ret vapp_fmgr_action_multiple_result_proc(mmi_event_struct *param)
{
	VfxS32 progressed_count = 0;
	srv_fmgr_async_done_event_struct *done_evt;
	VappFmgrGeneralOperation *obj = NULL;

	do {
		/* Get FMGR operation object */
		obj = (VappFmgrGeneralOperation*)VfxObject::handleToObject((VfxObjHandle)param->user_data);
		if (obj == NULL)
		{
			break;
		}					
			
		switch (param->evt_id)
	    {
	        case EVT_ID_SRV_FMGR_ASYNC_DONE:

	            done_evt = (srv_fmgr_async_done_event_struct*)param;				

	            if (obj != NULL &&
					obj->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrGeneralOperation)) &&
					obj->getJobId() == done_evt->job_id)
		        {
		        	/* Reset flag ongoing */
		        	obj->resetOngoing();
					
		            if (done_evt->result == 0)
		            {
		                /* Success */
						progressed_count = obj->getProgressed() + 1;
						if (obj->isRemainder(progressed_count))
						{
							/* Check if action was canceled */
							if (obj->getAborting())
							{
								obj->showActionResult(srv_fmgr_fs_error_get_string(FS_ABORTED_ERROR), VFX_TRUE, FS_ABORTED_ERROR, VFX_FALSE);
							}
							else
							{
								/* Next one */
								obj->updateProcessing_ex();
								obj->m_signalActionRsp.postEmit(obj, done_evt->result, VFX_FALSE);
							}							
						}
						else
						{
							/* Finished */					
							/* Clean up screen */
							obj->closeProcessing_ex();
							obj->m_signalActionRsp.postEmit(obj, done_evt->result, VFX_FALSE);
						}
		            }
		            else
		            {
		            	/* Clean up screen */
						obj->closeProcessing_ex();
						
		                /* Fail */
						if (done_evt->result == FS_ABORTED_ERROR)
						{
							obj->showActionResult(srv_fmgr_fs_error_get_string(done_evt->result), VFX_TRUE, done_evt->result, VFX_FALSE);
						}
						else
						{
							obj->showActionResult(srv_fmgr_fs_error_get_string(done_evt->result), VFX_FALSE, done_evt->result, VFX_FALSE);
						}					
		            }				
	            }
	            break;

	        case EVT_ID_SRV_FMGR_ASYNC_ABORTING:
				/* Show Canceling */
	            break;

	        default:
	            VFX_ASSERT(0);
	    }
	} while(0);
    return MMI_RET_OK;
}

mmi_ret vapp_fmgr_action_single_result_proc(mmi_event_struct *param)
{
	VfxU16 str_id = 0;
	srv_fmgr_async_done_event_struct *done_evt;
	VappFmgrGeneralOperation *obj = NULL;

	do {
		/* Get FMGR operation object */
		obj = (VappFmgrGeneralOperation*)VfxObject::handleToObject((VfxObjHandle)param->user_data);
			if (obj == NULL)
			{
				break;
			}					
		
		switch (param->evt_id)
	    {
	        case EVT_ID_SRV_FMGR_ASYNC_DONE:

	            done_evt = (srv_fmgr_async_done_event_struct*)param;				
				
	            if (obj != NULL &&
					obj->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrGeneralOperation)) &&
					obj->getJobId() == done_evt->job_id)
		        {
		        	/* Reset flag ongoing */
		        	obj->resetOngoing();
					
		            if (done_evt->result == 0)
		            {
		                /* Success */
						switch (obj->getAction())
						{
							case VAPP_FMGR_ACTION_COPY:
								break;
							case VAPP_FMGR_ACTION_MOVE:
								break;
							case VAPP_FMGR_ACTION_DELETE_SINGLE:
							case VAPP_FMGR_ACTION_DELETE_FOLDER:
								break;
							case VAPP_FMGR_ACTION_FORMAT:								
								break;
						};
                        
                        if (str_id != 0)
                        {
						    obj->showActionResult(str_id, VFX_TRUE, done_evt->result, VFX_FALSE);
                        }
                        else
                        {
                            obj->m_signalActionRsp.postEmit(obj, done_evt->result, VFX_FALSE);
                        }
		            }
		            else
		            {
		                /* Fail */
						if (done_evt->result == FS_ABORTED_ERROR)
						{
							obj->showActionResult(srv_fmgr_fs_error_get_string(done_evt->result), VFX_TRUE, done_evt->result, VFX_FALSE);
						}
						else
						{
							obj->showActionResult(srv_fmgr_fs_error_get_string(done_evt->result), VFX_FALSE, done_evt->result, VFX_FALSE);
						}
		            }
					//obj->setActionResult(done_evt->result);
			
		            /* Clean up screen */
					obj->closeProcessing_ex();

					//obj->m_signalActionRsp.postEmit(obj, done_evt->result, VFX_FALSE);
	           	}
	            break;

	        case EVT_ID_SRV_FMGR_ASYNC_ABORTING:
				/* Show Canceling */
	            break;

	        default:
	            VFX_ASSERT(0);
	    }
	} while(0);
    return MMI_RET_OK;
}

static mmi_ret vapp_fmgri_notify_all(mmi_event_struct *param)
{
	mmi_ret ret = MMI_RET_OK;
    VappFmgrInstance::NextNotify = VappFmgrInstance::getHeadInstancePtr();
	VappFmgrInstance *instance = VappFmgrInstance::NextNotify;
    
	while (instance != NULL)
	{
	    VFX_OBJ_ASSERT_VALID(instance);

		if (instance->callProc(param) != MMI_RET_OK)
		{
			ret = MMI_RET_ERR;
		}

        if (instance != VappFmgrInstance::NextNotify)
        {
		    instance = VappFmgrInstance::NextNotify;
        }
        else
        {
            instance = instance->getNextInstance();
            VappFmgrInstance::NextNotify = instance;
        }
	}

	return ret;
}

#ifdef __DM_LAWMO_SUPPORT__
static srv_dm_lawmo_wipe_report_cb_func_type g_cb = NULL;

static mmi_ret vapp_fmgr_dm_wipe_format_result_proc(mmi_event_struct *param)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_async_done_event_struct   *adv_action;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
    case EVT_ID_SRV_FMGR_ASYNC_DONE:
		adv_action = (srv_fmgr_async_done_event_struct*)param;
		if (g_cb != NULL)
		{
			(*g_cb)((adv_action->result >= 0) ? KAL_TRUE : KAL_FALSE, "FMGR");
		}
        break;
    }
    return MMI_RET_OK;
}

static VfxS32 vapp_fmgr_do_format(void)
{
	VfxS32 phone_drv = SRV_FMGR_PHONE_DRV;
    VfxS32 ret = 0;

	ret = srv_fmgr_async_format(phone_drv, FS_FORMAT_HIGH, vapp_fmgr_dm_wipe_format_result_proc, NULL);
    if(ret < 0)
        return ret;
    
    return 0;
}
#endif

mmi_ret vapp_fmgr_notify_hdlr(mmi_event_struct *param)
{
	VfxU16 evt_id = param->evt_id;
	if (evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION ||
		evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT ||
		evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN
	#ifdef __MMI_USB_SUPPORT__
		|| evt_id == EVT_ID_USB_ENTER_MS_MODE
	#endif
		)
    {    		
        return vapp_fmgri_notify_all(param);
    }
#if !defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) && !defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) && !defined(__MMI_IME_MEMORY_CARD_SUPPORT__) && !defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
    else if (evt_id == EVT_ID_SRV_FMGRI_CARD_PLUG_OUT)
    {
	    mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)GetString(STR_GLOBAL_MC_REMOVED));
    }
#endif
	else if (evt_id == EVT_ID_SRV_FMGRI_CARD_PLUG_IN)
	{
		mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)GetString(STR_GLOBAL_MC_INSERTED));	
    }
#ifdef __DM_LAWMO_SUPPORT__
	else if (evt_id == EVT_ID_SRV_DM_LAWMO_WIPE_IND)
	{
		srv_dm_lawmo_wipe_ind_evt_struct* lawmo_evt = (srv_dm_lawmo_wipe_ind_evt_struct*)param;
		switch (lawmo_evt->cmd)
		{
			case SRV_DM_LAWMO_WIPE_CMD_FMGR_FORMAT:
				/* Do FMGR DM wipe */
				{
					g_cb = (*lawmo_evt->cb);
					VfxS32 ret = vapp_fmgr_do_format();
            if (ret < 0 && g_cb != NULL)
            {
                (*g_cb)(KAL_FALSE, "FMGR");
            }
        }
				break;
			default:
				//(*lawmo_evt->cb)(KAL_TRUE, "FMGR");
				break;
		}
	}
#endif
    
	return MMI_RET_OK;
}

mmi_ret vapp_fmgr_async_create_folder_result_proc(mmi_event_struct *param)
{
    if (param->evt_id != EVT_ID_SRV_FMGR_ASYNC_DONE)
        return MMI_RET_OK;
    
    VappFmgrInstance *instance = (VappFmgrInstance*)VfxObject::handleToObject((VfxObjHandle)param->user_data);
    if (instance == NULL)
        return MMI_RET_OK;

    // Set create system folder result if drive changed
    srv_fmgr_async_done_event_struct *evt = (srv_fmgr_async_done_event_struct*)param;
    if (evt->job_id != instance->getCreateSystemFolderJobId())
        return MMI_RET_OK;

    instance->setCreateSystemFolderJobId(0);

    // Prepare system folder again if old job of create system folder was 
    // canceled, so index is assgined as 0;
    VfxS32 index = 0;
    if (instance->getCreateSystemFolderJobCancel() == VFX_FALSE)
    {
        index = instance->getPrepareSystemFolderIndex();
        if (evt->result == FS_FILE_EXISTS || evt->result == FS_NO_ERROR)
        {
            instance->setSystemFolderProperityExist(index, 0);
        }

        ++index;
    }
    
    instance->setPrepareSystemFolderIndex(index);
    VfxS32 fs_ret = instance->prepareSystemFolders();
    
    if (fs_ret == VAPP_FMGRI_ERROR_PREPARE_SYSTEM_FOLDER_COMPLETE ||
    fs_ret == FS_MSDC_MOUNT_ERROR)
    {
        // prepare system folder flow done.
        instance->setPrepareSystemFolderIndex(0);
        instance->refreshMenu(VENUS_FMGRI_INDEX_NOT_CHANGE);
    }

    return MMI_RET_OK;
}

#ifndef __MMI_SLIM_FILE_MANAGER__
mmi_ret vapp_fmgr_async_get_folder_size_result_proc(mmi_event_struct *param)
{
	if (param->evt_id == EVT_ID_SRV_FMGR_ASYNC_FOLDER_SIZE_PROGRESSING || 
		param->evt_id == EVT_ID_SRV_FMGR_ASYNC_FOLDER_SIZE_RESULT)
	{
		/* Get FMGR instance object */
		VappFmgrInstance *instance = (VappFmgrInstance*)VfxObject::handleToObject((VfxObjHandle)param->user_data);
		if (instance != NULL)
			{
				VfxS32 fs_ret = 0;
				VappFmgrStorageDetail* page = (VappFmgrStorageDetail*)instance->getPageObj();
				if (page != NULL &&
					page->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrStorageDetail))&&
					(page->getPageId() == VappFmgrPage::VAPP_FMGR_DRAW_STORAGE_DETAIL_PHONE_PAGE ||
					 page->getPageId() == VappFmgrPage::VAPP_FMGR_DRAW_STORAGE_DETAIL_MEM_PAGE))
				{
					if (param->evt_id == EVT_ID_SRV_FMGR_ASYNC_FOLDER_SIZE_PROGRESSING)
					{
						srv_fmgr_async_folder_size_progress_event_struct* evt = (srv_fmgr_async_folder_size_progress_event_struct*)param;

						fs_ret = page->queryUpdate(evt->job_id, evt->folder_size);

						VAPP_FMGR_TRACE1(TRC_VAPP_FMGR_SS_PROGRESS, "[VAPPFMGR] drawStorageDetail - progress queryUpdate %d", fs_ret);
					}
					else
					{
						srv_fmgr_async_folder_size_result_event_struct* evt = (srv_fmgr_async_folder_size_result_event_struct*)param;

						fs_ret = page->queryUpdate(evt->job_id, evt->folder_size, evt->result);

						VAPP_FMGR_TRACE1(TRC_VAPP_FMGR_SS_RESULT, "[VAPPFMGR] drawStorageDetail - result queryUpdate %d", fs_ret);
						
						if (fs_ret == VAPP_FMGRI_ERROR_STORAGE_REPORT_GO_ON ||
                            fs_ret == VAPP_FMGRI_ERROR_STORAGE_REPORT_SWITCH)
						{
                            if (fs_ret == VAPP_FMGRI_ERROR_STORAGE_REPORT_GO_ON)
                            {
							    page->prepareNext();
								page->updatePage(instance, page->getPageId(), -1, VFX_TRUE);
                            }
						}						
					}
				}
			}					
		}					

	return MMI_RET_OK;
}

mmi_ret vapp_fmgr_async_get_single_folder_size_result_proc(mmi_event_struct *param)
{
	if (param->evt_id == EVT_ID_SRV_FMGR_ASYNC_FOLDER_SIZE_PROGRESSING || 
		param->evt_id == EVT_ID_SRV_FMGR_ASYNC_FOLDER_SIZE_RESULT)
	{
		/* Get FMGR instance object */
		VappFmgrInstance *instance = (VappFmgrInstance*)VfxObject::handleToObject((VfxObjHandle)param->user_data);
		if (instance != NULL)
			{
				VfxS32 fs_ret = 0;
				VappFmgrFolderDetail* page = (VappFmgrFolderDetail*)instance->getPageObj();
				if (page != NULL &&
					page->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrFolderDetail))&&
					page->getPageId() == VappFmgrPage::VAPP_FMGR_DRAW_FILE_DETAIL_PAGE)
				{
					if (param->evt_id == EVT_ID_SRV_FMGR_ASYNC_FOLDER_SIZE_PROGRESSING)
					{
						srv_fmgr_async_folder_size_progress_event_struct* evt = (srv_fmgr_async_folder_size_progress_event_struct*)param;

						fs_ret = page->queryUpdate(evt->job_id, evt->folder_size);						
					}
					else
					{
						srv_fmgr_async_folder_size_result_event_struct* evt = (srv_fmgr_async_folder_size_result_event_struct*)param;

                        if (evt->result >= 0)
                        {
						    fs_ret = page->queryUpdate(evt->job_id, evt->folder_size);											
                        }
                        
                        page->setWorkStatus(VFX_FALSE);
                        page->disableEdit(VFX_FALSE);
                        page->updatePageOptionMenu(instance, page->getDisplayStyle());
					}
				}
			}					
		}					

	return MMI_RET_OK;
}
#endif

void vapp_file_type_unknown_launch(mmi_menu_id item_id, const WCHAR* filepath, 
                     const srv_fmgr_fileinfo_struct* fileinfo)
{	
}
