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
 *  vapp_drawer_shortcut_bar.cpp
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

#include "MMI_features.h"

/***************************************************************************** 
 * Include
 *****************************************************************************/

#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_VUI_LAUNCHER_KEY__)
extern "C" {
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "fs_gprot.h"
#include "gdi_include.h"
#include "AppMgrSrvGprot.h"
#include "nvram_common_defs.h"
}


// For VfxSize
#include "vfx_basic_type.h"
// For VfxWString
#include "vfx_string.h"

#include "vfx_cpp_base.h"
#include "vfx_datatype.h"

#include "vrt_datatype.h"

#include "vfx_image_src.h"

#endif /* __MMI_VUI_LAUNCHER__ || __MMI_VUI_LAUNCHER_KEY__ */


#ifdef __MMI_VUI_LAUNCHER__

#include "vapp_drawer.h" // for VAPP_DRAWER_MAX_APP_DATA, VAPP_DRAWER_MAX_GROUP_APP_DATA
#include "vapp_drawer_shortcut_bar.h"
#include "vapp_drawer_builder.h" // for createDrawerCell()
#include "vapp_drawer_gprot.h"
#include "mmi_rp_vapp_drawer_def.h"


#include "vapp_drawer_default_order.h"

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif // __MTK_TARGET__

#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif 


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined(__MMI_MAINLCD_480X800__)
static const VfxS32 VAPP_DRAWER_SHORTCUT_BAR_WIDTH = 480;
static const VfxS32 VAPP_DRAWER_SHORTCUT_BAR_HEIGHT = 120;
static const VfxS32 VAPP_DRAWER_SHORTCUT_BAR_CELL_OFFSET = 120;
static const VfxS32 VAPP_DRAWER_SHORTCUT_BAR_VISIBLE_SHIFT_Y = -3;

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
static const VfxS32 VAPP_DRAWER_SHORTCUT_BAR_WIDTH = 240;
static const VfxS32 VAPP_DRAWER_SHORTCUT_BAR_HEIGHT = 60;
static const VfxS32 VAPP_DRAWER_SHORTCUT_BAR_CELL_OFFSET = 80;
static const VfxS32 VAPP_DRAWER_SHORTCUT_BAR_VISIBLE_SHIFT_Y = -6;

#else // default HVGA 320X480
static const VfxS32 VAPP_DRAWER_SHORTCUT_BAR_WIDTH = 320;
static const VfxS32 VAPP_DRAWER_SHORTCUT_BAR_HEIGHT = 80;
static const VfxS32 VAPP_DRAWER_SHORTCUT_BAR_CELL_OFFSET = 80;
static const VfxS32 VAPP_DRAWER_SHORTCUT_BAR_VISIBLE_SHIFT_Y = -5;

#endif
static const VfxS32 VAPP_DRAWER_SAVED_DATA_COUNT = 34 * 3;

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
static VfxBool s_vappDrawerIsFirstLoad = VFX_TRUE;
static VfxBool s_vappDrawerNeedSync = VFX_TRUE;
static VfxS32 s_vappDrawerOrderCount = 0;
static VfxBool s_vappDrawerIsDataDirty = VFX_FALSE;
static mmi_app_package_name_struct s_vappDrawerAllOrderData[VAPP_DRAWER_SAVED_DATA_COUNT];


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

// predeclaration for drawer data utils

// remove the "delete" app in order list
// orderList [IN, OUT] : the order list to be compact
// maxDataCount [IN] : max data count in the order list
// return : data count after compact
static VfxS32 vappDrawerCompactData(mmi_app_package_name_struct * orderList, VfxS32 maxDataCount, VfxBool isNeedResetOrder);
static void vappDrawerCompactBarData(mmi_app_package_name_struct * barOrderList, VfxS32 maxBarDataCount);

static void sortAppListByDisplayName(mmi_app_package_name_struct * appList, VfxS32 appCount);

// allOrderData [OUT] : the order list to be compact
// pIsNeedResetOrder [OUT] : if is empty data in nvram
// return : data count after loading
static VfxS32 vappDrawerLoadData(mmi_app_package_name_struct * allOrderData, VfxBool * pIsNeedResetOrder);

// allOrderData [IN, OUT] : the order data to be compared with app manager data
static VfxS32 vappDrawerSyncAppMgr(mmi_app_package_name_struct * allOrderData, VfxS32 initOrderCount, VfxBool isNeedResetOrder, VfxBool * pIsDataDirty);

void updateAppDataCache(mmi_app_package_name_struct * allOrderData, VfxS32 orderCount);

