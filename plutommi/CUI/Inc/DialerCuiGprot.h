/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  DialerCuiGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the SAP of the dialer CUI.
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
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef DIALER_CUI_GPROT_H
#define DIALER_CUI_GPROT_H

/****************************************************************************
 * Header
 ****************************************************************************/

#include "custom_phb_config.h"          /* MMI_PHB_NUMBER_PLUS_LENGTH */

/* auto add by kw_check begin */
#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
/* auto add by kw_check end */

/****************************************************************************
 * Define
 ****************************************************************************/

/* Max dialing string length in UCS2 encoding. Plus 1 for the '+' sign. */
#define CUI_DIALER_MAX_DIAL_STR_LEN     (MMI_PHB_NUMBER_LENGTH + 1)

/* Max dialing string buffer in UCS2 encoding.*/
#define CUI_DIALER_MAX_DIAL_BUF_SIZE    ((CUI_DIALER_MAX_DIAL_STR_LEN) + 1)


/****************************************************************************
 * Enum
 ****************************************************************************/

/* This defines the supported dialer. */
typedef enum
{
    /* Classic dialer */
    CUI_DIALER_TYPE_CLASSIC,

    /* VoIP dialer */
    CUI_DIALER_TYPE_VOIP,

    /* Dialer search */
    CUI_DIALER_TYPE_SEARCH,

    /* SOS only dialer */
    CUI_DIALER_TYPE_SOS,

    /* BWT dialer */
    CUI_DIALER_TYPE_BWT,

    /* Total number of supported dialer. */
    CUI_DIALER_TYPE_TOTAL,

    /* Unspecified dialer. */
    CUI_DIALER_TYPE_UNSPECIFIED,

    CUI_DIALER_TYPE_INVALID
} cui_dialer_type_enum;


typedef enum
{
    CUI_DIALER_LAUNCH_TYPE_NORMAL = 0,
    CUI_DIALER_LAUNCH_TYPE_EDIT_BEFORE_CALL,
    CUI_DIALER_LAUNCH_TYPE_END
} cui_dialer_launch_type_enum;


/****************************************************************************
 * Event Id
 ****************************************************************************/

/* This enum defines the events of the screen locker service. */
typedef enum
{
    /*
     * Begin of event enum.
     */
    EVT_ID_CUI_DIALER_BEGIN_OF_ENUM = CUI_DIALER_BASE,

    /*
     * This event is emitted when the dialer wants to be closed.
     *
     * Structure: cui_dialer_close_req_evt_struct
     */
    EVT_ID_CUI_DIALER_CLOSE_REQ,

    /*
     * This event is emitted when the dialer is closed.
     *
     * Structure: cui_dialer_closed_ind_evt_struct
     */
    EVT_ID_CUI_DIALER_CLOSED_IND,

    /*
     * This event is emitted when the dialer should change its type.
     *
     * Structure: cui_dialer_change_type_evt_struct
     */
    EVT_ID_CUI_DIALER_CHANGE_TYPE,

    /*
     * This event is emitted just before the dialer launches UCM. For example,
     * APP can get the dial string here to know which dial string is dialled.
     *
     * Structure: cui_dialer_before_call_launched_evt_struct
     */
    EVT_ID_CUI_DIALER_BEFORE_CALL_LAUNCHED,

    /*
     * End of event enum.
     */
    EVT_ID_CUI_DIALER_END_OF_ENUM
} cui_dialer_event_enum;


/****************************************************************************
 * Event Structure
 ****************************************************************************/

/* This is the structure for the EVT_ID_CUI_DIALER_CLOSE_REQ. */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER

    /* Type of the dialer. */
    cui_dialer_type_enum type;
} cui_dialer_close_req_evt_struct;

/* This is the structure for the EVT_ID_CUI_DIALER_CLOSED_IND. */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER

    /* Type of the dialer. */
    cui_dialer_type_enum type;
} cui_dialer_closed_ind_evt_struct;

