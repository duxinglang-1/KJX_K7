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
 *  vapp_mms_view_objects.h
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
#ifndef __VENUS_MMI_MMS_VIEW_OBJ_APP__
#define __VENUS_MMI_MMS_VIEW_OBJ_APP__

#include "MMI_features.h"
#include "vapp_msg_features.h"

#ifdef __MMI_MMS_2__

#include "vfx_uc_include.h"
#include "vfx_mc_include.h"
#include "vcp_status_icon_bar.h"
#include "vcp_page_panel.h"
#include "vcp_list_menu.h"
#include "vcp_popup.h"
#include "vcp_image_button.h"



typedef enum
{
	VAPP_MMS_VIEW_OBJECT_SAVE,
	VAPP_MMS_VIEW_OBJECT_VIEW,
	VAPP_MMS_VIEW_OBJECT_MAX

}vapp_mms_view_object_type_enum;

class VappMmsViewObjectsPage : public VfxPage, public IVcpGroupListMenuContentProvider
{
	VFX_DECLARE_CLASS(VappMmsViewObjectsPage);
	
//declaration
public:
	static VfxU16 *getFileName(srv_mms_viewer_object_struct *object_info, VfxObject *obj_mem);

//constructor
public:
	VappMmsViewObjectsPage(VfxU32 index = 0):m_srv_index(index)
	{
		m_attachment_count = 0;
	}

//override
	virtual void onDeinit(void);
	virtual void onInit(void);
	void OnListFocused(VcpGroupListMenu *, // Sender
        VcpMenuPos,        // Current focus list item index
        VcpMenuPos         // Previous focus list item index
		);
	virtual VfxU32 getCount(VfxU32 group) const;
	virtual VfxU32 getGroupCount() const;
	virtual VfxBool getItemText(
        VcpMenuPos pos,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );
	virtual VfxBool onKeyInput(VfxKeyEvent &event);
	virtual VfxBool getItemImage(
        VcpMenuPos pos,                  // [IN] the position of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        ); 
	virtual void onQueryRotateEx(VfxScreenRotateParam &param);
	virtual VfxBool hasGroupHeader(VfxS32 group) const;
	virtual void onEnter(VfxBool isBackward);
	virtual void onRotate(const VfxScreenRotateParam &param);
//implementation
private:
	void onObjectTapped(VcpGroupListMenu *, // Sender
        VcpMenuPos );
	srv_mms_viewer_object_struct * getObjectFromPos(VcpMenuPos pos);
//variables
private:
	VcpGroupListMenu *m_list;
	VfxU32 m_srv_index;
	VfxU32 m_attachment_count;
	VfxBool txt_not_present;
	VfxS32 grp_pos;
	VcpMenuPos m_hilited_index;
//enum
private:
	enum
	{
		VIEW_OBJECT_SLIDE_STR_SIZE = 6,
		VIEW_OBJECT_BUFFER_SIZE = 20,
		VIEW_OBJECT_SIZE_CONVERTOR = 1024,
	}viewObjectEnum;
	
};

class VappMmsViewObjectsHandler : public VfxFrame
{

	VFX_DECLARE_CLASS(VappMmsViewObjectsHandler);
//declaration
//method
public:
	void VappMmsViewObjectsCb(VfxObject *obj, VfxId id);
	void preview();
	void deleteProgressBar(void);
//constructor
public:
	VappMmsViewObjectsHandler(srv_mms_viewer_object_struct *object = NULL, VfxU32 slide_num = 0)
	{
		m_object = object;
		m_progress = NULL;
		m_is_preview = VFX_FALSE;
		m_cuiId = GRP_ID_INVALID;
		m_parent_fh = 0;
		m_slide_num = slide_num;
	}
	virtual void onDeinit(void);
//implementation

//method
private:
	void save();
	static void saveRspFrmSrv(void *user_data, mmi_id evt_type, void *rsp_err);
	void saveRspFrmSrvHdlr(mmi_id evt_type, void *rsp_err);
	void usePreviewCui(void);
	static mmi_ret previewCuiProc(mmi_event_struct *evt);
	mmi_ret previewCuiProcInt(mmi_event_struct *evt);
	
//variable
private:
	srv_mms_viewer_object_struct * m_object;
	VfxBool m_is_preview;
	VcpIndicatorPopup *m_progress;
	mmi_id m_cuiId;
	S32 m_parent_fh;
	VfxU32 m_slide_num;
};

#endif /* __MMI_MMS_2__ */
#endif /*__VENUS_MMI_MMS_VIEW_OBJ_APP__*/