static mmi_ret vappDrawerEventHandler(mmi_event_struct *event);

static VfxS32 vappDrawerCalculateOrderCount(mmi_app_package_name_struct *orderList);

/*****************************************************************************
 * Class VappDrawerShortcutBar
 *****************************************************************************/

VappDrawerShortcutBar::VappDrawerShortcutBar():
    m_startClick(VFX_FALSE),
    m_updateCacheTimer(NULL)
{
    for (VfxS32 i = 0; i < VAPP_DRAWER_SHORTCUT_BAR_CELL_COUNT; ++i)
    {
        m_cell[i] = NULL;
        strncpy(m_targetAppName[i], "", MMI_APP_NAME_MAX_LEN - 1);
    }
}

void VappDrawerShortcutBar::reloadShortcutBar()
{
    updateAppData();

    updateCells();

    VFX_ASSERT(m_updateCacheTimer);

    m_updateCacheTimer->setStartDelay(1);
    m_updateCacheTimer->start();
}

void VappDrawerShortcutBar::onInit()
{
    VfxControl::onInit();

    setSize(VAPP_DRAWER_SHORTCUT_BAR_WIDTH, VAPP_DRAWER_SHORTCUT_BAR_HEIGHT);

    m_appClicked.connect(this, &VappDrawerShortcutBar::onAppClicked);
    
    // update cache timer
    VFX_OBJ_CREATE(m_updateCacheTimer, VfxTimer, this);
    m_updateCacheTimer->m_signalTick.connect(this, &VappDrawerShortcutBar::onUpdateCacheTimerTick);

    reloadShortcutBar();

    mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_INSTALL_PACKAGE,  &VappDrawerShortcutBar::eventHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE,  &VappDrawerShortcutBar::eventHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE,  &VappDrawerShortcutBar::eventHandler, this);
}

void VappDrawerShortcutBar::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_APPMGR_INSTALL_PACKAGE, &VappDrawerShortcutBar::eventHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE, &VappDrawerShortcutBar::eventHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE, &VappDrawerShortcutBar::eventHandler, this);
    
    VfxControl::onDeinit();
}

VfxBool VappDrawerShortcutBar::onPenInput(VfxPenEvent &event)
{
    VfxPoint downPos = event.getRelDownPos(this);
    VfxS32 index = downPos.x / VAPP_DRAWER_SHORTCUT_BAR_CELL_OFFSET;
    if (index < 0)
    {
        index = 0;
    }
    if (index > VAPP_DRAWER_SHORTCUT_BAR_CELL_COUNT - 1)
    {
        index = VAPP_DRAWER_SHORTCUT_BAR_CELL_COUNT - 1;
    }

    if (event.type == VFX_PEN_EVENT_TYPE_UP || event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        VfxPoint pos = event.getRelPos(this);
        if ( (vfxAbs(pos.x - downPos.x) > VAPP_DRAWER_SHORTCUT_BAR_CELL_OFFSET) || 
            (vfxAbs(pos.y - downPos.y) > VAPP_DRAWER_SHORTCUT_BAR_HEIGHT) )
        {
            m_startClick = VFX_FALSE;
        }
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        m_startClick = VFX_TRUE;
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_ABORT)
    {
        m_startClick = VFX_FALSE;
    }

    if (m_startClick && event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        m_appClicked.postEmit(index);
        m_startClick = VFX_FALSE;
    }

    if (m_cell[index] != NULL)
    {
        if (m_startClick)
        {
            m_cell[index]->setOpacity(0.5f);
        }
        else
        {
            m_cell[index]->setOpacity(1.0f);
        }
    }
    
    return VFX_TRUE;
}

void VappDrawerShortcutBar::onAppClicked(VfxS32 index)
{
    if (strncmp(m_targetAppName[index], "", MMI_APP_NAME_MAX_LEN) == 0)
    {
        return;
    }
    srv_appmgr_launch(m_targetAppName[index]);
}

void VappDrawerShortcutBar::onUpdateCacheTimerTick(VfxTimer *source)
{
    for (VfxS32 i = 0; i < VAPP_DRAWER_SHORTCUT_BAR_CELL_COUNT; ++i)
    {
        if (m_cell[i] != NULL)
        {
            m_cell[i]->setCacheMode(VFX_CACHE_MODE_FREEZE);
        }
    }
}

