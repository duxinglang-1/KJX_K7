/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   vapp_vol_dialog.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Volume Dialog main file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif
#include "MMI_features.h"
#include "ProfilesSrv.h" 
#include "mdi_audio.h"
#include "mmi_rp_vapp_vol_dialog_def.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#ifdef __MMI_THEMES_APPLICATION__
#include "mmi_rp_vapp_theme_def.h"
#endif
#include "Gpiosrvgprot.h"
#include "mmi_rp_vapp_sound_settings_def.h"
#include "mmi_rp_srv_prof_def.h"
#include "mmi_rp_srv_venus_component_popup_def.h"
#include "Wgui_categories_util.h"
#include "BootupSrvGProt.h"
#include "MMI_media_app_trc.h"
#ifdef __cplusplus
}
#endif

#include "vapp_vol_dialog.h"
#include "vapp_sound_settings_gprot.h"
#include "vapp_screen_lock_gprot.h"
#include "vfx_context.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
const VfxU32 g_memSize = 6 * 1024;
static VfxU8 buffer[g_memSize];
static VfxContext *g_context = NULL;

/***************************************************************************** 
 * Function
 *****************************************************************************/


#ifdef __cplusplus
extern "C"
{
#endif

MMI_BOOL g_vapp_volume_dialog_is_blocked = MMI_FALSE;
MMI_BOOL g_vapp_volume_dialog_is_previewing = MMI_FALSE;


#ifdef __BT_SPK_VOL_CONTROL__
MMI_BOOL vapp_volume_dialog_hfp_sync_callback(U8 volume, MMI_BOOL is_mute)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_VOL_DIALOG_HFP_SYNC_CALLBACK, g_vapp_volume_dialog_is_blocked);

    if(!g_vapp_volume_dialog_is_blocked)
    {
        VappVolumeDialog * volDialog = VFX_OBJ_GET_INSTANCE(VappVolumeDialog);
        volDialog->onVolHfp((VfxU8)volume);
        return MMI_TRUE;
    }

    return MMI_FALSE;
}
#endif

static void vapp_volume_dialog_play_audio_callback(mdi_result result, void *user_data)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_VOL_DIALOG_PLAY_AUDIO_CALLBACK, result);

	g_vapp_volume_dialog_is_previewing = MMI_FALSE;
}

mmi_ret vapp_volume_dialog_init(mmi_event_struct *evt)
{
    VappVolumeDialog * volDialog = VFX_OBJ_GET_INSTANCE(VappVolumeDialog);
    return MMI_RET_OK;
}

mmi_ret vapp_volume_dialog_vol(mmi_frm_key_evt_struct *key_evt)
{
    // not volume keys
    if((key_evt->key_code != KEY_VOL_DOWN && key_evt->key_code != KEY_VOL_UP) || !srv_bootup_is_completed() || g_vapp_volume_dialog_is_blocked)
    {
		MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_VOLUME_DIALOG_VOL, g_vapp_volume_dialog_is_blocked);
        return MMI_RET_OK;
    }

    VappVolumeDialog * volDialog = VFX_OBJ_GET_INSTANCE(VappVolumeDialog);

    volDialog->onVolKey((mmi_keypads_enum)key_evt->key_code, (mmi_key_types_enum)key_evt->key_type);
    
    return MMI_RET_KEY_HANDLED;
}

void vapp_volume_dialog_disappear(void)
{
    VappVolumeDialog * volDialog = VFX_OBJ_GET_INSTANCE(VappVolumeDialog);
    volDialog->forceDisappear();
}

void vapp_volume_dialog_block(MMI_BOOL block)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_VOLUME_DIALOG_BLOCK, block);

    if(block)
    {
        VappVolumeDialog * volDialog = VFX_OBJ_GET_INSTANCE(VappVolumeDialog);
        volDialog->forceDisappear();
    }

    g_vapp_volume_dialog_is_blocked = block;
}

#ifdef __MMI_THEMES_APPLICATION__
mmi_ret vapp_volume_dialog_theme_change(mmi_event_struct *evt)
{
	VFX_OBJ_CLOSE_INSTANCE(VappVolumeDialog);

	return MMI_RET_OK;
}
#endif

MMI_BOOL vapp_volume_dialog_is_media_type(void)
{
    VappVolumeDialog * volDialog = VFX_OBJ_GET_INSTANCE(VappVolumeDialog);
    VappVolumeDialog::VappVolumeDialogStateEnum state = volDialog->queryState();

    if(state == VappVolumeDialog::STATE_MEDIA || state == VappVolumeDialog::STATE_MEDIA_FM || state == VappVolumeDialog::STATE_MEDIA_ATV)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}

#ifdef __cplusplus
}
#endif

/////////////////////////////////////////////////////////////////////////////////

VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappVolumeDialog);

VappVolumeDialog::VappVolumeDialog():
    m_state(STATE_IDLE),
    m_icon(NULL),
    m_title(NULL),
    m_slider(NULL),
    m_max(VOL_7),
    m_vol(VOL_3),
    m_vib(VFX_FALSE),
    m_vibTmp(VFX_FALSE),
	m_topLevel(NULL),
    m_disappearTimer(NULL),
    m_previewTimer(NULL),
    m_repeatTimer(NULL),
    m_frameEffect(NULL)
{

}

