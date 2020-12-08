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
 *  vapp_msg_viewer.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef __VAPP_MSG_VIEWER_H__
#define __VAPP_MSG_VIEWER_H__

#include "ui_core\base\vfx_base.h"
#include "ui_core\pme\vfx_pme.h"
#include "vcp_include.h"

 /*****************************************************************************
 * class VcpMsgViewer
 *****************************************************************************/
class VappMsgViewerCp : public VfxControl
{
    VFX_DECLARE_CLASS(VappMsgViewerCp);
    #define VAPP_MSG_VIEWER_MIN_SIZE 32
public:
    enum
    {
        VAPP_MSG_VIEWER_LITE = 1,    /* use for dialog screen */
        VAPP_MSG_VIEWER_FULL         /* use for full viewer screen */
    };

#if defined(__MMI_MAINLCD_320X480__) /* HVGA */
    #define VAPP_MSG_VIEWER_LITE_MAX_HEIGHT 261
#elif defined(__MMI_MAINLCD_480X800__) /* WVGA */
    #define VAPP_MSG_VIEWER_LITE_MAX_HEIGHT 436
#elif defined(__MMI_MAINLCD_240X320__) /* QVGA */
    #define VAPP_MSG_VIEWER_LITE_MAX_HEIGHT 130
#elif defined(__MMI_MAINLCD_240X400__) /* WQVGA */
    #define VAPP_MSG_VIEWER_LITE_MAX_HEIGHT 210
#else
    #define VAPP_MSG_VIEWER_LITE_MAX_HEIGHT 261
#endif /* __MMI_MAINLCD_?X?__ */

// Constructor
public:
    VappMsgViewerCp(VfxU32 type = VAPP_MSG_VIEWER_LITE, VfxU32 msgId = 0, VfxU32 msgType = 0);

// Property
    virtual void setMsgId(VfxU32 msgId);
    virtual void setMsgType(VfxU32 msgType);
    virtual VfxU32 getTimestamp();
    virtual VfxBool isContentReady();
// Method
    virtual void forceUpdate();
// Event
    VfxSignal2 <
        VfxObject*, /* VappMsgViewerCp class */
        VfxBool     /* Readay or Unready */
    > m_signalContentReady;

// Overridable
protected:
    virtual void onInit();
    virtual void showLoading();
    virtual void stopLoading();
    virtual void setContentReady(VfxBool isReady = VFX_TRUE);

// extends arguments
    VfxU8 m_viewerType;
    VfxU32 m_msgId;
    VfxU32 m_msgType;

// Implementation
private:
    VfxBool m_isLoading;
    VfxBool m_isContentReady;
    VcpActivityIndicator *m_loadingIndicator;
};
#endif /* __VAPP_MSG_VIEWER_H__ */
