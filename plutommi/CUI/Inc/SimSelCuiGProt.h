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
 *  SimSelCUIGProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SIM selector CUI exported APIs.
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _SIM_SEL_CUI_GPROT_H_
#define _SIM_SEL_CUI_GPROT_H_

#if (MMI_MAX_SIM_NUM >= 3)

/****************************************************************************
* Include Files                                                                
*****************************************************************************/

/****************************************************************************
* Define
*****************************************************************************/

/* SIM selector result enum */
typedef enum
{
    CUI_SIM_SEL_OK, /* User has selected any sim*/
    CUI_SIM_SEL_ABORT, /* User doesn't select any sim, and go back */
    CUI_SIM_SEL_END_OF_ENUM /* end of the enum */
} cui_sim_sel_result_enum;

/* <GROUP SIM selector Event>
 *  Here are events that "SIM selector CUI" will notify to caller.
 */
typedef enum
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_CUI_SIM_SEL_BEGIN = CUI_SIM_SEL_BASE,
    /* DOM-NOT_FOR_SDK-END */
    EVT_ID_CUI_SIM_SEL_RESULT, /* cui_sim_sel_result_event_struct */
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_CUI_SIM_SEL_TOTAL
    /* DOM-NOT_FOR_SDK-END */
} cui_sim_sel_event_enum;

/* <GROUP SIM select Event>
 * event structure of EVT_ID_CUI_SIM_SEL_RESULT  */
typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
    cui_sim_sel_result_enum result; /* cui_sim_sel_result_enum */
    mmi_sim_enum sim_id; /* The selected sim id, if result is CUI_SIM_SEL_ABORT, it will be MMI_SIM_NONE */
    void* parent_data;
} cui_sim_sel_result_event_struct;

/* <GROUP SIM selector>
 * DESCRIPTION
 *  Create an instance of "SIM selector CUI", 
 *  It will display SIMs for user to choose, NO SIM will be indicated if SIM is not inserted
 * 
 * PARAMETERS
 *  caller              : [IN]  group id of caller
 *  sim_id             : [IN]  target SIMs, support bitwise operation
 *                                   ex. MMI_SIM_ALL for all sims
 *                                   ex. (MMI_SIM1 | MMI_SIM4) for SIM 1 & SIM4
 *  parent_data     : [IN] parent data
 * RETURNS
 *  id of the new created CUI
 */
mmi_id cui_sim_sel_create(mmi_id caller, mmi_sim_enum sim_id, void* parent_data);

/* <GROUP SIM selector>
 * DESCRIPTION
 *  Set the property of SIM selector CUI
 *  It will decide the condition to grey some sims or not
 *
 * PARAMETERS
 *  emergency       : [IN]  include emergency situation or not
 * RETURNS
 *  void
 */
void cui_sim_sel_set_mode(MMI_BOOL emergency);


/* <GROUP SIM selector>
 * DESCRIPTION
 *  Set the property of SIM selector CUI
 *  It will set the default highlight sim
 *
 * PARAMETERS
 *  highlight_sim       : [IN]  default highlight sim
 * RETURNS
 *  void
 */
void cui_sim_sel_set_highlight_sim(mmi_sim_enum highlight_sim);


/* <GROUP SIM selector>
 * DESCRIPTION
 *  Run function of "SIM selector CUI".
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
void cui_sim_sel_run(mmi_id cui_id);

/* <GROUP SIM selector>
 * DESCRIPTION
 *  Close function of "SIM selector CUI", 
 *  Caller should be responsible for closing CUI it created.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
void cui_sim_sel_close(mmi_id cui_id);

#endif /* (MMI_MAX_SIM_NUM >= 3) */

#endif /* _SIM_SEL_CUI_GPROT_H_ */

