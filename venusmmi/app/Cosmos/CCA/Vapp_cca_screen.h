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
#ifndef __VAPP_CCA_SCREEN_H__
#define __VAPP_CCA_SCREEN_H__

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_global_popup.h"

typedef enum
{
    POPUP_TYPE_INVALID_PIN = 0,
    POPUP_TYPE_MEM_FULL,
    POPUP_TYPE_INVAID_MSG,
    POPUP_TYPE_NO_APP,
    POPUP_TYPE_NO_AVAILABLE,
    POPUP_TYPE_AUTH_FAIL,
    POPUP_TYPE_PIN_ABORT,
    POPUP_TYPE_PIN_RETRY,
    POPUP_TYPE_PIN_FAIL,
    POPUP_TYPE_PIN_MAX_RETRY,
    POPUP_TYPE_UPDATE_MSG_FAIL,       
    POPUP_TYPE_GET_MSG_FAIL,
    POPUP_TYPE_PIN_PASS,    
    POPUP_TYPE_MAX_ITEM
} popup_type_enum;

typedef enum
{
    SCREEN_SEL_PIN = 0,
    SCREEN_SEL_PIN_CANCEL,
    SCREEN_SEL_INSTALL,
    SCREEN_SEL_INSTALL_CANCEL,
    SCREEN_SEL_INSTALL_RESULT,
    SCREEN_SEL_POPUP_OK,
    SCREEN_SEL_INVALID_PIN_POPUP_OK,
    SCREEN_SEL_MAX_ITEM
} screen_sel_result_enum;

class VappCCAEventSimpleObject : public VfxObject
{
    VFX_DECLARE_CLASS(VappCCAEventSimpleObject);
    
public:
    VappCCAEventSimpleObject()
    {
        m_value = 0;
    }

    VappCCAEventSimpleObject(VfxS32 value)
    {
        m_value = value;
    }

public:
    VfxS32 m_value;
};

class VappCCAInstallInfoItem : public VfxObject
{
    VFX_DECLARE_CLASS(VappCCAInstallInfoItem);

public:
    VappCCAInstallInfoItem()
    {
        m_id = 0;
        m_dependId = 0;
        m_appId = 0;
        m_state = 0;
        m_selected = 0;
    }
	
    VappCCAInstallInfoItem(VappCCAInstallInfoItem* obj)
    {
        m_id = obj->m_id;
        m_dependId = obj->m_dependId;
        m_appId = obj->m_appId;
        m_state = obj->m_state;
        m_selected = obj->m_selected;
    }
    
public:
    VfxU32 m_id;
    VfxU32 m_dependId;
    VfxU16 m_appId;
    VfxU16 m_state;
    VfxU16 m_selected;
};

class VappCCAMMIDataPack : public VfxObject
{
public:
    void addData(VfxObject* data);
    VfxObject* getData(VfxU32 index);
    VfxS32     getDataCount(void);
    void closeAll(void);
private:
    VfxObjList m_instList;
};

class VappCCAListProvider : public VfxObject, public IVcpListMenuContentProvider
{
public:
    VappCCAListProvider()
    {
        m_data = NULL;
    }
    
    virtual VfxU32 getCount() const;
    
    virtual VfxBool getItemText(
        VfxU32 index, 
        VcpListMenuFieldEnum fieldType,          
        VfxWString &text,                        
        VcpListMenuTextColorEnum &color);
        
    /* Provide the item states, in this sample, they are the selection state of radio buttons */
    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index
        ) const;

    void setContent(VappCCAMMIDataPack *data);
    VappCCAMMIDataPack * getContent(void);

    VfxObject* getItem(VfxS32 index) const;
    VfxS32     getItemCount(void);
    VfxWString getAppName(VfxU32 appId);
    VfxWString getStateString(VfxU16 state);

private:
    
    
private:
    VappCCAMMIDataPack *m_data;
};

class VappCCAPage : public VfxPage
{
public:
    typedef enum
    {
        PAGE_ID_INSTALL_LIST = 1,
        PAGE_ID_PRE_INSTALL,
        PAGE_ID_INSTALL_RESULT,
        PAGE_ID_MAX_ITEM
    } page_id_enum;

    typedef enum
    {
        BTN_ID_INSTALL = 0,
        BTN_ID_CANCEL,
        BTN_ID_INSTALL_RESULT_OK,
        BTN_ID_MAX_ITEM
    } btn_id_enum;
    
