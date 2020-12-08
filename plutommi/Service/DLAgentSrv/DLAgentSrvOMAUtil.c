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
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/

#include "MMI_include.h"

#if defined (__MMI_OMA_DD_DOWNLOAD__)

//#include "CommonScreens.h"
//#include "ProtocolEvents.h"
#include "app_str.h"
#include "app_mine.h"
//#include "drm_def.h"
//#include "DLAgentDef.h"
#include "DLAgentSrvGprot.h"
#include "DLAgentSrvIProt.h"
#ifdef __MMI_DOWNLOAD_AGENT__
#include "mmi_rp_srv_downloadagent_def.h"
#endif
//#include "DLAgentWPS.h"
#include "DLAgentSrvOMA.h"
#include "XML_def.h"
#include "das_struct.h"     /* WAP_DL_MAX_URL_LEN */
#include "Conversions.h"
//#include "FileMgr.h"
//#include "FileManagerGProt.h"
#include "FileMgrSrvGprot.h"

#if defined (__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
#include "MMIThemesGProt.h"
#endif


    #include "MMIDataType.h"
    #include "mmi_frm_mem_gprot.h"
    #include "kal_general_types.h"
    #include "wgui.h"
    #include "GlobalResDef.h"
    #include "mmi_rp_srv_downloadagent_def.h"
    #include "wchar.h"
    #include "kal_public_api.h"
    #include "string.h"
    #include "Unicodexdcl.h"
    #include "stdlib.h"
    #include "DebugInitDef_Int.h"

/****************************************************************************
* Define
*****************************************************************************/

#define DD_SHORT_STRING_LEN     40
#define DD_LONG_STRING_LEN      192
#define DD_VERYLONG_STRING_LEN  255
#define DD_URI_LEN              512
#define DD_INTEGER_LEN          32
#define DD_BOOLEAN_LEN          10      /* "true" or "false", 1 or 0 */
#define DD_DATETIME_LEN         30

/****************************************************************************
* Define - Macro
*****************************************************************************/

#define offsetof(type, mem) ((size_t) ((char*)&((type*)0)->mem - (char*)((type*)0)))

#define DD_IS_TAG(tagname, el)  (app_stricmp((kal_char *)tagname, (kal_char *)el) == 0)

#define DD_FIND_ATTR(attrname, attrlist, idx) \
    idx = 0; \
    while(attrlist[idx]) \
    { \
        if (DD_IS_TAG(attrname, attrlist[i])) \
            break; \
        idx+=2; \
    } \

#define DD_CONVERT_STRING(value, len, target) \
    (target) = (S8 *)srv_da_adp_mem_allocate( (len + 1) * ENCODING_LENGTH ); \
    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (S8*)value, (S8*)(target), (len + 1)*ENCODING_LENGTH)
    
/****************************************************************************
* Typedef - Enum
*****************************************************************************/

enum
{
    DD_PARSING_STATE_NONE = -1,
    DD_PARSING_STATE_MEDIA,

#ifdef __MMI_OMA_DD2_DOWNLOAD__
    DD2_PARSING_STATE_NONE = -1,
    DD2_PARSING_STATE_MEDIA,
    DD2_PARSING_STATE_VENDOR,
    DD2_PARSING_STATE_PRODUCT,
    DD2_PARSING_STATE_META,
    DD2_PARSING_STATE_MO,
    DD2_PARSING_STATE_RESERVE,
    DD2_PARSING_STATE_OBJ_URI,
#endif

    DD_PARSING_LEVEL_MAX = 12
};

enum
{
    DD_XSD_TYPE_SHORT_STRING,
    DD_XSD_TYPE_LONG_STRING,
    DD_XSD_TYPE_VERYLONG_STRING,
    DD_XSD_TYPE_URI,
    DD_XSD_TYPE_URI_UCS2,
    DD_XSD_TYPE_INTEGER,
    DD_XSD_TYPE_BOOLEAN,
    DD_XSD_TYPE_DATETIME,

    DD_XSD_TYPE_NUM
};

/****************************************************************************
* Typedef - Struct
*****************************************************************************/

typedef MMI_BOOL (*srv_da_oma_dd_elem_handler)(const S8* value, S32 len, void* obj, U16 offset);

typedef struct
{
    S32 errorNo;
    UI_string_ID_type stringId;         /* for displaypopup */
    S8 *report_msg;                     /* for send report */
} srv_da_oma_error_entry_struct;

typedef struct
{
    S8  *item;
    U16 type;
    U16 offset;
} dd_data_table_struct;

typedef struct
{
    S32                         max_len;
    srv_da_oma_dd_elem_handler  func;
} dd_type_table_struct;

