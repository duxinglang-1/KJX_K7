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
 * widget_sound.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Widget sound loading and caching in filesystem
 *
 * Author:
 * -------
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "widget.h"

#include "resource_audio.h"     /* Standard tone */
#include "settingprofile.h"     /* for SRV_PROF_TONE_MMS */
#include "msf_cmmn.h"   /* for msf_cmmn_* */
#include "ProfilesSrvGprot.h"      /* srv_prof_play_tone */

#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "device.h"     /* for DEVICE_AUDIO_XXX */

#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"

#ifdef __DRM_SUPPORT__
#include "../../drm/include/drm_gprot.h"
#endif 

/*
 * Note on the audio system
 * *
 * * 1. On playing a new audio (file/stream/audioId), it will automatically stop the last one
 * * 2. For input audio Id, it already known the audio type. For input files, it uses filename extension to determine the type.
 * * 3. use SMF for all kinds of midi (including SP-MIDI)
 * * 
 * * There is no race condition in MDI audio, it can play and stop the file very fast. 
 * *
 * * When playing an audio file (mdi_audio_play_file), it will send primitive to media task 
 * * When stopping an audio file (mdi_audio_stop_file), it will send primitive to media task and wait for event group.
 * * Because media task processes incoming requests sequentially, the sound is always gracefully stopped after mdi_audio_stop_file().
 * *
 * * When the current widget sound is preempted by another application, it will use mdi_audio_play_file() which invokes callback
 * * function immediately in MMI task. As a result, the registered callback function is always executed before 
 * * new requests to media task.
 * *
 * * NOTE: We always store sound in filesystem (NOR flash) instead of memory. If the system storage space is not enough,
 * * we will not be able to play sound at all (widget_sound_struct.rawfile_id == -1)
 */

/* 
 * Note on resource creation:
 * Teleca confirmed that we can return 0 if the audio creation (HDIa_widgetImageCreate, HDIa_widgetImageCreateResource, 
 * HDIa_widgetSoundCreate, HDIa_widgetSoundCreateResource. ) failed.
 */

/* NOTE: CHANGES SHOULD BE SYNCHRONIZED WITH widget_image.c */

/****************************************************************
 * Data structure
 ***************************************************************/
#ifdef WIDGET_SUPPORT_SOUND
typedef struct
{
    MsfSoundFormat format;
    char fn_ext[6]; /* Filename extension */
    const char *mime_type;
} widget_sound_typeinfo_struct;

const widget_sound_typeinfo_struct widget_sound_typeinfo_table[] = 
{
    {MsfAmr, ".amr", "audio/amr"},
#ifdef AMRWB_DECODE
    {MsfAmrWB, ".awb", "audio/amr-wb"},
#endif 
#ifdef DAF_DECODE
    {MsfMp3, ".mp3", "audio/mp3"},                          /* Standard audio/mpeg, but MMS modules use "audio/mp3" */
#endif 
#ifdef WMA_DECODE
        {MsfWma, ".wma", "audio/x-ms-wma"},
#endif 
#ifdef AAC_DECODE
        {MsfAac, ".aac", "audio/aac"},
#endif 
#ifdef MP4_DECODE
    {MsfM4a, ".m4a", "audio/m4a"},
#endif
#ifdef AIFF_DECODE
    {MsfAiff, ".aif", "audio/x-aiff"},
    {MsfAiff, ".aiff", "audio/x-aiff"},
    {MsfAiff, ".aifc", "audio/x-aiff"},
#endif
#ifdef AU_DECODE
    {MsfBasic, ".au", "audio/basic"},
    {MsfBasic, ".snd", "audio/basic"},
#endif
#ifdef  MUSICAM_DECODE
    {MsfMp2, ".mp2", "audio/mp2"},
#endif
    {MsfMidi, ".mid", "audio/midi"},                        /* x-midi & sp-midi */
    {MsfMidi, ".midi", "audio/midi"},
	{MsfMidi, ".mmf", "application/vnd.smaf"},
	{MsfMidi, ".mmf", "application/x-smaf"},
    {MsfWav, ".wav", "audio/x-wav"},                        /* NowSMS use audio/wav, MEA support both */
    {(MsfSoundFormat) MsfImelody, ".imy", "text/x-imelody"} /* Nokia use text/x-imelody, although audio/imelody should be standard */
};

#define WIDGET_SOUND_TYPEINFO_NUM   (sizeof(widget_sound_typeinfo_table)/sizeof(widget_sound_typeinfo_struct))

/* for waiting sound */
#define WIDGET_SOUND_WAIT_MORE_DATA					(1)
#define WIDGET_SOUND_WANT_TO_PLAY_WAITING_SOUND		(2)


/* for get sound duration */
#define WIDGET_SOUND_CACHE_SIZE     (2048)
#define WIDGET_SOUND_TEMP_SIZE      (1024)

/****************************************************************
 * Prototype of static function
 ***************************************************************/
static void widget_send_notification_load_resource(widget_sound_struct *snd, kal_bool state);
static int widget_sound_length(MsfSoundHandle sound);
static void widget_sound_set_done(widget_sound_struct *snd);

/* for get sound duration */
static kal_uint32 sound_duration = 0;

/****************************************************************
 * Extern
 ***************************************************************/
/* for get sound duration */
extern kal_bool aud_util_build_cache_start(
                    kal_wchar *filename, 
                    void* cache_p, kal_int32 cache_size, 
                    void *file_buf, kal_int32 file_buf_size, 
                    void *proc_buf, kal_int32 proc_buf_size);
extern void aud_util_build_cache_stop(void);
extern kal_bool aud_util_build_cache_process(kal_uint32 *progress_p);
extern kal_uint32 aud_util_build_cache_get_duration(void);


#ifndef __MTK_TARGET__


/*****************************************************************************
 * FUNCTION
 *  widget_output_sound_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  snd     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_output_sound_file(widget_sound_struct *snd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * if(snd->is_done)
     * {
     * static int cnt=0;
     * char filename[128];
     * switch(snd->sound_format)
     * {
     * case MsfAmr:      sprintf(filename,"wap_%03d.amr",cnt);break;
     * case MsfMidi:     sprintf(filename,"wap_%03d.mid",cnt);break;
     * case MsfWav:      sprintf(filename,"wap_%03d.wav",cnt);break;
     * case MsfImelody:  sprintf(filename, "wap_%03d.imy",cnt);break;
     * default:
     * ASSERT(0);
     * }
     * cnt++;
     * {
     * FILE *f=fopen(filename,"wb");
     * fwrite(snd->raw->data,snd->raw->size,1,f);
     * fclose(f);
     * }
     * }
     */
}
#endif /* __MTK_TARGET__ */ 

