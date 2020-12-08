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
 *   vapp_widget_sns_page.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines the page for sns widget to acess contact picker.
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/
#ifndef __VAPP_WIDGET_SNS_PAGE_H__
#define __VAPP_WIDGET_SNS_PAGE_H__
 
#include "MMI_features.h"
#if defined(__MMI_VUI_HOMESCREEN_SNS__)
#if defined(__MMI_VUI_WIDGET_SNS_TABBAR__)

#include "MMIDataType.h"

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_photo_border_frame.h"
#include "vcp_tabctrl_page.h"
#include "vapp_sns_gprot.h"
#include "SnsSrvTypes.h"

/***************************************************************************** 
 * Define
*****************************************************************************/

#define MAX_SELECTED_FRIENDS (5)

/*****************************************************************************
 * Class Declaration
 *****************************************************************************/
// VappWidgetSnsContactListPage class declaration
class VappWidgetSnsContactListPage : public VappSnsBasePage, IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappWidgetSnsContactListPage);

// Enum
public:
    // Layout mode enum
    enum LayoutModeEnum {
        LAYOUT_MODE_VIEWER_ALL,
        LAYOUT_MODE_VIEWER_BY_PROVIDER,
        LAYOUT_MODE_VIEWER_BY_GROUP,
        LAYOUT_MODE_PICKER_ALL,
        LAYOUT_MODE_PICKER_BY_PROVIDER,
        LAYOUT_MODE_PICKER_BY_GROUP,
        LAYOUT_MODE_END
    };

    enum {
#if defined(__MMI_MAINLCD_320X480__)        
        RESIZE_WIDTH = 50,
        RESIZE_HEIGHT = 46,
#elif defined(__MMI_MAINLCD_480X800__)
        RESIZE_WIDTH = 75,
        RESIZE_HEIGHT = 71,
#else            
        RESIZE_WIDTH = 38,
        RESIZE_HEIGHT = 37,
#endif
    };

// Constructor / Destructor
public:
    // Default constructor
    VappWidgetSnsContactListPage(
        LayoutModeEnum mode = LAYOUT_MODE_VIEWER_ALL
       // VfxBool supportRotate = VFX_FALSE
    ); 
    
    VappWidgetSnsContactListPage(
        VfxId id,
        LayoutModeEnum mode = LAYOUT_MODE_VIEWER_ALL
    ); 

protected:
    // Init function
    virtual void onInit();

    // Deinit function
    virtual void onDeinit();

    // Enter page function 
    virtual void onEnter(VfxBool isBackWard);

    // Exit page function
    virtual void onExit(VfxBool isBackward);

    // Item updated
    virtual void onItemUpdated(
        VfxS32 listId,
        VfxU16 index, 
        VappSnsItemUpdatedTypeEnum type, 
        VfxWChar *path
    );  
    
    // Load callback function
    virtual void onGetLoadResults(
        VfxS32 listId, 
        VfxU16 total, 
        VfxS16 startIndex, 
        VfxS16 endIndex
    );

    // Popup click event
    virtual void onPopupButtonClicked(
        VfxObject *sender,
        VfxId id
    );

    virtual void onSrvStatusChanged(
        VfxBool ready, 
        srv_sns_result err_code, 
        VfxU32 listId
    );

// Override
public:
    // IVcpGroupListMenuContentProvider
    virtual VfxBool getItemText (
        VfxU32 pos,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
    );   
    
    virtual VfxBool getItemImage(
        VfxU32 pos,
        VcpListMenuFieldEnum fieldType,
        VfxImageSrc &image
    );
    
    virtual VfxBool getMenuEmptyText (
        VfxWString &text,               
        VcpListMenuTextColorEnum &color
    );    

    using IVcpListMenuContentProvider::closeItemImage;
    virtual void closeItemImage(
        VcpMenuPos index,                   // [IN] the index of item
        VcpListMenuFieldEnum fieldType,     // [IN] the type of the field in the cell
        VfxImageSrc imgSrc                  // [IN] the image resource
    ) {};

    virtual VfxU32 getCount(
    ) const;

    virtual VfxBool getItemIsHighlightable(
        VfxU32 pos   // [IN] position of the item
    ) const;

    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame (
        VfxU32 pos,         // [IN] position of the item
        VfxFrame *parentFrame   // [IN] parent frame of the custom content frame
    );



// Implementation
public:
    // This function is used to set max selected number
    void setMaxSelectedNum(
        VfxU8 num
    );

    void onReceivedGroupResult(srv_sns_result result);

    static mmi_ret onContactsSelected(mmi_event_struct *evt);

    srv_sns_user_list_struct *getSelectedUsersInfo(VfxU16 *num);

    void showLoading();

    void onRemoveContact(VfxObject* sender, VfxId Id);


private:
    // This function is used to get contact info
    VfxBool getContactInfo(
        VfxU32 index, 
        void **contact
    );

    // This function is used update layout
    void updateLayout();

    // This function used to handle item tapped event
    void onItemTapped(
        VcpListMenu *list, 
        VfxU32 pos
    );

    // This function is used to prepare storage memory
    VfxBool prepareStorage(VfxU8 num);

    void prepareResizdPhoto();

    static void onDecodeResult(GDI_RESULT result, gdi_handle handle);

    void handleDecodeResult(GDI_RESULT result, gdi_handle handle);

    void releaseGdiResource();

    void releaseDecodeBuffer();

// Signal
public:
    // On item tapped (used by normal page)
    VfxSignal2 <VfxU32, VfxChar *> m_signalItemTapped;
   

// Variable
private:
    // enum
    enum ButtonIdEnum {
        COMMAND_POPUP_ID_ADD_MEMBER,
        COMMAND_POPUP_ID_REMOVE_MEMBER,
        COMMAND_POPUP_ID_CANCEL
    };

    // Selected result
    enum SelectedResultEnum {
        SELECTED_RESULT_CANCEL  = 0,
        SELECTED_RESULT_OK      = 1
    };

    // Layout mode
    LayoutModeEnum m_mode;

    VfxU8 m_defaultStorage;

    VfxBool m_folderPrepared;

    VfxU32 m_processedCount;

    VfxU32 m_decodeSize;

    GDI_HANDLE m_job;          // decoding job
    GDI_HANDLE m_layer;        // decoding layer

    // List menu
    VcpListMenu *m_list;

    // List id
    VfxS32 m_listId;

    // Count number
    VfxU32 m_count;

    srv_sns_user_list_struct *m_users;

    // Group name
    VfxWString m_title;

    // List memory pointer
    srv_sns_user_list_struct *m_storage;

    srv_sns_user_list_struct m_deleteBuffer;

    // Max selected number
    VfxU8 m_maxSelectedNum;

    // Selected number
    VfxU8 m_selectedNum;

    // Group operation
    VfxBool m_loaded;      

    // Is adding or removing contact
    VfxBool m_isEditting;

    VfxU8 *m_decodeBuf;

    static VappWidgetSnsContactListPage *m_self;
};

#endif /*__MMI_VUI_WIDGET_SNS_TABBAR__*/
#endif /* __MMI_VUI_HOMESCREEN_SNS__ */
#endif /* __VAPP_WIDGET_SNS_PAGE_H__*/
