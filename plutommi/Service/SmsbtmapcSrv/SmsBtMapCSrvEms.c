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
 *  SmsEmsSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service EMS Utility
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
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "MMIDataType.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_nvram_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "custom_mmi_default_value.h"
#include "ps_public_enum.h"
#include "fs_type.h"
#include "fs_func.h"
#include "Unicodexdcl.h"
#include "string.h"
#include "fs_errcode.h"
#include "app_mem.h"

#include "mmi_common_app_trc.h"
#include "SmsSrvGProt.h"
#include "SmsBtMapCSrvProt.h"
#include "Ems.h"
#include "Gsm7BitNationalLang.h"
#include "SmsBtMapCSrvEms.h"
#include "Mmi_msg_context.h"
#include "SmsBtMapCSrvGProt.h"

#ifdef __SRV_SMS_BTMAPC__

/**************************************************************
* MARCO
**************************************************************/
#define SRV_SMS_MAX_EMS_DATA_NUM    3
#define SRV_SMS_ESCAPE_CHAR         (0x1B)
#define MAX_ADD_GSM_BUFF_SIZE       (((SRV_SMS_MAX_BUFF_SIZE / 2 / ENCODING_LENGTH) - 1) * ENCODING_LENGTH)
#define MAX_ADD_ASC_BUFF_SIZE       ((SRV_SMS_MAX_BUFF_SIZE / ENCODING_LENGTH) - 1)

#define DCS_FIELD_SIZE              (sizeof(U8))
#define TEXT_LEN_FIELD_SIZE         (sizeof(U16))
#define OBJECT_NUM_FIELD_SIZE       (sizeof(U16))
#define EMSOBJECT_FIELD_SIZE        (sizeof(EMSObject))
#define MIN_EMS_FILE_SIZE           (DCS_FIELD_SIZE + TEXT_LEN_FIELD_SIZE + OBJECT_NUM_FIELD_SIZE)


/**************************************************************
* Structure Declaration
**************************************************************/
typedef struct
{
    MMI_BOOL valid_flag;
    EMSData ems_data;
} srv_sms_ems_data_struct;


/**************************************************************
* Global Variables Declaration
**************************************************************/ 
#ifdef __EMS_NON_STD_7BIT_CHAR__
extern const U8 AsciiToDefaultArray[];
extern const U8 ExtendedAsciiToDefaultArray[];
#endif /* __EMS_NON_STD_7BIT_CHAR__ */

extern EMSTATUS EMSSetMsgClass(EMSData *emsData, kal_uint8 msg_class);
extern kal_uint16 EMSUsableTextLenEx(kal_uint8 dcs, EMSNationalLanguage* lang);

#ifdef __SMS_R8_NATION_LANGUAGE__
extern EMSNationalLanguageType srv_sms_btmapc_get_system_ems_lang_type(void);
#endif /* __SMS_R8_NATION_LANGUAGE__ */


/**************************************************************
* Extern Function Declaration
**************************************************************/


/**************************************************************
* Static Variables Defination
**************************************************************/
static U16 concat_ref_num = 65534;
static srv_sms_ems_data_struct ems_data_pool[SRV_SMS_MAX_EMS_DATA_NUM];
static U8 srv_sms_tpud_buff[MMI_SMS_MAX_VIEW_MSG_SEG][SRV_SMS_BTMAPC_MSG_LEN];

#ifdef __EMS_NON_STD_7BIT_CHAR__
const static U8 no_std_asc_to_default_array[] = 
{
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32,             /* 0 ~ 9 */
    10, 32, 32, 13, 32, 32, 16, 32, 18, 19,             /* 10 ~ 19 */
    20, 21, 22, 23, 24, 25, 26, 27, 32, 32,             /* 20 ~ 29 */
    32, 32, 32, 33, 34, 35, 2, 37, 38, 39,              /* 30 ~ 39 */
    40, 41, 42, 43, 44, 45, 46, 47, 48, 49,             /* 40 ~ 49 */
    50, 51, 52, 53, 54, 55, 56, 57, 58, 59,             /* 50 ~ 59 */
    60, 61, 62, 63, 0, 65, 66, 67, 68, 69,              /* 60 ~ 69 */
    70, 71, 72, 73, 74, 75, 76, 77, 78, 79,             /* 70 ~ 79 */
    80, 81, 82, 83, 84, 85, 86, 87, 88, 89,             /* 80 ~ 89 */
    90, 32, 32, 32, 32, 17, 32, 97, 98, 99,             /* 90 ~ 99 */
    100, 101, 102, 103, 104, 105, 106, 107, 108, 109,   /* 100 ~ 109 */
    110, 111, 112, 113, 114, 115, 116, 117, 118, 119,   /* 110 ~ 119 */
    120, 121, 122, 32, 32, 32, 32, 32, 32, 32,          /* 120 ~ 129 */
    32, 32, 32, 32, 32, 32, 32, 32, 83, 32,             /* 130 ~ 139 */
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32,             /* 140 ~ 149 */
    32, 32, 32, 32, 115, 32, 32, 32, 32, 89,            /* 150 ~ 159 */
    32, 64, 99, 1, 36, 3, 32, 95, 32, 32,               /* 160 ~ 169 */
    32, 32, 32, 64, 32, 32, 32, 32, 32, 32,             /* 170 ~ 179 */
    32, 32, 32, 32, 32, 32, 32, 32, 32, 32,             /* 180 ~ 189 */
    32, 96, 65, 65, 65, 65, 91, 14, 28, 9,              /* 190 ~ 199 */
    69, 31, 69, 69, 73, 73, 73, 73, 68, 93,             /* 200 ~ 209 */
    79, 79, 79, 79, 92, 32, 11, 85, 85, 85,             /* 210 ~ 219 */
    94, 89, 80, 30, 127, 97, 97, 97, 123, 15,           /* 220 ~ 229 */
    29, 99, 4, 5, 101, 101, 7, 105, 105, 105,           /* 230 ~ 239 */
    32, 125, 8, 111, 111, 111, 124, 32, 12, 6,          /* 240 ~ 249 */
    117, 117, 126, 121, 112, 121                        /* 250 ~ 255 */
};
#endif /* __EMS_NON_STD_7BIT_CHAR__ */


/**************************************************************
* Static Function Declaration
**************************************************************/
static U16 srv_sms_btmapc_read_ref_num_from_nvram(void);
static void srv_sms_btmapc_write_ref_num_to_nvram(U16 ref_num);

static srv_sms_cause_enum srv_sms_btmapc_add_ucs2_content_into_ems(
                            EMSData* ems_data,
                            char* content_buff,
                            U16 content_buff_size,
                            srv_sms_dcs_enum dcs);
#ifndef __ULC_SLIM_EMS__
static srv_sms_cause_enum srv_sms_btmapc_add_asc_content_into_ems(
                            EMSData* ems_data,
                            char* content_buff,
                            U16 content_buff_size,
                            srv_sms_dcs_enum dcs);
#endif

static srv_sms_cause_enum srv_sms_btmapc_add_nbit_content_into_ems(
                            EMSData* ems_data,
                            char* content_buff,
                            U16 content_buff_size,
			                srv_sms_dcs_enum dcs);


static void srv_sms_btmapc_replace_end_char(U8* ucs2_buff, U16 buff_size);

static U32 srv_sms_btmapc_get_ems_file_size(EMSData* ems_data);
static void srv_sms_btmapc_convert_ems_to_buff(U8* file_buff, EMSData* ems_data);
static void srv_sms_btmapc_convert_buff_to_ems(EMSData* ems_data, U8* file_buff);
#ifndef __ULC_SLIM_EMS__
static MMI_BOOL srv_sms_btmapc_fill_object_data(
                    U8* dest_buff,
                    U32* object_data_size,
                    U8 object_type,
                    EMSObjData* object_data);
static U32 srv_sms_btmapc_get_object_data(EMSObjData *object_data, U8 object_type, U8 *raw_data);
static void srv_sms_btmapc_set_default_text_format(EMSTextFormat *text_format);
#endif

#ifdef __EMS_NON_STD_7BIT_CHAR__
static U8 srv_sms_btmapc_get_max_used_segment(U8 seg);
#endif /* __EMS_NON_STD_7BIT_CHAR__ */




/**************************************************************
* Function Defination
**************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_sms_init_ems
 * DESCRIPTION
 *  Init EMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __EMS_REL5__
#ifndef __EMS_NOT_COMPRESS__
void *applib_mem_screen_ems_alloc(kal_uint32 mem_size)
{
    return applib_mem_screen_alloc(mem_size);
}
 
void applib_mem_screen_ems_free(void *mem_ptr)
{
    applib_mem_screen_free(mem_ptr);
}
#endif
#endif
void srv_sms_btmapc_init_ems(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_INIT_EMS);

    EMSInitialize();
#ifdef __EMS_REL5__
#ifdef __EMS_NOT_COMPRESS__
    EMSSetCompressMode(KAL_FALSE,NULL,NULL);
#else /* __EMS_NOT_COMPRESS__ */
    EMSSetCompressMode(KAL_TRUE,applib_mem_screen_ems_alloc,applib_mem_screen_ems_free);
#endif /* __EMS_NOT_COMPRESS__ */ 
#endif /* __EMS_REL5__ */ 
    EMSConcatMsgRefFunc(srv_sms_btmapc_get_and_inc_concat_ref_num);

