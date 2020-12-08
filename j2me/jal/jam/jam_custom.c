/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
* permission of MediaTek Inc. (C) 2005
*
* BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
* THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
* RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
* AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
* NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
* SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
* SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
* THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
* NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
* SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
* BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
* LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
* AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
* MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
* THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
* WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
* LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
* RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
* THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  j2me_custom.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *      This file is intends for customization of default Java midletsuites
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/*************************************************************************
 * Include Header Files
 *************************************************************************/
#include "jal.h"
#include "j2me_custom.h"
#include "jvm_internal.h"
#include "jpush_interface.h"
#include "jam_internal.h"
#include "jam_msg_handler.h"
#include "jwa_internal.h"
#ifdef __COSMOS_MMI_PACKAGE__
#include "JavaAppFactorySrvGprot.h"
#endif
#include "mmi_frm_utility_gprot.h"
#include "app_str.h"

/*************************************************************************
 * Global Definition
 *************************************************************************/
j2me_custom_file_info_struct *j2me_custom_file_info_ptr;

int j2me_default_game_count;
int virtual_file_count;

int game_j2me_default_game_count;
int game_virtual_file_count;

kal_bool g_mmi_java_is_need_create_nw_setting = KAL_FALSE;

void create_default_nw_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #define LEN 30
    int ret = J2ME_NO_ERROR;
    int idx,jdx;
    int len = 0;
    int remainder = 0;
    int divider = 0;
    kal_uint32 count = 0;    
    char  storage_name[LEN] = {0};
    kal_char* preferred_con_profile = NULL;
    jam_mids_network_struct setting = {0};
    j2me_custom_file_info_struct *info_ptr = _jvm_get_builtin_file_info();
    kal_int8 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_java_is_need_create_nw_setting == KAL_FALSE)
    {
        return;
    }

    memset(storage_name,0,LEN);
    strcpy(storage_name,"global");
    for(i = 0;i < MMI_SIM_TOTAL; i++) 
    while((ret = jam_nw_create_setting(storage_name, &setting,NULL,i)) == NW_OP_ERR_BUSY)
    {
        count++;
        kal_sleep_task(10);
        if(count == 10)
        {
        #ifdef MIDP_FILE_DEBUG
            sprintf(_kvmLogStr, "[ERROR] create_default_nw_setting over 10");
            Kputs(_kvmLogStr);
        #endif
            return;
        }
    }
    if(ret!= 0)
    {
    #ifdef MIDP_FILE_DEBUG
          sprintf(_kvmLogStr, "[ERROR] create_default_nw_setting error code = %d",ret);
          Kputs(_kvmLogStr);
    #endif
          return;
    }
#if defined(__IJET_VM__) || defined(__NEMO_VM__)
    count = info_ptr->default_mids_count;
    memset(&setting, 0, sizeof(jam_mids_network_struct));
    for(i = 0; i < MMI_SIM_TOTAL; i++)   
    for(idx = 1;idx <= count; idx++)
    {
        memset(storage_name,0,LEN);
#if defined(__NEMO_VM__)
        strcpy(storage_name,"J0000000");
        jdx = 1;
#else
        strcpy(storage_name,"00000000_");
        jdx = 2;
#endif /* __NEMO_VM__ */

        len = strlen(storage_name);
        divider = idx;
        do{            
            remainder = divider%10;
            divider /= 10;
            storage_name[len - jdx] = '0'+remainder;
            jdx++;
        }while(divider > 0);
        if(jam_call_back_functions.jam_get_mids_app_property)
        {
    #define BUFFER_SIZE 100
            kal_wchar* buffer = (kal_wchar*)get_ctrl_buffer(BUFFER_SIZE);
            kal_mem_set(buffer,0,BUFFER_SIZE);
            jam_call_back_functions.jam_get_mids_app_property(storage_name,0,(kal_char*)"PREFERRED-Con-Profile-TO-USE",buffer,BUFFER_SIZE);
            if((len = app_ucs2_strlen((const kal_int8 *)buffer)) > 0)
            {
                preferred_con_profile = get_ctrl_buffer(len+1);
                app_ucs2_str_to_asc_str((kal_int8 *) preferred_con_profile,(kal_int8 *) buffer);
                
            }
            else
            {
                preferred_con_profile = NULL;
            }
            free_ctrl_buffer(buffer);
        }
        else
        {
            preferred_con_profile = NULL;
        }


        
        while((ret = jam_nw_create_setting(storage_name, &setting,preferred_con_profile,i)) == NW_OP_ERR_BUSY) 
        {
            count++;
            kal_sleep_task(10);
            if(count == 10)
            {
            #ifdef MIDP_FILE_DEBUG
                sprintf(_kvmLogStr, "[ERROR] create_default_nw_setting default game try time over 10");
                Kputs(_kvmLogStr);
            #endif
                if(preferred_con_profile)free_ctrl_buffer(preferred_con_profile);
                return;
            }
        }
        if(preferred_con_profile)free_ctrl_buffer(preferred_con_profile);
        if(ret!= 0)
        {
        #ifdef MIDP_FILE_DEBUG
              sprintf(_kvmLogStr, "[ERROR] create_default_nw_setting default game = %d",ret);
              Kputs(_kvmLogStr);
        #endif              
              return;
        }
    }
    g_mmi_java_is_need_create_nw_setting = KAL_FALSE;
#endif /*__IJET_VM__*/
}



