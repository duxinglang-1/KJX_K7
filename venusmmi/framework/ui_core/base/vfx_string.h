/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vfx_string.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Basic String Type Class
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
 * removed!
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_STRING_H__
#define __VFX_STRING_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VrtBaseString
#include "vrt_base_string.h"
// For primitive types
#include "vfx_datatype.h"
// For VfxBase 
#include "vfx_cpp_base.h"
// For vfx_sys_mem_get_global_allocator()
#include "vfx_sys_mem_config.h"

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
#include "vpi_datatype.h"
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/

// Define a null VfxSting.
#define VFX_STR_NULL                    VfxString()

// EXAMPLE:
// <code>
//  VfxString str(VFX_STR("Hello World"));
// </code> 
#define VFX_STR(str)                    VRT_STR(str)

// EXAMPLE: 
// <code>
//  VfxString str(VFX_STR_BINARY(BIN_ID_HELLO));
// </code> 
#define VFX_STR_BINARY(resId)           VRT_STR_BINARY(resId)

// EXAMPLE: 
// <code>
//  VfxString str(VFX_STR_CONST(constCharStrBuf));
// </code> 
#define VFX_STR_CONST(str)              VRT_STR_CONST(str)


// EXAMPLE: 
// <code>
//  VfxString str(VFX_STR_DYNAMIC(dyamicCharStrBuf));
// </code> 
#define VFX_STR_DYNAMIC(str)            VRT_STR_DYNAMIC(str)


// Define a null VfxWSting.
#define VFX_WSTR_NULL                   VfxWString()
// Define a VfxWSting with empty string (L"").
#define VFX_WSTR_EMPTY                  VfxWString(VfxWStringConstHelper((const VfxWChar *)L""))

/*
 * Define a VfxWString with a constant string.
 *
 * NOTE: Given string must be a constant string
 *
 * EXAMPLE:
 * <code>
 *  str = VFX_WSTR("Hello World!");
 * </code>
 */
#define VFX_WSTR(_str)                  VfxWString(VfxWStringConstHelper((const VfxWChar *)L##_str))

/*
 * Define a VfxWString with a static memory.
 *
 * NOTE: Given string must be a global buffer or a static buffer
 */
#define VFX_WSTR_STATIC(_mem)           VfxWString(VfxWStringConstHelper(_mem))
#define VFX_WSTR_CONST(_mem)            VfxWString(VfxWStringConstHelper(_mem))

/*
 * Define a VfxWString with a resource ID.
 *
 * EXAMPLE:
 * <code>
 *  str = VFX_WSTR_RES(STR_ID_HELLO);
 * </code>
 */
#define VFX_WSTR_RES(_id)               VfxWString((VfxResId)(_id))

/*
 * Define a VfxWString with a dynamic memory.
 */
#define VFX_WSTR_MEM(_mem)              VfxWString(_mem)
#define VFX_WSTR_DYNAMIC(_mem)          VfxWString(_mem)



/***************************************************************************** 
 * Template Class VrtMap
 *****************************************************************************/

class VfxString : 
    public VfxBase,
    public VrtBaseString
{
// Constructor / Destructor        
public:
    // Default constructor
    VfxString() : 
        VrtBaseString(vfx_sys_mem_get_global_allocator())
    {
    }

    // Initialized with const string
    // SEE ALSO: VFX_STR
    VfxString(const VrtStringConstHelper &initializer) :
        VrtBaseString(vfx_sys_mem_get_global_allocator(), initializer)
    {
    }

    // Initialized with binary resource ID
    // SEE ALSO: VFX_STR_BINARY
    VfxString(const VrtStringBinaryResHelper &initializer) :
        VrtBaseString(vfx_sys_mem_get_global_allocator(), initializer)
    {
    }
    
    // Initialized with dynamic resource ID
    // SEE ALSO: VFX_STR_DYNAMIC
    VfxString(const VrtStringDynamicHelper &initializer) :
        VrtBaseString(vfx_sys_mem_get_global_allocator(), initializer)
    {
    }
    
    // Copy constructor
    VfxString(const VfxString &other) :
        VrtBaseString(vfx_sys_mem_get_global_allocator(), other)
    {
    }

private:
    // Disable
    VfxString(vrt_allocator_handle allocator);    
};


/***************************************************************************** 
 * VfxWStringConstHelper
 *****************************************************************************/

/*
 * Internal Used. Use macro VFX_WSTR or VFX_WSTR_STATIC.
 */
class VfxWStringConstHelper : public VfxBase
{
// Constructor / Destructor        
public:
    // Default constructor
    VfxWStringConstHelper(const VfxWChar *str) : 
        m_str(str)
    {
    }

// Method
public:
    const VfxWChar *getString() const
    {
        return m_str;
    }

private:
    const VfxWChar *m_str;
};


/***************************************************************************** 
 * Class VfxWString
 *****************************************************************************/
 
/*
 * VfxWString class represents wide-character strings. 
 *
 * VfxWString can automatically allocate and free string buffers and
 * provides basic string operations, ex: get length, concatenate, etc.
 *
 * The default VfxWString constructor create a null string. 
 * There are serval macros to create string from other source.
 * You should use macro VFX_WSTR to create a VfxWString with a constant string; 
 * or use macro VFX_WSTR_RES to create with a resource ID.
 */
class VfxWString : public VfxBase
{
// Constructor / Destructor        
public:
    // Default constructor
    VfxWString() : m_bufType(BUF_TYPE_NONE)
    {
        m_value.buf = NULL;
    }

    // Initialized with resource ID
    VfxWString(VfxResId resId);

    // Initialized with dynamic string
    VfxWString(const VfxWChar *str);