#ifdef __EMS_NON_STD_7BIT_CHAR__
	EMSRegNonStdCharCallback(srv_sms_encode_no_sandard_char);
#endif /* __EMS_NON_STD_7BIT_CHAR__ */

    EMSRegNLtoUCS2Callback(gui_ems_nl_to_ucs2_callback);
    EMSRegUCS2toNLCallback(gui_ems_ucs2_to_nl_callback);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_malloc_ems_data
 * DESCRIPTION
 *  1. Allocate an EMSData Buffer (need to cast it to type EMSData)
 *  2. This API is for SMS application Internal Using
 * PARAMETERS
 *  void
 * RETURNS
 *  void*
 *****************************************************************************/
void* srv_sms_btmapc_malloc_ems_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSData *ems_data = NULL;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_MALLOC_EMS_DATA);

    for (i = 0; i < SRV_SMS_MAX_EMS_DATA_NUM; i++)
    {
        if (ems_data_pool[i].valid_flag == MMI_FALSE)
        {
            EMSTATUS result;

            ems_data = &ems_data_pool[i].ems_data;

            result = InitializeEMSData(ems_data, 0);
            ems_data->textBuffer[0] = 0;
            ems_data->textBuffer[1] = 0;
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_MALLOC_EMS_DATA_1, i, result);

            if (result == EMS_OK)
            {
                ems_data_pool[i].valid_flag = MMI_TRUE;
            }
            else
            {
                ems_data = NULL;
            }

            break;
        }
    }

    return ems_data;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_free_ems_data
 * DESCRIPTION
 *  1. Free an EMSData Buffer
 *  2. This API is for SMS application Internal Using
 * PARAMETERS
 *  ems_buff        [IN]        EMS Buffer
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_free_ems_data(void *ems_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSData *tmp_ems_data = (EMSData*)ems_data;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_FREE_EMS_DATA, ems_data);

    for (i = 0; i < SRV_SMS_MAX_EMS_DATA_NUM; i++)
    {
        if ((&ems_data_pool[i].ems_data == tmp_ems_data) &&
            (ems_data_pool[i].valid_flag == MMI_TRUE))
        {
            EMSTATUS result;

            result = ReleaseEMSData(tmp_ems_data);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_FREE_EMS_DATA_1, i, result);

            ems_data_pool[i].valid_flag = MMI_FALSE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_reset_ems_data
 * DESCRIPTION
 *  Reset EMSData Buffer
 *  This API is for SMS application Internal Using
 * PARAMETERS
 *  ems_data        [IN]        EMS Data   
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_reset_ems_data(void *ems_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSTATUS result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = ReleaseEMSData((EMSData*)ems_data);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_RESET_EMS_DATA, result);

    result = InitializeEMSData((EMSData*)ems_data, 0);
    ((EMSData*)ems_data)->textBuffer[0]= '\0';
    ((EMSData*)ems_data)->textBuffer[1]= '\0';
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_RESET_EMS_DATA_1, result);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_copy_ems_data
 * DESCRIPTION
 *  Copy EMSData Buffer to Destination EMS Buffer
 *  This API is for SMS application Internal Using
 * PARAMETERS
 *  dest_ems_data       [IN]        Destination EMS Data
 *  src_ems_data        [IN]        Source EMS Data
 * RETURNS
 *  MMI_BOOL    
 *****************************************************************************/
MMI_BOOL srv_sms_btmapc_copy_ems_data(void* dest_ems_data, void* src_ems_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __ULC_SLIM_EMS__
    EMSTATUS ems_result;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ems_result = CopyEMSData((EMSData*)dest_ems_data, (EMSData*)src_ems_data);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_EMS_DATA, ems_result);

    if (ems_result == EMS_OK)
    {
        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }

    return result;
#else
    return MMI_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_curr_concat_ref_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 srv_sms_btmapc_get_curr_concat_ref_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_CURR_CONCAT_REF_NUM, concat_ref_num);

    return concat_ref_num;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_concat_ref_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 srv_sms_btmapc_get_and_inc_concat_ref_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_AND_INC_CONCAT_REF_NUM, concat_ref_num);

    if (concat_ref_num == 65534)
    {
        concat_ref_num = srv_sms_btmapc_read_ref_num_from_nvram();
    }

    ++concat_ref_num;

    srv_sms_btmapc_write_ref_num_to_nvram(concat_ref_num);

    return concat_ref_num;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_ref_num_from_nvram
 * DESCRIPTION
 *  Get concatenate reference from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  reference
 *****************************************************************************/
static U16 srv_sms_btmapc_read_ref_num_from_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U16 ref_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ReadValue(NVRAM_SMS_CONCAT_MSG_REF_VALUE, (void*)&ref_num, DS_SHORT, &error) < 0)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_REF_NUM_FROM_NVRAM, error);
    }

    return ref_num;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_write_ref_num_from_nvram
 * DESCRIPTION
 *  Write referemce to NVRAM
 * PARAMETERS
 *  ref_num     [IN]        Reference
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_btmapc_write_ref_num_to_nvram(U16 ref_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WriteValue(NVRAM_SMS_CONCAT_MSG_REF_VALUE, (void*)&ref_num, DS_SHORT, &error) < 0)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_WRITE_REF_NUM_TO_NVRAM, error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_pack_ems
 * DESCRIPTION
 *  Pack EMSData to TP-UD
 * PARAMETERS
 *  pack_data   [OUT]
 *  ems_data    [IN]
 *  max_seg_num [IN]
 *  pack_flag   [IN]
 * RETURNS
 *  EMSTATUS
 *****************************************************************************/
