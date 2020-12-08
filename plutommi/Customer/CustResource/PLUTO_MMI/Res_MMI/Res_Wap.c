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
/**
 *	Copyright Notice
 *	?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 *	Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

	FILENAME	: Res_MtkApp.c

  	PURPOSE		: Populate Resource for MtkApp

	REMARKS		: nil

	AUTHOR		: Yogesh

	DATE		: August-15-2003

**************************************************************/

//MTK Add Robin 1001 for saperate MMI feature by project
#include "MMI_features.h"
//MTK End

#include "CustomCfg.h"


#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#include "WapResDef.h"

#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"


void PopulateWapRes(void)
{
#ifdef OBIGO_Q03C
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// wap status icon
#ifdef OBIGO_Q03C_MMS_V01
    /* Hilite hanadler for main setting menu*/
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_MMSV01_AGENT_SETTINGS_EDIT_PROFILE, mmi_mmsv01_highlight_edit_profile);
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_MMSV01_AGENT_SETTINGS_FOR_COMMON_HANDLING, mmi_mmsv01_highlight_common_mms_settings);

#ifdef __MMI_MMS_DUAL_SIM__
    /* For Sim selection*/
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_MMSV01_AGENT_SETTING_SIM1, mmi_mmsv01_highlight_mms_setting_sim1);
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_MMSV01_AGENT_SETTING_SIM2, mmi_mmsv01_highlight_mms_setting_sim2);
#endif

    /* Hilite hanadler for Common settings*/    
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_MMSV01_AGENT_SETTINGS_COMPOSE, mmi_mmsv01_highlight_compose_setings);
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_MMSV01_AGENT_SETTINGS_SENDING, mmi_mmsv01_highlight_sending_setings);
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_MMSV01_AGENT_SETTINGS_RETRIEVAL, mmi_mmsv01_highlight_retrieval_setings);
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_MMSV01_AGENT_SETTINGS_FILTER, mmi_mmsv01_highlight_filter_setings);
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_MMSV01_AGENT_SETTINGS_MEMORY_STATUS, mmi_mmsv01_highlight_memory_status);



#endif
#ifdef __MMI_WAP_DUAL_SIM__
#if defined(OBIGO_Q03C_MMS_V01)
#ifdef SLIM_WAP_MMS    
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_JAVA_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_message_sim1.bmp","java mms icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_JAVA_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Slave\\\\mms_message_sim2.bmp","java mms icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_message_sim1.bmp","unread forward-lock mms icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Slave\\\\mms_message_sim2.bmp","unread forward-lock mms icon");    
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_PRIO_HIGH_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_message_sim1.bmp","unread forward-lock mms icon with high priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_PRIO_HIGH_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Slave\\\\mms_message_sim2.bmp","unread forward-lock mms icon with high priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_PRIO_LOW_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_message_sim1.bmp","unread forward-lock mms icon with high priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_PRIO_LOW_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Slave\\\\mms_message_sim2.bmp","unread forward-lock mms icon with high priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_READ_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_messageread_sim1.bmp","forward-locked mms message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_READ_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Slave\\\\mms_messageread_sim2.bmp","forward-locked mms message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_READ_PRIO_HIGH_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_messageread_sim1.bmp","forward-locked mms message icon with low priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_READ_PRIO_HIGH_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Slave\\\\mms_messageread_sim2.bmp","forward-locked mms message icon with low priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_READ_PRIO_LOW_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_messageread_sim1.bmp","forward-locked mms message icon with low priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_READ_PRIO_LOW_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Slave\\\\mms_messageread_sim2.bmp","forward-locked mms message icon with low priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_PRIO_HIGH_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_message_sim1.bmp","mms high priority unread message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_PRIO_HIGH_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Slave\\\\mms_message_sim2.bmp","mms high priority unread message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_PRIO_LOW_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_message_sim1.bmp","mms low priority unread message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_PRIO_LOW_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Slave\\\\mms_message_sim2.bmp","mms low priority unread message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_READ_PRIO_HIGH_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_messageread_sim1.bmp","mms high priority read message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_READ_PRIO_HIGH_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Slave\\\\mms_messageread_sim2.bmp","mms high priority read message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_READ_PRIO_LOW_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_messageread_sim1.bmp","mms low priority read message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_READ_PRIO_LOW_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Slave\\\\mms_messageread_sim2.bmp","mms low priority read message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_NOTIF_PRIO_HIGH_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\notification\\\\Master\\\\notification_sim1.bmp","mms delivery report message read icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_NOTIF_PRIO_HIGH_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\notification\\\\Slave\\\\notification_sim2.bmp","mms delivery report message read icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_NOTIF_PRIO_LOW_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\notification\\\\Master\\\\notification_sim1.bmp","mms delivery report message read icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_NOTIF_PRIO_LOW_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\notification\\\\Slave\\\\notification_sim2.bmp","mms delivery report message read icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_RR_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_message_sim1.bmp","mms read report message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_RR_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Slave\\\\mms_message_sim2.bmp","mms read report message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_RR_READ_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_messageread_sim1.bmp","mms read report message read icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_RR_READ_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Slave\\\\mms_messageread_sim2.bmp","mms read report message read icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_DR_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_message_sim1.bmp","mms delivery report message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_DR_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Slave\\\\mms_message_sim2.bmp","mms delivery report message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_DR_READ_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_messageread_sim1.bmp","mms delivery report message read icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_DR_READ_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Slave\\\\mms_messageread_sim2.bmp","mms delivery report message read icon");
#else /*SLIM_WAP_MMS*/
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_JAVA_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\JSR\\\\Master\\\\mms_messagejsr_sim1.bmp","java mms icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_JAVA_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\JSR\\\\Slave\\\\mms_messagejsr_sim2.bmp","java mms icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Master\\\\mms_lock_sim1.bmp","unread forward-lock mms icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Slave\\\\mms_lock_sim2.bmp","unread forward-lock mms icon");    
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_PRIO_HIGH_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Master\\\\mms_lock_h_sim1.bmp","unread forward-lock mms icon with high priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_PRIO_HIGH_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Slave\\\\mms_lock_h_sim2.bmp","unread forward-lock mms icon with high priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_PRIO_LOW_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Master\\\\mms_lock_L_sim1.bmp","unread forward-lock mms icon with high priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_PRIO_LOW_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Slave\\\\mms_lock_L_sim2.bmp","unread forward-lock mms icon with high priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_READ_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Master\\\\mms_lock_read_sim1.bmp","forward-locked mms message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_READ_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Slave\\\\mms_lock_read_sim2.bmp","forward-locked mms message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_READ_PRIO_HIGH_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Master\\\\mms_lock_read_h_sim1.bmp","forward-locked mms message icon with low priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_READ_PRIO_HIGH_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Slave\\\\mms_lock_read_h_sim2.bmp","forward-locked mms message icon with low priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_READ_PRIO_LOW_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Master\\\\mms_lock_read_L_sim1.bmp","forward-locked mms message icon with low priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_READ_PRIO_LOW_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Slave\\\\mms_lock_read_L_sim2.bmp","forward-locked mms message icon with low priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_PRIO_HIGH_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_message_h_sim1.bmp","mms high priority unread message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_PRIO_HIGH_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Slave\\\\mms_message_h_sim2.bmp","mms high priority unread message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_PRIO_LOW_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_message_l_sim1.bmp","mms low priority unread message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_PRIO_LOW_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Slave\\\\mms_message_l_sim2.bmp","mms low priority unread message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_READ_PRIO_HIGH_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_messageread_h_sim1.bmp","mms high priority read message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_READ_PRIO_HIGH_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Slave\\\\mms_messageread_h_sim2.bmp","mms high priority read message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_READ_PRIO_LOW_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_messageread_l_sim1.bmp","mms low priority read message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_READ_PRIO_LOW_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Slave\\\\mms_messageread_l_sim2.bmp","mms low priority read message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_NOTIF_PRIO_HIGH_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\notification\\\\Master\\\\notification_h_sim1.bmp","mms delivery report message read icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_NOTIF_PRIO_HIGH_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\notification\\\\Slave\\\\notification_h_sim2.bmp","mms delivery report message read icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_NOTIF_PRIO_LOW_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\notification\\\\Master\\\\notification_sim1.bmp","mms delivery report message read icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_NOTIF_PRIO_LOW_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\notification\\\\Slave\\\\notification_sim2.bmp","mms delivery report message read icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_RR_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\readreport\\\\Master\\\\mms_read_sim1.bmp","mms read report message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_RR_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\readreport\\\\Slave\\\\mms_read_sim2.bmp","mms read report message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_RR_READ_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\readreport\\\\Master\\\\mms_read_read_SIM1.bmp","mms read report message read icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_RR_READ_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\readreport\\\\Slave\\\\mms_read_read_SIM2.bmp","mms read report message read icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_DR_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\deliveryreport\\\\Master\\\\mms_delivery_sim1.bmp","mms delivery report message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_DR_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\deliveryreport\\\\Slave\\\\mms_delivery_sim2.bmp","mms delivery report message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_DR_READ_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\deliveryreport\\\\Master\\\\mms_delivery_read_sim1.bmp","mms delivery report message read icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_DR_READ_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\deliveryreport\\\\Slave\\\\mms_delivery_read_sim2.bmp","mms delivery report message read icon");
#endif /*SLIM_WAP_MMS*/
    ADD_APPLICATION_IMAGE2(MEA_IMG_OUTBOX_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\master\\\\SB_UTBOX_sim1.bmp","mms menu icon outbox");
    ADD_APPLICATION_IMAGE2(MEA_IMG_OUTBOX_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\slave\\\\SB_UTBOX_sim2.bmp","mms menu icon outbox");
   // ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_CREATED_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Listmenuicon\\\\SB_SET_sim1.bmp","mms draft message icon");
   // ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_CREATED_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Listmenuicon\\\\SB_SET_sim2.bmp","mms draft message icon");    
    ADD_APPLICATION_IMAGE2(MEA_IMG_SENT_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\master\\\\SB_UTBOX_sim1.bmp","mms menu icon sent");
    ADD_APPLICATION_IMAGE2(MEA_IMG_SENT_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\slave\\\\SB_UTBOX_sim2.bmp","mms menu icon sent");    
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_message_sim1.bmp","mms unread message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Slave\\\\mms_message_sim2.bmp","mms unread message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_NOTIF_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\notification\\\\Master\\\\notification_sim1.bmp","mms notification icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_NOTIF_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\notification\\\\Slave\\\\notification_sim2.bmp","mms notification icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_READ_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_messageread_sim1.bmp","mms read message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_READ_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Slave\\\\mms_messageread_sim2.bmp","mms read message icon");
#endif /*defined(OBIGO_Q03C_MMS_V01*/

#endif /* #ifdef __MMI_WAP_DUAL_SIM__ */
#if defined(__COSMOS_MMI__)
    ADD_APPLICATION_IMAGE2(WAP_IMG_ICON_BROKEN_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\SW_Broken.pbm", "Image of a broken image");
#else
    ADD_APPLICATION_IMAGE2(WAP_IMG_ICON_BROKEN_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\SW_Broken.bmp", "Image of a broken image");
#endif
#ifdef  __MMI_WAP_MOUSE_POINTER_SUPPORT__
    ADD_APPLICATION_IMAGE2(WAP_IMG_ICON_MOUSE_POINTER, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Mouse_Pointer.bmp", "Mouse pointer image");
    ADD_APPLICATION_IMAGE2(WAP_IMG_ICON_LINK_SELECT_TOOL, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\link_select_tool.bmp", "Link Select hand tool image");
#endif /* __MMI_WAP_MOUSE_POINTER_SUPPORT__ */
#ifdef  __MMI_WAP_CORE_PICTOGRAM_SUPPORT__

	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_ARROW_UP, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\up.bmp", "Image of pictogram up");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_ARROW_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\down.bmp", "Image of pictogram down");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_ARROW_RIGHT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\right.BMP", "Image of pictogram right");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_ARROW_LEFT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\left.BMP", "Image of pictogram left");

	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_ARROW_UPPERRIGHT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\upperright.bmp", "Image of pictogram uppperright");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_ARROW_UPPERLEFT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\upperleft.BMP", "Image of pictogram upperleft");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_ARROW_LOWERRIGHT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\lowerright.bmp", "Image of pictogram lowerright");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_ARROW_LOWERLEFT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\lowerleft.BMP", "Image of pictogram lowerleft");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_ARROW_FINGERUP, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\fingerup.bmp", "Image of pictogram fingerup");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_ARROW_FINGERDOWN, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\fingerdown.bmp", "Image of pictogram fingerdown");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_ARROW_FINGERRIGHT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\fingerright.bmp", "Image of pictogram fingerright");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_ARROW_FINGERLEFT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\fingerleft.bmp", "Image of pictogram fingerleft");

	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_BUTTON_1, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\1.bmp", "Image of pictogram button 1");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_BUTTON_2, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\2.bmp", "Image of pictogram button 2");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_BUTTON_3, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\3.bmp", "Image of pictogram button 3");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_BUTTON_4, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\4.bmp", "Image of pictogram button 4");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_BUTTON_5, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\5.bmp", "Image of pictogram button 5");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_BUTTON_6, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\6.bmp", "Image of pictogram button 6");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_BUTTON_7, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\7.bmp", "Image of pictogram button 7");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_BUTTON_8, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\8.bmp", "Image of pictogram button 8");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_BUTTON_9, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\9.bmp", "Image of pictogram button 9");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_BUTTON_0, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\0.bmp", "Image of pictogram button 0");

	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_ACTION_MAKEPHONECALL, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\makephonecall.bmp", "Image of pictogram action makephonecall");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_ACTION_FIND, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\find.bmp", "Image of pictogram action find");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_ACTION_USERAUTHENTICATION, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\userauthentication.bmp", "Image of pictogram action userauthentication");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_ACTION_PASSWORD, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\password.bmp", "Image of pictogram action password");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_ACTION_NEXTITEM, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\nextitem.bmp", "Image of pictogram action nextitem");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_ACTION_CLEAR, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\clear.bmp", "Image of pictogram action clear");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_ACTION_STOP, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\stop.bmp", "Image of pictogram action stop");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_ACTION_TOP, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\top.bmp", "Image of pictogram action top");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_ACTION_NEXT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\next.bmp", "Image of pictogram action next");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_ACTION_BACK, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\back.bmp", "Image of pictogram action back");

	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_MESSAGE_RECEIVE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\message\\\\receive.bmp", "Image of pictogram message receive");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_MESSAGE_SEND, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\message\\\\send.bmp", "Image of pictogram message send");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_MESSAGE_MESSAGE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\message\\\\message.bmp", "Image of pictogram message message");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_MESSAGE_DOCUMENT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\message\\\\document.bmp", "Image of pictogram message document");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_MESSAGE_ATTACHMENT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\message\\\\attachment.bmp", "Image of pictogram message attachment");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_MESSAGE_FOLDER, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\message\\\\folder.bmp", "Image of pictogram message folder");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_MESSAGE_INBOX, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\message\\\\inbox.bmp", "Image of pictogram message inbox");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_MESSAGE_OUTBOX, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\message\\\\outbox.bmp", "Image of pictogram message outbox");

	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_STATE_SECURE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\state\\\\secure.bmp", "Image of pictogram state secure");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_STATE_INSECURE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\state\\\\insecure.bmp", "Image of pictogram state insecure");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_STATE_COPYRIGHT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\state\\\\copyright.bmp", "Image of pictogram state copyright");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_STATE_TRADEMARK, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\state\\\\trademark.bmp", "Image of pictogram state trademark");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_STATE_UNDERCONSTRUCTION, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\state\\\\underconstruction.bmp", "Image of pictogram state underconstruction");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_STATE_BEGINNER, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\state\\\\beginner.bmp", "Image of pictogram state beginner");

	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_MEDIA_BOOK, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\media\\\\book.bmp", "Image of pictogram media book");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_MEDIA_VIDEO, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\media\\\\video.bmp", "Image of pictogram media video");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_MEDIA_CD, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\media\\\\cd.bmp", "Image of pictogram media cd");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_MEDIA_DVD, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\media\\\\dvd.bmp", "Image of pictogram media dvd");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_MEDIA_GAME, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\media\\\\game.bmp", "Image of pictogram media game");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_MEDIA_RADIO, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\media\\\\radio.bmp", "Image of pictogram media radio");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_MEDIA_TV, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\media\\\\tv.bmp", "Image of pictogram media tv");

	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_INFO_NOTICE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\info\\\\notice.bmp", "Image of pictogram info notice");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_INFO_CHARGED, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\info\\\\charged.bmp", "Image of pictogram info charged");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_INFO_FREEOFCHARGE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\info\\\\freeofcharge.bmp", "Image of pictogram info freeofcharge");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_INFO_NEW, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\info\\\\new.bmp", "Image of pictogram info new");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_INFO_POSITION, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\info\\\\position.bmp", "Image of pictogram info position");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_INFO_TOLLFREE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\info\\\\tollfree.bmp", "Image of pictogram info tollfree");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_INFO_SHARPDIAL, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\info\\\\sharpdial.bmp", "Image of pictogram info sharpdial");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_INFO_RESERVED, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\info\\\\reserved.bmp", "Image of pictogram info reserved");
	ADD_APPLICATION_IMAGE2(WAP_IMG_PICT_CORE_INFO_SPEECHINFO, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\info\\\\speechinfo.bmp", "Image of pictogram info speechinfo");

#endif /*  __MMI_WAP_CORE_PICTOGRAM_SUPPORT__ */ 

#if defined(OBIGO_Q03C_MMS_V01)
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB1,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB1.bmp","list number icon 1");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB2,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB2.bmp","list number icon 2");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB3,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB3.bmp","list number icon 3");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB4,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB4.bmp","list number icon 4");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB5,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB5.bmp","list number icon 5");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB6,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB6.bmp","list number icon 6");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB7,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB7.bmp","list number icon 7");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB8,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB8.bmp","list number icon 8");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB9,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB9.bmp","list number icon 9");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB10,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB10.bmp","list number icon 10");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB11,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB11.bmp","list number icon 11");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB12,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB12.bmp","list number icon 12");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB13,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB13.bmp","list number icon 13");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB14,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB14.bmp","list number icon 14");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB15,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB15.bmp","list number icon 15");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB16,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB16.bmp","list number icon 16");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB17,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB17.bmp","list number icon 17");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB18,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB18.bmp","list number icon 18");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB19,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB19.bmp","list number icon 19");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB20,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB20.bmp","list number icon 20");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB21,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB21.bmp","list number icon 21");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB22,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB22.bmp","list number icon 22");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB23,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB23.bmp","list number icon 23");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB24,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB24.bmp","list number icon 24");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB25,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB25.bmp","list number icon 25");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB26,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB26.bmp","list number icon 26");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB27,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB27.bmp","list number icon 27");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB28,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB28.bmp","list number icon 28");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB29,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB29.bmp","list number icon 29");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB30,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB30.bmp","list number icon 30");


