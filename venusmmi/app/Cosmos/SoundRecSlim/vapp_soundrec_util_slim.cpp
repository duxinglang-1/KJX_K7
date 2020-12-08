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
 *  Sound recorder utility source code file
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
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h" 

#ifdef __MMI_SOUNDREC_SLIM__

#include "vapp_soundrec_slim.h"
#include "vapp_soundrec_util_slim.h"
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


#pragma arm section code = "DYNAMIC_CODE_SOUNDREC_ROCODE", rodata = "DYNAMIC_CODE_SOUNDREC_RODATA"


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


mdi_result vadp_soundrec_rec_start(VfxWChar *fullpath, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    mdi_audio_rec_param_struct rec_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_get_record_param(MDI_AUDIO_REC_MODE_IDLE, VADP_SOUND_RECORDER_REC_QUALITY, &rec_param);

    result = mdi_audio_start_record(fullpath, rec_param.format, MDI_AUDIO_REC_QUALITY_AUTO, vadp_soundrec_mdi_callback, user_data);

	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_SLIM_VADP_REC_START, result);

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
	
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_SLIM_VADP_REC_PAUSE, result);

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
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_SLIM_VADP_REC_RESUME, result);

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
	
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_SLIM_VADP_REC_STOP, result);
	
    // Enable touch feedback when play music
    vfx_adp_touch_fb_enable_tone();
    vfx_adp_touch_fb_enable_vibrate();

    return result;
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

VfxBool vapp_soundrec_util_check_memory_card_ready()
{
   return FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) == FS_NO_ERROR;
}

VfxBool vapp_soundrec_util_get_record_file_path(VfxU16 start_index, VfxU16 stop_index, VfxU16 *result_index, VfxWChar *filepath, VfxU16 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxU16 index = start_index;
    int ret;
    mdi_audio_rec_param_struct rec_param;

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
    mdi_audio_get_record_param(MDI_AUDIO_REC_MODE_IDLE, VADP_SOUND_RECORDER_REC_QUALITY, &rec_param);

    /* Create File */
    do
    {
		kal_wsprintf(filepath, "%c:\\%w%w%03d%w", vapp_soundrec_util_get_storage_drive(), RECORD_DOWNLOAD_FOLDER_NAME, GetString(STR_ID_VAPP_SNDREC_FILENAME_PREFIX), index, rec_param.file_ext);		  

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

	VfxU8 storage_drive = vapp_soundrec_util_get_storage_drive();
	kal_wsprintf((U16*) drive_str, "%c:\\", storage_drive);
    result.ret = FS_GetDevStatus(storage_drive, FS_FEATURE_STATE_ENUM);
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

VfxU8 vapp_soundrec_util_get_storage_drive(void)
{
	#ifdef __MMI_SOUNDREC_SLIM_PHONE_DRIVE__
		return srv_soundrec_get_storage();
	#else
		return srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE);
	#endif
}

#pragma arm section code, rodata


#endif // __MMI_SOUNDREC_SLIM__
