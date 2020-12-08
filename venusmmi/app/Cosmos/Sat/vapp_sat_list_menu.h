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
 *  Vapp_sat_list_menu.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SAT List menu Class header file.
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

#ifndef __VAPP_SAT_LIST_MENU_H__
#define __VAPP_SAT_LIST_MENU_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#ifdef __cplusplus
extern "C"{
#endif
     
#include "MMIDataType.h"
#include "SatSrvGprot.h"

#ifdef __cplusplus
}
#endif

#include "vfx_mc_include.h"
#include "vcp_include.h"

#include "vfx_cpp_base.h"
#include "vfx_class_info.h"
#include "vfx_page_bar.h"
#include "vfx_datatype.h"
#include "vfx_string.h"

#include "vapp_sat_gprot.h"
#include "vapp_sat_base.h"
#include "mmi_rp_vapp_sat_def.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MMI_SAT_MENU_ITEM_MAX_NUM   64

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
#if defined(__MMI_MAINLCD_320X480__)
/* under construction !*/
/* under construction !*/
    #if defined(__MMI_VUI_COSMOS_CP__)
/* under construction !*/
/* under construction !*/
    #else
/* under construction !*/
/* under construction !*/
    #endif
/* under construction !*/
#elif defined(__MMI_MAINLCD_480X800__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_VUI_COSMOS_CP__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* Shell: QVGA / WQVGA */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/***************************************************************************** 
 * Class VappSatListMenuCellMultiLine
 *****************************************************************************/
class VappSatListMenuCellMultiLine : public VcpListMenuCellClientBaseFrame
{
    //VFX_DECLARE_CLASS(VappSatListMenuCellMultiLine);
// Constructor / Destructor
public:
    VappSatListMenuCellMultiLine();
    VappSatListMenuCellMultiLine(const VfxWString &text1, const VfxWString &text2 = VFX_WSTR_NULL);

    virtual ~VappSatListMenuCellMultiLine(){}

// Overridable
public:
    virtual void onCreateElements();
    virtual void onCloseElements();
    virtual void onLayoutElements();
    virtual void onUpdateElements();

// Variable
protected:
/* DOM-NOT_FOR_SDK-BEGIN */    
#if defined(__MMI_MAINLCD_320X480__)
    enum
    {
        TEXT1_LEFT_GAPS   = 10,
        TEXT1_RIGHT_GAPS  = 10,
        TEXT1_TOP_GAPS    = 6,
        TEXT2_LEFT_GAPS   = 10,
        TEXT2_RIGHT_GAPS  = 10,
        TEXT2_BOTTOM_GAPS = 6,
    #if defined(__MMI_VUI_COSMOS_CP__)
        LEFT_GAPS   =  10,
        RIGHT_GAPS  =  3
    #else
        LEFT_GAPS   =  3,
        RIGHT_GAPS  =  3
    #endif
    };
#elif defined(__MMI_MAINLCD_480X800__)
    enum
    {
        TEXT1_LEFT_GAPS   = 18,
        TEXT1_RIGHT_GAPS  = 18,
        TEXT1_TOP_GAPS    = 9,
        TEXT2_LEFT_GAPS   = 18,
        TEXT2_RIGHT_GAPS  = 18,
        TEXT2_BOTTOM_GAPS = 10,
        LEFT_GAPS   =  18,
        RIGHT_GAPS  =  18
    };
#elif defined(__MMI_VUI_COSMOS_CP__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__))
    enum
    {
        TEXT1_LEFT_GAPS   = 8,
        TEXT1_RIGHT_GAPS  = 8,
        TEXT1_TOP_GAPS    = 5,
        TEXT2_LEFT_GAPS   = 8,
        TEXT2_RIGHT_GAPS  = 8,
        TEXT2_BOTTOM_GAPS = 5,
        LEFT_GAPS   =  8,
        RIGHT_GAPS  =  8
    };
#else /* Shell: QVGA / WQVGA */
    enum
    {
        TEXT1_LEFT_GAPS   = 11,
        TEXT1_RIGHT_GAPS  = 8,
        TEXT1_TOP_GAPS    = 11,
        TEXT2_LEFT_GAPS   = 11,
        TEXT2_RIGHT_GAPS  = 8,
        TEXT2_BOTTOM_GAPS = 8,
        LEFT_GAPS   =  11,
        RIGHT_GAPS  =  2
    };
#endif
/* DOM-NOT_FOR_SDK-END */

