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
 *  vapp_soundrec_util.cpp
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
 *  
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

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h" 
#include "vapp_soundrec.h"
#include "vapp_soundrec_util.h"
#include "mmi_rp_vapp_soundrec_def.h"

#include "vfx_adp_device.h" // For touch feedback

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
#include "mdi_audio.h"
#include "FileMgrSrvGProt.h"
#include "SoundRecSrvGProt.h"
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

/***************************************************************************** 
 * Function
 *****************************************************************************/

static mdi_handle g_vadp_soundrec_play_handle;


/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_soundrec_mdi_callback(mdi_result result, void *user_data)
{
    VappSoundRecorderRecordPage *cb_obj = (VappSoundRecorderRecordPage *)user_data;

    if(cb_obj != NULL)
    {
        cb_obj->recordCallbackHdlr(result);
    }
}


mdi_result vadp_soundrec_rec_start(VfxWChar *fullpath, void *user_data, VfxU32 size_limit, VfxU32 time_limit, VfxBool use_default_quality, VfxU8 quality)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    mdi_audio_rec_param_struct rec_param;
    MDI_AUDIO_REC_QUALITY_ENUM rec_quality;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(use_default_quality)
    {
        rec_quality = srv_soundrec_get_mdi_quality();
    }
    else
    {
        rec_quality = (MDI_AUDIO_REC_QUALITY_ENUM)quality;
    }

    mdi_audio_get_record_param(MDI_AUDIO_REC_MODE_IDLE, rec_quality, &rec_param);

    result = mdi_audio_start_record_with_limit(fullpath, rec_param.format, MDI_AUDIO_REC_QUALITY_AUTO, vadp_soundrec_mdi_callback, user_data, size_limit, time_limit);

	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_VADP_REC_START, result);

    if(result == MDI_AUDIO_SUCCESS)
    {
        // Disable touch feedback when play music
        vfx_adp_touch_fb_disable_tone();
        vfx_adp_touch_fb_disable_vibrate();
    }

    return result;
}

mdi_result vadp_soundrec_rec_pause(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_audio_pause(vadp_soundrec_mdi_callback, user_data);
	
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_VADP_REC_PAUSE, result);

    // Enable touch feedback when play music
    vfx_adp_touch_fb_enable_tone();
    vfx_adp_touch_fb_enable_vibrate();

    return result;
}


mdi_result vadp_soundrec_rec_resume(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_audio_resume(vadp_soundrec_mdi_callback, user_data);
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_VADP_REC_RESUME, result);

    if(result == MDI_AUDIO_SUCCESS)
    {
        // Disable touch feedback when play music
        vfx_adp_touch_fb_disable_tone();
        vfx_adp_touch_fb_disable_vibrate();
    }

    return result;
}


mdi_result vadp_soundrec_rec_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_audio_stop_record();
	
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_VADP_REC_STOP, result);
	
    // Enable touch feedback when play music
    vfx_adp_touch_fb_enable_tone();
    vfx_adp_touch_fb_enable_vibrate();

    return result;
}


/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_soundrec_play_callback(kal_int32 handle, kal_int32 result, void* user_data)
{
    VappSoundRecorderPlayPage *cb_obj = (VappSoundRecorderPlayPage *)user_data;

    if((cb_obj != NULL) && (handle == g_vadp_soundrec_play_handle))
    {
        cb_obj->playCallbackHdlr(result);
    }
}

void vadp_soundrec_seekStop(void)
{
	if (g_vadp_soundrec_play_handle)
		{
			mdi_audio_stop_seek();
		}
}

void vadp_soundrec_seekcallback(kal_uint8 result, void* user_data)
{
	/* Stop timer update */
	
    VappSoundRecorderPlayPage *cb_obj = (VappSoundRecorderPlayPage *)user_data;

	if(cb_obj != NULL)
    {
        cb_obj->seekCallbackHdlr((kal_int32)result);
    }

}


