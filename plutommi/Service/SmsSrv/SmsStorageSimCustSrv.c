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
 *  SmsStorageSimCustSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service Storage SIM Card Customization Handler
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MOD_SMSAL__
/**************************************************************
* Header Files Include
**************************************************************/
#ifdef __SRV_SMS_SIM_CUST_DATA__
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "MMIDataType.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_nvram_gprot.h"
#include "string.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"

#include "MMI_common_app_trc.h"
#include "nvram_common_defs.h"
#include "SmsSrvGProt.h"
#include "SmsProtSrv.h"
#include "SmsStorageSimCustSrv.h"
#include "SmsUtilSrv.h"
#include "FileMgrSrvGProt.h"


/**************************************************************
* MARCO
**************************************************************/
#define MAX_SIM_CUST_FILE_NAME_LEN      64
#define SIM_CUST_SYS_NUM                NVRAM_EF_SRV_SMS_CUST_SYS_NUM
#define SIM_CUST_PUB_NUM                NVRAM_EF_SRV_SMS_CUST_PUB_NUM

#define SRV_SMS_IMSI_LEN                NVRAM_EF_SRV_SMS_CUST_IMSI_LEN

#define SRV_SMS_SIM_CUST_PUB_PATH       "\\SMSSimCust\\"
#define SRV_SMS_SIM_CUST_SYS_PATH       "\\@SMSSimCust\\"
#define SRV_SMS_DEFAULT_IMSI_1          "000"
#define SRV_SMS_DEFAULT_IMSI_2          "111"
#define SRV_SMS_DEFAULT_IMSI_3          "222"
#define SRV_SMS_DEFAULT_IMSI_4          "333"


/**************************************************************
* Structure Declaration
**************************************************************/
/* Make sure the structure is same as nvram_ef_srv_sms_sim_cust_data_struct */
typedef struct
{
    U8 sys_imsi[SIM_CUST_SYS_NUM][SRV_SMS_IMSI_LEN];
    U8 pub_imsi[SIM_CUST_PUB_NUM][SRV_SMS_IMSI_LEN];
    U8 sys_num;
    U8 pub_num;
} srv_sms_sim_cust_info_struct;

typedef struct
{
    U8 imsi[SRV_SMS_IMSI_LEN];
    U16 total;
} sms_sim_cust_cntx_struct;


/**************************************************************
* Global Variables Declaration
**************************************************************/ 

/**************************************************************
* Extern Function Declaration
**************************************************************/


/**************************************************************
* Static Variables Defination
**************************************************************/
static sms_sim_cust_cntx_struct sim_cust_cntx[SMS_SIM_NUM];


/**************************************************************
* Static Function Declaration
**************************************************************/
static void srv_sms_read_cust_info_from_nvram(srv_sms_sim_cust_info_struct* cust_info);
static void srv_sms_write_cust_info_into_nvram(srv_sms_sim_cust_info_struct* cust_info);
static void srv_sms_get_sys_cust_file(U16 *file_name, U8 *imsi_number);
static void srv_sms_get_pub_cust_file(U16 *file_name, U8 *imsi_number);
static void srv_sms_get_sys_cust_folder(U16 *folder_name);
static void srv_sms_get_pub_cust_folder(U16 *folder_name);
static MMI_BOOL srv_sms_check_cust_file_valid(U16* file_name, U16 total);
static MMI_BOOL srv_sms_check_cust_file_content_valid(FS_HANDLE fs_hd, U16 total);
static MMI_BOOL srv_sms_move_sys_cust_file_to_pub(U8 *imsi_number);
static MMI_BOOL srv_sms_move_pub_cust_file_to_sys(U8 *imsi_number);
static MMI_BOOL srv_sms_move_cust_file(U16 *dest_file_name, U16 *src_file_name);
static void srv_sms_get_sim_cust_file_name(U16 *file_name, srv_sms_sim_enum sim_id);
static MMI_BOOL srv_sms_create_default_sim_cust_file(U16 *file_name, U16 total);
static MMI_BOOL srv_sms_create_cust_folder(U16 *folder_name);
static void srv_sms_delete_cust_file(U16 *file_name);
static void srv_sms_sim_cust_check_file(U32 *file_num, MMI_BOOL flag);


