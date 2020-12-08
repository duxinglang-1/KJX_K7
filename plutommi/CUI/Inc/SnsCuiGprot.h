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
 * SnsCuiGprot.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *  This file implements application functions for SNS feature.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SNS_CUI_GPROT_H__
#define __SNS_CUI_GPROT_H__

#include "MMI_features.h"
#ifdef __SOCIAL_NETWORK_SUPPORT__

#include "MMIDataType.h"

#include "SnsSrvDefs.h"
#include "SnsSrvTypes.h"


/**************************************************************
 * MARCO                                                      * 
 **************************************************************/


/**************************************************************
 * Structure Declaration                                      *
 **************************************************************/
/* Event ids */
typedef enum
{
    EVT_ID_CUI_SNS_BEGIN = APP_SNS,
    EVT_ID_CUI_SNS_FILTER,
    EVT_ID_CUI_SNS_SENDER,
    EVT_ID_CUI_SNS_FRIEND_LINK,
    EVT_ID_CUI_SNS_EDITOR_DONE,
    EVT_ID_CUI_SNS_SETTING_CLOSE_REQ,
    EVT_ID_CUI_SNS_SYNC_CLOSE_REQ,

    EVT_ID_CUI_SNS_TOTAL
} cui_sns_event_enum;


/* result */
typedef enum
{
    CUI_SNS_RESULT_OK,
    CUI_SNS_RESULT_ABORT,
    CUI_SNS_RESULT_ERROR,

    CUI_SNS_RESULT_TOTAL
} cui_sns_result_enum;


/* Filter CUI type */
typedef enum
{
    CUI_SNS_FILTER_NEWSFEED_LIST,
    CUI_SNS_FILTER_FRIEND_LIST,

    CUI_SNS_FILTER_TOTAL
} cui_sns_filter_enum;


/* Sender CUI types */
typedef enum
{
    CUI_SNS_SENDER_NEWSFEED,
    CUI_SNS_SENDER_MSG,

    CUI_SNS_SENDER_TOTAL
} cui_sns_sender_enum;


/* Editor CUI types */
typedef enum
{
    CUI_SNS_EDITOR_NONE,
    CUI_SNS_EDITOR_ACT_NEW,
    CUI_SNS_EDITOR_ACT_COMMENT,
    CUI_SNS_EDITOR_ACT_FORWARD,
    CUI_SNS_EDITOR_ACT_NEW_WITH_RECIPIENT,

    CUI_SNS_EDITOR_PHOTO_COMMENT,

    CUI_SNS_EDITOR_MSG_NEW,
    CUI_SNS_EDITOR_MSG_REPLY,
    CUI_SNS_EDITOR_MSG_NEW_WITH_RECIPIENT,

    CUI_SNS_EDITOR_TOTAL
} cui_sns_editor_enum;


/* Editor recipient selecor mode */
typedef enum
{
    CUI_SNS_EDITOR_RECIPIENT_SELECTOR_FRONT,
    CUI_SNS_EDITOR_RECIPIENT_SELECTOR_REAR,

    CUI_SNS_EDITOR_RECIPIENT_SELECTOR_END
} cui_sns_editor_recipient_selector_enum;


/* Setting CUI types */
typedef enum
{
    CUI_SNS_SETTING_ACCOUNT,
    CUI_SNS_SETTING_FRIEND,
    CUI_SNS_SETTING_NEWSFEED,

    CUI_SNS_SETTING_TOTAL
} cui_sns_setting_enum;

    
/* Event result struct (cui friend link) */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
    cui_sns_result_enum result;
} cui_sns_result_event_struct;


/* Event for filter */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
    cui_sns_result_enum result;
    MMI_BOOL is_group;
    S32 provider;
    S32 list_id;
} cui_sns_filter_event_struct;


/* Event for sender */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
    cui_sns_result_enum result;
    S32 list_id;
} cui_sns_sender_event_struct;


/**************************************************************
 * Global Function Declaration                              *
 **************************************************************/

/*****************************************************************************
 * FUNCTION
 *  cui_sns_filter_create
 * DESCRIPTION
 *  This function is used to create filter cui.
 * PARAMETERS
 *  parent_gid          [in]    parent group id
 *  filter_type         [in]    cui_sns_filter_enum
 * RETURNS
 *  MMI_ID
 *****************************************************************************/
extern MMI_ID cui_sns_filter_create(MMI_ID parent_gid, cui_sns_filter_enum filter_type);


