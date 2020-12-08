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
 * WgtMgrSrvMain.c
 *
 * Project:
 * --------
 * MAUI
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
 * removed!
 * removed!
 * removed!
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
/************************************************************************/
/* Include Header                                                       */
/************************************************************************/
//#include "MMI_include.h"

#ifdef __GADGET_SUPPORT__
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "fs_type.h"
#include "fs_func.h"
#include "mmi_frm_nvram_gprot.h"
#include "GlobalResDef.h"
#include "PixcomFontEngine.h"
#include "string.h"
#include "mmi_frm_mem_gprot.h"
#include "DebugInitDef_Int.h"
#include "widget_adp_struct.h"
#include "stack_config.h"
#include "app_str.h"
#include "WgtMgrSrvGprot.h"
#include "WgtMgrSrvIprot.h"
#include "WgtMgrSrv.h"
#include "widget_api.h"
#include "certman_api.h"
#include "FileMgrSrvGProt.h"
#include "cbm_consts.h"
#include "gadget_adp_avplugin.h"
#include "DtcntSrvGprot.h"
#include "cbm_api.h"
#include "custom_data_account.h"
#include "UsbSrvGProt.h"
#include "mmi_rp_srv_wgtmgr_def.h"
#include "fs_errcode.h"
#include "mmi_rp_srv_dtcnt_def.h"
#include "MMI_features.h"
#include "mmi_rp_app_usbsrv_def.h"
#include "app_datetime.h"
#include "USBSrvGprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "custom_gadget_config.h"
#include "CbmSrvGprot.h"

#ifdef __PLUTO_MMI_PACKAGE__
#include "mmi_rp_app_wgtmgr_def.h"
#endif

#ifdef __PLUTO_MMI_PACKAGE__
#include "vapp_hs_def.h"
#include "vadp_p2v_hs.h"
#endif

#include "gadget_adp_log.h"

/************************************************************************/
/* Structure and Definition                                             */
/************************************************************************/
typedef enum
{
    SRV_WGTMGR_CHECK_WHILE_BOOT_UP,
    SRV_WGTMGR_CHECK_ALL_DOWNLOADED_WGT,
    SRV_WGTMGR_CHECK_ALL_MEMCARD_WGT
} srv_wgtmgr_check_mode_enum;


/************************************************************************/
/* Internal Function Declaration                                        */
/************************************************************************/
static S32 srv_wgtmgr_get_enabled_wgt_int(srv_wgtmgr_wgt_list_struct *list_ptr);
static void srv_wgtmgr_quick_sort(S32 left, S32 right);
static S32 srv_wgtmgt_sort_partition(S32 left, S32 right);
static void srv_wgtmgt_switch_position(S32 i, S32 j);
static S32 srv_wgtmgr_sort_compare_by_name(S32 left, S32 right);
static S32 srv_wgtmgr_sort_compare_by_installed_time(S32 left, S32 right);
static void srv_wgtmgr_check_all_downloaded_wgt(void);
static void srv_wgtmgr_check_all_downloaded_wgt_int(srv_wgtmgr_wgt_item_struct *dwgt_info, srv_wgtmgr_check_mode_enum mode);
static void srv_wgtmgr_memcard_insert_hdlr(void);
static void srv_wgtmgr_dtcnt_ready_callback(void);
static MMI_BOOL srv_wgtmgr_is_stamp_file_valid(S32 id);
static srv_wgtmgr_result_enum srv_wgtmgr_check_downloaded_wgt_int(S32 id);
mmi_ret srv_wgtmgr_bearer_event_notify_hdlr(mmi_event_struct *param);

/************************************************************************/
/* External Function Declaration                                        */
/************************************************************************/
extern void gadget_adp_mgr_get_engine_version(char *version);
extern void widget_unload_widget(int instance_id);

/************************************************************************/
/* Golbal Variable                                                      */
/************************************************************************/
const WCHAR g_srv_wgtmgr_folder[] = SRV_WGTMGR_FOLDER;
const WCHAR g_srv_wgtmgr_name_data[] = SRV_WGTMGR_NAME_DATA_FILE;
const WCHAR g_srv_wgtmgr_name_guard[] = SRV_WGTMGR_NAME_GUARD_FILE;
const WCHAR g_srv_wgtmgr_version_data[] = SRV_WGTMGR_VERSION_DATA_FILE;
const WCHAR g_srv_wgtmgr_version_guard[] = SRV_WGTMGR_VERSION_GUARD_FILE;
const WCHAR g_srv_wgtmgr_memcard_wgt_icon[] = SRV_WGTMGR_MEMCARD_WGT_ICON;
#ifdef __WGTMGR_SAVE_ICON_FILE__
const WCHAR g_srv_wgtmgr_icon_folder[] = SRV_WGTMGR_ICON_FOLDER;
#endif

static const unsigned char g_srv_wgt_memcard_wgt_icon_data[] = 
{
#ifdef __PLUTO_MMI_PACKAGE__
#ifdef __MMI_MAINLCD_320X480__
#include "mem_widget_icon_big.png.hex"
#else
#include "mem_widget_icon.png.hex"
#endif
#else
#include "cosmos_widget_icon.png.hex"
#endif
}; 

static srv_wgtmgr_cntx_struct g_srv_wgtmgr_cntx;
srv_wgtmgr_cntx_struct *g_srv_wgtmgr_cntx_p = &g_srv_wgtmgr_cntx;

srv_wgtmgr_sort_compare_func_type g_srv_wgtmgr_sort_compare_func;

/************************************************************************/
/* Local Function Definition                                                  */
/************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_enabled_wgt_int
 * DESCRIPTION
 *  this function is used to get id list of enabled widget 
 * PARAMETERS
 *  list_ptr : [OUT] the buffer to store id list 
 * RETURNS
 *  number of enabled widgets
 *****************************************************************************/
static S32 srv_wgtmgr_get_enabled_wgt_int(srv_wgtmgr_wgt_list_struct *list_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, num = 0;
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;	
    U8 *wgt_status_p;
#ifdef __WGTMGR_MGR_PHONE_WIDGET__
    S32 *pwgt_id_p = cntx_p->pwgt_id;
#endif	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* get number of enabled phone widget */
#ifdef __WGTMGR_MGR_PHONE_WIDGET__
    wgt_status_p = cntx_p->pwgt_status;
    for (i = 0; i < SRV_WGTMGR_MAX_PHONE_WGT_NUM; i++)
    {
        if (wgt_status_p[i] == SRV_WGTMGR_WGT_STATUS_ENABLED) 
      	{
            if (list_ptr != NULL)
            {
                list_ptr[num].type = SRV_WGTMGR_WGT_TYPE_PHONE;
                list_ptr[num].id = pwgt_id_p[i];
            }
            num++;
        }
    }
#endif
    /* if the phone is in mass storage mode, we don't have to provide 
	   downloaded widget info */
#if 0
#ifdef __USB_IN_NORMAL_MODE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

    wgt_status_p = cntx_p->dwgt_status;

    /* get number of enabled downloaded widget */
    for (i = 0; i < SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM; i++)
    {
        if (wgt_status_p[i] == SRV_WGTMGR_WGT_STATUS_ENABLED) 
      	{
            if (list_ptr != NULL)
            {
                list_ptr[num].type = SRV_WGTMGR_WGT_TYPE_DOWNLOADED;
                list_ptr[num].id = i;
            }
            num++;
        }
    }
    return num;

}

/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_mainmenu_wgt_int
 * DESCRIPTION
 *  this function is used to get id list of enabled widget 
 * PARAMETERS
 *  list_ptr : [OUT] the buffer to store id list 
 * RETURNS
 *  number of enabled widgets
 *****************************************************************************/
static S32 srv_wgtmgr_get_mainmenu_wgt_int(mmi_app_package_name_struct *list_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, num = 0;
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;	
    srv_wgtmgr_wgt_item_struct wgt_info;
    U8 *wgt_status_p = cntx_p->dwgt_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    /* get number of main menu downloaded widget */
    for (i = 0; i < SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM; i++)
    {
        if (wgt_status_p[i] == SRV_WGTMGR_WGT_STATUS_ENABLED)
        {
            srv_wgtmgr_read_wgt_info_from_nvram_by_id(i, &wgt_info);    
            
            if (wgt_info.attribute & SRV_WGTMGR_ATTR_MAINMENU)
            {
                if (list_ptr != NULL)
                {
                    sprintf(list_ptr[num], "widget.mtk.%d", i);
                }
                num++;
            }
        }
    }
    return num;
}

