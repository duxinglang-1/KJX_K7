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
 *  vapp_widget_key_alarm.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the clock widget.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER_KEY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "GlobalResDef.h"
#include "vcp_include.h"
#include "Vfx_string.h"
#include "vdat_systime.h"
#include "vapp_widget_def.h"
#include "vapp_widget_key_alarm.h"
#include "mmi_rp_vapp_widget_key_alarm_def.h"
#include "Vapp_widget_def.h"
#include "vapp_widget_native_factory.h"
#include "Vfx_text_frame.h"


//
// Pluto headers
//
extern "C"
{
#include "worldclock.h"
#include "PhoneSetupGprots.h"
#include "DateTimeGprot.h"

#include "AlarmSrvGprot.h"
#include "custom_mmi_default_value.h"
#include "AlarmGprot.h"
#include "AlarmProt.h"
#include "AlarmFrameworkProt.h"
#include "Mmi_rp_app_alarm_def.h"
#include "gdi_include.h"
#include "pixcomfontengine.h"
}


/*****************************************************************************
 * Alarm Item Frame
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(
    "VappWidgetAlarmItemFrame",
    VappWidgetAlarmItemFrame,
    VfxFrame);


VappWidgetAlarmItemFrame::VappWidgetAlarmItemFrame() :
    m_divide_line(NULL),
    m_icon(NULL),
    m_attachment_icon(NULL),
    m_time_str(NULL),
    m_type_str(NULL)
{
    m_state = VAPP_WIDGET_ALARM_STATE_OFF;
    m_original_index = -1;
}


void VappWidgetAlarmItemFrame::onInit()
{
    VfxFrame::onInit(); 

    /* alarm icon */
    VFX_OBJ_CREATE(m_icon, VfxImageFrame, this);
    /* plus icon */
    VFX_OBJ_CREATE(m_attachment_icon, VfxImageFrame, this);
    /* item divide line */
    VFX_OBJ_CREATE(m_divide_line, VfxFrame, this);
	/* alarm time info */
    VFX_OBJ_CREATE(m_time_str, VfxTextFrame, this);
    m_time_str->setString(VFX_WSTR_NULL);
    /* alarm type */
    VFX_OBJ_CREATE(m_type_str, VfxTextFrame, this);
    m_type_str->setString(VFX_WSTR_NULL);
}


void VappWidgetAlarmItemFrame::onDeinit()
{
    VFX_OBJ_CLOSE(m_icon);
    VFX_OBJ_CLOSE(m_attachment_icon);
    VFX_OBJ_CLOSE(m_divide_line);
    VFX_OBJ_CLOSE(m_time_str);
    VFX_OBJ_CLOSE(m_type_str);

    VfxFrame::onDeinit();
}


void VappWidgetAlarmItemFrame::setIcon(VfxS32 res_id)
{    
    VfxS32 item_height = getSize().height;

    if (m_icon)
    {
        m_icon->setResId(res_id);
        m_icon->setHidden(VFX_FALSE);
        m_icon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        if (mmi_fe_is_r2l_state())
        {
            m_icon->setPos(VfxPoint(VAPP_WIDGET_ALARM_ITEM_WIDTH - VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_1 - VAPP_WIDGET_ALARM_ITEM_ICON_WIDTH, (item_height - VAPP_WIDGET_ALARM_ITEM_ICON_HEIGHT) >> 1));
        }
        else
        {
            m_icon->setPos(VfxPoint(VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_1, (item_height - VAPP_WIDGET_ALARM_ITEM_ICON_HEIGHT) >> 1));
        }
        m_icon->setSize(VAPP_WIDGET_ALARM_ITEM_ICON_WIDTH, VAPP_WIDGET_ALARM_ITEM_ICON_HEIGHT);
    }
}


