/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vapp_widget_flip_clock.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines widget flip clock class.
 *
 * Author:
 * -------
 * 
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

#include "MMI_features.h"

#ifdef __MMI_VUI_WIDGET_FLIP_CLOCK__

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_widget_def.h"
#include "vapp_widget_native_factory.h"
#include "vapp_widget_flip_clock.h"
#include "vcp_include.h"
#include "data\vdat_systime.h"
#include "mmi_rp_vapp_widget_flip_clock_def.h"
#include "vcui_worldclock_select_city_gprot.h"
#include "vapp_worldclock_gprot.h"

#ifdef __cplusplus
    extern "C"
    {
#endif
#include "GlobalResDef.h"
#ifdef __cplusplus
    }
#endif


/***************************************************************************** 
 * Class VcpFlipClockPage
 *****************************************************************************/

VappFlipClockPage::VappFlipClockPage():
    m_font_color(VFX_COLOR_BLACK),
    is_left_align(VFX_TRUE),
    m_index(-1)
{    
    m_string.setNull();
    m_str_pos.setZero();
    m_num1_pos.setZero();
    m_num1_pos.setZero();
    m_string_size.setZero();
    m_num1=NULL;
    m_num2=NULL;
    m_bg=NULL;
}


void VappFlipClockPage::setBackGround(VfxResId bg_id)
{
    m_bg=vrt_sys_res_image_lock(bg_id);
    invalidate();
}


void VappFlipClockPage::setNumber(VfxResId num1,VfxPoint num1_pos,VfxResId num2,VfxPoint num2_pos)
{
    m_num1=vrt_sys_res_image_lock(num1);
    m_num2=vrt_sys_res_image_lock(num2);
    m_num1_res=num1;
    m_num2_res=num2;
    m_num1_pos=num1_pos;
    m_num2_pos=num2_pos;
    invalidate();
}


void VappFlipClockPage::getNumber(VfxResId *num1,VfxResId *num2)
{
    *num1=m_num1_res;
    *num2=m_num2_res;
}


void VappFlipClockPage::setString(const VfxWString &value,const VfxFontDesc &fontDesc,VfxColor font_color,VfxPoint pos,VfxBool left_align)
{
    m_font=fontDesc;
    m_font_color=font_color;
    m_str_pos=pos;
    is_left_align=left_align;
	
    if ((m_string != value)||(m_string.isNull()))
    {
        vrt_font_struct vrtFont;
        m_font.initVrtFont(vrtFont);
        m_string_size=vrt_sys_font_measure_str(&vrtFont,value);
    }
	m_string=value;
	
    invalidate();
}


VfxWString &VappFlipClockPage::getString()
{
    return m_string;
}


void VappFlipClockPage::setIndex(VfxS32 index)
{
    m_index=index;
}


VfxS32 VappFlipClockPage::getIndex()
{
    return m_index;
}


void VappFlipClockPage::onInit()
{
    VfxFrame::onInit();
    m_bg=vrt_sys_res_image_lock(0);
    m_num1=vrt_sys_res_image_lock(0);
    m_num2=vrt_sys_res_image_lock(0);
}


void VappFlipClockPage::onDeinit()
{
    VfxFrame::onDeinit();
}


void VappFlipClockPage::onDraw(VfxDrawContext &dc)
{
    VfxRect bounds = getBounds();

    // Draw background image
    if (m_bg != NULL)
    {
        dc.drawResizedImageFromMem(VfxRect(0, 0,bounds.size.width,bounds.size.height), m_bg);          
    }
    // Draw left number of one page
    if (m_num1!=NULL)
    {
        dc.drawImageFromMem(m_num1_pos.x, m_num1_pos.y, m_num1);
    }
    // Draw right number of one page
    if (m_num2!=NULL)
    {
        dc.drawImageFromMem(m_num2_pos.x, m_num2_pos.y, m_num2);
    }
    // Draw string 
    if (!m_string.isNull())
    {        
        vrt_font_struct vrtFont;
        m_font.initVrtFont(vrtFont);
        dc.setFont(m_font);
        dc.setFillColor(m_font_color);
        vrt_text_dir_type_enum dir=vrt_sys_get_text_dir();
        if(dir==MG_TEXT_DIR_TYPE_R2L) // System language align mode is right to left
        {
            if(is_left_align) // String align in left of page 
                dc.drawText(m_str_pos.x+m_string_size.width,m_str_pos.y,m_string);
            else
                dc.drawText(m_str_pos.x,m_str_pos.y,m_string);
        }
        else
        {
            if(is_left_align)
                dc.drawText(m_str_pos.x,m_str_pos.y,m_string);
            else
                dc.drawText(m_str_pos.x-m_string_size.width,m_str_pos.y,m_string);
        }
    }
}


/***************************************************************************** 
 * Class VfxScreen
 *****************************************************************************/
#ifdef __cplusplus
    extern "C"
    {
    extern U8 PhnsetGetTimeFormat(void);
    }
#endif


VAPP_WIDGET_SYS_PUBLISH_NATIVE(
    VappWidgetFlipClock,
    VAPP_WIDGET_TYPE_FLIP_CLOCK,
    VappWidgetFlipClockPublisher);


VAPP_WIDGET_IMPLEMENT_CLASS(VappWidgetFlipClock, VappWidget);


VappWidgetFlipClock::VappWidgetFlipClock() :
    m_bg(NULL),
    need_animation(VFX_TRUE),
    disable_swipe(VFX_FALSE),
    is_swiping(VFX_FALSE),
    m_page_right_top(NULL),
    m_page_left_top(NULL),  
    m_page_left_bottom(NULL),
    m_page_right_bottom(NULL)
{ 
    m_formatFlags=VFX_DATE_TIME_DATE_YEAR|VFX_DATE_TIME_DATE_MONTH|VFX_DATE_TIME_DATE_DAY;
}


VappWidgetId VappWidgetFlipClock::getId() const
{
    return VappWidgetId(VAPP_WIDGET_SRC_NATIVE, VAPP_WIDGET_TYPE_FLIP_CLOCK);
}


VfxSize VappWidgetFlipClock::getMaxSize() const
{
    return VfxSize(MAX_SIZE_WIDTH, MAX_SIZE_HEIGHT);
}