#ifndef __MMI_WAP_DUAL_SIM__
#if SLIM_WAP_MMS
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_JAVA,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_message.bmp","java mms icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_PRIO_HIGH,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_message.bmp","mms high priority unread message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_message.bmp","unread forward-lock mms icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_PRIO_HIGH,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_message.bmp","unread forward-lock mms icon with high priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_PRIO_LOW,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_message.bmp","unread forward-lock mms icon with high priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_READ,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_messageread.bmp","forward-locked mms message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_READ_PRIO_HIGH,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_messageread.bmp","forward-locked mms message icon with low priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_READ_PRIO_LOW,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_messageread.bmp","forward-locked mms message icon with low priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_PRIO_LOW,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_message.bmp","mms low priority unread message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_READ_PRIO_HIGH,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_messageread.bmp","mms high priority read message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_READ_PRIO_LOW,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_messageread.bmp","mms low priority read message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_RR,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_message.bmp","mms read report message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_RR_READ,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_messageread.bmp","mms read report message read icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_DR,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_message.bmp","mms delivery report message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_DR_READ,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_messageread.bmp","mms delivery report message read icon");
#else /*SLIM_WAP_MMS*/
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_JAVA,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Jsr\\\\mms_messagejsr.bmp","java mms icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_PRIO_HIGH,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_message_h.bmp","mms high priority unread message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Master\\\\mms_lock_sim1.bmp","unread forward-lock mms icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_PRIO_HIGH,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Master\\\\mms_lock_h_sim1.bmp","unread forward-lock mms icon with high priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_PRIO_LOW,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Master\\\\mms_lock_L_sim1.bmp","unread forward-lock mms icon with high priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_READ,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Master\\\\mms_lock_read_sim1.bmp","forward-locked mms message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_READ_PRIO_HIGH,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Master\\\\mms_lock_read_h_sim1.bmp","forward-locked mms message icon with low priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_READ_PRIO_LOW,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Master\\\\mms_lock_read_L_sim1.bmp","forward-locked mms message icon with low priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_PRIO_LOW,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_message_l_sim1.bmp","mms low priority unread message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_READ_PRIO_HIGH,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_messageread_h_sim1.bmp","mms high priority read message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_READ_PRIO_LOW,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_messageread_l_sim1.bmp","mms low priority read message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_RR,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\readreport\\\\Master\\\\mms_read_sim1.bmp","mms read report message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_RR_READ,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\readreport\\\\Master\\\\mms_read_read_SIM1.bmp","mms read report message read icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_DR,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\deliveryreport\\\\Master\\\\mms_delivery_sim1.bmp","mms delivery report message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_DR_READ,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\deliveryreport\\\\Master\\\\mms_delivery_read_sim1.bmp","mms delivery report message read icon");
#endif /*SLIM_WAP_MMS*/
   ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_message.bmp","mms unread message icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_READ,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_messageread.bmp","mms read message icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_NOTIF,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\notification\\\\notification.bmp","mms notification icon");
