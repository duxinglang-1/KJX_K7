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
 *  RestoreSrvGprot.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __RESTORE_SRV_GPROT_H__
#define __RESTORE_SRV_GPROT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMIDataType.h"
//#include "mmi_rp_srv_restore_def.h" // For 
/***************************************************************************** 
 * Define
 *****************************************************************************/
typedef enum
{
    EVT_ID_SRV_RESTORE_START_NOTIFY = SRV_RESTORE_BASE,

    EVT_ID_SRV_RESTORE_NOTIFY_END    
} srv_restore_notification_enum;
typedef enum
{
    SRV_RESTORE_OK,
    SRV_RESTORE_HOLD,    
    SRV_RESTORE_ERROR,

    SRV_RESTORE_RESULT_ENUM_END
} srv_restore_result_enum;
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef srv_restore_result_enum (*srv_restore_process_func)(void);
typedef void (*srv_restore_callback_func)(MMI_BOOL result);
typedef struct
{
    srv_restore_process_func process_func;    
} srv_restore_table_struct;

/***************************************************************************** 
 * Function
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  srv_restore_start
 * DESCRIPTION
 *  Perform factory restore according to the input table 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_restore_start(srv_restore_table_struct *table, srv_restore_callback_func callback);

/*****************************************************************************
 * FUNCTION
 *  srv_restore_process_callback
 * DESCRIPTION
 *  When the APP finish its a-sync restore operation, this API should be 
 *  called to notify the restore service to continue factory restore 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_restore_process_callback(void);
#endif /* __RESTORE_SRV_GPROT_H__ */
 
