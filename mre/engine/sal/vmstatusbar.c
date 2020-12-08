/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * vmstatusbar.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
*  MRE status bar implement file
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
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

/*
 * include vmswitch.h in order to check whether __MRE_SAL_STATUS__ is defined. 
 */
#include "vmswitch.h"

#ifdef __MRE_SAL_STATUS__

#include "GeneralDeviceGprot.h"
#include "mdi_audio.h"
#include "UcmSrvGprot.h"
#include "gui_typedef.h"
#include "vmsys.h"
#include "vmpromng.h"
#include "vmresmng.h"
#include "vmdl.h"
#include "vmmod.h"
#include "vmmem.h"
#include "vmlog.h"
#include "vmchset.h"
#include "vmstdlib.h"
#include "vmstatusbar.h"
#include "MREAppMgrSrvGprot.h" // use for startup
#include "mredef.h"
#include "vmgraph.h"
#include "gpiosrvgprot.h"
#include "vmmm.h"
#ifndef SRV_MRE_APP_LOGO
#define SRV_MRE_APP_LOGO    "_MREApplogo30.img"
#endif 

/* 
 * the maxmium number of MRE apps which run at the same time is 10.
 * so we prepare 10 icon IDs for them, when search icon IDs, the index should 
 * be in the range of [1, 11)
 */
#define VM_STATUSBAR_START_INDEX    1
#define VM_STATUSBAR_MAX_COUNT      11

#ifndef vm_push_receiver_context_t

typedef struct vm_push_receiver_context_t
{
    int app_id;
    int app_handle;
    mmi_proc_func call_back;
} vm_push_receiver_context_t;
    
#endif /* vm_push_receiver_context_t */

typedef struct
{
    VMINT       icon_id;    
    VMINT       handle;   
    VMINT       is_used;    
    FuncPtr     cb;
    VMINT       new_message_index;
} vm_statusbar_icon_state_t;

/*
 * we preserved 10 icon id for MRE app. 
 * since there are 10 apps at most at them same time, so 10 icon id is enough.
 * if app gets the VM_STATUS_ICON_MRE_DEFAULT, that means all other icon IDs 
 * have been used. That is, VM_STATUS_ICON_MRE_DEFAULT is an invalid icon id.
 */
VMINT VM_STATUS_ICON_MRE_DEFAULT    =   STATUS_ICON_MRE_DEFAULT;
VMINT VM_STATUS_ICON_MRE_1          =   STATUS_ICON_MRE_DEFAULT + 1;
VMINT VM_STATUS_ICON_MRE_2          =   STATUS_ICON_MRE_DEFAULT + 2;
VMINT VM_STATUS_ICON_MRE_3          =   STATUS_ICON_MRE_DEFAULT + 3;
VMINT VM_STATUS_ICON_MRE_4          =   STATUS_ICON_MRE_DEFAULT + 4;
VMINT VM_STATUS_ICON_MRE_5          =   STATUS_ICON_MRE_DEFAULT + 5;
VMINT VM_STATUS_ICON_MRE_6          =   STATUS_ICON_MRE_DEFAULT + 6;
VMINT VM_STATUS_ICON_MRE_7          =   STATUS_ICON_MRE_DEFAULT + 7;
VMINT VM_STATUS_ICON_MRE_8          =   STATUS_ICON_MRE_DEFAULT + 8;
VMINT VM_STATUS_ICON_MRE_9          =   STATUS_ICON_MRE_DEFAULT + 9;
VMINT VM_STATUS_ICON_MRE_10         =   STATUS_ICON_MRE_DEFAULT + 10;

/* 10 icon IDs reserved for MRE apps, and a default icon id is reserved too. */
static vm_statusbar_icon_state_t g_icon_table[] = 
{
    /* 
     * the format is :
     * icon_id,                     handle, is_used,    cb,   new_message_index
     */
    {STATUS_ICON_MRE_DEFAULT,       0,      FALSE,      NULL,   0},
    {STATUS_ICON_MRE_DEFAULT + 1,   0,      FALSE,      NULL,   0},
    {STATUS_ICON_MRE_DEFAULT + 2,   0,      FALSE,      NULL,   0},
    {STATUS_ICON_MRE_DEFAULT + 3,   0,      FALSE,      NULL,   0},
    {STATUS_ICON_MRE_DEFAULT + 4,   0,      FALSE,      NULL,   0},
    {STATUS_ICON_MRE_DEFAULT + 5,   0,      FALSE,      NULL,   0},
    {STATUS_ICON_MRE_DEFAULT + 6,   0,      FALSE,      NULL,   0},
    {STATUS_ICON_MRE_DEFAULT + 7,   0,      FALSE,      NULL,   0},
    {STATUS_ICON_MRE_DEFAULT + 8,   0,      FALSE,      NULL,   0},
    {STATUS_ICON_MRE_DEFAULT + 9,   0,      FALSE,      NULL,   0},
    {STATUS_ICON_MRE_DEFAULT + 10,  0,      FALSE,      NULL,   0},
};

/*
 * This is a list, and it stores all icons that have been shown on statusbar.
 */
static vm_status_bar_icon_t *statusbar_image_queue = NULL;

/*
 * This is the data of midi, when show or hide icons on statusbar by calling 
 * vm_statusbar_set_image, this sound will be played.
 */
const __align(2) static VMUINT8 vm_notify_midi_data[] = 
{
    0x4D, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x01, 
    0x01, 0xE0, 0x4D, 0x54, 0x72, 0x6B, 0x00, 0x00, 0x00, 0x98, 0x00, 0xFF, 
    0x51, 0x03, 0x05, 0x16, 0x15, 0x00, 0xFF, 0x58, 0x04, 0x04, 0x02, 0x18, 
    0x08, 0x00, 0xF0, 0x07, 0x7F, 0x7F, 0x04, 0x01, 0x00, 0x7F, 0xF7, 0x01, 
    0xB0, 0x00, 0x00, 0x01, 0xB0, 0x20, 0x00, 0x01, 0xC0, 0x0B, 0x01, 0xB0, 
    0x07, 0x7F, 0x02, 0x90, 0x3D, 0x61, 0x00, 0x90, 0x36, 0x3F, 0x3C, 0x90, 
    0x36, 0x00, 0x00, 0x90, 0x3D, 0x00, 0x00, 0x90, 0x42, 0x68, 0x00, 0x90, 
    0x3B, 0x46, 0x3C, 0x90, 0x3B, 0x00, 0x00, 0x90, 0x42, 0x00, 0x00, 0x90, 
    0x49, 0x70, 0x00, 0x90, 0x42, 0x4E, 0x3C, 0x90, 0x42, 0x00, 0x00, 0x90, 
    0x49, 0x00, 0x00, 0x90, 0x4E, 0x78, 0x00, 0x90, 0x47, 0x56, 0x3C, 0x90, 
    0x47, 0x00, 0x00, 0x90, 0x4E, 0x00, 0x00, 0x90, 0x55, 0x7F, 0x00, 0x90, 
    0x4E, 0x5D, 0x3C, 0x90, 0x4E, 0x00, 0x00, 0x90, 0x55, 0x00, 0x85, 0x0E, 
    0x90, 0x24, 0x15, 0x78, 0x90, 0x24, 0x00, 0x86, 0x48, 0xFF, 0x07, 0x05, 
    0x53, 0x54, 0x41, 0x52, 0x54, 0x83, 0x60, 0xFF, 0x07, 0x04, 0x53, 0x54, 
    0x4F, 0x50, 0x00, 0xFF, 0x2F, 0x00
};

/* APIs only can be used in this file. */
static vm_status_bar_icon_t* vm_statusbar_get_status_bar_image_byhandle(
    VM_P_HANDLE pHandle);

static VMWCHAR* vm_get_fullfilename_by_iconid(VMINT icon_id);
static VMWCHAR* vm_get_fullfilename_by_queue_iconid(
    vm_status_bar_icon_t *image_queue, 
    VMINT icon_id);

static vm_status_bar_icon_t* vm_get_statusbar_byiconid(
    vm_status_bar_icon_t *image_queue, 
    VMINT icon_id);

static void vm_status_bar_status_notify_callback(
    VM_P_HANDLE pHandle, 
    VMINT status);

