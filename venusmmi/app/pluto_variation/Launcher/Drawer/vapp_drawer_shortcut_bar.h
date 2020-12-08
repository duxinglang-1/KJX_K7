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
 *  vapp_drawer_shortcut_bar.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#ifndef __VAPP_DRAWER_SHORTCUT_BAR_H__
#define __VAPP_DRAWER_SHORTCUT_BAR_H__

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_VUI_LAUNCHER_KEY__)

#include "vfx_datatype.h"
#include "vfx_control.h"
#endif


#if defined(__MMI_VUI_LAUNCHER__)


#if defined(__MMI_MAINLCD_480X800__)
static const VfxS32 VAPP_DRAWER_SHORTCUT_BAR_CELL_COUNT = 4;

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
static const VfxS32 VAPP_DRAWER_SHORTCUT_BAR_CELL_COUNT = 3;

#else // default HVGA 320X480
static const VfxS32 VAPP_DRAWER_SHORTCUT_BAR_CELL_COUNT = 4;

#endif

class VappDrawerCell;

/*****************************************************************************
 * Class VappDrawerShortcutBar
 *****************************************************************************/
class VappDrawerShortcutBar : public VfxControl
{
public:
    VappDrawerShortcutBar();

    void reloadShortcutBar();

protected:
    virtual void onInit();
    virtual void onDeinit();

    virtual VfxBool onPenInput(VfxPenEvent &event);
    
private:
    VappDrawerCell * m_cell[VAPP_DRAWER_SHORTCUT_BAR_CELL_COUNT];
    mmi_app_package_name_struct m_targetAppName[VAPP_DRAWER_SHORTCUT_BAR_CELL_COUNT];
    VfxSignal1<VfxS32> m_appClicked;
    VfxBool m_startClick;
    VfxTimer * m_updateCacheTimer;

    void onAppClicked(VfxS32 index);
    void onUpdateCacheTimerTick(VfxTimer *source);

    void updateAppData();
    void updateCells();

    static mmi_ret eventHandler(mmi_event_struct *event);
};


// order data utils
mmi_app_package_name_struct * vappDrawerGetAllOrderData();
VfxS32 vappDrawerGetOrderCount();
void vappDrawerSetNeedSycn();
void vappDrawerCheckLoadOrderData();
VfxBool vappDrawerGetIsDataDirty();
void vappDrawerSaveData();
VfxBool isPreinstallApp(mmi_app_package_name_struct appName);

#endif // __MMI_VUI_LAUNCHER__

#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_VUI_LAUNCHER_KEY__)
// share adm with key launcher
VfxBool vappDrawerGetAppDataCache(mmi_app_package_name_struct &appName, U8 **imageMem);
void vappDrawerCreateCacheAdm();
void updateAppDataCache(mmi_app_package_name_struct * allOrderData, VfxS32 orderCount);

#endif

#endif // __VAPP_DRAWER_SHORTCUT_BAR_H__

