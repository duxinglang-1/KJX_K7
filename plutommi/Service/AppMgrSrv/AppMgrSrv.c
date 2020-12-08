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
 *  AppMgrSrv.c
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "mmi_frm_gprot.h"
#include "mmi_frm_scenario_prot.h"
#include "AppMgrSrvGprot.h"
#include "AppMgrSrvProt.h"
#include "commonscreensresdef.h"
#include "sst_sla.h"
#include "gui.h"
#include "FileMgrSrvGProt.h"
#include "mmi_rp_app_usbsrv_def.h"

/****************************************************************************
 * Define
 ****************************************************************************/
#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif
#define SRV_APPMGR_MAX_RUNNING_APP_NUM			(50)
#define SRV_APPMGR_MAX_MULTIPLE_INSTANCE_NUM    (20)

#define _MIN(a,b) (a<b)? a:b
#define _GEN_APP_ID(type, fac_id)  (U32)(((type-1) & 0x0F) << 28 | (fac_id & 0xFFFF))
#define _GET_FAC_TYPE(app_id)      (U8)(((app_id & 0xF0000000) >> 28) + 1)
#define _GET_FAC_ID(app_id)        (U32)(app_id & 0xFFFF)

/****************************************************************************
 * Typedef
 ****************************************************************************/
typedef struct
{
    char                                    *prefix;
    srv_appmgr_app_package_type_enum        type;
    srv_appfactory_func_table_struct        *func_table;
}appmgr_table_struct;

typedef struct
{
    mmi_app_package_name_struct    app_name;
    U8                             instance_num;
    group_node_struct              *instance[SRV_APPMGR_MAX_MULTIPLE_INSTANCE_NUM];
}appmgr_app_multiple_instance_info_struct;


/****************************************************************************
 * Local variables
 ****************************************************************************/
extern srv_appfactory_func_table_struct native_appfactory_func_table;
extern srv_appfactory_func_table_struct mre_appfactory_func_table;
extern srv_appfactory_func_table_struct java_appfactory_func_table;
#ifdef __GADGET_SUPPORT__
extern srv_appfactory_func_table_struct widget_appfactory_func_table;
#endif

static appmgr_table_struct _table[] ={
	  #ifndef __MMI_MRE_DISABLE_FMGR__
        {SRV_MRE_APPFACTORY_PREFIX,     SRV_APPMGR_MRE_APP_PACKAGE_TYPE,        &mre_appfactory_func_table},
    #endif
    #ifdef __J2ME__    
        {SRV_JAVA_APPFACTORY_PREFIX,    SRV_APPMGR_JAVA_APP_PACKAGE_TYPE,       &java_appfactory_func_table},
    #endif
    #ifdef __GADGET_SUPPORT__
        {SRV_WIDGET_APPFACTORY_PREFIX, 	SRV_APPMGR_WIDGET_APP_PACKAGE_TYPE,		&widget_appfactory_func_table},
    #endif
        {SRV_NATIVE_APPFACTORY_PREFIX,  SRV_APPMGR_NATIVE_APP_PACKAGE_TYPE,     &native_appfactory_func_table}
        };

static appmgr_app_multiple_instance_info_struct _multiple_instance_info = {0};

/****************************************************************************
 * Global variables
 ****************************************************************************/

/****************************************************************************
 * Global functions
 ****************************************************************************/
U32 srv_appmgr_get_app_package_num(srv_appmgr_flag_type flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0, size = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < (sizeof(_table)/sizeof(appmgr_table_struct)); i++)
    {
        #ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("ANU", SA_start);
        #endif
        size += _table[i].func_table->get_app_num_func(flag);
		#ifdef __MAUI_SOFTWARE_LA__
	        SLA_CustomLogging("ANU", SA_stop);
        #endif
    }
    return size;
}