static VMINT vm_statusbar_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event);
static void vm_status_icon_cb(VMINT tid);
static void vm_statusbar_process_icon(VMINT icon_id);
static VMINT vm_statusbar_check_handle(VMINT unknow_handle);
static VMINT vm_statusbar_get_icon_id_by_handle(VM_P_HANDLE Handle);
static void vm_statusbar_play_midi_callback(
    kal_int32   handle, 
    kal_int32   result, 
    void        *user_data);

static U8* vm_statusbar_add_8byte_image_header(
    U8      identifier,
    S32     n_frames,
    U32     file_size,
    U32     width,
    U32     height, 
    VMUINT8 *img_buf);

static VMINT vm_statusbar_get_current_app_path(VMWCHAR *FullFilePath);
static VMWCHAR* vm_statusbar_get_current_app_name(VMWCHAR *FullFilePath);

#ifdef __MMI_NCENTER_SUPPORT__

static void vm_statusbar_release_notification_members_memory(
	mmi_mre_data *ncenter_cell_buf);
	
static void vm_statusbar_release_notification_memory(
	mmi_mre_data *ncenter_cell_buf);
	
static VMINT vm_statusbar_construct_notification(
    vm_status_bar_icon_t *icon,
    VM_NEW_MESSAGE_INFO  *new_message);

#endif /* __MMI_NCENTER_SUPPORT__ */

/* APIs can be used in other files. */
VMINT vm_statusbar_get_unused_iconid(void);
MMI_BOOL vm_statusbar_set_handle(VMINT icon_id, VMINT handle);
MMI_BOOL vm_statusbar_unset_handle(VMINT icon_id, VMINT icon_handle);
vm_status_bar_icon_t* vm_statusbar_list_node_create(VM_P_HANDLE pHandle);
void vm_process_status_icon_mre_0(void);
void vm_process_status_icon_mre_1(void);
void vm_process_status_icon_mre_2(void);
void vm_process_status_icon_mre_3(void);
void vm_process_status_icon_mre_4(void);
void vm_process_status_icon_mre_5(void);
void vm_process_status_icon_mre_6(void);
void vm_process_status_icon_mre_7(void);
void vm_process_status_icon_mre_8(void);
void vm_process_status_icon_mre_9(void);
void vm_process_status_icon_mre_10(void);
void vm_process_status_icon(void);
VMINT _vm_reg_statusbar_module(void);
VMINT vm_pmng_apply_to_run_in_fg(VMINT notify_type);
VMINT vm_statusbar_set_image(
    VM_ICON_STATUS_TYPE             status_type,
    VM_ICON_STATUS_ICON_IMAGE_INFO  *image_info);

/* APIs implemented in other files. */
extern VMUINT8* vm_load_resource_from_file(
    VMWSTR  filename, 
    char    *res_name, 
    VMINT   *res_size);

extern void wgui_status_icon_bar_change_icon_image_ex(
    S32 icon_id, 
    PU8 image_data);

extern void wgui_status_icon_bar_blink_icon(S32 icon_id);
extern void wgui_status_icon_bar_show_icon(S32 icon_id);
extern MMI_BOOL srv_mre_get_app_image(U16 *app_path, U8 *p_img, U32 *img_size);
extern void wgui_status_icon_bar_update(void);
extern void wgui_status_icon_bar_hide_icon(S32 icon_id);
extern void srv_mre_push_receiver_stdlib_list_callback_delete(
    VM_P_HANDLE Handle);

extern void srv_mre_push_receiver_stdlib_list_callback_reset(void);

extern void vm_graphic_async_blt_stop(void);
extern void vm_graphic_async_blt_start(void);

#ifdef __MMI_NCENTER_SUPPORT__
extern void vm_ncenter_close_notification(void*);
#endif /* __MMI_NCENTER_SUPPORT__ */

void vm_reset_status_icon_pen_event(void);
void vm_register_status_icon_pen_event(void);

#ifdef __MRE_SAL_PN__
void vm_push_new_message(U32 AppID);
#endif

#if defined(__MMI_TOUCH_SCREEN__) && defined(VM_STATUSBARICON_PRE09B) && !defined(__MMI_VUI_HOMESCREEN__)
/* 
 * we use this array to simplize the implementation of  
 * vm_register_status_icon_pen_event.
 */
typedef void (*func_ptr)(void);
static func_ptr vm_process_status_icon_mre_cb[] = {
    vm_process_status_icon_mre_0,
    vm_process_status_icon_mre_1,
    vm_process_status_icon_mre_2,
    vm_process_status_icon_mre_3,
    vm_process_status_icon_mre_4,
    vm_process_status_icon_mre_5,
    vm_process_status_icon_mre_6,
    vm_process_status_icon_mre_7,
    vm_process_status_icon_mre_8,
    vm_process_status_icon_mre_9,
    vm_process_status_icon_mre_10
};
#endif

/*****************************************************************************
 * FUNCTION
 *  vm_check_if_appcalling
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
VMINT vm_check_if_appcalling(void)
{
    #if defined(VM_STATUSBARICON_PRE09B)
        
        if ((mmi_ucm_app_incoming_call(MMI_UCM_CALL_TYPE_ALL) 
            + mmi_ucm_app_outgoing_call(MMI_UCM_CALL_TYPE_ALL) 
            + mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_NO_CSD)) > 0 )
        {
            return TRUE;
        }
        
    #else /* VM_STATUSBARICON_PRE09B */
        
        if (srv_ucm_query_call_count(
                SRV_UCM_CALL_STATE_ALL, 
                SRV_UCM_CALL_TYPE_ALL, 
                NULL) > 0)
        {
            return TRUE;
        }
        
    #endif /* VM_STATUSBARICON_PRE09B */

    return FALSE;
}
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
#endif
/******************************************************************************
 * FUNCTION
 *     vm_statusbar_release_icon_memory_internal
 * DESCRIPTION
 *     free memory that used by icon on statusbar and ncenter notification.
 *     This function is for internal use, and it is called only in 
 *     vm_statusbar_list_node_deinit.
 * PARAMETERS
 *     icon : [IN] the icon shown on statusbar and ncenter notification.
 * RETURNS
 *     void.
 *****************************************************************************/
static void vm_statusbar_release_icon_memory_internal(
    vm_status_bar_icon_t *icon)
{    
    if (icon != NULL)
    {
        /* we are going to release this icon, so we need change some flags in
         * g_icon_table[].
         *     1. set b_used to be FALSE, it means this icon is unused now.
         *     2. set handle to be 0, it means no app associated with it now.
         */
        vm_statusbar_unset_handle(icon->icon_id, 0);
        
        /* release the memory used for image buffer on statusbar. */
        if (icon->image_buffer_show != NULL)
        {
            _vm_kernel_free(icon->image_buffer_show);
        }
        
        if (icon->image_buffer_blink != NULL)
        {
            _vm_kernel_free(icon->image_buffer_blink);
        }
        
        /* release the memory used by ncenter. */
        #ifdef __MMI_NCENTER_SUPPORT__
	        vm_statusbar_release_notification_memory(icon->ncenter_cell_buf);      
        #endif /* __MMI_NCENTER_SUPPORT__ */
        
        /*
         * set all members of icon to be 0 (or NULL), because we don't need to
         * use the icon any more.
         */
        memset(icon, 0, sizeof(vm_status_bar_icon_t));
        
        /* release all memory used by icon. */
        _vm_kernel_free(icon);
    }
}

/*****************************************************************************
 * FUNCTION
 *  vm_status_bar_status_notify_callback
 * DESCRIPTION
 *   status bar system event handler ,status bar is one kind resource £¬
 *  when app status change.resource 
 *   manager will sent notify to each kind of resource
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void vm_statusbar_list_node_deinit(vm_status_bar_icon_t *node)
{
    VMINT resHandle = VM_RES_NOT_FIND;

    // if the icon is blinking ,we will hide it   
    wgui_status_icon_bar_hide_icon(node->icon_id);
    
    #ifdef __MMI_NCENTER_SUPPORT__
    	if (node->ncenter_cell_buf != NULL)
    	{
    		vm_ncenter_close_notification((void*) node);
    	}
    #endif /* __MMI_NCENTER_SUPPORT__ */

    // deinit all the res.
    while ((resHandle = vm_res_findfirst(node->pHandle,VM_RES_TYPE_STATUS_BAR)) 
            != VM_RES_NOT_FIND)
    {
        vm_res_release_data(VM_RES_TYPE_STATUS_BAR, resHandle);
        vm_res_findclose(VM_RES_TYPE_STATUS_BAR);
    }

    vm_statusbar_release_icon_memory_internal(node);
}

