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
 *    mmi_frm_qwerty.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   implementation of qwerty module
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
     
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)

//#include "mmi_frm_gprot.h"
//#include "mmi_frm_prot.h"

#include "ImeQwertyProt.h"

//RHR Add
#include "MMIDataType.h"
#include "mmi_frm_input.h"
#include "mmi_frm_input_gprot.h"
#include "kal_general_types.h"
#include "string.h"
#include "GlobalConstants.h"
#include "kal_public_api.h"
#include "GlobalResDef.h"
#include "DebugInitDef_Int.h"
#include "gui_data_types.h"
/*****************************************************************************
 * Defines
 *****************************************************************************/

/*****************************************************************************
 * Typedef
 *****************************************************************************/
typedef struct
{
    U32 special_key_flag_common;
    U32 special_key_flag;                             /* Special key status flag, SHIFT, CTRL, ALT... */
    U32 special_key_lock_flags;
    U16 pre_down_key;
    U32 special_key_flag_bak;                             /* Special key status flag, SHIFT, CTRL, ALT... */
    U32 special_key_lock_flags_bak;
    U16 pre_down_key_bak;
    U32 invalid_customized_special_key_flag;
    mmi_frm_qwerty_keypad_mode_enum keypad_mode;  /* Keypad mode */
    mmi_frm_qwerty_customized_special_key_flag_change_callback_funcptr customized_special_key_flag_change_callback;
}mmi_fram_qwerty_context_struct, *mmi_fram_qwerty_context_struct_p;

/*****************************************************************************
 * Global variables
 *****************************************************************************/

/*****************************************************************************
 * Local variables
 *****************************************************************************/
static mmi_fram_qwerty_context_struct g_mmi_frm_qwerty_context;

/*****************************************************************************
 * Local functions
 *****************************************************************************/