void VappWidgetAlarmItemFrame::setAttachmentIcon(VfxS32 res_id)
{    
    VfxS32 item_height = getSize().height;

    if (m_attachment_icon)
    {
        m_attachment_icon->setResId(res_id);
        m_attachment_icon->setHidden(VFX_FALSE);
        
        if (mmi_fe_is_r2l_state())
        {
            m_attachment_icon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_LEFT);
            m_attachment_icon->setPos(VfxPoint(VAPP_WIDGET_ALARM_ITEM_WIDTH - VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_1 - 1, (item_height - VAPP_WIDGET_ALARM_ITEM_ICON_HEIGHT) >> 1));
        }
        else
        {
            m_attachment_icon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RIGHT);
            m_attachment_icon->setPos(VfxPoint(0, (item_height - VAPP_WIDGET_ALARM_ITEM_ICON_HEIGHT) >> 1));
        }
        m_attachment_icon->setSize(VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_1, VAPP_WIDGET_ALARM_ITEM_ICON_HEIGHT);
    }
}


void VappWidgetAlarmItemFrame::setDivideLine(void)
{    
    if (m_divide_line)
    {
        m_divide_line->setBgColor(VFX_COLOR_WHITE);
        m_divide_line->setOpacity(VAPP_WIDGET_ALARM_ITEMS_DIVIDE_LINE_OPACITY);
        m_divide_line->setHidden(VFX_FALSE);
        m_divide_line->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        m_divide_line->setPos(VfxPoint(0, VAPP_WIDGET_ALARM_ITEM_HEIGHT - VAPP_WIDGET_ALARM_ITEM_DIVIDE_LINE_HEIGHT - 1));
        m_divide_line->setSize(VAPP_WIDGET_ALARM_ITEM_DIVIDE_LINE_WIDTH, VAPP_WIDGET_ALARM_ITEM_DIVIDE_LINE_HEIGHT);
    }
}


void VappWidgetAlarmItemFrame::setTime(const VfxWString &str, const VfxColor &value)
{
    VfxSize str_size;
    VfxS32 item_height = getSize().height;

    if (m_time_str)
    {
        m_time_str->setString(str);
        m_time_str->setHidden(VFX_FALSE);
        m_time_str->setOpacity(VAPP_WIDGET_ALARM_ITEMS_TEXT_OPACITY);
        m_time_str->setColor(value);
    }
    
    if (!m_time_str->getString().isEmpty())
    {
        str_size = m_time_str->getSize();
        if (mmi_fe_is_r2l_state())
        {
            m_time_str->setPos(VfxPoint(
                VAPP_WIDGET_ALARM_ITEM_WIDTH - VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_1 - VAPP_WIDGET_ALARM_ITEM_ICON_WIDTH - VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_2 - str_size.width, 
                (item_height - str_size.height) >> 1));
        }
        else
        {
            m_time_str->setPos(VfxPoint(
                VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_1 + VAPP_WIDGET_ALARM_ITEM_ICON_WIDTH + VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_2, 
                (item_height - str_size.height) >> 1));
        }
    }
}


void VappWidgetAlarmItemFrame::setType(const VfxWString &str)
{
    VfxSize str_size;

    if (m_type_str)
    {
        m_type_str->setString(str);
        m_type_str->setHidden(VFX_FALSE);
        m_type_str->setOpacity(VAPP_WIDGET_ALARM_ITEMS_TEXT_OPACITY);
        m_type_str->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_WIDGET_ALARM_ITEMS_TYPE_FONT_SIZE)));
        m_type_str->setAutoResized(VFX_FALSE);
        m_type_str->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
        m_type_str->setVerticalToCenter(VFX_TRUE);
    }
    
    if (!m_type_str->getString().isEmpty())
    {
        VfxS32 type_str_x;
        if (mmi_fe_is_r2l_state())
        {
            type_str_x = VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_4*2 + 1;
            m_type_str->setPos(VfxPoint(type_str_x, 0));
            m_type_str->setBounds(VfxRect(0, 0, 
                VAPP_WIDGET_ALARM_ITEM_WIDTH - (VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_1 + VAPP_WIDGET_ALARM_ITEM_ICON_WIDTH + VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_2 + getTimeTextWidth() + VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_3) - VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_4, VAPP_WIDGET_ALARM_ITEM_HEIGHT));
        }
        else
        {
            type_str_x = VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_1 + VAPP_WIDGET_ALARM_ITEM_ICON_WIDTH + VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_2 + getTimeTextWidth() + VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_3;
            m_type_str->setPos(VfxPoint(type_str_x, 0));
            m_type_str->setBounds(VfxRect(0, 0, VAPP_WIDGET_ALARM_ITEM_WIDTH - type_str_x - VAPP_WIDGET_ALARM_ITEM_HORIZONTAL_GAP_4, VAPP_WIDGET_ALARM_ITEM_HEIGHT));
        }
    }
}