static void vm_status_bar_status_notify_callback(
    VM_P_HANDLE pHandle, 
    VMINT       status)
{
    switch (status)
    {
    case VM_PMNG_FOREGROUND:
        {
            vm_status_bar_icon_t *temp_node 
                = vm_statusbar_get_status_bar_image_byhandle(pHandle);

            if (NULL != temp_node)
            {
                wgui_status_icon_bar_hide_icon(temp_node->icon_id);
            }
        }
        break;

    case VM_PMNG_UNLOAD:
        if (NULL != statusbar_image_queue)
        {    
            vm_status_bar_icon_t *cursor  = statusbar_image_queue;
            vm_status_bar_icon_t *current = statusbar_image_queue;
            while (NULL != cursor)
            {                                      
                // use cursor to find the value
                if(pHandle == cursor->pHandle)
                {                            
                    // finded
                    if(cursor == current)
                    {                              
                        // header node
                        current->pNext = cursor->pNext;
                        statusbar_image_queue = current->pNext;
                        vm_statusbar_list_node_deinit(current);
                        return ;
                    }
                    else
                    {                                                          
                        // not header node
                        do{
                            if(cursor == current->pNext)
                            {
                                current->pNext = cursor->pNext;
                                vm_statusbar_list_node_deinit(cursor);
                                return ;
                            }
                            current = current->pNext; 
                        } while(cursor != current);
                    }
                }
                else
                {                                   
                    cursor = cursor->pNext; // not finded
                }
            }
        }
        break;

    case VM_PMNG_BACKGROUND: /* background running.*/ 
        {            
            if (vm_pmng_is_support_bg(pHandle)) 
            {                
                vm_status_bar_icon_t *temp_node 
                    = vm_statusbar_get_status_bar_image_byhandle(pHandle);

                // first time in BackGround we should be init the image ID to app.
                if (NULL == temp_node)
                {
                    temp_node = vm_statusbar_list_node_create(pHandle);
                    if (NULL != temp_node)
                    {
                        wgui_status_icon_bar_show_icon(temp_node->icon_id);
                    }
                }
                else
                {
                    wgui_status_icon_bar_hide_icon(temp_node->icon_id);
                    wgui_status_icon_bar_show_icon(temp_node->icon_id);
                }
            }
        }
        break;

    default:
        break;
    }  
}

/*****************************************************************************
 * FUNCTION
 *  vm_statusbar_mod_evt_proc
 * DESCRIPTION
 *  statusbar is one kind of Resource .so We must register a Handler with 
 *  RESOURCE MANAGEMENT      
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static VMINT vm_statusbar_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
    VMINT resHandle = 0;
    vm_status_bar_icon_t *icon_node = NULL;

    switch(event)
    {
    case EVT_MOD_INIT:
        statusbar_image_queue = NULL;
        if (vm_res_type_set_notify_callback(
            VM_RES_TYPE_STATUS_BAR, 
            vm_status_bar_status_notify_callback) != 0)
        {
            return -1;
        }
        break;

    case EVT_MOD_RELEASE:
        /* release queue */
        while ((icon_node = statusbar_image_queue) != NULL)
        {
            statusbar_image_queue = statusbar_image_queue->pNext;
            
            /*
             * hide icon from statusbar and delete notification in ncenter.
             * then release the memory for it.
             */
            vm_statusbar_list_node_deinit(icon_node);
        }
        statusbar_image_queue = NULL;

        /* release resource */
        while ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_STATUS_BAR)) 
            != VM_RES_NOT_FIND)
        {
            vm_res_release_data(VM_RES_TYPE_STATUS_BAR, resHandle);
            vm_res_findclose(VM_RES_TYPE_STATUS_BAR);
        }

        // reset call back
        vm_res_type_set_notify_callback(VM_RES_TYPE_STATUS_BAR, NULL);
        break;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  _vm_reg_statusbar_module
 * DESCRIPTION
 *  handler which register with resource manager
 * PARAMETERS
 *  void
 * RETURNS
 *  REG_MRE_MODULE_SUCCESS if success
 *  Error code if fail
 *****************************************************************************/
VMINT _vm_reg_statusbar_module(void)
{   
    return _vm_reg_module(
        "STATUSBAR MODULE", 
        (MOD_EVT_PROCESS) vm_statusbar_mod_evt_proc);
}

#ifdef __MMI_MRE_PUSH_RECEIVER__

static void vm_push_receiver_status_notify_callback(
    VM_P_HANDLE pHandle, 
    VMINT       status)
{
    VMINT   resHandle   = 0;

    if (status == VM_PMNG_UNLOAD)
    {
        /* release all resource */
        while ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_PUSH_RECEIVER)) 
            != VM_RES_NOT_FIND)
        {
            /* 
             * TODO: here should be scan MIC to find the registered callback 
             * and delete it 
             */
            srv_mre_push_receiver_stdlib_list_callback_delete(pHandle);
            vm_res_release_data(VM_RES_TYPE_PUSH_RECEIVER, resHandle);
        }
    }
}

static VMINT vm_push_receiver_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
    VMINT resHandle = 0;
    vm_status_bar_icon_t* icon_node = NULL;

    switch(event)
    {
    case EVT_MOD_INIT:
        {
            if (vm_res_type_set_notify_callback(
                VM_RES_TYPE_PUSH_RECEIVER, 
                vm_push_receiver_status_notify_callback) != 0)
            {
                return 0;
            }
        }
        break;

    case EVT_MOD_RELEASE:
        {
            /* release all resource */
            while ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_PUSH_RECEIVER)) 
                != VM_RES_NOT_FIND)
            {
                // TODO: /* here should be scan MIC to find the registered call back and delete it */           
                vm_res_release_data(VM_RES_TYPE_PUSH_RECEIVER, resHandle);
                vm_res_findclose(VM_RES_TYPE_PUSH_RECEIVER);
            }

            // TODO: /* clear all callback function in MIC */
            #ifdef __MMI_MRE_PUSH_RECEIVER__
            srv_mre_push_receiver_stdlib_list_callback_reset();
            #endif

            // reset call back
            vm_res_type_set_notify_callback(VM_RES_TYPE_PUSH_RECEIVER, NULL);
        }
        break;
    }

    return 0;
}


VMINT _vm_reg_push_receiver_module(void)
{  
    return _vm_reg_module(
        "PUSH RECEIVER", 
        (MOD_EVT_PROCESS) vm_push_receiver_mod_evt_proc);
}

#endif /* __MMI_MRE_PUSH_RECEIVER__ */

extern VMINT vm_pmng_apply_to_run_in_fg_1(VMINT notify_type);

/*****************************************************************************
 * FUNCTION
 *  vm_pmng_apply_to_run_in_fg
 * DESCRIPTION
 *   app apply to run in foreground .
 *   call this funciton MRE will try let app running in foreground .
 *   call only when app running in background
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
VMINT vm_pmng_apply_to_run_in_fg(VMINT notify_type)
{
    VMINT retVal = MMI_FALSE;

    vm_log_debug("vm_pmng_apply_to_run_in_fg() notify_type = %d", notify_type);
    vm_pmng_apply_to_run_in_fg_1(notify_type);

    return retVal;
}

static VMINT vm_statusbar_get_icon_id_by_handle(VM_P_HANDLE handle)
{
    VMINT i = VM_STATUSBAR_START_INDEX;
    for (; i < VM_STATUSBAR_MAX_COUNT; ++i)
    {
        if (handle == g_icon_table[i].handle) 
        {
            return g_icon_table[i].icon_id;
        }
    }

    return 0;
}

VMINT vm_statusbar_get_by_handle_icon_id(VM_P_HANDLE icon_id)
{
    VMINT i = VM_STATUSBAR_START_INDEX;
    for (; i < VM_STATUSBAR_MAX_COUNT; ++i)
    {
        if (icon_id == g_icon_table[i].icon_id) 
        {
            return g_icon_table[i].handle;
        }
    }

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  vm_statusbar_play_midi_callback
 * DESCRIPTION
 *  STOP play mma audio file and close file 
 * PARAMETERS
 *  
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void vm_statusbar_play_midi_callback(
    kal_int32   handle, 
    kal_int32   result, 
    void        *user_data)
{
    mdi_audio_mma_stop(handle);
    mdi_audio_mma_close(handle);

    /* resume background play after play notify sound */
    vm_audio_resume_bg_play();
}

