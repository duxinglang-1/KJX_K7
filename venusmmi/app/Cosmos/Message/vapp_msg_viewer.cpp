/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH´Ë
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
 *  vapp_msg_viewer.cpp
 *
 * Project:
 * --------
 *  Venus
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
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_msg_viewer.h"

#ifdef __cplusplus
extern "C"
#endif
{
    #include "MMI_common_app_trc.h"     /* include trace files */
}



VFX_IMPLEMENT_CLASS("VappMsgViewerCp", VappMsgViewerCp, VfxControl);

VappMsgViewerCp::VappMsgViewerCp(VfxU32 type, VfxU32 msgId, VfxU32 msgType):
    m_viewerType(type), 
    m_msgId(msgId), 
    m_msgType(msgType), 
    m_isLoading(VFX_FALSE), 
    m_isContentReady(VFX_FALSE), 
    m_loadingIndicator(NULL)
{
}

void VappMsgViewerCp::setMsgId(VfxU32 msgId)
{
    m_msgId = msgId;

    checkUpdate();
}

void VappMsgViewerCp::setMsgType(VfxU32 msgType)
{
    m_msgType = msgType;

    checkUpdate();
}

VfxU32 VappMsgViewerCp::getTimestamp()
{
    return 0;
}

VfxBool VappMsgViewerCp::isContentReady()
{
    return m_isContentReady;
}

void VappMsgViewerCp::forceUpdate()
{
}

void VappMsgViewerCp::onInit()
{
    VfxControl::onInit();

    VFX_OBJ_CREATE(m_loadingIndicator, VcpActivityIndicator, this);

    /* invalid paramenter, display loading */
    if (m_msgId == 0 || m_msgType == 0)
    {
        showLoading();
    }
}

void VappMsgViewerCp::showLoading()
{
    MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "%s", this->getClassInfo()->getClassName());
    MMI_TRACE(TRACE_GROUP_6, TRC_MMI_VAPP_MSG_VIEWER_SHOW_LOADING_SIZE_CHECK, getSize().width, getSize().height, m_loadingIndicator->getSize().width, m_loadingIndicator->getSize().height, this);
    /* check the size if small than 32x32 */
    if (m_loadingIndicator->getSize().width > getSize().width ||
        m_loadingIndicator->getSize().height > getSize().height)
    {
        /* too small, do not show */
        return;
    }

    m_loadingIndicator->setPos(getSize().width/2 - m_loadingIndicator->getSize().width/2, 
                               getSize().height/2 - m_loadingIndicator->getSize().height/2);
    /* align parent */
    m_loadingIndicator->setAlignParent(
                            VFX_FRAME_ALIGNER_MODE_MID, 
                            VFX_FRAME_ALIGNER_MODE_MID, 
                            VFX_FRAME_ALIGNER_MODE_MID, 
                            VFX_FRAME_ALIGNER_MODE_MID);
    m_loadingIndicator->start();
}

void VappMsgViewerCp::stopLoading()
{
    MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "%s", this->getClassInfo()->getClassName());
    MMI_TRACE(TRACE_GROUP_6, TRC_MMI_VAPP_MSG_VIEWER_STOP_LOADING, this);
    m_loadingIndicator->stop();
}

void VappMsgViewerCp::setContentReady(VfxBool isReady)
{
    MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "%s", this->getClassInfo()->getClassName());
    MMI_TRACE(TRACE_GROUP_6, TRC_MMI_VAPP_MSG_VIEWER_SET_CONTENT_READY, m_msgType, m_msgId, isReady, this);
    m_signalContentReady.postEmit(this, isReady);
    m_isContentReady = isReady;
}
