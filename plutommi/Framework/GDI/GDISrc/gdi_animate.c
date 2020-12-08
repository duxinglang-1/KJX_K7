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
 *	 gdi_animate.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI animate handler
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "gdi_internal.h"
#include "mmi_frm_gprot.h"
#include "FileMgrSrvGProt.h"

#ifdef GDI_USING_TV_OUTPUT
	#include "mdi_datatype.h"
	#include "mdi_tv.h"
#endif

#include "kal_general_types.h"
#include "kal_release.h"
#include "fs_type.h"
#include "lcd_if.h"
#include "drv_sw_features_display.h"
#include "Unicodexdcl.h"
#include "MMIDataType.h"
#include "mmi_frm_timer_gprot.h"

#include "gdi_animate.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "gdi_mutex.h"
#include "gdi_primitive.h"
#include "gdi_image.h"
#include "gdi_features.h"
#include "gdi_layer.h"


typedef struct
{
    LOCAL_PARA_HDR

    kal_int32 timer_id;
    kal_int32 anim_index;
    kal_int32 serial_id;
    kal_uint32 delay_in_ms;
    void (*expiry_callback)(void *user_data);
    void *user_data;
} gdi_anim_start_timer_param_struct;

typedef struct
{
    LOCAL_PARA_HDR

    kal_int32 timer_id;
    kal_int32 anim_index;
    kal_int32 serial_id;
} gdi_anim_stop_timer_param_struct;

typedef struct
{
    LOCAL_PARA_HDR
    
    kal_int32 anim_index;
    kal_int32 serial_id;
} gdi_anim_callback_ind_struct;



/****************************************************************************
* Local Variable
*****************************************************************************/
static gdi_anim_cntx_struct 	GDI_ANIM;
static U16				gdi_anim_filename[GDI_ANIM_COUNT][SRV_FMGR_PATH_MAX_LEN + 1];
static U32 				gdi_anim_serial;
static U32 				gdi_anim_delay_time;
static U32 				gdi_anim_frame_delay_time;
static U32              gdi_anim_min_delay_time;
static BOOL             gdi_anim_enable_min_delay_time;
static S32              gdi_anim_current_anim_index = -1;


static void gdi_anim_callback_ind_mmi_handler(void *msg);


void gdi_anim_init(void)
{
	int i;
	
	// init animation structure
	for(i = 0; i < GDI_ANIM_COUNT; i++)
	{
		GDI_ANIM.anim_list[i].is_used			= GDI_ANIM_FLAG_IS_FREE;
	}
	gdi_anim_serial = 0;
    GDI_ANIM.disable_blt = MMI_FALSE;
    GDI_ANIM.anim_count  = -1;
}


static void gdi_anim_start_mmi_timer(
    kal_int32 timer_id,
    kal_int32 anim_index,
    kal_uint32 delay_in_ms,
    void (*expiry_callback)(void *user_data),
    void *user_data)
{
    module_type current_mod = kal_get_active_module_id();

    if (current_mod != MOD_MMI)
    {
        gdi_anim_start_timer_param_struct *param;
        ilm_struct *ilm_ptr;

        param = (gdi_anim_start_timer_param_struct*)
            construct_local_para(sizeof(gdi_anim_start_timer_param_struct), TD_CTRL);

        param->timer_id = timer_id;
        param->anim_index = anim_index;
        param->serial_id = GDI_ANIM.anim_list[anim_index].serial_id;
        param->delay_in_ms = delay_in_ms;
        param->expiry_callback = expiry_callback;
        param->user_data = user_data;
        
        ilm_ptr = allocate_ilm(current_mod);
        ilm_ptr->src_mod_id = current_mod;
        ilm_ptr->dest_mod_id = MOD_MMI;
        ilm_ptr->sap_id = GDC_SAP;

        ilm_ptr->msg_id = (msg_type)MSG_ID_MMI_GDI_ANIM_START_TIMER_IND;
        ilm_ptr->local_para_ptr = (local_para_struct*)param;
        ilm_ptr->peer_buff_ptr = NULL;

        msg_send_ext_queue(ilm_ptr);
    }
    else /* In MMI */
    {
        StartNonAlignTimerEx(
            timer_id,
            delay_in_ms,
            expiry_callback,
            user_data);
    }
}


static void gdi_anim_start_timer_mmi_handler(void *msg)
{
    gdi_anim_start_timer_param_struct *param =
        (gdi_anim_start_timer_param_struct*)msg;

    GDI_ENTER_CRITICAL_SECTION(gdi_anim_start_timer_mmi_handler)

    if (GDI_ANIM.anim_list[param->anim_index].is_used != GDI_ANIM_FLAG_IS_FREE &&
        GDI_ANIM.anim_list[param->anim_index].serial_id == param->serial_id)
    {
        StartNonAlignTimerEx(
            param->timer_id,
            param->delay_in_ms,
            param->expiry_callback,
            param->user_data);
    }

    GDI_EXIT_CRITICAL_SECTION(gdi_anim_start_timer_mmi_handler)
}


static void gdi_anim_stop_mmi_timer(kal_int32 timer_id, kal_int32 anim_index)
{
    module_type current_mod = kal_get_active_module_id();

    if (current_mod != MOD_MMI)
    {
        gdi_anim_stop_timer_param_struct *param;
        ilm_struct *ilm_ptr;

        param = (gdi_anim_stop_timer_param_struct*)
            construct_local_para(sizeof(gdi_anim_stop_timer_param_struct), TD_CTRL);

        param->timer_id = timer_id;
        param->anim_index = anim_index;
        param->serial_id = GDI_ANIM.anim_list[anim_index].serial_id;
        
        ilm_ptr = allocate_ilm(current_mod);
        ilm_ptr->src_mod_id = current_mod;
        ilm_ptr->dest_mod_id = MOD_MMI;
        ilm_ptr->sap_id = GDC_SAP;

        ilm_ptr->msg_id = (msg_type)MSG_ID_MMI_GDI_ANIM_STOP_TIMER_IND;
        ilm_ptr->local_para_ptr = (local_para_struct*)param;
        ilm_ptr->peer_buff_ptr = NULL;

        msg_send_ext_queue(ilm_ptr);
    }
    else /* In MMI */
    {
        StopTimer(timer_id);
    }
}