void VappWidgetAlarmItemFrame::setState(VfxS32 state)
{
    m_state = state;
}


void VappWidgetAlarmItemFrame::setOriginalIndex(VfxS32 state)
{
    m_original_index = state;
}


VfxS32 VappWidgetAlarmItemFrame::getOriginalIndex(void)
{
    return m_original_index;
}


VfxBool VappWidgetAlarmItemFrame::isAlarmStateOn(void)
{
    return (m_state == VAPP_WIDGET_ALARM_STATE_ON) ? VFX_TRUE : VFX_FALSE;
}


VfxS32 VappWidgetAlarmItemFrame::getTimeTextWidth(void)
{
    if (m_time_str && (!m_time_str->getString().isEmpty()))
    {
        VfxSize str_size = m_time_str->getSize();
        return ((str_size.width> VAPP_WIDGET_ALARM_TIME_TEXT_MIN_WIDTH) ? str_size.width: VAPP_WIDGET_ALARM_TIME_TEXT_MIN_WIDTH);
    }
    return 0;
}


/*****************************************************************************
 * Analog Clock Widget
 *****************************************************************************/

VAPP_WIDGET_SYS_PUBLISH_NATIVE(
    VappWidgetKeyAlarm,
    VAPP_WIDGET_TYPE_KEY_ALARM,
    VappWidgetKeyAlarmPublisher);

VAPP_WIDGET_IMPLEMENT_CLASS(VappWidgetKeyAlarm, VappWidget);
VfxS32 VappWidgetKeyAlarm::m_highlight_idx = 0;


VappWidgetKeyAlarm::VappWidgetKeyAlarm() :
    m_bg_img(NULL),
    m_highlight_img(NULL)
{
    // Do nothing.
    m_alarm_item[0] = NULL;
}


VappWidgetId VappWidgetKeyAlarm::getId() const
{
    return VappWidgetId(
            VAPP_WIDGET_SRC_NATIVE,
            VAPP_WIDGET_TYPE_KEY_ALARM);
}


VfxSize VappWidgetKeyAlarm::getMaxSize() const
{
    return VfxSize(VAPP_WIDGET_ALARM_MAX_WIDTH, VAPP_WIDGET_ALARM_MAX_HEIGHT);
}


VfxS32 VappWidgetKeyAlarm::getName(VfxWChar *string, VfxS32 size) const
{
    const VfxWChar *str = vfxSysResGetStr(STR_GLOBAL_ALARM);

    VFX_ASSERT(string && size > 0);

    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);

    return vfx_sys_wcslen(string);
}


VfxFrame *VappWidgetKeyAlarm::createIcon(VfxObject *parentObj)
{
    VfxImageFrame *icon;

    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);
    icon->setResId(IMG_ID_VAPP_WIDGET_ALARM_COMMON_ICON);

    return icon;
}


