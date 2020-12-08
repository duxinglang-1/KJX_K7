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
 *  vtst_rt_text_view.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for VtstRtTextView and VtstRtTextEditor
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vtst_rt_main.h"

#if defined(__COSMOS_MMI_PACKAGE__) && defined(__AFX_RT_TEST__)
#include "vcp_text_view.h"
#include "vcp_text_editor.h"
#include "vcp_contact_selector.h"
#include "vcp_popup.h"
#include "vcp_function_bar.h"
#include "vfx_primitive_frame.h"
#include "vcp_form.h"
#include "vcp_menu_popup.h"

// for test image
#include "GlobalResDef.h"


static VfxWChar multi_view_string[2048] = {0};
static VfxWChar multi_editor_string[2048] = {0};
static VfxWChar singleline_string[201] = {0};

#define  TEST_VIEW_START_X             5
#define  TEST_VIEW_START_Y            40
#define  TEST_VIEW_WIDTH             230

#if defined(__MMI_MAINLCD_320X480__)
#define  TEXT_VIEW_SINGLELINE_HEIGHT  39
#elif defined(__MMI_MAINLCD_480X800__)
#define  TEXT_VIEW_SINGLELINE_HEIGHT  67
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
#define  TEXT_VIEW_SINGLELINE_HEIGHT  37
#else
#define  TEXT_VIEW_SINGLELINE_HEIGHT  39
#endif

#define  TEXT_VIEW_MULTILINE_HEIGHT   90
#define  TEXT_VIEW_GAP                 5
#define  TEXT_VIEW_TEST_FUNC_NUM      29
#define  TEXT_VIEW_TEST_BUTTON_WIDTH  50
#define  TEXT_VIEW_TEST_BUTTON_HEIGHT 30
#define  TEXT_VIEW_TEST_EDITOR_NUM     5

class VtstRtTextView;

#define TEST_ICON_NUM      3
static VcpIconTable textIconTable[TEST_ICON_NUM] = 
{
    {IMG_GLOBAL_L1, (const VfxWChar *)L":)"},
    {IMG_GLOBAL_L2, (const VfxWChar *)L":("},
    {IMG_GLOBAL_L3, (const VfxWChar *)L"^_^"}
};

#if 0
/* under construction !*/
#if VCP_TEXT_MAGNIFIER_SUPPORT
/* under construction !*/
#endif
#endif

/***************************************************************************** 
 * Text View Test Implementation
 *****************************************************************************/
class VtstRtTextViewSingleView : public VtstRtScr
{
// Constructor / Destructor
public:
    VtstRtTextViewSingleView()
    {
    }

    //virtual VfxFrameImeModeEnum getImeMode() {return VFX_FRAME_IME_MODE_SHIFT;}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        
        setTitle(VFX_WSTR("Singleline text view Test"));

        testSinglelineView();
    }

    virtual void onDeinit()
    {
        VtstRtScr::onDeinit();
        
        closeTestObject();
    }

    void testSinglelineView()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        VFX_OBJ_CREATE(box, VfxControl, this);
        box->setRect(VfxRect(0, TEST_VIEW_START_Y, mainScreenSize.width, mainScreenSize.height - TEST_VIEW_START_Y));
        box->setBgColor(VFX_COLOR_WHITE);
        box->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                    VFX_FRAME_ALIGNER_MODE_SIDE,
                                    VFX_FRAME_ALIGNER_MODE_SIDE,
                                    VFX_FRAME_ALIGNER_MODE_SIDE);

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        // singleline text view
        mmi_ucs2cpy((char *)singleline_string, (const char*)L"This singleline line text view, you can use pen scroll to view more content.");
        VFX_OBJ_CREATE(m_singlelineView, VcpTextView, this);
        m_singlelineView->setPos(VfxPoint(xPos, yPos));
        m_singlelineView->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, TEXT_VIEW_SINGLELINE_HEIGHT));
        m_singlelineView->setText(singleline_string);
        m_singlelineView->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
    }

    virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    )
    {
        // do nothing
    }

    virtual void onRotate(
        const VfxScreenRotateParam &param // The parameter to rotate
    )
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        m_singlelineView->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, TEXT_VIEW_SINGLELINE_HEIGHT));

        VtstRtScr::onRotate(param);
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Does it work?"));
        return -1;
    }

    void closeTestObject()
    {
        if (m_singlelineView)
        {
            VFX_OBJ_CLOSE(m_singlelineView);
        }
    }

private:
    VcpTextView *m_singlelineView;
    VfxControl *box;
};


/***************************************************************************** 
 * Text View Test Implementation
 *****************************************************************************/
class VtstRtTextViewSingleEditor : public VtstRtScr
{
// Constructor / Destructor
public:
    VtstRtTextViewSingleEditor()
    {
    }

    //virtual VfxFrameImeModeEnum getImeMode() {return VFX_FRAME_IME_MODE_SHIFT;}

public:
    virtual VfxFrameImeModeEnum getImeMode() {return VFX_FRAME_IME_MODE_SHIFT;}
    
// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        
        setTitle(VFX_WSTR("Singleline text editor Test"));

        VfxS32 command = 0;

        testSinglelineEditor();
    }

    virtual void onDeinit()
    {
        VtstRtScr::onDeinit();
        
        closeTestObject();
    }

    void testSinglelineEditor()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
        VFX_OBJ_CREATE(box, VfxControl, this);
        box->setRect(VfxRect(0, TEST_VIEW_START_Y, mainScreenSize.width, mainScreenSize.height - TEST_VIEW_START_Y));
        box->setBgColor(VFX_COLOR_WHITE);
        box->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                            VFX_FRAME_ALIGNER_MODE_SIDE,
                            VFX_FRAME_ALIGNER_MODE_SIDE,
                            VFX_FRAME_ALIGNER_MODE_SIDE);

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        // singleline text editor
        mmi_ucs2cpy((char *)singleline_string, (const char*)L"This single line text editor test");
        VFX_OBJ_CREATE(m_singlineEditor, VcpTextEditor, this);
        m_singlineEditor->setPos(VfxPoint(xPos, yPos));
        m_singlineEditor->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, TEXT_VIEW_SINGLELINE_HEIGHT);
        m_singlineEditor->setText(singleline_string, 200);
      //  m_singlineEditor->setText(VFX_WSTR_NULL, 200);
      //  m_singlineEditor->setText(VFX_WSTR_EMPTY, 200);
        m_singlineEditor->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
        m_singlineEditor->setDeleteButton(VFX_TRUE);
    }

    virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    )
    {
        // do nothing
    }

    virtual void onRotate(
        const VfxScreenRotateParam &param // The parameter to rotate
    )
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        m_singlineEditor->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, TEXT_VIEW_SINGLELINE_HEIGHT);

        VtstRtScr::onRotate(param);
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Does it work?"));
        return -1;
    }

    void closeTestObject()
    {
        if (m_singlineEditor)
        {
            VFX_OBJ_CLOSE(m_singlineEditor);
        }
    }

private:
    VcpTextEditor *m_singlineEditor;
    VfxControl *box;
};


/***************************************************************************** 
 * Text View Test Implementation
 *****************************************************************************/
class VtstRtTextViewMultiView : public VtstRtScr
{
// Constructor / Destructor
public:
    VtstRtTextViewMultiView()
    {
    }

    //virtual VfxFrameImeModeEnum getImeMode() {return VFX_FRAME_IME_MODE_SHIFT;}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        
        setTitle(VFX_WSTR_EMPTY);

        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        VFX_OBJ_CREATE(m_fontEffectButton, VcpButton, this);
        m_fontEffectButton->setText(VFX_WSTR("Font effect"));
        m_fontEffectButton->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_fontEffectButton->setRect(VfxRect(
                                mainScreenSize.width - 150 - TEXT_VIEW_GAP, 
                                TEXT_VIEW_GAP,
                                150, 
                                TEXT_VIEW_TEST_BUTTON_HEIGHT));
        VfxFontDesc fontDesc;
        fontDesc.size = VFX_FONT_DESC_VF_SIZE(14);
        m_fontEffectButton->setTextFont(fontDesc);
        m_fontEffectButton->m_signalClicked.connect(this, &VtstRtTextViewMultiView::onEffectButtonClick);

        VFX_OBJ_CREATE(m_colorButton, VcpButton, this);
        m_colorButton->setText(VFX_WSTR("Revert color"));
        m_colorButton->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_colorButton->setRect(VfxRect(
                                TEXT_VIEW_GAP, 
                                TEXT_VIEW_GAP,
                                150, 
                                TEXT_VIEW_TEST_BUTTON_HEIGHT));
        m_colorButton->setTextFont(fontDesc);
        m_colorButton->m_signalClicked.connect(this, &VtstRtTextViewMultiView::onColorButtonClick);

        m_multilineView = NULL;

        VFX_ALLOC_NEW(m_effect, VfxFontEffect, this);

        testMultilineView();
    }

    void onEffectButtonClick(VfxObject* sender, VfxId id)
    {
        changeFont();
    }

    void onColorButtonClick(VfxObject* sender, VfxId id)
    {
        if (box->getBgColor() == (VfxColor)VRT_COLOR_MAKE(255, 170, 170, 170))
        {
            box->setBgColor(VFX_COLOR_WHITE);
            m_multilineView->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_BLACK);
        }
        else
        {
            box->setBgColor(VRT_COLOR_MAKE(255, 170, 170, 170));
            m_multilineView->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_WHITE);
        }
    }

    virtual void onDeinit()
    {
        VFX_DELETE(m_effect);
        
        VtstRtScr::onDeinit();
        
        closeTestObject();
    }

    void testMultilineView()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
        VFX_OBJ_CREATE(box, VfxControl, this);
        box->setRect(VfxRect(0, TEST_VIEW_START_Y, mainScreenSize.width, mainScreenSize.height - TEST_VIEW_START_Y));
        box->setBgColor(VFX_COLOR_WHITE);
        box->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                            VFX_FRAME_ALIGNER_MODE_SIDE,
                            VFX_FRAME_ALIGNER_MODE_SIDE,
                            VFX_FRAME_ALIGNER_MODE_SIDE);

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        // multiline text view
        mmi_ucs2cpy((char *)multi_view_string, (const char*)L"This is multiline text view test. 12345, a@g.com, 19415@sohu.com, www.123456432424.com, Hello, my name is Andy Liu, my phone number is 0123456789, my email address is aaa@bbb.com. Welcome to use richtext text view component.\n");
        for (VfxS32 i = 0; i < 30; i ++)
        {
            mmi_ucs2cat((char *)multi_view_string, (const char*)L"The quick brown fox jumps over the lazy dog. ");
        }
        if (m_multilineView == NULL)
        {
            VFX_OBJ_CREATE(m_multilineView, VcpTextView, this);
        }
        m_multilineView->setPos(VfxPoint(xPos, yPos));
        m_multilineView->setBounds(VfxRect(0, 0, mainScreenSize.width  - 2 * TEXT_VIEW_GAP, mainScreenSize.height * 3 / 4));
        m_multilineView->setText(multi_view_string);
        m_multilineView->setKeyword(VCP_TEXT_KEYWORD_EMAIL | VCP_TEXT_KEYWORD_URL | VCP_TEXT_KEYWORD_PHONENUMBER);
        m_multilineView->activate();
    }

    void changeFont()
    {
        m_font = m_multilineView->getFont();

        VfxU32 i = (VfxU32)(m_font.effect);
        i++;
        m_font.effect = i;
        if (m_font.effect >= FE_EFFECT_END_OF_ENUM + 1)
            m_font.effect = VFX_FONT_DESC_EFFECT_NONE;

        switch (m_font.effect)
        {
            case VFX_FONT_DESC_EFFECT_NONE:
                m_fontEffectButton->setText(VFX_WSTR("No effect"));
                break;
            case VFX_FONT_DESC_EFFECT_STRIKETHROUGH:
                m_fontEffectButton->setText(VFX_WSTR("Strikethrough"));
                break;
            case VFX_FONT_DESC_EFFECT_BORDER:
                m_fontEffectButton->setText(VFX_WSTR("Old Border"));
                break;
            case VFX_FE1_1:
                m_fontEffectButton->setText(VFX_WSTR("VFX_FE1_1"));
                break;
            case VFX_FE1_2:
                m_fontEffectButton->setText(VFX_WSTR("VFX_FE1_2"));
                break;
            case VFX_FE1_3:
                m_fontEffectButton->setText(VFX_WSTR("VFX_FE1_3"));
                break;
            case VFX_FE1_4:
                m_fontEffectButton->setText(VFX_WSTR("VFX_FE1_4"));
                break;
            case VFX_FE1_5:
                m_fontEffectButton->setText(VFX_WSTR("VFX_FE1_5"));
                break;
            case VFX_FE1_6:
                m_fontEffectButton->setText(VFX_WSTR("VFX_FE1_6"));
                break;
            case VFX_FE1_7:
                m_fontEffectButton->setText(VFX_WSTR("VFX_FE1_7"));
                break;
            case VFX_FE1_8:
                m_fontEffectButton->setText(VFX_WSTR("VFX_FE1_8"));
                break;
            case VFX_FE2_1:
                m_fontEffectButton->setText(VFX_WSTR("VFX_FE2_1"));
                break;
            case VFX_FE3_1:
                m_fontEffectButton->setText(VFX_WSTR("VFX_FE3_1"));
                break;
            case VFX_FE4_1:
                m_fontEffectButton->setText(VFX_WSTR("VFX_FE4_1"));
                break;
            case VFX_FE5_1:
                m_fontEffectButton->setText(VFX_WSTR("VFX_FE5_1"));
                break;
            case VFX_FE5_1 + 1:
                {
                    m_effect->setType(VFX_FONT_EFFECT_SHADOW);
                    m_effect->setShadow(VFX_COLOR_RED, 80 , 3, 2, 80);
                    m_font.effect = m_effect->getEffectId();
                    m_fontEffectButton->setText(VFX_WSTR("User-defined ID"));
                }
                break;

            default:
                m_fontEffectButton->setText(VFX_WSTR("Font effect"));
                break;
        }

        m_multilineView->setFont(m_font);
    }

    virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    )
    {
        // do nothing
    }

    virtual void onRotate(
        const VfxScreenRotateParam &param // The parameter to rotate
    )
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        m_multilineView->setBounds(VfxRect(0, 0, mainScreenSize.width /* - 2 * TEXT_VIEW_GAP*/, mainScreenSize.height * 3 / 4));

        VtstRtScr::onRotate(param);
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Does it work?"));
        return -1;
    }

    void closeTestObject()
    {
        if (m_multilineView)
        {
            VFX_OBJ_CLOSE(m_multilineView);
        }
    }

