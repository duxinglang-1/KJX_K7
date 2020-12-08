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
 *  ImageClipCui.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Image Clip Cui resource file
 *
 * Author:
 * -------
 *  Boli Li (MTK81132)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 06 06 2012 boli.li
 * [MAUI_03195517] [check in] LQVGA zoom button
 * .
 *
 * 06 04 2012 boli.li
 * [MAUI_03193346] [Photo Art Enhancement]The loading icon is too large, not fit the QVGA resolution size
 * .
 *
 * 06 01 2012 boli.li
 * [MAUI_03192815] [Photo Art Enhancement]should quit clip when user plug out the memorycard
 * .
 *
 * 05 31 2012 boli.li
 * [MAUI_03195445] [check in] can't drag Ncenter
 * .
 *
 * 05 25 2012 boli.li
 * [MAUI_03191923] [check in] add preview behavior
 * .
 *
 * 05 22 2012 boli.li
 * [MAUI_03185933] [Check in] Image clip CUI check in
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
  ****************************************************************************/
#include "mmi_features.h"
#ifdef __MMI_IMAGE_CLIP_CUI__
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="CUI_IMAGE_CLIP" name = "STR_ID_IMAGE_CLIP_CUI_CAPTION">

<!--Include Area-->


<!--String Area-->
<STRING id="STR_ID_IMAGE_CLIP_CUI_CAPTION">Image Clip</STRING>
<STRING id="STR_ID_IMAGE_CLIP_IMAGE_DECODE_FAILED"></STRING>
<STRING id="STR_ID_IMAGE_CLIP_PLEASE_CLOSE_ANOTHER"></STRING>

<!--Image Area-->
<IMAGE id="IMG_ID_IMAGE_CLIP_BALL" >CUST_IMG_PATH"\\\\MainLCD\\\\ImageClip\\\\adjust_ball_n.png"</IMAGE>
<IMAGE id="IMG_ID_IMAGE_CLIP_BALL_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\ImageClip\\\\adjust_ball_hl.png"</IMAGE>
<IMAGE id="IMG_ID_IMAGE_CLIP_MASK">CUST_IMG_PATH"\\\\MainLCD\\\\ImageClip\\\\adjust_bar_bg.9slice.png"</IMAGE>
<IMAGE id="IMG_ID_IMAGE_CLIP_FRAME">CUST_IMG_PATH"\\\\MainLCD\\\\ImageClip\\\\crop_frame.9slice.png"</IMAGE>

<IMAGE id="IMG_ID_IMAGE_CLIP_ZOOM_IN">CUST_IMG_PATH"\\\\MainLCD\\\\ImageClip\\\\zi.png"</IMAGE>
<IMAGE id="IMG_ID_IMAGE_CLIP_ZOOM_IN_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\ImageClip\\\\zi_dis.png"</IMAGE>
<IMAGE id="IMG_ID_IMAGE_CLIP_ZOOM_OUT" >CUST_IMG_PATH"\\\\MainLCD\\\\ImageClip\\\\zo.png"</IMAGE>
<IMAGE id="IMG_ID_IMAGE_CLIP_ZOOM_OUT_DISABLE" >CUST_IMG_PATH"\\\\MainLCD\\\\ImageClip\\\\zo_dis.png"</IMAGE>

<IMAGE id="IMG_ID_IMAGE_CLIP_BUSY_ANIM">CUST_IMG_PATH"\\\\MainLCD\\\\ImageClip\\\\loading"</IMAGE>

#ifdef __MMI_FTE_SUPPORT__
<IMAGE id="IMG_ID_IMAGE_CLIP_BUSY_ANIM_BG">CUST_IMG_PATH"\\\\MainLCD\\\\ImageClip\\\\process_bg.9slice.png"</IMAGE>

#ifndef __MMI_ICON_BAR_SUPPORT__
<IMAGE id="IMG_ID_IMAGE_CLIP_ZOOM_IN_BG">CUST_IMG_PATH"\\\\MainLCD\\\\ImageClip\\\\zin_bg.9slice.png"</IMAGE>
<IMAGE id="IMG_ID_IMAGE_CLIP_ZOOM_IN_BG_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\ImageClip\\\\zin_bg_pressed.9slice.png"</IMAGE>

<IMAGE id="IMG_ID_IMAGE_CLIP_ZOOM_OUT_BG">CUST_IMG_PATH"\\\\MainLCD\\\\ImageClip\\\\zout_bg.9slice.png"</IMAGE>
<IMAGE id="IMG_ID_IMAGE_CLIP_ZOOM_OUT_BG_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\ImageClip\\\\zout_bg_pressed.9slice.png"</IMAGE>
#endif /* __MMI_ICON_BAR_SUPPORT__ */
#else /* __MMI_FTE_SUPPORT__ */
<IMAGE id="IMG_ID_IMAGE_CLIP_ZOOM_IN_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\ImageClip\\\\zi_down.png"</IMAGE>
<IMAGE id="IMG_ID_IMAGE_CLIP_ZOOM_OUT_DOWN" >CUST_IMG_PATH"\\\\MainLCD\\\\ImageClip\\\\zo_down.png"</IMAGE>
#endif /* __MMI_FTE_SUPPORT__ */

<!--Event Handler-->
<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="cui_image_clip_fmgr_notify_handler"/>

<!--SCREEN Area-->
<SCREEN id="SCR_ID_IMAGE_CLIP_MAIN"/>

<MEMORY heap="$(IMAGE_CLIP_MEM_SIZE)+ $(AUD_EXT_MEM_SIZE) + $(MTV_BG_RECORD_MEM_SIZE) + $(MAX_VRT_EXT_MEM_SIZE) + $(MAX_MED_MEDIACACHE_IES_EXT_MEM_SIZE)" 
        fg="$(IMAGE_CLIP_DECODE_LAYER_MEM_SIZE) + $(MAX_MED_JPG_DEC_EXT_MEM_SIZE)"
        inc="ImageClipCui.h, med_global.h, med_mem.h"/>
</APP>
#endif /* __MMI_IMAGE_CLIP_CUI__ */