VfxS32 VappWidgetFlipClock::getName(VfxWChar *string, VfxS32 size) const
{
    const VfxWChar *str = vfxSysResGetStr(STR_ID_APP_HOME_WIDGET_FLIP_CLOCK);

    VFX_ASSERT(string && size > 0);

    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);

    return vfx_sys_wcslen(string);
}


VfxFrame *VappWidgetFlipClock::createIcon(VfxObject *parentObj)
{
    VfxImageFrame *icon;
 
    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);
    icon->setResId(IMG_FCLOCK_WIDGET_ICON);
 
    return icon;
}


void VappWidgetFlipClock::onCreateView()
{
    VappWidget::onCreateView();
 
    setBounds(VfxRect(0, 0, WIDTH, HEIGHT));
     
    // Background image
    VFX_OBJ_CREATE(m_bg, VfxImageFrame, this);
    m_bg->setResId(IMG_FCLOCK_WIDGET_BG);
    m_bg->setBounds(VfxRect(0, 0, WIDTH, HEIGHT));

    VFX_OBJ_CREATE(m_bg_timeline,VfxFrame,this);

    // Font style
    m_font.size=VFX_FONT_DESC_VF_SIZE(DATE_FONT_SIZE);
    m_effect = NULL;
    VFX_ALLOC_NEW(m_effect, VfxFontEffect, this);
    m_effect->setType(VFX_FONT_EFFECT_SHADOW);
    m_effect->setShadow(
        VFX_COLOR_WHITE,                 // shadow color
        -90,                             // degree of shadow 
        1,                               // distant between the shadow original to the text original
        0,                               // shadow range
        40                               // shadow intensity
    );
    m_font.effect = m_effect->getEffectId();
    m_color=VfxColor(0,60,60,60);

    // Create four pages
    m_dt.setCurrentTime();
    CreateFlipClock(m_dt);

    // Background translate frame
    VFX_OBJ_CREATE(m_bg_frame, VfxImageFrame, this);
    m_bg_frame->setBounds(VfxRect(0, 0, WIDTH, HEIGHT));
    
    // Create N-page animation frame
    for (VfxU8 i = 0; i < MAX_PAGE_COUNT; i++)
    {
        VFX_OBJ_CREATE(m_left_shadow[i],VappFlipClockPage,m_bg_frame);
        m_left_shadow[i]->setBounds(0,0,PAGE_WIDTH,PAGE_HEIGHT);
        m_left_shadow[i]->setImgContent(VfxImageSrc(IMG_FCLOCK_WIDGET_LEFT_SHADOW));
        m_left_shadow[i]->setPos(VfxPoint(getSize().width/2-PAGE_WIDTH,PAGE_Y));
        m_left_shadow[i]->setHidden(VFX_TRUE);
        m_left_shadow[i]->setIndex(MAX_PAGE_COUNT*4);
        m_left_shadow[i]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
                
        VFX_OBJ_CREATE(m_right_shadow[i],VappFlipClockPage,m_bg_frame);
        m_right_shadow[i]->setBounds(0,0,PAGE_WIDTH,PAGE_HEIGHT);
        m_right_shadow[i]->setImgContent(VfxImageSrc(IMG_FCLOCK_WIDGET_RIGHT_SHADOW));
        m_right_shadow[i]->setPos(VfxPoint(getSize().width/2,PAGE_Y));
        m_right_shadow[i]->setHidden(VFX_TRUE);
        m_right_shadow[i]->setIndex(MAX_PAGE_COUNT*4);
        m_right_shadow[i]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

        VFX_OBJ_CREATE(m_page_right_top_temp[MAX_PAGE_COUNT-i-1], VappFlipClockPage, m_bg_frame);
        m_page_right_top_temp[MAX_PAGE_COUNT-i-1]->setBackGround(IMG_FCLOCK_WIDGET_RIGHT_TOP);
        m_page_right_top_temp[MAX_PAGE_COUNT-i-1]->setBounds(VfxRect(0, 0, PAGE_WIDTH, PAGE_HEIGHT));
        m_page_right_top_temp[MAX_PAGE_COUNT-i-1]->setPos(VfxPoint(0,0));
        m_page_right_top_temp[MAX_PAGE_COUNT-i-1]->setHidden(VFX_TRUE);
        m_page_right_top_temp[MAX_PAGE_COUNT-i-1]->setIndex(MAX_PAGE_COUNT-i-1);
        //m_page_right_top_temp[MAX_PAGE_COUNT-i-1]->setOpacity(0.8);
        
        VFX_OBJ_CREATE(m_page_right_bottom_temp[i], VappFlipClockPage, m_bg_frame);
        m_page_right_bottom_temp[i]->setBackGround(IMG_FCLOCK_WIDGET_RIGHT_BOTTOM);
        m_page_right_bottom_temp[i]->setBounds(VfxRect(0, 0, PAGE_WIDTH, PAGE_HEIGHT));
        m_page_right_bottom_temp[i]->setPos(VfxPoint(0,0));
        m_page_right_bottom_temp[i]->setHidden(VFX_TRUE);
        m_page_right_bottom_temp[i]->setIndex(i+MAX_PAGE_COUNT);
        //m_page_right_bottom_temp[i]->setOpacity(0.8);
        
        VFX_OBJ_CREATE(m_page_left_top_temp[MAX_PAGE_COUNT-i-1], VappFlipClockPage, m_bg_frame);
        m_page_left_top_temp[MAX_PAGE_COUNT-i-1]->setBackGround(IMG_FCLOCK_WIDGET_LEFT_TOP);
        m_page_left_top_temp[MAX_PAGE_COUNT-i-1]->setBounds(VfxRect(0, 0, PAGE_WIDTH, PAGE_HEIGHT));
        m_page_left_top_temp[MAX_PAGE_COUNT-i-1]->setPos(VfxPoint(0,0));
        m_page_left_top_temp[MAX_PAGE_COUNT-i-1]->setHidden(VFX_TRUE);
        m_page_left_top_temp[MAX_PAGE_COUNT-i-1]->setIndex(MAX_PAGE_COUNT-i-1+MAX_PAGE_COUNT*2);
        //m_page_left_top_temp[MAX_PAGE_COUNT-i-1]->setOpacity(0.8);
        
        VFX_OBJ_CREATE(m_page_left_bottom_temp[i], VappFlipClockPage, m_bg_frame);
        m_page_left_bottom_temp[i]->setBackGround(IMG_FCLOCK_WIDGET_LEFT_BOTTOM);
        m_page_left_bottom_temp[i]->setBounds(VfxRect(0, 0, PAGE_WIDTH, PAGE_HEIGHT));
        m_page_left_bottom_temp[i]->setPos(VfxPoint(0,0));
        m_page_left_bottom_temp[i]->setHidden(VFX_TRUE);
        m_page_left_bottom_temp[i]->setIndex(i+MAX_PAGE_COUNT*3);
        //m_page_left_bottom_temp[i]->setOpacity(0.8);
    }

    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.connect(this, &VappWidgetFlipClock::onSystemTimeChanged);

    UpdateTime(m_dt,m_dt,VAPP_FLIP_CLOCK_ANIM_TYPE_RIGHT_SWIPE);
    UpdateTime(m_dt,m_dt,VAPP_FLIP_CLOCK_ANIM_TYPE_LEFT_SWIPE);
}