void VappWidgetKeyAlarm::onCreateView()
{
    VappWidget::onCreateView();
    
    VfxS32 i;

    //
    // Get alarm data
    //
    VfxS32 alarm_num = 0, add_new_alarm_num = 0;
    VfxU8 active_alarm_hour[VAPP_WIDGET_ALARM_ITEMS_NUMBER] = {0}, active_alarm_min[VAPP_WIDGET_ALARM_ITEMS_NUMBER] = {0};
    VfxS32 active_alarm_type[VAPP_WIDGET_ALARM_ITEMS_NUMBER] = {0};
    VfxU8 active_alarm_custom_info[VAPP_WIDGET_ALARM_ITEMS_NUMBER] = {0};
    VfxS32 active_alarm_original_index[VAPP_WIDGET_ALARM_ITEMS_NUMBER] = {0};

    for (i = 0 ; i < VAPP_WIDGET_ALARM_ITEMS_NUMBER ; i ++)
    {
        VfxU8 hour, min, state, freq, days;
        srv_alm_get_info(i, &hour, &min, &state, &freq, &days);

        /* state == 1 --> alarm on; state == 0 --> alarm off */
        if (state)
        {
            /* save and re-order alarm items */
            if (alarm_num == 0)
            {
                active_alarm_hour[alarm_num] = hour;
                active_alarm_min[alarm_num] = min;
                active_alarm_type[alarm_num] = (VfxS32)freq;
                active_alarm_custom_info[alarm_num] = days;
                active_alarm_original_index[alarm_num] = i;
            }
            else if (alarm_num > 0)
            {
                VfxS32 j;
                for (j = alarm_num - 1; j >= 0 ; j --)
                {
                    if (active_alarm_hour[j] * 60 + active_alarm_min[j] > (VfxS32)(hour * 60 + min))
                    {
                        active_alarm_hour[j + 1] = active_alarm_hour[j];
                        active_alarm_min[j + 1] = active_alarm_min[j];
                        active_alarm_type[j + 1] = active_alarm_type[j];
                        active_alarm_custom_info[j + 1] = active_alarm_custom_info[j];
                        active_alarm_original_index[j + 1] = active_alarm_original_index[j];
                    }
                    else
                    {
                        active_alarm_hour[j + 1] = hour;
                        active_alarm_min[j + 1] = min;
                        active_alarm_type[j + 1] = (VfxS32)freq;
                        active_alarm_custom_info[j + 1] = days;
                        active_alarm_original_index[j + 1] = i;
                        j = -1;
                    }
                }
                if (j == -1)
                {
                    active_alarm_hour[0] = hour;
                    active_alarm_min[0] = min;
                    active_alarm_type[0] = (VfxS32)freq;
                    active_alarm_custom_info[0] = days;
                    active_alarm_original_index[0] = i;
                }
            }
            alarm_num++;
        }
    }

    /* add new alarm item */
    if (alarm_num < VAPP_WIDGET_ALARM_ITEMS_NUMBER)
    {
        add_new_alarm_num = 1;
    }
    m_items_num = add_new_alarm_num + alarm_num;
    
    //
    // Get the next active item
    //
    MYTIME curr_time;
    GetDateTime(&curr_time);
	
    /* find out all of alarms in today, and compare with the current time */
    for (i = 0 ; i < alarm_num ; i ++)
    {
        if ((active_alarm_type[i] == ALM_FREQ_ONCE) ||
            (active_alarm_type[i] == ALM_FREQ_EVERYDAY) ||
            ((active_alarm_type[i] == ALM_FREQ_DAYS) && (((active_alarm_custom_info[i] >> curr_time.DayIndex) & 0x01))))
        {
            if ((active_alarm_hour[i] * 60 + active_alarm_min[i]) > ((VfxU8)curr_time.nHour * 60 + (VfxU8)curr_time.nMin))
            {
                break;
            }
        }
    }

    /* if the next item is not on today, try to highlight to tomorrow's */
    if (i == alarm_num)
    {
        for (i = 0 ; i < alarm_num ; i ++)
        {
            if ((active_alarm_type[i] == ALM_FREQ_ONCE) ||
                (active_alarm_type[i] == ALM_FREQ_EVERYDAY) ||
                ((active_alarm_type[i] == ALM_FREQ_DAYS) && (((active_alarm_custom_info[i] >> ((curr_time.DayIndex + 1) % 7)) & 0x01))))
            {
                break;
            }
        }
    }

    /* if the next item is not on tomorrow, try to find it from tomorrow to Saturday */
    if (i == alarm_num)
    {
        VfxS32 j = curr_time.DayIndex + 1;
        for ( ; j < 7 ; j++)
        {
            for (i = 0 ; i < alarm_num ; i ++)
            {
                if (((active_alarm_type[i] == ALM_FREQ_DAYS) && (((active_alarm_custom_info[i] >> j) & 0x01))))
                {
                    break;
                }
            }

            if (i < alarm_num)
            {
                break;
            }
        }
    }

    /* if the next item is not on this week, try to find in next week */
    if (i == alarm_num)
    {
        VfxS32 j = 0;
        for ( ; j < curr_time.DayIndex ; j++)
        {
            for (i = 0 ; i < alarm_num ; i ++)
            {
                if (((active_alarm_type[i] == ALM_FREQ_DAYS) && (((active_alarm_custom_info[i] >> j) & 0x01))))
                {
                    break;
                }
            }

            if (i < alarm_num)
            {
                break;
            }
        }

    }

    /* if we cannot find the next item, take the 1st one as the latest item */
    if ((i >= alarm_num) || (i < 0))
    {
        m_latest_item_idx = 0;
    }
    else
    {
        m_latest_item_idx = i;
    }

    /* set hightlight to the latest highlighted item */
    /* check highlight is vaild or not */
    if ((m_highlight_idx < 0) || (m_highlight_idx >= m_items_num))
    {
        m_highlight_idx = 0;
    }

    //
    // Background image
    //
    VfxS32 items_height = VAPP_WIDGET_ALARM_ITEM_HEIGHT * m_items_num + (VAPP_WIDGET_ALARM_BG_IMG_BORDER << 1);
    VfxS32 image_w, image_h;
    
    /* support 9silce image */
    gdi_image_get_dimension_id(IMG_ID_VAPP_WIDGET_ALARM_BACKGROUND, &image_w, &image_h);
    if (items_height < image_h)
    {
        items_height = image_h;
        m_item_height = (items_height - (VAPP_WIDGET_ALARM_BG_IMG_BORDER << 1)) / m_items_num;
    }
    else
    {
        m_item_height = VAPP_WIDGET_ALARM_ITEM_HEIGHT;
    }
	
    setSize(VAPP_WIDGET_ALARM_MAX_WIDTH, items_height);
    VFX_OBJ_CREATE(m_bg_img, VfxImageFrame, this);
    m_bg_img->setResId(IMG_ID_VAPP_WIDGET_ALARM_BACKGROUND);
    m_bg_img->setSize(VAPP_WIDGET_ALARM_MAX_WIDTH, items_height);
    m_bg_img->setPos(0, 0);
    m_bg_img->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    //
    // Setup highlight image
    //
    VFX_OBJ_CREATE(m_highlight_img, VfxImageFrame, this);
    m_highlight_img->setResId(IMG_ID_VAPP_WIDGET_ALARM_HIGHLIGHT);
    m_highlight_img->setSize(VAPP_WIDGET_ALARM_ITEM_WIDTH, m_item_height - VAPP_WIDGET_ALARM_ITEM_DIVIDE_LINE_HEIGHT);
    moveHighlight(m_highlight_idx);
    m_highlight_img->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    
    //
    // Setup alarm items
    //
    for (i = 0 ; i < alarm_num ; i ++)
    {
        VfxWString temp_str;
        
        VFX_OBJ_CREATE(m_alarm_item[i], VappWidgetAlarmItemFrame, this);
        m_alarm_item[i]->setPos(VAPP_WIDGET_ALARM_BG_IMG_BORDER, (VAPP_WIDGET_ALARM_BG_IMG_BORDER + m_item_height * i));
        m_alarm_item[i]->setSize(VAPP_WIDGET_ALARM_ITEM_WIDTH, m_item_height);
        m_alarm_item[i]->setIcon(IMG_ID_VAPP_WIDGET_ALARM_CLOCK_ICON);
        if (i < (m_items_num - 1))
        {
            m_alarm_item[i]->setDivideLine();
        }

        /* set time */
        temp_str.format("%02d:%02d", active_alarm_hour[i], active_alarm_min[i]);
        if (i == m_latest_item_idx)
        {
            m_alarm_item[i]->setTime(temp_str,VRT_COLOR_MAKE(255, 255, 71, 57)); 
        }
        else
        {
            m_alarm_item[i]->setTime(temp_str,VRT_COLOR_WHITE); 
        }

        /* set state */
        m_alarm_item[i]->setState(VAPP_WIDGET_ALARM_STATE_ON);

        /* set original index */
        m_alarm_item[i]->setOriginalIndex(active_alarm_original_index[i]);

        /* set type */
        switch (active_alarm_type[i])
        {
            case ALM_FREQ_ONCE:
                {
                    m_alarm_item[i]->setType(VFX_WSTR_RES(ALARM_ONCE_STRING));
                }
                break;
                
            case ALM_FREQ_EVERYDAY:
                {
                    m_alarm_item[i]->setType(VFX_WSTR_RES(ALARM_EVREYDAY_STRING));
                }
                break;
                
            case ALM_FREQ_DAYS:
                {
                    VfxWString space_str;
                    VfxWChar space_char[3];
                    kal_wsprintf(space_char, " ");
                    space_str.loadFromMem(space_char);
                                
                    temp_str.setEmpty();
                    for (VfxS32 j = 0; j < 7; j++)
                    {
                        if ((active_alarm_custom_info[i] >> j) & 0x01)
                        {
                            if (!temp_str.isEmpty())
                            {
                                temp_str += space_str;
                            }
                            temp_str += (VFX_WSTR_RES(STR_GLOBAL_SUNDAY_SHORT + j));
                        }
                    }
                    m_alarm_item[i]->setType(temp_str);
                }
                break;

            default:
                    break;
        }
    }

    //
    // Setup the new item
    //
    if (add_new_alarm_num)
    {
        VfxWString temp_str;
        
        VFX_OBJ_CREATE(m_alarm_item[i], VappWidgetAlarmItemFrame, this);
        m_alarm_item[i]->setPos(VAPP_WIDGET_ALARM_BG_IMG_BORDER, (VAPP_WIDGET_ALARM_BG_IMG_BORDER + m_item_height * i));
        m_alarm_item[i]->setSize(VAPP_WIDGET_ALARM_ITEM_WIDTH, m_item_height);
        m_alarm_item[i]->setAttachmentIcon(IMG_ID_VAPP_WIDGET_ALARM_PLUS_ICON);
        m_alarm_item[i]->setIcon(IMG_ID_VAPP_WIDGET_ALARM_CLOCK_ICON);
        
        temp_str.loadFromRes(STR_GLOBAL_ADD);
        m_alarm_item[i]->setTime(temp_str, VRT_COLOR_WHITE);
        m_alarm_item[i]->setState(VAPP_WIDGET_ALARM_STATE_NEW);
    }

    //
    // Register key handler
    //
    registerKeyHandler(VFX_KEY_CODE_ARROW_UP);
    registerKeyHandler(VFX_KEY_CODE_ARROW_DOWN);
    registerKeyHandler(VFX_KEY_CODE_CSK);
}


