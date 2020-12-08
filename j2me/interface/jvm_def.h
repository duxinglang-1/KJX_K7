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
 *
 *
 * Project:
 * --------
 *  MAUI
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
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef JAL_JVM_DEF_H
#define JAL_JVM_DEF_H

typedef enum
{
    JVM_FG_RUNNING_STATE = 100,
    JVM_FG_MMI_RUNNING_STATE=90,
    JVM_BG_RUNNING_STATE =  50,
    JVM_SHORT_EVENT_STATE = 70,
    JVM_LONG_EVENT_STATE = 20,
    JVM_PAUSED_STATE = 10,
    JVM_TERMINATING_STATE = 5,
    JVM_TERMINATE_STATE = 0
} jvm_state_enum;

typedef enum
{
    JAVA_MEDIA_STATE_NULL,          /* 0 */
    JAVA_MEDIA_STATE_OPENING,       /* 1 */
    JAVA_MEDIA_STATE_READY,         /* 2 */
    JAVA_MEDIA_STATE_PLAYING,       /* 3 */
    JAVA_MEDIA_STATE_RECORDING,     /* 4 */
    JAVA_MEDIA_STATE_PAUSED,        /* 5 */
    JAVA_MEDIA_STATE_STOPPED_PAUSED,/* 6 */
    JAVA_MEDIA_STATE_CONNECTING,    /* 7 */
    JAVA_MEDIA_STATE_CONNECTED,     /* 8 */
    JAVA_MEDIA_STATE_BUFFERING,     /* 9 */ 
    JAVA_MEDIA_STATE_PAUSED_BUFFERING, /* 10 */ 
    JAVA_MEDIA_STATE_SEEKING           /* 11 */
} java_media_state_enum;

/* Used to query supported content type */
typedef enum
{    
    MMA_MIDI_DECODE,    /* 0: midi playback */
    MMA_TONE_DECODE,    /* 1: tone playback */
    MMA_WAV_DECODE,     /* 2: wav playback */
    MMA_IMY_DECODE,     /* 3: imy playback */
    MMA_AMR_DECODE,     /* 4: amr playback */
    MMA_DAF_DECODE,     /* 5: mp3 playback */
    MMA_MUSICAM_DECODE, /* 6: mp2 playback */
    MMA_AAC_DECODE,     /* 7: aac playback */
    MMA_AU_DECODE,      /* 8: au playback */
    MMA_AWB_DECODE,     /* 9: awb playback */
    MMA_WMA_DECODE,     /* 10: wma playback */
    MMA_M4A_DECODE,     /* 11: m4a playback */
    MMA_AIFF_DECODE,    /* 12: aiff playback */
    MMA_3GP_DECODE,     /* 13: 3gp playback */ 
    MMA_MP4_DECODE,     /* 14: mp4 playback */ 
    MMA_AVI_DECODE,     /* 15: avi playback */
    MMA_GIF_DECODE,     /* 16: avi playback */
    MMA_WAV_ENCODE,     /* 17: wav recorder */
    MMA_AMR_ENCODE,     /* 18: amr recorder */ 
    MMA_AWB_ENCODE,     /* 19: awb recorder */  
    MMA_3GP_ENCODE,     /* 20: 3gp recorder */ 
    MMA_AVI_ENCODE,     /* 21: avi recorder */
    MMA_JPEG_ENCODE,    /* 22: camera */
    MMA_VIDEO_RTSP,     /* 23: rtsp streaming */
    MMA_VIDEO_PDL,      /* 24: video progressive download */
    MMA_RA_DECODE,      /* 25: ra, ram playback */
    MMA_RM_DECODE,      /* 26: rv, rmvb, rm playback */
    MMA_SUPPORT_TYPE_NUM   
} java_mma_support_type_enum;


#endif
