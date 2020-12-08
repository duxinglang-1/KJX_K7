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
 *  vtst_rt_menu_seekbar.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Description
 *      Screens for Menu Seek Bar cp testing
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

#include "vtst_rt_main.h"
#include "vcp_menu_seek_bar.h"
#include "vfx_datatype.h"
#include "vfx_text_frame.h"
#include "vfx_string.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "GlobalResDef.h"
#include "vfx_image_src.h"
#include "vfx_signal.h"
#include "vfx_app_cat_scr.h"


enum VtstRtMenuSeekBarHeightEnum 
{
#if defined(__MMI_MAINLCD_320X480__)
        VTSTRT_MENU_SEEK_BAR_DEFAULT_HEIGHT = 356,
#elif defined(__MMI_MAINLCD_480X800__)
        VTSTRT_MENU_SEEK_BAR_DEFAULT_HEIGHT = 588,
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
        VTSTRT_MENU_SEEK_BAR_DEFAULT_HEIGHT = 207, 
#else 
        VTSTRT_MENU_SEEK_BAR_DEFAULT_HEIGHT = 207,
#endif
#if defined(__MMI_MAINLCD_320X480__)
        VTSTRT_MENU_SEEK_BAR_LANDSCAPE_HEIGHT = 200,
#elif defined(__MMI_MAINLCD_480X800__)
        VTSTRT_MENU_SEEK_BAR_LANDSCAPE_HEIGHT = 300,
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
        VTSTRT_MENU_SEEK_BAR_LANDSCAPE_HEIGHT = 120, 
#else 
        VTSTRT_MENU_SEEK_BAR_LANDSCAPE_HEIGHT = 120,
#endif
        VTSTRT_MENU_SEEK_BAR_ALL_TYPE_HEIGHT

};    


/***************************************************************************** 
 * Class VtstRtMenuSeekBarScr
 *****************************************************************************/
class VtstRtMenuSeekBarScr : public VtstRtScr
{
// Constructor / Destructor
public:
    VcpMenuSeekBar *m_seekBar;
    VtstRtMenuSeekBarScr():m_seekBar(NULL){}

// Override
protected:
    virtual void onInit();

    virtual VfxS32 start() {return 1;}

    virtual VfxS32 phase(VfxS32 idx);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {
        switch(param.rotateTo)
        {       
        default:
            break;
        }
       // return param.rotateTo;
    }

   virtual void onRotate(const VfxScreenRotateParam &param)
    {
        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);
        if (m_seekBar)
        {
            #if defined(__MMI_MAINLCD_320X480__)
            m_seekBar->setPos(main_screen_size.width - 14, 74);
            #elif defined(__MMI_MAINLCD_480X800__)
            m_seekBar->setPos(main_screen_size.width - 23, 127);
            #elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
            m_seekBar->setPos(main_screen_size.width - 10, 69);
            #else
            m_seekBar->setPos(main_screen_size.width - 10, 69);
            #endif
        }
        if (m_seekBar && ((param.rotateTo == VFX_SCR_ROTATE_TYPE_90)
            || (param.rotateTo == VRT_SYS_SCREEN_ROTATE_270)))
        {
            if (m_textFrame1)
            {
                m_textFrame1->setRect(10, 150, 200, 25);
            }
            if (m_textFrame2)
            {
                m_textFrame2->setRect(10, 180, 200, 25);
            }
            m_seekBar->setHeight(VTSTRT_MENU_SEEK_BAR_LANDSCAPE_HEIGHT);
        }
        if (m_seekBar && ((param.rotateTo == VFX_SCR_ROTATE_TYPE_0)
            || (param.rotateTo == VRT_SYS_SCREEN_ROTATE_180)))
        {
            if (m_textFrame1)
            {
                m_textFrame1->setRect(10, 185, 200, 25);
            }
            if (m_textFrame2)
            {
                m_textFrame2->setRect(10, 215, 200, 25);
            }
            m_seekBar->setHeight(VTSTRT_MENU_SEEK_BAR_DEFAULT_HEIGHT);
        }
        VtstRtScr::onRotate(param);
    }    

// Implementation
private:
    VfxTextFrame *m_textFrame1;

    VfxTextFrame *m_textFrame2;

    void onSeekBarTouch(VfxId tabId);
};


void VtstRtMenuSeekBarScr::onSeekBarTouch(VfxId seekBarItem)
{
    VfxWString textFrameString;
    VfxTextFrame *pTextFrame = m_textFrame2;
    pTextFrame->setString(textFrameString.format("Seek Bar item:%d",seekBarItem));
}


