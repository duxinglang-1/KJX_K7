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
 *  vadp_v2p_cube.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions from the Venus MMI to the Pluto
 *  MMI.
 *
 *      Venus APP ---> v2p adaptor ---> Pluto APP
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VADP_V2P_CUBE_H__
#define __VADP_V2P_CUBE_H__

#include "MMI_Features.h"
#include "vfx_datatype.h"

#ifdef __cplusplus
extern "C"
{
#endif


/**********************************************************************
 * Structure Definitions
 **********************************************************************/

/**********************************************************************
 * External Interfaces
 **********************************************************************/

extern void vadp_v2p_cube_vapp_set_screen_effect_transition(VfxS8 enable);
extern VfxS8 vadp_v2p_cube_vapp_get_screen_effect_transition(void);
extern void vadp_v2p_cube_vapp_set_down_pos(VfxS32 x, VfxS32 y);
extern void vadp_v2p_cube_vapp_get_down_pos(VfxS32 *x, VfxS32 *y);
extern VfxS8 vadp_v2p_cube_vapp_is_cur_scr_snapshot_existed(VfxU8 cur_idx, VfxU8 encoded, VfxU8 public_drv);
extern void vadp_v2p_cube_vapp_save_cur_layer_to_buffer(VfxU8 cur_idx);
extern VfxU8 *vadp_v2p_cube_vapp_get_cube_layer_buf(VfxU32 cube_layer_idx, 
                                                    VfxS32 *width, VfxS32 *height);

extern VfxS8 vadp_v2p_cube_vapp_save_cur_scr_snapshot(VfxU8 cur_idx);
extern VfxS8 vadp_v2p_cube_vapp_save_cur_layer_buf_to_file(VfxU8 scr_idx);
extern VfxU8 *vadp_v2p_cube_vapp_get_layer_buf_from_file(VfxU8 scr_idx, VfxS32 *width, VfxS32 *height);
extern void vadp_v2p_cube_vapp_save_cur_layer(void);
extern void vadp_v2p_cube_vapp_free_layer(void);
extern VfxS8 vadp_v2p_cube_vapp_is_in_transition(void);
extern VfxS8 vadp_v2p_cube_vapp_get_cur_active_drv(VfxU8 public_drv);
extern VfxS32 vadp_v2p_cube_vapp_create_app_dir(VfxU8 public_drv);

#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif /* __VADP_V2P_CUBE_H__ */

