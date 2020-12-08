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
 * vapp_shell_mediaplayer_cfg.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef __VAPP_SHELL_MEDIA_PLAYER_CFG_H__
#define __VAPP_SHELL_MEDIA_PLAYER_CFG_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_SHELL_MULTI_PAGE__

/*****************************************************************************
 * Setting the Toolbar number and customize the icon
 *****************************************************************************/
#if defined(__MMI_MAINLCD_320X480__)
#define VAPP_SHELL_MP_TOOLBAR_Y_POSITION        364
#define VAPP_SHELL_MP_TOOLBAR_BUTTON_WIDTH      82
#define VAPP_SHELL_MP_TOOLBAR_BUTTON_HEIGTH     54
#elif defined(__MMI_MAINLCD_240X400__)
#define VAPP_SHELL_MP_TOOLBAR_Y_POSITION        297
#define VAPP_SHELL_MP_TOOLBAR_BUTTON_WIDTH      66
#define VAPP_SHELL_MP_TOOLBAR_BUTTON_HEIGTH     38
#elif defined(__MMI_MAINLCD_240X320__)
#define VAPP_SHELL_MP_TOOLBAR_Y_POSITION        220
#define VAPP_SHELL_MP_TOOLBAR_BUTTON_WIDTH      66
#define VAPP_SHELL_MP_TOOLBAR_BUTTON_HEIGTH     38
#endif
#define VAPP_SHELL_MP_TOOLBAR_SETTING            \
{                                                \
    { IMG_ID_SHELL_MEDIAPLAYER_PREV_NOR,         \
      IMG_ID_SHELL_MEDIAPLAYER_PREV_PRE,         \
      IMG_ID_SHELL_MEDIAPLAYER_PREV_DIS,         \
      0},                                        \
                                                 \
    { IMG_ID_SHELL_MEDIAPLAYER_PLAY_NOR,         \
      IMG_ID_SHELL_MEDIAPLAYER_PLAY_PRE,         \
      IMG_ID_SHELL_MEDIAPLAYER_PLAY_DIS,         \
      0},                                        \
                                                 \
    { IMG_ID_SHELL_MEDIAPLAYER_NEXT_NOR,         \
      IMG_ID_SHELL_MEDIAPLAYER_NEXT_PRE,         \
      IMG_ID_SHELL_MEDIAPLAYER_NEXT_DIS,         \
      0}                                         \
}

/*****************************************************************************
 * Class xyz
 *****************************************************************************/

/*****************************************************************************
 * Global Function
 *****************************************************************************/

#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */

#endif

