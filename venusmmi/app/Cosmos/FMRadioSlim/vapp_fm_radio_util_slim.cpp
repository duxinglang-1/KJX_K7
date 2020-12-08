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
 *  vapp_fm_radio_util_slim.cpp
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  FM Radio utility file
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h" 

/***************************************************************************** 
 * Include
 *****************************************************************************/
#if defined(__MMI_FM_RADIO_SLIM__)

#include "vfx_adp_device.h" // For touch feedback
#include "vapp_fm_radio_util_slim.h"
#include "vapp_vol_dialog_gprot.h"
#include "vapp_fm_radio_slim.h"
#include "vcp_global_popup.h"
#include "vcp_activity_indicator.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
#include "ProfilesSrv.h" 
#include "mdi_audio.h"
#include "mdi_include.h"
#include "Mmi_rp_srv_venus_component_tool_bar_def.h"
#include "mmi_rp_vapp_fm_radio_def.h"
#include "Mmi_frm_events_gprot.h"
#include "Filemgrcuigprot.h"
#include "FileMgrSrvGProt.h"
#include "GlobalConstants.h"
#include "AppMgrSrvGProt.h"
#include "GpioSrvGprot.h"
#include "UcmSrvGprot.h"
#include "mmi_rp_vapp_vol_dialog_def.h"
#include "NotificationGprot.h"
#include "Mmi_cb_mgr_gprot.h"
#include "Nvram_interface.h" /* nvram_get_default_value */
#include "mmi_frm_nvram_gprot.h" /* reset nvram record */
#include "Wgui_categories_util.h"
#include "mmi_rp_srv_prof_def.h"
#include "MMI_media_app_trc.h"

//klawmo
#ifdef __DM_LAWMO_SUPPORT__
#include "DmSrvGprot.h"
#endif


#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
vadp_fm_radio_power_on_struct g_vadp_fm_radio_general[VADP_FM_RADIO_TOTAL];
vadp_fm_radio_background_struct g_vadp_fm_radio_background[VADP_FM_RADIO_TOTAL];
vadp_fm_radio_seek_struct g_vadp_fm_radio_seek[VADP_FM_RADIO_TOTAL];
vadp_fm_radio_proc_struct g_vadp_fm_radio_proc[VADP_FM_RADIO_TOTAL];

vadp_fm_radio_state_enum g_vadp_fm_radio_state = VADP_FM_RADIO_POWER_OFF;

#ifdef __MMI_FM_VIA_A2DP__
	vadp_fm_radio_a2dp_connect_state_enum g_vadp_fm_radio_a2dp_connect_state = VADP_FM_RADIO_A2DP_DISCONNECTED;
#endif

#ifdef __MMI_BT_FM_VIA_SCO__
	VfxBool g_vadp_fm_radio_is_sco_disabled = VFX_FALSE;
#endif

#ifdef __MMI_AVRCP_SUPPORT__
	//g_vadp_fm_radio_avrcp_cmd[VADP_FM_RADIO_TOTAL] used for power on and power off, not component.
	VfxU8 g_vadp_fm_radio_avrcp_cmd_process_func_register_num = 0;
	vadp_fm_radio_avrcp_cmd_struct g_vadp_fm_radio_avrcp_cmd[VADP_FM_RADIO_TOTAL + 1];
#endif

#if (defined(__MMI_BT_FM_VIA_SCO__) || defined(__MMI_FM_VIA_A2DP__))
	VfxU32 g_vadp_fm_radio_bt_aud_handle;
	VfxBool g_vadp_fm_radio_is_audio_path_toggled = VFX_FALSE;
#endif

U16 vadp_fm_radio_cur_freq = 900;
U8 vadp_fm_radio_aud_path;
VfxU16 g_signalBand[VAPP_FM_RADIO_AUTO_LIST_NUM];
WCHAR g_vadp_fm_radio_fav_name[VAPP_FM_RADIO_FAV_NAME_CHAR_NUM];
VfxS32	g_vadp_fm_radio_global_popup_handle = NULL;
VfxBool g_vadp_fm_radio_global_popup_could_close = VFX_TRUE;



/***************************************************************************** 
 * Function
 *****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif


void* vadp_fm_radio_get_app_control(void)
{
	void* fm_app = NULL;
	MMI_ID app_instance_id;

	if(MMI_TRUE == srv_appmgr_is_app_package_running("native.mtk.fmradio"))
	{
		/* Get app instance */
		app_instance_id = srv_appmgr_query_instance_single_id("native.mtk.fmradio");
		fm_app = (void*)VfxAppLauncher::getObject(app_instance_id);
	}
	else
	{
		fm_app = NULL;
	}
	return fm_app;
}

const WCHAR* vapp_fm_radio_get_fav_name(VfxU16 freq)
{
    S16 error;
    nvram_ef_vapp_fmrdo_fav_list_struct data;
    VfxU8 total;

    ReadValue(NVRAM_VAPP_FMRDO_FAV_LIST_NUM, &total, DS_BYTE, &error);
    ReadRecord(NVRAM_EF_VAPP_FMRDO_FAV_LIST_LID, 1, &data, sizeof(nvram_ef_vapp_fmrdo_fav_list_struct), &error);

    for(VfxS16 i=total-1 ; i>=0 ; i--)
    {
        if(data.item[i].fav_freq == freq)
        {
        	// Can not return a local pointer, define a global array and return its pointer.
        	memcpy(g_vadp_fm_radio_fav_name, data.item[i].fav_name, sizeof(WCHAR) * VAPP_FM_RADIO_FAV_NAME_CHAR_NUM);
			return g_vadp_fm_radio_fav_name;
        }
    }
	return NULL;
}

VfxU8 vapp_fm_radio_get_fav_count(void)
{
	S16 error;
	VfxU8 total;
	ReadValue(NVRAM_VAPP_FMRDO_FAV_LIST_NUM, &total, DS_BYTE, &error);

	return total;
}

