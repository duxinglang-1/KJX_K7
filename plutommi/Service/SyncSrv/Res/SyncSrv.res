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
 *   SyncSrv.res
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Resource XML file
 *
 * Author:
 * -------
 *   Wen Wu(MTK80153)
 *
 *******************************************************************************/

#include "mmi_features.h"

<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "SRV_SYNC">

#ifdef __COSMOS_MMI__

#ifdef __SYNCML_SUPPORT__
	<EVENT id="EVT_ID_SRV_SYNC_ASK_SYNC" type="SENDER"/>
	<EVENT id="EVT_ID_SRV_SYNC_ASK_CONN" type="SENDER"/>
	<EVENT id="EVT_ID_SRV_SYNC_PROGRESS"	type="SENDER"/>
	<EVENT id="EVT_ID_SRV_SYNC_FINISH" type="SENDER"/>
	<EVENT id="EVT_ID_SRV_SYNC_BG_START" type="SENDER"/>
	<EVENT id="EVT_ID_SRV_SYNC_BG_FINISH" type="SENDER"/>
	<EVENT id="EVT_ID_SRV_SYNC_CM" type="SENDER"/>
	<EVENT id="EVT_ID_SRV_SYNC_ACCNT_OP" type="SENDER"/>
	<EVENT id="EVT_ID_SRV_SYNC_OTA_IND" type="SENDER"/>
	
	<RECEIVER id="EVT_ID_SRV_DTCNT_ACCT_DELETE_IND" proc="srv_sync_remote_accnt_evt_handlr"/>
	<RECEIVER id="EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND" proc="srv_sync_remote_accnt_evt_handlr"/>
	<RECEIVER id="EVT_ID_PHB_ADD_CONTACT" proc="srv_sync_contact_addition_notification"/>
	<RECEIVER id="EVT_ID_PHB_UPD_CONTACT" proc="srv_sync_contact_modification_notification"/>
	<RECEIVER id="EVT_ID_PHB_DEL_CONTACT" proc="srv_sync_contact_deletion_notification"/>
	
	#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
	<RECEIVER id="EVT_ID_SRV_TDL_EVENT_OP" proc="srv_sync_event_op_notify"/>	
	#endif
	
	#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
	<RECEIVER id="EVT_ID_SRV_TDL_OP" proc="srv_sync_task_op_notify"/>
	#endif
	
	#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
	#endif
	
	#ifdef __MMI_SYNCML_RESTORE_FACTORY_DEFAULT__
	<RECEIVER id="EVT_ID_SRV_RESTORE_START_NOTIFY" proc="srv_sync_clear_all_changelog"/>
	#endif
	
	<RECEIVER id="EVT_ID_SRV_REMINDER_BOOTUP_COMPLETE" proc="srv_sync_remote_accnt_evt_handlr"/>
	<RECEIVER id="EVT_ID_SRV_REMINDER_NOTIFY" proc="srv_sync_remote_rmdr_notify"/>
	
#endif  /*__SYNCML_SUPPORT__ */

#endif

</APP>



