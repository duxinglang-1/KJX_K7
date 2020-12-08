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
 *  vapp_certman_list_ui.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Header file for venus certificate manager list UI.
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_CERTMAN_LIST_UI_H__
#define __VAPP_CERTMAN_LIST_UI_H__
#ifdef __CERTMAN_SUPPORT__
#ifdef __COSMOS_MMI_PACKAGE__ 

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vapp_certman_gprot.h"
#include "vapp_certman_base_ui.h"
#include "vapp_certman_list_ui.h"
#include "vcp_tabctrl_page.h"
#include "vcp_menu_popup.h"

/*****************************************************************************
 * Class VappCertmanListApp
 ****************************************************************************/
/*
 * This class is for the certificate manager application which is launched from
 * security menu.
 *
 */
class VappCertmanListApp : public VfxCui
{
    VFX_DECLARE_CLASS(VappCertmanListApp);
public:
    void onRun(void* args, VfxU32 argSize);
};


/*****************************************************************************
 * Class VappCertmanCertListScr
 ****************************************************************************/
/*
 * This class is for the certificate manager screen which is launched from
 * security menu.
 *
 */
class VappCertmanCertListScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappCertmanCertListScr);
public:

// Declaration
    typedef enum
    {
        TAB_CONTAINER_PAGE_ID = 1,
        AUTH_CERT_TAB_PAGE_ID,
        USER_CERT_TAB_PAGE_ID,
        CERT_DETAILS_PAGE_ID,
        KEY_USAGE_PAGE_ID,
        MAX_PAGE_ID
    }vapp_certman_list_scrn_page_id_enum;

// Method
    void on1stReady();
};

/*****************************************************************************
 * Class VappCertmanListPageUser
 ****************************************************************************/
/*
 * 
 * 
 *
 */

class VappCertmanListPageUser
{
public:
    virtual void vapp_certman_select_certificates_rsp(VfxBool result, VfxU32 count, VfxU32* cert_id) = 0;
};


typedef enum
{
    VAPP_CERTMAN_LIST_IGNORE_LONG_TAP,
    VAPP_CERTMAN_LIST_LAUNCH_CONTEXT_MENU,
    VAPP_CERTMAN_LIST_MAX_LONG_TAP_BEHAVIOR
}VappCertmanCertListLongTapBehaviorEnum;


typedef enum
{
    VAPP_CERTMAN_LIST_IGNORE_TAP,
    VAPP_CERTMAN_LIST_VIEW_CERT,
    VAPP_CERTMAN_LIST_SELECT_CERT,
    VAPP_CERTMAN_LIST_SELECT_CERT_MULTIPLE,
    VAPP_CERTMAN_LIST_MAX_TAP_BEHAVIOR,
    TOTAL
}VappCertmanCertListTapBehaviorEnum;


class VappCertmanCertListPage;

class VappCertmanCertListBehavior
{
    VappCertmanCertListLongTapBehaviorEnum LongTapBehavior;
    VappCertmanCertListTapBehaviorEnum     TapBehavior;
    VappCertmanCertListPage* list_page;

public:

    VappCertmanCertListBehavior(VappCertmanCertListPage* list_page);
    
    void m_HandleLongTapCertItem(VcpListMenu *sender, VfxU32 index);
    void m_HandleTapCertItem(VcpListMenu *sender, VfxU32 index);

    void SetLongTabBehavior(VappCertmanCertListLongTapBehaviorEnum behavior);
    void SetTapBehavior(VappCertmanCertListTapBehaviorEnum behavior);
};


/*****************************************************************************
 * Class VappCertmanCertListPage
 ****************************************************************************/
/*
 * This class is for a page which displays the list of certificates installed
 * on the phone. To use this class just create the page and push it on the screen.
 * User need to provide the list filters. There are two types of constructor.
 * 
 * EXAMPLE
 * <code>
 *
 * VFX_OBJ_CREATE_EX(page, VappCertmanCertListPage, this, 
 *                   (
 *                    CERTMAN_CERTGRP_ROOTCA |CERTMAN_CERTGRP_OTHERUSER|CERTMAN_CERTGRP_CA,
 *                    VAPP_CERTMAN_PUBKEY_TYPE_ALL, VappCertmanCertListPage::LIST_PURPOSE_VIEW_CERT, NULL
 *                   )
 *                  );
 * 
 * VFX_OBJ_CREATE_EX(page, VappCertmanCertListPage, this, 
 *                   (select_user_cert_ind.key_purpose,
 *                    CERTMAN_CERTGRP_NONE,
 *                    VAPP_CERTMAN_PUBKEY_TYPE_ALL,
 *                    VappCertmanCertListPage::LIST_PURPOSE_SELECT,
 *                    (VfxU32*)select_user_cert_ind.pubkey_types,
 *                    select_user_cert_ind.pubkey_type_num,
 *                    select_user_cert_ind.issuer_filename,
 *                    this
 *                   )
 *                  );
 * </code>
 */

