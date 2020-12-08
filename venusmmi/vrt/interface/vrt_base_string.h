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
 *  vrt_base_string.h
 *
 * Project:
 * --------
 *  Venus Platform
 *
 * Description:
 * ------------
 *  String Type
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VRT_BASE_STRING_H__
#define __VRT_BASE_STRING_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vrt_datatype.h"
// For vrt_allocator_handle
#include "vrt_base_allocator.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

enum VrtStringType
{
    VRT_STRING_TYPE_NULL = 0,
    VRT_STRING_TYPE_RESOURCE,
    VRT_STRING_TYPE_CONST_BUF,
    VRT_STRING_TYPE_DYNAMIC_BUF,
    VRT_STRING_TYPE_LOCK,
    VRT_STRING_TYPE_END_OF_ENUM    
};


#ifdef __cplusplus

// EXAMPLE: 
//  VrtBaseString str(VRT_STR("Hello World"));
#define VRT_STR(str)                    VrtStringConstHelper(str##"")

// EXAMPLE: 
//  VrtBaseString str(VRT_STR_BINARY(BIN_ID_HELLO));
#define VRT_STR_BINARY(resId)           VrtStringBinaryResHelper(resId)

// EXAMPLE: 
//  VrtBaseString str(VRT_STR_CONST(constCharStrBuf));
#define VRT_STR_CONST(str)              VrtStringConstHelper(str)

// EXAMPLE: 
//  VrtBaseString str(VRT_STR_DYNAMIC(dyamicCharStrBuf));
#define VRT_STR_DYNAMIC(str)            VrtStringDynamicHelper(str)

// EXAMPLE: 
//  VrtBaseWString str(VRT_WSTR("Hello World"));
#define VRT_WSTR(str)                   VrtWStringConstHelper((const vrt_wchar *)L##str)

// EXAMPLE: 
//  VrtBaseWString str(VRT_WSTR_RES(STR_ID_HELLO));
#define VRT_WSTR_RES(resId)             VrtWStringResHelper(resId)

// EXAMPLE: 
//  VrtBaseWString str(VRT_WSTR_CONST(constWCharStrBuf));
#define VRT_WSTR_CONST(str)             VrtWStringConstHelper(str)

// EXAMPLE: 
//  VrtBaseWString str(VRT_WSTR_DYNAMIC(dyamicCharStrBuf));
#define VRT_WSTR_DYNAMIC(str)           VrtWStringDynamicHelper(str)

#endif /* __cplusplus */


/***************************************************************************** 
 * Global function
 *****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

extern const vrt_wchar *vrt_res_get_string(vrt_res_id res_id); 
extern const vrt_u8 *vrt_res_get_binary(vrt_res_id res_id, vrt_u32 *size); 

extern vrt_size vrt_strlen(const vrt_char *str); 
extern vrt_s32 vrt_strcmp(const vrt_char *str1, const vrt_char *str2); 
extern vrt_s32 vrt_strncmp(const vrt_char *str1, const vrt_char *str2, vrt_size n); 
extern vrt_char *vrt_strcpy(vrt_char *dest, const vrt_char *src); 
extern vrt_char *vrt_strncpy(vrt_char *dest, const vrt_char *src, vrt_size n); 

extern vrt_size vrt_wcslen(const vrt_wchar *str);
extern vrt_s32 vrt_wcscmp(const vrt_wchar *str1, const vrt_wchar *str2); 
extern vrt_s32 vrt_wcsncmp(const vrt_wchar *str1, const vrt_wchar *str2, vrt_size n); 
extern vrt_wchar *vrt_wcscpy(vrt_wchar *dest, const vrt_wchar *src); 
extern vrt_wchar *vrt_wcsncpy(vrt_wchar *dest, const vrt_wchar *src, vrt_size n);

extern vrt_size vrt_mbstowcs(vrt_wchar *wcstr, const vrt_char *mbstr, vrt_size max);

extern vrt_u32 vrt_str_hash(const vrt_char *str);
extern vrt_u32 vrt_wstr_hash(const vrt_wchar *str);
extern vrt_u16 mmi_asc_n_to_ucs2(vrt_char *pOutBuffer, vrt_char *pInBuffer, vrt_u32 len);


#ifdef __cplusplus
} /* extern "C" */
#endif


#ifdef __cplusplus

/***************************************************************************** 
 * Class VrtStringConstHelper
 *****************************************************************************/

// Internal used
class VrtStringConstHelper
{
// Constructor / Destructor        
public:
    VrtStringConstHelper(const vrt_char *str) : 
        m_str(str)
    {
    }

// Method
public:
    const vrt_char *getString() const
    {
        return m_str;
    }

// Implementation
private:
    const vrt_char *m_str;
};


/***************************************************************************** 
 * Class VrtStringBinaryResHelper
 *****************************************************************************/