typedef struct
{
    MMI_BOOL                    dd_parse_busy;
    MMI_BOOL                    dd_parse_error;

    S8                          *dd_url_base;
    srv_da_job_struct           *curr_job;

    srv_da_oma_dd_struct        *dd_info;   // current parsing dd
    
#ifdef __MMI_OMA_DD2_DOWNLOAD__
    S32                         dd2_product_idx;
    S32                         dd2_mo_idx;
    srv_da_oma_dd2_struct       *dd2_info;   // current parsing dd
    U8                          dd2_state_stack[DD_PARSING_LEVEL_MAX];
    S32                         dd2_state_level;
    S32                         dd2_skip;
#endif    
} srv_da_omautil_context_struct;

/****************************************************************************
* Static Variable
*****************************************************************************/

static srv_da_omautil_context_struct da_omautil_context = {0};

/* *FORMATTER-DISABLE* */
const static srv_da_oma_error_entry_struct oma_error_tbl[]=
{
    {SRV_DA_OMA_SUCCESS               ,STR_GLOBAL_DONE,                              "900 Success"                },
    {SRV_DA_OMA_INSUFFICIENT_MEMORY   ,STR_GLOBAL_INSUFFICIENT_MEMORY,               "901 Insufficient memory"    },
    {SRV_DA_OMA_USER_CANCELLED        ,STR_ID_DA_CANCELLED,                          "902 User Cancelled"         },
    {SRV_DA_OMA_LOSS_OF_SERVICE       ,STR_ID_DA_OMA_LOSS_OF_SERVICE_MSG,            "903 Loss of Service"        },
    {SRV_DA_OMA_ATTRIBUTE_MISMATCH    ,STR_ID_DA_OMA_ATTRIBUTE_MISMATCH_MSG,         "905 Attribute mismatch"     },
    {SRV_DA_OMA_INVALID_DESCRIPTOR    ,STR_ID_DA_OMA_INVALID_DESCRIPTOR_MSG,         "906 Invalid descriptor"     },
    {SRV_DA_OMA_INVALID_DDVSERSION    ,STR_ID_DA_OMA_INVALID_DDVSERSION_MSG,         "951 Invalid DDVersion"      },
    {SRV_DA_OMA_DEVICE_ABORTED        ,STR_ID_DA_OMA_DEVICE_ABORTED_MSG,             "952 Device Aborted"         },
    {SRV_DA_OMA_NON_ACCEPTABLE_CONTENT,STR_ID_DA_OMA_NON_ACCEPTABLE_CONTENT_MSG,     "953 Non-Acceptable Content" },
    {SRV_DA_OMA_LOADER_ERROR          ,STR_ID_DA_OMA_LOADER_ERROR_MSG,               "954 Loader Error"           },
    {SRV_DA_OMA_UNAUTHORIZED          ,STR_ID_DA_AHTUENTICATION_FAILED,              "952 Device Aborted"         },
    {SRV_DA_OMA_FILE_ACCESS_ERROR     ,STR_GLOBAL_ERROR,                             "952 Device Aborted"         },
    {0, 0, NULL}
};

static MMI_BOOL _dd_extract_string(const S8* value, S32 len, void* obj, U16 offset);
static MMI_BOOL _dd_extract_url(const S8* value, S32 len, void* obj, U16 offset);
static MMI_BOOL _dd_extract_url_ucs2(const S8* value, S32 len, void* obj, U16 offset);
static MMI_BOOL _dd_extract_integer(const S8* value, S32 len, void* obj, U16 offset);
static MMI_BOOL _dd_extract_boolean(const S8* value, S32 len, void* obj, U16 offset);
static MMI_BOOL _dd_extract_datetime(const S8* value, S32 len, void* obj, U16 offset);

const static dd_type_table_struct dd_xsd_type_info_table[DD_XSD_TYPE_NUM] =
{
     {DD_SHORT_STRING_LEN,      _dd_extract_string}
    ,{DD_LONG_STRING_LEN,       _dd_extract_string}
    ,{DD_VERYLONG_STRING_LEN,   _dd_extract_string}
    ,{DD_URI_LEN,               _dd_extract_url}
    ,{DD_URI_LEN,               _dd_extract_url_ucs2}
    ,{DD_INTEGER_LEN,           _dd_extract_integer}
    ,{DD_BOOLEAN_LEN,           _dd_extract_boolean}
    ,{DD_DATETIME_LEN,          _dd_extract_datetime}
};

