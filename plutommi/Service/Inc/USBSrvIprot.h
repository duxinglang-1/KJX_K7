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
 * USBsrvIprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Header file for USB Service internal API
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef USB_SRV_IPROT_H
#define USB_SRV_IPROT_H

#include "mmi_features.h"

#ifdef __MMI_USB_SUPPORT__

#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_rp_app_usbsrv_def.h"

typedef enum
{
    SRV_USB_COMPORT_PS,
    SRV_USB_COMPORT_JAVA,
    SRV_USB_MS_STORAGE_MS,
    SRV_USB_MS_STORAGE_MTP,
    SRV_USB_CDROM
} srv_usb_owner_type_enum;

/*****************************************************************************
 * FUNCTION
 *  srv_usb_init_context
 * DESCRIPTION
 *  This function is to initialize the mmi usb context.
 *  
 *  PARAMETERS: void
 *  
 *  RETURNS: void
 *****************************************************************************/
extern void srv_usb_init_context(void);

/*****************************************************************************
 * FUNCTION
 *  srv_usb_set_owner
 * DESCRIPTION
 *  This function is to set usb owner
 *  
 *  PARAMETERS: void
 *  
 *  RETURNS: void
 *  
 *****************************************************************************/
extern void srv_usb_set_owner(U8 owner);

/*****************************************************************************
 * FUNCTION
 *  srv_usb_get_owner
 * DESCRIPTION
 *  This function is to set usb owner
 *  
 *  PARAMETERS: void
 *  
 *  RETURNS: Owenr ID
 *  
 *****************************************************************************/
extern U8 srv_usb_get_owner(void);

/*****************************************************************************
 * FUNCTION
 *  srv_usb_is_dm_lock
 * DESCRIPTION
 *  To check if dm is lock
 * PARAMETERS
 *  path
 * RETURNS
 *  return MMI_TRUE if dm is lock, otherwise return MMI_FALSE
 *****************************************************************************/
#ifdef __DM_LAWMO_SUPPORT__
extern MMI_BOOL srv_usb_is_dm_lock(void);
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_usb_send_power_on_req
 * DESCRIPTION
 *  Send power on request (END key is long pressed) to L4C in USB power on mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_usb_send_power_on_req(void);

/*****************************************************************************
 * FUNCTION
 *  srv_usb_stop_config_ms
 * DESCRIPTION
 *  stop usb config mass storage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_usb_stop_config_ms(void);

/*****************************************************************************
 * FUNCTION
 *  srv_usb_init_bootup
 * DESCRIPTION
 *  This function is to initialize the event handler
 *  
 *  PARAMETERS: void
 *  
 *  RETURNS: void
 *  
 *****************************************************************************/
extern void srv_usb_init_bootup(void);

/*****************************************************************************
 * FUNCTION
 *  srv_usb_start_ms_shutdown
 * DESCRIPTION
 *  This fucntion is mass storage following action after usb conigure response comes,
 *  (MSG_ID_MMI_EQ_USBCONFIG_RSP) 
 *  PARAMETERS: 
 *  void
 *  RETURNS: 
 *  void
 *****************************************************************************/
extern void srv_usb_start_ms_shutdown(void);

/*****************************************************************************
 * FUNCTION
 *  srv_usb_init_event_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_usb_init_event_hdlr(void);

/*****************************************************************************
 * FUNCTION
 *  srv_usb_enter_ms_proc
 * DESCRIPTION
 *  Start procedure to enter Mass storage/MTP mode.
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __USB_IN_NORMAL_MODE__
extern void srv_usb_enter_ms_proc(void);
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_usb_shutdown_handler
 * DESCRIPTION
 *  Callback for EVT_ID_SRV_SHUTDOWN_DEINIT
 *
 * PARAMETERS
 *  evt
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
extern mmi_ret srv_usb_shutdown_handler(mmi_event_struct *evt);

/*****************************************************************************
 * FUNCTION
 *  srv_usb_app_reset_poweron
 * DESCRIPTION
 *  Reboot phone
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_usb_app_reset_poweron(void);

/*****************************************************************************
 * FUNCTION
 *  srv_usb_get_ps_port
 * DESCRIPTION
 *  Get current PS port setting value
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
extern U8 srv_usb_get_ps_port(void);

#endif
#endif

