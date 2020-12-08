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
 *   swje_fragment_processor.h
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
#ifndef __SWJE_FRAGMENT_PROCESSOR_H__
#define __SWJE_FRAGMENT_PROCESSOR_H__

#include "kal_general_types.h"

#include "iul_x_math.h"

#include "jpeg_enum.h"
    
#include "swje_structure.h"

/**
 * @brief                  Set Source Step.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeFragProcSetSrcStep(SWJE_FRAGMENT_PROCESSOR *pFragProcessor, IUL_FIXED srcStepX, IUL_FIXED srcStepY);



/**
 * @brief                  Set Destination Step.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeFragProcSetDstStep(SWJE_FRAGMENT_PROCESSOR *pFragProcessor, IUL_FIXED dstStepX, IUL_FIXED dstStepY);


kal_int32 swjeFragProcSetRotation(SWJE_FRAGMENT_PROCESSOR *pFragProcessor, JPEG_ENCODE_ROTATE_ANGLE_ENUM angle);


kal_int32 swjeFragProcSetDstRotateRGBBuffer(SWJE_FRAGMENT_PROCESSOR *pFragProcessor, void *rotateRGBBuffer);

kal_int32 swjeFragProcSetDstRotateYUVBuffer(SWJE_FRAGMENT_PROCESSOR *pFragProcessor, 
                                            void *dstYBuffer, void *dstUBuffer, void *dstVBuffer, 
                                            kal_uint32 dstYBufferSize, kal_uint32 dstUBufferSize, kal_uint32 dstVBufferSize);
                                            
kal_int32 swjeFragProcSetSrcResizeYUVBuffer(SWJE_FRAGMENT_PROCESSOR *pFragProcessor, void *srcYBuffer, void *srcUBuffer, void *srcVBuffer);

/**
 * @brief                  Set Source RGB Canvas.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeFragProcSetSrcRGBBuffer(SWJE_FRAGMENT_PROCESSOR *pFragProcessor, 
                                      void *srcRGBBuffer, kal_uint32 srcWidth, kal_uint32 srcHeight, JPEG_RGB_FORMAT_ENUM srcRGBFormat);
                                      


/**
 * @brief                  Set Resize RGB Canvas.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeFragProcSetDstResizeRGBBuffer(SWJE_FRAGMENT_PROCESSOR *pFragProcessor, void *resizeRGBBuffer);
   
kal_int32 swjeFragProcSetSrcResizeRGBBuffer(SWJE_FRAGMENT_PROCESSOR *pFragProcessor, void *srcResizeRGBBuffer);

/**
 * @brief                  Set Resize YUV Canvas.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeFragProcSetResizeYUVBuffer(SWJE_FRAGMENT_PROCESSOR *pFragProcessor, void *resizeRGBBuffer);

   
                                      

/**
 * @brief                  Set Source YUV Canvas.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */                                      
kal_int32 swjeFragProcSetSrcYUVBuffer(SWJE_FRAGMENT_PROCESSOR *pFragProcessor, 
                                      void *srcYBuffer, void *srcUBuffer, void *srcVBuffer,
                                      kal_uint32 srcWidth, kal_uint32 srcHeight, JPEG_YUV_FORMAT_ENUM srcYUVFormat);
                                      
                                      

/**
 * @brief                  Set Resize Destionation YUV Canvas.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeFragProcSetDstExpectResizeSize(SWJE_FRAGMENT_PROCESSOR *pFragProcessor, kal_uint32 w, kal_uint32 h);

kal_int32 swjeFragProcSetSrcResizeSize(SWJE_FRAGMENT_PROCESSOR *pFragProcessor, kal_uint32 w, kal_uint32 h);

/**
 * @brief                  Set Destionation YUV Canvas.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */                                        
kal_int32 swjeFragProcSetDstYUVBuffer(SWJE_FRAGMENT_PROCESSOR *pFragProcessor, 
                                      void *srcYBuffer, void *srcUBuffer, void *srcVBuffer,
                                      kal_uint32 dstWidth, kal_uint32 dstHeight, JPEG_YUV_FORMAT_ENUM dstSamplingFormat);



/**
 * @brief                  Set Output Image Size.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */ 
kal_int32 swjeFragProcSetOutputImageSize(SWJE_FRAGMENT_PROCESSOR *pFragProcessor,  kal_uint32 outputImageWidth, kal_uint32 outputImageHeight);



/**
 * @brief                  Set Fragment Process function.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeFragProcDecideFunc(SWJE_FRAGMENT_PROCESSOR *pFragProcessor);



/**
 * @brief                  Set the parameter to calculate the padding.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeFragProcSetPadding(SWJE_FRAGMENT_PROCESSOR *pFragProcessor, kal_uint32 mcuWidth, kal_uint32 mcuHeight);




/**
 * @brief                  Set the source clipping window.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeFragProcSetSrcClipWindow(SWJE_FRAGMENT_PROCESSOR *pFragProcessor, 
                                       kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h);

                                       
kal_int32 swjeFragProcSetSrcResizeClipWindow(SWJE_FRAGMENT_PROCESSOR *pFragProcessor,
                                             kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h);
                                             
/**
 * @brief                  Start to do fragment processor.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeFragProcProcessFragment(SWJE_FRAGMENT_PROCESSOR *pFragProcessor);


kal_int32 swjeFragProcHwYUVResizeCheckNeedHwResize(SWJE_FRAGMENT_PROCESSOR *pFragProcessor);


/**
 * @brief                  Start to do resize fragment processor.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeFragProcHwYUVResizeProcessFragment(SWJE_FRAGMENT_PROCESSOR *pFragProcessor);



/**
 * @brief                  Set the source clipping window.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeFragProcHwYUVResizeSetSrcClipWindow(SWJE_FRAGMENT_PROCESSOR *pFragProcessor, kal_int32 x, kal_int32 y);



/**
 * @brief                  Set the destination clipping window.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeFragProcHwYUVResizeSetDstResizeSize(SWJE_FRAGMENT_PROCESSOR *pFragProcessor, kal_uint32 w, kal_uint32 h);
                                                        

/**
 * @brief                  Get the Fragment Processor output buffer.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeFragProcGetDstYUVBuffer(SWJE_FRAGMENT_PROCESSOR *pFragProcessor, kal_uint8 *dstBuffer[3], kal_uint32 *dstPitch);
                                      
                                      

kal_int32 swjeFragProcResetDstYUVBuffer(SWJE_FRAGMENT_PROCESSOR *pFragProcessor, kal_uint8 *dstBuffer[3], kal_uint32 dstClipX);
                                      
#endif