/* Also add an element to  */
const static dd_data_table_struct dd_elem_media_table[]=
{
    {"type"             ,DD_XSD_TYPE_SHORT_STRING   ,offsetof(srv_da_oma_dd_struct, type)},
    {"objectURI"        ,DD_XSD_TYPE_URI            ,offsetof(srv_da_oma_dd_struct, objectURI)},
    {"installNotifyURI" ,DD_XSD_TYPE_URI            ,offsetof(srv_da_oma_dd_struct, installNotifyURI)},
    {"nextURL"          ,DD_XSD_TYPE_URI_UCS2       ,offsetof(srv_da_oma_dd_struct, nextURL)},
    {"DDVersion"        ,DD_XSD_TYPE_SHORT_STRING   ,offsetof(srv_da_oma_dd_struct, DDVersion)},
    {"name"             ,DD_XSD_TYPE_SHORT_STRING   ,offsetof(srv_da_oma_dd_struct, name)},
    {"description"      ,DD_XSD_TYPE_LONG_STRING    ,offsetof(srv_da_oma_dd_struct, description)},
    {"vendor"           ,DD_XSD_TYPE_SHORT_STRING   ,offsetof(srv_da_oma_dd_struct, vendor)},
    {"infoURL"          ,DD_XSD_TYPE_URI_UCS2       ,offsetof(srv_da_oma_dd_struct, infoURL)},
    {"iconURI"          ,DD_XSD_TYPE_URI            ,offsetof(srv_da_oma_dd_struct, iconURI)},
    {"installParam"     ,DD_XSD_TYPE_VERYLONG_STRING,offsetof(srv_da_oma_dd_struct, installParam)},
    {"size"             ,DD_XSD_TYPE_INTEGER        ,offsetof(srv_da_oma_dd_struct, size)},
    {"progressiveDownloadFlag", DD_XSD_TYPE_BOOLEAN ,offsetof(srv_da_oma_dd_struct, progressiveDownloadFlag)},
    {NULL, 0, 0}
};


#ifdef __MMI_OMA_DD2_DOWNLOAD__
const static dd_data_table_struct dd2_complex_elem_table[]=
{
    {"media"                 ,DD2_PARSING_STATE_MEDIA    ,0},
    {"vendor"                ,DD2_PARSING_STATE_VENDOR   ,0},
    {"product"               ,DD2_PARSING_STATE_PRODUCT  ,0},
    {"meta"                  ,DD2_PARSING_STATE_META     ,0},
    {"mediaObject"           ,DD2_PARSING_STATE_MO       ,0},
    {"objectURI"             ,DD2_PARSING_STATE_OBJ_URI  ,0},
    {NULL, 0, 0}
};

const static dd_data_table_struct dd2_elem_vendor_table[]=
{
    {"name"                  ,DD_XSD_TYPE_LONG_STRING  ,offsetof(srv_da_oma_dd2_struct, vendorName)},
    {"home"                  ,DD_XSD_TYPE_URI          ,offsetof(srv_da_oma_dd2_struct, vendorHome)},
    {"logo"                  ,DD_XSD_TYPE_URI          ,offsetof(srv_da_oma_dd2_struct, vendorLogo)},
    {"support"               ,DD_XSD_TYPE_URI          ,offsetof(srv_da_oma_dd2_struct, vendorSupport)},
    {NULL, 0, 0}
};

const static dd_data_table_struct dd2_elem_meta_table[]=
{
    {"name"                  ,DD_XSD_TYPE_LONG_STRING      ,offsetof(srv_da_oma_dd2_meta_struct, name)},
    {"description"           ,DD_XSD_TYPE_LONG_STRING      ,offsetof(srv_da_oma_dd2_meta_struct, description)},
//    {"id"                    ,DD_XSD_TYPE_SHORT_STRING     ,offsetof(srv_da_oma_dd2_meta_struct, name)},
//    {"display"               ,DD_XSD_TYPE_SHORT_STRING     ,offsetof(srv_da_oma_dd2_meta_struct, name)},
    {"infoURL"               ,DD_XSD_TYPE_URI              ,offsetof(srv_da_oma_dd2_meta_struct, infoURL)},
    {"media"                 ,DD_XSD_TYPE_URI              ,offsetof(srv_da_oma_dd2_meta_struct, mediaURI)},
    {"installParam"          ,DD_XSD_TYPE_VERYLONG_STRING  ,offsetof(srv_da_oma_dd2_meta_struct, installParam)},
    {"installNotifyURI"      ,DD_XSD_TYPE_URI              ,offsetof(srv_da_oma_dd2_meta_struct, installNotifyURI)},
    {"downloadNotifyURI"     ,DD_XSD_TYPE_URI              ,offsetof(srv_da_oma_dd2_meta_struct, downloadNotifyURI)},
    {"deleteNotifyURI"       ,DD_XSD_TYPE_URI              ,offsetof(srv_da_oma_dd2_meta_struct, deleteNotifyURI)},
    {"suppressUserConfirmation",DD_XSD_TYPE_BOOLEAN        ,offsetof(srv_da_oma_dd2_meta_struct, suppressUserConfirmation)},
    {NULL, 0, 0}
};

