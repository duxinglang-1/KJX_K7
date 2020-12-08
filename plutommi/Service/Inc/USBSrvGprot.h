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
 * USBsrvGprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Header file for GPIO Utility Functions
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
#ifndef USB_SRV_GPROT_H
#define USB_SRV_GPROT_H

#include "mmi_features.h"

#ifdef __MMI_USB_SUPPORT__

#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_rp_app_usbsrv_def.h"

/* DOM-NOT_FOR_SDK-BEGIN */

/* 
 * USB state used to keep the USB current status
 */
typedef enum
{

    SRV_USBSTATUS_UNKNOW = 0,           /* Unknow, initial state */
    SRV_USBSTATUS_PLUGIN,               /* Usb device pluged in */
    SRV_USBSTATUS_CONF_PAGE,            /* Usb device pluged in and MMI Screen is usb configure page */
    SRV_USBSTATUS_IGNORED,              /* Usb device pluged in, user ignore the configuration */
    SRV_USBSTATUS_PLUGOUT,              /* Usb device pluged out */
    SRV_USBSTATUS_MS_PROC,              /* Usb device is configuring as mass storage */
    SRV_USBSTATUS_EXIT_MS_PROC,              /* Usb device is configuring as mass storage */
    SRV_USBSTATUS_MS,                   /* Usb device is in mass storage mode */
    SRV_USBSTATUS_CDCACM_PROC,          /* Usb device is configuring as com port emulator */
    SRV_USBSTATUS_CDCACM,               /* Usb device is in com port emulator mode */
    SRV_USBSTATUS_WEBCAM,               /* Usb device is configuring as webcam */
    SRV_USBSTATUS_PICTBRIGE,            /* Usb device is configuring as pictbrige */
    SRV_USBSTATUS_JAVA_CONNECT,         /* Usb device is configuring as java connection */
    SRV_USBSTATUS_CFG_RSP,
    SRV_USBSTATUS_USBTETHERING,
    SRV_USBSTATUS_CDROM,
    SRV_USBSTATUS_ENUM_END              /* Last state, shall not modify this value */
} srv_usb_status_enum;

typedef enum
{
    SRV_USB_MMI_NOTIFY_POWER_OFF_REMOVED = 0,
    SRV_USB_MMI_NOTIFY_REMOVED,
    SRV_USB_MMI_NOTIFY_PLUGOUT,
    SRV_USB_MMI_NOTIFY_CLOSE_CFG_LIST,
    SRV_USB_MMI_NOTIFY_CLOSE_PROGRESS,
    SRV_USB_MMI_NOTIFY_EXIT_WEBCAM,
    SRV_USB_MMI_NOTIFY_CFG_ERROR,
    SRV_USB_MMI_NOTIFY_CFG_END,
    SRV_USB_MMI_NOTIFY_ENUM_END
} srv_usb_mmi_notify_action_enum;

typedef enum
{
    SRV_USB_ERROR_UNAVAILABLE = 0,
    SRV_USB_ERROR_MAX_ITEM
} srv_usb_error_type_enum;

/*
 * USB config respnose structrure
 */

typedef struct
{
    U8 mode;
    MMI_BOOL suc; 
} srv_usb_config_result_struct;

/*****************************************************************************
 * FUNCTION
 *  srv_usb_send_config_to_hw
 * DESCRIPTION
 *  This function is to send usb config request to PS
 *  
 *  PARAMETERS:
 *  mode        [IN]   refer to srv_usb_status_enum     
 *  RETURNS:
 *  void
 *****************************************************************************/
extern MMI_BOOL srv_usb_is_ms_exit_done(void);
extern void srv_usb_send_config_to_hw(U8 mode);
#ifdef __MMI_TETHERING__
extern void srv_usb_tethering_off(void);
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_usb_get_status
 * DESCRIPTION
 *  This function is to get the usb state
 *  
 *  PARAMETERS: 
 *  void
 *  RETURNS: 
 *  enum srv_usb_status_enum
 *****************************************************************************/
extern srv_usb_status_enum srv_usb_get_status(void);

/*****************************************************************************
 * FUNCTION
 *  srv_usb_set_status
 * DESCRIPTION
 *  This function is to set the usb state
 *  
 *  PARAMETERS: 
 *  state       [IN]        enum MMI_USB_STATUS
 *  RETURNS: 
 *  void
 *****************************************************************************/
extern void srv_usb_set_status(srv_usb_status_enum state);

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  srv_usb_block_event
 * DESCRIPTION
 *  When application handling EVT_ID_USB_ENTER_MS_MODE and EVT_ID_USB_EXIT_MS_MODE,
 * if it is an asynchronous process, application need call this API to notify USB service to wait
 * process finish to continue enter/exit Mass storage mode.
 * When application finish its process, need call srv_usb_unblock_event to notify USB service.
 * PARAMETERS
 *  event_id  : [IN] It is the event id that application handling.
 * RETURNS
 *  void
 * SEE ALSO
 *  srv_usb_unblock_event
 *****************************************************************************/
