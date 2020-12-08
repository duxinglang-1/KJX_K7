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
 *  vapp_fmgr_cui.cpp
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
#if defined(__COSMOS_MMI__)

#include "vapp_fmgr.h"
#include "vapp_fmgr_cui_gprot.h"
#include "vapp_fmgr_cui_prot.h"
#include "vapp_fmgr_cp.h"
#include "app_str.h"
#include "mmi_rp_vapp_fmgr_def.h"
#include "mmi_rp_vcui_fmgr_def.h"
#include "mmi_rp_srv_venus_component_list_menu_def.h"

#ifdef __MMI_USB_SUPPORT__
#include "vapp_usb_gprot.h"
#include "mmi_rp_vapp_usbmmi_def.h"
#endif

#include "mmi_rp_vapp_vol_dialog_def.h"
#include "mmi_rp_srv_prof_def.h"
#include "vapp_vol_dialog_gprot.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
#include "MMI_include.h"

#include "FileMgrSrvGProt.h"

#include "FileMgrSrvIProt.h"    /* for check drive */

#ifdef __DRM_SUPPORT__                
#include "Drm_gprot.h"
#include "RightsMgrGProt.h"
#endif

#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif

#include "ProfilesSrvGprot.h"

#include "mdi_audio.h"
#include "mdi_datatype.h"

#include "ucmsrvgprot.h"
#include "custmenures.h"
#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
#define VCUI_FILE_SELECTOR

typedef enum
{
    VCUI_FILE_SELECTOR_OPT_STYLE_MASK            = 0x00F00000,
    VCUI_FILE_SELECTOR_OPT_STYLE_FILE_ONLY       = 0x00000000,
    VCUI_FILE_SELECTOR_OPT_STYLE_FILE_FOLDER     = 0x00100000

} vcui_file_selector_option_internal_enum;

mmi_id vcui_file_selector_create(mmi_id caller, const WCHAR* start_path, const FMGR_FILTER* filter, 
                                vcui_file_selector_style_enum style, U32 option_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vapp_fmgr_launch_args arg;

	memset(&arg, 0, sizeof(vapp_fmgr_launch_args));
    /* Check if it is usb storage mode */
#ifdef __MMI_USB_SUPPORT__	
#if 1
	if (srv_usb_is_in_mass_storage_mode())
	{
		/* Todo: Usd defined value SRV_USB_ERROR_UNAVAILABLE to get error string id then popup */
        vapp_usb_unavailable_popup(0);		
		return GRP_ID_INVALID;
	}
#endif	
#endif	
	arg.flag = option_flag;
	arg.style = style;
	app_ucs2_strncpy((kal_int8*)arg.file_path, (const kal_int8*)start_path, sizeof(arg.file_path));
	arg.app_type = VappFmgrInstance::VAPP_FMGR2_TYPE_FILE_SELECTOR;
	memcpy(&arg.filter_type, filter, sizeof(arg.filter_type));

	/* Perform setting check */
    if (style == VCUI_FILE_SELECTOR_STYLE_FILE_AND_PATH)
    {
        FMGR_FILTER_SET(&(arg.filter_type), FMGR_TYPE_FOLDER);
        arg.flag |= VCUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_SUB;
    }
    else if (style == VCUI_FILE_SELECTOR_STYLE_FILE_ONLY)
    {
        if (!FMGR_FILTER_IS_SET(filter, FMGR_TYPE_FOLDER))
        {
            arg.flag |= VCUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_NONE;
        }
    }

	if (arg.flag & VCUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_NONE)
    {
        FMGR_FILTER_CLEAR(&(arg.filter_type), FMGR_TYPE_FOLDER);
    }
	
    return VfxAppLauncher::createCui( 
        VCUI_FMGR,
        VFX_OBJ_CLASS_INFO(VappFmgrCui),
        caller,
        &arg,
        sizeof(vapp_fmgr_launch_args));
}    

void   vcui_fmgr_run(mmi_id cui_id)
{
    if(cui_id != GRP_ID_INVALID)
	VfxAppLauncher::runCui(cui_id);
}

void vcui_fmgr_close(mmi_id cui_id, vcui_fmgr_type_enum cui_type)
{
    VappFmgrInstance::vapp_fmgri_type_enum fmgri_type;

    switch (cui_type)
    {
        case VCUI_FMGR_TYPE_FILE_SELECTOR:
            fmgri_type = VappFmgrInstance::VAPP_FMGR2_TYPE_FILE_SELECTOR;
            break;
            
        case VCUI_FMGR_TYPE_FOLDER_SELECTOR:
            fmgri_type = VappFmgrInstance::VAPP_FMGR2_TYPE_FOLDER_SELECTOR;
            break;
            
        case VCUI_FMGR_TYPE_FOLDER_BROWSER:
            fmgri_type = VappFmgrInstance::VAPP_FMGR2_TYPE_FOLDER_BROWSER;
            break;
            
        case VCUI_FMGR_TYPE_MEDIA_PICKER:
            fmgri_type = VappFmgrInstance::VAPP_FMGR2_TYPE_MEDIA_PICKER;
            break;
            
        default:
            VFX_ASSERT(0);
            return;
    }
    if (VappFmgrInstance::cui_basic_check(cui_id, fmgri_type))
    {
        VfxApp *app = VfxApp::getObject(cui_id);
        if (app != NULL)
        {
            app->exit();
        }
    }
}

void vcui_fmgr_set_title(mmi_id cui_id, U16 string, U16 icon, vcui_fmgr_type_enum cui_type)
{
    VappFmgrInstance::vapp_fmgri_type_enum fmgri_type;

    switch (cui_type)
    {
        case VCUI_FMGR_TYPE_FILE_SELECTOR:
            fmgri_type = VappFmgrInstance::VAPP_FMGR2_TYPE_FILE_SELECTOR;
            break;
            
        case VCUI_FMGR_TYPE_FOLDER_SELECTOR:
            fmgri_type = VappFmgrInstance::VAPP_FMGR2_TYPE_FOLDER_SELECTOR;
            break;
            
        case VCUI_FMGR_TYPE_FOLDER_BROWSER:
            fmgri_type = VappFmgrInstance::VAPP_FMGR2_TYPE_FOLDER_BROWSER;
            break;
            
        case VCUI_FMGR_TYPE_MEDIA_PICKER:
            fmgri_type = VappFmgrInstance::VAPP_FMGR2_TYPE_MEDIA_PICKER;
            break;
            
        default:
            VFX_ASSERT(0);
            return;
    }
    VappFmgrInstance *instance = VappFmgrInstance::cui_basic_check(cui_id, fmgri_type);
    if (instance)
    {
        VappFmgrCUIInstance *cui = (VappFmgrCUIInstance*)instance;
        cui->set_title(cui_id, fmgri_type, string, icon);
    }
}

void   vcui_file_selector_set_option(mmi_id cui_id, U32 option_mask, U32 option_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Not support this function */
}

void   vcui_file_selector_set_ui_style(mmi_id cui_id, S32 style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Not support this function */
}

void   vcui_file_selector_set_userdata(mmi_id cui_id, U32 userdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	VappFmgrInstance *instance = VappFmgrInstance::cui_basic_check(cui_id, VappFmgrInstance::VAPP_FMGR2_TYPE_FILE_SELECTOR);
	if (instance)
	{
		VappFmgrCUIInstance *cui = (VappFmgrCUIInstance*)instance;
		cui->set_userdata(cui_id, VappFmgrInstance::VAPP_FMGR2_TYPE_FILE_SELECTOR, userdata);
	}
}

U32    vcui_file_selector_get_userdata(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	VappFmgrInstance *instance = VappFmgrInstance::cui_basic_check(cui_id, VappFmgrInstance::VAPP_FMGR2_TYPE_FILE_SELECTOR);
	if (instance)
	{
		VappFmgrCUIInstance *cui = (VappFmgrCUIInstance*)instance;
		return cui->get_userdata(cui_id, VappFmgrInstance::VAPP_FMGR2_TYPE_FILE_SELECTOR);
	}
    return 0;
}

const WCHAR* vcui_file_selector_get_folder(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	VappFmgrInstance *instance = VappFmgrInstance::cui_basic_check(cui_id, VappFmgrInstance::VAPP_FMGR2_TYPE_FILE_SELECTOR);
	if (instance)
	{
		VappFmgrCUIInstance *cui = (VappFmgrCUIInstance*)instance;
		return cui->get_folder(cui_id, VappFmgrInstance::VAPP_FMGR2_TYPE_FILE_SELECTOR);
	}
    return NULL;
}

S32    vcui_file_selector_get_selected_filepath_old(mmi_id cui_id, srv_fmgr_fileinfo_struct* info, WCHAR* path_buffer, S32 path_size)
{
	/* Obsolete */
	return -1;
}

S32    vcui_file_selector_get_selected_filepath(mmi_id cui_id, srv_fmgr_fileinfo_struct* info, WCHAR* path_buffer, S32 path_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	VappFmgrInstance *instance = VappFmgrInstance::cui_basic_check(cui_id, VappFmgrInstance::VAPP_FMGR2_TYPE_FILE_SELECTOR);
	if (instance)
	{
		VappFmgrCUIInstance *cui = (VappFmgrCUIInstance*)instance;
		return cui->get_selected_filepath(cui_id, VappFmgrInstance::VAPP_FMGR2_TYPE_FILE_SELECTOR, info, path_buffer, path_size);
	}

	return VAPP_FMGR_ERROR_INVALID_PARAM;
}

#define VCUI_FOLDER_SELECTOR

void   vcui_folder_selector_set_option(mmi_id cui_id, U32 option_mask, U32 option_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Not support custom option menu */
}

void   vcui_folder_selector_set_ui_style(mmi_id cui_id, S32 style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/* Not support other UI style */
}

void vcui_folder_selector_set_userdata(mmi_id cui_id, U32 userdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	VappFmgrInstance *instance = VappFmgrInstance::cui_basic_check(cui_id, VappFmgrInstance::VAPP_FMGR2_TYPE_FOLDER_SELECTOR);
	if (instance)
	{
		VappFmgrCUIInstance *cui = (VappFmgrCUIInstance*)instance;
		cui->set_userdata(cui_id, VappFmgrInstance::VAPP_FMGR2_TYPE_FOLDER_SELECTOR, userdata);
	}
}

U32    vcui_folder_selector_get_userdata(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	VappFmgrInstance *instance = VappFmgrInstance::cui_basic_check(cui_id, VappFmgrInstance::VAPP_FMGR2_TYPE_FOLDER_SELECTOR);
	if (instance)
	{
		VappFmgrCUIInstance *cui = (VappFmgrCUIInstance*)instance;
		return cui->get_userdata(cui_id, VappFmgrInstance::VAPP_FMGR2_TYPE_FOLDER_SELECTOR);
	}
    return 0;
}

const WCHAR* vcui_folder_selector_get_folder(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	VappFmgrInstance *instance = VappFmgrInstance::cui_basic_check(cui_id, VappFmgrInstance::VAPP_FMGR2_TYPE_FOLDER_SELECTOR);
	if (instance)
	{
		VappFmgrCUIInstance *cui = (VappFmgrCUIInstance*)instance;
		return cui->get_folder(cui_id, VappFmgrInstance::VAPP_FMGR2_TYPE_FOLDER_SELECTOR);
	}
    return NULL;
}

mmi_id vcui_folder_selector_create(mmi_id caller, const WCHAR* start_path, 
                                  vcui_folder_selector_style_enum style, U32 option_flag)
{
	vapp_fmgr_launch_args arg;

	memset(&arg, 0, sizeof(vapp_fmgr_launch_args));
    /* Check if it is usb storage mode */
#ifdef __MMI_USB_SUPPORT__	
#if 1
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* Todo: Usd defined value SRV_USB_ERROR_UNAVAILABLE to get error string id then popup */
        vapp_usb_unavailable_popup(0);      
		return GRP_ID_INVALID;
    }
#endif	
#endif

	arg.flag = option_flag;
	arg.style = style;
	app_ucs2_strncpy((kal_int8*)arg.file_path, (const kal_int8*)start_path, sizeof(arg.file_path));
	arg.app_type = VappFmgrInstance::VAPP_FMGR2_TYPE_FOLDER_SELECTOR;
	FMGR_FILTER_INIT(&arg.filter_type);
	FMGR_FILTER_SET(&arg.filter_type, FMGR_TYPE_FOLDER);
		
    return VfxAppLauncher::createCui( 
        VCUI_FMGR,
        VFX_OBJ_CLASS_INFO(VappFmgrCui),
        caller,
        &arg,
        sizeof(vapp_fmgr_launch_args));
}

S32    vcui_folder_selector_get_selected_filepath_old(mmi_id cui_id, srv_fmgr_fileinfo_struct* info, WCHAR* path_buffer, S32 path_size)
{
	/* Obsolete */
	return -1;
}

VfxS32 vcui_folder_selector_get_selected_filepath(mmi_id cui_id, srv_fmgr_fileinfo_struct* info, WCHAR* path_buffer, S32 path_size)
{
	VappFmgrInstance *instance = VappFmgrInstance::cui_basic_check(cui_id, VappFmgrInstance::VAPP_FMGR2_TYPE_FOLDER_SELECTOR);
	if (instance)
	{
		VappFmgrCUIInstance *cui = (VappFmgrCUIInstance*)instance;
		return cui->get_selected_filepath(cui_id, VappFmgrInstance::VAPP_FMGR2_TYPE_FOLDER_SELECTOR, info, path_buffer, path_size);
	}

	return VAPP_FMGR_ERROR_INVALID_PARAM;
}

#define VCUI_FOLDER_BROWSER_LAUNCH
static mmi_id vcui_folder_browser_launch_int(mmi_id parent_id, const WCHAR* base_path, const FMGR_FILTER* filter)
{
    vapp_fmgr_launch_args arg;
    
    memset(&arg, 0, sizeof(vapp_fmgr_launch_args));

    /* Check if it is usb storage mode */
#ifdef __MMI_USB_SUPPORT__	
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* Todo: Usd defined value SRV_USB_ERROR_UNAVAILABLE to get error string id then popup */
        vapp_usb_unavailable_popup(0);      
        return GRP_ID_INVALID;
    }
#endif	

    VfxS32 len = app_ucs2_strlen((const kal_int8*)base_path);
    
    if (len <= 3 || app_ucs2_strncmp((const kal_int8*)base_path, (const kal_int8*)L"root", 4) == 0)
    {
        /* Can't be root or drive */
        return GRP_ID_INVALID;
    }
        
    app_ucs2_strncpy((kal_int8*)arg.file_path, (const kal_int8*)base_path, sizeof(arg.file_path));
    arg.app_type = VappFmgrInstance::VAPP_FMGR2_TYPE_FOLDER_BROWSER;
    FMGR_FILTER_INIT(&arg.filter_type);
    memcpy(&arg.filter_type, filter, sizeof(arg.filter_type));
    FMGR_FILTER_CLEAR(&arg.filter_type, FMGR_TYPE_FOLDER);
        
    return VfxAppLauncher::createCui( 
        VCUI_FMGR,
        VFX_OBJ_CLASS_INFO(VappFmgrCui),
        parent_id,
        &arg,
        sizeof(vapp_fmgr_launch_args));
}

mmi_id vcui_folder_browser_launch(mmi_id parent_id, const WCHAR* base_path, const FMGR_FILTER* filter)
{
    mmi_id gid = vcui_folder_browser_launch_int(parent_id, base_path, filter);
    vcui_fmgr_run(gid);
    return gid;
}

