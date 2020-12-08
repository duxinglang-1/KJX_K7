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
 * SyncSrvCM.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * connect manager of sync
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"

/*****************************************************************************
* Header files
*****************************************************************************/
#include "Cbm_api.h"
#include "custom_data_account.h"
#include "CbmSrvGprot.h"
#include "DtCntSrvGprot.h"
#include "ImeiSrvGprot.h"

#include "SyncSrvGprot.h"
#include "SyncSrvCm.h"
#include "SyncSrvRemoteSync.h"
#include "SyncSrvSync.h"

/*****************************************************************************
* Typedef 
*****************************************************************************/
typedef struct
{
	srv_sync_cm_type *active_cm;
	kal_uint32 conn_id;	/* net id */
	kal_uint8 app_id;	/* app id for cbm*/
	MMI_BOOL connecting;	
}srv_sync_cm_cbm_cntx_struct;

/*****************************************************************************
* Global Variables 
*****************************************************************************/

/*****************************************************************************
* Local Variables 
*****************************************************************************/
static srv_sync_cm_cbm_cntx_struct g_srv_cm_cbm_cntx;

#define SRV_SYNC_SET_ACTIVE_CM(_cm) (g_srv_cm_cbm_cntx.active_cm = (_cm))

/*****************************************************************************
 * Local Function 
 *****************************************************************************/
static mmi_ret srv_sync_cm_cbm_bearer_callback(mmi_event_struct *param);
static void srv_sync_cm_cbm_on_disconn(srv_sync_cm_type *obj, void *param);


U8 srv_sync_remote_app_id(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SYNC_SRV_RMT_SYNC_APPID);
	return g_srv_cm_cbm_cntx.app_id;
}

void srv_sync_cm_cbm_init(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	cbm_app_info_struct info;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SYNC_SRV_RMT_SYNC_INIT);
	
    info.app_type = DTCNT_APPTYPE_SYNCML;
    info.app_icon_id = 0;
	info.app_str_id = 1;

	memset(&g_srv_cm_cbm_cntx, 0, sizeof(srv_sync_cm_cbm_cntx_struct));
	
    /* register app_id */
    MMI_ASSERT(CBM_OK == cbm_register_app_id_with_app_info(&info, &g_srv_cm_cbm_cntx.app_id));
	
    /* register diconnection function for syncml app */
    srv_cbm_register_bearer_info(
        g_srv_cm_cbm_cntx.app_id, 
		SRV_CBM_ACTIVATED | SRV_CBM_DEACTIVATED, 
		SRV_CBM_BEARER_PS | SRV_CBM_BEARER_GPRS | SRV_CBM_BEARER_WIFI,
        (mmi_proc_func)srv_sync_cm_cbm_bearer_callback, 
        &g_srv_cm_cbm_cntx);
	
}

static mmi_ret srv_sync_cm_cbm_bearer_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_sync_cm_cbm_cntx_struct *cntx = (srv_sync_cm_cbm_cntx_struct *)param->user_data;
	srv_cbm_bearer_info_struct *bearer_info = (srv_cbm_bearer_info_struct *)param;	
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SYNC_LOG3(MMI_SYNC_SRV_CBM_CALLBACK, bearer_info->error, bearer_info->state, cntx->connecting);
	
    if (SRV_CBM_DISC_BY_CM == bearer_info->error)
    {
        srv_sync_abort(SRV_SYNC_REMOTE);

		return MMI_RET_OK;
    }

	if (bearer_info->state == SRV_CBM_DEACTIVATED || !srv_sync_is_state(SRV_SYNC_STATE_SYNCING))
	{
		cbm_release_bearer(cntx->app_id);
	}

	if (!srv_sync_is_state(SRV_SYNC_STATE_SYNCING))
	{
		srv_sync_cm_on_disconn(cntx->active_cm, cntx);
		
		return MMI_RET_OK;
	}

	if (!cntx->connecting)
	{
		return MMI_RET_OK;
	}

	if (bearer_info->state == SRV_CBM_ACTIVATED)
	{
		srv_sync_cm_on_connected(cntx->active_cm, cntx);
	}
	else if (bearer_info->state == SRV_CBM_DEACTIVATED)
	{			

		srv_sync_cm_on_disconn(cntx->active_cm, cntx);
	}
	else
	{
		// NOP
	}

	return MMI_RET_OK;
}