extern void srv_usb_block_event(U16 event_id);

/*****************************************************************************
 * FUNCTION
 *  srv_usb_unblock_event
 * DESCRIPTION
 *  When application handling EVT_ID_USB_ENTER_MS_MODE and EVT_ID_USB_EXIT_MS_MODE,
 * if it is an asynchronous process, application need call this srv_usb_block_event to notify USB 
 * service to wait process finish to continue enter/exit Mass storage mode.
 * When application finish its process, need call srv_usb_unblock_event to notify USB service.
 * PARAMETERS
 *  event_id  : [IN] It is the event id that application handling.
 * RETURNS
 *  void
 * SEE ALSO
 *  srv_usb_block_event
 *****************************************************************************/
extern void srv_usb_unblock_event(U16 event_id);

/*****************************************************************************
 * FUNCTION
 *  srv_usb_is_connected
 * DESCRIPTION
 *  Application call this API to check USB cable is connected or not. Notice that this is only the state
 *  of connected, but not Mass storage mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if USB cable is connected, otherwise return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL srv_usb_is_connected(void);

/*****************************************************************************
 * FUNCTION
 *  srv_usb_check_path_exported
 * DESCRIPTION
 *  Application can call this API to check a file path can be exported to PC or not in Mass storage
 *  mode and MTP mode. Exported means the driver the path in is accessible in PC side, and can't
 *  be accessed in Phone side, for example by File manager or application.
 *  The file path should be absolute path.
 * PARAMETERS
 *  path  : [IN] Specific absolute path to check, must contain the driver name, for example, "Z:\\..."
 * RETURNS
 *  MMI_TRUE if the path can't be accessed in Mass storage mode and MTP mode, otherwise return
 *  MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL srv_usb_check_path_exported(WCHAR *path);

/*****************************************************************************
 * FUNCTION
 *  srv_usb_is_in_mass_storage_mode
 * DESCRIPTION
 *  To check is the phone in Mass storage mode or in MTP mode.
 *  If an application can't work in these two mode, it should call this API, if it returns MMI_TRUE, 
 *  application can't access files in public drives, so need do some special process and notify user if 
 *  needed.
 *  Note that this API is available for most cases, but during application is handling 
 *  EVT_ID_USB_ENTER_MS_MODE and EVT_ID_USB_EXIT_MS_MODE, it is a special case that public
 *  is not exported yet, but this API will return MMI_TRUE. In this case, application should call 
 *  srv_usb_is_in_mass_storage_mode_ext instead of this one.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if in Mass storage mode or MTP mode, otherwise return MMI_FALSE.
 * SEE ALSO
 *  srv_usb_is_in_mass_storage_mode_ext
 *****************************************************************************/
extern MMI_BOOL srv_usb_is_in_mass_storage_mode(void);

/*****************************************************************************
 * FUNCTION
 *  srv_usb_is_in_mass_storage_mode_ext
 * DESCRIPTION
 *  If application need access public drive during handling handling 
 *  EVT_ID_USB_ENTER_MS_MODE and EVT_ID_USB_EXIT_MS_MODE, call this API to check USB
 *  mode state, but not blocked as srv_usb_is_in_mass_storage_mode do.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if in Mass storage mode or MTP mode, otherwise return MMI_FALSE.
 * SEE ALSO
 *  srv_usb_is_in_mass_storage_mode
 *****************************************************************************/
extern MMI_BOOL srv_usb_is_in_mass_storage_mode_ext(void);

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  srv_usb_set_reset_type
 * DESCRIPTION
 *  Set reset type
 * PARAMETERS
 *  reset_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_usb_set_reset_type(U8 reset_type);

/*****************************************************************************
 * FUNCTION
 *  srv_usb_is_any_exported_drive
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  True or False
 *****************************************************************************/
extern MMI_BOOL srv_usb_is_any_exported_drive(void);

/*****************************************************************************
 * FUNCTION
 *  srv_usb_is_leaving_ms_mode
 * DESCRIPTION
 *  Query if is exiting from Mass storage/MTP mode
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if in leaving, otherwise return MMI_FALSE
 *****************************************************************************/
#ifdef __USB_IN_NORMAL_MODE__
extern MMI_BOOL srv_usb_is_leaving_ms_mode(void);
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_usb_reset_poweron
 * DESCRIPTION
 *  Reboot phone
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_usb_reset_poweron(void);

/*****************************************************************************
 * FUNCTION
 *  srv_usb_leave_usb_mode
 * DESCRIPTION
 *  Notify USB application to close USB mode screens.
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_usb_leave_usb_mode(void);

/*****************************************************************************
 * FUNCTION
 *  srv_usb_detect_ind_hdlr
 * DESCRIPTION
 *  Handler of USB detect notify message from L4C. Used in MMITask.c
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_usb_detect_ind_hdlr(void *info);
#ifdef __USB_MMI_DEBUG__
extern void srv_usb_ut(U8 index);
#endif
/* DOM-NOT_FOR_SDK-END */

#endif
#endif