/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_quick_sort
 * DESCRIPTION
 *  This function is to sort widget with quick sort algorithm
 * PARAMETERS
 *  left:  [IN] left position 
 *  right: [IN] right position
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_wgtmgr_quick_sort(S32 left, S32 right)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 q;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (left < right)
    {
        q = srv_wgtmgt_sort_partition(left, right);
        srv_wgtmgr_quick_sort(left, q - 1);
        srv_wgtmgr_quick_sort(q + 1, right);		
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgt_sort_partition
 * DESCRIPTION
 *  This is the partition function is quick sort
 * PARAMETERS  
 *  left:  [IN] left position 
 *  right: [IN] right position
 * RETURNS
 * 
 *****************************************************************************/
static S32 srv_wgtmgt_sort_partition(S32 left, S32 right)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = left - 1;
    S32 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (j = left; j < right; j++)
    {
        if (g_srv_wgtmgr_sort_compare_func(j, right) <= 0)
        {   
            i++;
            srv_wgtmgt_switch_position(i, j);
        }
    }

    i++;    
    srv_wgtmgt_switch_position(i, right);

	return i;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgt_switch_position
 * DESCRIPTION
 *  This is the partition function is quick sort
 * PARAMETERS  
 *  i: [IN] position i
 *  j: [IN] position j
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_wgtmgt_switch_position(S32 i, S32 j)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 temp_id;
    U16 *sort_id_list_p = g_srv_wgtmgr_cntx_p->asm_data->sort_id_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_id = sort_id_list_p[i];
    sort_id_list_p[i] = sort_id_list_p[j];
    sort_id_list_p[j] = temp_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_sort_compare_by_name
 * DESCRIPTION
 *  This is the function to compare name
 * PARAMETERS
 *  left:  [IN] left position 
 *  right: [IN] right position 
 * RETURNS
 *  ret > 0 : left > right
 *  ret = 0 : left = right
 *  ret < 0 : left < right
 *****************************************************************************/
static S32 srv_wgtmgr_sort_compare_by_name(S32 left, S32 right)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_wgt_asm_data_struct *asm_data_p = g_srv_wgtmgr_cntx_p->asm_data;
    U16 *sort_id_list_p = asm_data_p->sort_id_list;
    WCHAR *left_name_p = NULL;
    WCHAR *right_name_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    left_name_p = asm_data_p->dwgt_name[sort_id_list_p[left]];
    right_name_p = asm_data_p->dwgt_name[sort_id_list_p[right]];
    return app_ucs2_wcsicmp(left_name_p, right_name_p);    
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_sort_compare_by_installed_time
 * DESCRIPTION
 *  This is the function to compare installed time
 * PARAMETERS
 *  left:  [IN] left position 
 *  right: [IN] right position 
 * RETURNS
 *  ret > 0 : left > right
 *  ret = 0 : left = right
 *  ret < 0 : left < right
 *****************************************************************************/
static S32 srv_wgtmgr_sort_compare_by_installed_time(S32 left, S32 right)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_wgt_item_struct *dwgt_p = g_srv_wgtmgr_cntx_p->asm_data->dwgt;
    U16 *sort_list_p = g_srv_wgtmgr_cntx_p->asm_data->sort_id_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    return (S32)dwgt_p[sort_list_p[left]].install_time - (S32)dwgt_p[sort_list_p[right]].install_time;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_check_all_downloaded_wgt
 * DESCRIPTION
 *  this funciton is used to check all downloaded widgets
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_wgtmgr_check_all_downloaded_wgt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_wgt_item_struct *dwgt_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dwgt_info = (srv_wgtmgr_wgt_item_struct*)OslMalloc(sizeof(srv_wgtmgr_wgt_item_struct) * SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM);

    /* read downloaded widget info from nvram */
    srv_wgtmgr_read_wgt_info_from_nvram(dwgt_info);

    srv_wgtmgr_check_all_downloaded_wgt_int(dwgt_info, SRV_WGTMGR_CHECK_ALL_DOWNLOADED_WGT);

    OslMfree(dwgt_info);

}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_check_downloaded_int
 * DESCRIPTION
 *  this funciton is to check all downloaded widgets
 * PARAMETERS
 *  dwgt_info: [IN] the widget info
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_wgtmgr_check_all_downloaded_wgt_int(srv_wgtmgr_wgt_item_struct *dwgt_info, srv_wgtmgr_check_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;
    U8 *dwgt_status_p = cntx_p->dwgt_status;
    U8 status = 0;
    WCHAR *icon_path, *main_view_path;
    S32 i = 0;
    U16 *delete_list_p;
    S32 num = 0;
    MMI_BOOL delete_wgt; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* we check the icon of each widget, if it is deleted and the widget is intalled in   *
     *  1. public drive: delete the widget                                                *
     *  2. memory card: (a) if memory card does not exist: disable the widget             *
     *                  (b) if memory card exists: delete the widget                      */

    icon_path = (WCHAR*) OslMalloc(SRV_WGTMGR_MAX_WGT_ICON_PATH_LEN * sizeof(WCHAR));
    main_view_path = (WCHAR*) OslMalloc(SRV_WGTMGR_MAX_WGT_MAIN_VIEW_PATH_LEN * sizeof(WCHAR));

    delete_list_p = (U16*)OslMalloc(SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM * sizeof(U16));

    if (icon_path == NULL || main_view_path == NULL || delete_list_p == NULL)
    {
        MMI_ASSERT(0);
    }

    for (i = 0; i < SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM; i++)
    {
        status = dwgt_status_p[i];
        delete_wgt = MMI_FALSE;

        if ((status == SRV_WGTMGR_WGT_STATUS_NULL && mode == SRV_WGTMGR_CHECK_WHILE_BOOT_UP) ||
            (status == SRV_WGTMGR_WGT_STATUS_DELETING) ||
            (status == SRV_WGTMGR_WGT_STATUS_UPDATING) ||
            (srv_wgtmgr_is_preinstall_widget_finished() == MMI_FALSE))
        {
            delete_wgt = MMI_TRUE;
        }
        else if (status == SRV_WGTMGR_WGT_STATUS_ENABLED)
        {
            /* get icon path */
            srv_wgtmgr_get_path(i, SRV_WGTMGR_PATH_ICON_FILE, icon_path);
            srv_wgtmgr_get_path(i, SRV_WGTMGR_PATH_MAIN_VIEW, main_view_path);

            /* check if it exists*/
            if (FS_GetAttributes(icon_path) < 0 || FS_GetAttributes(main_view_path) < 0)
            {
                srv_wgtmgr_notify_evt_struct event;
                MMI_FRM_INIT_EVENT(&event, EVT_ID_SRV_WGTMGR_FILE_NOT_EXISTS_IND);
                event.id = i;
                MMI_FRM_CB_EMIT_POST_EVENT(&event);

            #ifdef __PLUTO_MMI_PACKAGE__
                dwgt_status_p[i] = SRV_WGTMGR_WGT_STATUS_DISABLED;
            #endif
            }
       	}

        if (delete_wgt == MMI_TRUE)
        {
            delete_list_p[num] = i;
            num++;
        }
   	}

    srv_wgtmgr_save_wgt_status_to_nvram();
    if (num > 0)
    {
        srv_wgtmgr_send_delete_wgt_multiple_req(num, delete_list_p);
    }

    OslMfree(icon_path);
    OslMfree(main_view_path);
    OslMfree(delete_list_p);
}





/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_memcard_insert_hdlr
 * DESCRIPTION
 *  this funciton is to check all downloaded widgets
 * PARAMETERS
 *  drive: [IN] the specified drive
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_wgtmgr_memcard_insert_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if(srv_usb_is_in_mass_storage_mode() == MMI_TRUE)
    {
        return;
    }    
