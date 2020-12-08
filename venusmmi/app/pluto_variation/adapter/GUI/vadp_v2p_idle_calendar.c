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
 *  vapp_v2p_idle_calendar.c
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions from the Venus MMI to 
 *  the Pluto Calendar components
 *
 *      Venus ---> v2p adaptor ---> Pluto 
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

#include "MMI_features.h"

// Pluto headers
#include "MMI_include.h"
#if defined(__MMI_CALENDAR_ON_IDLE_SCREEN__)
//#include "CalendarDef.h"
#include "app_datetime.h"
#include "CalendarProt.h"
#include "CalendarGprot.h"
#endif /* defined(__MMI_CALENDAR_ON_IDLE_SCREEN__) */
#include "wgui_calendar.h"
// Venus headers
#include "GUI\vadp_v2p_idle_calendar.h"

#include "vfx_datatype.h"
#include "string.h"
#include "gui_typedef.h"
#include "wgui_include.h"
#include "gui_calendar.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "wgui_categories_util.h"


/**********************************************************************
 * Global Functions
 **********************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_create_idle_calendar
 * DESCRIPTION
 *  Create idle calendar
 * PARAMETERS
 *  
 *  
 * RETURNS
 *  The handle of created idle calendar
 *****************************************************************************/
void vadp_v2p_create_idle_calendar(
      VfxS32 *width,
      VfxS32 *height,
      void (*update_screen_callback)(void *handle),
      void *update_screen_handle,
      VfxU32 display_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct max_time, min_time, current_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&min_time, 0, sizeof(applib_time_struct));
    memset(&max_time, 0, sizeof(applib_time_struct));
    memset(&current_time, 0, sizeof(applib_time_struct));
    min_time.nYear = GUI_CALENDAR_DEFAULT_FIRST_NAVI_YEAR;
    min_time.nMonth = 1;
    min_time.nDay = 1;
    max_time.nYear = GUI_CALENDAR_DEFAULT_LAST_NAVI_YEAR;
    max_time.nMonth = 12;
    max_time.nDay = 31;
    applib_dt_get_date_time(&current_time);

#if defined(__MMI_CALENDAR_ON_IDLE_SCREEN__) && (defined(__MMI_VUI_HOMESCREEN__) || defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__))
    #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
        wgui_calendar_create(
            GUI_CALENDAR_TYPE_WEEK,
            max_time,
            min_time,
            current_time);
        wgui_calendar_set_flags_on(GUI_CALENDAR_WEEK_DISPLAY_WEEKDAY_DATE_TWO_LINE);
    #else /* __MMI_OP11_HOMESCREEN_0301__ */
    wgui_calendar_create(
        GUI_CALENDAR_TYPE_MONTH,
        max_time,
        min_time,
        current_time);
    #endif /* __MMI_OP11_HOMESCREEN_0301__ */
	wgui_calendar_set_flags_on(GUI_CALENDAR_DISABLE_PREV_NEXT_SWITCH);
	wgui_calendar_set_on_idle(MMI_TRUE);
    wgui_calendar_get_dimension((S32 *)width, (S32 *)height);
    wgui_calendar_set_target_layer((GDI_HANDLE)display_layer);
        wgui_calendar_set_in_venus(MMI_TRUE);
    wgui_calendar_register_update_screen_callback(
        update_screen_callback,
        update_screen_handle);
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ && __MMI_VUI_HOMESCREEN__*/
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_close_idle_calendar
 * DESCRIPTION
 *  Close idle calendar
 * PARAMETERS
 *  handle      [IN/OUT]    calendar handle
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_close_idle_calendar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CALENDAR_ON_IDLE_SCREEN__) && (defined(__MMI_VUI_HOMESCREEN__) || defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__))
    wgui_calendar_close();
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ && __MMI_VUI_HOMESCREEN__*/
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_show_idle_calendar
 * DESCRIPTION
 *  Show the idle calendar in the current layer
 * PARAMETERS
 *  handle      [IN/OUT]    calendar handle
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_show_idle_calendar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CALENDAR_ON_IDLE_SCREEN__) && (defined(__MMI_VUI_HOMESCREEN__) || defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__))
    wgui_calendar_move(0, 0);
    wgui_calendar_set_venus_update(MMI_TRUE);
    wgui_calendar_idle_update();
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ && __MMI_VUI_HOMESCREEN__*/
}

