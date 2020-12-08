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
#include "MMIDataType.h"
#include "MMI_features.h"
#if defined (__MMI_MAINLCD_176X220__)
// new slim pluto
#if defined (__LOW_COST_SUPPORT_COMMON__)
const U16 gCalcImgCoor[][2] = 
{
#if defined(__MMI_SLIM_IMG_RES__)
	{49, 6},           // +
	{49, 66},           // -
	{13, 36},           // x
	{86,36},           // /
	{49, 36},           // = 
#else
	{53, 19},          // +
	{53, 44},          // -
	{53, 19},          // x
	{89, 19},          // /
	{0, 0},            // =
	{31, 2},           // M+
	{31, 70},          // M-
	{30, 3},           // MC
	{126,3}            // MR
#endif
};
// old pluto
#else   /* defined (__LOW_COST_SUPPORT_COMMON__)*/
const U16 gCalcImgCoor[][2] = 
{
	{54, 17},
	{55, 44},
	{52, 21},
	{87, 21},
	{0, 0},   
	{34, 2},
	{34, 66},
	{27, 8},
	{122,7}
};
#endif  /* defined (__LOW_COST_SUPPORT_COMMON__)*/

#elif defined (__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__)
const U16 gCalcImgCoor[][2] = 
{
#if defined(__MMI_SLIM_IMG_RES__)
	{66, 9},  // +
	{66, 87},  // -
	{19, 48},  // x
	{115, 48},  // /
	{66, 48}   // =
#else
	{73, 33},
	{73, 66},
	{73, 33},
	{119, 33},
	{0, 0},
	{30, 0},
	{30, 100},
	{30, 0},
	{167, 0}
#endif
};

#elif defined (__MMI_MAINLCD_320X480__)
const U16 gCalcImgCoor[][2] = 
{
	{135, 160},  // +
	{135, 295},  // -
	{67, 229},  // x
	{205, 225},  // /
	{122, 213}   // =
};

#else
// new slim pluto
#if defined (__LOW_COST_SUPPORT_COMMON__)
const U16 gCalcImgCoor[][2] = {
#if defined(__MMI_SLIM_IMG_RES__)
	{35, 4},  // +
	{35, 47},  // -
	{9, 25},  // x
	{62, 25},  // /
	{35, 25}   // =
#else
	{17, 16},
	{17, 38},
	{16, 17},
	{60, 17},
	{26, 26},  
	{1, 0},
	{0, 48},
	{0,  1},
	{70, 1}
#endif
};

// old pluto
#else   /* defined (__LOW_COST_SUPPORT_COMMON__)*/
const U16 gCalcImgCoor[][2] = {
	{24, 11},
	{24, 38},
	{16, 18},
	{52, 17},
	{31, 22},  
	{13, 0},
	{14, 45},
	{0,  10},
	{62, 10}
};
#endif  /* defined (__LOW_COST_SUPPORT_COMMON__)*/

#endif