static void gdi_anim_stop_timer_mmi_handler(void *msg)
{
    gdi_anim_stop_timer_param_struct *param =
        (gdi_anim_stop_timer_param_struct*)msg;

    GDI_ENTER_CRITICAL_SECTION(gdi_anim_stop_timer_mmi_handler)
    if (GDI_ANIM.anim_list[param->anim_index].serial_id == param->serial_id)
    {
        StopTimer(param->timer_id);
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_anim_stop_timer_mmi_handler)
}


static void gdi_anim_mmi_register_handlers(void)
{
    SetProtocolEventHandler(gdi_anim_start_timer_mmi_handler, MSG_ID_MMI_GDI_ANIM_START_TIMER_IND);
    SetProtocolEventHandler(gdi_anim_stop_timer_mmi_handler, MSG_ID_MMI_GDI_ANIM_STOP_TIMER_IND);
    SetProtocolEventHandler(gdi_anim_callback_ind_mmi_handler, MSG_ID_MMI_GDI_ANIM_CALLBACK_IND);
}


void gdi_anim_mmi_init(void)
{
    gdi_anim_mmi_register_handlers();
}


mmi_ret gdi_anim_on_protocol_handler_reset(mmi_event_struct *evt)
{
    gdi_anim_mmi_register_handlers();

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_anim_get_min_delay_time
 * DESCRIPTION
 *  get anim min delay time
 * PARAMETERS
 *  enable_min_delay_time   [OUT]   enable min delay time
 *  min_delay_time          [OUT]   min delay time
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_anim_get_min_delay_time(BOOL *enable_min_delay_time, U32 *min_delay_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    GDI_ENTER_CRITICAL_SECTION(gdi_anim_get_min_delay_time)
    *enable_min_delay_time = gdi_anim_enable_min_delay_time;
    *min_delay_time = gdi_anim_min_delay_time;
    GDI_EXIT_CRITICAL_SECTION(gdi_anim_get_min_delay_time)	
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_anim_set_min_delay_time
 * DESCRIPTION
 *  set anim min delay time
 * PARAMETERS
 *  min_delay_time          [IN]    min delay time
 *  enable_min_delay_time   [IN]    enable min delay time
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_anim_set_min_delay_time(BOOL enable_min_delay_time, U32 min_delay_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	GDI_ENTER_CRITICAL_SECTION(gdi_anim_set_min_delay_time)	
	if( min_delay_time==0) 
    {
        min_delay_time=1;
    }
    gdi_anim_enable_min_delay_time = enable_min_delay_time;
	gdi_anim_min_delay_time = min_delay_time;
	GDI_EXIT_CRITICAL_SECTION(gdi_anim_set_min_delay_time)	
	return GDI_SUCCEED;
}



U32 gdi_anim_get_delay(void)
{
	return gdi_anim_delay_time;
}

void gdi_anim_set_delay(U32 delay)
{
	GDI_ENTER_CRITICAL_SECTION(gdi_anim_get_delay)	
		if(delay==0) delay=1;
		gdi_anim_delay_time = delay;
	GDI_EXIT_CRITICAL_SECTION(gdi_anim_get_delay)	
}


U32 gdi_anim_get_frame_delay(void)
{
	return gdi_anim_frame_delay_time;
}


void gdi_anim_set_frame_delay(U32 delay)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_anim_set_frame_delay)
    gdi_anim_frame_delay_time = delay;
	gdi_anim_set_delay(delay);
	GDI_EXIT_CRITICAL_SECTION(gdi_anim_set_frame_delay)
}


static GDI_RESULT gdi_anim_stop_internal(gdi_handle a_handle)
{
	GDI_ENTER_CRITICAL_SECTION(gdi_anim_stop_internal)	
		
		if(GDI_ANIM.anim_list[a_handle].is_used==GDI_ANIM_FLAG_IS_FREE)
			GDI_RETURN(GDI_FAILED);

		GDI_ANIM.anim_list[a_handle].is_used	= GDI_ANIM_FLAG_IS_FREE;

		gdi_anim_stop_mmi_timer(GDI_TIMER_ANIM_BASE + a_handle, a_handle);

		if(gdi_image_codecs[GDI_ANIM.anim_list[a_handle].image_identifier].draw_after)
			gdi_image_codecs[GDI_ANIM.anim_list[a_handle].image_identifier].draw_after(
					0,
					GDI_ANIM.anim_list[a_handle].frame_index,
					GDI_ANIM.anim_list[a_handle].offset_x,
					GDI_ANIM.anim_list[a_handle].offset_y,
					GDI_ANIM.anim_list[a_handle].resized_width,
					GDI_ANIM.anim_list[a_handle].resized_height,
					GDI_ANIM.anim_list[a_handle].image_ptr,
					GDI_ANIM.anim_list[a_handle].image_length);
	
	GDI_EXIT_CRITICAL_SECTION(gdi_anim_stop_internal)
    return GDI_SUCCEED;

}


static void gdi_anim_post_callback(kal_int32 anim_index)
{
    gdi_anim_callback_ind_struct *ind;
    ilm_struct *ilm_ptr;
    module_type current_mod = kal_get_active_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind = (gdi_anim_callback_ind_struct*)
        construct_local_para(sizeof(gdi_anim_callback_ind_struct), TD_CTRL);

    ind->anim_index = anim_index;
    ind->serial_id = GDI_ANIM.anim_list[anim_index].serial_id;
    
    ilm_ptr = allocate_ilm(current_mod);
    ilm_ptr->src_mod_id = current_mod;
    ilm_ptr->dest_mod_id = MOD_MMI;
    ilm_ptr->sap_id = GDC_SAP;

    ilm_ptr->msg_id = (msg_type)MSG_ID_MMI_GDI_ANIM_CALLBACK_IND;
    ilm_ptr->local_para_ptr = (local_para_struct*)ind;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);
}


