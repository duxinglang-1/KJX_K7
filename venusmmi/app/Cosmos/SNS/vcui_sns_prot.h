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
 *  vcui_sns_prot.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCUI_SNS_PROT_H__
#define __VCUI_SNS_PROT_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"

#ifdef __SOCIAL_NETWORK_SUPPORT__
#include "vfx_mc_include.h"
#include "vcp_include.h"

#include "vfx_page.h"
#include "vapp_sns_base.h"
#include "vcui_sns_gprot.h"
#include "vcp_photo_border_frame.h"
#include "vcp_text_editor.h"
#include "vapp_sns_base_cp.h"
#include "vapp_sns_gprot.h"
#include "vapp_sns_msg.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "FileMgrSrvGprot.h"
#include "SnsSrvGprot.h"
#include "gdi_include.h"
#ifdef __cplusplus
}
#endif

#if defined(__MMI_SNS_PHOTO_UPLOAD__)
typedef struct vcui_sns_args
{   
    VcuiSnsUploadPicStyleEnum  style;
    VfxWChar path[SRV_FMGR_PATH_MAX_LEN+1];
} vcui_sns_args;

class VcuiSnsUploadPicPage : public VappSnsBasePage
{
    VFX_DECLARE_CLASS(VcuiSnsUploadPicPage);
public:
    VcuiSnsUploadPicPage();
    VcuiSnsUploadPicPage(mmi_id grp_id, VfxWChar* path, VfxBool supportChangePic, VfxBool supportRotate = VFX_FALSE);

public:
    void setPath(VfxWChar* path);
    static mmi_ret callProc(mmi_event_struct * evt);

    void encodeRspHandler(VfxS32 req_id, VfxS32 result);
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onExit(VfxBool isBackward);
    virtual void onEnter(VfxBool isBackWard);
    virtual void onEntered();
    virtual void onBack();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
    virtual mmi_ret onProc(mmi_event_struct * evt);
    virtual void setBounds(const VfxRect &value);
    
protected:
    VappSnsAsyncPhotoBorderFrame *m_photo;
    VcpTextEditor *m_editor;
    VappSnsAcctSelButton *m_button;
    VcpForm *m_baseForm;
    
private:
    void onButtonTap(VfxObject *obj, VfxId id);
    void onSelectedAccChange(void);
    void showCommandPopup();
    void notifyCallerToClose();
    void getNewPath(VfxWString &folder_path);
    
    static void onDecodeResult(GDI_RESULT result, gdi_handle handle);
    void handleDecodeResult(GDI_RESULT result, gdi_handle handle);
    void onFormItemBoundsChanged(VfxFrame *obj, const VfxRect &rect);
    void upload();
    void prepareToUpload();
    void releaseGdiResource();
    void releaseDecodeBuffer();
private:
    enum {
        VCUI_SNS_UPLOAD = 1,
        VCUI_SNS_ADD,
        VCUI_SNS_EDIT,
        VCUI_SNS_CANCEL,

        VCUI_SNS_SEL_FROM_GALLERY,
        VCUI_SNS_SEL_FROM_CAM,
        VCUI_SNS_SEL_CANCEL,
    };

    enum {
    #ifdef __MMI_MAINLCD_480X800__
        ITEM_W = 480,
        ITEM_H = 800,
        TOOLBAR_H = 85,
        STATUSBAR_H =38,
        
        EDITOR_T_GAP = 4,
        EDITOR_LAND_T_GAP = EDITOR_T_GAP,
        EDITOR_L_GAP = 14,
        EDITOR_LAND_L_GAP = 20,
        EDITOR_LAND_R_GAP = 20,
        EDITOR_W = (ITEM_W-EDITOR_L_GAP*2),
        EDITOR_LAND_W = (ITEM_H - (EDITOR_LAND_L_GAP + EDITOR_LAND_R_GAP)),
        EDITOR_H = 60,

        BUTTON_T_GAP = 26,
        BUTTON_LAND_T_GAP = BUTTON_T_GAP,
        BUTTON_L_GAP = 14,
        BUTTON_LAND_L_GAP = EDITOR_LAND_L_GAP,
        BUTTON_LAND_R_GAP = EDITOR_LAND_L_GAP,
        BUTTON_LAND_WIDTH = EDITOR_LAND_W,

