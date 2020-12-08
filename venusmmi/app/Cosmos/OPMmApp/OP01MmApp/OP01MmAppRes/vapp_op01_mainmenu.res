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
 *  vapp_op01_mm.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the OP01 mainmenu screen specific APP resources.
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
 * 09 19 2011 guoyi.zhao
 * [MAUI_03030080] Operator cosmos mainmenu check in
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "CustResDef.h"

#ifdef __OP01_3G__

<?xml version="1.0" encoding="UTF-8"?>

#ifdef BROWSER_SUPPORT
<!--Mobile portal in mainmenu-->
<APP id = "VAPP_MOBILE_PORTAL" package_name="native.mtk.mobile_portal"
    name = "STR_ID_VAPP_MOBILE_PORTAL" img="IMG_ID_VAPP_MOBILE_PORTAL"
    launch="vapp_mobile_portal_launch">

    <STRING id="STR_ID_VAPP_MOBILE_PORTAL"/>
    <IMAGE id="IMG_ID_VAPP_MOBILE_PORTAL">RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\10086.png"</IMAGE>
</APP>
#endif /* BROWSER_SUPPORT */

#ifdef __MMI_OP01_MIDLET_FETION__
<!--Fetion in mainmenu-->
<APP id = "VAPP_FETION" package_name="native.mtk.fetion"
    name = "STR_ID_VAPP_FETION" img="IMG_ID_VAPP_FETION"
    launch="vapp_fetion_launch">

    <STRING id="STR_ID_VAPP_FETION"/>
    <IMAGE id="IMG_ID_VAPP_FETION">RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\Fetion.png"</IMAGE>
</APP>
#endif

#ifdef __MMI_OP01_MIDLET_MUSIC_WALKMAN__
<!--Music walkman in mainmenu-->
<APP id = "VAPP_MUSIC_WALKMAN" package_name="native.mtk.music_walkman"
    name = "STR_ID_VAPP_MUSIC_WALKMAN" img="IMG_ID_VAPP_MUSIC_WALKMAN"
    launch="vapp_music_walkman_launch">

    <STRING id="STR_ID_VAPP_MUSIC_WALKMAN"/>
    <IMAGE id="IMG_ID_VAPP_MUSIC_WALKMAN">RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\MusicWalkman.png"</IMAGE>
</APP>
#endif

#ifdef __MMI_OP01_MIDLET_MOBILE_STOCK__
<!--Mobile stock in mainmenu-->
<APP id = "VAPP_MOBILE_STOCK" package_name="native.mtk.mobile_stock"
    name = "STR_ID_VAPP_MOBILE_STOCK" img="IMG_ID_VAPP_MOBILE_STOCK"
    launch="vapp_mobile_stock_launch">

    <STRING id="STR_ID_VAPP_MOBILE_STOCK"/>
    <IMAGE id="IMG_ID_VAPP_MOBILE_STOCK">RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\MobileStock.png"</IMAGE>
</APP>
#endif

#ifdef __MMI_OP01_MIDLET_MOBILE_MAP__
<!--Mobile map in mainmenu-->
<APP id = "VAPP_MOBILE_MAP" package_name="native.mtk.mobile_map"
    name = "STR_ID_VAPP_MOBILE_MAP" img="IMG_ID_VAPP_MOBILE_MAP"
    launch="vapp_mobile_map_launch">

    <STRING id="STR_ID_VAPP_MOBILE_MAP"/>
    <IMAGE id="IMG_ID_VAPP_MOBILE_MAP">RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\MobileMap.png"</IMAGE>
</APP>
#endif

#ifdef __MMI_OP01_MIDLET_MOBILE_MARKET__
<!--Mobile market in mainmenu-->
<APP id = "VAPP_MOBILE_MARKET" package_name="native.mtk.mobile_market"
    name = "STR_ID_VAPP_MOBILE_MARKET" img="IMG_ID_VAPP_MOBILE_MARKET"
    launch="vapp_mobile_market_launch">

    <STRING id="STR_ID_VAPP_MOBILE_MARKET"/>
    <IMAGE id="IMG_ID_VAPP_MOBILE_MARKET">RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\MobileMarket.png"</IMAGE>
</APP>
#endif

#ifdef __MMI_OP01_MIDLET_MOBILE_READ__
<!--Mobile read in mainmenu-->
<APP id = "VAPP_MOBILE_READ" package_name="native.mtk.mobile_read"
    name = "STR_ID_VAPP_MOBILE_READER" img="IMG_ID_VAPP_MOBILE_READ"
    launch="vapp_mobile_read_launch">

    <STRING id="STR_ID_VAPP_MOBILE_READER"/>
    <IMAGE id="IMG_ID_VAPP_MOBILE_READ">RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\MobileRead.png"</IMAGE>
</APP>
#endif

#endif /* __OP01_3G__ */

