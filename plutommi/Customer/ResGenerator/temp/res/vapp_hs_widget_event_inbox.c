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
 *  vapp_hs_widget_event_inbox.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the resource ID for the "Event Inbox" widget.
 *
 * Author:
 * -------
 *  Cheng-Hung Ko (mtk01585)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * Jun 22 2010 mtk01585
 * [MAUI_02567833] [Idle] Revise codes by using XML resources
 * Check-in XML resources.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "CustResDef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_HOMESCREEN_WG_EVENT_INBOX">

    <!----- Include Area ------------------------------------------------------>
    <INCLUDE file="GlobalResDef.h"/>


#if defined(__MMI_VUI_HOMESCREEN_EVENT_INBOX__)

    <!----- String Resource Area ---------------------------------------------->
    <STRING id="VAPP_HS_STR_WG_EVENT_INBOX"/>


    <!----- Image Resource Area ----------------------------------------------->
    #define ROOT_PATH               CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\"
    #define WIDGET_PATH             ROOT_PATH"Widget\\\\"
    #define EVENT_INBOX_WIDGET_PATH WIDGET_PATH"EventInbox\\\\"

    <IMAGE id="VAPP_HS_IMG_WG_ICON_EVENT_INBOX">WIDGET_PATH"Widgeticon_EventInbox.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_EVENT_INBOX_BG">EVENT_INBOX_WIDGET_PATH"EventInbox_BG.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_EVENT_INBOX_CALL">EVENT_INBOX_WIDGET_PATH"EventInbox_Icon_Call.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_EVENT_INBOX_CALL_DOWN">EVENT_INBOX_WIDGET_PATH"EventInbox_Call_Down.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_EVENT_INBOX_SMS">EVENT_INBOX_WIDGET_PATH"EventInbox_Icon_SMS.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_EVENT_INBOX_SMS_DOWN">EVENT_INBOX_WIDGET_PATH"EventInbox_SMS_Down.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_EVENT_INBOX_MMS">EVENT_INBOX_WIDGET_PATH"EventInbox_Icon_MMS.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_EVENT_INBOX_MMS_DOWN">EVENT_INBOX_WIDGET_PATH"EventInbox_MMS_Down.png"</IMAGE>


    <!----- Screen Resource Area ---------------------------------------------->


    <!----- Menu Resource Area ------------------------------------------------>
    

#endif /* defined(__MMI_VUI_HOMESCREEN_EVENT_INBOX__) */

</APP>

