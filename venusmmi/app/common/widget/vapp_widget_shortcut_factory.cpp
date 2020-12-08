/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vapp_widget_shortcut_factory.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the factory to create the shortcut widget.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_FACTORY__) && defined(__COSMOS_MMI_PACKAGE__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMIDataType.h"
#include "vapp_widget_shortcut.h"
#include "vapp_widget_shortcut_factory.h"
#include "vapp_widget_kit.h"

//
// Include C headers without extern "C" internally.
//
extern "C"
{
#include "AppMgrSrvGprot.h"
}


/*****************************************************************************
 * Shortcut Factory
 *****************************************************************************/

VAPP_WIDGET_SYS_PUBLISH_FACTORY(
    VappWidgetShortcutFactory,
    VappWidgetShortcutFactoryPublisher);

VAPP_WIDGET_FACTORY_IMPLEMENT_CLASS(VappWidgetShortcutFactory);


VappWidgetShortcutFactory::VappWidgetShortcutFactory()
{
    // Do nothing.
}


VfxS32 VappWidgetShortcutFactory::getTotalNum() const
{
    U32 num;
    U32 preInstall_num;

    num = srv_appmgr_get_app_package_num(
            SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE);

    preInstall_num = srv_appmgr_get_app_package_num(
            SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE);
    
    return (VfxS32)(num + preInstall_num);
}


VfxS32 VappWidgetShortcutFactory::getAllId(VappWidgetId **id, VfxS32 size) const
{
    //
    // Get total number.
    //
    U32 num;
    U32 preInstall_num;

    num = srv_appmgr_get_app_package_num(
            SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE);

    preInstall_num = srv_appmgr_get_app_package_num(
            SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE);

    VfxS32 totalNum = (VfxS32)(num + preInstall_num);
    
    VFX_ASSERT(id && size >= totalNum);

    //
    // Get all application names.
    //
    U32* id_array;
    mmi_ret ret;

    VFX_SYS_ALLOC_MEM(id_array, totalNum * sizeof(U32));

    ret = srv_appmgr_get_app_package_id_list(
            SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE, 
            id_array, 
            num);
    
    VFX_ASSERT(ret != MMI_RET_ERR);

    ret = srv_appmgr_get_app_package_id_list(
            SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE, 
            &id_array[num], 
            preInstall_num);
    
    VFX_ASSERT(ret != MMI_RET_ERR);
    
    //
    // Assign value for each widget ID.
    //
    for (VfxS32 i = 0; i < totalNum; i++)
    {
        id[i]->assignWith(VAPP_WIDGET_SRC_SHORTCUT, (VfxS32)id_array[i]);
    }

    VFX_SYS_FREE_MEM(id_array);

    return totalNum;
}


VappWidget *VappWidgetShortcutFactory::createWidget(
    const VappWidgetId &id,
    VfxObject *parentObj)
{
    if (id.getSource() != VAPP_WIDGET_SRC_SHORTCUT ||
        id.getTypeKind() != VappWidgetId::TYPE_KIND_INTEGER)
    {
        return NULL;
    }

    VfxChar appName[MMI_APP_NAME_MAX_LEN];
    srv_appmgr_get_app_package_name_by_id(id.getIntType(), appName);

    srv_app_info_struct info;
    mmi_ret result = srv_appmgr_get_app_package_info(appName, &info);

    if (result != MMI_RET_OK)
        return NULL;

    VappWidgetShortcut *widget;

    VFX_OBJ_CREATE(widget, VappWidgetShortcut, parentObj);

    widget->setPackage(id.getIntType());

    return widget;
}

#endif /* defined(__MMI_VUI_WIDGET_FACTORY__) && defined(__COSMOS_MMI_PACKAGE__) */

