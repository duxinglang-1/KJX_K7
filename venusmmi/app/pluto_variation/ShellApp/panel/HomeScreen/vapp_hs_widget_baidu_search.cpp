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
 *  vapp_hs_widget_baidu_search.cpp
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
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#include "MMI_features.h"
#include "MMIDataType.h"
#include "mmi_rp_app_venus_hs_wg_baidu_def.h"
}
#endif 

#ifdef __MMI_VUI_HOMESCREEN_BAIDU_SEARCH__
#include "vapp_hs_widget_baidu_search.h"

#ifdef __cplusplus
extern "C"
{
#ifdef __MMI_TOUCH_SCREEN__
#include "gui_touch_feedback.h"
#endif /*__MMI_TOUCH_SCREEN__*/
}
#endif 

#include "vadp_v2p_hs_widget_baidu_search.h"
#include "vfx_primitive_frame.h"

#ifdef __cplusplus
extern "C"
{
#include "SearchWebBaiduProt.h"
#include "kal_release.h"
#include "kal_non_specific_general_types.h"
}
#endif

#include "vfx_input_event.h"
#include "vadp_v2p_inputbox.h"
#include "vfx_signal.h"
#include "vapp_hs_widget_base.h"


/***************************************************************************** 
 * Home screen widget: Baidu Search Category
 *****************************************************************************/

VappHsWidgetBaiduSearchCategory::VappHsWidgetBaiduSearchCategory() :
    m_imageBaidu(NULL),
    m_categoryCount(0),
    m_currentCategoryIndex(0),
    m_penState(PEN_STATE_NONE),
    m_penSelectedCategoryIndex(0)
{
    VfxS32 i;

    for (i = 0; i < CATEGORY_MAX_COUNT; i++)
    {
        m_categoryTextUp[i] = NULL;
        m_categoryTextDown[i] = NULL;
        m_category[i] = MMI_SEARCH_WEB_BAIDU_CATEGORY_END_OF_ENUM;
    }
}


void VappHsWidgetBaiduSearchCategory::onInit()
{
    VfxControl::onInit();
    m_categoryCount = vadp_v2p_hs_baidu_search_get_categories(
                          (VfxU32)CATEGORY_MAX_COUNT,
                          m_category);
    // Get the default current category index
    m_currentCategoryIndex = getCategoryIndex(vadp_v2p_hs_baidu_search_get_current_category());

    VFX_OBJ_CREATE(m_imageBaidu, VfxImageFrame, this);
    m_imageBaidu->setPos(VfxPoint(IMAGE_X, IMAGE_Y));
    m_imageBaidu->setBounds(VfxRect(0, 0, IMAGE_WIDTH, IMAGE_HEIGHT));
    m_imageBaidu->setResId(
        vadp_v2p_hs_baidu_search_get_category_icon(
            m_category[m_currentCategoryIndex]));

    VfxS32 i;
    for (i = 0; i < m_categoryCount; i++)
    {
        // Create the category button
        VFX_OBJ_CREATE(m_categoryTextUp[i], VfxImageFrame, this);
        VFX_OBJ_CREATE(m_categoryTextDown[i], VfxImageFrame, this);

        VfxS32 upTextIcon, downTextIcon;
        vadp_v2p_hs_baidu_search_get_category_string(
            m_category[i],
            &upTextIcon,
            &downTextIcon);

        m_categoryTextUp[i]->setResId(upTextIcon);
        m_categoryTextUp[i]->setPos(
            VfxPoint(CATEGORY_X + i * (CATEGORY_WIDTH + CATEGORY_GAP), CATEGORY_Y));
        m_categoryTextUp[i]->setBounds(VfxRect(0, 0, CATEGORY_WIDTH, CATEGORY_HEIGHT));
        m_categoryTextUp[i]->setIsCached(VFX_TRUE);

        m_categoryTextDown[i]->setResId(downTextIcon);
        m_categoryTextDown[i]->setPos(
            VfxPoint(CATEGORY_X + i * (CATEGORY_WIDTH + CATEGORY_GAP), CATEGORY_Y));
        m_categoryTextDown[i]->setBounds(VfxRect(0, 0, CATEGORY_WIDTH, CATEGORY_HEIGHT));
        m_categoryTextDown[i]->setIsCached(VFX_TRUE);
    }
    setCategoryTextState();
}


