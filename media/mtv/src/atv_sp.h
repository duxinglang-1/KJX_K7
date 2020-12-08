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
 *   atv_sp.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _ATV_SP_H
#define _ATV_SP_H

#ifndef _MTV_SPI_H
#include "mtv_spi.h"
#endif

#ifndef _MED_STRUCT_H
#include "med_struct.h"
#endif

typedef enum
{
    ATV_SERVICE_STOPPED,       /**< the service is stopped */
    ATV_SERVICE_STARTED,       /**< the service is started but not ready to run */
    ATV_SERVICE_READY          /**< the service is ready to run */
} atv_service_context_state_t;

/**
  * ATV service context. This struct contains runtime information about a started service.
  */
typedef struct
{
    kal_uint32 sid;                     /**< service ID */
    atv_service_context_state_t state; /**< context state */
    kal_uint32 freq;                     /**< service ID */

} atv_service_context_t;

/**
  * ATV service provider state.
  */
typedef enum
{
    ATV_SP_STATE_CLOSED,
    ATV_SP_STATE_OPENED,
    ATV_SP_STATE_SCANNING
} atv_sp_state_t;

typedef struct atv_sp_t atv_sp_t;
/**
  * ATV service provider
  */
struct atv_sp_t
{
    mtv_spi_t itf;
    mtv_spi_client_t* client;

    mtv_result_t (*on_scan_progress_ind)(atv_sp_t* self, media_atv_scan_progress_ind_struct* param);
    mtv_result_t (*on_event)(atv_sp_t* self, media_atv_event_ind_struct* ind);

    atv_sp_state_t state;

    atv_service_context_t curr_srv;

    mtv_freq_band_t band_to_scan;
    kal_uint32 scan_progress;
    kal_bool scan_aborted;
    kal_bool service_paused;
    kal_uint32 last_signal_strength;
    kal_uint32 selected_audio_mode;

    const kal_wchar* db_dir;
};

#endif /* _ATV_SP_H */