EMSTATUS srv_sms_btmapc_pack_ems(
            srv_sms_btmapc_pack_struct *pack_data,
            EMSData *ems_data,
            srv_sms_btmapc_pack_enum pack_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSTATUS result;
    U8 seg_num = SRV_SMS_MAX_SEND_SEG;
#ifdef __EMS_NON_STD_7BIT_CHAR__
    MMI_BOOL is_non_std = MMI_FALSE;
#endif /* __EMS_NON_STD_7BIT_CHAR__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_PACK_EMS, pack_data, ems_data, seg_num, pack_flag);

    do
    {
    #ifdef __EMS_NON_STD_7BIT_CHAR__
        if (pack_flag & SRV_SMS_PACK_SAVE_NON_STD)
        {
            /*
             * For the Saved SMS, the view content should be same as it saved.
             * So, if the content contains Non-Standard Characters, we need to save it
             * as UCS2 DCS instead of replacing the Non-Standard Character to 
             * Standard GSM Default 7Bit chaaracter.
             */
            if (ems_data->dcs == SMSAL_DEFAULT_DCS)
            {
                is_non_std = srv_sms_btmapc_is_no_standard_string(
                                ems_data->textBuffer,
                                ems_data->textLength);

                if (is_non_std == MMI_TRUE)
                {
                    seg_num = srv_sms_btmapc_get_max_used_segment(seg_num);

                    result = EMSSetEditSegs(ems_data, seg_num);

                    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_PACK_EMS_1, result);

                    if (result != EMS_OK)
                    {
                        break;
                    }

                    result = EMSSetDCS(ems_data, SMSAL_UCS2_DCS);                    

                    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_PACK_EMS_2, result);

                    if (result != EMS_OK)
                    {
                        break;
                    }
                }
            }
        }
    #endif /* __EMS_NON_STD_7BIT_CHAR__ */ 

    #ifdef __EMS_DYNAMIC_SEG_NUM__
        if (pack_flag & SRV_SMS_PACK_DYNAMIC_SEG)
        {
            result = EMSSetEditSegs(ems_data, seg_num);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_PACK_EMS_3, result);

            if (result != EMS_OK)
            {
                break;
            }
        }    
    #endif /* __EMS_DYNAMIC_SEG_NUM__ */ 

        result = EMSPack(
                    ems_data,
                    1,
                    &pack_data->total_seg,
                    pack_data->tpud,
                    pack_data->tpud_len);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_PACK_EMS_4, result);

        if (result != EMS_OK)
        {
        #ifdef __EMS_NON_STD_7BIT_CHAR__
            if (is_non_std == MMI_TRUE)
            {
                /*
                 * Reset the DCS to the original DCS of the EMSData
                 */
                EMSSetDCS(ems_data, SMSAL_DEFAULT_DCS);
            }
        #endif /* __EMS_NON_STD_7BIT_CHAR__ */ 
            break;
        }

        pack_data->udhi = ems_data->udhi;
        pack_data->ori_dcs = ems_data->ps_dcs;

    #ifdef __EMS_NON_STD_7BIT_CHAR__
        if (is_non_std == MMI_TRUE)
        {
            result = EMSSetDCS(ems_data, SMSAL_DEFAULT_DCS);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_PACK_EMS_5, result);
        }
    #endif /* __EMS_NON_STD_7BIT_CHAR__ */ 
    } while (0);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_PACK_EMS_6, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_unpack_ems
 * DESCRIPTION
 *  Unpack SMS after read/receive
 * PARAMETERS
 *  dcs         [IN]        Dcs
 *  fo          [IN]        Fo
 *  ori_dcs     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_unpack_ems(
        EMSData *ems_data,
        srv_sms_btmapc_unpack_struct *unpack_data,
        srv_sms_unpack_enum unpack_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 udhi;
    MMI_BOOL is_reset_default = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UNPACK_EMS, ems_data, unpack_data, unpack_flag);

    if (unpack_data->total_seg == 1)
    {
        udhi = GetUDHIBit(unpack_data->fo);
    }
    else
    {
        udhi = MMI_TRUE;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UNPACK_EMS_1, unpack_data->total_seg, udhi);

    do
    {
        EMSTATUS ems_result;
        U8 dcs = SMSAL_DEFAULT_DCS;
        U32 i;

        for (i = 0; i < unpack_data->total_seg; i++)
        {
            if (unpack_data->tpud[i] != NULL)
            {
                dcs = unpack_data->dcs[i];
                break;
            }
        }

        ems_result = EMSSetDCS(ems_data, dcs);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UNPACK_EMS_2, ems_result);

        if (ems_result != EMS_OK)
        {
            break;
        }

        ems_result = EMSUnPack(
                        ems_data,
                        udhi,
                        unpack_data->total_seg,
                        unpack_data->tpud,
                        unpack_data->tpud_len,
                        unpack_data->dcs);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UNPACK_EMS_3, ems_result);

        if (ems_result != EMS_OK)
        {
            break;
        }

        ems_result = EMSSetOriDCS(ems_data, unpack_data->ori_dcs, unpack_data->total_seg);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UNPACK_EMS_4, ems_result);

        if (ems_result != EMS_OK)
        {
            break;
        }

        is_reset_default = MMI_FALSE;
    } while(0);


    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UNPACK_EMS_5, is_reset_default);

    if (is_reset_default == MMI_TRUE)
    {
        /* Unpack the TP-UD as Default */
        if (unpack_data->total_seg == 1)
        {
            udhi = MMI_FALSE;
        }
        else
        {
            udhi = MMI_TRUE;
        }

        EMSSetDCS(ems_data, SMSAL_DEFAULT_DCS);

        EMSUnPack(
            ems_data,
            udhi,
            unpack_data->total_seg,
            unpack_data->tpud,
            unpack_data->tpud_len,
            unpack_data->dcs);
    }

    if((ems_data->dcs == SRV_SMS_DCS_8BIT) && 
       (unpack_flag & SRV_SMS_UNPACK_ORI_8BIT_DATA))
    {
        ems_data->textLength = srv_sms_btmapc_wchar_to_char(
                                    (S8*)ems_data->textBuffer,
                                    (S16*)ems_data->textBuffer,
                                    (ems_data->textLength / ENCODING_LENGTH));
    }
    else if (unpack_flag & SRV_SMS_UNPACK_REPLACE_END_CHAR)
    {
        /* Replace the END char to CR char to make sure all of 
         * the text content will be showed */
        srv_sms_btmapc_replace_end_char(ems_data->textBuffer, ems_data->textLength);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_convert_msg_data_to_spdu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_sms_cause_enum srv_sms_btmapc_convert_msg_data_to_ems(
                    EMSData* ems_data,
                    srv_sms_btmapc_int_msg_data_struct* msg_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum cause = SRV_SMS_CAUSE_NO_ERROR;
    srv_sms_para_enum para_flag = msg_data->para_flag;
    srv_sms_dcs_enum dcs;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONVERT_MSG_DATA_TO_EMS, ems_data, msg_data, para_flag);

    if (para_flag & SRV_SMS_PARA_DCS)
    {
        dcs = msg_data->dcs;
    }
    else
    {
        dcs = SRV_SMS_DCS_7BIT;
    }

    do
    {
        EMSTATUS ems_result;

        if (para_flag & SRV_SMS_PARA_PORT)
        {
            ems_result = EMSSetPortNum(ems_data, msg_data->src_port, msg_data->dest_port);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONVERT_MSG_DATA_TO_EMS_1, ems_result);

            if (ems_result != EMS_OK)
            {
                cause = SRV_SMS_CAUSE_UNKNOWN_ERROR;
                break;
            }
        }

        if (para_flag & SRV_SMS_PARA_CLASS)
        {
            ems_result = EMSSetMsgClass(ems_data, (U8)msg_data->class);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONVERT_MSG_DATA_TO_EMS_2, ems_result);

            if (ems_result != EMS_OK)
            {
                cause = SRV_SMS_CAUSE_UNKNOWN_ERROR;
                break;
            }
        }

        if (para_flag & SRV_SMS_PARA_CONTENT_FILE)
        {

            cause = srv_sms_btmapc_read_content_into_ems(
                        ems_data,
                        msg_data->content_file_path,
                        dcs);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONVERT_MSG_DATA_TO_EMS_3, cause);
        }
        else if (para_flag & SRV_SMS_PARA_CONTENT_BUFF)
        {
           cause = srv_sms_btmapc_add_content_into_ems(
                        ems_data,
                        msg_data->content_buff,
                        msg_data->content_buff_size,
                        dcs,
                        MMI_FALSE); 
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONVERT_MSG_DATA_TO_EMS_4, cause);
        }
    } while (0);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONVERT_MSG_DATA_TO_EMS_5, cause);

    return cause;
}



/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_content_from_file
 * DESCRIPTION
 *  Read Content from file, then add it into EMSData
 * PARAMETERS
 *  ems_data    [OUT]   EMSData
 *  file_path   [IN]    File path of content
 *  dcs         [IN]    DCS
 * RETURNS
 *  srv_sms_cause_enum    
 *****************************************************************************/
srv_sms_cause_enum srv_sms_btmapc_read_content_into_ems(
                    EMSData* ems_data,
                    char* file_path,
                    srv_sms_dcs_enum dcs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum cause = SRV_SMS_CAUSE_NO_ERROR;
    FS_HANDLE fs_hd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_CONTENT_INTO_EMS, ems_data, file_path, dcs);

    fs_hd = FS_Open((WCHAR*)file_path, FS_READ_ONLY);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_CONTENT_INTO_EMS_1, fs_hd);

    if (fs_hd > 0)
    {
        U32 file_size;

        FS_GetFileSize(fs_hd, &file_size);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_CONTENT_INTO_EMS_2, file_size);

        if (file_size > 0)
        {
            U32 remaining_len = file_size;

            while (remaining_len > 0)
            {
                S8 *read_buff;
                S32 read_buff_len;
                S32 read_size;
                S32 fs_error;

                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_CONTENT_INTO_EMS_3, remaining_len);

                if (remaining_len > SRV_SMS_MAX_BUFF_SIZE)
                {
                    read_buff_len = SRV_SMS_MAX_BUFF_SIZE;
                    remaining_len = remaining_len - read_buff_len;
                }
                else
                {
                    read_buff_len = remaining_len;
                    remaining_len = 0;
                }

                read_buff = OslMalloc(read_buff_len);

                fs_error = FS_Read(fs_hd, read_buff, read_buff_len, (UINT*)&read_size);

                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_CONTENT_INTO_EMS_4, fs_error, read_size);

                if (fs_error < 0)
                {
                    cause = SRV_SMS_CAUSE_DATA_INVALID;                    
                }
                else
                {
                    cause = srv_sms_btmapc_add_content_into_ems(
                                ems_data,
                                read_buff,
                                (U16)read_buff_len,
                                dcs,
                                MMI_FALSE);
                }

                OslMfree(read_buff);

                if (cause != SRV_SMS_CAUSE_NO_ERROR)
                {
                    break;
                }
            }
        }
    }
    else
    {
        cause = SRV_SMS_CAUSE_DATA_INVALID;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_CONTENT_INTO_EMS_5, cause);

    FS_Close(fs_hd);

    return cause;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_content_into_ems
 * DESCRIPTION
 *  Add Content Buffer into EMSData
 * PARAMETERS
 *  ems_data            [OUT]   EMSdata
 *  content_buff        [IN]    Content Buffer
 *  content_buff_size   [IN]    Content Buffer Size
 *  dcs                 [IN]    DCS
 * RETURNS
 *  srv_sms_cause_enum
 *****************************************************************************/