/****************************************************************
 * Audio format and filename extension conversion
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_sound_format_to_extension
 * DESCRIPTION
 *  
 * PARAMETERS
 *  soundFormat     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const char *widget_sound_format_to_extension(MsfSoundFormat soundFormat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    const widget_sound_typeinfo_struct *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WIDGET_SOUND_TYPEINFO_NUM; i++)
    {
        item = &widget_sound_typeinfo_table[i];
        if (item->format == soundFormat)
        {
            return item->fn_ext;
        }
    }

    return ".mid";
}


/*****************************************************************************
 * FUNCTION
 *  widget_sound_file_ext_to_mime_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ext     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const char *widget_sound_file_ext_to_mime_type(const char *ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    const widget_sound_typeinfo_struct *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WIDGET_SOUND_TYPEINFO_NUM; i++)
    {
        item = &widget_sound_typeinfo_table[i];
        if (msf_cmmn_strcmp_nc(item->fn_ext, ext) == 0)
        {
            return item->mime_type;
        }
    }
    return NULL;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

/****************************************************************
 * Resouce loading
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_sound_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sound       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int widget_sound_length(MsfSoundHandle sound)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_sound_struct *snd = _SND(sound);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(IS_SOUND_TYPE(snd));
    if (snd->rawfile_id > 0)
    {
        return widget_rawfile_getsize(snd->rawfile_id);
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_send_notification_load_resource
 * DESCRIPTION
 *  It is only for MsfSound widgets that are created using a resource
 *  (ie. not by HDIa_widgetSoundCreate() )
 * PARAMETERS
 *  snd         [IN]        The sound widget
 *  state       [IN]        Success or failure
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_send_notification_load_resource(widget_sound_struct *snd, kal_bool state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (state)
    {
        HDIc_widgetNotify(snd->module_id, (MSF_UINT32) snd, MsfNotifyResourceLoaded);
    }
    else
    {
        HDIc_widgetNotify(snd->module_id, (MSF_UINT32) snd, MsfNotifyResourceFailed);
    }

    widget_send_update_event_to_wap();
}


/*****************************************************************************
 * FUNCTION
 *  widget_sound_set_done
 * DESCRIPTION
 *  Set the sound ready (all data is read). Then we can play it
 * PARAMETERS
 *  snd     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_sound_set_done(widget_sound_struct *snd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (snd->rawfile_id > 0)    /* -1 is illegal */
    {
        widget_rawfile_configure_format(
            snd->rawfile_id,
            snd->sound_format,
            widget_sound_format_to_extension(snd->sound_format));
    }
    snd->is_done = KAL_TRUE;    /* Finish reading. The sound might not be saved successfully, however. */

    if (WSND_CTX->wait_more_data == WIDGET_SOUND_WANT_TO_PLAY_WAITING_SOUND)
    {
        /*
         * If the application wants to play the waiting sound,
         * we send the primitive to WAP task to play it.
         */
        widget_send_update_event_to_wap();
        WSND_CTX->waiting_sound = snd;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_read_sound_from_file
 * DESCRIPTION
 *  Callback function of reading sound data from file
 *  
 *  It will do these after the sound is loaded: (but it doesn't close file)
 *  1. set "done" flag
 *  2. Send MsfNotifyResourceLoaded, etc.
 *  
 *  Note: Modify widget_read_image_from_file also if this function is changed.
 * PARAMETERS
 *  f                   [IN]            File handle
 *  size                [IN]            Expected file size ( > 0)
 *  snd                 [IN/OUT]        The sound
 *  need_add_select     [IN]            Whether to add into the map "widget_fn_*"
 *  is_DRM              [IN]            
 * RETURNS
 *  WIDGET_READ_ERROR
 *  WIDGET_WAIT_SELECT
 *  WIDGET_READ_FINISH
 *****************************************************************************/
int widget_read_sound_from_file(int f, int size, widget_sound_struct *snd, kal_bool need_add_select, kal_bool is_DRM)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *buffer = WRAW_CTX->working_buffer;
    long ret;
    int rawfile_size;
    int data_to_read;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We guarentee that snd->rawfile_id is valid at this point */
    WAP_DBG_ASSERT(snd->rawfile_id > 0 && buffer);

    while (((rawfile_size = widget_rawfile_getsize(snd->rawfile_id)) < size) && (rawfile_size >= 0))
    {
        /* read sound data */
        data_to_read = size - rawfile_size;

    #ifdef __DRM_SUPPORT__
        if (is_DRM)
        {
            kal_uint32 length;

            if (DRM_read_file
                (f, buffer, (data_to_read < WIDGET_LOAD_BUFFER_SIZE) ? data_to_read : WIDGET_LOAD_BUFFER_SIZE,
                 &length) < FS_NO_ERROR)
            {
                ret = HDI_FILE_ERROR_INVALID;
            }
            else
            {
                if (length)
                {
                    ret = length;
                }
                else
                {	/* If read length is 0, we should return HDI_FILE_ERROR_EOF */
                    ret = HDI_FILE_ERROR_EOF;
                }
            }
        }
        else
    #endif /* __DRM_SUPPORT__ */ 
        {
            ret = MSF_FILE_READ(
                    f,
                    buffer,
                    (data_to_read < WIDGET_LOAD_BUFFER_SIZE) ? data_to_read : WIDGET_LOAD_BUFFER_SIZE);
        }

        if (ret < 0)
        {
            if (ret == HDI_FILE_ERROR_DELAYED)
            {
                /* In current implementation, DRM files are opened in blocking mode */
                WAP_DBG_ASSERT(!is_DRM);

                /* Wait for notification */
                if (need_add_select)
                {
                    widget_add_file_poll(f, _H(snd), size);
                }
                MSF_FILE_SELECT(f, HDI_FILE_EVENT_READ);
                return WIDGET_WAIT_SELECT;
            }

            /* Something wrong happened */

            /* Even if "ret == HDI_FILE_ERROR_EOF", it is still incorrect. */
            WAP_DBG_ASSERT(rawfile_size < size);

            widget_send_notification_load_resource(snd, KAL_FALSE);
            return WIDGET_READ_ERROR;
        }
        else
        {
            widget_rawfile_write(snd->rawfile_id, buffer, ret);

            if (widget_rawfile_getsize(snd->rawfile_id) == size)
            {
                widget_sound_set_done(snd);

                widget_send_notification_load_resource(snd, KAL_TRUE);
                return WIDGET_READ_FINISH;
            }
            else if (widget_rawfile_write_failed(snd->rawfile_id))
            {
                widget_send_notification_load_resource(snd, KAL_FALSE);
                return WIDGET_READ_ERROR;
            }
            /* Otherwise,  keep reading */
        }
    }

    /* Should not reach here */
    widget_send_notification_load_resource(snd, KAL_FALSE);
    return WIDGET_READ_ERROR;
}

/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetSoundNextPart
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sound               [IN]        
 *  soundData           [IN]         
 *  soundDataSize       [IN]        
 *  moreData            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetSoundNextPart(MsfSoundHandle sound, char *soundData, int soundDataSize, int moreData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_sound_struct *snd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sound == 0)
    {
        return 0;
    }

    WAP_DBG_ASSERT(IS_SOUND_TYPE(sound));
    snd = _SND(sound);

    if (snd->rawfile_id == 0)   /* Create new sound file and write it */
    {
        if (!widget_rawfile_allow_to_create_sound())
        {
            snd->rawfile_id = -1;
        }
        else
        {
            /* Write sound content in file */
            snd->rawfile_id = widget_rawfile_register((MsfSoundHandle) snd);
            widget_rawfile_write(snd->rawfile_id, soundData, soundDataSize);
        }
    }
    else if (snd->rawfile_id > 0)
    {
        /* snd->rawfile_id must not be 0 */
        widget_rawfile_write(snd->rawfile_id, soundData, soundDataSize);
    }
    /* else snd->rawfile_id < 0, do nothing */

    if (!moreData)
    {
        widget_sound_set_done(snd);
    }

    return 1;
}
/*****************************************************************************
 * FUNCTION
 *  widget_read_sound_from_pipe
 * DESCRIPTION
 *  Callback function of reading sound data from pipe
 *  
 *  It will do these after the sound is loaded: (but it doesn't close pipe)
 *  1. set "done" flag
 *  2. Send MsfNotifyResourceLoaded, etc.
 *  
 *  Note: Modify widget_read_image_from_pipe also if this function is changed.
 * PARAMETERS
 *  f                   [IN]            File handle
 *  snd                 [IN/OUT]        The sound
 *  need_add_select     [IN]            Whether to add into the map "widget_pn_*"
 * RETURNS
 *  WIDGET_READ_ERROR
 *  WIDGET_WAIT_SELECT
 *  WIDGET_READ_FINISH
 *****************************************************************************/
