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
 *  vapp_wallpaper_mre.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the MRE wallpaper's resources.
 *
 * Author:
 * -------
 *  Stella Yang (mtk01564)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 * 
 * 07 27 2012 stella.yang
 * [MAUI_03218706] [iBingo]Fatal Error (0x4, 0xe00dc30c) - MMI, Caller Address: 0xe00d8bd0
 * .
 * 
 * 07 27 2012 stella.yang
 * [MAUI_03218706] [iBingo]Fatal Error (0x4, 0xe00dc30c) - MMI, Caller Address: 0xe00d8bd0
 * .
 *
 * 07 09 2012 stella.yang
 * [MAUI_03212723] [1] Assert fail: Caller Address: 0x100a2d18 Line: 7949 - MMI [Scenario.c]
 * .
 *
 * 05 04 2012 stella.yang
 * [MAUI_03177248] Fatal Error (0x1, 0xf8646191) - MMI
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_WALLPAPER_MRE__)

/*****************************************************************************
 * Include
 *****************************************************************************/


/*****************************************************************************
 * XML
 *****************************************************************************/

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_WALLPAPER_MRE"
     name="STR_ID_VAPP_WALLPAPER_MRE"
     type="venus"
     hidden_in_mainmenu="true">

    <!-- System Resource Area-------------------------------------------------->

#if defined(__MMI_MAINLCD_480X800__)
    <MEMORY base="600 * 1024"/>
#elif defined(__MMI_MAINLCD_320X480__)
    <MEMORY base="320 * 1024"/>
#elif defined(__MMI_MAINLCD_240X400__)
    <MEMORY base="320 * 1024"/>
#elif defined(__MMI_MAINLCD_240X320__)
    <MEMORY base="320 * 1024"/>
#endif
    <!----- Screen Resource Area ---------------------------------------------->

    <SCREEN id="GRP_ID_VAPP_WALLPAPER_MRE_ASM"/>


    <!-- String Resource Area-------------------------------------------------->

    <STRING id="STR_ID_VAPP_WALLPAPER_MRE"/>

</APP>

#endif /* defined(__MMI_VUI_WALLPAPER_MRE__) */