void VappWidgetKeyAlarm::onReleaseView()
{
    VFX_OBJ_CLOSE(m_bg_img);
    VFX_OBJ_CLOSE(m_highlight_img);
    for (VfxS32 i = 0 ; i < m_items_num ; i ++)
    {
        VFX_OBJ_CLOSE(m_alarm_item[i]);
    }
    VappWidget::onReleaseView();
}


VfxBool VappWidgetKeyAlarm::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN || event.type == VFX_KEY_EVENT_TYPE_REPEAT)
    {
        switch (event.keyCode)
        {
            case VFX_KEY_CODE_ARROW_DOWN:
                {
                    if (m_highlight_idx < m_items_num - 1)
                    {
                        moveHighlight(m_highlight_idx + 1);
                    }
                    else
                    {
                        moveHighlight(0);
                    }
                    return VFX_TRUE;
                }
                break;
                
            case VFX_KEY_CODE_ARROW_UP:
                {
                    if (m_highlight_idx > 0)
                    {
                        moveHighlight(m_highlight_idx - 1);
                    }
                    else
                    {
                        moveHighlight(m_items_num - 1);
                    }
                    return VFX_TRUE;

                }
                break;

            default:
                break;
        }
    }

    /* entry alarm app */
    if (event.type == VFX_KEY_EVENT_TYPE_UP && event.keyCode == VFX_KEY_CODE_CSK)
    {
        entryAlarmApp();
        return VFX_TRUE;
    }
    
    return VfxControl::onKeyInput(event);
}


