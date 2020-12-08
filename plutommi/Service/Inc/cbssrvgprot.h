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
 *  CbsSrvGProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  CBS(Cell Broadcast Service) Service External Header File
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#ifndef __SRV_CBS_SRV_GPROT_H__
#define __SRV_CBS_SRV_GPROT_H__

#include "MMI_features.h"
#ifdef __SRV_CBS_SUPPORT__

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "ps_public_enum.h"
#include "nvram_common_defs.h"
#include "mmi_res_range_def.h"
#include "SmsSrvGprot.h"
#include "mmi_rp_srv_cbs_def.h"

#define SRV_CBS_INVALID_MSG_ID          0xFFFF

#define SRV_CBS_MAX_PAGE_PRE_MSG        15
#define SRV_CBS_PAGE_CONTENT_LEN        NVRAM_EF_SRV_CBS_PAGE_CONTENT_LEN
#define SRV_CBS_MAX_CONTENT_LEN         (SRV_CBS_PAGE_CONTENT_LEN * SRV_CBS_MAX_PAGE_PRE_MSG)

#define SRV_CBS_MAX_LANG_SUPPORT        180
#define SRV_CBS_MAX_LANG_NUM            SMSAL_MMI_DCS_MAX_ENTRY

/* Make sure the channel name entry is same as the max CBMI entry */
#if (NVRAM_EF_SRV_CBS_CHNL_NAME_NUM < SMSAL_MMI_CBMI_MAX_ENTRY)
#define SRV_CBS_MAX_CHNL_NUM            NVRAM_EF_SRV_CBS_CHNL_NAME_NUM
#else /* (NVRAM_EF_SRV_CBS_CHNL_NAME_NUM < SMSAL_MMI_CBMI_MAX_ENTRY) */
#define SRV_CBS_MAX_CHNL_NUM            SMSAL_MMI_CBMI_MAX_ENTRY
#endif /* (NVRAM_EF_SRV_CBS_CHNL_NAME_NUM < SMSAL_MMI_CBMI_MAX_ENTRY) */

#define SRV_CBS_CHNL_NAME_LEN           NVRAM_EF_SRV_CBS_CHNL_NAME_LEN

#define SRV_CBS_MAX_MSG_NUM             NVRAM_EF_SRV_CBS_MSG_NODE_NUM


/* CBS message Mode Enum */
typedef enum
{
    SRV_CBS_MODE_IMMEDICATE,
    SRV_CBS_MODE_NORMAL,
    SRV_CBS_MODE_TOTAL
} srv_cbs_mode_enum;

/* CBS Geographical Scope Enum */
typedef enum
{
   SRV_CBS_GS_CELL,
   SRV_CBS_GS_PLMN,
   SRV_CBS_GS_LA,
   SRV_CBS_GS_TOTAL
} srv_cbs_gs_enum;

