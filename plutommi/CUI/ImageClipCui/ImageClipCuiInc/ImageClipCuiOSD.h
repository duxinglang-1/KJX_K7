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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  ImageClipCuiOSD.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Image Clip Cui skin head file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
  ****************************************************************************/
#ifndef IMAGE_CLIP_CUI_OSD_H
#define IMAGE_CLIP_CUI_OSD_H

#include "MMI_features.h"
#ifdef __MMI_IMAGE_CLIP_CUI__

#include "ImageClipCui.h"

typedef struct
{
   U8 color_r;
   U8 color_g;
   U8 color_b;
} cui_image_clip_color_struct;

#ifdef __MMI_FTE_SUPPORT__
typedef struct
{
    cui_image_clip_rect_struct work_rect;         // work_rect

    cui_image_clip_pos_struct zin_btn_content;    // zoom in button content position
    cui_image_clip_pos_struct zout_btn_content;   // zoom out button content position

    cui_image_clip_rect_struct zin_btn_bg;        // zoom in button back ground rect        
    cui_image_clip_rect_struct zout_btn_bg;       // zoom out button back ground rect       

    cui_image_clip_rect_struct anim_bg;          // animation back ground rect
    cui_image_clip_pos_struct anim_str;          // animation string postion
    cui_image_clip_pos_struct anim;              // animation position

    cui_image_clip_color_struct clip_bg_color;   // clip layer bg color
    cui_image_clip_color_struct bound_color;     // bound color

    cui_image_clip_color_struct anim_str_color;  // animation string color
    cui_image_clip_color_struct hint_string_color;  // hint string color  
} cui_image_clip_skin_struct;
#else /* __MMI_FTE_SUPPORT__ */
typedef struct
{
    cui_image_clip_rect_struct work_rect;         // work_rect

    cui_image_clip_rect_struct zin_btn;        // zoom in button back ground rect        
    cui_image_clip_rect_struct zout_btn;       // zoom out button back ground rect       

    cui_image_clip_pos_struct anim;              // animation position

    cui_image_clip_color_struct clip_bg_color;   // clip layer bg color
    cui_image_clip_color_struct bound_color;     // bound color
    
    cui_image_clip_color_struct hint_string_color;  // hint string color  
} cui_image_clip_skin_struct;
#endif /* __MMI_FTE_SUPPORT__ */

extern cui_image_clip_skin_struct g_clip_skin_struct;

#endif /* __MMI_IMAGE_CLIP_CUI__ */

#endif /* IMAGE_CLIP_CUI_OSD_H */
