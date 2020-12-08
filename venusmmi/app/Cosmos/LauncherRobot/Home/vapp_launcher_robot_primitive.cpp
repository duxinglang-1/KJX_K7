/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vapp_launcher_robot_primitive.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the primitives.
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

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_launcher_robot_primitive.h"
#include "vapp_widget_kit.h"

#include "mmi_rp_vapp_launcher_robot_def.h"

#if defined(__COSMOS_3D_V10__)
#include "vfx_material.h"
#include "vfx_pass.h"
#include "vfx_shader_uniforms.h"
#include "vfx_shader.h"
#endif /* defined(__COSMOS_3D_V10__) */


/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "gdi_primitive.h"
#include "gdi_include.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
}
#endif


/*****************************************************************************
 * Color Material
 *  Based on material for 3D project.
 *
 * Color Filter
 *  Based on VfxFrameFilter for 2D project.
 *****************************************************************************/

#if defined(__COSMOS_3D_V10__)

VFX_IMPLEMENT_CLASS("VappLauncherRobotColorMaterial", VappLauncherRobotColorMaterial, VfxObject);


VappLauncherRobotColorMaterial::VappLauncherRobotColorMaterial() :
    m_material(NULL)
{
    // Do nothing.
}


void VappLauncherRobotColorMaterial::onInit()
{
    VfxObject::onInit();

    VFX_OBJ_CREATE(m_material, VfxMaterial, this);

    //
    // Pass
    //
    VfxPass *pass;

    VFX_OBJ_CREATE(pass, VfxPass, m_material);
    m_material->setPass(0, pass);

    //
    // Shader Programs
    //
    VfxShaderProgram *program;

//    VfxWChar vs[256];
//    VfxWChar fs[256];

//    kal_wsprintf(vs, "%c:\\test\\vapp_launcher_robot_color_filter.vs", SRV_FMGR_PHONE_DRV);
//    kal_wsprintf(fs, "%c:\\test\\vapp_launcher_robot_color_filter.fs", SRV_FMGR_PHONE_DRV);


//    VFX_OBJ_CREATE_EX(
//        program,
//        VfxShaderProgram,
//        pass,
//        (VFX_WSTR_DYNAMIC(vs), VFX_WSTR_DYNAMIC(fs)));

    VFX_OBJ_CREATE_EX(
        program,
        VfxShaderProgram,
        pass,
        (VFX_RES_ID_NULL, VAPP_LAUNCHER_ROBOT_COLOR_FILTER_FS));

    pass->setShaderProgram(program);
}


void VappLauncherRobotColorMaterial::onDeinit()
{
    VfxObject::onInit();
}


VfxMaterial *VappLauncherRobotColorMaterial::get() const
{
    return m_material;
}

#else /* defined(__COSMOS_3D_V10__) */

VFX_IMPLEMENT_CLASS("VappLauncherRobotColorFilter", VappLauncherRobotColorFilter, VfxFrameFilter);


VappLauncherRobotColorFilter::VappLauncherRobotColorFilter() :
    m_minR(0),
    m_minG(0),
    m_minB(0),
    m_rangeR(255),
    m_rangeG(255),
    m_rangeB(255)
{
}


void VappLauncherRobotColorFilter::setColorFilter(
    const VfxColor &colorMin,
    const VfxColor &colorMax)
{
    VFX_ASSERT(colorMax.getR() >= colorMin.getR() &&
               colorMax.getG() >= colorMin.getG() &&
               colorMax.getB() >= colorMin.getB());

    m_minR = colorMin.getR();
    m_minG = colorMin.getG();
    m_minB = colorMin.getB();

    m_rangeR = colorMax.getR() - colorMin.getR();
    m_rangeG = colorMax.getG() - colorMin.getG();
    m_rangeB = colorMax.getB() - colorMin.getB();
}


VfxFrameFilter::BufferModeEnum VappLauncherRobotColorFilter::onGetBufferMode() const
{
    return BUFFER_MODE_OUT_OF_PLACE;
}


