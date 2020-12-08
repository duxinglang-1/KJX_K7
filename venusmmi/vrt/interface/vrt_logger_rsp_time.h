/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vrt_logger_rsp_time.h
 *
 * Project:
 * --------
 *  VRT utility
 *
 * Description:
 * ------------
 *  Response time logger
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VRT_LOGGER_RSP_TIME_H__
#define __VRT_LOGGER_RSP_TIME_H__

// For basic types
#include "vrt_datatype.h"

#define VRT_LOG_RSP_TIME_DATA_SIZE      4

typedef enum _vrt_log_rsp_time_enum
{
    VRT_LOG_RSP_TIME_EVENT_NONE,
    VRT_LOG_RSP_TIME_EVENT_PEN_DOWN,
    VRT_LOG_RSP_TIME_EVENT_PEN_FIRST_MOVE,
    VRT_LOG_RSP_TIME_EVENT_PEN_UP,
    VRT_LOG_RSP_TIME_EVENT_KEY_DOWN,
    VRT_LOG_RSP_TIME_EVENT_KEY_UP,
    VRT_LOG_RSP_TIME_EVENT_SCR_ENTRY,
    VRT_LOG_RSP_TIME_EVENT_BLT,
    VRT_LOG_RSP_TIME_EVENT_TOTAL,
}vrt_log_rsp_time_enum;

typedef struct _vrt_log_rsp_time_data_struct
{
    vrt_u32 flag;
    vrt_u32 ticks;
}vrt_log_rsp_time_data_struct;

typedef struct _vrt_log_rsp_time_msg_struct
{
    vrt_log_rsp_time_data_struct evt_data[VRT_LOG_RSP_TIME_DATA_SIZE];
    vrt_u32 count;
}vrt_log_rsp_time_msg_struct;

extern vrt_u32 *vrt_log_rsp_time_set_event(vrt_log_rsp_time_enum state);
extern void vrt_log_rsp_time_set_event_BLT(vrt_u32 id_ticks);

/********** Guide for vrt_log_rsp_time_logging_var() usage ***************/
/* Following API and logs were used in development of this utility. */
/* To track down the Key/Pen/Screen events, we used the below trace */
/* TRC_VRT_LOG_RSP_TIME_EVENT_OTHER                                 */
/* This was used to throw a specific number and we designated the   */
/* following numbers for different events.                          */

/*  
5005 - vrt_render_draw_frame() - right before BLTing starts - We log the BLT time here.

2001 - vfx_frm_translate_keyhandler / VFX_KEY_EVENT_TYPE_FULL_PRESS_DOWN
2002 - vfx_frm_translate_keyhandler / VFX_KEY_EVENT_TYPE_UP

3001 - vfxPenPrePenEventProc / MMI_PEN_EVENT_DOWN
3002 - vfxPenPrePenEventProc / MMI_PEN_EVENT_MOVE / Only FIRST Pen move is recorded.
3003 - vfxPenPrePenEventProc / MMI_PEN_EVENT_UP
3005 - vfxPenPrePenEventProc / MMI_PEN_EVENT_MOVE / IGNORED

4001 - VfxTopLevel::processScreenBeforeEnter / When a new screen enters

6001 - vrt_frame_commit_end / BLTing with Commit identifier

7001 - vrt_task_main / VRT_MSG_ID_DRAW_COMMAND_COMMIT

*******************************************************
If need be, remove the following statement from comment. 
extern void vrt_log_rsp_time_logging_var(vrt_u32 log_id);
*/

#endif /* __VRT_LOGGER_RSP_TIME_H__ */

