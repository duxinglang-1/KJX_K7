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
 * key_tone.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for key tone mechanism
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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

/*****************************************************************************
* Include
*****************************************************************************/
//#include "mmi_frm_gprot.h"
#include "ProfilesSrvGprot.h"
#include "Resource_audio.h"


//RHR Add
#include "MMIDataType.h"
#include "device.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "DebugInitDef_Int.h"
#include "pluto_fw_trc.h"
#include "kal_trace.h"
#include "custom_srv_prof_defs.h"
#include "kal_public_api.h"
#include "GlobalResDef.h"
#include "kal_general_types.h"
/*****************************************************************************
* Define
*****************************************************************************/

/* 
 * The human voice tone is only for 0~9 *#.
 * As a result, the total number is 12.
 * We reserve an extra one. The range should be 12 + 1 = 13 
 */
#define HUMAN_VOICE_TONE_RANGE  (13)
#define DUMMY_TONE_ID           (0xFFFF)
#define INVALID_DIAL_KEY_INDEX  (-1)
#define MARKER  200
#define MAKE_DISABLE_TYPE(type) (type + MARKER)

/* if key tone white box test is needed, enable this macro */
//#define __MMI_KEY_TONE_UT__
/*****************************************************************************
* Typedef 
*****************************************************************************/

typedef struct
{
    U16      id;
    U8       duration;
    U8       key_code;
    U8       state;
    U8       dial_key_tone_type;
    MMI_BOOL is_playing;
} key_tone_cntx;

/*****************************************************************************
* Local Function
*****************************************************************************/
static MMI_BOOL is_tone_enabled(U8 key_code);
static MMI_BOOL can_play_human_voice_tone(void);
static MMI_BOOL can_play_cust_tone();
static S32 get_dialer_key_index(U8 mmi_key_code);
static void get_tone_info(U8 mmi_key_code, U16 *id_p, U8 *duration_p);
static void play_key_tone(U8 key_code);
#ifdef __MMI_KEY_TONE_UT__
static void audio_stop_simulate(U16 id);
static void audio_play_simulate(U16 id, U8 duration);
#endif /* __MMI_KEY_TONE_UT__ */

/*****************************************************************************
* Extern Global Function                                                      
*****************************************************************************/
extern MMI_BOOL mmi_idle_is_active(void);
extern MMI_BOOL mmi_dialer_is_active(void);

/*****************************************************************************
* static Global Variable
*****************************************************************************/
key_tone_cntx g_key_tone_cntx = {DUMMY_TONE_ID, DEVICE_AUDIO_PLAY_ONCE, KEY_INVALID};

/*****************************************************************************
* Const Global Variable
*****************************************************************************/

/* 
 * 1. Only 0~9 *# have special key tone in MMI_KEY_TONE_ENABLED_1_to_9_DTMF state. 
 * The following array is the set of these key tones. For other keys, 
 * Their tone is TONE_KEY_NORMAL.
 * 
 * 2. The following array is corresponse to the array PresentAllDialerKeys
 */
