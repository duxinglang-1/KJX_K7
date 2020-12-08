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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_widget_baidu_search.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the baidu search widget.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_WIDGET_BAIDU_SEARCH__
/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_widget_def.h"
#include "vapp_widget_native_factory.h"
#include "vapp_widget_baidu_search.h"
#include "vcp_include.h"
#include "Vapp_baidu_search.h"
#include "mmi_rp_vapp_baidu_search_def.h"

extern "C"
{
#include "browser_api.h"
}


/*****************************************************************************
 * Baidu Search Widget
 *****************************************************************************/

VAPP_WIDGET_SYS_PUBLISH_NATIVE(
    VappWidgetBaiduSearch,
    VAPP_WIDGET_TYPE_BAIDU_SEARCH,
    VappWidgetBaiduSearchPublisher);

VAPP_WIDGET_IMPLEMENT_CLASS(VappWidgetBaiduSearch, VappWidgetSearchEditor);

VappWidgetBaiduSearch::VappWidgetBaiduSearch()
{
    // Do nothing.
}


VappWidgetId VappWidgetBaiduSearch::getId() const
{
    return VappWidgetId(VAPP_WIDGET_SRC_NATIVE,VAPP_WIDGET_TYPE_BAIDU_SEARCH);
}


VfxSize VappWidgetBaiduSearch::getMaxSize() const
{
    return VfxSize(MAX_SIZE_WIDTH, MAX_SIZE_HEIGHT);
}


VfxS32 VappWidgetBaiduSearch::getName(VfxWChar *string, VfxS32 size) const
{
	const VfxWChar *name = vfxSysResGetStr(STR_ID_VAPP_WIDGET_BAIDU_NAME);

    VFX_ASSERT(string && size > 0);
    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)name, size - 1);

    return vfx_sys_wcslen((const VfxWChar *)string);
}


VfxFrame *VappWidgetBaiduSearch::createIcon(VfxObject *parentObj)
{
    VfxFrame *icon;

    VFX_OBJ_CREATE(icon, VfxFrame, parentObj);
    icon->setBounds(VfxRect(0, 0, BAIDU_WIDGET_ICON_SIZE, BAIDU_WIDGET_ICON_SIZE));
	icon->setImgContent(VfxImageSrc(IMG_ID_VAPP_BAIDU_ICON));
	
    return icon;
}


void VappWidgetBaiduSearch::onCreateView()
{
    VappWidgetSearchEditor::onCreateView();
	VappWidgetSearchEditor::setWidgetImage(IMG_ID_VAPP_BAIDU_SEARCH_WIDGET_SEARCH_BAR_BG);
	VappWidgetSearchEditor::setWidgetHint(STR_ID_BAIDU_HINT);
	
	VfxImageSrc iconImage((VfxResId)IMG_ID_VAPP_BAIDU_ICON);
	
	VFX_OBJ_CREATE(m_iconFrame, VfxFrame, this);	
	m_iconFrame->setPos(BAIDU_SEARCH_WIDET_ICON_POS_X,BAIDU_SEARCH_WIDET_ICON_POS_Y);
	m_iconFrame->setImgContent(iconImage);
	m_iconFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	m_iconFrame->setBounds(0,0,iconImage.getSize().width,iconImage.getSize().height); //100
	m_iconFrame->setIsUnhittable(VFX_TRUE);
}


void VappWidgetBaiduSearch::onReleaseView()
{
	VFX_OBJ_CLOSE(m_iconFrame);
    VappWidgetSearchEditor::onReleaseView();
}


void VappWidgetBaiduSearch::setOnWidgetClick()
{
    vapp_baidu_search_launch();
}

#endif /*__MMI_VUI_WIDGET_BAIDU_SEARCH__*/
