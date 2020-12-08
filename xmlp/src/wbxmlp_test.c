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
 *  wbxmlp_test.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  wbxml parser test file
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __WBXML_SUPPORT__

#include "kal_release.h"        /* Basic data type */
#include "fat_fs.h"

#include "wbxmlp.h"
#include "wbxmlp_def.h"

#ifdef TEST_WBXMLP
#include "MMI_trc.h"
#include "app_buff_alloc.h"
#include "wbxml_test.h"

FS_HANDLE  result; /* this file handle is used to save parsing result */
static void wbxml_test_stag_hdlr(void *resv, const kal_char *el, const kal_char **attr);
static void wbxml_test_elem_end_hdlr(void *resv, const kal_char *el);
static void wbxml_test_data_hdlr(void *resv, const kal_char  *el, const kal_char *data, kal_uint32 len, kal_uint8 datatype);
static kal_int32 test_get_tagname_by_token(kal_char *ptr, kal_uint32 tagcp, kal_uint8 token);
static kal_int32 test_get_attrname_by_token(kal_char *ptr, kal_char *prefix, kal_uint32 attrcp, kal_uint8 token);


#ifdef TEST_WBXMLP_SYNCML
const char* tag_sync_tokens_table[2][256];
const char* tag_dev_tokens_table[256];
static kal_int32 mark_space; /* 0: tag_sync_tokens_table; 1: tag_dev_tokens_table */
void init_table()
{   
    /* syncml */
    tag_sync_tokens_table[0][0x05] = "Add";
    tag_sync_tokens_table[0][0x06] = "Alert";
    tag_sync_tokens_table[0][0x07] = "Archive";
    tag_sync_tokens_table[0][0x08] = "Atomic";
    tag_sync_tokens_table[0][0x09] = "Chal";
    tag_sync_tokens_table[0][0x0A] = "Cmd";
    tag_sync_tokens_table[0][0x0B] = "CmdID";
    tag_sync_tokens_table[0][0x0C] = "CmdRef";
    tag_sync_tokens_table[0][0x0D] = "Copy";
    tag_sync_tokens_table[0][0x0E] = "Cred";
    tag_sync_tokens_table[0][0x0F] = "Data";
    tag_sync_tokens_table[0][0x10] = "Delete";
    tag_sync_tokens_table[0][0x11] = "Exec";
    tag_sync_tokens_table[0][0x12] = "Final";
    tag_sync_tokens_table[0][0x13] = "Get";
    tag_sync_tokens_table[0][0x14] = "Item";
    tag_sync_tokens_table[0][0x15] = "Lang";
    tag_sync_tokens_table[0][0x16] = "LocName";
    tag_sync_tokens_table[0][0x17] = "LocURI";
    tag_sync_tokens_table[0][0x18] = "Map";
    tag_sync_tokens_table[0][0x19] ="MapItem";
    tag_sync_tokens_table[0][0x1A] ="Meta";
    tag_sync_tokens_table[0][0x1B] ="MsgID";
    tag_sync_tokens_table[0][0x1C] ="MsgRef";
    tag_sync_tokens_table[0][0x1D] ="NoResp";
    tag_sync_tokens_table[0][0x1E] ="NoResults";
    tag_sync_tokens_table[0][0x1F] ="Put";
    tag_sync_tokens_table[0][0x20] ="Replace";
    tag_sync_tokens_table[0][0x21] ="RespURI";
    tag_sync_tokens_table[0][0x22] ="Results";
    tag_sync_tokens_table[0][0x23] ="Search";
    tag_sync_tokens_table[0][0x24] ="Sequence";
    tag_sync_tokens_table[0][0x25] ="SessionID";
    tag_sync_tokens_table[0][0x26] ="SftDel";
    tag_sync_tokens_table[0][0x27] ="Source";
    tag_sync_tokens_table[0][0x28] ="SourceRef";
    tag_sync_tokens_table[0][0x29] ="Status";
    tag_sync_tokens_table[0][0x2A] ="Sync";
    tag_sync_tokens_table[0][0x2B] ="SyncBody";
    tag_sync_tokens_table[0][0x2C] ="SyncHdr";
    tag_sync_tokens_table[0][0x2D] ="SyncML";
    tag_sync_tokens_table[0][0x2E] ="Target";
    tag_sync_tokens_table[0][0x2F] ="TargetRef";
    tag_sync_tokens_table[0][0x31] ="VerDTD";
    tag_sync_tokens_table[0][0x32] ="VerProto";
    tag_sync_tokens_table[0][0x33] ="NumberOfChanges";
    tag_sync_tokens_table[0][0x34] ="MoreData";
    tag_sync_tokens_table[0][0x35] ="Field";
    tag_sync_tokens_table[0][0x36] ="Filter";
    tag_sync_tokens_table[0][0x37] ="Record";
    tag_sync_tokens_table[0][0x38] ="FilterType";
    tag_sync_tokens_table[0][0x39] ="SourceParent";
    tag_sync_tokens_table[0][0x3A] ="TargetParent";
    tag_sync_tokens_table[0][0x3B] ="Move";
    tag_sync_tokens_table[0][0x3C] ="Correlator";

    /* Metinf */
    tag_sync_tokens_table[1][0x05] = "Anchor";
    tag_sync_tokens_table[1][0x06] = "EMI";
    tag_sync_tokens_table[1][0x07] = "Format";
    tag_sync_tokens_table[1][0x08] = "FreeID";
    tag_sync_tokens_table[1][0x09] = "FreeMem";
    tag_sync_tokens_table[1][0x0A] = "Last";
    tag_sync_tokens_table[1][0x0B] = "Mark";
    tag_sync_tokens_table[1][0x0C] = "MaxMsgSize";
    tag_sync_tokens_table[1][0x0D] = "Mem";
    tag_sync_tokens_table[1][0x0E] = "MetInf";
    tag_sync_tokens_table[1][0x0F] = "Next";
    tag_sync_tokens_table[1][0x10] = "NextNonce";
    tag_sync_tokens_table[1][0x11] = "SharedMem";
    tag_sync_tokens_table[1][0x12] = "Size";
    tag_sync_tokens_table[1][0x13] = "Type";
    tag_sync_tokens_table[1][0x14] = "Version";
    tag_sync_tokens_table[1][0x15] = "MaxObjSize";
    tag_sync_tokens_table[1][0x16] = "FieldLevel";

    /* devinfo tag */

    tag_dev_tokens_table[0x05] = "CTCap";
    tag_dev_tokens_table[0x06] = "CTType";
    tag_dev_tokens_table[0x07] = "DataStore";
    tag_dev_tokens_table[0x08] = "DataType";
    tag_dev_tokens_table[0x09] = "DevID";
    tag_dev_tokens_table[0x0A] = "DevInf";
    tag_dev_tokens_table[0x0B] = "DevTyp";
    tag_dev_tokens_table[0x0C] = "DisplayName";
    tag_dev_tokens_table[0x0D] = "DSMem";
    tag_dev_tokens_table[0x0E] = "Ext";
    tag_dev_tokens_table[0x0F] = "FwV";
    tag_dev_tokens_table[0x10] = "HwV";
    tag_dev_tokens_table[0x11] = "Man";
    tag_dev_tokens_table[0x12] = "MaxGUIDSize";
    tag_dev_tokens_table[0x13] = "MaxID";
    tag_dev_tokens_table[0x14] = "MaxMem";
    tag_dev_tokens_table[0x15] = "Mod";
    tag_dev_tokens_table[0x16] = "OEM";
    tag_dev_tokens_table[0x17] = "ParamName";
    tag_dev_tokens_table[0x18] = "PropName";
    tag_dev_tokens_table[0x19] = "Rx";
    tag_dev_tokens_table[0x1A] = "Rx-Pref";
    tag_dev_tokens_table[0x1B] = "SharedMem";
    tag_dev_tokens_table[0x1C] = "Size";
    tag_dev_tokens_table[0x1D] = "SourceRef";
    tag_dev_tokens_table[0x1E] = "SwV";
    tag_dev_tokens_table[0x1F] = "SyncCap";  
    tag_dev_tokens_table[0x20] = "SyncType";
    tag_dev_tokens_table[0x21] = "Tx";
    tag_dev_tokens_table[0x22] = "Tx-Pref";
    tag_dev_tokens_table[0x23] = "ValEnum";
    tag_dev_tokens_table[0x24] = "VerCT";
    tag_dev_tokens_table[0x25] = "VerDTD";
    tag_dev_tokens_table[0x26] = "Xnam";
    tag_dev_tokens_table[0x27] = "Xval";
    tag_dev_tokens_table[0x28] = "UTC";
    tag_dev_tokens_table[0x29] = "SupportNumberOfChanges";
    tag_dev_tokens_table[0x2A] = "SupportLargeObjs";
    tag_dev_tokens_table[0x2B] = "Property";
    tag_dev_tokens_table[0x2C] = "PropParam";
    tag_dev_tokens_table[0x2D] = "MaxOccur";
    tag_dev_tokens_table[0x2E] = "NoTruncate";

    tag_dev_tokens_table[0x30] = "Filter-Rx";
    tag_dev_tokens_table[0x31] = "FilterCap";
    tag_dev_tokens_table[0x32] = "FilterKey";
    tag_dev_tokens_table[0x33] = "FieldLevel";
    tag_dev_tokens_table[0x34] = "SupportHierarchicalSync";
}


