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
 *  vapp_bootup_sel_sim.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  SIM selection page
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

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMIDataType.h"

extern "C"
{
#include "SimCtrlSrvGprot.h"
}

#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_control.h"
#include "vfx_signal.h"
#include "vfx_text_frame.h"

#include "vcp_button.h"
#include "vcp_switch.h"

#include "vapp_sim_setting_gprot.h"
#include "vapp_style_dyer_gprot.h"
#include "vapp_bootup.h"
#include "vapp_bootup_app.h"
#include "mmi_rp_app_cosmos_global_def.h"
#pragma arm section code = "DYNAMIC_CODE_BOOTUP_ROCODE", rodata = "DYNAMIC_CODE_BOOTUP_RODATA"
using namespace VappBootupSimStr;
/***************************************************************************** 
 * Class VappBootupTextCtrl
 *****************************************************************************/
#if (MMI_MAX_SIM_NUM >= 2)
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_MAINLCD_480X800__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_MAINLCD_320X480__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
#endif

/***************************************************************************** 
 * Class VappBootupConfigSimPage
 *****************************************************************************/
void VappBootupConfigSimPage::onInit()
{
    VfxPage::onInit();
    
    //VappStyleDyer *dyer = VappStyleDyer::getDefaultDyer();
    //dyer->dyePage(this);
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    VfxSize pageSize = getSize();


	
    VfxTextFrame *promptText;
    VFX_OBJ_CREATE(promptText, VfxTextFrame, this);

    VfxFontDesc font;
    font.size = VFX_FONT_DESC_VF_SIZE(PROMPT_TEXT_FONT_SIZE);
    promptText->setFont(font);
	promptText->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
    promptText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    promptText->setAnchor(0.5, 1.0);
    promptText->setPos(pageSize.width / 2, PROMPT_TEXT_BOTTOM_Y);
    promptText->setSize(pageSize.width - 2 * MARGIN, PROMPT_TEXT_HEIGHT);
    promptText->setAutoFontSize(VFX_TRUE);
    promptText->setString(STR_ID_VAPP_BOOTUP_SELECT_SIM);
    promptText->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_NONE);

    // Select SIM form
    VfxS32 formItemY = CONFIG_FORM_Y;
    //static const VfxS32 MAX_SIM_NAME_STR_LEN = 128;
    formItemY += createHorizontalLine(0, formItemY, pageSize.width);

	VFX_OBJ_CREATE(m_form, VcpForm, this);
	m_form->setPos(0, formItemY);
	m_form->setBounds(VfxRect(0, 0, LCD_WIDTH, LCD_HEIGHT - CONFIG_FORM_Y));


    for (VfxS32 i = 0; i < MMI_SIM_TOTAL; i++)
    {
        mmi_sim_enum sim = mmi_frm_index_to_sim(i);
        VfxBool simIsInserted = srv_bootup_sim_is_inserted(sim) ? VFX_TRUE : VFX_FALSE;
		VFX_OBJ_CREATE(m_simModeSwitch[i], VcpFormItemSwitchCell, m_form);
		if(simIsInserted)
		{
			
			m_simModeSwitch[i]->setSwitchStatus(VFX_TRUE);
			m_simModeSwitch[i]->setMainText(getSimStrByIndex(i));
			m_simModeSwitch[i]->m_signalSwitchChangeReq.connect(this, &VappBootupConfigSimPage::onSwitch);
		}
		else
		{
			m_simModeSwitch[i]->setSwitchStatus(VFX_FALSE);
			m_simModeSwitch[i]->setMainText(STR_ID_VAPP_BOOTUP_EMPTY_SIM_SLOT);
			m_simModeSwitch[i]->setIsDisabled(VFX_TRUE);
		}
		m_form->addItem(m_simModeSwitch[i], i);

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
#endif		
    }
    
	VFX_OBJ_CREATE(m_okBtn, VcpFormItemBigButton, m_form);
	m_okBtn->setButtonText(STR_GLOBAL_OK);
	m_okBtn->m_signalButtonClick.connect(this, &VappBootupConfigSimPage::onOkBtnClicked);
	m_okBtn->getButton()->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
	m_form->addItem(m_okBtn, Button);

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
#endif	
}


VfxS32 VappBootupConfigSimPage::createHorizontalLine(
    //VappStyleDyer *dyer,
    VfxS32 x,
    VfxS32 y,
    VfxS32 len)
{
    VfxFrame *lineFrame;
    VFX_OBJ_CREATE(lineFrame, VfxFrame, this);
    lineFrame->setImgContent(VfxImageSrc(IMG_COSMOS_SEPARATOR_LINE));
    lineFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    //dyer->dyeLineOnPage(lineFrame);
    lineFrame->setRect(x, y, len, LINE_WIDTH);

    return LINE_WIDTH;
}


#if 0
/* under construction !*/
#endif
void VappBootupConfigSimPage::onOkBtnClicked(VfxId)
{
    VfxU32 enabledSim = 0;

    for (VfxS32 i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if (m_simModeSwitch[i] != NULL &&
            m_simModeSwitch[i]->getSwitchStatus())
        {
            enabledSim |= srv_sim_ctrl_get_sim_by_index(i);
        }
    }

    m_signalDone.emit(enabledSim);
}

void VappBootupConfigSimPage::onSwitch(VcpFormItemSwitchCell* item, VfxId id, VfxBool state)
{
	item->setSwitchStatus(state);
}

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
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
#endif
#endif /* MMI_MAX_SIM_NUM */
#pragma arm section code, rodata
