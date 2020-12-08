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
 *  vcp_jelly_filter.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Venus Main Menu Jelly Effect
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

//#define VCP_JELLY_FILTER_PROFILING
#if defined(MT6225)
#define VCP_JELLY_FILTER_4X_SPEED_UP
#endif
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_jelly_filter.h"
#if defined(VCP_JELLY_FILTER_PROFILING)
#include "trc/vadp_app_trc.h"
#endif
#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include <string.h>
#include "vrt_datatype.h"
#include "vfx_image_src.h"

/***************************************************************************** 
 * Class VcpJellyFilter
 *****************************************************************************/
VcpJellyFilter::VcpJellyFilter() :
   m_leftMargin(0), m_rightMargin(0), m_topMargin(0), m_bottomMargin(0), m_travelLength(0)
{
}

VfxBool VcpJellyFilter::twoSqueezeInX(VfxFloat level)
{
	VfxS32 x, y;
    VfxS32 old_x, old_y;
    VfxU32 *in_pixel_p = (VfxU32*)m_inBufP;
    VfxU32 in_pixel;
    VfxS32 warp_radius;
    VfxS32 anchor;
    VfxS32 diff_x, diff_y;
    VfxS32 squeeze_point, squeeze_point_2;
    VfxU32 square_of_warp_radius;
    VfxU32 *out_pixel_p = (VfxU32*)m_outBufP;
    
    VfxFloat square_of_cos, square_of_cos_2;
    VfxFloat inverse_to_square_of_warp_radius;
    VfxFloat t_tmp;

	/* temp variable for optimization */
    VfxFloat tmp_a = (VfxFloat)0;
    VfxFloat tmp_b = (VfxFloat)0;

	memset(out_pixel_p, 0, m_inBufWidth * m_inBufHeight * 4); /* clean out buffer */
#ifndef VCP_JELLY_FILTER_4X_SPEED_UP
	out_pixel_p += m_inBufWidth * m_inBufHeight - 1;
#endif

	anchor = m_anchor;

	warp_radius = m_warpRadius;
	square_of_warp_radius = warp_radius * warp_radius;
	inverse_to_square_of_warp_radius = 1 / (VfxFloat) square_of_warp_radius;
	if (m_squeezePoint != VCP_JELLY_FILTER_CONTINUED_SQUEEZE)
	{
    	squeeze_point = m_squeezePoint;
	}
	else
	{
	 	squeeze_point = m_imageHeight * level;
	}
	if (m_squeezePoint_2 != VCP_JELLY_FILTER_CONTINUED_SQUEEZE)
	{
		squeeze_point_2 = m_squeezePoint_2; 
	}
	else
	{
		squeeze_point_2 = m_imageHeight * (1 - level);
	}
	
    t_tmp = 1 - (VfxFloat) (2 * VFX_ABS(level - 0.5));

#ifndef VCP_JELLY_FILTER_4X_SPEED_UP
    for (y = m_inBufHeight-1; y >= 0; y--)
#else
	for (y = m_inBufHeight-1; y > 0; y-=2)
#endif
    {            
        old_y = y;

        if ((old_y <= m_topBoundary) || (old_y >= m_bottomBoundary))
        {
#ifndef VCP_JELLY_FILTER_4X_SPEED_UP
			out_pixel_p -= m_inBufWidth;
#endif
			continue;
		}

		if (y < m_topNewBoundary)
		{
			m_topNewBoundary = y;
		}

		if (y > m_bottomNewBoundary)
		{
			m_bottomNewBoundary = y;
		}

		diff_y = old_y - squeeze_point;

		if (VFX_ABS(diff_y) < warp_radius)
        {
			square_of_cos = (VfxFloat)((VfxFloat)(square_of_warp_radius - diff_y * diff_y) * inverse_to_square_of_warp_radius);
			tmp_a = 1 / (1 - t_tmp * m_squeezeCoefficient * square_of_cos * square_of_cos);
        }
        else
        {
            square_of_cos = 0;
        }

        diff_y = old_y - squeeze_point_2;

		if (VFX_ABS(diff_y) < warp_radius)
        {
			square_of_cos_2 = (VfxFloat)((VfxFloat)(square_of_warp_radius - diff_y * diff_y) * inverse_to_square_of_warp_radius);
			tmp_b = 1 / (1 - t_tmp * m_squeezeCoefficient * square_of_cos_2 * square_of_cos_2);
        }
        else
        {
            square_of_cos_2 = 0;
        }
#ifndef VCP_JELLY_FILTER_4X_SPEED_UP
        for (x = m_inBufWidth-1; x >= 0; x--)
#else
		for (x = m_inBufWidth-1; x > 0; x-=2)
#endif
        {
            diff_x = x - anchor;

			if (diff_x < 0)
			{
				if (square_of_cos == 0)
				{
					old_x = x;
				}
				else
				{
					old_x = anchor + (VfxS32)(diff_x * tmp_a);
				}
			}
			else
			{
				if (square_of_cos_2 == 0)
				{
					old_x = x;
				}
				else
				{
					old_x = anchor + (VfxS32)(diff_x * tmp_b);
				}
			}

			if ((old_x <= m_leftBoundary) || (old_x >= m_rightBoundary))
			{
			#ifndef VCP_JELLY_FILTER_4X_SPEED_UP
				out_pixel_p--;
			#endif
				continue;
			}

			if (x < m_leftNewBoundary)
			{
				m_leftNewBoundary = x;
			}

			if (x > m_rightNewBoundary)
			{
				m_rightNewBoundary = x;
			}
				
            in_pixel = *(in_pixel_p + old_y * m_inBufWidth + old_x);
		#ifndef VCP_JELLY_FILTER_4X_SPEED_UP
            *out_pixel_p = in_pixel;
		#else
			*((VfxU32 *)out_pixel_p + y * m_inBufWidth + x) = in_pixel;
			*((VfxU32 *)out_pixel_p + (y-1) * m_inBufWidth + x) = *(in_pixel_p + (old_y-1) * m_inBufWidth + old_x);
			*((VfxU32 *)out_pixel_p + y * m_inBufWidth + x-1) = *(in_pixel_p + old_y * m_inBufWidth + old_x-1);
			*((VfxU32 *)out_pixel_p + (y-1) * m_inBufWidth + x-1) = *(in_pixel_p + (old_y-1) * m_inBufWidth + old_x-1);
		#endif
		#ifndef VCP_JELLY_FILTER_4X_SPEED_UP
			out_pixel_p--;
		#endif
        }    
    }

    return VRT_TRUE;
}

