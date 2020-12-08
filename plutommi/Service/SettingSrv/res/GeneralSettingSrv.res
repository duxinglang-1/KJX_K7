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

/*******************************************************************************
 * Filename:
 * ---------
 *   GeneralSettingSrv.res
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Resource XML file
 *
 * Author:
 * -------
 *   Cong Zhou
 *
 *******************************************************************************/

#include "MMI_features.h"
#include "CustResDef.h"


<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "SRV_GENERAL_SETTING">
    <INCLUDE file = "GlobalResDef.h"/>
    
<!--------------------------------------------------------------------------------------------------------------------->
    <CACHEDATA type="byte" id="TIME_FORMAT" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X01] </DEFAULT_VALUE>
        <DESCRIPTION> Time format </DESCRIPTION>
        <FIELD>
           <OPTION hint = "12"> [0x00] </OPTION>
           <OPTION hint = "24"> [0x01] </OPTION>
        </FIELD>
    </CACHEDATA>

    <CACHEDATA type="byte" id="DATE_FORMAT" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X02] </DEFAULT_VALUE>
        <DESCRIPTION> Date format </DESCRIPTION>
        <FIELD>
	        <OPTION hint="DDMMYYYY"> [0x00]</OPTION>
	        <OPTION hint="MMDDYYYY"> [0x01] </OPTION>
	        <OPTION hint="YYYYMMDD"> [0x02]</OPTION>
        </FIELD>
    </CACHEDATA>

    <CACHEDATA type="byte" id="RESTORE_DEFAULT_TIME_FORMAT">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="RESTORE_DEFAULT_DATE_FORMAT">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_DT_SEP_FORMAT" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
        <FIELD>
	        <OPTION hint="."> [0x00]</OPTION>
	        <OPTION hint=":"> [0x01] </OPTION>
	        <OPTION hint="/"> [0x02]</OPTION>
	        <OPTION hint="-"> [0x03] </OPTION>
        </FIELD>
    </CACHEDATA>    

    <CACHEDATA type="byte" id="NVRAM_SETTING_LANG" restore_flag="TRUE">
    #if defined(__OP01__) || defined(__OP02__)
        <DEFAULT_VALUE> [0xFE] </DEFAULT_VALUE>
    #else
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
    #endif
        <DESCRIPTION> Current language </DESCRIPTION>
        <FIELD>
#if defined(__MMI_LANG_ENGLISH__)
            <OPTION hint="English"> [0x00]</OPTION>
#endif

#if defined(__MMI_LANG_FRENCH__)
            <OPTION hint="French"></OPTION>
#endif

#if defined(__MMI_LANG_SPANISH__)
            <OPTION hint="Spanish"></OPTION>
#endif

#if defined(__MMI_LANG_DANISH__)
            <OPTION hint="Danish"></OPTION>
#endif

#if defined(__MMI_LANG_POLISH__)
            <OPTION hint="Polish"></OPTION>
#endif

#if defined(__MMI_LANG_PORTUGUESE__)
            <OPTION hint="Portuguese"></OPTION>
#endif

#if defined(__MMI_LANG_ALBANIAN__)
            <OPTION hint="Albanian"></OPTION>
#endif

//English
#if defined(__MMI_LANG_UK_ENGLISH__)
            <OPTION hint="UK English"></OPTION>
#endif

#if defined(__MMI_LANG_CA_FRENCH__)
            <OPTION hint="CA French"></OPTION>
#endif

#if defined(__MMI_LANG_SA_SPANISH__)
            <OPTION hint="SA Spanish"></OPTION>
#endif

#if defined(__MMI_LANG_SA_PORTUGUESE__)
            <OPTION hint="SA Portuguese"></OPTION>
#endif

#if defined(__MMI_LANG_ICELANDIC__)
            <OPTION hint="Icelandic"></OPTION>
#endif

#if defined(__MMI_LANG_SERBIAN__)
            <OPTION hint="Serbian"></OPTION>
#endif

#if defined(__MMI_LANG_AZERBAIJANI__)
            <OPTION hint="Azerbaijani"></OPTION>
#endif

#if defined(__MMI_LANG_CATALAN__)
            <OPTION hint="Catalan"></OPTION>
#endif