void VappDrawerShortcutBar::updateAppData()
{
    vappDrawerCheckLoadOrderData();
    mmi_app_package_name_struct * barApp = vappDrawerGetAllOrderData();
    for (VfxS32 i = 0; i < VAPP_DRAWER_SHORTCUT_BAR_CELL_COUNT; ++i)
    {
        if (i == VAPP_DRAWER_SHORTCUT_BAR_CELL_COUNT - 1)
        {
            strncpy(m_targetAppName[i], "native.mtk.drawer", MMI_APP_NAME_MAX_LEN);
        }
        else
        {
            strncpy(m_targetAppName[i], barApp[i], MMI_APP_NAME_MAX_LEN - 1);
        }
    }
}

void VappDrawerShortcutBar::updateCells()
{
    for (VfxS32 i = 0; i < VAPP_DRAWER_SHORTCUT_BAR_CELL_COUNT; ++i)
    {
        // close cells need to be updated
        if (m_cell[i] != NULL)
        {
            mmi_app_package_name_struct appName;
            m_cell[i]->getCellAppName(appName);

            if (strncmp(m_targetAppName[i], appName, MMI_APP_NAME_MAX_LEN) == 0) 
            {
                continue;
            }
            VFX_OBJ_CLOSE(m_cell[i]);
        }

        if ( (strncmp(m_targetAppName[i], "", MMI_APP_NAME_MAX_LEN) == 0) ||
            (strncmp(m_targetAppName[i], "DELETED", MMI_APP_NAME_MAX_LEN) == 0) )
        {
            continue;
        }

        const VfxBool isPre = isPreinstallApp(m_targetAppName[i]);

        m_cell[i] = createDrawerCell(m_targetAppName[i], this, isPre);
        m_cell[i]->onCellDisplay();
        m_cell[i]->setPos(i * VAPP_DRAWER_SHORTCUT_BAR_CELL_OFFSET, VAPP_DRAWER_SHORTCUT_BAR_VISIBLE_SHIFT_Y);
    }

    for (VfxS32 i = 0; i < VAPP_DRAWER_SHORTCUT_BAR_CELL_COUNT; ++i)
    {
        if (m_cell[i] != NULL)
        {
            m_cell[i]->setOpacity(1.0f);
            m_cell[i]->setOnBottomBar(VFX_TRUE);
        }
    }
}

