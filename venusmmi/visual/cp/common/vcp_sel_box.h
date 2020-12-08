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
 *  vcp_sel_box.h
 *
 * Project:
 * --------
 *  Venus MMI
 *
 * Description:
 * ------------
 *  Selection Box (for input method) header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCP_SEL_BOX_H__
#define __VCP_SEL_BOX_H__

#if defined __MMI_IME_SCROLLING_COMPOSITION__
#include "Vcp_Scrollable.h"
#include "Vcp_button.h"
#endif
/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C"
{
    #include "MMI_features.h"
}

#include "vfx_uc_include.h"


/***************************************************************************** 
 * Defination
 *****************************************************************************/
// the string name of VcpSelBox
#define VCP_SEL_BOX_CLASS_NAME                      "SelectionBox"
#define VCP_RESIZABLE_COMPOSITION_BOX               "ResizableCompositionBox"

// the max number of candidates in selection box
#define VCP_SEL_BOX_CANDIDATE_COUNT_MAX             20

// the style of selection box
#define VCP_SEL_BOX_STYLE_ARROW                     0x0001
#define VCP_SEL_BOX_STYLE_LABEL                     0x0002
#define VCP_SEL_BOX_STYLE_STAR                      0x0004
#define VCP_SEL_BOX_STYLE_BORDER                    0x0008
#define VCP_SEL_BOX_STYLE_SPACE_AFTER_APOSTROPHE    0x0010
#define VCP_SEL_BOX_STYLE_SEPERATOR                 0x0020
#define VCP_SEL_BOX_STYLE_EXPAND_BUTTON             0x0040

// the flag of selection box
#define VCP_SEL_BOX_FLAG_FOCUS                      0x0001
#define VCP_SEL_BOX_FLAG_PRE_PAGE                   0x0002
#define VCP_SEL_BOX_FLAG_NEXT_PAGE                  0x0004
#define VCP_SEL_BOX_FLAG_SHOW_ARROW                 0x0008
#define VCP_SEL_BOX_FLAG_FIX_GRID                   0x0010
#define VCP_SEL_BOX_FLAG_R2L                        0x0020
#define VCP_SEL_BOX_FLAG_SPACE                      0x0040
#define VCP_SEL_BOX_FLAG_CENTER_INDEX               0x0080
#define VCP_SEL_BOX_FLAG_LAST_PAGE                  0x0100
#define VCP_SEL_BOX_FLAG_SHOW_STAR                  0x0200
#define VCP_SEL_BOX_FLAG_DISABLE_LABEL              0x0400
#define VCP_SEL_BOX_FLAG_SHOW_EXPAND_BUTTON         0x0800



/***************************************************************************** 
 * Enum
 *****************************************************************************/
// <group DOM_SelectionBox_Enum>
// The state of arrow in selection box
enum VcpSelBoxArrowStateEnum
{
    VCP_SEL_BOX_ARROW_STATE_NORMAL = 0,         // the arrow is in normal state
    VCP_SEL_BOX_ARROW_STATE_HILITE,             // the arrow is in highlight state
    VCP_SEL_BOX_ARROW_STATE_DISABLED            // the arrow is in disabled state
};


enum VcpEnumCandGridItemEnum
{
    VCP_CAND_GRID_CANDIDATE=16,
    VCP_CAND_GRID_BACKSPACE,         // the arrow is in normal state
    VCP_CAND_GRID_PREPAGE,            // the arrow is in disabled state
    VCP_CAND_GRID_NEXTPAGE,
    VCP_CAND_GRID_BACK
};

// <group DOM_SelectionBox_Enum>
// The direction of arrow in selection box
enum VcpSelBoxArrowDirectionEnum
{
    VCP_SEL_BOX_ARROW_DIRECTION_LEFT = 0,       // the direction is left
    VCP_SEL_BOX_ARROW_DIRECTION_RIGHT           // the direction is right
};


// <group DOM_SelectionBox_Enum>
// The state of candidate in selection box
enum VcpSelBoxCandStateEnum
{
    VCP_SEL_BOX_CAND_STATE_NORMAL = 0,          // the candidate is in normal state
    VCP_SEL_BOX_CAND_STATE_HILITE,              // the candidate is in highlight state
};


// <group DOM_SelectionBox_Enum>
// The size of selection box
// Note: use in FTE
enum VcpSelBoxCandSizeEnum
{
    VCP_SEL_BOX_SIZE_NONE = 0,                  // the size is no use (in non-FTE)
    VCP_SEL_BOX_SIZE_SMALL,                     // the size is small
    VCP_SEL_BOX_SIZE_MEDIUM,                    // the size is medium
    VCP_SEL_BOX_SIZE_LARGE                      // the size is large
};


// <group DOM_SelectionBox_Enum>
// the type of arrow
enum VcpSelBoxArrowTypeEnum
{
    VCP_SEL_BOX_ARROW_TYPE_NONE = 0,            // none
    VCP_SEL_BOX_ARROW_TYPE_PREVIOUS,            // previous button
    VCP_SEL_BOX_ARROW_TYPE_NEXT,                // next button
};


// <group DOM_SelectionBox_Enum>
// The size of resizable composition box
// Note: use in FTE
enum VcpResizableCompositionBoxSizeEnum
{
    VCP_RESIZABLE_COMPOSITION_BOX_SIZE_NONE = 0,                    // the size is no use
    VCP_RESIZABLE_COMPOSITION_BOX_SIZE_SMALL,                       // the size is small
    VCP_RESIZABLE_COMPOSITION_BOX_SIZE_MEDIUM,                      // the size is medium
    VCP_RESIZABLE_COMPOSITION_BOX_SIZE_LARGE                        // the size is large
};