int widget_read_sound_from_pipe(int f, widget_sound_struct *snd, kal_bool need_add_select)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long ret;
    long size;
    int is_open;
    char *buffer = WRAW_CTX->working_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(buffer);

    while (KAL_TRUE)
    {
        /* detect current data size */
        if (MSF_PIPE_STATUS(f, &is_open, &size) < 0)
        {
            return WIDGET_READ_ERROR;
        }

        if (size == 0)
        {
            /* nothing left to read */

            if (!is_open)
            {
                /* The peer writer has closed the pipe */

                /* Even though the pipe is read successfully, we still return error if snd->rawfile_id < 0 */
                if (widget_sound_length((MsfSoundHandle) snd) > 0)
                {
                    widget_sound_set_done(snd);

                    widget_send_notification_load_resource(snd, KAL_TRUE);
                    return WIDGET_READ_FINISH;
                }

                /* Note the case snd->is_done = KAL_FALSE */
                widget_send_notification_load_resource(snd, KAL_FALSE);
                return WIDGET_READ_ERROR;
            }
            else
            {
                /* Wait for notification */

                if (need_add_select)
                {
                    widget_add_pipe_poll(f, _H(snd));
                }

                MSF_PIPE_POLL(f);
                return WIDGET_WAIT_SELECT;
            }
        }

        if (size > WIDGET_LOAD_BUFFER_SIZE)
        {
            size = WIDGET_LOAD_BUFFER_SIZE;
        }
        ret = MSF_PIPE_READ(f, buffer, size);
        if (ret < 0)
        {
            if (ret == HDI_PIPE_ERROR_DELAYED)
            {
                if (need_add_select)
                {
                    widget_add_pipe_poll(f, _H(snd));
                }

                MSF_PIPE_POLL(f);
                return WIDGET_WAIT_SELECT;
            }
            else    /* if(ret == HDI_PIPE_ERROR_CLOSED) */
            {
                /* Should not happen, but no error */
                widget_send_notification_load_resource(snd, KAL_FALSE);
                return WIDGET_READ_ERROR;
            }
        }
        WAP_DBG_ASSERT(ret == size);

        HDIa_widgetSoundNextPart((MsfSoundHandle) snd, buffer, ret, KAL_TRUE);
    }

    /* UNREACHED */
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetSoundCreate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId           [IN]        
 *  soundData       [IN]         
 *  soundFormat     [IN]        
 *  size            [IN]        
 *  moreData        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfSoundHandle HDIa_widgetSoundCreate(
                MSF_UINT8 modId,
                char *soundData,
                MsfSoundFormat soundFormat,
                int size,
                int moreData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* NOTE: Some application might assume that HDIa_widgetSoundCreate always returns non-zero handle */
    widget_sound_struct *snd = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* setting the sound widget */
    if (widget_is_rawfile_full())
    {
        return (MsfSoundHandle) snd;
    }

    snd = widget_create_sound(modId);
    snd->module_id = modId;
    snd->sound_format = soundFormat;

    HDIa_widgetSoundNextPart((MsfSoundHandle) snd, (char*)soundData, size, moreData);

    return (MsfSoundHandle) snd;
}

/* The client might does not release predefined sound, and it is more complex to use memory efficiently.
   We will not support HDIa_widgetSoundGetPredefined until explicitly required by Obigo applications. */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

