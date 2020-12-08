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
 * 04 03 2012 weilun.liu
 * [MAUI_03162182] [Cosmos Slim]
 * wrap compile option on gallery widget
 *
 * 09 23 2011 weilun.liu
 * [MAUI_03036020] Support to change image per seconds in gallery widget
 * add 1s to slideshow interval time setting
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

<APP id="VAPP_WIDGET_GALLERY_SETTING" name="STR_ID_VAPP_WIDGET_GALLERY_SETTING" type="venus">
    <MEMORY heap="200*1024" cui="VCUI_FMGR"/>

    <!-- String Resource Area-------------------------------------------------->
    <STRING id="STR_ID_VAPP_WIDGET_GALLERY_SETTING_TITLE"/>
    <STRING id="STR_ID_VAPP_WIDGET_GALLERY_SETTING_INTERVAL_CELLL_TITLE"/>
    <STRING id="STR_ID_VAPP_WIDGET_GALLERY_SETTING_FILE_CELLL_TITLE"/>
    <STRING id="STR_ID_WIDGET_GALLERY_INTERVAL_1_SEC"/> 
    <STRING id="STR_ID_WIDGET_GALLERY_INTERVAL_10_SECS"/>    
    <STRING id="STR_ID_WIDGET_GALLERY_INTERVAL_30_SECS"/>
    <STRING id="STR_ID_WIDGET_GALLERY_INTERVAL_1_MIN"/>        
    <STRING id="STR_ID_WIDGET_GALLERY_INTERVAL_5_MINS"/>
    <STRING id="STR_ID_WIDGET_GALLERY_INTERVAL_10_MINS"/>
    <STRING id="STR_ID_WIDGET_GALLERY_INTERVAL_30_MINS"/>      


    <!-- Image Resource Area--------------------------------------------------->
    
    #define ROOT_PATH RES_IMG_ROOT"\\\\Widget\\\\"
    <IMAGE id="IMG_ID_VAPP_WIDGET_GALLERY_SETTING">ROOT_PATH""</IMAGE>

    <!------------------------------------------------------MMI Cache Resource---------------------------------------------------------->    
    <CACHEDATA type="byte" id="NVRAM_SETTING_SLIDE_SHOW_INTERVAL_TIME" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X03] </DEFAULT_VALUE>
        <DESCRIPTION> gallery widget slide show interval time </DESCRIPTION>
    </CACHEDATA>

    <!-- Event Area--------------------------------------------------->

</APP>

#endif
