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
 *  Vapp_Setting_DualSimSetting.h
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
#ifndef __VAPP_DUAL_SIM_SETTING_H__
#define __VAPP_DUAL_SIM_SETTING_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_setting_dual_sim_setting.h"
/***************************************************************************** 
 * External function
 *****************************************************************************/
 
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
/***************************************************************************** 
 * Class 
 *****************************************************************************/
#ifdef __GEMINI__
/***************************************************************************** 
 * VappPrimaryCardSettingContentProvider
 *****************************************************************************/
class VappPrimaryCardSettingContentProvider : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappPrimaryCardSettingContentProvider);

    // Overrides
    public:
    virtual void onInit();
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
    virtual VfxU32 getCount() const;
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const {return ((m_highlightItem == index) ? VCP_LIST_MENU_ITEM_STATE_SELECTED: VCP_LIST_MENU_ITEM_STATE_NONE);}
    // Methods
    void onSelectItem(VcpListMenu *listMenu, VfxU32 selectIdx);
    void onConfirmBtnClicked(VfxObject* sender, VfxId id);
    void setHighlightItem(VfxU32 highlightItem) ;//{m_highlightItem = highlightItem;};

    // Variables
    public:
    VfxSignal1 <mmi_sim_enum> m_signalUpdate;

    private:
    VcpListMenu *m_listMenu;
    VcpConfirmPopup* m_popup;
    VfxU32 m_highlightItem;
    VfxU32 m_selectItem;    
#ifdef __MMI_UART_SETTING__
    VfxU8 m_sim_num;
    VfxU8 m_sim_exist[MMI_MAX_SIM_NUM];
#endif
};

class VappSimNameSettingPage : public VfxPage
{
    // Overrides
    protected:
    virtual void onInit();
    virtual void onDeinit();

    // Methods
    public:
    VappSimNameSettingPage() : m_sim(MMI_SIM1) {};
    VappSimNameSettingPage(mmi_sim_enum sim) {m_sim = sim;}
    void onToolBarTapped(VfxObject *obj, VfxId id);
    static mmi_ret onFlightModeHdlr(mmi_event_struct* evt);

    // Variables
    public:
    VfxSignal0 m_signalSimNameUpdate;
    
    protected:
    VcpFormItemTextInput *m_textInputCell;
    mmi_sim_enum m_sim;
};
#endif
#endif /* __VAPP_DUAL_SIM_SETTING_H__ */
 