/* Note: According to Teleca's reply, files should only be closed, but pipes should be both closed and deleted. */


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetSoundCreateResource
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  resource            [IN]         
 *  resourceType        [IN]        
 *  soundFormat         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfSoundHandle HDIa_widgetSoundCreateResource(
                MSF_UINT8 modId,
                char *resource,
                MsfResourceType resourceType,
                MsfSoundFormat soundFormat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * User applications SHOULD use the return value to find out if the sound is created successfully
     *
     */

    widget_sound_struct *snd = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (widget_is_rawfile_full() || !widget_rawfile_allow_to_create_sound())
    {
        if (resourceType == MsfResourcePipe)
        {
            MSF_PIPE_DELETE(resource);
        }
        return (MsfSoundHandle) 0;
    }

    switch (resourceType)
    {
        case MsfResourceFile:
        {
            long size;
            int f;

            f = MSF_FILE_OPEN(MSF_MODID_WIDGET, resource, HDI_FILE_SET_RDONLY, 0 );
            if (f < 0)
            {
                /* do nothing */ ;
            }
            else if ((size = MSF_FILE_GETSIZE(resource )) <= 0)
            {
                MSF_FILE_CLOSE(f);
            }
            else
            {
                /* allocate the raw data */
                snd = widget_create_sound(modId);
                snd->module_id = modId;
                snd->sound_format = soundFormat;

                snd->rawfile_id = widget_rawfile_register((MsfSoundHandle) snd);

                switch (widget_read_sound_from_file(f, size, snd, KAL_TRUE, KAL_FALSE))
                {
                    case WIDGET_READ_FINISH:
                        MSF_FILE_CLOSE(f);
                        break;
                    case WIDGET_WAIT_SELECT:
                        WSND_CTX->wait_more_data = WIDGET_SOUND_WAIT_MORE_DATA;
                        break;
                    case WIDGET_READ_ERROR:
                        /* Actually we may free the data and return NULL alternatively */
                        MSF_FILE_CLOSE(f);
                        break;
                }
                return (MsfSoundHandle) snd;
            }
        }
            break;

        case MsfResourcePipe:
        {
            int f;

            f = MSF_PIPE_OPEN(MSF_MODID_WIDGET, resource);
            if (f >= 0)
            {
                snd = widget_create_sound(modId);
                snd->module_id = modId;
                snd->sound_format = soundFormat;

                switch (widget_read_sound_from_pipe(f, snd, KAL_TRUE))
                {
                    case WIDGET_READ_FINISH:
                        HDIa_pipeDeleteByHandle(f);
                        break;
                    case WIDGET_WAIT_SELECT:
                        WSND_CTX->wait_more_data = WIDGET_SOUND_WAIT_MORE_DATA;
                        break;
                    case WIDGET_READ_ERROR:
                        /* Actually we may free the data and return NULL alternatively */
                        HDIa_pipeDeleteByHandle(f);
                        break;
                }
                return (MsfSoundHandle) snd;
            }
        }
            break;

#if 0 /* Not supported */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __DRM_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __DRM_SUPPORT__ */ 
#endif /* 0 */

        default:
            break;
    }

    return (MsfSoundHandle) snd;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetSoundCreateFormat
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  soundData           [IN]         
 *  soundFormat         [IN]        
 *  resourceType        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfSoundHandle HDIa_widgetSoundCreateFormat(
                MSF_UINT8 modId,
                MsfCreateData *soundData,
                const char *soundFormat,
                MsfResourceType resourceType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* We do not support any audio format other than Teleca's default value */
    int sound_format = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: refer to SE technical doc for MIME type lists
    if (msf_cmmn_strcmp_nc(soundFormat, "audio/midi") == 0 ||
        msf_cmmn_strcmp_nc(soundFormat, "audio/mid") == 0 ||
        msf_cmmn_strcmp_nc(soundFormat, "audio/x-midi") == 0 || msf_cmmn_strcmp_nc(soundFormat, "audio/sp-midi") == 0 ||
        /* SMAF - Yamaha proprietary format. It depends on hardware configuration */
        msf_cmmn_strcmp_nc(soundFormat, "application/vnd.smaf") == 0 ||
        msf_cmmn_strcmp_nc(soundFormat, "application/x-smaf") == 0 ||
        /* By some vendors */
        msf_cmmn_strcmp_nc(soundFormat, "x-music/x-midi") == 0)
    {
        sound_format = MsfMidi;
    }
#ifdef AMRWB_DECODE
    else if (msf_cmmn_strcmp_nc(soundFormat, "audio/amr-wb") == 0)
    {
        sound_format = MsfAmrWB;
    }
    else if (msf_cmmn_strcmp_nc(soundFormat, "audio/amr") == 0)
    {
        sound_format = MsfAmr;
    }
#else /* AMRWB_DECODE */ 
    else if (msf_cmmn_strcmp_nc(soundFormat, "audio/amr") == 0 &&
             !(msf_cmmn_strcmp_nc(soundFormat, "audio/amr-wb") == 0))
    {
        sound_format = MsfAmr;
    }
#endif /* AMRWB_DECODE */ 
#ifdef DAF_DECODE
    else if (msf_cmmn_strcmp_nc(soundFormat, "audio/mpeg") == 0 ||
             msf_cmmn_strcmp_nc(soundFormat, "audio/mp3") == 0 /* non-standard */ )
    {
        sound_format = MsfMp3;
    }
#endif /* DAF_DECODE */ 
    else if (msf_cmmn_strcmp_nc(soundFormat, "audio/x-wav") == 0 ||
             msf_cmmn_strcmp_nc(soundFormat, "audio/wav") == 0 /* non-standard */ )
    {
        sound_format = MsfWav;
    }
    else if (msf_cmmn_strcmp_nc(soundFormat, "audio/imelody") == 0 ||
             msf_cmmn_strcmp_nc(soundFormat, "text/x-imelody") == 0 /* non-standard. Used by Nokia */ )
    {
        sound_format = MsfImelody;
    }

    if (sound_format < 0)
    {
        return (MsfSoundHandle) 0;
    }

    if (resourceType == MsfResourcePipe || resourceType == MsfResourceFile)
    {
        return (MsfSoundHandle) HDIa_widgetSoundCreateResource(
                                    modId,
                                    (char*)soundData->resource,
                                    resourceType,
                                    (MsfSoundFormat) sound_format);
    }
    else
    {
        return (MsfSoundHandle) HDIa_widgetSoundCreate(
                                    modId,
                                    (char*)soundData->directData->data,      /* prototype mismatch on 'const' */
                                    (MsfSoundFormat) sound_format,
                                    soundData->directData->dataSize,
                                    soundData->directData->moreData);
    }
}

/*****************************************************************************
 * Sound playing
 *****************************************************************************/

/* NOTE: WAP AND MMI MUST HAVE THE SAME PRIORITY TO USE MDI */

// TODO: Execute MMI sound function in MMI task!
// TODO: MMI_VOLUME_LEVEL_ENUM GetRingVolumeLevel(void)


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_sound_play_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_sound_play_callback(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Note: It is invoked from MMI task and we should not do too many things here */

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_SOUND_PLAY_CALLBACK, (int)result, (int)WSND_CTX->current_sound);

    if (!WSND_CTX->current_sound)
    {
        return;
    }

    /* Widget will set the state after sound stopped by itself */
    if (WSND_CTX->to_stop_by_WAP)
    {
        return;
    }

    WAP_DBG_ASSERT(WSND_CTX->state >= WIDGET_SOUND_ACTIVE_BEGIN && WSND_CTX->state <= WIDGET_SOUND_ACTIVE_END);

    switch (result)
    {
        case MDI_AUDIO_SUCCESS:
            WAP_DBG_ASSERT(WSND_CTX->state == WIDGET_SOUND_CMD_PROCESSING);
            WSND_CTX->state = WIDGET_SOUND_PLAYING;
            break;

        case MDI_AUDIO_END_OF_FILE:
            WSND_CTX->state = WIDGET_SOUND_PLAY_FINISHED;
            break;

        case MDI_AUDIO_TERMINATED:
            /* Some interrupt screen like CM might terminate current sound before display new screen */
            WAP_DBG_ASSERT(!WSND_CTX->to_play_by_WAP);  /* This should not be terminated by another MsfSound */
            WAP_DBG_ASSERT(WGUI_CTX->is_widget_screen); /* Sound must be already stopped after leaving widget screen */
            WSND_CTX->state = WIDGET_SOUND_TERMINATED;
            break;
        case MDI_AUDIO_DRM_PROHIBIT:    /* go through directly */
        case MDI_AUDIO_DRM_TIMEOUT:     /* go through directly */
        default:
            WSND_CTX->state = WIDGET_SOUND_PLAY_FAILED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_sound_play_file
 * DESCRIPTION
 *  Play sound file
 * PARAMETERS
 *  file_name       [IN]         
 * RETURNS
 *  If the request is successfully submitted to Media task, return KAL_TRUE
 *****************************************************************************/
static mdi_result widget_MMI_sound_play_file_ret = -1;

void widget_MMI_sound_play_file(void *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mdi_audio_set_volume(MDI_VOLUME_MEDIA, WSND_CTX->volume);
    /* popup sound issue, stop to set volume before play sound file, set the volume at the time of play file by using mdi_audio_play_file_with_vol_path API */
    widget_MMI_sound_play_file_ret = mdi_audio_play_file_with_vol_path(file_name, DEVICE_AUDIO_PLAY_ONCE, NULL, widget_MMI_sound_play_callback, NULL, WSND_CTX->volume, MDI_DEVICE_SPEAKER2);
}


/*****************************************************************************
 * FUNCTION
 *  widget_play_sound_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  snd     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_play_sound_file(widget_sound_struct *snd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *file_name;
    kal_uint8 *full_name;
    mdi_result res;
    MMI_ALERT_TYPE alertType;
    void *temp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!snd->is_done)
    {
        if (WSND_CTX->wait_more_data == WIDGET_SOUND_WAIT_MORE_DATA)
        {
            WSND_CTX->wait_more_data = WIDGET_SOUND_WANT_TO_PLAY_WAITING_SOUND;
        }

        return KAL_FALSE;
    }

    if (widget_sound_length((MsfSoundHandle) snd) <= 0)
    {
        return KAL_FALSE;
    }

    file_name = widget_rawfile_getname(snd->rawfile_id);
    if (file_name == NULL)
    {
        return KAL_FALSE;
    }

    alertType = srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_ALERT_TYPE,&temp);

    if ((alertType != MMI_VIBRATION_AND_RING && alertType != MMI_VIBRATION_THEN_RING && alertType != MMI_RING) ||
        !(widget_check_no_call_or_wap_call()) ||
        srv_prof_is_profile_activated(SRV_PROF_MEETING_MODE) ||
        srv_prof_ret srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE))
    {
        /* If the profile setting is meeting or silent, we change the state and try to play it when profile setting changes */
        if (srv_prof_is_profile_activated(SRV_PROF_MEETING_MODE) || srv_prof_ret srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE))
        {
            WSND_CTX->state = WIDGET_SOUND_TERMINATED;
        }
        return KAL_FALSE;
    }

    full_name = HDI_FileNameTranslate(file_name);
    WSND_CTX->to_play_by_WAP = 1;
    widget_execute_MMI_p(widget_MMI_sound_play_file, (void*)full_name, KAL_TRUE);
    res = widget_MMI_sound_play_file_ret;
    widget_MMI_sound_play_file_ret = -1;
    WSND_CTX->to_play_by_WAP = 0;
    HDI_FileNameFree(full_name);

    if (res == MDI_AUDIO_SUCCESS)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PLAY_SOUND_FILE, snd);
        return KAL_TRUE;
    }
    else
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PLAY_SOUND_FILE_FAIL, snd);
        return KAL_FALSE;   /* temporarily or permanently failure */
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_stop_sound_file_if_present
 * DESCRIPTION
 *  Stop a playing widget sound (should be used inside of widget screen)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_stop_sound_file_if_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_stop_file();  /* Blocking operation */
}


