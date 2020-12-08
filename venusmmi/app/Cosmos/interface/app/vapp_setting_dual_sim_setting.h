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
 *  vapp_setting_dual_sim_setting.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_SETTING_DUAL_SIM_SETTING_H__
#define __VAPP_SETTING_DUAL_SIM_SETTING_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
extern "C"
{
#include "GeneralSettingSrvGprot.h"    
#include "ModeSwitchSrvGprot.h"
}
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
extern "C"	mmi_ret verify_uart_setting(mmi_event_struct *evt);

/***************************************************************************** 
 * Class 
 *****************************************************************************/
#ifdef __GEMINI__
extern VfxBool vapp_multi_sim_cell_checking_hdlr(void);

#ifdef __MMI_UART_SETTING__
/***************************************************************************** 
 * VappUARTSettingCell
 *****************************************************************************/
class VappUARTSettingCell : public VcpFormItemLauncherCell
{
    VFX_DECLARE_CLASS(VappUARTSettingCell);

    // Overrides
    public:
    virtual void onInit();
    virtual void onTap(VcpFormItemCell* sender, VfxId senderId);
    virtual VfxWString getHint();
    virtual void updateCell() {setHintText(getHint());};

    // Methods
    public:
    VappUARTSettingCell() {m_primaryCard = srv_setting_get_primary_card();};
    void onContextUpdate(mmi_sim_enum sim) {m_primaryCard = sim; updateCell();};
    // Variables
    private:
    mmi_sim_enum m_primaryCard;
};
#endif /*__MMI_UART_SETTING__*/

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*#if 0*/
/***************************************************************************** 
 * VappBootupQuerySettingCell
 *****************************************************************************/
class VappBootupQuerySettingCell : public VcpFormItemSwitchCell
{
    VFX_DECLARE_CLASS(VappBootupQuerySettingCell);

    // Overrides
    public:
    virtual void onInit();
	virtual void onDeinit();

    // Methods
    public:
    VappBootupQuerySettingCell() {m_switchState = srv_mode_switch_is_query_mode_enabled();};
    void onSwitch(
        VcpFormItemSwitchCell* sender, // Sender
		VfxId senderId, // Sender id
		VfxBool switchValue// new switch value
		);
	VfxBool getStatus() { return m_switchState;}
	static mmi_ret flightModeSwitchHdlr(mmi_event_struct *evt);
    // Variables
    private:
    VfxBool m_switchState;
}; 

/***************************************************************************** 
 * VappSimSettingCell
 *****************************************************************************/
class VappMultiSimSettingCaptionCell : public VcpFormItemCaption
{
    VFX_DECLARE_CLASS(VappMultiSimSettingCaptionCell);

    // Overrides
    public:
    virtual void onInit();
};

/***************************************************************************** 
 * VappSimSettingCell
 *****************************************************************************/
class VappSimSettingCell : public VcpFormItemSwitchCell
{
    VFX_DECLARE_CLASS(VappSimSettingCell);

    // Overrides
    public:
    virtual void onInit();
    virtual void onDeinit();

    // Methods
    public:
    virtual void onSwitch(
        VcpFormItemSwitchCell* sender, // Sender
		VfxId senderId, // Sender id
		VfxBool switchValue// new switch value
		);
    virtual void updateCell();
    virtual void checkService();
    virtual void onCellTap(VfxPenEvent &event);
    virtual void onTapped(VcpFormItemCell* sender, VfxId id);

    static mmi_ret onSwitchProc(mmi_event_struct *evt);
    static mmi_sim_enum getSimforInit();
    static void deinitSim(mmi_sim_enum sim);

    // Variables
    protected:
    mmi_sim_enum m_sim;
    VfxBool m_switchState;
    VfxWString m_simName;
    static VfxBool m_simIsInit[MMI_MAX_SIM_NUM];
}; 
#endif
#endif /* __VAPP_SETTING_DUAL_SIM_SETTING_H__ */
 
