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
 *  vapp_hs_cp.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Internal UI componets of home screen application category
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN__

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_control.h"
#include "vfx_basic_type.h"
#include "vfx_cpp_base.h"
#include "vfx_input_event.h"
#include "vfx_signal.h"
#include "vfx_datatype.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_string.h"
#include "vfx_auto_animate.h"
#include "vrt_system.h"
#include "vapp_hs_widget_base.h"
#include "vfx_class_info.h"
#include "vfx_timer.h"
#include "vfx_pen.h"
#include "vrt_datatype.h"
#include "vfx_frame.h"
#include "vfx_primitive_frame.h"
#include "vcp_marquee.h"
#include "vfx_draw_context.h"
#include "vcp_status_icon_bar.h"
#include "vapp_hs_cp.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "gui_typedef.h"
#include "gui_touch_feedback.h"
#include "mmi_rp_app_venus_homescreen_def.h"

#if defined(__MMI_SEARCH_WEB_GOOGLE__)
#include "SearchWebGprot.h"
#endif

#ifdef __cplusplus
}
#endif


/*****************************************************************************
 * Home screen UI componet: drag and drop image
 *****************************************************************************/

VappHsDndImage::VappHsDndImage() :
    m_state(STATE_DROP),
    m_scrollWay(NONE_SCROLL)
{
}


void VappHsDndImage::onInit()
{
    VfxControl::onInit();

    // set anchor point to be center by default
    setAnchor(VfxFPoint(0.5, 0.5));

    // enable auto animation by default
    setAutoAnimate(VFX_TRUE);
}


VfxBool VappHsDndImage::onPenInput(VfxPenEvent &event)
{
    // bypass pen event while it is scrolling
    // if in drag and drop mode, the ret will be true
    VfxBool ret = VFX_FALSE;

    switch (event.type)
    {
        // pen down
        case VFX_PEN_EVENT_TYPE_DOWN:
            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
            m_state = STATE_DRAG;
            m_signalDrag.emit(this, event);
            ret = VFX_TRUE;
            break;

        // pen move
        case VFX_PEN_EVENT_TYPE_MOVE:
            if (m_scrollWay != NONE_SCROLL)
            {
                if (m_state == STATE_DRAG)
                {
                    VfxPoint pos = event.getRelPos(this);
                    VfxRect bounds = getBounds();
                    VfxS32 xdiff = VFX_ABS(event.downPos.x - event.pos.x);
                    VfxS32 ydiff = VFX_ABS(event.downPos.y - event.pos.y);

                    switch (m_scrollWay)
                    {
                        case HORI_SCROLL:
                            if (!containPoint(event.getRelPos(this)))
                            {
                                if ((pos.y < bounds.getMinY()) || (pos.y > bounds.getMaxY()) || (ydiff > (xdiff >> 1)))
                                {
                                    m_state = STATE_MOVE;
                                }
                                else
                                {
                                    m_state = STATE_SCROLL;
                                }
                            }
                            break;

                        case VERT_SCROLL:
                            if (!containPoint(event.getRelPos(this)))
                            {
                                if ((pos.x < bounds.getMinX()) || (pos.x > bounds.getMaxX()) || (xdiff > (ydiff >> 1)))
                                {
                                    m_state = STATE_MOVE;
                                }
                                else
                                {
                                    m_state = STATE_SCROLL;
                                }
                            }
                            break;

                        default:
                            break;
                    };

                    if (m_state == STATE_SCROLL)
                    {
                        // emit abort event for user to do some handling before scrolling
                        m_signalAbort.emit(this, event);
                    }
                    else
                    {
                        // do nothing if pen is still inside the image
                        ret = VFX_TRUE;
                    }
                }
            }
            else
            {
                m_state = STATE_MOVE;
            }

            if (m_state == STATE_MOVE)
            {
                m_signalMove.emit(this, event);
                ret = VFX_TRUE;
            }
            break;

        // pen up
        case VFX_PEN_EVENT_TYPE_UP:
            if (m_state != STATE_SCROLL)
            {
                m_state = STATE_DROP;
                m_signalDrop.emit(this, event);
                ret = VFX_TRUE;
            }
            break;

        default:
            ret = VFX_TRUE;
            break;
    }

    return ret;
}


void VappHsDndImage::setImageId(VfxS32 id)
{
    const VfxImageSrc source = getImgContent();

    if (source.getResId() == VFX_RES_ID_NULL)
    {
        VfxImageSrc image;
        image.setResId(id);

        setImgContent(image);
        setBounds(VfxRect(VFX_POINT_ZERO, image.getSize()));
    }
}


void VappHsDndImage::setImageSrc(const VfxWString &src)
{
    const VfxImageSrc source = getImgContent();
    const VfxWString path = source.getPath();

    if (path.isNull() || path.isEmpty())
    {
        VfxImageSrc image;
        image.setPath(src);

        setImgContent(image);
        setBounds(VfxRect(VFX_POINT_ZERO, image.getSize()));
    }
}


VfxS32 VappHsDndImage::getImageId()
{
    VfxS32 id = -1;

    const VfxImageSrc source = getImgContent();

    if (source.getResId() != VFX_RES_ID_NULL)
    {
        id = source.getResId();
    }

    return id;
}


/*****************************************************************************
 * Home screen UI componet: interactive image array class,
 *                          used for widget bar, shortcut bar / pool
 *****************************************************************************/

VappHsInteractiveImageArray::VappHsInteractiveImageArray() :
    m_isNeedArrange(VFX_FALSE),
    m_count(0),
    m_scrollWay(NONE_SCROLL),
    m_isScroll(0)
{
}


void VappHsInteractiveImageArray::initImage(VfxS32 count, VappHsDndImage **image)
{
    VappHsDndImage **m_dndImage = getImageArray();
    VfxS32 max = getMaxNumber();
    VfxControl *parent = getDndParent();

    // add each image
    for (VfxS32 i = 0 ; i < count ; i ++)
    {
        m_dndImage[i] = image[i];
        parent->addChildFrame(m_dndImage[i]);
        m_count ++;

        if (m_count == max)
        {
            break;
        }
    }

    // arrange all images and fold shortcut pool by default
    arrange(-1);
}


void VappHsInteractiveImageArray::cross(VfxPenEvent &event)
{
    VfxControl *parent = getDndParent();

    // before shuffle images with cross space, arrange all first
    // because image may be removed without arrange before
    if (m_isNeedArrange)
    {
        arrange(-1);
    }

    // located cross index and arrange all with cross space
    arrange(locateIdx(event.getRelPos(parent)));
}


void VappHsInteractiveImageArray::insertImage(VappHsDndImage *image, VfxPenEvent &event)
{
    VappHsDndImage **m_dndImage = getImageArray();
    VfxControl *parent = getDndParent();

    // locate where to insert the new image
    VfxS32 idx = locateIdx(event.getRelPos(parent));
    VfxS32 i;

    // re-order all images
    for (i = m_count ; i > idx ; i --)
    {
        m_dndImage[i] = m_dndImage[i - 1];
    }

    // insert image
    m_dndImage[idx] = image;
    parent->addChildFrame(m_dndImage[idx]);
    m_count ++;

    // arrange all images
    arrange(-1);

    // adjust view to see this image
    VfxRect bounds = parent->getBounds();
    VfxRect rect = image->getRect();
    VfxRect recti, rectj;
    VfxS32 diff = 0, j;

    if (m_scrollWay == VERT_SCROLL)
    {
        // scroll up
        if (rect.getMinY() < bounds.getMinY())
        {
            diff = rect.getMinY() - bounds.getMinY();
        }
        // scroll down
        else if (rect.getMaxY() > bounds.getMaxY())
        {
            // search first visibile icon
            for (i = 0 ; i < m_count ; i ++)
            {
                recti = m_dndImage[i]->getRect();
                if (recti.getMinY() >= bounds.getMinY())
                {
                    break;
                }
            }

            diff = rect.getMaxY() - bounds.getMaxY();

            // search how many icons to skip
            for (j = i + 1 ; j < m_count ; j ++)
            {
                rectj = m_dndImage[j]->getRect();
                if ((rectj.getMinY() - recti.getMinY()) > diff)
                {
                    break;
                }
            }
            diff = rectj.getMinY() - recti.getMinY();
        }
        bounds.origin.y += diff;
    }
    else if (m_scrollWay == HORI_SCROLL)
    {
        // scroll left
        if (rect.getMinX() < bounds.getMinX())
        {
            diff = rect.getMinX() - bounds.getMinX();
        }
        // scroll right
        else if (rect.getMaxX() > bounds.getMaxX())
        {
            // search first visibile icon
            for (i = 0 ; i < m_count ; i ++)
            {
                recti = m_dndImage[i]->getRect();
                if (recti.getMinX() >= bounds.getMinX())
                {
                    break;
                }
            }

            diff = rect.getMaxX() - bounds.getMaxX();

            // search how many icons to skip
            for (j = i + 1 ; j < m_count ; j ++)
            {
                rectj = m_dndImage[j]->getRect();
                if ((rectj.getMinX() - recti.getMinX()) > diff)
                {
                    break;
                }
            }
            diff = rectj.getMinX() - recti.getMinX();
        }
        bounds.origin.x += diff;
    }

    // apply new bounds and re-align
    parent->setBounds(bounds);
    alignment();
}


