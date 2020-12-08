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
 *  vapp_ucm_def.h
 *
 * Project:
 * -------- 
 *  COSMOS
 *
 * Description:
 * ------------
 *  UCM definitions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_UCM_RES_DEF_H__
#define __VAPP_UCM_RES_DEF_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/

#ifdef __MMI_VIDEO_TELEPHONY__
// two layer for HW layer and one for encode layer and one for capture
// each layer use 2 byte for one pixel
#define VAPP_UCM_VDO_FRAME_FACTOR    (3*2)
#define VAPP_UCM_VDO_FRAME_ENCODE_LAYER_SIZE    (176*144*2)

#define VAPP_UCM_RES_MAX_W ((VAPP_UCM_RES_VT_PREVIEW_W > VAPP_UCM_RES_VFRAME_W) ? VAPP_UCM_RES_VT_PREVIEW_W : VAPP_UCM_RES_VFRAME_W)
#define VAPP_UCM_RES_MAX_H ((VAPP_UCM_RES_VT_PREVIEW_H > VAPP_UCM_RES_VFRAME_H) ? VAPP_UCM_RES_VT_PREVIEW_H : VAPP_UCM_RES_VFRAME_H)

#ifdef __MMI_MAINLCD_320X480__
#define VAPP_UCM_RES_VFRAME_W 256
#define VAPP_UCM_RES_VFRAME_H 192
#define VAPP_UCM_RES_VT_PREVIEW_W 256
#define VAPP_UCM_RES_VT_PREVIEW_H 192

#elif defined __MMI_MAINLCD_480X800__
#define VAPP_UCM_RES_VFRAME_W 448
#define VAPP_UCM_RES_VFRAME_H 336
#define VAPP_UCM_RES_VT_PREVIEW_W 448
#define VAPP_UCM_RES_VT_PREVIEW_H 336

#elif defined __MMI_MAINLCD_240X320__
#define VAPP_UCM_RES_VFRAME_W 128
#define VAPP_UCM_RES_VFRAME_H 96
#define VAPP_UCM_RES_VT_PREVIEW_W 128
#define VAPP_UCM_RES_VT_PREVIEW_H 96

#elif defined __MMI_MAINLCD_240X400__
#define VAPP_UCM_RES_VFRAME_W 172
#define VAPP_UCM_RES_VFRAME_H 144
#define VAPP_UCM_RES_VT_PREVIEW_W 172
#define VAPP_UCM_RES_VT_PREVIEW_H 144

#else
#define VAPP_UCM_RES_VFRAME_W 224
#define VAPP_UCM_RES_VFRAME_H 160
#define VAPP_UCM_RES_VT_PREVIEW_W 304
#define VAPP_UCM_RES_VT_PREVIEW_H 224
#endif /* __MMI_MAINLCD_320X480__ */

#endif /* __MMI_VIDEO_TELEPHONY__ */

#endif /* __VAPP_UCM_RES_DEF_H__ */