    // The text element in this client frame
    VcpMarquee *m_marquee1;
    VcpMarquee *m_marquee2;

    VfxWString m_text1;
    VfxWString m_text2;

    //VfxRect m_rect1;
    //VfxRect m_rect2;
    VfxTextFrame *m_textView1;
    VfxTextFrame *m_textView2;
};

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
#if defined(__MMI_MAINLCD_320X480__)
/* under construction !*/
/* under construction !*/
#if defined(__MMI_VUI_COSMOS_CP__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#elif defined(__MMI_MAINLCD_480X800__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_VUI_COSMOS_CP__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* Shell: QVGA / WQVGA */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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

/***************************************************************************** 
 * Class VappSatListMenuCellIconMultiLine
 *****************************************************************************/
class VappSatListMenuCellIconMultiLine : public VcpListMenuCellClientBaseFrame
{
    //VFX_DECLARE_CLASS(VappSatListMenuCellIconMultiLine);
// Constructor / Destructor
public:
    VappSatListMenuCellIconMultiLine();
    VappSatListMenuCellIconMultiLine(const VfxImageSrc &imgScr, const VfxWString &text1, const VfxWString &text2);

    virtual ~VappSatListMenuCellIconMultiLine(){}

// Overridable
public:
    virtual void onCreateElements();
    virtual void onCloseElements();
    virtual void onLayoutElements();
    virtual void onUpdateElements();

// Variable
protected:
/* DOM-NOT_FOR_SDK-BEGIN */    
#if defined(__MMI_MAINLCD_320X480__)
    enum
    {
#if defined(__MMI_VUI_COSMOS_CP__)
        TEXT1_LEFT_GAPS   = 0,
        TEXT1_RIGHT_GAPS  = 10,
        TEXT1_TOP_GAPS    = 6,
        TEXT2_LEFT_GAPS   = 0,
        TEXT2_RIGHT_GAPS  = 10,
        TEXT2_BOTTOM_GAPS = 6,
        IMG_LEFT_GAPS     = 10,
        IMG_RIGHT_GAPS    = 10,
        IMG_MAX_WIDTH     = 30
#else
        TEXT1_LEFT_GAPS   = 0,
        TEXT1_RIGHT_GAPS  = 10,
        TEXT1_TOP_GAPS    = 15,
        TEXT2_LEFT_GAPS   = 0,
        TEXT2_RIGHT_GAPS  = 10,
        TEXT2_BOTTOM_GAPS = 11,
        IMG_LEFT_GAPS     = 11,
        IMG_RIGHT_GAPS    = 11,
        IMG_MAX_WIDTH     = 30
#endif
    };
#elif defined(__MMI_MAINLCD_480X800__)
    enum
    {
        TEXT1_LEFT_GAPS   = 0,
        TEXT1_RIGHT_GAPS  = 18,
        TEXT1_TOP_GAPS    = 9,
        TEXT2_LEFT_GAPS   = 0,
        TEXT2_RIGHT_GAPS  = 18,
        TEXT2_BOTTOM_GAPS = 10,
        IMG_LEFT_GAPS     = 14,
        IMG_RIGHT_GAPS    = 18,
        IMG_MAX_WIDTH     = 35
    };
#elif defined(__MMI_VUI_COSMOS_CP__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__))
    enum
    {
        TEXT1_LEFT_GAPS   = 0,
        TEXT1_RIGHT_GAPS  = 8,
        TEXT1_TOP_GAPS    = 5,
        TEXT2_LEFT_GAPS   = 0,
        TEXT2_RIGHT_GAPS  = 8,
        TEXT2_BOTTOM_GAPS = 5,
        IMG_LEFT_GAPS     = 8,
        IMG_RIGHT_GAPS    = 8,
        IMG_MAX_WIDTH     = 18
    };
#else /* Shell: QVGA / WQVGA */
    enum
    {
        TEXT1_LEFT_GAPS   = 0,
        TEXT1_RIGHT_GAPS  = 8,
        TEXT1_TOP_GAPS    = 11,
        TEXT2_LEFT_GAPS   = 0,
        TEXT2_RIGHT_GAPS  = 8,
        TEXT2_BOTTOM_GAPS = 8,
        IMG_LEFT_GAPS     = 8,
        IMG_RIGHT_GAPS    = 8,
        IMG_MAX_WIDTH     = 23
    };
#endif
/* DOM-NOT_FOR_SDK-END */

