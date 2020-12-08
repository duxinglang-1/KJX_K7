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
 * Vapp_notepaper_cfg.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __VAPP_NOTEPAPER_CFG_H__
#define __VAPP_NOTEPAPER_CFG_H__

/*****************************************************************************
 * Setting NotePaper size and real border
 *****************************************************************************/

#if defined(__MMI_MAINLCD_240X320__)
#define VAPP_NOTEPAPER_SIZE_X               206
#define VAPP_NOTEPAPER_SIZE_Y               200
#define VAPP_NOTEPAPER_INTERNAL_BORDER_X    14
#define VAPP_NOTEPAPER_INTERNAL_BORDER_Y    8
#elif defined(__MMI_MAINLCD_240X400__)
#define VAPP_NOTEPAPER_SIZE_X               240
#define VAPP_NOTEPAPER_SIZE_Y               252
#define VAPP_NOTEPAPER_INTERNAL_BORDER_X    15
#define VAPP_NOTEPAPER_INTERNAL_BORDER_Y    31
#elif defined(__MMI_MAINLCD_320X480__)
#define VAPP_NOTEPAPER_SIZE_X               320
#define VAPP_NOTEPAPER_SIZE_Y               327
#define VAPP_NOTEPAPER_INTERNAL_BORDER_X    28
#define VAPP_NOTEPAPER_INTERNAL_BORDER_Y    31
#else
#define VAPP_NOTEPAPER_SIZE_X               320
#define VAPP_NOTEPAPER_SIZE_Y               327
#define VAPP_NOTEPAPER_INTERNAL_BORDER_X    28
#define VAPP_NOTEPAPER_INTERNAL_BORDER_Y    31
#endif
/*****************************************************************************
 * Setting NotePaper Flip Page Effect
 *****************************************************************************/
#define VAPP_NOTEPAPER_FLIP_FRAME_RATE          15
#define VAPP_NOTEPAPER_FLIP_FRAME_NUMBER         8
#define VAPP_NOTEPAPER_FLIP_TIME_INTERVAL_MS    (1000 / VAPP_NOTEPAPER_FLIP_FRAME_RATE)

#if defined(__MMI_MAINLCD_240X320__)
/* x, y, width, heigth related to notepaper */
#define VAPP_NOTEPAPER_SCROLL_IMAGE_POSITION  {13,   0, 183, 45}
#define VAPP_NOTEPAPER_BOTTOM_IMAGE_POSITION  {13, 147, 180, 28}
#define VAPP_NOTEPAPER_FLIP_FRAME_POSITION                  \
{                                                           \
    {13, 134, 184,  56},        /* flipping page 1 */       \
    { 8, 124, 191,  64},        /* flipping page 2 */       \
    { 8, 105, 194,  66},        /* flipping page 3 */       \
    { 8,  88, 198,  67},        /* flipping page 4 */       \
    { 1,  67, 203,  66},        /* flipping page 5 */       \
    { 3,   9, 200,  83},        /* flipping page 6 */       \
    { 3,   0, 201,  73},        /* flipping page 7 */       \
    {11,   0, 184,  40}         /* flipping page 8 */       \
}

