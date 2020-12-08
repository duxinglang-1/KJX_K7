/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   AppMemMgrCore.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   add_description_here
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
 * removed!
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef __APPMEMMGRCORE_H__
#define __APPMEMMGRCORE_H__

/*****************************************************************************
 * Include header files
 *****************************************************************************/

/*****************************************************************************
 * Define
 *****************************************************************************/


/*****************************************************************************
 * Typedef
 *****************************************************************************/
typedef enum {
	ASM_CORE_STATE_NONE,
	ASM_CORE_STATE_BEGIN,
	ASM_CORE_STATE_FREE_VOLUNTEERS,
	ASM_CORE_STATE_FREE_IN_USED,
	ASM_CORE_STATE_FREE_SELECTED,
	ASM_CORE_STATE_WAIT,
	ASM_CORE_STATE_CANCEL,
	ASM_CORE_STATE_SUCCESS,
	ASM_CORE_STATE_V10,    // for v1.0 free volunteer
	ASM_CORE_STATE_END_OF_ENUM
} asm_core_state_enum;

typedef enum {
    ASM_CORE_WAIT_NONE,
    ASM_CORE_WAIT_VOLUNTEER,
    ASM_CORE_WAIT_IN_USED,
    ASM_CORE_WAIT_SELECTED,
    ASM_CORE_WAIT_V10,
    ASM_CORE_WAIT_SYNC_FREE,
    ASM_CORE_WAIT_V10_FORCE_FREE,
    ASM_CORE_WAIT_END_OF_ENUM
} asm_core_wait_type_enum;

typedef enum
{
    ASM_INIT_STAGE1   = 250,
    ASM_INIT_STAGE2   = 251,
    ASM_INIT_STAGE_END
} asm_init_stage_enum;

typedef enum
{
    ASM_CONTINUE_TO_CLOSE,
    ASM_CONTINUE_TO_IDLE,
    ASM_BACKWARD_PREPARE,
    ASM_ENLARGE_HEAP,
    ASM_UNHIDE_PREPARE,
	ASM_SET_ACTIVE_PREPARE,

    ASM_INTERNAL_EVT_MAX
} asm_internal_evt_enum;

typedef enum
{
    CLOSING,
    CLOSING_TO_IDLE,
    CLOSED,
} app_close_state_enum;

typedef enum {
    ASM_CORE_CB_SUCCESS,
    ASM_CORE_CB_CANCEL,
    ASM_CORE_CB_END_OF_ENUM
} asm_core_cb_type;




#endif /* __APPMEMMGRCORE_H__ */