static void vm_statusbar_play_vibration(VMINT notify_type)
{
    // vibration
    if (VM_NOTIFY_TYPE_VIBRATILITY 
        == (notify_type & VM_NOTIFY_TYPE_VIBRATILITY))
    {
        srv_vibrator_play_once();
    }    
}

static VMINT vm_statusbar_play_music(VMINT notify_type)
{
    // check
    if (srv_ucm_query_call_count(
        SRV_UCM_CALL_STATE_ALL, 
        SRV_UCM_CALL_TYPE_ALL, 
        NULL) > 0)
    {
        return MMI_FALSE;
    }

    // play music
    if (VM_NOTIFY_TYPE_SOUND == (notify_type & VM_NOTIFY_TYPE_SOUND))
    {
        mdi_mma_open_struct mma_open;
        mdi_handle handle = 0;

        memset((void*) &mma_open, 0, sizeof(mdi_mma_open_struct));
        mma_open.data = (void*)vm_notify_midi_data;
        mma_open.data_len = sizeof(vm_notify_midi_data);
        mma_open.mdi_format = MDI_FORMAT_SMF;
        mma_open.repeats = 1;
        mma_open.output_path = MDI_DEVICE_SPEAKER2;
        mma_open.callback = vm_statusbar_play_midi_callback;
        mma_open.handle_p = (mdi_handle*)(&handle);

        /* suspend background play before play notify sound */
        vm_audio_suspend_bg_play();

        mdi_audio_mma_open(&mma_open);
        if (*mma_open.handle_p != 0)    // open success
        {
            VMINT ret= 0;  
            ret = mdi_audio_mma_play(*mma_open.handle_p);
            if (MDI_AUDIO_SUCCESS != ret)   // play failed
            {
                mdi_audio_mma_close(handle);

                /* resume background play if play notify sound failed */
                vm_audio_resume_bg_play();
            }
            /* 
            * play notify sound successfully, after this, a callback
            * function : vm_statusbar_play_midi_callback will be called.
            */
        }
        else
        {
            /* resume background play if can't open the file of notify sound */
            vm_audio_resume_bg_play();
        }
    }

    return MMI_TRUE;
}

static VMINT vm_statusbar_get_current_app_path(VMWCHAR *FullFilePath)
{
    if (NULL == FullFilePath)
    {
        return MMI_FALSE;
    }

    if (0 != vm_get_exec_filename(FullFilePath) )
    {
        vm_free(FullFilePath);
        return MMI_FALSE;
    }

    return  MMI_TRUE;
}

static VMWCHAR* vm_statusbar_get_current_app_name(VMWCHAR *FullFilePath)
{
    VMWCHAR *FileName;
    // FullFilePath + vm_wstrlen(FullFilePath) - 1 
    // <here must be -1, otherwise will be have a error>
    for (FileName = FullFilePath + vm_wstrlen(FullFilePath) - 1; 
         FileName > FullFilePath; 
         --FileName)
    {
        if ((*FileName) == (VMWCHAR) L'\\')
        {
            if (FileName == (FullFilePath + vm_wstrlen(FullFilePath) - 1))
            {
                FileName = FullFilePath;
            }
            else
            {
                ++FileName;
            }
            
            break;
        }
    }

    return FileName;
}

static void vm_statusbar_list_insert(vm_status_bar_icon_t *insert_node)
{
    if (NULL == insert_node)
    {
        return;
    }

    insert_node->pNext = statusbar_image_queue;
    statusbar_image_queue = insert_node;
}

/*
 * must be use handle to init node    
 */
static void vm_statusbar_list_node_init(
    vm_status_bar_icon_t    *node,
    VM_P_HANDLE             pHandle)
{
    if( NULL != node)
    {
        VMINT b_used = node->b_used;
        memset(node, 0, sizeof(vm_status_bar_icon_t));
        node->b_used = b_used;
        node->pHandle = pHandle;
        node->icon_id = vm_statusbar_get_unused_iconid();
        vm_statusbar_set_handle(node->icon_id, pHandle);
    }
}

static vm_status_bar_icon_t* vm_statusbar_list_node_create(VM_P_HANDLE pHandle)
{
    vm_status_bar_icon_t    *node           = NULL;
    VMWCHAR*                fullFilename    = NULL;

    if ((fullFilename = _vm_kernel_malloc(
        (MAX_APP_NAME_LEN + 1) * sizeof(VMWCHAR))) == NULL)
    {
        return NULL;
    }

    vm_statusbar_get_current_app_path(fullFilename);
    vm_statusbar_get_current_app_name(fullFilename);

    if ((node = _vm_kernel_malloc(sizeof(vm_status_bar_icon_t))) != NULL)
    {
        memset(node, 0, sizeof(vm_status_bar_icon_t));
        if (vm_res_save_data(VM_RES_TYPE_STATUS_BAR, NULL, 0, NULL, pHandle) 
            >= 0)
        {
            // init node
            vm_statusbar_list_node_init(node, pHandle);
            // set full path
            wstrcpy(node->fullFilename, fullFilename);
            // set blink buffer 
            if (NULL != node->image_buffer_blink)
            {
                wgui_status_icon_bar_change_icon_image_ex(
                    node->icon_id,
                    node->image_buffer_blink);
            }
            // insert list
            vm_statusbar_list_insert(node);
        }
        else
        {
            _vm_kernel_free(node);
        }
    }
    
    _vm_kernel_free(fullFilename);

    return node;
}

static VMINT vm_pmng_apply_to_run_in_fg_1(VMINT notify_type)
{
    VMINT           check_ret       = 0;
    VMINT           icon_id_applyed = 0;
    VM_P_HANDLE     pHandle         = vm_pmng_get_current_handle();

    check_ret= vm_statusbar_check_handle(pHandle);
    if (check_ret != 0)
    {    
        icon_id_applyed = vm_statusbar_get_icon_id_by_handle(pHandle);
        if(icon_id_applyed != 0)
        {
            wgui_status_icon_bar_blink_icon(icon_id_applyed); 
            vm_statusbar_play_music(notify_type);
            vm_statusbar_play_vibration(notify_type);
        }
        
        return TRUE;
    }

    if (vm_pmng_state(pHandle) != VM_PMNG_BACKGROUND)
    {
        return VM_PMNG_NO_OP_IN_STATUS;
    }

    if (vm_res_get_data_list_count_by_proecss(pHandle, VM_RES_TYPE_STATUS_BAR) 
        > 0)
    {
        return VM_PMNG_OP_OK;
    }
    else
    {
        vm_status_bar_icon_t *node = NULL;

        node = vm_statusbar_list_node_create(pHandle);
        if (NULL != node)
        {
            wgui_status_icon_bar_blink_icon(node->icon_id);
        }
        vm_statusbar_play_music( notify_type);
        vm_statusbar_play_vibration(notify_type);

        return VM_PMNG_OP_OK;
    }
}

/*****************************************************************************
 * FUNCTION
 *  vm_statusbar_add_8byte_image_header
 * DESCRIPTION
 *  when we pass a raw data to GDI,we should add 8 byte file header 
 *  to tell GDI some information otherwise GDI can NOT draw image to LCD.
 * PARAMETERS
 *  identifier  : file 
 *  n_frames    : 
 *  file_size   : 
 *  width       : 
 *  height      : 
 *  img_buf     : 
 * RETURNS
 *  pointer to image which include 8byte file head
 *  NULL if fail
 *****************************************************************************/