VfxBool VcpJellyFilter::squeezeInX(VfxFloat level)
{
	VfxS32 x, y;
    VfxS32 old_x, old_y;
    VfxU32 *in_pixel_p = (VfxU32*)m_inBufP;
    VfxU32 in_pixel;
    VfxS32 warp_radius;
    VfxS32 anchor;
    VfxS32 diff_x, diff_y;
    VfxS32 squeeze_point;
    VfxU32 square_of_warp_radius;
    VfxU32 *out_pixel_p = (VfxU32*)m_outBufP;
		
    VfxFloat square_of_cos;
    VfxFloat inverse_to_square_of_warp_radius;
    VfxFloat t_tmp;
	

    /* temp variable for optimization */
    VfxFloat tmp_a = (VfxFloat)0;

	memset(out_pixel_p, 0, m_inBufWidth * m_inBufHeight * 4); /* clean out buffer */
#ifndef VCP_JELLY_FILTER_4X_SPEED_UP
	out_pixel_p += m_inBufWidth * m_inBufHeight - 1;
#endif
	anchor = m_anchor;

	warp_radius = m_warpRadius;
	square_of_warp_radius = warp_radius * warp_radius;
	inverse_to_square_of_warp_radius = 1 / (VfxFloat) square_of_warp_radius;
	
    if (m_squeezePoint != VCP_JELLY_FILTER_CONTINUED_SQUEEZE)
	{
    	squeeze_point = m_squeezePoint;
	}
	else
	{
	 	squeeze_point = m_imageHeight * level;
	}

    t_tmp = (VfxFloat)1 - (VfxFloat) (2 * VFX_ABS(level - 0.5));

#ifndef VCP_JELLY_FILTER_4X_SPEED_UP
    for (y = m_inBufHeight-1; y >= 0; y--)
#else
	for (y = m_inBufHeight-1; y > 0; y-=2)
#endif
    {          
        old_y = y;
        
        if ((old_y <= m_topBoundary) || (old_y >= m_bottomBoundary))
		{
		#ifndef VCP_JELLY_FILTER_4X_SPEED_UP
			out_pixel_p -= m_inBufWidth;
		#endif
			continue;
		}

		if (y < m_topNewBoundary)
		{
			m_topNewBoundary = y;
		}

		if (y > m_bottomNewBoundary)
		{
			m_bottomNewBoundary = y;
		}

		diff_y = old_y - squeeze_point;

		if (VFX_ABS(diff_y) < warp_radius)
        {
			square_of_cos = (VfxFloat)((VfxFloat)(square_of_warp_radius - diff_y * diff_y) * inverse_to_square_of_warp_radius);
			tmp_a = (VfxFloat)1 / ((VfxFloat)1 - t_tmp * m_squeezeCoefficient * square_of_cos * square_of_cos);
        }
        else
        {
            square_of_cos = 0;
        }
		
	#ifndef VCP_JELLY_FILTER_4X_SPEED_UP
        for (x = m_inBufWidth-1; x >= 0; x--)
	#else
		for (x = m_inBufWidth-1; x > 0; x-=2)
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

			if ((old_x <= m_leftBoundary) || (old_x >= m_rightBoundary))
			{
			#ifndef VCP_JELLY_FILTER_4X_SPEED_UP
				out_pixel_p--;
			#endif
				continue;
			}

			if (x < m_leftNewBoundary)
			{
				m_leftNewBoundary = x;
			}

			if (x > m_rightNewBoundary)
			{
				m_rightNewBoundary = x;
			}

            in_pixel = *(in_pixel_p + old_y * m_inBufWidth + old_x);

        #ifndef VCP_JELLY_FILTER_4X_SPEED_UP
            *out_pixel_p = in_pixel;
		#else
			*((VfxU32 *)out_pixel_p + y * m_inBufWidth + x) = in_pixel;
			*((VfxU32 *)out_pixel_p + (y-1) * m_inBufWidth + x) = *(in_pixel_p + (old_y-1) * m_inBufWidth + old_x);
			*((VfxU32 *)out_pixel_p + y * m_inBufWidth + x-1) = *(in_pixel_p + old_y * m_inBufWidth + old_x-1);
			*((VfxU32 *)out_pixel_p + (y-1) * m_inBufWidth + x-1) = *(in_pixel_p + (old_y-1) * m_inBufWidth + old_x-1);
		#endif
		#ifndef VCP_JELLY_FILTER_4X_SPEED_UP
			out_pixel_p--;
		#endif
        }    
    }

    return VRT_TRUE;
}

