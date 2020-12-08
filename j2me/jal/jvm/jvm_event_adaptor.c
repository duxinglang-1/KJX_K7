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
 * jvm_keypad_adaptor.c
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*************************************************************************
 * Include header files
 *************************************************************************/
/*************************************************************************
 * Plutommi include header files
 *************************************************************************/
#include "jal.h"

/*  Include: MMI header file */
#include "mmi_include.h"
#include "CommonScreens.h"
#include "gpioinc.h"

#include "Keypad_sw.h"
#include "j2me_trace.h"
#include "j2me_custom_option.h"
#include "jam_msg_handler.h"
#include "javaAgencyGProt.h"
#include "javaAgencyDef.h"
#include "jui_interface.h"
#include "jvm_adaptor.h"
#include "jwa_internal.h"
#include "kal_release.h"
#include "jvm_internal.h"
#include "jvm_interface.h"
#include "jam_internal.h"
#include "jui_internal.h"
#include "mmiapi_res.h"
#ifdef __COSMOS_MMI_PACKAGE__
#include "vapp_java_srv.h"
#include "IdleGprot.h"
#if defined(__GADGET_SUPPORT__) && !defined(__VM_CONCURRENCE__)
#include "MRESrvGProt.h"
#endif
#endif

/*************************************************************************
 * extern function
 *************************************************************************/
extern kal_bool endKeyPressed;  // TODO: revise
extern kal_bool j2me_in_tck_mode;
//extern kal_uint8 jui_softkey_label[2][32];        //JUI MVM
extern void j2me_lcd_mutex_lock(void);
extern void j2me_lcd_mutex_unlock(void);
//extern int jui_widget_get_current_menu_index(void);   //JUI MVM
//extern void jui_widget_set_current_menu_index(int idx);   //JUI MVM
/* extern void mmi_kbd_set_concurrent_mode(kal_bool mode); */

/*************************************************************************
 * extern variable
 *************************************************************************/
extern S32 MMI_status_bar_height;
#ifdef __COSMOS_MMI_PACKAGE__
extern void vapp_java_screen_switch_entry(void);
#endif
//extern kal_bool jui_is_show_menu; //JUI MVM
extern kal_uint8  *jui_lcd_total_buffer;
/*************************************************************************
 * Gloable variable
 *************************************************************************/

//////////////////////////////////////////////////////////////////////////////////////////////////////
//  JAVA KEYPAD SYSTEM
//////////////////////////////////////////////////////////////////////////////////////////////////////
#define JVM_KEYPAD_RING_BUFFER_SIZE_MASK  0x0f
#define JVM_KEYPAD_RING_BUFFER_SIZE          (JVM_KEYPAD_RING_BUFFER_SIZE_MASK+1)
#define KEY_DOWN_NUM (4)

typedef struct
{
    kal_uint16 code;
    kal_uint16 type;
} jvm_keypad_ring_buffer_struct;


static jvm_keypad_ring_buffer_struct jvm_keypad_ring_buffer[JVM_KEYPAD_RING_BUFFER_SIZE];
static int jvm_keypad_ring_buffer_reader;
static int jvm_keypad_ring_buffer_writer;
static int jvm_keypad_ring_buffer_size;
static kal_mutexid jvm_keypad_mutex;
kal_bool g_jvm_keypad_need_notify;
static kal_bool jvm_keypad_is_first_enter;
static kal_bool jvm_keypad_is_first_resume;
static kal_int16 last_down_key_num = 0;
static kal_int16 last_down_code[KEY_DOWN_NUM];
kal_bool g_jvm_is_show_ncenter = KAL_FALSE;
keypad_cb_funcptr jvm_keypad_event_notifier_cb_ptr = NULL;
tp_cb_funcptr jvm_tp_event_notifier_cb_ptr = NULL;

#define DEC_POS(V)      ((V -1) &  JVM_KEYPAD_RING_BUFFER_SIZE_MASK)
#define INC_POS(V)      ((V +1) &  JVM_KEYPAD_RING_BUFFER_SIZE_MASK)

#define DEC_WRITER      DEC_POS(jvm_keypad_ring_buffer_writer)
#define INC_WRITER      INC_POS(jvm_keypad_ring_buffer_writer)

#define DEC_READER      DEC_POS(jvm_keypad_ring_buffer_reader)
#define INC_READER      INC_POS(jvm_keypad_ring_buffer_reader)

#define WRITER       jvm_keypad_ring_buffer_writer
#define READER       jvm_keypad_ring_buffer_reader
#define RINGSIZE     jvm_keypad_ring_buffer_size

/*************************************************************************
 *  prototype
 *************************************************************************/
void jvm_keypad_init(void);
void jvm_keypad_flush(void);
kal_bool jvm_keypad_fetch(kal_uint16 *code, kal_uint16 *type);
void jvm_keypad_insert(kal_uint16 code, kal_uint16 type);
#if (defined(__MMI_QWERTY_KEYPAD_SUPPORT__) )
mmi_ret jvm_key_proc(mmi_event_struct *evt);
#endif
void jvm_normal_keypad_handler(void);
void jvm_keypad_collector(kal_uint16 keycode, kal_uint16 keytype);
void jvm_keypad_register_notify(void);
void jvm_register_keypad(kal_bool is_resume);
void jvm_unregister_keypad(void);


