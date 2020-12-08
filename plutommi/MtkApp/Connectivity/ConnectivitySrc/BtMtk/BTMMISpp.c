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
 * btmmispp.c
 *
 * Project:
 * --------
 *  
 *
 * Description:
 * ------------
 *   This file is for BT SPP app.
 *
 * Author:
 * -------
 * -------
 *
 *===========================================================
 ****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_SPP_SUPPORT__

#include "MMIDataType.h"

#include "SppSrvGprot.h"
#include "BTMMISpp.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "MMI_trc_Int.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "mmi_frm_scenario_gprot.h"

mmi_bt_spp_cntx mmi_spp_context;
mmi_bt_spp_cntx* g_mmi_spp_cntx_p = &mmi_spp_context;
extern kal_bool mmi_frm_nmgr_popup(mmi_scenario_id scenario_id, mmi_event_notify_enum type, WCHAR *string);
void mmi_bt_spp_init(void)
{
	srv_spp_init();
	mmi_bt_spp_server_init();
}

void mmi_bt_spp_server_init(void)
{	
	U32 evt_mask = 0;
	g_mmi_spp_cntx_p->handle = srv_spp_open();	
	if (g_mmi_spp_cntx_p->handle == SRV_SPP_INVALID_HANDLE)
		return;
	
	evt_mask = SRV_SPP_EVENT_BIND_FAIL|
		SRV_SPP_EVENT_AUTHORIZE|
		SRV_SPP_EVENT_CONNECT|
		SRV_SPP_EVENT_READY_TO_WRITE|
		SRV_SPP_EVENT_READY_TO_READ|
		SRV_SPP_EVENT_DISCONNECT;	
	srv_spp_set_notify_hdlr(g_mmi_spp_cntx_p->handle, evt_mask, mmi_bt_spp_event_handler, NULL);

	srv_spp_bind(g_mmi_spp_cntx_p->handle, SRV_BT_CM_SPP_PROFILE_UUID);

	g_mmi_spp_cntx_p->conn_id = -1;
	g_mmi_spp_cntx_p->is_connected = 0;
}
extern void mmi_bt_spp_receive_data(void);
S32 mmi_bt_spp_event_handler(U32 evt, void* para)
{
	srv_spp_event_cntx notify_para = *(srv_spp_event_cntx*)para;
	switch (evt)
	{
		case SRV_SPP_EVENT_BIND_FAIL:
			mmi_bt_spp_bind_handler();
			break;
		case SRV_SPP_EVENT_AUTHORIZE:
			mmi_bt_spp_authorize_ind(&notify_para);
			break;
		case SRV_SPP_EVENT_CONNECT:
			mmi_bt_spp_connect_ind(&notify_para);
			break;
		case SRV_SPP_EVENT_READY_TO_WRITE:
			break;
		case SRV_SPP_EVENT_READY_TO_READ:
			#ifdef __MMI_BT_SPP_TEST__
			mmi_bt_spp_receive_data();
			#endif
			break;
		case SRV_SPP_EVENT_DISCONNECT:
			mmi_bt_spp_disconnect(&notify_para);
			break;
		default:
			break;
	}
	return MMI_RET_OK;
}

void mmi_bt_spp_bind_handler(void)
{
	srv_spp_close(g_mmi_spp_cntx_p->handle);
}

void mmi_bt_spp_authorize_ind(srv_spp_event_cntx* para)
{
	srv_spp_event_cntx auth_ind = *(srv_spp_event_cntx*)para;
	srv_bt_cm_bt_addr dev_addr;

	if (g_mmi_spp_cntx_p->conn_id > 0) 
		srv_spp_reject(auth_ind.para);
	else
		g_mmi_spp_cntx_p->conn_id = auth_ind.para;

	srv_spp_get_dev_addr(g_mmi_spp_cntx_p->conn_id, &dev_addr);

	mmi_bt_authorize_ind_notify(
		NULL,
		&dev_addr,
		SRV_BT_CM_SPP_PROFILE_UUID,
		(void*)mmi_bt_spp_authorize_rsp
		);
}

void mmi_bt_spp_authorize_rsp(srv_bt_cm_bt_addr *bt_addr, U32 profile_id, U32 result)
{
	if (result)
		srv_spp_accept(
			g_mmi_spp_cntx_p->conn_id, 
			g_mmi_spp_cntx_p->buf, 
			sizeof(g_mmi_spp_cntx_p->buf)/2,
			sizeof(g_mmi_spp_cntx_p->buf)/2
			);
	else
	{		
		srv_spp_reject(g_mmi_spp_cntx_p->conn_id);
		g_mmi_spp_cntx_p->conn_id = -1;
	}
}

