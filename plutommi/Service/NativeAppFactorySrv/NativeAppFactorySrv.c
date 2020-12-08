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
 *  NativeAppFactorySrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  The implementation of application manager service.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/****************************************************************************
 * Include
 ****************************************************************************/
#include "MMI_features.h" 
#include "mmi_frm_gprot.h"
#include "mmi_frm_scenario_prot.h"
#include "AppMgrSrvGProt.h"
#include "AppMgrSrvProt.h"
#include "NativeAppFactorySrvGprot.h"
#include "NativeAppFactorySrvProt.h"
#include "mmi_rp_native_app_package_data.h" /* to get native_app_package_table[] that was generated from resgen */
#include "NotificationSettingSrvGprot.h"


/****************************************************************************
 * Define
 ****************************************************************************/


/****************************************************************************
 * Typedef
 ****************************************************************************/


/****************************************************************************
 * Local variables
 ****************************************************************************/
#ifdef __MMI_NSS_SUPPORT__
static MMI_BOOL g_is_register_nss_setting_change = MMI_FALSE;
#endif    

extern UI_string_type get_string(MMI_ID_TYPE i);

MMI_ID srv_nativeappfactory_launch_ex(srv_appfactory_launch_type_enum type, const mmi_app_package_char *app_name, void* param, U32 param_size);

srv_appfactory_func_table_struct native_appfactory_func_table = {
    SRV_APP_FACTORY_NATIVE_TYPE,
    srv_nativeappfactory_get_app_package_num,
    srv_nativeappfactory_get_app_package_list,
    srv_nativeappfactory_get_app_package_name,
    srv_nativeappfactory_get_app_package_image,
    srv_nativeappfactory_get_app_package_info,
    srv_nativeappfactory_launch_ex,
    NULL,
    srv_nativeappfactory_get_app_package_id_list,
    srv_nativeappfactory_get_app_package_name_by_id,
    (appfactory_get_id_by_app_name)srv_nativeappfactory_get_id_by_app_package_name
    };

/****************************************************************************
 * Global variables
 ****************************************************************************/

/****************************************************************************
 * Local functions
 ****************************************************************************/
    
#ifdef __MMI_NSS_SUPPORT__
/*Usage: Help to notify mainmenu that the badge setting has been changed*/
static void srv_nativeappfactory_listen_setting_change(MMI_ID app_id, U32 changed_setting, MMI_ID* alias_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    MMI_ID* temp_alias_id = NULL;
    U32 native_app_package_num = srv_nativeappfactory_get_table_size();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*Check if the change setting is badge*/
    if(changed_setting & NSS_MASK_BADGE_ICON)
    {
        /*Notify the badge setting change*/
        for (i = 0; i < native_app_package_num; i++)
        {
            if (app_id == native_app_package_table[i].app_id)
            {
                srv_appmgr_update_app_info(native_app_package_table[i].package_name, EVT_ID_SRV_APPMGR_UPDATE_BADGE);              
            }
            if(alias_id!=NULL)
            {
                temp_alias_id = alias_id;
                while (*temp_alias_id!=0xffff)
                {
                    if(*temp_alias_id == native_app_package_table[i].app_id)
                    {
                        srv_appmgr_update_app_info(native_app_package_table[i].package_name, EVT_ID_SRV_APPMGR_UPDATE_BADGE);
                        break;
                    }
                    temp_alias_id++;
                }
            }
        }
    }
}
    
#endif

/****************************************************************************
 * Global functions
 ****************************************************************************/
U32 srv_nativeappfactory_get_app_package_num(srv_appmgr_flag_type flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0, size = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE == flag)
    {
        /* we will check "hidden_in_mainmenu" is true or not */
        for (i = 0; i < srv_nativeappfactory_get_table_size(); i++)
        {
            if (MMI_FALSE == native_app_package_table[i].app_is_hidden_in_mainmenu)
            {
                size++;
            }
        }
        return size;
    }
    else if (SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE == flag)
    {
        return srv_nativeappfactory_get_table_size();
    }
    else
    {
        /* SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE,
         * SRV_APPMGR_SHORTCUT_APP_PACKAGE_FLAG_TYPE,
         * and others
         */
        return 0;
    }
}