/* CBS Language Enum */
typedef enum
{
    SRV_CBS_LANG_0_GERMAN      = 0,
    SRV_CBS_LANG_0_ENGLISH,
    SRV_CBS_LANG_0_ITALIAN,
    SRV_CBS_LANG_0_FRENCH,
    SRV_CBS_LANG_0_SPANISH,
    SRV_CBS_LANG_0_DUTCH,
    SRV_CBS_LANG_0_SWEDISH,
    SRV_CBS_LANG_0_DANISH,
    SRV_CBS_LANG_0_PORTUGUESE,
    SRV_CBS_LANG_0_FINNISH,
    SRV_CBS_LANG_0_NORWEGIAN,
    SRV_CBS_LANG_0_GREEK,
    SRV_CBS_LANG_0_TURKISH,
    SRV_CBS_LANG_0_HUNGARIAN,
    SRV_CBS_LANG_0_POLISH,
    SRV_CBS_LANG_0_UNSPECIFIED,

    SRV_CBS_LANG_1_CZECH       = 16,
    SRV_CBS_LANG_1_HEBREW,
    SRV_CBS_LANG_1_ARABIC,
    SRV_CBS_LANG_1_RUSSIAN,
    SRV_CBS_LANG_1_ICELANDIC,    /* 20 */

    SRV_CBS_LANG_2_AR = SRV_CBS_LANG_1_ARABIC,    /* ARABIC */

    SRV_CBS_LANG_2_CS = SRV_CBS_LANG_1_CZECH,    /* CZECH */

    SRV_CBS_LANG_2_DA = SRV_CBS_LANG_0_DANISH,    /* DANISH */
    SRV_CBS_LANG_2_DE = SRV_CBS_LANG_0_GERMAN,    /* GERMAN */

    SRV_CBS_LANG_2_EL = SRV_CBS_LANG_0_GREEK,    /* GREEK */
    SRV_CBS_LANG_2_EN = SRV_CBS_LANG_0_ENGLISH,    /* ENGLISH */
    SRV_CBS_LANG_2_ES = SRV_CBS_LANG_0_SPANISH,    /* SPANISH */

    SRV_CBS_LANG_2_FI = SRV_CBS_LANG_0_FINNISH,    /* FINNISH */
    SRV_CBS_LANG_2_FR = SRV_CBS_LANG_0_FRENCH,    /* FRENCH */

    SRV_CBS_LANG_2_HE = SRV_CBS_LANG_1_HEBREW,    /* HEBREW (FORMERLY IW) */
    SRV_CBS_LANG_2_HU = SRV_CBS_LANG_0_HUNGARIAN,    /* HUNGARIAN */

    SRV_CBS_LANG_2_IS = SRV_CBS_LANG_1_ICELANDIC,    /* ICELANDIC */
    SRV_CBS_LANG_2_IT = SRV_CBS_LANG_0_ITALIAN,    /* ITALIAN */

    SRV_CBS_LANG_2_NL = SRV_CBS_LANG_0_DUTCH,    /* DUTCH */
    SRV_CBS_LANG_2_NO = SRV_CBS_LANG_0_NORWEGIAN,    /* NORWEGIAN */

    SRV_CBS_LANG_2_PL = SRV_CBS_LANG_0_POLISH,    /* POLISH */
    SRV_CBS_LANG_2_PT = SRV_CBS_LANG_0_PORTUGUESE,    /* PORTUGUESE, 110 */

    SRV_CBS_LANG_2_RU = SRV_CBS_LANG_1_RUSSIAN,    /* RUSSIAN */

    SRV_CBS_LANG_2_SV = SRV_CBS_LANG_0_SWEDISH,    /* SWEDISH */

    SRV_CBS_LANG_2_TR = SRV_CBS_LANG_0_TURKISH,   /* TURKISH */

	SRV_CBS_LANG_2_OTHER,

    SRV_CBS_LANG_INVALID = 255
} srv_cbs_lang_enum;



/* Channel Entry Structure */
typedef struct
{
    MMI_BOOL mask;
    U16 id;
    WCHAR name[SRV_CBS_CHNL_NAME_LEN + 1];
} srv_cbs_chnl_entry_struct;

/* EVT_ID_SRV_CBS_READY_IND Event Data Structure */
typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_sms_sim_enum sim_id;
    MMI_BOOL is_ready;
} srv_cbs_ready_event_struct;

/* EVT_ID_SRV_CBS_NEW_MSG_IND Event Data Structure */
typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_sms_sim_enum sim_id;
    U16 msg_id;
    U16 channel_id;
    U16 channel_name[SRV_CBS_CHNL_NAME_LEN];
    srv_cbs_lang_enum lang_type;
    srv_sms_dcs_enum msg_dcs;
    srv_sms_class_enum msg_class;
    srv_cbs_mode_enum mode;
    U32 orig_msg_len;
    WCHAR *content;
    /* The buffer size of the msg content */
    U32 content_len;
} srv_cbs_new_msg_event_struct;

/* EVT_ID_SRV_CBS_GS_CHANGE_IND Event Data Structure */
typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_sms_sim_enum sim_id;
    srv_cbs_gs_enum change_type;
} srv_cbs_gs_change_event_struct;

/* EVT_ID_SRV_CBS_ADD_MSG Event Data Structure */
typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_sms_sim_enum sim_id;
    U16 msg_id;
} srv_cbs_add_msg_event_struct;

/* EVT_ID_SRV_CBS_DEL_MSG Event Data Structure */
typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_sms_sim_enum sim_id;
    U16 msg_id;
} srv_cbs_del_msg_event_struct;

/* EVT_ID_SRV_CBS_ADD_CHNL Event Data Structure */
typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_sms_sim_enum sim_id;
    U16 chnl_id;
} srv_cbs_add_chnl_event_struct;