void VappVolumeDialog::onInit(void)
{
	if(g_context == NULL)
	{
	    VFX_OBJ_CREATE(g_context, VfxContext, VFX_SYS_GLOBAL_CONTEXT);
	    g_context->assignPool((VfxU8 *)buffer, g_memSize);
	}

    VfxControl::onInit();

    //setBgColor(VFX_COLOR_GREY);
    //setOpacity(0.8);
    setAnchor(0.5, 0.5);
    setSize(VOL_DIALOG_WIDTH,VOL_DIALOG_HEIGHT);

    VfxImageFrame* image_bg;
    VFX_OBJ_CREATE(image_bg,VfxImageFrame,this);
    image_bg->setResId(VCP_IMG_POPUP_BACKGROUND);
    image_bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    image_bg->setAnchor(0.5,0.5);
    image_bg->setRect(0,0, getSize().width, getSize().height);
    image_bg->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_SIDE);

    VFX_OBJ_CREATE(m_icon, VfxImageFrame, this);
    m_icon->setPos(ICON_X,ICON_Y);
    m_icon->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE,VFX_FRAME_ALIGNER_MODE_NONE);
    //m_icon->setResId(IMG_ID_VAPP_VOL_DIALOG_RING);
    //m_icon->setIsOpaque(VFX_TRUE);
    //m_icon->setHidden(VFX_TRUE);

    VFX_OBJ_CREATE(m_title, VfxTextFrame, this);
	m_title->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_title->setString(VFX_WSTR_RES(STR_ID_VAPP_VOL_DIALOG_RING));
    m_title->setAnchor(0.5,0.5);
    m_title->setPos(TITLE_X,TITLE_Y);
    m_title->setColor(VFX_COLOR_RES(VCP_COL_POPUP_TITLE_FONT));
    m_title->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(TEXT_FONT_SIZE)));
    m_title->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_title->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_NONE);

    //Slider
    VFX_OBJ_CREATE(m_slider, VcpSlider, this);
    m_slider->setAnchor(0.5,0.5);
    m_slider->setPos(BAR_X, BAR_Y);
    m_slider->setLayout(VCP_SLIDER_LAYOUT_HORZ);
    m_slider->setLength(BAR_LENGTH);
    //m_slider->setMaxValue(m_max);
    m_slider->setMinValue(VOL_0);
    //m_slider->setCurrentValue(m_vol);
    m_slider->m_signalUserChangedValue.connect(this, &VappVolumeDialog::onSliderMoved);
    m_slider->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_SIDE);


    m_slider->m_signalThumbPressed.connect(this, &VappVolumeDialog::onSliderPressed);
    m_slider->m_signalThumbReleased.connect(this, &VappVolumeDialog::onSliderReleased);

    m_topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);

    VFX_OBJ_CREATE(m_disappearTimer, VfxTimer, this);
    m_disappearTimer->setStartDelay(1500);
    m_disappearTimer->m_signalTick.connect(this, &VappVolumeDialog::timeOutDisappear);

    VFX_OBJ_CREATE(m_repeatTimer, VfxTimer, this);
    m_repeatTimer->setStartDelay(250);

#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_register_volume_sync_callback(VAPP_VOL_DIALOG, MDI_AUD_VOL_LEVEL_EXTEND, vapp_volume_dialog_hfp_sync_callback);
#endif

}

vrt_allocator_handle VappVolumeDialog::getAllocator()    
{
	if(g_context != NULL)
	{
		return g_context->getAllocator();
	}
	return NULL;
}

void VappVolumeDialog::onRotate(VfxScreenRotateParam param)
{
    if (m_state != STATE_IDLE)
	{
        // From
        setAutoAnimate(VFX_FALSE);
        setAnchor(0.5f, 0.5f);

        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);

        setPos(getParentFrame()->getBounds().getMidPoint());

        VfxAutoAnimate::commit();

        VfxS32 width = VOL_DIALOG_WIDTH;

        switch(param.rotateTo)
        {
            case VFX_SCR_ROTATE_TYPE_90:
            case VFX_SCR_ROTATE_TYPE_270:
            {
                width += ROTATE_EXTND_SIZE;
                break;
            }
        }

        setSize(width , VOL_DIALOG_HEIGHT);

        VfxTransform t;
        t.data.affine.rz = VFX_DEG_TO_RAD(90.0f) * 
            (((VfxU32)param.rotateTo - (VfxU32)param.rotateFrom + 4) % 4);
        if (t.data.affine.rz > VFX_DEG_TO_RAD(180.0f))
        {
            t.data.affine.rz -= VFX_DEG_TO_RAD(360.0f);
        }
        setTransform(t);
        setQuality(VFX_RENDER_QUALITY_NORMAL);

        // To
        setAutoAnimate(VFX_TRUE);
        t.setIdentity();
        setTransform(t);

	}	
}


void VappVolumeDialog::timeOutDisappear(VfxTimer *source)
{
    VFX_UNUSED(source);

    if(m_state == STATE_IDLE)
    {
        return;
    }

    disappear();

    m_frameEffect->m_signalFinished.connect(this,&VappVolumeDialog::onFrameEffectFinished);
    m_frameEffect->applyEffect((VfxFrame*)this, VCP_EFFECT_FADE_IN,200,VCP_EFFECT_DIRECTION_FROM_NONE,VFX_TRUE,NULL,0);
}

void VappVolumeDialog::disappear(void)
{
    switch(m_state)
    {
        case STATE_SPEECH:
        {
            srv_speech_save_mode_volume((U8)MDI_AUD_VOL_MUTE(m_vol));
            break;
        }

        default:
            break;
    }

    m_state = STATE_IDLE;

    mmi_frm_cb_dereg_event(EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN, (mmi_proc_func)&VappVolumeDialog::onProc, getObjHandle());
    mmi_frm_cb_dereg_event(EVT_ID_SRV_PROF_PROFILE_SWITCHED, (mmi_proc_func)&VappVolumeDialog::onProc, getObjHandle());
	mmi_frm_cb_dereg_event(EVT_ID_MDI_AUDIO_PRE_MODE_SWITCH, (mmi_proc_func)&VappVolumeDialog::onProc, getObjHandle());

    if(m_previewTimer != NULL)
    {
        VFX_OBJ_CLOSE(m_previewTimer);
    }
    vapp_screen_lock_disable_backlight_timer(MMI_FALSE);

}