/*****************************************************************************
 * FUNCTION
 *  jvm_keypad_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_keypad_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_keypad_mutex = kal_create_mutex("jvm kdb");
    g_jvm_keypad_need_notify = KAL_FALSE;
    endKeyPressed = KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  jvm_keypad_event_notifier_register
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fp      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_keypad_event_notifier_register(keypad_cb_funcptr fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_keypad_event_notifier_cb_ptr = fp;

}

/*****************************************************************************
 * FUNCTION
 *  jvm_tp_event_notifier_register
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fp      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_tp_event_notifier_register(tp_cb_funcptr fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_tp_event_notifier_cb_ptr = fp;

}
kal_bool g_jvm_insert_key_for_match_down = KAL_FALSE;
kal_bool g_jvm_insert_tp_for_match_down = KAL_FALSE;
/*****************************************************************************
 * FUNCTION
 *  jvm_keypad_flush
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_keypad_flush(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_9, FUNC_JVM_KEYPAD_FLUSH);
    kal_take_mutex(jvm_keypad_mutex);
    jvm_keypad_ring_buffer_reader = 0;
    jvm_keypad_ring_buffer_writer = 0;
    jvm_keypad_ring_buffer_size = 0;
    endKeyPressed = KAL_FALSE;
    if (!jvm_keypad_is_first_resume)
    {
        for (i = 0; i < KEY_DOWN_NUM; i++)
        {
            if (last_down_code[i] != -1)
            {
                if (jvm_keypad_event_notifier_cb_ptr)
                {
                    (*jvm_keypad_event_notifier_cb_ptr) (last_down_code[i], KEY_EVENT_UP);
                }
                g_jvm_insert_key_for_match_down = KAL_TRUE;
                kal_give_mutex(jvm_keypad_mutex);
                jvm_keypad_insert(last_down_code[i], KEY_EVENT_UP);
                kal_take_mutex(jvm_keypad_mutex);
				jvm_send_keypad_notify_ind();								
                g_jvm_insert_key_for_match_down = KAL_FALSE;
                last_down_code[i] = -1;
            }
        }
        last_down_key_num = 0;
    }
    kal_give_mutex(jvm_keypad_mutex);
}


/*****************************************************************************
 * FUNCTION
 *  jvm_keypad_fetch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  code        [?]     
 *  type        [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jvm_keypad_fetch(kal_uint16 *code, kal_uint16 *type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(jvm_keypad_mutex);
    if (RINGSIZE > 0)
    {
        /*
         * We can enter critical-section only when have keyevent,
         * * worst case is to process the incoming kevent next loop but
         * * would be better for performance.
         */
        *code = jvm_keypad_ring_buffer[READER].code;
        *type = jvm_keypad_ring_buffer[READER].type;
        READER = INC_READER;
        RINGSIZE--;
        result = KAL_TRUE;
    }
    else
    {
        if (jvm_keypad_is_first_resume && last_down_key_num > 0)
        {
            int i;

            for (i = 0; i < KEY_DOWN_NUM; i++)
            {
                if (last_down_code[i] != -1)
                {
                    *code = last_down_code[i];
                    last_down_code[i] = -1;
                    break;
                }
            }

            if (i == KEY_DOWN_NUM)
            {
                ASSERT(0);
            }
            last_down_key_num--;
            *type = KEY_EVENT_UP;
            result = KAL_TRUE;
        }
    }
    kal_give_mutex(jvm_keypad_mutex);

    if (result && !jvm_keypad_is_first_resume)
    {
        int i;

        if (*type == KEY_EVENT_DOWN)
        {
            for (i = 0; i < KEY_DOWN_NUM; i++)
            {
                if (last_down_code[i] == -1)
                {
                    last_down_code[i] = *code;
                    break;
                }
            }
            last_down_key_num++;
        }
        else
        {
            /* up, long press, or repeat without a down key */
            if (last_down_key_num == 0)
            {
                result = KAL_FALSE;
            }
            else if (*type == KEY_EVENT_UP)
            {
                for (i = 0; i < KEY_DOWN_NUM; i++)
                {
                    if (last_down_code[i] == *code)
                    {
                        last_down_code[i] = -1;
                        last_down_key_num--;
                        break;
                    }
                }
            }
        }
        if (last_down_key_num >= 4 || last_down_key_num < 0)
        {
            int i;
            
            result = KAL_FALSE;
            last_down_key_num = 0;
            for (i = 0; i < KEY_DOWN_NUM; i++)
            {
                last_down_code[i] = -1;
            }
        }
    }
    if (last_down_key_num == 0 && jvm_keypad_is_first_resume)
    {
        jvm_keypad_is_first_resume = KAL_FALSE;
    }
    if (result)
    {
        kal_trace(TRACE_GROUP_9, FUNC_JVM_KEYPAD_FETCH, 32767, last_down_key_num);
        kal_trace(TRACE_GROUP_9, FUNC_JVM_KEYPAD_FETCH, (*code), (*type));
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_keypad_insert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  code        [IN]        
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_keypad_insert(kal_uint16 code, kal_uint16 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    kal_bool Is_match_UP = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_9, FUNC_JVM_KEYPAD_INSERT, code, type, endKeyPressed);

    if (endKeyPressed == KAL_FALSE)
    {
        /*
         *  Let LSK and RSK action like MMI 
         */

        //j2me_lcd_mutex_lock();

        /* To avoid the key up on popup screnn and then mismatch on soft button status */
        if ((code == KEY_LSK || code == KEY_RSK) && !g_jvm_insert_key_for_match_down && !g_jvm_insert_tp_for_match_down)
        {
            jui_widget_mvm_softkey_handler(code, type,JUI_WIDGET_UNKNOWN_DISPLAY_ID);
            SetKeyHandler((FuncPtr) jvm_normal_keypad_handler, KEY_LSK, KEY_EVENT_UP);
            SetKeyHandler((FuncPtr) jvm_normal_keypad_handler, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler((FuncPtr) jvm_normal_keypad_handler, KEY_LSK, KEY_EVENT_REPEAT);
            SetKeyHandler((FuncPtr) jvm_normal_keypad_handler, KEY_LSK, KEY_EVENT_LONG_PRESS);
            SetKeyHandler((FuncPtr) jvm_normal_keypad_handler, KEY_RSK, KEY_EVENT_UP);
            SetKeyHandler((FuncPtr) jvm_normal_keypad_handler, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler((FuncPtr) jvm_normal_keypad_handler, KEY_RSK, KEY_EVENT_REPEAT);
            SetKeyHandler((FuncPtr) jvm_normal_keypad_handler, KEY_RSK, KEY_EVENT_LONG_PRESS);
        }

        //j2me_lcd_mutex_unlock();
        kal_take_mutex(jvm_keypad_mutex);
        for (i = 0; i < KEY_DOWN_NUM; i++)
        {
            kal_int16 kcode = last_down_code[i];

            if (kcode == -1)
            {
                continue;
            }
            if (code == kcode && type == KEY_EVENT_UP)
            {
                Is_match_UP = KAL_TRUE;
                break;
            }
        }

        if (RINGSIZE + 6 < JVM_KEYPAD_RING_BUFFER_SIZE || Is_match_UP)
        {
            /* if( RINGSIZE + 6 < (JVM_KEYPAD_RING_BUFFER_SIZE) || type != KEY_EVENT_REPEAT ){ */
            /* reject the repeated key to fill in the last two spaces */
            /* still have room to put the key */
            jvm_keypad_ring_buffer[WRITER].code = code;
            jvm_keypad_ring_buffer[WRITER].type = type;
            WRITER = INC_WRITER;
            RINGSIZE++;
            /* } */
        }
        else if (RINGSIZE > 0)
        {
            int pos = DEC_WRITER;

            /* when we want drop the release key, we should drop the press key together */
            if (type == KEY_EVENT_UP)
            {
                if (jvm_keypad_ring_buffer[pos].type == KEY_EVENT_DOWN && jvm_keypad_ring_buffer[pos].code == code)
                {
                    WRITER = DEC_WRITER;
                    RINGSIZE--;
                }
            }
        }
        kal_give_mutex(jvm_keypad_mutex);
    }

    /* If JVM will sleep for message to wakeup, send that */
    if (g_jvm_keypad_need_notify)
    {
        g_jvm_keypad_need_notify = KAL_FALSE;
        jvm_send_keypad_notify_ind();
    }
}

#if (defined(__MMI_QWERTY_KEYPAD_SUPPORT__) )
kal_bool g_jvm_keypad_qwerty_mode = KAL_FALSE;
/*****************************************************************************
 * FUNCTION
 *  jvm_key_proc
 * DESCRIPTION
 *  collect all key event in qwerty option is ON, insert key event into pool buffer except
 *  END key
 * PARAMETERS
 *  key_code   [S16] 
 *  key_type   [S16] 
 *  ucs2_value [U16]  
 *  key_flag   [U32]
 * RETURNS
 *  BOOL
 *****************************************************************************/
mmi_ret jvm_key_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;
    kal_uint16 Keycode, Keytype;
    //kal_char s[50];
    S16 key_code = key_evt->key_code;
    S16 key_type = key_evt->key_type;
    U16 ucs2_value = key_evt->ucs2_value;
    //U32 key_flag = key_evt->special_key_flag;

    S32 vm_id = jam_mvm_get_current_vm_id();  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_evt->evt_id == EVT_ID_ON_KEY)
    { 
        
        if (key_code == KEY_POWER)
            return   MMI_RET_OK;

        if(key_code != KEY_END && key_type == KEY_LONG_PRESS)
            return MMI_RET_OK;
 
        /* switch number mode and qwerty mode */
        if(key_code == KEY_NUM_LOCK && key_type == KEY_EVENT_UP)
        {
            g_jvm_keypad_qwerty_mode = (g_jvm_keypad_qwerty_mode == KAL_FALSE)?(KAL_TRUE) : (KAL_FALSE);
            if(g_jvm_keypad_qwerty_mode == KAL_TRUE)
            {
                mmi_frm_set_keypad_mode(KEYPAD_2KEY_QWERTY);
            }
            else
            {
                mmi_frm_set_keypad_mode(KEYPAD_2KEY_NUMBER);
            }    
        }

        kal_trace(TRACE_GROUP_9, FUNC_JVM_QWERTY_KEYPAD_HDLR, key_code, key_type, ucs2_value, g_jvm_keypad_qwerty_mode);
        
        Keytype = key_type;
        
        if(key_code < MAX_KEYS)
        {
            Keycode = (kal_uint16)key_code;
    		/* bypass camera */
    		if(Keycode == KEY_CAMERA)
    			return MMI_RET_KEY_HANDLED; 
        }
        else
        {
            if(ucs2_value == 0)
                Keycode = key_code;
            else                                 
                Keycode = ucs2_value + MAX_QWERTY_KEYS;

        }

        if(jam_is_in_fg_screen(vm_id ))
            jvm_keypad_collector(Keycode, Keytype);
        return MMI_RET_KEY_HANDLED;
    }    
    return MMI_RET_OK;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  jvm_normal_keypad_handler
 * DESCRIPTION
 *  collect all key event, insert key event into pool buffer except
 *  END key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_normal_keypad_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 Keycode, Keytype;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    GetkeyInfo(&Keycode, &Keytype);
    jvm_keypad_collector(Keycode, Keytype);
}


//extern kal_uint16 *jui_lcd_buffer;        //JUI MVM


