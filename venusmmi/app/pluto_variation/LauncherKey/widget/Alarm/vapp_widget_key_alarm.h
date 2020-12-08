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
 *  vapp_widget_key_alarm.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the clock widget.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_WIDGET_KEY_ALARM_H
#define VAPP_WIDGET_KEY_ALARM_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER_KEY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vcp_include.h"
#include "vapp_widget_def.h"
#include "vapp_widget.h"
#include "vapp_widget_def.h"
#include "vapp_widget.h"

/*****************************************************************************
 * define
 *****************************************************************************/
 /* 
 *    Alarm item internal layout :
 * //////////////////////////////////////////////////
 * //      | I |      |       |      |      |      //
 * // gap1 | c | gap2 | Time  | gap3 | Type | gap4 //
 * //(plus | o |      | text  |      | text |      //
 * // icon)| n |      |       |      |      |      //
 * //////////////////////////////////////////////////
 */

#if defined(__MMI_MAINLCD_240X320__)
    #define VAPP_WIDGET_ALARM_ITEMS_NUMBER    (5)
    #define VAPP_WIDGET_ALARM_ITEMS_TEXT_OPACITY    (0.8f)
    #define VAPP_WIDGET_ALARM_ITEMS_DIVIDE_LINE_OPACITY    (0.7f)
    #define VAPP_WIDGET_ALARM_ITEMS_TIME_FONT_SIZE    (13)
    #define VAPP_WIDGET_ALARM_ITEMS_TYPE_FONT_SIZE    (11)

    #define VAPP_WIDGET_ALARM_MAX_WIDTH    (200)
    #define VAPP_WIDGET_ALARM_MAX_HEIGHT    (179)
    #define VAPP_WIDGET_ALARM_BG_IMG_BORDER    (7)
    #define VAPP_WIDGET_ALARM_ITEM_WIDTH      (VAPP_WIDGET_ALARM_MAX_WIDTH - (VAPP_WIDGET_ALARM_BG_IMG_BORDER << 1))
    #define VAPP_WIDGET_ALARM_ITEM_HEIGHT     ((VAPP_WIDGET_ALARM_MAX_HEIGHT - (VAPP_WIDGET_ALARM_BG_IMG_BORDER << 1)) / VAPP_WIDGET_ALARM_ITEMS_NUMBER)
    #define VAPP_WIDGET_ALARM_ITEM_ICON_WIDTH        (24)
    #define VAPP_WIDGET_ALARM_ITEM_ICON_HEIGHT        (24)
    #define VAPP_WIDGET_ALARM_ITEM_DIVIDE_LINE_WIDTH        (VAPP_WIDGET_ALARM_ITEM_WIDTH)
    #define VAPP_WIDGET_ALARM_ITEM_DIVIDE_LINE_HEIGHT        (1)
    #define VAPP_WIDGET_ALARM_TIME_TEXT_MIN_WIDTH        (45)

    #define VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_1    (20)
    #define VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_2    (3)
    #define VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_3    (3)
    #define VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_4    (3)

    #define VAPP_WIDGET_ALARM_EDITOR_BUTTON_X    (150)
    #define VAPP_WIDGET_ALARM_EDITOR_BUTTON_Y    (20)

