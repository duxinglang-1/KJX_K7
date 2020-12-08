#include "vmswitch.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "gdi_include.h"
#include "DevConfigGprot.h"
#include "vmopt.h"
#include "vmsys.h"
#include "vmcamera.h"
#include "vmlog.h"
#include "vmio.h"
#include "vmchset.h"
#include "vmpromng.h"
#include "vmresmng.h"
#include "vmmem.h"
#include "vmmod.h"
#include "vmpromnginner.h"
#include "lcd_sw_inc.h"
#include "mmi_frm_input_gprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gdi_datatype.h"
#include "vmtimer.h"
#include "gpiosrvgprot.h"
#include "lcd_sw_rnd.h"
#include "gdi_const.h"
#include "string.h"
#include "med_api.h"
#include "lcd_if.h"
#include "stdio.h"
#include "devconfigdef.h"
#include "mdi_camera.h"
#include "SensorSrvGport.h"
#include "app_mem_med.h"

typedef enum {
	VM_CAMERA_RES_NORMAL = 0,
	VM_CAMERA_RES_LOW
}_VM_CAMERA_RES_LEVEL;

#ifdef MRE_SUPPORT_CAMERA_FEATURE
#define VM_CAMERA_SUPPORT_ITEM_MAX_NO  (MDI_CAMERA_SUPPORT_ITEM_MAX_NO)
#endif

typedef struct vm_cam_internal_t
{
	VM_CAMERA_ID camera_id;					
	int timer_id;									
	gdi_handle preview_layer;						
	void* preview_layer_buffer;					
	unsigned int preview_width;					
	unsigned int preview_height;					
	unsigned int preview_fps;						

	gdi_handle osd_layer;							
	void* osd_layer_buffer_2;					
	
	void* preview_data;							
    void* frame_buffer;
	void* capture_data;							
	unsigned int capture_data_size;				
	unsigned int capture_width;					
	unsigned int capture_height;					

	int before_capature_repreview_success;			
	unsigned int before_capture_width;				
	unsigned int before_capture_height;			
	
	VM_CAMERA_STATUS_NOTIFY cam_callback;		
	vm_cam_notify_data_t user_notify_data; 		
	void* user_data;	
	void* af_user_data;
	VM_P_HANDLE pHandle;
	VMBOOL enable_osd_layer;
	unsigned int preview_x;
	unsigned int preview_y;
	unsigned int osd_x;
	unsigned int osd_y;
	unsigned int osd_width; 				
	unsigned int osd_height;
	unsigned int osd_rotation;
	VMUINT16 af_operation_mode;
	VMUINT16 af_range;
	VMBOOL is_lcd_update;
	VMINT32 tilt_handle;
	vm_camera_rotate_callback rotate_callback;
	VMUINT16 is_auto_detect;
	VMUINT8 rotation;
	VMINT anonymous_memroy;
}vm_cam_internal_t;

static vm_cam_internal_t* mainCamCorePtr = NULL;

extern void vm_camera_rotate_internal(void);
extern VM_GDI_RESULT convert_to_gdi_rotate_degree(vm_graphic_rotate_value degree, VMUINT8 *rotate_value);

VMINT vm_is_open_camera_flush_screen_patten(void)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE
	if (mainCamCorePtr && (mainCamCorePtr->user_notify_data.cam_status 
		== VM_CAM_PREVIEW_STATUS || (mainCamCorePtr->user_notify_data.cam_status 
		== VM_CAM_CAPTURING_STATUS && mainCamCorePtr->preview_layer != GDI_LAYER_EMPTY_HANDLE 
		&& mainCamCorePtr->preview_layer_buffer != NULL))  )
		return TRUE;
	else
		return FALSE;
#else
	return FALSE;
#endif
}

VMINT  vm_camera_patten_flush_screen_buffer(void)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE
	U8* mainBufferPtr = NULL;
	int bufferSize = (mainCamCorePtr->osd_width * mainCamCorePtr->osd_height * GDI_MAINLCD_BIT_PER_PIXEL)>>3;


	if (mainCamCorePtr && (mainCamCorePtr->user_notify_data.cam_status 
		== VM_CAM_PREVIEW_STATUS || (mainCamCorePtr->user_notify_data.cam_status 
		== VM_CAM_CAPTURING_STATUS && mainCamCorePtr->preview_layer != GDI_LAYER_EMPTY_HANDLE 
		&& mainCamCorePtr->preview_layer_buffer != NULL))  )
	{
		gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
		gdi_layer_get_buffer_ptr(&mainBufferPtr);
		
		gdi_layer_pop_and_restore_active();

		if (mainCamCorePtr->osd_layer_buffer_2)
		{

			gdi_layer_push_and_set_active(mainCamCorePtr->osd_layer);

			GDI_LOCK; 
			memcpy(mainCamCorePtr->osd_layer_buffer_2, mainBufferPtr, bufferSize);
			GDI_UNLOCK;

			gdi_layer_pop_and_restore_active();
		}

		if (gdi_layer_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1) == GDI_SUCCEED)
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}
	else
		return -1;
#else
	return -1;
#endif
}

#ifdef __MRE_SAL_CAMERA__
extern VMINT vm_graphic_get_current_layer_count(void);
extern void mmi_frm_kbd_set_tone_state(mmi_frm_kbd_tone_state_enum state);

#define CAM_CAPTURE_MAX_WIDTH							(480)
#define CAM_CAPTURE_MAX_HEIGHT							(640)
#define CAM_PREVIEW_MAX_FPS								(30)

void vm_camera_get_support_sensor_size(VMUINT* width, VMUINT* height);

#define SUPPORT_PREVIEW_SIZE_NUM 							(4)

#define NOTIFY_CAM_CALLBACK(notify_callback, notify_data, user_data, process_handle)	\
	if (notify_callback != NULL) {\
		if(vm_pmng_set_ctx(process_handle) == VM_PMNG_OP_OK)  {\
			notify_callback(notify_data, user_data);\
			vm_pmng_reset_ctx();\
		}\
	}

static vm_cam_size_t PREV_DEF_SIZE_LIS[SUPPORT_PREVIEW_SIZE_NUM];

#ifdef MRE_SUPPORT_CAMERA_FEATURE
static vm_cam_size_t CAP_DEF_SIZE_LIS[VM_CAMERA_SUPPORT_ITEM_MAX_NO];
#endif

static VMUINT vm_init_preview_size_list(void);
static void cam_internal_timer_proc(int tid);
static VMINT cam_really_start_preview(void);
static VMINT cam_create_preview_resource(void);
static void cam_free_preview_resource(void);
static void cam_really_stop_preview(void);


static void vm_finialize_camera_module(VMBOOL is_end)
{
	if( is_end )
	{
		vm_res_type_set_notify_callback(VM_RES_TYPE_CAMERA, NULL);
	}

	if (mainCamCorePtr)
	{
		if (mainCamCorePtr->user_notify_data.cam_status == VM_CAM_STARTING_PREVIEW_STATUS
			|| mainCamCorePtr->user_notify_data.cam_status == VM_CAM_PREVIEW_STATUS
			|| mainCamCorePtr->user_notify_data.cam_status == VM_CAM_CAPTURING_STATUS)
		{
			if (mainCamCorePtr->user_notify_data.cam_status == VM_CAM_PREVIEW_STATUS
				|| (mainCamCorePtr->user_notify_data.cam_status == VM_CAM_CAPTURING_STATUS
					&& mainCamCorePtr->before_capature_repreview_success))	
				cam_really_stop_preview();

			cam_free_preview_resource();
		}

		vm_delete_timer((VMSHORT)mainCamCorePtr->timer_id);
		_vm_kernel_free(mainCamCorePtr);
		mainCamCorePtr = NULL;

		mdi_audio_resume_background_play();								
		mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);	
	}
} 

