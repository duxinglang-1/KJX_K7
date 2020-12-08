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
 *  vapp_hs_widget_memo.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: Memo
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_MEMO__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_hs_widget_memo.h"

#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_primitive_frame.h"
#include "mmi_rp_app_venus_homescreen_wg_memo_def.h"
#include "vcp_pluto_control.h"
#include "vfx_basic_type.h"
#include "vfx_string.h"
#include "vadp_v2p_hs_widget_memo.h"

/***************************************************************************** 
 * Home screen widget: Memo
 *****************************************************************************/

VappHsWidgetMemo::VappHsWidgetMemo() :
    m_imageBg(NULL),
    m_text(NULL)
{
}


void VappHsWidgetMemo::onCreateView()
{
    // background image
    VFX_OBJ_CREATE(m_imageBg, VfxImageFrame, this);
    m_imageBg->setResId(VAPP_HS_IMG_WG_MEMO_BG);
#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    m_imageBg->setIsOpaque(VFX_TRUE);
    setIsOpaque(VFX_TRUE);
#endif /* defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */
    setIsCached(VFX_FALSE);

#if defined(__MMI_FTE_SUPPORT_SLIM__)
    m_imageBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_imageBg->setSize(BG_WIDTH, BG_HEIGHT);
#endif /* defined(__MMI_FTE_SUPPORT_SLIM__) */

    setBounds(m_imageBg->getBounds());

    // setting text
    VFX_OBJ_CREATE(m_text, VfxTextFrame, this);
    m_text->setPos(VfxPoint(TEXT_X_OFFSET, TEXT_Y_OFFSET));
    m_text->setBounds(VfxRect(0, 0, TEXT_WIDTH, TEXT_HEIGHT));
    m_text->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
    m_text->setAutoResized(VFX_FALSE);
    m_text->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_text->setString(VFX_WSTR_MEM(vadp_v2p_hs_memo_get_text()));
    m_text->setColor(VfxColor(93, 29, 7, 18));
}


void VappHsWidgetMemo::onReleaseView()
{
    VFX_OBJ_CLOSE(m_text);
    VFX_OBJ_CLOSE(m_imageBg);
}
#endif /* __MMI_VUI_HOMESCREEN_MEMO__ */

