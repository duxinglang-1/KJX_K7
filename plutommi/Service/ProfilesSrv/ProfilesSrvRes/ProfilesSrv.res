/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   ProfilesSrv.res
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  User Profiles Service resource file
 *
 * Author:
 * -------
 *   Kinse Lin (mtk01393)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision: $
 * $Modtime: $
 * $Log: $
 *
 * 11 27 2012 yufei.shen
 * [MAUI_03260502] [MCD] Remove unused string in 11BW1232OF_SLIM_DEV
 * .
 *
 * 04 20 2012 kinse.lin
 * [MAUI_03172471] [Res] move timer id to res file
 * .
 *
 * 03 16 2012 kinse.lin
 * [MAUI_03150889] [Profiles Srv] force to write to nvram when for shut down event
 * .
 *
 * 01 03 2012 kinse.lin
 * [MAUI_03105649] [Cosmos Slim] check in modification for Cosmos Slim
 * .
 *
 * 11 07 2011 kinse.lin
 * [MAUI_03020457] [Victor56][Cosmos][D-Audio] Can't control media volume
 * .
 *
 * 10 21 2011 kinse.lin
 * [MAUI_03059750] [Valid Bit] extend valid bit from U16 to U64
 * .
 *
 * 06 29 2011 kinse.lin
 * [MAUI_02972610] check in code (add and delete profile) for cmcc td project
 * .
 *
 * 06 07 2011 vovo.yang
 * [MAUI_02832291] Cosmos Development
 * fix .res syntax errors
 *
 * 06 07 2011 vovo.yang
 * [MAUI_02832291] Cosmos Development
 * fix .res syntax errors
 *
 * 12 21 2010 kinse.lin
 * [MAUI_02831540] [Gemini +] check in Profiles Service related files
 * .
 *
 * 11 27 2010 kinse.lin
 * [MAUI_02842883] [Profiles Srv] move is playing check back to application
 * .
 *
 * 11 23 2010 kinse.lin
 * [MAUI_02832467] [NVRAM] apply new mmi cache mechanism
 * .
 *
 * 10 27 2010 yan.liang
 * [MAUI_02634102] [FRM] Framework Callback Manager Revise
 * Fix spelling mistake
 *
 * 09 26 2010 kinse.lin
 * [MAUI_02623467] [Medply] check in event populate in reource
 * .
 *
 * 08 03 2010 kinse.lin
 * [MAUI_02314544] it should play the error tone in general mode
 * .
 *
 * May 16 2010 mtk01393
 * [MAUI_02420915] [Profiles Service] Check in 10A and Trunk
 * 
 *
 * May 12 2010 mtk01393
 * [MAUI_02420915] [Profiles Service] Check in 10A and Trunk
 * 
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "MMI_features.h" 
#include "custresdef.h"
<?xml version="1.0" encoding="UTF-8"?>

<APP id="SRV_PROF">   

<!----------------------------------------------------------------------------------------
******** String section 
------------------------------------------------------------------------------------------>

    <STRING id="STR_ID_SRV_PROF_TONE_1"/>
    <STRING id="STR_ID_SRV_PROF_TONE_2"/>
    <STRING id="STR_ID_SRV_PROF_TONE_3"/>
    <STRING id="STR_ID_SRV_PROF_TONE_4"/>
    <STRING id="STR_ID_SRV_PROF_TONE_5"/>
#ifndef __LOW_COST_SUPPORT_COMMON__
    <STRING id="STR_ID_SRV_PROF_TONE_6"/>
    <STRING id="STR_ID_SRV_PROF_TONE_7"/>
    <STRING id="STR_ID_SRV_PROF_TONE_8"/>
    <STRING id="STR_ID_SRV_PROF_TONE_9"/>
    <STRING id="STR_ID_SRV_PROF_TONE_10"/>
#endif

    <STRING id="STR_ID_SRV_PROF_RING_1"/>
    <STRING id="STR_ID_SRV_PROF_RING_2"/>
    <STRING id="STR_ID_SRV_PROF_RING_3"/>
    <STRING id="STR_ID_SRV_PROF_RING_4"/>
    <STRING id="STR_ID_SRV_PROF_RING_5"/>