/***************************************************************************** 
 * Struct
 *****************************************************************************/
// <group DOM_SelectionBox_Struct>
// the theme for arrow in selection box
struct VcpSelBoxArrowThemeStruct
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    VfxImageSrc imgNormalLeft;          // the image of left arrow in normal state
    VfxImageSrc imgHiliteLeft;          // the image of left arrow in highlight state
    VfxImageSrc imgDisabledLeft;        // the image of left arrow in disabled state
    VfxImageSrc imgNormalRight;         // the image of right arrow in normal state
    VfxImageSrc imgHiliteRight;         // the image of right arrow in highlight state
    VfxImageSrc imgDisabledRight;       // the image of right arrow in disabled state
#else
    VfxColor colorNormal;               // the color of arrow in normal state
    VfxColor colorHilite;               // the color of arrow in highlight state
    VfxColor colorDisabled;             // the color of arrow in disabled state
#endif
};


// <group DOM_SelectionBox_Struct>
// the theme for star in selection box
struct VcpSelBoxStarThemeStruct
{
    VfxFontDesc font;               // the font to draw star
    VfxColor color;                 // the color to draw star
};


// <group DOM_SelectionBox_Struct>
// the theme for seperator in selection box
struct VcpSelBoxSeperatorThemeStruct
{
#if defined(__MMI_IME_FTE_ENHANCE__)
    VfxImageSrc imageNormal;        // the image of seperator in normal state
    VfxImageSrc imageFocused;       // the image of seperator in focused state
#else
    VfxColor colorNormal;           // the color of seperator in normal state
    VfxColor colorFocused;          // the color of seperator in focused state
    VfxS32 width;                   // the width of seperator
#endif
};


// <group DOM_SelectionBox_Struct>
// the theme for candidate in selection box
struct VcpSelBoxCandThemeStruct
{
    // the theme of label
    VfxColor labelColor;                    // the color of label
    VfxFontDesc labelFont;                  // the font of label
    // the theme of text
    VfxFontDesc textFont;                   // the font of text
    VfxColor normalTextColor;               // the color of text in normal state
    VfxColor radicalNormalTextColor;        // the color of text which is radical in normal state
    VfxColor hiliteTextColor;               // the color of text in highlight state
    VfxColor radicalHiliteTextColor;        // the color of text which is radical in highlight state
#if defined(__MMI_IME_FTE_ENHANCE__)
    VfxImageSrc hiliteBgImg;                // the background image of text in highlight state (focused)
    VfxImageSrc dullHiliteBgImg;            // the background image of text in highlight state (no focused)
    VfxImageSrc radicalHiliteBgImg;         // the background image of text which is radical in highlight state (focused)
    VfxImageSrc radicalDullHiliteBgImg;     // the background image of text which is radical in highlight state (no focused)
#else
    VfxColor hiliteBgColor;                 // the background color of text in highlight state (focused)
    VfxColor dullHiliteBgColor;             // the background color of text in highlight state (no focused)
    VfxColor radicalHiliteBgColor;          // the background color of text which is radical in highlight state (focused)
    VfxColor radicalDullHiliteBgColor;      // the background color of text which is radical in highlight state (no focused)
#endif
};


// <group DOM_SelectionBox_Struct>
// the theme for selection box
struct VcpSelBoxThemeStruct
{


#if defined __MMI_IME_SCROLLING_COMPOSITION__
VfxImageSrc scrollableboxBg;

VfxImageSrc scrollableboxCandBg;


VfxImageSrc scrollableboxCandBgHl;


#endif



//expand button 
#if defined __MMI_IME_CANDIDATE_GRID__
VfxImageSrc expandImg;



VfxImageSrc gridBg;
VfxImageSrc gridCandBg;
VfxImageSrc gridCandBgHl;
VfxImageSrc gridFixedButtonBg;
VfxImageSrc gridFixedButtonBgHl;
VfxImageSrc deleteImg;
VfxImageSrc backImg;
VfxImageSrc arrowDownImg;
VfxImageSrc arrowDownDisableImg;
VfxImageSrc arrowUpImg;
VfxImageSrc arrowUpDisableImg;





#endif

    // star
    VfxFontDesc starFont;
    VfxColor starColor;
    
    // label
    VfxFontDesc labelFont;
    VfxColor labelColor;
    
    // candidate
    VfxFontDesc candFont;
    VfxColor candNormalColor;
    VfxColor candHiliteColor;
    VfxColor candRadicalNormalColor;
    VfxColor candRadicalHiliteColor;
    VfxS32 candGap;
#if defined(__MMI_IME_FTE_ENHANCE__)
    VfxImageSrc candHiliteBgImgSmall;
    VfxImageSrc candDullHiliteBgImgSmall;
    VfxImageSrc candRadicalHiliteBgImgSmall;
    VfxImageSrc candRadicalDullHiliteBgImgSmall;
    VfxImageSrc candHiliteBgImgMedium;
    VfxImageSrc candDullHiliteBgImgMedium;
    VfxImageSrc candRadicalHiliteBgImgMedium;
    VfxImageSrc candRadicalDullHiliteBgImgMedium;
    VfxImageSrc candHiliteBgImgLarge;
    VfxImageSrc candDullHiliteBgImgLarge;
    VfxImageSrc candRadicalHiliteBgImgLarge;
    VfxImageSrc candRadicalDullHiliteBgImgLarge;
#else
    VfxColor candHiliteBgColor;
    VfxColor candDullHiliteBgColor;
    VfxColor candRadicalHiliteBgColor;
    VfxColor candRadicalDullHiliteBgColor;
#endif

