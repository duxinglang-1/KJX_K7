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
 *  Resource_features_bcr.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  BCR Application
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
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef MMI_BCR_FEATURES_H
#define MMI_BCR_FEATURES_H

#include "MMI_features.h"

#ifdef __MMI_BCR__

#ifdef HORIZONTAL_CAMERA
    #define __MMI_HORIZONTAL_BCR__
#endif

/****************************************************************************
* Debug mode 
*****************************************************************************/
#ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*IDP rotate*/
#if defined(__MDI_CAMERA_HW_ROTATOR_SUPPORT__) && defined(GDI_USING_2D_ENGINE_V3) && defined(__MMI_HORIZONTAL_BCR__)
#define __MMI_BCR_USE_IDP_ROTATE__
#endif 

/****************************************************************************
* Vendor decode support  
*****************************************************************************/
#define __MMI_BCR_RECOGNIZE_MODE__

/****************************************************************************
* Watch dog open or not 
*****************************************************************************/
#define __MMI_BCR_PREVIEW_WATCHDOG_TIMEOUT__
#ifdef __MMI_BCR_PREVIEW_WATCHDOG_TIMEOUT__
    #define MMI_BCR_WATCHDOG_TIMEOUT_DUR_MAX       (120000)
    #define MMI_BCR_WATCHDOG_TIMEOUT_DUR_INTERVAL   (20000)
#endif


/****************************************************************************
* Device Feature Customization 
*****************************************************************************/
/*touch screen suport*/
#ifdef __MMI_TOUCH_SCREEN__
    #define __MMI_BCR_TOUCH_SCREEN_SUPPORT__
#endif 

//#define __MMI_BCR_ZOOM__

/****************************************************************************
* Camera Feature Customization 
*****************************************************************************/

/****************************************************************************
* EV status support
*****************************************************************************/
#define __MMI_BCR_EV_2__
#define __MMI_BCR_EV_3__
#define __MMI_BCR_EV_4__
#define MMI_BCR_EV_PRESS_LONG_DUR (300)
#define MMI_BCR_EV_PRESS_SHORT_DUR (100)

/****************************************************************************
* AF support
*****************************************************************************/
#ifdef AF_SUPPORT
    #define __MMI_BCR_AF_SUPPORT__
#endif

#ifdef __MMI_BCR_AF_SUPPORT__
    #define __MMI_BCR_FOCUS_MODE__ /* auto is default */
    #define __MMI_BCR_FOCUS_MODE_MACRO__
#endif 

/****************************************************************************
* Flash support
*****************************************************************************/
#if defined(LED_ONOFF_SUPPORT) || defined(LED_FLASHLIGHT_SUPPORT)
#define __MMI_BCR_FLASH__	
#endif

/****************************************************************************
* storage support
*****************************************************************************/
#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__))
    #define __MMI_BCR_STORAGE__
#endif

/****************************************************************************
* banding support
*****************************************************************************/
#define __MMI_BCR_BANDING__

/****************************************************************************
* rotate
*****************************************************************************/
#ifdef __MMI_HORIZONTAL_BCR__
	#define MMI_BCR_LCM_MAINLCD_ROTATE MMI_BCR_LCM_ROTATE_270
#else
	#define MMI_BCR_LCM_MAINLCD_ROTATE MMI_BCR_LCM_ROTATE_0
#endif

#if defined(SENSOR_ON_BODY)
    #if defined(SENSOR_ROTATE_0)
        #define MMI_BCR_PREVIEW_MAINLCD_ROTATE           MMI_BCR_PREVIEW_ROTATE_0
    #elif defined(SENSOR_ROTATE_180)
        #define MMI_BCR_PREVIEW_MAINLCD_ROTATE           MMI_BCR_PREVIEW_ROTATE_180
    #else
        /* rotate 90, 270 not used yet */
        #define MMI_BCR_PREVIEW_MAINLCD_ROTATE           MMI_BCR_PREVIEW_ROTATE_0
    #endif
#elif defined(SENSOR_ON_COVER)
    #if defined(SENSOR_ROTATE_0)
        #define MMI_BCR_PREVIEW_MAINLCD_ROTATE           MMI_BCR_PREVIEW_ROTATE_0
    #elif defined(SENSOR_ROTATE_180)
        #define MMI_BCR_PREVIEW_MAINLCD_ROTATE           MMI_BCR_PREVIEW_ROTATE_180
    #else
        /* rotate 90, 270 not used yet */
        #define MMI_BCR_PREVIEW_MAINLCD_ROTATE           MMI_BCR_PREVIEW_ROTATE_0
    #endif
#elif defined(SENSOR_INSIDE_CLAM)
    #if defined(SENSOR_ROTATE_0)
        #define MMI_BCR_PREVIEW_MAINLCD_ROTATE           MMI_BCR_PREVIEW_ROTATE_180
    #elif defined(SENSOR_ROTATE_180)
        #define MMI_BCR_PREVIEW_MAINLCD_ROTATE           MMI_BCR_PREVIEW_ROTATE_0
    #else
        /* rotate 90, 270 not used yet */
        #define MMI_BCR_PREVIEW_MAINLCD_ROTATE           MMI_BCR_PREVIEW_ROTATE_0
    #endif
#else /* not define SENSOR_LCATION */
    #if defined(SENSOR_ROTATE_0)
        #define MMI_BCR_PREVIEW_MAINLCD_ROTATE           MMI_BCR_PREVIEW_ROTATE_0
    #elif defined(SENSOR_ROTATE_180)
        #define MMI_BCR_PREVIEW_MAINLCD_ROTATE           MMI_BCR_PREVIEW_ROTATE_180
    #else
        /* rotate 90, 270 not used yet */
        #define MMI_BCR_PREVIEW_MAINLCD_ROTATE           MMI_BCR_PREVIEW_ROTATE_0
    #endif				
#endif /* SENSOR_LOCATION */

/****************************************************************************
* Default Setting
*****************************************************************************/
#define MMI_BCR_DEFAULT_SETTING_EV              MMI_BCR_SETTING_EV_0	
#define MMI_BCR_DEFAULT_SETTING_FOCUS_MODE      MMI_BCR_SETTING_FOCUS_MODE_AUTO
#define MMI_BCR_DEFAULT_SETTING_FLASH 	        MMI_BCR_SETTING_FLASH_OFF
#define MMI_BCR_DEFAULT_SETTING_BANDING         MMI_BCR_SETTING_BANDING_50HZ
#ifdef __MMI_BCR_RECOGNIZE_MODE__
#define MMI_BCR_DEFAULT_SETTING_RECOGNIZE_MODE  MMI_BCR_SETTING_RECOGNIZE_MODE_SC
#endif

/****************************************************************************
* Key Map Setting
*****************************************************************************/
#define MMI_BCR_FOCUS_MODE_KEY		    (KEY_1)
#define MMI_BCR_FLASH_KEY				(KEY_2)
#define MMI_BCR_CAPTURE_EXTRA_KEY	    (KEY_IP)
#define MMI_BCR_CAPTURE_KEY			    (KEY_CAMERA)

#endif /* __MMI_BCR__ */
#endif /* _BCR_FEATURES_H_ */