static void vm_cam_process_notify_state(VM_P_HANDLE process_handle, 
	VMINT sys_state)
{
	if (mainCamCorePtr)
	{
		if (sys_state == VM_PMNG_BACKGROUND || sys_state == VM_PMNG_UNLOAD)
		{
			if (mainCamCorePtr->pHandle == process_handle)
			{
				vm_finialize_camera_module(FALSE);
			}
		}
	}
}

static VMINT vm_initialize_camera_module(void)
{
	if (vm_res_type_set_notify_callback(VM_RES_TYPE_CAMERA, 
		(vm_res_release_callback_t)vm_cam_process_notify_state) == 0)
	{
		return 0;
	}

	return -1;
}


static VMINT vm_cam_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
	switch(event)
	{
		case EVT_MOD_INIT:
			if (vm_initialize_camera_module() != 0)
				return -1;
			break;
 		case EVT_MOD_RELEASE:
			vm_finialize_camera_module(TRUE);
			break;
	}
	return 0;
}

VMINT _vm_reg_cam_module(void)
{
	int res_code = REG_MRE_MODULE_SUCCESS;
	
	res_code = _vm_reg_module("CAMERA MODULE", (MOD_EVT_PROCESS)vm_cam_mod_evt_proc);

	return res_code;
}



static VMUINT vm_init_preview_size_list(void)
{
	VMINT i = 0;
	vm_cam_size_t* sizePtr = NULL;

	PREV_DEF_SIZE_LIS[0].width = 0;
	PREV_DEF_SIZE_LIS[0].height = 0;

	for (i = 1, sizePtr = PREV_DEF_SIZE_LIS + 1; i < SUPPORT_PREVIEW_SIZE_NUM; i++, sizePtr++)
	{
		if ((LCD_HEIGHT - (i - 1) * 40) < (LCD_HEIGHT >> 1))
			break;
	
		sizePtr->width = LCD_WIDTH;
		sizePtr->height = LCD_HEIGHT - (i - 1) * 40;
	}
	
	return i;
}

static void *vm_camera_malloc_nc(int size) 
{
	if(mainCamCorePtr->anonymous_memroy)
	{
		return (void*)applib_asm_alloc_anonymous_nc(size);
	}
	else
	{
		return vm_malloc_nc(size);
	}
}

static void vm_camera_free(void* ptr) 
{
	if(mainCamCorePtr->anonymous_memroy)
	{
		applib_asm_free_anonymous(ptr);
	}
	else
	{
		vm_free(ptr);
	}
}


static VMINT cam_create_preview_resource(void)
{
	VMINT osdLayerBufferSize = 0;
	VMINT previewBufferSize =(mainCamCorePtr->preview_width * mainCamCorePtr->preview_height * GDI_MAINLCD_BIT_PER_PIXEL) >> 3;
	
	if ((mainCamCorePtr->preview_layer_buffer = vm_camera_malloc_nc(previewBufferSize)) == NULL)
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_VMCAMERA, TRC_MRE_VMCAMERA_001 );
		return FALSE;
	}

    if ((mainCamCorePtr->frame_buffer = vm_camera_malloc_nc(previewBufferSize)) == NULL)
	{
		vm_camera_free(mainCamCorePtr->preview_layer_buffer);
		mainCamCorePtr->preview_layer_buffer = NULL;	
		MMI_TRACE(MMI_MRE_TRC_MOD_VMCAMERA, TRC_MRE_VMCAMERA_002 );
		return FALSE;
	}
	
	if(mainCamCorePtr->enable_osd_layer)
	{
		osdLayerBufferSize = (mainCamCorePtr->osd_height * mainCamCorePtr->osd_width * GDI_MAINLCD_BIT_PER_PIXEL) >> 3;
		
		if ((mainCamCorePtr->osd_layer_buffer_2 = vm_camera_malloc_nc(osdLayerBufferSize)) == NULL)
		{
			vm_camera_free(mainCamCorePtr->preview_layer_buffer);
			mainCamCorePtr->preview_layer_buffer = NULL;
			vm_camera_free(mainCamCorePtr->frame_buffer);
			mainCamCorePtr->frame_buffer = NULL;	
			MMI_TRACE(MMI_MRE_TRC_MOD_VMCAMERA, TRC_MRE_VMCAMERA_003 );
			return FALSE;
		}
	}

	if (GDI_SUCCEED != gdi_layer_create_cf_using_outside_memory(GDI_LCD->cf, 
		mainCamCorePtr->preview_x, mainCamCorePtr->preview_y, 
		mainCamCorePtr->preview_width, mainCamCorePtr->preview_height,
		&mainCamCorePtr->preview_layer, (U8*)mainCamCorePtr->preview_layer_buffer, 
		previewBufferSize))
	{
		vm_camera_free(mainCamCorePtr->preview_layer_buffer);
		mainCamCorePtr->preview_layer_buffer = NULL;

		if(mainCamCorePtr->osd_layer_buffer_2 != NULL)
		{
			vm_camera_free(mainCamCorePtr->osd_layer_buffer_2);
			mainCamCorePtr->osd_layer_buffer_2 = NULL;
		}

		vm_camera_free(mainCamCorePtr->frame_buffer);
		mainCamCorePtr->frame_buffer = NULL;
		MMI_TRACE(MMI_MRE_TRC_MOD_VMCAMERA, TRC_MRE_VMCAMERA_004 );
		return FALSE;
	}
	
	gdi_layer_push_and_set_active(mainCamCorePtr->preview_layer);	
	gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
	gdi_layer_clear(GDI_COLOR_TRANSPARENT);
	gdi_layer_pop_and_restore_active();


	if(mainCamCorePtr->enable_osd_layer)
	{
	
		U8* mainBufferPtr = NULL;
    	BOOL source_key_enable;
    	gdi_color source_key_value;

		gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
		gdi_layer_get_buffer_ptr(&mainBufferPtr);
		gdi_layer_pop_and_restore_active();

		if (GDI_SUCCEED != gdi_layer_create_cf_double_using_outside_memory(
			GDI_LCD->cf, mainCamCorePtr->osd_x, mainCamCorePtr->osd_x, 
			mainCamCorePtr->osd_width, mainCamCorePtr->osd_height, 
			&mainCamCorePtr->osd_layer, (U8*)mainCamCorePtr->osd_layer_buffer_2, osdLayerBufferSize, 
			(U8*)mainBufferPtr, osdLayerBufferSize))
		{
			gdi_layer_free(mainCamCorePtr->preview_layer);
			mainCamCorePtr->preview_layer = GDI_LAYER_EMPTY_HANDLE;

			vm_camera_free(mainCamCorePtr->preview_layer_buffer);
			mainCamCorePtr->preview_layer_buffer = NULL;
			vm_camera_free(mainCamCorePtr->osd_layer_buffer_2);
			mainCamCorePtr->osd_layer_buffer_2 = NULL;
	        vm_camera_free(mainCamCorePtr->frame_buffer);
			mainCamCorePtr->frame_buffer = NULL;
			MMI_TRACE(MMI_MRE_TRC_MOD_VMCAMERA, TRC_MRE_VMCAMERA_005 );
			return FALSE;
		}
		
		gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
	    gdi_layer_get_source_key(&source_key_enable, &source_key_value);
	   	gdi_layer_pop_and_restore_active();

	    if(source_key_enable)
	    {
		    gdi_layer_push_and_set_active(mainCamCorePtr->osd_layer);
		    gdi_layer_set_source_key(TRUE, source_key_value);
		    gdi_layer_clear(source_key_value);
			gdi_set_alpha_blending_source_layer(mainCamCorePtr->osd_layer);
		    gdi_layer_pop_and_restore_active();
	    }
	}

	return TRUE;
	
}
 
