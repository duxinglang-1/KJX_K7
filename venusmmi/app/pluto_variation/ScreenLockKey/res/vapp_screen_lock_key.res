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
 *  vapp_screen_lock_key.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 * Yiping Xie (mtk80652)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 06 15 2012 yiping.xie
 * [MAUI_03203299] [Widgets] [w12.24.p55] Performance becomes poor after setting widget on idle
 * .
 *
 * 05 21 2012 yiping.xie
 * [MAUI_03176582] [key launcher][locker]push notification check in
 * .
 *
 * 05 21 2012 yiping.xie
 * [MAUI_03176582] [key launcher][locker]push notification check in
 * .
 *
 * 04 05 2012 yiping.xie
 * [MAUI_03149969] [Opera] [1] Assert fail: gdi_layer.c 1199 - VRT
 * .
 *
 * 03 31 2012 yiping.xie
 * [MAUI_03158822] [Known Issue] icon is not in proper place in the lock screen
 * .
 *
 * 03 29 2012 yiping.xie
 * [MAUI_03137863] [Key Launcher]
 * .image reduce
 *
 * 03 07 2012 yiping.xie
 * [MAUI_03137863] [Key Launcher]
 * .
 *
 * 02 21 2012 yiping.xie
 * [MAUI_03134160] [Key Launcher]Check in new feature - Key launcher
 * .
 *
 * 
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "MMI_features.h" 

#if defined(__MMI_VUI_SCREEN_LOCK_KEY__) || defined(__MMI_VUI_LAUNCHER_KEY__)

#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_VENUS_SCREEN_LOCK_KEY" type="venus" name ="STR_ID_SCREEN_LOCK_KEY_NAME">


<MEMORY heap="0" fg="$(VFX_SYS_MEM_DEFAULT_SCR_ASM_SIZE)+$(VFX_SYS_MEM_VRT_SIZE)" inc="vfx_sys_config.h"/>

/* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
<!--Include Area-->
<INCLUDE file="GlobalResDef.h"/>

#define LOCK_KEY_PATH       CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\ScreenLockKey\\\\"
#define LOCK_COMMON_PATH    CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Common\\\\"
#ifdef __MMI_NCENTER_SUPPORT__
#define LOCK_PN_PATH        CUST_IMG_PATH"\\\\MainLCD\\\\NCenter\\\\Icons\\\\"
#endif


<!-- 
**************************************** String section ***************************************
-->
    <STRING id="STR_ID_SCREEN_LOCK_KEY_NAME"/>

<!-- 
**************************************** Image section ****************************************
-->


    /* time images */
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_TIME_NUM_0">LOCK_KEY_PATH"time_0.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_TIME_NUM_1">LOCK_KEY_PATH"time_1.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_TIME_NUM_2">LOCK_KEY_PATH"time_2.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_TIME_NUM_3">LOCK_KEY_PATH"time_3.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_TIME_NUM_4">LOCK_KEY_PATH"time_4.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_TIME_NUM_5">LOCK_KEY_PATH"time_5.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_TIME_NUM_6">LOCK_KEY_PATH"time_6.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_TIME_NUM_7">LOCK_KEY_PATH"time_7.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_TIME_NUM_8">LOCK_KEY_PATH"time_8.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_TIME_NUM_9">LOCK_KEY_PATH"time_9.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_TIME_NUM_COLON">LOCK_KEY_PATH"time_colon.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_TIME_NUM_BG">LOCK_KEY_PATH"up_glass.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_TIME_AM">LOCK_KEY_PATH"time_AM.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_TIME_PM">LOCK_KEY_PATH"time_PM.png"</IMAGE>

#ifdef __MMI_VUI_SCREEN_LOCK_KEY__

    /* background images */
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_BG_MAIN">LOCK_KEY_PATH"BG.jpg"</IMAGE>
    //<IMAGE id="IMG_ID_VAPP_SCRLOCK_BG_BAR">LOCK_COMMON_PATH"ann.9slice.png"</IMAGE>

    /* centry */
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_UNLOCK_LOCK">LOCK_KEY_PATH"lock.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_GLASS_CENTRY">LOCK_KEY_PATH"c_glass.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_GLASS_CENTRY_BIG">LOCK_KEY_PATH"c_glass_big.png"</IMAGE>

    /* up */
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_UNLOCK_HOME">LOCK_KEY_PATH"Home.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_UNLOCK_BG_HOME">LOCK_KEY_PATH"down_up_glass.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_GLASS_UP_SELECT">LOCK_KEY_PATH"down_up_glass_select3.png"</IMAGE>

    /* left */
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_UNLOCK_CALL">LOCK_KEY_PATH"Call.png"</IMAGE>
     <IMAGE id="IMG_ID_VAPP_SCRLOCK_UNLOCK_BG_CALL">LOCK_KEY_PATH"down_left_glass.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_GLASS_LEFT_SELECT">LOCK_KEY_PATH"down_left_glass_select3.png"</IMAGE>

    /* right */
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_UNLOCK_MSG">LOCK_KEY_PATH"Message.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_UNLOCK_BG_MSG">LOCK_KEY_PATH"down_right_glass.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_GLASS_RIGHT_SELECT">LOCK_KEY_PATH"down_right_glass_select3.png"</IMAGE>

    /* arrow images */
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_ARROW_UP">LOCK_KEY_PATH"down_up_arrows.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_ARROW_LEFT">LOCK_KEY_PATH"down_left_arrows.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCRLOCK_ARROW_RIGHT">LOCK_KEY_PATH"down_right_arrows.png"</IMAGE>

    #ifdef __MMI_NCENTER_SUPPORT__
        <IMAGE id="IMG_ID_VAPP_SCRLOCK_PN_BG">LOCK_KEY_PATH"Lock_notify.9slice.png"</IMAGE>
        <IMAGE id="IMG_ID_VAPP_SCRLOCK_PN_CALL">LOCK_PN_PATH"icon_call_miss.png"</IMAGE>
        <IMAGE id="IMG_ID_VAPP_SCRLOCK_PN_MSG">LOCK_PN_PATH"icon_msg_unread.png"</IMAGE>
        <IMAGE id="IMG_ID_VAPP_SCRLOCK_PN_MAIL">LOCK_PN_PATH"icon_email_unread.png"</IMAGE>
        <IMAGE id="IMG_ID_VAPP_SCRLOCK_PN_SNS">LOCK_PN_PATH"SNS.png"</IMAGE>
        <IMAGE id="IMG_ID_VAPP_SCRLOCK_PN_MRE">LOCK_PN_PATH"mre.png"</IMAGE>
    #endif

#endif

</APP>

#endif /* __MMI_VUI_SCREEN_LOCK_KEY__ */


