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
 *  vapp_npplg_av_video.cpp
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  This file implements NPPlg video frame component.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(OPERA_V10_BROWSER) || defined(__GADGET_SUPPORT__)

#include "MMI_features.h"

#ifdef __MMI_VIDEO_PLAY_SUPPORT__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_npplg_av_video.h"
#include "vapp_widget_view.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "MMIDataType.h"
#include "gdi_include.h"
#include "npplg_av_include.h"

#ifdef __cplusplus
}
#endif



/***************************************************************************** 
 * Class VappNpplgVideoFrame
 *****************************************************************************/
VfxVideoFrame* VappNpplgVideoFrame::m_videoFrame = NULL;
VfxU8 VappNpplgVideoFrame::m_appId = NPPLG_AV_APP_ID_TOTAL;
VfxU32 VappNpplgVideoFrame::m_instanceId = 0;
VfxWeakPtr <VfxVideoFrame> VappNpplgVideoFrame::m_videoFrameWeakPtr = NULL;
VfxS32 VappNpplgVideoFrame::m_vdoX = 0;
VfxS32 VappNpplgVideoFrame::m_vdoY = 0;
VfxS32 VappNpplgVideoFrame::m_vdoW = 0;
VfxS32 VappNpplgVideoFrame::m_vdoH = 0;


void VappNpplgVideoFrame::createVdoFrame(VfxU8 appId, VfxU32 instanceId, VfxS32 x, VfxS32 y, VfxS32 w, VfxS32 h, gdi_color transparent_color)
{
#ifdef __GADGET_SUPPORT__
    if (appId == NPPLG_AV_APP_ID_GOOGLE_GADGET)
    {
        if (m_videoFrame != NULL && m_videoFrameWeakPtr.isValid())
        {
            m_videoFrame->unPrepare();
            VFX_OBJ_CLOSE(m_videoFrame);
            m_appId = NPPLG_AV_APP_ID_TOTAL;
            m_instanceId = 0;
            m_vdoX = 0;
            m_vdoY = 0;
            m_vdoW = 0;
            m_vdoH = 0;
        }

        VfxPage *parentObj = gadget_adp_view_get_parent_object();
        VfxFrame *imgFrame = gadget_adp_view_get_image_frame_ptr();

        if (parentObj != NULL && imgFrame != NULL)
        {
            VFX_OBJ_CREATE(m_videoFrame, VfxVideoFrame, parentObj);
            m_videoFrame->setPos(x, y);
            m_videoFrame->setSize(w, h);
            m_videoFrame->setMultimediaType(VfxVideoFrame::MULTIMEDIA_VIDEO);
            m_videoFrame->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
            m_videoFrame->setBuffer(VAPP_WIDGET_DELEGATOR);
            VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
            VFX_OBJ_GET_INSTANCE(VfxRenderer)->waitForRenderingComplete();
            m_videoFrame->prepare();

            /* Video frame should be inserted before image frame since HW layer should be under OSD layer */
            parentObj->insertChildFrameBefore(imgFrame, m_videoFrame);

            gdi_layer_push_and_set_active(m_videoFrame->getLayerHandle());
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_set_background(transparent_color);
            gdi_layer_pop_and_restore_active();

            m_videoFrameWeakPtr = m_videoFrame;

            m_appId = appId;
            m_instanceId = instanceId;
            m_vdoX = x;
            m_vdoY = y;
            m_vdoW = w;
            m_vdoH = h;
        }
        else
        {
            VFX_ASSERT(0);
        }
    }
    else
#endif /* __GADGET_SUPPORT__ */
    {
        VFX_ASSERT(0);
    }
}

void VappNpplgVideoFrame::freeVdoFrame(VfxU8 appId, VfxU32 instanceId)
{
    if (m_videoFrame != NULL &&
        m_videoFrameWeakPtr.isValid() &&
        m_appId == appId &&
        m_instanceId == instanceId)
    {
        m_videoFrame->unPrepare();
        VFX_OBJ_CLOSE(m_videoFrame);
        m_appId = NPPLG_AV_APP_ID_TOTAL;
        m_instanceId = 0;
        m_vdoX = 0;
        m_vdoY = 0;
        m_vdoW = 0;
        m_vdoH = 0;
    }
}

gdi_handle VappNpplgVideoFrame::getVideoLayerHandle()
{
    if (m_videoFrame == NULL || !m_videoFrameWeakPtr.isValid())
    {
        return GDI_NULL_HANDLE;
    }
    else
    {
        return m_videoFrame->getLayerHandle();
    }
}

VfxU32 VappNpplgVideoFrame::getDisplayLayerFlag()
{
    if (m_videoFrame == NULL || !m_videoFrameWeakPtr.isValid())
    {
        return 0;
    }
    else
    {
        return m_videoFrame->getDisplayLayerFlag();
    }
}

