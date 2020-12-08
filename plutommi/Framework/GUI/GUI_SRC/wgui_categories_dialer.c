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
 *  wgui_categories_dialer.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Dialer related categories.
 *
 *  Author:
 * -------
 *  Viki Hung (MTK01926)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/


#include "mmi_frm_gprot.h"
#include "WguiCategoryGprot.h"
#include "Globaldefs.h"

/* for playRequestedTone(ERROR_TONE); */
#include "ProfilesSrvGprot.h"
#include "SettingProfile.h"
/* RHR header*/
#include "wgui_inputs.h"

#ifdef __MMI_ANIMATED_DIAL__

static void DrawCate631CategoryControlArea1(dm_coordinates *coordinate);
static void wgui_anim_dial_get_keycode_img_id(MMI_key_code_type key_code, S32 *img_id);
static void wgui_anim_dial_get_keycode_dspr_img_id(MMI_key_code_type key_code, S32 *img_id);
static void wgui_anim_dial_get_cursor_img_id(S32 *img_id);
static void wgui_anim_dial_play_fly_in_animation(void);
static void wgui_anim_dial_redraw(void);
static void wgui_anim_dial_insert_char_to_buffer(U8 character);
static MMI_BOOL wgui_anim_dial_clear_one_char(void);
static void wgui_anim_dial_delete_all(void);
static void wgui_anim_dial_change_clear_key_up_func(void);
static void wgui_anim_dial_RSK_key_up_handler(void);
static void wgui_anim_dial_init(
                S32 animated_dial_x, 
                S32 animated_dial_y,
                S32 animated_dial_w,
                S32 animated_dial_h,
                UI_buffer_type buffer,
                S32 buffer_size,
                U8 *history_buffer);

void wgui_anim_dail_animation_lastframe_callback(GDI_RESULT result);
void wgui_anim_dial_backspace(void);
void wgui_anim_dial_complete_multitap(void);
void wgui_anim_dial_multitap_key_down(void);
void wgui_anim_dial_star_key_down(void);
void wgui_anim_dial_key_down_handler(MMI_key_code_type key_code);
void wgui_anim_dial_digit_key_handler(void);
void wgui_anim_dial_move_cursor_previous_character(void);
void wgui_anim_dial_move_cursor_next_character(void);
void wgui_anim_dial_move_cursor_previous_line(void);
void wgui_anim_dial_move_cursor_next_line(void);

U8 wgui_anim_dial_set_category_history(U16 history_ID, U8 *history_buffer);
void wgui_anim_dial_get_category_history(U16 history_ID, U8 *history_buffer);
U8 *GetCategory631History(U8 *history_buffer);
S32 GetCategory631HistorySize(void);
void ExitCategory631Screen(void);

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define max(a,b)        (((a) > (b)) ? (a) : (b))
#define min(a,b)        (((a) < (b)) ? (a) : (b))

#ifdef __MMI_MULTITAP_KEY_0__   
    UI_character_type wgui_anim_dial_zero_key_string[] = { '+', 'p', 'w', '\0' };
#else   
    UI_character_type wgui_anim_dial_star_key_string[] = { '*', '+', 'p', 'w', '\0' };
#endif 

wgui_animated_dial_cntx_struct *g_anim_dial_cntx_p = NULL;
static void (*g_wgui_anim_dial_not_empty_callback) (void) = NULL;
static void (*g_wgui_anim_dial_empty_callback) (void) = NULL;

typedef struct _wgui_anim_dial_category_history
{
    S32 final_text_pos;             /* the current number of dial numbers in the buffer */
    S32 curr_cursor_pos;           /* the current position of cursor */
    S32 start_draw_pos;            /* the index of dial numbers to draw first */
    S32 img_size_level;            /* when the screen can't contain all dial numbers, show smaller imgs */
    U16 history_ID;
} wgui_anim_dial_category_history;

enum wgui_anim_dial_anim_style
{
    WGUI_ANIM_DIAL_ANIM_NONE = 0,
    WGUI_ANIM_DIAL_ANIM_MOVE_CURSOR,
    WGUI_ANIM_DIAL_ANIM_KEY_IN,
    WGUI_ANIM_DIAL_ANIM_CLEAR
};
#endif /*__MMI_ANIMATED_DIAL__*/


#ifdef __MMI_ANIMATED_DIAL__
/*****************************************************************************
 * FUNCTION
 *  wgui_anim_dial_change_clear_key_up_func
 * DESCRIPTION
 *  used to change the clear key or RSK KEY_UP handler when buffer 
 *  from empty to not empty or vice versa
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coordinates of category controlled area.
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_anim_dial_change_clear_key_up_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len;
    wgui_animated_dial_cntx_struct *ad_cntx = g_anim_dial_cntx_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = gui_strlen((UI_string_type)ad_cntx->dial_buffer);

    if (len != 0)
    {
        if (ad_cntx->is_buf_empty)
        {
            /* There are some characters in dial buffer (0->1) */
        #if defined(__MMI_WITH_C_KEY__)
            if (g_wgui_anim_dial_not_empty_callback != NULL)
            {
                (*g_wgui_anim_dial_not_empty_callback)();
            }
            SetKeyHandler(wgui_anim_dial_delete_all, KEY_CLEAR, KEY_LONG_PRESS);         //clear key 
            SetKeyHandler(wgui_anim_dial_backspace, KEY_CLEAR, KEY_EVENT_DOWN);
            SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_UP);
        #else
            //set left softkey label
            /* can't use change_right_softkey() here, because it will call reset_softkey() */
            set_right_softkey_label(get_string(STR_GLOBAL_CLEAR));
            set_right_softkey_icon(get_image(IMAGE_ID_NULL));
            if (g_wgui_anim_dial_not_empty_callback != NULL)
            {
                (*g_wgui_anim_dial_not_empty_callback)();
            }
            redraw_right_softkey();
            set_right_softkey_function(UI_dummy_function, KEY_EVENT_UP);
            set_right_softkey_function(wgui_anim_dial_backspace, KEY_EVENT_DOWN);
        #endif
            ad_cntx->is_buf_empty = FALSE;
        }
    }
    else
    {
        if (!ad_cntx->is_buf_empty)
        {
            /* There is no character in dial buffer (1->0) */
        #if defined(__MMI_WITH_C_KEY__)
            if (g_wgui_anim_dial_empty_callback != NULL)
            {
                (*g_wgui_anim_dial_empty_callback)();
            }
            SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_LONG_PRESS);         //clear key 
            SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_DOWN);
            SetKeyHandler(wgui_anim_dial_RSK_key_up_handler, KEY_CLEAR, KEY_EVENT_UP);
        #else
            //set left softkey label
            /* can't use change_right_softkey() here, because it will call reset_softkey() */
            set_right_softkey_label(get_string(STR_GLOBAL_BACK));
            set_right_softkey_icon(get_image(IMAGE_ID_NULL));
            if (g_wgui_anim_dial_empty_callback != NULL)
            {
                (*g_wgui_anim_dial_empty_callback)();
            }
            redraw_right_softkey();
            set_right_softkey_function(wgui_anim_dial_RSK_key_up_handler, KEY_EVENT_UP);
            set_right_softkey_function(UI_dummy_function, KEY_EVENT_DOWN);
        #endif
            ad_cntx->is_buf_empty = TRUE;
        }
    }
}   


/*****************************************************************************
 * FUNCTION
 *  wgui_anim_dial_RSK_key_up_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_anim_dial_RSK_key_up_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_animated_dial_cntx_struct *ad_cntx = g_anim_dial_cntx_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (ad_cntx->anim_dial_RSK_key_up_func != NULL)
    {
        ad_cntx->anim_dial_RSK_key_up_func();
    }
}


/*****************************************************************************
 * FUNCTION
 *  DrawCate631CategoryControlArea1
 * DESCRIPTION
 *  Draws the category631 category control area1
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coordinates of category controlled area.
 * RETURNS
 *  void
 *****************************************************************************/
static void DrawCate631CategoryControlArea1(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(coordinate);    
    gdi_image_draw_id(0, 0, IMG_ID_ANIMATED_DIAL_BG);
} 