void VappWidgetFlipClock::onReleaseView()
{
    VFX_OBJ_CLOSE(m_bg);
    VFX_OBJ_CLOSE(m_page_right_top);
    VFX_OBJ_CLOSE(m_page_left_top);
    VFX_OBJ_CLOSE(m_page_left_bottom);
    VFX_OBJ_CLOSE(m_page_right_bottom);
    VFX_OBJ_CLOSE(m_bg_frame);
    VFX_OBJ_CLOSE(m_bg_timeline);
	
    if (m_effect)
    {
        VFX_DELETE(m_effect);
    }

    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.disconnect(this,&VappWidgetFlipClock::onSystemTimeChanged);
 
    VappWidget::onReleaseView();
}


void VappWidgetFlipClock::onEnterSlimView()
{
    need_animation=VFX_FALSE;
}


void VappWidgetFlipClock::onExitSlimView()
{
    need_animation=VFX_TRUE;
}


VfxPoint VappWidgetFlipClock::onGetEditButtonOffset()
{
    return VfxPoint(BUTTON_X,BUTTON_Y);
}


void VappWidgetFlipClock::onSerializeView(VfxArchive *ar)
{
    is_swiping=VFX_FALSE;
    
    VFX_OBJ_CLOSE(m_bg_timeline);
    
    m_dt.setCurrentTime();
    UpdateTime(m_dt,m_dt,VAPP_FLIP_CLOCK_ANIM_TYPE_RIGHT_NONE);
    UpdateTime(m_dt,m_dt,VAPP_FLIP_CLOCK_ANIM_TYPE_LEFT_NONE);

    for (VfxU8 i = 0; i < MAX_PAGE_COUNT; i++)
    {
        m_page_right_top_temp[i]->setHidden(VFX_TRUE);
        m_page_right_bottom_temp[i]->setHidden(VFX_TRUE); 
        m_page_left_top_temp[i]->setHidden(VFX_TRUE);
        m_page_left_bottom_temp[i]->setHidden(VFX_TRUE);
    }

    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.disconnect(this, &VappWidgetFlipClock::onSystemTimeChanged);
}


void VappWidgetFlipClock::onRestoreView(VfxArchive *ar)
{
    if(m_bg_timeline==NULL)
        VFX_OBJ_CREATE(m_bg_timeline,VfxFrame,this);
    
    m_dt.setCurrentTime();
    UpdateTime(m_dt,m_dt,VAPP_FLIP_CLOCK_ANIM_TYPE_RIGHT_SWIPE);
    UpdateTime(m_dt,m_dt,VAPP_FLIP_CLOCK_ANIM_TYPE_LEFT_SWIPE);

    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.connect(this, &VappWidgetFlipClock::onSystemTimeChanged);
}


void VappWidgetFlipClock::onSystemTimeChanged(VfxU32 flag)
{
     if (is_swiping)
        return;
    
    VfxDateTime dt_org=m_dt;
    m_dt.setCurrentTime();
     
    if (flag & VDAT_SYSTIME_CHANGED_MIN)
    {
        // Update right page time. Minute page.
        if((need_animation)&&(dt_org.getMinute()!=m_dt.getMinute()))
            UpdateTime(m_dt,dt_org,VAPP_FLIP_CLOCK_ANIM_TYPE_RIGHT_NORMAL);
        else
            UpdateTime(m_dt,dt_org,VAPP_FLIP_CLOCK_ANIM_TYPE_RIGHT_NONE);
    }
     
    if (flag & VDAT_SYSTIME_CHANGED_HOUR)
    {
        // Update left page time. Hour page.
        if((need_animation)&&(dt_org.getHour()!=m_dt.getHour()))
            UpdateTime(m_dt,dt_org,VAPP_FLIP_CLOCK_ANIM_TYPE_LEFT_NORMAL);
        else
            UpdateTime(m_dt,dt_org,VAPP_FLIP_CLOCK_ANIM_TYPE_LEFT_NONE);
    }
    if ((flag & VDAT_SYSTIME_CHANGED_DAY) || (flag & VDAT_SYSTIME_CHANGED_MONTH))
    {     
        VfxWString str,str1;
        VfxWChar string_buf[32];
        VfxWString am_str;

        // Update date string
        m_dt.getDateTimeString(m_formatFlags, (VfxWChar*)string_buf, 34);
        str.loadFromMem(string_buf);
        m_page_right_top->setString(str,m_font,m_color,VfxPoint(DATE_X, DATE_Y),VFX_FALSE);

        m_dt.getDateTimeString(VFX_DATE_TIME_DAY_NORMAL_NAME, (VfxWChar*)string_buf, 34);
        str.loadFromMem(string_buf);
        m_page_left_top->setString(str,m_font,m_color,VfxPoint(DATA_NAME_X, DATA_NAME_Y),VFX_TRUE);

        // Update PM/AM string
        if (PhnsetGetTimeFormat())
        {
            am_str.setEmpty();
        }
        else
        {
            if (m_dt.getHour() >=12)
                am_str.loadFromMem((const VfxWChar*)L"PM");
            else
                am_str.loadFromMem((const VfxWChar*)L"AM");
         }
        m_page_right_bottom->setString(am_str,m_font,m_color,VfxPoint(AMPM_X, AMPM_Y),VFX_FALSE);
    }
}