static U8* vm_statusbar_add_8byte_image_header(
    U8      identifier,
    S32     n_frames,
    U32     file_size,
    U32     width,
    U32     height, 
    VMUINT8 *img_buf)
{
    S8  header_buffer[8]    = {0};
    S8* image_buffer        = NULL;
    U32 width_height        = 0;
    S32 data_size           = file_size ;

    if((image_buffer = (S8*) _vm_kernel_malloc(sizeof(S8) * (8 + file_size)))
        == NULL)
    {
        return NULL;
    }

    if (identifier == IMAGE_TYPE_BMP 
        || identifier == IMAGE_TYPE_GIF 
        || identifier == IMAGE_TYPE_JPG 
        || identifier == IMAGE_TYPE_PNG)
    {
        if ((file_size >> 24) > 0)
        {
            // if file too big return NULL;
            return NULL;
        }
    }

    if(width > 50 || height > 50)
    {
        return NULL; 
    }

    // set width and height.    
    width_height  = ((width & 0XFFF) << 12) | (height & 0XFFF); 

    // set frames
    if(n_frames==0)
    {
        n_frames = 1;
    }

    // construct 8 byte file header.
    header_buffer[0] = identifier;
    header_buffer[1] = n_frames;
    header_buffer[2] = (data_size & 0xff);
    header_buffer[3] = ((data_size & 0xff00) >> 8);
    header_buffer[4] = ((data_size & 0xff0000) >> 16);
    header_buffer[5] = (width_height & 0xff);
    header_buffer[6] = ((width_height & 0xff00) >> 8);
    header_buffer[7] = ((width_height & 0xff0000) >> 16);
    memcpy(image_buffer, header_buffer, 8);
    memcpy(image_buffer + 8, img_buf, file_size);

    return (U8*) image_buffer;
}

/*****************************************************************************
 * FUNCTION
 *     vm_statusbar_set_image
 * DESCRIPTION
 *     show an icon on statusbar. Caller must give a valid icon image, otherwise 
 *     this function will do nothing.
 * PARAMETERS 
 *     status_type  :   [IN]    the behavior of the icon. Please refer to 
 *                              VM_ICON_STATUS_TYPE for detail information. 
 *                              Notice that VM_ICON_NCENTER_CELL and 
 *                              VM_ICON_HIDE are not supported now.
 *     image_info   :   [IN]    the image of icon that you want to show on 
 *                              statusbar. Please refer to 
 *                              VM_ICON_STATUS_ICON_IMAGE_INFO for detail 
 *                              information.
 * RETURNS 
 *     TRUE means show icon or change icon successfully, 
 *     FALSE means fail to do that.
 *****************************************************************************/
VMINT vm_statusbar_set_image(
    VM_ICON_STATUS_TYPE             status_type,
    VM_ICON_STATUS_ICON_IMAGE_INFO  *image_info)
{
    return vm_statusbar_set_image_ex(
        status_type, 
        image_info, 
        VM_NOTIFY_TYPE_SOUND);
}

/*****************************************************************************
 * FUNCTION
 *     vm_statusbar_set_image_ex
 * DESCRIPTION
 *     show an icon on statusbar. Caller must give a valid icon image, otherwise 
 *     this function will do nothing.
 * PARAMETERS
 *     status_type  :   [IN]    the behavior of the icon. Please refer to 
 *                              VM_ICON_STATUS_TYPE for detail information. 
 *                              Notice that VM_ICON_NCENTER_CELL and 
 *                              VM_ICON_HIDE are not supported now.
 *     image_info   :   [IN]    the image of icon that you want to show on 
 *                              statusbar. Please refer to 
 *                              VM_ICON_STATUS_ICON_IMAGE_INFO for detail 
 *                              information.
 *     notify_type  :   [IN]    how to notify users that your icon on statusbar 
 *                              is changed (play a sound, vibrate, or do nothing
 *                              ). Please refer to VM_FG_NOTIFY_TYPE for detail 
 *                              information.
 * RETURNS
 *     TRUE means show icon or change icon successfully, 
 *     FALSE means fail to do that.
 *****************************************************************************/
VMINT vm_statusbar_set_image_ex(
    VM_ICON_STATUS_TYPE             status_type, 
    VM_ICON_STATUS_ICON_IMAGE_INFO  *image_info, 
    VMINT                           notify_type)
{
    VM_P_HANDLE             app_handle    = 0;
    vm_status_bar_icon_t*   icon          = NULL;
    
    vm_pmng_apply_to_run_in_fg_1(notify_type);

    /*
     * only VM_ICON_SHOW, VM_ICON_BLINK, VM_ICON_NCENTER_CELL, VM_ICON_HIDE 
     * can be handled. And the image of icon must be valid, otherwise we will do 
     * nothing but return directly.
     */
    if (VM_ICON_SHOW > status_type || status_type > VM_ICON_HIDE 
        || image_info == NULL)
    {   
        return FALSE;
    }

    /* get current app's handle. */
    if ((app_handle = vm_pmng_get_current_handle()) == 0)
    {
        return FALSE;
    }

    /*
     * get an icon by app's handle.
     * If the app doesn't have an icon, then we will create one for it.
     */
    if ((icon = vm_statusbar_get_status_bar_image_byhandle(app_handle)) == NULL)
    {
        icon = vm_statusbar_list_node_create(app_handle);
        if (icon == NULL)
        {
            return FALSE;
        }
    }

    /*
     * update the image buffer for icon on statusbar.
     * We will free the memory of image buffer firstly, because when we call 
     * vm_statusbar_add_8byte_image_header, a new block of memory is allocated, 
     * so the older memory should be released.
     */
    switch(status_type)
    {
    case VM_ICON_SHOW:
        if (icon->image_buffer_show != NULL)
        {
            _vm_kernel_free(icon->image_buffer_show);
        }
        
        icon->image_buffer_show = 
            (VMUSTR)vm_statusbar_add_8byte_image_header(
                image_info->image_type,
                image_info->image_frame_num,
                image_info->image_size,
                image_info->image_width,
                image_info->image_height,
                image_info->image_data_buf);
        break;
        
    case VM_ICON_BLINK:
        if (icon->image_buffer_blink != NULL)
        {
            _vm_kernel_free(icon->image_buffer_blink);
        }
        
        icon->image_buffer_blink = 
            (VMUSTR)vm_statusbar_add_8byte_image_header(
                image_info->image_type,
                image_info->image_frame_num,
                image_info->image_size,
                image_info->image_width,
                image_info->image_height,
                image_info->image_data_buf);
        break;
        
    /* TODO: we didn't handle VM_ICON_HIDE and VM_ICON_NCENTER_CELL. */
        
    default:
        break;
    }

    /* update all icons on statusbar. */
    {
        vm_status_bar_icon_t *temp = statusbar_image_queue;
        while(NULL != temp)
        {
            if(NULL != temp->image_buffer_blink)
            {
                wgui_status_icon_bar_change_icon_image_ex(
                    (S32) temp->icon_id,
                    (PU8) temp->image_buffer_blink );
                    
                wgui_status_icon_bar_blink_icon((S32) temp->icon_id );            
            }

            if(NULL != temp->image_buffer_show)
            {
                wgui_status_icon_bar_change_icon_image_ex(
                    (S32) temp->icon_id,
                    (PU8) temp->image_buffer_show );
                    
                wgui_status_icon_bar_show_icon((S32) temp->icon_id );            
            }

            temp = temp->pNext;
        }
    }

    /* TRUE means show icon or change icon on statusbar successfully. */
    return TRUE;
}
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

/******************************************************************************
 * FUNCTION
 *     vm_statusbar_release_notification_members_memory
 * DESCRIPTION
 *     release the memory that the notification's members used.
 *     the members here means:
 *         ncenter_cell_buf->subText
 *         ncenter_cell_buf->timeText
 *         ncenter_cell_buf->imageBuffer
 * PARAMETERS
 *     ncenter_cell_buf : [IN] a pointer to the memory that notifation used.
 * RETURNS
 *     void.
 *****************************************************************************/
#ifdef __MMI_NCENTER_SUPPORT__

static void vm_statusbar_release_notification_members_memory(
    mmi_mre_data *ncenter_cell_buf)
{
    if (ncenter_cell_buf != NULL)
    {
        /*
         * we don't need to check whether the pointer(subText, timeText and
         * imageBuffer) is NULL, because _vm_kernel_free will check it 
         * automatically.
         */
        _vm_kernel_free(ncenter_cell_buf->subText);
        _vm_kernel_free(ncenter_cell_buf->timeText);
        _vm_kernel_free(ncenter_cell_buf->imageBuffer);
        
        /*
         * ncenter_cell_buf->subText     = NULL;
         * ncenter_cell_buf->timeText    = NULL;
         * ncenter_cell_buf->imageBuffer = NULL;
         */
        memset(ncenter_cell_buf, 0, sizeof(mmi_mre_data));
    }
}

