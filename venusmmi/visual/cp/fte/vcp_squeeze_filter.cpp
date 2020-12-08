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
 *  vcp_squeeze_filter.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Venus Main Menu Squeeze Effect
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

//#define VCP_SQUEEZE_FILTER_PROFILING
#if defined(MT6225)
#define VCP_SQUEEZE_FILTER_4X_SPEED_UP
#endif
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_squeeze_filter.h"
#if defined(VCP_SQUEEZE_FILTER_PROFILING)
#include "trc/vadp_app_trc.h"
#endif
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_image_src.h"
#include <string.h>
#include "vrt_datatype.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VCP_SQUEEZE_FILTER_TRY_NEW_EFFECT

/***************************************************************************** 
 * Class VcpSqueezeFilter
 *****************************************************************************/
VcpSqueezeFilter::VcpSqueezeFilter() :
    m_squeezeCoefficient((VfxFloat)VCP_SQUEEZE_FILTER_SQUEEZE_DEFAUL_COEFFICIENT), m_travelLength(0),
    m_leftMargin(0), m_rightMargin(0), m_topMargin(0), m_bottomMargin(0)
{
}

VfxBool VcpSqueezeFilter::squeezeInX(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat level, VfxS32 squeeze_point)
{
	register VfxS32 x, y;
    register VfxS32 old_x, old_y;
	VfxS32 	diff_x, diff_y;

	VfxU32 	*in_pixel_p = (VfxU32*)inBuf.ptr;
    VfxU32 	in_pixel;
    VfxU32 	*out_pixel_p = (VfxU32*)outBuf;
	
    VfxS32 	warp_radius;
    VfxS32 	anchor;
	
    VfxS32 	square_of_warp_radius;
	
    VfxFloat    inverse_to_square_of_warp_radius;
	VfxFloat	square_of_cos;

#if !defined(VCP_SQUEEZE_FILTER_TRY_NEW_EFFECT)
	/* temp variable for optimization */
    VfxFloat	tmp_a = (VfxFloat)level;
#else
    /* temp variable for optimization */
    VfxFloat	tmp_a;
    VfxFloat	tmp_b;
    VfxFloat	tmp_c;
    VfxFloat	tmp_d;
    VfxFloat	tmp_e;
    //VfxFloat	tmp_f;

	VfxFloat    level_factor;
	VfxS32		bottomMargin_poistion;
#endif

    //anchor = (m_imageWidth >> 1) + 1 ;

	//anchor = m_imageWidth * 0.1f;
	anchor = m_anchorX;

    warp_radius = m_warpRadius;

    square_of_warp_radius = warp_radius * warp_radius;

    inverse_to_square_of_warp_radius = (VfxFloat)1 / (VfxFloat) square_of_warp_radius;

	
#if defined(VCP_SQUEEZE_FILTER_TRY_NEW_EFFECT)
    tmp_a = VfxFloat(m_imageHeight- m_topMargin - m_bottomMargin);
    tmp_b = tmp_a / 3.0f;
    tmp_c = -tmp_b + (VfxFloat)m_travelLength;
    tmp_d = tmp_b * 2.0f;
	tmp_e = m_travelLength * level;
	bottomMargin_poistion = m_imageHeight-m_bottomMargin;
	if (level <= 0.2)
	{
		level_factor = level / 0.2f;
	}
	else if (level <= 0.7)
	{
		level_factor = (level - 0.2f) / 0.5f;
	}
	else if (level <= 0.9)
	{
		level_factor = (level - 0.7f) / 0.2f;
	}
	else
	{
		level_factor = (level - 0.9f) / 0.1f;
	}
#endif
#ifndef VCP_SQUEEZE_FILTER_4X_SPEED_UP
	for (y = inBuf.height - 1; y >= 0; y--)
#else
	for (y = inBuf.height - 1; y > 0; y-=2)
#endif
    {
        if (m_transitionDirection == VCP_SQUEEZE_FILTER_TRANSITION_DIRECTION_DOWNWARD)
    	{
    		// TODO: Need optimization here
    		if (level <= 0.2)
    		{
				old_y = (VfxS32)((y + tmp_e - m_topMargin) * (1+level_factor) + m_topMargin);
    		}
            else if (level <= 0.7)
           	{
				old_y = (VfxS32)((y + tmp_e - (tmp_c * level_factor) - m_topMargin) * (2 - 1.25 * level_factor) + m_topMargin);		
           	}
			else if (level <= 0.9)
			{
				old_y = (VfxS32)((y + tmp_e - (tmp_d * level_factor) - tmp_c - m_topMargin) * (0.75 + 0.75 * level_factor) + m_topMargin);
			}
			else
			{
				old_y = (VfxS32)((y + tmp_e + (tmp_b * level_factor) - tmp_c - tmp_d - m_topMargin) * (1.5 - 0.5 * level_factor) + m_topMargin);
			}
			
		#ifndef VCP_SQUEEZE_FILTER_4X_SPEED_UP
			if ((old_y < 0) || (old_y >= m_imageHeight))
		#else
			/* because we want to calculate old_y-1 so dicard old_y = 0 */
			if ((old_y <= 0) || (old_y >= m_imageHeight))
		#endif
			{
				continue;
			}
		}
		else
		{
			if (level <= 0.2)
			{
				old_y = (VfxS32)((y - tmp_e - bottomMargin_poistion) * (1 + level_factor) + bottomMargin_poistion);
			}
            else if (level <= 0.7)
            {
				old_y = (VfxS32)((y - tmp_e + (tmp_c * level_factor - bottomMargin_poistion)) * (2 - 1.25 * level_factor) + bottomMargin_poistion);
            }
			else if (level <= 0.9)
			{
				old_y = (VfxS32)((y - tmp_e + (tmp_d * level_factor) + tmp_c - bottomMargin_poistion) * (0.75 + 0.75 * level_factor) + bottomMargin_poistion);
			}
			else
			{
				old_y = (VfxS32)((y - tmp_e - (tmp_b * level_factor) + tmp_c + tmp_d - bottomMargin_poistion) * (1.5 - 0.5 * level_factor) + bottomMargin_poistion);
			}
			
		#ifndef VCP_SQUEEZE_FILTER_4X_SPEED_UP
			if ((old_y < 0) || (old_y >= m_imageHeight))
		#else
			/* because we want to calculate old_y-1 so dicard old_y = 0 */
			if ((old_y <= 0) || (old_y >= m_imageHeight))
		#endif
			{
				continue;
			}
		}
        
		diff_y = old_y - squeeze_point;

		if (VFX_ABS(diff_y) < warp_radius)
        {
			square_of_cos = (VfxFloat) ((VfxFloat)(square_of_warp_radius - diff_y * diff_y) * inverse_to_square_of_warp_radius);

			tmp_a = (VfxFloat)1 / ((VfxFloat)1 - m_squeezeCoefficient * square_of_cos * square_of_cos);
        }
        else
        {
        	square_of_cos = 0;
        }
#ifndef VCP_SQUEEZE_FILTER_4X_SPEED_UP
		for (x = inBuf.width - m_rightMargin; x >= m_leftMargin; x--)
#else
		for (x = inBuf.width - m_rightMargin; x > m_leftMargin; x-=2)
#endif
        {
 			diff_x = x - anchor;

 			if (square_of_cos == 0)
			{
				old_x = x;
			}
			else
			{
				old_x = anchor + (VfxS32)(diff_x * tmp_a);
			}
			/* diable squeeze */
			//old_x = x;
		#ifndef VCP_SQUEEZE_FILTER_4X_SPEED_UP
			if ((old_x < 0) || (old_x >= m_imageWidth))
		#else
			/* because we want to calculate old_y-1 so dicard old_y = 0 */
			if ((old_x <= 0) || (old_x >= m_imageWidth))
		#endif
			{
				continue;
			}
				
            in_pixel = *(in_pixel_p + old_y * inBuf.width + old_x);
		#ifndef VCP_SQUEEZE_FILTER_4X_SPEED_UP
			*((VfxU32 *)out_pixel_p + y * inBuf.width + x) = in_pixel;
		#else
			*((VfxU32 *)out_pixel_p + y * inBuf.width + x) = in_pixel;
			*((VfxU32 *)out_pixel_p + (y-1) * inBuf.width + x) = *(in_pixel_p + (old_y-1) * inBuf.width + old_x);
			*((VfxU32 *)out_pixel_p + y * inBuf.width + x-1) = *(in_pixel_p + old_y * inBuf.width + old_x-1);
			*((VfxU32 *)out_pixel_p + (y-1) * inBuf.width + x-1) = *(in_pixel_p + (old_y-1) * inBuf.width + old_x-1);
		#endif
        }    	
    }

    return VFX_TRUE;
}

