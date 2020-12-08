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
 *  vapp_screen_lock_pattern_frame.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_SCREEN_LOCK_PATTERN_FRAME_H__
#define __VAPP_SCREEN_LOCK_PATTERN_FRAME_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_SCREEN_LOCK_PATTERN__

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"

/*****************************************************************************
 * Define
 *****************************************************************************/
#define VAPP_SCREEN_LOCK_PATTERN_GRIDS_NUMBER   (9)

/*****************************************************************************
 * Typedef
 *****************************************************************************/



/*****************************************************************************
 * Class
 *****************************************************************************/
class VappScreenLockPatternGrid : public VfxControl
{
    VFX_DECLARE_CLASS(VappScreenLockPatternGrid);

    enum GRID_STATE_ENUM
    {
        GRID_STATE_INITED = 0,
        GRID_STATE_NORMAL_1ST = 1,
        GRID_STATE_NORMAL = 2,
        GRID_STATE_ERROR_1ST = 3,
        GRID_STATE_ERROR = 4
    };

// Default Constructor
public:
    VappScreenLockPatternGrid(VfxS32 sizeX = 0, VfxS32 sizeY = 0);

    virtual void onInit();
    virtual void onDeinit();
    VfxBool isContainPoint(VfxPenEvent &event);

    void resetState();
    void set1stHit();
    void set2ndHit(const VfxPoint &point);
    void setCheckError();
    VfxBool isValid();

private:
    void onTimelineStop(VfxBaseTimeline *timeline, VfxBool is_stop);
    VfxS32 m_sizeX;
    VfxS32 m_sizeY;
    GRID_STATE_ENUM m_state;
    VfxImageFrame* m_dot;
    VfxImageFrame* m_circleG;
    VfxImageFrame* m_circleR;
    VfxImageFrame* m_arrowG;
    VfxImageFrame* m_arrowR;
    VfxFloat m_arrowAngle;
};

class VappScreenLockPatternFrame : public VfxControl
{
    VFX_DECLARE_CLASS(VappScreenLockPatternFrame);

// Default Constructor
public:
    VappScreenLockPatternFrame(VfxS32 width = 0, VfxS32 startY = 0);

// Override
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxBool onPenInput(VfxPenEvent &event);
    void setCheckError();
    void resetPattern();
    void setLocked(VfxBool enable);

// Signal
public:
    VfxSignal1 <VfxU8*> m_signalPattern;

private:
    void onPatternHandler();
    VfxU32 checkGridOnHit(VfxPenEvent &event);
    void addPattern(VfxU32 idx_1, VfxU32 idx_2);
    void drawLine(VfxU32 srcIdx, VfxPoint& tar);
    void onResetTimerCallback(VfxTimer *obj);

    VfxS32 m_width;
    VfxS32 m_startY;

    VappScreenLockPatternGrid* m_grid[VAPP_SCREEN_LOCK_PATTERN_GRIDS_NUMBER];
    VfxImageFrame* m_line[VAPP_SCREEN_LOCK_PATTERN_GRIDS_NUMBER];
    VfxU32 m_lineWidth;
    VfxU32 m_lineCnt;
    VfxU32 m_1stGridIdx;
    VfxU32 m_2ndGridIdx;

    VfxU8 m_pattern[VAPP_SCREEN_LOCK_PATTERN_GRIDS_NUMBER];
    VfxU32 m_patternCnt;
    VfxBool m_locked;
    VfxTimer* m_resetTimer;
};

#endif // #ifdef __MMI_VUI_SCREEN_LOCK_PATTERN__

#endif /* __VAPP_SCREEN_LOCK_PATTERN_FRAME_H__ */