#endif /* __MMI_NCENTER_SUPPORT__ */

/******************************************************************************
 * FUNCTION
 *     vm_statusbar_release_notification_memory
 * DESCRIPTION
 *     release the memory used by notification in ncenter.
 *     Please notice that, this function will only release the memory, but will
 *     NOT set the pointer to be NULL. If you need to do so, please do it 
 *     manually after calling this function.
 * PARAMETERS
 *     ncenter_cell_buf : [IN] a pointer to the memory used by notification in
 *                             ncenter.
 * RETURNS
 *     void.
 *****************************************************************************/
#ifdef __MMI_NCENTER_SUPPORT__

static void vm_statusbar_release_notification_memory(
    mmi_mre_data *ncenter_cell_buf)
{       
    /*
     * each one of ncenter_cell_buf->subText, ncenter_cell_buf->timeText and 
     * ncenter_cell_buf->imageBuffer points to a block of memory, here we need
     * to release the memory. 
     */
    vm_statusbar_release_notification_members_memory(ncenter_cell_buf);     
    
    /* 
     * release the memory of ncenter_cell_buf. 
     * please notice that, we just release the memory that ncenter_cell_buf
     * points to, but don't set ncenter_cell_buf's value to be NULL, if you
     * need this pointer to be set to NULL, please do it manually after 
     * calling this function.
     */
    _vm_kernel_free(ncenter_cell_buf);
}

#endif /* __MMI_NCENTER_SUPPORT__ */

/******************************************************************************
 * FUNCTION
 *     vm_statusbar_construct_notification
 * DESCRIPTION
 *     allocate memory for icon->ncenter_cell_buf->subText, 
 *     icon->ncenter_cell_buf->timeText, icon->ncenter_cell_buf->imageBuffer.
 *     then fill these buffers with correct value.
 * PARAMETERS
 *     icon        : [IN] a pointer to vm_status_bar_icon_t, which contains all
 *                        information to display an image icon on statusbar and
 *                        display a notification item in ncenter.
 *     new_message : [IN] it contains the new value of subText, timeText and
 *                        imageBuffer to display a notification item in ncenter.
 * RETURNS
 *     TRUE means success.
 *     FALSE means FAIL.
 *****************************************************************************/
#ifdef __MMI_NCENTER_SUPPORT__

static VMINT vm_statusbar_construct_notification(
    vm_status_bar_icon_t *icon,
    VM_NEW_MESSAGE_INFO  *new_message)
{
    VM_ICON_STATUS_ICON_IMAGE_INFO *para_image_buffer;
    mmi_mre_data                   *ncenter_cell_buffer = icon->ncenter_cell_buf;       
    VMUINT8                        *res_buf             = NULL;
    VMINT                          appLogoSize          = 0;
    MMI_BOOL                       ret                  = MMI_FALSE;
    
    /*
     * allocate memory for subText, then copy the value from parameter to
     * ncenter_cell_buffer.
     */
    if (new_message->us_subText != NULL
    	&& (ncenter_cell_buffer->subText = (U16*) _vm_kernel_malloc(
            vm_wstrlen((VMWSTR) new_message->us_subText) * 2 + 2)) != NULL)
    {
        wstrcpy(
            (VMWSTR) ncenter_cell_buffer->subText,
            (VMWSTR) new_message->us_subText);
    }
    
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
	#endif

    /*
     * allocate memory for imageBuffer, then copy image data into 
     * ncenter_cell_buffer.
     * if user have provided image data by parameter, then we will use it 
     * directly, otherwise, we will use the app logo image.
     */
    para_image_buffer = new_message->uc_imageBuffer;
    
    if (para_image_buffer != NULL) /* user provided image data. */
    {
        if (para_image_buffer->image_size != 0)
        {
            ncenter_cell_buffer->imageBuffer 
                = (VMUSTR) vm_statusbar_add_8byte_image_header(
                    para_image_buffer->image_type,
                    para_image_buffer->image_frame_num,
                    para_image_buffer->image_size,
                    para_image_buffer->image_width,
                    para_image_buffer->image_height,
                    para_image_buffer->image_data_buf);
        }
    }
    else /* user didn't provide image data. */
    {
        ret = srv_mre_get_app_image(
            (U16*) icon->fullFilename, 
            NULL, 
            (U32*) &appLogoSize);

        if (appLogoSize != 0 && ret == MMI_TRUE)
        {
            if((res_buf = (VMUINT8*) _vm_kernel_malloc(
                    sizeof(VMUINT8) * appLogoSize)) == NULL)
            {               
                return MMI_FALSE;
            }
            /*
             * if res_buf is not NULL here, 
             * please remember to release the memory. 
             */
        }
        
        /* get app image. */
        srv_mre_get_app_image(
            (U16*) icon->fullFilename,
            res_buf, 
            (U32 *) &appLogoSize);
            
        if (appLogoSize != 0)
        {
            ncenter_cell_buffer->imageBuffer 
                = (VMUSTR) vm_statusbar_add_8byte_image_header(
                    IMAGE_TYPE_GIF,
                    1,
                    appLogoSize,
                    45,
                    45,
                    res_buf);
        }
        
        _vm_kernel_free(res_buf);
    }
    
    /*
    if (ncenter_cell_buffer->imageBuffer == NULL)
    {
        return MMI_FALSE;
    }
    */

    /* 
     * we have allocated memory for notification item in ncenter, and set the 
     * correct value. so MMI_TRUE means everything is done successfully here.
     */
    return MMI_TRUE;
}

#endif /* __MMI_NCENTER_SUPPORT__ */

/******************************************************************************
 * FUNCTION
 *     vm_statusbar_new_message
 * DESCRIPTION
 *     show icon on statusbar, and show one notification in ncenter. If one app 
 *     calls this function for more times, then the older notification will be 
 *     replaced by the latest one.
 * PARAMETERS
 *     new_message  :   [IN]    the notification that you want to show in 
 *                              ncenter. It includes a sub text, a time text, 
 *                              and an icon image.
 * RETURNS
 *     TRUE means show notification item successfully.
 *     FALSE means failure.
 *****************************************************************************/