    // arrow
#if defined(__MMI_IME_FTE_ENHANCE__)
    VfxImageSrc leftArrowNormalImgSmall;
    VfxImageSrc leftArrowHiliteImgSmall;
    VfxImageSrc leftArrowDisabledImgSmall;
    VfxImageSrc leftArrowNormalImgMedium;
    VfxImageSrc leftArrowHiliteImgMedium;
    VfxImageSrc leftArrowDisabledImgMedium;
    VfxImageSrc leftArrowNormalImgLarge;
    VfxImageSrc leftArrowHiliteImgLarge;
    VfxImageSrc leftArrowDisabledImgLarge;
    VfxImageSrc rightArrowNormalImgSmall;
    VfxImageSrc rightArrowHiliteImgSmall;
    VfxImageSrc rightArrowDisabledImgSmall;
    VfxImageSrc rightArrowNormalImgMedium;
    VfxImageSrc rightArrowHiliteImgMedium;
    VfxImageSrc rightArrowDisabledImgMedium;
    VfxImageSrc rightArrowNormalImgLarge;
    VfxImageSrc rightArrowHiliteImgLarge;
    VfxImageSrc rightArrowDisabledImgLarge;
#else
    VfxColor arrowNormalColor;
    VfxColor arrowHiliteColor;
    VfxColor arrowDisabledColor;
#endif

    // seperator
#if defined(__MMI_IME_FTE_ENHANCE__)
    VfxImageSrc seperatorNormalImgSmall;
    VfxImageSrc seperatorFocusedImgSmall;
    VfxImageSrc seperatorNormalImgMedium;
    VfxImageSrc seperatorFocusedImgMedium;
    VfxImageSrc seperatorNormalImgLarge;
    VfxImageSrc seperatorFocusedImgLarge;
#else
    VfxColor seperatorNormalColor;
    VfxColor seperatorFocusedColor;
    VfxS32 seperatorWidth;
#endif

    // the background of selection box
#if defined(__MMI_IME_FTE_ENHANCE__)
    VfxImageSrc bgImageSmall;
    VfxImageSrc focusedBgImageSmall;
    VfxImageSrc bgImageMedium;
    VfxImageSrc focusedBgImageMedium;
    VfxImageSrc bgImageLarge;
    VfxImageSrc focusedBgImageLarge;
#else
    VfxColor borderColor;
    VfxImageSrc bgImage;
    VfxColor bgColor;
    VfxColor focusedBorderColor;
    VfxImageSrc focusedBgImage;
    VfxColor focusedBgColor;
#endif
};


// <group DOM_SelectionBox_Struct>
// the theme for the resizable composition box
struct VcpResizableCompositionBoxThemeStruct
{
    VfxFontDesc textFont;           // the font of text in the resizable composition box
    VfxColor textColor;             // the color of text in the resizable composition box
    VfxImageSrc bgImageSmall;       // the small image of background of the resizable composition box
    VfxImageSrc bgImageMedium;      // the medium image of background of the resizable composition box
    VfxImageSrc bgImageLarge;       // the large image of background of the resizable composition box
};


/***************************************************************************** 
 * Class VcpSelBoxArrow
 *****************************************************************************/

/*
 * DESCRIPTION
 *  VcpSelBoxArrow is a class to show the left/right arrow in selection box.
 *  The class can decide its width. the user should decide the height of it
 */
class VcpSelBoxArrow : public VfxFrame
{
// Constructor / Destructor
public:
    // <group DOM_SelectionBox_VcpSelBoxArrow_Constructor/Destructor>
    VcpSelBoxArrow(
        const VcpSelBoxArrowThemeStruct &theme      // [IN] the theme of arrow
        ) :
        m_state(VCP_SEL_BOX_ARROW_STATE_NORMAL),
        m_direction(VCP_SEL_BOX_ARROW_DIRECTION_LEFT),
        m_theme(theme)
    {
    }

// Method
public:
    // <group DOM_SelectionBox_VcpSelBoxArrow_Method>
    // set the state of arrow
    void setState(
        VcpSelBoxArrowStateEnum state               // [IN] the state of this arrow
        );

    // <group DOM_SelectionBox_VcpSelBoxArrow_Method>
    // get the state of arrow
    VcpSelBoxArrowStateEnum getState()
    {
        return m_state;
    }

    // <group DOM_SelectionBox_VcpSelBoxArrow_Method>
    // set the theme of arrow
    void setTheme(
        const VcpSelBoxArrowThemeStruct &theme      // [IN] the theme to be set
    );

    // <group DOM_SelectionBox_VcpSelBoxArrow_Method>
    // set the direction of arrow
    void setDirection(
        VcpSelBoxArrowDirectionEnum direction       // [IN] the direction of arrow
        );

// Override
protected:
    // <group DOM_SelectionBox_VcpSelBoxArrow_Override>
    virtual void onInit();

    // <group DOM_SelectionBox_VcpSelBoxArrow_Override>
    virtual void onDraw(
        VfxDrawContext &dc
        );

// Implementation
private:
    // <group DOM_SelectionBox_VcpSelBoxArrow_Implementation>
    // draw the arrow
    void drawArrow(
        VfxDrawContext &dc                          // [IN] the object of VfxDrawContext for drawing
        );

    // <group DOM_SelectionBox_VcpSelBoxArrow_Implementation>
    // draw the arrow from image
    void drawArrowFromImage(
        VfxDrawContext &dc                          // [IN] the object of VfxDrawContext for drawing
        );
    
// Variable
private:
    // <group DOM_SelectionBox_VcpSelBoxArrow_Variable>
    // the state of this arrow
    VcpSelBoxArrowStateEnum m_state;

