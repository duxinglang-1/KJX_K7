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
 *  vapp_sms_template_scrn.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  SMS setting for Venus UI
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifndef __VAPP_SMS_TEMPLATE_SCRN_H__
#define __VAPP_SMS_TEMPLATE_SCRN_H__
#include "MMI_features.h" 

#ifdef __MMI_MESSAGES_TEMPLATE__

#include "vfx_mc_include.h"
#include "vapp_sms_util.h"
#include "vcp_menu_popup.h"
#include "vcp_include.h"
#include "vapp_text_template_core.h"
//#include "vapp_msg_misc_cp.h" // for iterator view

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
    #include "SmssrvGprot.h"
#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Class 
 *****************************************************************************/

/***************************************************************************** 
 * Class VappTextTemplateListPage
 *****************************************************************************/
class VappTextTemplateListPage: public VfxPage, public IVcpListMenuContentProvider
{
    //VFX_DECLARE_CLASS(VappTextTemplateListPage);

    typedef VappTextTemplateListPage   Self;
    typedef VfxPage                    Super;

public:
    VappTextTemplateListPage();
    void setListMenuSize(VfxS32 width, VfxS32 height);
    void setListMenuPos(VfxS32 x, VfxS32 y);
    void setTitleString(VfxWString str);
    void closePage();
    virtual VfxU32 getCount() const;
    virtual VfxBool getItemText(
                        VfxU32 index,
                        VcpListMenuFieldEnum fieldType,
                        VfxWString &text,
                        VcpListMenuTextColorEnum &color);
    virtual VfxBool getMenuEmptyText(VfxWString & text, VcpListMenuTextColorEnum & color);

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
    void onItemTapped(VcpListMenu *sender, VfxU32 index);
    void onLoadTemplateListDone(VfxObject *sender, VfxBool result);
    void onUpdateTemplateList(VfxObject *sender, VfxU16 templateId, VfxU16 listIndex);

public:
    VfxSignal3<VfxObject*, //sender
        VfxWString, //tapped template content
        VfxU16 // template Id
        > m_signalTemplateTapped;

private:
    VcpTitleBar *m_title;
    VcpListMenu *m_listMenu;
    SmsTemplateList *m_templateList;
    VfxBool m_initTemplateListDone;
};


/***************************************************************************** 
 * Class VappTextTemplatePage
 *****************************************************************************/
class VappTextTemplatePage: public VfxPage, public IVcpListMenuContentProvider
{
    //VFX_DECLARE_CLASS(VappTextTemplatePage);

    typedef VappTextTemplatePage   Self;
    typedef VfxPage                Super;
 
public:
    VappTextTemplatePage();
    virtual VfxU32 getCount() const;
    virtual VfxBool getItemText(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxWString &text,
        VcpListMenuTextColorEnum &color);
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;
    virtual VfxBool getMenuEmptyText(VfxWString & text, VcpListMenuTextColorEnum & color);

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
    virtual void onBack();

private:
    VfxBool getCheckedState(VfxU16 templateId) const;
    void setCheckedState(VfxU16 templateId, VfxBool set);
    void setAllCheckedState(VfxBool set);
    void onAddTemplate(VfxObject *sender, VfxU16 templateId, VfxU16 listIndex);
    void onDelTemplate(VfxObject *sender, VfxU16 templateId, VfxU16 listIndex);
    void onChangeToNormalMode();
    void onChangeToMarkMode();
    void onUpdateNormalToolBar();
    void onUpdateMarkToolBar(VfxBool set);
    void onItemTapped(VcpListMenu *sender, VfxU32 index);
    void onItemLongTapped(VcpListMenu *sender, VfxU32 index);
    void onItemStateChanged(VcpListMenu *sender, VfxU32 index, VcpListMenuItemStateEnum newState);
    void onLongTappedMenuPopupClicked(VcpMenuPopup *sender, VcpMenuPopupEventEnum eventType, VcpMenuPopupItem *item);
    virtual mmi_ret onProc(mmi_event_struct * evt);
    void onToolbarTapped(VfxObject *sender, VfxId id);
    void onPreDeleteSingleTemplate(VfxObject *sender, VfxId id);
    void onDeleteSingleTemplate(VfxBasePopup *popup, VfxBasePopupStateEnum state);
    void onPreDeleteTemplate(VfxObject *sender, VfxId id);
    void onDeleteTemplate(VfxBasePopup *popup, VfxBasePopupStateEnum state);
    void onLoadTemplateListDone(VfxObject *sender, VfxBool result);

public:
    VfxSignal3<VfxObject*, //sender
        VfxWString, //tapped template content
        VfxU16 // template Id
        > m_signalTemplateTapped;

private:
    #define VAPP_SMS_TEMPLATE_CHECK_BIT_U8_NUM    ((SRV_SMS_TEMPLATE_TOTAL_NUM + 7)/8)

