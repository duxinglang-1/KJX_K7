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
 * ImgEdtSrv.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Image Edit Service internal data type definitions
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

#ifndef __IMG_EDT_SRV_CONFIG_H__
#define __IMG_EDT_SRV_CONFIG_H__

#include "mmi_features.h"

#define SRV_IES_CAPS_FAST_ANIMX             (1)                                     // Turn on to use fast animation mode
#define SRV_IES_CAPS_PREFETCH_ON            (1)                                     // Turn on to make animation smooth

#define SRV_IES_MIN_EDITABLE_WIDTH          (10)                                    // Mininum editable source image width
#define SRV_IES_MIN_EDITABLE_HEIGHT         (10)                                    // Mininum editable source image height

#if defined(__MMI_COSMOS_IMGEDT_SLIM__)
#define SRV_IES_JPEG_MAX_MEGA_PIXEL         (3)                                     // Support up to 10MP JPEG image file
#define SRV_IES_MAX_EDITABLE_WIDTH          (2048)                                  // Maximum editable source image width
#define SRV_IES_MAX_EDITABLE_HEIGHT         (1536)                                  // Maximum editable source image heigh
#elif defined(__MMI_COSMOS_IMGEDT_PARTIAL__)
#define SRV_IES_JPEG_MAX_MEGA_PIXEL         (5)                                     // Support up to 10MP JPEG image file
#define SRV_IES_MAX_EDITABLE_WIDTH          (2592)                                  // Maximum editable source image width
#define SRV_IES_MAX_EDITABLE_HEIGHT         (1944)                                  // Maximum editable source image heigh
#else
#define SRV_IES_JPEG_MAX_MEGA_PIXEL         (8)                                     // Support up to 10MP JPEG image file
#define SRV_IES_MAX_EDITABLE_WIDTH          (3264)                                  // Maximum editable source image width
#define SRV_IES_MAX_EDITABLE_HEIGHT         (2448)                                  // Maximum editable source image heigh
#endif // __MMI_COSMOS_IMGEDT_SLIM__

#define SRV_IES_JPEG_MAX_PROG_WIDTH         (720)                                   // Max progressive JPEG width supported
#define SRV_IES_JPEG_MAX_PROG_HEIGHT        (720)                                   // Max progressive JPEG height supported
#define SRV_IES_JPEG_MAX_SAVE_WIDTH         (16384)                                   // Max save JPEG width supported
#define SRV_IES_JPEG_MAX_SAVE_HEIGHT        (16384)                                   // Max save JPEG height supported

#define SRV_IES_UTIL_MAX_HEAP_SIZE          (150 * 1024)                            // Maximum heap size for util sub-module

#define SRV_IES_STREAM_CHUNK_SIZE           (64 * 1024)                             // Maximum stream chunk size for decode

#define SRV_IES_DOODLE_LINE_SHAPE           SHAPE_CIRCLE                            // Default doodle line shape for editing

#define SRV_IES_JOB_MAX_JOB_COUNT           (16)                                    // Maximum job count for job sub-module
#define SRV_IES_JOB_ITER_PER_STEP           (20)                                    // Maximum interation count per step
#define SRV_IES_JOB_MAX_PROGRESS            (100)                                   // Maximum job progress percentage

#define SRV_IES_JPEG_MAX_FILE_SIZE          (3 * 1024 * 1024)                       // Support up to 3MB JPEG image file 
#define SRV_IES_JPEG_MAX_META_SIZE          (300 * 1024)                            // Support up to 300KB META data size

// The following info from experiments on 5MP images.
// (i.e. Tested 204.jpg on Victor56 landcape mode.)
// It may be affected by the following differences:
// 1. source image size
// 2. source dimension
// 3. output dimension
// 4. output color format
#if (SRV_IES_JPEG_MAX_MEGA_PIXEL == 10)
    #ifdef __COSMOS_MMI_PACKAGE__
    #define SRV_IES_ANIM_WORK_BUFFER        (3 * 1024 * 1024)                       // Buffer for animation and rendering
    #else
    #define SRV_IES_ANIM_WORK_BUFFER        (2616892)                               // Buffer for animation and rendering
    #endif  // __COSMOS_MMI_PACKAGE__
    #define SRV_IES_RENDER_WORK_BUFFER      (1991853)                               // Buffer for background rendering
#elif (SRV_IES_JPEG_MAX_MEGA_PIXEL == 8)
    #ifdef __COSMOS_MMI_PACKAGE__
    #define SRV_IES_ANIM_WORK_BUFFER        (3 * 1024 * 1024)                       // Buffer for animation and rendering
    #else
    #define SRV_IES_ANIM_WORK_BUFFER        (2270348)                               // Buffer for animation and rendering
    #endif  // __COSMOS_MMI_PACKAGE__
    #define SRV_IES_RENDER_WORK_BUFFER      (1645309)                               // Buffer for background rendering
#elif (SRV_IES_JPEG_MAX_MEGA_PIXEL == 5)
    #ifdef __COSMOS_MMI_PACKAGE__
    #define SRV_IES_ANIM_WORK_BUFFER        (3 * 1024 * 1024)                       // Buffer for animation and rendering
    #else
    #define SRV_IES_ANIM_WORK_BUFFER        (1758240)                               // Buffer for animation and rendering
    #endif // __COSMOS_MMI_PACKAGE__
    #define SRV_IES_RENDER_WORK_BUFFER      (1135393)                               // Buffer for background rendering
#elif (SRV_IES_JPEG_MAX_MEGA_PIXEL == 3)
    #define SRV_IES_ANIM_WORK_BUFFER        (1445788)                               // Buffer for animation and rendering
    #define SRV_IES_RENDER_WORK_BUFFER      (820749)                                // Buffer for background rendering