static void gdi_anim_callback_ind_mmi_handler(void *msg)
{
    gdi_anim_callback_ind_struct *ind = (gdi_anim_callback_ind_struct*)msg;

    S32 index = ind->anim_index;
    GDI_LOCK;

    if (GDI_ANIM.anim_list[index].is_used != GDI_ANIM_FLAG_IS_FREE &&
        GDI_ANIM.anim_list[index].serial_id == ind->serial_id)
    {
        if(GDI_ANIM.anim_list[index].callback)
        {
            U32 frames = GDI_ANIM.anim_list[index].frames;
            void (*callback)(GDI_RESULT result);

            callback = (GDI_ANIM.anim_list[index].callback);

            GDI_UNLOCK;
            /*
             *  CallBackPowerOnAnimationComplete is the done_callback of Power On Animation.
             *  It would call EntryNewScreen, and EntryNewScreen would wait Venus resuming (vrt_resume task) when using Venus MMI.
             *  But vrt_resume task would get GDI lock.
             *  So, it must unlock GDI_lock before calling animation done_callback.
             *  Otherwise, vrt will assert.
             */

            if(frames == 1)
                callback(GDI_IMAGE_IS_STILL_IMAGE);
            else
                callback(GDI_ANIM.anim_list[index].result);

            GDI_LOCK;
        }

		if(GDI_ANIM.anim_list[index].is_used == GDI_ANIM_FLAG_IS_STOP_AFTER_CALLBACK)
            gdi_anim_stop_internal(index);
    }
    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_anim_set_frame_index_of_curr_anim
 * DESCRIPTION
 *  set the frame index of the current playing animation.
 *  This function only valid in gdi_anim_draw_internal_handler 
 *  and the functions called by gdi_anim_draw_internal_handler.
 *  Currently use by gif to retry sw decode frome first frame when get hw decode error.
 * PARAMETERS
 *  frame_index       [IN]  
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_anim_set_frame_index_of_curr_anim(U32 frame_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    GDI_ENTER_CRITICAL_SECTION(gdi_anim_set_frame_index_of_curr_anim)
    if (gdi_anim_current_anim_index < 0)
    {
        GDI_RETURN(GDI_FAILED);
    }
    GDI_ANIM.anim_list[gdi_anim_current_anim_index].frame_index = frame_index;
    GDI_EXIT_CRITICAL_SECTION(gdi_anim_set_frame_index_of_curr_anim);
    return GDI_SUCCEED;
}


static void gdi_anim_draw_internal_handler(void * arg)
{
	GDI_ENTER_CRITICAL_SECTION(gdi_anim_draw_internal_handler)
		gdi_handle a_handle;
		GDI_RESULT	ret = GDI_FAILED;
		gdi_handle	old_layer_handle;
		gdi_handle	old_lcd_handle;
		BOOL		stop_cyclic = FALSE;


		a_handle = ((S32)arg) - GDI_TIMER_ANIM_BASE;

		
		if (GDI_ANIM.anim_list[a_handle].is_used == GDI_ANIM_FLAG_IS_FREE)
		{
			GDI_RETURN_VOID;
		}

        gdi_anim_current_anim_index = (S32)a_handle;
        
		// push current LCD , and set to new LCD
		gdi_lcd_get_active(&old_lcd_handle);
		gdi_lcd_set_active(GDI_ANIM.anim_list[a_handle].lcd_handle);

		//push the current layer of the new LCD 
		gdi_layer_get_active(&old_layer_handle);
		
		#ifdef GDI_USING_TV_OUTPUT
		if (GDI_LCD->lcd_type == GDI_LCD_TYPE_TVOUT)
			gdi_layer_set_active(mdi_tvout_get_and_dupe_active_layer());
		else
		#endif
			gdi_layer_set_active(GDI_ANIM.anim_list[a_handle].layer_handle);

		gdi_layer_push_clip();
		gdi_layer_set_clip(	GDI_ANIM.anim_list[a_handle].clipx1,
							GDI_ANIM.anim_list[a_handle].clipy1,
							GDI_ANIM.anim_list[a_handle].clipx2,
							GDI_ANIM.anim_list[a_handle].clipy2);

		if(GDI_ANIM.anim_list[a_handle].draw_before_callback != NULL)
		{
			GDI_ANIM.anim_list[a_handle].draw_before_callback(GDI_SUCCEED);
		}
		// drawing
		{

			if (GDI_ANIM_POS_TYPE_TIME == GDI_ANIM.anim_list[a_handle].pos_type)
			{
				U32 current_time = 0;
				kal_get_time(&current_time);
				GDI_ANIM.anim_list[a_handle].frame_index = (U32)((current_time - GDI_ANIM.anim_list[a_handle].start_frame) * 4.615);
				gdi_anim_delay_time=1;
			}
            gdi_push_and_set_alpha_blending_source_layer(GDI_ANIM.anim_list[a_handle].src_layer_handle);
			ret = gdi_image_codec_draw(
							GDI_ANIM.anim_list[a_handle].src_type,
							GDI_ANIM.anim_list[a_handle].image_ptr, // image_ptr
							GDI_ANIM.anim_list[a_handle].image_identifier, // image_type
							GDI_ANIM.anim_list[a_handle].image_length, // img_size
							GDI_ANIM.anim_list[a_handle].offset_x,
							GDI_ANIM.anim_list[a_handle].offset_y,
							GDI_ANIM.anim_list[a_handle].resized_width,  // no resize is 0
							GDI_ANIM.anim_list[a_handle].resized_height,// no resize is 0
							GDI_ANIM.anim_list[a_handle].img_flag | GDI_IMAGE_CODEC_FLAG_IS_ANIMATION, // flag
							GDI_ANIM.anim_list[a_handle].frame_index);
            gdi_pop_and_restore_alpha_blending_source_layer();

			GDI_ANIM.anim_list[a_handle].result = ret; // remember this error code
		}
		if(GDI_ANIM.anim_list[a_handle].draw_after_callback != NULL)
		{
			GDI_ANIM.anim_list[a_handle].draw_after_callback(ret);
		}

		
		if(GDI_ANIM.anim_list[a_handle].blt_before_callback != NULL
		&& !(GDI_ANIM.anim_list[a_handle].img_flag & GDI_IMAGE_CODEC_FLAG_DISABLE_BLT))
		{
			GDI_ANIM.anim_list[a_handle].blt_before_callback(ret);
		}

        if(ret >= 0 && !(GDI_ANIM.anim_list[a_handle].img_flag & GDI_IMAGE_CODEC_FLAG_DISABLE_BLT)) // succeed , we should update the lcd
		{
			int lx,ly;
			lx = gdi_act_layer->offset_x;
			ly = gdi_act_layer->offset_y;
			
			#ifdef GDI_USING_TV_OUTPUT
			if (GDI_LCD->lcd_type == GDI_LCD_TYPE_TVOUT)
			{
				mdi_tvout_blt();
			}
			else
			#endif
			{
				int w,h;
				S32 repaint_x1, repaint_y1, repaint_x2, repaint_y2;

				if(GDI_ANIM.anim_list[a_handle].resized_width 
				&& GDI_ANIM.anim_list[a_handle].resized_height)
				{
					w = (int)GDI_ANIM.anim_list[a_handle].resized_width;
					h = (int)GDI_ANIM.anim_list[a_handle].resized_height;
				}
				else
				{
					w = (int)GDI_ANIM.anim_list[a_handle].width;
					h = (int)GDI_ANIM.anim_list[a_handle].height;
				}

                repaint_x1 = GDI_ANIM.anim_list[a_handle].offset_x;
                repaint_y1 = GDI_ANIM.anim_list[a_handle].offset_y;
                repaint_x2 = GDI_ANIM.anim_list[a_handle].offset_x + w - 1;
                repaint_y2 = GDI_ANIM.anim_list[a_handle].offset_y + h - 1;

                gdi_rotate_map_layer_to_lcd_region(
                    gdi_act_layer->rotate_value,
                    &repaint_x1,
                    &repaint_y1,
                    &repaint_x2,
                    &repaint_y2);
                    
                repaint_x1 += lx;
                repaint_y1 += ly;
                repaint_x2 += lx;
                repaint_y2 += ly;

                gdi_lcd_repaint(
                    repaint_x1,
                    repaint_y1,
                    repaint_x2,
                    repaint_y2);
			}
		}

        if(GDI_ANIM.anim_list[a_handle].blt_after_callback != NULL
        && !(GDI_ANIM.anim_list[a_handle].img_flag & GDI_IMAGE_CODEC_FLAG_DISABLE_BLT))
		{
			GDI_ANIM.anim_list[a_handle].blt_after_callback(ret);
		}

		gdi_layer_pop_clip(); // restore old clip
		gdi_layer_set_active(old_layer_handle); // restore layer of this new LCD
		gdi_lcd_set_active(old_lcd_handle); // restore to old LCD

		if(ret < 0)
		{
			if(GDI_ANIM.anim_list[a_handle].frame_index > 0
			&&  (  GDI_ANIM.anim_list[a_handle].frames == 0    // first time fail
			&& GDI_ANIM_POS_TYPE_TIME != GDI_ANIM.anim_list[a_handle].pos_type)) // or time base
			{
				GDI_ANIM.anim_list[a_handle].frames = GDI_ANIM.anim_list[a_handle].frame_index;
				gdi_anim_delay_time=1; // re try use very soon timer
				GDI_ANIM.anim_list[a_handle].frame_index --;
			}
			else // there is something wrong
			{
				stop_cyclic=TRUE;
                GDI_ANIM.anim_list[a_handle].frame_index --;

				if((GDI_ANIM.anim_list[a_handle].callback != NULL) &&
                   (ret != GDI_ERR_NB_ABORT))   /* don't call done-callback if it's force abort. */
				{
                    GDI_ANIM.anim_list[a_handle].is_used = GDI_ANIM_FLAG_IS_STOP_AFTER_CALLBACK;
                    gdi_anim_post_callback(a_handle);
				}
			}
		}

		if((GDI_ANIM.anim_list[a_handle].frame_index >= GDI_ANIM.anim_list[a_handle].frames-1) &&
           (GDI_ANIM.anim_list[a_handle].frame_index >= 0))
		{
			// if this animator has callback fucntion, the animator will be destroyed after calling the callback func
			if((GDI_ANIM.anim_list[a_handle].callback != NULL)
                && (GDI_ANIM_POS_TYPE_TIME != GDI_ANIM.anim_list[a_handle].pos_type))
			{
			    GDI_ANIM.anim_list[a_handle].result = GDI_SUCCEED;
			    gdi_anim_post_callback(a_handle);
			}
            if(GDI_ANIM.anim_list[a_handle].anim_count>0)
                GDI_ANIM.anim_list[a_handle].anim_count--;

			if(GDI_ANIM.anim_list[a_handle].anim_count == 0 // play count is run out
			|| ((GDI_ANIM.anim_list[a_handle].frames == 1) && (ret >= GDI_SUCCEED ))) // still image
	 		{
                if(GDI_ANIM.anim_list[a_handle].callback != NULL)
				    GDI_ANIM.anim_list[a_handle].is_used = GDI_ANIM_FLAG_IS_STOP_AFTER_CALLBACK;
				stop_cyclic = TRUE;	// stop cyclic playing
			}
			else
			{
				if (GDI_ANIM.anim_list[a_handle].frames && (0 != (GDI_ANIM.anim_list[a_handle].frame_index + 1)))
				{
                    GDI_ANIM.anim_list[a_handle].frame_index = 0;
				    if (GDI_ANIM_POS_TYPE_TIME == GDI_ANIM.anim_list[a_handle].pos_type)
				    {
					    U32 current_time = 0;
					    kal_get_time(&current_time);
					    GDI_ANIM.anim_list[a_handle].start_frame		= current_time;
				    }
				}
				else
				{
				    GDI_ANIM.anim_list[a_handle].frame_index		= 0;
				}
			}
		}
		else
		{
			GDI_ANIM.anim_list[a_handle].frame_index++;
		}

		if(stop_cyclic)
		{
			if(GDI_ANIM.anim_list[a_handle].is_used == GDI_ANIM_FLAG_IS_ANIMATING)
				gdi_anim_stop_internal(a_handle); // and no callback will destory 
		}
		else
		{
            /* if delay_time is less than min_delay_time, use the min_delay_time */
            if (gdi_anim_enable_min_delay_time && 
                (gdi_anim_delay_time < gdi_anim_min_delay_time))
            {
                gdi_anim_delay_time = gdi_anim_min_delay_time;
            }
            GDI_ANIM.anim_list[a_handle].delay = gdi_anim_delay_time;
            gdi_anim_start_mmi_timer(
                (kal_int32)(GDI_TIMER_ANIM_BASE + a_handle),
                a_handle,
                gdi_anim_delay_time,
                gdi_anim_draw_internal_handler,
                (void*)(GDI_TIMER_ANIM_BASE + a_handle));
		}
        gdi_anim_current_anim_index = -1;

	GDI_EXIT_CRITICAL_SECTION(gdi_anim_draw_internal_handler)
}

GDI_RESULT gdi_anim_codec_draw_internal(
						gdi_image_src_enum src_type,
						U8* img_src,U8 img_type,S32 img_size,
						S32 x,S32 y,S32 w,S32 h,U32 flag,
						gdi_handle * handle_ptr,
						U32 frame_pos, S32 anim_count)
{
    GDI_RESULT ret;
    U8* data_ptr;
    const gdi_image_codecs_struct *codec;
    void	(*callback)(GDI_RESULT result);
    void	(*draw_before_callback)(GDI_RESULT result);
    void	(*draw_after_callback)(GDI_RESULT result);        
    void	(*blt_before_callback)(GDI_RESULT result);
    void	(*blt_after_callback)(GDI_RESULT result);
    S32 width,height,frame_number;

	GDI_ENTER_CRITICAL_SECTION(gdi_anim_codec_draw_internal)

        flag |= gdi_image_codec_get_flag();
		// clean the global callback variable
		callback = GDI_ANIM.anim_callback;
		GDI_ANIM.anim_callback = NULL; 

		draw_before_callback = GDI_ANIM.anim_draw_before_callback;
		GDI_ANIM.anim_draw_before_callback = NULL; 

		draw_after_callback = GDI_ANIM.anim_draw_after_callback;
		GDI_ANIM.anim_draw_after_callback = NULL; 

		blt_before_callback = GDI_ANIM.anim_blt_before_callback;
		GDI_ANIM.anim_blt_before_callback = NULL; 

		blt_after_callback = GDI_ANIM.anim_blt_after_callback;
		GDI_ANIM.anim_blt_after_callback = NULL; 

        if(anim_count<0) anim_count = GDI_ANIM.anim_count;
        GDI_ANIM.anim_count = -1;

		// initialize the return handle
		if(handle_ptr != NULL)
			*handle_ptr = GDI_ERROR_HANDLE;
		
		// parsing the image header/information
		ret = gdi_image_parse_info(src_type,img_src,&data_ptr,&img_type,&img_size,&frame_number,&width,&height);
		if(ret != GDI_SUCCEED) GDI_RETURN(ret);
		
		if(GDI_IMAGE_TYPE_INVALID == img_type || img_type >= GDI_IMAGE_TYPE_SUM)
			GDI_RETURN(GDI_IMAGE_ERR_INVALID_IMG_TYPE);

		codec = &gdi_image_codecs[img_type];
		if(src_type == GDI_IMAGE_SRC_FROM_FILE)
			flag |= GDI_IMAGE_CODEC_FLAG_IS_FILE;
        else if(src_type == GDI_IMAGE_SRC_FROM_MEMORY)
            flag |= GDI_IMAGE_CODEC_FLAG_IS_MEM;

        
		if(!codec->is_animation)  // is still image
		{
    		if(draw_before_callback) draw_before_callback(GDI_SUCCEED);
            
			ret = gdi_image_codec_draw(
							src_type,
							img_src,img_type,img_size,
							x,y,w,h,flag,frame_pos);
			
    		if(draw_after_callback) draw_after_callback(ret);
			
			if(ret == GDI_SUCCEED) ret = GDI_IMAGE_IS_STILL_IMAGE;
		}
		else // is animation
		{
			if(width == -1 || height == -1)
			    ret = gdi_image_codec_get_dimension(
							src_type,
							img_src,img_type,img_size,
							&width,&height,flag);
			if(ret==GDI_SUCCEED)
			{
				int i;
				for(i = 0 ; i < GDI_ANIM_COUNT ; i++)
				if(GDI_ANIM.anim_list[i].is_used == GDI_ANIM_FLAG_IS_FREE)
				{
					gdi_anim_serial++;
					GDI_ANIM.anim_list[i].is_used  = GDI_ANIM_FLAG_IS_ANIMATING;
					GDI_ANIM.anim_list[i].serial_id = gdi_anim_serial*GDI_ANIM_COUNT + i;
                    GDI_ANIM.anim_list[i].job_handle = 0;
					GDI_ANIM.anim_list[i].src_type = src_type;
					if(GDI_ANIM.anim_list[i].src_type == GDI_IMAGE_SRC_FROM_FILE)
					{
						GDI_ANIM.anim_list[i].image_ptr		= (U8*)gdi_anim_filename[i];
						mmi_ucs2ncpy((PS8)GDI_ANIM.anim_list[i].image_ptr, (PS8)img_src, SRV_FMGR_PATH_MAX_LEN);
					}
					else
						GDI_ANIM.anim_list[i].image_ptr		= img_src;

					GDI_ANIM.anim_list[i].img_flag			= flag;
					GDI_ANIM.anim_list[i].start_frame		= frame_pos;
					GDI_ANIM.anim_list[i].frame_index		= frame_pos;
					GDI_ANIM.anim_list[i].frames			= 0;
					GDI_ANIM.anim_list[i].offset_x			= x;
					GDI_ANIM.anim_list[i].offset_y			= y;
					GDI_ANIM.anim_list[i].width				= width;
					GDI_ANIM.anim_list[i].height			= height;
					GDI_ANIM.anim_list[i].image_length		= img_size;
					GDI_ANIM.anim_list[i].layer_handle		= (gdi_handle)gdi_act_layer;
					GDI_ANIM.anim_list[i].lcd_handle		= GDI_LCD->act_handle;
					GDI_ANIM.anim_list[i].clipx1			= GDI_LAYER.clipx1;
					GDI_ANIM.anim_list[i].clipy1			= GDI_LAYER.clipy1;
					GDI_ANIM.anim_list[i].clipx2			= GDI_LAYER.clipx2;
					GDI_ANIM.anim_list[i].clipy2			= GDI_LAYER.clipy2;
					GDI_ANIM.anim_list[i].image_identifier	= img_type;
					GDI_ANIM.anim_list[i].callback			= callback;
					GDI_ANIM.anim_list[i].draw_before_callback		= draw_before_callback;
					GDI_ANIM.anim_list[i].draw_after_callback		    = draw_after_callback;
					GDI_ANIM.anim_list[i].blt_before_callback			= blt_before_callback;
					GDI_ANIM.anim_list[i].blt_after_callback			= blt_after_callback;
					GDI_ANIM.anim_list[i].anim_count 		= anim_count;
					GDI_ANIM.anim_list[i].resized_width		= w;
					GDI_ANIM.anim_list[i].resized_height	= h;
					GDI_ANIM.anim_list[i].pos_type		    = GDI_ANIM_POS_TYPE_INDEX;
					GDI_ANIM.anim_list[i].delay             = 1;
					GDI_ANIM.anim_list[i].is_pause          = 0;
                    GDI_ANIM.anim_list[i].retry_count       = 0;

                    gdi_get_alpha_blending_source_layer(&(GDI_ANIM.anim_list[i].src_layer_handle));

                    GDI_DEBUG_ASSERT(codec->get_pos_info); // is_animation codec must have pos_info callback
					ret = codec->get_pos_info(flag,data_ptr,img_size,TRUE, (S32*)&(GDI_ANIM.anim_list[i].frames),&(GDI_ANIM.anim_list[i].pos_type));
					if (GDI_ANIM_POS_TYPE_TIME == GDI_ANIM.anim_list[i].pos_type)
					{
						U32 current_time = 0;
						kal_get_time(&current_time);
						GDI_ANIM.anim_list[i].start_frame		= current_time;
						GDI_ANIM.anim_list[i].frame_index		= current_time;
                        if (ret)
                        {
                            break;
                        }
					}

					// start animation cyclic
					gdi_layer_lock_frame_buffer();
						
						// first frame don't need blt
    					GDI_ANIM.anim_list[i].img_flag |= GDI_IMAGE_CODEC_FLAG_DISABLE_BLT;
    					
						// first frame need draw_before(), draw()
						GDI_ANIM.anim_list[i].img_flag		|=GDI_IMAGE_CODEC_FLAG_DISABLE_DRAW_AFTER;
						
						gdi_anim_draw_internal_handler((void*)(i + GDI_TIMER_ANIM_BASE));
						
						// then frames only need draw()
						GDI_ANIM.anim_list[i].img_flag		|=GDI_IMAGE_CODEC_FLAG_DISABLE_DRAW_BEFORE;
						
                        // set disable blt flag if need.
                        if (!GDI_ANIM.disable_blt)
                            GDI_ANIM.anim_list[i].img_flag &= ~GDI_IMAGE_CODEC_FLAG_DISABLE_BLT;
						
					gdi_layer_unlock_frame_buffer();

					// if this image is animation, frame_index should be start_frame+1
                    if (0 == GDI_ANIM.anim_list[i].frame_index && 1 != GDI_ANIM.anim_list[i].frames)
                    {
                        ret = GDI_ANIM.anim_list[i].result;
                    }
					else if(GDI_ANIM.anim_list[i].frame_index==frame_pos) 
						ret = GDI_IMAGE_IS_STILL_IMAGE;
					else
					{
						if(handle_ptr != NULL)
							*handle_ptr = (gdi_handle)GDI_ANIM.anim_list[i].serial_id;
						ret = GDI_SUCCEED;
					}
					break;
				}
			}
		}
        GDI_ANIM.disable_blt = MMI_FALSE;
        if(ret < GDI_SUCCEED && gdi_image_is_abort()) 
            ret = GDI_ERR_NB_ABORT;
	GDI_EXIT_CRITICAL_SECTION(gdi_anim_codec_draw_internal)
    return ret;
}


S32 gdi_anim_get_current_frame_number(gdi_handle serial_handle)
{
    S32 ret = -1;

	GDI_ENTER_CRITICAL_SECTION(gdi_anim_get_current_frame_number)
	{
		U32 a_handle = serial_handle % GDI_ANIM_COUNT;
		if(  GDI_ANIM.anim_list[a_handle].is_used != GDI_ANIM_FLAG_IS_FREE
		&&  GDI_ANIM.anim_list[a_handle].serial_id == serial_handle)
		    ret = GDI_ANIM.anim_list[a_handle].frame_index;
	}
	GDI_EXIT_CRITICAL_SECTION(gdi_anim_get_current_frame_number)

    return ret;
}

/**************************************************************

	FUNCTION NAME		: gdi_image_stop_animation_all

  	PURPOSE				: stop all animation

	INPUT PARAMETERS	: void

	OUTPUT PARAMETERS	: nil

	RETURNS				: GDI_RESULT

	REMARKS				: nil

***************************************************************/
GDI_RESULT gdi_anim_stop_all(void)
{
	GDI_ENTER_CRITICAL_SECTION(gdi_image_stop_animation_all)
		gdi_handle act_lcd_handle;
		int index;

		// get current active lcd
		gdi_lcd_get_active(&act_lcd_handle);
		for(index = 0;index < GDI_ANIM_COUNT;index++)
		{
			if(GDI_ANIM.anim_list[index].is_used != GDI_ANIM_FLAG_IS_FREE)
			{
				if(GDI_ANIM.anim_list[index].lcd_handle == act_lcd_handle)
					gdi_anim_stop_internal(index);
			}
		}
	GDI_EXIT_CRITICAL_SECTION(gdi_image_stop_animation_all)
    return GDI_SUCCEED;
}

/**************************************************************

	FUNCTION NAME		: gdi_anim_stop_by_layer

  	PURPOSE				: stop all animation in spec layer

	INPUT PARAMETERS	: layer

	OUTPUT PARAMETERS	: nil

	RETURNS				: GDI_RESULT

	REMARKS				: nil

***************************************************************/
GDI_RESULT gdi_anim_stop_all_by_layer(gdi_handle layer)
{
	GDI_ENTER_CRITICAL_SECTION(gdi_anim_stop_all_by_layer)
		int index;

		for(index = 0;index < GDI_ANIM_COUNT;index++)
		{
			if(GDI_ANIM.anim_list[index].is_used != GDI_ANIM_FLAG_IS_FREE)
			{
				if(GDI_ANIM.anim_list[index].layer_handle == layer)
					gdi_anim_stop_internal(index);
			}
		}
	GDI_EXIT_CRITICAL_SECTION(gdi_anim_stop_all_by_layer)
    return GDI_SUCCEED;
}


/**************************************************************

	FUNCTION NAME		: gdi_image_stop_animation

  	PURPOSE				: stop a animation by handle

	INPUT PARAMETERS	: void

	OUTPUT PARAMETERS	: nil

	RETURNS				: GDI_RESULT

	REMARKS				: nil

***************************************************************/
GDI_RESULT gdi_anim_stop(gdi_handle serial_handle)
{
    gdi_result ret;
	GDI_ENTER_CRITICAL_SECTION(gdi_anim_stop)
		
		U32 a_handle = serial_handle % GDI_ANIM_COUNT;
		if(  GDI_ANIM.anim_list[a_handle].is_used != GDI_ANIM_FLAG_IS_FREE
		&&  GDI_ANIM.anim_list[a_handle].serial_id == serial_handle)
			ret = gdi_anim_stop_internal(a_handle);
		else
			ret = GDI_FAILED;
		
	GDI_EXIT_CRITICAL_SECTION(gdi_anim_stop)
    return ret;
}

static GDI_RESULT gdi_anim_set_callback(
                                        void (*last_frame_callback_ptr)(GDI_RESULT result), 
                                        void (*draw_before_callback_ptr)(GDI_RESULT result), 
                                        void (*draw_after_callback_ptr)(GDI_RESULT result),                                        
                                        void (*blt_before_callback_ptr)(GDI_RESULT result), 
                                        void (*blt_after_callback_ptr)(GDI_RESULT result))
{
	GDI_ENTER_CRITICAL_SECTION(gdi_anim_set_callback)
        if(last_frame_callback_ptr) GDI_ANIM.anim_callback = last_frame_callback_ptr;
		if(draw_before_callback_ptr)GDI_ANIM.anim_draw_before_callback = draw_before_callback_ptr;
		if(draw_after_callback_ptr) GDI_ANIM.anim_draw_after_callback = draw_after_callback_ptr;
		if(blt_before_callback_ptr) GDI_ANIM.anim_blt_before_callback = blt_before_callback_ptr;
		if(blt_after_callback_ptr)  GDI_ANIM.anim_blt_after_callback = blt_after_callback_ptr;
	GDI_EXIT_CRITICAL_SECTION(gdi_anim_set_callback)
    return GDI_SUCCEED;
}



GDI_RESULT gdi_anim_set_last_frame_callback(void (*callback_ptr)(GDI_RESULT result))
{
    return gdi_anim_set_callback(callback_ptr, NULL, NULL,NULL, NULL);
}

GDI_RESULT gdi_anim_set_draw_before_callback(void (*callback_ptr)(GDI_RESULT result))
{
    return gdi_anim_set_callback(NULL,callback_ptr, NULL, NULL,NULL);
}

GDI_RESULT gdi_anim_set_draw_after_callback(void (*callback_ptr)(GDI_RESULT result))
{
    return gdi_anim_set_callback(NULL,NULL,callback_ptr, NULL,NULL);
}

GDI_RESULT gdi_anim_set_blt_before_callback(void (*callback_ptr)(GDI_RESULT result))
{
    return gdi_anim_set_callback(NULL, NULL, NULL,callback_ptr, NULL);
}

GDI_RESULT gdi_anim_set_blt_after_callback(void (*callback_ptr)(GDI_RESULT result))
{
    return gdi_anim_set_callback(NULL, NULL, NULL,NULL, callback_ptr);
}

GDI_RESULT gdi_anim_set_disable_blt(void)
{
	GDI_ENTER_CRITICAL_SECTION(gdi_anim_set_last_frame_callback)
        GDI_ANIM.disable_blt = MMI_TRUE;
	GDI_EXIT_CRITICAL_SECTION(gdi_anim_set_last_frame_callback)
    return GDI_SUCCEED;
}

GDI_RESULT gdi_anim_set_nb_job_handle(gdi_handle anim_handle,gdi_handle job_handle)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_anim_set_nb_job_handle)
		U32 a_handle = anim_handle % GDI_ANIM_COUNT;
		if(GDI_ANIM.anim_list[a_handle].is_used != GDI_ANIM_FLAG_IS_FREE)
		{
            GDI_ANIM.anim_list[a_handle].job_handle = job_handle;
		}
    GDI_EXIT_CRITICAL_SECTION(gdi_anim_set_nb_job_handle)
    return GDI_SUCCEED;
}

