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
 *  vcui_sso_gprot.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCUI_SSO_GPROT_H__
#define __VCUI_SSO_GPROT_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_include.h"
#include "vfx_datatype.h"
#ifdef __cplusplus
extern "C"
{
#endif
#ifdef __cplusplus
}
#endif
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/
/* External interface */
#ifdef __cplusplus
extern "C"
{
#endif

extern mmi_ret vapp_sso_create_wizard(mmi_event_struct *param);

/* CUI */
/* <GROUP SSO login Event>
 *  Here are events that "File selector CUI" will notify to caller.
 */
typedef enum
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_VCUI_SSO_LOGIN_BEGIN = VCUI_SSO_SETTING,
    /* DOM-NOT_FOR_SDK-END */
    
    EVT_ID_VCUI_SSO_LOGIN_RESULT,     /* This event indicate the result of sso login cui.
                                       * See vcui_sso_login_result_event_struct for more info */
    
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_VCUI_SSO_LOGIN_TOTAL
    /* DOM-NOT_FOR_SDK-END */
} vcui_sso_login_event_enum;

/* <GROUP SSO login>
 *  Styles of "Folder selector CUI". 
 *  Styles affect major behavior, so it must be assigned during creation, 
 *  and not able to be changed later.
 */
typedef enum
{
    VCUI_SSO_LOGIN_ADD_SUCCESS,
    VCUI_SSO_LOGIN_ADD_FAIL,
    VCUI_SSO_LOGIN_SUCCESS,
    VCUI_SSO_LOGIN_FAIL,
    VCUI_SSO_LOGIN_CANCEL,

    /* DOM-NOT_FOR_SDK-BEGIN */
    VCUI_SSO_LOGIN_RESULT_TOTAL
    /* DOM-NOT_FOR_SDK-END */
} vcui_sso_login_result_enum;


/* <GROUP SSO login Event> 
 *  event structure of EVT_ID_VCUI_SSO_LOGIN_RESULT
 */
typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    vcui_sso_login_result_enum  result;
    VfxU8 accountId;
    VfxU32 providerId;
    VfxS32 err;

} vcui_sso_login_result_event_struct;

/* <GROUP SSO login>
 * DESCRIPTION
 *  Create an instance of "SSO login CUI", 
 *  Allow user to login, add or sign up a SSO account.
 * PARAMETERS
 *  caller                  : [IN]  group id of caller
 *  accountId               : [IN]  accountId.
 * RETURNS
 *  id of the new created CUI
 */
mmi_id vcui_sso_login_create(mmi_id caller, U32 provider, U8 accountId);

/* <GROUP SSO login>
 * DESCRIPTION
 *  Run function of "SSO login CUI".
 *  Allow user to login, add or sign up a SSO account.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
void   vcui_sso_login_run(mmi_id cui_id);

/* <GROUP File Selector>
 * DESCRIPTION
 *  Close function of "SSO login CUI", 
 *  Caller should be responsible for closing CUI it created.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
void   vcui_sso_login_close(mmi_id cui_id);

#ifdef __cplusplus
}
#endif

#endif /* __VCUI_SSO_GPROT_H__ */

