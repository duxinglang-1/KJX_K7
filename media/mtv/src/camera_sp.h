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
 *   camera_sp.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _CAMERA_SP_H
#define _CAMERA_SP_H

#ifndef _MTV_SPI_H
#include "mtv_spi.h"
#endif

#ifndef _MED_STRUCT_H
#include "med_struct.h"
#endif

typedef enum
{
    CAMERA_SERVICE_STOPPED,       /**< the service is stopped */
    CAMERA_SERVICE_STARTED,       /**< the service is started but not ready to run */
    CAMERA_SERVICE_READY          /**< the service is ready to run */
} camera_service_context_state_t;

/**
  * Camera stream info.
  */
typedef struct
{
    //camera_stream_type_t stream_type;     /**< stream type */
    mtv_dec_config_t dec_config;        /**< decoder configuration */

} camera_stream_info_t;

/**
  * Camera service context. This struct contains runtime information about a started service.
  */
typedef struct
{
    kal_uint32 sid;                     /**< service ID */

    camera_service_context_state_t state; /**< context state */

    struct camera_sp_t* sp;               /**< the SP owner of this context */
    kal_uint32 num_streams;
    camera_stream_info_t streams[2];      /**< media streams output from demux */

    kal_uint32 start_time;              /**< the start time (for bitrate calculation) */
    kal_uint32 freq;                     /**< service ID */
    kal_wchar signal_status_text[64];
} camera_service_context_t;

/**
  * Camera service provider state.
  */
typedef enum
{
    CAMERA_SP_STATE_CLOSED,
    CAMERA_SP_STATE_OPENED,
    CAMERA_SP_STATE_SCANNING
} camera_sp_state_t;

typedef struct camera_sp_t camera_sp_t;
/**
  * Camera service provider
  */
struct camera_sp_t
{
    mtv_spi_t itf;
    mtv_spi_client_t* client;

    mtv_result_t (*on_scan_progress_ind)(camera_sp_t* self, media_camera_scan_progress_ind_struct* param);
    mtv_result_t (*on_event)(camera_sp_t* self, media_camera_event_ind_struct* ind);

    camera_sp_state_t state;

    //camera_demod_t* demod;
    //camera_demod_client_t demod_client;



    camera_service_context_t services[1];

    mtv_freq_band_t band_to_scan;
    kal_uint32 scan_progress;
    kal_bool scan_aborted;

    const kal_wchar* db_dir;
    kal_wchar signal_status_text[64];
};

#endif /* _CAMERA_SP_H */

