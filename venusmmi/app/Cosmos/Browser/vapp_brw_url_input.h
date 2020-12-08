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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * VappBrowserMain.h
 *
 * Project:
 * --------
 *   MAUI
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

#ifndef _VAPP_BRW_URL_INPUT_H_
#define _VAPP_BRW_URL_INPUT_H_

#include "MMI_include.h"
#include "MMIDataType.h"
#ifdef __MMI_BROWSER_2__

#ifdef __cplusplus
extern "C"
{
#endif /* __CPLUSPLUS__ */
#include "BrowserSrvInterface.h"
#include "BrowserSrvGprot.h"
#include "BrowserSrvMain.h"
#include "BrowserSrvSettings.h"
#ifdef __cplusplus
}
#endif /* __cplusplus */

#include "vcp_tabctrl_page.h"
#include "vcp_list_menu.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_page_panel.h"
#include "Lcd_sw_inc.h"
#include "mmi_rp_vapp_browser_def.h"

#if defined(__MMI_MAINLCD_320X480__)
	#define TEXT_EDITOR_HEIGHT 38
#elif defined(__MMI_MAINLCD_240X320__)
	#define TEXT_EDITOR_HEIGHT 36
#elif defined(__MMI_MAINLCD_240X400__)
	#define TEXT_EDITOR_HEIGHT 36
#else
	#define TEXT_EDITOR_HEIGHT 38
#endif 
#define TEXT_EDITOR_WIDTH_MARGIN 5
#define TEXT_EDITOR_HEIGHT_MARGIN 5

/****************************************************************************
* Class VappBrowserStoredPageDataProvider
****************************************************************************/
//class VappBrowserSearchListDataProvider : public IVcpListMenuContentProvider, public VfxObject
class VappBrowserSearchListDataProvider : public VfxObject,public IVcpListMenuContentProvider
{
public:
    VfxBool m_searchItemsEnabled;
    VfxWString m_inputText;

    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        );

    virtual VfxU32 getCount() const
    {
        VfxU32 totalCount = 0;
        #ifdef __MMI_BRW_URL_AUTO_COMPLETION__
        totalCount += srv_brw_address_list_get_matched_item_count();
        #endif
        totalCount += srv_brw_bookmark_list_get_matched_item_count();
        #ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
        if(m_searchItemsEnabled)
        {
             totalCount += srv_brw_search_list_get_matched_item_count();
        }
        #endif
        return totalCount;
    }
    virtual VfxBool getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        ) 
    {
        text.loadFromRes(STR_ID_VAPP_BRW_NO_MATCHED_ITEM);
        return VFX_TRUE;
    }

    virtual VfxBool getItemTextFormat(
        VfxU32 index,                   // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VcpRichText &format             // [OUT] the text resource
        );
};


class VappBrowserEditShortcut : public VfxPage
{
public:
    enum
    {
        EDIT_SHORTCUT_SAVE = 0,
        EDIT_SHORTCUT_CANCEL,
        EDIT_SHORTCUT_END
    } ;
    VfxS8 m_shortcutID;

    VcpTitleBar *m_titleBar;
    VcpTextEditor *m_inputEditor;
    VcpListMenu *m_searchItemList;
    VappBrowserSearchListDataProvider *m_editItemListContentProvider;
    VcpToolBar *m_toolBar;
    VfxU32 selectedShortcutIndex;
    VfxWChar *m_urlBuffer;
    VfxFrame *m_frame;
    VcpIndicatorPopup *m_popup;
    VfxU32 m_orignalBookmarks;

    VappBrowserEditShortcut(void):
        m_shortcutID(-1),
        m_inputEditor(NULL),
        m_searchItemList(NULL),
        m_editItemListContentProvider(NULL),
        m_toolBar(NULL),
        m_urlBuffer(NULL),
        m_frame(NULL),
        m_popup(NULL),
        m_orignalBookmarks(0)
    {
    }

    VappBrowserEditShortcut(VfxS8 selectedID):
        m_shortcutID(selectedID),
        m_inputEditor(NULL),
        m_searchItemList(NULL),
        m_editItemListContentProvider(NULL),
        m_toolBar(NULL),
        m_urlBuffer(NULL),
        m_frame(NULL),
        m_popup(NULL),
        m_orignalBookmarks(0)
    {
    }

	VappBrowserEditShortcut(const VfxWChar * url);
    virtual void onInit();
    virtual void onDeinit();
    void onItemTap(VcpListMenu *sender, VfxU32 index);
    void onTBClick(VfxObject* sender, VfxId id);
    void onTextChanged(VcpTextEditor *editor);
    //virtual VfxScrRotateTypeEnum onQueryRotate(const VfxScreenRotateParam &param);
    virtual void onQueryRotateEx(VfxScreenRotateParam & param);
    void onFuncBarItemSelected(VfxObject *sender, VfxId id);
	// While the LCD screen has been rotate
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    void handleKeyInput(VfxKeyEvent &event);
    void wifiBearerCallback(VfxU32 state, VfxU32 errorCause);
    void launchUrlCallback(void);
    virtual void onEnter(VfxBool isBackward);
	virtual void onEntered();
	virtual void onRotate(const VfxScreenRotateParam &param);
};



#endif /* __MMI_BROWSER_2__ */

#endif /* _VAPP_BRW_URL_INPUT_H_ */
