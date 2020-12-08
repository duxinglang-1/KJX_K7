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
 *  vapp_bootup_cali.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Calibration stage of booting
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_TOUCH_SCREEN__

#include "vapp_bootup.h"
#include "vapp_bootup_app.h"
#include "vcui_pen_calibration_gprot.h"
extern "C"
{
#include "BootupSrvIprot.h"
#include "PenCalibrationSrvGprot.h"
#ifndef __MTK_TARGET__ /* on MODIS */
#include "w32_utility.h"
#endif
}


void VappBootupApp::doPenCalibration(mmi_proc_func proc, void *userData)
{
    m_callbackProc = proc;
    m_callbackUserData = userData;

    m_cali_instance = vcui_pen_calibration_create(getGroupId(), this);
    vcui_pen_calibration_set_attribute(m_cali_instance, CUI_PEN_CALIBRATION_FIRST_CALIBRATION);
    mmi_frm_group_set_caller_proc(m_cali_instance, &VappBootupApp::penCalibrationProc, this);
    vcui_pen_calibration_run(m_cali_instance);
}


mmi_ret VappBootupApp::penCalibrationProc(mmi_event_struct *evt)
{
    VappBootupApp *app = static_cast<VappBootupApp*>(evt->user_data);

    if (evt->evt_id == EVT_ID_CUI_PEN_CALIBRATION_DONE)
    {
        if (app->m_callbackProc != NULL)
        {
            mmi_proc_func proc = app->m_callbackProc;
            void *userData = app->m_callbackUserData;
            app->m_callbackProc = NULL;

            pen_calibration_done_evt_struct done_evt;
            MMI_FRM_INIT_EVENT(&done_evt, EVT_ID_PEN_CALIBRATION_DONE);
            MMI_FRM_SEND_EVENT(&done_evt, proc, userData);
        }

        if (app->m_cali_instance != 0)
        {
            vcui_pen_calibration_close(app->m_cali_instance);
            app->m_cali_instance = 0;
        }
    }

    return MMI_RET_OK;
}




typedef struct
{
    mmi_frm_proc_id_info_struct id_info;
} vapp_bootup_cali_cntx_struct;


static vapp_bootup_cali_cntx_struct vapp_bootup_cali_cntx;

VfxBool vapp_bootup_needs_pen_calibration(void)
{
    /*----------------------------------------------------------------*/
    /* Declaration                                                    */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__

    return ((VfxBool)srv_setting_pen_calibration_is_calibration_needed() &&
            !srv_bootup_is_auto_power_on_test() &&
            !w32_modis_is_disable_touchscreencalibration());
            
#else /* __MTK_TARGET__ */

    return (srv_setting_pen_calibration_is_calibration_needed() &&
            !srv_bootup_is_auto_power_on_test());
            
#endif /* __MTK_TARGET__ */
}


static mmi_ret vapp_bootup_pen_calibration_completed(mmi_event_struct *evt)
{
    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_PEN_CALIBRATION_DONE);
    
    mmi_frm_proc_notify_completed(vapp_bootup_cali_cntx.id_info);

    return MMI_RET_OK;
}


mmi_frm_proc_result_enum vapp_bootup_flow_pen_calibration(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Declaration                                                    */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vapp_bootup_cali_cntx.id_info = id_info;
    
    if (vapp_bootup_needs_pen_calibration())
    {
        VappBootupApp *app = VappBootupApp::getApp();

        app->doPenCalibration(vapp_bootup_pen_calibration_completed, &vapp_bootup_cali_cntx);
        
        return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
    }

    return MMI_FRM_PROC_RESULT_COMPLETED;
}

#endif /* __MMI_TOUCH_SCREEN__ */
