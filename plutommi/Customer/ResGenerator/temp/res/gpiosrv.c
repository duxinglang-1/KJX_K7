/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 *  gpiosrv.res
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Resource file.
 *
 * Author:
 * -------
 *  Fachao Zhang (MTK80513)
 *
 *                      
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 05 16 2012 fachao.zhang
 * [MAUI_03185928] CAT 2.0 support
 * .
 *
 * 03 27 2012 fachao.zhang
 * [MAUI_03157060] Move Timer define from global file to own app res file
 * .
 *
 * 02 21 2012 fachao.zhang
 * [MAUI_03134160] [Key Launcher]Check in new feature - Key launcher
 * .
 *
 * 10 18 2011 fachao.zhang
 * [MAUI_03053667] The brightness is still 3
 * .
 *
 * 07 08 2011 fachao.zhang
 * [MAUI_02980078] [CABC] Check in for Luffy76 reworking
 * .
 *
 * 06 08 2011 fachao.zhang
 * [MAUI_02958019] [CABC] new feature check in
 * .
 *
 * 01 11 2011 fachao.zhang
 * [MAUI_02647653] [Santiy Test fail] For pluto project NVRAM_BYTE_BL_SETTING_HFTIME byte-short
 * .
 *
 * 12 25 2010 fachao.zhang
 * [MAUI_02645344] [FTO] Device code check in
 * .
 *
 * 12 17 2010 yenhung.chen
 * [MAUI_02844420] [NVRAM] Country Adaptation Tool Checkin
 * .
 *
 * 11 18 2010 fachao.zhang
 * [MAUI_02641036] [NVRAM Cache Migrate] from /nvram_mgr.res to APP.res
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 

#include "mmi_features.h"
#include "CustResDef.h"
#include "custom_mmi_default_value.h"


<?xml version = "1.0" encoding = "UTF-8"?>


<APP id = "SRV_GPIO">


<!----------------- XML Begin ------------------------------------------------->

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->


<!-----------------------------------------------------Other Resource Area------------------------------------------------------>

    <CACHEDATA type="byte" id="NVRAM_SETTING_CONTRAST_LEVEL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X07] </DEFAULT_VALUE>
        <DESCRIPTION> LCD contrast </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_SETTING_CONTRAST_SUBLCD_LEVEL">
        <DEFAULT_VALUE> [0X07] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_NORMAL_MODE_VOICE_LEVEL">
        <DEFAULT_VALUE> [LEVEL5] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_LDSPK_MODE_VOICE_LEVEL">
        <DEFAULT_VALUE> [LEVEL5] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_HDSET_MODE_VOICE_LEVEL">
        <DEFAULT_VALUE> [LEVEL5] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BYTE_LED_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> LED On/Off </DESCRIPTION>
    </CACHEDATA>

#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_VUI_SCREEN_LOCK_KEY__)
    <CACHEDATA type="byte" id="NVRAM_BYTE_BL_SETTING_LEVEL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Backlight Level </DESCRIPTION>
		<FIELD min="1" max="20"></FIELD>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_BYTE_BL_SETTING_HFTIME" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Backlight timer </DESCRIPTION>
    </CACHEDATA>
#else
    <CACHEDATA type="byte" id="NVRAM_BYTE_BL_SETTING_LEVEL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Backlight Level </DESCRIPTION>
        <FIELD min="1" max="20"></FIELD>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_BYTE_BL_SETTING_HFTIME" restore_flag="TRUE">
#if defined(__KJX_FUN__)	//2017-07-18 ±≥π‚ ±º‰15√Î
        <DEFAULT_VALUE> [0x0F, 0x00] </DEFAULT_VALUE>
#else /*__OLED_BW_MMI__*/
        <DEFAULT_VALUE> [0x00, 0x2D] </DEFAULT_VALUE>
#endif /* __OLED_BW_MMI__ */
        <DESCRIPTION> Backlight timer </DESCRIPTION>
    </CACHEDATA>
#endif /* __COSMOS_MMI_PACKAGE__ */

    <CACHEDATA type="byte" id="NVRAM_BYTE_COVER_CLOSE_BACK_TO_IDLE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Clam Back to Idle </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BYTE_COVER_CLOSE_REJECT_CALL">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_BYTE_COVER_CLOSE_KEYPAD_LOCK">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
    
#ifdef __MMI_CABC__
    <CACHEDATA type="byte" id="NVRAM_BYTE_MMI_GPIO_CABC">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Automatic brightness to savepower </DESCRIPTION>
    </CACHEDATA>
#endif

	<TIMER id="BACKLIGHT_TIMER"/>
	<TIMER id="TIMER_KEYPAD_BACKLIGHT"/>
	<TIMER id="GPIO_KEYPAD_LIGHT_TIMER"/>

<!----------------- XML END --------------------------------------------------->

</APP>






  
