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
 *  vcui_sms_composer_contactlist.cpp
 *
 * Project:
 * --------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/ 
#ifndef _VCUI_SMS_COMPOSER_CONTACTLIST_H_
#define _VCUI_SMS_COMPOSER_CONTACTLIST_H_

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_contact_list.h"

class VcuiSmsComposerContactList:public VfxFrame,  public IVcpListMenuContentProvider
{
	 VFX_DECLARE_CLASS(VcuiSmsComposerContactList);
private:	

	VfxS32 m_hintlength;
	VfxWString m_hinttext;
	VcpListMenu* m_listmenu;
	ContactList *m_contactlist;
	VfxU32 m_alignField;
	VfxU8 m_contactlisttype;
	
protected:
	virtual void onInit();
public:

	enum
    {
		ENUM_VCUI_SMSC_CONTACTLIST_TYPE_NONE,
		ENUM_VCUI_SMSC_CONTACTLIST_TYPE_EMAIL,
		ENUM_VCUI_SMSC_CONTACTLIST_TYPE_PHBOOK,
		ENUM_VCUI_SMSC_CONTACTLIST_TYPE_TOTAL
	};

	VfxSignal1 <VfxU32> m_signalListUpdated;
    
    void setSearchString(const VfxWString& search);

    void setAlignField(VfxU32 alignField);

    void setGroup(VfxU32 groupId, VfxBool isEqual = VFX_TRUE);
	template <class _func_type>
	void setTappedHandler(VfxObject *obj, _func_type func)
	{
		this->m_listmenu->m_signalItemTapped.connect(obj, func);
	}
    
    void getList();

	ContactList *getContactList()
	{
		return m_contactlist;
	}

	VfxU8 getContactListType()
	{
		return m_contactlisttype;
	}

	// build list done
    void onListReady();

    // list changed
    void onListRefresh(ContactList* list, mmi_event_struct* evt);
		 
	VcuiSmsComposerContactList(VfxS32 len);
	VcuiSmsComposerContactList():
        m_hintlength(0),
        m_listmenu(NULL),
        m_contactlist(NULL)
	{
	}
	//virtual void setMenu(VcpListMenu *menu);
	virtual VfxBool getItemText(
		VfxU32 index,                    // [IN] the index of item
		VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
		VfxWString &text,                // [OUT] the text resource
		VcpListMenuTextColorEnum &color  // [OUT] the text color
		);
	virtual VfxU32 getCount() const;
	virtual VfxBool getItemImage(
		VfxU32 index,                    
		VcpListMenuFieldEnum fieldType,  
		VfxImageSrc &image         
		) ;

	virtual VfxBool getItemTextFormat(
							VfxU32 index,                    // [IN] the index of item,
							VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
							VcpRichText &format        // [OUT] the text resource
						);	
	void updateHintList(VfxWChar *text);
	void onTapItem(VcpListMenu *listMenu, VfxU32 itemIndex);
	VfxBool isMenuListActivated()
	{
		return (m_listmenu != NULL);
	}
};
#endif /* _VCUI_SMS_COMPOSER_CONTACTLIST_H_ */