static void cam_free_preview_resource(void)
{
	if (mainCamCorePtr->osd_layer_buffer_2 != NULL)
	{
		vm_camera_free(mainCamCorePtr->osd_layer_buffer_2);
		mainCamCorePtr->osd_layer_buffer_2 = NULL;
	}
	if (mainCamCorePtr->osd_layer != GDI_LAYER_EMPTY_HANDLE)
	{
		gdi_layer_free(mainCamCorePtr->osd_layer);
		mainCamCorePtr->osd_layer = GDI_LAYER_EMPTY_HANDLE;
	}

	if (mainCamCorePtr->preview_layer_buffer != NULL)
	{
		vm_camera_free(mainCamCorePtr->preview_layer_buffer);
		mainCamCorePtr->preview_layer_buffer = NULL;
	}
	if (mainCamCorePtr->preview_layer != GDI_LAYER_EMPTY_HANDLE)
	{
		gdi_layer_free(mainCamCorePtr->preview_layer);
		mainCamCorePtr->preview_layer = GDI_LAYER_EMPTY_HANDLE;
	}
    vm_camera_free(mainCamCorePtr->frame_buffer);
	mainCamCorePtr->frame_buffer = NULL;
}

static VMINT cam_really_start_preview(void)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE
	mdi_camera_setting_struct camera_setting_data = {0};
	mdi_camera_preview_struct	preview_setting_data = {0};
    BOOL source_key_enable;
    gdi_color source_key_value;
	MDI_RESULT preview_ret;

	if (mdi_camera_power_on(ASM_ANONYMOUS_ID) != MDI_RES_CAMERA_SUCCEED)
	{		
		MMI_TRACE(MMI_MRE_TRC_MOD_VMCAMERA, TRC_MRE_VMCAMERA_006 );
		return FALSE;
	}
	
	mdi_camera_load_default_setting(&camera_setting_data);
	
	camera_setting_data.preview_width 				=  mainCamCorePtr->preview_width;
	camera_setting_data.preview_height 				=  mainCamCorePtr->preview_height;   
	camera_setting_data.image_width				= mainCamCorePtr->capture_width;
	camera_setting_data.image_height				= mainCamCorePtr->capture_height;	
	camera_setting_data.lcm 						= MDI_CAMERA_PREVIEW_LCM_MAINLCD;
    camera_setting_data.af_operation_mode = mainCamCorePtr->af_operation_mode;
    camera_setting_data.af_range = mainCamCorePtr->af_range;

	gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
    gdi_layer_get_source_key(&source_key_enable, &source_key_value);
   	gdi_layer_pop_and_restore_active();

    if(mainCamCorePtr->enable_osd_layer)
    {
	    if(source_key_enable)
	    {
		    gdi_layer_set_blt_layer(mainCamCorePtr->preview_layer, mainCamCorePtr->osd_layer, 0, 0);
		    preview_setting_data.preview_layer_handle = mainCamCorePtr->preview_layer;
		    preview_setting_data.is_lcd_update = mainCamCorePtr->is_lcd_update;
		    preview_setting_data.src_key_color = GDI_COLOR_TRANSPARENT;
		    preview_setting_data.blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
		    preview_setting_data.preview_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
		    preview_setting_data.is_tvout = FALSE;    
	    }
	    else
    {
    	gdi_layer_set_blt_layer(0, mainCamCorePtr->osd_layer, 0, 0);
	    preview_setting_data.preview_layer_handle = mainCamCorePtr->preview_layer;
	    preview_setting_data.is_lcd_update = FALSE;
		    preview_setting_data.src_key_color = GDI_COLOR_TRANSPARENT;
		    preview_setting_data.blt_layer_flag = GDI_LAYER_ENABLE_LAYER_1;
		    preview_setting_data.preview_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
	    preview_setting_data.is_tvout = FALSE;    
    
	    }
    }
	else
	{
		gdi_layer_set_blt_layer(mainCamCorePtr->preview_layer, GDI_LAYER_MAIN_BASE_LAYER_HANDLE, 0, 0);
		preview_setting_data.preview_layer_handle = mainCamCorePtr->preview_layer;
		preview_setting_data.is_lcd_update = mainCamCorePtr->is_lcd_update;
		preview_setting_data.src_key_color = GDI_COLOR_TRANSPARENT;
		preview_setting_data.blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
		preview_setting_data.preview_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
		preview_setting_data.is_tvout = FALSE;	  
	}

	vm_camera_rotate_internal();
	
	preview_ret = mdi_camera_preview_start(&preview_setting_data, &camera_setting_data, NULL);
	
	if(MDI_RES_CAMERA_SUCCEED != preview_ret)
	{
		mdi_camera_power_off();		
		gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, 0, 0, 0);
		MMI_TRACE(MMI_MRE_TRC_MOD_VMCAMERA, TRC_MRE_VMCAMERA_007 , preview_ret );
		return FALSE;
	}

	return TRUE;
#else

	return FALSE;
#endif
}

static void cam_really_stop_preview(void)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE
	mdi_camera_preview_stop();
	mdi_camera_power_off();
	gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, 0, 0, 0);	
#endif
}

