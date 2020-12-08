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
 *  vtst_sample_contact_list.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Description
 *      Sample screens for contact list
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_CONTACT_LIST_H__
#define __VAPP_CONTACT_LIST_H__

#ifdef __AFX_RT_TEST__
#include "vcp_tabctrl_page.h"
//#include "cp\vcp_textview.h"
#include "vcp_list_menu.h"
#include "vfx_app.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_main_scr.h"
#include "vfx_page.h"
#include "vfx_text_frame.h"
#include "vcp_base_menu.h"
#include "vcp_text_editor.h"
#include "vfx_cpp_base.h"
#include "vfx_string.h"
#include "vcp_text_utils.h"
#include "vcp_tool_bar.h"
/***************************************************************************** 
 * Class VappTestContact
 *****************************************************************************/
class VappTestContact : public VfxApp
{
    VFX_DECLARE_CLASS(VappTestContact);
public:
    virtual void onRun(void* args, VfxU32 argSize);
};

/***************************************************************************** 
 * Class VappTestContactListScrn
 *****************************************************************************/
class VappTestContactListScrn : public VfxMainScr
{
     VFX_DECLARE_CLASS(VappTestContactListScrn);
public:
    virtual void on1stReady(); 
};


/***************************************************************************** 
 * Class VappTestContactTabPage
 *****************************************************************************/
class VappTestContactTabPage : public VcpTabCtrlPage
{
    VFX_DECLARE_CLASS(VappTestContactTabPage);
public:
    virtual void onInit();
	virtual VfxPage *onCreateTabPage(VfxId tabId);
	void onToolBarClick(VfxObject* sender, VfxId id);

};

/***************************************************************************** 
 * Class VappTestContactOtherPage
 *****************************************************************************/
class VappTestContactOtherPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappTestContactOtherPage);
// Override
public:
    virtual void onInit();
private:
	VfxTextFrame *m_text;
};

/***************************************************************************** 
 * Class VappSampleContactListPage
 *****************************************************************************/
/*
 *  VcpGroupListMenu is a class that can create contact list page, which display
 *  contact list group menu
 */
class VappTestContactListPage : public VfxPage,public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappTestContactListPage);
public:
    virtual void onInit();
// slot
	void OnListFocused(VcpGroupListMenu *, // Sender
        VcpMenuPos,        // Current focus list item index
        VcpMenuPos         // Previous focus list item index
		);
	void OnListTapped(VcpGroupListMenu *, // Sender
		VcpMenuPos);
	void OnTextChanged(VcpTextEditor*);
	void onToolBarClick(VfxObject* sender, VfxId id);

//override
public:
	virtual VfxU32 getGroupCount() const;
	virtual VfxU32 getCount(VfxU32 group) const;
	virtual VfxBool getItemText(
        VcpMenuPos pos,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );
	virtual VfxBool getItemTextFormat(
        VcpMenuPos pos,                  // [IN] the position of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VcpRichText &format          // [OUT] the text resource
        );
private:
	VcpGroupListMenu *m_list;
	VcpListMenuSearchBar *m_searchbar;
	VcpTextEditor *m_editor;
	VcpToolBar *m_bar;
	VfxU32 m_search_count;
	VfxU32 m_search_index;
	VfxBool  m_show_search;
	VfxU32 m_search_text_length;
};
#endif
#endif /* __VAPP_CONTACT_LIST_H__ */
