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
 * BtcmCuiGprot.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for MMI BT CM common UI function header external files
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __BT_MMI_CUI_GPROT_H__
#define __BT_MMI_CUI_GPROT_H__

#include "MMIDataType.h"
#include "bt_a2dp_base_struct.h"
#include "kal_general_types.h"
/*******************************************************************************
* Include Header File
*******************************************************************************/
#include "ConnectivityResDef.h"

/*******************************************************************************
* Enum Define
*******************************************************************************/

/* 
    It's used to indicate the event type. 
    After common UI process end, CM will use these event to notify caller 
*/
typedef enum _cui_bt_cm_event_enum
{   
    EVT_ID_CUI_BT_CM_POWER_ON_RESULT = (SCR_EXTDEV_IRDA_LAST+1),      /* power on confirm result, success or fail*/
    EVT_ID_CUI_BT_CM_DEFAULT_DEVICE,       /* set or reset default device result*/
    EVT_ID_CUI_BT_CM_DEVICE_SELECT        /* device select result */
}cui_bt_cm_event_enum;

/* 
    device select options, 
    CUI_BT_CM_DEVICE_SELECT_OPTION_SELECT means there is only one action, 
    so there won't be an option menu. LSK will be OK.
    CUI_BT_CM_DEVICE_SELECT_OPTION_SELECT | CUI_BT_CM_DEVICE_SELECT_OPTION_SET_DEFAULT 
    means there is set or reset default device option in the option menu. LSK will be Options. 
*/
typedef enum _cui_bt_cm_device_select_option_enum
{   
	CUI_BT_CM_DEVICE_SELECT_OPTION_SELECT = 0x00000001,         /* select */
	CUI_BT_CM_DEVICE_SELECT_OPTION_SET_DEFAULT = 0x00000010,     /* set or reset default device */
	CUI_BT_CM_DEVICE_SELECT_OPTION_NORMAL = 0x00000100
} cui_bt_cm_device_select_option_enum;

/*******************************************************************************
* Structure Define
*******************************************************************************/

/* 
    BT CM power on confirm result structure 
*/
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER  /* mmi event group parameter header */
    MMI_BOOL result;    /* power on result , TRUE : success*/
    mmi_id gid;         /* screen group id*/
} cui_event_bt_cm_power_on_result_struct;

/* 
    BT CM device select result structure 
*/
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER  /* mmi event group parameter header */
    MMI_BOOL result; /* device select result */
    mmi_id gid;     /* screen group id*/
    U32 lap;        /*device address */
    U8 uap;         /*device address */
    U16 nap;        /*device address */
} cui_event_bt_cm_device_select_result_struct;

/* 
    BT CM set or reset default device result structure 
*/
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER  /* mmi event group parameter header */
    MMI_BOOL result;    /* TRUE : set as default*/
    mmi_id gid;         /* group id*/
    U32 lap;            /* device address */
    U8 uap;             /* device address */
    U16 nap;            /* device address */
} cui_event_bt_cm_set_default_device_result_struct;

/*******************************************************************************
* Macro Define
*******************************************************************************/


/*******************************************************************************
* Export API 
*******************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  cui_bt_power_on_create
 * DESCRIPTION
 *  This function is to create power on confirm screen common UI
 *  if the common UI is unable to entry, it will return GRP_ID_INVALID
 *  caller need to check the returned group id to see if the common UI can be entry
 * PARAMETERS
 *  parent_gid : [IN]   parent or caller id
 * RETURNS
 *  mmi_id        return GRP_ID_BT_CM_POWER_ON_CNF, which is power on confirm group id
 *                or return GRP_ID_INVALID if common UI can not be entry
 *****************************************************************************/
mmi_id cui_bt_power_on_create(mmi_id parent_gid);

/*****************************************************************************
 * FUNCTION
 *  cui_bt_power_on_run
 * DESCRIPTION
 *  This function is to run power on confirm screen common UI
 *  It will entry a screen group and entry power on confirm screen
 * PARAMETERS
 *  cui_id :    [IN] common UI ID
 * RETURNS
 *  mmi_proc_func
 *****************************************************************************/
mmi_ret cui_bt_power_on_run(mmi_id cui_id);