const static dd_data_table_struct dd2_elem_mo_table[]=
{
    {"size"                  ,DD_XSD_TYPE_INTEGER          ,offsetof(srv_da_oma_dd2_mo_struct, size)},
    {"installSize"           ,DD_XSD_TYPE_INTEGER          ,offsetof(srv_da_oma_dd2_mo_struct, installSize)},
    {"type"                  ,DD_XSD_TYPE_SHORT_STRING     ,offsetof(srv_da_oma_dd2_mo_struct, type)},
    {"objectID"              ,DD_XSD_TYPE_URI              ,offsetof(srv_da_oma_dd2_mo_struct, objectId)},
    {"objectVersion"         ,DD_XSD_TYPE_SHORT_STRING     ,offsetof(srv_da_oma_dd2_mo_struct, objectVersion)},
    {"progressiveDownloadFlag",DD_XSD_TYPE_BOOLEAN         ,offsetof(srv_da_oma_dd2_mo_struct, progressiveDownloadflag)},
//    {"objectValidityTime"    ,DD_XSD_TYPE_DATETIME         ,offsetof(srv_da_oma_dd2_mo_struct, xx)},
    {"server"                ,DD_XSD_TYPE_URI              ,offsetof(srv_da_oma_dd2_mo_struct, objectURI)},
    {NULL, 0, 0}
};

const static dd_data_table_struct dd2_elem_media_table[]=
{
    {"nextURL"               ,DD_XSD_TYPE_URI_UCS2         ,offsetof(srv_da_oma_dd2_struct, nextURL)},
    {NULL, 0, 0}
};
#endif


const static srv_da_oma_install_check_tbl_struct srv_da_oma_install_check_tbl[] =
{
#if defined (__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
    {MIME_TYPE_APPLICATION,  MIME_SUBTYPE_THEME, (srv_da_oma_install_check_hdlr)mmi_ta_da_oma_install_check_hdlr},
#endif
    {MIME_TYPE_APPLICATION,  MIME_SUBTYPE_UNRECOGNIZED, NULL}
};
const static S32 srv_da_oma_install_check_hdlr_num = sizeof(srv_da_oma_install_check_tbl) / sizeof(srv_da_oma_install_check_tbl_struct);
/* *FORMATTER-ENABLE* */


/****************************************************************************
* Function Forward Declaration
*****************************************************************************/

#define END_OF_FUNCTION_DECLARATION

static MMI_BOOL _dd_extract_string(const S8* value, S32 len, void* obj, U16 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 **string_pp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    string_pp = (S8**)((S8*)obj + offset);

    if(*string_pp)
        return MMI_FALSE;

    DD_CONVERT_STRING(value, len, *string_pp);
    return MMI_TRUE;
}

static MMI_BOOL _dd_extract_url(const S8* value, S32 len, void* obj, U16 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 **string_pp;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    string_pp = (S8**)((S8*)obj + offset);

    if(*string_pp)
        return MMI_FALSE;

    if (app_strnicmp( (kal_char*)value, "http://", 7) ==0 ||
        app_strnicmp( (kal_char*)value, "http:\\\\", 7) ==0 )
    {
        /* Absolute URL */
        *string_pp = get_ctrl_buffer(len + 1);
        strncpy(*string_pp, value, len);
        (*string_pp)[len] = 0;
    }
    else if (app_strnicmp( (kal_char*)da_omautil_context.dd_url_base, "http://", 7) ==0 ||
               app_strnicmp( (kal_char*)da_omautil_context.dd_url_base, "http:\\\\", 7) ==0 )
    {
        /* Relative URL */
        if(value[0] == '/' || value[0] == '\\')
        {
            // find server address
            for(i=7; da_omautil_context.dd_url_base[i]; i++)
            {
                if(da_omautil_context.dd_url_base[i] == '/' ||
                    da_omautil_context.dd_url_base[i] == '\\')
                    break;
            }
        }
        else
        {
            /* related path, add dd url base */
            i = strlen(da_omautil_context.dd_url_base);
        }
        *string_pp = get_ctrl_buffer(len + i + 1);
        strncpy(*string_pp, da_omautil_context.dd_url_base, i);
        strncpy(*string_pp + i, value, len);
        (*string_pp)[i+len] = 0;
    }
    else
    {
        da_omautil_context.dd_parse_error = MMI_TRUE;
        return MMI_FALSE;
    }
    
    return MMI_TRUE;
}

