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
 *
 * Filename:
 * ---------
 *   aac_dec_exp.h
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   The AAC Decoder Interface
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
#ifndef _AACDEC_EXP_H
#define _AACDEC_EXP_H



/*   ASSERT Definition */
#if defined(__MTK_TARGET__)
//#include "kal_release.h"
#else

#ifndef ASSERT
#include <assert.h>
#define ASSERT(x)    assert(x)
#endif

#ifndef NULL
#define NULL    0
#endif
#endif


/* Structure Definition */
typedef struct {
	 int sampleRate;
	 int channelNum;
    int sbrFlag;
}AACDEC_Handle;


/* Interface Functions */
void AACDec_GetMemSize( int *InterBufSize, 			     /* required size of internal buffer */
								        int *TmpBufSize ,       /* required size of temporary buffer */
								        int *PcmBufSize,        /* required size of PCM buffer */
								        int *BsBufSize,         /* minimum required size of bitstream buffer */
								        int *SbrBufSize);       /* required size of SBR buffer */
											 
AACDEC_Handle* AACDec_Init( void *pInterBuf,       /* pointer to internal buffer */
                            void *pSbrBuf          /* pointer to SBR buffer */
                           );
                           
int AACDec_Set_DSCE_Config (AACDEC_Handle *pAacDecHandle, int dsce_config);
int AACDec_Bypass_CRC_Check(AACDEC_Handle *pAacDecHandle, int bypass);

int AACDec_DecodeFrame(AACDEC_Handle *pAacDecHandle,     /* pointer to decoder handle */
                       void* pPcmBuf,                    /* pointer to PCM buffer */
                       void* pTmpBuf,                    /* pointer to temprary buffer */
                       const void* pBsBuf,               /* pointer to bitstream buffer */
                       int BsBufLen,                     /* pointer to bitstream length */
                       const void* pBsRead,              /* bitstream buffer read pointer */
                       int *consumBsLen);                /* consumed length of bitstream */

int AACDec_DecodeFrameBypass(AACDEC_Handle *pAacDecHandle,     /* pointer to decoder handle */
                       void* pPcmBuf,                    /* pointer to PCM buffer */
                       void* pTmpBuf,                    /* pointer to temprary buffer */
                       const void* pBsBuf,               /* pointer to bitstream buffer */
                       int BsBufLen,                     /* pointer to bitstream length */
                       const void* pBsRead,              /* bitstream buffer read pointer */
                       int *consumBsLen);                /* consumed length of bitstream */


#endif
