/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_mav_motion_translator.h
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
 ****************************************************************************/

#ifndef __VAPP_MAV_MOTION_TRANSLATOR_H__
#define __VAPP_MAV_MOTION_TRANSLATOR_H__

#include "MMI_features.h" 
#if defined(MOTION_SENSOR_SUPPORT) || defined(__CAMERA_GYRO_SUPPORT__)
#define __VAPP_MAV_MOTION_TRANSLATOR_SUPPORT__
#endif

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_page_panel.h"

extern "C"
{
#include "fs_func.h"
#include "SensorSrvGport.h"
#include "CameraGyroSrvGport.h"
}

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
// working memory for camera motion sensor should be
// non-cache, continous, and switchable
#if !defined(MOTION_SENSOR_SUPPORT) && defined(__CAMERA_GYRO_SUPPORT__)
#define __VAPP_MAV_MOTION_TRANSLATOR_CAMERA_SENSOR_SUPPORT__
#define VAPP_MAV_MOTION_TRANSLATOR_WORKING_MEM (CAMERA_GYRO_SENSOR_EXT_MEM)
#else
#undef __VAPP_MAV_MOTION_TRANSLATOR_CAMERA_SENSOR_SUPPORT__
#define _VAPP_MAV_MOTION_TRANSLATOR_WORKING_MEM (0)
#endif

#ifdef __VAPP_MAV_MOTION_TRANSLATOR_SUPPORT__

/*****************************************************************************
 * Class Implementation
 *****************************************************************************/
enum VappGalleryMotionType
{
    GM_DIRECT,
    GM_SHAKE, 
    GM_TILT, 
    GM_END_OF_TYPE
};

class VappMavMotionTranslator : public VfxObject
{
public:
    VappMavMotionTranslator();
    VappMavMotionTranslator(VfxBool enableCameraSensor, const mmi_id m_appId);
    
protected:
    void onInit();
    void onDeinit();

public:
    VfxBool startListen(const VappGalleryMotionType type, void* userData);
    VfxBool stopListen(const VappGalleryMotionType type);

public:     
    VfxSignal1<VfxFloat> m_sigSensorEvent;
    
private:
    static void onMotion(srv_sensor_type_enum sensor_type, void *sensor_data, void *user_data);
    void handleDirect(void *sensor_data);
    void handleShake(void *sensor_data);
    void handleTilt(void *sensor_data);
    void notifySensorResult(const VfxFloat offset);
    VfxBool checkAndFixHandle(SRV_SENSOR_HANDLE handle);

private:    
    SRV_SENSOR_HANDLE m_hShake;
    SRV_SENSOR_HANDLE m_hTilt;
    SRV_SENSOR_HANDLE m_hDirect;

    srv_sensor_motion_shake_cfg_struct m_paramShake;
    srv_sensor_motion_direct_cfg_struct m_paramDirect;

    VfxBool m_enableCameraSensor;
    mmi_id m_appId;
    U32* m_workingMem;

    VfxS32 m_preTiltAcc;
    VfxS32 m_tiltDAccHistory[3];
};
#endif
#endif /* __VAPP_GALLERY_VIEWER_H__ */