#if defined(__MMI_LANG_HAUSA__)
            <OPTION hint="Hausa"></OPTION>
#endif


#if defined(__MMI_LANG_KAZAKH__)
            <OPTION hint="Kazakh"></OPTION>
#endif

#if defined(__MMI_LANG_GALICIAN__)
            <OPTION hint="Galician"></OPTION>
#endif

#if defined(__MMI_LANG_BASQUE__)
            <OPTION hint="Basque"></OPTION>
#endif

#if defined(__MMI_LANG_IGBO__)
            <OPTION hint="Igbo"></OPTION>
#endif

#if defined(__MMI_LANG_FILIPINO__)
            <OPTION hint="Filipino"></OPTION>
#endif

#if defined(__MMI_LANG_IRISH__)
            <OPTION hint="Irish"></OPTION>
#endif

#if defined (__MMI_LANG_KOREAN__)
            <OPTION hint="Korean"></OPTION>
#endif

#if defined (__MMI_LANG_JAPANESE__)
            <OPTION hint="Japanse"></OPTION>
#endif


#if defined(__MMI_LANG_MACEDONIAN__)
            <OPTION hint="Macedonian"></OPTION>
#endif

#if defined(__MMI_LANG_SESOTHO__)
            <OPTION hint="Sesotho"></OPTION>
#endif


#if defined(__MMI_LANG_TAGALOG__)
            <OPTION hint="Tagalog"></OPTION>
#endif

#if defined(__MMI_LANG_YORUBA__)
            <OPTION hint="Yoruba"></OPTION>
#endif


#if defined(__MMI_LANG_ITALIAN__)
            <OPTION hint="Italian"></OPTION>
#endif

#if defined(__MMI_LANG_GERMAN__)
            <OPTION hint="German"></OPTION>
#endif

#if defined(__MMI_LANG_MALAY__)
            <OPTION hint="Malay"></OPTION>
#endif

#if defined(__MMI_LANG_INDONESIAN__)
            <OPTION hint="Indonesian"></OPTION>
#endif

#if defined(__MMI_LANG_CZECH__)
            <OPTION hint="Czech"></OPTION>
#endif

#if defined(__MMI_LANG_NORWEGIAN__)
            <OPTION hint="Norwegian"></OPTION>
#endif
//Norwegian end

#if defined(__MMI_LANG_SLOVAK__)
            <OPTION hint="Slovak"></OPTION>
#endif

#if defined(__MMI_LANG_DUTCH__)
            <OPTION hint="Dutch"></OPTION>
#endif

#if defined(__MMI_LANG_FINNISH__)
            <OPTION hint="Finnish"></OPTION>
#endif

#if defined(__MMI_LANG_HUNGARIAN__)
            <OPTION hint="Hungarian"></OPTION>
#endif

#if defined(__MMI_LANG_VIETNAMESE__)
            <OPTION hint="Vietnamese"></OPTION>
#endif

#if defined(__MMI_LANG_TURKISH__)
            <OPTION hint="Turkish"></OPTION>
#endif

#if defined(__MMI_LANG_RUSSIAN__)
            <OPTION hint="Russian"></OPTION>
#endif

#if defined(__MMI_LANG_BULGARIAN__)
            <OPTION hint="Bulgarian"></OPTION>
#endif

#if defined(__MMI_LANG_UKRAINIAN__)
            <OPTION hint="Ukrainian"></OPTION>
#endif

//Arabic language
#if defined(__MMI_LANG_ARABIC__)
            <OPTION hint="Arabic"></OPTION>
#endif

#if defined(__MMI_LANG_PERSIAN__)
            <OPTION hint="Persian"></OPTION>
#endif
#if defined(__MMI_LANG_URDU__)
            <OPTION hint="Urdu"></OPTION>
#endif
#if defined(__MMI_LANG_HEBREW__)
            <OPTION hint="Hebrew"></OPTION>
#endif

//Thai language
#if defined(__MMI_LANG_THAI__)
            <OPTION hint="Thai"></OPTION>
#endif

//Greek
#if defined(__MMI_LANG_GREEK__)
            <OPTION hint="Greek"></OPTION>
#endif