/*****************************************************************************
 * FUNCTION
 *  widget_stop_sound_file_if_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_stop_sound_file_if_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WSND_CTX->state != WIDGET_SOUND_NONE && WSND_CTX->state != WIDGET_SOUND_PLAY_FAILED && 
        WSND_CTX->state != WIDGET_SOUND_PLAY_FINISHED && WSND_CTX->state != WIDGET_SOUND_TERMINATED)
    {
        WAP_DBG_ASSERT(WSND_CTX->current_sound);
        WAP_DBG_ASSERT(WGUI_CTX->is_widget_screen); /* Otherwise we might stop sound of other screens */

        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_STOP_SOUND_FILE_IF_PRESENT, WSND_CTX->state);
        WSND_CTX->to_stop_by_WAP = 1;
        widget_execute_MMI(widget_MMI_stop_sound_file_if_present, KAL_TRUE);

        WSND_CTX->to_stop_by_WAP = 0;

        return KAL_TRUE;
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_sound_pause_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_sound_pause_callback(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Note: It is invoked from MMI task and we should not do too many things here */

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_SOUND_PAUSE_CALLBACK, (int)result, (int)WSND_CTX->current_sound);

    if (!WSND_CTX->current_sound)
    {
        return;
    }

    /* Widget will set the state after sound stopped by itself */
    if (WSND_CTX->to_stop_by_WAP)
    {
        return;
    }

    switch (result)
    {
        case MDI_AUDIO_TERMINATED:
            /* Some interrupt screen like CM might terminate current sound before display new screen */
            WAP_DBG_ASSERT(!WSND_CTX->to_play_by_WAP);  /* This should not be terminated by another MsfSound */
            WAP_DBG_ASSERT(WGUI_CTX->is_widget_screen); /* Sound must be already stopped after leaving widget screen */
            WSND_CTX->state = WIDGET_SOUND_TERMINATED;
            break;
        case MDI_AUDIO_DRM_PROHIBIT:    /* go through directly */
        case MDI_AUDIO_DRM_TIMEOUT:     /* go through directly */
        default:
            WSND_CTX->state = WIDGET_SOUND_TERMINATED;
    }
}

