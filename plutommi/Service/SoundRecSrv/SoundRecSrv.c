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
 *  SoundRecSrv.cpp
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

#include "mmi_rp_srv_soundrec_def.h"
#include "MMIDataType.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "FileMgrSrvGProt.h"
#include "SoundRecSrvGProt.h"
#include "mmi_frm_nvram_gprot.h"

//#undef __COSMOS_NO_USER_DRIVE__

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
static MMI_BOOL is_init = MMI_FALSE;
static U8 m_quality;
static U8 m_drive;

/***************************************************************************** 
 * Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  _srv_soundrec_init
 * DESCRIPTION
 *  This function is to init variables
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void _srv_soundrec_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SRV_SNDREC_STORAGE, &m_drive, DS_BYTE, &error);
    ReadValue(NVRAM_SRV_SNDREC_QUALITY, &m_quality, DS_BYTE, &error);

    if(m_drive == 0xFF)
    {
        /* For cosmos slim package, record to memory card only */
    #if ((defined(__COSMOS_MMI_PACKAGE__) && defined(__LOW_COST_SUPPORT_COMMON__) && !defined(__MMI_SOUNDREC_SLIM__)) \
        || (defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_SOUNDREC_SLIM__) && defined(__COSMOS_NO_USER_DRIVE__)))       
        m_drive = SRV_FMGR_CARD_DRV;
    #else
        m_drive = SRV_FMGR_PUBLIC_DRV;
    #endif
        WriteValue(NVRAM_SRV_SNDREC_STORAGE, &m_drive, DS_BYTE, &error);
    }

    if(m_quality == 0xFF)
    {
        m_quality = SRV_SOUNDREC_QUALITY_NORMAL;
        WriteValue(NVRAM_SRV_SNDREC_QUALITY, &m_quality, DS_BYTE, &error);
    }

    is_init = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_soundrec_set_quality
 * DESCRIPTION
 *  This function is to set record quality and save to NVRAM
 * PARAMETERS
 *  quality       : [IN] record quality
 * RETURNS
 *  void
 *****************************************************************************/
void srv_soundrec_set_quality(srv_soundrec_quality_enum quality)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m_quality = (U8)quality;
    WriteValue(NVRAM_SRV_SNDREC_QUALITY, &m_quality, DS_BYTE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  srv_soundrec_set_storage
 * DESCRIPTION
 *  This function is to set record drive and save to NVRAM
 * PARAMETERS
 *  drive       : [IN] record storage
 * RETURNS
 *  void
 *****************************************************************************/
void srv_soundrec_set_storage(U8 drive)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m_drive = drive;
    WriteValue(NVRAM_SRV_SNDREC_STORAGE, &m_drive, DS_BYTE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  srv_soundrec_get_quality
 * DESCRIPTION
 *  This function is to get record drive from NVRAM
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  Quality in srv_soundrec_quality_enum
 *****************************************************************************/
srv_soundrec_quality_enum srv_soundrec_get_quality(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!is_init)
    {
        _srv_soundrec_init();
    }

    return (srv_soundrec_quality_enum)m_quality;
}

/*****************************************************************************
 * FUNCTION
 *  srv_soundrec_get_mdi_quality
 * DESCRIPTION
 *  This function is to get record drive from NVRAM
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  Quality in srv_soundrec_quality_enum
 *****************************************************************************/
MDI_AUDIO_REC_QUALITY_ENUM srv_soundrec_get_mdi_quality(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!is_init)
    {
        _srv_soundrec_init();
    }

    if(SRV_SOUNDREC_QUALITY_HIGH == m_quality)
    {
        return MDI_AUDIO_REC_QUALITY_HIGH;
    }
    else
    {
        return MDI_AUDIO_REC_QUALITY_LOW;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_soundrec_get_storage
 * DESCRIPTION
 *  This function is to set record drive of sound recorder and save to NVRAM
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  Drive letter
 *****************************************************************************/
U8 srv_soundrec_get_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!is_init)
    {
        _srv_soundrec_init();
    }
        /* For cosmos slim package, record to memory card only */
#if ((defined(__COSMOS_MMI_PACKAGE__) && defined(__LOW_COST_SUPPORT_COMMON__) && !defined(__MMI_SOUNDREC_SLIM__)) \
    || (defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_SOUNDREC_SLIM__) && defined(__COSMOS_NO_USER_DRIVE__))) 
    return SRV_FMGR_CARD_DRV;
