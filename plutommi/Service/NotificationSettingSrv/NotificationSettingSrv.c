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
 * NotificationSettingSrv.c
 *
 * Project:
 * --------
 * MAUI  
 *
 * Description:
 * ------------
 * NSS (Notification setting service) for storing and managing app's push or pool 
 * notification setting. Currently the setting includes sound, lock scrn, badge, ncenter, 
 * alert(popup, status bar).  And currently NSS only helps to save native app's configuration.
 * If you are not native app (Ex. MRE, JAVA), you need to register the callback function for 
 * saving the notification setting by yourself
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/

#include "mmi_features.h"
 #ifdef __MMI_NSS_SUPPORT__
#include "mmi_frm_events_gprot.h"
#include "mmi_trc_int.h"
#include "Unicodexdcl.h"
#include "CustDataRes.h"

#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "common_nvram_editor_data_item.h"

#include "NotificationSettingSrv.h"
#include "NotificationSettingSrvGprot.h"

#include "mmi_fw_trc.h"


#ifndef __MTK_TARGET__
/*unit test usage*/
#include "kal_debug.h"
static void mmi_nss_unit_test(void);
static U16 g_test_print_str[60];
#define g_test_mre_app_id 1000

#endif/* __MTK_TARGET__*/

/*****************************************************************************
* Definition 
*****************************************************************************/
#define MAX_NSS_NUM NVRAM_EF_SRV_NSS_PROFILE_TOTAL
#define MAX_NSS_LISTENER_NUM 5

/*****************************************************************************
* Local Variables 
*****************************************************************************/
static U32 g_native_app_num = 0;
static mmi_srv_nss_list g_mmi_srv_nss_list;
static MMI_BOOL g_nss_init = MMI_FALSE;
static mmi_srv_nss_register_node g_nss_register_node_r[MAX_NSS_NUM];
static mmi_srv_nss_listener_list g_nss_listener_list[MAX_NSS_LISTENER_NUM];

/*****************************************************************************
 * Local function 
 *****************************************************************************/
