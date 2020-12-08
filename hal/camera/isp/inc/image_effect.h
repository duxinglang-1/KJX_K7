/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *	.h
 *
 * Project:
 * --------
 *   MT6255
 *
 * Description:
 * ------------
 *   This file is intends for SW image effect.
 *
 * Author:
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __IMAGE_EFFECT_H__
#define __IMAGE_EFFECT_H__

enum
{
    COLOR_ACCENT_RED = 0,
    COLOR_ACCENT_YELLOW,
    COLOR_ACCENT_GREEN,
    COLOR_ACCENT_BLUE
};

extern void ImageEffectCoreLomo_YUV422(kal_uint32 SrcImageYUVBuffAddr,
									   kal_uint32 DestImageYUVBuffAddr,
									   kal_uint16 SrcImageWidth,
									   kal_uint16 SrcImageHeight);
extern void ImageEffectCoreLomo_YUV420(kal_uint32 SrcImageYBuffAddr,
									   kal_uint32 SrcImageUBuffAddr,
									   kal_uint32 SrcImageVBuffAddr,
									   kal_uint32 DestImageYBuffAddr,
									   kal_uint32 DestImageUBuffAddr,
									   kal_uint32 DestImageVBuffAddr,
									   kal_uint16 SrcImageWidth,
									   kal_uint16 SrcImageHeight);
extern void ImageEffectCoreColorAccent_YUV422(kal_uint32 SrcImageYUVBuffAddr,
											  kal_uint32 DestImageYUVBuffAddr,
											  kal_uint16 SrcImageWidth,
											  kal_uint16 SrcImageHeight,
											  kal_uint8  AccentColor);
extern void ImageEffectCoreColorAccent_YUV420(kal_uint32 SrcImageYBuffAddr,
											  kal_uint32 SrcImageUBuffAddr,
											  kal_uint32 SrcImageVBuffAddr,
											  kal_uint32 DestImageYBuffAddr,
											  kal_uint32 DestImageUBuffAddr,
											  kal_uint32 DestImageVBuffAddr,
											  kal_uint16 SrcImageWidth,
											  kal_uint16 SrcImageHeight,
											  kal_uint8  AccentColor);

extern kal_int32 RedSlopeThr1;
extern kal_int32 RedSlopeThr2;
extern kal_int32 YellowSlopeThr1;
extern kal_int32 YellowSlopeThr2;
extern kal_int32 GreenSlopeThr1;
extern kal_int32 GreenSlopeThr2;
extern kal_int32 BlueSlopeThr1;
extern kal_int32 BlueSlopeThr2;

#endif /* __IMAGE_EFFECT_H__ */
