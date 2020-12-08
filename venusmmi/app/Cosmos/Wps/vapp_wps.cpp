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
*  vapp_wps.cpp
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  To show security related UI for WPS on cosmos
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifdef __COSMOS_MMI_PACKAGE__
#ifdef WAP_SEC_SUPPORT

#include "stack_common.h"
#include "stack_msgs.h"
#include "vapp_wps.h"
#include "vcp_global_popup.h"
#include "wps_struct.h"
#include "vapp_nmgr_gprot.h"


static wps_show_confirm_dialog_ind_struct ind;


mmi_ret vapp_wps_on_bootup(mmi_event_struct *evt)
{
    vapp_wps::init();
    return MMI_RET_OK;
}

/* Register callbacks */
void vapp_wps::init(void)
{
    SetProtocolEventHandler(vapp_wps::wps_ind_hndlr, MSG_ID_WPS_SEC_SHOW_CONFIRM_DIALOG_IND);
}


void vapp_wps::wps_ind_hndlr(void* msg)
{
    vapp_wps *app;
    //VFX_SYS_NEW_EX(app, vapp_wps, (msg));
    //app->show_security_dialog();
    memcpy(&ind, msg, sizeof(wps_show_confirm_dialog_ind_struct));
    show_security_dialog();
}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* recieve msg from WPS*/ /* static */
void vapp_wps::show_security_dialog(void)
{
    VcpPopupTypeEnum popup_type;
    switch(ind.dialog_type)
    {
    case WPS_DLG_INFO:
        {
            popup_type = VCP_POPUP_TYPE_SUCCESS;
        }
        break;
    case WPS_DLG_ALERT:
        {
            popup_type = VCP_POPUP_TYPE_QUESTION;
        }
        break;
    default:
        {
            popup_type = VCP_POPUP_TYPE_FAILURE;
        }
        break;
    }

    switch(ind.buttons)
    {
    case WPS_DLG_BUTTON_YESNO:
        {
            vapp_nmgr_global_popup_show_confirm_two_button_id(
                MMI_SCENARIO_ID_HIGH_SCRN,
                popup_type, 
                ind.text_id, 
                STR_GLOBAL_YES, 
                STR_GLOBAL_NO,
                VCP_POPUP_BUTTON_TYPE_NORMAL,
                VCP_POPUP_BUTTON_TYPE_NORMAL,
                vapp_wps::popup_callback,
                NULL);

        }
        break;
    case WPS_DLG_BUTTON_OK:
    default:
        {
            vapp_nmgr_global_popup_show_confirm_one_button_id(
                MMI_SCENARIO_ID_HIGH_SCRN,
                popup_type, 
                ind.text_id, 
                STR_GLOBAL_OK, 
                VCP_POPUP_BUTTON_TYPE_NORMAL,
                vapp_wps::popup_callback,
                NULL);

        }
        break;
    }
}

/* popup callback */ /* static */
void vapp_wps::popup_callback(VfxId id, void *userData)
{
    //vapp_wps* temp = (vapp_wps*)userData;
    switch(id)
    {
    case VCP_CONFIRM_POPUP_BUTTON_USER_1:
        send_rsp(WPS_DLG_OK);
        break;
    case VCP_CONFIRM_POPUP_BUTTON_USER_2:
    case VCP_POPUP_BUTTON_NO_PRESSED:
        send_rsp(WPS_DLG_CANCEL);
        break;
    default:
        break;
    }
    //VFX_SYS_DELETE(temp);
}

/* send msg to wps */
void vapp_wps::send_rsp(VfxU32 result)
{
    wps_show_confirm_dialog_res_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wps_show_confirm_dialog_res_struct*) OslConstructDataPtr(sizeof(wps_show_confirm_dialog_res_struct));

    myMsgPtr->request_id = ind.request_id;
    myMsgPtr->result = result;

    mmi_frm_send_ilm(MOD_WPS, MSG_ID_WPS_SEC_SHOW_CONFIRM_DIALOG_RES, (oslParaType*)myMsgPtr, NULL);

}

#endif /* __COSMOS_MMI_PACKAGE__ */
#endif /* __VAPP_WPS__ */