#endif /*__MMI_WAP_DUAL_SIM__*/
#ifdef __MMI_MMS_BGSR_SUPPORT__
   ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_CREATED_FAILED,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\draft\\\\mmsdraft_failed.bmp","mms draft message icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_CREATED_DEFERRED,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\draft\\\\mmsdraft_deferred.bmp","mms draft message icon");
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
   ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_CREATED,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\draft\\\\mmsdraft.bmp","mms draft message icon");
   /*ADD_APPLICATION_IMAGE2(MEA_IMG_BROKEN_IMAGE,CUST_IMG_PATH"\\\\MainLCD\\\\WarningPage\\\\PopUpPage\\\\PP_QUE"__MMI_RES_TYPE_POPUP_SCREEN__,"mms broken image icon"); */
   ADD_APPLICATION_IMAGE2(MEA_IMG_BROKEN_IMAGE,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\SW_Broken.bmp","mms broken image icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_AUDIO,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\audio.bmp","mms audio icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_SMIL_EDITOR_ATTACHMENT,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\attachfile.bmp","mms attachment icon in SMIL editor");
   //ADD_APPLICATION_IMAGE2(MEA_IMG_SMIL_EDITOR_FRAME,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS-template.gif","mms image frame in SMIL editor");
   ADD_APPLICATION_IMAGE2(MEA_IMG_SMIL_EDITOR_PIC_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\pic_icon.bmp","mms image icon in SMIL editor");
   ADD_APPLICATION_IMAGE2(MEA_IMG_SMIL_EDITOR_VIDEO_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\video_icon.bmp","mms video icon in SMIL editor");
   ADD_APPLICATION_IMAGE2(MEA_IMG_SMIL_SLIDING_BAR_REGION,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\bar.gif","mms sliding bar background icon");

   //ADD_APPLICATION_IMAGE2(MEA_IMG_AUDIO_ERROR,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\Audio_error.gif","Broken audio icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_IMAGE_ERROR,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\Image_error.gif","Broken image icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_VIDEO_ERROR,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\Video_error.gif","Broken video icon");
   //ADD_APPLICATION_IMAGE2(MEA_IMG_AUDIO_LOCK,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\Audio_lock.gif","Lock audio icon");
   //ADD_APPLICATION_IMAGE2(MEA_IMG_IMAGE_LOCK,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\Image_lock.gif","Lock image icon");
   /*TO show image for DRM content*/
#ifdef __DRM_SUPPORT__
   ADD_APPLICATION_IMAGE2(MEA_IMG_IMAGE_DRM,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\DRM.gif","Lock image icon");
#endif
#ifdef __MMI_TOUCH_SCREEN__
   //ADD_APPLICATION_IMAGE2(MEA_IMG_MOB_UP_ARROW,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Touch\\\\th_mob_up.gif","Up arrow in mixed-object message");
   //ADD_APPLICATION_IMAGE2(MEA_IMG_MOB_DOWN_ARROW,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Touch\\\\th_mob_down.gif","Down arrow in mixed-object message");
#endif /* __MMI_TOUCH_SCREEN__ */
#ifdef __MMI_MMS_V01_TEMPLATES_SUPPORT__
   ADD_APPLICATION_IMAGE2(MEA_IMG_TEMPLATE,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\mmstemplate.bmp","mms template message icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_TEMPLATES,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\SB_TEMP.bmp","mms menu icon templates");
#endif /*__MMI_MMS_V01_TEMPLATES_SUPPORT__*/
   ADD_APPLICATION_IMAGE2(MEA_IMG_WRITE_MESSAGE,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\SB_WRITE.bmp","mms menu icon write message");
   ADD_APPLICATION_IMAGE2(MEA_IMG_INBOX,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\SB_INBOX.bmp","mms menu icon inbox");
   ADD_APPLICATION_IMAGE2(MEA_IMG_OUTBOX,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\SB_UTBOX.bmp","mms menu icon outbox");
   ADD_APPLICATION_IMAGE2(MEA_IMG_DRAFTS,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\SB_drafts.bmp","mms menu icon draft");
   ADD_APPLICATION_IMAGE2(MEA_IMG_SENT,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\SB_sent.bmp","mms menu icon sent");
   ADD_APPLICATION_IMAGE2(MEA_IMG_SETTINGS,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\SB_SET.bmp","mms menu icon settings");

   ADD_APPLICATION_IMAGE2(MEA_IMG_TITLE_NORMAL,CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_MG.png","message title icon");
   //ADD_APPLICATION_IMAGE2(MEA_IMG_TITLE_BUSY,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\titlebar\\\\MMSC.gif","mms title icon for busy state");
   ADD_APPLICATION_IMAGE2(MEA_IMG_TITLE_RING,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\titlebar\\\\MMSR.gif","mms title icon for busy state");
   //ADD_APPLICATION_IMAGE2(MEA_IMG_TITLE_ATTACHMENT,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\titlebar\\\\Attachfile.bmp","mms title icon for attachment");
   //ADD_APPLICATION_IMAGE2(MEA_IMG_EDITOR_FROM,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\editor\\\\from.bmp","mms message editor icon for <from>");
   ADD_APPLICATION_IMAGE2(MEA_IMG_EDITOR_TO,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\editor\\\\to.bmp","mms message editor icon for <to>");
   ADD_APPLICATION_IMAGE2(MEA_IMG_EDITOR_CC,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\editor\\\\cc.bmp","mms message editor icon for <cc>");
   ADD_APPLICATION_IMAGE2(MEA_IMG_EDITOR_BCC,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\editor\\\\bcc.bmp","mms message editor icon for <bcc>");
   ADD_APPLICATION_IMAGE2(MEA_IMG_EDITOR_SUBJECT,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\editor\\\\sb.bmp","mms message editor icon for <subject>");
   ADD_APPLICATION_IMAGE2(MEA_IMG_EDITOR_CONTENT,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\editor\\\\content.bmp","mms message editor icon for <edit content>");
   //ADD_APPLICATION_IMAGE2(MEA_IMG_EDITOR_LAYOUT,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\editor\\\\layout.bmp","mms message editor icon for <layout>");
   //ADD_APPLICATION_IMAGE2(MEA_IMG_EDITOR_SIZE,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\editor\\\\size.bmp","mms message editor icon for <size>");

   ADD_APPLICATION_IMAGE2(MEA_IMG_SET_SEND_PERIOD,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Setting\\\\mms_period.bmp","mms setting icon for expired period");
   ADD_APPLICATION_IMAGE2(MEA_IMG_SET_SEND_DR,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Setting\\\\mms_deliveryreport.bmp","mms setting icon for delivery report");
   ADD_APPLICATION_IMAGE2(MEA_IMG_SET_SEND_RR,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Setting\\\\mms_readreport.bmp","mms setting icon for read report");
   ADD_APPLICATION_IMAGE2(MEA_IMG_SET_SEND_PRIORITY,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Setting\\\\mms_Priority.bmp","mms setting icon for priority");
   ADD_APPLICATION_IMAGE2(MEA_IMG_SET_SEND_SLIDE_DUR,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Setting\\\\mms_stiming.bmp","mms setting icon for slide duration");
   ADD_APPLICATION_IMAGE2(MEA_IMG_SET_SEND_DELIVERY_TIME,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Setting\\\\mms_deliverytime.bmp","mms setting icon for delivery time");
   //ADD_APPLICATION_IMAGE2(MEA_IMG_SET_SIG_STATUS,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Setting\\\\mms_sig_status.bmp","mms setting icon for turning on/off auto signature");
   //ADD_APPLICATION_IMAGE2(MEA_IMG_SET_SIG_IMAGE,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Setting\\\\mms_sig_image.bmp","mms setting icon for signature image");
   //ADD_APPLICATION_IMAGE2(MEA_IMG_SET_SIG_TEXT,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Setting\\\\mms_sig_text.bmp","mms setting icon for signature text");
#ifdef __MMI_MMS_V01_TEMPLATES_SUPPORT__
#ifndef __MMI_MMS_TEMPLATES_NUM__
#define __MMI_MMS_TEMPLATES_NUM__ 5
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>0)
   ADD_APPLICATION_IMAGE2(MMS_IMG_TEMPLATES_01,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T01.gif","mms template image 01 ");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>1)
   ADD_APPLICATION_IMAGE2(MMS_IMG_TEMPLATES_02,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T02.gif","mms template image 02 ");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>2)
   ADD_APPLICATION_IMAGE2(MMS_IMG_TEMPLATES_03,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T03.gif","mms template image 03 ");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>3)
   ADD_APPLICATION_IMAGE2(MMS_IMG_TEMPLATES_04,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T04.gif","mms template image 04 ");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>4)
   ADD_APPLICATION_IMAGE2(MMS_IMG_TEMPLATES_05,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T05.gif","mms template image 05 ");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>5)
   ADD_APPLICATION_IMAGE2(MMS_IMG_TEMPLATES_06,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T06.gif","mms template image 06 ");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>6)
   ADD_APPLICATION_IMAGE2(MMS_IMG_TEMPLATES_07,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T07.gif","mms template image 07 ");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>7)
   ADD_APPLICATION_IMAGE2(MMS_IMG_TEMPLATES_08,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T08.gif","mms template image 08 ");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>8)
   ADD_APPLICATION_IMAGE2(MMS_IMG_TEMPLATES_09,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T09.gif","mms template image 09 ");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>9)
   ADD_APPLICATION_IMAGE2(MMS_IMG_TEMPLATES_10,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T10.gif","mms template image 10 ");
#endif
/* Audio Files */
#if (__MMI_MMS_TEMPLATES_NUM__>0)
   ADD_APPLICATION_AUDIO2(MMS_AUDIO_TEMPLATES_01,CUST_ADO_PATH"\\\\MMS\\\\mms01.mid","mms template audio 01 ");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>1)
   ADD_APPLICATION_AUDIO2(MMS_AUDIO_TEMPLATES_02,CUST_ADO_PATH"\\\\MMS\\\\mms02.mid","mms template audio 02 ");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>2)
   ADD_APPLICATION_AUDIO2(MMS_AUDIO_TEMPLATES_03,CUST_ADO_PATH"\\\\MMS\\\\mms03.mid","mms template audio 03 ");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>3)
   ADD_APPLICATION_AUDIO2(MMS_AUDIO_TEMPLATES_04,CUST_ADO_PATH"\\\\MMS\\\\mms04.mid","mms template audio 04 ");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>4)
   ADD_APPLICATION_AUDIO2(MMS_AUDIO_TEMPLATES_05,CUST_ADO_PATH"\\\\MMS\\\\mms05.mid","mms template audio 05 ");
#endif

#endif /*__MMI_MMS_V01_TEMPLATES_SUPPORT__*/
    ADD_APPLICATION_IMAGE2(MEA_IMG_IMAGE_USE_DETAILS_IMAGE_NUMBER,CUST_IMG_PATH"\\\\MainLCD\\\\Phonebook\\\\PBView\\\\PV_PHONE.bmp","mobile number image");
    ADD_APPLICATION_IMAGE2(MEA_IMG_IMAGE_USE_DETAILS_IMAGE_EMAIL,CUST_IMG_PATH"\\\\MainLCD\\\\Phonebook\\\\PBView\\\\PV_EM.bmp","email image");
    ADD_APPLICATION_IMAGE2(MEA_IMG_IMAGE_USE_DETAILS_IMAGE_URL,CUST_IMG_PATH"\\\\MainLCD\\\\Phonebook\\\\PBView\\\\PV_URL.bmp","url image");
    ADD_APPLICATION_MENUITEM((MENU_ID_MMSV01_AGENT_SETTINGS_DUMMY,0,2,
		MENU_ID_MMSV01_AGENT_SETTINGS_EDIT_PROFILE,
		MENU_ID_MMSV01_AGENT_SETTINGS_FOR_COMMON_HANDLING,
		SHOW, NONMOVEABLE,
		DISP_LIST,0,NULL));

    
    ADD_APPLICATION_MENUITEM((
		MENU_ID_MMSV01_AGENT_SETTINGS_FOR_COMMON_HANDLING,MENU_ID_MMSV01_AGENT_SETTINGS_DUMMY,5,
		MENU_ID_MMSV01_AGENT_SETTINGS_COMPOSE,
        MENU_ID_MMSV01_AGENT_SETTINGS_SENDING,
        MENU_ID_MMSV01_AGENT_SETTINGS_RETRIEVAL,
        MENU_ID_MMSV01_AGENT_SETTINGS_FILTER,
        MENU_ID_MMSV01_AGENT_SETTINGS_MEMORY_STATUS,
		SHOW, NONMOVEABLE,
		DISP_LIST,MEA_STR_ID_COMMON_SETTINGS,NULL));


#ifdef __MMI_MMS_DUAL_SIM__
    ADD_APPLICATION_MENUITEM((
		MENU_ID_MMSV01_AGENT_SETTINGS_EDIT_PROFILE,MENU_ID_MMSV01_AGENT_SETTINGS_DUMMY,2,
		MENU_ID_MMSV01_AGENT_SETTING_SIM1,
        MENU_ID_MMSV01_AGENT_SETTING_SIM2,
		SHOW, NONMOVEABLE,
		DISP_LIST,MEA_STR_ID_EDIT_PROFILE,NULL));


    ADD_APPLICATION_MENUITEM((
		MENU_ID_MMSV01_AGENT_SETTING_SIM1,MENU_ID_MMSV01_AGENT_SETTINGS_EDIT_PROFILE,0,
		SHOW, NONMOVEABLE,
		DISP_LIST,MEA_STR_ID_SIM_1,NULL));

    ADD_APPLICATION_MENUITEM((
		MENU_ID_MMSV01_AGENT_SETTING_SIM2,MENU_ID_MMSV01_AGENT_SETTINGS_EDIT_PROFILE,0,
		SHOW, NONMOVEABLE,
		DISP_LIST,MEA_STR_ID_SIM_2,NULL));
#else

    ADD_APPLICATION_MENUITEM((
		MENU_ID_MMSV01_AGENT_SETTINGS_EDIT_PROFILE,MENU_ID_MMSV01_AGENT_SETTINGS_DUMMY,0,
		SHOW, NONMOVEABLE,
		DISP_LIST,MEA_STR_ID_EDIT_PROFILE,NULL));
#endif



    ADD_APPLICATION_MENUITEM((
		MENU_ID_MMSV01_AGENT_SETTINGS_COMPOSE,MENU_ID_MMSV01_AGENT_SETTINGS_FOR_COMMON_HANDLING,0,
        SHOW, NONMOVEABLE,
		DISP_LIST,MEA_STR_ID_CONFIG_COMPOSE,NULL));

    ADD_APPLICATION_MENUITEM((
		MENU_ID_MMSV01_AGENT_SETTINGS_SENDING,MENU_ID_MMSV01_AGENT_SETTINGS_FOR_COMMON_HANDLING,0,
        SHOW, NONMOVEABLE,
		DISP_LIST,MEA_STR_ID_CONFIG_SENDING,NULL));

    ADD_APPLICATION_MENUITEM((
		MENU_ID_MMSV01_AGENT_SETTINGS_RETRIEVAL,MENU_ID_MMSV01_AGENT_SETTINGS_FOR_COMMON_HANDLING,0,
        SHOW, NONMOVEABLE,
		DISP_LIST,MEA_STR_ID_CONFIG_MSG_RETRIEVAL,NULL));

    ADD_APPLICATION_MENUITEM((
		MENU_ID_MMSV01_AGENT_SETTINGS_FILTER,MENU_ID_MMSV01_AGENT_SETTINGS_FOR_COMMON_HANDLING,0,
        SHOW, NONMOVEABLE,
		DISP_LIST,MEA_STR_ID_CONFIG_MSG_FILTERS,NULL));

    ADD_APPLICATION_MENUITEM((
		MENU_ID_MMSV01_AGENT_SETTINGS_MEMORY_STATUS,MENU_ID_MMSV01_AGENT_SETTINGS_FOR_COMMON_HANDLING,0,
        SHOW, NONMOVEABLE,
		DISP_LIST,MEA_STR_ID_MEMORY_STATUS,NULL));

    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MESSAGES_MENU_MMS_MENUID, mmi_mmsv01_agent_mms_entry);
	ADD_APPLICATION_IMAGE2 (MEA_IMG_IMAGE_MMS_MENUENTRY,
								CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\SB_mms.bmp",
							 	"MMS menu item Image");

    ADD_APPLICATION_MENUITEM((MESSAGES_MENU_MMS_MENUID,
									MAIN_MENU_MESSAGES_MENUID,	0, //sub menu
									SHOW,	MOVEABLEWITHINPARENT|SHORTCUTABLE,	DISP_LIST,
									MEA_STR_ID_MMS,	MEA_IMG_IMAGE_MMS_MENUENTRY));

#endif /* OBIGO_Q03C_MMS_V01 */

	ADD_APPLICATION_MENUITEM((WAP_MENU_FULLSCREEN_EDITOR_OPTION,0,3,
		WAP_MENU_FULLSCREEN_EDITOR_OPTION_DONE,
		WAP_MENU_FULLSCREEN_EDITOR_OPTION_CANCEL,
		WAP_MENU_FULLSCREEN_EDITOR_OPTION_INPUT_METHOD,
		SHOW, NONMOVEABLE,
		DISP_LIST,STR_GLOBAL_OPTIONS,IMG_GLOBAL_OPTIONS));

	ADD_APPLICATION_MENUITEM((
				WAP_MENU_FULLSCREEN_EDITOR_OPTION_DONE,
				WAP_MENU_FULLSCREEN_EDITOR_OPTION,
				0, SHOW, NONMOVEABLE,
				DISP_LIST,WIDGET_STR_ID_DONE,NULL));

	ADD_APPLICATION_MENUITEM((
				WAP_MENU_FULLSCREEN_EDITOR_OPTION_CANCEL,
				WAP_MENU_FULLSCREEN_EDITOR_OPTION,
				0, SHOW, NONMOVEABLE,
				DISP_LIST,WIDGET_STR_ID_CANCEL,NULL));

	ADD_APPLICATION_MENUITEM((
				WAP_MENU_FULLSCREEN_EDITOR_OPTION_INPUT_METHOD,
				WAP_MENU_FULLSCREEN_EDITOR_OPTION,
				0, SHOW, NONMOVEABLE,
				DISP_LIST,STR_GLOBAL_INPUT_METHOD,NULL));


	//////////////////////////////////////////////////////
	ADD_APPLICATION_STRING2(BRS_STR_ID_CANCEL,"Cancel","Cancel");
	#ifdef WAP2
	ADD_APPLICATION_STRING2(BRS_STR_ID_BUTTON,"Button","Button");
	ADD_APPLICATION_STRING2(BRS_STR_ID_DEFAULT_IMODE_DLG_CANCEL_MSG,"No","No");
	ADD_APPLICATION_STRING2(BRS_STR_ID_DEFAULT_IMODE_DLG_OK_MSG,"Yes","Yes");
	ADD_APPLICATION_STRING2(BRS_STR_ID_DEFAULT_IMODE_DLG_USER_MSG,"Send mobile phone info?","Send mobile phone info?");
	#endif
	ADD_APPLICATION_STRING2(BRS_STR_ID_DEFAULT_INPUT_FORMAT_USER_MSG,"Input format error","Input format error");
//	ADD_APPLICATION_STRING2(BRS_STR_ID_DEFAULT_INPUT_FORMAT_USER_MSG_INPUT_REQ,"The field cannot be empty.","The field cannot be empty.");
//	ADD_APPLICATION_STRING2(BRS_STR_ID_DEFAULT_INPUT_FORMAT_USER_MSG_LAST_CHAR,"The last character was not allowed.","The last character was not allowed.");
	ADD_APPLICATION_STRING2(BRS_STR_ID_OK,"Ok","Ok");
	ADD_APPLICATION_STRING2(BRS_STR_ID_REDIRECT_POST,"Redirected request received. Resubmit user data ?","Redirected request received. Resubmit user data ?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_RESEND_POST,"Do you want to resubmit user data ?","Do you want to resubmit user data ?");
	#if WAP2
	ADD_APPLICATION_STRING2(BRS_STR_ID_RESET,"Reset","Reset");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUBMIT,"Submit","Submit");
	#endif
	ADD_APPLICATION_STRING2(BRS_STR_ID_NO_MIME_MSG,"Do you wish to load this object ?","Do you wish to load this object?");
	#if 0
/* under construction !*/
	#endif
//	ADD_APPLICATION_STRING2(BRS_STR_ID_NO_MIME_MSG_2,"], with URL = [","], with URL = [");
//	ADD_APPLICATION_STRING2(BRS_STR_ID_NO_MIME_MSG_3,"] ?","] ?");
//	ADD_APPLICATION_STRING2(BRS_STR_ID_NO_MIME_MSG_4,"Unknown","Unknown");
	//////////////////////////////////////////////////////
#if defined(OBIGO_Q03C_MMS_V01)
#ifdef __MMI_URI_AGENT__
    ADD_APPLICATION_STRING2(MEA_STR_ID_SEND_MMS_QUERY, "Send MMS?", "Send MMS?");
#endif /*__MMI_URI_AGENT__*/
	ADD_APPLICATION_STRING2(MEA_STR_ID_SIM_1,"SIM 1","SIM 1");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SIM_2,"SIM 2","SIM 2");
   	ADD_APPLICATION_STRING2(MEA_STR_ID_FROM_SIM_1,"From Sim1","From Sim1");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FROM_SIM_2,"From Sim2","From Sim2");

	//ADD_APPLICATION_STRING2(MEA_STR_ID_CHOOSE_SIM,"Please choose a SIM card","Please choose a SIM card");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FORWARD_WITH_EDIT_CONTENT,"Do you want to edit content?","Do you want to edit content?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SERVER_TIMEOUT,"Server Timeout","Server Timeout");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NOT_AVAILABLE,"Not Available","Not Available");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_MAX_TEXT_LEN_REACHED,"Max text length reached!","Max text length reached!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REMOVE_INVALID_OBJECT,"Invalid Object Remove.","Invalid Object Remove.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADDRESS_FIELD_MISSING,"At least one address field must be filled in.","At least one address field must be filled in.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADD_EMAIL,"Add E-mail","Add E-mail");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADD_IMAGE,"Add Image","Add Image");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADD_MEDIA_OBJECT,"Add media object","Add media object");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADD_NUMBER,"Add Number","Add Number");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADD_RECIPIENT,"Add Recipient","Add Recipient");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_ADD_RECIPIENT_QUEST,"Add recipient?","Add recipient?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NO_OF_RECIPIENTS,"recipients","recipients");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_FORWARD,"The message is forward prohibited","The message is forward prohibited");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_FORWARD_LOCK,"The message is edit prohibited","The message is edit prohibited");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADD_TEXT,"Add text","Add text");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADD_BOOKMARK_TEXT,"Add Bookmark Text","Add Bookmark Text");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONTENT_TRUNCATED,"Content too long. Truncated.","Content too long. Truncated.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ALLOW,"Allow","Allow");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ATTACH_ERROR,"Unable to show attachment!","Unable to show attachment!");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_ATTACH_TITLE,"Attachment","Attachment");
	ADD_APPLICATION_STRING2(MEA_STR_ID_BACK,"Back","Back");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_BYTES_RECEIVED," bytes received."," bytes received.");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_BYTES_SENT," bytes sent."," bytes sent.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CANCEL,"Cancel","Cancel");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CC,"Cc: ","Cc: ");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CLOSE_MEA,"Do you want to close the Messenger Application?","Do you want to close the Messenger Application?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG,"Settings","Settings");
        ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_6_HOURS,"6 Hours","6 Hours");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_12_HOURS,"12 Hours","12 Hours");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_1_DAY,"1 Day","1 Day");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_1_HOUR,"1 Hour","1 Hour");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_1_WEEK,"1 Week","1 Week");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_ADVERT,"Advertisement","Advertisement");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_ANONYM,"Anonymous senders","Anonymous senders");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_MSG_RETRIEVAL,"Retrieval","Retrieval");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_AUTO,"AUTO messages","AUTO messages");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_DR,"Delivery report","Delivery report");
	ADD_APPLICATION_STRING2(MEA_STR_ID_UNSUPPORTED_HEADER_FIELDS,"Failed to open the originating message since it contains unsupported header fields!","Failed to open the originating message since it contains unsupported header fields!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_HIGH,"High","High");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_IM_SERVER,"Immediate server","Immediate server");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_IM_SIZE,"Immediate limit","Immediate limit");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_INFO,"INFORMATIONAL messages","INFORMATIONAL messages");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_LOW,"Low","Low");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_MAX,"Maximum","Maximum");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_MMSC,"MMSC","MMSC");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_MSG_FILTERS,"Filter","Filter");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_MSG_RETRIEVAL,"Retrieve","Retrieve");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_NETWORK,"Network","Network");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_NORMAL,"Medium","Medium");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_PERS,"PERSONAL messages","PERSONAL messages");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_PRIORITY,"Priority","Priority");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_RR,"Read report","Read report");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_SENDING,"Send","Send");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_TREAT_AS_DEL,"Treat as delayed","Treat as delayed");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_USER_STRING,"STRING messages","STRING messages");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_VAL_PER,"Validity period","Validity period");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONNECTING,"connecting.","connecting.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONN_TYPE,"Connection type","Connection type");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONN_TYPE_HTTP,"HTTP","HTTP");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONN_TYPE_WSP_CL,"WSP CL","WSP CL");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONN_TYPE_WSP_CO,"WSP CO","WSP CO");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_DATE,"Date:","Date:");
    ADD_APPLICATION_STRING2(MEA_STR_ID_RECEIVE_DATE,"Received date:","Received date:");
    ADD_APPLICATION_STRING2(MEA_STR_ID_SEND_DATE,"Sent date:","Sent date:");
    ADD_APPLICATION_STRING2(MEA_STR_ID_CREATE_DATE,"Created date:","Created date:");

	ADD_APPLICATION_STRING2(MEA_STR_ID_DEFERRED,"Deferred.","Deferred.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DELETE,"Delete","Delete");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DELETE_ALL,"Delete All","Delete All");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_DELETE_MSG_QUEST,"Do you want to delete the message?","Do you want to delete the message?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DELETE_MSG_QUEST,"Delete?","Delete?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DELETE_SLIDE,"Delete Slide","Delete Slide");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DELIV_REPORT,"Delivery report","Delivery report");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DEL_RETRIEVAL,"Delayed","Delayed");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DIAL,"Dial","Dial");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DONE,"Done","Done");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DOWNLOAD,"Download","Download");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DOWNLOAD_SIZE,"Download size","Download size");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NOTIFICATION_SIZE,"File size","File size");
	ADD_APPLICATION_STRING2(MEA_STR_ID_COMM_UNAVAILABLE,"The server is temporarily unavailable.","The server is temporarily unavailable.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DOWNLOADING_MM,"Downloading message.","Downloading message.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DOWNLOAD_FAILED,"Message download failed!","Message download failed!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DOWNLOAD_FAILED_ILLEGAL_PDU,"Invalid download data","Invalid download data");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DOWNLOAD_REQ1,"Download a ","Download a ");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DOWNLOAD_REQ2,"K MMS","K MMS");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DRAFTS,"Draft","Draft");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DURATION,"Slide Timing","Slide Timing");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EDIT,"Edit","Edit");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EDIT_AUDIO,"Edit Audio","Edit Audio");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EDIT_CONTENT,"Edit Content","Edit Content");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EDIT_FAILED_RESOURCES_EXHAUSTED,"Message creation failed. System resources exhausted!","Message creation failed. System resources exhausted!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EDIT_IMAGE,"Edit Image","Edit Image");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_EDIT_MESSAGE,"Edit Message","Edit Message");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EDIT_TEXT,"Edit text","Edit text");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EMPTY,"Empty","Empty");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EMPTY_LIST,"<Empty>","<Empty>");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_EMPTY199,"","");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_EMPTY212,"","");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_EMPTY213,"","");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_EMPTY214,"","");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EMPTY_STRING,"","");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_EMPTY_STRING023," "," ");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_EMPTY_STRING024," "," ");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_EMPTY_STRING025," "," ");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_EMPTY_STRING034," "," ");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ERROR,"Error","Error");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EXIT,"Exit","Exit");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EXPIRED,"Expired.","Expired.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_DISPLAY_JSR_MMS,"Read only by JAVA","Read only by JAVA");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_DISPLAY_MM,"Failed to display the message!","Failed to display the message!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_DISPLAY_NOTIF,"Erroneous notification!","Erroneous notification!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_EDIT,"Failed to edit the message","Failed to edit the message");
#ifdef __UNIFIED_COMPOSER_SUPPORT__
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_REPLY,"Failed to reply the message","Failed to reply the message");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REMOVE_INVALID_OBJECT_TO_ATTACH, "Invalid Object Remove to attachment.","Invalid Object Remove to attachment.");
#endif /*__UNIFIED_COMPOSER_SUPPORT__*/
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_READ_MO,"Failed to add media object","Failed to add media object");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_ADD_EMPTY_OBJECT, "Failed to add empty file","Failed to add empty file");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_LARGE_RESOLUTION, "Picture size too large","Picture size too large");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_FILE_CORRUPT, "File may be corrupted","File may be corrupted");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_SAVE,"Failed to save message!","Failed to save message!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_CONNECTION,"Connection error. Save to Outbox","Connection error. Save to Outbox");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_FORWARD,"Failed to forward message","Failed to forward message");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_SEND,"Failed to send message!","Failed to send message!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_SEND_RR,"The read report could not be sent!","The read report could not be sent!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FORWARD,"Forward","Forward");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FORWARDED,"Forwarded.","Forwarded.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FROM,"From: ","From: ");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_GENERATING_MESSAGE,"Generating message.","Generating message.");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_HTTP_PORT,"HTTP port","HTTP port");
	ADD_APPLICATION_STRING2(MEA_STR_ID_IM_RETRIEVAL,"Immediate","Immediate");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INBOX,"Inbox","Inbox");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INDETERMINATE,"Indeterminate.","Indeterminate.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INSERT_SLIDE,"Insert New Slide","Insert New Slide");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADD_SLIDE_BEFORE,"Add Slide Before","Add Slide Before");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADD_SLIDE_AFTER,"Add Slide After","Add Slide After");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INTERVAL_INFIX," and "," and ");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INTERVAL_PREFIX,"Input value between ","Input value between ");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_INVALID_ADDRESS,"Invalid from address!","Invalid from address!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INVALID_MESSAGE,"Message is invalid!","Message is invalid!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INVALID_MMS_VERSION,"The configuration is not valid. Please check the MMSC version number.","The configuration is not valid. Please check the MMSC version number.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INVALID_PROXY_HOST,"Invalid proxy address!","Invalid proxy address!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INVALID_PROXY_PORT,"Invalid proxy port!","Invalid proxy port!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INVALID_PROXY_SCHEME,"Invalid proxy scheme!","Invalid proxy scheme!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INVALID_RECIP_ADDRESS,"Invalid recipient address!","Invalid recipient address!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INVALID_VALUE,"Invalid input value!","Invalid input value!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INVALID_WAP_GATEWAY,"Invalid WAP gateway!","Invalid WAP gateway!");
    ADD_APPLICATION_STRING2(MEA_STR_ID_UNAUTHORIZED_ACCESS,"Unauthorized access","Unauthorized access");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_KB,"kB","kB");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_LOGIN,"Login","Login");
	ADD_APPLICATION_STRING2(MEA_STR_ID_MAX_RETR_SIZE,"Max retrieval size","Max retrieval size");
	ADD_APPLICATION_STRING2(MEA_STR_ID_MENU,"menu","menu");
	ADD_APPLICATION_STRING2(MEA_STR_ID_MIN_TIME_DURATION,"Valid time: 1-99 sec","Valid time: 1-99 sec");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_MESSAGE_SENT,"Message was sent successfully.","Message was sent successfully.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_MESSAGE_SENT,"Sent","Sent");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_MESSENGER_APP,"Messenger application","Messenger application");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ME_INVALID_CONFIG,"The configuration is not valid. Please check \"From\" address and the MMSC version number.","The configuration is not valid. Please check \"From\" address and the MMSC version number.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ME_TITLE,"Message editor","Message editor");
	ADD_APPLICATION_STRING2(MEA_STR_ID_MMS,"MMS","MMS");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_NETWORK_ACCOUNT,"Network account","Network account");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NEW_MMS_MSG,"New MMS Message","New MMS Message");