GDI_RESULT gdi_anim_stop_by_job_handle(gdi_handle job_handle)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_anim_stop_by_job_handle)
		int index;

		for(index = 0;index < GDI_ANIM_COUNT;index++)
		{
			if(GDI_ANIM.anim_list[index].is_used != GDI_ANIM_FLAG_IS_FREE)
			{
				if(GDI_ANIM.anim_list[index].job_handle == job_handle)
					gdi_anim_stop_internal(index);
			}
		}
    GDI_EXIT_CRITICAL_SECTION(gdi_anim_stop_by_job_handle)
    return GDI_SUCCEED;
}

GDI_RESULT gdi_anim_stop_by_all_job_handle(void)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_anim_stop_by_all_job_handle)
		int index;

		for(index = 0;index < GDI_ANIM_COUNT;index++)
		{
			if(GDI_ANIM.anim_list[index].is_used != GDI_ANIM_FLAG_IS_FREE)
			{
				if(GDI_ANIM.anim_list[index].job_handle!=0)
					gdi_anim_stop_internal(index);
			}
		}
    GDI_EXIT_CRITICAL_SECTION(gdi_anim_stop_by_all_job_handle)
    return GDI_SUCCEED;
}

void gdi_anim_set_count(S32 count)
{
    if(count <=0 ) count = -1;
    GDI_ANIM.anim_count = count;
}

