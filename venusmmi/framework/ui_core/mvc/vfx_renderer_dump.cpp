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
 *  vfx_renderer_dump.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Venus UI Engine Renderer Debug Dump
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

#include "vfx_renderer.h"

#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_system.h"
#include "vfx_object_list.h"
#include "vrt_datatype.h"
#include "vrt_canvas.h"

#ifdef __VENUS_3D_UI_ENGINE__
#ifdef VFX_TRACE_ENABLE
#include "vfx_node.h"
#include "vfx_group.h"
#include "vfx_mesh.h"
#include "vfx_material.h"
#include "vfx_compositing_mode.h"
#include "vfx_pass.h"
#include "vfx_blender.h"
#include "vfx_polygon_mode.h"
#include "vfx_shader.h"
#include "vfx_asset_src.h"
#include "vfx_shader_uniforms.h"
#include "vfx_texture.h"
#include "vfx_render_buffer.h"
extern "C"
{
#include "Conversions.h"
}
#endif /* VFX_TRACE_ENABLE */
#endif /* __VENUS_3D_UI_ENGINE__ */


/***************************************************************************** 
 * Class VfxRenderer
 *****************************************************************************/

#ifdef __VENUS_3D_UI_ENGINE__
void VfxRenderer::debugDumpNode(const VfxNode *node, VfxU32 level)
{
#ifdef VFX_TRACE_ENABLE

    VFX_OBJ_ASSERT_VALID(node);

    VfxClassInfo *classInfo = node->getClassInfo();
    VfxVector3f trans = node->getTranslation();
    VfxQuaternionf rotatef = node->getRotation();
    VfxVector3f scalef = node->getScale();
    VfxMatrix4f pivotf = node->getPivot();

    for (VfxU32 i = 0; i < level; i++)
    {
        VFX_TRACE(("  "));
    }

    /* dump Node information */
    VFX_TRACE((
            "%s T(%3.2f, %3.2f, %3.2f) R(%3.2f, %3.2f, %3.2f, %3.2f) S(%3.2f, %3.2f, %3.2f) \n", 
            classInfo->getClassName(),
            trans[0],
            trans[1],
            trans[2],
            rotatef.v[0],
            rotatef.v[1],
            rotatef.v[2],
            rotatef.w,
            scalef[0],
            scalef[1],
            scalef[2]));

    /* dump pivot information */
    if (pivotf != VfxMatrix4f())
    {
        for (VfxU32 i = 0; i < level; i++)
        {
            VFX_TRACE(("  "));
        }
        VFX_TRACE(("\t P[ %3.2f, %3.2f, %3.2f, %3.2f, \n", 
                pivotf.col[0][0], pivotf.col[1][0], pivotf.col[2][0], pivotf.col[3][0]));

        for (VfxU32 i = 0; i < level; i++)
        {
            VFX_TRACE(("  "));
        }
        VFX_TRACE(("\t    %3.2f, %3.2f, %3.2f, %3.2f, \n", 
                pivotf.col[0][1], pivotf.col[1][1], pivotf.col[2][1], pivotf.col[3][1]));

        for (VfxU32 i = 0; i < level; i++)
        {
            VFX_TRACE(("  "));
        }
        VFX_TRACE(("\t    %3.2f, %3.2f, %3.2f, %3.2f, \n", 
                pivotf.col[0][2], pivotf.col[1][2], pivotf.col[2][2], pivotf.col[3][2]));

        for (VfxU32 i = 0; i < level; i++)
        {
            VFX_TRACE(("  "));
        }
        VFX_TRACE(("\t    %3.2f, %3.2f, %3.2f, %3.2f ] \n", 
                pivotf.col[0][3], pivotf.col[1][3], pivotf.col[2][3], pivotf.col[3][3]));
    }

    /* dump Mesh information if this node is a Mesh */    
    if (node->isKindOf(VFX_OBJ_CLASS_INFO(VfxMesh)))
    {
        const VfxMesh *mesh = (const VfxMesh *)node;
        debugDumpMesh(mesh, level + 1);
    }

    /* dump child nodes */
    if (node->isKindOf(VFX_OBJ_CLASS_INFO(VfxGroup)))
    {   
        const VfxGroup *group = (const VfxGroup *)node;
        const VfxGroup::NodeList &childnodes = group->getChildren();
        VfxGroup::NodeList::ConstIt itr;
        for (itr = childnodes.begin(); itr != childnodes.end(); ++itr)
        {
            VfxNode *node = itr->get();
            debugDumpNode(node, level + 1);
        }
    }
    
#endif

}