// Internal used
class VrtStringBinaryResHelper
{
// Constructor / Destructor        
public:
    VrtStringBinaryResHelper(vrt_res_id resId) : 
        m_resId(resId)
    {
    }

// Method
public:
    vrt_res_id getResId() const
    {
        return m_resId;
    }

// Implementation
private:
    vrt_res_id m_resId;
};


/***************************************************************************** 
 * Class VrtStringDynamicHelper
 *****************************************************************************/

// Internal used
class VrtStringDynamicHelper
{
// Constructor / Destructor        
public:
    VrtStringDynamicHelper(const vrt_char *str) : 
        m_str(str)
    {
    }

// Method
public:
    const vrt_char *getString() const
    {
        return m_str;
    }

// Implementation
private:
    const vrt_char *m_str;
};


/***************************************************************************** 
 * Class VrtBaseString
 *****************************************************************************/
 
class VrtBaseString
{
// Constructor / Destructor        
public:
    // Default constructor
    VrtBaseString();

    // Constructor with allocator
    explicit VrtBaseString(
        vrt_allocator_handle Allocator
    );
    
    // Initialized with const string
    //  This constructor is for const string temp object, for example:
    //  str == VRT_STR("Hello")
    // SEE ALSO: VRT_STR
    VrtBaseString(
        const VrtStringConstHelper &initializer
    );

    // Initialized with const string
    // SEE ALSO: VRT_STR
    VrtBaseString(
        vrt_allocator_handle allocator, 
        const VrtStringConstHelper &initializer
    );

    // Initialized with binary resource ID
    // SEE ALSO: VRT_STR_BINARY
    VrtBaseString(
        vrt_allocator_handle allocator, 
        const VrtStringBinaryResHelper &initializer
    );
    
    // Initialized with dynamic resource ID
    // SEE ALSO: VRT_STR_DYNAMIC
    VrtBaseString(
        vrt_allocator_handle allocator, 
        const VrtStringDynamicHelper &initializer
    );
    
    // Copy constructor
    VrtBaseString(
        vrt_allocator_handle allocator, 
        const VrtBaseString &other
    );

    // Destructor
    ~VrtBaseString();

// Operator
public:
    vrt_char operator [] (vrt_u32 index) const
    {
        return getItem(index);
    }

    VrtBaseString &operator =(const VrtBaseString &other);
    
    operator const vrt_char *() const
    {
        return getBuf();
    }
    
    bool operator ==(const VrtBaseString &other) const
    {
        return compareWith(other) == 0;
    }
    
    bool operator !=(const VrtBaseString &other) const
    {
        return compareWith(other) != 0;
    }

    bool operator > (const VrtBaseString &other) const
    {
        return compareWith(other) > 0;
    }
    
    bool operator < (const VrtBaseString &other) const
    {
        return compareWith(other) < 0;
    }
    
// Method
public:
    vrt_char getItem(vrt_u32 index) const
    {
        const vrt_char *buf = getBuf();
        return buf[index];
    }

    const vrt_char *getBuf() const;

    vrt_res_id getResId(void)
    {
        return m_type == VRT_STRING_TYPE_RESOURCE ? m_value.resId : VRT_RES_ID_NULL;
    }

    vrt_size getLength() const;

    bool isEmpty() const
    {
        return m_type != VRT_STRING_TYPE_NULL ? (getBuf()[0] == 0) : true;
    }

    bool isNull() const
    {
        return m_type == VRT_STRING_TYPE_NULL;
    }

    bool isDynamic() const
    {
        return m_type == VRT_STRING_TYPE_DYNAMIC_BUF;
    }

    VrtBaseString &setNull();

    VrtBaseString &loadFromBinaryRes(vrt_res_id resId);
    VrtBaseString &loadFromConstBuf(const vrt_char *str);
    VrtBaseString &loadFromDynamicBuf(const vrt_char *str);

    vrt_char *lockBuf(vrt_size initialLength);
    void unlockBuf();

    VrtBaseString &format(const vrt_char *format, ...);

    vrt_u32 hash() const;

// Implementation
private:
    // Disable
    VrtBaseString(const VrtBaseString &other);

    vrt_allocator_handle m_allocator;
    VrtStringType m_type;    

    union
    {
        vrt_res_id      resId;
        const vrt_char  *buf;
    } m_value;

    const vrt_char *cloneBuf(const vrt_char *str);

    void clear();
    void initWithBinaryRes(vrt_res_id resId);
    void initWithConstBuf(const vrt_char *str);
    void initWithDynamicBuf(const vrt_char *str);
    void assignWith(const VrtBaseString &other);
    vrt_s32 compareWith(const VrtBaseString &other) const;
};


/***************************************************************************** 
 * Class VrtWStringConstHelper
 *****************************************************************************/

// Internal used
class VrtWStringConstHelper
{
// Constructor / Destructor        
public:
    VrtWStringConstHelper(const vrt_wchar *str) : 
        m_str(str)
    {
    }

// Method
public:
    const vrt_wchar *getString() const
    {
        return m_str;
    }

// Implementation
private:
    const vrt_wchar *m_str;
};


