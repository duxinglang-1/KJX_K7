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
 *   image_sensor_OV7675.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   CMOS sensor header file
 *
 * Author:
 * -------
 * -------
 *
 *=============================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *=============================================================
 ****************************************************************************/

#ifndef _IMAGE_SENSOR_OV7675_H
	#define _IMAGE_SENSOR_OV7675_H

	#include "sensor_comm_def.h"

	/* SENSOR VGA SIZE */
	#define OV7675_IMAGE_SENSOR_VGA_WIDTH					(640)
	#define OV7675_IMAGE_SENSOR_VGA_HEIGHT					(478)

	/* SETUP TIME NEED TO BE INSERTED */
	#define OV7675_IMAGE_SENSOR_VGA_INSERTED_PIXELS			128//56//(0)   
	#define OV7675_IMAGE_SENSOR_VGA_INSERTED_LINES		    17//(1)
	
	/* SENSOR READ/WRITE ID */
	#define OV7675_WRITE_ID								0x42
	#define OV7675_READ_ID								0x43

	MM_ERROR_CODE_ENUM OV7675SensorClose(void);
	MM_ERROR_CODE_ENUM OV7675SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc);

	MM_ERROR_CODE_ENUM OV7675WebcamFeatureCtrl(kal_uint32 FeatureId,
	                                                void *pFeatureParaIn, void *pFeatureParaOut,
	                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen);


#endif 	/* #ifndef _IMAGE_SENSOR_OV7675_H */