#ifndef __LOW_COST_SUPPORT_COMMON__
    <STRING id="STR_ID_SRV_PROF_RING_6"/>
    <STRING id="STR_ID_SRV_PROF_RING_7"/>
    <STRING id="STR_ID_SRV_PROF_RING_8"/>
    <STRING id="STR_ID_SRV_PROF_RING_9"/>
    <STRING id="STR_ID_SRV_PROF_RING_10"/>
    <STRING id="STR_ID_SRV_PROF_RING_11"/>
    <STRING id="STR_ID_SRV_PROF_RING_12"/>
    <STRING id="STR_ID_SRV_PROF_RING_13"/>
    <STRING id="STR_ID_SRV_PROF_RING_14"/>
    <STRING id="STR_ID_SRV_PROF_RING_15"/>
    <STRING id="STR_ID_SRV_PROF_RING_16"/>
    <STRING id="STR_ID_SRV_PROF_RING_17"/>
    <STRING id="STR_ID_SRV_PROF_RING_18"/>
    <STRING id="STR_ID_SRV_PROF_RING_19"/>
    <STRING id="STR_ID_SRV_PROF_RING_20"/>
#endif /* __LOW_COST_SUPPORT_COMMON__*/

<!----------------------------------------------------------------------------------------
******** Audio section 
------------------------------------------------------------------------------------------>

    <AUDIO id="AUD_ID_PROF_INTERNAL_BEGIN">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_TONE_BEGIN">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
#ifdef __KJX_FUN__	//xb add 2017-08-07	¿ª¹Ø»úÁåÉù
    <AUDIO id="AUD_ID_PROF_TONE1" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Tone\\\\poweron.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_TONE2" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Tone\\\\poweroff.mp3"</AUDIO>	
#else
    <AUDIO id="AUD_ID_PROF_TONE1" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Tone\\\\cs01.mid"</AUDIO>
    <AUDIO id="AUD_ID_PROF_TONE2" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Tone\\\\cs02.mid"</AUDIO>    
#endif
    <AUDIO id="AUD_ID_PROF_TONE3" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Tone\\\\cs03.mid"</AUDIO>
    <AUDIO id="AUD_ID_PROF_TONE4" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Tone\\\\cs04.mid"</AUDIO>
    <AUDIO id="AUD_ID_PROF_TONE5" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Tone\\\\cs05.mid"</AUDIO>
#ifndef __LOW_COST_SUPPORT_COMMON__
    <AUDIO id="AUD_ID_PROF_TONE6" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Tone\\\\cs06.mid"</AUDIO>
    <AUDIO id="AUD_ID_PROF_TONE7" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Tone\\\\cs07.mid"</AUDIO>
    <AUDIO id="AUD_ID_PROF_TONE8" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Tone\\\\cs08.mid"</AUDIO>
    <AUDIO id="AUD_ID_PROF_TONE9" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Tone\\\\cs09.mid"</AUDIO>
    <AUDIO id="AUD_ID_PROF_TONE10" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Tone\\\\cs10.mid"</AUDIO>
#endif /* __LOW_COST_SUPPORT_COMMON__*/

    <AUDIO id="AUD_ID_PROF_TONE_END">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>

    <AUDIO id="AUD_ID_PROF_RING_BEGIN">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_RING1" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Ring\\\\s1imy01.imy"</AUDIO>
    <AUDIO id="AUD_ID_PROF_RING2" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Ring\\\\s1imy02.imy"</AUDIO>
    <AUDIO id="AUD_ID_PROF_RING3" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Ring\\\\s1imy03.imy"</AUDIO>
    <AUDIO id="AUD_ID_PROF_RING4" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Ring\\\\s1imy04.imy"</AUDIO>
    <AUDIO id="AUD_ID_PROF_RING5" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Ring\\\\s1imy05.imy"</AUDIO>
#ifndef __LOW_COST_SUPPORT_COMMON__
    <AUDIO id="AUD_ID_PROF_RING6" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Ring\\\\s1imy06.imy"</AUDIO>
    <AUDIO id="AUD_ID_PROF_RING7" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Ring\\\\s1imy07.imy"</AUDIO>
    <AUDIO id="AUD_ID_PROF_RING8" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Ring\\\\s1imy08.imy"</AUDIO>
    <AUDIO id="AUD_ID_PROF_RING9" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Ring\\\\s1imy09.imy"</AUDIO>
    <AUDIO id="AUD_ID_PROF_RING10" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Ring\\\\s1imy10.imy"</AUDIO>
    <AUDIO id="AUD_ID_PROF_RING11" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Midi\\\\Aclassical04.mid"</AUDIO>
    <AUDIO id="AUD_ID_PROF_RING12" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Midi\\\\Aclassical09.mid"</AUDIO>
    <AUDIO id="AUD_ID_PROF_RING13" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Midi\\\\classical02.mid"</AUDIO>
    <AUDIO id="AUD_ID_PROF_RING14" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Midi\\\\classical10.mid"</AUDIO>
    <AUDIO id="AUD_ID_PROF_RING15" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Midi\\\\classical19.mid"</AUDIO>
    <AUDIO id="AUD_ID_PROF_RING16" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Midi\\\\classical24.mid"</AUDIO>
    <AUDIO id="AUD_ID_PROF_RING17" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Midi\\\\classical33.mid"</AUDIO>
    <AUDIO id="AUD_ID_PROF_RING18" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Midi\\\\classical35.mid"</AUDIO>
    <AUDIO id="AUD_ID_PROF_RING19" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Midi\\\\classical40.mid"</AUDIO>
    <AUDIO id="AUD_ID_PROF_RING20" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\Midi\\\\classical45.mid"</AUDIO>
