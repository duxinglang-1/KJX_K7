/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  NwNameSrv.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the resource ID for the network name service.
 *
 * Author:
 * -------
 *  Weilun-Liu (mtk02772)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 05 17 2012 weilun.liu
 * [MAUI_03184297] [FTA] 44.2.9.1.3
 * wrap nitz compile option
 *
 * 05 16 2012 weilun.liu
 * [MAUI_03184297] [FTA] 44.2.9.1.3
 * handle the nitz scenario that operator name changed but plmn id is the same
 *
 * 07 28 2011 wen.qi
 * [MAUI_02986852] [UE]N-center should update SIM operator name to flight mode
 * .
 *
 * 04 12 2011 weilun.liu
 * [MAUI_02912015] [NwName] support SIM hot swap
 * support SIM hot swap
 *
 * 12 10 2010 weilun.liu
 * [MAUI_02847720] [Idle] support SIM refresh event on 10A and MAUI
 * revise sim refresh by event and modify sim compile option.
 *
 * 11 28 2010 weilun.liu
 * [MAUI_02842932] [Idle] Network name service revision and provide api for idle service indication string
 * add string id.
 *
 * 11 28 2010 weilun.liu
 * [MAUI_02842932] [Idle] Network name service revision and provide api for idle service indication string
 * revise network name service to support providing service indication string for specific sim.
 *
 * 11 02 2010 weilun.liu
 * [MAUI_02833901] [Idle] support SIM Refresh
 * .
 *
 * 10 27 2010 yan.liang
 * [MAUI_02634102] [FRM] Framework Callback Manager Revise
 * Fix spelling mistake
 *
 * 09 30 2010 weilun.liu
 * [MAUI_02824995] [Idle, Scrsaver, ScrLocker, Eons, NwName] callback manager register revise
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "CustResDef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="SRV_NW_NAME">

    <!----- Include Area ------------------------------------------------------>


    <!----- String Resource Area ---------------------------------------------->
    <STRING id="STR_ID_NWNAME_LIMITED_SERVICE"/>
    <STRING id="STR_ID_NWNAME_INVALID_SIM"/>
    <STRING id="STR_ID_NWNAME_NO_SERVICE"/>
    <STRING id="STR_ID_NWNAME_INSERT_SIM"/>
    <STRING id="STR_ID_NWNAME_SIM_ACCESS_ERROR"/>
    <STRING id="STR_ID_NWNAME_SIM_BLOCKED"/>
    <STRING id="STR_ID_NWNAME_SIM_DISCONNECTED"/>
    <STRING id="STR_ID_NWNAME_SIM_ACCESS_PROFILE"/>
    <STRING id="STR_ID_NWNAME_SELECT_NETWORK"/>
    <STRING id="STR_ID_NWNAME_FLIGHT_MODE"/>
    <STRING id="STR_ID_NWNAME_SIM_CLOSED"/>
    <STRING id="STR_ID_NWNAME_INVALID_IMEI"/>
    <STRING id="STR_ID_NWNAME_SAME_IMEI"/>
    <STRING id="STR_ID_NWNAME_PREPAREING_SIM_CARD"/>

    <!----- Image Resource Area ----------------------------------------------->


    <!----- Screen Resource Area ---------------------------------------------->


    <!----- Menu Resource Area ------------------------------------------------>


    <!------------------------------------------------------Other Resource---------------------------------------------------------->    
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="srv_nw_name_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED" proc="srv_nw_name_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_NW_INFO_LOCATION_CHANGED" proc="srv_nw_name_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_EONS_UPDATED" proc="srv_nw_name_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SAT_SIM_REFRESH" proc="srv_nw_name_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED" proc="srv_nw_name_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="srv_nw_name_main_evt_hdlr"/>
#if defined(__MMI_NITZ__)
    <RECEIVER id="EVT_ID_NITZ_NW_NAME_UPDATE_NOTIFY" proc="srv_nw_name_main_evt_hdlr"/>
#endif

    /*
     * This event is emitted when the name is updated. For example, the SIM
     * refreshes some related files or the mobile camps-on another network.
     *
     * Structure: srv_nw_name_changed_evt_struct
     */

    <EVENT id="EVT_ID_SRV_NW_NAME_CHANGED" type="SENDER"/>

    /*
     * This event is emitted when sat happens. For example, SIM refresh
     *
     * Structure: srv_nw_name_sat_changed_evt_struct
     */
    <EVENT id="EVT_ID_SRV_NW_NAME_SIM_CHANGED_BY_SAT" type="SENDER"/>
</APP>