void VappHsWidgetBaiduSearchCategory::onDeinit()
{
    VfxControl::onDeinit();
}


mmi_search_web_baidu_category_enum VappHsWidgetBaiduSearchCategory::getCurrentCategory()
{
    mmi_search_web_baidu_category_enum category = MMI_SEARCH_WEB_BAIDU_CATEGORY_TOTAL;
    if (m_currentCategoryIndex >= 0 && m_currentCategoryIndex < m_categoryCount)
    {
        category = m_category[m_currentCategoryIndex];
    }
    else
    {
        VFX_ASSERT(0);
    }
    return category;
}


VfxS32 VappHsWidgetBaiduSearchCategory::getCategoryIndex(
        mmi_search_web_baidu_category_enum category)
{
    VfxS32 i;
    for (i = 0; i < m_categoryCount; i++)
    {
        if (category == m_category[i])
        {
            break;
        }
    }
    if (i >= m_categoryCount)
    {
        VFX_ASSERT(0);
    }
    return i;
}


void VappHsWidgetBaiduSearchCategory::setCategoryTextState()
{
    VfxS32 i;
    for(i = 0; i < m_categoryCount; i++)
    {
        if (i == m_currentCategoryIndex)
        {
            m_categoryTextDown[i]->setHidden(VFX_FALSE);
            m_categoryTextUp[i]->setHidden(VFX_TRUE);
        }
        else
        {
            m_categoryTextDown[i]->setHidden(VFX_TRUE);
            m_categoryTextUp[i]->setHidden(VFX_FALSE);
        }
    }
}


VfxBool VappHsWidgetBaiduSearchCategory::onPenInput(VfxPenEvent &event)
{
    VfxBool ret;  
    VfxPoint pos;
    VfxS32 i;

    pos = event.getRelPos(this);
    ret = VFX_TRUE;

    if (containPoint(pos) == VFX_FALSE && event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        return VFX_FALSE;
    }
    
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        for(i = 0; i < m_categoryCount; i++)
        {
            if (isPenOnCategoryText(i, pos))
            {
                m_penSelectedCategoryIndex = i;
                m_penState = PEN_STATE_DOWN;
                categoryTextDown(i);
            #ifdef __MMI_TOUCH_SCREEN__
                gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
            #endif
                return ret;
            }
        }
        ret = VFX_FALSE;
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        for(i = 0; i < m_categoryCount; i++)
        {
            if (isPenOnCategoryText(i, pos))
            {
                if (m_penState == PEN_STATE_DOWN &&
                    m_penSelectedCategoryIndex != m_currentCategoryIndex &&
                    i == m_penSelectedCategoryIndex)
                {
                    m_currentCategoryIndex = m_penSelectedCategoryIndex;
                    setCategoryTextState();
                    changeBaiduImage();
                    vadp_v2p_hs_baidu_search_set_default_category(
                        m_category[m_currentCategoryIndex]);
                    break;
                }
            }
        }
        categoryTextUp(m_penSelectedCategoryIndex);
        m_penState = PEN_STATE_NONE;
        m_penSelectedCategoryIndex = m_categoryCount;
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        for(i = 0; i < m_categoryCount; i++)
        {
            if (isPenOnCategoryText(i, pos))
            {
                if ((m_penState == PEN_STATE_DOWN ||
                     m_penState == PEN_STATE_MOVE_IN) &&
                    m_penSelectedCategoryIndex == i)
                {
                    return ret;
                }
                categoryTextUp(m_penSelectedCategoryIndex);
                m_penState = PEN_STATE_MOVE_IN;
                m_penSelectedCategoryIndex = i;
                categoryTextDown(m_penSelectedCategoryIndex);
                return ret;
            }
        }
        m_penState = PEN_STATE_MOVE_OUT;
        categoryTextUp(m_penSelectedCategoryIndex);
        m_penSelectedCategoryIndex = m_categoryCount;
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_ABORT)
    {
        categoryTextUp(m_penSelectedCategoryIndex);
        m_penState = PEN_STATE_NONE;
        m_penSelectedCategoryIndex = m_categoryCount;
    }

    return ret;
}


