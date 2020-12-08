/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  DialerCuiCommon.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the common component of the dialer CUI.
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
 *
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

/****************************************************************************
 * Include
 ****************************************************************************/

#include "kal_general_types.h"
#include "MMIDataType.h"
#include "DialerCuiProt.h"
#include "UcmSrvGprot.h"
#include "UcmGprot.h"
#include "MenuCuiGprot.h"
#include "SimCtrlSrvGprot.h"
#include "SmsGuiInterfaceProt.h"    /* DialVoiceMail */
#include "PhoneBookSpeedDial.h"
#include "PhoneBookGprot.h"
#include "PhbCuiGprot.h"
#include "SearchWebGprot.h"
#include "custom_ecc.h"
#include "ProfilesSrvGprot.h"
#include "ProfilesAppGprot.h"
#include "NwUsabSrvGprot.h"
#include "Unicodexdcl.h"
#include "DialerCuiObject.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "wgui_categories_idlescreen_op.h"
#include "DialerCuiMain.h"
#include "mmi_frm_scenario_gprot.h"
#include "AlertScreen.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_util.h"
#include "DialerCuiGprot.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalConstants.h"
#include "mmi_rp_cui_dialer_def.h"
#include "custom_phb_config.h"
#include "IdleAppDef.h"
#include "SSCGprot.h"
#include "GlobalResDef.h"
#include "MessagesMiscell.h"
#include "wgui_categories_CM.h"
#include "wgui_inputs.h"
#include "DialerCuiCommon.h"
#include "mmi_rp_menu_misc_def.h"    /* MENU_GROUP_EDITOR */
#ifdef __GENERAL_TTS__
#include "Gpiosrvgprot.h"
#include "mdi_audio.h"
#include "resource_audio.h"
#endif
#ifdef __OP01_FWPBW__
#include "CallLogGprot.h"
#include "PhbSrvGprot.h"
#endif
#if defined(__MMI_SEARCH_WEB__)
#include "IdleGprot.h"
#endif

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
#include "NetsetAppGprot.h"
#endif

#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
#ifdef __MMI_3G_SWITCH__
#include "NetSetSrvGprot.h"
#endif
#endif

/****************************************************************************
 * Extern Context
 ****************************************************************************/
#if defined(__GENERAL_TTS__) 
extern sLanguageDetails  *gLanguageArray;
extern U16  gCurrLangIndex;
#endif

/****************************************************************************
 * Global Context
 ****************************************************************************/
#if defined(__GENERAL_TTS__)
typedef struct
{
    MMI_BOOL is_enable;
} cui_dialer_tts_cntx_struct;

static cui_dialer_tts_cntx_struct g_cui_tts_cntx;
#endif



/****************************************************************************
 * Define
 ****************************************************************************/

/* Max string length of the abbreviation dial (or called SIM dial). */
#define CUI_DIALER_MAX_ABBREV_STR_LEN       (3)

/* Macro to get the size of an array. */
#define CUI_DIALER_GET_SIZE(x)              (sizeof(x) / sizeof(x[0]))

#if defined(__GENERAL_TTS__)
/* Macro to define the voice language tag  */
#define MMI_DIALER_DEFAULT_LANGUAGE_TAG  L"[g1]"
#define MMI_DIALER_ENGLISH_LANGUAGE_TAG  L"[g2]"
#endif

/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_is_ecc
 * DESCRIPTION
 *  This function checks if the dial string is an emergency number.
 * PARAMETERS
 *  dial_string             : [IN]          Dial string
 * RETURNS
 *  ecc_verify_detail_enum
 *****************************************************************************/
