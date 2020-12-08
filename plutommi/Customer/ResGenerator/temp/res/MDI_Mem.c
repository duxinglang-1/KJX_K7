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
 *   MDI_Mem.res
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
 * 08 08 2012 cathytr.huang
 * [MAUI_03222813] [MT6250] [Twitter/FB V2] Camera capture wallpaper reduce memory
 * .
 *
 * 06 21 2012 stella.yang
 * [MAUI_03205867] YouTube PGDL - MP4SP QVGA mode
 * .
 *
 * 03 21 2012 cathytr.huang
 * [MAUI_01960881] [MED][CAM] Revise code
 * .
 *
 * 03 21 2012 cathytr.huang
 * [MAUI_01960881] [MED][CAM] Revise code
 * .
 *
 * 03 19 2012 cathytr.huang
 * [MAUI_03101854] Video Clipper Check In
 * .
 *
 * 03 01 2012 cathytr.huang
 * [MAUI_03134625] [Non-W1208MP Features Issues][Camcorder][Autorama]Pop up "error" msg. on Zoon in Max
 * .
 *
 * 02 23 2012 cathytr.huang
 * [MAUI_03135884] [New feature] MAV check-in
 * .
 *
 * 02 22 2012 cathytr.huang
 * [MAUI_03020886] [MDI][CAM] Revise code
 * .
 *
 * 02 21 2012 cathytr.huang
 * [MAUI_03126180] [contact]failed to preview caller picture
 * .
 *
 * 12 23 2011 stella.yang
 * [MAUI_03080711] [New design] Support .mkv files and subtitle
 * .
 *
 * 12 20 2011 cathytr.huang
 * [MAUI_03101854] Video Clipper Check In
 * .
 *
 * 11 11 2011 stella.yang
 * [MAUI_03056122] [New Feautre] MBBMS cosmos support
 * .
 *
 * 10 20 2011 cathytr.huang
 * [MAUI_03058082] [HAL Rule 5]: Non-HAL MUST NOT refer to HAL private stuffs![MAUI.11B.W11.41]
 * .
 *
 * 10 19 2011 stella.yang
 * [MAUI_03056122] [New Feautre] MBBMS cosmos support
 * .
 *
 * 09 02 2011 kinse.lin
 * [MAUI_03016315] [MPL Player] Support MPL Player in MED and also support OGG playback / record
 * .
 *
 * 08 11 2011 stella.yang
 * [MAUI_03003813] [COSMOS Boot Video and Video Wallpaper] check-in
 * .
 *
 * 07 08 2011 stella.yang
 * [MAUI_02969864] [Cosmos][Video] "Failed to play" pop up shows tearing.
 * .
 *
 * 07 07 2011 stella.yang
 * [MAUI_02979810] Add MDI_VDOPLY_INFO service ID
 * .
 *
 * 06 12 2011 stella.yang
 * [MAUI_02960313] [New Feature] mATV Cosmos
 * .
 *
 * 06 10 2011 stella.yang
 * [MAUI_02960313] [New Feature] mATV Cosmos
 * .
 *
 * 05 31 2011 vincent.cho
 * [MAUI_02953046] [Need Patch] [Sanity Fail] Sanity Test of MAUI_LUFFY76V22_DEMO_hspa(COSMOS_WVGA_11B).W11.23 is Fail!!
 * .
 *
 * 05 31 2011 macross.chen
 * [MAUI_02953371] Add CIF player support
 * .
 *
 * 05 31 2011 stella.yang
 * [MAUI_02953371] Add CIF player support
 * .
 *
 * 05 31 2011 tokiya.chang
 * [MAUI_02952824] [HAL] Check in for High Dynamic Range capture
 * .
 *
 * 05 25 2011 vincent.cho
 * [MAUI_02945250] [Fix Warning] 10A, 11A and MAUI.
 * .
 *
 * 05 19 2011 cathytr.huang
 * [MAUI_02928814] Slim project support
 * .
 *
 * 05 10 2011 cathytr.huang
 * [MAUI_02936213] Add capture VGA size below memory definition and scenario
 * .
 *
 * 05 10 2011 vincent.cho
 * [MAUI_02936068] [CIF recorder support] add CIF memory configuration for recorder
 * .
 *
 * 03 23 2011 vincent.cho
 * [MAUI_02900324] [COSMOS][Recorder] Can't save recording video while call interrupt.
 * .
 *
 * 03 16 2011 vincent.cho
 * [MAUI_02656002] The option show messy
 * .
 *
 * 03 06 2011 stella.yang
 * [MAUI_02886944] [HAL] remove chip compile option.
 * .
 *
 * 02 26 2011 macross.chen
 * [MAUI_02878807] [Cosmos] Provide m.youtube level VDOPLY service to Opera Browser and Web Widget
 * video streaming part check in.
 *
 * 02 25 2011 stella.yang
 * [MAUI_02878807] [Cosmos] Provide m.youtube level VDOPLY service to Opera Browser and Web Widget
 * .
 *
 * 02 24 2011 cathytr.huang
 * [MAUI_02841129] [HAL] MED CAM check in
 * .
 *
 * 01 24 2011 cathytr.huang
 * [MAUI_02841129] [HAL] MED CAM check in
 * .
 *
 * 01 18 2011 cathytr.huang
 * [MAUI_02841091] [Cosmos] Webcam check in
 * .
 *
 * 12 27 2010 tokiya.chang
 * [MAUI_02840772] [HAL] video hal check-in W1049
 * .
 *
 * 12 08 2010 tokiya.chang
 * [MAUI_02840772] [HAL] video hal check-in W1049
 * .
 *
 * 12 07 2010 vincent.cho
 * [MAUI_02846290] [MDI] HAL check in W10.50
 * .
 *
 * 12 07 2010 cathytr.huang
 * [MAUI_02846195] [MDI][MED] Support app ASM new memory allocation
 * .
 *
 * 12 05 2010 cs.kuo
 * [MAUI_02837403] Revise MDI interface to support ASM memory
 * .
 *
 * 12 05 2010 cs.kuo
 * [MAUI_02837403] Revise MDI interface to support ASM memory
 * .
 *
 * 12 03 2010 macross.chen
 * [MAUI_02840968] Check in MED new memory & App ID
 * .
 *
 * 12 01 2010 tokiya.chang
 * [MAUI_02836519] [MAUI] FTO check in
 * .
 *
 * 12 01 2010 stella.yang
 * [MAUI_02840968] Check in MED new memory & App ID
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "MMI_features.h" 