        THUMB_W = 300,
        THUMB_H = 200,        
        THUMB_T_GAP = 26,
        THUMB_LAND_T_GAP = THUMB_T_GAP,
        THUMB_L_GAP = (ITEM_W-THUMB_W)/2,
        THUMB_LAND_L_GAP = (ITEM_H-THUMB_W)/2,
    #elif __MMI_MAINLCD_320X480__
        ITEM_W = 320,
        ITEM_H = 480,
        TOOLBAR_H = 50,
        STATUSBAR_H =24,
        
        EDITOR_T_GAP = 8,
        EDITOR_LAND_T_GAP = EDITOR_T_GAP,
        EDITOR_L_GAP = 8,
        EDITOR_LAND_L_GAP = 10,
        EDITOR_LAND_R_GAP = 10,
        EDITOR_W = (ITEM_W-EDITOR_L_GAP*2),
        EDITOR_LAND_W = (ITEM_H - (EDITOR_LAND_L_GAP + EDITOR_LAND_R_GAP)),
        EDITOR_H = 36,

        BUTTON_T_GAP = 14,
        BUTTON_LAND_T_GAP = BUTTON_T_GAP,
        BUTTON_L_GAP = 10,
        BUTTON_LAND_L_GAP = EDITOR_LAND_L_GAP,
        BUTTON_LAND_R_GAP = EDITOR_LAND_L_GAP,
        BUTTON_LAND_WIDTH = EDITOR_LAND_W,

        THUMB_W = 200,
        THUMB_H = 130,        
        THUMB_T_GAP = 14,
        THUMB_LAND_T_GAP = THUMB_T_GAP,
        THUMB_L_GAP = (ITEM_W-THUMB_W)/2,
        THUMB_LAND_L_GAP = (ITEM_H-THUMB_W)/2,
    #else
        ITEM_W = 240,
    #ifdef __MMI_MAINLCD_240X320__
        ITEM_H = 320,
    #else
        ITEM_H = 400,
    #endif /* __MMI_MAINLCD_240X320__ */
        TOOLBAR_H = 45,
        STATUSBAR_H =24,
        
        EDITOR_T_GAP = 8,
        EDITOR_LAND_T_GAP = EDITOR_T_GAP,
        EDITOR_L_GAP = 5,
        EDITOR_LAND_L_GAP = 5,
        EDITOR_LAND_R_GAP = 5,
        EDITOR_W = (ITEM_W-EDITOR_L_GAP*2),
        EDITOR_LAND_W = (ITEM_H - (EDITOR_LAND_L_GAP + EDITOR_LAND_R_GAP)),
        EDITOR_H = 32,

        BUTTON_T_GAP = 8,
        BUTTON_LAND_T_GAP = BUTTON_T_GAP,
        BUTTON_L_GAP = 5,
        BUTTON_LAND_L_GAP = EDITOR_LAND_L_GAP,
        BUTTON_LAND_R_GAP = EDITOR_LAND_L_GAP,
        BUTTON_LAND_WIDTH = EDITOR_LAND_W,

        THUMB_W = 150,
        THUMB_H = 100,        
        THUMB_T_GAP = 8,
        THUMB_LAND_T_GAP = THUMB_T_GAP,
        THUMB_L_GAP = (ITEM_W-THUMB_W)/2,
        THUMB_LAND_L_GAP = (ITEM_H-THUMB_W)/2,
    #endif
    };

    enum {
        VCUI_SNS_RESIZE_DECODE = 0,
        VCUI_SNS_RESIZE_ENCODE,
        VCUI_SNS_RESIZE_ABORT,
    };

    enum {
        VCUI_SNS_UPLOAD_FORM_COMMENTS = 1,
        VCUI_SNS_UPLOAD_FORM_PROVIDER,
        VCUI_SNS_UPLOAD_FORM_PHOTO,
    };
    #define VCUI_SNS_SET_RESIZE_STATE(f,b) ((f) |= (1 << (b)))
    #define VCUI_SNS_CLEAR_RESIZE_STATE(f,b) ((f) &= (0 << (b)))
    #define VCUI_SNS_CHECK_STATE(f,b) (f & (1 << (b)))

    VfxU8 m_resizeState;
    VfxBool m_supportRotate;
    VfxBool m_supportChangePic;
    mmi_id m_grpId;
    VfxU32 m_encodingReqId;
    VfxS32 m_decodeBufSize;
    GDI_HANDLE m_job;          // decoding job
    GDI_HANDLE m_layer;        // decoding layer
    VfxU8 *m_decodeBuf;
    VfxChar *m_path;
    VfxChar *m_newPath;
    static VcuiSnsUploadPicPage *m_self;
};