VfxU32 VappNpplgVideoFrame::getHwLayerFlag()
{
    if (m_videoFrame == NULL || !m_videoFrameWeakPtr.isValid())
    {
        return 0;
    }
    else
    {
        return m_videoFrame->getHwLayerFlag();
    }
}

void VappNpplgVideoFrame::updateVdoFrame(VfxU8 appId, VfxU32 instanceId, VfxS32 x, VfxS32 y, VfxS32 w, VfxS32 h, gdi_color transparent_color)
{
    if (m_videoFrame != NULL &&
        m_videoFrameWeakPtr.isValid() &&
        m_appId == appId &&
        m_instanceId == instanceId)
    {
        if (m_vdoW != w || m_vdoH != h)
        {
            m_videoFrame->unPrepare();
            m_videoFrame->setPos(x, y);
            m_videoFrame->setSize(w, h);
            VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
            VFX_OBJ_GET_INSTANCE(VfxRenderer)->waitForRenderingComplete();
            m_videoFrame->prepare();

            gdi_layer_push_and_set_active(m_videoFrame->getLayerHandle());
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_set_background(transparent_color);
            gdi_layer_pop_and_restore_active();
        }
        else
        {
            m_videoFrame->setPos(x, y);
        }

        m_vdoX = x;
        m_vdoY = y;
        m_vdoW = w;
        m_vdoH = h;
    }
}

void VappNpplgVideoFrame::unprepareVdoFrame(VfxU8 appId, VfxU32 instanceId)
{
    if (m_videoFrame != NULL &&
        m_videoFrameWeakPtr.isValid() &&
        m_appId == appId &&
        m_instanceId == instanceId)
    {
        m_videoFrame->unPrepare();
    }
}

void VappNpplgVideoFrame::prepareVdoFrame(VfxU8 appId, VfxU32 instanceId, VfxS32 x, VfxS32 y, VfxS32 w, VfxS32 h, gdi_color transparent_color)
{
    if (m_videoFrame != NULL &&
        m_videoFrameWeakPtr.isValid() &&
        m_appId == appId &&
        m_instanceId == instanceId)
    {
        m_videoFrame->setPos(x, y);
        m_videoFrame->setSize(w, h);
        VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
        VFX_OBJ_GET_INSTANCE(VfxRenderer)->waitForRenderingComplete();
        m_videoFrame->prepare();

        gdi_layer_push_and_set_active(m_videoFrame->getLayerHandle());
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_set_background(transparent_color);
        gdi_layer_pop_and_restore_active();
    }
}


/***************************************************************************** 
 * Export API
 *****************************************************************************/
extern "C" gdi_handle vapp_npplg_av_video_create_vdo_layer(U8 app_id, U32 instance_id, S32 x, S32 y, S32 w, S32 h, gdi_color transparent_color)
{
    VappNpplgVideoFrame::createVdoFrame(app_id, instance_id, x, y, w, h, transparent_color);
    return VappNpplgVideoFrame::getVideoLayerHandle();
}

extern "C" void vapp_npplg_av_video_free_vdo_layer(U8 app_id, U32 instance_id)
{
    VappNpplgVideoFrame::freeVdoFrame(app_id, instance_id);
}

extern "C" U32 vapp_npplg_av_video_get_display_layer_flag(void)
{
    return VappNpplgVideoFrame::getDisplayLayerFlag();
}

extern "C" U32 vapp_npplg_av_video_get_hw_layer_flag(void)
{
    return VappNpplgVideoFrame::getHwLayerFlag();
}

extern "C" void vapp_npplg_av_video_update_vdo_layer(U8 app_id, U32 instance_id, S32 x, S32 y, S32 w, S32 h, gdi_color transparent_color)
{
    VappNpplgVideoFrame::updateVdoFrame(app_id, instance_id, x, y, w, h, transparent_color);
}

extern "C" gdi_handle vapp_npplg_av_video_get_vdo_layer_handle(void)
{
    return VappNpplgVideoFrame::getVideoLayerHandle();
}

extern "C" void vapp_npplg_av_video_unprepare_vdo_layer(U8 app_id, U32 instance_id)
{
    VappNpplgVideoFrame::unprepareVdoFrame(app_id, instance_id);
}

extern "C" void vapp_npplg_av_video_prepare_vdo_layer(U8 app_id, U32 instance_id, S32 x, S32 y, S32 w, S32 h, gdi_color transparent_color)
{
    VappNpplgVideoFrame::prepareVdoFrame(app_id, instance_id, x, y, w, h, transparent_color);
}

#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
#endif /* defined(OPERA_V10_BROWSER) || defined(__GADGET_SUPPORT__) */
