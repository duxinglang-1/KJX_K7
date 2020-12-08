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
 *  vapp_usb_usbmode.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_USB_NORMALMODE_H__
#define __VAPP_USB_NORMALMODE_H__
     
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "mmi_rp_vapp_usbmmi_def.h"
#include "vcp_indicator_popup.h"

class VappUSBNormalModePage : public VfxPage
{
    VFX_DECLARE_CLASS(VappUSBNormalModePage);
    
// Override
public:
    virtual void onInit();
};

typedef struct
{
    VfxId id;
    MMI_ID str;
    MMI_ID string;
} CfgListItemInfoStruct;

typedef enum
{
    ITEM_ID_MS = 0,
    ITEM_ID_COM,
    ITEM_ID_WEBCAM,
    ITEM_ID_JAVA,
    ITEM_ID_MTP,
    ITEM_ID_PICTBRIDGE,
    ITEM_ID_USBTETHERING,
    ITEM_ID_MAX_CANCEL,
    ITEM_ID_MAX_ITEM
} ItemIdEnum;

static const CfgListItemInfoStruct m_listItem[] = 
{
#ifdef __USB_MASS_STORAGE_ENABLE__
    {ITEM_ID_MS, 0, STR_ID_VAPP_USB_CONFIG_MS},
#endif
#ifdef __MMI_WEBCAM__
    {ITEM_ID_WEBCAM, 0, STR_ID_VAPP_USB_WEBCAM},
#endif
#ifdef __USB_COM_PORT_ENABLE__
    {ITEM_ID_COM, 0, STR_ID_VAPP_USB_COM},
#endif
#ifdef __USB_TETHERING__
    {ITEM_ID_USBTETHERING, 0, STR_ID_VAPP_USB_TETHERING},
#endif
#if defined(__J2ME__) && defined(__USB_COM_PORT_ENABLE__)
    {ITEM_ID_JAVA, 0, STR_ID_VAPP_USB_CONFIG_COMPORT_JAVA},
#endif
#ifdef  __MTP_ENABLE__
    {ITEM_ID_MTP, 0, STR_ID_VAPP_USB_CONFIG_MTP},
#endif
#ifdef __MMI_PICT_BRIDGE_SUPPORT__
    {ITEM_ID_PICTBRIDGE, 0, STR_ID_VAPP_USB_CONFIG_PICT_BRIGE},
#endif
    {ITEM_ID_MAX_CANCEL, 0, STR_GLOBAL_CANCEL},
};

typedef enum
    {
        CFG_SUCCESS = 0,
        CFG_FAIL,
        MS_SUCCESS,
        MS_FAIL,
        MTP_SUCCESS,
        MTP_FAIL,
        COM_SUCCESS,
        COM_FAIL,
        JAVA_SUCCESS,
        JAVA_FAIL,
        PICTBRIDGE_SUCCESS,
        SELECT_INVALID,
        INVALID_DURING_CALL,
        CURRENTLY_INVALID,
        NO_MS_FOR_PC,
        SYS_NOT_READY,
        COM_OCCUPIED,
        POPUP_TYPE_MAX_ITEM
    } PopupTypeEnum;

//class VappUSBNormalModeContext;

class VappUSBCommandPopup : public VcpCommandPopup
{
    
public:
    VappUSBCommandPopup()
    {
        m_byBackKey = VFX_FALSE;
    }

    VfxBool isByBackKey(void);
    
protected:
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

private:
    VfxBool m_byBackKey;
};

class VappUSBNormalModeScrn : public VfxAppScr //VfxMainScr
{
    VFX_DECLARE_CLASS(VappUSBNormalModeScrn);

// Override
public:
    VappUSBNormalModeScrn()
    {
        m_page = NULL;
        m_cfgList = NULL;
        m_progress = NULL;
        m_context = NULL;
        m_bShowCfgList = VFX_FALSE;
        setIsSmallScreen();
    }

protected:
    virtual void onInit();
    virtual void onBeforeDeinit();
    virtual void onEnter(VfxBool back);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
	virtual void onRotate(const VfxScreenRotateParam & param);

public:
    void showCfgList(void);
    void closeCfgList(void);
    void resetCfgList(void);
    void showProgress(void);
    void closeProgress(void);
    void setContext(VfxObject *context);
    void showPopup(PopupTypeEnum type);
    static void closeFailPopComfirm(void);
    static void failPopConfirmCallback(VfxId id, void *usrData);
    void onCancelClick(VfxObject* sender, VfxFloat id);
    void onExitProgress(VfxTimer* timer);

private:
    void showInfoBollon(PopupTypeEnum type);
    void showConfirmPopup(PopupTypeEnum type);
    void showMSConfirm(ItemIdEnum itemId);
    
    void onMSConfirmClick(VfxObject* obj, VfxId id);
    void onCommandPopupClick(VfxObject * obj, VfxId id);
    
public:
    VfxSignal0 m_confirmCloseSignal;
    VfxSignal0 m_screenClosedSignal;
    VfxSignal1 <VfxId> m_cfgListSelectSignal;
    
private:
    VappUSBNormalModePage  *m_page;
    VappUSBCommandPopup *m_cfgList;
    VfxBool         m_bShowCfgList;
    VcpIndicatorPopup *m_progress;
    VcpIndicatorPopup *my_progress;
    VfxTimer *timer;
    VfxObject * m_context;
    ItemIdEnum            m_msSelId;
	VcpStatusIconBar *m_statusBar;

private:
    static VfxS32 m_sUsbCheckFialPopId;
};

class VappUSBNormalModeContext : public VfxObject
{

public:
    VappUSBNormalModeContext()
    {
        m_screen = NULL;
        m_inst = this;
    }

public:
    void preShowCfgList(void);
    void preShowCfgListCheck(void);
    void showCfgList(void);
    void closeCfgList(void);
    void onCommandPopupClick(VfxId id);
    void showProgress(void);
    void closeProgress(void);
    void showPopup(PopupTypeEnum type);
    static void showInfoBollon(PopupTypeEnum type);
    static void showStaticComfirm(PopupTypeEnum type);
    static void closeStaticComfirm(void);
    static void staticConfirmCallback(VfxId id, void *usrData);
    void usbCfgRspHdlr(VfxU8 mode, VfxBool result);
    static VfxBool preShowCfgListNotify(void);
    void createScreen(void);
    void closeScreen(void);
    void exitWebCam(void);
    
private:
    static VfxBool mmiPermitCheck(void);
    void configMSMTP(devusb_cfg_action_enum action);
    void configCOM(void);
    void configWebcam(void);
    VfxBool needReboot(void);
    VfxBool wapSysRead(void);
    void confirmCloseHdlr(void);
    void onScreenClosed(void);

public:
    static VcpPopupTypeEnum m_globalPopupType;
    static VfxResId m_globalPopupString;
    static VappUSBNormalModeContext *m_inst;
    VfxSignal0 m_screenClosedSignal;
    
private:
    VappUSBNormalModeScrn *m_screen;
    static VfxS32 m_staticConfirm;
};

#endif