void jvm_back_key_handler()
{
#ifdef __COSMOS_MMI_PACKAGE__
    kal_int32 vm_id = jam_mvm_get_current_vm_id();
    extern kal_int32 g_mmi_java_current_selected_vm_id;
    if(jam_mvm_get_vm_state(vm_id) == JVM_TERMINATING_STATE)
    {
        return;
    }
    jam_mvm_set_vm_need_call_pauseapp(vm_id,KAL_TRUE);
#ifndef J2ME_SUPPORT_BACKGROUND
    jam_enter_terminate_mode(vm_id);
	return;
#endif
    #if defined(J2ME_SUPPORT_PAUSE)
   
        // jvm_keypad_flush();  /* clear java key buffer */
        jvm_tp_flush();
#ifndef J2ME_SLIM_MEMORY_SUPPORT
        if(jui_lcd_total_buffer == NULL)    //JUI MVM
#else
		/* cosmos slim jui_lcd_buffer != NULL when java is fg */
        if(jui_lcd_buffer== NULL && jam_mvm_get_vm_state(vm_id) == JVM_FG_RUNNING_STATE)
#endif
        {
            jam_enter_terminate_mode(vm_id);
        }

        else if (jam_vm_canbe_paused(vm_id) == KAL_TRUE)
        {
            g_mmi_java_current_selected_vm_id = vm_id;
            vapp_java_screen_switch_entry();
        }
    #if defined(J2ME_SUPPORT_BACKGROUND)
        else if (jam_vm_canbe_minimize(vm_id))
        {
            if (vm_id != INVALIDE_VM_ID)
            {
                g_mmi_java_current_selected_vm_id = vm_id;
                vapp_java_screen_switch_entry();
            }
        }
    #endif /* defined(J2ME_SUPPORT_BACKGROUND) */ 
        return;
#elif defined(J2ME_SUPPORT_BACKGROUND)
 
        if(jam_mvm_is_vm_support_bg(vm_id))
        {
            // jvm_keypad_flush();  /* clear java key buffer */
            jvm_tp_flush();
#ifndef J2ME_SLIM_MEMORY_SUPPORT
    		/* cosmos slim jui_lcd_buffer != NULL when java is fg */
            if(jui_lcd_buffer== NULL && jam_mvm_get_vm_state(vm_id) == JVM_FG_RUNNING_STATE)
#else
		    /* cosmos slim jui_lcd_buffer != NULL when java is fg */
            if(jui_lcd_buffer== NULL && jam_mvm_get_vm_state(vm_id) == JVM_FG_RUNNING_STATE)
#endif
            {
                jam_enter_terminate_mode(vm_id);
            }
    
            else if (jam_vm_canbe_paused(vm_id) == KAL_TRUE)
            {
                g_mmi_java_current_selected_vm_id = vm_id;
                vapp_java_screen_switch_entry();
            }
#if defined(J2ME_SUPPORT_BACKGROUND)
            else if (jam_vm_canbe_minimize(vm_id))
            {
                if (vm_id != INVALIDE_VM_ID)
                {
                    g_mmi_java_current_selected_vm_id = vm_id;
                    vapp_java_screen_switch_entry();
                }
            }
#endif /* defined(J2ME_SUPPORT_BACKGROUND) */ 
            return;
        }
		else
		{
		    jam_enter_terminate_mode(vm_id);
            return;
		}

#else
        jam_enter_terminate_mode(vm_id);
        return;
#endif /* defined(J2ME_SUPPORT_PAUSE) || defined(J2ME_SUPPORT_BACKGROUND) */ 
#else
    return;
#endif
}


void jvm_home_key_handler(void)
{
#ifdef __COSMOS_MMI_PACKAGE__
    kal_int32 vm_id = jam_mvm_get_current_vm_id();
    extern kal_int32 g_mmi_java_current_selected_vm_id;
    jam_mvm_set_vm_need_call_pauseapp(vm_id,KAL_TRUE);
#ifndef J2ME_SUPPORT_BACKGROUND
    jam_enter_terminate_mode(vm_id);
	mmi_idle_display();
    //mmi_java_entry_terminating(MMI_FALSE);
    return;
#endif
#if defined(J2ME_SUPPORT_PAUSE)
   
        // jvm_keypad_flush();  /* clear java key buffer */
        jvm_tp_flush();
#ifndef J2ME_SLIM_MEMORY_SUPPORT
        if(jui_lcd_total_buffer == NULL)    //JUI MVM
#else
        /* cosmos slim jui_lcd_buffer != NULL when java is fg */
        if(jui_lcd_buffer== NULL && jam_mvm_get_vm_state(vm_id) == JVM_FG_RUNNING_STATE)    //JUI MVM
#endif
        {
            jam_enter_terminate_mode(vm_id);
            mmi_idle_display();
            return;
        }
        else
        {
            g_mmi_java_current_selected_vm_id = vm_id;
#if defined(__GADGET_SUPPORT__) && !defined(__VM_CONCURRENCE__)
            if (srv_mre_get_bg_app_num() > 0)
            {
                vapp_java_screen_switch_entry();
            }
            else
#endif
            {
                mmi_idle_display();
            }
            return;
        }
#elif defined(J2ME_SUPPORT_BACKGROUND)
    if(jam_mvm_is_vm_support_bg(vm_id))
    {

        // jvm_keypad_flush();  /* clear java key buffer */
        jvm_tp_flush();
#ifndef J2ME_SLIM_MEMORY_SUPPORT
        /* cosmos slim jui_lcd_buffer != NULL when java is fg */
        if(jui_lcd_buffer== NULL && jam_mvm_get_vm_state(vm_id) == JVM_FG_RUNNING_STATE)    //JUI MVM
#else
        /* cosmos slim jui_lcd_buffer != NULL when java is fg */
        if(jui_lcd_buffer== NULL && jam_mvm_get_vm_state(vm_id) == JVM_FG_RUNNING_STATE)    //JUI MVM
#endif
        {
            jam_enter_terminate_mode(vm_id);
            mmi_idle_display();
            return;
        }
        else /*if (jam_vm_canbe_minimize(vm_id))*/
        {
            g_mmi_java_current_selected_vm_id = vm_id;
#if defined(__GADGET_SUPPORT__) && !defined(__VM_CONCURRENCE__)
            if (srv_mre_get_bg_app_num() > 0)
            {
                vapp_java_screen_switch_entry();
            }
            else
#endif
            {
                mmi_idle_display();
            }
            return;
        }
    }
    else /* not support bg */
    {
        jam_enter_terminate_mode(vm_id);
        mmi_idle_display();
        //mmi_java_entry_terminating(MMI_FALSE);
        return;
    }
#endif /* defined(J2ME_SUPPORT_PAUSE) || defined(J2ME_SUPPORT_BACKGROUND) */ 
#else
    return;
#endif
}


