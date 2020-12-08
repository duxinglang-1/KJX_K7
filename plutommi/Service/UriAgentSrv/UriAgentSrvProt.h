/******************************************************************************
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
******************************************************************************/

/******************************************************************************
 *
 * Filename:
 * ---------
 *   UriAgentSrvProt.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   URI Agent internal structures, functions and macro definitions.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _URIAGENTPROT_H
#define _URIAGENTPROT_H

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "UriAgentSrvGprot.h"

#include "DebugInitDef_Int.h"
#include "app_ltlcom.h"
#include "kal_general_types.h"
#include "MMIDataType.h"

/****************************************************************************** 
 * Define
 ******************************************************************************/

#if 1
#define  SRV_URIAGENT_ASSERT(args)  MMI_ASSERT(args)
#else 
/* under construction !*/
#endif 

/****************************************************************************** 
 * Typedef
 ******************************************************************************/

/* MSG_ID_SRV_URIAGENT_INVOKE_URI_REQUEST_HDLR_CB_IND */
typedef struct
{
    LOCAL_PARA_HDR srv_uriagent_uri_request_hdlr_cb cb;
    S32 result;
    srv_uriagent_appid_enum ura_appid;
    srv_uriagent_appid_enum uha_appid;
} srv_uriagent_invoke_uri_request_hdlr_cb_ind_struct;

/****************************************************************************** 
 * External Function
 ******************************************************************************/

extern MMI_BOOL srv_uriagent_check_validity_of_scheme(const char *scheme);
extern MMI_BOOL srv_uriagent_check_validity_of_prefix(const char *prefix);

#endif /* _URIAGENTPROT_H */ 