mmi_ret VappDrawerShortcutBar::eventHandler(mmi_event_struct *event)
{
    VappDrawerShortcutBar *shortcutBar = (VappDrawerShortcutBar *)event->user_data;

    switch (event->evt_id)
    {
        case EVT_ID_SRV_APPMGR_INSTALL_PACKAGE:
        case EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE:
        case EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE:
            shortcutBar->reloadShortcutBar();
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


// order data utils
VfxS32 vappDrawerCompactData(mmi_app_package_name_struct * orderList, VfxS32 maxDataCount, VfxBool isNeedResetOrder)
{
    VfxS32 orderCount = 0;
    VfxS32 i1 = 0;
    VfxS32 i2 = 0;
    VfxS32 countInPage = 0;
    
    while (i1 < maxDataCount)
    {
        if (strncmp(orderList[i1], "DELETED", MMI_APP_NAME_MAX_LEN) == 0)
        {
            i1 += 1;
            continue;
        }

        if (i1 != i2)
        {
            // special handling for deleting the icon which is the only one icon in a page
            if (i2 >= 1 && strncmp(orderList[i2 - 1], "", MMI_APP_NAME_MAX_LEN) == 0 &&
                strncmp(orderList[i1], "", MMI_APP_NAME_MAX_LEN) == 0)
            {
                i1 += 1;
                continue;
            }
            
            // Do not reserve space when first time bootup
            if (isNeedResetOrder && strncmp(orderList[i1], "", MMI_APP_NAME_MAX_LEN) == 0)
            {
                i1 += 1;
                continue;
            }
            if (isNeedResetOrder && countInPage == vappDrawerGetCellCountInPage())
            {
                strncpy(orderList[i2], "", MMI_APP_NAME_MAX_LEN - 1);
                i2 += 1;
                countInPage = 0;
                continue;
            }
            
            strncpy(orderList[i2], orderList[i1], MMI_APP_NAME_MAX_LEN - 1);
            strncpy(orderList[i1], "", MMI_APP_NAME_MAX_LEN - 1);
        }

        // successive empty string means end of data
        if (strncmp(orderList[i2], "", MMI_APP_NAME_MAX_LEN) == 0)
        {
            if (i2 >= 1 && strncmp(orderList[i2 - 1], "", MMI_APP_NAME_MAX_LEN) == 0)
            {
                i1 += 1;
                i2 += 1;
                orderCount = i2;
                break;
            }
        }
        i1 += 1;
        i2 += 1;
        orderCount = i2;
        countInPage += 1;
    }
    orderCount -= 2;

    // set the remaining to empty string
    if (i1 != i2)
    {
        while (i1 < maxDataCount)
        {
            strncpy(orderList[i1], "", MMI_APP_NAME_MAX_LEN - 1);
            i1 += 1;
        }
    }

    return orderCount;
}

void vappDrawerCompactBarData(mmi_app_package_name_struct * barOrderList, VfxS32 maxBarDataCount)
{
    VfxS32 i1 = 0;
    VfxS32 i2 = 0;
    while (i1 < VAPP_DRAWER_MAX_GROUP_APP_DATA - 1)
    {
        if (strncmp(barOrderList[i1], "DELETED", MMI_APP_NAME_MAX_LEN) == 0)
        {
            i1 += 1;
            continue;
        }

        if (i1 != i2)
        {
            strncpy(barOrderList[i2], barOrderList[i1], MMI_APP_NAME_MAX_LEN - 1);
        }

        i1 += 1;
        i2 += 1;
    }
    if (i1 != i2)
    {
        while (i2 < VAPP_DRAWER_MAX_GROUP_APP_DATA - 1)
        {
            strncpy(barOrderList[i2], "", MMI_APP_NAME_MAX_LEN - 1);
            i2 += 1;
        }
    }
}

VfxS32 vappDrawerLoadData(mmi_app_package_name_struct * allOrderData, VfxBool * pIsNeedResetOrder)
{
    mmi_app_package_name_struct * orderList = allOrderData + VAPP_DRAWER_MAX_GROUP_APP_DATA;
    mmi_app_package_name_struct * barOrderList = allOrderData;

    U8 * readBufferPointer = (U8*)allOrderData;
    for (VfxS32 i = 0; i < NVRAM_EF_VAPP_DRAWER_ORDER_DATA_TOTAL; ++i)
    {
        S16 error;

        ReadRecord(
            NVRAM_EF_VAPP_DRAWER_ORDER_DATA_LID,
            1+i,
            readBufferPointer + NVRAM_EF_VAPP_DRAWER_ORDER_DATA_SIZE * i,
            NVRAM_EF_VAPP_DRAWER_ORDER_DATA_SIZE,
            &error);

        MMI_ASSERT(error == NVRAM_READ_SUCCESS);
    }

    VfxS32 orderCount = vappDrawerCalculateOrderCount(orderList);
    
    VfxBool isNeedResetOrder = VFX_FALSE;
    if ( (orderCount == 0) && (strncmp(barOrderList[0], "", MMI_APP_NAME_MAX_LEN) == 0) )
    {
        isNeedResetOrder = VFX_TRUE;
    }

    if (isNeedResetOrder)
    {
        if (vappDrawerDefaultOrderCount > VAPP_DRAWER_MAX_GROUP_APP_DATA)
        {
            memcpy(allOrderData, vappDrawerDefaultOrder, VAPP_DRAWER_MAX_GROUP_APP_DATA * sizeof(mmi_app_package_name_struct) );
        }

        VfxS32 i = VAPP_DRAWER_MAX_GROUP_APP_DATA;
        orderCount = 0;
        VfxS32 countInPage = 0;
        while (i < vappDrawerDefaultOrderCount)
        {
            if (countInPage == vappDrawerGetCellCountInPage() )
            {
                strncpy(orderList[orderCount], "", MMI_APP_NAME_MAX_LEN - 1);
                ++orderCount;
                countInPage = 0;
            }

            // append
            strncpy(orderList[orderCount], vappDrawerDefaultOrder[i], MMI_APP_NAME_MAX_LEN - 1);
            ++orderCount;
            ++countInPage;
            ++i;
        }
        orderCount -= 2;
    }

    *pIsNeedResetOrder = isNeedResetOrder;

    return orderCount;
}

VfxS32 vappDrawerSyncAppMgr(mmi_app_package_name_struct * allOrderData, VfxS32 initOrderCount, VfxBool isNeedResetOrder, VfxBool * pIsDataDirty)
{
    U32 count = srv_appmgr_get_app_package_num(SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM4", SA_start);
#endif
    U32 preCount = srv_appmgr_get_app_package_num(SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE);

    U32 totalCount = count + preCount;
    mmi_app_package_name_struct * array = NULL;
    VFX_SYS_ALLOC_MEM(array, sizeof(mmi_app_package_name_struct) * totalCount);
    memset(array, 0, sizeof(mmi_app_package_name_struct) * totalCount);
    mmi_ret result;

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM4", SA_stop);
#endif
    result = srv_appmgr_get_app_package_list(SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE, array, count);
    VFX_ASSERT(result != MMI_RET_ERR);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM4", SA_start);
#endif
    result = srv_appmgr_get_app_package_list(SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE, array + count, preCount);
    VFX_ASSERT(result != MMI_RET_ERR);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM4", SA_stop);
#endif
    if (isNeedResetOrder)
    {
        sortAppListByDisplayName(array, totalCount);
    }
    // check if every thing in the current order list are in the app list
    VfxS32 countInPage = 0;
    VfxBool isDataDirty = VFX_FALSE;
    for (VfxS32 i = 0; i < VAPP_DRAWER_MAX_GROUP_APP_DATA + initOrderCount; ++i)
    {
        VfxBool found = VFX_FALSE;
        if (strncmp(allOrderData[i], "", MMI_APP_NAME_MAX_LEN) == 0)
        {
            countInPage = 0;
            continue;
        }

        for (VfxU32 j = 0; j < totalCount; ++j)
        {
            if (strncmp(allOrderData[i], array[j], MMI_APP_NAME_MAX_LEN) == 0)
            {
                strncpy(array[j], "ADDED", MMI_APP_NAME_MAX_LEN - 1);
                found = VFX_TRUE;
                break;
            }
        }

        if (!found)
        {
            if (i == (VAPP_DRAWER_SHORTCUT_BAR_CELL_COUNT - 1)) // do not update the last entry on bottom bar
            {
                continue;
            }
            if (strncmp(allOrderData[i], "DELETED", MMI_APP_NAME_MAX_LEN) != 0)
            {
                strncpy(allOrderData[i], "DELETED", MMI_APP_NAME_MAX_LEN - 1);
                isDataDirty = VFX_TRUE;
            }
        }
        else
        {
            ++countInPage;
        }
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM4", SA_start);
#endif

    // append apps not in the order list
    mmi_app_package_name_struct * orderList = allOrderData + VAPP_DRAWER_MAX_GROUP_APP_DATA;
    VfxS32 newOrderCount = initOrderCount;
    for (VfxU32 i = 0; i < totalCount; ++i)
    {
        if (newOrderCount >= VAPP_DRAWER_MAX_APP_DATA)
        {
            break;
        }
        
        if (strncmp(array[i], "ADDED", MMI_APP_NAME_MAX_LEN) == 0)
        {
            continue;
        }
        if (strncmp(array[i], "native.mtk.drawer", MMI_APP_NAME_MAX_LEN) == 0)
        {
            continue;
        }
        if (strncmp(array[i], "native.mtk.desktop", MMI_APP_NAME_MAX_LEN) == 0)
        {
            continue;
        }

        if (countInPage >= vappDrawerGetCellCountInPage() )
        {
            strncpy(orderList[newOrderCount], "", MMI_APP_NAME_MAX_LEN - 1);
            ++newOrderCount;
            countInPage = 0;
        }

        // append
        strncpy(orderList[newOrderCount], array[i], MMI_APP_NAME_MAX_LEN - 1);
        isDataDirty = VFX_TRUE;
        ++newOrderCount;
        ++countInPage;
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM4", SA_stop);
#endif
    VFX_SYS_FREE_MEM(array);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM4", SA_start);
#endif
    newOrderCount = vappDrawerCompactData(orderList, VAPP_DRAWER_MAX_APP_DATA, isNeedResetOrder);
    vappDrawerCompactBarData(allOrderData, VAPP_DRAWER_MAX_GROUP_APP_DATA);
    *pIsDataDirty = isDataDirty;
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM4", SA_stop);
#endif
    return newOrderCount;
}

static VfxU32 getAppTypeOrder(mmi_app_package_name_struct appName)
{
    srv_appmgr_app_package_type_enum type = srv_appmgr_get_app_package_type(appName);
    if (type == SRV_APPMGR_NATIVE_APP_PACKAGE_TYPE)
    {
        return 0;
    }
    else if (type == SRV_APPMGR_MRE_APP_PACKAGE_TYPE)
    {
        return 1;
    }
    else if (type == SRV_APPMGR_JAVA_APP_PACKAGE_TYPE)
    {
        return 2;
    }
    return 100;
}

void sortAppListByDisplayName(mmi_app_package_name_struct * appList, VfxS32 appCount)
{
    // construct the display name mapping
    mmi_ret result;
    WCHAR **names;
    VFX_SYS_ALLOC_MEM(names, sizeof(WCHAR*) * appCount + sizeof(WCHAR) * MMI_APP_NAME_MAX_LEN * appCount);
    memset(names, 0, sizeof(WCHAR) * MMI_APP_NAME_MAX_LEN * appCount);
    names[0] = (WCHAR*)(names + appCount );
    for (VfxS32 iPos = 0; iPos < appCount; ++iPos)
    {
        names[iPos] = names[0] + iPos * MMI_APP_NAME_MAX_LEN;
        result = srv_appmgr_get_app_package_name(appList[iPos], names[iPos]);
        VFX_ASSERT(result != MMI_RET_ERR);
    }

    // selection sort
    for (VfxS32 iPos = 0; iPos < appCount; ++iPos)
    {
        VfxS32 iMin = iPos;
        VfxU32 iMinTypeOrder = getAppTypeOrder(appList[iPos]);
        for (VfxS32 i = iPos + 1; i < appCount; ++i)
        {
            // first compare app type, then compare app display name
            VfxU32 typeOrder = getAppTypeOrder(appList[i]);
            if (typeOrder < iMinTypeOrder)
            {
                iMin = i;
                iMinTypeOrder = typeOrder;
            }
            else if (typeOrder == iMinTypeOrder)
            {
                if (wcsncmp((const wchar_t*)names[iMin], (const wchar_t*)names[i], MMI_APP_NAME_MAX_LEN) > 0)
                {
                    iMin = i;
                }
            }
        }
        // swap(iPos, iMin)
        mmi_app_package_name_struct packageTemp;
        strncpy(packageTemp, appList[iMin], MMI_APP_NAME_MAX_LEN - 1);
        strncpy(appList[iMin], appList[iPos], MMI_APP_NAME_MAX_LEN - 1);
        strncpy(appList[iPos], packageTemp, MMI_APP_NAME_MAX_LEN - 1);

        WCHAR* nameTemp;
        nameTemp = names[iMin];
        names[iMin] = names[iPos];
        names[iPos] = nameTemp;
    }

    VFX_SYS_FREE_MEM(names);
}


mmi_app_package_name_struct * vappDrawerGetAllOrderData()
{
    //VFX_ASSERT(VAPP_DRAWER_SAVED_DATA_COUNT >= (VAPP_DRAWER_MAX_APP_DATA + VAPP_DRAWER_MAX_GROUP_APP_DATA) );

    return s_vappDrawerAllOrderData;
}

VfxS32 vappDrawerGetOrderCount()
{
    return s_vappDrawerOrderCount;
}

void vappDrawerSetNeedSycn()
{
    s_vappDrawerNeedSync = VFX_TRUE;
}

void vappDrawerCheckLoadOrderData()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM0", SA_start);
#endif
    VfxBool isNeedResetOrder = VFX_FALSE;

    if (s_vappDrawerIsFirstLoad)
    {
        s_vappDrawerIsFirstLoad = VFX_FALSE;
        s_vappDrawerOrderCount = vappDrawerLoadData(s_vappDrawerAllOrderData, &isNeedResetOrder);

		vappDrawerCreateCacheAdm();
        
        mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_INSTALL_PACKAGE, vappDrawerEventHandler, NULL);
        mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE, vappDrawerEventHandler, NULL);
        mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE, vappDrawerEventHandler, NULL);
    }

    VfxBool dirtyWhenSync = VFX_FALSE;
    if (s_vappDrawerNeedSync)
    {
        s_vappDrawerNeedSync = VFX_FALSE;
        mmi_app_package_name_struct *orderList = s_vappDrawerAllOrderData + VAPP_DRAWER_MAX_GROUP_APP_DATA;
        s_vappDrawerOrderCount = vappDrawerCalculateOrderCount(orderList);
        s_vappDrawerOrderCount = vappDrawerSyncAppMgr(s_vappDrawerAllOrderData, s_vappDrawerOrderCount, isNeedResetOrder, &dirtyWhenSync);
        updateAppDataCache(s_vappDrawerAllOrderData, s_vappDrawerOrderCount + VAPP_DRAWER_MAX_GROUP_APP_DATA);
    }
    s_vappDrawerIsDataDirty = s_vappDrawerIsDataDirty || isNeedResetOrder || dirtyWhenSync;
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM0", SA_stop);
#endif
}

VfxBool vappDrawerGetIsDataDirty()
{
    return s_vappDrawerIsDataDirty;
}

void vappDrawerSaveData()
{
    U8 * writeBufferPointer = (U8*)s_vappDrawerAllOrderData;
    for (VfxS32 i = 0; i < NVRAM_EF_VAPP_DRAWER_ORDER_DATA_TOTAL; ++i)
    {
        S16 error;

        WriteRecord(
            NVRAM_EF_VAPP_DRAWER_ORDER_DATA_LID,
            1+i,
            writeBufferPointer + NVRAM_EF_VAPP_DRAWER_ORDER_DATA_SIZE * i,
            NVRAM_EF_VAPP_DRAWER_ORDER_DATA_SIZE,
            &error);

        MMI_ASSERT(error == NVRAM_WRITE_SUCCESS);
    }
    s_vappDrawerIsDataDirty = VFX_FALSE;
}

mmi_ret vappDrawerEventHandler(mmi_event_struct *event)
{
    switch (event->evt_id)
    {
        case EVT_ID_SRV_APPMGR_INSTALL_PACKAGE:
        case EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE:
        case EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE:
            vappDrawerSetNeedSycn();
            s_vappDrawerIsDataDirty = VFX_TRUE;
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}

VfxS32 vappDrawerCalculateOrderCount(mmi_app_package_name_struct *orderList)
{
    VfxS32 orderCount = VAPP_DRAWER_MAX_APP_DATA;
    for (VfxS32 i = 0; i < VAPP_DRAWER_MAX_APP_DATA - 1; ++i)
    {
        if (strncmp(orderList[i], "", MMI_APP_NAME_MAX_LEN) == 0)
        {
            if (strncmp(orderList[i + 1], "", MMI_APP_NAME_MAX_LEN) == 0)
            {
                orderCount = i;
                break;
            }
        }
    }
    return orderCount;
}

VfxBool isPreinstallApp(mmi_app_package_name_struct appName)
{
    if (strncmp(appName, "mre", 3) != 0)
    {
        return VFX_FALSE;
    }
    // TODO : check with pre-install list

    return VFX_FALSE;
}

#endif // __MMI_VUI_LAUNCHER__

#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_VUI_LAUNCHER_KEY__)

typedef U8 *vappDrawerCacheDataType;

#if defined(__MMI_MAINLCD_480X800__)
static const VfxS32 VAPP_DRAWER_APP_DATA_CACHE_COUNT = 80;
static const VfxS32 VAPP_DRAWER_APP_ICON_CACHE_POOL_SIZE = 100 * 1024;
#elif defined(__MMI_MAINLCD_240X320__)
static const VfxS32 VAPP_DRAWER_APP_DATA_CACHE_COUNT = 36;
static const VfxS32 VAPP_DRAWER_APP_ICON_CACHE_POOL_SIZE = 100 * 1024;
#elif defined(__MMI_MAINLCD_240X400__)
static const VfxS32 VAPP_DRAWER_APP_DATA_CACHE_COUNT = 48;
static const VfxS32 VAPP_DRAWER_APP_ICON_CACHE_POOL_SIZE = 100 * 1024;
#else // default HVGA 320X480
static const VfxS32 VAPP_DRAWER_APP_DATA_CACHE_COUNT = 64;
static const VfxS32 VAPP_DRAWER_APP_ICON_CACHE_POOL_SIZE = 100 * 1024;
#endif

static VfxU8 s_vappDrawerAppIconCachePool[VAPP_DRAWER_APP_ICON_CACHE_POOL_SIZE];
static KAL_ADM_ID s_vappDrawerAppIconCachePoolAdm;
static mmi_app_package_name_struct s_vappDrawerAppDataCacheAppNames[VAPP_DRAWER_APP_DATA_CACHE_COUNT];
static U8 *s_vappDrawerAppDataCacheDatas[VAPP_DRAWER_APP_DATA_CACHE_COUNT];

static VfxBool s_vappDrawerAdmCreate = VFX_FALSE;

static VfxBool vappDrawerGetAppInfo(mmi_app_package_name_struct & appName, VfxS32 cacheIndex)
{
    srv_app_info_struct info;
    mmi_ret result = srv_appmgr_get_app_package_info(appName, &info);
	U8 type = 0;
    VFX_ASSERT(result != MMI_RET_ERR);
    if (info.image.type == MMI_IMAGE_SRC_TYPE_PATH)
    {
        strncpy(s_vappDrawerAppDataCacheAppNames[cacheIndex], appName, MMI_APP_NAME_MAX_LEN - 1);
        
        FS_HANDLE fileHandle = FS_Open ((const WCHAR *)info.image.data.path, FS_READ_ONLY);
        
        UINT fileSize, readSize;
        FS_GetFileSize(fileHandle, &fileSize);
        VfxS32 iconWidth, iconHeight;
        gdi_image_get_dimension_file((S8*)info.image.data.path, &iconWidth, &iconHeight);
        
        s_vappDrawerAppDataCacheDatas[cacheIndex] = (U8 *)kal_adm_alloc(s_vappDrawerAppIconCachePoolAdm, fileSize + 8);
        type = gdi_image_get_type_from_file((S8*)info.image.data.path);
		if (s_vappDrawerAppDataCacheDatas[cacheIndex] == NULL || type == GDI_IMAGE_TYPE_DEVICE_BMP_FILE)
        {
        	FS_Close(fileHandle);
            return VFX_FALSE;
        }

        FS_Read(fileHandle, s_vappDrawerAppDataCacheDatas[cacheIndex] + 8, fileSize, &readSize);
		if(type == GDI_IMAGE_TYPE_AB2_FILE)
		{
			type = GDI_IMAGE_TYPE_AB2;  // map for mre pre shortcut abm2 files.
		}
		else
		{
			type = (U8)gdi_image_get_type_from_mem((PS8)(s_vappDrawerAppDataCacheDatas[cacheIndex] + 8));
		}

		s_vappDrawerAppDataCacheDatas[cacheIndex][0] = type;
        s_vappDrawerAppDataCacheDatas[cacheIndex][1] = 1;
        s_vappDrawerAppDataCacheDatas[cacheIndex][2] = fileSize & 0xff;
        s_vappDrawerAppDataCacheDatas[cacheIndex][3] = (fileSize >> 8) & 0xff;
        s_vappDrawerAppDataCacheDatas[cacheIndex][4] = (fileSize >> 16) & 0xff;
        s_vappDrawerAppDataCacheDatas[cacheIndex][5] = iconHeight & 0xff;
        s_vappDrawerAppDataCacheDatas[cacheIndex][6] = ((iconHeight & 0xf00) >> 8) + ((iconWidth & 0xf) << 4);
        s_vappDrawerAppDataCacheDatas[cacheIndex][7] = (iconWidth >> 4) & 0xff;
        
        FS_Close(fileHandle);
        
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

/* share for launcher and key launcher manimenu */
void vappDrawerCreateCacheAdm()
{
	if(s_vappDrawerAdmCreate == VFX_FALSE)
	{
		s_vappDrawerAdmCreate = VFX_TRUE;

		s_vappDrawerAppIconCachePoolAdm = kal_adm_create(s_vappDrawerAppIconCachePool,
													 VAPP_DRAWER_APP_ICON_CACHE_POOL_SIZE,
													 NULL,
													 KAL_FALSE);
	}
}

void updateAppDataCache(mmi_app_package_name_struct * allOrderData, VfxS32 orderCount)
{
    // free old cache
    for (VfxS32 i = 0; i < VAPP_DRAWER_APP_DATA_CACHE_COUNT; ++i)
    {
        if (s_vappDrawerAppDataCacheDatas[i])
        {
            kal_adm_free(s_vappDrawerAppIconCachePoolAdm, s_vappDrawerAppDataCacheDatas[i]);
            s_vappDrawerAppDataCacheDatas[i] = NULL;
        }
    }

    VfxS32 cacheIndex = 0;
    for (VfxS32 i = 0; i < orderCount; ++i)
    {
        if (cacheIndex >= VAPP_DRAWER_APP_DATA_CACHE_COUNT)
        {
            break;
        }
        mmi_app_package_name_struct & appName = allOrderData[i];
        if (strncmp(appName, "", MMI_APP_NAME_MAX_LEN) == 0)
        {
            continue;
        }

        VfxBool isCached = vappDrawerGetAppInfo(appName, cacheIndex);
        if (isCached)
        {
            ++cacheIndex;
        }
    }

    for (; cacheIndex < VAPP_DRAWER_APP_DATA_CACHE_COUNT; ++cacheIndex)
    {
        strncpy(s_vappDrawerAppDataCacheAppNames[cacheIndex], "\0", MMI_APP_NAME_MAX_LEN - 1);
    }
}

VfxBool vappDrawerGetAppDataCache(mmi_app_package_name_struct &appName, U8 **imageMem)
{
    VfxS32 i;
    for (i = 0; i < VAPP_DRAWER_APP_DATA_CACHE_COUNT; ++i)
    {
        if (strncmp(s_vappDrawerAppDataCacheAppNames[i], appName, MMI_APP_NAME_MAX_LEN) == 0)
        {
            break;
        }
    }
    if (i == VAPP_DRAWER_APP_DATA_CACHE_COUNT)
    {
        return VFX_FALSE;
    }

    *imageMem = s_vappDrawerAppDataCacheDatas[i];
	return VFX_TRUE;
}

#endif // #if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_VUI_LAUNCHER_KEY__)

