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
 *  vapp_bootup_disk.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Disk check of venus MMI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMIDatatype.h"
 
#include "vfx_datatype.h"
#include "vfx_page.h"
#include "vfx_text_frame.h"

#include "vcp_button.h"

#include "vapp_bootup.h"
#include "vapp_bootup_app.h"

#include "vapp_style_dyer_gprot.h"
#include "mmi_rp_app_cosmos_global_def.h"
#pragma arm section code = "DYNAMIC_CODE_BOOTUP_ROCODE", rodata = "DYNAMIC_CODE_BOOTUP_RODATA"
class VappBootupDiskCheckInfoPage : public VfxPage
{
private:
    enum layout_constant
    {
#if defined(__MMI_MAINLCD_480X800__)
        MARGIN = 20,
        FONT_SIZE = 28,
        OK_BUTTON_HEIGHT = 80,
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
        MARGIN = 8,
        FONT_SIZE = 15,
        OK_BUTTON_HEIGHT = 42,
#else
        MARGIN = 10,
        FONT_SIZE = 20,
        OK_BUTTON_HEIGHT = 45,
#endif

        END_OF_LAYOUT_CONSTANT
    };

    VfxTextFrame *m_message;
    VcpButton *m_okBtn;

    void onOkClicked(VfxObject *obj, VfxId id);

protected:
    virtual void onInit();

public:
    VfxSignal0 m_signalDone;

    VappBootupDiskCheckInfoPage() :
        m_message(NULL),
        m_okBtn(NULL)
    {
    }

    void setMessage(const VfxResId msg_id);
};


void VappBootupDiskCheckInfoPage::onInit()
{
    VfxPage::onInit();

    //VappStyleDyer *dyer = VappStyleDyer::getDefaultDyer();
    //dyer->dyePage(this);
	setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    VfxSize pageSize = getSize();

    VFX_OBJ_CREATE(m_okBtn, VcpButton, this);
    m_okBtn->setText(STR_GLOBAL_OK);
    m_okBtn->setPos(MARGIN, pageSize.height - OK_BUTTON_HEIGHT - MARGIN);
    m_okBtn->setSize(pageSize.width - 2 * MARGIN, OK_BUTTON_HEIGHT);
    m_okBtn->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_NONE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_okBtn->m_signalClicked.connect(this, &VappBootupDiskCheckInfoPage::onOkClicked);
}


void VappBootupDiskCheckInfoPage::setMessage(const VfxResId msg_id)
{
    VfxSize pageSize = getSize();

    if (m_message == NULL)
    {

        
        VFX_OBJ_CREATE(m_message, VfxTextFrame, this);
        VfxFontDesc font;
    	font.size = VFX_FONT_DESC_VF_SIZE(FONT_SIZE);
    	m_message->setFont(font);       
		m_message->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
        m_message->setAutoResized(VFX_TRUE);
        m_message->setString(msg_id);
        m_message->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
        m_message->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        m_message->setSize(pageSize.width - 2 * MARGIN, m_message->getSize().height);
        m_message->setAnchor(0.5, 0.5);
        m_message->setPos(pageSize.width / 2, pageSize.height / 2);
    }
    else
    {
        m_message->setString(msg_id);
        m_message->setSize(m_message->getMeasureBounds().size);
    }
}


void VappBootupDiskCheckInfoPage::onOkClicked(VfxObject *obj, VfxId id)
{
    m_signalDone.emit();
}


VfxBool VappBootupApp::checkDisk(mmi_proc_func proc, void *userData)
{
    VFX_ASSERT(proc != NULL);
    
    m_callbackProc = proc;
    m_callbackUserData = userData;

    VfxS32 error_code = FS_SanityCheck();
    VfxId error_msg_str_id = 0;

    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_CHECK_DISK, error_code);

    switch (error_code)
    {
        case FS_NO_ERROR:
            break;

        case FS_FDM_SYS_DRIVE_BROKEN:
        case FS_FDM_MULTIPLE_BROKEN:
        case FS_FDM_USER_DRIVE_BROKEN:
            error_msg_str_id = STR_ID_VAPP_BOOTUP_SYSTEM_DRIVE_CORRUPTED;
            break;

        case FS_FDM_VERSION_MISMATCH:
            error_msg_str_id = STR_ID_VAPP_BOOTUP_NAND_VERSION_MISMATCH;
            break;

        case FS_QUOTA_OVER_DISK_SPACE:
            error_msg_str_id = STR_ID_VAPP_BOOTUP_NAND_QUOTA_OVER_DISK;
            break;

        case FS_QUOTA_USAGE_WARNING:
            error_msg_str_id = STR_ID_VAPP_BOOTUP_NAND_QUOTA_USAGE_WARNING;
            break;

        default:
            break;
    }

    if (error_msg_str_id != 0)
    {
        VappBootupDiskCheckInfoPage *infoPage;
        VFX_OBJ_CREATE(infoPage, VappBootupDiskCheckInfoPage, m_mainScr);
        infoPage->setMessage(error_msg_str_id);
        infoPage->setAllowDelete(VFX_FALSE);
        infoPage->m_signalDone.connect(this, &VappBootupApp::onDiskCheckMessageConfirmed);
        
        m_mainScr->pushPage(PAGE_DISK_CHECK, infoPage);
        showMainScr();

        return VFX_TRUE;
    }

    return VFX_FALSE;
}


// User confirmed on disk check warning page, send event to notify completed
void VappBootupApp::onDiskCheckMessageConfirmed()
{
    VfxPage *page = m_mainScr->getPage(PAGE_DISK_CHECK);
    if (page != NULL)
    {
        page->setIsDisabled(VFX_TRUE);
    }

    if (m_callbackProc != NULL)
    {
        disk_checked_evt_struct checked_evt;
        mmi_proc_func proc;
        void *user_data;
    
        proc = m_callbackProc;
        user_data = m_callbackUserData;
        m_callbackProc = NULL;

        MMI_FRM_INIT_EVENT(&checked_evt, EVT_ID_DISK_CHECKED);
        MMI_FRM_SEND_EVENT(&checked_evt, proc, user_data);
    }
}



typedef struct
{
    mmi_frm_proc_id_info_struct id_info;
} vapp_bootup_disk_check_cntx_struct;

static vapp_bootup_disk_check_cntx_struct g_vapp_bootup_disk_check_cntx;

static mmi_ret vapp_bootup_disk_check_on_completed(mmi_event_struct *evt);

mmi_frm_proc_result_enum vapp_bootup_flow_disk_check(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info)
{
    vapp_bootup_disk_check_cntx_struct *cntx = &g_vapp_bootup_disk_check_cntx;
    VappBootupApp *app = VappBootupApp::getApp();

    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_FLOW_DISK_CHECK);

    cntx->id_info = id_info;
    if (app->checkDisk(vapp_bootup_disk_check_on_completed, cntx))
    {
        return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
    }

    return MMI_FRM_PROC_RESULT_COMPLETED;
}


static mmi_ret vapp_bootup_disk_check_on_completed(mmi_event_struct *evt)
{
    vapp_bootup_disk_check_cntx_struct *cntx =
        static_cast<vapp_bootup_disk_check_cntx_struct*>(evt->user_data);
        
    mmi_frm_proc_notify_completed(cntx->id_info);

    return MMI_RET_OK;
}
#pragma arm section code, rodata