class VcuiSnsUploadPic : public VfxCui
{
    VFX_DECLARE_CLASS(VcuiSnsUploadPic);    

// Override
protected:
    virtual void onInit();
    virtual void onRun(void* args, VfxU32 argSize);
    virtual mmi_ret onProc(mmi_event_struct * evt);

private:
    enum {
        VCUI_SNS_UPLOAD_PIC_PAGE_ID = 1,

        VCUI_SNS_TOTAL_PAGE,
    };
};
#endif /* __MMI_SNS_PHOTO_UPLOAD__ */

// VcuiSnsContactsPicker class declaration
class VcuiSnsContactsPicker : public VfxCui
{
    VFX_DECLARE_CLASS(VcuiSnsContactsPicker);

// Constructor / destructor
public:
    // Default constructor
    VcuiSnsContactsPicker();

// Override
protected:
    // Init function
    virtual void onInit();

    // Deinit function 
    virtual void onDeinit();

    // onRun function
    virtual void onRun(void *args, VfxU32 argSize);

    // Proc function 
    virtual mmi_ret onProc(mmi_event_struct *evt);

// Implementation
public:
    // Set filter id
    void setFilterId(VfxBool hasFilter, VfxBool isProvider, VfxU32 filterId, VfxBool toSkip);

    // Set tiltle
    void setCaption(const VfxWChar *title);

    // Enable recommaned list
    void enableRecommandList(const VfxWChar *name);

    // Enable rotataion
    void enableRotation(VfxBool supportRotate);

    // Set max selected num
    void setMaxSelectedNum(VfxU8 num);

    // Set selected accounts
    void setSelectedAccounts(srv_sns_user_list_struct *acct_array, VfxU8 acct_array_num);

    // Get selected acccounts
    VfxU8 getSelectedAccounts(srv_sns_user_list_struct *out_array, VfxU8 out_num);

// Variable
private:
    // Has filter id flag
    VfxBool m_hasFilterId;

    // Provider or group
    VfxBool m_isProvider;

    // Filter id
    VfxU32 m_filterId;

    // Skip the indicated filter id member
    VfxBool m_skip;
    
    // Title
    VfxWString m_title;

    // Name
    VfxWChar *m_name;

    // Rotate flag
    VfxBool m_supportRotate;

    // Max selected num
    VfxU8 m_maxSelectedNum;

    // List memory backup 
    srv_sns_user_list_struct *m_backupStorage;

    // List memory backup count
    VfxU8 m_backupStorageCount;    
};

#ifdef __MMI_SNS_MESSAGES__
class VcuiSnsMsgComposer : public VfxCui
{
    VFX_DECLARE_CLASS(VcuiSnsMsgComposer);

    enum VCUI_SNS_MSG_COMPOSER_PAGE_ID
    {
        VCUI_SNS_MSG_COMPOSER_MAIN = 1, 
        VCUI_SNS_MSG_COMPOSER_END
    };

public:
// Constructor
    VcuiSnsMsgComposer();

// Method
    void setProviderId(VfxU32 provider);
    void setRecipients(srv_sns_user_list_struct *recipients, VfxU8 count);
    void setRotate(VfxBool isRotate);

// Override
protected:
    virtual void onDeinit();
    virtual void onRun(void* args, VfxU32 argSize);
    virtual mmi_ret onProc(mmi_event_struct * evt);

private:
    VfxBool m_isRotate;
    VfxU32 m_provider;
    srv_sns_user_list_struct *m_recipientList;
    VfxU8 m_recipientListCount;
};


class VcuiSnsMsgComposerPage : public VfxPage
{
    VFX_DECLARE_CLASS(VcuiSnsMsgComposerPage);

