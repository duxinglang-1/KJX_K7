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
 *  vapp_soundrecorder_util.h
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_SOUNDRECORDER_UTIL_H__
#define __VAPP_SOUNDRECORDER_UTIL_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif
#include "mdi_audio.h"
#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MDI_CACHE_SIZE 2*1024

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif
extern mdi_result vadp_soundrec_rec_start(VfxWChar *fullpath, void *user_data, VfxU32 size_limit, VfxU32 time_limit, VfxBool use_default_quality, VfxU8 quality);
extern mdi_result vadp_soundrec_rec_pause(void *user_data);
extern mdi_result vadp_soundrec_rec_resume(void *user_data);
extern mdi_result vadp_soundrec_rec_stop(void);

extern mdi_result vadp_soundrec_open(void *user_data, const VfxWChar *full_path);
extern mdi_result vadp_soundrec_play(void);
extern mdi_result vadp_soundrec_pause(void);
extern mdi_result vadp_soundrec_resume(void);
extern mdi_result vadp_soundrec_stop(void);
extern mdi_result vadp_soundrec_close(void *user_data);
extern void vadp_soundrec_seekStop(void);
extern void vadp_soundrec_seekcallback(kal_uint8 result, void* user_data);
extern VfxBool vadp_soundrec_is_playing(void);

extern VfxBool vadp_soundrec_get_current_time(VfxU32 *current_time);
extern void vadp_soundrec_set_current_time(VfxU32 current_time);

extern void vadp_soundrec_util_filter_set(FMGR_FILTER *filter);
extern VfxWString& vapp_soundrec_util_get_format_time(VfxWString &string, VfxU64 display_time);

extern S32 vapp_soundrec_util_check_record_folder(void);
extern VfxBool vapp_soundrec_util_get_record_file_path(VfxU16 start_index, VfxU16 stop_index, VfxU16 *result_index, VfxWChar *filepath, VfxU16 buffer_size, VfxBool default_quality, VfxU8 quality);
extern vapp_soundrec_check_size_result vapp_soundrec_util_get_record_drv_free_space(void);
#ifdef __cplusplus
}
#endif


#endif /* __VAPP_SOUNDRECORDER_UTIL_H__ */

