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
 *  vapp_screen_lock_pattern_frame.cpp
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

#include "MMI_features.h"

#ifdef __MMI_VUI_SCREEN_LOCK_PATTERN__

#include "vapp_screen_lock_pattern_frame.h"
#include "mmi_rp_vapp_screen_lock_pattern_def.h"
#include "math.h"
#include "vfx_adp_device.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

// extern pluto setting api
#include "GpioSrvGProt.h"

#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * Define
 *****************************************************************************/
#define VAPP_SCREEN_LOCK_PATTERN_INVALID_IDX  0xFFFFFFFF
#define VAPP_SLK_CENTER_IDX  4
#define VAPP_SCREEN_LOCK_PATTERN_RESET_TIME    1500

#if defined(__MMI_MAINLCD_480X800__)
    #define VAPP_SCREEN_LOCK_PATTERN_FRAME_ARROW_GAP  (8)
#elif defined(__MMI_MAINLCD_320X480__)
    #define VAPP_SCREEN_LOCK_PATTERN_FRAME_ARROW_GAP  (4)
#elif defined(__MMI_MAINLCD_240X400__)
    #define VAPP_SCREEN_LOCK_PATTERN_FRAME_ARROW_GAP  (2)
#elif defined(__MMI_MAINLCD_240X320__)
    #define VAPP_SCREEN_LOCK_PATTERN_FRAME_ARROW_GAP  (2)
#else
    #define VAPP_SCREEN_LOCK_PATTERN_FRAME_ARROW_GAP  (4)
#endif


/*****************************************************************************
 * Typedef
 *****************************************************************************/


/*****************************************************************************
 * Global Variable
 *****************************************************************************/