void vapp_fm_radio_add_to_fav_list(VfxU16 freq, VfxWString name)
{
    S16 error;
    nvram_ef_vapp_fmrdo_fav_list_struct data;
    VfxU8 total;

    ReadValue(NVRAM_VAPP_FMRDO_FAV_LIST_NUM, &total, DS_BYTE, &error);
    ReadRecord(NVRAM_EF_VAPP_FMRDO_FAV_LIST_LID, 1, &data, sizeof(nvram_ef_vapp_fmrdo_fav_list_struct), &error);

	data.item[total].fav_freq = freq;
	memcpy(&data.item[total].fav_name, (const VfxWChar*)name, sizeof(VfxWChar)*(name.getLength()+1) );
	total++;
	
	WriteValue(NVRAM_VAPP_FMRDO_FAV_LIST_NUM, &total, DS_BYTE, &error);
	WriteRecord(NVRAM_EF_VAPP_FMRDO_FAV_LIST_LID, 1, &data, sizeof(nvram_ef_vapp_fmrdo_fav_list_struct), &error);
}

void vadp_fm_radio_write_cur_freq(void)
{
	//kal_prompt_trace(MOD_MMI_MEDIA_APP, "[FM RADIO]vadp_fm_radio_write_cur_freq(), freq=%d ", vadp_fm_radio_cur_freq);

	S16 error;
	WriteValue(NVRAM_VAPP_FMRDO_CUR_FREQ, &vadp_fm_radio_cur_freq, DS_SHORT, &error);
}

void vadp_fm_radio_set_cur_freq(U16 cur_freq)
{
	//kal_prompt_trace(MOD_MMI_MEDIA_APP, "[FM RADIO]vadp_fm_radio_set_cur_freq(), freq=%d ", cur_freq);

	vadp_fm_radio_cur_freq = cur_freq;

	StartTimer(TIMER_ID_VAPP_FM_STORE_CUR_FREQ, 2500, vadp_fm_radio_write_cur_freq);
}

U16 vadp_fm_radio_get_cur_freq(void)
{
	//kal_prompt_trace(MOD_MMI_MEDIA_APP, "[FM RADIO]vadp_fm_radio_get_cur_freq(), freq=%d ", vadp_fm_radio_cur_freq);

	return vadp_fm_radio_cur_freq;
}

void vadp_fm_radio_toggle_aud_path(void)
{
	if(vadp_fm_radio_aud_path == 1)
	{
		vadp_fm_radio_aud_path = 0;
	}
	else
	{
		vadp_fm_radio_aud_path = 1;
	}

	//kal_prompt_trace(MOD_MMI_MEDIA_APP, "[FM RADIO]vadp_fm_radio_toggle_aud_path(), vadp_fm_radio_aud_path=%d ", vadp_fm_radio_aud_path);

	S16 error;
	WriteValue(NVRAM_VAPP_FMRDO_AUD_PATH, &vadp_fm_radio_aud_path, DS_BYTE, &error);
	
}

U8 vadp_fm_radio_get_aud_path(void)
{
	//kal_prompt_trace(MOD_MMI_MEDIA_APP, "[FM RADIO]vadp_fm_radio_get_aud_path(), vadp_fm_radio_aud_path=%d ", vadp_fm_radio_aud_path);

	if(vadp_fm_radio_aud_path == 0)
	{
		return MDI_DEVICE_SPEAKER2;
	}
	else
	{
		return MDI_DEVICE_SPEAKER_BOTH;
	}
}

void vadp_fm_radio_reset_aud_path(void)
{
	//kal_prompt_trace(MOD_MMI_MEDIA_APP, "[FM RADIO]vadp_fm_radio_reset_aud_path()");

	if( vadp_fm_radio_aud_path == 0)
	{
		return;
	}

	vadp_fm_radio_aud_path = 0;

	S16 error;
	WriteValue(NVRAM_VAPP_FMRDO_AUD_PATH, &vadp_fm_radio_aud_path, DS_BYTE, &error);
}

mmi_ret vadp_fm_radio_init(mmi_event_struct *evt)
{
	S16 error;
	ReadValue(NVRAM_VAPP_FMRDO_CUR_FREQ, &vadp_fm_radio_cur_freq, DS_SHORT, &error);
	ReadValue(NVRAM_VAPP_FMRDO_AUD_PATH, &vadp_fm_radio_aud_path, DS_BYTE, &error);

	//kal_prompt_trace(MOD_MMI_MEDIA_APP, "[FM RADIO]vadp_fm_radio_init(), freq=%d ", vadp_fm_radio_cur_freq);

	return MMI_RET_OK;
}

void vadp_fm_radio_app_power_off(void)
{
    vadp_fm_radio_stop_playing();
    vfx_adp_touch_fb_enable_tone();
}

void vadp_fm_radio_power_off(void)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_VADP_POWER_OFF, g_vadp_fm_radio_state);
	
	if(g_vadp_fm_radio_state != VADP_FM_RADIO_INTERRUPT)
	{
		vadp_fm_radio_stop_playing();
	}
	
	vfx_adp_touch_fb_enable_tone();	
	vadp_fm_radio_update_state(VADP_FM_RADIO_POWER_OFF);
	vadp_fm_radio_clear_background_handler();
}

