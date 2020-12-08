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
 *  vapp_hs_scr.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen APP category
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

#ifndef __VAPP_MM_SCR_H__
#define __VAPP_MM_SCR_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "GUI/vadp_p2v_theme_info.h"
#include "vcp_fancy_mode_menu.h"
#include "vcp_normal_mode_menu.h"

#include "vcp_app_scr.h"
#include "vfx_app_cat_scr.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vcp_softkey.h"
#include "vcp_matrix.h"
#include "vfx_string.h"
#include "vcp_title_bar.h"
#include "vfx_weak_ptr.h"
#include "vcp_shortcut.h"
#include "vrt_datatype.h"
#include "vfx_frame.h"
#include "vcp_option_menu.h"
#include "vfx_input_event.h"
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

#include "MMI_features.h"
#include "wgui_categories_list.h"
#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifdef __MMI_FTE_SUPPORT__
#define VAPP_MM_SHOW_STATUS_ICON_BAR   /* Show status icon bar in main menu screen */
#if defined(__MMI_MAINLCD_240X320__) && !defined (__MMI_VECTOR_FONT_SUPPORT__)
#define VAPP_MM_SHOW_INTEGRATED_TITLE  /* Show integrated title in main menu screen */
#else /* defined(__MMI_MAINLCD_320X240__) && defined (__MMI_VECTOR_FONT_SUPPORT__) */
#undef VAPP_MM_SHOW_INTEGRATED_TITLE  /* Show integrated title in main menu screen */
#endif /* defined(__MMI_MAINLCD_320X240__) && defined (__MMI_VECTOR_FONT_SUPPORT__) */
#elif defined(__MMI_MAINLCD_320X240__)
#undef VAPP_MM_SHOW_STATUS_ICON_BAR   /* Show status icon bar in main menu screen */
#define VAPP_MM_SHOW_INTEGRATED_TITLE  /* Show integrated title in main menu screen */
#else
#define VAPP_MM_SHOW_STATUS_ICON_BAR   /* Show status icon bar in main menu screen */
#undef VAPP_MM_SHOW_INTEGRATED_TITLE  /* Show integrated title in main menu screen */
#endif
/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/***************************************************************************** 
 * Home screen APP category
 *****************************************************************************/

class VappMmScr : public VcpAppScr
{
// Declaration
public:
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        SOFTKEY_HEIGHT          = 51,
    #else
        SOFTKEY_HEIGHT          = 38,
    #endif
    #if defined(__MMI_MAINLCD_320X240__)    
        STATUS_ICON_BAR_HEIGHT  = 0,
        MAX_ROWS                = 3,
        MAX_COLUMNS             = 4,
    #else
        STATUS_ICON_BAR_HEIGHT  = 20,
        MAX_ROWS                = 4,
        MAX_COLUMNS             = 3,
    #endif
    #ifdef __MMI_FTE_SUPPORT__
        #if defined(__MMI_MAINLCD_240X320__) && !defined (__MMI_VECTOR_FONT_SUPPORT__)
            TITLE_HEIGHT = 34
	#else
            TITLE_HEIGHT = 0
        #endif
    #elif defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) 
        TITLE_HEIGHT = 0
    #else
        TITLE_HEIGHT = 36
    #endif

    };

//Constructor / Destructor
public: 
    VappMmScr(VfxU16* string_id, VfxU16* iconId, VfxS32 highlight_id, VfxU8* menuOrder, VfxU8 Style);

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxBool onEntryEffectIsDisabled();
    virtual void onEntryEffectInit();
    virtual void onEntryEffectStart();

//Slot
public:
    void onEventLsk(VcpSoftkeyEventEnum event_type);
    void onEventRsk(VcpSoftkeyEventEnum event_type);

    void onSoftkeyStateChanged(VcpMatrixSoftkeyState isDisabled);
    void onTitleChanged(const VfxWString &string);
    void onTitleChangedNoRedraw(const VfxWString &string);


public:
    VcpSimpleMatrix         *m_matrix;
    VcpSoftkey              *m_softkeybar;
    VfxWeakPtr <VcpPlutoTitleBar>   m_titleFrame;
    VadpTheme               *m_theme;
    VcpShortcut             *m_shortcut;

    VcpMatrixSoftkeyState   m_softkeyState;

private:
    // True: user press softkey; false: interrupt screen such as MT call or charger/earphone popup 
    static VfxBool          s_isLeaveScreenByUser;
    
    VfxU16                  m_stringID[12];
    VfxU16                  m_iconID[12];
    VfxS32                  m_highlightID;
    VfxU8                   m_menuOrder[12];
    VfxU8                   m_highlightEffect;

    void handleLsk(void *data);
    void handleRsk(void *data);
};

#ifdef __MMI_VUI_3D_MAINMENU__
#define VAPP_3D_MAINMENU_MAX_COUNT 60
#define VAPP_3D_MAINMENU_PAGE_COUNT 10

