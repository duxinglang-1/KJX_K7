/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
//kcui
 *   vcui_tone_selector_gprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Tone Selector CUI prototype header file
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

//kcui
#ifndef __VCUI_TONE_SELECTOR_GPROT_H__
#define __VCUI_TONE_SELECTOR_GPROT_H__

#ifdef __cplusplus
extern "C"
{
#endif
#include "MMI_features.h"
#include "ProfilesSrv.h" 
#include "mdi_audio.h"
#include "Mmi_rp_srv_venus_component_tool_bar_def.h"
#include "Filemgrcuigprot.h"
#include "GlobalConstants.h"
#ifdef __cplusplus
}
#endif

#include "vfx_mc_include.h"


/***************************************************************************** 
 * Event declaration
 *****************************************************************************/
typedef enum
{
//kcui
    EVT_ID_VCUI_TONE_SELECTOR_RESULT = VCUI_TONE_SELECTOR + 1, /*CUI Result, only save, should not close CUI*/
    EVT_ID_VCUI_TONE_SELECTOR_CLOSE_REQUEST, /*Request app to close the CUI*/
    EVT_ID_VCUI_TONE_SELECTOR_MAX
}vcui_tone_selector_evt_enum;

typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER      /* in header: evt_id, size, user_data, sender_id */
    VfxBool     is_default_sound;   /* if it is MMI_FALSE, app need get file path from CUI*/
    VfxU16      selected_tone;      /* selected tone id */
//kcui
}vcui_tone_selector_evt_struct;

//kcui
enum
{
    VCUI_TONE_SELECTOR_FILTER_TONE       = 0x01, /*Message(short) sound which generated by framework resource gen*/
    VCUI_TONE_SELECTOR_FILTER_RING       = 0x02, /*Ring(long) sound which generated by framework resource gen*/  
    VCUI_TONE_SELECTOR_FILTER_FILE       = 0x04  /*External file*/
};

/*init filter*/
//kcui
#define VCUI_TONE_SELECTOR_FILTER_INIT(f)            ((f) = 0)
/*set filters, f: vFXU16, b:cui_tone_selector_tone_type_enum*/
#define VCUI_TONE_SELECTOR_FILTER_SET(f,b)           ((f) |= (b))
/*check the filter is set. f: vFXU16, b:cui_tone_selector_tone_type_enum*/
#define VCUI_TONE_SELECTOR_FILTER_IS_SET(f,b)        ((f) & (b))


#ifdef __cplusplus
extern "C"
{
#endif

//kcui
extern mmi_id vcui_tone_selector_create(mmi_id parent_id);
extern VfxS32 vcui_tone_selector_run(mmi_id cui_id);
extern VfxS32 vcui_tone_selector_set_title_id(mmi_id cui_id, VfxResId str_id, VfxResId img_id);
extern VfxS32 vcui_tone_selector_set_hightlight_tone(mmi_id cui_id, VfxS32 tone_id);
extern mmi_ret vcui_tone_selector_get_selected_filepath(mmi_id cui_id, srv_fmgr_fileinfo_struct *info, VfxWChar* path_buffer, VfxS32 path_size);
extern mmi_ret vcui_tone_selector_set_filter(mmi_id cui_id, VfxU16 filter);
extern mmi_ret vcui_tone_selector_set_user_data(mmi_id cui_id, void *data);
extern void* vcui_tone_selector_get_user_data (mmi_id cui_id);
extern void vcui_tone_selector_close(mmi_id cui_id);

#ifdef __cplusplus
}
#endif

#endif

