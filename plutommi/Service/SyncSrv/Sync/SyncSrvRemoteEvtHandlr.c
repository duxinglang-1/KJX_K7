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
 * SyncSrvRemoteEvtHandlr.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Alarm service management.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

/*****************************************************************************
* Header files
*****************************************************************************/
#include "global_def.h"
#include "DtcntSrvGprot.h"
#include "ReminderSrvGprot.h"
#include "BootupSrvGprot.h"
#include "common_nvram_editor_data_item.h"
#include "cbm_api.h"

#include "mmi_rp_srv_reminder_def.h"
#include "mmi_rp_srv_sync_def.h"

#include "SyncSrv.h"
#include "SyncSrvRemoteSync.h"
#include "SyncSrvRemoteAccnt.h"

/*****************************************************************************
* Define
*****************************************************************************/
#define INVALID_NETID 0xFFFFFFFF

/*****************************************************************************
* Typedef 
*****************************************************************************/
typedef nvram_ef_syncml_account_struct srv_sync_remote_accnt_type;

/*****************************************************************************
* Global Variables 
*****************************************************************************/

/*****************************************************************************
* Local Variables 
*****************************************************************************/
static U32 g_srv_sync_netid_buffer[MAX_SYNCML_SV_PROFILES][MAX_SIM_NUM];

/*****************************************************************************
* Local Function 
*****************************************************************************/
static void srv_sync_remote_reset_netid(U32 accnt_id, U32 sim_id)
{
  	/*----------------------------------------------------------------*/
  	/* Local Variables												  */
  	/*----------------------------------------------------------------*/
    srv_sync_remote_accnt_type *accnt;
    U32 new_netid;
      
  	/*----------------------------------------------------------------*/
  	/* Code Body													  */
  	/*----------------------------------------------------------------*/
    // encode the net_id as default net id.
    new_netid = cbm_encode_data_account_id(
    					CBM_DEFAULT_ACCT_ID,
    					(cbm_sim_id_enum)sim_id,
    					srv_sync_remote_app_id(),
    					KAL_FALSE);

    // update the accnt infomation
    accnt = (srv_sync_remote_accnt_type *)srv_sync_remote_read_accnt(accnt_id);
    accnt->net_id[sim_id] = new_netid;
    
    srv_sync_remote_write_accnt(accnt, accnt_id);
}


static void srv_sync_remote_check_netid(U32 accnt_id)
{
  	/*----------------------------------------------------------------*/
  	/* Local Variables												  */
  	/*----------------------------------------------------------------*/
    U32 j, k;
    
  	/*----------------------------------------------------------------*/
  	/* Code Body													  */
  	/*----------------------------------------------------------------*/
    for (j = 0; j < MAX_SYNCML_SV_PROFILES; j++)
    {          
        for (k = 0; k < MAX_SIM_NUM; k++)
        {
            if (g_srv_sync_netid_buffer[j][k] == INVALID_NETID)
            {
              continue;
            }
            
            if (accnt_id == (U32)cbm_get_original_account(g_srv_sync_netid_buffer[j][k]))
            {
                srv_sync_remote_reset_netid(j, k);
            }
        }
    }
}


static mmi_ret srv_sync_remote_dtcnt_del_notify(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_dtcnt_acct_delete_ind_evt_struct *dtcnt_evt;
	dtcnt_evt = (srv_dtcnt_acct_delete_ind_evt_struct *)evt;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(dtcnt_evt != NULL, MMI_RET_OK);
	
	SRV_SYNC_LOG1(MMI_SYNC_SRV_RMT_EVT_DEL_NOTIFY, dtcnt_evt->del_num);
	
  	if ((dtcnt_evt->del_num != 0) && 
        ((dtcnt_evt->cause == 0) || (dtcnt_evt->cause == 1)))
	{
  		U32 i;
        
  		for (i = 0; i < dtcnt_evt->del_num; i++)
  		{
            srv_sync_remote_check_netid(dtcnt_evt->acc_id[i]);
  		}
	}

	return MMI_RET_OK;
}


static mmi_ret srv_sync_remote_dtcnt_update_notify(mmi_event_struct *evt)
{
  	/*----------------------------------------------------------------*/
  	/* Local Variables												  */
  	/*----------------------------------------------------------------*/
  	srv_dtcnt_acct_update_ind_evt_struct *dtcnt_evt;
  	dtcnt_evt = (srv_dtcnt_acct_update_ind_evt_struct *)evt;
  	
  	/*----------------------------------------------------------------*/
  	/* Code Body													  */
  	/*----------------------------------------------------------------*/
  	RETURN_VAL_IF_FAIL(dtcnt_evt != NULL, MMI_RET_OK);
  	 	
  	if (dtcnt_evt->cause == 1)
  	{	
        srv_sync_remote_check_netid(dtcnt_evt->acc_id);  		
  	}

	return MMI_RET_OK;
}


static mmi_ret srv_sync_remote_pwron_notify(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SYNC_SRV_RMT_EVT_PWRON_NOTIFY);

	srv_sync_remote_regular_check((U8)SRV_SYNC_REGULAR_AT_PWRON, 0);
    srv_sync_check_regular_sync();

	// should also check data change notify. user may hasn't 
	
	return MMI_RET_OK;
}


void srv_sync_remote_set_netid_info(U8 accnt_index, void *accnt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_remote_accnt_type *remote_accnt = (srv_sync_remote_accnt_type *)accnt;
    
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
    if (remote_accnt->timestamp != 0)
    {
       	kal_mem_cpy(g_srv_sync_netid_buffer[accnt_index], remote_accnt->net_id, sizeof(U32) * MAX_SIM_NUM);
    }
    else
    {
    	memset(g_srv_sync_netid_buffer[accnt_index], 0xFF, sizeof(U32) * MAX_SIM_NUM);
    }
}


mmi_ret srv_sync_remote_accnt_evt_handlr(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SYNC_SRV_RMT_EVT_HDLR);

	MMI_ASSERT(evt != NULL);
	
	switch (evt->evt_id)
	{
		case EVT_ID_SRV_DTCNT_ACCT_DELETE_IND:
		{
			srv_sync_remote_dtcnt_del_notify(evt);
			break;
		}
        case EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND:
        {
            srv_sync_remote_dtcnt_update_notify(evt);
            break;
        }        
		case EVT_ID_SRV_REMINDER_NOTIFY:
		{
			srv_sync_remote_rmdr_notify(evt);
			break;
		}
		case EVT_ID_SRV_BOOTUP_COMPLETED:
		{
			srv_sync_remote_pwron_notify(evt);
			break;
		}	
		default:
			break;
	}
	
	return MMI_RET_OK;
}