class VappCertmanCertListPage : public VfxPage, public IVcpListMenuContentProvider, public VappCertmanDataUser
{

public:
    typedef enum
    {
        LIST_PURPOSE_VIEW_CERT,
        LIST_PURPOSE_SELECT,
        LIST_PURPOSE_SELECT_MULTIPLE,
        LIST_PURPOSE_MAX
    }vapp_certman_list_purpose_enum;

private:
    typedef enum
    {
        OK_BUTTON_ID = 1,
        CANCEL_BUTTON_ID
    }vapp_certman_list_tb_button_id;

    VfxU32 list_purpose;
    VappCertmanListPageUser* list_user;
    VcpActivityIndicator *progress_popup;
    void onInit(void);

public:

    // Constructor
    VappCertmanCertListPage(
        VfxU32 cert_group,                           //
        VfxU32 key_type,                             //
        VfxResId title,
        vapp_certman_list_purpose_enum list_purpose, //
        VappCertmanListPageUser* list_user           //
        );

    // Constructor
    VappCertmanCertListPage(
        VfxU32 key_purpose,                          //
        VfxU32 cert_group,                           //
        VfxU32 key_type,                             //
        vapp_certman_list_purpose_enum list_purpose, //
        VfxU32 *pubkey_types,                        //
        VfxU32 pubkey_type_num,                      //
        VfxWChar *issuer_filename,                   //
        VappCertmanListPageUser* list_user           //
        );

    void setMenu(VcpListMenu *)
    {
    }

    VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    virtual VfxBool getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color);

    VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        );

    void closeItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxImageSrc Image               // [IN] the image resource
        ){}

    VfxU32 getCount() const;

    // Get the state of a list item
    VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const;

    VfxBool swapItem(
        VfxU32 index1, // [IN] index of the first item
        VfxU32 index2  // [IN] index of the second item
        )
    {
        return VFX_FALSE;
    }

    VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,        // [IN] index of the item
        VfxFrame *parentFrame // [IN] parent frame of the custom content frame
        )
    {
        return NULL;
    }

    void closeItemCustomContentFrame(
        VfxU32 index,  // [IN] index of the item
        VcpListMenuCellClientBaseFrame *cell // [IN] the content frame to be released
        )
    {
        // move to .cpp if required
    }

    void updatelistmenu(void);   /* Redraw UI on basis of data on APP */

    void refresh_list(void);   /* Get fresh data from APP */

    void VappCertmanDataRspHndlr(void* msg);

    const VappCertmanCertListData& GetCertListDataObj(void);

    void onBack();

private:
    VfxU32 focused_index;
    VcpListMenu *listmenu;
    VfxResId title;
    VappCertmanCertListData certificate_list_data;
    VappCertmanCertListBehavior cert_list_behavior;
    VfxWString empty_text;

    /* encapsulate below methods to behavior class*/
    void m_signalTapCertItem(VcpListMenu *sender, VfxU32 index);
    void m_signalItemLongTapped(VcpListMenu *sender, VfxU32 index);
    void m_signalCertFocusChanged(VcpListMenu *sender, VfxU32 Currindex, VfxU32 Previndex);
    void onToolBarClick(VfxObject* sender, VfxId id);
};

class VappCertmanCertListMenuPopup : public VcpMenuPopup
{
    typedef enum
    {
        POPUP_MENU_ID_KEY_USAGE,
        POPUP_MENU_ID_DELETE,
        POPUP_MENU_ID_MAX
    };
    VappCertmanCertListDataItem* cert_list_item;
    VfxMainScr *m_appscr;
public:
    VappCertmanCertListMenuPopup(VappCertmanCertListDataItem* cert_list_item);
    void onInit(void);
    void m_signalTapItem(VcpMenuPopup*, VcpMenuPopupEventEnum, VcpMenuPopupItem*);
};

