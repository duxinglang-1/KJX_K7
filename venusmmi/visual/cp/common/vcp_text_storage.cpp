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
 *  Vcp_text_storage.cpp
 *
 * Project:
 * --------
 *  Venus MMI
 *
 * Description:
 * ------------
 *  text storage class
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_text_storage.h"
#include "mmi_rp_srv_venus_component_text_view_def.h"
#include "vadp_sys_trc.h"
#include "vcp_info_balloon.h"
#include "mmi_rp_srv_editor_def.h"

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

extern "C"
{
#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif
}

#ifdef __cplusplus
extern "C"
{
#include "Unicodexdcl.h"
#include "wgui_inputs.h"
#include "app_usedetails.h"
#include "fs_func.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "string.h"
#include "phbsrvgprot.h"  // 0x81 handling
}
#endif

#include "vfx_string.h"
#include "vfx_datatype.h"
#include "vcp_text_utils.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_frame.h"
#include "vfx_system.h"
#include "vrt_datatype.h"
#include "MMIDataType.h"
#include "vfx_signal.h" 
#include "custom_mmi_default_value.h"
#include "vfx_stream.h"
#include "vfx_font_desc.h"


/***************************************************************************** 
 * Class VcpTextStorage
 *****************************************************************************/

IVfxAllocatable *VcpTextStorage::s_owner = NULL;

VcpTextStorage::VcpTextStorage(IVfxAllocatable *client)
{
    m_text = VFX_WSTR_NULL;
    m_object = NULL;
    m_textType = TEXT_TYPE_NONE;
    m_fileName = VFX_WSTR_NULL;
    m_maxLen = -1;
    m_encodingLen = 0;
    m_encoding = TEXT_ENCODING_UCS2;
    m_client = client;
    m_mode = VCP_TEXT_KEYWORD_NONE;
#ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
    m_bIcon = VFX_FALSE;
    m_tableSize = 0;
    m_mapping = NULL;
    m_iconCount = 0;
    m_isMaxIconCount = VFX_FALSE;
#endif
    m_ucs2Count = 0;
    m_gsmExtCount = 0;
    m_nonAsciiCount = 0;
    m_plusCharHandling = VFX_FALSE;
    m_isKeywordDone = VFX_FALSE;

    // Initialize
    VFX_ALLOC_MEM(m_textBuffer, VCP_EDITOR_MAX_BUFFER_SIZE, client);
    m_textType = TEXT_TYPE_DYNAMIC_STRING;

    m_textBuffer[0] = 0;
    m_text = VFX_WSTR_STATIC(m_textBuffer);
}

    
VcpTextStorage::~VcpTextStorage()
{
    // deinitialize
    if (m_textBuffer)
    {
        VFX_FREE_MEM(m_textBuffer);
        m_textBuffer = NULL;
    }

    if (m_object)
    {
        deleteRichTextFormat(m_object);
        m_object = NULL;
    }
}


VfxS32 VcpTextStorage::getGBEncodingLength(const VfxWChar *text, VfxS32 size)
{
    VfxS32 enLen = 0;
    VfxU8 i = 0;
    VfxU8 char_len;
    VfxWChar ucs2_char;

    if (size == -1)
    {
        size = vfx_sys_wcslen(text);
    }

    while (i < size)
    {
        ucs2_char = text[i++];
        char_len = VCP_TEXT_GET_GB_LEN(ucs2_char);
        enLen += char_len;
    }

    return enLen;
}


VfxS32 VcpTextStorage::getGSMEncodingLength(const VfxWChar *text, VfxS32 size)
{
    VfxS32 enLen = 0;
    VfxU8 i = 0;
    if (size == -1)
    {
        size = vfx_sys_wcslen(text);
    }

    while (i < size)
    {
        if (VCP_TEXT_IS_GSM_EXT_CHAR(text[i++]))
        {
            enLen += 2;
        }
        else
        {
            enLen++;
        }
    }

    return enLen;
}


VfxS32 VcpTextStorage::getUTF8EncodingLength(const VfxWChar *text, VfxS32 size)
{
    VfxS32 enLen = 0;

    VfxU8 i = 0;
    if (size == -1)
    {
        size = vfx_sys_wcslen(text);
    }

    while (i < size)
    {
        VfxWChar checkString[2] = {0};
        checkString[0] = text[i++];
        enLen += VCP_TEXT_GET_UTF8_LEN(checkString);
    }

    return enLen;
}


void VcpTextStorage::getEncodingCount(const VfxWChar *text, VfxU32 *ucs2, VfxU32 *gsmExt, VfxU32 *nonAscii, VfxS32 count)
{
    VfxS32 textLen = vfx_sys_wcslen(text);
    VfxU32 ucs2Count = 0;
    VfxU32 gsmExtCount = 0;
    VfxU32 nonAsciiCount = 0;

    if (count > 0 && count < textLen)
    {
        textLen = count;
    }

    // only get the count for non-UCS2 encoding to enhance performance
    if (m_encoding != TEXT_ENCODING_UCS2)
    {
        for (VfxS32 i = 0; i < textLen; i++)
        {
            if (VCP_TEXT_IS_UCS2_CHAR(text[i]))
            {
                ucs2Count++;
            }
            if (VCP_TEXT_IS_GSM_EXT_CHAR(text[i]))
            {
                gsmExtCount++;
            }

            if (!VCP_TEXT_IS_ASCII_CHAR(text[i]))
            {
                nonAsciiCount++;
            }
        }
    }

    *ucs2 = ucs2Count;
    *gsmExt = gsmExtCount;
    *nonAscii = nonAsciiCount;
}


VfxS32 VcpTextStorage::getEncodingLength(const VfxWChar *text, VfxS32 size)
{
    VfxS32 enLen = 0;
    VfxS32 textLen = vfx_sys_wcslen(text);

    switch (m_encoding)
    {
    case TEXT_ENCODING_UTF8:
        enLen = getUTF8EncodingLength(text, size);
        break;
    case TEXT_ENCODING_GB2312:
        enLen = getGBEncodingLength(text, size);
        break;
    case TEXT_ENCODING_GSM:
        enLen = getGSMEncodingLength(text, size);
        break;
    default:
        if (size >= 0)
        {
            enLen = VFX_MIN(size, textLen);
        }
        else
        {
            enLen = textLen;
        }
        break;
    }

    return enLen;
}


