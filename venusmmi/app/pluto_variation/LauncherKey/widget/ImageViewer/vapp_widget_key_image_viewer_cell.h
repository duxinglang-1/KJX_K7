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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_widget_key_image_viewer_cell.h
 *
 * Project:
 * --------
 *  MAUI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_WIDGET_KEY_IMAGE_VIEWER_CELL_H
#define VAPP_WIDGET_KEY_IMAGE_VIEWER_CELL_H

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_KEY_IMAGE_VIEWER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_widget_key_image_viewer_def.h"
#include "vapp_widget_key_image_viewer_cache.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "MediaCacheSrvGprot.h"

#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * Defines
 *****************************************************************************/

#define CACHE_SRC_TYPE_MEM  (SRV_MEDIACACHE_IMAGE_SOURCE_CACHE)  
#define CACHE_SRC_TYPE_DB   (SRV_MEDIACACHE_IMAGE_SOURCE_CACHE_AND_DATABASE)

/*****************************************************************************
 * VappWidgetKeyImageViewerCell
 *****************************************************************************/

class VappWidgetKeyImageViewerCell : public VfxImageFrame
{

    VFX_DECLARE_CLASS(VappWidgetKeyImageViewerCell);

/*----------------------------------------------------------------*/
/* Functions                                                      */
/*----------------------------------------------------------------*/

public:

    VappWidgetKeyImageViewerCell() :
        m_cacher(NULL),
        m_isImgBufLock(VFX_FALSE),
        m_isNeedRetryOpenImg(VFX_FALSE),
        m_waitingIcon(NULL)
    {

    }

    VappWidgetKeyImageViewerCell(VappWidgetKeyImageViewerCache *cacher) : 
        m_cacher(cacher),
        m_isImgBufLock(VFX_FALSE),
        m_isNeedRetryOpenImg(VFX_FALSE),
        m_waitingIcon(NULL)
    {

    }

public:

    void setId(
        VfxS32 id
    );

    VfxS32 getId();

    void setImageIndex(
        VfxS32 idx
    );

    VfxS32 getImageIndex();

    static void lockImgBufCallback(
        VfxS32 err_group,
        VfxS32 err_code, 
        void *user_data
    );

    void onImageBufferLocked(VfxS32 err_code);

    void onFocus();

    void onUnFocus();

    void setMoveEnable();

    void onMove(
        VfxS32 distance, 
        VfxBool isNeedUpdate
    );

    void onSlideIn(
        VappWidgetKeyImageViewerSwitchTypeEnum type
    );

    void onSlideOut(
        VappWidgetKeyImageViewerSwitchTypeEnum type
    );

    void onSkip(
        VappWidgetKeyImageViewerSwitchTypeEnum type
    );

    void onSlideDone(
        VfxBaseTimeline *timeline, 
        VfxBool isComplete
    );

    void posAnimationHdlr(
    	VfxPoint fromValue, 
    	VfxPoint toValue
    );
    
private:

    void openImage(
        VfxBool isMoving
    );

    void closeImage();

    void showError();

    void showWaiting();

    void closeWaiting();

    void showImageWithMem(
        VfxU8 *mem
    );

protected:

    virtual void onInit();
    
    virtual void onDeinit();

/*----------------------------------------------------------------*/
/* Variables                                                      */
/*----------------------------------------------------------------*/

public:

    VfxPointTimeline *m_timeline;
    VfxSignal0        m_signalMoveDone;
        
private:

    VfxS32          m_id;
    VfxS32          m_imgIdx;
    VfxS32          m_imgWidth;
    VfxS32          m_imgHeight;
    VfxBool         m_isImgBufLock;
    VfxBool         m_isNeedRetryOpenImg;  
    void           *m_pImgBuf;
    VcpWaitingIcon *m_waitingIcon;
    
    VappWidgetKeyImageViewerCache *m_cacher;


};

#endif

#endif