void jvm_end_key_handler()
{
#if defined(__PLUTO_MMI_PACKAGE__)
    kal_int32 vm_id = jam_mvm_get_current_vm_id();
    extern kal_int32 g_mmi_java_current_selected_vm_id;
    jam_mvm_set_vm_need_call_pauseapp(vm_id,KAL_TRUE);
#ifndef J2ME_SUPPORT_BACKGROUND
    jam_enter_terminate_mode(vm_id);
#ifdef __PLUTO_MMI_PACKAGE__
	mmi_java_entry_terminating(MMI_FALSE);
#endif
	return;
#endif
    #if defined(J2ME_SUPPORT_PAUSE)
   
        // jvm_keypad_flush();  /* clear java key buffer */
        jvm_tp_flush();
#ifndef J2ME_SLIM_MEMORY_SUPPORT
        if(jui_lcd_total_buffer == NULL)    //JUI MVM
#else
        /* cosmos slim jui_lcd_buffer != NULL when java is fg */
        if(jui_lcd_buffer== NULL && jam_mvm_get_vm_state(vm_id) == JVM_FG_RUNNING_STATE)    //JUI MVM
#endif
        {
            jam_mvm_shutdown_all_req();
        #ifdef __PLUTO_MMI_PACKAGE__
            mmi_java_entry_terminating(MMI_FALSE);         
        #endif        
        }
        else if (jam_vm_canbe_paused(vm_id) == KAL_TRUE)
        {
            g_mmi_java_current_selected_vm_id = vm_id;
            #ifdef __PLUTO_MMI_PACKAGE__
            #if  !defined(__VM_CONCURRENCE__)
             if (srv_mre_get_bg_app_num() > 0)
            {
                 jam_enter_terminate_mode(vm_id);
            }
            else
            #endif
            {
                mmi_java_entry_terminate_dialog();
            }
            #endif
            #ifdef __COSMOS_MMI_PACKAGE__
            jam_enter_terminate_mode(vm_id);
            #endif
        }
    #if defined(J2ME_SUPPORT_BACKGROUND)
        else if (jam_vm_canbe_minimize(vm_id))
        {
            if (vm_id != INVALIDE_VM_ID)
            {
                g_mmi_java_current_selected_vm_id = vm_id;
    #ifdef __PLUTO_MMI_PACKAGE__
        #if  !defined(__VM_CONCURRENCE__)
             if (srv_mre_get_bg_app_num() > 0)
            {
                 jam_enter_terminate_mode(vm_id);
            }
             else
            #endif
            {
                mmi_java_entry_terminate_dialog_without_pause();
            }
    #endif
    #ifdef __COSMOS_MMI_PACKAGE__
                jam_enter_terminate_mode(vm_id);
    #endif
            }
        }
    #endif /* defined(J2ME_SUPPORT_BACKGROUND) */ 
        else
        {
            g_mmi_java_current_selected_vm_id = vm_id;
    #ifdef __PLUTO_MMI_PACKAGE__
            mmi_java_entry_force_terminate_dialog();
    #endif
    #ifdef __COSMOS_MMI_PACKAGE__
            jam_enter_terminate_mode(vm_id);
    #endif
        }
        return;
#elif defined(J2ME_SUPPORT_BACKGROUND)
        if(jam_mvm_is_vm_support_bg(vm_id))
        {
        // jvm_keypad_flush();  /* clear java key buffer */
        jvm_tp_flush();
#ifndef J2ME_SLIM_MEMORY_SUPPORT
        if(jui_lcd_total_buffer == NULL)    //JUI MVM
#else
        /* cosmos slim jui_lcd_buffer != NULL when java is fg */
        if(jui_lcd_buffer== NULL && jam_mvm_get_vm_state(vm_id) == JVM_FG_RUNNING_STATE)
#endif
        {
            jam_mvm_shutdown_all_req();
        #ifdef __PLUTO_MMI_PACKAGE__
            mmi_java_entry_terminating(MMI_FALSE);         
        #endif        
        }
        else if (jam_vm_canbe_paused(vm_id) == KAL_TRUE)
        {
            g_mmi_java_current_selected_vm_id = vm_id;
            #ifdef __PLUTO_MMI_PACKAGE__
            #if  !defined(__VM_CONCURRENCE__)
             if (srv_mre_get_bg_app_num() > 0)
            {
                 jam_enter_terminate_mode(vm_id);
            }
             else
            #endif
            {
                mmi_java_entry_terminate_dialog();
            }
            #endif
            #ifdef __COSMOS_MMI_PACKAGE__
            jam_enter_terminate_mode(vm_id);
            #endif
        }
    #if defined(J2ME_SUPPORT_BACKGROUND)
        else if (jam_vm_canbe_minimize(vm_id))
        {
            if (vm_id != INVALIDE_VM_ID)
            {
                g_mmi_java_current_selected_vm_id = vm_id;
    #ifdef __PLUTO_MMI_PACKAGE__
      #if  !defined(__VM_CONCURRENCE__)
             if (srv_mre_get_bg_app_num() > 0)
            {
                 jam_enter_terminate_mode(vm_id);
            }
             else
            #endif
            {
                mmi_java_entry_terminate_dialog_without_pause();
            }
    #endif
    #ifdef __COSMOS_MMI_PACKAGE__
                jam_enter_terminate_mode(vm_id);
    #endif
            }
        }
    #endif /* defined(J2ME_SUPPORT_BACKGROUND) */ 
        else
        {
            g_mmi_java_current_selected_vm_id = vm_id;
    #ifdef __PLUTO_MMI_PACKAGE__
            mmi_java_entry_force_terminate_dialog();
    #endif
    #ifdef __COSMOS_MMI_PACKAGE__
            jam_enter_terminate_mode(vm_id);
    #endif
        }
        return;
        }
		else
		{
    		jam_enter_terminate_mode(vm_id);
        #ifdef __PLUTO_MMI_PACKAGE__
            mmi_java_entry_terminating(MMI_FALSE);
        #endif
            return;
		}
			
#else
        jam_enter_terminate_mode(vm_id);
    #ifdef __PLUTO_MMI_PACKAGE__
        mmi_java_entry_terminating(MMI_FALSE);
    #endif
        return;
#endif /* defined(J2ME_SUPPORT_PAUSE) || defined(J2ME_SUPPORT_BACKGROUND) */ 
#endif
}


/*****************************************************************************
 * FUNCTION
 *  jvm_keypad_collector
 * DESCRIPTION
 *  collect all key event, insert key event into pool buffer except
 *  END key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_keypad_collector(kal_uint16 Keycode, kal_uint16 Keytype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 vm_id = 0;
    //kal_uint8 wait_time_limit = 0;

#ifdef __THREE_KEY_DETECTION_SWITCHABLE__
    kal_int32 i = 0;
    kal_bool key_matched = KAL_FALSE, accept_two_key_only = KAL_FALSE;
#endif /* __THREE_KEY_DETECTION_SWITCHABLE__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_9, FUNC_JVM_KEYPAD_COLLECTOR);    


    if (jvm_keypad_is_first_enter && Keytype != KEY_EVENT_DOWN) /* drop key */
    {
        return;
    }

    jvm_keypad_is_first_enter = KAL_FALSE;

#ifdef __THREE_KEY_DETECTION_SWITCHABLE__
    kal_trace(TRACE_GROUP_9, FUNC_JVM_KEYPAD_FETCH, 65536, Keytype);
    kal_trace(TRACE_GROUP_9, FUNC_JVM_KEYPAD_FETCH, last_down_key_num, Keycode);
    kal_trace(TRACE_GROUP_9, FUNC_JVM_KEYPAD_FETCH, last_down_code[0], last_down_code[1]);
    kal_trace(TRACE_GROUP_9, FUNC_JVM_KEYPAD_FETCH, last_down_code[2], last_down_code[3]);
    if (Keytype == KEY_EVENT_DOWN && Keycode != KEY_UP_ARROW && Keycode != KEY_DOWN_ARROW &&
        Keycode != KEY_SEND && Keycode != KEY_LEFT_ARROW && Keycode != KEY_RIGHT_ARROW &&
        Keycode != KEY_CSK && last_down_key_num >= 2)
    {
        return;
    }

    for (i = 0; i < KEY_DOWN_NUM; i++)
    {
        kal_int16 kcode = last_down_code[i];

        if (kcode == -1)
        {
            continue;
        }
        if (kcode == Keycode)
        {
            key_matched = KAL_TRUE;
        }
        if (kcode != KEY_UP_ARROW && kcode != KEY_DOWN_ARROW && kcode != KEY_SEND
            && kcode != KEY_LEFT_ARROW && kcode != KEY_RIGHT_ARROW && kcode != KEY_CSK)
        {
            accept_two_key_only = KAL_TRUE;
        }
    }

    if (!key_matched && last_down_key_num >= 2 && accept_two_key_only)
    {
        return;
    }

#endif /* __THREE_KEY_DETECTION_SWITCHABLE__ */ 
    vm_id = jam_mvm_get_current_vm_id();      
#ifdef __PLUTO_MMI_PACKAGE__
    if (Keycode == KEY_END && jam_is_in_fg_screen(vm_id ) && !mmi_java_tck_is_execute())
#elif defined( __COSMOS_MMI_PACKAGE__ )
    if((Keycode ==  KEY_BACK||Keycode == KEY_HOME||Keycode == KEY_END) && jam_is_in_fg_screen(vm_id ) && !mmi_java_tck_is_execute())
#endif
    {
#if defined(J2ME_SUPPORT_PAUSE)
    if(Keycode ==  KEY_BACK)
        jvm_back_key_handler();
    else if(Keycode ==  KEY_HOME)
        jvm_home_key_handler();
    else if(Keycode ==  KEY_END)
        jvm_end_key_handler();
        return;
#elif defined(J2ME_SUPPORT_BACKGROUND)
    if(jam_mvm_is_vm_support_bg(vm_id))
    {
        if(Keycode ==  KEY_BACK)
            jvm_back_key_handler();
        else if(Keycode ==  KEY_HOME)
            jvm_home_key_handler();
        else if(Keycode ==  KEY_END)
            jvm_end_key_handler();
            return;
    }
	else
    {
#ifdef __COSMOS_MMI_PACKAGE__ 
		if(Keycode ==  KEY_END)
		{
			return;
		}
#endif
        mmi_java_entry_terminating(MMI_FALSE);
        g_mmi_java_current_selected_vm_id = vm_id;
        jam_enter_terminate_mode(vm_id);
#ifndef J2ME_SLIM_MEMORY_SUPPORT        
        GoBackHistory();
#endif        
        return;
    }
#else
        mmi_java_entry_terminating(MMI_FALSE);
        g_mmi_java_current_selected_vm_id = vm_id;
        jam_enter_terminate_mode(vm_id);
#ifndef J2ME_SLIM_MEMORY_SUPPORT        
        GoBackHistory();
#endif        
        return;
#endif /* defined(J2ME_SUPPORT_PAUSE) || defined(J2ME_SUPPORT_BACKGROUND) */ 
    }


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
    jvm_keypad_insert(Keycode, Keytype);

    if (jvm_keypad_event_notifier_cb_ptr)
    {
        kal_uint16 keycode;
        kal_uint16 keytype;

        if (jvm_keypad_fetch(&keycode, &keytype))
        {
            (*jvm_keypad_event_notifier_cb_ptr) (keycode, keytype);
        }

    }

}