private:
    VcpTextView *m_multilineView;
    VfxControl *box;
    VcpButton *m_fontEffectButton;
    VcpButton *m_colorButton;
    VfxFontDesc m_font;
    VfxFontEffect *m_effect;
};


/***************************************************************************** 
 * Text View Test Implementation
 *****************************************************************************/
class VtstRtTextViewMultiEditor : public VtstRtScr
{
// Constructor / Destructor
public:
    VtstRtTextViewMultiEditor()
    {
    }

    //virtual VfxFrameImeModeEnum getImeMode() {return VFX_FRAME_IME_MODE_SHIFT;}

public:
    virtual VfxFrameImeModeEnum getImeMode() {return VFX_FRAME_IME_MODE_SHIFT;}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        
        setTitle(VFX_WSTR("Multiline text editor Test"));

        testMultilineEditor();
    }

    virtual void onDeinit()
    {
        VtstRtScr::onDeinit();
        
        closeTestObject();
    }

    void testMultilineEditor()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
        VFX_OBJ_CREATE(box, VfxControl, this);
        box->setRect(VfxRect(0, TEST_VIEW_START_Y, mainScreenSize.width, mainScreenSize.height - TEST_VIEW_START_Y));
        box->setBgColor(VFX_COLOR_WHITE);
        box->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                            VFX_FRAME_ALIGNER_MODE_SIDE,
                            VFX_FRAME_ALIGNER_MODE_SIDE,
                            VFX_FRAME_ALIGNER_MODE_SIDE);

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        // multiline text editor
        mmi_ucs2cpy((char *)multi_editor_string, (const char*)L"This is multiline text editor test.");
        for (VfxS32 i = 0; i < 30; i ++)
        {
            mmi_ucs2cat((char *)multi_editor_string, (const char*)L"The quick brown fox jumps over the lazy dog. ");
        }
        VFX_OBJ_CREATE(m_multilineEditor, VcpTextEditor, this);
        m_multilineEditor->setPos(VfxPoint(xPos, yPos));
        m_multilineEditor->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 3);
        m_multilineEditor->setText(multi_editor_string, 2000);
        m_multilineEditor->setAutoResized(VFX_TRUE, -1, mainScreenSize.height / 3);
        m_multilineEditor->setAutoAnimate(VFX_TRUE);
    }

    virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    )
    {
        // do nothing
    }

    virtual void onRotate(
        const VfxScreenRotateParam &param // The parameter to rotate
    )
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        m_multilineEditor->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 3);

        VtstRtScr::onRotate(param);
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Does it work?"));
        return -1;
    }

    void closeTestObject()
    {
        if (m_multilineEditor)
        {
            VFX_OBJ_CLOSE(m_multilineEditor);
        }
    }

private:
    VcpTextEditor *m_multilineEditor;
    VfxControl *box;
};


/***************************************************************************** 
 * Text View Test Implementation
 *****************************************************************************/
class VtstRtTextView : public VtstRtScr
{
// Constructor / Destructor
public:
    VtstRtTextView()
    {
    }

    //virtual VfxFrameImeModeEnum getImeMode() {return VFX_FRAME_IME_MODE_SHIFT;}

public:
    virtual VfxFrameImeModeEnum getImeMode() {return VFX_FRAME_IME_MODE_SHIFT;}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        
        setTitle(VFX_WSTR("Unit function test"));

        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
        VfxControl *box;
        VFX_OBJ_CREATE(box, VfxControl, this);
        box->setRect(VfxRect(0, TEST_VIEW_START_Y, mainScreenSize.width, mainScreenSize.height - TEST_VIEW_START_Y));
        box->setBgColor(VFX_COLOR_WHITE);

        // navigation button
        VFX_OBJ_CREATE(m_prevButton, VcpButton, this);
        m_prevButton->setText(VFX_WSTR("<<"));
        m_prevButton->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_prevButton->setRect(VfxRect(
                                mainScreenSize.width - TEXT_VIEW_TEST_BUTTON_WIDTH * 2 - TEXT_VIEW_GAP, 
                                TEXT_VIEW_GAP,
                                TEXT_VIEW_TEST_BUTTON_WIDTH, 
                                TEXT_VIEW_TEST_BUTTON_HEIGHT
                            ));
        m_prevButton->m_signalClicked.connect(this, &VtstRtTextView::onNavButtonClick);
        m_prevButton->setId(0);
        // navigation button
        VFX_OBJ_CREATE(m_nextButton, VcpButton, this);
        m_nextButton->setText(VFX_WSTR(">>"));
        m_nextButton->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_nextButton->setRect(VfxRect(
                                mainScreenSize.width - TEXT_VIEW_TEST_BUTTON_WIDTH, 
                                TEXT_VIEW_GAP,
                                TEXT_VIEW_TEST_BUTTON_WIDTH, 
                                TEXT_VIEW_TEST_BUTTON_HEIGHT
                            ));
        m_nextButton->m_signalClicked.connect(this, &VtstRtTextView::onNavButtonClick);
        m_prevButton->setId(1);

        // set test text
        mmi_ucs2cpy((char *)multi_view_string, (const char*)L"12345, a@g.com, 19415@sohu.com, www.123456432424.com, Hello, my name is Andy Liu, my phone number is 0123456789, my email address is Andy.Liu@mmm.com.");
        mmi_ucs2cpy((char *)multi_editor_string, (const char*)L"Hello, my name is Andy Liu, my phone number is 0123456789, my email address is aaa@bbb.ccc.");
        mmi_ucs2cpy((char *)singleline_string, (const char*)L"Hello, my name is Andy Liu, my phone number is 0123456789, my email address is Andy.Liu@mediatek.com. ");

        for (VfxS32 i = 0; i < 10; i ++)
        {
            mmi_ucs2cat((char *)multi_view_string, (const char*)L"The quick brown fox jumps over the lazy dog.");
            mmi_ucs2cat((char *)multi_editor_string, (const char*)L"The quick brown fox jumps over the lazy dog.");
        }

        m_multilineView = NULL;
        m_singlelineView = NULL;
        m_multilineEditor = NULL;
        m_singlineEditor = NULL;
        m_progressTimer = NULL;
        m_convertButton = NULL;
        m_magnifierTestButton = NULL;
        m_form = NULL;
        m_menu = NULL;

        for (VfxS32 i = 0; i < TEXT_VIEW_TEST_EDITOR_NUM; i++)
        {
            m_editors[i] = NULL;
        }

        m_testIndex = 0;

        testOverall();
    }

    void onNavButtonClick(VfxObject* sender, VfxId id)
    {
        if (id == 0)
        {
            m_testIndex++;
        }
        else
        {
            m_testIndex--;
        }

        if (m_testIndex < 0)
        {
            m_testIndex = 0;
        }
        else if (m_testIndex > TEXT_VIEW_TEST_FUNC_NUM)
        {
            m_testIndex = TEXT_VIEW_TEST_FUNC_NUM;
        }
        runTest(m_testIndex);
    }

    virtual void onDeinit()
    {
        VtstRtScr::onDeinit();
        
        closeTestObject();
    }

    void testOverall()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Unit function test"));

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;
#if 1
        // singleline text editor
        VFX_OBJ_CREATE(m_singlineEditor, VcpTextEditor, this);
        m_singlineEditor->setPos(VfxPoint(xPos, yPos));
        m_singlineEditor->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, TEXT_VIEW_SINGLELINE_HEIGHT));
        m_singlineEditor->setText(singleline_string, 200);
        m_singlineEditor->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);

        yPos += TEXT_VIEW_GAP + TEXT_VIEW_SINGLELINE_HEIGHT;

        // multiline text view
        VFX_OBJ_CREATE(m_multilineView, VcpTextView, this);
        m_multilineView->setPos(VfxPoint(xPos, yPos));
        m_multilineView->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 3));
        m_multilineView->setText(multi_view_string);

        yPos += TEXT_VIEW_GAP + mainScreenSize.height / 3;
