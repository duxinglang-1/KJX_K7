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
 * vapp_sns_mem_def.h
 *
 * Project:
 * --------
 * 
 *
 * Description:
 * ------------
 * 
 *
 * Author:
 * -------
 * -------
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_SNS_MEM_DEF_H__
#define __VAPP_SNS_MEM_DEF_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"

#if defined(__MMI_MAINLCD_320X480__)
    #define VCUI_SNS_RESIZE_W (320)
    #define VCUI_SNS_RESIZE_H (480)
#elif defined(__MMI_MAINLCD_480X800__)
    #define VCUI_SNS_RESIZE_W (480)
    #define VCUI_SNS_RESIZE_H (800)
#elif defined(__MMI_MAINLCD_240X320__)
    #define VCUI_SNS_RESIZE_W (240)
    #define VCUI_SNS_RESIZE_H (320)
#else
    #define VCUI_SNS_RESIZE_W (240)
    #define VCUI_SNS_RESIZE_H (400)
#endif

#if defined(__MMI_MAINLCD_320X480__)
    #define VCUI_SNS_THUMB_BUF_SIZE (200*130*4)
#elif defined(__MMI_MAINLCD_480X800__)
    #define VCUI_SNS_THUMB_BUF_SIZE (300*200*4)
#else
    #define VCUI_SNS_THUMB_BUF_SIZE (150*100*4)
#endif

#define VCUI_SNS_RESIZE_UPLOADED_PIC_BUF_SIZE (VCUI_SNS_RESIZE_W*VCUI_SNS_RESIZE_H*2)

#ifdef __MMI_SNS_SLIM__
    #define VAPP_SNS_VFX_CACHE_FG_SIZE           (50*1024)
    #define VAPP_SNS_HAPPENINGS_CACHE_FG_SIZE    ((768*1024) + (VAPP_SNS_VFX_CACHE_FG_SIZE))
    #define VAPP_SNS_PROFILE_EXTRA_BASE_SIZE     (303300)
    #define VAPP_SNS_WIDGET_EXTRA_BASE_SIZE      (258000)
    #define VAPP_SNS_PLUGIN_MIN_MEMORY           (500*1024)
#else
    #define VAPP_SNS_VFX_CACHE_FG_SIZE           (50*1024)
    #define VAPP_SNS_HAPPENINGS_CACHE_FG_SIZE    ((1*1024*1024) + (VAPP_SNS_VFX_CACHE_FG_SIZE))
    #define VAPP_SNS_PROFILE_EXTRA_BASE_SIZE     (303300)
    #define VAPP_SNS_WIDGET_EXTRA_BASE_SIZE      (965700)
    #define VAPP_SNS_PLUGIN_MIN_MEMORY           (500*1024)
#endif /*__MMI_SNS_SLIM__*/

#endif /* __VAPP_SNS_MEM_DEF_H__ */