static void cam_internal_timer_proc(int tid)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE
	static VMINT fps_expired_ms;
	static VMINT fps_current_ms;
	vm_cam_notify_data_t notify_data;

	if (mainCamCorePtr != NULL)
	{
		switch (mainCamCorePtr->user_notify_data.cam_status)
		{
		case VM_CAM_PREVIEW_STATUS:
			if (mainCamCorePtr->preview_layer != GDI_LAYER_EMPTY_HANDLE
				&& mainCamCorePtr->preview_layer_buffer != NULL)
			{
				fps_current_ms -= 10;

				if (fps_current_ms <= 0)
				{
					mainCamCorePtr->user_notify_data.cam_message = VM_CAM_PREVIEW_FRAME_RECEIVED;
					memcpy(&notify_data, &mainCamCorePtr->user_notify_data, sizeof(vm_cam_notify_data_t));
					NOTIFY_CAM_CALLBACK(mainCamCorePtr->cam_callback, &notify_data,  mainCamCorePtr->user_data, mainCamCorePtr->pHandle);
					fps_current_ms = fps_expired_ms;
				}
			}
			break;
		case VM_CAM_STARTING_PREVIEW_STATUS:
			if (vm_graphic_get_current_layer_count() > 1)
			{
				mainCamCorePtr->user_notify_data.cam_status = VM_CAM_READY_STATUS;
				mainCamCorePtr->user_notify_data.cam_message = VM_CAM_PREVIEW_START_ABORT;
			}
			else
			{
				mainCamCorePtr->before_capture_width = mainCamCorePtr->capture_width;
				mainCamCorePtr->before_capture_height = mainCamCorePtr->capture_height;
				
				if (cam_really_start_preview())
				{
					VMINT mod = 0;
				
					mainCamCorePtr->user_notify_data.cam_status = VM_CAM_PREVIEW_STATUS;
					mainCamCorePtr->user_notify_data.cam_message = VM_CAM_PREVIEW_START_DONE;

					fps_expired_ms = 1000 / mainCamCorePtr->preview_fps;
					if ((mod = (fps_expired_ms % 10)) > 4)
						fps_expired_ms += (10 - mod);
					else
						fps_expired_ms -= mod;
					fps_current_ms = fps_expired_ms;
				}
				else
				{
					mainCamCorePtr->user_notify_data.cam_status = VM_CAM_READY_STATUS;
					mainCamCorePtr->user_notify_data.cam_message = VM_CAM_PREVIEW_START_ABORT;
					
					cam_free_preview_resource();
				}	
			}
			
			memcpy(&notify_data, &mainCamCorePtr->user_notify_data, sizeof(vm_cam_notify_data_t));
			NOTIFY_CAM_CALLBACK(mainCamCorePtr->cam_callback, &notify_data,  mainCamCorePtr->user_data, mainCamCorePtr->pHandle);
			break;
		case VM_CAM_STOPPING_PREVIEW_STATUS:
			mainCamCorePtr->user_notify_data.cam_message = VM_CAM_PREVIEW_STOP_DONE;
			mainCamCorePtr->user_notify_data.cam_status = VM_CAM_READY_STATUS;
			memcpy(&notify_data, &mainCamCorePtr->user_notify_data, sizeof(vm_cam_notify_data_t));
			NOTIFY_CAM_CALLBACK(mainCamCorePtr->cam_callback, &notify_data,  mainCamCorePtr->user_data, mainCamCorePtr->pHandle);
			break;
		case VM_CAM_CAPTURING_STATUS:
			if(mainCamCorePtr->is_auto_detect == TRUE)
			{
				if(mainCamCorePtr->rotation == VM_CAMERA_ROTATE_90 || mainCamCorePtr->rotation == VM_CAMERA_ROTATE_270)
				{
					vm_camera_update_para_image_size(mainCamCorePtr->capture_height, mainCamCorePtr->capture_width);
				}
				
				vm_camera_set_capture_rotation(mainCamCorePtr->rotation);
			}
			
			if (mainCamCorePtr->before_capature_repreview_success)
			{
				VMCHAR capture_tmp_filename[12] = {0};
				VMWCHAR wide_capture_tmp_filename[12] = {0};
				MDI_RESULT ret_value;
				
				sprintf(capture_tmp_filename, "%c:\\tmp.jpg", (VMCHAR)vm_get_system_driver());
				vm_ascii_to_ucs2(wide_capture_tmp_filename, sizeof(wide_capture_tmp_filename), capture_tmp_filename);
				vm_file_delete(wide_capture_tmp_filename);
				
				ret_value = mdi_camera_capture_to_memory((U8**)&(mainCamCorePtr->capture_data), &(mainCamCorePtr->capture_data_size),(S8*)wide_capture_tmp_filename);
				
				MMI_TRACE(MMI_MRE_TRC_MOD_VMCAMERA, TRC_MRE_VMCAMERA_008, ret_value );

				if(ret_value == MDI_RES_CAMERA_SUCCEED)
				{
					VMINT ret;
					ret = mdi_camera_save_captured_image(); 
					MMI_TRACE(MMI_MRE_TRC_MOD_VMCAMERA, TRC_MRE_VMCAMERA_009, ret );
				}

				if(ret_value == MDI_RES_CAMERA_SUCCEED)
					mainCamCorePtr->user_notify_data.cam_message = VM_CAM_CAPTURE_DONE;
				else
					mainCamCorePtr->user_notify_data.cam_message = VM_CAM_CAPTURE_ABORT;
				
				mainCamCorePtr->user_notify_data.cam_status = VM_CAM_READY_STATUS;
			}
			else
			{
				mainCamCorePtr->before_capature_repreview_success = TRUE;

				mainCamCorePtr->user_notify_data.cam_message = VM_CAM_CAPTURE_ABORT;
				mainCamCorePtr->user_notify_data.cam_status = VM_CAM_READY_STATUS;
			}

			if(1)
			{
				cam_free_preview_resource();
				memcpy(&notify_data, &mainCamCorePtr->user_notify_data, sizeof(vm_cam_notify_data_t));
	
				NOTIFY_CAM_CALLBACK(mainCamCorePtr->cam_callback, &notify_data,  mainCamCorePtr->user_data, mainCamCorePtr->pHandle);
				mainCamCorePtr->capture_data = NULL;
				mainCamCorePtr->capture_data_size = 0;

				mdi_camera_power_off();
				gdi_layer_set_blt_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, 0, 0, 0);
			}

            		
			break;
		}
	}
#endif
}

VMINT vm_create_camera_instance(VM_CAMERA_ID camera_id, VM_CAMERA_HANDLE* handle_ptr)
{  
#ifdef MRE_SUPPORT_CAMERA_FEATURE
	VM_P_HANDLE proHandle;

	proHandle = vm_pmng_get_current_handle();

	if ( handle_ptr == NULL || vm_pmng_state(proHandle) != VM_PMNG_FOREGROUND || mainCamCorePtr != NULL)
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_VMCAMERA, TRC_MRE_VMCAMERA_010, camera_id );
		return VM_CAM_OPERATION_IN_PROCESS_STATUS;
	}
	
	vm_init_preview_size_list();

	if ((mainCamCorePtr = _vm_kernel_malloc(sizeof(vm_cam_internal_t))) == NULL)
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_VMCAMERA, TRC_MRE_VMCAMERA_011 );
	 	return VM_CAM_ERR_NOMEMORY;
	}
	
	memset(mainCamCorePtr, 0x00, sizeof(vm_cam_internal_t));
	
	mainCamCorePtr->pHandle = proHandle;
	mainCamCorePtr->camera_id = VM_CAMERA_MAIN_ID;
	mainCamCorePtr->user_notify_data.handle = VM_CAMERA_MAIN_ID;
	mainCamCorePtr->user_notify_data.cam_status = VM_CAM_READY_STATUS;
	mainCamCorePtr->preview_width = LCD_WIDTH;
	mainCamCorePtr->preview_height = LCD_HEIGHT;
	mainCamCorePtr->preview_fps = CAM_PREVIEW_MAX_FPS;
	mainCamCorePtr->capture_width = LCD_WIDTH;
	mainCamCorePtr->capture_height = LCD_HEIGHT;
	mainCamCorePtr->before_capture_width = LCD_WIDTH;
	mainCamCorePtr->before_capture_height = LCD_HEIGHT;
	mainCamCorePtr->osd_layer = GDI_LAYER_EMPTY_HANDLE;
	mainCamCorePtr->preview_layer = GDI_LAYER_EMPTY_HANDLE;
	mainCamCorePtr->capture_data = NULL;
	mainCamCorePtr->capture_data_size = 0;
	mainCamCorePtr->preview_data = NULL;
	mainCamCorePtr->preview_x = 0;
	mainCamCorePtr->preview_y = 0;
	mainCamCorePtr->osd_x = 0;
	mainCamCorePtr->osd_y = 0;
	mainCamCorePtr->osd_width = LCD_WIDTH;		
	mainCamCorePtr->osd_height = LCD_HEIGHT;
	mainCamCorePtr->osd_rotation = 0;
    mainCamCorePtr->af_operation_mode = MDI_CAMERA_AF_OPERATION_MODE_OFF;
    mainCamCorePtr->af_range = MDI_CAMERA_AF_RANGE_AUTO;
	mainCamCorePtr->rotate_callback = NULL;
	mainCamCorePtr->tilt_handle = 0;
	mainCamCorePtr->is_auto_detect = 0;
	mainCamCorePtr->rotation = 0;
	mainCamCorePtr->preview_layer_buffer = NULL;
	mainCamCorePtr->before_capature_repreview_success =TRUE;
	mainCamCorePtr->anonymous_memroy = 0;

	if (camera_id != VM_CAMERA_MAIN_ID)
	{
    	mainCamCorePtr->is_lcd_update = FALSE;
		mainCamCorePtr->enable_osd_layer = FALSE;	
	}
	else
	{
    	mainCamCorePtr->is_lcd_update = TRUE;
		mainCamCorePtr->enable_osd_layer = TRUE;	
	}

	if ((mainCamCorePtr->timer_id = vm_create_timer(10, (VM_TIMERPROC_T)cam_internal_timer_proc)) < 0)
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_VMCAMERA, TRC_MRE_VMCAMERA_012 );
		_vm_kernel_free(mainCamCorePtr);
		mainCamCorePtr = NULL;
		return VM_CAM_ERR_NOMEMORY;
	}

	mdi_audio_suspend_background_play();						
	mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
	
	*handle_ptr = mainCamCorePtr->user_notify_data.handle;
	
	 return VM_CAM_SUCCESS;
