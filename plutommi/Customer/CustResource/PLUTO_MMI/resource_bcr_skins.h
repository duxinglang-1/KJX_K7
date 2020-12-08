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
 *  Resource_bcr_skins.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  BCR Application
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
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef MMI_BCR_SKIN_H
#define MMI_BCR_SKIN_H

#include "mmi_features.h"
#ifdef __MMI_BCR__

typedef enum
{
    MMI_BCR_TEXT_STYLE_NORMAL,
    MMI_BCR_TEXT_STYLE_BORDER,
    MMI_BCR_TEXT_STYLE_SHADOW
} mmi_bcr_text_style;


typedef struct
{
    MMI_BOOL is_show;
    S32 offset_x;
    S32 offset_y;
} mmi_bcr_osd_icon_struct;

typedef struct
{
    U8 r;
    U8 g;
    U8 b;
    U8 style_r;
    U8 style_g;
    U8 style_b;
    U16 style;
} mmi_bcr_style_text_struct;

typedef struct
{
    MMI_BOOL is_draw_mmi_softkey;
    mmi_bcr_style_text_struct lsk;
    mmi_bcr_style_text_struct rsk;
} mmi_bcr_osd_softkey_struct;

typedef struct
{
    MMI_BOOL is_show;
    mmi_bcr_style_text_struct style_text;
} mmi_bcr_osd_hint_box_struct;

typedef struct
{
    MMI_BOOL is_use;

    S32 offset_x;
    S32 offset_y;
    S32 width;
    S32 height;
}mmi_bcr_osd_layer_struct;

typedef struct
{
    /* softkey*/
    mmi_bcr_osd_icon_struct lsk;
    mmi_bcr_osd_icon_struct rsk;

    /* status icons */
    mmi_bcr_osd_icon_struct flash;
    mmi_bcr_osd_icon_struct ev;
    mmi_bcr_osd_icon_struct ev_inc;
    mmi_bcr_osd_icon_struct ev_dec;
    mmi_bcr_osd_icon_struct af_mode;
    mmi_bcr_osd_icon_struct capture;
    mmi_bcr_osd_icon_struct banding;
    mmi_bcr_osd_icon_struct zoom;
    mmi_bcr_osd_icon_struct zoom_digit;
    mmi_bcr_osd_icon_struct zoom_in; 
    mmi_bcr_osd_icon_struct zoom_out;
    
    mmi_bcr_osd_hint_box_struct hint_box;   

    mmi_bcr_osd_layer_struct softkey_layer;
    mmi_bcr_osd_layer_struct hint_layer;
    mmi_bcr_osd_layer_struct icon_layer;

} mmi_bcr_osd_layeout_struct;

extern mmi_bcr_osd_layeout_struct g_bcr_osd_cntx;

extern mmi_bcr_osd_layeout_struct g_bcr_osd_cntx_270;


#endif /* __MMI_BCR__ */ 
#endif /* _BCR_SKIN_H_ */