const static ATTRSTARTTOKEN attrstart_tokens_test[]={
    { NULL, NULL, 0},   
};

const ATTRVALUETOKEN attrvalue_tokens_test[]=
{
    {NULL,0},
};
#endif //TEST_WBXMLP_SYNCML


#ifdef TEST_WBXMLP_WML  // for test cases of wml
const static TAGTOKEN tag_tokens_test[]=
{
    { "pre", 0x1B },
    { "a", 0x1C },
    { "td", 0x1D },
    { "tr", 0x1E },
    { "table", 0x1F },
    { "p", 0x20 },
    { "postfield", 0x21 },
    { "anchor", 0x22 },
    { "access", 0x23 },
    { "b", 0x24 },
    { "big", 0x25 },
    { "br",  0x26 },
    { "card", 0x27 },
    { "do", 0x28 },
    { "em", 0x29 },
    { "fieldset", 0x2A },
    { "go", 0x2B },
    { "head", 0x2C },
    { "i", 0x2D },
    { "img", 0x2E },
    { "input", 0x2F },
    { "meta", 0x30 },
    { "noop", 0x31 },
    { "prev", 0x32 },
    { "onevent", 0x33 },
    { "optgroup", 0x34 },
    { "option", 0x35 },
    { "refresh", 0x36 },
    { "select", 0x37 },
    { "small", 0x38 },
    { "strong", 0x39 },
    { "template", 0x3B },
    { "timer", 0x3C },
    { "u", 0x3D },
    { "setvar", 0x3E },
    { "wml", 0x3F },   
    { NULL, 0},
};