#elif defined(__MMI_MAINLCD_240X400__)

    #define VAPP_WIDGET_ALARM_ITEMS_NUMBER    (5)
    #define VAPP_WIDGET_ALARM_ITEMS_TEXT_OPACITY    (0.8f)
    #define VAPP_WIDGET_ALARM_ITEMS_DIVIDE_LINE_OPACITY    (0.7f)
    #define VAPP_WIDGET_ALARM_ITEMS_TIME_FONT_SIZE    (13)
    #define VAPP_WIDGET_ALARM_ITEMS_TYPE_FONT_SIZE    (11)

    #define VAPP_WIDGET_ALARM_MAX_WIDTH    (200)
    #define VAPP_WIDGET_ALARM_MAX_HEIGHT    (199)
    #define VAPP_WIDGET_ALARM_BG_IMG_BORDER    (7)
    #define VAPP_WIDGET_ALARM_ITEM_WIDTH      (VAPP_WIDGET_ALARM_MAX_WIDTH - (VAPP_WIDGET_ALARM_BG_IMG_BORDER << 1))
    #define VAPP_WIDGET_ALARM_ITEM_HEIGHT     ((VAPP_WIDGET_ALARM_MAX_HEIGHT - (VAPP_WIDGET_ALARM_BG_IMG_BORDER << 1)) / VAPP_WIDGET_ALARM_ITEMS_NUMBER)
    #define VAPP_WIDGET_ALARM_ITEM_ICON_WIDTH        (24)
    #define VAPP_WIDGET_ALARM_ITEM_ICON_HEIGHT        (24)
    #define VAPP_WIDGET_ALARM_ITEM_DIVIDE_LINE_WIDTH        (VAPP_WIDGET_ALARM_ITEM_WIDTH)
    #define VAPP_WIDGET_ALARM_ITEM_DIVIDE_LINE_HEIGHT        (1)
    #define VAPP_WIDGET_ALARM_TIME_TEXT_MIN_WIDTH        (45)

    #define VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_1    (20)
    #define VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_2    (3)
    #define VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_3    (3)
    #define VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_4    (3)

    #define VAPP_WIDGET_ALARM_EDITOR_BUTTON_X    (150)
    #define VAPP_WIDGET_ALARM_EDITOR_BUTTON_Y    (20)

#elif defined(__MMI_MAINLCD_320X480__)

    #define VAPP_WIDGET_ALARM_ITEMS_NUMBER    (5)
    #define VAPP_WIDGET_ALARM_ITEMS_TEXT_OPACITY    (0.8f)
    #define VAPP_WIDGET_ALARM_ITEMS_DIVIDE_LINE_OPACITY    (0.5f)
    #define VAPP_WIDGET_ALARM_ITEMS_TIME_FONT_SIZE    (18)
    #define VAPP_WIDGET_ALARM_ITEMS_TYPE_FONT_SIZE    (13)

    #define VAPP_WIDGET_ALARM_MAX_WIDTH    (248)
    #define VAPP_WIDGET_ALARM_MAX_HEIGHT    (251)
    #define VAPP_WIDGET_ALARM_BG_IMG_BORDER    (8)
    #define VAPP_WIDGET_ALARM_ITEM_WIDTH      (VAPP_WIDGET_ALARM_MAX_WIDTH - (VAPP_WIDGET_ALARM_BG_IMG_BORDER << 1))
    #define VAPP_WIDGET_ALARM_ITEM_HEIGHT     ((VAPP_WIDGET_ALARM_MAX_HEIGHT - (VAPP_WIDGET_ALARM_BG_IMG_BORDER << 1)) / VAPP_WIDGET_ALARM_ITEMS_NUMBER)
    #define VAPP_WIDGET_ALARM_ITEM_ICON_WIDTH        (35)
    #define VAPP_WIDGET_ALARM_ITEM_ICON_HEIGHT        (35)
    #define VAPP_WIDGET_ALARM_ITEM_DIVIDE_LINE_WIDTH        (VAPP_WIDGET_ALARM_ITEM_WIDTH)
    #define VAPP_WIDGET_ALARM_ITEM_DIVIDE_LINE_HEIGHT        (1)
    #define VAPP_WIDGET_ALARM_TIME_TEXT_MIN_WIDTH        (50)

    #define VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_1    (20)
    #define VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_2    (7)
    #define VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_3    (6)
    #define VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_4    (6)

    #define VAPP_WIDGET_ALARM_EDITOR_BUTTON_X    (220)
    #define VAPP_WIDGET_ALARM_EDITOR_BUTTON_Y    (20)

