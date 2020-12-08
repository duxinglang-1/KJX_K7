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
 *   vapp_vol_dialog.res
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Volume Dialog resource file
 *
 * Author:
 * -------
 *   Kinse Lin (mtk01393)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision: $
 * $Modtime: $
 * $Log: $
 *
 * 12 25 2012 yufei.shen
 * [MAUI_03281920] Sound settings slim modify
 * DCM check in.
 *
 * 01 16 2012 yufei.shen
 * [MAUI_03116113] [audio]the side key can't adjust  the volume
 * .
 *
 * 11 01 2011 yufei.shen
 * [MAUI_03067569] "Ring volume"'s display in Thme 2 is abnormal
 * .
 *
 * 08 05 2011 yufei.shen
 * [MAUI_02998959] volume dialog pop up theme change
 * .
 *
 * 06 10 2011 kinse.lin
 * [MAUI_02959785] [Slider Phone] Slider Phone Side Key Support check in
 * .
 *
 * 03 04 2011 kinse.lin
 * [MAUI_02872682] # [Cosmos Todo] [FM Radio] Resource naming revise
 * .
 *
 * 02 22 2011 kinse.lin
 * [MAUI_02449395] Audio still heard when volume set to zero level
 * .
 *
 * 12 25 2010 kinse.lin
 * [MAUI_02850366] [COSMOS] check in to MAUI / IT branch
 * .
 *
 * 12 23 2010 shinn.lin
 * [MAUI_02852469] add type attribute for venus app in <APP> tag
 * .
 *
 * 12 15 2010 kinse.lin
 * [MAUI_02836756] [COSMOS] check in COSMOS code to MAUI
 * .
 *
 * 11 29 2010 kinse.lin
 * [MAUI_02836756] [COSMOS] check in COSMOS code to MAUI
 * .
 *
 * 11 28 2010 kinse.lin
 * [MAUI_02836756] [COSMOS] check in COSMOS code to MAUI
 * .
 *
 * 11 10 2010 kinse.lin
 * [MAUI_02836756] [COSMOS] check in COSMOS code to MAUI
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"
#include "custresdef.h"


<?xml version = "1.0" encoding = "UTF-8"?>
<APP id = "VAPP_VOL_DIALOG" name = "STR_VOL_DIALOG" type="venus">

<!-----------------------------------------------------String Section------------------------------------------------------>
    <STRING id="STR_ID_VAPP_VOL_DIALOG_RING"/>
    <STRING id="STR_ID_VAPP_VOL_DIALOG_MEDIA"/>
    <STRING id="STR_ID_VAPP_VOL_DIALOG_SPEECH"/>

<!-----------------------------------------------------Image Section------------------------------------------------------>

    <IMAGE id="IMG_ID_VAPP_VOL_DIALOG_MUTE" >CUST_IMG_PATH_ROOT"\\\\MainLCD\\\\Default\\\\Profile\\\\Mute.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_VOL_DIALOG_RING" >CUST_IMG_PATH_ROOT"\\\\MainLCD\\\\Default\\\\Profile\\\\Ring.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_VOL_DIALOG_VIB" >CUST_IMG_PATH_ROOT"\\\\MainLCD\\\\Default\\\\Profile\\\\Shock.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_VOL_DIALOG_VIB_RING" >CUST_IMG_PATH_ROOT"\\\\MainLCD\\\\Default\\\\Profile\\\\Shock_Ring.png"</IMAGE>

<!-----------------------------------------------------Event Section------------------------------------------------------>
    <EVENT id="EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE" type="SENDER"/>
    <EVENT id="EVT_ID_VOL_DIALOG_VIB_CHANGED" type="SENDER"/>
#ifdef __MMI_THEMES_APPLICATION__
    <RECEIVER id="EVT_ID_VAPP_THEME_CHANGED" proc="vapp_volume_dialog_theme_change"/>
#endif
    <RECEIVER id="EVT_ID_KEY_DEFAULT_HANDLER" proc="vapp_volume_dialog_vol"/>

</APP>
