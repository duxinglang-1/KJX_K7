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
 *  vtst_rt_image_button.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Description
 * Screens for image button cp testing
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_config.h"

#if defined(__AFX_RT_TEST__)

#include "vcp_app_scr.h"
#include "vtst_rt_main.h"
#include "vcp_image_button.h"
#include "mmi_rp_srv_venus_component_button_def.h"

#include "vfx_datatype.h"
#include "vfx_text_frame.h"
#include "vfx_font_desc.h"
#include "vfx_object.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_app_cat_scr.h"
#include "vfx_string.h"
#include "kal_public_api.h"
#include "vrt_datatype.h"
#include "kal_general_types.h"
#include "vcp_state_image.h"
#include "vfx_image_src.h"
#include "vfx_basic_type.h"
#include "vfx_signal.h"

/***************************************************************************** 
 * Class VtstImgButton
 *****************************************************************************/

class VtstRtImgButtonScr : public VtstRtScr
{
// Constructor / Destructor
public:
    VtstRtImgButtonScr();

// Override
protected:
    virtual void onInit();
    virtual VfxS32 start();
    virtual VfxS32 phase(VfxS32 idx);
// Variable
private:
    VcpImageButton*   m_imgButton;
    VfxTextFrame*   m_text1;
    VfxTextFrame*   m_text2;
    VfxS32          m_clickCount;
    VfxFontDesc     m_font;

private:
    void onButtonClick(VfxObject *, VfxId);
};


VtstTestResultEnum vtst_rt_image_button(VfxU32 )
{
    VTST_START_SCRN(VtstRtImgButtonScr);
    return VTST_TR_OK;
}


VtstRtImgButtonScr::VtstRtImgButtonScr()
:m_clickCount(0)
{

}


VfxS32 VtstRtImgButtonScr::start()
{
    return 6; 
}


VfxS32 VtstRtImgButtonScr::phase(VfxS32 idx)
{
    VFX_UNUSED(idx);
    switch (idx)
    {
        case 0:
            m_text2->setString(VFX_WSTR("Basic"));
            break;

        case 1:
            m_imgButton->setIsHighlight(VFX_TRUE);
            m_text2->setString(VFX_WSTR("Highlight = TRUE"));

            break;

        case 2:
            m_text2->setString(VFX_WSTR("Highlight = TRUE, disabled = TRUE"));
            m_imgButton->setIsHighlight(VFX_FALSE);
            m_imgButton->setIsDisabled(VFX_TRUE);
            break;
        
        case 3:
            m_text2->setString(VFX_WSTR("Highlight = FALSE, disabled = TRUE"));
            m_imgButton->setIsHighlight(VFX_FALSE);
            m_imgButton->setIsDisabled(VFX_TRUE);
            break;

        case 4:
            m_text2->setString(VFX_WSTR("Effect off"));
            m_imgButton->setIsDisabled(VFX_FALSE);
            m_imgButton->setIsEffect(VFX_FALSE);
            break;

        case 5:
            m_text2->setString(VFX_WSTR("Stretch mode"));
            m_imgButton->setIsStretchMode(VFX_TRUE);
            m_imgButton->setIsEffect(VFX_TRUE);
            break;

        default:
            VFX_ASSERT(0);
    }
    confirm(VFX_WSTR("Does it work?"));
    return -1;
}


