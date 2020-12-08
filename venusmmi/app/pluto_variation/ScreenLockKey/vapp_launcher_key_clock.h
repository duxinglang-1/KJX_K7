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
 *  vapp_launcher_key_clock.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_LAUNCHER_KEY_CLOCK_H
#define VAPP_LAUNCHER_KEY_CLOCK_H

#include "MMI_features.h"

#if defined(__MMI_VUI_SCREEN_LOCK_KEY__) || defined(__MMI_VUI_LAUNCHER_KEY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vcp_include.h"
#include "vapp_screen_lock_key_def.h"
#include "mmi_rp_app_venus_screen_lock_key_def.h"


/*****************************************************************************
 * Defines
 *****************************************************************************/

/* HVGA */   
#if defined(__MMI_MAINLCD_320X480__)

    #define VAPP_SCREEN_LOCK_KEY_CLOCK_POS_TIME_X                    (56)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_POS_TIME_Y                    (34)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_POS_DATE_X                    (88)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_POS_DATE_Y                    (101)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_POS_AMPM_X                    (35)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_POS_AMPM_Y                    (38)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_GAP_TIME                      (6)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_GAP_COLON                     (2)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_FONT_SIZE_DATE                (18)

/* QVGA */      
#elif defined(__MMI_MAINLCD_240X320__)

    #define VAPP_SCREEN_LOCK_KEY_CLOCK_POS_TIME_X                    (42)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_POS_TIME_Y                    (8 + MMI_STATUS_BAR_HEIGHT)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_POS_DATE_X                    (65)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_POS_DATE_Y                    (77)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_POS_AMPM_X                    (25)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_POS_AMPM_Y                    (29)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_GAP_TIME                      (6)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_GAP_COLON                     (1)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_FONT_SIZE_DATE                (13)
    
/* WQVGA */   
#elif defined(__MMI_MAINLCD_240X400__)

    #define VAPP_SCREEN_LOCK_KEY_CLOCK_POS_TIME_X                    (42)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_POS_TIME_Y                    (8 + MMI_STATUS_BAR_HEIGHT)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_POS_DATE_X                    (65)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_POS_DATE_Y                    (77)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_POS_AMPM_X                    (25)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_POS_AMPM_Y                    (29)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_GAP_TIME                      (6)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_GAP_COLON                     (1)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_FONT_SIZE_DATE                (13)

/* LQVGA */   
#elif defined(__MMI_MAINLCD_320X240__)

    #define VAPP_SCREEN_LOCK_KEY_CLOCK_POS_TIME_X                    (102)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_POS_TIME_Y                    (25)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_POS_DATE_X                    (107)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_POS_DATE_Y                    (61)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_POS_AMPM_X                    (82)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_POS_AMPM_Y                    (25)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_GAP_TIME                      (4)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_GAP_COLON                     (1)
    #define VAPP_SCREEN_LOCK_KEY_CLOCK_FONT_SIZE_DATE                (13)

#endif

    #define VAPP_SCREEN_LOCK_KEY_CLOCK_FONT_COLOR                    VFX_COLOR_WHITE
    
/*****************************************************************************
 * VappLauncherKeyClock
 *****************************************************************************/

class VappLauncherKeyClock : public VfxFrame
{
    VFX_DECLARE_CLASS(VappLauncherKeyClock);

/*----------------------------------------------------------------*/
/* Functions                                                      */
/*----------------------------------------------------------------*/

public:

    VappLauncherKeyClock(){}
    
    VappLauncherKeyClock(VfxPoint pos)
    {
        setPos(pos);
    }

public:

    void onSystemTimeUpdate(VfxU32 flag);

private:

    void getDateTime();

    void createTimeClock();

    void createDateClock();

    void createAmPm();

    void setAmPm();
    
protected:  //override VfxFrame

    virtual void onInit();

    //virtual void onDeinit();

/*----------------------------------------------------------------*/
/* Variables                                                      */
/*----------------------------------------------------------------*/

private:

    VcpDigitalImageClock *m_timeClock;
	VcpDigitalTextClock  *m_dateClock;
    VfxImageFrame        *m_amPm;
    VfxImageFrame        *m_bg;
    VfxDateTime           m_dt;	

};


#endif

#endif