#endif

    srv_wgtmgr_check_all_downloaded_wgt();

    if (cntx_p->is_start == MMI_TRUE)
    {
        srv_wgtmgr_read_wgt_info_from_nvram(cntx_p->asm_data->dwgt);

        /* sort installed widget */
        srv_wgtmgr_sort_wgt();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_dtcnt_ready_callback
 * DESCRIPTION
 *  this funciton is to check data account
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_wgtmgr_dtcnt_ready_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;
    S32 i;
    cbm_sim_id_enum cbm_sim[] ={CBM_SIM_ID_SIM1, CBM_SIM_ID_SIM2, CBM_SIM_ID_SIM3, CBM_SIM_ID_SIM4};    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for( i = 0; i < SRV_WGTMGR_SIM_NUM; i++)
    {
        if (srv_wgtmgr_dtcnt_acct_is_valid(cntx_p->data_account[i]) == MMI_FALSE)
        {
            U32 account_id = cbm_encode_data_account_id(
                                         CBM_DEFAULT_ACCT_ID,
                                         cbm_sim[i], 
                                         cntx_p->da_app_id, 
                                         KAL_FALSE);
            U32 acct_id_out = 0;
            srv_dtcnt_get_auto_acc_id(account_id, &acct_id_out);
            
            srv_wgtmgr_set_default_data_account(i, acct_id_out);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_is_stamp_file_valid
 * DESCRIPTION
 *  This function is used to check the file's existence and validity of a widget
 * PARAMETERS
 *  id: [IN] widget id
 * RETURNS
 *  MMI_TRUE if yes
 *****************************************************************************/
static MMI_BOOL srv_wgtmgr_is_stamp_file_valid(S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
    char drive = srv_wgtmgr_get_drive_letter((srv_wgtmgr_wgt_drive_enum)g_srv_wgtmgr_cntx_p->dwgt_drive[id]);
    srv_wgtmgr_wgt_item_struct wgt_info;
    WCHAR* dst_path;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* read widget info from nvram */
    srv_wgtmgr_read_wgt_info_from_nvram_by_id(id, &wgt_info);

    /* get the file path of stamp file */
    dst_path = (WCHAR*)OslMalloc(sizeof(WCHAR) * 50);
    kal_wsprintf(dst_path, "%c:\\@gadget\\%03d\\%d", drive, id, wgt_info.install_time);

    if ( FS_GetAttributes(dst_path) >= 0 )
    {
        ret = MMI_TRUE;
    }

    OslMfree(dst_path);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_check_downloaded_wgt_int
 * DESCRIPTION
 *  this funciton is used to check a downloaded widget
 * PARAMETERS
 *  id: [IN] widget instance id
 * RETURNS
 *  error code
 *****************************************************************************/
static srv_wgtmgr_result_enum srv_wgtmgr_check_downloaded_wgt_int(S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *path;
    srv_wgtmgr_result_enum ret = SRV_WGTMGR_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_wgtmgr_is_stamp_file_valid(id) == MMI_FALSE)
    {
        return SRV_WGTMGR_RET_FILE_NOT_EXIST;
    }

    /* read downloaded widget info from nvram */
    path = (WCHAR*) OslMalloc(SRV_FMGR_PATH_MAX_LEN * sizeof(WCHAR));

    srv_wgtmgr_get_path(id, SRV_WGTMGR_PATH_ICON_FILE, path);
    if (FS_GetAttributes(path) < 0)
    {
        ret = SRV_WGTMGR_RET_FILE_NOT_EXIST;       
        goto end;
    }

    srv_wgtmgr_get_path(id, SRV_WGTMGR_PATH_MAIN_VIEW, path);
    if (FS_GetAttributes(path) < 0)
    {
        ret = SRV_WGTMGR_RET_FILE_NOT_EXIST;
        goto end;
    }

    srv_wgtmgr_get_path(id, SRV_WGTMGR_PATH_MANIFEST, path);
    if (FS_GetAttributes(path) < 0)
    {
        ret = SRV_WGTMGR_RET_FILE_NOT_EXIST;
        goto end;
    }

end:
    OslMfree(path);
    return ret;	
}



/************************************************************************/
/* Global Function Definition                                                  */
/************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_init
 * DESCRIPTION
 *  This function is used to init Widget Manager Service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 temp = 0;
    S32 i = 0;
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;
    nvram_wgtmgr_lid_struct *lid_p = NULL;
    U8* wgt_status_p;
    U8 status;
    S32 fd;
    U32 written;	
    cbm_app_info_struct info; 
    cbm_sim_id_enum cbm_sim[] ={CBM_SIM_ID_SIM1, CBM_SIM_ID_SIM2, CBM_SIM_ID_SIM3, CBM_SIM_ID_SIM4};
    static U32 init = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (init == 1)
   	{
        return;
    }

    init = 1;

    kal_mem_set(cntx_p, 0, sizeof(srv_wgtmgr_cntx_struct));

    cntx_p->system_drive = SRV_FMGR_SYSTEM_DRV;
    cntx_p->public_drive = SRV_FMGR_PUBLIC_DRV;
    cntx_p->memcard_drive = SRV_FMGR_CARD_DRV;

    /* create Z:\\@wgtmgr if necessary */
    if (FS_GetAttributes(g_srv_wgtmgr_folder) < 0)
    {
        FS_CreateDir(g_srv_wgtmgr_folder);
    }

#ifdef __WGTMGR_SAVE_ICON_FILE__
    /* create Z:\\@wgtmgr\\icon if necessary */
    if (FS_GetAttributes(g_srv_wgtmgr_icon_folder) < 0)
    {
        FS_CreateDir(g_srv_wgtmgr_icon_folder);
    }
#endif


    /* set protocol event handler */
    srv_wgtmgr_set_protocol_event_handler();

    /* read sort order from NVRAM Cache */
    ReadValue(NVRAM_WGTMGR_WGT_SORT_ORDER, &(cntx_p->sort_order), DS_BYTE, &error);
    if (cntx_p->sort_order >= SRV_WGTMGR_SORT_BY_TOTAL_NUM)
    {
        cntx_p->sort_order = SRV_WGTMGR_SORT_BY_NAME;
    }	

    /* read data account from NVRAM Cache */
    ReadValue(NVRAM_WGTMGR_WGT_DATA_ACCOUNT_FIRST, &temp, DS_SHORT, &error);
    cntx_p->data_account[SRV_WGTMGR_SIM1] = temp << 16;
    ReadValue(NVRAM_WGTMGR_WGT_DATA_ACCOUNT_LAST, &temp, DS_SHORT, &error);
    cntx_p->data_account[SRV_WGTMGR_SIM1] += temp;

    /* read data account from NVRAM Cache */
    ReadValue(NVRAM_WGTMGR_WGT_DATA_ACCOUNT_2_FIRST, &temp, DS_SHORT, &error);
    cntx_p->data_account[SRV_WGTMGR_SIM2] = temp << 16;
    ReadValue(NVRAM_WGTMGR_WGT_DATA_ACCOUNT_2_LAST, &temp, DS_SHORT, &error);
    cntx_p->data_account[SRV_WGTMGR_SIM2] += temp;

    /* read data account from NVRAM Cache */
    ReadValue(NVRAM_WGTMGR_WGT_DATA_ACCOUNT_3_FIRST, &temp, DS_SHORT, &error);
    cntx_p->data_account[SRV_WGTMGR_SIM3] = temp << 16;
    ReadValue(NVRAM_WGTMGR_WGT_DATA_ACCOUNT_3_LAST, &temp, DS_SHORT, &error);
    cntx_p->data_account[SRV_WGTMGR_SIM3] += temp;

    /* read data account from NVRAM Cache */
    ReadValue(NVRAM_WGTMGR_WGT_DATA_ACCOUNT_4_FIRST, &temp, DS_SHORT, &error);
    cntx_p->data_account[SRV_WGTMGR_SIM4] = temp << 16;
    ReadValue(NVRAM_WGTMGR_WGT_DATA_ACCOUNT_4_LAST, &temp, DS_SHORT, &error);
    cntx_p->data_account[SRV_WGTMGR_SIM4] += temp;

    //TODO: add string for cosmos
#ifdef __PLUTO_MMI_PACKAGE__
    info.app_str_id = STR_ID_WGTMGR_WIDGET_MANAGER;
#endif

#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_MAINLCD_320X480__) || defined (__COSMOS_MMI_PACKAGE__)
    info.app_icon_id = IMG_NONE;
#else
    info.app_icon_id = IMG_ID_WGTMGR_APP;
#endif
    info.app_type = (DTCNT_APPTYPE_SKIP_CSD | DTCNT_APPTYPE_NO_PX);
    cbm_register_app_id_with_app_info(&info, &cntx_p->da_app_id);

    /* register bear disconnect and switch event */
    srv_cbm_register_bearer_event(
        SRV_CBM_BEARER_EVENT_DISCONNECT | SRV_CBM_BEARER_EVENT_SWITCH, 
        cntx_p->da_app_id,
        srv_wgtmgr_bearer_event_notify_hdlr,
        NULL);

    gadget_adp_log_prompt_trace("widget app id: %d", cntx_p->da_app_id);

    for ( i = 0; i < SRV_WGTMGR_SIM_NUM; i++)
    {
        U32 account_id = 0;
        U32 acct_id_out = 0;

        if (cntx_p->data_account[i] == 0xFFFFFFFF)
        {
            account_id = cbm_encode_data_account_id(
                                     CBM_DEFAULT_ACCT_ID,
                                     cbm_sim[i], 
                                     cntx_p->da_app_id, 
                                     KAL_FALSE);

            gadget_adp_log_prompt_trace("[1]widget account id [%d]: %d", i, account_id);

            srv_dtcnt_get_auto_acc_id(account_id, &acct_id_out);
            srv_wgtmgr_set_default_data_account(i, acct_id_out);

            gadget_adp_log_prompt_trace("[2]widget account id [%d]: %d", i, acct_id_out);
        }
        else
        {
            account_id = cbm_set_app_id(cntx_p->data_account[i], cntx_p->da_app_id);
            srv_wgtmgr_set_default_data_account(i, account_id);
            
            gadget_adp_log_prompt_trace("[3]widget account id [%d]: %d", i, account_id);
        }
        
    }

    /* read network access from NVRAM Cache */
    ReadValue(NVRAM_WGTMGR_WGT_NETWORK_ACCESS, &(cntx_p->network_access), DS_BYTE, &error);
    if (cntx_p->network_access >= SRV_WGTMGR_NETWORK_ACCESS_TOTAL_NUM)
    {
        cntx_p->network_access = SRV_WGTMGR_NETWORK_ACCESS_ALLOW;
    }	

    ReadValue(NVRAM_WGTMGR_WIFI_ONLY, &(cntx_p->wifi_only), DS_BYTE, &error);
    if (cntx_p->wifi_only == 0xFF)
    {
        cntx_p->wifi_only = MMI_FALSE;
    }

    cntx_p->preferred_sim = SRV_WGTMGR_SIM1;

    /* read need_update_data flag from NVRAM Cache */
    ReadValue(NVRAM_WGTMGR_WGT_NEED_UPDATE_NAME, &(cntx_p->need_update_data), DS_BYTE, &error);

    /* check whether version data file is corrupted */
    if (FS_GetAttributes(g_srv_wgtmgr_version_guard) >= 0)
    {
        srv_wgtmgr_set_data_need_update(SRV_WGTMGR_UPDATE_VERSION);
    }

    /* read widget language from NVRAM Cache */
    ReadValue(NVRAM_WGTMGR_WGT_PHONE_LANG, &(cntx_p->wgt_lang), DS_DOUBLE, &error);

    /* check if need update widget name data */
    if ((cntx_p->need_update_data & SRV_WGTMGR_UPDATE_NAME) ||
        (FS_GetAttributes(g_srv_wgtmgr_name_guard) >= 0) ||
        (FS_GetAttributes(g_srv_wgtmgr_name_data) < 0) ||
        (strcmp(cntx_p->wgt_lang, (const char*)Get_Current_Lang_CountryCode()) != 0))
    {
        cntx_p->req_table.send_name_req = MMI_TRUE;
        strcpy(cntx_p->wgt_lang, (const char*)Get_Current_Lang_CountryCode());
        srv_wgtmgr_send_name_req();
    }


    /* allocate memory for LID */
    lid_p = (nvram_wgtmgr_lid_struct*) OslMalloc(sizeof(nvram_wgtmgr_lid_struct));
    MMI_ASSERT(lid_p);
    
    /* read record from NVRAM LID */
    srv_wgtmgr_read_lid(lid_p);

#ifdef __WGTMGR_MGR_PHONE_WIDGET__
    /* copy widget status to global context structure */
    kal_mem_cpy(cntx_p->pwgt_status, lid_p->pwgt_status, sizeof(U8) * SRV_WGTMGR_MAX_PHONE_WGT_NUM);

    vadp_p2v_hs_widget_get_all_id((S32*)cntx_p->pwgt_id, sizeof(cntx_p->pwgt_id));

    wgt_status_p = cntx_p->pwgt_status;
    for (i = 0; i < SRV_WGTMGR_MAX_PHONE_WGT_NUM; i++)
    {
        if ((wgt_status_p[i] != SRV_WGTMGR_WGT_STATUS_ENABLED) &&
            (wgt_status_p[i] != SRV_WGTMGR_WGT_STATUS_DISABLED))
        {
            wgt_status_p[i] = SRV_WGTMGR_WGT_STATUS_ENABLED;
        }	
    }
#endif

    kal_mem_cpy(cntx_p->dwgt_status, lid_p->dwgt_status, sizeof(U8) * SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM);

    wgt_status_p = cntx_p->dwgt_status;

    for (i = 0; i < SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM; i++)
    {
        status = wgt_status_p[i];
        cntx_p->dwgt_drive[i] = lid_p->dwgt[i].drive;		
        if (status >= SRV_WGTMGR_WGT_STATUS_TOTAL_NUM)
        {
            wgt_status_p[i] = SRV_WGTMGR_WGT_STATUS_NULL;
        }
		
        /* disable widgets installed in memory card if memory card does not exist */
    #ifdef __PLUTO_MMI_PACKAGE__
        if ((status == SRV_WGTMGR_WGT_STATUS_ENABLED) &&
            (lid_p->dwgt[i].drive == SRV_WGTMGR_DRIVE_MEMORY_CARD) &&
            (srv_wgtmgr_is_memcard_available() == MMI_FALSE))
        {
            wgt_status_p[i] = SRV_WGTMGR_WGT_STATUS_DISABLED;
        }
    #endif
    }

    /* check all downloaded widget folder */
    srv_wgtmgr_check_all_downloaded_wgt_int(lid_p->dwgt, SRV_WGTMGR_CHECK_WHILE_BOOT_UP);

    /* free control buffer */
    OslMfree(lid_p);

    if (FS_GetAttributes(g_srv_wgtmgr_memcard_wgt_icon) < 0)
    {
        fd = FS_Open(g_srv_wgtmgr_memcard_wgt_icon, FS_READ_WRITE | FS_CREATE | FS_OPEN_SHARED);
        FS_Write(fd, (void*)g_srv_wgt_memcard_wgt_icon_data, sizeof(g_srv_wgt_memcard_wgt_icon_data), &written);
        FS_Close(fd);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_init_evt_hdlr
 * DESCRIPTION
 *  This function is used to init Widget Manager Service
 * PARAMETERS
 *  evt : [IN] event
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_wgtmgr_init_evt_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_init();

    return MMI_RET_OK;	
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_start
 * DESCRIPTION
 *  This function is to start the native service of Widget Manager Serive
 * PARAMETERS
 *  mem_ptr : [IN] The pointer of ASM
 *  callback: [IN] The callback invoked when native service is ready
 *  user_data: [IN] The user data of application
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_start(void *mem_ptr, srv_wgtmgr_start_cb_func_ptr callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p->is_start = MMI_TRUE;

    /* set ASM */
    if (cntx_p->asm_data != NULL)
    {
        MMI_ASSERT(0);
    }

    cntx_p->asm_data = mem_ptr;
    cntx_p->cb_table.start_cb = callback;
    cntx_p->cb_table.start_cb_user_data = user_data;
    srv_wgtmgr_start_cont();	
}

/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_start_cont
 * DESCRIPTION
 *  This function is to continue to start the native service of Widget Manager Serive
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_start_cont()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;
    srv_wgtmgr_start_cb_func_ptr callback = cntx_p->cb_table.start_cb;
    void *user_data = cntx_p->cb_table.start_cb_user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx_p->is_start == MMI_FALSE)
    {
        return;
    }

    /* check if need update version file or it is updating now */
    if ((cntx_p->need_update_data & SRV_WGTMGR_UPDATE_VERSION) ||
        (FS_GetAttributes(g_srv_wgtmgr_version_guard) >= 0) ||
        (cntx_p->req_table.send_version_req == MMI_TRUE) ||
        (srv_wgtmgr_read_name_or_version_from_file(SRV_WGTMGR_UPDATE_VERSION) == MMI_FALSE))
    {
        if (cntx_p->req_table.send_version_req == MMI_FALSE)
        {
            cntx_p->req_table.send_version_req = MMI_TRUE;
            srv_wgtmgr_send_version_req();

        }
        return;
    }

    /* check if need update name file or it is updating now */
    if ((cntx_p->need_update_data & SRV_WGTMGR_UPDATE_NAME) ||
        (FS_GetAttributes(g_srv_wgtmgr_name_guard) >= 0) ||
        (strcmp(cntx_p->wgt_lang, (const char*)Get_Current_Lang_CountryCode()) != 0) ||
        (cntx_p->req_table.send_name_req == MMI_TRUE) ||
        (srv_wgtmgr_read_name_or_version_from_file(SRV_WGTMGR_UPDATE_NAME) == MMI_FALSE))
    {
        if (cntx_p->req_table.send_name_req == MMI_FALSE)
        {
            cntx_p->req_table.send_name_req = MMI_TRUE;
            strcpy(cntx_p->wgt_lang, (const char*)Get_Current_Lang_CountryCode());
            srv_wgtmgr_send_name_req();
        }
        return;
    }

    /* read widget info from nvram */
    srv_wgtmgr_read_wgt_info_from_nvram(cntx_p->asm_data->dwgt);

    /* sort installed widget */
    srv_wgtmgr_sort_wgt();

    /* invoke Widget Manager App's callback */	
    if (callback != NULL)
    {
        cntx_p->cb_table.start_cb = NULL;
        cntx_p->cb_table.start_cb_user_data = NULL;
        callback(user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_stop
 * DESCRIPTION
 *  This function is to start the native service of Widget Manager Serive
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Release asm */
    if (cntx_p->asm_data != NULL)
    {
        cntx_p->asm_data = NULL;
    }

    cntx_p->is_start = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_sort_wgt
 * DESCRIPTION
 *  This function is used to sort installed widget 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_sort_wgt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    U32 num = 0;
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;
    U16 *sort_list_p = cntx_p->asm_data->sort_id_list;
    U8 *wgt_status_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgt_status_p = cntx_p->dwgt_status;
    for (i = 0; i < SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM; i++)
    {
        if (wgt_status_p[i] == SRV_WGTMGR_WGT_STATUS_ENABLED || 
            wgt_status_p[i] == SRV_WGTMGR_WGT_STATUS_DISABLED )
        {
            sort_list_p[num] = i;
            num++;
        }
    }


    if (cntx_p->sort_order == SRV_WGTMGR_SORT_BY_INSTALLED_TIME)
    {
        g_srv_wgtmgr_sort_compare_func = srv_wgtmgr_sort_compare_by_installed_time;
    }
    else
    {
        g_srv_wgtmgr_sort_compare_func = srv_wgtmgr_sort_compare_by_name;    
    }

    srv_wgtmgr_quick_sort(0, num - 1);

}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_enable_wgt
 * DESCRIPTION
 *  This function is used to enable a widget
 * PARAMETERS
 *  type:  [IN] The widget type
 *  id  :  [IN] The widget id
 * RETURNS
 *  The result of the operation
 *****************************************************************************/
S32 srv_wgtmgr_enable_wgt(srv_wgtmgr_wgt_type_enum type, S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;	
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (srv_wgtmgr_get_enabled_wgt_num() >= SRV_WGTMGT_MAX_ENABLED_WGT_NUM)
    {
        return SRV_WGTMGR_RET_EXCEED_MAX_ENABLED_NUM;
    }

    if (type == SRV_WGTMGR_WGT_TYPE_PHONE)
    {
#ifdef __WGTMGR_MGR_PHONE_WIDGET__
        cntx_p->pwgt_status[id] = SRV_WGTMGR_WGT_STATUS_ENABLED;
#endif
    }
    else
    {
        MMI_ASSERT(id < SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM);

        /* check if the widget is installed in memory card which is not present now */
        ret = srv_wgtmgr_check_downloaded_wgt(id);

        if (ret != SRV_WGTMGR_RET_OK)
        {
            return ret;
        }
        cntx_p->dwgt_status[id] = SRV_WGTMGR_WGT_STATUS_ENABLED;
    }
    srv_wgtmgr_save_nvram_lid();
    return SRV_WGTMGR_RET_OK;
 
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_disable_wgt
 * DESCRIPTION
 *  This function is used to disable a widget
 * PARAMETERS
 *  type:  [IN] The widget type
 *  id  :  [IN] The widget id
 * RETURNS
 *  The result of the operation
 *****************************************************************************/
S32 srv_wgtmgr_disable_wgt(srv_wgtmgr_wgt_type_enum type, S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (type == SRV_WGTMGR_WGT_TYPE_PHONE)
    {
    #ifdef __WGTMGR_MGR_PHONE_WIDGET__
        cntx_p->pwgt_status[id] = SRV_WGTMGR_WGT_STATUS_DISABLED;
    #endif	
    }
    else
    {
        MMI_ASSERT(id < SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM);
        cntx_p->dwgt_status[id] = SRV_WGTMGR_WGT_STATUS_DISABLED;
        widget_unload_widget(id);
    }

    srv_wgtmgr_save_nvram_lid();
    return SRV_WGTMGR_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_wgt_num
 * DESCRIPTION
 *  This function is used to get number of widgets
 * PARAMETERS
 *  type : [IN] widget type
 * RETURNS
 *  The number of installed widgets
 *****************************************************************************/
S32 srv_wgtmgr_get_wgt_num(srv_wgtmgr_wgt_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (type == SRV_WGTMGR_WGT_TYPE_PHONE)
    {
    #ifdef __WGTMGR_MGR_PHONE_WIDGET__
        return SRV_WGTMGR_MAX_PHONE_WGT_NUM;
    #endif
    }
    else
    {
        U8 *dwgt_status_p = g_srv_wgtmgr_cntx_p->dwgt_status;	
        S32 i, num = 0;

        for (i = 0; i < SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM; i++)
        {
            if (dwgt_status_p[i] == SRV_WGTMGR_WGT_STATUS_ENABLED ||
                dwgt_status_p[i] == SRV_WGTMGR_WGT_STATUS_DISABLED) 
      	    {
                num++;
            }
        }
		return num;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_downloaded_wgt_list
 * DESCRIPTION
 *  This function is used to get total number of widgets
 * PARAMETERS
 *  type : [IN] widget type
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_get_downloaded_wgt_list(S32 *list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    for (i = 0; i < srv_wgtmgr_get_wgt_num(SRV_WGTMGR_WGT_TYPE_DOWNLOADED); i++)
    {
        list[i] = cntx_p->asm_data->sort_id_list[i];
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_enabled_wgt_num
 * DESCRIPTION
 *
 * PARAMETERS
 * 
 * RETURNS
 *
 *****************************************************************************/
S32 srv_wgtmgr_get_enabled_wgt_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    return srv_wgtmgr_get_enabled_wgt_int(NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_enabled_wgt_list
 * DESCRIPTION
 *
 * PARAMETERS
 * 
 * RETURNS
 *
 *****************************************************************************/
void srv_wgtmgr_get_enabled_wgt_list(srv_wgtmgr_wgt_list_struct *list_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    srv_wgtmgr_get_enabled_wgt_int(list_ptr);  
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_enabled_wgt_num
 * DESCRIPTION
 *
 * PARAMETERS
 * 
 * RETURNS
 *
 *****************************************************************************/
S32 srv_wgtmgr_get_mainmenu_wgt_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __WGTMGR_MAIN_MENU_SUPPORT__
    return srv_wgtmgr_get_mainmenu_wgt_int(NULL);
#else
    return 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_enabled_wgt_list
 * DESCRIPTION
 *
 * PARAMETERS
 * 
 * RETURNS
 *
 *****************************************************************************/
void srv_wgtmgr_get_mainmenu_wgt_list(mmi_app_package_name_struct *list_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#ifdef __WGTMGR_MAIN_MENU_SUPPORT__
    srv_wgtmgr_get_mainmenu_wgt_int(list_ptr);  
#else
    return ;
#endif
}



/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_downloaded_wgt_name
 * DESCRIPTION
 *  This function is used to get downloaded widget name
 * PARAMETERS
 *  id : [IN] widget id
 *  name : [OUT] buffer to store widget name
 *  size : [IN] size of buffer in byte
 * RETURNS
 *  MMI_TRUE if get name 
 *****************************************************************************/
MMI_BOOL srv_wgtmgr_get_downloaded_wgt_name(S32 id, WCHAR *name, S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset = 0;
    FS_HANDLE fd;
    U32 read;    
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id >= SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM)
    {
        ASSERT(0);
    }

    fd = FS_Open(g_srv_wgtmgr_name_data, FS_READ_ONLY);
    if (fd >= 0)
    {
        offset = sizeof(WCHAR) * id * (SRV_WGTMGR_MAX_WGT_NAME_LEN + 1);
        FS_Seek(fd, offset, FS_FILE_BEGIN);
        FS_Read(fd, name, size, &read);
        FS_Close(fd);
		return MMI_TRUE;
    }
    return MMI_FALSE;
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
#ifdef __WGTMGR_MGR_PHONE_WIDGET__
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __WGTMGR_MGR_PHONE_WIDGET__
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

/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_wgt_info
 * DESCRIPTION
 *  This is used to get the information of a widget for displaying on Widget Manager App
 * PARAMETERS
 *  type: [IN]  The widget type
 *  id  : [IN]  The widget id
 *  info: [OUT] The widget information
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_get_phone_wgt_info(S32 id, srv_wgtmgr_phone_wgt_info_struct *info)
{
#ifdef __WGTMGR_MGR_PHONE_WIDGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;
    S32 phone_wgt_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    phone_wgt_id = cntx_p->pwgt_id[id];
    info->name = vadp_p2v_hs_widget_get_name(phone_wgt_id);
    info->enabled = (cntx_p->pwgt_status[id] == SRV_WGTMGR_WGT_STATUS_ENABLED) ? MMI_TRUE : MMI_FALSE;
    info->attribute = 0;      
    if (vadp_p2v_hs_widget_need_network(phone_wgt_id) == MMI_TRUE)
   	{
        info->attribute |= SRV_WGTMGR_ATTR_NETWORK_ACCESS;
    }
#endif		
}




/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_downloaded_wgt_info
 * DESCRIPTION
 *  This is used to get the information of a widget for displaying on Widget Manager App
 * PARAMETERS
 *  type: [IN]  The widget type
 *  id  : [IN]  The widget id
 *  info: [OUT] The widget information
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_get_downloaded_wgt_info(S32 id, srv_wgtmgr_downloaded_wgt_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;
    srv_wgtmgr_wgt_asm_data_struct *asm_data_p = cntx_p->asm_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_ASSERT(cntx_p->is_start == MMI_TRUE);

    MMI_ASSERT(cntx_p->dwgt_status[id] == SRV_WGTMGR_WGT_STATUS_ENABLED ||
        cntx_p->dwgt_status[id] == SRV_WGTMGR_WGT_STATUS_DISABLED);

    info->attribute = asm_data_p->dwgt[id].attribute;
    info->enabled = (cntx_p->dwgt_status[id] == SRV_WGTMGR_WGT_STATUS_ENABLED) ? MMI_TRUE : MMI_FALSE;

    kal_wsprintf(info->size, "%d KB", asm_data_p->dwgt[id].size);
    MMI_ASSERT(app_ucs2_strlen((kal_int8 *)info->size) <= SRV_WGTMGR_MAX_WGT_SIZE_LEN);

    app_ucs2_strncpy((kal_int8 *)info->version, (const kal_int8 *)asm_data_p->version[id], SRV_WGTMGR_MAX_WGT_VERSION_LEN);
    info->version[SRV_WGTMGR_MAX_WGT_VERSION_LEN] = '\0';

    app_ucs2_strncpy((kal_int8 *)info->name, (const kal_int8 *)asm_data_p->dwgt_name[id], SRV_WGTMGR_MAX_WGT_NAME_LEN);
    info->name[SRV_WGTMGR_MAX_WGT_NAME_LEN] = '\0';

    info->install_time = asm_data_p->dwgt[id].install_time;
}



/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_is_wgt_enabled
 * DESCRIPTION
 *  This function is used to check if a widget is enabled
 * PARAMETERS
 *  type: [IN] the type of widget
 *  id: [IN] the index of widget
 * RETURNS
 *  MMI_TRUE if the widget is enabled
 *****************************************************************************/
MMI_BOOL srv_wgtmgr_is_wgt_enabled(srv_wgtmgr_wgt_type_enum type, S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (type == SRV_WGTMGR_WGT_TYPE_PHONE)
    {
    #ifdef __WGTMGR_MGR_PHONE_WIDGET__
        if(cntx_p->pwgt_status[id] == SRV_WGTMGR_WGT_STATUS_ENABLED)
        {
            return MMI_TRUE;
        }
    #endif
   	}
    else if (type == SRV_WGTMGR_WGT_TYPE_DOWNLOADED)    
    {
        if(cntx_p->dwgt_status[id] == SRV_WGTMGR_WGT_STATUS_ENABLED)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_phone_wgt_icon_id
 * DESCRIPTION
 *  This is used to get the information of a widget for displaying on Widget Manager App
 * PARAMETERS
 *  type: [IN]  The widget type
 *  id  : [OUT] The widget information
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_wgtmgr_get_phone_wgt_icon_id(S32 index, S32 *id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __WGTMGR_MGR_PHONE_WIDGET__
    *id = vadp_p2v_hs_widget_get_icon(g_srv_wgtmgr_cntx_p->pwgt_id[index]);
    return MMI_TRUE;
#else
    return MMI_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_downloaded_wgt_icon_path
 * DESCRIPTION
 *  This is used to get the icon path of a downloaded widget by instance id
 * PARAMETERS
 *  id : [IN]  The instance id of the downloaded widget
 *  path        : [OUT] The path of icon
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_get_downloaded_wgt_icon_path(S32 id, WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    srv_wgtmgr_get_path(id, SRV_WGTMGR_PATH_ICON_DISPLAY, path);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_downloaded_widget_idle_view_size
 * DESCRIPTION
 *  This is used to get the idle view size of a downloaded widget by instance id
 * PARAMETERS
 *  id : [IN]  The instance id of the downloaded widget
 *  width       : [OUT] The width of idle view
 *  height      : [OUT] The height of idle view
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_get_downloaded_widget_idle_view_size(S32 id, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_wgt_item_struct wgt_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_read_wgt_info_from_nvram_by_id(id, &wgt_info);
    *width = wgt_info.idle_width;
    *height = wgt_info.idle_height;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgt_get_downloaded_widget_max_resolution
 * DESCRIPTION
 *  This is used to get the max. resolution of a downloaded widget by instance id
 * PARAMETERS
 *  id : [IN]  The instance id of the downloaded widget
 * RETURNS
 *  U8
 *
 *****************************************************************************/
U8 srv_wgt_get_downloaded_widget_max_resolution(S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_wgt_item_struct wgt_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_read_wgt_info_from_nvram_by_id(id, &wgt_info);
    return wgt_info.max_resolution;
}

/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_is_memcard_available
 * DESCRIPTION
 *  This is the function to check memory card status
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if memory card is available
 *****************************************************************************/
MMI_BOOL srv_wgtmgr_is_memcard_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ret = FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM);
    if ( ret == FS_NO_ERROR || ret == FS_DEVICE_BUSY )
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_is_wgt_setting_available
 * DESCRIPTION
 *  This is used to check if setting is available for a widget
 * PARAMETERS
 *  instance_id : [IN]  The instance id of the downloaded widget
 * RETURNS
 *  MMI_TRUE if yes, MMI_FALSE if not
 *****************************************************************************/
MMI_BOOL srv_wgtmgr_is_wgt_setting_available(S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR path[50];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    srv_wgtmgr_get_path(id, SRV_WGTMGR_PATH_OPTIONS_FILE, path);

    if (FS_GetAttributes(path) >= 0)
   	{
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_check_data_account
 * DESCRIPTION
 *  This function is used to check the data account validity
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_check_data_account(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//#ifdef __COSMOS_MMI_PACKAGE__
    srv_dtcnt_sim_type_enum sim;
//#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (srv_wgtmgr_dtcnt_ready_check(srv_wgtmgr_dtcnt_ready_callback) == MMI_TRUE)
    {
        srv_wgtmgr_dtcnt_ready_callback();
    }
//#ifdef __COSMOS_MMI_PACKAGE__
    if (srv_dtcnt_get_sim_preference(&sim) == MMI_TRUE)
    {
        if (sim == SRV_DTCNT_SIM_TYPE_1)
        {
            g_srv_wgtmgr_cntx_p->preferred_sim = SRV_WGTMGR_SIM1;
        }
        else if (sim == SRV_DTCNT_SIM_TYPE_2)
        {
            g_srv_wgtmgr_cntx_p->preferred_sim = SRV_WGTMGR_SIM2;
        }
        else if (sim == SRV_DTCNT_SIM_TYPE_3)
        {
            g_srv_wgtmgr_cntx_p->preferred_sim = SRV_WGTMGR_SIM3;
        }
        else if (sim == SRV_DTCNT_SIM_TYPE_4)
        {
            g_srv_wgtmgr_cntx_p->preferred_sim = SRV_WGTMGR_SIM4;
        }
    }
//#endif    
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_data_account
 * DESCRIPTION
 *  This function is used to query the data account index of installed widgets
 * PARAMETERS
 *  void
 * RETURNS
 *  The data account index of installed widgets
 *****************************************************************************/
U32 srv_wgtmgr_get_data_account(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#ifdef __COSMOS_MMI_PACKAGE__
    if (cntx_p->wifi_only == KAL_TRUE)
    {
        return cbm_encode_data_account_id(CBM_WIFI_ACCT_ID, CBM_SIM_ID_SIM1, cntx_p->da_app_id, KAL_FALSE);
    }
#endif

    gadget_adp_log_prompt_trace("[Get]widget account id [%d]: %d", 
        g_srv_wgtmgr_cntx_p->preferred_sim, cntx_p->data_account[g_srv_wgtmgr_cntx_p->preferred_sim]);

    return cntx_p->data_account[g_srv_wgtmgr_cntx_p->preferred_sim];
}



/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_default_data_account
 * DESCRIPTION
 *  This is used to get default data account of installed widgets.
 * PARAMETERS
 *  sim: [IN] sim id
 * RETURNS
 *  data account
 *****************************************************************************/
U32 srv_wgtmgr_get_default_data_account(srv_wgtmgr_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (srv_wgtmgr_dtcnt_ready_check(srv_wgtmgr_dtcnt_ready_callback) == MMI_TRUE)
    {
        srv_wgtmgr_dtcnt_ready_callback();
    }

    return g_srv_wgtmgr_cntx_p->data_account[sim];
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_set_default_data_account
 * DESCRIPTION
 *  This is used to set data account of installed widgets.
 * PARAMETERS
 *  sim: [IN] sim id
 *  account_id: [IN] data account id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_set_default_data_account(srv_wgtmgr_sim_enum sim, U32 account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 temp;
    S16 error;
    U16 nvram_id_first = NVRAM_WGTMGR_WGT_DATA_ACCOUNT_FIRST, nvram_id_last = NVRAM_WGTMGR_WGT_DATA_ACCOUNT_LAST;
 	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    
    if (g_srv_wgtmgr_cntx_p->data_account[sim] != account_id)
    {
        g_srv_wgtmgr_cntx_p->data_account[sim] = account_id;

        if (sim == SRV_WGTMGR_SIM1)
        {
            nvram_id_first = NVRAM_WGTMGR_WGT_DATA_ACCOUNT_FIRST;
            nvram_id_last = NVRAM_WGTMGR_WGT_DATA_ACCOUNT_LAST;
        }
        else if (sim == SRV_WGTMGR_SIM2)
        {
            nvram_id_first = NVRAM_WGTMGR_WGT_DATA_ACCOUNT_2_FIRST;
            nvram_id_last = NVRAM_WGTMGR_WGT_DATA_ACCOUNT_2_LAST;
        }
        else if (sim == SRV_WGTMGR_SIM3)
        {
            nvram_id_first = NVRAM_WGTMGR_WGT_DATA_ACCOUNT_3_FIRST;
            nvram_id_last = NVRAM_WGTMGR_WGT_DATA_ACCOUNT_3_LAST;
        }
        else if (sim == SRV_WGTMGR_SIM4)
        {
            nvram_id_first = NVRAM_WGTMGR_WGT_DATA_ACCOUNT_4_FIRST;
            nvram_id_last = NVRAM_WGTMGR_WGT_DATA_ACCOUNT_4_LAST;
        }
        else
        {
            ASSERT(0);
        }

        temp = account_id >> 16;
        WriteValue(nvram_id_first, &temp, DS_SHORT, &error);

        temp = account_id << 16 >> 16;
        WriteValue(nvram_id_last, &temp, DS_SHORT, &error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_set_data_account
 * DESCRIPTION
 *  This is used to set data account of installed widgets.
 * PARAMETERS
 *  index: [IN] data account index
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_set_data_account(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    srv_wgtmgr_set_default_data_account(SRV_WGTMGR_SIM1, index);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_network_access
 * DESCRIPTION
 *  This function is used to query the network access setting of installed widgets
 * PARAMETERS
 *  void
 * RETURNS
 *  The network acess setting of installed widgets
 *****************************************************************************/
srv_wgtmgr_network_access_enum srv_wgtmgr_get_network_access(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    return (srv_wgtmgr_network_access_enum)g_srv_wgtmgr_cntx_p->network_access;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_set_network_access
 * DESCRIPTION
 *  This is used to set network access setting of installed widgets.
 * PARAMETERS
 *  index: [IN] network access setting
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_set_network_access(srv_wgtmgr_network_access_enum index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp = (U8)index;
    S16 error;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_srv_wgtmgr_cntx_p->network_access != index)
    {
        g_srv_wgtmgr_cntx_p->network_access = index;
        WriteValue(NVRAM_WGTMGR_WGT_NETWORK_ACCESS, &temp, DS_BYTE, &error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_set_wifi_only
 * DESCRIPTION
 *  This function is used to set if widgets connect network with WiFi only
 * PARAMETERS
 *  wifi_only : [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_set_wifi_only(MMI_BOOL wifi_only)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp = (U8)wifi_only;
    S16 error;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_srv_wgtmgr_cntx_p->wifi_only != wifi_only)
    {
        g_srv_wgtmgr_cntx_p->wifi_only = wifi_only;
        WriteValue(NVRAM_WGTMGR_WIFI_ONLY, &temp, DS_BYTE, &error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_is_wifi_only
 * DESCRIPTION
 *  This function is used to query if widgets connect network with WiFi only
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_wgtmgr_is_wifi_only(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    return g_srv_wgtmgr_cntx_p->wifi_only;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_sort_order
 * DESCRIPTION
 *  This is used to get sort order of installed widgets.
 * PARAMETERS
 *  void
 * RETURNS
 *  sort order
 *****************************************************************************/
srv_wgtmgr_sort_order_enum srv_wgtmgr_get_sort_order(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    return (srv_wgtmgr_sort_order_enum)g_srv_wgtmgr_cntx_p->sort_order;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_set_sort_order
 * DESCRIPTION
 *  This is used to set sort order of installed widgets.
 * PARAMETERS
 *  index: [IN] the index of sort order
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_set_sort_order(srv_wgtmgr_sort_order_enum index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp = (U8)index;
    S16 error;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_srv_wgtmgr_cntx_p->sort_order != index)
    {
        g_srv_wgtmgr_cntx_p->sort_order = index; 
        WriteValue(NVRAM_WGTMGR_WGT_SORT_ORDER, &temp, DS_BYTE, &error);
#ifdef __PLUTO_MMI_PACKAGE__
        srv_wgtmgr_sort_wgt();
#endif
	}		    
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_da_app_id
 * DESCRIPTION
 *   This is used to get data account app id of widget manager.
 * PARAMETERS
 *   void
 * RETURNS
 *   U8 data account app id
 *****************************************************************************/
U8 srv_wgtmgr_get_da_app_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    return g_srv_wgtmgr_cntx_p->da_app_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_fmgr_notify_hdlr
 * DESCRIPTION
 *  the handler for file manager events
 * PARAMETERS
 *  param : [IN] event
 * RETURNS
 *  MMI_RET
 *****************************************************************************/
mmi_ret srv_wgtmgr_fmgr_notify_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
        {
            srv_wgtmgr_recover_gadget_folder();
            srv_wgtmgr_memcard_insert_hdlr();
            break;
        }

        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        {
            srv_fmgr_notification_dev_plug_event_struct *event = (srv_fmgr_notification_dev_plug_event_struct *)param;
            U32 i;

            for (i = 0; i < event->count; i++)
            {
                if (event->drv_letters[i] == cntx_p->memcard_drive)
                {
                    srv_wgtmgr_unload_and_disable_all_downloaded_wgt(SRV_WGTMGR_DRIVE_MEMORY_CARD);
                }
            }
            break;
        }

        case EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT:
        {
            srv_fmgr_notification_format_event_struct *event = (srv_fmgr_notification_format_event_struct *)param;
            if (event->state == SRV_FMGR_NOTIFICATION_STATE_AFTER)
            {
                srv_wgtmgr_recover_gadget_folder();
                srv_wgtmgr_check_all_downloaded_wgt();
            }
            break;
        }
    }
	
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_dtcnt_notify_hdlr
 * DESCRIPTION
 *  check data account status 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_wgtmgr_dtcnt_notify_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;
    cbm_account_info_struct info;
    U32 h, i, j;
    cbm_sim_id_enum cbm_sim[] ={CBM_SIM_ID_SIM1, CBM_SIM_ID_SIM2, CBM_SIM_ID_SIM3, CBM_SIM_ID_SIM4};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param->evt_id == EVT_ID_SRV_DTCNT_SIM_PREFERENCE_UPDATE_IND)
    {
        srv_dtcnt_sim_preference_update_ind_evt_struct *event = (srv_dtcnt_sim_preference_update_ind_evt_struct *)param;
        if (event->sim_id == SRV_DTCNT_SIM_TYPE_1)
        {
            cntx_p->preferred_sim = SRV_WGTMGR_SIM1;
        }
        else if (event->sim_id == SRV_DTCNT_SIM_TYPE_2)
        {
            cntx_p->preferred_sim = SRV_WGTMGR_SIM2;
        }
        else if (event->sim_id == SRV_DTCNT_SIM_TYPE_3)
        {
            cntx_p->preferred_sim = SRV_WGTMGR_SIM3;
        }
        else if (event->sim_id == SRV_DTCNT_SIM_TYPE_4)
        {
            cntx_p->preferred_sim = SRV_WGTMGR_SIM4;
        }        
        return MMI_RET_OK;
    }


    for (h = 0; h < SRV_WGTMGR_SIM_NUM; h++)
    {
        if (cbm_decode_data_account_id_ext(cntx_p->data_account[h], &info) == CBM_OK)
        {
            switch(param->evt_id)
            {
                case EVT_ID_SRV_DTCNT_ACCT_DELETE_IND:
                {
                    srv_dtcnt_acct_delete_ind_evt_struct *event = (srv_dtcnt_acct_delete_ind_evt_struct *)param;

                    for (i = 0; i < info.acct_num; i++)
                    {
                        for (j = 0; j < event->del_num; j++)
                        {
                            if (event->acc_id[j] == info.account[i].account_id)
                            {
                                U32 account_id = cbm_encode_data_account_id(
                                                         CBM_DEFAULT_ACCT_ID,
                                                         cbm_sim[h],
                                                         cntx_p->da_app_id,
                                                         KAL_FALSE);
                                srv_wgtmgr_set_default_data_account(h, account_id);
                            }
                        }
                    }
                }
                break;

                case EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND:			
                {
                    srv_dtcnt_acct_update_ind_evt_struct *event = (srv_dtcnt_acct_update_ind_evt_struct *)param;

                    for (i = 0; i < info.acct_num; i++)
                    {
                        if (event->acc_id == info.account[i].account_id && event->cause ==  1)
                        {
                            srv_dtcnt_bearer_enum bearer = srv_dtcnt_get_bearer_type(event->acc_id, SRV_DTCNT_ACCOUNT_PRIMARY);
                            if (bearer != SRV_DTCNT_BEARER_GPRS && bearer != SRV_DTCNT_BEARER_WIFI)
                            {
                                U32 account_id = cbm_encode_data_account_id(
                                                 CBM_DEFAULT_ACCT_ID,
                                                 cbm_sim[h], 
                                                 cntx_p->da_app_id, 
                                                 KAL_FALSE);
                                srv_wgtmgr_set_default_data_account(h, account_id);
                            }
                        }
                    }
                }
                break;
            }
        }         
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_usb_notify_hdlr
 * DESCRIPTION
 *  check memory 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_wgtmgr_usb_notify_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_USB_SUPPORT__
    switch(param->evt_id)
    {
        case EVT_ID_USB_EXIT_MS_MODE:
        {
            srv_wgtmgr_recover_gadget_folder();
            srv_wgtmgr_check_all_downloaded_wgt();
            break;
        }
    }
#endif	
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_bearer_event_notify_hdlr
 * DESCRIPTION
 *  check memory 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_wgtmgr_bearer_event_notify_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_bearer_event_struct *event = (srv_cbm_bearer_event_struct *)param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(event->type)
    {
        case SRV_CBM_BEARER_EVENT_DISCONNECT:
        {
            gadget_adp_log_prompt_trace("widget received [SRV_CBM_BEARER_EVENT_DISCONNECT]");

            srv_wgtmgr_release_bearer();
            
            srv_wgtmgr_bearer_disconnect();
            break;
        }
        case SRV_CBM_BEARER_EVENT_SWITCH:
        {
            gadget_adp_log_prompt_trace("widget received [SRV_CBM_BEARER_EVENT_SWITCH]");

            srv_wgtmgr_bearer_switch(event->user_result, event->switch_type);
            break;
        }
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_unload_and_disable_all_downloaded_wgt
 * DESCRIPTION
 *  unload and disable all downloaded widget installed in a particular drive 
 * PARAMETERS
 *  drive: [IN] the specified drive
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_unload_and_disable_all_downloaded_wgt(srv_wgtmgr_wgt_drive_enum drive)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;
    U8 *dwgt_status_p = cntx_p->dwgt_status;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if widget is installed in specified drive and active, unload and disable it */
    for (i = 0; i < SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM; i++)
    {
        if (cntx_p->dwgt_drive[i] == drive && dwgt_status_p[i] == SRV_WGTMGR_WGT_STATUS_ENABLED)
        {
            srv_wgtmgr_notify_evt_struct event;
            MMI_FRM_INIT_EVENT(&event, EVT_ID_SRV_WGTMGR_FILE_NOT_EXISTS_IND);
            event.id = i;
            MMI_FRM_CB_EMIT_POST_EVENT(&event);
        #ifdef __PLUTO_MMI_PACKAGE__
            dwgt_status_p[i] = SRV_WGTMGR_WGT_STATUS_DISABLED;
        #endif
        }
    }

#ifdef __PLUTO_MMI_PACKAGE__
    /* save widget status to nvram */
    srv_wgtmgr_save_wgt_status_to_nvram();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_check_downloaded_wgt
 * DESCRIPTION
 *  this funciton is used to check a widget
 * PARAMETERS
 *  id: [IN] widget instance id
 * RETURNS
 *  error code
 *****************************************************************************/
srv_wgtmgr_result_enum srv_wgtmgr_check_downloaded_wgt(S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if widget is installed in memory card which is not inserted now */
    if (srv_wgtmgr_check_downloaded_wgt_int(id) != SRV_WGTMGR_RET_OK)
    {
        if (cntx_p->dwgt_drive[id] == SRV_WGTMGR_DRIVE_MEMORY_CARD)
        {
            return SRV_WGTMGR_RET_MEMCARD_NOT_EXIST;
        }
        else
        {
            return SRV_WGTMGR_RET_FILE_NOT_EXIST;
        }
    }
    return SRV_WGTMGR_RET_OK;	
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_drive_letter
 * DESCRIPTION
 *  This is the function to get drive letter
 * PARAMETERS
 *  drive: [IN]
 * RETURNS
 *  drive letter
 *****************************************************************************/
char srv_wgtmgr_get_drive_letter(srv_wgtmgr_wgt_drive_enum drive)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;
    char letter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drive == SRV_WGTMGR_DRIVE_SYSTEM)
    {
        letter = cntx_p->system_drive;
    }
    else if (drive == SRV_WGTMGR_DRIVE_PUBLIC)
    {
        letter = cntx_p->public_drive;
    }
    else
    {
        letter = cntx_p->memcard_drive;
    }
    return letter;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_exit_usb_mode_hdlr
 * DESCRIPTION
 *  This function is invoked when exiting USB mass storage mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_exit_usb_mode_hdlr(void)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_recover_gadget_folder();
    srv_wgtmgr_check_all_downloaded_wgt();
    /* set name and version data, because it might be wrongly produced when 
       phone is in USB mass storage mode */
    srv_wgtmgr_set_data_need_update(SRV_WGTMGR_UPDATE_NAME | SRV_WGTMGR_UPDATE_VERSION);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_recover_gadget_folder
 * DESCRIPTION
 *  this funciton is to recover all gadget folders
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_recover_gadget_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *buff;
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    buff = (WCHAR*)OslMalloc(sizeof(WCHAR) * 30);

    /* check @gadget */
    kal_wsprintf(buff, "%c:\\@gadget", cntx_p->public_drive);

    /* prevent the case that there is a file named @gadget */
    FS_Delete(buff);

    /* create if necessary */
    if (FS_GetAttributes((const WCHAR*)buff) < 0)
    {
        FS_CreateDir((const WCHAR*)buff);
    }
    FS_SetAttributes((const WCHAR*)buff, FS_ATTR_DIR | FS_ATTR_HIDDEN);

    /* check @gadget\\tmp */
    kal_wsprintf(buff, "%c:\\@gadget\\tmp", cntx_p->public_drive);    

    FS_Delete(buff);

    if(FS_GetAttributes((const WCHAR*)buff) < 0)
    {
        FS_CreateDir((const WCHAR*)buff);
    }
    FS_SetAttributes((const WCHAR*)buff, FS_ATTR_DIR | FS_ATTR_HIDDEN);

    kal_wsprintf(buff, "%c:\\@gadget", cntx_p->memcard_drive);

    /* prevent the case that there is a file named @gadget */
    FS_Delete(buff);

    if(FS_GetAttributes((const WCHAR*)buff) < 0)
    {
        FS_CreateDir((const WCHAR*)buff);
    }
    FS_SetAttributes((const WCHAR*)buff, FS_ATTR_DIR | FS_ATTR_HIDDEN);

    OslMfree(buff);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_current_time_in_sec
 * DESCRIPTION
 *  this funciton is to get current time in sec
 * PARAMETERS
 *  void
 * RETURNS
 *  U32
 *****************************************************************************/
U32 srv_wgtmgr_get_current_time_in_sec(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_dt_get_secure_time(&time);
    return applib_dt_mytime_2_utc_sec(&time, KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_downloaded_wgt_installed_drive
 * DESCRIPTION
 *  This function is used to get the drive where widget is installed
 * PARAMETERS
 *  id: [IN] the id of widget in query
 * RETURNS
 *  drive
 *****************************************************************************/
srv_wgtmgr_wgt_drive_enum srv_wgtmgr_get_downloaded_wgt_installed_drive(S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (srv_wgtmgr_wgt_drive_enum)g_srv_wgtmgr_cntx_p->dwgt_drive[id];
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_is_preinstall_widget_finished
 * DESCRIPTION
 *  This function is used to check if widget preinstallation is finished
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
MMI_BOOL srv_wgtmgr_is_preinstall_widget_finished()
{
#ifdef WIDGET_PREINSTALLATION_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 done;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* pre-install widget */
    ReadValue(NVRAM_WGTMGR_PRE_INSTALL_DONE, &done, DS_BYTE, &error);
    if (done == 1)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
#else
    return MMI_TRUE;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_engine_version
 * DESCRIPTION
 *  This function is used to get gadget engine version
 * PARAMETERS
 *  version: [Out] gadget engine version
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_get_engine_version(char *version)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gadget_adp_mgr_get_engine_version(version);
}

/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_hold_bearer
 * DESCRIPTION
 *  This function is used to hold bearer connect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_hold_bearer()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cbm_hold_bearer(g_srv_wgtmgr_cntx_p->da_app_id);
}

/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_release_bearer
 * DESCRIPTION
 *  This function is used to release bearer connect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_release_bearer()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cbm_release_bearer(g_srv_wgtmgr_cntx_p->da_app_id);
}



#endif /* __GADGET_SUPPORT__ */