mmi_ret srv_nativeappfactory_get_app_package_list(srv_appmgr_flag_type flag, mmi_app_package_name_struct *name_array, U32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0, j = 0;
    U32 native_app_package_num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    native_app_package_num = srv_nativeappfactory_get_app_package_num(flag);
    
    if (native_app_package_num <= num)
    {
        for (i = 0; i < srv_nativeappfactory_get_table_size(); i ++)
        {
            if (SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE == flag ||
				(SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE == flag && MMI_FALSE == native_app_package_table[i].app_is_hidden_in_mainmenu))
            {
                memcpy((mmi_app_package_char*)(name_array+j), native_app_package_table[i].package_name, MMI_APP_NAME_MAX_LEN);
                j++;
            }
        }
        return MMI_RET_OK;
    }
    else
    {
        return MMI_RET_ERR;
    }
}

mmi_ret srv_nativeappfactory_get_app_package_name(const mmi_app_package_char *app_name, WCHAR *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U32 native_app_package_num = srv_nativeappfactory_get_table_size();

    MMI_BOOL check_app_package_table = MMI_TRUE;
    srv_nativeappfactory_query_app_name_evt_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < native_app_package_num; i ++)
    {
        if (0 == strncmp((const char *)native_app_package_table[i].package_name, app_name, MMI_APP_NAME_MAX_LEN))
        {
            if (native_app_package_table[i].package_proc)
            {
                MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_NAME);
                /* send the event to app package to query the string content */
                if (MMI_RET_DONT_CARE != MMI_FRM_SEND_EVENT(&evt, native_app_package_table[i].package_proc, NULL))
                {
                    /* get the name from package_proc */
                    check_app_package_table = MMI_FALSE;
                    mmi_wcsncpy(string, evt.app_string, MMI_APP_NAME_MAX_LEN);
                }
            }

            if (check_app_package_table)
            {
                /* native_app_package_table[i].app_str_id should be valid */
                MMI_ASSERT(native_app_package_table[i].app_str_id);
                mmi_wcsncpy(string, (WCHAR*)get_string(native_app_package_table[i].app_str_id), MMI_APP_NAME_MAX_LEN);
            }
            
            return MMI_RET_OK;
        }
    }
    return MMI_RET_ERR;
}

mmi_ret srv_nativeappfactory_get_app_package_image(const mmi_app_package_char *app_name, mmi_image_src_struct *image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U32 native_app_package_num = srv_nativeappfactory_get_table_size();
    
    MMI_BOOL check_app_package_table = MMI_TRUE;
    srv_nativeappfactory_query_app_image_evt_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < native_app_package_num; i ++)
    {
        if (0 == strncmp((const char *)native_app_package_table[i].package_name, app_name, MMI_APP_NAME_MAX_LEN))
        {
            if (native_app_package_table[i].package_proc)
            {
                MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_IMAGE);
                /* send the event to app package to query the string content */
                if (MMI_RET_DONT_CARE != MMI_FRM_SEND_EVENT(&evt, native_app_package_table[i].package_proc, NULL))
                {
                    /* get the image from package_proc */
                    check_app_package_table = MMI_FALSE;
                }
            }

            if (check_app_package_table)
            {
                /* native_app_package_table[i].app_img_id should be valid */
                MMI_ASSERT(native_app_package_table[i].app_img_id);
                evt.app_img.type = MMI_IMAGE_SRC_TYPE_RES_ID;
                evt.app_img.data.res_id = native_app_package_table[i].app_img_id;
            }
            image->type = evt.app_img.type;
            if (MMI_IMAGE_SRC_TYPE_RES_ID == evt.app_img.type)
            {
                (*image).data.res_id = evt.app_img.data.res_id;
            }
            else
            {
                mmi_wcsncpy((*image).data.path, (WCHAR*)evt.app_img.data.path, SRV_FMGR_PATH_MAX_FILE_NAME_LEN+1);
            }
            return MMI_RET_OK;
        }
    }
    return MMI_RET_ERR;
}