void VappHsInteractiveImageArray::removeImage(VappHsDndImage *image, VfxBool isArrange)
{
    VappHsDndImage **m_dndImage = getImageArray();
    VfxS32 max = getMaxNumber();

    VfxBool is_find_widget = VFX_FALSE;

    // re-order all images
    for (VfxS32 i = 0 ; i < max ; i ++)
    {
        if (m_dndImage[i] == image)
        {
            m_dndImage[i] = NULL;
            is_find_widget = VFX_TRUE;
        }

        if (is_find_widget && (i < max - 1))
        {
            m_dndImage[i] = m_dndImage[i + 1];
            m_dndImage[i + 1] = NULL;
        }
    }

    // remove image
    if (is_find_widget)
    {
        image->removeFromParentFrame();
        m_count --;
    }

    m_isNeedArrange = VFX_TRUE;

    // arrange all images
    if (isArrange)
    {
        arrange(-1);
    }
}


void VappHsInteractiveImageArray::backupImage(VappHsDndImage *image)
{
    VappHsDndImage **m_dndImage = getImageArray();
    VfxS32 max = getMaxNumber();

    m_oriIdx = -1;
    for (VfxS32 i = 0 ; i < max ; i ++)
    {
        if (m_dndImage[i] == image)
        {
            m_oriIdx = i;
            m_oriPos = image->getPos();
            break;
        }
    }
}


void VappHsInteractiveImageArray::restoreImage(VappHsDndImage *image, VfxBool isBlink, VfxBool isArrange)
{
    if (m_oriIdx != -1)
    {
        VappHsDndImage **m_dndImage = getImageArray();
        VfxControl *parent = getDndParent();

        // re-order all images
        for (VfxS32 i = m_count ; i > m_oriIdx ; i --)
        {
            m_dndImage[i] = m_dndImage[i - 1];
        }

        // reset position and fade out first
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        image->setPos(m_oriPos);

        if (isBlink)
        {
            image->setOpacity(0.0f);
        }
        VfxAutoAnimate::commit();

        // insert image
        m_dndImage[m_oriIdx] = image;
        parent->addChildFrame(m_dndImage[m_oriIdx]);
        m_count ++;

        // arrange all images and fade-in this image
        if (isArrange)
        {
            arrange(-1);
        }

        if (isBlink)
        {
            image->setOpacity(1.0f);
        }

        m_oriIdx = -1;
    }
}


void VappHsInteractiveImageArray::highlightImage(VappHsDndImage *image, VfxBool isHighlight)
{
    // do nothing.
}


VfxBool VappHsInteractiveImageArray::onPenInput(VfxPenEvent &event)
{
    if (m_scrollWay != NONE_SCROLL && m_count > 0)
    {
        switch (event.type)
        {
            case VFX_PEN_EVENT_TYPE_MOVE:
            case VFX_PEN_EVENT_TYPE_UP:
                {
                    VfxPoint prev_pos = (!m_isScroll) ? (event.downPos) : (event.prevPos);

                    m_isScroll = (!m_isScroll) ? (VFX_TRUE) : (m_isScroll);

                    // scroll
                    VappHsDndImage **m_dndImage = getImageArray();
                    VfxControl *parent = getDndParent();
                    VfxRect bounds = parent->getBounds();
                    VfxS32 pos_diff = 0;

                    VfxAutoAnimate::begin();
                    VfxAutoAnimate::setDisable(VFX_TRUE);

                    switch (m_scrollWay)
                    {
                        case HORI_SCROLL:
                            pos_diff = event.pos.x - prev_pos.x;
                            bounds.origin.x -= pos_diff;
                            pos_diff = event.pos.x - event.downPos.x;
                            break;

                        case VERT_SCROLL:
                            pos_diff = event.pos.y - prev_pos.y;
                            bounds.origin.y -= pos_diff;

                            {
                                VfxS32 d = bounds.getMaxY() - m_dndImage[m_count - 1]->getRect().getMaxY();

                                bounds.origin.y -= (d > 0) ? (d) : (0);

                                if (bounds.getMinY() < 0)
                                {
                                    bounds.origin.y = 0;
                                }
                            }

                            pos_diff = event.pos.y - event.downPos.y;
                            break;

                        default:
                            break;
                    }

                    parent->setBounds(bounds);

                    VfxAutoAnimate::commit();

                    VfxAutoAnimate::begin();
                    if (event.type == VFX_PEN_EVENT_TYPE_UP)
                    {
                        // free run
                        VfxMsec diff_msec = vrt_sys_get_time() - event.downTimeStamp;
                        VfxS32 max_scroll = getMaxScrollValue();

                        if ((diff_msec > 0) && (diff_msec < SCROLL_TIME))
                        {
                            VfxAutoAnimate::setDuration(FRRUN_TIME);
                            VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);

                            pos_diff = (pos_diff < -max_scroll) ? (-max_scroll) : (pos_diff);
                            pos_diff = (pos_diff > max_scroll) ? (max_scroll) : (pos_diff);

                            switch (m_scrollWay)
                            {
                                case HORI_SCROLL:
                                    bounds.origin.x -= pos_diff * FRRUN_SPEED / diff_msec;
                                    if (bounds.origin.x < m_dndImage[0]->getPos().x)
                                    {
                                        bounds.origin.x = m_dndImage[0]->getPos().x;
                                    }
                                    if (bounds.origin.x > m_dndImage[m_count - 1]->getPos().x)
                                    {
                                        bounds.origin.x = m_dndImage[m_count - 1]->getPos().x;
                                    }
                                    break;

                                case VERT_SCROLL:
                                    bounds.origin.y -= pos_diff * FRRUN_SPEED / diff_msec;
                                    if (bounds.origin.y < m_dndImage[0]->getPos().y)
                                    {
                                        bounds.origin.y = m_dndImage[0]->getPos().y;
                                    }
                                    if (bounds.origin.y > m_dndImage[m_count - 1]->getPos().y)
                                    {
                                        bounds.origin.y = m_dndImage[m_count - 1]->getPos().y;
                                    }
                                    break;

                                default:
                                    break;
                            }

                            parent->setBounds(bounds);
                        }
                        alignment();
                        m_isScroll = VFX_FALSE;
                    }
                    VfxAutoAnimate::commit();
                }
                break;

            default:
                break;
        }
    }

    return VFX_TRUE;
}


/*****************************************************************************
 * Home screen UI componet: base widget class
 *****************************************************************************/

VFX_IMPLEMENT_VIRTUAL_CLASS("Widget", VappHsWidget, VfxControl);


VappHsWidget::VappHsWidget() :
    m_controlIcon(NULL),
    m_state(STATE_INIT),
    m_isForceFreeDrag(VFX_FALSE),
    m_desktop(NULL),
    m_childCount(0),
    m_timerDrag(NULL),
    m_isPenDown(VFX_FALSE),
    m_isFreeDrag(VFX_FALSE)
{
}


void VappHsWidget::onInit()
{
    VfxControl::onInit();

    // enable auto animation by default
    setAutoAnimate(VFX_TRUE);
}


