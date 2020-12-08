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
 *  vapp_browser_title_bar.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_BRW_TITLE_BAR_H__
#define __VAPP_BRW_TITLE_BAR_H__

#include "MMI_features.h" 
#ifdef __MMI_BROWSER_2__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_photo_border_frame.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappBrwTitleBar : public VcpTitleBar
{
    //VFX_DECLARE_CLASS(VappBrwTitleBar);

public:
    VappBrwTitleBar();
    virtual ~VappBrwTitleBar() {};
    void setRightIcon(const VfxImageSrc& image);
    void setEditorIcon(const VfxImageSrc& image);
    void deleteRightIcon(void);
    void deleteEditorIcon(void);
    VfxRect getRightIconRect(void){ return m_fullScreenIcon->getRect();}
    void setHomePageIcon();
    void deleteHomePageIcon(void);
    void enableHomePageTap(VfxBool enable);
    void setTitleText(const VfxWString& title);
    VcpTextView* getTitleTextEditor()
    {
        return m_textInput;
    }
    void enableScreenModeIconTap(VfxBool enable);
    VfxSignal0 m_screenModeIconTap;
    VfxSignal0 m_homePageIconTap;
    VfxSignal0 m_editorIconTap;
    VfxSignal1<VfxKeyEvent &> m_editorKeyInput;

protected:
    virtual void onInit(void);
    virtual void onDeinit(void);
    virtual void onUpdate();
    virtual VfxBool onPenInput(VfxPenEvent& event);

private:
    void setRightIconInt(const VfxImageSrc& image, VfxU32 index);
    void portraitPenDownEffect(void);
    void portraitPenUpEffect(void);
    void onClickHomePageIcon(VfxObject *obj, VfxId id);
    void onClickRightIcon(VfxObject *obj, VfxId id);
    void onClickAddress(void);
    void updateTitleTextFrame(VfxTextFrame * textFrame, S32 left, S32 top, S32 right, S32 bottom);
    void updateTitleText();
    VfxWString getTitleText();
    void setEditorIconInt(const VfxImageSrc& image, VfxU32 index);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

private:
    enum
    {
#if defined(__MMI_MAINLCD_320X480__)
        BAR_HEIGHT              = 54,
        PORTRAIT_BG_WIDTH       = 40,
     
        PORTRAIT_BG_X           = 8,
        PORTRAIT_BG_Y           = 8,
     

        ADDRESS_HEIGHT          = 38,
        ADDRESS_Y               = PORTRAIT_BG_Y,

        RIGHT_IMG_OFFSET        = 8,
        RIGHT_IMG_WIDTH         = PORTRAIT_BG_WIDTH,
        RIGHT_IMG_MARGIN        = 6,

        EDITOR_ICON_WIDTH     = 30,
		TEXT_FONT_SIZE		  = 18
#elif defined(__MMI_MAINLCD_240X320__)
		BAR_HEIGHT              = 46,
        PORTRAIT_BG_WIDTH       = 38,
     
        PORTRAIT_BG_X           = 5,
        PORTRAIT_BG_Y           = 5,
     

        ADDRESS_HEIGHT          = 36,
        ADDRESS_Y               = PORTRAIT_BG_Y,

        RIGHT_IMG_OFFSET        = 5,
        RIGHT_IMG_WIDTH         = PORTRAIT_BG_WIDTH,
        RIGHT_IMG_MARGIN        = 5,

        EDITOR_ICON_WIDTH     = 27,
		TEXT_FONT_SIZE		  = 16
#elif defined(__MMI_MAINLCD_240X400__)
		BAR_HEIGHT              = 46,
        PORTRAIT_BG_WIDTH       = 38,
     
        PORTRAIT_BG_X           = 5,
        PORTRAIT_BG_Y           = 5,
     

        ADDRESS_HEIGHT          = 36,
        ADDRESS_Y               = PORTRAIT_BG_Y,

        RIGHT_IMG_OFFSET        = 5,
        RIGHT_IMG_WIDTH         = PORTRAIT_BG_WIDTH,
        RIGHT_IMG_MARGIN        = 5,

        EDITOR_ICON_WIDTH     = 27,
		TEXT_FONT_SIZE		  = 16
#else
		BAR_HEIGHT              = 66,
        PORTRAIT_BG_WIDTH       = 40,
     
        PORTRAIT_BG_X           = 8,
        PORTRAIT_BG_Y           = 22,
     

        ADDRESS_HEIGHT          = 40,
        ADDRESS_Y               = PORTRAIT_BG_Y,

        RIGHT_IMG_OFFSET        = 8,
        RIGHT_IMG_WIDTH         = PORTRAIT_BG_WIDTH,
        RIGHT_IMG_MARGIN        = 6,

        EDITOR_ICON_WIDTH     = 30,
		TEXT_FONT_SIZE		  = 14
#endif 
    };

    enum command_id
    {
        CMD_ADD_NEW,
        CMD_ADD_EXIST,
        CMD_ADD_CANCEL
    };

    enum button_id
    {
        HOME_PAGE_BUTTON,
        FULL_SCREEN_BUTTON
    };
    VcpButton *m_homePageIcon;
    VfxBool m_isSaveEnabled;
    VfxBool m_isHomePageTapEnabled;
    VfxTextFrame * m_titleControl;
    VfxWString m_title;
    VcpTextView *m_textInput;
    VfxImageFrame *m_editorIcon;
    VfxBool m_isHitEditorIcon;
    VcpButton *m_fullScreenIcon;
};

#endif

#endif /* __VAPP_BRW_TITLE_BAR_H__ */

