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
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUN157DER WILL BE,
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
 *  vapp_usb.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_USB_H__
#define __VAPP_USB_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
class VfxApp;
#ifdef __cplusplus
extern "C"
{
#include "USBSrvIprot.h"
#include "USBSrvGProt.h"
#include "Device.h"
}
#endif
#include "Vapp_usb_usbmode.h"
#include "Vapp_usb_normalmode.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifdef __USB_MMI_DEBUG__

#ifndef __MTK_TARGET__
#ifndef __MMI_USB_SUPPORT__
#define __MMI_USB_SUPPORT__
#endif
#endif
#endif

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
extern "C" void vapp_usb_init_normalmode(void);
typedef void (*usbAppBlockedFunc)(void *);

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappUSBApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappUSBApp);
    
// Override
public:
    VappUSBApp()
    {
        VappUSBApp::m_inst = this;
        m_usbModeContext = NULL;
        m_normalModeContext = NULL;
        //m_blockedFunc = NULL;
        //m_blockedFuncData = NULL;
    }

    virtual ~VappUSBApp()
    {
        VappUSBApp::m_inst = NULL;
    }
    
/* Static functions*/
public:
    static void initApp(power_on_status_enum mode);
    static void initUSBMode(void);
    static void initNormalMode(void);
    static void initChargerMode(void);
    static power_on_status_enum getUsbMode(void);
    static void setAppBlockFunc(usbAppBlockedFunc func, void *data);
    static usbAppBlockedFunc getAppBlockFunc(void);
    static void runAppBlockFunc(void);
    
public:
    void chargerNotifyHdlr(VfxU16 status, VfxU8 level);
    void usbSrvNotifyHdlr(srv_usb_mmi_notify_action_enum action);
    void usbCfgRspHdlr(VfxU8 mode, VfxBool result);
    void usbPlugInHdlr(void);
    void usbPermitPreCheckHdlr(void);
    void usbPermitCheckHdlr(void);

protected:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onDeinit();
    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);
    
private:
    void onPowerOffRemoved(void);
    void onNormalModeSrvNotify(srv_usb_mmi_notify_action_enum action);
    void onContextScreenClosed(void);
    void terminate(void);
    void showCfgList(void);
    void onContextClose(void);
    void updatePowerOnMode(void);
    
public:
	static VappUSBApp *m_inst;

private:
    VappUSBModeContext *m_usbModeContext;
    VappUSBNormalModeContext *m_normalModeContext;
    static power_on_status_enum m_powerOnMode;
    static usbAppBlockedFunc m_blockedFunc;
    static void *m_blockedFuncData;
};

#endif /* __VAPP_USB_H__ */