    typedef enum
    {
        LIST_SEL_INSTALL = 0,
        LIST_SEL_INSTALL_CANCEL,
        LIST_SEL_INSTALL_RESULT_OK,
        LIST_SEL_HOME_KEY,
        LIST_SEL_MAX_ITEM
    } list_sel_type_enum;

    
public:
    VappCCAPage();
    VappCCAPage(page_id_enum pageId, VappCCAMMIDataPack *data);

    virtual void onInit();
    void createInstallResultList(page_id_enum pageId);

protected:
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    virtual void onQueryRotateEx(VfxScreenRotateParam & param)
    {
        //support all rotation
    }

private:
    void onListSelect(VfxObject* obj, VfxId id);
    void onListItemStateChanged(VcpListMenu* obj, 
        VfxU32 index, 
        VcpListMenuItemStateEnum newState);
    void updateButtons(void);
    void disableButtons(void);
    void setContentText(VcpTextView *view);
    VfxS32 getContentText(VfxWChar *textBuf, VfxS32 bufLen);
    void showProgress(void);
    void closeProgress(void);
public:
    VfxSignal3 <page_id_enum, list_sel_type_enum, VappCCAMMIDataPack*> m_listSelSignal;

private:
    page_id_enum m_pageId;
    VappCCAListProvider m_content;
    VcpToolBar *m_toolBar;
    VcpActivityIndicator *m_progress;
};

void globalPopupCallback (VfxId id, void *usrData);
void globalPinPopupCallback (VfxId id, void *usrData);
void globalPopupInvalidPinCallback (VfxId id, void *usrData);

class VappCCAPinScreen : public VfxAppScr
{
    friend void globalPopupInvalidPinCallback (VfxId id, void *usrData);
    friend void globalPinPopupCallback (VfxId id, void *usrData);

private:
    #define PIN_VERIFY_MAX_LEN  (SRV_CCA_MAX_PIN_CHARS + 1)

public:
    VappCCAPinScreen()
    {
        m_pinPopup = NULL;
        m_dataPack = NULL;
        m_popup = 0;
        setIsSmallScreen();
    };

    void showPinVerify(void);
    void closePinVerify(void);
    void showPopup(popup_type_enum type);
    void onBeforeDeinit();
    
protected:
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onObjectNotify(VfxId id, void *userData);
    virtual void onQueryRotateEx(VfxScreenRotateParam & param);

private:
    void onPinButtonClicked(VfxObject* sender,VcpInputPopupButtonEnum id);
    void onPinPopupBackClose(VcpInputPopup *sender);

public:
    VfxSignal2 <screen_sel_result_enum, VappCCAMMIDataPack*> m_screenSelSignal;
    
private:
    VcpInputPopup *m_pinPopup;
    VappCCAMMIDataPack *m_dataPack;
    VfxS32 m_popup;
    VfxScrRotateTypeEnum m_dir;
};



class VappCCAScreen : public VfxMainScr
{
    friend void globalPopupCallback (VfxId id, void *usrData);
    friend void globalPopupInvalidPinCallback (VfxId id, void *usrData);

public:
    //#define PIN_VERIFY_MAX_LEN  (SRV_CCA_MAX_PIN_CHARS + 1)
    
public:
    VappCCAScreen();

    void showPreInstall(VappCCAMMIDataPack *data);

    void showPreInstallSummary(VappCCAMMIDataPack *data);
    void closePreInstallSummary(void);

    void showInstallList(VappCCAMMIDataPack *data);
    void closeInstallList(void);

    void showInstallSummary(VappCCAMMIDataPack *data);
    void closeInstallSummary(void);

    void showInstallResult(VappCCAMMIDataPack *data);
    void closeInstallResult(void);
    void onBeforeDeinit();

protected:
    virtual void onQueryRotateEx(VfxScreenRotateParam & param)
    {
        //support all rotation
    }
    virtual void onObjectNotify(VfxId id, void *userData);
    
private:
    void onPopupButtonClicked(VfxObject* sender, VfxId id);
    void onListSelect(VappCCAPage::page_id_enum id,
        VappCCAPage::list_sel_type_enum sel,
        VappCCAMMIDataPack* data);
    void setDataPack(VappCCAMMIDataPack *pack);
    VappCCAMMIDataPack * getDataPack(void);
    void clearDataPack(void);

public:
    VfxSignal2 <screen_sel_result_enum, VappCCAMMIDataPack*> m_screenSelSignal;

private:
    VappCCAMMIDataPack *m_dataPack;
    VfxS32 m_popup;
};

VfxS32 showNMGRGlobalPopup(VcpPopupTypeEnum type, VfxResId str, PopupCallBackPtr cb, void *data);
VfxS32 showGlobalPopup(popup_type_enum type);

#endif /* __VAPP_CCA_SCREEN_H__*/

