/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_drawer_default_order.h
 *
 * Project:
 * --------
 *  Launcher
 *
 * Description:
 * ------------
 *  Launcher drawer
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_DRAWER_DEFAULT_ORDER_H__
#define __VAPP_DRAWER_DEFAULT_ORDER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h"

// declaration
extern const mmi_app_package_name_struct vappDrawerDefaultOrder[];
extern const VfxS32 vappDrawerDefaultOrderCount;

#ifdef __VAPP_DRAWER_INSTANTIATE_DEFAULT_ORDER__

// definition
const mmi_app_package_name_struct vappDrawerDefaultOrder[] = 
{
    // the shortcut bar
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    "native.mtk.dialer",
    "native.mtk.messaging",
    "native.mtk.desktop",
#else
    "native.mtk.dialer",
    "native.mtk.messaging",
    "native.mtk.mediaplayer",
    "native.mtk.desktop",
#endif
    
    // the page content
#ifdef __OP02_0200__
    "native.mtk.mobile_internet",
    "native.mtk.wo_store",
    "native.mtk.lemei",
    "native.mtk.online_sales",
#endif
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    "native.mtk.mediaplayer",
#endif
    "native.mtk.phonebook",
    "native.mtk.calllog",
    "native.mtk.calendar",
    "native.mtk.camcorder",
    "native.mtk.setting",
    "native.mtk.alarm",
    "native.mtk.browser",
    "native.mtk.imageviewer",
    "native.mtk.calculator",
    "native.mtk.filemgr",
    "native.mtk.sndrec",
    "native.mtk.connectivity",
    "native.mtk.todo",
    "native.mtk.fmrdo",
    "native.mtk.worldclock",
    "native.mtk.services_sat",
    "",
    ""
};

const VfxS32 vappDrawerDefaultOrderCount = sizeof(vappDrawerDefaultOrder) / sizeof(mmi_app_package_name_struct);

#endif

#endif // __VAPP_DRAWER_DEFAULT_ORDER_H__