#else
	MMI_TRACE(MMI_MRE_TRC_MOD_VMCAMERA, TRC_MRE_VMCAMERA_013 );
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}

VMBOOL vm_camera_is_invalid(void)
{
	if (mainCamCorePtr == NULL || vm_pmng_get_current_handle() != mainCamCorePtr->pHandle )
	{
		return TRUE;
	}
	
	return FALSE;
}

VMINT vm_camera_register_notify(VM_CAMERA_HANDLE handle, VM_CAMERA_STATUS_NOTIFY notify_callback, 
	void* user_data)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE

	if( vm_camera_is_invalid() || notify_callback == NULL)
		return VM_CAM_ERR_BAD_PARAM;

	mainCamCorePtr->user_data = user_data;
	mainCamCorePtr->cam_callback = notify_callback;

	return VM_CAM_SUCCESS;
#else

	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}

VMINT vm_camera_get_support_preview_size(VM_CAMERA_HANDLE handle, const vm_cam_size_t** cam_size_list, 
	VMUINT* list_size)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE
	VMUINT size = 0;

	if( vm_camera_is_invalid() || cam_size_list == NULL || list_size == NULL)
		return VM_CAM_ERR_BAD_PARAM;

	size = vm_init_preview_size_list();

	*cam_size_list = PREV_DEF_SIZE_LIS + 1; 		
	*list_size = size - 1;					     
	
	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}


VMINT vm_camera_get_support_capture_size(VM_CAMERA_HANDLE handle, const vm_cam_size_t** cam_size_list, 
	VMUINT* list_size)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE
	VMUINT size = 0;
	mdi_camera_fun_info cam_info;
	VMUINT16 capsize;
	
	if( vm_camera_is_invalid() || cam_size_list == NULL || list_size == NULL)
		return VM_CAM_ERR_BAD_PARAM;

	 mdi_camera_query_support_info(MDI_CAMERA_SETTING_CAPSIZE, &cam_info);
	
     if(cam_info.is_support != TRUE)
	 	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
	 
     if(cam_info.item_count > MDI_CAMERA_SUPPORT_ITEM_MAX_NO)
	 	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
   
    for (size = 0; size<cam_info.item_count; size++)
    {
		vm_cam_size_t* sizePtr = CAP_DEF_SIZE_LIS + size;

	    capsize = cam_info.support_item[size];

		switch(capsize)
		{
		   case MDI_CAMERA_CAP_SIZE_WALLPAPER:
			   sizePtr->width = LCD_WIDTH;
			   sizePtr->height = LCD_HEIGHT;
			   break;
			   
		  case MDI_CAMERA_CAP_SIZE_QVGA:
			   sizePtr->width = 320;
			   sizePtr->height = 240;
			   break;

		   case MDI_CAMERA_CAP_SIZE_VGA:
			   sizePtr->width = 640;
			   sizePtr->height = 480;
			   break;

		   case MDI_CAMERA_CAP_SIZE_1M:
			   sizePtr->width = 1280;
			   sizePtr->height = 960;
			   break;

		   case MDI_CAMERA_CAP_SIZE_2M:
			   sizePtr->width = 1600;
			   sizePtr->height = 1200;		   
			   break;

		   case MDI_CAMERA_CAP_SIZE_3M:
			   sizePtr->width = 2048;
			   sizePtr->height = 1536;		   
			   break;
			   
		   case MDI_CAMERA_CAP_SIZE_4M:
			   sizePtr->width = 2560;
			   sizePtr->height = 1920;		   
			   break;

		   case MDI_CAMERA_CAP_SIZE_5M:
			   sizePtr->width = 2592;
			   sizePtr->height = 1944;		   
			   break;			 
		   case MDI_CAMERA_CAP_SIZE_8M:
			   sizePtr->width = 3264;
			   sizePtr->height = 2488;		   
			   break;
		   default:
			   sizePtr->width = LCD_WIDTH;
			   sizePtr->height = LCD_HEIGHT;
			   break;
		}
   }


	*cam_size_list = CAP_DEF_SIZE_LIS; 		
	*list_size = size;					     
	
	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}


VMINT vm_camera_set_preview_size(VM_CAMERA_HANDLE handle, const vm_cam_size_t* preview_size)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE
	
	if( vm_camera_is_invalid() || preview_size == NULL)
		return VM_CAM_ERR_BAD_PARAM;

	if (mainCamCorePtr->user_notify_data.cam_status != VM_CAM_READY_STATUS)
	{
		return VM_CAM_ERR_OPERATE_BAD_STATUS;
	}
	MMI_TRACE(MMI_MRE_TRC_MOD_VMCAMERA, TRC_MRE_VMCAMERA_014 , preview_size->width, preview_size->height);
	mainCamCorePtr->preview_width = preview_size->width;
	mainCamCorePtr->preview_height = preview_size->height;

	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif	
}

VMINT vm_get_camera_status(VM_CAMERA_HANDLE handle, VM_CAMERA_STATUS* cam_status)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE

	if( vm_camera_is_invalid() || cam_status == NULL)
		return VM_CAM_ERR_BAD_PARAM;

	*cam_status = mainCamCorePtr->user_notify_data.cam_status;
	
	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}

VMINT vm_camera_set_preview_fps(VM_CAMERA_HANDLE handle, VMUINT fps)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE

	if( vm_camera_is_invalid() || fps == 0 || mainCamCorePtr->user_notify_data.cam_status != VM_CAM_READY_STATUS)
		return VM_CAM_ERR_BAD_PARAM;

	mainCamCorePtr->preview_fps = (fps >= CAM_PREVIEW_MAX_FPS ? CAM_PREVIEW_MAX_FPS : fps);

	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}


#if defined(MOTION_SENSOR_SUPPORT) && defined(__CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__ )
static void vm_camera_motion_tilt_hdlr(srv_sensor_type_enum sensor_type, 
               void *sensor_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sensor_motion_direct_struct* p_direct;
    srv_sensor_motion_direct_enum direct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_direct = (srv_sensor_motion_direct_struct*)sensor_data;
    direct = p_direct->direct;
	mainCamCorePtr->rotation = VM_CAMERA_ROTATE_0;
	
    switch (direct)
    {
        case SRV_SENSOR_MOTION_ANGLE_GX0:
            mainCamCorePtr->rotation = VM_CAMERA_ROTATE_270;
            break;
	    case SRV_SENSOR_MOTION_ANGLE_GY0:
            mainCamCorePtr->rotation = VM_CAMERA_ROTATE_180;;
            break;
        case SRV_SENSOR_MOTION_ANGLE_GX180:
			mainCamCorePtr->rotation = VM_CAMERA_ROTATE_90;
            break;
        case SRV_SENSOR_MOTION_ANGLE_GY180:
            mainCamCorePtr->rotation = VM_CAMERA_ROTATE_0;
            break;
        default:
            return;
    }

	if(mainCamCorePtr->rotate_callback != NULL)
	{
		if(vm_pmng_set_ctx(mainCamCorePtr->pHandle) == VM_PMNG_OP_OK)  
		{
			mainCamCorePtr->rotate_callback(mainCamCorePtr->rotation);
			vm_pmng_reset_ctx();
		}
	}
}
#endif



