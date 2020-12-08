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
 *  UpgradeSrvUtil.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Upgrade service utility header
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __UPGRADE_SRV_UTIL_H__
#define __UPGRADE_SRV_UTIL_H__

#include "DLAgentSrvGProt.h"
#include "UpgradeSrvGprot.h"
#include "FileMgrSrvGProt.h"

//#define UPGRADE_DEBUG_MEM

typedef enum 
{
    SRV_UPGRADE_REQUEST_STATE_START,
    SRV_UPGRADE_REQUEST_STATE_CHECK_NEW_VERSION,
    SRV_UPGRADE_REQUEST_STATE_WAITING_PERMISSION,
    SRV_UPGRADE_REQUEST_STATE_WAITING_DOWNLOAD,
    SRV_UPGRADE_REQUEST_STATE_DOWNLOADING,
    SRV_UPGRADE_REQUEST_STATE_FINISHED,
}srv_upgrade_reqest_state_enum;

typedef struct srv_upgrade_req_info
{
    U8 count;
    U8 download_count;
    U32 da_hdlr;
    S32 http_req_hdlr;
    srv_upgrage_originator_enum originator;
    srv_upgrade_reqest_state_enum state;
    srv_upgrade_vpp_info_struct *vpp_info;
    srv_upgrade_vpp_info_struct *checking_vpp;
    srv_upgrade_vpp_info_struct *downloading_vpp;
    srv_upgrade_download_info_struct *download_info;
    srv_vpp_upgrade_result_callback cb;
    struct srv_upgrade_req_info *next;
}srv_upgrade_req_info_struct;

typedef struct srv_upgrade_contex
{
    U8 cbm_app_id;
    U8 default_drive;
    U32 cbm_account_id;
    KAL_ADM_ID adm_id;
    S32 session;
    MMI_BOOL notify_result_sent;
    MMI_BOOL is_ready;
    srv_upgrade_req_info_struct *requests;
    srv_upgrade_req_info_struct *checking_req;
    srv_upgrade_req_info_struct *downloading_req;
    srv_upgrade_vpp_info_struct *downloaded_vpps;
    srv_da_start_download_struct *da_info;
} srv_upgrade_contex_struct;

#define SRV_UPGRADE_MAX_PATH_LEN                (SRV_FMGR_PATH_MAX_LEN + 1)
#define DEFAULT_FOLDER L"@upgrade"

/*****************************************************************************
 * FUNCTION
 *  upgrade_util_init_mem
 * DESCRIPTION
 *  Init memory allocator
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void upgrade_util_init_mem(void);

#if defined(UPGRADE_DEBUG_MEM)
#define upgrade_util_alloc(size) upgrade_util_alloc_int(size, __FILE__, __LINE__)
#define upgrade_util_free(mem) upgrade_util_free_int(mem, __FILE__, __LINE__)

extern void* upgrade_util_alloc_int(U32 size, const char *filename, int lineno);
extern void  upgrade_util_mem_free_int(void* p, const char *filename, int lineno); 
#else
#define upgrade_util_alloc(size) upgrade_util_alloc_int(size)
#define upgrade_util_free(mem) upgrade_util_free_int(mem)

extern void* upgrade_util_alloc_int(U32 size);
extern void  upgrade_util_mem_free_int(void* p); 
#endif

/*****************************************************************************
 * FUNCTION
 *  upgrade_util_free_vpp_info
 * DESCRIPTION
 *  Free vpp info
 * PARAMETERS
 *  request              [IN]    request pointer
 * RETURNS
 *  void
 *****************************************************************************/
void upgrade_util_free_vpp_info(srv_upgrade_vpp_info_struct *vpp_info);

/*****************************************************************************
 * FUNCTION
 *  upgrade_util_free_vpp_info_list
 * DESCRIPTION
 *  Free list of vpp info
 * PARAMETERS
 *  head             [IN]    vpp info list head
 * RETURNS
 *  void
 *****************************************************************************/
void upgrade_util_remove_vpp_info_list(srv_upgrade_vpp_info_struct *head);

/*****************************************************************************
 * FUNCTION
 *  upgrade_util_free_req_info
 * DESCRIPTION
 *  Free request info
 * PARAMETERS
 *  request              [IN]    request pointer
 * RETURNS
 *  void
 *****************************************************************************/
void upgrade_util_free_req_info(srv_upgrade_req_info_struct *req);

/*****************************************************************************
 * FUNCTION
 *  upgrade_util_free_da_info
 * DESCRIPTION
 *  Free download agent's information pointer
 * PARAMETERS
 *  da_info              [IN]    Download agent info pointer
 * RETURNS
 *  void
 *****************************************************************************/
void upgrade_util_free_da_info(srv_da_start_download_struct *da_info);

/*****************************************************************************
 * FUNCTION
 *  upgrade_util_free_req_info
 * DESCRIPTION
 *  Free request info
 * PARAMETERS
 *  request              [IN]    request pointer
 * RETURNS
 *  void
 *****************************************************************************/
void upgrade_util_free_results(srv_upgrade_result_struct *results);

/*****************************************************************************
 * FUNCTION
 *  upgrade_util_check_compile_option
 * DESCRIPTION
 *  Check upgrade for the originator is opened
 * PARAMETERS
 *  originator    [IN] the originator
 * RETURNS
 *  MMI_TRUE if allow to check upgrade
 *****************************************************************************/
MMI_BOOL upgrade_util_check_compile_option(srv_upgrage_originator_enum originator);

/*****************************************************************************
 * FUNCTION
 *  upgrade_util_create_default_folder
 * DESCRIPTION
 *  Create default folder of upgrade service if not exist
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if exists or created
 *****************************************************************************/
MMI_BOOL upgrade_util_create_default_folder(U8 drive);

/*****************************************************************************
 * FUNCTION
 *  upgrade_util_get_filename
 * DESCRIPTION
 *  Get filename part from a url
 * PARAMETERS
 *  url                  [IN]    URL
 * RETURNS
 *  Start position of a filename
 *****************************************************************************/
WCHAR *upgrade_util_get_filename(WCHAR* url);

/*****************************************************************************
 * FUNCTION
 *  upgrade_util_prepare_url
 * DESCRIPTION
 *  Generate the url to check new version
 * PARAMETERS
 *  vpp_info             [IN]    vpp information
 * RETURNS
 *  Generated URL
 *****************************************************************************/
CHAR *upgrade_util_prepare_url(srv_upgrade_vpp_info_struct *vpp_info);

/*****************************************************************************
 * FUNCTION
 *  upgrade_util_find_downloaded_vpps
 * DESCRIPTION
 *  Get downloaded vpps' information
 * PARAMETERS
 *  void
 * RETURNS
 *  VPP info list if found
 *****************************************************************************/
srv_upgrade_vpp_info_struct *upgrade_util_find_downloaded_vpps(U8 drive);

/*****************************************************************************
 * FUNCTION
 *  upgrade_util_check_vpp_existence
 * DESCRIPTION
 *  Check downloaded vpps existence
 * PARAMETERS
 *  head             [IN]    vpp info list head
 * RETURNS
 *  void
 *****************************************************************************/
void upgrade_util_check_vpp_existence(srv_upgrade_vpp_info_struct *head);

#endif
