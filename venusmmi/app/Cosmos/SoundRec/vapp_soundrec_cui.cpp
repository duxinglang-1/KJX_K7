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
 *  vapp_soundrec_cui.cpp
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h" 

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __MMI_SOUNDREC_CUI__

#include "vapp_soundrec.h"
#include "vapp_soundrec_util.h"
#include "vapp_soundrec_cui.h"
#include "mmi_rp_vapp_soundrec_def.h"
#include "../xml/vfx_xml_loader.h"

/* Pluto MMI headers */
#ifdef __cplusplus
extern "C"
{
#endif
#include "mdi_audio.h"
#include "FileMgrSrvGProt.h"
#include "vcui_soundrec_gprot.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif
#include "UcmSrvGprot.h"
#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Class Implementations
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VcuiSoundRecorder", VcuiSoundRecorder, VfxCui);

void VcuiSoundRecorder::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // create and display main screen
    VFX_OBJ_CREATE(scr, VcuiSoundRecorderScreen, this);
    scr->show();
}

void VcuiSoundRecorder::setParam(vcui_sndrec_param_enum param, VfxU32 value)
 {
    if(VCUI_SNDREC_PARAM_SIZE == param)
    {
        m_record_size = value;
    }
    else if(VCUI_SNDREC_PARAM_TIME == param)
    {
        m_record_time = value;
    }
    else if(VCUI_SNDREC_PARAM_QUALITY == param)
    {
        m_record_quality = value;
    }
    else if(VCUI_SNDREC_PARAM_PAGE_MODE == param)
    {
        m_param |= value;
    }
}

VfxU32 VcuiSoundRecorder::getParam(vcui_sndrec_param_enum param)
 {
    if(VCUI_SNDREC_PARAM_SIZE == param)
    {
        return m_record_size;
    }
    else if(VCUI_SNDREC_PARAM_TIME == param)
    {
        return m_record_time;
    }
    else if(VCUI_SNDREC_PARAM_QUALITY == param)
    {
        return m_record_quality;
    }
    else if(VCUI_SNDREC_PARAM_PAGE_MODE == param)
    {
        return m_param;
    }

    return 0;
}

void VcuiSoundRecorder::onInit()
{
    VfxApp::onInit();

    /*Register event handler when APP running */
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, &VcuiSoundRecorder::eventHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &VcuiSoundRecorder::eventHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE, &VcuiSoundRecorder::eventHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_UCM_STATUS_CHANGE, &VcuiSoundRecorder::eventHandler, this);

#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE, &VcuiSoundRecorder::eventHandler, this);
#endif
}

void VcuiSoundRecorder::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, &VcuiSoundRecorder::eventHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &VcuiSoundRecorder::eventHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE, &VcuiSoundRecorder::eventHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_UCM_STATUS_CHANGE, &VcuiSoundRecorder::eventHandler, this);

#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_dereg_event(EVT_ID_USB_ENTER_MS_MODE, &VcuiSoundRecorder::eventHandler, this);
#endif

    VfxApp::onDeinit();
}

mmi_ret VcuiSoundRecorder::eventHandler(mmi_event_struct *evt)
{
    if (evt->user_data == NULL)
        return MMI_RET_OK;

    VcuiSoundRecorder* cui = (VcuiSoundRecorder*) evt->user_data;

    switch (evt->evt_id)
    {
    #ifdef __MMI_USB_SUPPORT__
        case EVT_ID_USB_ENTER_MS_MODE:
        {
            /* Exit application */
            vcui_soundrec_evt_struct evt;

            MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_VCUI_SOUNDREC_RESULT, cui->getGroupId());

            evt.result = 0;

            cui->postToCaller((mmi_group_event_struct*)&evt);
            break;
        }
    #endif
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        case EVT_ID_SRV_UCM_STATUS_CHANGE:
        {
            cui->scr->notifyTopPage(evt);
            break;
        }

        case EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE:
            break;            
    }
    return MMI_RET_OK;
}

VFX_IMPLEMENT_CLASS("VcuiSoundRecorderScreen", VcuiSoundRecorderScreen, VfxMainScr);

void VcuiSoundRecorderScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    /* Get app handle and parameters */
    VcuiSoundRecorder *cui = (VcuiSoundRecorder*)getApp();
    VfxU32 record_size = cui->getParam(VCUI_SNDREC_PARAM_SIZE);
    VfxU32 record_time = cui->getParam(VCUI_SNDREC_PARAM_TIME);
    VfxU32 record_quality = cui->getParam(VCUI_SNDREC_PARAM_QUALITY);
    VfxU32 cui_mode = cui->getParam(VCUI_SNDREC_PARAM_PAGE_MODE);

    /* config record mode */
    VfxU8 mode = VappSoundRecorderRecordPage::RECORD_MODE_CUI;
    if(cui_mode & VCUI_SOUNDREC_PARAM_NO_PAUSE)
    {
        mode |= VappSoundRecorderRecordPage::RECORD_MODE_CUI_NO_PAUSE;
    }
    if(cui_mode & VCUI_SOUNDREC_PARAM_NO_PREVIEW)
    {
        mode |= VappSoundRecorderRecordPage::RECORD_MODE_CUI_NO_PREVIEW;
    }
    if(cui_mode & VCUI_SOUNDREC_PARAM_DISPLAY_REC_LIMIT)
    {
        mode |= VappSoundRecorderRecordPage::RECORD_MODE_CUI_DISPLAY_REC_LIMIT;
    }

    /* create and display first page */
    VappSoundRecorderRecordPage *page;
    VFX_OBJ_CREATE_EX(page, VappSoundRecorderRecordPage, this, (mode));
    page->setRecordParam(VappSoundRecorderRecordPage::SNDREC_PARAM_SIZE, record_size);
    page->setRecordParam(VappSoundRecorderRecordPage::SNDREC_PARAM_TIME, record_time);    
    if(VCUI_SOUNDREC_QUALITY_NORMAL == record_quality)
    {
        page->setRecordParam(VappSoundRecorderRecordPage::SNDREC_PARAM_QUALITY, VappSoundRecorderRecordPage::SNDREC_QUALITY_NORMAL);
    }
    else if(VCUI_SOUNDREC_QUALITY_HIGH == record_quality)
    {
        page->setRecordParam(VappSoundRecorderRecordPage::SNDREC_PARAM_QUALITY, VappSoundRecorderRecordPage::SNDREC_QUALITY_HIGH);
    }
    pushPage(0, page);
}

void VcuiSoundRecorderScreen::notifyTopPage(mmi_event_struct *evt)
{
    VfxPage *topPage = getPage(0);
    if(topPage != NULL)
    {
        topPage->processProc(evt);
    }
}

/***************************************************************************** 
 * Export C type CUI Functions
 *****************************************************************************/

mmi_id vcui_soundrec_create(mmi_id parent_id)
{
    mmi_id cui_id = VfxAppLauncher::createCui(
        VCUI_SOUNDREC,                              /* Cui's app id */
        VFX_OBJ_CLASS_INFO(VcuiSoundRecorder),       /* Cui class */
        parent_id,                            /* parent group id */
        NULL, 0);                             /* parameters, if any */
    return cui_id;
}

void vcui_soundrec_run(mmi_id cui_id)
{
    VfxAppLauncher::runCui(cui_id);
}


void vcui_soundrec_close(mmi_id cui_id)
{
    VfxAppLauncher::terminate(cui_id);
}


MMI_BOOL vcui_soundrec_set_param(mmi_id cui_id, VfxU32 param)
{
    VcuiSoundRecorder *cui = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VcuiSoundRecorder);
    cui->setParam(VCUI_SNDREC_PARAM_PAGE_MODE, param);

    return MMI_TRUE;
}


void vcui_soundrec_set_record_time(mmi_id cui_id, VfxU32 duration)
{
    VcuiSoundRecorder *cui = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VcuiSoundRecorder);
    cui->setParam(VCUI_SNDREC_PARAM_TIME, duration);
}

void vcui_soundrec_set_record_size(mmi_id cui_id, VfxU32 size)
{
    VcuiSoundRecorder *cui = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VcuiSoundRecorder);
    cui->setParam(VCUI_SNDREC_PARAM_SIZE, size);
}

void vcui_soundrec_set_record_quality(mmi_id cui_id, VfxU32 quality)
{
    VcuiSoundRecorder *cui = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VcuiSoundRecorder);
    cui->setParam(VCUI_SNDREC_PARAM_QUALITY, quality);
}

#endif

