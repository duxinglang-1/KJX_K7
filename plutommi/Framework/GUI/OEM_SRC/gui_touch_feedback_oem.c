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
 *   gui_touch_feedback_oem.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Adaptation layer touch feedback
 *
 *   
 *
 * Author:
 * -------
 * -------
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
#include "gui_typedef.h"
#include "gpiosrvgprot.h"
#include "mdi_audio.h"
#include "mmi_rp_app_uiframework_def.h"
#include "gui_touch_feedback_oem.h"
#include "wgui_categories_util.h"
#include "Resource_audio.h"


/***************************************************************************** 
* Define
*****************************************************************************/
#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__ 
/* under construction !*/
#if 0
#ifdef __MTK_TARGET__
/* under construction !*/
#endif
#endif
/* under construction !*/
#ifdef __MAUI_SOFTWARE_LA__
/* under construction !*/
#endif
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
#endif  /* __MMI_TOUCH_FEEDBACK_SUPPORT__  */
static U32 touch_feedback_used_audio_id = 0;

/***************************************************************************** 
* Local Function
*****************************************************************************/

/*****************************************************************************
* Global Function
*****************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if defined(MT6236)
#define GUI_TOUCH_FEEDBACK_MAX_SUPPORT_TONE  3
#else
#define GUI_TOUCH_FEEDBACK_MAX_SUPPORT_TONE  4
#endif

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
#endif


/*****************************************************************************
 * FUNCTION
 *  gui_touch_feedback_play_oem
 * DESCRIPTION
 *  Play tone and vibrate when response touch feedback
 * PARAMETERS
 *  component_enum     :[IN]    The component enum value
 * RETURNS
 *  void 
 *****************************************************************************/
static mdi_handle g_previous_audio_handler = -1;

static void gui_touch_feedback_audio_callback (kal_int32 handle, kal_int32 result, void* user_data)
{   
    static U32 index = 0;
    U32 old_index;
    static mdi_handle a_handle[4];
    srv_prof_volume_level audio_level;

    if (result == MDI_AUDIO_SUCCESS)
    {
        MMI_BOOL async = MMI_TRUE;

        a_handle[index] = handle;


        mdi_audio_mma_set_param(a_handle[index], MDI_MMA_PARAM_SET_ASYNC_MODE, (void*)&async);
        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_TOUCH_VOL, &audio_level);
        mdi_audio_set_volume(VOL_TYPE_MEDIA,audio_level);

#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("APL", SA_start);
#endif                                        
        mdi_audio_mma_play(a_handle[index]);

#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("APL", SA_stop);
#endif
        kal_prompt_trace(MOD_MMI, "[Touch Feedback] Audio play touch_feedback_used_audio_id: %d!", touch_feedback_used_audio_id);


        index ++;
        if (index >= GUI_TOUCH_FEEDBACK_MAX_SUPPORT_TONE)
    {
            index = 0;
        }
    }
    else if(result == MDI_AUDIO_OPEN_FILE_FAIL)
    {
        MMI_BOOL async = MMI_TRUE;
        g_previous_audio_handler = 0;
        old_index = (index - 1 + GUI_TOUCH_FEEDBACK_MAX_SUPPORT_TONE - 1) % GUI_TOUCH_FEEDBACK_MAX_SUPPORT_TONE;

        mdi_audio_mma_stop(a_handle[old_index]);
        mdi_audio_mma_set_param(a_handle[old_index], MDI_MMA_PARAM_SET_ASYNC_MODE, (void*)&async);
        mdi_audio_set_volume(VOL_TYPE_MEDIA,audio_level);
        mdi_audio_mma_play(a_handle[old_index]);
        kal_prompt_trace(MOD_MMI, "[Touch Feedback] Audio fail touch_feedback_used_audio_id: %d!", touch_feedback_used_audio_id);
    }

    else
    {
        kal_prompt_trace(MOD_MMI, "[Touch Feedback] audio close touch_feedback_used_audio_id: %d!", touch_feedback_used_audio_id);
//ktouch
    if (touch_feedback_used_audio_id != 1)
    {
        touch_feedback_used_audio_id --;
    }
        //ktouch
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("ACL", SA_start);
#endif                
    mdi_audio_mma_close(handle);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("ACL", SA_stop);
#endif       
    }
//    g_previous_audio_handler = -1;
}

#include "mmi_rp_srv_prof_def.h"
void gui_touch_feedback_play_oem(gui_touch_feedback_enum event_enum)
{
#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__    
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
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
#ifdef __MAUI_SOFTWARE_LA__
/* under construction !*/
#endif
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
#ifdef __MAUI_SOFTWARE_LA__
/* under construction !*/
#endif                                        
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MAUI_SOFTWARE_LA__
/* under construction !*/
#endif         
/* under construction !*/
#ifdef __MAUI_SOFTWARE_LA__
/* under construction !*/
#endif         
/* under construction !*/
#endif  /* __MMI_TOUCH_FEEDBACK_SUPPORT__ */    
}

