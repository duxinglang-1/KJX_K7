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
 *  AppMgrSrvProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Internal interface of application manager service.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SRV_APPMGR_PROT_H__
#define __SRV_APPMGR_PROT_H__

/****************************************************************************
 * Include
 ****************************************************************************/
#include "AppMgrSrvGprot.h"

/****************************************************************************
 * Define
 ****************************************************************************/

#define SRV_NATIVE_APPFACTORY_PREFIX        ("native")
#define SRV_JAVA_APPFACTORY_PREFIX          ("java")
#define SRV_MRE_APPFACTORY_PREFIX           ("mre")
#ifdef __GADGET_SUPPORT__
#define SRV_WIDGET_APPFACTORY_PREFIX		("widget")
#endif

/****************************************************************************
 * Typedef
 ****************************************************************************/
/* Application factory type */
typedef enum 
{
    SRV_APP_FACTORY_NATIVE_TYPE,
    SRV_APP_FACTORY_MRE_TYPE,
    SRV_APP_FACTORY_JAVA_TYPE,
#ifdef __GADGET_SUPPORT__
    SRV_APP_FACTORY_WIDGET_TYPE,
#endif

    SRV_APP_FACTORY_MAX_TYPE
}srv_appfactory_type_enum;

typedef enum 
{
    SRV_APP_FACTORY_APP_LAUNCH_TYPE,
    SRV_APP_FACTORY_SETTING_LAUNCH_TYPE,
    SRV_APP_FACTORY_SHORTCUT_LAUNCH_TYPE,

    SRV_APP_FACTORY_LAUNCH_MAX_TYPE
}srv_appfactory_launch_type_enum;


/* App Factory function declaration */
typedef U32     (*appfactory_get_reg_app_num) (srv_appmgr_flag_type flag);
typedef mmi_ret (*appfactory_get_reg_app_list) (srv_appmgr_flag_type flag, mmi_app_package_name_struct *item, U32 num);
typedef mmi_ret (*appfactory_get_name) (const mmi_app_package_char *app_name, WCHAR* string);
typedef mmi_ret (*appfactory_get_image) (const mmi_app_package_char *app_name, mmi_image_src_struct *info);
typedef mmi_ret (*appfactory_get_info) (const mmi_app_package_char *app_name, srv_app_info_struct *info);
typedef MMI_ID  (*appfacotry_launch) (srv_appfactory_launch_type_enum type, const mmi_app_package_char *app_name, void* param, U32 parm_size);
typedef mmi_ret (*appfactory_uninstall) (const mmi_app_package_char *app_name, srv_appmgr_uninstall_cb cb_fct, void* user_data);
typedef mmi_ret (*appfactory_get_reg_id_list) (srv_appmgr_flag_type flag, U32 *id, U32 num);
typedef mmi_ret (*appfactory_get_app_name_by_id) (U32 id, mmi_app_package_char *app_name);
typedef U32		(*appfactory_get_id_by_app_name) (const mmi_app_package_char *app_name);

typedef struct
{
    srv_appfactory_type_enum        type;
    appfactory_get_reg_app_num      get_app_num_func;
    appfactory_get_reg_app_list     get_app_list_func;
    appfactory_get_name             get_name;
    appfactory_get_image            get_image;
    appfactory_get_info             get_info;
    appfacotry_launch               launch;
    appfactory_uninstall            uninstall; /* Use NULL if not support */
	appfactory_get_reg_id_list      get_app_id_list_func;
	appfactory_get_app_name_by_id   get_app_name_by_id;
	appfactory_get_id_by_app_name   get_id_by_app_name;
	
}srv_appfactory_func_table_struct;

/****************************************************************************
 * Functions
 ****************************************************************************/

#endif /* __SRV_APPMGR_PROT_H__ */

