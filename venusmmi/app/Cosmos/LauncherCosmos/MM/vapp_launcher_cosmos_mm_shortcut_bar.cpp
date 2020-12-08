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
 *  vapp_launcher_cosmos_mm_shortcut_bar.cpp
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


#include "MMI_features.h"

#ifdef __MMI_VUI_LAUNCHER_COSMOS__


/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_font_desc.h"
#ifdef VAPP_LAUNCHER_COSMOS_MM_IN_PAGE
#include "vfx_main_scr.h" // for VfxMainScr
#endif
#include "vfx_signal.h"

#include "vapp_launcher.h"

#include "vapp_launcher_cosmos_mm.h" // for VAPP_LAUNCHER_COSMOS_MM_MAX_APP_DATA, VAPP_LAUNCHER_COSMOS_MM_MAX_GROUP_APP_DATA
#include "vapp_launcher_cosmos_mm_builder.h" // for vappLauncherCosmosMmCreateCell()
#include "vapp_launcher_cosmos_mm_default_order.h"
#include "vapp_launcher_cosmos_mm_gprot.h"
#include "vapp_launcher_cosmos_mm_shortcut_bar.h"
#include "mmi_rp_vapp_launcher_cosmos_mm_def.h"

#include "vapp_launcher_gprot.h"

#include "mmi_rp_vapp_setting_def.h" // for EVT_ID_VAPP_LANGUAGE_CHANGED

#ifdef __MMI_THEMES_APPLICATION__
#include "mmi_rp_vapp_theme_def.h" // for EVT_ID_VAPP_THEME_CHANGED
#endif

#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
#include "mmi_rp_vapp_fontmgr_def.h"  // for EVT_ID_VAPP_FONT_CHANGED
#endif
 
extern "C" {
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "fs_gprot.h"
#include "gdi_include.h"
#include "AppMgrSrvGprot.h"
#include "nvram_common_defs.h"
}

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif // __MTK_TARGET__

#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif 

#ifdef __AFX_RT_TEST__
#define VAPP_LAUNCHER_COSMOS_MM_SHOW_TESTBED
#include "vtst_rt_main.h" // for vtst_rt_main_entry
#endif


/*****************************************************************************
 * Define
 *****************************************************************************/

//#define VAPP_LAUNCHER_COSMOS_MM_DEBUG_ORDER_DATA


/*****************************************************************************
 * Static Constant
 *****************************************************************************/

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_SAVED_DATA_COUNT = NVRAM_EF_VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_COUNT_PER_RECORD * NVRAM_EF_VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_RECORD_TOTAL;

#if defined(__MMI_MAINLCD_480X800__)
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_WIDTH = 480;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_HEIGHT = 140;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_CELL_OFFSET = 120;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_VISIBLE_SHIFT_Y = 5;

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_WIDTH = 240;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_HEIGHT = 65;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_CELL_OFFSET = 60;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_VISIBLE_SHIFT_Y = -2;

#else // default HVGA 320X480
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_WIDTH = 320;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_HEIGHT = 80;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_CELL_OFFSET = 80;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_VISIBLE_SHIFT_Y = -5;

#endif

// Cache data variables
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_APP_DATA_CACHE_COUNT = VAPP_LAUNCHER_COSMOS_MM_SAVED_DATA_COUNT;


/*****************************************************************************
 * Local Variable
 *****************************************************************************/

// Order data variables
#ifdef VAPP_LAUNCHER_COSMOS_MM_DEBUG_ORDER_DATA
static VfxU32 s_vappLauncherCosmosMmAllOrderData[VAPP_LAUNCHER_COSMOS_MM_SAVED_DATA_COUNT];
#else
static VfxU32 *s_vappLauncherCosmosMmAllOrderData = NULL;
#endif
static VfxBool s_vappLauncherCosmosMmIsFirstLoad = VFX_TRUE;
static VfxS32 s_vappLauncherCosmosMmOrderCount = 0;
static VfxBool s_vappLauncherCosmosMmNeedSync = VFX_TRUE;
static VfxS32 s_vappLauncherCosmosMmSyncVersion = 0;
static VfxBool s_vappLauncherCosmosMmIsDataDirty = VFX_FALSE;

// Cache data variables
static VfxS16 *s_vappLauncherCosmosMmAppDataCacheStringWidth = NULL;


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

// Order data utilities
// allOrderData [OUT] : the order list to be compact
// pIsNeedResetOrder [OUT] : if is empty data in nvram
// return : data count after loading
static VfxS32 vappLauncherCosmosMmLoadData(VfxU32 *allOrderData, VfxBool *pIsNeedResetOrder);
static VfxS32 vappLauncherCosmosMmCalculateOrderCount(VfxU32 *orderList);
// allOrderData [IN, OUT] : the order data to be compared with app manager data
static VfxS32 vappLauncherCosmosMmSyncAppMgr(VfxU32 *allOrderData, VfxS32 initOrderCount, VfxBool isNeedResetOrder, VfxBool * pIsDataDirty);
static void vappLauncherCosmosMmSortAppListByDisplayName(mmi_app_package_name_struct * appList, VfxS32 appCount);
static VfxU32 vappLauncherCosmosMmGetAppTypeOrder(mmi_app_package_name_struct appName);
// remove the "delete" app in order list
// orderList [IN, OUT] : the order list to be compact
// maxDataCount [IN] : max data count in the order list
// return : data count after compact
static VfxS32 vappLauncherCosmosMmCompactData(VfxU32 *orderList, VfxS32 maxDataCount, VfxBool isNeedResetOrder);
static void vappLauncherCosmosMmCompactGroupData(VfxU32 *barOrderList, VfxS32 maxDataCount);
static mmi_ret vappLauncherCosmosMmEventHandler(mmi_event_struct *event);

