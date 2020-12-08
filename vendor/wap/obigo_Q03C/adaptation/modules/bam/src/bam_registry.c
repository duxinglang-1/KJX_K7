/*****************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2006
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
 *   bam_registry.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains code to handle the registry.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*
 * bam_registry.c
 *
 * Description:
 *              This file contains code to handle the registry.
 *
 */
#include "mmi_include.h"
#include "bam_cfg.h"

#include "wapadp.h"

#include "bam_registry.h"
#ifdef OBIGO_Q03C_BROWSER
#include "bam_cmn.h"
#include "bam_hist.h"
#include "bam_if.h"
#include "bam_main.h"
#include "bam_msg.h"
#include "bam_sif.h"
#include "bam_sig.h"
#include "bam_shortcuts.h"
#include "bam_file.h"

#include "brs_if.h"

#ifdef MSF_MODID_CPS
#include "cpm_if.h"

#endif /* MSF_MODID_CPS */

#include "stk_if.h"

#include "msf_cmmn.h"
#include "msf_core.h"
#include "msf_lib.h"
#include "msf_errc.h"
#include "msf_chrt.h"
#include "profile_struct.h"
#include "EngineerModeInetAppGprot.h"
#include "msf_log.h"
#include "FontDcl.h"
#include "app_str.h"
#include "app_ua.h"
#include "custom_wap_config.h"
#include "brs_main.h"
#ifdef QO3C_DYNAMIC_UA_
#include "nvram_common_defs.h"
#endif


/* Type of BAM Registry */
#define BAM_REG_INT (BAM_SETTING_VALUE_TYPE_INT)
#define BAM_REG_STR (BAM_SETTING_VALUE_TYPE_STR)

/* Initial Values of BAM Registry */
#define BAM_REG_INT_INIT_VAL    (BAM_SETTING_INT_INIT_VAL)
#define BAM_REG_STR_INIT_VAL    (BAM_SETTING_STR_INIT_VAL)

/* Maximum accept language header length = MAX_LANGUAGES * strlen(",XX-XX;q=0.X") */
#define BAM_MAX_ACCEPT_LANGUAGE_HEADER_LEN  MAX_LANGUAGES * 12
#define BAM_MAX_LANG_LEN                    20
#define BAM_INVALID_IDX                     -1
#define BAM_QUALITY_VALUE_STR               ";q=0."
#define BAM_QUALITY_START_VALUE             9
#ifdef __BAIDU_TRANSCODING_SUPPORT__
#define BAM_CFG_TRANSCODE_PROXY_URL         "http://tcproxy.baidu.com:80/proxy"
#define BAM_CFG_TRANSCODE_PROXY_HEADER      "ReqFrom: MTK"
#endif 

#define MAX_UA_STRING_LEN    512

typedef struct
{
    int path;
} bam_registry_item_struct;

typedef struct
{
    bam_set_profile_req_struct *profile;
    MSF_INT32 *int_value_table;
    char **str_value_table;
} bam_profile_req_struct;

	
enum
{
    bam_registry_path_bam,
    bam_registry_path_brs,
    bam_registry_path_stk_cookie,
	bam_registry_path_stk_cache,
    bam_registry_path_stk,
    bam_registry_path_total
} bam_registry_path_enum;



 
static bam_registry_item_struct bam_registry_key_table[BAM_REGISTRY_ENUM_TOTAL] =
{
    {bam_registry_path_brs},
    {bam_registry_path_brs},
    {bam_registry_path_brs},
    {-1},
    {-1},
    {-1},
    {bam_registry_path_stk_cookie},
    {bam_registry_path_brs},
    {bam_registry_path_stk_cache},
    {bam_registry_path_brs},
    {bam_registry_path_brs},
    {bam_registry_path_brs},
    {-1},
    {bam_registry_path_brs},
    {-1},
    {bam_registry_path_brs},
    {bam_registry_path_stk_cache},
    {bam_registry_path_brs},
    {bam_registry_path_brs},
    {bam_registry_path_brs},
    {bam_registry_path_brs},
    {bam_registry_path_brs},
    {bam_registry_path_brs},
    {bam_registry_path_brs},
    {bam_registry_path_brs},
    {-1},
	{bam_registry_path_brs},
	{bam_registry_path_brs},
	{bam_registry_path_brs},
#ifdef __BAIDU_TRANSCODING_SUPPORT__
	{bam_registry_path_brs},
#endif
	{bam_registry_path_brs}
};


#ifdef GDI_USING_PNG

#define BRS_CFG_ACCEPT_HEADER_COMMON_1 \
  "image/vnd.wap.wbmp, " \
  "image/gif, " \
  "image/bmp, " \
  "image/png, " \
  "audio/amr," \
  "audio/imelody, " \
  "audio/midi, " \
  "audio/wav, " \
  "application/vnd.wap.wtls-ca-certificate, "\
  "application/x-x509-ca-cert, "\
  "application/vnd.wap.hashed-certificate, "\
  "application/vnd.wap.signed-certificate, "\
  "*/*"

#else

#define BRS_CFG_ACCEPT_HEADER_COMMON_1 \
  "image/vnd.wap.wbmp, " \
  "image/gif, " \
  "image/bmp, " \
  "audio/amr," \
  "audio/imelody, " \
  "audio/midi, " \
  "audio/wav, " \
  "application/vnd.wap.wtls-ca-certificate, "\
  "application/x-x509-ca-cert, "\
  "application/vnd.wap.hashed-certificate, "\
  "application/vnd.wap.signed-certificate, "\
  "*/*"

#endif


#ifdef  __J2ME__

#define BRS_CFG_ACCEPT_HEADER_COMMON \
  "text/vnd.sun.j2me.app-descriptor, "\
  "application/java-archive, "\
  BRS_CFG_ACCEPT_HEADER_COMMON_1

#else

#define BRS_CFG_ACCEPT_HEADER_COMMON BRS_CFG_ACCEPT_HEADER_COMMON_1

#endif


#define BRS_CFG_ACCEPT_HEADER_WAP_1_2_1 \
  "application/vnd.wap.wmlc, " \
  "application/vnd.wap.wmlscriptc, " \
  "text/vnd.wap.wml, " \
  BRS_CFG_ACCEPT_HEADER_COMMON
#define BRS_CFG_ACCEPT_HEADER_WAP_2_0 \
  "application/xhtml+xml; profile=http://www.wapforum.org/xhtml, " \
  "application/vnd.wap.xhtml+xml, " \
  BRS_CFG_ACCEPT_HEADER_WAP_1_2_1 \
  ", text/html"
#define BRS_CFG_ACCEPT_HEADER_WML \
  "text/vnd.wap.wml, " \
  BRS_CFG_ACCEPT_HEADER_COMMON
#define BRS_CFG_ACCEPT_HEADER_XHTML \
  "application/xhtml+xml; profile=http://www.wapforum.org/xhtml, " \
  "application/vnd.wap.xhtml+xml, " \
  BRS_CFG_ACCEPT_HEADER_COMMON
#define BRS_CFG_ACCEPT_HEADER_HTML \
  "text/html, " \
  BRS_CFG_ACCEPT_HEADER_COMMON


#ifdef GDI_USING_PNG

#define BRS_CFG_ACCEPT_OBJECT_HEADER \
  "image/vnd.wap.wbmp, image/gif, image/bmp, image/jpeg, image/png, audio/amr, audio/imelody, audio/midi, audio/wav, */*"
  
#else

#define BRS_CFG_ACCEPT_OBJECT_HEADER \
  "image/vnd.wap.wbmp, image/gif, image/bmp, image/jpeg, audio/amr, audio/imelody, audio/midi, audio/wav, */*"

#endif

#ifdef GDI_USING_PNG
#define BAM_CFG_SUPPORTED_IMAGE_MIME \
  "image/vnd.wap.wbmp," \
  "image/gif," \
  "image/bmp," \
  "image/png," \
  "image/jpeg"
#else
#define BAM_CFG_SUPPORTED_IMAGE_MIME \
  "image/vnd.wap.wbmp," \
  "image/gif," \
  "image/bmp," \
  "image/jpeg"
#endif



/* 
 *  Default "Accept-Charset:" header, sent by browser when retrieving a document.
 *
 *  If no Accept-Charset header is present in the request, the server
 *  may assume that all languages are equally acceptable, e.g. 
 *
 *  The default charsets: UTF-8, UTF-16, ISO-8859-1, UCS2, ASCII
 *  Customer can add additional in BAM_CFG_ACCEPT_CHARSET.
 * 
 *  Reference: Section 14.2 Accept-Charset in RFC2616
 */
const char *BAM_CFG_ACCEPT_CHARSET = 
/******** Begin of BAM_CFG_ACCEPT_CHARSET ********/
  "utf-8,"
  "utf-16," 
  "iso-8859-1," 
  "iso-10646-ucs-2," 
#ifdef __MMI_CHSET_GB18030__
  "gb18030,"
#endif
#ifdef __MMI_CHSET_GB2312__ 
  "gb2312,"
#endif 
#ifdef __MMI_CHSET_BIG5__ 
  "Big5," 
#endif 
#ifdef __MMI_CHSET_HKSCS__ 
  "hkscs,"
#endif 
#ifdef __MMI_CHSET_CEURO_ISO__ 
  "iso-8859-2," 
#endif 
#ifdef __MMI_CHSET_SEURO_ISO__ 
  "iso-8859-3," 
#endif 
#ifdef __MMI_CHSET_BALTIC_ISO__ 
  "iso-8859-4," 
#endif 
#ifdef __MMI_CHSET_CYRILLIC_ISO__ 
  "iso-8859-5," 
#endif 
#ifdef __MMI_CHSET_ARABIC_ISO__ 
  "iso-8859-6," 
#endif 
#ifdef __MMI_CHSET_GREEK_ISO__ 
  "iso-8859-7," 