//Traditional Chinese
#if defined(__MMI_LANG_TR_CHINESE__)
            <OPTION hint="Traditional Chinese"></OPTION>
#endif

#if defined(__MMI_LANG_HK_CHINESE__)
            <OPTION hint="HK Chinese"></OPTION> 
#endif /* defined(__MMI_LANG_HK_CHINESE__) */

//Simplified Chinese
#if defined(__MMI_LANG_SM_CHINESE__)
            <OPTION hint="Simplified Chinese"></OPTION>
#endif

#if defined(__MMI_LANG_SWEDISH__)
            <OPTION hint="Swedish"></OPTION>
#endif

#if defined(__MMI_LANG_CROATIAN__)
            <OPTION hint="Croatian"></OPTION>
#endif

#if defined(__MMI_LANG_ROMANIAN__)
            <OPTION hint="Romanian"></OPTION>
#endif
#if defined(__MMI_LANG_SLOVENIAN__)
            <OPTION hint="Slovenian"></OPTION>
#endif

#if defined(__MMI_LANG_HINDI__)
            <OPTION hint="Hindi"></OPTION>
#endif


#if defined(__MMI_LANG_MARATHI__)  
            <OPTION hint="Marathi"></OPTION>
#endif
#if defined(__MMI_LANG_TAMIL__)
            <OPTION hint="Tamil"></OPTION>
#endif

#if defined(__MMI_LANG_GUJARATI__)
            <OPTION hint="Gujarati"></OPTION>
#endif
#if defined(__MMI_LANG_BENGALI__)
            <OPTION hint="Bengali"></OPTION>
#endif
#if defined(__MMI_LANG_ASSAMESE__)
            <OPTION hint="Assamese"></OPTION>
#endif
#if defined(__MMI_LANG_PUNJABI__)
            <OPTION hint="Punjabi"></OPTION>
#endif
#if defined(__MMI_LANG_TELUGU__)
            <OPTION hint="Telugu"></OPTION>
#endif
#if defined(__MMI_LANG_KANNADA__)
            <OPTION hint="Kannada"></OPTION>
#endif

#if defined(__MMI_LANG_MALAYALAM__)
            <OPTION hint="Malayalam"></OPTION>
#endif

#if defined(__MMI_LANG_LAO__)
            <OPTION hint="Lao"></OPTION>
#endif
#if defined(__MMI_LANG_KHMER__)
            <OPTION hint="Khmer"></OPTION>
#endif
#if defined(__MMI_LANG_MYANMAR__)
            <OPTION hint="Myanmar"></OPTION>
#endif

#if defined(__MMI_LANG_ORIYA__)
            <OPTION hint="Oriya"></OPTION>
#endif
#if defined(__MMI_LANG_XHOSA__)
            <OPTION hint="Xhosa"></OPTION>
#endif
#if defined(__MMI_LANG_SWAHILI__)
            <OPTION hint="Swahili"></OPTION>
#endif
#if defined(__MMI_LANG_AFRIKAANS__)
            <OPTION hint="Afrikaans"></OPTION>
#endif
#if defined(__MMI_LANG_ZULU__)
            <OPTION hint="Zulu"></OPTION>
#endif
#if defined(__MMI_LANG_LITHUANIAN__)
            <OPTION hint="Lithuanian"></OPTION>
#endif
#if defined(__MMI_LANG_LATVIAN__)
            <OPTION hint="Latvian"></OPTION>
#endif
#if defined(__MMI_LANG_ESTONIAN__)
            <OPTION hint="Estonian"></OPTION>
#endif
#if defined(__MMI_LANG_ARMENIAN__)
            <OPTION hint="Armenian"></OPTION>
#endif
#if defined(__MMI_LANG_GEORGIAN__)
            <OPTION hint="Georgian"></OPTION>
#endif
#if defined(__MMI_LANG_MOLDOVAN__)
            <OPTION hint="Moldovan"></OPTION>
#endif           
        </FIELD>
    </CACHEDATA>

