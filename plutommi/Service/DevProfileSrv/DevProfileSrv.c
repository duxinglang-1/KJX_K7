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
 *   DevProfileSrv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Device profile for MAUI SDK
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

#ifndef LOW_COST_SUPPORT
#include "mmi_features.h"
#include "verno.h"
#include "DevprofileGprot.h"
#include "MMIDataType.h"
#ifdef __J2ME__
#include "j2me_custom_option.h"
#endif

#include "Fontres.h"
#include "ScreenRotationGprot.h"
#include "Cbm_api.h"
#include "DtcntSrvGprot.h"
#include "BtcmSrvGprot.h"
#include "App_mem.h"
#include "gui_typedef.h"

typedef U16 (*dev_prof_value)(void);
typedef const CHAR* (*dev_prof_string)(void);

typedef struct
{
    srv_dev_profile_category_enum category;
    dev_prof_value func;
} dev_prof_value_struct;

typedef struct
{
    srv_dev_profile_category_enum category;
    dev_prof_string func;
} dev_prof_string_struct;

extern S32 UI_device_width;
extern S32 UI_device_height;
extern sLanguageDetails* gLanguageArray;
extern U16 gCurrLangIndex;
extern U16 gMaxDeployedLangs;



/*****************************************************************************
 * FUNCTION
 *  dev_profile_get_platform
 * DESCRIPTION
 *  To query the platform information.
 * PARAMETERS
 *  void
 * RETURNS
 *  The string.
 *****************************************************************************/
static const CHAR* dev_profile_get_platform(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return PLATFORM;
}



static const CHAR* dev_prof_get_verno_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return VERNO_STR;


}


static const CHAR* dev_prof_get_hw_ver_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return HW_VER_STR;
}


static const CHAR* dev_prof_get_build_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return BUILD_DATE_TIME_STR;
}


static const CHAR* dev_prof_get_build_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return BUILD_STR ;
}


static const CHAR* dev_prof_get_build_branch_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return BUILD_BRANCH_STR ;
}



/*****************************************************************************
 * FUNCTION
 *  dev_profile_get_hw_version
 * DESCRIPTION
 *  To query the hardware version information.
 * PARAMETERS
 *  void
 * RETURNS
 *  The string.
 *****************************************************************************/
static const CHAR* dev_profile_get_hw_version(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return HW_VER_STR;
}


/*****************************************************************************
 * FUNCTION
 *  dev_profile_get_hw_version
 * DESCRIPTION
 *  To query the hardware version information.
 * PARAMETERS
 *  void
 * RETURNS
 *  The string.
 *****************************************************************************/
const CHAR* dev_profile_get_mmi_base(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_BASE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_profile_get_mmi_version
 * DESCRIPTION
 *  To query the mmi version information.
 * PARAMETERS
 *  void
 * RETURNS
 *  The string.
 *****************************************************************************/
const CHAR* dev_profile_get_mmi_version(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_VERSION;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_keypad_support
 * DESCRIPTION
 *  To query if keypad is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_keypad_support(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if (defined(QWERTY_KEYPAD) || defined(NORMAL_KEYPAD) || defined(REDUCED_KEYPAD) || defined(EXTEND_QWERTY_KEYPAD))
        return MMI_TRUE;
    #else
        return MMI_FALSE;

    #endif
}


/*****************************************************************************
 * FUNCTION
 *  dev_profile_get_keypad_type
 * DESCRIPTION
 *  To query the keypad type.
 * PARAMETERS
 *  void
 * RETURNS
 *  dev_profile_result_enum
 *****************************************************************************/
static U16 dev_profile_get_keypad_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef QWERTY_KEYPAD
        return DEV_PROFILE_KEYPAD_QWERTY;
    #endif
    #ifdef NORMAL_KEYPAD
        return DEV_PROFILE_KEYPAD_NORMAL;
    #endif
    #ifdef REDUCED_KEYPAD
        return DEV_PROFILE_KEYPAD_REDUCED;
    #endif
    #ifdef EXTEND_QWERTY_KEYPAD
        return DEV_PROFILE_EXTEND_QWERTY_KEYPAD;
    #endif
    return DEV_PROFILE_KEYPAD_NONE;

}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_touch_support
 * DESCRIPTION
 *  To query if touch screen is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_touch_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_TOUCH_SCREEN__
        return MMI_TRUE;
    #else
        return MMI_FALSE;
    #endif   

}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_handwriting_support
 * DESCRIPTION
 *  To query if handwriting is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_handwriting_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if (defined(__MMI_HANWANG__) || defined(__MMI_PENPOWER__) || defined(__MMI_PENPOWER_DEMO__) || defined(__MMI_HANWANG_DEMO__) ||\
         defined(__MMI_DECUMA__))
        return MMI_TRUE;
    #endif   
        return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_mainlcd_width
 * DESCRIPTION
 *  To query the main LCD width.
 * PARAMETERS
 *  void
 * RETURNS
 *  the width of Main LCD
 *****************************************************************************/
