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
 * MsgViewerCui.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_include.h"

#include "MsgViewerCui.h"
#include "MsgViewerCuiGProt.h"


cui_msg_viewer_cntx_struct g_cui_msg_viewer;
cui_msg_viewer_cntx_struct *g_cui_msg_viewer_p = &g_cui_msg_viewer;


mmi_id cui_msg_viewer_create(mmi_id parent_grp_id, U32 msg_id, srv_um_msg_enum msg_type, U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_msg_viewer_inst_struct *inst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Initialize the instance */
    inst = cui_msg_viewer_create_instance();
    inst->curr_msg_id = msg_id;
    inst->curr_msg_type = msg_type;
    inst->parent_grp_id = parent_grp_id;
    inst->status = CUI_MSG_VIEWER_STATUS_INIT;
    inst->type = CUI_MSG_VIEWER_TYPE_NORMAL;

    /* create a new group */
    inst->group_id = mmi_frm_group_create(
                            inst->parent_grp_id, 
                            GRP_ID_AUTO_GEN, 
                            cui_msg_viewer_grp_proc, 
                            (void *) inst);
    inst->scrn_id = CUI_MSG_VIEWER_BASE;

        return inst->group_id;
}

void cui_msg_viewer_set_widget_csk_invoke(mmi_id group_id)
{
    cui_msg_viewer_inst_struct *inst = cui_msg_viewer_get_instance(group_id);
    if (inst->curr_msg_type == SRV_UM_MSG_MMS)
    {
        inst->type = CUI_MSG_VIEWER_TYPE_CSK_KEY;
    }
}

void cui_msg_viewer_set_widget_tap_invoke(mmi_id group_id)
{
    cui_msg_viewer_inst_struct *inst = cui_msg_viewer_get_instance(group_id);
    if (inst->curr_msg_type == SRV_UM_MSG_MMS)
    {
        inst->type = CUI_MSG_VIEWER_TYPE_INTUITIVE_CMD;
    }
}

void cui_msg_viewer_run(mmi_id grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_msg_viewer_inst_struct *inst = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst = cui_msg_viewer_get_instance(grp_id);
    CUI_MSG_VIEWER_CHECK_INST_VALID(inst);

    /* Create a group */
    cui_msg_viewer_schedule(inst);
}


void cui_msg_viewer_close(mmi_id grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Delete the screen group */
    mmi_frm_group_close(grp_id);
}


void cui_msg_viewer_set_style(mmi_id grp_id, cui_msg_viewer_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Not support yet */
    MMI_ASSERT(0);
}


void cui_msg_viewer_set_msg_list(mmi_id grp_id, srv_um_msg_node_struct *msg_list, U16 msg_list_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Not support yet */
    MMI_ASSERT(0);
}


void cui_msg_viewer_rel_msg_list(mmi_id grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Not support yet */
    MMI_ASSERT(0);
}


void cui_msg_viewer_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_cui_msg_viewer_p, 0, sizeof(cui_msg_viewer_cntx_struct));
}


cui_msg_viewer_inst_struct *cui_msg_viewer_create_instance(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    cui_msg_viewer_inst_struct *inst = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0 ; i < CUI_MSG_VIEWER_MAX_INSTANCE ; i++)
    {
        /* find the empty slot */
        if (GRP_ID_INVALID == g_cui_msg_viewer_p->inst_table[i].group_id)
        {
            inst = &(g_cui_msg_viewer_p->inst_table[i]);
            break;
        }
    }

    /* No empty slot */
    MMI_ASSERT(i < CUI_MSG_VIEWER_MAX_INSTANCE);

    return inst;
}


void cui_msg_viewer_rel_instance(cui_msg_viewer_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CUI_MSG_VIEWER_CHECK_INST_VALID(inst);

    memset(inst, 0, sizeof(cui_msg_viewer_inst_struct));
}


cui_msg_viewer_inst_struct *cui_msg_viewer_get_instance(mmi_id grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    cui_msg_viewer_inst_struct *inst = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(GRP_ID_INVALID != grp_id);

    for (i = 0 ; i < CUI_MSG_VIEWER_MAX_INSTANCE ; i++)
    {
        if (grp_id == g_cui_msg_viewer_p->inst_table[i].group_id)
        {
            inst = &(g_cui_msg_viewer_p->inst_table[i]);
            break;
        }
    }

    return inst;
}


void cui_msg_viewer_schedule(cui_msg_viewer_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (inst->status)
    {
        case CUI_MSG_VIEWER_STATUS_INIT:
            cui_msg_viewer_schedule_init(inst);
            break;

        case CUI_MSG_VIEWER_STATUS_READY:
            cui_msg_viewer_schedule_ready(inst);
            break;

        case CUI_MSG_VIEWER_STATUS_NO_MSG_LIST:
            MMI_ASSERT(0);
            break;

        case CUI_MSG_VIEWER_STATUS_DEINIT:
            cui_msg_viewer_schedule_deinit(inst);
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
}


mmi_ret cui_msg_viewer_grp_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return ret;
}


