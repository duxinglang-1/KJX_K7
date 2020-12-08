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
 *  DmSrvScomo.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 * DM service SCOMO header file.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __DM_SRV_SCOMO_H__
#define __DM_SRV_SCOMO_H__

/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/
#include "DmSrvGprot.h"
/****************************************************************************
 * Define
 ****************************************************************************/
#define DM_SCOMO_APP_CMD_INFO_FILE_NAME L"Z:\\@dm\\scomo_app_cmd_info.tmp"

/****************************************************************************
 * Typedef
 ****************************************************************************/
    
typedef enum
{
    SRV_DM_SCOMO_STATUS_NONE,
    SRV_DM_SCOMO_STATUS_INSTALL,
    SRV_DM_SCOMO_STATUS_INSTALL_INACTIVE,
    SRV_DM_SCOMO_STATUS_ACTIVATE,
    SRV_DM_SCOMO_STATUS_INACTIVATE,
    SRV_DM_SCOMO_STATUS_REMOVE,
    SRV_DM_SCOMO_STATUS_REMOVE_ALL,
    SRV_DM_SCOMO_STATUS_END
} srv_dm_scomo_status_enum;

/* Save the user operation info into file */
typedef struct
{                
    srv_dm_scomo_cmd_enum cmd;
    srv_dm_scomo_java_report_info_struct app_cmd_info;
} srv_dm_scomo_app_report_save_file_info_struct;

typedef struct
{
    void *callback;
    srv_dm_scomo_cmd_enum scomo_cmd;
    srv_dm_scomo_status_enum scomo_status;
} srv_dm_scomo_context_struct;
/****************************************************************************
 * Global variable
 ****************************************************************************/

/****************************************************************************
 * Global Function
 ****************************************************************************/
extern void srv_dm_scomo_init(void);
extern void srv_dm_scomo_reset_report_info(void);
extern void srv_dm_scomo_change_status_on_command(void);
extern void srv_dm_scomo_change_status_after_command(void);
extern dm_scomo_error_code_enum srv_dm_scomo_switch_error_code(srv_dm_scomo_result_enum result);
extern void srv_dm_scomo_install_by_srv_ind_hdlr(void *msg);
extern void srv_dm_scomo_remove_by_srv_ind_hdlr(void *msg);
extern void srv_dm_scomo_install_by_user_rsp_hdlr(void *msg);
extern void srv_dm_scomo_remove_by_user_rsp_hdlr(void *msg);
extern void srv_dm_scomo_handle_unfinished_report(void);
extern void srv_dm_scomo_app_operate_notify(
                srv_dm_scomo_cmd_enum cmd,
                srv_dm_scomo_java_report_info_struct *scomo_info);
extern srv_dm_scomo_cmd_enum srv_dm_scomo_get_cmd(dm_scomo_command_enum cmd);


#endif /* __DM_SRV_DL_H__ */