void VappVolumeDialog::previewRing(VfxTimer *source)
{
    if(mdi_audio_is_resource_available(MDI_AUDIO_PLAY_STRING,NULL)||g_vapp_volume_dialog_is_previewing == MMI_TRUE)
    {
        U8 *audio_data;
        U8 audio_type;
        U32 audio_len;
		mdi_result  result;

        audio_data = get_audio(AUD_ID_VAPP_SND_SET_PREVIEW, &audio_type, &audio_len);

        ASSERT(audio_data != NULL);
        
        result = mdi_audio_play_string_with_vol_path(
                 	(void*)audio_data,
                 	audio_len,
                 	audio_type,
                 	MDI_AUDIO_PLAY_ONCE,
                 	vapp_volume_dialog_play_audio_callback,
                 	NULL,
                 	MDI_AUD_VOL_MUTE(m_vol),
                 	MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER2)
                 	);

		g_vapp_volume_dialog_is_previewing = MMI_TRUE;

		if(result != MDI_AUDIO_SUCCESS)
		{
			g_vapp_volume_dialog_is_previewing = MMI_FALSE;
		}
 
    }
}

void VappVolumeDialog::onSliderPressed(VcpSlider *obj, VfxFloat val)
{
    VFX_UNUSED(obj);
    VFX_UNUSED(val);

    m_disappearTimer->stop();
    
}

void VappVolumeDialog::onSliderReleased(VcpSlider *obj, VfxFloat val)
{
    VFX_UNUSED(obj);
    VFX_UNUSED(val);

    m_disappearTimer->start();

}

void VappVolumeDialog::onSliderMoved(VfxObject *obj, VfxFloat oldval, VfxFloat newval)
{
    VappVolumeDialogStateEnum state = queryState();
    if(state != m_state)
    {
        disappear();
        dialogFinished();
    }

    if(m_vol == (VfxU8)newval)
    {
        return ;
    }

    switch(m_state)
    {
        case STATE_RING:
        {
            mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_MUTE((VfxU8)newval));

            m_previewTimer->start();

            VfxBool vib_update = VFX_FALSE;

            srv_prof_setting_struct settings_1;
            srv_prof_setting_struct settings_2;

            srv_prof_get_profile_values(SRV_PROF_PROFILE_1, &settings_1);
            srv_prof_get_profile_values(SRV_PROF_PROFILE_2, &settings_2);

            if(m_vol == VOL_0 || m_vol == VOL_7)
            {
                if(m_vib)
                {
                    m_vibTmp = VFX_TRUE;

                    settings_2.alert_type = SRV_PROF_ALERT_TYPE_VIB_ONLY;
                    settings_2.vibrate = MMI_TRUE;

                    settings_1.alert_type = SRV_PROF_ALERT_TYPE_VIB_AND_RING;
                    settings_1.vibrate = MMI_TRUE;

                }
                else
                {
                    m_vibTmp = VFX_FALSE;

                    settings_2.alert_type = SRV_PROF_ALERT_TYPE_SILENT;
                    settings_2.vibrate = MMI_FALSE;

                    settings_1.alert_type = SRV_PROF_ALERT_TYPE_RING;
                    settings_1.vibrate = MMI_FALSE;

                }

                vib_update = VFX_TRUE;

            }

            m_vol = newval;

            settings_1.ring_vol = m_vol;
            settings_1.msg_vol = m_vol;
			
            srv_prof_set_profile_values(SRV_PROF_PROFILE_1, &settings_1);

            if(vib_update)
            {
                srv_prof_set_profile_values(SRV_PROF_PROFILE_2, &settings_2);
            }

            if(newval > VOL_0)
            {
                srv_prof_deactivate_profile_by_external_module(SRV_PROF_SILENT_MODE);
            }
            else
            {
                srv_prof_activate_profile_by_external_module(SRV_PROF_SILENT_MODE);
            }

            if(vib_update)
            {
                mmi_event_struct evt;
                MMI_FRM_INIT_EVENT(&evt, EVT_ID_VOL_DIALOG_VIB_CHANGED);
                MMI_FRM_CB_EMIT_POST_EVENT(&evt);
            }

            updateIcon();
            break;
        }

        case STATE_MEDIA:
        {
            mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX_MUTE((VfxU8)newval));
            m_vol = newval;

        #ifdef __MMI_UNIQUE_MEDIA_VOL__
            setProfileMediaVol(m_vol);
        #endif 

            break;
        }
        
        case STATE_MEDIA_FM:
        {
            mdi_audio_set_volume(MDI_VOLUME_FMR, MDI_AUD_VOL_EX_MUTE((VfxU8)newval));
            m_vol = newval;

        #ifdef __MMI_UNIQUE_MEDIA_VOL__
            setProfileMediaVol(m_vol);
        #endif 

            break;
        }

        case STATE_MEDIA_ATV:
        {
            mdi_audio_set_volume(MDI_VOLUME_ATV, MDI_AUD_VOL_EX_MUTE((VfxU8)newval));
            m_vol = newval;

        #ifdef __MMI_UNIQUE_MEDIA_VOL__
            setProfileMediaVol(m_vol);
        #endif 

            break;
        }

        case STATE_SPEECH:
        {
            mdi_audio_set_volume(MDI_VOLUME_SPH, MDI_AUD_VOL_MUTE((VfxU8)newval));
            m_vol = newval;
            break;
        }

        case STATE_NOT_SHOWN:
        {
			mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_MUTE((VfxU8)newval));
            m_vol = newval;
            break;
        }

        default:
            break;
    }