mmi_id vcui_folder_browser_launch_by_custom(mmi_id parent_id, const WCHAR* base_path, const FMGR_FILTER* filter)
{
    return vcui_folder_browser_launch_int(parent_id, base_path, filter);
}

VFX_IMPLEMENT_CLASS("VappFmgrCui", VappFmgrCui, VappFmgrApp);

void VappFmgrCui::onInit()
{
	VappFmgrApp::onInit();
    registerCBEvent(EVT_ID_SRV_PROF_PROFILE_SWITCHED, VFX_TRUE);
}

void VappFmgrCui::onDeinit()
{  
    registerCBEvent(EVT_ID_SRV_PROF_PROFILE_SWITCHED, VFX_FALSE);
	VappFmgrApp::onDeinit();  
}

void VappFmgrCui::onGroupActive()
{
    VappFmgrApp::onGroupActive();

    registerCBEvent(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, VFX_TRUE);
}

void VappFmgrCui::onGroupInactive()
{
    registerCBEvent(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, VFX_FALSE);
	
	VappFmgrInstance *instance = (VappFmgrInstance*)m_instance;
	if (m_instance != NULL && m_instance->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrFileSelectorCUI)))
	{
		VappFmgrFileSelectorCUI *cui_instance = (VappFmgrFileSelectorCUI*)instance;
		/* Stop preview */
		cui_instance->stopPreviewAudioEx();
		/* Reset preview info */
		cui_instance->resetPreviewAudioStopInfoEx();
	}
    VappFmgrApp::onGroupInactive();
}

void VappFmgrCui::onRun(void * args, VfxU32 argSize)
{
    VappFmgrApp::onRun(args, argSize);

        /* Create instance */
    VFX_ASSERT(NULL != args);
    vapp_fmgr_launch_args *arg = (vapp_fmgr_launch_args*)args;
    VfxU32 page_id;
    VappFmgrInstance *instance;
    VappFmgrMainScr *scr;
    
    VFX_OBJ_CREATE(scr, VappFmgrMainScr, this);
    switch (arg->app_type)
    {
        case VappFmgrInstance::VAPP_FMGR2_TYPE_FOLDER_SELECTOR:
        {
            VFX_OBJ_CREATE(instance, VappFmgrFolderSelectorCUI, scr);
            page_id = VappFmgrPage::VAPP_FMGR_DRAW_FOLDER_SELECT_PAGE;
            VappFmgrFolderSelectorCUI* tmp_obj = (VappFmgrFolderSelectorCUI*)instance;
            tmp_obj->setStyle((vcui_folder_selector_style_enum)arg->style);
            break;
        }

        case VappFmgrInstance::VAPP_FMGR2_TYPE_FILE_SELECTOR:
        {
            VFX_OBJ_CREATE(instance, VappFmgrFileSelectorCUI, scr);
            page_id = VappFmgrPage::VAPP_FMGR_DRAW_SINGLE_FILE_SELECT_PAGE;
            break;
        }

        case VappFmgrInstance::VAPP_FMGR2_TYPE_FOLDER_BROWSER:
        {
            VFX_OBJ_CREATE(instance, VappFmgrFolderBrowserLaunch, scr);
            page_id = VappFmgrPage::VAPP_FMGR_DRAW_FOLDER_BROWSER_LAUNCH_PAGE;
            break;
        }		
        // For media picker
        case VappFmgrInstance::VAPP_FMGR2_TYPE_MEDIA_PICKER:
        {
            VFX_OBJ_CREATE(instance, VappFmgrMediaPickerCUI, scr);
            page_id = VappFmgrPage::VAPP_FMGR_DRAW_MEDIA_PICKER_PAGE;
            break;
        }

        default:
            VFX_ASSERT(0);
            return;
    }		

    instance->setGid(getGroupId());
    instance->setFilter(arg->filter_type);
    instance->setDisplayStyle(page_id);
    instance->createFSDataObj(VFX_TRUE, getGroupId());
    instance->setFilePath(arg->file_path);
    instance->setInstancyType(arg->app_type);

    scr->setCallerInstance(instance);

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
        page->updatePageOptionMenu(instance, 0);
    #endif
    }
    else
    {
        /* connect with instance */
        VappFmgrPage *page;
        VFX_OBJ_CREATE_EX(page, VappFmgrPage, scr, (page_id, instance));
        page->m_signalGetOptMenuItem.connect(instance, &VappFmgrInstance::getOptionItem);
        page->m_signalGetTitleStrAndIcn.connect(instance, &VappFmgrInstance::getTitleStrAndIcn);
        page->updatePage(instance, instance->GetDisplayStyle(), -1, VFX_TRUE);
        scr->pushPage((page_id+1), page);
    }

    instance->setTitleIconId(arg->title_icon_id);
    instance->setTitleStrId(arg->title_str_id);
    instance->setDrvType(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
    instance->setCurIndex(0);
    instance->setFlag(arg->flag);
    instance->setCustData(app_ucs2_strlen((const kal_int8*)instance->getFilePath().getBuf()));
    m_instance = (VfxObject*)instance;

    scr->show();
}

mmi_ret VappFmgrCui::onProc(mmi_event_struct *evt)
{
	if (m_instance != NULL)
	{
		VappFmgrInstance *instance = (VappFmgrInstance*)m_instance;
		return instance->callProc(evt);
	}

	return MMI_RET_OK;
}

VFX_IMPLEMENT_CLASS("VappFmgrCUIInstance", VappFmgrCUIInstance, VappFmgrInstance);

void VappFmgrCUIInstance::onInit()
{
	VappFmgrInstance::onInit();

	m_select_index = -1;
	m_select_pos.invalid();
	
	this->addFmgrInstance(this);
}

void VappFmgrCUIInstance::onDeinit()
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

/* *CUI commom API */
void   VappFmgrCUIInstance::set_title(mmi_id cui_id, vapp_fmgri_type_enum type, U16 string, U16 icon)
{
	title_str_id = string;
	title_icon_id = icon;
}

void   VappFmgrCUIInstance::set_userdata(mmi_id cui_id, vapp_fmgri_type_enum type, U32 userdata)
{
	user_data = userdata;
}

U32    VappFmgrCUIInstance::get_userdata(mmi_id cui_id, vapp_fmgri_type_enum type)
{
	return user_data;
}
		
const WCHAR* VappFmgrCUIInstance::get_folder(mmi_id cui_id, vapp_fmgri_type_enum type)
{
	return m_file_path.getBuf();    
}

// For media picker
VfxS32 VappFmgrCUIInstance::getPickedNum()
{
    // if mark all, then return 1 for parent folder;
    // else marked num
    if (m_ms)
    {
        if(m_ms->getSelectAllFlag())
        {
            return 1;
        }
        else
        {
            return m_ms->getCount()>MMI_FMGR_MEDIA_PICKER_MAX_NUM ? MMI_FMGR_MEDIA_PICKER_MAX_NUM : m_ms->getCount();
        }
    }
    // picked a folder with cmd button
    else if (m_select_pos.isValid() || !(m_select_index < 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
VfxS32 VappFmgrCUIInstance::getPickedMultiPath(void* pathArray, U32 picked_num)
{
    /* copy path */
    VfxU32 base_count = m_ms->getCount();
    if (base_count > MMI_FMGR_MEDIA_PICKER_MAX_NUM)
    {
        base_count = MMI_FMGR_MEDIA_PICKER_MAX_NUM;
    }

    VfxS8   *marked_file_name;
    VFX_ALLOC_MEM(marked_file_name, VENUS_FMGR_FILENAME_BUF_LEN, this);
    
    vcui_fmgr_media_path_struct *pArray = (vcui_fmgr_media_path_struct*)pathArray;
    VfxS32 idx = 0;
    do {
        VfxBool isDir;
        VfxS32 topRet = m_ms->top(this, marked_file_name, VENUS_FMGR_FILENAME_BUF_LEN_RESERVED, NULL, &isDir);
        if (topRet != VappFmgrMultiSelect::VAPP_FMGR_MSA_ERROR_NONE)
            break;

        if (composeFilePath((VfxS8*)(pArray[idx].path), VAPP_FMGR_FILE_PATH_LEN, m_file_path, marked_file_name, isDir) < 0)
        {
            memset(pArray[idx].path, 0, VAPP_FMGR_FILE_PATH_LEN);
            m_ms->pop(this);
            continue;
        }
        
        /* Check DRM permission */
#ifdef __DRM_SUPPORT__                      
        VfxS32 fs_ret = mmi_rmgr_check_forward((WCHAR*)pArray[idx].path);        
        if (fs_ret >= 0 && (!(fs_ret & MMI_RMGR_USAGE_SEND)))
        {
            memset(pArray[idx].path, 0, VAPP_FMGR_FILE_PATH_LEN);
            m_ms->pop(this);
            continue;
        }
#endif
        pArray[idx].isFolder = isDir? 1: 0;
        m_ms->pop(this);        
        ++idx;
    }while(idx < base_count);
    
    if (base_count != idx)
    {
        showPopup(STR_ID_VAPP_FMGR_DRM_AND_PATH_OVER_LEN_FAIL, VCP_POPUP_TYPE_INFO);
    }

    if (marked_file_name != NULL)
    {
        VFX_FREE_MEM(marked_file_name);
    }

    return idx;
}
VfxS32 VappFmgrCUIInstance::getPickedPathes(mmi_id cui_id, vapp_fmgri_type_enum type, void* pathArray, U32 picked_num)
{
    VfxS32 ret = 0;
    vcui_fmgr_media_path_struct *pArray = (vcui_fmgr_media_path_struct*)pathArray;

    if (m_ms)
    {
        if (m_ms->getSelectAllFlag())
        {
            pArray->isFolder = 1;
            memcpy(pArray->path, m_file_path.getBuf(), VAPP_FMGR_FILE_PATH_LEN);
            ret = 1;
        }
        else
        {
            ret = getPickedMultiPath(pathArray, picked_num);
        }
    }
    else
    {
        ret = get_selected_filepath(cui_id, type, NULL, pArray->path, VAPP_FMGR_FILE_PATH_LEN);
        if (ret >= 0)
            pArray->isFolder = 1;        
    }
    return ret;
}

VfxS32 VappFmgrCUIInstance::get_selected_filepath(mmi_id cui_id, vapp_fmgri_type_enum type, srv_fmgr_fileinfo_struct* info, VfxWChar* path_buffer, VfxS32 path_size)
{
	VfxS32 ret = 0;
	VappFmgrInstance *instance = NULL;
	VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;

	do{
		instance = cui_basic_check(cui_id, type);
	    if (!instance)
	    {
	        ret = VAPP_FMGR_ERROR_INVALID_PARAM;
			break;
	    }

		if (m_select_index < 0 && m_select_pos.pos < 0)
	    {
	        ret = FS_NO_MORE_FILES;
			break;
	    }

		VfxS32 index = -1;
		if (m_select_pos.group == 0)
		{
			/* System folders */
			index = m_select_pos.pos;
			
			ret = m_system_folder_properity[index].exist;
			if (ret < 0)
			{
				break;
			}

			if (path_buffer && path_size >= ENCODING_LENGTH)
		    {
		        if (!isFilePathRoot())
		        {
		        	VfxWString tmp = m_file_path;
					ret = composeFilePath(tmp, (VfxS8*)g_def_folder_table[index].path, VFX_FALSE);
		            if (ret < 0)
		            {
						break;
		            }

					if (tmp.getLength() >= path_size/ENCODING_LENGTH)
					{
						ret = FS_PATH_OVER_LEN_ERROR;
						break;
					}

					memset((VfxS8*)path_buffer, 0, path_size);
					app_ucs2_strncpy((kal_int8*)path_buffer, (const kal_int8*)tmp.getBuf(), (path_size/ENCODING_LENGTH-1));
		        }	        
		    }
		}
		else
		{
			/* User defined */
			if (m_select_pos.group == 1)
			{
				index = m_select_pos.pos;
			}
			else
			{
				index = m_select_index;
			}
			
			VappFmgrFSData *fsdata = getFSDataObj();
			if (fsdata != NULL)
			{
				VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
				ret = fsdata->getFileInfo(instance, index, file_info);

				if (ret < 0)
				{
					break;
				}			

				if (path_buffer && path_size >= ENCODING_LENGTH)
			    {
			        if (!isFilePathRoot())
			        {
			        	VfxWString tmp = m_file_path;
						VfxBool add_end_slash = VFX_FALSE;
						if (file_info->attribute & FS_ATTR_DIR)
						{
							add_end_slash = VFX_TRUE;
						}
						ret = composeFilePath(tmp, file_info->file_name, add_end_slash);
			            if (ret < 0)
			            {
							break;
			            }

						if (tmp.getLength() >= path_size/ENCODING_LENGTH)
						{
							ret = FS_PATH_OVER_LEN_ERROR;
							break;
						}

						memset((VfxS8*)path_buffer, 0, path_size);
						app_ucs2_strncpy((kal_int8*)path_buffer, (const kal_int8*)tmp.getBuf(), (path_size/ENCODING_LENGTH-1));
			        }	        
			    }

			    if (info)
			    {
			        info->attribute = file_info->attribute;
			        info->datetime = file_info->time;
			        info->size = file_info->file_size;
			        info->type = file_info->file_type;
			    }
			}
		}
	}while(0);
	
	if (file_info != NULL)
	{
		VFX_FREE_MEM(file_info);
	}

	return ret;
}

void VappFmgrCUIInstance::onPopupStateChange(VfxBasePopup* obj,  VfxBasePopupStateEnum state)
{
	if (state == VFX_BASE_POPUP_AFTER_END_ANIMATION)
	{
		if (m_flag & VAPP_FMGR_IFLAG_WAIT_POPUP)
		{
			m_flag &= ~VAPP_FMGR_IFLAG_WAIT_POPUP;

			/* callback here */
			if (m_delay_event != NULL)
			{
				VfxCui *app = (VfxCui*)VfxApp::getObject(m_gid);
				if (app != NULL)
				{
					app->postToParent((mmi_group_event_struct*)m_delay_event);
				}

                VFX_FREE_MEM(m_delay_event);
                m_delay_event = NULL;
			}
		}
	}
}

/* *CUI commom API */

VFX_IMPLEMENT_CLASS("VappFmgrFileSelectorCUI", VappFmgrFileSelectorCUI, VappFmgrCUIInstance);

mmi_id g_group_id = GRP_ID_INVALID;

static void vapp_fmgr_audio_play_callback(mdi_result result, void *user_data)
{
	if (result == MDI_AUDIO_TERMINATED ||
		result == MDI_AUDIO_END_OF_FILE)
	{
		/* Stop it */
		VappFmgrApp* app = (VappFmgrApp*)VfxApp::getObject(g_group_id);
		if (app != NULL)
		{
			VappFmgrFileSelectorCUI* instance = (VappFmgrFileSelectorCUI*)app->getInstance();
			if (instance != NULL && instance->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrFileSelectorCUI)))
			{
				instance->setPreviewAudioStopInfo();
			}
		}
	}
	else
	{
		/* Stop it */
		VappFmgrApp* app = (VappFmgrApp*)VfxApp::getObject(g_group_id);
		if (app != NULL)
		{
			VappFmgrFileSelectorCUI* instance = (VappFmgrFileSelectorCUI*)app->getInstance();
			if (instance != NULL && instance->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrFileSelectorCUI)))
			{
				instance->setPreviewAudioStopInfo();
			}
		}

        /* Show balloon*/
        mmi_event_notify_enum event_type;
        VfxU16 string_id = mdi_audio_get_error_info(result, &event_type);
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)GetString(string_id));
	}
}