static MMI_BOOL _dd_extract_url_ucs2(const S8* value, S32 len, void* obj, U16 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    S8 **string_pp;
    S8 *newstr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ret = _dd_extract_url(value, len, obj, offset);
    if(ret)
    {
        string_pp = (S8**)((S8*)obj + offset);
        newstr = get_ctrl_buffer((strlen(*string_pp)+1)*ENCODING_LENGTH);
        mmi_asc_to_ucs2((S8*)newstr, (S8*)(*string_pp));
        free_ctrl_buffer(*string_pp);
        *string_pp = newstr;
    }
    return ret;
}


static MMI_BOOL _dd_extract_integer(const S8* value, S32 len, void* obj, U16 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 *result_p;
    S32 v;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result_p = (S32*)((S8*)obj + offset);

    if(*result_p)
        return MMI_FALSE;

    v = atoi(value);
    if(v <= 0)
        da_omautil_context.dd_parse_error = MMI_TRUE;

    *result_p = v;
    return MMI_TRUE;
}

static MMI_BOOL _dd_extract_boolean(const S8* value, S32 len, void* obj, U16 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 *result_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result_p = (S32*)((S8*)obj + offset);

    if (app_stricmp((kal_char *)"true", (kal_char *)value) == 0)
        *result_p = MMI_TRUE;
    else if (app_stricmp((kal_char *)"false", (kal_char *)value) == 0)
        *result_p = MMI_FALSE;
    else
        da_omautil_context.dd_parse_error = MMI_TRUE;
    return MMI_TRUE;
}

static MMI_BOOL _dd_extract_datetime(const S8* value, S32 len, void* obj, U16 offset)
{
    MMI_ASSERT(0);
    return MMI_FALSE;
}

