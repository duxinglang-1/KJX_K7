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
 *  vapp_usb_basecontext.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h" 

#if defined(__MMI_USB_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
//#ifdef __cplusplus
//extern "C"

#include "MMI_include.h"
#include "mmi_rp_vapp_usbmmi_def.h"
#include "USBDeviceGProt.h"
#include "USBSrvIprot.h"
#include "USBSrvGProt.h"


extern  kal_bool USB_Boot_With_MS(void);
extern  void srv_usb_detect_ind_hdlr(void *info);
extern void vapp_usb_init_normalmode(void);
extern void vapp_usb_unavailable_popup(S32 str);

void InitMMIUsbContext(void)
{
    vapp_usb_init_normalmode();
}

pBOOL mmi_usb_check_path_exported(S8 *path)
{
    return srv_usb_check_path_exported((WCHAR*)path);
}

pBOOL mmi_usb_is_in_mass_storage_mode(void)
{
    return srv_usb_is_in_mass_storage_mode();
}

void UsbDetectIndHdlr(void *info)
{
    srv_usb_detect_ind_hdlr(info);
}

void UsbPwnOnThenPwnOn(void)
{
    if (srv_usb_get_status() == SRV_USBSTATUS_MS)
    {
	    if (USB_Boot_With_MS()==KAL_FALSE)
        {
        #ifdef __MTP_ENABLE__
            srv_usb_send_config_to_hw(DEVUSB_CFG_ACTION_STOP_MTP);
    	#endif
        }
        else
    	{
            srv_usb_send_config_to_hw(DEVUSB_CFG_ACTION_STOP_MS);
        }
		
       srv_usb_set_status(SRV_USBSTATUS_MS_PROC);    
    }    
    else
    {
    	srv_usb_set_reset_type(CHARGING_RESET);
        srv_usb_send_power_on_req();
    }
}

pBOOL mmi_usb_is_leaving_ms_mode(void)
{
    #ifdef __USB_IN_NORMAL_MODE__
    return srv_usb_is_leaving_ms_mode();
	#else
	return MMI_FALSE;
	#endif
}

 void mmi_usb_app_unavailable_popup(U16 stringId)
{
    vapp_usb_unavailable_popup((S32)stringId);
}

MMI_STR_ID mmi_usb_get_error_info(S32 error_result, mmi_event_notify_enum* popup_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     if (popup_type)
        *popup_type = MMI_EVENT_FAILURE;
#ifdef  __MTP_ENABLE__
        if (srv_usb_get_owner() == SRV_USB_MS_STORAGE_MTP)
            return STR_ID_VAPP_USB_NOT_AVAILABLE_IN_MTP_MODE;
#endif
        return STR_GLOBAL_NOT_AVAILABLE_IN_MASS_STORAGE_MODE;
}

#endif


