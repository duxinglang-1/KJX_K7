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
 *  vapp_hs_main.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions from the Venus MMI to the Pluto
 *  MMI.
 *
 *      Venus APP ---> v2p adaptor ---> Pluto APP
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

#ifndef __VADP_V2P_HS_H__
#define __VADP_V2P_HS_H__

#include "MMI_Features.h"

#ifdef __MMI_VUI_HOMESCREEN__

#include "vfx_datatype.h"


#ifdef __cplusplus
extern "C"
{
#endif

#include "CustThemesRes.h"


/**********************************************************************
 * Default Constant Definitions
 **********************************************************************/

#ifdef __MRE_AM__
// Max. file name length of a VRE shortcut icon (UCS2 encoded).
#define VADP_V2P_HS_VAM_MAX_ICON_FILE_NAME_SIZE     32
#endif /* __MRE_AM__ */


/**********************************************************************
 * Structure Definitions
 **********************************************************************/

struct _UI_filled_area;


/**********************************************************************
 * External Interfaces
 **********************************************************************/

extern void vadp_v2p_hs_get_alarm_info(VfxU8 index, VfxU8 *state, VfxU8 *time_str);

extern void vadp_v2p_hs_set_alarm(VfxU8 index, VfxU8 state);

extern void vadp_v2p_hs_launch_dialer(void);

extern void vadp_v2p_hs_launch_main_menu(void);

#ifdef BROWSER_SUPPORT
extern void vadp_v2p_hs_launch_broswer(void);
#endif /* BROWSER_SUPPORT */

#ifdef __MMI_FILE_MANAGER__
extern void vadp_v2p_hs_launch_file_manager(void);
#endif /* __MMI_FILE_MANAGER__ */

extern void vadp_v2p_hs_launch_phone_settting(void);

extern void vadp_v2p_hs_launch_profiles(void);

extern void vadp_v2p_hs_launch_phonebook(void);

extern void vadp_v2p_hs_launch_call_history(void);

#if defined(__MOD_SMSAL__)
extern void vadp_v2p_hs_launch_message_center(void);
#endif /* defined(__MOD_SMSAL__) */

#ifdef __MMI_CALENDAR__
extern void vadp_v2p_hs_launch_calendar(void);
#endif /* __MMI_CALENDAR__ */

#ifdef __MMI_TODOLIST__
extern void vadp_v2p_hs_launch_todo(void);
#endif /* __MMI_TODOLIST__ */

extern void vadp_v2p_hs_launch_alarm(void);

#if defined(__MMI_CALCULATOR__) || defined(__MMI_MRE_CALCULATOR__)
extern void vadp_v2p_hs_launch_calculator(void);
#endif /* __MMI_CALCULATOR__ */

#ifdef __MMI_AUDIO_PLAYER__
extern void vadp_v2p_hs_launch_audio_player(void);
#endif /* __MMI_AUDIO_PLAYER__ */

#ifdef __MMI_VIDEO_PLAYER__
extern void vadp_v2p_hs_launch_video_player(void);
#endif /* __MMI_VIDEO_PLAYER__ */

#ifdef __MMI_MEDIA_PLAYER__
extern void vadp_v2p_hs_launch_media_player(void);
#endif /* __MMI_MEDIA_PLAYER__ */

#ifdef __MMI_VUI_3D_CUBE_APP__
extern void vadp_v2p_hs_launch_3d_cube(void);
#endif

#ifdef __MRE_AM__
extern VfxS32 vadp_v2p_hs_am_get_shortcut_number(void);

extern void vadp_v2p_hs_am_get_all_shortcut_id(VfxS32 *id, VfxU32 size);

extern void vadp_v2p_hs_am_get_shortcut_icon(VfxS32 id, VfxWChar *filename, VfxU32 size);

extern void vadp_v2p_hs_am_launch_shortcut(VfxS32 id);
#endif /* __MRE_AM__ */

#ifdef __MMI_GADGET_SUPPORT__
extern void vadp_v2p_hs_launch_widget_manager(void);
#endif

#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif /* __MMI_VUI_HOMESCREEN__ */
#endif /* __VADP_V2P_HS_H__ */

