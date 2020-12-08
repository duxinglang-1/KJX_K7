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
 *  vapp_phb_extra.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifndef _PB_EXTRA_H__
#define _PB_EXTRA_H__

#include "vfx_uc_include.h"
#include "vfx_mc_include.h"

#include "vcp_include.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "mmi_frm_utility_gprot.h"
#include "PhbSrvGprot.h"
#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Class VappContactSettingExtraSimSelect
 *****************************************************************************/
class VappContactSettingExtraSimSelect : public VfxPageHandler, public IVcpListMenuContentProvider
{
public:
    virtual void onPageInit(VfxPageEx * page);

private:
    VcpForm                 *m_form;
    VcpFormItemLauncherCell *m_item[MMI_SIM_TOTAL];

private:
    void onButtonClicked(VcpFormItemCell* sender, VfxId id);
};


/***************************************************************************** 
 * Class VappContactSettingFdnList
 *****************************************************************************/
class VappContactSettingFdnList : public VfxPage, public IVcpListMenuContentProvider
{
public:
    enum secsetType
    {
        TYPE_MODE_SWITCH,
        TYPE_EDIT,
        TYPE_DELETE,
        TYPE_END
    };

public:
    VappContactSettingFdnList();
    VappContactSettingFdnList(mmi_sim_enum type);

    virtual void onInit();
    virtual VfxU32 getCount() const;
    virtual VfxBool getItemText(
            VfxU32 index,                    // [IN] the index of item
            VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
            VfxWString &text,                // [OUT] the text resource
            VcpListMenuTextColorEnum &color  // [OUT] the text color
            );
    virtual mmi_ret onProc(mmi_event_struct *evt);
    static void fdnModeRsp(VfxU16 result, void* user_data);
    static void getListCB(VfxU16 result, void* user_data);

private:
    VcpListMenu            *m_list;
    VcpForm                *m_form;
    VcpFormItemSwitchCell  *m_fdnSwitch;

    mmi_sim_enum            m_simType;
    SRV_PHB_XMGNT_HANDLE    m_handle;
    VfxBool                 m_fdnStatus;
    secsetType              m_secset;
    VfxU16                  m_index;
    VfxBool                 m_isNew;

private:
    void onNameItemClick(VcpListMenu *obj, VfxU32 index);
    void setFdnMode();
    void fdnModeReq();
    void asycPostInit();
    void onFdnModeChange(VcpFormItemSwitchCell* obj, VfxId id, VfxBool value);
    void onToolBarClicked(VfxObject* obj, VfxId id);
    void onEditDone();
    void secsetCuiRun();
    void editFdn();
    void deleteFdn();
    void addClick();
};


/***************************************************************************** 
 * Class VappContactSettingFdnEdit
 *****************************************************************************/
class VappContactSettingFdnEdit : public VfxPage
{
public:
    VfxSignal0             m_signalSave;

public:
    VappContactSettingFdnEdit();
    VappContactSettingFdnEdit(
        VfxWChar *name_buf,
        VfxWChar *num_buf,
        mmi_sim_enum simType,
        SRV_PHB_XMGNT_HANDLE handle,
        VfxU16 index,
        VfxBool value);

    virtual void onInit();
    void save();
    static void saveFdnRsp(VfxU16 result, void* user_data);

private:
    VcpForm               *m_form;
    VcpFormItemTextInput  *m_formName;
    VcpFormItemTextInput  *m_formNumber;
    VcpTextEditor         *m_editorName;
    VcpTextEditor         *m_editorNumber;
    VfxWString             name;
    VfxWString             number;
    mmi_sim_enum           m_simType;
    SRV_PHB_XMGNT_HANDLE   m_handle;
    VfxU16                 m_index;
    VfxBool                m_isNew;

private:
    void onToolBarClicked(VfxObject* obj, VfxId id);
    void onEditorActived(VcpTextEditor *editor, VfxBool isActived);
    void onFuncBarTapped(VfxObject* obj, VfxId id);
    void saveFdn();
};


/***************************************************************************** 
 * Class VappContactSettingFdnMarkDeleteList
 *****************************************************************************/
class VappContactSettingFdnMarkDeleteList : public VfxPage, public IVcpListMenuContentProvider
{
public:
    VfxSignal0                  m_signaldelete;

public:
    VappContactSettingFdnMarkDeleteList();
    VappContactSettingFdnMarkDeleteList(mmi_sim_enum type);

    virtual void onInit();
    virtual VfxU32 getCount() const;
    virtual VfxBool getItemText(
            VfxU32 index,                    // [IN] the index of item
            VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
            VfxWString &text,                // [OUT] the text resource
            VcpListMenuTextColorEnum &color  // [OUT] the text color
            );
    virtual void onEntered();
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;
    static void getListCB(VfxU16 result, void* user_data);
    static void deleteFdnRsp(VfxU16 result, void* user_data);

private:
    VcpListMenu                *m_list;
    mmi_sim_enum                m_simType;
    SRV_PHB_XMGNT_HANDLE        m_handle;
    VfxBool                     m_state[SRV_PHB_XMGNT_SIM_ENTRIES];
    VfxS32                      m_indexDeleting;

private:
    void onToolBarClicked(VfxObject* obj, VfxId id);
    void asycPostInit();
    void onItemTapped(VcpListMenu *list, VfxU32 index);
    void deleteSelectItems();
    void deleteOneItem();
    VfxU32 getSelectCount();
    void deleteTap();
    void onButtonClicked(VfxObject* obj, VfxId id);
};

#endif /* _PB_EXTRA_H__ */

