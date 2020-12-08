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
 * Vapp_shell_msg_viewer.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef __VAPP_SHELL_MSG_VIEWER_CFG_H__
#define __VAPP_SHELL_MSG_VIEWER_CFG_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_SHELL_MSG_VIEWER__

/**********  KAL Layer Header **************/

/**********  MMI Layer Header **************/
#include "vrt_datatype.h"
#include "vfx_font_desc.h"
#include "vapp_notepaper_cfg.h"


/*****************************************************************************
 * Setting the No Message Icon
 *****************************************************************************/
#if defined(__MMI_MAINLCD_240X320__)
#define VAPP_SHELL_MV_NO_MESSAGE_ICON_Y_POSITION             71
#define VAPP_SHELL_MV_NO_MESSAGE_TEXT_COLOR                  VRT_COLOR_WHITE
#define VAPP_SHELL_MV_NO_MESSAGE_TEXT_BORDER_COLOR           VRT_COLOR_GREY
#define VAPP_SHELL_MV_NO_MESSAGE_TEXT_Y_POSITION             180
#define VAPP_SHELL_MV_NO_MESSAGE_TEXT_WIDTH                  156
#define VAPP_SHELL_MV_NO_MESSAGE_TEXT_HEIGTH                  18
#define VAPP_SHELL_MV_NO_MESSAGE_TEXT_SIZE                   VFX_FONT_DESC_VF_SIZE(16)
#elif defined(__MMI_MAINLCD_240X400__)
#define VAPP_SHELL_MV_NO_MESSAGE_ICON_Y_POSITION             101
#define VAPP_SHELL_MV_NO_MESSAGE_TEXT_COLOR                  VRT_COLOR_WHITE
#define VAPP_SHELL_MV_NO_MESSAGE_TEXT_BORDER_COLOR           VRT_COLOR_GREY
#define VAPP_SHELL_MV_NO_MESSAGE_TEXT_Y_POSITION             193
#define VAPP_SHELL_MV_NO_MESSAGE_TEXT_WIDTH                  100
#define VAPP_SHELL_MV_NO_MESSAGE_TEXT_HEIGTH                  18
#define VAPP_SHELL_MV_NO_MESSAGE_TEXT_SIZE                   VFX_FONT_DESC_VF_SIZE(16)
#elif defined(__MMI_MAINLCD_320X480__)
#define VAPP_SHELL_MV_NO_MESSAGE_ICON_Y_POSITION             123
#define VAPP_SHELL_MV_NO_MESSAGE_TEXT_COLOR                  VRT_COLOR_WHITE
#define VAPP_SHELL_MV_NO_MESSAGE_TEXT_BORDER_COLOR           VRT_COLOR_GREY
#define VAPP_SHELL_MV_NO_MESSAGE_TEXT_Y_POSITION             262
#define VAPP_SHELL_MV_NO_MESSAGE_TEXT_WIDTH                  156
#define VAPP_SHELL_MV_NO_MESSAGE_TEXT_HEIGTH                  22
#define VAPP_SHELL_MV_NO_MESSAGE_TEXT_SIZE                   VFX_FONT_DESC_VF_SIZE(20)
#else
#define VAPP_SHELL_MV_NO_MESSAGE_ICON_Y_POSITION             123
#define VAPP_SHELL_MV_NO_MESSAGE_TEXT_COLOR                  VRT_COLOR_WHITE
#define VAPP_SHELL_MV_NO_MESSAGE_TEXT_BORDER_COLOR           VRT_COLOR_GREY
#define VAPP_SHELL_MV_NO_MESSAGE_TEXT_Y_POSITION             262
#define VAPP_SHELL_MV_NO_MESSAGE_TEXT_WIDTH                  156
#define VAPP_SHELL_MV_NO_MESSAGE_TEXT_HEIGTH                  22
#define VAPP_SHELL_MV_NO_MESSAGE_TEXT_SIZE                   VFX_FONT_DESC_VF_SIZE(20)
#endif

/*****************************************************************************
 * Setting Note Paper Position
 *****************************************************************************/
