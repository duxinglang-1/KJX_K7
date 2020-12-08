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
 *  vapp_mms_toolbar.h
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
#ifndef __VENUS_MMI_MMS_TOOLBAR_H__
#define __VENUS_MMI_MMS_TOOLBAR_H__

#include "MMI_features.h"
#include "vapp_msg_features.h"

#ifdef __MMI_MMS_2__
extern "C"
{
#include "MmsSrvGprot.h"
#include "mma_struct.h"
}
#include "vfx_uc_include.h"
#include "vfx_mc_include.h"
#include "vcp_status_icon_bar.h"
#include "vcp_page_panel.h"
#include "vcp_list_menu.h"
#include "vcp_popup.h"
#include "vcp_image_button.h"
#include "vcp_tool_bar.h"
#include "vcp_navi_title_bar.h"
#include "vapp_mms_data.h"
#include "vcp_tool_bar.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "MmsSrvGprot.h"
#include "MMIDataType.h"
#include "vcp_popup.h"

class VappMmsToolBar: public VcpToolBar
{
VFX_DECLARE_CLASS(VappMmsToolBar);
public:
    enum
    {
        ACTION_REPLY,
        ACTION_CALL,
        ACTION_FORWARD,
        ACTION_DELETE,
        ACTION_USE_DETAILS,
        ACTION_VIEW_OBJECTS,
        ACTION_COPY_TO,
        ACTION_RESEND,
        ACTION_EDIT,
        ACTION_USE,
        ACTION_REPORTS,	
        ACTION_TOTAL
    };
private:
    enum
    {
        COPY_MMS_TO_ARCHIVE,
        COPY_MMS_TO_CARD,
        COPY_MMS_TO_PHONE,
        COPY_MMS_TO_CANCEL,
        COPY_MMS_TO_TOTAL
    };
public:
    VappMmsToolBar():m_data(NULL),m_msg_id(0)
    {
        m_string = NULL;
		m_has_register = VFX_FALSE;
    }
    void onToolBarClick(VfxObject* sender, VfxId id);
    void onFolding(VfxObject* sender, VfxBool is_fold);
    void  setData(VappMmsViewerData *data);
    void updatToolbar(void);
    void call(void);
    static mmi_ret onUcClose(mmi_event_struct* user_data);
protected:
    virtual void onInit();
    virtual void  onDeinit(void);
private:
    void reply(void);
    void resend(void);
    void forward(void);
    void edit(void);
    void deleteMsg(void);
#ifdef __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__
    void copyToArchive(void);
    static void copyCbHdlr(srv_mms_result_enum result, void *rsp_data, void* user_data);
#endif  /*__MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__*/
#ifndef __COSMOS_NO_USER_DRIVE__    
    void copyToPhone(void);
    void copyTo(void);
#endif/*__COSMOS_NO_USER_DRIVE__*/
    void copyToMemoryCard(void);
    void viewObjects(void);
#ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
    void useDetails(void);
#endif/*__MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__*/    
#ifdef __MMI_MMS_REPORT_STATUS_SUPPORT__
	void reports(void);
#endif/*__MMI_MMS_REPORT_STATUS_SUPPORT__*/ 
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__	
    void editTemplate(void);
	void oneEditTemplatePopCallback(VfxObject *obj, VfxId id);
#endif/*__MMI_MMS_TEMPLATE_SUPPORT__*/ 
	void onForwardPopCallback(VfxObject *obj, VfxId id);
	void onEditPopCallback(VfxObject *obj, VfxId id);
	void onDeletePopCallback(VfxObject *obj, VfxId id);
	void onClickCmdBtn(VfxObject *obj, VfxId btn_id);
	VfxBool deleteOld(void);
	static mmi_ret handleCuiProc(mmi_event_struct *evt);
	static mmi_ret listener(mmi_event_struct* evt);
	static void * allocMem(U32 size, void *user_data);
    static void  freeMem(void *mem);
public:
    //VcpToolBar *m_tool_bar;
	VappMmsViewerData *m_data;
private:
	//static VfxU8 s_op_type ;
	VfxU32 m_msg_id;
	VfxU32 m_msg_type; 
	VfxU32 m_box_type;
	VcpIndicatorPopup *m_popup;
	VfxId m_btn_id;
	U16 *m_string;
	mmi_id m_curr_cui_id; 
	VfxBool m_has_register;
};
#ifdef __MMI_MMS_REPORT_STATUS_SUPPORT__
class  VappMMSReportsPage: public VfxPage, public IVcpListMenuContentProvider
{
VFX_DECLARE_CLASS(VappMMSReportsPage);
//Declaration
private:
    VfxU32 m_selectedIndex;
    VcpListMenu *m_menu;
    VcpTitleBar *m_titleBar;
    wap_mma_mms_msg_report_status_struct *m_list;
    VappMmsViewerData *m_data;
    VfxBool getMenuEmptyText(VfxWString &text,                
                                    VcpListMenuTextColorEnum &color  
                                    );

// Constructor/Destructors
public:
    VappMMSReportsPage(VappMmsViewerData *data = NULL):m_selectedIndex(0),m_menu(NULL),m_titleBar(NULL),m_list(NULL),m_data(data)
    {}

// Override
public:
    virtual void onInit();
    virtual void  onDeinit(void);
    void onQueryRotateEx(VfxScreenRotateParam &param); 
    virtual VfxU32 getCount() const;
    virtual VfxBool getItemText(
                                    VfxU32 index,                    
                                    VcpListMenuFieldEnum fieldType,  
                                    VfxWString &text,                
                                    VcpListMenuTextColorEnum &color  
                                    );
    virtual VfxBool getItemIsHighlightable(
                                                VfxU32 index       // [IN] the index of item
                                                ) const;


};
#endif /*__MMI_MMS_REPORT_STATUS_SUPPORT__*/
#endif /* __MMI_MMS_2__  */
#endif /*__VENUS_MMI_MMS_TOOLBAR_H__*/
