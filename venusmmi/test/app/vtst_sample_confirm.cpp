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
 *  vtst_sample_confirm.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Cosmos Sample Screen - Confirm
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_config.h"

#if defined(__AFX_RT_TEST__)
#include "vcp_popup.h"
#include "vtst_rt_main.h"

#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_string.h"
#include "vfx_signal.h"
#include "mmi_frm_history_gprot.h"
#include "vfx_app_cat_scr.h"

/***************************************************************************** 
 * Class VtstSampleConfirm
 *****************************************************************************/
class VtstSampleConfirm : public VtstRtScr
{
    VFX_DECLARE_CLASS(VtstSampleConfirm);

// Constructor / Destructor
public:
    VtstSampleConfirm():
        m_confirmPopup(NULL)
        {}

// Override
protected:
    virtual void onInit();
	virtual VfxS32 start() {return 1;}
	virtual VfxS32 phase(VfxS32 idx) {return -1;}

// Member Variables
private:
    VcpConfirmPopup* m_confirmPopup;

    void eventHandler(VfxObject* obj, VfxId id);
};


VFX_IMPLEMENT_CLASS("VtstSampleConfirm", VtstSampleConfirm, VtstRtScr);


void VtstSampleConfirm::onInit()
{
    VtstRtScr::onInit();
    setBgColor(VFX_COLOR_BLACK);

    VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
    m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
    m_confirmPopup->setText(VFX_WSTR("Are you sure you want to delete the \"Home\" group, and the Group member's group info will be removed"));
    m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    m_confirmPopup->setCustomButton(VFX_WSTR("Delete") , VFX_WSTR("Cancel"), VCP_POPUP_BUTTON_TYPE_RECOMMEND, VCP_POPUP_BUTTON_TYPE_CANCEL);
    m_confirmPopup->show(VFX_TRUE);
    m_confirmPopup->m_signalButtonClicked.connect(this, &VtstSampleConfirm::eventHandler);
}


void VtstSampleConfirm::eventHandler(VfxObject* obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_2)
    {
        GoBackHistory();
    }
}


VtstTestResultEnum vtst_sample_confirm(VfxU32 param)
{
    VTST_START_SCRN(VtstSampleConfirm);

    return VTST_TR_OK;
}

#endif