#endif
        // multiline text editor
        VFX_OBJ_CREATE(m_multilineEditor, VcpTextEditor, this);
        m_multilineEditor->setHint(VFX_WSTR("Please tap to input:"));
        m_multilineEditor->setPos(VfxPoint(xPos, yPos));
        m_multilineEditor->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 3);
      //  m_multilineEditor->setText(multi_editor_string, 2000);
        m_multilineEditor->setText(multi_editor_string, 2000);
    }

    void testSinglelineView()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Singleline view"));

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        // singleline text view
        mmi_ucs2cpy((char *)singleline_string, (const char*)L"This singleline line text view test case");
        VFX_OBJ_CREATE(m_singlelineView, VcpTextView, this);
        m_singlelineView->setPos(VfxPoint(xPos, yPos));
        m_singlelineView->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, TEXT_VIEW_SINGLELINE_HEIGHT));
        m_singlelineView->setText(singleline_string);
        m_singlelineView->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
    }

    void testMultilineView()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Multiline view"));

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        // multiline text view
        mmi_ucs2cpy((char *)multi_view_string, (const char*)L"This is multiline text view test. 12345, a@g.com, 19415@sohu.com, www.123456432424.com, Hello, my name is Andy Liu, my phone number is 0123456789, my email address is aaa@bbb.com. Welcome to use richtext text view component.");
        for (VfxS32 i = 0; i < 30; i ++)
        {
            mmi_ucs2cat((char *)multi_view_string, (const char*)L"The quick brown fox jumps over the lazy dog.");
        }
        VFX_OBJ_CREATE(m_multilineView, VcpTextView, this);
        m_multilineView->setPos(VfxPoint(xPos, yPos));
        m_multilineView->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height * 3 / 4));
        m_multilineView->setText(multi_view_string);
        m_multilineView->startScroll();
    }

    void testSinglelineEditor()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Singleline editor"));

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        // singleline text editor
        mmi_ucs2cpy((char *)singleline_string, (const char*)L"This single line text editor test case");
        VFX_OBJ_CREATE(m_singlineEditor, VcpTextEditor, this);
        m_singlineEditor->setPos(VfxPoint(xPos, yPos));
        m_singlineEditor->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, TEXT_VIEW_SINGLELINE_HEIGHT));
        m_singlineEditor->setText(singleline_string, 200);
        m_singlineEditor->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
        m_singlineEditor->setAutoActivated(VFX_TRUE, 0);

        yPos += TEXT_VIEW_SINGLELINE_HEIGHT + TEXT_VIEW_GAP;

        // empty content test
        VFX_OBJ_CREATE(m_editors[0], VcpTextEditor, this);
        m_editors[0]->setPos(VfxPoint(xPos, yPos));
        m_editors[0]->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, TEXT_VIEW_SINGLELINE_HEIGHT));
        m_editors[0]->setText(VFX_WSTR_NULL, 200);
        m_editors[0]->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);

        yPos += TEXT_VIEW_SINGLELINE_HEIGHT + TEXT_VIEW_GAP;

        // long content test
        VFX_OBJ_CREATE(m_editors[1], VcpTextEditor, this);
        m_editors[1]->setPos(VfxPoint(xPos, yPos));
        m_editors[1]->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, TEXT_VIEW_SINGLELINE_HEIGHT));
        m_editors[1]->setText(VFX_WSTR("This is a long test string in single line editor. This is a long test string in single line editor. This is a long test string in single line editor. This is a long test string in single line editor. "), 1000);
        m_editors[1]->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
    }

    void testMultilineEditor()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Multiline editor"));

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        // multiline text editor
        mmi_ucs2cpy((char *)multi_editor_string, (const char*)L"This is multiline text editor test. 12345, a@g.com, 19415@sohu.com, www.123456432424.com, Hello, my name is Andy Liu, my phone number is 0123456789, my email address is aaa@bbb.com. Welcome to use richtext text view component.");
        for (VfxS32 i = 0; i < 30; i ++)
        {
            mmi_ucs2cat((char *)multi_editor_string, (const char*)L"The quick brown fox jumps over the lazy dog.");
        }
        VFX_OBJ_CREATE(m_multilineEditor, VcpTextEditor, this);
        m_multilineEditor->setPos(VfxPoint(xPos, yPos));
        m_multilineEditor->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 3);
        m_multilineEditor->setText(multi_editor_string, 2000);
        m_multilineEditor->setAutoActivated(VFX_TRUE);

        yPos += TEXT_VIEW_GAP + mainScreenSize.height / 3;

        // empty content test
        VFX_OBJ_CREATE(m_editors[0], VcpTextEditor, this);
        m_editors[0]->setPos(VfxPoint(xPos, yPos));
        m_editors[0]->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 3);
        m_editors[0]->setText(VFX_WSTR_EMPTY, 2000);
    }
    
    void testSetKeyword()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Key word test"));

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        mmi_ucs2cpy((char *)multi_view_string, (const char*)L"This is multiline SetKeyword test.\n");
        mmi_ucs2cat((char *)multi_view_string, (const char*)L"11111, www.a.b, a@b\n");
        mmi_ucs2cat((char *)multi_view_string, (const char*)L"22222, www.b.c, b@c\n");
        mmi_ucs2cat((char *)multi_view_string, (const char*)L"33333, www.c.d, c@d\n");
        mmi_ucs2cat((char *)multi_view_string, (const char*)L"44444, www.d.e, d@e\n");
        mmi_ucs2cat((char *)multi_view_string, (const char*)L"55555, www.e.f, e@f\n");
        mmi_ucs2cat((char *)multi_view_string, (const char*)L"66666, www.f.g, f@g\n");
        mmi_ucs2cat((char *)multi_view_string, (const char*)L"77777, www.g.h, g@h\n");
        mmi_ucs2cat((char *)multi_view_string, (const char*)L"88888, www.i.j, i@j\n");
        mmi_ucs2cat((char *)multi_view_string, (const char*)L"99999, www.j.k, j@k\n");
        mmi_ucs2cat((char *)multi_view_string, (const char*)L"00000, www.k.l, k@l\n");
        mmi_ucs2cat((char *)multi_view_string, (const char*)L"12222, www.l.m, l@m\n");
        mmi_ucs2cat((char *)multi_view_string, (const char*)L"23333, www.m.n, m@n\n");
        mmi_ucs2cat((char *)multi_view_string, (const char*)L"34444, www.o.p, o@p\n");
        mmi_ucs2cat((char *)multi_view_string, (const char*)L"56666, www.q.r, q@r\n");
        mmi_ucs2cat((char *)multi_view_string, (const char*)L"78888, www.a.x, a@x\n");
        mmi_ucs2cat((char *)multi_view_string, (const char*)L"53333, www.r.t, t@t\n");
        mmi_ucs2cat((char *)multi_view_string, (const char*)L"97777, www.o.d, x@x\n");
        mmi_ucs2cat((char *)multi_view_string, (const char*)L"12232, www.q.d, t@c\n");
        mmi_ucs2cat((char *)multi_view_string, (const char*)L"42342, www.w.d, u@c\n");
        mmi_ucs2cat((char *)multi_view_string, (const char*)L"74564, www.e.d, x@c\n");
        mmi_ucs2cat((char *)multi_view_string, (const char*)L"97876, www.n.d, q@c\n");
        mmi_ucs2cat((char *)multi_view_string, (const char*)L"12333, www.i.d, l@c\n");

        // multiline text view
        VFX_OBJ_CREATE(m_multilineView, VcpTextView, this);
        m_multilineView->setPos(VfxPoint(xPos, yPos));
        m_multilineView->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 2));
        m_multilineView->setText(multi_view_string);
        m_multilineView->setKeyword(VCP_TEXT_KEYWORD_EMAIL | VCP_TEXT_KEYWORD_URL | VCP_TEXT_KEYWORD_PHONENUMBER);
        m_multilineView->m_signalKeywordClick.connect(this, &VtstRtTextView::onKeywordClicked);
        m_multilineView->setText(multi_view_string);
    }

    void onKeywordClicked(VcpTextKeyWordEnum mode, VfxWChar *text, VfxS32 len)
    {
        switch (mode)
        {
        case VCP_TEXT_KEYWORD_EMAIL:
            // get text and goto email
            break;
        case VCP_TEXT_KEYWORD_URL:
            // get URL and goto URL
            break;
        case VCP_TEXT_KEYWORD_PHONENUMBER:
            // get phonenumber and goto phonebook
            break;
        case VCP_TEXT_KEYWORD_USSD:
            // get USSD and goto USSD
            break;
        default:
            break;
        }
    }

    void testRichText()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Rich text test"));

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        mmi_ucs2cpy((char *)multi_editor_string, (const char*)L"This is multiline rich text test.\nHello, my name is Andy Liu, my phone number is 0123456789, my email address is aaa@bbb.com. You can set text format and image in the text. VcpRichText is used for set text format like color, size, underline attribute.... If you want to set a image in the format, you can use VcpRichTextImage. Also, VcpRichTextCustomFrame is also support if you want to set a custom frame in text view. Other format like VcpRichTextVideo, VcpRichTextAudio will support in future. \nThis is really a powerful rich text layout engine. Thanks. \nAny question welcome to let me know.");

        // set text format
        VcpRichText formatPhonenumber;
        VfxFontDesc numberFont;
        numberFont.attr |= VFX_FONT_DESC_ATTR_UNDERLINE | VFX_FONT_DESC_ATTR_BOLD;
        numberFont.size = VFX_FONT_DESC_SIZE_LARGE;
        formatPhonenumber.setTextColor(VRT_COLOR_RED);
        formatPhonenumber.setRange(8, 32);
        formatPhonenumber.setFont(numberFont);

        VcpRichText formatEmail;
        VfxFontDesc emailFont;
        emailFont.attr |= VFX_FONT_DESC_ATTR_STRIKETHROUGH | VFX_FONT_DESC_ATTR_OBLIQUE;
        emailFont.size = VFX_FONT_DESC_VF_SIZE(40);
        formatEmail.setTextColor(VRT_COLOR_MAKE(255, 0, 0, 230));
        formatEmail.setRange(52, 60);
        formatEmail.setFont(emailFont);

        VfxImageSrc testIcon1;
        testIcon1.setResId(IMG_GLOBAL_L1);

        VfxImageSrc testIcon2;
        testIcon2.setResId(IMG_GLOBAL_L1);

        VfxImageSrc testIcon3;
        testIcon3.setResId(IMG_GLOBAL_L1);

        VcpRichTextImage image1Format(this);
        image1Format.setImage(&testIcon1);
        image1Format.setRange(0, 0);
        image1Format.setObjectAttribute(VCP_RICH_TEXT_OBJ_ARRT_MID_ALIGN);

        VcpRichTextImage image2Format(this);
        image2Format.setImage(&testIcon2);
        image2Format.setRange(40, 40);
        //image2Format.setObjectAttribute(VCP_RICH_TEXT_OBJ_ARRT_RIGHT_ALIGN);

        VcpRichTextImage image3Format(this);
        image3Format.setImage(&testIcon3);
        VfxS32 strLen = mmi_ucs2strlen((const CHAR*)(multi_editor_string));
        image3Format.setRange(strLen, strLen);
        image3Format.setObjectAttribute(VCP_RICH_TEXT_OBJ_ARRT_MID_ALIGN);

        // multiline text view
        VFX_OBJ_CREATE(m_multilineView, VcpTextView, this);
        m_multilineView->setPos(VfxPoint(xPos, yPos));
        m_multilineView->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height * 3 / 4));
        m_multilineView->setText(multi_editor_string);
        m_multilineView->addTextFormat(image1Format);
        m_multilineView->addTextFormat(image2Format);
        m_multilineView->addTextFormat(image3Format);
        m_multilineView->addTextFormat(formatPhonenumber);
        m_multilineView->addTextFormat(formatEmail);
        m_multilineView->setKeyword(VCP_TEXT_KEYWORD_EMAIL | VCP_TEXT_KEYWORD_URL | VCP_TEXT_KEYWORD_PHONENUMBER);
        m_multilineView->activate();
    }

    
    void testIcon()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Icon test"));

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        mmi_ucs2cpy((char *)multi_editor_string, (const char*)L"This is multiline rich text test. Smile :), Cry: :(");
        mmi_ucs2cpy((char *)singleline_string, (const char*)L"This is singleline rich text test. Smile :), Cry: :(");

        // multiline text editor
        VFX_OBJ_CREATE(m_multilineEditor, VcpTextEditor, this);
        m_multilineEditor->setPos(VfxPoint(xPos, yPos));
        m_multilineEditor->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 2));
        m_multilineEditor->setText(multi_editor_string, 2000);
        m_multilineEditor->setIconMode(VFX_TRUE, textIconTable, TEST_ICON_NUM);
    }

    void testDisableBackground()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Disable/Enable background test"));

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        mmi_ucs2cpy((char *)multi_view_string, (const char*)L"This multiline text view DisableBackground test. 12345, a@g.com, 19415@sohu.com, www.123456432424.com, Hello, my name is Andy Liu, my phone number is 0123456789, my email address is aaa@bbb.com. Welcome to use richtext text view component.");
        mmi_ucs2cpy((char *)multi_editor_string, (const char*)L"This multiline text editor DisableBackground test. Hello, my name is Andy Liu, my phone number is 0123456789, my email address is aaa@bbb.com. Welcome to use multiline text editor component.");
        mmi_ucs2cpy((char *)singleline_string, (const char*)L"This singleline text editor DisableBackground test.");

        for (VfxS32 i = 0; i < 30; i ++)
        {
            mmi_ucs2cat((char *)multi_view_string, (const char*)L"The quick brown fox jumps over the lazy dog.");
            mmi_ucs2cat((char *)multi_editor_string, (const char*)L"The quick brown fox jumps over the lazy dog.");
        }

        // singleline text editor
        VFX_OBJ_CREATE(m_singlineEditor, VcpTextEditor, this);
        m_singlineEditor->setPos(VfxPoint(xPos, yPos));
        m_singlineEditor->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, TEXT_VIEW_SINGLELINE_HEIGHT));
        m_singlineEditor->setText(singleline_string, 200);
        m_singlineEditor->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
        m_singlineEditor->disableBackground(VFX_TRUE);

        yPos += TEXT_VIEW_GAP + TEXT_VIEW_SINGLELINE_HEIGHT;

        // multiline text view
        VFX_OBJ_CREATE(m_multilineView, VcpTextView, this);
        m_multilineView->setPos(VfxPoint(xPos, yPos));
        m_multilineView->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 3));
        m_multilineView->setText(multi_view_string);
        m_multilineView->disableBackground(VFX_FALSE);

        yPos += TEXT_VIEW_GAP + mainScreenSize.height / 3;

        // multiline text editor
        VFX_OBJ_CREATE(m_multilineEditor, VcpTextEditor, this);
        m_multilineEditor->setHint(VFX_WSTR("Please tap to input:"));
        m_multilineEditor->setPos(VfxPoint(xPos, yPos));
        m_multilineEditor->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 3);
        m_multilineEditor->setText(multi_editor_string, 2000);
        m_multilineEditor->disableBackground(VFX_TRUE);
    }

    void testSetIndent()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Indent test"));

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        mmi_ucs2cpy((char *)multi_view_string, (const char*)L"This multiline text view SetIndent test. 12345, a@g.com, 19415@sohu.com, www.123456432424.com, Hello, my name is Andy Liu, my phone number is 0123456789, my email address is aaa@bbb.com. Welcome to use richtext text view component.");
        mmi_ucs2cpy((char *)multi_editor_string, (const char*)L"This multiline text editor SetIndent test. Hello, my name is Andy Liu, my phone number is 0123456789, my email address is aaa@bbb.com. Welcome to use multiline text editor component.");
        mmi_ucs2cpy((char *)singleline_string, (const char*)L"This singleline text editor SetIndent test. ");

        for (VfxS32 i = 0; i < 30; i ++)
        {
            mmi_ucs2cat((char *)multi_view_string, (const char*)L"The quick brown fox jumps over the lazy dog.");
            mmi_ucs2cat((char *)multi_editor_string, (const char*)L"The quick brown fox jumps over the lazy dog.");
        }

        // singleline text editor
        VFX_OBJ_CREATE(m_singlineEditor, VcpTextEditor, this);
        m_singlineEditor->setPos(VfxPoint(xPos, yPos));
        m_singlineEditor->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, TEXT_VIEW_SINGLELINE_HEIGHT));
        m_singlineEditor->setText(singleline_string, 200);
        m_singlineEditor->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
     //   m_singlineEditor->setIndent(30);

        yPos += TEXT_VIEW_GAP + TEXT_VIEW_SINGLELINE_HEIGHT;

        // multiline text view
        VFX_OBJ_CREATE(m_multilineView, VcpTextView, this);
        m_multilineView->setPos(VfxPoint(xPos, yPos));
        m_multilineView->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 3));
        m_multilineView->setText(multi_view_string);
     //   m_multilineView->setIndent(30);

        yPos += TEXT_VIEW_GAP + mainScreenSize.height / 3;

        // multiline text editor
        VFX_OBJ_CREATE(m_multilineEditor, VcpTextEditor, this);
        m_multilineEditor->setHint(VFX_WSTR("Please tap to input:"));
        m_multilineEditor->setPos(VfxPoint(xPos, yPos));
        m_multilineEditor->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 3);
        m_multilineEditor->setText(multi_editor_string, 2000);
      //  m_multilineEditor->setIndent(30);
    }

    void testAutoResize()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Auto resize test"));

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        mmi_ucs2cpy((char *)multi_view_string, (const char*)L"Multiline text view\n");
        mmi_ucs2cpy((char *)multi_editor_string, (const char*)L"Multiline text editor\n");
        mmi_ucs2cpy((char *)singleline_string, (const char*)L"Singleline text editor");

        for (VfxS32 i = 0; i < 30; i ++)
        {
            mmi_ucs2cat((char *)multi_view_string, (const char*)L"The quick brown fox jumps over the lazy dog.");
            mmi_ucs2cat((char *)multi_editor_string, (const char*)L"The quick brown fox jumps over the lazy dog.");
        }

        // singleline text editor
        VFX_OBJ_CREATE(m_singlineEditor, VcpTextEditor, this);
        m_singlineEditor->setPos(VfxPoint(xPos, yPos));
        m_singlineEditor->setText(singleline_string, 200);
        m_singlineEditor->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
        m_singlineEditor->setAutoResized(VFX_TRUE, -1, mainScreenSize.width - 2 * TEXT_VIEW_GAP);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif   
        yPos += TEXT_VIEW_GAP + TEXT_VIEW_SINGLELINE_HEIGHT;//+ mainScreenSize.height / 3;

        // multiline text editor
        mmi_ucs2cpy((char *)multi_editor_string, (const char*)L"This is multiline text editor auto resize test");
        VFX_OBJ_CREATE(m_multilineEditor, VcpTextEditor, this);
        m_multilineEditor->setPos(VfxPoint(xPos, yPos));
        m_multilineEditor->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 3);
        m_multilineEditor->setText(multi_editor_string, 2000);
        m_multilineEditor->setAutoResized(VFX_TRUE, -1, mainScreenSize.height / 3);

    }

    void testAutoFontSize()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Auto font size test"));

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        mmi_ucs2cpy((char *)multi_editor_string, (const char*)L"Auto font size test");

        // multiline text editor
        VFX_OBJ_CREATE(m_multilineEditor, VcpTextEditor, this);
        m_multilineEditor->setPos(VfxPoint(xPos, yPos));
        m_multilineEditor->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 4);
        m_multilineEditor->setText(multi_editor_string, 2000);
        m_multilineEditor->setAutoFontSize(VFX_TRUE);

        VfxFontDesc font;
        font.size = VFX_FONT_DESC_VF_SIZE(50);
        m_multilineEditor->setFont(font);

        yPos += mainScreenSize.height / 4 + TEXT_VIEW_GAP;
        // singleline text editor
        VFX_OBJ_CREATE(m_singlineEditor, VcpTextEditor, this);
        m_singlineEditor->setPos(VfxPoint(xPos, yPos));
        m_singlineEditor->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, TEXT_VIEW_SINGLELINE_HEIGHT));
        m_singlineEditor->setText(multi_editor_string, 200);
        m_singlineEditor->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
        m_singlineEditor->setAutoFontSize(VFX_TRUE);
        m_singlineEditor->setAlignMode(VCP_TEXT_ALIGN_MODE_RIGHT);

        VfxFontDesc font1;
        font1.size = VFX_FONT_DESC_VF_SIZE(25);
        m_singlineEditor->setFont(font1);
    }

    void testSetHint()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Hint test"));

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        mmi_ucs2cpy((char *)multi_view_string, (const char*)L"12345, a@g.com, 19415@sohu.com, www.123456432424.com, Hello, my name is Andy Liu, my phone number is 0123456789, my email address is aaa@bbb.com. Welcome to use richtext text view component.");
        mmi_ucs2cpy((char *)multi_editor_string, (const char*)L"Hello, my name is Andy Liu, my phone number is 0123456789, my email address is aaa@bbb.com. Welcome to use multiline text editor component.");
        mmi_ucs2cpy((char *)singleline_string, (const char*)L"Hello, my name is Andy Liu, my phone number is 0123456789, my ema");

        for (VfxS32 i = 0; i < 30; i ++)
        {
            mmi_ucs2cat((char *)multi_view_string, (const char*)L"The quick brown fox jumps over the lazy dog.");
            mmi_ucs2cat((char *)multi_editor_string, (const char*)L"The quick brown fox jumps over the lazy dog.");
        }

        // singleline text editor
        VFX_OBJ_CREATE(m_singlineEditor, VcpTextEditor, this);
        m_singlineEditor->setPos(VfxPoint(xPos, yPos));
        m_singlineEditor->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, TEXT_VIEW_SINGLELINE_HEIGHT));
        m_singlineEditor->setText(singleline_string, 200);
        m_singlineEditor->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
      //  m_singlineEditor->setHint(VFX_WSTR("Singleline editor hint"));
        m_singlineEditor->setHint(VFX_WSTR_EMPTY);

        yPos += TEXT_VIEW_GAP + TEXT_VIEW_SINGLELINE_HEIGHT;

        // multiline text editor
        VFX_OBJ_CREATE(m_multilineEditor, VcpTextEditor, this);
        m_multilineEditor->setPos(VfxPoint(xPos, yPos));
        m_multilineEditor->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 3);
        m_multilineEditor->setText(multi_editor_string, 2000);
        m_multilineEditor->setHint(VFX_WSTR("Multiline editor hint:"));
    }

    void testSetMargins()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Margin test"));

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        mmi_ucs2cpy((char *)multi_editor_string, (const char*)L"Hello, my name is Andy Liu, my phone number is 0123456789, my email address is aaa@bbb.com. Welcome to use multiline text editor component.");
        mmi_ucs2cpy((char *)singleline_string, (const char*)L"Hello, my name is Andy Liu, my phone number is 0123456789, my ema");

        for (VfxS32 i = 0; i < 30; i ++)
        {
            mmi_ucs2cat((char *)multi_editor_string, (const char*)L"The quick brown fox jumps over the lazy dog.");
        }

        // singleline text editor
        VFX_OBJ_CREATE(m_singlineEditor, VcpTextEditor, this);
        m_singlineEditor->setPos(VfxPoint(xPos, yPos));
        m_singlineEditor->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, TEXT_VIEW_SINGLELINE_HEIGHT));
        m_singlineEditor->setText(singleline_string, 200);
        m_singlineEditor->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
        m_singlineEditor->setMargins(30, 0, 0, 0);

        yPos += TEXT_VIEW_GAP + TEXT_VIEW_SINGLELINE_HEIGHT;

        // multiline text editor
        VFX_OBJ_CREATE(m_multilineEditor, VcpTextEditor, this);
        m_multilineEditor->setPos(VfxPoint(xPos, yPos));
        m_multilineEditor->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 3);
        m_multilineEditor->setText(multi_editor_string, 2000);
        m_multilineEditor->setMargins(30, 30, 30, 30);
    }

    void testSetMarginFrame()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Margin frame test"));

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        mmi_ucs2cpy((char *)multi_editor_string, (const char*)L"Hello, my name is Andy Liu, my phone number is 0123456789, my email address is aaa@bbb.com. Welcome to use multiline text editor component.");
        mmi_ucs2cpy((char *)singleline_string, (const char*)L"Hello, my name is Andy Liu, my phone number is 0123456789, my ema");

        for (VfxS32 i = 0; i < 30; i ++)
        {
            mmi_ucs2cat((char *)multi_editor_string, (const char*)L"The quick brown fox jumps over the lazy dog.");
        }

        // search icon image
        VfxImageFrame *m_iconHint;
        VFX_OBJ_CREATE(m_iconHint, VfxImageFrame, this);
        m_iconHint->setResId(IMG_GLOBAL_L1);
 
        // singleline text editor
        VFX_OBJ_CREATE(m_singlineEditor, VcpTextEditor, this);
        m_singlineEditor->setPos(VfxPoint(xPos, yPos));
        m_singlineEditor->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, TEXT_VIEW_SINGLELINE_HEIGHT));
        m_singlineEditor->setText(singleline_string, 200);
        m_singlineEditor->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
        m_singlineEditor->setHint(VFX_WSTR("Search..."));
        m_singlineEditor->setMarginFrame(VCP_TEXT_MARGIN_FRAME_LEFT, m_iconHint);

        yPos += TEXT_VIEW_GAP + TEXT_VIEW_SINGLELINE_HEIGHT;

        // search icon image
        VfxImageFrame *m_iconHint1;
        VFX_OBJ_CREATE(m_iconHint1, VfxImageFrame, this);
        m_iconHint1->setResId(IMG_GLOBAL_L1);

        // multiline text editor
        VFX_OBJ_CREATE(m_multilineEditor, VcpTextEditor, this);
        m_multilineEditor->setPos(VfxPoint(xPos, yPos));
        m_multilineEditor->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 3);
        m_multilineEditor->setText(multi_editor_string, 2000);
        m_multilineEditor->setMarginFrame(VCP_TEXT_MARGIN_FRAME_RIGHT, m_iconHint1);
    }

    void testProgress()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Progress inputbox test"));

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        mmi_ucs2cpy((char *)multi_editor_string, (const char*)L"Hello, my name is Andy Liu, my phone number is 0123456789, my email address is aaa@bbb.com. Welcome to use multiline text editor component.");
        mmi_ucs2cpy((char *)singleline_string, (const char*)L"Hello, my name is Andy Liu, my phone number is 0123456789, my email address is aaa@bbb.com. ");

        for (VfxS32 i = 0; i < 30; i ++)
        {
            mmi_ucs2cat((char *)multi_editor_string, (const char*)L"The quick brown fox jumps over the lazy dog.");
        }

        m_progressValue = 0;

        // singleline text editor
        VFX_OBJ_CREATE(m_singlineEditor, VcpTextEditor, this);
        m_singlineEditor->setPos(VfxPoint(xPos, yPos));
        m_singlineEditor->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, TEXT_VIEW_SINGLELINE_HEIGHT));
        m_singlineEditor->setText(singleline_string, 200);
        m_singlineEditor->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
        m_singlineEditor->setHint(VFX_WSTR("Search..."));

        yPos += TEXT_VIEW_GAP + TEXT_VIEW_SINGLELINE_HEIGHT;

        // multiline text editor
        VFX_OBJ_CREATE(m_multilineEditor, VcpTextEditor, this);
        m_multilineEditor->setPos(VfxPoint(xPos, yPos));
        m_multilineEditor->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 4);
        m_multilineEditor->setText(multi_editor_string, 2000);

        // start a timer to update progress
        VFX_OBJ_CREATE(m_progressTimer, VfxTimer, this);
        m_progressTimer->setStartDelay(100);
        m_progressTimer->m_signalTick.connect(this, &VtstRtTextView::onProgress);
        m_progressTimer->start();
    }

    void onProgress(VfxTimer *timer)
    {
        VFX_UNUSED(timer);

        if (m_multilineEditor)  
        {
            m_multilineEditor->setProgressValue(m_progressValue);
        }
        if (m_singlineEditor)
        {
            m_singlineEditor->setProgressValue(m_progressValue);
        }

        m_progressValue = (VfxFloat)(m_progressValue + 0.01);

        if (m_progressValue > 1)
        {
            m_progressValue = 0;
        }
        m_progressTimer->start();
    }

    void testSetTruncate()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Truncate test"));

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        mmi_ucs2cpy((char *)multi_view_string, (const char*)L"12345, a@g.com, 19415@sohu.com, www.123456432424.com, Hello, my name is Andy Liu, my phone number is 0123456789, my email address is aaa@bbb.com. Welcome to use richtext text view component.");
        mmi_ucs2cpy((char *)singleline_string, (const char*)L"Hello, my name is Andy Liu, my phone number is 0123456789, my email address is aaa@bbb.com.");

        for (VfxS32 i = 0; i < 30; i ++)
        {
            mmi_ucs2cat((char *)multi_view_string, (const char*)L"The quick brown fox jumps over the lazy dog.");
        }

        // singleline editor
        VFX_OBJ_CREATE(m_singlelineView, VcpTextView, this);
        m_singlelineView->setPos(VfxPoint(xPos, yPos));
        m_singlelineView->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, TEXT_VIEW_SINGLELINE_HEIGHT));
        m_singlelineView->setText(singleline_string);
        m_singlelineView->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
        m_singlelineView->setTruncateMode(VCP_TEXT_TRUNCATE_MODE_END);

        yPos += TEXT_VIEW_SINGLELINE_HEIGHT + TEXT_VIEW_GAP;
        // multiline text view
        VFX_OBJ_CREATE(m_multilineView, VcpTextView, this);
        m_multilineView->setPos(VfxPoint(xPos, yPos));
        m_multilineView->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 2));
        m_multilineView->setText(multi_view_string);
        m_multilineView->setTruncateMode(VCP_TEXT_TRUNCATE_MODE_END);
    }

    void testCustomFrame()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Custom frame test"));

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        mmi_ucs2cpy((char *)multi_view_string, (const char*)L"This is text under custom frame\n");
        for (VfxS32 i = 0; i < 30; i ++)
        {
            mmi_ucs2cat((char *)multi_view_string, (const char*)L"The quick brown fox jumps over the lazy dog.");
        }

        VfxTextFrame *textFrame;
        VFX_OBJ_CREATE(textFrame, VfxTextFrame, m_multilineView);
        textFrame->setString(VFX_WSTR("Middle Frame, the frame above the content"));
        textFrame->setPos(VfxPoint(0, 0));
        textFrame->setSize(mainScreenSize.width / 2, 0);
        textFrame->setColor(VFX_COLOR_BLACK);
        textFrame->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
        textFrame->setBgColor(VFX_COLOR_YELLOW);

        VfxTextFrame *textFrameBottom;
        VFX_OBJ_CREATE(textFrameBottom, VfxTextFrame, m_multilineView);
        textFrameBottom->setString(VFX_WSTR("Right Frame"));
        textFrameBottom->setPos(VfxPoint(0, 0));
        textFrameBottom->setColor(VFX_COLOR_BLACK);
        textFrameBottom->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
        textFrameBottom->setBgColor(VFX_COLOR_GREY);

        VcpRichTextCustomFrame customFrame;
        customFrame.setFrame(textFrame);
        customFrame.setRange(0, 0);
        customFrame.setObjectAttribute(VCP_RICH_TEXT_OBJ_ARRT_MID_ALIGN);

        VcpRichTextCustomFrame customFrameBottom;
        customFrameBottom.setFrame(textFrameBottom);
        VfxS32 strLength = mmi_ucs2strlen((const char*)multi_view_string);
        customFrameBottom.setRange(strLength, strLength);
        customFrameBottom.setObjectAttribute(VCP_RICH_TEXT_OBJ_ARRT_RIGHT_ALIGN);
 
        // multiline text view
        VFX_OBJ_CREATE(m_multilineView, VcpTextView, this);
        m_multilineView->setPos(VfxPoint(xPos, yPos));
        m_multilineView->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 2)); 
        m_multilineView->setText(multi_view_string);
        m_multilineView->addTextFormat(customFrame); 
        m_multilineView->addTextFormat(customFrameBottom); 
    }

    void testAlignment()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Alignment test"));

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        mmi_ucs2cpy((char *)multi_view_string, (const char*)L"Alignment test\nAlignment test");

        // Vertical alignment
        VFX_OBJ_CREATE(m_multilineEditor, VcpTextEditor, this);
        m_multilineEditor->setPos(VfxPoint(xPos, yPos));
        m_multilineEditor->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 3));
        m_multilineEditor->setText(multi_view_string, 100);
        m_multilineEditor->setAlignMode(VCP_TEXT_ALIGN_MODE_RIGHT);
        m_multilineEditor->setVerticalAlignMode(VCP_TEXT_VERT_ALIGN_MODE_BOTTOM);

        yPos += mainScreenSize.height / 3 + TEXT_VIEW_GAP;
        
        // horizontal alignment
        VFX_OBJ_CREATE(m_multilineView, VcpTextView, this);
        m_multilineView->setPos(VfxPoint(xPos, yPos));
        m_multilineView->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 3));
        m_multilineView->setText(multi_view_string);
        m_multilineView->setAlignMode(VCP_TEXT_ALIGN_MODE_RIGHT);
    }

    void testEncoding()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Test Encoding"));

        VfxS32 xPos, yPos;
        VfxS32 height = 40;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        VFX_OBJ_CREATE(m_editors[0], VcpTextEditor, this);
        m_editors[0]->setPos(VfxPoint(xPos, yPos));
        m_editors[0]->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, height);
        m_editors[0]->setText(VFX_WSTR("GB2312 encoding"), 20, VFX_FALSE, VCP_TEXT_ENCODING_GB2312);

        yPos += height + TEXT_VIEW_GAP;
        VFX_OBJ_CREATE(m_editors[1], VcpTextEditor, this);
        m_editors[1]->setPos(VfxPoint(xPos, yPos));
        m_editors[1]->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, height);
        m_editors[1]->setText(VFX_WSTR("+12345678901234567890"), 20);
        m_editors[1]->setIME(IMM_INPUT_TYPE_PHONE_NUMBER, IME_PLUS_CHAR_HANDLING);

        yPos += height + TEXT_VIEW_GAP;
        VFX_OBJ_CREATE(m_editors[2], VcpTextEditor, this);
        m_editors[2]->setPos(VfxPoint(xPos, yPos));
        m_editors[2]->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, height);
        m_editors[2]->setText(VFX_WSTR("0x81 encoding"), 20, VFX_FALSE, VCP_TEXT_ENCODING_0X81);

        yPos += height + TEXT_VIEW_GAP;
        VFX_OBJ_CREATE(m_editors[3], VcpTextEditor, this);
        m_editors[3]->setPos(VfxPoint(xPos, yPos));
        m_editors[3]->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, height);
        m_editors[3]->setText(VFX_WSTR("ASCII based encoding"), 20, VFX_FALSE, VCP_TEXT_ENCODING_ASCII);

        yPos += height + TEXT_VIEW_GAP;
        VFX_OBJ_CREATE(m_editors[4], VcpTextEditor, this);
        m_editors[4]->setPos(VfxPoint(xPos, yPos));
        m_editors[4]->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, height);
        m_editors[4]->setText(VFX_WSTR("GSM based encoding"), 20, VFX_FALSE, VCP_TEXT_ENCODING_GSM);
    }

    void testCalculator()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Calculator APP test"));

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        VFX_OBJ_CREATE(m_multilineEditor, VcpTextEditor, this);

        VfxColor m_calcColor(255, 28, 28, 28);
        VfxFontDesc m_calcFont;
        m_calcFont.size = VFX_FONT_DESC_VF_SIZE(50);
        m_calcFont.effect |= VFX_FE1_9;

        m_multilineEditor->setText(VFX_WSTR_EMPTY, 72);
        m_multilineEditor->setPos(23, 21 + 24);
        m_multilineEditor->setBounds(VfxRect(0, 0, 274, 124));
        m_multilineEditor->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
        m_multilineEditor->setAlignMode(VCP_TEXT_ALIGN_MODE_RIGHT);
        m_multilineEditor->setVerticalAlignMode(VCP_TEXT_VERT_ALIGN_MODE_BOTTOM);
        m_multilineEditor->setIME(IME_SETTING_FLAG_NONE);
        m_multilineEditor->activate();
        m_multilineEditor->setDisableClipboard(VFX_TRUE);
        m_multilineEditor->disableBackground(VFX_TRUE);
        m_multilineEditor->hideCounter(VFX_TRUE);
        m_multilineEditor->setAutoFontSize(VFX_TRUE);
        m_multilineEditor->setHint(VFX_WSTR(""));
        m_multilineEditor->setFont(m_calcFont);
        m_multilineEditor->setColor(VCP_TEXT_NORMAL_TEXT_COLOR,m_calcColor);
    }

    void testMessageView()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Message view App test"));

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        mmi_ucs2cpy((char *)multi_view_string, (const char*)L"123456Hello Andy, this is Jacky from China, please call me back when you have time.\nmy phone number is 123456789,\nmy email address is Jacky@sohu.com. \nWelcome to visit my personal page: www.mediatek.com");

        VfxTextFrame *textFrame;
        VFX_OBJ_CREATE(textFrame, VfxTextFrame, m_multilineView);
        textFrame->setString(VFX_WSTR("From Jacky (13800180000)"));
        textFrame->setPos(VfxPoint(0, 0));
        textFrame->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, 0);
        textFrame->setColor(VFX_COLOR_BLACK);
        textFrame->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
        textFrame->setBgColor(VFX_COLOR_YELLOW);

        VfxTextFrame *textFrameBottom;
        VFX_OBJ_CREATE(textFrameBottom, VfxTextFrame, m_multilineView);
        textFrameBottom->setString(VFX_WSTR("Data time\n2010/10/31 18:30"));
        textFrameBottom->setPos(VfxPoint(0, 0));
        textFrameBottom->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, 0);
        textFrameBottom->setColor(VFX_COLOR_BLACK);
        textFrameBottom->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
        textFrameBottom->setBgColor(VFX_COLOR_GREY);

        VcpRichTextCustomFrame customFrame;
        customFrame.setFrame(textFrame);
        customFrame.setRange(0, 0);
        customFrame.setObjectAttribute(VCP_RICH_TEXT_OBJ_ARRT_MID_ALIGN);

        VcpRichTextCustomFrame customFrameBottom;
        customFrameBottom.setFrame(textFrameBottom);
        VfxS32 strLength = mmi_ucs2strlen((const char*)multi_view_string);
        customFrameBottom.setRange(strLength, strLength);
        customFrameBottom.setObjectAttribute(VCP_RICH_TEXT_OBJ_ARRT_RIGHT_ALIGN);
 
        // multiline text view
        VFX_OBJ_CREATE(m_multilineView, VcpTextView, this);
        m_multilineView->setPos(VfxPoint(xPos, yPos));
        m_multilineView->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 2)); 
        m_multilineView->setText(multi_view_string);
        m_multilineView->setKeyword(VCP_TEXT_KEYWORD_EMAIL | VCP_TEXT_KEYWORD_URL | VCP_TEXT_KEYWORD_PHONENUMBER | VCP_TEXT_KEYWORD_USSD);
        m_multilineView->addTextFormat(customFrame); 
        m_multilineView->addTextFormat(customFrameBottom); 
        m_multilineView->m_signalKeywordClick.connect(this, &VtstRtTextView::onKeywordClicked);
        m_multilineView->m_signalTapEvent.connect(this, &VtstRtTextView::onTapEvent);
    }

    void onTapEvent(VcpTextView *view, VcpTextTapAreaEnum tapArea, VcpRichTextFormat *format)
    {
        switch (tapArea)
        {
            case VCP_TEXT_TAP_AREA_TEXT:
                break;
            case VCP_TEXT_TAP_AREA_OBJECT:
                break;
            default:
                break;
        }
    }

    void testFunctionBar()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Test Function bar"));

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        // multiline text editor
        mmi_ucs2cpy((char *)multi_editor_string, (const char*)L"This is function bar test test.");
        VFX_OBJ_CREATE(m_multilineEditor, VcpTextEditor, this);
        m_multilineEditor->setPos(VfxPoint(xPos, yPos));
        m_multilineEditor->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 2);
        m_multilineEditor->setText(multi_editor_string, 2000);

        VFX_OBJ_CREATE(m_testFrame, VcpFunctionBar, this);
        m_testFrame->addItem(0, VFX_WSTR("Select"));
        m_testFrame->addItem(1, VFX_WSTR("Remove"));
        m_testFrame->addItem(2, VFX_WSTR("Send"));
        m_testFrame->setItemSpecial(2);
        m_testFrame->setBgColor(VfxColor(VFX_COLOR_BLACK));
        m_multilineEditor->setFunctionBar(m_testFrame);
    }

    void testDetailView()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Test Detail view"));

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        // multiline text view
        multi_view_string[0] = 0;

        VFX_OBJ_CREATE(m_multilineView, VcpTextView, this);
        m_multilineView->setPos(VfxPoint(xPos, yPos));
        m_multilineView->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, 0));
        m_multilineView->setAutoResized(VFX_TRUE);
        // use static buffer (isStaticBuf = VFX_TRUE) for detail buffer 
        // because we need to cat the buffer together for view
        // Please DO NOT use temp buffer
        m_multilineView->setText(multi_view_string, VFX_TRUE);

        m_multilineView->addDetail(VFX_WSTR("Name\n"), VCP_TEXT_DETAIL_TITLE, 1000);
        m_multilineView->addDetail(VFX_WSTR("This is a long file name 523949-1i2321i242\n"), VCP_TEXT_DETAIL_CONTENT, 1000);
        m_multilineView->addDetail(VFX_WSTR("Type\n"), VCP_TEXT_DETAIL_TITLE, 1000);
        m_multilineView->addDetail(VFX_WSTR("Jpg file\n"), VCP_TEXT_DETAIL_CONTENT, 1000);
        m_multilineView->addDetail(VFX_WSTR("Size\n"), VCP_TEXT_DETAIL_TITLE, 1000);
        m_multilineView->addDetail(VFX_WSTR("100 KB\n"), VCP_TEXT_DETAIL_CONTENT, 1000);
        m_multilineView->addDetail(VFX_WSTR("Create Time\n"), VCP_TEXT_DETAIL_TITLE, 1000);
        m_multilineView->addDetail(VFX_WSTR("2010-08-13 17:04:16\n"), VCP_TEXT_DETAIL_CONTENT, 1000);
        m_multilineView->addDetail(VFX_WSTR("Edit Time\n"), VCP_TEXT_DETAIL_TITLE, 1000);
        m_multilineView->addDetail(VFX_WSTR("2010-08-14 10:04:16\n"), VCP_TEXT_DETAIL_CONTENT, 1000);
        m_multilineView->addDetail(VFX_WSTR("Copy right\n"), VCP_TEXT_DETAIL_TITLE, 1000);
        m_multilineView->addDetail(VFX_WSTR("No project\n"), VCP_TEXT_DETAIL_CONTENT, 1000);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
    }

    void testLanguages()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Languages test"));

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        mmi_ucs2cpy((char *)multi_editor_string, (const char*)L"This is language test.");

        // multiline text editor
        VFX_OBJ_CREATE(m_multilineEditor, VcpTextEditor, this);
        m_multilineEditor->setHint(VFX_WSTR("Please tap to input:"));
        m_multilineEditor->setPos(VfxPoint(xPos, yPos));
        m_multilineEditor->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 4);
        m_multilineEditor->setText(multi_editor_string, 2000, VFX_TRUE);
        m_multilineEditor->hideCounter(VFX_TRUE);

        yPos += TEXT_VIEW_GAP + mainScreenSize.height / 4;

        VFX_OBJ_CREATE(m_convertButton, VcpButton, this);
        m_convertButton->setText(VFX_WSTR("Convert to viewer"));
        m_convertButton->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_convertButton->setPos(VfxPoint(xPos, yPos));
        m_convertButton->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, 40);
        m_convertButton->m_signalClicked.connect(this, &VtstRtTextView::onConvertButtonClick);

        yPos += TEXT_VIEW_GAP + 40;

        // multiline text view
        VFX_OBJ_CREATE(m_multilineView, VcpTextView, this);
        m_multilineView->setPos(VfxPoint(xPos, yPos));
        m_multilineView->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 3));
        m_multilineView->setText(multi_editor_string);
    }

    void onConvertButtonClick(VfxObject* sender, VfxId id)
    {
        m_multilineView->setText(multi_editor_string);
        m_multilineView->setKeyword(VCP_TEXT_KEYWORD_EMAIL | VCP_TEXT_KEYWORD_URL | VCP_TEXT_KEYWORD_PHONENUMBER | VCP_TEXT_KEYWORD_USSD);
        m_multilineView->forceUpdate();
    }

    void testWrapStyle()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Test wrap style"));

        VfxS32 xPos, yPos;
        VfxS32 height = mainScreenSize.height / 3;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        VFX_OBJ_CREATE(m_editors[0], VcpTextEditor, this);
        m_editors[0]->setPos(VfxPoint(xPos, yPos));
        m_editors[0]->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, height);
        m_editors[0]->setText(VFX_WSTR("This is word wrapping style, text editor/text view will use word wrap as default."), 200);
     //   m_editors[0]->setTextWrapStyle(VCP_TEXT_WRAP_WORD_WRAP);

        yPos += height + TEXT_VIEW_GAP;
        VFX_OBJ_CREATE(m_editors[1], VcpTextEditor, this);
        m_editors[1]->setPos(VfxPoint(xPos, yPos));
        m_editors[1]->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, height);
        m_editors[1]->setText(VFX_WSTR("This is character wrapping style, application need to set this style if they want character wrapping style"), 200);
        m_editors[1]->setTextWrapStyle(VCP_TEXT_WRAP_CHARACTER_WRAP);
    }

    void testIME1()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Test IME - 1"));

        VfxS32 xPos, yPos;
        VfxS32 height = mainScreenSize.height * 3 / 4;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        VcpFormItemTextInput *textInput;

        VFX_OBJ_CREATE(m_form, VcpForm, this);
        m_form->setPos(xPos, yPos);
        m_form->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, height);
        m_form->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE,
                        VFX_FRAME_ALIGNER_MODE_SIDE);

        VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
        textInput->setLabelText(VFX_WSTR("IMM_INPUT_TYPE_NUMERIC"));
        textInput->setLabelPosition(VCPFORM_TOP_LEFT);
        textInput->getTextBox()->setIME(IMM_INPUT_TYPE_NUMERIC);
        m_form->addItem(textInput, IMM_INPUT_TYPE_NUMERIC);

        VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
        textInput->setLabelText(VFX_WSTR("IMM_INPUT_TYPE_PHONE_NUMBER"));
        textInput->setLabelPosition(VCPFORM_TOP_LEFT);
        textInput->getTextBox()->setIME(IMM_INPUT_TYPE_PHONE_NUMBER);
        m_form->addItem(textInput, IMM_INPUT_TYPE_PHONE_NUMBER);
        
        VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
        textInput->setLabelText(VFX_WSTR("IMM_INPUT_TYPE_DECIMAL_NUMERIC"));
        textInput->setLabelPosition(VCPFORM_TOP_LEFT);
        textInput->getTextBox()->setIME(IMM_INPUT_TYPE_DECIMAL_NUMERIC);
        m_form->addItem(textInput, IMM_INPUT_TYPE_DECIMAL_NUMERIC);

        VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
        textInput->setLabelText(VFX_WSTR("IMM_INPUT_TYPE_SIGNED_NUMERIC"));
        textInput->setLabelPosition(VCPFORM_TOP_LEFT);
        textInput->getTextBox()->setIME(IMM_INPUT_TYPE_SIGNED_NUMERIC);
        m_form->addItem(textInput, IMM_INPUT_TYPE_SIGNED_NUMERIC);

        VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
        textInput->setLabelText(VFX_WSTR("IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC"));
        textInput->setLabelPosition(VCPFORM_TOP_LEFT);
        textInput->getTextBox()->setIME(IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC);
        m_form->addItem(textInput, IMM_INPUT_TYPE_SIGNED_DECIMAL_NUMERIC);

        VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
        textInput->setLabelText(VFX_WSTR("IMM_INPUT_TYPE_URL"));
        textInput->setLabelPosition(VCPFORM_TOP_LEFT);
        textInput->getTextBox()->setIME(IMM_INPUT_TYPE_URL);
        m_form->addItem(textInput, IMM_INPUT_TYPE_URL);
    }

    void testIME2()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Test IME - 2"));

        VfxS32 xPos, yPos;
        VfxS32 height = mainScreenSize.height * 3 / 4;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        VcpFormItemTextInput *textInput;

        VFX_OBJ_CREATE(m_form, VcpForm, this);
        m_form->setPos(xPos, yPos);
        m_form->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, height);
        m_form->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE,
                        VFX_FRAME_ALIGNER_MODE_SIDE);

        VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
        textInput->setLabelText(VFX_WSTR("IMM_INPUT_TYPE_QUICK_SEARCH"));
        textInput->setLabelPosition(VCPFORM_TOP_LEFT);
        textInput->getTextBox()->setIME(IMM_INPUT_TYPE_QUICK_SEARCH);
        m_form->addItem(textInput, IMM_INPUT_TYPE_QUICK_SEARCH);

        VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
        textInput->setLabelText(VFX_WSTR("IMM_INPUT_TYPE_SENTENCE"));
        textInput->setLabelPosition(VCPFORM_TOP_LEFT);
        textInput->getTextBox()->setIME(IMM_INPUT_TYPE_SENTENCE);
        m_form->addItem(textInput, IMM_INPUT_TYPE_SENTENCE);

        VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
        textInput->setLabelText(VFX_WSTR("IMM_INPUT_TYPE_ENGLISH_SENTENCE"));
        textInput->setLabelPosition(VCPFORM_TOP_LEFT);
        textInput->getTextBox()->setIME(IMM_INPUT_TYPE_ENGLISH_SENTENCE);
        m_form->addItem(textInput, IMM_INPUT_TYPE_ENGLISH_SENTENCE);

        VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
        textInput->setLabelText(VFX_WSTR("IMM_INPUT_TYPE_KEYPAD_NUMERIC"));
        textInput->setLabelPosition(VCPFORM_TOP_LEFT);
        textInput->getTextBox()->setIME(IMM_INPUT_TYPE_KEYPAD_NUMERIC);
        m_form->addItem(textInput, IMM_INPUT_TYPE_KEYPAD_NUMERIC);

        VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
        textInput->setLabelText(VFX_WSTR("IMM_INPUT_TYPE_SIM_NUMERIC"));
        textInput->setLabelPosition(VCPFORM_TOP_LEFT);
        textInput->getTextBox()->setIME(IMM_INPUT_TYPE_SIM_NUMERIC);
        m_form->addItem(textInput, IMM_INPUT_TYPE_SIM_NUMERIC);

        VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
        textInput->setLabelText(VFX_WSTR("IMM_INPUT_TYPE_ENGLISH_SENTENCE_UPPERCASE"));
        textInput->setLabelPosition(VCPFORM_TOP_LEFT);
        textInput->getTextBox()->setIME(IMM_INPUT_TYPE_ENGLISH_SENTENCE_UPPERCASE);
        m_form->addItem(textInput, IMM_INPUT_TYPE_ENGLISH_SENTENCE_UPPERCASE);
    }

    void testIME3()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Test IME - 3"));

        VfxS32 xPos, yPos;
        VfxS32 height = mainScreenSize.height * 3 / 4;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        VcpFormItemTextInput *textInput;

        VFX_OBJ_CREATE(m_form, VcpForm, this);
        m_form->setPos(xPos, yPos);
        m_form->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, height);
        m_form->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE,
                        VFX_FRAME_ALIGNER_MODE_SIDE);

        VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
        textInput->setLabelText(VFX_WSTR("IMM_INPUT_TYPE_ENGLISH_SENTENCE_LOWERCASE"));
        textInput->setLabelPosition(VCPFORM_TOP_LEFT);
        textInput->getTextBox()->setIME(IMM_INPUT_TYPE_ENGLISH_SENTENCE_LOWERCASE);
        m_form->addItem(textInput, IMM_INPUT_TYPE_ENGLISH_SENTENCE_LOWERCASE);

        VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
        textInput->setLabelText(VFX_WSTR("IMM_INPUT_TYPE_EMAIL"));
        textInput->setLabelPosition(VCPFORM_TOP_LEFT);
        textInput->getTextBox()->setIME(IMM_INPUT_TYPE_EMAIL);
        m_form->addItem(textInput, IMM_INPUT_TYPE_EMAIL);

        VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
        textInput->setLabelText(VFX_WSTR("IMM_INPUT_TYPE_PHONE_NUMBER_WILDCHAR"));
        textInput->setLabelPosition(VCPFORM_TOP_LEFT);
        textInput->getTextBox()->setIME(IMM_INPUT_TYPE_PHONE_NUMBER_WILDCHAR);
        m_form->addItem(textInput, IMM_INPUT_TYPE_PHONE_NUMBER_WILDCHAR);

        VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
        textInput->setLabelText(VFX_WSTR("IMM_INPUT_TYPE_NUMERIC_SYMBOL"));
        textInput->setLabelPosition(VCPFORM_TOP_LEFT);
        textInput->getTextBox()->setIME(IMM_INPUT_TYPE_NUMERIC_SYMBOL);
        m_form->addItem(textInput, IMM_INPUT_TYPE_NUMERIC_SYMBOL);

        VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
        textInput->setLabelText(VFX_WSTR("IMM_INPUT_TYPE_ASCII_CHAR"));
        textInput->setLabelPosition(VCPFORM_TOP_LEFT);
        textInput->getTextBox()->setIME(IMM_INPUT_TYPE_ASCII_CHAR);
        m_form->addItem(textInput, IMM_INPUT_TYPE_ASCII_CHAR);
    }

    void testMagnifer()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("Magnifier&Clipboard test"));

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        // singleline text editor
        VFX_OBJ_CREATE(m_singlineEditor, VcpTextEditor, this);
        m_singlineEditor->setPos(VfxPoint(xPos, yPos));
        m_singlineEditor->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, TEXT_VIEW_SINGLELINE_HEIGHT));
        m_singlineEditor->setText(VFX_WSTR("This is magnifer & clipboard test, long tap to show magnifer, then long tap again to mark text"), 200);
        m_singlineEditor->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);

        yPos += TEXT_VIEW_GAP + TEXT_VIEW_SINGLELINE_HEIGHT;

        // multiline text view
        VFX_OBJ_CREATE(m_multilineView, VcpTextView, this);
        m_multilineView->setPos(VfxPoint(xPos, yPos));
        m_multilineView->setBounds(VfxRect(0, 0, mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 4));
        m_multilineView->setText(VFX_WSTR("This is magnifer & clipboard test, long tap to show magnifer, then long tap again to mark text"));

        yPos += TEXT_VIEW_GAP + mainScreenSize.height / 4;

        // multiline text editor
        VFX_OBJ_CREATE(m_multilineEditor, VcpTextEditor, this);
        m_multilineEditor->setHint(VFX_WSTR("Please tap to input:"));
        m_multilineEditor->setPos(VfxPoint(xPos, yPos));
        m_multilineEditor->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, mainScreenSize.height / 4);
        m_multilineEditor->setText(VFX_WSTR("This is magnifer & clipboard test, long tap to show magnifer, then long tap again to mark text"), 2000);

        yPos += TEXT_VIEW_GAP + mainScreenSize.height / 4;
        if (m_magnifierTestButton == NULL)
        {
            VFX_OBJ_CREATE(m_magnifierTestButton, VcpButton, this);
            m_magnifierTestButton->setText(VFX_WSTR("Default value"));
            m_magnifierTestButton->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
            m_magnifierTestButton->setPos(VfxPoint(xPos, yPos));
            m_magnifierTestButton->setSize(mainScreenSize.width - 2 * TEXT_VIEW_GAP, 40);
            m_magnifierTestButton->m_signalClicked.connect(this, &VtstRtTextView::onMagnifierTestButtonClick);
        }
    }

    void onMagnifierTestButtonClick(VfxObject* sender, VfxId id)
    {
        static VfxU8 i = 0;
        if (m_magnifierTestButton)
        {
            switch (i)
            {
                case 0:
                    testMagniferInternal(500, 500);
                    break;
                case 1:
                    testMagniferInternal(600, 800);
                    break;
                case 2:
                    testMagniferInternal(600, 1000);
                    break;
                case 3:
                    testMagniferInternal(800, 800);
                    break;
                case 4:
                    testMagniferInternal(900, 900);
                    break;
                case 5:
                    testMagniferInternal(1000, 1000);
                    break;
                case 6:
                    testMagniferInternal(1200, 1200);
                    break;
                case 7:
                    testMagniferInternal(1500, 1500);
                    break;
                case 8:
                    testMagniferInternal(600, 1500);
                    break;
                case 9:
                    testMagniferInternal(200, 1000);
                    break;
                case 10:
                    testMagniferInternal(300, 800);
                    break;
                default:
                    break;
            }
        }
        i++;

        if (i > 10)
        {
            i = 0;
        }
    }

    void testMagniferInternal(VfxS32 mTime, VfxS32 cTime)
    {
#if 0
/* under construction !*/
    #if VCP_TEXT_MAGNIFIER_SUPPORT
/* under construction !*/
    #endif
#endif
        VfxWString btnText;
        btnText.format("M Time: %d, C Time: %d", mTime, cTime);
        m_magnifierTestButton->setText(btnText);

        if (m_multilineView)
        {
            VFX_OBJ_CLOSE(m_multilineView);
        }
        if (m_multilineEditor)
        {
            VFX_OBJ_CLOSE(m_multilineEditor);
        }
        if (m_singlineEditor)
        {
            VFX_OBJ_CLOSE(m_singlineEditor);
        }
            
        testMagnifer();
    }

    void showTestMenu()
    {
        VFX_OBJ_CREATE(m_menu, VcpMenuPopup, this);
        m_menu->setTitle(VFX_WSTR("Select test case"));
        VfxS32 index = 0;
        m_menu->addItem(index++, VFX_WSTR("Over all test"));
        m_menu->addItem(index++, VFX_WSTR("Single line view test"));
        m_menu->addItem(index++, VFX_WSTR("Multi line view test"));
        m_menu->addItem(index++, VFX_WSTR("Single line editor test"));
        m_menu->addItem(index++, VFX_WSTR("Multi line editor test"));
        m_menu->addItem(index++, VFX_WSTR("Key word test"));
        m_menu->addItem(index++, VFX_WSTR("Rich text view test"));
        m_menu->addItem(index++, VFX_WSTR("Background test"));
        m_menu->addItem(index++, VFX_WSTR("Indent test"));
        m_menu->addItem(index++, VFX_WSTR("Auto resize test"));
        m_menu->addItem(index++, VFX_WSTR("Hint test"));
        m_menu->addItem(index++, VFX_WSTR("Margin test"));
        m_menu->addItem(index++, VFX_WSTR("Margin frame test"));
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        m_menu->m_signalMenuCallback.connect(this, &VtstRtTextView::menuCallack);
        m_menu->show(VFX_TRUE);
    }

    void VtstRtTextView::menuCallack(VcpMenuPopup* menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem* item)
    {
        if (event == VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
        {   
            // item selected
            runTest(item->getId());
            VFX_OBJ_CLOSE(m_menu);
        }
    }

    virtual VfxBool onKeyInput(VfxKeyEvent &event)
    {
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
            switch(event.keyCode)
            {
            case VFX_KEY_CODE_ARROW_LEFT:
                m_testIndex--;
                if (m_testIndex < 0)
                {
                    m_testIndex = 0;
                }
                runTest(m_testIndex);
                break;
            case VFX_KEY_CODE_ARROW_RIGHT:
                m_testIndex++;
                if (m_testIndex > TEXT_VIEW_TEST_FUNC_NUM)
                {
                    m_testIndex = TEXT_VIEW_TEST_FUNC_NUM;
                }
                runTest(m_testIndex);
                break;
            case VFX_KEY_CODE_SEND:
                showTestMenu();
                break;
            case VFX_KEY_CODE_0:
                m_testIndex = 0;
                runTest(0);
                break;
            case VFX_KEY_CODE_1:
                m_testIndex = 1;
                runTest(1);
                break;
            case VFX_KEY_CODE_2:
                m_testIndex = 2;
                runTest(2);
                break;
            case VFX_KEY_CODE_3:
                m_testIndex = 3;
                runTest(3);
                break;
            case VFX_KEY_CODE_4:
                m_testIndex = 4;
                runTest(4);
                break;
            case VFX_KEY_CODE_5:
                m_testIndex = 5;
                runTest(5);
                break;
            case VFX_KEY_CODE_6:
                m_testIndex = 6;
                runTest(6);
                break;
            case VFX_KEY_CODE_7:
                m_testIndex = 7;
                runTest(7);
                break;
            case VFX_KEY_CODE_8:
                m_testIndex = 8;
                runTest(8);
                break;
            case VFX_KEY_CODE_9:
                m_testIndex = 9;
                runTest(9);
                break;
            default:
                break;
            }
        }
        return VFX_FALSE;
    }

    void runAutoTest()
    {
        // TODO:
    }

    void runTest(VfxS32 i)
    {
        if (i < 0)
        {
            i = 0;
        }
        else if (i > TEXT_VIEW_TEST_FUNC_NUM)
        {
            i = TEXT_VIEW_TEST_FUNC_NUM;
        }
        closeTestObject();
        switch (i)
        {
        case 0:
            testOverall();
            break;
        case 1:
            testSinglelineView();
            break;
        case 2:
            testMultilineView();
            break;
        case 3:
            testSinglelineEditor();
            break;
        case 4:
            testMultilineEditor();
            break;
        case 5:
            testSetKeyword();
            break;
        case 6:
            testRichText();
            break;
        case 7:
            testDisableBackground();
            break;
        case 8:
            testSetIndent();
            break;
        case 9:
            testAutoResize();
            break;
        case 10:
            testSetHint();
            break;
        case 11:
            testSetMargins();
            break;
        case 12:
            testSetMarginFrame();
            break;
        case 13:
            testProgress();
            break;
        case 14:
            testSetTruncate();
            break;
        case 15:
            testIcon();
            break;
        case 16:
            testCustomFrame();
            break;
        case 17:
            testAlignment();
            break;
        case 18:
            testAutoFontSize();
            break;
        case 19:
            testEncoding();
            break;
        case 20:
            testCalculator();
            break;
        case 21:
            testMessageView();
            break;
        case 22:
            testFunctionBar();
            break;
        case 23:
            testDetailView();
            break;
        case 24:
            testLanguages();
            break;
        case 25:
            testWrapStyle();
            break;
        case 26:
            testIME1();
            break;
        case 27:
            testIME2();
            break;
        case 28:
            testIME3();
            break;
        case 29:
            testMagnifer();
            break;
        default:
            break;
        }
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Does it work?"));
        return -1;
    }

    virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    )
    {
        // do nothing
    }

    void closeTestObject()
    {
        if (m_multilineView)
        {
            VFX_OBJ_CLOSE(m_multilineView);
        }
        if (m_singlelineView)
        {
            VFX_OBJ_CLOSE(m_singlelineView);
        }
        if (m_multilineEditor)
        {
            VFX_OBJ_CLOSE(m_multilineEditor);
        }
        if (m_singlineEditor)
        {
            VFX_OBJ_CLOSE(m_singlineEditor);
        }
        if (m_progressTimer)
        {
            VFX_OBJ_CLOSE(m_progressTimer);
        }
        for (VfxS32 i = 0; i < TEXT_VIEW_TEST_EDITOR_NUM; i++)
        {
            VFX_OBJ_CLOSE(m_editors[i]);
        }

        if (m_convertButton)
        {
            VFX_OBJ_CLOSE(m_convertButton);
        }

        if (m_magnifierTestButton)
        {
            VFX_OBJ_CLOSE(m_magnifierTestButton);
        }

        if (m_form)
        {
            VFX_OBJ_CLOSE(m_form);
        }
    }