/*****************************************************************************
 * FUNCTION
 *  wgui_anim_dial_register_not_empty_function
 * DESCRIPTION
 *  Register not empty callback function
 * PARAMETERS
 *  f      [IN]      not empty callback function
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_anim_dial_register_not_empty_function(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_anim_dial_not_empty_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_anim_dial_register_empty_function
 * DESCRIPTION
 *  Register empty callback function
 * PARAMETERS
 *  f      [IN]      empty callback function
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_anim_dial_register_empty_function(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_anim_dial_empty_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_anim_dial_register_RSK_function
 * DESCRIPTION
 *  Register empty callback function
 * PARAMETERS
 *  f      [IN]      empty callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_anim_dial_register_RSK_function(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_anim_dial_cntx_p != NULL)
    {
        g_anim_dial_cntx_p->anim_dial_RSK_key_up_func = f;
    }
}

/*****************************************************************************
 * FUNCTION
 *  wgui_anim_dial_get_keycode_img_id
 * DESCRIPTION
 *  Get the img id of key_code to be shown on screen when key down
 * PARAMETERS
 *  key_code        [IN]        
 *  img_id          [OUT]   return the img_id of key_code
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_anim_dial_get_cursor_img_id(S32 *img_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_animated_dial_cntx_struct *ad_cntx = g_anim_dial_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ad_cntx->img_size_level == 0)
    {
        *img_id = IMG_ID_ANIMATED_DIAL_CURSOR;
    }
    else if (ad_cntx->img_size_level == 1)
    {
        *img_id = IMG_ID_ANIMATED_DIAL_CURSOR_S;
    }
}
/*****************************************************************************
 * FUNCTION
 *  wgui_anim_dial_get_keycode_img_id
 * DESCRIPTION
 *  Get the img id of key_code to be shown on screen when key down
 * PARAMETERS
 *  key_code        [IN]        
 *  img_id          [OUT]   return the img_id of key_code
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_anim_dial_get_keycode_img_id(MMI_key_code_type key_code, S32 *img_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_animated_dial_cntx_struct *ad_cntx = g_anim_dial_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ad_cntx->img_size_level == 0)
    {
        if (key_code >= '0' && key_code <= '9')
        {
            *img_id = IMG_ID_ANIMATED_DIAL_0 + (key_code - '0');
        }
        else
        {
            switch(key_code)
            {       
                case '*':
                    *img_id = IMG_ID_ANIMATED_DIAL_STAR;
                    break;
                    
                case '+':
                    *img_id = IMG_ID_ANIMATED_DIAL_PLUS;
                    break;
                    
                case 'p':
                    *img_id = IMG_ID_ANIMATED_DIAL_P;
                    break;
                    
                case 'w':
                    *img_id = IMG_ID_ANIMATED_DIAL_W;
                    break;
                    
                case '#':
                    *img_id = IMG_ID_ANIMATED_DIAL_POUND;
                    break;

                case '?':
                    *img_id = IMG_ID_ANIMATED_DIAL_QUEST;
                    break;
                                        
                default:
                    ASSERT(0);
                    break;
            }
        }
    }
    else if (ad_cntx->img_size_level == 1)
    {
        if (key_code >= '0' && key_code <= '9')
        {
            *img_id = IMG_ID_ANIMATED_DIAL_S_0 + (key_code - '0');
        }
        else
        {
            switch(key_code)
            {    
                case '*':
                    *img_id = IMG_ID_ANIMATED_DIAL_S_STAR;
                    break;
                    
                case '+':
                    *img_id = IMG_ID_ANIMATED_DIAL_S_PLUS;
                    break;
                    
                case 'p':
                    *img_id = IMG_ID_ANIMATED_DIAL_S_P;
                    break;
                    
                case 'w':
                    *img_id = IMG_ID_ANIMATED_DIAL_S_W;
                    break;
                    
                case '#':
                    *img_id = IMG_ID_ANIMATED_DIAL_S_POUND;
                    break;
                    
                case '?':
                    *img_id = IMG_ID_ANIMATED_DIAL_S_QUEST;
                    break;
                    
                default:
                    ASSERT(0);
                    break;
            }   
        }
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_anim_dial_get_keycode_dspr_img_id
 * DESCRIPTION
 *  Get the disappear animation img id of key_code to be shown on screen when key down
 * PARAMETERS
 *  key_code        [IN]        
 *  img_id          [OUT]   return the img_id of key_code
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_anim_dial_get_keycode_dspr_img_id(MMI_key_code_type key_code, S32 *img_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_animated_dial_cntx_struct *ad_cntx = g_anim_dial_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ad_cntx->img_size_level == 0)
    {
        if (key_code >= '0' && key_code <= '9')
        {
            *img_id = IMG_ID_ANIM_DIAL_DSPR_0 + (key_code - '0');
        }
        else
        {
            switch(key_code)
            {     
                case '*':
                    *img_id = IMG_ID_ANIM_DIAL_DSPR_STAR;
                    break;
                    
                case '+':
                    *img_id = IMG_ID_ANIM_DIAL_DSPR_PLUS;
                    break;
                    
                case 'p':
                    *img_id = IMG_ID_ANIM_DIAL_DSPR_P;
                    break;
                    
                case 'w':
                    *img_id = IMG_ID_ANIM_DIAL_DSPR_W;
                    break;
                    
                case '#':
                    *img_id = IMG_ID_ANIM_DIAL_DSPR_POUND;
                    break;
                    
                case '?':
                    *img_id = IMG_ID_ANIM_DIAL_DSPR_QUEST;
                    break;
                    
                default:
                    ASSERT(0);
                    break;
            }
        }
    }
    else if (ad_cntx->img_size_level == 1)
    {
        if (key_code >= '0' && key_code <= '9')
        {
            *img_id = IMG_ID_ANIM_DIAL_DSPR_S_0 + (key_code - '0');
        }
        else
        {
            switch(key_code)
            {
                case '*':
                    *img_id = IMG_ID_ANIM_DIAL_DSPR_S_STAR;
                    break;
                    
                case '+':
                    *img_id = IMG_ID_ANIM_DIAL_DSPR_S_PLUS;
                    break;
                    
                case 'p':
                    *img_id = IMG_ID_ANIM_DIAL_DSPR_S_P;
                    break;
                    
                case 'w':
                    *img_id = IMG_ID_ANIM_DIAL_DSPR_S_W;
                    break;
                    
                case '#':
                    *img_id = IMG_ID_ANIM_DIAL_DSPR_S_POUND;
                    break;
                    
                case '?':
                    *img_id = IMG_ID_ANIM_DIAL_DSPR_S_QUEST;
                    break;
                    
                default:
                    ASSERT(0);
                    break;
            }   
        }
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_anim_dail_animation_lastframe_callback
 * DESCRIPTION
 *  the callback function triggered when the animation plays to the last frame
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_anim_dail_animation_lastframe_callback(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_animated_dial_cntx_struct *ad_cntx = g_anim_dial_cntx_p;
    GDI_HANDLE layer_0, layer_1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* flatten the number img on layer_1 to layer_0, let cursor img can show it on backround*/
    layer_0 = dm_get_layer_handle(0);
    layer_1 = dm_get_layer_handle(1);
    gdi_layer_push_and_set_active(layer_0);
    gdi_layer_set_clip(WGUI_ANIM_DIAL_REDRAW_X1, WGUI_ANIM_DIAL_REDRAW_Y1, WGUI_ANIM_DIAL_REDRAW_X2, WGUI_ANIM_DIAL_REDRAW_Y2);
    gdi_layer_flatten_with_clipping(layer_0,layer_1,0,0);
    gdi_layer_pop_and_restore_active();

    ad_cntx->anim_handle = GDI_NULL_HANDLE;
    if (ad_cntx->curr_cursor_pos >= ad_cntx->text_length)
    {
        ad_cntx->anim_keycode = ad_cntx->dial_buffer[ad_cntx->curr_cursor_pos - ad_cntx->text_length];
    }
    else
    {
        ad_cntx->anim_keycode = -1;
    }
    ad_cntx->draw_animation = WGUI_ANIM_DIAL_ANIM_NONE;
    wgui_anim_dial_redraw();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_anim_dial_play_fly_in_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_anim_dial_play_fly_in_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE layer_0, layer_1;
    S32 tmp_img_id, tmp_play_frame, oldpos_x, oldpos_y;
    wgui_animated_dial_cntx_struct *ad_cntx = g_anim_dial_cntx_p;
    S32 cx1, cy1, cx2, cy2;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    layer_0 = dm_get_layer_handle(0);
    layer_1 = dm_get_layer_handle(1);
    wgui_anim_dial_get_keycode_img_id(ad_cntx->anim_keycode, &tmp_img_id);

    tmp_play_frame = ad_cntx->fly_in_frame;
    if (ad_cntx->draw_animation == WGUI_ANIM_DIAL_ANIM_CLEAR && ad_cntx->fly_in_frame >= 0)
    {
        tmp_play_frame = ad_cntx->anim_max_frame[ad_cntx->img_size_level] - ad_cntx->fly_in_frame;
    }
    
    gdi_layer_lock_frame_buffer();
    gdi_layer_push_and_set_active(layer_1);
	gdi_set_alpha_blending_source_layer(layer_0);
    gdi_layer_reset_clip();
    
    /* save the original fly in position */
    oldpos_x = ad_cntx->fly_in_x;
    oldpos_y = ad_cntx->fly_in_y;    

    if (ad_cntx->fly_in_frame < 0) /* first frame */
    {
        gdi_image_stop_animation(ad_cntx->cursor_handle);

        cx1 = WGUI_ANIM_DIAL_REDRAW_X1;
        cy1 = WGUI_ANIM_DIAL_REDRAW_Y1;
        cx2 = WGUI_ANIM_DIAL_REDRAW_X2;
        cy2 = WGUI_ANIM_DIAL_REDRAW_Y2;
        gdi_layer_set_clip(cx1, cy1, cx2, cy2);
        /* clear background */
        gdi_draw_solid_rect(
            WGUI_ANIM_DIAL_REDRAW_X1, 
            WGUI_ANIM_DIAL_REDRAW_Y1, 
            WGUI_ANIM_DIAL_REDRAW_X2, 
            WGUI_ANIM_DIAL_REDRAW_Y2,
            GDI_COLOR_TRANSPARENT);

        /* init */
        ad_cntx->fly_in_frame = 0;
        ad_cntx->fly_in_timeslice = WGUI_ANIM_DIAL_FLY_IN_ANIM_TIME;
        ad_cntx->fly_in_dx = (ad_cntx->fly_in_x - ad_cntx->fly_in_final_x)/
                                   (ad_cntx->anim_max_frame[ad_cntx->img_size_level] + 1);
        ad_cntx->fly_in_dy = (ad_cntx->fly_in_y - ad_cntx->fly_in_final_y)/
                                   (ad_cntx->anim_max_frame[ad_cntx->img_size_level] + 1);
        gdi_image_draw_animation_single_frame_id(
                    ad_cntx->fly_in_x, 
                    ad_cntx->fly_in_y, 
                    (U16)tmp_img_id, 
                    (U16)tmp_play_frame);   
    }
    else if (ad_cntx->fly_in_frame == 
                ad_cntx->anim_max_frame[ad_cntx->img_size_level]) /* last frame */
    {   
        /* set position to the fianal position when playing last frame */
        ad_cntx->fly_in_x = ad_cntx->fly_in_final_x;
        ad_cntx->fly_in_y = ad_cntx->fly_in_final_y;

        cx1 = min(oldpos_x, ad_cntx->fly_in_x);
        cy1 = min(oldpos_y, ad_cntx->fly_in_y);
        cx2 = max(oldpos_x, ad_cntx->fly_in_x) + ad_cntx->img_w[ad_cntx->img_size_level];
        cy2 = max(oldpos_y, ad_cntx->fly_in_y) + ad_cntx->img_h[ad_cntx->img_size_level];
        gdi_layer_set_clip(cx1, cy1, cx2, cy2);
        /* clear background */
        gdi_draw_solid_rect(
            WGUI_ANIM_DIAL_REDRAW_X1, 
            WGUI_ANIM_DIAL_REDRAW_Y1, 
            WGUI_ANIM_DIAL_REDRAW_X2, 
            WGUI_ANIM_DIAL_REDRAW_Y2,
            GDI_COLOR_TRANSPARENT);
        gdi_draw_rect(
            cx1-1, 
            cy1-1, 
            cx2+1, 
            cy2+1, 
            GDI_COLOR_RED);
        
        gdi_image_draw_animation_single_frame_id(
                    ad_cntx->fly_in_x, 
                    ad_cntx->fly_in_y, 
                    (U16)tmp_img_id, 
                    (U16)tmp_play_frame);   
        ad_cntx->fly_in_frame = -1;
        
        /* flatten the number img on layer_1 to layer_0, let cursor img can show it on backround*/
        layer_0 = dm_get_layer_handle(0);
        layer_1 = dm_get_layer_handle(1);
        gdi_layer_push_and_set_active(layer_0);
        gdi_layer_set_clip(WGUI_ANIM_DIAL_REDRAW_X1, WGUI_ANIM_DIAL_REDRAW_Y1, WGUI_ANIM_DIAL_REDRAW_X2, WGUI_ANIM_DIAL_REDRAW_Y2);
        gdi_layer_flatten_with_clipping(layer_0,layer_1,0,0);
        gdi_layer_pop_and_restore_active();
        /* draw cursor */
        gdi_layer_set_clip(WGUI_ANIM_DIAL_REDRAW_X1, WGUI_ANIM_DIAL_REDRAW_Y1, WGUI_ANIM_DIAL_REDRAW_X2, WGUI_ANIM_DIAL_REDRAW_Y2);
        if (ad_cntx->final_text_pos > 0)
        {
            S32 tmp_cursor_img_id;
            wgui_anim_dial_get_cursor_img_id(&tmp_cursor_img_id);
            gdi_image_draw_animation_id(
                ad_cntx->cursor_x,
                ad_cntx->cursor_y, 
                (U16)tmp_cursor_img_id, 
                &ad_cntx->cursor_handle);
        }
        gui_cancel_timer(wgui_anim_dial_play_fly_in_animation);
    }
    else
    {
        /* calculate the next position */
        ad_cntx->fly_in_x -= ad_cntx->fly_in_dx;
        ad_cntx->fly_in_y -= ad_cntx->fly_in_dy;

        cx1 = min(oldpos_x, ad_cntx->fly_in_x);
        cy1 = min(oldpos_y, ad_cntx->fly_in_y); 
        cx2 = max(oldpos_x, ad_cntx->fly_in_x) + ad_cntx->img_w[ad_cntx->img_size_level];
        cy2 = max(oldpos_y, ad_cntx->fly_in_y) + ad_cntx->img_h[ad_cntx->img_size_level];
        gdi_layer_set_clip(cx1, cy1, cx2, cy2);
        /* clear background */
        gdi_draw_solid_rect(
            WGUI_ANIM_DIAL_REDRAW_X1, 
            WGUI_ANIM_DIAL_REDRAW_Y1, 
            WGUI_ANIM_DIAL_REDRAW_X2, 
            WGUI_ANIM_DIAL_REDRAW_Y2,
            GDI_COLOR_TRANSPARENT);

        gdi_image_draw_animation_single_frame_id(
                    ad_cntx->fly_in_x, 
                    ad_cntx->fly_in_y, 
                    (U16)tmp_img_id, 
                    (U16)tmp_play_frame);   
        ad_cntx->fly_in_frame++;
        ad_cntx->fly_in_timeslice += 20;  //the "fly in object" will run slowlyer and slowlyer
    }

    gdi_layer_pop_and_restore_active();

	gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(cx1, cy1, cx2, cy2);
    if ((ad_cntx->fly_in_frame >= 0) && 
        (ad_cntx->fly_in_frame <= ad_cntx->anim_max_frame[ad_cntx->img_size_level]))
    {
        gui_start_timer(ad_cntx->fly_in_timeslice, wgui_anim_dial_play_fly_in_animation);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_anim_dial_redraw
 * DESCRIPTION
 *  redraw animated dial screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_anim_dial_redraw(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE layer_0, layer_1;
    S32 i;
	S32 curr_pos_x, curr_pos_y;             /* the current position to draw img */
    S32 tmp_img_id, tmp_img_size_level;     /* the img_id to be draw, and the current img size level */
    S32 cursor_img_id;
    S32 animation_play_x = 0, animation_play_y = 0;
    S32 *cursor_x, *cursor_y;
    S32 the_final_i;
    wgui_animated_dial_cntx_struct *ad_cntx = g_anim_dial_cntx_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    layer_0 = dm_get_layer_handle(0);
    layer_1 = dm_get_layer_handle(1);

    gdi_layer_lock_frame_buffer();
    
    curr_pos_x = ad_cntx->x;   /* set current pos to the left up corner */
    curr_pos_y = ad_cntx->y;
    cursor_x = &ad_cntx->cursor_x;
    cursor_y = &ad_cntx->cursor_y;
    *cursor_x = -1;
    *cursor_y = -1;

    /* stop animation if there is still one animation is playing*/
    if (ad_cntx->anim_handle != 0)
    {
        gdi_image_stop_animation(ad_cntx->anim_handle);
        ad_cntx->anim_handle = GDI_NULL_HANDLE;
    }
    gui_cancel_timer(wgui_anim_dial_play_fly_in_animation);

    tmp_img_size_level = ad_cntx->img_size_level;
    
    /* draw layer 0*/
    gdi_layer_push_and_set_active(layer_0);
    gdi_set_alpha_blending_source_layer(layer_0);
    gdi_layer_push_clip();
    gdi_layer_set_clip(WGUI_ANIM_DIAL_REDRAW_X1, WGUI_ANIM_DIAL_REDRAW_Y1, WGUI_ANIM_DIAL_REDRAW_X2, WGUI_ANIM_DIAL_REDRAW_Y2);
    
    gdi_image_draw_id(0, 0, IMG_ID_ANIMATED_DIAL_BG);  /* redraw the background img */
   
    the_final_i = min(ad_cntx->final_text_pos, ad_cntx->start_draw_pos + ad_cntx->word_num[ad_cntx->img_size_level] * ad_cntx->text_length);
    if (ad_cntx->draw_animation == WGUI_ANIM_DIAL_ANIM_CLEAR && 
        (ad_cntx->final_text_pos > ad_cntx->start_draw_pos + (ad_cntx->word_num[ad_cntx->img_size_level] - 1) * ad_cntx->text_length))
    {
        the_final_i -= ad_cntx->text_length;
    }
    /* redraw the dial numbers in the buffer except the last one */
    for (i = ad_cntx->start_draw_pos; 
         i <= the_final_i;
         i += ad_cntx->text_length)
    {
        if (i == ad_cntx->curr_cursor_pos && ad_cntx->draw_animation == WGUI_ANIM_DIAL_ANIM_CLEAR)
        {   
            // save the position of animation 
            animation_play_x = curr_pos_x;
            animation_play_y = curr_pos_y;
            // save the space for animation 
            curr_pos_x += (S32) (ad_cntx->text_gap[tmp_img_size_level] + 
                                 ad_cntx->img_w[tmp_img_size_level]);
            if ((curr_pos_x + ad_cntx->img_w[tmp_img_size_level] + ad_cntx->text_gap[tmp_img_size_level]) > 
                (ad_cntx->width + ad_cntx->x))
            {
                curr_pos_x = ad_cntx->x;
                curr_pos_y += (S32)(ad_cntx->img_h[tmp_img_size_level] + ad_cntx->line_gap[tmp_img_size_level]);
            }
        }
        if (i == the_final_i)
        {
            break;
        }
        if (i == (ad_cntx->curr_cursor_pos - ad_cntx->text_length))
        {   
            if (ad_cntx->draw_animation == WGUI_ANIM_DIAL_ANIM_CLEAR)
            {
                wgui_anim_dial_get_keycode_img_id(ad_cntx->dial_buffer[i], &tmp_img_id);
                gdi_image_draw_animation_single_frame_id(
                    curr_pos_x, 
                    curr_pos_y, 
                    (U16) tmp_img_id, 
                    (U16)ad_cntx->anim_max_frame[tmp_img_size_level]);
            }
            /* save the position of animation */
            animation_play_x = curr_pos_x;
            animation_play_y = curr_pos_y;
        }
        else
        {
            wgui_anim_dial_get_keycode_img_id(ad_cntx->dial_buffer[i], &tmp_img_id);
            gdi_image_draw_animation_single_frame_id(
                curr_pos_x, 
                curr_pos_y, 
                (U16)tmp_img_id, 
                (U16)ad_cntx->anim_max_frame[tmp_img_size_level]);
        }

        /* save the position of cursor */
        if (i == (ad_cntx->curr_cursor_pos - ad_cntx->text_length))
        {
            *cursor_x = curr_pos_x;
            *cursor_y = curr_pos_y;
        }
        
        /* calculate the next draw position */
        curr_pos_x += (S32) (ad_cntx->text_gap[tmp_img_size_level] + 
                             ad_cntx->img_w[tmp_img_size_level]);
        if ((curr_pos_x + ad_cntx->img_w[tmp_img_size_level]) > 
            (ad_cntx->width + ad_cntx->x))
        {
            curr_pos_x = ad_cntx->x;
            curr_pos_y += (S32)(ad_cntx->img_h[tmp_img_size_level] + ad_cntx->line_gap[tmp_img_size_level]);
        }
    }

    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();

    /* draw layer 1*/    
    gdi_layer_push_and_set_active(layer_1);
	gdi_layer_push_clip();
    gdi_layer_set_clip(WGUI_ANIM_DIAL_REDRAW_X1, WGUI_ANIM_DIAL_REDRAW_Y1, WGUI_ANIM_DIAL_REDRAW_X2, WGUI_ANIM_DIAL_REDRAW_Y2);

    gdi_draw_solid_rect(
        WGUI_ANIM_DIAL_REDRAW_X1, 
        WGUI_ANIM_DIAL_REDRAW_Y1, 
        WGUI_ANIM_DIAL_REDRAW_X2, 
        WGUI_ANIM_DIAL_REDRAW_Y2,
        GDI_COLOR_TRANSPARENT);
    gdi_set_alpha_blending_source_layer(layer_0);

    /* decide the cursor position */
    if (ad_cntx->cursor_handle != 0)
    {
        gdi_image_stop_animation(ad_cntx->cursor_handle);
        ad_cntx->cursor_handle = GDI_NULL_HANDLE;
    }
    if (ad_cntx->curr_cursor_pos == 0 && ad_cntx->draw_animation != WGUI_ANIM_DIAL_ANIM_CLEAR)
    {
        ad_cntx->draw_animation = WGUI_ANIM_DIAL_ANIM_NONE;
        *cursor_x = ad_cntx->x - ad_cntx->img_w[tmp_img_size_level];
        *cursor_y = ad_cntx->y;
    }
    
    /* draw the dial number in front of cursor*/
    if (ad_cntx->anim_keycode >= 0)
    {
        if (ad_cntx->draw_animation == WGUI_ANIM_DIAL_ANIM_NONE)
        {
            /* draw the last frame of animation when press backspace or move cursor */
            wgui_anim_dial_get_keycode_img_id(ad_cntx->anim_keycode, &tmp_img_id);
            gdi_image_draw_animation_single_frame_id(
                animation_play_x, 
                animation_play_y, 
                (U16)tmp_img_id, 
                (U16)ad_cntx->anim_max_frame[tmp_img_size_level]);
            ad_cntx->anim_keycode = -1;

            /* flatten the number img on layer_1 to layer_0, let cursor img can show it on backround*/
            gdi_layer_push_and_set_active(layer_0);
            gdi_layer_set_clip(WGUI_ANIM_DIAL_REDRAW_X1, WGUI_ANIM_DIAL_REDRAW_Y1, WGUI_ANIM_DIAL_REDRAW_X2, WGUI_ANIM_DIAL_REDRAW_Y2);
            gdi_layer_flatten_with_clipping(layer_0,layer_1,0,0);
            gdi_layer_pop_and_restore_active();
        }
        else if(ad_cntx->draw_animation == WGUI_ANIM_DIAL_ANIM_MOVE_CURSOR)
        {
            /* draw animation when keyin dial number */
            wgui_anim_dial_get_keycode_img_id(ad_cntx->anim_keycode, &tmp_img_id);
            gdi_image_set_animation_last_frame_callback(wgui_anim_dail_animation_lastframe_callback);
            gdi_image_draw_animation_once(
                animation_play_x, 
                animation_play_y,
                (U8*)GetImage((U16)tmp_img_id), 
                &ad_cntx->anim_handle);
        }
        else if(ad_cntx->draw_animation == WGUI_ANIM_DIAL_ANIM_KEY_IN)
        {
        #if defined(__MMI_ANIM_DIAL_KEYIN_ANIMATION_FLYIN_SYTLE__)
            ad_cntx->fly_in_x = WGUI_ANIM_DIAL_REDRAW_X2 - ad_cntx->img_w[tmp_img_size_level];
            ad_cntx->fly_in_y = WGUI_ANIM_DIAL_REDRAW_Y2 - ad_cntx->img_h[tmp_img_size_level];
            ad_cntx->fly_in_final_x = animation_play_x;
            ad_cntx->fly_in_final_y = animation_play_y;
            ad_cntx->fly_in_frame = -1;
            wgui_anim_dial_play_fly_in_animation();
        #elif defined(__MMI_ANIM_DIAL_KEYIN_ANIMATION_ANIM_SYTLE__)
            /* draw animation when keyin dial number */
            wgui_anim_dial_get_keycode_img_id(ad_cntx->anim_keycode, &tmp_img_id);
            gdi_image_set_animation_last_frame_callback(wgui_anim_dail_animation_lastframe_callback);
            gdi_image_draw_animation_once(
                animation_play_x, 
                animation_play_y,
                (U8*)GetImage((U16)tmp_img_id), 
                &ad_cntx->anim_handle);
        #else
            /* draw the last frame of animation when press backspace or move cursor */
            gdi_image_draw_animation_single_frame_id(
                animation_play_x, 
                animation_play_y, 
                (U16)tmp_img_id, 
                (U16)ad_cntx->anim_max_frame[tmp_img_size_level]);*/
            /* draw animation when keyin dial number */
            wgui_anim_dial_get_keycode_img_id(ad_cntx->anim_keycode, &tmp_img_id);
            gdi_image_set_animation_last_frame_callback(wgui_anim_dail_animation_lastframe_callback);
            gdi_image_draw_animation_once(
                animation_play_x, 
                animation_play_y,
                (U8*)GetImage((U16)tmp_img_id), 
                &ad_cntx->anim_handle);
        #endif
        }
        else if(ad_cntx->draw_animation == WGUI_ANIM_DIAL_ANIM_CLEAR)
        {
            wgui_anim_dial_get_keycode_dspr_img_id(ad_cntx->anim_keycode, &tmp_img_id);
            gdi_anim_set_last_frame_callback(wgui_anim_dail_animation_lastframe_callback);
            gdi_image_draw_animation_once(
                animation_play_x, 
                animation_play_y,
                (U8*)GetImage((U16)tmp_img_id), 
                &ad_cntx->anim_handle);
            
        }
        /* calculate the next draw position and decide to change img_size_level or start_draw_pos */
        curr_pos_x += (S32)(ad_cntx->text_gap[tmp_img_size_level] + 
                            ad_cntx->img_w[tmp_img_size_level]);
        if ((curr_pos_x + ad_cntx->img_w[tmp_img_size_level] + ad_cntx->text_gap[tmp_img_size_level]) >= 
            (ad_cntx->width + ad_cntx->x))
        {
            curr_pos_x = ad_cntx->x;
            curr_pos_y += 
                (S32)(ad_cntx->img_h[tmp_img_size_level] + 
                ad_cntx->line_gap[tmp_img_size_level]);
        }
    }
    /* not draw cursor if it's playing other animation */
    if (ad_cntx->draw_animation == WGUI_ANIM_DIAL_ANIM_NONE)
    {
        
        wgui_anim_dial_get_cursor_img_id(&cursor_img_id);
        gdi_image_draw_animation_id(*cursor_x, *cursor_y, (U16)cursor_img_id, &ad_cntx->cursor_handle);
    }
    
	gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();

	gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(WGUI_ANIM_DIAL_REDRAW_X1, WGUI_ANIM_DIAL_REDRAW_Y1, WGUI_ANIM_DIAL_REDRAW_X2, WGUI_ANIM_DIAL_REDRAW_Y2);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_anim_dial_insert_char_to_buffer
 * DESCRIPTION
 *  insert one char to buffer, depend on position
 * PARAMETERS
 *  character        [IN]        the char to be insert
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_anim_dial_insert_char_to_buffer(U8 character)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 old_char, insert_char;
    S32 tmp_pos;
    UI_buffer_type bufferp;
    wgui_animated_dial_cntx_struct *ad_cntx = g_anim_dial_cntx_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* if buffer full, return*/
    if (ad_cntx->final_text_pos >= ad_cntx->dial_buffer_length)
    {
        return;
    }
    bufferp = ad_cntx->dial_buffer;
    tmp_pos = ad_cntx->curr_cursor_pos;
    insert_char = character;
    
    while (tmp_pos <= ad_cntx->final_text_pos + ad_cntx->text_length)
    {
        old_char = bufferp[tmp_pos];
        bufferp[tmp_pos] = insert_char;
        insert_char = old_char;

        tmp_pos += ad_cntx->text_length;
    }
    ad_cntx->curr_cursor_pos += ad_cntx->text_length;
    ad_cntx->final_text_pos += ad_cntx->text_length;
    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_anim_dial_clear_one_char
 * DESCRIPTION
 *  clear the char in cursor position from the buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL 
 *****************************************************************************/
static MMI_BOOL wgui_anim_dial_clear_one_char(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 insert_char;
    S32 tmp_pos;
    UI_buffer_type bufferp;
    wgui_animated_dial_cntx_struct *ad_cntx = g_anim_dial_cntx_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ad_cntx->curr_cursor_pos <= 0)
    {   
        /* play error tone if no character to clear */
        StopCurrentKeyPadTone();
        srv_prof_play_tone(ERROR_TONE, NULL);
        return MMI_FALSE;
    }
    bufferp = ad_cntx->dial_buffer;
    tmp_pos = ad_cntx->curr_cursor_pos - ad_cntx->text_length;
    
    while (tmp_pos <= ad_cntx->final_text_pos)    /* move all chars after cursor to its previous position */
    {
        insert_char = bufferp[tmp_pos + ad_cntx->text_length];
        bufferp[tmp_pos] = insert_char;

        tmp_pos += ad_cntx->text_length;
    }

    ad_cntx->dial_buffer[ad_cntx->final_text_pos] = 0; /* clear the last position of buffer */
    ad_cntx->final_text_pos -= ad_cntx->text_length;
    if (ad_cntx->final_text_pos < 0)
    {
        ad_cntx->final_text_pos = 0;
    }
    ad_cntx->curr_cursor_pos -= ad_cntx->text_length;
    if (ad_cntx->curr_cursor_pos < 0)
    {
        ad_cntx->curr_cursor_pos = 0;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_anim_dial_backspace
 * DESCRIPTION
 *  handle backspace event in animated dial
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_anim_dial_backspace(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_animated_dial_cntx_struct *ad_cntx = g_anim_dial_cntx_p;
    MMI_BOOL success_clear;
    MMI_BOOL decrease_img_size = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* save the cleared keycode to show in animation */
    if (ad_cntx->curr_cursor_pos >= ad_cntx->text_length)
    {
        ad_cntx->anim_keycode = ad_cntx->dial_buffer[ad_cntx->curr_cursor_pos - ad_cntx->text_length];
    }
    else
    {
        ad_cntx->anim_keycode = -1;
    }
    
    success_clear = wgui_anim_dial_clear_one_char();    

    /* decrease the img_size_level when the dial number is less than some number */
    if (ad_cntx->img_size_level > 0 &&
        ((ad_cntx->final_text_pos / ad_cntx->text_length) <= 
         ad_cntx->word_num[ad_cntx->img_size_level - 1]))
    {
        ad_cntx->img_size_level--;
        decrease_img_size = MMI_TRUE;
    }
	if (ad_cntx->start_draw_pos>0)
	{
	    if (ad_cntx->start_draw_pos + 
            (ad_cntx->word_num[ad_cntx->img_size_level] - 1)* ad_cntx->text_length 
            - ad_cntx->curr_cursor_pos <= 0)
        {
            ad_cntx->start_draw_pos = ad_cntx->curr_cursor_pos - (ad_cntx->word_num[ad_cntx->img_size_level]-1) * ad_cntx->text_length; 
        }
        else   
        {
            ad_cntx->start_draw_pos -= ad_cntx->text_length; 
        }
	   
	}
    /* redraw */
    if (success_clear)
    {
    #if defined(__MMI_ANIM_DIAL_CLEAR_ANIMATION__)
        if (decrease_img_size)
        {
            /* the moment that image size become smaller, don't play the clear animation */
            ad_cntx->draw_animation = WGUI_ANIM_DIAL_ANIM_NONE;
        }
        else
        {
            ad_cntx->draw_animation = WGUI_ANIM_DIAL_ANIM_CLEAR;
        }
    #else
        ad_cntx->draw_animation = WGUI_ANIM_DIAL_ANIM_NONE;
    #endif
        wgui_anim_dial_redraw();
        wgui_anim_dial_change_clear_key_up_func();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_anim_dial_delete_all
 * DESCRIPTION
 *  handle long press event of backspace
 *  delete all characters in the buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_anim_dial_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    wgui_animated_dial_cntx_struct *ad_cntx = g_anim_dial_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i=ad_cntx->dial_buffer_length; i>=0; i--)   /* clear the buffer */
    {
        ad_cntx->dial_buffer[i] = 0;
    }
    ad_cntx->final_text_pos = 0;
    ad_cntx->curr_cursor_pos = 0;
    ad_cntx->img_size_level = 0;
    ad_cntx->start_draw_pos = 0;

    ad_cntx->anim_keycode = -1;
    ad_cntx->draw_animation = WGUI_ANIM_DIAL_ANIM_NONE;
    wgui_anim_dial_redraw();
    wgui_anim_dial_change_clear_key_up_func();
    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_anim_dial_complete_multitap
 * DESCRIPTION
 *  expire when multitap is time out
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_anim_dial_complete_multitap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_animated_dial_cntx_struct *ad_cntx = g_anim_dial_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    #ifdef __MMI_MULTITAP_KEY_0__
    /* During MT/MO call, application will register their key handlers.
       Store the key handlers when get into multitap state,
       and restore them when multitap complete. */
    SetKeyHandler(ad_cntx->zero_key_func[KEY_0][KEY_EVENT_DOWN], KEY_0, KEY_EVENT_DOWN);
    SetKeyHandler(ad_cntx->zero_key_func[KEY_0][KEY_EVENT_UP], KEY_0, KEY_EVENT_UP);
    SetKeyHandler(ad_cntx->zero_key_func[KEY_0][KEY_LONG_PRESS], KEY_0, KEY_LONG_PRESS);
    SetKeyHandler(UI_dummy_function, KEY_0, KEY_REPEAT);
    #endif

    ad_cntx->multitap_index = -1;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_anim_dial_multitap_key_down
 * DESCRIPTION
 *  handle key down event when a multitap key key down
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_anim_dial_multitap_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 tmp_cursor_pos;
    MMI_BOOL ifdrawanim;
    U16 keyCode, keyType;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_animated_dial_cntx_struct *ad_cntx = g_anim_dial_cntx_p;

    GetkeyInfo(&keyCode, &keyType);

    gui_cancel_timer(wgui_anim_dial_complete_multitap);
    gui_start_timer(WGUI_ANIM_DIAL_MULTITAP_TIMEOUT, wgui_anim_dial_complete_multitap);
    
    #ifdef __MMI_MULTITAP_KEY_0__
    /* During MT/MO call, application will register their key handlers.
       Store the key handlers when get into multitap state,
       and restore them when multitap complete. */
    if (keyType == KEY_EVENT_LONG_PRESS)
    {
        ad_cntx->zero_key_func[KEY_0][KEY_EVENT_DOWN] = mmi_frm_get_key_handler(KEY_0, KEY_EVENT_DOWN);
        ad_cntx->zero_key_func[KEY_0][KEY_EVENT_UP] = mmi_frm_get_key_handler(KEY_0, KEY_EVENT_UP);
        ad_cntx->zero_key_func[KEY_0][KEY_LONG_PRESS] = mmi_frm_get_key_handler(KEY_0, KEY_LONG_PRESS);
    }
        
    SetKeyHandler(wgui_anim_dial_multitap_key_down, KEY_0, KEY_EVENT_REPEAT);     //zero key 
    SetKeyHandler(wgui_anim_dial_multitap_key_down, KEY_0, KEY_EVENT_DOWN);
    #endif
    /* add keycode to dial_buffer*/
    if (ad_cntx->multitap_index <= -1 && keyType == KEY_EVENT_DOWN)
    {
        ifdrawanim = MMI_TRUE;
        /* the first time press star key */
        ad_cntx->multitap_index = 0;
        /* if buffer full, then clear the first char in the buffer*/
        if (ad_cntx->final_text_pos >= ad_cntx->dial_buffer_length)
        {
            /* clear the first char in the buffer */
            tmp_cursor_pos = ad_cntx->curr_cursor_pos;
            ad_cntx->curr_cursor_pos = ad_cntx->text_length;
            wgui_anim_dial_clear_one_char();
            ad_cntx->curr_cursor_pos = tmp_cursor_pos - ad_cntx->text_length;
        }
        wgui_anim_dial_insert_char_to_buffer(
            (U8)ad_cntx->multitap_char[ad_cntx->multitap_index]);
        /* increase the img_size_level when the dial number is more than some number */
        if ((ad_cntx->final_text_pos / ad_cntx->text_length) > ad_cntx->word_num[ad_cntx->img_size_level])
        {
            if (ad_cntx->img_size_level < ad_cntx->max_img_size_level)
            {
                ad_cntx->img_size_level++;
            }
            else
            {
                ad_cntx->start_draw_pos += ad_cntx->text_length; 
            }
        }
    }
    else
    {
        ifdrawanim = MMI_FALSE;
        if (ad_cntx->anim_handle != 0)  /* if the animation is still playing, then return*/
        {
            gdi_image_stop_animation(ad_cntx->anim_handle);
            ad_cntx->anim_handle = GDI_NULL_HANDLE;
        }
        /* not the first time press star key */
        ad_cntx->multitap_index++;
		if (ad_cntx->multitap_char[ad_cntx->multitap_index] == '\0')
        {
            ad_cntx->multitap_index = 0;
        }
        /* change the character */
        ad_cntx->dial_buffer[ad_cntx->curr_cursor_pos - ad_cntx->text_length] = 
            ad_cntx->multitap_char[ad_cntx->multitap_index];
    }

    ad_cntx->anim_keycode = ad_cntx->dial_buffer[ad_cntx->curr_cursor_pos - ad_cntx->text_length];
    if (ifdrawanim)
    {
        if (ad_cntx->curr_cursor_pos >= ad_cntx->text_length)
        {
            ad_cntx->anim_keycode = ad_cntx->dial_buffer[ad_cntx->curr_cursor_pos - ad_cntx->text_length];
        }
        else
        {
            ad_cntx->anim_keycode = -1;
        }
    #if defined(__MMI_ANIM_DIAL_KEYIN_ANIMATION__)
        ad_cntx->draw_animation = WGUI_ANIM_DIAL_ANIM_KEY_IN;
    #else
        ad_cntx->draw_animation = WGUI_ANIM_DIAL_ANIM_NONE;
    #endif
    }
    else
    {
        ad_cntx->draw_animation = WGUI_ANIM_DIAL_ANIM_NONE;
    }
    wgui_anim_dial_redraw();
    wgui_anim_dial_change_clear_key_up_func();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_anim_dial_star_key_down
 * DESCRIPTION
 *  handle star key down event in animated dial
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_anim_dial_star_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifndef __MMI_MULTITAP_KEY_0__
    wgui_anim_dial_multitap_key_down();
    #else
    wgui_anim_dial_digit_key_handler();
    #endif
    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_anim_dial_key_down_handler
 * DESCRIPTION
 *  handle digit key down events in animated dial
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_anim_dial_key_down_handler(MMI_key_code_type key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dial_code;
    S32 tmp_cursor_pos;
    U16 keyCode, keyType;
    wgui_animated_dial_cntx_struct *ad_cntx = g_anim_dial_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    GetkeyInfo(&keyCode, &keyType);
    /* end up multitap key state */
    if (ad_cntx->multitap_index != -1)
    {
        if (keyCode == KEY_0)
        {
            wgui_anim_dial_multitap_key_down();
            return;
        }
        else
        {
            gui_cancel_timer(wgui_anim_dial_complete_multitap);
            wgui_anim_dial_complete_multitap();
        }
    }
    
    /* if buffer full, then clear the first char in the buffer*/
    if (ad_cntx->final_text_pos >= ad_cntx->dial_buffer_length)
    {
        /* clear the first char in the buffer */
        tmp_cursor_pos = ad_cntx->curr_cursor_pos;
        ad_cntx->curr_cursor_pos = ad_cntx->text_length;
        wgui_anim_dial_clear_one_char();
        ad_cntx->curr_cursor_pos = tmp_cursor_pos - ad_cntx->text_length;
        if (ad_cntx->curr_cursor_pos < 0)
        {
            ad_cntx->curr_cursor_pos = 0;
        }
    }
    /* add keycode to dial_buffer*/
    if (key_code >= KEY_0 && key_code <= KEY_9)
    {
        dial_code = '0' + key_code;
    }
    else if (key_code == KEY_POUND)
    {
        dial_code = '#';
    }
    else if (key_code == KEY_STAR)
    {
        dial_code = '*';
    }
    else
    {
        dial_code = 0;
    }
    wgui_anim_dial_insert_char_to_buffer((U8)dial_code);

    /* increase the img_size_level when the dial number is more than some number */
    if ((ad_cntx->final_text_pos / ad_cntx->text_length) > ad_cntx->word_num[ad_cntx->img_size_level])
    {
        if (ad_cntx->img_size_level < ad_cntx->max_img_size_level)
        {
            ad_cntx->img_size_level++;
        }
        else if (((ad_cntx->curr_cursor_pos - ad_cntx->start_draw_pos) / ad_cntx->text_length) > ad_cntx->word_num[ad_cntx->img_size_level])
        {
            ad_cntx->start_draw_pos += ad_cntx->text_length; 
        }
    }

    /* get the img id to show in animation */
    if (ad_cntx->curr_cursor_pos >= ad_cntx->text_length)
    {
        ad_cntx->anim_keycode = ad_cntx->dial_buffer[ad_cntx->curr_cursor_pos - ad_cntx->text_length];
    }
    else
    {
        ad_cntx->anim_keycode = -1;
    }
    #if defined(__MMI_ANIM_DIAL_KEYIN_ANIMATION__)
    ad_cntx->draw_animation = WGUI_ANIM_DIAL_ANIM_KEY_IN;
    #else
    ad_cntx->draw_animation = WGUI_ANIM_DIAL_ANIM_NONE;
    #endif
    wgui_anim_dial_redraw();
    wgui_anim_dial_change_clear_key_up_func();
}


/*****************************************************************************
 * FUNCTION
 *  MMI_key_input_handler
 * DESCRIPTION
 *  Handler key input events
 * PARAMETERS
 *  key_code        [IN]        
 *  key_event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_anim_dial_digit_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keyCode, keyType;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keyCode, &keyType);

    switch (keyType)
    {
        case KEY_EVENT_DOWN:
        case KEY_EVENT_REPEAT:
            wgui_anim_dial_key_down_handler(keyCode);
            break;
            
        case KEY_EVENT_UP:
            break;
    }
}




/*****************************************************************************
 * FUNCTION
 *  wgui_anim_dial_move_cursor_previous_character
 * DESCRIPTION
 *  move cursor to the previous position
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_anim_dial_move_cursor_previous_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_animated_dial_cntx_struct *ad_cntx = g_anim_dial_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ad_cntx->curr_cursor_pos -= ad_cntx->text_length;
    if (ad_cntx->curr_cursor_pos <= 0)
    {
        /* play error tone if cant't move cursor */
        StopCurrentKeyPadTone();
        srv_prof_play_tone(ERROR_TONE, NULL);
        
        ad_cntx->curr_cursor_pos = 0;
    }
    if (ad_cntx->curr_cursor_pos <= ad_cntx->start_draw_pos)
    {
        ad_cntx->start_draw_pos = ad_cntx->curr_cursor_pos - ad_cntx->text_length;
        if (ad_cntx->start_draw_pos <= 0)
        {
            ad_cntx->start_draw_pos = 0;
        }
    }

    if (ad_cntx->curr_cursor_pos >= ad_cntx->text_length)
    {
        ad_cntx->anim_keycode = ad_cntx->dial_buffer[ad_cntx->curr_cursor_pos - ad_cntx->text_length];
    }
    else
    {
        ad_cntx->anim_keycode = -1;
    }
    #if defined(__MMI_ANIM_DIAL_CURSOR_ANIMATION__)
    ad_cntx->draw_animation = WGUI_ANIM_DIAL_ANIM_MOVE_CURSOR;
    #else
    ad_cntx->draw_animation = WGUI_ANIM_DIAL_ANIM_NONE;
    #endif
    wgui_anim_dial_redraw();
    wgui_anim_dial_change_clear_key_up_func();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_anim_dial_move_cursor_next_character
 * DESCRIPTION
 *  move cursor to the next position
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_anim_dial_move_cursor_next_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_animated_dial_cntx_struct *ad_cntx = g_anim_dial_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ad_cntx->curr_cursor_pos += ad_cntx->text_length;
    if (ad_cntx->curr_cursor_pos >= ad_cntx->final_text_pos)
    {
        /* play error tone if cant't move cursor */
        StopCurrentKeyPadTone();
        srv_prof_play_tone(ERROR_TONE, NULL);

        ad_cntx->curr_cursor_pos = ad_cntx->final_text_pos;
    }
    if (ad_cntx->curr_cursor_pos > (ad_cntx->start_draw_pos + ad_cntx->word_num[ad_cntx->img_size_level] * ad_cntx->text_length))
    {
        ad_cntx->start_draw_pos = ad_cntx->curr_cursor_pos - ad_cntx->word_num[ad_cntx->img_size_level]* ad_cntx->text_length;
    }

    if (ad_cntx->curr_cursor_pos >= ad_cntx->text_length)
    {
        ad_cntx->anim_keycode = ad_cntx->dial_buffer[ad_cntx->curr_cursor_pos - ad_cntx->text_length];
    }
    else
    {
        ad_cntx->anim_keycode = -1;
    }
    #if defined(__MMI_ANIM_DIAL_CURSOR_ANIMATION__)
    ad_cntx->draw_animation = WGUI_ANIM_DIAL_ANIM_MOVE_CURSOR;
    #else
    ad_cntx->draw_animation = WGUI_ANIM_DIAL_ANIM_NONE;
    #endif
    wgui_anim_dial_redraw();
    wgui_anim_dial_change_clear_key_up_func();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_anim_dial_move_cursor_previous_line
 * DESCRIPTION
 *  move cursor to the previous line
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_anim_dial_move_cursor_previous_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_pos;
    S32 img_size_level;
    wgui_animated_dial_cntx_struct *ad_cntx = g_anim_dial_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_pos = ad_cntx->curr_cursor_pos;
    img_size_level = ad_cntx->img_size_level;
    
    ad_cntx->curr_cursor_pos -= 
        (ad_cntx->line_word_num[img_size_level] * ad_cntx->text_length);

    /* if there is no previous line, set cursor to the old position */
    if (ad_cntx->curr_cursor_pos <= 0)
    {
        /* play error tone if cant't move cursor */
        StopCurrentKeyPadTone();
        srv_prof_play_tone(ERROR_TONE, NULL);
        
        if (ad_cntx->start_draw_pos == 0)
        {
            ad_cntx->curr_cursor_pos = old_pos;
        }
        else
        {
            ad_cntx->curr_cursor_pos = 0;
        }
    }
    /* calculate start_draw_pos */
    if (ad_cntx->curr_cursor_pos <= ad_cntx->start_draw_pos)
    {
        ad_cntx->start_draw_pos -= (ad_cntx->line_word_num[img_size_level] * ad_cntx->text_length);
        if (ad_cntx->start_draw_pos < 0)
    {
            ad_cntx->start_draw_pos = 0;
        }
    }
    /* redraw */

    if (ad_cntx->curr_cursor_pos >= ad_cntx->text_length)
    {
        ad_cntx->anim_keycode = ad_cntx->dial_buffer[ad_cntx->curr_cursor_pos - ad_cntx->text_length];
    }
    else
    {
        ad_cntx->anim_keycode = -1;
    }
    #if defined(__MMI_ANIM_DIAL_CURSOR_ANIMATION__)
    ad_cntx->draw_animation = WGUI_ANIM_DIAL_ANIM_MOVE_CURSOR;
    #else
    ad_cntx->draw_animation = WGUI_ANIM_DIAL_ANIM_NONE;
    #endif
    wgui_anim_dial_redraw();
    wgui_anim_dial_change_clear_key_up_func();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_anim_dial_move_cursor_next_line
 * DESCRIPTION
 *  move cursor to the next line
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_anim_dial_move_cursor_next_line(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 img_size_level;
    wgui_animated_dial_cntx_struct *ad_cntx = g_anim_dial_cntx_p;
    S32 totalword, wordinfinalline, currword;
    BOOL has_next_line = TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if there is no next line, return */
    totalword = ad_cntx->final_text_pos / ad_cntx->text_length;
    wordinfinalline = totalword % ad_cntx->line_word_num[ad_cntx->img_size_level];
    if (wordinfinalline == 0)
    {
        wordinfinalline = ad_cntx->line_word_num[ad_cntx->img_size_level];
    }
    currword = ad_cntx->curr_cursor_pos / ad_cntx->text_length;
    if (totalword - currword < wordinfinalline)
    {
        /* play error tone if cant't move cursor */
        StopCurrentKeyPadTone();
        srv_prof_play_tone(ERROR_TONE, NULL);
        
        has_next_line = FALSE;
    }

    if (has_next_line)
    {
        img_size_level = ad_cntx->img_size_level;
        
        ad_cntx->curr_cursor_pos += 
            (ad_cntx->line_word_num[img_size_level] * ad_cntx->text_length);
        
        /* if the next line has no current position, set cursor to the last position */
        if (ad_cntx->curr_cursor_pos > ad_cntx->final_text_pos)
        {
            ad_cntx->curr_cursor_pos = ad_cntx->final_text_pos;
        }
    }
        
    /* calculate the start_draw_pos */
    if (ad_cntx->curr_cursor_pos > 
        (ad_cntx->start_draw_pos + ad_cntx->word_num[ad_cntx->img_size_level] * ad_cntx->text_length))
    {
        ad_cntx->start_draw_pos = ad_cntx->curr_cursor_pos - ad_cntx->word_num[ad_cntx->img_size_level]* ad_cntx->text_length;
    }
    /* redraw */
    if (ad_cntx->curr_cursor_pos >= ad_cntx->text_length)
    {
        ad_cntx->anim_keycode = ad_cntx->dial_buffer[ad_cntx->curr_cursor_pos - ad_cntx->text_length];
    }
    else
    {
        ad_cntx->anim_keycode = -1;
    }    
    #if defined(__MMI_ANIM_DIAL_CURSOR_ANIMATION__)
    ad_cntx->draw_animation = WGUI_ANIM_DIAL_ANIM_MOVE_CURSOR;
    #else
    ad_cntx->draw_animation = WGUI_ANIM_DIAL_ANIM_NONE;
    #endif
    wgui_anim_dial_redraw();
    wgui_anim_dial_change_clear_key_up_func();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_anim_dial_set_category_history
 * DESCRIPTION
 *  put the data from history data to context data
 * PARAMETERS
 *  history_ID          [IN]        
 *  history_buffer      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 wgui_anim_dial_set_category_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len, final_pos, i;
    wgui_animated_dial_cntx_struct *ad_cntx = g_anim_dial_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        // if history buffer is not null, use the content in history buffer to fill ad_cntx information
        wgui_anim_dial_category_history *h = (wgui_anim_dial_category_history*) history_buffer;

        if (history_valid(h->history_ID, history_ID))
        {
            len = gui_strlen((UI_string_type)ad_cntx->dial_buffer);
            final_pos = len * ad_cntx->text_length;
            if (final_pos == h->final_text_pos)
            {
                ad_cntx->final_text_pos = h->final_text_pos;
                ad_cntx->curr_cursor_pos = h->curr_cursor_pos;
                ad_cntx->start_draw_pos = h->start_draw_pos;
                ad_cntx->img_size_level = h->img_size_level;

                return (1);
            }
        }
    }

    // if history buffer is null, init the ad_cntx information
    len = gui_strlen((UI_string_type)ad_cntx->dial_buffer);
    final_pos = len * ad_cntx->text_length;
    
    ad_cntx->final_text_pos = final_pos;
    ad_cntx->curr_cursor_pos = final_pos;
    ad_cntx->img_size_level = 0;
    for (i = 0; i < ad_cntx->max_img_size_level; i++)
    {
        if (len > ad_cntx->word_num[i])
        {
            ad_cntx->img_size_level++;
        }
    }
    ad_cntx->start_draw_pos = final_pos - (ad_cntx->word_num[ad_cntx->img_size_level] * ad_cntx->text_length);
    if (ad_cntx->start_draw_pos < 0)
    {
        ad_cntx->start_draw_pos = 0;
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_anim_dial_get_category_history
 * DESCRIPTION
 *  save the context data to history buffer of Animated_dial screen
 * PARAMETERS
 *  history_ID          [IN]        
 *  history_buffer      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_anim_dial_get_category_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_animated_dial_cntx_struct *ad_cntx = g_anim_dial_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        U16 hID = (U16) (history_ID | 0x8000);
        wgui_anim_dial_category_history *h = (wgui_anim_dial_category_history *) history_buffer;

        h->history_ID = hID;
        h->curr_cursor_pos = ad_cntx->curr_cursor_pos;
        h->final_text_pos = ad_cntx->final_text_pos;
        h->img_size_level = ad_cntx->img_size_level;
        h->start_draw_pos = ad_cntx->start_draw_pos;
    }
}

/*****************************************************************************
 * FUNCTION
 *  GetCategory631History
 * DESCRIPTION
 *  Get the category631 screen history
 * PARAMETERS
 *  history_buffer      [IN/OUT]        History_buffer
 * RETURNS
 *  U8*
 *****************************************************************************/
U8 *GetCategory631History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_anim_dial_get_category_history(MMI_CATEGORY631_ID, history_buffer);
    return (history_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory631HistorySize
 * DESCRIPTION
 *  Get the category631 screen history size
 * PARAMETERS
 *  void
 * RETURNS
 *  S32 size of category 631 history
 *****************************************************************************/
S32 GetCategory631HistorySize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sizeof(wgui_anim_dial_category_history);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_anim_dial_init
 * DESCRIPTION
 *  do the initialize work of struct wgui_anim_dial_cntx
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_anim_dial_init(
        S32 animated_dial_x, 
        S32 animated_dial_y,
        S32 animated_dial_w,
        S32 animated_dial_h,
        UI_buffer_type buffer,
        S32 buffer_size,
        U8 *history_buffer)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num_lines;
    S32 cursor_img_w, cursor_img_h[WGUI_ANIM_DIAL_TOTAL_IMG_SIZE_LEVEL - 1];
    S32 i;
	wgui_animated_dial_cntx_struct *ad_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_anim_dial_cntx_p != NULL)
    {
        OslMfree(g_anim_dial_cntx_p);
        g_anim_dial_cntx_p = NULL;
    }
    g_anim_dial_cntx_p = (wgui_animated_dial_cntx_struct*)OslMalloc(sizeof(wgui_animated_dial_cntx_struct));
    MMI_ASSERT(g_anim_dial_cntx_p != NULL);
    
    memset(g_anim_dial_cntx_p, 0, sizeof(wgui_animated_dial_cntx_struct));
    ad_cntx = g_anim_dial_cntx_p;
    
    gdi_image_get_dimension_id(IMG_ID_ANIMATED_DIAL_CURSOR, &cursor_img_w, &cursor_img_h[0]);
    gdi_image_get_dimension_id(IMG_ID_ANIMATED_DIAL_CURSOR_S, &cursor_img_w, &cursor_img_h[1]);
    ad_cntx->x = animated_dial_x;
    ad_cntx->y = animated_dial_y;
    ad_cntx->width = animated_dial_w;
    ad_cntx->height = animated_dial_h /*- cursor_img_h*/;

    ad_cntx->dial_buffer = buffer;
    /* buffer_size should -1 to save the space for string end */
    ad_cntx->dial_buffer_length = (buffer_size - 1)*WGUI_ANIM_DIAL_TEXT_LENGTH;
    ad_cntx->text_length = WGUI_ANIM_DIAL_TEXT_LENGTH;
    
    ad_cntx->max_img_size_level = WGUI_ANIM_DIAL_TOTAL_IMG_SIZE_LEVEL - 1;
    ad_cntx->anim_handle = GDI_NULL_HANDLE;
    ad_cntx->cursor_handle = GDI_NULL_HANDLE;
    ad_cntx->draw_animation = WGUI_ANIM_DIAL_ANIM_NONE;
    ad_cntx->multitap_index = -1;
    #ifndef __MMI_MULTITAP_KEY_0__
    ad_cntx->multitap_char = wgui_anim_dial_star_key_string;
    #else
    ad_cntx->multitap_char = wgui_anim_dial_zero_key_string;
    #endif
    
    gdi_image_get_frame_count((U8*)GetImage(IMG_ID_ANIMATED_DIAL_0), &ad_cntx->anim_max_frame[0]);
    gdi_image_get_frame_count((U8*)GetImage(IMG_ID_ANIMATED_DIAL_S_0), &ad_cntx->anim_max_frame[1]);
    for (i = 0; i < WGUI_ANIM_DIAL_TOTAL_IMG_SIZE_LEVEL; i++)
    {
        ad_cntx->anim_max_frame[i]--;
    }
    gdi_image_get_dimension_id(IMG_ID_ANIMATED_DIAL_0, &ad_cntx->img_w[0], &ad_cntx->img_h[0]);
    gdi_image_get_dimension_id(IMG_ID_ANIMATED_DIAL_S_0, &ad_cntx->img_w[1], &ad_cntx->img_h[1]);
    if (ad_cntx->img_w[0] <= 0 || ad_cntx->img_w[1] <= 0 || ad_cntx->img_h[0] <= 0 || ad_cntx->img_h[1] <= 0)
    {
        ASSERT(0);
    }

    ad_cntx->fly_in_frame = -1;
    
    /* calculate text_gap and word_num from width, height and img size */
    ad_cntx->line_word_num[0] = WGUI_ANIM_DIAL_DIGIT_IN_LINE_0;
    ad_cntx->line_word_num[1] = WGUI_ANIM_DIAL_DIGIT_IN_LINE_1;
    for (i = 0; i < WGUI_ANIM_DIAL_TOTAL_IMG_SIZE_LEVEL; i++)
    {
        num_lines = (ad_cntx->height - cursor_img_h[i] + ad_cntx->img_h[i]) / ad_cntx->img_h[i];
        ad_cntx->word_num[i] = ad_cntx->line_word_num[i] * num_lines;
        ad_cntx->text_gap[i] = ((ad_cntx->width - 
                                           (ad_cntx->img_w[i] * ad_cntx->line_word_num[i])) / 
    						              (ad_cntx->line_word_num[i] - 1))-1;
        ad_cntx->line_gap[i] = (((ad_cntx->height - cursor_img_h[i]) % ad_cntx->img_h[i]) / (num_lines - 1 ))-1;
    }

    wgui_anim_dial_set_category_history(MMI_CATEGORY631_ID, history_buffer);
    
    ad_cntx->anim_dial_RSK_key_up_func = NULL;
    ad_cntx->is_buf_empty = (gui_strlen((UI_string_type)ad_cntx->dial_buffer) >0)? FALSE : TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory631Screen
 * DESCRIPTION
 *  Exits the category631 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory631Screen(void)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_animated_dial_cntx_struct *ad_cntx = g_anim_dial_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    gui_cancel_timer(wgui_anim_dial_complete_multitap);
    gui_cancel_timer(wgui_anim_dial_play_fly_in_animation);
    if (ad_cntx)
    {
        gdi_image_stop_animation(ad_cntx->anim_handle);
        gdi_image_stop_animation(ad_cntx->cursor_handle);
        OslMfree(g_anim_dial_cntx_p);
    }
    g_anim_dial_cntx_p = NULL;
    g_wgui_anim_dial_not_empty_callback = NULL;
    g_wgui_anim_dial_empty_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory631Screen
 * DESCRIPTION
 *  Displays the category631 screen(Animated Dialing Screen)
 * PARAMETERS
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the Left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  Buffer                  [IN]        Message string
 *  BufferLength            [IN]        Length of buffer
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory631Screen(
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8 *Buffer,
        U32 BufferLength,
        U8 *history_buffer)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    wgui_animated_dial_cntx_struct *ad_cntx = NULL;
    U16 KEY_CODE_NUMBER[11] = {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_POUND};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* init */
    wgui_anim_dial_init( 
        WGUI_ANIM_DIAL_CONTENT_X, 
        WGUI_ANIM_DIAL_CONTENT_Y, 
        WGUI_ANIM_DIAL_CONTENT_W, 
        WGUI_ANIM_DIAL_CONTENT_H, 
        (UI_buffer_type)Buffer,BufferLength,history_buffer);

    ad_cntx = g_anim_dial_cntx_p;
    /* lock */
    gdi_layer_lock_frame_buffer();
    
    dm_add_softkey((UI_string_type)GetString(left_softkey), (PU8)GetImage(left_softkey_icon), (UI_string_type)GetString(right_softkey), (PU8)GetImage(right_softkey_icon));
    
    /* let the status bar and button bar to be transparent */
    wgui_set_wallpaper_on_bottom(MMI_TRUE);

    /* CONTROLLED_AREA */
    dm_register_category_controlled_callback(DrawCate631CategoryControlArea1);

    // set key handlers
    SetGroupKeyHandler(wgui_anim_dial_digit_key_handler, KEY_CODE_NUMBER, 11, KEY_EVENT_DOWN);
    SetGroupKeyHandler(wgui_anim_dial_digit_key_handler, KEY_CODE_NUMBER, 11, KEY_EVENT_REPEAT);
    SetKeyHandler(wgui_anim_dial_star_key_down, KEY_STAR, KEY_EVENT_DOWN);       // star key 
    SetKeyHandler(wgui_anim_dial_star_key_down, KEY_STAR, KEY_EVENT_LONG_PRESS); // star key 
    SetKeyHandler(wgui_anim_dial_star_key_down, KEY_STAR, KEY_EVENT_REPEAT);     //star key 

#ifdef __MMI_MULTITAP_KEY_0__
    SetKeyHandler(wgui_anim_dial_multitap_key_down, KEY_0, KEY_EVENT_LONG_PRESS); // zero key 
    SetKeyHandler(wgui_anim_dial_multitap_key_down, KEY_0, KEY_EVENT_REPEAT);     //zero key 
#endif

#if defined(__MMI_WITH_C_KEY__)
    set_right_softkey_function(wgui_anim_dial_RSK_key_up_handler, KEY_EVENT_UP);
    SetKeyHandler(wgui_anim_dial_delete_all, KEY_CLEAR, KEY_LONG_PRESS);         //clear key 
    SetKeyHandler(wgui_anim_dial_backspace, KEY_CLEAR, KEY_EVENT_DOWN);
    if (ad_cntx->is_buf_empty)
    {
        SetKeyHandler(wgui_anim_dial_RSK_key_up_handler, KEY_CLEAR, KEY_EVENT_UP);
        if (g_wgui_anim_dial_empty_callback != NULL)
        {
            (*g_wgui_anim_dial_empty_callback)();
        }
    }
    else
    {
        SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_UP);
        if (g_wgui_anim_dial_not_empty_callback != NULL)
        {
            (*g_wgui_anim_dial_not_empty_callback)();
        }
    }
#else    
    set_right_softkey_function(wgui_anim_dial_delete_all, KEY_LONG_PRESS);
    set_right_softkey_function(wgui_anim_dial_backspace, KEY_EVENT_DOWN);
    if (ad_cntx->is_buf_empty)
    {
        set_right_softkey_function(wgui_anim_dial_RSK_key_up_handler, KEY_EVENT_UP);
        if (g_wgui_anim_dial_empty_callback != NULL)
        {
            (*g_wgui_anim_dial_empty_callback)();
        }
    }
    else
    {
        /* can't use change_right_softkey() here, because it will call reset_softkey() */
        set_right_softkey_label(get_string(STR_GLOBAL_CLEAR));
        set_right_softkey_icon(get_image(IMAGE_ID_NULL));
        if (g_wgui_anim_dial_not_empty_callback != NULL)
        {
            (*g_wgui_anim_dial_not_empty_callback)();
        }
        redraw_right_softkey();
        set_right_softkey_function(UI_dummy_function, KEY_EVENT_UP);
    }
#endif   

    SetKeyHandler(wgui_anim_dial_move_cursor_previous_character, KEY_LEFT_ARROW, KEY_EVENT_DOWN);  //arrow keys  
    SetKeyHandler(wgui_anim_dial_move_cursor_next_character, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_anim_dial_move_cursor_previous_line, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_anim_dial_move_cursor_next_line, KEY_DOWN_ARROW, KEY_EVENT_DOWN);

    wgui_softkey_set_filler_disabled(MMI_TRUE);     /* set the button bar transparent*/
    ExitCategoryFunction = ExitCategory631Screen;    
    
    dm_setup_category_functions(dm_redraw_category_screen, GetCategory631History, GetCategory631HistorySize);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY631_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_data.s32flags |= DM_SET_AS_ABM_LAYER;

    dm_setup_data(&dm_data);
    dm_redraw_category_screen();

    /* unlock */
    gdi_layer_unlock_frame_buffer();
    
    ad_cntx = g_anim_dial_cntx_p;
    /* save the keycode to show in animation */
    if (ad_cntx->curr_cursor_pos >= ad_cntx->text_length)
    {
        ad_cntx->anim_keycode = ad_cntx->dial_buffer[ad_cntx->curr_cursor_pos - ad_cntx->text_length];
    }
    else
    {
        ad_cntx->anim_keycode = -1;
    }
    ad_cntx->draw_animation = WGUI_ANIM_DIAL_ANIM_NONE;

	wgui_anim_dial_redraw();
    wgui_anim_dial_change_clear_key_up_func();
    
}   /* end of ShowCategory631Screen */
#else /* __MMI_ANIMATED_DIAL__ */ 
void wgui_categories_dialer_dummy(void){}
#endif /* __MMI_ANIMATED_DIAL__ */



