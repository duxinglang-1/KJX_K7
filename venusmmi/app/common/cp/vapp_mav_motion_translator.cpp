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
 *  vapp_mav_motion_translator.cpp
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

#include "MMI_features.h"
#include "vapp_mav_motion_translator.h"

#ifdef __VAPP_MAV_MOTION_TRANSLATOR_SUPPORT__

/*****************************************************************************
 * Inplementation
 *****************************************************************************/
VappMavMotionTranslator:: VappMavMotionTranslator()
    :m_hShake(SRV_SENSOR_MOTION_NO_SLOT)
    ,m_hTilt(SRV_SENSOR_MOTION_NO_SLOT)
    ,m_hDirect(SRV_SENSOR_MOTION_NO_SLOT)
    ,m_enableCameraSensor(VFX_FALSE)
    ,m_appId(-1)
    ,m_workingMem(NULL)
    ,m_preTiltAcc(0)
{
}

VappMavMotionTranslator::VappMavMotionTranslator(VfxBool enableCameraSensor, const mmi_id m_appId)
    :m_hShake(SRV_SENSOR_MOTION_NO_SLOT)
    ,m_hTilt(SRV_SENSOR_MOTION_NO_SLOT)
    ,m_hDirect(SRV_SENSOR_MOTION_NO_SLOT)
    ,m_enableCameraSensor(enableCameraSensor)
    ,m_appId(m_appId)
    ,m_workingMem(NULL)
    ,m_preTiltAcc(0)
{
}

void VappMavMotionTranslator::onInit()
{
    VfxObject::onInit();

    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[MavMotionTranslator] onInit, appId[%d], enableCameraSensor[%d]", m_appId, m_enableCameraSensor);

    m_tiltDAccHistory[0] = 0;
    m_tiltDAccHistory[1] = 0;
    m_tiltDAccHistory[2] = 0;

    // allocate mem in camera motion sensor case
#ifdef __VAPP_MAV_MOTION_TRANSLATOR_CAMERA_SENSOR_SUPPORT__
    if(m_enableCameraSensor)
    {
        VFX_ASSERT(m_appId > 0);
        m_workingMem = (U32*)applib_asm_alloc_nc_r(m_appId, VAPP_MAV_MOTION_TRANSLATOR_WORKING_MEM);
        VFX_ASSERT(m_workingMem);
        
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[MavMotionTranslator] onInit_, allocate woring mem, size[%d], ptr[%x]", VAPP_MAV_MOTION_TRANSLATOR_WORKING_MEM, m_workingMem);
    }
#endif
}

void VappMavMotionTranslator::onDeinit()
{
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[MavMotionTranslator] onDeinit");
    // release mem in camera motion sensor case
#ifdef __VAPP_MAV_MOTION_TRANSLATOR_CAMERA_SENSOR_SUPPORT__
    if(m_enableCameraSensor && m_workingMem)
    {
        applib_asm_free_r(m_appId, m_workingMem);
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[MavMotionTranslator] onDeinit, destory woring mem, ptr[%x]", m_workingMem);
        m_workingMem = NULL;
    }
#endif
    VfxObject::onDeinit();
}

VfxBool VappMavMotionTranslator::startListen(const VappGalleryMotionType type, void* userData)
{
#ifdef __VAPP_MAV_MOTION_TRANSLATOR_CAMERA_SENSOR_SUPPORT__
    do
    {
        if(!m_enableCameraSensor)
            return VFX_FALSE; 
        if(NULL == m_workingMem)
            return VFX_FALSE;

        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[MavMotionTranslator] set working mem, add[%x], size[%d]",
            m_workingMem, VAPP_MAV_MOTION_TRANSLATOR_WORKING_MEM);
        const U32 start_addr = (VfxU32)m_workingMem;
        srv_sensor_set_ext_mem(start_addr, VAPP_MAV_MOTION_TRANSLATOR_WORKING_MEM);
    }while(0);