void VcpTextStorage::setText(const VfxWString &text, VfxBool isStaticBuf, TextEncodingEnum encoding, VfxS32 maxLen, VcpRichTextFormat *format)
{
    // used for editing counter
    if (maxLen == -1)
    {
        m_maxLen = text.getLength();
    }
    else
    {
        m_maxLen = maxLen;
    }

    VFX_FREE_MEM(m_textBuffer);

    if (isStaticBuf)
    {
        m_text = VFX_WSTR_STATIC(text.getBuf());
        m_textType = TEXT_TYPE_STATIC_STRING;
    }
    else
    {
        const VfxWChar *textBuf = text.getBuf();
        // leave extra buffer for plus character
        VFX_ALLOC_MEM(m_textBuffer, (m_maxLen + 2) * sizeof(VfxWChar), m_client);
        if (textBuf)
        {
            vfx_sys_wcsncpy((VfxWChar *)m_textBuffer, (VfxWChar *)textBuf, m_maxLen + 1);
        }
        else
        {
            m_textBuffer[0] = 0;
        }

        m_text = VFX_WSTR_STATIC(m_textBuffer);
        m_textType = TEXT_TYPE_DYNAMIC_STRING;
    }

    // delete format object when set text
    if (m_object)
    {
        deleteRichTextFormat(m_object);
    #ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
        m_iconCount = 0;
    #endif
        m_object = NULL;
    }

    m_encoding = encoding;

    // calculate count of ucs2, ascii, gsm
    getEncodingCount(text.getBuf(), &m_ucs2Count, &m_gsmExtCount, &m_nonAsciiCount);
    
    // get encoding len
    m_encodingLen = getEncodingLength(text.getBuf());

    // add format
    if (format)
    {
        addFormatObject(format);
    }

    // need to re-parse the keyword
    m_isKeywordDone = VFX_FALSE;
        
    m_signalTextChanged.emit(0, m_text.getLength(), 0, TEXT_CHANGE_INIT);
}

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
/* under construction !*/
#endif

void VcpTextStorage::setFormat(VcpRichTextFormat *format)
{
    copyFormatObject(format);
}


void VcpTextStorage::addFormat(const VcpRichTextFormat &format, VfxS32 shiftOffset)
{
    if (shiftOffset > 0)
    {
        VcpRichTextFormat *head = (VcpRichTextFormat *)&format;
        while (head)
        {
            head->m_range.shift(shiftOffset);
            head = head->getNext();
        }
    }

    addFormatObject((VcpRichTextFormat *)&format);
}


VfxBool VcpTextStorage::removeFormat(const VcpRichTextFormat &format)
{
    if (m_object == NULL)
    {
        return VFX_FALSE;
    }

    VcpRichTextFormat *pObject = m_object;
    VcpRichTextFormat *preObject = NULL;
    while (pObject)
    {
        if (pObject->m_range.getStart() == format.m_range.getStart() &&
            pObject->m_range.getEnd() == format.m_range.getEnd())
        {
            VcpRichTextFormat *delObject = pObject;
            pObject = pObject->m_next;
            // delete the object
            if (preObject == NULL)
            {
                m_object = pObject;
            }
            else
            {
                preObject->m_next = pObject;
            }

            VFX_DELETE(delObject);

            return VFX_TRUE;
        }

        preObject = pObject;
        pObject = pObject->m_next;
    }

    return VFX_FALSE;
}


void VcpTextStorage::setKeyword(VfxS32 mode)
{
    if (m_mode != mode)
    {
        m_mode = mode;
    }
    m_isKeywordDone = VFX_FALSE;
}


#ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
void VcpTextStorage::setIconMode(VfxBool mode, VcpIconTable *mapping, VfxU8 size)
{
    if (m_bIcon != mode)
    {
        m_bIcon = mode;
        m_mapping = mapping;
        m_tableSize = size;
    }
  //  updateFormatForIcon(0, m_text.getLength());
}
#endif

void VcpTextStorage::setPlusCharHandling(VfxBool value)
{
    if (m_plusCharHandling != value)
    {
        m_plusCharHandling = value;

        // need to notify the VcpTextCounter to update counter
        m_signalTextChanged.emit(0, m_text.getLength(), 0, TEXT_CHANGE_INIT);
    }
}
    

const VfxWChar* VcpTextStorage::getText(VcpRichTextFormat **object) 
{
    const VfxWChar* text;
    VfxS32 len;

    getText(&text, 0, 0, &len, object);

    return text;
}


void VcpTextStorage::getText(const VfxWChar **text, VfxS32 *retLen, VcpRichTextFormat **object)
{
    return getText(text, 0, 0, retLen, object);
}


void VcpTextStorage::getText(const VfxWChar **text, VfxS32 len, VfxS32 *retLen, VcpRichTextFormat **object)
{
    return getText(text, 0, len, retLen, object);
}


void VcpTextStorage::getText(
    const VfxWChar **text,
    VfxS32 offset,
    VfxS32 len,
    VfxS32 *retLen,
    VcpRichTextFormat **object)
{
    VfxS32 textLen = m_text.getLength();
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif

    switch (m_textType)
    {
    case TEXT_TYPE_STATIC_STRING:
    case TEXT_TYPE_DYNAMIC_STRING:
        if (offset <= textLen)
        {
            *text = m_text.getBuf() + offset;
            *retLen = (len < (textLen - offset) && (len > 0)) ? len : (textLen - offset);
        }
        else
        {
            *text = NULL;
            *retLen = 0;
        }
        break;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    default:
        *text = m_text.getBuf();
        *retLen = m_text.getLength();
        break;
    }
    if (object)
    {
        *object = m_object;
    }
}


VfxS32 VcpTextStorage::getObjectStart(VfxS32 index)
{
    VcpRichTextFormat *obj = m_object;
    while (obj)
    {
        if ((obj->m_range.getLength() == 0 && obj->m_range.getStart() == index) ||
            (obj->m_range.getStart() <= index) && (index < obj->m_range.getEnd()))
        {
            return obj->m_range.getStart();
        }
        else if (index < obj->m_range.getStart())
        {
            break;
        }
        obj = obj->getNext();   
    }

    // not within object range
    return index;
}


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
    #ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