void VappFmgrFileSelectorCUI::onInit()
{
    VappFmgrCUIInstance::onInit();

    if (m_system_folder_properity == NULL)
    {
        VFX_ALLOC_MEM(m_system_folder_properity, sizeof(vapp_fmgr_system_folder_properity_struct)*g_def_folder_table_size, this);
        resetSystemFolderProperity();
    }
    m_stop_audio_index = -1;
    m_stop_audio_pos.group = -1;
    m_stop_audio_pos.pos = -1;

    m_playing_audio_index = -1;
    m_playing_audio_pos.group = -1;
    m_playing_audio_pos.pos = -1;
}

void VappFmgrFileSelectorCUI::onDeinit()
{
    /* Stop preivew audio */
	stopPreviewAudio();
    
	VappFmgrCUIInstance::onDeinit();
}

mmi_ret VappFmgrFileSelectorCUI::callProc(mmi_event_struct *param)
{
	return onProc(param);
}

mmi_ret VappFmgrFileSelectorCUI::onProc(mmi_event_struct *param)
{
	mmi_ret ret = MMI_RET_OK;

    VAPP_FMGR_TRACE1(TRC_VAPP_FMGR_FILESEL_ONPROC, "[VAPPFMGR] file selector onProc, evt id %d", param->evt_id);
    
	ret = VappFmgrInstance::onProc(param);

	if (ret == MMI_RET_OK)
	{
		switch (param->evt_id)
		{
		#ifdef __MMI_USB_SUPPORT__
		    case EVT_ID_USB_ENTER_MS_MODE:
                {
                    /* Close file manager */
            		callbackApp(this, NULL, 0);
                }
                break;
		#endif

                case EVT_ID_SRV_PROF_PROFILE_SWITCHED:
		{
		    if(m_flag & VCUI_FILE_SELECTOR_OPT_AUDIO_PREVIEW_ON)
		    {
			stopPreviewAudio();
                        setPreviewAudioStopInfo();
		    }
		    break;
		}
            case EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE:
                {
                    if (m_flag & VCUI_FILE_SELECTOR_OPT_AUDIO_PREVIEW_ON)
                    {
                        vapp_vol_dialog_evt_struct *volEvent = (vapp_vol_dialog_evt_struct*)param;
            
                        if (volEvent->type == VAPP_VOL_DIALOG_IS_MEDIA)
                        {
                            return !MMI_RET_OK;
                        }
                    }
                }
                break;
			case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
				{
					srv_fmgr_notification_dev_plug_event_struct *evt = (srv_fmgr_notification_dev_plug_event_struct*)param;

					VfxU8 i = 0;
					
					for (i = 0; i < evt->count; i++)
			        {
			        	if (evt->drv_letters[i] == (VfxU8)m_file_path.getBuf()[0])
						{
							/* Todo: Close new folder ediotr */
						
							if (m_file_path.getLength() == 3)
							{
								/* Reset preview info */
								resetPreviewAudioStopInfo();
								/* On drv page so refresh it */
								refreshMenu(VENUS_FMGRI_INDEX_ERROR_CODE, FS_MSDC_MOUNT_ERROR);
							}
							else
							{
								/* Back root */
								backRoot();
							}
							break;
			        	}
					}					 
				}
				break;
			case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
				{
					onHandleEventPlugIn(param);
				}
				break;

		}
	}

	return ret;
}

void VappFmgrFileSelectorCUI::setMenu(VcpListMenu *listmenu)
{
	m_listmenu = listmenu;	
	m_listmenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT);
	if (m_flag & VCUI_FILE_SELECTOR_OPT_AUDIO_PREVIEW_ON)
	{
		m_listmenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_FALSE);
		m_listmenu->m_signalCmdButtonClicked.connect(this, &VappFmgrFileSelectorCUI::onClickCmdButton);
	}
	else
	{
		m_listmenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE, VFX_FALSE);
	}
	m_listmenu->m_signalItemTapped.connect(this, &VappFmgrFileSelectorCUI::onTapListMenuItem);	

	/* Connect signal of view start and end */
	VappFmgrInstance::setMenu(listmenu);
}

void VappFmgrFileSelectorCUI::setMenu(VcpGroupListMenu *listmenu)
{
	m_glist = listmenu;
	m_glist->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT);
	if (m_flag & VCUI_FILE_SELECTOR_OPT_AUDIO_PREVIEW_ON)
	{
		m_glist->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_FALSE);
		m_glist->m_signalCmdButtonClicked.connect(this, &VappFmgrFileSelectorCUI::onClickGroupCmdButton);
	}
	else
	{
		m_glist->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE, VFX_FALSE);
	}
	m_glist->m_signalItemTapped.connect(this, &VappFmgrFileSelectorCUI::onTapGroupListMenuItem);

	/* Connect signal of view start and end */
	VappFmgrInstance::setMenu(listmenu);
}

VfxBool VappFmgrFileSelectorCUI::getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        )
{
	
	VfxBool result = VFX_FALSE;	
	VfxS32 fs_ret = 0;
	VappFmgrFSData *obj = getFSDataObj();
	VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;

	do {
		if (isFilePathRoot())
		{
			result = VappFmgrInstance::getItemImage(index, fieldType, image);
		}
		else
		{
			/* file list */
			VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
			fs_ret = obj->getFileInfo(this, index, file_info);
			if (fs_ret < 0)
			{
				/* error handling */
				//vapp_fmgr_error_handling_cb(fs_ret);
				obj->setLoadFileIndex(index);
				error_handler(fs_ret);
				break;
			}
			
			if (fieldType == VCP_LIST_MENU_FIELD_ICON)
			{						
				image.setResId(srv_fmgr_types_get_icon(file_info->file_type, NULL, SRV_FMGR_TYPES_ICON_LARGE));
				result = VFX_TRUE;
			}			
			else if (fieldType >= VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL &&
				     fieldType <= VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT)
			{
				if (!(file_info->attribute & FS_ATTR_DIR))
				{
					/* audio preview img button */										
					if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL ||
						fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT)
					{
						if (m_playing_audio_index == index)
						{
							image.setResId(IMG_ID_VAPP_FMGR_AUD_PREV_STOP_N);
						}
						else
						{
							image.setResId(IMG_ID_VAPP_FMGR_AUD_PREV_PLAY_N);
						}
					}
					else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_PRESSED)
					{
						if (m_playing_audio_index == index)
						{
							image.setResId(IMG_ID_VAPP_FMGR_AUD_PREV_STOP_P);
						}
						else
						{
							image.setResId(IMG_ID_VAPP_FMGR_AUD_PREV_PLAY_P);
						}
					}
					else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED)
					{
						if (m_stop_audio_index == index)
						{
							image.setResId(IMG_ID_VAPP_FMGR_AUD_PREV_STOP_D);
						}
						else
						{
							image.setResId(IMG_ID_VAPP_FMGR_AUD_PREV_PLAY_D);
						}
					}
					result = VFX_TRUE;
				}
			}
            else if ((file_info->attribute & FS_ATTR_DIR) && fieldType == VCP_LIST_MENU_FIELD_DISCLOSURE_IMG)
            {
                image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
                result = VFX_TRUE;
            }
		}
	}while(0);

    if (file_info != NULL)
    {
        VFX_FREE_MEM(file_info);
    }
    
	return result;
}

VcpListMenuCellBaseControl* VappFmgrFileSelectorCUI::getItemCustomControl(VfxU32 index,VcpListMenuCellControlLocationTypeEnum location,VfxFrame * parentFrame)
{
	VfxS32 fs_ret = 0;
	VappFmgrFSData *obj = getFSDataObj();
	VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;
	VcpListMenuDisclosure* disclosure = NULL;
	
	do {
		VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
		fs_ret = obj->getFileInfo(this, index, file_info);
		if (fs_ret < 0)
		{
			/* error handling */
			obj->setLoadFileIndex(index);
			error_handler(fs_ret);
			break;
		}
		
		if(file_info->attribute & FS_ATTR_DIR && location == VCP_LIST_MENU_CELL_CONTROL_LOCATION_TYPE_TAIL)
	    {
	        VfxImageSrc image;
	        image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
	        VFX_OBJ_CREATE_EX(disclosure, VcpListMenuDisclosure, parentFrame,(image));
	    }
	} while(0);

	if (file_info != NULL)
	{
		VFX_FREE_MEM(file_info);
	}
    return disclosure;
}

VcpListMenuCellBaseControl* VappFmgrFileSelectorCUI::getItemCustomControl(VcpMenuPos pos,VcpListMenuCellControlLocationTypeEnum location,VfxFrame * parentFrame)
{
    if (!m_isGroupListMenu)
    {
        return getItemCustomControl(pos.pos, location, parentFrame);
    }
	VfxBool ShowCustControl = VFX_TRUE;
	VfxS32 fs_ret = 0, index = pos.pos;
	VappFmgrFSData *obj = getFSDataObj();
	VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;
	VcpListMenuDisclosure* disclosure = NULL;

	do {
		if (pos.group > 0)
		{
			VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
			fs_ret = obj->getFileInfo(this, index, file_info);
			if (fs_ret < 0)
			{
				/* error handling */
				obj->setLoadFileIndex(index);
				error_handler(fs_ret);
				break;
			}

			if (!(file_info->attribute & FS_ATTR_DIR))
			{
				ShowCustControl = VFX_FALSE;
			}
		}
		
		if(ShowCustControl && location == VCP_LIST_MENU_CELL_CONTROL_LOCATION_TYPE_TAIL)
	    {
	        VfxImageSrc image;
	        image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
	        VFX_OBJ_CREATE_EX(disclosure, VcpListMenuDisclosure, parentFrame,(image));
	    }
	} while(0);

	if (file_info != NULL)
	{
		VFX_FREE_MEM(file_info);
	}
    return disclosure;
}

VfxBool VappFmgrFileSelectorCUI::getItemImage(
        VcpMenuPos pos,                  // [IN] the position of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        )
{
	if (!m_isGroupListMenu)
    {
        return getItemImage(pos.pos, fieldType, image);
    }   
	VfxBool result = VFX_FALSE;	
	VfxS32 fs_ret = 0, index = pos.pos;
	VappFmgrFSData *obj = getFSDataObj();
	VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;

	do {
		if (pos.group == 0)
		{
			/* System folder */			
			if (fieldType == VCP_LIST_MENU_FIELD_ICON)
			{						
				result = VappFmgrInstance::getItemImage(pos, fieldType, image);
			}
            else if (fieldType == VCP_LIST_MENU_FIELD_DISCLOSURE_IMG)
            {
                image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
                result = VFX_TRUE;
            }
		}
		else
		{
			/* file list */
			VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
			fs_ret = obj->getFileInfo(this, index, file_info);
			if (fs_ret < 0)
			{
				/* error handling */
				//vapp_fmgr_error_handling_cb(fs_ret);
				obj->setLoadFileIndex(index);
				error_handler(fs_ret);
				break;
			}
			
			if (fieldType == VCP_LIST_MENU_FIELD_ICON)
			{						
				image.setResId(srv_fmgr_types_get_icon(file_info->file_type, NULL, SRV_FMGR_TYPES_ICON_LARGE));
				result = VFX_TRUE;
			}			
			else if (fieldType >= VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL &&
				     fieldType <= VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT)
			{
				if (!(file_info->attribute & FS_ATTR_DIR))
				{
					/* audio preview img button */										
					if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL ||
						fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT)
					{
						if (m_playing_audio_pos.pos == index)
						{
							image.setResId(IMG_ID_VAPP_FMGR_AUD_PREV_STOP_N);
						}
						else
						{
							image.setResId(IMG_ID_VAPP_FMGR_AUD_PREV_PLAY_N);
						}
					}
					else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_PRESSED)
					{
						if (m_playing_audio_pos.pos == index)
						{
							image.setResId(IMG_ID_VAPP_FMGR_AUD_PREV_STOP_P);
						}
						else
						{
							image.setResId(IMG_ID_VAPP_FMGR_AUD_PREV_PLAY_P);
						}
					}
					else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED)
					{
						if (m_stop_audio_pos.pos == index)
						{
							image.setResId(IMG_ID_VAPP_FMGR_AUD_PREV_STOP_D);
						}
						else
						{
							image.setResId(IMG_ID_VAPP_FMGR_AUD_PREV_PLAY_D);
						}
					}
					result = VFX_TRUE;
				}
			}
            else if ((file_info->attribute & FS_ATTR_DIR) && fieldType == VCP_LIST_MENU_FIELD_DISCLOSURE_IMG)
            {
                image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
                result = VFX_TRUE;
            }
		}
	}while(0);

    if (file_info != NULL)
    {
        VFX_FREE_MEM(file_info);
    }
	return result;
}

VfxBool VappFmgrFileSelectorCUI::isMenuItemDisable(VfxU32 page_id, VfxU16 &opt_menu_id)
{
    if (opt_menu_id == MENU_ID_FMGR_CANCEL)
	{
		return VFX_FALSE;
	}

    return VappFmgrInstance::isMenuItemDisable(page_id, opt_menu_id);
}

void VappFmgrFileSelectorCUI::onTapListMenuItem(VcpListMenu *listmenu, VfxU32 index)
{
	VfxS32 fs_ret = 0;
	VappFmgrFSData *fsdata = getFSDataObj();
	VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;
	
	/* Stop preview */
	stopPreviewAudio();
	/* Reset preview info */
	resetPreviewAudioStopInfo();
	/* Reset select info */
    m_select_index = -1;
    m_select_pos.invalid();
    
	do {
		if (fsdata != NULL)
		{			
			VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
			fs_ret = fsdata->getFileInfo(this, index, file_info);

			if (fs_ret < 0)
			{
				/* error handling */
				showPopup(srv_fmgr_fs_error_get_string(fs_ret), VCP_POPUP_TYPE_FAILURE);
				VFX_FREE_MEM(file_info);
				break;
			}
			
			if (file_info->attribute & FS_ATTR_DIR)
			{
				/* Folder case */
                m_cur_index = index;
				enterFolder(file_info->file_name);						
			}
			else
			{
				/* File case */
				m_select_index = index;
					
				callbackApp(this, file_info, 1);
			}
			VFX_FREE_MEM(file_info);
		}
	} while(0);
}

void VappFmgrFileSelectorCUI::onTapGroupListMenuItem(VcpGroupListMenu *listmenu, VcpMenuPos pos)
{
	VfxS32 fs_ret = 0;
	VappFmgrFSData *fsdata = getFSDataObj();
	VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;
	VfxS32 index = pos.pos;

    /* Stop preview */
	stopPreviewAudio();
	/* Reset preview info */
	resetPreviewAudioStopInfo();
    /* Reset select info */
    m_select_index = -1;
    m_select_pos.invalid();
    
	do {
		if (fsdata != NULL)
		{
			if (pos.group == 0 && index >= 0)
			{
				/* System folder */
				fs_ret = m_system_folder_properity[index].exist;
				if (fs_ret < 0)
				{
					/* The system folder does not exist */
					/* error handling */
					showPopup(srv_fmgr_fs_error_get_string(FS_PATH_NOT_FOUND), VCP_POPUP_TYPE_FAILURE);
					break;
				}

                m_group_pos = pos;
				enterFolder((VfxS8*)g_def_folder_table[index].path);	
			}
			else if (pos.group == 1 && index >= 0)
			{			
				/* User defined */
				VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
				fs_ret = fsdata->getFileInfo(this, index, file_info);

				if (fs_ret < 0)
				{
					/* error handling */
					showPopup(srv_fmgr_fs_error_get_string(fs_ret), VCP_POPUP_TYPE_FAILURE);
					VFX_FREE_MEM(file_info);
					break;
				}
				
				if (file_info->attribute & FS_ATTR_DIR)
				{
					/* Folder case */
                    m_group_pos = pos;
					enterFolder(file_info->file_name);						
				}
				else
				{
					/* File case */
					m_select_pos.setCell(pos.group, index);
					
					callbackApp(this, file_info, 1);
				}				
				VFX_FREE_MEM(file_info);
			}
		}
	} while(0);
}