/* EVT_ID_SRV_CBS_DEL_CHNL Event Data Structure */
typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_sms_sim_enum sim_id;
    U16 chnl_id;
} srv_cbs_del_chnl_event_struct;

/* EVT_ID_SRV_CBS_UPDATE_CHNL Event Data Structure */
typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_sms_sim_enum sim_id;
    srv_cbs_chnl_entry_struct new_chnl;
    srv_cbs_chnl_entry_struct old_chnl;
} srv_cbs_update_chnl_event_struct;

/* EVT_ID_SRV_CBS_MODE_CHANGE Event Data Structure */
typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_sms_sim_enum sim_id;
    MMI_BOOL mode;
} srv_cbs_mode_change_event_struct;

/* Channel Information Structure */
typedef struct
{
    U16 total;
    U16 max_entry;
    srv_cbs_chnl_entry_struct entry[SRV_CBS_MAX_CHNL_NUM];
} srv_cbs_channel_struct;

/* Language Entry Structure */
typedef struct
{
    srv_cbs_lang_enum lang_type;
    MMI_BOOL mask;
} srv_cbs_lang_entry_struct;

/* Language Information Structure */
typedef struct
{
    U16 total;
    MMI_BOOL is_all_on;
    srv_cbs_lang_entry_struct entry[SRV_CBS_MAX_LANG_NUM];
} srv_cbs_language_struct;

/* srv_cbs_subscribe Callback Data Structure */
typedef struct
{
    void *dummy;
} srv_cbs_subscribe_cb_struct;

/* srv_cbs_add_channel Callback Data Structure */
typedef struct
{
    void *dummy;
} srv_cbs_add_channel_cb_struct;

/* srv_cbs_delete_channel Callback Data Structure */
typedef struct
{
    void *dummy;
} srv_cbs_delete_channel_cb_struct;

/* srv_cbs_update_channel Callback Data Structure */
typedef struct
{
    void *dummy;
} srv_cbs_update_channel_cb_struct;

/* srv_cbs_select_language Callback Data Structure */
typedef struct
{
    srv_sms_sim_enum sim_id;
} srv_cbs_select_language_cb_struct;

/*****************************************************************************
 * FUNCTION
 *  srv_cbs_is_ready
 * DESCRIPTION
 *  Check CBS whether is ready
 * PARAMETERS
 *  sim_id          [IN]        SIM Card ID
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_cbs_is_ready(srv_sms_sim_enum sim_id);

/*****************************************************************************
 * FUNCTION
 *  srv_cbs_read_msg
 * DESCRIPTION
 *  Read a CBS message's content;
 *  If the returned value is MMI_FALSE, the content will be filled a end character.
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 *  sim_id          [IN]        SIM Card ID
 *  content_buff    [OUT]    Content Buffer for filling message content
 *  buff_len        [IN]        Content Buffer Length
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_cbs_read_msg(
                    U16 msg_id,
                    srv_sms_sim_enum sim_id,
                    WCHAR* content_buff,
                    U32 buff_len);
                    
/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_msg_time
 * DESCRIPTION
 *  Set whether subscribe CBS service. Set the receive mode.
 * PARAMETERS
 *  is_subsrcibe    [IN]        Subscribe or not
 *  sim_id          [IN]        SIM Card ID
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
extern U32 srv_cbs_get_msg_time(
                U16 msg_id,
                srv_sms_sim_enum sim_id);
/*****************************************************************************
 * FUNCTION
 *  srv_cbs_delete_msg
 * DESCRIPTION
 *  Delete a CBS message;
 *  If the message is invalid, the returned value is MMI_FALSE.
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 *  sim_id          [IN]        SIM Card ID
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_cbs_delete_msg(U16 msg_id, srv_sms_sim_enum sim_id);

/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_msg_num
 * DESCRIPTION
 *  Get CBS message total number
 * PARAMETERS
 *  sim_id          [IN]        SIM Card ID
 * RETURNS
 *  U16
 *****************************************************************************/
extern U16 srv_cbs_get_msg_num(srv_sms_sim_enum sim_id);

/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_msg_id
 * DESCRIPTION
 *  Get Message ID of a message by its position of CBS message List(List index)
 * PARAMETERS
 *  list_index      [IN]        The position of message in the Message List
 *  sim_id          [IN]        SIM Card ID
 * RETURNS
 *  U16
 *****************************************************************************/
