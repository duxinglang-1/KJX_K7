/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *  vapp_widget_mre.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the MRE widget's resources.
 *
 * Author:
 * -------
 *  Cheng-Hung Ko (mtk01585)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 07 17 2012 ch.ko
 * [MAUI_03163831] [DLUI] Check-in patch
 * Revise codes.
 *
 * 07 10 2012 ch.ko
 * [MAUI_03211939] [UE] the launcher does not restore when we plug out USB
 * Check-in patch and revise codes.
 *
 * 06 15 2012 cathytr.huang
 * [MAUI_03183719] [DLUI] Revise code
 * .
 *
 * 05 17 2012 cathytr.huang
 * [MAUI_03183719] [DLUI] Revise code
 * .
 *
 * 05 16 2012 cathytr.huang
 * [MAUI_03183719] [DLUI] Revise code
 * .
 *
 * 05 04 2012 ch.ko
 * [MAUI_03163831] [DLUI] Check-in patch
 * Revise ASM usage.
 *
 * 04 24 2012 ch.ko
 * [MAUI_03163831] [DLUI] Check-in patch
 * Check-in MRE widget memory model patch.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_MRE__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "CustResDef.h"


/*****************************************************************************
 * XML
 *****************************************************************************/

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_WIDGET_MRE"
     name="STR_ID_VAPP_WIDGET_MRE"
     type="venus"
     hidden_in_mainmenu="true">

    <!-- System Resource Area-------------------------------------------------->

#if defined(__MMI_VUI_WIDGET_MRE_MEM_SIZE__)
    <MEMORY base="__MMI_VUI_WIDGET_MRE_MEM_SIZE__"/>
#else
    #if defined(__MMI_MAINLCD_480X800__)
        <MEMORY base="1800 * 1024"/>
    #elif defined(__MMI_MAINLCD_320X480__)
        <MEMORY base="1420 * 1024"/>
    #elif defined(__MMI_MAINLCD_240X400__)
        <MEMORY base="1420 * 1024"/>
    #elif defined(__MMI_MAINLCD_240X320__)
        <MEMORY base="1420 * 1024"/>
    #endif
#endif


    <!----- Screen Resource Area ---------------------------------------------->

    <SCREEN id="GRP_ID_VAPP_WIDGET_MRE_ASM"/>


    <!-- String Resource Area-------------------------------------------------->

    <STRING id="STR_ID_VAPP_WIDGET_MRE"/>
    <STRING id="STR_ID_VAPP_WIDGET_MRE_CANNOT_LOAD_WIDGET"/>
    <STRING id="STR_ID_VAPP_WIDGET_MRE_REMOVE_SOME_WIDGETS_FIRST"/>


    <!-- Image Resource Area--------------------------------------------------->
    #define WIDGET_IMG_ROOT       RES_IMG_ROOT"\\\\Widget\\\\"

    <IMAGE id="IMG_ID_VAPP_WIDGET_MRE_NOT_AVAILABLE_BG">WIDGET_IMG_ROOT"Widget_BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MRE_MEMORY_CARD_PLUG_OUT">WIDGET_IMG_ROOT"Card.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MRE_USB_MASS_STORAGE_MODE">WIDGET_IMG_ROOT"USB.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MRE_UNKNOWN_ERROR">WIDGET_IMG_ROOT"Others.png"</IMAGE>


    <!-- Event Area (Sender) -------------------------------------------------->


    <!-- Event Area (Receiver) ------------------------------------------------>

    <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidgetMreFactoryPublisher"/>

</APP>

#endif /* defined(__MMI_VUI_WIDGET_MRE__) */

