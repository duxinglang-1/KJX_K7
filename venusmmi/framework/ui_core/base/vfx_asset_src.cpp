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
 *  vrt_asset_src.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_asset_src.h"

/***************************************************************************** 
 * Class VfxAssetSrc
 *****************************************************************************/

VfxAssetSrc::VfxAssetSrc()
    : m_type(VFX_ASSET_SRC_TYPE_NULL)
{
}

VfxAssetSrc::VfxAssetSrc(VfxResId resId)
    : m_type(VFX_ASSET_SRC_TYPE_NULL)
{
    if (resId != 0)
    {
        assign(resId);
    }
}

VfxAssetSrc::VfxAssetSrc(const VfxU8 *mem)
    : m_type(VFX_ASSET_SRC_TYPE_NULL)
{
    if (mem != NULL)
    {
        assign(mem);
    }
}

VfxAssetSrc::VfxAssetSrc(const VfxWString &path)
    : m_type(VFX_ASSET_SRC_TYPE_NULL)
{
    if (!path.isNull())
    {
        assign(path);
    }
}

VfxAssetSrc::VfxAssetSrc(const VfxAssetSrc &other)
    : m_type(VFX_ASSET_SRC_TYPE_NULL)
{
    assign(other);
}

VfxAssetSrc::~VfxAssetSrc()
{
    deinit();
}

VfxAssetSrc &VfxAssetSrc::operator =(const VfxAssetSrc &other)
{
    if (m_type != other.m_type)
    {
        deinit();
    }

    assign(other);
    return *this;
}

void VfxAssetSrc::setResId(VfxResId resId)
{
    if (resId == 0)
    {
        deinit();
        return;
    }

    if (m_type != VFX_ASSET_SRC_TYPE_RES_ID)
    {
        deinit();
    }

    assign(resId);
}


void VfxAssetSrc::setMem(const VfxU8 *mem)
{
    if (mem == NULL)
    {
        deinit();
        return;
    }

    if (m_type != VFX_ASSET_SRC_TYPE_MEM)
    {
        deinit();
    }

    assign(mem);
}


void VfxAssetSrc::setPath(const VfxWString &path)
{
    if (path.isNull())
    {
        deinit();
        return;
    }

    if (m_type != VFX_ASSET_SRC_TYPE_PATH)
    {
        deinit();
    }

    assign(path);
}


void VfxAssetSrc::deinit()
{
    if (m_type == VFX_ASSET_SRC_TYPE_PATH)
    {
        ((VfxWString *)m_pathBuffer)->setNull();
    }
    m_type = VFX_ASSET_SRC_TYPE_NULL;
}


void VfxAssetSrc::assign(VfxResId resId)
{
    VFX_DEV_ASSERT(m_type == VFX_ASSET_SRC_TYPE_NULL || m_type == VFX_ASSET_SRC_TYPE_RES_ID);
    VFX_DEV_ASSERT(resId != 0);

    m_type = VFX_ASSET_SRC_TYPE_RES_ID;
    m_id = resId;
}


void VfxAssetSrc::assign(const VfxU8 *mem)
{
    VFX_DEV_ASSERT(m_type == VFX_ASSET_SRC_TYPE_NULL || m_type == VFX_ASSET_SRC_TYPE_MEM);
    VFX_DEV_ASSERT(mem != NULL);

    m_type = VFX_ASSET_SRC_TYPE_MEM;
    m_mem = mem;
}


void VfxAssetSrc::assign(const VfxWString &path)
{
    VFX_DEV_ASSERT(m_type == VFX_ASSET_SRC_TYPE_NULL || m_type == VFX_ASSET_SRC_TYPE_PATH);
    //VFX_DEV_ASSERT(!path.isNull());

    if (m_type == VFX_ASSET_SRC_TYPE_PATH)
    {
        *(VfxWString *)m_pathBuffer = path;
    }
    else
    {
        m_type = VFX_ASSET_SRC_TYPE_PATH;
        new (m_pathBuffer) VfxWString(path);
    }
}


void VfxAssetSrc::assign(const VfxAssetSrc &other)
{
    VFX_DEV_ASSERT(m_type == VFX_ASSET_SRC_TYPE_NULL || m_type == other.m_type);

    switch (other.m_type)
    {
    case VFX_ASSET_SRC_TYPE_NULL:
        // Do nothing
        break;

    case VFX_ASSET_SRC_TYPE_RES_ID:
        assign(other.m_id);
        break;

    case VFX_ASSET_SRC_TYPE_MEM:
        assign(other.m_mem);
        break;

    case VFX_ASSET_SRC_TYPE_PATH:
        assign(*(VfxWString *)other.m_pathBuffer);
        break;

    default:
        VFX_DEV_ASSERT(VFX_FALSE);
    }
}


VfxBool VfxAssetSrc::compareWith(const VfxAssetSrc &other) const
{
    if (m_type != other.m_type)
    {
        return VFX_FALSE;
    }

    switch (m_type)
    {
    case VFX_ASSET_SRC_TYPE_NULL:
        // Always return true
        return VFX_TRUE;

    case VFX_ASSET_SRC_TYPE_RES_ID:
        return m_id == other.m_id;

    case VFX_ASSET_SRC_TYPE_MEM:
        return m_mem == other.m_mem;

    case VFX_ASSET_SRC_TYPE_PATH:
        return *(VfxWString *)m_pathBuffer == *(VfxWString *)other.m_pathBuffer;

    default:
        VFX_DEV_ASSERT(VFX_FALSE);
    }

    return VFX_FALSE;
}