void VcpTextStorage::sendTextChange(TextChangeEnum type, VfxS32 textLen, VfxS32 offset, VfxS32 charChanged)
{
    VFX_ASSERT((type == TEXT_CHANGE_INSERTED) || (type == TEXT_CHANGE_DELETED));

    if (charChanged)
    {
        // Get affect text range according to new line symbol
        VcpTextUtils tu(m_client);
        VfxS32 start, end;

        // to enhance performance, we update max two previous lines 
        // (worst case for every line, use (mainScreenSize.width / 2 * 2) characters)
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
        VfxS32 maxCharPerLine = mainScreenSize.width / VCP_TEXT_MIN_CHAR_WIDTH;
    
        tu.setText(m_text);
        // TODO: new line symbol should be 0x0A or 0x0D or 0x0D0A
        if (offset - 1 > maxCharPerLine)
        {
            start = tu.lastIndexOf(0x0A, offset - 1 - maxCharPerLine, offset - 1);
        }
        else
        {
            start = tu.lastIndexOf(0x0A, 0, offset - 1);
        }

        if (start <= 0)
        {
            // not find the new line symbol
            if (offset > maxCharPerLine)
            {
                start = offset - maxCharPerLine;
            }
            else
            {
                start = 0;
            }
        }
        else
        {
            // find the new line symbol, update from new line symbol index
            start++;
        }
        // adjust start if start is within the range of format range
        start = getObjectStart(start);

        if (type == TEXT_CHANGE_INSERTED)
        {
            end = tu.indexOf(0x0A, offset + charChanged, textLen);
        }
        else
        {
            end = tu.indexOf(0x0A, offset, textLen);
        }

        if (end == -1)
        {
            // not found the new line symbol
            end = textLen;
        }
        else
        {
            // if end is newline symbol, it should be count into layout range
            end++;
        }

        if (type == TEXT_CHANGE_INSERTED)
        {
            VFX_LOG(VFX_INFO2, VCP_TEXT_STORAGE_INSERT_TEXT, start, end);
        #ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
            updateFormat(start, end, offset, charChanged);
        #endif
            //updateFormatForIcon(start, end);
            m_signalTextChanged.emit(/*start*/offset, end, charChanged, type);
        }
        else
        {
        #ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
            updateFormat(start, end, offset, -charChanged);
        #endif
            //updateFormatForIcon(start, end);
            m_signalTextChanged.emit(/*start*/offset, end, -charChanged, type);
        }
            
    }
}


VfxS32 VcpTextStorage::insertText(VfxU32 offset, const VfxWChar *text, VcpRichTextFormat *object)
{
    VfxWString tmpText;

    tmpText = VFX_WSTR_MEM(text);
    
    return insertText(offset, tmpText, object);
}


VfxS32 VcpTextStorage::insertText(VfxU32 offset, const VfxWString &text, VcpRichTextFormat *object)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TS1", SA_start);
#endif
    VfxS32 orgLen = m_text.getLength();

    VfxS32 retLen = getAvailableLen(text.getBuf(), offset);

    // return if alreay reach max length
    if (retLen <= 0)
    {
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TS1", SA_stop);
    #endif
        return 0;
    }

    // update char count
    VfxU32 ucs2Count = 0;
    VfxU32 gsmExtCount = 0;
    VfxU32 nonAsciiCount = 0;
    getEncodingCount(text.getBuf(), &ucs2Count, &gsmExtCount, &nonAsciiCount, retLen);
    m_ucs2Count += ucs2Count;
    m_gsmExtCount += gsmExtCount;
    m_nonAsciiCount += nonAsciiCount;

    switch (m_textType)
    {
    case TEXT_TYPE_STATIC_STRING:
    case TEXT_TYPE_DYNAMIC_STRING:
        memmove((VfxWChar *)(m_text.getBuf() + offset + retLen), (VfxWChar *)(m_text.getBuf() + offset), sizeof(VfxWChar) * (orgLen - offset + 1));
        memcpy((VfxWChar *)(m_text.getBuf() + offset), (VfxWChar *)(text.getBuf()), sizeof(VfxWChar) * retLen);
        break;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    default:
        break;
    }

    // If text changes, text emit change signal
    sendTextChange(TEXT_CHANGE_INSERTED, orgLen + retLen, offset, retLen);

    // should add format after sendTextChange because sendTextChange will adjsut the format range
    if (object != NULL)
    {
        addFormat(*object, offset);
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TS1", SA_stop);
#endif

    return retLen;
}


VfxS32 VcpTextStorage::deleteText(VfxU32 offset, VfxU32 len)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TS2", SA_start);
#endif
    VfxS32 retLen = 0;
    VfxS32 orgLen = m_text.getLength();
    VfxS32 delEncodingLen = getEncodingLength(m_text.getBuf() + offset, len);

    // update char count
    VfxU32 ucs2Count = 0;
    VfxU32 gsmExtCount = 0;
    VfxU32 nonAsciiCount = 0;
    getEncodingCount(m_text.getBuf() + offset, &ucs2Count, &gsmExtCount, &nonAsciiCount, len);
    m_ucs2Count -= ucs2Count;
    m_gsmExtCount -= gsmExtCount;
    m_nonAsciiCount -= nonAsciiCount;

    if (offset < orgLen)
    {
        VfxS32 restLen = orgLen - offset;
        len = len < (VfxU32)restLen ? len : restLen;
        switch (m_textType)
        {
        case TEXT_TYPE_STATIC_STRING:
        case TEXT_TYPE_DYNAMIC_STRING:
            memmove((VfxWChar *)(m_text.getBuf() + offset), (VfxWChar *)(m_text.getBuf() + offset + len), sizeof(VfxWChar) * (restLen - len + 1));
            retLen = len;
            m_encodingLen -= delEncodingLen;
            break;
     //   case TEXT_TYPE_FILE:
      //      VFX_ASSERT(0);
      //      break;
      //  case TEXT_TYPE_STREAM:
       //     VFX_ASSERT(0);
       //     break;
        default:
            break;
        }
    }

    // If text changes, text emit change signal
    sendTextChange(TEXT_CHANGE_DELETED, orgLen - retLen, offset, retLen);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TS2", SA_stop);
#endif
    return retLen;
}

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
/* under construction !*/
/* under construction !*/
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
    #endif
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


void VcpTextStorage::clear(void)
{
    VfxS32 len = m_text.getLength();

    // delete all text
    VfxWChar *p = (VfxWChar *)m_text.getBuf();
    p[0] = 0;

    // reset encoding count
    m_encodingLen = 0;
    m_ucs2Count = 0;
    m_gsmExtCount = 0;
    m_nonAsciiCount = 0;
#ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
    m_iconCount = 0;
#endif
    if (m_object)
    {
        deleteRichTextFormat(m_object);
        m_object = NULL;
    }

    m_signalTextChanged.emit(0, len, 0, TEXT_CHANGE_DELETED_ALL);
}