#endif /* __LOW_COST_SUPPORT_COMMON__*/

    <AUDIO id="AUD_ID_PROF_RING_END">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>

#ifdef __KJX_AGAINST_THEFT__
	<AUDIO id="AUD_ID_PROF_CUST_ALARM_BEGIN">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
	<AUDIO id="AUD_ID_PROF_CUST_ALARM_1" flag="MULTIBIN">CUST_ADO_PATH"\\\\Alarm\\\\001.mp3"</AUDIO>
	<AUDIO id="AUD_ID_PROF_CUST_ALARM_2" flag="MULTIBIN">CUST_ADO_PATH"\\\\Alarm\\\\002.mp3"</AUDIO>
	<AUDIO id="AUD_ID_PROF_CUST_ALARM_3" flag="MULTIBIN">CUST_ADO_PATH"\\\\Alarm\\\\003.mp3"</AUDIO>
	<AUDIO id="AUD_ID_PROF_CUST_ALARM_4" flag="MULTIBIN">CUST_ADO_PATH"\\\\Alarm\\\\004.mp3"</AUDIO>
	<AUDIO id="AUD_ID_PROF_CUST_ALARM_5" flag="MULTIBIN">CUST_ADO_PATH"\\\\Alarm\\\\005.mp3"</AUDIO>	
	<AUDIO id="AUD_ID_PROF_CUST_ALARM_END">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
#endif

    <AUDIO id="AUD_ID_PROF_INTERNAL_END">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>

    <AUDIO id="AUD_ID_PROF_EXT_BEGIN">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT1">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT2">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT3">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT4">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT5">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT6">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT7">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT8">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT9">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT10">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT11">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT12">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>    
    <AUDIO id="AUD_ID_PROF_EXT13">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT14">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT15">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT16">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT17">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT18">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT19">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT20">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
#ifdef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
    <AUDIO id="AUD_ID_PROF_EXT21">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT22">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT23">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT24">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT25">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT26">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT27">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT28">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT29">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT30">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT31">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT32">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT33">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT34">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT35">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT36">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT37">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT38">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT39">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT40">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT41">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT42">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT43">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT44">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT45">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT46">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT47">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT48">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT49">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT50">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT51">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT52">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT53">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT54">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT55">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT56">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT57">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT58">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT59">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT60">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT61">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT62">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT63">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT64">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT65">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT66">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT67">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT68">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT69">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_EXT70">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
#endif
    <AUDIO id="AUD_ID_PROF_EXT_END">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>

#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__) || defined(DIGIT_TONE_SUPPORT)
    <AUDIO id="AUD_ID_PROF_NUM_BEGIN">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_NUM1_0" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\HumanVoice\\\\female_mandarin_0.wav"</AUDIO>
    <AUDIO id="AUD_ID_PROF_NUM1_1" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\HumanVoice\\\\female_mandarin_1.wav"</AUDIO>
    <AUDIO id="AUD_ID_PROF_NUM1_2" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\HumanVoice\\\\female_mandarin_2.wav"</AUDIO>
    <AUDIO id="AUD_ID_PROF_NUM1_3" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\HumanVoice\\\\female_mandarin_3.wav"</AUDIO>
    <AUDIO id="AUD_ID_PROF_NUM1_4" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\HumanVoice\\\\female_mandarin_4.wav"</AUDIO>
    <AUDIO id="AUD_ID_PROF_NUM1_5" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\HumanVoice\\\\female_mandarin_5.wav"</AUDIO>
    <AUDIO id="AUD_ID_PROF_NUM1_6" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\HumanVoice\\\\female_mandarin_6.wav"</AUDIO>
    <AUDIO id="AUD_ID_PROF_NUM1_7" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\HumanVoice\\\\female_mandarin_7.wav"</AUDIO>
    <AUDIO id="AUD_ID_PROF_NUM1_8" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\HumanVoice\\\\female_mandarin_8.wav"</AUDIO>
    <AUDIO id="AUD_ID_PROF_NUM1_9" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\HumanVoice\\\\female_mandarin_9.wav"</AUDIO>
    <AUDIO id="AUD_ID_PROF_NUM1_STAR" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\HumanVoice\\\\female_mandarin_star.wav"</AUDIO>
    <AUDIO id="AUD_ID_PROF_NUM1_POUND" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\HumanVoice\\\\female_mandarin_pound.wav"</AUDIO>
    <AUDIO id="AUD_ID_PROF_NUM1_PLUS" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\HumanVoice\\\\female_mandarin_plus.wav"</AUDIO>
    <AUDIO id="AUD_ID_PROF_NUM_END">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
