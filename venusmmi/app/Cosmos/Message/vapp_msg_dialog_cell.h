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
 *  vapp_msg_dialog_cell.h
 *
 * Project:
 * --------
 *  Venus 
 *
 * Description:
 * ------------
 *  Message Dialog Cell
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_MSG_DIALOG_CELL_H__
#define __VAPP_MSG_DIALOG_CELL_H__

#include "vcp_var_height_menu.h"
#ifdef __cplusplus
extern "C"
#endif
{
    #include "mmi_rp_vapp_msg_def.h" /* CLR_ID_VAPP_MSG_DIALOG_CELL_TIME/CLR_ID_VAPP_MSG_DIALOG_CELL_TIME_SHADOW */
}

/***************************************************************************** 
 * Class VappMsgDialogCell
 *****************************************************************************/

class VappMsgDialogCell : public VcpVarHeightMenuCell
{
	VFX_DECLARE_CLASS(VappMsgDialogCell);

// Constants
public:
    enum VappMsgDialogCellStyleEnum {
        NORMAL,
        CHECKBOX
    };

    enum VappMsgDialogCellSideEnum {
        LEFT,
        RIGHT
    };

#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) /* QVGA & WQVGA */
    enum {
        BUBBLE_MIN_WIDTH             = 67,
        BUBBLE_MIN_HEIGHT            = 35,
        BUBBLE_EXT_MARGIN_CB         = 45,
        BUBBLE_EXT_MARGIN_LEFT       = 0,
        BUBBLE_EXT_MARGIN_RIGHT      = 0,
        BUBBLE_EXT_MARGIN_TOP        = 0,
        BUBBLE_EXT_MARGIN_TOP_EXT    = 2,
        BUBBLE_EXT_MARGIN_BOTTOM     = 0,
        BUBBLE_EXT_MARGIN_BOTTOM_EXT = 2,
        BUBBLE_INT_MARGIN_LEFT       = 6,
        BUBBLE_INT_MARGIN_RIGHT      = 6,
        BUBBLE_INT_MARGIN_TOP        = 6,
        BUBBLE_INT_MARGIN_BOTTOM     = 6,
        BUBBLE_ARROW_WIDTH           = 5,
        BUBBLE_ARROW_HEIGHT          = 12,
        BUBBLE_ARROW_SPACING         = 1,
        BUBBLE_TIME_MARGIN_TOP       = 0,
        BUBBLE_TIME_OFFSET_LEFT      = 5,
        BUBBLE_TIME_OFFSET_RIGHT     = 5,
        BUBBLE_TIME_FONT_SIZE        = 10,
        CHECKBOX_SIZE                = 24,
        INIT_ANIMATION_OFFSET_X      = 60,
    };
#elif __MMI_MAINLCD_480X800__ /* WVGA */
    enum {
        BUBBLE_MIN_WIDTH             = 122,
        BUBBLE_MIN_HEIGHT            = 57,
        BUBBLE_EXT_MARGIN_CB         = 90,
        BUBBLE_EXT_MARGIN_LEFT       = 0,
        BUBBLE_EXT_MARGIN_RIGHT      = 0,
        BUBBLE_EXT_MARGIN_TOP        = 2,
        BUBBLE_EXT_MARGIN_TOP_EXT    = 4,
        BUBBLE_EXT_MARGIN_BOTTOM     = 2,
        BUBBLE_EXT_MARGIN_BOTTOM_EXT = 4,
        BUBBLE_INT_MARGIN_LEFT       = 14,
        BUBBLE_INT_MARGIN_RIGHT      = 14,
        BUBBLE_INT_MARGIN_TOP        = 14,
        BUBBLE_INT_MARGIN_BOTTOM     = 14,
        BUBBLE_ARROW_WIDTH           = 9,
        BUBBLE_ARROW_HEIGHT          = 14,
        BUBBLE_ARROW_SPACING         = 1,
        BUBBLE_TIME_MARGIN_TOP       = 0,
        BUBBLE_TIME_OFFSET_LEFT      = 7,
        BUBBLE_TIME_OFFSET_RIGHT     = 7,
        BUBBLE_TIME_FONT_SIZE        = 18,
        CHECKBOX_SIZE                = 42,
        INIT_ANIMATION_OFFSET_X      = 120,
    };
#elif __MMI_MAINLCD_320X480__ /* HVGA */
    enum {
        BUBBLE_MIN_WIDTH             = 82,
        BUBBLE_MIN_HEIGHT            = 37,
        BUBBLE_EXT_MARGIN_CB         = 60,
        BUBBLE_EXT_MARGIN_LEFT       = 0,
        BUBBLE_EXT_MARGIN_RIGHT      = 0,
        BUBBLE_EXT_MARGIN_TOP        = 1,
        BUBBLE_EXT_MARGIN_TOP_EXT    = 3,
        BUBBLE_EXT_MARGIN_BOTTOM     = 1,
        BUBBLE_EXT_MARGIN_BOTTOM_EXT = 3,
        BUBBLE_INT_MARGIN_LEFT       = 8,
        BUBBLE_INT_MARGIN_RIGHT      = 8,
        BUBBLE_INT_MARGIN_TOP        = 8,
        BUBBLE_INT_MARGIN_BOTTOM     = 8,
        BUBBLE_ARROW_WIDTH           = 7,
        BUBBLE_ARROW_HEIGHT          = 12,
        BUBBLE_ARROW_SPACING         = 2,
        BUBBLE_TIME_MARGIN_TOP       = 0,
        BUBBLE_TIME_OFFSET_LEFT      = 6,
        BUBBLE_TIME_OFFSET_RIGHT     = 6,
        BUBBLE_TIME_FONT_SIZE        = 11,
        CHECKBOX_SIZE                = 30,
        INIT_ANIMATION_OFFSET_X      = 80,
    };
#endif
    enum { /* common */
        BUBBLE_TIME_FONT_COLOR_LEFT  = CLR_ID_VAPP_MSG_DIALOG_CELL_TIME_LEFT,
        BUBBLE_TIME_FONT_COLOR_RIGHT = CLR_ID_VAPP_MSG_DIALOG_CELL_TIME_RIGHT,
        BUBBLE_TIME_SHADOW_COLOR     = CLR_ID_VAPP_MSG_DIALOG_CELL_TIME_SHADOW,
        BUBBLE_TIME_SHADOW_DEGREE    = 270,
        BUBBLE_TIME_SHADOW_DISTANCE  = 1,
        BUBBLE_TIME_SHADOW_RANGE     = 0,
        BUBBLE_TIME_SHADOW_INTENSITY = 80,
        CHECKBOX_EXT_MARGIN_LEFT     = (BUBBLE_EXT_MARGIN_CB - CHECKBOX_SIZE) / 2,
        CHECKBOX_EXT_MARGIN_TOP      = BUBBLE_EXT_MARGIN_TOP,
        INIT_ANIMATION_DURATION      = 500,
        INIT_ANIMATION_DELAY         = 120,
        CB_ANIMATION_DURATION        = 250,
    };

// Constructor / Destructor
public:
    VappMsgDialogCell(VcpMenuPos menupos, VappMsgDialogCellSideEnum side, VappMsgDialogCellStyleEnum style = VappMsgDialogCell::NORMAL);

// Property
public:
    VappMsgDialogCellStyleEnum getStyle();
    VappMsgDialogCellSideEnum getSide();
    VfxFrame *getContentFrame();

