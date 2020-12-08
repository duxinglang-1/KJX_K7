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
 *   mtv_src_stat.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MTV_SRC_STAT_H
#define _MTV_SRC_STAT_H

#include "kal_general_types.h"

typedef enum
{
    MTV_TIMESTAMP_OK = 0,
    MTV_TIMESTAMP_DUP = -1,
    MTV_TIMESTAMP_BIG_JUMP = -2,
    MTV_TIMESTAMP_REORDERED = -3

} mtv_timestamp_status_t;

typedef struct
{
    kal_uint32 id;
    kal_uint32 au_duration;     /**< access unit duration */
    kal_uint32 possible_au_duration;    /**< possible access unit duration */

    kal_uint32 probing;         /**< successive packets till source is valid */
    kal_uint32 base_timestamp;  /**< base timestamp */
    kal_uint32 max_timestamp;   /**< highest timestamp seen */
    kal_uint32 bad_delta;       /**< last 'bad' delta + 1 */

    /* info about the last packet */

    kal_uint32 loss;            /**< packet loss before last received packet */
    kal_uint32 discontinuity;   /**< indicate whether a timestamp discontinuity is found in last packet */
    kal_uint32 delta;           /**< timestamp delta of last packet */

    /* info about the entire session */

    kal_uint32 received;        /**< packets received */
    kal_uint32 total_loss;      /**< total loss during playback session */
    kal_uint32 invalid;         /**< invalid packet count during playback session */
    kal_uint32 rebasing;        /**< count of timestamp rebasing due to discontinuity */

} mtv_source_stat_t;

/* public functions */

/**
  * Initialize source state with AU duration.
  *
  * @param au_duration [IN] the duration of AU. If 0 is specified, duration probing will be done.
  */
extern void mtv_source_stat_init(mtv_source_stat_t* stat, kal_uint32 au_duration, kal_uint32 stat_id);

/**
  * Initialize source state with AU duration and first timestamp.
  *
  * @param au_duration [IN] the duration of AU. Could not be 0.
  * @param first_timestamp [IN] the first timestamp.
  */
extern void mtv_source_stat_prepare(mtv_source_stat_t* stat, kal_uint32 au_duration, kal_uint32 first_timestamp);

/**
  * Update source state by packet timestamp.
  *
  * @param timestamp [IN] timestamp of new incoming packet
  * @return timestamp status
  */
extern mtv_timestamp_status_t mtv_source_stat_update(mtv_source_stat_t* stat, kal_uint32 timestamp);

/**
  * Notify about new time segment.
  * @param timestamp [IN] timestamp of new segment
  */
extern void mtv_source_stat_new_segment(mtv_source_stat_t* stat, kal_uint32 timestamp);

#endif /* _MTV_SRC_STAT_H */