const static U8 g_key_tone[] =
{
   TONE_DTMF_0,
   TONE_DTMF_1,
   TONE_DTMF_2,
   TONE_DTMF_3,
   TONE_DTMF_4,
   TONE_DTMF_5,
   TONE_DTMF_6,
   TONE_DTMF_7,
   TONE_DTMF_8,
   TONE_DTMF_9,
   TONE_KEY_STAR,
   TONE_KEY_HASH,
};
const U8 disable_tone_by_key_info[] = 
{
    MAKE_DISABLE_TYPE(MMI_KEY_VOL_TONE_DISABLED), KEY_VOL_UP, KEY_VOL_DOWN,
    MAKE_DISABLE_TYPE(MMI_KEY_VOL_UP_DOWN_RIGHT_LEFT_ARROW_DISABLE), KEY_VOL_UP, KEY_VOL_DOWN, KEY_LEFT_ARROW, KEY_RIGHT_ARROW,
    MAKE_DISABLE_TYPE(MMI_KEY_VOL_UP_DOWN_TONE_DISABLED), KEY_VOL_UP, KEY_VOL_DOWN, KEY_UP_ARROW, KEY_DOWN_ARROW,
    MAKE_DISABLE_TYPE(MMI_KEY_RIGHT_LEFT_ARROW_TONE_DISABLED), KEY_LEFT_ARROW, KEY_RIGHT_ARROW,
    MAKE_DISABLE_TYPE(MMI_KEY_LSK_TONE_DISABLE), KEY_LSK,
    MAKE_DISABLE_TYPE(MMI_KEY_RSK_TONE_DISABLE), KEY_RSK,
    MAKE_DISABLE_TYPE(MMI_KEY_LSK_RSK_TONE_DISABLE), KEY_LSK, KEY_RSK
};

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + External API
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*****************************************************************************
* FUNCTION
*  mmi_frm_set_dial_key_tone_type
* DESCRIPTION
*  This function is used to set dialer key tone type
*
* PARAMETERS
*  type      : [IN]  see mmi_frm_dial_key_tone_type_enum
* RETURNS
*  void
*****************************************************************************/
void mmi_frm_set_dial_key_tone_type(mmi_frm_dial_key_tone_type_enum  type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_key_tone_cntx.dial_key_tone_type = type;
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_get_dial_key_tone_type
* DESCRIPTION
*  This function is used to get dialer key tone type
*
* PARAMETERS
*  void
* RETURNS
*  see mmi_frm_dial_key_tone_type_enum
*****************************************************************************/
mmi_frm_dial_key_tone_type_enum mmi_frm_get_dial_key_tone_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return  (mmi_frm_dial_key_tone_type_enum)g_key_tone_cntx.dial_key_tone_type;
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_kbd_set_tone_state
* DESCRIPTION
*  This function is used to set the key tone state of the keypad
*
* PARAMETERS
*  state       :[IN]  Keypad tone state that want to be changed
* RETURNS
*  void
*****************************************************************************/
void mmi_frm_kbd_set_tone_state(mmi_frm_kbd_tone_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_key_tone_cntx.state = state;
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_kbd_get_key_tone_state
* DESCRIPTION
*  This function is used for gets the state to see if keypad tone is disabled.
* PARAMETERS
*  void
* RETURNS
*  Return the key pad tone state. Refer to mmi_frm_kbd_tone_state_enum.
*****************************************************************************/
mmi_frm_kbd_tone_state_enum mmi_frm_kbd_get_key_tone_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (mmi_frm_kbd_tone_state_enum)g_key_tone_cntx.state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_curr_key_tone
 * DESCRIPTION
 *  This function is used for queries the current keypad tone.
 * PARAMETERS
 *  void
 * RETURNS
 *  Returns the keypad tone enum. Refer audio_id_enum.
 *****************************************************************************/
U16 mmi_frm_get_curr_key_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_key_tone_cntx.id;
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_stop_curr_key_tone
* DESCRIPTION
*  This function is used to stop the current key tone
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_frm_stop_curr_key_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(PLUTO_FW_TRC_KEY,
        TRC_MMI_FRM_KEY_TONE_STOP,
        g_key_tone_cntx.key_code,
        g_key_tone_cntx.id,
        g_key_tone_cntx.duration);
    if (g_key_tone_cntx.duration == SRV_PROF_RING_TYPE_REPEAT)
    {
    #ifdef __MMI_KEY_TONE_UT__
        audio_stop_simulate(g_key_tone_cntx.id);
    #else
        srv_prof_stop_tone(SRV_PROF_TONE_KEYPAD);
    #endif /* __MMI_KEY_TONE_UT__ */
    }
    g_key_tone_cntx.id = DUMMY_TONE_ID;
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_key_tone_player
* DESCRIPTION
*  This function is used to play key tone according to the key code and key type
*
*  Behavior
*  case1
*     KEY_1 DOWN - play KEY_1's tone
*     KEY_1 UP   - stop KEY_1's tone
*  case2
*     KEY_1 DOWN - play KEY_1's tone
*     KEY_2 DOWN - stop KEY_1's tone, play KEY_2's tone
*     KEY_1 UP   - do nothing
*     KEY_2 UP   - stop KEY_2's tone
*  case3
*     KEY_1 DOWN - play KEY_1's tone
*     KEY_2 DOWN - stop KEY_1's tone, play KEY_2's tone
*     KEY_2 UP   - stop KEY_2's tone
*     KEY_1 UP   - do nothing
* PARAMETERS
*  key_code   :[IN] mmi key code
*  key_type   :[IN] mmi key type
* RETURNS
*  void
*****************************************************************************/
void mmi_frm_key_tone_player(U8 key_code, U8 key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __IV_TTS__
	NPR_TTS_DialNumberRead((UI_character_type)key_code);
	#endif
	
    switch (key_type)
    {
        case KEY_EVENT_DOWN:
        {
            if (g_key_tone_cntx.id != DUMMY_TONE_ID)
            {
                mmi_frm_stop_curr_key_tone();
            }
            play_key_tone(key_code);
            break;
        }

        case KEY_EVENT_UP:
        {
            if (key_code == g_key_tone_cntx.key_code)
            {
                mmi_frm_stop_curr_key_tone();
            }
            break;
        }

        default:
            break;
    }
   
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + Call Back function
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*****************************************************************************
* FUNCTION
*  mmi_key_tone_pre_key_routing_cb
* DESCRIPTION
*  This function is EVT_ID_PRE_KEY_EVT_ROUTING events call back function
*
* PARAMETERS
*  evt                   :[IN] key event  
* RETURNS
*  MMI_RET_OK
*****************************************************************************/
mmi_ret mmi_key_tone_pre_key_routing_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(key_evt->evt_id == EVT_ID_PRE_KEY_EVT_ROUTING);
    mmi_frm_key_tone_player(key_evt->key_code, key_evt->key_type);
    return MMI_RET_OK;
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + Local Functions
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
 
/*****************************************************************************
* FUNCTION
*  key_tone_play_call_back
* DESCRIPTION
*  This function is used to play key tone
* PARAMETERS
*  key_code        :[IN] mmi key code
* RETURNS
*  void
*****************************************************************************/
static srv_prof_ret key_tone_play_call_back(srv_prof_ret res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_key_tone_cntx.is_playing = MMI_FALSE;
    return 0;
}

/*****************************************************************************
* FUNCTION
*  play_key_tone
* DESCRIPTION
*  This function is used to play key tone
* PARAMETERS
*  key_code        :[IN] mmi key code
* RETURNS
*  void
*****************************************************************************/
static void play_key_tone(U8 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tone_id;
    U8 tone_duration;
#ifndef __MMI_KEY_TONE_UT__
    srv_prof_ret  ret;
#endif    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_tone_info(key_code, &tone_id, &tone_duration);
    g_key_tone_cntx.key_code = key_code;
    g_key_tone_cntx.id = tone_id;
    g_key_tone_cntx.duration = tone_duration;

    
    MMI_TRACE(PLUTO_FW_TRC_KEY, 
        TRC_MMI_FRM_KEY_TONE_PLAY,
        key_code,
        tone_id,
        tone_duration);
    /* DUMMY_TONE_ID means tone type = KEYPAD_SILENCE */
    if (is_tone_enabled(key_code) && g_key_tone_cntx.id != DUMMY_TONE_ID)
    {
    #ifdef __MMI_KEY_TONE_UT__
        audio_play_simulate(tone_id, tone_duration);
    #else
        ret = srv_prof_play_tone_with_id(SRV_PROF_TONE_KEYPAD, tone_id, (srv_prof_ring_type_enum)tone_duration, key_tone_play_call_back);
        if (ret == SRV_PROF_RET_SUCCESS)
        {
            g_key_tone_cntx.is_playing = MMI_TRUE;
        }
    #endif /* __MMI_KEY_TONE_UT__ */
    }
	else
	{
		g_key_tone_cntx.key_code = KEY_INVALID;
		g_key_tone_cntx.id = DUMMY_TONE_ID;
		g_key_tone_cntx.duration = 0xFF;
	}
}


/*****************************************************************************
* FUNCTION
*  get_tone_info
* DESCRIPTION
*  This function is used to get tone id and duration
*  
*  About tone id:
*  
*  if tone type = KEYPAD_TONE
*  then      
*      if tone state != MMI_KEY_TONE_ENABLED_1_to_9_DTMF
*      then id = TONE_KEY_NORMAL
*      else
*      then id: see g_key_tone
*
*  if tone type = KEYPAD_CLICK, then id = TONE_KEY_CLICK
*
*  if tone type = KEYPAD_TONE_HUMAN_VOICE_x,
*  then id = MIN_HUMAN_VOICE_ID + (KEYPAD_TONE_HUMAN_VOICE_x - KEYPAD_TONE_HUMAN_VOICE_1) * HUMAN_VOICE_TONE_RANGE
*  
*  if tone type = KEYPAD_TONE_CUST_x
*  then id = MIN_KEYPAD_TONE_ID + (KEYPAD_TONE_CUST_x - KEYPAD_TONE_CUST_1)
*
* PARAMETERS
*  mmi_key_code      :[IN]    Key code of MMI
*  id_p              :[OUT]   tone id
*  duration_p        :[OUT]   tone duration
* RETURNS
*  void
*****************************************************************************/
static void get_tone_info(U8 mmi_key_code, U16 *id_p, U8 *duration_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_keypad_tone_type_enum tone_type;
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_KEYPAD_TONE_TYPE, (void* )&tone_type);
    MMI_TRACE(PLUTO_FW_TRC_KEY, TRC_MMI_FRM_KEY_TONE_INFO, tone_type, g_key_tone_cntx.state);
    *duration_p = SRV_PROF_RING_TYPE_ONCE;
    if (tone_type == SRV_PROF_KEYPAD_CLICK)
    {
        *id_p = TONE_KEY_CLICK;
        return;
    }
    else if (tone_type == SRV_PROF_KEYPAD_SILENT)
    {
        *id_p = DUMMY_TONE_ID;
        return;
    }
	#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__) && defined(__PLUTO_MMI_PACKAGE__) 
    else if (tone_type >= SRV_PROF_KEYPAD_NUM_1 && tone_type <= SRV_PROF_KEYPAD_NUM_6)
    {
        if (can_play_human_voice_tone() == MMI_TRUE)
        {
            if ((index = get_dialer_key_index(mmi_key_code)) != INVALID_DIAL_KEY_INDEX)
            {
                /* id = base_id + type_index * type_range + index_with_type */
                *id_p = srv_prof_get_special_key_tone_audio_id(tone_type, index);
                return;
            }
        }
    }
	#endif
	#if defined(__MMI_CUST_KEYPAD_TONE__) && defined(__PLUTO_MMI_PACKAGE__)
    else if (tone_type >= SRV_PROF_KEYPAD_CUST_1 && tone_type <= SRV_PROF_KEYPAD_CUST_6)
    {
        if (can_play_cust_tone() == MMI_TRUE)
        {
            /* id = base_id + type_index */
            *id_p = srv_prof_get_cust_key_tone_audio_id(tone_type);
            return;
        }
    }
	#endif

    if (mmi_frm_get_dial_key_tone_type() == MMI_DIALER_KEY_TONE_DTMF)
    {
        if ((index = get_dialer_key_index(mmi_key_code)) != INVALID_DIAL_KEY_INDEX)
        {
            *id_p = (U16)g_key_tone[index];
            *duration_p = SRV_PROF_RING_TYPE_REPEAT;
            return;
        }
    }
    *id_p = TONE_KEY_NORMAL;
    return;
}


/*****************************************************************************
* FUNCTION
*  get_dialer_key_index
* DESCRIPTION
*  This function is used to get index of key code in table PresentAllDialerKeys
*
* PARAMETERS
*  mmi_key_code   :[IN]  mmi key code
*
* RETURNS
*  INVALID_DIAL_KEY_INDEX if not found, index of the mmi_key_code in table
*  PresentAllDialerKeys
*****************************************************************************/
static S32 get_dialer_key_index(U8 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_key_code <= KEY_9) || (mmi_key_code == KEY_STAR) || (mmi_key_code == KEY_POUND))
    {
        for (i = 0; i < TOTAL_DIALER_KEYS; i++)
        {
            if (PresentAllDialerKeys[i] == mmi_key_code)
            {
                return i;
            }
        }
    }
    return INVALID_DIAL_KEY_INDEX;
}