VMINT vm_statusbar_new_message(VM_NEW_MESSAGE_INFO* new_message)
{
    VM_P_HANDLE                     app_handle;
    vm_status_bar_icon_t            *icon                   = NULL;
    mmi_event_struct                event_data;
    mmi_mre_data                    *ncenter_cell_buffer    = NULL;     

/* only valid when __MMI_NCENTER_SUPPORT__ is defined. */
#ifdef __MMI_NCENTER_SUPPORT__

    /* the text length must less than 50 characters. */
    if (new_message == NULL
        || new_message->subText_lenth > 50 
        || new_message->timeText_lenth > 50)
    {
        return MMI_FALSE;
    }
    
    /* get current app's handle. */
    if ((app_handle = vm_pmng_get_current_handle()) == 0)
    {
        return MMI_FALSE;
    }

    /* 
     * get icon by app's handle, if the app doesn't have an icon, then create 
     * one for it. 
     */
    if ((icon = vm_statusbar_get_status_bar_image_byhandle(app_handle)) == NULL)
    {
        icon = vm_statusbar_list_node_create(app_handle);
        if (icon == NULL)
        {
            return MMI_FALSE;
        }
    }

    /* show icon on statusbar. */
    if (icon->icon_id)
    {
        wgui_status_icon_bar_show_icon(icon->icon_id);
    }
    
    /* 
     * init new message
     * NOTE:this macro will memset "event_data" so do NOT set any event data 
     * before the macro.
     */
    MMI_FRM_INIT_EVENT(&event_data, EVT_ID_MRE_NOTIFICATION_MESSAGE); 

    ncenter_cell_buffer = (mmi_mre_data*) icon->ncenter_cell_buf;
    
    /*
     * if current app has shown one notification in ncenter, then we will delete
     * it from ncenter firstly, and release all the memory used for this 
     * notification (and we will re-allocate memory for it in the later).
     */
    if (ncenter_cell_buffer != NULL)
    {
        /* close the notification from ncenter. */
        vm_ncenter_close_notification((void*) icon);
        
        /*
         * release memory which is pointed to by ncenter_cell_buffer->subText,
         * ncenter_cell_buffer->timeText and ncenter_cell_buffer->imageBuffer.
         *
         * The reason is : suppose original subText's length is 10, now we want
         * to set a new subText, and the new length is 20. so the original 
         * buffer is not enough, and we need to release it firstly, then 
         * allocate a new block of memory for the new subText.
         */
        vm_statusbar_release_notification_members_memory(ncenter_cell_buffer);
    }
    
    /*
     * if current app doesn't have a notification shown in ncenter, then we will
     * allocate a block of memory for the notification.
     */
    if (NULL == ncenter_cell_buffer)
    {
        if ((ncenter_cell_buffer = (mmi_mre_data* ) _vm_kernel_malloc(
                sizeof(mmi_mre_data))) != NULL)
        {
            icon->ncenter_cell_buf = ncenter_cell_buffer;
            
            /*
             * ncenter_cell_buffer->subText     = NULL;
             * ncenter_cell_buffer->timeText    = NULL;
             * ncenter_cell_buffer->imageBuffer = NULL;
             */
            memset(ncenter_cell_buffer, 0, sizeof(mmi_mre_data));
        }
        else
        {
            return MMI_FALSE;
        }
    }
    
    /*
     * now we have a block of memory for ncenter_cell_buffer, but we still need
     * to allocate memory for its members: subText, timeText, and imageBuffer.
     */
    if (vm_statusbar_construct_notification(icon, new_message) == MMI_TRUE)
    {
        event_data.user_data = icon;
        MMI_FRM_CB_EMIT_EVENT(&event_data);
        
        /* show notification item successfully. */
        return MMI_TRUE;
    }
    else
    {
        /*
         * we can NOT construct the notification, the reason may be memory is 
         * not enough or something else. Then we should release the memory and
         * return FALSE to tell user : we can NOT show notification in ncenter.
         */
        vm_statusbar_release_notification_memory(ncenter_cell_buffer);
        icon->ncenter_cell_buf = NULL;
        
        return MMI_FALSE;
    }

#else /* __MMI_NCENTER_SUPPORT__ */

	/* if __MMI_NCENTER_SUPPORT__ is not defined, we just return FALSE. */
	return MMI_FALSE;

#endif /* __MMI_NCENTER_SUPPORT__ */
}

#ifdef __MRE_SAL_PN__

S32 vapp_mre_push_new_message(U32 app_id);
void vm_push_new_message(U32 AppID)
{
    /* TODO: */
}

#endif /* __MRE_SAL_PN__ */

vm_status_bar_icon_t* vm_statusbar_get_status_bar_image_byhandle(
    VM_P_HANDLE pHandle)
{
    vm_status_bar_icon_t *tmp = statusbar_image_queue;
    
    while (tmp != NULL)
    {
        if (tmp->pHandle == pHandle)
        {
            return tmp;
        }
        tmp = tmp->pNext;
    }

    return NULL;
}

