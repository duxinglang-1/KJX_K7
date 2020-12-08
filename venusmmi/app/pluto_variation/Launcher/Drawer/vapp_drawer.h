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
 *  vapp_drawer.h
 *
 * Project:
 * --------
 *  Launcher
 *
 * Description:
 * ------------
 *  Launcher drawer
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_DRAWER_H__
#define __VAPP_DRAWER_H__


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_LAUNCHER__

#include "MMIDataType.h"
#include "vfx_datatype.h"
#include "vfx_app_cat_scr.h"
#include "vcp_status_icon_bar.h"
#include "vapp_drawer_builder.h"
#include "vapp_drawer_gprot.h"

extern "C" {
#include "mmi_frm_events_gprot.h"
#include "AlertScreen.h"
#include "AppMgrSrvGprot.h"
}

/*****************************************************************************
 * Define
 *****************************************************************************/

#if defined(__MMI_MAINLCD_480X800__)
static const VfxS32 VAPP_DRAWER_MAX_APP_DATA = 160;
static const VfxS32 VAPP_DRAWER_MAX_GROUP_APP_DATA = 4;
#elif defined(__MMI_MAINLCD_240X320__)
static const VfxS32 VAPP_DRAWER_MAX_APP_DATA = 54;
static const VfxS32 VAPP_DRAWER_MAX_GROUP_APP_DATA = 3;
#elif defined(__MMI_MAINLCD_240X400__)
static const VfxS32 VAPP_DRAWER_MAX_APP_DATA = 72;
static const VfxS32 VAPP_DRAWER_MAX_GROUP_APP_DATA = 3;
#else // default HVGA 320X480
static const VfxS32 VAPP_DRAWER_MAX_APP_DATA = 96;
static const VfxS32 VAPP_DRAWER_MAX_GROUP_APP_DATA = 4;
#endif


/***************************************************************************** 
 * Structure
 *****************************************************************************/

struct VappDrawerConfirmCtx
{
    MMI_STR_ID              string_id;
    mmi_event_notify_enum   event;
    mmi_confirm_type_enum   ctype;
    mmi_proc_func           proc;
};

struct VappDrawerPopupCtx
{
    MMI_STR_ID              string_id;
    mmi_event_notify_enum   event;
    MMI_ID                  parent_id;
};

/*****************************************************************************
 * Global Function
 *****************************************************************************/

void vapp_drawer_uninstall_app(VappDrawerCell *cell);

/***************************************************************************** 
 * Class VappDrawerScr
 *****************************************************************************/

class VappDrawerScr : public VfxAppCatScr
{
    VFX_DECLARE_CLASS(VappDrawerScr);

// Declaration
private:

// Constructor / Destructor
public:
    VappDrawerScr();
    
// Method
public:
    void reloadMainmenu();
    
    static void setOrganizeChanged(VfxBool organizeMode);

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    
    virtual void onEnter(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);
    virtual void onExited(VfxBool isBackward);
    virtual void onSnapshotEnter();
    virtual void onSnapshotExit();
    
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
// Variable
private:
    VcpStatusIconBar        *m_statusBar;
    VappDrawerPageMenu      *m_menu;
    VappDrawerBuilder       *m_builder;
    VfxFrame                *m_bgImageFrame;
    VfxFrame                *m_shortcutBarBgFrame;
    VfxFrame                *m_shortcutBarBgFrameShadow;
    VfxFrame                *m_lines[5];

    VfxBool m_isDataDirty;
    
    static VfxS32   m_currentPage;
    static VfxBool  m_isOrganizeMode;
    
// Implementation
private:
    void initMenu();
    void initUI();
    void deinitUI();
    
    void onAppClicked(VcpPageMenuCell *cell);
    void onOrganizeChanged(VfxBool organizeMode);
};

// utils
VfxS32 vappDrawerGetCellCountInPage();

#endif // __MMI_VUI_LAUNCHER__

#endif // __VAPP_DRAWER_H__

