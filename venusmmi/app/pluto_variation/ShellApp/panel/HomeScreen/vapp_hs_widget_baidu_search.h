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
 *  vapp_hs_widget_baidu_search.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: Baidu Search
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_HS_WIDGET_BAIDU_SEARCH_H__
#define __VAPP_HS_WIDGET_BAIDU_SEARCH_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#include "MMI_features.h"
}
#endif

#ifdef __MMI_VUI_HOMESCREEN_BAIDU_SEARCH__
#include "vfx_uc_include.h"
#include "vapp_hs_res.h"
#include "vapp_hs_widget_base.h"
#include "vcp_button.h"
#include "vcp_text_editor.h"

#include "vfx_control.h"
#include "vfx_primitive_frame.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_basic_type.h"
#include "vfx_input_event.h"
#include "vapp_hs_widget_cfg.h"
#include "vapp_hs_def.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_frame.h"

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#include "mmi_rp_app_venus_hs_wg_baidu_def.h"
#include "HomeScreen\vadp_v2p_hs_widget_baidu_search.h"

}
#endif
/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Home screen widget: Baidu search category
 *****************************************************************************/
class VappHsWidgetBaiduSearchCategory : public VfxControl
{
//Implementation
private:
    // The enum map the Baidu Search Category enum to mmi_search_web_baidu_category_enum
    enum
    {
        CATEGORY_MAX_COUNT = 5// category total count
    };
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        IMAGE_X = 6, // Baidu logo x position
        IMAGE_Y = 0, // Baidu logo y position
        IMAGE_WIDTH = 67, // Baidu logo width
        IMAGE_HEIGHT = 33 // Baidu logo height
    #else
        IMAGE_X = 0, // Baidu logo x position
        IMAGE_Y = 2, // Baidu logo y position
        IMAGE_WIDTH = 61, // Baidu logo width
        IMAGE_HEIGHT = 26 // Baidu logo height
    #endif
    };
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        CATEGORY_X = 74, // category x position
        CATEGORY_Y = 9, // category y position
        CATEGORY_WIDTH = 44, // one category width
        CATEGORY_HEIGHT = 24, // one category height
        CATEGORY_GAP = 3 // gap between two cagetory text
    #else
        CATEGORY_X = 66, // category x position
        CATEGORY_Y = 7, // category y position
        CATEGORY_WIDTH = 31, // one category width
        CATEGORY_HEIGHT = 19, // one category height
        CATEGORY_GAP = 0 // gap between two cagetory text
    #endif
    };
    enum PenStateEnum
    {
        PEN_STATE_NONE = 0,
        PEN_STATE_DOWN,
        PEN_STATE_MOVE_IN,
        PEN_STATE_MOVE_OUT,
        PEN_STATE_UP
    };
//Implementation
private:
    VfxImageFrame *m_imageBaidu; // Baidu logo.

    VfxImageFrame *m_categoryTextUp[CATEGORY_MAX_COUNT]; // Category item up text of Baidu search.
    VfxImageFrame *m_categoryTextDown[CATEGORY_MAX_COUNT]; // Category item down text of Baidu search.
    mmi_search_web_baidu_category_enum m_category[CATEGORY_MAX_COUNT]; // Category enums of Baidu Search
    VfxS32 m_categoryCount; // the count of category item
    VfxS32 m_currentCategoryIndex; // current category item of search

    PenStateEnum m_penState; // Pen state of Baidu search category
    VfxS32 m_penSelectedCategoryIndex; // Is the category index that pen on.
private:
    void setCategoryTextState();
    VfxS32 getCategoryIndex(mmi_search_web_baidu_category_enum category);
    VfxBool isPenOnCategoryText(VfxS32 categoryIndex, VfxPoint penPos);
    void changeBaiduImage();
    void categoryTextDown(VfxS32 index);
    void categoryTextUp(VfxS32 index);

//Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxBool onPenInput(VfxPenEvent &event);

//Constructor / Destructor
public:
    VappHsWidgetBaiduSearchCategory();

//Method
public:
    // Get the current selected category.
    mmi_search_web_baidu_category_enum getCurrentCategory();
};

/***************************************************************************** 
 * Home screen widget: Baidu search
 *****************************************************************************/