    // Initialized with const string
    VfxWString(const VfxWStringConstHelper &initializer);

    // Copy constructor
    VfxWString(const VfxWString &other) :
        m_bufType(BUF_TYPE_NONE)
    {
        m_value.buf = NULL;
        assignWith(other);
    }

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    // Initialized with vm_wstring_struct
    VfxWString(const vm_wstring_struct &string);
#endif

    // Destructor
    ~VfxWString()
    {
        clear();
    }

// Operator
public:
    // Get the character at given position index
    // 
    // RETURNS: The character at given position index
    VfxWChar operator [] (VfxS32 index) const
    {
        return getItem(index);
    }

    // Assigned with other string.
    //
    // RETURNS: The buffer of the string
    VfxWString &operator =(const VfxWString &other);

    // Return the string buffer, and type cast to const VfxWChar *
    //
    // RETURNS: The buffer of the string.
    operator const VfxWChar *() const
    {
        return getBuf();
    }
    
    // Compared with another string.
    //
    // RETURNS: Return VFX_TRUE the string is equal to the other.    
    VfxBool operator ==(const VfxWString &other) const
    {
        return compareWith(other) == 0;
    }

    // Compared with another string.
    //
    // RETURNS: Return VFX_TRUE the string is *not* equal to the other.    
    VfxBool operator !=(const VfxWString &other) const
    {
        return compareWith(other) != 0;
    }

    // Append the string with another string.
    //
    // RETURNS: Reference to the string
    VfxWString &operator +=(const VfxWString &other)
    {
        appendWith(other);
        return *this;
    }

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    operator vm_wstring_struct() const;
#endif

// Method
public:
    // Return the buffer of the string
    //
    // RETURNS: The buffer of the string
    const VfxWChar *getBuf() const;
    
    // Get the character at given position index
    // 
    // RETURNS: The character at given position index
    VfxWChar getItem(
        VfxS32 index        // [IN] The position index to get
        ) const
    {
        const VfxWChar *buf = getBuf();
        return buf[index]; 
    }

    VfxResId getResId(void)
    {    
        return m_bufType == BUF_TYPE_RESOURCE?
            m_value.resId : VFX_RES_ID_NULL;
    }

    // Prepare and lock a new string buffer as given length.
    //
    // You must call unlockBuf before calling any other methods.
    // Before unlocking, the buffer can be modified directly.
    //
    // SEE ALSO: unlockBuf
    VfxWChar *lockBuf(
        VfxU32 initialLength // [IN] The initial buffer length, included zero terminal.
        );

    // Unlock the string buffer which be lock by unlockBuf
    //
    // SEE ALSO: lockBuf
    void unlockBuf(); 

    // Return charactor numbers of the string
    //
    // RETURNS: The charactor numbers of the string.
    VfxU32 getLength() const;

    // Determines whether the string is empty
    //
    // RETURNS: Return VFX_TRUE if the string is empty or NULL
    VfxBool isEmpty() const
    {
        const VfxWChar *buf = getBuf();
        
        return buf ? (buf[0] == 0) : VFX_TRUE;
    }

    // Set the string to be empty string
    //
    // RETURNS: Reference to the string
    VfxWString &setEmpty();

    // Determines whether the string is NULL
    //
    // RETURNS: Return VFX_TRUE if the string is NULL
    VfxBool isNull() const
    {
        const VfxWChar *buf = getBuf();
        return buf == NULL;
    }

    // Clear all string data and set the string to be NULL
    //
    // RETURNS: Reference to the string
    VfxWString &setNull()
    {
        clear();
        return *this;
    }

    // Return if the string buffer whatever a dynamic string buffer
    //
    // RETURNS: Return VFX_TRUE if the string buffer is dynamic
    VfxBool isDynamic() const
    {
        return VFX_FLAG_HAS(m_bufType, BUF_TYPE_DYNAMIC);
    }

    // Load string from resource.
    //
    // RETURNS: Reference to the string
    VfxWString &loadFromRes(VfxResId res_id);
    
    // Load string from memory. The string content will be cloned.
    //
    // RETURNS: Reference to the string
    VfxWString &loadFromMem(const VfxWChar *mem);

    // Make string with sprintf like format.
    //
    // RETURNS: Reference to the string
    VfxWString &format(const VfxChar *formatStr, ...);
    
    // Make string with sprintf like format.
    //
    // RETURNS: Reference to the string
    VfxWString &format(const VfxWChar *formatStr, ...);

protected:
    enum BufTypeEnum
    {
        BUF_TYPE_NONE       = 0,
        // The buffer is created from memory pool, need to free
        BUF_TYPE_DYNAMIC    = (1 << 0),
        // The buffer is from resource
        BUF_TYPE_RESOURCE   = (1 << 1),
        // The buffer has been locked
        BUF_TYPE_LOCK       = (1 << 2),
        // End of enum
        BUF_TYPE_END_OF_ENUM
    };

    // Protected constructor
    VfxWString(BufTypeEnum buf_type, const VfxWChar *buf) :
        m_bufType(buf ? buf_type : BUF_TYPE_NONE)
    {
        m_value.buf = buf;
    }

    const VfxWChar *cloneBuf(const VfxWChar *buf);

// Implementation
private:
    BufTypeEnum m_bufType;
    //const VfxWChar *m_buf;
    union
    {
        VfxResId        resId;
        const VfxWChar *buf;
    } m_value;

    // Helper methods
    void clear();
    void assignWith(const VfxWString &ohter);
    void appendWith(const VfxWString &ohter);
    VfxS32 compareWith(const VfxWString &str) const;
};

#endif /* __VFX_STRING_H__ */