mmi_ret srv_appmgr_get_app_package_list(srv_appmgr_flag_type flag, mmi_app_package_name_struct *name_array, U32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0, size = 0;

    mmi_app_package_name_struct *write_ptr = name_array;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < (sizeof(_table)/sizeof(appmgr_table_struct)); i++)
    {
        size = _table[i].func_table->get_app_num_func(flag);
        /* If the array remained size is less than app number, we return MMI_RET_ERR */
        if (0 < size)
        {
            if (num < size)
            {
                return MMI_RET_ERR;
            }
			
		#ifdef __MAUI_SOFTWARE_LA__
	        SLA_CustomLogging("ALI", SA_start);
        #endif
            if (_table[i].func_table->get_app_list_func(flag, write_ptr, num) != MMI_RET_OK)
            {
                MMI_ASSERT(0);
            }
	    #ifdef __MAUI_SOFTWARE_LA__
	        SLA_CustomLogging("ALI", SA_stop);
        #endif
	    
            /* update array point and size and then query the next appfactory */
            write_ptr += size;
            num -= size;
        }
    }
    return MMI_RET_OK;
}

mmi_ret srv_appmgr_get_app_package_id_list(srv_appmgr_flag_type flag, U32 *id_array, U32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j, size;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/* Get application package name list */
    for (i = 0; i < (sizeof(_table)/sizeof(appmgr_table_struct)); i++)
    {
        size = _table[i].func_table->get_app_num_func(flag);
        /* If the array remained size is less than app number, we return MMI_RET_ERR */
        if (0 < size)
        {
            if (num < size)
            {
                return MMI_RET_ERR;
            }

			if (_table[i].func_table->get_app_id_list_func)
			{
                _table[i].func_table->get_app_id_list_func(flag, id_array, size);

				/* Attach App Category flag to the ID returned from app factory */
				for (j = 0; j < size; j ++)
				{
                    id_array[j] = _GEN_APP_ID(_table[i].type, id_array[j]);
				}
	    
            	/* update array point and size and then query the next appfactory */
				id_array += size;
            	num -= size;
			}
        }
    }
		
    return MMI_RET_OK;
}

mmi_ret srv_appmgr_get_app_package_name_by_id(U32 id, mmi_app_package_name_struct app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i;
	U8 table_idx = 0xFF;
	MMI_RET ret = MMI_RET_ERR;
	U8 type = _GET_FAC_TYPE(id);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < (sizeof(_table)/sizeof(appmgr_table_struct)); i++)
    {
        if (_table[i].type == type)
        {
            table_idx = i;
			break;
        }
    }

	if (table_idx != 0xFF)
	{
	    if (_table[table_idx].func_table->get_app_name_by_id)
	    {
            ret = _table[table_idx].func_table->get_app_name_by_id(_GET_FAC_ID(id), app_name);
	    }
	}

	return ret;

}

U32 srv_appmgr_get_id_by_app_package_name(mmi_app_package_name_struct app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i;
	U8 table_idx = 0xFF;
	U32 fac_id = 0;
	U32 app_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < (sizeof(_table)/sizeof(appmgr_table_struct)); i++)
    {
        if (0 == strncmp(app_name, _table[i].prefix, strlen(_table[i].prefix)))
        {
            table_idx = i;
			break;
        }
    }

	if (table_idx != 0xFF)
	{
	    if (_table[table_idx].func_table->get_id_by_app_name)
	    {
            fac_id = _table[table_idx].func_table->get_id_by_app_name(app_name);
			app_id = _GEN_APP_ID(_table[i].type, fac_id);
	    }
	}

	return app_id;
}

mmi_ret srv_appmgr_get_app_package_name(const mmi_app_package_char *app_name, WCHAR *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    mmi_ret ret = MMI_RET_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set 'string' to be the empty string */
    memset((U8*)string, 0, 2);
    for (i = 0; i < (sizeof(_table)/sizeof(appmgr_table_struct)); i++)
    {
        if (0 == strncmp(app_name, _table[i].prefix, strlen(_table[i].prefix)))
        {
        #ifdef __MAUI_SOFTWARE_LA__
	        SLA_CustomLogging("ANM", SA_start);
        #endif
            ret = _table[i].func_table->get_name(app_name, string);
		#ifdef __MAUI_SOFTWARE_LA__
	        SLA_CustomLogging("ANM", SA_stop);
        #endif
            MMI_ASSERT(mmi_wcslen((const WCHAR*)string) <= MMI_APP_NAME_MAX_LEN - 1);
            return ret;
        }
    }
    return MMI_RET_ERR;
}