// Data cache utilities
static void vappLauncherCosmosMmUpdateAppDataCache(VfxU32 *allOrderData, VfxS32 orderCount);
static void vappLauncherCosmosMmGetAppInfo(mmi_app_package_name_struct & appName, VfxS32 cacheIndex);
static VfxS32 vappLauncherCosmosMmFindAppDataIndex(mmi_app_package_name_struct & appName);


/*****************************************************************************
 * Pre-declaration
 *****************************************************************************/

#ifdef __MMI_ENGINEER_MODE__
extern "C" void mmi_em_pre_entry_engineermode_menu(void);
#endif


/***************************************************************************** 
 * Local Function
 *****************************************************************************/

VfxS32 vappLauncherCosmosMmLoadData(VfxU32 *allOrderData, VfxBool *pIsNeedResetOrder)
{
    VfxU32 *orderList = allOrderData + VAPP_LAUNCHER_COSMOS_MM_MAX_GROUP_APP_DATA;
    VfxU32 *barOrderList = allOrderData;

    U8 * readBufferPointer = (U8*)allOrderData;
    for (VfxS32 i = 0; i < NVRAM_EF_VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_RECORD_TOTAL; ++i)
    {
        S16 error;

        ReadRecord(
            NVRAM_EF_VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_LID,
            1+i,
            readBufferPointer + NVRAM_EF_VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_RECORD_SIZE * i,
            NVRAM_EF_VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_RECORD_SIZE,
            &error);

        MMI_ASSERT(error == NVRAM_READ_SUCCESS);
    }

    VfxS32 orderCount = 0;
    VfxBool isNeedResetOrder = VFX_FALSE;
    if (orderList[0] == 0 && orderList[1] == 0)
    {
        isNeedResetOrder = VFX_TRUE;
    }
    else
    {
        orderCount = vappLauncherCosmosMmCalculateOrderCount(orderList);
    }

    if (isNeedResetOrder)
    {
        U32 count = srv_appmgr_get_app_package_num(SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE);
        mmi_app_package_name_struct *array = NULL;
        VFX_SYS_ALLOC_MEM(array, sizeof(mmi_app_package_name_struct) * count);
        memset(array, 0, sizeof(mmi_app_package_name_struct) * count);
        mmi_ret result = srv_appmgr_get_app_package_list(SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE, array, count);
        VFX_ASSERT(result != MMI_RET_ERR);

        VfxS32 i;
        for (i = 0;
             i < VAPP_LAUNCHER_COSMOS_MM_BAR_CELL_COUNT && i < vappLauncherCosmosMmDefaultOrderCount;
             ++i)
        {
            VfxBool found = VFX_FALSE;
            for (VfxS32 j = 0; j < count; ++j)
            {
                if (strncmp(vappLauncherCosmosMmDefaultOrder[i], array[j], MMI_APP_NAME_MAX_LEN) == 0)
                {
                    found = VFX_TRUE;
                    break;
                }
            }
            if (found)
            {
                mmi_app_package_name_struct appPackageName;
                strncpy(appPackageName, vappLauncherCosmosMmDefaultOrder[i], MMI_APP_NAME_MAX_LEN - 1);
                barOrderList[i] = srv_appmgr_get_id_by_app_package_name(appPackageName);
            }
            else
            {
                barOrderList[i] = VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_DISABLED;
            }
        }

        // set remaining bar data as empty
        for (; i < VAPP_LAUNCHER_COSMOS_MM_MAX_GROUP_APP_DATA; ++i)
        {
            barOrderList[i] = VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_EMPTY;
        }
        
        orderCount = 0;
        VfxS32 countInPage = 0;
        for (VfxS32 i = VAPP_LAUNCHER_COSMOS_MM_BAR_CELL_COUNT; i < vappLauncherCosmosMmDefaultOrderCount; ++i)
        {
            if (countInPage == vappLauncherCosmosMmGetCellCountInPage())
            {
                orderList[orderCount] = VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_EMPTY;
                ++orderCount;
                countInPage = 0;
            }

            // append
            VfxBool found = VFX_FALSE;
            for (VfxS32 j = 0; j < count; ++j)
            {
                if (strncmp(vappLauncherCosmosMmDefaultOrder[i], array[j], MMI_APP_NAME_MAX_LEN) == 0)
                {
                    found = VFX_TRUE;
                    break;
                }
            }
            if (found)
            {
                mmi_app_package_name_struct appPackageName;
                strncpy(appPackageName, vappLauncherCosmosMmDefaultOrder[i], MMI_APP_NAME_MAX_LEN - 1);
                orderList[orderCount] = srv_appmgr_get_id_by_app_package_name(appPackageName);
            }
            else
            {
                orderList[orderCount] = VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_DISABLED;
            }
            
            ++orderCount;
            ++countInPage;
        }
        
        // set remaining data as empty
        for (VfxS32 i = orderCount; i < VAPP_LAUNCHER_COSMOS_MM_MAX_APP_DATA; ++i)
        {
            orderList[i] = VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_EMPTY;
        }
        
        VFX_SYS_FREE_MEM(array);
    }

    *pIsNeedResetOrder = isNeedResetOrder;

    return orderCount;
}

VfxS32 vappLauncherCosmosMmCalculateOrderCount(VfxU32 *orderList)
{
    VfxS32 orderCount = VAPP_LAUNCHER_COSMOS_MM_MAX_APP_DATA;
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MM_MAX_APP_DATA - 1; ++i)
    {
        if (orderList[i] == VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_EMPTY)
        {
            if (orderList[i + 1] == VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_EMPTY)
            {
                orderCount = i;
                break;
            }
        }
    }
    return orderCount;
}