srv_sms_cause_enum srv_sms_btmapc_add_content_into_ems(
                    EMSData* ems_data,
                    char* content_buff,
                    U16 content_buff_size,
                    srv_sms_dcs_enum dcs,
                    MMI_BOOL is_asc_content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum cause = SRV_SMS_CAUSE_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_CONTENT_INTO_EMS, ems_data, content_buff, content_buff_size);

    if ((content_buff != NULL) && (content_buff_size > 0))
    {
    #ifndef __ULC_SLIM_EMS__
        if (is_asc_content == MMI_TRUE)
        {
            cause = srv_sms_btmapc_add_asc_content_into_ems(
                        ems_data,
                        content_buff,
                        content_buff_size,
                        dcs);
        }
        else
    #endif /* __ULC_SLIM_EMS__ */
        {
            cause = srv_sms_btmapc_add_ucs2_content_into_ems(
                        ems_data,
                        content_buff,
                        content_buff_size,
                        dcs);
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_CONTENT_INTO_EMS_1, cause);

    return cause;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_ucs2_content_into_ems
 * DESCRIPTION
 *  Add Content Buffer (UCS2 Format) into EMSData
 * PARAMETERS
 *  ems_data            [OUT]   EMSdata
 *  content_buff        [IN]    Content Buffer
 *  content_buff_size   [IN]    Content Buffer Size
 *  dcs                 [IN]    DCS
 * RETURNS
 *  srv_sms_cause_enum
 *****************************************************************************/
static srv_sms_cause_enum srv_sms_btmapc_add_ucs2_content_into_ems(
                            EMSData* ems_data,
                            char* content_buff,
                            U16 content_buff_size,
                            srv_sms_dcs_enum dcs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum cause = SRV_SMS_CAUSE_NO_ERROR;
    U8 new_dcs = dcs;
    U16 real_buff_size = content_buff_size;
    U16 char_num = content_buff_size;
    EMSTATUS ems_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_UCS2_CONTENT_INTO_EMS, dcs);

    char_num = mmi_ucs2strlen(content_buff);

    /* If the content_buff_size may larger than the character real buffer occupied */
    if(dcs != SRV_SMS_DCS_8BIT)
    {
        if (char_num > (content_buff_size / ENCODING_LENGTH))
        {
            char_num = content_buff_size / ENCODING_LENGTH;
        }
        else
        {
            real_buff_size = char_num * ENCODING_LENGTH;
        }
        if (new_dcs == SRV_SMS_DCS_7BIT)
        {
            if (srv_sms_btmapc_check_ucs2(content_buff, (U16)char_num) == MMI_TRUE)
            {
                new_dcs = SRV_SMS_DCS_UCS2;
            }
            else
            {
                new_dcs = SRV_SMS_DCS_7BIT;
            }
        }
    }
    ems_result = EMSSetDCS(ems_data, new_dcs);
    if (ems_result != EMS_OK)
    {
        cause = SRV_SMS_CAUSE_UNKNOWN_ERROR;
    }
    else
    {
        switch (new_dcs)
        {
            case SRV_SMS_DCS_UCS2:
            #ifndef __ULC_SLIM_EMS__
                ems_result = AddString(ems_data, (U8*)content_buff, char_num, NULL);
                if (ems_result != EMS_OK)
                {
                    cause = SRV_SMS_CAUSE_DATA_EXCEED;
                    break;
                }
            #else
                memcpy(ems_data->textBuffer, (U8*)content_buff, char_num<<1);
				ems_data->textLength = (char_num<<1);
				cause = SRV_SMS_CAUSE_NO_ERROR;//EMS_OK;
            #endif
                break;
            case SRV_SMS_DCS_7BIT:
            case SRV_SMS_DCS_8BIT:
            default:
            {
	            cause = srv_sms_btmapc_add_nbit_content_into_ems(
                            ems_data,
                            content_buff,
			                real_buff_size,
					        (srv_sms_dcs_enum)new_dcs);
                break;
            }
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_UCS2_CONTENT_INTO_EMS_4, cause);

    return cause;
}


#ifndef __ULC_SLIM_EMS__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_asc_content_into_ems
 * DESCRIPTION
 *  Add Content Buffer(ASCII Format) into EMSData
 * PARAMETERS
 *  ems_data            [OUT]   EMSdata
 *  content_buff        [IN]    Content Buffer
 *  content_buff_size   [IN]    Content Buffer Size
 *  dcs                 [IN]    DCS
 * RETURNS
 *  srv_sms_cause_enum
 *****************************************************************************/
static srv_sms_cause_enum srv_sms_btmapc_add_asc_content_into_ems(
                            EMSData* ems_data,
                            char* content_buff,
                            U16 content_buff_size,
                            srv_sms_dcs_enum dcs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum cause = SRV_SMS_CAUSE_NO_ERROR;
    U8 new_dcs = dcs;
    U16 char_num = content_buff_size;
    EMSTATUS ems_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_ASC_CONTENT_INTO_EMS, dcs);

    if (new_dcs == SRV_SMS_DCS_7BIT)
    {
        char_num = strlen(content_buff);

        if (char_num > content_buff_size)
        {
            char_num = content_buff_size;
        }

        if (srv_sms_btmapc_check_ucs2_with_asc_content(content_buff, (U16)char_num) == MMI_TRUE)
        {
            new_dcs = SRV_SMS_DCS_UCS2;
        }
        else
        {
            new_dcs = SRV_SMS_DCS_7BIT;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_ASC_CONTENT_INTO_EMS_1, new_dcs);

    ems_result = EMSSetDCS(ems_data, new_dcs);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_ASC_CONTENT_INTO_EMS_2, ems_result);

    if (ems_result != EMS_OK)
    {
        cause = SRV_SMS_CAUSE_UNKNOWN_ERROR;
    }
    else
    {
        if (new_dcs == SRV_SMS_DCS_8BIT)
        {
            cause = srv_sms_btmapc_add_nbit_content_into_ems(
                        ems_data,
                        content_buff,
                        content_buff_size,
                        (srv_sms_dcs_enum)new_dcs);
        }
        else
        {
            S8 *remaining_buff = content_buff;
            U16 remaining_buff_len = char_num;
            S8 *add_buff = NULL;

            while ((remaining_buff != NULL) && (remaining_buff_len > 0))
            {
                U16 add_char_num;
                S8 *temp_buff = remaining_buff;
                U16 temp_char_num;

                if (remaining_buff_len > MAX_ADD_ASC_BUFF_SIZE)
                {
                    temp_char_num = MAX_ADD_ASC_BUFF_SIZE;
                    remaining_buff = remaining_buff + MAX_ADD_ASC_BUFF_SIZE;
                    remaining_buff_len = remaining_buff_len - MAX_ADD_ASC_BUFF_SIZE;
                }
                else
                {
                    temp_char_num = remaining_buff_len;
                    remaining_buff = NULL;
                    remaining_buff_len = 0;
                }

                if (add_buff == NULL)
                {
                    add_buff = OslMalloc((temp_char_num + 1)* ENCODING_LENGTH);
                }

                mmi_asc_n_to_ucs2(add_buff, temp_buff, temp_char_num);

                add_char_num = temp_char_num;

                if (new_dcs == SRV_SMS_DCS_UCS2)
                {
                    ems_result = AddString(ems_data, (U8*)add_buff, add_char_num, NULL);

                    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_ASC_CONTENT_INTO_EMS_3, ems_result);

                    if (ems_result != EMS_OK)
                    {
                        cause = SRV_SMS_CAUSE_DATA_EXCEED;
                        break;
                    }
                }
                else
                {
                    cause = srv_sms_btmapc_add_nbit_content_into_ems(
                                ems_data,
                                add_buff,
                                (U16)(add_char_num * ENCODING_LENGTH),
                                (srv_sms_dcs_enum)new_dcs);

                    if (cause != SRV_SMS_CAUSE_NO_ERROR)
                    {
                        break;
                    }
                }
            }

            if (add_buff != NULL)
            {
                OslMfree(add_buff);
            }
        }          
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_ASC_CONTENT_INTO_EMS_4, cause);

    return cause;
}
#endif /* __ULC_SLIM_EMS__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_nbit_content_into_ems
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_sms_cause_enum srv_sms_btmapc_add_nbit_content_into_ems(
                            EMSData* ems_data,
                            char* content_buff,
                            U16 content_buff_size,
                            srv_sms_dcs_enum dcs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum cause = SRV_SMS_CAUSE_NO_ERROR;
#ifndef __ULC_SLIM_EMS__
    EMSTATUS ems_result = EMS_OK;
    S8 *remaining_buff = content_buff;
#endif
    U16 remaining_buff_len = content_buff_size;
#ifdef __ULC_SLIM_EMS__
	U16 add_char_num;
	kal_uint8 *temp_textBuffer;
	temp_textBuffer = ems_data->textBuffer;
#endif /* __ULC_SLIM_EMS__ */

#ifdef __ULC_SLIM_EMS__
	if(dcs == SRV_SMS_DCS_7BIT)
    {
		add_char_num = srv_sms_btmapc_add_escape_char((CHAR*)temp_textBuffer, content_buff, remaining_buff_len / ENCODING_LENGTH);
    }
    else
    {
        if(dcs == SRV_SMS_DCS_8BIT)
        {
            if((content_buff_size) > (153 * SRV_SMS_MAX_SEG - 1))
            {
                return SRV_SMS_CAUSE_DATA_EXCEED;
            }
        }
		srv_sms_btmapc_char_to_wchar((CHAR*)temp_textBuffer, content_buff, remaining_buff_len);
	    add_char_num = remaining_buff_len;
    }
    add_char_num = add_char_num<<1;
    ems_data->textLength = add_char_num;
#else
#ifdef __SMS_R8_NATION_LANGUAGE__
	if(dcs == SRV_SMS_DCS_7BIT)
    {
    EMSNationalLanguage sys_lang;
    mmi_7bit_get_national_lang_table(&sys_lang);   
    ems_result = EMSSetNationalLanguage(ems_data, &sys_lang);
	}
    if (ems_result != EMS_OK)
    {
        cause = SRV_SMS_CAUSE_UNKNOWN_ERROR;
    }
    else
#endif /* __SMS_R8_NATION_LANGUAGE__ */
    {
        S8 *add_buff = NULL;

        while ((remaining_buff != NULL) && (remaining_buff_len > 0))
        {
            U16 add_char_num;
            S8 *temp_buff = remaining_buff;
            U16 temp_char_num;
			U16 temp_size;
            if(dcs == SRV_SMS_DCS_7BIT)//fix
            {
				temp_size = MAX_ADD_GSM_BUFF_SIZE;
            }
			else
            {
				temp_size = SRV_SMS_MAX_BUFF_SIZE / ENCODING_LENGTH;
            }
            if (remaining_buff_len > temp_size)
            {
                if(dcs == SRV_SMS_DCS_7BIT)
                {
                	temp_char_num = temp_size / ENCODING_LENGTH;
                }
				else
                {
					temp_char_num = temp_size;
                }
                remaining_buff = remaining_buff + temp_size;
                remaining_buff_len = remaining_buff_len - temp_size;
            }
            else
            {
            	if(dcs == SRV_SMS_DCS_7BIT)
                {
                    temp_char_num = remaining_buff_len / ENCODING_LENGTH;
                }
                else
                {
		           temp_char_num = remaining_buff_len;
                }
                remaining_buff = NULL;
                remaining_buff_len = 0;
            }
            /* If add_buff is not NULL, it means that it have allocated the max buffer,
             * don't need to allocate again */
            if (add_buff == NULL)
            {
            	if(dcs == SRV_SMS_DCS_7BIT)
                {
                    add_buff = OslMalloc((temp_char_num * 2 + 1) * ENCODING_LENGTH);
                }
                else
                {
		            add_buff = OslMalloc(temp_char_num * ENCODING_LENGTH);
                }
            }
			if(dcs == SRV_SMS_DCS_7BIT)
            {
                add_char_num = srv_sms_btmapc_add_escape_char(add_buff, temp_buff, temp_char_num);
            }
            else
			{
			    srv_sms_btmapc_char_to_wchar(add_buff, temp_buff, temp_char_num);
				add_char_num = temp_char_num;
			}			
            ems_result = AddString(ems_data, (U8*)add_buff, add_char_num, NULL);
            if (ems_result != EMS_OK)
            {
                cause = SRV_SMS_CAUSE_DATA_EXCEED;
                break;
            }    
        }

        if (add_buff != NULL)
        {
            OslMfree(add_buff);
        }
    }
#endif
    return cause;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_char_to_wchar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
U32 srv_sms_btmapc_char_to_wchar(char* out_wchar_buff, char *in_char_buff, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *wchar_buff = (U16*)out_wchar_buff;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHAR_TO_WCHAR);

    for (i = 0; i < len; i++)
    {
        wchar_buff[i] = (U16)in_char_buff[i];
    }

    return i;
}