void VappHsWidget::onDeinit()
{
    // before leaving, release all content of the widget
    releaseView();

    VfxControl::onDeinit();
}


VfxBool VappHsWidget::createIconView()
{
    VFX_OBJ_CREATE(m_controlIcon, VfxControl, this);
    VfxBool ret = onCreateIconView();

    if (ret)
    {
        return VFX_TRUE;
    }
    else
    {
        VFX_OBJ_CLOSE(m_controlIcon);
        return VFX_FALSE;
    }
}


VfxBool VappHsWidget::onPreviewPenInput(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        setDesktopTop();
    }

    return VFX_FALSE;
}


void VappHsWidget::onTimerDrag(VfxTimer *timer)
{
    VFX_UNUSED(timer);

    gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_HOLD);

    // fake pen event
    VfxPen *pen = VFX_OBJ_GET_INSTANCE(VfxPen);
    VfxPenEvent event;

    event.type = VFX_PEN_EVENT_TYPE_DOWN;
    event.timeStamp = pen->getDownTimeStamp();
    event.prevTimeStamp = pen->getDownTimeStamp();
    event.downTimeStamp = pen->getDownTimeStamp();
    event.pos = pen->getDownPos();
    event.prevPos = pen->getDownPos();
    event.downPos = pen->getDownPos();

    m_signalDrag.emit(this, event);

    m_isPenDown = VFX_TRUE;
}


VfxBool VappHsWidget::onPenInput(VfxPenEvent &event)
{
    // bypass pen event to desktop if necessary, but this event is still captured by widget
    VfxControl* parent = VFX_OBJ_DYNAMIC_CAST(getParentControl(), VappHsDesktop);

    // dispatch event directly
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);

#if FREEDRAGANDDROP
            m_signalDrag.emit(this, event);
#else /* FREEDRAGANDDROP */
            m_isPenDown = VFX_FALSE;

            if (!m_isFreeDrag && !m_isForceFreeDrag)
            {
                // start timer to drag
                m_timerDrag->start();
            }
            else
            {
                onTimerDrag(NULL);
            }

            if (parent != NULL)
            {
                parent->penInput(event);
            }
#endif /* FREEDRAGANDDROP */
            break;

        case VFX_PEN_EVENT_TYPE_UP:
#if FREEDRAGANDDROP
            m_signalDrop.emit(this, event);
#else /* FREEDRAGANDDROP */
            if (m_timerDrag->getIsEnabled())
            {
                m_timerDrag->stop();

                m_isPenDown = VFX_FALSE;

                if ((VFX_ABS(event.pos.x - event.downPos.x) <= 5) &&
                    (VFX_ABS(event.pos.y - event.downPos.y) <= 5))
                {
                    onDirectLaunch();
                }
            }
            else
            {
                // drop widget
                if (m_isPenDown)
                {
                    m_signalDrop.emit(this, event);
                }
                // scroll desktop
                else
                {
                    if (parent != NULL)
                    {
                        parent->penInput(event);
                    }
                }

                m_isPenDown = VFX_FALSE;
            }
#endif /* FREEDRAGANDDROP */
            break;

        case VFX_PEN_EVENT_TYPE_MOVE:
#if FREEDRAGANDDROP
            m_signalMove.emit(this, event);
#else /* FREEDRAGANDDROP */
            if (m_timerDrag->getIsEnabled())
            {
                // once move out of this widget, start scrolling desktop
                //if (!containPoint(event.getRelPos(this)))
                if ((VFX_ABS(event.pos.x - event.downPos.x) > 10) ||
                    (VFX_ABS(event.pos.y - event.downPos.y) > 10))
                {
                    m_timerDrag->stop();

                    event.prevPos = event.downPos;
                    if (parent != NULL)
                    {
                        parent->penInput(event);
                    }
                }
            }
            else
            {
                // move widget
                if (m_isPenDown)
                {
                    m_signalMove.emit(this, event);
                }
                // scroll desktop
                else
                {
                    if (parent != NULL)
                    {
                        parent->penInput(event);
                    }
                }
            }
#endif /* FREEDRAGANDDROP */
            break;

        default:
            break;
    }

    return VFX_TRUE;
}


void VappHsWidget::createView()
{
    // do no create twice
    if (m_state == STATE_INIT)
    {
        m_childCount = getChildCount();

        // create the whole content for each widget itself
        onCreateView();

        // create drag timer
        VFX_OBJ_CREATE(m_timerDrag, VfxTimer, this);
        m_timerDrag->setStartDelay(START_DRAG_TIME);
        m_timerDrag->m_signalTick.connect(this, &VappHsWidget::onTimerDrag);

        // set anchor point to the center by default
        setAnchor(VfxFPoint(0.5, 0.5));

        m_state = STATE_CREATE;
    }
}


void VappHsWidget::releaseView(VfxBool isDeselected)
{
    // do not release twice
    if (m_state == STATE_CREATE)
    {
        // close timer
        VFX_OBJ_CLOSE(m_timerDrag);

        if (isDeselected)
        {
            onDeselect();
        }

        // release the whole content for each widget itself
        onReleaseView();

        VFX_ASSERT(m_childCount == getChildCount());

        m_state = STATE_INIT;
    }
}


void VappHsWidget::addToDesktop()
{
    m_desktop = VFX_OBJ_DYNAMIC_CAST(getParentFrame(), VappHsDesktop);
    onAddToDesktop();
	enterTop();
}


void VappHsWidget::removeFromDesktop()
{
    onRemoveFromDesktop();
    m_desktop = NULL;
}


VfxBool VappHsWidget::isCreated()
{
    return m_state == STATE_CREATE ? VFX_TRUE : VFX_FALSE;
}


void VappHsWidget::addToBottom(VfxFrame* frame)
{
    if (m_desktop != NULL)
    {
        m_desktop->m_frameBottom->addChildFrame(frame);
    }
}


void VappHsWidget::removeFromBottom(VfxFrame* frame)
{
    frame->removeFromParentFrame();
}


VfxRect VappHsWidget::getCurrentValidRect() const
{
    if (m_desktop != NULL)
    {
        return m_desktop->getValidRegion();
    }

    return VFX_RECT_ZERO;
}


void VappHsWidget::setDesktopTop()
{
    if (m_desktop != NULL)
    {
		// TODO: maybe we should search from last instead of get last directly
		VappHsWidget *f = VFX_OBJ_DYNAMIC_CAST(m_desktop->getLastChildFrame(), VappHsWidget);

		if (f && (f != this))
		{
			f->leaveTop();
		}

        bringToFront();

		enterTop();
    }
}


/*****************************************************************************
 * Home screen UI componet: widget bar
 *****************************************************************************/

VappHsWidgetBar::VappHsWidgetBar() :
    m_controlPanel(NULL),
    m_imageBg(NULL),
    m_imageButton(NULL),
    m_timerClick(NULL),
    m_state(STATE_INIT),
    m_xOri(0),
    m_penState(PEN_STATE_NONE),
    m_isOpening(VFX_FALSE)
{
    for (VfxS32 i = 0 ; i < MAX_ITEM ; i++)
    {
        m_dndImage[i] = NULL;
    }
}


void VappHsWidgetBar::onInit()
{
    VfxControl::onInit();

    // TODO: revise this
    setPos(VfxPoint(X_POS - FOLD_WIDTH, Y_POS));
    m_scrollWay = VERT_SCROLL;

    //
    // Background image. For FTE's slim project, use 9-slice image. 
    //
    VFX_OBJ_CREATE(m_imageBg, VfxImageFrame, this);
    m_imageBg->setResId(VAPP_HS_IMG_WG_BAR_BG);
    m_imageBg->setIsCached(VFX_TRUE);
    m_imageBg->setAutoAnimate(VFX_TRUE);

#if defined(__MMI_FTE_SUPPORT_SLIM__)
    VfxSize bgImgOriginalSize = m_imageBg->getSize();

    m_imageBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_imageBg->setSize(bgImgOriginalSize.width, BG_HEIGHT);
#endif /* defined(__MMI_FTE_SUPPORT_SLIM__) */

    setBounds(m_imageBg->getBounds());

    // 
    // Image panel frame
    //
    VFX_OBJ_CREATE(m_controlPanel, VfxControl, this);
    m_controlPanel->setPos(VfxPoint(0, GAP));
    m_controlPanel->setBounds(VfxRect(0, 0, FOLD_WIDTH, (getBounds().getHeight() - GAP * 2)));
    m_controlPanel->setAutoAnimate(VFX_TRUE);

    //
    // Button
    //
    VFX_OBJ_CREATE(m_imageButton, VfxImageFrame, this);
    m_imageButton->setResId(VAPP_HS_IMG_WG_BAR_FOLD);
    m_imageButton->setPos(VfxPoint((IND_X_POS + m_imageButton->getBounds().getMidX()), (IND_Y_POS + IND_HEIGHT / 2)));
    m_imageButton->setAnchor(VfxFPoint(0.5, 0.5));
    m_imageButton->setIsCached(VFX_TRUE);
    m_imageButton->setAutoAnimate(VFX_TRUE);

    // 
    // Init click timer
    //
    VFX_OBJ_CREATE(m_timerClick, VfxTimer, this);
    m_timerClick->setStartDelay(CLICK_TIME);

    // 
    // Enable auto animation by default
    //
    setAutoAnimate(VFX_TRUE);
}


