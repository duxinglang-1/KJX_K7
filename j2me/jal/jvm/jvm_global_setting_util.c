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
 * jam_global_setting_util.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

/*************************************************************************
 * Include header files
 *************************************************************************/
#include "kal_release.h"
/*************************************************************************
 * Plutommi include header files
 *************************************************************************/
#include "stdC.h"
#include "mmi_platform.h"
#include "MMIDataType.h"
#include "MMI_Features.h"
#include "mdi_datatype.h"
#include "Mdi_audio.h"
#include "j2me_custom_option.h"
#include "j2me_trace.h"
#include "jvm_interface.h"
#include "jnw_interface.h"
#include "jam_interface.h"
#include "jma_interface.h"
#include "browser_struct.h"
#include "wap_ps_struct.h"
#include "wapadp.h"
#include "cbm_api.h"
#include "profile_struct.h"
#include "ProfilesSrvGprot.h"
/****************
 *  Global setting variable
 ***********************************************/
extern U8 g_mmi_java_aud_volume_level;
extern U8 g_mmi_java_is_vib_on;
extern U8 g_mmi_java_is_net_icon_on;
extern U8 g_mmi_java_app_id;
extern U8 g_mmi_java_install_app_id;
extern U8 g_mmi_java_vk_permission;
extern U8 g_mmi_java_bk_light;

extern void mdi_audio_set_volume(U8 type, U8 volume);
extern void jvm_force_backlight_on(kal_bool force_on);
extern wap_get_prof_content_rsp_struct wap_prof;
extern wap_get_bra_prof_id_rsp_struct wap_bra_prof;
extern srv_prof_volume_level srv_prof_get_ring_vol(void);

extern kal_uint32 J2ME_active_nw_acc_id[MAX_VM_INSTANCE_NUM];
extern kal_uint32 J2ME_active_nw_acc_id_CSD;
extern kal_uint32 J2ME_current_active_nw_id;

#ifdef __MMI_FOURWAYS_KEY_DISABLE__
/*****************************************************************************
 * FUNCTION
 *  jam_get_vk_permission
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_uint8 jam_get_vk_permission(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_java_vk_permission;
}

#endif /* __MMI_FOURWAYS_KEY_DISABLE__ */

/*****************************************************************************
 * FUNCTION
 *  jam_set_bk_status
 * DESCRIPTION
 *
 * PARAMETERS
 *  level       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_set_bk_status(kal_bool status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(status)    
    {
        jvm_force_backlight_on(KAL_TRUE);
    }
    else
    {
        jvm_force_backlight_on(KAL_FALSE);
    }
}
/*****************************************************************************
 * FUNCTION
 *  jam_set_aud_volume_level
 * DESCRIPTION
 *
 * PARAMETERS
 *  level       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_set_aud_volume_level(kal_int8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __PLUTO_MMI_PACKAGE__
    if (level > 7)
    {
        g_mmi_java_aud_volume_level = 7;
    }
    #elif defined(__COSMOS_MMI_PACKAGE__)
    if (level > 16)
    {
        g_mmi_java_aud_volume_level = 16;
    } 
    #endif
    else if (level < 0)
    {
        g_mmi_java_aud_volume_level = 0;
    }
    else
    {
        g_mmi_java_aud_volume_level = level;
    }
    #ifdef __PLUTO_MMI_PACKAGE__
    mdi_audio_set_volume((U8)MDI_VOLUME_MEDIA, (U8)(MDI_AUD_VOL_MUTE(g_mmi_java_aud_volume_level)));
    #elif defined(__COSMOS_MMI_PACKAGE__)
    mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX_MUTE(g_mmi_java_aud_volume_level));
    #endif

}


/*****************************************************************************
 * FUNCTION
 *  jam_get_aud_volume_level
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_uint8 jam_get_aud_volume_level(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_java_aud_volume_level;
}


/*****************************************************************************
 * FUNCTION
 *  jam_get_ring_volume_level
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_uint8 jam_get_ring_volume_level(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint8) srv_prof_get_ring_vol();
}


/*****************************************************************************
 * FUNCTION
 *  jam_press_dec_volume
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
void jam_press_dec_volume_level(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jam_set_aud_volume_level((U8)(g_mmi_java_aud_volume_level-1));
}
/*****************************************************************************
 * FUNCTION
 *  jam_press_inc_volume
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
void jam_press_inc_volume_level(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jam_set_aud_volume_level((U8)(g_mmi_java_aud_volume_level+1));
}


#ifdef __BT_SPK_VOL_CONTROL__
/*****************************************************************************
 * FUNCTION
 *  jam_bt_volume_sync_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL jam_bt_volume_sync_hdlr(U8 volume, MMI_BOOL is_mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    kal_trace(TRACE_FUNC, JAM_BT_VOLUME_SYNC_HDLR, volume, is_mute);  
    /* (1) java is foreground running. --> Always return true.
       (2) java is not foreground running --> return true if java audio is occupying resource */
    if (jam_mvm_get_vm_state(0) == JVM_FG_RUNNING_STATE || jma_audio_player_is_really_active())
    {
        jam_set_aud_volume_level(volume);
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE; 
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  jam_get_vib_on
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_uint8 jam_get_vib_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_java_is_vib_on;
}

/*****************************************************************************
 * FUNCTION
 *  jam_get_app_id
 * DESCRIPTION
 *  wrap for Installer and Midlet.
 *  return Installer App_id or Midlet App_id
 * PARAMETERS
 *  kal_uint8
 * RETURNS
 *****************************************************************************/
kal_uint8 jam_get_app_id(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(vm_id == J2ME_HTTP_INSTALL_APP_ID)
    	return g_mmi_java_install_app_id;
	else
    	return g_mmi_java_app_id;
}

/*****************************************************************************
 * FUNCTION
 *  jam_get_net_icon_setting
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  0: turn off
 *  1: turn on
 *  default: 1
 *****************************************************************************/
kal_uint8 jam_get_net_icon_setting(void)
{
#ifdef SUPPORT_JAVA_NET_ICON_SETTING
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    return 1;
#endif
}