void VcpTextStorage::setMaxLength(VfxS32 maxLength)
{
    if (m_maxLen != maxLength)
    {
        m_maxLen = maxLength;

        if (m_textType == TEXT_TYPE_DYNAMIC_STRING)
        {
            // need enlarge the text buffer size
            VfxWChar *newTextBuffer = NULL;
            // leave extra buffer for plus character
            VFX_ALLOC_MEM(newTextBuffer, (m_maxLen + 2) * sizeof(VfxWChar), m_client);
            if (m_textBuffer)
            {
                vfx_sys_wcsncpy((VfxWChar *)newTextBuffer, (VfxWChar *)m_textBuffer, m_maxLen + 1);
            }
            else
            {
                newTextBuffer[0] = 0;
            }

            // free original buffer
            VFX_FREE_MEM(m_textBuffer);
            m_textBuffer = newTextBuffer;
            m_text = VFX_WSTR_STATIC(m_textBuffer);
        }
    }
}


VfxS32 VcpTextStorage::getMaxLength() const
{
    VfxS32 retLen = m_maxLen;

    if (m_encoding == TEXT_ENCODING_ASCII)
    {
        if (m_nonAsciiCount > 0)
        {
            // half length of encoding
            retLen = m_maxLen / 2;
        }
    }
    else if (m_encoding == TEXT_ENCODING_GSM)
    {
        if (m_ucs2Count > 0)
        {
            // half length of encoding
            retLen = UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE((m_maxLen + 1) * 2) / 2 - 1;
        }
    }
    else if (m_encoding == TEXT_ENCODING_0X81)
    {
        VfxU8 temp_0x81 = 0;
        temp_0x81 = srv_phb_convert_to_0x81((VfxU16*)m_text.getBuf(), MMI_FALSE);
        if (0 != temp_0x81)
        {
            retLen =  m_maxLen - 3;
        }
        else
        {
            if (m_ucs2Count > 0)
            {
                // half length of encoding
                retLen = UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE((m_maxLen + 1) * 2) / 2 - 1;
            }
            else
            {
                retLen =  m_maxLen;
            }
        }
    }

    return retLen;
}


VfxS32 VcpTextStorage::getTextEncodingLength() const
{
    VfxS32 retLen = m_encodingLen;

    if (m_encoding == TEXT_ENCODING_0X81)
    {
        VfxU8 temp_0x81 = 0;
        temp_0x81 = srv_phb_convert_to_0x81((VfxU16*)m_text.getBuf(), MMI_FALSE);
        if (0 != temp_0x81)
        {
            retLen = temp_0x81 - 3;
        }
    }
    else if (m_encoding == TEXT_ENCODING_ASCII)
    {
        if (m_nonAsciiCount > 0)
        {
            retLen = m_text.getLength();
        }
    }
    else if (m_encoding == TEXT_ENCODING_GSM)
    {
        if (m_ucs2Count > 0)
        {
            retLen = m_text.getLength();
        }
    }

    // handle plus character, don't count '+'
    if (m_plusCharHandling == VFX_TRUE)
    {
        const VfxWChar *textBuf = m_text.getBuf();
        if (VCP_TEXT_IS_PLUS_CHAR(*textBuf))
        {
            retLen--;
        }
    }

    return retLen;
}


VfxS32 VcpTextStorage::getGBAvailableLen(const VfxWChar *text)
{
    VfxU8 i = 0;
    VfxU8 char_len = 0;

    while (m_encodingLen < m_maxLen)
    {
        char_len = VCP_TEXT_GET_GB_LEN(text[i]);
        if (m_encodingLen + char_len <= m_maxLen)
        {
            m_encodingLen += char_len;
            i++;
        }
        else
        {
            break;
        }
    }
    return i;
}


VfxS32 VcpTextStorage::getGSMAvailableLen(const VfxWChar *text)
{
    VfxU8 i = 0;
    VfxU8 char_len = 0;
    while (m_encodingLen < m_maxLen)
    {
        if (VCP_TEXT_IS_UCS2_CHAR(text[i]))
        {
            VfxS32 maxLen = UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE((m_maxLen + 1) * 2) / 2 - 1;
            VfxS32 textLen = m_text.getLength();
            VfxS32 intLen = vfx_sys_wcslen(text);
            if (textLen + intLen <= maxLen)
            {
                return intLen;
            }
            else
            {
                return maxLen - textLen;
            }
        }
        if (VCP_TEXT_IS_GSM_EXT_CHAR(text[i]))
        {
            char_len = 2;
        }
        else
        {
            char_len = 1;
        }
        if (m_encodingLen + char_len <= m_maxLen)
        {
            m_encodingLen += char_len;
            i++;
        }
        else
        {
            break;
        }
    }
    return i;
}


VfxS32 VcpTextStorage::getUTF8AvailableLen(const VfxWChar *text)
{
    VfxU8 i = 0;
    VfxU8 char_len = 0;

    while (m_encodingLen < m_maxLen)
    {
        VfxWChar checkString[2] = {0};
        checkString[0] = text[i];
        char_len = VCP_TEXT_GET_UTF8_LEN(checkString);

        if (m_encodingLen + char_len <= m_maxLen)
        {
            m_encodingLen += char_len;
            i++;
        }
        else
        {
            break;
        }
    }

    return i;
}