    /* layout */
#if defined(__MMI_MAINLCD_320X480__) /* HVGA */
    #define VCUI_SNS_MSG_COMPOSER_INT_MARGIN            (8)
    #define VCUI_SNS_MSG_COMPOSER_EXT_MARGIN            (8)
    #define VCUI_SNS_MSG_COMPOSER_RECIPIENT_HEIGHT      (39)
    #define VCUI_SNS_MSG_COMPOSER_CONTENT_HEIGHT        (36)
#elif defined(__MMI_MAINLCD_480X800__) /* WVGA */
    #define VCUI_SNS_MSG_COMPOSER_INT_MARGIN            (10)
    #define VCUI_SNS_MSG_COMPOSER_EXT_MARGIN            (14)
    #define VCUI_SNS_MSG_COMPOSER_RECIPIENT_HEIGHT      (67)
    #define VCUI_SNS_MSG_COMPOSER_CONTENT_HEIGHT        (60)
#elif defined(__MMI_MAINLCD_240X320__) /* QVGA */
    #define VCUI_SNS_MSG_COMPOSER_INT_MARGIN            (5)
    #define VCUI_SNS_MSG_COMPOSER_EXT_MARGIN            (5)
    #define VCUI_SNS_MSG_COMPOSER_RECIPIENT_HEIGHT      (36)
    #define VCUI_SNS_MSG_COMPOSER_CONTENT_HEIGHT        (32)
#elif defined(__MMI_MAINLCD_240X400__) /* WQVGA */
    #define VCUI_SNS_MSG_COMPOSER_INT_MARGIN            (5)
    #define VCUI_SNS_MSG_COMPOSER_EXT_MARGIN            (5)
    #define VCUI_SNS_MSG_COMPOSER_RECIPIENT_HEIGHT      (36)
    #define VCUI_SNS_MSG_COMPOSER_CONTENT_HEIGHT        (32)
#else
    #define VCUI_SNS_MSG_COMPOSER_INT_MARGIN            (8)
    #define VCUI_SNS_MSG_COMPOSER_EXT_MARGIN            (8)
    #define VCUI_SNS_MSG_COMPOSER_RECIPIENT_HEIGHT      (39)
    #define VCUI_SNS_MSG_COMPOSER_CONTENT_HEIGHT        (60)
#endif /* __MMI_MAINLCD_?X?__ */
    
    enum
    {
        VCUI_SNS_MSG_COMPOSER_TOOLBAR_SEND = 1, 
        VCUI_SNS_MSG_COMPOSER_TOOLBAR_END
    };

    enum 
    {
        VCUI_SNS_MSG_COMPOSER_FUNC_BAR_SEND =  1, 
        VCUI_SNS_MSG_COMPOSER_FUNC_BAR_END
    };

    enum
    {
        VCUI_SNS_MSG_COMPOSER_FORM_RECIPIENT = 1, 
        VCUI_SNS_MSG_COMPOSER_FORM_CONTENT, 
        VCUI_SNS_MSG_COMPOSER_FORM_END
    };
// constructor
public:
    VcuiSnsMsgComposerPage();

// Method
    void setProvider(VfxU32 provider);
    void setRecipients(srv_sns_user_list_struct *recipients, VfxU8 count);
    void setRotate(VfxBool isRotate);
    VcpContactSelector *getRecipientList();
    srv_sns_user_list_struct *getRecipientListData();
    VfxU8 getRecipientListCount();
    void setContactChange(VcpContactSelector *obj);

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onUpdate();
    virtual mmi_ret onProc(mmi_event_struct *evt);
    virtual void onBack();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

// internal apis
private:
    void onFbClicked(VfxObject *obj, VfxId id);
    void onToolbarClicked(VfxObject *obj, VfxId id);
    void onSearchClicked();
    void onFormItemBoundsChanged(VfxFrame *obj, const VfxRect &rect);
    void onContentChanged(VcpTextEditor *obj);
    void onContactChanged(VcpContactSelector *obj, VcpContactChangedEnum state);
    void onMoreClicked(VcpContactSelector *obj);
    void updateRecipient();
    void updateToolbar();
    void sendMsg();

// member variables
private:
    VfxBool m_isRotate;
    VfxU32 m_provider;
    VcpContactSelector *m_recipientList;
    VcpTextEditor *m_content;
    srv_sns_user_list_struct *m_recipientListData;
    VfxU8 m_recipientListCount;
};


class VcuiSnsMsgComposerRecipientPage : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VcuiSnsMsgComposerRecipientPage);

// constructor
public:
    VcuiSnsMsgComposerRecipientPage(VcuiSnsMsgComposerPage *mainPage = NULL);

// Method
    void setRotate(VfxBool isRotate);

// Override
protected:
    virtual void onInit();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

// Provider 
public:
    virtual VfxU32 getCount() const;
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

// internal apis
private:
    void onDeleteRecipient(VcpListMenu *list, VfxU32 index);

private:
    VfxBool m_isRotate;
    VcuiSnsMsgComposerPage *m_mainPage;
};
#endif /* __MMI_SNS_MESSAGES__ */

#endif /* __SOCIAL_NETWORK_SUPPORT__ */

#endif /* __VCUI_SNS_PROT_H__ */