mmi_ret srv_nativeappfactory_get_app_package_info(const mmi_app_package_char *app_name, srv_app_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U32 native_app_package_num = srv_nativeappfactory_get_table_size();
#ifdef __MMI_NSS_SUPPORT__
    U16 badge_setting = 0;
#endif
    
    MMI_BOOL check_app_package_table = MMI_TRUE;
    srv_nativeappfactory_query_app_info_evt_struct info_evt;
    srv_nativeappfactory_query_app_badge_evt_struct badge_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
#ifdef __MMI_NSS_SUPPORT__
    if(g_is_register_nss_setting_change == MMI_FALSE)
    {
        mmi_srv_nss_register_listener(NSS_MASK_BADGE_ICON, srv_nativeappfactory_listen_setting_change);
        g_is_register_nss_setting_change = MMI_TRUE;
    }
#endif
    
    for (i = 0; i < native_app_package_num; i ++)
    {
        if (0 == strncmp((const char *)native_app_package_table[i].package_name, app_name, MMI_APP_NAME_MAX_LEN))
        {
            if (native_app_package_table[i].package_proc)
            {
                MMI_FRM_INIT_EVENT(&info_evt, EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_INFO);
                /* send the event to app package to query the string content */
                if (MMI_RET_DONT_CARE != MMI_FRM_SEND_EVENT(&info_evt, native_app_package_table[i].package_proc, NULL))
                {
                    /* get the name from package_proc */
                    check_app_package_table = MMI_FALSE;
                    mmi_wcsncpy((*info).string, info_evt.app_string, MMI_APP_NAME_MAX_LEN);
                }
            }
            if (check_app_package_table)
            {
                /* native_app_package_table[i].app_str_id & native_app_package_table[i].app_img_id should be valid */
                MMI_ASSERT(native_app_package_table[i].app_str_id && native_app_package_table[i].app_img_id);
                mmi_wcsncpy((*info).string, (WCHAR*)get_string(native_app_package_table[i].app_str_id), MMI_APP_NAME_MAX_LEN);
                info_evt.app_img.type = MMI_IMAGE_SRC_TYPE_RES_ID;
                info_evt.app_img.data.res_id = native_app_package_table[i].app_img_id;
            }
            
            (*info).image.type = info_evt.app_img.type;
            if (MMI_IMAGE_SRC_TYPE_RES_ID == info_evt.app_img.type)
            {
                (*info).image.data.res_id = info_evt.app_img.data.res_id;
            }
            else
            {
                mmi_wcsncpy((*info).image.data.path, (WCHAR*)info_evt.app_img.data.path, SRV_FMGR_PATH_MAX_FILE_NAME_LEN+1);
            }

            /* Query NSS to check if need to fill badge information*/
            (*info).badge[0] = L'\0';
        #ifdef __MMI_NSS_SUPPORT__
            mmi_srv_nss_get_setting (native_app_package_table[i].app_id, NSS_SETTING_BADGE_ICON, &badge_setting);
            if(badge_setting == SETTING_ON)
        #endif    
            {                
                if (native_app_package_table[i].package_proc)
                {
                    MMI_FRM_INIT_EVENT(&badge_evt, EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_BADGE);
                    /* send the event to app package to query the count info */
                    if (MMI_RET_DONT_CARE != MMI_FRM_SEND_EVENT(&badge_evt, native_app_package_table[i].package_proc, NULL))
                    {
                        /* get badge info from package_proc */
                        mmi_wcsncpy((*info).badge, badge_evt.badge, SRV_APPMGR_BADGE_MAX_LEN);
                    }
                }
            }
            
            return MMI_RET_OK;
        }
    }
    return MMI_RET_ERR;
}