//    m_slider->setCurrentValue(m_vol);


}

#ifdef __MMI_UNIQUE_MEDIA_VOL__
void VappVolumeDialog::setProfileMediaVol(VfxU8 vol)
{
	srv_prof_setting_struct settings;
	
	srv_prof_get_profile_values(SRV_PROF_PROFILE_2, &settings);
	settings.media_vol = (srv_prof_volume_level)vol;
	srv_prof_set_profile_values(SRV_PROF_PROFILE_2, &settings);

	srv_prof_get_profile_values(SRV_PROF_PROFILE_1, &settings);
	settings.media_vol = (srv_prof_volume_level)vol;
	srv_prof_set_profile_values(SRV_PROF_PROFILE_1, &settings);

}
#endif

void VappVolumeDialog::setProfileVibAlertType(
		srv_prof_alert_type_enum type_profile2,
		srv_prof_alert_type_enum type_profile1,
		MMI_BOOL can_vib)
{
	srv_prof_setting_struct settings;
	
	srv_prof_get_profile_values(SRV_PROF_PROFILE_2, &settings);
	settings.alert_type = type_profile2;
	settings.vibrate = can_vib;
	srv_prof_set_profile_values(SRV_PROF_PROFILE_2, &settings);

	srv_prof_get_profile_values(SRV_PROF_PROFILE_1, &settings);
	settings.alert_type = type_profile1;
	settings.vibrate = can_vib;
	srv_prof_set_profile_values(SRV_PROF_PROFILE_1, &settings);

}

void VappVolumeDialog::setIncreaseRing(void)
{
    VfxBool vib_update = VFX_FALSE;

    m_previewTimer->start();

    if(m_vol == VOL_0 && !m_vibTmp)
    {
        m_vibTmp = VFX_TRUE;

		setProfileVibAlertType(
		SRV_PROF_ALERT_TYPE_VIB_ONLY,
		SRV_PROF_ALERT_TYPE_VIB_AND_RING,
		MMI_TRUE);
		vib_update = VFX_TRUE;
    }
    else if(m_vol == VOL_0 && m_vibTmp && !m_vib)
    {
        m_vol = VOL_1;
		if(g_vapp_volume_dialog_is_previewing == MMI_FALSE)
		{
        	mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_MUTE(m_vol));
		}
        m_vibTmp = VFX_FALSE;

        srv_prof_setting_struct settings;
        srv_prof_get_profile_values(SRV_PROF_PROFILE_1, &settings);
        settings.ring_vol = (srv_prof_volume_level)m_vol;
		settings.msg_vol = (srv_prof_volume_level)m_vol;
        srv_prof_set_profile_values(SRV_PROF_PROFILE_1, &settings);

		setProfileVibAlertType(
		SRV_PROF_ALERT_TYPE_SILENT,
		SRV_PROF_ALERT_TYPE_RING,
		MMI_FALSE);
		vib_update = VFX_TRUE;
    }
    else if(m_vol < VOL_7)
    {
        m_vol ++;
        //srv_prof_deactivate_profile_by_external_module(SRV_PROF_SILENT_MODE);
        if(g_vapp_volume_dialog_is_previewing == MMI_FALSE)
        {
        	mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_MUTE(m_vol));
        }
        srv_prof_setting_struct settings;
        srv_prof_get_profile_values(SRV_PROF_PROFILE_1, &settings);
        settings.ring_vol = (srv_prof_volume_level)m_vol;
		settings.msg_vol = (srv_prof_volume_level)m_vol;
        srv_prof_set_profile_values(SRV_PROF_PROFILE_1, &settings);

    }
    else if(m_vol == VOL_7 && !m_vibTmp)
    {
        m_vibTmp = VFX_TRUE;

		setProfileVibAlertType(
		SRV_PROF_ALERT_TYPE_VIB_ONLY,
		SRV_PROF_ALERT_TYPE_VIB_AND_RING,
		MMI_TRUE);
		vib_update = VFX_TRUE;
    }

    if(m_vol > VOL_0)
    {
        srv_prof_deactivate_profile_by_external_module(SRV_PROF_SILENT_MODE);
    }

    if(vib_update)
    {
        mmi_event_struct evt;
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_VOL_DIALOG_VIB_CHANGED);
        MMI_FRM_CB_EMIT_POST_EVENT(&evt);
    }

    updateIcon();
    m_slider->setCurrentValue(m_vol);
    
}

void VappVolumeDialog::setDecreaseRing(void)
{
    VfxBool vib_update = VFX_FALSE;

    m_previewTimer->start();

    if(m_vol == VOL_7 && m_vibTmp && !m_vib)
    {
        m_vibTmp = VFX_FALSE;

		setProfileVibAlertType(
		SRV_PROF_ALERT_TYPE_SILENT,
		SRV_PROF_ALERT_TYPE_RING,
		MMI_FALSE);
        vib_update = VFX_TRUE;
    }
    else if(m_vol > VOL_1)
    {
        m_vol --;
		if(g_vapp_volume_dialog_is_previewing == MMI_FALSE)
		{
        	mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_MUTE(m_vol));
		}
        srv_prof_setting_struct settings;
        srv_prof_get_profile_values(SRV_PROF_PROFILE_1, &settings);
        settings.ring_vol = (srv_prof_volume_level)m_vol;
		settings.msg_vol= (srv_prof_volume_level)m_vol;
        srv_prof_set_profile_values(SRV_PROF_PROFILE_1, &settings);

    }
    else if(m_vol == VOL_1)
    {
        m_vol = VOL_0;
		if(g_vapp_volume_dialog_is_previewing == MMI_FALSE)
		{
        	mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_MUTE(m_vol));
		}
        m_vibTmp = VFX_TRUE;

        srv_prof_setting_struct settings;
        srv_prof_get_profile_values(SRV_PROF_PROFILE_1, &settings);
        settings.ring_vol = (srv_prof_volume_level)m_vol;
		settings.msg_vol = (srv_prof_volume_level)m_vol;
        srv_prof_set_profile_values(SRV_PROF_PROFILE_1, &settings);

		setProfileVibAlertType(
		SRV_PROF_ALERT_TYPE_VIB_ONLY,
		SRV_PROF_ALERT_TYPE_VIB_AND_RING,
		MMI_TRUE);
        vib_update = VFX_TRUE;

    }
    else if(m_vol == VOL_0)
    {
        m_vibTmp = VFX_FALSE;

		setProfileVibAlertType(
		SRV_PROF_ALERT_TYPE_SILENT,
		SRV_PROF_ALERT_TYPE_RING,
		MMI_FALSE);
		vib_update = VFX_TRUE;

    }

    if(m_vol == VOL_0)
    {
        srv_prof_activate_profile_by_external_module(SRV_PROF_SILENT_MODE);
    }

    if(vib_update)
    {
        mmi_event_struct evt;
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_VOL_DIALOG_VIB_CHANGED);
        MMI_FRM_CB_EMIT_POST_EVENT(&evt);
    }

    updateIcon();
    m_slider->setCurrentValue(m_vol);

}

