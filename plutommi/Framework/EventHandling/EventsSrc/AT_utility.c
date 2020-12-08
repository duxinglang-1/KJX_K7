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
 *   AT_utility.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is used to
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 ------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/*****************************************************************************
* Include                                                                     
*****************************************************************************/

#include "tst_def.h"
#include "CommonScreensResDef.h"
#include "PhoneSetupGprots.h"
#include "Conversions.h"
#include "SIMProvAgentGProt.h"
#include "gdi_include.h"
#include "FileMgrSrvGProt.h"
#include "App_mem.h"
#include "app_ltlcom.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "stack_config.h"
#include "mmi_frm_queue_gprot.h"
#include "stack_msgs.h"
#include "kal_debug.h"
#include "string.h"
#include "fs_type.h"
#include "fs_func.h"
#include "Unicodexdcl.h"
#include "gdi_datatype.h"
#include "CustDataRes.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "MMI_features.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_msg_struct.h"
#include "stdio.h"
#include "gui.h"
#include "mmi_frm_scenario_gprot.h"
#include "IdleAppResDef.h"
#include "ImeGprot.h"
#include "wgui_inputs.h"
#include "gui_inputs.h"
#include "PixcomFontEngine.h"
#include "vadp_v2p_autotest.h"
#include "gdi_const.h"
#include "app_mem_med.h"
#include "Vfx_sys_memory.h"

/*****************AT Command For Snapshot****************************/
#define MMI_FRM_SNAPSHOT_MAX_FILEPATH 30
#define MMI_FRM_SNAPSHOT_FOLDER    L":\\Snapshot\\"
#define MMI_FRM_SNAPSHOT_FILE      L"atCom"

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 mode;
    kal_uint16	x_coordinate;
    kal_uint16	y_coordinate;
    kal_uint16	width;
    kal_uint16	height;
} mmi_frm_snapshot_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8 result;
    kal_uint8 option;
    WCHAR filepath[MMI_FRM_SNAPSHOT_MAX_FILEPATH];
} mmi_frm_snapshot_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8 result;
    kal_uint16 width;
    kal_uint16 height;
}mmi_frm_screen_touch_size_rsp_struct;


static MMI_BOOL mmi_frm_at_snapshot_check_folder_exist(const WCHAR *path);
static U8 mmi_frm_at_snapshot_req_int(void *para);
static void mmi_frm_at_snapshot_send_rsp(U8 result, module_type src_mod, U8 mode);
extern U8 mmi_proc_inject_string(void * in);

static U8 mmi_proc_at_quick_input(void * in);

#ifdef __MMI_VUI_ENGINE__
extern U32 vadp_p2v_editor_direct_input(U8 index, U16 *string);
extern U32 vadp_p2v_uc_is_in_venus(void);
#endif

#ifdef __BT_DIALER_SUPPORT__
extern U8  mmi_bt_proc_inject_string(U8 index, kal_uint8 *string);
#endif

#ifdef __BT_MAP_CLIENT__
extern U8  mmi_bt_mapc_proc_inject_string(U8 index, kal_uint8 *string);
extern U8 srv_sms_btmapc_ut_handle(U8 index, kal_uint8 *string);
#endif

#ifdef __BT_PBAP_CLIENT__
extern U8  mmi_bt_pbap_proc_inject_string(U8 index, kal_uint8 *string);

extern U8 srv_phb_pbapc_proc_inject_string(U8 index, kal_uint8 *string);
#endif

typedef void (*mmi_inject_string_str_hdlr_type)(U8 idx);
typedef void (*mmi_inject_string_idx_hdlr_type)(U8 idx, U8 *str);

typedef struct {
    const char *str;
    mmi_inject_string_str_hdlr_type hdlr;
} mmi_inject_string_str_hdlr_table_struct;


typedef struct {
    U8 start_idx;
    U8 end_idx;
    mmi_inject_string_idx_hdlr_type hdlr;
} mmi_inject_string_idx_hdlr_table_struct;


/* generic string handler table */
const mmi_inject_string_str_hdlr_table_struct mmi_inject_string_str_hdlr_table[] = {
    {"GET_INPUT_MODE",  (mmi_inject_string_str_hdlr_type)mmi_imc_send_current_input_mode_indication},
    /* for auto-test */
#if defined(__MMI_VUI_ENGINE__)
    {"VST_DUMP",        vadp_at_scene_tree_dump},
    {"SCR_LOCK",        vadp_at_scr_lock},                      /* screen lock : index = 0/1/2 = disable/enable/exit */
    {"VK_CTRL",         vadp_at_vk_control},                    /* vk control */
    {"BL_CTRL",         vadp_at_bl_control},                    /* backlight control */
    {"Q_APP_INFO",      vadp_at_query_app_info},                /* query app info */
#endif
};


const mmi_inject_string_idx_hdlr_table_struct mmi_inject_string_idx_hdlr_table[] = {
    /*30 ~ 31 : for AutoTest */
#if defined(__MMI_VUI_ENGINE__)
    {30, 30, vadp_at_execute_cmd}, /* execute command w/ parameters */
    {31, 31, vadp_at_app_launch},   /* app launch */
#else
    {31, 31, NULL}  /* just used to prevent from zero size of this table. may remove if table size is always not-zero */
#endif
};