/*****************************************************************************
 * FUNCTION
 *  jvm_dummy_key_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_dummy_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
}


/*****************************************************************************
 * FUNCTION
 *  jvm_keypad_register_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_keypad_register_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jvm_keypad_need_notify = KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_register_keypad
 * DESCRIPTION
 *  this function will register keypad handler to JVM_redirect_keyevent() function.
 * CALLS
 *  
 * PARAMETERS
 *  is_resume       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_register_keypad(kal_bool is_resume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_QWERTY_KEYPAD_SUPPORT__    
    U16 keyCode = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    endKeyPressed = KAL_FALSE;
    ClearAllKeyHandler();
    clear_left_softkey();
    clear_right_softkey();
    register_default_hide_softkeys();

    /* enable 2 or 3 key simultanenous detection */
#ifdef __TWO_KEY_DETECTION_SWITCHABLE__
    mmi_kbd_set_concurrent_mode(CONCURRENT_KEY_MODE_2_KEYS);
#elif defined(__THREE_KEY_DETECTION_SWITCHABLE__)
    mmi_kbd_set_concurrent_mode(CONCURRENT_KEY_MODE_3_KEYS);
#endif 

    if (is_resume)
    {
        jvm_keypad_is_first_resume = KAL_TRUE;
        jvm_keypad_ring_buffer_reader = 0;
        jvm_keypad_ring_buffer_writer = 0;
        jvm_keypad_ring_buffer_size = 0;
        endKeyPressed = KAL_FALSE;
        //set_left_softkey_label((UI_string_type) jui_softkey_label[0]);    //JUI MVM
        //set_right_softkey_label((UI_string_type) jui_softkey_label[1]);   //JUI MVM

        if (jvm_keypad_event_notifier_cb_ptr)
        {
            kal_uint16 keycode;
            kal_uint16 keytype;

            while (jvm_keypad_fetch(&keycode, &keytype))
            {
                (*jvm_keypad_event_notifier_cb_ptr)(keycode, keytype);
            }
        }

    }
    else
    {
        int i;

        //JUI MVM
        /*jui_softkey_label[0][0] = 0;
        jui_softkey_label[0][1] = 0;
        jui_softkey_label[1][0] = 0;
        jui_softkey_label[1][1] = 0;
        set_left_softkey_label((UI_string_type) jui_softkey_label[0]);
        set_right_softkey_label((UI_string_type) jui_softkey_label[1]);
        */
        jvm_keypad_is_first_enter = KAL_TRUE;
        last_down_key_num = 0;
        for (i = 0; i < KEY_DOWN_NUM; i++)
        {
            last_down_code[i] = -1;
        }
    }

    jvm_keypad_flush();
#if (defined(__MMI_QWERTY_KEYPAD_SUPPORT__) )
    mmi_frm_scrn_set_key_proc(GRP_ID_JAVA_APP, SCR_JAVA_APP, jvm_key_proc);
