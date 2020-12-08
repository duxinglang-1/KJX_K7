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
 *  vapp_op02_mm.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the OP02 mainmenu screen specific APP resources.
 *
 * Author:
 * -------
 *  Guoyi Zhao (mtk80128)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 07 04 2011 guoyi.zhao
 * [MAUI_02976199] [CU]手机音乐和音乐播放器的图标一样
 * .
 *
 * 06 15 2011 guoyi.zhao
 * [MAUI_02960551] CU2.0 Cosmos mainmenu check in
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "CustResDef.h"

#ifdef __OP02_0200__

<?xml version="1.0" encoding="UTF-8"?>

#ifdef BROWSER_SUPPORT
<!--Mobile internet in mainmenu-->
<APP id = "VAPP_MOBILE_INTERNET" package_name="native.mtk.mobile_internet"
    name = "STR_ID_VAPP_MOBILE_INTERNET" img="IMG_ID_VAPP_MOBILE_INTERNET"
    launch="vapp_mobile_internet_launch">

    <STRING id="STR_ID_VAPP_MOBILE_INTERNET"/>
    <IMAGE id="IMG_ID_VAPP_MOBILE_INTERNET">RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\MO.png"</IMAGE>
</APP>

<!--Online sales in mainmenu-->
<APP id = "VAPP_ONLINE_SALES" package_name="native.mtk.online_sales"
    name = "STR_ID_VAPP_ONLINE_SALES" img="IMG_ID_VAPP_ONLINE_SALES"
    launch="vapp_online_sales_launch">

    <STRING id="STR_ID_VAPP_ONLINE_SALES"/>
    <IMAGE id="IMG_ID_VAPP_ONLINE_SALES">RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\OS.png"</IMAGE>
</APP>

<!--Wo read in mainmenu-->
<APP id = "VAPP_WO_READ" package_name="native.mtk.wo_read"
    name = "STR_ID_VAPP_WO_READ" img="IMG_ID_VAPP_WO_READ"
    launch="vapp_wo_read_launch">

    <STRING id="STR_ID_VAPP_WO_READ"/>
    <IMAGE id="IMG_ID_VAPP_WO_READ">RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\READ.png"</IMAGE>
</APP>
#endif /* BROWSER_SUPPORT */

#ifdef __MMI_OP02_MIDLET_WO_STORE__
<!--Wo store in mainmenu-->
<APP id = "VAPP_WO_STORE" package_name="native.mtk.wo_store"
    name = "STR_ID_VAPP_WO_STORE" img="IMG_ID_VAPP_WO_STORE"
    launch="vapp_wo_store_launch">

    <STRING id="STR_ID_VAPP_WO_STORE"/>
    <IMAGE id="IMG_ID_VAPP_WO_STORE">RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\STORE.png"</IMAGE>
</APP>
#endif

#ifdef __MMI_OP02_MIDLET_PUSH_MAIL__
<!--Push mail in mainmenu-->
<APP id = "VAPP_PUSH_MAIL" package_name="native.mtk.push_mail"
    name = "STR_ID_VAPP_PUSH_MAIL" img="IMG_ID_VAPP_PUSH_MAIL"
    launch="vapp_push_mail_launch">

    <STRING id="STR_ID_VAPP_PUSH_MAIL"/>
    <IMAGE id="IMG_ID_VAPP_PUSH_MAIL">RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\PushMail.png"</IMAGE>
</APP>
#endif

#ifdef __MMI_OP02_MIDLET_MOBILE_TV__
<!--Mobile TV in mainmenu-->
<APP id = "VAPP_MOBILE_TV" package_name="native.mtk.mobile_tv"
    name = "STR_ID_VAPP_MOBILE_TV" img="IMG_ID_VAPP_MOBILE_TV"
    launch="vapp_mobile_tv_launch">

    <STRING id="STR_ID_VAPP_MOBILE_TV"/>
    <IMAGE id="IMG_ID_VAPP_MOBILE_TV">RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\MobileTV.png"</IMAGE>
</APP>
#endif

#ifdef __MMI_OP02_MIDLET_MOBILE_MUSIC__
<!--Mobile music in mainmenu-->
<APP id = "VAPP_MOBILE_MUSIC" package_name="native.mtk.mobile_music"
    name = "STR_ID_VAPP_MOBILE_MUSIC" img="IMG_ID_VAPP_MOBILE_MUSIC"
    launch="vapp_mobile_music_launch">

    <STRING id="STR_ID_VAPP_MOBILE_MUSIC"/>
    <IMAGE id="IMG_ID_VAPP_MOBILE_MUSIC">RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\MobileMusic.png"</IMAGE>
</APP>
#endif

#ifdef __MMI_OP02_MIDLET_116114__
<!--116114 mobile guide in mainmenu-->
<APP id = "VAPP_MOBILE_GUIDE" package_name="native.mtk.mobile_guide"
    name = "STR_ID_VAPP_MOBILE_GUIDE" img="IMG_ID_VAPP_MOBILE_GUIDE"
    launch="vapp_116114_launch">

    <STRING id="STR_ID_VAPP_MOBILE_GUIDE"/>
    <IMAGE id="IMG_ID_VAPP_MOBILE_GUIDE">RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\116114.png"</IMAGE>
</APP>
#endif

#endif /* __OP02_0200__ */