private:
    VcpTextView *m_multilineView;
    VcpTextView *m_singlelineView;
    VcpTextEditor *m_multilineEditor;
    VcpTextEditor *m_singlineEditor;
    VcpTextEditor* m_editors[TEXT_VIEW_TEST_EDITOR_NUM];
    VfxTimer *m_progressTimer;
    VfxFloat m_progressValue;
    VcpButton *m_prevButton;
    VcpButton *m_nextButton;
    VcpButton *m_convertButton;
    VcpButton *m_magnifierTestButton;
    VfxS32 m_testIndex;
    VcpFunctionBar *m_testFrame;
    VcpForm *m_form;
    VcpMenuPopup *m_menu;
};


/***************************************************************************** 
 * Contact selector Test Implementation
 *****************************************************************************/
class VtstRtContactSelector : public VtstRtScr
{
// Constructor / Destructor
public:
    VtstRtContactSelector()
    {
    }

    //virtual VfxFrameImeModeEnum getImeMode() {return VFX_FRAME_IME_MODE_SHIFT;}

public:
    virtual VfxFrameImeModeEnum getImeMode() {return VFX_FRAME_IME_MODE_SHIFT;}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        
        setTitle(VFX_WSTR("Contact selector test"));

        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
        VfxControl *box;
        VFX_OBJ_CREATE(box, VfxControl, this);
        box->setRect(VfxRect(0, TEST_VIEW_START_Y, mainScreenSize.width, mainScreenSize.height - TEST_VIEW_START_Y));
        box->setBgColor(VFX_COLOR_WHITE);