const static ATTRSTARTTOKEN attrstart_tokens_test[]={
    { "accept-charset", NULL, 0x05 },
    { "align", "bottom", 0x06 },
    { "align", "center", 0x07 },
    { "align", "left", 0x08 },
    { "align", "middle", 0x09 },
    { "align", "right", 0x0A },
    { "align", "top", 0x0B },
    { "alt", NULL, 0x0C },
    { "content", NULL, 0x0D },
    { "domain", NULL, 0x0F },
    { "emptyok", "false", 0x10 },
    { "emptyok", "true", 0x11 },
    { "format", NULL, 0x012 },
    { "height", NULL, 0x013 },
    { "hspace", NULL, 0x014 },
    { "ivalue", NULL, 0x15 },
    { "iname", NULL, 0x16 },
    { "label", NULL, 0x18 },
    { "localsrc", NULL, 0x19 },
    { "maxlength", NULL, 0x1A },
    { "method", "get", 0x1B },
    { "method", "post", 0x1C },
    { "mode", "nowrap", 0x1D },
    { "mode", "wrap", 0x1E },
    { "multiple", "false", 0x1F },
    { "multiple", "true", 0x20 },
    { "name", NULL, 0x21 },
    { "newcontext", "false", 0x22 },
    { "newcontext", "true", 0x23 },
    { "onpick", NULL, 0x24 },
    { "onenterbackward", NULL, 0x25 },
    { "onenterforward", NULL, 0x26 },
    { "ontimer", NULL, 0x27 },
    { "optional", "false", 0x28 },
    { "optional", "true", 0x29 },
    { "path", NULL, 0x2A },
    { "scheme", NULL, 0x2E },
    { "sendreferer", "false", 0x2F },
    { "sendreferer", "true", 0x30 },
    { "size", NULL, 0x31 },
    { "src", NULL, 0x32 },
    { "ordered", "true", 0x33 },
    { "ordered", "false", 0x34 },
    { "tabindex", NULL, 0x35 },
    { "title", NULL, 0x36 },
    { "type", NULL, 0x37 },
    { "type", "accept", 0x38 },
    { "type", "delete", 0x39 },
    { "type", "help", 0x3A },
    { "type", "password", 0x3B },
    { "type", "onpick", 0x3C },
    { "type", "onenterbackward", 0x3D },
    { "type", "onenterforward", 0x3E },
    { "type", "ontimer", 0x3F },
    { "type", "options", 0x45 },
    { "type", "prev", 0x46 },
    { "type", "reset", 0x47 },
    { "type", "text", 0x48 },
    { "type", "vnd.", 0x49 },
    { "href", NULL, 0x04A },
    { "href", "http://", 0x4B },
    { "href", "https://", 0x4C },
    { "value", NULL, 0x4D },
    { "vspace", NULL, 0x4E },
    { "width", NULL, 0x4F },
    { "xml:lang", NULL, 0x50 },
    { "align", NULL, 0x52 },
    { "columns", NULL, 0x53 },
    { "class", NULL, 0x54 },
    { "id", NULL, 0x55 },
    { "forua", "false", 0x56 },
    { "forua", "true", 0x57 },
    { "src", "http://", 0x58 },
    { "src", "https://", 0x59 },
    { "http-equiv", NULL, 0x05A },
    { "http-equiv", "Content-Type", 0x5B },
    { "content", "application/vnd.wap.wmlc;charset=", 0x5C },
    { "http-equiv", "Expires", 0x5D },
    { "accesskey", NULL, 0x5E },
    { "enctype", NULL, 0x5F },
    { "enctype", "application/x-www-form-urlencoded", 0x60 },
    { "enctype", "multipart/form-data", 0x61 },
    { NULL, NULL, 0},
};