/*****************************************************************************
* FUNCTION
*  can_play_cust_tone
* DESCRIPTION
*  This function is used to check if the cust tone can be played or not
*
* PARAMETERS
*  void
*
* RETURNS
*  MMI_TRUE if can be played
*****************************************************************************/
static MMI_BOOL can_play_cust_tone()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((mmi_idle_is_active() || mmi_dialer_is_active()) &&
           (mdi_audio_is_idle() || g_key_tone_cntx.is_playing))
    	ret = MMI_TRUE;
	else
		ret = MMI_FALSE;
#ifdef __MMI_KEY_TONE_UT__
    ret = MMI_TRUE;
#endif /* __MMI_KEY_TONE_UT__ */
    return ret;
}


/*****************************************************************************
* FUNCTION
*  can_play_human_voice_tone
* DESCRIPTION
*  This function is used to check if the human voice tone can be played or not
*
* PARAMETERS
*  void
*
* RETURNS
*  MMI_TRUE if can be played
*****************************************************************************/
static MMI_BOOL can_play_human_voice_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((mmi_idle_is_active() || mmi_dialer_is_active()))
		ret = MMI_TRUE;
	else
		ret = MMI_FALSE;
#ifdef __MMI_KEY_TONE_UT__
    ret = MMI_TRUE;