    // <group DOM_SelectionBox_VcpSelBoxArrow_Variable>
    // the direction of this arrow
    VcpSelBoxArrowDirectionEnum m_direction;

    // <group DOM_SelectionBox_VcpSelBoxArrow_Variable>
    // the theme of this arrow
    VcpSelBoxArrowThemeStruct m_theme;
};


/***************************************************************************** 
 * Class VcpSelBoxStar
 *****************************************************************************/

/*
 * DESCRIPTION
 *  VcpSelBoxStar is a class to show the indicator of star in selection box
 *  The class can decide its width. the user should decide the height of it
 */
class VcpSelBoxStar : public VfxTextFrame
{
// Constructor / Destructor
public:
    // <group DOM_SelectionBox_VcpSelBoxStar_Constructor/Destructor>
    VcpSelBoxStar(
        const VcpSelBoxStarThemeStruct &theme      // [IN] the theme to be set
        ) :
        m_theme(theme)
    {
    }

// Method
public:
    // <group DOM_SelectionBox_VcpSelBoxStar_Method>
    // set the theme of star
    void setTheme(
        const VcpSelBoxStarThemeStruct &theme      // [IN] the theme to be set
    );

// Override
protected:
    // <group DOM_SelectionBox_VcpSelBoxStar_Override>
    virtual void onInit();

// Variable
private:   
    // <group DOM_SelectionBox_VcpSelBoxStar_Variable>
    // the theme of star in selection box
    VcpSelBoxStarThemeStruct m_theme;
};


/***************************************************************************** 
 * Class VcpSelBoxSeperator
 *****************************************************************************/

/*
 * DESCRIPTION
 *  VcpSelBoxSeperator is a class to show the indicator of seperator
 *  The class can decide its width. the user should decide the height of it
 */
class VcpSelBoxSeperator : public VfxFrame
{
// Constructor / Destructor
public:
    // <group DOM_SelectionBox_VcpSelBoxSeperator_Constructor/Destructor>
    VcpSelBoxSeperator(
        const VcpSelBoxSeperatorThemeStruct &theme      // [IN] the theme to be set
        ) :
        m_isFocused(VFX_FALSE),
        m_theme(theme)
    {
    }

// Method
public:
    // <group DOM_SelectionBox_VcpSelBoxSeperator_Method>
    // set whether the seperator is focused
    void setIsFocused(
        VfxBool isFocused                               // [IN] whether the seperator is focused
                                                        // VFX_TRUE, the seperator is focused; VFX_FALSE, the seperator is not focused
        );

    // <group DOM_SelectionBox_VcpSelBoxSeperator_Method>
    // set the theme of seperator
    void setTheme(
        const VcpSelBoxSeperatorThemeStruct &theme      // [IN] the theme to be set
    );
    
// Override
protected:
    // <group DOM_SelectionBox_VcpSelBoxSeperator_Override>
    virtual void onInit();

    // <group DOM_SelectionBox_VcpSelBoxSeperator_Override>
    virtual void onDraw(
        VfxDrawContext &dc
        );

// Implementation
private:
    // <group DOM_SelectionBox_VcpSelBoxSeperator_Implementation>
    // draw the seperator
    void drawSeperator(
        VfxDrawContext &dc                              // [IN] the object of VfxDrawContext for drawing
        );

    // <group DOM_SelectionBox_VcpSelBoxSeperator_Implementation>
    // draw the seperator from image
    void drawSeperatorFromImage(
        VfxDrawContext &dc                              // [IN] the object of VfxDrawContext for drawing
        );

// Variable
private:
    // <group DOM_SelectionBox_VcpSelBoxSeperator_Variable>
    // whether the seperator is focused
    VfxBool m_isFocused;
    
    // <group DOM_SelectionBox_VcpSelBoxSeperator_Variable>
    // the theme of seperator
    VcpSelBoxSeperatorThemeStruct m_theme;
};


/***************************************************************************** 
 * Class VcpSelBoxCandidate
 *****************************************************************************/

/*
 * DESCRIPTION
 *  VcpSelBoxCandidate is a class to show the candidate in selection box
 *  The class can decide its width. the user should decide the height of it
 */
class VcpSelBoxCandidate : public VfxFrame
{
// Constructor / Destructor
public:
    // <group DOM_SelectionBox_VcpSelBoxCandidate_Constructor/Destructor>
    VcpSelBoxCandidate(
        const VfxWString &text,                                         // [IN] the text of this candidate
        const VcpSelBoxCandThemeStruct &theme,                          // [IN] the theme to be set
        VfxS32 label = -1,                                              // [IN] the label of this candidate, -1 indicate no label
        VcpSelBoxCandStateEnum state = VCP_SEL_BOX_CAND_STATE_NORMAL,   // [IN] the state of this candidate
        VfxBool isR2L = VFX_FALSE,                                      // [IN] whether the layout is right to left
                                                                        // VFX_TRUE, right ro left; VFX_FALSE, left to right
        VfxBool isAddingSpace = VFX_FALSE,                              // [IN] whether adding a space after apostrophe for seperate spelling
                                                                        // VFX_TRUE, adding; VFX_FALSE, no adding
        VfxBool isLabelShow = VFX_TRUE                                  // [IN] whether show the label
                                                                        // VFX_TRUE, show; VFX_FALSE, do not show
        );

// Method
public:
    // <group DOM_SelectionBox_VcpSelBoxCandidate_Method>
    // set the state of candidate
    void setState(
        VcpSelBoxCandStateEnum state            // [IN] the state of candidate
        );