#else
    for (keyCode = 0; keyCode < MAX_KEYS; keyCode++)
    {
        if(keyCode != KEY_POWER)        
        {            
            SetKeyHandler((FuncPtr) jvm_normal_keypad_handler, keyCode, KEY_EVENT_UP);
            SetKeyHandler((FuncPtr) jvm_normal_keypad_handler, keyCode, KEY_EVENT_DOWN);
            SetKeyHandler((FuncPtr) jvm_normal_keypad_handler, keyCode, KEY_EVENT_REPEAT);
            if(keyCode != KEY_END)        
                SetKeyHandler((FuncPtr) jvm_normal_keypad_handler, keyCode, KEY_EVENT_LONG_PRESS);
        }                
    }
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  jvm_unregister_keypad
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_unregister_keypad(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* disable 2 or 3 key simultanenous detection */
#if defined(__THREE_KEY_DETECTION_SWITCHABLE__) || defined(__TWO_KEY_DETECTION_SWITCHABLE__)
    mmi_kbd_set_concurrent_mode(CONCURRENT_KEY_MODE_1_KEY);
#endif 

    set_left_softkey_label((UI_string_type) 0);
    set_right_softkey_label((UI_string_type) 0);
    clear_left_softkey();
    clear_right_softkey();
    ClearAllKeyHandler();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//  JAVA TouchPanel SYSTEM
//////////////////////////////////////////////////////////////////////////////////////////////////////
#define JVM_TP_RING_BUFFER_SIZE_MASK   0x3F
#define JVM_TP_RING_BUFFER_SIZE        (JVM_TP_RING_BUFFER_SIZE_MASK+1)

typedef struct
{
    kal_uint16 x;
    kal_uint16 y;
    kal_uint16 type;
} jvm_tp_ring_buffer_struct;

static jvm_tp_ring_buffer_struct jvm_tp_ring_buffer[JVM_TP_RING_BUFFER_SIZE];
static int jvm_tp_ring_buffer_reader;
static int jvm_tp_ring_buffer_writer;
static int jvm_tp_ring_buffer_size;
static kal_mutexid jvm_tp_mutex;

/*
 * this variable is used to indicate if Java touch panel is
 * * in virtual direction key mode or normal mode 
 */
static kal_bool tp_virtual_direction = KAL_FALSE;

/*
 * this is the screen slope (x/y) * 65536 ( << 16). The 
 * * value will be used to get the direction of the screen area 
 */
static kal_bool java_level_tp_virtual = KAL_TRUE;

/*
 * this is the screen slope (x/y) * 65536 ( << 16). The 
 * * value will be used to get the direction of the screen area 
 */
static int screen_diagonal_slope;

/*
 * after pressing touch panel on the virtual keypad mode, 
 * * tp moving will triger the kbd_onekey_repeated every 80 ms
 * * this variable is used to memorize the last pressed key event.
 */
static kal_uint16 tp_virtual_last_pressed_key_code = 0;

/*
 * the variable indicates the last touch panel pressed time.
 * * the time is in ticks got by kal_get_time
 */
#ifdef __MMI_TOUCH_SCREEN__
static kal_uint32 last_pressed_ticks = 0;
static kal_bool has_pressed;
#endif /* __MMI_TOUCH_SCREEN__ */ 

#define TP_DEC_POS(V)      ((V -1) &  JVM_TP_RING_BUFFER_SIZE_MASK)
#define TP_INC_POS(V)      ((V +1) &  JVM_TP_RING_BUFFER_SIZE_MASK)

#define TP_DEC_WRITER      TP_DEC_POS(jvm_tp_ring_buffer_writer)
#define TP_INC_WRITER      TP_INC_POS(jvm_tp_ring_buffer_writer)

#define TP_DEC_READER      TP_DEC_POS(jvm_tp_ring_buffer_reader)
#define TP_INC_READER      TP_INC_POS(jvm_tp_ring_buffer_reader)

#define TP_WRITER       jvm_tp_ring_buffer_writer
#define TP_READER       jvm_tp_ring_buffer_reader
#define TP_RINGSIZE     jvm_tp_ring_buffer_size

/*************************************************************************
 *  prototype
 *************************************************************************/
void jvm_tp_init(void);
void jvm_tp_flush(void);
kal_bool jvm_tp_fetch(kal_uint16 *x, kal_uint16 *y, kal_uint16 *type);
void jvm_tp_insert(kal_uint16 x, kal_uint16 y, kal_uint16 type);


/*****************************************************************************
 * FUNCTION
 *  jvm_tp_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_tp_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_tp_mutex = kal_create_mutex("jvm tp");
    g_jvm_keypad_need_notify = KAL_FALSE;
    screen_diagonal_slope = (jui_widget_get_display_width() << 16) / UI_device_height;
}

static kal_int16 last_down_x, last_down_y;

/*****************************************************************************
 * FUNCTION
 *  jvm_tp_flush
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_tp_flush(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(jvm_tp_mutex);
    jvm_tp_ring_buffer_reader = 0;
    jvm_tp_ring_buffer_writer = 0;
    jvm_tp_ring_buffer_size = 0;
#ifdef __MMI_TOUCH_SCREEN__    
    if(has_pressed)
    {
#if 0    	
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif        
        g_jvm_insert_tp_for_match_down = KAL_TRUE;
        kal_give_mutex(jvm_tp_mutex);
        jvm_tp_insert((kal_uint16)last_down_x,(kal_uint16)last_down_y,MMI_PEN_EVENT_UP);
        kal_take_mutex(jvm_tp_mutex);
        g_jvm_insert_tp_for_match_down = KAL_FALSE;
        last_down_x = last_down_y = -1;
    }        
#endif    
    kal_give_mutex(jvm_tp_mutex);
}


/*****************************************************************************
 * FUNCTION
 *  set_virtual_direction
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_direction        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
/*
 * this function is used to set the touch panel mode.
 * * is_derection == KAL_TRUE, use virtual keypad.
 * * is_derection == KAL_FALSE, use normal touch panel.
 */
void set_virtual_direction(kal_bool is_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tp_virtual_direction = is_direction;
}


/*****************************************************************************
 * FUNCTION
 *  set_java_level_virtual_direction
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_direction        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_java_level_virtual_direction(kal_bool is_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tp_virtual_direction && java_level_tp_virtual && !is_direction)
    {
        if (tp_virtual_last_pressed_key_code != 0)
        {
            jvm_keypad_insert(tp_virtual_last_pressed_key_code, KEY_EVENT_UP);
            tp_virtual_last_pressed_key_code = 0;
        }
    }
    java_level_tp_virtual = is_direction;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_tp_fetch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x           [?]     
 *  y           [?]     
 *  type        [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jvm_tp_fetch(kal_uint16 *x, kal_uint16 *y, kal_uint16 *type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (TP_RINGSIZE > 0)
    {
        kal_trace(TRACE_GROUP_9, FUNC_JVM_TP_FETCH_SIZE ,TP_RINGSIZE);    	
        /*
         * We can enter critical-section only when have keyevent,
         * * worst case is to process the incoming kevent next loop but
         * * would be better for performance.
         */
        kal_take_mutex(jvm_tp_mutex);
        *x = jvm_tp_ring_buffer[TP_READER].x;
        *y = jvm_tp_ring_buffer[TP_READER].y;
        *type = jvm_tp_ring_buffer[TP_READER].type;

        /* kal_trace(TRACE_GROUP_9, FUNC_JVM_TP_FETCH,*x,*y,*type); */

        TP_READER = TP_INC_READER;
        TP_RINGSIZE--;
        result = KAL_TRUE;

        kal_give_mutex(jvm_tp_mutex);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_tp_insert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x           [IN]        
 *  y           [IN]        
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_tp_insert(kal_uint16 x, kal_uint16 y, kal_uint16 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_9, FUNC_JVM_TP_INSERT, x, y, type, endKeyPressed);
#ifdef __MMI_TOUCH_SCREEN__
    if (endKeyPressed == KAL_FALSE)
    {
        /* If ring buffer fulled, and "END_Key" pressed, no more touch panel inserted */
        kal_take_mutex(jvm_tp_mutex);
        if (type == MMI_PEN_EVENT_DOWN)
        {
            has_pressed = KAL_TRUE;
        }
        else
        {
            if (type == MMI_PEN_EVENT_UP || type == MMI_PEN_EVENT_MOVE)
            {
                if (has_pressed == KAL_FALSE)
                {
                    kal_give_mutex(jvm_tp_mutex);
                    /* this is not a valid press, just throw the event */
                    return;
                }
                else if (type == MMI_PEN_EVENT_UP)
                {
                    last_down_x = last_down_y = -1;
                    has_pressed = KAL_FALSE;
                }
            }
        }

        if (tp_virtual_direction && java_level_tp_virtual && !jui_widget_mvm_is_in_menu())
        {
            if (type == MMI_PEN_EVENT_UP)
            {
                if (tp_virtual_last_pressed_key_code != 0)
                {
                    jvm_keypad_insert(tp_virtual_last_pressed_key_code, KEY_EVENT_UP);
                    tp_virtual_last_pressed_key_code = 0;
                }
            }
            else
            {
                int direction;

                if (x > ((y * screen_diagonal_slope) >> 16))
                {
                    if (x > (jui_widget_get_display_width() - ((y * screen_diagonal_slope) >> 16)))
                    {
                        direction = KEY_RIGHT_ARROW;
                    }
                    else
                    {
                        direction = KEY_UP_ARROW;
                    }
                }
                else
                {
                    if (x > (jui_widget_get_display_width() - ((y * screen_diagonal_slope) >> 16)))
                    {
                        direction = KEY_DOWN_ARROW;
                    }
                    else
                    {
                        direction = KEY_LEFT_ARROW;
                    }
                }
                if (type == MMI_PEN_EVENT_DOWN)
                {
                    kal_get_time(&last_pressed_ticks);
                    tp_virtual_last_pressed_key_code = direction;
                    jvm_keypad_insert((kal_uint16) direction, KEY_EVENT_DOWN);
                }
                else if (type == MMI_PEN_EVENT_MOVE)
                {
                    if (tp_virtual_last_pressed_key_code != 0)
                    {
                        unsigned int current_ticks;

                        kal_get_time(&current_ticks);
                        if (current_ticks - last_pressed_ticks > 12)
                        {
                            jvm_keypad_insert(tp_virtual_last_pressed_key_code, KEY_EVENT_UP);
                            jvm_keypad_insert((kal_uint16) direction, KEY_EVENT_DOWN);
                            tp_virtual_last_pressed_key_code = direction;
                            last_pressed_ticks = current_ticks;
                        }
                    }
                }
            }
        }
        else
        {
            if (TP_RINGSIZE < JVM_TP_RING_BUFFER_SIZE_MASK)
            {
                /* still have room to put the key */
                jvm_tp_ring_buffer[TP_WRITER].x = x;
                jvm_tp_ring_buffer[TP_WRITER].y = y;
                if(has_pressed)
                {                    
                    last_down_x = (kal_int16) x;
                    last_down_y = (kal_int16) y;
                }
                jvm_tp_ring_buffer[TP_WRITER].type = type;
                TP_WRITER = TP_INC_WRITER;
                TP_RINGSIZE++;
            }
            else if (TP_RINGSIZE > 0)
            {
                /* if the event is pen down or pen move, just throw the event */
                if (type == MMI_PEN_EVENT_DOWN)
                {
                    has_pressed = KAL_FALSE;
                    kal_give_mutex(jvm_tp_mutex);
                    return;
                }
                /* do not thing, just drop the pen event */
            }
        }
        kal_give_mutex(jvm_tp_mutex);
    }
#endif /* __MMI_TOUCH_SCREEN__ */ 
		if(jvm_tp_event_notifier_cb_ptr)
		{
			kal_uint16 x;
			kal_uint16 y;
			kal_uint16 type;
			kal_uint16 cb_type = 3;
			if (jvm_tp_fetch(&x, &y, &type))
			{
				if(type == MMI_PEN_EVENT_DOWN)
				{ 
					cb_type = 0;						            	
				}
				else if(type == MMI_PEN_EVENT_UP)
				{ 
					cb_type = 1;
				}
				else if(type == MMI_PEN_EVENT_MOVE)
				{ 
					cb_type = 2;
				}				
                kal_trace(TRACE_GROUP_9, FUNC_JVM_TP_INSERT_CB, x, y, cb_type);
				if(cb_type < 3)
				{         
				    (*jvm_tp_event_notifier_cb_ptr)(x, y, cb_type);												
				}
			}
						
		}

    /* If JVM will sleep for message to wakeup, send that */
    if (g_jvm_keypad_need_notify)
    {
        g_jvm_keypad_need_notify = KAL_FALSE;
        jvm_send_keypad_notify_ind();
    }
}

#ifdef __MMI_TOUCH_SCREEN__

extern MMI_BOOL wgui_test_rsk_position(mmi_pen_point_struct pos);
extern MMI_BOOL wgui_test_lsk_position(mmi_pen_point_struct pos);
extern int j2me_get_category_index_by_position(int pen_type, mmi_pen_point_struct pos, kal_bool *is_selected);
static kal_bool lsk_pressed;
static kal_bool rsk_pressed;

/*************************************************************************
 *  prototype
 *************************************************************************/