VfxS32 VcpTextStorage::getAvailableLen(const VfxWChar *text, VfxS32 offset)
{
    VfxS32 len = vfx_sys_wcslen(text);
    VfxS32 intEncodingLen = getEncodingLength(text);
    VfxS32 maxLen = m_maxLen;
    VfxS32 encodingLen = m_encodingLen;
    const VfxWChar *textBuf = (VfxWChar *)m_text.getBuf();

    // get char count
    VfxU32 ucs2Count = 0;
    VfxU32 gsmExtCount = 0;
    VfxU32 nonAsciiCount = 0;
    getEncodingCount(text, &ucs2Count, &gsmExtCount, &nonAsciiCount);

    // handle plus character
    if (m_plusCharHandling == VFX_TRUE)
    {
        // +1 if first character is '+' or the insert '+' at first position
        if (VCP_TEXT_IS_PLUS_CHAR(*textBuf) || 
            (VCP_TEXT_IS_PLUS_CHAR(*text) && (offset == 0)))
        {
            maxLen = m_maxLen + 1;
        }
    }

    if (m_encoding == TEXT_ENCODING_ASCII)
    {
        if ((m_nonAsciiCount > 0) || (nonAsciiCount > 0))
        {
            // half length of encoding
            maxLen = maxLen / 2;
            encodingLen = m_text.getLength();
            intEncodingLen = len;
        }
    }

    if (m_encoding == TEXT_ENCODING_GSM)
    {
        if ((m_ucs2Count > 0) || (ucs2Count > 0))
        {
            // half length of encoding
            maxLen = UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE((maxLen + 1) * 2) / 2 - 1;
            encodingLen = m_text.getLength();
            intEncodingLen = len;
        }
    }

    // if editor full
    if (encodingLen >= maxLen)
    {
        return 0;
    }

    // 0x81 handling
    if (m_encoding == TEXT_ENCODING_0X81)
    {
        U32 temp_0x81 = 0;
        if(m_encodingLen < maxLen - 3) // current character count = text lenght /2 - NULL
        {
            if(m_encodingLen > 0) // NULL should use at least 2 bytes
            {
                VfxWChar *tempText;
                VFX_ALLOC_MEM(tempText, (m_text.getLength() + len + 1) * sizeof(VfxWChar), m_client);
                mmi_ucs2cpy((S8 *)tempText, (const S8 *)textBuf);
                mmi_ucs2cat((S8 *)tempText, (const S8 *)text);
                temp_0x81 = srv_phb_convert_to_0x81((VfxU16*)tempText, MMI_FALSE);
                VFX_FREE_MEM(tempText);
            }
        }
        else
        {
            temp_0x81 = srv_phb_convert_to_0x81((VfxU16*)textBuf, MMI_FALSE);
        }

        if ((temp_0x81 != 0) && (m_encodingLen >= maxLen - 3))
        {
            return 0;
        }
        else if (temp_0x81 == 0)
        {
            // can't 0x81, apply GSM rule
            if ((m_ucs2Count > 0) || (ucs2Count > 0))
            {
                // half length of encoding
                maxLen = UI_UCS2_STRING_HALF_LENGTH_MINUS_ONE((maxLen + 1) * 2) / 2 - 1;
                encodingLen = m_text.getLength();
                intEncodingLen = len;
            }
            // if editor full
            if (encodingLen >= maxLen)
            {
                return 0;
            }
        }
    }

    if (encodingLen + intEncodingLen <= maxLen)
    {
        m_encodingLen += intEncodingLen;
        return len;
    }
    else
    {
        VfxS32 leftLen = maxLen - encodingLen;

        switch (m_encoding)
        {
        case TEXT_ENCODING_GB2312:
            len = getGBAvailableLen(text);
            break;
        case TEXT_ENCODING_GSM:
            len = getGSMAvailableLen(text);
            break;
        case TEXT_ENCODING_UTF8:
            len = getUTF8AvailableLen(text);
            break;
        default:
            m_encodingLen += leftLen;
            len = leftLen;
            break;
        }

        return len;
    }
}


void VcpTextStorage::copyFormatObject(VcpRichTextFormat *object)
{
    VcpRichTextFormat *pObject = NULL;
#ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
    m_isMaxIconCount = VFX_FALSE;
#endif

    if (m_object)
    {
        deleteRichTextFormat(m_object);
    #ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
        m_iconCount = 0;
    #endif
        m_object = NULL;
    }

    while (object)
    {
    #ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
        if (object->getType() == VCP_RICH_TEXT_TYPE_IMAGE && object->m_range.getLength() > 0)
        {
            if (m_iconCount >= VCP_TEXT_MAX_ICON_NUM)
            {
                m_isMaxIconCount = VFX_TRUE;
                break;
            }
            else
            {
                m_iconCount++;
            }
        }
    #endif
        VCP_TEXT_FORMAT_ALLOC_NEW(pObject, object->getType(), m_client);
        VCP_TEXT_FORMAT_OBJ_COPY(pObject, object);
        if (m_object)
        {
            m_object->append(pObject);
        }
        else
        {
            m_object = pObject;
        }
        object = object->getNext();
    }
}


void VcpTextStorage::addFormatObject(VcpRichTextFormat *object)
{
    VcpRichTextFormat *pObject = NULL;
#ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
    m_isMaxIconCount = VFX_FALSE;
#endif
    if (object == NULL)
        return;

    if (m_object == NULL)
    {
        copyFormatObject(object);
    }
    else
    {
        // merge with previous object list
        VcpRichTextFormat *orgObject = m_object;
        VcpRichTextFormat *header = NULL;
    #ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
        m_iconCount = 0;
    #endif
        while (object && orgObject)
        {
            if (!(object->m_range.isOutside(orgObject->m_range)))
            {
                //need to check if the format range is overlap
                object = object->getNext();
                continue;
            }
            else if (orgObject->m_range.getStart() < object->m_range.getStart())
            {
                VCP_TEXT_FORMAT_ALLOC_NEW(pObject, orgObject->getType(), m_client);
                VCP_TEXT_FORMAT_OBJ_COPY(pObject, orgObject);
                orgObject = orgObject->getNext();
            }
            else if (orgObject->m_range.getStart() == object->m_range.getStart())
            {
                // the image/custom frame case start == end
                // for example: format1: (0, 0) format2: (0, N), should add format1
                if (orgObject->m_range.getLength() == 0)
                {
                    VCP_TEXT_FORMAT_ALLOC_NEW(pObject, orgObject->getType(), m_client);
                    VCP_TEXT_FORMAT_OBJ_COPY(pObject, orgObject);
                    orgObject = orgObject->getNext();
                }
                else
                {
                    VCP_TEXT_FORMAT_ALLOC_NEW(pObject, object->getType(), m_client);
                    VCP_TEXT_FORMAT_OBJ_COPY(pObject, object);
                    object = object->getNext();
                }
            }
            else
            {
                VCP_TEXT_FORMAT_ALLOC_NEW(pObject, object->getType(), m_client);
                VCP_TEXT_FORMAT_OBJ_COPY(pObject, object);
                object = object->getNext();
            }
        #ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
            if (pObject && pObject->getType() == VCP_RICH_TEXT_TYPE_IMAGE && pObject->m_range.getLength() > 0)
            {
                if (m_iconCount >= VCP_TEXT_MAX_ICON_NUM)
                {
                    m_isMaxIconCount = VFX_TRUE;
                    break;
                }
                else
                {
                    m_iconCount++;
                }
            }
        #endif
            if (header)
            {
                header->append(pObject);
            }
            else
            {
                header = pObject;
            }
        }

        // copy the rest object
        while (object)
        {
        #ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
            if (object->getType() == VCP_RICH_TEXT_TYPE_IMAGE && object->m_range.getLength() > 0)
            {
                if (m_iconCount >= VCP_TEXT_MAX_ICON_NUM)
                {
                    m_isMaxIconCount = VFX_TRUE;
                    break;
                }
                else
                {
                    m_iconCount++;
                }
            }
        #endif
            VCP_TEXT_FORMAT_ALLOC_NEW(pObject, object->getType(), m_client);
            VCP_TEXT_FORMAT_OBJ_COPY(pObject, object);
            if (header)
            {
                header->append(pObject);
            }
            else
            {
                header = pObject;
            }
            object = object->getNext();
        }
        while (orgObject)
        {
        #ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
            if (orgObject->getType() == VCP_RICH_TEXT_TYPE_IMAGE && orgObject->m_range.getLength() > 0)
            {
                if (m_iconCount >= VCP_TEXT_MAX_ICON_NUM)
                {
                    m_isMaxIconCount = VFX_TRUE;
                    break;
                }
                else
                {
                    m_iconCount++;
                }
            }
        #endif
            VCP_TEXT_FORMAT_ALLOC_NEW(pObject, orgObject->getType(), m_client);
            VCP_TEXT_FORMAT_OBJ_COPY(pObject, orgObject);
            if (header)
            {
                header->append(pObject);
            }
            else
            {
                header = pObject;
            }
            orgObject = orgObject->getNext();
        }

        deleteRichTextFormat(m_object);
        m_object = header;
    }
}

#ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
void VcpTextStorage::deleteIconObject(VfxS32 start, VfxS32 end)
{
    if (m_object == NULL)
    {
        return;
    }

    VcpRichTextFormat *pObject = m_object;
    VcpRichTextFormat *preObject = NULL;
    while (pObject)
    {
        if (pObject->getType() == VCP_RICH_TEXT_TYPE_IMAGE &&
            !(pObject->getObjectAttribute() & VCP_RICH_TEXT_OBJ_EMOTION_ICON) &&
            ((pObject->m_range.getEnd() > start && pObject->m_range.getStart() < end) ||
            (pObject->m_range.getStart() < 0))) // invalid object
        {
            VcpRichTextFormat *delObject = pObject;
            pObject = pObject->m_next;
            // delete the object
            if (preObject == NULL)
            {
                m_object = pObject;
            }
            else
            {
                preObject->m_next = pObject;
            }

            VFX_DELETE(delObject);
            m_iconCount--;

            continue;
        }
        else if (pObject->m_range.getStart() > end)
        {
            break;
        }

        preObject = pObject;
        pObject = pObject->m_next;
    }
}


VfxResId VcpTextStorage::getIconIdByText(VfxWChar *text)
{
    if (m_mapping == NULL || m_tableSize == 0)
    {
        return VFX_RES_ID_NULL;
    }

    VfxU32 txtLen = vfx_sys_wcslen((const VfxWChar*)text);
    for (VfxS32 i = 0; i < m_tableSize; i++)
    {
        VfxU8 strLen = vfx_sys_wcslen((const VfxWChar*)(m_mapping[i].text));
        if ((txtLen == strLen) && vfx_sys_wcsncmp((VfxWChar*)(text), (VfxWChar*)m_mapping[i].text, strLen) == 0)
        {
            // find icon
            return m_mapping[i].imageId;
        }
    }

    return VFX_RES_ID_NULL;
}