VfxBool VcpJellyFilter::twoSqueezeInY(VfxFloat level)
{
	VfxS32 x, y;
    VfxS32 old_x, old_y;
    VfxU32 *in_pixel_p = (VfxU32*)m_inBufP;
    VfxU32 in_pixel;
    VfxS32 warp_radius;
    VfxS32 anchor;
    VfxS32 diff_x, diff_y;
    VfxS32 squeeze_point, squeeze_point_2;
    VfxU32 square_of_warp_radius;
    VfxU32 *out_pixel_p = (VfxU32*)m_outBufP;
    
    VfxFloat square_of_cos, square_of_cos_2;
    VfxFloat inverse_to_square_of_warp_radius;
    VfxFloat t_tmp;

    /* temp variable for optimization */
    VfxFloat tmp_a = (VfxFloat)0;
    VfxFloat tmp_b = (VfxFloat)0;

	memset(out_pixel_p, 0, m_inBufWidth * m_inBufHeight * 4); /* clean out buffer */
	
	anchor = m_anchor;

	warp_radius = m_warpRadius;
	square_of_warp_radius = warp_radius * warp_radius;
	inverse_to_square_of_warp_radius = (VfxFloat)1 / (VfxFloat) square_of_warp_radius;

	t_tmp = (VfxFloat)1 - (VfxFloat) (2 * VFX_ABS(level - 0.5));
	
	if (m_squeezePoint != VCP_JELLY_FILTER_CONTINUED_SQUEEZE)
	{
    	squeeze_point = m_squeezePoint;
	}
	else
	{
	 	squeeze_point = m_imageWidth * level;
	}
	if (m_squeezePoint_2 != VCP_JELLY_FILTER_CONTINUED_SQUEEZE)
	{
		squeeze_point_2 = m_squeezePoint_2; 
	}
	else
	{
		squeeze_point_2 = m_imageWidth * (1 - level);
	}

#ifndef VCP_JELLY_FILTER_4X_SPEED_UP
	for (x = m_inBufWidth - 1; x >= 0; x--)
#else
	for (x = m_inBufWidth - 1; x > 0; x-=2)
#endif
    {
		old_x = x;

		if ((old_x <= m_leftBoundary) || (old_x >= m_rightBoundary))
		{
			continue;
		}

		if (x < m_leftNewBoundary)
		{
			m_leftNewBoundary = x;
		}

		if (x > m_rightNewBoundary)
		{
			m_rightNewBoundary = x;
		}

		diff_x = old_x - squeeze_point;

        if (VFX_ABS(diff_x) < warp_radius)
        {
			square_of_cos = (VfxFloat) (((VfxFloat)(square_of_warp_radius - diff_x * diff_x)) * inverse_to_square_of_warp_radius);
			tmp_a = (VfxFloat)1 / ((VfxFloat)1 - t_tmp * m_squeezeCoefficient * square_of_cos * square_of_cos);
        }
        else
        {
            square_of_cos = 0;
        }

        diff_x = old_x - squeeze_point_2;

		if (VFX_ABS(diff_x) < warp_radius)
        {
			square_of_cos_2 = (VfxFloat) (((VfxFloat)(square_of_warp_radius - diff_x * diff_x)) * inverse_to_square_of_warp_radius);
			tmp_b = (VfxFloat)1 / ((VfxFloat)1 - t_tmp * m_squeezeCoefficient * square_of_cos_2 * square_of_cos_2);
        }
        else
        {
            square_of_cos_2 = 0;
        }
		
	#ifndef VCP_JELLY_FILTER_4X_SPEED_UP
		for (y = m_inBufHeight - 1; y >= 0; y--)
	#else
		for (y = m_inBufHeight - 1; y > 0; y-=2)
	#endif
    	{            
        	diff_y = y - anchor;

        	if (diff_y < 0)
        	{
        		if (square_of_cos == 0)
				{
					old_y = y;
				}
				else
				{
					old_y = anchor + (VfxS32)(diff_y * tmp_a);
				}
        	}
        	else
        	{
        		if (square_of_cos_2 == 0)
				{
					old_y = y;
				}
				else
				{
					old_y = anchor + (VfxS32)(diff_y * tmp_b);
				}
        	}

        	if ((old_y <= m_topBoundary) || (old_y >= m_bottomBoundary))
			{
				continue;
			}

			if (y < m_topNewBoundary)
			{
				m_topNewBoundary = y;
			}

			if (y > m_bottomNewBoundary)
			{
				m_bottomNewBoundary = y;
			}
				
            in_pixel = *(in_pixel_p + old_y * m_inBufWidth + old_x);

			*((VfxU32 *)out_pixel_p + y * m_inBufWidth + x) = in_pixel;

		#ifdef VCP_JELLY_FILTER_4X_SPEED_UP
			*((VfxU32 *)out_pixel_p + (y-1) * m_inBufWidth + x) = *(in_pixel_p + (old_y-1) * m_inBufWidth + old_x);
			*((VfxU32 *)out_pixel_p + y * m_inBufWidth + x-1) = *(in_pixel_p + old_y * m_inBufWidth + old_x-1);
			*((VfxU32 *)out_pixel_p + (y-1) * m_inBufWidth + x-1) = *(in_pixel_p + (old_y-1) * m_inBufWidth + old_x-1);
		#endif
        }
	}

    return VRT_TRUE;
}


