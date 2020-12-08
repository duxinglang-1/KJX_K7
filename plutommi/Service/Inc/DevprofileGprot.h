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
 *   DevProfileSrv.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef LOW_COST_SUPPORT


#include "MMIDatatype.h"


/* This enum is all the category of device profile. Pleaer refer to each item discription of the enum.
 * If you want to add item, please add the feature according to the following group. If it is a new group,
 * Please add the end of the enum.
 */
typedef enum
{
    /* platform related */

    /* This enum is used to get the chip platform, such as MT6236,
     * You should call srv_dev_profile_get_value_string to get this info.
     */
    dev_profile_platform = 0,

    /* This enum is used to get the hardware version, such as JADE36V2_DEMO_BB,
     * You should call srv_dev_profile_get_value_string to get this info.
     */
    dev_profile_hw_version,

    /* This enum is used to get mmi base, such as PLUTO_MMI or VENUS_MMI,
     * You should call srv_dev_profile_get_value_string to get this info.
     */
    dev_profile_mmi_base,

    /* This enum is used to get mmi package, such as PLUTO_MMI or COSMOS_MMI,
     * You should call srv_dev_profile_get_value_string to get this info.
     */
    dev_profile_mmi_version,
    
    /* This enum is used to get verno string, such as "MAUI.11B.W11.41",
     * You should call srv_dev_profile_get_value_string to get this info.
     */
    dev_profile_verno_string,

    /* This enum is used to get hardware verno string, such as "VICTOR56V10_DEMO_HW",
     * You should call srv_dev_profile_get_value_string to get this info.
     */
    dev_profile_hw_ver_string,

    /* This enum is used to get build date time, such as "2011/10/25 20:40",
     * You should call srv_dev_profile_get_value_string to get this info.
     */
    dev_profile_build_date_time,

    /* This enum is used to get build string, such as "BUILD_NO",
     * You should call srv_dev_profile_get_value_string to get this info.
     */
    dev_profile_build_string,

    /* This enum is used to get build branch string, such as "11B VICTOR56V10_DEMO",
     * You should call srv_dev_profile_get_value_string to get this info.
     */
    dev_profile_build_branch_string,

    /* input related */
    /* This enum is used to query if keypad is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_keypad_support = 50,

    /* This enum is used to query keypad type,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is dev_profile_result_enum.
     */
    dev_profile_keypad_type,

    /* This enum is used to query if touchscreen is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */    
    dev_profile_touch_support,

    /* This enum is used to query if handwriting is supported,
    * You should call srv_dev_profile_get_value_int to get this info
    * The return value is MMI_TRUE or MMI_FALSE.
    */    
    dev_profile_handwriting_support,

    /* This enum is used to query if finger touch is supported,
    * You should call srv_dev_profile_get_value_int to get this info
    * The return value is MMI_TRUE or MMI_FALSE.
    */    
    dev_profile_figer_touch_support,

    /* This enum is used to query if jogball is supported,
    * You should call srv_dev_profile_get_value_int to get this info
    * The return value is MMI_TRUE or MMI_FALSE.
    */    
    dev_profile_jogball_support,
    
    /* This enum is used to query if sub LCD key is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */    
    dev_profile_sublcd_key_support,

    /* LCD Information */

    /* This enum is used to query if main LCD width,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is U16, the width of LCD.
     */ 
    dev_profile_mainlcd_width = 100,

    /* This enum is used to query if main LCD height,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is U16, the height of LCD.
     */ 
    dev_profile_mainlcd_height,

    /* This enum is used to query if sub LCD width,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is U16, the width of LCD.
     */ 
    dev_profile_sublcd_width,

    /* This enum is used to query if sub LCD height,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is U16, the height of LCD.
     */ 
    dev_profile_sublcd_height,

    /* This enum is used to query if screen rotation is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_screen_rotate_support,

    /* This enum is used to query if landscape is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_landscape_support,

    /* This enum is used to query if landscape on poratrait LCM is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_landscape_support_on_portait_lcm,

    /* Multimedia feature - Camera */

    /* This enum is used to query if heorizontal camera is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_heorizontal_camera_support = 200,

    /* This enum is used to query if camera is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_camera_support,

    /* This enum is used to query if sub camera is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_sub_camera_support,

    /* This enum is used to query if sub camera rotate is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_sub_camera_rotate_support,

    /* This enum is used to query if web camera is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_webcamera_support,

    /* This enum is used to query if dual camera is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_dual_camera_support,
    
    /* Multimedia feature - FM Radio */

    /* This enum is used to query if FM Radio is enable,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_fm_radio_enable = 300,

    /* This enum is used to query if FM Radio Record is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_fm_radio_record_support,

    /* This enum is used to query if FM Radio is binded with earphone,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_fm_radio_bind_earphone,

    /* Multimedia feature - Camcorder */

    /* This enum is used to query if camcorder is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_camcorder_support = 400,
    
    /* Multimedia feature - Media player */

    /* This enum is used to query if media player is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_mediaplay_support  = 500,

    /* This enum is used to query if kuro is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_kuro_support,

    /* This enum is used to query if media player will show lyric,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_mediaplay_show_lyric,

    /* This enum is used to query if media player is playing,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_mediaplay_is_playing,

     /* Multimedia feature - audio player */

    /* This enum is used to query if audio player is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_audio_player_support = 600,

    /* This enum is used to query if audio player will show lyric,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_audio_player_show_lyric,
    
    /* Multimedia feature - imageviewer */

    /* This enum is used to query the image viewer version,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is dev_profile_result_enum.
     */
    dev_profile_imageview_version = 700,

    /* This enum is used to query if media wall is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_mediawall_support,

    /* This enum is used to query if photo editor is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_photoeditor_support,

    /* Multimedia feature - video player */

    /* This enum is used to query if video player is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_video_player_support = 800,

    /* This enum is used to query if video record is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_video_record_support,
    
    /* Multimedia feature - slide show */

    /* This enum is used to query if slide show is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_slideshow_support = 850,
    
    /* Multimedia feature - mediacache */

    /* This enum is used to query if meida cache is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_meidacache_support = 900,
    
    /* motion sensor */

    /* This enum is used to query if motion sensor is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_motion_sensor_support = 950,

    /* JAVA */

    /* This enum is used to query if java is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_java_support = 1000,

    /* This enum is used to query if java background is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_java_background_support,

    /* This enum is used to query if java is playing,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_java_statues_on,

    /* MRE */

    /* This enum is used to query if mre is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI_TRUE or MMI_FALSE.
     */
    dev_profile_mre_support = 1100,

    /* This enum is used to query mre version,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is dev_profile_result_enum.
     */
    dev_profile_mre_version,

    /* This enum is used to query who provide mre memory,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is dev_profile_result_enum.
     */
    dev_profile_mre_memory_provide,

    /* This enum is used to query mre memory size,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is the size of memory.
     */
    dev_profile_mre_memory_size,

    /* graphic related */

    /* This enum is used to query jpg decode type, software or hardware,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is dev_profile_result_enum.
     */
    dev_profile_jpg_decode_type = 1200,

    /* This enum is used to query jpg encode type, software or hardware,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is dev_profile_result_enum.
     */
    dev_profile_jpg_encode_type,

    /* This enum is used to query gif decode type, software or hardware,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is dev_profile_result_enum.
     */
    dev_profile_gif_decode_type,

    /* This enum is used to query png decode type, software or hardware,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is dev_profile_result_enum.
     */
    dev_profile_png_decode_type,

    /* font and lanuage */

    /* This enum is used to query font engine type, bitmap or vector,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is dev_profile_result_enum.
     */
    dev_profile_font_engine_type = 1300,

    /* This enum is used to query support language number,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is the number of the language.
     */
    dev_profile_support_lanuage_num,

    
    //dev_profile_support_lanuage,

    /* This enum is used to query current language SSC,
     * You should call srv_dev_profile_get_value_string to get this info
     * The return value is CHAR*.
     */
    dev_profile_current_language,

    /* This enum is used to query input method type,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is dev_profile_result_enum.
     */
    dev_profile_input_method,

    /* network and connect related */

    /* This enum is used to query if gprs is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI TRUE or MMI_FALSE.
     */
    dev_profile_gprs_support = 1500,

    /* This enum is used to query if tcpip is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI TRUE or MMI_FALSE.
     */
    dev_profile_tcpip_support,

    /* This enum is used to query if wifi is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI TRUE or MMI_FALSE.
     */
    dev_profile_wifi_support,

    /* This enum is used to query the wifi status, if it is on or off,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI TRUE or MMI_FALSE.
     */
    dev_profile_wifi_status_is_on,

    /* This enum is used to query if bluetooth is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI TRUE or MMI_FALSE.
     */
    dev_profile_bt_support,

    /* This enum is used to query the bluetooth status, if it is on or off,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI TRUE or MMI_FALSE.
     */
    dev_profile_bt_status_is_on,

    /* This enum is used to query if gps is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI TRUE or MMI_FALSE.
     */
    dev_profile_gps_support,

    /* This enum is used to query if agps is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI TRUE or MMI_FALSE.
     */
    dev_profile_agps_support,

    /* This enum is used to query if dual sim is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI TRUE or MMI_FALSE.
     */
    dev_profile_dual_sim_support,

    /* This enum is used to query the network intensity,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is in percentage from 0 to 100.
     */
    dev_profile_network_intensity,

    /* Browser */

    /* This enum is used to query browser type,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is dev_profile_result_enum.
     */
    dev_profile_browser_type = 1800,
    
    /* Battery */

    /* This enum is used to query the battery intensity,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value please refer battery_level_enum.
     */
    dev_profile_battery_intensity = 1900,

    /* USB */

    /* This enum is used to query if USB is supported,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI TRUE or MMI_FALSE.
     */
    dev_profile_usb_support = 2000,


    /* Message related */

    /* This enum is used to query if MMS is enable,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI TRUE or MMI_FALSE.
     */
    dev_profile_mms_enable = 2100,

    /* This enum is used to query if email is enable,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI TRUE or MMI_FALSE.
     */
    dev_profile_email_enable,

    /* This enum is used to query if background sms is enable,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI TRUE or MMI_FALSE.
     */
    dev_profile_background_sms_enable,

    /* This enum is used to query if unified message is enable,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI TRUE or MMI_FALSE.
     */
    dev_profile_unifined_message_enable,

    /* This enum is used to query sms phone max item,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is the max number stored in phone.
     */
    dev_profile_sms_phone_max_item,

    /* This enum is used to query sms sim max item,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is the max number stored in SIM.
     */
    dev_profile_sms_sim_max_item,

    /* phonebook */

    /* This enum is used to query if Phonebook option field is enable,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI TRUE or MMI_FALSE.
     */
    dev_profile_phb_option_field_enable = 2300,

    /* This enum is used to query if Phonebook option email field is enable,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI TRUE or MMI_FALSE.
     */
    dev_profile_phb_option_email_enable,

    /* This enum is used to query if Phonebook option birthday field is enable,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI TRUE or MMI_FALSE.
     */
    dev_profile_phb_birthday_field_enable,

    /* This enum is used to query if Phonebook info field is enable,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is MMI TRUE or MMI_FALSE.
     */
    dev_profile_phb_info_field_enable,

    /* This enum is used to query phooebook max item stored in phone,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is the max number stored in phone.
     */
    dev_profile_phb_phone_max_item,

    /* This enum is used to query phooebook max item stored in sim,
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is the max number stored in phone.
     */
    dev_profile_phb_sim_max_item,


    /* Memory */

    /* This enum is used to query ram usage of screen based ASM, App based ASM and MED buffer.
     * You should call srv_dev_profile_get_value_int to get this info
     * The return value is the total size of screen based ASM, App based ASM and MED bufer.
     */
    dev_profile_ram_usage = 2500,

    dev_profile_category_total
   
}srv_dev_profile_category_enum;