void VappWidgetFlipClock::UpdateTime(VfxDateTime dt_new,VfxDateTime dt_old,VappFlipClockAnimTyepEnum type)
{
    VfxWString am_str;
    VfxWString str,str1;
    VfxWChar string_buf[32];
    VfxS32 min=dt_new.getMinute();
    VfxS32 hour=dt_new.getHour();
    VfxS32 hour_old=dt_old.getHour();
    VfxS32 min_old=dt_old.getMinute();
    
    if (PhnsetGetTimeFormat())
    {
        am_str.setEmpty();
    }
    else
    {
        if (hour >=12)
        {
            am_str.loadFromMem((const VfxWChar*)L"PM");     
            if(hour>12)
                hour-=12;     
        }
        else
        {
            am_str.loadFromMem((const VfxWChar*)L"AM");
            if(hour==0)
                hour=12;
        }
    }
    
    switch (type)
    {
        case VAPP_FLIP_CLOCK_ANIM_TYPE_LEFT_NONE:        
            // Update left top page to new time
            m_page_left_top->setNumber(
                IMG_FCLOCK_WIDGET_NUM_T_0+hour/10,
                VfxPoint(NUM_X,PAGE_HEIGHT-NUM_TOP_HEIGHT),
                IMG_FCLOCK_WIDGET_NUM_T_0+hour%10,
                VfxPoint(NUM_X+NUM_WIDTH+NUM_GAP,PAGE_HEIGHT-NUM_TOP_HEIGHT)
            );
            dt_new.getDateTimeString(VFX_DATE_TIME_DAY_NORMAL_NAME, (VfxWChar*)string_buf, 34);
            str.loadFromMem(string_buf);
            m_page_left_top->setString(str,m_font,m_color,VfxPoint(DATA_NAME_X, DATA_NAME_Y),VFX_TRUE);
            
            // Update left bottom page to new time
            m_page_left_bottom->setNumber(
                IMG_FCLOCK_WIDGET_NUM_B_0+hour/10,
                VfxPoint(NUM_X,0),
                IMG_FCLOCK_WIDGET_NUM_B_0+hour%10,
                VfxPoint(NUM_X+NUM_WIDTH+NUM_GAP,0)
            );
            break;
            
        case VAPP_FLIP_CLOCK_ANIM_TYPE_RIGHT_NONE:
            //Update right top page to new time
            m_page_right_top->setNumber(
                IMG_FCLOCK_WIDGET_NUM_T_0+min/10,
                VfxPoint(NUM_X,PAGE_HEIGHT-NUM_TOP_HEIGHT),
                IMG_FCLOCK_WIDGET_NUM_T_0+min%10,
                VfxPoint(NUM_X+NUM_WIDTH+NUM_GAP,PAGE_HEIGHT-NUM_TOP_HEIGHT)
            );
            dt_new.getDateTimeString(m_formatFlags, (VfxWChar*)string_buf, 34);
            str.loadFromMem(string_buf);
            m_page_right_top->setString(str,m_font,m_color,VfxPoint(DATE_X, DATE_Y),VFX_FALSE);
 
            //Update right bottom page to new time
            m_page_right_bottom->setNumber(
            IMG_FCLOCK_WIDGET_NUM_B_0+min/10,
            VfxPoint(NUM_X,0),
            IMG_FCLOCK_WIDGET_NUM_B_0+min%10,
            VfxPoint(NUM_X+NUM_WIDTH+NUM_GAP,0)
            );
            m_page_right_bottom->setString(am_str,m_font,m_color,VfxPoint(AMPM_X, AMPM_Y),VFX_FALSE);
            break;

        case VAPP_FLIP_CLOCK_ANIM_TYPE_LEFT_NORMAL:
        {
            // Update left top page to new time
            m_page_left_top->setNumber(
                IMG_FCLOCK_WIDGET_NUM_T_0+hour/10,
                VfxPoint(NUM_X,PAGE_HEIGHT-NUM_TOP_HEIGHT),
                IMG_FCLOCK_WIDGET_NUM_T_0+hour%10,
                VfxPoint(NUM_X+NUM_WIDTH+NUM_GAP,PAGE_HEIGHT-NUM_TOP_HEIGHT)
            );
            dt_new.getDateTimeString(VFX_DATE_TIME_DAY_NORMAL_NAME, (VfxWChar*)string_buf, 34);
            str.loadFromMem(string_buf);
            m_page_left_top->setString(str,m_font,m_color,VfxPoint(DATA_NAME_X, DATA_NAME_Y),VFX_TRUE);
            
            if (!PhnsetGetTimeFormat())
            {
                if (hour_old >12)
                {
                    hour_old-=12;
                }
                else if (hour_old==0)
                {
                    hour_old=12;
                }
            }
            
            // Update left top temp page to old time for timeline
            m_page_left_top_temp[0]->setNumber(
                IMG_FCLOCK_WIDGET_NUM_T_0+hour_old/10,
                VfxPoint(NUM_X,PAGE_HEIGHT-NUM_TOP_HEIGHT),
                IMG_FCLOCK_WIDGET_NUM_T_0+hour_old%10,
                VfxPoint(NUM_X+NUM_WIDTH+NUM_GAP,PAGE_HEIGHT-NUM_TOP_HEIGHT)
            );
            
            dt_old.getDateTimeString(VFX_DATE_TIME_DAY_NORMAL_NAME, (VfxWChar*)string_buf, 34);
            str.loadFromMem(string_buf);
            m_page_left_top_temp[0]->setString(str,m_font,m_color,VfxPoint(AMPM_X, AMPM_Y),VFX_TRUE);
            
            // Update left bottom temp page to new time for timeline
            m_page_left_bottom_temp[0]->setNumber(
                IMG_FCLOCK_WIDGET_NUM_B_0+hour/10,
                VfxPoint(NUM_X,0),
                IMG_FCLOCK_WIDGET_NUM_B_0+hour%10,
                VfxPoint(NUM_X+NUM_WIDTH+NUM_GAP,0)
            );
            
            // Begin timeline
            TimelineBegin(m_page_left_top_temp[0],0);
            break;            
        }

        case VAPP_FLIP_CLOCK_ANIM_TYPE_RIGHT_NORMAL:
        {
            //Update right top page to new time
            m_page_right_top->setNumber(
                IMG_FCLOCK_WIDGET_NUM_T_0+min/10,
                VfxPoint(NUM_X,PAGE_HEIGHT-NUM_TOP_HEIGHT),
                IMG_FCLOCK_WIDGET_NUM_T_0+min%10,
                VfxPoint(NUM_X+NUM_WIDTH+NUM_GAP,PAGE_HEIGHT-NUM_TOP_HEIGHT)
            );
            dt_new.getDateTimeString(m_formatFlags, (VfxWChar*)string_buf, 34);
            str.loadFromMem(string_buf);
            m_page_right_top->setString(str,m_font,m_color,VfxPoint(DATE_X, DATE_Y),VFX_FALSE);

            // Update right top temp page to old time for timeline
            m_page_right_top_temp[0]->setNumber(
                IMG_FCLOCK_WIDGET_NUM_T_0+min_old/10,
                VfxPoint(NUM_X,PAGE_HEIGHT-NUM_TOP_HEIGHT),
                IMG_FCLOCK_WIDGET_NUM_T_0+min_old%10,
                VfxPoint(NUM_X+NUM_WIDTH+NUM_GAP,PAGE_HEIGHT-NUM_TOP_HEIGHT)
            );
            dt_old.getDateTimeString(m_formatFlags, (VfxWChar*)string_buf, 34);
            str.loadFromMem(string_buf);
            m_page_right_top_temp[0]->setString(str,m_font,m_color,VfxPoint(DATE_X, DATE_Y),VFX_FALSE);

            // Update right bottom temp page to new time for timeline
            m_page_right_bottom_temp[0]->setNumber(
            IMG_FCLOCK_WIDGET_NUM_B_0+min/10,
            VfxPoint(NUM_X,0),
            IMG_FCLOCK_WIDGET_NUM_B_0+min%10,
            VfxPoint(NUM_X+NUM_WIDTH+NUM_GAP,0)
            );
            m_page_right_bottom_temp[0]->setString(am_str,m_font,m_color,VfxPoint(AMPM_X, AMPM_Y),VFX_FALSE);

            // Begin timeline
            TimelineBegin(m_page_right_top_temp[0],0);

            break;
        }

        case VAPP_FLIP_CLOCK_ANIM_TYPE_LEFT_SWIPE:
        {
            VfxDateTime decrease_time;
            VfxDateTime increase_time;
            decrease_time.setTime(G1_PAGE_COUNT-1,0,0);
            dt_old.decrease(decrease_time);
            increase_time.setTime(1,0,0);

            VfxS32 hour_temp0=dt_old.getHour();
            VfxS32 hour_temp1=0;

            // Update left top page to new time
            m_page_left_top->setNumber(
                IMG_FCLOCK_WIDGET_NUM_T_0+hour/10,
                VfxPoint(NUM_X,PAGE_HEIGHT-NUM_TOP_HEIGHT),
                IMG_FCLOCK_WIDGET_NUM_T_0+hour%10,
                VfxPoint(NUM_X+NUM_WIDTH+NUM_GAP,PAGE_HEIGHT-NUM_TOP_HEIGHT)
            );
            dt_new.getDateTimeString(VFX_DATE_TIME_DAY_NORMAL_NAME, (VfxWChar*)string_buf, 34);
            str.loadFromMem(string_buf);
            m_page_left_top->setString(str,m_font,m_color,VfxPoint(DATA_NAME_X, DATA_NAME_Y),VFX_TRUE);
                        
            if (!PhnsetGetTimeFormat())
            {
                if (hour_temp0 >12)
                {
                    hour_temp0-=12;
                }
                else if (hour_temp0==0)
                {
                    hour_temp0=12;
                }
            }

            m_page_left_bottom->setNumber(
                IMG_FCLOCK_WIDGET_NUM_B_0+hour_temp0/10,
                VfxPoint(NUM_X,0),
                IMG_FCLOCK_WIDGET_NUM_B_0+hour_temp0%10,
                VfxPoint(NUM_X+NUM_WIDTH+NUM_GAP,0)
            );

            for (VfxS32 i = 0; i < G1_PAGE_COUNT-1; i++)
            {
                m_page_left_top_temp[i]->setNumber(
                    IMG_FCLOCK_WIDGET_NUM_T_0+hour_temp0/10,
                    VfxPoint(NUM_X,PAGE_HEIGHT-NUM_TOP_HEIGHT),
                    IMG_FCLOCK_WIDGET_NUM_T_0+hour_temp0%10,
                    VfxPoint(NUM_X+NUM_WIDTH+NUM_GAP,PAGE_HEIGHT-NUM_TOP_HEIGHT)
                );
                dt_old.getDateTimeString(VFX_DATE_TIME_DAY_NORMAL_NAME, (VfxWChar*)string_buf, 34);
                str.loadFromMem(string_buf);
                m_page_left_top_temp[i]->setString(str,m_font,m_color,VfxPoint(DATA_NAME_X, DATA_NAME_Y),VFX_TRUE);

                dt_old.increase(increase_time);
                hour_temp1=dt_old.getHour();

                if (!PhnsetGetTimeFormat())
                {
                    if (hour_temp1 >12)
                    {
                        hour_temp1-=12;
                    }
                    else if (hour_temp1==0)
                    {
                        hour_temp1=12;
                    }
                }
                
                m_page_left_bottom_temp[i]->setNumber(
                    IMG_FCLOCK_WIDGET_NUM_B_0+hour_temp1/10,
                    VfxPoint(NUM_X,0),
                    IMG_FCLOCK_WIDGET_NUM_B_0+hour_temp1%10,
                    VfxPoint(NUM_X+NUM_WIDTH+NUM_GAP,0)
                );
                
                TimelineBegin(m_page_left_top_temp[i],i*ANIMATION_TIME+ANIMATION_TIME/G1_PAGE_COUNT+ANIMATION_DELAY);

                hour_temp0=hour_temp1;
            }
            
            break;            
        }

        case VAPP_FLIP_CLOCK_ANIM_TYPE_RIGHT_SWIPE:
        {
            VfxDateTime decrease_time;
            VfxDateTime increase_time;
            decrease_time.setTime(0,G1_PAGE_COUNT,0);
            dt_old.decrease(decrease_time);
            increase_time.setTime(0,1,0);

            VfxS32 min_temp0=dt_old.getMinute();
            VfxS32 min_temp1=0;
            
            VfxS32 hour_temp=dt_old.getHour();
            
            is_swiping=VFX_TRUE;

            //Update right top page to new time
            m_page_right_top->setNumber(
                IMG_FCLOCK_WIDGET_NUM_T_0+min/10,
                VfxPoint(NUM_X,PAGE_HEIGHT-NUM_TOP_HEIGHT),
                IMG_FCLOCK_WIDGET_NUM_T_0+min%10,
                VfxPoint(NUM_X+NUM_WIDTH+NUM_GAP,PAGE_HEIGHT-NUM_TOP_HEIGHT)
            );
            dt_new.getDateTimeString(m_formatFlags, (VfxWChar*)string_buf, 34);
            str.loadFromMem(string_buf);
            m_page_right_top->setString(str,m_font,m_color,VfxPoint(DATE_X, DATE_Y),VFX_FALSE);

            if (PhnsetGetTimeFormat())
            {
                am_str.setEmpty();
            }
            else
            {
                if (hour_temp >=12)
                {
                    am_str.loadFromMem((const VfxWChar*)L"PM");  
                }
                else
                {
                    am_str.loadFromMem((const VfxWChar*)L"AM");
                }
            }

            m_page_right_bottom->setNumber(
            IMG_FCLOCK_WIDGET_NUM_B_0+min_temp0/10,
            VfxPoint(NUM_X,0),
            IMG_FCLOCK_WIDGET_NUM_B_0+min_temp0%10,
            VfxPoint(NUM_X+NUM_WIDTH+NUM_GAP,0)
            );
            m_page_right_bottom->setString(am_str,m_font,m_color,VfxPoint(AMPM_X, AMPM_Y),VFX_FALSE);

            for (VfxS32 i = 0; i < G1_PAGE_COUNT; i++)
            {
                m_page_right_top_temp[i]->setNumber(
                    IMG_FCLOCK_WIDGET_NUM_T_0+min_temp0/10,
                    VfxPoint(NUM_X,PAGE_HEIGHT-NUM_TOP_HEIGHT),
                    IMG_FCLOCK_WIDGET_NUM_T_0+min_temp0%10,
                    VfxPoint(NUM_X+NUM_WIDTH+NUM_GAP,PAGE_HEIGHT-NUM_TOP_HEIGHT)
                );
                dt_old.getDateTimeString(m_formatFlags, (VfxWChar*)string_buf, 34);
                str.loadFromMem(string_buf);
                m_page_right_top_temp[i]->setString(str,m_font,m_color,VfxPoint(DATE_X, DATE_Y),VFX_FALSE);

                dt_old.increase(increase_time);
                min_temp1=dt_old.getMinute();
                hour_temp=dt_old.getHour();
                if (PhnsetGetTimeFormat())
                {
                    am_str.setEmpty();
                }
                else
                {
                    if (hour_temp >= 12)
                    {
                        am_str.loadFromMem((const VfxWChar*)L"PM");  
                    }
                    else
                    {
                        am_str.loadFromMem((const VfxWChar*)L"AM");
                    }
                }
                m_page_right_bottom_temp[i]->setNumber(
                IMG_FCLOCK_WIDGET_NUM_B_0+min_temp1/10,
                VfxPoint(NUM_X,0),
                IMG_FCLOCK_WIDGET_NUM_B_0+min_temp1%10,
                VfxPoint(NUM_X+NUM_WIDTH+NUM_GAP,0)
                );
                m_page_right_bottom_temp[i]->setString(am_str,m_font,m_color,VfxPoint(AMPM_X, AMPM_Y),VFX_FALSE);

                TimelineBegin(m_page_right_top_temp[i],i*ANIMATION_TIME+ANIMATION_DELAY);

                min_temp0=min_temp1;
            }
            
            VfxTimer *swipe_time;
            VFX_OBJ_CREATE(swipe_time,VfxTimer,m_bg_timeline);
            swipe_time->setStartDelay(ANIMATION_TIME*2+ANIMATION_TIME*(G1_PAGE_COUNT-1)+ANIMATION_DELAY);
            swipe_time->m_signalTick.connect(this, &VappWidgetFlipClock::onTimerTick);
            swipe_time->start();
            break;
        }
        default:
            break;
            
    }
}


