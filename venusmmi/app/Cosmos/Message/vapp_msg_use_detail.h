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
 *  vapp_msg_use_detail.h
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
 * -------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_MSG_USE_DETAIL_H__
#define __VAPP_MSG_USE_DETAIL_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "app_usedetails.h"
#include "vcui_phb_gprot.h"

#ifdef __cplusplus
extern "C"
#endif
{
    #include "UcSrvGprot.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
class VappMsgUseDetailProvider;
class VappMsgAddrOption;


/***************************************************************************** 
 * Class 
 *****************************************************************************/
enum VappMsgAddrType
{
    VAPP_MSG_ADDR_TYPE_NONE,
    VAPP_MSG_ADDR_TYPE_PHONENUMBER,
    VAPP_MSG_ADDR_TYPE_URL,
    VAPP_MSG_ADDR_TYPE_EMAIL,
    VAPP_MSG_ADDR_TYPE_USSD,

    VAPP_MSG_ADDR_TYPE_TOTAL
};

class VappMsgAddrItem : public VfxBase
{
public:
    VappMsgAddrItem() : m_type(VAPP_MSG_ADDR_TYPE_NONE) {};

    VappMsgAddrItem(VfxWString& text, VappMsgAddrType type)
    {
        m_text = text;
        m_type = type;
    };

    VappMsgAddrItem(VappMsgAddrItem& addrItem)
    {
        m_text = addrItem.m_text;
        m_type = addrItem.m_type;
    };

    VappMsgAddrItem& operator = (VappMsgAddrItem& assignItem)
    {
        m_text = assignItem.m_text;
        m_type = assignItem.m_type;

        return *this;
    }

public:
    VfxWString m_text;
    VappMsgAddrType m_type;
};
#ifdef __MMI_SMS_DETAILS_INFO__	

class VappMsgUseDetailPage : public VfxPage
{
public:
    VappMsgUseDetailPage();
    virtual ~VappMsgUseDetailPage() {};

    void setProvider(VappMsgUseDetailProvider& provider);
    VfxBool addAddrItem(VfxWString& text, VappMsgAddrType type);
    VfxBool addAddrItem(VappMsgAddrItem& addrItem);

protected:
    virtual void onInit(void);
    virtual void onQueryRotateEx(VfxScreenRotateParam & param);

private:
    void onItemTapped(VcpListMenu* listMenu, VfxU32 index);
    void onCmdButtonClicked(VcpListMenu* listMenu, VfxU32 index);
    void onPopupButtonClicked(VfxObject* obj, VfxId id);
    void onPopupStateChanged(VfxBasePopup* popup, VfxBasePopupStateEnum state);

private:
    VappMsgUseDetailProvider *m_provider;
	VcpListMenu *m_listMenu;
    VappMsgAddrOption *m_addrOtion;
    mmi_sim_enum m_dialSimId;
    VfxBool m_isDialNumber;
};

class VappMsgUseDetailProvider : public VfxObject, public IVcpListMenuContentProvider
{
public:
    VappMsgUseDetailProvider();
    VappMsgUseDetailProvider(VappMsgUseDetailProvider& copyProvider);
    virtual ~VappMsgUseDetailProvider(){};

    void setSimId(mmi_sim_enum simId);
    mmi_sim_enum getSimId(void);

    VfxBool addAddrItem(VfxWString& text, VappMsgAddrType type);
    VfxBool addAddrItem(VappMsgAddrItem& addrItem);

    VappMsgAddrItem& getAddrItem(VfxU32 index);

    virtual VfxBool getItemText(
                VfxU32 index,
                VcpListMenuFieldEnum fieldType,
                VfxWString& text,
                VcpListMenuTextColorEnum& color);

    virtual VfxBool getItemImage(
                VfxU32 index,
                VcpListMenuFieldEnum fieldType,
                VfxImageSrc& image);

    virtual VfxU32 getCount(void) const;

    virtual VcpListMenuCmdStateEnum getItemCmdState(VfxU32 index) const;

private:
    enum
    {
        MAX_ADDR_ITEM = 40
    };

    enum IconIndexEnum
    {
        ICON_DIAL         = 0,
    #if (MMI_MAX_SIM_NUM >= 2)
        ICON_DIAL_SIM2,
    #endif
	#if (MMI_MAX_SIM_NUM >= 3)
        ICON_DIAL_SIM3,
    #endif
	#if (MMI_MAX_SIM_NUM >= 4)
        ICON_DIAL_SIM4,
    #endif
    #ifdef __MMI_EMAIL__       
        ICON_SEND_EMAIL,
    #endif
        ICON_GO_TO_URL,

        ICON_TOTAL
    };

    enum IconStateEnum
    {
        ICON_STATE_NORNAL       = 0,
        ICON_STATE_PRESSED,
        ICON_STATE_DIALBLED,

        ICON_STATE_TOTAL
    };

    static const VfxResId m_buttonIcon[ICON_TOTAL][ICON_STATE_TOTAL];
    VappMsgAddrItem m_addrItem[MAX_ADDR_ITEM];
    VfxU32 m_count;
    mmi_sim_enum m_simId;
};
#endif
class VappMsgAddrOption : public VfxControl
{
public:
    VappMsgAddrOption();

    void setAddrItem(VfxWString& addr, VappMsgAddrType addrType);
    void setAddrItem(VappMsgAddrItem& addrItem);

    void show(VfxPage *page);
	void setInViewerPage(VfxBool isInViewerPage);
    void dialNumber(mmi_sim_enum sim_id);
    void editBeforeCall(void);
    void gotoUrl(void);
#ifdef __MMI_EMAIL__
    void sendEmail(void);
#endif

protected:
    virtual void onDeinit(void);

private:
    void sendMessage(void);
    static void removePhoneNumberSeparator(VfxWChar *dest, const VfxWChar *src);

    void OnButtonClicked(VfxObject* obj, VfxId id);
    //void onPopupStateChanged(VfxBasePopup* popup, VfxBasePopupStateEnum state);
    void saveContact(vcui_phb_save_contact_type_enum tpye);
#if defined(__MMI_VUI_SAVE_BOOKMARK_SUPPORT__) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
    void saveToBookmark(void);
#endif /* __MMI_VUI_SAVE_BOOKMARK_SUPPORT__ */

    static mmi_ret onCuiProc(mmi_event_struct *evt);

private:
    enum buttonId
    {
        BUTTON_EDIT_BEFORE_CALL,
        BUTTON_SEND_MESSAGE,
        BUTTON_ADD_AS_NEW_CONTACT,
        BUTTON_ADD_TO_EXISTING_CONTACT,

        BUTTON_GOTO_URL,
        BUTTON_SAVE_TO_BOOKMARK,

        BUTTON_SEND_EMAIL,

        BUTTON_CANCEL,
            
        BUTTON_TOTAL
    };

private:
    VappMsgAddrItem m_addrItem;
    VfxId m_clickedButton;
    VcpCommandPopup *m_cmdPopup;
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
    srv_uc_addr_struct m_ucAddr;
#endif  /*(__MMI_UNIFIED_COMPOSER__) || (__MMI_MMS_STANDALONE_COMPOSER__)*/
	VfxBool m_isInViewPage;
};

#endif /* __VAPP_MSG_USE_DETAIL_H__ */