/*****************************************************************************
 * Function
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappScreenLockPatternGrid", VappScreenLockPatternGrid, VfxControl);

VappScreenLockPatternGrid::VappScreenLockPatternGrid(VfxS32 sizeX, VfxS32 sizeY):
    m_sizeX(sizeX),
    m_sizeY(sizeY),
    m_state(GRID_STATE_INITED),
    m_dot(NULL),
    m_circleG(NULL),
    m_circleR(NULL),
    m_arrowG(NULL),
    m_arrowR(NULL),
    m_arrowAngle(0.0f)
{
}

void VappScreenLockPatternGrid::onInit()
{
    VfxControl::onInit();

    // To cache dot frame.
    VfxFloatTimeline * m_cacheTL;
    VFX_OBJ_CREATE(m_cacheTL, VfxFloatTimeline, this);
    m_cacheTL->setTarget(this);
    m_cacheTL->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
    m_cacheTL->setDurationTime(3);
    m_cacheTL->setFromValue(0.01f);
    m_cacheTL->setToValue(0.0f);
    m_cacheTL->m_signalStopped.connect(this, &VappScreenLockPatternGrid::onTimelineStop);
    m_cacheTL->start();

    VFX_OBJ_CREATE(m_dot, VfxImageFrame, this);
    m_dot->setResId(IMG_ID_VAPP_SCREEN_LOCK_PATTERN_DOT);
    m_dot->setPos(m_sizeX / 2, m_sizeY / 2);
    m_dot->setAnchor(0.5, 0.5);

    VFX_OBJ_CREATE(m_circleG, VfxImageFrame, this);
    m_circleG->setResId(IMG_ID_VAPP_SCREEN_LOCK_PATTERN_CIRCLE_G);
    m_circleG->setPos(m_sizeX / 2, m_sizeY / 2);
    m_circleG->setAnchor(0.5, 0.5);

     // set m_dot attribute
    VfxSize borderSize = m_circleG->getSize();
    m_dot->setBounds(0, 0, borderSize.width, borderSize.height);

    VFX_OBJ_CREATE(m_circleR, VfxImageFrame, this);
    m_circleR->setResId(IMG_ID_VAPP_SCREEN_LOCK_PATTERN_CIRCLE_R);
    m_circleR->setPos(m_sizeX / 2, m_sizeY / 2);
    m_circleR->setAnchor(0.5, 0.5);

    VFX_OBJ_CREATE(m_arrowG, VfxImageFrame, this);
    m_arrowG->setResId(IMG_ID_VAPP_SCREEN_LOCK_PATTERN_ARROW_G);
    m_arrowG->setPos(m_sizeX / 2, m_sizeY / 2);
    m_arrowG->setAnchor(0.5, 0.5);

    VFX_OBJ_CREATE(m_arrowR, VfxImageFrame, this);
    m_arrowR->setResId(IMG_ID_VAPP_SCREEN_LOCK_PATTERN_ARROW_R);
    m_arrowR->setPos(m_sizeX / 2, m_sizeY / 2);
    m_arrowR->setAnchor(0.5, 0.5);

    resetState();

    // set bounds from largest image
    //setBounds(-(m_sizeX/2), -(m_sizeY/2), m_sizeX/2-1, m_sizeY/2-1);
    setBounds(0, 0, m_sizeX, m_sizeY);
}


void VappScreenLockPatternGrid::onDeinit()
{
    VFX_OBJ_CLOSE(m_dot);
    VFX_OBJ_CLOSE(m_circleG);
    VFX_OBJ_CLOSE(m_circleR);
    VFX_OBJ_CLOSE(m_arrowG);
    VFX_OBJ_CLOSE(m_arrowR);

    VfxControl::onDeinit();
}

void VappScreenLockPatternGrid::resetState()
{
    m_state = GRID_STATE_INITED;

    m_dot->setHidden(VFX_FALSE);
    m_circleG->setHidden(VFX_TRUE);
    m_circleR->setHidden(VFX_TRUE);
    m_arrowG->setHidden(VFX_TRUE);
    m_arrowR->setHidden(VFX_TRUE);
}

void VappScreenLockPatternGrid::set1stHit()
{
    if (m_state == GRID_STATE_INITED)
    {
        m_state = GRID_STATE_NORMAL_1ST;
        m_circleG->setHidden(VFX_FALSE);
    }
}

void VappScreenLockPatternGrid::set2ndHit(const VfxPoint &point)
{
    if (m_state == GRID_STATE_NORMAL_1ST)
    {
        m_state = GRID_STATE_NORMAL;

        VfxS32 circleLen = ((m_circleG->getSize().width + 1) / 2);
        VfxS32 pointLen = (VfxS32)sqrt((VfxFloat)point.x*point.x + (VfxFloat)point.y*point.y);
        m_arrowAngle = atan2((VfxFloat)point.y, (VfxFloat)point.x);

        VfxTransform T;
        T.setIdentity();
        T.data.affine.rz = m_arrowAngle;

        /* include gap between images */
        if (point.x)
        {
            T.data.affine.tx = ((VfxFloat)point.x / (VfxFloat)pointLen) * (circleLen + VAPP_SCREEN_LOCK_PATTERN_FRAME_ARROW_GAP);
        }
        if (point.y)
        {
            T.data.affine.ty = ((VfxFloat)point.y / (VfxFloat)pointLen) * (circleLen + VAPP_SCREEN_LOCK_PATTERN_FRAME_ARROW_GAP);
        }

        m_arrowG->setTransform(T);
        m_arrowG->setHidden(VFX_FALSE);

        m_arrowR->setTransform(T);
    }
}

void VappScreenLockPatternGrid::setCheckError()
{
    if (m_state == GRID_STATE_NORMAL_1ST)
    {
        m_circleG->setHidden(VFX_TRUE);
        m_circleR->setHidden(VFX_FALSE);
    }
    else if (m_state == GRID_STATE_NORMAL)
    {
        m_circleG->setHidden(VFX_TRUE);
        m_arrowG->setHidden(VFX_TRUE);

        m_circleR->setHidden(VFX_FALSE);
        m_arrowR->setHidden(VFX_FALSE);
    }
}