VfxBool VcpJellyFilter::squeezeInY(VfxFloat level)
{
	VfxS32 x, y;
    VfxS32 old_x, old_y;
    VfxU32 *in_pixel_p = (VfxU32*)m_inBufP;
    VfxU32 in_pixel;
    VfxS32 warp_radius;
    VfxS32 anchor;
    VfxS32 diff_x, diff_y;
    VfxS32 squeeze_point;
    VfxU32 square_of_warp_radius;
    VfxU32 *out_pixel_p = (VfxU32*)m_outBufP;
    
    VfxFloat square_of_cos;
    VfxFloat inverse_to_square_of_warp_radius;
    VfxFloat t_tmp;

    /* temp variable for optimization */
    VfxFloat tmp_a = (VfxFloat)0;

	memset(out_pixel_p, 0, m_inBufWidth * m_inBufHeight * 4); /* clean out buffer */

	anchor = m_anchor;

	warp_radius = m_warpRadius;
	square_of_warp_radius = warp_radius * warp_radius;
	inverse_to_square_of_warp_radius = 1 / (VfxFloat) square_of_warp_radius;
	
    if (m_squeezePoint != VCP_JELLY_FILTER_CONTINUED_SQUEEZE)
	{
    	squeeze_point = m_squeezePoint;
	}
	else
	{
	 	squeeze_point = m_imageWidth * level;
	}

    t_tmp = (VfxFloat)1 - (VfxFloat) (2 * VFX_ABS(level - 0.5));
#ifndef VCP_JELLY_FILTER_4X_SPEED_UP
	for (x = m_inBufWidth - 1; x >= 0; x--)
#else
	for (x = m_inBufWidth - 1; x > 0; x-=2)
#endif
    {
		old_x = x;

		if ((old_x <= m_leftBoundary) || (old_x >= m_rightBoundary))
		{
			continue;
		}

		if (x < m_leftNewBoundary)
		{
			m_leftNewBoundary = x;
		}

		if (x > m_rightNewBoundary)
		{
			m_rightNewBoundary = x;
		}

		diff_x = old_x - squeeze_point;

        if (VFX_ABS(diff_x) < warp_radius)
        {
			square_of_cos = (VfxFloat) (((VfxFloat)(square_of_warp_radius - diff_x * diff_x)) * inverse_to_square_of_warp_radius);
			tmp_a = (VfxFloat)1 / ((VfxFloat)1 - t_tmp * m_squeezeCoefficient * square_of_cos * square_of_cos);
        }
        else
        {
            square_of_cos = 0;
        }
#ifndef VCP_JELLY_FILTER_4X_SPEED_UP
		for (y = m_inBufHeight - 1; y >= 0; y--)
#else
		for (y = m_inBufHeight - 1; y > 0; y-=2)
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

        	if ((old_y <= m_topBoundary) || (old_y >= m_bottomBoundary))
			{
				continue;
			}

			if (y < m_topNewBoundary)
			{
				m_topNewBoundary = y;
			}

			if (y > m_bottomNewBoundary)
			{
				m_bottomNewBoundary = y;
			}

            in_pixel = *(in_pixel_p + old_y * m_inBufWidth + old_x);

			*((VfxU32 *)out_pixel_p + y * m_inBufWidth + x) = in_pixel;
		#ifdef VCP_JELLY_FILTER_4X_SPEED_UP
			*((VfxU32 *)out_pixel_p + (y-1) * m_inBufWidth + x) = *(in_pixel_p + (old_y-1) * m_inBufWidth + old_x);
			*((VfxU32 *)out_pixel_p + y * m_inBufWidth + x-1) = *(in_pixel_p + old_y * m_inBufWidth + old_x-1);
			*((VfxU32 *)out_pixel_p + (y-1) * m_inBufWidth + x-1) = *(in_pixel_p + (old_y-1) * m_inBufWidth + old_x-1);
		#endif
        }
	}

    return VRT_TRUE;
}

