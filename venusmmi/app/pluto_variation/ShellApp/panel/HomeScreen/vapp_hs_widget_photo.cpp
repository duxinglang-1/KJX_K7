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
 *  vapp_hs_widget_photo.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: photo album
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
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_VUI_HOMESCREEN_PHOTO__
#include "vapp_hs_widget_photo.h"
#include "vadp_v2p_widget_photo.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_datatype.h"
#include "vfx_primitive_frame.h"
#include "vfx_input_event.h"
#include "vfx_basic_type.h"
#include "vfx_signal.h"
#include "vfx_string.h"
#include "vapp_hs_widget_base.h"
#include "mmi_rp_app_venus_homescreen_wg_photo_def.h"
#include "vfx_draw_context.h"
#include "vfx_text_frame.h"
#include "vrt_datatype.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "USBDeviceGprot.h"
#ifdef __cplusplus
#include "MMIDataType.h"
}
#endif

/*****************************************************************************
 * Class VappHsWidgetPhotoButton
 *****************************************************************************/
VFX_IMPLEMENT_CLASS(VAPP_HS_PHOTO_BUTTON_CLASS_NAME, VappHsWidgetPhotoButton, VfxControl);


VappHsWidgetPhotoButton::VappHsWidgetPhotoButton() : m_image(NULL)
{
}


VappHsWidgetPhotoButton::~VappHsWidgetPhotoButton()
{

}

void VappHsWidgetPhotoButton::onInit(void)
{
    VfxControl::onInit();

    VFX_OBJ_CREATE(m_image, VfxImageFrame, this);
}


void VappHsWidgetPhotoButton::onDeinit(void)
{
    VfxControl::onDeinit();
}


void VappHsWidgetPhotoButton::setImage(VfxS32 upImage,VfxS32 downImage)
{
    m_imageUpId= upImage;
    m_imageDownId = downImage;

    m_image->setResId(upImage);
    setBounds(m_image->getBounds());
}


void VappHsWidgetPhotoButton::setDisplay(VfxBool isDisplay)
{
    if (isDisplay)
    {
        setHidden(VFX_FALSE);
    }
    else
    {
        setHidden(VFX_TRUE);
    }
}


VfxBool VappHsWidgetPhotoButton::onPenInput(VfxPenEvent &event)
{
    setOpacity(1);
    VfxPoint pos(event.getRelPos(this));

    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        m_image->setResId(m_imageDownId);
        m_eventPenDown.emit(event);
        return VFX_TRUE;
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        m_image->setResId(m_imageUpId);
        if (containPoint(pos))
        {
            m_eventPenUp.emit(event);
        }
        else
        {
            setOpacity(0);
            setHidden(VFX_TRUE);
        }
        return VFX_TRUE;
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        if (containPoint(pos))
        {
            m_image->setResId(m_imageDownId);
            setOpacity(1);
            setHidden(VFX_FALSE);
        }
        else
        {
            m_image->setResId(m_imageUpId);
            if (getOpacity() == 1)
            {
                setOpacity(0);
            }
        }
        return VFX_TRUE;
    }

    return VfxControl::onPenInput(event);

}


/*****************************************************************************
 * Class VappHsWidgetPhoto
 *****************************************************************************/
VappHsWidgetPhoto::VappHsWidgetPhoto() :
    m_image(NULL),
    m_strFilename(VFX_WSTR_NULL)
{
}


void VappHsWidgetPhoto::onInit()
{
    VappHsWidget::onInit();

#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    setIsOpaque(VFX_TRUE);
#endif

    setBounds(VfxRect(0, 0, MAX_WIDTH, MAX_HEIGHT));

    m_strFilename = VFX_WSTR_MEM((const U16*)vadp_v2p_photo_get_transcode_image_path());
}


VfxBool VappHsWidgetPhoto::onPenInput(VfxPenEvent &event)
{
    return VappHsWidget::onPenInput(event);
}


void VappHsWidgetPhoto::onDirectLaunch()
{
    vfxPostInvoke0(this, &VappHsWidgetPhoto::launchApp);
}


void VappHsWidgetPhoto::launchApp()
{
    vadp_v2p_photo_launch_filemanager();
}