#elif (SRV_IES_JPEG_MAX_MEGA_PIXEL == 2)
    define SRV_IES_ANIM_WORK_BUFFER         (1224684)                               // Buffer for animation and rendering
    #define SRV_IES_RENDER_WORK_BUFFER      (599645)                                // Buffer for background rendering
#else
    #error "Please sepcify max JPEG supported mega pixels"
#endif


#ifdef __COSMOS_MMI_PACKAGE__
#define SRV_IES_META_WORK_BUFFER            (800 * 1024)                            // Memory buffer for creating meta
#define SRV_IES_FRAME_WORK_BUFFER           (3156400)                               // Memory buffer for frame operation
#define SRV_IES_ICON_WORK_BUFFER            (300 * 1024)                            // Memory buffer for icon operation
#define SRV_IES_DOODLE_WORK_BUFFER          (2004072)                               // Memory buffer for doodle operation
#define SRV_IES_SAVE_WORK_BUFFER            (2 * 1024 * 1024)                       // Memory buffer for save image file

#define SRV_IES_QVGA_FRAME_MARGIN           (281772)                                // Extra memory for saving QVGA frame
#define SRV_IES_WQVGA_FRAME_MARGIN          (339376)                                // Extra memory for saving WQVGA frame
#define SRV_IES_HVGA_FRAME_MARGIN           (513176)                                // Extra memory for saving HVGA frame
#define SRV_IES_VGA_FRAME_MARGIN            (975732)                                // Extra memory for saving VGA frame
#define SRV_IES_WVGA_FRAME_MARGIN           (1206220)                               // Extra memory for saving WVGA frame
#define SRV_IES_MAX_FRAME_MARGIN            (1258291)                               // Max memory size for saving frame
#else
#define SRV_IES_META_WORK_BUFFER            (800 * 1024)                            // Memory buffer for creating meta
#define SRV_IES_FRAME_WORK_BUFFER           (1923360)                               // Memory buffer for frame operation
#define SRV_IES_ICON_WORK_BUFFER            (300 * 1024)                            // Memory buffer for icon operation
#define SRV_IES_DOODLE_WORK_BUFFER          (900 * 1024)                            // Memory buffer for doodle operation
#define SRV_IES_SAVE_WORK_BUFFER            (900 * 1024)                            // Memory buffer for save image file

#define SRV_IES_QVGA_FRAME_MARGIN           (281772)                                // Extra memory for saving QVGA frame
#define SRV_IES_WQVGA_FRAME_MARGIN          (339376)                                // Extra memory for saving WQVGA frame
#define SRV_IES_HVGA_FRAME_MARGIN           (513176)                                // Extra memory for saving HVGA frame
#define SRV_IES_VGA_FRAME_MARGIN            (975732)                                // Extra memory for saving VGA frame
#define SRV_IES_WVGA_FRAME_MARGIN           (1206220)                               // Extra memory for saving WVGA frame
#define SRV_IES_MAX_FRAME_MARGIN            (1258291)                               // Max memory size for saving frame
#endif // __COSMOS_MMI_PACKAGE__

#define SRV_IES_CAPS_RAJPEG_CACHE           (800)                                   // Random access JPEG decoder cache buffer

#if SRV_IES_CAPS_PREFETCH_ON
    #if defined(__MMI_SRV_IES_META__) ||  defined(__MMI_SRV_IES_META_DB__)
        #define SRV_IES_VIEW_WORK_MEMORY    (SRV_IES_ANIM_WORK_BUFFER * 1) +        \
                                            (SRV_IES_RENDER_WORK_BUFFER * 1) +      \
                                            (SRV_IES_JPEG_MAX_FILE_SIZE * 1) +      \
                                            (SRV_IES_META_WORK_BUFFER * 1) +        \
                                            (SRV_IES_JPEG_MAX_META_SIZE * 5)
    #else
        #define SRV_IES_VIEW_WORK_MEMORY    (SRV_IES_ANIM_WORK_BUFFER * 1) +        \
                                            (SRV_IES_RENDER_WORK_BUFFER * 1) +      \
                                            (SRV_IES_JPEG_MAX_FILE_SIZE * 1)
    #endif

    #define SRV_IES_ALL_WORK_MEMORY         (SRV_IES_VIEW_WORK_MEMORY)

#else
    #if defined(__MMI_SRV_IES_META__) ||  defined(__MMI_SRV_IES_META_DB__)
        #define SRV_IES_VIEW_WORK_MEMORY    (SRV_IES_ANIM_WORK_BUFFER * 1) +        \
                                            (SRV_IES_RENDER_WORK_BUFFER * 1) +      \
                                            (SRV_IES_META_WORK_BUFFER * 1) +        \
                                            (SRV_IES_JPEG_MAX_META_SIZE * 5)
    #else
        #define SRV_IES_VIEW_WORK_MEMORY    (SRV_IES_ANIM_WORK_BUFFER * 1) +        \
                                            (SRV_IES_RENDER_WORK_BUFFER * 1)
    #endif

    #define SRV_IES_ALL_WORK_MEMORY         (SRV_IES_VIEW_WORK_MEMORY)
#endif

#define SRV_IES_EDIT_WORK_MEMORY            (SRV_IES_RENDER_WORK_BUFFER * 1) +      \
                                            (SRV_IES_CAPS_RAJPEG_CACHE * 1024) +    \
                                            (SRV_IES_FRAME_WORK_BUFFER * 1) +       \
                                            (SRV_IES_ICON_WORK_BUFFER * 1) +        \
                                            (SRV_IES_DOODLE_WORK_BUFFER * 1)

#endif  // __IMG_EDT_SRV_CONFIG_H__