const ATTRVALUETOKEN attrvalue_tokens_test[]=
{
    ///attributes value tokens
    { ".com/", 0x85 },
    { ".edu/", 0x86 },
    { ".net/", 0x87 },
    { ".org/", 0x88 },
    { "accept", 0x89 },
    { "bottom", 0x8A },
    { "clear", 0x8B },
    { "delete", 0x8C },
    { "help", 0x8D },
    { "http://", 0x8E },
    { "http://www.", 0x8F },
    { "https://", 0x90 },
    { "https://www.", 0x91 },
    { "middle", 0x93 },
    { "nowrap", 0x94 },
    { "onpick", 0x95 },
    { "onenterbackward", 0x96 },
    { "onenterforward", 0x97 },
    { "ontimer", 0x98 },
    { "options", 0x99 },
    { "password", 0x9A },
    { "reset", 0x9B },
    { "text", 0x9D },
    { "top", 0x9E },
    { "unknown", 0x9F },
    { "wrap", 0xA0 },
    { "Www.", 0xA1 },
    {NULL,0},
};
#endif  //TEST_WBXMLP_WML


#ifdef TEST_WBXMLP_MYOWN   // for test cases made by myself
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
#endif
const TAGTOKEN tag_tokens_test[]={
    {"bookshop", 0x05},
    {"book1", 0x06},
    {"contact", 0x07},
    {"address", 0x08},
    {"email", 0x09},
    {"book2", 0x0A},
    {"book3", 0x0B},    
    {NULL, 0},
};

