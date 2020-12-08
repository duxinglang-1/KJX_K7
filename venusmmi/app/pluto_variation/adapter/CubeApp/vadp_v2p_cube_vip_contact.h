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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VADP_V2P_CUBE_VIP_CONTACT_H__
#define __VADP_V2P_CUBE_VIP_CONTACT_H__

#include "MMI_Features.h"

#ifdef __MMI_VUI_3D_CUBE_APP__

/* Venus MMI headers: */
#include "ui_core\base\vfx_base.h"

#ifdef __cplusplus
extern "C"
{
#endif
extern VfxS8 vadp_v2p_contact_is_available(void);
extern VfxS8 vadp_v2p_vip_contact_is_nwk_available(void);
extern VfxS8 vadp_v2p_vip_contact_is_sms_available(void);

extern void vadp_v2p_vip_contact_load_setting(void);
extern void vadp_v2p_vip_contact_save_setting(void);
extern void* vadp_v2p_vip_contact_get_setting(void);
extern VfxS8 vadp_v2p_vip_contact_get_image_id(VfxU16 store_index, VfxS32 *image);
extern VfxS8 vadp_v2p_vip_contact_get_image_path(VfxU16 store_index,
                                                            VfxWChar *buffer,
                                                            VfxU16 len);
extern void vadp_v2p_vip_contact_get_name(VfxU16 store_index, 
                                                    VfxWChar *buffer,
                                                    VfxU16 len);
extern VfxS8 vadp_v2p_vip_contact_get_number(VfxWChar *buffer, 
                                                      VfxU16 length, 
                                                      VfxU16 store_index, 
                                                      VfxU32 flag);
extern VfxS32 vadp_v2p_vip_contact_get_number_res(const VfxU32 flag);
extern void vadp_v2p_vip_contact_send_sms(const VfxWChar *number);
extern void vadp_v2p_vip_contact_make_call(const VfxWChar *number,
                                                     VfxU32 flag,
                                                     VfxU16 store_index);
extern void vadp_v2p_vip_contact_select_contact(VfxU16 index);

extern VfxU16 vadp_v2p_vip_contact_get_index(VfxU16 index);
extern void vadp_v2p_vip_contact_clear_index(VfxU16 index);


#define CONTACT_NUMBER_MASK_HOME   0x0001
#define CONTACT_NUMBER_MASK_OFFICE 0x0010
#define CONTACT_NUMBER_MASK_MOBILE 0x0100
#define CONTACT_NUMBER_MASK_FAX    0x1000

#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif /* __MMI_VUI_3D_CUBE_APP__ */

#endif /* __VADP_V2P_CUBE_VIP_CONTACT_H__ */