void VappHsWidgetPhoto::onDraw(VfxDrawContext &dc)
{
    VfxS32 top_width,top_height;
    VfxS32 bottom_l_width,bottom_l_height;
    VfxS32 bottom_r_width,bottom_r_height;
    VfxS32 left_width,left_height;
    VfxS32 right_width,right_height;
    VfxS32 bounds_width,bounds_height;
    VfxS32 image_bg_width, image_bg_height;
    VfxImageSrc image_bg(VAPP_HS_IMG_WG_PHOTO_BG);
    VfxSize image_bg_size = image_bg.getSize();

    bounds_width = getBounds().getWidth();
    bounds_height = getBounds().getHeight();

    top_width = bounds_width - BORDER_W_RIGHT;
    top_height = BORDER_H_TOP;

    right_width = BORDER_W_RIGHT;
    right_height = bounds_height - BORDER_H_BOTTOM;

    bottom_l_width = bounds_width >> 1;
    bottom_l_height = BORDER_H_BOTTOM;

    bottom_r_width = bounds_width >> 1;
    bottom_r_height = BORDER_H_BOTTOM;

    left_width = BORDER_W_LEFT;
    left_height = bounds_height - BORDER_H_TOP - BORDER_H_BOTTOM;

    image_bg_width = image_bg_size.width;
    image_bg_height = image_bg_size.height;

    dc.setClip(VfxRect(0, 0, top_width, top_height));
    dc.drawImageFromRes(0, 0, VAPP_HS_IMG_WG_PHOTO_BG);

    dc.setClip(VfxRect(bounds_width - BORDER_W_RIGHT, 0, right_width, right_height));
    dc.drawImageFromRes(bounds_width - image_bg_width, 0, VAPP_HS_IMG_WG_PHOTO_BG);

    dc.setClip(VfxRect(0, BORDER_H_TOP, left_width, left_height));
    dc.drawImageFromRes(0, 0, VAPP_HS_IMG_WG_PHOTO_BG);

    dc.setClip(VfxRect(0, bounds_height - BORDER_H_BOTTOM, bottom_l_width, bottom_l_height));
    dc.drawImageFromRes(0, bounds_height - image_bg_height, VAPP_HS_IMG_WG_PHOTO_BG);

    dc.setClip(VfxRect(bounds_width >> 1, bounds_height - BORDER_H_BOTTOM, bottom_r_width, bottom_r_height));
    dc.drawImageFromRes(bounds_width - image_bg_width, bounds_height - image_bg_height, VAPP_HS_IMG_WG_PHOTO_BG);

    // TODO: Remove this later
    dc.setClip(VfxRect(0, 0, -1, -1));

}


VfxU16 VappHsWidgetPhoto::getIcon()
{
    return VAPP_HS_IMG_WG_ICON_PHOTO;
}


VfxU16 VappHsWidgetPhoto::getName()
{
    return VAPP_HS_STR_WG_PHOTO;
}


void VappHsWidgetPhoto::onCreateView()
{
    VfxS32 iw = MAX_WIDTH, ih = MAX_HEIGHT;
    VfxS8* file_p;

    VFX_OBJ_CREATE(m_image, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_strDefault, VfxTextFrame, this);

    // TODO: JPEG can't support PARGB layer. Therefore, set opaque to be ture for making to be RGB565 layer.
    m_image->setIsOpaque(VFX_TRUE);
    m_image->setBgColor(VFX_COLOR_GREY);

    file_p = (VfxS8*)vadp_v2p_photo_get_original_image_path();
    if (vadp_v2p_photo_is_cache_file_exist() > 0 &&
        file_p[0] != 0x00)
    {
        m_image->setSrc(m_strFilename);
        m_strDefault->setHidden(VFX_TRUE);
    }
    else
    {
        m_image->setResId(VAPP_HS_IMG_WG_PHOTO_DEFAULT);
        m_strDefault->setString(VFX_WSTR_RES(VAPP_HS_STR_PHOTO_ADD_PHOTO));
        m_strDefault->setFont(VFX_FONT_DESC_SMALL);
        m_strDefault->setHidden(VFX_FALSE);
        m_strDefault->setPos(VfxPoint(IMAGE_OFFSET_X + STR_OFFSET_X, IMAGE_OFFSET_Y + STR_OFFSET_Y));
        m_strDefault->setColor(VfxColor(255, 106, 106, 106));
        m_strDefault->setAutoResized(VFX_FALSE);
        m_strDefault->setBounds(VfxRect(
                                    0,
                                    0,
                                    DEFAULT_WIDTH,
                                    DEFAULT_HEIGHT - m_strDefault->getPos().y));
        m_strDefault->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    }

    iw = m_image->getBounds().getWidth();
    ih = m_image->getBounds().getHeight();
    m_image->setPos(VfxPoint(IMAGE_OFFSET_X, IMAGE_OFFSET_Y));

    setBounds(VfxRect(0, 0, iw + BORDER_W_LEFT + BORDER_W_RIGHT, ih + BORDER_H_TOP + BORDER_H_BOTTOM));

}


void VappHsWidgetPhoto::onReleaseView()
{
    VFX_OBJ_CLOSE(m_strDefault);
    VFX_OBJ_CLOSE(m_image);
}

#endif /* __MMI_VUI_HOMESCREEN_PHOTO__ */