void VappHsWidgetBar::arrange(VfxS32 crossIdx)
{
    VfxS32 y_offset = 0, y_offset_cross = 0;

    for (VfxS32 i = 0 ; i < m_count ; i++)
    {
        if (m_dndImage[i])
        {
            if (crossIdx != -1)
            {
                // all images before the index will move up, and vice versa
                y_offset_cross = (i < crossIdx) ? (- CROSS_GAP) : (CROSS_GAP);
            }
            m_dndImage[i]->setPos(VfxPoint((getBounds().getX() + FOLD_WIDTH / 2), m_dndImage[i]->getBounds().getMidY() + y_offset + y_offset_cross));
            y_offset += m_dndImage[i]->getBounds().getHeight() + GAP;
        }
    }

    m_isNeedArrange = VFX_FALSE;

    // do not alignment while cross
    if (crossIdx == -1)
    {
        alignment();
    }
}


VfxS32 VappHsWidgetBar::locateIdx(VfxPoint pos)
{
    // the default (un-located) index is below the last image
    VfxS32 ret = m_count;

    for (VfxS32 i = 0 ; i < m_count ; i ++)
    {
        if (!m_dndImage[i])
        {
            break;
        }

        // moving point over the anchor point (center) can insert before / after this image
        if (pos.y < m_dndImage[i]->getPos().y)
        {
            ret = i;
            break;
        }
    }

    return ret;
}


void VappHsWidgetBar::initImage(VfxS32 count, VappHsDndImage **image)
{
    // do not init twice
    if (m_state == STATE_INIT)
    {
        VappHsInteractiveImageArray::initImage(count, image);

        // after init image, fold the widget bar by default
        fold();
    }
}


void VappHsWidgetBar::flyInAllImages()
{
    VfxS32 i;

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    for (i = 0 ; i < m_count ; i ++)
    {
        m_dndImage[i]->setPos(VfxPoint(m_dndImage[i]->getPos().x, 300 + 100 * i));
        m_dndImage[i]->setOpacity(0.5f);
    }
    VfxAutoAnimate::commit();

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDuration(500);
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    arrange(-1);
    for (i = 0 ; i < m_count ; i ++)
    {
        m_dndImage[i]->setOpacity(1.0f);
    }
    VfxAutoAnimate::commit();
}


void VappHsWidgetBar::fold()
{
    // auto animation (ease out) for position
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);

    setPos(VfxPoint(X_POS - FOLD_WIDTH, Y_POS));

    VfxAutoAnimate::commit();

    m_state = STATE_FOLD;

    m_imageButton->setResId(VAPP_HS_IMG_WG_BAR_FOLD);

    m_signalUpdateFolding.emit(VFX_TRUE);
}


void VappHsWidgetBar::unfold()
{
    if (m_state == STATE_FOLD && !m_isOpening && m_timerClick->getIsEnabled())
    {   // let widget bar icon fly in from far away
        flyInAllImages();
    }
    m_isOpening = VFX_TRUE;

    // auto animation (ease out) for position
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);

    setPos(VfxPoint(X_POS, Y_POS));

    VfxAutoAnimate::commit();

    m_state = STATE_UNFOLD;

    m_imageButton->setResId(VAPP_HS_IMG_WG_BAR_UNFOLD);

    m_signalUpdateFolding.emit(VFX_FALSE);
}


VfxBool VappHsWidgetBar::onPenInput(VfxPenEvent &event)
{
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            {
                if (!m_isOpening)
                {
                    VfxAutoAnimate::begin();
                    VfxAutoAnimate::setDisable(VFX_TRUE);
                    for (VfxS32 i = 0 ; i < m_count ; i ++)
                    {
                        m_dndImage[i]->setOpacity(0.0f);
                    }
                    VfxAutoAnimate::commit();
                }

                VfxRect rect = VfxRect(IND_X_POS, IND_Y_POS, IND_WIDTH, IND_HEIGHT);
                VfxBool is_indicator = rect.contains(event.getRelPos(this));

                m_penState = (is_indicator) ? (PEN_STATE_FOLD_UNFOLD) : (PEN_STATE_NONE);
                if (m_penState == PEN_STATE_FOLD_UNFOLD)
                {
                    gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
                    m_xOri = event.pos.x;      // store pen down position
                    m_timerClick->start();     // start click timer
                }
            }
            break;

        case VFX_PEN_EVENT_TYPE_MOVE:
            if (m_penState == PEN_STATE_FOLD_UNFOLD)
            {
                VfxPoint pos = getPos();

                // move widget bar with the difference of previous location
                pos.x += event.pos.x - m_xOri;
                if (pos.x > X_POS)
                {   // fix widget bar at the left of the screen
                    pos.x   = X_POS;
                    // skip pen movement outside the valid widget bar region
                    m_xOri = X_POS + FOLD_WIDTH - 1;
                }
                else
                {
                    m_xOri = event.pos.x;
                }

                // no auto animation for moving
                VfxAutoAnimate::begin();
                VfxAutoAnimate::setDisable(VFX_TRUE);
                setPos(pos);
                VfxAutoAnimate::commit();

                if (!m_isOpening && ((X_POS - pos.x) <= (FOLD_WIDTH * 3 / 4)))
                {
                    flyInAllImages();
                    m_isOpening = VFX_TRUE;
                }
            }
            else
            {
                VappHsInteractiveImageArray::onPenInput(event);
            }
            break;

        case VFX_PEN_EVENT_TYPE_UP:
            if (m_penState == PEN_STATE_FOLD_UNFOLD)
            {
                // if pen up in click timer, fold / unfold directly
                if (m_timerClick->getIsEnabled())
                {
                    switch (m_state)
                    {
                        case STATE_FOLD:
                            unfold();
                            break;

                        case STATE_UNFOLD:
                            fold();
                            break;

                        default:
                            break;
                    }
                    m_timerClick->stop();
                }
                // fold or unfold according to current position
                else
                {
                    VfxPoint pos = getPos();

                    pos.x += event.pos.x - m_xOri;
                    pos.x = (pos.x > X_POS) ? (X_POS) : (pos.x);

                    if ((X_POS - pos.x) > (FOLD_WIDTH / 2))
                    {
                        fold();
                    }
                    else
                    {
                        unfold();
                    }
                }
            }
            else
            {
                VappHsInteractiveImageArray::onPenInput(event);
            }

            m_penState = PEN_STATE_NONE;
            break;

        default:
            break;
    }

    return VFX_TRUE;
}


VfxBool VappHsWidgetBar::onContainPoint(const VfxPoint &point) const
{
    VfxBool ret = VFX_FALSE;
    VfxRect bounds;

    do
    {
        // widget bar body
        bounds = getBounds();
        bounds.size.width = FOLD_WIDTH;
        ret = bounds.contains(point);
        if (ret)    break;

        // widget bar indicator
        bounds = VfxRect(IND_X_POS, IND_Y_POS, IND_WIDTH, IND_HEIGHT);
        ret = bounds.contains(point);
        if (ret)    break;
    } while (0);

    return ret;
}