void VappWidgetFlipClock::TimelineBegin(VappFlipClockPage *target,VfxS32 delay)
{
    VappFlipClockPage *shadow = NULL;
    if ((target->getIndex()>=MAX_PAGE_COUNT*2)&&(target->getIndex()<MAX_PAGE_COUNT*3))
    {
        shadow=m_left_shadow[target->getIndex()-MAX_PAGE_COUNT*2];
        shadow->setHidden(VFX_FALSE);
    }
    else if ((target->getIndex()>=0)&&(target->getIndex()<MAX_PAGE_COUNT))
    {
        shadow=m_right_shadow[target->getIndex()];
        shadow->setHidden(VFX_FALSE);
    }
    else 
        ASSERT(0);

    target->setHidden(VFX_FALSE);

    VfxMatrix4x4 camera;
    camera.setCamera(1, 1, getSize().width/2, PAGE_Y, 240, 240, 0, 0, 0);

    // Model matrix
    VfxMatrix4x4 M;
    if (target->getIndex()>=MAX_PAGE_COUNT*2&&target->getIndex()<MAX_PAGE_COUNT*3)
        M.setTranslation(-PAGE_WIDTH, -PAGE_HEIGHT, 0);
    else if (target->getIndex()>=0&&target->getIndex()<MAX_PAGE_COUNT)
        M.setTranslation(0, -PAGE_HEIGHT, 0);
 
    // Rotate a angle 
    VfxMatrix4x4 R;
    R.setRotateByX(VFX_DEG_TO_RAD(88));
 
    // Total. Transform end
    VfxTransform tempTransform;
    VfxMatrix4x4 total = camera *R *M; 
    tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;
    total.initMatrix3x3(tempTransform.data.matrix3x3); 
    
    // Total. Transform begin
    VfxTransform tempTransform0;
    total = camera * M; 
    tempTransform0.type = VFX_TRANSFORM_TYPE_MATRIX3X3;
    total.initMatrix3x3(tempTransform0.data.matrix3x3); 

    if (delay!=0)
    {
        target->setTransform(tempTransform0);
        shadow->setSize(shadow->getSize().width,0);
    }
    // Transform timeline for right top temp page animation
    VfxTransformTimeline *m_switchPageTimeline;
    VFX_OBJ_CREATE(m_switchPageTimeline, VfxTransformTimeline, m_bg_timeline);  
    m_switchPageTimeline->setTarget(target);
    m_switchPageTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
    m_switchPageTimeline->setFromValue(tempTransform0);
    m_switchPageTimeline->setToValue(tempTransform);
    m_switchPageTimeline->setRepeatCount(1);
    m_switchPageTimeline->setDuration(ANIMATION_TIME);
    m_switchPageTimeline->setStartDelay(delay);
    m_switchPageTimeline->m_signalStopped.connect(this,&VappWidgetFlipClock::TimelineOnGoing);
    m_switchPageTimeline->start();     
    
    VfxS32Timeline *m_shadowTimeline;
    VFX_OBJ_CREATE(m_shadowTimeline, VfxS32Timeline, m_bg_timeline);     
    m_shadowTimeline->setTarget(shadow);
    m_shadowTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_BOUNDS_SIZE_HEIGHT);
    m_shadowTimeline->setFromValue(0);
    m_shadowTimeline->setToValue(PAGE_HEIGHT/2);
    m_shadowTimeline->setRepeatCount(1);
    m_shadowTimeline->setDuration(ANIMATION_TIME);
    m_shadowTimeline->setStartDelay(delay);
    m_shadowTimeline->m_signalStopped.connect(this,&VappWidgetFlipClock::TimelineOnGoing);
    m_shadowTimeline->start();
}


