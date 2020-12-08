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
 *   lens_module.h
 *
 * Project:
 * --------
 *   MT6219/MT6226/MT6227/MT6228/MT6229
 *
 * Description:
 * ------------
 *   Lens module header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _LENS_MODULE_SUNNY_Q5M04B_MT9P015_BH6412GUL_
#define _LENS_MODULE_SUNNY_Q5M04B_MT9P015_BH6412GUL_

#include "mm_comm_def.h"
#include "aaa_af.h"
#include "lens_comm_def.h"

#if (defined(AF_SUPPORT))

#define BH6412GUL_HW_SCCB
#define BH6412GUL_SCCB_FAST_MODE_SPEED 200

extern AF_LENS_TIMING_STRUCT SunnyQ5m04bMt9p015Bh6412gulCameraLensTiming;
extern MM_ERROR_CODE_ENUM SunnyQ5m04bMt9p015Bh6412gulLensFuncInit(P_LENS_FUNCTION_STRUCT *pfFunc);

#define BH6412GUL_WRITE_ID          0x18
#define BH6412GUL_READ_ID           0x19

#define SUNNY_Q5M04B_MT9P015_BH6412GUL_LENS_I2C_DELAY    0x20

#define SUNNY_Q5M04B_MT9P015_BH6412GUL_Lens_START_BIT \
{ \
    volatile kal_uint32 j; \
    SET_SCCB_CLK_OUTPUT; \
    SET_SCCB_DATA_OUTPUT; \
    SET_SCCB_CLK_HIGH; \
    SET_SCCB_DATA_HIGH; \
    for(j=0;j<SUNNY_Q5M04B_MT9P015_BH6412GUL_LENS_I2C_DELAY;j++);\
    SET_SCCB_DATA_LOW; \
    for(j=0;j<SUNNY_Q5M04B_MT9P015_BH6412GUL_LENS_I2C_DELAY;j++);\
    SET_SCCB_CLK_LOW; \
}

#define SUNNY_Q5M04B_MT9P015_BH6412GUL_Lens_STOP_BIT \
{ \
    volatile kal_uint32 j; \
    SET_SCCB_CLK_OUTPUT; \
    SET_SCCB_DATA_OUTPUT; \
    SET_SCCB_CLK_LOW; \
    SET_SCCB_DATA_LOW; \
    for(j=0;j<SUNNY_Q5M04B_MT9P015_BH6412GUL_LENS_I2C_DELAY;j++);\
    SET_SCCB_CLK_HIGH; \
    for(j=0;j<SUNNY_Q5M04B_MT9P015_BH6412GUL_LENS_I2C_DELAY;j++);\
    SET_SCCB_DATA_HIGH; \
}

#endif

#endif /* _LENS_MODULE_SUNNY_Q5M04B_MT9P015_BH6412GUL */