#ifdef __MMI_MMS_V01_TEMPLATES_SUPPORT__	
	ADD_APPLICATION_STRING2(MEA_STR_ID_NEW_MSG_FROM_TEMPL,"Create message from template","Create message from template");
#endif /*__MMI_MMS_V01_TEMPLATES_SUPPORT__*/
	//ADD_APPLICATION_STRING2(MEA_STR_ID_NEW_SMIL,"New multimedia message","New multimedia message");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NEXT_SLIDE,"Next Slide","Next Slide");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NO,"No","No");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NOT_ENOUGH_MEM,"Not enough memory to complete this operation!","Not enough memory to complete this operation!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NOT_READ,"Deleted, not read.","Deleted, not read.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NO_OF_RECIPIENTS," recipients."," recipients.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NO_PERSISTENT_STORAGE,"Not enough message storage. Delete messages to free storage space.","Not enough message storage. Delete messages to free storage space.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_OFF,"Off","Off");
	ADD_APPLICATION_STRING2(MEA_STR_ID_OK,"Ok","Ok");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ON,"On","On");
	ADD_APPLICATION_STRING2(MEA_STR_ID_OPTIONS,"Options","Options");
	ADD_APPLICATION_STRING2(MEA_STR_ID_OUTBOX,"Outbox","Outbox");
	ADD_APPLICATION_STRING2(MEA_STR_ID_PANIC,"Internal error. The application is going to close.","Internal error. The application is going to close.");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_PASSWD,"Password","Password");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_PHONE_BOOK,"Phone book","Phone book");
	ADD_APPLICATION_STRING2(MEA_STR_ID_PREVIEW_SMIL,"Preview multimedia message","Preview multimedia message");
	ADD_APPLICATION_STRING2(MEA_STR_ID_PREVIOUS_SLIDE,"Previous Slide","Previous Slide");
	ADD_APPLICATION_STRING2(MEA_STR_ID_PROPERTIES,"Properties","Properties");
	ADD_APPLICATION_STRING2(MEA_STR_ID_READ,"Read.","Read.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_READING_MSG,"Reading message.....","Reading message.....");
	ADD_APPLICATION_STRING2(MEA_STR_ID_READ_REPORT,"Read report","Read report");
	ADD_APPLICATION_STRING2(MEA_STR_ID_READ_REPORT_SEND,"A read report has been requested for this message. Do you want to send a read report?","A read report has been requested for this message. Do you want to send a read report?");
//	ADD_APPLICATION_STRING2(MEA_STR_ID_REALM,"Realm","Realm");
	ADD_APPLICATION_STRING2(MEA_STR_ID_RECIPIENTS,"Recipients:","Recipients:");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REJECT,"Reject","Reject");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REJECTED,"Rejected.","Rejected.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REMOVE_AUDIO,"Remove Audio","Remove Audio");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REMOVE_IMAGE,"Remove Image","Remove Image");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REMOVE_TEXT,"Remove Text","Remove Text");
#ifdef __MMI_MMS_VIDEO_FEATURE__
#if defined(MJPG_DECODE) || defined(MP4_DECODE) || defined(__RM_DEC_SUPPORT__) 
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADD_VIDEO, "Add Video", "Add Video");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EDIT_VIDEO, "Edit Video", "Edit Video");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REMOVE_VIDEO, "Remove Video", "Remove Video");
#endif
#endif
	ADD_APPLICATION_STRING2(MEA_STR_ID_REM_MEDIA_OBJ,"Remove current media object","Remove current media object");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REPLY,"Reply","Reply");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REPLY_SMS,"Reply by SMS","Reply by SMS");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REPLY_TO_ALL,"Reply All","Reply All");
	ADD_APPLICATION_STRING2(MEA_STR_ID_RETRIEVED,"Retrieved.","Retrieved.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_RETR_SIZE_EXCEEDED,"A too large message was blocked","A too large message was blocked");
#ifdef __MMI_WAP_MMS_NO_REJECT_NOTIFICATION_BY_SIZE__	
	ADD_APPLICATION_STRING2(MEA_STR_ID_RETR_SIZE_EXCEEDED_CONFIRM,"The size of MMS message exceeds max message size, Continue?","The size of MMS message exceeds max message size, Continue?");
#endif	
	ADD_APPLICATION_STRING2(MEA_STR_ID_SAVE,"Save","Save");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SAVE_AND_SEND,"Save and Send","Save and Send");
#ifdef __MMI_MMS_V01_TEMPLATES_SUPPORT__	
	ADD_APPLICATION_STRING2(MEA_STR_ID_SAVE_AS_TEMPLATE,"Save as template","Save as template");
#endif /*__MMI_MMS_V01_TEMPLATES_SUPPORT__*/
	ADD_APPLICATION_STRING2(MEA_STR_ID_SAVE_TO_PHONE_BOOK,"Save To Phone Book","Save To Phone Book");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_SEC_PORT,"Secure port","Secure port");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SELECT,"Select","Select");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SEND,"Send","Send");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SENDING_MSG,"Sending MMS","Sending MMS");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SEND_OPTIONS,"Send Options","Send Options");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SEND_ONLY,"Send Only","Send Only");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SENT,"Sent","Sent");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SLIDE_LIMIT_REACHED,"Maximum number of slides reached!","Maximum number of slides reached!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_STATUS,"Status:","Status:");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SUBJECT,"Subject: ","Subject: ");
#ifdef __MMI_MMS_V01_TEMPLATES_SUPPORT__	
	ADD_APPLICATION_STRING2(MEA_STR_ID_TEMPLATES,"Template","Template");
#endif /*__MMI_MMS_V01_TEMPLATES_SUPPORT__*/
	ADD_APPLICATION_STRING2(MEA_STR_ID_TO,"To:","To:");
	ADD_APPLICATION_STRING2(MEA_STR_ID_TO_MANY_RECIPIENTS,"To many recipients.","To many recipients.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_UNKOWN,"Unknown.","Unknown.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_UNRECOGNIZED,"Unrecognized.","Unrecognized.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_USE_DETAILS,"Use Details","Use Details");
	ADD_APPLICATION_STRING2(MEA_STR_ID_VIEW,"View","View");
    ADD_APPLICATION_STRING2(MEA_STR_ID_REVIEW,"View from start","View from start");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_VIEW_ATTACHMENTS,"View attachments","View attachments");
	ADD_APPLICATION_STRING2(MEA_STR_ID_VIEW_TITLE,"View message","View message");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_WAP_GATEWAY,"WAP gateway","WAP gateway");
	ADD_APPLICATION_STRING2(MEA_STR_ID_WRITE_MESSAGE,"Write Message","Write Message");
	ADD_APPLICATION_STRING2(MEA_STR_ID_WRITE_MMS,"Write MMS","Write MMS");
	ADD_APPLICATION_STRING2(MEA_STR_ID_WRONG_MESSAGE_TYPE,"Unsupported message type!","Unsupported message type!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_YES,"Yes","Yes");
	ADD_APPLICATION_STRING2(MEA_STR_ID_RE,"RE: ","RE: ");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FW,"FW: ","FW: ");
	ADD_APPLICATION_STRING2(MEA_STR_ID_MESSAGE_SIZE_MAXIMUM_REACHED,"Maximum message size reached","Maximum message size reached");
    //ADD_APPLICATION_STRING2(MEA_STR_ID_MESSAGE_SIZE_WARNING,"Recipient may not be able to view large MMS","Recipient may not be able to view large MMS");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CREATION_MODE_MAX_MESSAGE_SIZE_REACHED,"Creation mode, message size exceeds","Creation mode, message size exceeds");
#ifdef __MMS_SIZE_CONFIRM_BEFORE_SEND__
/* under construction !*/
/* under construction !*/
#endif /*__MMS_SIZE_CONFIRM_BEFORE_SEND__*/
	ADD_APPLICATION_STRING2(MEA_STR_ID_DOWNLOAD_EXPIRED_MM_CONFIRM,"The MM is expired. Download it?","The MM is expired. Download it?");
#ifdef __MMI_MMS_BGSR_SUPPORT__
	ADD_APPLICATION_STRING2(MEA_STR_ID_DOWNLOAD_EXPIRED_MM_PROHIBIT,"The MM is expired.","The MM is expired.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_SOS,"Auto save","Auto save");
#endif
	ADD_APPLICATION_STRING2(MEA_STR_ID_REPLY_CHARGING,"Reply charging","Reply charging");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REPLY_CHARGING_DEADLINE,"Reply charging deadline","Reply charging deadline");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REPLY_CHARGING_SIZE,"Reply charging size","Reply charging size");
	ADD_APPLICATION_STRING2(MEA_STR_ID_TEXT_ONLY,"Text only","Text only");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_1_KB,"1 KB","1 KB");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_10_KB,"10 KB","10 KB");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SELECT_COLOR,"Select color","Select color");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_BG_COLOR,"Background color","Background color");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_MSG_RETR_HOME_MODE,"Home network","Home network");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_MSG_RETR_ROAM_MODE,"Roaming network","Roaming network");
	ADD_APPLICATION_STRING2(MEA_STR_ID_AUTO_RETRIEVAL_ROAM,"Automatic","Automatic");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ASK_RETRIEVAL_ROAM,"Ask","Ask");
	ADD_APPLICATION_STRING2(MEA_STR_ID_RES_RETRIEVAL_ROAM,"Rejected","Rejected");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_SEND_VISIBILITY,"Sender visibility","Sender visibility");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_HIDE_NUMBER,"Show number","Show number");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_SHOW_NUMBER,"Hide number","Hide number");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_SEND_READ_REPORT,"Send Read Report","Send Read Report");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_ALWAYS,"Always","Always");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_ON_REQUEST,"On request","On request");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_NEVER,"Never","Never");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_DELIVERY_TIME,"Delivery time","Delivery time");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_IMMEDIATE,"Immediate","Immediate");
#ifdef __OP01_MMS_RETRIEVE_SETTING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_IN_ONE_HOUR,"1 hour later","In 1 hour later");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_IN_12_HOURS,"12 hours later","12 hours later");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_IN_24_HOURS,"24 hours later","24 hours later");
	ADD_APPLICATION_STRING2(MEA_STR_ID_PLAY_SOUND,"Play Audio","Play Audio");
#ifdef __MMI_MMS_VIDEO_FEATURE__	
	ADD_APPLICATION_STRING2(MEA_STR_ID_PLAY_VIDEO,"Play Video","Play Video");
#endif
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_DELIVERY_REPORT_ALLOWED,"Delivery report allowed","Delivery report allowed");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADD_AUDIO,"Add Audio","Add Audio");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_TEXT_COLOR,"Add text color","Add text color");
	ADD_APPLICATION_STRING2(MEA_STR_ID_BCC,"Bcc:","Bcc:");
	ADD_APPLICATION_STRING2(MEA_STR_ID_TEXT_MISSING,"The text can not be displayed","The text can not be displayed");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_SINGLE_OBJECT_SIZE_WARNING,"Recipient may not be able to view large media","Recipient may not be able to view large media");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_INSERT_DRM,"Failed to insert DRM object","Failed to insert DRM object");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_RESIZE_IMAGE,"Failed to resize image","Failed to resize image");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ROAM_DOWNLOAD_REQ1,"You are currently not in your home network and there might be additional charges on transactions. Do you want to download the message with size","You are currently not in your home network and there might be additional charges on transactions. Do you want to download the message with size");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ROAM_DOWNLOAD_REQ2,"K?","K?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ROAM_SEND_REQ1,"You are currently not in your home network and there might be additional charges on transactions. Do you want to send the message with size ","You are currently not in your home network and there might be additional charges on transactions. Do you want to send the message with size ");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ROAM_SEND_REQ2,"K?","K?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INVALID_NETWORK_SETTINGS,"Your network settings are invalid. Please check MMSC and WAP settings","Your network settings are invalid. Please check MMSC and WAP settings");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_CALL_BUSY,"The called party is busy","The called party is busy");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CALL_NO_NETWORK,"The network is not available","The network is not available");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_CALL_NO_ANSWER,"The called party did not answer","The called party did not answer");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_CALL_NOT_A_NUMBER,"Invalid number","Invalid number");	//
	ADD_APPLICATION_STRING2(MEA_STR_ID_CALL_ERROR,"Could not place call","Could not place call");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_UNHANDLED_LINK,"Cannot handle this link","Cannot handle this link");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_GET_MESSAGE_INFO,"Failed to open original message","Failed to open original message");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_OPEN_WINDOW,"Failed to open window","Failed to open window");
	ADD_APPLICATION_STRING2(MEA_STR_ID_MAX_NUMBER_OF_MSG,"Max number of stored messages reached. Please delete messages.","Storage Full for New Incoming MMS!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_SEND_REFUSED,"The message was not accepted by the server due to size or some other reason.","Not accepted by the server.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NUMBER_OF_MSG_WARNING,"Near max number of stored messages. Please delete messages.","Near max number of stored MMS. Please delete messages.");

	ADD_APPLICATION_STRING2(MEA_STR_ID_REMOVE_INVALID_NUMBER,"Invalid Number Removed","Invalid Number Removed");
#if (defined(__MMI_MMS_IN_UM__) && defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__))
    ADD_APPLICATION_STRING2(MEA_STR_ID_MOVE_TO_ARCHIVE, "Move to archive", "Move to archive");
    ADD_APPLICATION_STRING2(MEA_STR_ID_MOVE_TO_ARCHIVE_QUERY, "Move to archive?", "Move to archive?");    
	ADD_APPLICATION_STRING2(MEA_STR_ID_DELETE_ALL_ARCHIVE,"Delete All Archive?","Delete All Archive?");
#endif
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADDRESS_ALREADY_EXISTS,"Address Already Exists","Address Already Exists");
    ADD_APPLICATION_STRING2(MEA_STR_ID_ATTACH_MAXIMUM_REACHED,"Maximum attachment number reached", "Maximum attachment number reached");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADD_ATTACHMENT,"Add Attachment","Add Attachment");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ATTACHMENT_REMOVED,"Attachment was removed","Attachment was removed");
	ADD_APPLICATION_STRING2(MEA_STR_ID_AUTO_SIGNATURE,"Auto Signature","Auto Signature");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SIGNATURE,"Signature","Signature");	
	ADD_APPLICATION_STRING2(MEA_STR_ID_AUTO_SIGNATURE_ERROR_TOO_MANY_SLIDES,"No Signature Due to Too Many Slides","No Signature Due to Too Many Slides");
	ADD_APPLICATION_STRING2(MEA_STR_ID_AUTO_SIGNATURE_ERROR_SIZE_TOO_LARGE,"No Signature Due to Size Too Large","No Signature Due to Size Too Large");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_COMPOSE,"Compose","Compose");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CREATION_MODE,"Creation Mode","Creation Mode");
#if defined(MMS_SUPPORT) && !(defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))
		ADD_APPLICATION_STRING2(MEA_STR_ID_BEST_SLIDE_DURATION,"Best Slide Duration","Best Slide Duration");
#endif
	ADD_APPLICATION_STRING2(MEA_STR_ID_CREATION_MODE_FREE,"Free","Free");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CREATION_MODE_RESTRICTED,"Restricted","Restricted");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CREATION_MODE_WARNING,"Warning","Warning");
	ADD_APPLICATION_STRING2(MEA_STR_ID_RESTRICTED_MIME_ACTION_NONE,"Prohibited by creation mode", "Prohibited by creation mode");
	ADD_APPLICATION_STRING2(MEA_STR_ID_RESTRICTED_MODE_REMOVE_OBJ_REQ,"Restricted object(s), remove?","Restricted object(s), remove?");
    ADD_APPLICATION_STRING2(MEA_STR_ID_RESTRICTED_MODE_FAIL_TO_EDIT,"Restricted mode: edit prohibited","Restricted mode: edit prohibited");
    ADD_APPLICATION_STRING2(MEA_STR_ID_RESTRICTED_MODE_FAIL_TO_SEND,"Restricted mode: send prohibited","Restricted mode: send prohibited");
    ADD_APPLICATION_STRING2(MEA_STR_ID_RESTRICTED_MODE_FAIL_TO_FORWARD,"Restricted mode: forward prohibited","Restricted mode: forward prohibited");
	ADD_APPLICATION_STRING2(MEA_STR_ID_WARNING_MODE_CONFIRM,"Restricted object(s), continue?","Restricted object(s), continue?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_IMAGE_RESIZE,"Image Resizing","Image Resizing");
#ifdef JPG_ENCODE
#if !(defined(__MMI_MMS_MAX_IMAGE_RESIZING_RESOLUTION__) && (__MMI_MMS_MAX_IMAGE_RESIZING_RESOLUTION__ == __320x240__))
    ADD_APPLICATION_STRING2(MEA_STR_ID_640x480,"640x480","640x480");
#endif
#endif
	ADD_APPLICATION_STRING2(MEA_STR_ID_320x240,"320x240","320x240");
	ADD_APPLICATION_STRING2(MEA_STR_ID_160x120,"160x120","160x120");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DELETE_ALL_INBOX,"Delete All Inbox?","Delete All Inbox?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DELETE_ALL_OUTBOX,"Delete All Outbox?","Delete All Outbox?");
#ifdef __MMI_MMS_V01_TEMPLATES_SUPPORT__	
	ADD_APPLICATION_STRING2(MEA_STR_ID_DELETE_ALL_TEMPLATE,"Delete all Templates?","Delete all Templates?");
#endif /*__MMI_MMS_V01_TEMPLATES_SUPPORT__*/
	ADD_APPLICATION_STRING2(MEA_STR_ID_DELETE_ALL_SENT,"Delete All Sent?","Delete All Sent?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DELETE_ALL_DRAFTS,"Delete All Drafts?","Delete All Drafts?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DIAL,"Dial","Dial");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EDIT_ATTACHMENT,"Edit Attachment","Edit Attachment");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EDIT_PROFILE,"Profiles","Profiles");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FREE, "Free Space: ","Free Space: ");
	ADD_APPLICATION_STRING2(MEA_STR_ID_LSK_READ,"Read","Read");
	ADD_APPLICATION_STRING2(MEA_STR_ID_LSK_YES,"Yes","Yes");
	ADD_APPLICATION_STRING2(MEA_STR_ID_MEMORY_STATUS,"Memory Status","Memory Status");
	ADD_APPLICATION_STRING2(MEA_STR_ID_MSG,"msg","msg");
	ADD_APPLICATION_STRING2(MEA_STR_ID_MSGS,"msgs","msgs");
    ADD_APPLICATION_STRING2(MEA_STR_ID_NO_CONTENT, "No Content", "No Content");
