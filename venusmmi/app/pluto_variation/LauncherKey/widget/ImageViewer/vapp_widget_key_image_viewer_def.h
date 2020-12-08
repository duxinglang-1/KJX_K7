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
 *  vapp_widget_key_image_viewer_def.h
 *
 * Project:
 * --------
 *  MAUI
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
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_WIDGET_KEY_IMAGE_VIEWER_DEF_H
#define VAPP_WIDGET_KEY_IMAGE_VIEWER_DEF_H

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_KEY_IMAGE_VIEWER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_basic_type.h"
#include "vcp_include.h" 

#include "mmi_rp_app_venus_widget_key_image_viewer_def.h"

#include "trc/vadp_app_trc.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "SST_sla.h"
#include "kal_trace.h"
#include "MMI_common_app_trc.h"

#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * Defines
 *****************************************************************************/

/*
 * Catcher logging:
 */
#if defined(__MTK_TARGET__)
#define VAPP_WKIV_LOG_EX(...) MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, __VA_ARGS__)
#define VAPP_WKIV_LOG(_x)     VAPP_WKIV_LOG_EX _x
#else
#define VAPP_WKIV_LOG(_x)  
#endif /* defined(__MTK_TARGET__) */

/*
 * SWLA logging:
 */
#if defined(__MTK_TARGET__)
#define VAPP_WKIV_SLA(_x)       SLA_CustomLogging _x
#else
#define VAPP_WKIV_SLA(_x)
#endif

/*
 * Layout:
 */

/* HVGA */   
#if defined(__MMI_MAINLCD_320X480__)
    
    #define VIEW_PANEL_WIDTH                    (244)
    #define VIEW_PANEL_HEIGHT                   (254)
    
    #define CELL_WIDTH                          (206)
    #define CELL_HEIGHT                         (216)

    #define CELL_PREV_POS                       (VfxPoint(CELL_WIDTH/2, -CELL_HEIGHT/2 - 20))
    #define CELL_CURR_POS                       (VfxPoint(CELL_WIDTH/2, CELL_HEIGHT/2))
    #define CELL_NEXT_POS                       (VfxPoint(CELL_WIDTH/2, (CELL_HEIGHT*3)/2 + 20))

/* QVGA */      
#elif defined(__MMI_MAINLCD_240X320__)
    
    #define VIEW_PANEL_WIDTH                    (186)
    #define VIEW_PANEL_HEIGHT                   (196)    
    #define CELL_WIDTH                          (162)
    #define CELL_HEIGHT                         (172)
    #define CELL_PREV_POS                       (VfxPoint(CELL_WIDTH/2, -CELL_HEIGHT/2 - 15))
    #define CELL_CURR_POS                       (VfxPoint(CELL_WIDTH/2, CELL_HEIGHT/2))
    #define CELL_NEXT_POS                       (VfxPoint(CELL_WIDTH/2, (CELL_HEIGHT*3)/2 + 15))
    
/* WQVGA */   
#elif defined(__MMI_MAINLCD_240X400__)
    
    #define VIEW_PANEL_WIDTH                    (186)
    #define VIEW_PANEL_HEIGHT                   (196)    
    #define CELL_WIDTH                          (162)
    #define CELL_HEIGHT                         (172)
    #define CELL_PREV_POS                       (VfxPoint(CELL_WIDTH/2, -CELL_HEIGHT/2 - 15))
    #define CELL_CURR_POS                       (VfxPoint(CELL_WIDTH/2, CELL_HEIGHT/2))
    #define CELL_NEXT_POS                       (VfxPoint(CELL_WIDTH/2, (CELL_HEIGHT*3)/2 + 15))

/* LQVGA */   
#elif defined(__MMI_MAINLCD_320X240__)
    
    #define VIEW_PANEL_WIDTH                    (206)
    #define VIEW_PANEL_HEIGHT                   (146)    
    #define CELL_WIDTH                          (168)
    #define CELL_HEIGHT                         (122)
    #define CELL_PREV_POS                       (VfxPoint(CELL_WIDTH/2, -CELL_HEIGHT/2 - 15))
    #define CELL_CURR_POS                       (VfxPoint(CELL_WIDTH/2, CELL_HEIGHT/2))
    #define CELL_NEXT_POS                       (VfxPoint(CELL_WIDTH/2, (CELL_HEIGHT*3)/2 + 15))

#endif


#define IMAGE_SWITCH_DURATION                   (500)

typedef enum
{
    SWITCH_TYPE_PREV,
    SWITCH_TYPE_NEXT,
    SWITCH_TYPE_STATIC,
    SWITCH_TYPE_TOTAL

}VappWidgetKeyImageViewerSwitchTypeEnum;

typedef enum
{
    FILE_LIST_EMPTY,
    FILE_LIST_RESET,
    FILE_LIST_DIRTY,
    MEDIA_CACHE_START
    
}VappWidgetKeyImageViewerMsgEnum;

#endif

#endif