/*****************************************************************************
 * FUNCTION
 *  mmi_pen_css_req
 * DESCRIPTION
 *  Protocol event handler of CSS.
 *
 * PARAMETERS
 *  para    :[IN]  local parameter of the message
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_pen_css_req(void *para, int src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_screen_touch_size_rsp_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_data = (mmi_frm_screen_touch_size_rsp_struct*) mmi_construct_msg_local_para(sizeof(mmi_frm_screen_touch_size_rsp_struct));
    local_data->width = UI_device_width;
    local_data->height = UI_device_height;
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_PEN_CSS_REQ, local_data->width, local_data->height);
    local_data->result = 0;
    mmi_frm_send_ilm((module_type)src_mod, MSG_ID_MMI_EQ_SCRNSIZE_QUERY_RES_REQ, (oslParaType*)local_data, NULL);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_at_snapshot_req
 * DESCRIPTION
 *  screen snapshot protocol event handler.
 * PARAMETERS
 *  para: local parameter.
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_frm_at_snapshot_req(void *para, int src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_frm_at_snapshot_req_int(para);
    mmi_frm_at_snapshot_send_rsp(result, (module_type)src_mod, ((mmi_frm_snapshot_req_struct *)para)->mode);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_at_snapshot_send_rsp
 * DESCRIPTION
 *  Send response to L4
 * PARAMETERS
 *  para: local parameter.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_at_snapshot_send_rsp(U8 result, module_type src_mod, U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    MYQUEUE message;
    mmi_frm_snapshot_rsp_struct *local_data;
    WCHAR drv[2] = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    message.oslSrcId = MOD_MMI;
    message.oslDestId = src_mod;
    message.oslMsgId = MSG_ID_MMI_EQ_SCREEN_SHOT_RES_REQ;
    local_data = (mmi_frm_snapshot_rsp_struct*) mmi_construct_msg_local_para(sizeof(mmi_frm_snapshot_rsp_struct));
    local_data->option = mode;
    if (!result) // error
    {
        local_data->result = -1;
        memset(local_data->filepath, 0x00, sizeof(local_data->filepath)); 
    }
    else//right
    {
        local_data->result = 0;
        if((mode != 2) && (mode != 3))
        {  
            if(result == 2)
            {
                drv[0] = SRV_FMGR_PUBLIC_DRV;
                drv[1] = 0;
            }
            else if(result == 3)
            {
                drv[0] = SRV_FMGR_CARD_DRV;
                drv[1] = 0;
            }
            mmi_ucs2cpy((CHAR *)local_data->filepath, (CHAR *)drv);
            mmi_ucs2cat((CHAR *)local_data->filepath, (CHAR *)MMI_FRM_SNAPSHOT_FOLDER);
            mmi_ucs2cat((CHAR *)local_data->filepath, (CHAR *)MMI_FRM_SNAPSHOT_FILE);
            mmi_ucs2cat((CHAR *)local_data->filepath, (CHAR *)L"\0");
        }
    }
    message.oslDataPtr = (oslParaType*) local_data;
    message.oslPeerBuffPtr = NULL;
    mmi_msg_send_ext_queue(&message);
}

 
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_snapshot_write_info
 * DESCRIPTION
 *  write snapshot info into different drv
 * PARAMETERS
 *  disk: drv
 *  info: capture screen snapshot info buffer
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_frm_snapshot_write_info(int disk, gdi_screen_shot_info_struct* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR drv[2] = {0};
    WCHAR folderpath[MMI_FRM_SNAPSHOT_MAX_FILEPATH] = {0};
    MMI_BOOL ifCreateFolder;
    int result = 0;
    UINT writesize;
    drv[0] = disk;
    drv[1] = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((CHAR *)folderpath, (CHAR *)drv);
    mmi_ucs2cat((CHAR *)folderpath, (CHAR *)MMI_FRM_SNAPSHOT_FOLDER);
    ifCreateFolder = mmi_frm_at_snapshot_check_folder_exist((WCHAR *)folderpath);
    if(!ifCreateFolder)
    {
        result = FS_CreateDir((WCHAR *)folderpath);
        if (result < 0)
        {
            return 0;
        }
    }
    mmi_ucs2cat((CHAR *)folderpath, (CHAR *)MMI_FRM_SNAPSHOT_FILE);
    result = FS_Open((WCHAR *)folderpath, FS_READ_WRITE | FS_CREATE);
    if (result < 0)
    {   
        return 0;
    }
    if (FS_Write(result, (void *)info, info->header_size, &writesize) < 0)
    {   
        FS_Close(result);
        return 0;
    }
    if (FS_Write(result, (void *)(info->buf_ptr), info->buf_size, &writesize) < 0)
    {
        FS_Close(result);
        return 0;
    }
    FS_Close(result);
    return 1;
    
} 

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_at_snapshot_req_int
 * DESCRIPTION
 *  internal function.
 * PARAMETERS
 *  para: local parameter.
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_frm_at_snapshot_req_int(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 mode;
    gdi_screen_shot_info_struct *info = NULL;
    int result = 0;
    kal_uint16 x, y, width, height;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mode = ((mmi_frm_snapshot_req_struct *)para)->mode;
    x    = ((mmi_frm_snapshot_req_struct *)para)->x_coordinate;
    y    = ((mmi_frm_snapshot_req_struct *)para)->y_coordinate;
    width=((mmi_frm_snapshot_req_struct *)para)->width;
    height=((mmi_frm_snapshot_req_struct *)para)->height;
    switch (mode)
    {
        case 0:
            info = gdi_screen_shot_capture(GDI_LCD_MAIN_LCD_HANDLE, 0);
            break;
        case 1:
            #ifdef __MMI_SUBLCD__
                info = gdi_screen_shot_capture(GDI_LCD_SUB_LCD_HANDLE, 0);
                break;
            #else /*  __MMI_SUBLCD__ */
                return 0;
            #endif /*  __MMI_SUBLCD__ */

         case 2: //enable string capture
            result = mmi_res_str_chk_set_status(MMI_TRUE);
            if (result != 0)
            {
                return 0;
            }
             return 1;

         case 3:// disable string capture
            result =  mmi_res_str_chk_set_status(MMI_FALSE);
            if (result != 0)
            {
                return 0;
            }
             return 1;

         case 4:
            {
                void *ptr = NULL;
                gdi_screen_shot_info_struct gdi_scrn_info;
                kal_uint32 buffer_size = 0;
                info = &gdi_scrn_info;
                if((width > GDI_LCD_WIDTH) || (height > GDI_LCD_HEIGHT) || x > GDI_LCD_WIDTH || y > GDI_LCD_HEIGHT)
                { 
                    return 0;
                }
                if((x + width >GDI_LCD_HEIGHT) || (y + height > GDI_LCD_HEIGHT))
                {
                    return 0;
                }
                buffer_size = ((width + 16) * (height + 16) * GDI_MAINLCD_BIT_PER_PIXEL) >> 3;
                ptr = applib_asm_alloc_anonymous_nc(buffer_size);
                if(NULL == ptr)
                {
                    return 0;
                }
                result = gdi_util_get_screenshot_region(
                            &gdi_scrn_info,
                            GDI_LCD_MAIN_LCD_HANDLE,
                            (kal_int32)x,
                            (kal_int32)y,
                            (kal_int32)width,
                            (kal_int32)height,
                            ptr,
                            buffer_size,
                            GDI_COLOR_FORMAT_16,
                            0
                            );
                applib_asm_free_anonymous(ptr);
                ptr = NULL;
                break;
            }
            

        default:
            MMI_ASSERT(0);
            break;
    }
    if (!info)
    {
        return 0;
    }

    if (mmi_frm_snapshot_write_info(SRV_FMGR_PUBLIC_DRV, info) == 1)
    {   
        return 2;
    }
    else if(mmi_frm_snapshot_write_info(SRV_FMGR_CARD_DRV, info) == 1)
    {   
        return 3;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_at_snap_shot_check_folder_exist
 * DESCRIPTION
 *  screen snapshot protocol event handler.
 * PARAMETERS
 *  path: snapshot folder path.
 * RETURNS
 MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_frm_at_snapshot_check_folder_exist(const WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = FS_Open(path, FS_OPEN_DIR | FS_READ_ONLY);
    if (handle < 0)
    {
        return MMI_FALSE;
    }
    FS_Close(handle);
    return MMI_TRUE;    
}


/*****************************************************************************
 *
 *   AT:  dump screen string support
 *
 *****************************************************************************/

/***************************************************************************** 
* define
*****************************************************************************/
#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
    
/* Enable dump screen string trace in MoDIS */
#define ENABLE_DUMP_SCREEN_STRING_TRACE
    
/* compose the chars in the same colume to the string */
#define __COMPOSE_CHAR_IN_DUMP_SCREEN_STRING__
#endif

/* MMI supports dump screen string automatically */
#define MMI_STR_DUMP_TIMEOUT                    (1500)  /* ms */
#define MMI_SCREEN_NO_STR                       (0)
#define MMI_SCREEN_NORMAL_STR                   (1)
#define MMI_SCREEN_HIGHLIGHT_STR                (2)
/* We want combined separated chars to the string */
#define MMI_SCREEN_COMPOSED_CHAR_MAX_LENGTH     (100)
/*
 * MMI_SCREEN_STR_MAX_LENGTH should be the same with
 * "data_string" in mmi_eq_str_res_req_struct/mmi_eq_str_req_ind_struct
 */
#define MMI_SCREEN_STR_MAX_LENGTH               (250)


/***************************************************************************** 
* Typdef
*****************************************************************************/
typedef struct
{
    MMI_BOOL    is_enable;
    MMI_BOOL    allow_dump_screen_str;
    MMI_BOOL    allow_dump_dm_screen;
    U16         highlight_type;
    U16         backup_highlight_type;
    S16         y;
    S16         backup_y;
    S16         compose_chars_x;
    S16         compose_chars_y;
    S8          compose_chars[MMI_SCREEN_COMPOSED_CHAR_MAX_LENGTH];
    /* the backup string size should be the same with mmi_eq_str_res_req_struct*/
    S8          backup_string[MMI_SCREEN_STR_MAX_LENGTH];
} mmi_dss_struct;


/***************************************************************************** 
* Global Varialbe
*****************************************************************************/
mmi_dss_struct g_mmi_dss_cntx;


/***************************************************************************** 
* Local Function Declaration
*****************************************************************************/
static void mmi_str_cmd_ind(void *info);
static void mmi_enable_str_dump(void *info);
#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
static void mmi_no_more_str_hdlr(void);
static void send_msg_int(oslModuleType src_mod_id, oslModuleType dest_mod_id, oslMsgType msg_id, 
                        oslParaType *local_para, oslPeerBuffType *peer_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE ilm;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm.oslSrcId = src_mod_id;
    ilm.oslDestId = dest_mod_id;
    ilm.oslMsgId = msg_id;
    ilm.oslDataPtr = local_para;
    ilm.oslPeerBuffPtr = peer_buff;
    OslMsgSendExtQueue(&ilm);    
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_init_dump_screen_string
 * DESCRIPTION
 *  init dump screen string module
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_init_dump_screen_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EQ_STR_ENABLE_REQ_IND, (PsIntFuncPtr)mmi_enable_str_dump, MMI_FALSE);
	mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EQ_STR_REQ_IND, (PsIntFuncPtr)mmi_str_cmd_ind, MMI_FALSE);