void VappHsWidgetBaiduSearchCategory::changeBaiduImage()
{
    if (m_currentCategoryIndex >= 0 && m_currentCategoryIndex < m_categoryCount)
    {
        m_imageBaidu->setResId(
            vadp_v2p_hs_baidu_search_get_category_icon(
                m_category[m_currentCategoryIndex]));
    }
    else
    {
        VFX_ASSERT(0);
    }
}


VfxBool VappHsWidgetBaiduSearchCategory::isPenOnCategoryText(
         VfxS32 categoryIndex,
         VfxPoint penPos)
{
    VfxPoint pos = m_categoryTextUp[categoryIndex]->getPos();
    VfxRect bounds = m_categoryTextUp[categoryIndex]->getBounds();
    VfxS32 x = penPos.x - pos.x;
    VfxS32 y = penPos.y - pos.y;
    
    if (x >= 0 && x < bounds.size.width &&
        y >= 0 && y < bounds.size.height)
    {
        return VFX_TRUE;
    }
    return VFX_FALSE;
}


void VappHsWidgetBaiduSearchCategory::categoryTextDown(VfxS32 index)
{
    if (index >= 0 && index < m_categoryCount)
    {
        VfxPoint pos;
        pos = m_categoryTextUp[index]->getPos();
        pos.x++;
        pos.y++;
        m_categoryTextUp[index]->setPos(pos);
    }
}


void VappHsWidgetBaiduSearchCategory::categoryTextUp(VfxS32 index)
{
    if (index >= 0 && index < m_categoryCount)
    {
        VfxPoint pos;
        pos = m_categoryTextUp[index]->getPos();
        pos.x--;
        pos.y--;
        m_categoryTextUp[index]->setPos(pos);
    }
}


/***************************************************************************** 
 * Home screen widget: Baidu search
 *****************************************************************************/


#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
VcpTextEditorHistoryStruct g_textInputHistory = {0};
#endif

VappHsWidgetBaiduSearch::VappHsWidgetBaiduSearch() :
    m_background(NULL),
    m_category(NULL),
    m_searchButton(NULL),
    m_textInput(NULL),
    m_isDeselect(VFX_FALSE),
    m_firstAddToDesktop(VFX_FALSE)
#if !(defined(__MMI_QWERTY_KEYPAD_SUPPORT__))
    ,m_penOnInput(VFX_FALSE),
    m_penState(PEN_STATE_NONE)
#endif
{
}