mmi_ret srv_appmgr_get_app_package_image(const mmi_app_package_char *app_name, mmi_image_src_struct *image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
	mmi_ret ret = MMI_RET_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set 'string' to be the empty string */
    memset((U8*)image, 0, sizeof(mmi_image_src_struct));
    for (i = 0; i < (sizeof(_table)/sizeof(appmgr_table_struct)); i++)
    {
        if (0 == strncmp(app_name, _table[i].prefix, strlen(_table[i].prefix)))
        {
        #ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("AIM", SA_start);
        #endif
            ret = _table[i].func_table->get_image(app_name, image);
        #ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("AIM", SA_stop);
        #endif
		    return ret;
        }
    }
    return MMI_RET_ERR;
}


mmi_ret srv_appmgr_get_app_package_info(const mmi_app_package_char *app_name, srv_app_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
	mmi_ret ret = MMI_RET_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(info, 0, sizeof(srv_app_info_struct));
    
    for (i = 0; i < (sizeof(_table)/sizeof(appmgr_table_struct)); i++)
    {
        if (0 == strncmp(app_name, _table[i].prefix, strlen(_table[i].prefix)))
        {
        #ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("AIN", SA_start);
        #endif
            ret = _table[i].func_table->get_info(app_name, info);
        #ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("AIN", SA_stop);
        #endif
			return ret;
        }
    }
    return MMI_RET_ERR;
}


srv_appmgr_app_package_type_enum srv_appmgr_get_app_package_type(const mmi_app_package_char *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < (sizeof(_table)/sizeof(appmgr_table_struct)); i++)
    {
        if (0 == strncmp(app_name, _table[i].prefix, strlen(_table[i].prefix)))
        {
            return _table[i].type;
        }
    }

    /* there is no match app package type */
    return SRV_APPMGR_UNKNOWN_APP_PACKAGE_TYPE;
}


MMI_BOOL srv_appmgr_is_app_package_running(const mmi_app_package_char *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_query_app_name((const char*)app_name) != GRP_ID_INVALID)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


MMI_ID srv_appmgr_launch_adp(srv_appfactory_launch_type_enum type, const mmi_app_package_char *app_name, void* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    MMI_ID gid = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < (sizeof(_table)/sizeof(appmgr_table_struct)); i++)
    {
        if (0 == strncmp(app_name, _table[i].prefix, strlen(_table[i].prefix)))
        {
            gid = _table[i].func_table->launch(type, app_name, param, param_size);
            if (GRP_ID_INVALID != gid)
            {
                /* launch the application successfually */
                return gid;
            }
        }
    }

    return GRP_ID_INVALID;
}

MMI_ID srv_appmgr_launch(const mmi_app_package_char *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_appmgr_launch_ex(app_name, NULL, 0);
}


MMI_ID srv_appmgr_launch_ex(const mmi_app_package_char *app_name, mmi_app_launch_param_struct* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_ERR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * We keep the app_name first and then launch1 the application.
     * When the application launches, it will invoke mmi_frm_group_create().
     * Screen group will call srv_appmgr_query_launching_app_name() to save
     * app_name in group node.
     */
    ret = srv_appmgr_launch_adp(SRV_APP_FACTORY_APP_LAUNCH_TYPE, app_name, (void*)param, param_size);

    return ret;
}


MMI_ID srv_appmgr_launch_shortcut(const mmi_app_package_char *app_name, void* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_appmgr_launch_adp(SRV_APP_FACTORY_SHORTCUT_LAUNCH_TYPE, app_name, param, param_size);
}


MMI_ID srv_appmgr_launch_setting(const mmi_app_package_char *app_name, void* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_appmgr_launch_adp(SRV_APP_FACTORY_SETTING_LAUNCH_TYPE, app_name, param, param_size);
}