S32 gdi_anim_get_count(U8* res_src)
{
	U8* data_ptr;
	U8   img_type;
	S32 img_size;
	S32 frame_number;
	S32 width;
	S32 height;
    S32 anim_count = 0;

    GDI_ENTER_CRITICAL_SECTION(gdi_anim_get_count);
	gdi_image_parse_resource_internal(res_src, &data_ptr, &img_type, &img_size, &frame_number, &width, &height);
    GDI_EXIT_CRITICAL_SECTION(gdi_anim_get_count);
    switch(img_type)
    {
    case GDI_IMAGE_TYPE_BMP_SEQUENCE:
    case GDI_IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE:
    case GDI_IMAGE_TYPE_JPG_SEQUENCE:
    case GDI_IMAGE_TYPE_PNG_SEQUENCE:
    case GDI_IMAGE_TYPE_ABM_SEQUENCE:
    case GDI_IMAGE_TYPE_AB2_SEQUENCE:
    case GDI_IMAGE_TYPE_BMP_SEQUENCE_FILE_OFFSET:
    case GDI_IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE_FILE_OFFSET:
    case GDI_IMAGE_TYPE_JPG_SEQUENCE_FILE_OFFSET:
    case GDI_IMAGE_TYPE_PNG_SEQUENCE_FILE_OFFSET:
    case GDI_IMAGE_TYPE_ABM_SEQUENCE_FILE_OFFSET:
    case GDI_IMAGE_TYPE_AB2_SEQUENCE_FILE_OFFSET:
    	anim_count = (img_size&0x00ff); // for sequence data , image_size (bytes [2][3][4]) , the bytes[2] is used for animation loop count
    	break;
    default:
        anim_count = 0;
        break;
    }
    return anim_count;
}

