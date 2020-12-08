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
 *  vcui_wallpaper_setting_gprot.h
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VCUI_WALLPAPER_SETTING_GPROT_H__
#define __VCUI_WALLPAPER_SETTING_GPROT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
    EVT_ID_CUI_WALLPAPER_SETTING_DONE = GET_RESOURCE_BASE(VCUI_WALLPAPER_SETTING),
    EVT_ID_CUI_WALLPAPER_SETTING_ERROR,
    EVT_ID_CUI_WALLPAPER_SETTING_CANCEL,

    EVT_ID_CUI_WALLPAPER_SETTING_EVENT_END
} cui_wallpaper_setting_event_enum;

typedef enum
{
    CUI_WALLPAPER_SETTING_HOME_SCREEN,
    CUI_WALLPAPER_SETTING_LOCK_SCREEN,
//    CUI_WALLPAPER_SETTING_MAIN_MENU,
    CUI_VIDEO_PWR_ON_SETTING,
    CUI_VIDEO_PWR_OFF_SETTING,
    
    CUI_WALLPAPER_SETTING_SCREEN_TYPE_END
} cui_wallpaper_setting_screen_type_enum;

typedef enum
{
    CUI_WALLPAPER_SETTING_NO_ERROR,

    CUI_WALLPAPER_SETTING_INVALID_FORMAT,
    CUI_WALLPAPER_SETTING_NOT_ENOUGH_SIZE,
    CUI_WALLPAPER_SETTING_FAIL_TO_SAVE,

    EVT_ID_CUI_WALLPAPER_SETTING_ERROR_END
} cui_wallpaper_setting_error_enum;

typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
    cui_wallpaper_setting_error_enum error_code;
} cui_wallpaper_setting_event_struct;

typedef struct
{
    cui_wallpaper_setting_screen_type_enum screen_type;
    WCHAR *filename;
    void *user_data;
} cui_wallpaper_setting_create_struct;

extern mmi_id vcui_wallpaper_setting_create(mmi_id parent_gid, cui_wallpaper_setting_create_struct *data);
extern void vcui_wallpaper_setting_run(mmi_id cui_gid);
extern void vcui_wallpaper_setting_close(mmi_id cui_gid);
/***************************************************************************** 
 * Class 
 *****************************************************************************/

#endif /* __VCUI_WALLPAPER_SETTING_GPROT_H__ */
 