VMINT vm_camera_preview_start(VM_CAMERA_HANDLE handle)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE
	if( vm_camera_is_invalid() || mainCamCorePtr->cam_callback == NULL || mainCamCorePtr->user_notify_data.cam_status != VM_CAM_READY_STATUS)
		return VM_CAM_ERR_BAD_PARAM;

	if (vm_graphic_get_current_layer_count() > 1)
	{
	
		MMI_TRACE(MMI_MRE_TRC_MOD_VMCAMERA, TRC_MRE_VMCAMERA_015);
		return VM_CAM_ERR_NOMEMORY;
	}
	
	if (!cam_create_preview_resource())
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_VMCAMERA, TRC_MRE_VMCAMERA_016);
		return VM_CAM_ERR_NOMEMORY;
	}
	
	mainCamCorePtr->user_notify_data.cam_status = VM_CAM_STARTING_PREVIEW_STATUS;
		
	if(mainCamCorePtr->is_auto_detect == TRUE)
	{
#if defined(MOTION_SENSOR_SUPPORT) && defined(__CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__)
		if(mainCamCorePtr->tilt_handle == 0)
		{
			srv_sensor_motion_direct_cfg_struct sensitive;
		
			sensitive.angle_threshold = 30;
			mainCamCorePtr->tilt_handle = srv_sensor_start_listen(SRV_SENSOR_MOTION_DIRECT, &sensitive, vm_camera_motion_tilt_hdlr,NULL);
		}
#endif
	}

	
	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}

VMINT vm_camera_preview_stop(VM_CAMERA_HANDLE handle)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE

	if( vm_camera_is_invalid() || mainCamCorePtr->cam_callback == NULL)
		return VM_CAM_ERR_BAD_PARAM;

	if (mainCamCorePtr->user_notify_data.cam_status != VM_CAM_STARTING_PREVIEW_STATUS
		&& mainCamCorePtr->user_notify_data.cam_status != VM_CAM_PREVIEW_STATUS)
	{	
		MMI_TRACE(MMI_MRE_TRC_MOD_VMCAMERA, TRC_MRE_VMCAMERA_017);
		return VM_CAM_ERR_OPERATE_BAD_STATUS;
	}

	if (mainCamCorePtr->user_notify_data.cam_status == VM_CAM_PREVIEW_STATUS)
	{
		cam_really_stop_preview();
	}
	
	cam_free_preview_resource();

	mainCamCorePtr->user_notify_data.cam_status = VM_CAM_STOPPING_PREVIEW_STATUS;
	
	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}

VMINT vm_camera_get_frame(VM_CAMERA_HANDLE handle, vm_cam_frame_data_t* frame_data)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE


  VMINT bit_per_pixel = 0;
  gdi_color_format cf;

    
	if( vm_camera_is_invalid() || frame_data == NULL || vm_pmng_state(mainCamCorePtr->pHandle) != VM_PMNG_FOREGROUND)
		return VM_CAM_ERR_BAD_PARAM;

	if (VM_CAM_PREVIEW_STATUS != mainCamCorePtr->user_notify_data.cam_status
		|| mainCamCorePtr->preview_layer == GDI_LAYER_EMPTY_HANDLE
		|| mainCamCorePtr->preview_layer_buffer == NULL
		|| mainCamCorePtr->frame_buffer == NULL

  		)
  	{
		MMI_TRACE(MMI_MRE_TRC_MOD_VMCAMERA, TRC_MRE_VMCAMERA_018);
		return VM_CAM_ERR_OPERATE_BAD_STATUS;
  	}

	gdi_layer_push_and_set_active(mainCamCorePtr->preview_layer);
	bit_per_pixel =gdi_layer_get_bit_per_pixel(); 
    
    gdi_layer_get_color_format(&cf);
    
    if(GDI_COLOR_FORMAT_16 == cf)
    {   
        frame_data->pixtel_format = PIXTEL_RGB565;
    }
    else if(GDI_COLOR_FORMAT_UYVY422 == cf)
    {
        frame_data->pixtel_format = PIXTEL_UYUV422;
    }
    else
    {
        memset(frame_data,0,sizeof(vm_cam_frame_data_t));        
        gdi_layer_pop_and_restore_active();
        return VM_CAM_ERR_UNSUPPORT_OPERATION;
    }

	GDI_LOCK; 
    mdi_camera_get_hw_layer_buffer_content(mainCamCorePtr->preview_layer,(U8*)mainCamCorePtr->frame_buffer,mainCamCorePtr->preview_width*mainCamCorePtr->preview_height*bit_per_pixel/8);
//    memcpy(mainCamCorePtr->frame_buffer,mainCamCorePtr->preview_layer_buffer,mainCamCorePtr->preview_width*mainCamCorePtr->preview_height*bit_per_pixel/8);
	GDI_UNLOCK;
    frame_data->pixtel_data = mainCamCorePtr->frame_buffer;

	gdi_layer_pop_and_restore_active();
	frame_data->col_pixel =  mainCamCorePtr->preview_width;
	frame_data->row_pixel = mainCamCorePtr->preview_height;

	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}


VMINT vm_camera_get_raw_data_frame(VM_CAMERA_HANDLE handle, vm_cam_frame_raw_data_t* frame_data)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE
  MDI_RESULT ret = MDI_RES_CAMERA_ERR_CAPTURE_FAILED;

	if( vm_camera_is_invalid() || frame_data == NULL || vm_pmng_state(mainCamCorePtr->pHandle) != VM_PMNG_FOREGROUND || frame_data->buffer == NULL || frame_data->buffer_size <= 0)
		return VM_CAM_ERR_BAD_PARAM;

	if (VM_CAM_PREVIEW_STATUS != mainCamCorePtr->user_notify_data.cam_status
		|| mainCamCorePtr->preview_layer == GDI_LAYER_EMPTY_HANDLE
		|| mainCamCorePtr->preview_layer_buffer == NULL
		|| mainCamCorePtr->frame_buffer == NULL

  		)
  	{
		MMI_TRACE(MMI_MRE_TRC_MOD_VMCAMERA, TRC_MRE_VMCAMERA_019);
		return VM_CAM_ERR_OPERATE_BAD_STATUS;
  	}

	GDI_LOCK; 
	ret = mdi_camera_capture_to_memory_with_raw_data((mdi_camera_raw_data_format_enum)frame_data->format, frame_data->buffer, frame_data->buffer_size);
	GDI_UNLOCK;
	
	frame_data->col_pixel =  mainCamCorePtr->capture_width;
	frame_data->row_pixel = mainCamCorePtr->capture_height;

	return ret;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}



VMINT vm_camera_get_max_capture_size(VM_CAMERA_HANDLE handle, 
	vm_cam_size_t* size)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE

	if( vm_camera_is_invalid() || size == NULL)
		return VM_CAM_ERR_BAD_PARAM;

	size->width = CAM_CAPTURE_MAX_WIDTH;
	size->height = CAM_CAPTURE_MAX_HEIGHT;
	
	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif	
}