#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
#if !defined(__MTK_TARGET__)
        g_mmi_dss_cntx.is_enable = (MMI_BOOL)0;
        g_mmi_dss_cntx.highlight_type = 0;
        g_mmi_dss_cntx.backup_highlight_type = 0;
        g_mmi_dss_cntx.y = 0;
        g_mmi_dss_cntx.backup_y = 0;
        g_mmi_dss_cntx.compose_chars_x = 0;
        g_mmi_dss_cntx.compose_chars_y = 0;
        memset(g_mmi_dss_cntx.backup_string, 0, MMI_SCREEN_STR_MAX_LENGTH);
#endif
#endif /* __MMI_SUPPORT_DUMP_SCREEN_STRING__ */
}


#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
/*****************************************************************************
 * FUNCTION
 *  mmi_trace_screen_string
 * DESCRIPTION
 *  Sending the screen string
 *  
 * PARAMETERS
 *  x           [IN]
 *  y           [IN]
 *  str         [IN]
 *  len         [IN]
 *  Bordered    [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_trace_screen_string(S32 x, S32 y, U8 *str, S32 len, S32 Bordered)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    S32 composed_chars_len = 0;
#ifdef __MTK_TARGET__
    mmi_eq_str_res_req_struct *rsp_msg;
#else
    U8 data_string[200];
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If having composed chars, dump the string first */
    composed_chars_len = mmi_ucs2strlen(g_mmi_dss_cntx.compose_chars);
    if (composed_chars_len)
    {
    #ifdef __MTK_TARGET__
        rsp_msg = (mmi_eq_str_res_req_struct *)	OslConstructDataPtr( sizeof(mmi_eq_str_res_req_struct) );
        composed_chars_len = (composed_chars_len > MMI_SCREEN_COMPOSED_CHAR_MAX_LENGTH/ENCODING_LENGTH) ? MMI_SCREEN_COMPOSED_CHAR_MAX_LENGTH/ENCODING_LENGTH : composed_chars_len;
        kal_sprintf((char*)rsp_msg->data_string, "%d,(%d,%d),%d,", 
                        1,  /* Normal string */
                        g_mmi_dss_cntx.compose_chars_x,
                        g_mmi_dss_cntx.compose_chars_y,
                        composed_chars_len);

        rsp_msg->length = strlen((char*)rsp_msg->data_string);
        mmi_ucs2ncpy((S8*)(rsp_msg->data_string+rsp_msg->length), (S8*)g_mmi_dss_cntx.compose_chars, composed_chars_len);
        rsp_msg->length += composed_chars_len*ENCODING_LENGTH;

        send_msg_int(
            kal_get_active_module_id(),
            MOD_L4C,
            MSG_ID_MMI_EQ_STR_RES_REQ,
            (void *)rsp_msg,
            NULL);
    #else /* __MTK_TARGET__ */
        kal_sprintf((char*)data_string, "%d,(%d,%d),%d,", 
                        1,  /* Normal string */
                        g_mmi_dss_cntx.compose_chars_x,
                        g_mmi_dss_cntx.compose_chars_y,
                        mmi_ucs2strlen(g_mmi_dss_cntx.compose_chars));

    #ifdef ENABLE_DUMP_SCREEN_STRING_TRACE
        kal_printf(data_string);
        kal_printf("%c%c%c%c%c ...",g_mmi_dss_cntx.compose_chars[0], g_mmi_dss_cntx.compose_chars[2], 
                                    g_mmi_dss_cntx.compose_chars[4], g_mmi_dss_cntx.compose_chars[6],
                                    g_mmi_dss_cntx.compose_chars[8]);
        kal_printf(" ++++ \n");
    #endif /* ENABLE_DUMP_SCREEN_STRING_TRACE */
    #endif /* __MTK_TARGET__ */

    }

    /* Dump the screen string */
    if (g_mmi_dss_cntx.is_enable
        && (g_mmi_dss_cntx.allow_dump_screen_str
            || g_mmi_dss_cntx.allow_dump_dm_screen))
    {
        /* check if the string is the same */
        if (mmi_ucs2strlen((S8*)str) && 
            (mmi_ucs2cmp((S8*)str, g_mmi_dss_cntx.backup_string) != 0 || g_mmi_dss_cntx.y != y))
        {
            mmi_ucs2ncpy(g_mmi_dss_cntx.backup_string, (S8*)str, MMI_SCREEN_STR_MAX_LENGTH/ENCODING_LENGTH);
            g_mmi_dss_cntx.y = y;

            if (g_mmi_dss_cntx.backup_highlight_type &&
                g_mmi_dss_cntx.backup_y == y)
            {
                g_mmi_dss_cntx.highlight_type = g_mmi_dss_cntx.backup_highlight_type;
            }
            /*
            else
            {
                g_mmi_dss_cntx.backup_y = 0;
                g_mmi_dss_cntx.highlight_type = 0;
            }
            */
        #ifdef __MTK_TARGET__

            rsp_msg = (mmi_eq_str_res_req_struct *)	OslConstructDataPtr( sizeof(mmi_eq_str_res_req_struct) );
            kal_sprintf((char*)rsp_msg->data_string, "%d,(%d,%d),%d,", 
                            (g_mmi_dss_cntx.highlight_type>0)?MMI_SCREEN_HIGHLIGHT_STR:MMI_SCREEN_NORMAL_STR,
                            x, 
                            y,
                            mmi_ucs2strlen(g_mmi_dss_cntx.backup_string));
            rsp_msg->length = strlen((char*)rsp_msg->data_string);
            if((rsp_msg->length + mmi_ucs2strlen(g_mmi_dss_cntx.backup_string)*ENCODING_LENGTH) > MMI_SCREEN_STR_MAX_LENGTH)
            {
                mmi_ucs2ncpy((CHAR*)(rsp_msg->data_string+rsp_msg->length), g_mmi_dss_cntx.backup_string, MMI_SCREEN_STR_MAX_LENGTH - rsp_msg->length);
                rsp_msg->length = MMI_SCREEN_STR_MAX_LENGTH;
            }
            else
            {    
                mmi_ucs2cpy((CHAR*)(rsp_msg->data_string+rsp_msg->length), g_mmi_dss_cntx.backup_string);
                rsp_msg->length += mmi_ucs2strlen(g_mmi_dss_cntx.backup_string)*ENCODING_LENGTH;
                MMI_ASSERT(rsp_msg->length <= MMI_SCREEN_STR_MAX_LENGTH);
            }
            send_msg_int(
                kal_get_active_module_id(),
                MOD_L4C,
                MSG_ID_MMI_EQ_STR_RES_REQ,
                (void *)rsp_msg,
                NULL);
        #else  /* __MTK_TARGET__ */
            kal_sprintf((char*)data_string, "%d,(%d,%d),%d,", 
                            (g_mmi_dss_cntx.highlight_type>0)?MMI_SCREEN_HIGHLIGHT_STR:MMI_SCREEN_NORMAL_STR,
                            x, 
                            y,
                            mmi_ucs2strlen(g_mmi_dss_cntx.backup_string));

        #ifdef ENABLE_DUMP_SCREEN_STRING_TRACE
            kal_printf(data_string);
            kal_printf("%c%c%c%c%c ...",str[0], str[2], str[4], str[6], str[8]);
            kal_printf(" ++++ \n");
        #endif  /* ENABLE_DUMP_SCREEN_STRING_TRACE */
        #endif  /* __MTK_TARGET__ */
            if (g_mmi_dss_cntx.highlight_type)
            {
                g_mmi_dss_cntx.backup_highlight_type = g_mmi_dss_cntx.highlight_type;
                g_mmi_dss_cntx.backup_y = y;
            }

            gui_cancel_timer(mmi_no_more_str_hdlr);
            gui_start_timer(MMI_STR_DUMP_TIMEOUT, mmi_no_more_str_hdlr);
            ret = MMI_TRUE;
        }
    }
    g_mmi_dss_cntx.highlight_type = 0;

    if (mmi_ucs2strlen(g_mmi_dss_cntx.compose_chars))
    {
        memset(g_mmi_dss_cntx.compose_chars, 0, MMI_SCREEN_COMPOSED_CHAR_MAX_LENGTH);
        g_mmi_dss_cntx.compose_chars_x = 0;
        g_mmi_dss_cntx.compose_chars_y = 0;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_trace_screen_char
 * DESCRIPTION
 *  Sending the screen char
 *  
 * PARAMETERS
 *  x           [IN]
 *  y           [IN]
 *  unicode     [IN]
 *  len         [IN]
 *  Bordered    [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_trace_screen_char(S32 x, S32 y, U16 unicode, S32 len, S32 Bordered)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_dss_cntx.is_enable
        && (g_mmi_dss_cntx.allow_dump_screen_str
            || g_mmi_dss_cntx.allow_dump_dm_screen))
    {
    #ifdef __COMPOSE_CHAR_IN_DUMP_SCREEN_STRING__
        U8 dummy;
        S32 len;

        /* combine the separated chars to the string */
        len = mmi_ucs2strlen(g_mmi_dss_cntx.compose_chars);
        if (g_mmi_dss_cntx.compose_chars_y == y)
        {
            /* chars are at The same column */
			if ((len + 1) < (MMI_SCREEN_COMPOSED_CHAR_MAX_LENGTH/ENCODING_LENGTH))
			{
				mmi_wc_to_ucs2(
						unicode, 
						&dummy, 
						(U8*)g_mmi_dss_cntx.compose_chars + len * ENCODING_LENGTH);
				memset(g_mmi_dss_cntx.compose_chars + ((len + 1) * ENCODING_LENGTH),
					   0,
					   ENCODING_LENGTH);
			}
        }
        else
        {
            /* chars are not at The same column */
            if (len)
            {
                mmi_trace_screen_string(
                        g_mmi_dss_cntx.compose_chars_x,
                        g_mmi_dss_cntx.compose_chars_y,
                        (U8*)g_mmi_dss_cntx.compose_chars,
                        len,
                        0);
            }
            mmi_wc_to_ucs2(
                    unicode, 
                    &dummy, 
                    (U8*)g_mmi_dss_cntx.compose_chars);
            memset(g_mmi_dss_cntx.compose_chars + ENCODING_LENGTH,
                   0,
                   ENCODING_LENGTH);
            g_mmi_dss_cntx.compose_chars_x = x;
            g_mmi_dss_cntx.compose_chars_y = y;
        }
    #else
        /* Dump the separated chars directly */
        #ifdef __MTK_TARGET__
        {
            mmi_eq_str_res_req_struct *rsp_msg;

            rsp_msg = (mmi_eq_str_res_req_struct *)	OslConstructDataPtr( sizeof(mmi_eq_str_res_req_struct) );
            kal_sprintf((char*)rsp_msg->data_string, "%d,(%d,%d),1,", 0, x, y);
    
            rsp_msg->length = strlen((char*)rsp_msg->data_string);
            memcpy((S8*)(rsp_msg->data_string+rsp_msg->length), &unicode, ENCODING_LENGTH);
            rsp_msg->length += ENCODING_LENGTH;
    
            send_msg_int(
                kal_get_active_module_id(),
                MOD_L4C,
                MSG_ID_MMI_EQ_STR_RES_REQ,
                (void *)rsp_msg,
                NULL);

        }
        #else /* __MTK_TARGET__ */
        {
            U8 data_string[200];

            kal_sprintf((char*)data_string, "%d,(%d,%d),1,", 0, x, y);
        #ifdef ENABLE_DUMP_SCREEN_STRING_TRACE
            kal_printf(data_string);
            kal_printf(" %c ", unicode>>8);
            kal_printf(" %c ", unicode&0x00FF);
            kal_printf(" --- \n");
        #endif /* ENABLE_DUMP_SCREEN_STRING_TRACE */
        }
        #endif /* __MTK_TARGET__ */
    #endif /* __COMPOSE_CHAR_IN_DUMP_SCREEN_STRING__ */
        gui_cancel_timer(mmi_no_more_str_hdlr);
        gui_start_timer(MMI_STR_DUMP_TIMEOUT, mmi_no_more_str_hdlr);
        ret = MMI_TRUE;
    }
    
    return ret;
}
#endif /* __MMI_SUPPORT_DUMP_SCREEN_STRING__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_dss_clear_backup_string
 * DESCRIPTION
 *  clear back up string
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_dss_clear_backup_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
        /* Clear g_mmi_dss_cntx.backup_string */
        g_mmi_dss_cntx.backup_string[0] = 0;
        g_mmi_dss_cntx.backup_string[1] = 0;
        g_mmi_dss_cntx.allow_dump_screen_str = MMI_TRUE;
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_dss_set_menu_highlight
 * DESCRIPTION
 *  set menu highlight for dumpping screen screen(dss)
 *  
 * PARAMETERS
 *  type        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_dss_set_menu_highlight(U16 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
    g_mmi_dss_cntx.highlight_type = type;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_dss_defer_dump_string
 * DESCRIPTION
 *  Notify dump screen string(dss) mechanism if need to defer dumping string
 *  
 * PARAMETERS
 *  type        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_dss_defer_dump_string(MMI_BOOL is_deferred)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
    if (MMI_TRUE == is_deferred)
    {
        g_mmi_dss_cntx.allow_dump_screen_str = MMI_FALSE;
    }
    else
    {
        g_mmi_dss_cntx.allow_dump_screen_str = MMI_TRUE;
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_enable_str_dump
 * DESCRIPTION
 *  The message handler of MSG_ID_MMI_EQ_STR_ENABLE_REQ_IND
 *  
 * PARAMETERS
 *  void*           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_enable_str_dump(void *info)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__    
    mmi_eq_str_enable_req_ind_struct *data = (mmi_eq_str_enable_req_ind_struct *)info;
#endif    
    mmi_at_general_res_req_struct *rsp_msg;
  #ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
    kal_bool ret = KAL_TRUE;
  #else
    kal_bool ret = KAL_FALSE;
  #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  #ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
    g_mmi_dss_cntx.is_enable = (MMI_BOOL)(data->enable);
    g_mmi_dss_cntx.highlight_type = 0;
    g_mmi_dss_cntx.backup_highlight_type = 0;
    g_mmi_dss_cntx.y = 0;
    g_mmi_dss_cntx.backup_y = 0;
    g_mmi_dss_cntx.compose_chars_x = 0;
    g_mmi_dss_cntx.compose_chars_y = 0;
    memset(g_mmi_dss_cntx.backup_string, 0, MMI_SCREEN_STR_MAX_LENGTH);
  #endif /* __MMI_SUPPORT_DUMP_SCREEN_STRING__ */
    
    /* confirm the message */
    rsp_msg = (mmi_at_general_res_req_struct *)	OslConstructDataPtr( sizeof(mmi_at_general_res_req_struct) );
    rsp_msg->result = ret;

    mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_AT_GENERAL_RES_REQ, (void *)rsp_msg, NULL);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_str_cmd_ind
 * DESCRIPTION
 *  The message handler of MSG_ID_MMI_EQ_STR_REQ_IND
 *  
 * PARAMETERS
 *  void*           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_str_cmd_ind(void *info)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_str_req_ind_struct *data = (mmi_eq_str_req_ind_struct *)info;
    mmi_at_general_res_req_struct *rsp_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(data->length <= MMI_SCREEN_STR_MAX_LENGTH);
    /* process the string command here */

    /* confirm the message */
    rsp_msg = (mmi_at_general_res_req_struct *)	OslConstructDataPtr( sizeof(mmi_at_general_res_req_struct) );
    rsp_msg->result = KAL_TRUE;
    mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_AT_GENERAL_RES_REQ, (void *)rsp_msg, NULL);