ecc_verify_detail_enum cui_dialer_is_ecc(const WCHAR *dial_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 verify_detail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ecc_custom_verify_emergency_number(
        (kal_uint8 *)dial_string,
        (kal_uint8)mmi_wcslen(dial_string),
        ECC_ENCODING_UCS2,
        ECC_ALL_CALL,
        NULL,
        NULL,
        &verify_detail);

    return (ecc_verify_detail_enum)verify_detail;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_is_long_press_enable
 * DESCRIPTION
 *  This function checks if the functions coupled with the LONG-PRESS event
 *  (e.g. toggle the profile or speed dial) are enable.
 * PARAMETERS
 *  obj                 : [IN]                  Object
 * RETURNS
 *  On enable, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL cui_dialer_is_long_press_enable(cui_dialer_obj_struct *obj)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*
     * Only launch when the dial pad is empty and the user presses and holds the
     * key to input the first digit.
     */

#if defined(__MMI_DIALER_SEARCH__) && !defined(__MMI_FTE_SUPPORT__)
    if (wgui_cat203_is_vk_input())
    {
        return (mmi_wcslen(obj->dial_string) == 0) ? MMI_TRUE : MMI_FALSE;
    }
    else
#endif
    {
        return (mmi_wcslen(obj->dial_string) == 1) ? MMI_TRUE : MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_is_digit
 * DESCRIPTION
 *  This function checks if the character is a digital character.
 * PARAMETERS
 *  c           : [IN]      Character
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL cui_dialer_is_digit(WCHAR c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (c >= L'0' && c <= L'9') ? MMI_TRUE : MMI_FALSE;
}


#if defined(__GENERAL_TTS__)

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_tts_play_callback
 * DESCRIPTION
 *  This callback function will hanle exception
 * PARAMETERS
 *  srv_prof_ret                   
 * RETURNS
 *  void.
 *****************************************************************************/
srv_prof_ret cui_dialer_tts_play_callback(srv_prof_ret result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return SRV_PROF_RET_NO;
}

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_tts_report
 * DESCRIPTION
 *  This function will read key code for user
 * PARAMETERS
 *  void           
 * RETURNS
 *  void.
 *****************************************************************************/
 void cui_dialer_do_tts_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_tts_cntx_struct *cntx = &g_cui_tts_cntx;
	srv_prof_play_req_struct play_req;
    cui_dialer_obj_struct *obj;
	U8 audio_mode;
	WCHAR *dial_string_ptr;
	WCHAR tts_buf[8] = {'\0','\0','\0','\0','\0','\0','\0','\0'};

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
#ifdef IFLY_TTS
	if (!strcmp((CHAR *) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_ENGLISH))
	{
	    mmi_wcscpy(
			(tts_buf),
			MMI_DIALER_ENGLISH_LANGUAGE_TAG);
	}
	else
	{
	    mmi_wcscpy(
			(tts_buf),
			MMI_DIALER_DEFAULT_LANGUAGE_TAG);
	}
#else
	mmi_wcscpy(
		  (tts_buf),
		  MMI_DIALER_DEFAULT_LANGUAGE_TAG);
#endif 

    obj = cui_dialer_get_obj_from_group();
    MMI_ASSERT(obj);
	
	dial_string_ptr = &(obj->dial_string[mmi_wcslen(obj->dial_string) - 1]);
	mmi_wcscat(tts_buf, dial_string_ptr);		
	
    if(cntx->is_enable)
    {

		if(srv_prof_is_tone_playing(SRV_PROF_TONE_SMS))         
    	{
    		srv_prof_stop_tone(SRV_PROF_TONE_SMS);
    	}
		if(srv_prof_is_tone_playing(SRV_PROF_TONE_MMS))         
    	{
    	    srv_prof_stop_tone(SRV_PROF_TONE_MMS);
    	}
    	if(srv_prof_is_tone_playing(SRV_PROF_TONE_VOICE))
    	{
            srv_prof_stop_tone(SRV_PROF_TONE_VOICE);	
    	}	
        
        srv_prof_play_req_struct_init(&play_req, SRV_PROF_TONE_DIALER);

		audio_mode = mdi_audio_get_audio_mode();
        
        play_req.aud_path = (audio_mode == AUD_MODE_LOUDSPK) ? MDI_DEVICE_LOUDSPEAKER : MDI_DEVICE_SPEAKER;

	#ifdef __OP01_FWPBW__ 			
		if (srv_gpio_transmitter_is_hold_on())
		{
			play_req.aud_path = MDI_DEVICE_SPEAKER;	
		}
		else
		{
			play_req.aud_path = MDI_DEVICE_LOUDSPEAKER;
		}
	#endif
		
		play_req.text = (U8 *)tts_buf;
        play_req.audio_type = SRV_PROF_AUDIO_TEXT;
        play_req.play_style = SRV_PROF_RING_TYPE_ONCE;
	    play_req.volume = 3;
        srv_prof_play_tone_with_full_struct(&play_req);
        
    }  
    
}

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_read_tts_setting
 * DESCRIPTION
 *  This function will read voice report setting from nvram
 * PARAMETERS
 *  error_code           : [IN/OUT]
 * RETURNS
 *  U8.
 *****************************************************************************/
U8 cui_dialer_read_tts_setting(S16* error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    ReadValue(NVRAM_IDLE_DIALER_TTS_SETTING, &setting, DS_BYTE, error_code);
    
    return setting;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_write_tts_setting
 * DESCRIPTION
 *  This function will write voice report setting to nvram
 * PARAMETERS
 *  setting         : [IN]
 * RETURNS
 *  void.
 *****************************************************************************/
static void cui_dialer_write_tts_setting(U8 setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    WriteValue(NVRAM_IDLE_DIALER_TTS_SETTING, &setting, DS_BYTE, &err);
    
}

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_save_tts_setting
 * DESCRIPTION
 *  This function will save voice report setting
 * PARAMETERS
 *  MMI_BOOL           : [IN]
 * RETURNS
 *  void.
 *****************************************************************************/
void cui_dialer_save_tts_setting(MMI_BOOL is_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 setting;
    cui_dialer_tts_cntx_struct *cntx = &g_cui_tts_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    setting = (is_on ? 0x01: 0x00);
    if(is_on)
    {
        cntx->is_enable = MMI_TRUE;
    }
    else
    {
        cntx->is_enable = MMI_FALSE;
    }

    cui_dialer_write_tts_setting(setting);   
}

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_get_tts_setting
 * DESCRIPTION
 *  This function will read voice report setting from nvram during init proc.
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_get_tts_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 err;
    U8  setting;
    cui_dialer_tts_cntx_struct *cntx = &g_cui_tts_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting = cui_dialer_read_tts_setting(&err);
    
    if(err != NVRAM_READ_SUCCESS)
    {
        cntx->is_enable = MMI_TRUE;  
    }
    else
    {
        cntx->is_enable = (setting? MMI_TRUE: MMI_FALSE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_is_tts_enable
 * DESCRIPTION
 *  This function will judge if voice report is enable in dialer.
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL cui_dialer_is_tts_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_tts_cntx_struct *cntx = &g_cui_tts_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return cntx->is_enable;  
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_tts_setting_group_proc
 * DESCRIPTION
 *  This proc function which handle menu cui.
 * PARAMETERS
 *  mmi_event_struct          : [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret cui_dialer_tts_setting_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        {
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        { 
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
            if(menu_evt->highlighted_menu_id == MENU_ID_CUI_DIALER_TTS_ON)
            {
                cui_dialer_save_tts_setting(MMI_TRUE);                
                cui_menu_close(menu_evt->sender_id);
                
            }
            else if(menu_evt->highlighted_menu_id == MENU_ID_CUI_DIALER_TTS_OFF)
            {
                cui_dialer_save_tts_setting(MMI_FALSE);                
                cui_menu_close(menu_evt->sender_id);
            }
            else
            {
                return MMI_RET_DONT_CARE;
            }
            return MMI_RET_OK;
            break;   
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
            cui_menu_close(menu_evt->sender_id);
            return MMI_RET_OK;
            break;
        }
        default:
            break;    
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_entry_tts_setting_menu
 * DESCRIPTION
 *  This function will show the menu.
 * PARAMETERS
 *  void       
 * RETURNS
 *  void.
 *****************************************************************************/
void cui_dialer_entry_tts_setting_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_tts_cntx_struct *cntx = &g_cui_tts_cntx;
    mmi_id menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    menu_gid = cui_menu_create(
                   GRP_ID_CUI_DIALER_TTS_SETTING,
                   CUI_MENU_SRC_TYPE_RESOURCE,
                   CUI_MENU_TYPE_FROM_RESOURCE,
                   MENU_ID_CUI_DIALER_TTS_SETTING,
                   MMI_FALSE, 
                   NULL);

    cui_menu_set_currlist_left_softkey(
        menu_gid, 
        (WCHAR*)get_string(STR_GLOBAL_SELECT));
    
    cui_menu_set_currlist_right_softkey(
        menu_gid, 
        (WCHAR*)get_string(STR_GLOBAL_BACK));

    if(cntx->is_enable)
    {
        cui_menu_set_currlist_highlighted_id(
            menu_gid, 
            MENU_ID_CUI_DIALER_TTS_ON);   
    }
    else
    {
        cui_menu_set_currlist_highlighted_id(
            menu_gid, 
            MENU_ID_CUI_DIALER_TTS_OFF);      
    } 
    
	cui_menu_run(menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_entry_tts_setting
 * DESCRIPTION
 *  This function will entry voice report setting scrn
 * PARAMETERS
 *  void          
 * RETURNS
 *  void.
 *****************************************************************************/
void cui_dialer_entry_tts_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id this_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    this_gid = mmi_frm_group_get_active_id();
    mmi_frm_group_create(this_gid, GRP_ID_CUI_DIALER_TTS_SETTING, cui_dialer_tts_setting_group_proc, NULL);
    mmi_frm_group_enter(GRP_ID_CUI_DIALER_TTS_SETTING, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_dialer_entry_tts_setting_menu();  
}

#endif 
/*****************************************************************************
 * FUNCTION
 *  cui_dialer_copy_before
 * DESCRIPTION
 *  This function copies at most 'len' digits from the 'src' to 'dst'. In
 *  addition, the ended character before the digits should be 'c'.
 * PARAMETERS
 *  src           : [IN]
 *  len           : [IN]
 *  dst           : [IN]
 *  c           : [IN]
 * RETURNS
 *  Please check the comment in the function.
 *****************************************************************************/
static MMI_BOOL cui_dialer_copy_before(WCHAR *dst, WCHAR *src, S32 len, WCHAR c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < len && cui_dialer_is_digit(src[i]); i++)
    {
        dst[i] = src[i];
    }

    dst[i] = 0; /* null-terminated */

    /*
     * 1) 'src' is parsed until the specified char.
     *
     * 2) 'src' has no other char in the end. This is to avoid the situation,
     *    for example, let len = 3 and c = #,
     *
     *      User inputs the string 12345#. This string returns MMI_FALSE.
     *      User modifies the string 123#45#.
     *
     * 3) 'dst' should not be empty string.
     */
    if (src[i] == c && src[i + 1] == 0 && mmi_wcslen(dst) > 0)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_after_make_call_hdlr
 * DESCRIPTION
 *  This function is the make call callback.
 * PARAMETERS
 *  p           : [IN]          Callback parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_after_make_call_hdlr(mmi_ucm_after_make_call_cb_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(p && p->user_data);

    obj = p->user_data;

    /*
     * If the user presses "Back" on the SIM selection screen, go back to the
     * dialer; otherwise, go back to the idle screen.
     */
#ifdef __OP01_FWPBW__
    if (obj->type == CUI_DIALER_TYPE_BWT && p->result == SRV_UCM_RESULT_OK)
    {
        cui_dialer_bwt_struct *bwt_obj = (cui_dialer_bwt_struct *)obj;
        bwt_obj->is_can_close = MMI_TRUE;
        cui_dialer_emit_close_req(obj);
        return;
    }
#endif
    if (p->result != SRV_UCM_RESULT_CANCEL
#ifdef __OP01_FWPBW__
	    && obj->type != CUI_DIALER_TYPE_BWT
#endif
	)
    {
        cui_dialer_emit_close_req(obj);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_get_obj_from_group
 * DESCRIPTION
 *  This function gets the dialer object from the active group.
 * PARAMETERS
 *  void
 * RETURNS
 *  Dialer object.
 *****************************************************************************/
cui_dialer_obj_struct *cui_dialer_get_obj_from_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id group_id;
    cui_dialer_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_id = mmi_frm_group_get_active_id();

    obj = (cui_dialer_obj_struct *)mmi_frm_group_get_user_data(group_id);

    MMI_ASSERT(obj);

    return obj;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_display_popup
 * DESCRIPTION
 *  This function displays a error popup.
 * PARAMETERS
 *  str_id          : [IN]          String ID
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_display_popup(U16 str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_property_init(&param);
    mmi_popup_display((WCHAR *)get_string(str_id), MMI_EVENT_FAILURE, &param);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_call_launch
 * DESCRIPTION
 *  This function launches the call.
 * PARAMETERS
 *  obj                 : [IN]              Object
 *  param               : [IN]              Make call parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_call_launch(
    cui_dialer_obj_struct *obj,
    mmi_ucm_make_call_para_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj && param);

    /*
     * For SOS dialer, we can only dial emergency call.
     */
    if (obj->type == CUI_DIALER_TYPE_SOS &&
        cui_dialer_is_ecc(obj->dial_string) != ECC_FULLY_MATCH)
    {
        cui_dialer_display_popup(
            srv_ucm_query_error_message(SRV_UCM_RESULT_SOS_NUMBER_ONLY));

        cui_dialer_emit_close_req(obj); /* close dialer */

        return;
    }

    /*
     * Notify APP that dialer will launch call immediately.
     */
    cui_dialer_emit_before_call_launched(obj);

    /*
     * Setup common parameter to launch call.
     */
    param->ucs2_num_uri                      = (PU16)obj->dial_string;
    param->adv_para.phb_data                 = obj->phb_data;
    param->adv_para.after_make_call_callback = cui_dialer_after_make_call_hdlr;
    param->adv_para.after_callback_user_data = obj;

    /*
     * Launch call.
     */
    mmi_ucm_call_launch(obj->this_gid, param);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_close
 * DESCRIPTION
 *  This function closes the dialer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_do_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = cui_dialer_get_obj_from_group();

    cui_dialer_emit_close_req(obj);
}


#if defined(__MMI_SEARCH_WEB__)
/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_baidu_search
 * DESCRIPTION
 *  This function launch the baidu search.
 *
 *  TODO 1: Baidu Search does not support multiple instance.
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_do_baidu_search(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = cui_dialer_get_obj_from_group();

    if (!cui_dialer_is_long_press_enable(obj))
    {
        return;
    }

    /*
     * The UE design of Baidu Search, launched from dialer, requires the handset
     * uses the idle screen as the background. Thus, we should first display
     * idle screen then launch the Baidu Search.
     */
    mmi_idle_display();

    mmi_search_web_trigger_by_long_pressing_star();
}
#endif /* defined(__MMI_SEARCH_WEB__) */


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_toggle_silent_profile
 * DESCRIPTION
 *  Toggles profiles between silent mode and current activated profile on long press of # key.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_do_toggle_silent_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;
    srv_prof_ret prof_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = cui_dialer_get_obj_from_group();

    if (!cui_dialer_is_long_press_enable(obj))
    {
        return;
    }

    prof_ret = srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE);
    if (prof_ret == SRV_PROF_RET_PROFILE_ACTIVATED)
    {
        mmi_prof_deactivate_silent_profile(MMI_TRUE);
    }
    else
    {
        mmi_prof_activate_profile(MMI_PROFILE_SILENT, MMI_TRUE);
    }

    cui_dialer_emit_close_req(obj); /* close dialer */
}

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
/*****************************************************************************
 * FUNCTION
 *  cui_dialer_set_sim_menu_string
 * DESCRIPTION
 *  Set sim menu string.
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
void cui_dialer_set_sim_menu_string(mmi_id owner_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_sim_enum sim_id;
	WCHAR menu_str[MAX_SUBMENU_CHARACTERS];
	U16 menu_string[] = {
#if (MMI_MAX_SIM_NUM >= 2)
        STR_ID_CUI_DIALER_CALL_FROM_SIM1,
        STR_ID_CUI_DIALER_CALL_FROM_SIM2,
#if (MMI_MAX_SIM_NUM>=3)
        STR_ID_CUI_DIALER_CALL_FROM_SIM3,
#if (MMI_MAX_SIM_NUM>=4)
        STR_ID_CUI_DIALER_CALL_FROM_SIM4,
#endif /* (MMI_MAX_SIM_NUM >= 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */
        };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(srv_sim_ctrl_get_num_of_inserted() <= 1)
    {
    	return;
    }
	
    for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
    {   
        if (srv_sim_ctrl_is_inserted(sim_id) && mmi_netset_get_sim_name(sim_id) != NULL)
        {
            kal_wsprintf(menu_str, "%w(%w)", GetString(menu_string[i]), mmi_netset_get_sim_name(sim_id));
            cui_menu_set_item_string(owner_gid, MENU_ID_CUI_DIALER_CALL_FROM_SIM1 + i, menu_str);
        }  
    }

}
#endif 
#if  defined(__MMI_DIALER_DYNAMIC_CALL_UI__) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
/*****************************************************************************
 * FUNCTION
 *  cui_dialer_index_to_ucm_type
 * DESCRIPTION
 *  Convert index to ucm type.
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_ucm_call_type_enum
 *****************************************************************************/
static srv_ucm_call_type_enum cui_dialer_index_to_ucm_type(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_ucm_call_type_enum ucm_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(index)
	{
		case 0:
			ucm_type = SRV_UCM_VOICE_CALL_TYPE;
			break;
		case 1:
			ucm_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
			break;
		case 2:
			ucm_type = SRV_UCM_VOICE_CALL_TYPE_SIM3;
			break;
		case 3:
			ucm_type = SRV_UCM_VOICE_CALL_TYPE_SIM4;
			break;
		default:
			ucm_type = SRV_UCM_VOICE_CALL_TYPE_ALL;
			break;
	}
		
	return ucm_type;
}

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_get_avaliable_sim_number
 * DESCRIPTION
 *  This function is used to get the avaliable sim number.
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 cui_dialer_get_available_sim_number()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i;
	S32 ucm_count = 0;
	S32 real_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*Use srv_sim_ctrl_is_inserted() to judge whether the simcard number is 0 or not.
	We can not always use srv_ucm_is_call_srv_available(), because if no sim card, may UCM is
	available*/
	for(i = 0; i < MMI_SIM_TOTAL; i++)
	{
		if (srv_ucm_is_call_srv_available(cui_dialer_index_to_ucm_type(i)))
		{
			ucm_count++;
		}
	}
	
	if(srv_sim_ctrl_get_num_of_inserted() == 0)
	{
		real_count = 0;
	}
	else
	{
		real_count = ucm_count;
	}

	return real_count;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_is_emergency_call_only
 * DESCRIPTION
 *  This function is used to check if only ecc call can dial.
 * PARAMETERS
 *  void 
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL cui_dialer_is_emergency_call_only(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return (MMI_BOOL)(srv_sim_ctrl_get_num_of_inserted() == 0);
}

#ifdef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__
void cui_dialer_set_dynamic_sim_hdlr(FuncPtr sim_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	SetDialingKeypadCallHandler(sim_func);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_sim_select_call
 * DESCRIPTION
 *  This function is used to call after select sim card.
 * PARAMETERS
 *  srv_ucm_call_type_enum 
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_do_sim_select_call(srv_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
#ifdef __MMI_DIALER_SEARCH__
	if (!wgui_cat203_is_editor_active())
    {
        mmi_phb_ds_sendkey_call_pre_entry(call_type);
    }
	else
#endif
	{
		if (call_type == SRV_UCM_VOICE_CALL_TYPE)
		{
			cui_dialer_do_key_dial_by_type(CUI_DIALER_SIM1);
		}

		else if(call_type == SRV_UCM_VOICE_CALL_TYPE_SIM2)
		{
			cui_dialer_do_key_dial_by_type(CUI_DIALER_SIM2);
		}
			
		else if(call_type == SRV_UCM_VOICE_CALL_TYPE_SIM3)
		{
			cui_dialer_do_key_dial_by_type(CUI_DIALER_SIM3);
		}

		else if(call_type == SRV_UCM_VOICE_CALL_TYPE_SIM4)
		{
			cui_dialer_do_key_dial_by_type(CUI_DIALER_SIM4);
		}
		else if(call_type == SRV_UCM_VOICE_CALL_TYPE_ALL)
		{
			cui_dialer_do_key_dial_by_type(CUI_DIALER_ALL);
		}
	}

}

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_entry_sim_select_proc
 * DESCRIPTION
 *  This function is the proc func of select sim.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret cui_dialer_entry_sim_select_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	switch(evt->evt_id)
	{
		case EVT_ID_GROUP_ACTIVE:
		{
			break;
		}
		case EVT_ID_CUI_MENU_ITEM_SELECT:
		{
			cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
		#if MMI_MAX_SIM_NUM >= 2	
			if (menu_evt->highlighted_menu_id == MENU_ID_CUI_DIALER_CALL_FROM_SIM1)
			{
				cui_menu_close(menu_evt->sender_id);
				cui_dialer_do_sim_select_call(SRV_UCM_VOICE_CALL_TYPE);
			}	
			else if (menu_evt->highlighted_menu_id == MENU_ID_CUI_DIALER_CALL_FROM_SIM2)
			{
				cui_menu_close(menu_evt->sender_id);
				cui_dialer_do_sim_select_call(SRV_UCM_VOICE_CALL_TYPE_SIM2);
			}
		#if MMI_MAX_SIM_NUM >= 3	
			else if (menu_evt->highlighted_menu_id == MENU_ID_CUI_DIALER_CALL_FROM_SIM3)
			{
				cui_menu_close(menu_evt->sender_id);
				cui_dialer_do_sim_select_call(SRV_UCM_VOICE_CALL_TYPE_SIM3);
			}
		#if MMI_MAX_SIM_NUM >= 4
			else if (menu_evt->highlighted_menu_id == MENU_ID_CUI_DIALER_CALL_FROM_SIM4)
			{
				cui_menu_close(menu_evt->sender_id);
				cui_dialer_do_sim_select_call(SRV_UCM_VOICE_CALL_TYPE_SIM4);
			}
		#endif
		#endif
		#endif
			break;
		}
	#ifdef 	__MMI_DYNAMIC_SIM_DYNAMIC_UI__
		case EVT_ID_CUI_MENU_LIST_ENTRY:	
		{
			cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
			cui_dialer_set_sim_menu_string(menu_evt->sender_id);
            break;
		}	
	#endif	
		case EVT_ID_CUI_MENU_CLOSE_REQUEST:
		{
			cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
			cui_menu_close(menu_evt->sender_id);
			break;
		}
		default:
			break;	
	}
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_create_sim_select_menu
 * DESCRIPTION
 *  Create sim selected menu cui.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_create_sim_select_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_ucm_call_type_enum ucm_type;
	mmi_id menu_id;
	U32 i;	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	menu_id = cui_menu_create(
					GRP_ID_SIM_SELECT,
					CUI_MENU_SRC_TYPE_RESOURCE,
					CUI_MENU_TYPE_OPTION,
					MENU_ID_CUI_DIALER_SIM_SELECT_MENU,
					MMI_TRUE,
					NULL);

	for (i = 0; i < MMI_MAX_SIM_NUM; i++)
	{
	
		ucm_type = cui_dialer_index_to_ucm_type(i);
		
		if (srv_ucm_is_call_srv_available(ucm_type))
		{
			cui_menu_set_item_hidden(menu_id, (mmi_menu_id)MENU_ID_CUI_DIALER_CALL_FROM_SIM1 + i, MMI_FALSE);
		}
		else
		{
			cui_menu_set_item_hidden(menu_id, (mmi_menu_id)MENU_ID_CUI_DIALER_CALL_FROM_SIM1 + i, MMI_TRUE);
		}
		
	}
	
	cui_menu_run(menu_id);
	
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_entry_sim_select_menu
 * DESCRIPTION
 *  Entry sim select menu cui.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_entry_sim_select_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_ID group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	group_id = mmi_frm_group_get_active_id();
	mmi_frm_group_create_ex(
						group_id, 
						GRP_ID_SIM_SELECT, 
						cui_dialer_entry_sim_select_proc, 
						NULL, 
						MMI_FRM_NODE_SMART_CLOSE_FLAG);
	
	cui_dialer_create_sim_select_menu();
}

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_sim_select_hdlr
 * DESCRIPTION
 *  This function is used to show sim select menu cui.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_sim_select_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (cui_dialer_get_available_sim_number() == 0)
	{
		cui_dialer_do_sim_select_call(SRV_UCM_VOICE_CALL_TYPE_ALL);
	}
	else if(cui_dialer_get_available_sim_number() == 1)
	{
		for (i = 0; i < MMI_MAX_SIM_NUM; i++)
		{
			if (srv_ucm_is_call_srv_available(cui_dialer_index_to_ucm_type(i)))
			{
				cui_dialer_do_sim_select_call(cui_dialer_index_to_ucm_type(i));
			}
		}
	}
	else
	{
		cui_dialer_entry_sim_select_menu();
	}
}
#endif

#if defined(__OP01_FWPBW__)

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_direct_dial_handler
 * DESCRIPTION
 *  This function is the handler for the op01 family key.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_do_direct_dial_handler(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 number[SRV_UCM_MAX_NUM_URI_LEN + 1];
    mmi_ucm_make_call_para_struct make_call_para;
    cui_dialer_obj_struct *obj;
    MMI_BOOL ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = cui_dialer_get_obj_from_group();
    MMI_ASSERT(obj);

	if(obj->type == CUI_DIALER_TYPE_BWT && mmi_wcslen(obj->dial_string) == 0)
    {
        ret = srv_phb_get_direct_dial(index, number);
        
        if (ret)
        {
            cui_dialer_emit_close_req(obj);
          
            mmi_ucm_init_call_para(&make_call_para);
            make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_ALL;
            make_call_para.ucs2_num_uri = number;
            mmi_ucm_call_launch(0, &make_call_para);
        }
    }
}
/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_direct_dial_sos
 * DESCRIPTION
 *  This function is the handler for the op01 dial sos key.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_do_direct_dial_sos(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mmi_ucm_make_call_para_struct make_call_para;
    U16 number[SRV_UCM_MAX_NUM_URI_LEN + 1];
    cui_dialer_obj_struct *obj;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = cui_dialer_get_obj_from_group();
    MMI_ASSERT(obj);

	  if(obj->type == CUI_DIALER_TYPE_BWT && mmi_wcslen(obj->dial_string) == 0)
	  {	
	
		  cui_dialer_emit_close_req(obj);

          mmi_ucs2cpy((CHAR*)number, (CHAR*)L"112");
          mmi_ucm_init_call_para(&make_call_para);
          make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_ALL;
          make_call_para.ucs2_num_uri = number;
          mmi_ucm_call_launch(0, &make_call_para);
	  }   

}

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_dial_12580
 * DESCRIPTION
 *  This function is the handler for the op01 dial 12580 key.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_do_dial_12580(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mmi_ucm_make_call_para_struct make_call_para;
    U16 number[SRV_UCM_MAX_NUM_URI_LEN + 1];
    cui_dialer_obj_struct *obj;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = cui_dialer_get_obj_from_group();
    MMI_ASSERT(obj);

	  if(obj->type == CUI_DIALER_TYPE_BWT && mmi_wcslen(obj->dial_string) == 0)
	  {	

          cui_dialer_emit_close_req(obj);
        
          mmi_ucs2cpy((CHAR*)number, (CHAR*)L"12580");
          mmi_ucm_init_call_para(&make_call_para);
          make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_ALL;
          make_call_para.ucs2_num_uri = number;
          mmi_ucm_call_launch(0, &make_call_para);   
	  }    
    
}

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_direct_dial_0
 * DESCRIPTION
 *  This function is the handler for the first family key.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_do_direct_dial_0(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_dialer_do_direct_dial_handler(0);
}

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_direct_dial_1
 * DESCRIPTION
 *  This function is the handler for the second family key.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_do_direct_dial_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_dialer_do_direct_dial_handler(1);   
}

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_direct_dial_2
 * DESCRIPTION
 *  This function is the handler for the third family key.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_do_direct_dial_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_dialer_do_direct_dial_handler(2);

}

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_direct_dial_3
 * DESCRIPTION
 *  This function is the handler for the fourth family key.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_do_direct_dial_3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_dialer_do_direct_dial_handler(3);
}

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_direct_dial_4
 * DESCRIPTION
 *  This function is the handler for the fifth family key.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_do_direct_dial_4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_dialer_do_direct_dial_handler(4);
    
}

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_set_direct_dial
 * DESCRIPTION
 *  This function which is used for setting the family keys.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_set_direct_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(cui_dialer_do_dial_12580, KEY_F7, KEY_EVENT_DOWN);
    SetKeyHandler(cui_dialer_do_direct_dial_0, KEY_F1, KEY_EVENT_DOWN);
    SetKeyHandler(cui_dialer_do_direct_dial_1, KEY_F2, KEY_EVENT_DOWN);
    SetKeyHandler(cui_dialer_do_direct_dial_2, KEY_F3, KEY_EVENT_DOWN);
    SetKeyHandler(cui_dialer_do_direct_dial_3, KEY_F4, KEY_EVENT_DOWN);
    SetKeyHandler(cui_dialer_do_direct_dial_4, KEY_F5, KEY_EVENT_DOWN);
    SetKeyHandler(cui_dialer_do_direct_dial_sos, KEY_F6, KEY_EVENT_DOWN);

}
#endif
/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_voice_mail_dial
 * DESCRIPTION
 *  This function handles the voice mail dial.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_do_voice_mail_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = cui_dialer_get_obj_from_group();

    if (!cui_dialer_is_long_press_enable(obj))
    {
        return;
    }

    DialVoiceMail();

    cui_dialer_emit_close_req(obj); /* close dialer */
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_speed_dial
 * DESCRIPTION
 *  This function handles the speed dial.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_do_speed_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;
    U16 key_code, key_type;
    CHAR *phb_dial_string;
    mmi_ucm_make_call_para_struct param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = cui_dialer_get_obj_from_group();

    if (!cui_dialer_is_long_press_enable(obj))
    {
        return;
    }

    /* Skip if key is not speed dial key. Do not close dialer. */
    mmi_frm_get_key_info(&key_code, &key_type);
    if (key_code < KEY_1 && key_code > KEY_9)
    {
        return;
    }

    /* Skip if phone book is not ready. Phone book will display error popup. */
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        cui_dialer_emit_close_req(obj); /* close dialer */
        return;
    }

    /* Skip if handset cannot find corresponding contact. */
    phb_dial_string = mmi_phb_speed_dial_get_number(key_code);
    if (!phb_dial_string)
    {
        cui_dialer_display_popup(STR_ID_CUI_DIALER_NO_SPEED_DIAL_NUM);
        cui_dialer_emit_close_req(obj); /* close dialer */
        return;
    }

    /* Because 'phb_dial_string' might not be 2-bytes aligned, we cannot use
       mmi_wcs2ncpy; otherwise, ARM will fatal when it takes the value of the
       address which is not 2-bytes aligned. */
    mmi_ucs2ncpy(
        (CHAR *)obj->dial_string,
        (const CHAR *)phb_dial_string,
        CUI_DIALER_MAX_DIAL_STR_LEN);

    /* Set a global buffer to tell category should clear all input buffer */
    obj->dial_string_change = MMI_TRUE;

    /*
     * Launch call.
     */
    mmi_ucm_init_call_para(&param);
    param.dial_type = SRV_UCM_CALL_TYPE_ALL;
    cui_dialer_call_launch(obj, &param);
}