static MMI_BOOL srv_sync_cm_cbm_conn(srv_sync_cm_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  	   */
	/*----------------------------------------------------------------*/
	srv_sync_cm_cbm_cntx_struct *cntx = GET_OBJ_PRIV(srv_sync_cm_cbm_cntx_struct, obj);
	S32 ret;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  	   */
	/*----------------------------------------------------------------*/
	ret = cbm_open_bearer(cntx->conn_id);

	SRV_SYNC_LOG1(MMI_SYNC_SRV_CBM_CONN, ret);
	
	switch (ret)
	{
		case CBM_WOULDBLOCK:
			cntx->connecting = MMI_TRUE;
			break;
			
		case CBM_OK:
			srv_sync_cm_on_connected(obj, cntx);
			break;
			
		default:
			return MMI_FALSE;
	}

	return MMI_TRUE;
}

static void srv_sync_cm_cbm_on_connected(srv_sync_cm_type *obj, void *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_cm_cbm_cntx_struct *cntx = GET_OBJ_PRIV(srv_sync_cm_cbm_cntx_struct, obj);
	CHAR imei[SRV_IMEI_MAX_LEN + 1];
	srv_dtcnt_sim_type_enum sim_id;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	cntx->connecting = MMI_FALSE;

	srv_dtcnt_get_sim_preference(&sim_id);
	if (sim_id == SRV_DTCNT_SIM_TYPE_NONE)
	{
		sim_id = SRV_DTCNT_SIM_TYPE_1;
	}

	SRV_SYNC_LOG1(MMI_SYNC_SRV_CBM_ON_CONN, sim_id);
	
	srv_imei_get_imei(mmi_frm_index_to_sim(sim_id - 1), imei, (SRV_IMEI_MAX_LEN + 1));
	
	srv_sync_remote_start(srv_sync_active_sync(), (U8 *)imei);
}

static void srv_sync_cm_cbm_disconn(srv_sync_cm_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_cm_cbm_cntx_struct *cntx = GET_OBJ_PRIV(srv_sync_cm_cbm_cntx_struct, obj);

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	/*
	  *  If cbm function reuturn CBM_OK, 
	  *	it won't cal the registered callback srv_sync_cm_cbm_bearer_callback()
	  */
	cbm_result_error_enum result = (cbm_result_error_enum)cbm_release_bearer(cntx->app_id);
	if (result == CBM_OK)
	{
		srv_sync_cm_cbm_on_disconn(obj, NULL);
	}
}

static void srv_sync_cm_cbm_on_disconn(srv_sync_cm_type *obj, void *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_cm_cbm_cntx_struct *cntx = GET_OBJ_PRIV(srv_sync_cm_cbm_cntx_struct, obj);

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/	
	RETURN_IF_FAIL(obj != NULL);
	SRV_SYNC_LOG1(MMI_SYNC_SRV_CBM_ON_DISCONN, cntx->connecting);
	
	if (cntx->connecting)
	{
		srv_sync_dummy_finish();
	}
	else
	{
		srv_sync_type *sync = srv_sync_active_sync();
	    if (sync != NULL && 
			srv_sync_match(sync, SRV_SYNC_REMOTE) &&
			srv_sync_is_state(SRV_SYNC_STATE_SYNCING))
		{		
			srv_sync_abort(SRV_SYNC_REMOTE);
	    }
	}

}

static void srv_sync_cm_cbm_reset_cntx(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	g_srv_cm_cbm_cntx.active_cm = NULL;
	g_srv_cm_cbm_cntx.connecting = MMI_FALSE;
	g_srv_cm_cbm_cntx.conn_id = 0;
}

static void srv_sync_cm_cbm_destroy(srv_sync_cm_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SYNC_SRV_CBM_DESTROY);

	if (obj != NULL)
	{		
		OslMfree(obj);
		obj = NULL;
	}
	
	srv_sync_cm_cbm_reset_cntx();
}


srv_sync_cm_type *srv_sync_cm_cbm_create(void *addr)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_sync_cm_type *obj;
	srv_sync_cm_cbm_cntx_struct *cntx = &g_srv_cm_cbm_cntx;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/ 
	SRV_SYNC_LOG0(MMI_SYNC_SRV_CBM_CREATE);

	obj = (srv_sync_cm_type *)OslMalloc(sizeof(srv_sync_cm_type));
	memset(obj, 0, sizeof(srv_sync_cm_type));
	
	obj->destroy = srv_sync_cm_cbm_destroy;	
	
	obj->conn = srv_sync_cm_cbm_conn;
	obj->on_connected = srv_sync_cm_cbm_on_connected;
	
	obj->disconn = srv_sync_cm_cbm_disconn;
	obj->on_disconn = srv_sync_cm_cbm_on_disconn;

	cntx->conn_id = (kal_uint32)addr;
	obj->priv = cntx;

	SRV_SYNC_SET_ACTIVE_CM(obj);

	return obj;
}

