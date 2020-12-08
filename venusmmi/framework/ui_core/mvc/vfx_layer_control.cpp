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
 *  vfx_layer_control.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Layer control
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
#include "vfx_layer_control.h"
#include "vfx_renderer.h"

extern "C"
{
#include "gdi_include.h"

extern void vrt_set_video_layer(vrt_sys_video_layer_index_enum index, gdi_handle layer, vrt_s32 order);
extern vrt_u32 vrt_add_video_layer(gdi_handle layer, vrt_s32 order);
extern gdi_handle vrt_get_blt_layer(void);
}

/***************************************************************************** 
 * class VfxLayerControl
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VfxLayerControl", VfxLayerControl, VfxControl);

VfxLayerControl:: VfxLayerControl() : 
    m_id(INVALID_ID),
    m_order(DEFAULT_ORDER),
    m_layerHandle(GDI_NULL_HANDLE)
{
}

void VfxLayerControl::setHidden(VfxBool value)
{   
    if (getHidden() != value)
    {
        VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();

        VfxControl::setHidden(value);

        updateLayerHandle();
    }
}

void VfxLayerControl::setLayerHandle(VfxU32 layerHandle)
{
    if (m_layerHandle != layerHandle)
    {
        VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();

        m_layerHandle = layerHandle;
        
        updateLayerHandle();
    }
    

    VfxFrame::setLayerHandle(layerHandle);
}

void VfxLayerControl::updateLayerHandle()
{
    if (m_id != INVALID_ID)
    {
        VfxFrame::setLayerHandle(GDI_NULL_HANDLE);
        vrt_set_video_layer((vrt_sys_video_layer_index_enum)m_id, GDI_NULL_HANDLE, (vrt_s32)m_order);
        m_id = INVALID_ID;
    }

    if (getHidden() || m_layerHandle == GDI_NULL_HANDLE || m_order == INVALID_ID)
    {
        return;
    }

    VfxFrame::setLayerHandle(m_layerHandle);
    
    m_id = (VfxU32)vrt_add_video_layer((vrt_u32)m_layerHandle, (vrt_s32)m_order);
}


void VfxLayerControl::setIsOnTop(VfxBool isTop)
{
    if (isTop)
    {
        setOrder(TOPPEST_ORDER);
    }        
}

void VfxLayerControl::setOrder(VfxU32 order)
{     
    if (m_order != order)
    {
        VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();

        m_order = order;

        updateLayerHandle();

        invalidate();
    }
}

void VfxLayerControl::onInit()
{
    VfxControl::onInit();

    // do not cache this frame
    setCacheMode(VFX_CACHE_MODE_PREVENT);
    setBgColor(VFX_COLOR_BLACK);
}

void VfxLayerControl::onDeinit()
{
    setLayerHandle(0);
    
    VfxControl::onDeinit();
}