/*****************************************************************************
 * FUNCTION
 *  cui_sns_filter_run
 * DESCRIPTION
 *  This function is used to run filter cui.
 * PARAMETERS
 *  gid          [in]    filter group id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sns_filter_run(MMI_ID gid);


/*****************************************************************************
 * FUNCTION
 *  cui_sns_filter_create_ex
 * DESCRIPTION
 *  This function is used to create and run filter cui.
 * PARAMETERS
 *  parent_gid          [in]    parent group id
 *  filter_type         [in]    cui_sns_filter_enum
 * RETURNS
 *  MMI_ID
 *****************************************************************************/
extern MMI_ID cui_sns_filter_create_ex(MMI_ID parent_gid, cui_sns_filter_enum filter_type);


/*****************************************************************************
 * FUNCTION
 *  cui_sns_filter_close
 * DESCRIPTION
 *  This function is used to close filter cui.
 * PARAMETERS
 *  gd          [in]    filter group id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sns_filter_close(MMI_ID gid);


/*****************************************************************************
 * FUNCTION
 *  cui_sns_sender_create
 * DESCRIPTION
 *  This function is used to create sender cui.
 * PARAMETERS
 *  parent_gid             [in]    parent group id
 *  sender_type         [in]    cui_sns_sender_enum
 * RETURNS
 *  MMI_ID
 *****************************************************************************/
extern MMI_ID cui_sns_sender_create(MMI_ID parent_gid, cui_sns_sender_enum sender_type);


/*****************************************************************************
 * FUNCTION
 *  cui_sns_sender_run
 * DESCRIPTION
 *  This function is used to run sender cui.
 * PARAMETERS
 *  gid             [in]    sender group id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sns_sender_run(MMI_ID gid);


/*****************************************************************************
 * FUNCTION
 *  cui_sns_sender_set_content
 * DESCRIPTION
 *  This function is used to set sender content.
 * PARAMETERS
 *  gid             [in]    sender group id
 *  text            [in]    text
 *  img             [in]    image path
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sns_sender_set_content(MMI_ID gid, WCHAR *text, WCHAR *img_path);


/*****************************************************************************
 * FUNCTION
 *  cui_sns_sender_close
 * DESCRIPTION
 *  This function is used to close sender cui.
 * PARAMETERS
 *  gid             [in]    sender group id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sns_sender_close(MMI_ID gid);


/*****************************************************************************
 * FUNCTION
 *  cui_sns_editor_create
 * DESCRIPTION
 *  This function is used to create editor cui.
 * PARAMETERS
 *  parend_gid             [in]    parent group id
 *  editor_type            [in]    cui_sns_editor_enum
 *  title_id                  [in]    title string id
 * RETURNS
 *  MMI_ID
 *****************************************************************************/
extern MMI_ID cui_sns_editor_create(MMI_ID parend_gid, cui_sns_editor_enum editor_type, U16 title_id);


/*****************************************************************************
 * FUNCTION
 *  cui_sns_editor_set_image
 * DESCRIPTION
 *  This function is used to set image.
 * PARAMETERS
 *  gid             [in]    editor group id
 *  path           [in]    image path
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sns_editor_set_image(MMI_ID gid, WCHAR *path);


/*****************************************************************************
 * FUNCTION
 *  cui_sns_editor_run
 * DESCRIPTION
 *  This function is used to run editor cui.
 * PARAMETERS
 *  gid             [in]    editor group id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sns_editor_run(MMI_ID gid);


/*****************************************************************************
 * FUNCTION
 *  cui_sns_editor_activity_given
 * DESCRIPTION
 *  This function is used to set activity given.
 * PARAMETERS
 *  gid             [in]    editor group id
 *  activity       [in]    forward activity
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sns_editor_activity_given(MMI_ID gid, srv_sns_activity_struct *activity);


/*****************************************************************************
 * FUNCTION
 *  cui_sns_editor_message_given
 * DESCRIPTION
 *  This function is used to message given.
 * PARAMETERS
 *  gid             [in]    editor group id
 *  message     [in]
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sns_editor_message_given(MMI_ID gid, srv_sns_thread_struct *message);


/*****************************************************************************
 * FUNCTION
 *  cui_sns_editor_message_given
 * DESCRIPTION
 *  This function is used to photo given.
 * PARAMETERS
 *  gid             [in]    editor group id
 *  message     [in]
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sns_editor_photo_given(MMI_ID gid, srv_sns_photo_struct *photo);


/*****************************************************************************
 * FUNCTION
 *  cui_sns_editor_fmgr_add_image_run
 * DESCRIPTION
 *  This function is used to fmgr first and run editor cui.
 * PARAMETERS
 *  gid             [in]    editor group id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sns_editor_fmgr_add_image_run(MMI_ID gid);


/*****************************************************************************
 * FUNCTION
 *  cui_sns_editor_camera_add_image_run
 * DESCRIPTION
 *  This function is used to camera first and run editor cui.
 * PARAMETERS
 *  gid             [in]    editor group id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sns_editor_camera_add_image_run(MMI_ID gid);


/*****************************************************************************
 * FUNCTION
 *  cui_sns_editor_set_recipient
 * DESCRIPTION
 *  This function is used to set recipient for ImageViewer & Contact.
 * PARAMETERS
 *  gid             [in]    editor group id
 *  provider      [in]
 *  user           [in]
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sns_editor_set_recipient(MMI_ID gid, U32 provider, srv_sns_user_list_struct user);


/*****************************************************************************
 * FUNCTION
 *  cui_sns_editor_close
 * DESCRIPTION
 *  This function is used to close editor.
 * PARAMETERS
 *  gid             [in]    editor group id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sns_editor_close(MMI_ID gid);


/*****************************************************************************
 * FUNCTION
 *  cui_sns_setting_create
 * DESCRIPTION
 *  This function is used to create setting cui.
 * PARAMETERS
 *  parent_gid             [in]    parent group id
 * RETURNS
 *  MMI_ID
 *****************************************************************************/
