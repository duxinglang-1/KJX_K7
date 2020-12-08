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
 *   DataAccountCui.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Data Account header file.
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
 *==============================================================================
 *******************************************************************************/
#ifndef CUI_DTCNT_H
#define CUI_DTCNT_H

#include "..\Inc\DataAccountCuiGprot.h"
#include "DataAccountDef.h"
#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#include "wgui_categories_list.h"
#include "MMI_features.h"
#include "kal_general_types.h"
#include "DataAccountGProt.h"
#include "DtcntSrvGprot.h"
#include "mmi_frm_utility_gprot.h"

/*******************************************************************************
* Include Header File
*******************************************************************************/

/*******************************************************************************
* Macro Define
*******************************************************************************/
#ifdef __SLIM_NWK_PROFILE__
#define CUI_DTCNT_MAX_BEARER_LIST_NUM 2
#else
#define CUI_DTCNT_MAX_BEARER_LIST_NUM 6
#endif

typedef enum
{
    CUI_DTCNT_SCREEN_GROUP = DATA_ACCOUNT_BASE + 1,
    CUI_DTCNT_SCREEN_GROUP_ALL
} cui_dtcnt_screen_group_enum;

typedef enum
{
    CUI_DTCNT_ITEM_NONE,
    CUI_DTCNT_ITEM_AUTO,
    CUI_DTCNT_ITEM_ALWAYS_ASK,
    CUI_DTCNT_ITEM_WIFI,
    CUI_DTCNT_ITEM_WIFI_LIST,
    CUI_DTCNT_ITEM_CSD,
    CUI_DTCNT_ITEM_GPRS,
    CUI_DTCNT_ITEM_TOTAL    
}cui_dtcnt_item_type_enum; 


typedef struct
{
    U32 profile_id;
    U16 item_name_str_id;
    cui_dtcnt_item_type_enum item_type;
}cui_dtcnt_list_disp_struct;


typedef struct
{
    cui_dtcnt_item_type_enum item_type;
    U16 item_name;
}cui_dtcnt_select_item_struct;

typedef struct
{
    U8 valid;
    U8 current_item_selected;
    U8 bearers;
    U8 app_id;
    U16 app_str_id;
    U16 app_icon_id;
    U16 app_menu_id;
    U16 curr_sim_list_index;
    U16 avail_sim_enum[MMI_SIM_TOTAL];
    MMI_BOOL sim_list_existed; // show sim list before choose data account
    mmi_sim_enum sim_enum; // this value used to display which sim's account
    U32 list_item_number;
    U32 sim_account_id[MMI_SIM_TOTAL];
    mmi_id curr_cui_id;
    cui_dtcnt_list_disp_struct list_info[MMI_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM + MAX_DATA_ACCOUN_CUI_FIX_ITEM];
    cui_dtcnt_select_option_enum option;
    cui_dtcnt_select_type_enum type;
    cui_dtcnt_select_sim_enum sim_selection;
}cui_dtcnt_select_account_option_struct;


/*******************************************************************************
* Export API 
*******************************************************************************/

#endif /* CUI_CAMERACUI_H */ 

