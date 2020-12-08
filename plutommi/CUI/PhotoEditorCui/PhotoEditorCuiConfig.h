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
 *  PhotoEditorCuiConfig.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Photo Art Applcation Header of PhotoEditor
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _PHOEDT_CUI_CONFIG_H_
#define _PHOEDT_CUI_CONFIG_H_

#include "MMI_features.h"

#ifdef __MMI_PHOTOEDITOR__
#include "Mmi_rp_app_phoedt_def.h"
#include "ImgEdtSrvGprot.h"

/* effect & adjust ***********************************************************************************/
#define PHOEDT_EFFECT_MAX_COUNT             (10)  /* maxinum count of effect which under "Add effect" */
#define PHOEDT_ADJUST_MAX_COUNT             (5)   /* maxinum count of adjust which under "Adjust" */
#define PHOEDT_ADJUST_ITEM_TOTAL_COUNT      (5)   /* maxinum sum count of sub-items of all adjust */
#define PHOEDT_ADJUST_MAX_STEP_COUNT        (10)  /* maxinum step count of all sub-items of all adjust */
#define PHOEDT_ADJUST_MIN_STEP_COUNT        (2)   /* mininum step count of all sub-items of all adjust */

typedef struct
{
    srv_ies_effect_param_enum   para_id;
    MMI_IMG_ID                  para_icon;
}phoedt_adjust_para_icon_struct;

static const phoedt_adjust_para_icon_struct g_phoedt_adjust_para_icons[] =
{
    {SRV_IES_EFFECT_PARAM_BRIGHTNESS_STRENGTH,      IMG_ID_PHOEDT_ADJUST_BRIGHTNESS},
    {SRV_IES_EFFECT_PARAM_CONTRAST_STRENGTH,        IMG_ID_PHOEDT_ADJUST_CONTRAST},
    {SRV_IES_EFFECT_PARAM_SHARPNESS_STRENGTH,       IMG_ID_PHOEDT_ADJUST_SHARPNESS},
    {SRV_IES_EFFECT_PARAM_HUE_ADJUST,               IMG_ID_PHOEDT_ADJUST_HUE},
    {SRV_IES_EFFECT_PARAM_SATURATION_STRENGTH,      IMG_ID_PHOEDT_ADJUST_SATURATION},

    {SRV_IES_EFFECT_PARAM_INVALID,                  0}
};
/* effect & adjust ***********************************************************************************/


/* action limitation *********************************************************************************/
typedef enum
{
    PHOEDT_LIMIT_TYPE_TOTAL,
    PHOEDT_LIMIT_TYPE_FRAME,
    PHOEDT_LIMIT_TYPE_ICON,
    PHOEDT_LIMIT_TYPE_DOODLE,

    PHOEDT_LIMIT_TYPE_COUNT
} phoedt_limit_type_enum;

#define PHOEDT_LIMIT_CHANGE_COUNT_TOTAL     (30)
#define PHOEDT_LIMIT_CHANGE_COUNT_FRAME     (1)
#define PHOEDT_LIMIT_CHANGE_COUNT_ICON      (4)
#define PHOEDT_LIMIT_CHANGE_COUNT_DOODLE    (1)

static const U8 g_phoedt_limit_values[PHOEDT_LIMIT_TYPE_COUNT] =
{
    PHOEDT_LIMIT_CHANGE_COUNT_TOTAL,        /* PHOEDT_LIMIT_TYPE_TOTAL */
    PHOEDT_LIMIT_CHANGE_COUNT_FRAME,        /* PHOEDT_LIMIT_TYPE_FRAME */
    PHOEDT_LIMIT_CHANGE_COUNT_ICON,         /* PHOEDT_LIMIT_TYPE_ICON */
    PHOEDT_LIMIT_CHANGE_COUNT_DOODLE        /* PHOEDT_LIMIT_TYPE_DOODLE */
};
/* action limitation *********************************************************************************/


#endif /* __MMI_PHOTOEDITOR__ */
#endif /* _PHOEDT_CUI_CONFIG_H_ */

