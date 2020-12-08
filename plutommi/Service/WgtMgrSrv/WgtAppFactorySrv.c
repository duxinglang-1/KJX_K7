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
 * WgtAppFactorySrv.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
/************************************************************************/
/* Include Header                                                       */
/************************************************************************/
#include "MMI_features.h"

#ifdef __GADGET_SUPPORT__

#include "MMIDataType.h"
#include "app_str.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "fs_type.h"
#include "fs_func.h"
#include "AppMgrSrvGprot.h"
#include "AppMgrSrvProt.h"
#include "WgtMgrSrvGprot.h"
#include "WgtMgrSrvIprot.h"
#include "WgtMgrSrv.h"

/************************************************************************/
/* Structure and Definition                                             */
/************************************************************************/
#define SRV_WIDGET_APPMGR_ID_PREFIX "widget."


/************************************************************************/
/* Internal Function Declaration                                        */
/************************************************************************/
U32 srv_widget_appmgr_get_reg_app_num(srv_appmgr_flag_type flag);
mmi_ret srv_widget_appmgr_get_reg_app_list(srv_appmgr_flag_type flag, mmi_app_package_name_struct *name_array, U32 num);
mmi_ret srv_widget_appmgr_get_app_name(const mmi_app_package_char *app_name, WCHAR* string);
mmi_ret srv_widget_appmgr_get_app_image(const mmi_app_package_char *app_name, mmi_image_src_struct *image);
mmi_ret srv_widget_appmgr_get_app_info(const mmi_app_package_char *app_name, srv_app_info_struct *info);
MMI_ID srv_widget_appmgr_launch(srv_appfactory_launch_type_enum type, const mmi_app_package_char *app_name, void* param, U32 param_size);

#ifdef __WGTMGR_MAIN_MENU_SUPPORT__
extern kal_bool vapp_widget_launch_in_main_menu(int id);
extern void vapp_widget_load_widget(int instance_id, int details);
#endif

/************************************************************************/
/* Golbal Variable                                                      */
/************************************************************************/
srv_appfactory_func_table_struct widget_appfactory_func_table = 
{
    SRV_APP_FACTORY_WIDGET_TYPE,
    (appfactory_get_reg_app_num)srv_widget_appmgr_get_reg_app_num,
    (appfactory_get_reg_app_list)srv_widget_appmgr_get_reg_app_list,
    (appfactory_get_name)srv_widget_appmgr_get_app_name,
    (appfactory_get_image)srv_widget_appmgr_get_app_image,
    (appfactory_get_info)srv_widget_appmgr_get_app_info,
    (appfacotry_launch)srv_widget_appmgr_launch,
    NULL
};


/************************************************************************/
/* Local Function Definition                                                  */
/************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  srv_widget_appmgr_check_app_name
 * DESCRIPTION
 *  This function is used for get widget id by app name.
 * PARAMETERS
 *  
 * RETURNS
 *   
 *****************************************************************************/
