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
 *  vapp_home_gprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the external interface
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_HOME_GPROT_H
#define VAPP_HOME_GPROT_H

#include "MMI_features.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "lcd_sw_inc.h"


/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * Config
 *****************************************************************************/

/* The layout of the cells on the desktop. */
#if defined(__MMI_MAINLCD_480X800__)
#define VAPP_HOME_DESKTOP_HORIZ_TILE_NUM                (4)
#define VAPP_HOME_DESKTOP_VERTI_TILE_NUM                (5)
#define VAPP_HOME_DESKTOP_OUTER_BORDER_TOP_WIDTH        (78)
#define VAPP_HOME_DESKTOP_OUTER_BORDER_BOTTOM_WIDTH     (122)
#define VAPP_HOME_DESKTOP_OUTER_BORDER_LEFT_WIDTH       (0)
#define VAPP_HOME_DESKTOP_OUTER_BORDER_RIGHT_WIDTH      (0)
#define VAPP_HOME_DESKTOP_AUTO_SLIDE_BORDER_LEFT_WIDTH  (53)
#define VAPP_HOME_DESKTOP_AUTO_SLIDE_BORDER_RIGHT_WIDTH (53)
#elif defined(__MMI_MAINLCD_320X480__)
#define VAPP_HOME_DESKTOP_HORIZ_TILE_NUM                (4)
#define VAPP_HOME_DESKTOP_VERTI_TILE_NUM                (4)
#define VAPP_HOME_DESKTOP_OUTER_BORDER_TOP_WIDTH        (58)
#define VAPP_HOME_DESKTOP_OUTER_BORDER_BOTTOM_WIDTH     (86)
#define VAPP_HOME_DESKTOP_OUTER_BORDER_LEFT_WIDTH       (0)
#define VAPP_HOME_DESKTOP_OUTER_BORDER_RIGHT_WIDTH      (0)
#define VAPP_HOME_DESKTOP_AUTO_SLIDE_BORDER_LEFT_WIDTH  (35)
#define VAPP_HOME_DESKTOP_AUTO_SLIDE_BORDER_RIGHT_WIDTH (35)
#elif defined(__MMI_MAINLCD_240X400__)
#define VAPP_HOME_DESKTOP_HORIZ_TILE_NUM                (4)
#define VAPP_HOME_DESKTOP_VERTI_TILE_NUM                (4)
#define VAPP_HOME_DESKTOP_OUTER_BORDER_TOP_WIDTH        (54)
#define VAPP_HOME_DESKTOP_OUTER_BORDER_BOTTOM_WIDTH     (62)
#define VAPP_HOME_DESKTOP_OUTER_BORDER_LEFT_WIDTH       (0)
#define VAPP_HOME_DESKTOP_OUTER_BORDER_RIGHT_WIDTH      (0)
#define VAPP_HOME_DESKTOP_AUTO_SLIDE_BORDER_LEFT_WIDTH  (26)
#define VAPP_HOME_DESKTOP_AUTO_SLIDE_BORDER_RIGHT_WIDTH (26)
#else /* defined(__MMI_MAINLCD_240X320__) */
#define VAPP_HOME_DESKTOP_HORIZ_TILE_NUM                (4)
#define VAPP_HOME_DESKTOP_VERTI_TILE_NUM                (3)
#define VAPP_HOME_DESKTOP_OUTER_BORDER_TOP_WIDTH        (48)
#define VAPP_HOME_DESKTOP_OUTER_BORDER_BOTTOM_WIDTH     (62)
#define VAPP_HOME_DESKTOP_OUTER_BORDER_LEFT_WIDTH       (0)
#define VAPP_HOME_DESKTOP_OUTER_BORDER_RIGHT_WIDTH      (0)
#define VAPP_HOME_DESKTOP_AUTO_SLIDE_BORDER_LEFT_WIDTH  (26)
#define VAPP_HOME_DESKTOP_AUTO_SLIDE_BORDER_RIGHT_WIDTH (26)
#endif /* defined(__MMI_MAINLCD_240X320__) */