VcpRichTextFormat *VcpTextStorage::getIconObject(VfxS32 start, VfxS32 end)
{
    if (m_bIcon == VFX_FALSE)
        return NULL;

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TS3", SA_start);
#endif
    VcpRichTextImage* retObj = NULL;
    VcpRichTextImage* obj = NULL;
    VfxS32 offset = start;
    VfxS32 i = 0;
    VfxWChar *pText = (VfxWChar *)m_text.getBuf();
    VfxBool isFind = VFX_FALSE;
    VfxS32 iconCount = 0;

    while (offset < end)
    {
        isFind = VFX_FALSE;
        for (i = 0; i < m_tableSize; i++)
        {
            VfxU8 strLen = vfx_sys_wcslen((const VfxWChar*)(m_mapping[i].text));
            if (vfx_sys_wcsncmp((VfxWChar*)(pText + offset), (VfxWChar*)m_mapping[i].text, strLen) == 0)
            {
                // find icon
                VFX_ALLOC_NEW_EX(obj, VcpRichTextImage, m_client, (m_client));
                obj->setImage(m_mapping[i].imageId);
                obj->m_range.setRange(offset, offset + strLen);

                if (retObj)
                {
                    retObj->append(obj);
                }
                else
                {
                    retObj = obj;
                }
                isFind = VFX_TRUE;
                offset += strLen;
                iconCount++;
                break;
            }
        }

        if (!isFind)
        {
            offset++;
        }

        // stop if reach max icon count
        if (m_iconCount + iconCount >=  VCP_TEXT_MAX_ICON_NUM)
        {
            break;
        }
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TS3", SA_stop);
#endif
    return retObj;
}


void VcpTextStorage::updateFormat(VfxS32 start, VfxS32 end, VfxS32 offset, VfxS32 charChanged)
{
    if ((m_object == NULL) || (charChanged == 0))
        return;

    VcpRichTextFormat *format = m_object;
    VcpRichTextFormat *preFormat = NULL;

    while (format)
    {
        if (format->m_range.getEnd() > offset)
        {
            VfxBool isDel = VFX_FALSE;

            if (format->m_range.getStart() < offset)
            {
                format->m_range.setEnd(format->m_range.getEnd() + charChanged);
                if (format->m_range.getLength() <= 0)
                {
                    isDel = VFX_TRUE;
                }
            }
            else if (charChanged < 0)
            {
                // delete
                if (format->m_range.getStart() < (offset - charChanged))
                {
                    if (format->m_range.getEnd() <= (offset - charChanged))
                    {
                        isDel = VFX_TRUE;
                    }
                    else
                    {
                        format->m_range.setStart(offset);
                        format->m_range.setEnd(format->m_range.getEnd() + charChanged);
                    }
                }
                else
                {
                    format->m_range.shift(charChanged);
                }
            }
            else
            {
                format->m_range.shift(charChanged);
            }

            if (isDel)
            {
                VcpRichTextFormat *delFormat = format;
                format = format->m_next;
                // delete the object
                if (preFormat == NULL)
                {
                    m_object = format;
                }
                else
                {
                    preFormat->m_next = format;
                }

                m_iconCount--;

                VFX_DELETE(delFormat);

                continue;
            }
        }

        preFormat = format;
        format = format->m_next;
    }
}


void VcpTextStorage::updateFormatForIcon(VfxS32 start, VfxS32 end)
{
    if ((m_bIcon == VFX_FALSE) || (m_mapping == NULL) || (m_tableSize == 0) || (start == end))
    {
        return;
    }

    // adjust pos for icon
    VcpRichTextFormat *curObj = getRichTextFormat(start);
    if (curObj && curObj->m_range.getStart() < start && curObj->m_range.getEnd() > start)
    {
        start = curObj->m_range.getStart();
    }

    // delete previous icon object within range
    deleteIconObject(start, end);

    VcpRichTextFormat *iconList = getIconObject(start, end);

    // add to current format
    addFormatObject(iconList);
    deleteRichTextFormat(iconList);
}
#endif

VcpRichTextFormat *VcpTextStorage::getRichTextFormat(VfxS32 offset)
{
    VcpRichTextFormat *obj = m_object;
    while (obj)
    {
        if (((obj->m_range.getStart() <= offset) && (offset < obj->m_range.getEnd())) ||
            ((obj->m_range.getStart() == offset) && (offset == obj->m_range.getEnd())))
        {
            return obj;
        }
        obj = obj->getNext();
    }

    return m_object;
}


VcpRichTextFormat *VcpTextStorage::getRichTextFormat(VfxS32 start, VfxS32 end)
{
    VcpRichTextFormat *obj = m_object;

    // skip the stand alone object which occupy one line
    if (start != end && obj && obj->isOccopyOneLine())
    {
        obj = obj->getNext();
    }
    return getRichTextFormat(obj, start, end);
}


VcpRichTextFormat *VcpTextStorage::getRichTextFormat(VcpRichTextFormat *startObj, VfxS32 start, VfxS32 end)
{
    VcpRichTextFormat* obj = NULL;
    VcpRichTextFormat* retObj = NULL;
    VcpRichTextFormat *head = startObj;

    // no text format object in textstorage
    if (head == NULL)
    {
        return NULL;
    }
    
    // find start format object
    VfxTextRange textRange(start, end);
    while (head && (head->m_range.isOutside(textRange) || (head->m_range.getEnd() < start)))
    {
        if (head->m_range.getStart() == start)
        {
            break;
        }
        head = head->getNext();
    }

    while (head && ((head->m_range.getStart() < end) || (start == end && head->m_range.getStart() == start)))
    {
        VCP_TEXT_FORMAT_ALLOC_NEW(obj, head->getType(), m_client);
        VCP_TEXT_FORMAT_OBJ_COPY(obj, head);

        // update start/end
        obj->m_range.setRange(obj->m_range.getStart() - start, obj->m_range.getEnd() - start);

        if (retObj)
        {
            retObj->append(obj);
        }
        else
        {
            retObj = obj;
        }
        head = head->getNext();
    }

    return retObj;
}


void VcpTextStorage::deleteRichTextFormat(VcpRichTextFormat *object)
{
    VcpRichTextFormat *obj = object;

    // Free rich text format object memory    
    while (obj)
    {
        obj = obj->getNext();
        VFX_DELETE(object);
        object = obj;
    }
}


void* VcpTextStorage::textStorageMalloc(VfxU32 size)
{
    void* p;

	VFX_ALLOC_MEM(p, size, s_owner);

    return p;
}


void VcpTextStorage::textStorageFree(void* p)
{
    VFX_FREE_MEM(p);
}

kal_bool VcpTextStorage::textStorageHiliteCheckStopFunc(applib_addr_type_enum type, applib_address_node_struct *addr, kal_uint32 num)
{
    if (num >= VCP_TEXT_MAX_KEYWORD_NUM)
    {
        return KAL_TRUE;
    }
    return KAL_FALSE;
}

VcpRichText *VcpTextStorage::getKeyword()
{
    if (m_isKeywordDone)
    {
        return NULL;
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TS4", SA_start);
#endif

    VcpRichText* retObj = NULL;
    VcpRichText* obj = NULL;
    VcpRichText* urlObj = NULL;
    VcpRichText* emailObj = NULL;
    VcpRichText* ussdObj = NULL;
    VcpRichText* phoneNumObj = NULL;
    VcpRichText* pUrlObj = NULL;
    VcpRichText* pEmailObj = NULL;
    VcpRichText* pUssdObj = NULL;
    VcpRichText* pPhoneNumObj = NULL;
    VcpRichText* addTempObj = NULL;
    VcpTextKeyWordEnum addType = VCP_TEXT_KEYWORD_NONE;

    // get keyword by type
    if (m_mode & VCP_TEXT_KEYWORD_URL)
    {
        pUrlObj = urlObj = getKeywordByType(VCP_TEXT_KEYWORD_URL);
    }

    if (m_mode & VCP_TEXT_KEYWORD_EMAIL)
    {
        pEmailObj = emailObj = getKeywordByType(VCP_TEXT_KEYWORD_EMAIL);
    }

    if (m_mode & VCP_TEXT_KEYWORD_USSD)
    {
        pUssdObj = ussdObj = getKeywordByType(VCP_TEXT_KEYWORD_USSD);
    }

    if (m_mode & VCP_TEXT_KEYWORD_PHONENUMBER)
    {
        pPhoneNumObj = phoneNumObj = getKeywordByType(VCP_TEXT_KEYWORD_PHONENUMBER);
    }

    VfxS32 offset = m_text.getLength();
    // sort keyword by priority (urlObj > emailObj > ussdObj > phoneNumberObj)
    // and delete redunant keyword which is overlapped
    while (urlObj || emailObj || ussdObj || phoneNumObj)
    {
        offset = m_text.getLength();
        addType = VCP_TEXT_KEYWORD_NONE;

        // get add object by min offset
        if (urlObj && urlObj->m_range.getStart() < offset)
        {
            offset = urlObj->m_range.getStart();
            addType = VCP_TEXT_KEYWORD_URL;
        }
        if (emailObj && emailObj->m_range.getStart() < offset)
        {
            offset = emailObj->m_range.getStart();
            addType = VCP_TEXT_KEYWORD_EMAIL;
        }
        if (ussdObj && ussdObj->m_range.getStart() < offset)
        {
            offset = ussdObj->m_range.getStart();
            addType = VCP_TEXT_KEYWORD_USSD;
        }
        if (phoneNumObj && phoneNumObj->m_range.getStart() < offset)
        {
            offset = phoneNumObj->m_range.getStart();
            addType = VCP_TEXT_KEYWORD_PHONENUMBER;
        }

        // check if the object is overlap by priority
        // Priority: URL > Email > USSD > phonenumber
        // Example: www.123456.com, URL will be saved while phonenumber will be ignored
        if (addType == VCP_TEXT_KEYWORD_URL)
        {
            addTempObj = urlObj;

            // proceed the object if overlap with email object
            while (emailObj && !emailObj->m_range.isOutside(urlObj->m_range))
            {
                emailObj = (VcpRichText *)(emailObj->getNext());
            }
            while (ussdObj && !ussdObj->m_range.isOutside(urlObj->m_range))
            {
                ussdObj = (VcpRichText *)(ussdObj->getNext());
            }
            while (phoneNumObj && !phoneNumObj->m_range.isOutside(urlObj->m_range))
            {
                phoneNumObj = (VcpRichText *)(phoneNumObj->getNext());
            }
            urlObj = (VcpRichText *)(urlObj->getNext());
        }
        else if (addType == VCP_TEXT_KEYWORD_EMAIL)
        {
            if (urlObj && !emailObj->m_range.isOutside(urlObj->m_range))
            {
                //addTempObj = urlObj;
                emailObj = (VcpRichText *)(emailObj->getNext());
                continue;
            }
            else
            {
                addTempObj = emailObj;
                while (ussdObj && !ussdObj->m_range.isOutside(emailObj->m_range))
                {
                    ussdObj = (VcpRichText *)(ussdObj->getNext());
                }
                while (phoneNumObj && !phoneNumObj->m_range.isOutside(emailObj->m_range))
                {
                    phoneNumObj = (VcpRichText *)(phoneNumObj->getNext());
                }
            }
            emailObj = (VcpRichText *)(emailObj->getNext());
        }
        else if (addType == VCP_TEXT_KEYWORD_USSD)
        {
            if (urlObj && !ussdObj->m_range.isOutside(urlObj->m_range))
            {
                //addTempObj = urlObj;
                ussdObj = (VcpRichText *)(ussdObj->getNext());
                continue;
            }
            else if (emailObj && !ussdObj->m_range.isOutside(emailObj->m_range))
            {
                //addTempObj = emailObj;
                ussdObj = (VcpRichText *)(ussdObj->getNext());
                continue;
            }
            else
            {
                addTempObj = ussdObj;
                while (phoneNumObj && !phoneNumObj->m_range.isOutside(ussdObj->m_range))
                {
                    phoneNumObj = (VcpRichText *)(phoneNumObj->getNext());
                }
            }
            ussdObj = (VcpRichText *)(ussdObj->getNext());
        }
        else if (addType == VCP_TEXT_KEYWORD_PHONENUMBER)
        {
            // phonenumber
            if (urlObj && !phoneNumObj->m_range.isOutside(urlObj->m_range))
            {
              //  addTempObj = urlObj;
                phoneNumObj = (VcpRichText *)(phoneNumObj->getNext());
                continue;
            }
            else if (emailObj && !phoneNumObj->m_range.isOutside(emailObj->m_range))
            {
              //  addTempObj = emailObj;
                phoneNumObj = (VcpRichText *)(phoneNumObj->getNext());
                continue;
            }
            else if (ussdObj && !phoneNumObj->m_range.isOutside(ussdObj->m_range))
            {
              //  addTempObj = ussdObj;
                phoneNumObj = (VcpRichText *)(phoneNumObj->getNext());
                continue;
            }
            else
            {
                addTempObj = phoneNumObj;
            }
            phoneNumObj = (VcpRichText *)(phoneNumObj->getNext());
        }
        else
        {
            break;
        }

        // create new text format object to store the keyword
        VFX_ALLOC_NEW(obj, VcpRichText, m_client);

        *obj = *addTempObj;

        if (retObj)
        {
            retObj->append(obj);
        }
        else
        {
            retObj = obj;
        }
    }
    
    // delete temp format object
    deleteRichTextFormat((VcpRichTextFormat*)pUrlObj);
    deleteRichTextFormat((VcpRichTextFormat*)pEmailObj);
    deleteRichTextFormat((VcpRichTextFormat*)pUssdObj);
    deleteRichTextFormat((VcpRichTextFormat*)pPhoneNumObj);

    m_isKeywordDone = VFX_TRUE;

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TS4", SA_stop);
#endif
    return retObj;
}


VcpRichText *VcpTextStorage::getKeywordByType(VcpTextKeyWordEnum type)
{
    applib_address_node_struct *curr_addr_list = NULL;
    kal_bool is_stopped = KAL_FALSE;
    VcpRichText* retObj = NULL;
    VcpRichText* obj = NULL;
    applib_addr_type_enum addrType = APPLIB_ADDR_TYPE_EMAIL;

    switch (type)
    {
    case VCP_TEXT_KEYWORD_EMAIL:
        addrType = APPLIB_ADDR_TYPE_EMAIL;
        break;
    case VCP_TEXT_KEYWORD_URL:
        addrType = APPLIB_ADDR_TYPE_URL;
        break;
    case VCP_TEXT_KEYWORD_PHONENUMBER:
        addrType = APPLIB_ADDR_TYPE_PHONENUMBER;
        break;
    case VCP_TEXT_KEYWORD_USSD:
        addrType = APPLIB_ADDR_TYPE_USSD;
        break;
    default:
        // not support
        VFX_ASSERT(0);
    }

	s_owner = m_client;
    curr_addr_list = applib_get_exclusive_address_list_from_text_ext(
                                        addrType,
                                        VcpTextStorage::textStorageMalloc,
                                        VcpTextStorage::textStorageFree,
                                        VcpTextStorage::textStorageHiliteCheckStopFunc,
                                        APPLIB_INPUT_DATA_TYPE_UNICODE,
                                        (char *)m_text.getBuf(),
                                        m_text.getLength() * sizeof(VfxWChar),
                                        &is_stopped);

    applib_address_node_struct *pNode = curr_addr_list;
    // convert to text format
    while (pNode)
    {
        // create new text format object to store the keyword
        VFX_ALLOC_NEW(obj, VcpRichText, m_client);

    #if defined(__COSMOS_MMI_PACKAGE__)
        VfxFontDesc keywordFont = VFX_FONT_RES(VCP_FNT_TEXT_VIEW_TXT);
    #else
        VfxFontDesc keywordFont;
    #endif
        keywordFont.attr |= VFX_FONT_DESC_ATTR_UNDERLINE;
    #if defined(__COSMOS_MMI_PACKAGE__)
        obj->setTextColor(VFX_COLOR_RES(VCP_COL_TEXT_VIEW_HYPELINK));
    #else
        obj->setTextColor(VRT_COLOR_MAKE(255, 110, 165, 50));
    #endif
        obj->setFont(keywordFont);
        obj->m_range.setRange(pNode->pos / ENCODING_LENGTH, (pNode->pos + pNode->length) / ENCODING_LENGTH);
        obj->m_mode = type;

        if (retObj)
        {
            retObj->append(obj);
        }
        else
        {
            retObj = obj;
        }

        pNode = pNode->next;
    }

    applib_free_address_list((applib_address_node_struct **)&curr_addr_list, textStorageFree);

    return retObj;
}