const ATTRSTARTTOKEN attrstart_tokens_test[] ={
    {"street", NULL, 0x05},
    {"city", NULL, 0x06},
    {"auther", NULL, 0x07},
    {"sex", NULL, 0x08},
    {NULL, NULL, 0},
};

const ATTRVALUETOKEN attrvalue_tokens_test[] = {
    {"Beijing", 0x85},
    {NULL, 0},    
};

#endif /* TEST_WBXMLP_MYOWN  */




/*****************************************************************************
 * FUNCTION
 *  wbxml_test_stag_hdlr
 * DESCRIPTION
 *  this function is used as  element start handler when testing.
 * PARAMETERS
 *  resv        [IN]        reserved
 *  el          [IN]        Element name
 *  attr        [IN]        Attribution list
 * RETURNS
 *  void
 *****************************************************************************/
static void wbxml_test_stag_hdlr(void *resv, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    kal_int32 i=0, length ;
    kal_char *el_info;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    el_info = get_ctrl_buffer(1024);
    memset(el_info, 0, 1024);

    strcat(el_info, "<");
    strcat(el_info, el);
    strcat(el_info, " ");


    while ((attr[i] != NULL) && (attr[i+1] != NULL))
    {
        strcat(el_info, attr[i]);
        strcat(el_info, " = ");
        strcat(el_info, attr[i+1]);
        strcat(el_info, "; ");
        i+=2;
    }

    strcat(el_info, ">");
    strcat(el_info, "\r\n");

    kal_prompt_trace(MOD_MMI, el_info);
    FS_Write(result, el_info, strlen(el_info), (kal_uint32*)&length);
    free_ctrl_buffer(el_info);
    el_info = NULL;

}


/*****************************************************************************
 * FUNCTION
 *  wbxml_test_elem_end_hdlr
 * DESCRIPTION
 *  this function is used as default element_end_handler when testing
 * PARAMETERS
 *  resv        [IN]        reserved
 *  el          [IN]        Element name
 * RETURNS
 *  void
 *****************************************************************************/
static void wbxml_test_elem_end_hdlr(void *resv, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_char endtag[100];
    kal_int32 length;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(endtag, 0, 100);
    strcat(endtag, "</");
    strcat(endtag, el);
    strcat(endtag, ">");
    strcat(endtag, "\r\n");

    kal_prompt_trace(MOD_MMI, endtag);
    FS_Write(result, endtag, strlen(endtag), (kal_uint32*)&length);

}


/*****************************************************************************
 * FUNCTION
 *  wbxml_test_data_hdlr
 * DESCRIPTION
 *  this function is used as general data handler when testing
 * PARAMETERS
 *  resv        [IN]        reserved
 *  el          [IN]        Element name
 *  data        [IN]        Data to be handled
 *  len         [IN]        Length of data   
 *  datataype   [IN]        data type of data(1:string; 2:opaque; 3: entity; 4:extension; 5: mixed)
 * RETURNS
 *  void
 *****************************************************************************/
static void wbxml_test_data_hdlr(void *resv, const kal_char  *el, const kal_char *data, kal_uint32 len, kal_uint8 datatype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 length;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (len != 0)
    {
        kal_prompt_trace(MOD_MMI, data);
        kal_prompt_trace(MOD_MMI, "\r\n");
        FS_Write(result, (void*)data, len, &length);
        FS_Write(result, "\r\n", 2, &length);
    }
    else
    {
        kal_prompt_trace(MOD_MMI, "data is saved in file");
        kal_prompt_trace(MOD_MMI, "\r\n");
        FS_Write(result, "data is saved in file", strlen("data is saved in file"), &length);
        FS_Write(result, "\r\n", 2, &length);        
    }
  
}

