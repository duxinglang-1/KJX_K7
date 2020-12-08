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
 *  vapp_key_mainmenu_default_order.h
 *
 * Project:
 * --------
 *  Key launcher
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_KEY_MAINMENU_DEFAULT_ORDER_H__
#define __VAPP_KEY_MAINMENU_DEFAULT_ORDER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h"

// declaration
extern const mmi_app_package_name_struct vappKeyMainmenuDefaultOrder[];
extern const VfxS32 vappKeyMainmenuDefaultOrderCount;

#ifdef __VAPP_LAUNCHER_KEY_INSTANTIATE_DEFAULT_ORDER__

// definition
const mmi_app_package_name_struct vappKeyMainmenuDefaultOrder[] = 
{
#if defined(__OP01_3G__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    "native.mtk.op01_monternet",
    "native.mtk.op01_mobile_portal",
#ifdef __MMI_MOBILE_TV_CMMB_SUPPORT__
    "native.mtk.dtvplayer",
#endif
    "native.mtk.customerservice",
    "native.mtk.phonebookmanager",
    "native.mtk.myfavorite",
    "native.mtk.op01_fetion",
    "native.mtk.op01_mobile_market",
    "native.mtk.op01_139_push_mail",
    "native.mtk.op01_music_walkman",
    "native.mtk.op01_mobile_read",
    "native.mtk.op01_mobile_game",
    "native.mtk.op01_mobile_stock",
#endif
    "native.mtk.dialer",
    "native.mtk.messaging",
    // the page content
#ifdef __OP02_0200__
    "native.mtk.mobile_internet",
    "native.mtk.wo_store",
    "native.mtk.lemei",
    "native.mtk.online_sales",
#endif
#ifdef __MMI_MEDIA_PLAYER__
    "native.mtk.mediaplayer",
#endif
    "native.mtk.phonebook",
    "native.mtk.calllog",
#if defined(__MMI_YOUTUBE_SHORTCUT__)
	  "native.mtk.youtube",
#endif
    "native.mtk.calendar",
#if defined(__MMI_CAMCORDER__)
    "native.mtk.camcorder",
#endif
    "native.mtk.setting",
    "native.mtk.alarm",
    "native.mtk.imageviewer",
    "native.mtk.calculator",
    "native.mtk.filemgr",
    "native.mtk.sndrec",
    "native.mtk.connectivity",
#if defined(__MMI_TODOLIST__)
    "native.mtk.todo",
#endif
    "native.mtk.fmrdo",
    "native.mtk.worldclock",
    "native.mtk.services_sat",
    "",
    ""
};

const VfxS32 vappKeyMainmenuDefaultOrderCount = sizeof(vappKeyMainmenuDefaultOrder) / sizeof(mmi_app_package_name_struct);

#endif

#endif // __VAPP_KEY_MAINMENU_DEFAULT_ORDER_H__

