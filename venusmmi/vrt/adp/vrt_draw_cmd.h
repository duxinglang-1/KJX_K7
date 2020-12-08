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
 *  vrt_draw_cmd.h
 *
 * Project:
 * --------
 *  Venus Rendering Task
 *
 * Description:
 * ------------
 *  Venus Rendering Task draw command header file  
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
 * removed!
 * removed!
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

#ifndef __VRT_DRAW_CMD_H__
#define __VRT_DRAW_CMD_H__

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
/*
 * draw command type
 */
typedef enum
{    
    /* Frame commands */
    VRT_DRAW_CMD_PUSH_AND_SET_ACTIVE_FRAME   = 0x0001,
    VRT_DRAW_CMD_POP_AND_RESTORE_FRAME       = 0x0002,
    
    /* Setting commands */
    VRT_DRAW_CMD_SET_CLIP                    = 0x0003,
    VRT_DRAW_CMD_END_OF_DIRTY_SCAN           = VRT_DRAW_CMD_SET_CLIP,
    VRT_DRAW_CMD_SET_FILL_COLOR              = 0x0004,
    VRT_DRAW_CMD_SET_STROKE_COLOR            = 0x0005,
    VRT_DRAW_CMD_SET_FALLBACK_IMAGE          = 0x0007,
    
    /* Draw commands */
    VRT_DRAW_CMD_FILL_RECT                   = 0x0101,
    VRT_DRAW_CMD_DRAW_PIXEL                  = 0x0102,
    VRT_DRAW_CMD_DRAW_LINE                   = 0x0103,
    VRT_DRAW_CMD_DRAW_AA_LINE                = 0x0104,
    VRT_DRAW_CMD_DRAW_RECT                   = 0x0105,
    
    /* Image and content commands */
    VRT_DRAW_CMD_DRAW_IMG_FROM_MEM           = 0x0201,
    VRT_DRAW_CMD_DRAW_IMG_FROM_RES_ID        = 0x0202,
    VRT_DRAW_CMD_DRAW_IMG_FROM_FILE          = 0x0203,
    VRT_DRAW_CMD_DRAW_RESIZED_IMG_FROM_MEM   = 0x0204,
    VRT_DRAW_CMD_DRAW_RESIZED_IMG_FROM_RES_ID = 0x0205,
    VRT_DRAW_CMD_DRAW_RESIZED_IMG_FROM_FILE  = 0x0206,
    VRT_DRAW_CMD_DRAW_IMG_CONTENT_FROM_MEM   = 0x0207,
    VRT_DRAW_CMD_DRAW_IMG_CONTENT_FROM_RES_ID = 0x0208,
    VRT_DRAW_CMD_DRAW_IMG_CONTENT_FROM_FILE  = 0x0209,
    VRT_DRAW_CMD_DRAW_LAYER                  = 0x020A,
    VRT_DRAW_CMD_DRAW_IMG_CONTENT_FROM_LAYER = 0x020B,
    VRT_DRAW_CMD_DRAW_IMG_BUF                = 0x020C,
    VRT_DRAW_CMD_DRAW_RESIZED_IMG_BUF        = 0x020D,
    VRT_DRAW_CMD_DRAW_IMG_CONTENT_FROM_IMG_BUF = 0x020E,
    VRT_DRAW_CMD_DRAW_IMG_RAW_DATA           = 0x020F,
    VRT_DRAW_CMD_DRAW_RESIZED_RAW_DATA       = 0x0210,
    VRT_DRAW_CMD_DRAW_IMG_CONTENT_FROM_RAW_DATA = 0x0211,
    
    /* Font and text commands */
    VRT_DRAW_CMD_SET_FONT                   = 0x0301,
    VRT_DRAW_CMD_SET_ELLIPSIS               = 0x0302,
    /*
     * VRT_DRAW_CMD_DRAW_TEXT
     *  Arg0: x positon
     *  Arg1: y position
     *  Arg2: pointer to z-string
     *  Arg3: truncate width, 0 for disable
     */
    VRT_DRAW_CMD_DRAW_TEXT                  = 0x0303,
    /*
     * VRT_DRAW_CMD_DRAW_TEXT_N
     *  Arg0: pointer to position
     *  Arg1: pointer to n-string
     *  Arg2: Reserved, must be 0
     *  Arg3: Reserved, must be 0
     */
    VRT_DRAW_CMD_DRAW_TEXT_N                = 0x0304,
    /*
     * VRT_DRAW_CMD_DRAW_TEXT_N_BASELINE
     *  Arg0: pointer to position
     *  Arg1: baseline height
     *  Arg2: pointer to n-string
     *  Arg3: Reserved, must be 0
     */
    VRT_DRAW_CMD_DRAW_TEXT_N_BASELINE       = 0x0305,

    /* 3D */
    VRT_DRAW_CMD_DRAW_WORLD                 = 0x0401,

    /* System commands */
    VRT_DRAW_CMD_NOP                        = 0x0500,
    VRT_DRAW_CMD_END                        = 0x0501,
    VRT_DRAW_CMD_COMMENT                    = 0x0502,
    VRT_DRAW_CMD_DRAW_NON					= 0x0503,

    /* Other commands */
    VRT_DRAW_CMD_CUSTOM                     = 0x0601
} vrt_draw_cmd_type_enum;


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

#endif /* __VRT_DRAW_CMD_H__ */