VfxBool VappScreenLockPatternGrid::isContainPoint(VfxPenEvent &event)
{
    if (m_state == GRID_STATE_INITED)
    {
        return m_dot->containPoint(event.getRelPos(m_dot));
    }

    return VFX_FALSE;
}

VfxBool VappScreenLockPatternGrid::isValid()
{
    if (m_state == GRID_STATE_INITED)
    {
        return VFX_TRUE;
    }

    return VFX_FALSE;
}


void VappScreenLockPatternGrid::onTimelineStop(VfxBaseTimeline *timeline, VfxBool is_stop)
{
    VFX_OBJ_CLOSE(timeline);
}


VFX_IMPLEMENT_CLASS("VappScreenLockPatternFrame", VappScreenLockPatternFrame, VfxControl);

VappScreenLockPatternFrame::VappScreenLockPatternFrame(VfxS32 width, VfxS32 startY):
    m_width(width),
    m_startY(startY),
    m_locked(VFX_FALSE),
    m_resetTimer(NULL)
{
    m_1stGridIdx = VAPP_SCREEN_LOCK_PATTERN_INVALID_IDX;
    m_2ndGridIdx = VAPP_SCREEN_LOCK_PATTERN_INVALID_IDX;
    for (VfxS32 i = 0; i < VAPP_SCREEN_LOCK_PATTERN_GRIDS_NUMBER; i++)
    {
        m_grid[i] = NULL;
        m_line[i] = NULL;
    }

    resetPattern();
}

void VappScreenLockPatternFrame::onInit()
{
    VfxControl::onInit();

    for (VfxU32 j = 0; j < 3; j++)
    {
        for (VfxU32 i = 0; i < 3; i++)
        {
            VfxU32 idx = j*3 + i;

            VFX_OBJ_CREATE(m_line[idx], VfxImageFrame, this);
            m_line[idx]->setResId(IMG_ID_VAPP_SCREEN_LOCK_PATTERN_LINE);
            m_line[idx]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
            m_line[idx]->setHidden(VFX_TRUE);
            m_line[idx]->setAnchor(0.5, 0.5);
            m_line[idx]->sendToBack();

            VFX_OBJ_CREATE_EX(m_grid[idx], VappScreenLockPatternGrid, this, (m_width / 3, m_width/3));
            m_grid[idx]->setPos(m_width*i/3+m_width/3/2, m_width*j/3 + m_width/3/2 + m_startY);
            m_grid[idx]->setAnchor(0.5, 0.5);
            //m_grid[idx]->setBounds(-(m_sizeX/2), -(m_sizeY/2), m_sizeX/2-1, m_sizeY/2-1);
        }
    }

    m_lineWidth = m_line[0]->getSize().width;

    VFX_OBJ_CREATE(m_resetTimer, VfxTimer, this);
    m_resetTimer->setStartDelay(VAPP_SCREEN_LOCK_PATTERN_RESET_TIME);
    m_resetTimer->m_signalTick.connect(this, &VappScreenLockPatternFrame::onResetTimerCallback);
}

void VappScreenLockPatternFrame::onDeinit()
{
    for (VfxU32 i = 0; i < VAPP_SCREEN_LOCK_PATTERN_GRIDS_NUMBER; i++)
    {
        VFX_OBJ_CLOSE(m_grid[i]);
        VFX_OBJ_CLOSE(m_line[i]);
    }

    VFX_OBJ_CLOSE(m_resetTimer);

    VfxControl::onDeinit();
}

