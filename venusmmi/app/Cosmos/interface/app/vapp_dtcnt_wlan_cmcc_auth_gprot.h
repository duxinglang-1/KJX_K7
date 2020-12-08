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
 *  vapp_dtcnt_wlan_cmcc_auth_gprot.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_DTCNT_WLAN_CMCC_AUTH_GPROT_H__
#define __VAPP_DTCNT_WLAN_CMCC_AUTH_GPROT_H__

#ifdef __MMI_OP01_WIFI__
#ifdef __cplusplus
extern "C"
{
#endif
#include "MMIDataType.h"

typedef enum
{
    VAPP_CMCC_WLAN_AUTH_OK = 0, /* Login successfully */

    VAPP_CMCC_WLAN_AUTH_NO_NEED_LOGIN, /* Server response OK directly, could take it as CMCC_WLAN_AUTH_OK */

    VAPP_CMCC_WLAN_AUTH_WBLOCK, /* Would block, callback will be called later */

    VAPP_CMCC_WLAN_AUTH_PARA_ERROR, /* Parameter error */

    VAPP_CMCC_WLAN_AUTH_ABORTED,/* Action aborted by user */

    VAPP_CMCC_WLAN_AUTH_NO_ACCOUNT, /* User press NO in the setting screen */

    VAPP_CMCC_WLAN_AUTH_BUSY, /* Previous login / logout activity not finished */

    VAPP_CMCC_WLAN_AUTH_WPS_ERROR, /* HTTP layer error  */

    VAPP_CMCC_WLAN_AUTH_BEARER_ERROR, /* WiFi AP is unreachable */

    VAPP_CMCC_WLAN_AUTH_LOGIN_FAIL, /* CMCC server response fail, maybe wrong user name or password */

    VAPP_CMCC_WLAN_AUTH_WBLOCK_FAIL /* WBLOCK FAIL*/
}vapp_cmcc_wlan_auth_ret_enum;

typedef struct
{
    MMI_EVT_PARAM_HEADER

    vapp_cmcc_wlan_auth_ret_enum ret;
} vapp_auth_ret_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER

} vapp_auth_close_page_struct;


typedef enum
{
    EVT_ID_VAPP_WLAN_CMCC_AUTH = VAPP_WLAN_AUTH + 1,
    EVT_ID_VAPP_WLAN_CMCC_CLOSE_PAGE,
    EVT_ID_VAPP_AUTH_TOTAL
} vapp_auth_event_id_enum;

/* callback for login / logout result */
typedef void(*vapp_dtcnt_wlan_auth_callback)(vapp_cmcc_wlan_auth_ret_enum ret);

mmi_id vapp_dtcnt_wlan_auth_login(vapp_dtcnt_wlan_auth_callback cb);

mmi_id vapp_dtcnt_wlan_auth_logout(vapp_dtcnt_wlan_auth_callback cb);

void vapp_dtcnt_wlan_auth_abort();

mmi_ret vapp_dtcnt_wlan_auth_launch(mmi_event_struct *param);

MMI_BOOL vapp_dtcnt_wlan_is_auto_auth();

#ifdef __cplusplus
}
#endif

#endif /* __MMI_OP01_WIFI__ */

#endif /* __VAPP_DTCNT_WLAN_CMCC_AUTH_GPROT_H__ */