/*****************************************************************************
 * FUNCTION
 *  srv_sms_wchar_to_char
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
U32 srv_sms_btmapc_wchar_to_char(char* out_char_buff, S16 *in_wchar_buff, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *char_buff = (U8 *)out_char_buff;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHAR_TO_WCHAR);

    for (i = 0; i < len; i++)
    {
        char_buff[i] = (U8)in_wchar_buff[i];
    }

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_check_ucs2
 * DESCRIPTION
 *  Check whether the DCS of text buffer is UCS2.
 *  If all of the characters in the text buffer is in GSM 7Bit character sets,
 *  the DCS is GSM 7Bit, otherwise the DCS is UCS2.
 * PARAMETERS
 *  ucs2_text_buff       [IN]    text buff (Unicode Format)
 *  char_num             [IN]    Character number 
 * RETURNS
 *  return MMI_TRUE if UCS2 characters exists, else return MMI_FALSE
 *****************************************************************************/
MMI_BOOL srv_sms_btmapc_check_ucs2(char* ucs2_text_buff, U16 char_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    U16 *ucs2_buff = (U16*)ucs2_text_buff;
    U16 c;
    U32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHECK_UCS2, char_num);

#ifdef __EMS_NON_STD_7BIT_CHAR__
    if (srv_sms_btmapc_is_7bit_setting(SRV_SMS_SIM_1) == MMI_TRUE)
    {
        while (count < char_num)
        {
            c = ucs2_buff[count];

            if ((!mmi_7bit_check_gsm(c)) && (!mmi_7bit_check_gsm_ext_character(c)) &&
                (srv_sms_btmapc_is_no_standard_character(c) != TRUE))
            {
                result = MMI_TRUE;
                break;
            }

            count++;
        }
    }
    else
#endif /* __EMS_NON_STD_7BIT_CHAR__ */
    {
        while (count < char_num)
        {
            c = ucs2_buff[count];

            if ((!mmi_7bit_check_gsm(c)) && (!mmi_7bit_check_gsm_ext_character(c)))
            {
                result = MMI_TRUE;
                break;
            }

            count++;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHECK_UCS2_1, result);

    return result;
}


#ifndef __ULC_SLIM_EMS__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_check_ucs2_with_asc_content
 * DESCRIPTION
 *  check whether the DCS of text buffer (ASC Format) is UCS2.
 * PARAMETERS
 *  asc_text_buff   [IN]    text buff (Unicode Format)    
 *  char_num        [IN]    Number of char in buffer
 * RETURNS
 *  return true if UCS2 char exists, else return false
 *****************************************************************************/
MMI_BOOL srv_sms_btmapc_check_ucs2_with_asc_content(char* asc_text_buff, U16 char_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    U16 c;
    U32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHECK_UCS2_WITH_ASC_CONTENT, char_num);

#ifdef __EMS_NON_STD_7BIT_CHAR__
    if (srv_sms_btmapc_is_7bit_setting(SRV_SMS_SIM_1) == MMI_TRUE)
    {
        while (count < char_num)
        {
            c = (U16)asc_text_buff[count];

            if ((!mmi_7bit_check_gsm(c)) && (!mmi_7bit_check_gsm_ext_character(c)) &&
                (srv_sms_btmapc_is_no_standard_character(c) != TRUE))
            {
                result = MMI_TRUE;
                break;
            }

            count++;
        }
    }
    else
#endif /* __EMS_NON_STD_7BIT_CHAR__ */
    {
        while (count < char_num)
        {
            c = (U16)asc_text_buff[count];

            if ((!mmi_7bit_check_gsm(c)) && (!mmi_7bit_check_gsm_ext_character(c)))
            {
                result = MMI_TRUE;
                break;
            }

            count++;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHECK_UCS2_WITH_ASC_CONTENT_1, result);

    return result;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_no_standard_character
 * DESCRIPTION
 *  check whether a character is non_standard GSM 7Bit character
 * PARAMETERS
 *  ucs2_char       [IN]    UCS2 Character
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sms_btmapc_is_no_standard_character(U16 ucs2_char)
{
#ifdef __EMS_NON_STD_7BIT_CHAR__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SMS_R8_NATION_LANGUAGE__
    if ((!mmi_7bit_check_gsm(ucs2_char)) || (!mmi_7bit_check_gsm_ext_character(ucs2_char)))
#endif /* __SMS_R8_NATION_LANGUAGE__ */
    {
        U8 high_byte = (U8) ((ucs2_char & 0XFF00) >> 8);
        U8 low_tyte = (U8) (ucs2_char & 0X00FF);

        if (high_byte == 0 && no_std_asc_to_default_array[low_tyte] != AsciiToDefaultArray[low_tyte])
        {
            result = MMI_TRUE;
        }
    }

    return result;
#else /* __EMS_NON_STD_7BIT_CHAR__ */
    return MMI_FALSE;
#endif /* __EMS_NON_STD_7BIT_CHAR__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_no_standard_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  UCS2_char       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_btmapc_is_no_standard_string(U8* ucs2_text_buff, U16 text_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __EMS_NON_STD_7BIT_CHAR__
    MMI_BOOL result = MMI_FALSE;
    U16 c;
    U32 text_offset = 0;
    U8 *text_buff = ucs2_text_buff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_IS_NO_STANDARD_STRING);

    while (text_offset < text_len)
    {
        c = (U16)(text_buff[text_offset] | (text_buff[text_offset + 1] << 8));

        if (srv_sms_btmapc_is_no_standard_character(c) == TRUE)
        {                
            
            result = MMI_TRUE;
            break;
        }

        text_offset += 2;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_IS_NO_STANDARD_STRING_1, result);

    return result;
#else /* __EMS_NON_STD_7BIT_CHAR__ */
    return MMI_FALSE;
#endif /* __EMS_NON_STD_7BIT_CHAR__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_encode_no_sandard_char
 * DESCRIPTION
 *  Encode two byte to a non-standard character
 * PARAMETERS
 *  high_byte       [IN]    High Byte
 *  low_byte        [IN]    Low Byte
 * RETURNS
 *  U16
 *****************************************************************************/
U16 srv_sms_btmapc_encode_no_sandard_char(U8 high_byte, U8 low_byte)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __EMS_NON_STD_7BIT_CHAR__
    static MMI_BOOL is_ext_char = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (high_byte == 0)
    {
        if (low_byte == SRV_SMS_ESCAPE_CHAR)
        {
            is_ext_char = MMI_TRUE;
        }
        else
        {
            if (is_ext_char == MMI_TRUE)
            {
                low_byte = ExtendedAsciiToDefaultArray[low_byte];
            }
            else
            {
                low_byte = no_std_asc_to_default_array[low_byte];
            }

            is_ext_char = MMI_FALSE;
        }
    }
#endif /* __EMS_NON_STD_7BIT_CHAR__ */

    return (U16)((high_byte << 8) | low_byte);
}