GDI_RESULT gdi_anim_pause(gdi_handle a_handle)
{
    U32 anim_handle = a_handle % GDI_ANIM_COUNT;
    
	GDI_ENTER_CRITICAL_SECTION(gdi_anim_pause)	
		
	if((GDI_ANIM.anim_list[anim_handle].is_used == GDI_ANIM_FLAG_IS_FREE) ||
       (GDI_ANIM.anim_list[anim_handle].serial_id != a_handle))
			GDI_RETURN(GDI_FAILED);

	GDI_ANIM.anim_list[anim_handle].is_pause	= 1;

	StopTimer((U16)(GDI_TIMER_ANIM_BASE + anim_handle));
	
	GDI_EXIT_CRITICAL_SECTION(gdi_anim_pause)
    return GDI_SUCCEED;
}

GDI_RESULT gdi_anim_resume(gdi_handle a_handle)
{
    U32 anim_handle = a_handle % GDI_ANIM_COUNT;

	GDI_ENTER_CRITICAL_SECTION(gdi_anim_resume)	
		
	if((GDI_ANIM.anim_list[anim_handle].is_used == GDI_ANIM_FLAG_IS_FREE) ||
       (GDI_ANIM.anim_list[anim_handle].serial_id != a_handle))
			GDI_RETURN(GDI_FAILED);

	GDI_ANIM.anim_list[anim_handle].is_pause	= 0;

	StartNonAlignTimer((U16)(GDI_TIMER_ANIM_BASE+anim_handle),
							GDI_ANIM.anim_list[anim_handle].delay,
								(FuncPtr)gdi_anim_draw_internal_handler);
        
	GDI_EXIT_CRITICAL_SECTION(gdi_anim_resume)
    return GDI_SUCCEED;
}

