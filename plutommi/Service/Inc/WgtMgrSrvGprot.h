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
 * WgtMgrSrvGprot.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef WGTMGR_SRV_GPROT_H
#define WGTMGR_SRV_GPROT_H

/************************************************************************/
/* Include Header                                                       */
/************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

#include "MMIDataType.h"
#include "kal_non_specific_general_types.h"
#include "mmi_res_range_def.h"

#ifdef __PLUTO_MMI_PACKAGE__
#define __WGTMGR_MGR_PHONE_WIDGET__
#endif

#define WGTMGR_VERSION_MAX_LEN 20   /* widget engine max length in WCHAR*/

/************************************************************************/
/* Structure and Definition                                             */
/************************************************************************/
typedef enum
{
    EVT_ID_SRV_WGTMGR_FILE_NOT_EXISTS_IND = WGTMGR_SRV_BASE,
    EVT_ID_SRV_WGTMGR_DELETE_WIDGET_IND,
    EVT_ID_SRV_WGTMGR_FINISH_PRE_INSATLL_WIDGET_IND,
} srv_wgtmgt_evt_enum;


/* The type of widget */
typedef enum
{
    SRV_WGTMGR_WGT_TYPE_PHONE,       /* The phone widget */
    SRV_WGTMGR_WGT_TYPE_DOWNLOADED,  /* The downloaded gadget */
    SRV_WGTMGR_WGT_TYPE_TOTAL_NUM
} srv_wgtmgr_wgt_type_enum;

/* The network access options */
typedef enum
{
    SRV_WGTMGR_NETWORK_ACCESS_NO,         /* It won't allow widget use network */
    SRV_WGTMGR_NETWORK_ACCESS_ALWAYS_ASK, /* It will always ask user first when it needs to connect to Internet */
    SRV_WGTMGR_NETWORK_ACCESS_ALLOW,      /* It will allow user if it needs to connect to Internet              */
    SRV_WGTMGR_NETWORK_ACCESS_TOTAL_NUM
} srv_wgtmgr_network_access_enum;


/* The sim id */
typedef enum
{
    SRV_WGTMGR_SIM1 = 0,
    SRV_WGTMGR_SIM2,
    SRV_WGTMGR_SIM3,
    SRV_WGTMGR_SIM4,
    SRV_WGTMGR_SIM_NUM
} srv_wgtmgr_sim_enum;


/* The result of operation */
typedef enum
{
    SRV_WGTMGR_RET_OK,                /* successfully                      */
    SRV_WGTMGR_RET_ERROR,		     /* error without specific reason     */
    SRV_WGTMGR_RET_WGT_CORRUPTED,     /* the widget file is corrupted      */
    SRV_WGTMGR_RET_WGT_UNTRUSTED,     /* the widget file is untrusted      */
    SRV_WGTMGR_RET_WGT_INSTALLED,     /* the widget has been installed     */
    SRV_WGTMGR_RET_MEM_NOT_ENOUGH,    /* the memory space is not enough    */
    SRV_WGTMGR_RET_FILE_NOT_EXIST,    /* the widget file is not present    */
    SRV_WGTMGR_RET_MEMCARD_NOT_EXIST, /* the memory card which the widget is installed is not present */
    SRV_WGTMGR_RET_WGT_NOT_VALID,      /* the widget file is not valid      */
    SRV_WGTMGR_RET_EXCEED_MAX_INSTALLED_NUM, /* the number of intalled widget exceed limitation */
    SRV_WGTMGR_RET_OLD_VERSION,
    SRV_WGTMGR_RET_NEW_VERSION,
    SRV_WGTMGR_RET_ALREADY_INSTALLED,
    SRV_WGTMGR_RET_DISK_SPACE_NOT_ENOUGH,
    SRV_WGTMGR_RET_EXCEED_MAX_ENABLED_NUM,
    SRV_WGTMGR_RET_CONTINUE,
} srv_wgtmgr_result_enum;


/* The list of widget */
typedef struct
{
    srv_wgtmgr_wgt_type_enum type; /* the type of widget */
    S32 id;	                       /* the widget id */
} srv_wgtmgr_wgt_list_struct;


typedef struct 
{
    MMI_EVT_PARAM_HEADER
    S32 id;
} srv_wgtmgr_notify_evt_struct;

/************************************************************************/
/* Function Definition                                                  */
/************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_wgt_num
 * DESCRIPTION
 *  This function is used to get number of installed widgets
 * PARAMETERS
 *  void
 * RETURNS
 *  The number of installed widgets
 *****************************************************************************/
extern S32 srv_wgtmgr_get_wgt_num(srv_wgtmgr_wgt_type_enum type);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_enabled_wgt_num
 * DESCRIPTION
 *  This function is used to query the number of enabled widgets
 * PARAMETERS
 *  void
 * RETURNS
 *  The number of enabled widgets
 *****************************************************************************/
extern S32 srv_wgtmgr_get_enabled_wgt_num(void);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_enabled_wgt_list
 * DESCRIPTION
 *  This function is used to query the list of enabled widgets
 * PARAMETERS
 *  list_ptr:  [OUT] list of enabled widgets
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_get_enabled_wgt_list(srv_wgtmgr_wgt_list_struct *list_ptr);


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
extern U32 srv_wgtmgr_get_data_account(void);


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
extern U32 srv_wgtmgr_get_default_data_account(srv_wgtmgr_sim_enum sim);


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
extern void srv_wgtmgr_check_data_account(void);


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
extern srv_wgtmgr_network_access_enum srv_wgtmgr_get_network_access(void);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_check_downloaded_wgt
 * DESCRIPTION
 *  this funciton is to check all downloaded widgets
 * PARAMETERS
 *  drive: [IN] the specified drive
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_check_all_downloaded_wgt(void);


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
extern MMI_BOOL srv_wgtmgr_get_downloaded_wgt_name(S32 id, WCHAR *name, S32 size);


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
extern void srv_wgtmgr_get_downloaded_wgt_icon_path(S32 id, WCHAR *path);


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
extern void srv_wgtmgr_get_downloaded_widget_idle_view_size(S32 id, S32 *width, S32 *height);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_downloaded_widget_idle_view_size
 * DESCRIPTION
 *  This is used to get the max. resolution of a downloaded widget by instance id
 * PARAMETERS
 *  id : [IN]  The instance id of the downloaded widget
 * RETURNS
 *  WIDGET_LCD_UNKNOWN  0
 *  WIDGET_LCD_240x320  1
 *  WIDGET_LCD_240x400  2
 *  WIDGET_LCD_320x480  3
 *  WIDGET_LCD_480x800  4
 *****************************************************************************/
extern U8 srv_wgt_get_downloaded_widget_max_resolution(S32 id);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_is_wgt_setting_available
 * DESCRIPTION
 *  This is used to check if setting is available for a widget
 * PARAMETERS
 *  id : [IN]  The instance id of the downloaded widget
 * RETURNS
 *  MMI_TRUE if yes, MMI_FALSE if not
 *****************************************************************************/
extern MMI_BOOL srv_wgtmgr_is_wgt_setting_available(S32 id);


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
extern MMI_BOOL srv_wgtmgr_is_wifi_only(void);


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
extern srv_wgtmgr_result_enum srv_wgtmgr_check_downloaded_wgt(S32 id);


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
extern void srv_wgtmgr_get_engine_version(char *version);

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
extern void srv_wgtmgr_hold_bearer();

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
extern void srv_wgtmgr_release_bearer();

#ifdef __cplusplus
}
#endif
#endif
