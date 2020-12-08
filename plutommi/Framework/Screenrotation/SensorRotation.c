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
 *  ScreenRotation.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Sensor framework
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
//#include "MMI_include.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "ScreenRotationGprot.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "mdi_datatype.h" 
//#include "mdi_motion.h"
#include "gpiosrvgprot.h"
#include "Wgui_categories.h"
#ifdef MOTION_SENSOR_SUPPORT
#include "SensorSrvGport.h"
#include "mmi_rp_app_auto_rotate_def.h"
#endif

/* Define */

#if defined(__COSMOS_MMI__)&&defined(__MTK_INTERNAL__)&&defined(__MMI_REDUCED_KEYPAD__)
/* under construction !*/
#endif

#if defined(__MMI_SLIDE__) && defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	#define __MMI_AUTO_ROTATE_SLIDE__
#if defined(__MTK_TARGET__) && defined(__MTK_INTERNAL__)
/* under construction !*/
#endif
#endif

#if defined(HEPHAESTUS68_DEMO_BB) && defined(__FLAVOR_COSMOS_WQVGA__) && defined(__MMI_AUTO_ROTATE_KEY_SENSOR__) && defined(__MTK_TARGET__)
    #define __MMI_AUTO_ROTATE_CAMERA_KEY_SENSOR__
#endif

#if !defined(__MTK_TARGET__) && defined(__COSMOS_MMI__)
#define __MMI_AUTO_ROTATE_MODIS_BUTTON_SENSOR__
#define __MMI_AUTO_ROTATE_SUPPORT_180_DEGREE__
#endif

/* static variable */
static U8 g_sensor_type = 0;
static MMI_BOOL g_auto_rotate = MMI_FALSE;
static mdi_handle g_motion_handle = 0;
static mmi_frm_screen_rotate_enum g_sensor_rotate = MMI_FRM_SCREEN_ROTATE_0;
static mmi_frm_screen_rotate_enum g_sensor_old_rotate = MMI_FRM_SCREEN_ROTATE_0;
static mmi_frm_screen_rotate_enum g_motion_sensor_rotate = MMI_FRM_SCREEN_ROTATE_0;
static mmi_frm_screen_rotate_enum g_ssq_rotate = MMI_FRM_SCREEN_ROTATE_0;
#if defined(__MMI_AUTO_ROTATE_CAMERA_KEY_SENSOR__)
static U8 g_auto_rotate_key_count = 0;
#endif

#ifdef MOTION_SENSOR_SUPPORT
/* static function */
static void mmi_auto_rotate_tilt_callback(
					srv_sensor_type_enum sensor_type,
                    void *sensor_data, 
                    void *user_data);
#endif
static void mmi_auto_rotate_orientation_change(mmi_frm_screen_rotate_enum rotation, mmi_frm_auto_rotate_type_enum type);
static void mmi_auto_rotate_update_screen(void);


