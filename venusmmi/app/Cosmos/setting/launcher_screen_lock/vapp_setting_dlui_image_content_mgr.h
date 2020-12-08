/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_setting_dlui_image_content_mgr.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the dlui provider.
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

#ifndef VAPP_SETTING_DLUI_IMG_CONTENT_MGR_H
#define VAPP_SETTING_DLUI_IMG_CONTENT_MGR_H

#include "MMI_features.h"

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
/*****************************************************************************
 * Define
 *****************************************************************************/

struct DluiImgBufItem
{
	VfxS32 group;
	VfxS32 pos;
	VfxFrame* pThumbFrame;
	VfxFrame ** pShotFrame;
	DluiImgBufItem*  next;
}; 

class DluiImgBufMgr: public VfxObject
{
public:
	DluiImgBufMgr(): m_head(NULL), m_tail(NULL){}

	virtual ~DluiImgBufMgr()
	{
		while (m_head)
		{
			DluiImgBufItem* freeItem = m_head;
			m_head = m_head->next;
			
			VFX_FREE_MEM(freeItem);
		}
	}
	
	void addThumbFrame(VfxS32 g, VfxS32 p, VfxFrame* thumb);

	void addShotFrame(VfxS32 g, VfxS32 p, VfxFrame** shot);

	VfxFrame* getThumbForFree(VfxS32 g, VfxS32 p);

	VfxFrame** getShotForFree(VfxS32 g, VfxS32 p);
	
private:
 	DluiImgBufItem* _isItemExist(VfxS32 g, VfxS32 p);
	
	VfxFrame* _getThumbFrame(VfxS32 g, VfxS32 p);

	VfxFrame** _getShotFrame(VfxS32 g, VfxS32 p);
	
	DluiImgBufItem* _createItem(VfxS32 g, VfxS32 p);
	
private:
	DluiImgBufItem* m_head;
	DluiImgBufItem* m_tail;
};
#endif // VAPP_SETTING_DLUI_IMG_CONTENT_MGR_H