extern MMI_ID cui_sns_setting_create(MMI_ID parent_gid);


/*****************************************************************************
 * FUNCTION
 *  cui_sns_setting_run
 * DESCRIPTION
 *  This function is used to run editor.
 * PARAMETERS
 *  gid             [in]    setting group id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sns_setting_run(MMI_ID gid);


/*****************************************************************************
 * FUNCTION
 *  cui_sns_setting_create_ex
 * DESCRIPTION
 *  This function is used to create and run setting cui.
 * PARAMETERS
 *  parent_gid             [in]    parent group id
 * RETURNS
 *  MMI_ID
 *****************************************************************************/
extern MMI_ID cui_sns_setting_create_ex(MMI_ID parent_gid);


/*****************************************************************************
 * FUNCTION
 *  cui_sns_setting_close
 * DESCRIPTION
 *  This function is used to close editor.
 * PARAMETERS
 *  gid             [in]    setting group id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sns_setting_close(MMI_ID gid);


/*****************************************************************************
 * FUNCTION
 *  cui_sns_friend_link_create
 * DESCRIPTION
 *  This function is used to create friend link cui.
 * PARAMETERS
 *  parent_gid             [in]    parent group id
 * RETURNS
 *  MMI_ID
 *****************************************************************************/
extern MMI_ID cui_sns_friend_link_create(MMI_ID parent_gid, U16 contact_id);


/*****************************************************************************
 * FUNCTION
 *  cui_sns_friend_link_run
 * DESCRIPTION
 *  This function is used to run editor.
 * PARAMETERS
 *  gid             [in]    friend link group id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sns_friend_link_run(MMI_ID gid);


/*****************************************************************************
 * FUNCTION
 *  cui_sns_friend_link_close
 * DESCRIPTION
 *  This function is used to close editor.
 * PARAMETERS
 *  gid             [in]    friend link group id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sns_friend_link_close(MMI_ID gid);


/*****************************************************************************
 * FUNCTION
 *  cui_sns_sync_create
 * DESCRIPTION
 *  This function is used to close editor.
 * PARAMETERS
 *  parent_gid             [in]    parent group id
 *  account                 [in]    account data
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_ID cui_sns_sync_create(MMI_ID parent_gid, srv_sns_account_struct *account);


/*****************************************************************************
 * FUNCTION
 *  cui_sns_sync_run
 * DESCRIPTION
 *  This function is used to run sync cui.
 * PARAMETERS
 *  gid             [in]    group id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sns_sync_run(MMI_ID group_id);


/*****************************************************************************
 * FUNCTION
 *  cui_sns_sync_close
 * DESCRIPTION
 *  This function is used to close editor.
 * PARAMETERS
 *  gid             [in]    group id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sns_sync_close(MMI_ID group_id);


#endif /* __SOCIAL_NETWORK_SUPPORT__ */
#endif /* __SNS_CUI_GPROT_H__ */