void VtstRtMenuSeekBarScr::onInit()
{
    VtstRtScr::onInit();
    setBgColor(VFX_COLOR_WHITE);

    VFX_OBJ_CREATE(m_textFrame1, VfxTextFrame, this);
    m_textFrame1->setRect(10, 185, 200, 25);
    m_textFrame1->setColor(VfxColor(255,154,154,154));

    VFX_OBJ_CREATE(m_textFrame2, VfxTextFrame, this);
    m_textFrame2->setRect(10, 215, 200, 25);
    m_textFrame2->setColor(VfxColor(255,154,154,154));
    
    //VfxS32 total_items;
    VFX_OBJ_CREATE(m_seekBar, VcpMenuSeekBar, this);
	vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;
    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);
    #if defined(__MMI_MAINLCD_320X480__)
    m_seekBar->setPos(main_screen_size.width - 14, 74);
    #elif defined(__MMI_MAINLCD_480X800__)
    m_seekBar->setPos(main_screen_size.width - 23, 127);
    #elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    m_seekBar->setPos(main_screen_size.width - 10, 69);
    #else
    m_seekBar->setPos(main_screen_size.width - 10, 69);
    #endif
    m_seekBar->setHeight(VTSTRT_MENU_SEEK_BAR_DEFAULT_HEIGHT);
    //total_items = m_seekBar->getMaxItemCount();
    m_seekBar->addImageItem(0, VfxImageSrc(IMG_GLOBAL_L1));
    m_seekBar->addTextItem(1, VFX_WSTR("A"));
    m_seekBar->addTextItem(2, VFX_WSTR("B"));
    m_seekBar->addTextItem(3, VFX_WSTR("C"));
    m_seekBar->addTextItem(4, VFX_WSTR("D"));
    m_seekBar->addTextItem(5, VFX_WSTR("E"));
    m_seekBar->addTextItem(6, VFX_WSTR("F"));
    m_seekBar->addTextItem(7, VFX_WSTR("G"));
    m_seekBar->addTextItem(8, VFX_WSTR("H"));
    m_seekBar->addTextItem(9, VFX_WSTR("I"));
    m_seekBar->addTextItem(10, VFX_WSTR("J"));
    m_seekBar->addImageItem(11, VfxImageSrc(IMG_GLOBAL_L2));
    m_seekBar->addImageItem(12, VfxImageSrc(IMG_GLOBAL_L3));
    m_seekBar->addTextItem(13, VFX_WSTR("K"));
    m_seekBar->addImageItem(14, VfxImageSrc(IMG_GLOBAL_L4));
    m_seekBar->addImageItem(15, VfxImageSrc(IMG_GLOBAL_L5));
    m_seekBar->addTextItem(16, VFX_WSTR("L"));
    m_seekBar->addTextItem(17, VFX_WSTR("M"));
    m_seekBar->addTextItem(18, VFX_WSTR("N"));
    m_seekBar->addTextItem(19, VFX_WSTR("0"));
    m_seekBar->addTextItem(20, VFX_WSTR("P"));
    m_seekBar->addTextItem(21, VFX_WSTR("Q"));
    m_seekBar->addTextItem(22, VFX_WSTR("R"));
    m_seekBar->addImageItem(23, VfxImageSrc(IMG_GLOBAL_L6));
    m_seekBar->addImageItem(24, VfxImageSrc(IMG_GLOBAL_L7));
    m_seekBar->addImageItem(25, VfxImageSrc(IMG_GLOBAL_L8));
    m_seekBar->addImageItem(26, VfxImageSrc(IMG_GLOBAL_L9));
    m_seekBar->addImageItem(27, VfxImageSrc(IMG_GLOBAL_L10));
    m_seekBar->m_signalMenuSeekBarTouch.connect(this, &VtstRtMenuSeekBarScr::onSeekBarTouch);
    m_textFrame1->setString(VFX_WSTR("Menu Seek Bar"));
    m_textFrame2->setString(VFX_WSTR("Menu Seek Bar Item:-1"));
}


VfxS32 VtstRtMenuSeekBarScr::phase(VfxS32 idx)
{
    setTitle(VFX_WSTR("Menu Seek Bar"));
    m_title->setColor(VfxColor(255,15,15,15));
    confirm(VFX_WSTR("Result is correct?"));
    return -1;
}


VtstTestResultEnum vtst_rt_menu_seek_bar(VfxU32 param)
{
    VTST_START_SCRN(VtstRtMenuSeekBarScr);
    return VTST_TR_OK;
}

#endif /* __AFX_RT_TEST__ */