#ifdef __MMI_KLG__
	ADD_APPLICATION_STRING2(MEA_STR_ID_NO_NUMBER, "No Number!", "No Number!");
#endif
	ADD_APPLICATION_STRING2(MEA_STR_ID_NO_SUBJECT, "(No Subject)", "(No Subject)");
	ADD_APPLICATION_STRING2(MEA_STR_ID_PLY_SMIL_BUSY,"System Busy","System Busy");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REMOVE_ATTACHMENT,"Remove Attachment","Remove Attachment");
	ADD_APPLICATION_STRING2(MEA_STR_ID_RESEND,"Resend","Resend");
	ADD_APPLICATION_STRING2(MEA_STR_ID_RSK_NO,"No","No");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SAVED_AND_SENT,"Saved and Sent","Saved and Sent");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SAVE_TO_DRAFTS,"Save to Draft","Save to Draft");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SLIDE,"slide","slide");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SLIDES,"slides","slides");
	ADD_APPLICATION_STRING2(MEA_STR_ID_STORAGE_FULL,"Storage Full!","Storage Full!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_TOO_MANY_CONNECTIONS,"Too many connections","Too many connections");
	ADD_APPLICATION_STRING2(MEA_STR_ID_TOTAL,"Used Space: ","Used Space: ");
	ADD_APPLICATION_STRING2(MEA_STR_ID_USAGE,"Usage: ","Usage: ");
#ifdef __MMI_MMS_V01_TEMPLATES_SUPPORT__	
	ADD_APPLICATION_STRING2(MEA_STR_ID_TEMPLATE_CORRUPT,"The template is corrupted","The template is corrupted");
#endif /*__MMI_MMS_V01_TEMPLATES_SUPPORT__*/
	ADD_APPLICATION_STRING2(MEA_STR_ID_MESSAGE_CORRUPT,"Message may be corrupted. Please remove it.","Message may be corrupted. Please remove it.");
#ifdef __MMI_MMS_IN_UM__
	ADD_APPLICATION_STRING2(MEA_STR_ID_REMOVE_CORRUPT_MESSAGE_REQ,"Message corrupted. Remove it?","Message corrupted. Remove it?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_WRITE_SMS,"Write SMS","Write SMS");
    ADD_APPLICATION_STRING2(MEA_STR_ID_UM_MSG, "msg", "msg");
    ADD_APPLICATION_STRING2(MEA_STR_ID_UM_MSGS, "msgs", "msgs");
#endif
	ADD_APPLICATION_STRING2(MEA_STR_ID_SERVER,"Server","Server");
#ifdef __MMI_MMS_BGSR_SUPPORT__
	ADD_APPLICATION_STRING2(MEA_STR_ID_MINS,"Mins","Mins");
    ADD_APPLICATION_STRING2(MEA_STR_ID_MESSAGE_IS_IN_USE, "The message is in use", "The message is in use");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SHOW_STATUS,"Status","Status");
	ADD_APPLICATION_STRING2(MEA_STR_ID_MOVE_TO_DRAFT_QUERY,"Move To Draft?","Move To Draft?");	
	ADD_APPLICATION_STRING2(MEA_STR_ID_WAITING,"Waiting","Waiting");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NEXT_TRANS_TIME,"Next Transmission Time","Next Transmission Time");
	ADD_APPLICATION_STRING2(MEA_STR_ID_MOVE_TO_DRAFT,"Move To Draft","Move To Draft");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REMAIN_QUOTA,"The Remaining Quota","The Remaining Quota");
#endif

       //ADD_APPLICATION_STRING2(MEA_STR_ID_TEMPLATES_FOLDER_LIST, "MMS Templates", "MMS Templates");
    ADD_APPLICATION_STRING2(MEA_STR_ID_NUMBER_TOO_LONG, "Maximum number length exceeded", "Maximum number length exceeded");
#ifdef __MMI_MMS_V01_TEMPLATES_SUPPORT__	
#ifdef __MMI_OBIGO_Q03C_MMS_USER_DEFINED_TEMPLATES__
    ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_ENTER_DEF_TEMPLATE, "Enter template fail", "Enter template fail");
    ADD_APPLICATION_STRING2(MEA_STR_ID_DEFAULT_TEMPLATES, "Default", "Default");
    ADD_APPLICATION_STRING2(MEA_STR_ID_USER_TEMPLATES, "User Defined", "User Defined");
    ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_SAVE_AS_TEMPLATE, "Failed to Save Template!", "Failed to Save Template!");
#endif
#endif /*__MMI_MMS_V01_TEMPLATES_SUPPORT__*/
    ADD_APPLICATION_STRING2(MEA_STR_ID_COLON, ":", ":");
    ADD_APPLICATION_STRING2(MEA_STR_ID_CALL_IN_PROGRESS, "Failed due to call in progress", "Send 0r Download fail due to call in progress");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADDRESS_TOO_LONG, "Maximum address length exceeded", "Maximum address length exceeded");
    ADD_APPLICATION_STRING2(MEA_STR_ID_COMMON_SETTINGS, "Common Settings", "Common Settings");
    ADD_APPLICATION_STRING2(MEA_STR_ID_UNREAD, "unread", "unread");
    ADD_APPLICATION_STRING2(MEA_STR_ID_URL_TOOLONG, "URL too long", "URL too long");
	
    ADD_APPLICATION_STRING2(MEA_STR_ID_INVALID_DTCNT_ASK_CFG, "Invalid data account. Configure?", "Invalid data account. Configure?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ERROR_GPRS_UNKNOWN_APN,"APN error","Acess point name (APN) error");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ERROR_GPRS_AUTHENTICATION_FAILURE,"GPRS authentication error","GPRS authentication error");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ERROR_GPRS_UNSUPPORTED_SERVICE_OPTION,"GPRS not support","GPRS not support");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ERROR_GPRS_UNSUBSCRIBED_SERVICE_OPTION,"GPRS not subscribed","GPRS not subscribed");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ERROR_COMMUNICATION,"Error in communication","Error in communication");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INVALID_URL,"Invalid URL","Invalid URL");
    ADD_APPLICATION_STRING2(MEA_STR_ID_SAVED, "Saved", "Someting is already saved");
    ADD_APPLICATION_STRING2(MEA_STR_ID_SAVE_ASK, "Save?", "Save?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DELETED,"Deleted","Deleted");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DELETE_ALL_ASK,"Delete all?","Delete all?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_GOTO,"Goto","Goto or visit a URL");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADD_TO_BOOKMARKS,"Add to bookmarks","Add to bookmarks");
    ADD_APPLICATION_STRING2(MEA_STR_ID_CANCEL_PROV, "Cancel?", "Cancel?");

	//////////////////////////////////////////////////////
	ADD_APPLICATION_STRING2(MMS_STR_ID_EMPTY_STRING," "," ");
	ADD_APPLICATION_STRING2(MMS_STR_ID_RR_TEXT_FROM,"From:","From:");
	ADD_APPLICATION_STRING2(MMS_STR_ID_RR_TEXT_MSGID,"Message ID:","Message ID:");
	ADD_APPLICATION_STRING2(MMS_STR_ID_RR_TEXT_READ,"READ:","READ:");
	ADD_APPLICATION_STRING2(MMS_STR_ID_RR_TEXT_SENT,"Sent:","Sent:");
	ADD_APPLICATION_STRING2(MMS_STR_ID_RR_TEXT_SUBJECT,"Subject:","Subject:");
	ADD_APPLICATION_STRING2(MMS_STR_ID_RR_TEXT_TO,"To:","To:");
	ADD_APPLICATION_STRING2(MMS_STR_ID_RR_TEXT_WAS_READ,"\\nwas read on ","\\nwas read on ");
	ADD_APPLICATION_STRING2(MMS_STR_ID_RR_TEXT_YOUR_MSG,"Your message\\n","Your message\\n");
#ifdef __MMI_MMS_V01_TEMPLATES_SUPPORT__	
#if (__MMI_MMS_TEMPLATES_NUM__>0)
	ADD_APPLICATION_STRING2(MMS_STR_ID_TEMPLATES_TITLE_01,"Happy birthday","Happy birthday");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>1)
	ADD_APPLICATION_STRING2(MMS_STR_ID_TEMPLATES_TITLE_02,"Call me","Call me");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>2)
	ADD_APPLICATION_STRING2(MMS_STR_ID_TEMPLATES_TITLE_03,"Take care","Take care");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>3)
	ADD_APPLICATION_STRING2(MMS_STR_ID_TEMPLATES_TITLE_04,"I am busy now","I am busy now");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>4)
	ADD_APPLICATION_STRING2(MMS_STR_ID_TEMPLATES_TITLE_05,"I'll be late","I'll be late");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>5)
	ADD_APPLICATION_STRING2(MMS_STR_ID_TEMPLATES_TITLE_06,"Miss you","Miss you");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>6)
	ADD_APPLICATION_STRING2(MMS_STR_ID_TEMPLATES_TITLE_07,"Thank you","Thank you");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>7)
	ADD_APPLICATION_STRING2(MMS_STR_ID_TEMPLATES_TITLE_08,"Where are you?","Where are you?");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>8)
	ADD_APPLICATION_STRING2(MMS_STR_ID_TEMPLATES_TITLE_09,"The appointment is cancelled","The appointment is cancelled");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>9)
	ADD_APPLICATION_STRING2(MMS_STR_ID_TEMPLATES_TITLE_10,"Everything is OK","Everything is OK");
#endif
#endif /*__MMI_MMS_V01_TEMPLATES_SUPPORT__*/
#endif /* OBIGO_Q03C_MMS_V01 */

	//////////////////////////////////////////////////////
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_ACTION_OK,"Ok","Ok");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_ACTION_BACK,"Back","Back");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_ACTION_CANCEL,"Cancel","Cancel");
	#if 0
/* under construction !*/
    #endif
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_TEXT_EDIT_FILENAME,"Edit filename","Edit filename");
	#if 0
/* under construction !*/
/* under construction !*/
	#endif
	#ifndef WAP_SUPPORT
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_EXISTS_TEXT1,"","");
	#endif
	#if 0
/* under construction !*/
    #endif
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_EXISTS_TITLE,"File exists","File exists");
	#ifndef WAP_SUPPORT
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_NO_REPLACE_TEXT1,"","");
	#endif
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_NO_REPLACE_TEXT2,"  exists and cannot be replaced.","  exists and cannot be replaced.");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_SAVE_ERROR,"Save Error","Save Error");
	#ifdef SLIM_WAP_MMS
	#if 0
/* under construction !*/
	#endif
	#endif
	#if 0
/* under construction !*/
/* under construction !*/
	#endif
	ADD_APPLICATION_STRING2(MSF_STR_ID_SAS_ACTION_CANCEL,"Cancel","Cancel");
	#if 0
/* under construction !*/
    #endif
	ADD_APPLICATION_STRING2(MSF_STR_ID_SAS_ERROR_FULL,"Not enough memory","indicate user storage is too small to save large content");
	ADD_APPLICATION_STRING2(MSF_STR_ID_SAS_ERROR_SIZE,"File size exceeds maximum value","File size exceeds maximum value");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DAS_MEMORY_NOT_ENOUGH,"Memory not enough","Memory not enough");
	ADD_APPLICATION_STRING2(MSF_STR_ID_MIME_ACTION_SAVE,"Save As","Save As");
	#if 0
/* under construction !*/
    #endif
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_MIME_ACTION_NONE,"Unsupported content.", "Unsupported content.");
	#ifndef WAP_SUPPORT
	ADD_APPLICATION_STRING2(MSF_STR_ID_MIME_ACTION_SET_RINGTONE,"Set ringtone", "Set ringtone");
	#endif
#if 0
/* under construction !*/
#endif
	ADD_APPLICATION_STRING2(MSF_STR_ID_DAY_MONDAY_SHORT,"Mon", "Mon");
	ADD_APPLICATION_STRING2( MSF_STR_ID_DAY_TUESDAY_SHORT,"Tue", "Tue");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DAY_WEDNESDAY_SHORT,"Wed", "Wed");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DAY_THURSDAY_SHORT,"Thu", "Thu");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DAY_FRIDAY_SHORT,"Fri", "Fri");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DAY_SATURDAY_SHORT,"Sat", "Sat");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DAY_SUNDAY_SHORT,"Sun", "Sun");
	ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_JANUARY_SHORT,"Jan", "Jan");
	ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_FEBRUARY_SHORT,"Feb", "Feb");
	ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_MARCH_SHORT,"Mar", "Mar");
	ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_APRIL_SHORT,"Apr", "Apr");
	ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_MAY_SHORT,"May", "May");
	ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_JUNE_SHORT,"Jun", "Jun");
	ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_JULY_SHORT,"Jul", "Jul");
	ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_AUGUST_SHORT,"Aug", "Aug");
	ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_SEPTEMBER_SHORT,"Sep", "Sep");
	ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_OCTOBER_SHORT,"Oct", "Oct");
	ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_NOVEMBER_SHORT,"Nov", "Nov");	
	ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_DECEMBER_SHORT,"Dec", "Dec");
	ADD_APPLICATION_STRING2(MSF_STR_ID_INTERNAL_ERROR,"Internal error","Internal error");	
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	

	//////////////////////////////////////////////////////
	//ADD_APPLICATION_STRING2(PHS_STR_ID_ACCEPT_MSG,"Accept push","Accept push");
	//ADD_APPLICATION_STRING2(PHS_STR_ID_CANCEL,"Cancel","Cancel");
	//ADD_APPLICATION_STRING2(PHS_STR_ID_DECLINE_MSG,"Decline push","Decline push");
	//ADD_APPLICATION_STRING2(PHS_STR_ID_NO_WHITELIST_MSG,"Push from unauthorised sender","Push from unauthorised sender");
	//ADD_APPLICATION_STRING2(PHS_STR_ID_OK,"Ok","Ok");
	//ADD_APPLICATION_STRING2(PHS_STR_ID_SIA_CONFIRM_MSG,"Would you like to set up a new push connection?","Would you like to set up a new push connection?");
	/*ADD_APPLICATION_STRING2(PRS_STR_ID_CANCEL,"Cancel","Cancel");
	ADD_APPLICATION_STRING2(PRS_STR_ID_ENTER_PIN,"Enter the PIN","Enter the PIN");
	ADD_APPLICATION_STRING2(PRS_STR_ID_ENTER_PIN_AGAIN,"Wrong PIN Code!","Wrong PIN Code!");
	ADD_APPLICATION_STRING2(PRS_STR_ID_OK,"Ok","Ok");
	ADD_APPLICATION_STRING2(PRS_STR_ID_PIN_TITLE,"PIN Dialog","PIN Dialog");
	*/
	//////////////////////////////////////////////////////
	
#ifdef WAP_SEC_SUPPORT
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT1,"Store unknown certificate?","Store unknown certificate?");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT10,"No trusted certificate, continue?","No trusted certificate, continue?");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT11,"No user certificate, continue?","No user certificate, continue?");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT14,"Could not show the certificate","Could not show the certificate");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT15,"Could not delete the certificate","Could not delete the certificate");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT16,"No trusted certificate. continue?","No trusted certificate. continue?");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT17,"Cannot store the certificate","Cannot store the certificate");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT18,"Unknown server, continue?","Unknown server, continue?");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT19,"Error in certificate. continue?","Error in certificate. continue?");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT2,"Overwrite existing same certificate?","Overwrite existing same certificate?");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT3,"Overwrite existing old certificate?","Overwrite existing old certificate?");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT4,"Overwrite existing new certificate?","Overwrite existing new certificate?");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT5,"The certificate has been stored.","The certificate has been stored.");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT7,"Remove existing old trust certificate?","Remove existing old trust certificate?");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CHOOSE_CERT_TITLE,"Choose a certificate:","Choose a certificate:");
	ADD_APPLICATION_STRING2(SEC_STR_ID_EMPTY," "," ");
	ADD_APPLICATION_STRING2(SEC_STR_ID_OK,"Ok","Ok");
	ADD_APPLICATION_STRING2(SEC_STR_ID_NO, "No", "No");
	ADD_APPLICATION_STRING2(SEC_STR_ID_YES,"Yes", "Yes");
	ADD_APPLICATION_STRING2(SEC_STR_ID_STORE_CERT,"Store this certificate?","Store this certificate?");
#endif /* WAP_SEC_SUPPORT */
	
	//////////////////////////////////////////////////////
