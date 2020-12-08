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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vcui_videoclipper_gprot.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCUI_VIDEOCLIPPER__GPROT_H__
#define __VCUI_VIDEOCLIPPER__GPROT_H__

#if defined(__MMI_VIDEO_CLIPPER__)

#ifdef __cplusplus
extern "C"
{
#endif

#include "MMIDataType.h"
#include "mdi_video.h"
/***************************************************************************** 
 * VideoClipper CUI
 *****************************************************************************/
typedef enum
{
    VCUI_VIDEOCLIPPER_EVENT_RESULT_SUCCESS = VCUI_VIDEOCLIPPER,
    
    VCUI_VIDEOCLIPPER_EVENT_RESULT_FAILED, 
    
    VCUI_VIDEOCLIPPER_EVENT_TOTAL
} vcui_videoclipper_event_enum;

typedef struct 
{
    MMI_EVT_GROUP_PARAM_HEADER
    vcui_videoclipper_event_enum result;
    WCHAR filepath[SRV_FMGR_PATH_MAX_LEN];

} vcui_videoclipper_result_event_struct;

typedef struct
{
    VappVideoMsec curr_time;
    VappVideoMsec total_time;
    WCHAR filepath[SRV_FMGR_PATH_MAX_LEN];                   // video filepath
       
} vcui_videoclipper_param_struct;

extern MMI_BOOL vcui_videoclipper_is_available(const mdi_video_info_struct* video_info_p);
extern mmi_id vcui_videoclipper_create(mmi_id parent_id, vcui_videoclipper_param_struct *param);
extern void vcui_videoclipper_run(mmi_id cui_id);
extern void vcui_videoclipper_close(mmi_id cui_id);

#ifdef __cplusplus
}
#endif

#endif /* __MMI_VIDEO_CLIPPER__ */
#endif /* __VCUI_VIDEOCLIPPER__GPROT_H__ */