void VappHsWidgetBar::alignment()
{
    VfxRect bounds = m_controlPanel->getBounds();
    VfxS32 max_height = bounds.getHeight();
    VfxS32 total_height = m_dndImage[m_count - 1]->getRect().getMaxY() + 1;
    VfxS32 i;
    VfxBool is_aligned = VFX_FALSE;

    // check whether current state is aligned
    if (total_height - bounds.origin.y == max_height)
    {
        VfxS32 first_idx = 0, last_idx = 0;

        // search first visible image
        for (i = 0 ; i < m_count ; i ++)
        {
            if (m_dndImage[i]->getRect().getMaxY() >= bounds.getY())
            {
                first_idx = last_idx = i;
                break;
            }
        }

        // search last visible image
        for (i = first_idx + 1 ; i < m_count ; i ++)
        {
            if (m_dndImage[i]->getRect().getY() <= bounds.getMaxY())
            {
                last_idx = i;
                break;
            }
        }

        // align first or last
        is_aligned = (m_dndImage[first_idx]->getRect().getY() >= bounds.getY()) ? (VFX_TRUE) : (is_aligned);
        is_aligned = (m_dndImage[last_idx]->getRect().getMaxY() <= bounds.getMaxY()) ? (VFX_TRUE) : (is_aligned);
    }

    // do nothing if is already aligned
    if (is_aligned)
    {
        // do nothing
    }
    // fewer images or move over top, align to top-most
    else if ((total_height <= max_height) || (bounds.origin.y < 0))
    {
        bounds.origin.y = 0;
    }
    else
    {
        for (i = 0 ; i < m_count ; i ++)
        {
            if (!m_dndImage[i])
            {
                break;
            }

            // align the first widget of current screen
            if (bounds.origin.y <= m_dndImage[i]->getRect().getMidY())
            {
                bounds.origin.y = m_dndImage[i]->getRect().getY();
                break;
            }
        }

        // move over bottom, align to bottom-most
        if ((total_height - bounds.origin.y) < max_height)
        {
            bounds.origin.y = total_height - max_height;
        }
    }

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);

    m_controlPanel->setBounds(bounds);

    VfxAutoAnimate::commit();
}


/*****************************************************************************
 * Home screen UI componet: desktop
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("Desktop", VappHsDesktop, VfxControl);


VappHsDesktop::VappHsDesktop() :
    m_frameBottom(NULL),
    m_xOri(0),
    m_timerSwitch(NULL),
    m_validY(0),
    m_validHeight(0)
{
}


void VappHsDesktop::onInit()
{
    VfxControl::onInit();

    setBounds(VfxRect(0, 0, PAGE_WIDTH, PAGE_HEIGHT));

    // Default vertical valid region is the entire bounds.
    m_validY = 0;
    m_validHeight = PAGE_HEIGHT;

    // enable auto animation by default
    setAutoAnimate(VFX_TRUE);

    // init bottom frame
    VFX_OBJ_CREATE(m_frameBottom, VfxFrame, this);
    m_frameBottom->setPos(VfxPoint(0, 0));
    m_frameBottom->setBounds(VfxRect(0, 0, PAGE_WIDTH, PAGE_HEIGHT));
    m_frameBottom->setAutoAnimate(VFX_TRUE);

    // init switch timer
    VFX_OBJ_CREATE(m_timerSwitch, VfxTimer, this);
    m_timerSwitch->setStartDelay(SWITCH_TIME);

    m_signalBoundsChanged.connect(this, &VappHsDesktop::onBoundsValueChange);
}


void VappHsDesktop::addWidget(VappHsWidget *widget)
{
    VfxPoint pos = widget->getPos();
    VfxS32 x1 = getValidRegion().getMinX();
    VfxS32 y1 = getValidRegion().getMinY() + widget->getBounds().getMidY();
    VfxS32 x2 = x1 + PAGE_WIDTH - 1;
    VfxS32 y2 = getValidRegion().getMaxY();;

    addChildFrame(widget);

    // boundary check to re-locate
    if (pos.x < x1) pos.x = x1;
    if (pos.x > x2) pos.x = x2;
    if (pos.y < y1) pos.y = y1;
    if (pos.y > y2) pos.y = y2;
    widget->setPos(pos);

    // notify widget
    widget->addToDesktop();
}


void VappHsDesktop::addWidgetFromHistory(VappHsWidget *widget)
{
    VfxPoint pos = widget->getPos();
    VfxS32 y1 = getValidRegion().getMinY() + widget->getBounds().getMidY();
    VfxS32 y2 = getValidRegion().getMaxY();

    // boundary check to re-locate
    if (pos.y < y1) pos.y = y1;
    if (pos.y > y2) pos.y = y2;
    widget->setPos(pos);

    // notify widget
    widget->addToDesktop();
}


void VappHsDesktop::removeWidget(VappHsWidget *widget)
{
    widget->removeFromParentFrame();

    // notify widget
    widget->removeFromDesktop();
}


void VappHsDesktop::alignment()
{
    VfxRect bounds = getBounds();
    VfxS32 x = bounds.origin.x;         // current bounds origin
    VfxS32 i;

    for (i = 0 ; i < TOTAL_PAGE ; i ++)
    {
        VfxS32 xp = i * PAGE_WIDTH;

        // check which page is close to current view
        if (x < (xp + PAGE_WIDTH / 2))
        {
            bounds.origin.x = xp;
            break;
        }
    }

    // boundary check
    if (i == TOTAL_PAGE)
    {
        bounds.origin.x = (i - 1) * PAGE_WIDTH;
    }

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);

    setBounds(bounds);

    VfxAutoAnimate::commit();
}


void VappHsDesktop::alignBottomFrame()
{
    VfxPoint pos = m_frameBottom->getPos();

    pos.x = getBounds().origin.x;
    m_frameBottom->setPos(pos);
}


void VappHsDesktop::onBoundsValueChange(VfxFrame *source, const VfxRect &oldBounds)
{
    VFX_UNUSED(source);
    VFX_UNUSED(oldBounds);

    alignBottomFrame();
}


VfxBool VappHsDesktop::doPenInput(VfxPenEvent &event)
{
#if !defined(VAPP_HS_CFG_MULTI_DESKTOP)
    return VFX_FALSE;
#else
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            m_xOri = getBounds().origin.x;     // original bounds origin
            m_timerSwitch->start();
            break;

        case VFX_PEN_EVENT_TYPE_MOVE:
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);
            {   // move bounds without auto animation
                VfxS32 x_diff = event.pos.x - event.prevPos.x;
                VfxRect bounds = getBounds();

                bounds.origin.x -= x_diff;
                setBounds(bounds);
            }
            VfxAutoAnimate::commit();
            break;

        case VFX_PEN_EVENT_TYPE_UP:
            if (m_timerSwitch->getIsEnabled())
            {   // if user scroll quickly, change page directly
                // otherwise, page is decided according to current position
                VfxRect bounds = getBounds();
                VfxS32 x_diff = bounds.origin.x - m_xOri;

                // if not scroll enough, force to scroll more
                if ((VFX_ABS(x_diff) > SENSITIVITY) && (VFX_ABS(x_diff) < PAGE_WIDTH / 2))
                {
                    bounds.origin.x += (x_diff > 0) ? (PAGE_WIDTH) : (-PAGE_WIDTH);
                    setBounds(bounds);
                }
            }

            // align the page
            alignment();
            break;

        default:
            break;
    }

    return VFX_FALSE;
#endif /* !defined(VAPP_HS_CFG_MULTI_DESKTOP) */
}


void VappHsDesktop::setVerticalValidRegion(VfxS32 y, VfxS32 height)
{
    m_validY = y;
    m_validHeight = height;
}


VfxRect VappHsDesktop::getValidRegion()
{
    VfxRect rect;

    rect = getBounds();
    rect.origin.y = m_validY;
    rect.size.height = m_validHeight;

    return rect;
}


/*****************************************************************************
 * Home screen UI componet: shortcut bar class
 *****************************************************************************/

VappHsShortcutBar::VappHsShortcutBar() :
    m_imageHighlight(NULL),
    m_state(STATE_INIT)
{
    for (VfxS32 i = 0 ; i < MAX_ITEM ; i ++)
    {
        m_dndImage[i] = NULL;
    }
}