        testContactSelector();
    }

    virtual void onDeinit()
    {
        VtstRtScr::onDeinit();
        
        closeTestObject();
    }

    void testContactSelector()
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        VfxS32 xPos, yPos;
        xPos = TEST_VIEW_START_X;
        yPos = TEST_VIEW_START_Y;

        VFX_OBJ_CREATE(m_contactSelector, VcpContactSelector, this);
        m_contactSelector->setPos(xPos, 100);
        m_contactSelector->setBounds(VfxRect(0, 0, (mainScreenSize.width - 2 * TEXT_VIEW_GAP), 50));

        // set hint text
        m_contactSelector->setHintText(VFX_WSTR("To:"));

        // connect signal
        m_contactSelector->m_signalSearchButtonClicked.connect(this, &VtstRtContactSelector::csOnSearchButtonClicked);
        m_contactSelector->m_signalTextChanged.connect(this, &VtstRtContactSelector::csOnTextChanged);

        // Add contact
        m_contactSelector->add(VFX_WSTR("qwertyuioplkjhgfdsazxcvbnmasdfgh"), VFX_WSTR("12345"));
        m_contactSelector->add(VFX_WSTR("A"), VFX_WSTR("12345"));
        m_contactSelector->add(VFX_WSTR("AB"), VFX_WSTR("12345"));
        m_contactSelector->add(VFX_WSTR("ABC"), VFX_WSTR("12345"));
        m_contactSelector->add(VFX_WSTR("ABCD"), VFX_WSTR("12345"));
        m_contactSelector->add(VFX_WSTR("ABCDE"), VFX_WSTR("12345"));
        m_contactSelector->add(VFX_WSTR("Ken"), VFX_WSTR("12345"));
        m_contactSelector->add(VFX_WSTR("Ben"), VFX_WSTR("12345"));
        m_contactSelector->add(VFX_WSTR("Jack"), VFX_WSTR("12345"));
        m_contactSelector->add(VFX_WSTR("Mic"), VFX_WSTR("12345"));
        m_contactSelector->add(VFX_WSTR("David.Lee"), VFX_WSTR("12345"));
        m_contactSelector->add(VFX_WSTR("Jack.Chen"), VFX_WSTR("67890"));
        m_contactSelector->add(VFX_WSTR("Steven.Chen"), VFX_WSTR("13467890"));
        m_contactSelector->add(VFX_WSTR("ABCDEFGHOIPPOP"), VFX_WSTR("67890"));
        m_contactSelector->add(VFX_WSTR("QWERTYUIOPASDFGHJKL"), VFX_WSTR("67890"));
        m_contactSelector->add(VFX_WSTR("Ken"), VFX_WSTR("12345"));
        m_contactSelector->add(VFX_WSTR("Ben"), VFX_WSTR("12345"));
        m_contactSelector->add(VFX_WSTR("Jack"), VFX_WSTR("12345"));
        m_contactSelector->add(VFX_WSTR("Mic"), VFX_WSTR("12345"));
    }

    void csOnSearchButtonClicked()
    {
        // click the search button, goto phonebook
    }

    void csOnTextChanged(VcpContactSelector *cs, VfxWChar *text)
    {
        // inputbox text changed, search in phonebook and update list
        m_contactSelector->hideContact(VFX_TRUE);

        // search in phonebook and display reslut list
        // TODO:
    }

    virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    )
    {
        // do nothing
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Does it work?"));
        return -1;
    }

    void closeTestObject()
    {
        if (m_contactSelector)
        {
    //        VFX_OBJ_CLOSE(m_contactSelector);
        }
    }