static mmi_srv_nss_register_node *mmi_nss_malloc();
static void mmi_nss_free(mmi_srv_nss_register_node *free_mem_p);
static void nss_init(void);
static mmi_srv_nss_register_node* find_nss_entry(MMI_ID app_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_nss_malloc
 * DESCRIPTION
 *  wrapper for malloc nss node from array
 * PARAMETERS
 *  
 * RETURNS
 *  pointer to a mmi_srv_nss_register_node or NULL
 *****************************************************************************/
static mmi_srv_nss_register_node *mmi_nss_malloc()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 counter = 0;
    mmi_srv_nss_register_node *mem_output_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                */
    /*----------------------------------------------------------------*/
    
    for(counter = 0; counter < MAX_NSS_NUM; counter++)
    {
        if(!(g_nss_register_node_r[counter].is_node_used))
        {
            mem_output_ptr = &g_nss_register_node_r[counter];            
            mem_output_ptr->is_node_used = 1;
            break;
        }
    }
    return mem_output_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_certman_free
 * DESCRIPTION
 *  wrapper for free nss node to array
 * PARAMETERS
 *  free_mem_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nss_free(mmi_srv_nss_register_node *free_mem_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 temp_nvram_idx = free_mem_p->nvram_record_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (free_mem_p != NULL)
    {
        memset(free_mem_p , 0, sizeof(mmi_srv_nss_register_node));
        free_mem_p->nvram_record_index = temp_nvram_idx;
        free_mem_p = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *      nss_init //NSS: Notification Setting Service
 *
 * DESCRIPTION
 *      1. load static app list (native app) into nss list 
 *      2. read configuration from nvram and update the nss list 
 * PARAMETERS
 *      void
 *
 * RETURNS
 *      void
 *****************************************************************************/
static void nss_init(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 app_idx = 0, alias_id_idx = 0;
    S16 error;    
    mmi_srv_nss_register_node *node=NULL;
    nvram_ef_srv_nss_struct nvram_node_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_nss_init != MMI_FALSE)
    {
        return;
    }

    g_native_app_num = srv_notification_setting_get_native_table_size();

    MMI_ASSERT(g_native_app_num<=NVRAM_EF_SRV_NSS_PROFILE_TOTAL);

    memset(g_nss_listener_list, 0, sizeof(g_nss_listener_list));
    memset(g_nss_register_node_r, 0, sizeof(g_nss_register_node_r));

    g_mmi_srv_nss_list.list_counter = 0;
    g_mmi_srv_nss_list.head = NULL;
    g_mmi_srv_nss_list.tail = NULL;    
    g_mmi_srv_nss_list.iter = NULL;        

    for(app_idx = 0; app_idx < MAX_NSS_NUM; app_idx++)
    {
        node = &g_nss_register_node_r[app_idx];
        node->nvram_record_index = app_idx+1;

        if(app_idx < g_native_app_num)
        {
            memcpy(&node->node_info, &g_native_nss_table [app_idx], sizeof(mmi_srv_nss_node));

           /*
           *NSS_MASK_DEFAULT presents the pleatform support range, tbl.notification_mask presents
           *app's support range, we need to take its union for NSS usage
           */        
            node->node_info.notification_mask = g_native_nss_table [app_idx].notification_mask & NSS_MASK_DEFAULT;

            /*If alias id exist, check if the alias array is end with 0xffff, 0x0*/
            if(node->node_info.alias_app_id!=NULL)
            {
                for(alias_id_idx = 0;;alias_id_idx++)
                {
                    if(*(node->node_info.alias_app_id+alias_id_idx) == 0)
                    {
                        break;
                    }
                }
                
                if(alias_id_idx!=0 && *(node->node_info.alias_app_id+alias_id_idx-1) != 0xffff) //0xffff is end symbol
                {
                    MMI_ASSERT(0);
                }
            }
            /*
             * Under some platform, call log and SNS will have no cinfiguration for user to check
             * So we will not add this node to list for user to configuration
             */
            if(node->node_info.notification_mask == 0)
            {
            	continue;
            }
        }

        /*Prepare to read the configuration from NVRAM*/        
        memset(&nvram_node_info , 0 , sizeof(nvram_ef_srv_nss_struct));
        ReadRecord(
                NVRAM_EF_SRV_NSS_PROFILE_LID,
                node->nvram_record_index,
                (void*)&nvram_node_info,
                NVRAM_EF_SRV_NSS_PROFILE_SIZE,
                &error);

        /*
        *if app id doesn't match, which means nvram setting may not correct or 
        *in the initial stage (the initial value of notification setting in nvram is zero)
        */
        if(app_idx >= g_native_app_num && nvram_node_info.app_id==0)
        {           
           continue;
        }
        
        if(app_idx < g_native_app_num && nvram_node_info.app_id == node->node_info.app_id)
        {/*Native app*/
            node->node_info.notification_setting = nvram_node_info.notification_setting;
        }

        if(app_idx >= g_native_app_num)
        {/*Download app*/
            node->node_info.app_type = DOWNLOAD_APP_TYPE;
            node->node_info.app_id = nvram_node_info.app_id;
            node->node_info.notification_setting = nvram_node_info.notification_setting;
            node->node_info.notification_mask = nvram_node_info.notification_mask;

            /*If alias id exist, check if the alias array is end with 0xffff, 0x0*/
            if(node->node_info.alias_app_id!=NULL)
            {
                for(alias_id_idx = 0;;alias_id_idx++)
                {
                    if(*(node->node_info.alias_app_id+alias_id_idx) == 0)
                    {
                        break;
                    }
                }
                
                if(alias_id_idx!=0 && *(node->node_info.alias_app_id+alias_id_idx-1) != 0xffff) //0xffff is end symbol
                {
                    MMI_ASSERT(0);
                }
            }
        }

        /*Insert to list control block*/
        if(g_mmi_srv_nss_list.head == NULL)
        {
            node->next = NULL;
            g_mmi_srv_nss_list.head = node;
            g_mmi_srv_nss_list.tail = node;
        }
        else
        {
            g_mmi_srv_nss_list.tail->next = node;
            g_mmi_srv_nss_list.tail = node;            
        }
        g_mmi_srv_nss_list.list_counter++;
        node->is_node_used = 1;
    }

    g_nss_init = MMI_TRUE;

#ifndef __MTK_TARGET__
    //mmi_nss_unit_test();    
#endif /*__MTK_TARGET__*/
}


/*****************************************************************************
 * FUNCTION
 *      find_nss_entry //NSS: Notification Setting Service
 *
 * DESCRIPTION
 *  find the specific entry by the input app id
 *
 * PARAMETERS
 *  app_id     [IN] application ID
 *
 * RETURNS
 * NULL : not found
 * or mmi_srv_nss_register_node
 *****************************************************************************/
    
static mmi_srv_nss_register_node* find_nss_entry(MMI_ID app_id)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 alias_id_index = 0;
    mmi_srv_nss_register_node *node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(app_id == 0x0 || app_id == 0xffff)
    {
        return node;
    }

    node = g_mmi_srv_nss_list.head;
    
    for( ; node!=NULL ; node = node->next)
    {
        if(node->node_info.app_id == app_id)
        {
            return node;
        }
        /*Check if the app id is located in the alias id range*/
        if(node->node_info.alias_app_id!=NULL)
        {
            for(alias_id_index = 0; *(node->node_info.alias_app_id+alias_id_index)!=0xffff; alias_id_index++)
            {
                if(*(node->node_info.alias_app_id+alias_id_index) == app_id)
                {
                    return node;
                }
            }
        }
    }   
    return node;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_srv_nss_register
 * DESCRIPTION
 *  if the installed app can receive push or poll notification, it should be registered to notification 
 *  setting service for user to modify its setting. And currently NSS only helps to save notification 
 *  setting of native app, if you are MRE or JAVA (anyway, not native app) then you need to register
 *  the callback function for receiving the notification change and save the content by yourself
 *
 * PARAMETERS
 *  nss_node     : [IN] register information
 * RETURN VALUES
 *  handle
 *  if register success, the function will return handle (the value is same as app_id)
 *  if register fail, the function will return NULL
 *****************************************************************************/
MMI_ID mmi_srv_nss_register(mmi_srv_nss_node *nss_node)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_srv_nss_register_node *new_node = NULL;
    nvram_ef_srv_nss_struct nvram_node_info;
    S16 sError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nss_init();
    /*
    *If counter exceed maximum allowed register number or
    *registerd app's type is native app or 
    *the register app id already exist in the NSS list, we will
    *return fail directly
    */
    if( g_mmi_srv_nss_list.list_counter == MAX_NSS_NUM ||
        nss_node->app_type == NATIVE_APP_TYPE ||
        find_nss_entry(nss_node->app_id)!=NULL)
    {
         return NULL;
    }
    
    new_node = mmi_nss_malloc();
    MMI_ASSERT(new_node!=NULL);
    MMI_ASSERT(new_node->nvram_record_index!=0);
    
    memcpy(&new_node->node_info, nss_node, sizeof(mmi_srv_nss_node));

    /*
     *NSS_MASK_DEFAULT presents the pleatform support range, tbl.notification_mask presents
     *app's support range, we need to take its union for NSS usage
     */      
    new_node->node_info.notification_mask &= NSS_MASK_DEFAULT;
    /*Alias id is only supported by native table now*/
    new_node->node_info.alias_app_id = NULL;

    /*Save to NVRAM*/
    memset(&nvram_node_info , 0 , sizeof(nvram_ef_srv_nss_struct));
    nvram_node_info.app_id = new_node->node_info.app_id;
    nvram_node_info.notification_setting = new_node->node_info.notification_setting;
    nvram_node_info.notification_mask = new_node->node_info.notification_mask;
    WriteRecord(NVRAM_EF_SRV_NSS_PROFILE_LID, 
                new_node->nvram_record_index, 
                &nvram_node_info, 
                NVRAM_EF_SRV_NSS_PROFILE_SIZE, 
                &sError);

    new_node->next = NULL;
    /*Insert the node to the NSS list*/
    if(g_mmi_srv_nss_list.head == NULL)
    {        
        g_mmi_srv_nss_list.head = new_node;
        g_mmi_srv_nss_list.tail = new_node;
    }
    else
    {
        g_mmi_srv_nss_list.tail->next = new_node;
        g_mmi_srv_nss_list.tail = new_node;            
    }
    g_mmi_srv_nss_list.list_counter++;

    MMI_TRACE(
        MMI_FW_TRC_G1_FRM, 
        TRC_MMI_FRM_NSS_REGISTER,
        nss_node->app_id, 
        nss_node->app_type,
        nss_node->notification_mask, 
        nss_node->notification_setting, 
        g_mmi_srv_nss_list.list_counter
        );

    return (new_node->node_info.app_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_srv_nss_unregister
 * DESCRIPTION
 *  Unregister nss function should be called when app (within notification ability) is uninstalled
 *  Noted. In the current version, native app cannot be uninstalled
 *
 * PARAMETERS
 *  app_id     : [IN] application identity
 * RETURN VALUES
 *  MMI_RET_OK : unregister successfully 
 *  MMI_RET_ERR : unregister fail
 *****************************************************************************/
mmi_ret mmi_srv_nss_unregister(MMI_ID app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_srv_nss_register_node *remove_node = NULL, *prev_remove_node=NULL;
    nvram_ef_srv_nss_struct nvram_node_info;
    S16 sError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    /*Traves the list to find out register node*/
    for(  remove_node = g_mmi_srv_nss_list.head; 
            remove_node!=NULL ; 
            prev_remove_node = remove_node, remove_node=remove_node->next)
    {
        if(remove_node->node_info.app_id == app_id)
        break;
    }

    /*
    * If fail to found the node or the node's app type is native app, 
    * we will return unregister fail directly
    */    
    if(remove_node == NULL ||
        remove_node->node_info.app_type == NATIVE_APP_TYPE)
    {
        return MMI_RET_ERR;
    }

    /*Remove the node from list*/
    if(prev_remove_node == NULL)
    {
        if(g_mmi_srv_nss_list.head == g_mmi_srv_nss_list.tail)
        {
            g_mmi_srv_nss_list.tail = remove_node->next;
        }
        g_mmi_srv_nss_list.head = remove_node->next;
    }
    else
    {
        if(g_mmi_srv_nss_list.tail == remove_node)
        {
            g_mmi_srv_nss_list.tail = prev_remove_node;
        }
        prev_remove_node->next = remove_node->next;
    }
    /*Clear Nvram*/
    memset(&nvram_node_info , 0 , sizeof(nvram_ef_srv_nss_struct));    
    WriteRecord(NVRAM_EF_SRV_NSS_PROFILE_LID, 
                remove_node->nvram_record_index, 
                &nvram_node_info, 
                NVRAM_EF_SRV_NSS_PROFILE_SIZE, 
                &sError);

    mmi_nss_free(remove_node);
    g_mmi_srv_nss_list.list_counter--;

    MMI_TRACE(
        MMI_FW_TRC_G1_FRM, 
        TRC_MMI_FRM_NSS_UNREGISTER,
        app_id, 
        g_mmi_srv_nss_list.list_counter
        );
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_srv_nss_get_setting
 * DESCRIPTION
 *  get the specific setting(KEY) of the specific app
 * PARAMETERS
 *  app_id     : [IN] application identity
 *  key     : [IN] the specific setting (Ex. sound, lock scrn..,etc)
 *  value     : [OUT] the value of the specific setting
 * RETURN VALUES
 *  MMI_RET_OK : get setting successfully 
 *  MMI_RET_FAIL : get setting fail
 * NOTED
 *  For general service (Ex. NMGR, Ncenter platform service, App mgr service), don't care RETURN VALUE
 *  just need to use the "value" to check the key's configuration
 *  For notification app, use the the RETURN VALUE to check if the setting can be configurable or not
 *****************************************************************************/
mmi_ret mmi_srv_nss_get_setting (MMI_ID app_id, nss_setting_key_enum key, U16 *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_srv_nss_register_node *get_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(value == NULL)
    {
        return MMI_RET_ERR;
    }
    
    nss_init();

    /*If key exceed support range, we will return SETTING_OFF*/
    *value = SETTING_OFF;

    if(key > NSS_SETTING_ALERT)
    {
        return MMI_RET_ERR;
    }

    /*
    * If the key is not configurable or the app entry is not existed
    * we will return the key's corresponding default setting value
    */
    switch(key)
    {
        case NSS_SETTING_BADGE_ICON:
            *value = SETTING_BADGE_DEFAULT;
            break;    
        case NSS_SETTING_SOUND:
            *value = SETTING_SOUND_DEFAULT;
            break;    
        case NSS_SETTING_LOCK_SCRN:
            *value = SETTING_LOCK_SCRN_DEFAULT;
            break;    
        case NSS_SETTING_NCENTER:
            *value = SETTING_NCENTER_DEFAULT;
            break;    
        case NSS_SETTING_ALERT:
            *value = ALERT_TYPE_DEFAULT;
            break;    
    }
     
    get_node = find_nss_entry(app_id);
    if(get_node == NULL)
    {
        return MMI_RET_ERR;
    }
    /*
    * Check if the setting is configurable, if not, we will return default setting value 
    * and the return value is fail
    */
    if(NSS_IS_SETTING_CONFIGURABLE(get_node->node_info.notification_mask, KEY_TO_MASK(key)))
    {
        NSS_EXTRACT_SETTING_VALUE(get_node->node_info.notification_setting, key, (*value));
    }
    else
    {
        /*if query non-mask value, we will return fail*/
        return MMI_RET_ERR;    
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_srv_nss_set_setting
 * DESCRIPTION
 *  set the specific setting(KEY) of the specific app
 * PARAMETERS
 *  app_id     : [IN] application identity
 *  key     : [IN] the specific setting (Ex. sound, lock scrn..,etc)
 *  value     : [IN] the value of the specific setting
 * RETURN VALUES
 *  MMI_RET_OK : set setting successfully 
 *  MMI_RET_FAIL : set setting fail
 *  This function is only opened for notification setting app
 *****************************************************************************/
mmi_ret mmi_srv_nss_set_setting(MMI_ID app_id, nss_setting_key_enum key, U16 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret =MMI_RET_OK;
    mmi_srv_nss_register_node *set_node = NULL;
    nvram_ef_srv_nss_struct nvram_node_info;
    U32 temp_notification_setting = 0;
    S16 sError, i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    /*
    * If fail to found the node or the node's mask show not configurable, 
    * we will return fail directly
    */
    set_node = find_nss_entry(app_id);
    if(set_node == NULL ||
        NSS_IS_SETTING_CONFIGURABLE(set_node->node_info.notification_mask, KEY_TO_MASK(key)) == NULL)
    {
        return MMI_RET_ERR;
    }

    /*
    * Start to update the setting
    */
    temp_notification_setting = set_node->node_info.notification_setting;
    NSS_MODIFY_SETTING_VALUE(temp_notification_setting, key, value);

    if(ret == MMI_RET_OK)
    {        
        set_node->node_info.notification_setting = temp_notification_setting;
        for(i = 0; i < MAX_NSS_LISTENER_NUM; i++)
        {
            if(g_nss_listener_list[i].interest_notification_mask != 0
                && (g_nss_listener_list[i].interest_notification_mask & KEY_TO_MASK(key)))
            {
                g_nss_listener_list[i].cb_proc(app_id, (g_nss_listener_list[i].interest_notification_mask & 
                    KEY_TO_MASK(key)), set_node->node_info.alias_app_id);
            }        
        }
    }
    /*
    * Save configuration to nvram if the app is native app
    */   
    MMI_ASSERT(set_node->nvram_record_index > 0);
    memset(&nvram_node_info , 0 , sizeof(nvram_ef_srv_nss_struct));
    nvram_node_info.app_id = set_node->node_info.app_id;
    nvram_node_info.notification_setting = set_node->node_info.notification_setting;
    nvram_node_info.notification_mask = set_node->node_info.notification_mask;
    WriteRecord(NVRAM_EF_SRV_NSS_PROFILE_LID, 
            set_node->nvram_record_index, 
            &nvram_node_info, 
            NVRAM_EF_SRV_NSS_PROFILE_SIZE, 
            &sError);
    
    
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_srv_nss_get_app_setting
 * DESCRIPTION
 *  get all settings of the specific app
 * PARAMETERS
 *  app_id     : [IN] application identity
 *  notification_setting : [OUT] notification setting of specific app
 *  notification_mask   : [OUT] notification mask of specific app
 * RETURN VALUES
 *  MMI_RET_OK : get setting successfully 
 *  MMI_RET_FAIL : get setting fail
 * NOTED
 *  NSS provide macro to help app to retrieve the specific setting's value
 *  This function is only opened for notification setting app, general service should 
 *  use mmi_srv_nss_get_setting to retrieve the setting value
 *****************************************************************************/
mmi_ret mmi_srv_nss_get_app_setting(MMI_ID app_id, U32 *notification_setting, U32 *notification_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_srv_nss_register_node *get_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(notification_setting == NULL
        || notification_mask == NULL)
    {
        return MMI_RET_ERR;
    }
    
    nss_init();

    /*
    * If fail to found the node, we will return zero setting
    * the logic is different from get_setting, due to this function
    * is only opened for notification setting app, the node they queried
    * must be existed
    */
    *notification_setting = 0;
    *notification_mask = 0;        
     
    get_node = find_nss_entry(app_id);
    if(get_node == NULL)
    {
        return MMI_RET_ERR;
    }

    *notification_setting = get_node->node_info.notification_setting;
    *notification_mask = get_node->node_info.notification_mask;
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_srv_nss_set_app_setting
 * DESCRIPTION
 *  set all settings of the specific app
 * PARAMETERS
 *  app_id     : [IN] application identity
 *  notification_setting : [IN] notification setting of specific app
 * RETURN VALUES
 *  MMI_RET_OK : get setting successfully 
 *  MMI_RET_FAIL : get setting fail
 * NOTED
 *  NSS provide macro to help app to modify the specific setting's value
 *  This function is only opened for notification setting app
 *****************************************************************************/
mmi_ret mmi_srv_nss_set_app_setting(MMI_ID app_id, U32 notification_setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret =MMI_RET_OK;
    mmi_srv_nss_register_node *set_node = NULL;
    U32 changed_mask = 0;
    nvram_ef_srv_nss_struct nvram_node_info;
    S16 sError, i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    
    set_node = find_nss_entry(app_id);
    if(set_node == NULL)
    {
        return MMI_RET_ERR;
    }
    /*
    * If the setting did not change, then you don't need to save the setting 
    * to nvram or callback
    */
    if(notification_setting != set_node->node_info.notification_setting)
    {            
        if(ret == MMI_RET_OK)
        {
            changed_mask = set_node->node_info.notification_setting^notification_setting;
            if(changed_mask & NSS_MASK_ALERT<<1)
            {
                changed_mask &=~(NSS_MASK_ALERT<<1);
                changed_mask |= NSS_MASK_ALERT;
            }
            
            set_node->node_info.notification_setting = notification_setting;
            
            for(i = 0; i < MAX_NSS_LISTENER_NUM; i++)
            {
                if(g_nss_listener_list[i].interest_notification_mask != 0
                    && (g_nss_listener_list[i].interest_notification_mask & changed_mask))
                {
                    g_nss_listener_list[i].cb_proc(app_id, (g_nss_listener_list[i].interest_notification_mask & 
                        changed_mask), set_node->node_info.alias_app_id);
                }        
            }
        }
       /*
     * Save configuration to nvram if the app is native app
     */
        MMI_ASSERT(set_node->nvram_record_index > 0);

        memset(&nvram_node_info , 0 , sizeof(nvram_ef_srv_nss_struct));
        nvram_node_info.app_id = set_node->node_info.app_id;
        nvram_node_info.notification_setting = set_node->node_info.notification_setting;
        nvram_node_info.notification_mask = set_node->node_info.notification_mask;
        WriteRecord(NVRAM_EF_SRV_NSS_PROFILE_LID, 
            set_node->nvram_record_index, 
            &nvram_node_info, 
            NVRAM_EF_SRV_NSS_PROFILE_SIZE, 
            &sError);
    }
    
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_srv_nss_get_first_node
 * DESCRIPTION
 *  get the first node of nss node list (for showing app list to user)
 * PARAMETERS
 *  nss_node     : [OUT] you can use the structure to retrieve 1. app_id, 2. ALERT name, 3. image icon
 * RETURN VALUES
 *  void. if there is no node, the app_id would be zero
 *****************************************************************************/
void mmi_srv_nss_get_first_node(mmi_srv_nss_node *nss_node) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nss_init();        
    if(nss_node != NULL)
    {
        nss_node->app_id = 0;
        
        if(g_mmi_srv_nss_list.head!=NULL)
        {
            g_mmi_srv_nss_list.iter = g_mmi_srv_nss_list.head;
            memcpy(nss_node, &g_mmi_srv_nss_list.iter->node_info, sizeof(mmi_srv_nss_node));
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_srv_nss_get_next_node
 * DESCRIPTION
 *  get the next node of nss node list (for showing app list to user)
 * PARAMETERS
 *  nss_node     : [OUT] you can use the structure to retrieve 1. app_id, 2. ALERT name, 3. image icon
 * RETURN VALUES
 *  void. if there is no node, the app_id would be zero
 *****************************************************************************/
void mmi_srv_nss_get_next_node(mmi_srv_nss_node *nss_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    
    if(nss_node != NULL)
    {
          nss_node->app_id = 0;
          
          if(g_mmi_srv_nss_list.iter->next!=NULL)
          {
              g_mmi_srv_nss_list.iter = g_mmi_srv_nss_list.iter->next;
              memcpy(nss_node, &g_mmi_srv_nss_list.iter->node_info, sizeof(mmi_srv_nss_node));
          }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_srv_nss_get_node_by_index
 * DESCRIPTION
 *  get the node by its index (for showing app list to user, and the index is start from zero)
 * PARAMETERS
 *  index     : [IN] the node you want to get
 *  nss_node     : [OUT] you can use the structure to retrieve 1. app_id, 2. ALERT name, 3. image icon
 * RETURN VALUES
 *  void. if there is no such index, the app_id of the nss_node would be zero
 *****************************************************************************/
void mmi_srv_nss_get_node_by_index (U32 index , mmi_srv_nss_node *nss_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_srv_nss_register_node *get_node = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if(nss_node != NULL)
    {
        nss_node->app_id = 0;

        if(index >= g_mmi_srv_nss_list.list_counter)
            return;
        
        get_node = g_mmi_srv_nss_list.head;
       /*
     * Traves the list to find out the node by index
     */
        if(get_node)
        {
            for(; index != 0; index--)
            {
                get_node = get_node->next; 
            }
            memcpy(nss_node, &get_node->node_info, sizeof(mmi_srv_nss_node));
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_srv_nss_get_node_num
 * DESCRIPTION
 *  get the total number of nodes
 * PARAMETERS
 * RETURN VALUES
 *  the total number of nodes
 *****************************************************************************/
U32 mmi_srv_nss_get_node_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    nss_init();
    return g_mmi_srv_nss_list.list_counter;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_srv_nss_register_listener
 * DESCRIPTION
 *  app or other service can register this function to listen the setting change
 *  you can unregister by insert the NULL mask value
 * PARAMETERS
 * RETURN VALUES
 *  true when register or unregister success
 *****************************************************************************/

MMI_BOOL mmi_srv_nss_register_listener(U32 interest_notification_mask, mmi_listener_proc_func cb_proc)
{
    U16 i = 0; 
    S16 free_node = -1;   

    nss_init();
        
    for(i = 0; i < MAX_NSS_LISTENER_NUM; i++)
    {
        if(g_nss_listener_list[i].interest_notification_mask == 0)
        {
            free_node = i;
        }
        else
        {
            if(g_nss_listener_list[i].cb_proc == cb_proc)
            {
                g_nss_listener_list[i].interest_notification_mask = interest_notification_mask;
                return MMI_TRUE;
            }
        }        
    }

    if(free_node == -1)
    {
        return MMI_FALSE;
    }
    
    g_nss_listener_list[free_node].interest_notification_mask = interest_notification_mask;
    g_nss_listener_list[free_node].cb_proc = cb_proc;
    return MMI_TRUE;
}

#ifndef __MTK_TARGET__

static void dump_nss_list(void)
{        
    mmi_srv_nss_register_node *get_node = NULL;
    CHAR *temp_string = NULL;
    
    kal_print("Current NSS list counter [%d]\n", g_mmi_srv_nss_list.list_counter);

    get_node = g_mmi_srv_nss_list.head;

    while (get_node!=NULL)
    {        
        memset(g_test_print_str, 0, sizeof(g_test_print_str));
        if(get_node->node_info.app_type == DOWNLOAD_APP_TYPE)
        {            
            //mmi_asc_to_wcs(g_test_print_str, get_node->node_info.app_info.mre_res.app_mre_package_name);
        }
        else
        {
            temp_string = GetString(get_node->node_info.app_info.native_res.app_str_id);           
            if(temp_string)
            {         
                mmi_ucs2cpy((CHAR*)g_test_print_str, temp_string);
            }
        }
    
        kal_print("%ws-App ( ID , String ) = ( %d, %ws ) \n", (get_node->node_info.app_type == NATIVE_APP_TYPE)?L"NATIVE":L"MRE",
            get_node->node_info.app_id, g_test_print_str);
        kal_print("( Setting , Mask) = ( %x, %x) \n", 
            get_node->node_info.notification_setting,
            get_node->node_info.notification_mask);       
        if(get_node->node_info.alias_app_id!=NULL)
        {
            kal_print("( Alias ID) = ( ");
            while(1)
            {
                kal_print("%d, ", *get_node->node_info.alias_app_id);
                if(*get_node->node_info.alias_app_id == 0)
                {
                    break;
                }
                get_node->node_info.alias_app_id++;
            }
            kal_print(")\n");
        }
        
        get_node = get_node->next;
    }    
    
}

#define FILL_APP_NSS_INFO(_nss_node, _app_id, _app_type, _notification_setting, _notification_mask) do { \
    _nss_node.app_id = _app_id; \
    _nss_node.app_type = _app_type; \
    _nss_node.notification_setting = _notification_setting; \
    _nss_node.notification_mask = _notification_mask; \
    } while(0)

static void mmi_nss_unit_test(void)
{
    U32  temp_setting_value = 0, temp_mask_value = 0;    
    U16  temp_value = 0;    
    U32 i = 0;
    S16 error;
    CHAR test_pack_name[] = "mre.xxx.product";
    mmi_ret result = MMI_RET_OK;
    nvram_ef_srv_nss_struct nvram_node_info;
    mmi_srv_nss_node app_nss_node_r;

    // Register Test
    //
    //
    // 1. Register native node - fail result
    kal_print("=====Start NSS unit test=====\n");
    memset(&app_nss_node_r, 0, sizeof(mmi_srv_nss_node));
    FILL_APP_NSS_INFO(app_nss_node_r, g_test_mre_app_id, NATIVE_APP_TYPE, NSS_SETTING_DEFAULT, NSS_MASK_DEFAULT);
    temp_value = mmi_srv_nss_register(&app_nss_node_r);
    MMI_ASSERT(temp_value == NULL);

    // 2. Register MRE node without alias id- success result
    memset(&app_nss_node_r, 0, sizeof(mmi_srv_nss_node));
    FILL_APP_NSS_INFO(app_nss_node_r, g_test_mre_app_id, DOWNLOAD_APP_TYPE, NSS_SETTING_DEFAULT, NSS_MASK_DEFAULT);
    temp_value = mmi_srv_nss_register(&app_nss_node_r);
    MMI_ASSERT(temp_value == g_test_mre_app_id);

    // 2. Register MRE node with alias id- success result
    mmi_srv_nss_unregister(g_test_mre_app_id);
    memset(&app_nss_node_r, 0, sizeof(mmi_srv_nss_node));
    FILL_APP_NSS_INFO(app_nss_node_r, g_test_mre_app_id , DOWNLOAD_APP_TYPE, NSS_SETTING_DEFAULT, NSS_MASK_DEFAULT);
    temp_value = mmi_srv_nss_register(&app_nss_node_r);
    MMI_ASSERT(temp_value == g_test_mre_app_id);
    
    // 3. Register already existed MRE node
    // and check by mmi_srv_nss_get_setting (MMI_ID app_id, nss_setting_key_enum key, U16 *value)
    //mmi_srv_nss_get_app_setting(MMI_ID app_id, U16 *notification_setting, U16 *notification_mask)    
   temp_setting_value = NSS_FILL_SETTING_VALUE( SETTING_OFF,
              SETTING_SOUND_DEFAULT, 
              SETTING_NCENTER_DEFAULT, 
              SETTING_OFF, 
              ALERT_TYPE_STATUS_BAR);

    memset(&app_nss_node_r, 0, sizeof(mmi_srv_nss_node));
    FILL_APP_NSS_INFO(app_nss_node_r, g_test_mre_app_id, DOWNLOAD_APP_TYPE, temp_setting_value, NSS_MASK_DEFAULT);
    temp_value = mmi_srv_nss_register(&app_nss_node_r);
    MMI_ASSERT(temp_value == NULL);

    result = mmi_srv_nss_get_setting (g_test_mre_app_id, NSS_SETTING_BADGE_ICON, &temp_value);        
    MMI_ASSERT(result==MMI_RET_OK);
    MMI_ASSERT(temp_value!=SETTING_OFF);

    result = mmi_srv_nss_get_setting (g_test_mre_app_id, NSS_SETTING_ALERT, &temp_value);
    if(result == MMI_RET_OK)
    MMI_ASSERT(temp_value==ALERT_TYPE_DEFAULT);

    result = mmi_srv_nss_get_app_setting(g_test_mre_app_id, &temp_setting_value, &temp_mask_value);
    MMI_ASSERT(result==MMI_RET_OK);
    MMI_ASSERT(temp_setting_value==NSS_SETTING_DEFAULT);
    MMI_ASSERT(temp_mask_value==NSS_MASK_DEFAULT);

    // 4. Register too many nodes that exceed maximum number of nss list 
    for(i = 0; i < MAX_NSS_NUM*2; i++)
    {
        memset(&app_nss_node_r, 0, sizeof(mmi_srv_nss_node));
        FILL_APP_NSS_INFO(app_nss_node_r, (g_test_mre_app_id-i), DOWNLOAD_APP_TYPE, NSS_SETTING_DEFAULT,\
            (NSS_MASK_SOUND|NSS_MASK_LOCK_SCRN|NSS_MASK_NCENTER));
        temp_value = mmi_srv_nss_register(&app_nss_node_r);        
    }
    MMI_ASSERT(temp_value==NULL);
    MMI_ASSERT(g_mmi_srv_nss_list.list_counter == MAX_NSS_NUM);

    //Set & Get notification setting test
    //
    //
    //1. Set native app setting by key-setting    
    result = mmi_srv_nss_set_setting(g_native_nss_table[0].app_id, NSS_SETTING_ALERT, ALERT_TYPE_NONE);
    result = mmi_srv_nss_get_setting(g_native_nss_table[0].app_id, NSS_SETTING_ALERT, &temp_value);
    if(result == MMI_RET_OK)
    MMI_ASSERT(temp_value == ALERT_TYPE_NONE);

    result = mmi_srv_nss_set_setting(g_native_nss_table[0].app_id, NSS_SETTING_LOCK_SCRN, SETTING_OFF);
    result = mmi_srv_nss_get_setting(g_native_nss_table[0].app_id, NSS_SETTING_LOCK_SCRN, &temp_value);
    if(result == MMI_RET_OK)
    MMI_ASSERT(temp_value == SETTING_OFF);

    result = mmi_srv_nss_set_setting(g_native_nss_table[0].app_id, NSS_SETTING_NCENTER, SETTING_OFF);
    result = mmi_srv_nss_get_setting(g_native_nss_table[0].app_id, NSS_SETTING_NCENTER, &temp_value);
    if(result == MMI_RET_OK)
    MMI_ASSERT(temp_value == SETTING_OFF);

    result = mmi_srv_nss_set_setting(g_native_nss_table[0].app_id, NSS_SETTING_SOUND, SETTING_OFF);
    result = mmi_srv_nss_get_setting(g_native_nss_table[0].app_id, NSS_SETTING_SOUND, &temp_value);
    if(result == MMI_RET_OK)
    MMI_ASSERT(temp_value == SETTING_OFF);

    result = mmi_srv_nss_set_setting(g_native_nss_table[0].app_id, NSS_SETTING_BADGE_ICON, SETTING_OFF);
    result = mmi_srv_nss_get_setting(g_native_nss_table[0].app_id, NSS_SETTING_BADGE_ICON, &temp_value);
    if(result == MMI_RET_OK)
    MMI_ASSERT(temp_value == SETTING_OFF);


    //1.1 Set alias native app setting by key-setting    
    result = mmi_srv_nss_set_setting(g_test_native_app_id+3, NSS_SETTING_ALERT, ALERT_TYPE_NONE);    
    result = mmi_srv_nss_get_setting(g_test_native_app_id, NSS_SETTING_ALERT, &temp_value);
    if(result == MMI_RET_OK)
    MMI_ASSERT(temp_value == ALERT_TYPE_NONE);

    result = mmi_srv_nss_set_setting(g_test_native_app_id-10, NSS_SETTING_ALERT, ALERT_TYPE_DEFAULT);    
    result = mmi_srv_nss_get_setting(g_test_native_app_id+5, NSS_SETTING_ALERT, &temp_value);
    if(result == MMI_RET_OK)
    MMI_ASSERT(temp_value == ALERT_TYPE_DEFAULT);

    //2. Set MRE app setting by key-setting, setting is configurable    
    result = mmi_srv_nss_set_setting(g_test_mre_app_id, NSS_SETTING_SOUND, SETTING_OFF);    
    result = mmi_srv_nss_get_setting(g_test_mre_app_id, NSS_SETTING_SOUND, &temp_value);
    MMI_ASSERT(result == MMI_RET_OK);
    MMI_ASSERT(temp_value == SETTING_OFF);

    result = mmi_srv_nss_set_setting(g_test_mre_app_id, NSS_SETTING_SOUND, SETTING_ON);    
    result = mmi_srv_nss_get_setting(g_test_mre_app_id, NSS_SETTING_SOUND, &temp_value);
    MMI_ASSERT(result == MMI_RET_OK);
    MMI_ASSERT(temp_value == SETTING_ON);

    //2.1. Set alias MRE app setting by key-setting, setting is configurable    
    result = mmi_srv_nss_get_setting(g_test_mre_app_id, NSS_SETTING_SOUND, &temp_value);
    MMI_ASSERT(result == MMI_RET_OK);
    MMI_ASSERT(temp_value == SETTING_ON);

    result = mmi_srv_nss_set_setting(g_test_mre_app_id, NSS_SETTING_SOUND, SETTING_OFF);
    MMI_ASSERT(result == MMI_RET_OK);
    result = mmi_srv_nss_get_setting(g_test_mre_app_id, NSS_SETTING_SOUND, &temp_value);
    MMI_ASSERT(result == MMI_RET_OK);
    MMI_ASSERT(temp_value == SETTING_OFF);

    //3. Set MRE app setting by key-setting, setting is not configurable
    result = mmi_srv_nss_set_setting((g_test_mre_app_id-1), NSS_SETTING_BADGE_ICON, SETTING_OFF);
    MMI_ASSERT(result == MMI_RET_ERR);
    result = mmi_srv_nss_get_setting((g_test_mre_app_id-1), NSS_SETTING_BADGE_ICON, &temp_value);
    MMI_ASSERT(result == MMI_RET_ERR);
    MMI_ASSERT(temp_value == SETTING_BADGE_DEFAULT);

    //4. Get non-exist node's setting by key-setting 
    result = mmi_srv_nss_get_setting(0, NSS_SETTING_BADGE_ICON, &temp_value);
    MMI_ASSERT(result == MMI_RET_ERR);
    MMI_ASSERT(temp_value == SETTING_BADGE_DEFAULT);

    //5. Set non-exist node by key-setting   
    result = mmi_srv_nss_set_setting(0, NSS_SETTING_BADGE_ICON, SETTING_OFF);
    MMI_ASSERT(result == MMI_RET_ERR);

    //6. Set out of boundary setting by key-setting   
    result = mmi_srv_nss_set_setting((g_test_mre_app_id-2), NSS_SETTING_SOUND, SETTING_OFF);
    MMI_ASSERT(result == MMI_RET_OK);
    result = mmi_srv_nss_get_setting((g_test_mre_app_id-2), NSS_SETTING_SOUND, &temp_value);
    MMI_ASSERT(result == MMI_RET_OK);
    MMI_ASSERT(temp_value == SETTING_OFF);

    result = mmi_srv_nss_set_setting((g_test_mre_app_id-2), NSS_SETTING_SOUND, 111);
    result = mmi_srv_nss_get_setting((g_test_mre_app_id-2), NSS_SETTING_SOUND, &temp_value);
    MMI_ASSERT(result == MMI_RET_OK);
    MMI_ASSERT(temp_value == SETTING_OFF);

    result = mmi_srv_nss_set_setting((g_test_mre_app_id-2), NSS_SETTING_SOUND+10000, SETTING_OFF);
    result = mmi_srv_nss_get_setting((g_test_mre_app_id-2), NSS_SETTING_SOUND+10000, &temp_value);
    MMI_ASSERT(result == MMI_RET_ERR);
    MMI_ASSERT(temp_value == SETTING_OFF);

    
    //7. Set native app setting by app-setting     
    result = mmi_srv_nss_get_app_setting(g_native_nss_table[0].app_id, &temp_setting_value, &temp_mask_value);
    MMI_ASSERT(result == MMI_RET_OK);
    if(NSS_IS_SETTING_CONFIGURABLE(temp_mask_value,KEY_TO_MASK(NSS_SETTING_ALERT)))
    {
       NSS_MODIFY_SETTING_VALUE(temp_setting_value, NSS_SETTING_ALERT, ALERT_TYPE_NONE);
       result = mmi_srv_nss_set_app_setting(g_native_nss_table[0].app_id, temp_setting_value);
       MMI_ASSERT(result == MMI_RET_OK);
       result = mmi_srv_nss_get_app_setting(g_native_nss_table[0].app_id, &temp_setting_value, &temp_mask_value);
       MMI_ASSERT(result == MMI_RET_OK);
       NSS_EXTRACT_SETTING_VALUE(temp_setting_value, NSS_SETTING_ALERT, temp_mask_value);
       MMI_ASSERT(temp_mask_value == ALERT_TYPE_NONE);
    }

    //8. Set MRE app setting by app-setting  , setting is configurable   
    result = mmi_srv_nss_get_app_setting(g_test_mre_app_id, &temp_setting_value, &temp_mask_value);
    MMI_ASSERT(result == MMI_RET_OK);
    if(NSS_IS_SETTING_CONFIGURABLE(temp_mask_value,KEY_TO_MASK(NSS_SETTING_SOUND)))
    {
       NSS_MODIFY_SETTING_VALUE(temp_setting_value, NSS_SETTING_SOUND, SETTING_ON);
       result = mmi_srv_nss_set_app_setting(g_test_mre_app_id, temp_setting_value);
       MMI_ASSERT(result == MMI_RET_OK);
       result = mmi_srv_nss_get_app_setting(g_test_mre_app_id, &temp_setting_value, &temp_mask_value);
       MMI_ASSERT(result == MMI_RET_OK);
       NSS_EXTRACT_SETTING_VALUE(temp_setting_value, NSS_SETTING_SOUND, temp_mask_value);
       MMI_ASSERT(temp_mask_value == SETTING_ON);
    }    
       
    //9. Set MRE app setting by app-setting  , setting is not configurable
    result = mmi_srv_nss_get_app_setting(g_test_mre_app_id-1, &temp_setting_value, &temp_mask_value);
    MMI_ASSERT(result == MMI_RET_OK);
    if(NSS_IS_SETTING_CONFIGURABLE(temp_mask_value,KEY_TO_MASK(NSS_SETTING_BADGE_ICON)))
    {
        MMI_ASSERT(0);      
    }
   
    //10. set non-exist node    
    result = mmi_srv_nss_get_app_setting((g_test_mre_app_id-100), &temp_setting_value, &temp_mask_value);
    MMI_ASSERT(result == MMI_RET_ERR);

    //12.Get's error handling
    mmi_srv_nss_get_app_setting(g_native_nss_table[0].app_id, NULL, &temp_mask_value);
    mmi_srv_nss_get_app_setting(g_native_nss_table[0].app_id, &temp_setting_value, NULL);
    mmi_srv_nss_get_setting((g_test_mre_app_id-1), NSS_SETTING_BADGE_ICON, NULL);

    //Get app list 
    //
    //
    // 1. get_first_node, get_next_node

    memset(&app_nss_node_r, 0, sizeof(mmi_srv_nss_node));   
    i = 0;
    mmi_srv_nss_get_first_node (&app_nss_node_r);

    while (app_nss_node_r.app_id)
    {
        mmi_srv_nss_get_next_node (&app_nss_node_r);
        i ++;
    }
    MMI_ASSERT( i == g_mmi_srv_nss_list.list_counter );

    // 2. get_counter
    MMI_ASSERT(mmi_srv_nss_get_node_num () == MAX_NSS_NUM);

    // 3. get node by index
    for(i = 0; i < g_native_app_num; i++)
    {
      mmi_srv_nss_get_node_by_index (i,&app_nss_node_r);
      MMI_ASSERT(app_nss_node_r.app_id == g_native_nss_table[i].app_id);   
    }

    for( i = g_native_app_num; i < MAX_NSS_NUM; i++)
    {
       mmi_srv_nss_get_node_by_index (i , &app_nss_node_r);
       MMI_ASSERT(app_nss_node_r.app_id == (g_test_mre_app_id - (i-g_native_app_num)));
    }
    //nvram test

    memset(&nvram_node_info , 0 , sizeof(nvram_ef_srv_nss_struct));

    ReadRecord(
                NVRAM_EF_SRV_NSS_PROFILE_LID,
                1,
                (void*)&nvram_node_info,
                NVRAM_EF_SRV_NSS_PROFILE_SIZE,
                &error);
    
    MMI_ASSERT(nvram_node_info.app_id == g_native_nss_table[0].app_id);   
    
    //Unregister test
    //
    //
    //1. remove node that exist in NSS list 
    result = mmi_srv_nss_unregister(g_test_mre_app_id);
    MMI_ASSERT(result==MMI_RET_OK);

    //2. remove node that not exist in NSS list 
    result = mmi_srv_nss_unregister(g_test_mre_app_id);
    MMI_ASSERT(result==MMI_RET_ERR);

    //3. remove node that belong to native app type    
    result = mmi_srv_nss_unregister(g_native_nss_table[0].app_id);    
    MMI_ASSERT(result==MMI_RET_ERR);
    
    //4. remove all (only exist native app node)
    for(i = 0; i < MAX_NSS_NUM; i++)
    {
        result = mmi_srv_nss_unregister(g_test_mre_app_id-i);        
    }
    MMI_ASSERT(g_mmi_srv_nss_list.list_counter == g_native_app_num);

   // reset native value 
   temp_setting_value = NSS_FILL_SETTING_VALUE( SETTING_BADGE_DEFAULT,
              SETTING_SOUND_DEFAULT, 
              SETTING_NCENTER_DEFAULT, 
              SETTING_LOCK_SCRN_DEFAULT, 
              ALERT_TYPE_DEFAULT);
    mmi_srv_nss_set_app_setting(g_native_nss_table[0].app_id, temp_setting_value);

    dump_nss_list();
    kal_print("=====Complete NSS unit test=====\n");

}



#endif /*__MTK_TARGET__*/
#endif /*__MMI_NSS_SUPPORT__*/