#ifdef __MMI_MOTION_DIAL__

#include "swflashGprot.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_swflash.h"
#include "PhoneSetupGprots.h"

#ifdef __MMI_MULTITAP_KEY_0__
UI_character_type g_wgui_cat633_zero_key_string[] = { '+', 'p', 'w', '\0' };
#else /* __MMI_MULTITAP_KEY_0__ */ 
UI_character_type g_wgui_cat633_star_key_string[] = { '*', '+', 'p', 'w', '\0' };
#endif /* __MMI_MULTITAP_KEY_0__ */ 

static void (*g_wgui_cat633_RSK_function) (void) = NULL;
static wgui_cat633_cntx_struct *g_wgui_cat633_cntx_p = NULL;
static mdi_swflash_para *g_wgui_cat633_swflash_para_p = NULL;
static void (*g_wgui_cat633_not_empty_callback) (void) = NULL;
static void (*g_wgui_cat633_empty_callback) (void) = NULL;

static void wgui_cat633_backspace(void);
static void wgui_cat633_clear_key_up_handler(void);
static void wgui_cat633_complete_multitap(void);
static void wgui_cat633_convert_ansii_buffer_to_unicode_buffer(void);
static void wgui_cat633_delete_all(void);
static void wgui_cat633_register_clear_key_up_handler(void);