private:
    VcpContactSelector *m_contactSelector;
};


/***************************************************************************** 
 * Input popup Test Implementation
 *****************************************************************************/
class VtstRtInputPopup : public VtstRtScr
{
// Constructor / Destructor
public:
    VtstRtInputPopup()
    {
    }

    //virtual VfxFrameImeModeEnum getImeMode() {return VFX_FRAME_IME_MODE_SHIFT;}

public:
    virtual VfxFrameImeModeEnum getImeMode() {return VFX_FRAME_IME_MODE_SHIFT;}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        
        setTitle(VFX_WSTR("Inputpopup test"));

        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        VFX_OBJ_CREATE(box, VfxControl, this);
        box->setRect(VfxRect(0, TEST_VIEW_START_Y, mainScreenSize.width, mainScreenSize.height - TEST_VIEW_START_Y));
        box->setBgColor(VFX_COLOR_WHITE);
        box->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                            VFX_FRAME_ALIGNER_MODE_SIDE,
                            VFX_FRAME_ALIGNER_MODE_SIDE,
                            VFX_FRAME_ALIGNER_MODE_SIDE);

        m_inputPopup = NULL;

        testInputPopup(0);
    }

    virtual void onDeinit()
    {
        VtstRtScr::onDeinit();
        
        closeTestObject();
    }

    void testInputPopup(VfxS32 command)
    {
        if (m_inputPopup != NULL)
        {
            VFX_OBJ_CLOSE(m_inputPopup);
        }

        VFX_OBJ_CREATE(m_inputPopup, VcpInputPopup, this);

        if (command == 0)
        { 
            VsrvInputBinding inputBind(
                IMM_INPUT_TYPE_SENTENCE,
                0,
                IME_INPUT_STYLE_NONE,
                static_cast<InputConnection*> (m_inputPopup->getInputbox()->m_editing));
            inputBind.setDisabledChars(VFX_WSTR("*-\n"));
            m_inputPopup->getInputbox()->setIME(inputBind);
            m_inputPopup->setHintText(VFX_WSTR("Input frequency (MHZ)")); 
            m_inputPopup->m_signalButtonClicked.connect(this, &VtstRtInputPopup::ipOnButtonClicked);
            m_inputPopup->setText(VFX_WSTR("Hello World!"), 20);
            m_inputPopup->setTitle(VFX_WSTR("Quick frequency set"));
            m_inputPopup->show(VFX_TRUE);
        }
        else if (command == 1)
        { 
            VsrvInputBinding inputBind(
                IMM_INPUT_TYPE_SENTENCE,
                0,
                IME_INPUT_STYLE_NONE,
                static_cast<InputConnection*> (m_inputPopup->getInputbox()->m_editing));
            inputBind.setDisabledChars(VFX_WSTR("*-\n"));
            m_inputPopup->getInputbox()->setIME(inputBind);
            m_inputPopup->setHintText(VFX_WSTR("Input frequency (MHZ), hint text max line is thee line, the hint text will be hide when only one group.")); 
            m_inputPopup->m_signalButtonClicked.connect(this, &VtstRtInputPopup::ipOnButtonClicked);
            m_inputPopup->setText(VFX_WSTR("Hello World!"), 20);
            m_inputPopup->setTitle(VFX_WSTR("Quick frequency set"));
            m_inputPopup->show(VFX_TRUE);
        }
        else if (command == 2)
        {
            m_inputPopup->setGroupNum(2);
            m_inputPopup->setTitle(VFX_WSTR("Quick frequency set"));
            m_inputPopup->setHintText(VFX_WSTR("Input frequency (MHZ)"), 0);
            m_inputPopup->setHintText(VFX_WSTR("Input frequency (MHZ)"), 1);
            m_inputPopup->m_signalButtonClicked.connect(this, &VtstRtInputPopup::ipOnButtonClicked);
            m_inputPopup->show(VFX_TRUE);
        }
        else if (command == 3)
        {
            m_inputPopup->setGroupNum(2);
            m_inputPopup->setTitle(VFX_WSTR("Quick frequency set"));
            m_inputPopup->setHintText(VFX_WSTR("Input frequency (MHZ), this is hint text of first group, the hint text max lines is 3 line"), 0);
      //      m_inputPopup->setHintText(VFX_WSTR("Input frequency (MHZ), this is hint text of second group, the hint text max lines is 3 line"), 1);
      //      m_inputPopup->setHintText(VFX_WSTR("Input frequency (MHZ), this is hint text of first group, the hint text max lines is 3 lines, if the hint text exceed three lines, it will truncate"), 0);
            m_inputPopup->setHintText(VFX_WSTR("Input frequency (MHZ), this is hint text of second group, the hint text max lines is 3 lines, if the hint text exceed three lines, it will truncate"), 1);
            m_inputPopup->m_signalButtonClicked.connect(this, &VtstRtInputPopup::ipOnButtonClicked);
            m_inputPopup->show(VFX_TRUE);
        }
    }

    void ipOnButtonClicked(VfxObject* sender, VcpInputPopupButtonEnum id)
    {
        VfxWString inputText;
        switch (id)
        {
        case VCP_INPUT_POPUP_BTN_OK:
            // DO ok operation
            inputText = m_inputPopup->getText();

            if (inputText == VFX_WSTR("0"))
            {
                testInputPopup(0);
            }
            else if (inputText == VFX_WSTR("1"))
            {
                testInputPopup(1);
            }
            else if (inputText == VFX_WSTR("2"))
            {
                testInputPopup(2);
            }
            else if (inputText == VFX_WSTR("3"))
            {
                testInputPopup(3);
            }
            else
            {
                m_inputPopup->setErrorText(VFX_WSTR("Invalid frequency"));
                m_inputPopup->setErrorText(VFX_WSTR("Invalid frequency, this is error text, max lines is two lines, if exceed 2 lines, it will truncate."), 1);
            }

            break;
        case VCP_INPUT_POPUP_BTN_CANCEL:
            // DO cancel operation
            // close popup
            VFX_OBJ_CLOSE(m_inputPopup);
            break;
        default:
            break;
        }
    }

    virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    )
    {
        // do nothing
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Does it work?"));
        return -1;
    }

    void closeTestObject()
    {
        if (m_inputPopup)
        {
   //         VFX_OBJ_CLOSE(m_inputPopup);
        }
    }

