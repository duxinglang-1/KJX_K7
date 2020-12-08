/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vfx_asset_src.h
 *
 * Project:
 * --------
 *  Venus UI Core
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VFX_ASSET_SRC_H__
#define __VFX_ASSET_SRC_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_string.h"
#include "vfx_datatype.h"

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

// Asset source type
enum VfxAssetSrcTypeEnum
{
    VFX_ASSET_SRC_TYPE_NULL = 0,        // Null asset
    VFX_ASSET_SRC_TYPE_RES_ID,          // Asset from resource ID
    VFX_ASSET_SRC_TYPE_MEM,             // Asset from memory buffer
    VFX_ASSET_SRC_TYPE_PATH,            // Asset from file path

    VFX_ASSET_SRC_TYPE_END_OF_ENUM
};

/***************************************************************************** 
 * Class VfxAssetSrc
 *****************************************************************************/

/*
 * VfxAssetSrc describes a 3D asset source
 */
class VfxAssetSrc : public VfxBase
{
// Constructor / Destructor
public:
    // Default constructor
    VfxAssetSrc();

    // Construct with a resource ID
    explicit VfxAssetSrc(VfxResId resId);

    // Construct with a memory buffer
    explicit VfxAssetSrc(const VfxU8 *mem);

    // Construct with a path
    explicit VfxAssetSrc(const VfxWString &path);

    // Copy constructor
    VfxAssetSrc(const VfxAssetSrc &other);

    // Destructor
    ~VfxAssetSrc();

// Operator
public:
    // Assigned with another asset source.
    //
    // RETURNS: Reference to the asset source.
    VfxAssetSrc &operator = (const VfxAssetSrc &other);

    // Compared with another asset source.
    //
    // RETURNS: Return VFX_TRUE if the asset source is equal to the other.
    //  Otherwise return VFX_FALSE.
    VfxBool operator == (const VfxAssetSrc &other) const
    {
        return compareWith(other);
    }

    // Compared with another asset source.
    //
    // RETURNS: Return VFX_TRUE if the asset source is *NOT* equal to the other.
    //  Otherwise return VFX_FALSE.
    VfxBool operator != (const VfxAssetSrc &other) const
    {
        return !compareWith(other);
    }

// Method
public:
    // Return the source type of the asset.
    //
    // RETURNS: The source type of the asset.
    VfxAssetSrcTypeEnum getType() const
    {
        return m_type;
    }

    // Check if the asset is a null asset.
    //
    // RETURNS: Return VFX_TRUE if this is a null asset.
    //  Otherwise return VFX_FALSE.
    VfxBool isNull() const
    {
        return m_type == VFX_ASSET_SRC_TYPE_NULL;
    }

    // Set the asset to be a null asset.
    void setNull()
    {
        deinit();
    }

    // Return the resource ID of the asset source.
    //
    // RETURNS: The resource ID of the asset source.
    //  Assert if the asset source type is not VFX_ASSET_SRC_TYPE_RES_ID.
    VfxResId getResId() const
    {
        VFX_ASSERT(m_type == VFX_ASSET_SRC_TYPE_RES_ID);
        return m_type == VFX_ASSET_SRC_TYPE_RES_ID ? m_id : VFX_RES_ID_NULL;
    }

    // Return the memory pointer of the asset source.
    //
    // RETURNS: The memory pointer of the asset source.
    //  Assert if the asset source type is not VFX_ASSET_SRC_TYPE_MEM.
    const VfxU8 *getMem() const
    {
        VFX_ASSERT(m_type == VFX_ASSET_SRC_TYPE_MEM);
        return m_type == VFX_ASSET_SRC_TYPE_MEM ? m_mem : NULL;
    }

    // Return the path of the asset source.
    //
    // RETURNS: The path of the asset source.
    //  Assert if the asset source type is not VFX_ASSET_SRC_TYPE_PATH.
    const VfxWString &getPath() const
    {
        VFX_ASSERT(m_type == VFX_ASSET_SRC_TYPE_PATH);
        return *(VfxWString *)m_pathBuffer;
    }

    // Set the asset source to a given resource ID.
    //
    // NOTE: The type of asset source becomes VFX_ASSET_SRC_TYPE_RES_ID.
    void setResId(
        VfxResId resId
    );

    // Set the asset source to a given memory pointer.
    //
    // NOTE: The type of asset source becomes VFX_ASSET_SRC_TYPE_RES_MEM.
    void setMem(
        const VfxU8 *mem
    );

    // Set the asset source to a given path.
    //
    // NOTE: The type of asset source becomes VFX_ASSET_SRC_TYPE_PATH.
    void setPath(
        const VfxWString &path
    );

// Implementation
private:

    union {
        VfxResId        m_id;
        const VfxU8    *m_mem;
        VfxU8           m_pathBuffer[sizeof(VfxWString)];
    };

    VfxAssetSrcTypeEnum m_type;

    void deinit();

    void assign(VfxResId resId);
    void assign(const VfxU8 *mem);
    void assign(const VfxWString &path);
    void assign(const VfxAssetSrc &other);

    VfxBool compareWith(const VfxAssetSrc &other) const;
};

#endif /* __VFX_ASSET_SRC_H__ */