#endif
#ifdef CUST_KEYPAD_TONE_SUPPORT 
    <AUDIO id="AUD_ID_PROF_CUST_BEGIN">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_CUST_1" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\KeyPad\\\\bubbles.wav"</AUDIO>
    <AUDIO id="AUD_ID_PROF_CUST_END">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
#endif
#ifdef __MMI_OP11_PROF_SOUND__
    <AUDIO id="AUD_ID_PROF_OP11_BEGIN">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
    <AUDIO id="AUD_ID_PROF_OP11_SENT" flag="MULTIBIN">CUST_ADO_PATH"\\\\OP11_Profiles\\\\sent_short24.wav"</AUDIO>
    <AUDIO id="AUD_ID_PROF_OP11_PROBLEM" flag="MULTIBIN">CUST_ADO_PATH"\\\\OP11_Profiles\\\\problem_short06.wav"</AUDIO>
    <AUDIO id="AUD_ID_PROF_OP11_SAVED" flag="MULTIBIN">CUST_ADO_PATH"\\\\OP11_Profiles\\\\saved_short01.wav"</AUDIO>
    <AUDIO id="AUD_ID_PROF_OP11_DELETED" flag="MULTIBIN">CUST_ADO_PATH"\\\\OP11_Profiles\\\\deleted_short04.wav"</AUDIO>
    <AUDIO id="AUD_ID_PROF_OP11_CONFIRM" flag="MULTIBIN">CUST_ADO_PATH"\\\\OP11_Profiles\\\\confirm_short05.wav"</AUDIO>
    <AUDIO id="AUD_ID_PROF_OP11_WARNING" flag="MULTIBIN">CUST_ADO_PATH"\\\\OP11_Profiles\\\\warning_short18.wav"</AUDIO>
    <AUDIO id="AUD_ID_PROF_OP11_OOPS" flag="MULTIBIN">CUST_ADO_PATH"\\\\OP11_Profiles\\\\Oops_short12.wav"</AUDIO>
    <AUDIO id="AUD_ID_PROF_OP11_ANSPHONE" flag="MULTIBIN">CUST_ADO_PATH"\\\\OP11_Profiles\\\\ansPhone_short16.wav"</AUDIO>
    <AUDIO id="AUD_ID_PROF_OP11_REMIND" flag="MULTIBIN">CUST_ADO_PATH"\\\\OP11_Profiles\\\\remind_temp.wav"</AUDIO>
    <AUDIO id="AUD_ID_PROF_OP11_END">"..\\\\..\\\\Customer\\\\AUDIO\\\\EmptyAudio.mp3"</AUDIO>
#endif

<!----------------------------------------------------------------------------------------
******** Timer section  
------------------------------------------------------------------------------------------>

    <TIMER id="SRV_PROF_STORE_CUR_TIMER"/>
    <TIMER id="SRV_PROF_STORE_BUF_TIMER"/>

<!----------------------------------------------------------------------------------------
******** Event section 
------------------------------------------------------------------------------------------>
    <EVENT id="EVT_ID_SRV_PROF_PROFILE_SWITCHED" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_PROF_IS_PLAYING" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_PROF_VOL_CHANGED" type="SENDER"/>

    <RECEIVER id="EVT_ID_SRV_SHUTDOWN_DEINIT" proc="srv_prof_cb_evt_hdlr"/>

<!----------------------------------------------------------------------------------------
******** MISC section 
------------------------------------------------------------------------------------------>

    <CACHEDATA type="byte" id="NVRAM_PROFILES_ACTIVATED" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
        <DESCRIPTION> User profiles </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_PROFILES_LASTACTIVATED" restore_flag="TRUE">
        <DEFAULT_VALUE> [0XFF] </DEFAULT_VALUE>
        <DESCRIPTION> User profiles </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="NVRAM_SRV_PROF_EXT_MELODY_BITS">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Profile Srv Ext Melody Bits </DESCRIPTION>
    </CACHEDATA>

</APP>
