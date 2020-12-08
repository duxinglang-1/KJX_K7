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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   widget_view_ui.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements widget view UI presentation
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/
extern "C"
{
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */
//#include "syscomp_config.h"
#include "task_config.h"      	/* Task creation */
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "widget_adp_struct.h"
#include "Conversions.h"
}


#include "vfx_uc_include.h"
#include "vapp_launcher_app.h"
#include "vapp_widget_view.h"
extern "C"
{
  #include "vcui_camco_gprot.h"
}
/*****************************************************************************
 * Class Declaration
 *****************************************************************************/
class VappWidgetCameraAdp : public VfxApp
{
    VFX_DECLARE_CLASS(VappWidgetCameraAdp);

// Constructor / Destructor
public:
    VappWidgetCameraAdp();

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);

    virtual void onDeinit();

    virtual mmi_ret onProc(mmi_event_struct *);

private:
    void *m_data;
};


static void send_message(void *local_para_ptr, void *peer_buff_ptr, msg_type ilm_id)
{
    ilm_struct *ilm_ptr = NULL;

    /* allocate ilm */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*) local_para_ptr;
    ilm_ptr->msg_id = ilm_id;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buff_ptr;

    SEND_ILM(MOD_MMI, MOD_GADGET, MMI_GADGET_SAP, ilm_ptr);
}

static void send_capture_image_response(void *user_data, int ret, kal_uint8 *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_capture_image_rsp_struct *rsp = (widget_capture_image_rsp_struct *)
      construct_local_para(sizeof(widget_capture_image_rsp_struct), TD_RESET);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp->user_data = user_data;
    rsp->ret = ret;
    if (file_path)
    {
        mmi_ucs2ncpy((CHAR *)rsp->img_path, (const CHAR *)file_path, sizeof(rsp->img_path));
    }
    send_message(rsp, NULL, MSG_ID_WIDGET_CAPTURE_IMAGE_RSP);
}

void vapp_widget_handle_capture_image(void *param)
{
    widget_capture_image_req_struct *req = (widget_capture_image_req_struct *)param;
#ifdef __MMI_CAMCORDER__
    /* Get home app and its group id */
    VfxApp *homeApp = (VfxApp *) VfxAppLauncher::findApp(VAPP_LAUNCHER,
        VFX_OBJ_CLASS_INFO(VappLauncherApp), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG,
        0);

    /* Check if active group is home app or not */
    if (homeApp->getGroupId() != mmi_frm_group_get_active_id())
    {
        /* Find widget delegator app and check it exist or not */
        if (!VfxAppLauncher::findApp(VAPP_WIDGET_DELEGATOR,
            VFX_OBJ_CLASS_INFO(VappWidgetView),
            VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0))
        {
            send_capture_image_response(req->user_data, WIDGET_API_CAMERA_CAPTURE_ERROR, NULL);
            return;
        }
    }

    /* Launch widget delegator application */
    VfxAppLauncher::launch(VAPP_WIDGET_CUI, VFX_OBJ_CLASS_INFO(VappWidgetCameraAdp),
                        GRP_ID_ROOT,
                        req,
                        sizeof(widget_capture_image_req_struct));
#else
    send_capture_image_response(req->user_data, WIDGET_API_CAMERA_CAPTURE_ERROR, NULL);
    return;
#endif
}

#ifdef __MMI_CAMCORDER__


// VappWidgetCameraAdp Implementation
VFX_IMPLEMENT_CLASS("VappWidgetCameraAdp", VappWidgetCameraAdp, VfxApp);

VappWidgetCameraAdp::VappWidgetCameraAdp():
  m_data(NULL)
{
}

void VappWidgetCameraAdp::onRun(void * args, VfxU32 argSize)
{
    // Call VfxApp's onRun
    VfxApp::onRun(args, argSize);

    m_data = ((widget_capture_image_req_struct *)args)->user_data;

    if (vcui_slim_camera_launchable_check()== VCUI_CAMCO_ERR_NONE)
    {
        vcui_camco_param_struct param;
        vcui_slim_camera_struct_init(&param);

        mmi_id cui_id = vcui_slim_camera_create(getGroupId(), &param);

        if (cui_id != GRP_ID_INVALID)
        {
            vcui_slim_camera_run(cui_id);
            return;
        }
    }

    send_capture_image_response(m_data, WIDGET_API_CAMERA_CAPTURE_ERROR, NULL);
    m_data = NULL;
    VfxApp::exit();
}


void VappWidgetCameraAdp::onDeinit()
{
    if (m_data)
    {
        send_capture_image_response(m_data, WIDGET_API_USER_CANCELLED, NULL);
    }
    VfxApp::onDeinit();
}


mmi_ret VappWidgetCameraAdp::onProc(mmi_event_struct * e)
{
    switch(e->evt_id)
    {
        case VCUI_CAMCO_EVENT_RESULT_SUCCESS:
        case VCUI_CAMCO_EVENT_RESULT_FAILED:
        {
            vcui_camco_event_struct *event = (vcui_camco_event_struct*)e;

            if (event->errCode == VCUI_CAMCO_ERR_NONE)
            {
                if (event->filePath != NULL)
                {
                    send_capture_image_response(m_data, WIDGET_API_NO_ERROR, (kal_uint8 *)event->filePath);
                }
                else
                {
                    send_capture_image_response(m_data, WIDGET_API_USER_CANCELLED, NULL);
                }
            }
            else
            {
                send_capture_image_response(m_data, WIDGET_API_CAMERA_CAPTURE_ERROR, NULL);
            }
            m_data = NULL;
            vcui_slim_camera_close(((mmi_group_event_struct*) e)->sender_id);
            VfxApp::exit();
        }
        break;
        case EVT_ID_ASM_FREE_REQ:
            send_capture_image_response(m_data, WIDGET_API_USER_CANCELLED, NULL);
            VfxApp::exit();
	        break;
        default:
            break;
    }

    return VfxApp::onProc(e);
}

#endif