void VappWidgetFlipClock::TimelineOnGoing(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    if (!isCompleted)
        return;
    
    VappFlipClockPage *target=(VappFlipClockPage *)timeline->getTarget();
    VappFlipClockPage *new_target = NULL;
    VFX_OBJ_CLOSE(timeline);

    if (target->getIndex()==MAX_PAGE_COUNT*4)
    {
        VfxS32Timeline *m_shadowTimeline;
        VFX_OBJ_CREATE(m_shadowTimeline, VfxS32Timeline, m_bg_timeline);     
        m_shadowTimeline->setTarget(target);
        m_shadowTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_BOUNDS_SIZE_HEIGHT);
        m_shadowTimeline->setFromValue(0);
        m_shadowTimeline->setToValue(PAGE_HEIGHT/2);
        m_shadowTimeline->setRepeatCount(1);
        m_shadowTimeline->setDuration(ANIMATION_TIME);
        m_shadowTimeline->m_signalStopped.connect(this,&VappWidgetFlipClock::TimelineEnd);
        m_shadowTimeline->start();
        return;
    }
    
    if ((target->getIndex()>=MAX_PAGE_COUNT*2)&&(target->getIndex()<MAX_PAGE_COUNT*3))
    {
        new_target=m_page_left_bottom_temp[target->getIndex()-MAX_PAGE_COUNT*2];
    }
    else if ((target->getIndex()>=0)&&(target->getIndex()<MAX_PAGE_COUNT))
    {
        new_target=m_page_right_bottom_temp[target->getIndex()];
    }
    else 
        ASSERT(0);

    target->setHidden(VFX_TRUE);
    new_target->setHidden(VFX_FALSE);
 
    VfxMatrix4x4 camera;
    camera.setCamera(1, 1, getSize().width/2, PAGE_Y, 240, 240, 0, 0, 0);

    // Model matrix
    VfxMatrix4x4 M;
    if (target->getIndex()>=MAX_PAGE_COUNT*2&&target->getIndex()<MAX_PAGE_COUNT*3)
        M.setTranslation(-PAGE_WIDTH, 0, 0);
    else if (target->getIndex()>=0&&target->getIndex()<MAX_PAGE_COUNT)
        M.setIdentity();
         
    // Rotate a angle 
    VfxMatrix4x4 R;
    R.setRotateByX(VFX_DEG_TO_RAD(-88));
     
    // Total. Transform end
    VfxTransform tempTransform;
    VfxMatrix4x4 total = camera * M; 
    tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;
    total.initMatrix3x3(tempTransform.data.matrix3x3); 
    
    // Total. Transform begin
    VfxTransform tempTransform0;
    total = camera * M * R; 
    tempTransform0.type = VFX_TRANSFORM_TYPE_MATRIX3X3;
    total.initMatrix3x3(tempTransform0.data.matrix3x3);
    
    // Transform timeline for right bottom temp page animation
    VfxTransformTimeline *m_switchPageTimeline;
    VFX_OBJ_CREATE(m_switchPageTimeline, VfxTransformTimeline, m_bg_timeline);     
    m_switchPageTimeline->setTarget(new_target);
    m_switchPageTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
    m_switchPageTimeline->setFromValue(tempTransform0);
    m_switchPageTimeline->setToValue(tempTransform);
    m_switchPageTimeline->setRepeatCount(1);
    m_switchPageTimeline->setDuration(ANIMATION_TIME);
    m_switchPageTimeline->m_signalStopped.connect(this,&VappWidgetFlipClock::TimelineEnd);
    m_switchPageTimeline->start();
}