#ifdef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  cui_dialer_pen_speed_dial
 * DESCRIPTION
 *  This function handles the pen long press speed dial.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_pen_speed_dial(U16 pen_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;
    CHAR *phb_dial_string;
    mmi_ucm_make_call_para_struct param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = cui_dialer_get_obj_from_group();

    if (!cui_dialer_is_long_press_enable(obj))
    {
        return;
    }

    /* Skip if key is not speed dial key. Do not close dialer. */
    if (pen_code < KEY_1 && pen_code > KEY_9)
    {
        return;
    }

    /* Skip if phone book is not ready. Phone book will display error popup. */
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
        cui_dialer_emit_close_req(obj); /* close dialer */
        return;
    }

    /* Skip if handset cannot find corresponding contact. */
    phb_dial_string = mmi_phb_speed_dial_get_number(pen_code);
    if (!phb_dial_string)
    {
        cui_dialer_display_popup(STR_ID_CUI_DIALER_NO_SPEED_DIAL_NUM);
        cui_dialer_emit_close_req(obj); /* close dialer */
        return;
    }

    /* Because 'phb_dial_string' might not be 2-bytes aligned, we cannot use
       mmi_wcs2ncpy; otherwise, ARM will fatal when it takes the value of the
       address which is not 2-bytes aligned. */
    mmi_ucs2ncpy(
        (CHAR *)obj->dial_string,
        (const CHAR *)phb_dial_string,
        CUI_DIALER_MAX_DIAL_STR_LEN);

	/* Set a global buffer to tell category should clear all input buffer */
	obj->dial_string_change = MMI_TRUE;

    /*
     * Launch call.
     */
    mmi_ucm_init_call_para(&param);
    param.dial_type = SRV_UCM_CALL_TYPE_ALL;
    cui_dialer_call_launch(obj, &param);
}

