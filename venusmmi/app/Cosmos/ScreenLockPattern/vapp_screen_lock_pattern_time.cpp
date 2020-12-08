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
 *  vapp_screen_lock_pattern_time.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_SCREEN_LOCK_PATTERN__

#include "vapp_screen_lock_pattern_time.h"
#include "vdat_include.h"

#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_vapp_screen_lock_pattern_def.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

// extern pluto setting api
#include "MMIDataType.h"
#include "NwNameSrvGprot.h"
#include "mmi_frm_utility_gprot.h"

#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * Define
 *****************************************************************************/
#define SLK_MAX(a, b) (((a) > (b)) ? (a) : (b))

/*****************************************************************************
 * Typedef
 *****************************************************************************/

/*****************************************************************************
 * Global Variable
 *****************************************************************************/

/*****************************************************************************
 * Function
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappScreenLockPatternTime", VappScreenLockPatternTime, VfxFrame);

VappScreenLockPatternTime::VappScreenLockPatternTime():
    m_imgBg(NULL),
    m_DateTimeArea(NULL)
{
}

void VappScreenLockPatternTime::onInit()
{
    VfxFrame::onInit();

    setSize(getParentFrame()->getSize().width, VAPP_SCREEN_LOCK_PATTERN_OPERATOR_AND_TIME_HIEGHT + VAPP_SCREEN_LOCK_PATTERN_STATUS_BAR_HEIGHT);

    //setBgColor(VRT_COLOR_MAKE(255*0.3, 0, 0, 0));
    VFX_OBJ_CREATE(m_imgBg, VfxImageFrame, this);
    m_imgBg->setResId(IMG_ID_VAPP_SCREEN_LOCK_PATTERN_TIME_BG);
    m_imgBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_imgBg->setSize(getParentFrame()->getSize().width, VAPP_SCREEN_LOCK_PATTERN_OPERATOR_AND_TIME_HIEGHT + VAPP_SCREEN_LOCK_PATTERN_STATUS_BAR_HEIGHT);

    /* date time area */
    VFX_OBJ_CREATE(m_DateTimeArea, VappScreenLockPatternDateTimeArea, this);
    m_DateTimeArea->setSize(VfxSize(getParentFrame()->getSize().width, VAPP_SCREEN_LOCK_PATTERN_DATE_TIME_SIZE_HEIGHT));
    m_DateTimeArea->setPos(0, VAPP_SCREEN_LOCK_PATTERN_DATE_TIME_AREA_Y);
    m_DateTimeArea->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

    m_DateTimeArea->setBgColor(VFX_COLOR_TRANSPARENT);
}

void VappScreenLockPatternTime::onDeinit()
{
    if(m_DateTimeArea)
    {
        VFX_OBJ_CLOSE(m_DateTimeArea);
    }
    VfxFrame::onDeinit();
}


/*****************************************************************************
 * Class VappScreenLockPatternDateTimeArea
 *****************************************************************************/
VappScreenLockPatternDateTimeArea::VappScreenLockPatternDateTimeArea():
    m_DateTimeBg(NULL),
    m_Time(NULL),
    m_AmPm(NULL),
    m_WeekDay(NULL),
    m_Date(NULL)
{
}


void VappScreenLockPatternDateTimeArea::onInit()
{
    VfxFrame::onInit();
    //m_bgColor = VfxColor(0x3f000000);
    setIsOpaque(VFX_FALSE);

    VFX_OBJ_CREATE(m_Time, VfxTextFrame, this);
    VFX_OBJ_CREATE(m_AmPm, VfxTextFrame, this);
    VFX_OBJ_CREATE(m_WeekDay, VfxTextFrame, this);
    VFX_OBJ_CREATE(m_Date, VfxTextFrame, this);

    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.connect(this, &VappScreenLockPatternDateTimeArea::timeUpdate);

    timeUpdate(VDAT_SYSTIME_CHANGED_MIN);
}