/*****************************************************************************
 * FUNCTION
 *  widget_MMI_pause_sound_file_if_present
 * DESCRIPTION
 *  Pause a playing widget sound (should be used inside of widget screen)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_MMI_pause_sound_file_if_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_pause(widget_MMI_sound_pause_callback, NULL);  /* Blocking operation */
}


/*****************************************************************************
 * FUNCTION
 *  widget_pause_sound_file_if_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_pause_sound_file_if_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WSND_CTX->state >= WIDGET_SOUND_ACTIVE_BEGIN && WSND_CTX->state <= WIDGET_SOUND_ACTIVE_END)
    {
        WAP_DBG_ASSERT(WSND_CTX->current_sound);
        WAP_DBG_ASSERT(WGUI_CTX->is_widget_screen); /* Otherwise we might stop sound of other screens */

        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PAUSE_SOUND_FILE_IF_PRESENT, WSND_CTX->state);
        WSND_CTX->to_stop_by_WAP = 1;
        widget_execute_MMI(widget_MMI_pause_sound_file_if_present, KAL_TRUE);

        WSND_CTX->to_stop_by_WAP = 0;

        return KAL_TRUE;
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_resume_sound_file_if_present
 * DESCRIPTION
 *  resume sound file
 * PARAMETERS
 *  file_name       [IN]         
 * RETURNS
 *  If the request is successfully submitted to Media task, return KAL_TRUE
 *****************************************************************************/
static void widget_MMI_resume_sound_file_if_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_set_volume(MDI_VOLUME_MEDIA, WSND_CTX->volume);
    mdi_audio_resume(widget_MMI_sound_play_callback, NULL);  /* Blocking operation */
}


/*****************************************************************************
 * FUNCTION
 *  widget_resume_sound_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  snd     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_resume_sound_file(widget_sound_struct *snd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RESUME_SOUND_FILE, snd);

    if (!snd->is_done)
    {
        if (WSND_CTX->wait_more_data == WIDGET_SOUND_WAIT_MORE_DATA)
        {
            WSND_CTX->wait_more_data = WIDGET_SOUND_WANT_TO_PLAY_WAITING_SOUND;
        }

        return KAL_FALSE;
    }

    if (widget_sound_length((MsfSoundHandle) snd) <= 0)
    {
        return KAL_FALSE;
    }

    WSND_CTX->to_stop_by_WAP = 1;
    widget_execute_MMI(widget_MMI_resume_sound_file_if_present, KAL_TRUE);

    WSND_CTX->to_stop_by_WAP = 0;
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_sound_play_id
 * DESCRIPTION
 *  Play a sound when a window is displayed
 * PARAMETERS
 *  sound_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_sound_play_id(int sound_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mdi_audio_set_volume(MDI_VOLUME_MEDIA, WSND_CTX->volume);
    /* popup sound issue, stop to set volume before play sound file, set the volume at the time of play file by using mdi_audio_play_id_with_vol_path API */
    mdi_audio_play_id_with_vol_path((U16) sound_id, DEVICE_AUDIO_PLAY_ONCE, WSND_CTX->volume, MDI_DEVICE_SPEAKER2);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtSoundPlayOnWindow
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sound       [IN]        
 *  owner       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetExtSoundPlayOnWindow(MsfSoundHandle sound, MsfWindowHandle owner)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_sound_struct *snd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(WSND_CTX->current_sound == NULL);
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_SOUND_PLAY, (int)sound);

    if (sound == 0)
    {
        return 0;
    }

    if (owner && !IS_WINDOW_TYPE(owner))
    {
        owner = 0;
    }

    snd = _SND(sound);
    WAP_DBG_ASSERT(snd->is_done);

    if (snd->sound_id)
    {
        /* Ignore "owner" parameter */
        if (WGUI_CTX->is_widget_screen)
        {
            void *temp;
            MMI_ALERT_TYPE alertType;

            alertType = srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_ALERT_TYPE,&temp);
            if ((alertType == MMI_VIBRATION_AND_RING || alertType == MMI_VIBRATION_THEN_RING || alertType == MMI_RING)
                &&
                (widget_check_no_call_or_wap_call()) &&
                !srv_prof_is_profile_activated(SRV_PROF_MEETING_MODE) &&
                !srv_prof_ret srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE))
            {
                widget_execute_MMI_i(widget_MMI_sound_play_id, (int)(snd->sound_id), KAL_TRUE);
            }
        }
    }
    else    /* From file */
    {
        if (!owner || (WGUI_CTX->current_window == _WINDOW(owner)))
        {
            if (WGUI_CTX->is_widget_screen)
            {
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_SOUND_PLAY_IN_WIDGET_SCREEN, owner, WGUI_CTX->current_window);
                widget_stop_sound_file_if_present();
                WSND_CTX->current_sound = NULL;
                WSND_CTX->owner_window = NULL;
                WSND_CTX->state = WIDGET_SOUND_NONE;

                if (widget_play_sound_file(snd))
                {
                    WSND_CTX->current_sound = snd;
                    WSND_CTX->state = WIDGET_SOUND_CMD_PROCESSING;
                }
                else
                {
                    WSND_CTX->current_sound = snd;
                    if (WSND_CTX->state == WIDGET_SOUND_NONE)
                    {
                        /* if the state doesn't change, we set it to WIDGET_SOUND_PLAY_FAILED. */
                        WSND_CTX->state = WIDGET_SOUND_PLAY_FAILED;
                    }
                }
            }
            else
            {
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_SOUND_PLAY_IN_PENDING_FOR_PLAYING, owner, WGUI_CTX->current_window);
                /* There might be another sound playing */
                WAP_DBG_ASSERT(!(WSND_CTX->state >= WIDGET_SOUND_ACTIVE_BEGIN &&
                               WSND_CTX->state <= WIDGET_SOUND_ACTIVE_END));
                WSND_CTX->current_sound = snd;
                WSND_CTX->state = WIDGET_SOUND_PENDING_FOR_PLAYING;
            }
        }
        else
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_SOUND_PLAY_IN_PENDING_ON_DISPLAYED, owner, WGUI_CTX->current_window);
            WSND_CTX->current_sound = snd;
            WSND_CTX->state = WIDGET_SOUND_PENDING_ON_DISPLAYED;
            WSND_CTX->owner_window = _WINDOW(owner);
        }
    }

    return 1;

}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetSoundPlay
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sound       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetSoundPlay(MsfSoundHandle sound)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return HDIa_widgetExtSoundPlayOnWindow(sound, 0);
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_sound_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sound       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_sound_stop(void *sound)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_sound_struct *snd = (widget_sound_struct*) sound;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_SOUND_STOP, (int)sound);

    if (snd->sound_id)
    {
        /* gilbert */
        mdi_audio_stop_id(snd->sound_id);
    }
    else if (snd == WSND_CTX->current_sound)
    {
        widget_stop_sound_file_if_present();
        WSND_CTX->current_sound = NULL;
        WSND_CTX->owner_window = NULL;
        WSND_CTX->state = WIDGET_SOUND_NONE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetSoundStop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sound       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetSoundStop(MsfSoundHandle sound)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sound == 0)
    {
        return 0;
    }

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_SOUND_STOP, (int)sound);
    widget_execute_MMI_p(widget_MMI_sound_stop, (void*)sound, KAL_TRUE);
    return 1;
}

