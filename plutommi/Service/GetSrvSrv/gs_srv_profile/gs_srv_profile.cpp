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
*   gs_srv_idlescreen.cpp 
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   IProfile implement file
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "MMI_features.h"
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 
	//#include "custom_mmi_default_value.h"
#include "ProfilesSrvGprot.h"
#ifdef __cplusplus
}
#endif 

#include "gs_srv_profile_impl.h"
#include "vmlog.h"

GS_IBase *CreateProfileService(U32 hd)
{
	ProfileService* service = NULL;
	GS_NEW_EX(service, ProfileService,(hd));
	return (GS_IBase*)(GS_CBase*)service;
}

ProfileService::ProfileService(U32 handle):GS_CBase(handle){}

S32 CALLCC ProfileService::queryInterface(S32 iid, GS_IBase **pptr)
{
	/* Please notes: pptr may be a proxy, your call should not use it directly. */
	if (pptr == NULL)
		return 0;
	if (iid == IID_IPROFILE)
	{
		//vm_log_debug("ProfileService::iid == IID_IPROFILE ");
		addRef();
		*pptr = BIND_PROXY(IProfile,this);
		return 1;
	}
	return GS_CBase::queryInterface(iid, pptr);
}


gs_srv_prof_ret CALLCC ProfileService::active(gs_srv_prof_external_profile_enum profile)
{    
	return srv_prof_activate_profile_by_external_module((srv_prof_external_profile_enum)profile);
}

gs_srv_prof_ret CALLCC ProfileService::deactive(gs_srv_prof_external_profile_enum profile)
{
	return srv_prof_deactivate_profile_by_external_module((srv_prof_external_profile_enum)profile);
}

gs_srv_prof_ret CALLCC ProfileService::getCurrentProfileValue(gs_srv_prof_settings_enum setting, void* value)
{
	return srv_prof_get_current_profile_value((srv_prof_settings_enum)setting,value);
}    

gs_srv_prof_ret CALLCC ProfileService::setCurrentProfileValue(gs_srv_prof_settings_enum setting, void* value)
{
	return srv_prof_set_current_profile_value((srv_prof_settings_enum)setting,value);
}    

gs_srv_prof_ret CALLCC ProfileService::isProfileActivated(gs_srv_prof_external_profile_enum profile)
{
	return srv_prof_is_profile_activated((srv_prof_external_profile_enum)profile);
}    

MMI_BOOL CALLCC ProfileService::ifCanRing()
{
	return srv_prof_if_can_ring();
}    

MMI_BOOL CALLCC ProfileService::ifCanVibrate()
{
	return srv_prof_if_can_vibrate();
}

gs_srv_prof_ret CALLCC ProfileService::playTone(gs_srv_prof_tone_enum tone_type, gs_srv_prof_play_tone_callback callback)
{
	return srv_prof_play_tone((srv_prof_tone_enum)tone_type,callback);
}

gs_srv_prof_ret CALLCC ProfileService::playToneWithId(gs_srv_prof_tone_enum tone_type, U16 audio_id, gs_srv_prof_ring_type_enum play_type, gs_srv_prof_play_tone_callback callback)
{
	return srv_prof_play_tone_with_id((srv_prof_tone_enum)tone_type, audio_id, (srv_prof_ring_type_enum)play_type, callback);
}
gs_srv_prof_ret CALLCC ProfileService::playToneWithFullStruct(gs_srv_prof_play_req_struct* play_struct)
{
	return srv_prof_play_tone_with_full_struct((srv_prof_play_req_struct*)play_struct);
}

gs_srv_prof_ret CALLCC ProfileService::playToneWithText(gs_srv_prof_tone_enum tone_type, U8* text, S32 text_speed, gs_srv_prof_play_tone_callback callback)
{
	return srv_prof_play_tone_with_text((srv_prof_tone_enum)tone_type, text, text_speed, callback);
}

MMI_BOOL CALLCC ProfileService::isSettingAvailable(gs_srv_prof_settings_enum setting)
{
	return srv_prof_is_setting_available((srv_prof_settings_enum)setting);
}
void CALLCC ProfileService::stopTone(gs_srv_prof_tone_enum tone_type)
{
	srv_profiles_stop_tone((srv_prof_tone_enum)tone_type);
}

MMI_BOOL CALLCC ProfileService::isTonePlaying(gs_srv_prof_tone_enum tone_type)
{
	return srv_prof_is_tone_playing((srv_prof_tone_enum)tone_type);
}

U8 CALLCC ProfileService::getProfileCount()
{
	return srv_prof_get_num_of_profiles();
}


