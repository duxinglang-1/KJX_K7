/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vapp_widget_vip_contact.h
 *
 * Project:
 * --------
 *  MAUI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_WIDGET_VIP_CONTACT_H
#define VAPP_WIDGET_VIP_CONTACT_H

#include "MMI_features.h"

#ifdef __MMI_VUI_WIDGET_VIP_CONTACT__
/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vcp_include.h"
#include "vapp_widget_def.h"
#include "vapp_widget.h"
#include "vcp_menu_popup.h"
#include "PhbSrvGProt.h"
#include "vapp_contact_entry.h"
#include "vcp_photo_border_frame.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "Ucmgprot.h"

#ifdef __cplusplus
}
#endif

#ifdef __LOW_COST_SUPPORT_COMMON__
#define __MMI_SLIM_WIDGET_VIP_CONTACTS__
#endif

/*****************************************************************************
 * VIP Contacts Widget
 *****************************************************************************/
#define MY_DEL_ID_BASE 12

class VappWidgetVipContactPhotoBorder : public VcpPhotoBorderFrame
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidgetVipContactPhotoBorder);
    
public:
    VappWidgetVipContactPhotoBorder();
    VappWidgetVipContactPhotoBorder(VfxBool show_name_area, VfxS32 width, VfxS32 height);

    void setName(VfxWString name);
    void disable();
    void enable();
// Override
protected:
    virtual void onInit();

private:

    enum {
    #ifdef __MMI_MAINLCD_480X800__
        NAME_AREA_WIDTH = 104,
        NAME_AREA_HEIGHT = 30,
        NAME_AREA_SHIFT = 3,
        ITEM_NAME_LALIGN = 14,
        ITEM_NAME_TALIGN = 4,
        ITEM_NAME_WIDTH = (NAME_AREA_WIDTH-2*ITEM_NAME_LALIGN),
        ITEM_NAME_HEIGHT = (NAME_AREA_HEIGHT-2*ITEM_NAME_TALIGN),

        TEXT_FONT_SIZE = 20
    #elif __MMI_MAINLCD_320X480__
        NAME_AREA_WIDTH = 70,
        NAME_AREA_HEIGHT = 19,
        NAME_AREA_SHIFT = 3,
        ITEM_NAME_LALIGN = 4,
        ITEM_NAME_TALIGN = 2,
        ITEM_NAME_WIDTH = (NAME_AREA_WIDTH-2*ITEM_NAME_LALIGN),
        ITEM_NAME_HEIGHT = (NAME_AREA_HEIGHT-2*ITEM_NAME_TALIGN),
        
        TEXT_FONT_SIZE = 13
    #else
        NAME_AREA_WIDTH = 52,
        NAME_AREA_HEIGHT = 16,
        NAME_AREA_SHIFT = 3,
        ITEM_NAME_LALIGN = 3,
        ITEM_NAME_TALIGN = 2,
        ITEM_NAME_WIDTH = (NAME_AREA_WIDTH-2*ITEM_NAME_LALIGN),
        ITEM_NAME_HEIGHT = (NAME_AREA_HEIGHT-2*ITEM_NAME_TALIGN),

        TEXT_FONT_SIZE = 11
    #endif
    };
    
    VfxBool m_show_name_area;
    VfxS32 m_width;
    VfxS32 m_height;
    VfxFrame *m_name_area;
    VfxTextFrame *m_name;
};

class VappWidgetVipContactPopup : public VfxBasePopup
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidgetVipContactPopup);

    friend class VappWidgetVipContact;
    