GDI_RESULT gdi_anim_pause_all(void)
{
	GDI_ENTER_CRITICAL_SECTION(gdi_anim_pause_all)
		gdi_handle act_lcd_handle;
		int index;

		// get current active lcd
		gdi_lcd_get_active(&act_lcd_handle);
		for(index = 0;index < GDI_ANIM_COUNT;index++)
		{
			if(GDI_ANIM.anim_list[index].is_used != GDI_ANIM_FLAG_IS_FREE)
			{
				if(GDI_ANIM.anim_list[index].lcd_handle == act_lcd_handle)
					gdi_anim_pause(index);
			}
		}
	GDI_EXIT_CRITICAL_SECTION(gdi_anim_pause_all)
    return GDI_SUCCEED;
}

GDI_RESULT gdi_anim_resume_all(void)
{
	GDI_ENTER_CRITICAL_SECTION(gdi_anim_pause_all)
		gdi_handle act_lcd_handle;
		int index;

		// get current active lcd
		gdi_lcd_get_active(&act_lcd_handle);
		for(index = 0;index < GDI_ANIM_COUNT;index++)
		{
			if(GDI_ANIM.anim_list[index].is_used != GDI_ANIM_FLAG_IS_FREE)
			{
				if(GDI_ANIM.anim_list[index].lcd_handle == act_lcd_handle)
					gdi_anim_resume(index);
			}
		}
	GDI_EXIT_CRITICAL_SECTION(gdi_anim_pause_all)
    return GDI_SUCCEED;
}