/* extern */
extern mdi_swflash_info_struct wgui_swflash_info;
extern MMI_BOOL mmi_suspend_handle_key_process(MMI_BOOL enable);
extern kal_uint16 app_asc_str_to_ucs2_str(kal_int8 *pOutBuffer, kal_int8 *pInBuffer);
extern kal_uint16 app_ucs2_str_to_asc_str(kal_int8 *pOutBuffer, kal_int8 *pInBuffer);
extern gdi_handle wgui_base_layer;

/*****************************************************************************
 * FUNCTION
 *  wgui_cat633_register_RSK_function
 * DESCRIPTION
 *  Register RSK callback function
 * PARAMETERS
 *  f      [IN]      RSK callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat633_register_RSK_function(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_cat633_RSK_function = f;
}    


/*****************************************************************************
 * FUNCTION
 *  wgui_cat633_register_not_empty_function
 * DESCRIPTION
 *  Register not empty callback function
 * PARAMETERS
 *  f      [IN]      not empty callback function
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat633_register_not_empty_function(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_cat633_not_empty_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat633_register_empty_function
 * DESCRIPTION
 *  Register empty callback function
 * PARAMETERS
 *  f      [IN]      empty callback function
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat633_register_empty_function(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_cat633_empty_callback = f;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat633_swflash_pre_callback
 * DESCRIPTION
 *  Redraw status icon bar before blt swflash.
 * PARAMETERS
 *  offset_x      [IN]
 *  offset_y      [IN]          
 *  width         [IN]
 *  height        [IN]  
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat633_swflash_pre_callback(S32 offset_x, S32 offset_y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(offset_x);
    UI_UNUSED_PARAMETER(offset_y);
    UI_UNUSED_PARAMETER(width);
    UI_UNUSED_PARAMETER(height);
    gdi_layer_lock_frame_buffer();
    wgui_status_icon_bar_update();
    gdi_layer_unlock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat633_draw_controlled_area
 * DESCRIPTION
 *  Play SWFlash content in the controlled area in motion dial
 * PARAMETERS
 *  coordinate      [IN]        Coordinates of category controlled area.
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat633_draw_controlled_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result = MDI_RES_SWFLASH_ERR_FAILED; 
    GDI_HANDLE active_layer;
    U16 dialer_style;
    S32 purpose;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(coordinate);

    /* get dialer style from setting */
    dialer_style = PhnsetGetDialStyle();
    MMI_ASSERT(dialer_style != 0);	
    
    /* open SWFlash file from resource */
    result = mdi_swflash_open_id(dialer_style, SWFLASH_SCREEN, &wgui_swflash_info);
    /* No SWFlash file */
    MMI_ASSERT(result == MDI_RES_SWFLASH_SUCCEED);

    /* play SWFlash */
    gdi_layer_get_active(&active_layer);

    purpose = mdi_swflash_get_play_purpose();
    mdi_swflash_change_play_purpose(MDI_SWFLASH_PURPOSE_MOTION_STYLE);
    result = mdi_swflash_play(active_layer, 1, MDI_DEVICE_SPEAKER2, NULL); 
	wgui_status_icon_set_alpha_layer(active_layer);
    mdi_swflash_register_blt_callback(wgui_cat633_swflash_pre_callback, NULL);
    /* File is not valid or load unsuccessful */
    MMI_ASSERT(result == MDI_RES_SWFLASH_SUCCEED);
    mdi_swflash_change_play_purpose(purpose);
}   