public:
    VappWidgetVipContactPopup();
    VappWidgetVipContactPopup(mmi_phb_contact_id id, mmi_id group_id, VfxObject *parent);

    void refreshContactPic(void);
    void showSimList();
    void disableCallButton(VfxBool disable);
    
    enum {
    #ifdef __MMI_MAINLCD_480X800__
        ITEM_WIDTH = 446,
        ITEM_HEIGHT = 304,

        PIC_LALIGN = 27,
        PIC_TALIGN = 37,
        PIC_WIDTH = 115,
        PIC_HEIGHT = 115,

        TEXT_LALIGN = 14,
        TEXT_TBGAP = 1,
        NAME_TALIGN = 39,        
        NAME_FONT_SIZE = 36,
        NAME_TITLE_ALIGN = 9,
        TITLE_FONT_SIZE = 26,
        TITLE_COMPANY_ALIGN = 6,
        COMPANY_FONT_SIZE = 26,

        BUTTON_WIDTH = 77,
        BUTTON_HEIGHT = 77,
        BUTTON_RALIGN = 27,
        BUTTON_LALIGN = 27,
        BUTTON_BALIGN = 37,
        BUTTON_TALIGN = (ITEM_HEIGHT - BUTTON_HEIGHT - BUTTON_BALIGN),
        BUTTON_GAP = 17,
    #elif __MMI_MAINLCD_320X480__
        ITEM_WIDTH = 290,
        ITEM_HEIGHT = 177,

        PIC_LALIGN = 17,
        PIC_TALIGN = 23,
        PIC_WIDTH = 66,
        PIC_HEIGHT = 66,

        TEXT_LALIGN = 15,
        TEXT_TBGAP = 1,
        NAME_TALIGN = 25,
        NAME_FONT_SIZE = 24,
        NAME_TITLE_ALIGN = 4,
        TITLE_FONT_SIZE = 14,
        TITLE_COMPANY_ALIGN = 3,
        COMPANY_FONT_SIZE = 14,

        BUTTON_WIDTH = 42,
        BUTTON_HEIGHT = 42,
        BUTTON_RALIGN = 17,
        BUTTON_LALIGN = 17,
        BUTTON_BALIGN = 19,
        BUTTON_TALIGN = (ITEM_HEIGHT - BUTTON_HEIGHT - BUTTON_BALIGN),
        BUTTON_GAP = 11,        
    #else
        ITEM_WIDTH = 222,
        ITEM_HEIGHT = 135,

        PIC_LALIGN = 11,
        PIC_TALIGN = 17,
        PIC_WIDTH = 50,
        PIC_HEIGHT = 50,

        TEXT_LALIGN = 8,
        TEXT_TBGAP = 1,
        NAME_TALIGN = 17,
        NAME_TITLE_ALIGN = 2,
        NAME_FONT_SIZE = 16,
        TITLE_FONT_SIZE = 12,
        TITLE_COMPANY_ALIGN = 1,
        COMPANY_FONT_SIZE = 12,

        BUTTON_WIDTH = 42,
        BUTTON_HEIGHT = 42,
        BUTTON_RALIGN = 10,
        BUTTON_LALIGN = 11,
        BUTTON_BALIGN = 10,
        BUTTON_TALIGN = (ITEM_HEIGHT - BUTTON_HEIGHT - BUTTON_BALIGN),
        BUTTON_GAP = 5,
    #endif

        NAME_WIDTH = ITEM_WIDTH-2*PIC_LALIGN-PIC_WIDTH-TEXT_LALIGN,
        TITLE_WIDTH = NAME_WIDTH,
        COMPANY_WIDTH = NAME_WIDTH,

        NAME_HEIGHT = NAME_FONT_SIZE+3,
        TITLE_HEIGHT = TITLE_FONT_SIZE+3,
        COMPANY_HEIGHT = COMPANY_FONT_SIZE+3
    };
// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    
    #define VAPP_WIDGET_VIP_CONTACT_CANCEL 1
    #define VAPP_WIDGET_VIP_CONTACT_CALL 2
    #define VAPP_WIDGET_VIP_CONTACT_MSG 3
    #define VAPP_WIDGET_VIP_CONTACT_EMAIL 4

    enum {
        MSG_START = 50,
        EMAIL_START = 100
    };
    
    void onClickLaunch(VfxObject* obj, VfxId id);
    void showNumberList(ContactEntry &entry, VfxId id, VfxU32 count);
    void showEmailList(ContactEntry &entry, VfxU32 count);
private:
    mmi_phb_contact_id m_phb_id;
    mmi_id m_group_id;
    VcpPhotoBorderFrame *m_pic;
    VfxTextFrame *m_name;
    VfxTextFrame *m_title;
    VfxTextFrame *m_company;
    VcpImageButton    *m_call;
    VcpImageButton    *m_sim2_call;
    VcpImageButton    *m_message;
    VcpImageButton    *m_email;
    VcpImageButton    *m_cancel;
    VfxObject *m_parent;
};

class VappWidgetVipContactItem : public VfxFrame
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidgetVipContactItem);

    friend class VappWidgetVipContact;
public:
    enum {
    #ifdef __MMI_MAINLCD_480X800__
        ITEM_WIDTH = 110,
        ITEM_HEIGHT = 110,

        ITEM_PIC_LRGAP = 0,
        ITEM_PIC_TGAP = 0,
        ITEM_PIC_WIDTH = ITEM_WIDTH,
        ITEM_PIC_HEIGHT = ITEM_HEIGHT,
    #elif __MMI_MAINLCD_320X480__
        ITEM_WIDTH = 76,
        ITEM_HEIGHT = 76,

        ITEM_PIC_LRGAP = 0,
        ITEM_PIC_TGAP = 0,
        ITEM_PIC_WIDTH = ITEM_WIDTH,
        ITEM_PIC_HEIGHT = ITEM_HEIGHT,        
    #else
        ITEM_WIDTH = 56,
        ITEM_HEIGHT = 56,

        ITEM_PIC_LRGAP = 0,
        ITEM_PIC_TGAP = 0,
        ITEM_PIC_WIDTH = ITEM_WIDTH,
        ITEM_PIC_HEIGHT = ITEM_HEIGHT,
    #endif
    };
// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

public:
    VappWidgetVipContactItem();
    VappWidgetVipContactItem(mmi_phb_contact_id id, VfxId my_id, VfxObject* parent, VfxBool isReady);
        
    void disableFpButton();
    void enableFpButton();
    void setFpButtonId(VfxId id);

    void hideDelButton(VfxBool hide);
    void setName(VfxWString &text);
    void setName(mmi_phb_contact_id id);
    void setPic(VfxImageSrc &img);
    void setPic(mmi_phb_contact_id id);    
    
    void setPhbId(mmi_phb_contact_id id);
private:
    VfxBool m_is_ready;
    VfxId m_my_id;
    mmi_phb_contact_id m_phb_id;
    VcpImageButton *m_del_button;    
    VappWidgetVipContactPhotoBorder *m_fp_frame;
    //VfxFrame *m_fp_frame;
    VfxFrame *m_pic_frame;
    VfxObject *m_parent;
};

class VappWidgetVipContact : public VappWidget
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidgetVipContact);

    friend class VappWidgetVipContactPopup; 
public:
    enum
    {
    #ifdef __MMI_MAINLCD_480X800__
        WIDTH = 434,
        HEIGHT = 507,

        TITLE_FRAME_LALIGN = 16,
        TITLE_FRAME_TALIGN = 9,
        TITLE_FRAME_WIDTH = 340,
        TITLE_FRAME_HEIGHT = 58,
        TITLE_LALIGN = 18,
        TITLE_TALIGN = 14,
        TITLE_WIDTH = 100,
        TITLE_HEIGHT = 5,
        
        DEL_MODE_ICON_RALIGN = 19,
        DEL_MODE_ICON_TALIGN = 12,
        DEL_MODE_ICON_WIDTH = 50,
        DEL_MODE_ICON_HEIGHT = 50,

        ITEM_LALIGN = 32,
        ITEM_LRGAP = 20,
        ITEM_TBGAP = 20,
        ITEM_TALIGN = 93,
        
        NAME_FONT_SIZE = 20,
        TITLE_FONT_SIZE = 26,

        WIDGET_EDIT_BUTTON_X = 419,
        WIDGET_EDIT_BUTTON_Y = 12,
    #elif __MMI_MAINLCD_320X480__
        WIDTH = 286,
        HEIGHT = 320,

        TITLE_FRAME_LALIGN = 7,
        TITLE_FRAME_TALIGN = 4,
        TITLE_FRAME_WIDTH = 234,
        TITLE_FRAME_HEIGHT = 37,
        TITLE_LALIGN = 12,
        TITLE_TALIGN = 8,
        TITLE_WIDTH = 100,
        TITLE_HEIGHT = 5,
        
        DEL_MODE_ICON_RALIGN = 10,
        DEL_MODE_ICON_TALIGN = 7,
        DEL_MODE_ICON_WIDTH = 29,
        DEL_MODE_ICON_HEIGHT = 29,

        ITEM_LALIGN = 19,
        ITEM_LRGAP = 10,
        ITEM_TBGAP = 10,
        ITEM_TALIGN = 52,
        
        NAME_FONT_SIZE = 13,
        TITLE_FONT_SIZE = 18,

        WIDGET_EDIT_BUTTON_X = 271,
        WIDGET_EDIT_BUTTON_Y = 12,
    #else
        WIDTH = 222,

        TITLE_FRAME_LALIGN = 8,
        TITLE_FRAME_TALIGN = 5,
        TITLE_FRAME_WIDTH = 175,
        TITLE_FRAME_HEIGHT = 28,
        TITLE_LALIGN = 5,
        TITLE_TALIGN = 5,
        TITLE_WIDTH = 100,
        TITLE_HEIGHT = 5,
        
        DEL_MODE_ICON_RALIGN = 8,
        DEL_MODE_ICON_TALIGN = 5,
        DEL_MODE_ICON_WIDTH = 27,
        DEL_MODE_ICON_HEIGHT = 27,

        ITEM_LALIGN = 17,
        ITEM_LRGAP = 10,
        ITEM_TBGAP = 8,
        ITEM_TALIGN = 46,
        
        NAME_FONT_SIZE = 13,
        TITLE_FONT_SIZE = 16,

        #ifdef __MMI_MAINLCD_240X320__
        HEIGHT = 183,
        #else /* __MMI_MAINLCD_240X400__ */
        HEIGHT = 250,
        #endif

        WIDGET_EDIT_BUTTON_X = 210,
        WIDGET_EDIT_BUTTON_Y = 10
    #endif
    };    

    static void makeCallCb(mmi_ucm_after_make_call_cb_struct* make_call_cb_para);
    mmi_sim_enum getOnlyOneAvailableSim(void);
    VfxBool isSimAvailable(mmi_sim_enum sim);
    VfxBool isAnySimAvailable(void);
