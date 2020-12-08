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
 *   mms_adp.h
 *
 * Project:
 * --------
 *   Maui_Software
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMS_ADP_H
#define _MMS_ADP_H

#include "kal_general_types.h"
#include "stack_config.h"

/*****************************************************************************
 * FUNCTION
 *  mms_on_enter_usb_mode 
 * DESCRIPTION
 *  This function is used by MMI USB application to inform MMS solution that user wants to enter USB mode. MMS solution has to send MSG_ID_MMS_ENTER_USB_RSP to MOD_MMI after MMS solution is ready to enter USB mode. Otherwise, MMI will stay in progress screen forever. 
 * PARAMETERS
 *  none
 * RETURNS
 *  none
*****************************************************************************/
extern void mms_on_enter_usb_mode(void);

/*****************************************************************************
 * FUNCTION
 *  mms_on_exit_usb_mode 
 * DESCRIPTION
 *  This function is used by MMI USB application to inform MMS solution that user wants to exit USB mode. MMS solution has to send MSG_ID_MMS_EXIT_USB_RSP to MOD_MMI after MMS solution is ready to exit USB mode. Otherwise, MMI will stay in progress screen forever. 
 * PARAMETERS
 *  none
 * RETURNS
 *  none
*****************************************************************************/
extern void mms_on_exit_usb_mode(void);

/*****************************************************************************
 * FUNCTION
 *  mms_owner_number_indication_callback 
 * DESCRIPTION
 *  This function is used by MMI SIM application to inform MMS solution of owner number per sim card.
 * PARAMETERS
 *  sim_id 			 : [IN] 0:SIM1, 1: SIM2
 *  owner_number : [IN] owner number encoded by ASCII
 * RETURNS
 *  none
*****************************************************************************/
extern void mms_owner_number_indication_callback(kal_uint8 sim_id, const kal_wchar *owner_number);

/*****************************************************************************
 * FUNCTION
 *  mms_plmn_number_indication_callback 
 * DESCRIPTION
 *  This function is used by MMI SIM application to inform MMS solution of PLMN of operator (only support SIM1).
 * PARAMETERS
 *  plmn_number : [IN] PLMN of operator
 * RETURNS
 *  none
*****************************************************************************/
extern void mms_plmn_number_indication_callback(const unsigned char *plmn_number);

/*****************************************************************************
 * FUNCTION
 *  mms_roaming_status_indication_callback 
 * DESCRIPTION
 *  This function is used by MMI SIM application to inform MMS solution of roaming status per sim card.
 * PARAMETERS
 *  simId 		: [IN] 0:SIM1, 1: SIM2
 *  isRoaming : [IN] 0:FALSE,1: TRUE
 * RETURNS
 *  none
*****************************************************************************/
extern void mms_roaming_status_indication_callback(int simId, unsigned long isRoaming);

/*****************************************************************************
 * FUNCTION
 *  mms_get_service_module 
 * DESCRIPTION
 *  This function is used by who wants to send primitive to MMS solution to get module id of MMS solution.
 *  Depends of systtem architecture of MMS solution, primitives may be handled in MOD_MMI, MOD_WAP or MOD_MMS.
 * PARAMETERS
 *  msg_id : [IN] primitive id, ex:MSG_ID_MEA_STARTUP_NEW_MMS_REQ
 * RETURNS
 *  module_type (Module ID, ex: MOD_MMI, MOD_WAP or MOD_MMS)
*****************************************************************************/
extern module_type mms_get_service_module(kal_uint32 msg_id);
#endif /*_MMS_ADP_H*/