#endif

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_ssc
 * DESCRIPTION
 *  This function handles the SSC string.
 * PARAMETERS
 *  obj           : [IN]        Dialer object
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL cui_dialer_do_ssc(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ssc_sim_string_pass((WCHAR *)obj->dial_string))
    {
        return MMI_TRUE;
    }

    if (mmi_ssc_phone_string_pass((WCHAR *)obj->dial_string))
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_ssc_lang
 * DESCRIPTION
 *  This function handles the SSC string to change the language.
 * PARAMETERS
 *  obj           : [IN]        Dialer object
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL cui_dialer_do_ssc_lang(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_ssc_lauguage_string_pass((WCHAR *)obj->dial_string);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_abbrev_dial
 * DESCRIPTION
 *  This function implments the abbrev. dial. It is a feature to access SIM
 *  contact quickly.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_do_abbrev_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;
    WCHAR dial_string[CUI_DIALER_MAX_DIAL_BUF_SIZE];
    S32 read_length, atoi_result, index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = cui_dialer_get_obj_from_group();

    /* Handle SSC dial string. */
    if (cui_dialer_do_ssc(obj))
    {
        cui_dialer_emit_close_req(obj);
        return;
    }

    /* Skip non-abbrev. dialing string. */
    if (!cui_dialer_copy_before(dial_string, obj->dial_string, CUI_DIALER_MAX_ABBREV_STR_LEN, L'#'))
    {
        return;
    }

    /* Skip invalid dial string. Otherwise, show the SIM contact entry and close
       the dialer. */
    atoi_result = mmi_ucs2toi(
                    (const CHAR *)dial_string,
                    &index,
                    &read_length);

    if (atoi_result < 0)
    {
        return;
    }

    if (!mmi_phb_get_sim_entry_by_location((U16)index))
    {
        return;
    }

    /* Success. Can close the dialer. */
    cui_dialer_emit_close_req(obj);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_save_contact_evt_hdlr
 * DESCRIPTION
 *  This function is the proc function of the phone book "Save Contact" CUI.
 * PARAMETERS
 *  event             : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret cui_dialer_do_save_contact_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_phb_save_contact_result_struct *evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt = (cui_phb_save_contact_result_struct *)event;

    switch (evt->evt_id)
    {
        case EVT_ID_PHB_SAVE_CONTACT:   /* fall-throught */
        case EVT_ID_PHB_SAVE_CONTACT_CANCEL:
            cui_phb_save_contact_close(evt->sender_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_save_contact_ex
 * DESCRIPTION
 *  This function saves the contact.
 * PARAMETERS
 *  obj           : [IN]        Dialer object
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_do_save_contact_ex(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id parent_gid, child_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parent_gid = mmi_frm_group_create(
                    obj->this_gid,
                    GRP_ID_AUTO_GEN,
                    cui_dialer_do_save_contact_evt_hdlr,
                    obj);

    mmi_frm_group_enter(parent_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    child_gid = cui_phb_save_contact_create(parent_gid);

    if (child_gid == GRP_ID_INVALID)
    {
        cui_dialer_display_popup(STR_GLOBAL_NOT_AVAILABLE);
        cui_dialer_emit_close_req(obj);
        return;
    }

#if defined(__MMI_VOIP__)
    if (obj->type == CUI_DIALER_TYPE_VOIP)
    {
        cui_phb_save_contact_set_voip(child_gid, obj->dial_string);
    }
    else
#endif /*  defined(__MMI_VOIP__) */
    {
        cui_phb_save_contact_set_number(child_gid, obj->dial_string);
    }

    cui_phb_save_contact_run(child_gid);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_save_contact
 * DESCRIPTION
 *  This function saves the contact.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_do_save_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = cui_dialer_get_obj_from_group();

    cui_dialer_do_save_contact_ex(obj);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_ip_dial
 * DESCRIPTION
 *  This function implements the IP dial.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_do_ip_dial(void)
{
#if defined(__IP_NUMBER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;
    mmi_ucm_make_call_para_struct param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = cui_dialer_get_obj_from_group();

    /*
     * Launch call.
     */
    mmi_ucm_init_call_para(&param);
    param.dial_type = SRV_UCM_CALL_TYPE_ALL;
    param.adv_para.is_ip_dial = MMI_TRUE;
    cui_dialer_call_launch(obj, &param);
#endif /* defined(__IP_NUMBER__) */
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_center_key_dial_ex
 * DESCRIPTION
 *  This function dials call by center key.
 * PARAMETERS
 *  obj           : [IN]        Dialer object
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_do_center_key_dial_ex(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Launch call.
     */
    mmi_ucm_init_call_para(&param);
    param.dial_type = SRV_UCM_CALL_TYPE_ALL;
    cui_dialer_call_launch(obj, &param);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_center_key_dial
 * DESCRIPTION
 *  This function dials call by center key.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_do_center_key_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = cui_dialer_get_obj_from_group();

    cui_dialer_do_center_key_dial_ex(obj);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_send_key_dial
 * DESCRIPTION
 *  This function dials call by send key.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_do_send_key_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;
    mmi_ucm_make_call_para_struct param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = cui_dialer_get_obj_from_group();

#ifdef __OP01_FWPBW__
	  if(obj->type == CUI_DIALER_TYPE_BWT && mmi_wcslen(obj->dial_string) == 0)
	  {	

	      cui_dialer_emit_close_req(obj);
		  mmi_clog_sendkey_launch();
	
		  return;
	  }
#endif

    if (cui_dialer_do_ssc_lang(obj))
    {
        cui_dialer_emit_close_req(obj);
        return;
    }

    /*
     * Launch call.
     */
    mmi_ucm_init_call_para_for_sendkey(&param);
    cui_dialer_call_launch(obj, &param);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_send_key_dial_by_voip
 * DESCRIPTION
 *  This function dials a VoIP call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_do_key_dial_by_type(cui_dialer_ucm_type_enum ucm_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;
    mmi_ucm_make_call_para_struct param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = cui_dialer_get_obj_from_group();

    if (cui_dialer_do_ssc_lang(obj))
    {
        cui_dialer_emit_close_req(obj);
        return;
    }

    /*
     * Launch call.
     */
    mmi_ucm_init_call_para(&param);
    
	switch(ucm_type)
	{
		case CUI_DIALER_VOIP:
    param.dial_type = SRV_UCM_VOIP_CALL_TYPE;
			break;
    	case CUI_DIALER_SIM1:
#if  defined(__MMI_DIALER_DYNAMIC_CALL_UI__) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
			param.dial_type = SRV_UCM_VOICE_CALL_TYPE;
#else
			#if(GEMINI_PLUS<=2)
    			param.dial_type = SRV_UCM_VOICE_CALL_TYPE;
			#elif (GEMINI_PLUS >=3)
				param.dial_type = SRV_UCM_VOICE_CALL_TYPE_ALL;
			#endif
#endif			
			break;
    	case CUI_DIALER_SIM2:
			param.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
			break;
		case CUI_DIALER_SIM3:
			param.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM3;
			break;
		case CUI_DIALER_SIM4:
			param.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM4;
			break;
#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
   		case CUI_DIALER_VIDEO:
#ifdef __MMI_3G_SWITCH__
			if (srv_netset_get_3g_capacity_sim() == MMI_SIM)
			{
				param.dial_type = SRV_UCM_VIDEO_CALL_TYPE_SIM2;
			}
			else
			{
				param.dial_type = SRV_UCM_VIDEO_CALL_TYPE;
			}
#else
			param.dial_type = SRV_UCM_VIDEO_CALL_TYPE;	
#endif				
			break;			
    	case CUI_DIALER_VOICE:
			param.dial_type = SRV_UCM_VOICE_CALL_TYPE_ALL;
			break;
#endif
		case CUI_DIALER_ALL:
			param.dial_type = SRV_UCM_VOICE_CALL_TYPE_ALL;
			break;
		default:
			param.dial_type = SRV_UCM_VOICE_CALL_TYPE_ALL;
			break;		
	}

    cui_dialer_call_launch(obj, &param);
}



/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_send_key_dial_by_voip
 * DESCRIPTION
 *  This function dials a VoIP call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_do_send_key_dial_by_voip(void)
{
	cui_dialer_do_key_dial_by_type(CUI_DIALER_VOIP);
}


#if defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_send_key_dial_1
 * DESCRIPTION
 *  This function dials call from SIM 1.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_do_send_key_dial_1(void)
{
	cui_dialer_do_key_dial_by_type(CUI_DIALER_SIM1);
}


#if defined(__MMI_DUAL_SIM_MASTER__)
/*****************************************************************************
 * FUNCTION
 *  cui_dialer_do_send_key_dial_2
 * DESCRIPTION
 *  This function dials call from SIM 2.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_do_send_key_dial_2(void)
{
	cui_dialer_do_key_dial_by_type(CUI_DIALER_SIM2);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_set_touch_send_hdlr
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  sim2_func           : [IN]      SIM 1 dial function
 *  sim1_func           : [IN]      SIM 2 dial function
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_set_touch_send_hdlr(FuncPtr sim1_func, FuncPtr sim2_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_is_call_srv_available(SRV_UCM_VOICE_CALL_TYPE))
    {
        SetDialingKeypadCallHandler(sim1_func);
    }

    if (srv_ucm_is_call_srv_available(SRV_UCM_VOICE_CALL_TYPE_SIM2))
    {
        SetDialingKeypadCall2Handler(sim2_func);
    }
}
#endif /* defined(__MMI_DUAL_SIM_MASTER__) */
#endif /* defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */


#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
//#ifdef __MMI_VIDEO_TELEPHONY__
void cui_dialer_do_video_dial(void)
{
	cui_dialer_do_key_dial_by_type(CUI_DIALER_VIDEO);
}


void cui_dialer_do_voice_dial(void)
{
	cui_dialer_do_key_dial_by_type(CUI_DIALER_VOICE);
}

#endif /* defined(__OP01_TD0200_SEGC__) && defined(__MMI_VIDEO_TELEPHONY__) */


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_set_speed_dial_hdlr
 * DESCRIPTION
 *  This function sets the speed dial key handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_set_speed_dial_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keys[] = {KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_DUAL_SIM_MASTER__)
    if (srv_nw_usab_any_sim_is_usable())
#else
    if (srv_sim_ctrl_is_available(MMI_SIM1))
#endif
    {
        if (mmi_phb_get_speed_dial_status() == MMI_TRUE)
        {
            SetGroupKeyHandler(
                cui_dialer_do_speed_dial,
                keys,
                CUI_DIALER_GET_SIZE(keys),
                KEY_LONG_PRESS);
        }

        SetKeyHandler(cui_dialer_do_voice_mail_dial, KEY_1, KEY_LONG_PRESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_input_first_char
 * DESCRIPTION
 *  This function inputs the first digits into the dialer if it is present.
 * PARAMETERS
 *  obj           : [IN]      Dial object
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_input_first_char(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    if (obj->first_input_source == CUI_DIALER_FIRST_INPUT_QWERTY_KEY)
    #if defined(__MMI_DIALER_SEARCH__) || defined(__CAT16_MULTIEDITOR_STYLE__)
    {
        /* On QWERTY project, the first digit is inserted by executing the key
           handler of the dialer. */
        mmi_frm_key_evt_struct tmp_evt;
        mmi_frm_construct_key_event(obj->key_code, KEY_EVENT_DOWN, &tmp_evt);
		tmp_evt.evt_id = EVT_ID_PRE_KEY;
        MMI_FRM_SEND_EVENT(&tmp_evt, mmi_imc_key_qwerty_key_proc, NULL);
        mmi_frm_construct_key_event(obj->key_code, KEY_EVENT_UP, &tmp_evt);
		tmp_evt.evt_id = EVT_ID_PRE_KEY;
        MMI_FRM_SEND_EVENT(&tmp_evt, mmi_imc_key_qwerty_key_proc, NULL);
    }
    #else
	{
        /* On QWERTY project, the first digit is inserted by executing the key
           handler of the dialer. */
        wgui_inputs_dialer_qwerty_key_handler(
            obj->key_code,
            obj->key_type,
            obj->ucs2_value,
            obj->key_flag);
    }
    #endif
    else
#endif /* defined(__MMI_QWERTY_KEYPAD_SUPPORT__) */
    if (obj->first_input_source == CUI_DIALER_FIRST_INPUT_DIGITAL_KEY)
    {
        /* On non-QWERTY project, the first digit should be inserted by executing
           the current key handler. */
        ExecuteCurrKeyHandler(obj->key_code, KEY_EVENT_DOWN);
    }

    /* Reset input source after the first character. */
    obj->first_input_source = CUI_DIALER_FIRST_INPUT_INVALID;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_set_handler
 * DESCRIPTION
 *  This function sets the handlers for the dialer.
 * PARAMETERS
 *  obj           : [IN]        Dialer object
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_set_handler(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_capability_struct *capability;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    capability = &obj->capability; /* for quick access. */

    /*
     * LSK
     */
    if (capability->enable_lsk)
    {
    #ifdef __MMI_MAINLCD_96X64__
    		SetLeftSoftkeyFunction(cui_dialer_do_save_contact, KEY_EVENT_UP);    
    #else
        SetLeftSoftkeyFunction(cui_dialer_entry_menu, KEY_EVENT_UP);
    #endif
    }

    /*
     * CSK
     */
    if (capability->enable_csk)
    {
        SetCenterSoftkeyFunction(cui_dialer_do_center_key_dial, KEY_EVENT_UP);
    }

    /*
     * SEND
     */
    if (capability->enable_send)
    {
        if (obj->type == CUI_DIALER_TYPE_VOIP)
        {
            SetKeyHandler(
                cui_dialer_do_send_key_dial_by_voip,
                KEY_SEND,
                KEY_EVENT_DOWN);
        }
        else
        {
            mmi_ucm_handle_sendkeys_for_call(
                cui_dialer_do_send_key_dial,
                KEY_EVENT_DOWN);
        }
    }

    /*
     * Abbrev. dial
     */
    if (capability->enable_abbrev_dial)
    {
        SetKeyHandler(cui_dialer_do_abbrev_dial, KEY_POUND, KEY_EVENT_UP);
    }

#if defined(__MMI_IP_KEY__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_IP_KEY__) */

    /*
     * Speed dial
     */
    if (capability->enable_speed_dial)
    {
        cui_dialer_set_speed_dial_hdlr();
    }

    /*
     * Toggle silent profile
     */
    if (capability->enable_toggle_profile)
    {
        SetKeyHandler(
            cui_dialer_do_toggle_silent_profile,
            KEY_POUND,
            KEY_LONG_PRESS);
    }

#if defined(__MMI_SEARCH_WEB__)
    /*
     * Baidu Search
     */
    if (capability->enable_baidu_search &&
        mmi_search_web_hot_key_is_enabled(MMI_SEARCH_WEB_HOT_KEY_LONG_PRESS_STAR))
    {
        SetKeyHandler(cui_dialer_do_baidu_search, KEY_STAR, KEY_LONG_PRESS);
    }
#endif /* defined(__MMI_SEARCH_WEB__) */

    /*
     * Direct dial
     */
#ifdef __OP01_FWPBW__
    if(capability->enable_direct_dial)
    {
        cui_dialer_set_direct_dial();
    }
#endif    

}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_init_capability
 * DESCRIPTION
 *  This function initializes the capability of the dialer.
 * PARAMETERS
 *  capability           : [IN]         Capability
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_init_capability(cui_dialer_capability_struct *capability)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(capability);

    memset(capability, 1, sizeof(cui_dialer_capability_struct));
}


#if defined(__MMI_VOIP__)
/*****************************************************************************
 * FUNCTION
 *  cui_dialer_menu_change_dial_mode
 * DESCRIPTION
 *  This function changes the dialer type.
 * PARAMETERS
 *  obj             : [IN]          Dialer object
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_menu_change_dial_mode(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (obj->type == CUI_DIALER_TYPE_CLASSIC)
    {
        cui_dialer_emit_change_type(obj, CUI_DIALER_TYPE_VOIP);
    }
    else if (obj->type == CUI_DIALER_TYPE_VOIP)
    {
        cui_dialer_emit_change_type(obj, CUI_DIALER_TYPE_CLASSIC);
    }
}
#endif /* defined(__MMI_VOIP__) */


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_menu_handle_item_select
 * DESCRIPTION
 *  This function handles the "menu item select" event of the menu CUI.
 * PARAMETERS
 *  event               : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret cui_dialer_menu_handle_item_select(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *evt;
    cui_dialer_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event && event->user_data);

    evt = (cui_menu_event_struct *)event;
    obj = (cui_dialer_obj_struct *)evt->user_data;

    switch (evt->highlighted_menu_id)
    {
        case MENU_ID_CUI_DIALER_DIAL:
            cui_dialer_do_center_key_dial_ex(obj);
            break;

        case MENU_ID_CUI_DIALER_SAVE_CONTACT:
            cui_dialer_do_save_contact_ex(obj);
            break;

    #if defined(__MMI_VOIP__)
        case MENU_ID_CUI_DIALER_CHANGE_MODE:
            cui_dialer_menu_change_dial_mode(obj);
            break;
    #endif /* defined(__MMI_VOIP__) */

    #if defined(__MMI_DIALER_SEARCH__)
        case MENU_ID_CUI_DIALER_DIALER_SEARCH:
            cui_dialer_search_entry_setting(obj->this_gid);
            break;
    #endif /* defined(__MMI_DIALER_SEARCH__) */

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_set_common_item_disabled
 * DESCRIPTION
 *  This function hides or unhides the dialer's common menu item.
 * PARAMETERS
 *  cui_id              : [IN]          CUI ID
 *  is_hidden           : [IN]          Hidden or not
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_set_common_item_disabled(
    mmi_id cui_id,
    MMI_BOOL is_hidden)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_set_item_disabled(
        cui_id,
        MENU_ID_CUI_DIALER_DIAL,
        is_hidden);

    cui_menu_set_item_disabled(
        cui_id,
        MENU_ID_CUI_DIALER_SAVE_CONTACT,
        is_hidden);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_menu_handle_list_entry
 * DESCRIPTION
 *  This function handles the "list entry" event of the menu CUI.
 * PARAMETERS
 *  event               : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret cui_dialer_menu_handle_list_entry(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *evt;
    cui_dialer_obj_struct *obj;
    mmi_id cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event && event->user_data);

    evt = (cui_menu_event_struct *)event;
    obj = (cui_dialer_obj_struct *)evt->user_data;
    cui_id = evt->sender_id;

    if (evt->parent_menu_id == MENU_ID_CUI_DIALER_MENU)
    {
        if (mmi_wcslen(obj->dial_string))
        {
            cui_dialer_set_common_item_disabled(cui_id, MMI_FALSE);
        }
        else
        {
            cui_dialer_set_common_item_disabled(cui_id, MMI_TRUE);
        }

    #if defined(__MMI_VOIP__)
        if (obj->type == CUI_DIALER_TYPE_VOIP)
        {
            cui_menu_set_group_disabled(cui_id, MENU_GROUP_EDITOR, MMI_FALSE);
        }
        else
        {
            cui_menu_set_group_disabled(cui_id, MENU_GROUP_EDITOR, MMI_TRUE);
        }
    #endif /* defined(__MMI_VOIP__) */

    #if defined(__MMI_DIALER_SEARCH__)
        if (obj->launch_by_calllog)
        {
            cui_menu_set_item_disabled(
                cui_id,
                MENU_ID_CUI_DIALER_DIALER_SEARCH,
                MMI_TRUE);
        }
        else
        {
            if (cui_dialer_search_is_enable())
            {
                cui_menu_set_item_hint(
                    cui_id,
                    MENU_ID_CUI_DIALER_DIALER_SEARCH,
                    get_string(STR_GLOBAL_ON));
            }
            else
            {
                cui_menu_set_item_hint(
                    cui_id,
                    MENU_ID_CUI_DIALER_DIALER_SEARCH,
                    get_string(STR_GLOBAL_OFF));
            }
        }
    #endif /* defined(__MMI_DIALER_SEARCH__) */
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_menu_evt_hdlr
 * DESCRIPTION
 *  This function is the event handler of the menu CUI.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret cui_dialer_menu_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_event_struct *evt;
    cui_dialer_obj_struct *obj;
    mmi_id cui_id;
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event && event->user_data);

    evt = (mmi_group_event_struct *)event;
    obj = (cui_dialer_obj_struct *)evt->user_data;
    cui_id = evt->sender_id;

    /*
     * APP handles the event.
     */
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            ret = cui_dialer_menu_handle_list_entry(event);
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            ret = cui_dialer_menu_handle_item_select(event);
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(cui_id);
            break;

        default:
            break;
    }

    /*
     * Editor handles the events.
     */
    if (cui_menu_is_menu_event(evt->evt_id))
    {
        wgui_inputs_options_menu_handler(event, obj->this_gid);
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_entry_menu
 * DESCRIPTION
 *  This function entries the option menu of the dialer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_entry_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;
    mmi_id grp_id, cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = cui_dialer_get_obj_from_group();

    grp_id = mmi_frm_group_create(
                obj->this_gid,
                GRP_ID_AUTO_GEN,
                cui_dialer_menu_evt_hdlr,
                obj);

    MMI_ASSERT(grp_id != GRP_ID_INVALID);

    mmi_frm_group_enter(grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_id = cui_menu_create(
                grp_id,
                CUI_MENU_SRC_TYPE_RESOURCE,
                CUI_MENU_TYPE_OPTION,
                MENU_ID_CUI_DIALER_MENU,
                MMI_FALSE,
                NULL);

    MMI_ASSERT(cui_id != GRP_ID_INVALID);

    cui_menu_run(cui_id);
}

