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
 * PhbSrv.res
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * 
 *
 * Author:
 * -------
 * Li (mtk80244)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 01 18 2013 mingliang.xu
 * [MAUI_03317644] [MT6260 pre-SQC]red x is showing on incoming call screen
 * .
 *
 * 12 25 2012 yanchao.yang
 * [MAUI_03257448] [phbsrv]SLIM check in
 * .
 * 
 * 08 13 2012 naiming.guo
 * [MAUI_03223978] It still shows importing contacts and imports contacts from memory card after removing Tcard while in importing progress.
 * .
 * 
 * 08 10 2012 naiming.guo
 * [MAUI_03223978] It still shows importing contacts and imports contacts from memory card after removing Tcard while in importing progress.
 * .
 * 
 * 07 19 2012 naiming.guo
 * [MAUI_03215531] [PHB_Tcard]Phonebook list don't display any Tcard contact after remove out and plug in Tcard
 * .
 *
 * 06 05 2012 naiming.guo
 * [MAUI_03196674] [CAT2.0]Preferred storage of Phonebook show wrong
 * .
 *
 * 06 01 2012 naiming.guo
 * [MAUI_03194396] [CAT2.0]There is no default value in the item of " Prefferred Storage" in "Phonebook"
 * .
 *
 * 05 23 2012 naiming.guo
 * [MAUI_03188662] [CAT 2.0 IT] The option of Preferred Storage is not matched to the phone on COSMOS.
 * .
 *
 * 05 17 2012 naiming.guo
 * [MAUI_03185875] [CAT 2.0 IT] The description of Preferred Storage is not matched to the real value in the phone.
 * .
 *
 * 05 04 2012 naiming.guo
 * [MAUI_03177169] [Known Issue] Shows Red cross icon in during Call
 * .
 *
 * 11 04 2011 naiming.guo
 * [MAUI_03065842] [Contact]It show Backing up popup for too long time after plug out /in memory card
 * .
 *
 * 08 05 2011 naiming.guo
 * [MAUI_02995791] [In-house FTA][TP][SIM/SAT][Luffy76_V22] 27.22.4.7.1 REFRESH SEQ 1.1
 * .
 *
 * 07 26 2011 huilong.yin
 * [MAUI_02978146] [Message]Cosmos1.5 support
 * revise phb event.
 *
 * 04 13 2011 naiming.guo
 * [MAUI_02658875] [MAUI SDK]  App service ->PIM , phonebook fail
 * .
 *
 * 04 01 2011 naiming.guo
 * [MAUI_02658799] change phone book default pic
 * .
 *
 * 04 01 2011 naiming.guo
 * [MAUI_02658799] change phone book default pic
 * .
 *
 * 04 01 2011 naiming.guo
 * [MAUI_02658799] change phone book default pic
 * .
 *
 * 02 16 2011 yue.zheng
 * [MAUI_02736698] [UE][CALL] there is no incoming call image
 * .
 *
 * 02 15 2011 shengjun.cui
 * [MAUI_02735175] should not show deleted type
 * .
 *
 * 01 18 2011 yue.zheng
 * [MAUI_02648777] [Contact] Fix Bootup sanity fail
 * .
 *
 * 01 12 2011 li.ding
 * [MAUI_02647584] [PHB] fix build error
 * .
 *
 * 12 30 2010 li.ding
 * [MAUI_02646402] [PHB] add phb srv res
 * .
 *
 * 12 30 2010 li.ding
 * [MAUI_02646402] [PHB] add phb srv res
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_PHB">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_PHB_MOBILE_NUMBER"/>
    <STRING id="STR_HOME_NUMBER"/>
    <STRING id="STR_OFFICE_NUMBER"/>
    <STRING id="STR_FAX_NUMBER"/>
    <STRING id="STR_EMERGENCY_NUMBER"/>
    
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
#ifdef __MMI_VIDEO_TELEPHONY__
#if defined __COSMOS_MMI_PACKAGE__
    <IMAGE id="IMG_PHB_VIDEO_DEFAULT">RES_THEME_ROOT"\\\\Theme1\\\\Common\\\\Avatar_02.png"</IMAGE>