void VappHsShortcutBar::onInit()
{
    VfxControl::onInit();

    setPos(VfxPoint(X_POS, Y_POS));
    setBounds(VfxRect(0, 0, MAX_WIDTH, MAX_HEIGHT));

    // enable auto animation by default
    setAutoAnimate(VFX_TRUE);

    // init highlight image
    VFX_OBJ_CREATE(m_imageHighlight, VfxImageFrame, this);
    m_imageHighlight->setResId(VAPP_HS_IMG_SC_HILITE);
    m_imageHighlight->setOpacity(0.0f);
    m_imageHighlight->setAnchor(VfxFPoint(0.5, 0.5));
    m_imageHighlight->setAutoAnimate(VFX_TRUE);

    m_signalBoundsChanged.connect(this, &VappHsShortcutBar::onBoundsValueChange);
}


void VappHsShortcutBar::initImage(VfxS32 count, VappHsDndImage **image)
{
    // do not init twice
    if (m_state == STATE_INIT)
    {
        VappHsInteractiveImageArray::initImage(count, image);

        m_state = STATE_ACTIVE;
    }
}


void VappHsShortcutBar::arrange(VfxS32 crossIdx)
{
    VfxS32 x_offset = 0, x_offset_cross = 0;

    for (VfxS32 i = 0 ; i < m_count ; i++)
    {
        if (m_dndImage[i])
        {
            if (crossIdx != -1)
            {
                // all image before the index will move left, and vice versa
                x_offset_cross = (i < crossIdx) ? (- CROSS_GAP) : (CROSS_GAP);
            }
            m_dndImage[i]->setPos(VfxPoint(m_dndImage[i]->getBounds().getMidX() + x_offset + x_offset_cross, Y_OFFSET));
            x_offset += m_dndImage[i]->getBounds().getWidth() + GAP;
        }
    }

    // do not alignment while cross
    if (crossIdx == -1)
    {
        alignment();
    }

    updateIndicators();
}


void VappHsShortcutBar::alignment()
{
    VfxRect bounds = getBounds();
    VfxS32 total_width = m_dndImage[m_count - 1]->getRect().origin.x + m_dndImage[m_count - 1]->getRect().size.width - 1;

    if (total_width <= MAX_WIDTH)
    {   // fewer images, align to centra
        bounds.origin.x = -(MAX_WIDTH - total_width) / 2;
    }
    else
    {   // align to the left most point
        VfxS32 start_idx = 0, end_idx = 0, available_width = 0, i;
        VfxBool is_find_end = VFX_FALSE;

        if (bounds.origin.x < 0)
        {   // if moving over left-most, align the first one
            start_idx = 0;
        }
        else
        {
            for (i = 0 ; i < m_count ; i ++)
            {
                if (!m_dndImage[i])
                {
                    break;
                }

                // align the first shortcut of current screen
                if (bounds.origin.x <= m_dndImage[i]->getRect().getMidX())
                {
                    start_idx = i;
                    break;
                }
            }

            if (i == m_count)
            {
                start_idx = m_count - 1;
            }

            // if moving over right-most, align the last one
            if ((total_width - m_dndImage[start_idx]->getRect().origin.x) < MAX_WIDTH)
            {
                end_idx = m_count - 1;
                for (i = end_idx ; i >= 0 ; i --)
                {
                    if ((m_dndImage[end_idx]->getRect().origin.x - m_dndImage[i]->getRect().origin.x + m_dndImage[end_idx]->getRect().size.width) > MAX_WIDTH)
                    {
                        break;
                    }
                    start_idx = i;
                }
                is_find_end = VFX_TRUE;
            }
        }

        // because we want to know the first and the last display shortcut to caulate the width for alignment
        // we have to know the start and end index
        if (!is_find_end)
        {
            for (i = (start_idx + 1) ; i < m_count ; i ++)
            {
                if (m_dndImage[i])
                {
                    VfxS32 w = m_dndImage[i]->getRect().origin.x - m_dndImage[start_idx]->getRect().origin.x + m_dndImage[i]->getRect().size.width;

                    if (w > MAX_WIDTH)
                    {
                        break;
                    }
                    end_idx = i;
                }
            }
        }

        // available width means the total width of current display shortcuts
        available_width = m_dndImage[end_idx]->getRect().origin.x - m_dndImage[start_idx]->getRect().origin.x + m_dndImage[end_idx]->getRect().size.width;

        // align to center for current shortcuts
        bounds.origin.x = m_dndImage[start_idx]->getRect().origin.x - (MAX_WIDTH - available_width) / 2;
    }

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);

    setBounds(bounds);

    VfxAutoAnimate::commit();
}


void VappHsShortcutBar::highlightImage(VappHsDndImage *image, VfxBool isHighlight)
{
    if (m_state != STATE_INIT)
    {
        if (isHighlight)
        {
            // disable auto animation for position
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);
            m_imageHighlight->setPos(image->getPos());
            VfxAutoAnimate::commit();
        }

        // let the highlight image appear from dark to bright
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        m_imageHighlight->setOpacity((isHighlight) ? (1.0f) : (0.0f));
        VfxAutoAnimate::commit();
    }
}


VfxS32 VappHsShortcutBar::locateIdx(VfxPoint pos)
{
    // the default (un-located) index is below the last image
    VfxS32 ret = m_count;

    for (VfxS32 i = 0 ; i < m_count ; i ++)
    {
        if (!m_dndImage[i])
        {
            break;
        }

        // moving point over the anchor point (center) can insert before / after this image
        if (pos.x < m_dndImage[i]->getPos().x)
        {
            ret = i;
            break;
        }
    }

    return ret;
}


VfxBool VappHsShortcutBar::onPenInput(VfxPenEvent &event)
{
    VappHsInteractiveImageArray::onPenInput(event);

    if (m_isScroll)
    {
        m_signalUpdateIndicator.emit(LEFT_IND, VFX_TRUE);
        m_signalUpdateIndicator.emit(RIGHT_IND, VFX_TRUE);
    }
    else
    {
        updateIndicators();
    }

    return VFX_TRUE;
}


VfxBool VappHsShortcutBar::onContainPoint(const VfxPoint &point) const
{
    VfxBool ret = VFX_FALSE;
    VfxRect bounds;

    bounds = getBounds();
    bounds.origin.y = Y_MARGIN;
    bounds.size.height -=  Y_MARGIN;

    ret = bounds.contains(point);

    return ret;
}


void VappHsShortcutBar::updateIndicators()
{
    if (!m_isScroll)
    {
        VfxRect bounds = getBounds();
        VfxBool isHidden;

        isHidden = (bounds.origin.x <= 0) ? (VFX_TRUE) : (VFX_FALSE);
        m_signalUpdateIndicator.emit(LEFT_IND, isHidden);

        isHidden = (bounds.origin.x + bounds.size.width - 1 <= m_dndImage[m_count - 1]->getPos().x) ? (VFX_FALSE) : (VFX_TRUE);
        m_signalUpdateIndicator.emit(RIGHT_IND, isHidden);
    }
}


void VappHsShortcutBar::onBoundsValueChange(VfxFrame *source, const VfxRect &oldBounds)
{
    VFX_UNUSED(source);
    VFX_UNUSED(oldBounds);

    updateIndicators();
}


/*****************************************************************************
 * Home screen UI componet: black screen class
 *****************************************************************************/

void VappHsBlackScreen::onInit()
{
    VfxControl::onInit();

    setPos(VfxPoint(X_POS, Y_POS));
    setBounds(VfxRect(0, 0, MAX_WIDTH, MAX_HEIGHT));
    setBgColor(VFX_COLOR_BLACK);
    setIsOpaque(VFX_TRUE);
    setOpacity(0.5f);
}


VfxBool VappHsBlackScreen::onPenInput(VfxPenEvent &event)
{
    // hook all events
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
        m_signalDown.emit();
    }

    return VFX_TRUE;
}


/*****************************************************************************
 * Home screen UI componet: shortcut pool class
 *****************************************************************************/

VappHsShortcutPool::VappHsShortcutPool() :
    m_imageHighlight(NULL),
    m_state(STATE_INIT),
    m_crossRow(0),
    m_isOpening(VFX_FALSE)
{
    for (VfxS32 i = 0 ; i < MAX_ITEM ; i ++)
    {
        m_dndImage[i] = NULL;
    }
}


