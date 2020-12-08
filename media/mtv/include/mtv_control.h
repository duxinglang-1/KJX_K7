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
 *   mtv_control.h
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
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MTV_CONTROL_H
#define _MTV_CONTROL_H

#ifndef _MTV_COMM_H
#include "mtv_comm.h"
#endif

#include "kal_general_types.h"
#include "mtv_error.h"
#include "med_global.h"

typedef struct mtv_control_volume_t mtv_control_volume_t;

/**
  * Volume control.
  */
struct mtv_control_volume_t
{
    mtv_result_t (*set_mute)(mtv_control_volume_t* control, kal_bool mute);
    mtv_result_t (*get_mute)(mtv_control_volume_t* control, kal_bool* mute);

    mtv_result_t (*set_level)(mtv_control_volume_t* control, kal_int32 level);
    mtv_result_t (*get_level)(mtv_control_volume_t* control, kal_int32* level);
};

typedef struct mtv_control_video_t mtv_control_video_t;

/**
  * Video control.
  */
struct mtv_control_video_t
{
#if defined(__MED_ATV_MOD__)
    mtv_result_t (*set_brightness)(mtv_control_video_t* control, kal_int32 brightness);
    mtv_result_t (*set_contrast)(mtv_control_video_t* control, kal_int32 contrast);
    mtv_result_t (*set_gamma)(mtv_control_video_t* control, kal_int32 gamma);
#endif

#if defined(__MED_MTV_MOD__)
    mtv_result_t (*set_sleep_time)(mtv_control_video_t* control, kal_int32 elapse_ticks, kal_int32 sleep_ticks);
#endif
};

typedef struct mtv_control_record_t mtv_control_record_t;

/**
  * Controls the recording of TV program.
  */
struct mtv_control_record_t
{
    /**
      * Get recorded duration in seconds.
      *
      * @param seconds [out] duration in seconds.
      */
    mtv_result_t (*get_recorded_duration)(mtv_control_record_t* control, kal_uint32* seconds);
};

#define MTV_TIMESHIFT_DELAY_MAX ((kal_uint32)-1)

typedef struct mtv_control_timeshift_t mtv_control_timeshift_t;

/**
  * Time-shift control.
  */
struct mtv_control_timeshift_t
{
    mtv_result_t (*set_pause)(mtv_control_timeshift_t* control, kal_bool pause);
    mtv_result_t (*get_pause)(mtv_control_timeshift_t* control, kal_bool* pause);
    mtv_result_t (*set_delay)(mtv_control_timeshift_t* control, kal_uint32 delay);
    mtv_result_t (*get_delay)(mtv_control_timeshift_t* control, kal_uint32* delay);
    mtv_result_t (*get_buffer_status)(mtv_control_timeshift_t* control, kal_uint32* max_delay, kal_uint32* buffer_duration);
    mtv_result_t (*set_prebuffering)(mtv_control_timeshift_t* control, kal_bool change_state);
};

typedef struct mtv_control_trick_mode_t mtv_control_trick_mode_t;

/**
  * Trick mode control.
  */
struct mtv_control_trick_mode_t
{
    mtv_result_t (*set_rate)(mtv_control_trick_mode_t* control, kal_int32 rate);
    mtv_result_t (*get_rate)(mtv_control_trick_mode_t* control, kal_int32* rate);
};

/**
  * Service control interface ID.
  */
typedef enum
{
    MTV_CONTROL_VOLUME,     /**< mtv_control_volume_t */
    MTV_CONTROL_VIDEO,      /**< mtv_control_video_t */
    MTV_CONTROL_RECORD,     /**< mtv_control_record_t */
    MTV_CONTROL_TIMESHIFT,  /**< mtv_control_timeshift_t */
    MTV_CONTROL_TRICK_MODE  /**< mtv_control_trick_mode_t */

} mtv_control_t;

#endif /* _MTV_CONTROL_H */

