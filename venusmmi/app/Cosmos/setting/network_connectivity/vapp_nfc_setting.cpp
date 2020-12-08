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
  *  vapp_nfc_setting.cpp
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
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_setting_nfc_setting.h"
#include "mmi_rp_vapp_setting_def.h"
#include "vapp_network_checking.h"
extern "C"
{
#include "ModeSwitchSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "Wgui_categories_util.h"
#include "Nvram_data_items.h"
#include "L4c_common_enum.h"
#include "Gui_typedef.h"
#include "UcmSrvGprot.h"
#include "mtk_nfc_ext_msg.h"
}
/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifdef __NFC_SUPPORT__
VfxBool VappNFCSwitchCell::m_isBusy         = VFX_FALSE;
VappNFCSwitchCell* VappNFCSwitchCell::m_cell = NULL;
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
extern "C"
{
    // Get / set the nfc status value from / to nvram
MMI_BOOL vapp_get_nfc_status()
{
    MMI_BOOL result = MMI_FALSE;
    VfxU8 data = 0;
    S16 error;
    ReadValue(NVRAM_EF_NFC_SETTING_LID, &data, DS_BYTE, &error);
    if (0 != data)
    {
        result = MMI_TRUE;
    }

    return result;
}

    void vapp_set_nfc_status(MMI_BOOL status)
{
    S16 error;
        VfxU8 data = (VfxU8)status;
        WriteValue(NVRAM_EF_NFC_SETTING_LID, &data, DS_BYTE, &error);    
}

void vapp_nfc_update_icon()
{
    if (vapp_get_nfc_status())
    {
        wgui_status_icon_bar_show_icon(STATUS_ICON_NFC);
    }
    else
    {
        wgui_status_icon_bar_hide_icon(STATUS_ICON_NFC);
    }
}

    // Send msg to nfc
    void vapp_send_nfc_switch_req(MMI_BOOL status)
    {    
        if (MMI_TRUE == status)
        {
            mmi_frm_send_ilm((oslModuleType)MOD_NFC, MSG_ID_NFC_LIB_INIT_REQ, (oslParaType*)NULL, NULL);
        }
        else
        {
            mmi_frm_send_ilm((oslModuleType)MOD_NFC, MSG_ID_NFC_LIB_DEINIT_REQ, (oslParaType*)NULL, NULL);
        }
    }

    // Handle the msg from nfc
static void vapp_nfc_init_rsp_hdlr(void* msg)
{
    nfc_init_deinit_rsp_struct *rsp =(nfc_init_deinit_rsp_struct*)msg;
    
    VappNFCSwitchCell* cell = VappNFCSwitchCell::getCell();
    if (NULL != cell)
    {
        cell->updateCellProc(NFC_RSP_SET_ON, rsp->action_result);
    }
    else
{
    	if (rsp->action_result)
    	{
	        vapp_set_nfc_status(MMI_TRUE);
    vapp_nfc_update_icon();
    	}
    }
    VappNFCSwitchCell::setBusyStatus(VFX_FALSE);
}

static void vapp_nfc_deinit_rsp_hdlr(void* msg)
{
    nfc_init_deinit_rsp_struct *rsp =(nfc_init_deinit_rsp_struct*)msg;
    
    VappNFCSwitchCell* cell = VappNFCSwitchCell::getCell();
    if (NULL != cell)
    {
        cell->updateCellProc(NFC_RSP_SET_OFF, rsp->action_result);
    }
    else
    {
    	if (rsp->action_result)
    	{
	        vapp_set_nfc_status(MMI_FALSE);
	        vapp_nfc_update_icon();        		
    	}
    }
    VappNFCSwitchCell::setBusyStatus(VFX_FALSE);
}


void vapp_nfc_reset(void* msg)
{
    nfc_mmi_notify_event_struct* notify = (nfc_mmi_notify_event_struct*)msg;
    
    if (NFC_MMI_NOTIFY_EVENT_NFC_OFF == notify->event)
    {    
        VappNFCSwitchCell* cell = VappNFCSwitchCell::getCell();
        if (NULL != cell)
        {
            cell->updateCellProc(NFC_RSP_SET_RST, 1);
        }
	else
	{
            vapp_set_nfc_status(MMI_FALSE);
            vapp_nfc_update_icon();
        }
    }
    VappNFCSwitchCell::setBusyStatus(VFX_FALSE);
}

void vapp_nfc_setting_init()
{
    SetProtocolEventHandler(vapp_nfc_init_rsp_hdlr, MSG_ID_NFC_LIB_INIT_RSP);
    SetProtocolEventHandler(vapp_nfc_deinit_rsp_hdlr, MSG_ID_NFC_LIB_DEINIT_RSP);
    SetProtocolEventHandler(vapp_nfc_reset, MSG_ID_NFC_LIB_MMI_EVENT_NOTIFY);

    #ifdef __MTK_TARGET__
    MMI_BOOL nfc_status = vapp_get_nfc_status();
    vapp_send_nfc_switch_req(nfc_status);
    VappNFCSwitchCell::setBusyStatus(VFX_TRUE);
    #endif
}
}
/***************************************************************************** 
 * Class 
 *****************************************************************************/