#ifdef __EMS_NON_STD_7BIT_CHAR__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_max_used_segment
 * DESCRIPTION
 *  get the max used segment
 * PARAMETERS
 *  seg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_sms_btmapc_get_max_used_segment(U8 seg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 used_seg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (seg == 1)
    {
        /* Max GSM 7Bit Content Length is 160, Max UCS2 Content Length is 70 */
        used_seg = (160 + 69) / 70;
    }
    else
    {
        /* For Concatenated SMS,
         * Max GSM 7Bit Content Length is 153, Max UCS2 Content Length is 67 */
        used_seg = ((seg * 153) + 66) / 67;
    }
    return used_seg;
}
#endif /* __EMS_NON_STD_7BIT_CHAR__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sms_replace_end_char
 * DESCRIPTION
 *  Replace the END char to CR char
 * PARAMETERS
 *  ucs2_text   [IN]        unicode text
 *  text_len    [IN]        length
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_btmapc_replace_end_char(U8* ucs2_buff, U16 buff_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *ucs2_text = (U16*)ucs2_buff;
    U16 char_num = buff_size / ENCODING_LENGTH;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_REPLACE_END_CHAR);

    for (i = 0; i < char_num; i++)
    {    
        if (ucs2_text[i] == '\0')
        {
            ucs2_text[i] = '\n';
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_escape_char
 * DESCRIPTION
 *  Added '0x1b' before extionsion char.
 *  Caller must make sure the dest_buff size is at least 
 *  twice more than src_buff size.
 * PARAMETERS
 *  dest_buff       [OUT]       
 *  src_buff        [IN]        
 *  char_num        [IN]        Number of char in srcBuffer
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_sms_btmapc_add_escape_char(char* dest_buff, char* src_buff, U16 char_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *src_buffer = (U16*)src_buff;
    U16 *dest_buffer = (U16*)dest_buff;
    U32 src_count = 0;
    U16 dest_count = 0;
    U16 c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_ESCAPE_CHAR, char_num);

    while (src_count < char_num)
    {
        c = src_buffer[src_count++];

		if (c != SRV_SMS_ESCAPE_CHAR)
		{
            if (mmi_7bit_check_gsm_ext_character(c))
            {
                dest_buffer[dest_count++] = SRV_SMS_ESCAPE_CHAR;
            }

            dest_buffer[dest_count++] = c;
        }
    }

    dest_buffer[dest_count] = '\0';

    return dest_count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_remove_escape_char
 * DESCRIPTION
 *  remove '0x1b' before extionsion char
 * PARAMETERS
 *  dest_buff       [OUT]       
 *  src_buff        [IN]        
 *  char_num        [IN]        Number of char in srcBuffer
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_sms_btmapc_remove_escape_char(char* dest_buff, char* src_buff, U16 char_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *src_buffer = (U16*)src_buff;
    U16 *dest_buffer = (U16*)dest_buff;
    U32 src_count = 0;
    U16 dest_count = 0;
    U16 c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_REMOVE_ESCAPE_CHAR, char_num);

    while (src_count < char_num)
    {
        c = src_buffer[src_count++];

        if (c != SRV_SMS_ESCAPE_CHAR)
        {
            dest_buffer[dest_count++] = c;
        }
    }

    dest_buffer[dest_count] = '\0';

    return dest_count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_remove_escape_char_ext
 * DESCRIPTION
 *  remove '0x1b' before extionsion char
 * PARAMETERS
 *  dest_buff       [OUT]       
 *  src_buff        [IN]        
 *  char_num        [IN]        Number of char in srcBuffer
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_sms_btmapc_remove_escape_char_ext(
        char* dest_buff,
        char* src_buff,
        U16 dest_char_num,
        U16 src_char_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *src_buffer = (U16*)src_buff;
    U16 *dest_buffer = (U16*)dest_buff;
    U32 src_count = 0;
    U32 dest_count = 0;
    U16 c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((src_count < src_char_num) && (dest_count < dest_char_num))
    {
        c = src_buffer[src_count++];

        if (c != SRV_SMS_ESCAPE_CHAR)
        {
            dest_buffer[dest_count++] = c;
        }
    }

    dest_buffer[dest_count] = '\0';

    return dest_count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_count_extension_char
 * DESCRIPTION
 *  count the number of extension characters in buff
 * PARAMETERS
 *  buff            [IN]        
 *  char_num        [IN]        
 * RETURNS
 *  number of extension characters in buff
 *****************************************************************************/
U32 srv_sms_btmapc_count_extension_char(char* buff, U32 char_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *ucs2_buff = (U16*)buff;
    U32 ext_char_num = 0;
    U32 count = 0;
    U16 c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COUNT_EXTENSION_CHAR, char_num);

    while (count < char_num)
    {
        c = ucs2_buff[count];

        if (mmi_7bit_check_gsm_ext_character(c))
        {
            ext_char_num++;
        }

        count++;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COUNT_EXTENSION_CHAR_1, ext_char_num);

    return ext_char_num;
}


/*****************************************************************************
* FUNCTION
*  srv_sms_sms_get_usable_text_len
* DESCRIPTION
*  This function is used to get number of max characters of SMS message.
* PARAMETERS
*  dcs            [IN]
* RETURNS
*  number of max characters
*****************************************************************************/
U16 srv_sms_btmapc_sms_get_usable_text_len(U8 dcs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSNationalLanguage sys_lang;
#ifdef __SMS_R8_NATION_LANGUAGE__
    EMSNationalLanguageType curr_lang_type;                
    EMSNationalLanguageType sys_lang_type;
#endif /* __SMS_R8_NATION_LANGUAGE__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SMS_GET_USABLE_TEXT_LEN, dcs);

#ifdef __SMS_R8_NATION_LANGUAGE__
    curr_lang_type = mmi_7bit_get_national_lang();
    
    sys_lang_type = srv_sms_btmapc_get_system_ems_lang_type();
    
    if (curr_lang_type != sys_lang_type)
    {
        mmi_7bit_set_national_lang(sys_lang_type);
    }
    
    mmi_7bit_get_national_lang_table(&sys_lang);

    if (curr_lang_type != sys_lang_type)
    {
        mmi_7bit_set_national_lang(curr_lang_type);
    }  
#else /* __SMS_R8_NATION_LANGUAGE__ */
    sys_lang.locking_shift = EMS_NL_DEFAULT;
    sys_lang.single_shift = EMS_NL_DEFAULT;
#endif /* __SMS_R8_NATION_LANGUAGE__ */

    return ((U16)EMSUsableTextLenEx(dcs, &sys_lang));
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_pack_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_get_pack_data(srv_sms_btmapc_pack_struct* pack_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_INIT_PACK_DATA);

    for (i = 0; i < SRV_SMS_MAX_SEG; i++)
    {
        pack_data->tpud[i] = (U8*)srv_sms_tpud_buff[i];
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_unpack_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_get_unpack_data(srv_sms_btmapc_unpack_struct* unpack_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_INIT_UNPACK_DATA);

    for (i = 0; i < SRV_SMS_MAX_SEG; i++)
    {
        unpack_data->tpud[i] = (U8*)srv_sms_tpud_buff[i];
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_write_ems_data_to_file
 * DESCRIPTION
 *  1. Write an EMSData Buffer to File;
 *  2. If the return value is less than zero, it result is FALSE, otherwise it is TRUE.
 *  3. This API is for SMS application Internal Using
 * PARAMETERS
 *  file_path       [IN]    File Path (UCS2 Format)
 *  ems_data        [IN]    EMS Data Buffer
 *  fs_error        [OUT]   File System Error
 * RETURNS
 *  S32
 *****************************************************************************/
S32 srv_sms_btmapc_write_ems_data_to_file(char *file_path, void *ems_data, S32* fs_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 write_result = -1;
    U32 file_size;
    U8 *ems_file_buff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_WRITE_EMS_DATA_TO_FILE, file_path, ems_data);

    *fs_error = FS_NO_ERROR;

    file_size = srv_sms_btmapc_get_ems_file_size((EMSData*)ems_data);

    ems_file_buff = (U8*)applib_mem_screen_alloc(file_size);

    if (ems_file_buff != NULL)
    {
        FS_HANDLE file_handle;

        file_handle = FS_Open((WCHAR*)file_path, FS_CREATE_ALWAYS | FS_READ_WRITE);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_WRITE_EMS_DATA_TO_FILE_1, file_handle);

        if (file_handle >= 0)
        {
            S32 tmp_fs_error;
        
            srv_sms_btmapc_convert_ems_to_buff(ems_file_buff, (EMSData*)ems_data);

            tmp_fs_error = FS_Write(
                            file_handle,
                            ems_file_buff,
                            file_size,
                            (UINT*)&write_result);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_WRITE_EMS_DATA_TO_FILE_2, tmp_fs_error);

            if (tmp_fs_error < 0)
            {
                write_result = -1;
                *fs_error = tmp_fs_error;
            }
        }
        else
        {
            *fs_error = file_handle;
        }

        FS_Close(file_handle);

        applib_mem_screen_free(ems_file_buff);
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_WRITE_EMS_DATA_TO_FILE_3, write_result);

    return write_result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_ems_data_from_file
 * DESCRIPTION
 *  1. Read an EMSData From File
 *  2. If the return value is less than zero, it result is FALSE, otherwise it is TRUE.
 *  3. This API is for SMS application Internal Using
 * PARAMETERS
 *  ems_data        [IN]    EMS Data Buffer
 *  file_path       [IN]    File Path (UCS2 Format)
 *  fs_error        [OUT]   File System Error
 * RETURNS
 *  S32
 *****************************************************************************/
S32 srv_sms_btmapc_read_ems_data_from_file(void *ems_data, char *file_path, S32* fs_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    S32 read_result = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_EMS_DATA_FROM_FILE, ems_data, file_path);

    *fs_error = FS_NO_ERROR;

    file_handle = FS_Open((WCHAR*)file_path, FS_READ_ONLY);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_EMS_DATA_FROM_FILE_1, file_handle);

    if (file_handle >= 0)
    {
        U32 file_size = 0;

        FS_GetFileSize(file_handle, &file_size);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_EMS_DATA_FROM_FILE_2, file_size);

        if (file_size >= MIN_EMS_FILE_SIZE)
        {
            U8 *ems_file_buff;

            ems_file_buff = (U8*)applib_mem_screen_alloc(file_size);

            if (ems_file_buff != NULL)
            {
                S32 tmp_fs_error;

                tmp_fs_error = FS_Read(
                                file_handle,
                                ems_file_buff,
                                file_size,
                                (UINT*)&read_result);

                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_EMS_DATA_FROM_FILE_3, fs_error);

                if (tmp_fs_error >= 0)
                {
                    srv_sms_btmapc_convert_buff_to_ems((EMSData*)ems_data, ems_file_buff);
                }
                else
                {
                    read_result = -1;
                    *fs_error = tmp_fs_error;
                }

                applib_mem_screen_free(ems_file_buff);
            }
        }

        FS_Close(file_handle);
    }
    else
    {
        read_result = -1;
        *fs_error = file_handle;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_EMS_DATA_FROM_FILE_4, read_result);

    return read_result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_ems_file_size
 * DESCRIPTION
 *  Get ems object file sze
 * PARAMETERS
 *  void
 * RETURNS
 *  return file size.
 *****************************************************************************/