#if defined(OBIGO_Q03C_MMS_V01)
	ADD_APPLICATION_STRING2(SMA_STR_ID_BACK,"Back","Back");
	ADD_APPLICATION_STRING2(SMA_STR_ID_EMPTY_STRING," "," ");
	ADD_APPLICATION_STRING2(SMA_STR_ID_ERR_NO_MEMORY,"Not enough persistent storage.","Not enough persistent storage.");
	ADD_APPLICATION_STRING2(SMA_STR_ID_ERR_WRITING_FILE,"Error writing file.","Error writing file.");
	ADD_APPLICATION_STRING2(SMA_STR_ID_LINKS,"Links","Links");
	ADD_APPLICATION_STRING2(SMA_STR_ID_MENU_NEXT,"Next page","Next page");
	ADD_APPLICATION_STRING2(SMA_STR_ID_MENU_PLAY,"Play","Play");
	ADD_APPLICATION_STRING2(SMA_STR_ID_MENU_PREVIOUS,"Previous page","Previous page");
	ADD_APPLICATION_STRING2(SMA_STR_ID_MENU_SAVE_AUDIO,"Save audio","Save audio");
	ADD_APPLICATION_STRING2(SMA_STR_ID_MENU_SAVE_IMAGE,"Save image","Save image");
	ADD_APPLICATION_STRING2(SMA_STR_ID_OK,"Ok","Ok");
	ADD_APPLICATION_STRING2(SMA_STR_ID_SLIDE_ACTION_EXIT,"Exit","Exit");
	//ADD_APPLICATION_STRING2(SMA_STR_ID_SLIDE_ACTION_OK," "," ");
	ADD_APPLICATION_STRING2(SMA_STR_ID_SLIDE_ACTION_PLAY,"Play","Play");
	ADD_APPLICATION_STRING2(SMA_STR_ID_SLIDE_ACTION_STOP,"Stop","Stop");
	ADD_APPLICATION_STRING2(SMA_STR_ID_SLIDE_MENU_ACTION_BACK,"Back","Back");
	//ADD_APPLICATION_STRING2(SMA_STR_ID_SLIDE_MENU_ACTION_SELECT,"Select","Select");
	ADD_APPLICATION_STRING2(SMA_STR_ID_UNKNOWN_TEXT,"The text could not be displayed.","The text could not be displayed.");
	ADD_APPLICATION_STRING2(SMA_STR_ID_MENU_SAVE_OBJECT,"Save Object","Save Object");
	ADD_APPLICATION_STRING2(SMA_STR_ID_MENU_SAVE_VIDEO,"Save video","Save video");
        ADD_APPLICATION_STRING2(SMA_STR_ID_MENU_SAVE_TEXT,"Save text","Save text");
	ADD_APPLICATION_STRING2(SMA_STR_ID_FAILED_TO_SAVE,"Failed to save the media object.","Failed to save the media object.");
	ADD_APPLICATION_STRING2(SMA_STR_ID_FAILED_TO_SAVE_DRM,"The object is protected and cannot be saved.","The object is protected and cannot be saved.");
	ADD_APPLICATION_STRING2(SMA_STR_ID_ATTACHMENTS,"View attachments","View attachments");
	ADD_APPLICATION_STRING2(SMA_STR_ID_ATTACHMENT_LIST,"Attachment List","Attachment List");
	//ADD_APPLICATION_STRING2(SMA_STR_ID_CALL_BUSY,"Called party is busy","Called party is busy");
	ADD_APPLICATION_STRING2(SMA_STR_ID_CALL_FAILED,"Call failed","Call failed");
	ADD_APPLICATION_STRING2(SMA_STR_ID_UI_OPEN,"Open ","Open ");
	ADD_APPLICATION_STRING2(SMA_STR_ID_UI_CALL,"Call ","Call ");
	ADD_APPLICATION_STRING2(SMA_STR_ID_NOT_ABLE_PLAY_ALL_SLIDES,"Not able to play all slides ","Not able to play all slides ");
  //  ADD_APPLICATION_STRING2(SMA_STR_ID_NO_FIT_OBJECT,"No fit file can be saved","No fit file can be saved");
#endif /* OBIGO_Q03C_MMS_V01 */
	//////////////////////////////////////////////////////
#ifndef WAP_SUPPORT
	ADD_APPLICATION_STRING2(STK_STR_ID_EXIT,"Exit","Exit");
	ADD_APPLICATION_STRING2(STK_STR_ID_NON_SECURE,"Warning: Transmitted unprotected!","Warning: Transmitted unprotected!");
	ADD_APPLICATION_STRING2(STK_STR_ID_PASSWORD,"Password:","Password:");
	ADD_APPLICATION_STRING2(STK_STR_ID_REALM_LABEL,"Realm:","Realm:");
	ADD_APPLICATION_STRING2(STK_STR_ID_SAVE_PASSWORD,"Save Username and Password","Save Username and Password");
	ADD_APPLICATION_STRING2(STK_STR_ID_SAVE_USERNAME,"Save Username","Save Username");
	ADD_APPLICATION_STRING2(STK_STR_ID_OK,"Ok","Ok");
	ADD_APPLICATION_STRING2(STK_STR_ID_TITLE_PROXY,"Enter Proxy Password","Enter Proxy Password");
	ADD_APPLICATION_STRING2(STK_STR_ID_TITLE_SERVER,"Enter Server Password","Enter Server Password");
	ADD_APPLICATION_STRING2(STK_STR_ID_USERNAME,"UserName:","UserName:");
#endif /* WAP_SUPPORT */
	//////////////////////////////////////////////////////
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_CANCEL,"Cancel","Cancel");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_CANT_INPUT_EMPTY_VALUE,"Cannot input empty value!","Cannot input empty value!");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_CANT_SWITCH_INPUT_METHOD, "Can't set input method", "Can't set input method");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_DONE,"Done","Done");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_INPUT_FORMAT_ERROR,"Invalid number!","Invalid number!");
	#if 0
/* under construction !*/
    #endif
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_INPUT_TITLE,"Input","Input");
	#if 0
/* under construction !*/
    #endif
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_OPTION,"Option","Option");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_SAVEAS_NAME_INVALID_CHARS,"Please input alphabets and numbers only","Please input alphabets and numbers only");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_PLEASE_WAIT, "Please Wait", "Please Wait");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_IMAGE_RESIZE, "Resizing image", "Resizing image");
#ifdef __OBIGO_Q03C_MMS_V01__
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_SEARCH, "Search", "Search");
#endif
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_PUSH, "New Service Message", "Push message prompt");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_PROVISION, "New Settings", "Provision message prompt");
#ifdef __MMI_WAP_DUAL_SIM__
#if 0
/* under construction !*/
/* under construction !*/
#endif
#endif
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_MMS_MSG, "New MMS Message", "MMS message prompt");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_JAVA_MMS_MSG, "New JAVA MMS Message", "JAVA MMS message prompt");
#ifdef __MMI_WAP_DUAL_SIM__
#ifdef __OBIGO_Q03C_MMS_V01__
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_MMS_MSG_SIM_1, "New MMS Message(SIM 1)", "MMS message prompt(SIM 1)");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_MMS_MSG_SIM_2, "New MMS Message(SIM 2)", "MMS message prompt(SIM 2)");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_JAVA_MMS_MSG_SIM_1, "New JAVA MMS Message(SIM 1)", "JAVA MMS message prompt(SIM 1)");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_JAVA_MMS_MSG_SIM_2, "New JAVA MMS Message(SIM 2)", "JAVA MMS message prompt(SIM 2)");
#endif 
#if 0
/* under construction !*/
/* under construction !*/
#endif
#endif
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_MMS_NOTIFICATION, "New MMS Message", "MMS notification prompt");
#ifdef __MMI_WAP_DUAL_SIM__
#ifdef __OBIGO_Q03C_MMS_V01__
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_MMS_NOTIFICATION_SIM_1, "New MMS Message(SIM 1)", "MMS notification prompt(SIM 1)");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_MMS_NOTIFICATION_SIM_2, "New MMS Message(SIM 2)", "MMS notification prompt(SIM 2)");    
#endif
#endif
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_MMS_READ_REPORT, "New MMS Report", "MMS report prompt");
#ifdef __MMI_WAP_DUAL_SIM__
#ifdef __OBIGO_Q03C_MMS_V01__
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_MMS_READ_REPORT_SIM_1, "New MMS Report(SIM 1)", "MMS report prompt(SIM 1)");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_MMS_READ_REPORT_SIM_2, "New MMS Report(SIM 2)", "MMS report prompt(SIM 2)");    
#endif
#endif
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_MMS_DELIVERY_REPORT, "New MMS Report", "MMS report prompt");
#ifdef __MMI_WAP_DUAL_SIM__
#ifdef __OBIGO_Q03C_MMS_V01__
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_MMS_DELIVERY_REPORT_SIM_1, "New MMS Report(SIM 1)", "MMS report prompt(SIM 1)");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_MMS_DELIVERY_REPORT_SIM_2, "New MMS Report(SIM 2)", "MMS report prompt(SIM 2)");    
#endif
#endif
#ifdef __MMI_WCSS_INPUT_FORMAT_SUPPORT__
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_INVALID_WCSS__UPPERCASE_A, "invalid WCSS format - A", "invalid WCSS format - A");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_INVALID_WCSS__LOWERCASE_A, "invalid WCSS format - a", "invalid WCSS format - a");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_INVALID_WCSS__UPPERCASE_X, "invalid WCSS format - X", "invalid WCSS format - X");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_INVALID_WCSS__LOWERCASE_X, "invalid WCSS format - x", "invalid WCSS format - x");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_INVALID_WCSS__LOWERCASE_N, "invalid WCSS format - n", "invalid WCSS format - n");
#endif
    ADD_APPLICATION_STRING2(WIDGET_STR_ID_INPUT_EMAIL_ERROR,"Invalid Email address","Invalid Email address");	

	/* workaround */
	ADD_APPLICATION_STRING2(WAP_STR_ID_LAST_DUMMY ,"dummy","dummy");
#if defined(OBIGO_Q03C_MMS_V01) && defined(__MMI_MMS_IN_UM__)
	/* MMA */
    ADD_APPLICATION_IMAGE2(MMA_IMG_LOCK_MODE, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\SB_MMSLOCK.bmp", "");
    ADD_APPLICATION_IMAGE2(MMA_IMG_LETTER_JAVA, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Jsr\\\\mms_messagejsr.bmp", "");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK_READ_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock_read_h.bmp", "read forward-locked mms message icon with high priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK_READ_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock_read_l.bmp", "read forward-locked mms message icon with low priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock_h.bmp", "unread forward-lock mms icon with high priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock_l.bmp", "unread forward-lock mms icon with high priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock.bmp", "unread forward-lock mms icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK_READ, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock_read.bmp", "read forward-locked mms message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK_ATTACHMENT_READ_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_ALmessageread_h.bmp", "icon of mms message which is read, forward-locked, high priority, with attchement");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK_ATTACHMENT_READ_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_ALmessageread_l.bmp", "icon of mms message which is read, forward-locked, low priority, with attchement");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK_ATTACHMENT_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_ALmessage_h.bmp", "icon of mms message which is unread, forward-locked, high priority, with attchement");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK_ATTACHMENT_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_ALmessage_l.bmp", "icon of mms message which is unread, forward-locked, low priority, with attchement");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK_ATTACHMENT, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_ALmessage.bmp", "icon of mms message which is unread, forward-locked, with attchement");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK_ATTACHMENT_READ, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_ALmessageread.bmp", "icon of mms message which is read, forward-locked, with attchement");
    ADD_APPLICATION_IMAGE2(MMA_IMG_ATTACHMENT_READ_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_Amessageread_h.bmp", "icon of mms message which is read, high protity, with attchement");
    ADD_APPLICATION_IMAGE2(MMA_IMG_ATTACHMENT_READ_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_Amessageread_l.bmp", "icon of mms message which is read, low protity, with attchement");
    ADD_APPLICATION_IMAGE2(MMA_IMG_ATTACHMENT_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_Amessage_h.bmp", "icon of mms message which is unread, high protity, with attchement");
    ADD_APPLICATION_IMAGE2(MMA_IMG_ATTACHMENT_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_Amessage_l.bmp", "icon of mms message which is unread, low protity, with attchement");
    ADD_APPLICATION_IMAGE2(MMA_IMG_ATTACHMENT, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_Amessage.bmp", "icon of mms message which is unread, with attchement");
    ADD_APPLICATION_IMAGE2(MMA_IMG_ATTACHMENT_READ, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_Amessageread.bmp","icon of mms message which is read, with attchement");
    ADD_APPLICATION_IMAGE2(MMA_IMG_CORRUPT, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\MMS_corrupted.bmp","corrupted mms message icon");

    ADD_APPLICATION_IMAGE2(MMA_IMG_LETTER, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_message.bmp", "mms unread message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_LETTER_READ, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_messageread.bmp", "mms read message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_LETTER_READ_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_messageread_h.bmp","mms high priority read message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_LETTER_READ_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_messageread_l.bmp","mms low priority read message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_LETTER_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_message_h.bmp", "mms high priority unread message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_LETTER_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_message_l.bmp", "mms low priority unread message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_NOTIF, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\notification\\\\notification.bmp", "mms notification icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_LETTER_CREATED, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\draft\\\\mmsdraft.bmp", "mms draft message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_RR, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\readreport\\\\mms_read.bmp","mms read report message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_RR_READ, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\readreport\\\\mms_read_read.bmp","mms read report message read icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_DR, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\deliveryreport\\\\mms_delivery.bmp","mms delivery report message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_DR_READ, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\deliveryreport\\\\mms_delivery_read.bmp","mms delivery report message read icon");

    ADD_APPLICATION_STRING2(MMA_STR_ID_MESSAGE_CORRUPT, "[Corrupted MMS]", "[Corrupted MMS]");
    ADD_APPLICATION_STRING2(MMA_STR_ID_MMS_DELIVERY_REPORT, "[Delivery Report]", "[Delivery Report]");
    ADD_APPLICATION_STRING2(MMA_STR_ID_MMS_READ_REPORT, "[Read Report]", "[Read Report]");
    ADD_APPLICATION_STRING2(MMA_STR_ID_MMS_GROUP_MESSAGE, "Group Message", "Group Message");
#endif /*defined(OBIGO_Q03C_MMS_V01) && defined(__MMI_MMS_IN_UM__)*/
#endif /*OBIGO_Q03C*/

#if defined(OBIGO_Q05A)
    /* MSF */
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    ADD_APPLICATION_STRING2(MSF_STR_ID_UCDG_MESSAGE_ACTION_OK, "OK", "OK");
    ADD_APPLICATION_STRING2(MSF_STR_ID_UCDG_PROMPT_ACTION_OK, "OK", "OK");
    ADD_APPLICATION_STRING2(MSF_STR_ID_UCDG_PROMPT_ACTION_CANCEL, "Cancel", "Cancel");

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_YES, "Yes", "Yes");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_NO, "No", "No");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_SELECT, "Select", "Select");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_CANCEL, "Cancel", "Cancel");

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    
    ADD_APPLICATION_STRING2(MSF_STR_ID_SAS_ERROR_FULL, "There is no free space left.", "There is no free space left.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_SAS_ERROR_SIZE, "File size exceeds system maximum file size.", "File size exceeds system maximum file size.");

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    ADD_APPLICATION_STRING2(MSF_STR_ID_ASCII_TO_UTF8, "ASCII", "ASCII");
    ADD_APPLICATION_STRING2(MSF_STR_ID_LATIN1_TO_UTF8, "Western European (ISO-8859-1)", "Western European (ISO-8859-1)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_UTF16_TO_UTF8, "Unicode (UTF-16)", "Unicode (UTF-16)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_UCS2_TO_UTF8, "Unicode (UCS-2)", "Unicode (UCS-2)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_LATIN2_TO_UTF8, "Central European (ISO-8859-2)", "Central European (ISO-8859-2)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_HEBREW_TO_UTF8, "Hebrew (ISO-8859-8)", "Hebrew (ISO-8859-8)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_SHIFT_JIS_TO_UTF8, "Japanese (Shift-JIS)", "Japanese (Shift-JIS)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_UTF8_TO_UTF8, "Unicode (UTF-8)", "Unicode (UTF-8)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_BIG5_TO_UTF8, "Chinese Traditional (Big5)", "Chinese Traditional (Big5)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_HKSCS_TO_UTF8, "Chinese Traditional (Big5-HKSCS)", "Chinese Traditional (Big5-HKSCS)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_EUC_JP_TO_UTF8, "Japanese (EUC-JP)", "Japanese (EUC-JP)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_LATIN3_TO_UTF8, "South European (ISO-8859-3)", "South European (ISO-8859-3)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_LATIN4_TO_UTF8, "Baltic (ISO-8859-4)", "Baltic (ISO-8859-4)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CYRILLIC_TO_UTF8, "Cyrillic (ISO-8859-5)", "Cyrillic (ISO-8859-5)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ARABIC_TO_UTF8, "Arabic (ISO-8859-6)", "Arabic (ISO-8859-6)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_GREEK_TO_UTF8, "Greek (ISO-8859-7)", "Greek (ISO-8859-7)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_LATIN5_TO_UTF8, "Turkish (ISO-8859-9)", "Turkish (ISO-8859-9)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_LATIN6_TO_UTF8, "Nordic (ISO-8859-10)", "Nordic (ISO-8859-10)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_EUC_KR_TO_UTF8, "Korean (EUC-KR)", "Korean (EUC-KR)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_THAI_TO_UTF8, "Thai (ISO-8859-11)", "Thai (ISO-8859-11)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_LATIN7_TO_UTF8, "Baltic (ISO-8859-13)", "Baltic (ISO-8859-13)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_LATIN8_TO_UTF8, "Celtic (ISO-8859-14)", "Celtic (ISO-8859-14)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_LATIN9_TO_UTF8, "Western European (ISO-8859-15)", "Western European (ISO-8859-15)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_LATIN10_TO_UTF8, "Romanian (ISO-8859-16)", "Romanian (ISO-8859-16)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_WIN_1250_TO_UTF8, "Central European (Windows-1250)", "Central European (Windows-1250)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_WIN_1251_TO_UTF8, "Cyrillic (Windows-1251)", "Cyrillic (Windows-1251)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_WIN_1252_TO_UTF8, "Western European (Windows-1252)", "Western European (Windows-1252)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_WIN_1253_TO_UTF8, "Greek (Windows-1253)", "Greek (Windows-1253)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_WIN_1254_TO_UTF8, "Turkish (Windows-1254)", "Turkish (Windows-1254)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_WIN_1255_TO_UTF8, "Hebrew (Windows-1255)", "Hebrew (Windows-1255)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_WIN_1256_TO_UTF8, "Arabic (Windows-1256)", "Arabic (Windows-1256)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_WIN_1257_TO_UTF8, "Baltic (Windows-1257)", "Baltic (Windows-1257)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_WIN_1258_TO_UTF8, "Vietnamese (Windows-1258)", "Vietnamese (Windows-1258)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_WIN_874_TO_UTF8, "Thai (Windows-874)", "Thai (Windows-874)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_GB2312_TO_UTF8, "Chinese Simplified (GB2312)", "Chinese Simplified (GB2312)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_GB18030_TO_UTF8, "Chinese Simplified (GB18030)", "Chinese Simplified (GB18030)");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ISO_2022_JP_TO_UTF8, "Japanese (ISO-2022-JP)", "Japanese (ISO-2022-JP)");
    #if 0
/* under construction !*/
    #endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	/* BRS */
	ADD_APPLICATION_IMAGE2(BRS_IMG_ID_ICON_RADIO_UNCHECKED, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Q05ASkin\\\\Q05AUIcomponent\\\\ro_uns.bmp", "Image of Unchecked Radio Button");
	ADD_APPLICATION_IMAGE2(BRS_IMG_ID_ICON_RADIO_CHECKED, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Q05ASkin\\\\Q05AUIcomponent\\\\ro_s.bmp", "Image of Checked Radio Button");
	ADD_APPLICATION_IMAGE2(BRS_IMG_ID_ICON_RADIO_UNCHECKED_DISABLED, CUST_IMG_PATH"\\\\WAP\\\\Q05ASkin\\\\Q05AUIcomponent\\\\ro_duns.bmp", "Image of Disabled Unchecked Radio Button");
	ADD_APPLICATION_IMAGE2(BRS_IMG_ID_ICON_RADIO_CHECKED_DISABLED, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Q05ASkin\\\\Q05AUIcomponent\\\\ro_ds.bmp", "Image of Disabled Checked Radio Button");
	ADD_APPLICATION_IMAGE2(BRS_IMG_ID_ICON_CHECKBOX_UNCHECKED, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Q05ASkin\\\\Q05AUIcomponent\\\\CK_UNS.bmp", "Image of Unchecked CheckBox");
	ADD_APPLICATION_IMAGE2(BRS_IMG_ID_ICON_CHECKBOX_CHECKED, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Q05ASkin\\\\Q05AUIcomponent\\\\CK_S.bmp", "Image of Checked CheckBox");	    
	ADD_APPLICATION_IMAGE2(BRS_IMG_ID_ICON_CHECKBOX_UNCHECKED_DISABLED, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Q05ASkin\\\\Q05AUIcomponent\\\\CK_DUNS.bmp", "Image of Disabled Unchecked CheckBox");
	ADD_APPLICATION_IMAGE2(BRS_IMG_ID_ICON_CHECKBOX_CHECKED_DISABLED, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Q05ASkin\\\\Q05AUIcomponent\\\\CK_DS.bmp", "Image of Disabled Checked CheckBox");
	ADD_APPLICATION_IMAGE2(BRS_IMG_ID_ICON_BROKEN_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\SW_Broken.bmp", "Image of a broken image");
	ADD_APPLICATION_IMAGE2(BRS_IMG_ID_ICON_BGSOUND, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\SW_BGSound.bmp", "Image of Background Sound");
	ADD_APPLICATION_IMAGE2(BRS_IMG_ID_ICON_IMG_TO_LARGE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\SW_larger.bmp", "Image of a too-large image");


	ADD_APPLICATION_STRING2(BRS_STR_ID_BUTTON, "Button", "Button");
	ADD_APPLICATION_STRING2(BRS_STR_ID_CACHE_NOTIFICATION, "The page is not in cache, reload?", "The page is not in cache, reload?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_CACHE_NOTIFICATION_OBJECT_1, "An object with url = [", "An object with url = [");
	ADD_APPLICATION_STRING2(BRS_STR_ID_CACHE_NOTIFICATION_OBJECT_2, "] is not in cache, reload?", "] is not in cache, reload?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_CACHE_TITLE, "Cache", "Cache");
	ADD_APPLICATION_STRING2(BRS_STR_ID_CONFIRM_TITLE, "Confirm", "Confirm");
	ADD_APPLICATION_STRING2(BRS_STR_ID_ALERT_TITLE, "Alert", "Alert");
	ADD_APPLICATION_STRING2(BRS_STR_ID_DOWNLOAD_FAILED_TITLE, "Download failed", "Download failed");
	ADD_APPLICATION_STRING2(BRS_STR_ID_ENABLE_SCRIPT_DLG_MSG, "This site uses scripts. Do you want to enable scripting?", "This site uses scripts. Do you want to enable scripting?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_ENABLE_SCRIPT_DLG_TITLE, "Script disabled", "Script disabled");
	ADD_APPLICATION_STRING2(BRS_STR_ID_HTTP_TO_HTTPS_DLG_MSG, "Entering secure connection, continue?", "Entering secure connection, continue?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_HTTPS_TO_HTTP_DLG_MSG, "Connection no longer secure, continue?", "Connection no longer secure, continue?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_INPUT_TITLE, "Input", "Input");
	ADD_APPLICATION_STRING2(BRS_STR_ID_INVALID_INPUT, "Invalid input! Proceed?", "Invalid input! Proceed?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_JAM_CONFIRM, "Start midlet?", "Start midlet?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_NOT_SUPPORT_FILE_UPLOAD, "File uploading is not supported", "File uploading is not supported");
	ADD_APPLICATION_STRING2(BRS_STR_ID_NO_MIME_MSG_1, "Do you wish to load this object of mime-type = [", "Do you wish to load this object of mime-type = [");
	ADD_APPLICATION_STRING2(BRS_STR_ID_NO_MIME_MSG_2, "], with url = [", "], with url = [");
	ADD_APPLICATION_STRING2(BRS_STR_ID_NO_MIME_MSG_3, "]?", "]?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_NO_MIME_MSG_4, "Unknown", "Unknown");
	ADD_APPLICATION_STRING2(BRS_STR_ID_REDIRECT_POST, "Redirected request received. Resubmit user data?", "Redirected request received. Resubmit user data?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_RESEND_POST, "Do you want to resubmit user data?", "Do you want to resubmit user data?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_RESET, "Reset", "Reset");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SAS_DOWNLOAD_CANCEL, "Downloading was canceled!", "Downloading was canceled!");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SAS_DOWNLOAD_ERROR, "An error occurred.", "An error occurred.");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SAS_DOWNLOAD_SUCCESS, "File successfully saved.", "File successfully saved.");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SAVE_COMPLETE_TITLE, "Save complete", "Save complete");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SCRIPT_DISABLED_NOTIFICATION, "This site uses scripts. Scripting support is disabled", "This site uses scripts. Scripting support is disabled");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SECURITY, "Security", "Security");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUBMIT, "Submit", "Submit");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUI_2WAY_NAVIGATION, "2 Way navigation", "2 Way navigation");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUI_4WAY_NAVIGATION, "4 Way navigation", "4 Way navigation");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUI_FRAMES_AS_LINKS, "This page contains frames. In order to view the content of a frame, navigate to it and press select.", "This page contains frames. In order to view the content of a frame, navigate to it and press select.");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUI_REND_FULL, "Standard", "Standard");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUI_REND_NARROW, "Screen Optimized", "Screen Optimized");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUI_REND_TEXT, "Text only", "Text only");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUI_REND_WRAP, "Text Wrap", "Text Wrap");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUI_SCROLLING_NAVIGATION, "Scrolling", "Scrolling");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUI_THUMBNAIL_CREATING, "Creating Thumbnail", "Creating Thumbnail");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUI_THUMBNAIL_FRAME_PAGE, "Page contains frames, no thumbnail will be created", "Page contains frames, no thumbnail will be created");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUI_THUMBNAIL_OUT_OF_MEMORY, "Out of memory, no thumbnail will be created", "Out of memory, no thumbnail will be created");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUI_THUMBNAIL_SMALL_PAGE, "No need for a thumbnail", "No need for a thumbnail");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUI_THUMBNAIL_LARGE_PAGE, "Large page, no thumbnail will be created", "Large page, no thumbnail will be created");
