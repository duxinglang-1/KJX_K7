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
 *  vapp_cnmgr_setting.h
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  This is FTO CNMGR application header file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_CNMGR_SETTING_H__
#define __VAPP_CNMGR_SETTING_H__

#ifdef __TCPIP__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "MMI_features.h"
#include "CnmgrSrvGprot.h"
#include "cbm_consts.h"

#ifdef __cplusplus
}
#endif

#ifdef __MMI_CBM_CONNECTION_MANAGER__

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_CNMGR_DATA_UNIT_SIZE 1024
#define VAPP_CNMGR_HOUR_TO_SEC 3600
#define VAPP_CNMGR_MIN_TO_SEC 60

/* The trace group of CNMGR Application */
#define VAPP_CNMGR_TRC_GROUP MMI_CONN_TRC_INFO


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

typedef enum
{
  VAPP_CNMGR_DETAIL_INFO_SETTING = 0,
  VAPP_CNMGR_DETAIL_INFO_TYPE,
  VAPP_CNMGR_DETAIL_INFO_CONNECT_STATUS,
  VAPP_CNMGR_DETAIL_INFO_CONNECT_TIME,
  VAPP_CNMGR_DETAIL_INFO_ALL_DATA_SIZE,
  VAPP_CNMGR_DETAIL_INFO_RECV_DATA_SIZE,
  VAPP_CNMGR_DETAIL_INFO_SENT_DATA_SIZE,
  VAPP_CNMGR_DETAIL_INFO_UPLOAD_RATE,
  VAPP_CNMGR_DETAIL_INFO_DOWNLOAD_RATE,
  VAPP_CNMGR_DETAIL_INFO_TOTAL
} vapp_cnmgr_detail_info_enum;

typedef enum
{
  VAPP_CNMGR_DETAIL_FILTER_NO_SETTING = 0x01,
  VAPP_CNMGR_DETAIL_FILTER_NO_TRANSMISSION_DATA = 0x02
} vapp_cnmgr_detail_filter_enum;

typedef struct
{
  VfxU64 all_data_size;
  VfxU64 connect_time;
  VfxU32 account_id;
  VfxU8 connect_type;
  VfxU8 dialup_type;
  VfxWString profile_name;
} vapp_cnmgr_bearer_node_struct;

typedef struct
{
  vapp_cnmgr_bearer_node_struct bearer[SRV_CNMGR_MAX_BEARER_NUM];
  VfxU8 bearer_num;
} vapp_cnmgr_bearer_list_struct;

typedef struct
{
  VfxU64 all_data_size;
  VfxU64 recv_data_size;
  VfxU64 sent_data_size;
  VfxU64 upload_rate;
  VfxU64 download_rate;
  VfxU64 connect_time;
  VfxU8 bearer_status;
  VfxWString setting;
  cbm_bearer_enum bearer_type;
} vapp_cnmgr_bearer_detail_info_struct;

/***************************************************************************** 
 * Class VappCnmgrApp
 *****************************************************************************/
class VappCnmgrApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappCnmgrApp);

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
};

/***************************************************************************** 
 * Class VappCnmgrScreen
 *****************************************************************************/
 
class VappCnmgrScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappCnmgrScreen);

// Override
public:
    virtual void on1stReady();
};

/***************************************************************************** 
 * Class VappCnmgrSettingCell
 *****************************************************************************/
/*
class VappCnmgrSettingCell : public VcpFormItemLauncherCell
{
    VFX_DECLARE_CLASS(VappCnmgrSettingCell);

// Overrides
public:
    virtual void onInit();

// Methods
public:
    void onTap(VcpFormItemCell *sender, VfxId senderId);
};
*/

/***************************************************************************** 
 * Class VappCnmgrBearerListPage
 *****************************************************************************/
class VappCnmgrBearerListPage : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappCnmgrBearerListPage);

public:
    VappCnmgrBearerListPage();
    virtual ~VappCnmgrBearerListPage(){};

// Overrides
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onExit(VfxBool isBackward);

    virtual VfxBool getItemText(
        VfxU32 index,                   // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxWString &text,               // [OUT] the text resource
        VcpListMenuTextColorEnum &color // [OUT] the text color
    );
    virtual VfxBool getItemImage(
        VfxU32 index,                   // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
    );
   virtual VfxBool getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
    virtual VfxU32 getCount() const;

// Methods
public:
    void reset();
    void updateBearerList();
    void onSelectItem(VcpListMenu *listMenu, VfxU32 selectIdx);
    void onToolBarTap(VfxObject *sender,VfxId id);
    void onDiscAllPopupBtnTap(VfxObject *sender, VfxId id);
    void closeIndicatorPopup();
    void displayErrorPopup(const VfxWString &text);
    void onErrorPopupBtnTap(VfxObject *sender, VfxId id);
    static void refreshPage(void *userData);
    static void discAllDone(VfxU8 result, void *userData);

    // get method
    VfxBool getDiscAll() {return m_discAll;}

    // set method
    void setDiscAll(VfxBool discAll) {m_discAll = discAll;}

// Variables
private:
    VcpListMenu *m_listMenu;
    VfxTextFrame *m_textNoConnection;
    VcpTitleBar *m_titleBar;
    VcpToolBar *m_toolBar;
    VcpConfirmPopup *m_confirmPopup;
    VfxWeakPtr<VcpConfirmPopup> m_confirmPopupPtr;
    VcpIndicatorPopup *m_indicatorPopup;
    VcpConfirmPopup *m_errorPopup;
    vapp_cnmgr_bearer_list_struct m_bearerList;
    VfxBool m_discAll;
    VfxU32 m_activeNum;
};


/***************************************************************************** 
 * Class VappCnmgrBearerDetailInfoPage
 *****************************************************************************/
class VappCnmgrBearerDetailInfoPage : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappCnmgrBearerDetailInfoPage);

public:
    VappCnmgrBearerDetailInfoPage();
    VappCnmgrBearerDetailInfoPage(const VfxU32 &accountId, const VfxU8 &connectType, const VfxU8 &dialupType, const VfxWString &profileName);
    virtual ~VappCnmgrBearerDetailInfoPage(){};

// Overrides
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onExit(VfxBool isBackward);

    virtual VfxBool getItemText(
        VfxU32 index,                   // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxWString &text,               // [OUT] the text resource
        VcpListMenuTextColorEnum &color // [OUT] the text color
    );
    virtual VfxU32 getCount() const;

// Methods
public:
    void getBearerData();
    void redrawPage();
    static void refreshPage(void *userData);
    static void updateData(void *userData);
    void onToolBarTap(VfxObject *sender,VfxId id);
    void onDiscPopupBtnTap(VfxObject *sender, VfxId id);
    void exitPage();
    static void discDone(VfxU8 result, void *userData);

// Variables
private:
    VfxU32 m_accountId;
    VfxU8 m_connectType;
    VfxU8 m_dialupType;
    VfxWString m_profileName;
    VcpListMenu *m_listMenu;
    VcpTitleBar *m_titleBar;
    VcpToolBar *m_toolBar;
    VcpConfirmPopup *m_confirmPopup;
    VfxWeakPtr<VcpConfirmPopup> m_confirmPopupPtr;
    VcpIndicatorPopup *m_indicatorPopup;
    vapp_cnmgr_bearer_detail_info_struct m_bearerData;
    VfxU8 m_detailFilter;
};

#endif /* __MMI_CBM_CONNECTION_MANAGER__ */
#endif /* __TCPIP__ */
#endif /* __VAPP_CNMGR_SETTING_H__ */