#ifdef __MMI_SET_DEF_ENCODING_TYPE__
    <CACHEDATA type="byte" id="NVRAM_SETTING_DEF_ENCODING" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> user defined encoding type </DESCRIPTION>
        <FIELD>
            <OPTION hint="ASCII"> [0x01]</OPTION>
		#ifdef __MMI_CHSET_ARABIC_ISO__        
            <OPTION hint="ARABIC_ISO">[0x02]</OPTION>
		#endif
        
		#ifdef __MMI_CHSET_ARABIC_WIN__
            <OPTION hint="ARABIC_WIN">[0x03]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_PERSIAN_CP1097__
            <OPTION hint="PERSIAN_CP1097">[0x04]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_PERSIAN_CP1098__
            <OPTION hint="PERSIAN_CP1098">[0x05]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_BALTIC_ISO__
            <OPTION hint="BALTIC_ISO">[0x06]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_BALTIC_WIN__
            <OPTION hint="BALTIC_WIN">[0x07]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_CEURO_ISO__
            <OPTION hint="CEURO_ISO">[0x08]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_CEURO_WIN__        
            <OPTION hint="CEURO_WIN">[0x09]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_CYRILLIC_ISO__        
            <OPTION hint="CYRILLIC_ISO">[0x0A]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_CYRILLIC_WIN__        
            <OPTION hint="CYRILLIC_WIN">[0x0B]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_GREEK_ISO__
            <OPTION hint="GREEK_ISO">[0x0C]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_GREEK_WIN__        
            <OPTION hint="GREEK_WIN">[0x0D]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_HEBREW_ISO__
            <OPTION hint="HEBREW_ISO">[0x0E]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_HEBREW_WIN__        
            <OPTION hint="HEBREW_WIN">[0x0F]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_LATIN_ISO__        
            <OPTION hint="LATIN_ISO">[0x10]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_NORDIC_ISO__        
            <OPTION hint="NORDIC_ISO">[0x11]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_SEURO_ISO__        
            <OPTION hint="SEURO_ISO">[0x12]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_TURKISH_ISO__        
            <OPTION hint="TURKISH_ISO">[0x13]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_TURKISH_WIN__
            <OPTION hint="TURKISH_WIN">[0x14]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_WESTERN_ISO__
            <OPTION hint="WESTERN_ISO">[0x15]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_ARMENIAN_ISO__
            <OPTION hint="ARMENIAN_ISO">[0x16]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_THAI_WINDOWS__
            <OPTION hint="THAI_WIN">[0x17]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_VIETNAMESE_WINDOWS__        
            <OPTION hint="VIETNAMESE_WIN">[0x18]</OPTION>
        #endif
        
        #ifdef __MMI_CHSET_KOI8_R__
            <OPTION hint="KOI8_R">[0x19]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_TIS_620__        
            <OPTION hint="TIS_620">[0x1A]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_WESTERN_WIN__
            <OPTION hint="WESTERN_WIN">[0x1B]</OPTION>
        #endif
        
            /* Add new (8-bit) encodings above this line */
		#ifdef __MMI_CHSET_BIG5__
            <OPTION hint="BIG5">[0x1C]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_GB2312__
            <OPTION hint="GB2312">[0x1D]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_HKSCS__
            <OPTION hint="HKSCS">[0x1E]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_SJIS__
            <OPTION hint="SJIS">[0x1F]</OPTION>
        #endif
        
        #ifdef __MMI_CHSET_GB18030__
            <OPTION hint="GB18030">[0x20]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_UTF7__        
            <OPTION hint="UTF7">[0x21]</OPTION>
        #endif
        
		#ifdef __MMI_CHSET_EUCKR_WIN__
            <OPTION hint="EUCKR">[0x22]</OPTION>
        #endif
        
		#if 0
            /* PLace all encodings using algo to above this one */
            <OPTION hint="UTF16LE"></OPTION>
        
            <OPTION hint="UTF16BE"></OPTION>
        
            <OPTION hint="UTF8"></OPTION>
        
            <OPTION hint="UCS2"></OPTION>       
        #endif
        </FIELD>
    </CACHEDATA>
#endif /*__MMI_SET_DEF_ENCODING_TYPE__*/

    <SENDER id="EVT_ID_SETTING_LANGUAGE_CHANGED" hfile="GeneralSettingSrvGprot.h"/>

    <SENDER id="EVT_ID_SRV_SETTING_UART_SETTING_CHANGED" hfile="GeneralSettingSrvGprot.h"/>
</APP>



