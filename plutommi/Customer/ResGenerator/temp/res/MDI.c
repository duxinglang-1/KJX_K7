/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   MDI.res
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 *   Stella Yang (mtk01564)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision: $
 * $Modtime: $
 * $Log: $
 *
 * 11 29 2012 stella.yang
 * [MAUI_03278557] Remove Redundant String
 * .
 *
 * 04 20 2012 kinse.lin
 * [MAUI_03172471] [Res] move timer id to res file
 * .
 *
 * 10 25 2011 kinse.lin
 * [MAUI_03054046] [Luffy76V22][Cosmos][D-Audio] Call voice will changed after switch SPK/Receiver
 * .
 *
 * 10 14 2011 stella.yang
 * [MAUI_03021627] [New Feature] Check in MBBMS 3.0
 * .
 *
 * 10 11 2011 kinse.lin
 * [MAUI_03024367] [Cosmos]Speaker tab can be switched, but no effect .
 * .
 *
 * 09 06 2011 stella.yang
 * [MAUI_03021627] [New Feature] Check in MBBMS 3.0
 * .
 *
 * 08 28 2011 kinse.lin
 * [MAUI_03010109] [Victor55V10][Cosmos][Sound setting] Ringtone preview no rsponding and pop out "Hardware busy"
 * .
 *
 * 07 14 2011 kinse.lin
 * [MAUI_02984077] [GainTable] merge mmi application related gain table modifiastions to A2SP and ABC branches
 * .
 *
 * 06 30 2011 kinse.lin
 * [MAUI_02969716] [Media player] play a video with no audio track , press back will popup a "error" message .
 * .
 *
 * 06 22 2011 stella.yang
 * [MAUI_02968211] [MATV]after interrput,recording stoped, the recording time still go on
 * .
 *
 * 06 07 2011 vovo.yang
 * [MAUI_02832291] Cosmos Development
 * fix .res syntax errors
 *
 * 06 07 2011 vovo.yang
 * [MAUI_02832291] Cosmos Development
 * fix .res syntax errors
 *
 * 05 25 2011 vincent.cho
 * [MAUI_02931574] [Slim] - Video recorder part.
 * .
 *
 * 05 18 2011 kinse.lin
 * [MAUI_02943509] [Slim] check in slim modification for Audio Related files
 * .
 *
 * 03 29 2011 stella.yang
 * [MAUI_02904204] Split CMMB and mATV
 * .
 *
 * 03 16 2011 stella.yang
 * [MAUI_02897316] [MTV] matv 11A code check in & sync with ASTRO branch.
 * .
 *
 * 03 04 2011 cathytr.huang
 * [MAUI_02888116] Phase out TVOUT
 * .
 *
 * 02 12 2011 stella.yang
 * [MAUI_02869600] Sync MBBMS to 11A. MAUI &  Add DDv2 Support
 * .
 *
 * 12 21 2010 cs.kuo
 * [MAUI_02851652] Update FMR antenna type in MDI
 * .
 *
 * 11 25 2010 stella.yang
 * [MAUI_02841093] [New Feature] MBBMS check in
 * .
 *
 * 11 23 2010 ham.wang
 * [MAUI_02641608] [Auto test][Camera]The Restore default does not work for storage set
 * .
 *
 * 10 28 2010 cs.kuo
 * [MAUI_02832609] Move SENDER and RECEIVER of Callback Manager to MDI resource folder
 * .
 *
 * 10 26 2010 cs.kuo
 * [MAUI_02831580] Move MDI folder from mtkapp to service
 * .
 *
 * Jun 17 2010 mtk80018
 * [MAUI_02211233] [Camera]fix motion mdi build error
 * 
 *
 * Mar 26 2010 mtk01564
 * [MAUI_02382557] [10A] MMI Resource
 * 
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "MMI_features.h" 
#include "custresdef.h"
<?xml version="1.0" encoding="UTF-8"?>

<APP id="SRV_MDI">   
    <INCLUDE file="mdi_resdef.h"/>

#if defined(__GPS_SUPPORT__)
    <CACHEDATA type="byte" id="NRRAM_GPS_LOGGING_SWITCH">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_GPS_PAYLOAD_STORAGE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> NVRAM_GPS_PAYLOAD_STORAGE </DESCRIPTION>
    </CACHEDATA>

#endif

<!----------------------------------------------------------------------------------------
******** String section 
------------------------------------------------------------------------------------------>

    <STRING id="STR_ID_MDI_COMMON_FAIL"/>
    <STRING id="STR_ID_MDI_COMMON_OPEN_FAIL"/>
    <STRING id="STR_ID_MDI_COMMON_PLAY_FAIL"/>
    <STRING id="STR_ID_MDI_COMMON_RECORD_FAIL"/>
    /*<STRING id="STR_ID_MDI_COMMON_DEVICE_BUSY"/>*/
    <STRING id="STR_ID_MDI_COMMON_WRITE_PROTECTION"/>
    <STRING id="STR_ID_MDI_COMMON_HW_NOT_READY"/>
    <STRING id="STR_ID_MDI_COMMON_INVALID_FILE"/>    
#ifndef __LOW_COST_SUPPORT_COMMON__
    <STRING id="STR_ID_MDI_AUDIO_UNSUPPORTED_SPEED"/>
#endif
    <STRING id="STR_ID_MDI_AUDIO_NO_AUD_TRACK"/>
    <STRING id="STR_ID_MDI_CAMERA_PREVIEW_FAILED"/>
    <STRING id="STR_ID_MDI_CAMERA_CAPTURE_FAILED"/>
    <STRING id="STR_ID_MDI_CAMERA_XENONFLASH_TIMEOUT"/>
    <STRING id="STR_ID_MDI_CAMERA_XENONFLASH_LOW_BATTERY"/>
    <STRING id="STR_ID_MDI_WEBCAM_USB_NOTIFY_ERROR"/>
#if defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__)
    <STRING id="STR_ID_MDI_VIDEO_REC_STORAGE_TOO_SLOW"/>
#endif
#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
    <STRING id="STR_ID_MDI_VIDEO_PLY_FILE_TOO_LARGE"/>
    <STRING id="STR_ID_MDI_VIDEO_PLY_SNAPSHOT_FAILED"/>
    /*<STRING id="STR_ID_MDI_VIDEO_PLY_PLAY_FAILED"/> */
    <STRING id="STR_ID_MDI_VIDEO_PLY_NETWORK_CONNECT_FAILED"/>
    <STRING id="STR_ID_MDI_VIDEO_PLY_INVALID_RESOULTION"/>
    <STRING id="STR_ID_MDI_VIDEO_PLY_NETWORK_BUFFER_FAILED"/>
#endif
#if defined(__MMI_ATV_SUPPORT__) || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    <STRING id="STR_ID_MDI_MTV_DEVICE_BUSY"/>
    <STRING id="STR_ID_MDI_MTV_STORAGE_IO_ERROR"/>
    <STRING id="STR_ID_MDI_MTV_VIDEO_ERROR"/>
    <STRING id="STR_ID_MDI_MTV_AUDIO_ERROR"/>
    <STRING id="STR_ID_MDI_MTV_STORAGE_NOT_READY"/>
    <STRING id="STR_ID_MDI_MTV_FAILED_TO_PAUSE"/>
    <STRING id="STR_ID_MDI_MTV_FAILED_TO_SET_SPEED"/>
    <STRING id="STR_ID_MDI_MTV_FAILED_TO_SNAPSHOT"/>
    <STRING id="STR_ID_MDI_MTV_OVER_LIMIT"/>
#endif /* __MMI_ATV_SUPPORT__ ||  __MMI_MOBILE_TV_CMMB_SUPPORT__ */
#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)       
    <STRING id="STR_ID_MDI_MTV_DEVICE_AUTHENTICATION_FAILED"/>      
    <STRING id="STR_ID_MDI_MTV_PURCHASE_ITEM_UNKNOWN"/>            
    <STRING id="STR_ID_MDI_MTV_SERVICE_ERROR"/>           
    <STRING id="STR_ID_MDI_MTV_MAL_FORMED_MESSAGE_ERROR"/>           
    <STRING id="STR_ID_MDI_MTV_NO_SUBSCRIPTION"/>            
    <STRING id="STR_ID_MDI_MTV_OPERATION_NOT_PERMITTED"/>            
    <STRING id="STR_ID_MDI_MTV_REQUESTED_SERVICE_UNAVAILABLE"/>            
    <STRING id="STR_ID_MDI_MTV_REQUESTED_SERVICE_ACCEPTED"/>           
    <STRING id="STR_ID_MDI_MTV_INVALID_REQUEST"/>            
    <STRING id="STR_ID_MDI_MTV_DELIVERY_OF_WRONG_KEY_INFORMATION"/>            
    <STRING id="STR_ID_MDI_MTV_ALREADY_IN_USE"/>            
    <STRING id="STR_ID_MDI_MTV_NO_MATCHING_FRAGMENT"/>            
    <STRING id="STR_ID_MDI_MTV_NOW_SUBSCRIBED"/>            
    <STRING id="STR_ID_MDI_MTV_INSUFFICIENT_CHARGE"/>
    <STRING id="STR_ID_MDI_MTV_INVALID_NW_PARAM"/>
    <STRING id="STR_ID_MDI_MTV_NW_TIMEOUT"/>
    <STRING id="STR_ID_MDI_MTV_FAIL_TO_SUBSCRIBE"/>
    <STRING id="STR_ID_MDI_MTV_FAIL_TO_UNSUBSCRIBE"/>
    <STRING id="STR_ID_MDI_MTV_FAIL_TO_RETRIEVE_AREA"/>
    <STRING id="STR_ID_MDI_MTV_FAIL_TO_ACCOUNT_INQUIRY"/>
    <STRING id="STR_ID_MDI_MTV_FAIL_TO_RETRIEVE_MSK"/>
    <STRING id="STR_ID_MDI_MTV_FAIL_TO_RETRIEVE_INTERACTIVITY"/>
#endif /* __MMI_MOBILE_TV_CMMB_SUPPORT__ */


#ifdef MOTION_SENSOR_SUPPORT
    <STRING id="STR_ID_MDI_MOTION_NO_SLOT"/>
    <STRING id="STR_ID_MDI_MOTION_CB_NOT_FOUND"/>
#endif
#if defined(__GPS_SUPPORT__) || defined(__BT_GPS_SUPPORT__)
    <STRING id="STR_ID_MDI_GPS_UART_ERR_PORT_ALREADY_OPEN"/>
    <STRING id="STR_ID_MDI_GPS_UART_ERR_PORT_NUMBER_WRONG"/>
    <STRING id="STR_ID_MDI_GPS_UART_ERR_PARAM_ERROR"/>
    <STRING id="STR_ID_MDI_GPS_UART_ERR_PORT_ALREADY_CLOSED"/>
    <STRING id="STR_ID_MDI_GPS_UART_ERR_PORT_ERR_UNKNOW"/>
    <STRING id="STR_ID_MDI_GPS_UART_ERR_PORT_ERR_NOT_OPEN"/>
    <STRING id="STR_ID_MDI_GPS_UART_ERR_NO_SLOT"/>
#endif