VMINT vm_camera_set_capture_size(VM_CAMERA_HANDLE handle, const vm_cam_size_t* size)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE

	MMI_TRACE(MMI_MRE_TRC_MOD_VMCAMERA, TRC_MRE_VMCAMERA_020, size->width, size->height);

	if( vm_camera_is_invalid() || size == NULL)
		return VM_CAM_ERR_BAD_PARAM;

	if ( size->width == 0 || size->height == 0 || 
		size->width > CAM_CAPTURE_MAX_WIDTH || size->height > CAM_CAPTURE_MAX_HEIGHT)
	{
		return VM_CAM_ERR_BAD_PARAM;
	}
	if (mainCamCorePtr->user_notify_data.cam_status == VM_CAM_CAPTURING_STATUS)
	{
		return VM_CAM_ERR_OPERATE_BAD_STATUS;
	}
	
	mainCamCorePtr->capture_width = size->width;
	mainCamCorePtr->capture_height = size->height;
	
	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}

extern mmi_devconfig_system_config_struct sysconf;
VMINT vm_camera_capture(VM_CAMERA_HANDLE handle)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE

  	//if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_ASM)
  	{
	if( vm_camera_is_invalid() || vm_pmng_state(mainCamCorePtr->pHandle) != VM_PMNG_FOREGROUND || mainCamCorePtr->cam_callback == NULL)
		return VM_CAM_ERR_BAD_PARAM;

		if (mainCamCorePtr->user_notify_data.cam_status == VM_CAM_STARTING_PREVIEW_STATUS 
			|| mainCamCorePtr->user_notify_data.cam_status == VM_CAM_STOPPING_PREVIEW_STATUS
			|| mainCamCorePtr->user_notify_data.cam_status == VM_CAM_CAPTURING_STATUS)
		{
			MMI_TRACE(MMI_MRE_TRC_MOD_VMCAMERA, TRC_MRE_VMCAMERA_021);
			return VM_CAM_ERR_OPERATE_BAD_STATUS;
		}
		if (mainCamCorePtr->user_notify_data.cam_status  == VM_CAM_READY_STATUS)
		{
			if (vm_graphic_get_current_layer_count() > 1)
			{
				MMI_TRACE(MMI_MRE_TRC_MOD_VMCAMERA, TRC_MRE_VMCAMERA_022);
				return VM_CAM_ERR_NOMEMORY;
			}
						
			if (!cam_create_preview_resource())
			{
				MMI_TRACE(MMI_MRE_TRC_MOD_VMCAMERA, TRC_MRE_VMCAMERA_023);
				return VM_CAM_ERR_NOMEMORY;
			}
			
			if (!cam_really_start_preview())
			{
				MMI_TRACE(MMI_MRE_TRC_MOD_VMCAMERA, TRC_MRE_VMCAMERA_024);
				cam_free_preview_resource();
				return VM_CAM_ERR_NOMEMORY;
			}

			mainCamCorePtr->before_capture_width = mainCamCorePtr->capture_width;
			mainCamCorePtr->before_capture_height = mainCamCorePtr->capture_height;
		}
		else
		{
			if (mainCamCorePtr->before_capture_width != mainCamCorePtr->capture_width
				|| mainCamCorePtr->before_capture_height != mainCamCorePtr->capture_height)
			{
				cam_really_stop_preview();

				mainCamCorePtr->before_capture_width = mainCamCorePtr->capture_width;
				mainCamCorePtr->before_capture_height = mainCamCorePtr->capture_height;

				if (!cam_really_start_preview())
				{
					cam_free_preview_resource();
					mainCamCorePtr->before_capature_repreview_success = FALSE;
				}
			}
		}

		mainCamCorePtr->user_notify_data.cam_status = VM_CAM_CAPTURING_STATUS;

		return VM_CAM_SUCCESS;
	}

#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}

VMINT vm_camera_get_capture_data(VM_CAMERA_HANDLE handle, vm_cam_capture_data_t* capture_data)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE

	if( vm_camera_is_invalid() || capture_data == NULL || mainCamCorePtr->capture_data == NULL)
		return VM_CAM_ERR_BAD_PARAM;

	capture_data->data = mainCamCorePtr->capture_data;
	capture_data->data_size = mainCamCorePtr->capture_data_size;
	strcpy(capture_data->mime_type, "JPEG");

	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}

VMINT vm_release_camera_instance(VM_CAMERA_HANDLE handle)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE
	if (vm_camera_is_invalid())
	{
		return VM_CAM_ERR_INVALID_CAM_HANDLE;
	}
	if (mainCamCorePtr->user_notify_data.cam_status == VM_CAM_PREVIEW_STATUS)
	{
		return VM_CAM_ERR_OPERATE_BAD_STATUS;
	}	

	vm_delete_timer(mainCamCorePtr->timer_id);

#if defined(MOTION_SENSOR_SUPPORT) && defined(__CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__ ) 
	if(mainCamCorePtr->tilt_handle != 0)
		srv_sensor_stop_listen(mainCamCorePtr->tilt_handle);
	mainCamCorePtr->rotate_callback = NULL;
#endif

	_vm_kernel_free(mainCamCorePtr);
	mainCamCorePtr = NULL;

	mdi_audio_resume_background_play();								
	mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);				
	
	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}


#ifdef MRE_SUPPORT_CAMERA_FEATURE
static void vm_af_ind_callback(mdi_camera_af_result_struct result_ind, void* user_data)
{
	vm_camera_af_ind_callback callback = NULL;
	vm_camera_af_result_struct af_result;

	if( vm_camera_is_invalid() || user_data == NULL)
		return ;
	
	af_result.af_result = (vm_af_result_enum)result_ind.af_result;
	af_result.af_success_zone = (VMUINT)result_ind.af_success_zone;
	callback = (vm_camera_af_ind_callback)user_data;
	NOTIFY_CAM_CALLBACK(callback, af_result, mainCamCorePtr->af_user_data, mainCamCorePtr->pHandle);
	return;
}
#endif


VMINT vm_camera_get_focus_zone(VM_CAMERA_HANDLE handle, vm_camera_af_window_struct* zone)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE
	mdi_camera_get_focus_zone((mdi_camera_af_window_struct*)zone);
	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}

VMINT vm_camera_start_autofocus_process(VM_CAMERA_HANDLE handle, vm_camera_af_ind_callback af_callback, void* user_data)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE
	if( vm_camera_is_invalid())
		return VM_CAM_ERR_INVALID_CAM_HANDLE;

	mainCamCorePtr->af_user_data = user_data;
	mdi_camera_start_autofocus_process(vm_af_ind_callback, (void*)af_callback);
	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}

VMINT vm_camera_stop_autofocus_process(VM_CAMERA_HANDLE handle)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE
	if( vm_camera_is_invalid())
		return VM_CAM_ERR_INVALID_CAM_HANDLE;

	mdi_camera_stop_autofocus_process();
	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}

VMINT vm_camera_set_preview_origin(VM_CAMERA_HANDLE handle, const vm_cam_origin_t* origin)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE
		
	if( vm_camera_is_invalid() || origin == NULL )
		return VM_CAM_ERR_INVALID_CAM_HANDLE;

	mainCamCorePtr->preview_x = origin->x;
	mainCamCorePtr->preview_y = origin->y;

	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif	
}