void mmi_bt_spp_connect_ind(srv_spp_event_cntx* para)
{
	U16 str_popup[60];
	g_mmi_spp_cntx_p->is_connected = 1;
	kal_wsprintf(
        str_popup,
        "%w%w",
        (WCHAR*)GetString(STR_BT_PROF_SPP),
        (WCHAR*)GetString(STR_BT_CONN_ED)
        );
    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_SUCCESS, (WCHAR*)str_popup);	
}

#ifdef __MMI_BT_SPP_TEST__
extern spp_rev_cntx g_spp_rev_cntx;
#endif
void mmi_bt_spp_disconnect(srv_spp_event_cntx* para)
{
	srv_spp_event_cntx disconn_ind = *(srv_spp_event_cntx*)para;
	U16 str_popup[60];
	if (g_mmi_spp_cntx_p->conn_id == disconn_ind.para)
	{		
		mmi_bt_authorize_screen_close(SRV_BT_CM_SPP_PROFILE_UUID);
		if (!disconn_ind.ret && g_mmi_spp_cntx_p->is_connected)
		{
			kal_wsprintf(
		        str_popup,
		        "%w%w",
		        (WCHAR*)GetString(STR_BT_PROF_SPP),
		        (WCHAR*)GetString(STR_BT_DISCON_ED)
		        );
	    	mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR*)str_popup);
		}
		g_mmi_spp_cntx_p->conn_id = -1;
		g_mmi_spp_cntx_p->is_connected = 0;
		#ifdef __MMI_BT_SPP_TEST__
		if (g_spp_rev_cntx.fs_handle > FS_NO_ERROR)
			FS_Close(g_spp_rev_cntx.fs_handle);
		#endif
	}
	else
		return;
}


#ifdef __MMI_BT_SPP_TEST__
spp_rev_cntx g_spp_rev_cntx;
void mmi_bt_spp_receiving_data(void);
void mmi_bt_spp_pre_receive_data(void);

void mmi_bt_spp_receive_data(void)
{
	if (g_spp_rev_cntx.fs_handle <= 0)
		mmi_bt_spp_pre_receive_data();
	mmi_bt_spp_receiving_data();
}

void mmi_bt_spp_pre_receive_data(void)
{
	WCHAR file_name[50];
	U8 drive = (U8)FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_V_REMOVABLE);
	kal_wsprintf(file_name, "%c:\\Mp3.mp3", drive);
	g_spp_rev_cntx.fs_handle = FS_Open(file_name, FS_READ_WRITE | FS_CREATE_ALWAYS);	
}

void mmi_bt_spp_receiving_data(void)
{
	U32 read_size;
	while (1)
	{ 
		read_size = srv_spp_read(
			g_mmi_spp_cntx_p->conn_id,
			g_spp_rev_cntx.buf,
			2048
			);
		if (read_size > 0)
			FS_Write(g_spp_rev_cntx.fs_handle, g_spp_rev_cntx.buf, read_size, NULL); 
		else break;
	}
}
#endif

#ifdef __MMI_BT_SPP_TEST__
typedef struct{
	SppHandle handle;
	S32 conn_id;
	U8 buf[SRV_SPP_MIN_BUFF_SIZE];
	U8 send_buf[2048];
	FS_HANDLE send_file_handle;
	U32 total_size;
	U32 send_remain_size;
}mmi_spp_client;

mmi_spp_client spp_client_cntx;
void mmi_bt_sppc_disconnect_ind(srv_spp_event_cntx* notify_para);
S32 mmi_bt_spp_client_hdlr(U32 evt, void* para);
void mmi_bt_sppc_bind_handler(void);
void mmi_bt_sppc_connect_ind(srv_spp_event_cntx* notify_para);
void mmi_bt_sppc_pre_send_data(void);
void mmi_bt_sppc_send_data(void);
void mmi_bt_sppc_send_data_end(void);
void mmi_bt_sppc_disconnect_ind(srv_spp_event_cntx* notify_para);
void mmi_bt_spp_after_send_data(void);