/*****************************************************************************
 * FUNCTION
 *  cui_bt_power_on_result_hdlr
 * DESCRIPTION
 *  This function is to handle power on confirm result, and return to parent
 * PARAMETERS
 *  result :  [IN] the result of power on confirm, MMI_TRUE means power on success
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bt_power_on_result_hdlr(MMI_BOOL result);

/*****************************************************************************
 * FUNCTION
 *  cui_bt_power_on_close
 * DESCRIPTION
 *  This function is to close power on confirm common UI
 * PARAMETERS
 *  cui_gid :  [IN] common UI group ID
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bt_power_on_close(mmi_id cui_gid);

/*****************************************************************************
 * FUNCTION
 *  cui_bt_device_select_screen_create
 * DESCRIPTION
 *  This function is to create device select screen common UI
 *  if the common UI is unable to entry, it will return GRP_ID_INVALID
 *  caller need to check the returned group id to see if the common UI can be entry
 * PARAMETERS
 *  parent_gid :  [IN] parent or caller id
 * RETURNS
 *  mmi_id        return GRP_ID_BT_CM_SELECT_DEVICE, which is device select screen group id
 *                or return GRP_ID_INVALID if common UI can not be entry 
 *****************************************************************************/
mmi_id cui_bt_device_select_screen_create(mmi_id parent_gid);

/*****************************************************************************
 * FUNCTION
 *  cui_bt_device_select_screen_set_mask
 * DESCRIPTION
 *  This function is to set cod bit mask and service id on device select screen 
 *  the cod bit mask and service id will be used to search and filter device
 * PARAMETERS
 *  cui_id :         [IN] common UI id
 *  cod_bit_mask :   [IN] cod bit mask
 *  service_id  :    [IN]  service id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bt_device_select_screen_set_mask(mmi_id cui_id, U32 cod_bit_mask, U32 service_id);

/*****************************************************************************
 * FUNCTION
 *  cui_bt_device_select_screen_set_default_device
 * DESCRIPTION
 *  This function is to set default device
 * PARAMETERS
 *  cui_id :         [IN] common UI id
 *  lap :            [IN] device address
 *  uap :            [IN] device address 
 *  nap :            [IN] device address 
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bt_device_select_screen_set_default_device(mmi_id cui_id, U32 lap, U8 uap, U16 nap);

/*****************************************************************************
 * FUNCTION
 *  cui_bt_device_select_screen_set_option_flag
 * DESCRIPTION
 *  This function is to set flag, 
 *  it¡¦s for show the LSK option and option menu, use bit mask of cui_bt_cm_device_select_option_enum
 * PARAMETERS
 *  cui_id :  [IN] common UI id
 *  flag :    [IN] flag to set, refer to cui_bt_cm_device_select_option_enum
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bt_device_select_screen_set_option_flag(mmi_id cui_id, U32 flag);

/*****************************************************************************
 * FUNCTION
 *  cui_bt_device_select_screen_run
 * DESCRIPTION
 *  This function is to run device select screen common UI
 *  It will entry a screen group and entry device select screen
 * PARAMETERS
 *  cui_id :     [IN] common UI ID
 * RETURNS
 *  mmi_proc_func
 *****************************************************************************/
mmi_ret cui_bt_device_select_screen_run(mmi_id cui_id);

/*****************************************************************************
 * FUNCTION
 *  cui_bt_device_set_default_hdlr
 * DESCRIPTION
 *  This function is to set default device, and return to parent 
 * PARAMETERS
 *  result :  [IN] result of set default device
 *  lap :     [IN] device address
 *  uap :     [IN] device address
 *  nap :     [IN] device address
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bt_device_set_default_hdlr(MMI_BOOL result, U32 lap, U8 uap, U16 nap);

/*****************************************************************************
 * FUNCTION
 *  cui_bt_device_select_hdlr
 * DESCRIPTION
 *  This function is to handle device select screen result, and return to parent
 * PARAMETERS
 *  result :  [IN] the result of device select
 *  lap :     [IN] device address
 *  uap :     [IN] device address
 *  nap :     [IN] device address
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bt_device_select_hdlr(MMI_BOOL result, U32 lap, U8 uap, U16 nap);

/*****************************************************************************
 * FUNCTION
 *  cui_bt_device_select_screen_close
 * DESCRIPTION
 *  This function is to close device select screen common UI
 * PARAMETERS
 *  cui_gid :  [IN] common UI group ID
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bt_device_select_screen_close(mmi_id cui_gid);
#endif /*__BT_MMI_CUI_GPROT_H__*/