void VfxRenderer::debugDumpMesh(const VfxMesh *mesh, VfxU32 level)
{
#ifdef VFX_TRACE_ENABLE
    VFX_OBJ_ASSERT_VALID(mesh);

    /* unmark following code to dump some mesh information */
    
    /*
    VfxClassInfo *classInfo = mesh->getClassInfo();

    for (VfxU32 i = 0; i < level; i++)
    {
        VFX_TRACE(("  "));
    }

    VFX_TRACE((
        "%s \n", 
        classInfo->getClassName()));
    */

    /* Dump each material of this mesh */
    for (VfxU32 i = 0 ; i < mesh->getSubMeshCount() ; i++)
    {
        const VfxMaterial *mat = mesh->getMaterial(i);
        if (mat != NULL)
        {
            debugDumpMaterial(mat, i, level);
        }
    }
    
#endif
}


void VfxRenderer::debugDumpMaterial(const VfxMaterial *mat, VfxU32 idx, VfxU32 level)
{
#ifdef VFX_TRACE_ENABLE
    VFX_OBJ_ASSERT_VALID(mat);

    /* dump some Material information below */
    
    for (VfxU32 i = 0; i < level; i++)
    {
        VFX_TRACE(("  "));
    }

    VFX_TRACE(("[Material [%d] ] \n", idx));
    
    /* Dump each Pass */
    for(VfxU32 i = 0 ; i < mat->getPassCount() ; i++)
    {
        const VfxPass *pass = mat->getPass(i);
        debugDumpPass(pass, i,level + 1);
    }
    
#endif
}