VfxBool VcpJellyFilter::effectSelector(VfxS32 effectType, VfxFloat level)
{
	VfxBool returnValue = VFX_TRUE;
	
	switch (effectType)
	{
	case VCP_JELLY_FILTER_FUNCTYPE_TYPE_SQUEEZE_IN_X:
		returnValue = squeezeInX(level);
	    break;
    case VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_X:
    	returnValue = twoSqueezeInX(level);
        break;
    case VCP_JELLY_FILTER_FUNCTYPE_TYPE_SQUEEZE_IN_Y:
    	returnValue = squeezeInY(level);
    	break;
    case VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_Y:
    	returnValue = twoSqueezeInY(level);
    	break;
	default:
		VFX_ASSERT(0);
		break;
	}

	return returnValue;
}

void VcpJellyFilter::resetBoundary(VfxImageBuffer &inBuf)
{
	switch (m_transitionDirection)
	{
	case VCP_JELLY_FILTER_TRANSITION_DIRECTION_LEFTWARD:
		m_leftBoundary 	 = inBuf.width - m_rightMargin - m_imageWidth;
		m_rightBoundary  = inBuf.width - m_rightMargin;
		m_topBoundary 	 = m_topMargin;
		m_bottomBoundary = m_topBoundary + m_imageHeight;
		break;

	case VCP_JELLY_FILTER_TRANSITION_DIRECTION_UPWARD:
		m_leftBoundary 	 = m_leftMargin;
		m_rightBoundary  = m_leftBoundary + m_imageWidth;
		m_topBoundary 	 = inBuf.height - m_bottomMargin - m_imageHeight;
		m_bottomBoundary = inBuf.height - m_bottomMargin;
		break;

	case VCP_JELLY_FILTER_TRANSITION_DIRECTION_RIGHTWARD:
	case VCP_JELLY_FILTER_TRANSITION_DIRECTION_DOWNWARD:
		m_leftBoundary 	 = m_leftMargin;
		m_rightBoundary  = m_leftBoundary + m_imageWidth;
		m_topBoundary 	 = m_topMargin;
		m_bottomBoundary = m_topBoundary + m_imageHeight;
		break;

	default:
		VFX_ASSERT(0);
		break;
	}
	
	m_leftNewBoundary 	= m_leftBoundary;
	m_rightNewBoundary 	= m_rightBoundary;
	m_topNewBoundary 	= m_topBoundary;
	m_bottomNewBoundary = m_bottomBoundary;
}

