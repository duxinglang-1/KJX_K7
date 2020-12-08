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
 *  TetheringSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 * Wi-Fi hotspot service global prototype header.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __TETHERING_SRV_GPROT_H__
#define __TETHERING_SRV_GPROT_H__

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMIDataType.h"

/****************************************************************************
* Define
*****************************************************************************/

/* Tethering type enum */
typedef enum
{
    SRV_TETHERING_TYPE_WIFI_HS, /* Wi-Fi tethering type */
    SRV_TETHERING_TYPE_USB,     /* USB tethering type */
    SRV_TETHERING_TYPE_ALL      /* Total number */
} srv_tethering_type_enum;

/* Structure of tethering status changed event (currently not used) */
typedef struct
{
    MMI_EVT_PARAM_HEADER                    /* Event parameter header */
    srv_tethering_type_enum tethering_type; /* Tethering type */
    MMI_BOOL status;                        /* Tethering status */
} srv_tethering_status_changed_evt_struct;

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_tethering_cb_func_ptr
 * DESCRIPTION
 *  Funtion type for other application/service to receive a operation callback.
 * PARAMETERS
 *  tethering_type:     [IN] Tethering type
 *  result:             [IN] Operation result
 *  user_data:          [IN] User data
 * RETURN VALUES
 *  void
 *****************************************************************************/
typedef void(*srv_tethering_cb_func_ptr)(
                srv_tethering_type_enum tethering_type,
                MMI_BOOL result,
                void *user_data);

/* Structure of store tethering callback function infomation */
typedef struct
{
    srv_tethering_cb_func_ptr cb_func_ptr;
    void *user_data;
} srv_tethering_cb_info;

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_is_on
 * DESCRIPTION
 *  Function of checking specific tethering is activated.
 * PARAMETERS
 *  tethering_type: [IN] Tethering type
 * RETURNS
 *  MMI_TRUE: tethering is activated
 *  MMI_FALSE: tethering is not activated (maybe on switching)
 *****************************************************************************/
extern MMI_BOOL srv_tethering_is_on(srv_tethering_type_enum tethering_type);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_is_off
 * DESCRIPTION
 *  Function of checking specific tethering is inactivated.
 * PARAMETERS
 *  tethering_type: [IN] Tethering type
 * RETURNS
 *  MMI_TRUE: tethering is inactivated
 *  MMI_FALSE: tethering is not inactivated (maybe on switching)
 *****************************************************************************/
extern MMI_BOOL srv_tethering_is_off(srv_tethering_type_enum tethering_type);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_is_switching
 * DESCRIPTION
 *  Function of checking specific tethering is on switching.
 * PARAMETERS
 *  tethering_type: [IN] Tethering type
 * RETURNS
 *  MMI_TRUE: tethering is on switching
 *  MMI_FALSE: tethering is not on switching
 *****************************************************************************/
extern MMI_BOOL srv_tethering_is_switching(srv_tethering_type_enum tethering_type);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_any_type_is_on
 * DESCRIPTION
 *  Function of checking any tethering type is activated.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: exist a tethering type is activated
 *  MMI_FALSE: no tethering type is activated
 *****************************************************************************/
extern MMI_BOOL srv_tethering_any_type_is_on(void);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_stop
 * DESCRIPTION
 *  Function of stopping a specific tethering type.
 * PARAMETERS
 *  tethering_type  : [IN] Tethering type
 *  cb_func_ptr     : [IN] Callback function pointer
 *  user_data       : [IN] User data
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_tethering_stop(
                srv_tethering_type_enum tethering_type,
                srv_tethering_cb_func_ptr cb_func_ptr,
                void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_stop_all
 * DESCRIPTION
 *  Function of stopping all running tethering type.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: successful
 *  MMI_FALSE: failed
 *****************************************************************************/
extern MMI_BOOL srv_tethering_stop_all(void);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_stop_all
 * DESCRIPTION
 *  Function of calling the tethering callback function (srv_tethering_cb_func_ptr).
 * PARAMETERS
 *  tethering_type  : [IN] Tethering type
 *  result          : [IN] Operation result
 * RETURNS
 *  MMI_TRUE: successful
 *  MMI_FALSE: failed
 *****************************************************************************/
extern void srv_tethering_run_cb_func(srv_tethering_type_enum tethering_type, MMI_BOOL result);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_usb_cable_disconnect_notify_hdlr
 * DESCRIPTION
 *  Function of handling usb cable disconnect notification, only for USB tethering.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_tethering_usb_cable_disconnect_notify_hdlr(void);

/*****************************************************************************
 * FUNCTION
 *  srv_tethering_usb_qurey_acct_id
 * DESCRIPTION
 *  USB tethering doesn't use the selected data account by user, it only get the
 *  infomation of this account and use another account to connect the network.
 *  So USB tethering should tell other modules what the user selected account is.
 * PARAMETERS
 *  void
 * RETURNS
 *  data account id
 *****************************************************************************/
extern U32 srv_tethering_usb_qurey_acct_id(void);

#endif /* __TETHERING_SRV_GPROT_H__ */
