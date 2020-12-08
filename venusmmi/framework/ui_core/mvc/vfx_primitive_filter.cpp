/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vfx_primitive_filter.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Description
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_primitive_filter.h"
#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vfx_image_src.h"
#include "vrt_datatype.h"

/***************************************************************************** 
 * Class VfxScreen
 *****************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm
#endif
 
VfxBool VfxDarkenFilter::onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat level)
{
    if (inBuf.colorFormat == VRT_COLOR_TYPE_RGB565)
    {
        VfxU16 maskShift1 = 0x7BEF;
        //VfxU16 maskShift2 = 0x39E7;

        VfxU32 pixel;
        VfxU16 *in_pixel_p = (VfxU16*)inBuf.ptr;
    	VfxU16 *out_pixel_p = (VfxU16 *)outBuf;
        VfxS32 i, j;

        VfxS32 width = inBuf.width;
        VfxS32 height = inBuf.height;

        for (j = height-1 ; j >=0; j--)
        {
            for (i = width-1 ; i >= 0; i--)
            {
                pixel = (VfxU32)(*(in_pixel_p));

                pixel >>= 1;
                pixel &= maskShift1;
                *out_pixel_p = pixel;
                
                out_pixel_p ++;
                in_pixel_p ++;
            }
        }
    }
    else
    {
        
        VfxU8 *in_pixel_p = (VfxU8*)inBuf.ptr;
    	VfxU8 *out_pixel_p = (VfxU8 *)outBuf;
        VfxS32 width = inBuf.width;
        VfxS32 height = inBuf.height;
        
        VfxS32 i,j;

        for (j = height - 1; j >= 0; j--)
        {
            for (i = width - 1; i >= 0; i--)
            {
                *(out_pixel_p) = (*(in_pixel_p)) >> 1;
                *(out_pixel_p + 1) = (*(in_pixel_p + 1)) >> 1;
                *(out_pixel_p + 2) = (*(in_pixel_p + 2)) >> 1;
                *(out_pixel_p+3) =  (*(in_pixel_p + 3));

                in_pixel_p +=4;
                out_pixel_p +=4;
            }
        }
    }
    return VFX_TRUE;
}

#ifdef __MTK_TARGET__
#pragma thumb
#endif

