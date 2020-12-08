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
 *  vcp_text_storage.h
 *
 * Project:
 * --------
 *  Venus MMI
 *
 * Description:
 * ------------
 *  text storage class header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCP_TEXT_STORAGE_H__
#define __VCP_TEXT_STORAGE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vcp_text_utils.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_frame.h"
#include "vfx_signal.h"
#include "vfx_string.h"
#include "vfx_stream.h"
    
extern "C"
{
#include "app_usedetails.h"
#include "custom_mmi_default_value.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VCP_TEXT_STORAGE_MAX_TEXT_LEN   1024
#define VCP_TEXT_STORAGE_MAX_BUF_SIZE   (VCP_TEXT_STORAGE_MAX_TEXT_LEN + 1) * ENCODING_LENGTH
#define VCP_EDITOR_MAX_BUFFER_SIZE      (20 + 2)

// max key word number for every type (url, ussd, email addr, phone number)
// so total keyword would be 20 + 20 + 20 +20
#define VCP_TEXT_MAX_KEYWORD_NUM         20
#define VCP_TEXT_MAX_ICON_NUM            (2048 / 3)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef struct
{
    VfxResId imageId;                           // icon image ID
    const VfxWChar *text;                       // icon text
} VcpIconTable, *pVcpIconTable;

class VcpTextStorage;

/***************************************************************************** 
 * Class VcpTextStorage
 *****************************************************************************/

/*
 * DESCRIPTION
 *  VcpTextStorage is a class provide text storage function.
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VcpTextStorage : public VfxBase
{

// Constructor / Destructor
public:
    VcpTextStorage(IVfxAllocatable *client);

    ~VcpTextStorage();

// Enum
public:
    // <group DOM_TextStorage_VfxTextStorage_Enum>
    // Text type Enum
    enum TextTypeEnum
    {
        TEXT_TYPE_NONE,
        // The text is created from static buffer or global buffer
        TEXT_TYPE_STATIC_STRING,
        // The text is created from dynamic memory pool, need to free
        TEXT_TYPE_DYNAMIC_STRING,
        // The text is from file
        //TEXT_TYPE_FILE,
        // The text is from I/O stream
        //TEXT_TYPE_STREAM,
        // End of enum
        TEXT_TYPE_END_OF_ENUM
    };

    // <group DOM_TextStorage_VfxTextStorage_Enum>
    // Text change type Enum
    enum TextChangeEnum
    {
        TEXT_CHANGE_NONE,
        // Text is set to storage
        TEXT_CHANGE_INIT,
        // Text is inserted
        TEXT_CHANGE_INSERTED,
        // Text is deleted
        TEXT_CHANGE_DELETED,
        // All text is deleted
        TEXT_CHANGE_DELETED_ALL,
        // The text is replaced
        TEXT_CHANGE_REPLACED,
        // End of enum
        TEXT_CHANGE_END_OF_ENUM
    };

    // <group DOM_TextStorage_VfxTextStorage_Enum>
    // Text encoding type Enum
    enum TextEncodingEnum
    {
        // UCS2 encoding type
        TEXT_ENCODING_UCS2,

        // GB encoding type
        TEXT_ENCODING_GB2312,

        // ascii encoding based length
        // if input ASCII char, can input N chars,
        // if input UCS2 char, can only input N/2 chars
        TEXT_ENCODING_ASCII,

        // gsm char based length
        // if input GSM char, can input N chars,
        // if input UCS2 char, can only input N/2 chars
        // if input GSM extension char, it will +2
        TEXT_ENCODING_GSM,

        // 0x81 encoding
        TEXT_ENCODING_0X81,

        // TODO: following encoding types is not support currently
        // UTF8 encoding type
        TEXT_ENCODING_UTF8,

        // End of enum
        TEXT_ENCODING_END_OF_ENUM
    };

// Signal
public:
    // <group DOM_TextStorage_VfxTextStorage_Signal>
    // indicate the text content has been changed with affect text offset and length
    VfxSignal4 <VfxS32, VfxS32, VfxS32, TextChangeEnum> m_signalTextChanged;

// Method
public:
    // <group DOM_TextStorage_VfxTextStorage_Method>
    // Set text with string
    void setText(
        const VfxWString &text,                         // [IN] text content
        VfxBool isStaticBuf = VFX_FALSE,                // [IN] is static or dynamic
        TextEncodingEnum encoding = TEXT_ENCODING_UCS2, // [IN] text encoding 
        VfxS32 maxLen = -1,                             // [IN] max len, -1 means use text length
        VcpRichTextFormat *format = NULL                // [IN] text format if any
        );

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
#endif

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // Set text format
    void setFormat(
        VcpRichTextFormat *format                // [IN] text format if any
        );

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // Add text format
    void addFormat(
        const VcpRichTextFormat &format,         // [IN] text format if any
        VfxS32 shiftOffset = 0                   // [IN] shift the format range by shiftOffset
        );

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // Remove text format
    VfxBool removeFormat(
        const VcpRichTextFormat &format          // [IN] text format if any
        );

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // Set text format
    void setKeyword(
        VfxS32 mode          // [IN] text format if any
        );

#ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
    // <group DOM_TextStorage_VfxTextStorage_Method>
    // Set the icon Mode
    void setIconMode(
        VfxBool mode,                 // [IN] icon mode or not
        VcpIconTable *mapping = NULL, // [IN] icon mapping table
        VfxU8 size = 0               // [IN] mapping table size
        );
#endif

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // get text and object
    const VfxWChar* getText(
        VcpRichTextFormat **object = NULL         // [IN] object list, include object like picture and text format object
        );

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // get text and object
    void getText(
        const VfxWChar **text,                    // [IN] text buffer
        VfxS32 *retLen,                           // [IN] return text length
        VcpRichTextFormat **object = NULL         // [IN] object list, include object like picture and text format object
        );

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // get text and object
    void getText(
        const VfxWChar **text,                    // [IN] text buffer
        VfxS32 len,                               // [IN] text len
        VfxS32 *retLen,                           // [IN] return text length
        VcpRichTextFormat **object = NULL         // [IN] object list, include object like picture and text format object
        );
    
    // <group DOM_TextStorage_VfxTextStorage_Method>
    // get text and object
    void getText(
        const VfxWChar **text,                    // [IN] text buffer
        VfxS32 offset,                            // [IN] offset
        VfxS32 len,                               // [IN] required text len, 0 means all text
        VfxS32 *retLen,                           // [IN] returned text length
        VcpRichTextFormat **object = NULL         // [IN] object list, include object like picture and text format object
        );
    
    // <group DOM_TextStorage_VfxTextStorage_Method>
    // get current index object start position
    VfxS32 getObjectStart(VfxS32 index);

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
#endif

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // Insert text after specific text offset, return the text length inserted
    VfxS32 insertText(
        VfxU32 offset,                            // [IN] text offset
        const VfxWString &text,                   // [IN] text
        VcpRichTextFormat *object = NULL          // [IN] object list, include object like picture and text format object
        );

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // Insert text after specific text offset, return the text length inserted
    VfxS32 insertText(
        VfxU32 offset,                            // [IN] text offset
        const VfxWChar *text,                     // [IN] text
        VcpRichTextFormat *object = NULL          // [IN] object list, include object like picture and text format object
        );

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // Delete text, return the text length deleted
    VfxS32 deleteText(
        VfxU32 offset,                            // [IN] text
        VfxU32 len                                // [IN] text len
        );

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
#endif

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // Delete all text
    void clear();

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // Get text length
    VfxS32 getTextLength() { return m_text.getLength(); }

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // Get rich text format object
    VcpRichTextFormat *getRichTextFormat() const { return m_object; }

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // return specific offset format object
    VcpRichTextFormat *getRichTextFormat(VfxS32 offset);

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // Get rich text format object for specific range (convert the format object)
    // will have a copy of new format list and convert the offset
    VcpRichTextFormat *getRichTextFormat(VfxS32 start, VfxS32 end);

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // Get rich text format object for specific range with start object (convert the format object)
    // will have a copy of new format list and convert the offset
    VcpRichTextFormat *getRichTextFormat(VcpRichTextFormat *startObj, VfxS32 start, VfxS32 end);

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // delete rich text format object list
    void deleteRichTextFormat(VcpRichTextFormat *object);

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // get current text encoding
    TextEncodingEnum getEncoding() const { return m_encoding; }

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // get current text encoding length
    VfxS32 getTextEncodingLength() const;

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // set text max length can be input
    void setMaxLength(VfxS32 maxLength);

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // get text max length can be input
    VfxS32 getMaxLength() const;

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // check if in keyword mode
    VfxBool isKeywordMode() const { return m_mode ? VFX_TRUE : VFX_FALSE; }

#ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
    // <group DOM_TextStorage_VfxTextStorage_Method>
    // check if in icon display mode
    VfxBool isIconMode() const { return m_bIcon; }
#endif

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // get key word from text and convert to text format
    VcpRichText *getKeyword(); 

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // copy format object, it will override previous object list
    void copyFormatObject(VcpRichTextFormat *object);

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // add format object to current object list
    void addFormatObject(VcpRichTextFormat *object);

#ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
    // <group DOM_TextStorage_VfxTextStorage_Method>
    // get icon format
    VcpRichTextFormat *getIconObject(
        VfxS32 start,            // [IN] text start
        VfxS32 end               // [IN] text end
    );
#endif

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // set plus character handling, if true, it can allowed N+1 characters when first char is '+'
    void setPlusCharHandling(
        VfxBool value            // [IN] plus character handling or not
        );

#ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
    // <group DOM_TextStorage_VfxTextStorage_Method>
    // update icon format
    void updateFormatForIcon(
        VfxS32 start,            // [IN] text start
        VfxS32 end               // [IN] text end
    );

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // check if max icon reached
    VfxBool isMaxIconReached() { return m_isMaxIconCount; }

    // <group DOM_TextStorage_VfxTextStorage_Method>
    // check if given text is emotion icon text
    VfxResId getIconIdByText(VfxWChar *text);
#endif

// Implementation
private:
    // get GB encoding length in bytes
    VfxS32 getGBEncodingLength(const VfxWChar *text, VfxS32 size = -1);

    // get GSM encoding length in bytes
    VfxS32 getGSMEncodingLength(const VfxWChar *text, VfxS32 size = -1);

    // get UTF8 encoding length in bytes
    VfxS32 getUTF8EncodingLength(const VfxWChar *text, VfxS32 size = -1);

    // get encoding char count
    void getEncodingCount(const VfxWChar *text, VfxU32 *ucs2, VfxU32 *gsmExt, VfxU32 *nonAscii, VfxS32 count = -1);

    // get encoding length in bytes
    VfxS32 getEncodingLength(const VfxWChar *text, VfxS32 size = -1);

    // get available length return in UCS2 character count
    VfxS32 getAvailableLen(const VfxWChar *text, VfxS32 offset);

    // get GB available length return in UCS2 character count
    VfxS32 getGBAvailableLen(const VfxWChar *text);

    // get GSM available length return in UCS2 character count
    VfxS32 getGSMAvailableLen(const VfxWChar *text);

    // get UTF8 available length return in UCS2 character count
    VfxS32 getUTF8AvailableLen(const VfxWChar *text);

    // get keyword by type
    VcpRichText *getKeywordByType(VcpTextKeyWordEnum type);

    // memory alloc function for applib to find keyword
    static void* textStorageMalloc(VfxU32 size);

    // memory free function for applib to find keyword
    static void textStorageFree(void* p);

    static kal_bool textStorageHiliteCheckStopFunc(applib_addr_type_enum type, applib_address_node_struct *addr, kal_uint32 num);

#ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
    // update format offset when text changes, delete/merge/update format range
    void updateFormat(VfxS32 start, VfxS32 end, VfxS32 offset, VfxS32 charChanged);

    void deleteIconObject(VfxS32 start, VfxS32 end);
#endif

    void sendTextChange(TextChangeEnum type, VfxS32 textLen, VfxS32 offset, VfxS32 charChanged);

// Implementation
protected:

// Implementation

private:
    // text
    VfxWString m_text;

    // text buffer pointer
    VfxWChar *m_textBuffer;

    // rich text format object list
    VcpRichTextFormat *m_object;

    // text type
    TextTypeEnum m_textType;

    // file name
    VfxWString m_fileName;

    // stream
    VfxInputStream *m_stream;

    // key word mode
    VfxS32 m_mode;

#ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
    // icon display support or not
    VfxBool m_bIcon;

    // icon mapping table size
    VfxU8 m_tableSize;

    // icon mapping table
    VcpIconTable *m_mapping;

    // icon mapping table size
    VfxU32 m_iconCount;

    // if max icon count reached
    VfxBool m_isMaxIconCount;
#endif

    // client frame
    IVfxAllocatable *m_client;

    // max length can hold in character count
    VfxS32 m_maxLen;

    // text length in encoding in bytes
    VfxS32 m_encodingLen;

    // text encoding
    TextEncodingEnum m_encoding;

    // ucs2 char count (!(gsm + gsm_ext))
    VfxU32 m_ucs2Count;

    // gsm ext char count
    VfxU32 m_gsmExtCount;

    // non ascii char count (!ascii char)
    VfxU32 m_nonAsciiCount;

    // plus character handling or not
    VfxBool m_plusCharHandling;

    // check if has parse the keyword
    VfxBool m_isKeywordDone;

    // used to save client pointer for textStorageMalloc
    static IVfxAllocatable *s_owner;
};


#endif /* __VCP_TEXT_STORAGE_H__ */