void VappHsShortcutPool::onInit()
{
    VfxControl::onInit();

    setPos(VfxPoint(X_POS, Y_POS));
    setBounds(VfxRect(0, 0, MAX_WIDTH, 0));           // init hight to be 0 as folded
#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    setIsOpaque(VFX_TRUE);
#endif /* defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */

#if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    // enable auto animation by default
    setAutoAnimate(VFX_TRUE);
#endif /* !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */

    // 
    // Set background image. For FTE's slim project, use 9-slice image.
    //
    VfxImageFrame *bgImg;

    VFX_OBJ_CREATE(bgImg, VfxImageFrame, this);
    bgImg->setResId(VAPP_HS_IMG_SC_POOL_BG);
    bgImg->setIsCached(VFX_TRUE);

#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    bgImg->setIsOpaque(VFX_TRUE);
#endif /* defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */

#if defined(__MMI_FTE_SUPPORT_SLIM__)
    VfxSize bgImgOriginalSize = bgImg->getSize();

    bgImg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    bgImg->setSize(LCD_WIDTH, bgImgOriginalSize.height);
#endif /* defined(__MMI_FTE_SUPPORT_SLIM__) */

    // 
    // Init highlight image
    //
    VFX_OBJ_CREATE(m_imageHighlight, VfxImageFrame, this);
    m_imageHighlight->setResId(VAPP_HS_IMG_SC_HILITE);
    m_imageHighlight->setOpacity(0.0f);
    m_imageHighlight->setAnchor(VfxFPoint(0.5, 0.5));
    m_imageHighlight->setAutoAnimate(VFX_TRUE);
}


void VappHsShortcutPool::fold()
{   // move to bottom and resize hight to 0 with ease out auto animation
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);

    setPos(VfxPoint(X_POS, Y_POS + 1));
    setBounds(VfxRect(0, 0, MAX_WIDTH, 0));

    VfxAutoAnimate::commit();

    m_state = STATE_FOLD;
}


void VappHsShortcutPool::unfold()
{
#if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    if (m_state == STATE_FOLD && !m_isOpening)
    {   // let shortcut pool icon fly in from far away
        VfxS32 num_of_x = getBounds().getWidth() / ITEM_WIDTH;
        VfxS32 i;

        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        for (i = 0 ; i < m_count ; i ++)
        {
            vrt_size_struct main_screen_size;
            vrt_color_type_enum main_screen_color_format;
            vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

            VfxS32 x = main_screen_size.width + (main_screen_size.width >> 2);
            m_dndImage[i]->setPos(VfxPoint(x + 100 * (i / num_of_x) * i, m_dndImage[i]->getPos().y));
            m_dndImage[i]->setOpacity(0.5f);
        }
        VfxAutoAnimate::commit();

        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDuration(500);
        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        arrange(-1);
        for (i = 0 ; i < m_count ; i ++)
        {
            m_dndImage[i]->setOpacity(1.0f);
        }
        VfxAutoAnimate::commit();

        m_isOpening = VFX_TRUE;
    }
#endif /* !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */

    // move to top and resize hight to max hight with ease out auto animation
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);

    setPos(VfxPoint(X_POS, Y_POS - MAX_HEIGHT + 1));
    setBounds(VfxRect(0, 0, MAX_WIDTH, MAX_HEIGHT));

    VfxAutoAnimate::commit();

    m_state = STATE_UNFOLD;
}


void VappHsShortcutPool::initImage(VfxS32 count, VappHsDndImage **image)
{
    if (m_state == STATE_INIT)
    {
        VappHsInteractiveImageArray::initImage(count, image);

        // fold shortcut pool by default
        fold();
    }
}


void VappHsShortcutPool::arrange(VfxS32 crossIdx)
{
    VfxS32 pool_width = getBounds().getWidth();

    // number of image in each row
    VfxS32 num_of_x = pool_width / ITEM_WIDTH;

    // x gap between images in each row
    VfxS32 x_gap = (pool_width % ITEM_WIDTH) / (num_of_x - 1);

    // x start offset of the first image in each row
    VfxS32 x_start = ((pool_width % ITEM_WIDTH) - x_gap * (num_of_x - 1)) / 2;

    // y start offset of the first image in each column
    VfxS32 y_offset = Y_GAP * 2 + ITEM_HEIGHT / 2;

    VfxS32 w = ITEM_WIDTH / 2, idx = 0, x_offset = x_start + w, x_offset_cross = 0;

    // search two dimensions of the image array, i is row, j is column
    for (VfxS32 i = 0 ; i < ((m_count / num_of_x) + 1) ; i ++)
    {
        for (VfxS32 j = 0 ; j < num_of_x ; j ++)
        {
            if (m_dndImage[idx])
            {
                if ((crossIdx != -1) && (i == m_crossRow))
                {
                    // all images in a specific row before the index will move left, and vice versa
                    x_offset_cross = (idx < crossIdx) ? (-CROSS_GAP) : (CROSS_GAP);
                }
                m_dndImage[idx]->setPos(VfxPoint(x_offset + x_offset_cross, y_offset));
                idx ++;
            }
            x_offset += x_gap + ITEM_WIDTH;
            x_offset_cross = 0;
        }
        x_offset = x_start + w;
        y_offset += Y_GAP + ITEM_HEIGHT;
    }

    m_isNeedArrange = VFX_FALSE;
}


VfxS32 VappHsShortcutPool::locateIdx(VfxPoint pos)
{
    VfxS32 pool_width   = getBounds().getWidth();
    VfxS32 num_of_x     = pool_width / ITEM_WIDTH;
    VfxS32 x_gap        = (pool_width % ITEM_WIDTH) / (num_of_x - 1);
    VfxS32 x_start      = ((pool_width % ITEM_WIDTH) - x_gap * (num_of_x - 1)) / 2;
    VfxS32 ret          = 0;

    // re-offset
    pos.x -= x_start;
    pos.y -= Y_GAP * 2;

    // boundary check
    pos.x = (pos.x < 0) ? (0) : (pos.x);
    pos.y = (pos.y < 0) ? (0) : (pos.y);

    // calculate which row
    m_crossRow = pos.y / (ITEM_HEIGHT + Y_GAP);

    if (ret < m_count)
    {
        ret = (m_crossRow + 1) * num_of_x;
        ret -= (m_isNeedArrange) ? (1) : (0);

        // calculate which two images the point is located between
        for (VfxS32 i = (m_crossRow * num_of_x) ; i < ((m_crossRow + 1) * num_of_x) ; i ++)
        {
            if ((i >= m_count) || (!m_dndImage[i]))
            {
                ret = m_count;
                break;
            }

            // moving point over the anchor point (center) can insert before / after this image
            if (pos.x < m_dndImage[i]->getPos().x)
            {
                ret = i;
                break;
            }
        }
    }
    else
    {
        ret = m_count;
    }

    ret = (ret > m_count) ? (m_count) : (ret);

    return ret;
}


void VappHsShortcutPool::highlightImage(VappHsDndImage *image, VfxBool isHighlight)
{
    if (m_state != STATE_INIT)
    {
        if (isHighlight)
        {
            // disable auto animation for position
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);
            m_imageHighlight->setPos(image->getPos());
            VfxAutoAnimate::commit();
        }

        // let the highlight image appear from dark to bright
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        m_imageHighlight->setOpacity((isHighlight) ? (1.0f) : (0.0f));
        VfxAutoAnimate::commit();
    }
}


VfxBool VappHsShortcutPool::onPenInput(VfxPenEvent &event)
{
    VFX_UNUSED(event);

    // currently do nothing
    return VFX_TRUE;
}


/*****************************************************************************
 * Home screen UI componet:  native status icon class
 *****************************************************************************/

void VappHsStatusIcon::onInit()
{
    VfxControl::onInit();

    // 
    // set statuc icon bar
    //
    VcpStatusIconBar *iconBar;

    VFX_OBJ_CREATE(iconBar, VcpStatusIconBar, this);
    iconBar->enableBackground(VFX_FALSE);

    // 
    // Set background image. For FTE's slim project, use 9-slice image.
    //
    VfxImageFrame *bgImg;

    VFX_OBJ_CREATE(bgImg, VfxImageFrame, this);
    bgImg->setResId(VAPP_HS_IMG_SI_BG);

#if defined(__MMI_FTE_SUPPORT_SLIM__)
    bgImg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    bgImg->setSize(iconBar->getSize());
#endif /* defined(__MMI_FTE_SUPPORT_SLIM__) */

    setSize(iconBar->getSize());
}


