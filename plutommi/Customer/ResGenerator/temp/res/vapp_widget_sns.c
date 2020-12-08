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
 *  vapp_widget_sns.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the sns widget's resources.
 *
 * Author:
 * -------
 *  Mason Lai (vend_yl00004)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 * 
 * 09 14 2012 mason.lai
 * [MAUI_03233769] [SNS] Solve build error
 * Move resource declartion from vapp_packages_res.h to mmi_lib_res_range_def.h.
 *
 * 06 14 2012 mason.lai
 * [MAUI_03202413] [Need Patch][Build Error] 11B.W12.24 build error for KHAN50_V11_DEMO_gprs(12864_COSMOS_QVGA_CN)
 * Fix Cosmos Slim build error.
 *
 * 05 31 2012 mason.lai
 * [MAUI_03133042] [SNS] Review widget code
 * Move sns widget codes from venusmmi/app/cosmos/widget to venusmmi/app/cosmos/sns.
 *
 * 05 07 2012 mason.lai
 * [MAUI_03133042] [SNS] Review widget code
 * Check in compile option for individual widgets.
 *
 * 03 21 2012 mason.lai
 * [MAUI_03153456] [1] Assert fail: vapp_gallery_cache.h 326 - MMI
 * Delcare fg memory.
 *
 * 03 20 2012 mason.lai
 * [MAUI_03152965] there are two SNS icon in the mainpage
 * Use correct package name.
 *
 * 03 19 2012 mason.lai
 * [MAUI_03128419] Message: [1] Fatal Error (0x2, 0xf3d1ca34) - MMI
 * Create a dummy app to exit sns service when OOM happens.
 *
 * 03 19 2012 mason.lai
 * [MAUI_03133042] [SNS] Review widget code
 * Extends extra base memory.
 *
 * 03 12 2012 mason.lai
 * [MAUI_03133042] [SNS] Review widget code
 * .
 *
 * 01 20 2012 vend_yl00004
 * [MAUI_03117726] SNS deep integration initial check-in
 * Apply to new widget architecture.
 *
 * 01 18 2012 vend_yl00004
 * [MAUI_03117726] SNS deep integration initial check-in
 * Check in SNS data storage service and widget.
 *
 * 01 17 2012 vend_yl00004
 * NULL
 * .
 *
 * 12 27 2011 vend_yl00004
 * NULL
 * .
 *
 * 12 06 2011 vend_yl00004
 * NULL
 * .
 *
 * 11 30 2011 vend_yl00004
 * NULL
 * .
 *
 * 11 08 2011 vend_yl00004
 * NULL
 * Check in sns widget.
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/
#include "CustResDef.h"


/*****************************************************************************
 * XML
 *****************************************************************************/

<?xml version="1.0" encoding="UTF-8"?>
#ifdef __MMI_VUI_HOMESCREEN_SNS__
#ifdef __COSMOS_MMI_PACKAGE__
<APP package_name="native.mtk.sns_widget" id="VAPP_WIDGET_SNS_COSMOS" name="STR_ID_VAPP_WIDGET_SNS_APP" type="venus" hidden_in_mainmenu="true">
	
    <MEMORY cui="max(VCUI_SNS_CONTACTS_PICKER)" fg="max(VAPP_GALLERY_ASYNC_MEDIALIST_L1_PREVIEW_FG_SIZE, VAPP_GALLERY_ASYNC_MEDIALIST_THUMB_FG_SIZE)" heap="500*1024" extra_base="VAPP_SNS_WIDGET_EXTRA_BASE_SIZE"/>
 
#ifdef __SOCIAL_NETWORK_SUPPORT__
    <APPCONCURRENT concurrent ="VAPP_WIDGET_SNS, VAPP_SNS_PLUGIN"/>
#endif
 
    <!-- String Resource Area-------------------------------------------------->
    <STRING id="STR_ID_VAPP_WIDGET_SNS_APP"/>
    <STRING id="STR_ID_VAPP_WIDGET_SNS1"/>
    <STRING id="STR_ID_VAPP_WIDGET_SNS2"/>
    <STRING id="STR_ID_VAPP_WIDGET_SNS_NO_DATA"/>
    <STRING id="STR_ID_VAPP_WIDGET_SNS_NO_ACCOUNT"/>
    <STRING id="STR_ID_VAPP_WIDGET_SNS_LOADING_DATA"/>
    <STRING id="STR_ID_VAPP_WIDGET_SNS_LOADING_FAILED"/>
    <STRING id="STR_ID_VAPP_WIDGET_SNS_TAP_TO_ADD"/>
    <STRING id="STR_ID_VAPP_WIDGET_SNS_ADD_CONTACT"/>
    <STRING id="STR_ID_VAPP_WIDGET_SNS_AT_MOST_CONTACT"/>
    <STRING id="STR_ID_VAPP_WIDGET_SNS_REMOVE_CONTACT"/>
    <STRING id="STR_ID_VAPP_WIDGET_SNS_EDIT_CONTACT"/>
    <STRING id="STR_ID_VAPP_WIDGET_SNS_SELECT_CONTACT"/>
    <STRING id="STR_ID_VAPP_WIDGET_SNS_MEMORY_CARD_NOT_EXIST"/>
    <STRING id="STR_ID_VAPP_WIDGET_SNS_IN_MS_MODE"/>
    <STRING id="STR_ID_VAPP_WIDGET_SNS_NO_ACTIVITIES"/>

    <!-- Image Resource Area--------------------------------------------------->
    
    #define ROOT_PATH RES_IMG_ROOT"\\\\Widget\\\\Sns\\\\"
#if defined (__MMI_VUI_WIDGET_SNS_STICKY__)    
    <IMAGE id="IMG_ID_VAPP_WIDGET_SNS_STICKTY_BG">ROOT_PATH"BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_SNS_ICON1">ROOT_PATH"Icon_SNS_widget2.png"</IMAGE>
#endif    
#if defined (__MMI_VUI_WIDGET_SNS_TABBAR__)          
    <IMAGE id="IMG_ID_VAPP_WIDGET_SNS_TAB_BG_BOTTOM">ROOT_PATH"Tab_BG_Bottom.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_SNS_TAB_BG_TOP">ROOT_PATH"Tab_BG_Top.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_SNS_TAB_BG_TOP_BORDER">ROOT_PATH"BG_Border.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_SNS_TAB_PERSON_SEL">ROOT_PATH"Tab_Person_Sel.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_SNS_TAB_PERSON_UNSEL">ROOT_PATH"Tab_Person_Unsel.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_SNS_TAB_SETTING">ROOT_PATH"Icon_Settings.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_SNS_ICON2">ROOT_PATH"Icon_SNS_widget1.png"</IMAGE>
#endif        

    <!-- Event Area--------------------------------------------------->
#if defined (__MMI_VUI_WIDGET_SNS_STICKY__)    
    <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidgetSnsStickyPublisher"/>
#endif    
#if defined (__MMI_VUI_WIDGET_SNS_TABBAR__)    
    <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidgetSnsTabBarPublisher"/>
#endif
</APP>
#endif /* __COSMOS_MMI_PACKAGE__ */
#endif /* __MMI_VUI_HOMESCREEN_SNS__ */