#endif 
#ifdef __MMI_CHSET_HEBREW_ISO__ 
  "iso-8859-8," 
#endif 
#ifdef __MMI_CHSET_TURKISH_ISO__ 
  "iso-8859-9," 
#endif 
#ifdef __MMI_CHSET_NORDIC_ISO__ 
  "iso-8859-10," 
#endif 
#ifdef __MMI_CHSET_EUCKR_WIN__ 
  "EUC-KR," 
#endif 
#ifdef __MMI_CHSET_LATIN_ISO__ 
  "iso-8859-15," 
#endif 
#ifdef __MMI_CHSET_CEURO_WIN__ 
  "windows-1250," 
#endif
#ifdef __MMI_CHSET_CYRILLIC_WIN__ 
  "windows-1251," 
#endif
#ifdef __MMI_CHSET_WESTERN_WIN__ 
  "windows-1252," 
#endif 
#ifdef __MMI_CHSET_GREEK_WIN__ 
  "windows-1253," 
#endif 
#ifdef __MMI_CHSET_TURKISH_WIN__ 
  "windows-1254," 
#endif 
#ifdef __MMI_CHSET_HEBREW_WIN__ 
  "windows-1255," 
#endif 
#ifdef __MMI_CHSET_ARABIC_WIN__ 
  "windows-1256," 
#endif 
#ifdef __MMI_CHSET_BALTIC_WIN__ 
  "windows-1257," 
#endif 
#ifdef __MMI_CHSET_VIETNAMESE_WIN__ 
  "windows-1258," 
#endif 
#ifdef __MMI_CHSET_THAI_WINDOWS__ 
  "windows-874," 
#endif 
  /* Customer may add additional charset after this line */

  /* Customer may add additional charset before this line */
  "us-ascii";
/******** End of BAM_CFG_ACCEPT_CHARSET ********/


/* 
 * Define the default CSS style sheet used in BRS.
 * 
 * Note: the syntax of the defined CSS style sheet MUST conform to W3C CSS.
 * 
 * This default CSS style sheet defines the behaviour of BRS layout engine for all mark-up content. 
 * The customer may change some of these CSS rules, such as the background color or font settings, 
 * when configuring the layout of a small screen device. 
 * 
 * Please also note that the CSS rules configured with '!important' in this default style sheet 
 * will override the CSS rules specified in the web pages, in case of conflict.
 * 
 */