#if defined (__MMI_MAINLCD_240X320__)
	#define VAPP_3D_MAINMENU_NUM_IN_PAGE 9
#elif defined(__MMI_MAINLCD_240X400__)
	#define VAPP_3D_MAINMENU_NUM_IN_PAGE 12
#elif defined(__MMI_MAINLCD_320X480__)
	#define VAPP_3D_MAINMENU_NUM_IN_PAGE 16
#else
#define VAPP_3D_MAINMENU_NUM_IN_PAGE 16
#endif

#define VAPP_3D_MAINMENU_ORDER_SIZE 70
#define NVRAM_EF_VENUS_3D_MM_SIZE 70   // to do move to nvram_common_defs.h

class Vapp3DMmScr : public VcpAppScr
{
	// Declaration
	enum{
    #if defined(__MMI_MAINLCD_320X480__)
        SOFTKEY_HEIGHT          = 51,
		SOFTKEY_WIDTH			= 78,
		NORMAL_OFFSET_Y         = 11,
    #elif defined(__MMI_MAINLCD_240X320__)
        SOFTKEY_HEIGHT          = 38,
		SOFTKEY_WIDTH			= 57,
		NORMAL_OFFSET_Y         = 6,
    #elif defined(__MMI_MAINLCD_240X400__)
        SOFTKEY_HEIGHT          = 38,
		SOFTKEY_WIDTH			= 57,
		NORMAL_OFFSET_Y         = 6,
    #else
        SOFTKEY_HEIGHT          = 38,
		SOFTKEY_WIDTH			= 60,
		NORMAL_OFFSET_Y         = 6,
    #endif
        STATUS_ICON_BAR_HEIGHT = 20,
	};
	enum{
		NORMAL_MODE = 0,
		FANCY_MODE = 1,
		TWIST_STYLE = 0,
		SPACE_STYLE = 1,
	};
	//Constructor / Destructor
public: 
    Vapp3DMmScr(VfxU16 n_items, AppEntry *app_info, FuncPtr *launch_table, VfxU8 *order, VfxS32 curr_page, VfxU8 mode, VfxU8 style, VfxU8 index, VfxS32 foucus_index);
protected:
    virtual void onInit();
    virtual void onDeinit();
	//solt
public:
	void onEventLsk(VcpSoftkeyEventEnum event_type);
    void onEventRsk(VcpSoftkeyEventEnum event_type);
#ifdef __MMI_VUI_3D_MAINMENU_FANCY__
	void onEventCsk(VcpSoftkeyEventEnum event_type);
#endif
	void onAppClicked(VfxS32 appIndex);
    void onPageChanged(VfxS32 index);
	void onOrganizationChanged(VfxBool isOrganization);
private:
	VfxFrame *m_bg;
	VcpSoftkey *m_softkeybar;
	VfxS32 m_curr_page;
	AppEntry m_entry[VAPP_3D_MAINMENU_MAX_COUNT];
	VfxBool m_organizer;
	VfxU8 m_curr_index;
	FuncPtr m_launch[VAPP_3D_MAINMENU_MAX_COUNT];

public:
    VcpNormalModeMenu *m_normal;
    VcpNormalModeMenuBuilder *m_normalBuilder;
#ifdef __MMI_VUI_3D_MAINMENU_FANCY__
	VcpFancyModeMenu	  *m_fancy;
#endif
	VfxU16 m_items;
	VfxS32 m_order[VAPP_3D_MAINMENU_ORDER_SIZE];
	VfxU8 m_mode;
	VfxU8 m_style;
	VfxS32 m_focus;

private:
#ifdef __MMI_VUI_3D_MAINMENU_FANCY__
    VcpOptionMenu           *m_fancyList;
	VcpOptionMenuItem       **m_menuItems;
#endif
	VfxBool IsChanged;
	VfxBool Isblocking;
public:
	VfxS32 getCurrentPageIndex();
	VfxU8 getCurrentAppIndex();
	VfxS32 getCurrentFocusIndex();
	void leaveOrganizationMode(VfxBool saveChanges);
private:
	void CreateNormalMode();
	void handleRsk(void *data);
	void handleLsk(void *data);
	void writeMenuOrder(void);
#ifdef __MMI_VUI_3D_MAINMENU_FANCY__
	void CreateFancyMode();
	void CloseFancyMode(VfxU8 style);
	void onFancyModeLeave(void);
	void onFancyModeFinish(void);
	void EnterFancyMode(VfxU8 style, VfxBool IsAnim);
	void CreateOptionList();
    void onCandidateListSel(VcpOptionMenu *sender, VcpOptionMenu::VcpOptionMenuEventEnum evt, VcpOptionMenuItem *item);
#endif   
    VfxBool onKeyInput(VfxKeyEvent &event);  
};
#endif /*__MMI_VUI_3D_MAINMENU__ */
#endif /* __VAPP_MM_SCR_H__ */

