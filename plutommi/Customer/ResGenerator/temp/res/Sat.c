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
 * Sat.res
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
 * Mingliang Xu (mtk80021)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 25 2012 yier.liao
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * .
 *
 * 04 10 2012 xiaolin.chen
 * [MAUI_03165048] [SAT] Move timer ID to app resource
 * .
 *
 * 11 18 2011 xiaolin.chen
 * [MAUI_03011995] [STK]UE displays unexpected text "Done" after rejecting to send USSD
 * .
 *
 * 08 26 2011 xiaolin.chen
 * [MAUI_03013554] [In-house FTA][TP][SIM/SAT][Victor56_V1.0] 27.22.4.9.2 SELECT ITEM SEQ 2.1
 * .
 *
 * 01 17 2011 mingliang.xu
 * [MAUI_02861791] [LION52_BT IOT] Enter the STK item, MS will always display the "Please wait" message
 * .
 *
 * 12 03 2010 mingliang.xu
 * [MAUI_02639002] [New feature] SAT app/srv split check in
 * .
 *
 * 11 25 2010 mingliang.xu
 * [MAUI_02639002] [New feature] SAT app/srv split check in
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_SAT">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------------------------Event Resource Area----------------------------------------------------->


    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_SAT_MENU_TITLE"/>

    <STRING id="STR_ID_SAT_PLAY_TONE"/>
    <STRING id="STR_ID_SAT_SEND_SMS"/>
    <STRING id="STR_ID_SAT_SEND_SS"/>
    <STRING id="STR_ID_SAT_SEND_USSD"/>
    <STRING id="STR_ID_SAT_SETUP_CALL_CONFIRM"/>
#ifdef __SATCB__    
    <STRING id="STR_ID_SAT_RUN_AT_COMMAND"/>
#endif  
    <STRING id="STR_ID_SAT_SEND_DTMF"/>
#ifdef BROWSER_SUPPORT     
    <STRING id="STR_ID_SAT_LAUNCH_BROWSER_CONFIRM"/>
#endif
#ifdef __SATCE__
    <STRING id="STR_ID_SAT_OPEN_CHANNEL_CONFIRM"/>
    <STRING id="STR_ID_SAT_CLOSE_CHANNEL"/>
    <STRING id="STR_ID_SAT_SEND_DATA"/>
    <STRING id="STR_ID_SAT_RECV_DATA"/>
#endif

    <STRING id="STR_ID_SAT_NEXT_ACTION_SEND_SMS"/>
    <STRING id="STR_ID_SAT_NEXT_ACTION_SETUP_CALL"/>
    <STRING id="STR_ID_SAT_NEXT_ACTION_LAUNCH_BROWSER"/>
    <STRING id="STR_ID_SAT_NEXT_ACTION_PROVIDE_LOCAL_INFORMATION"/>
    <STRING id="STR_ID_SAT_NEXT_ACTION_PROVIDE_LOCAL_INFO"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    
    /* For the detail of scope="XML" please check user manual */


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */

    <!--Menu Tree Area-->

    /* Type Support:OPTION, APP_MAIN, APP_SUB, default value is ORIGINAL */
    /* default="TRUE" means this item is active item when use CSK.       */
    /* type="SEPARATOR" means that CUI will show a separator here        */


    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SENDER id="EVT_ID_SRV_SAT_PROACTIVE_SIM" hfile="SatSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_SAT_SETUP_MENU" hfile="SatSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_SAT_SETUP_IDLE_DISPLAY" hfile="SatSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_SAT_SIM_REFRESH" hfile="SatSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_SAT_SESSION_END" hfile="SatSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_SAT_SIM_CTRL_INFO" hfile="SatSrvGprot.h"/>
    
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_UNAVAILABLE" proc="srv_sat_sim_unavailable_hdlr"/>

    <TIMER id="SAT_MESSAGE_WAIT_TIMER"/>
    <TIMER id="SAT_PLAY_TONE_TIMER"/>

</APP>