    void setMark(VfxBool isMark);
    void setStyle(VappMsgDialogCellStyleEnum style, VfxBool with_animation = VFX_FALSE);
    void setSide(VappMsgDialogCellSideEnum side, VfxBool force = VFX_FALSE);
    void setTime(const VfxWString &value); 
    void setContentFrame(VfxFrame *content);    
    void setDisabled(VfxBool disabled);
    void setReadyForAnimation(VfxBool isReady);

// Method
public:
    virtual void prepareAnimation();
    virtual void playAnimation(VfxU32 start_seq);
    virtual void finishAnimation();

// Event
public:
    VfxSignal2 <VfxControl*, VfxBool>  m_signalMarked;
    VfxSignal0 m_signalAnimationPlayed;

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onUpdate();

// Overridable
public:
    virtual VfxRect getHitRect();
    virtual void setHighlight(VfxBool isHighlight);
    virtual void onBoundsChanged(VfxFrame *frame, const VfxRect &rect);
    virtual VfxBool isReadyForAnimation() ;

// Overridable
protected:    
    virtual void forceUpdateContent() = 0;
    virtual VfxBool isDisabled() = 0;
    void needRelayout();
    virtual void reLayoutAllItems();

// Implementation
private:
    void onMarkClicked(VfxObject *obj, VfxId id);
    void onContentBoundsChanged(VfxFrame *frame, const VfxRect &rect);
    void onCellTapped(VcpVarHeightMenuCell *varHeightCell);
    void onTimelineStopped(VfxBaseTimeline *timline, VfxBool isComplete);


    VfxBool m_isUpdate;
    VfxBool m_isMarked;
    VfxBool m_isDisabled;
    VfxBool m_isReadyForAnimation;
    VappMsgDialogCellStyleEnum m_style;
    VappMsgDialogCellSideEnum m_side;

    VcpImageButton *m_checkbox;          /* for mark several */
    VfxFrame *m_container;              /* contain bubble, arrow, time */
    VfxFrame *m_bubble;                 /* for body background and corner */
    VfxFrame *m_bubbleMask;
    VfxFrame *m_content;
    VfxTextFrame *m_timeText;           /* for time display text */
    VfxFontEffect *m_timeFontEffect;
    VfxFrame *m_arrow;
    VfxFrame *m_arrowMask;

    VfxFloatTimeline *m_tl_init_opacity;
    VfxS32Timeline *m_tl_init_pos_x;
    VfxS32Timeline *m_tl_style_pos_x;
    VfxS32Timeline *m_tl_style_cb_pos_x;
};

#endif /* __VAPP_MSG_DIALOG_CELL_H__ */

