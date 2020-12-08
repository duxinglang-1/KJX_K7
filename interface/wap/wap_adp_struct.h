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
 *   das_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for local parameter declaration about DAS SAP
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *                              HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _WAP_ADP_STRUCT_H
#define _WAP_ADP_STRUCT_H 

#include "kal_general_types.h"
#include "app_ltlcom.h"
#include "MMI_features.h"

/* Send indication to SAT application about the termination of browser */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8 cause;  /* Cause of termination, refer to 'sat_browser_termination_mode_enum' */
} wap_mmi_browser_termination_ind_struct;

#ifdef OBIGO_Q03C

/* For Obigo Q03C only, bypass MMI key event to WAP task */
typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint16 keycode;  /* Key code for generated event */
    kal_uint16 keytype;  /* Key type for generated event */
} wap_mmi_key_indication_struct;


/* For Obigo Q03C only, return the information of PUSH messages */
typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32 total_unread_num;  /* The number of total unread messages */
    kal_int32 tone_id;           /* Tone id for messages */
  #ifdef __MMI_WAP_DUAL_SIM__
    kal_int32 sim_information;   /* SIM information for the message */
  #endif  /* __MMI_WAP_DUAL_SIM__ */
} wap_mmi_nmgr_push_info_rsp_struct;

#endif /* OBIGO_Q03C */
#endif /* _WAP_ADP_STRUCT_H */
