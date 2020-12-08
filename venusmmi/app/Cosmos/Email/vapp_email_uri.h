/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  Vapp_email_uri.h
 *
 * Project:
 * --------
 *  COSMOS Email URI support
 *
 * Description:
 * ------------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _VAPP_EMAIL_URI_H_
#define _VAPP_EMAIL_URI_H_

#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"

#ifdef __MMI_URI_AGENT__
typedef enum
{
    MMI_EMAIL_URI_TO_TYPE = 0,
    MMI_EMAIL_URI_CC_TYPE,
    MMI_EMAIL_URI_BCC_TYPE
} vapp_email_uri_addr_type_enum;

static void vapp_email_uri_mailto_send(void);
static void vapp_email_uri_mailto_back(void);
static void vapp_email_uri_mailto_back_interrupt(void);
static VfxBool vapp_email_uri_mailto_parser(void);
static VfxBool vapp_email_uri_mailto_parse_sector(
                                              char **parser_head,
                                              char **parser_tail,
                                              char **parser_ptr,
                                              char *parser,
                                              U16 parser_len,
                                              U16 *sector_len);
static void vapp_email_uri_mailto_fill_data(
                                           mmi_email_app_send_param_struct *param,
                                           U32 *param_fill_flag);
static VfxBool vapp_email_uri_mailto_convertor(
                                           char **src_ptr,
                                           U16 *src_len,
                                           char *buf_ptr,
                                           S32 buf_len,
                                           U16 *ucs2_len);
static VfxBool vapp_email_uri_mailto_fill_addr(
                                           char *data,
                                           U16 data_len,
                                           vapp_email_uri_addr_type_enum type,
                                           mmi_email_app_send_param_struct *parm);
static void vapp_email_uri_mailto_post_handler(void);

extern void vapp_email_uri_register(void);

#endif

#endif /* _VAPP_EMAIL_URI_H_ */