/*****************************************************************************
* FUNCTION
*   dd_read_end_element
* DESCRIPTION
*   a callback function for XML parser, parse dd file
* PARAMETERS
*   void
* RETURNS
*   void
*****************************************************************************/
static void _dd_read_end_element(void *no_used, const char *el, S32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

/*****************************************************************************
* FUNCTION
*   dd_read_start_element
* DESCRIPTION
*   a callback function for XML parser, parse dd file
* PARAMETERS
*   void
* RETURNS
*   void
*****************************************************************************/
static void _dd_read_start_element(void *no_used, const char *el, const char **attr, S32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

/*****************************************************************************
* FUNCTION
*   dd_read_data_element
* DESCRIPTION
*   a callback function for XML parser, parse dd file
* PARAMETERS
*
* RETURNS
*   void
*****************************************************************************/
static void _dd_read_data_element(void *no_used, const S8 * el, const S8 * value, S32 len, S32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32                             i;
    srv_da_oma_dd_struct            *dd_info;
    MMI_BOOL                            pre_handled;
    MMI_BOOL                            add_to_list;
    
    void                            *obj;
    const dd_data_table_struct      *table;
    const dd_type_table_struct      *type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(da_omautil_context.dd_parse_error)
        return;

    if (el == NULL || value[len] != 0)
    {
        da_omautil_context.dd_parse_error = MMI_TRUE;
        return;
    }

    dd_info = da_omautil_context.dd_info;

    obj = dd_info;
    table = dd_elem_media_table;
    pre_handled = MMI_FALSE;
    add_to_list = MMI_FALSE;

    if(DD_IS_TAG("type", el))
    {
        for(i=0;i<4;i++)
        {
            if(!dd_info->type[i])
            {
                /* MAUI_01722088: value may be raw data and not terminated by '\0' */
                dd_info->type[i] = (S8 *)srv_da_adp_mem_allocate(len + 1);
                memcpy(dd_info->type[i], value, len);
                dd_info->type[i][len] = '\0';
                break;
            }
        }
        add_to_list = (i==0) ? MMI_TRUE : MMI_FALSE;
        pre_handled = MMI_TRUE;
    }

    i = 0;
    while(table->item)
    {
        if(DD_IS_TAG(table->item, el))
            break;
        table++;
        i++;
    }

    if(!table->item)
        return;

    DA_TRACE_FUNC1(_dd_read_data_element, i);

    /* found */
    type = &dd_xsd_type_info_table[table->type];
    
    if(!len || len > type->max_len)
    {
        //da_omautil_context.dd_parse_error = MMI_TRUE;
        //return;
		len = type->max_len;
    }

    MMI_ASSERT(type->func);
    MMI_ASSERT(table->offset % 4 == 0);
    if(!pre_handled)
        add_to_list = type->func(value, len, obj, table->offset);

    if(add_to_list)
    {
        dd_info->attr_order[dd_info->attr_num] = i;
        dd_info->attr_num++;
    }

}

/*****************************************************************************
* FUNCTION
*   srv_da_oma_parse_dd
* DESCRIPTION
*   the main function to parse a dd file
* PARAMETERS
*   filename    IN      The path of dd file
*   item        OUT     Output the result to item
* RETURNS
*   MMI_TRUE :  OK
*   MMI_FALSE:  FAIL
*****************************************************************************/
MMI_BOOL srv_da_oma_parse_dd(U16 * filename, srv_da_job_struct *job, srv_da_oma_dd_struct *dd_info, S8* url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    XML_PARSER_STRUCT           parser;
    S32                         ret, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename == NULL)
        return MMI_FALSE;

    if (da_omautil_context.dd_parse_busy)
        return MMI_FALSE;

    da_omautil_context.dd_parse_busy = MMI_TRUE;
    da_omautil_context.dd_info = dd_info;
    da_omautil_context.curr_job = job;
    da_omautil_context.dd_parse_error = MMI_FALSE;

    MMI_ASSERT(url != NULL);
    ANSI_STR_MALLOC_COPY(da_omautil_context.dd_url_base, url, WAP_DL_MAX_URL_LEN);
    
    MMI_ASSERT(da_omautil_context.dd_url_base != NULL);
    for(i = strlen(da_omautil_context.dd_url_base) - 1; i>=0 ;i--)
    {
        if(da_omautil_context.dd_url_base[i] == '/' ||  da_omautil_context.dd_url_base[i] == '\\' )
        {
            da_omautil_context.dd_url_base[i+1] = 0;
            break;
        }
    }

    xml_new_parser(&parser);
    xml_register_element_handler(&parser, _dd_read_start_element, _dd_read_end_element);
    xml_register_data_handler(&parser, _dd_read_data_element);
    ret = xml_parse(&parser, filename);
    xml_stop_parse(&parser);
    xml_close_parser(&parser);

    da_omautil_context.curr_job = NULL;
    da_omautil_context.dd_parse_busy = MMI_FALSE;
    DA_FREE_BUFFER(da_omautil_context.dd_url_base);

    if (ret == XML_RESULT_OK && !da_omautil_context.dd_parse_error)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}
#ifdef __MMI_OMA_DD2_DOWNLOAD__
/*****************************************************************************
* FUNCTION
*   dd_read_end_element
* DESCRIPTION
*   a callback function for XML parser, parse dd file
* PARAMETERS
*   void
* RETURNS
*   void
*****************************************************************************/
static void _dd2_read_end_element(void *no_used, const char *el, S32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const dd_data_table_struct     *table;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(da_omautil_context.dd_parse_error)
        return;
    
    table = dd2_complex_elem_table;
    while(table->item)
    {
        if (DD_IS_TAG(table->item, el))
            break;
        table++;
    }
    if(!table->item)
        return;

    MMI_ASSERT(da_omautil_context.dd2_state_stack[da_omautil_context.dd2_state_level] == table->type);
    da_omautil_context.dd2_state_level--;

    switch(table->type)
    {
    case DD2_PARSING_STATE_PRODUCT:
        if(da_omautil_context.dd2_skip > 0)
            da_omautil_context.dd2_skip--;
        da_omautil_context.dd2_product_idx = -1;
        break;

    case DD2_PARSING_STATE_MO:
        if(da_omautil_context.dd2_skip > 0)
            da_omautil_context.dd2_skip--;
        da_omautil_context.dd2_mo_idx = -1;
        break;
    }

}

/*****************************************************************************
* FUNCTION
*   dd_read_start_element
* DESCRIPTION
*   a callback function for XML parser, parse dd file
* PARAMETERS
*   void
* RETURNS
*   void
*****************************************************************************/
static void _dd2_read_start_element(void *no_used, const char *el, const char **attr, S32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32                             i;
    srv_da_oma_dd2_struct           *dd2_info;
    srv_da_oma_dd2_product_struct   *product;
    srv_da_oma_dd2_mo_struct        *mo;
    srv_da_oma_dd2_meta_struct      *meta;

    const dd_data_table_struct     *table;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(da_omautil_context.dd_parse_error)
        return;

    dd2_info = da_omautil_context.dd2_info;
    table = dd2_complex_elem_table;

    while(table->item)
    {
        if (DD_IS_TAG(table->item, el))
            break;
        table++;
    }

    if(!table->item)
        return;

    da_omautil_context.dd2_state_level++;
    da_omautil_context.dd2_state_stack[da_omautil_context.dd2_state_level] = table->type;

    switch(da_omautil_context.dd2_state_stack[da_omautil_context.dd2_state_level])
    {
    case DD2_PARSING_STATE_MEDIA:
        /* <media>, search for DDVersion */
        DD_FIND_ATTR("DDVersion", attr, i);
        if(attr[i])
        {
            i++;
            if( !attr[i] ||
                strlen(attr[i]) != 3 ||
    		    attr[i][1] != '.' ||
    		    attr[i][0] < '0' || attr[i][0] > '9' ||
    		    attr[i][2] < '0' || attr[i][2] > '9')
            {
                da_omautil_context.dd_parse_error = MMI_TRUE;
                return;
            }

            dd2_info->DDVersion = (attr[i][0] - '0') * 10 + (attr[i][2] - '0');
        }
        else
            dd2_info->DDVersion = 10;
        break;

    case DD2_PARSING_STATE_PRODUCT:
        /* in skip mode */
        if(da_omautil_context.dd2_skip)
        {
            da_omautil_context.dd2_skip++;
            return;
        }

        /* <product>, check compund, new a product object */
        if(dd2_info->product_num)    // TODO: only accept 1 product for now
        {
            MMI_ASSERT(da_omautil_context.dd2_skip==0);
            da_omautil_context.dd2_skip++;
            return; 
        }

        DA_ALLOC_OBJ(product, srv_da_oma_dd2_product_struct);
        dd2_info->product_list = product;
        dd2_info->product_num = 1;
        da_omautil_context.dd2_product_idx = 0;
        
        DD_FIND_ATTR("compound", attr, i);
        if(attr[i])
        {
            // TODO: parse compound flag attr[i+1]
            i++;
        }
        break;

    case DD2_PARSING_STATE_MO:
        /* in skip mode */
        if(da_omautil_context.dd2_skip)
        {
            da_omautil_context.dd2_skip++;
            return;
        }

        // TODO: same, support 1 mo only for now 
        product = dd2_info->product_list;
        if(product->mo_num)
        {
            MMI_ASSERT(da_omautil_context.dd2_skip==0);
            da_omautil_context.dd2_skip++;
            return;
        }

        DA_ALLOC_OBJ(mo, srv_da_oma_dd2_mo_struct);
        product->mo_list = mo;
        product->mo_num = 1;
        da_omautil_context.dd2_mo_idx = 0;
        break;
        
    case DD2_PARSING_STATE_META:
        /* in skip mode */
        if(da_omautil_context.dd2_skip)
            return;

        DA_ALLOC_OBJ(meta, srv_da_oma_dd2_meta_struct);

        MMI_ASSERT(da_omautil_context.dd2_product_idx >= 0);
        product = dd2_info->product_list;
        if(da_omautil_context.dd2_mo_idx >= 0)
        {
            mo = product->mo_list;
            mo->meta_info = meta;
        }
        else
        {
            product->meta_info = meta;
        }
        break;
        
    }
}

/*****************************************************************************
* FUNCTION
*   dd_read_data_element
* DESCRIPTION
*   a callback function for XML parser, parse dd file
* PARAMETERS
*
* RETURNS
*   void
*****************************************************************************/
static void _dd2_read_data_element(void *no_used, const S8 * el, const S8 * value, S32 len, S32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32                             i;
    srv_da_oma_dd2_struct           *dd2_info;
    srv_da_oma_dd2_product_struct   *product;
    srv_da_oma_dd2_mo_struct        *mo;
    srv_da_oma_dd2_meta_struct      *meta;
    
    void                            *obj;
    const dd_data_table_struct      *table;
    const dd_type_table_struct      *type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(da_omautil_context.dd_parse_error || da_omautil_context.dd2_skip)
        return;

    if(!el)
    {
        da_omautil_context.dd_parse_error = MMI_TRUE;
        return;
    }

    dd2_info = da_omautil_context.dd2_info;

    product = da_omautil_context.dd2_product_idx >= 0 ? dd2_info->product_list : NULL;
    mo = (product && da_omautil_context.dd2_mo_idx >= 0) ? product->mo_list : NULL;
    meta = mo ? mo->meta_info : (product ? product->meta_info : NULL);

    switch(da_omautil_context.dd2_state_stack[da_omautil_context.dd2_state_level])
    {
    case DD2_PARSING_STATE_VENDOR:
        obj = dd2_info;
        table = dd2_elem_vendor_table;
        break;

    case DD2_PARSING_STATE_META:
        obj = meta;
        table = dd2_elem_meta_table;
        break;

    case DD2_PARSING_STATE_MO:
        // TODO: if there are many multiple, handle it in table
        /* special case for "type" */
        if(DD_IS_TAG("type", el))
        {
            for(i=0;i<4;i++)
            {
                if(!mo->type[i])
                {
                    mo->type[i] = (S8 *)srv_da_adp_mem_allocate( len + 1 );
                    strcpy(mo->type[i], value);
                    break;
                }
            }
            return;
        }
        /* continue */
        
    case DD2_PARSING_STATE_OBJ_URI:
        obj = mo;
        table = dd2_elem_mo_table;
        break;

    case DD2_PARSING_STATE_MEDIA:
        obj = dd2_info;
        table = dd2_elem_media_table;
        break;

    default:
        return;
    }

    i = 0;
    while(table->item)
    {
        if(DD_IS_TAG(table->item, el))
            break;
        table++;
        i++;
    }

    if(!table->item)
        return;

    /* found */
    DA_TRACE_FUNC2(_dd2_read_data_element, i, da_omautil_context.dd2_state_stack[da_omautil_context.dd2_state_level]);
    type = &dd_xsd_type_info_table[table->type];
    
    if(!len || len > type->max_len)
    {
        da_omautil_context.dd_parse_error = MMI_TRUE;
        return;
    }

    MMI_ASSERT(type->func);
    MMI_ASSERT(table->offset % 4 == 0);
    type->func(value, len, obj, table->offset);

}

/*****************************************************************************
* FUNCTION
*   srv_da_oma_parse_dd2
* DESCRIPTION
*   the main function to parse a dd file
* PARAMETERS
*   filename    IN      The path of dd file
*   item        OUT     Output the result to item
* RETURNS
*   MMI_TRUE :  OK
*   MMI_FALSE:  FAIL
*****************************************************************************/
MMI_BOOL srv_da_oma_parse_dd2(U16 * filename, srv_da_job_struct *job, srv_da_oma_dd2_struct *dd2_info, S8* url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    XML_PARSER_STRUCT           parser;
    S32                         ret, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename == NULL)
        return MMI_FALSE;
    
    if (da_omautil_context.dd_parse_busy)
        return MMI_FALSE;

    da_omautil_context.dd_parse_busy = MMI_TRUE;

    da_omautil_context.dd2_info = dd2_info;
    da_omautil_context.dd2_state_level = -1;
    da_omautil_context.dd2_skip = 0;
    da_omautil_context.dd2_mo_idx = -1;
    da_omautil_context.dd2_product_idx = -1;

    da_omautil_context.curr_job = job;
    da_omautil_context.dd_parse_error = MMI_FALSE;

    MMI_ASSERT(url != NULL);
    ANSI_STR_MALLOC_COPY(da_omautil_context.dd_url_base, url, WAP_DL_MAX_URL_LEN);

    MMI_ASSERT(da_omautil_context.dd_url_base != NULL);
    for(i = strlen(da_omautil_context.dd_url_base) - 1; i>=0 ;i--)
    {
        if(da_omautil_context.dd_url_base[i] == '/' ||  da_omautil_context.dd_url_base[i] == '\\' )
        {
            da_omautil_context.dd_url_base[i+1] = 0;
            break;
        }
    }

    xml_new_parser(&parser);
    xml_register_element_handler(&parser, _dd2_read_start_element, _dd2_read_end_element);
    xml_register_data_handler(&parser, _dd2_read_data_element);
    ret = xml_parse(&parser, filename);
    xml_stop_parse(&parser);
    xml_close_parser(&parser);

    da_omautil_context.curr_job = NULL;
    da_omautil_context.dd_parse_busy = MMI_FALSE;
    DA_FREE_BUFFER(da_omautil_context.dd_url_base)

    if(dd2_info->DDVersion == 0)
        dd2_info->DDVersion = DD2_VERSION;

    if (ret == XML_RESULT_OK)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}