VfxBool VappWidgetKeyAlarm::onPenInput(VfxPenEvent &event)
{
    VfxPoint pos = event.getRelPos(m_bg_img);
    VfxS32 idx = getAlarmItemIndex(pos);

    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
        case VFX_PEN_EVENT_TYPE_MOVE:
            {
                if ((idx >= 0) && (idx < m_items_num) && (idx != m_highlight_idx))
                {
                    moveHighlight(idx);
                }
                return VFX_TRUE;
            }
            break;
            
        case VFX_PEN_EVENT_TYPE_UP:
            {
                if (idx >= 0 && idx < m_items_num)
                {
                    entryAlarmApp();
                }
                return VFX_TRUE;
            }
            break;

        default:
                break;
    }            
    return VfxControl::onPenInput(event);
}


VfxPoint VappWidgetKeyAlarm::onGetEditButtonOffset()
{
    return VfxPoint(VAPP_WIDGET_ALARM_EDITOR_BUTTON_X, VAPP_WIDGET_ALARM_EDITOR_BUTTON_Y);
}


VfxS32 VappWidgetKeyAlarm::getAlarmItemIndex(VfxPoint pos)
{
    if ((pos.x < VAPP_WIDGET_ALARM_BG_IMG_BORDER) || 
        (pos.x > VAPP_WIDGET_ALARM_BG_IMG_BORDER + VAPP_WIDGET_ALARM_ITEM_WIDTH))
    {
        return -1;
    }
    else if (pos.y < VAPP_WIDGET_ALARM_BG_IMG_BORDER)
    {
        return -1;
    }
    else if (pos.y > VAPP_WIDGET_ALARM_BG_IMG_BORDER + m_item_height * m_items_num)
    {
        return - 1;
    }
    else
    {   
        VfxS32 index = ((pos.y - VAPP_WIDGET_ALARM_BG_IMG_BORDER) / m_item_height);
        if (index > (m_items_num - 1))
        {
            index = (m_items_num - 1);
        }
        return index;
    }    
}


void VappWidgetKeyAlarm::moveHighlight(VfxS32 index)
{
    m_highlight_idx = index;
#ifdef __MMI_MAINLCD_320X240__
    m_highlight_img->setPos(
        VAPP_WIDGET_ALARM_BG_IMG_BORDER, 
        VAPP_WIDGET_ALARM_BG_IMG_BORDER + m_item_height * m_highlight_idx + 1);
#else
    m_highlight_img->setPos(
        VAPP_WIDGET_ALARM_BG_IMG_BORDER, 
        VAPP_WIDGET_ALARM_BG_IMG_BORDER + m_item_height * m_highlight_idx - 1);
#endif
}


void VappWidgetKeyAlarm::entryAlarmApp(void)
{
    if (m_alarm_item[m_highlight_idx]->isAlarmStateOn())
    {
        mmi_alm_entry_alm_eidt_screen(m_alarm_item[m_highlight_idx]->getOriginalIndex());
    }
    else
    {
        EntryAlmMenu();
    }
}


#endif /* defined(__MMI_VUI_LAUNCHER_KEY__) */