#elif defined __MMI_FTE_SUPPORT__
    <IMAGE id="IMG_PHB_VIDEO_DEFAULT">CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoTelephony\\\\Incoming\\\\CL_Vincom.png"</IMAGE>
#else
    <IMAGE id="IMG_PHB_VIDEO_DEFAULT">CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoTelephony\\\\Incoming\\\\CL_Vincom.gif"</IMAGE>
#endif
#endif

#if defined(__COSMOS_MMI__)
    <THEME>
        <IMAGE id="IMG_PHB_DEFAULT" desc="phonebook hearportrait"/>
    </THEME>

#elif defined __MMI_FTE_SUPPORT__
#if defined(__FTE_NON_SLIM_RES__)
    <IMAGE id="IMG_PHB_DEFAULT">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Connect\\\\CL_NET"</IMAGE>
#else
    <IMAGE id="IMG_PHB_DEFAULT">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Connect\\\\CL_NET.png"</IMAGE>
#endif
#elif defined(__MMI_MAINLCD_128X128__) && defined(LOW_COST_SUPPORT)
    <IMAGE id="IMG_PHB_DEFAULT">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Connect\\\\CL_NET.jpg"</IMAGE>
#else
    <IMAGE id="IMG_PHB_DEFAULT">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Connect\\\\CL_NET.png"</IMAGE>
#endif
    
    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */

	<SENDER id="EVT_ID_PHB_ADD_CONTACT" hfile="PhbSrvGprot.h"/>
	<SENDER id="EVT_ID_PHB_UPD_CONTACT" hfile="PhbSrvGprot.h"/>
	<SENDER id="EVT_ID_PHB_DEL_CONTACT" hfile="PhbSrvGprot.h"/>
	<SENDER id="EVT_ID_PHB_PRE_UPDATE_CONTACT" hfile="PhbSrvGprot.h"/>
	<SENDER id="EVT_ID_PHB_READY" hfile="PhbSrvGprot.h"/>
	<SENDER id="EVT_ID_PHB_OWNER_NUMBER_CHANGED" hfile="PhbSrvGprot.h"/>
	<SENDER id="EVT_ID_PHB_OP_GROUP" hfile="PhbSrvGprot.h"/>
	<SENDER id="EVT_ID_PHB_MULTI_OP_STATUS" hfile="PhbSrvGprot.h"/>
	<SENDER id="EVT_ID_PHB_STORAGE_CHANGE" hfile="PhbSrvGprot.h"/>
	<SENDER id="EVT_ID_PHB_NAME_SEQUENCE_CHANGE" hfile="PhbSrvGprot.h"/>
	<SENDER id="EVT_ID_PHB_BACKUP_RESTORE_NCENTER" hfile="PhbSrvGprot.h"/>
	<SENDER id="EVT_ID_PHB_FIELD_TYPE_CHNAGED_IND" hfile="PhbSrvGprot.h"/>
	<SENDER id="EVT_ID_PHB_MULTI_OP_DONE" hfile="PhbSrvGprot.h"/>
#ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
	<SENDER id="EVT_ID_PHB_TCARD_READY" hfile="PhbSrvGprot.h"/>
#endif

#if defined(__MMI_PHB_QUICK_SEARCH__)
	<RECEIVER id="EVT_ID_PHB_ADD_CONTACT"    proc="srv_phb_sse_updata_qcache"/>	
	<RECEIVER id="EVT_ID_PHB_UPD_CONTACT"    proc="srv_phb_sse_updata_qcache"/>
	<RECEIVER id="EVT_ID_PHB_DEL_CONTACT"    proc="srv_phb_sse_delete_qcache"/>