void VappHsWidgetBaiduSearch::onCreateView()
{
    // Init Baidu Search App
    vadp_v2p_hs_baidu_search_init_cntx();

    VFX_OBJ_CREATE(m_background, VfxImageFrame, this);
    m_background->setPos(VFX_POINT_ZERO);
    m_background->setBounds(VfxRect(0, 0, DEFAULT_WIDTH, DEFAULT_HEIGHT));
    m_background->setResId(VAPP_HS_IMG_WG_BAIDU_SEARCH_BACKGROUND);

    setBounds(VfxRect(0, 0, DEFAULT_WIDTH, DEFAULT_HEIGHT));

    VFX_OBJ_CREATE(m_category, VappHsWidgetBaiduSearchCategory, this);
    m_category->setPos(VfxPoint(SEARCH_CATEGORY_X, SEARCH_CATEGORY_Y));
    m_category->setBounds(VfxRect(0, 0, SEARCH_CATEGORY_WIDTH, SEARCH_CATEGORY_HEIGHT));

    VFX_OBJ_CREATE(m_searchButton, VcpButtonInternal, this);
    m_searchButton->setPos(VfxPoint(SEARCH_BUTTON_X, SEARCH_BUTTON_Y));
    m_searchButton->setBounds(VfxRect(0, 0, SEARCH_BUTTON_WIDTH, SEARCH_BUTTON_HEIGHT));

    VfxImageSrc searchButtonDown(VAPP_HS_IMG_WG_BAIDU_SEARCH_BUTTON_DOWN);
    m_searchButton->setBackgroundDown(searchButtonDown);
    VfxImageSrc searchButtonUp(VAPP_HS_IMG_WG_BAIDU_SEARCH_BUTTON_UP);
    m_searchButton->setBackgroundUp(searchButtonUp);
    m_searchButton->m_eventUp.connect(this, &VappHsWidgetBaiduSearch::onSearchButtonClicked);

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    VFX_OBJ_CREATE(m_textInput, VcpTextEditor, this);
#else
    VFX_OBJ_CREATE(m_textInput, VcpTextView, this);
#endif
    
    m_textInput->setPos(VfxPoint(INPUT_X, INPUT_Y));
    m_textInput->setBounds(VfxRect(0, 0, INPUT_WIDTH, INPUTY_HEIGHT));
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    m_textInput->setText(
        (VfxWChar *)vadp_v2p_hs_baidu_search_get_text(),
        INPUT_MAX_LENGTH,
        VCP_TEXT_ENCODING_GB2312);
    m_textInput->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
	m_textInput->disableBackground(VFX_TRUE);
    m_textInput->m_signalActivated.connect(this, &VappHsWidgetBaiduSearch::onTextViewActivated);
	m_textInput->setAutoDeactivated(VFX_TRUE);
#else /* __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__ */
    m_textInput->setText((VfxWChar *)vadp_v2p_hs_baidu_search_get_text());
    m_textInput->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
    m_textInput->setHint(VFX_WSTR("Baidu"));
#endif /* __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__ */
        

    if (vadp_v2p_hs_baidu_search_get_input_reserve() == 0)
    {
    #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        m_textInput->setHighlight(0, m_textInput->getLength());
    #endif
    }
    m_firstAddToDesktop = VFX_TRUE;

    m_isDeselect = VFX_TRUE;
}


void VappHsWidgetBaiduSearch::onReleaseView()
{
    // Deinit Baidu Search App
    if (m_isDeselect == MMI_FALSE)
    {
        vadp_v2p_hs_baidu_search_set_input_reserve();
    #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
      //  m_textInput->getHistory(&(::g_textInputHistory));
    #endif
    }
    else
    {
        vadp_v2p_hs_baidu_search_reset_input_reserve();
    }
    VFX_OBJ_CLOSE(m_background);
    VFX_OBJ_CLOSE(m_category);
    VFX_OBJ_CLOSE(m_searchButton);
    VFX_OBJ_CLOSE(m_textInput);
    vadp_v2p_hs_baidu_search_release_cntx();
}

void VappHsWidgetBaiduSearch::onAddToDesktop()
{
    if (m_firstAddToDesktop == VFX_TRUE)
    {
        if (vadp_v2p_hs_baidu_search_get_input_reserve() != 0)
        {
        #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
            m_textInput->setHistory(&(::g_textInputHistory));
        #endif
        }
        m_firstAddToDesktop = VFX_FALSE;
    }
    m_isDeselect = VFX_FALSE;
    return;
}


void VappHsWidgetBaiduSearch::onFocusChanged(VfxBool focused)
{
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    if (!focused)
    {
        if (!m_isDeselect)
        {
            m_textInput->getHistory(&(::g_textInputHistory));
        }
    }
#endif 
}


