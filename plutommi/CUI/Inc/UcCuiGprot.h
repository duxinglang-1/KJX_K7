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
 * UcCuiGprot.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file have UC application core part.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *============================================================================
 ****************************************************************************/
#ifndef _MMI_UNIFIED_COMPOSER_CUI_GPROT_H
#define _MMI_UNIFIED_COMPOSER_CUI_GPROT_H
//suggested add
    #include "MMIDataType.h"
    #include "UcSrvGprot.h"
    //#include "kal_general_types.h"
//end
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))

#include "UcAppGProt.h" /* Unifide composer application global header file */


/*****************************************************************************
 * FUNCTION
 *  cui_uc_write_msg_launch
 * DESCRIPTION
 *  Launch write message editor cui from the message menu.
 * PARAMETERS
 *  parent_grp_id : [IN]        parent id of screen group passed by caller      
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_uc_write_msg_launch(mmi_id parent_grp_id);

/*****************************************************************************
 * FUNCTION
 *  cui_uc_write_msg_create
 * DESCRIPTION
 *  create the cui id of unified composer.
 * PARAMETERS
 *  parent_grp_id : [IN]        parent id of screen group passed by caller        
 * RETURNS
 *  created cui id
 *****************************************************************************/
 extern mmi_id cui_uc_write_msg_create(mmi_id parent_gid);
 
 /*****************************************************************************
 * FUNCTION
 *  cui_uc_write_msg_with_content_launch
 * DESCRIPTION
 *  Launch editor with content. It can be called by any application.
 * PARAMETERS
 *  cui_gid : [IN]        cui group id
 *  type : [IN]        mmi_uc_done_type_enum
 *  data : [IN]        uc assential data context 'mmi_uc_entry_write_struct' passed by caller filled with proper data
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_uc_write_msg_with_content_launch(mmi_id cui_gid, mmi_uc_done_type_enum type, mmi_uc_entry_write_struct *data);

/*****************************************************************************
 * FUNCTION
 *  cui_uc_launch
 * DESCRIPTION
 *  Launch editor cui from MMS application
 * PARAMETERS
 *  cui_gid : [IN]        cui group id
 *  msg_req : [IN]        uc start req structue filed by mms app.     
 * RETURNS
 *  void
 *****************************************************************************/
extern U32 cui_uc_write_msg_from_mms_launch(mmi_id cui_gid, mmi_uc_start_struct *msg_req);

/*****************************************************************************
 * FUNCTION
 *  cui_uc_write_msg_close
 * DESCRIPTION
 *  Close the group id craeted for the write message cui launch.
 * PARAMETERS
 *  cui_gid : [IN]        cui group id        
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_uc_write_msg_close(mmi_id cui_gid);
/*****************************************************************************
 * FUNCTION
 *  cui_uc_entry_msg_operation_launch
 * DESCRIPTION
 *  Api to launch the operation via UC over a SMS.
 *  Here possible operations are edit, forward, reply and Send.
 * PARAMETERS
 *  cui_gid : [IN]        cui group id
 *  msg_id : [IN]        msg_id of the msg
 *  msg_id : [IN]        message type sms/mms
 *  operation : [IN]        mmi_uc_msg_operation_enum edit/reply...
 * RETURNS
 *  MMI_TRUE:   Success
 *  MMI_FALSE:  Failure
 *****************************************************************************/
extern MMI_BOOL cui_uc_entry_msg_operation_launch( mmi_id cui_gid, U32 msg_id, U16 msg_type, mmi_uc_msg_operation_enum operation);
#endif
#endif