U32 srv_appmgr_get_running_app_num(srv_appmgr_flag_type flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_APPMGR_RUNNING_APP_FLAG_TYPE == flag)
    {
        return mmi_frm_group_query_app_num(GROUP_TREE);
    }
    else if (SRV_APPMGR_BG_RUNNING_APP_FLAG_TYPE == flag)
    {
        return mmi_frm_group_query_app_num(GROUP_BG_TREE);
    }
    return 0;
}

mmi_ret srv_appmgr_get_running_app_list(srv_appmgr_flag_type flag, mmi_app_package_name_struct *name_array, U32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    scenario_tree_type_enum _flag = (SRV_APPMGR_RUNNING_APP_FLAG_TYPE == flag) ? GROUP_TREE : GROUP_BG_TREE; 
    
    U32 i = 0, size = 0;
    mmi_ret ret = MMI_RET_ERR;
    group_node_struct *table[SRV_APPMGR_MAX_RUNNING_APP_NUM];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check the array size is enough */
    size = mmi_frm_group_query_app_num(_flag);
    if (size == 0)
    {
        /* there is no running applications */
        return MMI_RET_OK;
    }
	/* "size" should less than input param "num" and local varaible "table[]" */
    MMI_ASSERT(size <= num && size < SRV_APPMGR_MAX_RUNNING_APP_NUM);

    ret = mmi_frm_group_query_app_list(_flag, table, size);
    if (MMI_RET_OK != ret)
    {
        return ret;
    }

    for (i = 0; i < size; i++)
    {
        if (((group_node_struct *)table[i])->app_name)
        {
            memcpy(&name_array[i], ((group_node_struct *)table[i])->app_name, MMI_APP_NAME_MAX_LEN);
        }
        else
        {
            strncpy((char*)&name_array[i], "Known App Package Name", MMI_APP_NAME_MAX_LEN);
        }
    }
    return ret;
}

U32 srv_appmgr_query_instance_num(const mmi_app_package_char *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    scenario_tree_type_enum flag[3] = {GROUP_TREE, GROUP_BG_TREE, SCENARIO_TREE_TYPE_MAX};

    U32 i = 0, j = 0, size = 0, instance_num = 0;
    group_node_struct *table[SRV_APPMGR_MAX_MULTIPLE_INSTANCE_NUM];
    mmi_ret           ret = MMI_RET_ERR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset (&_multiple_instance_info, 0, sizeof(appmgr_app_multiple_instance_info_struct));
    /* search in running application list */
    while (SCENARIO_TREE_TYPE_MAX != flag[i])
    {
        size = mmi_frm_group_query_app_num(flag[i]);
		/* size should not 0 and less than SRV_APPMGR_MAX_MULTIPLE_INSTANCE_NUM */
        if (size && size < SRV_APPMGR_MAX_MULTIPLE_INSTANCE_NUM)
        {
            ret = mmi_frm_group_query_app_list(flag[i], table, size);
            MMI_ASSERT(MMI_RET_OK == ret);
            for (j = 0; j < size; j++)
            {
                if (((group_node_struct *)table[j])->app_name)
                {
                    if (0 == strncmp(((group_node_struct *)table[j])->app_name, app_name, MMI_APP_NAME_MAX_LEN))
                    {
                        memcpy((void*)_multiple_instance_info.app_name, (const void *)app_name, MMI_APP_NAME_MAX_LEN);
                        _multiple_instance_info.instance[instance_num] = (group_node_struct *)table[j];
                        _multiple_instance_info.instance_num++;
                        MMI_ASSERT(_multiple_instance_info.instance_num <= SRV_APPMGR_MAX_MULTIPLE_INSTANCE_NUM);
                    }
                }
            }
        }
        i++;
    }
    return _multiple_instance_info.instance_num;
}

mmi_ret srv_appmgr_query_instance_id(const mmi_app_package_char *app_name, MMI_ID *instance_id_array, U32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_appmgr_query_instance_num(app_name) <= num)
    {
        memset(instance_id_array, 0, sizeof(MMI_ID)*num);
        for (i = 0; i < _multiple_instance_info.instance_num;  i++)
        {
            instance_id_array[i] = (MMI_ID)(_multiple_instance_info.instance[i]->id);
        }
        return MMI_RET_OK;
    }
    else
    {
        /* the instance_id_array size isn't enough */
        return MMI_RET_ERR;
    }
}

