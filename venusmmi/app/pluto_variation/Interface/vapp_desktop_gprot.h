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
 *  vapp_desktop_gprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the interface of the desktop launcher.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_DESKTOP_GPROT_H
#define VAPP_DESKTOP_GPROT_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

#ifdef __cplusplus
extern "C"
{
#endif

#include "MMIDataType.h"


/*****************************************************************************
 * Include
 *****************************************************************************/


/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * Config
 *****************************************************************************/

#if defined(__MMI_MAINLCD_480X800__)
#define VAPP_DESKTOP_PAGE_HORIZ_TILE_NUM                (4)
#define VAPP_DESKTOP_PAGE_VERTI_TILE_NUM                (5)
#define VAPP_DESKTOP_PAGE_OUTER_BORDER_TOP_WIDTH        (78)
#define VAPP_DESKTOP_PAGE_OUTER_BORDER_BOTTOM_WIDTH     (122)
#define VAPP_DESKTOP_PAGE_OUTER_BORDER_LEFT_WIDTH       (0)
#define VAPP_DESKTOP_PAGE_OUTER_BORDER_RIGHT_WIDTH      (0)
#define VAPP_DESKTOP_PAGE_AUTO_SLIDE_BORDER_LEFT_WIDTH  (53)
#define VAPP_DESKTOP_PAGE_AUTO_SLIDE_BORDER_RIGHT_WIDTH (53)
#elif defined(__MMI_MAINLCD_320X480__)
#define VAPP_DESKTOP_PAGE_HORIZ_TILE_NUM                (4)
#define VAPP_DESKTOP_PAGE_VERTI_TILE_NUM                (4)
#define VAPP_DESKTOP_PAGE_OUTER_BORDER_TOP_WIDTH        (58)
#define VAPP_DESKTOP_PAGE_OUTER_BORDER_BOTTOM_WIDTH     (86)
#define VAPP_DESKTOP_PAGE_OUTER_BORDER_LEFT_WIDTH       (0)
#define VAPP_DESKTOP_PAGE_OUTER_BORDER_RIGHT_WIDTH      (0)
#define VAPP_DESKTOP_PAGE_AUTO_SLIDE_BORDER_LEFT_WIDTH  (35)
#define VAPP_DESKTOP_PAGE_AUTO_SLIDE_BORDER_RIGHT_WIDTH (35)
#elif defined(__MMI_MAINLCD_240X400__)
#define VAPP_DESKTOP_PAGE_HORIZ_TILE_NUM                (3)
#define VAPP_DESKTOP_PAGE_VERTI_TILE_NUM                (4)
#define VAPP_DESKTOP_PAGE_OUTER_BORDER_TOP_WIDTH        (54)
#define VAPP_DESKTOP_PAGE_OUTER_BORDER_BOTTOM_WIDTH     (62)
#define VAPP_DESKTOP_PAGE_OUTER_BORDER_LEFT_WIDTH       (0)
#define VAPP_DESKTOP_PAGE_OUTER_BORDER_RIGHT_WIDTH      (0)
#define VAPP_DESKTOP_PAGE_AUTO_SLIDE_BORDER_LEFT_WIDTH  (26)
#define VAPP_DESKTOP_PAGE_AUTO_SLIDE_BORDER_RIGHT_WIDTH (26)
#else /* defined(__MMI_MAINLCD_240X320__) */
#define VAPP_DESKTOP_PAGE_HORIZ_TILE_NUM                (3)
#define VAPP_DESKTOP_PAGE_VERTI_TILE_NUM                (3)
#define VAPP_DESKTOP_PAGE_OUTER_BORDER_TOP_WIDTH        (48)
#define VAPP_DESKTOP_PAGE_OUTER_BORDER_BOTTOM_WIDTH     (62)
#define VAPP_DESKTOP_PAGE_OUTER_BORDER_LEFT_WIDTH       (0)
#define VAPP_DESKTOP_PAGE_OUTER_BORDER_RIGHT_WIDTH      (0)
#define VAPP_DESKTOP_PAGE_AUTO_SLIDE_BORDER_LEFT_WIDTH  (26)
#define VAPP_DESKTOP_PAGE_AUTO_SLIDE_BORDER_RIGHT_WIDTH (26)
#endif /* defined(__MMI_MAINLCD_240X320__) */


/*****************************************************************************
 * Macro
 *****************************************************************************/

/* Width of the region on the desktop that the user can put widgets on it. */
#define VAPP_DESKTOP_PAGE_VALID_WIDTH               \
    (LCD_WIDTH -                                    \
     VAPP_DESKTOP_PAGE_OUTER_BORDER_LEFT_WIDTH -    \
     VAPP_DESKTOP_PAGE_OUTER_BORDER_RIGHT_WIDTH)

/* Height of the region on the desktop that the user can put widgets on it. */
#define VAPP_DESKTOP_PAGE_VALID_HEIGHT              \
    (LCD_HEIGHT -                                   \
     VAPP_DESKTOP_PAGE_OUTER_BORDER_TOP_WIDTH -     \
     VAPP_DESKTOP_PAGE_OUTER_BORDER_BOTTOM_WIDTH)

/* Width of a tile on the desktop. */
#define VAPP_DESKTOP_PAGE_TILE_WIDTH                                    \
    (VAPP_DESKTOP_PAGE_VALID_WIDTH / VAPP_DESKTOP_PAGE_HORIZ_TILE_NUM)

/* Height of a tile on the desktop. */
#define VAPP_DESKTOP_PAGE_TILE_HEIGHT                                   \
    (VAPP_DESKTOP_PAGE_VALID_HEIGHT / VAPP_DESKTOP_PAGE_VERTI_TILE_NUM)

/* Width of the max room on the desktop. */
#define VAPP_DESKTOP_PAGE_MAX_ROOM_WIDTH                                \
    (VAPP_DESKTOP_PAGE_TILE_WIDTH * VAPP_DESKTOP_PAGE_HORIZ_TILE_NUM)

/* Width of the max room on the desktop. */
#define VAPP_DESKTOP_PAGE_MAX_ROOM_HEIGHT                               \
    (VAPP_DESKTOP_PAGE_TILE_HEIGHT * VAPP_DESKTOP_PAGE_VERTI_TILE_NUM)

/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vapp_desktop_create
 * DESCRIPTION
 *  This function creates the desktop of the launcher.
 * PARAMETERS
 *  group_id  : [IN] parent group ID of app category
 * RETURNS
 *  void
 *****************************************************************************/
extern void vapp_desktop_create(MMI_ID group_id);


/*****************************************************************************
 * FUNCTION
 *  vapp_desktop_release
 * DESCRIPTION
 *  This function releases the desktop of the launcher.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vapp_desktop_release(void);


/*****************************************************************************
 * FUNCTION
 *  vapp_desktop_launch
 * DESCRIPTION
 *  This function is a dummy function used in the resource XML. It always
 *  return GRP_ID_INVALID because only the Bootup App can launch the desktop.
 * PARAMETERS
 *  param           : [IN]      Paramter
 *  param_size      : [IN]      Parameter size
 * RETURNS
 *  Group ID.
 *****************************************************************************/
extern MMI_ID vapp_desktop_launch(void *param, U32 param_size);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* defined(__MMI_VUI_LAUNCHER__) */
#endif /* VAPP_DESKTOP_GPROT_H */