<?xml version="1.0" encoding="UTF-8"?>

#if defined(__MED_IN_ASM__)
<!----------------------------------------------------------------------------------------
******** MDI_AUDIO
------------------------------------------------------------------------------------------>
<APP id="SRV_MDI_AUDPLY" name="STR_MDI_AUDPLY">
    <MEMORY base="MED_AUD_PLY_BASE_MEM" fg="MED_AUD_PLY_FG_MEM" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_AUD_INFO" name="STR_MDI_AUD_INFO">
    <MEMORY base="MED_AUD_INFO_BASE_MEM" fg="MED_AUD_INFO_FG_MEM" inc="med_global.h"/>
</APP>


<!----------------------------------------------------------------------------------------
******** MDI_VIDEO 
------------------------------------------------------------------------------------------>

#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
<APP id="SRV_MDI_VDOPLY" name="STR_MDI_VDOPLY">
    <MEMORY base="MED_VDOPLY_BASE_MEM" fg="MED_VDOPLY_FG_MEM" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_VDOPLY_V" name="STR_MDI_VDOPLY_V">
    <MEMORY base="MED_VDOPLY_V_BASE_MEM" fg="MED_VDOPLY_V_FG_MEM" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_VDOPLY_A" name="STR_MDI_VDOPLY_A" >
    <MEMORY base="MED_VDOPLY_A_BASE_MEM" fg="MED_VDOPLY_A_FG_MEM" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_VDOPLY_QVGA" name="STR_MDI_VDOPLY_QVGA" >
    <MEMORY base="MED_VDOPLY_QVGA_BASE_MEM" fg="MED_VDOPLY_QVGA_FG_MEM" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_VDOPLY_CIF" name="STR_MDI_VDOPLY_CIF" >
    <MEMORY base="MED_VDOPLY_CIF_BASE_MEM" fg="MED_VDOPLY_CIF_FG_MEM" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_VDOPLY_PREVIEW" name="STR_MDI_VDOPLY_PREVIEW" >
    <MEMORY base="MED_VDOPLY_PREVIEW_BASE_MEM" fg="MED_VDOPLY_PREVIEW_FG_MEM" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_VDOPLY_INFO" name="STR_MDI_VDOPLY_INFO" >
    <MEMORY base="MED_VDOPLY_INFO_BASE_MEM" fg="MED_VDOPLY_INFO_FG_MEM" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_VDOPLY_MP4" name="STR_MDI_VDOPLY_MP4" >
    <MEMORY base="MED_VDOPLY_MP4_BASE_MEM" fg="MED_VDOPLY_MP4_FG_MEM" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_VDOPLY_SUBTITLE" name="STR_MDI_VDOPLY_SUBTITLE" >
    <MEMORY base="MED_VDOPLY_SUBTITLE_BASE_MEM" fg="MED_VDOPLY_SUBTITLE_FG_MEM" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_VDOPLY_QVGA_MPEG4SP" name="STR_MDI_VDOPLY_QVGA_MPEG4SP" >
    <MEMORY base="MED_VDOPLY_QVGA_MPEG4SP_BASE_MEM" fg="MED_VDOPLY_QVGA_MPEG4SP_FG_MEM" inc="med_global.h"/>
