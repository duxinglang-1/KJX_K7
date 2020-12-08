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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * vmautostart.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * auto start application for safe mode
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h" 
#include "MMIDataType.h"
#include "SafeModeSrvGprot.h"
#include "BootupSrvGprot.h"
#include "AppMgrSrvGprot.h"
#include "MreAppMgrSrvGprot.h"
#include "MreSrvGprot.h"

#ifdef __MMI_MRE_AUTO_START__
extern srv_mre_launch_app_result_enum srv_mre_launch_app_ex(U16 *app_path, srv_mre_launch_app_cb_t app_cb);
extern void *_vm_kernel_malloc(int size);
extern void _vm_kernel_free(void* ptr);
/*****************************************************************************
 * Global Variable
 *****************************************************************************/
static mmi_app_package_name_struct *g_autostart_app_list_p = NULL;
static S32 g_autostart_app_num = 0;
static S32 g_autostart_active_app = 0;

/*****************************************************************************
 * Prototype
 *****************************************************************************/
static void vm_launch_autostart_app_callback(U16 *app_path, srv_mre_launch_app_evt_enum evt);


/*****************************************************************************
 * Function
 *****************************************************************************/
static void vm_launch_autostart_app(void)
{
    for(; g_autostart_active_app < g_autostart_app_num; g_autostart_active_app++)
    {
    	if(srv_mre_appmgr_get_autostart(g_autostart_app_list_p[g_autostart_active_app]) == 1)
    	{
			U16 filepath[SRV_MRE_APPMGR_FILEPATH_LEN];
			srv_mre_launch_app_result_enum ret;

			memset(filepath,0,sizeof(filepath));
			srv_mre_appmgr_get_file_path(g_autostart_app_list_p[g_autostart_active_app], filepath);
			ret = srv_mre_launch_app_ex(filepath, vm_launch_autostart_app_callback);

			if(ret == SRV_MRE_LAUNCH_APP_SUCCESS)
			{
				g_autostart_active_app++;
				break; // wait for callback
			}
        }
    }

	if(g_autostart_app_num == g_autostart_active_app)
	{
		_vm_kernel_free(g_autostart_app_list_p);
	}
}

static void vm_launch_autostart_app_callback(U16 *app_path, srv_mre_launch_app_evt_enum evt)
{
	if(evt == SRV_MRE_LAUNCH_APP_EVT_SUCCESS  && g_autostart_app_num > g_autostart_active_app)
	{
		vm_launch_autostart_app();
	}
}

mmi_ret vm_bootup_launch_autostart_app_hdlr(mmi_event_struct *evt)
{  
    if(!srv_safe_mode_is_active())
	{
		switch (evt->evt_id)
		{     
			case EVT_ID_SRV_BOOTUP_COMPLETED:
			{   
                U32 auto_start_app_num = 0;
                U32 auto_start_vsp_num = 0;
				auto_start_app_num= srv_mre_appmgr_get_app_num(SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE);
                auto_start_vsp_num = srv_mre_appmgr_get_app_num(SRV_APPMGR_INSTALLED_VSP_FLAG_TYPE);
                g_autostart_app_num = auto_start_app_num + auto_start_vsp_num;
				if(g_autostart_app_num > 0)
				{
					g_autostart_app_list_p = (mmi_app_package_name_struct *)_vm_kernel_malloc(g_autostart_app_num * sizeof(mmi_app_package_name_struct));
					g_autostart_active_app = 0;
					if(g_autostart_app_list_p == NULL)
					{
						ASSERT(0);
					}
                    if(auto_start_app_num>0)
                    {
					    srv_mre_appmgr_get_app_list(SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE, g_autostart_app_list_p, auto_start_app_num);
                    }
                    if(auto_start_vsp_num>0)
                    {
                        srv_mre_appmgr_get_app_list(SRV_APPMGR_INSTALLED_VSP_FLAG_TYPE, g_autostart_app_list_p+auto_start_app_num, auto_start_vsp_num);
                    }
					vm_launch_autostart_app();
				}
				break;
			}
	        default:
	            break;
	   }
	}
    return MMI_RET_OK;
}

#endif /* __MMI_MRE_AUTO_START__ */
