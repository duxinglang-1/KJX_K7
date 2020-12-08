/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   vapp_picture_quality_setting.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   picture quality setting
 *
 * Author:
 * -------
 * -------
 *
/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h" 

#ifdef __LCD_COLOR_ENGINE_SUPPORT__
#include "vcp_include.h"
#include "vfx_mc_include.h"
#include "mmi_rp_vapp_setting_def.h"
#include "vapp_setting_picture_quality_setting.h"
#include "gdi_include.h"

extern "C"
{
#include "Nvram_data_items.h"
}

extern "C"
{

MMI_BOOL vapp_get_picture_quality_status()
{
    MMI_BOOL result = MMI_FALSE;
    VfxU8 data = 0;
    S16 error;
    ReadValue(NVRAM_PICTURE_QUALITY_SETTING_LID, &data, DS_BYTE, &error);
    if (0 != data)
    {
        result = MMI_TRUE;
    }

    return result;
}

void vapp_set_picture_quality_status(MMI_BOOL status)
{
    S16 error;
    VfxU8 data = (VfxU8)status;
    WriteValue(NVRAM_PICTURE_QUALITY_SETTING_LID, &data, DS_BYTE, &error);    
}


void vapp_picture_quality_setting_init()
{
    MMI_BOOL pq_status = vapp_get_picture_quality_status();
    if (pq_status == MMI_TRUE)
    {
        gdi_color_engine_custom_on();
    }
    else
    {
        gdi_color_engine_custom_off();
    }
}

}
/***************************************************************************** 
 * VappPictureQualitySwitchCell
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappPictureQualitySwitchCell", VappPictureQualitySwitchCell, VcpFormItemSwitchCell);
VappPictureQualitySwitchCell::VappPictureQualitySwitchCell()
{
//    gdi_color_engine_get_power_status((kal_bool*)&m_switchState);
    m_switchState = (VfxBool)vapp_get_picture_quality_status();
}

void VappPictureQualitySwitchCell::onInit()
{
	VcpFormItemSwitchCell::onInit();

   // setMainText(VFX_WSTR("Picture Quality"));
    setMainText(STR_ID_VAPP_SETTING_PICTURE_QUALITY);
    setSwitchStatus(m_switchState);
    setIsTappable(VFX_FALSE);
    m_signalSwitchChangeReq.connect(this, &VappPictureQualitySwitchCell::onSwitch);
}

void VappPictureQualitySwitchCell::onSwitch(VcpFormItemSwitchCell* sender, VfxId senderId, VfxBool switchValue)
{
    m_switchState = switchValue;
    if (switchValue == VFX_TRUE)
    {
        gdi_color_engine_custom_on();
        vapp_set_picture_quality_status(MMI_TRUE);
    }
    else
    {
        gdi_color_engine_custom_off();
        vapp_set_picture_quality_status(MMI_FALSE);
    }
    setSwitchStatus(m_switchState);
    VcpForm *cellListForm;
    cellListForm = (VcpForm*)getParent();
    cellListForm->invalidate();
}

#endif // __LCD_COLOR_ENGINE_SUPPORT__

//End of File