void VappVolumeDialog::setRepeatVol(mmi_keypads_enum keycode)
{
	VappVolumeDialogStateEnum state = queryState();
	if(state != m_state)
	{
		disappear();
		dialogFinished();
	}

	switch(m_state)
	{
		case STATE_RING:
		{
			onSetRingVol(keycode);
			break;
		}
		
		case STATE_MEDIA:
		case STATE_MEDIA_FM:
		case STATE_MEDIA_ATV:
		{
			onSetMediaVol(keycode);
			break;
		}

		case STATE_NOT_SHOWN:
		{
			onSetNotShownVol(keycode);
			break;
		}

		case STATE_SPEECH:
		{
			onSetSpeechVol(keycode);
			break;
		}

		default: 
			break;
	}

	m_repeatTimer->start();

}

void VappVolumeDialog::onSetNotShownVol(mmi_keypads_enum keycode)
{
	if((keycode == KEY_VOL_DOWN) && (m_vol > VOL_0))
	{
		m_vol --;
	}
	if((keycode == KEY_VOL_UP) && (m_vol < VOL_7))
	{
		m_vol ++;
	}
	
    mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_MUTE(m_vol));

	srv_prof_setting_struct settings;

	srv_prof_get_profile_values(SRV_PROF_PROFILE_1, &settings);
	settings.ring_vol = (srv_prof_volume_level)m_vol;
	settings.msg_vol = (srv_prof_volume_level)m_vol;
	srv_prof_set_profile_values(SRV_PROF_PROFILE_1, &settings);

/*
	if(m_vol == VOL_0)
    {
        srv_prof_activate_profile_by_external_module(SRV_PROF_SILENT_MODE);
    }
	else
	{
		srv_prof_deactivate_profile_by_external_module(SRV_PROF_SILENT_MODE);
	}
*/

	/*updateIcon after set volume*/
	updateIcon();
}

void VappVolumeDialog::onSetSpeechVol(mmi_keypads_enum keycode)
{
	if((keycode == KEY_VOL_DOWN) && (m_vol > VOL_0))
	{
		m_vol --;
	}
	if((keycode == KEY_VOL_UP) && (m_vol < VOL_7))
	{
		m_vol ++;
	}
	mdi_audio_set_volume(MDI_VOLUME_SPH, MDI_AUD_VOL_MUTE(m_vol));
	m_slider->setCurrentValue(m_vol);
	
}

void VappVolumeDialog::onSetMediaVol(mmi_keypads_enum keycode)
{
	if((keycode == KEY_VOL_DOWN) && (m_vol > VOL_0))
	{
		m_vol --;
	}
	if((keycode == KEY_VOL_UP) && (m_vol < VOL_16))
	{
		m_vol ++;
	}
	mdi_audio_set_volume(MDI_VOLUME_FMR, MDI_AUD_VOL_EX_MUTE(m_vol));
	mdi_audio_set_volume(MDI_VOLUME_ATV, MDI_AUD_VOL_EX_MUTE(m_vol));
	mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX_MUTE(m_vol));

	#ifdef __MMI_UNIQUE_MEDIA_VOL__
		setProfileMediaVol(m_vol);
	#endif 

	m_slider->setCurrentValue(m_vol);

}

void VappVolumeDialog::onSetRingVol(mmi_keypads_enum keycode)
{
	if(keycode == KEY_VOL_DOWN)
	{
		setDecreaseRing();
	}
	if(keycode == KEY_VOL_UP)
	{
		setIncreaseRing();
	}

}

void VappVolumeDialog::onDecreaseRepeat(VfxTimer *source)
{
    setRepeatVol(KEY_VOL_DOWN);
}

void VappVolumeDialog::onIncreaseRepeat(VfxTimer *source)
{
    setRepeatVol(KEY_VOL_UP);
}

void VappVolumeDialog::updateIcon(void)
{
    if(m_vibTmp && m_vol != VOL_0)
    {
        m_icon->setResId(IMG_ID_VAPP_VOL_DIALOG_VIB_RING);
    }
    else if(m_vibTmp && m_vol == VOL_0)
    {
        m_icon->setResId(IMG_ID_VAPP_VOL_DIALOG_VIB);
    }
    else if(!m_vibTmp && m_vol != VOL_0)
    {
        m_icon->setResId(IMG_ID_VAPP_VOL_DIALOG_RING);
    }
    else if(!m_vibTmp && m_vol == VOL_0)
    {
        m_icon->setResId(IMG_ID_VAPP_VOL_DIALOG_MUTE);
    }

    vapp_sound_settings_update_status_icon();
    
}