MMI_BOOL vm_statusbar_set_handle(VMINT icon_id, VMINT icon_handle)
{
    VMINT i = VM_STATUSBAR_START_INDEX;
    for (; i < VM_STATUSBAR_MAX_COUNT; ++i)
    {
        if (icon_id == g_icon_table[i].icon_id) 
        {
            g_icon_table[i].handle     = icon_handle;
            g_icon_table[i].is_used    = MMI_TRUE; 

            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}

MMI_BOOL vm_statusbar_unset_handle(VMINT icon_id, VMINT icon_handle)
{
    VMINT i = VM_STATUSBAR_START_INDEX;
    for (; i < VM_STATUSBAR_MAX_COUNT; ++i)
    {
        if (icon_id == g_icon_table[i].icon_id) 
        {
            g_icon_table[i].handle      = icon_handle;
            g_icon_table[i].is_used     = MMI_FALSE; 

            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}

static VMINT vm_statusbar_check_handle(VMINT unknow_handle)
{
    VMINT i = VM_STATUSBAR_START_INDEX;
    for (; i < VM_STATUSBAR_MAX_COUNT; ++i)
    {
        if (unknow_handle == g_icon_table[i].handle) 
        {
            return g_icon_table[i].handle;
        }
    }

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  vm_statusbar_get_unused_iconid
 * DESCRIPTION
 *  get current not used IconID
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
VMINT vm_statusbar_get_unused_iconid(void)
{
    VMINT i = VM_STATUSBAR_START_INDEX;
    for (; i < VM_STATUSBAR_MAX_COUNT; ++i)
    {
        if (!g_icon_table[i].is_used) // unused
        {
            g_icon_table[i].is_used = TRUE;

            return g_icon_table[i].icon_id;
        }
    }

    /*
     * if all icon IDs have been used, then we will return the default icon id,
     * and user must know that, the default icon id means invalid icon id.
     */
    return VM_STATUS_ICON_MRE_DEFAULT; 
}

/*****************************************************************************
 * FUNCTION
 *  vm_register_status_icon_pen_event
 * DESCRIPTION
 *  get current not used IconID
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_VUI_HOMESCREEN__)

void vm_register_status_icon_pen_event(void)
{
    VMINT i;
    
    #if defined(VM_STATUSBARICON_PRE09B)
    
        for (i = 0; i < 11; ++i)
        {
            wgui_register_status_icon_pen_event_hdlr(
                VM_STATUS_ICON_MRE_DEFAULT + i,
                WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON,
                vm_process_status_icon_mre_cb[i]);
        }

    #else /* VM_STATUSBARICON_PRE09B */

        for (i = 0; i < 11; ++i)
        {
            wgui_status_icon_bar_register_pen_event_handler(
                VM_STATUS_ICON_MRE_DEFAULT + i,
                WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON,
                vm_process_status_icon_mre_0);
        }

    #endif /* VM_STATUSBARICON_PRE09B */
}

#else /* (__MMI_TOUCH_SCREEN__) && !defined(__MMI_VUI_HOMESCREEN__) */

void vm_register_status_icon_pen_event(void)    
{
    /* do nothing. */
}

#endif /* (__MMI_TOUCH_SCREEN__) && !defined(__MMI_VUI_HOMESCREEN__) */

/*****************************************************************************
 * FUNCTION
 *  vm_process_status_icon
 * DESCRIPTION
 *   when app running in background,IconID was be clicked,
 *   this function will be call
 * PARAMETERS
 *   
 * RETURNS
 *  void
 *****************************************************************************/
void vm_status_icon_cb(VMINT icon_id)
{
    if (VM_STATUS_ICON_MRE_1 >= icon_id && icon_id <= VM_STATUS_ICON_MRE_10)
    {
        vm_statusbar_process_icon(icon_id);
    }
}

void vm_statusbar_process_icon(VMINT icon_id)
{
    {
        // try to running app in foreground
        VMWCHAR *app_name = vm_get_fullfilename_by_iconid(icon_id);

        srv_mre_appmgr_launch_by_filepath((U16*) app_name);
    }
}

void vm_process_status_icon_mre_0(void)
{
    vm_status_icon_cb(VM_STATUS_ICON_MRE_DEFAULT);
}

void vm_process_status_icon_mre_1(void)
{
    vm_status_icon_cb(VM_STATUS_ICON_MRE_1);
}

void vm_process_status_icon_mre_2(void)
{
    vm_status_icon_cb(VM_STATUS_ICON_MRE_2);
}

void vm_process_status_icon_mre_3(void)
{
    vm_status_icon_cb(VM_STATUS_ICON_MRE_3);
}

void vm_process_status_icon_mre_4(void)
{
    vm_status_icon_cb(VM_STATUS_ICON_MRE_4);
}

void vm_process_status_icon_mre_5(void)
{
    vm_status_icon_cb(VM_STATUS_ICON_MRE_5);
}

void vm_process_status_icon_mre_6(void)
{
    vm_status_icon_cb(VM_STATUS_ICON_MRE_6);
}

void vm_process_status_icon_mre_7(void)
{
    vm_status_icon_cb(VM_STATUS_ICON_MRE_7);
}

void vm_process_status_icon_mre_8(void)
{
    vm_status_icon_cb(VM_STATUS_ICON_MRE_8);
}

void vm_process_status_icon_mre_9(void)
{
    vm_status_icon_cb(VM_STATUS_ICON_MRE_9);
}

void vm_process_status_icon_mre_10(void)
{
    vm_status_icon_cb(VM_STATUS_ICON_MRE_10);
}

/*****************************************************************************
 * FUNCTION
 *  vm_get_fullfilename_by_queue_iconid 
 * DESCRIPTION
 * find the process full file name include path by icon_id
 * PARAMETERS 
 *  [IN]  image_queue   : 
 *  [IN]  icon_id       : ICON ID 
 * RETURNS
 *  [OUT] SUCCESS       : full file name
 *  [OUT] FAIL          : NULL 
 *****************************************************************************/
static VMWCHAR* vm_get_fullfilename_by_iconid(VMINT icon_id)
{   
    VMWCHAR *app_name = vm_get_fullfilename_by_queue_iconid(
        statusbar_image_queue, 
        icon_id);

    return app_name;
}

/*****************************************************************************
 * FUNCTION
 *  vm_get_fullfilename_by_queue_iconid 
 * DESCRIPTION
 * find the process full file name include path by icon_id
 * PARAMETERS 
 *  [IN]  image_queue   : special icon queue
 *  [IN]  icon_id       : ICON ID 
 * RETURNS
 *  [OUT] SUCCESS       : full file name
 *  [OUT] FAIL          : NULL 
 *****************************************************************************/
static  VMWCHAR* vm_get_fullfilename_by_queue_iconid(
    vm_status_bar_icon_t    *image_queue,
    VMINT                   icon_id)
{
    vm_status_bar_icon_t *tmp = vm_get_statusbar_byiconid(image_queue, icon_id);
    if (tmp)
    {
        return tmp->fullFilename; // full file name include path
    }

    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  vm_get_statusbar_byiconid
 * DESCRIPTION
 *  find icon by icon_id
 * PARAMETERS
 *  [IN]  image_queue   :  
 *  [IN]  icon_id       : ICON ID
 * RETURNS
 *  [OUT] SUCCESS       : pointer which point to icon node.
 *  [OUT] FAIL          : NULL
 *****************************************************************************/
static vm_status_bar_icon_t* vm_get_statusbar_byiconid(
    vm_status_bar_icon_t    *image_queue,
    VMINT                   icon_id)
{
    vm_status_bar_icon_t *tmp = image_queue;

    // search the linked-list
    while (tmp != NULL)
    {
        if (tmp->icon_id== icon_id)
        {
            return tmp;
        }
        tmp = tmp->pNext;
    }

    return NULL;
}

/*******************************************************************************
 * FUNCTION
 *  vm_statusbar_get_height
 * DESCRIPTION
 *  get the height of statusbar.
 * PARAMETER
 *  void
 * RETURNS
 *  the height (in pixels) of statusbar.
 ******************************************************************************/
VMINT vm_statusbar_get_height(void)
{
    return MMI_STATUS_BAR_HEIGHT;
}

#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_VUI_HOMESCREEN__)

void vm_reset_status_icon_pen_event(void)
{
    VMINT i;

    #if defined(VM_STATUSBARICON_PRE09B)
        for (i = VM_STATUS_ICON_MRE_DEFAULT; i <= VM_STATUS_ICON_MRE_10; ++i)
        {
            wgui_register_status_icon_pen_event_hdlr(
                i,
                WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON,
                NULL);
        }
    #else
        for (i = VM_STATUS_ICON_MRE_DEFAULT; i <= VM_STATUS_ICON_MRE_10; ++i)
        {
            wgui_status_icon_bar_register_pen_event_handler(
                i,
                WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON,
                NULL);
        }
    #endif
}

#else /* (__MMI_TOUCH_SCREEN__) && !(__MMI_VUI_HOMESCREEN__) */

void vm_reset_status_icon_pen_event(void)
{
    /* do nothing. */
}

#endif /* (__MMI_TOUCH_SCREEN__) && !(__MMI_VUI_HOMESCREEN__) */

// Zhibo.Tong (mtk80982) add start (cut from vmgraph.c)
#ifndef MRE_GRAPHIC_FUNC_FOR_MTK_VERSION_09B
#define MRE_GRAPHIC_FUNC_FOR_MTK_VERSION_09B

void vm_graphic_status_icon_bar_hide_callback(void)
{
    S32         x1, y1, x2, y2;
    BOOL        source_key_enable;
    gdi_color   source_key_value;

    /* set clip region */
    gdi_layer_push_clip();

    /* get the clip values of bar_id */
    #ifndef  MRE_GRAPHIC_FUNC_FOR_MTK_VERSION_09B
    
        wgui_status_icon_get_status_icon_bar_clip(0, &x1, &y1, &x2, &y2);
    
    #else /* MRE_GRAPHIC_FUNC_FOR_MTK_VERSION_09B */
    
        wgui_status_icon_bar_get_clip(
            WGUI_STATUS_ICON_BAR_H_BAR, &x1, &y1, &x2, &y2);
            
    #endif /* MRE_GRAPHIC_FUNC_FOR_MTK_VERSION_09B */

    gdi_layer_set_clip(x1, y1, x2, y2);
    gdi_layer_get_source_key(&source_key_enable, &source_key_value);
    gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
    gdi_layer_pop_clip();
}

void vm_graphic_show_status_icon_bar(void)
{
    gdi_handle  cur_active_layer = 0;
    gdi_handle  cur_alpha_layer = 0;
	/*
    if(vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND)
    { 
        return;
    };
    */

    vm_graphic_async_blt_stop();

    gdi_layer_get_active(&cur_active_layer);
    gdi_get_alpha_blending_source_layer(&cur_alpha_layer);
    #ifndef MRE_GRAPHIC_FUNC_FOR_MTK_VERSION_09B
    
        wgui_status_icon_set_status_icon_bar_layer(0, cur_active_layer);
        wgui_status_icon_register_hide_status_icon_bar(
            0, 
            vm_graphic_status_icon_bar_hide_callback);
        wgui_status_icon_show_status_icon_bar(0);
        wgui_status_icon_update_status_icons();
    
    #else /* MRE_GRAPHIC_FUNC_FOR_MTK_VERSION_09B */
    
        wgui_status_icon_bar_set_target_layer(
            WGUI_STATUS_ICON_BAR_H_BAR, 
            (gdi_handle) cur_active_layer);
        if(cur_alpha_layer != 0)
        {
            wgui_status_icon_bar_set_alpha_blend_layer(
                WGUI_STATUS_ICON_BAR_H_BAR, 
                 (gdi_handle) cur_alpha_layer); 
        }
        else
        {
            wgui_status_icon_bar_set_alpha_blend_layer(
                WGUI_STATUS_ICON_BAR_H_BAR, 
                (gdi_handle) cur_active_layer);
        }
        /*
         * if we register a hide_callback to statusbar, then the callback will
         * be called to draw statusbar's background, instead of using default
         * background image.
         * 
         * here, we want the statusbar to use its default background image, so
         * the statement below is commented out.
         */
        //wgui_status_icon_bar_register_hide_callback(
        //    WGUI_STATUS_ICON_BAR_H_BAR, 
        //    vm_graphic_status_icon_bar_hide_callback);
        if(vm_pmng_state(VM_PMNG_CUR_HANDLE) == VM_PMNG_FOREGROUND)
        {
            wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
        }
        gdi_layer_lock_frame_buffer();
        wgui_status_icon_bar_update();
        gdi_layer_unlock_frame_buffer();
    
    #endif /* MRE_GRAPHIC_FUNC_FOR_MTK_VERSION_09B */   
}

/* This api is not in the sandbox, so it will be called by other api */
void vm_graphic_reset_status_icon_bar(void)
{
    VM_PROCESS_STATUS   state = vm_pmng_state(VM_PMNG_CUR_HANDLE);

    #ifndef MRE_GRAPHIC_FUNC_FOR_MTK_VERSION_09B
        wgui_status_icon_reset_status_icon_bar_layer(0);
        wgui_status_icon_reset_all_status_icon_bar_layer();
    #else
        wgui_status_icon_bar_reset_target_layer(WGUI_STATUS_ICON_BAR_H_BAR);
        wgui_status_icon_bar_reset();
    #endif

    vm_graphic_async_blt_start();
}

#endif /* MRE_GRAPHIC_FUNC_FOR_MTK_VERSION_09B */

#endif /* __MRE_SAL_STATUS__ */