    // <group DOM_SelectionBox_VcpSelBoxCandidate_Method>
    // set whether the candidate is focused
    void setIsFocused(
        VfxBool isFocused                       // [IN] whether the candidate is focused
                                                // VFX_TRUE, the candidate is focused; VFX_FALSE, the candidate is not focused
        );

// Override
public:
    // <group DOM_SelectionBox_VcpSelBoxCandidate_Override>
    virtual void setBounds(const VfxRect &value);

protected:
    // <group DOM_SelectionBox_VcpSelBoxCandidate_Override>
    virtual void onInit();
    
    // <group DOM_SelectionBox_VcpSelBoxCandidate_Override>
    virtual void onDraw(
        VfxDrawContext &dc
        );

// Implementation
private:
    // <group DOM_SelectionBox_VcpSelBoxCandidate_Implementation>
    // init the layout and display
    void initLayoutDisplay();

    // <group DOM_SelectionBox_VcpSelBoxCandidate_Implementation>
    // update the layout according to the size
    void updateLayout();

    // <group DOM_SelectionBox_VcpSelBoxCandidate_Implementation>
    // update the display
    void updateDisplay();

// Variable
private:
    // <group DOM_SelectionBox_VcpSelBoxCandidate_Variable>
    // the state of this candidate
    VcpSelBoxCandStateEnum m_state;

    // <group DOM_SelectionBox_VcpSelBoxCandidate_Variable>
    // the label of this candidate
    VfxS32 m_label;

    // <group DOM_SelectionBox_VcpSelBoxCandidate_Variable>
    // the text of this candidate
    VfxWString m_text;

    // <group DOM_SelectionBox_VcpSelBoxCandidate_Variable>
    // whether the layout is right to left
    VfxBool m_isR2L;

    // <group DOM_SelectionBox_VcpSelBoxCandidate_Variable>
    // whether adding a space after apostrophe for seperate spelling
    VfxBool m_isAddingSpace;

    // <group DOM_SelectionBox_VcpSelBoxCandidate_Variable>
    // whether the candidate is focused
    VfxBool m_isFocused;

    // <group DOM_SelectionBox_VcpSelBoxCandidate_Variable>
    // the theme of candidate
    VcpSelBoxCandThemeStruct m_theme;

    // <group DOM_SelectionBox_VcpSelBoxCandidate_Variable>
    // the text frame to show label
    VfxTextFrame *m_labelFrame;

    // <group DOM_SelectionBox_VcpSelBoxCandidate_Variable>
    // the text frame to show text
    VfxTextFrame *m_textFrame;

    // <group DOM_SelectionBox_VcpSelBoxCandidate_Variable>
    // whether the label is showed
    VfxBool m_isLabelShow;
};


/***************************************************************************** 
 * Class VcpSelBox
 *****************************************************************************/

/*
 * DESCRIPTION
 *  VcpSelBox is a class to show the selection box and emit signal to ouside when
 *  there is pen event.
 *  The class can decide its height. the user should decide the width of it
 */
class VcpSelBox : public VfxControl
{
    VFX_DECLARE_CLASS(VcpSelBox);

// Constructor / Destructor
public:
    // <group DOM_SelectionBox_VcpSelBox_Constructor/Destructor>
    VcpSelBox(
        VfxU32 style = 0                            // [IN] the style of selection box
                                                    // Note: please find the style in VCP_SEL_BOX_STYLE_XXX
        );
    
// Method
public:
    // <group DOM_SelectionBox_VcpSelBox_Method>
    // update the selection box
    // RETURNS: the count of candidate show in selection box
    // Note: when the size of selection box is changed, the caller should call this interface again
    // Note: if the setTheme() will call later, the parameter of candStr do not destroy or change till the setTheme() is called
    VfxS32 update(
        const VfxWChar *candStr,        // [IN] the string of candidates
        VfxS32 count,                   // [IN] the count of candidates
        VfxS32 hiliteIndex,             // [IN] the index of highlight candidate, -1 indicate no highlight candidate
        VfxU32 flag                     // [IN] the flag of selection box
                                        // Note: please find the flag in VCP_SEL_BOX_FLAG_XXX
        );

    // <group DOM_SelectionBox_VcpSelBox_Method>
    // set the highlight candidate
    // RETURNS: VFX_TRUE, set successfully; VFX_FALSE, can not set the highlight candidate because the candidate indicated is
    // not in selection box
    VfxBool setHiliteCandidate(
        VfxS32 hiliteIndex              // [IN] the index of highlight candidate, -1 indicate no highlight candidate
        );

    // <group DOM_SelectionBox_VcpSelBox_Method>
    // get the index of highlight candidate
    // RETURNS: the index of highlight candidate, -1 if no highlight candidate
    VfxS32 getHiliteCandidate();

    // <group DOM_SelectionBox_VcpSelBox_Method>
    // set the theme of selection box
    // RETURNS: the count of candidate show in selection box after changing theme
    // Note: when this interface is called, the height of selection box may be changed
    VfxS32 setTheme(
        const VcpSelBoxThemeStruct &theme   // [IN] the theme to be set
        );

    // <group DOM_SelectionBox_VcpSelBox_Method>
    // get the theme of selection box
    // RETURNS: the theme of selection box
    const VcpSelBoxThemeStruct &getTheme();

    // <group DOM_SelectionBox_VcpSelBox_Method>
    // set whether this selection box is focused
    void setIsFocused(
        VfxBool isFocused                   // [IN] whether this selection box is focused
                                            // VFX_TRUE, this selection box is focused; VFX_FALSE, this selection box is not focused
        );

    // <group DOM_SelectionBox_VcpSelBox_Method>
    // set the string for new word
    void setNewWordString(
        const VfxWString &str               // [IN] the string for new word
        );