void VfxRenderer::debugDumpPass(const VfxPass *pass, VfxU32 idx, VfxU32 level)
{
#ifdef VFX_TRACE_ENABLE
    VFX_OBJ_ASSERT_VALID(pass);

    for (VfxU32 i = 0; i < level; i++)
    {
        VFX_TRACE(("  "));
    }

    VFX_TRACE(("[Pass [%d] ] \n", idx));

    /* Dump Compositing Mode */
    VfxCompositingMode *compos = pass->getCompositingMode();
    if (compos != NULL)
    {
        VfxBlender *blender = compos->getBlender();

        if (blender)
        {
            for (VfxU32 i = 0; i < level+1; i++)
            {
                VFX_TRACE(("  "));
            }

            VFX_TRACE(("[CompositingMode] blender=(AE=%d, BC=(%d,%d,%d,%d), CE=%d, DAF=%d, DCF=%d, SAF=%d, SCF=%d) \n",
                blender->getAlphaEquation(),
                blender->getBlendColor().getA(),
                blender->getBlendColor().getR(),
                blender->getBlendColor().getG(),
                blender->getBlendColor().getB(),
                blender->getColorEquation(),
                blender->getDestinationAlphaFactor(),
                blender->getDestinationColorFactor(),
                blender->getSourceAlphaFactor(),
                blender->getSourceColorFactor()));
        }

        /*
        VfxStencil *stencil = compos->getStencil();
        if (stencil)
        {
            for (VfxU32 i = 0; i < level+1; i++)
            {
                VFX_TRACE(("  "));
            }
            // TODO: print
            VFX_TRACE(("CompositingMode stencil \n"));
        }
        */
        
    }

    /* Dump Polygon Mode */
    VfxPolygonMode *poly = pass->getPolygonMode();
    if (poly != NULL)
    {
        for (VfxU32 i = 0; i < level+1; i++)
        {
            VFX_TRACE(("  "));
        }
        VFX_TRACE(("[PolygonMode] culling mode=%d, winding mode=%d) \n",
            poly->getCulling(),
            poly->getWinding()));
    }

    /* Dump Shader Program */
    VfxShaderProgram *shader = pass->getShaderProgram();
    if (shader != NULL)
    {
        const VfxAssetSrc vs = shader->getVertexShader();
        const VfxAssetSrc fs = shader->getFragmentShader();
        
        for (VfxU32 i = 0; i < level+1; i++)
        {
            VFX_TRACE(("  "));
        }
        VFX_TRACE(("[ShaderProgram] "));

        if (vs.isNull())
        {
            VFX_TRACE(("VS=NULL  "));
        }
        else
        {
            VfxAssetSrcTypeEnum srctype = vs.getType();
            if (srctype == VFX_ASSET_SRC_TYPE_RES_ID)
            {
                VFX_TRACE(("VS ResID=%d  ", vs.getResId()));
            }
            else if (srctype == VFX_ASSET_SRC_TYPE_PATH)
            {
                VfxWString vspath = vs.getPath();
                VFX_TRACE(("VS Path=%ls  ", vspath.getBuf()));
            }
            else if (srctype == VFX_ASSET_SRC_TYPE_MEM)
            {
                VFX_TRACE(("VS Mem=%X  ", vs.getMem()));
            }
        }

        if (fs.isNull())
        {
            VFX_TRACE(("FS=NULL  "));
        }
        else
        {
            VfxAssetSrcTypeEnum srctype = fs.getType();
            if (srctype == VFX_ASSET_SRC_TYPE_RES_ID)
            {
                VFX_TRACE(("FS ResID=%d  ", fs.getResId()));
            }
            else if (srctype == VFX_ASSET_SRC_TYPE_PATH)
            {
                VfxWString fspath = fs.getPath();
                VFX_TRACE(("FS Path=%ls  ", fspath.getBuf()));
            }
            else if (srctype == VFX_ASSET_SRC_TYPE_MEM)
            {
                VFX_TRACE(("FS Mem=%X  ", fs.getMem()));
            }
        }

        VFX_TRACE(("\n"));
    }

    /* Dump Shader Uniform */
    const VfxList<VfxWeakPtr<VfxShaderUniforms>> &shaderuniforms = pass->getShaderUniformList();
    VfxList<VfxWeakPtr<VfxShaderUniforms>>::ConstIt itr;
    for (itr = shaderuniforms.begin(); itr != shaderuniforms.end(); ++itr)
    {
        VfxShaderUniforms *su = itr->get();
        if (!su)
        {
            continue;
        }
        
        for (VfxU32 i = 0; i < level+1; i++)
        {
            VFX_TRACE(("  "));
        }
        VFX_TRACE(("[Shader Uniform] "));

        const VfxShaderUniforms::VariableList &variables = su->getVariableList();
        VfxShaderUniforms::VariableList::ConstIt vitr;
        for (vitr = variables.begin(); vitr != variables.end(); ++vitr)
        {
            VfxShaderVariable *var = *vitr;

            /* for each uniform variable, get its name, data type, and data pointer */
            const VfxString &varname = var->getName();
            void *varptr = var->getDataPtr();
            VfxTypeIdEnum dtype = var->getDataType();

            /* print its name */
            VFX_TRACE(("%s=", varname.getBuf()));

            /* print its data value */
            switch(dtype)
            {
                case VFX_TYPE_ID_BOOL:
                {
                    VfxBool* varvalue = reinterpret_cast<VfxBool *>(varptr);
                    if (*varvalue == VFX_TRUE)
                    {
                        VFX_TRACE(("TRUE", *varvalue));
                    }
                    else
                    {
                        VFX_TRACE(("FALSE", *varvalue));
                    }
                    break;
                }
                case VFX_TYPE_ID_FLOAT:
                {
                    VfxFloat* varvalue = reinterpret_cast<VfxFloat *>(varptr);
                    VFX_TRACE(("%3.2f", *varvalue));
                    break;
                }
                case VFX_TYPE_ID_S8:
                {
                    VfxS8* varvalue = reinterpret_cast<VfxS8 *>(varptr);
                    VFX_TRACE(("%d", *varvalue));
                    break;
                }
                case VFX_TYPE_ID_U8:
                {
                    VfxU8* varvalue = reinterpret_cast<VfxU8 *>(varptr);
                    VFX_TRACE(("%d", *varvalue));
                    break;
                }
                case VFX_TYPE_ID_S16:
                {
                    VfxS16* varvalue = reinterpret_cast<VfxS16 *>(varptr);
                    VFX_TRACE(("%d", *varvalue));
                    break;
                }
                case VFX_TYPE_ID_U16:
                {
                    VfxU16* varvalue = reinterpret_cast<VfxU16 *>(varptr);
                    VFX_TRACE(("%d", *varvalue));
                    break;
                }
                case VFX_TYPE_ID_S32:
                {
                    VfxS32* varvalue = reinterpret_cast<VfxS32 *>(varptr);
                    VFX_TRACE(("%d", *varvalue));
                    break;
                }
                case VFX_TYPE_ID_U32:
                {
                    VfxU32* varvalue = reinterpret_cast<VfxU32 *>(varptr);
                    VFX_TRACE(("%d", *varvalue));
                    break;
                }
                case VFX_TYPE_ID_S64:
                {
                    VfxS64* varvalue = reinterpret_cast<VfxS64 *>(varptr);
                    VFX_TRACE(("%d", *varvalue));
                    break;
                }
                case VFX_TYPE_ID_U64:
                {
                    VfxU64* varvalue = reinterpret_cast<VfxU64 *>(varptr);
                    VFX_TRACE(("%d", *varvalue));
                    break;
                }
                case VFX_TYPE_ID_CHAR:
                {
                    VfxChar* varvalue = reinterpret_cast<VfxChar *>(varptr);
                    VFX_TRACE(("%c", *varvalue));
                    break;
                }

                /* 3D type */
                case VFX_TYPE_ID_VEC2:
                {
                    VfxVector2f* varvalue = reinterpret_cast<VfxVector2f *>(varptr);
                    VFX_TRACE(("(%3.2f, %3.2f)", varvalue[0], varvalue[1]));
                    break;
                }
                case VFX_TYPE_ID_VEC3:
                {
                    VfxVector3f* varvalue = reinterpret_cast<VfxVector3f *>(varptr);
                    VFX_TRACE(("(%3.2f, %3.2f, %3.2f)", varvalue[0], varvalue[1], varvalue[2]));
                    break;
                }
                case VFX_TYPE_ID_VEC4:
                {
                    VfxVector4f* varvalue = reinterpret_cast<VfxVector4f *>(varptr);
                    VFX_TRACE(("(%3.2f, %3.2f, %3.2f)", varvalue[0], varvalue[1], varvalue[2], varvalue[3]));
                    break;
                }
                case VFX_TYPE_ID_BVEC2:
                {
                    VfxVector2b* varvalue = reinterpret_cast<VfxVector2b *>(varptr);
                    VFX_TRACE(("(%d, %d)", varvalue[0], varvalue[1]));
                    break;
                }
                case VFX_TYPE_ID_BVEC3:
                {
                    VfxVector3b* varvalue = reinterpret_cast<VfxVector3b *>(varptr);
                    VFX_TRACE(("(%d, %d, %d)", varvalue[0], varvalue[1], varvalue[2]));
                    break;
                }
                case VFX_TYPE_ID_BVEC4:
                {
                    VfxVector4b* varvalue = reinterpret_cast<VfxVector4b *>(varptr);
                    VFX_TRACE(("(%d, %d, %d, %d)", varvalue[0], varvalue[1], varvalue[2], varvalue[3]));
                    break;
                }
                case VFX_TYPE_ID_QUAT:
                {
                    VfxQuaternionf* varvalue = reinterpret_cast<VfxQuaternionf *>(varptr);
                    VFX_TRACE(("(%3.2f, %3.2f, %3.2f, %3.2f)", varvalue->v[0], varvalue->v[1], varvalue->v[2], varvalue->w));
                    break;
                }
                case VFX_TYPE_ID_MAT3:
                {
                    VfxMatrix3f* varvalue = reinterpret_cast<VfxMatrix3f *>(varptr);
                    VFX_TRACE(("(%3.2f, %3.2f, %3.2f, %3.2f, %3.2f, %3.2f, %3.2f, %3.2f, %3.2f)", 
                        varvalue[0], varvalue[1], varvalue[2], 
                        varvalue[3], varvalue[4], varvalue[5],
                        varvalue[6], varvalue[7], varvalue[8]));
                    break;
                }
                case VFX_TYPE_ID_MAT4:
                {
                    VfxMatrix4f* varvalue = reinterpret_cast<VfxMatrix4f *>(varptr);
                    VFX_TRACE(("(%3.2f, %3.2f, %3.2f, %3.2f, %3.2f, %3.2f, %3.2f, %3.2f, %3.2f, %3.2f, %3.2f, %3.2f, %3.2f, %3.2f, %3.2f, %3.2f)", 
                        varvalue[0], varvalue[1], varvalue[2], varvalue[3],
                        varvalue[4], varvalue[5], varvalue[6], varvalue[7],
                        varvalue[8], varvalue[9], varvalue[10], varvalue[11],
                        varvalue[12], varvalue[13], varvalue[14], varvalue[15]));
                    break;
                }
                case VRT_TYPE_ID_SAMPLER:
                {
                    VfxTexture** varvalue = reinterpret_cast<VfxTexture **>(varptr);
                    VfxRenderBuffer *rb = (*varvalue)->getImage();
                    
                    if (rb)
                    {
                        /* if render buffer is Image Base, print Image Base information */
                        if (rb->isKindOf(VFX_OBJ_CLASS_INFO(VfxImageBase)))
                        {
                            /* print the real class name of render buffer */
                            VfxClassInfo *classInfo = rb->getClassInfo();
                            VFX_TRACE(("(renderbuf=%s, ", classInfo->getClassName()));

                            /* print the image source of the render buffer */
                            VfxImageBase *imgbase = VFX_OBJ_DYNAMIC_CAST(rb, VfxImageBase);
                            const VfxImageSrc &imgsrc = imgbase->getImageSrc();
                            VfxImageSrcTypeEnum imgsrctype = imgsrc.getType();

                            if (imgsrctype == VFX_IMAGE_SRC_TYPE_RES_ID)
                            {
                                VFX_TRACE(("ResID=%d)", imgsrc.getResId()));
                            }
                            else if (imgsrctype == VFX_IMAGE_SRC_TYPE_PATH)
                            {
                                VfxWString imgpath = imgsrc.getPath();
                                VFX_TRACE(("Path=%ls)", imgpath.getBuf()));
                            }
                            else if (imgsrctype == VFX_IMAGE_SRC_TYPE_MEM)
                            {
                                VFX_TRACE(("Mem=%X)", imgsrc.getMem()));
                            }
                            else
                            {
                                VFX_TRACE(("source type=%d)", imgsrctype));
                            }
                            
                            
                        }
                        else
                        {
                            VFX_TRACE(("(renderbuf!=NULL, not a VfxImageBase)"));
                        }
                    }
                    else
                    {
                        VFX_TRACE(("(renderbuf=NULL)"));
                    }
                    
                    
                    
                    break;
                }
                default:
                    VFX_TRACE(("Type_not_supported_by_debugDumpPass"));
                    break;
            }

            VFX_TRACE((", "));
        }

        VFX_TRACE(("\n"));
    }
#endif
}
#endif