VfxBool VappScreenLockPatternFrame::onPenInput(VfxPenEvent &event)
{
    VfxU32 grid_idx;

    if (m_locked)
    {
        return VFX_FALSE;
    }

    // dispatch event directly
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            resetPattern();

            grid_idx = checkGridOnHit(event);
            if (grid_idx != VAPP_SCREEN_LOCK_PATTERN_INVALID_IDX)
            {
                addPattern(grid_idx, VAPP_SCREEN_LOCK_PATTERN_INVALID_IDX);
                vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN_VIBRATE);
            }
            return VFX_TRUE;

        case VFX_PEN_EVENT_TYPE_MOVE:
            grid_idx = checkGridOnHit(event);
            if (grid_idx != VAPP_SCREEN_LOCK_PATTERN_INVALID_IDX &&
                grid_idx != m_1stGridIdx)
            {
                // check if any grid between 1st & 2nd
                if (m_1stGridIdx != VAPP_SCREEN_LOCK_PATTERN_INVALID_IDX)
                {
                    VfxU32 half_idx;
                    VfxBool b_half = VFX_FALSE;

                    half_idx = (m_1stGridIdx + grid_idx) / 2;

                    if(m_grid[half_idx]->isValid() == VFX_TRUE)
                    {
                        if ((m_1stGridIdx % 2) == 0 && (grid_idx % 2) == 0)
                        {
                            // both even idx
                            if ((half_idx % 2) == 1 &&
                                    (((m_1stGridIdx / 3) == (half_idx / 3) && (half_idx / 3) == (grid_idx / 3)) ||
                                     ((m_1stGridIdx % 3) == (half_idx % 3) && (half_idx % 3) == (grid_idx % 3))
                                    )
                               )
                            {
                                b_half = VFX_TRUE;
                            }
                            else if (half_idx == VAPP_SLK_CENTER_IDX)
                            {
                                b_half = VFX_TRUE;
                            }
                        }
                        else if ((m_1stGridIdx % 2) == 1 && (grid_idx % 2) == 1)
                        {
                            // both odd idx
                            if (half_idx == VAPP_SLK_CENTER_IDX)
                            {
                                b_half = VFX_TRUE;
                            }
                        }

                        if (b_half == VFX_TRUE)
                        {
                            addPattern(half_idx, m_1stGridIdx);
                        }
                    }
                }

                if (m_1stGridIdx != VAPP_SCREEN_LOCK_PATTERN_INVALID_IDX)
                {
                    addPattern(grid_idx, m_1stGridIdx);
                }
                else
                {
                    addPattern(grid_idx, VAPP_SCREEN_LOCK_PATTERN_INVALID_IDX);
                }

                VfxPoint tar;
                tar.x = event.getRelPos(m_grid[m_1stGridIdx]).x - m_width/3/2;
                tar.y = event.getRelPos(m_grid[m_1stGridIdx]).y - m_width/3/2;
                drawLine(m_1stGridIdx, tar);

                vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN_VIBRATE);

                return VFX_TRUE;
            }

            if (m_1stGridIdx != VAPP_SCREEN_LOCK_PATTERN_INVALID_IDX)
            {
                VfxPoint tar;
                tar.x = event.getRelPos(m_grid[m_1stGridIdx]).x - m_width/3/2;
                tar.y = event.getRelPos(m_grid[m_1stGridIdx]).y - m_width/3/2;
                drawLine(m_1stGridIdx, tar);
            }

            break;

        case VFX_PEN_EVENT_TYPE_ABORT:
            //break;

        case VFX_PEN_EVENT_TYPE_UP:
            {
                if (m_1stGridIdx != VAPP_SCREEN_LOCK_PATTERN_INVALID_IDX)
                {
                    // remove last line
                    m_line[m_lineCnt]->setHidden(VFX_TRUE);
                    onPatternHandler();
                }
                return VFX_TRUE;
            }

        default:
            break;
    }
    return VfxControl::onPenInput(event);
}

void VappScreenLockPatternFrame::onPatternHandler()
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_PAGE_ON_UNLOCK_HANDLER, 200);
    m_signalPattern.emit(m_pattern);
}

VfxU32 VappScreenLockPatternFrame::checkGridOnHit(VfxPenEvent &event)
{
    for (VfxU32 i = 0; i < VAPP_SCREEN_LOCK_PATTERN_GRIDS_NUMBER; i++)
    {
        if (m_grid[i]->isContainPoint(event) == VFX_TRUE)
        {
            return i;
        }
    }

    return VAPP_SCREEN_LOCK_PATTERN_INVALID_IDX;
}

