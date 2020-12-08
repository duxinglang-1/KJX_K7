/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vapp_widget_gallery.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the gallery widget's resources.
 *
 * Author:
 * -------
 *  Weilun Liu (mtk02772)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 05 31 2012 weilun.liu
 * [MAUI_03191173] [MP]Message: [1] Assert fail: vapp_gallery_data.cpp 1107 - MMI
 * show error pic if memory allocate fail
 *
 * 04 03 2012 weilun.liu
 * [MAUI_03162182] [Cosmos Slim]
 * wrap compile option on gallery widget
 *
 * 01 18 2012 ch.ko
 * [MAUI_03118855] Check-in Cosmos 2.0 launcher and screen lock
 * Check-in patch.
 *
 * 03 30 2011 weilun.liu
 * [MAUI_02904268] [Home][ScreenLock] Fix incorrect AP naming
 * rename app id
 *
 * 02 11 2011 weilun.liu
 * [MAUI_02868660] [COSMOS] checkin gallery widget
 * check in gallery widget.
 *
 * 02 11 2011 weilun.liu
 * [MAUI_02868660] [COSMOS] checkin gallery widget
 * check-in gallery widget
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_GALLERY__)

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "CustResDef.h"


/*****************************************************************************
 * XML
 *****************************************************************************/

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_WIDGET_GALLERY" type="venus">

    <!-- String Resource Area-------------------------------------------------->
    <STRING id="STR_ID_VAPP_WIDGET_GALLERY"/>

    <!-- Image Resource Area--------------------------------------------------->
    
    #define ROOT_PATH RES_IMG_ROOT"\\\\Widget\\\\Gallery\\\\"
    <IMAGE id="IMG_ID_VAPP_WIDGET_GALLERY_ERROR_INDICATOR">ROOT_PATH"default_issue.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_GALLERY_CONTROL_BAR_BG">ROOT_PATH"bg_widget.9slice.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_WIDGET_GALLERY_ICON">ROOT_PATH"Gallery.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_GALLERY_BTN_PAUSE">ROOT_PATH"btn_pause.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_GALLERY_BTN_REFRESH">ROOT_PATH"btn_refresh.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_GALLERY_BTN_VIEW">ROOT_PATH"btn_view.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_GALLERY_BTN_PLAY">ROOT_PATH"btn_play.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_GALLERY_BTN_SETTIG">ROOT_PATH"btn_setting.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_GALLERY_DE_COVER">ROOT_PATH"default_cover.jpg"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_GALLERY_PHOTO_BG">ROOT_PATH"photo_frame.png"</IMAGE>
    

    <!-- Event Area--------------------------------------------------->
    <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidgetGalleryPublisher"/>
</APP>

#endif /* defined(__MMI_VUI_WIDGET_GALLERY__) */