#ifdef __MMI_AUTO_ROTATE_MODIS_BUTTON_SENSOR__
static void mmi_auto_rotate_receive_hdlr(void *msgPtr, int mod_src)
{
	mmi_auto_rotate_orientation_change(g_motion_sensor_rotate,MMI_FRM_AUTO_ROTATE_SENSOR);	
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_auto_rotate_listen_motion
 * DESCRIPTION
 *  Register listen title for motion sensor when init application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_frm_auto_rotate_listen_motion(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef MOTION_SENSOR_SUPPORT
    srv_sensor_motion_direct_cfg_struct sensitive;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (MOTION_SENSOR_SUPPORT) && defined(__COSMOS_MMI__)
    if(mmi_get_ui_rotation_state_by_mcube_sensor() == MMI_TRUE)
    {
        sensitive.angle_threshold = 40;
        g_motion_handle = srv_sensor_start_listen(SRV_SENSOR_MOTION_DIRECT, &sensitive, mmi_auto_rotate_tilt_callback, NULL);
    }
#endif
#ifdef __MMI_AUTO_ROTATE_MODIS_BUTTON_SENSOR__
	mmi_frm_set_protocol_event_handler(MSG_ID_MMI_AUTO_ROTATE_CHANGE_IND, (PsIntFuncPtr)mmi_auto_rotate_receive_hdlr, MMI_FALSE);
#endif
#if defined(__MMI_AUTO_ROTATE_SLIDE__) && !defined(__MTK_TARGET__)
	if(!srv_clam_is_close())  /* 1 open */
	{
		g_sensor_rotate = g_ssq_rotate = MMI_FRM_SCREEN_ROTATE_270;
	}
	
#endif
    return MMI_RET_OK;
}

#ifdef MOTION_SENSOR_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_auto_rotate_tilt_callback
 * DESCRIPTION
 *  Register listen title for motion sensor when init application.
 * PARAMETERS
 *  direct  [IN] the direct mdi motion detected.
 *  action  [IN] the action user played.
 *  detail_p    [IN]  pointer to the detail information structure
 *  user_data   [IN]  the data of application pass to MDI motion when call the start.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_auto_rotate_tilt_callback(
					srv_sensor_type_enum sensor_type,
                    void *sensor_data, 
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_screen_rotate_enum rotation;
    srv_sensor_motion_direct_struct *p_direction;
    srv_sensor_motion_direct_enum direct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(sensor_type == SRV_SENSOR_DISABLE)
     {
       		g_motion_sensor_rotate = MMI_FRM_SCREEN_ROTATE_0;
	        mmi_auto_rotate_orientation_change(g_motion_sensor_rotate,MMI_FRM_AUTO_ROTATE_SENSOR); 
	        return;
     }
	p_direction = (srv_sensor_motion_direct_struct *)sensor_data;
	direct = p_direction->direct;
	
	switch (direct)
	{
		case SRV_SENSOR_MOTION_ANGLE_GX0:
		{
			kal_prompt_trace(MOD_MMI, "[AUTO ROTATE]motion_sensor = GX0");
			rotation = MMI_FRM_SCREEN_ROTATE_90;
			break;
		}
		case SRV_SENSOR_MOTION_ANGLE_GX180:
		{
			kal_prompt_trace(MOD_MMI, "[AUTO ROTATE]motion_sensor = GX180");
			rotation = MMI_FRM_SCREEN_ROTATE_270;
			break;
		}
		case SRV_SENSOR_MOTION_ANGLE_GY0:
		{
			kal_prompt_trace(MOD_MMI, "[AUTO ROTATE]motion_sensor = GY0");
			rotation = MMI_FRM_SCREEN_ROTATE_180;
			break;
		}
		case SRV_SENSOR_MOTION_ANGLE_GY180:
		{
			kal_prompt_trace(MOD_MMI, "[AUTO ROTATE]motion_sensor = GY180");
			rotation = MMI_FRM_SCREEN_ROTATE_0;
			break;
		}
		default:
		{
			return;
		}
	}
	if((rotation == MMI_FRM_SCREEN_ROTATE_0) || \
        (rotation == MMI_FRM_SCREEN_ROTATE_270) || \
        (rotation == MMI_FRM_SCREEN_ROTATE_90)
#ifdef __MMI_AUTO_ROTATE_SUPPORT_180_DEGREE__
		|| (rotation == MMI_FRM_SCREEN_ROTATE_180)
#endif
		)
		g_motion_sensor_rotate = rotation;
	mmi_auto_rotate_orientation_change(rotation,MMI_FRM_AUTO_ROTATE_SENSOR);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_auto_rotate_orientation_change
 * DESCRIPTION
 *  Called when orientation changed
 * PARAMETERS
 *  rotation  [IN] new orientation degree.
 *  type       [IN] sensor type
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_auto_rotate_orientation_change(mmi_frm_screen_rotate_enum rotation, mmi_frm_auto_rotate_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_frm_auto_rotate_evt_struct evt;
    mmi_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_sensor_rotate == rotation)
		return;

	if((rotation != MMI_FRM_SCREEN_ROTATE_0) \
        && (rotation != MMI_FRM_SCREEN_ROTATE_270)\
        && (rotation != MMI_FRM_SCREEN_ROTATE_90) 
#ifdef __MMI_AUTO_ROTATE_SUPPORT_180_DEGREE__
		&& (rotation != MMI_FRM_SCREEN_ROTATE_180)
#endif
		)
		return;

	/* Emit the orientation change evt */
	g_sensor_old_rotate = g_sensor_rotate;
	g_sensor_rotate = rotation;

	MMI_FRM_INIT_EVENT(&evt, EVT_ID_ORIENTATION_CHANGED);
	evt.old_degree = g_sensor_old_rotate;
	evt.new_degree = g_sensor_rotate;
	evt.rotation_type = type;
	ret = MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&evt);

	if((type != g_sensor_type) && (g_sensor_type != MMI_FRM_AUTO_ROTATE_DEFAULT))
		return;
    if(ret>0)  // current app handle the updated action
        return;
	/* Do auto update action */
	if(g_auto_rotate == MMI_TRUE)
	{
		mmi_auto_rotate_update_screen();
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_auto_rotate_update_screen
 * DESCRIPTION
 *  Update current screen when screen orientation changed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_auto_rotate_update_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_ID act_group;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	act_group = mmi_frm_group_get_active_id();

	if(act_group == GRP_ID_INVALID)
		act_group = GRP_ID_ROOT;

	if(!mmi_frm_scrn_enter(act_group, SCR_ID_DUMMY, NULL, mmi_auto_rotate_update_screen, MMI_FRM_UNKNOW_SCRN))
		return;
	
	ShowCategoryDummyScreen();
	mmi_frm_scrn_close_active_id();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_auto_rotate_begin
 * DESCRIPTION
 *  Begin auto rotate if sensor device is exists. 
 *  After start auto rotate, it will be 
 *    1.  Auto update current screen when orientaion changed.
 *    2.  Set screen rotation when showcategory.
 * PARAMETERS
 *  rotate_type  [IN] sensor type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_auto_rotate_begin(mmi_frm_auto_rotate_type_enum rotate_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_auto_rotate = MMI_TRUE;
	g_sensor_type = rotate_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_auto_rotate_end
 * DESCRIPTION
 *  Stop auto rotate if sensor device is exists. 
 * PARAMETERS
 *  rotate_type  [IN] sensor type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_auto_rotate_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_auto_rotate = MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_auto_rotate_is_run
 * DESCRIPTION
 *  check if auto rotate is run
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL  [OUT]
 *****************************************************************************/
MMI_BOOL mmi_frm_auto_rotate_is_run()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return g_auto_rotate;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_auto_rotate_get_degree
 * DESCRIPTION
 *  Get current sensor orientation
 * PARAMETERS
 *  rotate_type [IN] sensor type
 * RETURNS
 *  mmi_frm_screen_rotate_enum  [OUT]
 *****************************************************************************/
mmi_frm_screen_rotate_enum  mmi_frm_auto_rotate_get_degree(mmi_frm_auto_rotate_type_enum rotate_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(rotate_type == MMI_FRM_AUTO_ROTATE_DEFAULT)
		return g_sensor_rotate;
	else if(rotate_type == MMI_FRM_AUTO_ROTATE_SSQ)
		return g_ssq_rotate;
	else if(rotate_type == MMI_FRM_AUTO_ROTATE_SENSOR)
		return g_motion_sensor_rotate;
	else
		MMI_ASSERT(0);
    return MMI_FRM_SCREEN_ROTATE_0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_auto_rotate
 * DESCRIPTION
 *  It's called by category and  set right rotate degree.
 *  If auto rotate is run, category will call the function first.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_auto_rotate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_frm_auto_rotate_evt_struct evt;
	mmi_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SCREEN_ROTATE__  

	if(g_auto_rotate == MMI_TRUE)
	{
		MMI_FRM_INIT_EVENT(&evt, EVT_ID_AUTO_ROTATE_QUERY);
		evt.old_degree = g_sensor_old_rotate;
		evt.new_degree = g_sensor_rotate;
		ret = mmi_frm_send_event_to_active_screen((mmi_event_struct*)&evt);
		if(ret == evt.new_degree)
		{
			mmi_frm_screen_rotate(g_sensor_rotate);
		}
		else
		{
			mmi_frm_screen_rotate((mmi_frm_screen_rotate_enum)ret);
		}
	}
#endif
}


MMI_BOOL mmi_auto_rotate_on_modis_handler(U16 key_code)
{
	mmi_frm_screen_rotate_enum rotation = MMI_FRM_SCREEN_ROTATE_MAX_TYPE;

	switch(key_code)
	{
		case KEY_0:
		rotation = MMI_FRM_SCREEN_ROTATE_0;
			break;
		case KEY_1:
			rotation = MMI_FRM_SCREEN_ROTATE_180;
			break;
		case KEY_STAR:
        rotation = MMI_FRM_SCREEN_ROTATE_90;
			break;
		case KEY_POUND:
        rotation = MMI_FRM_SCREEN_ROTATE_270;
			break;
		default:
			break;
	}
	g_motion_sensor_rotate = rotation;

#ifdef __MMI_AUTO_ROTATE_MODIS_BUTTON_SENSOR__
	if(rotation != MMI_FRM_SCREEN_ROTATE_MAX_TYPE)
	{
		mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_AUTO_ROTATE_CHANGE_IND, NULL, NULL);
	}
#endif

	return MMI_TRUE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_auto_rotate_ssq_handler
 * DESCRIPTION
 *  register callback to receive ssq event.
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_ret.
 *****************************************************************************/
mmi_ret mmi_auto_rotate_ssq_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	 switch(evt->evt_id)
	 {
#ifdef __MMI_AUTO_ROTATE_SLIDE__
		  case EVT_ID_GPIO_CLAM_CLOSE:
				g_ssq_rotate = MMI_FRM_SCREEN_ROTATE_0;
				mmi_auto_rotate_orientation_change(MMI_FRM_SCREEN_ROTATE_0, MMI_FRM_AUTO_ROTATE_SSQ);
				break;
		  case EVT_ID_GPIO_CLAM_OPEN:
				g_ssq_rotate = MMI_FRM_SCREEN_ROTATE_270;
			    mmi_auto_rotate_orientation_change(MMI_FRM_SCREEN_ROTATE_270, MMI_FRM_AUTO_ROTATE_SSQ);
				break;
#endif

          case EVT_ID_PRE_KEY_EVT_ROUTING:
                {
                    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;
                    mmi_frm_screen_rotate_enum rotation;
#ifdef __MMI_AUTO_ROTATE_KEY_SENSOR__
#ifdef __MMI_AUTO_ROTATE_CAMERA_KEY_SENSOR__
                    if(key_evt->key_code == KEY_STAR && key_evt->key_type == KEY_EVENT_DOWN)
                    { 
                        if(g_auto_rotate_key_count == 0)
                        {
                            rotation = MMI_FRM_SCREEN_ROTATE_90;
                            g_auto_rotate_key_count ++;
                        }
                        else if(g_auto_rotate_key_count == 1)
                        {
                            rotation = MMI_FRM_SCREEN_ROTATE_270;
                            g_auto_rotate_key_count ++;            
                        }
                        else if (g_auto_rotate_key_count == 2)
                        {   
                             rotation = MMI_FRM_SCREEN_ROTATE_0;
                             g_auto_rotate_key_count = 0;       
                        }
                        else
                        {
                             rotation = MMI_FRM_SCREEN_ROTATE_0;
                             g_auto_rotate_key_count = 0;  
                        }
						g_motion_sensor_rotate = rotation;
						mmi_auto_rotate_orientation_change(rotation,MMI_FRM_AUTO_ROTATE_SENSOR);
                    }
#else  
                    if(key_evt->key_code == KEY_0 && key_evt->key_type== KEY_LONG_PRESS)
                    {
                        rotation = MMI_FRM_SCREEN_ROTATE_0;
						g_motion_sensor_rotate = rotation;
						mmi_auto_rotate_orientation_change(rotation,MMI_FRM_AUTO_ROTATE_SENSOR);
                    }
                    if(key_evt->key_code == KEY_STAR && key_evt->key_type== KEY_LONG_PRESS)
                    {
                        rotation = MMI_FRM_SCREEN_ROTATE_90;
						g_motion_sensor_rotate = rotation;
						mmi_auto_rotate_orientation_change(rotation,MMI_FRM_AUTO_ROTATE_SENSOR);
                    }
                    if(key_evt->key_code == KEY_POUND && key_evt->key_type== KEY_LONG_PRESS)
                    {
                        rotation = MMI_FRM_SCREEN_ROTATE_270;
						g_motion_sensor_rotate = rotation;
						mmi_auto_rotate_orientation_change(rotation,MMI_FRM_AUTO_ROTATE_SENSOR);
                    }
#ifdef __MMI_AUTO_ROTATE_SUPPORT_180_DEGREE__
					if(key_evt->key_code == KEY_1 && key_evt->key_type == KEY_LONG_PRESS)
					{
						rotation = MMI_FRM_SCREEN_ROTATE_180;
						g_motion_sensor_rotate = rotation;
						mmi_auto_rotate_orientation_change(rotation,MMI_FRM_AUTO_ROTATE_SENSOR);
					}
#endif
#endif  /* __MMI_AUTO_ROTATE_CAMERA_KEY_SENSOR__ */
#endif  /* __MMI_AUTO_ROTATE_KEY_SENSOR__ */
#ifdef __MMI_AUTO_ROTATE_SLIDE_VOLUME_KEY__
					if(key_evt->key_code == KEY_VOL_DOWN && key_evt->key_type == KEY_EVENT_DOWN)
					{
						rotation = MMI_FRM_SCREEN_ROTATE_270;
						g_ssq_rotate = rotation;
						mmi_auto_rotate_orientation_change(rotation,MMI_FRM_AUTO_ROTATE_SSQ);
					}
					if(key_evt->key_code == KEY_VOL_UP && key_evt->key_type == KEY_EVENT_DOWN)
					{
						rotation = MMI_FRM_SCREEN_ROTATE_0;
						g_ssq_rotate = rotation;
						mmi_auto_rotate_orientation_change(rotation,MMI_FRM_AUTO_ROTATE_SSQ);
					}
#endif
					break;
                }

		  default:
				break;
	 }
	 return MMI_RET_OK;
}

#if defined (MOTION_SENSOR_SUPPORT) && defined(__COSMOS_MMI__)
MMI_BOOL mmi_get_ui_rotation_state_by_mcube_sensor(void)
{
    U8 buf;
    S16 err;
    
    ReadValue(NVRAM_EF_SENSOR_UI_ROTATION_SWITCH, &buf, DS_BYTE, &err);
    
    if(buf == 0x00)
        return MMI_FALSE;
    else
        return MMI_TRUE;
    
}

void mmi_set_ui_rotation_state_by_mcube_sensor(MMI_BOOL is_on)
{

    srv_sensor_motion_direct_cfg_struct sensitive;
    S16 error;
    U8 mode;
    
    if(is_on)
    {
        mode = 1;

        sensitive.angle_threshold = 40;
        g_motion_handle = srv_sensor_start_listen(SRV_SENSOR_MOTION_DIRECT, &sensitive, mmi_auto_rotate_tilt_callback, NULL);
        WriteValue(NVRAM_EF_SENSOR_UI_ROTATION_SWITCH, &mode, DS_BYTE, &error);
    }
    else
    {
        mode = 0;
        
        srv_sensor_stop_listen(g_motion_handle);
        g_motion_handle = 0;
		g_motion_sensor_rotate = MMI_FRM_SCREEN_ROTATE_0;  // reset ui rotaion to 0 degree.
	    mmi_auto_rotate_orientation_change(MMI_FRM_SCREEN_ROTATE_0,MMI_FRM_AUTO_ROTATE_SENSOR);
	    WriteValue(NVRAM_EF_SENSOR_UI_ROTATION_SWITCH, &mode, DS_BYTE, &error);
	    
    }

}
#endif
