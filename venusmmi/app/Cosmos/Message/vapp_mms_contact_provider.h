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
 *  vapp_mms_contact_provider.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VENUS_MMI_MMS_CNTCT_PROVIDER_APP__
#define __VENUS_MMI_MMS_CNTCT_PROVIDER_APP__

#include "MMI_features.h"
#include "vapp_msg_features.h"

#ifdef __MMI_MMS_2__

#include "vfx_uc_include.h"
#include "vfx_mc_include.h"
#include "vapp_msg_contact_bar.h"

extern "C"
{
	#include "MmsSrvGprot.h"
}

class VappMmsContactProvider :public VappMsgContactProvider
{
	VFX_DECLARE_CLASS(VappMmsContactProvider);
//constructor
public:
    VappMmsContactProvider(srv_mms_func_mem_alloc_user_data alloc = NULL, srv_mms_func_mem_free free = NULL, void *user_data = NULL)
	{
		m_msgID = 0;
		m_alloc_fn = alloc;
		m_free_fn  =free;
		m_to_count = -1;
		m_cc_count = -1;
		m_bcc_count = -1;
	}

    void setMsgID(VfxU32 msgID);

    virtual VfxBool getContact(VappMsgContact& contact, VcpMenuPos index = VcpMenuPos(0, 0));
    virtual VfxU32 getCount(VfxU32 group) const;
	virtual VfxBool hasGroupHeader(VfxS32 group) const;
	virtual VfxU32 getGroupCount(void) const;
	virtual VfxBool isShowRecipientList(VfxWString& causeStr);
	virtual VfxBool getGroupPrefix(VfxU32 group, VfxWString& text) const;
	virtual VfxBool isShowMemberInBar(VfxU32 group) const;
	virtual VfxBool isResendFailed(void);
	virtual VfxBool getHeaderText(VfxS32 group, VfxWString& address) const;
	virtual void resendFailed(void);
	virtual void onDeinit(void);
	static void *allocMem(U32 size,void *user_data);
	static void freeMem(void *mem);
	VfxSignal0 m_signalMmsClose;
private:
    VfxU32 m_msgID; 
	srv_mms_func_mem_alloc_user_data m_alloc_fn;
	srv_mms_func_mem_free m_free_fn;
	p_srv_mms_msg_report_status *mms_msg_addr_info;
	VfxS32 m_to_count;
	VfxS32 m_cc_count;
	VfxS32 m_bcc_count;
	enum
	{
		VAPP_CONTACT_TYPE_TO = 0,
		VAPP_CONTACT_TYPE_CC,
		VAPP_CONTACT_TYPE_BCC
	};
};
#endif /*__MMI_MMS_2__*/
#endif /*__VENUS_MMI_MMS_CNTCT_PROVIDER_APP__*/