#if defined(__MMI_MAINLCD_240X320__)
#define VAPP_SHELL_MV_NOTEPAPER_Y_POSITION          18
#elif defined(__MMI_MAINLCD_240X400__)
#define VAPP_SHELL_MV_NOTEPAPER_Y_POSITION          39
#elif defined(__MMI_MAINLCD_320X480__)
#define VAPP_SHELL_MV_NOTEPAPER_Y_POSITION          20
#else
#define VAPP_SHELL_MV_NOTEPAPER_Y_POSITION          20
#endif

/*****************************************************************************
 * Setting the Message Frame Font and Layout
 *****************************************************************************/
// Total size is (VAPP_NOTEPAPER_SIZE_X, VAPP_NOTEPAPER_SIZE_Y)
// The position is related the message viewer screen without status bar (20)
#if defined(__MMI_MAINLCD_240X320__)
#define VAPP_SHELL_MV_FRAME_BORDER_WIDTH                VAPP_NOTEPAPER_INTERNAL_BORDER_X
#define VAPP_SHELL_MV_FRAME_BORDER_HEIGTH               VAPP_NOTEPAPER_INTERNAL_BORDER_Y
#define VAPP_SHELL_MV_FRAME_MARGIN                      26

#define VAPP_SHELL_MV_FRAME_NAME_FONT_SIZE              VFX_FONT_DESC_VF_SIZE(16)
#define VAPP_SHELL_MV_FRAME_NAME_HEIGTH                 18
#define VAPP_SHELL_MV_FRAME_NAME_Y_POSITION             15

#define VAPP_SHELL_MV_FRAME_DATE_FONT_SIZE              VFX_FONT_DESC_VF_SIZE(10)
#define VAPP_SHELL_MV_FRAME_DATE_HEIGTH                 12
#define VAPP_SHELL_MV_FRAME_DATE_Y_POSITION             37

#define VAPP_SHELL_MV_FRAME_CONTENT_FONT_SIZE           VFX_FONT_DESC_VF_SIZE(12)
#define VAPP_SHELL_MV_FRAME_CONTENT_LINE_HEIGTH         26
#define VAPP_SHELL_MV_FRAME_CONTENT_LINE_NUMBER         3
#define VAPP_SHELL_MV_FRAME_CONTENT_TOTAL_HEIGTH        (VAPP_SHELL_MV_FRAME_CONTENT_LINE_HEIGTH * VAPP_SHELL_MV_FRAME_CONTENT_LINE_NUMBER)
#define VAPP_SHELL_MV_FRAME_CONTENT_Y_POSITION          51
//#define VAPP_SHELL_MV_FRAME_CONTENT_LINE_GAP            (27-14)   // heigth - font size

#define VAPP_SHELL_MV_FRAME_PAGE_FONT_SIZE              VFX_FONT_DESC_VF_SIZE(12)
#define VAPP_SHELL_MV_FRAME_PAGE_HEIGTH                 14
#define VAPP_SHELL_MV_FRAME_PAGE_Y_POSITION             153

#define VAPP_SHELL_MV_FRAME_NEW_MSG_ICON_X_POSITION     140
#define VAPP_SHELL_MV_FRAME_NEW_MSG_ICON_Y_POSITION     34

#elif defined(__MMI_MAINLCD_240X400__)
#define VAPP_SHELL_MV_FRAME_BORDER_WIDTH                VAPP_NOTEPAPER_INTERNAL_BORDER_X
#define VAPP_SHELL_MV_FRAME_BORDER_HEIGTH               VAPP_NOTEPAPER_INTERNAL_BORDER_Y
#define VAPP_SHELL_MV_FRAME_MARGIN                      11

#define VAPP_SHELL_MV_FRAME_NAME_FONT_SIZE              VFX_FONT_DESC_VF_SIZE(18)
#define VAPP_SHELL_MV_FRAME_NAME_HEIGTH                 20
#define VAPP_SHELL_MV_FRAME_NAME_Y_POSITION              5

#define VAPP_SHELL_MV_FRAME_DATE_FONT_SIZE              VFX_FONT_DESC_VF_SIZE(12)
#define VAPP_SHELL_MV_FRAME_DATE_HEIGTH                 14
#define VAPP_SHELL_MV_FRAME_DATE_Y_POSITION             25

