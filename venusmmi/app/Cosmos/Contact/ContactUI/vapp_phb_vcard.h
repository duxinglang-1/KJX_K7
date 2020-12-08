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
 *  vapp_phb_vcard.h
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
#include "MMI_features.h"

#ifndef __PB_VCARD_H__
#define __PB_VCARD_H__

#include "vfx_uc_include.h"
#include "vfx_mc_include.h"

#include "vcp_include.h"

#include "vapp_contact_entry.h"
#include "vapp_contact_op.h"


/***************************************************************************** 
 * Class ContactVcardViewer
 *****************************************************************************/ 
#ifdef __MMI_VCARD__
/*----------------------------------------------------------------*/
/* ContactVcardViewer                                             */
/*----------------------------------------------------------------*/
class ContactVcardViewerData;

class ContactVcardViewer : public VfxPage
{
private:
#if defined(__MMI_MAINLCD_320X480__)
    static const VfxU32 vcard_nav_icon_size = 40;
#elif defined(__MMI_MAINLCD_480X800__)
    static const VfxU32 vcard_nav_icon_size = 60;
#else
    static const VfxU32 vcard_nav_icon_size = 30;
#endif

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual mmi_ret onProc(mmi_event_struct *evt);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
    virtual void onRotate(
        const VfxScreenRotateParam &param // The parameter to rotate
        );
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

private:
    VcpForm                *m_form;
    VfxTextFrame           *m_title;
    VcpImageButton         *m_leftNav;
    VcpImageButton         *m_rightNav;
    VfxU32                  m_activeCount;
    ContactVcardViewerData *m_dateProvider;
    VfxU32                  m_fieldCount;
#ifdef __MMI_MULTI_VCARD__
    ContactRestore         *m_restore;
#endif
    VfxWString              m_path;
    VfxWString              m_titleString;
    VcpIndicatorPopup      *m_progress;
    VfxImageFrame          *m_bg;
    VfxBool                 m_isVertical;

private:
    void placeComponent();
    void createVcardForm();
    void onToolbarClicked(VfxObject* obj, VfxId id);
#ifdef __MMI_MULTI_VCARD__
    static void onSaveVcardCB(ContactOP* op, CONTACT_STATE state, srv_phb_async_op_cb_struct* result);
#endif
    static mmi_ret listener(mmi_event_struct* evt);
#ifdef __MMI_MULTI_VCARD__
    void onBtnClick(VfxObject* obj, VfxId id);
    void viewFront();
    void viewNext();
#endif    
    void nameFieldCreate();
    void numberFieldCreate();
    void emailFieldCreate();
#ifdef __MMI_PHB_INFO_FIELD__
    void addressFieldCreate();
#endif
    void birthdayFieldCreate();
#ifdef __MMI_PHB_INFO_FIELD__
    void titleFieldCreate();
#endif
#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
    void companyFieldCreate();
#endif
#ifdef __MMI_PHB_INFO_FIELD__
    void noteFieldCreate();
#endif
    void createNavBtn();
    void vcardPassDone();
#ifdef __MMI_MULTI_VCARD__
    void saveVcard();
    void onCancelClick(VfxObject* obj, VfxFloat num);
#endif
    ContactVcardViewerData *getDateProvider() {return m_dateProvider;}
};


/***************************************************************************** 
 * Class VappVcardCuiMainScr
 *****************************************************************************/ 
class VappVcardCuiMainScr : public VfxMainScr
{
public:
    VappVcardCuiMainScr(){}

protected:
    virtual void on1stReady();
};

/***************************************************************************** 
 * Class ContactApp
 *****************************************************************************/ 
class VappVcardCUI : public VfxCui
{
    VFX_DECLARE_CLASS(VappVcardCUI);

public:
    VappVcardCUI(){m_path = VFX_WSTR(""); m_content = 0; m_length = 0; m_isFromPath = VFX_TRUE;}
    virtual void onRun(void* args, VfxU32 argSize);
    void setPath(const VfxWString &path);
    void setContent(void *content, VfxU32 len);
    VfxWString getPath() const {return m_path;}
    VfxBool getIsFromPath() const {return m_isFromPath;}
    void *getContent() const {return m_content;}
    VfxU32 getContentSize() const {return m_length;}

public:

private:
    VfxWString m_path;
    void*      m_content;
    VfxU32     m_length;
    VfxBool    m_isFromPath;

private:
    void deleteTempPath();
    VfxBool createTempPath();
    void createFolder();
};


extern "C"
{
mmi_id vcui_vcard_create(mmi_id parent_id);
void vcui_vcard_run(mmi_id cui_id);
void vcui_vcard_close(mmi_id cui_id);

void vcui_vcard_set_path(mmi_id cui_id, const WCHAR *path);
void vcui_vcard_set_content(mmi_id cui_id, void *content, U32 length);
}

#ifdef __MMI_SMS_PORT_MSG__

extern "C"
{
void vapp_phb_vcard_sms_register(void);
}
#endif



#endif /* __MMI_VCARD__  */


#endif /* __PB_VCARD_H__ */