void vadp_fm_radio_power_on_callback(mdi_result result, void* user_data)
{
    switch(result)
    {
        case MDI_AUDIO_TERMINATED:
        {		
			MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_VADP_POWER_ON_CALLBACK);

			switch(g_vadp_fm_radio_state)
    		{
        		case VADP_FM_RADIO_SEEKING:
				case VADP_FM_RADIO_SCANING:
        		{
		            /* mute and reset */
		        #if defined(__MMI_BT_FM_VIA_SCO__)
		            mdi_audio_bt_hfp_turn_on();
		        #endif
		            mdi_audio_set_volume(MDI_VOLUME_FMR, srv_prof_get_media_vol());
		            break;
		        }
		    }
			vadp_fm_radio_stop_playing();
			vfx_adp_touch_fb_enable_tone();
			vadp_fm_radio_update_state(VADP_FM_RADIO_INTERRUPT);
			break;
        }
		default:
			break;
    }

	for(U8 i=0; i<VADP_FM_RADIO_TOTAL; i++)
	{
		if(g_vadp_fm_radio_general[i].handler != NULL)
		{
			g_vadp_fm_radio_general[i].handler(result, g_vadp_fm_radio_general[i].user_data);
		}
	}
}

void vadp_fm_radio_power_on_with_path(U8 path, U8 app_id)
{
	vfx_adp_touch_fb_disable_tone();

#if defined(__MMI_NCENTER_SUPPORT__)  
	// show ncenter when fm power on
	vadp_fm_radio_update_ncenter();
#endif

	if (vadp_fm_radio_get_aud_path() == MDI_DEVICE_SPEAKER2) 			
    {
    	#ifdef __MMI_FM_VIA_A2DP__
    		if(srv_a2dp_is_output_to_bt())		// Check if FM Radio could go through a2dp
    		{
				vadp_fm_radio_set_a2dp_connect_state(VADP_FM_RADIO_A2DP_CONNECTING);
    			vadp_fm_radio_connect_a2dp();
				return;
    		}
		#endif 
	}
	else // MDI_DEVICE_SPEAKER_BOTH
	{
		#if (defined(__MMI_BT_FM_VIA_SCO__) || defined(__MMI_FM_VIA_A2DP__))
			vadp_fm_radio_disable_play_via_bt_headset();
		#endif
	}

	vadp_fm_radio_start_playing();
}

void vadp_fm_radio_scan(void)
{
	//kal_prompt_trace(MOD_MMI_MEDIA_APP, "[FM RADIO]vadp_fm_radio_scan()");

    memset(&g_signalBand, 0, sizeof(g_signalBand));

    mdi_fmr_scan_req_struct scan_param;
    scan_param.sorting = MDI_FMR_SORTING_BY_FREQ;
    scan_param.callback = vadp_fm_radio_scan_callback;
    scan_param.max_channel = VAPP_FM_RADIO_AUTO_LIST_NUM;
    scan_param.channel_list = (U16*)&g_signalBand;
    scan_param.user_data = NULL;

    mdi_fmr_scan_start(&scan_param);
}

void vadp_fm_radio_update_scan_freq(U8 total,VfxU16* signalBand)
{
    U16 count;
    S16 error;

    nvram_ef_vapp_fmrdo_auto_list_struct set_freq;

    for(count=0; count < total; count++)
    {
        set_freq.freq[count]= signalBand[count];
    }

    WriteValue(NVRAM_VAPP_FMRDO_AUTO_LIST_NUM, &total, DS_BYTE, &error);
    WriteRecord(NVRAM_EF_VAPP_FMRDO_AUTO_LIST_LID, 1, &set_freq, sizeof(nvram_ef_vapp_fmrdo_auto_list_struct), &error);
}

void vadp_fm_radio_scan_callback(mdi_fmr_cb_reason_enum result, void* cb_data, void* user_data)
{
	//kal_prompt_trace(MOD_MMI_MEDIA_APP, "[FM RADIO]vadp_fm_radio_scan_callback(),result = %d ", result);

	mmi_event_struct evt;
	
    if(result != MDI_FMR_CB_REASON_DONE)
    {
        return;
    }

#if defined(__MMI_BT_FM_VIA_SCO__)
	mdi_audio_bt_hfp_turn_on();
#endif

	mdi_fmr_set_freq(vadp_fm_radio_cur_freq);
	mdi_audio_set_volume(MDI_VOLUME_FMR, srv_prof_get_media_vol());
	vadp_fm_radio_update_scan_freq((VfxU8)(VfxU32)cb_data, g_signalBand);
	vadp_fm_radio_update_state(VADP_FM_RADIO_POWER_ON);

	MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_FM_SCAN_DONE);
	MMI_FRM_CB_EMIT_POST_EVENT(&evt);

}

void vadp_fm_radio_seek_callback(mdi_fmr_cb_reason_enum result, U16 stop_freq, MMI_BOOL is_valid, void* user_data)
{

	if(g_vadp_fm_radio_state != VADP_FM_RADIO_SEEKING)
	{
		return;
	}

	// Save freq
	if(result != MDI_FMR_CB_REASON_ABORT)
	{		
		if(stop_freq > FM_RADIO_MAX_FREQ)
	    {
	        stop_freq = FM_RADIO_MAX_FREQ;        
	    }

	    if(stop_freq < FM_RADIO_MIN_FREQ)
	    {
	        stop_freq = FM_RADIO_MIN_FREQ;        
	    }

		vadp_fm_radio_set_cur_freq(stop_freq);
	}

	// Handle seek result
	if((result == MDI_FMR_CB_REASON_DONE) || (result == MDI_FMR_CB_REASON_ABORT))
	{
	#if defined(__MMI_BT_FM_VIA_SCO__)
		mdi_audio_bt_hfp_turn_on();
	#endif

		if(result == MDI_FMR_CB_REASON_DONE)
		{
			mdi_fmr_set_freq(stop_freq);
			mdi_audio_set_volume(MDI_VOLUME_FMR, srv_prof_get_media_vol());
		}

		vadp_fm_radio_update_state(VADP_FM_RADIO_POWER_ON);
	}

	// Call seek callback func
	for(U8 i=0; i<VADP_FM_RADIO_TOTAL; i++)
	{
		if(g_vadp_fm_radio_seek[i].handler != NULL)
		{
			g_vadp_fm_radio_seek[i].handler(result,stop_freq,is_valid,g_vadp_fm_radio_seek[i].user_data);
		}
	}
}

