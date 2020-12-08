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
 *  DataLockSrv.c
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_DATA_LOCK__
#include "MMIDataType.h"
#include "CbmSrvGprot.h"
#include "NwInfoSrvGprot.h"
#include "cbm_api.h"
#include "Mmi_rp_srv_datalock_def.h"
#include "DataLockSrvGprot.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
static U8 g_data_lock_cbm_app_id;
/***************************************************************************** 
 * Functions
 *****************************************************************************/
//#ifdef __COSMOS_MMI_PACKAGE__
static void srv_data_lock_network_roaming_update_status(void);
//#endif
MMI_BOOL srv_data_lock_get_setting(void)
{
    U8 data;
    S16 error;
    ReadValue(NVRAM_SETTING_DATA_LOCK, &data, DS_BYTE, &error);
    return (MMI_BOOL)data;
}

void srv_data_lock_set_setting(MMI_BOOL data)
{
    U8 nvramData;
    S16 error;
#ifdef __COSMOS_MMI_PACKAGE__
    mmi_event_struct evt;    
#endif

    ReadValue(NVRAM_SETTING_DATA_LOCK, &nvramData, DS_BYTE, &error);
    if (data != (MMI_BOOL)nvramData)
	{
	    WriteValue(NVRAM_SETTING_DATA_LOCK, &data, DS_BYTE, &error);
	}

    if (g_data_lock_cbm_app_id == 0)
	{
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[DataLockSrv.c] g_data_lock_cbm_app_id %d", g_data_lock_cbm_app_id);
	    return;
	}

    if (data == MMI_FALSE)
	{
	    srv_cbm_disallow_nwk_srv(SRV_CBM_BEARER_CSD | SRV_CBM_BEARER_PS | SRV_CBM_BEARER_LOCAL, g_data_lock_cbm_app_id);
	}
    else
    {
        srv_data_lock_network_roaming_update_status();
    }
    
#ifdef __COSMOS_MMI_PACKAGE__
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DATA_LOCK_UPDATE);
    MMI_FRM_CB_EMIT_EVENT(&evt);
#endif
}

//#ifdef __COSMOS_MMI_PACKAGE__
/* Network roaming feature is only supported on COSMOS */
MMI_BOOL srv_data_lock_network_roaming_get_setting(void)
{
    U8 data;
    S16 error;
    ReadValue(NVRAM_SETTING_NETWORK_ROAMING, &data, DS_BYTE, &error);
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[DataLockSrv.c] srv_data_lock_network_roaming_get_setting %d", data);
    return (MMI_BOOL)data;
}

void srv_data_lock_network_roaming_set_setting(MMI_BOOL data)
{
    U8 nvramData;
    S16 error;
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[DataLockSrv.c] srv_data_lock_network_roaming_set_setting %d", data);
	
    ReadValue(NVRAM_SETTING_NETWORK_ROAMING, &nvramData, DS_BYTE, &error);
    if (data != (MMI_BOOL)nvramData)
	{
	    WriteValue(NVRAM_SETTING_NETWORK_ROAMING, &data, DS_BYTE, &error);
	}
    srv_data_lock_network_roaming_update_status();    
}

static void srv_data_lock_network_roaming_update_status(void)
{
    U32 i;
    if (g_data_lock_cbm_app_id == 0)
	{
	    return;
	}
    for (i = 0; i < MMI_MAX_SIM_NUM; i++)
    {
	    mmi_sim_enum sim = mmi_frm_index_to_sim(i);
        MMI_BOOL is_roaming = srv_nw_info_is_roaming(sim);
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[DataLockSrv.c] srv_data_lock_network_roaming_update_status is_roaming %d", is_roaming);
        if (is_roaming && srv_data_lock_network_roaming_get_setting() == MMI_FALSE)
    	{
            MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[DataLockSrv.c] Disable %d", i);
    	    srv_cbm_disallow_nwk_srv_by_sim((cbm_sim_id_enum)i, SRV_CBM_BEARER_CSD | SRV_CBM_BEARER_PS | SRV_CBM_BEARER_LOCAL, g_data_lock_cbm_app_id);
    	}
        else
        {
            MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[DataLockSrv.c] Enable %d", i);
    	    srv_cbm_allow_nwk_srv_by_sim((cbm_sim_id_enum)i, SRV_CBM_BEARER_CSD | SRV_CBM_BEARER_PS | SRV_CBM_BEARER_LOCAL, g_data_lock_cbm_app_id);        
        }
    }

}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

mmi_ret srv_data_lock_network_roaming_check_hdlr(mmi_event_struct *evt)
{
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[DataLockSrv.c] srv_data_lock_network_roaming_check_hdlr");
    if (evt->evt_id == EVT_ID_SRV_NW_INFO_ROAMING_STATUS_CHANGED 
        && srv_data_lock_network_roaming_get_setting() == MMI_FALSE
        && g_data_lock_cbm_app_id != 0)
	{
        srv_nw_info_roaming_status_changed_evt_struct *roaming_change_evt = (srv_nw_info_roaming_status_changed_evt_struct*)evt;
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[DataLockSrv.c] Roaming state changed %d %d", roaming_change_evt->is_roaming_now, roaming_change_evt->sim);
        if (roaming_change_evt->is_roaming_now)
    	{
    	    srv_cbm_disallow_nwk_srv_by_sim((cbm_sim_id_enum)mmi_frm_sim_to_index(roaming_change_evt->sim), SRV_CBM_BEARER_CSD | SRV_CBM_BEARER_PS | SRV_CBM_BEARER_LOCAL, g_data_lock_cbm_app_id);
    	}
        else
        {
    	    srv_cbm_allow_nwk_srv_by_sim((cbm_sim_id_enum)mmi_frm_sim_to_index(roaming_change_evt->sim), SRV_CBM_BEARER_CSD | SRV_CBM_BEARER_PS | SRV_CBM_BEARER_LOCAL, g_data_lock_cbm_app_id);        
        }
	}
    return MMI_RET_OK;
}

//#endif /* __COSMOS_MMI_PACKAGE__ */

/*****************************************************************************
 * FUNCTION
 *  srv_data_lock_init
 * DESCRIPTION
 *  Init handler for data lock 
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_data_lock_init(mmi_event_struct *evt)
{
    cbm_app_info_struct info;

    info.app_str_id = STR_ID_SRV_DATA_LOCK;
    info.app_icon_id = 0;
    info.app_type = DTCNT_APPTYPE_NONE;
    
    cbm_register_app_id_with_app_info(&info, &g_data_lock_cbm_app_id);
    
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[DataLockSrv.c] g_data_lock_cbm_app_id %d", g_data_lock_cbm_app_id);
    
    srv_data_lock_set_setting(srv_data_lock_get_setting());
    
    return MMI_RET_OK;
}
#endif