    // <group DOM_SelectionBox_VcpSelBox_Method>
    // set whether select candidate by pen event
    void setIsPenSelectionValid(
        VfxBool isValid                     // [IN] whether enable that selecting candidate by pen event
                                            // VFX_TRUE, enable that selecting candidate by pen event; VFX_FALSE, disable that selecting candidate by pen event
        );
    
// Signal
public:
    // <group DOM_SelectionBox_VcpSelBox_Signal>
    // notify that the pen is down on one candidate
    VfxSignal2 <
        VfxObject*,                     // sender
        VfxS32                          // the index of candidate
        > m_signalCandDown;

    // <group DOM_SelectionBox_VcpSelBox_Signal>
    // notify that the pen is up on one candidate
    VfxSignal2 <
        VfxObject*,                     // sender
        VfxS32                          // the index of candidate
        > m_signalCandUp;

    // <group DOM_SelectionBox_VcpSelBox_Signal>
    // notify that the pen is abort on one candidate
    VfxSignal2 <
        VfxObject*,                     // sender
        VfxS32                          // the index of candidate
        > m_signalCandAbort;

    // <group DOM_SelectionBox_VcpSelBox_Signal>
    // notify that the pen has moved onto another candidate
    VfxSignal2 <
        VfxObject*,                     // sender
        VfxS32                          // the index of candidate
        > m_signalCandMove;

    // <group DOM_SelectionBox_VcpSelBox_Signal>
    // notify that previous arrow is clicked
    VfxSignal1 <
        VfxObject*                      // sender
        > m_signalPreArrowClicked;

    // <group DOM_SelectionBox_VcpSelBox_Signal>
    // notify that next arrow is clicked
    VfxSignal1 <
        VfxObject*                      // sender
        > m_signalNextArrowClicked;

// Override
protected:
    // <group DOM_SelectionBox_VcpSelBox_Override>
    virtual void onDraw(
        VfxDrawContext &dc
        );

    // <group DOM_SelectionBox_VcpSelBox_Override>
    virtual void onInit();

    // <group DOM_SelectionBox_VcpSelBox_Override>
    virtual VfxBool onPenInput(
        VfxPenEvent &event
        );

// Implementation
private:
    // <group DOM_SelectionBox_VcpSelBox_Implementation>
    // build the default theme from system theme
    void buildDefaultTheme();
    
    // <group DOM_SelectionBox_VcpSelBox_Implementation>
    // decide the height of selection box according to the font/image
    // RETRUNS: the height of selection box according to the font/image
    VfxS32 getDefaultHeight();

    // <group DOM_SelectionBox_VcpSelBox_Implementation>
    // build the theme of arrow according the theme of selection box.
    void buildArrowTheme(
        VcpSelBoxArrowThemeStruct &arrowTheme               // [OUT] the theme of arrow
        );

    // <group DOM_SelectionBox_VcpSelBox_Implementation>
    // build the theme of star according the theme of selection box.
    void buildStarTheme(
        VcpSelBoxStarThemeStruct &starTheme                 // [OUT] the theme of star
        );

    // <group DOM_SelectionBox_VcpSelBox_Implementation>
    // build the theme of seperator according the theme of selection box.
    void buildSeperatorTheme(
        VcpSelBoxSeperatorThemeStruct &seperatorTheme       // [OUT] the theme of seperator
        );

    // <group DOM_SelectionBox_VcpSelBox_Implementation>
    // build the theme of candidate according the theme of selection box.
    void buildCandidateTheme(
        VcpSelBoxCandThemeStruct &candTheme                 // [OUT] the theme of candidate
        );

    // <group DOM_SelectionBox_VcpSelBox_Implementation>
    // check whether the position is in arrow
    // RETRUNS: VCP_SEL_BOX_ARROW_TYPE_NONE, the position is not in arrow; VCP_SEL_BOX_ARROW_TYPE_PREVIOUS,
    // the positon is in previous arrow; VCP_SEL_BOX_ARROW_TYPE_NEXT, the position is in next arrow
    VcpSelBoxArrowTypeEnum checkIsInArrow(
        const VfxPoint &pos                                 // [IN] the positon to check
        );

    // <group DOM_SelectionBox_VcpSelBox_Implementation>
    // check whether the position is in one candidate
    // RETRUNS: the index of candidate which contains this position, or -1 if no candidate contains this position
    VfxS32 checkIsInCandidate(
        const VfxPoint &pos                                 // [IN] the positon to check
        );
    // <group DOM_SelectionBox_VcpSelBox_Implementation>
    // check whether the position is in one candidate
    // RETRUNS: the index of candidate which contains this position, or -1 if no candidate contains this position
#if defined __MMI_IME_CANDIDATE_GRID__
    void onGridExpandPress(VfxObject *selBox,VfxId index);
#endif


    // <group DOM_SelectionBox_VcpSelBox_Implementation>
    // emit the signal of candidate down
    void emitCandDownSignal(
        VfxS32 index                                        // [IN] the candidate this signal associates with
        );

    // <group DOM_SelectionBox_VcpSelBox_Implementation>
    // emit the signal of candidate up
    void emitCandUpSignal(
        VfxS32 index                                        // [IN] the candidate this signal associates with
        );

    // <group DOM_SelectionBox_VcpSelBox_Implementation>
    // emit the signal of candidate abort
    void emitCandAbortSignal(
        VfxS32 index                                        // [IN] the candidate this signal associates with
        );

    // <group DOM_SelectionBox_VcpSelBox_Implementation>
    // emit the signal of candidate move
    void emitCandMoveSignal(
        VfxS32 index                                        // [IN] the candidate this signal associates with
        );