/*****************************************************************************
 * FUNCTION
 *  test_get_name_by_token
 * DESCRIPTION
 *  this function is used to get tagname by token 
 * PARAMETERS
 *  ptr             [IN]        buf to save tag name
 *  tagcp           [IN]        tag space code page
 *  token           [IN]        token of tag
 * RETURNS
 *  if < 0: failed
 *****************************************************************************/
#if defined(TEST_WBXMLP_SYNCML) 

static kal_int32 test_get_tagname_by_token(kal_char *ptr, kal_uint32 tagcp, kal_uint8 token)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mark_space == 0)
    {

        if (tag_sync_tokens_table[tagcp][token] == NULL)
        {
            ASSERT(tag_sync_tokens_table[tagcp][token] != NULL);
            return 0; /* cannot find token in tag token space */
        }
        len = strlen(tag_sync_tokens_table[tagcp][token]);

        if (len < WBXML_MAX_BUFFER_SIZE)
        {
            strcpy(ptr, tag_sync_tokens_table[tagcp][token]);
            return len;
        }
        else    /* len is over 2k */
        {
            ASSERT(len < WBXML_MAX_BUFFER_SIZE);
            return -1;
        }
       
    }
    else if(mark_space == 1)
    {
        if (tag_dev_tokens_table[token] == NULL)
        {
            return 0; /* cannot find token in tag token space */
        }
        len = strlen(tag_dev_tokens_table[token]);

        if (len < WBXML_MAX_BUFFER_SIZE)
        {
            strcpy(ptr, tag_dev_tokens_table[token]);
            return len;
        }
        else    /* len is over 2k */
        {
            return -1;
        }
    }
     return 0;
}

#else
static kal_int32 test_get_tagname_by_token(kal_char *ptr, kal_uint32 tagcp, kal_uint8 token)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(TEST_WBXMLP_WML) || defined(TEST_WBXMLP_MYOWN))
    kal_int32  index=0;
    while(1)
    {
        if (tag_tokens_test[index].tag_name == NULL)
        {
            ASSERT(tag_tokens_test[index].tag_name != NULL);
            return 0; /* cannot find token in tag token space */
        }
        if (tag_tokens_test[index].tag_ref == token)
        {
            len = strlen(tag_tokens_test[index].tag_name);
            if (len < WBXML_MAX_BUFFER_SIZE)
            {
                strcpy(ptr, tag_tokens_test[index].tag_name);
                return len;
            }
            else    /* len is over 2k */
            {
                ASSERT(len < WBXML_MAX_BUFFER_SIZE);
                return -1;
            }
        }
        index++;
    }
     return 0;
#else
    static kal_int32  index;
    len = strlen("tagname");
    strcpy(ptr, "tagname");
    sprintf(ptr+len, "%02d--%2d", index, token);
    index++;
    return len+4;
#endif    //(defined(TEST_WBXMLP_WML) || defined(TEST_WBXMLP_MYOWN))

}
#endif /* TEST_WBXMLP_SYNCML */

/*****************************************************************************
 * FUNCTION
 *  test_get_attrname_by_token
 * DESCRIPTION
 *  this function is used to get attrname by token 
 * PARAMETERS
 *  ptr             [IN]        buf to save attribute name or attribute value
 *  prefix          [IN]        buf to save attribute value prefix if prefix is exsit in attrstart
 *  attrcp          [IN]        attribute code page
 *  token           [IN]        token of attrstart or attrvalue
 * RETURNS
 *  if < 0, failed
 *****************************************************************************/
