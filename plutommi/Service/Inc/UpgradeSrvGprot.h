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
 *  UpgradeSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Upgrade service exported enums, structures, functions and constant definitions
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VPP_UPGRADE_SRV_GPROT_H__
#define __VPP_UPGRADE_SRV_GPROT_H__

#include "mmi_frm_gprot.h"

typedef enum
{
    SRV_UPGRADE_ORIGINATOR_SNS,
    SRV_UPGRADE_ORIGINATOR_CLOUD_SSO,
    SRV_UPGRADE_ORIGINATOR_CLOUD_BACKUP_RESTORE,
    SRV_UPGRADE_ORIGINATOR_CLOUD_EMAIL,
    SRV_UPGRADE_ORIGINATOR_MRE,
    SRV_UPGRADE_ORIGINATOR_ALL,
}srv_upgrage_originator_enum;

typedef enum
{
    SRV_UPGRADE_STATUS_WAITING_TO_CHECK,    
    SRV_UPGRADE_STATUS_CHECKING,
    SRV_UPGRADE_STATUS_NO_UPGRADE,
    SRV_UPGRADE_STATUS_HAS_NEW_VERSION,
    SRV_UPGRADE_STATUS_DOWNLOADING,
    SRV_UPGRADE_STATUS_CANCELLED,
    SRV_UPGRADE_STATUS_FAILED,
    SRV_UPGRADE_STATUS_DOWNLOADED,
    SRV_UPGRADE_STATUS_NOT_SUPPORT,
    SRV_UPGRADE_STATUS_ALL,
}srv_upgrage_status_enum;

typedef struct srv_upgrade_req
{
    U32 provider;                                         // provider id
    WCHAR *path;                                          // path of the vpp
    WCHAR *url;
    struct srv_upgrade_req *next;
} srv_upgrade_req_struct;

typedef struct srv_upgrade_result
{
    U32 provider;                                        // app_id
    srv_upgrage_status_enum status;                 // status
    WCHAR *path;                                    // download url or downloaded path
    struct srv_upgrade_result *next;
} srv_upgrade_result_struct;

typedef struct srv_upgrade_vpp_info
{
    U32 provider;                                        // provider id
    U32 version;                                         // version   
    S32 app_id;                                        // app_id
    CHAR *download_url;
    WCHAR *app_name;
    WCHAR *path;                                    // download url or downloaded path
    srv_upgrage_status_enum status;                 // status
    struct srv_upgrade_vpp_info *next;
} srv_upgrade_vpp_info_struct;

typedef struct srv_upgrade_download_info
{
    U32 count;                                          // number of vpps to check
    srv_upgrage_originator_enum originator;         // originator                    
    srv_upgrade_vpp_info_struct *vpp_info;          // download url or downloaded path                     
} srv_upgrade_download_info_struct;


/* event structure for EVT_ID_SRV_VPP_UPGRADE_DOWNLOAD_REQ */
typedef struct srv_upgrade_evt_download_req {
   MMI_EVT_PARAM_HEADER
   srv_upgrade_download_info_struct *info;
} srv_upgrade_evt_download_req_struct;


/* event structure for EVT_ID_SRV_UPGRADE_CHECK_VERSION_DONE_IND */
typedef struct srv_upgrade_evt_check_version_done_ind{
   MMI_EVT_PARAM_HEADER
} srv_upgrade_evt_check_version_done_ind_struct;

/* event structure for EVT_ID_SRV_UPGRADE_DOWNLOAD_APP_DONE_IND */
typedef struct srv_upgrade_evt_download_app_done_ind{
   MMI_EVT_PARAM_HEADER
} srv_upgrade_evt_download_app_done_ind_struct;

/* event structure for EVT_ID_SRV_UPGRADE_NOTIFY_RESULT_IND */
typedef struct srv_upgrade_evt_notify_result_ind{
   MMI_EVT_PARAM_HEADER
} srv_upgrade_evt_notify_result_ind_struct;

typedef void (*srv_vpp_upgrade_result_callback)(srv_upgrage_originator_enum originator, srv_upgrade_result_struct *result);

/*****************************************************************************
 * FUNCTION
 *  srv_upgrade_check_update
 * DESCRIPTION
 *  Check if there is a new version for a list of vpp
 * PARAMETERS
 *  vpp_info             [IN]    vpp information list
 *  count                [IN]    vpp number
 *  originator           [IN]    app enum
 *  cb                   [IN]    callback function
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_upgrade_check_update(srv_upgrade_req_struct* vpp_info, U8 count, srv_upgrage_originator_enum originator, srv_vpp_upgrade_result_callback cb);

/******************************************************************************
 * FUNCTION
 *  srv_upgrade_download
 * DESCRIPTION
 *  API for Upgrade APP to notify user agree to download new version
 * PARAMETERS
 *  originator  [IN]    source of the request
 * RETURNS
 *  void
 ******************************************************************************/
void srv_upgrade_download(srv_upgrage_originator_enum originator);

/******************************************************************************
 * FUNCTION
 *  srv_upgrade_cancel
 * DESCRIPTION
 *  API for Upgrade APP to notify user do not want to download new version
 * PARAMETERS
 *  originator  [IN]    source of the request
 * RETURNS
 *  void
 ******************************************************************************/
void srv_upgrade_cancel(srv_upgrage_originator_enum originator);
#endif  /* __VPP_UPGRADE_SRV_GPROT_H__ */