    // <group DOM_SelectionBox_VcpSelBox_Implementation>
    // emit the signal of arrow clicked
    void emitArrowClickedSignal(
        VcpSelBoxArrowTypeEnum arrow                        // [IN] the arrow this signal associates with
        );

    // <group DOM_SelectionBox_VcpSelBox_Implementation>
    // set the state of arrow according to the highlight candidate, style and flag
    void setArrowState();

// Variable
private:
    // <group DOM_SelectionBox_VcpSelBox_Variable>
    // the style of selection box
    VfxU32 m_style;

    // <group DOM_SelectionBox_VcpSelBox_Variable>
    // the flag of selection box
    VfxU32 m_flag;
    
    // <group DOM_SelectionBox_VcpSelBox_Variable>
    // the theme of selection box
    VcpSelBoxThemeStruct m_theme;
    
    // <group DOM_SelectionBox_VcpSelBox_Variable>
    // the previous arrow to go back to previous page of candidates
    VcpSelBoxArrow *m_preArrow;

    // <group DOM_SelectionBox_VcpSelBox_Variable>
    // the previous seperator beside the previous arrow
    VcpSelBoxSeperator *m_preSeperator;

    // <group DOM_SelectionBox_VcpSelBox_Variable>
    // the next arrow to go to next page of candidates
    VcpSelBoxArrow *m_nextArrow;

    // <group DOM_SelectionBox_VcpSelBox_Variable>
    // the previous seperator beside the next arrow
    VcpSelBoxSeperator *m_nextSeperator;
    
    // <group DOM_SelectionBox_VcpSelBox_Variable>
    // the star which show in selection box
    VcpSelBoxStar *m_star;
#if defined __MMI_IME_CANDIDATE_GRID__
    VcpButton *m_candExpand;
    VcpSelBoxSeperator *m_expandSeperator;
#endif
    // <group DOM_SelectionBox_VcpSelBox_Variable>
    // the candidates
    VcpSelBoxCandidate *m_candArray[VCP_SEL_BOX_CANDIDATE_COUNT_MAX];

    // <group DOM_SelectionBox_VcpSelBox_Variable>
    // the seperators used for seperate candidates
    VcpSelBoxSeperator *m_seperatorArray[VCP_SEL_BOX_CANDIDATE_COUNT_MAX - 1];

    // <group DOM_SelectionBox_VcpSelBox_Variable>
    // the count of candidates
    VfxS32 m_candCount;

    // <group DOM_SelectionBox_VcpSelBox_Variable>
    // the index of current highlight candidate
    VfxS32 m_currHiliteCand;

    // <group DOM_SelectionBox_VcpSelBox_Variable>
    // the size of selection box (in FTE)
    VcpSelBoxCandSizeEnum m_fteSize;

    // <group DOM_SelectionBox_VcpSelBox_Variable>
    // the candidate arrow which come form update()
    const VfxWChar *m_outsideCandStr;

    // <group DOM_SelectionBox_VcpSelBox_Variable>
    // the count of candidate arrow which come form update()
    VfxS32 m_outsideCandCount;

    // <group DOM_SelectionBox_VcpSelBox_Variable>
    // whether show the seperator
    VfxBool m_isSeperatorShow;

    // <group DOM_SelectionBox_VcpSelBox_Variable>
    // whether the selection box is in arrow state (one arrow is pressed down)
    VcpSelBoxArrowTypeEnum m_inArrowState;

    // <group DOM_SelectionBox_VcpSelBox_Variable>
    // whether the selection box is in candidate state (one candidate is pressed down)
    VfxBool m_inCandidateState;

    // <group DOM_SelectionBox_VcpSelBox_Variable>
    // whether the selection box is focused
    VfxBool m_isFocused;

    // <group DOM_SelectionBox_VcpSelBox_Variable>
    // the string of new word used in database
    VfxWString m_newWordStr;

    // <group DOM_SelectionBox_VcpSelBox_Variable>
    // whether select candidate by pen event
    VfxBool m_penSelectionValid;
};


#if defined(__MMI_IME_FTE_ENHANCE__)
/***************************************************************************** 
 * Class VcpResizableCompositionBox
 *****************************************************************************/

/*
 * DESCRIPTION
 *  VcpResizableCompositionBox is a class to show the box contains only one composition
 *  and emit signal to ouside when the box is clicked.
 *  The class can decide its size.
 */
class VcpResizableCompositionBox : public VfxControl
{
    VFX_DECLARE_CLASS(VcpResizableCompositionBox);

// Constructor / Destructor
public:
    // <group DOM_SelectionBox_VcpResizableCompositionBox_Constructor/Destructor>
    VcpResizableCompositionBox(
        VfxU32 coveredHeight = 0,                   // [IN] the height of area which is covered by others
        VfxU32 maxWidth = 0xffff                    // [IN] the max width of box 
        ) :
        m_textFrame(NULL),
        m_coveredHeight(coveredHeight),
        m_maxWidth(maxWidth),
        m_size(VCP_RESIZABLE_COMPOSITION_BOX_SIZE_NONE)
    {
        m_text.setEmpty();
    }

// Method
public:
    // <group DOM_SelectionBox_VcpResizableCompositionBox_Method>
    // set the text of box
    void setText(
        const VfxWString &text                      // [IN] the text of box
        );