void mmi_bt_spp_test()
{
	srv_bt_cm_bt_addr bt_addr;
	U32 evt_mask;
	
	bt_addr.lap = 0x005c6612;
	bt_addr.uap = 0x63;
	bt_addr.nap = 0x441b;

	spp_client_cntx.handle = srv_spp_open();
	if (spp_client_cntx.handle == SRV_SPP_INVALID_HANDLE)
		return;
	evt_mask = SRV_SPP_EVENT_CONNECT|
			SRV_SPP_EVENT_READY_TO_WRITE|
			SRV_SPP_EVENT_READY_TO_READ|
			SRV_SPP_EVENT_DISCONNECT;	
	srv_spp_set_notify_hdlr(spp_client_cntx.handle, evt_mask, mmi_bt_spp_client_hdlr, NULL);
	srv_spp_connect(spp_client_cntx.handle,
					SRV_BT_CM_SPP_PROFILE_UUID,
					&bt_addr,
					spp_client_cntx.buf,
					SRV_SPP_MIN_BUFF_SIZE/2,
					SRV_SPP_MIN_BUFF_SIZE/2
					);
}

S32 mmi_bt_spp_client_hdlr(U32 evt, void* para)
{
	srv_spp_event_cntx notify_para = *(srv_spp_event_cntx*)para;
	switch (evt)
	{
		case SRV_SPP_EVENT_BIND_FAIL:
			mmi_bt_sppc_bind_handler();
			break;
		case SRV_SPP_EVENT_CONNECT:
			mmi_bt_sppc_connect_ind(&notify_para);
			break;
		case SRV_SPP_EVENT_READY_TO_WRITE:
			mmi_bt_sppc_send_data();
			break;
		case SRV_SPP_EVENT_READY_TO_READ:
			break;
		case SRV_SPP_EVENT_DISCONNECT:
			mmi_bt_sppc_disconnect_ind(&notify_para);
		default:
			break;
	}
	return MMI_RET_OK;
}

void mmi_bt_sppc_bind_handler(void)
{
	srv_spp_close(spp_client_cntx.handle);
}

void mmi_bt_sppc_connect_ind(srv_spp_event_cntx* notify_para)
{
	spp_client_cntx.conn_id = notify_para->para;
//	mmi_bt_sppc_pre_send_data();
}

void mmi_bt_sppc_pre_send_data(void)
{
	FS_HANDLE send_file_hd = FS_Open(L"D:\\Audio\\Mp3.mp3", FS_READ_ONLY);
	spp_client_cntx.send_file_handle = send_file_hd;
	FS_GetFileSize(send_file_hd, &spp_client_cntx.total_size);
	spp_client_cntx.send_remain_size = 0;
	
	mmi_bt_sppc_send_data();
}

void mmi_bt_sppc_send_data(void)
{
	U32 read_size, retval;
	U32 send_size;
	while (spp_client_cntx.total_size || spp_client_cntx.send_remain_size)
	{
		if (!spp_client_cntx.send_remain_size)
		{		
			retval = FS_Read(
				spp_client_cntx.send_file_handle,
				spp_client_cntx.send_buf,
				2048,
				&read_size
				);		
			if (retval < FS_NO_ERROR) MMI_ASSERT(0);
			spp_client_cntx.total_size -= read_size;
			spp_client_cntx.send_remain_size = read_size;
		}
		send_size = srv_spp_write(
							spp_client_cntx.conn_id, 
							spp_client_cntx.send_buf + 2048 - spp_client_cntx.send_remain_size, 
							spp_client_cntx.send_remain_size
							);
		spp_client_cntx.send_remain_size -= send_size;
		if (!spp_client_cntx.total_size || !spp_client_cntx.send_remain_size)
		{
			mmi_bt_sppc_send_data_end();
			break;
		}
		if (spp_client_cntx.send_remain_size) break;
	}
	return;
}

void mmi_bt_sppc_send_data_end(void)
{
	mmi_popup_display_simple((WCHAR*)L"spp send end",
							MMI_EVENT_SUCCESS,
							GRP_ID_ROOT, NULL);
}

void mmi_bt_sppc_disconnect_ind(srv_spp_event_cntx* notify_para)
{
	if (spp_client_cntx.conn_id != notify_para->para)
		return;
	mmi_bt_spp_after_send_data();
	srv_spp_close(spp_client_cntx.handle);
}

void mmi_bt_spp_after_send_data(void)
{
	if (spp_client_cntx.send_file_handle >= 0)
		FS_Close(spp_client_cntx.send_file_handle);
	
}
#endif/*__MMI_BT_SPP_TEST__*/

#endif/*__MMI_SPP_SUPPORT__*/

