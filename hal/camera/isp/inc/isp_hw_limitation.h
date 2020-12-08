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
 *   MT6238
 *
 * Description:
 * ------------
 *   This file is intends for ISP HW.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __ISP_HW_LIMITATION_H__
#define __ISP_HW_LIMITATION_H__

#include "drv_features.h"

#undef __ISP_MEMORY_IN_ADDRESS_LIMITATION__			/* raw sensor support */


// define some comoon compile option for ISP drivers of various chips.
#if (defined(DRV_ISP_MT6236_HW_SUPPORT))
#define __ISP_MEMORY_IN_ADDRESS_LIMITATION__
#define ISP_MEMORY_IN_ADDRESS_BOUNDARY (0x4000000)
#define ISP_MEMORY_IN_ADDRESS_BOUNDARY_SHIFT_BIT (26)
#endif

#if (defined(DRV_ISP_MT6268_HW_SUPPORT))
#define __ISP_MEMORY_IN_ADDRESS_LIMITATION__
#define ISP_MEMORY_IN_ADDRESS_BOUNDARY (0x4000000)	
#define ISP_MEMORY_IN_ADDRESS_BOUNDARY_SHIFT_BIT (26)
#endif


#if (defined(MT6235)||defined(MT6235B))
#define __ISP_MEMORY_IN_ADDRESS_LIMITATION__
#define ISP_MEMORY_IN_ADDRESS_BOUNDARY (0x1000000)
#define ISP_MEMORY_IN_ADDRESS_BOUNDARY_SHIFT_BIT (24)
#endif




#endif /* __ISP_HW_FEATURE_DEF_H__ */
