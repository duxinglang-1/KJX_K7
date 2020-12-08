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
 *  vfx_mc_trace.h
 *
 * Project:
 * --------
 *  Venus FW
 *
 * Description:
 * ------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_MC_TRACE_H__
#define __VFX_MC_TRACE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "kal_trace.h"
#include "trc\vadp_sys_trc.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

#if !defined(__MTK_TARGET__)
/* MoDIS */
#define VFX_MC_TRACE0(g, tr, f)                     vfx_mc_trace(g, f)
#define VFX_MC_TRACE1(g, tr, f, a1)                 vfx_mc_trace(g, f, a1)
#define VFX_MC_TRACE2(g, tr, f, a1, a2)             vfx_mc_trace(g, f, a1, a2)
#define VFX_MC_TRACE3(g, tr, f, a1, a2, a3)         vfx_mc_trace(g, f, a1, a2, a3)
#define VFX_MC_TRACE4(g, tr, f, a1, a2, a3, a4)     vfx_mc_trace(g, f, a1, a2, a3, a4)
#define VFX_MC_TRACE5(g, tr, f, a1, a2, a3, a4, a5) vfx_mc_trace(g, f, a1, a2, a3, a4, a5)
#else
/* Target */
#define VFX_MC_TRACE0(g, tr, f)                     kal_trace(g, tr)
#define VFX_MC_TRACE1(g, tr, f, a1)                 kal_trace(g, tr, a1)
#define VFX_MC_TRACE2(g, tr, f, a1, a2)             kal_trace(g, tr, a1, a2)
#define VFX_MC_TRACE3(g, tr, f, a1, a2, a3)         kal_trace(g, tr, a1, a2, a3)
#define VFX_MC_TRACE4(g, tr, f, a1, a2, a3, a4)     kal_trace(g, tr, a1, a2, a3, a4)
#define VFX_MC_TRACE5(g, tr, f, a1, a2, a3, a4, a5) kal_trace(g, tr, a1, a2, a3, a4, a5)
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/

#if !defined(__MTK_TARGET__)
void    vfx_mc_trace(trace_class_enum g, VfxChar* format, ...);
#endif

#endif /* __VFX_MC_TRACE_H__ */
