/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 *  vadp_v2p_widget_profile.c
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions from the Venus MMI to the Pluto
 *  MMI.
 *
 *      Venus APP ---> v2p adaptor ---> Pluto APP
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/ 
#include "MMI_features.h"
#ifdef __MMI_VUI_HOMESCREEN_PROFILE__
/* Pluto headers: */
//#include "MMI_include.h"
#include "MMIDataType.h"

#include "ProfilesAppGprot.h"

/* Venus headers: */
#include "HomeScreen\vadp_v2p_widget_profile.h"

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_profile_set_activated_profile
 * DESCRIPTION
 *  activate profile
 * PARAMETERS
 *  currentProfile      : [IN]  the profile which need to activate
 * RETURNS
 *  return 0 : success; return -1: fail
 *****************************************************************************/
S32 vadp_v2p_profile_set_activated_profile(U8 currentProfile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (currentProfile)
    {
        case GENERAL_PROFILE:
            currentProfile = MMI_PROFILE_GENERAL;
            break;
        case MEETING_PROFILE:
            currentProfile = MMI_PROFILE_MEETING;
            break;
        case OUTDOOR_PROFILE:
            currentProfile = MMI_PROFILE_OUTDOOR;
            break;
    #if !defined(__MMI_BASIC_UI_STYLE__) && !defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
        case MYSTYLE_PROFILE:
            currentProfile = MMI_PROFILE_MY_STYLE;
            break;
    #endif
        case SILENT_PROFILE:
            currentProfile = MMI_PROFILE_SILENT;
            break;
        default:
            return -1;
    }
	if (currentProfile != srv_prof_get_activated_profile())
	{
        srv_prof_activate_profile(currentProfile);
	}
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_profile_get_activated_profile
 * DESCRIPTION
 *  get activated profile
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 vadp_v2p_profile_get_activated_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 activatedProfile;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (srv_prof_get_activated_profile())
    {
        case MMI_PROFILE_GENERAL:
            activatedProfile = GENERAL_PROFILE;
            break;
        case MMI_PROFILE_MEETING:
            activatedProfile = MEETING_PROFILE;
            break;
        case MMI_PROFILE_OUTDOOR:
            activatedProfile = OUTDOOR_PROFILE;
            break;
        case MMI_PROFILE_SILENT:
            activatedProfile = SILENT_PROFILE;
            break;
    #if !defined(__MMI_BASIC_UI_STYLE__) && !defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
        case MMI_PROFILE_MY_STYLE:
            activatedProfile = MYSTYLE_PROFILE;
            break;
    #endif
        default:
            activatedProfile = GENERAL_PROFILE;
            break;
    }
    return activatedProfile;
}

#endif /* __MMI_VUI_HOMESCREEN_PROFILE__*/