void vadp_fm_radio_seek(U16 start_freq, VfxBool forward)
{
	/* mute and reset */
	mdi_audio_set_mute(MDI_VOLUME_FMR, MMI_TRUE);
#if defined(__MMI_BT_FM_VIA_SCO__)
	mdi_audio_bt_hfp_turn_off();
#endif

	mdi_fmr_seek_req_struct seek_param;
	seek_param.start_freq = start_freq;

	if(forward)
	{
		seek_param.is_step_up = MMI_TRUE;
	}
	else
	{
		seek_param.is_step_up = MMI_FALSE;
	}

	seek_param.stop_criteria = MDI_FMR_SEEK_STOP_AT_BOUNDARY;
	seek_param.callback = (mdi_fmr_seek_cb_fct)vadp_fm_radio_seek_callback;
	seek_param.user_data = NULL;
	mdi_fmr_seek_start(&seek_param);

}


void vadp_fm_radio_background_callback(mdi_result result, void* user_data)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_VADP_BACKGROUND_CALLBACK, result, g_vadp_fm_radio_state);

    switch(result)
    {
        /*stop by other app*/
        case MDI_AUDIO_TERMINATED:
        {			
			vadp_fm_radio_power_off();
            break;
        }

        case MDI_AUDIO_RESUME:
        {
            if(g_vadp_fm_radio_state == VADP_FM_RADIO_INTERRUPT)
            {
            	#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
					if(!srv_earphone_is_plug_in())
					{
						break;
					}    
				#endif // __MMI_FM_RADIO_BIND_EARPHONE__
				
				vadp_fm_radio_power_on_with_path(vadp_fm_radio_get_aud_path(), VADP_FM_RADIO_APP);
				vadp_fm_radio_set_background_handler();
				vadp_fm_radio_update_state(VADP_FM_RADIO_POWER_ON);

				if(g_vadp_fm_radio_global_popup_handle != NULL)
				{
					g_vadp_fm_radio_global_popup_could_close = VFX_FALSE;
				}
			}
            break;
        }

        default:
            break;
    }

	for(U8 i=0; i<VADP_FM_RADIO_TOTAL; i++)
	{
		if(g_vadp_fm_radio_background[i].handler != NULL)
		{
			g_vadp_fm_radio_background[i].handler(result, g_vadp_fm_radio_background[i].user_data);
		}
	}
}

void vadp_fm_radio_set_background_handler(void)
{
	mdi_audio_set_background_handler(MDI_BACKGROUND_APP_FMR, (mdi_bg_callback)&vadp_fm_radio_background_callback, NULL);
}

void vadp_fm_radio_clear_background_handler(void)
{
	mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_FMR);
}

void vadp_fm_radio_register_general_callback(mdi_ext_callback handler, void *user_data, U8 app_id)
{
	g_vadp_fm_radio_general[app_id].handler = handler;
	g_vadp_fm_radio_general[app_id].user_data = user_data;
}

void vadp_fm_radio_deregister_general_callback(U8 app_id)
{
	g_vadp_fm_radio_general[app_id].handler = NULL;
	g_vadp_fm_radio_general[app_id].user_data = NULL;
}

void vadp_fm_radio_register_background_callback(mdi_bg_callback handler, void *user_data, U8 app_id)
{
	g_vadp_fm_radio_background[app_id].handler = handler;
	g_vadp_fm_radio_background[app_id].user_data = user_data;
}

void vadp_fm_radio_deregister_background_callback(U8 app_id)
{
	g_vadp_fm_radio_background[app_id].handler = NULL;
	g_vadp_fm_radio_background[app_id].user_data = NULL;
}

void vadp_fm_radio_register_seek_callback(mdi_fmr_seek_cb_fct handler, void *user_data, U8 app_id)
{
	g_vadp_fm_radio_seek[app_id].handler = handler;
	g_vadp_fm_radio_seek[app_id].user_data = user_data;
}

void vadp_fm_radio_deregister_seek_callback(U8 app_id)
{
	g_vadp_fm_radio_seek[app_id].handler = NULL;
	g_vadp_fm_radio_seek[app_id].user_data = NULL;
}

void vadp_fm_radio_register_proc_callback(vadp_fmr_proc_callback handler, void *user_data, U8 app_id)
{
	g_vadp_fm_radio_proc[app_id].handler = handler;
	g_vadp_fm_radio_proc[app_id].user_data = user_data;
}

void vadp_fm_radio_deregister_proc_callback(U8 app_id)
{
	g_vadp_fm_radio_proc[app_id].handler = NULL;
	g_vadp_fm_radio_proc[app_id].user_data = NULL;
}


vadp_fm_radio_state_enum vadp_fm_radio_query_state(void)
{
	return g_vadp_fm_radio_state;
}

void vadp_fm_radio_update_state(vadp_fm_radio_state_enum state)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_VADP_UPDATE_STATE, state);

	g_vadp_fm_radio_state = state;

	vadp_fm_radio_update_status_icon_bar();
}

#if defined(__MMI_NCENTER_SUPPORT__)  
void vadp_fm_radio_update_ncenter()
{
	vapp_fm_radio_ncenter_update_evt_struct evt;
	MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_FM_UPDATE_NCENTER);
	evt.is_shown = VFX_TRUE;
	MMI_FRM_CB_EMIT_POST_EVENT(&evt);	
}
#endif

void vadp_fm_radio_update_status_icon_bar()
{
	// only show fm status icon when fm is playing
	if(vadp_fm_radio_is_playing())
	{
		wgui_status_icon_bar_set_icon_display(STATUS_ICON_FM);
	}
	else
	{
		wgui_status_icon_bar_reset_icon_display(STATUS_ICON_FM);
	}
	wgui_status_icon_bar_update();
}

