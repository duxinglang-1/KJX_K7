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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vfx_shader.cpp
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
 * removed!
 *
 * removed!
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

#include "vfx_shader.h"
#include "vfx_system.h"
#include "vrt_3d.h"


/***************************************************************************** 
 * Class VfxShaderProgram
 *****************************************************************************/

#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"

VFX_IMPLEMENT_VIRTUAL_CLASS("ShaderProgram", VfxShaderProgram, VfxObject3D);


VfxShaderProgram::VfxShaderProgram(const VfxChar *vsCode, const VfxChar *fsCode)
: m_vsSrc((VfxU8 *)vsCode)
, m_fsSrc((VfxU8 *)fsCode)
{
}


VfxShaderProgram::VfxShaderProgram(const VfxWString &vsPath, const VfxWString &fsPath)
: m_vsSrc(vsPath)
, m_fsSrc(fsPath)
{
}


VfxShaderProgram::VfxShaderProgram(const VfxResId vsId, const VfxResId fsId)
: m_vsSrc(vsId)
, m_fsSrc(fsId)
{
}


VfxShaderProgram::VfxShaderProgram(const VfxAssetSrc &vsSrc, const VfxAssetSrc &fsSrc)
: m_vsSrc(vsSrc)
, m_fsSrc(fsSrc)
{
}


void VfxShaderProgram::createHandle() const
{

    switch (m_vsSrc.getType())
    {
    case VFX_ASSET_SRC_TYPE_NULL:
        switch (m_fsSrc.getType())
        {
        case VFX_ASSET_SRC_TYPE_NULL:
            m_handle = vrt_create_program_from_code_code(NULL, NULL);
            break;
        case VFX_ASSET_SRC_TYPE_RES_ID:
            m_handle = vrt_create_program_from_code_resource(NULL, m_fsSrc.getResId());
            break;
        case VFX_ASSET_SRC_TYPE_MEM:
            m_handle = vrt_create_program_from_code_code(NULL, (const vrt_char *)m_fsSrc.getMem());
            break;
        case VFX_ASSET_SRC_TYPE_PATH:
            {
                const VfxWString fsPath = m_fsSrc.getPath();
                m_handle = vrt_create_program_from_code_path(NULL, fsPath.getBuf(), fsPath.isDynamic() ? VRT_TRUE : VRT_FALSE);
            }
            break;
        default:
            VFX_DEV_ASSERT(VFX_FALSE);
        }
        break;

    case VFX_ASSET_SRC_TYPE_RES_ID:
        switch (m_fsSrc.getType())
        {
        case VFX_ASSET_SRC_TYPE_NULL:
            m_handle = vrt_create_program_from_resource_code(m_vsSrc.getResId(), NULL);
            break;
        case VFX_ASSET_SRC_TYPE_RES_ID:
            m_handle = vrt_create_program_from_resource_resource(m_vsSrc.getResId(), m_fsSrc.getResId());
            break;
        case VFX_ASSET_SRC_TYPE_MEM:
            m_handle = vrt_create_program_from_resource_code(m_vsSrc.getResId(), (const vrt_char *)m_fsSrc.getMem());
            break;
        case VFX_ASSET_SRC_TYPE_PATH:
            {
                const VfxWString fsPath = m_fsSrc.getPath();
                m_handle = vrt_create_program_from_resource_path(m_vsSrc.getResId(), fsPath.getBuf(), fsPath.isDynamic() ? VRT_TRUE : VRT_FALSE);
            }
            break;
        default:
            VFX_DEV_ASSERT(VFX_FALSE);
        }
        break;

    case VFX_ASSET_SRC_TYPE_MEM:
        switch (m_fsSrc.getType())
        {
        case VFX_ASSET_SRC_TYPE_NULL:
            m_handle = vrt_create_program_from_code_code((const vrt_char *)m_vsSrc.getMem(), NULL);
            break;
        case VFX_ASSET_SRC_TYPE_RES_ID:
            m_handle = vrt_create_program_from_code_resource((const vrt_char *)m_vsSrc.getMem(), m_fsSrc.getResId());
            break;
        case VFX_ASSET_SRC_TYPE_MEM:
            m_handle = vrt_create_program_from_code_code((const vrt_char *)m_vsSrc.getMem(), (const vrt_char *)m_fsSrc.getMem());
            break;
        case VFX_ASSET_SRC_TYPE_PATH:
            {
                const VfxWString fsPath = m_fsSrc.getPath();
                m_handle = vrt_create_program_from_code_path((const vrt_char *)m_vsSrc.getMem(), fsPath.getBuf(), fsPath.isDynamic() ? VRT_TRUE : VRT_FALSE);
            }
            break;
        default:
            VFX_DEV_ASSERT(VFX_FALSE);
        }
        break;

    case VFX_ASSET_SRC_TYPE_PATH:
        switch (m_fsSrc.getType())
        {
        case VFX_ASSET_SRC_TYPE_NULL:
            {
                const VfxWString vsPath = m_vsSrc.getPath();
                m_handle = vrt_create_program_from_path_code(vsPath.getBuf(), vsPath.isDynamic() ? VRT_TRUE : VRT_FALSE, NULL);
            }
            break;
        case VFX_ASSET_SRC_TYPE_RES_ID:
            {
                const VfxWString vsPath = m_vsSrc.getPath();
                m_handle = vrt_create_program_from_path_resource(vsPath.getBuf(), vsPath.isDynamic() ? VRT_TRUE : VRT_FALSE, m_fsSrc.getResId());
            }
            break;
        case VFX_ASSET_SRC_TYPE_MEM:
            {
                const VfxWString vsPath = m_vsSrc.getPath();
                m_handle = vrt_create_program_from_path_code(vsPath.getBuf(), vsPath.isDynamic() ? VRT_TRUE : VRT_FALSE, (const vrt_char *)m_fsSrc.getMem());
            }
            break;
        case VFX_ASSET_SRC_TYPE_PATH:
            {
                const VfxWString vsPath = m_vsSrc.getPath();
                const VfxWString fsPath = m_fsSrc.getPath();
                m_handle = vrt_create_program_from_path_path(vsPath.getBuf(), vsPath.isDynamic() ? VRT_TRUE : VRT_FALSE, fsPath.getBuf(), fsPath.isDynamic() ? VRT_TRUE : VRT_FALSE);
            }
            break;
        default:
            VFX_DEV_ASSERT(VFX_FALSE);
        }
        break;

    default:
        VFX_DEV_ASSERT(VFX_FALSE);
    }

}


const VfxAssetSrc &VfxShaderProgram::getVertexShader() const
{
    return m_vsSrc;
}


const VfxAssetSrc &VfxShaderProgram::getFragmentShader() const
{
    return m_fsSrc;
}



#pragma arm section code, rodata
