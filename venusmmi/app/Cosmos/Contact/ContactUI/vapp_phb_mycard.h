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
 *  vapp_phb_mycard.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "vapp_phb_gprot.h"

#ifdef __MMI_PHB_MYCARD__
#ifndef __PB_MYCARD_H__
#define __PB_MYCARD_H__

#include "vfx_uc_include.h"
#include "vfx_mc_include.h"

#include "vcp_include.h"
#include "vcp_form.h"

#include "vapp_contact_vcard.h"
#include "vapp_contact_util.h"
#include "vapp_phb_editor.h"
#include "vapp_uc_gprot.h"


/***************************************************************************** 
 * Class VappPhbMycardScr
 *****************************************************************************/ 
class VappPhbMycardScr: public VfxMainScr
{
public:
    void onSavedDone();

protected:
    virtual void on1stReady();

    void onContactUpdated(ContactTask* task, mmi_event_struct* evt);

private:
    Contact *m_contact;
};


/***************************************************************************** 
 * Class VappPhbMycardEditorPage
 *****************************************************************************/ 
class VappPhbMycardEditorPage: public VfxPage
{
public:
    VappPhbMycardEditorPage(Contact *contact);

    void onToolBarClick(VfxObject* obj, VfxId id);

    void onItemLabelSelected(VfxU32 type, VfxWString label, VfxU32 userData);

    void onItemLabelClick(VfxObject* obj, VfxId id);

    void onNumberClick(VcpFormItemRemovableTextEntry* obj, VfxId id, VfxBool addRemove);

    void onEmailClick(VcpFormItemRemovableTextEntry* obj, VfxId id, VfxBool addRemove);

    void onEditorActived(VcpTextEditor *editor, VfxBool isActived);

    void onEditorPreActive();

    VfxSignal0 m_signalSaved;

private:
    void createForm();

    void createName();

    void createNumber();

    void createNewNumber();

    void createEmail();

    void createNewEmail();

    void save();

protected:
    virtual void onInit();

#ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__
    virtual mmi_ret onProc(mmi_event_struct *evt);
#endif

private:
    VappPhbMycardEditorPage(){}

private:
    VcpForm                 *m_form;
    Contact                 *m_contact;
    VappPhbFieldItem        *m_field;
    VfxU32                   m_numCount;
    VfxU32                   m_emailCount;
    VcpTextEditor           *m_activeEditor;

    enum PB_CONTACT_EDITOR_CMD_TYPE
    {
        PB_CONTACT_EDITOR_CMD_SAVE,
        PB_CONTACT_EDITOR_CMD_CANCEL,
        PB_CONTACT_EDITOR_CMD_TYPE_TOTAL
    };

    enum PB_CONTACT_ITEM_TYPE
    {
        PB_CONTACT_ITEM_NAME,
        PB_CONTACT_ITEM_NUMBER_CAP,
        PB_CONTACT_ITEM_NUMBER,
        PB_CONTACT_ITEM_NUMBER_NEW,
        PB_CONTACT_ITEM_EMAIL_CAP,
        PB_CONTACT_ITEM_EMAIL,
        PB_CONTACT_ITEM_EMAIL_NEW,
        PB_CONTACT_ITEM_TYPE_TOTAL
    };
};


/***************************************************************************** 
 * Class VappPhbMycardProfilePage
 *****************************************************************************/ 
class VappPhbMycardProfilePage: public VfxPage
{
public:
    VappPhbMycardProfilePage(Contact *contact);

#ifdef __MMI_VCARD__
    void shareContact();

    void onShareSelected(VfxObject *obj, VfxId id);
#endif

    void onToolBarClick(VfxObject *obj, VfxId id);

    void onSavedDone();

protected:
    virtual void onInit();

#ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__
    virtual mmi_ret onProc(mmi_event_struct *evt);
#endif

private:
    void createForm();

private:
    Contact *m_contact;
    VcpForm *m_form;

private:
    VappPhbMycardProfilePage(){}

public:
#ifdef __MMI_VCARD__
    VappContactvCard *m_vcard;
#endif
    VfxWChar         *m_path;

    enum
    {
        VAPP_PHB_MYCARD_PROFILE_SHARE,
        VAPP_PHB_MYCARD_PROFILE_EDIT
    };

    enum
    {
        VAPP_CONTACT_SHARE_BY_SMS,
        VAPP_CONTACT_SHARE_BY_MMS,
        VAPP_CONTACT_SHARE_BY_BT,
        VAPP_CONTACT_SHARE_BY_EMAIL,
        VAPP_CONTACT_SHARE_TOTAL
    };
};

#endif /* __PB_MYCARD_H__ */
#endif /* __MMI_PHB_MYCARD__ */
