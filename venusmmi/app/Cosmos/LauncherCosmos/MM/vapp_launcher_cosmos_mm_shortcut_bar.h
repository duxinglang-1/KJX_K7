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
 *  vapp_launcher_cosmos_mm_shortcut_bar.h
 *
 * Project:
 * --------
 *  Cosmos Launcher 2.0 - Launcher Cosmos
 *
 * Description:
 * ------------
 *  Launcher Cosmos Main Menu Shortcut Bar
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


#ifndef __VAPP_LAUNCHER_COSMOS_MM_SHORTCUT_BAR_H__
#define __VAPP_LAUNCHER_COSMOS_MM_SHORTCUT_BAR_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_LAUNCHER_COSMOS__


/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_control.h"
#include "vfx_datatype.h"
#include "vfx_page_transition.h"    // for VfxPageTransition
#include "vfx_signal.h"

#include "vapp_launcher.h"

#include "vapp_launcher_cosmos_mm.h"
#include "vapp_launcher_cosmos_mm_builder.h"
#include "vapp_launcher_cosmos_mm_page_menu.h"


/*****************************************************************************
 * Define
 *****************************************************************************/

#define VAPP_LAUNCHER_COSMOS_MM_USE_PAGE_CUSTOM_OUT


/*****************************************************************************
 * Global Variable
 *****************************************************************************/

#if defined(__MMI_MAINLCD_480X800__)
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_CELL_COUNT = 4;

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_CELL_COUNT = 4;

#else // default HVGA 320X480
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_CELL_COUNT = 4;

#endif

static const VfxU32 VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_EMPTY = 0xE0E0E0E0;
static const VfxU32 VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_DISABLED = 0xD0D0D0D0;
static const VfxU32 VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_DELETED = 0xD1D1D1D1;


/*****************************************************************************
 * Global Function
 *****************************************************************************/

// Order data utilities
extern void vappLauncherCosmosMmCheckLoadOrderData();
extern void vappLauncherCosmosMmSaveData();
extern VfxU32 *vappLauncherCosmosMmGetAllOrderData();
extern VfxBool vappLauncherCosmosMmGetIsDataDirty();
extern VfxS32 vappLauncherCosmosMmGetSycnVersion();
extern void vappLauncherCosmosMmSetNeedSycn();

// Cache data utilities
extern VfxS32 vappLauncherCosmosMmGetStringWidth(mmi_app_package_name_struct &appName);
extern void vappLauncherCosmosMmSetStringWidth(mmi_app_package_name_struct &appName, VfxS16 stringWidth);
extern void vappLauncherCosmosMmClearStringWidth();


/*****************************************************************************
 * Class VappLauncherCosmosMmShortcutBar
 *****************************************************************************/

class VappLauncherCosmosMmShortcutBar : public VfxControl
{
    VFX_DECLARE_CLASS(VappLauncherCosmosMmShortcutBar);
    
// Constructor / Destructor
public:
    VappLauncherCosmosMmShortcutBar();

// Method
public:
    void reloadShortcutBar();

    static void setIsEnterMainmenu(VfxBool isEnterMainmenu);
    
// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

    virtual VfxBool onPenInput(VfxPenEvent &event);
    
// Variable
private:
    mmi_app_package_name_struct     m_targetAppName[VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_CELL_COUNT];
    VappLauncherCosmosMmCell                *m_cell[VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_CELL_COUNT];
    
    VfxS32                          m_dataSyncVersion;
    
    VfxBool                         m_startClick;
    
    VfxTimer                        *m_updateCacheTimer;
    
    VappLauncherCosmosMmContent             *m_content;
    VfxWeakPtr<VappLauncherCosmosMmPage>    m_mainmenu;

    static VfxBool                  s_isEnterMainmenu;

// Implementation
private:
    void updateAppData();
    void updateCells();

    void createTestbedCell(VfxS32 index);
    
    void onUpdateCacheTimerTick(VfxTimer *source);
    void onAppClicked(VfxS32 index);
    void onLeaveMainmenuTransition(VfxBool in, VfxS32 direction);

    VappLauncher *findLauncher();
    void pushMainmenuPage();
    void emitMainmenuLaunchedSignel();

    static mmi_ret eventHandler(mmi_event_struct *event);
    
// Signal
private:
    VfxSignal1<VfxS32> m_appClicked;
    
public:
    VfxSignal0 m_mainmenuLaunched;
};


/*****************************************************************************
 * Class VfxNullPageSlideTransition
 *****************************************************************************/

class VfxNullPageSlideTransition : public VfxPageTransition
{
    VFX_DECLARE_CLASS(VfxNullPageSlideTransition);

// Constructor / Destructor
public:
    VfxNullPageSlideTransition();

// Override
protected:
    virtual void customPrepare(VfxBool in, VfxS32 direction, const VfxScreenRotateParam *param);
    virtual void customStart(VfxBool in, VfxS32 direction, VfxMsec duration);
    virtual void customStop(VfxBool in, VfxS32 direction, VfxMsec duration);
#ifdef VAPP_LAUNCHER_COSMOS_MM_USE_PAGE_CUSTOM_OUT
    virtual VfxBool customOuted();
#endif
};


/*****************************************************************************
 * Class VfxMMSimplePageSlideTransition
 *****************************************************************************/

class VfxMMSimplePageSlideTransition : public VfxPageTransition
{
    VFX_DECLARE_CLASS(VfxMMSimplePageSlideTransition);

// Constructor / Destructor
public:
    VfxMMSimplePageSlideTransition();

// Override
protected:
    virtual void customPrepare(VfxBool in, VfxS32 direction, const VfxScreenRotateParam *param);
    virtual void customStart(VfxBool in, VfxS32 direction, VfxMsec duration);
    virtual void customStop(VfxBool in, VfxS32 direction, VfxMsec duration);
#ifdef VAPP_LAUNCHER_COSMOS_MM_USE_PAGE_CUSTOM_OUT
    virtual VfxBool customOuted();
#endif
};


#endif // __MMI_VUI_LAUNCHER_COSMOS__


#endif // __VAPP_LAUNCHER_COSMOS_MM_SHORTCUT_BAR_H__

