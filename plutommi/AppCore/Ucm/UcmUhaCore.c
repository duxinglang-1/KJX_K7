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
 *  UCMMain.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  UCM uri handler agnent source file
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_URI_AGENT__
#include "UcmSrvGProt.h"
#include "mmi_rp_core_ucm_def.h"
#include "UcmCoreProt.h"
#include "ProfilesSrvGprot.h"
#include "Gpiosrvgprot.h"
#include "string.h"
#include "UriAgentSrvGprot.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "Unicodexdcl.h"
#include "kal_public_api.h"
#include "gui_data_types.h"
#include "custom_events_notify.h"
#include "GlobalConstants.h"
#include "CustDataRes.h"
#include "mmi_frm_timer_gprot.h"
#include "mdi_audio.h"
#include "AlertScreen.h"


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_send_dtmf_check_hdlr
 * DESCRIPTION
 *  execute send dtmf if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_uha_send_dtmf_check_hdlr(U8* num, mmi_proc_func result_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 pos = 0;
    S32 keycode;
    srv_ucm_dtmf_digits_struct check_act_req;
    srv_ucm_result_enum permit_result; 
    S32 group_index_array[SRV_UCM_MAX_GROUP];
	srv_ucm_group_info_struct group_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (srv_ucm_query_group_count(SRV_UCM_ACTIVE_STATE, MMI_UCM_UHA_SUPPORT_CALL_TYPE, MMI_FALSE, group_index_array) == 0)
    {
        /* 1. check if there is no call */
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_URI_AGENT_SEND_DTMF_CHECK_HDLR, SRV_UCM_RESULT_NO_ACTIVE_CALL);
        return SRV_UCM_RESULT_NO_ACTIVE_CALL;
    }
    else
    {
        /* 2. prerare check struct */
        MMI_ASSERT(srv_ucm_query_group_count(SRV_UCM_ACTIVE_STATE, MMI_UCM_UHA_SUPPORT_CALL_TYPE, MMI_FALSE, NULL) == 1);

    	srv_ucm_query_group_data(group_index_array[0], &group_info);

        memset(&check_act_req, 0, sizeof(srv_ucm_dtmf_digits_struct));
        check_act_req.length = strlen((CHAR*)num);

        while (pos < check_act_req.length)
        {
            keycode = mmi_ucm_uha_convert_dtmf_ascii_to_keycode(num[pos]);

            if (MMI_TRUE == srv_ucm_is_valid_dtmf_digit(group_info.call_type, (U16)keycode))
            {
                MMI_ASSERT(keycode >= 0);
                check_act_req.dtmf_digits[pos].digit = keycode;
                pos++;
            }
            else
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_URI_AGENT_SEND_DTMF_CHECK_HDLR, SRV_UCM_RESULT_INVALID_NUMBER);
                return SRV_UCM_RESULT_INVALID_NUMBER;
            }
        }

        permit_result = srv_ucm_query_act_permit(SRV_UCM_SEND_DTMF_DIGITS_ACT, &check_act_req);

        /* 3. execute action if permit pass */
        if (SRV_UCM_RESULT_OK == permit_result)
        {
            srv_ucm_act_request(SRV_UCM_SEND_DTMF_DIGITS_ACT, &check_act_req, NULL, result_callback);

            if (srv_speech_is_phone_mute() == MMI_FALSE)
            {
                srv_gpio_set_device_mute(SRV_GPIO_AUDDEV_MISROPHONE, MMI_TRUE);
            }
        }
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_URI_AGENT_SEND_DTMF_CHECK_HDLR, permit_result);
        return permit_result;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_check_gsm_dtmf_number
 * DESCRIPTION
 *  Validation check before sending DTMF
 * PARAMETERS
 *  strNumber       [IN] dtmf digit in ascii
 * RETURNS
 *  pBOOL
 *****************************************************************************/