/***************************************************************************** 
 * Class VrtWStringResHelper
 *****************************************************************************/

// Internal used
class VrtWStringResHelper
{
// Constructor / Destructor        
public:
    VrtWStringResHelper(vrt_res_id resId) : 
        m_resId(resId)
    {
    }

// Method
public:
    vrt_res_id getResId() const
    {
        return m_resId;
    }

// Implementation
private:
    vrt_res_id m_resId;
};


/***************************************************************************** 
 * Class VrtWStringDynamicHelper
 *****************************************************************************/

// Internal used
class VrtWStringDynamicHelper
{
// Constructor / Destructor        
public:
    VrtWStringDynamicHelper(const vrt_wchar *str) : 
        m_str(str)
    {
    }

// Method
public:
    const vrt_wchar *getString() const
    {
        return m_str;
    }

// Implementation
private:
    const vrt_wchar *m_str;
};


/***************************************************************************** 
 * Class VrtBaseWString
 *****************************************************************************/
 
class VrtBaseWString
{
// Constructor / Destructor        
public:
    // Default constructor
    VrtBaseWString();

    // Constructor with allocator
    explicit VrtBaseWString(
        vrt_allocator_handle allocator
    );
    
    //  This constructor is for const string temp object, for example:
    //  str == VRT_WSTR("Hello")
    // SEE ALSO: VRT_WSTR
    VrtBaseWString(
        const VrtWStringConstHelper &initializer
    );

    // Initialized with const string
    // SEE ALSO: VRT_WSTR
    VrtBaseWString(
        vrt_allocator_handle allocator, 
        const VrtWStringConstHelper &initializer
    );

    // Initialized with binary resource ID
    // SEE ALSO: VRT_WSTR_BINARY
    VrtBaseWString(
        vrt_allocator_handle allocator, 
        const VrtWStringResHelper &initializer
    );
    
    // Initialized with dynamic string
    // SEE ALSO: VRT_WSTR_DYNAMIC
    VrtBaseWString(
        vrt_allocator_handle allocator, 
        const VrtWStringDynamicHelper &initializer
    );

    // Copy constructor
    VrtBaseWString(
        vrt_allocator_handle allocator, 
        const VrtBaseWString &other
    );

    // Destructor
    ~VrtBaseWString();

// Operator
public:
    vrt_wchar operator [] (vrt_u32 index) const
    {
        return getItem(index);
    }

    VrtBaseWString &operator =(const VrtBaseWString &other);
    
    operator const vrt_wchar *() const
    {
        return getBuf();
    }
    
    bool operator ==(const VrtBaseWString &other) const
    {
        return compareWith(other) == 0;
    }
    
    bool operator !=(const VrtBaseWString &other) const
    {
        return compareWith(other) != 0;
    }

    bool operator > (const VrtBaseWString &other) const
    {
        return compareWith(other) > 0;
    }
    
    bool operator < (const VrtBaseWString &other) const
    {
        return compareWith(other) < 0;
    }

// Method
public:
    vrt_wchar getItem(vrt_u32 index) const
    {
        const vrt_wchar *buf = getBuf();
        return buf[index];
    }

    const vrt_wchar *getBuf() const;

    vrt_res_id getResId(void)
    {
        return m_type == VRT_STRING_TYPE_RESOURCE ? m_value.resId : VRT_RES_ID_NULL;
    }

    vrt_size getLength() const;

    bool isEmpty() const
    {
        return m_type != VRT_STRING_TYPE_NULL ? (getBuf()[0] == 0) : true;
    }

    bool isNull() const
    {
        return m_type == VRT_STRING_TYPE_NULL;
    }

    bool isDynamic() const
    {
        return m_type == VRT_STRING_TYPE_DYNAMIC_BUF;
    }

    VrtBaseWString &setNull();

    VrtBaseWString &loadFromRes(vrt_res_id resId);
    VrtBaseWString &loadFromConstBuf(const vrt_wchar *str);
    VrtBaseWString &loadFromDynamicBuf(const vrt_wchar *str);

    vrt_wchar *lockBuf(vrt_size initialLength);
    void unlockBuf();

    VrtBaseWString &format(const vrt_char *format, ...);

    vrt_u32 hash() const;

// Implementation
private:
    // Disable
    VrtBaseWString(const VrtBaseWString &other);

    const vrt_wchar *cloneBuf(const vrt_wchar *str);

    void clear();
    void initWithRes(vrt_res_id resId);
    void initWithConstBuf(const vrt_wchar *str);
    void initWithDynamicBuf(const vrt_wchar *str);
    void assignWith(const VrtBaseWString &other);
    vrt_s32 compareWith(const VrtBaseWString &other) const;

    vrt_allocator_handle m_allocator;
    VrtStringType m_type;    
    union
    {
        vrt_res_id          resId;
        const vrt_wchar     *buf;
    } m_value;

};


#endif /* __cplusplus */

#endif /* __VRT_BASE_STRING_H__ */