/* This is the structure for the EVT_ID_CUI_DIALER_CHANGE_TYPE. */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER

    /* Old dialer type. */
    cui_dialer_type_enum old_type;

    /* New dialer type. */
    cui_dialer_type_enum new_type;
} cui_dialer_change_type_evt_struct;

/* This is the structure for the EVT_ID_CUI_DIALER_BEFORE_CALL_LAUNCHED. */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER

    /* Type of the dialer. */
    cui_dialer_type_enum type;
} cui_dialer_before_call_launched_evt_struct;


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_create
 * DESCRIPTION
 *  This function creates a dialer CUI.
 * PARAMETERS
 *  parent_gid          : [IN]      Parent group ID
 * RETURNS
 *  Dialer CUI group ID.
 *****************************************************************************/
extern mmi_id cui_dialer_create(mmi_id parent_gid);


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_create_ex
 * DESCRIPTION
 *  This function creates a dialer CUI of the specified type.
 * PARAMETERS
 *  parent_gid          : [IN]      Parent group ID
 *  type                : [IN]      Type of dialer CUI
 * RETURNS
 *  Dialer CUI group ID.
 *****************************************************************************/
extern mmi_id cui_dialer_create_ex(
    mmi_id parent_gid,
    cui_dialer_type_enum type);


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_run
 * DESCRIPTION
 *  This function runs the dialer CUI.
 * PARAMETERS
 *  this_gid            : [IN]      Dialer CUI group ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_dialer_run(mmi_id this_gid);


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_close
 * DESCRIPTION
 *  This function closes the dialer CUI.
 * PARAMETERS
 *  this_gid            : [IN]      Dialer CUI group ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_dialer_close(mmi_id this_gid);


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_set_dial_string
 * DESCRIPTION
 *  This function sets the dialing string. The dialer will be launched with this
 *  default dialing string.
 * PARAMETERS
 *  this_gid            : [IN]      Dialer CUI group ID
 *  string              : [IN]      Dialing string.
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_dialer_set_dial_string(mmi_id this_gid, const WCHAR *string);


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_set_key
 * DESCRIPTION
 *  This function sets the key code which triggers the dialer. The dialer will
 *  be launched with this default digit.
 * PARAMETERS
 *  this_gid           : [IN]       Dialer CUI group ID
 *  key_code           : [IN]       Key code
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_dialer_set_key(mmi_id this_gid, U16 key_code);


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_set_translate_key
 * DESCRIPTION
 *  This function sets the tranlate key which triggers the dialer. The dialer
 *  will be launched with this default translate key.
 * PARAMETERS
 *  this_gid            : [IN]      Dialer CUI group ID
 *  key_code            : [IN]      Key code
 *  key_flag            : [IN]      Key flag
 *  key_type            : [IN]      Key type
 *  ucs2_value          : [IN]      UCS2 value
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_dialer_set_translate_key(
    mmi_id this_gid,
    S16 mmi_key_code,
    S16 mmi_key_type,
    U16 ucs2_value,
    U32 special_key_flag);


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_get_dial_string
 * DESCRIPTION
 *  This function gets the dialing string of the dialer.
 * PARAMETERS
 *  this_gid           : [IN]           Dialer CUI group ID
 * RETURNS
 *  Dialing string.
 *****************************************************************************/
extern const WCHAR *cui_dialer_get_dial_string(mmi_id this_gid);


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_set_phb_data
 * DESCRIPTION
 *  This function sets the phone book data which will be passed to UCM when the
 *  user dials call. Please refer to mmi_ucm_advanced_make_call_para_struct for
 *  the details.
 * PARAMETERS
 *  this_gid            : [IN]          Dialer CUI group ID
 *  phb_data            : [IN]          Phone book data
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_dialer_set_phb_data(mmi_id this_gid, void *phb_data);


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_get_phb_data
 * DESCRIPTION
 *  This function gets the phone book data.
 * PARAMETERS
 *  this_gid            : [IN]          Dialer CUI group ID
 * RETURNS
 *  Phone book data.
 *****************************************************************************/
extern void *cui_dialer_get_phb_data(mmi_id this_gid);