    // <group DOM_SelectionBox_VcpResizableCompositionBox_Method>
    // set the theme of box
    void setTheme(
        const VcpResizableCompositionBoxThemeStruct &theme        // [IN] the theme of box
        );

// Signal
public:
    // <group DOM_SelectionBox_VcpResizableCompositionBox_Signal>
    // notify that the box is clicked
    VfxSignal1 <
        VfxObject*                                  // sender
        > m_signalClicked;

// Override
protected:
    // <group DOM_SelectionBox_VcpResizableCompositionBox_Override>
    virtual void onDraw(
        VfxDrawContext &dc
        );

    // <group DOM_SelectionBox_VcpResizableCompositionBox_Override>
    virtual void onInit();

    // <group DOM_SelectionBox_VcpResizableCompositionBox_Override>
    virtual VfxBool onPenInput(
        VfxPenEvent &event
        );

// Implementation
private:
    // <group DOM_SelectionBox_VcpResizableCompositionBox_Implementation>
    // build the default theme from system theme
    void buildDefaultTheme();

    // <group DOM_SelectionBox_VcpResizableCompositionBox_Implementation>
    // decide the height of box according to the font
    // RETRUNS: the height of box according to the font
    VfxS32 getDefaultHeight();

// Variable
private:
    // <group DOM_SelectionBox_VcpResizableCompositionBox_Variable>
    // the text frame for show text
    VfxWString m_text;
    
    // <group DOM_SelectionBox_VcpResizableCompositionBox_Variable>
    // the text frame for show text
    VfxTextFrame *m_textFrame;

    // <group DOM_SelectionBox_VcpResizableCompositionBox_Variable>
    // the theme
    VcpResizableCompositionBoxThemeStruct m_theme;

    // <group DOM_SelectionBox_VcpResizableCompositionBox_Variable>
    // the height of area which is covered by others
    VfxU32 m_coveredHeight;

    // <group DOM_SelectionBox_VcpResizableCompositionBox_Variable>
    // the max width of box
    VfxU32 m_maxWidth;

    // <group DOM_SelectionBox_VcpResizableCompositionBox_Variable>
    // the size of box
    VcpResizableCompositionBoxSizeEnum m_size;
};

#endif /* __MMI_IME_FTE_ENHANCE__ */

#if defined __MMI_IME_SCROLLING_COMPOSITION__


class VcpScrollableSelBox : public  VcpScrollable 
{


public :
    VcpScrollableSelBox();
    virtual void onInit();


    void  setTheme(const VcpSelBoxThemeStruct &theme);

    VfxBool setHiliteCandidate(
        VfxS32 hiliteIndex              // [IN] the index of highlight candidate, -1 indicate no highlight candidate
        );

    // <group DOM_SelectionBox_VcpSelBox_Method>
    // get the index of highlight candidate
    // RETURNS: the index of highlight candidate, -1 if no highlight candidate
    VfxS32 getHiliteCandidate();


    VfxS32 update(
        const VfxWChar *candStr,        // [IN] the string of candidates
        VfxS32 count,                   // [IN] the count of candidates
        VfxS32 hiliteIndex,             // [IN] the index of highlight candidate, -1 indicate no highlight candidate
        VfxU32 flag                     // [IN] the flag of selection box
        // Note: please find the flag in VCP_SEL_BOX_FLAG_XXX
        );

    VfxSignal2 <
        VfxObject*,                     // sender
        VfxS32                          // the index of candidate
    > m_signalCandUp;


    VfxSignal2 <
        VfxObject*,                     // sender
        VfxS32                          // the index of candidate
    > m_signalCandDown;


    VfxS32 m_currHiliteCand;



    //void onButtonClick(VfxObject *selBox, VfxS32 index);
   /* void emitCandUpSignal(VfxS32 index);
    void emitCandDownSignal(VfxS32 index);*/
    void onButtonClick(VfxObject *selBox, VfxId index);
    void emitCandExpandSignal();
private : /* this should actually belong to derived class*/

    VcpScrollingTextButton* m_btnArray[20];
    VfxU32 m_candCount ;    
    VcpSelBoxThemeStruct m_theme;


};
#endif
#if defined __MMI_IME_CANDIDATE_GRID__

class VcpCandGrid : public  VfxControl
{
public:
    VcpScrollingTextButton* m_candArray[16];
    VcpButton* m_nextPage ;
    VcpButton* m_prePage ;
    VcpButton* m_back ;
    VcpButton* m_backspace;

    // <group DOM_SelectionBox_VcpSelBox_Variable>
    // the string of new word used in database
    VfxWString m_newWordStr;
    virtual void onInit();
    VcpCandGrid();
    void  setTheme(const VcpSelBoxThemeStruct &theme);


    VfxBool setHiliteCandidate(VfxS32 hiliteIndex);
    VfxTimer *m_repeatTimer;    
    VfxS32 getHiliteCandidate();
    VfxS32 m_candCount;
    VfxS32 m_currHiliteCand;
    VcpSelBoxThemeStruct m_theme;

    VfxSignal2 <
        VfxObject*,                     // sender
        VfxS32                          // the index of candidate
    > m_signalGridClick;

void layoutButtons();
    void onButtonClick(VfxObject *selBox, VfxId index);
void onButtonDown(VfxObject *selBox, VfxId index,VcpButtonStateEnum);
void repeatTimeup(VfxTimer *timerFunc);
void setNewWordString(const VfxWString &str);

    VfxS32 update(
        const VfxWChar *candStr,        // [IN] the string of candidates
        VfxS32 count,                   // [IN] the count of candidates
        VfxS32 hiliteIndex,             // [IN] the index of highlight candidate, -1 indicate no highlight candidate
        VfxU32 flag                     // [IN] the flag of selection box
        // Note: please find the flag in VCP_SEL_BOX_FLAG_XXX
        );

};

#endif 


#endif /* __VCP_SEL_BOX_H__ */

