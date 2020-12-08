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
 *    pdn_hw_series.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the power down management header file
 *
 * Author:
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *
 ****************************************************************************/
#include "kal_general_types.h"

#ifndef __PDN_HW_SERIES_H__
#define __PDN_HW_SERIES_H__

/*******************************************************************************
 * Define HW registers
 *******************************************************************************/

#if defined(MT6253T) || defined(MT6253)
#include "pdn_hw_mt6253_series.h"
#endif  /* MT6253T || MT6253 */

#if defined(MT6251)
#include "pdn_hw_mt6251_series.h"
#endif  /* MT6251 */

#if defined(MT6236) || defined(MT6236B)
#include "pdn_hw_mt6236_series.h"
#endif  /* MT6236 || MT6236B */

#if defined(MT6270A)
#include "pdn_hw_mt6270a_series.h"
#endif //MT6270A

#if defined(MT6256)
#include "pdn_hw_mt6256_series.h"
#endif //MT6256

#if defined(MT6276)
#include "pdn_hw_mt6276_series.h"
#endif //MT6276

#if defined(MT6253E) || defined(MT6253L)
#include "pdn_hw_mt6253EL_series.h"
#endif  /* MT6253E || MT6253L */

#if defined(MT6252) || defined(MT6252H)
#include "pdn_hw_mt6252_series.h"
#endif  /* MT6252 || MT6252H */

#if defined(MT6573)
#include "pdn_hw_mt6573_series.h"
#endif //MT6573

#if defined(MT6255)
#include "pdn_hw_mt6255_series.h"
#endif //MT6255

#if defined(MT6250)
#include "pdn_hw_mt6250_series.h"
#endif //MT6250

#if defined(MT6260)
#include "pdn_hw_mt6260_series.h"
#endif //MT6260

#endif /* !__PDN_HW_SERIES_H__ */