/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_is_active_if_any
 * DESCRIPTION
 *  This function checks if there is any active dialer.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL cui_dialer_is_active_if_any(void);


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_get_dial_string_if_any
 * DESCRIPTION
 *  This function gets the dialing string if there is any dialer.
 * PARAMETERS
 *  void
 * RETURNS
 *  Dialing string.
 *****************************************************************************/
extern const WCHAR *cui_dialer_get_dial_string_if_any(void);


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_close_if_present
 * DESCRIPTION
 *  This function will close all the dialer cui in history.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_dialer_close_if_present(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_handle_dialer_change_type
 * DESCRIPTION
 *  This function handle cui dialer change type event.
 * PARAMETERS
 *  event            : [IN]          mmi_event_struct
 *  parent_id       : [IN]         MMI_ID
 * RETURNS
 *  MMI_ID
 *****************************************************************************/
extern MMI_ID cui_dialer_handle_dialer_change_type(mmi_event_struct *event, MMI_ID parent_id);

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_get_type_if_any
 * DESCRIPTION
 *  Get active dialer type.
 * PARAMETERS
 *  void
 * RETURNS
 *  cui_dialer_type_enum
 *****************************************************************************/
cui_dialer_type_enum cui_dialer_get_type_if_any(void);


#if  defined(__MMI_DIALER_DYNAMIC_CALL_UI__) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_get_avaliable_sim_number
 * DESCRIPTION
 *  This function is to get the avaliable sim number.
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 cui_dialer_get_available_sim_number(void);


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_is_emergency_call_only
 * DESCRIPTION
 *  This function is to check if only ecc number can dial.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL cui_dialer_is_emergency_call_only(void);



/*****************************************************************************
 * FUNCTION
 *  cui_dialer_sim_select_hdlr
 * DESCRIPTION
 *  This function will show sim select menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_dialer_sim_select_hdlr(void);
#endif 


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_set_launch_style
 * DESCRIPTION
 *  This function tell dialer it launch by calllog
 * PARAMETERS
 *  this_gid     [IN]    this dialer cui group id
 *  value        [IN]    true for launch by calllog
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_dialer_set_launch_style(mmi_id this_gid, cui_dialer_launch_type_enum value);


#if defined(__MMI_DIALER_SEARCH__)

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_search_set_enable
 * DESCRIPTION
 *  This function sets the dialer search state.
 * PARAMETERS
 *  enable           : [IN]      Enable or not
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_dialer_search_set_enable(MMI_BOOL enable);


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_search_is_enable
 * DESCRIPTION
 *  This function checks if dialer search is enable.
 * PARAMETERS
 *  void
 * RETURNS
 *  On enable, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL cui_dialer_search_is_enable(void);


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_search_entry_setting
 * DESCRIPTION
 *  This function entries the dialer search setting screen.
 * PARAMETERS
 *  group_id     [IN]    parent group id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_dialer_search_entry_setting(MMI_ID group_id);


#ifdef __MMI_ICON_BAR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  cui_dialer_toolbar_update
 * DESCRIPTION
 *  fte contact main list toolbar update callback
 * PARAMETERS
 *  MMI_BOOL        [IN]      is the edit box acitve
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_dialer_toolbar_update(MMI_BOOL set);
#endif
/* DOM-NOT_FOR_SDK-END */

#endif /* defined(__MMI_DIALER_SEARCH__) */

#ifdef __OP01_FWPBW__

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_bwt_close
 * DESCRIPTION
 *  This function is to close bwt dialer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_dialer_bwt_close(void);
#endif


#ifdef __GENERAL_TTS__

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_is_tts_enable
 * DESCRIPTION
 *  This function return if dialer tts is enabled.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL enable, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL cui_dialer_is_tts_enable(void);


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_entry_tts_setting
 * DESCRIPTION
 *  This function entries the dialer tts setting screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_dialer_entry_tts_setting(void);

#endif /*ifdef __GENERAL_TTS__*/


#endif /* DIALER_CUI_GPROT_H */