/* This enum is return value of srv_dev_profile_get_value_int. Please refer to srv_dev_profile_category_enum
 * to check which feature needs this enum.
 */
typedef enum
{

    /* Qwerty keypad type */
    DEV_PROFILE_KEYPAD_QWERTY = 2,
    /* Normal keypad type */
    DEV_PROFILE_KEYPAD_NORMAL,
    /* Reduced keypad type */
    DEV_PROFILE_KEYPAD_REDUCED,
    /* Extend qwerty keypad keypad type */
    DEV_PROFILE_EXTEND_QWERTY_KEYPAD,
    /* No keypad */
    DEV_PROFILE_KEYPAD_NONE,

    /* Image view extend version */
    DEV_PROFILE_IMAGEVIEW_EX = 20,
    /* Image view standard version */
    DEV_PROFILE_IMAGEVIEW_STANDARD,
    /* No image view */
    DEV_PROFILE_IMAGEVIEW_NONE,

    /* Input method T9 */
    DEV_PROFILE_INPUT_METHOD_T9 = 30,
    /* Input method ZI */
    DEV_PROFILE_INPUT_METHOD_ZI,
    /* Input method CTAR */
    DEV_PROFILE_INPUT_METHOD_CSTAR,
    /* No input method  */
    DEV_PROFILE_INPUT_METHOD_NONE,

    /* The Browser type is OBIGO_Q03C */
    DEV_PROFILE_BROWSER_OBIGO_Q03C = 50,
    /* The Browser type is OBIGO_Q05C */
    DEV_PROFILE_BROWSER_OBIGO_Q05C,
    /* The Browser type is OPERA */
    DEV_PROFILE_BROWSER_OPERA,
    /* No Browser */
    DEV_PROFILE_BROWSER_NONE,

    /* The MRE version is 3.0 */
    DEV_PROFILE_MRE_VERSION_V30 = 70,
     /* The MRE version is 4.0 */
    DEV_PROFILE_MRE_VERSION_V40,
     /* No MRE */
    DEV_PROFILE_MRE_VERSION_NONE,

    /* MRE Memory provided is Med Buffer */
    DEV_PROFILE_MRE_MEMORY_PROVIDE_MED_BUFFER = 90,
    /* MRE Memory provided is ASM */
    DEV_PROFILE_MRE_MEMORY_PROVIDE_ASM,
    /* No memory provide */
    DEV_PROFILE_MRE_MEMORY_PROVIDE_NONE,

    /* Software decode */
    DEV_PROFILE_DECODE_SW = 100,
    /* hardware decode */
    DEV_PROFILE_DECODE_HW,
    /* Software encode */
    DEV_PROFILE_ENCODE_SW,
    /* hardware encode */
    DEV_PROFILE_ENCODE_HW,
    /* No decode */
    DEV_PROFILE_ENCODE_NONE,
    /* No encode */
    DEV_PROFILE_DECODE_NONE,

    /* Font engine is Bitmap */
    DEV_PROFILE_FONT_ENGINE_BITMAP = 130,
    /* Font engine is vector */
    DEV_PROFILE_FONT_ENGINE_VECTOR,

    DEV_PROFILE_RESULT_TOTAL
} dev_profile_result_enum;



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
extern const CHAR* srv_dev_profile_get_value_string(srv_dev_profile_category_enum category);


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
extern U16 srv_dev_profile_get_value_int(srv_dev_profile_category_enum category);



#endif /* LOW_COST_SUPPORT */
