class VappCertmanCertListTabContainer : public VcpTabCtrlPage
{
    // Override
public:
    void onInit();
    VappCertmanCertListPage *get_auth_list_page(void);
    VappCertmanCertListPage *get_user_list_page(void);

protected:
    VfxPage* onCreateTabPage(VfxId tabId);

private:

    /* TabCtrlPage does not provide any method to access its pages
       So keeping there references here
    */
    VappCertmanCertListPage *auth_list_page;
    VappCertmanCertListPage *user_list_page;
};


class VappCertmanViewDetailsPage : public VappCertmanDetailsPage
{
    typedef enum
    {
        KEY_USAGE_BUTTON_ID,
        DELETE_BUTTON_ID
    }view_details_page_button_enum;

    VappCertmanCertListDataItem* cert_list_item;
    VfxU32 cert_prop;
    void setuptoolbar(void);
public:
    VappCertmanViewDetailsPage(VappCertmanCertListDataItem* cert_list_item);
    void onToolBarClick(VfxObject* sender, VfxId id);
    void onDeleteCnfPopupClick(VfxObject* sender, VfxId id);
};


class VappCertmanViewKeyUsagePage : public VappCertmanKeyUsagePage
{
    VappCertmanCertListDataItem *cert_list_item;
public:
    VappCertmanViewKeyUsagePage(VappCertmanCertListDataItem* cert_list_item);
    virtual void onToolBarClick(VfxObject* sender, VfxId id);
};


class VappCertmanDeleteCnfPopup : public VcpConfirmPopup
{
    VappCertmanCertListDataItem* cert_list_item;
    VfxMainScr *m_appscr;
public:
    VappCertmanDeleteCnfPopup(VappCertmanCertListDataItem* cert_list_item, VfxMainScr *m_appscr);
    void OnClick(VfxObject* sender, VfxId id);
};


class VappCertmanDeletingProgressPopup : public VcpActivityIndicator, public VappCertmanDataUser
{
    VappCertmanCertListDataItem* cert_list_item;
    VappCertmanDeleteReqData delete_req_data;
public:
    void VappCertmanDataRspHndlr(void* msg);
    VappCertmanDeletingProgressPopup(VappCertmanCertListDataItem* cert_list_item);
};


class VappCertmanKeyUsageUpdateProgressPopup : public VcpActivityIndicator, public VappCertmanDataUser
{
    VappCertmanCertListDataItem* cert_list_item;
    VappCertmanKeyUsageUpdateReqData key_usage_update_req_data;
public:
    void VappCertmanDataRspHndlr(void* msg);
    VappCertmanKeyUsageUpdateProgressPopup(VappCertmanCertListDataItem* cert_list_item);
};


/* select cert ui */

class VappCertmanSelectList : public VfxApp
{
    VFX_DECLARE_CLASS(VappCertmanSelectList);
public:
    void onRun(void* args, VfxU32 argSize);
    ~VappCertmanSelectList(void);
};

class VappCertmanSelectCertScr : public VfxMainScr, public VappCertmanListPageUser
{
    //VFX_DECLARE_CLASS(VappCertmanSelectCertScr);
    vapp_certman_select_cert_ind_struct select_cert_ind;
public:
    void vapp_certman_select_certificates_rsp(VfxBool result, VfxU32 count, VfxU32* cert_id);
    VappCertmanSelectCertScr(void* msg);
    void on1stReady(void);
};


/* select user cert ui */
class VappCertmanSelectUserCertListApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappCertmanSelectUserCertListApp);
public:
    void onRun(void* args, VfxU32 argSize);
    ~VappCertmanSelectUserCertListApp(void);
};


class VappCertmanSelectUserCertScr : public VfxMainScr, public VappCertmanListPageUser
{
    //VFX_DECLARE_CLASS(VappCertmanSelectCertScr);
    vapp_certman_select_user_cert_ind_struct select_user_cert_ind;
public:
    void vapp_certman_select_certificates_rsp(VfxBool result, VfxU32 count, VfxU32* cert_id);
    VappCertmanSelectUserCertScr(void* msg);
    void on1stReady(void);
};


/* interface message handler class */
void vapp_certman_launch_cert_list_ind_handler(void);

#endif /* __COSMOS_MMI_PACKAGE__ */
#endif /* __CERTMAN_SUPPORT__ */
#endif /* __VAPP_CERTMAN_LIST_UI_H__ */
