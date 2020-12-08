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
 * SSOAPPSrc.c
 *
 * Project:
 * --------
 *	 MAUI
 *
 * Description:
 * ------------
 *	This file is intends for Yahoo service Settings Acconuts
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

*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef __SSO_CUI_GPROT_H__
#define __SSO_CUI_GPROT_H__

#include "MMI_features.h"

#if defined (__MMI_SSO__) || defined (__SOCIAL_NETWORK_SUPPORT__)

#include "MMIDataType.h"
#include "snssrvgprot.h" /*sns service*/


typedef enum
{
    EVT_ID_CUI_SSO_LOGIN_OK,
    EVT_ID_CUI_SS0_LOGIN_ABORT,
    EVT_ID_CUI_SSO_LOGIN_FAILED
} cui_sso_login_result_event_enum;


typedef enum
{
    EVT_ID_CUI_SSO_LOGIN_DONE,
    EVT_ID_CUI_SSO_LOGIN_DONE_SNS
} cui_sso_login_event_enum;


/* EVT_ID_CUI_SSO_LOGIN_DONE */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
    cui_sso_login_result_event_enum result;
    srv_sns_account_struct *account;
} cui_sso_login_done_sns_event_struct;


/* EVT_ID_CUI_SSO_LOGIN_DONE */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
    cui_sso_login_result_event_enum result;
    U32 provider;
    U8 account_id;
} cui_sso_login_done_event_struct;


/*****************************************************************************
 * FUNCTION
 *  cui_sso_login_create
 * DESCRIPTION
 *  This function is used to create login cui.
 * PARAMETERS
 *  gid          [in]    prarent group id
 * RETURNS
 *  return login cui group id
 *****************************************************************************/
extern MMI_ID cui_sso_login_create(MMI_ID parent_gid, U32 provider, U8 account);

/*****************************************************************************
 * FUNCTION
 *  cui_sso_login_create_bootup
 * DESCRIPTION
 *  This function is used to create login cui when boot up.
 * PARAMETERS
 * parent_gid [IN]   MI_ID  cui parent gid
 * provoider  [IN]   U32 provider id
 * account    [IN]   U8  account id
 * RETURNS
 *  return login cui group id
 *****************************************************************************/
extern MMI_ID cui_sso_login_create_bootup(MMI_ID parent_gid, U32 provider, U8 account);


/*****************************************************************************
 * FUNCTION
 *  cui_sso_login_run
 * DESCRIPTION
 *  This function is used to run login cui.
 * PARAMETERS
 *  gid          [in]    login cui group id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sso_login_run(MMI_ID gid);


/*****************************************************************************
 * FUNCTION
 *  cui_sso_login_close
 * DESCRIPTION
 *  This function is used to close SSO login cuii.
 * PARAMETERS
 *  gid          [in]    login cui group id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sso_login_close(MMI_ID gid);


/*****************************************************************************
 * FUNCTION
 *  cui_sso_login_create_run_sns
 * DESCRIPTION
 *  This function is used to create and run sns login cui.
 * PARAMETERS
 * parent_gid [IN]   MI_ID  cui parent gid
 * provoider  [IN]   srv_sns_account_struct *account
 * RETURNS
 *  return login cui group id
 *****************************************************************************/
extern MMI_ID cui_sso_login_create_run_sns(MMI_ID parent_gid, srv_sns_account_struct *account);


/*****************************************************************************
 * FUNCTION
 *  cui_sso_login_sns_close
 * DESCRIPTION
 *  This function is used to close SSO login cui of sns.
 * PARAMETERS
 *  gid          [in]    login cui group id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sso_login_sns_close(MMI_ID gid);

#endif /* __MMI_SSO__ */
#endif /* __SSO_CUI_GPROT_H__ */

