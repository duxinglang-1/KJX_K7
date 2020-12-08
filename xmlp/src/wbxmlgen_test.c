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
 *  wbxmlgen_test.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  wbxml generator test file
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

//#include "fat_fs.h"
//#include "app_buff_alloc.h"

//#include "wbxmlgen.h"


#ifdef TEST_WBXMLGEN

#include "wbxml_test.h"

#if defined(TEST_WBXMLGEN_MYOWN)

extern const ATTRSTARTTOKEN attrstart_tokens_test[];
extern const TAGTOKEN tag_tokens_test[];
extern const ATTRVALUETOKEN attrvalue_tokens_test[];


static kal_int32 wbxml_test_get_tagtoken_hdlr(const kal_char *tagname, kal_uint8 tagcp,  kal_uint8* token)
{
    kal_uint32 index = 0;

    while(1)
    {
        if (tag_tokens_test[index].tag_name == NULL)
        {
            ASSERT(tag_tokens_test[index].tag_name != NULL);
            return -1;
        }
        if (strcmp(tagname, tag_tokens_test[index].tag_name) == 0)
        {
            *token = tag_tokens_test[index].tag_ref;
            return 0;
        }
        index++;
    }
}

static kal_int32 wbxml_test_get_attrnametoken_hdlr(const kal_char *attrname, kal_uint8 attrcp, kal_uint8* token, void *reserved)
{

    kal_uint32 index = 0;

    while(1)
    {
        if (attrstart_tokens_test[index].name == NULL)
        {
            ASSERT(attrstart_tokens_test[index].name != NULL);
            return -1;
        }
        if (strcmp(attrname, attrstart_tokens_test[index].name) == 0)
        {
            *token = attrstart_tokens_test[index].ref;
            break;
        }
        index++;
    }

    return 0;
}

static kal_int32 wbxml_test_get_attrvaluetoken_hdlr(const kal_char *attrvalue, kal_uint8 attrcp, kal_uint8 *token, kal_uint8 *datatype)
{
    
    kal_uint32 index = 0;
    
 
    while(1)
    {
        if (attrvalue_tokens_test[index].ref == NULL)
        {
             return 0;
        }
        if (strcmp(attrvalue, attrvalue_tokens_test[index].value) == 0)
        {
            *token = attrvalue_tokens_test[index].ref;
            break;
        }
        index++;
    }
    return 0;
}

#else
static kal_int32 wbxml_test_get_tagtoken_hdlr(const kal_char *tagname, kal_uint8 tagcp,  kal_uint8* token)
{
    if (tagname == NULL)
    {
        return -1;
    }
    *token = 0x0F; // for testing, token value is always 0x0F
    return 0;
}


static kal_int32 wbxml_test_get_attrnametoken_hdlr(const kal_char *attrname, kal_uint8 attrcp, kal_uint8* token, void *reserved)
{
    if (attrname == NULL) 
    {
        return -1;
    }
    *token = 0x0E; // for testing, token for attrname is always 0x0E;
    return 0;
}

static kal_int32 wbxml_test_get_attrvaluetoken_hdlr(const kal_char *attrvalue, kal_uint8 attrcp, kal_uint8 *token, kal_uint8 *datatype)
{
    if (attrvalue == NULL) 
    {
        return -1;
    }
     *token = 0x80; // for testing, token for attrvalue is always 0x80; 
    return 0;
}
#endif //TEST_WBXMLGEN_MYOWN

void test_wbxmlgen(void)
{
    
    WG_HANDLE  hd;
    FS_HANDLE  fd;
    kal_char *dest = NULL;
    kal_wchar resultname[128];
    xg_attr_struct attrlist[2];
    char* data = NULL;
    kal_int32 ret, driver;
    kal_uint32 len, buf_len;

    driver = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_DRIVE_I_SYSTEM);
    kal_wsprintf((kal_uint16*)resultname, "%c:\\wbxmlsample.txt",driver); 

    hd = wbxml_new_generator((kal_char*)resultname, 0);
    wbxml_register_get_token_handler(hd, wbxml_test_get_tagtoken_hdlr, 
        wbxml_test_get_attrnametoken_hdlr, wbxml_test_get_attrvaluetoken_hdlr);
    ret = wbxml_generate_header(hd, 1, 0, "test publicid", WBXML_CHARSET_UTF_8);
 
    ret = wbxml_generate_stag(hd,"bookshop", 0, 0, 1);
 
    attrlist[0].attrname = "auther";
    attrlist[0].attrvalue = "Jonh";
    attrlist[1].attrname = "sex";
    attrlist[1].attrvalue = "male";    
    ret = wbxml_generate_stag(hd, "book1", attrlist, 2, 1);
 
    data = "book1:computer book";

     len = strlen(data);
 //   ret = wbxml_generate_data(hd, data, len+1, 0);
        ret = wbxml_generate_data(hd, data, len, 1);
//    ret = wbxml_generate_data(hd, (kal_char*)L"D:\\data", 0, 1);
    ret = wbxml_generate_etag(hd, "book1");
   
    data ="book2:artist book";
    len = strlen(data);
    ret = wbxml_generate_inline_element(hd, "book2", data, len+1, 0);
    
    attrlist[0].attrname = "city";
    attrlist[1].attrvalue = "Beijing";
    ret = wbxml_generate_empty_element(hd, "address", attrlist, 1);
    
    ret = wbxml_generate_etag(hd, "bookshop");
    len = wbxml_close_generator(hd);

    test_wbxmlp("wbxmlsample.txt", 0);

//    free_ctrl_buffer(dest);
}


#endif /* TEST_WBXMLGEN */
#endif /* #ifdef __WBXML_SUPPORT__ */


