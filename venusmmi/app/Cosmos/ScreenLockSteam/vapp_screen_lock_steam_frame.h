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
 *  vapp_steam_screen_lock_frame.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_SCREEN_LOCK_STEAM_FRAME_H__
#define __VAPP_SCREEN_LOCK_STEAM_FRAME_H__

#ifdef __COSMOS_3D_SCREEN_LOCK__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#ifdef MOTION_SENSOR_SUPPORT
// for motion sensor
#include "SensorSrvGport.h"
#endif

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/
// start to fog after do not receive pen or key event
#define VAPP_STEAM_SCREEN_LOCK_FRAME_FOG_UP_TIMER_TIME    5000


class VappSteamScreenLockOwenerDraw;

#ifdef MOTION_SENSOR_SUPPORT
/* context */
typedef struct motion_sensor_para
{
    SRV_SENSOR_HANDLE m_motion_shake_handle;
    SRV_SENSOR_HANDLE m_motion_tilt_handle;
};
#endif


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappSteamScreenLockFrame : public VfxControl
{
    VFX_DECLARE_CLASS(VappSteamScreenLockFrame);

// Default Constructor
public:
    VappSteamScreenLockFrame();

    
private:
    
    VfxSize getScreenSize();

    void notifyUnlock();

// Method
public:
    void startFogUpTimer();
    void stopFogUp();
    void stopFogUpNoBacklight();
    void resetOwnerDraw();
    void addWaterDrop(VfxPoint pos);

private:
    static vrt_render_dirty_type_enum frameEffectCallBack(
                   vrt_frame_visual_property_struct *target_frame,
                   const vrt_frame_visual_property_struct *watch_frame,
                   void *user_data,
                   vrt_u32 user_data_size);

#ifdef MOTION_SENSOR_SUPPORT
    /*****************************************************************************
     * FUNCTION
     *  onMotionShakeCallback
     * DESCRIPTION
     *  the callback of shake detection
     * PARAMETERS
     *  param       shake direction
     * RETURNS
     *  void
     *****************************************************************************/
    static void onMotionShakeCallback(
                    srv_sensor_type_enum sensor_type, 
                    void *sensor_data, 
                    void *user_data);

    /*****************************************************************************
     * FUNCTION
     *  onMotionTiltDetailCallback
     * DESCRIPTION
     *  the callback function of the tilt detail
     * PARAMETERS
     *  direct      direction of the phone
     *  action      the action of user
     *  *detail_p   pointer of the detail info
     * RETURNS
     *  void
     *****************************************************************************/
    static void onMotionTiltDetailCallback(
            srv_sensor_type_enum sensor_type, void *sensor_data, void *user_data);
#endif

    void onStartFogTimerCallback(VfxTimer *obj);
    static mmi_ret eventHandler(mmi_event_struct *event);

// Override
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxBool onPenInput(VfxPenEvent &event);

// Variable
private:
    VappSteamScreenLockOwenerDraw *m_ownerDraw;
    VfxS32      m_lastDropletTimestamp;
    VfxTimer    *m_timerStartFog;
    VfxS32      m_movingArea;
    VfxPoint    m_lastDropletPos;
    
#ifdef MOTION_SENSOR_SUPPORT
    motion_sensor_para m_motionSensorPara;
#endif
};
#endif /* __COSMOS_3D_SCREEN_LOCK__*/
#endif /* __VAPP_SCREEN_LOCK_STEAM_FRAME_H__ */