#endif

#define OMA_UTIL

void srv_da_oma_report_map_string(S32 error, U16 *strId_p, S8** str_pp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 stringId = 0;
    S8  *string = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(error > 0)
    {
        stringId = srv_fmgr_fs_error_get_string(-error);
        error = SRV_DA_OMA_DEVICE_ABORTED;
    }
    
    for (i = 0; oma_error_tbl[i].report_msg != NULL; i++)
    {
        if (oma_error_tbl[i].errorNo == error)
        {
            if(stringId == 0)
                stringId = oma_error_tbl[i].stringId;
            string = oma_error_tbl[i].report_msg;
            break;
        }
    }
    MMI_ASSERT(stringId && string);

    if(strId_p)
        *strId_p = stringId;
    if(str_pp)
        *str_pp = string;
}

#define OMA_APP_CHECK

/*****************************************************************************
* FUNCTION
*   srv_da_oma_search_install_check_handler
* DESCRIPTION
*   Handler: to find if there is corresponding instal callback funtion
* PARAMETERS
*   type    [IN]    the mime type of file
* RETURNS
*   return the callback function
*****************************************************************************/
const srv_da_oma_install_check_tbl_struct *srv_da_oma_search_install_check_handler(const applib_mime_type_struct * type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == NULL)
    {
        return NULL;
    }

    for (i = srv_da_oma_install_check_hdlr_num - 1; i >= 0; i--)
    {
        if (srv_da_oma_install_check_tbl[i].mime_subtype == type->mime_subtype)
        {
            return &srv_da_oma_install_check_tbl[i];
        }
    }

    return NULL;
}

#endif /* __MMI_OMA_DD_DOWNLOAD__ */