VfxBool VcpJellyFilter::onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat level)
{
	VfxU32	 i;
	VfxFloat play_interval;
	VfxFloat play_start_level;
	VfxFloat play_end_level;

#if defined(VCP_JELLY_FILTER_PROFILING)
	VfxU32	 clock_count;

	kal_get_time(&clock_count);
    VFX_TRACE(("Vcp Jelly Filter On Process Clock Begin: %d\n", clock_count));
    VFX_LOG(VFX_INFO, VAPP_JELLY_FILTER_ON_PROCESS_CLOCK_BEGIN_MSG, clock_count);
#endif	

	/* common parameters */
	m_inBufWidth = inBuf.width;
	m_inBufHeight = inBuf.height;
	m_inBufP = inBuf.ptr;
	m_outBufP = outBuf;
	
	if (level <= 0 || level >= 1)
    {
        /* to do remove memcpy */
        memcpy(outBuf, inBuf.ptr, inBuf.width * inBuf.height * 4);
        return VRT_FALSE;
    }
    
	play_interval = 1 / (VfxFloat)(m_keyFrameCount+ 1);

	/* setting parameters for each key frame */
	/* At any moment, one or two key frames will take effects 				*/
	/* If two key frames take effects, the out buffer of first key frame 	*/
	/* will be the in buffer of the second key frame 						*/
	for (i = 0; i < m_keyFrameCount; i++)
	{
		if (m_keyFrameSettingArray[i].startLevel == VCP_JELLY_FILTER_NULL_LEVEL)
		{
			play_start_level = i * play_interval;
		}
		else
		{
			play_start_level = m_keyFrameSettingArray[i].startLevel;
		}

		if (m_keyFrameSettingArray[i].endLevel == VCP_JELLY_FILTER_NULL_LEVEL)
		{
			play_end_level = (i + 2) * play_interval;
		}
		else
		{
			play_end_level = m_keyFrameSettingArray[i].endLevel;
		}

		VFX_ASSERT(play_start_level <= play_end_level);

        if ((level >= play_start_level) && (level < play_end_level))
		{   /* each key frame occupy two intervals */
			VfxFloat rescale_t;

        	rescale_t = (VfxFloat)(level - play_start_level) / (play_end_level - play_start_level);

			/* specific settings for each key frame */
			m_squeezePoint = m_keyFrameSettingArray[i].squeezePoint;
			m_squeezePoint_2 = m_keyFrameSettingArray[i].squeezePoint2;
			m_anchor = m_keyFrameSettingArray[i].anchor;
			m_squeezeCoefficient = m_keyFrameSettingArray[i].squeezeCoefficient;
			
			/* set in-buffer and out-buffer */
			if (rescale_t < 0.5)
			{
				if (i == 0)
				{   
					resetBoundary(inBuf);
				}
				else
				{
                    /* boundaries are from previous key frame's */
					m_leftBoundary 	 = m_leftNewBoundary;
					m_rightBoundary  = m_rightNewBoundary;
					m_topBoundary 	 = m_topNewBoundary;
					m_bottomBoundary = m_bottomNewBoundary;
				}				

				effectSelector(m_keyFrameSettingArray[i].funcType, rescale_t);
			}
			else
			{
				resetBoundary(inBuf);
				effectSelector(m_keyFrameSettingArray[i].funcType, rescale_t);
				/*
				if (i != m_keyFrameCount - 1)
				{
					memcpy(inBuf.ptr, outBuf, inBuf.width * inBuf.height * 4);
				}
				*/
				
			}
		}
	}

#if defined(VCP_JELLY_FILTER_PROFILING)

	kal_get_time(&clock_count);

	VFX_TRACE(("Vcp Jelly Filter On Process Clock End: %d\n", clock_count));	
	VFX_LOG(VFX_INFO, VAPP_JELLY_FILTER_ON_PROCESS_CLOCK_END_MSG, clock_count);

#endif	

	return VRT_TRUE;
}