//static void jvm_insert_select(void);
static void jvm_pen_down_hdlr(mmi_pen_point_struct pos);
static void jvm_pen_up_hdlr(mmi_pen_point_struct pos);
static void jvm_pen_move_hdlr(mmi_pen_point_struct pos);
static void jvm_pen_abort_hdlr(mmi_pen_point_struct pos);
static void jvm_pen_repeat_hdlr(mmi_pen_point_struct pos);
static void jvm_pen_long_tap_hdlr(mmi_pen_point_struct pos);

//static void jvm_pen_stroke_down_hdlr(mmi_pen_point_struct pos);   
//static void jvm_pen_stroke_move_hdlr(mmi_pen_point_struct pos);   
//static void jvm_pen_stroke_up_hdlr(mmi_pen_point_struct pos);   
void jvm_register_pen_events(void);
void jvm_unregister_pen_events(void);


/*****************************************************************************
 * FUNCTION
 *  jvm_insert_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
//James modified start1
static void jvm_insert_event_hdlr(mmi_pen_event_type_enum event_type, S16 x, S16 y, mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_NCENTER_SUPPORT__
    wgui_status_icon_bar_pen_enum status_icon_bar_event;
    S32 status_icon_id; 
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!jui_widget_mvm_is_in_fullscreen()) /* normal mode, no status icons */
    {
#ifdef __MMI_NCENTER_SUPPORT__
        if(wgui_status_icon_bar_translate_pen_event(event_type,x,y,&status_icon_id,&status_icon_bar_event))
        {
            g_jvm_is_show_ncenter = KAL_TRUE;
            return;
        }
#endif
        if (y < MMI_status_bar_height)
        {
        #if 0
/* under construction !*/
/* under construction !*/
			#ifdef __MMI_NCENTER_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
			#endif            		
/* under construction !*/
        #endif

	       jvm_tp_insert(x, 0, event_type);
        }
        else
        {
            jvm_tp_insert(x, (S16) (y - MMI_status_bar_height), event_type);
        }
    }
    else
    {
        jvm_tp_insert(x, y, event_type);
    }
}
//James modified end1
/*****************************************************************************
 * FUNCTION
 *  jvm_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void jvm_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
    mmi_event_struct evt;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_9, FUNC_JVM_PEN_DOWN_HDLR, jui_widget_mvm_is_in_fullscreen(), jui_widget_mvm_is_in_menu());
    lsk_pressed = KAL_FALSE;
    rsk_pressed = KAL_FALSE;
    if (!jui_widget_mvm_is_in_fullscreen() || jui_widget_mvm_is_in_menu())
    {
        if (wgui_test_lsk_position(pos))
        {
            kal_trace(TRACE_GROUP_9, FUNC_JVM_PEN_DOWN_HDLR_LSK);

            jui_widget_touch_feedback_play(JUI_WIDGET_TOUCH_FEEDBACK_DOWN); //added for touch feedback
            if(jvm_keypad_event_notifier_cb_ptr)
            {
                lsk_pressed = KAL_TRUE;
				jvm_keypad_event_notifier_cb_ptr(KEY_LSK, KEY_EVENT_DOWN);
				return;
            }	
            jvm_keypad_insert(KEY_LSK, KEY_EVENT_DOWN);
            lsk_pressed = KAL_TRUE;
            return;
        }
        else if (wgui_test_rsk_position(pos))
        {
            kal_trace(TRACE_GROUP_9, FUNC_JVM_PEN_DOWN_HDLR_RSK);
            jui_widget_touch_feedback_play(JUI_WIDGET_TOUCH_FEEDBACK_DOWN); //aded for touch feedback
            if(jvm_keypad_event_notifier_cb_ptr)
            {
				rsk_pressed = KAL_TRUE;
				jvm_keypad_event_notifier_cb_ptr(KEY_RSK, KEY_EVENT_DOWN);
				return;
            }	       
            jvm_keypad_insert(KEY_RSK, KEY_EVENT_DOWN);
            rsk_pressed = KAL_TRUE;     
            return;
        }
    }
    

#if defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
    jvm_tp_insert(pos.x, pos.y, MMI_PEN_EVENT_DOWN);
#else /* defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 
#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
    if ((jui_vk_get_display_id() >= 0 && jui_vk_get_display_id() < MAX_VM_INSTANCE_NUM) &&
        (jui_widget_mvm_get_screen_mode(jui_vk_get_display_id()) == JUI_SCREEN_MODE_NORMAL) &&
        (pos.y >= jui_widget_get_display_height() - jui_widget_get_button_bar_height()) &&
        (pos.y <= jui_widget_get_display_height() + JUI_VIRTUAL_KEYPAD_HEIGHT - jui_widget_get_button_bar_height() - 1))
    {
        jui_vk_pen_down_hdlr(pos.x, pos.y - (jui_widget_get_display_height() - jui_widget_get_button_bar_height()));
        return;
    }
    else if ((jui_vk_get_display_id() >= 0 && jui_vk_get_display_id() < MAX_VM_INSTANCE_NUM) &&
        (jui_widget_mvm_get_screen_mode(jui_vk_get_display_id()) == JUI_SCREEN_MODE_FULL) &&
        (pos.y >= jui_widget_get_display_height()) &&
        (pos.y <= jui_widget_get_display_height() + JUI_VIRTUAL_KEYPAD_HEIGHT - 1))
    {
        jui_vk_pen_down_hdlr(pos.x, pos.y - jui_widget_get_display_height());
        return;
    }
#endif
//James modified start1
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
	jvm_insert_event_hdlr(MMI_PEN_EVENT_DOWN, pos.x,pos.y,&evt);
#else
	jvm_insert_event_hdlr(MMI_PEN_EVENT_DOWN, pos.x,pos.y,NULL);
#endif
//James modified end1
#endif /* defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 
}


/*****************************************************************************
 * FUNCTION
 *  jvm_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void jvm_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_9, FUNC_JVM_PEN_UP_HDLR, jui_widget_mvm_is_in_menu());
    if (lsk_pressed)
    {
        kal_trace(TRACE_GROUP_9, FUNC_JVM_PEN_UP_HDLR_LSK);    
        if(jvm_keypad_event_notifier_cb_ptr)
        {
			lsk_pressed = KAL_FALSE;
         	jvm_keypad_event_notifier_cb_ptr(KEY_LSK, KEY_EVENT_UP);
			return;
        }	        

        jvm_keypad_insert(KEY_LSK, KEY_EVENT_UP);
        lsk_pressed = KAL_FALSE;
        return;
    }
    else if (rsk_pressed)
    {
        kal_trace(TRACE_GROUP_9, FUNC_JVM_PEN_UP_HDLR_RSK);     
        if(jvm_keypad_event_notifier_cb_ptr)
        {
            rsk_pressed = KAL_FALSE;
			jvm_keypad_event_notifier_cb_ptr(KEY_RSK, KEY_EVENT_UP);
			return;
        }
        jvm_keypad_insert(KEY_RSK, KEY_EVENT_UP);
        rsk_pressed = KAL_FALSE;	                
        return;
    }

#if defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
    jvm_tp_insert(pos.x, pos.y, MMI_PEN_EVENT_UP);
#else /* defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 
#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
    if ((jui_vk_get_display_id() >= 0 && jui_vk_get_display_id() < MAX_VM_INSTANCE_NUM) &&
             (jui_widget_mvm_get_screen_mode(jui_vk_get_display_id()) == JUI_SCREEN_MODE_FULL) &&
             (pos.y >= jui_widget_get_display_height()) &&
             (pos.y <= jui_widget_get_display_height() + JUI_VIRTUAL_KEYPAD_HEIGHT - 1))
    {
        jui_vk_pen_up_hdlr(pos.x, pos.y - jui_widget_get_display_height());
        return;
    }
    else
    {
        jui_vk_keypad_highlight_clear();
    }
#endif
//James modified start1
jvm_insert_event_hdlr(MMI_PEN_EVENT_UP, pos.x,pos.y,NULL);
//James modified end1
#endif /* defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 
}


/*****************************************************************************
 * FUNCTION
 *  jvm_pen_move_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void jvm_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_9, FUNC_JVM_PEN_MOVE_HDLR, jui_widget_mvm_is_in_menu());
    if (lsk_pressed || rsk_pressed)
    {
        return;
    }

#if defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
    jvm_tp_insert(pos.x, pos.y, MMI_PEN_EVENT_MOVE);
#else /* defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 
#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
    if ((jui_vk_get_display_id() >= 0 && jui_vk_get_display_id() < MAX_VM_INSTANCE_NUM) &&
        (jui_widget_mvm_get_screen_mode(jui_vk_get_display_id()) == JUI_SCREEN_MODE_NORMAL) &&
        (pos.y >= jui_widget_get_display_height() - jui_widget_get_button_bar_height()) &&
        (pos.y <= jui_widget_get_display_height() + JUI_VIRTUAL_KEYPAD_HEIGHT - jui_widget_get_button_bar_height() - 1))
    {
        jui_vk_pen_move_hdlr(pos.x, pos.y - (jui_widget_get_display_height() - jui_widget_get_button_bar_height()));
        return;
    }
    else if ((jui_vk_get_display_id() >= 0 && jui_vk_get_display_id() < MAX_VM_INSTANCE_NUM) &&
             (jui_widget_mvm_get_screen_mode(jui_vk_get_display_id()) == JUI_SCREEN_MODE_FULL) &&
             (pos.y >= jui_widget_get_display_height()) &&
             (pos.y <= jui_widget_get_display_height() + JUI_VIRTUAL_KEYPAD_HEIGHT - 1))
    {
        jui_vk_pen_move_hdlr(pos.x, pos.y - jui_widget_get_display_height());
        return;
    }
    else
    {
        jui_vk_keypad_highlight_clear();
    }
#endif
//James modified start1
jvm_insert_event_hdlr(MMI_PEN_EVENT_MOVE, pos.x,pos.y,NULL);
//James modified end1
#endif /* defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 

}


/*****************************************************************************
 * FUNCTION
 *  jvm_pen_abort_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void jvm_pen_abort_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
    jvm_tp_insert(pos.x, pos.y, MMI_PEN_EVENT_ABORT);
#else /* defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 
#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
    if ((jui_vk_get_display_id() >= 0 && jui_vk_get_display_id() < MAX_VM_INSTANCE_NUM) &&
        (jui_widget_mvm_get_screen_mode(jui_vk_get_display_id()) == JUI_SCREEN_MODE_NORMAL) &&
        (pos.y >= jui_widget_get_display_height() - jui_widget_get_button_bar_height()) &&
        (pos.y <= jui_widget_get_display_height() + JUI_VIRTUAL_KEYPAD_HEIGHT - jui_widget_get_button_bar_height() - 1))
    {
        jui_vk_pen_up_hdlr(pos.x, pos.y - (jui_widget_get_display_height() - jui_widget_get_button_bar_height()));
        return;
    }
    else if ((jui_vk_get_display_id() >= 0 && jui_vk_get_display_id() < MAX_VM_INSTANCE_NUM) &&
             (jui_widget_mvm_get_screen_mode(jui_vk_get_display_id()) == JUI_SCREEN_MODE_FULL) &&
             (pos.y >= jui_widget_get_display_height()) &&
             (pos.y <= jui_widget_get_display_height() + JUI_VIRTUAL_KEYPAD_HEIGHT - 1))
    {
        jui_vk_pen_up_hdlr(pos.x, pos.y - jui_widget_get_display_height());
        return;
    }
    else
    {
        jui_vk_keypad_highlight_clear();
    }
#endif
//James modified start1
jvm_insert_event_hdlr(MMI_PEN_EVENT_ABORT, pos.x,pos.y,NULL);
//James modified end1
#endif /* defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 
}


/*****************************************************************************
 * FUNCTION
 *  jvm_pen_repeat_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void jvm_pen_repeat_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
    jvm_tp_insert(pos.x, pos.y, MMI_PEN_EVENT_REPEAT);
#else /* defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 
#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
    if ((jui_vk_get_display_id() >= 0 && jui_vk_get_display_id() < MAX_VM_INSTANCE_NUM) &&
        (jui_widget_mvm_get_screen_mode(jui_vk_get_display_id()) == JUI_SCREEN_MODE_NORMAL) &&
        (pos.y >= jui_widget_get_display_height() - jui_widget_get_button_bar_height()) &&
        (pos.y <= jui_widget_get_display_height() + JUI_VIRTUAL_KEYPAD_HEIGHT - jui_widget_get_button_bar_height() - 1))
    {
        jui_vk_pen_repeat_hdlr(pos.x, pos.y - (jui_widget_get_display_height() - jui_widget_get_button_bar_height()));
        return;
    }
    else if ((jui_vk_get_display_id() >= 0 && jui_vk_get_display_id() < MAX_VM_INSTANCE_NUM) &&
             (jui_widget_mvm_get_screen_mode(jui_vk_get_display_id()) == JUI_SCREEN_MODE_FULL) &&
             (pos.y >= jui_widget_get_display_height()) &&
             (pos.y <= jui_widget_get_display_height() + JUI_VIRTUAL_KEYPAD_HEIGHT - 1))
    {
        jui_vk_pen_repeat_hdlr(pos.x, pos.y - jui_widget_get_display_height());
        return;
    }
#endif
//James modified start1
jvm_insert_event_hdlr(MMI_PEN_EVENT_REPEAT, pos.x,pos.y,NULL);
//James modified end1
#endif /* defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 
}


/*****************************************************************************
 * FUNCTION
 *  jvm_pen_long_tap_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void jvm_pen_long_tap_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
    jvm_tp_insert(pos.x, pos.y, MMI_PEN_EVENT_LONG_TAP);
#else /* defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 
#ifdef __SUPPORT_JAVA_VIRTUAL_KEYPAD__
    if ((jui_vk_get_display_id() >= 0 && jui_vk_get_display_id() < MAX_VM_INSTANCE_NUM) &&
        (jui_widget_mvm_get_screen_mode(jui_vk_get_display_id()) == JUI_SCREEN_MODE_NORMAL) &&
        (pos.y >= jui_widget_get_display_height() - jui_widget_get_button_bar_height()) &&
        (pos.y <= jui_widget_get_display_height() + JUI_VIRTUAL_KEYPAD_HEIGHT - jui_widget_get_button_bar_height() - 1))
    {
        jui_vk_pen_long_tp_hdlr(pos.x, pos.y - (jui_widget_get_display_height() - jui_widget_get_button_bar_height()));
        return;
    }
    else if ((jui_vk_get_display_id() >= 0 && jui_vk_get_display_id() < MAX_VM_INSTANCE_NUM) &&
             (jui_widget_mvm_get_screen_mode(jui_vk_get_display_id()) == JUI_SCREEN_MODE_FULL) &&
             (pos.y >= jui_widget_get_display_height()) &&
             (pos.y <= jui_widget_get_display_height() + JUI_VIRTUAL_KEYPAD_HEIGHT - 1))
    {
        jui_vk_pen_long_tp_hdlr(pos.x, pos.y - jui_widget_get_display_height());
        return;
    }
#endif
//James modified start1
jvm_insert_event_hdlr(MMI_PEN_EVENT_LONG_TAP, pos.x,pos.y,0);
//James modified end1
#endif /* defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 
}

/*
 * 
 * static void jvm_pen_stroke_down_hdlr(mmi_pen_point_struct pos){
 * // TODO:
 * }
 * static void jvm_pen_stroke_move_hdlr(mmi_pen_point_struct pos){
 * // TODO:
 * }
 * 
 * static void jvm_pen_stroke_up_hdlr(mmi_pen_point_struct pos){
 * // TODO:
 * }
 */