<!----------------------------------------------------------------------------------------
******** Audio section 
------------------------------------------------------------------------------------------>
#if defined(SIMPLE_TTS)
    <AUDIO id="AUD_ID_SIMPLE_TTS_1">CUST_ADO_PATH"\\\\SimpleTTS\\\\a1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_2">CUST_ADO_PATH"\\\\SimpleTTS\\\\a2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_3">CUST_ADO_PATH"\\\\SimpleTTS\\\\a5.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_4">CUST_ADO_PATH"\\\\SimpleTTS\\\\ai1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_5">CUST_ADO_PATH"\\\\SimpleTTS\\\\ai2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_6">CUST_ADO_PATH"\\\\SimpleTTS\\\\ai3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_7">CUST_ADO_PATH"\\\\SimpleTTS\\\\ai4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_8">CUST_ADO_PATH"\\\\SimpleTTS\\\\an1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_9">CUST_ADO_PATH"\\\\SimpleTTS\\\\an3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_10">CUST_ADO_PATH"\\\\SimpleTTS\\\\an4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_11">CUST_ADO_PATH"\\\\SimpleTTS\\\\ang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_12">CUST_ADO_PATH"\\\\SimpleTTS\\\\ang2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_13">CUST_ADO_PATH"\\\\SimpleTTS\\\\ang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_14">CUST_ADO_PATH"\\\\SimpleTTS\\\\ao1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_15">CUST_ADO_PATH"\\\\SimpleTTS\\\\ao2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_16">CUST_ADO_PATH"\\\\SimpleTTS\\\\ao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_17">CUST_ADO_PATH"\\\\SimpleTTS\\\\ao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_18">CUST_ADO_PATH"\\\\SimpleTTS\\\\ba1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_19">CUST_ADO_PATH"\\\\SimpleTTS\\\\ba2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_20">CUST_ADO_PATH"\\\\SimpleTTS\\\\ba3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_21">CUST_ADO_PATH"\\\\SimpleTTS\\\\ba4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_22">CUST_ADO_PATH"\\\\SimpleTTS\\\\bai1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_23">CUST_ADO_PATH"\\\\SimpleTTS\\\\bai2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_24">CUST_ADO_PATH"\\\\SimpleTTS\\\\bai3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_25">CUST_ADO_PATH"\\\\SimpleTTS\\\\bai4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_26">CUST_ADO_PATH"\\\\SimpleTTS\\\\ban1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_27">CUST_ADO_PATH"\\\\SimpleTTS\\\\ban3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_28">CUST_ADO_PATH"\\\\SimpleTTS\\\\ban4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_29">CUST_ADO_PATH"\\\\SimpleTTS\\\\bang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_30">CUST_ADO_PATH"\\\\SimpleTTS\\\\bang3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_31">CUST_ADO_PATH"\\\\SimpleTTS\\\\bang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_32">CUST_ADO_PATH"\\\\SimpleTTS\\\\bao1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_33">CUST_ADO_PATH"\\\\SimpleTTS\\\\bao2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_34">CUST_ADO_PATH"\\\\SimpleTTS\\\\bao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_35">CUST_ADO_PATH"\\\\SimpleTTS\\\\bao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_36">CUST_ADO_PATH"\\\\SimpleTTS\\\\bei1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_37">CUST_ADO_PATH"\\\\SimpleTTS\\\\bei3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_38">CUST_ADO_PATH"\\\\SimpleTTS\\\\bei4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_39">CUST_ADO_PATH"\\\\SimpleTTS\\\\bei5.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_40">CUST_ADO_PATH"\\\\SimpleTTS\\\\ben1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_41">CUST_ADO_PATH"\\\\SimpleTTS\\\\ben3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_42">CUST_ADO_PATH"\\\\SimpleTTS\\\\ben4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_43">CUST_ADO_PATH"\\\\SimpleTTS\\\\beng1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_44">CUST_ADO_PATH"\\\\SimpleTTS\\\\beng2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_45">CUST_ADO_PATH"\\\\SimpleTTS\\\\beng4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_46">CUST_ADO_PATH"\\\\SimpleTTS\\\\bi1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_47">CUST_ADO_PATH"\\\\SimpleTTS\\\\bi2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_48">CUST_ADO_PATH"\\\\SimpleTTS\\\\bi3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_49">CUST_ADO_PATH"\\\\SimpleTTS\\\\bi4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_50">CUST_ADO_PATH"\\\\SimpleTTS\\\\bian1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_51">CUST_ADO_PATH"\\\\SimpleTTS\\\\bian3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_52">CUST_ADO_PATH"\\\\SimpleTTS\\\\bian4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_53">CUST_ADO_PATH"\\\\SimpleTTS\\\\biao1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_54">CUST_ADO_PATH"\\\\SimpleTTS\\\\biao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_55">CUST_ADO_PATH"\\\\SimpleTTS\\\\biao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_56">CUST_ADO_PATH"\\\\SimpleTTS\\\\bie1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_57">CUST_ADO_PATH"\\\\SimpleTTS\\\\bie2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_58">CUST_ADO_PATH"\\\\SimpleTTS\\\\bie3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_59">CUST_ADO_PATH"\\\\SimpleTTS\\\\bie4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_60">CUST_ADO_PATH"\\\\SimpleTTS\\\\bin1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_61">CUST_ADO_PATH"\\\\SimpleTTS\\\\bin4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_62">CUST_ADO_PATH"\\\\SimpleTTS\\\\bing1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_63">CUST_ADO_PATH"\\\\SimpleTTS\\\\bing3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_64">CUST_ADO_PATH"\\\\SimpleTTS\\\\bing4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_65">CUST_ADO_PATH"\\\\SimpleTTS\\\\bing5.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_66">CUST_ADO_PATH"\\\\SimpleTTS\\\\bo1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_67">CUST_ADO_PATH"\\\\SimpleTTS\\\\bo2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_68">CUST_ADO_PATH"\\\\SimpleTTS\\\\bo3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_69">CUST_ADO_PATH"\\\\SimpleTTS\\\\bo4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_70">CUST_ADO_PATH"\\\\SimpleTTS\\\\bo5.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_71">CUST_ADO_PATH"\\\\SimpleTTS\\\\bu1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_72">CUST_ADO_PATH"\\\\SimpleTTS\\\\bu2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_73">CUST_ADO_PATH"\\\\SimpleTTS\\\\bu3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_74">CUST_ADO_PATH"\\\\SimpleTTS\\\\bu4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_75">CUST_ADO_PATH"\\\\SimpleTTS\\\\ca1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_76">CUST_ADO_PATH"\\\\SimpleTTS\\\\ca3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_77">CUST_ADO_PATH"\\\\SimpleTTS\\\\cai1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_78">CUST_ADO_PATH"\\\\SimpleTTS\\\\cai2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_79">CUST_ADO_PATH"\\\\SimpleTTS\\\\cai3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_80">CUST_ADO_PATH"\\\\SimpleTTS\\\\cai4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_81">CUST_ADO_PATH"\\\\SimpleTTS\\\\can1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_82">CUST_ADO_PATH"\\\\SimpleTTS\\\\can2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_83">CUST_ADO_PATH"\\\\SimpleTTS\\\\can3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_84">CUST_ADO_PATH"\\\\SimpleTTS\\\\can4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_85">CUST_ADO_PATH"\\\\SimpleTTS\\\\cang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_86">CUST_ADO_PATH"\\\\SimpleTTS\\\\cang2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_87">CUST_ADO_PATH"\\\\SimpleTTS\\\\cao1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_88">CUST_ADO_PATH"\\\\SimpleTTS\\\\cao2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_89">CUST_ADO_PATH"\\\\SimpleTTS\\\\cao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_90">CUST_ADO_PATH"\\\\SimpleTTS\\\\cao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_91">CUST_ADO_PATH"\\\\SimpleTTS\\\\ce4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_92">CUST_ADO_PATH"\\\\SimpleTTS\\\\cen2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_93">CUST_ADO_PATH"\\\\SimpleTTS\\\\ceng1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_94">CUST_ADO_PATH"\\\\SimpleTTS\\\\ceng2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_95">CUST_ADO_PATH"\\\\SimpleTTS\\\\ceng4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_96">CUST_ADO_PATH"\\\\SimpleTTS\\\\cha1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_97">CUST_ADO_PATH"\\\\SimpleTTS\\\\cha2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_98">CUST_ADO_PATH"\\\\SimpleTTS\\\\cha3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_99">CUST_ADO_PATH"\\\\SimpleTTS\\\\cha4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_100">CUST_ADO_PATH"\\\\SimpleTTS\\\\chai1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_101">CUST_ADO_PATH"\\\\SimpleTTS\\\\chai2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_102">CUST_ADO_PATH"\\\\SimpleTTS\\\\chai4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_103">CUST_ADO_PATH"\\\\SimpleTTS\\\\chan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_104">CUST_ADO_PATH"\\\\SimpleTTS\\\\chan2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_105">CUST_ADO_PATH"\\\\SimpleTTS\\\\chan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_106">CUST_ADO_PATH"\\\\SimpleTTS\\\\chan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_107">CUST_ADO_PATH"\\\\SimpleTTS\\\\chang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_108">CUST_ADO_PATH"\\\\SimpleTTS\\\\chang2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_109">CUST_ADO_PATH"\\\\SimpleTTS\\\\chang3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_110">CUST_ADO_PATH"\\\\SimpleTTS\\\\chang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_111">CUST_ADO_PATH"\\\\SimpleTTS\\\\chao1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_112">CUST_ADO_PATH"\\\\SimpleTTS\\\\chao2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_113">CUST_ADO_PATH"\\\\SimpleTTS\\\\chao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_114">CUST_ADO_PATH"\\\\SimpleTTS\\\\chao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_115">CUST_ADO_PATH"\\\\SimpleTTS\\\\che1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_116">CUST_ADO_PATH"\\\\SimpleTTS\\\\che3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_117">CUST_ADO_PATH"\\\\SimpleTTS\\\\che4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_118">CUST_ADO_PATH"\\\\SimpleTTS\\\\chen1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_119">CUST_ADO_PATH"\\\\SimpleTTS\\\\chen2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_120">CUST_ADO_PATH"\\\\SimpleTTS\\\\chen3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_121">CUST_ADO_PATH"\\\\SimpleTTS\\\\chen4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_122">CUST_ADO_PATH"\\\\SimpleTTS\\\\chen5.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_123">CUST_ADO_PATH"\\\\SimpleTTS\\\\cheng1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_124">CUST_ADO_PATH"\\\\SimpleTTS\\\\cheng2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_125">CUST_ADO_PATH"\\\\SimpleTTS\\\\cheng3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_126">CUST_ADO_PATH"\\\\SimpleTTS\\\\cheng4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_127">CUST_ADO_PATH"\\\\SimpleTTS\\\\chi1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_128">CUST_ADO_PATH"\\\\SimpleTTS\\\\chi2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_129">CUST_ADO_PATH"\\\\SimpleTTS\\\\chi3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_130">CUST_ADO_PATH"\\\\SimpleTTS\\\\chi4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_131">CUST_ADO_PATH"\\\\SimpleTTS\\\\chong1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_132">CUST_ADO_PATH"\\\\SimpleTTS\\\\chong2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_133">CUST_ADO_PATH"\\\\SimpleTTS\\\\chong3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_134">CUST_ADO_PATH"\\\\SimpleTTS\\\\chong4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_135">CUST_ADO_PATH"\\\\SimpleTTS\\\\chou1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_136">CUST_ADO_PATH"\\\\SimpleTTS\\\\chou2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_137">CUST_ADO_PATH"\\\\SimpleTTS\\\\chou3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_138">CUST_ADO_PATH"\\\\SimpleTTS\\\\chou4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_139">CUST_ADO_PATH"\\\\SimpleTTS\\\\chu1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_140">CUST_ADO_PATH"\\\\SimpleTTS\\\\chu2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_141">CUST_ADO_PATH"\\\\SimpleTTS\\\\chu3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_142">CUST_ADO_PATH"\\\\SimpleTTS\\\\chu4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_143">CUST_ADO_PATH"\\\\SimpleTTS\\\\chuai1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_144">CUST_ADO_PATH"\\\\SimpleTTS\\\\chuai3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_145">CUST_ADO_PATH"\\\\SimpleTTS\\\\chuai4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_146">CUST_ADO_PATH"\\\\SimpleTTS\\\\chuan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_147">CUST_ADO_PATH"\\\\SimpleTTS\\\\chuan2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_148">CUST_ADO_PATH"\\\\SimpleTTS\\\\chuan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_149">CUST_ADO_PATH"\\\\SimpleTTS\\\\chuan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_150">CUST_ADO_PATH"\\\\SimpleTTS\\\\chuang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_151">CUST_ADO_PATH"\\\\SimpleTTS\\\\chuang2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_152">CUST_ADO_PATH"\\\\SimpleTTS\\\\chuang3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_153">CUST_ADO_PATH"\\\\SimpleTTS\\\\chuang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_154">CUST_ADO_PATH"\\\\SimpleTTS\\\\chui1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_155">CUST_ADO_PATH"\\\\SimpleTTS\\\\chui2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_156">CUST_ADO_PATH"\\\\SimpleTTS\\\\chun1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_157">CUST_ADO_PATH"\\\\SimpleTTS\\\\chun2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_158">CUST_ADO_PATH"\\\\SimpleTTS\\\\chun3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_159">CUST_ADO_PATH"\\\\SimpleTTS\\\\chuo1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_160">CUST_ADO_PATH"\\\\SimpleTTS\\\\chuo4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_161">CUST_ADO_PATH"\\\\SimpleTTS\\\\ci1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_162">CUST_ADO_PATH"\\\\SimpleTTS\\\\ci2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_163">CUST_ADO_PATH"\\\\SimpleTTS\\\\ci3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_164">CUST_ADO_PATH"\\\\SimpleTTS\\\\ci4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_165">CUST_ADO_PATH"\\\\SimpleTTS\\\\cong1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_166">CUST_ADO_PATH"\\\\SimpleTTS\\\\cong2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_167">CUST_ADO_PATH"\\\\SimpleTTS\\\\cou4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_168">CUST_ADO_PATH"\\\\SimpleTTS\\\\cu1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_169">CUST_ADO_PATH"\\\\SimpleTTS\\\\cu2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_170">CUST_ADO_PATH"\\\\SimpleTTS\\\\cu4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_171">CUST_ADO_PATH"\\\\SimpleTTS\\\\cuan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_172">CUST_ADO_PATH"\\\\SimpleTTS\\\\cuan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_173">CUST_ADO_PATH"\\\\SimpleTTS\\\\cui1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_174">CUST_ADO_PATH"\\\\SimpleTTS\\\\cui3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_175">CUST_ADO_PATH"\\\\SimpleTTS\\\\cui4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_176">CUST_ADO_PATH"\\\\SimpleTTS\\\\cun1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_177">CUST_ADO_PATH"\\\\SimpleTTS\\\\cun2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_178">CUST_ADO_PATH"\\\\SimpleTTS\\\\cun3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_179">CUST_ADO_PATH"\\\\SimpleTTS\\\\cun4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_180">CUST_ADO_PATH"\\\\SimpleTTS\\\\cuo1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_181">CUST_ADO_PATH"\\\\SimpleTTS\\\\cuo2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_182">CUST_ADO_PATH"\\\\SimpleTTS\\\\cuo3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_183">CUST_ADO_PATH"\\\\SimpleTTS\\\\cuo4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_184">CUST_ADO_PATH"\\\\SimpleTTS\\\\da1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_185">CUST_ADO_PATH"\\\\SimpleTTS\\\\da2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_186">CUST_ADO_PATH"\\\\SimpleTTS\\\\da3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_187">CUST_ADO_PATH"\\\\SimpleTTS\\\\da4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_188">CUST_ADO_PATH"\\\\SimpleTTS\\\\dai1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_189">CUST_ADO_PATH"\\\\SimpleTTS\\\\dai3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_190">CUST_ADO_PATH"\\\\SimpleTTS\\\\dai4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_191">CUST_ADO_PATH"\\\\SimpleTTS\\\\dan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_192">CUST_ADO_PATH"\\\\SimpleTTS\\\\dan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_193">CUST_ADO_PATH"\\\\SimpleTTS\\\\dan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_194">CUST_ADO_PATH"\\\\SimpleTTS\\\\dang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_195">CUST_ADO_PATH"\\\\SimpleTTS\\\\dang3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_196">CUST_ADO_PATH"\\\\SimpleTTS\\\\dang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_197">CUST_ADO_PATH"\\\\SimpleTTS\\\\dao1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_198">CUST_ADO_PATH"\\\\SimpleTTS\\\\dao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_199">CUST_ADO_PATH"\\\\SimpleTTS\\\\dao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_200">CUST_ADO_PATH"\\\\SimpleTTS\\\\de2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_201">CUST_ADO_PATH"\\\\SimpleTTS\\\\de5.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_202">CUST_ADO_PATH"\\\\SimpleTTS\\\\deng1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_203">CUST_ADO_PATH"\\\\SimpleTTS\\\\deng3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_204">CUST_ADO_PATH"\\\\SimpleTTS\\\\deng4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_205">CUST_ADO_PATH"\\\\SimpleTTS\\\\di1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_206">CUST_ADO_PATH"\\\\SimpleTTS\\\\di2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_207">CUST_ADO_PATH"\\\\SimpleTTS\\\\di3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_208">CUST_ADO_PATH"\\\\SimpleTTS\\\\di4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_209">CUST_ADO_PATH"\\\\SimpleTTS\\\\dia3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_210">CUST_ADO_PATH"\\\\SimpleTTS\\\\dian1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_211">CUST_ADO_PATH"\\\\SimpleTTS\\\\dian3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_212">CUST_ADO_PATH"\\\\SimpleTTS\\\\dian4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_213">CUST_ADO_PATH"\\\\SimpleTTS\\\\diao1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_214">CUST_ADO_PATH"\\\\SimpleTTS\\\\diao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_215">CUST_ADO_PATH"\\\\SimpleTTS\\\\diao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_216">CUST_ADO_PATH"\\\\SimpleTTS\\\\die1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_217">CUST_ADO_PATH"\\\\SimpleTTS\\\\die2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_218">CUST_ADO_PATH"\\\\SimpleTTS\\\\ding1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_219">CUST_ADO_PATH"\\\\SimpleTTS\\\\ding3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_220">CUST_ADO_PATH"\\\\SimpleTTS\\\\ding4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_221">CUST_ADO_PATH"\\\\SimpleTTS\\\\diu1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_222">CUST_ADO_PATH"\\\\SimpleTTS\\\\dong1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_223">CUST_ADO_PATH"\\\\SimpleTTS\\\\dong3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_224">CUST_ADO_PATH"\\\\SimpleTTS\\\\dong4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_225">CUST_ADO_PATH"\\\\SimpleTTS\\\\dou1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_226">CUST_ADO_PATH"\\\\SimpleTTS\\\\dou3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_227">CUST_ADO_PATH"\\\\SimpleTTS\\\\dou4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_228">CUST_ADO_PATH"\\\\SimpleTTS\\\\du1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_229">CUST_ADO_PATH"\\\\SimpleTTS\\\\du2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_230">CUST_ADO_PATH"\\\\SimpleTTS\\\\du3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_231">CUST_ADO_PATH"\\\\SimpleTTS\\\\du4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_232">CUST_ADO_PATH"\\\\SimpleTTS\\\\duan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_233">CUST_ADO_PATH"\\\\SimpleTTS\\\\duan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_234">CUST_ADO_PATH"\\\\SimpleTTS\\\\duan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_235">CUST_ADO_PATH"\\\\SimpleTTS\\\\dui1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_236">CUST_ADO_PATH"\\\\SimpleTTS\\\\dui4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_237">CUST_ADO_PATH"\\\\SimpleTTS\\\\dun1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_238">CUST_ADO_PATH"\\\\SimpleTTS\\\\dun3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_239">CUST_ADO_PATH"\\\\SimpleTTS\\\\dun4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_240">CUST_ADO_PATH"\\\\SimpleTTS\\\\duo1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_241">CUST_ADO_PATH"\\\\SimpleTTS\\\\duo2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_242">CUST_ADO_PATH"\\\\SimpleTTS\\\\duo3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_243">CUST_ADO_PATH"\\\\SimpleTTS\\\\duo4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_244">CUST_ADO_PATH"\\\\SimpleTTS\\\\e1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_245">CUST_ADO_PATH"\\\\SimpleTTS\\\\e2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_246">CUST_ADO_PATH"\\\\SimpleTTS\\\\e3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_247">CUST_ADO_PATH"\\\\SimpleTTS\\\\e4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_248">CUST_ADO_PATH"\\\\SimpleTTS\\\\ei2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_249">CUST_ADO_PATH"\\\\SimpleTTS\\\\en1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_250">CUST_ADO_PATH"\\\\SimpleTTS\\\\en4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_251">CUST_ADO_PATH"\\\\SimpleTTS\\\\er2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_252">CUST_ADO_PATH"\\\\SimpleTTS\\\\er3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_253">CUST_ADO_PATH"\\\\SimpleTTS\\\\er4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_254">CUST_ADO_PATH"\\\\SimpleTTS\\\\fa1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_255">CUST_ADO_PATH"\\\\SimpleTTS\\\\fa2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_256">CUST_ADO_PATH"\\\\SimpleTTS\\\\fa3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_257">CUST_ADO_PATH"\\\\SimpleTTS\\\\fa4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_258">CUST_ADO_PATH"\\\\SimpleTTS\\\\fan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_259">CUST_ADO_PATH"\\\\SimpleTTS\\\\fan2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_260">CUST_ADO_PATH"\\\\SimpleTTS\\\\fan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_261">CUST_ADO_PATH"\\\\SimpleTTS\\\\fan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_262">CUST_ADO_PATH"\\\\SimpleTTS\\\\fang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_263">CUST_ADO_PATH"\\\\SimpleTTS\\\\fang2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_264">CUST_ADO_PATH"\\\\SimpleTTS\\\\fang3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_265">CUST_ADO_PATH"\\\\SimpleTTS\\\\fang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_266">CUST_ADO_PATH"\\\\SimpleTTS\\\\fei1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_267">CUST_ADO_PATH"\\\\SimpleTTS\\\\fei2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_268">CUST_ADO_PATH"\\\\SimpleTTS\\\\fei3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_269">CUST_ADO_PATH"\\\\SimpleTTS\\\\fei4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_270">CUST_ADO_PATH"\\\\SimpleTTS\\\\fen1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_271">CUST_ADO_PATH"\\\\SimpleTTS\\\\fen2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_272">CUST_ADO_PATH"\\\\SimpleTTS\\\\fen3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_273">CUST_ADO_PATH"\\\\SimpleTTS\\\\fen4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_274">CUST_ADO_PATH"\\\\SimpleTTS\\\\feng1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_275">CUST_ADO_PATH"\\\\SimpleTTS\\\\feng2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_276">CUST_ADO_PATH"\\\\SimpleTTS\\\\feng3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_277">CUST_ADO_PATH"\\\\SimpleTTS\\\\feng4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_278">CUST_ADO_PATH"\\\\SimpleTTS\\\\fo2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_279">CUST_ADO_PATH"\\\\SimpleTTS\\\\fou2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_280">CUST_ADO_PATH"\\\\SimpleTTS\\\\fou3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_281">CUST_ADO_PATH"\\\\SimpleTTS\\\\fu1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_282">CUST_ADO_PATH"\\\\SimpleTTS\\\\fu2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_283">CUST_ADO_PATH"\\\\SimpleTTS\\\\fu3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_284">CUST_ADO_PATH"\\\\SimpleTTS\\\\fu4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_285">CUST_ADO_PATH"\\\\SimpleTTS\\\\ga1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_286">CUST_ADO_PATH"\\\\SimpleTTS\\\\ga2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_287">CUST_ADO_PATH"\\\\SimpleTTS\\\\ga3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_288">CUST_ADO_PATH"\\\\SimpleTTS\\\\ga4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_289">CUST_ADO_PATH"\\\\SimpleTTS\\\\gai1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_290">CUST_ADO_PATH"\\\\SimpleTTS\\\\gai3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_291">CUST_ADO_PATH"\\\\SimpleTTS\\\\gai4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_292">CUST_ADO_PATH"\\\\SimpleTTS\\\\gan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_293">CUST_ADO_PATH"\\\\SimpleTTS\\\\gan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_294">CUST_ADO_PATH"\\\\SimpleTTS\\\\gan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_295">CUST_ADO_PATH"\\\\SimpleTTS\\\\gang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_296">CUST_ADO_PATH"\\\\SimpleTTS\\\\gang3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_297">CUST_ADO_PATH"\\\\SimpleTTS\\\\gang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_298">CUST_ADO_PATH"\\\\SimpleTTS\\\\gao1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_299">CUST_ADO_PATH"\\\\SimpleTTS\\\\gao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_300">CUST_ADO_PATH"\\\\SimpleTTS\\\\gao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_301">CUST_ADO_PATH"\\\\SimpleTTS\\\\ge1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_302">CUST_ADO_PATH"\\\\SimpleTTS\\\\ge2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_303">CUST_ADO_PATH"\\\\SimpleTTS\\\\ge3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_304">CUST_ADO_PATH"\\\\SimpleTTS\\\\ge4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_305">CUST_ADO_PATH"\\\\SimpleTTS\\\\gei3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_306">CUST_ADO_PATH"\\\\SimpleTTS\\\\gen1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_307">CUST_ADO_PATH"\\\\SimpleTTS\\\\gen2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_308">CUST_ADO_PATH"\\\\SimpleTTS\\\\gen3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_309">CUST_ADO_PATH"\\\\SimpleTTS\\\\gen4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_310">CUST_ADO_PATH"\\\\SimpleTTS\\\\geng1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_311">CUST_ADO_PATH"\\\\SimpleTTS\\\\geng3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_312">CUST_ADO_PATH"\\\\SimpleTTS\\\\geng4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_313">CUST_ADO_PATH"\\\\SimpleTTS\\\\gong1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_314">CUST_ADO_PATH"\\\\SimpleTTS\\\\gong3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_315">CUST_ADO_PATH"\\\\SimpleTTS\\\\gong4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_316">CUST_ADO_PATH"\\\\SimpleTTS\\\\gou1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_317">CUST_ADO_PATH"\\\\SimpleTTS\\\\gou3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_318">CUST_ADO_PATH"\\\\SimpleTTS\\\\gou4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_319">CUST_ADO_PATH"\\\\SimpleTTS\\\\gu1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_320">CUST_ADO_PATH"\\\\SimpleTTS\\\\gu3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_321">CUST_ADO_PATH"\\\\SimpleTTS\\\\gu4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_322">CUST_ADO_PATH"\\\\SimpleTTS\\\\gua1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_323">CUST_ADO_PATH"\\\\SimpleTTS\\\\gua3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_324">CUST_ADO_PATH"\\\\SimpleTTS\\\\gua4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_325">CUST_ADO_PATH"\\\\SimpleTTS\\\\guai1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_326">CUST_ADO_PATH"\\\\SimpleTTS\\\\guai3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_327">CUST_ADO_PATH"\\\\SimpleTTS\\\\guai4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_328">CUST_ADO_PATH"\\\\SimpleTTS\\\\guan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_329">CUST_ADO_PATH"\\\\SimpleTTS\\\\guan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_330">CUST_ADO_PATH"\\\\SimpleTTS\\\\guan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_331">CUST_ADO_PATH"\\\\SimpleTTS\\\\guang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_332">CUST_ADO_PATH"\\\\SimpleTTS\\\\guang3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_333">CUST_ADO_PATH"\\\\SimpleTTS\\\\guang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_334">CUST_ADO_PATH"\\\\SimpleTTS\\\\gui1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_335">CUST_ADO_PATH"\\\\SimpleTTS\\\\gui3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_336">CUST_ADO_PATH"\\\\SimpleTTS\\\\gui4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_337">CUST_ADO_PATH"\\\\SimpleTTS\\\\gun3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_338">CUST_ADO_PATH"\\\\SimpleTTS\\\\gun4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_339">CUST_ADO_PATH"\\\\SimpleTTS\\\\guo1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_340">CUST_ADO_PATH"\\\\SimpleTTS\\\\guo2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_341">CUST_ADO_PATH"\\\\SimpleTTS\\\\guo3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_342">CUST_ADO_PATH"\\\\SimpleTTS\\\\guo4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_343">CUST_ADO_PATH"\\\\SimpleTTS\\\\ha1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_344">CUST_ADO_PATH"\\\\SimpleTTS\\\\ha2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_345">CUST_ADO_PATH"\\\\SimpleTTS\\\\hai1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_346">CUST_ADO_PATH"\\\\SimpleTTS\\\\hai2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_347">CUST_ADO_PATH"\\\\SimpleTTS\\\\hai3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_348">CUST_ADO_PATH"\\\\SimpleTTS\\\\hai4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_349">CUST_ADO_PATH"\\\\SimpleTTS\\\\han1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_350">CUST_ADO_PATH"\\\\SimpleTTS\\\\han2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_351">CUST_ADO_PATH"\\\\SimpleTTS\\\\han3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_352">CUST_ADO_PATH"\\\\SimpleTTS\\\\han4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_353">CUST_ADO_PATH"\\\\SimpleTTS\\\\hang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_354">CUST_ADO_PATH"\\\\SimpleTTS\\\\hang2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_355">CUST_ADO_PATH"\\\\SimpleTTS\\\\hang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_356">CUST_ADO_PATH"\\\\SimpleTTS\\\\hao1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_357">CUST_ADO_PATH"\\\\SimpleTTS\\\\hao2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_358">CUST_ADO_PATH"\\\\SimpleTTS\\\\hao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_359">CUST_ADO_PATH"\\\\SimpleTTS\\\\hao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_360">CUST_ADO_PATH"\\\\SimpleTTS\\\\he1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_361">CUST_ADO_PATH"\\\\SimpleTTS\\\\he2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_362">CUST_ADO_PATH"\\\\SimpleTTS\\\\he4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_363">CUST_ADO_PATH"\\\\SimpleTTS\\\\hei1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_364">CUST_ADO_PATH"\\\\SimpleTTS\\\\hen2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_365">CUST_ADO_PATH"\\\\SimpleTTS\\\\hen3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_366">CUST_ADO_PATH"\\\\SimpleTTS\\\\hen4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_367">CUST_ADO_PATH"\\\\SimpleTTS\\\\heng1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_368">CUST_ADO_PATH"\\\\SimpleTTS\\\\heng2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_369">CUST_ADO_PATH"\\\\SimpleTTS\\\\heng4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_370">CUST_ADO_PATH"\\\\SimpleTTS\\\\hong1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_371">CUST_ADO_PATH"\\\\SimpleTTS\\\\hong2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_372">CUST_ADO_PATH"\\\\SimpleTTS\\\\hong3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_373">CUST_ADO_PATH"\\\\SimpleTTS\\\\hong4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_374">CUST_ADO_PATH"\\\\SimpleTTS\\\\hou2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_375">CUST_ADO_PATH"\\\\SimpleTTS\\\\hou3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_376">CUST_ADO_PATH"\\\\SimpleTTS\\\\hou4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_377">CUST_ADO_PATH"\\\\SimpleTTS\\\\hu1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_378">CUST_ADO_PATH"\\\\SimpleTTS\\\\hu2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_379">CUST_ADO_PATH"\\\\SimpleTTS\\\\hu3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_380">CUST_ADO_PATH"\\\\SimpleTTS\\\\hu4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_381">CUST_ADO_PATH"\\\\SimpleTTS\\\\hua1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_382">CUST_ADO_PATH"\\\\SimpleTTS\\\\hua2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_383">CUST_ADO_PATH"\\\\SimpleTTS\\\\hua4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_384">CUST_ADO_PATH"\\\\SimpleTTS\\\\huai2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_385">CUST_ADO_PATH"\\\\SimpleTTS\\\\huai4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_386">CUST_ADO_PATH"\\\\SimpleTTS\\\\huan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_387">CUST_ADO_PATH"\\\\SimpleTTS\\\\huan2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_388">CUST_ADO_PATH"\\\\SimpleTTS\\\\huan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_389">CUST_ADO_PATH"\\\\SimpleTTS\\\\huan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_390">CUST_ADO_PATH"\\\\SimpleTTS\\\\huang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_391">CUST_ADO_PATH"\\\\SimpleTTS\\\\huang2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_392">CUST_ADO_PATH"\\\\SimpleTTS\\\\huang3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_393">CUST_ADO_PATH"\\\\SimpleTTS\\\\huang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_394">CUST_ADO_PATH"\\\\SimpleTTS\\\\hui1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_395">CUST_ADO_PATH"\\\\SimpleTTS\\\\hui2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_396">CUST_ADO_PATH"\\\\SimpleTTS\\\\hui3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_397">CUST_ADO_PATH"\\\\SimpleTTS\\\\hui4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_398">CUST_ADO_PATH"\\\\SimpleTTS\\\\hun1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_399">CUST_ADO_PATH"\\\\SimpleTTS\\\\hun2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_400">CUST_ADO_PATH"\\\\SimpleTTS\\\\hun4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_401">CUST_ADO_PATH"\\\\SimpleTTS\\\\huo1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_402">CUST_ADO_PATH"\\\\SimpleTTS\\\\huo2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_403">CUST_ADO_PATH"\\\\SimpleTTS\\\\huo3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_404">CUST_ADO_PATH"\\\\SimpleTTS\\\\huo4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_405">CUST_ADO_PATH"\\\\SimpleTTS\\\\ji1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_406">CUST_ADO_PATH"\\\\SimpleTTS\\\\ji2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_407">CUST_ADO_PATH"\\\\SimpleTTS\\\\ji3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_408">CUST_ADO_PATH"\\\\SimpleTTS\\\\ji4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_409">CUST_ADO_PATH"\\\\SimpleTTS\\\\jia1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_410">CUST_ADO_PATH"\\\\SimpleTTS\\\\jia2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_411">CUST_ADO_PATH"\\\\SimpleTTS\\\\jia3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_412">CUST_ADO_PATH"\\\\SimpleTTS\\\\jia4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_413">CUST_ADO_PATH"\\\\SimpleTTS\\\\jian1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_414">CUST_ADO_PATH"\\\\SimpleTTS\\\\jian3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_415">CUST_ADO_PATH"\\\\SimpleTTS\\\\jian4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_416">CUST_ADO_PATH"\\\\SimpleTTS\\\\jiang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_417">CUST_ADO_PATH"\\\\SimpleTTS\\\\jiang3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_418">CUST_ADO_PATH"\\\\SimpleTTS\\\\jiang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_419">CUST_ADO_PATH"\\\\SimpleTTS\\\\jiao1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_420">CUST_ADO_PATH"\\\\SimpleTTS\\\\jiao2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_421">CUST_ADO_PATH"\\\\SimpleTTS\\\\jiao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_422">CUST_ADO_PATH"\\\\SimpleTTS\\\\jiao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_423">CUST_ADO_PATH"\\\\SimpleTTS\\\\jie1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_424">CUST_ADO_PATH"\\\\SimpleTTS\\\\jie2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_425">CUST_ADO_PATH"\\\\SimpleTTS\\\\jie3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_426">CUST_ADO_PATH"\\\\SimpleTTS\\\\jie4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_427">CUST_ADO_PATH"\\\\SimpleTTS\\\\jin1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_428">CUST_ADO_PATH"\\\\SimpleTTS\\\\jin3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_429">CUST_ADO_PATH"\\\\SimpleTTS\\\\jin4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_430">CUST_ADO_PATH"\\\\SimpleTTS\\\\jing1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_431">CUST_ADO_PATH"\\\\SimpleTTS\\\\jing3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_432">CUST_ADO_PATH"\\\\SimpleTTS\\\\jing4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_433">CUST_ADO_PATH"\\\\SimpleTTS\\\\jiong1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_434">CUST_ADO_PATH"\\\\SimpleTTS\\\\jiong3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_435">CUST_ADO_PATH"\\\\SimpleTTS\\\\jiu1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_436">CUST_ADO_PATH"\\\\SimpleTTS\\\\jiu3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_437">CUST_ADO_PATH"\\\\SimpleTTS\\\\jiu4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_438">CUST_ADO_PATH"\\\\SimpleTTS\\\\ju1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_439">CUST_ADO_PATH"\\\\SimpleTTS\\\\ju2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_440">CUST_ADO_PATH"\\\\SimpleTTS\\\\ju3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_441">CUST_ADO_PATH"\\\\SimpleTTS\\\\ju4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_442">CUST_ADO_PATH"\\\\SimpleTTS\\\\juan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_443">CUST_ADO_PATH"\\\\SimpleTTS\\\\juan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_444">CUST_ADO_PATH"\\\\SimpleTTS\\\\juan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_445">CUST_ADO_PATH"\\\\SimpleTTS\\\\jue1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_446">CUST_ADO_PATH"\\\\SimpleTTS\\\\jue2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_447">CUST_ADO_PATH"\\\\SimpleTTS\\\\jue4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_448">CUST_ADO_PATH"\\\\SimpleTTS\\\\jun1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_449">CUST_ADO_PATH"\\\\SimpleTTS\\\\jun4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_450">CUST_ADO_PATH"\\\\SimpleTTS\\\\ka1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_451">CUST_ADO_PATH"\\\\SimpleTTS\\\\ka3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_452">CUST_ADO_PATH"\\\\SimpleTTS\\\\kai1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_453">CUST_ADO_PATH"\\\\SimpleTTS\\\\kai3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_454">CUST_ADO_PATH"\\\\SimpleTTS\\\\kai4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_455">CUST_ADO_PATH"\\\\SimpleTTS\\\\kan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_456">CUST_ADO_PATH"\\\\SimpleTTS\\\\kan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_457">CUST_ADO_PATH"\\\\SimpleTTS\\\\kan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_458">CUST_ADO_PATH"\\\\SimpleTTS\\\\kang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_459">CUST_ADO_PATH"\\\\SimpleTTS\\\\kang2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_460">CUST_ADO_PATH"\\\\SimpleTTS\\\\kang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_461">CUST_ADO_PATH"\\\\SimpleTTS\\\\kao1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_462">CUST_ADO_PATH"\\\\SimpleTTS\\\\kao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_463">CUST_ADO_PATH"\\\\SimpleTTS\\\\kao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_464">CUST_ADO_PATH"\\\\SimpleTTS\\\\ke1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_465">CUST_ADO_PATH"\\\\SimpleTTS\\\\ke2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_466">CUST_ADO_PATH"\\\\SimpleTTS\\\\ke3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_467">CUST_ADO_PATH"\\\\SimpleTTS\\\\ke4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_468">CUST_ADO_PATH"\\\\SimpleTTS\\\\ken3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_469">CUST_ADO_PATH"\\\\SimpleTTS\\\\ken4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_470">CUST_ADO_PATH"\\\\SimpleTTS\\\\keng1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_471">CUST_ADO_PATH"\\\\SimpleTTS\\\\kong1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_472">CUST_ADO_PATH"\\\\SimpleTTS\\\\kong3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_473">CUST_ADO_PATH"\\\\SimpleTTS\\\\kong4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_474">CUST_ADO_PATH"\\\\SimpleTTS\\\\kou1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_475">CUST_ADO_PATH"\\\\SimpleTTS\\\\kou3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_476">CUST_ADO_PATH"\\\\SimpleTTS\\\\kou4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_477">CUST_ADO_PATH"\\\\SimpleTTS\\\\ku1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_478">CUST_ADO_PATH"\\\\SimpleTTS\\\\ku3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_479">CUST_ADO_PATH"\\\\SimpleTTS\\\\ku4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_480">CUST_ADO_PATH"\\\\SimpleTTS\\\\kua1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_481">CUST_ADO_PATH"\\\\SimpleTTS\\\\kua3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_482">CUST_ADO_PATH"\\\\SimpleTTS\\\\kua4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_483">CUST_ADO_PATH"\\\\SimpleTTS\\\\kuai1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_484">CUST_ADO_PATH"\\\\SimpleTTS\\\\kuai3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_485">CUST_ADO_PATH"\\\\SimpleTTS\\\\kuai4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_486">CUST_ADO_PATH"\\\\SimpleTTS\\\\kuan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_487">CUST_ADO_PATH"\\\\SimpleTTS\\\\kuan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_488">CUST_ADO_PATH"\\\\SimpleTTS\\\\kuang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_489">CUST_ADO_PATH"\\\\SimpleTTS\\\\kuang2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_490">CUST_ADO_PATH"\\\\SimpleTTS\\\\kuang3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_491">CUST_ADO_PATH"\\\\SimpleTTS\\\\kuang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_492">CUST_ADO_PATH"\\\\SimpleTTS\\\\kui1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_493">CUST_ADO_PATH"\\\\SimpleTTS\\\\kui2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_494">CUST_ADO_PATH"\\\\SimpleTTS\\\\kui3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_495">CUST_ADO_PATH"\\\\SimpleTTS\\\\kui4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_496">CUST_ADO_PATH"\\\\SimpleTTS\\\\kun1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_497">CUST_ADO_PATH"\\\\SimpleTTS\\\\kun3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_498">CUST_ADO_PATH"\\\\SimpleTTS\\\\kun4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_499">CUST_ADO_PATH"\\\\SimpleTTS\\\\kuo4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_500">CUST_ADO_PATH"\\\\SimpleTTS\\\\la1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_501">CUST_ADO_PATH"\\\\SimpleTTS\\\\la2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_502">CUST_ADO_PATH"\\\\SimpleTTS\\\\la3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_503">CUST_ADO_PATH"\\\\SimpleTTS\\\\la4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_504">CUST_ADO_PATH"\\\\SimpleTTS\\\\la5.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_505">CUST_ADO_PATH"\\\\SimpleTTS\\\\lai2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_506">CUST_ADO_PATH"\\\\SimpleTTS\\\\lai4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_507">CUST_ADO_PATH"\\\\SimpleTTS\\\\lan2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_508">CUST_ADO_PATH"\\\\SimpleTTS\\\\lan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_509">CUST_ADO_PATH"\\\\SimpleTTS\\\\lan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_510">CUST_ADO_PATH"\\\\SimpleTTS\\\\lang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_511">CUST_ADO_PATH"\\\\SimpleTTS\\\\lang2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_512">CUST_ADO_PATH"\\\\SimpleTTS\\\\lang3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_513">CUST_ADO_PATH"\\\\SimpleTTS\\\\lang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_514">CUST_ADO_PATH"\\\\SimpleTTS\\\\lao1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_515">CUST_ADO_PATH"\\\\SimpleTTS\\\\lao2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_516">CUST_ADO_PATH"\\\\SimpleTTS\\\\lao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_517">CUST_ADO_PATH"\\\\SimpleTTS\\\\lao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_518">CUST_ADO_PATH"\\\\SimpleTTS\\\\le4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_519">CUST_ADO_PATH"\\\\SimpleTTS\\\\le5.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_520">CUST_ADO_PATH"\\\\SimpleTTS\\\\lei2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_521">CUST_ADO_PATH"\\\\SimpleTTS\\\\lei3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_522">CUST_ADO_PATH"\\\\SimpleTTS\\\\lei4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_523">CUST_ADO_PATH"\\\\SimpleTTS\\\\lei5.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_524">CUST_ADO_PATH"\\\\SimpleTTS\\\\leng2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_525">CUST_ADO_PATH"\\\\SimpleTTS\\\\leng3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_526">CUST_ADO_PATH"\\\\SimpleTTS\\\\leng4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_527">CUST_ADO_PATH"\\\\SimpleTTS\\\\li2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_528">CUST_ADO_PATH"\\\\SimpleTTS\\\\li3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_529">CUST_ADO_PATH"\\\\SimpleTTS\\\\li4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_530">CUST_ADO_PATH"\\\\SimpleTTS\\\\li5.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_531">CUST_ADO_PATH"\\\\SimpleTTS\\\\lian2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_532">CUST_ADO_PATH"\\\\SimpleTTS\\\\lian3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_533">CUST_ADO_PATH"\\\\SimpleTTS\\\\lian4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_534">CUST_ADO_PATH"\\\\SimpleTTS\\\\liang2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_535">CUST_ADO_PATH"\\\\SimpleTTS\\\\liang3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_536">CUST_ADO_PATH"\\\\SimpleTTS\\\\liang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_537">CUST_ADO_PATH"\\\\SimpleTTS\\\\liao2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_538">CUST_ADO_PATH"\\\\SimpleTTS\\\\liao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_539">CUST_ADO_PATH"\\\\SimpleTTS\\\\liao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_540">CUST_ADO_PATH"\\\\SimpleTTS\\\\lie4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_541">CUST_ADO_PATH"\\\\SimpleTTS\\\\lie5.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_542">CUST_ADO_PATH"\\\\SimpleTTS\\\\lin2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_543">CUST_ADO_PATH"\\\\SimpleTTS\\\\lin3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_544">CUST_ADO_PATH"\\\\SimpleTTS\\\\lin4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_545">CUST_ADO_PATH"\\\\SimpleTTS\\\\ling1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_546">CUST_ADO_PATH"\\\\SimpleTTS\\\\ling2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_547">CUST_ADO_PATH"\\\\SimpleTTS\\\\ling3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_548">CUST_ADO_PATH"\\\\SimpleTTS\\\\ling4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_549">CUST_ADO_PATH"\\\\SimpleTTS\\\\liu1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_550">CUST_ADO_PATH"\\\\SimpleTTS\\\\liu2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_551">CUST_ADO_PATH"\\\\SimpleTTS\\\\liu3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_552">CUST_ADO_PATH"\\\\SimpleTTS\\\\liu4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_553">CUST_ADO_PATH"\\\\SimpleTTS\\\\long2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_554">CUST_ADO_PATH"\\\\SimpleTTS\\\\long3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_555">CUST_ADO_PATH"\\\\SimpleTTS\\\\lou2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_556">CUST_ADO_PATH"\\\\SimpleTTS\\\\lou3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_557">CUST_ADO_PATH"\\\\SimpleTTS\\\\lou4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_558">CUST_ADO_PATH"\\\\SimpleTTS\\\\lou5.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_559">CUST_ADO_PATH"\\\\SimpleTTS\\\\lu1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_560">CUST_ADO_PATH"\\\\SimpleTTS\\\\lu2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_561">CUST_ADO_PATH"\\\\SimpleTTS\\\\lu3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_562">CUST_ADO_PATH"\\\\SimpleTTS\\\\lu4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_563">CUST_ADO_PATH"\\\\SimpleTTS\\\\lu5.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_564">CUST_ADO_PATH"\\\\SimpleTTS\\\\luan2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_565">CUST_ADO_PATH"\\\\SimpleTTS\\\\luan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_566">CUST_ADO_PATH"\\\\SimpleTTS\\\\luan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_567">CUST_ADO_PATH"\\\\SimpleTTS\\\\lun2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_568">CUST_ADO_PATH"\\\\SimpleTTS\\\\lun4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_569">CUST_ADO_PATH"\\\\SimpleTTS\\\\luo1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_570">CUST_ADO_PATH"\\\\SimpleTTS\\\\luo2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_571">CUST_ADO_PATH"\\\\SimpleTTS\\\\luo3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_572">CUST_ADO_PATH"\\\\SimpleTTS\\\\luo4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_573">CUST_ADO_PATH"\\\\SimpleTTS\\\\lv2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_574">CUST_ADO_PATH"\\\\SimpleTTS\\\\lv3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_575">CUST_ADO_PATH"\\\\SimpleTTS\\\\lv4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_576">CUST_ADO_PATH"\\\\SimpleTTS\\\\lve4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_577">CUST_ADO_PATH"\\\\SimpleTTS\\\\m2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_578">CUST_ADO_PATH"\\\\SimpleTTS\\\\ma1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_579">CUST_ADO_PATH"\\\\SimpleTTS\\\\ma2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_580">CUST_ADO_PATH"\\\\SimpleTTS\\\\ma3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_581">CUST_ADO_PATH"\\\\SimpleTTS\\\\ma4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_582">CUST_ADO_PATH"\\\\SimpleTTS\\\\ma5.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_583">CUST_ADO_PATH"\\\\SimpleTTS\\\\mai2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_584">CUST_ADO_PATH"\\\\SimpleTTS\\\\mai3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_585">CUST_ADO_PATH"\\\\SimpleTTS\\\\mai4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_586">CUST_ADO_PATH"\\\\SimpleTTS\\\\man1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_587">CUST_ADO_PATH"\\\\SimpleTTS\\\\man2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_588">CUST_ADO_PATH"\\\\SimpleTTS\\\\man3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_589">CUST_ADO_PATH"\\\\SimpleTTS\\\\man4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_590">CUST_ADO_PATH"\\\\SimpleTTS\\\\mang2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_591">CUST_ADO_PATH"\\\\SimpleTTS\\\\mang3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_592">CUST_ADO_PATH"\\\\SimpleTTS\\\\mao1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_593">CUST_ADO_PATH"\\\\SimpleTTS\\\\mao2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_594">CUST_ADO_PATH"\\\\SimpleTTS\\\\mao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_595">CUST_ADO_PATH"\\\\SimpleTTS\\\\mao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_596">CUST_ADO_PATH"\\\\SimpleTTS\\\\me5.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_597">CUST_ADO_PATH"\\\\SimpleTTS\\\\mei2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_598">CUST_ADO_PATH"\\\\SimpleTTS\\\\mei3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_599">CUST_ADO_PATH"\\\\SimpleTTS\\\\mei4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_600">CUST_ADO_PATH"\\\\SimpleTTS\\\\men2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_601">CUST_ADO_PATH"\\\\SimpleTTS\\\\men4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_602">CUST_ADO_PATH"\\\\SimpleTTS\\\\men5.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_603">CUST_ADO_PATH"\\\\SimpleTTS\\\\meng2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_604">CUST_ADO_PATH"\\\\SimpleTTS\\\\meng3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_605">CUST_ADO_PATH"\\\\SimpleTTS\\\\meng4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_606">CUST_ADO_PATH"\\\\SimpleTTS\\\\mi1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_607">CUST_ADO_PATH"\\\\SimpleTTS\\\\mi2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_608">CUST_ADO_PATH"\\\\SimpleTTS\\\\mi3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_609">CUST_ADO_PATH"\\\\SimpleTTS\\\\mi4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_610">CUST_ADO_PATH"\\\\SimpleTTS\\\\mian2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_611">CUST_ADO_PATH"\\\\SimpleTTS\\\\mian3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_612">CUST_ADO_PATH"\\\\SimpleTTS\\\\mian4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_613">CUST_ADO_PATH"\\\\SimpleTTS\\\\miao1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_614">CUST_ADO_PATH"\\\\SimpleTTS\\\\miao2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_615">CUST_ADO_PATH"\\\\SimpleTTS\\\\miao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_616">CUST_ADO_PATH"\\\\SimpleTTS\\\\miao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_617">CUST_ADO_PATH"\\\\SimpleTTS\\\\mie1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_618">CUST_ADO_PATH"\\\\SimpleTTS\\\\mie4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_619">CUST_ADO_PATH"\\\\SimpleTTS\\\\min2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_620">CUST_ADO_PATH"\\\\SimpleTTS\\\\min3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_621">CUST_ADO_PATH"\\\\SimpleTTS\\\\ming2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_622">CUST_ADO_PATH"\\\\SimpleTTS\\\\ming3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_623">CUST_ADO_PATH"\\\\SimpleTTS\\\\ming4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_624">CUST_ADO_PATH"\\\\SimpleTTS\\\\miu4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_625">CUST_ADO_PATH"\\\\SimpleTTS\\\\mo1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_626">CUST_ADO_PATH"\\\\SimpleTTS\\\\mo2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_627">CUST_ADO_PATH"\\\\SimpleTTS\\\\mo3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_628">CUST_ADO_PATH"\\\\SimpleTTS\\\\mo4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_629">CUST_ADO_PATH"\\\\SimpleTTS\\\\mou1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_630">CUST_ADO_PATH"\\\\SimpleTTS\\\\mou2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_631">CUST_ADO_PATH"\\\\SimpleTTS\\\\mou3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_632">CUST_ADO_PATH"\\\\SimpleTTS\\\\mu2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_633">CUST_ADO_PATH"\\\\SimpleTTS\\\\mu3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_634">CUST_ADO_PATH"\\\\SimpleTTS\\\\mu4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_635">CUST_ADO_PATH"\\\\SimpleTTS\\\\n2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_636">CUST_ADO_PATH"\\\\SimpleTTS\\\\na2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_637">CUST_ADO_PATH"\\\\SimpleTTS\\\\na3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_638">CUST_ADO_PATH"\\\\SimpleTTS\\\\na4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_639">CUST_ADO_PATH"\\\\SimpleTTS\\\\nai3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_640">CUST_ADO_PATH"\\\\SimpleTTS\\\\nai4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_641">CUST_ADO_PATH"\\\\SimpleTTS\\\\nan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_642">CUST_ADO_PATH"\\\\SimpleTTS\\\\nan2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_643">CUST_ADO_PATH"\\\\SimpleTTS\\\\nan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_644">CUST_ADO_PATH"\\\\SimpleTTS\\\\nang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_645">CUST_ADO_PATH"\\\\SimpleTTS\\\\nang2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_646">CUST_ADO_PATH"\\\\SimpleTTS\\\\nang3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_647">CUST_ADO_PATH"\\\\SimpleTTS\\\\nao1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_648">CUST_ADO_PATH"\\\\SimpleTTS\\\\nao2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_649">CUST_ADO_PATH"\\\\SimpleTTS\\\\nao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_650">CUST_ADO_PATH"\\\\SimpleTTS\\\\nao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_651">CUST_ADO_PATH"\\\\SimpleTTS\\\\ne4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_652">CUST_ADO_PATH"\\\\SimpleTTS\\\\ne5.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_653">CUST_ADO_PATH"\\\\SimpleTTS\\\\nei3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_654">CUST_ADO_PATH"\\\\SimpleTTS\\\\nei4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_655">CUST_ADO_PATH"\\\\SimpleTTS\\\\nen4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_656">CUST_ADO_PATH"\\\\SimpleTTS\\\\neng2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_657">CUST_ADO_PATH"\\\\SimpleTTS\\\\ni1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_658">CUST_ADO_PATH"\\\\SimpleTTS\\\\ni2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_659">CUST_ADO_PATH"\\\\SimpleTTS\\\\ni3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_660">CUST_ADO_PATH"\\\\SimpleTTS\\\\ni4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_661">CUST_ADO_PATH"\\\\SimpleTTS\\\\nian1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_662">CUST_ADO_PATH"\\\\SimpleTTS\\\\nian2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_663">CUST_ADO_PATH"\\\\SimpleTTS\\\\nian3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_664">CUST_ADO_PATH"\\\\SimpleTTS\\\\nian4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_665">CUST_ADO_PATH"\\\\SimpleTTS\\\\niang2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_666">CUST_ADO_PATH"\\\\SimpleTTS\\\\niang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_667">CUST_ADO_PATH"\\\\SimpleTTS\\\\niao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_668">CUST_ADO_PATH"\\\\SimpleTTS\\\\niao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_669">CUST_ADO_PATH"\\\\SimpleTTS\\\\nie1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_670">CUST_ADO_PATH"\\\\SimpleTTS\\\\nie4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_671">CUST_ADO_PATH"\\\\SimpleTTS\\\\nin2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_672">CUST_ADO_PATH"\\\\SimpleTTS\\\\ning2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_673">CUST_ADO_PATH"\\\\SimpleTTS\\\\ning3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_674">CUST_ADO_PATH"\\\\SimpleTTS\\\\ning4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_675">CUST_ADO_PATH"\\\\SimpleTTS\\\\niu1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_676">CUST_ADO_PATH"\\\\SimpleTTS\\\\niu2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_677">CUST_ADO_PATH"\\\\SimpleTTS\\\\niu3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_678">CUST_ADO_PATH"\\\\SimpleTTS\\\\niu4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_679">CUST_ADO_PATH"\\\\SimpleTTS\\\\nong2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_680">CUST_ADO_PATH"\\\\SimpleTTS\\\\nong4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_681">CUST_ADO_PATH"\\\\SimpleTTS\\\\nou4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_682">CUST_ADO_PATH"\\\\SimpleTTS\\\\nu2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_683">CUST_ADO_PATH"\\\\SimpleTTS\\\\nu3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_684">CUST_ADO_PATH"\\\\SimpleTTS\\\\nu4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_685">CUST_ADO_PATH"\\\\SimpleTTS\\\\nuan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_686">CUST_ADO_PATH"\\\\SimpleTTS\\\\nuo2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_687">CUST_ADO_PATH"\\\\SimpleTTS\\\\nuo4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_688">CUST_ADO_PATH"\\\\SimpleTTS\\\\nv3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_689">CUST_ADO_PATH"\\\\SimpleTTS\\\\nv4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_690">CUST_ADO_PATH"\\\\SimpleTTS\\\\nve4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_691">CUST_ADO_PATH"\\\\SimpleTTS\\\\o1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_692">CUST_ADO_PATH"\\\\SimpleTTS\\\\o4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_693">CUST_ADO_PATH"\\\\SimpleTTS\\\\ou1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_694">CUST_ADO_PATH"\\\\SimpleTTS\\\\ou3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_695">CUST_ADO_PATH"\\\\SimpleTTS\\\\ou4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_696">CUST_ADO_PATH"\\\\SimpleTTS\\\\pa1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_697">CUST_ADO_PATH"\\\\SimpleTTS\\\\pa2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_698">CUST_ADO_PATH"\\\\SimpleTTS\\\\pa4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_699">CUST_ADO_PATH"\\\\SimpleTTS\\\\pa5.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_700">CUST_ADO_PATH"\\\\SimpleTTS\\\\pai1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_701">CUST_ADO_PATH"\\\\SimpleTTS\\\\pai2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_702">CUST_ADO_PATH"\\\\SimpleTTS\\\\pai4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_703">CUST_ADO_PATH"\\\\SimpleTTS\\\\pan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_704">CUST_ADO_PATH"\\\\SimpleTTS\\\\pan2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_705">CUST_ADO_PATH"\\\\SimpleTTS\\\\pan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_706">CUST_ADO_PATH"\\\\SimpleTTS\\\\pang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_707">CUST_ADO_PATH"\\\\SimpleTTS\\\\pang2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_708">CUST_ADO_PATH"\\\\SimpleTTS\\\\pang3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_709">CUST_ADO_PATH"\\\\SimpleTTS\\\\pang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_710">CUST_ADO_PATH"\\\\SimpleTTS\\\\pao1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_711">CUST_ADO_PATH"\\\\SimpleTTS\\\\pao2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_712">CUST_ADO_PATH"\\\\SimpleTTS\\\\pao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_713">CUST_ADO_PATH"\\\\SimpleTTS\\\\pao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_714">CUST_ADO_PATH"\\\\SimpleTTS\\\\pei1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_715">CUST_ADO_PATH"\\\\SimpleTTS\\\\pei2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_716">CUST_ADO_PATH"\\\\SimpleTTS\\\\pei4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_717">CUST_ADO_PATH"\\\\SimpleTTS\\\\pen1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_718">CUST_ADO_PATH"\\\\SimpleTTS\\\\pen2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_719">CUST_ADO_PATH"\\\\SimpleTTS\\\\peng1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_720">CUST_ADO_PATH"\\\\SimpleTTS\\\\peng2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_721">CUST_ADO_PATH"\\\\SimpleTTS\\\\peng3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_722">CUST_ADO_PATH"\\\\SimpleTTS\\\\peng4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_723">CUST_ADO_PATH"\\\\SimpleTTS\\\\pi1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_724">CUST_ADO_PATH"\\\\SimpleTTS\\\\pi2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_725">CUST_ADO_PATH"\\\\SimpleTTS\\\\pi3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_726">CUST_ADO_PATH"\\\\SimpleTTS\\\\pi4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_727">CUST_ADO_PATH"\\\\SimpleTTS\\\\pian1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_728">CUST_ADO_PATH"\\\\SimpleTTS\\\\pian2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_729">CUST_ADO_PATH"\\\\SimpleTTS\\\\pian3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_730">CUST_ADO_PATH"\\\\SimpleTTS\\\\pian4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_731">CUST_ADO_PATH"\\\\SimpleTTS\\\\piao1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_732">CUST_ADO_PATH"\\\\SimpleTTS\\\\piao2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_733">CUST_ADO_PATH"\\\\SimpleTTS\\\\piao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_734">CUST_ADO_PATH"\\\\SimpleTTS\\\\piao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_735">CUST_ADO_PATH"\\\\SimpleTTS\\\\pie1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_736">CUST_ADO_PATH"\\\\SimpleTTS\\\\pie3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_737">CUST_ADO_PATH"\\\\SimpleTTS\\\\pin1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_738">CUST_ADO_PATH"\\\\SimpleTTS\\\\pin2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_739">CUST_ADO_PATH"\\\\SimpleTTS\\\\pin3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_740">CUST_ADO_PATH"\\\\SimpleTTS\\\\pin4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_741">CUST_ADO_PATH"\\\\SimpleTTS\\\\ping1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_742">CUST_ADO_PATH"\\\\SimpleTTS\\\\ping2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_743">CUST_ADO_PATH"\\\\SimpleTTS\\\\po1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_744">CUST_ADO_PATH"\\\\SimpleTTS\\\\po2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_745">CUST_ADO_PATH"\\\\SimpleTTS\\\\po3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_746">CUST_ADO_PATH"\\\\SimpleTTS\\\\po4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_747">CUST_ADO_PATH"\\\\SimpleTTS\\\\pou1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_748">CUST_ADO_PATH"\\\\SimpleTTS\\\\pou2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_749">CUST_ADO_PATH"\\\\SimpleTTS\\\\pu1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_750">CUST_ADO_PATH"\\\\SimpleTTS\\\\pu2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_751">CUST_ADO_PATH"\\\\SimpleTTS\\\\pu3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_752">CUST_ADO_PATH"\\\\SimpleTTS\\\\pu4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_753">CUST_ADO_PATH"\\\\SimpleTTS\\\\qi1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_754">CUST_ADO_PATH"\\\\SimpleTTS\\\\qi2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_755">CUST_ADO_PATH"\\\\SimpleTTS\\\\qi3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_756">CUST_ADO_PATH"\\\\SimpleTTS\\\\qi4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_757">CUST_ADO_PATH"\\\\SimpleTTS\\\\qia1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_758">CUST_ADO_PATH"\\\\SimpleTTS\\\\qia4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_759">CUST_ADO_PATH"\\\\SimpleTTS\\\\qian1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_760">CUST_ADO_PATH"\\\\SimpleTTS\\\\qian2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_761">CUST_ADO_PATH"\\\\SimpleTTS\\\\qian3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_762">CUST_ADO_PATH"\\\\SimpleTTS\\\\qian4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_763">CUST_ADO_PATH"\\\\SimpleTTS\\\\qiang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_764">CUST_ADO_PATH"\\\\SimpleTTS\\\\qiang2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_765">CUST_ADO_PATH"\\\\SimpleTTS\\\\qiang3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_766">CUST_ADO_PATH"\\\\SimpleTTS\\\\qiang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_767">CUST_ADO_PATH"\\\\SimpleTTS\\\\qiao1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_768">CUST_ADO_PATH"\\\\SimpleTTS\\\\qiao2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_769">CUST_ADO_PATH"\\\\SimpleTTS\\\\qiao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_770">CUST_ADO_PATH"\\\\SimpleTTS\\\\qiao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_771">CUST_ADO_PATH"\\\\SimpleTTS\\\\qie2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_772">CUST_ADO_PATH"\\\\SimpleTTS\\\\qie3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_773">CUST_ADO_PATH"\\\\SimpleTTS\\\\qie4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_774">CUST_ADO_PATH"\\\\SimpleTTS\\\\qin1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_775">CUST_ADO_PATH"\\\\SimpleTTS\\\\qin2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_776">CUST_ADO_PATH"\\\\SimpleTTS\\\\qin3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_777">CUST_ADO_PATH"\\\\SimpleTTS\\\\qin4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_778">CUST_ADO_PATH"\\\\SimpleTTS\\\\qing1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_779">CUST_ADO_PATH"\\\\SimpleTTS\\\\qing2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_780">CUST_ADO_PATH"\\\\SimpleTTS\\\\qing3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_781">CUST_ADO_PATH"\\\\SimpleTTS\\\\qing4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_782">CUST_ADO_PATH"\\\\SimpleTTS\\\\qiong2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_783">CUST_ADO_PATH"\\\\SimpleTTS\\\\qiu1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_784">CUST_ADO_PATH"\\\\SimpleTTS\\\\qiu2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_785">CUST_ADO_PATH"\\\\SimpleTTS\\\\qiu3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_786">CUST_ADO_PATH"\\\\SimpleTTS\\\\qu1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_787">CUST_ADO_PATH"\\\\SimpleTTS\\\\qu2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_788">CUST_ADO_PATH"\\\\SimpleTTS\\\\qu3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_789">CUST_ADO_PATH"\\\\SimpleTTS\\\\qu4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_790">CUST_ADO_PATH"\\\\SimpleTTS\\\\quan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_791">CUST_ADO_PATH"\\\\SimpleTTS\\\\quan2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_792">CUST_ADO_PATH"\\\\SimpleTTS\\\\quan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_793">CUST_ADO_PATH"\\\\SimpleTTS\\\\quan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_794">CUST_ADO_PATH"\\\\SimpleTTS\\\\que1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_795">CUST_ADO_PATH"\\\\SimpleTTS\\\\que2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_796">CUST_ADO_PATH"\\\\SimpleTTS\\\\que4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_797">CUST_ADO_PATH"\\\\SimpleTTS\\\\qun1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_798">CUST_ADO_PATH"\\\\SimpleTTS\\\\qun2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_799">CUST_ADO_PATH"\\\\SimpleTTS\\\\ran2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_800">CUST_ADO_PATH"\\\\SimpleTTS\\\\ran3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_801">CUST_ADO_PATH"\\\\SimpleTTS\\\\rang2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_802">CUST_ADO_PATH"\\\\SimpleTTS\\\\rang3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_803">CUST_ADO_PATH"\\\\SimpleTTS\\\\rang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_804">CUST_ADO_PATH"\\\\SimpleTTS\\\\rao2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_805">CUST_ADO_PATH"\\\\SimpleTTS\\\\rao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_806">CUST_ADO_PATH"\\\\SimpleTTS\\\\rao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_807">CUST_ADO_PATH"\\\\SimpleTTS\\\\re3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_808">CUST_ADO_PATH"\\\\SimpleTTS\\\\re4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_809">CUST_ADO_PATH"\\\\SimpleTTS\\\\ren2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_810">CUST_ADO_PATH"\\\\SimpleTTS\\\\ren3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_811">CUST_ADO_PATH"\\\\SimpleTTS\\\\ren4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_812">CUST_ADO_PATH"\\\\SimpleTTS\\\\reng1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_813">CUST_ADO_PATH"\\\\SimpleTTS\\\\reng2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_814">CUST_ADO_PATH"\\\\SimpleTTS\\\\ri4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_815">CUST_ADO_PATH"\\\\SimpleTTS\\\\rong2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_816">CUST_ADO_PATH"\\\\SimpleTTS\\\\rong3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_817">CUST_ADO_PATH"\\\\SimpleTTS\\\\rou2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_818">CUST_ADO_PATH"\\\\SimpleTTS\\\\rou4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_819">CUST_ADO_PATH"\\\\SimpleTTS\\\\ru2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_820">CUST_ADO_PATH"\\\\SimpleTTS\\\\ru3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_821">CUST_ADO_PATH"\\\\SimpleTTS\\\\ru4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_822">CUST_ADO_PATH"\\\\SimpleTTS\\\\ruan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_823">CUST_ADO_PATH"\\\\SimpleTTS\\\\rui2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_824">CUST_ADO_PATH"\\\\SimpleTTS\\\\rui3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_825">CUST_ADO_PATH"\\\\SimpleTTS\\\\rui4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_826">CUST_ADO_PATH"\\\\SimpleTTS\\\\run4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_827">CUST_ADO_PATH"\\\\SimpleTTS\\\\ruo4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_828">CUST_ADO_PATH"\\\\SimpleTTS\\\\sa1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_829">CUST_ADO_PATH"\\\\SimpleTTS\\\\sa3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_830">CUST_ADO_PATH"\\\\SimpleTTS\\\\sa4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_831">CUST_ADO_PATH"\\\\SimpleTTS\\\\sai1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_832">CUST_ADO_PATH"\\\\SimpleTTS\\\\sai4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_833">CUST_ADO_PATH"\\\\SimpleTTS\\\\san1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_834">CUST_ADO_PATH"\\\\SimpleTTS\\\\san3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_835">CUST_ADO_PATH"\\\\SimpleTTS\\\\san4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_836">CUST_ADO_PATH"\\\\SimpleTTS\\\\sang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_837">CUST_ADO_PATH"\\\\SimpleTTS\\\\sang3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_838">CUST_ADO_PATH"\\\\SimpleTTS\\\\sang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_839">CUST_ADO_PATH"\\\\SimpleTTS\\\\sao1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_840">CUST_ADO_PATH"\\\\SimpleTTS\\\\sao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_841">CUST_ADO_PATH"\\\\SimpleTTS\\\\sao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_842">CUST_ADO_PATH"\\\\SimpleTTS\\\\se4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_843">CUST_ADO_PATH"\\\\SimpleTTS\\\\sen1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_844">CUST_ADO_PATH"\\\\SimpleTTS\\\\seng1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_845">CUST_ADO_PATH"\\\\SimpleTTS\\\\sha1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_846">CUST_ADO_PATH"\\\\SimpleTTS\\\\sha3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_847">CUST_ADO_PATH"\\\\SimpleTTS\\\\sha4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_848">CUST_ADO_PATH"\\\\SimpleTTS\\\\shai1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_849">CUST_ADO_PATH"\\\\SimpleTTS\\\\shai4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_850">CUST_ADO_PATH"\\\\SimpleTTS\\\\shan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_851">CUST_ADO_PATH"\\\\SimpleTTS\\\\shan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_852">CUST_ADO_PATH"\\\\SimpleTTS\\\\shan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_853">CUST_ADO_PATH"\\\\SimpleTTS\\\\shang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_854">CUST_ADO_PATH"\\\\SimpleTTS\\\\shang3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_855">CUST_ADO_PATH"\\\\SimpleTTS\\\\shang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_856">CUST_ADO_PATH"\\\\SimpleTTS\\\\shang5.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_857">CUST_ADO_PATH"\\\\SimpleTTS\\\\shao1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_858">CUST_ADO_PATH"\\\\SimpleTTS\\\\shao2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_859">CUST_ADO_PATH"\\\\SimpleTTS\\\\shao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_860">CUST_ADO_PATH"\\\\SimpleTTS\\\\shao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_861">CUST_ADO_PATH"\\\\SimpleTTS\\\\she1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_862">CUST_ADO_PATH"\\\\SimpleTTS\\\\she2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_863">CUST_ADO_PATH"\\\\SimpleTTS\\\\she3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_864">CUST_ADO_PATH"\\\\SimpleTTS\\\\she4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_865">CUST_ADO_PATH"\\\\SimpleTTS\\\\shei2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_866">CUST_ADO_PATH"\\\\SimpleTTS\\\\shen1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_867">CUST_ADO_PATH"\\\\SimpleTTS\\\\shen2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_868">CUST_ADO_PATH"\\\\SimpleTTS\\\\shen3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_869">CUST_ADO_PATH"\\\\SimpleTTS\\\\shen4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_870">CUST_ADO_PATH"\\\\SimpleTTS\\\\sheng1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_871">CUST_ADO_PATH"\\\\SimpleTTS\\\\sheng2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_872">CUST_ADO_PATH"\\\\SimpleTTS\\\\sheng3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_873">CUST_ADO_PATH"\\\\SimpleTTS\\\\sheng4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_874">CUST_ADO_PATH"\\\\SimpleTTS\\\\shi1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_875">CUST_ADO_PATH"\\\\SimpleTTS\\\\shi2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_876">CUST_ADO_PATH"\\\\SimpleTTS\\\\shi3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_877">CUST_ADO_PATH"\\\\SimpleTTS\\\\shi4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_878">CUST_ADO_PATH"\\\\SimpleTTS\\\\shi5.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_879">CUST_ADO_PATH"\\\\SimpleTTS\\\\shou1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_880">CUST_ADO_PATH"\\\\SimpleTTS\\\\shou3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_881">CUST_ADO_PATH"\\\\SimpleTTS\\\\shou4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_882">CUST_ADO_PATH"\\\\SimpleTTS\\\\shu1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_883">CUST_ADO_PATH"\\\\SimpleTTS\\\\shu2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_884">CUST_ADO_PATH"\\\\SimpleTTS\\\\shu3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_885">CUST_ADO_PATH"\\\\SimpleTTS\\\\shu4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_886">CUST_ADO_PATH"\\\\SimpleTTS\\\\shua1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_887">CUST_ADO_PATH"\\\\SimpleTTS\\\\shua3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_888">CUST_ADO_PATH"\\\\SimpleTTS\\\\shuai1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_889">CUST_ADO_PATH"\\\\SimpleTTS\\\\shuai3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_890">CUST_ADO_PATH"\\\\SimpleTTS\\\\shuai4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_891">CUST_ADO_PATH"\\\\SimpleTTS\\\\shuan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_892">CUST_ADO_PATH"\\\\SimpleTTS\\\\shuan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_893">CUST_ADO_PATH"\\\\SimpleTTS\\\\shuang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_894">CUST_ADO_PATH"\\\\SimpleTTS\\\\shuang3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_895">CUST_ADO_PATH"\\\\SimpleTTS\\\\shui2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_896">CUST_ADO_PATH"\\\\SimpleTTS\\\\shui3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_897">CUST_ADO_PATH"\\\\SimpleTTS\\\\shui4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_898">CUST_ADO_PATH"\\\\SimpleTTS\\\\shun3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_899">CUST_ADO_PATH"\\\\SimpleTTS\\\\shun4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_900">CUST_ADO_PATH"\\\\SimpleTTS\\\\shuo1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_901">CUST_ADO_PATH"\\\\SimpleTTS\\\\shuo4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_902">CUST_ADO_PATH"\\\\SimpleTTS\\\\si1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_903">CUST_ADO_PATH"\\\\SimpleTTS\\\\si3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_904">CUST_ADO_PATH"\\\\SimpleTTS\\\\si4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_905">CUST_ADO_PATH"\\\\SimpleTTS\\\\song1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_906">CUST_ADO_PATH"\\\\SimpleTTS\\\\song3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_907">CUST_ADO_PATH"\\\\SimpleTTS\\\\song4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_908">CUST_ADO_PATH"\\\\SimpleTTS\\\\sou1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_909">CUST_ADO_PATH"\\\\SimpleTTS\\\\sou3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_910">CUST_ADO_PATH"\\\\SimpleTTS\\\\sou4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_911">CUST_ADO_PATH"\\\\SimpleTTS\\\\su1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_912">CUST_ADO_PATH"\\\\SimpleTTS\\\\su2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_913">CUST_ADO_PATH"\\\\SimpleTTS\\\\su4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_914">CUST_ADO_PATH"\\\\SimpleTTS\\\\suan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_915">CUST_ADO_PATH"\\\\SimpleTTS\\\\suan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_916">CUST_ADO_PATH"\\\\SimpleTTS\\\\sui1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_917">CUST_ADO_PATH"\\\\SimpleTTS\\\\sui2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_918">CUST_ADO_PATH"\\\\SimpleTTS\\\\sui3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_919">CUST_ADO_PATH"\\\\SimpleTTS\\\\sui4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_920">CUST_ADO_PATH"\\\\SimpleTTS\\\\sun1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_921">CUST_ADO_PATH"\\\\SimpleTTS\\\\sun3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_922">CUST_ADO_PATH"\\\\SimpleTTS\\\\suo1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_923">CUST_ADO_PATH"\\\\SimpleTTS\\\\suo3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_924">CUST_ADO_PATH"\\\\SimpleTTS\\\\ta1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_925">CUST_ADO_PATH"\\\\SimpleTTS\\\\ta3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_926">CUST_ADO_PATH"\\\\SimpleTTS\\\\ta4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_927">CUST_ADO_PATH"\\\\SimpleTTS\\\\tai1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_928">CUST_ADO_PATH"\\\\SimpleTTS\\\\tai2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_929">CUST_ADO_PATH"\\\\SimpleTTS\\\\tai4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_930">CUST_ADO_PATH"\\\\SimpleTTS\\\\tan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_931">CUST_ADO_PATH"\\\\SimpleTTS\\\\tan2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_932">CUST_ADO_PATH"\\\\SimpleTTS\\\\tan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_933">CUST_ADO_PATH"\\\\SimpleTTS\\\\tan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_934">CUST_ADO_PATH"\\\\SimpleTTS\\\\tang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_935">CUST_ADO_PATH"\\\\SimpleTTS\\\\tang2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_936">CUST_ADO_PATH"\\\\SimpleTTS\\\\tang3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_937">CUST_ADO_PATH"\\\\SimpleTTS\\\\tang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_938">CUST_ADO_PATH"\\\\SimpleTTS\\\\tao1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_939">CUST_ADO_PATH"\\\\SimpleTTS\\\\tao2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_940">CUST_ADO_PATH"\\\\SimpleTTS\\\\tao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_941">CUST_ADO_PATH"\\\\SimpleTTS\\\\tao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_942">CUST_ADO_PATH"\\\\SimpleTTS\\\\te4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_943">CUST_ADO_PATH"\\\\SimpleTTS\\\\teng2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_944">CUST_ADO_PATH"\\\\SimpleTTS\\\\ti1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_945">CUST_ADO_PATH"\\\\SimpleTTS\\\\ti2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_946">CUST_ADO_PATH"\\\\SimpleTTS\\\\ti3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_947">CUST_ADO_PATH"\\\\SimpleTTS\\\\ti4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_948">CUST_ADO_PATH"\\\\SimpleTTS\\\\tian1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_949">CUST_ADO_PATH"\\\\SimpleTTS\\\\tian2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_950">CUST_ADO_PATH"\\\\SimpleTTS\\\\tian3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_951">CUST_ADO_PATH"\\\\SimpleTTS\\\\tian4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_952">CUST_ADO_PATH"\\\\SimpleTTS\\\\tiao1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_953">CUST_ADO_PATH"\\\\SimpleTTS\\\\tiao2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_954">CUST_ADO_PATH"\\\\SimpleTTS\\\\tiao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_955">CUST_ADO_PATH"\\\\SimpleTTS\\\\tiao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_956">CUST_ADO_PATH"\\\\SimpleTTS\\\\tie1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_957">CUST_ADO_PATH"\\\\SimpleTTS\\\\tie3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_958">CUST_ADO_PATH"\\\\SimpleTTS\\\\tie4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_959">CUST_ADO_PATH"\\\\SimpleTTS\\\\ting1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_960">CUST_ADO_PATH"\\\\SimpleTTS\\\\ting2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_961">CUST_ADO_PATH"\\\\SimpleTTS\\\\ting3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_962">CUST_ADO_PATH"\\\\SimpleTTS\\\\tong1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_963">CUST_ADO_PATH"\\\\SimpleTTS\\\\tong2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_964">CUST_ADO_PATH"\\\\SimpleTTS\\\\tong3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_965">CUST_ADO_PATH"\\\\SimpleTTS\\\\tong4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_966">CUST_ADO_PATH"\\\\SimpleTTS\\\\tou1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_967">CUST_ADO_PATH"\\\\SimpleTTS\\\\tou2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_968">CUST_ADO_PATH"\\\\SimpleTTS\\\\tou3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_969">CUST_ADO_PATH"\\\\SimpleTTS\\\\tou4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_970">CUST_ADO_PATH"\\\\SimpleTTS\\\\tu1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_971">CUST_ADO_PATH"\\\\SimpleTTS\\\\tu2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_972">CUST_ADO_PATH"\\\\SimpleTTS\\\\tu3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_973">CUST_ADO_PATH"\\\\SimpleTTS\\\\tu4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_974">CUST_ADO_PATH"\\\\SimpleTTS\\\\tuan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_975">CUST_ADO_PATH"\\\\SimpleTTS\\\\tuan2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_976">CUST_ADO_PATH"\\\\SimpleTTS\\\\tuan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_977">CUST_ADO_PATH"\\\\SimpleTTS\\\\tuan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_978">CUST_ADO_PATH"\\\\SimpleTTS\\\\tui1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_979">CUST_ADO_PATH"\\\\SimpleTTS\\\\tui2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_980">CUST_ADO_PATH"\\\\SimpleTTS\\\\tui3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_981">CUST_ADO_PATH"\\\\SimpleTTS\\\\tui4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_982">CUST_ADO_PATH"\\\\SimpleTTS\\\\tun1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_983">CUST_ADO_PATH"\\\\SimpleTTS\\\\tun2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_984">CUST_ADO_PATH"\\\\SimpleTTS\\\\tun3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_985">CUST_ADO_PATH"\\\\SimpleTTS\\\\tuo1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_986">CUST_ADO_PATH"\\\\SimpleTTS\\\\tuo2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_987">CUST_ADO_PATH"\\\\SimpleTTS\\\\tuo3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_988">CUST_ADO_PATH"\\\\SimpleTTS\\\\tuo4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_989">CUST_ADO_PATH"\\\\SimpleTTS\\\\wa1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_990">CUST_ADO_PATH"\\\\SimpleTTS\\\\wa2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_991">CUST_ADO_PATH"\\\\SimpleTTS\\\\wa3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_992">CUST_ADO_PATH"\\\\SimpleTTS\\\\wa4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_993">CUST_ADO_PATH"\\\\SimpleTTS\\\\wai1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_994">CUST_ADO_PATH"\\\\SimpleTTS\\\\wai4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_995">CUST_ADO_PATH"\\\\SimpleTTS\\\\wan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_996">CUST_ADO_PATH"\\\\SimpleTTS\\\\wan2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_997">CUST_ADO_PATH"\\\\SimpleTTS\\\\wan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_998">CUST_ADO_PATH"\\\\SimpleTTS\\\\wan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_999">CUST_ADO_PATH"\\\\SimpleTTS\\\\wang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1000">CUST_ADO_PATH"\\\\SimpleTTS\\\\wang2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1001">CUST_ADO_PATH"\\\\SimpleTTS\\\\wang3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1002">CUST_ADO_PATH"\\\\SimpleTTS\\\\wang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1003">CUST_ADO_PATH"\\\\SimpleTTS\\\\wei1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1004">CUST_ADO_PATH"\\\\SimpleTTS\\\\wei2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1005">CUST_ADO_PATH"\\\\SimpleTTS\\\\wei3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1006">CUST_ADO_PATH"\\\\SimpleTTS\\\\wei4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1007">CUST_ADO_PATH"\\\\SimpleTTS\\\\wen1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1008">CUST_ADO_PATH"\\\\SimpleTTS\\\\wen2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1009">CUST_ADO_PATH"\\\\SimpleTTS\\\\wen3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1010">CUST_ADO_PATH"\\\\SimpleTTS\\\\wen4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1011">CUST_ADO_PATH"\\\\SimpleTTS\\\\weng1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1012">CUST_ADO_PATH"\\\\SimpleTTS\\\\weng3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1013">CUST_ADO_PATH"\\\\SimpleTTS\\\\weng4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1014">CUST_ADO_PATH"\\\\SimpleTTS\\\\wo1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1015">CUST_ADO_PATH"\\\\SimpleTTS\\\\wo3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1016">CUST_ADO_PATH"\\\\SimpleTTS\\\\wo4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1017">CUST_ADO_PATH"\\\\SimpleTTS\\\\wu1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1018">CUST_ADO_PATH"\\\\SimpleTTS\\\\wu2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1019">CUST_ADO_PATH"\\\\SimpleTTS\\\\wu3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1020">CUST_ADO_PATH"\\\\SimpleTTS\\\\wu4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1021">CUST_ADO_PATH"\\\\SimpleTTS\\\\xi1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1022">CUST_ADO_PATH"\\\\SimpleTTS\\\\xi2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1023">CUST_ADO_PATH"\\\\SimpleTTS\\\\xi3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1024">CUST_ADO_PATH"\\\\SimpleTTS\\\\xi4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1025">CUST_ADO_PATH"\\\\SimpleTTS\\\\xia1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1026">CUST_ADO_PATH"\\\\SimpleTTS\\\\xia2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1027">CUST_ADO_PATH"\\\\SimpleTTS\\\\xia4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1028">CUST_ADO_PATH"\\\\SimpleTTS\\\\xian1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1029">CUST_ADO_PATH"\\\\SimpleTTS\\\\xian2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1030">CUST_ADO_PATH"\\\\SimpleTTS\\\\xian3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1031">CUST_ADO_PATH"\\\\SimpleTTS\\\\xian4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1032">CUST_ADO_PATH"\\\\SimpleTTS\\\\xiang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1033">CUST_ADO_PATH"\\\\SimpleTTS\\\\xiang2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1034">CUST_ADO_PATH"\\\\SimpleTTS\\\\xiang3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1035">CUST_ADO_PATH"\\\\SimpleTTS\\\\xiang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1036">CUST_ADO_PATH"\\\\SimpleTTS\\\\xiao1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1037">CUST_ADO_PATH"\\\\SimpleTTS\\\\xiao2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1038">CUST_ADO_PATH"\\\\SimpleTTS\\\\xiao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1039">CUST_ADO_PATH"\\\\SimpleTTS\\\\xiao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1040">CUST_ADO_PATH"\\\\SimpleTTS\\\\xie1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1041">CUST_ADO_PATH"\\\\SimpleTTS\\\\xie2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1042">CUST_ADO_PATH"\\\\SimpleTTS\\\\xie3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1043">CUST_ADO_PATH"\\\\SimpleTTS\\\\xie4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1044">CUST_ADO_PATH"\\\\SimpleTTS\\\\xin1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1045">CUST_ADO_PATH"\\\\SimpleTTS\\\\xin4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1046">CUST_ADO_PATH"\\\\SimpleTTS\\\\xing1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1047">CUST_ADO_PATH"\\\\SimpleTTS\\\\xing2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1048">CUST_ADO_PATH"\\\\SimpleTTS\\\\xing3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1049">CUST_ADO_PATH"\\\\SimpleTTS\\\\xing4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1050">CUST_ADO_PATH"\\\\SimpleTTS\\\\xiong1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1051">CUST_ADO_PATH"\\\\SimpleTTS\\\\xiong2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1052">CUST_ADO_PATH"\\\\SimpleTTS\\\\xiu1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1053">CUST_ADO_PATH"\\\\SimpleTTS\\\\xiu3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1054">CUST_ADO_PATH"\\\\SimpleTTS\\\\xiu4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1055">CUST_ADO_PATH"\\\\SimpleTTS\\\\xu1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1056">CUST_ADO_PATH"\\\\SimpleTTS\\\\xu2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1057">CUST_ADO_PATH"\\\\SimpleTTS\\\\xu3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1058">CUST_ADO_PATH"\\\\SimpleTTS\\\\xu4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1059">CUST_ADO_PATH"\\\\SimpleTTS\\\\xu5.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1060">CUST_ADO_PATH"\\\\SimpleTTS\\\\xuan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1061">CUST_ADO_PATH"\\\\SimpleTTS\\\\xuan2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1062">CUST_ADO_PATH"\\\\SimpleTTS\\\\xuan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1063">CUST_ADO_PATH"\\\\SimpleTTS\\\\xuan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1064">CUST_ADO_PATH"\\\\SimpleTTS\\\\xue1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1065">CUST_ADO_PATH"\\\\SimpleTTS\\\\xue2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1066">CUST_ADO_PATH"\\\\SimpleTTS\\\\xue3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1067">CUST_ADO_PATH"\\\\SimpleTTS\\\\xue4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1068">CUST_ADO_PATH"\\\\SimpleTTS\\\\xun1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1069">CUST_ADO_PATH"\\\\SimpleTTS\\\\xun2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1070">CUST_ADO_PATH"\\\\SimpleTTS\\\\xun4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1071">CUST_ADO_PATH"\\\\SimpleTTS\\\\ya1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1072">CUST_ADO_PATH"\\\\SimpleTTS\\\\ya2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1073">CUST_ADO_PATH"\\\\SimpleTTS\\\\ya3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1074">CUST_ADO_PATH"\\\\SimpleTTS\\\\ya4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1075">CUST_ADO_PATH"\\\\SimpleTTS\\\\yan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1076">CUST_ADO_PATH"\\\\SimpleTTS\\\\yan2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1077">CUST_ADO_PATH"\\\\SimpleTTS\\\\yan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1078">CUST_ADO_PATH"\\\\SimpleTTS\\\\yan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1079">CUST_ADO_PATH"\\\\SimpleTTS\\\\yang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1080">CUST_ADO_PATH"\\\\SimpleTTS\\\\yang2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1081">CUST_ADO_PATH"\\\\SimpleTTS\\\\yang3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1082">CUST_ADO_PATH"\\\\SimpleTTS\\\\yang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1083">CUST_ADO_PATH"\\\\SimpleTTS\\\\yao1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1084">CUST_ADO_PATH"\\\\SimpleTTS\\\\yao2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1085">CUST_ADO_PATH"\\\\SimpleTTS\\\\yao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1086">CUST_ADO_PATH"\\\\SimpleTTS\\\\yao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1087">CUST_ADO_PATH"\\\\SimpleTTS\\\\ye1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1088">CUST_ADO_PATH"\\\\SimpleTTS\\\\ye2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1089">CUST_ADO_PATH"\\\\SimpleTTS\\\\ye3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1090">CUST_ADO_PATH"\\\\SimpleTTS\\\\ye4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1091">CUST_ADO_PATH"\\\\SimpleTTS\\\\yi1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1092">CUST_ADO_PATH"\\\\SimpleTTS\\\\yi2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1093">CUST_ADO_PATH"\\\\SimpleTTS\\\\yi3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1094">CUST_ADO_PATH"\\\\SimpleTTS\\\\yi4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1095">CUST_ADO_PATH"\\\\SimpleTTS\\\\yin1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1096">CUST_ADO_PATH"\\\\SimpleTTS\\\\yin2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1097">CUST_ADO_PATH"\\\\SimpleTTS\\\\yin3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1098">CUST_ADO_PATH"\\\\SimpleTTS\\\\yin4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1099">CUST_ADO_PATH"\\\\SimpleTTS\\\\ying1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1100">CUST_ADO_PATH"\\\\SimpleTTS\\\\ying2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1101">CUST_ADO_PATH"\\\\SimpleTTS\\\\ying3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1102">CUST_ADO_PATH"\\\\SimpleTTS\\\\ying4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1103">CUST_ADO_PATH"\\\\SimpleTTS\\\\yo1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1104">CUST_ADO_PATH"\\\\SimpleTTS\\\\yo5.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1105">CUST_ADO_PATH"\\\\SimpleTTS\\\\yong1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1106">CUST_ADO_PATH"\\\\SimpleTTS\\\\yong2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1107">CUST_ADO_PATH"\\\\SimpleTTS\\\\yong3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1108">CUST_ADO_PATH"\\\\SimpleTTS\\\\yong4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1109">CUST_ADO_PATH"\\\\SimpleTTS\\\\you1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1110">CUST_ADO_PATH"\\\\SimpleTTS\\\\you2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1111">CUST_ADO_PATH"\\\\SimpleTTS\\\\you3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1112">CUST_ADO_PATH"\\\\SimpleTTS\\\\you4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1113">CUST_ADO_PATH"\\\\SimpleTTS\\\\yu1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1114">CUST_ADO_PATH"\\\\SimpleTTS\\\\yu2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1115">CUST_ADO_PATH"\\\\SimpleTTS\\\\yu3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1116">CUST_ADO_PATH"\\\\SimpleTTS\\\\yu4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1117">CUST_ADO_PATH"\\\\SimpleTTS\\\\yuan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1118">CUST_ADO_PATH"\\\\SimpleTTS\\\\yuan2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1119">CUST_ADO_PATH"\\\\SimpleTTS\\\\yuan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1120">CUST_ADO_PATH"\\\\SimpleTTS\\\\yuan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1121">CUST_ADO_PATH"\\\\SimpleTTS\\\\yue1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1122">CUST_ADO_PATH"\\\\SimpleTTS\\\\yue4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1123">CUST_ADO_PATH"\\\\SimpleTTS\\\\yun1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1124">CUST_ADO_PATH"\\\\SimpleTTS\\\\yun2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1125">CUST_ADO_PATH"\\\\SimpleTTS\\\\yun3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1126">CUST_ADO_PATH"\\\\SimpleTTS\\\\yun4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1127">CUST_ADO_PATH"\\\\SimpleTTS\\\\za1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1128">CUST_ADO_PATH"\\\\SimpleTTS\\\\za2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1129">CUST_ADO_PATH"\\\\SimpleTTS\\\\za3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1130">CUST_ADO_PATH"\\\\SimpleTTS\\\\zai1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1131">CUST_ADO_PATH"\\\\SimpleTTS\\\\zai3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1132">CUST_ADO_PATH"\\\\SimpleTTS\\\\zai4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1133">CUST_ADO_PATH"\\\\SimpleTTS\\\\zan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1134">CUST_ADO_PATH"\\\\SimpleTTS\\\\zan2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1135">CUST_ADO_PATH"\\\\SimpleTTS\\\\zan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1136">CUST_ADO_PATH"\\\\SimpleTTS\\\\zan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1137">CUST_ADO_PATH"\\\\SimpleTTS\\\\zang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1138">CUST_ADO_PATH"\\\\SimpleTTS\\\\zang3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1139">CUST_ADO_PATH"\\\\SimpleTTS\\\\zang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1140">CUST_ADO_PATH"\\\\SimpleTTS\\\\zao1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1141">CUST_ADO_PATH"\\\\SimpleTTS\\\\zao2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1142">CUST_ADO_PATH"\\\\SimpleTTS\\\\zao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1143">CUST_ADO_PATH"\\\\SimpleTTS\\\\zao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1144">CUST_ADO_PATH"\\\\SimpleTTS\\\\ze2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1145">CUST_ADO_PATH"\\\\SimpleTTS\\\\ze4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1146">CUST_ADO_PATH"\\\\SimpleTTS\\\\zei2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1147">CUST_ADO_PATH"\\\\SimpleTTS\\\\zen3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1148">CUST_ADO_PATH"\\\\SimpleTTS\\\\zen4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1149">CUST_ADO_PATH"\\\\SimpleTTS\\\\zeng1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1150">CUST_ADO_PATH"\\\\SimpleTTS\\\\zeng4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1151">CUST_ADO_PATH"\\\\SimpleTTS\\\\zha1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1152">CUST_ADO_PATH"\\\\SimpleTTS\\\\zha2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1153">CUST_ADO_PATH"\\\\SimpleTTS\\\\zha3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1154">CUST_ADO_PATH"\\\\SimpleTTS\\\\zha4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1155">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhai1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1156">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhai2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1157">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhai3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1158">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhai4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1159">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1160">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1161">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1162">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1163">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhang3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1164">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1165">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhao1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1166">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhao3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1167">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhao4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1168">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhe1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1169">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhe2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1170">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhe3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1171">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhe4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1172">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhe5.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1173">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhen1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1174">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhen3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1175">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhen4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1176">CUST_ADO_PATH"\\\\SimpleTTS\\\\zheng1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1177">CUST_ADO_PATH"\\\\SimpleTTS\\\\zheng3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1178">CUST_ADO_PATH"\\\\SimpleTTS\\\\zheng4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1179">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhi1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1180">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhi2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1181">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhi3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1182">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhi4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1183">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhong1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1184">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhong3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1185">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhong4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1186">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhou1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1187">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhou2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1188">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhou3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1189">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhou4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1190">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhu1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1191">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhu2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1192">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhu3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1193">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhu4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1194">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhua1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1195">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhuai4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1196">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhuan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1197">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhuan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1198">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhuan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1199">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhuang1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1200">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhuang4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1201">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhui1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1202">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhui4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1203">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhun1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1204">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhun3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1205">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhuo1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1206">CUST_ADO_PATH"\\\\SimpleTTS\\\\zhuo2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1207">CUST_ADO_PATH"\\\\SimpleTTS\\\\zi1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1208">CUST_ADO_PATH"\\\\SimpleTTS\\\\zi3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1209">CUST_ADO_PATH"\\\\SimpleTTS\\\\zi4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1210">CUST_ADO_PATH"\\\\SimpleTTS\\\\zong1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1211">CUST_ADO_PATH"\\\\SimpleTTS\\\\zong3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1212">CUST_ADO_PATH"\\\\SimpleTTS\\\\zong4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1213">CUST_ADO_PATH"\\\\SimpleTTS\\\\zou1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1214">CUST_ADO_PATH"\\\\SimpleTTS\\\\zou3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1215">CUST_ADO_PATH"\\\\SimpleTTS\\\\zou4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1216">CUST_ADO_PATH"\\\\SimpleTTS\\\\zu1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1217">CUST_ADO_PATH"\\\\SimpleTTS\\\\zu2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1218">CUST_ADO_PATH"\\\\SimpleTTS\\\\zu3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1219">CUST_ADO_PATH"\\\\SimpleTTS\\\\zuan1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1220">CUST_ADO_PATH"\\\\SimpleTTS\\\\zuan3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1221">CUST_ADO_PATH"\\\\SimpleTTS\\\\zuan4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1222">CUST_ADO_PATH"\\\\SimpleTTS\\\\zui3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1223">CUST_ADO_PATH"\\\\SimpleTTS\\\\zui4.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1224">CUST_ADO_PATH"\\\\SimpleTTS\\\\zun1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1225">CUST_ADO_PATH"\\\\SimpleTTS\\\\zun3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1226">CUST_ADO_PATH"\\\\SimpleTTS\\\\zuo1.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1227">CUST_ADO_PATH"\\\\SimpleTTS\\\\zuo2.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1228">CUST_ADO_PATH"\\\\SimpleTTS\\\\zuo3.amr"</AUDIO>
    <AUDIO id="AUD_ID_SIMPLE_TTS_1229">CUST_ADO_PATH"\\\\SimpleTTS\\\\zuo4.amr"</AUDIO>
#endif

<!----------------------------------------------------------------------------------------
******** Timer 
------------------------------------------------------------------------------------------>

    <TIMER id="TIMER_PROFILES_ALERT_PLAY"/>
    <TIMER id="MDI_AUDIO_PLAYER_TEXT_TIMER"/>
    <TIMER id="MDI_AUDIO_CRESCENDO_TIMER"/>

<!----------------------------------------------------------------------------------------
******** Callback Manager 
------------------------------------------------------------------------------------------>
    <EVENT id="EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND" type="SENDER"/>
    <EVENT id="EVT_ID_MDI_AUDIO_PRE_MODE_SWITCH" type="SENDER"/>
    <EVENT id="EVT_ID_MDI_AUDIO_MODE_SWITCHED" type="SENDER"/>

    <RECEIVER id="EVT_ID_SRV_SHUTDOWN_HANDLER_RESET" proc="mdi_audio_cb_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SHUTDOWN_DEINIT" proc="mdi_audio_cb_evt_hdlr"/>
    <RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_IN" proc="mdi_audio_cb_evt_hdlr"/>
    <RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_OUT" proc="mdi_audio_cb_evt_hdlr"/>
    
</APP>
