#ifdef OBIGO_Q03C_BROWSER
/*****************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2006
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
 *   bam_act.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Object Action handling
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*
 * bam_act.h
 *
 * Description:
 *    Object Action handling
 *
 */

#ifndef _bam_act_h

#define _bam_act_h

#include "msf_pck.h"

/************************************************************
 * Type definitions
 ************************************************************/

typedef MSF_UINT16 bam_act_excl_filter_t;

#define BAM_ACT_FILTER_EXCL_NO      0x0000
#define BAM_ACT_FILTER_EXCL_SAVE_AS 0x0001

typedef MSF_UINT16 bam_act_incl_filter_t;

#define BAM_ACT_FILTER_INCL_NO      0x0000
#define BAM_ACT_FILTER_INCL_SAVE_AS 0x0001
#define BAM_ACT_FILTER_INCL_URL     0x0002

typedef void *bam_act_handle_t;

typedef enum
{
    BAM_ACT_EXEC_RESULT_SUCCESS,
    BAM_ACT_EXEC_RESULT_CANCELLED,
    BAM_ACT_EXEC_RESULT_ERROR
} bam_act_exec_result_enum;

typedef void (*bam_act_get_fn) (bam_act_handle_t *handle);
typedef void (*bam_act_exec_fn) (bam_act_handle_t *handle, MSF_INT32 action_id, bam_act_exec_result_enum result);

typedef struct
{
    const char *title;
    const char *mime_type;
    const char *file_path;
    MSF_UINT32 data_len;
    const char *data;
    MSF_INT16 drm_restriction;
    bam_act_excl_filter_t excl_filter;
    bam_act_incl_filter_t incl_filter;
    void *priv_data;
} bam_act_object_struct;

/************************************************************
 * Functions
 ************************************************************/
/*
 * Initialize action object handling
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
extern void bam_act_init(void);

/*
 * Start/Real initialize action object handling
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
extern void bam_act_start(void);

/*
 * Terminate action object handling
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
extern void bam_act_terminate(void);

/*
 * Retrieve action handle
 *
 * PARAMETERS
 *
 * RETURN    : Object action handle
 */
#if 0
/* under construction !*/
#endif

/*
 * Called when act package is finished
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
extern void bam_act_finished(MSF_INT32 act_id);

extern void bam_act_init_object(bam_act_object_struct *object);

extern bam_act_handle_t *bam_act_session_start(bam_act_object_struct *object);

extern void bam_act_session_terminate(bam_act_handle_t *handle);

/*
 * Get object actions for the object in focus
 */
extern void bam_act_get_actions(bam_act_handle_t *handle, bam_act_get_fn funct);

extern MSF_INT32 bam_act_nbr_of_actions(bam_act_handle_t *handle);

extern MsfStringHandle bam_act_get_string(bam_act_handle_t *handle, MSF_INT32 index);

extern MSF_INT32 bam_act_get_nbr_of_sub_actions(bam_act_handle_t *handle, MSF_INT32 index);

extern MsfStringHandle bam_act_get_sub_string(bam_act_handle_t *handle, MSF_INT32 sub_index, MSF_UINT32 index);

extern void *bam_act_get_private_data(bam_act_handle_t *handle);

extern void bam_act_exec_action(bam_act_handle_t *handle, MSF_INT32 index, bam_act_exec_fn funct);

extern void bam_act_exec_sub_action(
                bam_act_handle_t *handle,
                MSF_INT32 index,
                MSF_UINT32 sub_index,
                bam_act_exec_fn funct);

extern void bam_act_save_get_actions_reply(bam_act_handle_t *handle);

#endif /* _bam_act_h */ 


#endif /*OBIGO_Q03C_BROWSER*/