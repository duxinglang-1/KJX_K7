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
 *  vapp_v2p_hs_widget_baidu_search.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions of Baidu search widget from 
 *  Pluto MMI to Venus MMI.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VADP_V2P_WIDGET_BAIDU_SEARCH_H__
#define __VADP_V2P_WIDGET_BAIDU_SEARCH_H__

#include "MMI_features.h"
#ifdef __MMI_VUI_HOMESCREEN_BAIDU_SEARCH__

#ifdef __cplusplus
extern "C"
{
#endif

#include "MMIDataType.h"
#include "SearchWebBaiduProt.h"
#include "vfx_datatype.h"

/**********************************************************************
 * Define
 **********************************************************************/
typedef struct
{
    mmi_search_web_baidu_category_enum category;
    U16 category_icon;
    U16 category_text_icon_up;
    U16 category_text_icon_down;
} vadp_v2p_hs_baidu_search_category_struct;

/**********************************************************************
 * External Interfaces
 **********************************************************************/
extern VfxS32 vadp_v2p_hs_baidu_search_get_categories(
               VfxU32 count,
               mmi_search_web_baidu_category_enum* categories);

extern mmi_search_web_baidu_category_enum vadp_v2p_hs_baidu_search_get_current_category(void);

extern VfxResId vadp_v2p_hs_baidu_search_get_category_icon(
                 mmi_search_web_baidu_category_enum category);

extern void vadp_v2p_hs_baidu_search_get_category_string(
             mmi_search_web_baidu_category_enum category,
             VfxResId *up_icon,
             VfxResId *down_icon);

extern void vadp_v2p_hs_baidu_search_init_cntx(void);
extern void vadp_v2p_hs_baidu_search_release_cntx(void);
extern VfxWChar* vadp_v2p_hs_baidu_search_get_text(void);
extern void vadp_v2p_hs_baidu_search_launch_browser(
             mmi_search_web_baidu_category_enum category,
             VfxWChar* buffer);

extern void vadp_v2p_hs_baidu_search_set_default_category(
             mmi_search_web_baidu_category_enum category);
extern void vadp_v2p_hs_baidu_search_set_input_reserve(void);
extern void vadp_v2p_hs_baidu_search_reset_input_reserve(void);
extern VfxS32 vadp_v2p_hs_baidu_search_get_input_reserve(void);

#if !(defined(__MMI_QWERTY_KEYPAD_SUPPORT__))
extern void vadp_v2p_hs_baidu_search_start_edit(void);
#endif

#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif /* __MMI_VUI_HOMESCREEN_BAIDU_SEARCH__ */

#endif /* __VADP_V2P_WIDGET_BAIDU_SEARCH_H__ */