static MMI_BOOL srv_widget_appmgr_check_app_name(const mmi_app_package_char *app_name, int *instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i, num = 0;
    CHAR id_str[4] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (app_name == NULL)
    {
        return MMI_FALSE;
    }

    if (app_strnicmp((CHAR*)app_name, (CHAR*)SRV_WIDGET_APPMGR_ID_PREFIX, 7) == 0)
    {
        for (i = 11; i < strlen(app_name); i++)
        {
            id_str[num++] = app_name[i];
        }
        id_str[num] = '\0';

        *instance_id = atoi(id_str);
        
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_widget_appmgr_get_reg_app_num
 * DESCRIPTION
 *  This function is used for app manager service to get registered widgets number.
 * PARAMETERS
 *  flag : [IN] application manager service flag
 * RETURNS
 *   return the number of registered widgets
 *****************************************************************************/
U32 srv_widget_appmgr_get_reg_app_num(srv_appmgr_flag_type flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (flag == SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE || /* not include uninstalled/undownloaded shortcut app */
	    flag == SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE)
    {
        return srv_wgtmgr_get_mainmenu_wgt_num();
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_widget_appmgr_get_reg_app_list
 * DESCRIPTION
 *  This function is used for app manager service to get registered widgets list.
 * PARAMETERS
 *  flag : [IN] application manager service flag.
 *  name_array : [OUT] get the application name of all installed applications.
 *  size : [IN]  the array size.
 * RETURNS
 *  MMI_RET_OK: Get the application list successfully.
 *  MMI_RET_ERR: Get the application list fail.
 *****************************************************************************/
mmi_ret srv_widget_appmgr_get_reg_app_list(srv_appmgr_flag_type flag, mmi_app_package_name_struct *name_array, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!size || !name_array)
    {
        return MMI_RET_OK;
    }

    if (flag == SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE || /* not include uninstalled/undownloaded shortcut app */
	    flag == SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE)
    {
        srv_wgtmgr_get_mainmenu_wgt_list(name_array);
        return MMI_RET_OK;
    }
    return MMI_RET_ERR;
}


/*****************************************************************************
 * FUNCTION
 *  srv_widget_appmgr_get_app_name
 * DESCRIPTION
 *  This function is used for app manager service to get name of registered widget.
 * PARAMETERS
 *  app_name  : [IN] the application package identification.
 *  string    : [OUT] the application name.
 * RETURNS
 *  MMI_RET_OK: Get the application name successfully.
 *  MMI_RET_ERR: Get the application name fail.
 *****************************************************************************/
mmi_ret srv_widget_appmgr_get_app_name(const mmi_app_package_char *app_name, WCHAR* string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_widget_appmgr_check_app_name(app_name, &id))
    {
        srv_wgtmgr_get_downloaded_wgt_name(id, string, sizeof(WCHAR) * SRV_WGTMGR_MAX_WGT_NAME_LEN);
        return MMI_RET_OK;
    }
    
    return MMI_RET_ERR;
}


/*****************************************************************************
 * FUNCTION
 *  srv_widget_appmgr_get_app_image
 * DESCRIPTION
 *  This function is used for app manager service to get name of registered widget.  
 * PARAMETERS
 *  app_name  : [IN] the application identification.
 *  image     : [OUT] the application image.
 * RETURNS
 *  MMI_RET_OK: Get the application image successfully.
 *  MMI_RET_ERR: Get the application image fail.
 *****************************************************************************/
mmi_ret srv_widget_appmgr_get_app_image(const mmi_app_package_char *app_name, mmi_image_src_struct *image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_widget_appmgr_check_app_name(app_name, &id))
    {
        image->type = MMI_IMAGE_SRC_TYPE_PATH;
        srv_wgtmgr_get_downloaded_wgt_icon_path(id, image->data.path);

        return MMI_RET_OK;
    }

    return MMI_RET_ERR;
}


/*****************************************************************************
 * FUNCTION
 *  srv_widget_appmgr_get_app_info
 * DESCRIPTION
 *  This function is used for app manager service to get information of registered widget.
 * PARAMETERS
 *  app_name  : [IN] the application identification.
 *  info      : [OUT] the application information.
 * RETURNS
 *  MMI_RET_OK: Get the application information successfully.
 *  MMI_RET_ERR: Get the application information fail.
 *****************************************************************************/
mmi_ret srv_widget_appmgr_get_app_info(const mmi_app_package_char *app_name, srv_app_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_widget_appmgr_get_app_name(app_name, info->string) == MMI_RET_OK
        && srv_widget_appmgr_get_app_image(app_name, &info->image) == MMI_RET_OK)
    {
        return MMI_RET_OK;
    }

    return MMI_RET_ERR;
}


/*****************************************************************************
 * FUNCTION
 *  srv_widget_appmgr_launch
 * DESCRIPTION
 *  This function is used for app manager service to invoke registered widget's launch function.
 * PARAMETERS
 *  type : [IN] app launch type
 *  app_name  : [IN] the application identification.
 *  param : [IN] parameter
 *  parm_size : [IN] parameter size
 * RETURNS
 *  MMI_RET_OK: launch the application successfully.
 *  MMI_RET_ERR: launch the application fail.
 *****************************************************************************/
MMI_ID srv_widget_appmgr_launch(srv_appfactory_launch_type_enum type, const mmi_app_package_char *app_name, void* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __WGTMGR_MAIN_MENU_SUPPORT__
    if (srv_widget_appmgr_check_app_name(app_name, &id))
    {
        if (vapp_widget_launch_in_main_menu(id) == KAL_TRUE)
        {
            vapp_widget_load_widget(id, 1);
        }
        
        return MMI_RET_OK;
    }
#endif

    return MMI_RET_ERR;
}

#endif /* __GADGET_SUPPORT__ */

