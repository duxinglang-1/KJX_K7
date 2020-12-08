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
 *	 mmi_features_barcodereader.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  QR Code Reader Applications v0.1
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef MMI_BARCODEREADER_FEATURES_H
#define MMI_BARCODEREADER_FEATURES_H

#include "MMI_features.h"

#ifdef __MMI_BARCODEREADER__

    #if defined (BARCODE_DECODER_MMI_ONLY) && defined(__MMI_OP01_BARCODEREADER__)
/* under construction !*/
    #endif
    
    #if !defined(__MMI_OP11_BARCODEREADER__) && !defined(__MMI_OP01_BARCODEREADER__)
        #define __MMI_OP00_BARCODEREADER__
        #endif
        
	#ifdef HORIZONTAL_CAMERA
		#define __MMI_HORIZONTAL_BARCODEREADER__
    #endif

    #ifdef __CAMERA_FEATURE_ZOOM__
        //#define __MMI_BARCODEREADER_ZOOM__
    #endif

    //#define __MMI_BARCODEREADER_MF_SUPPORT__
    #define __MMI_BARCODEREADER_EV_SUPPORT__

	#ifdef __MMI_HORIZONTAL_BARCODEREADER__
		#define MMI_BARCODEREADER_LCM_MAINLCD_ROTATE MMI_BARCODEREADER_LCM_ROTATE_270
	#else
		#define MMI_BARCODEREADER_LCM_MAINLCD_ROTATE MMI_BARCODEREADER_LCM_ROTATE_0
	#endif

	
	#if defined(SENSOR_ON_BODY)
        #if defined(SENSOR_ROTATE_0)
            #define MMI_BARCODEREADER_PREVIEW_MAINLCD_ROTATE           MMI_BARCODEREADER_PREVIEW_ROTATE_0
        #elif defined(SENSOR_ROTATE_180)
            #define MMI_BARCODEREADER_PREVIEW_MAINLCD_ROTATE           MMI_BARCODEREADER_PREVIEW_ROTATE_180
        #else
            /* rotate 90, 270 not used yet */
	#define MMI_BARCODEREADER_PREVIEW_MAINLCD_ROTATE MMI_BARCODEREADER_PREVIEW_ROTATE_0
        #endif
    #elif defined(SENSOR_ON_COVER)
        #if defined(SENSOR_ROTATE_0)
            #define MMI_BARCODEREADER_PREVIEW_MAINLCD_ROTATE           MMI_BARCODEREADER_PREVIEW_ROTATE_0
        #elif defined(SENSOR_ROTATE_180)
            #define MMI_BARCODEREADER_PREVIEW_MAINLCD_ROTATE           MMI_BARCODEREADER_PREVIEW_ROTATE_180
        #else
            /* rotate 90, 270 not used yet */
            #define MMI_BARCODEREADER_PREVIEW_MAINLCD_ROTATE           MMI_BARCODEREADER_PREVIEW_ROTATE_0
        #endif
    #else /* not define SENSOR_LCATION */
        #if defined(SENSOR_ROTATE_0)
            #define MMI_BARCODEREADER_PREVIEW_MAINLCD_ROTATE           MMI_BARCODEREADER_PREVIEW_ROTATE_0
        #elif defined(SENSOR_ROTATE_180)
            #define MMI_BARCODEREADER_PREVIEW_MAINLCD_ROTATE           MMI_BARCODEREADER_PREVIEW_ROTATE_180
        #else
            /* rotate 90, 270 not used yet */
            #define MMI_BARCODEREADER_PREVIEW_MAINLCD_ROTATE           MMI_BARCODEREADER_PREVIEW_ROTATE_0
        #endif				
    #endif /* SENSOR_LOCATION */

	
	/****************************************************************************
    * Watch dog open or not 
    *****************************************************************************/
    #define __MMI_BARCODEREADER_WATCHDOG_TIMEOUT__

    #ifdef __MMI_BARCODEREADER_WATCHDOG_TIMEOUT__
        #define MMI_BARCODEREADER_WATCHDOG_TIMEOUT_DUR_MAX       (120000)
        #define MMI_BARCODEREADER_WATCHDOG_TIMEOUT_DUR_INTERVAL   (20000)
    #endif
	
	/****************************************************************************
	* Device Feature Customization 
	*****************************************************************************/

	#ifdef __MMI_TOUCH_SCREEN__
		#define __MMI_BARCODEREADER_TOUCH_SCREEN_SUPPORT__
	#endif 

	#ifdef AF_SUPPORT
		#define __MMI_BARCODEREADER_AF_SUPPORT__
	#endif

	/****************************************************************************
	* Camera Feature Customization 
	*****************************************************************************/
	#define __MMI_BARCODEREADER_EV_2__
	#define __MMI_BARCODEREADER_EV_3__
	#define __MMI_BARCODEREADER_EV_4__


	#ifdef __MMI_BARCODEREADER_AF_SUPPORT__
		#define __MMI_BARCODEREADER_FOCUS_MODE__ /* auto is default */
	
		#define __MMI_BARCODEREADER_FOCUS_MODE_MACRO__
        #ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
		    //#define __MMI_BARCODEREADER_FOCUS_MODE_MANUAL__
        #endif
        #endif 

    #if defined(LED_ONOFF_SUPPORT) || defined(LED_FLASHLIGHT_SUPPORT)
	#define __MMI_BARCODEREADER_FLASH__	
    #endif
    
	#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__))
    	#define __MMI_BARCODEREADER_STORAGE__
    #endif
    #define __MMI_BARCODEREADER_BANDING__
	/****************************************************************************
	* Default Setting
	*****************************************************************************/
	#define MMI_BARCODEREADER_DEFAULT_SETTING_EV MMI_BARCODEREADER_SETTING_EV_0	
	#define MMI_BARCODEREADER_DEFAULT_SETTING_FOCUS_MODE MMI_BARCODEREADER_SETTING_FOCUS_MODE_AUTO
	#define MMI_BARCODEREADER_DEFAULT_SETTING_FLASH 	MMI_BARCODEREADER_SETTING_FLASH_OFF
    #define MMI_BARCODEREADER_DEFAULT_SETTING_BANDING   MMI_BARCODEREADER_SETTING_BANDING_50HZ


	/****************************************************************************
	* Key Map Setting
	*****************************************************************************/
	#define MMI_BARCODEREADER_FOCUS_MODE_KEY		(KEY_1)
	#define MMI_BARCODEREADER_FLASH_KEY				(KEY_2)
    #ifdef __MMI_OP11_BARCODEREADER__
/* under construction !*/
    #else
	#define MMI_BARCODEREADER_STORAGE_KEY			(KEY_3)
    #endif
	#define MMI_BARCODEREADER_CAPTURE_EXTRA_KEY	    (KEY_IP)
	#define MMI_BARCODEREADER_CAPTURE_KEY			(KEY_CAMERA)


#endif /* __MMI_MMI_BARCODEREADER__ */
#endif /* _MMI_BARCODEREADER_FEATRUES_H_ */