void VfxRenderer::debugDumpFrame(const VfxFrame *frame, VfxU32 level)
{
#ifdef VFX_TRACE_ENABLE
    VFX_OBJ_ASSERT_VALID(frame);

    VfxClassInfo *classInfo = frame->getClassInfo();
    VfxPoint  pos     = frame->getPos();
    VfxRect   bounds  = frame->getBounds();
    VfxBool   hidden  = frame->getHidden();
    
    for (VfxU32 i = 0; i < level; i++)
    {
        VFX_TRACE(("  "));
    }

    VFX_TRACE((
        "%s P(%d, %d) B(%d, %d, %d, %d) %c\n", 
        classInfo->getClassName(),
        pos.x,
        pos.y,
        bounds.origin.x,
        bounds.origin.y,
        bounds.size.width,
        bounds.size.height,
        hidden ? 'H' : 'h'));

#ifdef __VENUS_3D_UI_ENGINE__
    const VfxWorld *world = frame->getWorld();
    if (world)
    {
        debugDumpNode(reinterpret_cast <const VfxNode *>(world), level + 1);
    }
#endif

    const VfxFrame *childFrame;
    for (childFrame = frame->getFirstChildFrame(); 
        childFrame != NULL; 
        childFrame = childFrame->getNextFrame())
    {
        debugDumpFrame(childFrame, level + 1);
    }
#else
    VFX_UNUSED(frame);
    VFX_UNUSED(level);
#endif
}


void VfxRenderer::debugDump() const
{
    if (m_rootFramePtr == NULL)
    {
        // do nothing
        return;
    }
    
    debugDumpFrame(m_rootFramePtr.get(), 0);
}


void VfxRenderer::debugDumpFrameDummy()
{
}

