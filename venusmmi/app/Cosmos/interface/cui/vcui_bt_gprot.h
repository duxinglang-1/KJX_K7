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
 *  vcui_bt_gprot.h
 *
 * Project:
 * --------
 *  Cosmos
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h" 
#ifndef __VCUI_BT_GPROT_H__
#define __VCUI_BT_GPROT_H__

#ifdef __MMI_BT_SUPPORT__
extern "C" {
#include "MmiDataType.h"
#include "BtcmSrvGprot.h"
}

#include "vfx_datatype.h"

extern "C"
{
    typedef enum 
    {
        EVT_ID_GROUP_CUI_BT_SELECT_DEVICE = VCUI_BT_SELDEV + 1,
        EVT_ID_GROUP_CUI_BT_POWER_ON = VCUI_BT_POWERON + 1,
        EVT_ID_GROUP_CUI_BT_TOTAL
    } cui_bt_event_enum;
    
    typedef struct
    {
        U32 cod_mask;               // device cod
        U32 service_id;             // service ID
    } cui_bt_select_device_struct;

    typedef struct
    {
        MMI_EVT_GROUP_PARAM_HEADER
        mmi_id cui_id;
        VfxBool result;
        srv_bt_cm_dev_struct dev_info;
    } cui_bt_select_device_result;


    typedef enum
    {
        CUI_BT_POWER_ON_WITHOUT_CONFIRM,
        CUI_BT_POWER_ON_WITH_FLIGHT_MODE_CONFIRM_ONLY,
        CUI_BT_POWER_ON_WITH_ALL_CONFIRM,
        CUI_BT_POWER_ON_CONFIRM_TYPE_TOTAL
    } cui_bt_power_on_show_confirm_type_enum;

    typedef struct
    {
        U32 confirm_type;
    } cui_bt_power_on_struct;

    typedef struct
    {
        MMI_EVT_GROUP_PARAM_HEADER
        mmi_id cui_id;
        VfxBool result;
    } cui_bt_power_on_result;


    extern mmi_id vcui_bt_select_device_create(mmi_id appId, cui_bt_select_device_struct* para);

    extern void vcui_bt_select_device_run(mmi_id cui_id);

    extern void vcui_bt_select_device_close(mmi_id cui_id);

    extern mmi_id vcui_bt_power_on_create(mmi_id appId, cui_bt_power_on_struct* para);

    extern void vcui_bt_power_on_run(mmi_id cui_id);

    extern void vcui_bt_power_on_close(mmi_id cui_id);


    // should not use this API, will remove
    extern VfxBool vcui_bt_power_on(mmi_id appId, cui_bt_power_on_struct* para);
}

#endif  // __MMI_BT_SUPPORT__
#endif  // __VCUI_BT_GPROT_H__



