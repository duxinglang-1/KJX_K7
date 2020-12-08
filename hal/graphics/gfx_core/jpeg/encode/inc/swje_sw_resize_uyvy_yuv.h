/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   swje_sw_r2y_565.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __SWJE_SW_UYVY_YUV_H__
#define __SWJE_SW_UYVY_YUV_H__

#include "kal_general_types.h"

/**
 * @brief                  CSC(UYVY -> YUV420).
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swje_frag_proc_func_uyvy_to_yuv420_csc_no_resize_no_pad(void *fragProcPtr);



/**
 * @brief                  CSC(UYVY -> YUV420) + Resize.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swje_frag_proc_func_uyvy_to_yuv420_csc_resize_no_pad(void *fragProcPtr);




/**
 * @brief                  CSC(UYVY -> YUV422).
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swje_frag_proc_func_uyvy_to_yuv422_csc_no_resize_no_pad(void *fragProcPtr);



/**
 * @brief                  CSC(UYVY -> YUV422) + Resize.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swje_frag_proc_func_uyvy_to_yuv422_csc_resize_no_pad(void *fragProcPtr);



/**
 * @brief                  CSC(UYVY -> YUV420) + Padding.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swje_frag_proc_func_uyvy_to_yuv420_csc_no_resize_pad(void *fragProcPtr);



/**
 * @brief                  CSC(UYVY -> YUV420) + Padding + Resize.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swje_frag_proc_func_uyvy_to_yuv420_csc_resize_pad(void *fragProcPtr);



/**
 * @brief                  CSC(UYVY -> YUV422) + Padding.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swje_frag_proc_func_uyvy_to_yuv422_csc_no_resize_pad(void *fragProcPtr);



/**
 * @brief                  CSC(UYVY -> YUV422) + Padding + Resize.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swje_frag_proc_func_uyvy_to_yuv422_csc_resize_pad(void *fragProcPtr);

#endif
