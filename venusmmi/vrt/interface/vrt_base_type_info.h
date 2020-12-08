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
 *  vrt_base_list.h
 *
 * Project:
 * --------
 *  Venus Platform
 *
 * Description:
 * ------------
 *  Type Info
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VRT_BASE_TYPE_INFO_H__
#define __VRT_BASE_TYPE_INFO_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/

#ifdef __cplusplus
// For placement new
#include <new>
#endif

#include "vrt_datatype.h"

#ifdef __cplusplus
extern "C"
{
#endif

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

typedef void (*vrt_type_info_init_funcptr_type)(
    void *value_buf,
    const void *other_value);

typedef void (*vrt_type_info_deinit_funcptr_type)(
    void *release_value_buf);

typedef vrt_bool (*vrt_type_info_equal_funcptr_type)(
    const void *value1,
    const void *value2);

typedef vrt_s32 (*vrt_type_info_compare_funcptr_type)(
    const void *value1,
    const void *value2);

typedef struct 
{
    vrt_size value_size;
    vrt_type_info_init_funcptr_type init_callback;
    vrt_type_info_deinit_funcptr_type deinit_callback;
} vrt_type_info_struct;


#ifdef __cplusplus
} /* extern "C" */
#endif


#ifdef __cplusplus

/***************************************************************************** 
 * Template VrtTypeInfo
 *****************************************************************************/

template <class T>
class VrtTypeInfo
{
// Constant value
public:
    enum
    {
        VALUE_SIZE = sizeof(T)
    };

// Static method
public:
    static void init(void *value_buf, const void *other_value);
    static void deinit(void *release_value_buf);
    
    static vrt_bool equal(const void *value1, const void *value2);
    static vrt_s32 compare(const void *value1, const void *value2);

// Static variable
public:
    static const vrt_type_info_struct s_info;
};


/***************************************************************************** 
 * Template VrtTypeInfo Implementation
 *****************************************************************************/

template <class T>
void VrtTypeInfo <T>::init(void *value_buf, const void *other_value)
{
    VRT_DEV_ASSERT(value_buf != NULL);

    if (other_value == NULL)
    {
        new (value_buf) T();
        return;
    }

    const T &valueRef = *(const T *)other_value;
    new (value_buf) T(valueRef);
}


template <class T>
void VrtTypeInfo <T>::deinit(void *release_value_buf)
{
    VRT_DEV_ASSERT(release_value_buf != NULL);
    
    T *valuePtr = (T *)release_value_buf;
    valuePtr->~T();
}


template <class T>
vrt_bool VrtTypeInfo <T>::equal(const void *value1, const void *value2)
{
    VRT_DEV_ASSERT(value1 != NULL);
    VRT_DEV_ASSERT(value2 != NULL);
    
    const T &value1Ref = *(const T *)value1;
    const T &value2Ref = *(const T *)value2;

    return value1Ref == value2Ref ? VRT_TRUE : VRT_FALSE;
}


template <class T>
vrt_s32 VrtTypeInfo <T>::compare(const void *value1, const void *value2)
{
    VRT_DEV_ASSERT(value1 != NULL);
    VRT_DEV_ASSERT(value2 != NULL);
    
    const T &value1Ref = *(const T *)value1;
    const T &value2Ref = *(const T *)value2;

    if (value1Ref == value2Ref)
    {
        return 0;
    }

    if (value1Ref > value2Ref)
    {
        return 1;
    }

    return -1;
}


template <class T>
const vrt_type_info_struct VrtTypeInfo <T>::s_info = 
{
    VrtTypeInfo <T>::VALUE_SIZE,
    VrtTypeInfo <T>::init,
    VrtTypeInfo <T>::deinit
};

#endif /* __cplusplus */

#endif /* __VRT_BASE_TYPE_INFO_H__ */