</APP>

#endif 

<!----------------------------------------------------------------------------------------
******** MDI_VIDEO_STREAMING
------------------------------------------------------------------------------------------>

#if defined(__MMI_VIDEO_STREAM__)
<APP id="SRV_MDI_STREAMING" name="STR_MDI_STREAMING">
    <MEMORY base="MED_STREAMING_BASE_MEM" fg="MED_STREAMING_FG_MEM" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_STREAMING_QVGA" name="STR_MDI_STREAMING_QVGA" >
    <MEMORY base="MED_STREAMING_QVGA_BASE_MEM" fg="MED_STREAMING_QVGA_FG_MEM" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_STREAMING_CIF" name="STR_MDI_STREAMING_CIF" >
    <MEMORY base="MED_STREAMING_CIF_BASE_MEM" fg="MED_STREAMING_CIF_FG_MEM" inc="med_global.h"/>
</APP>
#endif


<!----------------------------------------------------------------------------------------
******** MDI_CAMERA 
------------------------------------------------------------------------------------------>

#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)
<APP id="SRV_MDI_CAMERA_STANDARD" name="STR_MDI_CAMERA_STANDARD">
    <MEMORY base="max(MAX_MED_CAM_CAP_EXT_MEM_SIZE, MAX_MED_CAM_PREVIEW_EXT_MEM_SIZE)" fg="0" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_CAMERA_FULL" name="STR_MDI_CAMERA_FULL">
    <MEMORY base="max(max(max(max(MAX_MED_CAM_CAP_EXT_MEM_SIZE, MAX_MED_CAM_PREVIEW_EXT_MEM_SIZE) + MED_CAM_BG_STITCH_EXT_MEM_SIZE,MED_CAM_PANORAMA_STITCH_SIZE), MAX_CAM_HDR_EXT_MEM_SIZE), MAX_CAM_MAV_WORKING_EXT_MEM_SIZE)" fg="0" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_CAMERA_ONLY_CAP_LCD" name="STR_MDI_CAMERA_ONLY_CAP_LCD">
    <MEMORY base="max(MAX_MED_CAM_CAP_LCD_EXT_MEM_SIZE, MAX_MED_CAM_PREVIEW_EXT_MEM_SIZE)" fg="0" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_CAMERA_ONLY_CAP_LCD_DISABLE_JAIA" name="STR_MDI_CAMERA_ONLY_CAP_LCD_DISABLE_JAIA">
    <MEMORY base="max(MIN_CAM_CAPTURE_LCD_ISP_BUF_SIZE, MAX_MED_CAM_PREVIEW_EXT_MEM_SIZE)" fg="0" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_CAMERA_CAP_VGA_BELOW" name="STR_MDI_CAMERA_CAP_VGA_BELOW">
    <MEMORY base="max(MAX_MED_CAM_CAP_VGA_EXT_MEM_SIZE, MAX_MED_CAM_PREVIEW_EXT_MEM_SIZE)" fg="0" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_CAMERA_AUTORAMA" name="STR_MDI_CAMERA_AUTORAMA">
    <MEMORY base="max(MAX_CAM_PREVIEW_EXT_MEM_SIZE + MED_CAM_BG_STITCH_EXT_MEM_SIZE,MED_CAM_PANORAMA_STITCH_SIZE)" fg="0" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_CAMERA_CAP_HDR" name="STR_MDI_CAMERA_CAP_HDR">
    <MEMORY base="max(max(MAX_MED_CAM_CAP_EXT_MEM_SIZE, MAX_MED_CAM_PREVIEW_EXT_MEM_SIZE), MAX_CAM_HDR_EXT_MEM_SIZE)" fg="0" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_CAMERA_CAP_MAV" name="STR_MDI_CAMERA_CAP_MAV">
    <MEMORY base="max(MAX_MED_CAM_PREVIEW_EXT_MEM_SIZE, MAX_CAM_MAV_WORKING_EXT_MEM_SIZE)" fg="0" inc="med_global.h"/>
