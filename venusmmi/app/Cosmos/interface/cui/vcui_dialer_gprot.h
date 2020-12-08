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
 *  vcui_dialer_gprot.h
 *
 * Project:
 * --------
 *  Venus
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifndef __DIALER_CUI_GPROT_H__
#define __DIALER_CUI_GPROT_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include "MMIDataType.h"
#include "DialerCuiGprot.h"
#ifdef __cplusplus
}
#endif

#include "vfx_string.h"

extern "C"
{

typedef enum
{
    /* Classic dialer */
    VCUI_DIALER_TYPE_CLASSIC,

    /* SOS only dialer */
    VCUI_DIALER_TYPE_EMERGENCY,

    /* Total number of supported dialer. */
    VCUI_DIALER_TYPE_ADD_CALL,

    /* Unspecified dialer. */
    VCUI_DIALER_TYPE_UNSPECIFIED,

    VCUI_DIALER_TYPE_INVALID
} vcui_dialer_type_enum;


/* This is the structure for the EVT_ID_CUI_DIALER_CLOSE_REQ. */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER

    /* Type of the dialer. */
    vcui_dialer_type_enum type;
} vcui_dialer_close_req_evt_struct;


/* This is the structure for the EVT_ID_CUI_DIALER_CLOSED_IND. */
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER

    /* Type of the dialer. */
    vcui_dialer_type_enum type;
} vcui_dialer_closed_ind_evt_struct;


typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER

    /* Type of the dialer. */
    vcui_dialer_type_enum type;
} vcui_dialer_before_call_launched_evt_struct;


mmi_id vcui_dialer_create(mmi_id parent_id);
mmi_id vcui_dialer_create_ex(mmi_id parent_id, vcui_dialer_type_enum type);
void vcui_dialer_run(mmi_id cui_id);
void vcui_dialer_close(mmi_id cui_id);
void vcui_dialer_set_dial_string(mmi_id this_gid, const VfxWString &string);
const VfxWString &vcui_dialer_get_dial_string(mmi_id this_gid);
void vcui_dialer_set_phb_data(mmi_id this_gid, void *phb_data);
void *vcui_dialer_get_phb_data(mmi_id this_gid);

}

#endif /* __DIALER_CUI_GPROT_H__ */