    // The text element in this client frame
    VcpMarquee *m_marquee1;
    VcpMarquee *m_marquee2;
    VfxImageFrame *m_imageFrame;

    VfxWString m_text1;
    VfxWString m_text2;
    VfxImageSrc m_imgSrc;

    VfxTextFrame *m_textView1;
    VfxTextFrame *m_textView2;
};


/***************************************************************************** 
 * Class VappSatGroupListHeader
 *****************************************************************************/
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
/***************************************************************************** 
 * Class VappSatMenuPage
 *****************************************************************************/

//class VappSatMenuPage : public VappSatBasePage, IVcpGroupListMenuContentProvider 
class VappSatMenuPage : public VappSatBasePage, IVcpListMenuContentProvider

{
    //VFX_DECLARE_CLASS(VappSatMenuPage);

public:

    VappSatMenuPage();

    VappSatMenuPage(srv_sat_proactive_sim_struct *cmdInfo);
#if 0
/* under construction !*/
#endif
    VappSatMenuPage(mmi_sim_enum simId, srv_sat_setup_menu_struct *mainmenu, VfxBool isTitlebar = VFX_TRUE);

    virtual ~VappSatMenuPage(){}

private:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onUpdate();
    virtual mmi_ret onProc(mmi_event_struct *evt);

    virtual VfxBool onResponse(VappSatToolbarTypeEnum BtnId);

    void cmdParser();
    void setItemData(VfxS32 num, srv_sat_item_struct *items);
    void setTitleData(srv_sat_icon_struct iconInfo, WCHAR *string);

public:
    //virtual VfxU32 getGroupCount() const {return m_groupNum;}
    virtual VfxU32 getCount() const {return m_listNum;}
	//virtual VfxBool getHeaderText(VfxWString &text) {return VFX_FALSE;}
	virtual VfxBool getText(VfxS32 index, VfxWString &text) {return VFX_FALSE;}
	//virtual VfxU32 getUpdatedCount(void) {return m_listNum;}

    //virtual VfxBool getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color);
	virtual VfxBool getItemText(
		  VfxU32 index, 				  // [IN] the index of item
		  VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
		  VfxWString &text, 			  // [OUT] the text resource
		  VcpListMenuTextColorEnum &color // [OUT] the text color
		  );

	virtual VfxBool getItemTextFormat(VfxU32 index, VcpListMenuFieldEnum fieldType, VcpRichText &format);
    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(VfxU32 index, VfxFrame *parentFrame);
    virtual void closeItemCustomContentFrame(VfxU32 index, VcpListMenuCellClientBaseFrame *cell);
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    virtual VfxBool getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc &image);
#endif
    virtual VfxBool getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color);
    //virtual VfxBool hasGroupHeader(VfxS32 group) const;

public:
    void setItemNum(VfxU32 count) {m_listNum = count;}

    void setSelectedIndex(VfxU32 index) {m_selectedIndex = index;}
    VfxU32 getSelectedIndex() const {return m_selectedIndex;}

