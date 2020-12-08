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

/*******************************************************************************
 * Filename:
 * ---------
 *  Vapp_rmgr_service.h
 *
 * Project:
 * --------
 *  VenusMMI
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
 *          HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/


#include "MMI_include.h"

#ifdef __MMI_RMGR__

void mmi_rmgr_send_nw_pwroff_detach_req(void);
void mmi_rmgr_send_nw2_pwroff_detach_req(void);
void mmi_rmgr_send_wap_shutdown_req(void);
void mmi_rmgr_send_mms_shutdown_req(void);
void mmi_rmgr_disable_interrupt(void);
void mmi_rmgr_reboot_ms(void *msg);
void mmi_rmgr_scan_disk(void);
mmi_ret mmi_rmgr_scan_disk_turnoff(mmi_event_struct *evt);
mmi_ret mmi_rmgr_scan_disk_turnoff_1(void);
mmi_ret mmi_rmgr_scan_disk_turnon(mmi_event_struct *evt);
mmi_ret mmi_rmgr_scan_disk_turnon_1(void);


typedef void (*vapp_rmgr_ri_callback)(MMI_BOOL result);


typedef struct
{
    U8 serial;
    U8 reboot_type;
    MMI_BOOL can_cancel;
    MMI_BOOL cancel_when_exit;
#ifdef __MMI_RMGR_SWEEP_DB_PERIODICALLY__
    MMI_BOOL period_sweep_db_finished;
    U8 period_sweep_db_serial;
#endif /* __MMI_RMGR_SWEEP_DB_PERIODICALLY__ */ 
    U16 str_id;
    S8 *path;
    U16 menu_id;
}rmgr_process_db_cntx_struct;

typedef struct
{
#if defined(__MMI_RMGR_SEAMLESS_UNLOCK__) && defined(__MMI_BROWSER_2__)
    S32 sd_callback_id;
#endif
    vapp_rmgr_ri_callback result_callback;
    U16 *file_path;
    U16 *url;
    U16 *confirm_string;
    U16 icon;
    FS_HANDLE file_handle;
    MMI_BOOL is_activating;  /* only usable in __MMI_RMGR_SEAMLESS_UNLOCK__ */
    MMI_BOOL more;
    MMI_BOOL show_detail;
    U8 permission;
}rmgr_request_rights_struct;

extern rmgr_request_rights_struct rmgr_req_ri_entry;

extern rmgr_process_db_cntx_struct rmgr_process_db_cntx ;

#endif /* __MMI_RMGR__ */