#elif defined(__MMI_MAINLCD_320X240__)

    #define VAPP_WIDGET_ALARM_ITEMS_NUMBER    (5)
    #define VAPP_WIDGET_ALARM_ITEMS_TEXT_OPACITY    (0.8f)
    #define VAPP_WIDGET_ALARM_ITEMS_DIVIDE_LINE_OPACITY    (0.7f)
    #define VAPP_WIDGET_ALARM_ITEMS_TIME_FONT_SIZE    (13)
    #define VAPP_WIDGET_ALARM_ITEMS_TYPE_FONT_SIZE    (11)

    #define VAPP_WIDGET_ALARM_MAX_WIDTH    (220)
    #define VAPP_WIDGET_ALARM_MAX_HEIGHT    (169)
    #define VAPP_WIDGET_ALARM_BG_IMG_BORDER    (7)
    #define VAPP_WIDGET_ALARM_ITEM_WIDTH      (VAPP_WIDGET_ALARM_MAX_WIDTH - (VAPP_WIDGET_ALARM_BG_IMG_BORDER << 1))
    #define VAPP_WIDGET_ALARM_ITEM_HEIGHT     ((VAPP_WIDGET_ALARM_MAX_HEIGHT - (VAPP_WIDGET_ALARM_BG_IMG_BORDER << 1)) / VAPP_WIDGET_ALARM_ITEMS_NUMBER)
    #define VAPP_WIDGET_ALARM_ITEM_ICON_WIDTH        (21)
    #define VAPP_WIDGET_ALARM_ITEM_ICON_HEIGHT        (21)
    #define VAPP_WIDGET_ALARM_ITEM_DIVIDE_LINE_WIDTH        (VAPP_WIDGET_ALARM_ITEM_WIDTH)
    #define VAPP_WIDGET_ALARM_ITEM_DIVIDE_LINE_HEIGHT        (1)
    #define VAPP_WIDGET_ALARM_TIME_TEXT_MIN_WIDTH        (45)

    #define VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_1    (20)
    #define VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_2    (6)
    #define VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_3    (6)
    #define VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_4    (6)

    #define VAPP_WIDGET_ALARM_EDITOR_BUTTON_X    (150)
    #define VAPP_WIDGET_ALARM_EDITOR_BUTTON_Y    (20)

#else  /* __MMI_MAINLCD_240X320__ */

    #define VAPP_WIDGET_ALARM_ITEMS_NUMBER    (5)
    #define VAPP_WIDGET_ALARM_ITEMS_TEXT_OPACITY    (0.8f)
    #define VAPP_WIDGET_ALARM_ITEMS_DIVIDE_LINE_OPACITY    (0.7f)
    #define VAPP_WIDGET_ALARM_ITEMS_TIME_FONT_SIZE    (13)
    #define VAPP_WIDGET_ALARM_ITEMS_TYPE_FONT_SIZE    (11)

    #define VAPP_WIDGET_ALARM_MAX_WIDTH    (200)
    #define VAPP_WIDGET_ALARM_MAX_HEIGHT    (199)
    #define VAPP_WIDGET_ALARM_BG_IMG_BORDER    (7)
    #define VAPP_WIDGET_ALARM_ITEM_WIDTH      (VAPP_WIDGET_ALARM_MAX_WIDTH - (VAPP_WIDGET_ALARM_BG_IMG_BORDER << 1))
    #define VAPP_WIDGET_ALARM_ITEM_HEIGHT     ((VAPP_WIDGET_ALARM_MAX_HEIGHT - (VAPP_WIDGET_ALARM_BG_IMG_BORDER << 1)) / VAPP_WIDGET_ALARM_ITEMS_NUMBER)
    #define VAPP_WIDGET_ALARM_ITEM_ICON_WIDTH        (22)
    #define VAPP_WIDGET_ALARM_ITEM_ICON_HEIGHT        (22)
    #define VAPP_WIDGET_ALARM_ITEM_DIVIDE_LINE_WIDTH        (VAPP_WIDGET_ALARM_ITEM_WIDTH)
    #define VAPP_WIDGET_ALARM_ITEM_DIVIDE_LINE_HEIGHT        (1)
    #define VAPP_WIDGET_ALARM_TIME_TEXT_MIN_WIDTH        (45)

    #define VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_1    (16)
    #define VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_2    (3)
    #define VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_3    (3)
    #define VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_4    (3)

    #define VAPP_WIDGET_ALARM_EDITOR_BUTTON_X    (150)
    #define VAPP_WIDGET_ALARM_EDITOR_BUTTON_Y    (20)