/**************************************************************
* Function Defination
**************************************************************/
static void srv_sms_sim_cust_check_file(U32 *file_num, MMI_BOOL flag)
{
	FS_HANDLE fs_hd;
	U16 file_name[MAX_SIM_CUST_FILE_NAME_LEN + 1];

	if(flag)
    {
		srv_sms_get_sys_cust_folder(file_name);
    }
	else
    {
		srv_sms_get_pub_cust_folder(file_name);
    }
	fs_hd = FS_Open(file_name, FS_READ_ONLY);
		
	if (fs_hd < FS_NO_ERROR)
	{
		*file_num = 0;	
		srv_sms_create_cust_folder(file_name);
	}
	else
	{
		FS_Close(fs_hd);
		if (*file_num == 0)
		{
			FS_XDelete((WCHAR*)file_name, FS_FILE_TYPE, NULL, 0);
		}
	}	
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_sim_cust_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_set_sim_cust_cntx(U16 total, U8 *imsi, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SET_SIM_CUST_CNTX, total, (S8*)imsi, sim_id);

    index = srv_sms_sim_id_to_sim_index(sim_id);
    
    sim_cust_cntx[index].total = total;
    memcpy(sim_cust_cntx[index].imsi, imsi, SRV_SMS_IMSI_LEN);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sim_cust_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_sim_cust_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sim_cust_info_struct *cust_info;
    srv_sms_sim_cust_info_struct *new_cust_info;
    U16 file_name[MAX_SIM_CUST_FILE_NAME_LEN + 1];
    MMI_BOOL exist_flag[SMS_SIM_NUM] = {MMI_FALSE};
    U32 i;
    U8 sys_count = 0;
    U8 pub_count = 0;
    U32 sys_file_num;
    U32 pub_file_num;
    U32 remain_count = 0;
    U32 remain_index = 0;    
    U8 sim_total = 0;
    MMI_BOOL need_update = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SMS_SIM_NUM; i++)
    {
        if (sim_cust_cntx[i].total > 0)
        {
            sim_total++;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SIM_CUST_INIT, sim_total);

    /* If not insert SIM Card */
    if (sim_total == 0)
    {
        return;
    }

    remain_index = sim_total;
    cust_info = OslMalloc(sizeof(srv_sms_sim_cust_info_struct));
    new_cust_info = OslMalloc(sizeof(srv_sms_sim_cust_info_struct));

    srv_sms_read_cust_info_from_nvram(cust_info);

    sys_file_num = cust_info->sys_num;
    pub_file_num = cust_info->pub_num;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SIM_CUST_INIT_1, sys_file_num, pub_file_num);

    /* Check whether the value is valid */
    if (sys_file_num > SIM_CUST_SYS_NUM)
    {
        sys_file_num = 0;
    }

    if (pub_file_num > SIM_CUST_PUB_NUM)
    {
        pub_file_num = 0;
    }

    /* Check system folder */
    srv_sms_sim_cust_check_file(&sys_file_num,MMI_TRUE);

    /* Check Public folder */
    srv_sms_sim_cust_check_file(&pub_file_num,MMI_FALSE);

    for (i = 0; i < SMS_SIM_NUM; i++)
    {
    	U32 index ;
        if (sim_cust_cntx[i].total > 0 )
        {
        	U8 *curr_imsi = sim_cust_cntx[i].imsi;
            for(index = 0; index < SIM_CUST_SYS_NUM ; index++)
            {	
            	U8 *tmp_imsi = cust_info->sys_imsi[i];
            	if (strcmp((S8*)tmp_imsi, (S8*)curr_imsi) == 0)
            	{
            	    continue;
                }
					
            }
            if(index == SIM_CUST_SYS_NUM)
            {
                need_update = MMI_TRUE;
            }
        }
    }

    if(need_update == MMI_TRUE)
    {
    /* Check system Cust File */
        for (i = 0; i < sys_file_num; i++)
        {
            U32 index = 0;
            U8 *curr_imsi = cust_info->sys_imsi[i];
            MMI_BOOL is_match = MMI_FALSE;
            U16 sms_total = 0;

            if (sys_count < sim_total)
            {
                for (index = 0; index < SMS_SIM_NUM; index++)
                {
                    sms_total = sim_cust_cntx[index].total;

                    if (sms_total > 0)
                    {
                        U8 *tmp_imsi = sim_cust_cntx[index].imsi;

                        if (strcmp((S8*)tmp_imsi, (S8*)curr_imsi) == 0)
                        {
                            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SIM_CUST_INIT_4, i);
                            is_match = MMI_TRUE;
                            break;
                        }
                    }
                }
            }

            srv_sms_get_sys_cust_file(file_name, curr_imsi);

            if (is_match == MMI_TRUE)
            {
                if (srv_sms_check_cust_file_valid(file_name, sms_total) == MMI_TRUE)
                {
                    exist_flag[index] = MMI_TRUE;
                    memcpy(new_cust_info->sys_imsi[sys_count++], curr_imsi, SRV_SMS_IMSI_LEN);
                }
                else
                {
                    srv_sms_delete_cust_file(file_name);
                }
            }
            else
            {
                if (remain_index < SIM_CUST_SYS_NUM)
                {
                    memcpy(new_cust_info->sys_imsi[remain_index++], curr_imsi, SRV_SMS_IMSI_LEN);
                    remain_count++;
                }
                else
                {
                    if ((pub_count < SIM_CUST_PUB_NUM) &&
                        (srv_sms_move_sys_cust_file_to_pub(curr_imsi) == MMI_TRUE))
                    {
                        memcpy(new_cust_info->pub_imsi[pub_count++], curr_imsi, SRV_SMS_IMSI_LEN);
                    }
                    else
                    {
                        srv_sms_delete_cust_file(file_name);
                    }
                }
            }
        }

        /* Check Public Cust File */
        for (i = 0; i < pub_file_num; i++)
        {
            U32 index = 0;
            U8 *curr_imsi = cust_info->pub_imsi[i];
            MMI_BOOL is_match = MMI_FALSE;
            U16 sms_total = 0;

            if (sys_count < sim_total)
            {
                for (index = 0; index < SMS_SIM_NUM; index++)
                {
                    sms_total = sim_cust_cntx[index].total;

                    if ((sms_total > 0) && (exist_flag[index] == MMI_FALSE))
                    {
                        U8 *tmp_imsi = sim_cust_cntx[index].imsi;

                        if (strcmp((S8*)tmp_imsi, (S8*)curr_imsi) == 0)
                        {
                            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SIM_CUST_INIT_5, i);
                            is_match = MMI_TRUE;
                            break;
                        }
                    }
                }
            }

            srv_sms_get_pub_cust_file(file_name, curr_imsi);

            if (is_match == MMI_TRUE)
            {
                if ((srv_sms_check_cust_file_valid(file_name, sms_total) == MMI_TRUE) &&
                    (srv_sms_move_pub_cust_file_to_sys(curr_imsi) == MMI_TRUE))
                {
                    exist_flag[index] = MMI_TRUE;
                    memcpy(new_cust_info->sys_imsi[sys_count++], curr_imsi, SRV_SMS_IMSI_LEN);
                }
                else
                {
                    srv_sms_delete_cust_file(file_name);
                }
            }
            else
            {
                if (pub_count < SIM_CUST_PUB_NUM)
                {
                    memcpy(new_cust_info->pub_imsi[pub_count++], curr_imsi, SRV_SMS_IMSI_LEN);
                }
                else
                {
                    srv_sms_delete_cust_file(file_name);
                }
            }
        }

        for (i = 0; i < SMS_SIM_NUM; i++)
        {
            U16 sms_total = sim_cust_cntx[i].total;

            if ((sms_total > 0) && (exist_flag[i] == MMI_FALSE))
            {
                U8 *curr_imsi = sim_cust_cntx[i].imsi;
                MMI_BOOL result;

                srv_sms_get_sys_cust_file(file_name, curr_imsi);

                result = srv_sms_create_default_sim_cust_file(file_name, sim_cust_cntx[i].total);

                MMI_ASSERT(result == MMI_TRUE);

                memcpy(new_cust_info->sys_imsi[sys_count++], curr_imsi, SRV_SMS_IMSI_LEN);
            }
        }

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SIM_CUST_INIT_6, sys_count, remain_count, pub_count);

        new_cust_info->sys_num = sys_count + remain_count;
        new_cust_info->pub_num = pub_count;

        srv_sms_write_cust_info_into_nvram(new_cust_info);
	}
	else
	{
		for(i=0; i < SMS_SIM_NUM; i++)
		{
			U16 sms_total = sim_cust_cntx[i].total;
			U8 *curr_imsi = sim_cust_cntx[i].imsi;
			if(sms_total > 0)
			{
				srv_sms_get_pub_cust_file(file_name, curr_imsi);
				if(srv_sms_check_cust_file_valid(file_name, sms_total) != MMI_TRUE)
				{
					MMI_BOOL result;
					srv_sms_delete_cust_file(file_name);
					result = srv_sms_create_default_sim_cust_file(file_name, sim_cust_cntx[i].total);
            		MMI_ASSERT(result == MMI_TRUE);
				}
			}		
		}
	}
    OslMfree(cust_info);
    OslMfree(new_cust_info);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_sim_cust_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_read_write_sim_cust_data(
             U16 record_index,
             srv_sms_sim_enum sim_id,
             srv_sms_sim_cust_data_struct *cust_data,
			 MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 file_name[MAX_SIM_CUST_FILE_NAME_LEN + 1];
    FS_HANDLE fs_hd;
    MMI_BOOL result = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    srv_sms_get_sim_cust_file_name(file_name, sim_id);
    if(flag == MMI_TRUE)//fix
    {
    fs_hd = FS_Open((WCHAR*)file_name, FS_READ_ONLY);
    }
	else
    {
        fs_hd = FS_Open((WCHAR*)file_name, FS_READ_WRITE);
    }
    if (fs_hd < 0)
    {
        result = MMI_FALSE;
    }
    else
    {
        S32 fs_error;
        U32 offset = record_index * sizeof(srv_sms_sim_cust_data_struct);
        U32 size;

        /* If seeking error, it may means the record is not existed, record index is invalid */
        fs_error = FS_Seek(fs_hd, offset, FS_FILE_BEGIN);
        if(flag == MMI_TRUE)
            fs_error = FS_Read(
                           fs_hd,
                           cust_data,
                           sizeof(srv_sms_sim_cust_data_struct),
                           &size);
        else
            fs_error = FS_Write(
                           fs_hd,
                           cust_data,
                           sizeof(srv_sms_sim_cust_data_struct),
						   &size);
        if (fs_error < FS_NO_ERROR)
        {
            result = MMI_FALSE;
        }

        FS_Close(fs_hd);
    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_cust_info_from_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_read_cust_info_from_nvram(srv_sms_sim_cust_info_struct* cust_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_SRV_SMS_SIM_CUST_DATA_LID,
        1,
        cust_info,
        sizeof(srv_sms_sim_cust_info_struct),
        &error_code);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_write_cust_info_into_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_write_cust_info_into_nvram(srv_sms_sim_cust_info_struct* cust_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(
        NVRAM_EF_SRV_SMS_SIM_CUST_DATA_LID,
        1,
        cust_info,
        sizeof(srv_sms_sim_cust_info_struct),
        &error_code);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_sys_cust_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_get_sys_cust_file(U16* file_name, U8* imsi_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(file_name, "%c:%s%s.dat", SRV_FMGR_SYSTEM_DRV, SRV_SMS_SIM_CUST_SYS_PATH, (S8*)imsi_number);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_pub_cust_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_get_pub_cust_file(U16 *file_name, U8 *imsi_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(file_name, "%c:%s%s.dat", SRV_FMGR_PUBLIC_DRV, SRV_SMS_SIM_CUST_PUB_PATH, (S8*)imsi_number);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_sys_cust_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_get_sys_cust_folder(U16 *folder_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(folder_name, "%c:%s", SRV_FMGR_SYSTEM_DRV, SRV_SMS_SIM_CUST_SYS_PATH);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_pub_cust_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_get_pub_cust_folder(U16 *folder_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(folder_name, "%c:%s", SRV_FMGR_PUBLIC_DRV, SRV_SMS_SIM_CUST_PUB_PATH);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_check_cust_file_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_sms_check_cust_file_valid(U16* file_name, U16 total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_hd;
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_hd = FS_Open(file_name, FS_READ_ONLY);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHECK_CUST_FILE_VALID, total, fs_hd);

    if (fs_hd < 0)
    {
        result = MMI_FALSE;
    }
    else
    {
        if (srv_sms_check_cust_file_content_valid(fs_hd, total) == MMI_FALSE)
        {
            result = MMI_FALSE;
        }

        FS_Close(fs_hd);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_check_cust_file_content_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_sms_check_cust_file_content_valid(FS_HANDLE fs_hd, U16 total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_error;
    U32 file_size;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_error = FS_GetFileSize(fs_hd, &file_size);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHECK_CUST_FILE_CONTENT_VALID, fs_error, file_size);

    if (fs_error >= FS_NO_ERROR)
    {
        U32 real_size = total * sizeof(srv_sms_sim_cust_data_struct);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHECK_CUST_FILE_CONTENT_VALID_1, real_size);

        if (file_size == real_size)
        {
            result = MMI_TRUE;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_move_sys_cust_file_to_pub
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_sms_move_sys_cust_file_to_pub(U8 *imsi_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 sys_file_name[MAX_SIM_CUST_FILE_NAME_LEN + 1];
    U16 pub_file_name[MAX_SIM_CUST_FILE_NAME_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_get_sys_cust_file(sys_file_name, imsi_number);
    srv_sms_get_pub_cust_file(pub_file_name, imsi_number);

    return srv_sms_move_cust_file(pub_file_name, sys_file_name);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_move_pub_cust_file_to_sys
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_sms_move_pub_cust_file_to_sys(U8 *imsi_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 sys_file_name[MAX_SIM_CUST_FILE_NAME_LEN + 1];
    U16 pub_file_name[MAX_SIM_CUST_FILE_NAME_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_get_sys_cust_file(sys_file_name, imsi_number);
    srv_sms_get_pub_cust_file(pub_file_name, imsi_number);

    return srv_sms_move_cust_file(sys_file_name, pub_file_name);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_move_cust_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_sms_move_cust_file(U16 *dest_file_name, U16 *src_file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_error = FS_Move(
                (const WCHAR*)src_file_name,
                (const WCHAR*)dest_file_name,
                FS_MOVE_KILL | FS_MOVE_OVERWRITE,
                NULL,
                NULL,
                0);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_MOVE_CUST_FILE, fs_error);

    if (fs_error < FS_NO_ERROR)
    {
        return MMI_FALSE;
    }
    else
    {
        FS_SetAttributes((const WCHAR*)dest_file_name, FS_ATTR_HIDDEN);
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_sim_cust_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_get_sim_cust_file_name(U16 *file_name, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = srv_sms_sim_id_to_sim_index(sim_id);

    srv_sms_get_sys_cust_file(file_name, sim_cust_cntx[index].imsi);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_create_default_sim_cust_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_sms_create_default_sim_cust_file(U16 *file_name, U16 total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sim_cust_data_struct *cust_data;
    FS_HANDLE fs_hd;
    MMI_BOOL result;
    U32 cust_data_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cust_data_size = total * sizeof(srv_sms_sim_cust_data_struct);
    
    cust_data = OslMalloc(cust_data_size);

    memset(cust_data, 0, cust_data_size);

    fs_hd = FS_Open(file_name, FS_READ_WRITE | FS_CREATE_ALWAYS);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CREATE_DEFAULT_SIM_CUST_FILE, fs_hd);

    if (fs_hd < FS_NO_ERROR)
    {
        result = MMI_FALSE;
    }
    else
    {
        S32 fs_error;
        U32 write_size;

        fs_error = FS_Write(
                        fs_hd,
                        cust_data,
                        cust_data_size,
                        &write_size);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CREATE_DEFAULT_SIM_CUST_FILE_1, fs_error);

        FS_Close(fs_hd);

        if (fs_error < FS_NO_ERROR)
        {
            result = MMI_FALSE;        
        }
        else
        {
            result = MMI_TRUE;
        }
    }

    OslMfree(cust_data);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_create_cust_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_sms_create_cust_folder(U16 *folder_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_handle = FS_CreateDir((const WCHAR*)folder_name);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CREATE_CUST_FOLDER, fs_handle);

    if ((fs_handle >= 0) || (fs_handle == FS_FILE_EXISTS))
    {
        FS_SetAttributes((const WCHAR*)folder_name, FS_ATTR_DIR | FS_ATTR_HIDDEN);
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_cust_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_delete_cust_file(U16 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_error = FS_Delete((const WCHAR*)file_name);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_CUST_FILE, fs_error);

    if (fs_error < 0)
    {
        /* mean user may change attribute to read only via usb */
        if (fs_error == FS_READ_ONLY_ERROR )
        {
            FS_SetAttributes((WCHAR*)file_name, FS_READ_WRITE);

            fs_error = FS_Delete((const WCHAR*)file_name);
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_CUST_FILE_1, fs_error);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_default_imsi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_get_default_imsi(U8 *imsi, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id == SRV_SMS_SIM_1)
    {
        strcpy((S8*)imsi, SRV_SMS_DEFAULT_IMSI_1);
    }
#if (MMI_MAX_SIM_NUM >= 2)
    else if (sim_id == SRV_SMS_SIM_2)
    {
        strcpy((S8*)imsi, SRV_SMS_DEFAULT_IMSI_2);
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if (sim_id == SRV_SMS_SIM_3)
    {
        strcpy((S8*)imsi, SRV_SMS_DEFAULT_IMSI_3);
    }
#endif
#if (MMI_MAX_SIM_NUM >= 4)	
    else if (sim_id == SRV_SMS_SIM_4)
    {
        strcpy((S8*)imsi, SRV_SMS_DEFAULT_IMSI_4);
    }
#endif
#endif /*  (MMI_MAX_SIM_NUM >= 2) */

}
#endif /* __SRV_SMS_SIM_CUST_DATA__ */
#endif /* __MOD_SMSAL__ */
