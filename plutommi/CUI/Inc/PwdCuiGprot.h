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
 *  PwdCuiGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  CUI of password screens.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __PWD_CUI_GPROT_H__
#define __PWD_CUI_GPROT_H__


/****************************************************************************
 * Include
 ****************************************************************************/
 
#include "MMIDataType.h"
#include "GlobalConstants.h"
#include "kal_general_types.h"
#include "mmi_res_range_def.h"


/****************************************************************************
 * Constants
 ****************************************************************************/

/*
 * DESCRIPTION
 *  Maximum length of extra message of CUI
 */
#define CUI_PWD_MAX_EXTRA_MSG_STR_LEN (40)

/*
 * DESCRIPTION
 *  Return value for PASSIVE_CLOSING events. This value will forbid the CUI
 *  from being closed.
 */
#define CUI_PWD_DONT_CLOSE  (-1)

/*
 * DESCRIPTION
 *  Auxiliary function of CUI. Client can set auxiliary for some operation.
 *  Take cui_pwd_basic for example, if its cancel is disabled, the RSK
 *  will become the auxiliary key. When user presses the auxiliary key,
 *  the registered function will be invoked.
 */
typedef enum
{
    CUI_PWD_AUXILIARY_BASIC_DEFAULT, /* Default auxiliary for cui_pwd_basic */
    CUI_PWD_AUXILIARY_CHECK_DEFAULT, /* Default auxiliary for cui_pwd_check */
    CUI_PWD_AUXILIARY_GUARD_DEFAULT, /* Default auxiliary for cui_pwd_guard */

    CUI_PWD_AUXILIARY_END_OF_ENUM
} cui_pwd_auxiliary_type_enum;


/****************************************************************************
 * [Single screen password CUI]
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_basic_create
 * DESCRIPTION
 *  Create a basic password CUI.
 *  This CUI only shows a input box for user to input password.
 * PARAMETERS
 *  parent_grp_id       : [IN] Parent group ID
 *  prompt_str_id       : [IN] Prompt for the input
 *  min_pwd_len         : [IN] Minimum password length. DONE event will be
 *                             emitted only if the input exceeds this length.
 *  max_pwd_len         : [IN] Maximum password length.
 * RETURNS
 *  Instance ID.
 *****************************************************************************/
extern mmi_id cui_pwd_basic_create(
                mmi_id parent_grp_id,
                MMI_STR_ID prompt_str_id,
                S32 min_pwd_len,
                S32 max_pwd_len);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_basic_create_dynamic_str
 * DESCRIPTION
 *  Create a basic password CUI.
 *  This CUI only shows a input box for user to input password.
 * PARAMETERS
 *  parent_grp_id       : [IN] Parent group ID
 *  prompt_str          : [IN] Prompt for the input. Password CUI will hold a
 *                             copy of the string content.
 *  min_pwd_len         : [IN] Minimum password length. DONE event will be
 *                             emitted only if the input exceeds this length.
 *  max_pwd_len         : [IN] Maximum password length.
 * RETURNS
 *  Instance ID.
 *****************************************************************************/
