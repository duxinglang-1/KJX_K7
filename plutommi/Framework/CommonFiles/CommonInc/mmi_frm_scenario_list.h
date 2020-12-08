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
 * mmi_frm_scenario_list.h
 *
 * Project:
 * --------
 *   MAUI
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
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef MMI_FRM_SCENARIO_LIST_H
#define MMI_FRM_SCENARIO_LIST_H

#include "mmi_frm_scenario_gprot.h"
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
/* Scenario attribute structure */
typedef struct
{
    mmi_scenario_id scenario_id;
    mmi_scen_attr_prio_enum notify_priority;
    S16 ref_cnt;
} mmi_app_scenario_attribute_struct;

typedef struct _mmi_scenario_list_node
{
    mmi_app_scenario_attribute_struct scenario_info;
    struct _mmi_scenario_list_node *next;
} mmi_scenario_list_node;

typedef mmi_scenario_list_node  *mmi_scenario_list_node_p;
typedef mmi_scenario_list_node_p mmi_scenario_list;
typedef mmi_scenario_list_node_p mmi_scenario_position;
typedef mmi_app_scenario_attribute_struct mmi_scenario_list_elem_type;

/***************************************************************************** 
 * Extern Global Function
 *****************************************************************************/
/* Create & destroy */
extern void scenario_list_create(void);
extern void scenario_list_destroy(void);
/* Search */
extern mmi_scenario_position scenario_list_find(mmi_scenario_id scen_id);
extern mmi_scenario_position scenario_list_find_previous(mmi_scenario_id scen_id);
extern mmi_scenario_position scenario_list_find_next(mmi_scenario_id scen_id);
/* Delete & insert */
extern void scenario_list_delete(mmi_scenario_id scen_id);
extern void scenario_list_insert(mmi_scenario_list_elem_type scen, mmi_scenario_position position);
extern void scenario_list_insert_after(mmi_scenario_list_elem_type scen, mmi_scenario_id id);
/* Query */
extern MMI_BOOL scenario_list_is_empty(void);
extern MMI_BOOL scenario_list_is_last(mmi_scenario_position position);
extern U32 scenario_list_get_length(void);
extern mmi_scenario_position scenario_list_get_header(void);
extern mmi_scenario_position scenario_list_get_first(void);
extern mmi_scenario_position scenario_list_get_latest(void);
extern mmi_scenario_position scenario_list_advance(mmi_scenario_position position);
extern mmi_scenario_list_elem_type scenario_list_retrieve(mmi_scenario_position position);

#ifdef MMI_NOTI_MGR_UT
extern MMI_BOOL mmi_scenario_list_ut(void);
#endif

#endif /* MMI_FRM_SCENARIO_LIST_H */

