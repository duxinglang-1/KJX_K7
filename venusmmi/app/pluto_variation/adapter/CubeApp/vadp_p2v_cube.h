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
 *  vadp_p2v_cube.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions from the Pluto MMI to the Venus
 *  MMI.
 *
 *      Pluto APP ---> p2v adaptor ---> Venus APP
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VADP_P2V_CUBE_H__
#define __VADP_P2V_CUBE_H__

#ifdef __cplusplus
extern "C"
{
#endif

/* Pluto MMI headers: */
#include "MMIDataType.h"

/* Venus MMI headers: */
#include "ui_core\base\vfx_base.h"

#include "CubeAppProt.h"
#include "kal_general_types.h"

/**********************************************************************
 * Enumeration definition:
 **********************************************************************/

/**********************************************************************
 * Structure Definitions:
 **********************************************************************/


/**********************************************************************
 * External Interfaces:
 **********************************************************************/
extern void vadp_p2v_cube_vapp_init(MMI_BOOL cube_effect);
extern void vadp_p2v_cube_vapp_deinit(void);
extern MMI_BOOL vadp_p2v_cube_vapp_is_small(void);
extern void vadp_p2v_cube_vapp_set_small_mode(void);
extern void vadp_p2v_cube_vapp_set_effect(MMI_BOOL enable);
extern MMI_BOOL vadp_p2v_cube_vapp_get_effect(void);
extern void vadp_p2v_cube_vapp_set_free_mode(MMI_BOOL enable);
extern void vadp_p2v_cube_vapp_set_action(mmi_cube_vapp_dir_enum action);
extern S8 vadp_p2v_cube_vapp_get_cur_scr_idx(U8 *idx);
extern void vadp_p2v_cube_vapp_fold_all_by_buffer(void);
extern void vadp_p2v_cube_vapp_fold_all(void);
extern MMI_BOOL vadp_p2v_cube_vapp_is_fold(void);
extern MMI_BOOL vadp_p2v_cube_vapp_is_active(void);

#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif /* __VADP_P2V_CUBE_H__ */