MMI_ID srv_nativeappfactory_launch_ex(srv_appfactory_launch_type_enum type, const mmi_app_package_char *app_name, void* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U32 native_app_package_num = srv_nativeappfactory_get_table_size();
    
    static S32  launch_entry_cnt = 0;
    mmi_ret     ret = MMI_RET_ERR;
    MMI_ID      app_group_id = GRP_ID_INVALID;
    MMI_BOOL    check_app_package_table = MMI_TRUE;
    
    srv_nativeappfactory_launch_app_evt_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (launch_entry_cnt > 0)
    {
        /* to avoid re-enter launch API */
        return GRP_ID_INVALID;
    }
    launch_entry_cnt++;

    for (i = 0; i < native_app_package_num; i ++)
    {
        if (0 == strncmp((const char *)native_app_package_table[i].package_name, app_name, MMI_APP_NAME_MAX_LEN))
        {
            if (native_app_package_table[i].package_proc)
            {
                MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_NATIVEAPPFACTORY_LAUNCH_APP);
                evt.param = (mmi_app_launch_param_struct*)param;
                evt.param_size = param_size;
                /* send the event to app package to query the string content */
                ret = MMI_FRM_SEND_EVENT(&evt, native_app_package_table[i].package_proc, NULL);
                if (MMI_RET_DONT_CARE != ret)
                {
                    check_app_package_table = MMI_FALSE;
                    app_group_id = (MMI_ID)ret;
                }
            }
            if (check_app_package_table)
            {
                /* native_app_package_table[i].app_launch should be valid */
                MMI_ASSERT(native_app_package_table[i].app_launch);
                app_group_id = native_app_package_table[i].app_launch((mmi_app_launch_param_struct*)param, param_size);
            }
            if (GRP_ID_INVALID != app_group_id)
            {
                /* We set app package name into group node */
                mmi_frm_group_set_app_name(app_group_id, (CHAR *)native_app_package_table[i].package_name);
            }
            launch_entry_cnt--;
            return app_group_id;
        }
    }
    launch_entry_cnt--;
    return app_group_id;
}
 

MMI_ID srv_nativeappfactory_launch(const mmi_app_package_char *app_name, mmi_app_launch_param_struct* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_nativeappfactory_launch_ex(SRV_APP_FACTORY_APP_LAUNCH_TYPE, app_name, (void*)param, param_size);
} 

mmi_ret srv_nativeappfactory_get_app_package_id_list(srv_appmgr_flag_type flag, U32 *id_array, U32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0, j = 0;
    U32 native_app_package_num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    native_app_package_num = srv_nativeappfactory_get_app_package_num(flag);
    
    if (native_app_package_num <= num)
    {
        for (i = 0; i < srv_nativeappfactory_get_table_size(); i ++)
        {
            if (SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE == flag ||
				(SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE == flag && MMI_FALSE == native_app_package_table[i].app_is_hidden_in_mainmenu))
            {
                id_array[j] = native_app_package_table[i].app_id;
                j++;
            }
        }
        return MMI_RET_OK;
    }
    else
    {
        return MMI_RET_ERR;
    }

}

mmi_ret srv_nativeappfactory_get_app_package_name_by_id(U32 id, mmi_app_package_name_struct app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < srv_nativeappfactory_get_table_size(); i ++)
    {
        if (id == native_app_package_table[i].app_id)
        {
            memcpy(app_name, native_app_package_table[i].package_name, MMI_APP_NAME_MAX_LEN);
			return MMI_RET_OK;
        }
    }

	return MMI_RET_ERR;
}

U32 srv_nativeappfactory_get_id_by_app_package_name(mmi_app_package_name_struct app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
	U32 id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < srv_nativeappfactory_get_table_size(); i ++)
    {
        if (0 == strncmp((const char *)native_app_package_table[i].package_name, app_name, MMI_APP_NAME_MAX_LEN))
        {
            id = native_app_package_table[i].app_id;
			break;
        }
    }

	return id;

}

