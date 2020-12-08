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
 * mmi_frm_at_util_gprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Events.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef MMI_FRM_AT_UTIL_GPROT_H
#define MMI_FRM_AT_UTIL_GPROT_H

#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
/*****************************************************************************
 * FUNCTION
 *  mmi_trace_screen_string
 * DESCRIPTION
 *  Sending the screen string
 *  
 * PARAMETERS
 *  x           [IN]
 *  y           [IN]
 *  str         [IN]
 *  len         [IN]
 *  Bordered    [IN]
 * RETURNS
 *  MMI_BOOL
*****************************************************************************/
extern MMI_BOOL mmi_trace_screen_string(S32 x, S32 y, U8 *str, S32 len, S32 Bordered);

/*****************************************************************************
 * FUNCTION
 *  mmi_trace_screen_char
 * DESCRIPTION
 *  Sending the screen char
 *  
 * PARAMETERS
 *  x           [IN]
 *  y           [IN]
 *  unicode     [IN]
 *  len         [IN]
 *  Bordered    [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mmi_trace_screen_char(S32 x, S32 y, U16 unicode, S32 len, S32 Bordered);

#endif /* __MMI_SUPPORT_DUMP_SCREEN_STRING__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_dss_set_menu_highlight
 * DESCRIPTION
 *  set menu highlight for dumpping screen screen(dss)
 *  
 * PARAMETERS
 *  type        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_dss_set_menu_highlight(U16 type);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_dss_defer_dump_string
 * DESCRIPTION
 *  Notify dump screen string(dss) mechanism if need to defer dumping string
 *  
 * PARAMETERS
 *  type        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_dss_defer_dump_string(MMI_BOOL is_deferred);

#if defined(__OP11_ATK__) || defined(__AUTO_ATK__)
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_at_ram_usage_ind_hdlr
 * DESCRIPTION
 *  Ram usage indication handler
 *  
 * PARAMETERS
 *  para           [IN]
 *  src_mod        [IN]
 * RETURNS
 *  MMI_BOOL
*****************************************************************************/
extern MMI_BOOL mmi_frm_at_ram_usage_ind_hdlr(void *para, int src_mod);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_at_lauch_app_ind_hdlr
 * DESCRIPTION
 *  Lauch application indication handler
 *  
 * PARAMETERS
 *  para           [IN]
 *  src_mod        [IN]
 * RETURNS
 *  MMI_BOOL
*****************************************************************************/
extern MMI_BOOL mmi_frm_at_lauch_app_ind_hdlr(void *para, int src_mod);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_at_app_info_output_ind_hdlr
 * DESCRIPTION
 *  Application standard output or error message indication handler
 *  
 * PARAMETERS
 *  para           [IN]
 *  src_mod        [IN]
 * RETURNS
 *  MMI_BOOL
*****************************************************************************/
extern MMI_BOOL mmi_frm_at_app_info_output_ind_hdlr(void *para, int src_mod);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_send_at_app_info_output_res_req
 * DESCRIPTION
 *  Application standard output or error message response to L4C
 *  
 * PARAMETERS
 *  app_type    :[OUT]  0 is Java application and 1 is VRE application
 *  trace_type  :[OUT]  0 is error log and 1 is standard output
 *  length      :[OUT]  ucs2 encoded message bytes number include terminate character
 *  output      :[OUT]  output message encoded with UCS2 and append "..." when message length exceeds max buffer size
 * RETURNS
 *  MMI_BOOL
*****************************************************************************/
extern MMI_BOOL mmi_frm_send_at_app_info_output_res_req(kal_uint8 app_type, kal_uint8 trace_type, kal_uint16 length, kal_uint8 *output);

#endif /* defined(__OP11_ATK__) || defined(__AUTO_ATK__) */


#endif /* MMI_FRM_AT_UTIL_GPROT_H */

