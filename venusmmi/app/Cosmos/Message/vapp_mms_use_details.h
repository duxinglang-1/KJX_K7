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
#ifndef __VENUS_MMI_MMS_USE_DETAIL_APP__
#define __VENUS_MMI_MMS_USE_DETAIL_APP__

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
	VAPP_MMS_USE_DETAILS_ADDRESSES_NEW_CONTACT,
	VAPP_MMS_USE_DETAILS_ADDRESSES_SAVE_TO_PHBOOK,
	VAPP_MMS_USE_DETAILS_SEND_MESSAGE,
	VAPP_MMS_USE_DETAILS_SEND_MMS,
	VAPP_MMS_USE_DETAILS_SEND_EMAIL,
	VAPP_MMS_USE_DETAILS_ADDRESSES_GO_TO,
	VAPP_MMS_USE_DETAILS_ADDRESSES_ADD_BOOKMARK,
	VAPP_MMS_USE_DETAILS_ADDRESSES_EDIT_BEFORE_CALL,
	VAPP_MMS_USE_DETAILS_TOTAL
}vapp_mms_use_detail_enum;

#ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__

class VappMmsUseDetailsPage : public VfxPage, public IVcpListMenuContentProvider
{
	VFX_DECLARE_CLASS(VappMmsUseDetailsPage);
	

//declaration
	
public:
	void VappMmsUseNumberCb(VfxObject *obj, VfxId id);
	void VappMmsUseEmailCb(VfxObject *obj, VfxId id);
	void VappMmsUseUrlCb(VfxObject *obj, VfxId id);
	virtual void onInit(void);
	virtual void onDeInit(void);
	virtual VfxU32 getCount(void) const;
	virtual VfxBool getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc &image);
	virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        ); 
	virtual VfxBool onKeyInput(VfxKeyEvent &event);
	virtual void onQueryRotateEx(VfxScreenRotateParam &param);
	virtual void onEnter(VfxBool isBackward);
	virtual void onRotate(const VfxScreenRotateParam &param);
//contructor
public:
	VappMmsUseDetailsPage(VfxU32 index = 0, VfxU8 sim = 0):m_srv_index(index), m_sim(sim)
	{

	}

//override
protected:
	
	void onUseDetialTapped(VcpListMenu *, VfxU32);
	void onClickLaunchers(VcpListMenu *list, // Sender
        VfxU32  index);
	
//implementation

//variables
private:
	VcpListMenu *m_list;
	VappMmsUseDetails *m_use_details;
	VfxU32 m_srv_index;
	VfxS32 m_hilited_index;
	VfxU8 m_sim;
	
};
#endif  /*__MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__*/

class VappMmsUseDetailHandler : public VfxFrame
{

	VFX_DECLARE_CLASS(VappMmsUseDetailHandler);
//declaration
//method
public:
	void VappMmsUseNumberCb(VfxObject *obj, VfxId id);
	void VappMmsUseEmailCb(VfxObject *obj, VfxId id);
	void VappMmsUseUrlCb(VfxObject *obj, VfxId id);
	void call(void);
	void goToUrl(void);
	void SendEmail(void);
//constructor
public:
	VappMmsUseDetailHandler()
	{
		m_string = NULL;
	}
	VappMmsUseDetailHandler(U16 *, VfxS32, U16, VfxU8);
	VappMmsUseDetailHandler(U16 *, U16, VfxU8);

protected:
	virtual void onDeinit(void);
//implementation

//method
private:
	void saveToBookmark(void);
	mmi_ret handleCuiIntProc(mmi_event_struct *evt);
	static mmi_ret handleCuiProc(mmi_event_struct *evt);
	void onEmailTruncated(VfxBasePopup*, VfxBasePopupStateEnum);
	void onClickOk(VfxObject* obj, VfxId id);
	void useCui();
//variable
private:
	U16 *m_string;
	mmi_id m_curr_cui_id; 
	vapp_mms_use_detail_enum m_operation;
	U16 m_type;
	VfxU8 m_sim;

};

#endif /* __MMI_MMS_2__ */
#endif /*__VENUS_MMI_MMS_USE_DETAIL_APP__*/
