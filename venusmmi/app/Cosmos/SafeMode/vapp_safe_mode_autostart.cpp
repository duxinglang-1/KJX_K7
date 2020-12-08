/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *  vapp_safe_mode.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the autostart mre app in safe mode.
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_MRE_AUTO_START__)

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vcp_global_popup.h"
#include "vfx_adp_device.h"
#include "vapp_safe_mode.h"
#include "vapp_safe_mode_autostart.h"
#include "mmi_rp_vapp_safe_mode_def.h"

extern "C"
{
#include "wgui_categories_util.h"
#include "SafeModeSrvGprot.h"
#include "BootupSrvGprot.h"
#include "ShutdownSrvGprot.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "app_datetime.h"
#include "ProfilesSrvGprot.h"
#include "AppMgrSrvGprot.h"
#include "MreAppMgrSrvGprot.h"
#include "MreSrvGprot.h"
#include "globalresdef.h"
}

extern "C" srv_mre_launch_app_result_enum srv_mre_launch_app_ex(U16 *app_path, srv_mre_launch_app_cb_t app_cb);
/*****************************************************************************
 * Global Variable
 *****************************************************************************/
static mmi_app_package_name_struct *g_autostart_app_list_p = NULL;
static VfxS32 g_autostart_app_num = 0;
static VfxS32 g_autostart_active_app = 0;

/*****************************************************************************
 * Prototype
 *****************************************************************************/
static void vapp_safe_mode_autostart_launch_app_callback(VfxU16 *app_path, srv_mre_launch_app_evt_enum evt);
static void vapp_safe_mode_autostart_launch_app_popup_button_clicked(VfxId id, void *userData);
static void vapp_safe_mode_autostart_launch_app_popup(void);
static void vapp_safe_mode_autostart_launch_app(void);
static void vapp_safe_mode_check_autostart_query_popup();

/*****************************************************************************
 * Function
 *****************************************************************************/
static void vapp_safe_mode_autostart_launch_app_popup(void)
{
	if(g_autostart_app_num == g_autostart_active_app)
	{
		VFX_SYS_FREE_MEM(g_autostart_app_list_p);
		return;
	}

	//compose the string
	VfxWString strTemp = VFX_WSTR_RES(STR_ID_VAPP_SAFE_MODE_QUERY_LAUNCH);
	strTemp += VFX_WSTR_MEM((VfxWChar*)L" ");
	srv_app_info_struct info;
    mmi_ret result = srv_appmgr_get_app_package_info(g_autostart_app_list_p[g_autostart_active_app], &info);
	VfxWString strAppend = VFX_WSTR_MEM((VfxWChar*)info.string);
	strTemp += strAppend;
	strTemp += VFX_WSTR_MEM((VfxWChar*)L" ");
	VfxWString strQuestion = VFX_WSTR_RES(STR_ID_VAPP_SAFE_MODE_QUESTION_MARKER);
	strTemp += strQuestion;

	vcp_global_popup_show_confirm_two_button_str(
		GRP_ID_ROOT,
		VCP_POPUP_TYPE_QUESTION,
		strTemp,
		VFX_WSTR_RES(STR_GLOBAL_OK),
		VFX_WSTR_RES(STR_GLOBAL_CANCEL),
        VCP_POPUP_BUTTON_TYPE_WARNING,
        VCP_POPUP_BUTTON_TYPE_CANCEL,
        vapp_safe_mode_autostart_launch_app_popup_button_clicked,
        NULL);
}
static void vapp_safe_mode_autostart_launch_app_popup_button_clicked(VfxId id, void *userData)
{
    switch (id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
        {
			// launch the application.
 		    vapp_safe_mode_autostart_launch_app();
            break;
        }
        case VCP_CONFIRM_POPUP_BUTTON_USER_2:
			// cancel, don't launch the application, launch next.
			g_autostart_active_app++;
			vapp_safe_mode_autostart_launch_app_popup();
			break;
        case VCP_POPUP_BUTTON_NO_PRESSED:
        {
            // Do nothing.
            break;
        }

        default:
            break;
    }
}

void vapp_safe_mode_autostart_launch_app(void)
{
	for(; g_autostart_active_app < g_autostart_app_num; g_autostart_active_app++)
	{
		if(srv_mre_appmgr_get_autostart(g_autostart_app_list_p[g_autostart_active_app]) == 1)
		{
			VfxU16 filepath[SRV_MRE_APPMGR_FILEPATH_LEN];
			srv_mre_launch_app_result_enum ret;

			memset(filepath,0,sizeof(filepath));
			srv_mre_appmgr_get_file_path(g_autostart_app_list_p[g_autostart_active_app], filepath);
			ret = srv_mre_launch_app_ex(filepath, vapp_safe_mode_autostart_launch_app_callback);

			if(ret == SRV_MRE_LAUNCH_APP_SUCCESS)
			{
				break;// wait for callback
			}
			else
			{
				g_autostart_active_app++;
				vapp_safe_mode_autostart_launch_app_popup();
				break;
			}
		}
	};
}