extern mmi_id cui_pwd_basic_create_dynamic_str(
                mmi_id parent_grp_id,
                const WCHAR* prompt_str,
                S32 min_pwd_len,
                S32 max_pwd_len);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_basic_set_action_str
 * DESCRIPTION
 *  Set the strings for actions: done & cancel.
 *  Usually, done and cancel will be the LSK & RSK respectively.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 *  done_str_id     : [IN] Done string; 0 means don't change
 *  cancel_str_id   : [IN] Cancel string; 0 means don't change
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_basic_set_action_str(mmi_id instance_id, MMI_STR_ID done_str_id, MMI_STR_ID cancel_str_id);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_basic_set_proc
 * DESCRIPTION
 *  Set the proc for all events from the CUI.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 *  proc            : [IN] Proc
 *  user_data       : [IN] The user_data field for all events
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_basic_set_proc(mmi_id instance_id, mmi_proc_func proc, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_basic_set_small_screen_enabled
 * DESCRIPTION
 *  cui_pwd_basic is full screen by default. This API can enable the password
 *  screen as a small screen, similar to a popup.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 *  enabled         : [IN] MMI_TRUE to enable small-screen style.
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_basic_set_small_screen_enabled(mmi_id instance_id, MMI_BOOL enabled);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_basic_set_input_prompt
 * DESCRIPTION
 *  Set input prompt
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 *  prompt_str      : [IN] Input prompt string. The CUI will hold a copy.
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_basic_set_input_prompt(mmi_id instance_id, const WCHAR *prompt_str);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_basic_set_extra_msg
 * DESCRIPTION
 *  Set the extra message to user. This message can be used to prompt the number
 *  of trials remaining.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 *  extra_msg       : [IN] The extra message
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_basic_set_extra_msg(mmi_id instance_id, const WCHAR *extra_msg);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_basic_set_cancel_enabled
 * DESCRIPTION
 *  Enable cancel or not.
 *  If cancel is enabled, the screen will show cancel option for user.
 *  Note that even cancel is disabled, user may close the CUI by End key or
 *  other method(such as some operation may go back to idle). Client can
 *  return CUI_PWD_DONE_CLOSE to forbid the closing.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 *  enabled         : [IN] Enable cancel option or not
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_basic_set_cancel_enabled(mmi_id instance_id, MMI_BOOL enabled);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_basic_set_auxiliary
 * DESCRIPTION
 *  Set the auxiliary of basic CUI. Auxiliaries are client-defined option
 *  of the CUI. User can select the auxiliary on the password CUI, then
 *  CUI may send EVT_ID_CUI_PWD_BASIC_AUXILIARY to the client. The client
 *  can run pre-defined process for the auxiliary function.
 *
 *  If cancel is disabled, usually auxiliary will be set to the RSK of the screen.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 *  type            : [IN] Auxiliary type
 *  enabled         : [IN] Enable auxiliary
 *  str_id          : [IN] Auxiliary string
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_basic_set_auxiliary(
                mmi_id instance_id,
                cui_pwd_auxiliary_type_enum type,
                MMI_BOOL enabled,
                MMI_STR_ID str_id);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_basic_run
 * DESCRIPTION
 *  Display the CUI(password input screen).
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_basic_run(mmi_id instance_id);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_basic_set_input
 * DESCRIPTION
 *  Set the content of the input box.
 *  Note: the screen does not support update right away if active
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 *  str             : [IN] String to be filled in the input box
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_basic_set_input(mmi_id instance_id, const WCHAR *str);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_basic_clear_input
 * DESCRIPTION
 *  Clear the input box.
 *  Note: the screen does not support update right away if active
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_basic_clear_input(mmi_id instance_id);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_basic_get_input
 * DESCRIPTION
 *  Get the content of the input box.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 * RETURNS
 *  void
 *****************************************************************************/
extern const WCHAR* cui_pwd_basic_get_input(mmi_id instance_id);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_basic_reset
 * DESCRIPTION
 *  Reset CUI state as newly created.
 *  Note: the screen does not support update right away if active
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_basic_reset(mmi_id instance_id);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_basic_close
 * DESCRIPTION
 *  Close the password CUI and release the instance.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_basic_close(mmi_id instance_id);


/****************************************************************************
 * [Checked password CUI]
 *
 * Input password -> confirm password
 * IF the second-time input is different from the first one, an error message
 * will be prompted and go back to the first input.
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_check_create
 * DESCRIPTION
 *  Create a check password CUI.
 *  This CUI will show 2 input screens. One for first input, and the second
 *  to confirm the input. If the inputs do not match, an message will be
 *  prompted.
 * PARAMETERS
 *  parent_grp_id       : [IN] Parent group ID
 *  input_prompt_str_id : [IN] Prompt for the first-time input
 *  confirm_prompt_str_id   : [IN] Prompt for the confirmation input
 *  min_pwd_len         : [IN] Minimum password length. The input is acceptable
 *                             only if exceed minimum length.
 *  max_pwd_len         : [IN] Maximum password length.
 * RETURNS
 *  Instance ID.
 *****************************************************************************/
extern mmi_id cui_pwd_check_create(
                mmi_id parent_grp_id,
                MMI_STR_ID input_prompt_str_id,
                MMI_STR_ID confirm_prompt_str_id,
                S32 min_pwd_len,
                S32 max_pwd_len);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_check_set_action_str
 * DESCRIPTION
 *  Set the strings for actions: done & cancel.
 *  Usually, done is the LSK(or other positive function) of the last screen,
 *  cancel is the RSK(or other negative function) of the second screen.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 *  done_str_id     : [IN] Done string; 0 means don't change
 *  cancel_str_id   : [IN] Cancel string; 0 means don't change
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_check_set_action_str(mmi_id instance_id, MMI_STR_ID done_str_id, MMI_STR_ID cancel_str_id);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_check_set_diff_input_prompt
 * DESCRIPTION
 *  Set the string to prompt the second-time(confirmation) input is different from
 *  the first-time.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 *  prompt_str_id   : [IN] Prompt
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_check_set_diff_input_prompt(mmi_id instance_id, MMI_STR_ID prompt_str_id);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_check_set_proc
 * DESCRIPTION
 *  Set the proc for all events from the CUI.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 *  proc            : [IN] Proc
 *  user_data       : [IN] The user_data field for all events
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_check_set_proc(mmi_id instance_id, mmi_proc_func proc, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_check_run
 * DESCRIPTION
 *  Display the CUI.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_check_run(mmi_id instance_id);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_check_get_input_of_active
 * DESCRIPTION
 *  Get the content of the active input box.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 * RETURNS
 *  void
 *****************************************************************************/
extern const WCHAR* cui_pwd_check_get_input_of_active(mmi_id instance_id);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_check_clear_input_of_active
 * DESCRIPTION
 *  Clear the content of the active input box.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_check_clear_input_of_active(mmi_id instance_id);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_check_reset
 * DESCRIPTION
 *  Reset the CUI.
 *  The CUI state will be restored as newly created.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_check_reset(mmi_id instance_id);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_check_close
 * DESCRIPTION
 *  Close the CUI.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_check_close(mmi_id instance_id);


/****************************************************************************
 * [Guard password CUI]
 *
 * Input guard password -> input target password -> confirm target password
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_check_create
 * DESCRIPTION
 *  Create a check password CUI.
 *  This CUI will show 3 input boxes. The first for the guard password,
 *  the second & the third for the input and confirmation of new password,
 *  respectively.
 * PARAMETERS
 *  parent_grp_id       : [IN] Parent group ID
 *  guard_prompt_str_id : [IN] Prompt for the guard password
 *  input_prompt_str_id : [IN] Prompt for the new password
 *  confirm_prompt_str_id : [IN] Prompt for the confirmation of new password
 *  guard_min_pwd_len   : [IN] Minimum length of guard password
 *  guard_max_pwd_len   : [IN] Maximum length of guard password
 *  input_min_pwd_len   : [IN] Minimum length of new password
 *  input_max_pwd_len   : [IN] Maximum length of new password
 * RETURNS
 *  Instance ID.
 *****************************************************************************/
extern mmi_id cui_pwd_guard_create(
                    mmi_id parent_grp_id,
                    MMI_STR_ID guard_prompt_str_id,
                    MMI_STR_ID input_prompt_str_id,
                    MMI_STR_ID confirm_prompt_str_id,
                    S32 guard_min_pwd_len,
                    S32 guard_max_pwd_len,
                    S32 input_min_pwd_len,
                    S32 input_max_pwd_len);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_guard_create_dynamic_str
 * DESCRIPTION
 *  Create a check password CUI.
 *  This CUI will show 3 input boxes. The first for the guard password,
 *  the second & the third for the input and confirmation of new password,
 *  respectively.
 * PARAMETERS
 *  parent_grp_id       : [IN] Parent group ID
 *  guard_prompt_str    : [IN] Prompt for the guard password. Guard password
 *                             CUI will hold a copy of this string.
 *  input_prompt_str    : [IN] Prompt for the new password. Guard password
 *                             CUI will hold a copy of this string.
 *  confirm_prompt_str  : [IN] Prompt for the confirmation of new password.
 *                             Guard password CUI will hold a copy of this string.
 *  guard_min_pwd_len   : [IN] Minimum length of guard password
 *  guard_max_pwd_len   : [IN] Maximum length of guard password
 *  input_min_pwd_len   : [IN] Minimum length of new password
 *  input_max_pwd_len   : [IN] Maximum length of new password
 * RETURNS
 *  Instance ID.
 *****************************************************************************/
mmi_id cui_pwd_guard_create_dynamic_str(
        mmi_id parent_grp_id,
        const WCHAR* guard_prompt_str,
        const WCHAR* input_prompt_str,
        const WCHAR* confirm_prompt_str,
        S32 guard_min_pwd_len,
        S32 guard_max_pwd_len,
        S32 input_min_pwd_len,
        S32 input_max_pwd_len);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_guard_set_action_str
 * DESCRIPTION
 *  Set the strings for actions: done & cancel.
 *  Usually, done is the LSK(or other positive function) of the last screen,
 *  cancel is the RSK(or other negative function) of the second screen.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 *  done_str_id     : [IN] Done string; 0 means don't change
 *  cancel_str_id   : [IN] Cancel string; 0 means don't change
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_guard_set_action_str(mmi_id instance_id, MMI_STR_ID done_str_id, MMI_STR_ID cancel_str_id);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_guard_set_cancel_enabled
 * DESCRIPTION
 *  Enable cancel or not.
 *  If cancel is enabled, the screen will show cancel option for user.
 *  Note that even cancel is disabled, user may close the CUI by End key or
 *  other method(such as some operation may go back to idle). Client can
 *  return CUI_PWD_DONE_CLOSE to forbid the closing.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 *  enabled         : [IN] Enable cancel option or not
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_guard_set_cancel_enabled(mmi_id instance_id, MMI_BOOL enabled);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_guard_set_proc
 * DESCRIPTION
 *  Set the proc for all events from the CUI.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 *  proc            : [IN] Proc
 *  user_data       : [IN] The user_data field for all events
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_guard_set_proc(mmi_id instance_id, mmi_proc_func proc, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_guard_set_prompt_strings
 * DESCRIPTION
 *  Set the prompt strings of the CUI.
 * PARAMETERS
 *  instance_id         : [IN] Instance ID
 *  guard_prompt_str    : [IN] Prompt for the guard password. Guard password
 *                             CUI will hold a copy of this string.
 *  input_prompt_str    : [IN] Prompt for the new password. Guard password
 *                             CUI will hold a copy of this string.
 *  confirm_prompt_str  : [IN] Prompt for the confirmation of new password.
 *                             Guard password CUI will hold a copy of this string.
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_guard_set_prompt_strings(
    mmi_id instance_id,
    const WCHAR* guard_prompt_str,
    const WCHAR* input_prompt_str,
    const WCHAR* confirm_prompt_str);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_guard_set_diff_input_prompt
 * DESCRIPTION
 *  Set the string to prompt the second-time(confirmation) input is different from
 *  the first-time, of new password.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 *  prompt_str_id   : [IN] Prompt
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_guard_set_diff_input_prompt(mmi_id instance_id, MMI_STR_ID prompt_str_id);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_guard_set_guard_extra_msg
 * DESCRIPTION
 *  Set the extra message of the guard password to user. This message can be
 *  used to prompt the number of trials remaining.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 *  extra_msg       : [IN] The extra message
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_guard_set_guard_extra_msg(mmi_id instance_id, const WCHAR *extra_msg);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_guard_set_auxiliary
 * DESCRIPTION
 *  Set the auxiliary of guard CUI. Auxiliaries are client-defined option
 *  of the CUI. User can select the auxiliary on the password CUI, then
 *  CUI may send EVT_ID_CUI_PWD_GUARD_AUXILIARY to the client. The client
 *  can run pre-defined process for the auxiliary function.
 *
 *  If cancel is disabled, auxiliary will be set to the RSK of the guard screen.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 *  type            : [IN] Auxiliary type
 *  enabled         : [IN] Enable auxiliary
 *  str_id          : [IN] Auxiliary string
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_guard_set_auxiliary(
                mmi_id instance_id,
                cui_pwd_auxiliary_type_enum type,
                MMI_BOOL enabled,
                MMI_STR_ID str_id);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_guard_run
 * DESCRIPTION
 *  Display the CUI.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_guard_run(mmi_id instance_id);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_guard_get_input_of_active
 * DESCRIPTION
 *  Get the content of the active input box.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 * RETURNS
 *  void
 *****************************************************************************/
extern const WCHAR* cui_pwd_guard_get_input_of_active(mmi_id instance_id);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_guard_clear_input_of_active
 * DESCRIPTION
 *  Clear the content of the active input box.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_guard_clear_input_of_active(mmi_id instance_id);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_guard_reset
 * DESCRIPTION
 *  Reset the CUI.
 *  The CUI state will be restored as newly created.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_guard_reset(mmi_id instance_id);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_guard_is_on_guard_input_box
 * DESCRIPTION
 *  Query whether the input box of guard password is focused on the instance.
 *  That is, the active screen of the CUI is the guard password.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL cui_pwd_guard_is_on_guard_input_box(mmi_id instance_id);

/*****************************************************************************
 * FUNCTION
 *  cui_pwd_guard_close
 * DESCRIPTION
 *  Close the instance.
 * PARAMETERS
 *  instance_id     : [IN] Instance ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_pwd_guard_close(mmi_id instance_id);


/****************************************************************************
 * Events
 ****************************************************************************/

typedef enum
{
    /*
     * [cui_pwd_basic]
     * Input completed.
     *
     * Structure:
     *  cui_pwd_basic_done_evt_struct
     */
    EVT_ID_CUI_PWD_BASIC_DONE = CUI_PASSWORD_BASE,
    
    /*
     * [cui_pwd_basic]
     * User selected cancel.
     *
     * Structure:
     *  cui_pwd_basic_cancel_evt_struct
     * See also:
     *  cui_pwd_basic_set_cancel_enabled
     */
    EVT_ID_CUI_PWD_BASIC_CANCEL,

    /*
     * [cui_pwd_basic]
     * CUI is going to close passively. It may be caused by user presses End
     * key or some application close the CUI by framework's group operations.
     * Client can return CUI_PWD_DONT_CLOSE to stop the closing.
     * This event will not be emitted if close by cui_pwd_basic_close().
     *
     * Structure:
     *  cui_pwd_basic_passive_closing_evt_struct
     */
    EVT_ID_CUI_PWD_BASIC_PASSIVE_CLOSING,

    /*
     * [cui_pwd_basic]
     * Key pressed on the CUI. cui_pwd_basic will convert ON_KEY event
     * to this event, then pass to client.
     *
     * Structure:
     *  cui_pwd_basic_key_evt_struct
     */
    EVT_ID_CUI_PWD_BASIC_KEY,

    /*
     * [cui_pwd_basic]
     * Auxiliary option is selected.
     *
     * Structure:
     *  cui_pwd_basic_aux_evt_struct
     * See also:
     *  cui_pwd_basic_set_auxiliary
     */
    EVT_ID_CUI_PWD_BASIC_AUX,

    /*
     * [cui_pwd_check]
     * Input completed.
     *
     * Structure:
     *  cui_pwd_check_done_evt_struct
     */
    EVT_ID_CUI_PWD_CHECK_DONE,

    /*
     * [cui_pwd_check]
     * User selected cancel.
     *
     * Structure:
     *  cui_pwd_check_cancel_evt_struct
     * See also:
     *  cui_pwd_check_set_cancel_enabled
     */
    EVT_ID_CUI_PWD_CHECK_CANCEL,

    /*
     * [cui_pwd_check]
     * CUI is going to close passively. It may cause by user presses end
     * key or some application close the CUI by framework's group operations.
     * Client can return CUI_PWD_DONT_CLOSE to stop the closing.
     * This event will not be emitted if close by cui_pwd_check_close().
     *
     * Structure:
     *  cui_pwd_check_passive_closing_evt_struct
     */
    EVT_ID_CUI_PWD_CHECK_PASSIVE_CLOSING,

    /*
     * [cui_pwd_check]
     * Key pressed on the CUI. cui_pwd_check will convert ON_KEY event
     * on ALL screens to this event, then pass to client.
     *
     * Structure:
     *  cui_pwd_check_key_evt_struct
     */
    EVT_ID_CUI_PWD_CHECK_KEY,

    /*
     * [cui_pwd_check]
     * Auxiliary option is selected.
     *
     * Structure:
     *  cui_pwd_check_aux_evt_struct
     * See also:
     *  cui_pwd_check_set_auxiliary
     */
    EVT_ID_CUI_PWD_CHECK_AUX,

    /*
     * [cui_pwd_guard]
     * Input completed.
     *
     * Structure:
     *  cui_pwd_guard_done_evt_struct
     */
    EVT_ID_CUI_PWD_GUARD_DONE,

    /*
     * [cui_pwd_guard]
     * User selected cancel.
     *
     * Structure:
     *  cui_pwd_guard_cancel_evt_struct
     * See also:
     *  cui_pwd_guard_set_cancel_enabled
     */
    EVT_ID_CUI_PWD_GUARD_CANCEL,

    /*
     * [cui_pwd_guard]
     * CUI is going to close passively. It may cause by user presses end
     * key or some application close the CUI by framework's group operations.
     * Client can return CUI_PWD_DONT_CLOSE to stop the closing.
     * This event will not be emitted if close by cui_pwd_guard_close().
     *
     * Structure:
     *  cui_pwd_guard_passive_closing_evt_struct
     */
    EVT_ID_CUI_PWD_GUARD_PASSIVE_CLOSING,

    /*
     * [cui_pwd_guard]
     * Key pressed on the CUI. cui_pwd_guard will convert ON_KEY event
     * on ALL screens to this event, then pass to client.
     *
     * Structure:
     *  cui_pwd_guard_key_evt_struct
     * See also
     *  cui_pwd_guard_is_on_guard_input_box
     */
    EVT_ID_CUI_PWD_GUARD_KEY,

    /*
     * [cui_pwd_guard]
     * Auxiliary option is selected.
     *
     * Structure:
     *  cui_pwd_guard_aux_evt_struct
     * See also:
     *  cui_pwd_guard_set_auxiliary
     */
    EVT_ID_CUI_PWD_GUARD_AUX,

    EVT_ID_CUI_PWD_END_OF_ENUM
} cui_pwd_event_enum;


/*
 * Structure of EVT_ID_CUI_PWD_BASIC_DONE
 */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER

    const WCHAR *input; /* Input of password */
} cui_pwd_basic_done_evt_struct;


/*
 * Structure of EVT_ID_CUI_PWD_BASIC_CANCEL
 */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
} cui_pwd_basic_cancel_evt_struct;


/*
 * Structure of EVT_ID_CUI_PWD_BASIC_PASSIVE_CLOSING
 */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
} cui_pwd_basic_passive_closing_evt_struct;