</APP>
#endif

<!----------------------------------------------------------------------------------------
******** MDI_WEBCAM 
------------------------------------------------------------------------------------------>

#if defined(__MMI_WEBCAM__)
<APP id="SRV_MDI_WEBCAM" name="STR_MDI_WEBCAM">
    <MEMORY base="0" fg="MAX_MED_WEBCAM_EXT_MEM_SIZE" inc="med_global.h"/>
</APP>
#endif

<!----------------------------------------------------------------------------------------
******** MDI_VT
------------------------------------------------------------------------------------------>
#if defined(__MMI_VIDEO_TELEPHONY__)
<APP id="SRV_MDI_VT" name="STR_MDI_VT">
    <MEMORY base="MAX_VT_BASIC_MEM_SIZE" fg="0" inc="med_global.h"/>
</APP>
#endif 

<!----------------------------------------------------------------------------------------
******** MDI_VIDEO_RECORDER
------------------------------------------------------------------------------------------>

#if defined(__MMI_VIDEO_RECORDER__)|| defined(__MMI_CAMCORDER__)     
<APP id="SRV_MDI_VDOREC" name="STR_MDI_VDOREC">
    <MEMORY base="MAX_MED_VID_BG_EXT_MEM_SIZE" fg="MAX_MED_VID_ENC_EXT_MEM_SIZE" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_VDOREC_CIF" name="STR_MDI_VDOREC_CIF">
    <MEMORY base="MAX_MED_VID_BG_EXT_MEM_SIZE" fg="MAX_MED_VID_ENC_CIF_EXT_MEM_SIZE" inc="med_global.h"/>
</APP>
#endif

<!----------------------------------------------------------------------------------------
******** MDI_ATV
------------------------------------------------------------------------------------------>

#if defined(__MMI_ATV_SUPPORT__)
<APP id="SRV_MDI_ATV_REC" name="STR_MDI_ATV_REC">
    <MEMORY base="MED_ATV_REC_BASE_MEM" fg="MED_ATV_REC_FG_MEM" inc="med_global.h"/>
</APP>

<APP id="SRV_MDI_ATV" name="STR_MDI_ATV">
    <MEMORY base="MED_ATV_BASE_MEM" fg="MED_ATV_FG_MEM" inc="med_global.h"/>
</APP>

#endif

#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
<!----------------------------------------------------------------------------------------
******** MDI_MTV
------------------------------------------------------------------------------------------>
<APP id="SRV_MDI_MTV" name="STR_MDI_MTV">
    <MEMORY base="MED_MTV_BASE_MEM" fg="MED_MTV_FG_MEM" inc="med_global.h"/>
</APP>

<!----------------------------------------------------------------------------------------
******** MDI_MBBMS_ESG
------------------------------------------------------------------------------------------>
<APP id="SRV_MDI_MBBMS_ESG" name="STR_MDI_MBBMS_ESG">
    <MEMORY base="MBBMS_ESG_MEM_SIZE" fg="0" inc="med_global.h"/>
</APP>

#endif 

#if defined(__MMI_VIDEO_CLIPPER__)
<!----------------------------------------------------------------------------------------
******** MDI_VIDEO_CLIPPER
------------------------------------------------------------------------------------------>
<APP id="SRV_MDI_VDOCLIP" name="STR_MDI_VDOCLIP">
    <MEMORY base="0" fg="MED_VID_CLIP_EXT_MEM_BUFFER_SIZE" inc="med_vid_clip_mem_def.h"/>
</APP>
#endif 

#endif //__MED_IN_ASM__
