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
 * PushSwitchSrvGprot.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SRV_PUSH_SWITCH_GPROT_H__
#define __SRV_PUSH_SWITCH_GPROT_H__

#include "MMI_features.h"
#ifdef __MMI_PUSH_TURN_ON_OFF_SWITCH__

#include "kal_general_types.h"
#include "MMIDataType.h"
#include "mmi_res_range_def.h"

#ifdef __cplusplus 
extern "C" {
#endif


/*****************************************************************************
 * Enum
 *****************************************************************************/
typedef enum
{
    SRV_PUSH_SWITCH_MODE_OFF    = 0,    /* turn off */
    SRV_PUSH_SWITCH_MODE_ON     = 1,    /* turn on */
    SRV_PUSH_SWITCH_MODE_END
} srv_push_switch_mode_enum;

typedef enum
{
    EVT_ID_SRV_PUSH_SWITCH_NOTIFY = SRV_PUSH_SWITCH_BASE,
    EVT_ID_SRV_PUSH_SWITCH_END
} srv_push_switch_event_enum;


/*****************************************************************************
 * Struct
 *****************************************************************************/
typedef struct
{
    MMI_EVT_PARAM_HEADER
} srv_push_switch_notify_evt_struct;


/*****************************************************************************
 * Extern func
 *****************************************************************************/
extern MMI_BOOL srv_push_switch_check_service_ready(void);
extern srv_push_switch_mode_enum srv_push_switch_get_mode(void);
extern MMI_BOOL srv_push_switch_set_mode(srv_push_switch_mode_enum mode);


#ifdef __cplusplus 
}
#endif

#endif /* __MMI_PUSH_TURN_ON_OFF_SWITCH__ */

#endif /* __SRV_PUSH_SWITCH_GPROT_H__ */