/*****************************************************************************
 * FUNCTION
 *  jvm_register_pen_events
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_register_pen_events(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_tp_flush();
    wgui_register_pen_down_handler(jvm_pen_down_hdlr);
    wgui_register_pen_up_handler(jvm_pen_up_hdlr);
    wgui_register_pen_move_handler(jvm_pen_move_hdlr);
    wgui_register_pen_long_tap_handler(jvm_pen_long_tap_hdlr);
    wgui_register_pen_repeat_handler(jvm_pen_repeat_hdlr);
    wgui_register_pen_abort_handler(jvm_pen_abort_hdlr);
    //mmi_pen_register_stroke_down_handler(jvm_pen_stroke_down_hdlr);
    //mmi_pen_register_stroke_move_handler(jvm_pen_stroke_move_hdlr);
    //mmi_pen_register_stroke_up_handler(jvm_pen_stroke_up_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  jvm_unregister_pen_events
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_unregister_pen_events(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_register_general_pen_handler();
    /* wgui_register_general_pen_stroke_handler(); */
}

#else /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  jvm_register_pen_events
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_register_pen_events(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  jvm_unregister_pen_events
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_unregister_pen_events(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  jvm_send_keypad_notify_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_send_keypad_notify_ind(void)
{
    java_send_msg_from_active_mod(MOD_J2ME_D,MMI_J2ME_SAP,MSG_ID_JAVA_KEYPAD_NOTIFY_IND,NULL);
}