void VappScreenLockPatternDateTimeArea::timeUpdate(VfxU32 flag)
{
    if(flag & VDAT_SYSTIME_CHANGED_MIN || flag & VDAT_SYSTIME_CHANGED_HOUR || flag & VDAT_SYSTIME_CHANGED_DAY || flag & VDAT_SYSTIME_CHANGED_MONTH)
    {
        VfxDateTime date;
        date.setCurrentTime();

        VfxWChar string_buf[32], ampm_buf[3];
        VfxS32 time_x, time_y, day_x, day_y;
        VfxU8 str_len;
        VfxBool ampm_exist = VFX_FALSE;


        date.getDateTimeString(VFX_DATE_TIME_TIME_MINUTE|VFX_DATE_TIME_TIME_HOUR, (VfxWChar*)string_buf, 32);
        str_len = vfx_sys_wcslen((VfxWChar*)string_buf);
        if(str_len > 6)//with AMPM
        {
            ampm_exist = VFX_TRUE;
            vfx_sys_wcscpy((VfxWChar*) ampm_buf, (VfxWChar*) &string_buf[str_len-2]);
            string_buf[str_len-3] = 0; /* \space */
            string_buf[str_len-2] = 0;
            string_buf[str_len-1] = 0;
            m_AmPm->setFullLineHeightMode(VFX_FALSE);
            m_AmPm->setString((ampm_buf));
            m_AmPm->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_SCREEN_LOCK_PATTERN_AMPM_STR_SIZE), VFX_FONT_DESC_ATTR_BOLD, VFX_FE1_1));
            m_AmPm->setAutoResized(VFX_TRUE);
        }

        // Time
        m_Time->setFullLineHeightMode(VFX_FALSE);
        m_Time->setString((string_buf));
        m_Time->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_SCREEN_LOCK_PATTERN_TIME_STR_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FE1_1));
        m_Time->setAutoResized(VFX_TRUE);

        // Week day
        date.getDateTimeString(VFX_DATE_TIME_DAY_NORMAL_NAME, (VfxWChar*)string_buf, 32);
        time_x = vfx_sys_wcslen((VfxWChar*)string_buf);
        string_buf[time_x] = ',';
        string_buf[time_x + 1] = 0;
        m_WeekDay->setString((string_buf));
        m_WeekDay->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_SCREEN_LOCK_PATTERN_DAY_STR_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FE1_1));
        m_WeekDay->setAutoResized(VFX_TRUE);

        // Date
        date.getDateTimeString(VFX_DATE_TIME_DATE_YEAR | VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY, (VfxWChar*)string_buf, 32);
        m_Date->setString((string_buf));
        m_Date->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_SCREEN_LOCK_PATTERN_DAY_STR_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FE1_1));
        m_Date->setAutoResized(VFX_TRUE);

        if(ampm_exist == VFX_TRUE)
        {
            time_x = (LCD_WIDTH - m_Time->getSize().width)>>1;
            time_y = 0;
            m_AmPm->setPos(time_x + m_Time->getSize().width + VAPP_SCREEN_LOCK_PATTERN_TIME_AMPM_GAP, time_y +m_Time->getSize().height-m_AmPm->getSize().height);
        }
        else
        {
            time_x = (LCD_WIDTH - m_Time->getSize().width)>>1;
            time_y = 0;
        }
        m_Time->setPos(time_x, time_y);

        day_x = (LCD_WIDTH - m_WeekDay->getSize().width - m_Date->getSize().width - VAPP_SCREEN_LOCK_PATTERN_TIME_AMPM_GAP)>>1;
        day_y = VAPP_SCREEN_LOCK_PATTERN_WEEK_DATE_AREA_POS_Y - VAPP_SCREEN_LOCK_PATTERN_OPERATOR_NAME_AREA_HEIGHT;
        m_WeekDay->setPos(day_x, day_y);
        m_Date->setPos(day_x + m_WeekDay->getSize().width + VAPP_SCREEN_LOCK_PATTERN_TIME_AMPM_GAP, day_y);
    }
}


void VappScreenLockPatternDateTimeArea::onDeinit()
{
    VFX_OBJ_CLOSE(m_Time);
    VFX_OBJ_CLOSE(m_AmPm);
    VFX_OBJ_CLOSE(m_WeekDay);
    VFX_OBJ_CLOSE(m_Date);
    VfxFrame::onDeinit();
}

#endif // #ifdef __MMI_VUI_SCREEN_LOCK_PATTERN__

