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
 *  gpiosrv.res
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Resource file.
 *
 * Author:
 * -------
 *  Fachao Zhang (MTK80513)
 *
 *                      
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 04 24 2012 feng.yang
 * [MAUI_03174161] [Sensor serive]Add direct debounce
 * .
 *
 * 02 22 2012 feng.yang
 * [MAUI_03135149] [Sensor service]mCube motion sensor porting support
 * .
 *
 * 05 24 2011 feng.yang
 * [MAUI_02948467] Add compile option for PXS sensor res
 * .
 *
 * 03 28 2011 gilbert.wang
 * [MAUI_02740536] [Proximity] MMI PXS Service Check in
 * Check in additional events.
 *
 * 03 13 2011 gilbert.wang
 * [MAUI_02740536] [Proximity] MMI PXS Service Check in
 * check in PXS service.
 *
 * 01 11 2011 fachao.zhang
 * [MAUI_02647653] [Santiy Test fail] For pluto project NVRAM_BYTE_BL_SETTING_HFTIME byte-short
 * .
 *
 * 12 25 2010 fachao.zhang
 * [MAUI_02645344] [FTO] Device code check in
 * .
 *
 * 12 17 2010 yenhung.chen
 * [MAUI_02844420] [NVRAM] Country Adaptation Tool Checkin
 * .
 *
 * 11 18 2010 fachao.zhang
 * [MAUI_02641036] [NVRAM Cache Migrate] from /nvram_mgr.res to APP.res
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 

#include "mmi_features.h"
#include "CustResDef.h"
#include "custom_mmi_default_value.h"


<?xml version = "1.0" encoding = "UTF-8"?>


<APP id = "SRV_SENSOR">


<!----------------- XML Begin ------------------------------------------------->

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    
#ifdef __PXS_ENABLE__

    <TIMER id="SRV_PXS_TIMER_ID"/>
    
	<SENDER id="EVT_ID_SENSOR_PXS_TURN_ON_NOTIFY" hfile="SensorSrvGport.h"/>
	<SENDER id="EVT_ID_SENSOR_PXS_TURN_OFF_NOTIFY" hfile="SensorSrvGport.h"/>
	<SENDER id="EVT_ID_SENSOR_PXS_DETECT_OBJ_CLOSE" hfile="SensorSrvGport.h"/>
	<SENDER id="EVT_ID_SENSOR_PXS_DETECT_OBJ_AWAY" hfile="SensorSrvGport.h"/>
	
#endif /*__PXS_ENABLE__*/


#ifdef MOTION_SENSOR_SUPPORT
	<SENDER id="EVT_ID_SENSOR_MOTION_CALI_FINISHED" hfile="SensorSrvGport.h"/>
	<SENDER id="EVT_ID_SENSOR_MOTION_CALI_TIMEOUT" hfile="SensorSrvGport.h"/>
	<SENDER id="EVT_ID_SENSOR_MOTION_CALI_WRITE_FAIL" hfile="SensorSrvGport.h"/>


	<TIMER id="SRV_MOTION_DIRECT_TIMER_ID"/>



#endif /*MOTION_SENSOR_SUPPORT*/


<!----------------- XML END --------------------------------------------------->

</APP>






  