void cui_msg_viewer_schedule_init(cui_msg_viewer_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CUI_MSG_VIEWER_CHECK_INST_VALID(inst);
    MMI_ASSERT(inst->status == CUI_MSG_VIEWER_STATUS_INIT);

    mmi_frm_group_enter(inst->group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    /* Entry a marker of cui message viewer */
    mmi_frm_scrn_first_enter(
        inst->group_id, 
        inst->scrn_id, 
        (FuncPtr) cui_msg_viewer_schedule_init_entry, 
        (void *)inst);
}


void cui_msg_viewer_schedule_init_entry(mmi_scrn_essential_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_msg_viewer_inst_struct *inst;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst = (cui_msg_viewer_inst_struct *)arg->user_data;
    CUI_MSG_VIEWER_CHECK_INST_VALID(inst);

    mmi_frm_scrn_enter(
        inst->group_id, 
        inst->scrn_id, 
        NULL, 
        (FuncPtr) cui_msg_viewer_entry, 
        MMI_FRM_SCRN_GROUP);
#ifdef __MMI_VUI_WIDGET_KEY_MESSAGE__
    mmi_frm_scrn_clear_attribute(inst->group_id, inst->scrn_id, MMI_SCRN_ATTRIB_ADD_HISTORY);
#endif
    mmi_frm_scrn_set_leave_proc(inst->group_id, inst->scrn_id, cui_msg_viewer_leave_proc);
    /* check the status of this instance */
    switch (inst->type)
    {
        case CUI_MSG_VIEWER_TYPE_NORMAL:
        case CUI_MSG_VIEWER_TYPE_CSK_KEY:
        case CUI_MSG_VIEWER_TYPE_INTUITIVE_CMD:
            /* set as ready type */
            inst->status = CUI_MSG_VIEWER_STATUS_READY;
            cui_msg_viewer_schedule(inst);
            break;

        case CUI_MSG_VIEWER_TYPE_ITERATOR:
            MMI_ASSERT(0);
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
}


void cui_msg_viewer_schedule_ready(cui_msg_viewer_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CUI_MSG_VIEWER_CHECK_INST_VALID(inst);
    MMI_ASSERT(inst->status == CUI_MSG_VIEWER_STATUS_READY);

    /* Launch the corresponding viewer */
    cui_msg_viewer_adp_launch_viewer_ptr(
                        inst->curr_msg_type, 
                        inst->group_id, 
                        inst->curr_msg_id, 
                        (void *)inst, 
                        inst->type);
    
#ifdef __MMI_VUI_WIDGET_KEY_MESSAGE__
    if((inst->group_id == mmi_frm_group_get_active_id())
            && (CUI_MSG_VIEWER_BASE == mmi_frm_scrn_get_active_id()))
    {
        /* refresh to destory current dummy screen from  cui_msg_viewer_schedule_init_entry*/
        mmi_frm_display_dummy_screen();
        mmi_frm_scrn_close_active_id();
    }
#endif
}


void cui_msg_viewer_schedule_deinit(cui_msg_viewer_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_msg_viewer_event_struct evt;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CUI_MSG_VIEWER_CHECK_INST_VALID(inst);
    MMI_ASSERT(inst->status == CUI_MSG_VIEWER_STATUS_DEINIT);

    MMI_FRM_INIT_GROUP_EVENT(&evt, sizeof(cui_msg_viewer_event_struct), inst->group_id);
    evt.evt_id = EVT_ID_CUI_MSG_VIEWER_CLOSE;
    mmi_frm_group_post_to_caller(inst->group_id, (mmi_group_event_struct *)&evt);
}


void cui_msg_viewer_entry(mmi_scrn_essential_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_msg_viewer_inst_struct *inst;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst = (cui_msg_viewer_inst_struct *)arg->user_data;
    CUI_MSG_VIEWER_CHECK_INST_VALID(inst);

    /* FW usage */
    mmi_frm_scrn_enter(
        inst->group_id, 
        inst->scrn_id, 
        NULL, 
        (FuncPtr) cui_msg_viewer_entry, 
        MMI_FRM_SCRN_GROUP);

    /* Hit the marker, delete the group */
    inst->status = CUI_MSG_VIEWER_STATUS_DEINIT;
    cui_msg_viewer_schedule(inst);
}


mmi_ret cui_msg_viewer_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret result;
    cui_msg_viewer_inst_struct *inst = NULL;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = MMI_RET_OK;

    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
            inst = evt->user_data;
            CUI_MSG_VIEWER_CHECK_INST_VALID(inst);

            /* Delete the instance context */
            cui_msg_viewer_rel_instance(inst);
            break;
        }
        default:
        {
            break;
        }
    }

    return result;
}