#define VAPP_SHELL_MV_FRAME_CONTENT_FONT_SIZE           VFX_FONT_DESC_VF_SIZE(14)
#define VAPP_SHELL_MV_FRAME_CONTENT_LINE_HEIGTH         27
#define VAPP_SHELL_MV_FRAME_CONTENT_LINE_NUMBER         4
#define VAPP_SHELL_MV_FRAME_CONTENT_TOTAL_HEIGTH        (VAPP_SHELL_MV_FRAME_CONTENT_LINE_HEIGTH * VAPP_SHELL_MV_FRAME_CONTENT_LINE_NUMBER)
#define VAPP_SHELL_MV_FRAME_CONTENT_Y_POSITION          40

#define VAPP_SHELL_MV_FRAME_PAGE_FONT_SIZE              VFX_FONT_DESC_VF_SIZE(12)
#define VAPP_SHELL_MV_FRAME_PAGE_HEIGTH                 14
#define VAPP_SHELL_MV_FRAME_PAGE_Y_POSITION             179

#define VAPP_SHELL_MV_FRAME_NEW_MSG_ICON_X_POSITION     170
#define VAPP_SHELL_MV_FRAME_NEW_MSG_ICON_Y_POSITION     5

#elif defined(__MMI_MAINLCD_320X480__)
#define VAPP_SHELL_MV_FRAME_BORDER_WIDTH                VAPP_NOTEPAPER_INTERNAL_BORDER_X
#define VAPP_SHELL_MV_FRAME_BORDER_HEIGTH               VAPP_NOTEPAPER_INTERNAL_BORDER_Y
#define VAPP_SHELL_MV_FRAME_MARGIN                      15

#define VAPP_SHELL_MV_FRAME_NAME_FONT_SIZE              VFX_FONT_DESC_VF_SIZE(23)
#define VAPP_SHELL_MV_FRAME_NAME_HEIGTH                 25
#define VAPP_SHELL_MV_FRAME_NAME_Y_POSITION             27

#define VAPP_SHELL_MV_FRAME_DATE_FONT_SIZE              VFX_FONT_DESC_VF_SIZE(14)
#define VAPP_SHELL_MV_FRAME_DATE_HEIGTH                 16
#define VAPP_SHELL_MV_FRAME_DATE_Y_POSITION             56

#define VAPP_SHELL_MV_FRAME_CONTENT_FONT_SIZE           VFX_FONT_DESC_VF_SIZE(18)
#define VAPP_SHELL_MV_FRAME_CONTENT_LINE_HEIGTH         35
#define VAPP_SHELL_MV_FRAME_CONTENT_LINE_NUMBER         4
#define VAPP_SHELL_MV_FRAME_CONTENT_TOTAL_HEIGTH        (VAPP_SHELL_MV_FRAME_CONTENT_LINE_HEIGTH * VAPP_SHELL_MV_FRAME_CONTENT_LINE_NUMBER)
#define VAPP_SHELL_MV_FRAME_CONTENT_Y_POSITION          74

#define VAPP_SHELL_MV_FRAME_PAGE_FONT_SIZE              VFX_FONT_DESC_VF_SIZE(14)
#define VAPP_SHELL_MV_FRAME_PAGE_HEIGTH                 16
#define VAPP_SHELL_MV_FRAME_PAGE_Y_POSITION             249

#define VAPP_SHELL_MV_FRAME_NEW_MSG_ICON_X_POSITION     218
#define VAPP_SHELL_MV_FRAME_NEW_MSG_ICON_Y_POSITION     48

#else
#define VAPP_SHELL_MV_FRAME_BORDER_WIDTH                VAPP_NOTEPAPER_INTERNAL_BORDER_X
#define VAPP_SHELL_MV_FRAME_BORDER_HEIGTH               VAPP_NOTEPAPER_INTERNAL_BORDER_Y
#define VAPP_SHELL_MV_FRAME_MARGIN                      15

#define VAPP_SHELL_MV_FRAME_NAME_FONT_SIZE              VFX_FONT_DESC_VF_SIZE(23)
#define VAPP_SHELL_MV_FRAME_NAME_HEIGTH                 25
#define VAPP_SHELL_MV_FRAME_NAME_Y_POSITION             27

#define VAPP_SHELL_MV_FRAME_DATE_FONT_SIZE              VFX_FONT_DESC_VF_SIZE(14)
#define VAPP_SHELL_MV_FRAME_DATE_HEIGTH                 16
#define VAPP_SHELL_MV_FRAME_DATE_Y_POSITION             56