void VappFmgrFileSelectorCUI::handleClickCmdButton(VfxS32 playing_index, VfxS32 cur_index, VfxS32 group)
{
		VfxS32 fs_ret = 0;
		VappFmgrFSData *obj = getFSDataObj();
		VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;

	/* file list */
		VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
	fs_ret = obj->getFileInfo(this, cur_index, file_info);
		if (fs_ret < 0)
		{
			/* error handling */
			VFX_FREE_MEM(file_info);
		obj->setLoadFileIndex(cur_index);
			showPopup(srv_fmgr_fs_error_get_string(fs_ret), VCP_POPUP_TYPE_FAILURE);
			return;
		}

		if (file_info->attribute & FS_ATTR_DIR)
		{
			/* Folder case */
			/* Stop preview */
			stopPreviewAudio();
			/* Reset preview info */
			resetPreviewAudioStopInfo();
			enterFolder(file_info->file_name);
		}
		else
		{			
			/* audio preview */
			VfxBool stop_only = VFX_FALSE;

		if (playing_index == cur_index)
			{
				stop_only = VFX_TRUE;
			}
			/* 1. stop preview */
			stopPreviewAudio();
			
			/* 2. play sound */
			if (!stop_only)
			{
			    VfxU16 string_id = 0;
				VfxBool playing = startPreviewAudio(file_info, &string_id);
				
				if (playing)
				{
			    if (group != -1)
                {         
				    m_playing_audio_pos.pos = cur_index;
                }
                else
                {
                    m_playing_audio_index = cur_index;
                }
				if (m_glist != NULL && m_playing_audio_pos.group == 1 && m_playing_audio_pos.pos != -1)
				{
					m_glist->updateItem(m_playing_audio_pos);
				}
                else if (m_listmenu != NULL && m_playing_audio_index != -1)
					{
						m_listmenu->updateItem(m_playing_audio_index);
					}
				}
				else
				{
					/* Can not preview so popup error */
					mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)GetString(string_id));
				}
			}			
		}

		VFX_FREE_MEM(file_info);
	}

void VappFmgrFileSelectorCUI::onClickCmdButton(VcpListMenu *listmenu, VfxU32 index)
{
	if (m_flag & VCUI_FILE_SELECTOR_OPT_AUDIO_PREVIEW_ON)
	{
		
		handleClickCmdButton(m_playing_audio_index, index);
	}
}

void VappFmgrFileSelectorCUI::onClickGroupCmdButton(VcpGroupListMenu *listmenu, VcpMenuPos pos)
{
	if (m_flag & VCUI_FILE_SELECTOR_OPT_AUDIO_PREVIEW_ON)
	{
		VfxS32 fs_ret = 0, index = pos.pos;
		
		if (pos.group == 0)
		{
			/* System folder */			
			fs_ret = m_system_folder_properity[index].exist;
			if (fs_ret < 0)
			{
				/* The system folder does not exist */
				/* error handling */
				showPopup(srv_fmgr_fs_error_get_string(FS_PATH_NOT_FOUND), VCP_POPUP_TYPE_FAILURE);
				return;
			}

			/* Stop preview */
			stopPreviewAudio();
			/* Reset preview info */
			resetPreviewAudioStopInfo();
			enterFolder((VfxS8*)g_def_folder_table[index].path);
		}
		else
		{
			handleClickCmdButton(m_playing_audio_pos.pos, index, pos.group);
		}
	}
}

void VappFmgrFileSelectorCUI::onClickUpButton(VfxObject* obj, VfxId button_id)
{
	/* Stop preview */
	stopPreviewAudio();
	/* Reset preview info */
	resetPreviewAudioStopInfo();

	VappFmgrInstance::onClickUpButton(obj, button_id);
}

void VappFmgrFileSelectorCUI::onClickToolBarButton(VfxObject* obj, VfxId button_id)
{	
	if (m_action == NULL)
	{		
		switch (button_id)
		{					
			case MENU_ID_FMGR_CANCEL:
				{					
					callbackApp(this, NULL, 0);
				}
				break;			
			default:
				break;
		};
	}
}
	
void VappFmgrFileSelectorCUI::getOptionItem(VfxU32 page_id, VfxU16 &opt_menu_id, VfxU16 &opt_menu_num)
{	
	VfxU16 opt_menu = 0;

	opt_menu = MENU_ID_FMGR_OPTION_FOLDER_SELECTOR_CUI;
	resetOptMenu(opt_menu);
    mmi_frm_hide_menu_item(MENU_ID_FMGR_OPTION_NEW_FOLDER);
    
	opt_menu_id = opt_menu;

	opt_menu_num = GetNumOfChild_Ext(opt_menu_id);
}

void VappFmgrFileSelectorCUI::stopPreviewAudioEx(void)
{
	stopPreviewAudio();
}

void VappFmgrFileSelectorCUI::resetPreviewAudioStopInfoEx(void)
{
	resetPreviewAudioStopInfo();
}

void VappFmgrFileSelectorCUI::callbackApp(VappFmgrInstance* instance, VAPP_FMGR_FILE_INFO_STRUCT *file_info, VfxS32 result)
{
	vcui_folder_selector_result_event_struct evt;
#ifdef __DRM_SUPPORT__
    S32 fwd_flag;
#endif /* __DRM_SUPPORT__ */

	/* Stop preivew audio */
	stopPreviewAudio();
	/* Reset preview info */
	resetPreviewAudioStopInfo();
	
	if (file_info)
    {        
        /* Check max path */
		VfxS8 *buffer = NULL;
		VFX_ALLOC_MEM(buffer, VAPP_FMGR_FILE_PATH_LEN, this);

		if (composeFilePath(buffer,VAPP_FMGR_FILE_PATH_LEN, m_file_path, file_info->file_name, VFX_FALSE))
		{
			/* popup error */
			showPopup(srv_fmgr_fs_error_get_string(FS_PATH_OVER_LEN_ERROR), VCP_POPUP_TYPE_FAILURE);
			VFX_FREE_MEM(buffer);
			return;
		}

	#ifdef __DRM_SUPPORT__
        /* Check the file's forward status */
        if (!(file_info->attribute & FS_ATTR_DIR) &&
            (m_flag & (VCUI_FILE_SELECTOR_OPT_DRM_CHECK_SEND_ON|VCUI_FILE_SELECTOR_OPT_DRM_CHECK_SET_ON)))
        {
            fwd_flag = mmi_rmgr_check_forward((U16*)buffer);
            if (fwd_flag < 0)
            {
                showPopup(srv_fmgr_fs_error_get_string(fwd_flag), VCP_POPUP_TYPE_FAILURE);
                VFX_FREE_MEM(buffer);
                return;
            }
			
            if (((m_flag & VCUI_FILE_SELECTOR_OPT_DRM_CHECK_SET_ON) && !(fwd_flag & MMI_RMGR_USAGE_SET)) ||
                ((m_flag & VCUI_FILE_SELECTOR_OPT_DRM_CHECK_SEND_ON) && !(fwd_flag & MMI_RMGR_USAGE_SEND)))
            {
                showPopup(STR_GLOBAL_DRM_PROHIBITED, VCP_POPUP_TYPE_FAILURE);
                VFX_FREE_MEM(buffer);
                return;
            }
        }
	#endif /* __DRM_SUPPORT__ */

		VFX_FREE_MEM(buffer);
    }

    /* Dead, skip the event */
    if(instance->getFlag()& VAPP_FMGR_IFLAG_DEAD)
    {        
        return;
    }

    if (!file_info)
    {
        instance->addFlag(VAPP_FMGR_IFLAG_DEAD);
    }

    evt.evt_id = EVT_ID_VCUI_FILE_SELECTOR_RESULT;
    evt.size = sizeof(evt);
    evt.user_data = NULL;
    evt.sender_id = m_gid;

    evt.result = result;

	VappFmgrInstance::callbackApp((mmi_group_event_struct*)&evt);
}

VfxBool VappFmgrFileSelectorCUI::error_handler(VfxS32 error_code, VfxS32 line)
{
	VfxBool result = VFX_FALSE;

	do {
        VAPP_FMGR_TRACE2(TRC_VAPP_FMGR_FILESEL_ERR, "[VAPPFMGR]file selector error handler, err_code %d, line %d", error_code, line);
        
		switch (error_code)
	    {
	        case VAPP_FMGRI_ERROR_FILE_LIST_IS_DIRTY:
                break;
	        case SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY:
            case SRV_FMGR_FILELIST_ERROR_BUSY:
                VappFmgrInstance::error_handler(error_code);
                break;
            case FS_DEVICE_BUSY:
                showPopup(srv_fmgr_fs_error_get_string(error_code), VCP_POPUP_TYPE_FAILURE);
                callbackApp(this, NULL, error_code);
            case FS_MSDC_MOUNT_ERROR:
	        case FS_MSDC_READ_SECTOR_ERROR:
	        case FS_MSDC_WRITE_SECTOR_ERROR:
	        case FS_MSDC_DISCARD_SECTOR_ERROR:
	        case FS_MSDC_PRESNET_NOT_READY:
	        case FS_MSDC_NOT_PRESENT:
			case FS_DRIVE_NOT_READY:
			case FS_FILE_NOT_FOUND:
	                return VFX_TRUE;

	        case FS_MEDIA_CHANGED:
	        case VAPP_FMGR_ERROR_EMPTY:
	        case FS_DRIVE_NOT_FOUND:
	            if (isFilePathRoot())
	            {
	                /* Popup error */	                					
					#ifdef __FS_CARD_SUPPORT__
						showPopup(STR_GLOBAL_INSERT_MEMORY_CARD, VCP_POPUP_TYPE_FAILURE);	
	                #else /* __FS_CARD_SUPPORT__ */
						showPopup(STR_ID_VAPP_FMGR_NO_AVAILABLE_STORAGE, VCP_POPUP_TYPE_FAILURE);
	                #endif /* __FS_CARD_SUPPORT__ */
	                callbackApp(this, NULL, error_code);
	            }
				else
				{
					return VFX_TRUE;
				}
	            break;
	        default:
	            /* Popup error */
				showPopup(srv_fmgr_fs_error_get_string(error_code), VCP_POPUP_TYPE_FAILURE);
				
	            if (isFilePathRoot())
	            {
	                callbackApp(this, NULL, error_code);
	            }
	            else
	            {
	                switch (error_code)
	                {
	                    case FS_PATH_OVER_LEN_ERROR:
	                    case FS_PATH_NOT_FOUND:
                        case FS_ABORTED_ERROR:
	                        leaveFolder(error_code);
	                        break;

	                    default:
	                        /* Move to Root */
	                        backRoot();
	                        break;
	                }
	            }
	            break;
	    }	
	} while(0);
	
	return result;
}

void VappFmgrFileSelectorCUI::leaveFolder(S32 result)
{
	if (m_file_path.getLength() == 3 ||
        (m_flag & VCUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_NONE) ||
        ((m_flag & VCUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_SUB) && m_file_path.getLength() <= (S32)cust_data))
    {
        callbackApp(this, NULL, result);
    }
    else
    {    
        if (m_page != NULL)
		{
			/* Stop preview */
			stopPreviewAudio();
			/* Reset preview info */
			resetPreviewAudioStopInfo();

			VappFmgrPage *page = (VappFmgrPage*)m_page;
            page->setExit();
			page->closePage();
			m_page = NULL;
		}
    }
}

void VappFmgrFileSelectorCUI::leaveFolderEx(S32 result)
{
	leaveFolder(result);
}

void VappFmgrFileSelectorCUI::stopPreviewAudio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (m_playing_audio_pos.pos != -1 || m_playing_audio_index != -1)
	{
		mdi_audio_stop_file();		
	}
}

void VappFmgrFileSelectorCUI::setPreviewAudioStopInfo(void)
{
	if (m_playing_audio_pos.pos != -1 || m_playing_audio_index != -1)
	{
		m_stop_audio_index = m_playing_audio_index;
		m_stop_audio_pos = m_playing_audio_pos;
		
		m_playing_audio_index = -1;
		m_playing_audio_pos.group = 1;
		m_playing_audio_pos.pos = -1;

		if (m_stop_audio_index != -1 && m_listmenu != NULL)
		{
			m_listmenu->updateItem(m_stop_audio_index);
		}
		else if (m_stop_audio_pos.group == 1 && m_stop_audio_pos.pos != -1 && m_glist != NULL)
		{
			m_glist->updateItem(m_stop_audio_pos);
		}
			
	}
}

void VappFmgrFileSelectorCUI::resetPreviewAudioStopInfo(void)
{
	m_playing_audio_index = -1;
	m_playing_audio_pos.group = 1;
	m_playing_audio_pos.pos = -1;

	m_stop_audio_index = -1;
	m_stop_audio_pos.group = 1;
	m_stop_audio_pos.pos = -1;
}

VfxBool VappFmgrFileSelectorCUI::startPreviewAudio(VAPP_FMGR_FILE_INFO_STRUCT *file_info, VfxU16 *str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxU16 string_id = 0;
    VfxBool result = VFX_TRUE;
    VfxS8  *buffer = NULL;
#ifdef __DRM_SUPPORT__
    VfxS32 fwd_rule;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do {
        
#ifdef __MMI_BACKGROUND_CALL__
        if (srv_ucm_is_background_call())
        {
            string_id = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL;
            result = VFX_FALSE;
            break;
        }
#endif

        if((m_flag & VCUI_FILE_SELECTOR_OPT_AUDIO_PREVIEW_ON) &&
            (srv_fmgr_types_find_group_by_type(file_info->file_type) == FMGR_GROUP_AUDIO))
        {
            /* check path */
    		VFX_ALLOC_MEM(buffer, VAPP_FMGR_FILE_PATH_LEN, this);
    		memset(buffer, 0, VAPP_FMGR_FILE_PATH_LEN);
            if(composeFilePath(buffer, VAPP_FMGR_FILE_PATH_LEN, m_file_path, file_info->file_name, VFX_FALSE) < 0)
            {
                string_id = srv_fmgr_fs_error_get_string(FS_PATH_OVER_LEN_ERROR);
                result = VFX_FALSE;
                break;
            }
            
#if defined(__DRM_SUPPORT__)
            /* check DRM */
            fwd_rule = mmi_rmgr_check_forward((U16*)buffer);
            if(fwd_rule < 0 || !(fwd_rule & MMI_RMGR_USAGE_SET))
            {
                string_id = STR_GLOBAL_DRM_PROHIBITED;
                result = VFX_FALSE;
                break;
            }
#endif        
                        
        	g_group_id = m_gid;
            mdi_result mdiresult = mdi_audio_play_file_portion_with_vol_path(buffer,
                                                                             0,
                                                                             0,
                                                                             DEVICE_AUDIO_PLAY_INFINITE,
                                                                             NULL,
                                                                             vapp_fmgr_audio_play_callback,
                                                                             NULL,
                                                                             (U8)srv_prof_get_media_vol(),
                                                                             MDI_DEVICE_SPEAKER2);
            if (mdiresult != MDI_AUDIO_SUCCESS)
            {
                mmi_event_notify_enum event_type;
                string_id = mdi_audio_get_error_info(mdiresult, &event_type);
                result = VFX_FALSE;
            }
        }
    } while(0);

    if (buffer != NULL)
    {
        VFX_FREE_MEM(buffer);
    }

    (*str_id) = string_id;
	return result;
}

