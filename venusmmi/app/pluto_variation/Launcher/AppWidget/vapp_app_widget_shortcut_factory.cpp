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
 *  vapp_app_widget_shortcut_factory.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMIDataType.h"
#include "vapp_app_widget_shortcut.h"
#include "vapp_app_widget_shortcut_factory.h"

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

VAPP_APP_WIDGET_FACTORY_IMPLEMENT_CLASS(VappAppWidgetShortcutFactory);


VappAppWidgetShortcutFactory::VappAppWidgetShortcutFactory()
{
    // Do nothing.
}


VfxS32 VappAppWidgetShortcutFactory::getTotalNum() const
{
    U32 num;

    num = srv_appmgr_get_app_package_num(
            SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE);

    return (VfxS32)num;
}


VfxS32 VappAppWidgetShortcutFactory::getAllId(VappAppWidgetId **id, VfxS32 size) const
{
    //
    // Get total number.
    //
    VfxS32 totalNum = getTotalNum();
    VFX_ASSERT(id && size >= totalNum);

    //
    // Get all application names.
    //
    mmi_app_package_name_struct *package;
    mmi_ret ret;

    VFX_SYS_ALLOC_MEM(package, totalNum * sizeof(mmi_app_package_name_struct));

    ret = srv_appmgr_get_app_package_list(
            SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE,
            package,
            totalNum);
    VFX_ASSERT(ret != MMI_RET_ERR);

    //
    // Assign value for each widget ID.
    //
    for (VfxS32 i = 0; i < totalNum; i++)
    {
        id[i]->assignWith(VAPP_APP_WIDGET_SRC_SHORTCUT, package[i]);
    }

    VFX_SYS_FREE_MEM(package);

    return totalNum;
}


VappAppWidget *VappAppWidgetShortcutFactory::createWidget(
    const VappAppWidgetId &id,
    VfxObject *parentObj)
{
    if (id.getSource() != VAPP_APP_WIDGET_SRC_SHORTCUT ||
        id.getTypeKind() != VappAppWidgetId::TYPE_KIND_STRING)
    {
        return NULL;
    }

    VappAppWidgetShortcut *widget;

    VFX_OBJ_CREATE(widget, VappAppWidgetShortcut, parentObj);

    widget->setPackage(id.getStringType());

    return widget;
}

#endif /* defined(__MMI_VUI_LAUNCHER__) */
