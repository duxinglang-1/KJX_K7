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
 *  vapp_task_all_list.h
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

#ifndef __VAPP_TASK_ALL_LIST_H__
#define __VAPP_TASK_ALL_LIST_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_cal_list_mgr.h"
#include "vcp_menu_popup.h"



/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
enum VAPP_TASK_ALL_LIST_ENTRY_TYPE
{
    VAPP_TASK_ALL_ENTRY_TASK,
    VAPP_TASK_ALL_ENTRY_UC,
    VAPP_TASK_ALL_ENTRY_TOTAL
};

/***************************************************************************** 
 * Class 
 *****************************************************************************/
 

class VappTaskAllListPage : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappTaskAllListPage);
    
public:
    VappTaskAllListPage(){};
    VappTaskAllListPage(VAPP_TASK_ALL_LIST_ENTRY_TYPE type) : m_entryType(type){};

public:
    enum VAPP_TASK_ALL_LIST_ACTION
    {
        VAPP_TASK_LIST_ADD,
        VAPP_TASK_LIST_SEARCH,
        VAPP_TASK_LIST_DELETE,
        VAPP_TASK_SEL_LIST_MARK_ALL,
        VAPP_TASK_SEL_LIST_DELETE,
        VAPP_TASK_SEL_LIST_CANCEL
    };

public:
    virtual void onInit();
    virtual void onDeinit();
    void onEnter(VfxBool isBackward);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
    virtual void onBack();

    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    virtual VfxU32 getCount() const;

    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        );
    
    VcpListMenuItemStateEnum getItemState(VfxU32 index) const;

    virtual VfxBool getMenuEmptyText(
                        VfxWString &text,               
                        VcpListMenuTextColorEnum &color);

    
    void updateTaskListPageInt();

public:
    void onToolBarClicked(VfxObject *sender, VfxId id);
    void onListMenuClicked(VcpListMenu *sender, VfxU32 index);
    void onCommBtnClicked(VcpListMenu *sender, VfxU32 index);
    void onSelListMenuClicked(
                        VcpListMenu * sender, 
                        VfxU32 index,        
                        VcpListMenuItemStateEnum state);
    void onDeleteConfirm(VfxObject* sender, VfxId id);
    void onListMenuLongTap(VcpListMenu *sender, VfxId id);
    void onOpListClicked(VcpMenuPopup* sender, VcpMenuPopupEventEnum evtEnum, VcpMenuPopupItem* item);
    void onLongPressDelConfirm(VfxObject* sender, VfxId id);
    void updateListData();
    
public:
    //VfxSignal2 <VfxObject*, VfxId, VfxU16> m_signalDataChanged;
    VfxBool m_markAllBtn;            // this flag used to distinguish button is mark-all or unmark-all

public:
    static mmi_ret updateTaskListPage(mmi_event_struct *param);
    
private:
    VcpTitleBar *m_titleBar;
    VcpToolBar *m_toolBar;
    VcpListMenu *m_listMenu;
    VappCalListMgr *m_listMgr;
    VfxBool m_isMutiDelProcessing;    
    VfxU16 m_selIdx;
    VAPP_TASK_ALL_LIST_ENTRY_TYPE m_entryType;
    VfxU16 m_dataChangedType;

    VfxWeakPtr<VcpMenuPopup> m_opListWeakPtr;
    VfxWeakPtr<VcpConfirmPopup> m_confirmPopupWeakPtr;

    VfxWChar *path;
};

#endif //__VAPP_TASK_ALL_LIST_H__
