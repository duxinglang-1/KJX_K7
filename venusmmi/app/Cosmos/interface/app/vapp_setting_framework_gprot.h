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
 *  vapp_setting_framework_gprot.h 
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_SETTING_FRAMEWORK_GPROT_H__
#define __VAPP_SETTING_FRAMEWORK_GPROT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
//#include "vapp_setting_framework.h"
//#include "vapp_setting_framework_cell_list.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/
#define SETTING_FRAMEWORK_MAX_DEPTH 5

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
    SETTING_MENU_NONE,
    SETTING_MAIN_MENU,
    
    SETTING_MENU_NETWORK_CONNECTIVITY,
    
    SETTING_MENU_THEME_SETTING,
    //SETTING_MENU_SOUND_SETTING,
    SETTING_MENU_SECURITY_SETTING,

	SETTING_MENU_DISPLAY_SETTING,
    SETTING_MENU_DATE_TIME_SETTING,
    SETTING_MENU_LANGUAGE_INPUT,
#if (MMI_MAX_SIM_NUM >= 2)
	SETTING_MENU_DUAL_SIM_SETTING,
#endif // (MMI_MAX_SIM_NUM >= 2)
    SETTING_MENU_ADVANCED_SETTING,
    
    //SETTING_MENU_CALL_SETTING,
    //SETTING_MENU_CONTACT_SETTING,
    //SETTING_MENU_MESSAGE_SETTING,
#if !defined(__LOW_COST_SUPPORT_COMMON__)
    SETTING_MENU_SCHEDULE_POWER,
#endif
    //SETTING_MENU_USAGE,
    //SETTING_MENU_FACTORY_RESTORE,

    SETTING_MENU_WALLPAPER_SETTING,
  
    SETTING_MENU_ITEM_END
} VappSettingPublicMenuItemEnum;

typedef VfxObject* (*VappSettingFWCreateCellHdlr)(VfxObject*);
typedef void (*VappSettingLaunchHdlr)(VfxMainScr*);
typedef VfxBool (*VappSettingCheckHdlr)(void);

typedef struct
{
    VfxId parentId; // Parent menu ID
    VfxId menuId;   // menu Id for public items
    VappSettingFWCreateCellHdlr createCellHandler;  // APP cell create handler

    // The following data will only be used if createCellHandler is NULL
    // It will simply implement a launcher cell
    VfxId titleStringId;  // title string ID
    VfxId hintStringId;   // hint string ID
    VfxId iconId; // Only for menu item on the main menu
    VappSettingLaunchHdlr launcherSettingHandler; // launcher handler
    
    VappSettingCheckHdlr checkHdlr; // return VFX_FALSE if the cell should be hidden.    
} VappSettingConfigStruct; 

/***************************************************************************** 
 * APIs for launch setting
 *****************************************************************************/
extern "C" MMI_ID vapp_setting_launch_by_menu_id(VappSettingPublicMenuItemEnum menu_id);
extern "C" MMI_ID vapp_setting_launch_by_hdlr(VappSettingLaunchHdlr launchHdlr);

/***************************************************************************** 
 * Class 
 *****************************************************************************/
/***************************************************************************** 
 * VappSettingFWMgr
 *****************************************************************************/
class VappSettingFWCellList;
class VappSettingFWCelllistCreator;
class VappSettingFWMgr : public VfxObject
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappSettingFWMgr);

    // Methods
    public:
    MMI_ID launchSetting(VfxU32 menuId = SETTING_MAIN_MENU, VappSettingLaunchHdlr launchHdlr = NULL);
    MMI_ID getAppId() {return m_appId;};
    
    // Internal
    
    // Typedef
    typedef struct
    {
        VfxId menuId;
        VfxPage *page;
        VappSettingFWCellList *menuCellList;
    } VappSettingFWHistory;
    VfxMainScr* getMainScr();
    public:
    VappSettingFWMgr() : m_topHistoryIdx(0), m_appId(0), m_mainScr(NULL), m_cellListCreator(NULL) {};
    private:
    friend class VappSettingMainScr;
    friend class VappSettingApp;
    void popMenu();
    void pushMenu(VfxId menuId);
    void setMainScr(VfxMainScr *mainScr) {m_mainScr = mainScr;};
    VfxBool isSettingMenuExist() {return m_topHistoryIdx;};


    // Variables
    private:
    VfxU8                        m_topHistoryIdx;
    VappSettingFWHistory         m_menuHistory[SETTING_FRAMEWORK_MAX_DEPTH];

    MMI_ID                        m_appId;
    VfxWeakPtr<VfxMainScr>        m_mainScr;
    VappSettingFWCelllistCreator *m_cellListCreator;
};
#endif /* __VAPP_SETTING_FRAMEWORK_GPROT_H__ */
 