VfxBool VcpSqueezeFilter::squeezeInY(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat level, VfxS32 squeeze_point)
{
	register VfxS32 x, y;
    register VfxS32 old_x, old_y;
    VfxS32 	diff_x, diff_y;
    
    VfxU32 	*in_pixel_p = (VfxU32*)inBuf.ptr;
    VfxU32 	in_pixel;
    VfxU32 	*out_pixel_p = (VfxU32*)outBuf;
    
    VfxS32 	warp_radius;
    VfxS32 	anchor;

    VfxS32 	square_of_warp_radius;

    VfxFloat    inverse_to_square_of_warp_radius;
    VfxFloat	square_of_cos;

#if !defined(VCP_SQUEEZE_FILTER_TRY_NEW_EFFECT)
	/* temp variable for optimization */
    VfxFloat	tmp_a = (VfxFloat)level;
#else
    /* temp variable for optimization */
    VfxFloat	tmp_a;
    VfxFloat	tmp_b;
    VfxFloat	tmp_c;
    VfxFloat	tmp_d;
    VfxFloat	tmp_e;
    //VfxFloat	tmp_f;

	VfxFloat    level_factor;
	VfxS32		rightMargin_poistion;
#endif
    
    //anchor = (m_imageHeight >> 1) +1;

	//anchor = m_imageHeight * 0.1f;
	anchor = m_anchorY;

    warp_radius = m_warpRadius;
    
    square_of_warp_radius = warp_radius * warp_radius;

    inverse_to_square_of_warp_radius = (VfxFloat)1 / (VfxFloat) square_of_warp_radius;

#if defined(VCP_SQUEEZE_FILTER_TRY_NEW_EFFECT)
    tmp_a = VfxFloat(m_imageWidth - m_leftMargin - m_rightMargin);
    tmp_b = tmp_a / 3.0f;
    tmp_c = -tmp_b + (VfxFloat)m_travelLength;
    tmp_d = tmp_b * 2.0f;
	tmp_e = m_travelLength * level;
	rightMargin_poistion = m_imageHeight-m_rightMargin;
	if (level <= 0.2)
	{
		level_factor = level / 0.2f;
	}
	else if (level <= 0.7)
	{
		level_factor = (level - 0.2f) / 0.5f;
	}
	else if (level <= 0.9)
	{
		level_factor = (level - 0.7f) / 0.2f;
	}
	else
	{
		level_factor = (level - 0.9f) / 0.1f;
	}
#endif

#ifndef VCP_SQUEEZE_FILTER_4X_SPEED_UP	
	for (x = inBuf.width - 1; x >= 0; x--)
#else
	for (x = inBuf.width - 1; x > 0; x-=2)
#endif
    {        
		if (m_transitionDirection == VCP_SQUEEZE_FILTER_TRANSITION_DIRECTION_RIGHTWARD)
    	{
    		// TODO: Need optimization here
    		if (level <= 0.2)
    		{
				old_x = (VfxS32)((x + tmp_e - m_leftMargin) * (1 + level_factor) + m_leftMargin);
    		}
            else if (level <= 0.7)
            {
				old_x = (VfxS32)((x + tmp_e - (tmp_c * level_factor) - m_leftMargin) * (2 - 1.25 * level_factor) + m_leftMargin);
            }
            else if (level <= 0.9)
            {
				old_x = (VfxS32)((x + tmp_e - (tmp_d * level_factor) - tmp_c - m_leftMargin) * (0.75 + 0.75 * level_factor) + m_leftMargin);
            }
			else
			{
				old_x = (VfxS32)((x + tmp_e + (tmp_b * level_factor) - tmp_c - tmp_d - m_leftMargin) * (1.5 - 0.5 * level_factor) + m_leftMargin);
			}
		
		#ifndef VCP_SQUEEZE_FILTER_4X_SPEED_UP
			if ((old_x < 0) || (old_x >= m_imageWidth))
		#else
			/* because we want to calculate old_y-1 so dicard old_y = 0 */
			if ((old_x <= 0) || (old_x >= m_imageWidth))
		#endif
			{
				continue;
			}
		}
		else
		{
			if (level <= 0.2)
			{
				old_x = (VfxS32)((x - tmp_e - rightMargin_poistion) * (1 + level / 0.2) + rightMargin_poistion);
			}
            else if (level <= 0.7)
            {
				old_x = (VfxS32)((x - tmp_e + (tmp_c * (level - 0.2) / 0.5) - rightMargin_poistion) * (2 - 1.25 * level_factor) + rightMargin_poistion);
            }
            else if (level <= 0.9)
            {
				old_x = (VfxS32)((x - tmp_e + (tmp_d * (level - 0.7) / 0.2) + tmp_c - rightMargin_poistion) * (0.75 + 0.75 * level_factor) + rightMargin_poistion);
            }
			else
			{
				old_x = (VfxS32)((x - tmp_e - (tmp_b * (level - 0.9) / 0.1) + tmp_c + tmp_d - rightMargin_poistion) * (1.5 - 0.5 * level_factor) + rightMargin_poistion);
			}
			
		#ifndef VCP_SQUEEZE_FILTER_4X_SPEED_UP
			if ((old_x < 0) || (old_x >= m_imageWidth))
		#else
			/* because we want to calculate old_y-1 so dicard old_y = 0 */
			if ((old_x <= 0) || (old_x >= m_imageWidth))
		#endif
			{
				continue;
			}
		}

       	diff_x = old_x - squeeze_point;

		if (VFX_ABS(diff_x) < warp_radius)
        {
			square_of_cos = (VfxFloat) ((VfxFloat)(square_of_warp_radius - diff_x * diff_x) * inverse_to_square_of_warp_radius);

			tmp_a = (VfxFloat)1 / ((VfxFloat)1 - m_squeezeCoefficient * square_of_cos * square_of_cos);
        }
        else
        {
        	square_of_cos = 0;
        }
	#ifndef VCP_SQUEEZE_FILTER_4X_SPEED_UP
		for (y = inBuf.height - m_bottomMargin; y >= m_topMargin; y--)
	#else
		for (y = inBuf.height - m_bottomMargin; y > m_topMargin; y-=2)
	#endif
        {
 			diff_y = y - anchor;

 			if (square_of_cos == 0)
			{
				old_y = y;
			}
			else
			{				
				old_y = anchor + (VfxS32)(diff_y * tmp_a);
			}
			/* diable squeeze */
			//old_y = y;
		#ifndef VCP_SQUEEZE_FILTER_4X_SPEED_UP
			if ((old_y < 0) || (old_y >= m_imageHeight))
		#else
			/* because we want to calculate old_y-1 so dicard old_y = 0 */
			if ((old_y <= 0) || (old_y >= m_imageHeight))
		#endif
			{
				continue;
			}
			
		#ifndef VCP_SQUEEZE_FILTER_4X_SPEED_UP		
            in_pixel = *(in_pixel_p + old_y * inBuf.width + old_x);
			*((VfxU32 *)out_pixel_p + y * inBuf.width + x) = in_pixel;
		#else
			*((VfxU32 *)out_pixel_p + y * inBuf.width + x) = *(in_pixel_p + old_y * inBuf.width + old_x);
			*((VfxU32 *)out_pixel_p + (y-1) * inBuf.width + x) = *(in_pixel_p + (old_y-1) * inBuf.width + old_x);
			*((VfxU32 *)out_pixel_p + y * inBuf.width + x-1) = *(in_pixel_p + old_y * inBuf.width + old_x-1);
			*((VfxU32 *)out_pixel_p + (y-1) * inBuf.width + x-1) = *(in_pixel_p + (old_y-1) * inBuf.width + old_x-1);
		#endif
			
        }
    }

    return VFX_TRUE;
}

