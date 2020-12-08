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
 *   ThemeConverterXML.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 * Contains parser side handlers for the DLT project
 *
 * Author:
 * -------
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "MMI_features.h"
#include "CustThemesRes.h"
#include "MMIDataType.h"
#include "gui_data_types.h"
#include "mmi_theme_converter.h"
#include "string.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "stdlib.h"
#include "mmi_theme_mgr.h"
#include "xml_def.h"

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__

#ifdef __COSMOS_MMI_PACKAGE__
#include "mmi_rp_vapp_calllog_def.h"
#else
#include "mmi_rp_app_calllog_def.h"
#endif	/* __COSMOS_MMI_PACKAGE__ */

#include "mmi_rp_app_phonebook_def.h"
#include "mmi_rp_srv_phb_def.h"
#include "mmi_rp_app_uiframework_def.h"
#include "mmi_rp_srv_mmi_theme_def.h"
#include "mmi_rp_app_sms_def.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "NetworkSetupResDef.h"
#include "PhoneSetupResList.h"
#include "mmi_rp_srv_venus_component_softkey_def.h"
#include "mmi_rp_srv_status_icons_def.h"
#ifdef __MMI_VUI_LAUNCHER_KEY__
#include "mmi_rp_vapp_key_mainmenu_def.h"
#endif
#if defined(__J2ME__)
#include "j2me_custom_option.h"
#endif /* defined(__J2ME__) */

#define __THEME_CONVERTER_XML_C__
#include "mmi_theme_converter_data.h"

/* Parser Object */

XML_PARSER_STRUCT g_tc_parser;  /* parser object */

#define NO_IMG_ATTR 300
#define NO_XML_TAGS 42
#define IMAGE_LIST_POS_XML_TAG_MAP 12

/* Temporary Images ID for some images */

/* End of the temporary id's */

/*******book Keeping***************/
extern MMI_theme theme_DLT;
extern U16 g_tm_checkThemeVersion;

/**********************************/

extern MMI_theme g_tc_theme_DLT;

static U8 g_tc_thm_process_call_count;  /* theme Process Queue Counter */


/* function pointer type for string query */
typedef PS8 (*mmi_tc_string_query_funcptr_type)(S32);


/*****************************************************************************
 * FUNCTION
 *  mmi_tc_tag_string_query
 * DESCRIPTION
 *  query the tag string
 * PARAMETERS
 *  idx     [IN]    string map index
 * RETURNS
 *  string pointer
 *****************************************************************************/
static CHAR* mmi_tc_tag_string_query(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_tc_xml_tags_map[idx].xml_tag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tc_attr_string_query
 * DESCRIPTION
 *  query the attribute string of image tag
 * PARAMETERS
 *  idx     [IN]    string map index
 * RETURNS
 *  string pointer
 *****************************************************************************/
static CHAR* mmi_tc_attr_string_query(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_tc_image_tags_map[idx].image_tag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tc_string_binary_search
 * DESCRIPTION
 *  string binary search.
 *  [Note] all strings in tag_map should be sorted in ascending alphabetic order
 * PARAMETERS
 *  str_query_func  [IN] function pointer to string query function     
 *  num         [IN] total number of tag_map items
 *  str         [IN] tag string to search
 * RETURNS
 *  -1: error, otherwise: index in tag_map where str found
 *****************************************************************************/
static S32 mmi_tc_string_binary_search(mmi_tc_string_query_funcptr_type str_query_func, S32 num, const CHAR *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 iEnd = num-1;
    S32 iStart = 0;
    S32 result;
    S32 idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    while (iStart <= iEnd)
    {
        idx = (iStart + iEnd)/2;

        //Trace2((MMI_FW_TRC_G1_FRM, "search index = (%d, %d, %d)\n", iStart, iEnd, idx));

        result = strcmp(str, str_query_func(idx));
        if ( result == 0)
        {
            return idx;
        }
        else if (result < 0)
        {
            iEnd = idx-1;
        }
        else
        {
            iStart = idx+1;
        }
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tc_my_xml_elem_start_hdlr
 * DESCRIPTION
 *  (void *data, const char *el, const char **attr)
 *  function for handling of the start element tag
 * PARAMETERS
 *  data_p      [?]         
 *  el_p        [IN]        
 *  attr_p      [IN] 
 *  err_code    [IN]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tc_my_xml_elem_start_hdlr(void *data_p, const char *el_p, const char **attr_p, S32 err_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 tag_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_tm_checkThemeVersion)
    {
        if (!(strncmp((PS8) "devicetheme", el_p, strlen(el_p))) || !(strncmp((PS8) "deviceinfo", el_p, strlen(el_p))) ||
            !(strncmp((PS8) "media", el_p, strlen(el_p))))
        {   /* continue */
        }
        else
        {
            xml_free_parse(&g_tc_parser);
            return;
        }
    }

    /* find tag handler by binary search */

    tag_index = mmi_tc_string_binary_search(mmi_tc_tag_string_query, 
                                sizeof(g_tc_xml_tags_map)/sizeof(tc_all_tags_index_struct), el_p);

    /* tag should always be found */
    MMI_ASSERT(tag_index >= 0);

    /* execute tag handler */
    g_tc_xml_tags_map[tag_index].tag_handler((U8 **) attr_p, (void*)(g_tc_xml_tags_map+tag_index));
    g_tc_thm_process_call_count++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tc_my_xml_elem_end_hdlr
 * DESCRIPTION
 *  (void *data, const char *el)
 *  function for handling of the end element tag
 * PARAMETERS
 *  data_p      [?]         
 *  el_p        [IN]        
 *  err_code    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tc_my_xml_elem_end_hdlr(void *data_p, const char *el_p, S32 err_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 end_element[] = "media";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!strcmp(el_p, (PS8) end_element))
    {
        xml_free_parse(&g_tc_parser);
    }
    else
    {
        if (g_tc_thm_process_call_count == 15)
    #ifdef __DLT_ENABLE_PROCESS_QUEUE__
            theme_process_queue();
    #else /* __DLT_ENABLE_PROCESS_QUEUE__ */ 
        {
        }
    #endif /* __DLT_ENABLE_PROCESS_QUEUE__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tc_processqueue
 * DESCRIPTION
 *  (void)
 *  function for polling of the queues
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int mmi_tc_processqueue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tc_image_list_tag_handler
 * DESCRIPTION
 *  (U8 **attr)
 *  handles the image_list tag obained by parsing the XML file
 * PARAMETERS
 *  attr_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tc_image_list_tag_handler(U8 **attr_p, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tm_image_load_type_enum type;
    S32 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
    if (!strcmp((PS8) attr_p[0], "status_sig"))
    {
        strcpy((PS8) attr_p[0], "st_sig1");
    }
#endif /* __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ */ 

    idx = mmi_tc_string_binary_search(mmi_tc_attr_string_query, 
                                sizeof(g_tc_image_tags_map)/sizeof(tc_image_tags_index_struct), (PS8)attr_p[0]);
    if (idx)
    {
        type = (tm_image_load_type_enum) atoi((PS8) attr_p[3]);
        mmi_tm_set_imageid(g_tc_image_tags_map[idx].imageId, (U32) atoi((PS8) attr_p[1]), type);
    }
}

#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ /* mmi downloadble themes support */


