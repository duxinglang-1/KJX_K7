/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_callset_ctm.cpp
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h" 

#include "MMIDatatype.h"
#include "GlobalResDef.h"

extern "C" 
{
#include "CallSetSrvGprot.h"
#include "NotificationGprot.h"
}

#include "Mmi_rp_vapp_callset_def.h"

#include "vcp_navi_title_bar.h"
#include "vapp_callset_ctm.h"

#pragma arm section code = "DYNAMIC_CODE_CALLSET_ROCODE", rodata = "DYNAMIC_CODE_CALLSET_RODATA" 
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
#define VAPP_CALLET_CTM_GET_STRID(_idx) VappCallSetPageCtm::s_ctmResId[_idx]

/***************************************************************************** 
 * Class VappCallSetPageCtm
 *****************************************************************************/
VfxResId VappCallSetPageCtm::s_ctmResId[] = 
{
	STR_ID_VAPP_CALLSET_CTM_BAUDOT,
	STR_ID_VAPP_CALLSET_CTM_HCO,
	STR_ID_VAPP_CALLSET_CTM_VCO
};

void VappCallSetPageCtm::onInit()
{
    VfxPage::onInit(); // call base class

    VcpTitleBar *titlebar;
    VFX_OBJ_CREATE(titlebar, VcpTitleBar, this);
    titlebar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_CALLSET_CTM_SEL_MODE));
    setTopBar(titlebar);

	srv_callset_ctm_setting_enum setting = srv_callset_ctm_get_setting();

	m_activateIndex = (VfxU32)(setting <= SRV_CALLSET_CTM_SETTING_VCO ? setting : SRV_CALLSET_CTM_SETTING_BAUDOT);

    VcpListMenu *menu;
    VFX_OBJ_CREATE(menu, VcpListMenu, this);
    menu->setSize(getSize());
    menu->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);
    menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    menu->setContentProvider(this);
    menu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK);
    menu->m_signalItemSelectionStateChanged.connect(this, &VappCallSetPageCtm::onSelect);
    menu->m_signalItemTapped.connect(this, &VappCallSetPageCtm::onTapped);
}

VfxBool VappCallSetPageCtm::getItemText(
    VfxU32 index,                    
    VcpListMenuFieldEnum fieldType,  
    VfxWString &text,                
    VcpListMenuTextColorEnum &color  
    )
{
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
	text = VFX_WSTR_RES(VAPP_CALLET_CTM_GET_STRID(index));

    return VFX_TRUE;
}

VfxU32 VappCallSetPageCtm::getCount() const
{
	return (VfxU32)(SRV_CALLSET_CTM_SETTING_VCO + 1);
}

VcpListMenuItemStateEnum VappCallSetPageCtm::getItemState(
    VfxU32 index   
    ) const 
{
    return (index == m_activateIndex) ?
                VCP_LIST_MENU_ITEM_STATE_SELECTED : VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}

void VappCallSetPageCtm::onSelect(
    VcpListMenu* menu, 
    VfxU32 index, 
    VcpListMenuItemStateEnum state
    )
{
    if (state != VCP_LIST_MENU_ITEM_STATE_SELECTED)
    {
        return;
    }

    srv_callset_ctm_setting_struct setting;
	
    setting.mode = srv_callset_ctm_get_mode();
	setting.setting = (srv_callset_ctm_setting_enum)index;

    srv_callset_result_enum result = srv_callset_ctm_set_mode(&setting);
    if (result != SRV_CALLSET_RESULT_OK)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
                             MMI_EVENT_INFO_BALLOON,
                             MMI_NMGR_BALLOON_TYPE_FAILURE,
                             (WCHAR*)GetString(srv_callset_get_result_string_id(result)));
    }
    m_activateIndex = index;
}

void VappCallSetPageCtm::onTapped(
    VcpListMenu* menu,
    VfxU32 index)
{
    getMainScr()->popPage();
}

#pragma arm section code, rodata