VfxBool VcpSqueezeFilter::onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat level)
{
    VfxU32 	*out_pixel_p = (VfxU32*)outBuf;
	VfxS32 	squeeze_point;
	VfxBool return_value = VFX_TRUE;
#if defined(VCP_SQUEEZE_FILTER_PROFILING)
	VfxU32	 clock_count;

	kal_get_time(&clock_count);
	
    VFX_TRACE(("Vcp Squeeze Filter On Process Clock Begin: %d\n", clock_count));
    VFX_LOG(VFX_INFO, VAPP_SQUEEZE_FILTER_ON_PROCESS_CLOCK_BEGIN_MSG, clock_count);
#endif	
	//level = g_level;
    if (level <= 0 || level >= 1)
    {
        /* to do: remove memcpy */
        memcpy(out_pixel_p, inBuf.ptr, inBuf.width * inBuf.height * 4);
        return VRT_FALSE;
    }
    memset(out_pixel_p, 0, inBuf.width * inBuf.height * 4); /* clean out buffer */

    switch (m_transitionDirection)
    {
    case VCP_SQUEEZE_FILTER_TRANSITION_DIRECTION_UPWARD:
        squeeze_point = (VfxS32)(m_topMargin - m_warpRadius + (VfxS32)((VfxFloat)m_warpRadius * (VfxFloat)4 * level)); 
        return_value = squeezeInX(outBuf, inBuf, level, squeeze_point);
        break;
    case VCP_SQUEEZE_FILTER_TRANSITION_DIRECTION_DOWNWARD: 
        squeeze_point = (VfxS32)(m_warpRadius + m_imageHeight - m_bottomMargin - (VfxS32)((VfxFloat)m_warpRadius * (VfxFloat)4 * level)); 
        return_value = squeezeInX(outBuf, inBuf, level, squeeze_point);
        break;
    case VCP_SQUEEZE_FILTER_TRANSITION_DIRECTION_LEFTWARD:
        squeeze_point = (VfxS32)(m_leftMargin - m_warpRadius + (VfxS32)((VfxFloat)m_warpRadius * (VfxFloat)4 * level)); 
        return_value = squeezeInY(outBuf, inBuf, level, squeeze_point);
        break;
    case VCP_SQUEEZE_FILTER_TRANSITION_DIRECTION_RIGHTWARD:
        squeeze_point = (VfxS32)(m_warpRadius + m_imageWidth - m_rightMargin - (VfxS32)((VfxFloat)m_warpRadius * (VfxFloat)4 * level)); 
		return_value = squeezeInY(outBuf, inBuf, level, squeeze_point);
        break;
    default:
        VFX_ASSERT(0);
        break;
    }

#if defined(VCP_SQUEEZE_FILTER_PROFILING)

	kal_get_time(&clock_count);
	
	VFX_TRACE(("Vcp Squeeze Filter On Process Clock End: %d\n", clock_count));
    VFX_LOG(VFX_INFO, VAPP_SQUEEZE_FILTER_ON_PROCESS_CLOCK_END_MSG, clock_count);

#endif	

    return return_value;
}