#endif

    VfxBool alreadyExist = VFX_FALSE; 
    switch(type)
    {    
    case GM_DIRECT:
        alreadyExist = (SRV_SENSOR_MOTION_NO_SLOT == m_hDirect)? VFX_FALSE : VFX_TRUE; 
        break;
    case GM_SHAKE:
        alreadyExist = (SRV_SENSOR_MOTION_NO_SLOT == m_hShake)? VFX_FALSE : VFX_TRUE; 
        break;
    case GM_TILT:
        alreadyExist = (SRV_SENSOR_MOTION_NO_SLOT == m_hTilt)? VFX_FALSE : VFX_TRUE; 
        break;        
    default: 
        break;
    }

    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, 
        "[Gallery][GSensor] startListen[%d], alreadyExist = %d", type, alreadyExist);
    if(alreadyExist)
    {
        return VFX_FALSE; 
    }
    
    switch(type)
    {    
    case GM_DIRECT:
        srv_sensor_motion_direct_cfg_struct sensitive;
        sensitive.angle_threshold = 15;
        m_hDirect = srv_sensor_start_listen(SRV_SENSOR_MOTION_DIRECT, 
                                            &sensitive,
                                            &VappMavMotionTranslator::onMotion, 
                                            getObjHandle());
        
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[Gallery][GSensor]startListen[%d], handle[%d]", type, m_hDirect);
        break;
    case GM_SHAKE:
        m_paramShake.sensitive = SRV_SENSOR_MOTION_SHAKE_STRONG;
        m_hShake = srv_sensor_start_listen(SRV_SENSOR_MOTION_SHAKE, 
                                           &m_paramShake,
                                           &VappMavMotionTranslator::onMotion, 
                                           getObjHandle());
        
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[Gallery][GSensor]startListen[%d], handle[%d]", type, m_hShake);
        break;
    case GM_TILT:        
        m_hTilt = srv_sensor_start_listen(SRV_SENSOR_MOTION_TILT, 
                                          NULL,
                                          &VappMavMotionTranslator::onMotion, 
                                          getObjHandle());
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[Gallery][GSensor]startListen[%d], handle[%d]", type, m_hTilt);

        // reset tilt info
        m_preTiltAcc = 0;
        m_tiltDAccHistory[0] = 0;
        m_tiltDAccHistory[1] = 0;
        m_tiltDAccHistory[2] = 0;
        break;        
    default: 
        return VFX_FALSE; 
    }
    
    return VFX_TRUE;
}

VfxBool VappMavMotionTranslator::stopListen(const VappGalleryMotionType type)
{
#ifdef __VAPP_MAV_MOTION_TRANSLATOR_CAMERA_SENSOR_SUPPORT__
    do
    {
        if(!m_enableCameraSensor)
            return VFX_FALSE; 
        if(NULL == m_workingMem)
            return VFX_FALSE; 
    }while(0);
#endif

    // get handle
    SRV_SENSOR_HANDLE *handle = NULL; 
    do
    {
        switch(type)
        {
        case GM_DIRECT:
            handle = &m_hDirect;
            break; 
        case GM_SHAKE:
            handle = &m_hShake;
            break;
        case GM_TILT:
            handle = &m_hTilt;
            break;
        default: 
            break;
        }   
        if(NULL == handle){return VFX_FALSE;}
    }while(0);

    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_1, "stopListen[%d], handle[%d][%d][%d]", type, m_hDirect, m_hShake, m_hTilt);
    // stop handle
    if(0 < (*handle))
    {
        srv_sensor_stop_listen((*handle));
    }    
    (*handle) = SRV_SENSOR_MOTION_NO_SLOT;
    return VFX_TRUE;
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "stopListen[%d]_2, handle[%d][%d][%d]", type, m_hDirect, m_hShake, m_hTilt);
}

void VappMavMotionTranslator::onMotion(srv_sensor_type_enum sensor_type, void *sensor_data, void *user_data)
{
    VappMavMotionTranslator *pThis = (VappMavMotionTranslator*)handleToObject((VfxObjHandle)(user_data));
    if(NULL == pThis)
    {
        return;
    }
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "onMotion[%d]", sensor_type);
    
    switch(sensor_type)
    {
    case SRV_SENSOR_MOTION_DIRECT:
        return pThis->handleDirect(sensor_data);
    case SRV_SENSOR_MOTION_SHAKE:
        return pThis->handleShake(sensor_data);
    case SRV_SENSOR_MOTION_TILT:
        return pThis->handleTilt(sensor_data); 
    default:
        return; 
    }
}

void VappMavMotionTranslator::handleDirect(void *sensor_data)
{
    srv_sensor_motion_direct_struct *pDirect = (srv_sensor_motion_direct_struct *)sensor_data;
    srv_sensor_motion_direct_enum direction = pDirect->direct; 
    srv_sensor_motion_action_enum action = pDirect->action;
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2,"[Gallery][GSensor] handleDirect, action[%d], direction[%d]", action, direction);

    switch(action)
    {
        case SRV_SENSOR_MOTION_ACTION_YAW_RIGHT:   
        case SRV_SENSOR_MOTION_ACTION_ROLL_RIGHT:
        case SRV_SENSOR_MOTION_ACTION_PITCH_BACKWARD:
            notifySensorResult(1);
            return;
        case SRV_SENSOR_MOTION_ACTION_ROLL_LEFT:
        case SRV_SENSOR_MOTION_ACTION_PITCH_FORWARD:
        case SRV_SENSOR_MOTION_ACTION_YAW_LEFT:
            notifySensorResult(-1);
            return;
        default:
            return;
    }    
}

