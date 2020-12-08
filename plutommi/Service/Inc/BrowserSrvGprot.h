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
 * BrowserSrvGProt.h
 *
 * Project:
 * --------
 *   MAUI
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

#ifdef BROWSER_SUPPORT

#include "MMI_include.h"
#ifndef MMI_BROWSERSRVGPROT_H
#define MMI_BROWSERSRVGPROT_H

/*  Include: MMI header file */


#include "WAPProfileSrvGProt.h"
#include "Browser_api.h"
#ifdef __MMI_BROWSER_2__
#include "mmi_res_range_def.h"
#endif
/* Browser Event Type */

/************************************************************
 * Define
 ************************************************************/
#define SRV_BRW_PROF_USERNAME_LEN  41    /* SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN + 1 */
#define SRV_BRW_PROF_PASSWORD_LEN  41    /* SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN + 1 */
#define SRV_BRW_PROF_URL_LEN       1025


#ifdef __MMI_BROWSER_2__
typedef enum
{
    EVT_ID_SRV_BRW_ERROR_IND = MMI_BRW_SRV_BASE + 1,
    EVT_ID_SRV_BRW_SHOW_POPUP,
	EVT_ID_SRV_BRW_UPDATE_TITLE, //notify app ind
	EVT_ID_SRV_BRW_RENDERING_STATUS_START_IND,
	EVT_ID_SRV_BRW_RENDERING_STATUS_END_IND,
	EVT_ID_SRV_BRW_RENDERING_STATUS_CONTINUE_IND,
	EVT_ID_SRV_BRW_DOC_INFO_IND,
	EVT_ID_SRV_BRW_SHOW_SEC_CNF_DLG,
	EVT_ID_SRV_BRW_SELECT_FILE_IND,
	EVT_ID_SRV_BRW_URI_REQ_IND,
	EVT_ID_SRV_BRW_WAIT_USER_ACTION_IND,
	EVT_ID_SRV_BRW_SHOW_AUTH_DLG,
	EVT_ID_SRV_BRW_RENDERING_ERROR_IND,
	EVT_ID_SRV_START_BROWSER_ACTION_IND,
	EVT_ID_SRV_BRW_SAT_LAUNCH_REQ,
	EVT_ID_SRV_BRW_ELEMENT_FOCUSSED_IND,
	EVT_ID_SRV_BRW_WMLS_DLG_IND,
    EVT_ID_SRV_BRW_BKM_PROVISIONING_IND,
    EVT_ID_SRV_BRW_OPEN_BEARER_IND,
	/* Add events before this */
    EVT_ID_SRV_BRW_END
} srv_brw_event_enum;
#endif

typedef enum
{
	SRV_BRW_ERROR_TRUSTED_CERT_FAIL = -1,
  SRV_BRW_ERROR_OK,
  SRV_BRW_ERROR_INVALID_URL,
  SRV_BRW_ERROR_READ_ONLY_PROFILE,
	SRV_BRW_WAP_NOT_READY,
  SRV_BRW_ERROR
} srv_brw_error_enum;

typedef enum
{
  SRV_BRW_DTCNT_PRIMARY = 1,
  SRV_BRW_DTCNT_SECONDARY    
} srv_brw_dtcnt_count_enum;

typedef enum
{
  SRV_BRW_PROF_CONN_TYPE_NONE,
  SRV_BRW_PROF_CONN_TYPE_HTTP,
  SRV_BRW_PROF_CONN_TYPE_CONNECTION_OREINTED,
  SRV_BRW_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE,
  SRV_BRW_PROF_CONN_TYPE_TOTAL
} srv_brw_conn_type_enum;

typedef struct
{
  kal_uint8  *proxy_ip;
  kal_uint8  username[SRV_BRW_PROF_USERNAME_LEN];
  kal_uint8  password[SRV_BRW_PROF_PASSWORD_LEN];
  kal_uint8  url[SRV_BRW_PROF_URL_LEN];
  kal_uint32 data_account_primary_id;
  kal_uint32 data_account_secondary_id;
  kal_uint16 proxy_port;
  srv_brw_conn_type_enum conn_type;    
} srv_brw_profile_content_struct;

#ifdef __MMI_WAP_PROF__
extern void srv_brw_add_bookmark_provisioning (U8 *title_p, U8 *url_p, srv_wap_prof_response_funcptr_type callback);
extern void srv_brw_active_profile_changed_hdlr(
                srv_wap_prof_profile_content_struct *profile_content_p,
                srv_wap_prof_sim_id_enum sim_id,
                srv_wap_prof_response_funcptr_type callback);
#endif /* __MMI_WAP_PROF__ */
extern void srv_brw_get_active_sim_setting (U32 *active_sim, U16 *is_asked);
extern mmi_brw_sim_id_enum srv_brw_get_active_sim_id(void);
extern kal_bool srv_brw_get_default_bookmark_by_index (int index, kal_uint8 *title_buf, kal_uint16 title_buf_len, 
													 kal_uint8 *url_buf, kal_uint16 url_buf_len);
extern int srv_brw_get_num_of_default_bookmarks(void);
extern int srv_brw_get_num_of_user_defined_bookmarks(void);
extern srv_brw_error_enum srv_brw_set_as_homepage(U8 *url_p);
extern kal_bool srv_brw_get_active_browser_profile(srv_brw_profile_content_struct *active_prof);

#endif /* MMI_BROWSERSRVPROTS_H */

#endif /* BROWSER_SUPPORT */
