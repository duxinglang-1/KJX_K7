/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 *   matv_hostdrv.h
 *
 * Project:
 * --------
 *   Maui_sw
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
 *****************************************************************************
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MATV_HOSTDRV_H__
#define __MATV_HOSTDRV_H__

#if defined(__MTK_TARGET__) 

	#include "drv_features.h"
	
  /* SENSOR FULL SIZE */
	#if defined(__SERIAL_SENSOR_V1_SUPPORT__)
	#define ATV_IMAGE_SENSOR_FULL_WIDTH	316 // 312 (320)
	#define ATV_IMAGE_SENSOR_FULL_HEIGHT	236 //(240)
	#else	
	#define ATV_IMAGE_SENSOR_FULL_WIDTH	320 // 312 (320)
	#define ATV_IMAGE_SENSOR_FULL_HEIGHT	240 //(240)
	#endif
	/* SENSOR START/EDE POSITION */
	#define ATV_FULL_PERIOD_PIXEL_NUMS 858 //PAL 864
	#define ATV_FULL_PERIOD_LINE_NUMS	 525 //PAL 625
	#define ATV_PV_PERIOD_PIXEL_NUMS	(ATV_FULL_PERIOD_PIXEL_NUMS)
	#define ATV_PV_PERIOD_LINE_NUMS	(ATV_FULL_PERIOD_LINE_NUMS)
	
	/* SETUP TIME NEED TO BE INSERTED */
	#if defined(__SERIAL_SENSOR_V1_SUPPORT__)
	#define ATV_IMAGE_SENSOR_PV_INSERTED_PIXELS		0  
	#define ATV_IMAGE_SENSOR_PV_INSERTED_LINES			1	
	#define ATV_IMAGE_SENSOR_FULL_INSERTED_PIXELS	0
	#define ATV_IMAGE_SENSOR_FULL_INSERTED_LINES		1
	#else
	#define ATV_IMAGE_SENSOR_PV_INSERTED_PIXELS		12  
	#define ATV_IMAGE_SENSOR_PV_INSERTED_LINES			3	
	#define ATV_IMAGE_SENSOR_FULL_INSERTED_PIXELS	12
	#define ATV_IMAGE_SENSOR_FULL_INSERTED_LINES		3
	#endif	
	
	#define ATV_IMAGE_WIDTH_OFFSET				        12
	#define ATV_IMAGE_HEIGHT_OFFSET				        14
        #define ATV_20FPS   20
        #define ATV_15FPS   15
        #define ATV_30FPS   30
	/* SENSOR READ/WRITE ID */
	#define ATV_WRITE_ID				        0x82 
	#define ATV_READ_ID					  0x83 
	#define ATV_READ_REG_ID				  0xF1

#endif /* __MTK_TARGET__ */

#include "sensor_common_interface.h"

#define mATV_SENSOR_ID 0xff

MM_ERROR_CODE_ENUM mATV_SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);
void ATV_i2c_init(void);
void ATV_i2c_deinit(void);

#endif /* __MATV_HOSTDRV_H__ */