#else
    return m_drive;
#endif

}

#ifdef AUD_REC_ENABLE
#include "dcl.h"

/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURN VALUES
 *
 *****************************************************************************/
static void srv_soundrec_auto_record_start_evt_hdlr(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURN VALUES
 *
 *****************************************************************************/
static void srv_soundrec_auto_record_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    WCHAR filepath[50];

    RTC_CTRL_GET_TIME_T   rtc_time;
    DCL_HANDLE rtc_handler;
    kal_uint8 count;
    FS_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check if destination folder exists before record. */
    kal_wsprintf((WCHAR*) filepath, "%c%w", srv_soundrec_get_storage(), L":\\AutoVM\\");
    result = srv_fmgr_fs_create_folder((const WCHAR *)filepath);

    if(result != FS_NO_ERROR)
    {
        return;
    }

    /* Get full path */
    rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE); 
    DclRTC_Control(rtc_handler, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T *) &rtc_time);
    DclRTC_Close(rtc_handler);
    for (count = 0; count < 100; count++)
    {
        kal_wsprintf(
            filepath,
            "%c%w%02d%02d%02d%02d%02d%02d.vm",
            srv_soundrec_get_storage(),
            L":\\AutoVM\\",
            rtc_time.u1Mon,
            rtc_time.u1Day,
            rtc_time.u1Hour,
            rtc_time.u1Min,
            rtc_time.u1Sec,
            count);   

        /* Check if filename duplicate */
        handle = FS_Open(filepath, FS_READ_ONLY);
        if (handle >= FS_NO_ERROR)
        {
            FS_Close(handle);
            if(count == 99)
            {
                return;
            } 
        }
        else
        {
            break;
        }
    }

    /* start record */
    result = mdi_audio_start_record(
                filepath,
                MDI_FORMAT_GSM_EFR,                      //for em vm only 
                srv_soundrec_get_mdi_quality(),
                srv_soundrec_auto_record_start_evt_hdlr,
                NULL);

    if (result == MDI_AUDIO_SUCCESS)
    {
        /* set state to record */
    }
}

/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURN VALUES
 *
 *****************************************************************************/
static void srv_soundrec_auto_record_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_stop_record();
}

/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURN VALUES
 *
 *****************************************************************************/
static mmi_ret srv_soundrec_auto_record_cb(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evt_mdi_audio_speech_ind_struct *event = (mmi_evt_mdi_audio_speech_ind_struct*) param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event->status)
    {
        case MDI_AUDIO_SPH_POST_SPEECH_ON:
        case MDI_AUDIO_SPH_POST_VOIP_ENCODE_START:
        case MDI_AUDIO_SPH_PRE_VOIP_DECODE_START:
        {
            srv_soundrec_auto_record_start();
        }
            break;
        case MDI_AUDIO_SPH_PRE_SPEECH_OFF:
        case MDI_AUDIO_SPH_PRE_VOIP_ENCODE_STOP:
        case MDI_AUDIO_SPH_PRE_VOIP_DECODE_STOP:
            srv_soundrec_auto_record_stop();
            break;
        default:
            break;
    }
	return MMI_RET_OK; 
}

/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURN VALUES
 *
 *****************************************************************************/
void srv_soundrec_auto_record_set_status(MMI_BOOL is_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    // TODO: print a log here

    if (is_on)
    {
        mmi_frm_cb_reg_event(EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND, (mmi_proc_func) srv_soundrec_auto_record_cb, NULL);
    }
    else
    {
        mmi_frm_cb_dereg_event(EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND, (mmi_proc_func) srv_soundrec_auto_record_cb, NULL);
    }
}

#endif /* AUD_REC_ENABLE */

