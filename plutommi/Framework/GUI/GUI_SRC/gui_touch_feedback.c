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
 *   gui_touch_feedback.c
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
#include "gui_touch_feedback.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

U32 g_touch_feedback_disable_tone_cnt = 0;
U32 g_touch_feedback_disable_vibrate_cnt = 0;

 /*****************************************************************************
 * FUNCTION
 *  gui_touch_feedback_play
 * DESCRIPTION
 *  Play tone and vibrate when response touch feedback
 * PARAMETERS
 *  component_enum     :[IN]    The component enum value
 * RETURNS
 *  void 
 *****************************************************************************/
void gui_touch_feedback_play(gui_touch_feedback_enum event_enum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_touch_feedback_play_oem(event_enum);
}


/*****************************************************************************
* FUNCTION
*  gui_touch_feedback_enable_tone
* DESCRIPTION
*  enable Play tone  when response touch feedback
* PARAMETERS
*  void
* RETURNS
*  void 
*****************************************************************************/
void gui_touch_feedback_enable_tone_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_touch_feedback_disable_tone_cnt > 0)
    {
        g_touch_feedback_disable_tone_cnt --;
    }
}


/*****************************************************************************
* FUNCTION
*  gui_touch_feedback_disable_tone
* DESCRIPTION
*  disable Play tone when response touch feedback
* PARAMETERS
*  void
* RETURNS
*  void 
*****************************************************************************/
void gui_touch_feedback_disable_tone_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_touch_feedback_disable_tone_cnt ++;
}


/*****************************************************************************
* FUNCTION
*  gui_touch_feedback_enable_vibrate
* DESCRIPTION
*  enable Play vibrate when response touch feedback
* PARAMETERS
*  void
* RETURNS
*  void 
*****************************************************************************/
void gui_touch_feedback_enable_vibrate_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_touch_feedback_disable_vibrate_cnt > 0)
    {
        g_touch_feedback_disable_vibrate_cnt --;
    }
}


/*****************************************************************************
* FUNCTION
*  gui_touch_feedback_disable_vibrate
* DESCRIPTION
*  disable Play vibrate when response touch feedback
* PARAMETERS
*  void
* RETURNS
*  void 
*****************************************************************************/
void gui_touch_feedback_disable_vibrate_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_touch_feedback_disable_vibrate_cnt ++;
}


/*****************************************************************************
* FUNCTION
*  gui_touch_feedback_get_tone_state
* DESCRIPTION
*  get the state of whether should play tone
* PARAMETERS
*  void
* RETURNS
*  MMI_BOOL 
*****************************************************************************/
MMI_BOOL gui_touch_feedback_get_tone_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_touch_feedback_disable_tone_cnt ||
        (!mdi_audio_is_resource_available(MDI_AUDIO_PLAY_STRING, NULL)))
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
* FUNCTION
*  gui_touch_feedback_get_vibrate_state
* DESCRIPTION
*   get the state of whether should play vibrate
* PARAMETERS
*  void
* RETURNS
*  MMI_BOOL 
*****************************************************************************/
MMI_BOOL gui_touch_feedback_get_vibrate_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_touch_feedback_disable_vibrate_cnt)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