/*****************************************************************************
 * FUNCTION
 *  wgui_cat633_input_handle
 * DESCRIPTION
 *  When input, this function register RSK function or C key function, and set
 *  RSK label according to each situation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat633_input_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dial_length;
    wgui_cat633_cntx_struct *md_cntx = g_wgui_cat633_cntx_p;
    mdi_swflash_para *swflash_para = g_wgui_cat633_swflash_para_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dial_length = strlen(swflash_para->para[1]);    

    if (dial_length > 0) /* There are some characters in dial buffer (0->1) */
    {
#if defined(__MMI_WITH_C_KEY__)
        if (md_cntx->RSK_label_clear == 0)
        {
            if (g_wgui_cat633_not_empty_callback != NULL)
            {
                g_wgui_cat633_not_empty_callback();
            }
            md_cntx->RSK_label_clear = 1;
            SetKeyHandler(wgui_cat633_backspace, KEY_CLEAR, KEY_EVENT_DOWN);
            SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_UP);
            SetKeyHandler(wgui_cat633_delete_all, KEY_CLEAR, KEY_EVENT_LONG_PRESS);
        }
#else /* defined(__MMI_WITH_C_KEY__) */ 
        if (md_cntx->RSK_label_clear == 0)
        {
            set_right_softkey_label((UI_string_type)get_string(STR_GLOBAL_CLEAR));
            set_right_softkey_icon(NULL);
            if (g_wgui_cat633_not_empty_callback != NULL)
            {
                g_wgui_cat633_not_empty_callback();
            }
            redraw_right_softkey();
            md_cntx->RSK_label_clear = 1;
            set_right_softkey_function(UI_dummy_function, KEY_EVENT_UP);
            set_right_softkey_function(wgui_cat633_backspace, KEY_EVENT_DOWN);
        }