/* #ifdef MTK_TMP_PATCH of CR36621 */
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUI_FONT_SIZE, "Font size:", "Font size:");
/* #endif */
	ADD_APPLICATION_STRING2(BRS_STR_ID_UNHANDLED_CONTENT_TYPE, "Unknown content type! Download anyway?", "Unknown content type! Download anyway?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_WML_SCRIPT_ALERT_TITLE, "WML script", "WML script");
	
	ADD_APPLICATION_STRING2(BRS_STR_ID_JS_ERR, "emory error", "emory error");
	ADD_APPLICATION_STRING2(BRS_STR_ID_JS_INTERNAL_ERR, "Internal error", "Internal error");
	ADD_APPLICATION_STRING2(BRS_STR_ID_JS_EVALERR, "Eval error", "Eval error");
	ADD_APPLICATION_STRING2(BRS_STR_ID_JS_RANGEERR, "Reference error", "Reference error");
	ADD_APPLICATION_STRING2(BRS_STR_ID_JS_SYNTAXERR, "Syntax error", "Syntax error");
	ADD_APPLICATION_STRING2(BRS_STR_ID_JS_TYPEERR, "Type error", "Type error");
	ADD_APPLICATION_STRING2(BRS_STR_ID_JS_URIERR, "URI error", "URI error");
	ADD_APPLICATION_STRING2(BRS_STR_ID_JS_LINE, "Line:", "Line:");
	ADD_APPLICATION_STRING2(BRS_STR_ID_JS_INLINE_SCRIPT, "Inline script#", "Inline script#");
	ADD_APPLICATION_STRING2(BRS_STR_ID_JS_BUF_CHAR, "Char:", "Char:");
	ADD_APPLICATION_STRING2(BRS_STR_ID_JS_BUF_CHAR_POS, "Char pos:", "Char pos:");
	ADD_APPLICATION_STRING2(BRS_STR_ID_JS_ERR_REQUEST_ABORTED, "Request aborted when loading", "Request aborted when loading");
	ADD_APPLICATION_STRING2(BRS_STR_ID_JS_ERR_HTTP_REPLY, "Http reply error when requesting", "Http reply error when requesting");
	ADD_APPLICATION_STRING2(BRS_STR_ID_JS_ERR_CHAR_ENCODING, "Char conversion error when loading", "Char conversion error when loading");
	ADD_APPLICATION_STRING2(BRS_STR_ID_JS_ERR_NOT_DEF, "Error undefined", "Error undefined");
	ADD_APPLICATION_STRING2(BRS_STR_ID_JS_ERR_EMRS_PERMISSION_DENIED, "Mime type rejected", "Mime type rejected");
	ADD_APPLICATION_STRING2(BRS_STR_ID_JS_ERR_STREAM_ERROR, "Error in stream", "Error in stream");
	ADD_APPLICATION_STRING2(BRS_STR_ID_JS_ERR_PIPE_CLOSED, "Pipe closed error", "Pipe closed error");
	ADD_APPLICATION_STRING2(BRS_STR_ID_JS_CALLED_FROM, "Called from", "Called from");
    ADD_APPLICATION_STRING2(BRS_STR_ID_JS_SIZE_TOO_LARGE, "JavaScript code is too large to be handled.", "JavaScript code is too large to be handled.");
    ADD_APPLICATION_STRING2(BRS_STR_ID_JS_EXECUTION_TIME_TOO_LONG, "JavaScript execution is terminated because execution time exceeds limit.", "JavaScript execution is terminated because execution time exceeds limit.");
	
	
#if defined(MMS_SUPPORT) && !defined(OBIGO_Q03C_MMS_V02)
    /* MMA */
    ADD_APPLICATION_IMAGE2(MMA_IMG_LOCK_MODE, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\SB_MMSLOCK.bmp", "");
    ADD_APPLICATION_IMAGE2(MMA_IMG_LETTER_JAVA, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Jsr\\\\mms_messagejsr.bmp", "");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK_READ_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock_read_h.bmp", "read forward-locked mms message icon with high priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK_READ_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock_read_l.bmp", "read forward-locked mms message icon with low priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock_h.bmp", "unread forward-lock mms icon with high priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock_l.bmp", "unread forward-lock mms icon with high priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock.bmp", "unread forward-lock mms icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK_READ, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock_read.bmp", "read forward-locked mms message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK_ATTACHMENT_READ_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_ALmessageread_h.bmp", "icon of mms message which is read, forward-locked, high priority, with attchement");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK_ATTACHMENT_READ_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_ALmessageread_l.bmp", "icon of mms message which is read, forward-locked, low priority, with attchement");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK_ATTACHMENT_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_ALmessage_h.bmp", "icon of mms message which is unread, forward-locked, high priority, with attchement");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK_ATTACHMENT_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_ALmessage_l.bmp", "icon of mms message which is unread, forward-locked, low priority, with attchement");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK_ATTACHMENT, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_ALmessage.bmp", "icon of mms message which is unread, forward-locked, with attchement");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK_ATTACHMENT_READ, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_ALmessageread.bmp", "icon of mms message which is read, forward-locked, with attchement");
    ADD_APPLICATION_IMAGE2(MMA_IMG_ATTACHMENT_READ_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_Amessageread_h.bmp", "icon of mms message which is read, high protity, with attchement");
    ADD_APPLICATION_IMAGE2(MMA_IMG_ATTACHMENT_READ_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_Amessageread_l.bmp", "icon of mms message which is read, low protity, with attchement");
    ADD_APPLICATION_IMAGE2(MMA_IMG_ATTACHMENT_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_Amessage_h.bmp", "icon of mms message which is unread, high protity, with attchement");
    ADD_APPLICATION_IMAGE2(MMA_IMG_ATTACHMENT_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_Amessage_l.bmp", "icon of mms message which is unread, low protity, with attchement");
    ADD_APPLICATION_IMAGE2(MMA_IMG_ATTACHMENT, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_Amessage.bmp", "icon of mms message which is unread, with attchement");
    ADD_APPLICATION_IMAGE2(MMA_IMG_ATTACHMENT_READ, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_Amessageread.bmp","icon of mms message which is read, with attchement");

    ADD_APPLICATION_IMAGE2(MMA_IMG_LETTER, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_message.bmp", "mms unread message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_LETTER_READ, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_messageread.bmp", "mms read message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_LETTER_READ_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_messageread_h.bmp","mms high priority read message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_LETTER_READ_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_messageread_l.bmp","mms low priority read message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_LETTER_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_message_h.bmp", "mms high priority unread message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_LETTER_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_message_l.bmp", "mms low priority unread message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_NOTIF, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\notification\\\\notification.bmp", "mms notification icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_LETTER_CREATED, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\draft\\\\mmsdraft.bmp", "mms draft message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_RR, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\readreport\\\\mms_read.bmp","mms read report message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_RR_READ, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\readreport\\\\mms_read_read.bmp","mms read report message read icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_DR, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\deliveryreport\\\\mms_delivery.bmp","mms delivery report message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_DR_READ, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\deliveryreport\\\\mms_delivery_read.bmp","mms delivery report message read icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_CORRUPT, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\MMS_corrupted.bmp","corrupted mms message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_AUDIO, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Audiounread.bmp","audio mms unread icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_AUDIO_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Audiounread_h.bmp","audio mms unread icon with high priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_AUDIO_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Audiounread_l.bmp","audio mms unread icon with low priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_AUDIO_READ, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Audioread.bmp","audio mms read icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_AUDIO_READ_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Audioread_h.bmp","audio mms read icon with high priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_AUDIO_READ_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Audioread_l.bmp","audio mms read icon with low priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_VIDEO, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Videounread.bmp","video mms unread icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_VIDEO_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Videounread_h.bmp","video mms unread icon with high priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_VIDEO_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Videounread_l.bmp","video mms unread icon with low priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_VIDEO_READ, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Videoread.bmp","video mms read icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_VIDEO_READ_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Videoread_h.bmp","video mms read icon with high priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_VIDEO_READ_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Videoread_l.bmp","video mms read icon with low priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_PHOTO, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Picunread.bmp","photo mms unread icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_PHOTO_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Picunread_h.bmp","photo mms unread icon with high priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_PHOTO_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Picunread_l.bmp","photo mms unread icon with low priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_PHOTO_READ, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Picread.bmp","photo mms read icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_PHOTO_READ_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Picread_h.bmp","photo mms read icon with high priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_PHOTO_READ_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Picread_l.bmp","photo mms read icon with low priority");

    ADD_APPLICATION_IMAGE2(MMA_IMG_GROUP, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Gmessageunread.bmp","group mms unread icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_GROUP_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Gmessageunread_h.bmp","group mms unread icon with high priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_GROUP_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Gmessageunread_l.bmp","group mms unread icon with low priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_GROUP_READ, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Gmessageread.bmp","group mms read icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_GROUP_READ_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Gmessageread_h.bmp","group mms read icon with high priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_GROUP_READ_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_Gmessageread_l.bmp","group mms read icon with low priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_GROUP_AUDIO, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GAudiounread.bmp","audio group mms unread icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_GROUP_AUDIO_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GAudiounread_h.bmp","audio group mms unread icon with high priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_GROUP_AUDIO_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GAudiounread_l.bmp","audio group mms unread icon with low priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_GROUP_AUDIO_READ, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GAudioread.bmp","audio group mms read icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_GROUP_AUDIO_READ_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GAudioread_h.bmp","audio group mms read icon with high priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_GROUP_AUDIO_READ_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GAudioread_l.bmp","audio group mms read icon with low priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_GROUP_VIDEO, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GVideounread.bmp","video group mms unread icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_GROUP_VIDEO_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GVideounread_h.bmp","video group mms unread icon with high priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_GROUP_VIDEO_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GVideounread_l.bmp","video group mms unread icon with low priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_GROUP_VIDEO_READ, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GVideoread.bmp","video group mms read icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_GROUP_VIDEO_READ_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GVideoread_h.bmp","video group mms read icon with high priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_GROUP_VIDEO_READ_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GVideoread_l.bmp","video group mms read icon with low priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_GROUP_PHOTO, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GPicunread.bmp","photo group mms unread icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_GROUP_PHOTO_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GPicunread_h.bmp","photo group mms unread icon with high priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_GROUP_PHOTO_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GPicunread_l.bmp","photo group mms unread icon with low priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_GROUP_PHOTO_READ, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GPicread.bmp","photo group mms read icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_GROUP_PHOTO_READ_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GPicread_h.bmp","photo group mms read icon with high priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_GROUP_PHOTO_READ_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_GPicread_l.bmp","photo group mms read icon with low priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_POSTCARD_MMS, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\MMSType\\\\mms_postcard.bmp","Postcard MMS icon");

    ADD_APPLICATION_STRING2(MMA_STR_ID_MESSAGE_CORRUPT, "[Corrupted MMS]", "[Corrupted MMS]");
    ADD_APPLICATION_STRING2(MMA_STR_ID_MMS_DELIVERY_REPORT, "[Delivery Report]", "[Delivery Report]");
    ADD_APPLICATION_STRING2(MMA_STR_ID_MMS_READ_REPORT, "[Read Report]", "[Read Report]");
    ADD_APPLICATION_STRING2(MMA_STR_ID_MMS_GROUP_MESSAGE, "Group Message", "Group Message");

    /* MMS */
    ADD_APPLICATION_STRING2(MMS_STR_EMPTY_STRING, " ", " ");
    ADD_APPLICATION_STRING2(MMS_STR_ID_READ_REPORT, "[Read Report]", "[Read Report]");
    ADD_APPLICATION_STRING2(MMS_STR_ID_YOUR_MESSAGE_BEEN_READ, "Your message has been read at ", "Your message has been read at ");
    ADD_APPLICATION_STRING2(MMS_STR_ID_RR_UNKNOWN_TO, "Unknown", "Unknown");
#endif /*#if defined(MMS_SUPPORT) && !defined(OBIGO_Q03C_MMS_V02)*/
    /* PHS */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    /* SES */
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_CONFIRM, "Confirm", "Confirm");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_HASH, "Hashed CA", "Hashed CA");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_STORE, "Save", "Save");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_VALIDATION_ERROR, "Validation error", "Validation error");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_CLIENT_CERT, "Client certificate", "Client certificate");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_ERROR, "Error", "Error");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_OVERWRITE, "Certificate overwrite", "Certificate overwrite");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_MISSING_CERT, "Missing certificate", "Missing certificate");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_STORE_SUCCEEDED, "Save succeeded", "Save succeeded");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_DELETE, "Delete", "Delete");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_STORE_ERROR, "Save error", "Save error");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_DELETE_ERROR, "Delete error", "Delete error");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_PIN_BLOCKED, "PIN blocked", "PIN blocked");
    ADD_APPLICATION_STRING2(SES_STR_ID_CONFIRM_STORE, "Save certificate?", "Save certificate?");
    ADD_APPLICATION_STRING2(SES_STR_ID_CONFIRM_STORE_NOT_VERIFIED, "Could not validate the certificate. Save anyway?", "Could not validate the certificate. Save anyway?");
    ADD_APPLICATION_STRING2(SES_STR_ID_CONFIRM_STORE_SAME, "Certificate with same date exists. Overwrite?", "Certificate with same date exists. Overwrite?");
    ADD_APPLICATION_STRING2(SES_STR_ID_CONFIRM_STORE_NEWER, "Certificate with older date exists. Overwrite?", "Certificate with older date exists. Overwrite?");
    ADD_APPLICATION_STRING2(SES_STR_ID_CONFIRM_STORE_OLDER, "Certificate with newer date exists. Overwrite?", "Certificate with newer date exists. Overwrite?");
    ADD_APPLICATION_STRING2(SES_STR_ID_CONFIRM_CONNECT, "Could not validate certificate. Connect anyway?", "Could not validate certificate. Connect anyway?");
    ADD_APPLICATION_STRING2(SES_STR_ID_CONFIRM_CONNECT_NO_USER, "No matching client certificate found. Connect with server authentication, without client authentication?", "No matching client certificate found. Connect with server authentication, without client authentication?");
    ADD_APPLICATION_STRING2(SES_STR_ID_CONFIRM_DELETE_CERT, "Delete certificate?", "Delete certificate?");
    ADD_APPLICATION_STRING2(SES_STR_ID_INFO_CERT_STORED, "Certificate has been saved.", "Certificate has been saved.");
    ADD_APPLICATION_STRING2(SES_STR_ID_INFO_CERT_NOT_STORED, "Certificate could not be saved.", "Certificate could not be saved.");
    ADD_APPLICATION_STRING2(SES_STR_ID_INFO_CERT_DELETED, "Certificate has been deleted.", "Certificate has been deleted.");
    ADD_APPLICATION_STRING2(SES_STR_ID_INFO_CERT_NOT_DELETED, "Certificate could not be deleted.", "Certificate could not be deleted.");
    ADD_APPLICATION_STRING2(SES_STR_ID_INFO_CERT_NOT_SHOWN, "Could not show the certificate.", "Could not show the certificate.");
    ADD_APPLICATION_STRING2(SES_STR_ID_INFO_NO_CERTS, "Certificate list is empty.", "Certificate list is empty.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_UNKNOWN_CERTIFICATE_TYPE, "Unknown certificate type.", "Unknown certificate type.");

	/* OWL */
	ADD_APPLICATION_STRING2(OWL_ADP_STR_ID_INVALID_WCSS__UPPERCASE_A, "invalid WCSS format - A", "invalid WCSS format - A");
	ADD_APPLICATION_STRING2(OWL_ADP_STR_ID_INVALID_WCSS__LOWERCASE_A, "invalid WCSS format - a", "invalid WCSS format - a");
	ADD_APPLICATION_STRING2(OWL_ADP_STR_ID_INVALID_WCSS__UPPERCASE_X, "invalid WCSS format - X", "invalid WCSS format - X");
	ADD_APPLICATION_STRING2(OWL_ADP_STR_ID_INVALID_WCSS__LOWERCASE_X, "invalid WCSS format - x", "invalid WCSS format - x");
	ADD_APPLICATION_STRING2(OWL_ADP_STR_ID_INVALID_WCSS__LOWERCASE_N, "invalid WCSS format - n", "invalid WCSS format - n");
	ADD_APPLICATION_STRING2(OWL_ADP_STR_ID_INPUT_FORMAT_ERROR,"Input format error!","Input format error!");

	/* OWL PICTOGRAM */
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ARROW_UP, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\up.bmp", "Image of pictogram up");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ARROW_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\down.bmp", "Image of pictogram down");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ARROW_RIGHT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\right.BMP", "Image of pictogram right");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ARROW_LEFT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\left.BMP", "Image of pictogram left");

	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ARROW_UPPERRIGHT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\upperright.bmp", "Image of pictogram uppperright");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ARROW_UPPERLEFT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\upperleft.BMP", "Image of pictogram upperleft");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ARROW_LOWERRIGHT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\lowerright.bmp", "Image of pictogram lowerright");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ARROW_LOWERLEFT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\lowerleft.BMP", "Image of pictogram lowerleft");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ARROW_FINGERUP, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\fingerup.bmp", "Image of pictogram fingerup");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ARROW_FINGERDOWN, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\fingerdown.bmp", "Image of pictogram fingerdown");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ARROW_FINGERRIGHT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\fingerright.bmp", "Image of pictogram fingerright");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ARROW_FINGERLEFT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\fingerleft.bmp", "Image of pictogram fingerleft");

	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_BUTTON_1, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\1.bmp", "Image of pictogram button 1");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_BUTTON_2, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\2.bmp", "Image of pictogram button 2");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_BUTTON_3, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\3.bmp", "Image of pictogram button 3");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_BUTTON_4, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\4.bmp", "Image of pictogram button 4");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_BUTTON_5, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\5.bmp", "Image of pictogram button 5");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_BUTTON_6, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\6.bmp", "Image of pictogram button 6");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_BUTTON_7, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\7.bmp", "Image of pictogram button 7");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_BUTTON_8, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\8.bmp", "Image of pictogram button 8");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_BUTTON_9, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\9.bmp", "Image of pictogram button 9");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_BUTTON_0, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\0.bmp", "Image of pictogram button 0");

	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ACTION_MAKEPHONECALL, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\makephonecall.bmp", "Image of pictogram action makephonecall");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ACTION_FIND, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\find.bmp", "Image of pictogram action find");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ACTION_USERAUTHENTICATION, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\userauthentication.bmp", "Image of pictogram action userauthentication");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ACTION_PASSWORD, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\password.bmp", "Image of pictogram action password");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ACTION_NEXTITEM, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\nextitem.bmp", "Image of pictogram action nextitem");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ACTION_CLEAR, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\clear.bmp", "Image of pictogram action clear");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ACTION_STOP, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\stop.bmp", "Image of pictogram action stop");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ACTION_TOP, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\top.bmp", "Image of pictogram action top");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ACTION_NEXT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\next.bmp", "Image of pictogram action next");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ACTION_BACK, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\back.bmp", "Image of pictogram action back");

	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MESSAGE_RECEIVE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\message\\\\receive.bmp", "Image of pictogram message receive");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MESSAGE_SEND, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\message\\\\send.bmp", "Image of pictogram message send");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MESSAGE_MESSAGE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\message\\\\message.bmp", "Image of pictogram message message");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MESSAGE_DOCUMENT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\message\\\\document.bmp", "Image of pictogram message document");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MESSAGE_ATTACHMENT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\message\\\\attachment.bmp", "Image of pictogram message attachment");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MESSAGE_FOLDER, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\message\\\\folder.bmp", "Image of pictogram message folder");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MESSAGE_INBOX, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\message\\\\inbox.bmp", "Image of pictogram message inbox");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MESSAGE_OUTBOX, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\message\\\\outbox.bmp", "Image of pictogram message outbox");

	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_STATE_SECURE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\state\\\\secure.bmp", "Image of pictogram state secure");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_STATE_INSECURE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\state\\\\insecure.bmp", "Image of pictogram state insecure");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_STATE_COPYRIGHT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\state\\\\copyright.bmp", "Image of pictogram state copyright");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_STATE_TRADEMARK, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\state\\\\trademark.bmp", "Image of pictogram state trademark");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_STATE_UNDERCONSTRUCTION, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\state\\\\underconstruction.bmp", "Image of pictogram state underconstruction");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_STATE_BEGINNER, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\state\\\\beginner.bmp", "Image of pictogram state beginner");

	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MEDIA_BOOK, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\media\\\\book.bmp", "Image of pictogram media book");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MEDIA_VIDEO, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\media\\\\video.bmp", "Image of pictogram media video");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MEDIA_CD, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\media\\\\cd.bmp", "Image of pictogram media cd");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MEDIA_DVD, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\media\\\\dvd.bmp", "Image of pictogram media dvd");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MEDIA_GAME, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\media\\\\game.bmp", "Image of pictogram media game");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MEDIA_RADIO, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\media\\\\radio.bmp", "Image of pictogram media radio");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MEDIA_TV, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\media\\\\tv.bmp", "Image of pictogram media tv");

	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_INFO_NOTICE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\info\\\\notice.bmp", "Image of pictogram info notice");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_INFO_CHARGED, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\info\\\\charged.bmp", "Image of pictogram info charged");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_INFO_FREEOFCHARGE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\info\\\\freeofcharge.bmp", "Image of pictogram info freeofcharge");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_INFO_NEW, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\info\\\\new.bmp", "Image of pictogram info new");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_INFO_POSITION, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\info\\\\position.bmp", "Image of pictogram info position");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_INFO_TOLLFREE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\info\\\\tollfree.bmp", "Image of pictogram info tollfree");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_INFO_SHARPDIAL, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\info\\\\sharpdial.bmp", "Image of pictogram info sharpdial");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_INFO_RESERVED, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\info\\\\reserved.bmp", "Image of pictogram info reserved");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_INFO_SPEECHINFO, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\info\\\\speechinfo.bmp", "Image of pictogram info speechinfo");

	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_ACCESSKEY_0, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\AccessKey\\\\accesskey_0.gif", "Image of accesskey 0");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_ACCESSKEY_1, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\AccessKey\\\\accesskey_1.gif", "Image of accesskey 1");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_ACCESSKEY_2, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\AccessKey\\\\accesskey_2.gif", "Image of accesskey 2");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_ACCESSKEY_3, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\AccessKey\\\\accesskey_3.gif", "Image of accesskey 3");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_ACCESSKEY_4, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\AccessKey\\\\accesskey_4.gif", "Image of accesskey 4");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_ACCESSKEY_5, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\AccessKey\\\\accesskey_5.gif", "Image of accesskey 5");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_ACCESSKEY_6, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\AccessKey\\\\accesskey_6.gif", "Image of accesskey 6");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_ACCESSKEY_7, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\AccessKey\\\\accesskey_7.gif", "Image of accesskey 7");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_ACCESSKEY_8, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\AccessKey\\\\accesskey_8.gif", "Image of accesskey 8");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_ACCESSKEY_9, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\AccessKey\\\\accesskey_9.gif", "Image of accesskey 9");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_ACCESSKEY_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\AccessKey\\\\accesskey_down.gif", "Image of accesskey down");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_ACCESSKEY_LEFT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\AccessKey\\\\accesskey_left.gif", "Image of accesskey left");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_ACCESSKEY_POUND, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\AccessKey\\\\accesskey_pound.gif", "Image of accesskey pound");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_ACCESSKEY_RIGHT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\AccessKey\\\\accesskey_right.gif", "Image of accesskey right");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_ACCESSKEY_STAR, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\AccessKey\\\\accesskey_star.gif", "Image of accesskey star");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_ACCESSKEY_UP, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\AccessKey\\\\accesskey_up.gif", "Image of accesskey up");

	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_CHECK_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Q05ASkin\\\\checkoff.png", "Image of check off");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_CHECK_ON, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Q05ASkin\\\\checkon.png", "Image of check on");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_RADIO_OFF, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Q05ASkin\\\\radiooff.png", "Image of radio off");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_RADIO_ON, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Q05ASkin\\\\radioon.png", "Image of radio on");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_SELECT_ITEM, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Q05ASkin\\\\selected_item.gif", "Image of selected item");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_SELECT_ITEM_BIG, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Q05ASkin\\\\selected_item_big.gif", "Big image of selected item");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_TEXTINPUT_BORDER_BOTTOM, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Q05ASkin\\\\textinput_border_bottom.gif", "Image of textinput bottom border");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_TEXTINPUT_BORDER_LEFT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Q05ASkin\\\\textinput_border_left.gif", "Image of textinput left border");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_TEXTINPUT_BORDER_RIGHT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Q05ASkin\\\\textinput_border_right.gif", "Image of textinput right border");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_TEXTINPUT_BORDER_TOP, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Q05ASkin\\\\textinput_border_top.gif", "Image of textinput top border");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_CACHE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Q05ASkin\\\\0180_16_OWL_cache.png", "Image of owl cache");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_BUSY, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Q05ASkin\\\\0181_16_OWL_busy.png", "Image of owl busy");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_SECURE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Q05ASkin\\\\0182_16_OWL_secure.png", "Image of owl secure");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_HAS_SUB_MENU, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Q05ASkin\\\\has_sub_menu.png", "Image of has sub menu");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_SOFT_TITLE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Q05ASkin\\\\soft_and_title.png", "Image of soft and title");


	/* OWL Adp */
	ADD_APPLICATION_STRING2(OWL_ADP_STR_ID_INPUT_TITLE, "Input", "Input");
	//ADD_APPLICATION_STRING2(OWL_ADP_STR_ID_CANT_SWITCH_INPUT_METHOD,"Can't Set Input Method","Can't Set Input Method");

    ADD_APPLICATION_IMAGE2(OWL_ADP_IMAGE_WAP_LOGO,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_SV.PNG","WAP Menu Item Icon");

	ADD_APPLICATION_MENUITEM((OWL_ADP_MENU_FULLSCREEN_EDITOR_OPTION,0,3,
		OWL_ADP_MENU_FULLSCREEN_EDITOR_OPTION_DONE,
		OWL_ADP_MENU_FULLSCREEN_EDITOR_OPTION_CANCEL,
		OWL_ADP_MENU_FULLSCREEN_EDITOR_OPTION_INPUT_METHOD,
		SHOW, NONMOVEABLE,
		DISP_LIST,STR_GLOBAL_OPTIONS,IMG_GLOBAL_OPTIONS));

	ADD_APPLICATION_MENUITEM((
				OWL_ADP_MENU_FULLSCREEN_EDITOR_OPTION_DONE,
				OWL_ADP_MENU_FULLSCREEN_EDITOR_OPTION,
				0, SHOW, NONMOVEABLE,
				DISP_LIST,STR_GLOBAL_DONE,NULL));

	ADD_APPLICATION_MENUITEM((
				OWL_ADP_MENU_FULLSCREEN_EDITOR_OPTION_CANCEL,
				OWL_ADP_MENU_FULLSCREEN_EDITOR_OPTION,
				0, SHOW, NONMOVEABLE,
				DISP_LIST,STR_GLOBAL_CANCEL,NULL));

	ADD_APPLICATION_MENUITEM((
				OWL_ADP_MENU_FULLSCREEN_EDITOR_OPTION_INPUT_METHOD,
				OWL_ADP_MENU_FULLSCREEN_EDITOR_OPTION,
				0, SHOW, NONMOVEABLE,
				DISP_LIST,STR_GLOBAL_INPUT_METHOD,NULL));

    /* VDS */
    ADD_APPLICATION_IMAGE2(VDS_IMG_ID_LOADING,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\vds\\\\vds_loading.bmp","VDS loading icon");
    ADD_APPLICATION_IMAGE2(VDS_IMG_ID_PLAY,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\vds\\\\vds_play.bmp","vid playing icon");
    ADD_APPLICATION_IMAGE2(VDS_IMG_ID_BROKEN,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\vds\\\\vds_broken.bmp","VDS broken icon");
    ADD_APPLICATION_IMAGE2(VDS_IMG_ID_AUDIO,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\vds\\\\vds_audio.bmp","VDS audio icon");
    ADD_APPLICATION_IMAGE2(VDS_IMG_ID_VDO_INACTIVE,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\vds\\\\vds_inactive.bmp","VDS inactive");

#endif

#ifdef __MMI_MMS_2__
//	PopulateMMSAppResource();
#endif
}
#endif