void VappWidgetFlipClock::TimelineEnd(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    
    if(!isCompleted)
        return;

    VappFlipClockPage *target=(VappFlipClockPage *)timeline->getTarget();
    target->setHidden(VFX_TRUE);
    VFX_OBJ_CLOSE(timeline);
    
    if (target->getIndex()==MAX_PAGE_COUNT*4)
        return;

    VfxResId num1=0,num2=0;
    VfxWString str;

    if ((target->getIndex()>=MAX_PAGE_COUNT)&&(target->getIndex()<MAX_PAGE_COUNT*2))
    {
        m_right_shadow[target->getIndex()-MAX_PAGE_COUNT]->setHidden(VFX_TRUE);
    }
    if ((target->getIndex()>=MAX_PAGE_COUNT*3)&&(target->getIndex()<MAX_PAGE_COUNT*4))
    {
        m_left_shadow[target->getIndex()-MAX_PAGE_COUNT*3]->setHidden(VFX_TRUE);
    }
    
    target->getNumber(&num1,&num2);
    str=target->getString();
    
    if (target->getIndex()>=MAX_PAGE_COUNT*3)
    {
        m_page_left_bottom->setNumber(
            num1,
            VfxPoint(NUM_X,0),
            num2,
            VfxPoint(NUM_X+NUM_WIDTH+NUM_GAP,0)
        );
    }
    else if (target->getIndex()>=MAX_PAGE_COUNT&&target->getIndex()<MAX_PAGE_COUNT*2)
    {
        m_page_right_bottom->setNumber(
        num1,
        VfxPoint(NUM_X,0),
        num2,
        VfxPoint(NUM_X+NUM_WIDTH+NUM_GAP,0)
        );
        m_page_right_bottom->setString(str,m_font,m_color,VfxPoint(AMPM_X, AMPM_Y),VFX_FALSE);
    }
}


