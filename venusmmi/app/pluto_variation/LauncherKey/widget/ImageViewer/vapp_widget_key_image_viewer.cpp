/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vapp_widget_key_image_viewer.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_KEY_IMAGE_VIEWER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_widget_key_image_viewer.h"
#include "vapp_widget_native_factory.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "wgui.h"

#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * VappWidgetKeyImageViewer
 *****************************************************************************/

VAPP_WIDGET_SYS_PUBLISH_NATIVE(
    VappWidgetKeyImageViewer,
    VAPP_WIDGET_TYPE_KEY_IMAGE_VIEWER,
    VappWidgetKeyImageViewerPublisher);

VAPP_WIDGET_IMPLEMENT_CLASS(VappWidgetKeyImageViewer, VappWidget);

VappWidgetId VappWidgetKeyImageViewer::getId() const
{
	return VappWidgetId(VAPP_WIDGET_SRC_NATIVE, VAPP_WIDGET_TYPE_KEY_IMAGE_VIEWER);
}

VfxS32 VappWidgetKeyImageViewer::getName(VfxWChar * string,VfxS32 size) const
{
	const VfxWChar *name = vfxSysResGetStr(STR_ID_WIDGET_KEY_IMAGE_VIEWER_NAME);

    VFX_ASSERT(string && size > 0);
    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)name, size - 1);

    return vfx_sys_wcslen((const VfxWChar *)string);
}

VfxSize VappWidgetKeyImageViewer::getMaxSize() const
{
	return VfxSize(VIEW_PANEL_WIDTH, VIEW_PANEL_HEIGHT);
}

VfxFrame *VappWidgetKeyImageViewer::createIcon(VfxObject *parentObj)
{
    VfxImageFrame *icon;
    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);
	icon->setResId(IMG_ID_WIDGET_KEY_IMAGE_VIEWER_ICON);
	
    return icon;
}

void VappWidgetKeyImageViewer::onCreateView()
{
	VappWidget::onCreateView();
	
	VFX_OBJ_CREATE(m_viewer, VappWidgetKeyImageViewerPanel, this);
	m_viewer->setSize(VIEW_PANEL_WIDTH, VIEW_PANEL_HEIGHT);
	m_viewer->creatView();
}

void VappWidgetKeyImageViewer::onReleaseView()
{
	VFX_OBJ_CLOSE(m_viewer);
	
	VappWidget::onReleaseView();
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


#endif