#endif /* WIDGET_SUPPORT_SOUND */
/*****************************************************************************
 * FUNCTION
 *  widget_MMI_sound_play_predefined
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sound       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_sound_play_predefined(int sound)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 sound_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* gilbert */
    switch ((MsfPredefinedSound) sound)
    {
        case MsfClick:
            return; /* We already play keypad sound in MMI */

        case MsfSound_1:    /* used for MMS incoming notification */
            if (!widget_check_is_in_call())
                /* Becuase message tone is long and interrupts previous sound, it should not be used here actually */
            {
                sound_id = SRV_PROF_TONE_MMS;
            }
            else
            {
                sound_id = SRV_PROF_TONE_SMS_INCALL;
            }
            break;
        default:
            sound_id = SRV_PROF_TONE_GENERAL_TONE;
            break;
    }

    /* mdi_audio_play_id() doesnot handle some properties of tones */
    /* mdi_audio_play_id(sound_id, DEVICE_AUDIO_PLAY_ONCE, NULL, NULL); */
    srv_prof_play_tone(sound_id, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetSoundPlayPredefined
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sound       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetSoundPlayPredefined(MsfPredefinedSound sound)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//widget_execute_MMI_i(widget_MMI_sound_play_predefined, (int)sound, KAL_TRUE);  //MAUI_03167113
    widget_execute_MMI_i(widget_MMI_sound_play_predefined, (int)sound, KAL_FALSE);
    return 1;
}
#ifdef WIDGET_SUPPORT_SOUND
/*****************************************************************************
 * Volume setting
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_set_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vol     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_set_volume(int vol)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // mdi_audio_set_volume(VOL_TYPE_MEDIA, (U8) vol);
    /*  Set the volume key effect on mdi task as well as profile's volume, 
    mdi_audio_set_volume is called from SetRingVolumeLevel() */
    srv_prof_set_current_profile_value(SRV_PROF_SETTINGS_RING_VOL_LEVEL,vol);
	
}