mmi_ret vadp_fm_radio_evt_proc(mmi_event_struct *evt)
{
	switch(evt->evt_id)
	{
		case EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE:
		{
			vapp_vol_dialog_evt_struct *vol_evt = (vapp_vol_dialog_evt_struct*) evt;
			if(vol_evt->type == VAPP_VOL_DIALOG_IS_FM)
			{
				//If FM Radio is power on or in FM Radio main graph, then adjust media volume. Otherwise,  adjust ringtone volume.
				VappFMRadioApp* app = (VappFMRadioApp*)vadp_fm_radio_get_app_control();	
				if((g_vadp_fm_radio_state != VADP_FM_RADIO_POWER_OFF)
					|| ((app != NULL) && (app->isFMRadioMainInterfaceActive())))
				{
					return !MMI_RET_OK;
				}				
			}
			break;
		}

		case EVT_ID_SRV_PROF_IS_PLAYING:
		{
			if(g_vadp_fm_radio_state == VADP_FM_RADIO_POWER_ON)
			{
				return !MMI_RET_OK;
			}
			break;
		}

		case EVT_ID_GPIO_EARPHONE_PLUG_OUT:
		{	
			U8 audio_path = vadp_fm_radio_get_aud_path();
			vadp_fm_radio_reset_aud_path();

			if(!vadp_fm_radio_is_playing())
			{
				break;
			}
			
			#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
			{	
				if((g_vadp_fm_radio_state == VADP_FM_RADIO_SEEKING) || 
					(g_vadp_fm_radio_state == VADP_FM_RADIO_SCANING))
				{
				
				#if defined(__MMI_BT_FM_VIA_SCO__)
					mdi_audio_bt_hfp_turn_on();
				#endif
				}
				vadp_fm_radio_power_off();
				break;
			}
			#endif // __MMI_FM_RADIO_BIND_EARPHONE__

			if(audio_path == MDI_DEVICE_SPEAKER_BOTH)
			{
				#if (defined(__MMI_BT_FM_VIA_SCO__) || defined(__MMI_FM_VIA_A2DP__))
					vadp_fm_radio_toggle_bt_aud_path();
				#endif
			}
					
			mdi_fmr_set_output_path(vadp_fm_radio_get_aud_path());
			break;
		}

		case EVT_ID_GPIO_EARPHONE_PLUG_IN:
		{	
			break;
		}

	//klawmo
	#ifdef __DM_LAWMO_SUPPORT__
		case EVT_ID_SRV_DM_LAWMO_LOCK_IND:
		{
			srv_dm_lawmo_lock_ind_evt_struct* lock_ind = (srv_dm_lawmo_lock_ind_evt_struct *)evt;
			if(lock_ind->cmd == SRV_DM_LAWMO_LOCK_CMD_LOCK)
			{
				if(g_vadp_fm_radio_state == VADP_FM_RADIO_POWER_OFF)
				{
					break;
				}
				if(g_vadp_fm_radio_state == VADP_FM_RADIO_SCANING ||
					g_vadp_fm_radio_state == VADP_FM_RADIO_SEEKING)
				{
					#if defined(__MMI_BT_FM_VIA_SCO__)
						mdi_audio_bt_hfp_turn_on();
					#endif
				}
			
				vadp_fm_radio_power_off();
			}
			
			break;
		}
	#endif
	
		default:
			break;

	}

	for(U8 i=0; i < VADP_FM_RADIO_TOTAL - 1; i++)
	{
		if(g_vadp_fm_radio_proc[i].handler != NULL)
		{
			g_vadp_fm_radio_proc[i].handler(evt, g_vadp_fm_radio_proc[i].user_data);
		}
	}
	
	return MMI_RET_OK;
	
}

void vadp_fm_radio_set_global_popup_could_close(VfxBool could_close)
{
	g_vadp_fm_radio_global_popup_could_close = could_close;
}

void vadp_fm_radio_set_global_popup_handle(VfxU32 popup_handle)
{
	g_vadp_fm_radio_global_popup_handle = popup_handle;
}

VfxU32 vadp_fm_radio_get_global_popup_handle()
{
	return g_vadp_fm_radio_global_popup_handle;
}

void vadp_fm_radio_close_global_popup()
{
	if (g_vadp_fm_radio_global_popup_could_close && (g_vadp_fm_radio_global_popup_handle != NULL))
	{
		vapp_fm_radio_cancel_popup_event_struct postInvoke;
	    MMI_FRM_INIT_EVENT(&postInvoke, 0);
	    postInvoke.popup_handle = g_vadp_fm_radio_global_popup_handle;
	    MMI_FRM_POST_EVENT(&postInvoke, vadp_fm_radio_cancel_global_popup, NULL);  
	}
}

mmi_ret vadp_fm_radio_cancel_global_popup(mmi_event_struct *evt)
{
    vapp_fm_radio_cancel_popup_event_struct *evnt = (vapp_fm_radio_cancel_popup_event_struct *)evt;
    VfxS32 popuphandle = evnt->popup_handle;
    
    if (popuphandle != NULL)
    { 
        vcp_global_popup_cancel(popuphandle);          
		g_vadp_fm_radio_global_popup_handle = NULL;
    }
    
    return MMI_RET_OK;
}

void vadp_fm_radio_start_playing(void)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_VADP_START_PLAYING);
	
    // Must power on FM before set freq
	mdi_fmr_power_on_with_path(vadp_fm_radio_get_aud_path(), (mdi_ext_callback)vadp_fm_radio_power_on_callback, NULL);

	VappFMRadioApp *app = (VappFMRadioApp*)vadp_fm_radio_get_app_control();
	VfxBool isNoNeedSetFreq = ((app != NULL) && app->isDelaySetPowerOnFreqEnable());	// Freq will delay set by FM Radio app.
	if(!isNoNeedSetFreq)
	{
		mdi_fmr_set_freq(vadp_fm_radio_get_cur_freq());
		mdi_audio_set_volume(MDI_VOLUME_FMR, srv_prof_get_media_vol());
	}
	
	#ifdef __MMI_FM_VIA_A2DP__
		vadp_fm_radio_listen_to_BT_connection();
	#endif

	#ifdef __MMI_AVRCP_SUPPORT__
		vadp_fm_radio_register_avrcp_cmd_callback(vadp_fm_radio_process_avrcp_cmd, NULL, VADP_FM_RADIO_TOTAL);
	#endif
}