VFX_IMPLEMENT_CLASS("VappFmgrFolderSelectorCUI", VappFmgrFolderSelectorCUI, VappFmgrCUIInstance);

void VappFmgrFolderSelectorCUI::onInit()
{
    VappFmgrCUIInstance::onInit();

    m_style = VCUI_FOLDER_SELECTOR_STYLE_WRITE;

    if (m_system_folder_properity == NULL)
    {
        VFX_ALLOC_MEM(m_system_folder_properity, sizeof(vapp_fmgr_system_folder_properity_struct)*g_def_folder_table_size, this);
        resetSystemFolderProperity();
    }
}

mmi_ret VappFmgrFolderSelectorCUI::callProc(mmi_event_struct *param)
{
	return onProc(param);
}

mmi_ret VappFmgrFolderSelectorCUI::onProc(mmi_event_struct *param)
{
	mmi_ret ret = MMI_RET_OK;

    VAPP_FMGR_TRACE1(TRC_VAPP_FMGR_FOLDERSEL_ONPROC, "[VAPPFMGR] folder selector onProc, evt id %d", param->evt_id);
    
	ret = VappFmgrInstance::onProc(param);

	if (ret == MMI_RET_OK)
	{
		switch (param->evt_id)
		{
		#ifdef __MMI_USB_SUPPORT__
		    case EVT_ID_USB_ENTER_MS_MODE:
                {
                    /* Close file manager */
            		callbackApp(this, NULL, 0);
                }
                break;
		#endif
			case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
				{
					srv_fmgr_notification_dev_plug_event_struct *evt = (srv_fmgr_notification_dev_plug_event_struct*)param;

					VfxU8 i = 0;
					
					for (i = 0; i < evt->count; i++)
			        {
			        	if (evt->drv_letters[i] == (VfxU8)m_file_path.getBuf()[0])
						{
							/* Todo: Close new folder ediotr */
							if (m_action != NULL)
                            {
                                if (m_action->getAction() == VAPP_FMGR_ACTION_CREATE_FOLDER)
                                {
                                    /* Close filename editor */
                                    VFX_OBJ_CLOSE(m_action);
                                }
                            }
							
							if (m_file_path.getLength() == 3)
							{
								/* On drv page so refresh it */
								refreshMenu(VENUS_FMGRI_INDEX_ERROR_CODE, FS_MSDC_MOUNT_ERROR);
							}
							else
							{
								/* Back root */
								backRoot();
							}
							break;
			        	}
					}					 
				}
				break;
			case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
				{
					onHandleEventPlugIn(param);				 
				}
				break;

		}
	}

	return ret;
}

void VappFmgrFolderSelectorCUI::onActionRsp(VfxObject* obj, VfxS32 error_code, VfxBool no_on_confirm)
{
	VfxWString action_file_path;
	VfxS32 refresh_type = VENUS_FMGRI_INDEX_NOT_CHANGE;
	
	if (m_action == (VappFmgrGeneralOperation*)obj)
	{		
		/* Single file operation */
		if (no_on_confirm == VFX_TRUE)
		{
			/* User press No on confirm popup */
			VFX_OBJ_CLOSE(m_action);
			m_action = NULL;
		}
		else
		{
		    if (error_code < 0)
            {
                /* Show error message if action is rename or create folder */
                VfxU32 action  = m_action->getAction();
                if (action == VAPP_FMGR_ACTION_CREATE_FOLDER)
                {
                    showPopup(srv_fmgr_fs_error_get_string(error_code), VCP_POPUP_TYPE_FAILURE);
                }
            }
            else
            {
                refreshMenu(refresh_type);
            }
            
		    VFX_OBJ_CLOSE(m_action);
			m_action = NULL;
		}
	}
}

void VappFmgrFolderSelectorCUI::setMenu(VcpListMenu *listmenu)
{
	m_listmenu = listmenu;
	m_listmenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT);
	m_listmenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_FALSE);
	m_listmenu->m_signalItemTapped.connect(this, &VappFmgrFolderSelectorCUI::onTapListMenuItem);
	m_listmenu->m_signalCmdButtonClicked.connect(this, &VappFmgrFolderSelectorCUI::onClickCmdButton);

	/* Connect signal of view start and end */
	VappFmgrInstance::setMenu(listmenu);
}

void VappFmgrFolderSelectorCUI::setMenu(VcpGroupListMenu *listmenu)
{
	m_glist = listmenu;
	m_glist->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT);
	m_glist->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_FALSE);
	m_glist->m_signalItemTapped.connect(this, &VappFmgrFolderSelectorCUI::onTapGroupListMenuItem);
	m_glist->m_signalCmdButtonClicked.connect(this, &VappFmgrFolderSelectorCUI::onClickGroupCmdButton);

	/* Connect signal of view start and end */
	VappFmgrInstance::setMenu(listmenu);
}

VfxBool VappFmgrFolderSelectorCUI::getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc & image)
{	
	VfxBool result = VFX_FALSE;	
	VfxS32 fs_ret = 0;
	VappFmgrFSData *obj = getFSDataObj();
	VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;

	do {
		if (isFilePathRoot())
		{
			result = VappFmgrInstance::getItemImage(index, fieldType, image);
		}
		else
		{
			/* file list */
			if (fieldType == VCP_LIST_MENU_FIELD_ICON)
			{
				VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
				fs_ret = obj->getFileInfo(this, index, file_info);
				if (fs_ret < 0)
				{
					/* error handling */
					//vapp_fmgr_error_handling_cb(fs_ret);
					obj->setLoadFileIndex(index);
					error_handler(fs_ret);
					break;
				}		
				image.setResId(srv_fmgr_types_get_icon(file_info->file_type, NULL, SRV_FMGR_TYPES_ICON_LARGE));			
				result = VFX_TRUE;
			}
			else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL ||
                     fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED||
                     fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT)
			{
				image.setResId(IMG_ID_VAPP_FMGR_SELECT_N);
				result = VFX_TRUE;
			}
            else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_PRESSED)
            {
                image.setResId(IMG_ID_VAPP_FMGR_SELECT_P);
				result = VFX_TRUE;
            }
		}
	}while(0);

    if (file_info != NULL)
    {
        VFX_FREE_MEM(file_info);
    }
	return result;		
}

VfxBool VappFmgrFolderSelectorCUI::getItemImage(
        VcpMenuPos pos,                  // [IN] the position of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        )
{
	if (!m_isGroupListMenu)
    {
        return getItemImage(pos.pos, fieldType, image);
    }   
	
	VfxBool result = VFX_FALSE;	
	VfxS32 index = pos.pos;
	VappFmgrFSData *obj = getFSDataObj();
	VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;

	do {
		if (pos.group == 0)
		{
			/* System folder */			
			if (fieldType == VCP_LIST_MENU_FIELD_ICON)
			{						
				result = VappFmgrInstance::getItemImage(pos, fieldType, image);
			}
			else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL ||
					 fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED ||
					 fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT)
			{
				
				image.setResId(IMG_ID_VAPP_FMGR_SELECT_N);
				result = VFX_TRUE;
			}
            else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_PRESSED)
            {
                image.setResId(IMG_ID_VAPP_FMGR_SELECT_P);
				result = VFX_TRUE;
            }
		}
		else
		{
		    result = getItemImage(index, fieldType, image);
				
		}
	}while(0);

    if (file_info != NULL)
    {
        VFX_FREE_MEM(file_info);
    }
	return result;
}

void VappFmgrFolderSelectorCUI::handleTapListMenuItem(VfxS32 index, VfxS32 group)
{
	VfxS32 fs_ret = 0;
	VappFmgrFSData *fsdata = getFSDataObj();
	VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;
	
	do {
			VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
			fs_ret = fsdata->getFileInfo(this, index, file_info);

			if (fs_ret < 0)
			{
				/* error handling */
				showPopup(srv_fmgr_fs_error_get_string(fs_ret), VCP_POPUP_TYPE_FAILURE);
				VFX_FREE_MEM(file_info);
				break;
			}

        if (group == -1)
        {
            m_cur_index = index;
        }
        else
        {
            m_group_pos.group = group;
    	    m_group_pos.pos = index;
        }
            
			if (file_info->attribute & FS_ATTR_DIR)
			{
				/* Folder case */
				enterFolder(file_info->file_name);						
			}			
    	else
    	{
    		/* File case */
    		 VFX_DEV_ASSERT(0);
    	}
			VFX_FREE_MEM(file_info);
    } while(0);
		}

void VappFmgrFolderSelectorCUI::onTapListMenuItem(VcpListMenu *listmenu, VfxU32 index)
{
	handleTapListMenuItem(index);
}

void VappFmgrFolderSelectorCUI::onTapGroupListMenuItem(VcpGroupListMenu *listmenu, VcpMenuPos pos)
{
	VfxS32 fs_ret = 0;
	VappFmgrFSData *fsdata = getFSDataObj();
	VfxS32 index = pos.pos;
	
	do {
		if (fsdata != NULL)
		{
			if (pos.group == 0 && index >= 0)
			{
				/* System folder */
				fs_ret = m_system_folder_properity[index].exist;
				if (fs_ret < 0)
				{
					/* The system folder does not exist */
					/* error handling */
					showPopup(srv_fmgr_fs_error_get_string(FS_PATH_NOT_FOUND), VCP_POPUP_TYPE_FAILURE);
					break;
				}

				m_group_pos = pos;
				
				enterFolder((VfxS8*)g_def_folder_table[index].path);	
			}
			else if (pos.group == 1 && index >= 0)
			{			
				/* User defined */
				handleTapListMenuItem(index, pos.group);
			}
		}
	} while(0);
}

void VappFmgrFolderSelectorCUI::handleClickCmdButton(VfxS32 index, VfxS32 group)
{
	VfxS32 fs_ret = 0;
	VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;	
    VappFmgrFSData *fsdata = getFSDataObj();

	if (fsdata != NULL)
	{
		VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
		fs_ret = fsdata->getFileInfo(this, index, file_info);
		if (fs_ret < 0)
		{
			/* error handling */
			showPopup(srv_fmgr_fs_error_get_string(fs_ret), VCP_POPUP_TYPE_FAILURE);
			VFX_FREE_MEM(file_info);
			file_info = NULL;			
			return;
		}

        if (group != -1)
        {
    		m_select_pos.setCell(group, index);
        }
        else
        {
		m_select_index = index;
        }
		
		callbackApp(this, file_info, 1);

		if (file_info != NULL)
		{
			VFX_FREE_MEM(file_info);
		}
	}
}

void VappFmgrFolderSelectorCUI::onClickCmdButton(VcpListMenu *listmenu, VfxU32 index)
{
    handleClickCmdButton(index);
}

void VappFmgrFolderSelectorCUI::onClickGroupCmdButton(VcpGroupListMenu *listmenu, VcpMenuPos pos)
{
	VfxS32 fs_ret = FS_NO_ERROR;
	VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;	
	VfxS32 index = pos.pos;

	if (pos.group == 0)
	{
		/* System folders */
		fs_ret = m_system_folder_properity[index].exist;
		if (fs_ret < 0)
		{
			/* error handling */
			showPopup(srv_fmgr_fs_error_get_string(FS_PATH_NOT_FOUND), VCP_POPUP_TYPE_FAILURE);
			return;
		}

		m_select_pos.setCell(pos.group, index);

		callbackApp(this, file_info, 1);
	}
	else if (pos.group == 1)
	{
		/* User defined */
		handleClickCmdButton(index, pos.group);
	}
}

void VappFmgrFolderSelectorCUI::onClickToolBarButton(VfxObject* obj, VfxId button_id)
{	
	if (m_action == NULL)
	{		
		switch (button_id)
		{					
			case MENU_ID_FMGR_CANCEL:
				{					
					callbackApp(this, NULL, 0);
				}
				break;
			case MENU_ID_FMGR_OPTION_NEW_FOLDER:
				{
					VFX_OBJ_CREATE(m_action, VappFmgrGeneralOperation, this);
					m_action->setCallerInstanceId(m_id);
					m_action->setCallerGroupId(m_gid);
					m_action->setAction(VAPP_FMGR_ACTION_CREATE_FOLDER);				
					m_action->setSrcPath(m_file_path);
					m_action->m_signalActionRsp.connect(this, &VappFmgrFolderSelectorCUI::onActionRsp);
					m_action->run();
				}
				break;
			default:
				break;
		};
	}
}

void VappFmgrFolderSelectorCUI::getOptionItem(VfxU32 page_id, VfxU16 &opt_menu_id, VfxU16 &opt_menu_num)
{	
	VfxU16 opt_menu = 0;

	if (m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_DRV_PHONE_PAGE ||
		m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_DRV_MEM_PAGE ||
		m_style == VCUI_FOLDER_SELECTOR_STYLE_READ)
	{
		/* Drv tab page */
		opt_menu = MENU_ID_FMGR_OPTION_FOLDER_SELECTOR_CUI;
		resetOptMenu(opt_menu);

		mmi_frm_hide_menu_item(MENU_ID_FMGR_OPTION_NEW_FOLDER);
	}
	else if (m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_FOLDER_SELECT_PAGE)
	{
		/* General option case */		
		opt_menu = MENU_ID_FMGR_OPTION_FOLDER_SELECTOR_CUI;
		resetOptMenu(opt_menu);			
	}

	opt_menu_id = opt_menu;

	opt_menu_num = GetNumOfChild_Ext(opt_menu_id);
}

void VappFmgrFolderSelectorCUI::callbackApp(VappFmgrInstance* instance, VAPP_FMGR_FILE_INFO_STRUCT *file_info, VfxS32 result)
{
	vcui_folder_selector_result_event_struct evt;
	
	if (file_info)
    {
        ASSERT(file_info->attribute & FS_ATTR_DIR);
        
        /* Check max path */
		if (isComposeFilePathOverLen(m_file_path, file_info->file_name, VFX_FALSE))
		{
			/* popup error */
            showPopup(srv_fmgr_fs_error_get_string(FS_PATH_OVER_LEN_ERROR), VCP_POPUP_TYPE_FAILURE);
			return;
		}		
    }

    /* Dead, skip the event */
    if(instance->getFlag() & VAPP_FMGR_IFLAG_DEAD)
    {        
        return;
    }

    if (!file_info)
    {
        instance->addFlag(VAPP_FMGR_IFLAG_DEAD);
    }

    evt.evt_id = EVT_ID_VCUI_FOLDER_SELECTOR_RESULT;
    evt.size = sizeof(evt);
    evt.user_data = NULL;
    evt.sender_id = m_gid;

    evt.result = result;

	VappFmgrInstance::callbackApp((mmi_group_event_struct*)&evt);
}