/*****************************************************************************
 * Home screen UI componet: idle mode text class
 *****************************************************************************/

VappHsIdleModeText::VappHsIdleModeText() :
    m_bgImg(NULL),
    m_marquee(NULL),
    m_iconData(NULL),
    m_isTextPresent(VFX_FALSE)
{
}


void VappHsIdleModeText::onInit()
{
    VfxFrame::onInit();

    setBounds(VfxRect(0, 0, FRAME_WIDTH, FRAME_HEIGHT));

    //
    // Background image. For FTE's slim project, use 9-slice image. 
    //
    VFX_OBJ_CREATE(m_bgImg, VfxImageFrame, this);
    m_bgImg->setResId(VAPP_HS_IMG_IDLE_MODE_TEXT_BG);
    m_bgImg->setHidden(VFX_TRUE);   // By default, there doesn't have texts.

#if defined(__MMI_FTE_SUPPORT_SLIM__)
    VfxSize bgImgOriginalSize = m_bgImg->getSize();

    m_bgImg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_bgImg->setSize(FRAME_WIDTH, bgImgOriginalSize.height);
#endif /* defined(__MMI_FTE_SUPPORT_SLIM__) */

    //
    // Marquee
    //
    VFX_OBJ_CREATE(m_marquee, VcpMarquee, this);
    m_marquee->setAnchor(VfxFPoint(0.5, 0.0));
    m_marquee->setPos(VfxPoint(FRAME_WIDTH / 2, 0));
    m_marquee->setBounds(VfxRect(0, 0, TEXT_WIDTH, TEXT_HEIGHT));
    m_marquee->setHalign(VcpMarquee::HALIGN_CENTER);
    m_marquee->setSpeed(MARQUEE_SPEED);
}


void VappHsIdleModeText::onDeinit()
{
    VfxFrame::onDeinit();
}


void VappHsIdleModeText::onDraw(VfxDrawContext &dc)
{
    // Draw SAT icon when the data is provided.
    if (m_iconData)
    {
        VfxRect rect;

        // Horizontal: centralized
        // Vertical: below the idle mode text
        rect.origin.x = (FRAME_WIDTH - ICON_WIDTH) >> 1;
        rect.origin.y = TEXT_HEIGHT + ICON_GAP_Y;

        // icon is resized
        rect.size.width  = ICON_WIDTH;
        rect.size.height = ICON_HEIGHT;

        // TODO: this function cannnot resize the image actually
        dc.drawResizedImageFromMem(rect, m_iconData);
    }
}


void VappHsIdleModeText::setText(const VfxWString &str)
{
    if (str.isNull())
    {
        m_bgImg->setHidden(VFX_TRUE);
        m_marquee->clearMovableFrame(); // stop scroll internally
        m_isTextPresent = VFX_FALSE;
    }
    else
    {
        m_bgImg->setHidden(VFX_FALSE);
        m_marquee->setMovableFrame(str);
        m_marquee->startScroll();
        m_isTextPresent = VFX_TRUE;
    }

    updateHidden();
}


void VappHsIdleModeText::setIcon(const VfxU8 *iconData)
{
    m_iconData = iconData;

    updateHidden();

    invalidate();
}


void VappHsIdleModeText::updateHidden()
{
    if (m_iconData || m_isTextPresent)
    {
        setHidden(VFX_FALSE);
    }
    else
    {
        setHidden(VFX_TRUE);
    }
}


/*****************************************************************************
 * Home screen UI componet: desktop indicator
 *****************************************************************************/

VappHsDesktopIndicator::VappHsDesktopIndicator() :
    m_highlightIndex(0)
{
}


void VappHsDesktopIndicator::onInit()
{
    VfxFrame::onInit();

    setBounds(VfxRect(0, 0, IND_WIDTH * TOTAL_PAGE, IND_HEIGHT));
}


void VappHsDesktopIndicator::onDraw(VfxDrawContext &dc)
{
    for (VfxS32 i = 0; i < TOTAL_PAGE; i++)
    {
        if (i == m_highlightIndex)
        {
            dc.drawImageFromRes(i * IND_WIDTH, 0, VAPP_HS_IMG_DT_IND_HILITE);
        }
        else
        {
            dc.drawImageFromRes(i * IND_WIDTH, 0, VAPP_HS_IMG_DT_IND);
        }
    }
}


void VappHsDesktopIndicator::highlight(VfxS32 pos)
{
    VfxS32 idx;

    idx = (pos + PAGE_WIDTH / 2) / PAGE_WIDTH;
    idx = (idx < 0) ? (0) : (idx);
    idx = (idx >= TOTAL_PAGE) ? (TOTAL_PAGE - 1) : (idx);

    m_highlightIndex = idx;
    invalidate();
}


#if defined(__MMI_SEARCH_WEB_GOOGLE__)

VFX_IMPLEMENT_CLASS("VappHsSearchBar", VappHsSearchBar, VfxControl);

const VfxFloat VappHsSearchBar::s_pressedOpacity = 0.6f;


VappHsSearchBar::VappHsSearchBar() :
    m_bgImg(NULL),
    m_icon(NULL),
    m_text(NULL)
{
    // Do nothing.
}


void VappHsSearchBar::onInit()
{
    VfxControl::onInit();

    setSize(WIDTH, HEIGHT);

    //
    // Background Image.
    //
    VFX_OBJ_CREATE(m_bgImg, VfxImageFrame, this);
    m_bgImg->setResId(VAPP_HS_IMG_SEARCH_BAR_BG);
    m_bgImg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_bgImg->setSize(WIDTH, HEIGHT);

    //
    // Icon & Text
    //
    const U8 *image;
    const WCHAR *string;

    if (mmi_search_web_get_idle_hint(&image, &string))
    {
        VFX_DEV_ASSERT(image && string);

        VFX_OBJ_CREATE(m_icon, VfxImageFrame, this);
        m_icon->setMem(image);
        m_icon->setAnchor(0.0f, 0.5f);
        m_icon->setPos(ICON_POS_X, HEIGHT / 2);

        VFX_OBJ_CREATE(m_text, VfxTextFrame, this);
        m_text->setString(VFX_WSTR_MEM((VfxWChar *)string));
        m_text->setColor(VFX_COLOR_BLACK);
        m_text->setFont(VAPP_HS_SEARCH_BAR_FONT);
        m_text->setAnchor(0.0f, 0.5f);
        m_text->setPos(TEXT_POS_X, HEIGHT / 2);
    }
}


VfxBool VappHsSearchBar::onPenInput(VfxPenEvent &event)
{
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            setPressed(VFX_TRUE);
            break;

        case VFX_PEN_EVENT_TYPE_MOVE:
            if (containPoint(event.getRelPos(this)))
            {
                setPressed(VFX_TRUE);
            }
            else
            {
                setPressed(VFX_FALSE);
            }
            break;

        case VFX_PEN_EVENT_TYPE_UP:
            setPressed(VFX_FALSE);

            if (containPoint(event.getRelPos(this)))
            {
                vfxPostInvoke0(this, &VappHsSearchBar::onLaunchSearchApp);
            }
            break;

        case VFX_PEN_EVENT_TYPE_ABORT:
            setPressed(VFX_FALSE);
            break;

        default:
            break;
    }

    return VFX_TRUE;
}


void VappHsSearchBar::setPressed(VfxBool isPressed)
{
    if (isPressed)
    {
        setOpacity(s_pressedOpacity);
    }
    else
    {
        setOpacity(1.0f);
    }
}


void VappHsSearchBar::onLaunchSearchApp()
{
    mmi_search_web_trigger_by_hot_key(MMI_SEARCH_WEB_HOT_KEY_TOUCH_HINT);
}

#endif /* defined(__MMI_SEARCH_WEB_GOOGLE__) */

#endif /* __MMI_VUI_HOMESCREEN__ */

