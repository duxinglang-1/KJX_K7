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
 * Filename:
 * ---------
 *  vapp_atv_gprot.h
 *
 * Project:
 * --------
 *  Venus
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

#ifndef _VAPP_ATV_GPROT_H_
#define _VAPP_ATV_GPROT_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include "gdi_include.h"
/*****************************************************************************
 * Define
 *****************************************************************************/
#if ((LCD_WIDTH == 240) && (LCD_HEIGHT == 320))

#define VAPP_ATV_THUMBNAIL_W (36)
#define VAPP_ATV_THUMBNAIL_H (36)


#elif ((LCD_WIDTH == 240) && (LCD_HEIGHT == 400))

#define VAPP_ATV_THUMBNAIL_W (36)
#define VAPP_ATV_THUMBNAIL_H (36)


#elif ((LCD_WIDTH == 320) && (LCD_HEIGHT == 480))

#define VAPP_ATV_THUMBNAIL_W (54)
#define VAPP_ATV_THUMBNAIL_H (54)

#elif ((LCD_WIDTH == 480) && (LCD_HEIGHT == 800))

#define VAPP_ATV_THUMBNAIL_W (72)
#define VAPP_ATV_THUMBNAIL_H (72)

#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */

#define VAPP_ATV_MAX_SERVICES (30)
#define VAPP_ATV_SERVICE_STRUCT_SIZE (170)

#define VAPP_ATV_SERVICE_SIZE (VAPP_ATV_MAX_SERVICES * VAPP_ATV_SERVICE_STRUCT_SIZE)

#define VAPP_ATV_LAYER_SIZE (GDI_LCD_WIDTH*GDI_LCD_HEIGHT*(GDI_MAINLCD_BIT_PER_PIXEL>>3))
#define VAPP_ATV_SNAPSHOT_SIZE (GDI_LCD_WIDTH*GDI_LCD_HEIGHT*(GDI_MAINLCD_BIT_PER_PIXEL>>3))
#define VAPP_ATV_THUMBNAIL_SIZE (VAPP_ATV_THUMBNAIL_W*VAPP_ATV_THUMBNAIL_H*(GDI_MAINLCD_BIT_PER_PIXEL>>3))

/*****************************************************************************
 * Structure
 *****************************************************************************/


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _VAPP_GALLERY_GPROT_H_ */