#endif
}


#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
/*****************************************************************************
 * FUNCTION
 *  mmi_no_more_str_hdlr
 * DESCRIPTION
 *  Sending the termination of dumpping screen string
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_no_more_str_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    mmi_eq_str_res_req_struct *rsp_msg;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen(g_mmi_dss_cntx.compose_chars))
    {
        mmi_trace_screen_string(
                g_mmi_dss_cntx.compose_chars_x,
                g_mmi_dss_cntx.compose_chars_y,
                (U8*)g_mmi_dss_cntx.compose_chars,
                mmi_ucs2strlen(g_mmi_dss_cntx.compose_chars),
                0);
    }
    memset(g_mmi_dss_cntx.compose_chars, 0, ENCODING_LENGTH);
    g_mmi_dss_cntx.allow_dump_screen_str = MMI_FALSE;
    g_mmi_dss_cntx.highlight_type = 0;
    g_mmi_dss_cntx.backup_highlight_type = 0;
    g_mmi_dss_cntx.y = 0;
    g_mmi_dss_cntx.backup_y = 0;
    g_mmi_dss_cntx.compose_chars_x = 0;
    g_mmi_dss_cntx.compose_chars_y = 0;
#ifdef __MTK_TARGET__
    rsp_msg = (mmi_eq_str_res_req_struct *)	OslConstructDataPtr( sizeof(mmi_eq_str_res_req_struct) );
    kal_sprintf((char*)rsp_msg->data_string, "%d", MMI_SCREEN_NO_STR);
    rsp_msg->length = strlen((char*)rsp_msg->data_string);
    mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_EQ_STR_RES_REQ, (void *)rsp_msg, NULL);
#else /* __MTK_TARGET__ */
  #ifdef ENABLE_DUMP_SCREEN_STRING_TRACE
    kal_printf("\n <<END>> \n");
  #endif