static void vapp_safe_mode_autostart_launch_app_callback(U16 *app_path, srv_mre_launch_app_evt_enum evt)
{
	if(evt == SRV_MRE_LAUNCH_APP_EVT_SUCCESS)
	{
			g_autostart_active_app++;
			vapp_safe_mode_autostart_launch_app_popup();
	}
}

void vapp_safe_mode_check_autostart_query_button_clicked(VfxId id, void *userData)
{
    switch (id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
        {
			// find first autostart application.
			for(; g_autostart_active_app < g_autostart_app_num; g_autostart_active_app++)
			{
				if(srv_mre_appmgr_get_autostart(g_autostart_app_list_p[g_autostart_active_app]) == 1)
				{
					break;
				}
			}
			vapp_safe_mode_autostart_launch_app_popup();
            break;
        }
        case VCP_CONFIRM_POPUP_BUTTON_USER_2:
		{
			// free memory if user don't launch application
			VFX_SYS_FREE_MEM(g_autostart_app_list_p);
		}
        case VCP_POPUP_BUTTON_NO_PRESSED:
        {
            // Do nothing.
            break;
        }

        default:
            break;
    }
}

// Ask user if launch auto start app one by one.
static void vapp_safe_mode_check_autostart_query_popup()
{
    vcp_global_popup_show_confirm_two_button_id(
        GRP_ID_ROOT,
        VCP_POPUP_TYPE_QUESTION,
        STR_ID_VAPP_SAFE_MODE_QUERY_CHECK,
        STR_GLOBAL_OK,
        STR_GLOBAL_CANCEL,
        VCP_POPUP_BUTTON_TYPE_WARNING,
        VCP_POPUP_BUTTON_TYPE_CANCEL,
        vapp_safe_mode_check_autostart_query_button_clicked,
        NULL);
}

mmi_ret vapp_safe_mode_autostart_init(mmi_event_struct *event)
{
	if(srv_safe_mode_is_active())
	{
    	VfxS32 auto_start_app_num = 0;
        VfxS32 auto_start_vsp_num = 0;
        VfxS32 appCount = 0;
    	auto_start_app_num= srv_mre_appmgr_get_app_num(SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE);
        auto_start_vsp_num = srv_mre_appmgr_get_app_num(SRV_APPMGR_INSTALLED_VSP_FLAG_TYPE);
                //g_autostart_app_num = auto_start_app_num + auto_start_vsp_num;
		appCount = auto_start_app_num + auto_start_vsp_num;
		mmi_app_package_name_struct *appList = NULL;

		if(appCount > 0)
		{
			VFX_SYS_ALLOC_MEM(appList, appCount * sizeof(mmi_app_package_name_struct));
			memset(appList, 0, sizeof(mmi_app_package_name_struct) * appCount);
            if(auto_start_app_num>0)
            {
			    srv_mre_appmgr_get_app_list(SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE, appList, auto_start_app_num);
            }
            if(auto_start_vsp_num>0)
            {
                srv_mre_appmgr_get_app_list(SRV_APPMGR_INSTALLED_VSP_FLAG_TYPE, appList+auto_start_app_num, auto_start_vsp_num);
            }
			//srv_mre_appmgr_get_installed_app_list(appList, appCount);

			// check how much autostart app
			g_autostart_app_num = 0;
			for(VfxS32 i = 0; i < appCount; i++)
			{
				if(srv_mre_appmgr_get_autostart(appList[i]) == 1)
				{
					g_autostart_app_num ++;
				}
			}
			
			// copy autostart app list
			if(g_autostart_app_num > 0)
			{
				VFX_SYS_ALLOC_MEM(g_autostart_app_list_p, g_autostart_app_num * sizeof(mmi_app_package_name_struct));
				VfxS32 j = 0;
				for(VfxS32 i = 0; i < appCount; i++)
				{
					if(srv_mre_appmgr_get_autostart(appList[i]) == 1)
					{
						memcpy((mmi_app_package_char*)(g_autostart_app_list_p[j]), (mmi_app_package_char*)(appList[i]), MMI_APP_NAME_MAX_LEN);
						j ++;
					}
				}
				// query user if launch autostart mre app one by one
				vapp_safe_mode_check_autostart_query_popup();
			}
			VFX_SYS_FREE_MEM(appList);
		}
	}

	return MMI_RET_OK;
}

mmi_ret vapp_safe_mode_autostart_evt_hdlr(mmi_event_struct *event)
{
    mmi_ret ret;

    VFX_ASSERT(event);

    switch (event->evt_id)
    {
		case EVT_ID_SRV_BOOTUP_COMPLETED:
			ret = vapp_safe_mode_autostart_init(event);
			break;
			
        default:
            ret = MMI_RET_OK;
            break;
    }

    return ret;
}

#endif /* defined(__MMI_MRE_AUTO_START__) */