#endif /* __MMI_MAINLCD_240X320__ */

#define VAPP_WIDGET_ALARM_STATE_ON     (1)
#define VAPP_WIDGET_ALARM_STATE_OFF    (2)
#define VAPP_WIDGET_ALARM_STATE_NEW    (3)

/*****************************************************************************
 * Alarm Item Frame
 *****************************************************************************/

class VappWidgetAlarmItemFrame : public VfxFrame
{
    VFX_DECLARE_CLASS(VappWidgetAlarmItemFrame);

// Constructor / Destructor
public:
    VappWidgetAlarmItemFrame();

// Method
public:
    void setIcon(VfxS32 res_id);
    void setAttachmentIcon(VfxS32 res_id);
    void setDivideLine(void);
    void setTime(const VfxWString &str, const VfxColor &value);
    void setType(const VfxWString &str);
    void setState(VfxS32 state);
    void setOriginalIndex(VfxS32 state);
    VfxS32 getOriginalIndex();
    VfxBool isAlarmStateOn();

protected:
    virtual void onInit();
    virtual void onDeinit();
    
private:
    VfxS32 getTimeTextWidth();

// Variable
private:
    /* divide line between the two items */
    VfxFrame *m_divide_line;
    /* alarm icon frame */
    VfxImageFrame *m_icon;
    /* plus icon frame */
    VfxImageFrame *m_attachment_icon;
    /* alarm time info, format is "00:00"  */
    VfxTextFrame   *m_time_str;
    /* alarm repeat type, everyday / once / speical DOWs */
    VfxTextFrame   *m_type_str;
    /* alarm item index in alarm app(pluto) */
    VfxS32        m_original_index;
    /* alarm item state, on / off / new item */
    VfxS32        m_state;
};

/*****************************************************************************
 * Analog Clock Widget
 *****************************************************************************/

class VappWidgetKeyAlarm : public VappWidget
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidgetKeyAlarm);

// Constructor / Destructor
public:
    VappWidgetKeyAlarm();

// Method
public:
    virtual VappWidgetId getId() const;
    virtual VfxSize getMaxSize() const;
    virtual VfxS32 getName(VfxWChar *string, VfxS32 size) const;
    virtual VfxFrame *createIcon(VfxObject *parentObj);

protected:
    virtual void onCreateView();
    virtual void onReleaseView();
    virtual VfxPoint onGetEditButtonOffset();
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    virtual VfxBool onPenInput(VfxPenEvent &event);

private:
    VfxS32 getAlarmItemIndex(VfxPoint pos);
    void moveHighlight(VfxS32 index);
    void entryAlarmApp();
        
// Variable
private:
    /* highlight index */
    static VfxS32 m_highlight_idx;
    /* highlight index */
    VfxS32 m_latest_item_idx;
    /* num of items */
    VfxS32 m_items_num;
    /* background image frame */
    VfxImageFrame *m_bg_img;
    /* highlight image frame */
    VfxImageFrame *m_highlight_img;
    /* alarm items frame */
    VappWidgetAlarmItemFrame *m_alarm_item[VAPP_WIDGET_ALARM_ITEMS_NUMBER];
    /* one item height */
    VfxS32 m_item_height;
};


#endif /* defined(__MMI_VUI_LAUNCHER_KEY__) */
#endif /* VAPP_WIDGET_KEY_ALARM_H */