VfxFrameImeModeEnum VappHsWidgetBaiduSearch::getImeMode()
{
    return VFX_FRAME_IME_MODE_SHIFT;
}


void VappHsWidgetBaiduSearch::onObjectNotify(VfxId id, void *userData)
{
    switch (id)
    {
        case VFX_FRAME_NOTIFY_ID_FOCUS_CHANGED:
        {
            onFocusChanged(*(VfxBool *)userData);
            return;
        }

        case VFX_FRAME_NOTIFY_ID_QUERY_IME_MODE:
        {
            getImeMode();
            return;
        }

        default:
        {
            VappHsWidget::onObjectNotify(id, userData);
            return;
        }
    }
}


void VappHsWidgetBaiduSearch::onDeselect()
{
    m_isDeselect = VFX_TRUE;
    return;
}

#if !(defined(__MMI_QWERTY_KEYPAD_SUPPORT__))
VfxBool VappHsWidgetBaiduSearch::onPreviewPenInput(VfxPenEvent &event)
{
    VfxPoint pos, penPos;
    VfxRect bounds = m_textInput->getBounds();
    pos = m_textInput->getPos();
    penPos = event.getRelPos(this);
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        if (penPos.x >= pos.x && penPos.x < pos.x + bounds.size.width &&
            penPos.y >= pos.y && penPos.y < pos.y + bounds.size.height)
        {
            m_penOnInput = VFX_TRUE;
            m_penState = PEN_STATE_DOWN;
        #ifdef __MMI_TOUCH_SCREEN__
            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
        #endif

            return VFX_TRUE;
        }
    }
    if (m_penOnInput == VFX_TRUE)
    {
        VfxBool ret = VFX_TRUE;
        if(event.type == VFX_PEN_EVENT_TYPE_UP)
        {
            if (penPos.x >= pos.x && penPos.x < pos.x + bounds.size.width &&
                penPos.y >= pos.y && penPos.y < pos.y + bounds.size.height)
            {
                if (m_penState == PEN_STATE_DOWN)
                {
                    // Enter full screen Edit
                    vadp_v2p_hs_baidu_search_start_edit();
                }
                else
                {
                    ; // recover normal edit
                }
            }
            m_penOnInput = VFX_FALSE;
            m_penState = PEN_STATE_NONE;
        }
        else if(event.type == VFX_PEN_EVENT_TYPE_MOVE)
        {
            if (penPos.x >= pos.x && penPos.x < pos.x + bounds.size.width &&
                penPos.y >= pos.y && penPos.y < pos.y + bounds.size.height)
            {
                if (m_penState == PEN_STATE_DOWN)
                {
                    return VFX_TRUE;
                }
                else
                {
                    m_penState = PEN_STATE_MOVE_IN;
                }
            }
            else
            {
                m_penState = PEN_STATE_MOVE_OUT;
            }
        }
        else if(event.type == VFX_PEN_EVENT_TYPE_ABORT)
        {
            m_penState = PEN_STATE_NONE;
            m_penOnInput = VFX_FALSE;
        }

        return ret;
    }
    return VFX_FALSE;
}
#endif


void VappHsWidgetBaiduSearch::onSearchButtonClicked()
{
    vadp_v2p_hs_baidu_search_launch_browser(
        m_category->getCurrentCategory(),
        m_textInput->getText());
    vadp_v2p_hs_baidu_search_reset_input_reserve();
}


void VappHsWidgetBaiduSearch::onTextViewActivated(VcpTextEditor *textInput, VfxBool activated)
{
    VFX_UNUSED(textInput);
    if (activated)
    {
        m_signalRequest.emit(this, REQ_ID_CHANGE_CUBE_TO_UNSCROLLABLE);
    }
    else
    {
        m_signalRequest.emit(this, REQ_ID_CHANGE_CUBE_TO_SCROLLABLE);
    }
}

#endif /* __MMI_VUI_HOMESCREEN_BAIDU_SEARCH__ */