static U32 srv_sms_btmapc_get_ems_file_size(EMSData *ems_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
#ifndef __ULC_SLIM_EMS__
    EMSObject *curr_object;
#endif
    U32 file_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_EMS_FILE_SIZE);

    /* [Text Part] */
    file_size = DCS_FIELD_SIZE + TEXT_LEN_FIELD_SIZE + ems_data->textLength;

    /* [Object Part] */
    file_size += OBJECT_NUM_FIELD_SIZE;

#ifndef __ULC_SLIM_EMS__
    curr_object = ems_data->listHead;

    while (curr_object != NULL)
    {
        file_size += EMSOBJECT_FIELD_SIZE;

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_EMS_FILE_SIZE_1, curr_object->Type);

        switch (curr_object->Type)
        {
            case EMS_TYPE_TEXT_FORMAT:
            {
                file_size += sizeof(EMSTextFormat);
                break;
            }

            case EMS_TYPE_PREDEF_SND:
            case EMS_TYPE_PREDEF_ANM:
            {
                break;
            }

            case EMS_TYPE_USERDEF_SND:
            {
                file_size += sizeof(EMSSound) + curr_object->data->sound.pdu_length;
                break;
            }

            case EMS_TYPE_USERDEF_ANM:
            {
                file_size += sizeof(EMSAnim) + curr_object->data->animation.pdu_length;
                break;
            }

            case EMS_TYPE_PIC:
            {
                file_size += sizeof(EMSPicture) + curr_object->data->picture.pdu_length;
                break;
            }

            default:
            {
                break;
            }
        }

        curr_object = curr_object->next;
    }
#endif
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_EMS_FILE_SIZE_2, file_size);

    return file_size;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_convert_ems_to_buff
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_btmapc_convert_ems_to_buff(U8 *file_buff, EMSData *ems_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __ULC_SLIM_EMS__
    U32 object_data_size;
    EMSObject *curr_object = NULL;
    U16 object_num = 0;
#endif
    U32 curr_offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONVERT_EMS_TO_BUFF);

    /* [File Content] := [Text Part][Object Part] */
    /* [Text Part] := [DCS][Text Length][Text Buffer] */
    /* [DCS] */
    file_buff[0] = ems_data->dcs;
    curr_offset = DCS_FIELD_SIZE;

    /* [Text Length] */    
    memcpy(file_buff + curr_offset, &(ems_data->textLength), TEXT_LEN_FIELD_SIZE);
    curr_offset += TEXT_LEN_FIELD_SIZE;

    /* [Text Buffer] */
    memcpy(file_buff + curr_offset, ems_data->textBuffer, ems_data->textLength);
    curr_offset += ems_data->textLength;

#ifndef __ULC_SLIM_EMS__
    /* [Object Part] := [Object Num][Object 1] ... [Object N] */
    curr_object = ems_data->listHead;

    /* Count the objects number */
    while (curr_object != NULL)
    {
        curr_object = curr_object->next;
        object_num++;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONVERT_EMS_TO_BUFF_1, object_num);

    /* [Object Num] */
    memcpy(file_buff + curr_offset, &object_num, OBJECT_NUM_FIELD_SIZE);
    curr_offset += OBJECT_NUM_FIELD_SIZE;

    curr_object = ems_data->listHead;

    /* [Object N] := [EMSObject][Object Data] */
    while (curr_object != NULL)
    {
        MMI_BOOL copy_result;

        /* [EMSObject] */
        memcpy(file_buff + curr_offset, curr_object, EMSOBJECT_FIELD_SIZE);
        curr_offset += EMSOBJECT_FIELD_SIZE;

        object_data_size = 0;

        /* [Object Data] */
        copy_result = srv_sms_btmapc_fill_object_data(
                        file_buff + curr_offset,
                        &object_data_size,
                        curr_object->Type,
                        curr_object->data);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONVERT_EMS_TO_BUFF_2, copy_result);

        if (copy_result == MMI_TRUE)
        {
            curr_offset += object_data_size;
        }
        else
        {
            /* If FALSE, Skip the unsupported object */
            curr_offset -= EMSOBJECT_FIELD_SIZE;
        }

        curr_object = curr_object->next;
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_convert_buff_to_ems
 * DESCRIPTION
 *  convert to EMS
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_btmapc_convert_buff_to_ems(EMSData *ems_data, U8 *file_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 file_buff_offset = 0;
    U8 dcs;
    U16 text_len = 0;
#ifndef __ULC_SLIM_EMS__
    U8 *text_buff;
    U16 object_num;
    U8 *object_buff;
    U16 obj_buff_offset = 0;
    U16 prev_text_offset = 0;
    U32 i;
    MMI_BOOL is_with_txt_fmt = MMI_FALSE;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONVERT_BUFF_TO_EMS);

    /* [DCS] */
    dcs = file_buff[0];
    file_buff_offset += DCS_FIELD_SIZE;

    ems_data->dcs = dcs;
    ems_data->ps_dcs = dcs;

    /* [Text Length] */
    memcpy(&text_len, (file_buff + file_buff_offset), TEXT_LEN_FIELD_SIZE);
    file_buff_offset += TEXT_LEN_FIELD_SIZE;

#ifndef __ULC_SLIM_EMS__
    /* [Text Buffer] */
    text_buff = file_buff + file_buff_offset;
    file_buff_offset += text_len;

    /* [Object Num] */
    memcpy(&object_num, (file_buff + file_buff_offset), OBJECT_NUM_FIELD_SIZE);
    file_buff_offset += OBJECT_NUM_FIELD_SIZE;

    object_buff = file_buff + file_buff_offset;

    ResetCurrentPosition(ems_data);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONVERT_BUFF_TO_EMS_1, object_num);

    for (i = 0; i < object_num; i++)
    {
        EMSObject curr_object;
        EMSObjData curr_obj_data;
        U32 object_data_size;
        U16 backward_step = 0;

        memcpy(&curr_object, (object_buff + obj_buff_offset), EMSOBJECT_FIELD_SIZE);
        obj_buff_offset += EMSOBJECT_FIELD_SIZE;

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONVERT_BUFF_TO_EMS_2, curr_object.OffsetToText, prev_text_offset);

        if (curr_object.OffsetToText > prev_text_offset)
        {
            EMSTextFormat *txt_fmt = NULL;
            EMSTextFormat tmp_txt_fmt;

            if (is_with_txt_fmt == MMI_TRUE)
            {
                txt_fmt = &tmp_txt_fmt;

                srv_sms_btmapc_set_default_text_format(txt_fmt);
            }

            AddString(
                ems_data,
                (U8*)(text_buff + prev_text_offset),
                (U16)((curr_object.OffsetToText - prev_text_offset) / 2),
                txt_fmt);

            prev_text_offset = curr_object.OffsetToText;
        }
        /* For case: [Text Format Begin][Text][Object][Text][Text Format End],
         * the object is in the middle of the formated text */
        else if (curr_object.OffsetToText < prev_text_offset)
        {
            backward_step = (prev_text_offset - curr_object.OffsetToText) / 2;

            BackwardCurrentPosition(ems_data, backward_step);
        }

        object_data_size = srv_sms_btmapc_get_object_data(
                            &curr_obj_data,
                            curr_object.Type,
                            (object_buff + obj_buff_offset));
        obj_buff_offset += object_data_size;

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONVERT_BUFF_TO_EMS_3, curr_object.Type);

        switch (curr_object.Type)
        {
            case EMS_TYPE_TEXT_FORMAT:
            {
                EMSTextFormat *text_format = &curr_obj_data.text_format;

                is_with_txt_fmt = MMI_TRUE;

                AddString(
                    ems_data,
                    (U8*)(text_buff + curr_object.OffsetToText),
                    (U16) (text_format->textLength / 2),
                    text_format);

        		prev_text_offset += text_format->textLength;
                break;
            }

            case EMS_TYPE_PREDEF_ANM:
            case EMS_TYPE_PREDEF_SND:
            {
                AddObject(ems_data, curr_object.Type, NULL, curr_object.PredefNo);

                if (backward_step > 0)
                {
                    GoToEndPosition(ems_data);
                }
                break;
            }

            case EMS_TYPE_USERDEF_SND:
            case EMS_TYPE_USERDEF_ANM:
            case EMS_TYPE_PIC:
            {
                AddObject(ems_data, curr_object.Type, &curr_obj_data, curr_object.PredefNo);

                if (backward_step > 0)
                {
                    GoToEndPosition(ems_data);
                }
                break;
            }
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONVERT_BUFF_TO_EMS_4, prev_text_offset, text_len);

    if (prev_text_offset < text_len)
    {
        EMSTextFormat *txt_fmt = NULL;
        EMSTextFormat tmp_txt_fmt;

        if (is_with_txt_fmt == MMI_TRUE)
        {
            txt_fmt = &tmp_txt_fmt;

            srv_sms_btmapc_set_default_text_format(txt_fmt);
        }

        AddString(
            ems_data,
            (U8*) (text_buff + prev_text_offset),
            (U16) ((text_len - prev_text_offset) / 2),
            txt_fmt);
    }

    ResetCurrentPosition(ems_data);