void vadp_fm_radio_stop_playing(void)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_VADP_STOP_PLAYING);

	mdi_fmr_power_off();

	#ifdef __MMI_FM_VIA_A2DP__
		vadp_fm_radio_close_a2dp_connection();
		srv_btaud_close(g_vadp_fm_radio_bt_aud_handle);
	#endif

	#ifdef __MMI_BT_FM_VIA_SCO__
		// If SCO is disabled in FM Radio, we must enable it when FM power off, or it will disabled permanently.
		if(g_vadp_fm_radio_is_sco_disabled)
		{		
			srv_btsco_enable_sco_connection(SRV_BT_SCO_INT_FMRADIO);
			g_vadp_fm_radio_is_sco_disabled = VFX_FALSE;
		}
	#endif

	#ifdef __MMI_AVRCP_SUPPORT__
		vadp_fm_radio_deregister_avrcp_cmd_callback(VADP_FM_RADIO_TOTAL);
	#endif
}

VfxBool vadp_fm_radio_is_playing()
{
	return ((g_vadp_fm_radio_state != VADP_FM_RADIO_POWER_OFF) 
			&& (g_vadp_fm_radio_state != VADP_FM_RADIO_INTERRUPT));
}

#ifdef __MMI_FM_VIA_A2DP__
vadp_fm_radio_a2dp_connect_state_enum vadp_fm_radio_get_a2dp_connect_state(void)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_VADP_GET_A2DP_CONNECT_STATE, g_vadp_fm_radio_a2dp_connect_state);

	return g_vadp_fm_radio_a2dp_connect_state;
}

void vadp_fm_radio_set_a2dp_connect_state(vadp_fm_radio_a2dp_connect_state_enum a2dp_connect_state)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_VADP_SET_A2DP_CONNECT_STATE, a2dp_connect_state);

	g_vadp_fm_radio_a2dp_connect_state = a2dp_connect_state;
}

void vadp_fm_radio_connect_a2dp(void)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_VADP_CONNECT_A2DP);

	// Get the audio info of fm radio.
	mdi_fmr_audio_info_struct audio_info;
	mdi_fmr_get_audio_info(&audio_info);

	// Set up a2dp connection
	srv_a2dp_open(
		srv_a2dp_get_bt_headset(),
		audio_info.sampleRate,
		audio_info.stereo,
		vadp_fm_radio_a2dp_connect_callback,
		MMI_TRUE	// Always true in FM radio
		);
	
	// Notify FM Radio app connect A2DP has began.
	VappFMRadioApp *app = (VappFMRadioApp*)vadp_fm_radio_get_app_control();
	if(app != NULL)
	{
		app->connectA2dpBegin();
	}
}

void vadp_fm_radio_a2dp_connect_callback(S32 result)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_VADP_A2DP_CONNECT_CALLBACK, result);

	// Notify FM Radio app connect A2DP has end.
	VappFMRadioApp *app = (VappFMRadioApp*)vadp_fm_radio_get_app_control();
	if(app != NULL)
	{
		app->connectA2dpEnd();
	}

	vadp_fm_radio_a2dp_connect_state_enum a2dp_connect_state = vadp_fm_radio_get_a2dp_connect_state();
	switch(result)
	{	
		// Connect A2DP successfully.
		case SRV_A2DP_CALLBACK_EVENT_OPEN_OK:
		{		
			switch(a2dp_connect_state)
			{
				case VADP_FM_RADIO_A2DP_CONNECTING:
				{
					// Pass MMI_FALSE for not playing directly
                	srv_a2dp_open_codec(MMI_FALSE);
                	vadp_fm_radio_start_playing();				
					break;
				}
				case VADP_FM_RADIO_A2DP_CONNECTING_WHILE_PLAY:
				{
					srv_a2dp_open_codec(MMI_TRUE);					
					break;
				}
			}
			vadp_fm_radio_set_a2dp_connect_state(VADP_FM_RADIO_A2DP_CONNECTED);
			break;
		}

		// Need to close A2DP connection
        case SRV_A2DP_CALLBACK_EVENT_STREAM_ABORT_IND:
        case SRV_A2DP_CALLBACK_EVENT_STREAM_CLOSE_IND:
        case SRV_A2DP_CALLBACK_EVENT_STREAM_SUSPEND_IND:
        case SRV_A2DP_CALLBACK_EVENT_UNEXPECTED_DISCONNECT_IND:

		// Connect A2DP failed..
		case SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED:
        case SRV_A2DP_CALLBACK_EVENT_OPEN_STOPPED:		
		case SRV_A2DP_CALLBACK_EVENT_OPEN_SCO:
		{
			switch(a2dp_connect_state)
			{
				case VADP_FM_RADIO_A2DP_CONNECTING:
				{
                	vadp_fm_radio_start_playing();
					break;
				}
				case VADP_FM_RADIO_A2DP_CONNECTING_WHILE_PLAY:
				{
					break;
				}
				case VADP_FM_RADIO_A2DP_CONNECTED:
				{
					vadp_fm_radio_close_a2dp_connection();
					break;
				}
			}
			vadp_fm_radio_set_a2dp_connect_state(VADP_FM_RADIO_A2DP_DISCONNECTED);
			break;
		}

		default:
			break;

/**
        case SRV_A2DP_CALLBACK_EVENT_OPEN_CANCELED:
            // this result means someone else is using mdi audio thus current playing is canceled
            break;

        case SRV_A2DP_CALLBACK_EVENT_INQUIRY_START_IND:
            // Shall not happen
            break;

        case SRV_A2DP_CALLBACK_EVENT_INQUIRY_STOP_IND:
            // Shall not happen
            break;

        case SRV_A2DP_CALLBACK_EVENT_STREAM_START_IND:
            // not support
            break;
*/           
	}

}