private:
    enum VappSatListMenuCellStyleEnum
    {
        VAPP_SAT_LIST_MENU_CELL_STYLE_NONE,
        VAPP_SAT_LIST_MENU_CELL_STYLE_SINGLE_TEXT,            // Single text cell
        VAPP_SAT_LIST_MENU_CELL_STYLE_MULTI_TEXT,             // One text and one sub-text in the second line
#ifndef __SAT_DISABLE_ICON_SUPPORT__
        VAPP_SAT_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT,       // One icon with single text cell, icon is on the left side
        VAPP_SAT_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT,        // One icon with one text and one sub-text in the second line
#endif //__SAT_DISABLE_ICON_SUPPORT__
        VAPP_SAT_LIST_MENU_CELL_STYLE_MAX
    };

    enum VappTapTypeEnum
    {
        SAT_LIST_ITEM_TAP,
        SAT_LIST_ITEM_CMD_TAP,

        SAT_TAP_END
    };

public:
    VfxU8 getMenuId();
    void setInService(VfxBool bVal);
    VfxBool getIsService() const;

    void setCellStyle(VappSatListMenuCellStyleEnum style);
    VappSatListMenuCellStyleEnum getCellStyle() const;

    //void setMenuMode(VcpListMenuModeEnum mode);
    //VcpListMenuModeEnum getMenuMode() const;

    void setMenuCtrlMode(VcpListMenuControlModeEnum mode);
    VcpListMenuControlModeEnum getMenuCtrlMode() const;

private:
    void updateListMenu();
    void onItemStateChanged(VcpListMenu *sender, VfxU32 pos, VcpListMenuItemStateEnum state);
    void onItemTapped(VcpListMenu *sender, VfxU32 pos);
    void onCmdBtnTapped(VcpListMenu *sender, VfxU32 pos);

protected:
    VappTapTypeEnum getTapType() const;
    void setTapType(VappTapTypeEnum tapType);

private:
    VfxBool m_bInService;
    VfxBool m_isTitlebar;
    VfxU32  m_groupNum;
    VfxU32  m_listNum;
    VfxS32  m_selectedIndex;

    VappTapTypeEnum m_tapType;

    //VappSatGroupListMenu    *m_listMenu;
    VcpListMenu *m_listMenu;
    VappSatListMenuCellStyleEnum    m_cellStyle;
    VcpListMenuModeEnum         m_menuMode;
    VcpListMenuControlModeEnum  m_menuCtrlMode;

    VfxU8 *m_itemText[MMI_SAT_MENU_ITEM_MAX_NUM];
    VfxU8 *m_itemHint[MMI_SAT_MENU_ITEM_MAX_NUM];
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    VfxU8 *m_itemIcon[MMI_SAT_MENU_ITEM_MAX_NUM];
#endif
};


#if (MMI_MAX_SIM_NUM >= 2)
/***************************************************************************** 
 * Class VappSatMainMenuCtrlPage
 *****************************************************************************/

class VappSatMainMenuCtrlPage : public VcpTabCtrlPage
{
    //VFX_DECLARE_CLASS(VappSatMainMenuCtrlPage);

public:
    VappSatMainMenuCtrlPage();

    virtual ~VappSatMainMenuCtrlPage(){}

private:
    virtual void onInit();
    virtual VfxPage *onCreateTabPage(VfxId tabId);
    virtual mmi_ret processProc(mmi_event_struct *evt);
    virtual void onTabSwitching(VfxId tabId);
    virtual mmi_ret onProc(mmi_event_struct *evt);

protected:
    enum
    {
        TAB_SIM1 = 1,
        TAB_SIM2,
#if (MMI_MAX_SIM_NUM >= 3)
        TAB_SIM3,

#if (MMI_MAX_SIM_NUM >= 4)
        TAB_SIM4,

#endif
#endif
        TAB_TOTAL
    };

private:
    void getTabTextIcon(mmi_sim_enum sim_id);
    void updateTab(mmi_sim_enum sim_id);

private:
    VappSatMenuPage *m_sat[TAB_TOTAL -1];
#if 0
/* under construction !*/
/* under construction !*/
#if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
#if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
#endif

    VfxWString      m_tabText[TAB_TOTAL];
    VcpStateImage   m_tabIcon[TAB_TOTAL];

};
#endif /* MMI_MAX_SIM_NUM >= 2 */

#endif /* __VAPP_SAT_LIST_MENU_H__ */
