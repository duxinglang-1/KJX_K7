/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vfx_adp_sse.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  SSE (Screen switch effect) Adapatation Layer 
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

#ifndef __VFX_ADP_SSE_H__
#define __VFX_ADP_SSE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For basic types
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"

/***************************************************************************** 
 * Type
 *****************************************************************************/

/* Screen transit type, may vary for different project */
typedef enum
{
    VFX_SCR_TRANSIT_TYPE_DEFAULT = 0,
    VFX_SCR_TRANSIT_TYPE_NONE,

    // System transit types start here
    VFX_SCR_TRANSIT_TYPE_APP,
    VFX_SCR_TRANSIT_TYPE_SCR,
    VFX_SCR_TRANSIT_TYPE_CUI,

    // App transit types start here
    VFX_SCR_TRANSIT_TYPE_LOCK,
#if defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__)  &&  (defined(__COSMOS_3D_V10__) || defined(__PLUTO_3D_V10__))
    VFX_SCR_TRANSIT_TYPE_3D_BLIND,
    VFX_SCR_TRANSIT_TYPE_3D_CIRCLE,
    VFX_SCR_TRANSIT_TYPE_3D_CUBE,
    VFX_SCR_TRANSIT_TYPE_3D_BRICK,
    VFX_SCR_TRANSIT_TYPE_3D_TWIST,
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__) &&  (defined(__COSMOS_3D_V10__) || defined(__PLUTO_3D_V10__) */
    VFX_SCR_TRANSIT_TYPE_END_OF_ENUM

} VfxScrTransitTypeEnum;

#define VFX_SCR_TRANSIT_PRIORITY_SCR        0
#define VFX_SCR_TRANSIT_PRIORITY_APP        5
#define VFX_SCR_TRANSIT_PRIORITY_HOME       6
#define VFX_SCR_TRANSIT_PRIORITY_SMALL_SCR  10
#define VFX_SCR_TRANSIT_PRIORITY_USER       15
typedef VfxU32 VfxScrTransitPriority;

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

extern void vfx_adp_sse_setup_transit(VfxScrTransitTypeEnum type, VfxBool in, VfxScrTransitPriority priority);

extern void vfx_adp_sse_commit();

#endif /* __VFX_ADP_SSE_H__ */

