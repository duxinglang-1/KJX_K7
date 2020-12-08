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
 *   swje_quant_fdct_unit.h
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
#ifndef __SWJE_FDCT_QUANT_UNIT_H__
#define __SWJE_FDCT_QUANT_UNIT_H__

#include "kal_general_types.h"

#include "swje_structure.h"



/**
 * @brief                  Generate Quantization table for YUV component.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeFDCTQuantGenNonStdQuantTable(SWJE_QUANT_TABLE *table,
                                     kal_uint32 tableID, SWJE_QUANT_TABLE_ENUM tableType, kal_int32 dstQualityDivider,
                                     kal_bool enableDynamicQuantAdjustment, float quantScaleFactor);



kal_int32 swjeFDCTQuantGenStdQuantTable(SWJE_QUANT_TABLE *table,
                                        kal_uint32 tableID, SWJE_QUANT_TABLE_ENUM tableType, kal_int32 dstQualityDivider,
                                     kal_bool enableDynamicQuantAdjustment, float quantScaleFactor);



/**
 * @brief                  Set Quantization table for YUV component.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeFDCTQuantSetQuantTable(SWJE_FDCT_QUANT_UNIT *pFDCTQuantUnit, SWJE_QUANT_TABLE *table) ;



/**
 * @brief                  Set Z-Zag table for YUV component.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeFDCTQuantSetZZagTable(SWJE_FDCT_QUANT_UNIT *pFDCTQuantUnit, kal_uint32 *table);



/**
 * @brief                  Set FDCT destination canvas.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeFDCTQuantSetFDCTDstBuffer(SWJE_FDCT_QUANT_UNIT *pFDCTQuantUnit, kal_uint8 *dstWritePtr);



/**
 * @brief                  Get Quantization destination canvas.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeFDCTQuantGetQuantDstBuffer(SWJE_FDCT_QUANT_UNIT *pFDCTQuantUnit, kal_uint8 **dstWritePtr);



/**
 * @brief                  Set Quantization destination canvas.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeFDCTQuantSetQuantDstBuffer(SWJE_FDCT_QUANT_UNIT *pFDCTQuantUnit, kal_uint8 *dstWritePtr);



kal_int32 swjeFDCTQuantGetSrcBuffer(SWJE_FDCT_QUANT_UNIT *pFDCTQuantUnit, kal_uint8 **srcBuffer, kal_uint32 *srcPitch);

/**
 * @brief                  Set source canvas.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeFDCTQuantSetSrcBuffer(SWJE_FDCT_QUANT_UNIT *pFDCTQuantUnit, kal_uint8 *srcReadPtr, kal_uint32 src_pitch);



/**
 * @brief                  Start to do FDCTQuant processor.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeFDCTQuantProcessDU(void *FDCTQuantPtr, kal_int32 compID, kal_uint32 duCount);



/**
 * @brief                  
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeFDCTQuantGetLastNonzeroCoeff(SWJE_FDCT_QUANT_UNIT *pFDCTQuantUnit, kal_uint32 duCount, kal_uint32 *lastNonzeroCoeff);

//(SWJE_FDCT_QUANT_UNIT* pFDCTQuantUnit, kal_uint8 *srcReadPtr, kal_uint32 srcPitch)
#define SWJE_FDCT_QUANT_SET_SRC_BUFFER(pFDCTQuantUnit, srcReadPtr, srcPitchval)\
do{                                                                            \
   pFDCTQuantUnit->pSrc = srcReadPtr;                                          \
   pFDCTQuantUnit->srcPitch = srcPitchval;                                     \
}while(0)


//(SWJE_FDCT_QUANT_UNIT *pFDCTQuantUnit, kal_uint32 duCount, kal_uint32 lastNonzeroCoeff)
#define SWJE_FDCT_WUANT_GET_LAST_NONZERO_COEFF(FDCTQuantUnit, duCount, lastNonzeroCoeff)\
do{                                                                            \
   lastNonzeroCoeff = (FDCTQuantUnit.lastNonzeroCoeff >> (duCount << 3)) & 0xFF;                          \
}while(0)


#endif