#endif /* defined(__MMI_WITH_C_KEY__) */ 
    }
    else /* There is no character in dial buffer (1->0) */
    {
#if defined(__MMI_WITH_C_KEY__)
        if (md_cntx->RSK_label_clear == 1)
        {
            if (g_wgui_cat633_empty_callback != NULL)
            {
                g_wgui_cat633_empty_callback();
            }
            md_cntx->RSK_label_clear = 0;
            SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_DOWN);
            SetKeyHandler(wgui_cat633_clear_key_up_handler, KEY_CLEAR, KEY_EVENT_UP);
            SetKeyHandler(UI_dummy_function, KEY_CLEAR, KEY_EVENT_LONG_PRESS);
        }
#else /* defined(__MMI_WITH_C_KEY__) */ 
        if (md_cntx->RSK_label_clear == 1)
        {
    #if(WGUI_CAT633_DISABLE_DIALER_BACK_KEY)
            set_right_softkey_function(wgui_cat633_clear_key_up_handler, KEY_EVENT_UP);
            set_right_softkey_label(md_cntx->RSK_label_original_string);
            set_right_softkey_icon(md_cntx->RSK_label_original_icon); 
            if (g_wgui_cat633_empty_callback != NULL)
            {
                g_wgui_cat633_empty_callback();
            }
            redraw_right_softkey();
            md_cntx->RSK_label_clear = 0;
    #else /* (DISABLE_DIALER_BACK_KEY) */
            set_right_softkey_label(md_cntx->RSK_label_original_string);
            set_right_softkey_icon(md_cntx->RSK_label_original_icon); 
            if (g_wgui_cat633_empty_callback != NULL)
            {
                g_wgui_cat633_empty_callback();
            }
            redraw_right_softkey();
            md_cntx->RSK_label_clear = 0;
            set_right_softkey_function(wgui_cat633_register_clear_key_up_handler, KEY_EVENT_UP);
            set_right_softkey_function(UI_dummy_function, KEY_EVENT_DOWN);
    #endif /* (DISABLE_DIALER_BACK_KEY) */ 
        }