#endif /* __MTK_TARGET__ */
}
#endif 


/*****************************************************************************
 *
 *  Inject String Module and screen id report
 *
 *****************************************************************************/

/***************************************************************************** 
* Typedef
*****************************************************************************/
typedef enum
{
    MMI_FRM_REPORT_SCREEN_STATE_PASSIVE,   /* only report screen id when receiving request command */
    MMI_FRM_REPORT_SCREEN_STATE_AUTO,      /* only report popup screen id in active */
    MMI_FRM_REPORT_SCREEN_STATE_ACTIVE,    /* report all screen id in active */
    MMI_FRM_REPORT_SCREEN_STATE_MAX
}mmi_frm_report_screen_state_enum;


/***************************************************************************** 
* Local function declaration
*****************************************************************************/


/***************************************************************************** 
* Global Variable
*****************************************************************************/
static mmi_frm_report_screen_state_enum mmi_frm_report_screen_state = MMI_FRM_REPORT_SCREEN_STATE_PASSIVE;

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_init_inject_string
 * DESCRIPTION
 *  This function will process injection string
 * CALLS
 *  
 * PARAMETERS
 *  inject_str      [IN]        Injection string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_init_inject_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_frm_set_protocol_event_handler(MSG_ID_TST_INJECT_STRING, mmi_proc_inject_string, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EQ_AT_QUICK_INPUT_IND, mmi_proc_at_quick_input, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_dump_screen_id
 * DESCRIPTION
 *  This function will dump active screen id
 * CALLS
 *  
 * PARAMETERS
 *  inject_str      [IN]        Injection string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_dump_screen_id(void)
{
    MMI_BOOL need_dump = MMI_FALSE;
    mmi_id   scrn_id;
    
    scrn_id = mmi_frm_scrn_get_active_id();
    switch (mmi_frm_report_screen_state)
    {
    case MMI_FRM_REPORT_SCREEN_STATE_PASSIVE:   /* only report screen id when receiving request command */
        /* do nothing */
        break;
    case MMI_FRM_REPORT_SCREEN_STATE_AUTO:      /* only report popup screen id in active */
        scrn_id = mmi_frm_scrn_get_active_id();
        if (scrn_id == POPUP_SCREENID ||
            scrn_id == SCR_POPUP_SCREEN ||
            scrn_id == SCR_CONFIRM_SCREEN)
        {
            need_dump = MMI_TRUE;
        }
        break;
    case MMI_FRM_REPORT_SCREEN_STATE_ACTIVE:    /* report all screen id in active */
        need_dump = MMI_TRUE;
        break;
    default:
        break;
    }
    
    if (need_dump)
    {
        mmi_inject_string_rsp_struct *rsp;

        rsp = (mmi_inject_string_rsp_struct*) OslConstructDataPtr(sizeof(mmi_inject_string_rsp_struct));
        rsp->scrnid = (kal_uint16)scrn_id;

        mmi_frm_send_ilm(
            MOD_L4C,
            MSG_ID_MMI_INJECT_STRING_RSP,
            (oslParaType*) rsp,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_proc_at_quick_input
 * DESCRIPTION
 *  This function will process injection string from AT command
 *  
 * PARAMETERS
 *  in           [IN]        Injection string
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_proc_at_quick_input(void * in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_at_quick_input_ind_struct *at_input = (mmi_eq_at_quick_input_ind_struct *)in;
    tst_inject_string_struct inject_str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inject_str.index = 10;
    //inject_str.string = at_input->string;
    kal_mem_cpy(inject_str.string, at_input->string, sizeof(at_input->string));

    return mmi_proc_inject_string(&inject_str);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_proc_inject_string
 * DESCRIPTION
 *  This function will process injection string
 * CALLS
 *  
 * PARAMETERS
 *  inject_str      [IN]        Injection string
 * RETURNS
 *  void
 *****************************************************************************/
 #ifdef __USB_MMI_DEBUG__

extern  void srv_usb_ut(U8 index);  
#endif
U8 mmi_proc_inject_string(void * in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tst_inject_string_struct *inject_str = (tst_inject_string_struct *)in;
    U32 i;

#ifdef SG_UT
    const char *sg_ut = "SG_UT";
#endif
#ifdef __BT_DIALER_SUPPORT__
    const char *btdialer = "BTD_";
#endif

#ifdef __BT_MAP_CLIENT__
    const char *btmapc = "BTM_";
    const char *btsms = "sms";
#endif

#ifdef __BT_PBAP_CLIENT__
    const char *btpbabc = "BTP_";
    const char *btsrvphb = "PBAPC_";
#endif
#ifdef __MMI_SCR_UT__
    const char *scrn_h  = "SCRN_UT";
#endif
#ifdef ENHANCE_HISTORY_UNIT_TEST
    const char *history_test_case = "HISTORY_UT";
#endif
#ifdef APPLIB_MEM_UNIT_TEST
    const char *asm_ut = "ASM_UT";
    const char *asm_manual_ut = "ASM_MUT";
#endif
#ifdef APPLIB_MEM_UNIT_TEST
    const char *pen_ut = "PEN_UT";
#endif
#ifdef MMI_CB_MGR_UT
        const char *cbmgr_ut = "CB_MGR_UT";
#endif
#ifdef KEY_EVENT_UNIT_TEST
    const char *key_ut = "KEY_UT";
    const char *key_tone_ut = "KEY_TONE_UT";
#endif
#ifdef TOUCH_SCREEN_UNIT_TEST
        const char *pen_ut = "PEN_UT";
#endif  

    const char *turn_on_keymap_auto_test = "TURN_ON_KEYMAP_AUTO_TEST";

    const char *turn_off_keymap_auto_test = "TURN_OFF_KEYMAP_AUTO_TEST";
#ifdef MMI_NOTI_MGR_UT
        const char *noti_mgr_ut = "NOTI_MGR_UT";
#endif /* MMI_NOTI_MGR_UT */
    
#ifdef __MMI_FRM_STRING_UT__
        const char *app_str_ut = "APP_STR_UT";
#endif /* __MMI_FRM_STRING_UT__ */
#if defined __VENUS_UI_ENGINE__ /*Only triggered if __VFX_HEAP_PROFILE__ defined in vfx_config.h*/
        const char *vfx_heap_overall_profile_str = "VFX_HEAP_OVERALL_PROFILE";
        const char *vfx_heap_remaining_alloc_str = "VFX_HEAP_REMAINING_ALLOC";
#endif /* __VENUS_UI_ENGINE__ */
#ifdef __USB_MMI_DEBUG__

    const char *usb_ut = "USB";  
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  //  extern void srv_sensor_pxs_ut(int idx); 

    /*generic string handler */
    for (i=0; i<sizeof(mmi_inject_string_str_hdlr_table)/sizeof(mmi_inject_string_str_hdlr_table_struct); i++)
    {
        if (strncmp((const kal_char *)inject_str->string, 
                    mmi_inject_string_str_hdlr_table[i].str, 
                    strlen(mmi_inject_string_str_hdlr_table[i].str)) == 0)
        {
            if (mmi_inject_string_str_hdlr_table[i].hdlr)
                mmi_inject_string_str_hdlr_table[i].hdlr(inject_str->index);
            return 0;
        }
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#ifdef __USB_MMI_DEBUG__

    if (strncmp((const kal_char*)inject_str->string, usb_ut, strlen(usb_ut)) == 0)
    {
        srv_usb_ut(inject_str->index);
    }

#endif

#ifdef __BT_DIALER_SUPPORT__
    if (strncmp((const kal_char*)inject_str->string, btdialer, strlen(btdialer)) == 0)
    {
        mmi_bt_proc_inject_string(inject_str->index, (kal_uint8 *)inject_str->string);
    }
#endif

#ifdef __BT_MAP_CLIENT__
    if (strncmp((const kal_char*)inject_str->string, btmapc, strlen(btmapc)) == 0)
    {
        mmi_bt_mapc_proc_inject_string(inject_str->index, (kal_uint8 *)inject_str->string);
    }
    else if (strncmp((const kal_char*)inject_str->string, btsms, strlen(btsms)) == 0)
    {
        srv_sms_btmapc_ut_handle(inject_str->index, (kal_uint8 *)inject_str->string);
    }
#endif

#ifdef __BT_PBAP_CLIENT__
    if (strncmp((const kal_char*)inject_str->string, btpbabc, strlen(btpbabc)) == 0)
    {
        mmi_bt_pbap_proc_inject_string(inject_str->index, (kal_uint8 *)inject_str->string);
    }
    if (strncmp((const kal_char*)inject_str->string, btsrvphb, strlen(btsrvphb)) == 0)
    {
        srv_phb_pbapc_proc_inject_string(inject_str->index, (kal_uint8 *)(inject_str->string + strlen(btsrvphb)));
    }
#endif

#ifdef SG_UT
    if (strncmp((const kal_char*)inject_str->string, sg_ut, strlen(sg_ut)) == 0)
    {
        mmi_frm_sg_ut(inject_str->index);
    }
#endif
#ifdef __MMI_SCR_UT__
    if (strncmp((const kal_char*)inject_str->string, scrn_h, strlen(scrn_h)) == 0)
    {
        mmi_frm_hs_ut(inject_str->index);
    }    
#endif
#ifdef TOUCH_SCREEN_UNIT_TEST
        kal_prompt_trace(MOD_MMI, "[PEN_UT] Starting....");
        if (strncmp((const kal_char*)inject_str->string, pen_ut, strlen(pen_ut)) == 0)
        {
            mmi_frm_touch_screen_ut(inject_str->index);
        }
        kal_prompt_trace(MOD_MMI, "[PEN_UT] Finished.");
#endif /* TOUCH_SCREEN_UNIT_TEST */
#ifdef ENHANCE_HISTORY_UNIT_TEST
    if (strncmp((const kal_char*)inject_str->string, history_test_case, strlen(history_test_case)) == 0)
    {
        mmi_frm_history_test_case_entry(inject_str->index);
    }
#endif /* ENHANCE_HISTORY_UNIT_TEST */
#ifdef APPLIB_MEM_UNIT_TEST
    if (strncmp((const kal_char *)inject_str->string, asm_ut, strlen(asm_ut)) == 0)
    {
        mmi_frm_asm_test_case_entry(inject_str->index);
    }
    else if (strncmp((const kal_char *)inject_str->string, asm_manual_ut, strlen(asm_manual_ut)) == 0)
    {
        mmi_frm_appmem_ut_entry();
    }
#endif /* APPLIB_MEM_UNIT_TEST */
#ifdef MMI_PEN_UT
    if (strncmp((const kal_char *)inject_str->string, pen_ut, strlen(pen_ut)) == 0)
    {
        mmi_frm_pen_ut_test_fetch_pen_event();
    }
#endif /* MMI_PEN_UT */
#ifdef MMI_CB_MGR_UT
    if (strncmp((const kal_char*)inject_str->string, cbmgr_ut, strlen(cbmgr_ut)) == 0)
    {
        mmi_cb_manager_ut_entry(inject_str->index);
    }
#endif
#ifdef KEY_EVENT_UNIT_TEST
    if (strncmp((const kal_char *)inject_str->string, key_ut, strlen(key_ut)) == 0)
    {
        mmi_frm_key_event_ut(inject_str->index);
    }
    if (strncmp((const kal_char *)inject_str->string, key_tone_ut, strlen(key_ut)) == 0)
    {
        mmi_frm_key_tone_ut(inject_str->index);
    }
#endif
#ifdef __MMI_FRM_STRING_UT__
    if (strncmp((const kal_char *)inject_str->string, app_str_ut, strlen(app_str_ut)) == 0)
    {
		extern void mmi_frm_string_ut(kal_uint8 index);
        mmi_frm_string_ut(inject_str->index);
    }
#endif /* __MMI_FRM_STRING_UT__ */

#ifdef MMI_NOTI_MGR_UT
    if (strncmp((const kal_char *)inject_str->string, noti_mgr_ut, strlen(noti_mgr_ut)) == 0)
    {
        mmi_frm_noti_mgr_test_case_entry(inject_str->index);
    }
#endif /* MMI_NOTI_MGR_UT */
#if defined __VENUS_UI_ENGINE__ /*Only triggered if __VFX_HEAP_PROFILE__ defined in vfx_config.h*/
    if (strncmp((const kal_char *)inject_str->string, vfx_heap_overall_profile_str, strlen(vfx_heap_overall_profile_str)) == 0)
    {
        vfx_heap_profiling_overall_output(inject_str->index);
    }
    if (strncmp((const kal_char *)inject_str->string, vfx_heap_remaining_alloc_str, strlen(vfx_heap_remaining_alloc_str)) == 0)
    {
        vfx_sys_dbg_mem_pool_remaining_output(inject_str->index);
    }
#endif /* __VENUS_UI_ENGINE__ */

    if (strncmp((const kal_char*)inject_str->string, turn_on_keymap_auto_test, strlen(turn_on_keymap_auto_test)) == 0)
    {
        mmi_imc_config_keymap_auto_test(MMI_TRUE);
    }

    if (strncmp((const kal_char*)inject_str->string, turn_off_keymap_auto_test, strlen(turn_off_keymap_auto_test)) == 0)
    {
        mmi_imc_config_keymap_auto_test(MMI_FALSE);
    }

    /* the index 0~3(MMI_FRM_REPORT_SCREEN_STATE_MAX) was reserved for "mtk+config" */

    /*generic index handler */
    for (i=0; i<sizeof(mmi_inject_string_idx_hdlr_table)/sizeof(mmi_inject_string_idx_hdlr_table_struct); i++)
    {
        if ((mmi_inject_string_idx_hdlr_table[i].start_idx <= inject_str->index) &&
            (inject_str->index <= mmi_inject_string_idx_hdlr_table[i].end_idx))
        {
            if (mmi_inject_string_idx_hdlr_table[i].hdlr)
                mmi_inject_string_idx_hdlr_table[i].hdlr(inject_str->index, inject_str->string);
            return 0;
        }
    }

    switch(inject_str->index)
    {
        /* index 10~13 are for direct input */
        case 10:
        case 11:
        case 12:
        case 13:
        #ifdef __MMI_VUI_ENGINE__
            if (vadp_p2v_uc_is_in_venus())
            {
                vadp_p2v_editor_direct_input(inject_str->index, (U16 *)inject_str->string);
            }
            else
        #endif
            {
                mmi_direct_input_from_tst_module(inject_str->index, inject_str->string);
            }
            break;
            
    #ifdef __MMI_SCREEN_SWITCH_EFFECT__
        case 20:
            /* disable screen switch effect */
           PhnsetSetScreenSwitchEffectStatus((mmi_phnset_sse_status_enum)MMI_FALSE);
            break;    
        case 21:
            /* enable screen switch effect */
           PhnsetSetScreenSwitchEffectStatus((mmi_phnset_sse_status_enum)MMI_TRUE);
            break;    
    #endif /* __MMI_SCREEN_SWITCH_EFFECT__ */      
    
    #ifdef GUI_INPUT_BOX_CACHE_SUPPORT
        case 60: 
            if (strcmp((const kal_char*)inject_str->string, "on") == 0)
            {
                gui_inputs_cache_switch(0);
            }
            else if (strcmp((const kal_char*)inject_str->string, "off") == 0)
            {
                gui_inputs_cache_switch(1);
            }
            break;
    #endif

    #ifdef __SMS_R8_NATION_LANGUAGE__
        case 61:
            {
                S32 mode;

                mode = (S32)(inject_str->string[0] - '0');
                mmi_7bit_change_table_mechanism_by_catcher(mode);
            }
            break;
    #endif 

    #ifdef __MMI_EDITOR_SSP_SUPPORT__
        case 62:
            {
                S32 mux, len;

                mmi_ucs2toi((const char *)inject_str->string, &mux, &len);
                gui_input_box_ssp_change_speed_multiple(mux);
            }
            break;

        case 63:
            {
                S32 mux, len;
                
                mmi_ucs2toi((const char *)inject_str->string, &mux, &len);
                gui_input_box_ssp_change_parabolic_model(mux);
            }
            break;
    #endif 

    #ifdef __MMI_VECTOR_FONT_SUPPORT__
        case 64:
            {
                mmi_fe_cache_print_all();
            }
            break;
    #endif 

        /* Set default encoding type from catcher */    
        case 100:
            mmi_chset_set_default_encoding_type((const kal_int8*)inject_str->string);
            break;
            
#ifdef __SPA_SUPPORT__
        case 70:
        case 71:
        case 72:
        case 73:
        case 74:
        case 75:
        case 76:
            mmi_spa_inject_string_hdlr(inject_str->index, (kal_uint8*)inject_str->string);
            break;
#endif /* __SPA_SUPPORT__ */

        default:
            /* We could parser the string to execute the different actions. */
            if (strcmp((const kal_char*)inject_str->string, "mtk+scrnid?") == 0)
            {
                mmi_frm_report_screen_state_enum org_setting = mmi_frm_report_screen_state;
                
                mmi_frm_report_screen_state = MMI_FRM_REPORT_SCREEN_STATE_ACTIVE;
                mmi_frm_dump_screen_id();
                mmi_frm_report_screen_state = org_setting;
            }
            else if (strcmp((const kal_char*)inject_str->string, "mtk+config") == 0)
            {
                if (inject_str->index < MMI_FRM_REPORT_SCREEN_STATE_MAX)
                {
                    mmi_frm_report_screen_state = (mmi_frm_report_screen_state_enum)inject_str->index;
                }
                return 0;
            }
            break;
    }
    return 0;
}


#if defined(__OP11_ATK__) || defined(__AUTO_ATK__)

#if defined(__MRE_AM__) && !defined(__COSMOS_MMI__)
#include "AMGprot.h"
#endif
#include "med_smalloc.h"
#include "FileMgrSrvGProt.h"
#ifdef __J2ME__
#include "JavaAgencyGProt.h"
#endif
#include "IdleGProt.h"


/* get ram usage begin */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 type;     /* memory type reserved for future use */
} mmi_frm_ram_usage_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    result;   /* 0 :ok; other value :error */
    kal_uint32  used_count;
} mmi_frm_ram_usage_rsp_struct;

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_at_ram_usage_ind_hdlr
 * DESCRIPTION
 *  This is the protocal event handler of MSG_ID_MMI_EQ_RAM_USAGE_REQ_IND
 *
 * PARAMETERS
 *  para    :[IN]  local parameter of the message MSG_ID_MMI_EQ_RAM_USAGE_REQ_IND
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_frm_at_ram_usage_ind_hdlr(void *para, int src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_asm_mem_detail_info_struct app_asm;
    size_type med_used;
    U32 mem_used;    
    mmi_frm_ram_usage_rsp_struct *local;
    mmi_frm_ram_usage_req_struct *p = (mmi_frm_ram_usage_req_struct *)para;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&app_asm, 0, sizeof(app_asm));
    applib_mem_asm_get_detail_info(&app_asm, MMI_FRM_MEM_APP_ASM);
    med_used = med_ext_used_size();
    
    mem_used = app_asm.total_used_size + med_used;

    local = (mmi_frm_ram_usage_rsp_struct *)mmi_construct_msg_local_para(sizeof(mmi_frm_ram_usage_rsp_struct));
    local->result = 0;
    local->used_count = mem_used;
    mmi_frm_send_ilm(
        src_mod,
        MSG_ID_MMI_EQ_RAM_USAGE_RES_REQ,
        (local_para_struct *)local,
        NULL);

    return MMI_TRUE;
}
/* get ram usage end */


/* launch Java or MRE application begin */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   type;                               /* 0 :launch java application, 1 :launch MRE application */
    kal_uint8   mids_idx;                           /* for Java application */
    kal_uint16  midlet_idx;                         /* for Java application */
    kal_uint8   mode;                               /* 1 :Launch Java application for ATK */
    kal_uint16  appName[SRV_FMGR_PATH_MAX_LEN + 1]; /* MRE application full path name */
} mmi_frm_lauch_app_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    result;   /* 0:ok; other value:error */
} mmi_frm_lauch_app_rsp_struct;


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_at_lauch_app_ind_hdlr
 * DESCRIPTION
 *  This is the protocal event handler of MSG_ID_MMI_EQ_LAUNCH_APP_REQ_IND
 *
 * PARAMETERS
 *  para    :[IN]  local parameter of the message MSG_ID_MMI_EQ_LAUNCH_APP_REQ_IND
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_frm_at_lauch_app_ind_hdlr(void *para, int src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_lauch_app_req_struct *p = (mmi_frm_lauch_app_req_struct *)para;
    MYQUEUE message;
    mmi_frm_lauch_app_rsp_struct *local;
    kal_int8 result = 0;
    char app_name[21];
    kal_int32 len;
    kal_int8 asc_buf[15];
    kal_uint16 temp_buf[15];
    kal_uint16 ucs_buf[21];
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_idle_is_active())
    {
        result = 1; /* error code */
    }
    else
    {
        if (p->type == 1)
        {
        #if defined(__MRE_AM__) && !defined(__COSMOS_MMI__)
            mmi_am_start_from_fm(p->appName);   /* launch MRE application */
        #endif
        }
        else if (p->type == 0)
        {
            memset(asc_buf, 0, sizeof(asc_buf));
            memset(temp_buf, 0, sizeof(temp_buf));
            memset(ucs_buf, 0, sizeof(ucs_buf));

            sprintf(asc_buf, " %d %d %d", p->mids_idx, p->midlet_idx, 1);
            mmi_asc_to_ucs2((CHAR *)temp_buf, (CHAR *)asc_buf);
            mmi_ucs2cpy((CHAR *)ucs_buf, (CHAR *)L"Launch");
            mmi_ucs2cat((CHAR *)ucs_buf, (CHAR *)temp_buf);

            len = mmi_ucs2strlen((CHAR *) ucs_buf) + 1;
            mmi_chset_ucs2_to_utf8_string(app_name, len, (kal_uint8 *)ucs_buf);
        #ifdef __J2ME__
            result = mmi_java_execute_cmd(app_name);    /* launch Java application */
        #endif
        }
    }

    local = (mmi_frm_lauch_app_rsp_struct *)mmi_construct_msg_local_para(sizeof(mmi_frm_lauch_app_rsp_struct));
    local->result = result;
    message.oslMsgId = MSG_ID_MMI_EQ_LAUNCH_APP_RES_REQ;
    message.oslDataPtr = (local_para_struct *)local;
    message.oslPeerBuffPtr = NULL;
    message.oslSrcId = MOD_MMI;
    message.oslDestId = src_mod;
    mmi_msg_send_ext_queue(&message);
    
    return MMI_TRUE;
}
/* launch Java or MRE application end */


