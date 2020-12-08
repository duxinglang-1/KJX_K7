/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vcui_sns_gprot.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCUI_SNS_GROT_H__
#define __VCUI_SNS_GROT_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __SOCIAL_NETWORK_SUPPORT__
#if defined(__MMI_SNS_PHOTO_UPLOAD__)
#include "mmi_rp_vcui_sns_upload_pic_def.h"
#endif
#ifdef __cplusplus
extern "C"
{
#endif
#include "SnsSrvTypes.h"
#ifdef __cplusplus
}
#endif

#if defined(__MMI_SNS_PHOTO_UPLOAD__)
enum VcuiSnsUploadPicStyleEnum
{
    VCUI_SNS_SLIM = 0, /* Can't change picture in the CUI. Use the enum if app used VCUI_SNS_SLIM_UPLOAD_PIC to calculate memory in app's resource file.*/
    VCUI_SNS_NORMAL,   /* Can change picture in the CUI. Use the enum if app used VCUI_SNS_UPLOAD_PIC to calculate memory in app's resource file.*/

    VCUI_SNS_END,
};
#endif

/* External interface */
#ifdef __cplusplus
extern "C"
{
#endif

typedef enum
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_VCUI_SNS_BEGIN = VCUI_SNS_UPLOAD_PIC,
    /* DOM-NOT_FOR_SDK-END */
    
    EVT_ID_VCUI_SNS_RESULT,    /* This event indicate to close the cui */

    EVT_ID_VCUI_SNS_CONTACT_PICKER_RESULT,
    
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_VCUI_SNS_TOTAL
    /* DOM-NOT_FOR_SDK-END */
} vcui_sns_event_enum;

/* event structure of EVT_ID_VCUI_SNS_RESULT  */
typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    S32     result;         /* > 0: success
                             * = 0: user cancel,
                             * < 0: error */

} vcui_sns_result_event_struct;

/* event structure of EVT_ID_VCUI_SNS_CONTACTS_PICKER_RESULT */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    S32                          result; 
    srv_sns_user_list_struct     *selected_list;
    VfxU8                        selected_list_num;
} vcui_sns_contacts_picker_result_event_sturct;

#if defined(__MMI_SNS_PHOTO_UPLOAD__)
/* DESCRIPTION
 *  Create an instance of "Upload pic CUI", 
 *  Allow user to upload picture.
 * PARAMETERS
 *  caller                  : [IN]  group id of caller
 *  path                    : [IN]  picture path.
 *  style                   : [IN]  style of CUI, see VcuiSnsUploadPicStyleEnum
 * RETURNS
 *  id of the new created CUI
 */
mmi_id vcui_sns_upload_pic_create(mmi_id caller, const WCHAR* path, VcuiSnsUploadPicStyleEnum style);

/* DESCRIPTION
 *  Run function of "Upload pic CUI".
 *  Allow user to upload picture.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
void vcui_sns_upload_pic_run(mmi_id cui_id);


/* DESCRIPTION
 *  Close function of "Upload pic CUI", 
 *  Caller should be responsible for closing CUI it created.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
void vcui_sns_upload_pic_close(mmi_id cui_id);
#endif /* __MMI_SNS_PHOTO_UPLOAD__ */

/* DESCRIPTION
 *  Set filter id function of "Contacts Picker CUI".
 *  Allow user to choose contact.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  filter_id                : [IN] filter id or provider id
 * RETURNS
 *  void
 */
mmi_id vcui_sns_contacts_picker_create(mmi_id parent_gid);


/* DESCRIPTION
 *  Set filter id function of "Contacts Picker CUI".
 *  Allow user to choose contact.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  isProvider             : [IN] indicate the filter id type (if it is sns provider, set to MMI_TRUE; else, set to MMI_FALSE)
 *  filter_id               : [IN] filter id or provider id
 *  to_skip                : [IN] MMI_TRUE : search the contacts exclude the indicated filter
 *                                      MMI_FLASE: search the contacts by the indicated filter
 * RETURNS
 *  void
 */
void vcui_sns_contacts_picker_set_filter_id(mmi_id cui_id, MMI_BOOL isProvider, U32 filter_id, MMI_BOOL toSkip);


/* DESCRIPTION
 *  Set title function of "Contacts Picker CUI".
 *  Allow user to choose contact.
 * PARAMETERS
 *  cui_id                  : [IN] id of CUI
 *  title                     : [IN] tilte of CUI contact pages
 * RETURNS
 *  void
 */