void vadp_fm_radio_close_a2dp_connection()
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_VADP_CLOSE_A2DP_CONNECTION);

	// Suggest to use them together (close codec first then close signal) to prevent some potential problems.
	srv_a2dp_close_codec();
	srv_a2dp_close(MMI_FALSE);
	vadp_fm_radio_set_a2dp_connect_state(VADP_FM_RADIO_A2DP_DISCONNECTED);
}
#endif // __MMI_FM_VIA_A2DP__

#ifdef __MMI_AVRCP_SUPPORT__
void vadp_fm_radio_register_avrcp_cmd_callback(vadp_fmr_avrcp_cmd_callback handler, void *user_data, U8 app_id)
{
	if(g_vadp_fm_radio_avrcp_cmd[app_id].handler == NULL)
	{
		g_vadp_fm_radio_avrcp_cmd[app_id].handler = handler;
		g_vadp_fm_radio_avrcp_cmd[app_id].user_data = user_data;

		g_vadp_fm_radio_avrcp_cmd_process_func_register_num++;
		srv_avrcp_set_cmd_hdlr(vadp_fm_radio_avrcp_cmd_callback);
		
		MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_VADP_REGISTER_AVRCP_CMD_CALLBACK, app_id, g_vadp_fm_radio_avrcp_cmd_process_func_register_num);
	}
}

void vadp_fm_radio_deregister_avrcp_cmd_callback(U8 app_id)
{
	if(g_vadp_fm_radio_avrcp_cmd[app_id].handler != NULL)
	{
		g_vadp_fm_radio_avrcp_cmd[app_id].handler = NULL;
		g_vadp_fm_radio_avrcp_cmd[app_id].user_data = NULL;

		g_vadp_fm_radio_avrcp_cmd_process_func_register_num--;	
		if(g_vadp_fm_radio_avrcp_cmd_process_func_register_num == 0)
		{
			srv_avrcp_clear_cmd_hdlr(vadp_fm_radio_avrcp_cmd_callback);
		}
		
		MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_VADP_DEREGISTER_AVRCP_CMD_CALLBACK, app_id, g_vadp_fm_radio_avrcp_cmd_process_func_register_num);
	}
}

VfxBool vadp_fm_radio_process_avrcp_cmd(VfxKeyEvent & event, VfxBool is_from_avrcp, void *user_data)
{
	// Only need to  process key down event.
	if(event.type != VFX_KEY_EVENT_TYPE_DOWN)
	{
		return VFX_FALSE;
	}

	if(vadp_fm_radio_query_state() == VADP_FM_RADIO_SCANING)
	{
		//Pop out balloon "currently not avaiable" only in key down. Do nothing in key up.
		VfxWString info;
		info = VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE);
		mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)info.getBuf());

		return VFX_FALSE;
	}
	
	switch (event.keyCode)
    {
        case VFX_KEY_CODE_ENTER:
        {
           	vadp_fm_radio_power_off();
			break;
        }
		case VFX_KEY_CODE_ARROW_RIGHT:
		{
			if(vadp_fm_radio_query_state() == VADP_FM_RADIO_SEEKING)
		    {
		        return VFX_FALSE;
		    }
			
        	#ifndef __FM_RADIO_HW_SEARCH__
	            if(vadp_fm_radio_get_cur_freq() == VappFMRadioApp::MAX_FREQ)
	            {
	                return VFX_FALSE;
	            }
        	#endif

			//go to next good channel
			vadp_fm_radio_seek(vadp_fm_radio_get_cur_freq(), VFX_TRUE);
			vadp_fm_radio_update_state(VADP_FM_RADIO_SEEKING);
			break;
		}
		case VFX_KEY_CODE_ARROW_LEFT:
		{
			if(vadp_fm_radio_query_state() == VADP_FM_RADIO_SEEKING) 
		    {
		        return VFX_FALSE;
		    }
			
        	#ifndef __FM_RADIO_HW_SEARCH__
	            if(vadp_fm_radio_get_cur_freq() == VappFMRadioApp::MIN_FREQ)
	            {
	                return VFX_FALSE;
	            }
        	#endif

			//go to prev good channel
			vadp_fm_radio_seek(vadp_fm_radio_get_cur_freq(), VFX_FALSE);
			vadp_fm_radio_update_state(VADP_FM_RADIO_SEEKING);
			break;
		}
		
	}

	return VFX_TRUE;
}