#elif defined(__MMI_MAINLCD_240X400__)
/* x, y, width, heigth related to notepaper */
#define VAPP_NOTEPAPER_SCROLL_IMAGE_POSITION  {15,   5, 211, 30}
#define VAPP_NOTEPAPER_BOTTOM_IMAGE_POSITION  {13, 183, 219, 49}
#define VAPP_NOTEPAPER_FLIP_FRAME_POSITION                  \
{                                                           \
    {11, 163, 224,  69},        /* flipping page 1 */       \
    { 8, 153, 227,  74},        /* flipping page 2 */       \
    { 8, 129, 230,  80},        /* flipping page 3 */       \
    { 0, 107, 240,  83},        /* flipping page 4 */       \
    { 0,  86, 240,  77},        /* flipping page 5 */       \
    { 0,  15, 240,  98},        /* flipping page 6 */       \
    { 0,   0, 240,  86},        /* flipping page 7 */       \
    {11,   2, 222,  51}         /* flipping page 8 */       \
}
#elif defined(__MMI_MAINLCD_320X480__)
/* x, y, width, heigth related to notepaper */
#define VAPP_NOTEPAPER_SCROLL_IMAGE_POSITION  {23,  18, 273, 39}
#define VAPP_NOTEPAPER_BOTTOM_IMAGE_POSITION  {21, 248, 283, 63}
#define VAPP_NOTEPAPER_FLIP_FRAME_POSITION                  \
{                                                           \
    {20, 223, 287,  90},        /* flipping page 1 */       \
    {15, 206, 291, 102},        /* flipping page 2 */       \
    {14, 179, 297, 104},        /* flipping page 3 */       \
    { 5, 154, 308, 103},        /* flipping page 4 */       \
    { 3, 122, 312, 100},        /* flipping page 5 */       \
    { 5,  30, 311, 127},        /* flipping page 6 */       \
    { 6,  10, 310, 115},        /* flipping page 7 */       \
    {19,  14, 283,  60}         /* flipping page 8 */       \
}
#else
/* x, y, width, heigth related to notepaper */
#define VAPP_NOTEPAPER_SCROLL_IMAGE_POSITION  {23,  18, 273, 39}
#define VAPP_NOTEPAPER_BOTTOM_IMAGE_POSITION  {21, 248, 283, 63}
#define VAPP_NOTEPAPER_FLIP_FRAME_POSITION                 \
{                                                          \
    {20, 223, 287,  90},       /* flipping page 1 */       \
    {15, 206, 291, 102},       /* flipping page 2 */       \
    {14, 179, 297, 104},       /* flipping page 3 */       \
    { 5, 154, 308, 103},       /* flipping page 4 */       \
    { 3, 122, 312, 100},       /* flipping page 5 */       \
    { 5,  30, 311, 127},       /* flipping page 6 */       \
    { 6,  10, 310, 115},       /* flipping page 7 */       \
    {19,  14, 283,  60}        /* flipping page 8 */       \
}
#endif
/*****************************************************************************
 * Setting NotePaper Flip Page Effect
 *****************************************************************************/
#if defined(__MMI_MAINLCD_240X320__)
#define VAPP_NOTE_PAPER_FLIP_BOUNDS_Y   \
{                           \
    VAPP_NOTEPAPER_SIZE_Y,  \
    168,                    \
    168,                    \
    168 - 26 * 1,           \
    168 - 26 * 2,           \
    0,                      \
    0,                      \
    0                       \
}
#elif defined(__MMI_MAINLCD_240X400__)
#define VAPP_NOTE_PAPER_FLIP_BOUNDS_Y   \
{                           \
    VAPP_NOTEPAPER_SIZE_Y,  \
    187,                    \
    187,                    \
    187 - 27 * 1,           \
    187 - 27 * 2,           \
    0,                      \
    0,                      \
    0                       \
}
#elif defined(__MMI_MAINLCD_320X480__)
#define VAPP_NOTE_PAPER_FLIP_BOUNDS_Y   \
{                           \
    VAPP_NOTEPAPER_SIZE_Y,  \
    249,                    \
    249,                    \
    249 - 35 * 1,           \
    249 - 35 * 2,           \
    0,                      \
    0,                      \
    0                       \
}
#else
#define VAPP_NOTE_PAPER_FLIP_BOUNDS_Y   \
{                           \
    VAPP_NOTEPAPER_SIZE_Y,  \
    249,                    \
    249,                    \
    249 - 35 * 1,           \
    249 - 35 * 2,           \
    0,                      \
    0,                      \
    0                       \
}
#endif

#endif /* __VAPP_NOTEPAPER_CFG_H__ */