void VappMavMotionTranslator::handleShake(void *sensor_data)
{
    srv_sensor_motion_shake_struct *pShake = (srv_sensor_motion_shake_struct *)sensor_data;
    switch (pShake->action)
    {
    case SRV_SENSOR_MOTION_SHAKING:
        notifySensorResult(1);
        break;
    case SRV_SENSOR_MOTION_SHAKE_NULL:
        notifySensorResult(0);
        break;
    default: 
        break; 
    }
}

static VfxS32 g_threshold = 5;
void VappMavMotionTranslator::handleTilt(void *sensor_data)
{
    srv_sensor_motion_tilt_struct *pTilt = (srv_sensor_motion_tilt_struct *)sensor_data;

    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][GSensor] handleTilt, acc[%d][%d][%d], g[%d][%d][%d]", pTilt->acc.x, pTilt->acc.y, pTilt->acc.z, pTilt->angle.gx, pTilt->angle.gy, pTilt->angle.gz);

    VfxS32 acc = 0;
    VfxFloat nAcc = 0.f;
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    const VfxScrRotateTypeEnum screenRotation = renderer->getScreenRotateType();
    switch(screenRotation)
    {
    case VFX_SCR_ROTATE_TYPE_90:
    case VFX_SCR_ROTATE_TYPE_270:
        acc = (pTilt->acc.y);
        break;
    case VFX_SCR_ROTATE_TYPE_0:
    case VFX_SCR_ROTATE_TYPE_180:
        acc = (pTilt->acc.x);                
        break;
    default:
        break;
    }

#ifdef __VAPP_MAV_MOTION_TRANSLATOR_CAMERA_SENSOR_SUPPORT__

    const VfxS32 dAcc     = acc - m_preTiltAcc;
    const VfxS32 dAcc_abs = VFX_ABS(acc - m_preTiltAcc);

    VfxS32 error = 0;
    do
    {
        if(g_threshold >= dAcc_abs)
        {
            error = -100;
            break;
        }
        if(0 > m_tiltDAccHistory[0] * dAcc)
        {
            error = -200;
            break;
        }
        if(0 > m_tiltDAccHistory[1] * dAcc)
        {
            error = -300;
            break;
        }

        if(0 > m_tiltDAccHistory[2] * dAcc)
        {
            error = -400;
            break;
        }

        nAcc = (0 < dAcc) ? -1.f : 1.f;
    }while(0);

    // update dacc history
    m_tiltDAccHistory[2] = m_tiltDAccHistory[1];
    m_tiltDAccHistory[1] = m_tiltDAccHistory[0];
    m_tiltDAccHistory[0] = dAcc;

    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, 
        "[Gallery][GSensor] handleTilt__1, err[%d], dAcc history[%d], [%d], [%d]", 
         error, m_tiltDAccHistory[0],  m_tiltDAccHistory[1],  m_tiltDAccHistory[2]);

   
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, 
        "[Gallery][GSensor] handleTilt__2, dAcc_abs[%d], dAcc[%d], acc[%d], m_preTiltAcc[%d]", 
        dAcc_abs, dAcc, acc, m_preTiltAcc);
    
    m_preTiltAcc = acc;    
#else
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][GSensor] handleTilt__ERR!!");
    nAcc = - ((VfxFloat)(acc / 100)) /10.f ;
#endif

    notifySensorResult(nAcc); 
    return;
}

void VappMavMotionTranslator::notifySensorResult(const VfxFloat offset)
{
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Gallery][GSensor] notifySensorResult[%d]", (VfxS32)(offset * 10000));
    m_sigSensorEvent.emit(offset);
}

VfxBool VappMavMotionTranslator::checkAndFixHandle(SRV_SENSOR_HANDLE handle)
{
    if(0 < handle)
    {
        return VFX_TRUE; 
    }
    else if(0 == handle)
    {
        handle = SRV_SENSOR_MOTION_NO_SLOT;
        return VFX_FALSE; 
    }

    return VFX_FALSE; 
}
#endif

