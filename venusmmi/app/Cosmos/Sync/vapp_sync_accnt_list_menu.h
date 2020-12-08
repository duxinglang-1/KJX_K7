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
 *  vapp_sync_accnt_list_menu.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_SYNC_ACCNT_LIST_MENU_H__
#define __VAPP_SYNC_ACCNT_LIST_MENU_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_datatype.h"
#include "vfx_signal.h"

#include "vcp_list_menu.h"
#include "vcp_menu_popup.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_SYNC_ACCNT_LIST_ACTION_SYNC	'SYNC'
#define VAPP_SYNC_ACCNT_LIST_ACTION_DELETE	'DELE'
#define VAPP_SYNC_ACCNT_LIST_ACTION_VLOG	'VLOG'	/* View Log */

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef struct{
	VfxS32 index;
	VfxU32 timestamp;
}IndexTimestampStruct;

/***************************************************************************** 
 * Class VappSyncAccntListMenu
 *****************************************************************************/
class VfxObject;
class VfxWString;
class VfxImageSrc;
class VappSyncAccntListMenu : public VcpGroupListMenu, public IVcpGroupListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappSyncAccntListMenu);
	
public:

	VappSyncAccntListMenu() : m_nAccnt(0), m_index(0) {}
	virtual ~VappSyncAccntListMenu(){}

	VfxSignal2<VfxObject *, VfxS32> m_signalTap;
	VfxSignal3<VfxObject *, VfxId, VfxS32> m_signalAction;

	void updateAllItems();

	enum{ MAX_ARRAY_BUFF = 10};
	
	static void sortIndexList(IndexTimestampStruct *list, const VfxU32 &len);
	
// Override
protected:	
	virtual void onInit(void);
	virtual VfxU32 getCount(VfxU32 group) const {return m_nAccnt;}
	virtual VfxU32 getGroupCount() const {return (m_nAccnt > 0 ? 1 : 0);} // only one group right now
	virtual VfxBool getHeaderText(VfxWString &text){ return VFX_FALSE; }
	virtual VfxBool getText(VfxS32 index, VfxWString &text){ return VFX_FALSE; }
	virtual VfxU32 getUpdatedCount(void) { return m_nAccnt; }
	virtual VfxBool isShowIcon(const VfxS32 &index) { return VFX_FALSE; }
	
private:
	VfxBool getItemText(
		        VcpMenuPos pos,                  // [IN] the position of item
		        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
		        VfxWString &text,                // [OUT] the text resource
		        VcpListMenuTextColorEnum &color  // [OUT] the text color
		        );
	VfxBool getItemImage(
				VcpMenuPos pos, 				 // [IN] the position of item
				VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
				VfxImageSrc &image				 // [OUT] the image resource
				);
	
	void onItemTap(VcpGroupListMenu *obj, VcpMenuPos pos)
	{
		if (pos.pos >= 0) { m_signalTap.emit(this, getAccntIndex(pos.pos)); }
	}
	VfxS32 getAccntIndex(const VfxS32 &index) const 
	{
		VFX_ASSERT(index < (VfxS32)m_nAccnt);
		return m_indexArray[index].index; 
	}
	void onLongTap(VcpGroupListMenu *obj, VcpMenuPos pos);
	void onMenuCallack(
			VcpMenuPopup *menu, 
			VcpMenuPopupEventEnum evt, 
			VcpMenuPopupItem *item);
	
	void onCmdCallback(VfxObject *obj, VfxId id);
	
protected:
	VfxU32  m_nAccnt;
	VfxS32  m_index;
	IndexTimestampStruct m_indexArray[MAX_ARRAY_BUFF];
};

#endif /* __VAPP_SYNC_ACCNT_LIST_MENU_H__ */