MMI_BOOL mmi_ucm_uha_check_gsm_dtmf(CHAR *strNumber)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 pos = 0;
    srv_ucm_group_info_struct group_info;
    S32 group_index_array[SRV_UCM_MAX_GROUP];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* get current active call type */
    if (srv_ucm_query_group_count(SRV_UCM_ACTIVE_STATE, MMI_UCM_UHA_SUPPORT_CALL_TYPE, MMI_FALSE, group_index_array) == 0)
    {
        return MMI_FALSE;
    }
    else
    {
    	srv_ucm_query_group_data(group_index_array[0], &group_info);
    }
    
    while (strNumber[pos] != 0)
    {
        if (MMI_TRUE == srv_ucm_is_valid_dtmf_digit(group_info.call_type, (U16)mmi_ucm_uha_convert_dtmf_ascii_to_keycode(strNumber[pos])))
        {
            pos ++;
        }
        else
        {
            return MMI_FALSE;
        }        
    }
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_parse_uri
 * DESCRIPTION
 *  Parse URL passed by uri agent
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum mmi_ucm_uha_parse_uri(U8 *param, U8 **result_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 num_uri[SRV_UCM_MAX_NUM_URI_LEN + 1];
    U8 *cur_pos = param;
    U8 *end_pos = NULL;
    U8 *attr = NULL;
    U8 *value = NULL;
    U8 *temp_buf = NULL;
    U32 len = 0;
    U32 temp_buf_len = 2000;
    U32 max_attr_len = 500;
    U32 max_value_len = 500;
    U32 attr_len = 0;
    U32 value_len = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    memset(num_uri, 0, SRV_UCM_MAX_NUM_URI_LEN + 1);
    
    cur_pos = (U8*)strstr((char*)param, ";");

    /* number */
    if (cur_pos == NULL)
    {
        len = strlen((char*)param);
    }
    else
    {
        len = cur_pos - param;
        cur_pos++;
    }

    if (len == 0)
    {
        return SRV_UCM_RESULT_EMPTY_NUMBER;
    }

    if (mmi_ucm_uha_remove_separator_in_phone_number((U8*)num_uri, (U8*)param, SRV_UCM_MAX_NUM_URI_LEN, len) == MMI_FALSE)
    {
        return SRV_UCM_RESULT_INVALID_NUMBER;
    }
    else
    {
        //MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G5_CALL,"[UCM] mmi_ucm_uha_parse_uri(),  num:%s", num_uri);
    }

    while (cur_pos != NULL)
    {
        end_pos = (U8*)strstr((char*)cur_pos, ";");

        if (end_pos != NULL)
        {
            len = end_pos - cur_pos;
        }
        else
        {
            len = strlen((char*)cur_pos);
        }

        if (len >= temp_buf_len)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_URI_AGENT_PARSE_URI_LEN_EXCEED, len);
            return SRV_UCM_RESULT_INVALID_NUMBER;
        }
        else
        {
            temp_buf = OslMalloc(temp_buf_len);
            memcpy(temp_buf, cur_pos, len);
            temp_buf[len] = 0;

            mmi_ucm_uha_to_lower_case((U8*) temp_buf);

            attr = temp_buf;
            value = (U8*)strstr((char*)temp_buf, "=");

            if (value != NULL)
            {
                attr_len = value - attr;
                value++;
                value_len = len - strlen((char*)value);
            }
            else
            {
                attr_len = strlen((char*)attr);
                value_len = 0;
            }

            if (attr_len >= max_attr_len || value_len >= max_value_len)
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_URI_AGENT_PARSE_URI_ATTR_LEN_EXCEED, attr_len, value_len);
                
                OslMfree(temp_buf);
                return SRV_UCM_RESULT_INVALID_NUMBER;
            }
            else
            {
                /* extension number */
                if (strcmp((char*)attr, MMI_UCM_UHA_EXT_NUM_STRING) == 0)
                {
                    /* number + 'p' + extension num */
                    if ((strlen((char*)num_uri) + 1 + value_len) >= SRV_UCM_MAX_NUM_URI_LEN + 1)
                    {
                        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_URI_AGENT_PARSE_URI_EXT_EXCEEDS, (strlen((char*)num_uri) + 1 + value_len));
                    
                        OslMfree(temp_buf);
                        return SRV_UCM_RESULT_INVALID_NUMBER;
                    }
                    else if (value == NULL)
                    {
                        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_URI_AGENT_PARSE_URI_EXT_NO_VALUE);
                        
                        OslMfree(temp_buf);
                        return SRV_UCM_RESULT_INVALID_NUMBER;
                    }
                    else
                    {
                        strcat((char*)num_uri, "p");
                        strcat((char*)num_uri, (char*)value);
                    }
                }
                /* only handle ext number currently */
            }

            OslMfree(temp_buf);

            if (end_pos != NULL)
            {
                cur_pos = end_pos + 1;
            }
            else
            {
                cur_pos = NULL;
            }
        }
    }

    len = strlen((char*)num_uri);
    *result_num = OslMalloc(len + 1);
    memcpy(*result_num, num_uri, len);
    (*result_num)[len] = 0;

    return SRV_UCM_RESULT_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_stop_sending_dtmf
 * DESCRIPTION
 *  stop sending dtmf
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_uha_stop_sending_dtmf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_URI_AGENT_STOP_SENDING_DTMF, 0);

    srv_ucm_act_request(SRV_UCM_STOP_DTMF_ACT, NULL, NULL, NULL);
                
    if (srv_speech_is_phone_mute() == MMI_FALSE)
    {
        srv_gpio_set_device_mute(SRV_GPIO_AUDDEV_MISROPHONE, MMI_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_to_lower_case
 * DESCRIPTION
 *  convert ASCII string to lower case
 * PARAMETERS
 *  str:          [IN]        ASCII string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_uha_to_lower_case(U8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = str;
    while (*ptr != 0)
    {
        if ((*ptr >= 'A') && (*ptr <= 'Z'))
        {
            *ptr += 'a' - 'A';
        }
        ptr++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_convert_dtmf_ascii_to_keycode
 * DESCRIPTION
 *  convert dtmf ascii code to key code
 * PARAMETERS
 *  dtmf_ascii:          [IN]        dtmf ascii digit
 * RETURNS
 *  negative means false. Otherwise the key code of the dtmf digit.
 *****************************************************************************/
S32 mmi_ucm_uha_convert_dtmf_ascii_to_keycode(U8 dtmf_ascii)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (dtmf_ascii)
    {
        case '0':
        {
            result = KEY_0;
        }
        break;

        case '1':
        {
            result = KEY_1;
        }
        break;

        case '2':
        {
            result = KEY_2;
        }
        break;

        case '3':
        {
            result = KEY_3;
        }
        break;

        case '4':
        {
            result = KEY_4;
        }
        break;

        case '5':
        {
            result = KEY_5;
        }
        break;

        case '6':
        {
            result = KEY_6;
        }
        break;

        case '7':
        {
            result = KEY_7;
        }
        break;

        case '8':
        {
            result = KEY_8;
        }
        break;

        case '9':
        {
            result = KEY_9;
        }
        break;

        case '*':
        {
            result = KEY_STAR;
        }
        break;

        case '#':
        {
            result = KEY_POUND;
        }
        break;

        default:
        {
            result = -1;
        }
        break;
        
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_remove_separator_in_phone_number
 * DESCRIPTION
 *  Remove separateros in phone number
 * PARAMETERS
 *  output:          [OUT]        asctii, output string after removing separator
 *  input_number:          [IN]        ascii, input phone number string
 *  output_len:          [IN]        output buffer length 
 *  input_number_len:          [IN]        input number length 
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_ucm_uha_remove_separator_in_phone_number(U8* output, U8* input_number, U32 output_len, U32 input_number_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 separator_chars[] = {'-','(',')','.',' '};
    U32 separator_chars_num = sizeof(separator_chars);
    U32 separator_index = 0;
    U32 output_index = 0;
    U32 input_index = 0;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(output, 0, output_len);

    for (input_index = 0; input_index < input_number_len; input_index++)
    {
        U8 input_char = input_number[input_index];
        
        for (separator_index = 0; separator_index < separator_chars_num; separator_index++)
        {
            if (input_char == separator_chars[separator_index])
            {
                break;
            }
        }

        if (separator_index == separator_chars_num)
        {
            if (output_index >= output_len)
            {
                return MMI_FALSE;
            }
            else
            {
                output[output_index] = input_char;
                output_index++;            
            }
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_uha_get_warning_tone
 * DESCRIPTION
 *  Get warning tone id 
 * PARAMETERS
 *  void
 * RETURNS
 *  error tone id 
 *****************************************************************************/
srv_prof_tone_enum mmi_ucm_uha_get_warning_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_tone_enum tone_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, MMI_UCM_UHA_SUPPORT_CALL_TYPE, NULL) > 0)
    {
        tone_id = WARNING_TONE_IN_CALL;
    }
    else
    {
        tone_id = WARNING_TONE;
    }

    return tone_id;
}

#endif /* __MMI_URI_AGENT__ */