    enum
    {
        ITEM_ID_TOOLBAR1_ADD,
        ITEM_ID_TOOLBAR1_DELETE,
        ITEM_ID_TOOLBAR2_SELECT_ALL,
        ITEM_ID_TOOLBAR2_UNSELECT_ALL,
        ITEM_ID_TOOLBAR2_DELETE,
        ITEM_ID_TOOLBAR2_CANCEL,
        ITEM_ID_LONGTAP_ID_USE,
        ITEM_ID_LONGTAP_ID_DELETE,
        ITEM_ID_LONGTAP_ID_EDIT,
        TTEM_ID_TOTAL
    };

    VcpListMenu *m_listMenu;
    SmsTemplateList *m_templateList;
    VcpToolBar *m_toolBar;
    VfxBool m_hasCheckBox;
    VfxBool m_initTemplateListDone;
    VfxBool m_deleteConfirmed;
    VfxU16 m_curTemplateId;
    VfxU8 m_checkBit[VAPP_SMS_TEMPLATE_CHECK_BIT_U8_NUM];
    VfxU16 m_selectCount;
};


/***************************************************************************** 
 * Class VappTextTemplateViewerPage
 *****************************************************************************/
class VappTextTemplateViewerPage: public VfxPage
{
    //VFX_DECLARE_CLASS(VappTextTemplateViewerPage);

    typedef VappTextTemplateViewerPage   Self;
    typedef VfxPage                      Super;

public:
    VappTextTemplateViewerPage();
    VappTextTemplateViewerPage(VfxU16 templateId);

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
    void onToolBarClick(VfxObject *obj, VfxId id); //m_signalButtonTap
    static mmi_ret onCuiProc(mmi_event_struct * evt);
    void onPreDeleteTemplate(VfxObject *sender, VfxId id);
    void onDeleteTemplate(VfxBasePopup *popup, VfxBasePopupStateEnum state);
    void onDelTemplate(VfxObject *sender, VfxU16 templateId, VfxU16 listIndex);

private:
    enum
    {
        TOOLBAR_ID_USE,
        TOOLBAR_ID_EDIT,
        TOOLBAR_ID_DELETE,
        TOOLBAR_ID_TOTAL
    };

    enum
    {
    #if defined(__MMI_MAINLCD_480X800__)
        TEXT_VIEW_MARGIN_TOP        = 14,
        TEXT_VIEW_MARGIN_LEFT       = 14,
        TEXT_VIEW_MARGIN_BUTTOM     = 14
    #elif defined(__MMI_MAINLCD_320X480__)
        TEXT_VIEW_MARGIN_TOP        = 8,
        TEXT_VIEW_MARGIN_LEFT       = 8,
        TEXT_VIEW_MARGIN_BUTTOM     = 8
    #else /* __MMI_MAINLCD_240X320__ __MMI_MAINLCD_240X400__  */
        TEXT_VIEW_MARGIN_TOP        = 5,
        TEXT_VIEW_MARGIN_LEFT       = 5,
        TEXT_VIEW_MARGIN_BUTTOM     = 5
    #endif
    };

    VcpTextView *m_templateView;
    VcpToolBar *m_toolBar;
    SmsTemplate *m_template;
    VfxU16 m_templateId;
    VfxBool m_deleteConfirmed;
};

#if 0 // for iterator view
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // end if 0, for iterator view

#endif //__SRV_SMS_TEMPLATE__

#endif /* __VAPP_SMS_TEMPLATE_SCRN_H__ */