#ifdef BRS_CFG_LE_CSS_SUPPORT_ACTIVE_PSEUDO_CLASS
#ifdef MSF_CFG_VECTOR_FONT_SUPPORT
#define BAM_CFG_BRS_CSS_DEFAULT_STYLE_SHEET \
  "BODY,CARD{ width: auto !important; height: auto !important; margin-right: 0 !important; padding-top:2px; padding-left:8px !important} \n" /* MAUI_03010219 */ /* MAUI_03089482 (, CARD) */ \
  "OL UL, UL OL, UL UL, OL OL  { margin-top: 0; margin-bottom: 0 } \n" \
  "HR {margin-top: 10px; margin-bottom 10px } \n" /* MAUI_02443628 */\
  "A:link, anchor:link { color: blue } \n" \
  "A:visited, anchor:visited { color: red } \n" \
  "A:focus, anchor:focus, A > *:focus { color: black ; background-color: #9E7BFF  } \n" \
  "area {color:blue} \n" \
  "area:focus {color:red} \n" \
  "do:focus, textarea:focus, input:focus, " \
  "object:focus, select:focus{border-color: black !important; border-style: dotted !important; border-width: 1px !important; padding: 0px !important} \n" \
  "img:focus {color: black !important; border-color: black !important; border-style: dotted !important; border-width: 1px !important;padding: 0px !important} \n" \
  "A > IMG { padding: 1px !important; border-width: 0px } \n" \
  "A:active, anchor:active, do:active, textarea:active, " \
  "img:active, object:active, input:active { color: red } \n" \
  "do, object, select {padding: 1px} \n" \
  "input[type='checkbox'], input[type='radio'],input[type='button'], input[type='reset'], input[type='submit'] {padding: 1px} \n" \
  "img { padding: 0px; } \n" \
  "caption, th {text-align: center} \n" \
  "optgroup, address, dfn, i, cite, em, var {font-style: italic} \n" /* MAUI_02441305 */ \
  "option {font-style: normal} \n" \
  "h1 {font-size: xx-large; font-style: normal; font-weight: 700;} \n" \
  "h2 {font-size: x-large; font-style: normal; font-weight: 700} \n" \
  "h3 {font-size: large; font-style: normal; font-weight: 700} \n" \
  "h4 {font-size: medium; font-style: normal; font-weight: 700} \n" \
  "h5 {font-size: small; font-style: normal; font-weight: 700} \n" \
  "h6 {font-size: x-small; font-style: normal; font-weight: 700} \n" \
  "plaintext, pre {white-space: pre; font-family: monospace} \n" \
 "code, kbd, samp, tt {font-family: monospace} \n" \
  "big {font-size: large} \n" \
  "small {font-size: small} \n" \
  "b, strong {font-weight: 700} \n" \
  "th {font-weight: 700} \n" \
  "ol {list-style-type: decimal} \n" \
  "menu, dir, ul {list-style-type: disc} \n" \
  "u, a[href], anchor {text-decoration: underline} \n" \
  "blink {text-decoration: blink} " \
  "input { font-family: sans-serif }" \
  "table { border-spacing: 2px; text-align: left; empty-cells: show }" \
  "tr {vertical-align: middle } " \
  "td, th { vertical-align: inherit; background-image: inherit; " \
  "         background-color: inherit }" \
  "center > * { margin-left: auto; margin-right: auto } " \
  "center { text-align: center }" \
  "td[align=center] > * {margin-left: auto; margin-right: auto}" \
  "div[align=center] > * {margin-left: auto; margin-right: auto}" \
  "div[align=center] { text-align: center }"\
  "div {height:auto !important} " \
  "pre {height:auto !important} " \
  "a * {background-color: inherit}"\
  /* */"input, textarea {border-style: solid; border-width: 1px; border-color: black}"  \
  "input[type='checkbox'], input[type='radio'], input[type='submit'], input[type='reset'], " \
  "input[type='image'], input[type='button'] {border-style: none; border-width: 0px}" \
  "input[type='checkbox']:focus, input[type='radio']:focus, input[type='submit']:focus, "\
  "input[type='reset']:focus, input[type='image']:focus, "\
  "input[type='button']:focus {border-style: dotted; border-width: 1px;padding: 0px}"\
  "marquee { margin-right: auto !important;}" \
  "input[disabled] {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */ \
  "input[disabled]:active {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */ \
  "input[disabled]:focus {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */ \
  "textarea[disabled] {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */ \
  "textarea[disabled]:focus {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */ \
  "select[disabled] {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */ \
  "select[disabled]:focus {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */
#else
  #define BAM_CFG_BRS_CSS_DEFAULT_STYLE_SHEET \
  "BODY,CARD { width: auto !important; height: auto !important; margin-right: 0 !important; padding-top:2px; padding-left:8px !important} \n" /* MAUI_03010219 */ /* MAUI_03089482 (, CARD) */ \
  "OL UL, UL OL, UL UL, OL OL  { margin-top: 0; margin-bottom: 0 } \n" \
  "HR {margin-top: 10px; margin-bottom 10px } \n" /* MAUI_02443628 */\
  "A:link, anchor:link { color: blue } \n" \
  "A:visited, anchor:visited { color: red } \n" \
  "A:focus, anchor:focus, A > *:focus { color: black ; background-color: #9E7BFF  } \n" \
  "area {color:blue} \n" \
  "area:focus {color:red} \n" \
  "do:focus, textarea:focus, input:focus, " \
  "object:focus, select:focus{border-color: black !important; border-style: dotted !important; border-width: 1px !important; padding: 0px !important} \n" \
  "img:focus {color: black !important; border-color: black !important; border-style: dotted !important; border-width: 1px !important;padding: 0px !important} \n" \
  "A > IMG { padding: 1px !important; border-width: 0px } \n" \
  "A:active, anchor:active, do:active, textarea:active, " \
  "img:active, object:active, input:active { color: red } \n" \
  "do, object, select {padding: 1px} \n" \
  "input[type='checkbox'], input[type='radio'], input[type='button'], input[type='reset'] , input[type='submit']{padding: 1px} \n" \
  "img { padding: 0px; } \n" \
  "caption, th {text-align: center} \n" \
  "optgroup, address, dfn, i, cite, em, var {font-style: italic} \n" /* MAUI_02441305 */ \
  "option {font-style: normal} \n" \
  "h1 {font-size: xx-large; font-style: normal; font-weight: 700} \n" \
  "h2 {font-size: x-large; font-style: normal; font-weight: 700} \n" \
  "h3 {font-size: medium; font-style: normal; font-weight: 700} \n" /* MAUI_02445015 */ \
  "h4 {font-size: medium; font-style: normal; font-weight: 700} \n" /* MAUI_02445015 */ \
  "h5 {font-size: small; font-style: normal; font-weight: 700} \n" \
  "h6 {font-size: small; font-style: normal; font-weight: 700} \n" /* MAUI_02445015 */ \
  "plaintext, pre {white-space: pre; font-family: monospace} \n" \
  "code, kbd, samp, tt {font-family: monospace} \n" \
  "big {font-size: large} \n" \
  "small {font-size: small} \n" \
  "b, strong {font-weight: 700} \n" \
  "th {font-weight: 700} \n" \
  "ol {list-style-type: decimal} \n" \
  "menu, dir, ul {list-style-type: disc} \n" \
  "u, a[href], anchor {text-decoration: underline} \n" \
  "blink {text-decoration: blink} " \
  "input { font-family: sans-serif }" \
  "table { border-spacing: 2px; text-align: left; empty-cells: show }" \
  "tr {vertical-align: middle } " \
  "td, th { vertical-align: inherit; background-image: inherit; " \
  "         background-color: inherit }" \
  "center > * { margin-left: auto; margin-right: auto } " \
  "center { text-align: center }" \
  "td[align=center] > * {margin-left: auto; margin-right: auto}" \
  "div[align=center] > * {margin-left: auto; margin-right: auto}" \
  "div[align=center] { text-align: center }"\
  "div {height:auto !important} " \
  "pre {height:auto !important} " \
  "a * {background-color: inherit}"\
  /* */"input, textarea {border-style: solid; border-width: 1px; border-color: black}"  \
  "input[type='checkbox'], input[type='radio'], input[type='submit'], input[type='reset'], " \
  "input[type='image'], input[type='button'] {border-style: none; border-width: 0px}" \
  "input[type='checkbox']:focus, input[type='radio']:focus, input[type='submit']:focus, "\
  "input[type='reset']:focus, input[type='image']:focus, "\
  "input[type='button']:focus {border-style: dotted; border-width: 1px;padding: 0px}"\
  "marquee { margin-right: auto !important;}" \
  "input[disabled] {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */ \
  "input[disabled]:active {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */ \
  "input[disabled]:focus {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */ \
  "textarea[disabled] {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */ \
  "textarea[disabled]:focus {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */ \
  "select[disabled] {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */ \
  "select[disabled]:focus {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */
#endif
#else
#ifdef MSF_CFG_VECTOR_FONT_SUPPORT
#define BAM_CFG_BRS_CSS_DEFAULT_STYLE_SHEET \
  "BODY,CARD { width: auto !important; height: auto !important; margin-right: 0 !important; padding-top:2px; padding-left:8px !important} \n" /* MAUI_03010219 */ /* MAUI_03089482 (, CARD) */ \
  "OL UL, UL OL, UL UL, OL OL  { margin-top: 0; margin-bottom: 0 } \n" \
  "HR {margin-top: 10px; margin-bottom 10px } \n" /* MAUI_02443628 */\
  "A:link, anchor:link { color: blue } \n" \
  "A:visited, anchor:visited { color: red } \n" \
  "A:focus, anchor:focus, A > *:focus { color: black !important; background-color: #9E7BFF !important } \n" \
  "area {color:blue} \n" \
  "area:focus {color:red} \n" \
  "do:focus, textarea:focus, input:focus, " \
  "object:focus, select:focus{border-color: black !important; border-style: dotted !important; border-width: 1px !important; padding: 0px !important} \n" \
  "img:focus {color: black !important; border-color: black !important; border-style: dotted !important; border-width: 1px !important;padding: 0px !important} \n" \
  "A > IMG { padding: 1px !important; border-width: 0px } \n" \
  "A:active, anchor:active, do:active, textarea:active, " \
  "img:active, object:active, input:active { color: red } \n" \
  "do, object, select {padding: 1px} \n" \
  "input[type='checkbox'], input[type='radio'], input[type='button'], input[type='reset'] , input[type='submit'] {padding: 1px} \n" \
  "img { padding: 0px; } \n" \
  "caption, th {text-align: center} \n" \
  "optgroup, address, dfn, i, cite, em, var {font-style: italic} \n" /* MAUI_02441305 */\
  "option {font-style: normal} \n" \
  "h1 {font-size: xx-large; font-style: normal; font-weight: 700;} \n" \
  "h2 {font-size: x-large; font-style: normal; font-weight: 700} \n" \
  "h3 {font-size: large; font-style: normal; font-weight: 700} \n" \
  "h4 {font-size: medium; font-style: normal; font-weight: 700} \n" \
  "h5 {font-size: small; font-style: normal; font-weight: 700} \n" \
  "h6 {font-size: x-small; font-style: normal; font-weight: 700} \n" \
  "plaintext, pre {white-space: pre; font-family: monospace} \n" \
 "code, kbd, samp, tt {font-family: monospace} \n" \
  "big {font-size: large} \n" \
  "small {font-size: small} \n" \
  "b, strong {font-weight: 700} \n" \
  "th {font-weight: 700} \n" \
  "ol {list-style-type: decimal} \n" \
  "menu, dir, ul {list-style-type: disc} \n" \
  "u, a[href], anchor {text-decoration: underline} \n" \
  "blink {text-decoration: blink} " \
  "input { font-family: sans-serif }" \
  "table { border-spacing: 2px; text-align: left; empty-cells: show }" \
  "tr {vertical-align: middle } " \
  "td, th { vertical-align: inherit; background-image: inherit; " \
  "         background-color: inherit }" \
  "center > * { margin-left: auto; margin-right: auto } " \
  "center { text-align: center }" \
  "td[align=center] > * {margin-left: auto; margin-right: auto}" \
  "div[align=center] > * {margin-left: auto; margin-right: auto}" \
  "div[align=center] { text-align: center }"\
  "div {height:auto !important} " \
  "pre {height:auto !important} " \
  "a * {background-color: inherit}"\
  /* */"input, textarea {border-style: solid; border-width: 1px; border-color: black}"  \
  "input[type='checkbox'], input[type='radio'], input[type='submit'], input[type='reset'], " \
  "input[type='image'], input[type='button'] {border-style: none; border-width: 0px}" \
  "input[type='checkbox']:focus, input[type='radio']:focus, input[type='submit']:focus, "\
  "input[type='reset']:focus, input[type='image']:focus, "\
  "input[type='button']:focus {border-style: dotted; border-width: 1px;padding: 0px}"\
  "marquee { margin-right: auto !important;}" \
  "input[disabled] {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */ \
  "input[disabled]:active {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */ \
  "input[disabled]:focus {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */ \
  "textarea[disabled] {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */ \
  "textarea[disabled]:focus {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */ \
  "select[disabled] {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */ \
  "select[disabled]:focus {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */
#else
  #define BAM_CFG_BRS_CSS_DEFAULT_STYLE_SHEET \
  "BODY,CARD { width: auto !important; height: auto !important; margin-right: 0 !important; padding-top:2px; padding-left:8px !important} \n" /* MAUI_03010219 */ /* MAUI_03089482 (, CARD) */ \
  "OL UL, UL OL, UL UL, OL OL  { margin-top: 0; margin-bottom: 0 } \n" \
  "HR {margin-top: 10px; margin-bottom 10px } \n" /* MAUI_02443628 */\
  "A:link, anchor:link { color: blue } \n" \
  "A:visited, anchor:visited { color: red } \n" \
  "A:focus, anchor:focus, A > *:focus { color: black !important; background-color: #9E7BFF !important } \n" \
  "area {color:blue} \n" \
  "area:focus {color:red} \n" \
  "do:focus, textarea:focus, input:focus, " \
  "object:focus, select:focus{border-color: black !important; border-style: dotted !important; border-width: 1px !important; padding: 0px !important} \n" \
  "img:focus {color: black !important; border-color: black !important; border-style: dotted !important; border-width: 1px !important;padding: 0px !important} \n" \
  "A > IMG { padding: 1px !important; border-width: 0px } \n" \
  "A:active, anchor:active, do:active, textarea:active, " \
  "img:active, object:active, input:active { color: red } \n" \
  "do, object, select {padding: 1px} \n" \
  "input[type='checkbox'], input[type='radio'],input[type='button'], input[type='reset'] , input[type='submit']  {padding: 1px} \n" \
  "img { padding: 0px;} \n" \
  "caption, th {text-align: center} \n" \
  "optgroup, address, dfn, i, cite, em, var {font-style: italic} \n" /* MAUI_02441305 */ \
  "option {font-style: normal} \n" \
  "h1 {font-size: xx-large; font-style: normal; font-weight: 700} \n" \
  "h2 {font-size: x-large; font-style: normal; font-weight: 700} \n" \
  "h3 {font-size: medium; font-style: normal; font-weight: 700} \n" /* MAUI_02445015 */ \
  "h4 {font-size: medium; font-style: normal; font-weight: 700} \n" /* MAUI_02445015 */ \
  "h5 {font-size: small; font-style: normal; font-weight: 700} \n" \
  "h6 {font-size: small; font-style: normal; font-weight: 700} \n" /* MAUI_02445015 */ \
  "plaintext, pre {white-space: pre; font-family: monospace} \n" \
  "code, kbd, samp, tt {font-family: monospace} \n" \
  "big {font-size: large} \n" \
  "small {font-size: small} \n" \
  "b, strong {font-weight: 700} \n" \
  "th {font-weight: 700} \n" \
  "ol {list-style-type: decimal} \n" \
  "menu, dir, ul {list-style-type: disc} \n" \
  "u, a[href], anchor {text-decoration: underline} \n" \
  "blink {text-decoration: blink} " \
  "input { font-family: sans-serif }" \
  "table { border-spacing: 2px; text-align: left; empty-cells: show }" \
  "tr {vertical-align: middle } " \
  "td, th { vertical-align: inherit; background-image: inherit; " \
  "         background-color: inherit }" \
  "center > * { margin-left: auto; margin-right: auto } " \
  "center { text-align: center }" \
  "td[align=center] > * {margin-left: auto; margin-right: auto}" \
  "div[align=center] > * {margin-left: auto; margin-right: auto}" \
  "div[align=center] { text-align: center }"\
  "div {height:auto !important} " \
  "pre {height:auto !important} " \
  "a * {background-color: inherit}"\
  /* */"input, textarea {border-style: solid; border-width: 1px; border-color: black}"  \
  "input[type='checkbox'], input[type='radio'], input[type='submit'], input[type='reset'], " \
  "input[type='image'], input[type='button'] {border-style: none; border-width: 0px}" \
  "input[type='checkbox']:focus, input[type='radio']:focus, input[type='submit']:focus, "\
  "input[type='reset']:focus, input[type='image']:focus, "\
  "input[type='button']:focus {border-style: dotted; border-width: 1px;padding: 0px}"\
  "marquee { margin-right: auto !important;}" \
  "input[disabled] {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */ \
  "input[disabled]:active {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */ \
  "input[disabled]:focus {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */ \
  "textarea[disabled] {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */ \
  "textarea[disabled]:focus {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */ \
  "select[disabled] {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */ \
  "select[disabled]:focus {border-style: none ; color:#999999;background-color:gray;}" /* MAUI_01546590 */
#endif
#endif

/* The WML standard says that the history stack must be cleared
 * when entering a card that has the "newcontext" attribute set,
 * or if a script calls the function Browser.newContext. Also,
 * calling the function BRSif_loadUrl sets the "newcontext" attribute
 * by default.
 * However, frequent emptying of the history stack usually implies
 * that the history becomes very shallow, and limits the usefulness
 * of the BACK and FWD buttons.
 * By default, BRS will let the history remain intact on "newcontext".
 * The following configurations are available:
 *   0: Never clear history on newcontext. (default)
 *   1: Always clear history on newcontext.
 *   2: Never clear history on newcontext, and don't set "newcontext" in BRSif_loadUrl. 
 *		(recommended, but violates WML spec)
 *   3: Always clear history on newcontext, but don't set "newcontext" in BRSif_loadUrl.
 *		(conforms to WML spec)
 */
#define BAM_CFG_BRS_CLEAR_HISTORY_ON_NEWCONTEXT	3


/*
 * How to handle redirections:
 *   1      Normal:   always automatic redirection, and POST is changed into GET
 *                      (this is what most browsers do)
 *   2      Cautious: responses with status codes 301 and 307 are always
 *                      shown to the user
 *   3      Special:  for responses with status codes 301, 302, 307:
 *                      if GET, do automatic redirection,
 *                      if POST, ask for user confirmation
 */
#define BAM_CFG_BRS_REDIRECT_HANDLING 1 


#ifdef MTK_TMP_PATCH /* CR34945 */
/** 
 * If BAM_CFG_BRS_IGNORE_EMPTYOK == 1, Browser will disable the checking of 
 *    (1) the attribute "emptyok" in web pages and
 *    (2) the property "-wap-input-required" in CSS,
 * so that Browser will not prompt any error dialog if the user input does not conform to the attribute "emptyok" or 
 * the property "-wap-input-required".   
 *
 * Default: BAM_CFG_BRS_IGNORE_EMPTYOK == 0
 */
#define BAM_CFG_BRS_IGNORE_EMPTYOK 0
#endif /* MTK_TMP_PATCH */

/* defines a table of file extensions and their corresponding mime-types
 * the mime-types defined here are used when a page is loaded via file:// scheme
 * by default, all file extensions will be mapped to text/plain
 * table must be terminated by {0, 0} entry
 */
#ifdef BAM_CFG_ENABLE_FILE_SCHEME
const char *bam_mimeext[][2] = 
{
  {"htm", "text/html"},
  {"html", "text/html"},
  {0, 0}
};
#endif  /* BAM_CFG_ENABLE_FILE_SCHEME */

/* Define if a dialog asking the user if the user wants to make an  */
/* anonymous handshake or abort handshake when the CA certificate   */
/* could not be verified (used in TLS/SSL and WTLS).                */
/*customer can enable or disable by setting it value to 1 or 0 respectively*/
#define BAM_CFG_SEC_CONN_WITHOUT_CERT_DLG     0

static MSF_BOOL bam_is_set_profile_process;
static MSF_UINT8 bam_set_profile_request_id;

static MSF_INT32 bam_registry_value_table[BAM_REGISTRY_ENUM_TOTAL];
static char *bam_registry_value_string_table[BAM_REGISTRY_ENUM_TOTAL];
static bam_profile_req_struct bam_pending_profile_req;
static bam_profile_req_struct *bam_pending_profile = &bam_pending_profile_req;

extern U16 gMaxDeployedLangs;
extern sLanguageDetails *gLanguageArray;
extern U16 gCurrLangIndex;

/************************************************************
 * Function declarations
 ************************************************************/
/* 
 * There is no any module other than BAM has chance to update registry. BAM has 
 * no chance to receive/process response signal to inform registry is updated 
 * by other module. 
 */
bam_registry_content_t bam_registry_active_profile;


static void bam_registry_set_defaults(void);

static void bam_registry_commit_em_settings(void);
static char* bam_registry_map_accept_header(int em_index);
static void bam_registry_update_active_profile_settings(int acct_id, int conn_type, char *proxy_addr, int proxy_port, char *username, char *password);

/************************************************************
 * Functions
 ************************************************************/


/*****************************************************************************
 * FUNCTION
 *  bam_registry_init
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_registry_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_main_set_module_state(BAM_INIT_REGISTRY);
    bam_main_set_module_state(BAM_INIT_PROFILE);
	
	/* 
	 * There is no any module other than BAM has chance to update registry. BAM
	 * has no chance to receive/process response signal to inform registry is 
	 * updated by other module. 
	 */

    for (i = 0; i < BAM_REGISTRY_ENUM_TOTAL; i++)
    {
        bam_registry_value_table[i] = BAM_REG_INT_INIT_VAL;
        bam_registry_value_string_table[i] = BAM_REG_STR_INIT_VAL;
    }

  
    bam_registry_set_defaults();
    bam_registry_commit_em_settings();

    bam_pending_profile->int_value_table = NULL;
    bam_pending_profile->str_value_table = NULL;
    bam_pending_profile->profile = NULL;

		
    bam_main_remove_module_state(BAM_INIT_REGISTRY);
}


/*****************************************************************************
 * FUNCTION
 *  bam_registry_terminate
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_registry_terminate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < BAM_REGISTRY_ENUM_TOTAL; i++)
    {
        BAM_FREE(bam_registry_value_string_table[i]);
        bam_registry_value_string_table[i] = BAM_REG_STR_INIT_VAL;
    }
        
    bam_signal_deregister(BAM_SIG_DEST_REGISTRY);
}

/* 
 * There is no any module other than BAM has chance to update registry. BAM has 
 * no chance to receive/process response signal to inform registry is updated 
 * by other module. 
 */

  
MSF_BOOL bam_registry_commit_item_in_registry(int key, int path, int type,

											  int i_val, char *s_val, bam_set_profile_option_enum type1)
{
    MSF_BOOL ret=TRUE;
    if (path != -1)
    {
        if (type == 0)
        {
            if(bam_registry_value_table[key] == i_val)
	    {
                ret= FALSE;
            }
	    else
	    {
            bam_registry_value_table[key] = i_val;
        }
			
        }
        else
        {
            if((bam_registry_value_string_table[key] != NULL) && (s_val != NULL))
            {
                if(strcmp(bam_registry_value_string_table[key], s_val) == 0)
                    ret= FALSE;
            }
            if((bam_registry_value_string_table[key] == NULL) && (s_val == NULL))
            {
                ret= FALSE;
            }
            if(bam_registry_value_string_table[key] != NULL)
                BAM_FREE(bam_registry_value_string_table[key]);
            bam_registry_value_string_table[key] = msf_cmmn_strdup (MSF_MODID_BAM, s_val);
        }
		switch(path)
        {
		case bam_registry_path_brs:
			if(bam_sif_get_brs_status() == BAM_SIF_BRS_READY && (type1==BAM_SET_PROFILE_TO_BRS))
			{
			BRSif_set_preference_values(key,i_val,(unsigned char*)BAM_CMN_HNV(s_val));
			BRSif_appPrefChanged(MSF_MODID_BAM, 1);
			}
		break;
		default:
			break;

        }
    }
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  bam_registry_set_defaults
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bam_registry_set_defaults(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_registry_change_key_str_value(BAM_REGISTRY_ENUM_OBJ_ASK, BAM_CFG_DEFAULT_OBJ_ASK, BAM_SET_PROFILE_TO_BRS);
    bam_registry_change_key_str_value(BAM_REGISTRY_ENUM_OBJ_LOAD, BAM_CFG_DEFAULT_OBJ_LOAD,BAM_SET_PROFILE_TO_BRS);
    bam_registry_change_key_int_value(BAM_REGISTRY_ENUM_TIMEOUT, BAM_CFG_DEFAULT_BRS_TIMEOUT, BAM_SET_PROFILE_TO_BRS);
    bam_registry_change_key_int_value(BAM_REGISTRY_ENUM_USER_TIMEOUT, BAM_CFG_DEFAULT_TIMEOUT, BAM_SET_PROFILE_TO_BRS);
    bam_registry_change_key_int_value(BAM_REGISTRY_ENUM_COOKIES, BAM_CFG_REGISTRY_DEFAULT_COOKIES, BAM_SET_PROFILE_TO_BRS);
    bam_registry_change_key_int_value(BAM_REGISTRY_ENUM_CACHEON, 1, BAM_SET_PROFILE_TO_BRS);
    bam_registry_change_key_int_value(BAM_REGISTRY_ENUM_CASHSIZE, BAM_CFG_REGISTRY_DEFAULT_CACHESIZE, BAM_SET_PROFILE_TO_BRS);
    bam_registry_change_key_int_value(BAM_REGISTRY_ENUM_HISTSIZE, BAM_CFG_REGISTRY_DEFAULT_HISTSIZE, BAM_SET_PROFILE_TO_BRS);
    bam_registry_change_key_int_value(BAM_REGISTRY_ENUM_LDNOMIME, BAM_CFG_REGISTRY_DEFAULT_LDNOMIME, BAM_SET_PROFILE_TO_BRS);
    bam_registry_change_key_int_value(BAM_REGISTRY_ENUM_REFRESH, BAM_CFG_REGISTRY_DEFAULT_REFRESH, BAM_SET_PROFILE_TO_BRS);
    bam_registry_change_key_int_value(BAM_REGISTRY_ENUM_USE_CAHCE, BAM_CFG_REGISTRY_DEFAULT_USE_CACHE, BAM_SET_PROFILE_TO_BRS);
    bam_registry_change_key_int_value(BAM_REGISTRY_ENUM_USE_CSS, BAM_CFG_REGISTRY_DEFAULT_USE_CSS, BAM_SET_PROFILE_TO_BRS);
    bam_registry_change_key_int_value(BAM_REGISTRY_ENUM_INLINE_DO, BAM_CFG_REGISTRY_DEFAULT_INLINE_DO, BAM_SET_PROFILE_TO_BRS);
    bam_registry_change_key_int_value(BAM_REGISTRY_ENUM_CACHE_MODE, 3, BAM_SET_PROFILE_TO_BRS);
    bam_registry_commit_item_in_registry(BAM_REGISTRY_ENUM_PRX_RLM, bam_registry_key_table[BAM_REGISTRY_ENUM_PRX_RLM].path, BAM_REG_STR,-1, BAM_CFG_REGISTRY_DEFAULT_PRX_RLM, BAM_SET_PROFILE_TO_BRS);
    bam_registry_commit_item_in_registry(BAM_REGISTRY_ENUM_PRX_SECP, bam_registry_key_table[BAM_REGISTRY_ENUM_PRX_SECP].path, BAM_REG_INT,0, NULL, BAM_SET_PROFILE_TO_BRS);
}


static void
bam_registry_commit_em_settings(void)
{
    char *ua_prof, *accept_header;
    	const char *language_header;
	
#ifdef OBIGO_DEFAULT_CONFIG_UA_STRING 
	char ua[MAX_UA_STRING_LEN+1];
	applib_get_dynamic_ua(ua);
#else
#ifdef OBIGO_DEFAULT_PART_CONFIG_UA_STRING
	char ua[MAX_UA_STRING_LEN+1];
	brs_get_default_dynamic_ua_string(ua);
#else
	char *ua;
    ua = (char*) applib_inet_get_user_agent_string();
#endif
#endif
	

    if(ua)
    {
      bam_registry_value_string_table[BAM_REGISTRY_ENUM_USER_AGT] = msf_cmmn_strdup(MSF_MODID_BAM, ua);
    }

    accept_header = bam_registry_map_accept_header(wap_custom_get_accept_header_index());
    bam_registry_value_string_table[BAM_REGISTRY_ENUM_ACCEPT_HEADER] = msf_cmmn_strdup(MSF_MODID_BAM, accept_header);
	bam_registry_value_string_table[BAM_REGISTRY_ENUM_ACCEPT_OBJ_HEADER] = msf_cmmn_strdup(MSF_MODID_BAM, BRS_CFG_ACCEPT_OBJECT_HEADER);
    language_header=bam_cfg_default_accept_language_header();
	if(language_header)
	{
	   bam_registry_value_string_table[BAM_REGISTRY_ENUM_ACCEPT_LANGUAGE_HEADER]=msf_cmmn_strdup(MSF_MODID_BAM, language_header);
	}
    ua_prof = (char*) applib_inet_get_user_agent_profile();
    if (ua_prof)
      {
        bam_registry_value_string_table[BAM_REGISTRY_ENUM_UA_PROF] = msf_cmmn_strdup(MSF_MODID_BAM, ua_prof);
    }    
}

static char*
bam_registry_map_accept_header(int em_index)
{
    switch(em_index)
    {
    case APPLIB_INET_ACCEPT_HEADER_WAP_1_2_1:
        return (char*) BRS_CFG_ACCEPT_HEADER_WAP_1_2_1;
    case APPLIB_INET_ACCEPT_HEADER_WAP_2_0:
        return (char*) BRS_CFG_ACCEPT_HEADER_WAP_2_0;
    case APPLIB_INET_ACCEPT_HEADER_WML:
        return (char*) BRS_CFG_ACCEPT_HEADER_WML;
    case APPLIB_INET_ACCEPT_HEADER_XHTML:
        return (char*) BRS_CFG_ACCEPT_HEADER_XHTML;
    case APPLIB_INET_ACCEPT_HEADER_HTML:
        return (char*) BRS_CFG_ACCEPT_HEADER_HTML;
    default:
        return (char*) BRS_CFG_ACCEPT_HEADER_WAP_2_0;
    }
}

void
bam_registry_handle_em_setting_changed_ind(void *p)
{
  bam_em_setting_changed_ind_struct *em_settings = (bam_em_setting_changed_ind_struct*)p;
  char *accept_header;
  switch(em_settings->opt)
  {
  case APPLIB_INET_UA_STRING_OPT:
      if(em_settings->value_str)
      {
        if(bam_sif_get_brs_status() == BAM_SIF_BRS_READY )
		{
		    BRSif_set_preference_values(BAM_REGISTRY_ENUM_USER_AGT,0,(unsigned char*)BAM_CMN_HNV((unsigned char*)em_settings->value_str));
		    BRSif_appPrefChanged(MSF_MODID_BAM, 1);
		}
        if(bam_registry_value_string_table[BAM_REGISTRY_ENUM_USER_AGT] != NULL)
            BAM_FREE(bam_registry_value_string_table[BAM_REGISTRY_ENUM_USER_AGT]);
        bam_registry_value_string_table[BAM_REGISTRY_ENUM_USER_AGT] = msf_cmmn_strdup(MSF_MODID_BAM, em_settings->value_str);
      }
      break;
  case APPLIB_INET_UA_PROFILE_OPT:
      if(em_settings->value_str)
      {
          if(bam_registry_value_string_table[BAM_REGISTRY_ENUM_UA_PROF] != NULL)
              BAM_FREE(bam_registry_value_string_table[BAM_REGISTRY_ENUM_UA_PROF]);
          bam_registry_value_string_table[BAM_REGISTRY_ENUM_UA_PROF] = msf_cmmn_strdup(MSF_MODID_BAM, em_settings->value_str);
      }
      break;
  case APPLIB_INET_ACCEPT_HEADER_OPT:
      accept_header = bam_registry_map_accept_header(em_settings->value_int);
	  if(bam_sif_get_brs_status() == BAM_SIF_BRS_READY)
	  {
	      BRSif_set_preference_values(BAM_REGISTRY_ENUM_ACCEPT_HEADER,0, (unsigned char*)BAM_CMN_HNV((unsigned char*)em_settings->value_str));
	      BRSif_appPrefChanged(MSF_MODID_BAM, 1);
	  }
      if(bam_registry_value_string_table[BAM_REGISTRY_ENUM_ACCEPT_HEADER] != NULL)
          BAM_FREE(bam_registry_value_string_table[BAM_REGISTRY_ENUM_ACCEPT_HEADER]);
      bam_registry_value_string_table[BAM_REGISTRY_ENUM_ACCEPT_HEADER] = msf_cmmn_strdup(MSF_MODID_BAM, accept_header);
      break;
  default:
      break;
  } 
}



/*****************************************************************************
 * FUNCTION
 *  bam_registry_get_int
 * DESCRIPTION
 *
 * PARAMETERS
 *  key     [IN]
 * RETURNS
 *
 *****************************************************************************/
MSF_INT32 bam_registry_get_int(unsigned key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return bam_registry_value_table[key];
}




#ifdef MSF_MODID_CPS


/*****************************************************************************
 * FUNCTION
 *  bam_registry_set_conn_profile_by_cps
 * DESCRIPTION
 *
 * PARAMETERS
 *  int_value_table     [?]
 *  str_value_table     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_registry_set_conn_profile_by_cps(MSF_INT32 *int_value_table, char **str_value_table)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cpm_profile_t profile;
    char *strval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Set the integer values */
    profile.dataAccount = int_value_table[BAM_SETTING_ID_CON_ACCOUNT];

    switch (int_value_table[BAM_SETTING_ID_CON_TYPE])
    {
        case bam_setting_val_conn_type_http:
            profile.connectionType = CPM_HTTP;
            break;

        case bam_setting_val_conn_type_connection_oreinted:
            profile.connectionType = CPM_CO_WSP;
            break;

        case bam_setting_val_conn_type_connection_oreinted_secure:
            profile.connectionType = CPM_CO_WSP_SEC;
            break;

        default:
            /* Invalid value */
            return;
    }

    profile.addrType = int_value_table[BAM_SETTING_ID_CON_ADDR_TYPE];
    profile.proxyPort = int_value_table[BAM_SETTING_ID_CON_PORT];

    /* Set the string values without allocating memory */
    strval = str_value_table[BAM_SETTING_ID_CON_ADDR];
    profile.proxyAddr = (strval != BAM_REG_STR_INIT_VAL) ? strval : NULL;
    strval = str_value_table[BAM_SETTING_ID_CON_USER];
    profile.username = (strval != BAM_REG_STR_INIT_VAL) ? strval : NULL;
    strval = str_value_table[BAM_SETTING_ID_CON_PWD];
    profile.password = (strval != BAM_REG_STR_INIT_VAL) ? strval : NULL;
    profile.url = NULL;

    CPMif_set_profile(MSF_MODID_BAM, CPM_APP_BROWSER, (cpm_profile_t*) & profile);
}

#endif /* MSF_MODID_CPS */

static char*
bam_registry_validate_proxy_addr (char *proxy_ip)
{
  int   i = 0;
  int   j = 0;
  char *s;
  char addr[4][4];

  if (proxy_ip == NULL)
    goto error;

  s = proxy_ip;
  
  /*Check that there is 4 address parts and copy parts to array*/
  while (*s != '\0')
  {
    if (*s != '.')
    {
      if (j > 2)
        goto error; /*To many characters in part*/

      if(ct_isdigit(*s))
      {
        addr[i][j] = *s;
        j++;
      }
      else
        goto error; /*Ilegal character*/
    }
    else
    {
      if (j == 0)
        goto error;; /*No sub part between dots*/

      addr[i][j] = '\0';
     
      if (i < 3)
        i++;
      else
        goto error;; /*To many parts*/

      j = 0;
    }
    s++;
  }

  addr[i][j] = '\0';

  /*Check that sub parts are < 255*/
  if ((atoi ((const char *)&addr[0]) > 255) || (atoi ((const char *)&addr[1]) > 255) || 
      (atoi ((const char *)&addr[2]) > 255) || (atoi ((const char *)&addr[3]) > 255))
      goto error;

  if ((atoi ((const char *)&addr[0]) == 0) && (atoi ((const char *)&addr[1]) == 0) &&
      (atoi ((const char *)&addr[2]) == 0) && (atoi ((const char *)&addr[3]) == 0))
    return NULL;
  else      
    return proxy_ip;


error:
  return NULL;
}

static char*
bam_registry_remove_str_str (char* s, char* remove)
{
  char *p;
  char *str;  
  int   l;
  int   rl;
  int   sp;
  int   ep;

  if ((s == NULL) || (remove == NULL))
  {
    return  msf_cmmn_strdup (MSF_MODID_BAM, s);
  }
  
  if ((p = strstr (s, remove)) == NULL)
  {
    /*String not in stirng*/
    return  msf_cmmn_strdup (MSF_MODID_BAM, s);
  }

  l  = strlen (s);
  rl = strlen (remove);

  str = BAM_ALLOC (l - rl + 1);

  if (l == rl)
  {
    str[0] = '\0';
    return str;
  }

  sp = (p - s);
  ep = sp + rl;

  if (s[ep] == ',')
    ep++;
  else if (sp != 0)
    sp--;
  
  memcpy (str, s, sp);
  memcpy (&str[sp], &s[ep], l - ep);
  str[l - rl - 1] = '\0';

  return str;
}

/*Add string add to string s, copy to new buffer, and retrun new buffer*/
static char*
bam_registry_add_str_str (char* s, char* add)
{
  char *str;  
  int   l;
  int   al;
  int   ac = 0; /*add comma*/

  if (add == NULL)
  {
    return msf_cmmn_strdup (MSF_MODID_BAM, s);
  }
  

  if (s == NULL)
  {
    l = 0;
  }
  else
  {
    if (strstr (s, add) != NULL)
    {
      /*String already in stirng*/
      return msf_cmmn_strdup (MSF_MODID_BAM, s);
    }

    l  = strlen (s);
  }

  al = strlen (add);

  if (l > 0)
    ac = 1;;
  
  str = BAM_ALLOC (l + al + ac + 1);

  memcpy (str, s, l);
  memcpy (&str[l], ",", ac);
  memcpy (&str[l + ac], add, al);
  str[l + al + ac] = '\0';

  return str;
}

static void
bam_registry_enable_object (int status, char* s, bam_set_profile_option_enum type)
{
  char * ask;
  char * load;
  char * n_ask;
  char * n_load;

  /*Fist get current value*/
  ask = bam_registry_value_string_table[BAM_REGISTRY_ENUM_OBJ_ASK];
  if(ask && *ask == 0)
    ask = NULL;
  load = bam_registry_value_string_table[BAM_REGISTRY_ENUM_OBJ_LOAD];
  if(load && *load == 0)
    load = NULL;

  if (status == bam_setting_val_never)
  {
    /*Never display images*/
    n_ask = bam_registry_remove_str_str (ask , s);
    n_load = bam_registry_remove_str_str (load, s);
  }
  else if (status == bam_setting_val_always)
  {
    /*Always display*/
    n_ask = bam_registry_remove_str_str (ask, s);
    n_load = bam_registry_add_str_str (load, s);
  }
  else
  {
    /*Ask before loading*/
    n_load = bam_registry_remove_str_str (load, s);
    n_ask = bam_registry_add_str_str (ask, s);
  }
  
  bam_registry_change_key_str_value(BAM_REGISTRY_ENUM_OBJ_LOAD, n_load, type);
  bam_registry_change_key_str_value(BAM_REGISTRY_ENUM_OBJ_ASK, n_ask, type);

  BAM_FREE (n_load);
  BAM_FREE (n_ask);

}

void bam_registry_enable_object_setting(int status, char* s)
{
bam_registry_enable_object (status,s, BAM_SET_PROFILE_TO_BRS);
}

void bam_registry_set_settings_by_reg(MSF_INT32 *int_value_table, char **str_value_table, bam_set_profile_option_enum type)
{
    if(int_value_table[wap_bam_setting_id_images] != BAM_REG_INT_INIT_VAL)
        bam_registry_enable_object(int_value_table[wap_bam_setting_id_images], "image/*", type);
    if(int_value_table[wap_bam_setting_id_sounds] != BAM_REG_INT_INIT_VAL)
        bam_registry_enable_object(int_value_table[wap_bam_setting_id_sounds], "audio/*", type);
    if(int_value_table[wap_bam_setting_id_movies] != BAM_REG_INT_INIT_VAL)
        bam_registry_enable_object(int_value_table[wap_bam_setting_id_movies], "movie/*", type);
    if(int_value_table[wap_bam_setting_id_cookies] != BAM_REG_INT_INIT_VAL)
        bam_registry_change_key_int_value(BAM_REGISTRY_ENUM_COOKIES, int_value_table[wap_bam_setting_id_cookies], type);
    if(int_value_table[wap_bam_setting_id_history] != BAM_REG_INT_INIT_VAL)
        bam_registry_change_key_int_value(BAM_REGISTRY_ENUM_HISTSIZE, int_value_table[wap_bam_setting_id_history], type);
    if(int_value_table[wap_bam_setting_id_no_mime] != BAM_REG_INT_INIT_VAL)
        bam_registry_change_key_int_value(BAM_REGISTRY_ENUM_LDNOMIME, int_value_table[wap_bam_setting_id_no_mime], type);
    if(int_value_table[wap_bam_setting_id_refresh] != BAM_REG_INT_INIT_VAL)
        bam_registry_change_key_int_value(BAM_REGISTRY_ENUM_REFRESH, int_value_table[wap_bam_setting_id_refresh], type);
    if(int_value_table[wap_bam_setting_id_cache] != BAM_REG_INT_INIT_VAL)
        bam_registry_change_key_int_value(BAM_REGISTRY_ENUM_CACHEON, int_value_table[wap_bam_setting_id_cache], type);
    if(int_value_table[wap_bam_setting_id_css] != BAM_REG_INT_INIT_VAL)
        bam_registry_change_key_int_value(BAM_REGISTRY_ENUM_USE_CSS, int_value_table[wap_bam_setting_id_css],type);
#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
    if(int_value_table[wap_bam_setting_id_add_history] != BAM_REG_INT_INIT_VAL)
        bam_sif_set_add_to_history_setting(int_value_table[wap_bam_setting_id_add_history]);
#endif
#ifdef __BAIDU_TRANSCODING_SUPPORT__
	if(int_value_table[wap_bam_setting_id_transcode_proxy] != BAM_REG_INT_INIT_VAL)
        bam_registry_change_key_int_value(BAM_REGISTRY_ENUM_TRANSCODE_PROXY,int_value_table[wap_bam_setting_id_transcode_proxy], type);
#endif

}

/*****************************************************************************
 * FUNCTION
 *  bam_registry_set_profile_by_reg
 * DESCRIPTION
 *
 * PARAMETERS
 *  int_value_table     [?]
 *  str_value_table     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
MSF_BOOL bam_registry_set_profile_by_reg(MSF_INT32 *int_value_table, char **str_value_table, bam_set_profile_option_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int  conn_type = -1;
    char *proxy_addr;
    unsigned char addr[4] = {0};
    int i, len = 0;
    MSF_BOOL flag[6];
    memset(flag, 0, sizeof(MSF_BOOL)*6);
    flag[0] = bam_registry_commit_item_in_registry(BAM_REGISTRY_ENUM_NET_ID, bam_registry_key_table[BAM_REGISTRY_ENUM_NET_ID].path, BAM_REG_INT, int_value_table[wap_bam_setting_id_con_account], NULL, type);
    switch(int_value_table[wap_bam_setting_id_con_type])
    {
    case bam_setting_val_conn_type_http:
        conn_type = BAM_REGISTRY_CONNECTION_TYPE_HTTP;
        break;
    case bam_setting_val_conn_type_connection_oreinted:
        conn_type = BAM_REGISTRY_CONNECTION_TYPE_WSP_CO;
        break;
    case bam_setting_val_conn_type_connection_oreinted_secure:
        conn_type = BAM_REGISTRY_CONNECTION_TYPE_WSP_CO;
        break;
    default:
        ASSERT(0);
        break;
    }
    flag[1] = bam_registry_commit_item_in_registry(BAM_REGISTRY_ENUM_CON_TYPE, bam_registry_key_table[BAM_REGISTRY_ENUM_CON_TYPE].path, BAM_REG_INT, conn_type, NULL, type);
    //proxy_addr = bam_registry_validate_proxy_addr(str_value_table[wap_bam_setting_id_con_addr]);
    proxy_addr = str_value_table[wap_bam_setting_id_con_addr];
    flag[2] = bam_registry_commit_item_in_registry(BAM_REGISTRY_ENUM_PRX_ADDR, bam_registry_key_table[BAM_REGISTRY_ENUM_PRX_ADDR].path, BAM_REG_STR, -1, proxy_addr, type);
    flag[3] = bam_registry_commit_item_in_registry(BAM_REGISTRY_ENUM_PRX_PWD, bam_registry_key_table[BAM_REGISTRY_ENUM_PRX_PWD].path, BAM_REG_STR, -1, str_value_table[wap_bam_setting_id_con_pwd], type);
    flag[4] = bam_registry_commit_item_in_registry(BAM_REGISTRY_ENUM_PRX_PORT, bam_registry_key_table[BAM_REGISTRY_ENUM_PRX_PORT].path, BAM_REG_INT, int_value_table[wap_bam_setting_id_con_port], NULL, type);
    flag[5] = bam_registry_commit_item_in_registry(BAM_REGISTRY_ENUM_PRX_UID, bam_registry_key_table[BAM_REGISTRY_ENUM_PRX_UID].path, BAM_REG_STR, -1, str_value_table[wap_bam_setting_id_con_user], type);
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_REGISTRY_SET_PROFILE_CONTENT, "BAM: set profile content : acc_id = %d, conn_type = %d, prx = %s, port = %d", int_value_table[wap_bam_setting_id_con_account], conn_type, proxy_addr, int_value_table[wap_bam_setting_id_con_port]));
    bam_registry_commit_item_in_registry(BAM_REGISTRY_ENUM_HOMEPAGE_URL, bam_registry_key_table[BAM_REGISTRY_ENUM_HOMEPAGE_URL].path, BAM_REG_STR, -1, str_value_table[wap_bam_setting_id_homepage], type);
    bam_registry_update_active_profile_settings(int_value_table[wap_bam_setting_id_con_account], conn_type, proxy_addr, int_value_table[wap_bam_setting_id_con_port], str_value_table[wap_bam_setting_id_con_user], str_value_table[wap_bam_setting_id_con_pwd]);
    if(proxy_addr != NULL)
        len = bam_cmn_get_address((const char*)(proxy_addr), (unsigned char*)addr);
    else
    {
        char temp_proxy[2];
        temp_proxy[0] = '\0';
        len = bam_cmn_get_address((const char*)(temp_proxy), (unsigned char*)addr);
    }
    for (i = 0; i < 6; i++)
    {
        if (flag[i] == TRUE)
        {
            return TRUE;
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  bam_registry_set_profile
 * DESCRIPTION
 *
 * PARAMETERS
 *  int_value_table     [?]
 *  str_value_table     [IN]
 *  profile             [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_registry_set_profile(MSF_UINT8 setting_id,bam_set_profile_option_enum type, MSF_INT32 *int_value_table, char **str_value_table, void *profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_BOOL flag = FALSE;
	int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Aplying the settings by using Registry mechanism */
    bam_is_set_profile_process = TRUE;
    bam_set_profile_request_id = ((bam_set_profile_req_struct*) profile)->request_id;
    if(setting_id == wap_bam_setting_type_settings)
    {
        bam_registry_set_settings_by_reg(int_value_table, str_value_table, type);
    }
    else if(setting_id == wap_bam_setting_type_profile)
    {
        flag = bam_registry_set_profile_by_reg(int_value_table, str_value_table, type);
    }
    else
    {
        bam_registry_set_settings_by_reg(int_value_table, str_value_table, type);
        flag = bam_registry_set_profile_by_reg(int_value_table, str_value_table, type);
    }
#ifndef MSF_MODID_CPS


    if((bam_sif_get_brs_status() != BAM_SIF_BRS_READY) || (setting_id == wap_bam_setting_type_settings) || (flag == FALSE) || (type != BAM_SET_PROFILE_TO_BRS))

    {
        bam_msg_set_profile_cnf(bam_main_get_instance_id(), ((bam_set_profile_req_struct*) profile)->request_id, BAM_ERROR_OK);
        bam_is_set_profile_process = FALSE;
    }
    //MSF_SIGNAL_DESTRUCT(MSF_MODID_BAM, BAM_SIG_SET_PROFILE_REQ, profile);
	BAM_FREE( ((bam_set_profile_req_struct*) profile)->int_value_table);
	 for (i = 0; i < BAM_SETTING_ID_TOTAL; i++)
    {
        if (((bam_set_profile_req_struct*)profile)->str_value_table[i] != NULL)
        {
            BAM_FREE(((bam_set_profile_req_struct*)profile)->str_value_table[i]);
        }
    }
	BAM_FREE( ((bam_set_profile_req_struct*) profile)->str_value_table);
    BAM_FREE( profile);

#else /* MSF_MODID_CPS */

    bam_pending_profile->int_value_table = int_value_table;
    bam_pending_profile->str_value_table = str_value_table;
    bam_pending_profile->profile = (bam_set_profile_req_struct*) profile;
    bam_registry_set_conn_profile_by_cps(int_value_table, str_value_table);
    /* We will destruct the profile after CPS applys the connection settings */

#endif /* MSF_MODID_CPS */
    bam_main_profile_init_done();
}

#ifdef MSF_MODID_CPS


/*****************************************************************************
 * FUNCTION
 *  bam_registry_process_pending_profile
 * DESCRIPTION
 *
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_registry_process_pending_profile(MSF_UINT8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bam_pending_profile->profile != NULL)
    {
        if (result == 0)
        {
            /* Update network account ID after CPS applys the setting */
            bam_registry_value_table[BAM_SETTING_ID_CON_ACCOUNT] =
                bam_pending_profile->int_value_table[BAM_SETTING_ID_CON_ACCOUNT];

            bam_msg_set_profile_cnf(bam_main_get_instance_id(), bam_pending_profile->profile->request_id, BAM_ERROR_OK);
        }
        else
        {
            bam_msg_set_profile_cnf(
                bam_main_get_instance_id(),
                bam_pending_profile->profile->request_id,
                BAM_ERROR_SET_PROFILE);
        }

        //MSF_SIGNAL_DESTRUCT(MSF_MODID_BAM, BAM_SIG_SET_PROFILE_REQ, bam_pending_profile->profile);
        BAM_FREE( profile->int_value_table);
	    BAM_FREE( profile->str_value_table);
        BAM_FREE( profile);
        bam_pending_profile->profile = NULL;
    }
}

#endif /* MSF_MODID_CPS */


    
/*****************************************************************
 *    Set zoom
 *****************************************************************/







#endif

unsigned int bam_cfg_brs_clear_history_on_newcontext(void)
{
#ifdef OBIGO_Q03C_BROWSER
  return (unsigned int) BAM_CFG_BRS_CLEAR_HISTORY_ON_NEWCONTEXT;
#else
  return 0;
#endif
}

const char*
bam_cfg_default_accept_header (void)
{
#ifdef OBIGO_Q03C_BROWSER
  return(bam_registry_value_string_table[BAM_REGISTRY_ENUM_ACCEPT_HEADER]);
#else
  return 0;
#endif
}

const char*
bam_cfg_default_charset_header (void)
{
#ifdef OBIGO_Q03C_BROWSER
  return (BAM_CFG_ACCEPT_CHARSET);
#else
  return 0;
#endif
}

const char*
bam_cfg_default_accept_language_header (void)
{
#ifdef OBIGO_Q03C_BROWSER
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static char final_accept_lang[BAM_MAX_ACCEPT_LANGUAGE_HEADER_LEN+1] = {0};
    char *curr_lang_setting = (char *)Get_Current_Lang_CountryCode();

    memset(final_accept_lang, 0, BAM_MAX_ACCEPT_LANGUAGE_HEADER_LEN);
	if (curr_lang_setting != NULL)
    {
        strcpy(final_accept_lang, curr_lang_setting);
    }
    return final_accept_lang;
#else
	return 0;
#endif

}

unsigned int bam_cfg_brs_redirect_handling(void)
{
#ifdef OBIGO_Q03C_BROWSER
  return (unsigned int) BAM_CFG_BRS_REDIRECT_HANDLING;
#else
  return 0;
#endif
}

const char*
bam_cfg_supported_image_mime (void)
{
#ifdef OBIGO_Q03C_BROWSER
  return BAM_CFG_SUPPORTED_IMAGE_MIME;
#else
  return 0;
#endif
}

const char*
bam_cfg_brs_default_css (void)
{
#ifdef OBIGO_Q03C_BROWSER
  return BAM_CFG_BRS_CSS_DEFAULT_STYLE_SHEET;
#else
  return 0;
#endif
}


const char* bam_cfg_brs_j2me_midp_version (void)				//vik - MAUI_03325833
{
#ifdef __J2ME__
#ifdef OBIGO_Q03C_BROWSER
	return BAM_CFG_J2ME_MIDP_VERSION;
#else
	return "";
#endif
#else 
	return "";
#endif
}



const char* bam_cfg_brs_j2me_cldc_version (void)				//vik - MAUI_03325833
{
#ifdef __J2ME__
#ifdef OBIGO_Q03C_BROWSER
	return BAM_CFG_J2ME_CLDC_VERSION;
#else
	return "";
#endif
#else 
	return "";
#endif
}

const char* bam_cfg_brs_https_pgdl_support(void)				//vik - MAUI_03325833
{
#ifdef OBIGO_Q03C_BROWSER
	return BAM_CFG_HTTPS_PGDL_SUPPORT;
#else
	return "";
#endif
}

const char* bam_cfg_brs_language_code(void)						//vik - MAUI_03325833
{
#ifdef OBIGO_Q03C_BROWSER
	return BAM_CFG_LANGUAGE_CODE;
#else
	return "";
#endif
}

const char* bam_cfg_brs_build_date_time(void)					//vik - MAUI_03325833		
{
#ifdef OBIGO_Q03C_BROWSER
	return BAM_CFG_BUILD_DATE_TIME;
#else
	return "";
#endif
}

const char* bam_cfg_brs_release_version(void)					//vik - MAUI_03325833	
{
#ifdef OBIGO_Q03C_BROWSER
	return BAM_CFG_RELEASE_VERSION;
#else
	return "";
#endif
}

const char* bam_cfg_brs_hw_release_ver(void)					//vik - MAUI_03325833	
{
#ifdef OBIGO_Q03C_BROWSER
	return BAM_CFG_HW_RELEASE_VER;
#else
	return "";
#endif
}


#ifdef MTK_TMP_PATCH /* CR34945 */
unsigned int bam_cfg_brs_ignore_emptyok(void)
{
#ifdef OBIGO_Q03C_BROWSER
  return (unsigned int) BAM_CFG_BRS_IGNORE_EMPTYOK;
#else
  return 0;
#endif
}
#endif /* MTK_TMP_PATCH */

#ifdef MSF_CFG_9W_MODE_KBRD_SIMULATION
MSF_BOOL bam_cfg_get_nine_way_navigation_mode_status(void)
{
#ifdef OBIGO_Q03C_BROWSER
    return(bam_main_get_nine_way_navigation_mode_status());
#endif
}
#endif

#ifdef OBIGO_Q03C_BROWSER

unsigned int bam_cfg_get_show_cookie_disabled_popup_status(void)
{
  return (unsigned int) BAM_CFG_SHOW_COOKIE_DISABLED_POPUP;
}

unsigned int bam_cfg_get_display_cookie_popup_for_all_req(void)
{
  return (unsigned int) BAM_CFG_SHOW_COOKIE_POPUP_FOR_ALL_REQ;
}

int bam_cfg_get_sec_conn_without_cert_dlg_setting(void)
{
    return BAM_CFG_SEC_CONN_WITHOUT_CERT_DLG;
}

int bam_registry_get_browser_timeout(void)
{
    return(bam_registry_value_table[BAM_REGISTRY_ENUM_TIMEOUT]);
}

MSF_UINT8 bam_registry_load_browser_active_profile(bam_registry_content_t  **prof_cont_ptr)
{
    *prof_cont_ptr = &bam_registry_active_profile;
    return WAP_PROF_SUCCESS;
}

static void bam_registry_update_active_profile_settings(int acct_id, int conn_type, char *proxy_addr, int proxy_port, char *username, char *password)
{
    bam_registry_active_profile.net_id = acct_id;
    bam_registry_active_profile.con_type = conn_type;
    memset(bam_registry_active_profile.prx_addr, 0, 4);
    if(proxy_addr != NULL)
    {
	    strcpy(bam_registry_active_profile.prx_ip, proxy_addr);
        bam_cmn_get_address((const char*)proxy_addr, (unsigned char*)bam_registry_active_profile.prx_addr);
    }
    else
    {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
        bam_registry_active_profile.prx_ip[0] = '\0';
#endif
    }
    bam_registry_active_profile.prx_port = proxy_port;
    if(username == NULL)
        bam_registry_active_profile.username[0] = '\0';
    else
        kal_mem_cpy(bam_registry_active_profile.username, username, BAM_REGISTRY_USERNAME_LEN);
    if(password == NULL)
        bam_registry_active_profile.password[0] = '\0';
    else
        kal_mem_cpy(bam_registry_active_profile.password, password, BAM_REGISTRY_PASSWORD_LEN);
}

int
bam_registry_change_key_str_value (int index, char* value, bam_set_profile_option_enum type)
{
    int path,cmp;
    if (index < 0 || index >= BAM_REGISTRY_ENUM_TOTAL)
      return -1;
    cmp=strcmp((unsigned char*)BAM_CMN_HNV(bam_registry_value_string_table[index]),(unsigned char*)BAM_CMN_HNV(value));
    BAM_FREE (bam_registry_value_string_table[index]);
    bam_registry_value_string_table[index] = msf_cmmn_strdup (MSF_MODID_BAM, value);

    path = bam_registry_key_table[index].path;
        
         switch(path)
        {
	        case bam_registry_path_bam:
		  	break;
		    case bam_registry_path_brs:
				if(bam_sif_get_brs_status() == BAM_SIF_BRS_READY && cmp!=0 && ((bam_set_profile_option_enum)type==BAM_SET_PROFILE_TO_BRS))
    {
                    BRSif_set_preference_values(index,0,(unsigned char*)BAM_CMN_HNV(value));
			        BRSif_appPrefChanged(MSF_MODID_BAM, 1);     
				}
			break;

		    case bam_registry_path_stk:
		    case bam_registry_path_stk_cookie:
		    case bam_registry_path_stk_cache:
			break;
			default:
			break;

    }

    if (index == BAM_REGISTRY_ENUM_NET_ID && bam_sif_get_brs_status() == BAM_SIF_BRS_READY)
    {
        if (bam_sif_is_holding_bearer())
        {
            /* Release the bearer with old network account id */
            bam_sif_set_holding_bearer(FALSE, bam_registry_get_int(BAM_SETTING_ID_CON_ACCOUNT));
            /* Hold the bearer with new network account id */
            bam_sif_set_holding_bearer(TRUE, (MSF_INT32)value);
        }				
    }
#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
    if (index == BAM_REGISTRY_ENUM_HISTSIZE)
    {
        bam_hist_resize();
    }
#endif
    return 1;
}

int
bam_registry_change_key_int_value (int index, int value, bam_set_profile_option_enum type1)
{
    int path;
	int type=-1;
    if (index < 0 || index >= BAM_REGISTRY_ENUM_TOTAL)
      return -1;
    if(bam_registry_value_table[index]!= value)
    {
	switch(index)
{
    	case BAM_REGISTRY_ENUM_COOKIES:
		    type= STK_CONFIG_TYPE_COOKIE_ENABLED;
            break;
		case BAM_REGISTRY_ENUM_CASHSIZE:
			type= STK_CONFIG_TYPE_CACHE_MAX_SIZE;
            break;
		case BAM_REGISTRY_ENUM_USE_CAHCE:
			type= STK_CONFIG_TYPE_CACHE_ENABLED;
            break;
		case BAM_REGISTRY_ENUM_CACHE_MODE:
			type= STK_CONFIG_TYPE_CACHE_MODE;
            break;
		default: 
			type=-1;
            break;
	}
    
    bam_registry_value_table[index] = value;

    path = bam_registry_key_table[index].path;
    
	 switch(path)
    {
		case bam_registry_path_bam:
            break;
		case bam_registry_path_brs:
			if(bam_sif_get_brs_status() == BAM_SIF_BRS_READY && (type1==BAM_SET_PROFILE_TO_BRS))
			{
			BRSif_set_preference_values(index,value,NULL);
			BRSif_appPrefChanged(MSF_MODID_BAM, 1);
			}
            break;
		case bam_registry_path_stk:
		case bam_registry_path_stk_cookie:
		case bam_registry_path_stk_cache:
			STKif_modifyConfig(MSF_MODID_BAM,type,value);
            break;
        default:
            break;

    }
    }
    return 1;
}


void bam_registry_handle_channel_config_notify(void)
{
    if(bam_is_set_profile_process == TRUE)
    {
        bam_msg_set_profile_cnf(bam_main_get_instance_id(), bam_set_profile_request_id, BAM_ERROR_OK);
        bam_is_set_profile_process = FALSE;
    }
}
#ifdef __BAIDU_TRANSCODING_SUPPORT__
void bam_registry_change_transcode_proxy_value(int i_value)
{
    bam_registry_value_table[BAM_REGISTRY_ENUM_TRANSCODE_PROXY]=i_value;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  bam_registry_get_net_acc_id
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/

int bam_registry_get_net_acc_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return bam_registry_value_table[BAM_REGISTRY_ENUM_NET_ID];
}

int bam_registry_check_cache_status(void)
{

	stk_check_parameter_enum istype;
    MSF_BOOL status;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0
    status=STKif_isEmpty(STK_PARAM_CACHE);
    return status;
}

int bam_registry_check_cookie_status(void)
{
    MSF_BOOL status;
    status=STKif_isEmpty(STK_PARAM_COOKIE);
    return status;
}
int bam_registry_check_auth_status(void)
{
    MSF_BOOL status;
    status=STKif_isEmpty(STK_PARAM_AUTHENTICATION);
    return status;
}
#endif /*OBIGO_Q03C_BROWSER*/
const char* bam_registry_get_ua_profile()
{   
#ifdef OBIGO_Q03C_BROWSER
	char *ua_prof;
    ua_prof = (char*) applib_inet_get_user_agent_profile();
	if (!ua_prof)
    {
        if(BAM_CFG_REGISTRY_DEFAULT_UA_PROF != NULL && strlen((char*)BAM_CFG_REGISTRY_DEFAULT_UA_PROF) > 0)
        {
		    return BAM_CFG_REGISTRY_DEFAULT_UA_PROF;
	    }
	    else
	    {
	        return NULL;
	    }
	}
	else
	{  return bam_registry_value_string_table[BAM_REGISTRY_ENUM_UA_PROF];}
#else
	return NULL;
#endif /*OBIGO_Q03C_BROWSER*/
}



void bam_regitry_get_pref_value(int key, char **s_value, int *i_value)
{
#ifdef OBIGO_Q03C_BROWSER
	*i_value=bam_registry_value_table[key];
   if(s_value)
	*s_value=(unsigned char*)BAM_CMN_HNV(bam_registry_value_string_table[key]);
#endif /*OBIGO_Q03C_BROWSER*/
}



#ifdef __BAIDU_TRANSCODING_SUPPORT__
const char* bam_registry_get_transcode_proxy_url(void)
{
#ifdef OBIGO_Q03C_BROWSER
    return BAM_CFG_TRANSCODE_PROXY_URL;
#else
    return NULL;
#endif
}


const char* bam_registry_get_transcode_proxy_header(void)
{
#ifdef OBIGO_Q03C_BROWSER
    return BAM_CFG_TRANSCODE_PROXY_HEADER;
#else
    return NULL;
#endif
}
#endif