static void mmi_frm_qwerty_update_customized_special_key_status(S16 mmi_key_code, S16 mmi_key_type);
static MMI_BOOL mmi_frm_qwerty_is_valid_customized_special_key(S16 mmi_key_code);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_qwerty_init
 * DESCRIPTION
 *  Initialize qwerty module
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_frm_qwerty_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_mmi_frm_qwerty_context, 0, sizeof(mmi_fram_qwerty_context_struct));

    g_mmi_frm_qwerty_context.pre_down_key = KEY_INVALID;

    g_mmi_frm_qwerty_context.customized_special_key_flag_change_callback = NULL;
        
    mmi_frm_qwerty_set_keypad_mode(MMI_FRM_QWERTY_MODE_NUMBER);

    mmi_imm_qwerty_init();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_qwerty_is_special_key
 * DESCRIPTION
 *  Is special key which support multi-key mode
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_frm_qwerty_is_special_key(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_imm_qwerty_is_special_key(mmi_key_code);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_qwerty_pre_key_routing_cb
 * DESCRIPTION
 *  Update qwerty key status when pre key event
 * PARAMETERS
 *  evt        :[IN] key event
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_qwerty_pre_key_routing_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(key_evt->evt_id == EVT_ID_PRE_KEY_EVT_ROUTING);
    if (key_evt->key_code == KEY_SHIFT)
    {
       if (key_evt->key_type == KEY_EVENT_DOWN)
       {
           g_mmi_frm_qwerty_context.special_key_flag_common |= MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT;
       }
       else if (key_evt->key_type == KEY_EVENT_UP)
       {
           g_mmi_frm_qwerty_context.special_key_flag_common &= ~MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT;
       }
    }

    if (key_evt->key_code == KEY_FN)
    {
       if (key_evt->key_type == KEY_EVENT_DOWN)
       {
           g_mmi_frm_qwerty_context.special_key_flag_common |= MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN;
       }
       else if (key_evt->key_type == KEY_EVENT_UP)
       {
           g_mmi_frm_qwerty_context.special_key_flag_common &= ~MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN;
       }
    }
    
    if (key_evt->key_type != KEY_EVENT_UP)
    {
        mmi_frm_qwerty_update_customized_special_key_status(key_evt->key_code, key_evt->key_type);
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_qwerty_post_key_routing_cb
 * DESCRIPTION
 *  Post key event routing event call back
 * PARAMETERS
 *  evt        :[IN]  key event   
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_qwerty_post_key_routing_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(key_evt->evt_id == EVT_ID_POST_KEY_EVT_ROUTING);
    if (key_evt->key_type == KEY_EVENT_UP)
    {
        mmi_frm_qwerty_update_customized_special_key_status(key_evt->key_code, key_evt->key_type);
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_qwerty_update_customized_special_key_status
 * DESCRIPTION
 *  Update qwerty key status
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_frm_qwerty_update_customized_special_key_status(S16 mmi_key_code, S16 mmi_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 old_flag, old_lock_flag;
    MMI_BOOL is_ime_sdk_handled;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_qwerty_is_valid_customized_special_key(mmi_key_code))
    {
        return;
    }

    old_flag = g_mmi_frm_qwerty_context.special_key_flag;

    old_lock_flag = g_mmi_frm_qwerty_context.special_key_lock_flags;
    
    is_ime_sdk_handled = mmi_imm_qwerty_custom_update_special_key_status(mmi_key_code,
                                                                         mmi_key_type,
                                                                         &g_mmi_frm_qwerty_context.special_key_flag,
                                                                         &g_mmi_frm_qwerty_context.special_key_lock_flags);
    
    if (is_ime_sdk_handled == MMI_FALSE)
    {
        if (mmi_key_code != KEY_SHIFT && mmi_key_code != KEY_FN)
        {
            if (mmi_key_type == KEY_EVENT_UP)
            {
                if ((g_mmi_frm_qwerty_context.special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT)
                     && !(g_mmi_frm_qwerty_context.special_key_lock_flags & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT)
                     && !(g_mmi_frm_qwerty_context.special_key_flag_common & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT))
                {
                    g_mmi_frm_qwerty_context.special_key_flag &= ~MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT;
                }
    
                if ((g_mmi_frm_qwerty_context.special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN)
                     && !(g_mmi_frm_qwerty_context.special_key_lock_flags & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN)
                     && !(g_mmi_frm_qwerty_context.special_key_flag_common & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN))
                {
                    g_mmi_frm_qwerty_context.special_key_flag &= ~MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN;
    
                    g_mmi_frm_qwerty_context.special_key_flag = g_mmi_frm_qwerty_context.special_key_flag_bak;
                    g_mmi_frm_qwerty_context.special_key_lock_flags = g_mmi_frm_qwerty_context.special_key_lock_flags_bak;
                    g_mmi_frm_qwerty_context.pre_down_key = g_mmi_frm_qwerty_context.pre_down_key_bak;
                }
            }
        }
    
        if (mmi_key_code == KEY_SHIFT && !(g_mmi_frm_qwerty_context.special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN)
            && !(g_mmi_frm_qwerty_context.special_key_lock_flags & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_NUMLOCK))
        {
           if (mmi_key_type == KEY_EVENT_DOWN)
           {
               if (!(g_mmi_frm_qwerty_context.special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT))
               {
                   g_mmi_frm_qwerty_context.special_key_flag = MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT;
			       g_mmi_frm_qwerty_context.special_key_lock_flags = 0;
               }
               else if ((g_mmi_frm_qwerty_context.special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT)
			            && !(g_mmi_frm_qwerty_context.special_key_lock_flags & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT))
               {
                   g_mmi_frm_qwerty_context.special_key_lock_flags = MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT;
               }
               else if (g_mmi_frm_qwerty_context.special_key_lock_flags & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT)
               {
                   g_mmi_frm_qwerty_context.special_key_flag &= ~MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT;
			       g_mmi_frm_qwerty_context.special_key_lock_flags &= ~MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT;
               }
           }
           else if (mmi_key_type == KEY_EVENT_UP)
           {
               if ((g_mmi_frm_qwerty_context.special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT)
                     && !(g_mmi_frm_qwerty_context.special_key_lock_flags & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT)
                     && g_mmi_frm_qwerty_context.pre_down_key != KEY_SHIFT)
               {
                    g_mmi_frm_qwerty_context.special_key_flag &= ~MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT;
               }
           }
        }
        else if (mmi_key_code == KEY_FN)
        {
           if (mmi_key_type == KEY_EVENT_DOWN)
           {
               if (!(g_mmi_frm_qwerty_context.special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN))
               {
                   g_mmi_frm_qwerty_context.special_key_flag_bak = g_mmi_frm_qwerty_context.special_key_flag;
                   g_mmi_frm_qwerty_context.special_key_lock_flags_bak = g_mmi_frm_qwerty_context.special_key_lock_flags;
                   g_mmi_frm_qwerty_context.pre_down_key_bak = g_mmi_frm_qwerty_context.pre_down_key;
                   
                   g_mmi_frm_qwerty_context.special_key_flag = MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN;
			       g_mmi_frm_qwerty_context.special_key_lock_flags = 0;
               }
               else if ((g_mmi_frm_qwerty_context.special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN)
			            && !(g_mmi_frm_qwerty_context.special_key_lock_flags & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN))
               {
                   g_mmi_frm_qwerty_context.special_key_lock_flags = MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN;
               }
               else if (g_mmi_frm_qwerty_context.special_key_lock_flags & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN)
               {
                   g_mmi_frm_qwerty_context.special_key_flag &= ~MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN;
			       g_mmi_frm_qwerty_context.special_key_lock_flags &= ~MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN;
    
                   g_mmi_frm_qwerty_context.special_key_flag = g_mmi_frm_qwerty_context.special_key_flag_bak;
                   g_mmi_frm_qwerty_context.special_key_lock_flags = g_mmi_frm_qwerty_context.special_key_lock_flags_bak;
                   g_mmi_frm_qwerty_context.pre_down_key = g_mmi_frm_qwerty_context.pre_down_key_bak;
               }
           }
           else if (mmi_key_type == KEY_EVENT_UP)
           {
               if ((g_mmi_frm_qwerty_context.special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN)
                     && !(g_mmi_frm_qwerty_context.special_key_lock_flags & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN)
                     && g_mmi_frm_qwerty_context.pre_down_key != KEY_FN)
               {
                   g_mmi_frm_qwerty_context.special_key_flag &= ~MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN;
    
                   g_mmi_frm_qwerty_context.special_key_flag = g_mmi_frm_qwerty_context.special_key_flag_bak;
                   g_mmi_frm_qwerty_context.special_key_lock_flags = g_mmi_frm_qwerty_context.special_key_lock_flags_bak;
                   g_mmi_frm_qwerty_context.pre_down_key = g_mmi_frm_qwerty_context.pre_down_key_bak;
               }
           }
        }
        else if (mmi_key_code == KEY_NUM_LOCK)
        {
           if (mmi_key_type == KEY_EVENT_DOWN)
           {
               if (g_mmi_frm_qwerty_context.special_key_lock_flags & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_NUMLOCK)
               {
                   g_mmi_frm_qwerty_context.special_key_flag = 0;
                   g_mmi_frm_qwerty_context.special_key_lock_flags = 0;
               }
               else 
               {
                   g_mmi_frm_qwerty_context.special_key_flag = 0;
                   g_mmi_frm_qwerty_context.special_key_lock_flags = MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_NUMLOCK;
               }
           }
        } 
    }
    if (mmi_key_type == KEY_EVENT_DOWN)
    {
        g_mmi_frm_qwerty_context.pre_down_key = mmi_key_code;
    }

    if (old_flag != g_mmi_frm_qwerty_context.special_key_flag || old_lock_flag != g_mmi_frm_qwerty_context.special_key_lock_flags)
    {
        if (g_mmi_frm_qwerty_context.customized_special_key_flag_change_callback != NULL)
        {
            g_mmi_frm_qwerty_context.customized_special_key_flag_change_callback(g_mmi_frm_qwerty_context.special_key_flag, g_mmi_frm_qwerty_context.special_key_lock_flags);

        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_qwerty_is_valid_customized_special_key
 * DESCRIPTION
 *  Check the special key's validation
 * PARAMETERS
 * RETURNS
 *  If valid key
 *****************************************************************************/
static MMI_BOOL mmi_frm_qwerty_is_valid_customized_special_key(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_key_code == KEY_SHIFT 
        && (g_mmi_frm_qwerty_context.invalid_customized_special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT))
    {
        return MMI_FALSE;
    }
    else if (mmi_key_code == KEY_FN
             && (g_mmi_frm_qwerty_context.invalid_customized_special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN))
    {
        return MMI_FALSE;
    }
    else if (mmi_key_code == KEY_NUM_LOCK
             && (g_mmi_frm_qwerty_context.invalid_customized_special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_NUMLOCK))
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_qwerty_get_opposite_key_code
 * DESCRIPTION
 *  Get opposited mmi key code
 * PARAMETERS
 * RETURNS
 *  Opposite mmi key code
 *****************************************************************************/
S16 mmi_frm_qwerty_get_opposite_key_code(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_imm_qwerty_get_opposite_key_code(mmi_key_code);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_qwerty_convert_key_code
 * DESCRIPTION
 *  Convert mmi key code by current mode (normal or number)
 * PARAMETERS
 * RETURNS
 *  Converted mmi key code
 *****************************************************************************/
S16 mmi_frm_qwerty_convert_key_code(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 converted_code;
    U32 translated_code;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    translated_code = mmi_imm_qwerty_get_translated_key_code_of_current_lang(mmi_key_code, g_mmi_frm_qwerty_context.special_key_flag_common);

    if (MMI_FRM_QWERTY_INVALID_TRANSLATED_CODE != translated_code)
    {
        if (MMI_QWERTY_GET_MMI_KEY_CODE(translated_code) != 0)
        {
            return MMI_QWERTY_GET_MMI_KEY_CODE(translated_code);
        }
    }
    
    if (g_mmi_frm_qwerty_context.keypad_mode == MMI_FRM_QWERTY_MODE_STANDARD)
    {
        if ((mmi_key_code >= KEY_0 && mmi_key_code <= KEY_9) || mmi_key_code == KEY_POUND || mmi_key_code == KEY_STAR)
        {
            return mmi_imm_qwerty_get_opposite_key_code(mmi_key_code);
        }
        else
        {
            return mmi_key_code;
        }
    }
    else if (g_mmi_frm_qwerty_context.keypad_mode == MMI_FRM_QWERTY_MODE_NUMBER)
    {
        converted_code = mmi_imm_qwerty_get_opposite_key_code(mmi_key_code);

        if ((converted_code >= KEY_0 && converted_code <= KEY_9)
            || converted_code == KEY_POUND || converted_code == KEY_STAR)
        {
            return converted_code;
        }
        else
        {
            return mmi_key_code;
        }
    }
    else
    {
        MMI_ASSERT(0);
    }

	return mmi_key_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_qwerty_get_translated_code_and_special_key_flag
 * DESCRIPTION
 *  Get translated key code and current special_key key flag
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_frm_qwerty_get_translated_code_and_special_key_flag(S16 mmi_key_code, U16 *ucs2_value, U32 *special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 translated_code;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    translated_code = mmi_imm_qwerty_get_translated_key_code_of_current_lang(mmi_key_code, g_mmi_frm_qwerty_context.special_key_flag);

    *ucs2_value = MMI_QWERTY_GET_UCS2_CODE(translated_code);

    *special_key_flag = g_mmi_frm_qwerty_context.special_key_flag_common;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_qwerty_set_keypad_mode
 * DESCRIPTION
 *  Set keypad mode
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_frm_qwerty_set_keypad_mode(mmi_frm_qwerty_keypad_mode_enum key_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mmi_frm_qwerty_context.keypad_mode = key_mode;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_frm_qwerty_register_customized_special_key_flag_change_callback
 * DESCRIPTION
 *  This function is used to register customized special key flag change call back.
 *  This function is used by IME module.
 *  when customized special key flag change, framwork qwerty module will invoke this
 *  call back.
 * PARAMETERS
 *  f         :[IN]  special key changed call back
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_qwerty_register_customized_special_key_flag_change_callback(mmi_frm_qwerty_customized_special_key_flag_change_callback_funcptr f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mmi_frm_qwerty_context.customized_special_key_flag_change_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_qwerty_clear_customized_special_key_flag_change_callback
 * DESCRIPTION
 *  This function is used to clear customized special key flag change callback function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_qwerty_clear_customized_special_key_flag_change_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mmi_frm_qwerty_context.customized_special_key_flag_change_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_qwerty_reset_key_status
 * DESCRIPTION
 *  reset special key flag and special key lock state. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_qwerty_reset_key_status(void)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mmi_frm_qwerty_context.special_key_lock_flags = 0;
    g_mmi_frm_qwerty_context.special_key_flag = 0;

    if (g_mmi_frm_qwerty_context.customized_special_key_flag_change_callback != NULL)
    {
        g_mmi_frm_qwerty_context.customized_special_key_flag_change_callback(g_mmi_frm_qwerty_context.special_key_flag, g_mmi_frm_qwerty_context.special_key_lock_flags);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_qwerty_get_customized_special_key_flag
 * DESCRIPTION
 *  IME module uses this interface to get the special key flag that customized by IME
 * PARAMETERS
 *  void
 * RETURNS
 *  special key flag
 *****************************************************************************/
U32  mmi_frm_qwerty_get_customized_special_key_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_mmi_frm_qwerty_context.special_key_flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_qwerty_set_invalid_customized_special_key
 * DESCRIPTION
 *  If IME want to ignore some special key's change, it may use this interface
 *  to set this information.
 * PARAMETERS
 *  special_key_flag  :[IN] special flag that needs to be ignore.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_qwerty_set_invalid_customized_special_key(U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mmi_frm_qwerty_context.invalid_customized_special_key_flag = special_key_flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_qwerty_get_invalid_customized_special_key
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
U32 mmi_frm_qwerty_get_invalid_customized_special_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_mmi_frm_qwerty_context.invalid_customized_special_key_flag;
}

#endif /* #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__) */