VfxBool VappFmgrFolderSelectorCUI::error_handler(VfxS32 error_code, VfxS32 line)
{
	VfxBool result = VFX_FALSE;

	do {
        VAPP_FMGR_TRACE2(TRC_VAPP_FMGR_FOLDERSEL_ERR, "[VAPPFMGR]folder selector error handler, err_code %d, line %d", error_code, line);
        
		switch (error_code)
	    {
	        case VAPP_FMGRI_ERROR_FILE_LIST_IS_DIRTY:
                break;
	        case SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY:
            case SRV_FMGR_FILELIST_ERROR_BUSY:
                VappFmgrInstance::error_handler(error_code);
                break;
            case FS_DEVICE_BUSY:
                showPopup(srv_fmgr_fs_error_get_string(error_code), VCP_POPUP_TYPE_FAILURE);
                callbackApp(this, NULL, error_code);
                break;
            case FS_MSDC_MOUNT_ERROR:
	        case FS_MSDC_READ_SECTOR_ERROR:
	        case FS_MSDC_WRITE_SECTOR_ERROR:
	        case FS_MSDC_DISCARD_SECTOR_ERROR:
	        case FS_MSDC_PRESNET_NOT_READY:
	        case FS_MSDC_NOT_PRESENT:
			case FS_DRIVE_NOT_READY:
			case FS_FILE_NOT_FOUND:
	                return VFX_TRUE;

	        case FS_MEDIA_CHANGED:
	        case VAPP_FMGR_ERROR_EMPTY:
	        case FS_DRIVE_NOT_FOUND:
	            if (isFilePathRoot())
	            {
	                /* Popup error */	                					
					#ifdef __FS_CARD_SUPPORT__
						showPopup(STR_GLOBAL_INSERT_MEMORY_CARD, VCP_POPUP_TYPE_FAILURE);	
	                #else /* __FS_CARD_SUPPORT__ */
						showPopup(STR_ID_VAPP_FMGR_NO_AVAILABLE_STORAGE, VCP_POPUP_TYPE_FAILURE);
	                #endif /* __FS_CARD_SUPPORT__ */
	                callbackApp(this, NULL, error_code);
	            }
				else
				{
					return VFX_TRUE;
				}
	            break;
	        default:
	            /* Popup error */
				showPopup(srv_fmgr_fs_error_get_string(error_code), VCP_POPUP_TYPE_FAILURE);
				
	            if (isFilePathRoot())
	            {
	                callbackApp(this, NULL, error_code);
	            }
	            else
	            {
	                switch (error_code)
	                {
	                    case FS_PATH_OVER_LEN_ERROR:
	                    case FS_PATH_NOT_FOUND:
                        case FS_ABORTED_ERROR:
	                        leaveFolder(error_code);
	                        break;

	                    default:
	                        /* Move to Root */
	                        backRoot();
	                        break;
	                }
	            }
	            break;
	    }	
	} while(0);
	
	return result;
}

void VappFmgrFolderSelectorCUI::leaveFolder(S32 result)
{
	if (m_file_path.getLength() == 3 ||
        (m_flag & VCUI_FOLDER_SELECTOR_OPT_FOLDER_TRAVERSE_NONE) ||
        ((m_flag & VCUI_FOLDER_SELECTOR_OPT_FOLDER_TRAVERSE_SUB) && m_file_path.getLength() <= (S32)cust_data))
    {
        callbackApp(this, NULL, result);
    }
    else
    {
        if (m_page != NULL)
		{
			VappFmgrPage *page = (VappFmgrPage*)m_page;
            page->setExit();
			page->closePage();
			m_page = NULL;
		}
    }
}

void VappFmgrFolderSelectorCUI::leaveFolderEx(S32 result)
{
	leaveFolder(result);
}

VfxBool VappFmgrFolderSelectorCUI::isMenuItemDisable(VfxU32 page_id, VfxU16 &opt_menu_id)
{
    if (opt_menu_id == MENU_ID_FMGR_OPTION_NEW_FOLDER)
    {
        vcui_folder_selector_query_event_struct evt;

        memset(&evt, 0, sizeof(vcui_folder_selector_query_event_struct));

        evt.evt_id = EVT_ID_VCUI_FOLDER_SELECTOR_ENABLE_CREATE_FOLDER;
        evt.sender_id = m_gid;
        evt.size = sizeof(vcui_folder_selector_query_event_struct);
        evt.path = (CHAR*)m_file_path.getBuf();
        evt.menuid = opt_menu_id;

        VfxApp *app = VfxApp::getObject(m_gid);
        if (app->sendToCaller((mmi_group_event_struct*)&evt) == MMI_RET_ERR)
        {
            return VFX_TRUE;
        }        
    }
	else if (opt_menu_id == MENU_ID_FMGR_CANCEL)
	{
		return VFX_FALSE;
	}
		

    return VappFmgrInstance::isMenuItemDisable(page_id, opt_menu_id);
}

void VappFmgrFolderSelectorCUI::setStyle(vcui_folder_selector_style_enum style)
{
    m_style = style;
}

VFX_IMPLEMENT_CLASS("VappFmgrFolderBrowserLaunch", VappFmgrFolderBrowserLaunch, VappFmgrMain);

void VappFmgrFolderBrowserLaunch::onInit()
{
	VappFmgrMain::onInit();	
}

void VappFmgrFolderBrowserLaunch::onDeinit()
{
	VappFmgrMain::onDeinit();
}

void VappFmgrFolderBrowserLaunch::closeMySelf()
{
    VfxApp *app = VfxApp::getObject(m_gid);
	if (app != NULL)
	{
		app->exit();
	}
}

mmi_ret VappFmgrFolderBrowserLaunch::callProc(mmi_event_struct *param)
{
	return onProc(param);
}

mmi_ret VappFmgrFolderBrowserLaunch::onProc(mmi_event_struct *param)
{
	mmi_ret ret = MMI_RET_OK;

    VAPP_FMGR_TRACE1(TRC_VAPP_FMGR_FOLDERLAUNCH_ONPROC, "[VAPPFMGR] folder launch onProc, evt id %d", param->evt_id);
    
	ret = VappFmgrInstance::onProc(param);

	if (ret == MMI_RET_OK)
	{
		switch (param->evt_id)
		{
		#ifdef __MMI_USB_SUPPORT__
		    case EVT_ID_USB_ENTER_MS_MODE:
                {
                    callbackApp(this, NULL, 0);
                }
                break;
		#endif
			case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
				{
					srv_fmgr_notification_dev_plug_event_struct *evt = (srv_fmgr_notification_dev_plug_event_struct*)param;

					VfxU8 i = 0;
					
					for (i = 0; i < evt->count; i++)
			        {
			        	if (evt->drv_letters[i] == (VfxU8)m_file_path.getBuf()[0])
						{
							callbackApp(this, NULL, 0);
							break;
			        	}
					}					 
				}
				break;
		}
	}

	return ret;
}

void VappFmgrFolderBrowserLaunch::setMenu(VcpListMenu *listmenu)
{
    m_listmenu = listmenu;
    m_listmenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT);
#if !defined(__COSMOS_SLIM_FMGR_MT6260__)
    m_listmenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_FALSE);
    m_listmenu->m_signalCmdButtonClicked.connect(this, &VappFmgrMain::onClickCmdButton);
#else
    m_listmenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL, VFX_FALSE);
#endif // VCP_LIST_MENU_CONTROL_MODE_NORMAL
    m_listmenu->m_signalItemTapped.connect(this, &VappFmgrMain::onTapListMenuItem);

    /* Connect signal of view start and end */
    VappFmgrInstance::setMenu(listmenu);
}

VfxBool VappFmgrFolderBrowserLaunch::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString & text, VcpListMenuTextColorEnum & color)
{
	VfxBool result = VFX_FALSE;
	VappFmgrFSData *obj = getFSDataObj();
	VfxS32 fs_ret = 0;
	VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;

	do {
		if (obj != NULL)
		{
			/* file list */
			VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
			fs_ret = obj->getFileInfo(this, index, file_info);
			if (fs_ret < 0)
			{
				/* error handling */						
				obj->setLoadFileIndex(index);
				if (error_handler(fs_ret) && fieldType == VCP_LIST_MENU_FIELD_TEXT)
				{
					text.loadFromRes(STR_ID_VAPP_FMGR_NO_DATA);
					color = VCP_LIST_MENU_TEXT_COLOR_DISABLED;
					result = VFX_TRUE;
				}
				break;
			}
			if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
			{
				/* Main text */
                if (file_info->file_type == FMGR_TYPE_DAF)
                {
                    VfxS8 *buffer = NULL;
                    VFX_ALLOC_MEM(buffer, VAPP_FMGR_FILE_PATH_LEN, this);
                    app_ucs2_strncpy((kal_int8*)buffer, (const kal_int8*)file_info->file_name, SRV_FMGR_PATH_MAX_LEN);
                    srv_fmgr_path_hide_extension((WCHAR*)buffer);
                    text.loadFromMem((VfxWChar*)buffer);
                    VFX_FREE_MEM(buffer);
                }
                else
                {
				    text.loadFromMem((VfxWChar*)file_info->file_name);
                }			
			}
			else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
			{
				/* Sub text1: display size */
				if (file_info->attribute& FS_ATTR_DIR)
				{
					/* If it is folder, do not show sub text */
                    break;
				}
				else
				{
					getSizeString(text, file_info->file_size);
				}										
			}
			else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT2)
			{
				/* Sub text2: display modified time */
				text = VfxWString().format("%d-%d-%d %d:%d", file_info->time.nYear,
				                           file_info->time.nMonth, file_info->time.nDay,
				                           file_info->time.nHour, file_info->time.nMin);
			}
			result = VFX_TRUE;
		}
	} while(0);

	if (file_info != NULL)
	{
		VFX_FREE_MEM(file_info);
	}
	return result;
}

VfxBool VappFmgrFolderBrowserLaunch::getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc & image)
{	
	VfxBool result = VFX_FALSE;	
	VfxS32 fs_ret = 0;
	VappFmgrFSData *obj = getFSDataObj();
	VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;

	do {
		if (isFilePathRoot())
		{
			result = VappFmgrInstance::getItemImage(index, fieldType, image);
		}
		else
		{
			/* file list */
			VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
		    fs_ret = obj->getFileInfo(this, index, file_info);
		    if (fs_ret < 0)
		    {
			    /* error handling */
			    //vapp_fmgr_error_handling_cb(fs_ret);
			    obj->setLoadFileIndex(index);
			    error_handler(fs_ret);
			    break;
		    }
			
			if (fieldType == VCP_LIST_MENU_FIELD_ICON)
			{
				image.setResId(srv_fmgr_types_get_icon(file_info->file_type, NULL, SRV_FMGR_TYPES_ICON_LARGE));			
				result = VFX_TRUE;
			}
#if !defined(__COSMOS_SLIM_FMGR_MT6260__)
			else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL ||
                     fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED||
                     fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT ||
                     fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_PRESSED)
			{
				image.setResId(IMG_ID_VAPP_FMGR_DETAIL_INFO);
				result = VFX_TRUE;
			}            
#endif // !defined(__COSMOS_SLIM_FMGR_MT6260__)
		}
	}while(0);

    if (file_info != NULL)
    {
        VFX_FREE_MEM(file_info);
    }
    
	return result;		
} 

VfxBool VappFmgrFolderBrowserLaunch::getItemIsDisabled(
        VfxU32 index       // [IN] the index of item
        ) const
{
	VfxBool result = VFX_FALSE;
	
	result = m_context->isDisabled(0, index);

	return result;
}

void VappFmgrFolderBrowserLaunch::onClickToolBarButton(VfxObject* obj, VfxId button_id)
{	
    if (m_action == NULL)
    {
        switch (button_id)
        {
            case MENU_ID_FMGR_CANCEL:
            {
                callbackApp(this, NULL, 0);
                break;
            }

            default:
                VappFmgrMain::onClickToolBarButton(obj, button_id);
            break;
        };
    }
}

void VappFmgrFolderBrowserLaunch::getOptionItem(VfxU32 page_id, VfxU16 &opt_menu_id, VfxU16 &opt_menu_num)
{
    VfxU16 opt_menu = 0;

    if (page_id == VappFmgrPage::VAPP_FMGR_DRAW_FILE_DETAIL_PAGE)
    {
        opt_menu = MENU_ID_FMGR_SINGLE_GEN_OPTIONS;
    	resetOptMenu(opt_menu);

        /* Only show "Open", "Delete", "Share" */
        mmi_frm_hide_menu_item(MENU_ID_FMGR_OPTION_SHARE_SINGLE);
        mmi_frm_hide_menu_item(MENU_ID_FMGR_OPTION_MOVE_TO);
        mmi_frm_hide_menu_item(MENU_ID_FMGR_OPTION_COPY_TO);
    }
    else if (page_id == VappFmgrPage::VAPP_FMGR_DRAW_FOLDER_BROWSER_LAUNCH_PAGE)
    {
        opt_menu = MENU_ID_FMGR_GEN_OPTIONS;
    	resetOptMenu(opt_menu);

        /* Only show "Delete" */
        mmi_frm_hide_menu_item(MENU_ID_FMGR_OPTION_NEW_FOLDER);
        mmi_frm_hide_menu_item(MENU_ID_FMGR_OPTION_SHARE);
        mmi_frm_hide_menu_item(MENU_ID_FMGR_OPTION_MOVE);
        mmi_frm_hide_menu_item(MENU_ID_FMGR_OPTION_COPY);
#if defined( __FS_SORT_SUPPORT__) && !defined(__COSMOS_SLIM_FMGR_MT6260__)
        mmi_frm_hide_menu_item(MENU_ID_FMGR_OPTION_SORT);
#endif
    }
    
    opt_menu_id = opt_menu;

    opt_menu_num = GetNumOfChild_Ext(opt_menu_id);
}

void VappFmgrFolderBrowserLaunch::callbackApp(VappFmgrInstance* instance, VAPP_FMGR_FILE_INFO_STRUCT *file_info, VfxS32 result)
{
    vcui_folder_browser_launch_result_event_struct evt;

    memset(&evt, 0, sizeof(vcui_folder_browser_launch_result_event_struct));

    /* Dead, skip the event */
    if(instance->getFlag() & VAPP_FMGR_IFLAG_DEAD)
    {        
        return;
    }

    if (!file_info)
    {
        instance->addFlag(VAPP_FMGR_IFLAG_DEAD);
    }

    evt.evt_id = EVT_ID_VCUI_FOLDER_BROWSER_LAUNCH_QUIT;
    evt.size = sizeof(evt);
    evt.user_data = NULL;
    evt.sender_id = m_gid;

    evt.result = result;

	VappFmgrInstance::callbackApp((mmi_group_event_struct*)&evt);
    
	closeMySelf();
}