/*
 * Structure of EVT_ID_CUI_PWD_BASIC_KEY
 */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER

    /*
     * Key event ID from framework.
     * We only support EVT_ID_ON_KEY event now. However, client should
     * still check this field to filter out useless events for future extension.
     */
    U16 key_evt_id;
    
    /* Which key */
    mmi_keypads_enum key_code;

    /* Event type: KEY_EVENT_UP/KEY_EVENT_DOWN/... etc */
    mmi_key_types_enum key_type;
} cui_pwd_basic_key_evt_struct,
  cui_pwd_check_key_evt_struct,
  cui_pwd_guard_key_evt_struct,
  cui_pwd_general_key_evt_struct;


/*
 * Structure of EVT_ID_CUI_PWD_BASIC_AUX
 */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER

    cui_pwd_auxiliary_type_enum type; /* Auxiliary type */
} cui_pwd_basic_aux_evt_struct;


/*
 * Structure of EVT_ID_CUI_PWD_CHECK_DONE
 */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER

    const WCHAR *input; /* Input */
} cui_pwd_check_done_evt_struct;


/*
 * Structure of EVT_ID_CUI_PWD_CHECK_CANCEL
 */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
} cui_pwd_check_cancel_evt_struct;


/*
 * Structure of EVT_ID_CUI_PWD_CHECK_PASSIVE_CLOSING
 */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
} cui_pwd_check_passive_closing_evt_struct;


/*
 * Structure of EVT_ID_CUI_PWD_CHECK_AUX
 */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER

    cui_pwd_auxiliary_type_enum type; /* Auxiliary type */
} cui_pwd_check_aux_evt_struct;


/*
 * Structure of EVT_ID_CUI_PWD_GUARD_DONE
 */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER

    const WCHAR *guard; /* Guard password */
    const WCHAR *input; /* Input password(new password) */
} cui_pwd_guard_done_evt_struct;


/*
 * Structure of EVT_ID_CUI_PWD_GUARD_CANCEL
 */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
} cui_pwd_guard_cancel_evt_struct;


/*
 * Structure of EVT_ID_CUI_PWD_GUARD_PASSIVE_CLOSING
 */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
} cui_pwd_guard_passive_closing_evt_struct;


/*
 * Structure of EVT_ID_CUI_PWD_GUARD_AUX
 */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER

    cui_pwd_auxiliary_type_enum type; /* Auxiliary type */
} cui_pwd_guard_aux_evt_struct;


#endif /* __PWD_CUI_GPROT_H__ */