protected:
    mmi_ret onProc(mmi_event_struct *evt);

    void resetContactItem(VfxS8 index);
    void refreshContactItems(void);
    void onClickMenuPopup(VcpMenuPopup* opt_menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem* item);
    void onSelectSimPopup(VcpMenuPopup* opt_menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem* item);
    void onMenuPopupStateChange(VfxBasePopup* obj,  VfxBasePopupStateEnum state);
    void onSelectSimPopupStateChange(VfxBasePopup* obj,  VfxBasePopupStateEnum state);
    void showEditMode(void);
    void leaveEditMode(void);
    
private:
#ifdef __MMI_MAINLCD_240X320__
    #define ITEM_NUM 6
#else
    #define ITEM_NUM 9
#endif

    void launchApp(mmi_sim_enum sim = MMI_SIM_NONE);
    VfxU16 getNvramItemId(VfxS32 index);
#ifdef __MMI_SLIM_WIDGET_VIP_CONTACTS__
    void createAllCp();
#endif
// Override
public:
    virtual VappWidgetId getId() const;

    virtual VfxSize getMaxSize() const;

    virtual VfxS32 getName(VfxWChar *string, VfxS32 size) const;

    virtual VfxFrame *createIcon(VfxObject *parentObj);

    /* For click signal of 9(or 6) photo border */
    void onClickCard1();
    void onClickCard2();
    void onClickCard3();
    void onClickCard4();
    void onClickCard5();
    void onClickCard6();
    void onClickCard7();
    void onClickCard8();
    void onClickCard9();
    void onClickCardPanel(VfxObject* obj, VfxId id);
    
    void onClickDelete(VfxObject* obj, VfxId id);

    void onClickEdit(VfxObject* obj, VfxId id);

    mmi_ret callProc(mmi_event_struct *evt);

    void setContactCuiId(mmi_id cui_id);
    void clearAppId(void);
    void getDialType(srv_ucm_call_type_enum *dial_type, mmi_sim_enum preferSIM);
    void setSelectedInfo(VfxS32 selected_index = -1, mmi_sim_enum selected_sim = MMI_SIM_NONE);
// Overide
public:
    virtual void onCreateView();

    virtual void onReleaseView();

    virtual void onSerializeView(VfxArchive *ar);

    virtual void onRestoreView(VfxArchive *ar);

    virtual void onEnterEditMode();

    virtual void onExitEditMode();

    void save(VfxS32 index = ITEM_NUM);

    virtual VfxPoint onGetEditButtonOffset();

    virtual void onDrag(VfxPenEvent &event);

    virtual void onMove(VfxPenEvent &event);

    virtual void onDrop(VfxPenEvent &event);

    virtual void onAbort(VfxPenEvent &event);

    virtual void onFocus();

    virtual void onDefocus();

    static mmi_ret static_callerProc(mmi_event_struct *evt);

// Variable
private:
    VfxS8 m_curr_id;
    VfxS32 m_selected_menu_popup_id;
    mmi_sim_enum m_selected_sim;    
    mmi_id m_phb_list_cui;
    mmi_id m_id;
    VfxBool m_edit_mode;
    VfxImageFrame *m_bgImg;
    VfxFrame *m_title_frame;
    VfxTextFrame *m_title;
    VcpImageButton *m_edit;
    VfxWeakPtr <VcpMenuPopup> m_opt_menu;
    VfxWeakPtr <VcpMenuPopup> m_sim_menu;
    VfxWeakPtr <VappWidgetVipContactPopup> m_card;
    VfxWeakPtr <VcpConfirmPopup> m_pop;
    VappWidgetVipContactItem* m_item_array[ITEM_NUM];
    mmi_phb_contact_id m_contacts_id[ITEM_NUM];
    static VappWidgetVipContact *m_context;
    static mmi_ret PhbListen(mmi_event_struct* evt);
    static mmi_ret DriveListen(mmi_event_struct* evt);
#if (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
    static mmi_ret SimEventListen(mmi_event_struct* evt);
#endif
};

struct vapp_widget_vip_contact_arg{
    VappWidgetVipContact *vipcontact;
};

class VappWidgetVipContactApp : public VfxApp
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidgetVipContactApp);

// Override
protected:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual mmi_ret onProc(mmi_event_struct * evt);

private:
    VappWidgetVipContact *m_vipcontact;
};

#endif /* __MMI_VUI_WIDGET_VIP_CONTACT__ */
#endif /* VAPP_WIDGET_VIP_CONTACT_H */