void vcui_sns_contacts_picker_set_title(mmi_id cui_id, const WCHAR *title);


/* DESCRIPTION
 *  Run function of "Contacts Picker CUI".
 *  Allow user to choose contact.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  name                   : [IN]  user name
 *  phone                  : [IN]  user phone
 *  mail                     : [IN]  user email
 * RETURNS
 *  void
 */
void vcui_sns_contacts_picker_enable_recommanded(mmi_id cui_id, const WCHAR *name);

/* DESCRIPTION
 *  Set enable rotation function of "Contacts Picker CUI".
 *  Allow user to choose contact.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  rotate                   : [IN]  enable retataton, default is MMI_FALSE
 * RETURNS
 *  void
 */
void vcui_sns_contacts_picker_enable_rotate(mmi_id cui_id, MMI_BOOL rotate);


/* DESCRIPTION
 *  Set max selected number function of "Contacts Picker CUI".
 *  Allow user to choose contact.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  num                    : [IN]  max selected number
 * RETURNS
 *  void
 */
void vcui_sns_contacts_picker_set_max_selected_num(mmi_id cui_id, U8 num);

/* DESCRIPTION
 *  Set selected account function of "Contacts Picker CUI".
 *  Allow user to choose contact.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  acct_array            : [IN]  selected accounts array
 *  acct_array_num    : [IN]  selected account array number
 * RETURNS
 *  void
 */
void vcui_sns_contacts_picker_set_selected_accounts(mmi_id cui_id, srv_sns_user_list_struct *acct_array, VfxU8 acct_array_num);

/* DESCRIPTION
 *  Run function of "Contacts Picker CUI".
 *  Allow user to choose contact.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
void vcui_sns_contacts_picker_run(mmi_id cui_id);


/* DESCRIPTION
 *  Close function of "Contacts Picker CUI".
 *  Allow user to choose contact.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
void vcui_sns_contacts_picker_close(mmi_id cui_id);

#ifdef __MMI_SNS_MESSAGES__
/* DESCRIPTION
 *  Create an instance of "Compose a sns message CUI", 
 *  Allow user to composer a sns message and send.
 * PARAMETERS
 *  parent_grp_id           : [IN]  group id of caller
 * RETURNS
 *  id of the new created CUI
 */
mmi_id vcui_sns_msg_composer_create(mmi_id parent_grp_id);

/* DESCRIPTION
 *  Run function of "Compose a sns message CUI".
 *  Allow user to composer a sns message and send
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
void vcui_sns_msg_composer_run(mmi_id cui_id);

/* DESCRIPTION
 *  Close function of "Compose a sns message CUI", 
 *  Caller should be responsible for closing CUI it created.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
void vcui_sns_msg_composer_close(mmi_id cui_id);

/* DESCRIPTION
 *  Allow user to set a specific provider id
 * PARAMETERS
 *  caller                  : [IN]  group id of caller
 *  provider_id             : [IN]  provider to send
 * RETURNS
 *  void
 */
void vcui_sns_msg_composer_set_provider_id(mmi_id cui_id, VfxU32 provider_id);

/* DESCRIPTION
 *  Allow user to set a specific recipient list.
 *  But all of the recipients should come from the 
 *  same provider.
 * PARAMETERS
 *  caller                  : [IN]  group id of caller
 *  recipients              : [IN]  recipient list
 *  recipient_count         : [IN]  number of recipients
 * RETURNS
 *  void
 */
void vcui_sns_msg_composer_set_recipient_list(mmi_id cui_id, srv_sns_user_list_struct *recipients, VfxU8 recipient_count);

/* DESCRIPTION
 *  Allow user to set rotate feature. User could 
 *  choose if he needs rotate or not. The default
 *  behavior could support rotate feature.
 * PARAMETERS
 *  isSupportRotate         : [IN]  support rotate or not
 * RETURNS
 *  void
 */
void vcui_sns_msg_composer_set_rotate(mmi_id cui_id, VfxBool isSupportRotate);
#endif /* __MMI_SNS_MESSAGES__ */

#ifdef __cplusplus
}
#endif

#endif /* __SOCIAL_NETWORK_SUPPORT__ */
#endif /* __VCUI_SNS_GROT_H__ */
