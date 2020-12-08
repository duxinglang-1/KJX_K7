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
 *  SecSetSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Interface of security setting
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SRV_SECSET_GPROT_H__
#define __SRV_SECSET_GPROT_H__

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMIDataType.h"


/****************************************************************************
 * Constant
 ****************************************************************************/

/*
 * DESCRIPTION
 *  Minimum length of phone password
 */
#define SRV_SECSET_MIN_PHONE_PASSWORD_LEN 4

/*
 * DESCRIPTION
 *  Maximum length of phone password
 */
#define SRV_SECSET_MAX_PHONE_PASSWORD_LEN 8


/****************************************************************************
 * Functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_secset_phone_lock_is_enabled
 * DESCRIPTION
 *  Check whether the phone lock is enabled.
 *  If enabled, phone password is required during booting.
 * PARAMETERS
 *  void
 * RETURNS
 *  Enabled or not
 *****************************************************************************/
MMI_BOOL srv_secset_phone_lock_is_enabled(void);

/*****************************************************************************
 * FUNCTION
 *  srv_secset_phone_lock_set_enabled
 * DESCRIPTION
 *  Set enabled of phone lock.
 *  If enabled, phone password is required during booting.
 * PARAMETERS
 *  enabled     : [IN] Target setting of phone lock
 *  password    : [IN] Phone password
 *  proc        : [IN] Proc for EVT_ID_SRV_SECSET_PHONE_LOCK_SET_ENABLED_RESULT
 *  user_data   : [IN] To be passed into the proc
 * RETURNS
 *  Session ID; > 0 means session is successfully started and result will be
 *  notified by the given proc.
 *****************************************************************************/
S32 srv_secset_phone_lock_set_enabled(
    MMI_BOOL enabled,
    const WCHAR *password,
    mmi_proc_func proc,
    void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_secset_verify_phone_password
 * DESCRIPTION
 *  Verify phone password.
 *  It does not require phone lock is enabled.
 * PARAMETERS
 *  password    : [IN] Phone password
 *  proc        : [IN] Proc for EVT_ID_SRV_SECSET_VERIFY_PHONE_PASSWORD_RESULT
 *  user_data   : [IN] To be passed into the proc
 * RETURNS
 *  Session ID; > 0 means session is successfully started and result will be
 *  notified by the given proc.
 *****************************************************************************/
S32 srv_secset_verify_phone_password(const WCHAR *password, mmi_proc_func proc, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_secset_change_phone_password
 * DESCRIPTION
 *  Change phone password.
 *  It does not require phone lock is enabled. The change will not affect the
 *  enableness of phone lock.
 * PARAMETERS
 *  old_pwd     : [IN] Old phone password
 *  new_pwd     : [IN] New phone password
 *  proc        : [IN] Proc for EVT_ID_SRV_SECSET_CHANGE_PHONE_PASSWORD_RESULT
 *  user_data   : [IN] To be passed into the proc
 * RETURNS
 *  Session ID; > 0 means session is successfully started and result will be
 *  notified by the given proc.
 *****************************************************************************/
S32 srv_secset_change_phone_password(
    const WCHAR *old_pwd,
    const WCHAR *new_pwd,
    mmi_proc_func proc,
    void *user_data);


/****************************************************************************
 * Events
 ****************************************************************************/

/*
 * Events of security setting.
 */
typedef enum
{
    /*
     * Result of srv_secset_phone_lock_set_enabled
     * Structure:
     *  srv_secset_phone_lock_set_enabled_result_evt_struct
     */
    EVT_ID_SRV_SECSET_PHONE_LOCK_SET_ENABLED_RESULT = SRV_SECURITY_SETTING,

    /*
     * Result of srv_secset_verify_phone_password
     * Structure:
     *  srv_secset_verify_phone_password_result_evt_struct
     */
    EVT_ID_SRV_SECSET_VERIFY_PHONE_PASSWORD_RESULT,

    /*
     * Result of srv_secset_change_phone_password
     * Structure:
     *  srv_secset_change_phone_password_result_evt_struct
     */
    EVT_ID_SRV_SECSET_CHANGE_PHONE_PASSWORD_RESULT,
    
    EVT_ID_SRV_SECSET_END_OF_ENUM
} srv_secset_event_enum;


/*
 * Strurture of EVT_ID_SRV_SECSET_PHONE_LOCK_SET_ENABLED_RESULT
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    MMI_BOOL success;       /* Success or not */
    MMI_BOOL is_enabled;    /* The enableness of phone lock */
} srv_secset_phone_lock_set_enabled_result_evt_struct;


/*
 * Structure of EVT_ID_SRV_SECSET_VERIFY_PHONE_PASSWORD_RESULT
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    MMI_BOOL success;       /* Success or not */
} srv_secset_verify_phone_password_result_evt_struct;


/*
 * Structure of EVT_ID_SRV_SECSET_CHANGE_PHONE_PASSWORD_RESULT
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    MMI_BOOL success;       /* Success or not */
} srv_secset_change_phone_password_result_evt_struct;


#endif /* __SRV_SECSET_GPROT_H__ */

