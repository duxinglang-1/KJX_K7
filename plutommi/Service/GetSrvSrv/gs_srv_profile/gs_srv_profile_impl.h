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
*   gs_srv_profile_impl.h
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   Class header file
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
#ifndef _GS_SRV_PROFILE_IMPL_H
#define _GS_SRV_PROFILE_IMPL_H

#include "gs_id.h"
#include "gs_base.h"
#include "gs_cbase.h"

#define GS_GEN_INTERFACE
#include "gs_srv_profile_interface_def.h"

class ProfileService : public GS_CBase, public IProfile
{

public:
	ProfileService(U32 handle);

	/* Common API */
	virtual S32 CALLCC addRef()
	{
		return GS_CBase::addRef();
	}
	virtual S32 CALLCC release()
	{
		return GS_CBase::release();
	}
	virtual S32 CALLCC queryInterface(S32 iid, GS_IBase **pptr);

	/* Functional API */
	virtual gs_srv_prof_ret CALLCC active(gs_srv_prof_external_profile_enum profile);

	virtual gs_srv_prof_ret CALLCC deactive(gs_srv_prof_external_profile_enum profile);



	virtual gs_srv_prof_ret CALLCC getCurrentProfileValue(gs_srv_prof_settings_enum setting, void* value);

	virtual gs_srv_prof_ret CALLCC setCurrentProfileValue(gs_srv_prof_settings_enum setting, void* value);

	virtual gs_srv_prof_ret CALLCC isProfileActivated(gs_srv_prof_external_profile_enum profile);

	virtual MMI_BOOL CALLCC ifCanRing();

	virtual MMI_BOOL CALLCC ifCanVibrate();


	// new added
	virtual gs_srv_prof_ret CALLCC playTone(gs_srv_prof_tone_enum tone_type, gs_srv_prof_play_tone_callback callback);

	virtual gs_srv_prof_ret CALLCC playToneWithId(gs_srv_prof_tone_enum tone_type, U16 audio_id, gs_srv_prof_ring_type_enum play_type, gs_srv_prof_play_tone_callback callback);

	virtual gs_srv_prof_ret CALLCC playToneWithFullStruct(gs_srv_prof_play_req_struct* play_struct);


	virtual gs_srv_prof_ret CALLCC playToneWithText(gs_srv_prof_tone_enum tone_type, U8* text, S32 text_speed, gs_srv_prof_play_tone_callback callback);


	virtual MMI_BOOL CALLCC isSettingAvailable(gs_srv_prof_settings_enum setting);
	virtual void CALLCC stopTone(gs_srv_prof_tone_enum tone_type);
	virtual MMI_BOOL CALLCC isTonePlaying(gs_srv_prof_tone_enum tone_type);
	virtual U8 CALLCC getProfileCount();




};

#endif /* _PROFILE_INTERFACE_ */ 