#endif /* defined(__MMI_PHB_QUICK_SEARCH__) */

    <!------------------------------------------------------NARAM Resource---------------------------------------------------------->

    <CACHEDATA type="byte" id="NVRAM_PHB_SPEAK_NAME_ON_OFF" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> PHB_SPEAK_NAME </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="byte" id="NVRAM_PHB_STARTUP_COPY_SIM">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> PHB_STARTUP_COPY_1 </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_PHB_STARTUP_COPY_SIM2">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> PHB_STARTUP_COPY_2 </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_PHB_STARTUP_COPY_SIM3">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> PHB_STARTUP_COPY_3 </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_PHB_STARTUP_COPY_SIM4">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> PHB_STARTUP_COPY_4 </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_PHB_NAME_DISPLAY_TYPE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> Phonebook name display type </DESCRIPTION>
    </CACHEDATA>
        
    <CACHEDATA type="short" id="NVRAM_PHB_STORAGE_LOCATION" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x02, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Phonebook prefer storage </DESCRIPTION>
    <FIELD>
    <OPTION hint="Phone"> [0x02, 0x00] </OPTION>

		#if (MMI_MAX_SIM_NUM == 1)
		  <OPTION hint="SIM"> [0x04, 0x00] </OPTION>
		#endif
		
		#if (MMI_MAX_SIM_NUM >= 2)
		  <OPTION hint="SIM1"> [0x04, 0x00] </OPTION>
			<OPTION hint="SIM2"> [0x08, 0x00] </OPTION>
		#endif

		#if (MMI_MAX_SIM_NUM >= 3)
			<OPTION hint="SIM3"> [0x10, 0x00] </OPTION>
		#endif

		#if (MMI_MAX_SIM_NUM >= 4)
			<OPTION hint="SIM4"> [0x20, 0x00] </OPTION>
		#endif
		
		#ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
		  <OPTION hint="Memory card"> [0x40, 0x00] </OPTION>
		#endif
#ifndef __COSMOS_MMI_PACKAGE__
  #ifndef __SRV_PHB_TCARD_STORAGE_SUPPORT__
		#if (MMI_MAX_SIM_NUM == 1)
			<OPTION hint="All"> [0x06, 0x00] </OPTION>
		#elif (MMI_MAX_SIM_NUM == 2)
			<OPTION hint="All"> [0x0E, 0x00] </OPTION>
		#elif (MMI_MAX_SIM_NUM == 3)
			<OPTION hint="All"> [0x1E, 0x00] </OPTION>
		#elif (MMI_MAX_SIM_NUM == 4)
			<OPTION hint="All"> [0x3E, 0x00] </OPTION>
		#endif
	#else
		#if (MMI_MAX_SIM_NUM == 1)
			<OPTION hint="All"> [0x46, 0x00] </OPTION>
		#elif (MMI_MAX_SIM_NUM == 2)
			<OPTION hint="All"> [0x4E, 0x00] </OPTION>
		#elif (MMI_MAX_SIM_NUM == 3)
			<OPTION hint="All"> [0x5E, 0x00] </OPTION>
		#elif (MMI_MAX_SIM_NUM == 4)
			<OPTION hint="All"> [0x7E, 0x00] </OPTION>
		#endif
	#endif
#endif
        </FIELD>
    </CACHEDATA>
    
    <CACHEDATA type="short" id="NVRAM_PHB_NAME_LIST_FILTER" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> PHB_NLF </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="short" id="NVRAM_PHB_VCARD_VERSION" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> VCARD VERSION </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="byte" id="NVRAM_PHB_SAVE_CONTACT_NOTIFY" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> PHB_SAVE_NOTIFY </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="byte" id="NVRAM_SSC_DISABLE_FLAG">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="byte" id="NVRAM_IDLE_DIALER_SEARCH_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> Dialer search on / off </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="byte" id="NVRAM_SETTING_SPEED_DIAL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
        <DESCRIPTION> Speed dial status </DESCRIPTION>
    </CACHEDATA>

</APP>