void VtstRtImgButtonScr::onInit()
{
    VcpStateImage     imgList;
    
    VcpImageButton    *imgButton2;
    VcpImageButton    *imgButton3;
    VcpImageButton    *imgButton4;
    VcpImageButton    *imgButton5;
    VcpImageButton    *imgButton6;
    VfxWString        tmpStr;

    VtstRtScr::onInit();
 
#ifdef __COSMOS_MMI__

#if 1
    imgList.setImage(
            VfxImageSrc(VCP_IMG_BUTTON_N),
            VfxImageSrc(VCP_IMG_BUTTON_P),
            VfxImageSrc(VCP_IMG_BUTTON_D),
            VfxImageSrc(VCP_IMG_BUTTON_H) );
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#else
    imgList.setImage(
            VfxImageSrc(VFX_WSTR("d:\\testIcon\\scroll_btn_up_n.png")),
            VfxImageSrc(VFX_WSTR("d:\\testIcon\\scroll_btn_up_p.png")),
            VfxImageSrc(VFX_WSTR("d:\\testIcon\\scroll_btn_down_n.png")),
            VfxImageSrc(VFX_WSTR("d:\\testIcon\\scroll_btn_down_p.png")));
#endif

    VFX_OBJ_CREATE(m_imgButton, VcpImageButton, this);

    VfxS32 buttonWidth = 53;
    VfxS32 buttonHeight = 54;
    VfxS32 xStart = 10;
    VfxS32 yStart = 30;
    VfxS32 xOffset = buttonWidth + 15;
    VfxS32 yOffset = buttonHeight + 15;

    m_imgButton->setImage(imgList);
    m_imgButton->setRect(VfxRect(xStart, yStart, buttonWidth, buttonHeight));
    m_imgButton->setIsStretchMode(VFX_TRUE);
    m_imgButton->m_signalClicked.connect(this, &VtstRtImgButtonScr::onButtonClick);
    m_imgButton->setIsEffect(VFX_TRUE);

    VFX_OBJ_CREATE(imgButton2, VcpImageButton, this);
    imgButton2->setImage(imgList);
    imgButton2->setRect(VfxRect(xStart, yStart + yOffset, buttonWidth, buttonHeight));
    imgButton2->setIsStretchMode(VFX_TRUE);

    VFX_OBJ_CREATE(imgButton3, VcpImageButton, this);
    imgButton3->setImage(imgList);
    imgButton3->setRect(VfxRect(xStart + xOffset, yStart, buttonWidth, buttonHeight));
    imgButton3->setIsStretchMode(VFX_TRUE);

    VFX_OBJ_CREATE(imgButton4, VcpImageButton, this);
    imgButton4->setImage(imgList);
    imgButton4->setRect(VfxRect(xStart + xOffset * 2, yStart, buttonWidth, buttonHeight));
    imgButton4->setIsStretchMode(VFX_TRUE);
    imgButton4->setIsEffect(VFX_TRUE);
    imgButton4->setEffectRatio(1.0F);
 
    VFX_OBJ_CREATE(imgButton5, VcpImageButton, this);
    imgButton5->setImage(imgList);
    imgButton5->setRect(VfxRect(xStart + xOffset * 3, yStart, buttonWidth, buttonHeight));
    imgButton5->setIsStretchMode(VFX_TRUE);
    this->setBgColor(VFX_COLOR_BLACK);
    imgButton5->setIsEffect(VFX_TRUE);
    imgButton5->setEffectRatio(2.0F);

    VFX_OBJ_CREATE(imgButton6, VcpImageButton, this);
    imgButton6->setImage(imgList);
    imgButton6->setRect(VfxRect(xStart + xOffset * 4, yStart, buttonWidth, buttonHeight));
    imgButton6->setEffectGlowType(VCP_GLOW_VISUAL_TYPE_3D);

    m_font.size = VFX_FONT_DESC_SIZE_SMALL;
    VFX_OBJ_CREATE(m_text1, VfxTextFrame, this);
    m_text1->setPos(VfxPoint(10, 300));
    tmpStr.format("Click count: %d", m_clickCount);
    m_text1->setString(tmpStr);
    m_text1->setFont(m_font);

    VFX_OBJ_CREATE(m_text2, VfxTextFrame, this);
    m_text2->setPos(VfxPoint(10, 270));
    m_text2->setFont(m_font);
}


void VtstRtImgButtonScr::onButtonClick(VfxObject*, VfxId)
{
    VfxWString      tmpStr;

    m_clickCount++;
    tmpStr.format("Click count: %d", m_clickCount);
    m_text1->setString(tmpStr);
}
#endif /* __AFX_RT_TEST__ */