MMI_ID srv_appmgr_query_instance_single_id(const mmi_app_package_char *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_appmgr_query_instance_num(app_name) > 0)
    {
        for (i = 0; i < _multiple_instance_info.instance_num;  i++)
        {
            /* return the first one instance id */
            return (MMI_ID)(_multiple_instance_info.instance[i]->id);
        }
    }

    return GRP_ID_INVALID;
}

void srv_appmgr_close_app(MMI_ID app_instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(app_instance_id);
}

void srv_appmgr_config(MMI_ID app_instance_id, CHAR* inject_string, U8 inject_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_app_config_evt_struct evt = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI task parse inject string and then invoke this function to notify the running application. */
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_APP_CONFIG);
    evt.index = inject_index;
    memcpy(evt.string, inject_string, MMI_APP_CONFIG_STRING_MAX_SIZE);
    mmi_frm_group_post_event_ex(GRP_ID_ROOT, app_instance_id, (mmi_event_struct*)&evt, 0);
}

mmi_ret srv_appmgr_send_evt(MMI_ID sender_app_instance_id, MMI_ID rec_app_instance_id, mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_frm_group_send_event_ex(sender_app_instance_id, rec_app_instance_id, evt);
}

void srv_appmgr_post_evt(MMI_ID sender_app_instance_id, MMI_ID rec_app_instance_id, mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_post_event_ex(sender_app_instance_id, rec_app_instance_id, evt, 0);
}

void srv_appmgr_post_evt_ex(MMI_ID sender_app_instance_id, MMI_ID rec_app_instance_id, mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_post_event_ex(sender_app_instance_id, rec_app_instance_id, evt, MMI_SCENARIO_SEND_GROUP_EVENT_NEED_RESULT);
}

void srv_appmgr_update_app_info_ex(const mmi_app_package_char *app_name, srv_appmgr_event_enum event, void* data, U16 data_len)
{
    srv_appmgr_update_event_struct evt;

    MMI_FRM_INIT_EVENT(&evt, event);

	if (app_name)
	{
	    memcpy(evt.app_name, app_name, MMI_APP_NAME_MAX_LEN);
	}

	if (data && data_len > 0)
    {
        memcpy(evt.data, data, _MIN(data_len, SRV_APPMGR_EVENT_DATA_MAX_LEN));
		evt.data_len = _MIN(data_len, SRV_APPMGR_EVENT_DATA_MAX_LEN);
    }
    
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}

void srv_appmgr_update_app_info(const mmi_app_package_char *app_name, srv_appmgr_event_enum event)
{
    srv_appmgr_update_app_info_ex(app_name, event, NULL, 0);
}

mmi_ret srv_appmgr_uninstall_app(const mmi_app_package_char *app_name, srv_appmgr_uninstall_cb cb_fct, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    for (i = 0; i < (sizeof(_table)/sizeof(appmgr_table_struct)); i++)
    {
        if (0 == strncmp(app_name, _table[i].prefix, strlen(_table[i].prefix)))
        {
            if (_table[i].func_table->uninstall)
            {
                return _table[i].func_table->uninstall(app_name, cb_fct, user_data);
            }
            
            return MMI_RET_ERR;
        }
    }
    
    return MMI_RET_ERR;
}

/*****************************************************************************
 * FUNCTION
 *  srv_appmgr_cb_evt_hdlr
 * DESCRIPTION
 *  This function is to handle callback events from callback manager.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_appmgr_cb_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (event->evt_id)
    {
    #ifdef __MMI_USB_SUPPORT__	
        case EVT_ID_USB_ENTER_MS_MODE:
        case EVT_ID_USB_EXIT_MS_MODE:
    #endif
	    	case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
				case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
						srv_appmgr_update_app_info("", EVT_ID_SRV_APPMGR_UPDATE_ALL_INSTALLED_PACKAGE);
						srv_appmgr_update_app_info("", EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE); /* to be removed */
						break;
        default:
            break;
    }

    return ret;
}


