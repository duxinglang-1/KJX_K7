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
 *  vapp_prov_msg.res
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  Ying Fang (mtk80514)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 27 2010 ying.fang
 * [MAUI_02645448] [Cosmos] Check in Cosmos to MAUI
 * .
 *
 * 12 23 2010 ying.fang
 * [MAUI_02645448] [Cosmos] Check in Cosmos to MAUI
 * .
 *
 * 12 21 2010 ying.fang
 * [MAUI_02644803] [Daily build] Fix  MAUI build error for HEPHAESTUS68_DEMO_umts
 * Check FTO to IT Branch.
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>

#if defined(__MMI_PROV_MESSAGE_SUPPORT__) && defined(__MMI_PROV_IN_UM__)
<APP id="VAPP_PROV_HEAP" name="STR_ID_VAPP_PROV_HEAP" type="venus">

    <MEMORY heap= "0" vrt_mem_factor = "0" />
    <STRING id="STR_ID_VAPP_PROV_HEAP"/>
    
</APP>

<APP id="VAPP_PROV_EXTRA_BASE" name="STR_ID_VAPP_PROV_EXTRA_BASE" type="venus">

    <MEMORY extra_base="0" vrt_mem_factor = "0" />
    <STRING id="STR_ID_VAPP_PROV_EXTRA_BASE"/>
    
</APP>
<APP id="VAPP_PROV_FG" name="STR_ID_VAPP_PROV_FG" type="venus">

    <MEMORY fg="0" vrt_mem_factor = "0" />
    <STRING id="STR_ID_VAPP_PROV_FG"/>
    
</APP>
<APP id = "VAPP_PROV_MSG" name = "STR_VAPP_PROV_MSG" type="venus">

     <!---------------------------------------- String Resource Area ----------------------------------------------->
     
     <STRING id = "STR_ID_VAPP_PROV_MSG_SIZE">Size</STRING>
     <STRING id = "STR_ID_VAPP_PROV_MSG_INSTALL">Install</STRING>
     <STRING id = "STR_ID_VAPP_PROV_MSG_CNFIG">Configuration</STRING>
     <STRING id = "STR_ID_VAPP_PROV_MSG_DELETE_FAIL">Delete failure!</STRING>
     <STRING id = "STR_ID_VAPP_PROV_MSG_NO_NUMBER">No number</STRING>
     <STRING id = "STR_ID_VAPP_PROV_MSG_SIM2">SIM2</STRING>
     <STRING id = "STR_ID_VAPP_PROV_MSG_SIM1">SIM1</STRING>
     <STRING id = "STR_ID_VAPP_PROV_MSG_SIM1_NAME">SIM1 settings message</STRING>
     <STRING id = "STR_ID_VAPP_PROV_MSG_SIM2_NAME">SIM2 settings message</STRING>
     <STRING id = "STR_ID_VAPP_PROV_MSG_SIM3_NAME">SIM3 settings message</STRING>
     <STRING id = "STR_ID_VAPP_PROV_MSG_SIM4_NAME">SIM4 settings message</STRING>
     <STRING id = "STR_ID_VAPP_PROV_MSG_SIM_NAME">SIM settings message</STRING>
     <STRING id = "STR_ID_VAPP_PROV_MSG_LIST_ITEM_NAME">Configuration message</STRING>
     <STRING id = "STR_ID_VAPP_PROV_MSG_DELETE_QUERY">Delete the message?</STRING>
     <STRING id = "STR_ID_VAPP_PROV_INSUFFICIENT_MEMORY">Not enough memory</STRING>
     
     <!---------------------------------------- Register event handler --------------------------------------------->
     <IMAGE id="IMG_ID_VAPP_PROV_MSG_INDICTOR_ICON">RES_IMG_ROOT"\\\\Message\\\\ListIcon\\\\Provisioning.png"</IMAGE>

     <THEME>
         <COLOR id = "CLR_ID_VAPP_PROV_MSG_CP_INSTALL_BTN_FONT_COLOR" desc = "provisioning message component install button font color"/>
         <COLOR id = "CLR_ID_VAPP_PROV_MSG_PROV_TEXT_FONT_COLOR" desc = "the text of provisioning message font color"/>
         <COLOR id = "CLR_ID_VAPP_PROV_MSG_PROV_SIZE_FONT_COLOR" desc = "the size of provisioning message font color"/>
         <COLOR id = "CLR_ID_VAPP_PROV_MSG_BG_FONT_COLOR" desc = "the size of provisioning BG"/>
         <COLOR id = "CLR_ID_VAPP_PROV_MSG_VIEW_FONT_COLOR" desc = "the size of provisioning viewer color"/>
     </THEME>

     <!---------------------------------------- Register event handler --------------------------------------------->
     <RECEIVER id="EVT_ID_SRV_PROVBOX_NOTIFY_IND" proc="vapp_prov_um_event_hdlr_proc"/>
</APP>

#endif /* __MMI_PROV_MSG_SUPPORT__ */