VappVolumeDialog::VappVolumeDialogStateEnum VappVolumeDialog::queryState(void)
{
    //mmi_event_struct evt_media, evt_not_shown, evt_speech;
    vapp_vol_dialog_evt_struct evt;
    mmi_ret result_media, result_fm, result_mtv, result_not_shown, result_speech;

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE);
    evt.type = VAPP_VOL_DIALOG_IS_MEDIA;
    result_media = MMI_FRM_CB_EMIT_EVENT(&evt);
    
    evt.type = VAPP_VOL_DIALOG_IS_FM;
    result_fm = MMI_FRM_CB_EMIT_EVENT(&evt);

    evt.type = VAPP_VOL_DIALOG_IS_MTV;
    result_mtv = MMI_FRM_CB_EMIT_EVENT(&evt);

    evt.type = VAPP_VOL_DIALOG_IS_NOT_SHOWN;
    result_not_shown = MMI_FRM_CB_EMIT_EVENT(&evt);

    evt.type = VAPP_VOL_DIALOG_IS_SPEECH;
    result_speech = MMI_FRM_CB_EMIT_EVENT(&evt);

    if(result_speech != MMI_RET_OK && result_speech != MMI_RET_ERR_NO_REG_CB)
    {
        return STATE_SPEECH;
    }
    else if(result_not_shown != MMI_RET_OK && result_not_shown != MMI_RET_ERR_NO_REG_CB)
    {
        return STATE_NOT_SHOWN;
    }
    else if((result_media != MMI_RET_OK && result_media != MMI_RET_ERR_NO_REG_CB))
    {
        return STATE_MEDIA;
    }
    else if((result_fm != MMI_RET_OK && result_fm != MMI_RET_ERR_NO_REG_CB))
    {
         return STATE_MEDIA_FM;
    }
    else if((result_mtv != MMI_RET_OK && result_mtv != MMI_RET_ERR_NO_REG_CB))
    {
         return STATE_MEDIA_ATV;
    }
    else
    {
        return STATE_RING;
    }

}


void VappVolumeDialog::updateDialog(void)
{
    vapp_screen_lock_disable_backlight_timer(MMI_TRUE);

    VappVolumeDialogStateEnum state = queryState();

    m_vib = (srv_prof_if_can_vibrate() != MMI_FALSE) ;
    m_vibTmp = m_vib;

    if(state == STATE_SPEECH)
    {
        m_state = STATE_SPEECH;
        m_title->setString(VFX_WSTR_RES(STR_ID_VAPP_VOL_DIALOG_SPEECH));
        m_icon->setHidden(VFX_TRUE);
        m_vol = MDI_AUD_VOL_GET_EX_LEVEL(srv_speech_get_mode_volume());
        m_slider->setMaxValue(VOL_7);
        m_slider->setTotalDiscreteStepsForPen(7);
        m_slider->setCurrentValue(m_vol);
    }
    else if(state == STATE_NOT_SHOWN)
    {
        if(srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) == SRV_PROF_RET_PROFILE_ACTIVATED)
        {
            vapp_screen_lock_disable_backlight_timer(MMI_FALSE);
            return;
        }
        m_state = STATE_NOT_SHOWN;
        m_vol = MDI_AUD_VOL_GET_EX_LEVEL(srv_prof_get_ring_vol());
        m_slider->setMaxValue(VOL_7);
        m_slider->setTotalDiscreteStepsForPen(7);
        m_slider->setCurrentValue(m_vol);
    }
    else if(state == STATE_MEDIA)
    {
        m_state = STATE_MEDIA;
        m_title->setString(VFX_WSTR_RES(STR_ID_VAPP_VOL_DIALOG_MEDIA));
        m_icon->setHidden(VFX_TRUE);
        m_vol = MDI_AUD_VOL_GET_EX_LEVEL(srv_prof_get_media_vol());
        m_slider->setMaxValue(VOL_16);
        m_slider->setTotalDiscreteStepsForPen(16);
        m_slider->setCurrentValue(m_vol);
    }
    else if(state == STATE_MEDIA_FM)
    {
        m_state = STATE_MEDIA_FM;
        m_title->setString(VFX_WSTR_RES(STR_ID_VAPP_VOL_DIALOG_MEDIA));
        m_icon->setHidden(VFX_TRUE);
        m_vol = MDI_AUD_VOL_GET_EX_LEVEL(srv_prof_get_media_vol());
        m_slider->setMaxValue(VOL_16);
        m_slider->setTotalDiscreteStepsForPen(16);
        m_slider->setCurrentValue(m_vol);
    }
    else if(state == STATE_MEDIA_ATV)
    {
        m_state = STATE_MEDIA_ATV;
        m_title->setString(VFX_WSTR_RES(STR_ID_VAPP_VOL_DIALOG_MEDIA));
        m_icon->setHidden(VFX_TRUE);
        m_vol = MDI_AUD_VOL_GET_EX_LEVEL(srv_prof_get_media_vol());
        m_slider->setMaxValue(VOL_16);
        m_slider->setTotalDiscreteStepsForPen(16);
        m_slider->setCurrentValue(m_vol);
    }
    else
    {
        m_state = STATE_RING;
        m_title->setString(VFX_WSTR_RES(STR_ID_VAPP_VOL_DIALOG_RING));
        m_icon->setHidden(VFX_FALSE);
        m_vol = MDI_AUD_VOL_GET_EX_LEVEL(srv_prof_get_ring_vol());
        m_slider->setMaxValue(VOL_7);
        m_slider->setTotalDiscreteStepsForPen(7);
        m_slider->setCurrentValue(m_vol);
        updateIcon();
    }

}

