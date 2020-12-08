/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*******************************************************************************
 * Filename:
 * ---------
 *  vadp_v2p_media_player.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  .
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
 
#include "MMI_features.h"
#ifdef __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__

#ifndef __VADP_V2P_IMAGEFLOW_H__
#define __VADP_V2P_IMAGEFLOW_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "ui_core\base\vfx_datatype.h"
#include "PlstSrvGprot.h"
//#ifdef MOTION_SENSOR_SUPPORT
//#include "mdi_motion.h"
//#include "sensorSrvGport.h"
//#endif
#include "MMIDataType.h"

#define VAPP_IMGFLOW_MAX_CELL_NUM       9
#define VAPP_IMGFLOW_CACHE_NUMBER       15
#define SRV_CACHE_RUN_BUF_SIZE_MIN      (SRV_MEDIACACHE_RUN_BUF_SIZE(VAPP_IMGFLOW_CACHE_NUMBER)) 
#define SRV_CACHE_BIG_IMAGE_CACHE       SRV_PLST_ARTWORK_RESIZED_WIDTH*SRV_PLST_ARTWORK_RESIZED_HEIGHT*2


//If there are bad performace in reflected shadow on low-end chip, such as MT6253, can define 
//VAPP_IMAGE_FLOW_REFLECTED_ENABLE to 1 to get a acceptable performance
#define VAPP_IMAGE_FLOW_REFLECTED_ENABLE  (0)


#define __IMGFLOW_USE_GDI_BACKGROUND_DECODE__

#define IMGFLOW_TRACE0(exp)             MMI_TRACE(MMI_MEDIA_TRC_G2_APP, exp)
#define IMGFLOW_TRACE1(exp, a1)         MMI_TRACE(MMI_MEDIA_TRC_G2_APP, exp, a1)
#define IMGFLOW_TRACE2(exp, a1, a2)     MMI_TRACE(MMI_MEDIA_TRC_G2_APP, exp, a1, a2)
#define IMGFLOW_TRACE3(exp, a1, a2, a3) MMI_TRACE(MMI_MEDIA_TRC_G2_APP, exp, a1, a2, a3)


typedef enum
{
    VAPP_IMGFLOW_STATE_NULL = 0,
    VAPP_IMGFLOW_STATE_INITED,
    VAPP_IMGFLOW_STATE_READY,
    VAPP_IMGFLOW_STATE_LOADING,  //waiting callback from PLS service to get image
    VAPP_IMGFLOW_STATE_DECODING, //waiting callbckk from GDI to decode image
    VAPP_IMGFLOW_STATE_PAUSE,    //image flow pause, in track list view state
    VAPP_IMGFLOW_STATE_SKIP,     //cancel current image, get next one directly.    

    VAPP_IMGFLOW_STATE_END

} vapp_imgflow_state_enum;

typedef enum
{
    /*OK*/
    VAPP_IMGFLOW_ERR_NONE = 0,
    /* Error Types*/
    VAPP_IMGFLOW_ERR_LISTSRV_INVALID = -500,
    VAPP_IMGFLOW_ERR_LIST_INVALID,
    VAPP_IMGFLOW_ERR_NO_MEMORY,
    VAPP_IMGFLOW_ERR_CACHESRV_INVALID,
    VAPP_IMGFLOW_ERR_CACHESRV_START_FAIL,
    VAPP_IMGFLOW_ERR_PLST_QUERY_FAIL,
    VAPP_IMGFLOW_ERR_PLAY_FAIL,
    VAPP_IMGFLOW_ERR_NO_VALID_COVER,
    VAPP_IMGFLOW_ERR_PARA,

    VAPP_IMGFLOW_ERR_END
} vapp_imgflow_error_enum;


typedef enum
{
    /*OK*/
    VAPP_IMGFLOW_TYPE_NONE = 0,
    VAPP_IMGFLOW_INFO_TITLE,
    VAPP_IMGFLOW_INFO_ARTIST,

    VAPP_IMGFLOW_INFO_END
} vapp_imgflow_album_info_enum;


typedef struct
{
    /* base background image */
    U16 bg_img_id;
    /* image cp */
    S32 cp_x, cp_y, cp_w, cp_h; 
    S32 cp_angle, cp_upshift, cp_focus_upshift;

    S32 cell_focus_w, cell_focus_h;
    S32 cell_second_w;
    S32 cell_other_w, cell_other_h;
    /* sk + title*/
    U16 lsk_img_id;
    S32 lsk_x, lsk_y, lsk_w, lsk_h;
    U16 rsk_img_id;
    S32 rsk_x, rsk_y, rsk_w, rsk_h;
    S32 title_x, title_y, title_w, title_h;
    S32 artist_x, artist_y, artist_w, artist_h;
    /* high light*/
    U16 hl_img_id;
    S32 hl_w, hl_h;

}vapp_imgflow_skin_struct;

extern vapp_imgflow_skin_struct g_image_flow_skin_layout;


/* Extern declerations */
extern VfxS32 vadp_v2p_imgflow_init(void);
extern VfxS32 vadp_v2p_imgflow_deinit(void);
extern VfxS32 vadp_v2p_imgflow_run(void);
extern VfxS32 vadp_v2p_imgflow_stop(void);
//#ifdef MOTION_SENSOR_SUPPORT
//extern void vadp_v2p_imgflow_tilt_hdlr(mdi_motion_angle_enum direction,
//                                       mdi_motion_action_enum action,
//                                       mdi_motion_tilt_detail_struct *detail,
//                                       void *user_data);
//#endif /* MOTION_SENSOR_SUPPORT */
extern void vadp_v2p_imgflow_reg_callback(void* user_data, void(*callback)(void* user_data, VfxS32 index));
extern void vadp_v2p_imgflow_unreg_callback(void);
extern VfxS32 vadp_v2p_imgflow_listsrv_callback(srv_plst_cb_evt_enum cb_event, S32 result, U32 ca_para_2);
extern VfxS32 vadp_v2p_imgflow_get_focus_index(void);
extern VfxS32 vadp_v2p_imgflow_set_focus_index(VfxS32 index);
extern VfxS32 vadp_v2p_imgflow_get_album_number(void);
extern VfxS32 vadp_v2p_imgflow_get_album_info(VfxS32 index, vapp_imgflow_album_info_enum type, VfxWChar* str);
extern VfxU8* vadp_v2p_imgflow_get_def_cover(void);
extern VfxS32 vadp_v2p_imgflow_get_album_cover(VfxS32 index, VfxU8* buf, VfxS32 flag);
extern VfxS32 vadp_v2p_imgflow_play_album(VfxS32 index);
extern void vadp_v2p_imgflow_cachesrv_pause(void);
extern void vadp_v2p_imgflow_cachesrv_resume(void);
//extern VfxS32 vadp_v2p_imgflow_lock_image_buffer(S32 index, void** buffer);
extern VfxS32 vadp_v2p_imgflow_lock_image_buffer(S32 index, void** buffer, S32* w, S32* h);
extern void vadp_v2p_imgflow_unlock_image_buffer(S32 index, void* buffer);
extern VfxS32 vadp_v2p_imgflow_popup_error(MMI_ID parent_id, S32 error_id);

#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif /* __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__ */
#endif /* __VADP_V2P_IMAGEFLOW_H__ */