void VappScreenLockPatternFrame::addPattern(VfxU32 idx_1, VfxU32 idx_2)
{
    if (idx_2 != VAPP_SCREEN_LOCK_PATTERN_INVALID_IDX)
    {
        m_2ndGridIdx = m_1stGridIdx;
        m_1stGridIdx = idx_1;

        VfxPoint arrow_t;
        arrow_t.x = ((m_grid[m_1stGridIdx]->getPos().x - m_grid[m_2ndGridIdx]->getPos().x) / 2) * 2;
        arrow_t.y = ((m_grid[m_1stGridIdx]->getPos().y - m_grid[m_2ndGridIdx]->getPos().y) / 2) * 2;
        m_grid[m_2ndGridIdx]->set2ndHit(arrow_t);
        m_grid[m_1stGridIdx]->set1stHit();

        drawLine(m_2ndGridIdx, arrow_t);
        m_lineCnt++;
    }
    else
    {
        m_1stGridIdx = idx_1;
        m_grid[m_1stGridIdx]->set1stHit();
    }

    m_pattern[m_patternCnt] = idx_1;
    m_patternCnt++;
}

void VappScreenLockPatternFrame::drawLine(VfxU32 srcIdx, VfxPoint& tar)
{
    VfxFloat arrowAngle;
    VfxU32 len;

    arrowAngle = atan2((VfxFloat)tar.y, (VfxFloat)tar.x);
    len = (VfxU32)sqrt((VfxFloat)tar.x*tar.x+(VfxFloat)tar.y*tar.y) + m_lineWidth; // add each side a line-boundary.

    VfxTransform T;
    T.setIdentity();
    T.data.affine.rz = arrowAngle;
    T.data.affine.tx = (VfxFloat)m_grid[srcIdx]->getPos().x + (tar.x+1)/2; //len / 2;
    T.data.affine.ty = (VfxFloat)m_grid[srcIdx]->getPos().y + (tar.y+1)/2; //m_line[m_1stGridIdx]->getSize().width / 2;
    m_line[m_lineCnt]->setTransform(T);
    m_line[m_lineCnt]->setHidden(VFX_FALSE);

    m_line[m_lineCnt]->setSize(len, m_lineWidth);
}

void VappScreenLockPatternFrame::resetPattern()
{
    memset(m_pattern, 0xFF, sizeof(m_pattern));
    m_patternCnt = 0;
    m_lineCnt = 0;
    m_1stGridIdx = VAPP_SCREEN_LOCK_PATTERN_INVALID_IDX;
    m_2ndGridIdx = VAPP_SCREEN_LOCK_PATTERN_INVALID_IDX;

    if (m_grid[0] != NULL)
    {
        for (VfxU32 i = 0; i < VAPP_SCREEN_LOCK_PATTERN_GRIDS_NUMBER; i++)
        {
            m_grid[i]->resetState();
            m_line[i]->setHidden(VFX_TRUE);
        }
    }

    // stop reset timer if any input or modification
    if (m_resetTimer)
    {
        m_resetTimer->stop();
    }
}

void VappScreenLockPatternFrame::setCheckError()
{
    for (VfxU32 i = 0; i< VAPP_SCREEN_LOCK_PATTERN_GRIDS_NUMBER; i++)
    {
        m_grid[i]->setCheckError();
    }

    // hide line of pen-move.
    m_line[m_lineCnt]->setHidden(VFX_TRUE);

    // start reset timer
    m_resetTimer->start();
}

void VappScreenLockPatternFrame::setLocked(VfxBool enable)
{
    m_locked = enable;
}

void VappScreenLockPatternFrame::onResetTimerCallback(VfxTimer *obj)
{
    resetPattern();
}

#endif // #ifdef __MMI_VUI_SCREEN_LOCK_PATTERN__
