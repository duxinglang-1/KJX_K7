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
 * MsgViewerCuiAdp.c
 *
 * Project:
 * --------
 * MAUI
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
#include "MMI_include.h"

#include "MsgViewerCui.h"
#include "MsgViewerCuiGProt.h"
#include "SmsAppGprot.h"
#ifdef __MMI_MMS_2__
#include "MMSAppCommonGprot.h"   /* mmi_umms_app_if_start_viewer */
#endif /* __MMI_MMS_2__ */

#ifndef __COSMOS_MMI_PACKAGE__
#ifdef WAP_SUPPORT
#include "WAPPushGprots.h" /* mmi_wap_push_if_launch_viewer */
#endif /* WAP_SUPPORT */
#endif /*__COSMOS_MMI_PACKAGE__*/

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
#include "ProvBoxAppGProt.h" /* mmi_provboxui_launch_viewer */
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */

cui_msg_viewer_launch_ptr cui_msg_viewer_adp_get_viewer_ptr(srv_um_msg_enum msg_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_msg_viewer_launch_ptr func_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_type)
    {
        case SRV_UM_MSG_SMS:
        {
            break;
        }
    #ifdef __MMI_MMS_2__
        case SRV_UM_MSG_MMS:
        {
            break;
        }
    #endif /* __MMI_MMS_2__ */
    #ifdef WAP_SUPPORT
        case SRV_UM_MSG_WAP_PUSH:
        {
            break;
        }
    #endif /* WAP_SUPPORT */
    #ifdef __MMI_PROV_MESSAGE_SUPPORT__
        case SRV_UM_MSG_PROV:
        {
            break;
        }
    #endif /* __MMI_PROV_MESSAGE_SUPPORT__ */
        default:
        {
            MMI_ASSERT(0);
        }
    }

    return func_ptr;
}


void cui_msg_viewer_adp_launch_viewer_ptr(srv_um_msg_enum msg_type, 
                                          mmi_id parent_grp_id, 
                                          U32 msg_id, 
                                          void *user_data, 
                                          cui_msg_viewer_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_type)
    {
        case SRV_UM_MSG_SMS:
        {
            mmi_sms_launch_viewer(parent_grp_id, msg_id, user_data, type);
            break;
        }
    #ifdef __MMI_MMS_2__
        case SRV_UM_MSG_MMS:
        {
            mmi_umms_app_if_start_viewer(parent_grp_id, msg_id, user_data, type);
            break;
        }
    #endif /* __MMI_MMS_2__ */
    #ifdef __WAP_PUSH_SUPPORT__
        case SRV_UM_MSG_WAP_PUSH:
        {
			#ifndef __COSMOS_MMI_PACKAGE__
            mmi_wap_push_if_launch_viewer(parent_grp_id, msg_id, user_data, type);
			#endif /*__COSMOS_MMI_PACKAGE__*/
            break;
        }
    #endif /* WAP_SUPPORT */
    #ifdef __MMI_PROV_MESSAGE_SUPPORT__
        case SRV_UM_MSG_PROV:
        {
        #ifdef __MMI_PROV_IN_UM__
            mmi_provbox_um_iter_launch_viewer(parent_grp_id, msg_id, user_data, type);
        #endif
            break;
        }
    #endif /* __MMI_PROV_MESSAGE_SUPPORT__ */
        default:
        {
            MMI_ASSERT(0);
        }
    }
}
