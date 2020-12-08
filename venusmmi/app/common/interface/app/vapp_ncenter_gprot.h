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
 *  vapp_ncenter_table.h
 *
 * Project:
 * --------
 *  COSMOS Notification Center
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
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_NCENTER_GPROT_H__
#define __VAPP_NCENTER_GPROT_H__


#include "MMI_features.h"

#if defined(__MMI_NCENTER_SUPPORT__)


#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"

#ifdef __cplusplus

#if defined(__MMI_KEY_ONLY_NCENTER__)
#include "vapp_ncenter_pure_key_base_cell.h"
#else
#include "vapp_ncenter_base_cell.h"
#endif

#endif

/***************************************************************************** 
 * enum
 *****************************************************************************/

typedef enum
{
    EVT_ID_VAPP_NCENTER_DRAG = GET_RESOURCE_BASE(APP_NCENTER) + 1, 
    EVT_ID_VAPP_NCENTER_ENTER, 
    EVT_ID_VAPP_NCENTER_ENTERED, 
    EVT_ID_VAPP_NCENTER_EXIT, 
    EVT_ID_VAPP_NCENTER_EXITED,        
    MMI_NCENTER_EVENT_END_OF_ENUM
} vapp_ncenter_event_enum;


/***************************************************************************** 
 * External interface
 *****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

void vapp_ncenter_disable_leave(void);
void vapp_ncenter_disable_drag(void);
void vapp_ncenter_enable_drag(void);

BOOL vapp_ncenter_is_entered(void);

#if defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_KEY_ONLY_NCENTER__)
    extern mmi_ret vapp_ncenter_pure_key_routing_cb(mmi_event_struct *evt);
    extern mmi_ret vapp_ncenter_pure_key_bootup_handler(mmi_event_struct *evt);
#endif


#ifdef __cplusplus
}
#endif



#endif /* defined(__MMI_NCENTER_SUPPORT__) */


#endif /* __VAPP_NCENTER_GPROT_H__ */