#define VAPP_SHELL_MV_FRAME_CONTENT_FONT_SIZE           VFX_FONT_DESC_VF_SIZE(18)
#define VAPP_SHELL_MV_FRAME_CONTENT_LINE_HEIGTH         35
#define VAPP_SHELL_MV_FRAME_CONTENT_LINE_NUMBER         4
#define VAPP_SHELL_MV_FRAME_CONTENT_TOTAL_HEIGTH        (VAPP_SHELL_MV_FRAME_CONTENT_LINE_HEIGTH * VAPP_SHELL_MV_FRAME_CONTENT_LINE_NUMBER)
#define VAPP_SHELL_MV_FRAME_CONTENT_Y_POSITION          74

#define VAPP_SHELL_MV_FRAME_PAGE_FONT_SIZE              VFX_FONT_DESC_VF_SIZE(14)
#define VAPP_SHELL_MV_FRAME_PAGE_HEIGTH                 16
#define VAPP_SHELL_MV_FRAME_PAGE_Y_POSITION             249

#define VAPP_SHELL_MV_FRAME_NEW_MSG_ICON_X_POSITION     218
#define VAPP_SHELL_MV_FRAME_NEW_MSG_ICON_Y_POSITION     22

#endif
/*****************************************************************************
 * Setting the Toolbar number and customize the icon
 *****************************************************************************/
#if defined(__MMI_MAINLCD_240X320__)
#define VAPP_SHELL_MV_TOOLBAR_Y_POSITION        224
#define VAPP_SHELL_MV_TOOLBAR_BUTTON_WIDTH      51
#define VAPP_SHELL_MV_TOOLBAR_BUTTON_HEIGTH     40
#elif defined(__MMI_MAINLCD_240X400__)
#define VAPP_SHELL_MV_TOOLBAR_Y_POSITION        301
#define VAPP_SHELL_MV_TOOLBAR_BUTTON_WIDTH      51
#define VAPP_SHELL_MV_TOOLBAR_BUTTON_HEIGTH     40
#elif defined(__MMI_MAINLCD_320X480__)
#define VAPP_SHELL_MV_TOOLBAR_Y_POSITION        364
#define VAPP_SHELL_MV_TOOLBAR_BUTTON_WIDTH      62
#define VAPP_SHELL_MV_TOOLBAR_BUTTON_HEIGTH     54
#else
#define VAPP_SHELL_MV_TOOLBAR_Y_POSITION        364
#define VAPP_SHELL_MV_TOOLBAR_BUTTON_WIDTH      62
#define VAPP_SHELL_MV_TOOLBAR_BUTTON_HEIGTH     54
#endif

#define VAPP_SHELL_MV_TOOLBAR_SETTING                   \
{                                                       \
    { IMG_ID_SHELL_MSG_VIEWER_TB_CREATE_NORMAL,         \
      IMG_ID_SHELL_MSG_VIEWER_TB_CREATE_PRESSED,        \
      IMG_ID_SHELL_MSG_VIEWER_TB_CREATE_DISABLED,       \
      0},                                               \
                                                        \
    { IMG_ID_SHELL_MSG_VIEWER_TB_REPLY_NORMAL,          \
      IMG_ID_SHELL_MSG_VIEWER_TB_REPLY_PRESSED,         \
      IMG_ID_SHELL_MSG_VIEWER_TB_REPLY_DISABLED,        \
      0},                                               \
                                                        \
    { IMG_ID_SHELL_MSG_VIEWER_TB_SWITCH_NORMAL,         \
      IMG_ID_SHELL_MSG_VIEWER_TB_SWITCH_PRESSED,        \
      IMG_ID_SHELL_MSG_VIEWER_TB_SWITCH_DISABLED,       \
      0},                                               \
                                                        \
    { VAPP_SHELL_IMG_DELETE_NOR,                        \
      VAPP_SHELL_IMG_DELETE_PRE,                        \
      VAPP_SHELL_IMG_DELETE_DIS,                        \
      0}                                                \
}

/*****************************************************************************
 * Class xyz
 *****************************************************************************/

/*****************************************************************************
 * Global Function
 *****************************************************************************/

#endif /* __MMI_VUI_SHELL_MSG_VIEWER__ */

#endif