VfxBool VappLauncherRobotColorFilter::onProcess(
    VfxU8 *outBuf,
    VfxImageBuffer &inBuf,
    VfxFloat timing)
{
    VfxBool ret = VFX_TRUE;

    switch (inBuf.colorFormat)
    {
        case VRT_COLOR_TYPE_ARGB8888:
            onProcessArgb(outBuf, inBuf, timing);
            break;

        case VRT_COLOR_TYPE_PARGB8888:
            onProcessPargb(outBuf, inBuf, timing);
            break;
            
    #if defined(GDI_LAYER_PARGB6666_FLATTEN_SUPPORT)
        case VRT_COLOR_TYPE_PARGB6666:
            onProcessPargb6666(outBuf, inBuf, timing);
            break;
    #endif
    
        default:
            ret = VFX_FALSE;
            break;
    }

    return ret;
}


void VappLauncherRobotColorFilter::onProcessArgb(
    VfxU8 *outBuf,
    VfxImageBuffer &inBuf,
    VfxFloat timing)
{
    //
    // 0: Blue
    // 1: Green
    // 2: Red
    // 3: Alpha
    //

    VfxU8 *src = inBuf.ptr;
    VfxU8 *dst = outBuf;

    for (VfxS32 y = inBuf.height - 1; y >= 0; y--)
    {
        for (VfxS32 x = inBuf.width - 1; x >= 0; x--)
        {
            dst[3] = src[3];

            if (dst[3] == 0)
            {
                dst[0] = src[0];
                dst[1] = src[1];
                dst[2] = src[2];
            }
            else
            {
                dst[0] = m_minB + ((src[0] * m_rangeB) >> 8);
                dst[1] = m_minG + ((src[1] * m_rangeG) >> 8);
                dst[2] = m_minR + ((src[2] * m_rangeR) >> 8);
            }

            src += 4;
            dst += 4;
        }
    }
}


void VappLauncherRobotColorFilter::onProcessPargb(
    VfxU8 *outBuf,
    VfxImageBuffer &inBuf,
    VfxFloat timing)
{
    //
    // 0: Blue
    // 1: Green
    // 2: Red
    // 3: Alpha
    //

    VfxU8 *src = inBuf.ptr;
    VfxU8 *dst = outBuf;

    for (VfxS32 y = inBuf.height - 1; y >= 0; y--)
    {
        for (VfxS32 x = inBuf.width - 1; x >= 0; x--)
        {
            dst[3] = src[3];

            if (dst[3] == 0)
            {
                dst[0] = src[0];
                dst[1] = src[1];
                dst[2] = src[2];
            }
            else
            {
                dst[0] = ((m_minB * src[3]) + (src[0] * m_rangeB)) >> 8;
                dst[1] = ((m_minG * src[3]) + (src[1] * m_rangeG)) >> 8;
                dst[2] = ((m_minR * src[3]) + (src[2] * m_rangeR)) >> 8;
            }

            src += 4;
            dst += 4;
        }
    }
}

#if defined(GDI_LAYER_PARGB6666_FLATTEN_SUPPORT)
void VappLauncherRobotColorFilter::onProcessPargb6666(
    VfxU8 *outBuf,
    VfxImageBuffer &inBuf,
    VfxFloat timing)
{
    VfxU8 *src = inBuf.ptr;
    VfxU8 *dst = outBuf;

    VfxU32 inPixel;
    VfxU32 outPixel;
    VfxU8 inA, outA;
    VfxU8 inR, outR;
    VfxU8 inG, outG;
    VfxU8 inB, outB;
    
    for(VfxS32 i = 0; i < (inBuf.height * inBuf.width); i++)
    {
        inPixel = GDI_MEM_GET_24(src);
        inA = GDI_A_OF_PARGB6666(inPixel);
        inR = GDI_PR_OF_PARGB6666(inPixel);
        inG = GDI_PG_OF_PARGB6666(inPixel);
        inB = GDI_PB_OF_PARGB6666(inPixel);

        outA = inA;
        outR = ((m_minR * inA) + (inR * m_rangeR)) >> 8;
        outG = ((m_minG * inA) + (inG * m_rangeR)) >> 8;
        outB = ((m_minB * inA) + (inB * m_rangeR)) >> 8;
        outPixel = GDI_PARGB6666(outA, outR, outG, outB);
        GDI_MEM_PUT_24(dst, outPixel);

        src += 3;
        dst += 3;
    }
}
#endif /* defined(GDI_LAYER_PARGB6666_FLATTEN_SUPPORT) */