/* standard output and error log begin */
#define MMI_FRM_OUTPUT_INFO_MAX_LENGTH  1000

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 type;     /* 0:error log; 1:standard output */
    kal_uint8 enable;   /* 0:disable; 1:enable */
} mmi_frm_app_info_output_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   type;   /* 0:error log; 1:standard output */
    kal_uint16  output_info[MMI_FRM_OUTPUT_INFO_MAX_LENGTH];
} mmi_frm_app_info_output_rsp_struct;

typedef enum
{
	TRACE_TYPE_ERROR,
	TRACE_TYPE_STANDARD,
	TRACE_TYPE_TOTAL
} mmi_trace_type_enum;

typedef struct
{
    module_type scr_mod;
    MMI_BOOL    trace_enable[TRACE_TYPE_TOTAL];
} mmi_frm_app_info_output_cntx_struct;

static mmi_frm_app_info_output_cntx_struct g_output_info;
static mmi_frm_app_info_output_cntx_struct *g_output_info_p = &g_output_info;

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_at_app_info_output_ind_hdlr
 * DESCRIPTION
 *  This is the protocal event handler of MSG_ID_MMI_EQ_APP_INFO_OUTPUT_REQ_IND
 *
 * PARAMETERS
 *  para    :[IN]  local parameter of the message MSG_ID_MMI_EQ_APP_INFO_OUTPUT_REQ_IND
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_frm_at_app_info_output_ind_hdlr(void *para, int src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_app_info_output_req_struct *p = (mmi_frm_app_info_output_req_struct *)para;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p->type == 0)
    {
        if (p->enable == 0)
        {
            g_output_info_p->trace_enable[TRACE_TYPE_ERROR] = MMI_FALSE;
        }
        else
        {
            g_output_info_p->trace_enable[TRACE_TYPE_ERROR] = MMI_TRUE;
        }
    }
    else
    {
        if (p->enable == 0)
        {
            g_output_info_p->trace_enable[TRACE_TYPE_STANDARD] = MMI_FALSE;
        }
        else
        {
            g_output_info_p->trace_enable[TRACE_TYPE_STANDARD] = MMI_TRUE;
        }
    }
    
    g_output_info_p->scr_mod = src_mod;

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_send_at_app_info_output_res_req
 * DESCRIPTION
 *  Get app output and send it to L4C
 *
 * PARAMETERS
 *  app_type    :[OUT]  0 is Java application and 1 is MRE application
 *  trace_type  :[OUT]  0 is error log and 1 is standard output
 *  length      :[OUT]  ucs2 encoded message bytes number include terminate character
 *  output      :[OUT]  output message which is encoded with UCS2
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_frm_send_at_app_info_output_res_req(kal_uint8 app_type, kal_uint8 trace_type, kal_uint16 length, kal_uint8 *output)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_frm_app_info_output_rsp_struct *local;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (trace_type == 0)
    {
        if (g_output_info_p->trace_enable[TRACE_TYPE_ERROR] == MMI_FALSE)
        {
            return MMI_TRUE;
        }
    }
    else
    {
        if (g_output_info_p->trace_enable[TRACE_TYPE_STANDARD] == MMI_FALSE)
        {
            return MMI_TRUE;
        }
    }

    MMI_ASSERT(length <= MMI_FRM_OUTPUT_INFO_MAX_LENGTH);
    local = (mmi_frm_app_info_output_rsp_struct *)mmi_construct_msg_local_para(sizeof(mmi_frm_app_info_output_rsp_struct));
    local->type = trace_type;
    //local->length = length;
    mmi_ucs2cpy((CHAR *)local->output_info, output);

    message.oslMsgId = MSG_ID_MMI_EQ_APP_INFO_OUTPUT_RES_REQ;
    message.oslDataPtr = (local_para_struct *)local;
    message.oslPeerBuffPtr = NULL;
    
    if (app_type == 0)
    {
        message.oslSrcId = MOD_J2ME;
    }
    else if (app_type == 1)
    {
        message.oslSrcId = MOD_MMI;
    }
    
    message.oslDestId = g_output_info_p->scr_mod;
    mmi_msg_send_ext_queue(&message);

    return MMI_TRUE;
}
/* standard output and error log end */

#endif /* defined(__OP11_ATK__) || defined(__AUTO_ATK__) */