void VappVolumeDialog::dialogFinished(void)
{
    this->removeFromParentFrame();
	m_topLevel->m_signalRotated.disconnect(this, &VappVolumeDialog::onRotate);
    m_topLevel->m_signalActiveScreenExit.disconnect(this, &VappVolumeDialog::onScreenChanged);
    VFX_OBJ_CLOSE(m_frameEffect);
	m_disappearTimer->stop();
}

void VappVolumeDialog::forceDisappear(void)
{
    if(m_state == STATE_IDLE)
    {
        return;
    }

    m_repeatTimer->stop();
    disappear();
    dialogFinished();
}


void VappVolumeDialog::onFrameEffectFinished(VfxFrame *target, VfxBool isCompleted)
{
    if(!isCompleted)
    {
        return;
    }

    dialogFinished();
}

void VappVolumeDialog::onScreenChanged(VfxWeakPtr<VfxScreen> scr)
{
    forceDisappear();
}

void VappVolumeDialog::profileSwitched(void)
{
    if((srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) > 0 && m_vol != 0) || (srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) < 0 && m_vol == 0))
    {
        m_state = STATE_IDLE;
        disappear();
        dialogFinished();        
    }
}

void VappVolumeDialog::modeSwitched(void)
{
    disappear();
    dialogFinished();
}

mmi_ret VappVolumeDialog::onProc(mmi_event_struct *evt)
{
    VappVolumeDialog* dialog = (VappVolumeDialog*)VfxObject::handleToObject((VfxObjHandle)evt->user_data);

    if(dialog == NULL)
    {
        return MMI_RET_OK;
    }

    if(dialog->m_state == STATE_IDLE)
    {
        return MMI_RET_OK;
    }

    switch(evt->evt_id)
    {
        case EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN:
        {
            dialog->disappear();
            dialog->dialogFinished();
            break;
        }

        case EVT_ID_SRV_PROF_PROFILE_SWITCHED:
        {
            dialog->profileSwitched();
            break;
        }
		case EVT_ID_MDI_AUDIO_PRE_MODE_SWITCH:
		{
			dialog->modeSwitched();
			break;
		}

    }

    return MMI_RET_OK;

}

#ifdef __BT_SPK_VOL_CONTROL__
void VappVolumeDialog::onVolHfp(VfxU8 bt_volume)
{
    if(m_state == STATE_IDLE)
    {
        m_disappearTimer->stop();
        updateDialog();

        if(m_state == STATE_IDLE)
        {
            return;
        }
        
        if(m_frameEffect == NULL)
        {
            VFX_OBJ_CREATE(m_frameEffect, VcpFrameEffect, this);
            m_frameEffect->applyEffect((VfxFrame*)this, VCP_EFFECT_FADE_IN,150,VCP_EFFECT_DIRECTION_FROM_NONE,VFX_FALSE,NULL,0);
        }
        else
        {
            m_frameEffect->restore();
        }

        mmi_frm_cb_reg_event(EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN, (mmi_proc_func)&VappVolumeDialog::onProc, getObjHandle());
        mmi_frm_cb_reg_event(EVT_ID_SRV_PROF_PROFILE_SWITCHED, (mmi_proc_func)&VappVolumeDialog::onProc, getObjHandle());
		mmi_frm_cb_reg_event(EVT_ID_MDI_AUDIO_PRE_MODE_SWITCH, (mmi_proc_func)&VappVolumeDialog::onProc, getObjHandle());
    
        if(m_state == STATE_NOT_SHOWN)
        {
            m_topLevel->m_signalActiveScreenExit.connect(this, &VappVolumeDialog::onScreenChanged);
            return;
        }

        if(m_state == STATE_RING && m_previewTimer == NULL)
        {
            VFX_OBJ_CREATE(m_previewTimer, VfxTimer, this);
            m_previewTimer->setStartDelay(500);
            m_previewTimer->m_signalTick.connect(this, &VappVolumeDialog::previewRing);
        }

        m_topLevel->addChildFrame(this);
		m_topLevel->m_signalRotated.connect(this, &VappVolumeDialog::onRotate);

        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);

        setPos(getParentFrame()->getBounds().getMidPoint());

        VfxS32 width = VOL_DIALOG_WIDTH;

        switch(m_topLevel->getScreenRotateType())
        {
            case VFX_SCR_ROTATE_TYPE_90:
            case VFX_SCR_ROTATE_TYPE_270:
            {
                width += ROTATE_EXTND_SIZE;
                break;
            }
        }

        setSize(width , VOL_DIALOG_HEIGHT);
        VfxAutoAnimate::commit();

        m_topLevel->m_signalActiveScreenExit.connect(this, &VappVolumeDialog::onScreenChanged);

        //this->setPos(m_topLevel->getSize().width/2,m_topLevel->getSize().height/2);
    }

    VfxU8 app_volume = 0;

    switch(m_state)
    {
        case STATE_RING:
        case STATE_SPEECH:
        case STATE_NOT_SHOWN:
        {
            app_volume = (VfxU8)mdi_audio_bt_get_volume_level_from_type((U8)bt_volume, MDI_AUD_VOL_LEVEL_NORMAL_MUTE);
            break;
        }

        case STATE_MEDIA:
        case STATE_MEDIA_FM:
        case STATE_MEDIA_ATV:
        {
            app_volume = (VfxU8)mdi_audio_bt_get_volume_level_from_type((U8)bt_volume, MDI_AUD_VOL_LEVEL_EXTEND_MUTE);
            break;
        }
    }
	
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_VOL_DIALOG_BT_ONVOLHFP, m_state, app_volume);

    m_disappearTimer->start();

    m_slider->setCurrentValue(app_volume);
    onSliderMoved(NULL,0.0,(VfxFloat) app_volume);

}
#endif