/*****************************************************************************
 * FUNCTION
 *  widget_press_inc_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_press_inc_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/* we are getting the value of volume from profile's volume every time before update volume
    because User can also change the volume by using HFP (speaker)and this directly put
    impact on profile's volume, so we sync the behaviour with HFP volume setting */    
    /* reset the widget volume value from the profile setting */
    
    
    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_RING_VOL_LEVEL,&WSND_CTX->volume);

    /*  Set the volume key effect on mdi task as well as profile's volume  */ 
    if (WSND_CTX->volume < (MAX_VOL_LEVEL-1))
    {
        widget_execute_MMI_i(widget_MMI_set_volume, (int)((++WSND_CTX->volume)), KAL_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_press_dec_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_press_dec_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

/* we are getting the value of volume from profile's volume every time before update volume
    because User can also change the volume by using HFP (speaker)and this directly put
    impact on profile's volume so we sync the behaviour with HFP volume setting */        
    /* reset the widget volume value from the profile setting */
    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_RING_VOL_LEVEL,&WSND_CTX->volume);

    
    /* Set the volume key effect on mdi task as well as profile's volume */
    if (WSND_CTX->volume > 0)
    {
        widget_execute_MMI_i(widget_MMI_set_volume, (int)((--WSND_CTX->volume)), KAL_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_setup_volume_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_setup_volume_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(widget_press_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(widget_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * Sound intialization/deinitialization
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  widget_sound_release
 * DESCRIPTION
 *  Used when HDIa_widgetRelease a MsfSound object
 * PARAMETERS
 *  snd     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_sound_release(widget_sound_struct *snd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Stop sound if it is active */
    if (snd == WSND_CTX->current_sound)
    {
        /* HDIa_widgetSoundStop should be used before releasing the sound object */
        widget_stop_sound_file_if_present();

        WSND_CTX->current_sound = NULL;
        WSND_CTX->owner_window = NULL;
        WSND_CTX->state = WIDGET_SOUND_NONE;
    }

    /* Remove internal sound storage */
    if (snd->rawfile_id > 0)
    {
        widget_rawfile_deregister(snd->rawfile_id);
    }
    snd->rawfile_id = 0;
}


/*****************************************************************************
 * FUNCTION
 *  widget_resume_pending_sound_if_present
 * DESCRIPTION
 *  When going back to widget screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_resume_pending_sound_if_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WSND_CTX->current_sound && WSND_CTX->state == WIDGET_SOUND_INTERRUPTED)
    {
        if (widget_resume_sound_file(WSND_CTX->current_sound))
        {
            WSND_CTX->state = WIDGET_SOUND_CMD_PROCESSING;
        }
        else
        {
            WSND_CTX->state = WIDGET_SOUND_INTERRUPTED;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_resume_pending_sound_on_displayed
 * DESCRIPTION
 *  When display an window
 * PARAMETERS
 *  wnd     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void widget_resume_pending_sound_on_displayed(widget_window_struct *wnd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RESUME_PENDING_SOUND_ON_DISPLAYED, WSND_CTX->current_sound, wnd, WSND_CTX->state, WSND_CTX->owner_window);
    if (wnd &&
        WSND_CTX->current_sound &&
        ((WSND_CTX->owner_window == wnd && WSND_CTX->state == WIDGET_SOUND_PENDING_ON_DISPLAYED) ||
         (WSND_CTX->state == WIDGET_SOUND_PENDING_FOR_PLAYING)))
    {
        if (widget_play_sound_file(WSND_CTX->current_sound))
        {
            WSND_CTX->owner_window = NULL;
            WSND_CTX->state = WIDGET_SOUND_CMD_PROCESSING;
        }
        else
        {
            WSND_CTX->state = WIDGET_SOUND_PENDING_ON_DISPLAYED;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_pause_sound_if_present
 * DESCRIPTION
 *  When widget screen is paused
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_pause_sound_if_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WSND_CTX->current_sound &&
        WSND_CTX->state >= WIDGET_SOUND_ACTIVE_BEGIN && WSND_CTX->state <= WIDGET_SOUND_ACTIVE_END)
    {
        widget_pause_sound_file_if_present();

        WSND_CTX->state = WIDGET_SOUND_INTERRUPTED;
    }
    else if (WSND_CTX->current_sound && WSND_CTX->state == WIDGET_SOUND_TERMINATED)
    {
        WSND_CTX->state = WIDGET_SOUND_INTERRUPTED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_stop_sound_if_present
 * DESCRIPTION
 *  When widget screen exits
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_stop_sound_if_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WSND_CTX->current_sound)
    {
        widget_stop_sound_file_if_present();
    }
    WSND_CTX->state = WIDGET_SOUND_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_is_sound_playing
 * DESCRIPTION
 *  An sound object was HDIa_widgetSoundPlay()-ed  but not HDIa_widgetSoundStop
 *  (However, the sound playing might be already finished or failed)
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_is_sound_playing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WSND_CTX->current_sound != NULL &&
        WSND_CTX->state >= WIDGET_SOUND_ACTIVE_BEGIN && WSND_CTX->state <= WIDGET_SOUND_ACTIVE_END)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtIsSoundPlaying
 * DESCRIPTION
 *  An sound object was HDIa_widgetSoundPlay()-ed  but not HDIa_widgetSoundStop
 *  (However, the sound playing might be already finished or failed)
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetExtIsSoundPlaying(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (widget_is_sound_playing() == KAL_TRUE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_init_sound
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_init_sound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Note that we do not reset g_widget_sound_cntxt because we want to keep the states
     * * after WAP is restarted.
     */
    if (WSND_CTX->volume == 0)  /* Initialized for the first time only */
    {
        WSND_CTX->volume = 5 + 1;
    }

    WSND_CTX->to_stop_by_WAP = 0;
    WSND_CTX->to_play_by_WAP = 0;
    WSND_CTX->wait_more_data = -1;
    WSND_CTX->waiting_sound = NULL;
    WSND_CTX->current_sound = NULL;
    WSND_CTX->owner_window = NULL;
    WSND_CTX->state = WIDGET_SOUND_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_deinit_sound
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_deinit_sound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // widget_stop_sound_file_if_present(); /*We should not invoke this on task deinit? */

    WSND_CTX->to_stop_by_WAP = 0;
    WSND_CTX->to_play_by_WAP = 0;
    WSND_CTX->wait_more_data = -1;
    WSND_CTX->waiting_sound = NULL;
    WSND_CTX->current_sound = NULL;
    WSND_CTX->owner_window = NULL;
    WSND_CTX->state = WIDGET_SOUND_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_check_play_waiting_sound
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_check_play_waiting_sound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WSND_CTX->wait_more_data == WIDGET_SOUND_WANT_TO_PLAY_WAITING_SOUND &&
        WSND_CTX->waiting_sound == WSND_CTX->current_sound)
    {
        HDIa_widgetSoundPlay((MsfSoundHandle)WSND_CTX->waiting_sound);
        WSND_CTX->wait_more_data = -1;
        WSND_CTX->waiting_sound = NULL;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_sound_get_duration
 * DESCRIPTION
 *  Get the audio duration information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_MMI_sound_get_duration(void *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 progress = 0;
    kal_uint8 *_cache = NULL;
    kal_uint8 *_file_buf = NULL;
    kal_uint8 *_proc_buf = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Need to build cache to get precise duration */
    if(mdi_audio_is_duration_need_build_cache(file_name))
    {
#ifdef WAP_USE_ASM
        _cache = widget_internal_mem_alloc(MSF_MODID_WIDGET, WIDGET_SOUND_CACHE_SIZE + WIDGET_SOUND_TEMP_SIZE + WIDGET_SOUND_TEMP_SIZE);
#else
        _cache = MSF_MEM_ALLOC(MSF_MODID_WIDGET, WIDGET_SOUND_CACHE_SIZE + WIDGET_SOUND_TEMP_SIZE + WIDGET_SOUND_TEMP_SIZE);
#endif
        if (_cache != NULL)
        {
            _file_buf = _cache + WIDGET_SOUND_CACHE_SIZE;
            _proc_buf = _file_buf + WIDGET_SOUND_TEMP_SIZE;

            if (aud_util_build_cache_start( file_name, 
                (void *)_cache, WIDGET_SOUND_CACHE_SIZE, 
                (void *)_file_buf, WIDGET_SOUND_TEMP_SIZE, 
                (void *)_proc_buf, WIDGET_SOUND_TEMP_SIZE))
            {
                while (progress != 100)
                {
                    if (aud_util_build_cache_process(&progress))
                    {
                       // Trace2(TRACE_GROUP_2, "[Widget] aud_util_build_cache_process = %d", progress);
                       WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_UTIL_BUILD_CACHE_PROCESS_WITH_ARG, progress);
                    }
                    else
                    {
                        /* process error */
                        //Trace2(TRACE_GROUP_2, "[Widget] aud_util_build_cache_process Error!");
                        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_UTIL_BUILD_CACHE_PROCESS_WITHOUT_ARG);
                        sound_duration = 0;
#ifdef WAP_USE_ASM
                        widget_internal_mem_free(MSF_MODID_WIDGET, _cache);
#else
                        MSF_MEM_FREE(MSF_MODID_WIDGET, _cache);
#endif
                        return;
                    }
                }
                sound_duration = aud_util_build_cache_get_duration();
                aud_util_build_cache_stop();
            }
#ifdef WAP_USE_ASM
            widget_internal_mem_free(MSF_MODID_WIDGET, _cache);
#else
            MSF_MEM_FREE(MSF_MODID_WIDGET, _cache);
#endif
        }
        else
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_SOUND_GET_DURATION_NO_BUFFER);
            /* Can't get buffer to calculate the precise duration time */
            mdi_audio_get_duration(file_name, &sound_duration);
        }
    }
    else
    {
        /* No need to build cache, get duration directly */
        mdi_audio_get_duration(file_name, &sound_duration);
    }

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_MMI_SOUND_GET_DURATION, (int)sound_duration);
}



/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtSoundGetDuration
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  int
 *****************************************************************************/
int HDIa_widgetExtSoundGetDuration(void* file_name, kal_uint32 *duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *fname = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sound_duration = 0;
    if (file_name != NULL)
    {
        fname = (char*)HDI_FileNameTranslate(file_name);
        widget_execute_MMI_p(widget_MMI_sound_get_duration, (void*)fname, KAL_TRUE);
        *duration = sound_duration;
        HDI_FileNameFree((kal_uint8*) fname);

        return 1;
    }
    return 0;
}

#endif /* WIDGET_SUPPORT_SOUND */