private:
    VcpInputPopup *m_inputPopup;
    VfxControl *box;
};


VtstTestResultEnum vtst_rt_text_view(VfxU32 param)
{
    VTST_START_SCRN(VtstRtTextView);
    return VTST_TR_OK;
}


VtstTestResultEnum vtst_rt_text_view_single_view(VfxU32 param)
{
    VTST_START_SCRN(VtstRtTextViewSingleView);
    return VTST_TR_OK;
}


VtstTestResultEnum vtst_rt_text_view_single_editor(VfxU32 param)
{
    VTST_START_SCRN(VtstRtTextViewSingleEditor);
    return VTST_TR_OK;
}


VtstTestResultEnum vtst_rt_text_view_multi_view(VfxU32 param)
{
    VTST_START_SCRN(VtstRtTextViewMultiView);
    return VTST_TR_OK;
}


VtstTestResultEnum vtst_rt_text_view_multi_editor(VfxU32 param)
{
    VTST_START_SCRN(VtstRtTextViewMultiEditor);
    return VTST_TR_OK;
}


VtstTestResultEnum vtst_rt_contact_selector(VfxU32 param)
{
    VTST_START_SCRN(VtstRtContactSelector);
    return VTST_TR_OK;
}


VtstTestResultEnum vtst_rt_input_popup(VfxU32 param)
{
    VTST_START_SCRN(VtstRtInputPopup);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