U8 vadp_fm_radio_avrcp_cmd_callback(U8 command, srv_avrcp_key_events key_events)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_VADP_AVRCP_CMD_CALLBACK, command, key_events);

	VfxKeyEvent transferEvent;

	// Only need to process key_down and key_up. 
	switch(key_events)
	{
		case SRV_AVRCP_KEY_DOWN:
		{
			transferEvent.type = VFX_KEY_EVENT_TYPE_DOWN;
			break;
		}		
		case SRV_AVRCP_KEY_UP:
		{
			transferEvent.type = VFX_KEY_EVENT_TYPE_UP;
			break;
		}

		// No need to process, as long press.
		default:
		{
			return SRV_AVRCP_CR_REJECT;
		}
	}
	
	switch (command)
	{
		case SRV_AVRCP_POP_PLAY:
		case SRV_AVRCP_POP_STOP:
		case SRV_AVRCP_POP_PAUSE:
		{
			transferEvent.keyCode = VFX_KEY_CODE_ENTER;
			break;		
		}
		case SRV_AVRCP_POP_FORWARD:
		{
			transferEvent.keyCode = VFX_KEY_CODE_ARROW_RIGHT;
			break;
		}				
		case SRV_AVRCP_POP_BACKWARD:
		{
			transferEvent.keyCode = VFX_KEY_CODE_ARROW_LEFT;
			break;
		}

		// No need to process, as mute.
		default:
		{
			return SRV_AVRCP_CR_NOT_IMPLEMENT;
		}	
	}

	// Callback FM Radio component  fucntion to process AVRCP cmd.
    for(U8 i = 0; i <= VADP_FM_RADIO_TOTAL; i++)
	{
		if(g_vadp_fm_radio_avrcp_cmd[i].handler != NULL)
		{
			g_vadp_fm_radio_avrcp_cmd[i].handler(transferEvent, VFX_TRUE, g_vadp_fm_radio_avrcp_cmd[i].user_data);
			return SRV_AVRCP_CR_ACCEPT;
		}
	}
	
	return SRV_AVRCP_CR_NOT_IMPLEMENT;	
}
#endif // __MMI_AVRCP_SUPPORT__

#if (defined(__MMI_BT_FM_VIA_SCO__) || defined(__MMI_FM_VIA_A2DP__))
VfxBool vadp_fm_radio_is_connecting_bt_headset()
{	
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_VADP_IS_CONNECTING_A2DP, vadp_fm_radio_get_a2dp_connect_state());
	
	return ((vadp_fm_radio_get_a2dp_connect_state() == VADP_FM_RADIO_A2DP_CONNECTING)
			|| (vadp_fm_radio_get_a2dp_connect_state() == VADP_FM_RADIO_A2DP_CONNECTING_WHILE_PLAY));
}

void vadp_fm_radio_enable_play_via_bt_headset(void)
{	
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_VADP_ENABLE_BT_HEADSET);

	#ifdef __MMI_BT_FM_VIA_SCO__
		if(g_vadp_fm_radio_is_sco_disabled)
		{		
			srv_btsco_enable_sco_connection(SRV_BT_SCO_INT_FMRADIO);
			g_vadp_fm_radio_is_sco_disabled = VFX_FALSE;
		}
	#endif
			
	#ifdef __MMI_FM_VIA_A2DP__
		if(srv_a2dp_is_output_to_bt())		// Can connect A2DP or SCO
		{	
			vadp_fm_radio_set_a2dp_connect_state(VADP_FM_RADIO_A2DP_CONNECTING_WHILE_PLAY);		
			vadp_fm_radio_connect_a2dp();
		}
	#endif	
}

void vadp_fm_radio_disable_play_via_bt_headset(void)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_VADP_DISABLE_BT_HEADSET);

	#ifdef __MMI_BT_FM_VIA_SCO__
		srv_btsco_disable_sco_connection(SRV_BT_SCO_INT_FMRADIO);
		g_vadp_fm_radio_is_sco_disabled = VFX_TRUE;
	#endif
		
	#ifdef __MMI_FM_VIA_A2DP__
		vadp_fm_radio_close_a2dp_connection();
	#endif
}
 
void vadp_fm_radio_listen_to_BT_connection(void)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_VADP_LISTEN_TO_BT_CONNECTION);

	g_vadp_fm_radio_bt_aud_handle = srv_btaud_open(BTAUD_LEVEL_NORMAL, BTAUD_CHNL_ANY);
	srv_btaud_set_notify(
		g_vadp_fm_radio_bt_aud_handle, 
		BTAUD_EV_STEREO_CONFIG_IND, 
		(BtAudNotify) vadp_fm_radio_BT_aud_event_handler, 
		NULL
		);	
}

S32 vadp_fm_radio_BT_aud_event_handler(BtAudEvent event, U32 arg, void *user_data)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_VADP_BT_AUD_EVENT_HDLR, event);

	// Only interested in BTAUD_EV_STEREO_CONFIG_IND in FM Radio. 
    if (event == BTAUD_EV_STEREO_CONFIG_IND)
    {	
        if (vadp_fm_radio_is_playing() 
			&& (vadp_fm_radio_get_aud_path() == MDI_DEVICE_SPEAKER2)
		#ifdef __MMI_FM_VIA_A2DP__
			&& (vadp_fm_radio_get_a2dp_connect_state() == VADP_FM_RADIO_A2DP_DISCONNECTED)
		#endif
			)
        {
			vadp_fm_radio_enable_play_via_bt_headset();
			return VFX_TRUE;
        }
   }       

	return VFX_FALSE;
}

void vadp_fm_radio_toggle_bt_aud_path()
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_VADP_TOGGLE_BT_AUD_PATH, vadp_fm_radio_aud_path);

	if(vadp_fm_radio_get_aud_path() == MDI_DEVICE_SPEAKER2)		// Audio passsed by earphone or bt.
	{						
		g_vadp_fm_radio_is_audio_path_toggled = VFX_TRUE;
		vadp_fm_radio_enable_play_via_bt_headset();
	}
	else 	// MDI_DEVICE_SPEAKER_BOTH,  Audio passsed by earphone and loudspeaker.
	{
		vadp_fm_radio_disable_play_via_bt_headset();
	}
}
#endif // (defined(__MMI_BT_FM_VIA_SCO__) || defined(__MMI_FM_VIA_A2DP__))


/***************************************************************************** 
 * temp dummy
 *****************************************************************************/
void mmi_fmrdo_init_app(void)
{
}

BOOL mmi_fmrdo_is_power_on(void)
{
    return FALSE;
}

mmi_ret mmi_fmrdo_earphone_notify_hdlr(mmi_event_struct *event)
{
    return 0;
}

mmi_ret mmi_fmgr_fmrdo_notify_hdlr(mmi_event_struct *event)
{
    return 0;
}

#ifdef __cplusplus
}
#endif

#endif

