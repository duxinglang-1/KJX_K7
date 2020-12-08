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
 *  ServiceMsgCuiGprot.h
 *
 * Project:
 * -------- 
 *  Service msg CUI
 *
 * Description:
 * ------------
 *  This file contains exported APIs of Service msg CUI.
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _SERVICEMSGCUIGPROT_H_
#define _SERVICEMSGCUIGPROT_H_

/***************************************************************************** 
 * Include
 *****************************************************************************/
//#include "MMI_include.h"
    #include "mmi_res_range_def.h"
    #include "MMIDataType.h"
    #include "MMI_features.h"
/***************************************************************************** 
 * Constant
 *****************************************************************************/

/***************************************************************************** 
 * Macro
 *****************************************************************************/

/***************************************************************************** 
 * Enum
 *****************************************************************************/
 #ifdef __WAP_PUSH_SUPPORT__
#ifndef __COSMOS_MMI_PACKAGE__
typedef enum
{
    EVT_ID_CUI_SERVICE_MSG_CLOSE_SETTING = (MMI_WAP_PUSH_BASE + 1),
    EVT_ID_CUI_SERVICE_MSG_CLOSE,

    EVT_ID_CUI_SERVICE_MSG_END
} cui_service_msg_evt_enum;
#endif
/***************************************************************************** 
 * Structure
 *****************************************************************************/
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
} cui_service_msg_setting_evt_struct;

typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
} cui_service_msg_evt_struct;

/***************************************************************************** 
 * Type Definition
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
extern mmi_id cui_service_msg_setting_create(mmi_id parent_gid);
extern void cui_service_msg_setting_run(mmi_id cui_gid);
extern void cui_service_msg_setting_close(mmi_id cui_gid);


#ifdef __MMI_PUSH_IN_MSG__
extern mmi_id cui_service_msg_menu_create(mmi_id parent_gid);
extern void cui_service_msg_menu_run(mmi_id cui_gid);
extern void cui_service_msg_menu_close(mmi_id cui_gid);
#endif /* __MMI_PUSH_IN_MSG__ */

#endif
/*****************************************************************************/

#endif /* _SERVICEMSGCUIGPROT_H_ */