extern U16 srv_cbs_get_msg_id(U16 list_index, srv_sms_sim_enum sim_id);

/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_msg_id
 * DESCRIPTION
 *  Get a message's position (list index) in CBS message list by message ID
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 *  sim_id          [IN]        SIM Card ID
 * RETURNS
 *  U16
 *****************************************************************************/
extern U16 srv_cbs_get_list_index(U16 msg_id, srv_sms_sim_enum sim_id);

/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_msg_chnl_id
 * DESCRIPTION
 *  Get a message's channel ID
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 *  sim_id          [IN]        SIM Card ID
 * RETURNS
 *  U16
 *****************************************************************************/
extern U16 srv_cbs_get_msg_chnl_id(U16 msg_id, srv_sms_sim_enum sim_id);

/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_msg_chnl_id
 * DESCRIPTION
 *  Get a Channel's name
 * PARAMETERS
 *  channel_name    [OUT]       Channel Name Buffer
 *  channel_id      [IN]        Channel ID
 *  sim_id          [IN]        SIM Card ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_cbs_get_channel_name(
                WCHAR channel_name[],
                U16 channel_id,
                srv_sms_sim_enum sim_id);

/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_receive_mode
 * DESCRIPTION
 *  Get CBS Receive mode
 * PARAMETERS
 *  sim_id          [IN]        SIM Card ID
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_cbs_get_receive_mode(srv_sms_sim_enum sim_id);

/*****************************************************************************
 * FUNCTION
 *  srv_cbs_subscribe
 * DESCRIPTION
 *  Set whether subscribe CBS service. Set the receive mode.
 * PARAMETERS
 *  is_subsrcibe    [IN]        Subscribe or not
 *  sim_id          [IN]        SIM Card ID
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_cbs_subscribe(
                MMI_BOOL is_subsrcibe,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void* user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_channel
 * DESCRIPTION
 *  Get All of Channel Information
 * PARAMETERS
 *  chnl_data       [IN]        Channel Data Buffer
 *  sim_id          [IN]        SIM Card ID
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_cbs_get_channel(
                    srv_cbs_channel_struct *chnl_data,
                    srv_sms_sim_enum sim_id);


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_channel
 * DESCRIPTION
 *  Get Information of a single Channel
 * PARAMETERS
 *  chnl_data       [IN]        Channel Data Buffer
 *  sim_id          [IN]        SIM Card ID
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_cbs_get_channel_single_entry(
            srv_cbs_chnl_entry_struct *chnl_data,
            U16 chnl_id,
            srv_sms_sim_enum sim_id);


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_add_channel
 * DESCRIPTION
 *  Add a channel
 * PARAMETERS
 *  chnl_entry      [IN]        Channel Entry
 *  sim_id          [IN]        SIM Card ID
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_cbs_add_channel(
                srv_cbs_chnl_entry_struct* chnl_entry,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void* user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_cbs_add_channel
 * DESCRIPTION
 *  Delete a channel
 * PARAMETERS
 *  channel_id      [IN]        Channel ID
 *  sim_id          [IN]        SIM Card ID
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_cbs_delete_channel(
                U16 channel_id,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void* user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_cbs_update_channel
 * DESCRIPTION
 *  Update a channel
 * PARAMETERS
 *  new_chnl        [IN]        New Channel Entry
 *  old_chnl        [IN]        Old Channel Entry
 *  sim_id          [IN]        SIM Card ID
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_cbs_update_channel(
                srv_cbs_chnl_entry_struct* new_chnl,
                srv_cbs_chnl_entry_struct* old_chnl,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void* user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_language
 * DESCRIPTION
 *  Get All of Language Information
 * PARAMETERS
 *  lang_data       [IN]        Language Data Buffer
 *  sim_id          [IN]        SIM Card ID
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_cbs_get_language(
                srv_cbs_language_struct *lang_data,
                srv_sms_sim_enum sim_id);

/*****************************************************************************
 * FUNCTION
 *  srv_cbs_select_language
 * DESCRIPTION
 *  Get All of Language Information
 * PARAMETERS
 *  lang_info       [IN]        Language Infomation
 *  sim_id          [IN]        SIM Card ID
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_cbs_select_language(
                srv_cbs_language_struct *lang_info,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void* user_data);
#endif /* __SRV_CBS_SRV_GPROT_H__ */
#endif /*__SRV_CBS_SUPPORT__*/