static kal_int32 test_get_attrname_by_token(kal_char *ptr, kal_char *prefix, kal_uint32 attrcp, kal_uint8 token)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 len1, len2;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if (defined(TEST_WBXMLP_WML) || defined(TEST_WBXMLP_MYOWN) || defined(TEST_WBXMLP_SYNCML))
    kal_int32 index = 0;
    if (token < 128) /* attrstart token */
    {
        while(1)
        {
            if (attrstart_tokens_test[index].name == NULL)
            {
                ASSERT(attrstart_tokens_test[index].name != NULL);
                return 0; /* cannot find token in tag token space */
            }
            if (attrstart_tokens_test[index].ref == token)
            {/* find token in token space */
                if ((len1 = strlen(attrstart_tokens_test[index].name)) < WBXML_MAX_BUFFER_SIZE)
                {
                    strcpy(ptr, attrstart_tokens_test[index].name);
                }
                if (attrstart_tokens_test[index].prefix != NULL)
                {/* prefix is not NULL, copy it to attrvalue */
                    if ((len2 = strlen(attrstart_tokens_test[index].prefix))<WBXML_MAX_BUFFER_SIZE)
                    {
                        strcpy(prefix, attrstart_tokens_test[index].prefix);
                    }
                }
                if (len1 < WBXML_MAX_BUFFER_SIZE)
                {
                    return len1;
                }
                else    /* len is over 2k */
                {
                    ASSERT(len1 < WBXML_MAX_BUFFER_SIZE);
                    return -1;
                }
            }
            index++;
        }
    }
    else            /* attrvalue token */
    {
        while(1)
        {
            if (attrvalue_tokens_test[index].value == NULL)
            {
                ASSERT(attrvalue_tokens_test[index].value != NULL);
                return 0; /* cannot find token in tag token space */
            }
            if (attrvalue_tokens_test[index].ref == token)
            {
                len2 = strlen(attrvalue_tokens_test[index].value);
                if (len2 < WBXML_MAX_BUFFER_SIZE)
                {
                    strcpy(ptr, attrvalue_tokens_test[index].value);
                    return len2;
                }
                else    /* len is over 2k */
                {
                    ASSERT(len2 < WBXML_MAX_BUFFER_SIZE);
                    return -1;
                }
            }
            index++;
        }
    }
    return 0;
#else
    static kal_int32  index;
    len1 = strlen("attr");
    strcpy(ptr, "attr");
    sprintf(ptr+len1, "%2d", index);
    index++;
    return len1+2;
    
#endif  //(defined(TEST_WBXMLP_WML) || defined(TEST_WBXMLP_MYOWN) || defined(TEST_WBXMLP_SYNCML))
    }

/*****************************************************************************
 * FUNCTION
 *  test_wbxmlp
 * DESCRIPTION
 *  this function is used to test wbxml parser
 * PARAMETERS
 *  void
 * RETURNS
 * void
 *****************************************************************************/
void test_wbxmlp(kal_char *src, kal_uint32 buf_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_wchar resultname[128];
    kal_wchar testname[128];
    kal_int32 ret;
    static kal_int32 driver;
    kal_char *err_tag;
    WP_HANDLE hd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ( result == 0)
    {
        driver = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_DRIVE_I_SYSTEM);
        kal_wsprintf((kal_uint16*)resultname, "%c:\\result",driver);
        result = FS_Open(resultname, FS_READ_WRITE | FS_CREATE_ALWAYS);
        kal_prompt_trace(MOD_MMI, "result handle :%c\r\n", result);
    }

    if ((hd = wbxml_new_parser()) == -1)
    {
        return;
    }
    wbxml_register_header_handler(hd, NULL);
    wbxml_register_element_handler(hd, wbxml_test_stag_hdlr, wbxml_test_elem_end_hdlr);
    wbxml_register_data_handler (hd, wbxml_test_data_hdlr);
    wbxml_register_get_name_handler(hd, test_get_tagname_by_token, test_get_attrname_by_token);

    if (buf_len == 0)
    {
        kal_wsprintf(testname, "%c:\\%s",driver, src); 
    ret = wbxml_parse(hd, (char*)testname, 0);
    }
    else
    {
        ret = wbxml_parse(hd, src, buf_len);
    }
    if (ret < 0)
    {
        err_tag = wbxml_get_error_tag(hd);
    }
    wbxml_close_parser(hd); 
    FS_Close (result);
    result = 0;
}

#endif /* TEST_WBXMLP */
#endif /* #ifdef __WBXML_SUPPORT__ */