#endif /* defined(__MMI_WITH_C_KEY__) */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat633_convert_ansii_buffer_to_unicode_buffer
 * DESCRIPTION
 *  This is the callback function for SWFlash engine in in motion dial.
 *  Convert dial ansii buffer (used in SWFlash engine) to dial unicode buffer(used in MMI)
 *  If there are some numbers in dial buffer, right softkey must change to "CLEAR". 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat633_convert_ansii_buffer_to_unicode_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_cat633_cntx_struct *md_cntx = g_wgui_cat633_cntx_p;
    mdi_swflash_para *swflash_para = g_wgui_cat633_swflash_para_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	//printf("--------------------------convert_ansii_buffer_to_unicode_buffer:%d\n",g_mmi_suspend_key_flag);
    app_asc_str_to_ucs2_str((kal_int8*)md_cntx->dial_buffer_unicode, (kal_int8*)swflash_para->para[1]);	
    wgui_cat633_input_handle();
    mmi_suspend_handle_key_process(MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat633_group_key_event_down
 * DESCRIPTION
 *  Key down event handler for group key in motion dial 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat633_group_key_event_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    U16 key_code, key_type;
    wgui_cat633_cntx_struct *md_cntx = g_wgui_cat633_cntx_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* SWFlash key event */
    md_cntx->multitap_charater_index = -1;
    GetkeyInfo(&key_code, &key_type);    
    mdi_swflash_key_down_event(key_code);
    mmi_suspend_handle_key_process(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat633_group_key_event_up
 * DESCRIPTION
 *  Key up event handler for group key in motion dial
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat633_group_key_event_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    U16 key_code, key_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&key_code, &key_type);    
    mdi_swflash_key_up_event(key_code);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat633_backspace
 * DESCRIPTION
 *  Handle backspace event in motion dial
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat633_backspace(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_cat633_cntx_struct *md_cntx = g_wgui_cat633_cntx_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/       
    /* SWFlash key event */    
    md_cntx->multitap_charater_index = -1;
    mdi_swflash_key_down_event(KEY_CLEAR);
    mmi_suspend_handle_key_process(MMI_TRUE);
    //printf("--------------------------backspace:%d\n", g_mmi_suspend_key_flag);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat633_delete_all
 * DESCRIPTION
 *  Handle long press event of backspace in motion dial
 *  delete all characters in dial ansii buffer and dial unicode buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat633_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_cat633_cntx_struct *md_cntx = g_wgui_cat633_cntx_p;
	mdi_swflash_para *swflash_para = g_wgui_cat633_swflash_para_p;
    S32 dial_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear buffer */
    dial_length = strlen(swflash_para->para[1]);
    memset(swflash_para->para[1], 0, dial_length);
    app_asc_str_to_ucs2_str((kal_int8*)md_cntx->dial_buffer_unicode, (kal_int8*)swflash_para->para[1]);
    wgui_cat633_input_handle();

    /* SWFlash key event: clear all */
    md_cntx->multitap_charater_index = -1;
    mdi_swflash_key_down_event('c');
    mmi_suspend_handle_key_process(MMI_TRUE);
    //printf("--------------------------delete all:%d\n", g_mmi_suspend_key_flag);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat633_register_clear_key_up_handler
 * DESCRIPTION
 *  Register clear key up handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat633_register_clear_key_up_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(WGUI_CAT633_DISABLE_DIALER_BACK_KEY != 1)
    set_right_softkey_function(wgui_cat633_clear_key_up_handler, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat633_clear_key_up_handler
 * DESCRIPTION
 *  Handle key up event of clear key (or RSK) in motion dial
 *  If there is no character in dial buffer, RSK_key_up_funcion() is executed.
 *  RSK_key_up_funcion() is registered by APP in SetCategory16RightSoftkeyFunction
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat633_clear_key_up_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_swflash_para *swflash_para = g_wgui_cat633_swflash_para_p;
    S32 dial_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* There is no character in buffer, return to idle screen*/
    dial_length = strlen(swflash_para->para[1]);
	//printf("--------------------------clear_key_up_handler: dial_length %d, %d\n", dial_length, g_mmi_suspend_key_flag);
    if (dial_length <= 0)
    {
	    if(g_wgui_cat633_RSK_function != NULL)
        {
            g_wgui_cat633_RSK_function();
        }    
    }    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat633_register_cursor_key_handler
 * DESCRIPTION
 *  Register cursor key and digit key (0-9) handler in motion dial
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat633_register_input_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U16 key_input[WGUI_CAT633_DIAL_KEY_NUMBER] = {
        KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6,KEY_7, KEY_8, KEY_9,
        };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    SetGroupKeyHandler(wgui_cat633_group_key_event_down, key_input, WGUI_CAT633_DIAL_KEY_NUMBER, KEY_EVENT_DOWN);
    SetGroupKeyHandler(wgui_cat633_group_key_event_up, key_input, WGUI_CAT633_DIAL_KEY_NUMBER, KEY_EVENT_UP);
    SetGroupKeyHandler(wgui_cat633_group_key_event_down, key_input, WGUI_CAT633_DIAL_KEY_NUMBER, KEY_REPEAT);   
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat633_complete_multitap
 * DESCRIPTION
 *  expire when multitap is time out in motion dial
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat633_complete_multitap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_cat633_cntx_struct *md_cntx = g_wgui_cat633_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* when multitap time out, multitap index set to -1 */
    md_cntx->multitap_charater_index = -1; 
	
#ifdef __MMI_MULTITAP_KEY_0__
    SetKeyHandler(wgui_cat633_group_key_event_down, KEY_0, KEY_EVENT_DOWN);
#endif /* __MMI_MULTITAP_KEY_0__ */
    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat633_multitap_key_handler
 * DESCRIPTION
 *  Handle key down event when a multitap key key down in motion dial
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat633_multitap_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    wgui_cat633_cntx_struct *md_cntx = g_wgui_cat633_cntx_p;
    mdi_swflash_para *swflash_para = g_wgui_cat633_swflash_para_p;
	U16 key_code, key_type;	
    S32 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	GetkeyInfo(&key_code, &key_type);

    /* multitap timer: when time out, cursor move to the next position */
    gui_start_timer(WGUI_CAT633_MULTITAP_TIMEOUT, wgui_cat633_complete_multitap);

#ifdef __MMI_MULTITAP_KEY_0__
    SetKeyHandler(wgui_cat633_multitap_key_handler, KEY_0, KEY_EVENT_DOWN);
#endif

    /* add keycode to dial_buffer*/
    length = strlen(swflash_para->para[1]);
    if ((md_cntx->multitap_charater_index <= -1) && ((key_type == KEY_EVENT_DOWN) || (key_type == KEY_EVENT_REPEAT)))
    {
        /* the first time press star key */
        md_cntx->multitap_charater_index = 0;
        
        /* SWFlash key event */
#ifdef __MMI_MULTITAP_KEY_0__
        mdi_swflash_key_down_event(md_cntx->multitap_char[md_cntx->multitap_charater_index]);        
        mmi_suspend_handle_key_process(MMI_TRUE);
#else /* __MMI_MULTITAP_KEY_0__ */        
        mdi_swflash_key_down_event(KEY_STAR);
        mmi_suspend_handle_key_process(MMI_TRUE);
#endif /* __MMI_MULTITAP_KEY_0__ */        
    }
    else
    {       
        /* not the first time press star key */
        md_cntx->multitap_charater_index++;
		
		/* raech the last character of multitap string: a new character in the screen */
		if (md_cntx->multitap_char[md_cntx->multitap_charater_index] == '\0')
        {
            md_cntx->multitap_charater_index = 0;
			
            mdi_swflash_key_down_event(md_cntx->multitap_char[md_cntx->multitap_charater_index]);        
            mmi_suspend_handle_key_process(MMI_TRUE);
        }
        else
        {		
            /* change the character */
            length = strlen(swflash_para->para[1]);
		    (swflash_para->para[1])[length] = (U8)(md_cntx->multitap_char[md_cntx->multitap_charater_index]);

            /* SWFlash key event */
            mdi_swflash_key_down_event(md_cntx->multitap_char[md_cntx->multitap_charater_index]);
            mmi_suspend_handle_key_process(MMI_TRUE);
        }
    }    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat633_pound_key_down
 * DESCRIPTION
 *  Pound key(#) down event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat633_pound_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_cat633_cntx_struct *md_cntx = g_wgui_cat633_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* SWFlash key event */
    md_cntx->multitap_charater_index = -1;
    mdi_swflash_key_down_event(KEY_POUND);
    mmi_suspend_handle_key_process(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat633_star_key_down
 * DESCRIPTION
 *  Handle star key down event in motion dial
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat633_star_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MULTITAP_KEY_0__  
    wgui_cat633_multitap_key_handler();  /* star key support multitap */
#else  
	mdi_swflash_key_down_event(KEY_STAR);     /* star key just show '*' */
    mmi_suspend_handle_key_process(MMI_TRUE);
#endif  /* __MMI_MULTITAP_KEY_0__ */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat633_set_key_handler
 * DESCRIPTION
 *  Set all key handler in motion dial
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat633_set_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* cursor key & number keys*/
    wgui_cat633_register_input_key_handler();

    /* pound key */
    SetKeyHandler(wgui_cat633_pound_key_down, KEY_POUND, KEY_EVENT_DOWN);     

    /* star key */    
    SetKeyHandler(wgui_cat633_star_key_down, KEY_STAR, KEY_EVENT_DOWN);       
    SetKeyHandler(wgui_cat633_star_key_down, KEY_STAR, KEY_EVENT_LONG_PRESS); 
    SetKeyHandler(wgui_cat633_star_key_down, KEY_STAR, KEY_EVENT_REPEAT);     

    /* zero key */
#ifdef __MMI_MULTITAP_KEY_0__
	SetKeyHandler(wgui_cat633_multitap_key_handler, KEY_0, KEY_EVENT_LONG_PRESS);    
	SetKeyHandler(wgui_cat633_multitap_key_handler, KEY_0, KEY_EVENT_REPEAT);
#endif /* __MMI_MULTITAP_KEY_0__ */

    /* clear key */
#ifdef __MMI_WITH_C_KEY__
	SetKeyHandler(wgui_cat633_delete_all, KEY_CLEAR, KEY_LONG_PRESS);         
	SetKeyHandler(wgui_cat633_backspace, KEY_CLEAR, KEY_EVENT_DOWN);    
    SetKeyHandler(wgui_cat633_clear_key_up_handler, KEY_CLEAR, KEY_EVENT_UP);    
    SetRightSoftkeyFunction(wgui_cat633_delete_all, KEY_EVENT_DOWN);    
    SetRightSoftkeyFunction(wgui_cat633_clear_key_up_handler, KEY_EVENT_UP);
#else   /* __MMI_WITH_C_KEY__ */
	SetRightSoftkeyFunction(wgui_cat633_delete_all, KEY_LONG_PRESS);    
    SetRightSoftkeyFunction(wgui_cat633_backspace, KEY_EVENT_DOWN);    
    SetRightSoftkeyFunction(wgui_cat633_clear_key_up_handler, KEY_EVENT_UP);
#endif  /* __MMI_WITH_C_KEY__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat633_dial_init_cntx
 * DESCRIPTION
 *  Initial motion dial paramters
 * PARAMETERS
 *  buffer      [IN]        dial unicode buffer (user in MMI)
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat633_init_cntx(UI_buffer_type buffer, UI_string_type RSK_label, PU8 RSK_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* pre-process memory */
    if (g_wgui_cat633_cntx_p != NULL)
    {
        OslMfree(g_wgui_cat633_cntx_p);
		g_wgui_cat633_cntx_p = NULL;
    }   

    /* allocate memory */
    g_wgui_cat633_cntx_p = (wgui_cat633_cntx_struct*)OslMalloc(sizeof(wgui_cat633_cntx_struct));   
    MMI_ASSERT(g_wgui_cat633_cntx_p != NULL);
    memset(g_wgui_cat633_cntx_p, 0, sizeof(wgui_cat633_cntx_struct));
    g_wgui_cat633_cntx_p->multitap_charater_index = -1;
    g_wgui_cat633_cntx_p->RSK_label_clear = 0;
#ifndef __MMI_WITH_C_KEY__
    g_wgui_cat633_cntx_p->RSK_label_original_string = RSK_label;
    g_wgui_cat633_cntx_p->RSK_label_original_icon = RSK_icon;
#endif

    g_wgui_cat633_cntx_p->dial_buffer_unicode = buffer;
    /* convert unicode buffer to ansii buffer */
	app_ucs2_str_to_asc_str((kal_int8 *)g_wgui_cat633_swflash_para_p->para[1], (kal_int8 *)g_wgui_cat633_cntx_p->dial_buffer_unicode);
    
#ifndef __MMI_MULTITAP_KEY_0__
	g_wgui_cat633_cntx_p->multitap_char = g_wgui_cat633_star_key_string;
#else
	g_wgui_cat633_cntx_p->multitap_char = g_wgui_cat633_zero_key_string;
#endif /* __MMI_MULTITAP_KEY_0__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat633_dial_init_swflash_para
 * DESCRIPTION
 *  Initial the parameter between motion dial and SWFlash engine
 * PARAMETERS
 *  BufferLength    [IN]    size of dial buffer(ansii) 
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat633_init_swflash_para(U32 BufferLength)
{	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    /* pre-process memory */
    if(g_wgui_cat633_swflash_para_p != NULL)
    {
        if(g_wgui_cat633_swflash_para_p->para != NULL)
        {
            for ( i=0; i<2; i++)
            {
                if(g_wgui_cat633_swflash_para_p->para[i] != NULL)
                {
                    OslMfree(g_wgui_cat633_swflash_para_p->para[i]);
		            g_wgui_cat633_swflash_para_p->para[i] = NULL;
                }
            }            
            OslMfree(g_wgui_cat633_swflash_para_p->para);
		    g_wgui_cat633_swflash_para_p->para = NULL;
        }
        OslMfree(g_wgui_cat633_swflash_para_p);
		g_wgui_cat633_swflash_para_p = NULL;
    }    

    /* allocate memory */
    g_wgui_cat633_swflash_para_p = (mdi_swflash_para*)OslMalloc(sizeof(mdi_swflash_para));
    MMI_ASSERT(g_wgui_cat633_swflash_para_p != NULL);
    memset(g_wgui_cat633_swflash_para_p, 0, sizeof(mdi_swflash_para));

    /* g_motion_dial_para:
     *      para[0]: style, "dialer", need 7 bytes      
     *      para[1]: ansii dial buffer      
     *      callback function: convert ansii to unicode
     */        
    g_wgui_cat633_swflash_para_p->callbackfunction = wgui_cat633_convert_ansii_buffer_to_unicode_buffer;
	g_wgui_cat633_swflash_para_p->num_of_para = 2;    

    g_wgui_cat633_swflash_para_p->para = (S8 **)OslMalloc(sizeof(S8*)*(g_wgui_cat633_swflash_para_p->num_of_para));
    MMI_ASSERT(g_wgui_cat633_swflash_para_p->para != NULL);
    memset(g_wgui_cat633_swflash_para_p->para, 0, sizeof(S8*)*(g_wgui_cat633_swflash_para_p->num_of_para));

    g_wgui_cat633_swflash_para_p->para[0] = (S8 *)OslMalloc(sizeof(S8)*7);
    MMI_ASSERT(g_wgui_cat633_swflash_para_p->para[0] != NULL);
	memset(g_wgui_cat633_swflash_para_p->para[0], 0, sizeof(S8)*7);
    strcpy(g_wgui_cat633_swflash_para_p->para[0], "dialer");
    
	g_wgui_cat633_swflash_para_p->para[1] = (S8 *)OslMalloc(sizeof(S8)*BufferLength);
    MMI_ASSERT(g_wgui_cat633_swflash_para_p->para[1] != NULL);
	memset(g_wgui_cat633_swflash_para_p->para[1], 0, sizeof(S8)*BufferLength);

    /* set mdi parameter */
    mdi_swflash_init_data(g_wgui_cat633_swflash_para_p);
    mdi_swflash_change_play_purpose(MDI_SWFLASH_PURPOSE_PLAYER);
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory633Screen
 * DESCRIPTION
 *  Displays the category633 screen(Motion Dialing Screen)
 * PARAMETERS
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the Left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  Buffer                  [IN]        Message string
 *  BufferLength            [IN]        Length of buffer
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory633Screen(
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        U8 *Buffer,
        U32 BufferLength,
        U8 *history_buffer)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S32 dial_length;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    /* init swflash para */
    wgui_cat633_init_swflash_para(BufferLength);    

    /* init dial context */
    wgui_cat633_init_cntx(Buffer, right_softkey, right_softkey_icon);

    /* lock layers */
    gdi_layer_lock_frame_buffer();

    /* set softkey */
    dm_add_softkey(left_softkey, left_softkey_icon, right_softkey, right_softkey_icon);  
    
    /*set key handler for interaction*/
    wgui_cat633_set_key_handler();   

    /* handle input */
    wgui_cat633_input_handle();

    /* first time to handle input */
    dial_length = strlen(g_wgui_cat633_swflash_para_p->para[1]);    
    if (dial_length <= 0)
    {
    #if defined(__MMI_WITH_C_KEY__)
        SetKeyHandler(wgui_cat633_clear_key_up_handler, KEY_CLEAR, KEY_EVENT_UP);
        if (g_wgui_cat633_empty_callback != NULL)
        {
            g_wgui_cat633_empty_callback();
        }
    #else /* defined(__MMI_WITH_C_KEY__) */ 
        set_right_softkey_function(wgui_cat633_clear_key_up_handler, KEY_EVENT_UP);
        if (g_wgui_cat633_empty_callback != NULL)
        {
            g_wgui_cat633_empty_callback();
        }
    #endif /* defined(__MMI_WITH_C_KEY__) */ 
    }
    else if (g_wgui_cat633_not_empty_callback != NULL)
    {
        g_wgui_cat633_not_empty_callback();
    }    
    
    /* let the status bar and button bar to be transparent */
    wgui_set_wallpaper_on_bottom(MMI_TRUE);
    wgui_softkey_set_filler_disabled(MMI_TRUE);

	gdi_layer_get_base_handle(&wgui_base_layer);
	wgui_status_icon_set_display_layer(wgui_base_layer);

    /* CONTROLLED_AREA */
    dm_register_category_controlled_callback(wgui_cat633_draw_controlled_area);

    /* set redraw function, history function */
    dm_setup_category_functions(dm_redraw_category_screen, dummy_get_history, dummy_get_history_size);   
    ExitCategoryFunction = ExitCategory633Screen; 

    /* unlock */
    gdi_layer_unlock_frame_buffer(); 

    /* set draw manager data */
    dm_data.s32CatId = MMI_CATEGORY633_ID;
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND | DM_SET_AS_ABM_LAYER;
    dm_setup_data(&dm_data);

    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory633Screen
 * DESCRIPTION
 *  Exits the category633 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory633Screen(void)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    gui_cancel_timer(wgui_cat633_complete_multitap);

    /* stop playback */
    mdi_swflash_stop();
    
    /*free SWFlash content*/
    mdi_swflash_close_id();
    
    mdi_swflash_change_play_purpose(MDI_SWFLASH_PURPOSE_PLAYER);

    /* free key suspending */
    mmi_suspend_handle_key_process(MMI_FALSE);    

    /* free motion dial parameter */
    if(g_wgui_cat633_swflash_para_p != NULL)
    {
        if(g_wgui_cat633_swflash_para_p->para != NULL)
        {
            for (i=g_wgui_cat633_swflash_para_p->num_of_para-1; i>=0; i--)
            {
                if(g_wgui_cat633_swflash_para_p->para[i] != NULL)
                {
                    OslMfree(g_wgui_cat633_swflash_para_p->para[i]);
		            g_wgui_cat633_swflash_para_p->para[i] = NULL;
                }
            }
            OslMfree(g_wgui_cat633_swflash_para_p->para);
		    g_wgui_cat633_swflash_para_p->para = NULL;
        }
        OslMfree(g_wgui_cat633_swflash_para_p);
		g_wgui_cat633_swflash_para_p = NULL;
    }    

    /* free motion dial context */
    if(g_wgui_cat633_cntx_p != NULL)
    {
        OslMfree(g_wgui_cat633_cntx_p);
		g_wgui_cat633_cntx_p = NULL;
    }    

    /* set function pointer */
    g_wgui_cat633_RSK_function = NULL;
    g_wgui_cat633_not_empty_callback = NULL;
    g_wgui_cat633_empty_callback = NULL;
    wgui_status_icon_reset_display_layer();
}
#endif /* __MMI_MOTION_DIAL__  */


/*****************************************************************************
 * FUNCTION
 *  wgui_multitap_0_long_press_key_handler
 * DESCRIPTION
 *  the long press key handler of KEY_0 when __MMI_MULTITAP_KEY_0__ is defined
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat016_multitap_0_long_press_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Cod e Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_ANIMATED_DIAL__
    wgui_anim_dial_multitap_key_down();
    #elif defined(__MMI_MOTION_DIAL__)
    wgui_cat633_multitap_key_handler();
    #else 
    dialer_inputbox_handle_zero_key_long_press();
    #endif  
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat16_register_not_empty_function
 * DESCRIPTION
 *  register not empty function
 * PARAMETERS
 *  f       [IN]        not empty function pointer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat016_register_not_empty_function(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MOTION_DIAL__)
    wgui_cat633_register_not_empty_function(f);
#elif defined(__MMI_ANIMATED_DIAL__)
    wgui_anim_dial_register_not_empty_function(f);
#else /* defined(__MMI_MOTION_DIAL__) */
    RegisterInputBoxNotEmptyFunction(f);
#endif /* defined(__MMI_MOTION_DIAL__) */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat016_register_empty_function
 * DESCRIPTION
 *  register empty function
 * PARAMETERS
 *  f       [IN]       empty function pointer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat016_register_empty_function(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MOTION_DIAL__)
    wgui_cat633_register_empty_function(f);
#elif defined(__MMI_ANIMATED_DIAL__)
    wgui_anim_dial_register_empty_function(f);
#else /* defined(__MMI_MOTION_DIAL__) */
    RegisterInputBoxEmptyFunction(f);
#endif /* defined(__MMI_MOTION_DIAL__) */
}