void VappVolumeDialog::setStateVol(VappVolumeDialogStateEnum state, mmi_keypads_enum key_code)
{
	switch(m_state)
	{
		case STATE_RING:
		{
			onSetRingVol(key_code);
			break;
		}
		
		case STATE_MEDIA:
		case STATE_MEDIA_FM:
		case STATE_MEDIA_ATV:
		{
			onSetMediaVol(key_code);
			break;
		}

		case STATE_NOT_SHOWN:
		{
			onSetNotShownVol(key_code);
			break;
		}

		case STATE_SPEECH:
		{
			onSetSpeechVol(key_code);
			break;
		}

		default: 
			break;
	}

}
void VappVolumeDialog::onVolKey(mmi_keypads_enum key_code, mmi_key_types_enum key_type)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_VOL_DIALOG_ONVOLKEY, m_state, key_code, key_type);

    if(m_state == STATE_IDLE)
    {
        if(key_type != KEY_EVENT_DOWN)
        {
            return;
        }

        m_disappearTimer->stop();
        updateDialog();
		
        if(m_state == STATE_IDLE)
        {
            return;
        }
        
        if(m_frameEffect == NULL)
        {
            VFX_OBJ_CREATE(m_frameEffect, VcpFrameEffect, this);
            m_frameEffect->applyEffect((VfxFrame*)this, VCP_EFFECT_FADE_IN,150,VCP_EFFECT_DIRECTION_FROM_NONE,VFX_FALSE,NULL,0);
        }
        else
        {
            m_frameEffect->restore();
        }

        mmi_frm_cb_reg_event(EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN, (mmi_proc_func)&VappVolumeDialog::onProc, getObjHandle());
        mmi_frm_cb_reg_event(EVT_ID_SRV_PROF_PROFILE_SWITCHED, (mmi_proc_func)&VappVolumeDialog::onProc, getObjHandle());
		mmi_frm_cb_reg_event(EVT_ID_MDI_AUDIO_PRE_MODE_SWITCH, (mmi_proc_func)&VappVolumeDialog::onProc, getObjHandle());

        if(m_state != STATE_NOT_SHOWN)
        {
            if(m_state == STATE_RING && m_previewTimer == NULL)
            {
                VFX_OBJ_CREATE(m_previewTimer, VfxTimer, this);
                m_previewTimer->setStartDelay(500);
                m_previewTimer->m_signalTick.connect(this, &VappVolumeDialog::previewRing);
            }

            m_topLevel->addChildFrame(this);
			m_topLevel->m_signalRotated.connect(this, &VappVolumeDialog::onRotate);

            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);

            setPos(getParentFrame()->getBounds().getMidPoint());

            VfxS32 width = VOL_DIALOG_WIDTH;

            switch(m_topLevel->getScreenRotateType())
            {
                case VFX_SCR_ROTATE_TYPE_90:
                case VFX_SCR_ROTATE_TYPE_270:
                {
                    width += ROTATE_EXTND_SIZE;
                    break;
                }
            }

            setSize(width , VOL_DIALOG_HEIGHT);
            VfxAutoAnimate::commit();

            m_topLevel->m_signalActiveScreenExit.connect(this, &VappVolumeDialog::onScreenChanged);

            m_repeatTimer->m_signalTick.disconnect(this, &VappVolumeDialog::onIncreaseRepeat);
            m_repeatTimer->m_signalTick.disconnect(this, &VappVolumeDialog::onDecreaseRepeat);

            if(key_code == KEY_VOL_DOWN)
            {
                m_repeatTimer->m_signalTick.connect(this, &VappVolumeDialog::onDecreaseRepeat);
            }
            else
            {
                m_repeatTimer->m_signalTick.connect(this, &VappVolumeDialog::onIncreaseRepeat);
            }

            m_repeatTimer->start();

            return;

        }
        else
        {
            m_topLevel->m_signalActiveScreenExit.connect(this, &VappVolumeDialog::onScreenChanged);
        }
 
        //this->setPos(m_topLevel->getSize().width/2,m_topLevel->getSize().height/2);
    }
    else
    {
        VappVolumeDialogStateEnum state = queryState();

        if(state != m_state)
        {
            disappear();
            dialogFinished();
        }
    }

    switch(key_code)
    {
        case KEY_VOL_DOWN:
        {
            switch(key_type)
            {
                case KEY_EVENT_DOWN:
                {
                    m_disappearTimer->stop();

					setStateVol(m_state, KEY_VOL_DOWN);
					
                    m_repeatTimer->m_signalTick.disconnect(this, &VappVolumeDialog::onIncreaseRepeat);
                    m_repeatTimer->m_signalTick.connect(this, &VappVolumeDialog::onDecreaseRepeat);
                    m_repeatTimer->start();
                    break;
                }

                case KEY_EVENT_UP:
                {
                    m_disappearTimer->start();
                    m_repeatTimer->stop();
                    break;
                }

                default: 
                    break;
            }
            break;
        }

        case KEY_VOL_UP:
        {
            switch(key_type)
            {
                case KEY_EVENT_DOWN:
                {
                    m_disappearTimer->stop();

                    setStateVol(m_state, KEY_VOL_UP);

                    m_repeatTimer->m_signalTick.disconnect(this, &VappVolumeDialog::onDecreaseRepeat);
                    m_repeatTimer->m_signalTick.connect(this, &VappVolumeDialog::onIncreaseRepeat);
                    m_repeatTimer->start();

                    break;
                }

                case KEY_EVENT_UP:
                {
                    m_disappearTimer->start();
                    m_repeatTimer->stop();
                    break;
                }

                default: 
                    break;
            }

            break;
        }

        default: 
            break;

    }

}