/*****************************************************************************
 * Macro
 *****************************************************************************/

/* Width of the region on the desktop that the user can put widgets on it. */
#define VAPP_HOME_DESKTOP_VALID_WIDTH               \
    (LCD_WIDTH -                                    \
     VAPP_HOME_DESKTOP_OUTER_BORDER_LEFT_WIDTH -    \
     VAPP_HOME_DESKTOP_OUTER_BORDER_RIGHT_WIDTH)

/* Height of the region on the desktop that the user can put widgets on it. */
#define VAPP_HOME_DESKTOP_VALID_HEIGHT              \
    (LCD_HEIGHT -                                   \
     VAPP_HOME_DESKTOP_OUTER_BORDER_TOP_WIDTH -     \
     VAPP_HOME_DESKTOP_OUTER_BORDER_BOTTOM_WIDTH)

/* Width of a tile on the desktop. */
#define VAPP_HOME_DESKTOP_TILE_WIDTH                                    \
    (VAPP_HOME_DESKTOP_VALID_WIDTH / VAPP_HOME_DESKTOP_HORIZ_TILE_NUM)

/* Height of a tile on the desktop. */
#define VAPP_HOME_DESKTOP_TILE_HEIGHT                                   \
    (VAPP_HOME_DESKTOP_VALID_HEIGHT / VAPP_HOME_DESKTOP_VERTI_TILE_NUM)

/* Width of the max room on the desktop. */
#define VAPP_HOME_DESKTOP_MAX_ROOM_WIDTH                                \
    (VAPP_HOME_DESKTOP_TILE_WIDTH * VAPP_HOME_DESKTOP_HORIZ_TILE_NUM)

/* Width of the max room on the desktop. */
#define VAPP_HOME_DESKTOP_MAX_ROOM_HEIGHT                               \
    (VAPP_HOME_DESKTOP_TILE_HEIGHT * VAPP_HOME_DESKTOP_VERTI_TILE_NUM)

/* DOM-NOT_FOR_SDK-END */


/****************************************************************************
 * Event Structure
 ****************************************************************************/

/* This is the structure for the EVT_ID_VAPP_HOME_ACTIVE. */
typedef struct
{
    MMI_EVT_PARAM_HEADER
} vapp_home_active_evt_struct;

/* This is the structure for the EVT_ID_VAPP_HOME_INACTIVE. */
typedef struct
{
    MMI_EVT_PARAM_HEADER
} vapp_home_inactive_evt_struct;


/*****************************************************************************
 * Structure
 *****************************************************************************/

/* Parameter structure for the Home launch function. */
typedef struct
{
    mmi_id base_app_id;
} vapp_home_launch_param_struct;


/*****************************************************************************
 * Function
 *****************************************************************************/

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_main_evt_hdlr
 * DESCRIPTION
 *  This function is the main event handler.
 * PARAMETERS
 *  event               : [IN]          Event
 * RETURNS
 *  void
 *****************************************************************************/
extern mmi_ret vapp_home_main_evt_hdlr(mmi_event_struct *event);

/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  vapp_home_launch
 * DESCRIPTION
 *  This function launches the home screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  Group ID of home screen App.
 *****************************************************************************/
extern MMI_ID vapp_home_launch(void *param, U32 param_size);


/*****************************************************************************
 * FUNCTION
 *  vapp_home_display
 * DESCRIPTION
 *  This function displays the home screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vapp_home_display();


/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  vapp_home_restart
 * DESCRIPTION
 *  This function restarts the home screen.
 *
 *  DO NOT CALL THIS FUNCTION UNLESS YOU KNOW CLEARLY WHAT THIS FUNCTION DOES.
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  Group ID of home screen App.
 *****************************************************************************/
extern MMI_ID vapp_home_restart();

/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  vapp_home_is_active
 * DESCRIPTION
 *  This function checks if the home App is active.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL vapp_home_is_active();


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* VAPP_HOME_GPROT_H */