VfxBool VappFmgrFolderBrowserLaunch::error_handler(VfxS32 error_code, VfxS32 line)
{
	VfxBool result = VFX_FALSE;

	do {
        VAPP_FMGR_TRACE3(TRC_VAPP_FMGR_FOLDERLAUNCH_ERR, "[VAPPFMGR]folder launch error handler, err_code %d, line %d, display_style %d", error_code, line, m_display_style);
        
		switch (error_code)
	    {
            case VAPP_FMGRI_ERROR_FILE_LIST_IS_DIRTY:
                {
                    if (m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE)
                    {
                        closeMarkSeveral();

                        /* If action is waitting for confirm, close it */
                        if (m_action != NULL && m_action->getWaitConfirm())
                        {
                            VFX_OBJ_CLOSE(m_action);
                            m_action = NULL;
                        }
                        
                        showPopup(STR_ID_VAPP_FMGR_FILE_LIST_IS_DIRTY, VCP_POPUP_TYPE_WARNING);
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
							page->getPageId() == VappFmgrPage::VAPP_FMGR_DRAW_FOLDER_BROWSER_LAUNCH_PAGE)
						{
							/* In page is in file list */
							/* Close long tap option */
							if (m_opt_menu != NULL)
							{
								VFX_OBJ_CLOSE(m_opt_menu);
							}
							doFileListDirtyErrorHandle();
						}
					}
                }
                break;
	        case SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY:
            case SRV_FMGR_FILELIST_ERROR_BUSY:
                VappFmgrInstance::error_handler(error_code);
                break;
            case FS_MSDC_MOUNT_ERROR:
	        case FS_MSDC_READ_SECTOR_ERROR:
	        case FS_MSDC_WRITE_SECTOR_ERROR:
	        case FS_MSDC_DISCARD_SECTOR_ERROR:
	        case FS_MSDC_PRESNET_NOT_READY:
	        case FS_MSDC_NOT_PRESENT:
			case FS_DRIVE_NOT_READY:
	                return VFX_TRUE;

	        case FS_MEDIA_CHANGED:
	        case VAPP_FMGR_ERROR_EMPTY:
	        case FS_DRIVE_NOT_FOUND:
	            if (isFilePathRoot())
	            {
	                /* Popup error */	                					
					#ifdef __FS_CARD_SUPPORT__
						showPopup(STR_GLOBAL_INSERT_MEMORY_CARD, VCP_POPUP_TYPE_FAILURE);	
	                #else /* __FS_CARD_SUPPORT__ */
						showPopup(STR_ID_VAPP_FMGR_NO_AVAILABLE_STORAGE, VCP_POPUP_TYPE_FAILURE);
	                #endif /* __FS_CARD_SUPPORT__ */
	                callbackApp(this, NULL, error_code);
	            }
				else
				{
					return VFX_TRUE;
				}
	            break;
	        default:
	            /* Popup error */
				/*
				if (!m_closed)
				{
					mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)GetString(STR_ID_VAPP_FMGR_FILE_LIST_IS_DIRTY));
	                callbackApp(this, NULL, error_code);
				}
				*/
				result = VFX_TRUE;
	            break;
	    }	
	} while(0);
	
	return result;
}

void VappFmgrFolderBrowserLaunch::leaveFolder(S32 result)
{
	callbackApp(this, NULL, result);
}

void VappFmgrFolderBrowserLaunch::leaveFolderEx(S32 result)
{
	leaveFolder(result);
}
// For media picker
mmi_id vcui_fmgr_media_picker_create(mmi_id caller, const WCHAR* start_path, const FMGR_FILTER* filter, 
                                vcui_fmgr_media_picker_style_enum style, U32 option_flag)
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

    arg.flag = option_flag;
    arg.style = style;
    app_ucs2_strncpy((kal_int8*)arg.file_path, (const kal_int8*)start_path, sizeof(arg.file_path));
    arg.app_type = VappFmgrInstance::VAPP_FMGR2_TYPE_MEDIA_PICKER;
    FMGR_FILTER_INIT(&arg.filter_type);
    memcpy(&arg.filter_type, filter, sizeof(FMGR_FILTER));

    return VfxAppLauncher::createCui( 
                            VCUI_FMGR,
                            VFX_OBJ_CLASS_INFO(VappFmgrCui),
                            caller,
                            &arg,
                            sizeof(vapp_fmgr_launch_args));

}

S32 vcui_fmgr_media_picker_get_picked_num(mmi_id cui_id)
{
    VappFmgrInstance *instance = VappFmgrInstance::cui_basic_check(cui_id, VappFmgrInstance::VAPP_FMGR2_TYPE_MEDIA_PICKER);
    if (instance)
    {
        VappFmgrCUIInstance *pickerCUI = (VappFmgrCUIInstance*)instance;
        return pickerCUI->getPickedNum();
    }

    return VAPP_FMGR_ERROR_INVALID_PARAM;

}

S32 vcui_fmgr_media_picker_get_picked_path(mmi_id cui_id, vcui_fmgr_media_path_struct* pathArray, U32 picked_num)
{
    VappFmgrInstance *instance = VappFmgrInstance::cui_basic_check(cui_id, VappFmgrInstance::VAPP_FMGR2_TYPE_MEDIA_PICKER);
    if (instance)
    {
        VappFmgrCUIInstance *cui = (VappFmgrCUIInstance*)instance;
        return cui->getPickedPathes(cui_id, VappFmgrInstance::VAPP_FMGR2_TYPE_MEDIA_PICKER, pathArray, picked_num);
    }

    return VAPP_FMGR_ERROR_INVALID_PARAM;
}


VFX_IMPLEMENT_CLASS("VappFmgrMediaPickerCUI", VappFmgrMediaPickerCUI, VappFmgrCUIInstance);
void VappFmgrMediaPickerCUI::onInit()
{
    VappFmgrCUIInstance::onInit();

    m_style = VCUI_FMGR_MEDIA_PICKER_STYLE_READ;

    if (m_system_folder_properity == NULL)
    {
        VFX_ALLOC_MEM(m_system_folder_properity, sizeof(vapp_fmgr_system_folder_properity_struct)*g_def_folder_table_size, this);
        resetSystemFolderProperity();
    }
}

mmi_ret VappFmgrMediaPickerCUI::callProc(mmi_event_struct *param)
{
    return onProc(param);
}

mmi_ret VappFmgrMediaPickerCUI::onProc(mmi_event_struct *param)
{
    VAPP_FMGR_TRACE1(TRC_VAPP_FMGR_FOLDERSEL_ONPROC, "[VAPPFMGR] media picker onProc, evt id %d", param->evt_id);

    mmi_ret ret = VappFmgrInstance::onProc(param);

    if (ret == MMI_RET_OK)
    {
        switch (param->evt_id)
        {
        #ifdef __MMI_USB_SUPPORT__
            case EVT_ID_USB_ENTER_MS_MODE:
            {
                /* Close file manager */
                callbackApp(this, NULL, 0);
                break;
            }
        #endif
        
            case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
            {
                srv_fmgr_notification_dev_plug_event_struct *evt = (srv_fmgr_notification_dev_plug_event_struct*)param;

                for (VfxS32 i = 0; i < evt->count; ++i)
                {
                    if (evt->drv_letters[i] == (VfxU8)m_file_path.getBuf()[0])
                    {
                        if (m_file_path.getLength() == 3)
                        {
                            /* On drv page so refresh it */
                            refreshMenu(VENUS_FMGRI_INDEX_ERROR_CODE, FS_MSDC_MOUNT_ERROR);
                        }
                        else
                        {
                            /* Back root */
                            backRoot();
                        }
                        break;
                    }
                }
                break;
            }

            case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
            {
                onHandleEventPlugIn(param);
                break;
            }

            default:
                break;
        }
    }

    return ret;
}

void VappFmgrMediaPickerCUI::setMenu(VcpListMenu *listmenu)
{
    m_listmenu = listmenu;
    m_listmenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT);
    m_listmenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_FALSE);
    m_listmenu->m_signalItemTapped.connect(this, &VappFmgrMediaPickerCUI::onTapListMenuItem);
    m_listmenu->m_signalCmdButtonClicked.connect(this, &VappFmgrMediaPickerCUI::onClickCmdButton);

    /* Connect signal of view start and end */
    VappFmgrInstance::setMenu(listmenu);
}

void VappFmgrMediaPickerCUI::setMenu(VcpGroupListMenu *listmenu)
{
    m_glist = listmenu;
    m_glist->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT);
    m_glist->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_FALSE);
    m_glist->m_signalItemTapped.connect(this, &VappFmgrMediaPickerCUI::onTapGroupListMenuItem);
    m_glist->m_signalCmdButtonClicked.connect(this, &VappFmgrMediaPickerCUI::onClickGroupCmdButton);

    /* Connect signal of view start and end */
    VappFmgrInstance::setMenu(listmenu);
}

VfxBool VappFmgrMediaPickerCUI::getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc & image)
{
    VfxBool result = VFX_FALSE;
    VappFmgrFSData *obj = getFSDataObj();
    VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;

    do {        
        VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
        VfxS32 fs_ret = obj->getFileInfo(this, index, file_info);
        if (fs_ret < 0)
        {
            /* error handling */
            //vapp_fmgr_error_handling_cb(fs_ret);
            obj->setLoadFileIndex(index);
            error_handler(fs_ret);
            break;
        }
        /* file list */
        if (fieldType == VCP_LIST_MENU_FIELD_ICON)
        {
            image.setResId(srv_fmgr_types_get_icon(file_info->file_type, NULL, SRV_FMGR_TYPES_ICON_LARGE));
            result = VFX_TRUE;
        }
        else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL ||
            fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED ||
            fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT)
        {
            if (file_info->attribute & FS_ATTR_DIR)
            {
                image.setResId(IMG_ID_VAPP_FMGR_SELECT_N);
            }
            else
            {
                image.setNull();
            }

            result = VFX_TRUE;
        }
        else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_PRESSED)
        {
            if (file_info->attribute & FS_ATTR_DIR)
             {
                 image.setResId(IMG_ID_VAPP_FMGR_SELECT_N);
             }
             else
             {
                 image.setNull();
             }
            
             result = VFX_TRUE;
        }    
    }while(0);

    if (file_info != NULL)
    {
        VFX_FREE_MEM(file_info);
    }
    return result;
}

VcpListMenuItemStateEnum VappFmgrMediaPickerCUI::getItemState(VfxU32 index) const
{	
    VcpListMenuItemStateEnum ret = VCP_LIST_MENU_ITEM_STATE_UNSELECTED;

    do {
        if (NULL == m_context)
            break;

        if (NULL != m_ms && 
        (m_ms->isMarked(m_context, index) >= VappFmgrMultiSelect::VAPP_FMGR_MSA_ERROR_NONE))
            ret = VCP_LIST_MENU_ITEM_STATE_SELECTED;
    } while(0);

    return ret;
}

VfxBool VappFmgrMediaPickerCUI::getItemImage(
        VcpMenuPos pos,                  // [IN] the position of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        )
{
    if (!m_isGroupListMenu)
    {
        return getItemImage(pos.pos, fieldType, image);
    }   

    VfxBool result = VFX_FALSE;

    do {
        if (pos.group == 0)
        {
            /* System folder */
            if (fieldType == VCP_LIST_MENU_FIELD_ICON)
            {
                result = VappFmgrInstance::getItemImage(pos, fieldType, image);
            }
            else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL ||
            fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED ||
            fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT)
            {
                image.setResId(IMG_ID_VAPP_FMGR_SELECT_N);
                result = VFX_TRUE;
            }
            else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_PRESSED)
            {
                image.setResId(IMG_ID_VAPP_FMGR_SELECT_P);
                result = VFX_TRUE;
            }
        }
        else
        {
            result = getItemImage(pos.pos, fieldType, image);
        }
    }while(0);

    return result;
}

void VappFmgrMediaPickerCUI::handleTapListMenuItem(VfxS32 index, VfxS32 group)
{
    VfxS32 fs_ret = 0;
    VappFmgrFSData *fsdata = getFSDataObj();
    VAPP_FMGR_FILE_INFO_STRUCT *file_info = NULL;

    do {
        VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
        fs_ret = fsdata->getFileInfo(this, index, file_info);

        if (fs_ret < 0)
        {
            /* error handling */
            showPopup(srv_fmgr_fs_error_get_string(fs_ret), VCP_POPUP_TYPE_FAILURE);
            VFX_FREE_MEM(file_info);
            break;
        }
        if (VappFmgrPage::VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE == m_display_style)
        {
            if (m_ms == NULL)
            {                   
                VFX_OBJ_CREATE(m_ms, VappFmgrMultiSelect, this);
                m_ms->createMSA(fsdata->getCount());
            }

            VfxS16 idx = m_ms->isMarked(this, index);
            if (VappFmgrMultiSelect::VAPP_FMGR_MSA_ERROR_FILE_NOT_FOUND != idx)
            {
                m_ms->remove_by_array_idx(this, idx);
                m_ms->setSelectallFlag(VFX_FALSE);
                if (m_ms->getCount() == 0 || (m_ms->getAllowToMarkCount() - m_ms->getCount()) == 1)
                {
                    /* update option menu */
                    VappFmgrPage *page = (VappFmgrPage*)m_page;
                    if (page != NULL)
                    {
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

                fs_ret = m_ms->add(this, index, flag);
                if (fs_ret < 0)
                {
                    break;
                }

                VfxU32 marked_count = m_ms->getCount();
                VfxBool isAllPicked = marked_count == m_ms->getAllowToMarkCount();

                if (marked_count == 1 || isAllPicked)
                {
                    if (isAllPicked)
                    {
                        m_ms->setSelectallFlag(VFX_TRUE);
                    }
                    /* update option menu */
                    VappFmgrPage *page = (VappFmgrPage*)m_page;
                    if (page != NULL)
                    {
                        page->updatePageOptionMenu(this, m_display_style);
                    }
                }
            }
        }
        else
        {
            if (file_info->attribute & FS_ATTR_DIR)
            {
                /* Folder case */
                enterFolder(file_info->file_name);
            }
        }

        if (group == -1)
        {
            m_cur_index = index;
        }
        else
        {
            m_group_pos.group = group;
            m_group_pos.pos = index;
        }
        
        VFX_FREE_MEM(file_info);
    } while(0);
}

void VappFmgrMediaPickerCUI::onTapListMenuItem(VcpListMenu *listmenu, VfxU32 index)
{
    handleTapListMenuItem(index);
}

void VappFmgrMediaPickerCUI::onTapGroupListMenuItem(VcpGroupListMenu *listmenu, VcpMenuPos pos)
{
    VappFmgrFSData *fsdata = getFSDataObj();
    VfxS32 index = pos.pos;

    do {
        if (NULL == fsdata || index < 0)
            break;
        
        if (pos.group == 0)
        {
            /* System folder */
            VfxS32 fs_ret = m_system_folder_properity[index].exist;
            if (fs_ret < 0)
            {
                /* The system folder does not exist */
                /* error handling */
                showPopup(srv_fmgr_fs_error_get_string(FS_PATH_NOT_FOUND), VCP_POPUP_TYPE_FAILURE);
                break;
            }

            m_group_pos = pos;
            enterFolder((VfxS8*)g_def_folder_table[index].path);
        }
        else if (pos.group == 1)
        {
            /* User defined */
            handleTapListMenuItem(index, pos.group);
        }
    } while(0);
}

void VappFmgrMediaPickerCUI::handleClickCmdButton(VfxS32 index, VfxS32 group)
{
    VappFmgrFSData *fsdata = getFSDataObj();

    if (fsdata == NULL)
        return ;

    VAPP_FMGR_FILE_INFO_STRUCT *file_info;
    VFX_ALLOC_MEM(file_info, sizeof(VAPP_FMGR_FILE_INFO_STRUCT), this);
    VfxS32 fs_ret = fsdata->getFileInfo(this, index, file_info);
    
    if (fs_ret < 0)
    {
        /* error handling */
        showPopup(srv_fmgr_fs_error_get_string(fs_ret), VCP_POPUP_TYPE_FAILURE);
        VFX_FREE_MEM(file_info);
        file_info = NULL;
        return;
    }

    if (group != -1)
    {
        m_select_pos.setCell(group, index);
    }
    else
    {
        m_select_index = index;
    }

    callbackApp(this, file_info, 1);

    if (file_info != NULL)
    {
        VFX_FREE_MEM(file_info);
    }

}

void VappFmgrMediaPickerCUI::onClickCmdButton(VcpListMenu *listmenu, VfxU32 index)
{
    handleClickCmdButton(index);
}

void VappFmgrMediaPickerCUI::onClickGroupCmdButton(VcpGroupListMenu *listmenu, VcpMenuPos pos)
{
    VfxS32 index = pos.pos;
    if (pos.group == 0)
    {
        /* System folders */
        VfxS32 fs_ret = m_system_folder_properity[index].exist;
        if (fs_ret < 0)
        {
        /* error handling */
        showPopup(srv_fmgr_fs_error_get_string(FS_PATH_NOT_FOUND), VCP_POPUP_TYPE_FAILURE);
        return;
        }

        m_select_pos.setCell(pos.group, index);

        callbackApp(this, NULL, 1);
    }
    else if (pos.group == 1)
    {
        /* User defined */
        handleClickCmdButton(index, pos.group);
    }
}

void VappFmgrMediaPickerCUI::closeMarkSeveral(void)
{
    /* Close Mark Several Page */
    m_display_style = VappFmgrPage::VAPP_FMGR_DRAW_MEDIA_PICKER_PAGE;

    if (m_listmenu != NULL)
    {
        m_listmenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
        m_listmenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON);
        /* Update title and option menu */
        VappFmgrPage* page = (VappFmgrPage*)m_page;
        if (page != NULL && page->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrPage)))
        {
            VfxU32 tableIdx = page->convertPageIdToCPTabIndex(m_display_style);
            page->updatePageTitle(this, tableIdx);
            VfxU16 removed_opt_menu = MENU_ID_FMGR_OPTION_MULTI_SELECT;
            page->removeAllButtonsFromToolbar(removed_opt_menu);
            page->updatePageOptionMenu(this, tableIdx);
        }

#ifdef __VAPP_FMGR_DIR_CTRL__
        /* Unlock dir cache slot */
        FS_HANDLE fh = FS_Open((WCHAR*)m_file_path.getBuf(), FS_READ_ONLY | FS_OPEN_SHARED | FS_OPEN_DIR);
        if(fh >= 0)
        {
            FS_DirCtrl(fh, FS_DIRCTRL_DATA_UNLOCK, NULL);
            FS_Close(fh);
        }
#endif
    }

    if (m_ms != NULL)
    {
        VFX_OBJ_CLOSE(m_ms);
    }
}

