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
 *  vapp_sync_phone_accnt_list.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_SYNC_PHONE_ACCNT_LIST_H__
#define __VAPP_SYNC_PHONE_ACCNT_LIST_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMIDataType.h"
#include "BtcmSrvGprot.h"

#include "vfx_datatype.h"
#include "vfx_page.h"
#include "vapp_sync_accnt_list_menu.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class VappSyncPhoneAccntListMenu
 *****************************************************************************/
class VfxWString;
class VappSyncPhoneAccntListMenu : public VappSyncAccntListMenu
{
	VFX_DECLARE_CLASS(VappSyncPhoneAccntListMenu);

public:
	VappSyncPhoneAccntListMenu(){}
	~VappSyncPhoneAccntListMenu(){}
	
protected:
	VfxBool getHeaderText(VfxWString &text);
	VfxBool getText(VfxS32 index, VfxWString &text);
	VfxU32 getUpdatedCount(void);
        VfxBool isShowIcon(const VfxS32 &index);
	VfxBool getMenuEmptyText(
		VfxWString &text,				 // [OUT] the text resource
		VcpListMenuTextColorEnum &color  // [OUT] the text color
		);
};


/***************************************************************************** 
 * Class VappSyncPhoneAccntListPage
 *****************************************************************************/
class VfxObject;
class VappSyncPhoneAccntListPage : public VfxPage
{
	VFX_DECLARE_CLASS(VappSyncPhoneAccntListPage);

public:
	VappSyncPhoneAccntListPage(const VfxBool &bTitle = VFX_FALSE);
	~VappSyncPhoneAccntListPage(){}
	
protected:
	void onInit(void);
	void onEnter(VfxBool isBackward);
	
private:
	void onToolbarClick(VfxObject* obj, VfxId id);
	void onTapCallback(VfxObject *obj, VfxS32 index);
	void onActionCallback(VfxObject *obj, VfxId action, VfxS32 index);
	void startSync(const VfxS32 &index);	
	void startNewSync(void);
	void viewLog(const VfxS32 &index);
	void onSelectDone(VfxObject *obj, VfxU32 dbMask);
	mmi_ret onProc(mmi_event_struct *evt);

private:
	VfxU32 getTotalCount(void);
	VfxBool isCodMatch(const VfxU32 &device_cod, const VfxU32 &specific_cod);

private:
	VappSyncPhoneAccntListMenu *m_list;
	VfxBool m_hasTitle;
	VfxS32 m_activeIndex;
  srv_bt_cm_bt_addr m_selBtAddr;

public:
	static VfxS32 locateAccntIndex(VfxBool &isNew, void *btAddr);
};

#endif /* __VAPP_SYNC_PHONE_ACCNT_LIST_H__ */

