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
 *  ServiceMsgCuiMain.c
 *
 * Project:
 * -------- 
 *  Service Msg Cui
 *
 * Description:
 * ------------
 *  This file contains Service message CUI.
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

/***************************************************************************** 
 * Include
 *****************************************************************************/

//#include "MMI_include.h"
#ifndef MMI_SERVICEMSGCUIMAIN_C
#define MMI_SERVICEMSGCUIMAIN_C
#include "WAPPushGprots.h"
#include "WAPPushUIProts.h"
    #include "MMIDataType.h"
    #include "GlobalResDef.h"
    #include "WAPPushUITypes.h"
    #include "mmi_frm_events_gprot.h"
    #include "WAPPushResDef.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "kal_public_api.h"
    #include "DebugInitDef_Int.h"
    #include "kal_general_types.h"
    #include "MMI_features.h"

#ifdef __WAP_PUSH_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  cui_service_msg_setting_create
 * DESCRIPTION
 *  To create select bookmark group
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_id  : Returns Group Id
 *****************************************************************************/
mmi_id cui_service_msg_setting_create (mmi_id parent_gid)
{
    if(parent_gid != GRP_ID_INVALID)
    {
        if(g_push_cntxt->service_msg_setting_cid != GRP_ID_INVALID)
        {
            mmi_wap_push_event_based_display_popup(MMI_EVENT_FAILURE, STR_GLOBAL_NOT_AVAILABLE);
            return GRP_ID_INVALID;
        }
        g_push_cntxt->service_msg_setting_cid = mmi_frm_group_create(parent_gid, GRP_ID_BRW_PUSH_SETTING, mmi_wap_push_service_msg_setting_proc, NULL);
        g_push_cntxt->scr_grp_id = GRP_ID_BRW_PUSH_SETTING;
        return  g_push_cntxt->service_msg_setting_cid;
    }
    else
    {
        return GRP_ID_INVALID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_service_msg_setting_create
 * DESCRIPTION
 *  To enter into select service message setting group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_service_msg_setting_run (mmi_id cui_gid)
{
    MMI_ASSERT (g_push_cntxt->service_msg_setting_cid == cui_gid);
    mmi_frm_group_enter(cui_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_wap_push_setting_entry_main_menu();
}

/*****************************************************************************
 * FUNCTION
 *  cui_service_msg_setting_close
 * DESCRIPTION
 *  To close select bookmark group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_service_msg_setting_close (mmi_id cui_gid)
{
    mmi_frm_group_close(cui_gid);
    g_push_cntxt->service_msg_setting_cid = GRP_ID_INVALID;
    g_push_cntxt->scr_grp_id = GRP_ID_INVALID;
}


#ifdef __MMI_PUSH_IN_MSG__
/*****************************************************************************
 * FUNCTION
 *  cui_service_msg_menu_create
 * DESCRIPTION
 *  To create select bookmark group
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_id  : Returns Group Id
 *****************************************************************************/
mmi_id cui_service_msg_menu_create (mmi_id parent_gid)
{
    if(parent_gid != GRP_ID_INVALID)
    {
        if(g_push_cntxt->service_msg_cid != GRP_ID_INVALID)
        {
            mmi_wap_push_event_based_display_popup(MMI_EVENT_FAILURE, STR_GLOBAL_NOT_AVAILABLE);
            return GRP_ID_INVALID;
        }
        g_push_cntxt->service_msg_cid = mmi_frm_group_create(parent_gid, GRP_ID_WAP_PUSH_SERVICE_MSG_MAIN, mmi_wap_push_service_msg_main_manu_proc, NULL);
        g_push_cntxt->scr_grp_id = GRP_ID_WAP_PUSH_SERVICE_MSG_MAIN;
        return  g_push_cntxt->service_msg_cid;
    }
    else
    {
        return GRP_ID_INVALID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_service_msg_menu_run
 * DESCRIPTION
 *  To enter into select service message setting group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_service_msg_menu_run (mmi_id cui_gid)
{
    MMI_ASSERT (g_push_cntxt->service_msg_cid == cui_gid);
    mmi_frm_group_enter(cui_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_wap_push_entry_service_message();
}

/*****************************************************************************
 * FUNCTION
 *  cui_service_msg_menu_close
 * DESCRIPTION
 *  To close select bookmark group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_service_msg_menu_close (mmi_id cui_gid)
{
    mmi_frm_group_close(cui_gid);
    g_push_cntxt->service_msg_cid = GRP_ID_INVALID;
    g_push_cntxt->scr_grp_id = GRP_ID_INVALID;
}
#endif /* __MMI_PUSH_IN_MSG__ */

#endif /* __WAP_PUSH_SUPPORT__ */
#endif /* MMI_SERVICEMSGCUIMAIN_C */