void VappWidgetFlipClock::onTimerTick(VfxTimer *source)
{
    is_swiping=VFX_FALSE;
    
    VfxDateTime dt_org=m_dt;
    m_dt.setCurrentTime();

    if (dt_org.getMinute()!=m_dt.getMinute())
    {
        // Update right page time. Minute page.
        if (need_animation)
            UpdateTime(m_dt,dt_org,VAPP_FLIP_CLOCK_ANIM_TYPE_RIGHT_NORMAL);
        else
            UpdateTime(m_dt,dt_org,VAPP_FLIP_CLOCK_ANIM_TYPE_RIGHT_NONE);
    }
    if (dt_org.getHour()!=m_dt.getHour())
    {
        // Update left page time. Hour page.
        if (need_animation)
            UpdateTime(m_dt,dt_org,VAPP_FLIP_CLOCK_ANIM_TYPE_LEFT_NORMAL);
        else
            UpdateTime(m_dt,dt_org,VAPP_FLIP_CLOCK_ANIM_TYPE_LEFT_NONE);
    }

    VFX_OBJ_CLOSE(source);
}


void VappWidgetFlipClock::CreateFlipClock(VfxDateTime dt)
{
    VfxWString str,str1;
    VfxWChar string_buf[32];
    VfxS32 min=dt.getMinute();
    VfxS32 hour;
    VfxWString am_str;

    // Create right top page
    VFX_OBJ_CREATE(m_page_right_top, VappFlipClockPage, this);
    m_page_right_top->setNumber(
        IMG_FCLOCK_WIDGET_NUM_T_0+min/10,
        VfxPoint(NUM_X,PAGE_HEIGHT-NUM_TOP_HEIGHT),
        IMG_FCLOCK_WIDGET_NUM_T_0+min%10,
        VfxPoint(NUM_X+NUM_WIDTH+NUM_GAP,PAGE_HEIGHT-NUM_TOP_HEIGHT)
    );
    m_page_right_top->setBounds(VfxRect(0, 0, PAGE_WIDTH, PAGE_HEIGHT));
    m_page_right_top->setPos(VfxPoint(getSize().width/2,PAGE_Y));
    m_page_right_top->setAnchor(0,1.0);
    dt.getDateTimeString(m_formatFlags, (VfxWChar*)string_buf, 34);
    str.loadFromMem(string_buf);
    m_page_right_top->setString(str,m_font,m_color,VfxPoint(DATE_X, DATE_Y),VFX_FALSE);

    hour=dt.getHour();
    if (PhnsetGetTimeFormat())
    {
        am_str.setEmpty();
    }
    else
    {
        if (hour >=12)
        {
            am_str.loadFromMem((const VfxWChar*)L"PM");     
            if (hour>12)
                hour-=12;
        }
        else
        {
            am_str.loadFromMem((const VfxWChar*)L"AM");
            if(hour==0)
                hour=12;
        }
    }

    // Create right bottom page     
    VFX_OBJ_CREATE(m_page_right_bottom, VappFlipClockPage, this);
    m_page_right_bottom->setNumber(
        IMG_FCLOCK_WIDGET_NUM_B_0+min/10,
        VfxPoint(NUM_X,0),
        IMG_FCLOCK_WIDGET_NUM_B_0+min%10,
        VfxPoint(NUM_X+NUM_WIDTH+NUM_GAP,0)
    );
    m_page_right_bottom->setBounds(VfxRect(0, 0, PAGE_WIDTH, PAGE_HEIGHT));
    m_page_right_bottom->setPos(VfxPoint(getSize().width/2,PAGE_Y));
     m_page_right_bottom->setString(am_str,m_font,m_color,VfxPoint(AMPM_X, AMPM_Y),VFX_FALSE);
    
    // Create left bottom page
    VFX_OBJ_CREATE(m_page_left_bottom, VappFlipClockPage, this);
    m_page_left_bottom->setNumber(
        IMG_FCLOCK_WIDGET_NUM_B_0+hour/10,
        VfxPoint(NUM_X,0),
        IMG_FCLOCK_WIDGET_NUM_B_0+hour%10,
        VfxPoint(NUM_X+NUM_WIDTH+NUM_GAP,0)
    );
    m_page_left_bottom->setBounds(VfxRect(0, 0, PAGE_WIDTH, PAGE_HEIGHT));
    m_page_left_bottom->setPos(VfxPoint(getSize().width/2-PAGE_WIDTH,PAGE_Y));

    // Create left top page
    VFX_OBJ_CREATE(m_page_left_top, VappFlipClockPage, this);
    m_page_left_top->setNumber(
        IMG_FCLOCK_WIDGET_NUM_T_0+hour/10,
        VfxPoint(NUM_X,PAGE_HEIGHT-NUM_TOP_HEIGHT),
        IMG_FCLOCK_WIDGET_NUM_T_0+hour%10,
        VfxPoint(NUM_X+NUM_WIDTH+NUM_GAP,PAGE_HEIGHT-NUM_TOP_HEIGHT)
    );
    m_page_left_top->setBounds(VfxRect(0, 0, PAGE_WIDTH, PAGE_HEIGHT));
    m_page_left_top->setPos(VfxPoint(getSize().width/2-PAGE_WIDTH,PAGE_Y));
    m_page_left_top->setAnchor(0,1.0);
    dt.getDateTimeString(VFX_DATE_TIME_DAY_NORMAL_NAME, (VfxWChar*)string_buf, 34);
    str.loadFromMem(string_buf);
    m_page_left_top->setString(str,m_font,m_color,VfxPoint(DATA_NAME_X, DATA_NAME_Y),VFX_TRUE);
}

#endif /*__MMI_VUI_WIDGET_FLIP_CLOCK__*/
