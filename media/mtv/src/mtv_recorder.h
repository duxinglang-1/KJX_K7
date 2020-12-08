/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   mtv_recorder.h
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
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MTV_RECORDER_H
#define _MTV_RECORDER_H

#ifndef _MTV_COMM_H
#include "mtv_comm.h"
#endif

#ifndef _MTV_BUFFER_ENGINE_H
#include "mtv_buffer_engine.h"
#endif

#ifndef _MTV_CONTROL_H
#include "mtv_control.h"
#endif

#include "kal_general_types.h"
#include "mtv_error.h"
#include "mtv_custom.h"

typedef enum
{
    MTV_RECORDER_STATE_STOPPED,   /**< the recorder is started */
    MTV_RECORDER_STATE_STARTED,   /**< the recorder is stopped */
    MTV_RECORDER_STATE_SAVING     /**< the recorder is saving the recorded program */

} mtv_recorder_state_t;

/**
  * Context of checkpoint saving.
  */
typedef struct
{
    kal_wchar* file;
    kal_wchar* temp;

} mtv_checkpoint_context_t;

typedef struct mtv_recorder_client_t mtv_recorder_client_t;

/**
  * Client interface of player.
  */
struct mtv_recorder_client_t
{
    kal_uint32 session_id;

    void (*on_state_change)(mtv_recorder_client_t* client, mtv_recorder_state_t state);
    void (*on_error)(mtv_recorder_client_t* client, mtv_result_t result);
    void (*on_save)(mtv_recorder_client_t* client, mtv_result_t result);
};

typedef struct mtv_recorder_t mtv_recorder_t;

/**
  * Mobile TV recorder.
  */
struct mtv_recorder_t
{
    /**
      * Start file recording.
      *
      * @param be [in] the buffer engine as media source
      * @param client [in] the recorder client
      * @param recording_name [in] the base filename for recording
      * @param recording_format [in] the file format of recording
      */
    mtv_result_t (*start)(
        mtv_recorder_t* self,
        mtv_buffer_engine_t* be,
        mtv_recorder_client_t* client,
        const kal_wchar* recording_dir,
        const kal_wchar* recording_name,
        mtv_recording_format_t recording_format);

    /**
      * Query specified control interface.
      */
    mtv_result_t (*get_control)(mtv_recorder_t* self, mtv_control_t control_id, void** control);

    /**
      * Get current recorder state.
      */
    mtv_recorder_state_t (*get_state)(mtv_recorder_t* self);

    /**
      * Stop recording.
      */
    mtv_result_t (*stop)(mtv_recorder_t* self);

    /**
      * pause recording.
      */
    mtv_result_t (*pause)(mtv_recorder_t* self);

    /**
      * resume recording.
      */
    mtv_result_t (*resume)(mtv_recorder_t* self);

    /**
      * Do the preparation for saving.
      */
    mtv_result_t (*prepare_saving)(mtv_recorder_t* self);

    /**
      * Save the recording into local file. Note that prepare_saving should be called
      * before calling this function.
      *
      * @param record_dir [in] the folder path where the recording will be saved.
      * @param aborted [in] the address of boolean variable to trigger the saving abort.
      */
    mtv_result_t (*do_saving)(mtv_recorder_t* self, const kal_wchar* record_dir, kal_wchar* file_path, volatile kal_bool* aborted);

    /**
      * Save recording checkpoint so that it can be recovered after abnormal reset.
      *
      * @param dir [in] the folder path where the checkpoint will be saved.
      */
    mtv_result_t (*save_checkpoint)(mtv_recorder_t* self, const kal_wchar* dir);

    /**
      * Recover recording from checkpoint.
      *
      * @param checkpoint [in] the full path of checkpoint file.
      * @param aborted [in] the address of boolean variable to trigger the saving abort.
      */
    mtv_result_t (*recover_from_checkpoint)(mtv_recorder_t* self, const kal_wchar* checkpoint, const kal_wchar* record_dir,volatile kal_bool* aborted);

    /**
      * Delete checkpoint.
      */
    mtv_result_t (*delete_checkpoint)(mtv_recorder_t* self);

    /**
      * Destroy the instance.
      */
    void (*destroy)(mtv_recorder_t* self);

    /* private data */

    mtv_recorder_state_t state;
    kal_uint16 app_id;

    mtv_recorder_client_t* client;
    mtv_control_record_t record_ctrl;

    mtv_buffer_engine_t* be;

    mtv_recording_format_t recording_format;
    kal_wchar recording_name[MTV_MAX_SERVICE_NAME];

    mtv_checkpoint_context_t* chkpt_ctx;
};

/* instance creation */

extern mtv_recorder_t* construct_mtv_recorder(kal_uint16 app_id);

/* helper functions */

/**
  * @return whether there is recoverable checkpoint file in specified directory.
  */
extern kal_bool mtv_recorder_find_checkpoints(kal_uint16 app_id, const kal_wchar* dir);

/**
  * Discard unsaved recording files in specified directory.
  */
extern void mtv_recorder_discard_unsaved_recording(kal_uint16 app_id, const kal_wchar* dir);

/**
  * Recover unsaved recording in specified directory.
  */
extern mtv_result_t mtv_recorder_recover_recording(kal_uint16 app_id, const kal_wchar* dir, const kal_wchar* record_dir, volatile kal_bool* aborted);

#endif /* _MTV_RECORDER_H */