#endif
    return ret;
}


/*****************************************************************************
* FUNCTION
*  is_tone_enabled
* DESCRIPTION
*  This function is used to check if tone of the specified key can be played
*  or not according to the key tone state.
*
*  In addition to the tone state, the key tone can be played or not still is
*  determined by the tone type
*
* PARAMETERS
*  key_code        :[IN]   mmi key code
*
* RETURNS
*  MMI_TRUE if the tone of the specified key can be played according to the
*  tone state
*****************************************************************************/
static MMI_BOOL is_tone_enabled(U8 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;
	U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_key_tone_cntx.state == MMI_KEY_TONE_DISABLED)
    {
        return MMI_FALSE;
    }
    for (i = 0; i < sizeof(disable_tone_by_key_info) / sizeof(disable_tone_by_key_info[0]); i++)
    {
        if (disable_tone_by_key_info[i] == MAKE_DISABLE_TYPE(g_key_tone_cntx.state))
        {
            i++;
            break;           
        }
    }
    
    while ((i < sizeof(disable_tone_by_key_info) / sizeof(disable_tone_by_key_info[0])))
    {
        if (disable_tone_by_key_info[i] >= MARKER)
        {
            break;
        }
        if (disable_tone_by_key_info[i] == key_code)
        {
            ret = MMI_FALSE;
            break;
        }
        i++;
    } 

    return ret;
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + The following part is the unit test of key tone
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#ifdef __MMI_KEY_TONE_UT__
/*****************************************************************************
* FUNCTION
*  ut_is_tone_enabled
* DESCRIPTION
*  Test function of the function - is_tone_eanbled
*
* PARAMETERS
*  para        :[IN]   reserved
*
* RETURNS
*  MMI_RET_OK
*****************************************************************************/
static mmi_ret ut_is_tone_enabled(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 key_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (key_code = KEY_0; key_code < MAX_KEYS; key_code++)
    {
        
        /* all enabled */
        g_key_tone_cntx.state = MMI_KEY_TONE_ENABLED;
        MMI_ASSERT(is_tone_enabled(key_code) == MMI_TRUE);

        /* all disabled */
        g_key_tone_cntx.state = MMI_KEY_TONE_DISABLED;
        MMI_ASSERT(is_tone_enabled(key_code) == MMI_FALSE);

        /* vol up/vol down disabled */
        g_key_tone_cntx.state = MMI_KEY_VOL_TONE_DISABLED;
        if (key_code == KEY_VOL_UP || key_code == KEY_VOL_DOWN)
        {
            MMI_ASSERT(is_tone_enabled(key_code) == MMI_FALSE);
        }
        else
        {
            MMI_ASSERT(is_tone_enabled(key_code) == MMI_TRUE);
        }

        /* vol up/vol down/up/down disabled */
        g_key_tone_cntx.state = MMI_KEY_VOL_UP_DOWN_TONE_DISABLED;
        if (key_code == KEY_VOL_UP || key_code == KEY_VOL_DOWN || key_code == KEY_UP_ARROW || key_code == KEY_DOWN_ARROW)
        {
            MMI_ASSERT(is_tone_enabled(key_code) == MMI_FALSE);
        }
        else
        {
            MMI_ASSERT(is_tone_enabled(key_code) == MMI_TRUE);
        }

        /* right/left disabled */
        g_key_tone_cntx.state = MMI_KEY_RIGHT_LEFT_ARROW_TONE_DISABLED;
        if (key_code == KEY_RIGHT_ARROW || key_code == KEY_LEFT_ARROW)
        {
            MMI_ASSERT(is_tone_enabled(key_code) == MMI_FALSE);
        }
        else
        {
            MMI_ASSERT(is_tone_enabled(key_code) == MMI_TRUE);
        }        
    }
    kal_prompt_trace(MOD_MMI, "[UT_KEY_TONE]is_tone_enabled test PASS");
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  ut_mmi_frm_kbd_set_tone_state
* DESCRIPTION
*  Test function of the function mmi_frm_kbd_set_tone_state
*
* PARAMETERS
*  para        :[IN]   reserved
*
* RETURNS
*  MMI_RET_OK
*****************************************************************************/
static mmi_ret ut_mmi_frm_kbd_set_tone_state(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (state = MMI_KEY_TONE_ENABLED; state < MMI_KEY_TONE_INVALID; state++)
    {
        mmi_frm_kbd_set_tone_state(state);
        MMI_ASSERT(g_key_tone_cntx.state == state);
    }
    kal_prompt_trace(MOD_MMI, "[UT_KEY_TONE]mmi_frm_kbd_set_tone_state test PASS");
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  ut_mmi_frm_kbd_set_tone_state
* DESCRIPTION
*  Test function of the function mmi_frm_kbd_get_key_tone_state
*
* PARAMETERS
*  para        :[IN]   reserved
*
* RETURNS
*  MMI_RET_OK
*****************************************************************************/
static mmi_ret ut_mmi_frm_kbd_get_key_tone_state(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (state = MMI_KEY_TONE_ENABLED; state < MMI_KEY_TONE_INVALID; state++)
    {
        g_key_tone_cntx.state = state;
        MMI_ASSERT(mmi_frm_kbd_get_key_tone_state() == state);
    }
    kal_prompt_trace(MOD_MMI, "[UT_KEY_TONE]mmi_frm_kbd_get_key_tone_state test PASS");
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  ut_get_dialer_key_index
* DESCRIPTION
*  Test function of the function get_dialer_key_index
*
* PARAMETERS
*  para        :[IN]   reserved
*
* RETURNS
*  MMI_RET_OK
*****************************************************************************/
static mmi_ret ut_get_dialer_key_index(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 key_code;
    S32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (key_code = KEY_0; key_code < MAX_QWERTY_KEYS; key_code++)
    {
        index = get_dialer_key_index(key_code);
        if (key_code >= 0 && key_code <= KEY_9)
        {
            MMI_ASSERT(index == key_code);
        }
        else if (key_code == KEY_STAR)
        {
            MMI_ASSERT(index == 10);
        }
        else if (key_code == KEY_POUND)
        {
            MMI_ASSERT(index == 11);
        }
        else
        {
            MMI_ASSERT(INVALID_DIAL_KEY_INDEX == index);
        }
    }
    kal_prompt_trace(MOD_MMI, "[UT_KEY_TONE]get_dialer_key_index test PASS");
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  ut_get_tone_info
* DESCRIPTION
*  Test function of the function get_tone_info
*
* PARAMETERS
*  para        :[IN]   reserved
*
* RETURNS
*  MMI_RET_OK
*****************************************************************************/
static mmi_ret ut_get_tone_info(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 key_code;
    S32 index;
    U16 tone_id;
    U8 tone_duration;
    srv_prof_keypad_tone_type_enum value;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
		if (srv_prof_get_activated_profile()!= 1)
		{
			kal_prompt_trace(MOD_MMI, "Please set the profile as general");
			return MMI_RET_OK;
		}
    for (key_code = KEY_0; key_code < MAX_QWERTY_KEYS; key_code++)
    {
        value = SRV_PROF_KEYPAD_SILENT;
		srv_prof_set_current_profile_value(SRV_PROF_SETTINGS_KEYPAD_TONE_TYPE, (void *)&value);
        get_tone_info(key_code, &tone_id, &tone_duration);
        MMI_ASSERT(tone_id == DUMMY_TONE_ID);
        MMI_ASSERT(tone_duration == SRV_PROF_RING_TYPE_ONCE);
        
		value = SRV_PROF_KEYPAD_CLICK;
		srv_prof_set_current_profile_value(SRV_PROF_SETTINGS_KEYPAD_TONE_TYPE, (void *)&value);
        get_tone_info(key_code, &tone_id, &tone_duration);
        MMI_ASSERT(tone_id == TONE_KEY_CLICK);
        MMI_ASSERT(tone_duration == SRV_PROF_RING_TYPE_ONCE);
		
		value = SRV_PROF_KEYPAD_TONE;
		srv_prof_set_current_profile_value(SRV_PROF_SETTINGS_KEYPAD_TONE_TYPE, (void *)&value);
		mmi_frm_set_dial_key_tone_type(MMI_DIALER_KEY_TONE_NORMAL);
        mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);
        get_tone_info(key_code, &tone_id, &tone_duration);
        MMI_ASSERT(tone_id == TONE_KEY_NORMAL);
        MMI_ASSERT(tone_duration == SRV_PROF_RING_TYPE_ONCE);
		
		
		mmi_frm_set_dial_key_tone_type(MMI_DIALER_KEY_TONE_DTMF);
        get_tone_info(key_code, &tone_id, &tone_duration);
        if ((index = get_dialer_key_index(key_code)) != INVALID_DIAL_KEY_INDEX)
        {
            MMI_ASSERT(tone_id == g_key_tone[index]);
            MMI_ASSERT(tone_duration == SRV_PROF_RING_TYPE_REPEAT);
        }
        else
        {
            MMI_ASSERT(tone_id == TONE_KEY_NORMAL);
            MMI_ASSERT(tone_duration == SRV_PROF_RING_TYPE_ONCE);
        }
		
        #if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__) && defined(__PLUTO_MMI_PACKAGE__)
        for (value = SRV_PROF_KEYPAD_NUM_1; value <= SRV_PROF_KEYPAD_NUM_6; value++)
        {
			srv_prof_set_current_profile_value(SRV_PROF_SETTINGS_KEYPAD_TONE_TYPE, (void *)&value);
            get_tone_info(key_code, &tone_id, &tone_duration);
            if ((index = get_dialer_key_index(key_code)) != INVALID_DIAL_KEY_INDEX)
            {
                MMI_ASSERT(tone_duration == SRV_PROF_RING_TYPE_ONCE);
            }
            else
            {
                MMI_ASSERT(tone_id == TONE_KEY_NORMAL);
                MMI_ASSERT(tone_duration == SRV_PROF_RING_TYPE_ONCE);
            }
        }
		#endif
		#if defined(__MMI_CUST_KEYPAD_TONE__) && defined(__PLUTO_MMI_PACKAGE__)
        for (value = SRV_PROF_KEYPAD_CUST_1; value <= SRV_PROF_KEYPAD_CUST_6; value++)
        {
			srv_prof_set_current_profile_value(SRV_PROF_SETTINGS_KEYPAD_TONE_TYPE, (void *)&value);
            get_tone_info(key_code, &tone_id, &tone_duration);
            MMI_ASSERT(tone_duration == SRV_PROF_RING_TYPE_ONCE);
        }
		#endif
    }
    kal_prompt_trace(MOD_MMI, "[UT_KEY_TONE]get_tone_info test PASS");
    return MMI_RET_OK;
}


/*==============================================================================*/
static U8 play_code = 0;
static U16 play_id = 0;
static U8 play_duration;
static U8 stop_code = 0;
static U16 stop_id = 0;

/* simulate AudioStopReq */
static void audio_stop_simulate(U16 id)
{
    stop_id = id;
    stop_code = g_key_tone_cntx.key_code;
}

/* simulate AudioPlayReq */
static void audio_play_simulate(U16 id, U8 duration)
{
    play_code = g_key_tone_cntx.key_code;
    play_id = id;
    play_duration = duration;
}


/*****************************************************************************
* FUNCTION
*  ut_mmi_frm_key_tone_player
* DESCRIPTION
*  This function is used to check if tone of the specified key can be played
*  or not according to the key tone state.
*
*  In addition to the tone state, the key tone can be played or not still is
*  determined by the tone type
*
* PARAMETERS
*  key_code        :[IN]   mmi key code
*
* RETURNS
*  MMI_TRUE if the tone of the specified key can be played according to the
*  tone state
*****************************************************************************/
mmi_ret ut_mmi_frm_key_tone_player(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    U8 key_code;
    U8 tone_type;
    U8 tone_state;
    srv_prof_keypad_tone_type_enum value;
	mmi_frm_dial_key_tone_type_enum  dial_key_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (srv_prof_get_activated_profile()!= 1)
	{
		kal_prompt_trace(MOD_MMI, "Please set the profile as general");
		return MMI_RET_OK;
	}
    for (value = SRV_PROF_KEYPAD_SILENT; value <= SRV_PROF_KEYPAD_CUST_6; value++)
    {
		srv_prof_set_current_profile_value(SRV_PROF_SETTINGS_KEYPAD_TONE_TYPE, (void *)&value);
        for (tone_state = MMI_KEY_TONE_ENABLED; tone_state < MMI_KEY_TONE_INVALID; tone_state++)
        {
            mmi_frm_kbd_set_tone_state(tone_state);
            for (dial_key_type = MMI_DIALER_KEY_TONE_DTMF; dial_key_type < MMI_DIALER_KEY_TONE_MAX; dial_key_type++)
			{
				mmi_frm_set_dial_key_tone_type(dial_key_type);
				for (key_code = KEY_0; key_code < MAX_QWERTY_KEYS; key_code++)
				{
					play_code = KEY_INVALID;
					play_id = DUMMY_TONE_ID;
					play_duration = 255;
					if (value == SRV_PROF_KEYPAD_TONE && dial_key_type == MMI_DIALER_KEY_TONE_DTMF && tone_state == MMI_KEY_TONE_DISABLED && key_code == 0)
					{
						int i = 0;
					}
					mmi_frm_key_tone_player(key_code, KEY_EVENT_DOWN);

					stop_code = KEY_INVALID;
					stop_id  = DUMMY_TONE_ID;

					mmi_frm_key_tone_player(key_code, KEY_EVENT_UP);
					if ((value == SRV_PROF_KEYPAD_SILENT) ||
						(tone_state == MMI_KEY_TONE_DISABLED) || 
						(!is_tone_enabled(key_code)))
						//((tone_state == MMI_KEY_VOL_TONE_DISABLED) && (key_code == KEY_VOL_UP || key_code == KEY_VOL_DOWN)) ||
						//((tone_state == MMI_KEY_VOL_UP_DOWN_TONE_DISABLED) && (key_code == KEY_VOL_UP || key_code == KEY_VOL_DOWN || key_code == KEY_UP_ARROW || key_code == KEY_DOWN_ARROW)) ||
						//((tone_state == MMI_KEY_RIGHT_LEFT_ARROW_TONE_DISABLED) && (key_code == KEY_RIGHT_ARROW || key_code == KEY_LEFT_ARROW)))
					{
						MMI_ASSERT(play_code == KEY_INVALID);
						MMI_ASSERT(play_id == DUMMY_TONE_ID);
						MMI_ASSERT(play_duration == 255);
						MMI_ASSERT(stop_code == KEY_INVALID);
						MMI_ASSERT(stop_id == DUMMY_TONE_ID);
					}
					else if (value == SRV_PROF_KEYPAD_CLICK)
					{
						MMI_ASSERT(play_code == key_code);
						MMI_ASSERT(play_id == TONE_KEY_CLICK);
						MMI_ASSERT(play_duration == SRV_PROF_RING_TYPE_ONCE);
						MMI_ASSERT(stop_code == KEY_INVALID);
						MMI_ASSERT(stop_id == DUMMY_TONE_ID);                    
					}
					else if (value == SRV_PROF_KEYPAD_TONE && dial_key_type == MMI_DIALER_KEY_TONE_DTMF)
					{
						if ((index = get_dialer_key_index(key_code)) != INVALID_DIAL_KEY_INDEX)
						{             
							MMI_ASSERT(play_code == key_code);
							MMI_ASSERT(play_id == g_key_tone[index]);
							MMI_ASSERT(play_duration == SRV_PROF_RING_TYPE_REPEAT);
							MMI_ASSERT(stop_code == key_code);
							MMI_ASSERT(stop_id == g_key_tone[index]);              
						}
						else
						{
							MMI_ASSERT(play_code == key_code);
							MMI_ASSERT(play_id == TONE_KEY_NORMAL);
							MMI_ASSERT(play_duration == SRV_PROF_RING_TYPE_ONCE);
							MMI_ASSERT(stop_code == KEY_INVALID);
							MMI_ASSERT(stop_id == DUMMY_TONE_ID);           
						}                   
					}
					else if (value == SRV_PROF_KEYPAD_TONE && tone_state == MMI_KEY_TONE_ENABLED && dial_key_type == MMI_DIALER_KEY_TONE_NORMAL)
					{
						MMI_ASSERT(play_code == key_code);
						MMI_ASSERT(play_id == TONE_KEY_NORMAL);
						MMI_ASSERT(play_duration == SRV_PROF_RING_TYPE_ONCE);
						MMI_ASSERT(stop_code == KEY_INVALID);
						MMI_ASSERT(stop_id == DUMMY_TONE_ID);
					}
					#if defined(__MMI_CUST_KEYPAD_TONE__) && defined(__PLUTO_MMI_PACKAGE__)
					else if (value >= SRV_PROF_KEYPAD_CUST_1 && value <= SRV_PROF_KEYPAD_CUST_6)
					{
						MMI_ASSERT(play_code == key_code);
						MMI_ASSERT(play_duration == SRV_PROF_RING_TYPE_ONCE);
						MMI_ASSERT(stop_code == KEY_INVALID);
						MMI_ASSERT(stop_id == DUMMY_TONE_ID);                
					}
					#endif
					#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__) && defined(__PLUTO_MMI_PACKAGE__) 
					else if (value >= SRV_PROF_KEYPAD_NUM_1 && value <= SRV_PROF_KEYPAD_NUM_6)
					{
	                    
						if ((index = get_dialer_key_index(key_code)) != INVALID_DIAL_KEY_INDEX)
						{
						}
						else
						{
							MMI_ASSERT(play_id == TONE_KEY_NORMAL);
						}
						MMI_ASSERT(play_code == key_code);
						MMI_ASSERT(play_duration == SRV_PROF_RING_TYPE_ONCE);
						MMI_ASSERT(stop_code == KEY_INVALID);
						MMI_ASSERT(stop_id == DUMMY_TONE_ID);                     
					}
					#endif
				}
			}
        }
    }
	value = SRV_PROF_KEYPAD_TONE;
    srv_prof_set_current_profile_value(SRV_PROF_SETTINGS_KEYPAD_TONE_TYPE, (void *)&value);
	mmi_frm_set_dial_key_tone_type(dial_key_type);
	mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    mmi_frm_set_dial_key_tone_type(MMI_DIALER_KEY_TONE_DTMF);
    play_code = KEY_INVALID;
    play_id = DUMMY_TONE_ID;
    play_duration = 255;
    mmi_frm_key_tone_player(KEY_0, KEY_EVENT_DOWN);
    MMI_ASSERT(play_code == KEY_0);
    MMI_ASSERT(play_id == TONE_DTMF_0);
    MMI_ASSERT(play_duration == SRV_PROF_RING_TYPE_REPEAT);
    stop_code = KEY_INVALID;
    stop_id  = DUMMY_TONE_ID;
    mmi_frm_key_tone_player(KEY_1, KEY_EVENT_DOWN);
    MMI_ASSERT(stop_code == KEY_0);
    MMI_ASSERT(stop_id == TONE_DTMF_0);
    stop_code = KEY_INVALID;
    stop_id  = DUMMY_TONE_ID;    
    mmi_frm_key_tone_player(KEY_0, KEY_EVENT_UP);
    MMI_ASSERT(stop_code == KEY_INVALID);
    MMI_ASSERT(stop_id == DUMMY_TONE_ID);
    mmi_frm_key_tone_player(KEY_1, KEY_EVENT_UP);
    MMI_ASSERT(stop_code == KEY_1);
    MMI_ASSERT(stop_id == TONE_DTMF_1);
    kal_prompt_trace(MOD_MMI, "[UT_KEY_TONE]mmi_frm_key_tone_player test PASS");
    return MMI_RET_OK;
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + key tone unit test framework
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/* key unit test table size */
#define KEY_TONE_UT_TABLE_ENTRY  sizeof(g_key_tone_ut_table) / sizeof(g_key_tone_ut_table[0])

/* unit test function */
typedef mmi_ret (*unit_test_func)(void *para);

/* unit test struct */
typedef struct
{
    U8 index;
    unit_test_func test;
} mmi_unit_test_struct;

/* key event unit test table */
const static mmi_unit_test_struct g_key_tone_ut_table[] = 
{
    {1, ut_is_tone_enabled},
    {2, ut_mmi_frm_kbd_set_tone_state},
    {3, ut_mmi_frm_kbd_get_key_tone_state},
    {4, ut_get_dialer_key_index},
    {5, ut_get_tone_info},
    {6, ut_mmi_frm_key_tone_player}
};
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_key_tone_ut
 * DESCRIPTION
 *  This function is key event unit test external interface.
 *  It is invoked in events.c (mmi_proc_inject_string)
 * 
 * PARAMETERS
 *  index         :[IN]  test item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_key_tone_ut(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 0)
    {
        for (i = 0; i < KEY_TONE_UT_TABLE_ENTRY; i++)
        {
            g_key_tone_ut_table[i].test(NULL);
        }
    }
    else
    {
        for (i = 0; i < KEY_TONE_UT_TABLE_ENTRY; i++)
        {
            if (g_key_tone_ut_table[i].index == index)
            {
                g_key_tone_ut_table[i].test(NULL);
            }
        }
    }
}

#endif /* __MMI_KEY_TONE_UT__ */