static U16 dev_prof_mainlcd_width(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SCREEN_ROTATE__

    if((mmi_frm_get_screen_rotate() != MMI_FRM_SCREEN_ROTATE_0) &&
        (mmi_frm_get_screen_rotate() != MMI_FRM_SCREEN_ROTATE_180))
    {
        return UI_device_height;

    }
#endif
    return UI_device_width;
        
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_mainlcd_height
 * DESCRIPTION
 *  To query the main LCD height.
 * PARAMETERS
 *  void
 * RETURNS
 *  the height of Main LCD
 *****************************************************************************/
static U16 dev_prof_mainlcd_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SCREEN_ROTATE__

    if((mmi_frm_get_screen_rotate() != MMI_FRM_SCREEN_ROTATE_0) &&
    (mmi_frm_get_screen_rotate() != MMI_FRM_SCREEN_ROTATE_180))
    {
        return UI_device_width;

    }
#endif
    return UI_device_height;
        
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_landscape_support
 * DESCRIPTION
 *  To query if landscape is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_landscape_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_SCREEN_ROTATE__
    if((mmi_frm_get_screen_rotate() != MMI_FRM_SCREEN_ROTATE_0) &&
        (mmi_frm_get_screen_rotate() != MMI_FRM_SCREEN_ROTATE_180))
    {
        if (UI_device_width < UI_device_height)
        {
           return MMI_TRUE;
        }
        return MMI_FALSE;
    
    }
    #endif
    if (UI_device_width > UI_device_height)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_fte_support
 * DESCRIPTION
 *  To query if fte is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_fte_support(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}            


/*****************************************************************************
 * FUNCTION
 *  dev_prof_jogball_support
 * DESCRIPTION
 *  To query if jogball is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_jogball_support(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef JOGBALL_SUPPORT
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_sublcd_key_support
 * DESCRIPTION
 *  To query if sub LCD key is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_sublcd_key_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __SUBLCD_DEDICATED_KEYS_SUPPORT__
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_sublcd_width
 * DESCRIPTION
 *  To query the sub LCD width.
 * PARAMETERS
 *  void
 * RETURNS
 *  the width of sub LCD
 *****************************************************************************/
static U16 dev_prof_sublcd_width(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/            
#ifdef __MMI_SUBLCD__
    return SUB_LCD_device_width;
#endif
    return 0;

}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_sublcd_height
 * DESCRIPTION
 *  To query the sub LCD height.
 * PARAMETERS
 *  void
 * RETURNS
 *  the height of sub LCD
 *****************************************************************************/
static U16 dev_prof_sublcd_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
#ifdef __MMI_SUBLCD__
    return SUB_LCD_device_height;
#endif
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_screen_rotate_support
 * DESCRIPTION
 *  To query if screen rotate is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_screen_rotate_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
#ifdef __MMI_SCREEN_ROTATE__
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_landscape_support_on_portait_lcm
 * DESCRIPTION
 *  To query if landscape on portrait LCM is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_landscape_support_on_portait_lcm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
#ifdef __LANDSCAPE_UI_ON_PORTRAIT_LCM__
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_herizon_camera_support
 * DESCRIPTION
 *  To query if herizon camera is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_herizon_camera_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef HORIZONTAL_CAMERA
    return MMI_TRUE;
#endif
    return MMI_FALSE;    
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_sub_camera_support
 * DESCRIPTION
 *  To query if sub camera is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_sub_camera_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef CMOS_SENSOR_SUB
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_sub_camera_rotate_support
 * DESCRIPTION
 *  To query if sub camera rotate is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_sub_camera_rotate_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef SUB_SENSOR_ROTATE_180
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_webcamera_support
 * DESCRIPTION
 *  To query if web camera rotate is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_webcamera_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef WEBCAM_SUPPORT
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_camera_support
 * DESCRIPTION
 *  To query if camera is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_camera_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMERA__
    return MMI_TRUE;
#endif
    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_dual_camera_support
 * DESCRIPTION
 *  To query if dual camera is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_dual_camera_support(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DUAL_CAMERA_SUPPORT
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_fm_radio_support
 * DESCRIPTION
 *  To query if fm radio is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_fm_radio_support(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FM_RADIO__
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_fm_radio_record_support
 * DESCRIPTION
 *  To query if fm radio record is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_fm_radio_record_support(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FM_RADIO_RECORD__
    return MMI_TRUE;
#endif
    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_fm_radio_bind_earphone
 * DESCRIPTION
 *  To query if fm radio need to bind earphone.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_fm_radio_bind_earphone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
    return MMI_TRUE;
#endif
    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_camcorder_support
 * DESCRIPTION
 *  To query if camcorder is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_camcorder_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_CAMCORDER__
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_mediaplay_support
 * DESCRIPTION
 *  To query if media player is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_mediaplay_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_MEDIA_PLAYER__
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_kuro_support
 * DESCRIPTION
 *  To query if kuro is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_kuro_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_KURO_SUPPORT__
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_mediaplay_show_lyric
 * DESCRIPTION
 *  To query if mediaplayer shows lyric is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_mediaplay_show_lyric(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_MEDIA_PLAYER_LYRIC_DISPLAY__
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_audio_player_support
 * DESCRIPTION
 *  To query if audio player is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_audio_player_support(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_AUDIO_PLAYER__
    return MMI_TRUE;
#endif
    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_audio_player_show_lyric
 * DESCRIPTION
 *  To query if audio player shows lyric is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_audio_player_show_lyric(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_imageview_version
 * DESCRIPTION
 *  To query if image viewer is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_imageview_version(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_IMAGE_VIEWER_EX__
    return DEV_PROFILE_IMAGEVIEW_EX;
#endif

#ifdef __MMI_IMAGE_VIEWER__
    return DEV_PROFILE_IMAGEVIEW_STANDARD;
#endif
    return DEV_PROFILE_IMAGEVIEW_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_mediawall_support
 * DESCRIPTION
 *  To query if media wall is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_mediawall_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_VUI_MEDIAWALL__
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_photoeditor_support
 * DESCRIPTION
 *  To query if photo editor is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_photoeditor_support(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_PHOTOEDITOR__
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_video_player_support
 * DESCRIPTION
 *  To query if video player is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_video_player_support(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_VIDEO_PLAYER__
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_video_record_support
 * DESCRIPTION
 *  To query if video record is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_video_record_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_VIDEO_RECORDER__
    return MMI_TRUE;
#endif
    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_meidacache_support
 * DESCRIPTION
 *  To query if meida cache is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_meidacache_support(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_SRV_MEDIACACHE__
    return MMI_TRUE;
#endif
    return MMI_FALSE;

}



/*****************************************************************************
 * FUNCTION
 *  dev_prof_slideshow_support
 * DESCRIPTION
 *  To query if slide show is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_slideshow_support(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_SLIDESHOW__
    return MMI_TRUE;
#endif
    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_motion_sensor_support
 * DESCRIPTION
 *  To query if motion senser is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_motion_sensor_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef MOTION_SENSOR_SUPPORT
    return MMI_TRUE;
#endif
    return MMI_FALSE;

}



/*****************************************************************************
 * FUNCTION
 *  dev_prof_java_support
 * DESCRIPTION
 *  To query if java is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_java_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __J2ME__
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_mre_support
 * DESCRIPTION
 *  To query if mre is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_mre_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_mre_version
 * DESCRIPTION
 *  To query mre version.
 * PARAMETERS
 *  void
 * RETURNS
 *  dev_profile_result_enum
 *****************************************************************************/
static U16 dev_prof_mre_version(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if (MRE_VERSION == 1000)
        return DEV_PROFILE_MRE_VERSION_V30;
    #else
        return DEV_PROFILE_MRE_VERSION_V40;
    #endif

}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_mre_memory_provide
 * DESCRIPTION
 *  To query mre memory provided source.
 * PARAMETERS
 *  void
 * RETURNS
 *  dev_profile_result_enum
 *****************************************************************************/
static U16 dev_prof_mre_memory_provide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined(__MRE_MEDIA_BUF__)
        return DEV_PROFILE_MRE_MEMORY_PROVIDE_MED_BUFFER;
    #endif
    #if !defined(__MRE_MEDIA_BUF__)
        return DEV_PROFILE_MRE_MEMORY_PROVIDE_ASM;
    #endif
        return DEV_PROFILE_MRE_MEMORY_PROVIDE_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_mre_memory_size
 * DESCRIPTION
 *  To query mre memory size.
 * PARAMETERS
 *  void
 * RETURNS
 *  mre memory size
 *****************************************************************************/
static U16 dev_prof_mre_memory_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return  (U16) ((MRE_SYS_MEMORY_SIZE) << 10);
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_jpg_decode_type
 * DESCRIPTION
 *  To query jpg decode type.
 * PARAMETERS
 *  void
 * RETURNS
 *  dev_profile_result_enum
 *****************************************************************************/
static U16 dev_prof_jpg_decode_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(JPG_DECODE) && defined(__SW_JPEG_CODEC_SUPPORT__))
    return DEV_PROFILE_DECODE_SW;
#endif

#if (defined(JPG_DECODE) && !defined(__SW_JPEG_CODEC_SUPPORT__))
    return DEV_PROFILE_DECODE_HW;
#endif
    return DEV_PROFILE_DECODE_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_jpg_encode_type
 * DESCRIPTION
 *  To query jpg encode type.
 * PARAMETERS
 *  void
 * RETURNS
 *  dev_profile_result_enum
 *****************************************************************************/
static U16 dev_prof_jpg_encode_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(JPG_ENCODE) && defined(__SW_JPEG_CODEC_SUPPORT__))
    return DEV_PROFILE_ENCODE_SW;
#endif

#if (defined(JPG_ENCODE) && !defined(__SW_JPEG_CODEC_SUPPORT__))
    return DEV_PROFILE_ENCODE_HW;
#endif
    return DEV_PROFILE_ENCODE_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_gif_decode_type
 * DESCRIPTION
 *  To query gif decode type.
 * PARAMETERS
 *  void
 * RETURNS
 *  dev_profile_result_enum
 *****************************************************************************/
static U16 dev_prof_gif_decode_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(GIF_DECODE)
    return DEV_PROFILE_DECODE_HW;
#else
    return DEV_PROFILE_DECODE_SW;
#endif

}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_png_decode_type
 * DESCRIPTION
 *  To query png decode type.
 * PARAMETERS
 *  void
 * RETURNS
 *  dev_profile_result_enum
 *****************************************************************************/
static U16 dev_prof_png_decode_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(USE_SW_PNG_DECODER)
    return DEV_PROFILE_DECODE_SW;
#endif

#if defined(USE_HW_PNG_DECODER)
    return DEV_PROFILE_DECODE_HW;
#endif
    return DEV_PROFILE_DECODE_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_font_engine_type
 * DESCRIPTION
 *  To query font engine type.
 * PARAMETERS
 *  void
 * RETURNS
 *  dev_profile_result_enum
 *****************************************************************************/
static U16 dev_prof_font_engine_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_fe_is_vector_font_support())
    {
        return DEV_PROFILE_FONT_ENGINE_VECTOR;
    }
    else
    {
        return DEV_PROFILE_FONT_ENGINE_BITMAP;
    }
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_support_lanuage_num
 * DESCRIPTION
 *  To query support language number.
 * PARAMETERS
 *  void
 * RETURNS
 *  the language number.
 *****************************************************************************/
static U16 dev_prof_support_lanuage_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gMaxDeployedLangs;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_current_language
 * DESCRIPTION
 *  To query current language ssc string.
 * PARAMETERS
 *  void
 * RETURNS
 *  the current langugae ssc string.
 *****************************************************************************/
static const CHAR* dev_prof_current_language(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (CHAR* )(gLanguageArray[gCurrLangIndex].aLangSSC);
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_input_method
 * DESCRIPTION
 *  To query input method type.
 * PARAMETERS
 *  void
 * RETURNS
 *  dev_profile_result_enum
 *****************************************************************************/
static U16 dev_prof_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_ZI__
    return DEV_PROFILE_INPUT_METHOD_ZI;
#endif
#ifdef __MMI_T9__
    return DEV_PROFILE_INPUT_METHOD_T9;
#endif

#ifdef __MMI_CSTAR__
    return DEV_PROFILE_INPUT_METHOD_CSTAR;
#endif
    return DEV_PROFILE_INPUT_METHOD_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_gprs_support
 * DESCRIPTION
 *  To query if gprs is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_gprs_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_GPRS_FEATURES__
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_gprs_support
 * DESCRIPTION
 *  To query if gprs is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_tcpip_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __TCPIP__
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}



/*****************************************************************************
 * FUNCTION
 *  dev_prof_wifi_support
 * DESCRIPTION
 *  To query if wifi is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_wifi_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CUSTOM_WIFI_FEATURES_SWITCH__
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_bt_support
 * DESCRIPTION
 *  To query if Bluetooth is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_bt_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BT_SUPPORT__
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_gps_support
 * DESCRIPTION
 *  To query if gps is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_gps_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_GPS__
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}



/*****************************************************************************
 * FUNCTION
 *  dev_prof_agps_support
 * DESCRIPTION
 *  To query if agps is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_agps_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __AGPS_SUPPORT__
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_dual_sim_support
 * DESCRIPTION
 *  To query if dual sim is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_dual_sim_support(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    return MMI_TRUE;
#endif
    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_browser_type
 * DESCRIPTION
 *  To query browser type.
 * PARAMETERS
 *  void
 * RETURNS
 *  dev_profile_result_enum
 *****************************************************************************/
static U16  dev_prof_browser_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef OBIGO_Q03C_BROWSER
    return DEV_PROFILE_BROWSER_OBIGO_Q03C;
    #endif 
    #ifdef OBIGO_Q05A
    return DEV_PROFILE_BROWSER_OBIGO_Q05C;
    #endif
    #ifdef OPERA_BROWSER
    return DEV_PROFILE_BROWSER_OPERA;
    #endif
    return DEV_PROFILE_BROWSER_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_usb_support
 * DESCRIPTION
 *  To query if usb is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_usb_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_USB_SUPPORT__
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_mms_enable
 * DESCRIPTION
 *  To query if mms is enable.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_mms_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS__
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_email_enable
 * DESCRIPTION
 *  To query if email is enable.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_email_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL__
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_background_sms_enable
 * DESCRIPTION
 *  To query if background sms is enable.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_background_sms_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_BACKGROUND_SEND_SUPPORT__
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_unifined_message_enable
 * DESCRIPTION
 *  To query if background sms is enable.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_unifined_message_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UM_FOLDER__
    return MMI_TRUE;
#endif
    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_sms_phone_max_item
 * DESCRIPTION
 *  To query the number of sms stored in phone.
 * PARAMETERS
 *  void
 * RETURNS
 *  the max number of sms
 *****************************************************************************/
static U16 dev_prof_sms_phone_max_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return SMS_PHONE_ENTRY;

}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_sms_sim_max_item
 * DESCRIPTION
 *  To query the number of sms stored in sim.
 * PARAMETERS
 *  void
 * RETURNS
 *  the max number of sms
 *****************************************************************************/
static U16 dev_prof_sms_sim_max_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return SMS_SIM_ENTRY;

}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_phb_option_field_enable
 * DESCRIPTION
 *  To query if phonebook option field is enable.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_phb_option_field_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    return MMI_TRUE;
#endif
    return MMI_FALSE;   
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_phb_option_email_enable
 * DESCRIPTION
 *  To query if phonebook option email field is enable.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_phb_option_email_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_phb_birthday_field_enable
 * DESCRIPTION
 *  To query if phonebook option birthday field is enable.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_phb_birthday_field_enable(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_BIRTHDAY_FIELD__
    return MMI_TRUE;
#endif
    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_phb_info_field_enable
 * DESCRIPTION
 *  To query if phonebook option info field is enable.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_phb_info_field_enable(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_INFO_FIELD__
    return MMI_TRUE;
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_phb_phone_max_item
 * DESCRIPTION
 *  To query the number of phoonebook stored in phone.
 * PARAMETERS
 *  void
 * RETURNS
 *  the max number of phoonebook
 *****************************************************************************/
static U16 dev_prof_phb_phone_max_item(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MAX_PHB_PHONE_ENTRY;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_phb_sim_max_item
 * DESCRIPTION
 *  To query the number of phoonebook stored in sim.
 * PARAMETERS
 *  void
 * RETURNS
 *  the max number of phoonebook
 *****************************************************************************/
static U16 dev_prof_phb_sim_max_item(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MAX_PHB_SIM_ENTRY;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_ram_usage
 * DESCRIPTION
 *  the ram usage of screen based ASM, App based ASM and Med buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  the ram usage
 *****************************************************************************/
static U16 dev_prof_ram_usage(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 med_used, total;
    applib_asm_mem_detail_info_struct app_asm, scr_asm;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_asm_get_detail_info(&app_asm, MMI_FRM_MEM_APP_ASM);
    applib_mem_asm_get_detail_info(&scr_asm, MMI_FRM_MEM_SCR_ASM);
    med_used = med_ext_used_size();
    total = app_asm.total_used_size + scr_asm.total_used_size + med_used;
    return total;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_java_background_support
 * DESCRIPTION
 *  To query if java background run is enable.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_java_background_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef J2ME_SUPPORT_BACKGROUND
    return MMI_TRUE;
#endif
    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_network_intensity
 * DESCRIPTION
 *  To query network intensity.
 * PARAMETERS
 *  void
 * RETURNS
 *  Strength value ranges from 0 to 100.
 *****************************************************************************/
static U16 dev_prof_network_intensity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_nw_info_get_signal_strength_in_percentage(MMI_SIM1);
    
}



/*****************************************************************************
 * FUNCTION
 *  dev_prof_battery_intensity
 * DESCRIPTION
 *  To query battery intensity.
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 : please refer to battery_level_enum
 *****************************************************************************/
static U16 dev_prof_battery_intensity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   return srv_charbat_get_battery_level();

}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_mediaplay_status_on
 * DESCRIPTION
 *  To query if media player is on.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_mediaplay_status_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_MEDIA_PLAYER__
    return mmi_medply_is_play_activated();
    #endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_java_statues_on
 * DESCRIPTION
 *  To query if java is on.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_java_statues_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __J2ME__
    return jam_is_java_running();
    #endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_wifi_status_on
 * DESCRIPTION
 *  To query if wifi is on.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_wifi_status_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_DTCNT_WLAN_STATUS_INACTIVE == srv_dtcnt_wlan_status())
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  dev_prof_bt_status_on
 * DESCRIPTION
 *  To query if bt is on.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static U16 dev_prof_bt_status_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_BT_SUPPORT__
    if (SRV_BT_CM_POWER_ON == srv_bt_cm_get_power_status())
    {
        return MMI_TRUE;
    }
    #endif
    return MMI_FALSE;
}



static const  dev_prof_string_struct dev_prof_get_string_table[] =
{
    {dev_profile_platform, dev_profile_get_platform},
    {dev_profile_hw_version, dev_profile_get_hw_version},
    {dev_profile_mmi_base, dev_profile_get_mmi_base},
    {dev_profile_mmi_version, dev_profile_get_mmi_version},
    {dev_profile_current_language, dev_prof_current_language},
    {dev_profile_verno_string, dev_prof_get_verno_string},
    {dev_profile_hw_ver_string, dev_prof_get_hw_ver_string},
    {dev_profile_build_date_time, dev_prof_get_build_time},
    {dev_profile_build_string, dev_prof_get_build_string},
    {dev_profile_build_branch_string, dev_prof_get_build_branch_string},
};



static const  dev_prof_value_struct dev_prof_get_value_table[] =
{
    {dev_profile_keypad_support, dev_prof_keypad_support},
    {dev_profile_touch_support, dev_prof_touch_support},
    {dev_profile_handwriting_support, dev_prof_handwriting_support},
    {dev_profile_figer_touch_support, dev_prof_fte_support},
    {dev_profile_jogball_support, dev_prof_jogball_support},
    {dev_profile_sublcd_key_support,dev_prof_sublcd_key_support},
    {dev_profile_mainlcd_width,dev_prof_mainlcd_width},
    {dev_profile_mainlcd_height, dev_prof_mainlcd_height},
    {dev_profile_sublcd_width, dev_prof_sublcd_width},
    {dev_profile_sublcd_height, dev_prof_sublcd_height},
    {dev_profile_screen_rotate_support, dev_prof_screen_rotate_support},
    {dev_profile_landscape_support, dev_prof_landscape_support},
    {dev_profile_landscape_support_on_portait_lcm,dev_prof_landscape_support_on_portait_lcm},
    {dev_profile_heorizontal_camera_support, dev_prof_herizon_camera_support},
    {dev_profile_camera_support, dev_prof_camera_support},
    {dev_profile_sub_camera_support, dev_prof_sub_camera_support},
    {dev_profile_sub_camera_rotate_support, dev_prof_sub_camera_rotate_support},
    {dev_profile_webcamera_support, dev_prof_webcamera_support},
    {dev_profile_dual_camera_support, dev_prof_dual_camera_support},
    {dev_profile_fm_radio_enable, dev_prof_fm_radio_support},
    {dev_profile_fm_radio_record_support, dev_prof_fm_radio_record_support},
    {dev_profile_fm_radio_bind_earphone, dev_prof_fm_radio_bind_earphone},
    {dev_profile_camcorder_support, dev_prof_camcorder_support},
    {dev_profile_mediaplay_support, dev_prof_mediaplay_support},
    {dev_profile_mediaplay_is_playing, dev_prof_mediaplay_status_on},
    {dev_profile_kuro_support, dev_prof_kuro_support},
    {dev_profile_mediaplay_show_lyric, dev_prof_mediaplay_show_lyric},
    {dev_profile_audio_player_support, dev_prof_audio_player_support},
    {dev_profile_audio_player_show_lyric, dev_prof_audio_player_show_lyric},
    {dev_profile_mediawall_support, dev_prof_mediawall_support},
    {dev_profile_photoeditor_support, dev_prof_photoeditor_support},
    {dev_profile_video_player_support, dev_prof_video_player_support},
    {dev_profile_video_record_support, dev_prof_video_record_support},
    {dev_profile_meidacache_support, dev_prof_meidacache_support},
    {dev_profile_slideshow_support, dev_prof_slideshow_support},
    {dev_profile_motion_sensor_support, dev_prof_motion_sensor_support},
    {dev_profile_java_support, dev_prof_java_support},
    {dev_profile_java_background_support, dev_prof_java_background_support}, 
    {dev_profile_java_statues_on, dev_prof_java_statues_on}, 
    {dev_profile_mre_support, dev_prof_mre_support},
    {dev_profile_mre_memory_size, dev_prof_mre_memory_size},
    {dev_profile_support_lanuage_num, dev_prof_support_lanuage_num},
    {dev_profile_gprs_support, dev_prof_gprs_support},
    {dev_profile_tcpip_support, dev_prof_tcpip_support},
    {dev_profile_wifi_support, dev_prof_wifi_support},
    {dev_profile_wifi_status_is_on, dev_prof_wifi_status_on},
    {dev_profile_bt_support, dev_prof_bt_support},
    {dev_profile_bt_status_is_on, dev_prof_bt_status_on},
    {dev_profile_gps_support, dev_prof_gps_support},
    {dev_profile_agps_support, dev_prof_agps_support},
    {dev_profile_dual_sim_support,dev_prof_dual_sim_support},
    {dev_profile_network_intensity, dev_prof_network_intensity},
    {dev_profile_battery_intensity, dev_prof_battery_intensity},  
    {dev_profile_usb_support, dev_prof_usb_support},
    {dev_profile_mms_enable, dev_prof_mms_enable},
    {dev_profile_email_enable, dev_prof_email_enable},
    {dev_profile_background_sms_enable, dev_prof_background_sms_enable},
    {dev_profile_unifined_message_enable, dev_prof_unifined_message_enable},
    {dev_profile_sms_phone_max_item, dev_prof_sms_phone_max_item},
    {dev_profile_sms_sim_max_item, dev_prof_sms_sim_max_item},
    {dev_profile_phb_option_field_enable, dev_prof_phb_option_field_enable},
    {dev_profile_phb_option_email_enable, dev_prof_phb_option_email_enable},
    {dev_profile_phb_birthday_field_enable, dev_prof_phb_birthday_field_enable},
    {dev_profile_phb_info_field_enable, dev_prof_phb_info_field_enable},
    {dev_profile_phb_phone_max_item, dev_prof_phb_phone_max_item},
    {dev_profile_phb_sim_max_item, dev_prof_phb_sim_max_item},
    {dev_profile_ram_usage, dev_prof_ram_usage},
    {dev_profile_keypad_type, dev_profile_get_keypad_type},
    {dev_profile_imageview_version, dev_prof_imageview_version},
    {dev_profile_input_method, dev_prof_input_method},
    {dev_profile_browser_type, dev_prof_browser_type},
    {dev_profile_mre_version, dev_prof_mre_version},
    {dev_profile_mre_memory_provide, dev_prof_mre_memory_provide},
    {dev_profile_jpg_decode_type, dev_prof_jpg_decode_type},
    {dev_profile_jpg_encode_type, dev_prof_jpg_encode_type},
    {dev_profile_gif_decode_type, dev_prof_gif_decode_type},
    {dev_profile_png_decode_type, dev_prof_png_decode_type},
    {dev_profile_font_engine_type, dev_prof_font_engine_type},
 
};




/*****************************************************************************
 * FUNCTION
 *  srv_dev_profile_get_value_int
 * DESCRIPTION
 *  To query the feature. Return type is U16, it could be MMI_TRUE, MMI_FALSE, number or  dev_profile_result_enum. 
 *  Please refer to srv_dev_profile_category_enum. And get which feature you should call this function.
 * PARAMETERS
 *  category       : [IN] The query feature category.
 * RETURNS
 *  The string.
 *****************************************************************************/
U16 srv_dev_profile_get_value_int(srv_dev_profile_category_enum category)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    U32 num = sizeof(dev_prof_get_value_table)/sizeof(dev_prof_value_struct);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(index = 0; index < num; index++)
    {
        if (category == dev_prof_get_value_table[index].category)
        {
            return  (dev_prof_get_value_table[index].func)();
        }        
    }
    return 0xffff;
}



/*****************************************************************************
 * FUNCTION
 *  srv_dev_profile_get_value_string
 * DESCRIPTION
 *  To query the feature, and return type is CHAR*. Please refer to srv_dev_profile_category_enum
 *  And get which feature you should call this function.
 * PARAMETERS
 *  category       : [IN] The query feature category.
 * RETURNS
 *  The string.
 *****************************************************************************/
const CHAR* srv_dev_profile_get_value_string(srv_dev_profile_category_enum category)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    U32 num = sizeof(dev_prof_get_string_table)/sizeof(dev_prof_string_struct);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(index = 0; index < num; index++)
    {
        if (category == dev_prof_get_string_table[index].category)
        {
            return  (dev_prof_get_string_table[index].func)();
        }        
    }
    return " ";
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

#endif /* LOW_COST_SUPPORT */