#endif /* !defined(__COSMOS_3D_V10__)*/


/*****************************************************************************
 * Sorting Utility
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherRobotSort", VappLauncherRobotSort, VfxObject);


VappLauncherRobotSort::VappLauncherRobotSort()
{
    // Do nothing.
}


void VappLauncherRobotSort::sortByName(VappWidgetId **array, VfxS32 size)
{
    VfxWChar **nameArray = createNameArray(array, size);

    quickSort(array, nameArray, 0, size - 1);

    releaseNameArray(nameArray, size);
}


VfxWChar **VappLauncherRobotSort::createNameArray(
    VappWidgetId **array,
    VfxS32 size)
{
    VfxWChar **nameArray;
    VFX_ALLOC_MEM(nameArray, size * sizeof(VfxWChar *), this);

    VappWidgetKit *kit = VFX_OBJ_GET_INSTANCE(VappWidgetKit);

    for (VfxS32 i = 0; i < size; i++)
    {
        VFX_ALLOC_MEM(nameArray[i], sizeof(VfxWChar) * MAX_NAME_SIZE, this);
        kit->getName(*(array[i]), nameArray[i], MAX_NAME_LEN);
    }

    return nameArray;
}


void VappLauncherRobotSort::releaseNameArray(
    VfxWChar **nameArray,
    VfxS32 size)
{
    if (nameArray)
    {
        for (VfxS32 i = 0; i < size; i++)
        {
            VFX_FREE_MEM(nameArray[i]);
        }

        VFX_FREE_MEM(nameArray);
    }
}


void VappLauncherRobotSort::quickSort(
    VappWidgetId **array,
    VfxWChar **nameArray,
    VfxS32 left,
    VfxS32 right)
{
    if (right > left)
    {
        VfxS32 pivotIndex = left + (right - left) / 2;

        pivotIndex = partition(array, nameArray, left, right, pivotIndex);

        quickSort(array, nameArray, left, pivotIndex - 1);
        quickSort(array, nameArray, pivotIndex + 1, right);
    }
}


VfxS32 VappLauncherRobotSort::partition(
    VappWidgetId **array,
    VfxWChar **nameArray,
    VfxS32 left,
    VfxS32 right,
    VfxS32 pivotIndex)
{
    swap(array, nameArray, pivotIndex, right);

    VfxS32 storeIndex = left;

    for (VfxS32 i = left; i < right; i++)
    {
        if (mmi_wcsicmp(nameArray[i], nameArray[right]) < 0)
        {
            swap(array, nameArray, i, storeIndex++);
        }
    }

    swap(array, nameArray, storeIndex, right);

    return storeIndex;
}


void VappLauncherRobotSort::swap(
    VappWidgetId **array,
    VfxWChar **nameArray,
    VfxS32 index1,
    VfxS32 index2)
{
    // Swap widget Id.
    VappWidgetId *tempIdPtr;

    tempIdPtr = array[index1];
    array[index1] = array[index2];
    array[index2] = tempIdPtr;

    // Swap name.
    VfxWChar *tempNamePtr;

    tempNamePtr = nameArray[index1];
    nameArray[index1] = nameArray[index2];
    nameArray[index2] = tempNamePtr;
}

