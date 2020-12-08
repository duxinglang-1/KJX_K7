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
 *  vapp_v2p_hs_widget_dualclock.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions of dual clock widget from Venus MMI to PlutoMMI.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VADP_V2P_WIDGET_DUALCLOCK_H__
#define __VADP_V2P_WIDGET_DUALCLOCK_H__

#include "MMI_features.h"

#if defined(__MMI_VUI_HOMESCREEN_CLOCK__) || defined(__MMI_VUI_HOMESCREEN_DUALCLOCK__)
#include "vfx_datatype.h"
#ifdef __cplusplus
extern "C"
{
#endif


/**********************************************************************
 * External Interfaces
 **********************************************************************/
extern void vadp_v2p_hs_clock_read_nvram(void);
extern void vadp_v2p_hs_clock_save_nvram(void);
extern U32 vadp_v2p_hs_clock_get_type(void);
extern U32 vadp_v2p_hs_clock_get_style(void);


extern VfxWChar* vadp_v2p_hs_dualclock_get_home_name(void);
extern VfxWChar* vadp_v2p_hs_dualclock_get_name(void);
extern void vadp_v2p_hs_dualclock_get_time(VfxU32 *hour, VfxU32 *mins, VfxU32 *secs);
extern void vadp_v2p_hs_dualclock_entry_setting(void);


extern  void vadp_v2p_hs_clock_entry_setting(void);


#define VADP_V2P_HS_CLOCK_TYPE_COUNT 3
#define VADP_V2P_HS_CLOCK_STYLE_COUNT 3

typedef struct
{
    U8 *type_option[VADP_V2P_HS_CLOCK_TYPE_COUNT];
    U8 *style_option[VADP_V2P_HS_CLOCK_STYLE_COUNT];
} vadp_v2p_hs_clock_setting_struct;



#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif /* __MMI_VUI_HOMESCREEN_CLOCK__ */
#endif /* __VADP_V2P_WIDGET_DUALCLOCK_H__ */