/*****************************************************************************
 * FUNCTION
 *  _jvm_get_dir_path
 * DESCRIPTION
 *  return directory path according to game type
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_char *_jvm_get_dir_path(void)
{
    return j2me_sys_dir_path;
}


/*****************************************************************************
 * FUNCTION
 *  _jvm_get_builtin_file_info
 * DESCRIPTION
 *  return directory path according to game type
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
j2me_custom_file_info_struct *_jvm_get_builtin_file_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    j2me_custom_file_info_struct *info_ptr = NULL;
    extern mmi_ret srv_java_appfactory_gen_file(void);
    extern mmi_ret srv_java_appfactory_remove_all_records(void);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
            j2me_default_game_count = game_j2me_default_game_count;
            virtual_file_count = game_virtual_file_count;
            info_ptr = j2me_custom_file_info_ptr;
    return info_ptr;
}
void jam_gen_jal_sys_file(void)
{
    jam_mids_np_reset();
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
#endif 
#ifdef __SUPPORT_JAVA_PUSH__
    jpush_push_restore_factory_setting();
#endif

    create_default_nw_setting();
#ifdef __DM_SCOMO_SUPPORT__
    jam_remove_all_mids_notify();
#endif
    srv_java_appfactory_remove_all_records();
    srv_java_appfactory_gen_file();
#ifdef SUPPORT_JSR_120
    J2ME_sms_init();
#endif
}

/*****************************************************************************
 * FUNCTION
 *  javaFileGenerator
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type                    [IN]        
 *  force_remove_all        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void javaFileGenerator(kal_bool force_get_all)
{
    if(jam_call_back_functions.jam_check_and_gen_sys_file)
    {
        jam_call_back_functions.jam_check_and_gen_sys_file(force_get_all);
    }
    g_mmi_java_is_need_create_nw_setting = KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  javaFileRecovery
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void javaFileRecovery(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 attribute = 0;
    kal_uint32 real_size = 0;
    int handle = -1;
    int i = 0;
    int normal_file_count = 0;
    const char *normal_file_name = NULL;
    const unsigned char *normal_file_data = NULL;
    int normal_file_size = 0;
    j2me_custom_file_info_struct *info_ptr = _jvm_get_builtin_file_info();
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    work_sys_dir_path = _jvm_get_dir_path();

    normal_file_count = info_ptr->normal_file_info.normal_file_count;

    /* check normal file */
    for (i = 0; i < normal_file_count; i++)
    {
        /* added by Justin to not block low priority task */
        if ((i & 0x3) == 0x3)
        {
            kal_sleep_task(1);
        }

        normal_file_name = info_ptr->normal_file_info.normal_file_name[i];
        normal_file_data = info_ptr->normal_file_info.normal_file_data[i];
        normal_file_size = info_ptr->normal_file_info.normal_file_size[i];

        kal_wsprintf(WCHARFilename, "%s\\%s", work_sys_dir_path, normal_file_name);

        attribute = FS_GetAttributes(WCHARFilename);

        if (attribute < 0)
        {
            /* regenerate file only when file not existed */
            handle = FS_Open(WCHARFilename, FS_READ_WRITE);

            if (handle < 0)
            {
                handle = FS_Open(WCHARFilename, FS_READ_WRITE | FS_CREATE_ALWAYS);
                if (handle < 0)
                {
                    handle = FS_Open(WCHARFilename, FS_READ_WRITE | FS_CREATE_ALWAYS | FS_OPEN_SHARED);

                    if (handle > 0)
                    {
                    #ifdef MIDP_FILE_DEBUG
                        sprintf(_kvmLogStr, "J2ME Warning: file handle leak - %s", normal_file_name);
                        Kputs(_kvmLogStr);
                    #endif                        
                    }
                    else
                    {
                        ASSERT(0);
                    }
                }
            }

            FS_GetFileSize(handle, &real_size);
            if ((real_size == 0) && (normal_file_size != 0))
            {   /* recovery only when size 0 */
                if ((FS_Write(handle, (void*)normal_file_data, normal_file_size, &real_size)) != FS_NO_ERROR)
                {
                #ifdef MIDP_FILE_DEBUG
                    sprintf(_kvmLogStr, "J2ME Warning: file recovery write failed - %s, %d", normal_file_name, result);
                    Kputs(_kvmLogStr);
                #endif                    
                }
                /* added by Justin to not block low priority task */
                kal_sleep_task(1);
            }

            FS_Close(handle);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  javaFileRemoveAll
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void javaFileRemoveAll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    int normal_file_count = 0;
    const char *normal_file_name = NULL;
    j2me_custom_file_info_struct *info_ptr = _jvm_get_builtin_file_info();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    work_sys_dir_path = _jvm_get_dir_path();

    normal_file_count = info_ptr->normal_file_info.normal_file_count;

    /* remove all normal file */
    for (i = 0; i < normal_file_count; i++)
    {
        normal_file_name = info_ptr->normal_file_info.normal_file_name[i];

        kal_wsprintf(WCHARFilename, "%s\\%s", work_sys_dir_path, normal_file_name);
        FS_Delete(WCHARFilename);
        /* added by Justin to not block low priority task */
        if ((i & 0x3) == 0x3)
        {
            kal_sleep_task(1);
        }
    }
    //create_default_nw_setting();
    g_mmi_java_is_need_create_nw_setting = KAL_TRUE;

#ifdef __DM_SCOMO_SUPPORT__
    jam_remove_all_mids_notify();
#endif
}