VfxS32 vappLauncherCosmosMmSyncAppMgr(VfxU32 *allOrderData, VfxS32 initOrderCount, VfxBool isNeedResetOrder, VfxBool * pIsDataDirty)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM4", SA_start);
#endif

    U32 count = srv_appmgr_get_app_package_num(SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE);
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
        vappLauncherCosmosMmSortAppListByDisplayName(array, totalCount);
    }
    
    // check if every thing in the current order list are in the app list
    VfxS32 countInPage = 0;
    VfxBool isDataDirty = VFX_FALSE;
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MM_MAX_GROUP_APP_DATA + initOrderCount; ++i)
    {
        VfxBool found = VFX_FALSE;
        if (allOrderData[i] == VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_EMPTY)
        {
            countInPage = 0;
            continue;
        }

        for (VfxU32 j = 0; j < totalCount; ++j)
        {
            if (strncmp(array[j], "ADDED", MMI_APP_NAME_MAX_LEN) != 0 &&
                allOrderData[i] == srv_appmgr_get_id_by_app_package_name(array[j]))
            {
                strncpy(array[j], "ADDED", MMI_APP_NAME_MAX_LEN - 1);
                found = VFX_TRUE;
                break;
            }
        }

        if (!found)
        {
        #if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
            mmi_app_package_name_struct appPackageName;
            memset(appPackageName, 0, sizeof(mmi_app_package_name_struct));
            srv_appmgr_get_app_package_name_by_id(allOrderData[i], appPackageName);
            if (i == VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_CELL_COUNT - 1 ||
                strncmp(appPackageName, "native.mtk.launcher_cosmos_mm_barrel_setting", MMI_APP_NAME_MAX_LEN) == 0) // do not update the last entry on bottom bar
        #else // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
            if (i == VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_CELL_COUNT - 1) // do not update the last entry on bottom bar
        #endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
            {
                ++countInPage;
                continue;
            }
            if (allOrderData[i] != VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_DELETED)
            {
                allOrderData[i] = VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_DELETED;

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

    VfxU32 *orderList = allOrderData + VAPP_LAUNCHER_COSMOS_MM_MAX_GROUP_APP_DATA;
    VfxS32 newOrderCount = initOrderCount;
    for (VfxU32 i = 0; i < totalCount; ++i)
    {
        if (newOrderCount >= VAPP_LAUNCHER_COSMOS_MM_MAX_APP_DATA)
        {
            break;
        }
        
        if (strncmp(array[i], "ADDED", MMI_APP_NAME_MAX_LEN) == 0)
        {
            continue;
        }

        if (countInPage >= vappLauncherCosmosMmGetCellCountInPage())
        {
            orderList[newOrderCount] = VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_EMPTY;

            ++newOrderCount;
            countInPage = 0;
        }

        // append
        orderList[newOrderCount] = srv_appmgr_get_id_by_app_package_name(array[i]);

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
    newOrderCount = vappLauncherCosmosMmCompactData(orderList, VAPP_LAUNCHER_COSMOS_MM_MAX_APP_DATA, isNeedResetOrder);

    VfxU32 *barOrderList = allOrderData;
    vappLauncherCosmosMmCompactGroupData(barOrderList, VAPP_LAUNCHER_COSMOS_MM_MAX_GROUP_APP_DATA);
    *pIsDataDirty = isDataDirty;
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM4", SA_stop);
#endif
    return newOrderCount;
}

void vappLauncherCosmosMmSortAppListByDisplayName(mmi_app_package_name_struct * appList, VfxS32 appCount)
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
        VfxU32 iMinTypeOrder = vappLauncherCosmosMmGetAppTypeOrder(appList[iPos]);
        for (VfxS32 i = iPos + 1; i < appCount; ++i)
        {
            // first compare app type, then compare app display name
            VfxU32 typeOrder = vappLauncherCosmosMmGetAppTypeOrder(appList[i]);
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

VfxU32 vappLauncherCosmosMmGetAppTypeOrder(mmi_app_package_name_struct appName)
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

VfxS32 vappLauncherCosmosMmCompactData(VfxU32 *orderList, VfxS32 maxDataCount, VfxBool isNeedResetOrder)
{
    VfxS32 orderCount = 0;
    VfxS32 i1 = 0;
    VfxS32 i2 = 0;
    VfxS32 countInPage = 0;
    
    while (i1 < maxDataCount)
    {
        if (orderList[i1] == VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_DELETED)
        {
            i1 += 1;
            continue;
        }

        if (i1 != i2)
        {
            // special handling for deleting the icon which is the only one icon in a page
            if (i2 >= 1 &&
                orderList[i2 - 1] == VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_EMPTY &&
                orderList[i2] == VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_DELETED &&
                orderList[i1] == VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_EMPTY)
            {
                i1 += 1;
                continue;
            }
            
            // Do not reserve space when first time bootup
            if (isNeedResetOrder &&
                orderList[i1] == VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_EMPTY &&
                orderList[i1 + 1] != VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_EMPTY)
            {
                i1 += 1;
                continue;
            }
            if (isNeedResetOrder && countInPage == vappLauncherCosmosMmGetCellCountInPage())
            {
                orderList[i2] = VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_EMPTY;
                i2 += 1;
                countInPage = 0;
                continue;
            }
            
            orderList[i2] = orderList[i1];
            orderList[i1] = VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_EMPTY;
        }

        // successive empty string means end of data
        if (orderList[i2] == VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_EMPTY)
        {
            if (i2 >= 1 && orderList[i2 - 1] == VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_EMPTY)
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
        while (i2 < maxDataCount)
        {
            orderList[i2] = VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_EMPTY;
            i2 += 1;
        }
    }

    return orderCount;
}

void vappLauncherCosmosMmCompactGroupData(VfxU32 *barOrderList, VfxS32 maxDataCount)
{
    // For shortcut bar
    VfxS32 i1 = 0;
    VfxS32 i2 = 0;
    while (i1 < maxDataCount - 1)
    {
        if (barOrderList[i1] == VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_EMPTY ||
            barOrderList[i1] == VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_DELETED)
        {
            i1 += 1;
            continue;
        }

        if (i1 != i2)
        {
            barOrderList[i2] = barOrderList[i1];
        }

        i1 += 1;
        i2 += 1;
    }
    if (i1 != i2)
    {
        while (i2 < maxDataCount - 1)
        {
            barOrderList[i2] = VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_EMPTY;
            i2 += 1;
        }
    }
}

mmi_ret vappLauncherCosmosMmEventHandler(mmi_event_struct *event)
{
    switch (event->evt_id)
    {
        case EVT_ID_SRV_APPMGR_INSTALL_PACKAGE:
        case EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE:
        case EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE:
        case EVT_ID_VAPP_LANGUAGE_CHANGED:
#ifdef __MMI_THEMES_APPLICATION__
        case EVT_ID_VAPP_THEME_CHANGED:
#endif
#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
        case EVT_ID_VAPP_FONT_CHANGED:
#endif
            vappLauncherCosmosMmSetNeedSycn();
            s_vappLauncherCosmosMmIsDataDirty = VFX_TRUE;
            vappLauncherCosmosMmClearStringWidth();
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}

void vappLauncherCosmosMmUpdateAppDataCache(VfxU32 *allOrderData, VfxS32 orderCount)
{
    vappLauncherCosmosMmClearStringWidth();
    
    for (VfxS32 i = 0; i < orderCount; ++i)
    {
        if (allOrderData[i] == VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_EMPTY)
        {
            continue;
        }

        if (allOrderData[i] == VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_DELETED)
        {
            continue;
        }

        mmi_app_package_name_struct appName;
        srv_appmgr_get_app_package_name_by_id(allOrderData[i], appName);
        if (strncmp(appName, "native.mtk.launcher", MMI_APP_NAME_MAX_LEN) == 0)
        {
            continue;
        }
        vappLauncherCosmosMmGetAppInfo(appName, i);
    }
}

void vappLauncherCosmosMmGetAppInfo(mmi_app_package_name_struct & appName, VfxS32 cacheIndex)
{
    srv_app_info_struct info;
    mmi_ret result = srv_appmgr_get_app_package_info(appName, &info);
    VFX_ASSERT(result != MMI_RET_ERR);
    
    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_FONT_SIZE);
    s_vappLauncherCosmosMmAppDataCacheStringWidth[cacheIndex] = fontDesc.measureStr(info.string).width;
}

VfxS32 vappLauncherCosmosMmFindAppDataIndex(mmi_app_package_name_struct & appName)
{
    VfxS32 i;
    for (i = 0; i < VAPP_LAUNCHER_COSMOS_MM_APP_DATA_CACHE_COUNT; ++i)
    {
        if (s_vappLauncherCosmosMmAllOrderData[i] != VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_EMPTY)
        {
            mmi_app_package_name_struct appPackageName;
            srv_appmgr_get_app_package_name_by_id(s_vappLauncherCosmosMmAllOrderData[i], appPackageName);
            if (strncmp(appPackageName, appName, MMI_APP_NAME_MAX_LEN) == 0)
            {
                return i;
            }
        }
    }

    return -1;
}


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

void vappLauncherCosmosMmCheckLoadOrderData()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM0", SA_start);
#endif
    VfxBool isNeedResetOrder = VFX_FALSE;

    if (s_vappLauncherCosmosMmIsFirstLoad)
    {
        s_vappLauncherCosmosMmIsFirstLoad = VFX_FALSE;
        s_vappLauncherCosmosMmOrderCount = vappLauncherCosmosMmLoadData(s_vappLauncherCosmosMmAllOrderData, &isNeedResetOrder);
    }

    VfxBool dirtyWhenSync = VFX_FALSE;
    if (s_vappLauncherCosmosMmNeedSync)
    {
        s_vappLauncherCosmosMmNeedSync = VFX_FALSE;
        VfxU32 *orderList = s_vappLauncherCosmosMmAllOrderData + VAPP_LAUNCHER_COSMOS_MM_MAX_GROUP_APP_DATA;
        s_vappLauncherCosmosMmOrderCount = vappLauncherCosmosMmCalculateOrderCount(orderList);
        s_vappLauncherCosmosMmOrderCount = vappLauncherCosmosMmSyncAppMgr(s_vappLauncherCosmosMmAllOrderData, s_vappLauncherCosmosMmOrderCount, isNeedResetOrder, &dirtyWhenSync);
        vappLauncherCosmosMmUpdateAppDataCache(s_vappLauncherCosmosMmAllOrderData, s_vappLauncherCosmosMmOrderCount + VAPP_LAUNCHER_COSMOS_MM_MAX_GROUP_APP_DATA);
    }
    s_vappLauncherCosmosMmIsDataDirty = s_vappLauncherCosmosMmIsDataDirty || isNeedResetOrder || dirtyWhenSync;
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM0", SA_stop);
#endif
}

void vappLauncherCosmosMmSaveData()
{
    U8 * writeBufferPointer = (U8*)s_vappLauncherCosmosMmAllOrderData;
    for (VfxS32 i = 0; i < NVRAM_EF_VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_RECORD_TOTAL; ++i)
    {
        S16 error;

        WriteRecord(
            NVRAM_EF_VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_LID,
            1+i,
            writeBufferPointer + NVRAM_EF_VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_RECORD_SIZE * i,
            NVRAM_EF_VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_RECORD_SIZE,
            &error);

        MMI_ASSERT(error == NVRAM_WRITE_SUCCESS);
    }
    s_vappLauncherCosmosMmIsDataDirty = VFX_FALSE;
}

VfxU32 *vappLauncherCosmosMmGetAllOrderData()
{
    //VFX_ASSERT(VAPP_LAUNCHER_COSMOS_MM_SAVED_DATA_COUNT >= (VAPP_LAUNCHER_COSMOS_MM_MAX_APP_DATA + VAPP_LAUNCHER_COSMOS_MM_MAX_GROUP_APP_DATA) );

    return s_vappLauncherCosmosMmAllOrderData;
}

VfxBool vappLauncherCosmosMmGetIsDataDirty()
{
    return s_vappLauncherCosmosMmIsDataDirty;
}

VfxS32 vappLauncherCosmosMmGetSycnVersion()
{
    return s_vappLauncherCosmosMmSyncVersion;
}

void vappLauncherCosmosMmSetNeedSycn()
{
    s_vappLauncherCosmosMmNeedSync = VFX_TRUE;
    s_vappLauncherCosmosMmSyncVersion += 1;
}

VfxS32 vappLauncherCosmosMmGetStringWidth(mmi_app_package_name_struct & appName)
{
    VfxS32 i = vappLauncherCosmosMmFindAppDataIndex(appName);
    if (i == -1)
    {
        return -1;
    }

    return s_vappLauncherCosmosMmAppDataCacheStringWidth[i];
}

void vappLauncherCosmosMmSetStringWidth(mmi_app_package_name_struct & appName, VfxS16 stringWidth)
{
    VfxS32 i = vappLauncherCosmosMmFindAppDataIndex(appName);
    if (i == -1)
    {
        return;
    }

    s_vappLauncherCosmosMmAppDataCacheStringWidth[i] = stringWidth;
}

void vappLauncherCosmosMmClearStringWidth()
{
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MM_APP_DATA_CACHE_COUNT; ++i)
    {
        s_vappLauncherCosmosMmAppDataCacheStringWidth[i] = -1;
    }
}


/*****************************************************************************
 * Class VappLauncherCosmosMmShortcutBar
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherCosmosMmShortcutBar", VappLauncherCosmosMmShortcutBar, VfxControl);

VfxBool VappLauncherCosmosMmShortcutBar::s_isEnterMainmenu = VFX_FALSE;

VappLauncherCosmosMmShortcutBar::VappLauncherCosmosMmShortcutBar():
    m_dataSyncVersion(-1),
    m_startClick(VFX_FALSE),
    m_updateCacheTimer(NULL),
    m_content(NULL)
{
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_CELL_COUNT; ++i)
    {
        m_cell[i] = NULL;
        strncpy(m_targetAppName[i], "", MMI_APP_NAME_MAX_LEN - 1);
    }
}

void VappLauncherCosmosMmShortcutBar::reloadShortcutBar()
{
    updateAppData();

    updateCells();

    VFX_ASSERT(m_updateCacheTimer);

    m_updateCacheTimer->setStartDelay(1);
    m_updateCacheTimer->start();
}

void VappLauncherCosmosMmShortcutBar::setIsEnterMainmenu(VfxBool isEnterMainmenu)
{
    s_isEnterMainmenu = isEnterMainmenu;
}

void VappLauncherCosmosMmShortcutBar::onInit()
{
    VfxControl::onInit();

    setSize(VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_WIDTH, VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_HEIGHT);

    m_appClicked.connect(this, &VappLauncherCosmosMmShortcutBar::onAppClicked);

    // update cache timer
    VFX_OBJ_CREATE(m_updateCacheTimer, VfxTimer, this);
    m_updateCacheTimer->m_signalTick.connect(this, &VappLauncherCosmosMmShortcutBar::onUpdateCacheTimerTick);
    
#ifndef VAPP_LAUNCHER_COSMOS_MM_DEBUG_ORDER_DATA
    VFX_ALLOC_MEM(s_vappLauncherCosmosMmAllOrderData,
                  sizeof(VfxU32) * VAPP_LAUNCHER_COSMOS_MM_SAVED_DATA_COUNT,
                  this);
#endif
    VFX_ALLOC_MEM(s_vappLauncherCosmosMmAppDataCacheStringWidth,
                  sizeof(VfxS16) * VAPP_LAUNCHER_COSMOS_MM_APP_DATA_CACHE_COUNT,
                  this);
    s_vappLauncherCosmosMmIsFirstLoad = VFX_TRUE;
    s_vappLauncherCosmosMmOrderCount = 0;
    s_vappLauncherCosmosMmNeedSync = VFX_TRUE;
    s_vappLauncherCosmosMmSyncVersion = 0;
    s_vappLauncherCosmosMmIsDataDirty = VFX_FALSE;
    
    reloadShortcutBar();
    
    mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_INSTALL_PACKAGE, vappLauncherCosmosMmEventHandler, NULL);
    mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE, vappLauncherCosmosMmEventHandler, NULL);
    mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE, vappLauncherCosmosMmEventHandler, NULL);
    mmi_frm_cb_reg_event(EVT_ID_VAPP_LANGUAGE_CHANGED, vappLauncherCosmosMmEventHandler, NULL);
#ifdef __MMI_THEMES_APPLICATION__
    mmi_frm_cb_reg_event(EVT_ID_VAPP_THEME_CHANGED, vappLauncherCosmosMmEventHandler, NULL);
#endif
#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
    mmi_frm_cb_reg_event(EVT_ID_VAPP_FONT_CHANGED, vappLauncherCosmosMmEventHandler, NULL);
#endif

    mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_INSTALL_PACKAGE,  &VappLauncherCosmosMmShortcutBar::eventHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE,  &VappLauncherCosmosMmShortcutBar::eventHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE,  &VappLauncherCosmosMmShortcutBar::eventHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_VAPP_LANGUAGE_CHANGED,  &VappLauncherCosmosMmShortcutBar::eventHandler, this);
#ifdef __MMI_THEMES_APPLICATION__
    mmi_frm_cb_reg_event(EVT_ID_VAPP_THEME_CHANGED,  &VappLauncherCosmosMmShortcutBar::eventHandler, this);
#endif
#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
	mmi_frm_cb_reg_event(EVT_ID_VAPP_FONT_CHANGED,  &VappLauncherCosmosMmShortcutBar::eventHandler, this);
#endif

    VFX_OBJ_CREATE(m_content, VappLauncherCosmosMmContent, this);

    VappLauncher *launcher = findLauncher();
    VFX_ASSERT(launcher);
    // Make sure to set main menu page is not entered if process home key
    if (launcher->isProcessHomeKey())
    {
        setIsEnterMainmenu(VFX_FALSE);
    }
    // Check if need to push main menu page when restoring launcher
    if (launcher->isRestoreStatus() && !launcher->isProcessHomeKey() && s_isEnterMainmenu)
    {
        pushMainmenuPage();
    }
}

void VappLauncherCosmosMmShortcutBar::onDeinit()
{
#ifndef VAPP_LAUNCHER_COSMOS_MM_DEBUG_ORDER_DATA
    VFX_FREE_MEM(s_vappLauncherCosmosMmAllOrderData);
#endif
    VFX_FREE_MEM(s_vappLauncherCosmosMmAppDataCacheStringWidth);
    
    mmi_frm_cb_dereg_event(EVT_ID_SRV_APPMGR_INSTALL_PACKAGE, vappLauncherCosmosMmEventHandler, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE, vappLauncherCosmosMmEventHandler, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE, vappLauncherCosmosMmEventHandler, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_VAPP_LANGUAGE_CHANGED, vappLauncherCosmosMmEventHandler, NULL);
#ifdef __MMI_THEMES_APPLICATION__
    mmi_frm_cb_dereg_event(EVT_ID_VAPP_THEME_CHANGED, vappLauncherCosmosMmEventHandler, NULL);
#endif
#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
    mmi_frm_cb_dereg_event(EVT_ID_VAPP_FONT_CHANGED, vappLauncherCosmosMmEventHandler, NULL);
#endif

    mmi_frm_cb_dereg_event(EVT_ID_SRV_APPMGR_INSTALL_PACKAGE, &VappLauncherCosmosMmShortcutBar::eventHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE, &VappLauncherCosmosMmShortcutBar::eventHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE, &VappLauncherCosmosMmShortcutBar::eventHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_VAPP_LANGUAGE_CHANGED, &VappLauncherCosmosMmShortcutBar::eventHandler, this);
#ifdef __MMI_THEMES_APPLICATION__
    mmi_frm_cb_dereg_event(EVT_ID_VAPP_THEME_CHANGED, &VappLauncherCosmosMmShortcutBar::eventHandler, this);
#endif
#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
	mmi_frm_cb_dereg_event(EVT_ID_VAPP_FONT_CHANGED, &VappLauncherCosmosMmShortcutBar::eventHandler, this);
#endif
    
    VfxControl::onDeinit();
}

VfxBool VappLauncherCosmosMmShortcutBar::onPenInput(VfxPenEvent &event)
{
    VfxPoint downPos = event.getRelDownPos(this);
    VfxS32 index = downPos.x / VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_CELL_OFFSET;
    if (index < 0)
    {
        index = 0;
    }
    if (index > 3)
    {
        index = 3;
    }

    if (event.type == VFX_PEN_EVENT_TYPE_UP || event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        VfxPoint pos = event.getRelPos(this);
        if ( (vfxAbs(pos.x - downPos.x) > VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_CELL_OFFSET) || 
            (vfxAbs(pos.y - downPos.y) > VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_HEIGHT) )
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
        if (m_cell[index] != NULL)
        {
            VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        #ifdef VAPP_LAUNCHER_COSMOS_MM_IN_PAGE
            m_cell[index]->setOpacity(1.0f);
            renderer->suspendUntilCommit();
        #endif
        }
        
        m_appClicked.postEmit(index);
        m_startClick = VFX_FALSE;
        return VFX_TRUE;
    }

    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_CELL_COUNT; ++i)
    {
        if (m_cell[i] != NULL)
        {
            if (m_startClick && index == i)
            {
                m_cell[i]->setOpacity(0.5f);
            }
            else
            {
                m_cell[i]->setOpacity(1.0f);
            }
        }
    }

    return VFX_TRUE;
}

void VappLauncherCosmosMmShortcutBar::updateAppData()
{
    vappLauncherCosmosMmCheckLoadOrderData();
    VfxU32 *barApp = vappLauncherCosmosMmGetAllOrderData();
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_CELL_COUNT; ++i)
    {
        if (i == VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_CELL_COUNT - 1)
        {
            strncpy(m_targetAppName[i], "native.mtk.launcher_cosmos_mm", MMI_APP_NAME_MAX_LEN);
        }
        else
        {
            mmi_app_package_name_struct appName;
            memset(appName, 0, sizeof(mmi_app_package_name_struct));
            srv_appmgr_get_app_package_name_by_id(barApp[i], appName);
            strncpy(m_targetAppName[i], appName, MMI_APP_NAME_MAX_LEN - 1);
        }
    }
}

void VappLauncherCosmosMmShortcutBar::updateCells()
{
    if (m_dataSyncVersion != vappLauncherCosmosMmGetSycnVersion())
    {
        for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_CELL_COUNT; ++i)
        {
            VFX_OBJ_CLOSE(m_cell[i]);
        }
        m_dataSyncVersion = vappLauncherCosmosMmGetSycnVersion();
    }

    mmi_app_package_name_struct *preInstalledAppArray = NULL;
    U32 preInstalledAppCount = srv_appmgr_get_app_package_num(SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE);
    if (preInstalledAppCount)
    {
        VFX_SYS_ALLOC_MEM(preInstalledAppArray, sizeof(mmi_app_package_name_struct) * preInstalledAppCount );
        mmi_ret result;
        result = srv_appmgr_get_app_package_list(SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE, preInstalledAppArray, preInstalledAppCount);
        VFX_ASSERT(result != MMI_RET_ERR);
    }
    
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_CELL_COUNT; ++i)
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

#ifdef VAPP_LAUNCHER_COSMOS_MM_SHOW_TESTBED
        if ((i == 1 || i == 2) && i < VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_CELL_COUNT - 1)
        {
            createTestbedCell(i);
            continue;
        }
#endif // VAPP_LAUNCHER_COSMOS_MM_SHOW_TESTBED

        if ( (strncmp(m_targetAppName[i], "", MMI_APP_NAME_MAX_LEN) == 0) ||
            (strncmp(m_targetAppName[i], "DELETED", MMI_APP_NAME_MAX_LEN) == 0) )
        {
            VFX_OBJ_CLOSE(m_cell[i]);
            continue;
        }

        VfxBool isPreInstalled = VFX_FALSE;
        if (preInstalledAppArray)
        {
            isPreInstalled = vappLauncherCosmosMmIsPreInstalledApp(m_targetAppName[i], preInstalledAppArray, preInstalledAppCount);
        }
        m_cell[i] = vappLauncherCosmosMmCreateCell(m_targetAppName[i], this, isPreInstalled);
        m_cell[i]->setOnShortcut(VFX_TRUE);
        m_cell[i]->onCellDisplay();
        m_cell[i]->setPos(i * VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_CELL_OFFSET, VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_VISIBLE_SHIFT_Y);
    }
    
    if (preInstalledAppArray)
    {
        VFX_SYS_FREE_MEM(preInstalledAppArray);
    }
    
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_CELL_COUNT; ++i)
    {
        if (m_cell[i] != NULL)
        {
            m_cell[i]->setOpacity(1.0f);
        }
    }
}

void VappLauncherCosmosMmShortcutBar::createTestbedCell(VfxS32 index)
{
#ifdef VAPP_LAUNCHER_COSMOS_MM_SHOW_TESTBED
    if (index == 1)
    {
        m_cell[index] = vappLauncherCosmosMmCreateCellRaw(VfxImageSrc(IMG_ID_VAPP_LAUNCHER_COSMOS_MM_ICON_HOME),
                VFX_WSTR("RT"),this);
    }
    else if (index == 2)
    {
        m_cell[index] = vappLauncherCosmosMmCreateCellRaw(VfxImageSrc(IMG_ID_VAPP_LAUNCHER_COSMOS_MM_ICON_HOME),
                VFX_WSTR("Engineer"),this);
    }
    else
    {
        VFX_ASSERT(VFX_FALSE);
    }

    m_cell[index]->setOnShortcut(VFX_TRUE);
    m_cell[index]->setPos(index * VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_CELL_OFFSET, VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_VISIBLE_SHIFT_Y);
    m_cell[index]->onCellDisplay();
#endif // VAPP_LAUNCHER_COSMOS_MM_SHOW_TESTBED
}

void VappLauncherCosmosMmShortcutBar::onUpdateCacheTimerTick(VfxTimer *source)
{
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_CELL_COUNT; ++i)
    {
        if (m_cell[i] != NULL)
        {
            m_cell[i]->setCacheMode(VFX_CACHE_MODE_FREEZE);
        }
    }
}

void VappLauncherCosmosMmShortcutBar::onAppClicked(VfxS32 index)
{
#ifdef VAPP_LAUNCHER_COSMOS_MM_SHOW_TESTBED
    if (index == 1)
    {
        vtst_rt_main_entry();
        return;
    }
    if (index == 2 && index < VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_CELL_COUNT - 1)
    {
    #ifdef __MMI_ENGINEER_MODE__
        mmi_em_pre_entry_engineermode_menu();
    #endif
        return;
    }
#endif // VAPP_LAUNCHER_COSMOS_MM_SHOW_TESTBED

    if (strncmp(m_targetAppName[index], "", MMI_APP_NAME_MAX_LEN) == 0)
    {
        return;
    }

#ifdef VAPP_LAUNCHER_COSMOS_MM_IN_PAGE
    if (strncmp(m_targetAppName[index], "native.mtk.launcher_cosmos_mm", MMI_APP_NAME_MAX_LEN) == 0)
    {
        pushMainmenuPage();
        
        return;
    }
#endif // VAPP_LAUNCHER_COSMOS_MM_IN_PAGE
    
    srv_appmgr_launch(m_targetAppName[index]);
}

void VappLauncherCosmosMmShortcutBar::onLeaveMainmenuTransition(VfxBool in, VfxS32 direction)
{
    if (in)
    {
        VfxMainScr *mainScr;
        mainScr = VfxMainScr::findMainScr(this);
        VFX_ASSERT(mainScr);
        VfxPage * topPage = mainScr->getPage(mainScr->getTopPageId() );
        topPage->setTransition(NULL);
	}
}

VappLauncher *VappLauncherCosmosMmShortcutBar::findLauncher()
{
    for (VfxFrame *f = this; f != NULL; f = f->getParentFrame())
    {
        if(f->isKindOf(VFX_OBJ_CLASS_INFO(VappLauncher)))
        {
            return VFX_OBJ_DYNAMIC_CAST(f, VappLauncher);
        }
    }
    
    return NULL;
}

void VappLauncherCosmosMmShortcutBar::pushMainmenuPage()
{
    if (!m_mainmenu.isValid())
    {
        VappLauncherCosmosMmPage *mainmenu;
        VFX_OBJ_CREATE_EX(mainmenu, VappLauncherCosmosMmPage, this, (m_content));
        m_mainmenu = mainmenu;
    
        VfxMMSimplePageSlideTransition * mainmenuTrans;
        VFX_OBJ_CREATE(mainmenuTrans, VfxMMSimplePageSlideTransition, this);
        m_mainmenu->setTransition(mainmenuTrans);
    }
    
    // Push page into the screen.
    VfxMainScr *mainScr;
    mainScr = VfxMainScr::findMainScr(this);
    VFX_ASSERT(mainScr);
    VfxPage * topPage = mainScr->getPage(mainScr->getTopPageId());
    
    VfxNullPageSlideTransition *transition;
    VFX_OBJ_CREATE(transition, VfxNullPageSlideTransition, this);
    transition->m_signalStopped.connect(this, &VappLauncherCosmosMmShortcutBar::onLeaveMainmenuTransition);
    topPage->setTransition(transition);
    
    mainScr->pushPage(0, m_mainmenu.get());

    vfxPostInvoke0(this, &VappLauncherCosmosMmShortcutBar::emitMainmenuLaunchedSignel);
}

void VappLauncherCosmosMmShortcutBar::emitMainmenuLaunchedSignel()
{
    m_mainmenuLaunched.emit();
}

mmi_ret VappLauncherCosmosMmShortcutBar::eventHandler(mmi_event_struct *event)
{
    VappLauncherCosmosMmShortcutBar *shortcutBar = (VappLauncherCosmosMmShortcutBar *)event->user_data;

    switch (event->evt_id)
    {
        case EVT_ID_SRV_APPMGR_INSTALL_PACKAGE:
        case EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE:
        case EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE:
        case EVT_ID_VAPP_LANGUAGE_CHANGED:
#ifdef __MMI_THEMES_APPLICATION__
        case EVT_ID_VAPP_THEME_CHANGED:
#endif
#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
		case EVT_ID_VAPP_FONT_CHANGED:
#endif
            if (vapp_launcher_is_active() )
            {
                shortcutBar->reloadShortcutBar();
            }
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * Class VfxNullPageSlideTransition
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VfxNullPageSlideTransition", VfxNullPageSlideTransition, VfxPageTransition);

VfxNullPageSlideTransition::VfxNullPageSlideTransition()
{
}

void VfxNullPageSlideTransition::customPrepare(VfxBool in, VfxS32 direction, const VfxScreenRotateParam *param)
{
}

void VfxNullPageSlideTransition::customStart(VfxBool in, VfxS32 direction, VfxMsec duration)
{
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    getTarget()->setOpacity(1.0f);
    getTarget()->setPosZ(2.0f);
    VfxAutoAnimate::commit();
}

void VfxNullPageSlideTransition::customStop(VfxBool in, VfxS32 direction, VfxMsec duration)
{
}

#ifdef VAPP_LAUNCHER_COSMOS_MM_USE_PAGE_CUSTOM_OUT
VfxBool VfxNullPageSlideTransition::customOuted()
{
#if !defined(VAPP_LAUNCHER_COSMOS_MM_TRANSLUCENT_BACKGROUND)
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    getTarget()->setOpacity(0.0f);
    VfxAutoAnimate::commit();
#endif

    return VFX_TRUE;
}
#endif


/*****************************************************************************
 * Class VfxMMSimplePageSlideTransition
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VfxMMSimplePageSlideTransition", VfxMMSimplePageSlideTransition, VfxPageTransition);

VfxMMSimplePageSlideTransition::VfxMMSimplePageSlideTransition()
{
}

void VfxMMSimplePageSlideTransition::customPrepare(VfxBool in, VfxS32 direction, const VfxScreenRotateParam *param)
{
}

void VfxMMSimplePageSlideTransition::customStart(VfxBool in, VfxS32 direction, VfxMsec duration)
{
    VfxRect pageRect = getTarget()->getRect();
    getTarget()->bringToFront();

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    getTarget()->setOpacity(1.0f);
    VfxAutoAnimate::commit();
    
    VfxS32 height = pageRect.size.height;

    VfxPoint srcPos, destPos;
    srcPos = destPos = getTarget()->getPos();

    if (in)
    {
        srcPos.y += height;
        VappLauncherCosmosMmShortcutBar::setIsEnterMainmenu(VFX_TRUE);
    }
    else
    {
        destPos.y += height;
        VappLauncherCosmosMmShortcutBar::setIsEnterMainmenu(VFX_FALSE);
    }
    
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    {
        getTarget()->setPos(srcPos);
    }
    VfxAutoAnimate::commit();

    VfxAutoAnimate::begin();
    VfxAutoAnimate::initAnimateBegin();
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    {
        VfxAutoAnimate::setDuration(duration);
        getTarget()->setPos(destPos);
    }
    VfxAutoAnimate::initAnimateEnd();
    VfxAutoAnimate::commit();

}

void VfxMMSimplePageSlideTransition::customStop(VfxBool in, VfxS32 direction, VfxMsec duration)
{
}

#ifdef VAPP_LAUNCHER_COSMOS_MM_USE_PAGE_CUSTOM_OUT
VfxBool VfxMMSimplePageSlideTransition::customOuted()
{
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    
    getTarget()->setOpacity(0.0f);

    // Make sure to set correct position
    VfxPoint pos = getTarget()->getPos();
    pos.y = getTarget()->getRect().getHeight();
    getTarget()->setPos(pos);
    
    VfxAutoAnimate::commit();
    
    return VFX_FALSE;
}
#endif


#endif // __MMI_VUI_LAUNCHER_COSMOS__

