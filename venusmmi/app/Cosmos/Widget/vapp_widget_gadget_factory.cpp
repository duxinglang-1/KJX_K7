/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vapp_widget_gadget_factory.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the gadget factory.
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

#include "MMI_features.h"

#if defined(__MMI_GADGET_SUPPORT__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_widget.h"
#include "vapp_widget_def.h"
#include "vapp_widget_gadget_factory.h"
#include "vapp_widget_kit.h"

#include "WgtMgrSrvGprot.h"
extern "C"
{
#include "WgtMgrSrvIprot.h"
}
#include "vapp_widget_delegator.h"

#include "mmi_frm_mem_gprot.h"


/*****************************************************************************
 * Gadget Factory
 *****************************************************************************/

VAPP_WIDGET_SYS_PUBLISH_FACTORY(
    VappWidgetGadgetFactory,
    VappWidgetGadgetFactoryPublisher);

VAPP_WIDGET_FACTORY_IMPLEMENT_CLASS(VappWidgetGadgetFactory);


VappWidgetGadgetFactory::VappWidgetGadgetFactory()
{
    // Do nothing.
}


VfxS32 VappWidgetGadgetFactory::getTotalNum() const
{
    return srv_wgtmgr_get_enabled_wgt_num();
}


VfxS32 VappWidgetGadgetFactory::getAllId(VappWidgetId **id, VfxS32 size) const
{
    VfxS32 num = srv_wgtmgr_get_enabled_wgt_num();

    // There is no gadget existed.
    if (num == 0)
    {
        return 0;
    }

    VFX_ASSERT(id && size >= num);

    srv_wgtmgr_wgt_list_struct *list;

    list = (srv_wgtmgr_wgt_list_struct *)
            mmi_frm_temp_alloc(num * sizeof(srv_wgtmgr_wgt_list_struct));

    srv_wgtmgr_get_enabled_wgt_list(list);

    // Copy ID to the buffer.
    for (VfxS32 i = 0; i < num; i++)
    {
        if (list[i].type == SRV_WGTMGR_WGT_TYPE_DOWNLOADED)
        {
            id[i]->assignWith(VAPP_WIDGET_SRC_GADGET, list[i].id);
        }
    }

    mmi_frm_temp_free(list);

    return num;
}


VappWidget *VappWidgetGadgetFactory::createWidget(
    const VappWidgetId &id,
    VfxObject *parentObj)
{
    VappWidget *widget;

    if (isValid(id) == VFX_FALSE)
    {
        return NULL; // id is invalid.
    }

    if (id.getSource() != getSource())
    {
        return NULL;
    }

    // create gadget
    widget = (VappWidget *)VappWidgetDelegator::createWidget(id, parentObj);

    return widget;
}

VfxS32 VappWidgetGadgetFactory::getPreInstalledNum() const
{
    return srv_wgtmgr_get_preload_widget_num();
}

VfxS32 VappWidgetGadgetFactory::getPreInstalledWidget(
        VappWidgetPreInstalled **preInstalled,
        VfxS32 size) const
{

    srv_wgtmgt_preload_wgt_struct *preload_list = NULL;

    VfxS32 num = srv_wgtmgr_get_preload_widget_num();

    // There is no preload gadget existed.
    if (num == 0)
    {
        return 0;
    }

    VFX_ASSERT(preInstalled && size >= num);

    preload_list = (srv_wgtmgt_preload_wgt_struct*)mmi_frm_temp_alloc(num * sizeof(srv_wgtmgt_preload_wgt_struct));

    srv_wgtmgr_get_preload_widget_list(preload_list);

    // Copy ID to the buffer.
    for (VfxS32 i = 0; i < num; i++)
    {
        preInstalled[i]->m_id.assignWith(VAPP_WIDGET_SRC_GADGET, preload_list[i].id);
        preInstalled[i]->m_pageIdx = preload_list[i].page;
        preInstalled[i]->m_pos.x = preload_list[i].x_pos;
        preInstalled[i]->m_pos.y = preload_list[i].y_pos;
    }

    mmi_frm_temp_free(preload_list);

    return num;
}


#endif /* defined(__MMI_GADGET_SUPPORT__) */