VMINT vm_camera_update_parameter(VM_CAMERA_HANDLE handle, vm_camera_para_struct* para)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE
	if( vm_camera_is_invalid() || para == NULL )
		return VM_CAM_ERR_INVALID_CAM_HANDLE;

	mainCamCorePtr->preview_x = para->preview_x;
	mainCamCorePtr->preview_y = para->preview_y;
	mainCamCorePtr->preview_width = para->preview_width;			
	mainCamCorePtr->preview_height = para->preview_height;
	mainCamCorePtr->osd_x = para->osd_x;
	mainCamCorePtr->osd_y = para->osd_y;
	mainCamCorePtr->osd_width = para->osd_width;		
	mainCamCorePtr->osd_height = para->osd_height;
    mainCamCorePtr->af_operation_mode = para->af_operation_mode;
    mainCamCorePtr->af_range = para->af_range;	
	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}

VMINT vm_camera_get_default_parameter(VM_CAMERA_HANDLE handle, vm_camera_para_struct* para)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE
	if( vm_camera_is_invalid() || para == NULL )
		return VM_CAM_ERR_INVALID_CAM_HANDLE;

	para->preview_x = mainCamCorePtr->preview_x;
	para->preview_y = mainCamCorePtr->preview_y;
	para->preview_width = mainCamCorePtr->preview_width;			
	para->preview_height = mainCamCorePtr->preview_height;
	para->osd_x = mainCamCorePtr->osd_x;
	para->osd_y = mainCamCorePtr->osd_y;
	para->osd_width = mainCamCorePtr->osd_width;		
	para->osd_height = mainCamCorePtr->osd_height;
    para->af_operation_mode = mainCamCorePtr->af_operation_mode;
    para->af_range = mainCamCorePtr->af_range;	
	return VM_CAM_SUCCESS;
#else
	return VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE;
#endif
}

void* vm_camera_get_osd_layer_buffer(VM_CAMERA_HANDLE handle, vm_cam_size_t* osd)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE
	if( vm_camera_is_invalid() || osd == NULL )
		return NULL;

	osd->height = mainCamCorePtr->osd_height ;
	osd->width = mainCamCorePtr->osd_width ;
	return mainCamCorePtr->osd_layer_buffer_2;
#else
	return NULL;
#endif
}

VMINT vm_camera_get_osd_layer_handle(VM_CAMERA_HANDLE handle)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE
	if( vm_camera_is_invalid())
		return 0;

	return mainCamCorePtr->osd_layer;
#else
	return 0;
#endif
}

VMINT vm_camera_set_camera_id(VMUINT16 camera_id)
{
	VMINT result = -1;
#ifdef MRE_SUPPORT_CAMERA_FEATURE
	result = mdi_camera_set_camera_id(camera_id);
#endif
	return result;
}

void vm_camera_set_lcd_update(VMBOOL update)
{
	mainCamCorePtr->is_lcd_update = update;
}

void vm_camera_enable_osd_layer(VMBOOL enable)
{
	mainCamCorePtr->enable_osd_layer = enable;
}

void vm_camera_use_anonymous_memory(VMBOOL mode)
{
	mainCamCorePtr->anonymous_memroy = mode;
}

VMINT vm_camera_get_main_camera_id(void)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE
	return MDI_CAMERA_MAIN;
#else
	return -1;
#endif
}

VMINT vm_camera_get_sub_camera_id(void)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE
	return MDI_CAMERA_SUB;
#else
	return -1;
#endif
}


VMINT vm_camera_is_support_dual_camera(void)
{
#ifdef DUAL_CAMERA_SUPPORT
	return 1;
#else
	return 0;
#endif
}

void vm_camera_set_capture_rotation(VMUINT8 rotate)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE
    mdi_camera_set_capture_rotation(rotate);
#endif
}

void vm_camera_register_rotation_callback(vm_camera_rotate_callback callback)
{
#if defined(MOTION_SENSOR_SUPPORT) && defined(__CAMERA_MOTION_SENSOR_SUPPORT_BY_TAG__ )
	srv_sensor_motion_direct_cfg_struct sensitive;

	sensitive.angle_threshold = 30;
	mainCamCorePtr->rotate_callback = callback;
	if(mainCamCorePtr->tilt_handle == 0)
	{
		mainCamCorePtr->tilt_handle = srv_sensor_start_listen(SRV_SENSOR_MOTION_DIRECT, &sensitive, vm_camera_motion_tilt_hdlr,NULL);
	}
#endif
}


void vm_camera_update_para_image_size(VMUINT16 image_width, VMUINT16 image_height)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE
	mdi_camera_update_para_image_size(image_width,image_height);
#endif
}

void vm_camera_set_auto_detect_mode(VMBOOL mode)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE
	mainCamCorePtr->is_auto_detect = mode;
#endif
}

VMINT vm_camera_is_horizontal_sensor(void)
{
#ifdef HORIZONTAL_CAMERA
	return 1;
#else
	return 0;
#endif
}


void vm_camera_set_capture_disable_jaia(VMBOOL is_disable)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE
	mdi_camera_set_capture_disable_jaia((MMI_BOOL)is_disable);
#endif
}


void vm_camera_rotate_internal(void)
{
	gdi_handle cur_active_layer;

	if(mainCamCorePtr->osd_rotation == 0)
		return;
	
	gdi_layer_get_active(&cur_active_layer);

	if (GDI_LAYER_MAIN_BASE_LAYER_HANDLE != cur_active_layer)
	{
		gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);	
		gdi_layer_set_rotate(mainCamCorePtr->osd_rotation);
		gdi_layer_pop_and_restore_active();
	}
	else
	{
		gdi_layer_set_rotate(mainCamCorePtr->osd_rotation);
	}

	if(mainCamCorePtr->preview_layer != GDI_LAYER_EMPTY_HANDLE)
	{
		if (mainCamCorePtr->preview_layer!= cur_active_layer)
		{
			gdi_layer_push_and_set_active(mainCamCorePtr->preview_layer);	
			gdi_layer_set_rotate(mainCamCorePtr->osd_rotation);
			gdi_layer_pop_and_restore_active();
		}
		else
		{
			gdi_layer_set_rotate(mainCamCorePtr->osd_rotation);
		}
	}
	if(mainCamCorePtr->enable_osd_layer == TRUE && mainCamCorePtr->osd_layer != GDI_LAYER_EMPTY_HANDLE)
	{
		if (mainCamCorePtr->osd_layer != cur_active_layer)
		{
			gdi_layer_push_and_set_active(mainCamCorePtr->osd_layer);	
			gdi_layer_set_rotate(mainCamCorePtr->osd_rotation);
			gdi_layer_pop_and_restore_active();
		}
		else
		{
			gdi_layer_set_rotate(mainCamCorePtr->osd_rotation);
		}
	}
}

VMBOOL vm_camera_rotate_osd_layer(VM_CAMERA_HANDLE handle, vm_graphic_rotate_value rotatevalue)
{
#ifdef MRE_SUPPORT_CAMERA_FEATURE
	VMUINT8 rotate_value;
	
	if (mainCamCorePtr == NULL)
	{
		return 0;
	}
	if (vm_pmng_get_current_handle() != mainCamCorePtr->pHandle)
	{
		return 0;
	}

	if ( convert_to_gdi_rotate_degree(rotatevalue, &rotate_value) != VM_GDI_SUCCEED )
		return -1;
	
	mainCamCorePtr->osd_rotation = rotate_value;
		
	vm_camera_rotate_internal();
	
	return TRUE;
#else
	return FALSE;
#endif
}

VMINT vm_get_camera_sym(VMCHAR* func_name)
{
	return 0;
}

#endif