/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result vadp_soundrec_open(void *user_data, const VfxWChar *full_path)
{
    /* Open file */
    VappSoundRecorderPlayPage *cb_obj = (VappSoundRecorderPlayPage *)user_data;
	
    g_vadp_soundrec_play_handle = mdi_audio_mma_open_file(0, (void*)full_path, 0, MMI_FALSE, vadp_soundrec_play_callback, user_data);

    if(g_vadp_soundrec_play_handle == NULL)
    {
        return MDI_AUDIO_FAIL;
    }

	if(cb_obj->m_cacheTable == NULL)
	{
		VFX_ALLOC_MEM(cb_obj->m_cacheTable, MDI_CACHE_SIZE, cb_obj);
		memset(cb_obj->m_cacheTable, 0, MDI_CACHE_SIZE);
	}
	else
	{
		memset(cb_obj->m_cacheTable, 0, MDI_CACHE_SIZE);
	}
		
    mdi_audio_mma_set_cache_table(g_vadp_soundrec_play_handle, cb_obj->m_cacheTable);   

	return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result vadp_soundrec_play(void)
{
    mdi_result result;

    if(g_vadp_soundrec_play_handle)
    {
        mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2);
        result = mdi_audio_mma_play(g_vadp_soundrec_play_handle);
		
		MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_VADP_PLAY_START, result);

        if(result == MDI_AUDIO_SUCCESS)
        {
            // Disable touch feedback when play music
            vfx_adp_touch_fb_disable_tone();
        }
    }
    else
    {
        result = MDI_AUDIO_FAIL;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result vadp_soundrec_pause(void)
{
    mdi_result result;

    if(g_vadp_soundrec_play_handle)
    {
        result = mdi_audio_mma_pause(g_vadp_soundrec_play_handle);
		
		MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_VADP_PLAY_PAUSE, result);
		
        // Enable touch feedback when play music
        vfx_adp_touch_fb_enable_tone();
    }
    else
    {
        result = MDI_AUDIO_FAIL;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result vadp_soundrec_resume(void)
{
    mdi_result result;

    if(g_vadp_soundrec_play_handle)
    {
        result = mdi_audio_mma_resume(g_vadp_soundrec_play_handle);
		
		MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_VADP_PLAY_RESUME, result);

        if(result == MDI_AUDIO_SUCCESS)
        {
            // Disable touch feedback when play music
            vfx_adp_touch_fb_disable_tone();
        }
    }
    else
    {
        result = MDI_AUDIO_FAIL;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result vadp_soundrec_stop(void)
{
    mdi_result result;

    if(g_vadp_soundrec_play_handle)
    {
        result = mdi_audio_mma_stop(g_vadp_soundrec_play_handle);

		MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_VADP_PLAY_STOP, result);

        // Enable touch feedback when play music
        vfx_adp_touch_fb_enable_tone();
    }
    else
    {
        result = MDI_AUDIO_FAIL;
    }

    return result;    
}


/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result vadp_soundrec_close(void *user_data)
{
    mdi_result result;
	
    VappSoundRecorderPlayPage *cb_obj = (VappSoundRecorderPlayPage *)user_data;

    if(g_vadp_soundrec_play_handle)
    {
        result = mdi_audio_mma_close(g_vadp_soundrec_play_handle);
    }
    else
    {
        result = MDI_AUDIO_FAIL;
    }

	if (cb_obj->m_cacheTable != NULL)
    {
        VFX_FREE_MEM(cb_obj->m_cacheTable);
        cb_obj->m_cacheTable = NULL;
    }

    return result;  
}


/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
VfxBool vadp_soundrec_is_playing(void)
{
    if(g_vadp_soundrec_play_handle)
    {
        if(mdi_audio_is_playing(MDI_AUDIO_PLAY_MMA))
        {
            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
VfxBool vadp_soundrec_get_current_time(VfxU32 *current_time)
{
    U32 get_time;

    if(g_vadp_soundrec_play_handle)
    {    
        if(mdi_audio_mma_get_current_time(g_vadp_soundrec_play_handle, &get_time) == MDI_AUDIO_SUCCESS)
        {
            *current_time = get_time;
            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_soundrec_set_current_time(VfxU32 current_time)
{
    if(g_vadp_soundrec_play_handle)
    {    
        mdi_audio_mma_set_start_time(g_vadp_soundrec_play_handle, current_time);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_util_filter_set
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filter    [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_soundrec_util_filter_set(FMGR_FILTER *filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(filter);
#ifndef __MTK_TARGET__
    FMGR_FILTER_SET(filter, FMGR_TYPE_DAF); /* Test on Modis only */ 
#endif
    FMGR_FILTER_SET(filter, FMGR_TYPE_WAV);
    FMGR_FILTER_SET(filter, FMGR_TYPE_AMR);
    FMGR_FILTER_SET(filter, FMGR_TYPE_AWB);
#if defined(__VORBIS_DECODE__) && defined(__VORBIS_ENCODE__)
    FMGR_FILTER_SET(filter, FMGR_TYPE_OGG);
#endif

}


VfxWString& vapp_soundrec_util_get_format_time(VfxWString &string, VfxU64 display_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxU32 hour, minute, second;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    display_time = display_time / 1000;

    hour = display_time / 3600;
    minute = (display_time %3600)/60;
    second = (display_time %3600)%60;

    return string.format("%02d:%02d:%02d", hour, minute, second);
}

S32 vapp_soundrec_util_check_record_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxWChar folder_path[VAPP_SNDREC_FOLDER_LEN + 1];

	#ifdef __LOW_COST_SUPPORT_COMMON__
		VfxU8 m_drive = srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE);
	#else
		VfxU8 m_drive = srv_soundrec_get_storage();
	#endif
	
		kal_wsprintf(folder_path, "%c:\\%w", m_drive, RECORD_DOWNLOAD_FOLDER_NAME);

    /* Check and create folder */
    return srv_fmgr_fs_create_folder(folder_path);
}


VfxBool vapp_soundrec_util_get_record_file_path(VfxU16 start_index, VfxU16 stop_index, VfxU16 *result_index, VfxWChar *filepath, VfxU16 buffer_size, VfxBool default_quality, VfxU8 quality)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxU16 index = start_index;
    int ret;
    mdi_audio_rec_param_struct rec_param;
    MDI_AUDIO_REC_QUALITY_ENUM rec_quality;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check buffer size */
    if(buffer_size < (VAPP_SNDREC_FOLDER_LEN + VAPP_SNDREC_FILENAME_LEN + 1)*sizeof(VfxWChar))
    {
        *result_index = 0xFFFF;
        return VFX_FALSE;
    }

    /*Get file extension*/
    if(default_quality)
    {
        rec_quality = srv_soundrec_get_mdi_quality();
    }
    else
    {
        rec_quality = (MDI_AUDIO_REC_QUALITY_ENUM)quality;
    }
    mdi_audio_get_record_param(MDI_AUDIO_REC_MODE_IDLE, rec_quality, &rec_param);

    /* Create File */
    do
    {
    #ifdef __LOW_COST_SUPPORT_COMMON__
		VfxU8 m_drive = srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE);
	#else
    	VfxU8 m_drive = srv_soundrec_get_storage();
	#endif
	
		kal_wsprintf(filepath, "%c:\\%w%w%03d%w", m_drive, RECORD_DOWNLOAD_FOLDER_NAME, GetString(STR_ID_VAPP_SNDREC_FILENAME_PREFIX), index, rec_param.file_ext);		  

        /* Check if file exists */
		ret = FS_Open(filepath, FS_READ_ONLY);
        if(FS_FILE_NOT_FOUND == ret)
        {
            *result_index = index;
            return VFX_TRUE;
        }
        else if(ret < FS_NO_ERROR)
        {
            /* Other file system error */
            *result_index = 0xFFFF;
            return VFX_FALSE;
        }
        FS_Close(ret);
		index++;
    } while (index <= stop_index);

    *result_index = stop_index;
    return VFX_FALSE;
}

vapp_soundrec_check_size_result vapp_soundrec_util_get_record_drv_free_space(void)
{
    VfxU8 drive_str[32];
    FS_DiskInfo diskinfo;
	vapp_soundrec_check_size_result result;
	result.disk_size = 0; result.ret = 0;

	#ifdef __LOW_COST_SUPPORT_COMMON__
		VfxU8 m_drive = srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE);
	#else
	    VfxU8 m_drive = srv_soundrec_get_storage();
	#endif
	
	kal_wsprintf((U16*) drive_str, "%c:\\", m_drive);
    result.ret = FS_GetDevStatus(m_drive, FS_FEATURE_STATE_ENUM);
    if (result.ret >= FS_NO_ERROR)
    {
        result.ret = FS_GetDiskInfo((U16*) drive_str, &diskinfo, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
	    if (result.ret >= FS_NO_ERROR)
	    {
            result.disk_size = diskinfo.FreeClusters * diskinfo.SectorsPerCluster * diskinfo.BytesPerSector;
	    }
    }

    return result;
}