#endif
}


#ifndef __ULC_SLIM_EMS__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_fill_object_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_sms_btmapc_fill_object_data(
                    U8* dest_buff,
                    U32* object_data_size,
                    U8 object_type,
                    EMSObjData* object_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    U32 curr_offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_FILL_OBJECT_DATA, object_type);
    /* [Object Data]:= [EMSObjData][PDU Data] */
    switch (object_type)
    {
        case EMS_TYPE_TEXT_FORMAT:
        {
            EMSTextFormat *text_ptr = &(object_data->text_format);

            /* [EMSTextFormat] */
            memcpy(dest_buff + curr_offset, text_ptr, sizeof(EMSTextFormat));
            curr_offset += sizeof(EMSTextFormat);
            break;
        }

        case EMS_TYPE_PREDEF_SND:
        case EMS_TYPE_PREDEF_ANM:
        {
            break;
        }

        case EMS_TYPE_USERDEF_SND:
        {
            EMSSound *sound_ptr = &(object_data->sound);

            /* [EMSSound] */
            memcpy(dest_buff + curr_offset, sound_ptr, sizeof(EMSSound));
            curr_offset += sizeof(EMSSound);

            /* [PDU Data] */
            memcpy(dest_buff + curr_offset, sound_ptr->pdu, sound_ptr->pdu_length);
            curr_offset += sound_ptr->pdu_length;
            break;
        }

        case EMS_TYPE_USERDEF_ANM:
        {
            EMSAnim *anm_ptr = &(object_data->animation);

            /* [EMSAnim] */
            memcpy(dest_buff + curr_offset, anm_ptr, sizeof(EMSAnim));
            curr_offset += sizeof(EMSAnim);

            /* [PDU Data] */
            memcpy(dest_buff + curr_offset, anm_ptr->pdu, anm_ptr->pdu_length);
            curr_offset += anm_ptr->pdu_length;
            break;
        }

        case EMS_TYPE_PIC:
        {
            EMSPicture *pic_ptr = &(object_data->picture);

            /* [EMSPicture] */
            memcpy(dest_buff + curr_offset, pic_ptr, sizeof(EMSPicture));
            curr_offset += sizeof(EMSPicture);

            /* [PDU Data] */
            memcpy(dest_buff + curr_offset, pic_ptr->pdu, pic_ptr->pdu_length);
            curr_offset += pic_ptr->pdu_length;
            break;
        }

        default:
        {
            result = MMI_FALSE;
            break;
        }
    }

    *object_data_size = curr_offset;
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_FILL_OBJECT_DATA_1, curr_offset);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_object_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  U32
 *****************************************************************************/
static U32 srv_sms_btmapc_get_object_data(EMSObjData *object_data, U8 object_type, U8 *raw_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 object_data_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_OBJECT_DATA, object_type);

    switch (object_type)
    {
        case EMS_TYPE_TEXT_FORMAT:
        {
            EMSTextFormat *text_ptr = &(object_data->text_format);

            memcpy(text_ptr, raw_data, sizeof(EMSTextFormat));
            object_data_size = sizeof(EMSTextFormat);
            break;
        }

        case EMS_TYPE_USERDEF_SND:
        {
            EMSSound *sound_ptr = &(object_data->sound);

            memcpy(sound_ptr, raw_data, sizeof(EMSSound));
            object_data_size = sizeof(EMSSound);

            sound_ptr->pdu = raw_data + sizeof(EMSSound);
            object_data_size += sound_ptr->pdu_length;
            break;
        }

        case EMS_TYPE_USERDEF_ANM:
        {
            EMSAnim *anm_ptr = &(object_data->animation);

            memcpy(anm_ptr, raw_data, sizeof(EMSAnim));
            object_data_size = sizeof(EMSAnim);

            anm_ptr->pdu = raw_data + sizeof(EMSAnim);
            object_data_size += anm_ptr->pdu_length;
            break;
        }

        case EMS_TYPE_PIC:
        {
            EMSPicture *pic_ptr = &(object_data->picture);

            memcpy(pic_ptr, raw_data, sizeof(EMSPicture));
            object_data_size = sizeof(EMSPicture);

            pic_ptr->pdu = raw_data + sizeof(EMSPicture);
            object_data_size += pic_ptr->pdu_length;
            break;
        }
    
        case EMS_TYPE_PREDEF_SND:
        case EMS_TYPE_PREDEF_ANM:
        default:
        {
            break;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_OBJECT_DATA_1, object_data_size);

    return object_data_size;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_default_text_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_btmapc_set_default_text_format(EMSTextFormat *text_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    text_format->FontSize = EMS_FONTSIZE_NORMAL;
    text_format->Alignment = EMS_ALIGN_LANG_DEP;
    text_format->isBold = KAL_FALSE;
    text_format->isItalic = KAL_FALSE;
    text_format->isUnderline = KAL_FALSE;
    text_format->isStrikethrough = KAL_FALSE;
    text_format->bgColor = EMS_BLACK;
    text_format->fgColor = EMS_WHITE;
    text_format->textLength = 2;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_content_from_tpud
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_btmapc_get_content_from_tpud(
        U8 *content,
        U16 content_size,
        U8 fo,
        U8 dcs,
        U8 *tpdu,
        U8 tpdu_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_CONTENT_FROM_TPUD, content, content_size, fo, dcs);

    if (tpdu_len > 0)
    {
        U8 is_obj_present = 0;
        EMSTATUS result;
        U8 *tpdu_list[1];
        U8 tpdu_len_list[1];
        U8 *temp_content = NULL;        
        U8 *text_buff;
        U16 text_buff_size;
        U16 text_len = 0;

        tpdu_list[0] = tpdu;
        tpdu_len_list[0] = tpdu_len;

    #ifdef __EMS_NON_STD_7BIT_CHAR__
        if ((dcs == SMSAL_DEFAULT_DCS) || (dcs == SMSAL_UCS2_DCS))
    #else /* __EMS_NON_STD_7BIT_CHAR__ */
        if (dcs == SMSAL_DEFAULT_DCS)
    #endif /* __EMS_NON_STD_7BIT_CHAR__ */ 
        {
            text_buff_size = content_size * 2;

            temp_content = OslMalloc(text_buff_size);

            text_buff = temp_content;
        }
        else
        {
            text_buff_size = content_size;
            text_buff = content;
        }

        result = EMSMsgPreview(
                    1,
                    dcs,
                    (U8)GetUDHIBit(fo),
                    tpdu_list,
                    tpdu_len_list,
                    text_buff_size,
                    text_buff,
                    &is_obj_present,
                    &text_len);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_CONTENT_FROM_TPUD_1, result, text_len);

        if (result == EMS_OK)
        {
            U16 char_num = (U16)(text_len / ENCODING_LENGTH);

            MMI_ASSERT(text_buff_size >= text_len);
            
            srv_sms_btmapc_replace_end_char(text_buff, text_len);

        #ifdef __EMS_NON_STD_7BIT_CHAR__
            if ((dcs == SMSAL_DEFAULT_DCS) || (dcs == SMSAL_UCS2_DCS))
        #else /* __EMS_NON_STD_7BIT_CHAR__ */
            if (dcs == SMSAL_DEFAULT_DCS)
        #endif /* __EMS_NON_STD_7BIT_CHAR__ */ 
            {           
                srv_sms_btmapc_remove_escape_char_ext(
                    (S8*)content,
                    (S8*)text_buff,
                    (U16)(content_size / ENCODING_LENGTH),
                    char_num);
            }
            else
            {
                content[text_len] = '\0';
                content[text_len + 1] = '\0';
            }
        }
        else
        {
            content[0] = '\0';
            content[1] = '\0';
        }

        if (temp_content != NULL)
        {
            OslMfree(temp_content);
        }
    }
    else
    {
        content[0] = '\0';
        content[1] = '\0';
    }
}

#endif /* __SRV_SMS_BTMAPC__ */
#endif /* __MOD_SMSAL__ */