void VappFmgrMediaPickerCUI::onClickConfirmButton(VfxObject* obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
#ifdef __MMI_OPP_SUPPORT__    
        callbackApp(this, NULL, m_ms->getCount());
#endif        
    }
    else if (id == VCP_CONFIRM_POPUP_BUTTON_USER_2)
    {
        /* User wouldn't like to do BT send so close multi option */
        closeMarkSeveral();
    }
}

void VappFmgrMediaPickerCUI::onClickMarkToolbarButton(VfxObject* obj, VfxId button_id)
{
    if (m_action == NULL)
    {       
        switch (button_id)
        {
            case MENU_ID_FMGR_OPTION_SELECT_ALL:
            {
                VappFmgrFSData *fsdata = getFSDataObj();
                if (fsdata == NULL)
                    break;
                
                VfxS32 selected_num = fsdata->getCount();
                if (m_ms == NULL)
                {                   
                    VFX_OBJ_CREATE(m_ms, VappFmgrMultiSelect, this);
                    m_ms->createMSA(selected_num);
                }

                m_ms->Selectall(selected_num, 0);

                VappFmgrPage *page = NULL;
                if (m_page != NULL)
                {
                    page = (VappFmgrPage*)m_page;
                    page->updatePage(this, page->getPageId(), m_cur_index, VFX_TRUE);
                }
                break;
            }
            // Set list menu style as normal list      
            case MENU_ID_FMGR_CANCEL:
            {
                closeMarkSeveral();
                break;
            }

            case MENU_ID_FMGR_OPTION_UNSELECT_ALL:
            {
                if (m_ms != NULL)
                {
                    m_ms->remove_all(this);

                    if (m_page != NULL)
                    {
                        VappFmgrPage *page = (VappFmgrPage*)m_page;
                        page->updatePage(this, page->getPageId(), m_cur_index, VFX_TRUE);
                    }
                }
                break;
            }
            
            case MENU_ID_FMGR_OPTION_ADD:
            {
                if (!m_ms->getSelectAllFlag() && m_ms->getCount() > MMI_FMGR_MEDIA_PICKER_MAX_NUM)
                {
                    showPopup(STR_ID_VAPP_FMGR_MEDIA_PICKER_BEYOND_LIMIT_Q, VCP_POPUP_TYPE_WARNING, VCP_CONFIRM_BUTTON_SET_USER_DEFINE, 
                                STR_GLOBAL_ADD, STR_GLOBAL_CANCEL);
                }
                else
                {
                    callbackApp(this, NULL, 1);
                }
                break;
            }

            default:
            break;
        };
    }
}

void VappFmgrMediaPickerCUI::onClickViewToolbarButton(VfxObject* obj, VfxId button_id)
{
    switch (button_id)
    {
       case MENU_ID_FMGR_CANCEL:
       {
           callbackApp(this, NULL, 0);
            break;
       }
       
        case MENU_ID_FMGR_OPTION_SELECT:
        {
            VfxU16 opt_menu = MENU_ID_FMGR_OPTION_MULTI_SELECT;
            resetOptMenu(opt_menu);
            const VfxU16 opt_menu_num = GetNumOfChild(opt_menu);

            for (VfxU32 i = 2; i < opt_menu_num-2; ++i)
            {
                /* skip Select all, Unselect all , add and cancel */
                VfxU16 child_id = GetSeqItemId(opt_menu, i);
                if (child_id != button_id)
                {
                    mmi_frm_hide_menu_item(child_id);
                }
            }

            m_curMenuId = opt_menu;
            m_ms_title_id = STR_ID_VAPP_FMGR_APP_TITLE;
            if (m_listmenu != NULL)
            {
                m_display_style = VappFmgrPage::VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE;
                m_listmenu->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_TRUE);
                m_listmenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL, VFX_FALSE);

                /* Update title and option menu */
                VappFmgrPage* page = (VappFmgrPage*)m_page;
                if (page != NULL && page->isKindOf(VFX_OBJ_CLASS_INFO(VappFmgrPage)))
                {
                    page->updatePageTitle(this, m_display_style);
                    VfxU16 removed_opt_menu = MENU_ID_FMGR_OPTION_MEDIA_PICKER_CUI;
                    page->removeAllButtonsFromToolbar(removed_opt_menu);
                    page->updatePageOptionMenu(this, m_display_style);
                }

                if (m_ms == NULL)
                {
                    VFX_OBJ_CREATE(m_ms, VappFmgrMultiSelect, this);
                    VappFmgrFSData *fsdata = getFSDataObj();
                    
                    if (fsdata != NULL)
                    {
                        m_ms->createMSA(fsdata->getCount());
                        m_ms->setAllowToMarkCount(fsdata->getCount());
                    }
                }
        #ifdef __VAPP_FMGR_DIR_CTRL__
                /* lock dir cache */
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

       default:
       break;
    }
}

void VappFmgrMediaPickerCUI::onClickToolBarButton(VfxObject* obj, VfxId button_id)
{
    if (m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE)
    {
        onClickMarkToolbarButton(obj, button_id);
    }
    else
    {
        onClickViewToolbarButton(obj, button_id);
    }
}

void VappFmgrMediaPickerCUI::getMarkOptionItem(VfxU32 page_id, VfxU16 &opt_menu_id, VfxU16 &opt_menu_num)
{
    if (m_curMenuId != MENU_ID_FMGR_OPTION_MULTI_SELECT)
        return;

    VfxBool pickedAll = VFX_FALSE;
    if (m_ms != 0)
    {
        if (m_ms->getCount() == m_ms->getAllowToMarkCount() &&
            m_ms->getCount() > 0)
        {
            pickedAll = VFX_TRUE;
        }
    }

    if (pickedAll)
    {
        mmi_frm_unhide_menu_item(MENU_ID_FMGR_OPTION_UNSELECT_ALL);
        mmi_frm_hide_menu_item(MENU_ID_FMGR_OPTION_SELECT_ALL);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_FMGR_OPTION_SELECT_ALL);
        mmi_frm_hide_menu_item(MENU_ID_FMGR_OPTION_UNSELECT_ALL);
    }

    // hidden not necessery item.
    mmi_frm_hide_menu_item(MENU_ID_FMGR_OPTION_SHARE);
    mmi_frm_hide_menu_item(MENU_ID_FMGR_OPTION_DELETE);
    mmi_frm_hide_menu_item(MENU_ID_FMGR_OPTION_COPY);
    mmi_frm_hide_menu_item(MENU_ID_FMGR_OPTION_MOVE);
    
    opt_menu_id = m_curMenuId;
    opt_menu_num = GetNumOfChild_Ext(m_curMenuId);
}
void VappFmgrMediaPickerCUI::getViewOptionItem(VfxU32 page_id, VfxU16 &opt_menu_id, VfxU16 &opt_menu_num)
{
    VfxU16 opt_menu = 0;

    if ((m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_DRV_PHONE_PAGE ||
        m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_DRV_MEM_PAGE) &&
        m_style == VCUI_FMGR_MEDIA_PICKER_STYLE_READ)
    {
        /* Drv tab page */
        opt_menu = MENU_ID_FMGR_OPTION_MEDIA_PICKER_CUI;
        resetOptMenu(opt_menu);

        mmi_frm_hide_menu_item(MENU_ID_FMGR_OPTION_SELECT);
    }
    else if (m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_MEDIA_PICKER_PAGE)
    {
        /* General option case */
        opt_menu = MENU_ID_FMGR_OPTION_MEDIA_PICKER_CUI;
        resetOptMenu(opt_menu);
    }

    opt_menu_id = opt_menu;
    opt_menu_num = GetNumOfChild_Ext(opt_menu_id);
}

void VappFmgrMediaPickerCUI::getOptionItem(VfxU32 page_id, VfxU16 &opt_menu_id, VfxU16 &opt_menu_num)
{
    if (m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE)
    {
        getMarkOptionItem(page_id, opt_menu_id, opt_menu_num);
    }
    else
    {
        getViewOptionItem(page_id, opt_menu_id, opt_menu_num);
    }
}

void VappFmgrMediaPickerCUI::callbackApp(VappFmgrInstance* instance, VAPP_FMGR_FILE_INFO_STRUCT *file_info, VfxS32 result)
{
    /* Dead, skip the event */
    if(instance->getFlag() & VAPP_FMGR_IFLAG_DEAD)
        return;

    if (!file_info)
    {
        instance->setFlag((VfxU32)VAPP_FMGR_IFLAG_DEAD);
    }
    else
    {        
        /* Check max path */
        if (isComposeFilePathOverLen(m_file_path, file_info->file_name, VFX_FALSE))
        {
            /* popup error */
            showPopup(srv_fmgr_fs_error_get_string(FS_PATH_OVER_LEN_ERROR), VCP_POPUP_TYPE_FAILURE);
            return;
        }
    }

    vcui_fmgr_media_picker_event_struct evt;
    evt.evt_id = EVT_ID_VCUI_FMGR_MEDIA_PICKER_RESULT;
    evt.size = sizeof(evt);
    evt.user_data = NULL;
    evt.sender_id = m_gid;
    evt.result = result;

    VappFmgrInstance::callbackApp((mmi_group_event_struct*)&evt);
}

VfxBool VappFmgrMediaPickerCUI::error_handler(VfxS32 error_code, VfxS32 line)
{
	VfxBool result = VFX_FALSE;

	do {
        VAPP_FMGR_TRACE2(TRC_VAPP_FMGR_FOLDERSEL_ERR, "[VAPPFMGR]folder selector error handler, err_code %d, line %d", error_code, line);
        
		switch (error_code)
	    {
	        case VAPP_FMGRI_ERROR_FILE_LIST_IS_DIRTY:
                break;
	        case SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY:
            case SRV_FMGR_FILELIST_ERROR_BUSY:
                VappFmgrInstance::error_handler(error_code);
                break;
            case FS_DEVICE_BUSY:
                showPopup(srv_fmgr_fs_error_get_string(error_code), VCP_POPUP_TYPE_FAILURE);
                callbackApp(this, NULL, error_code);
                break;
            case FS_MSDC_MOUNT_ERROR:
	        case FS_MSDC_READ_SECTOR_ERROR:
	        case FS_MSDC_WRITE_SECTOR_ERROR:
	        case FS_MSDC_DISCARD_SECTOR_ERROR:
	        case FS_MSDC_PRESNET_NOT_READY:
	        case FS_MSDC_NOT_PRESENT:
			case FS_DRIVE_NOT_READY:
			case FS_FILE_NOT_FOUND:
	                return VFX_TRUE;

	        case FS_MEDIA_CHANGED:
	        case VAPP_FMGR_ERROR_EMPTY:
	        case FS_DRIVE_NOT_FOUND:
	            if (isFilePathRoot())
	            {
	                /* Popup error */	                					
					#ifdef __FS_CARD_SUPPORT__
						showPopup(STR_GLOBAL_INSERT_MEMORY_CARD, VCP_POPUP_TYPE_FAILURE);
	                #else /* __FS_CARD_SUPPORT__ */
						showPopup(STR_ID_VAPP_FMGR_NO_AVAILABLE_STORAGE, VCP_POPUP_TYPE_FAILURE);
	                #endif /* __FS_CARD_SUPPORT__ */
	                callbackApp(this, NULL, error_code);
	            }
				else
				{
					return VFX_TRUE;
				}
	            break;
	        default:
	            /* Popup error */
				showPopup(srv_fmgr_fs_error_get_string(error_code), VCP_POPUP_TYPE_FAILURE);
				
	            if (isFilePathRoot())
	            {
	                callbackApp(this, NULL, error_code);
	            }
	            else
	            {
	                switch (error_code)
	                {
	                    case FS_PATH_OVER_LEN_ERROR:
	                    case FS_PATH_NOT_FOUND:
                        case FS_ABORTED_ERROR:
	                        leaveFolder(error_code);
	                        break;

	                    default:
	                        /* Move to Root */
	                        backRoot();
	                        break;
	                }
	            }
	            break;
	    }	
	} while(0);
	
	return result;
}

void VappFmgrMediaPickerCUI::leaveFolder(S32 result)
{
    if (m_file_path.getLength() == 3 ||
    (m_flag & VCUI_FMGR_MEDIA_PICKER_OPT_FOLDER_TRAVERSE_NONE) ||
    ((m_flag & VCUI_FMGR_MEDIA_PICKER_OPT_FOLDER_TRAVERSE_SUB) && m_file_path.getLength() <= (S32)cust_data))
    {
        callbackApp(this, NULL, result);
    }
    else
    {
        if (m_page != NULL)
        {
            VappFmgrPage *page = (VappFmgrPage*)m_page;
            page->setExit();
            page->closePage();
            m_page = NULL;
        }
    }
}

void VappFmgrMediaPickerCUI::leaveFolderEx(S32 result)
{
	leaveFolder(result);
}

VfxBool VappFmgrMediaPickerCUI::isMenuItemDisable(VfxU32 page_id, VfxU16 &opt_menu_id)
{
    VfxBool result = VappFmgrInstance::isMenuItemDisable(page_id, opt_menu_id);
    // for empty folder, select btn should be disable
    if (opt_menu_id == MENU_ID_FMGR_OPTION_SELECT && (0 == getGroupCount() || 0 == getCount(0)))
    {
        result = VFX_TRUE;
    }
    
    if (m_display_style == VappFmgrPage::VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE && 
        VFX_FALSE == result)
    {
        /* Disable add menu item if there is no marked item */
        if (opt_menu_id == MENU_ID_FMGR_OPTION_ADD &&
            (m_ms == NULL || (m_ms != NULL && m_ms->getCount() == 0)))
        {       
            result = VFX_TRUE;    
        }
    }

    return result;    

}

void VappFmgrMediaPickerCUI::setStyle(vcui_fmgr_media_picker_style_enum style)
{
    m_style = style;
}

#endif /* __COSMOS_MMI__ */