class VappHsWidgetBaiduSearch : public VappHsWidget
{
    VAPP_HS_WIDGET_CREATE(VappHsWidgetBaiduSearch);

// Constructor / Destructor
public:
    // Default constructor
    VappHsWidgetBaiduSearch();

//Override
public:
    // get the image ID of widget bar icon
    // RETURNS: image ID
    virtual VfxU16 getIcon() { return VAPP_HS_IMG_WG_BAIDU_SEARCH; }
    virtual VfxU16 getName() { return VAPP_HS_STR_WG_BAIDU_SEARCH_TITLE; }
    virtual void onCreateView();
    virtual void onReleaseView();
    virtual void onAddToDesktop();
    virtual void onDeselect();
    VfxFrameImeModeEnum getImeMode();

//Override

protected:
    virtual void onObjectNotify(VfxId eventId, void *userData);
#if !(defined(__MMI_QWERTY_KEYPAD_SUPPORT__))
    virtual VfxBool onPreviewPenInput(VfxPenEvent &event);
#endif /* __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__ */

    void onFocusChanged(VfxBool focused);

//Event
protected:
    // Respond to the click event of search button
    // RETURNS: void
    void onSearchButtonClicked();

    // Respond to textview activated signal
    void onTextViewActivated(VcpTextEditor *textInput, VfxBool activated);

//Implementation
private:
    enum
    {
        INPUT_MAX_LENGTH = 32 // Is the max single line input length.
    };

    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        DEFAULT_WIDTH = 314, // default width of Baidu search
        DEFAULT_HEIGHT = 93 // default height of Baidu search
    #else
        DEFAULT_WIDTH = 231, // default width of Baidu search
        DEFAULT_HEIGHT = 70 // default height of Baidu search
    #endif
    };

    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        SEARCH_CATEGORY_X = 0, // search category x position
        SEARCH_CATEGORY_Y = 0, // search category y position
        SEARCH_CATEGORY_WIDTH = 314, // search category width
        SEARCH_CATEGORY_HEIGHT = 36 // search category height
    #else
        SEARCH_CATEGORY_X = 5, // search category x position
        SEARCH_CATEGORY_Y = 0, // search category y position
        SEARCH_CATEGORY_WIDTH = 224, // search category width
        SEARCH_CATEGORY_HEIGHT = 28 // search category height
    #endif
    };

    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        INPUT_X = 13, // editor input x position
        INPUT_Y = 45, // editor input y position
        INPUT_WIDTH = 242, // editor input width
        INPUTY_HEIGHT = 31 // editor input height
    #else
        INPUT_X = 10, // editor input x position
        INPUT_Y = 30, // editor input y position
        INPUT_WIDTH = 181, // editor input width
        INPUTY_HEIGHT = 24 // editor input height
    #endif
    };

    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        SEARCH_BUTTON_X = 261, // search category x position
        SEARCH_BUTTON_Y = 37, // search category y position
        SEARCH_BUTTON_WIDTH = 49, // search category width
        SEARCH_BUTTON_HEIGHT = 45 // search category height
    #else
        SEARCH_BUTTON_X = 198, // search category x position
        SEARCH_BUTTON_Y = 30, // search category y position
        SEARCH_BUTTON_WIDTH = 29, // search category width
        SEARCH_BUTTON_HEIGHT = 29 // search category height
    #endif
    };

#if !(defined(__MMI_QWERTY_KEYPAD_SUPPORT__))
    enum PenStateEnum
    {
        PEN_STATE_NONE = 0,
        PEN_STATE_DOWN,
        PEN_STATE_MOVE_IN,
        PEN_STATE_MOVE_OUT,
        PEN_STATE_UP
    };
#endif /* __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__ */

    VfxImageFrame *m_background; // Is the background of widget.
    VappHsWidgetBaiduSearchCategory *m_category; // Is the category member.
    VcpButtonInternal *m_searchButton; // Is search button.
    
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    VcpTextEditor *m_textInput;
#else
    VcpTextView *m_textInput; // single line editor
#endif

    VfxBool m_isDeselect;
    VfxBool m_firstAddToDesktop;

#if !(defined(__MMI_QWERTY_KEYPAD_SUPPORT__))
    VfxBool m_penOnInput;
    PenStateEnum m_penState; // Pen state of Baidu search category
#endif
};

#endif /* __MMI_VUI_HOMESCREEN_BAIDU_SEARCH__ */
#endif /* __VAPP_HS_WIDGET_BAIDU_SEARCH_H__ */