/***************************************************************************** 
 * VappNFCSwitchCell
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappNFCSwitchCell", VappNFCSwitchCell, VcpFormItemSwitchCell);
void VappNFCSwitchCell::onInit()
{
	VcpFormItemSwitchCell::onInit();

    setMainText(VFX_WSTR_RES(STR_ID_VAPP_NFC_SWITCH));
    m_signalSwitchChangeReq.connect(this, &VappNFCSwitchCell::onSwitch);
    m_status = (VfxBool)vapp_get_nfc_status();
    setSwitchStatus(m_status);
    m_cell = this;
    setIsTappable(VFX_FALSE);
    #ifdef __MTK_TARGET__
    if (m_isBusy)
    {
        showProcessInd();
        m_status = !m_status;
    }
    #endif
}

void VappNFCSwitchCell::onDeinit()
{
    m_cell = NULL;
    VcpFormItemSwitchCell::onDeinit();
}

void VappNFCSwitchCell::onSwitch(VcpFormItemSwitchCell* sender, VfxId senderid, VfxBool status)
{
	if (getBusyStatus())
	{
		return;
	}
    if (m_status != status)
	{
		m_status = status;
		setBusyStatus(VFX_TRUE);
		showProcessInd();
        vapp_send_nfc_switch_req((MMI_BOOL)m_status);
	}
}

void VappNFCSwitchCell::updateCellProc(NfcRspType setType, VfxBool rspCode)
{    
    if (setType == NFC_RSP_SET_RST)
    {
        vapp_set_nfc_status(MMI_FALSE);
        setNFCStatus(VFX_FALSE); 
        }
    else if (rspCode&&
    		(setType == NFC_RSP_SET_ON && m_status
            || setType == NFC_RSP_SET_OFF && !m_status))
	{
        vapp_set_nfc_status((MMI_BOOL)m_status);
        setNFCStatus(m_status);
	}
	else
	{	
        mmi_id strId = m_status? STR_ID_VAPP_NFC_SWITCH_ON_FAIL : STR_ID_VAPP_NFC_SWITCH_OFF_FAIL;
	    VcpConfirmPopup *errPop;
        VFX_OBJ_CREATE(errPop, VcpConfirmPopup, this);
            errPop->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
            errPop->setText(VFX_WSTR_RES(strId));
    	    errPop->setInfoType(VCP_POPUP_TYPE_FAILURE);		
        errPop->m_signalButtonClicked.connect(this, &VappNFCSwitchCell::onPopupBtnTap);
	}
    
    vapp_nfc_update_icon();
    VappNFCSwitchCell::setBusyStatus(VFX_FALSE);
}

void VappNFCSwitchCell::onPopupBtnTap(VfxObject *obj, VfxId id)
{
    m_status = vapp_get_nfc_status();
    setNFCStatus(m_status);
	return;
}

void VappNFCSwitchCell::setNFCStatus(VfxBool isNFCOn)
{
    m_status = isNFCOn;
    setSwitchStatus(m_status);
}
#endif //__NFC_SUPPORT__
