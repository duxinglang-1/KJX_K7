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
 *  vapp_sync_now.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_SYNC_NOW_H__
#define __VAPP_SYNC_NOW_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMIDataType.h"
 
#include "vfx_datatype.h"
#include "vfx_weak_ptr.h"
#include "vfx_app_scr.h"
#include "vcp_indicator_popup.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
class VfxWString;
class VfxKeyEvent;
class VappSyncNowProgPopup : public VcpIndicatorPopup
{
public:
	VappSyncNowProgPopup() : m_bDisable(VFX_FALSE){}
	
	void disableButton(void);
	void setProcessText(const VfxWString &accntName, const VfxWString &text);
	
protected:
	VfxBool onKeyInput(VfxKeyEvent &event);
	
private:
	VfxBool m_bDisable;
};
 
/***************************************************************************** 
 * Class VappSyncNowScr
 *****************************************************************************/
class VcpStatusIconBar;
class VappSyncNowScr : public VfxAppScr
{
	VFX_DECLARE_CLASS(VappSyncNowScr);

// Override
public:
	VappSyncNowScr();
	VappSyncNowScr(const VfxU16 &sync, const VfxS32 &index, const void* usr_data = 0);
	virtual ~VappSyncNowScr(){};
	virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    );
    virtual void onRotate(const VfxScreenRotateParam & param);
	
	mmi_ret onSrvEvt(mmi_event_struct *evt);

  void abortSync(void) { onCancel(this, 0); }
  
protected:
	virtual void onInit(void);
	virtual void onDeinit(void);
	virtual void onEnter(VfxBool isBackward);
	virtual void onBack();
	
private:
	void createIndPopup(void);
	void onCancel(VfxObject* obj, VfxFloat id);
	mmi_ret onFinish(mmi_event_struct *evt);
	mmi_ret onProgress(mmi_event_struct *evt);
	void regEvtHdlr(void);
	void deregEvtHdlr(void);
	VfxWString getAccntName(void) const;
    VfxScrRotateTypeEnum m_direction;
	
private:
	VcpStatusIconBar *m_statusBar;
	VfxWeakPtr<VappSyncNowProgPopup> m_syncPopupWeakPtr;

	VfxU16 m_sync;
	VfxS32 m_index;
	const void *m_data;
	
	static mmi_ret onSyncEvt(mmi_event_struct *evt);
	static MMI_BOOL checkConnCallback(U32 net_id);
};


#endif /* __VAPP_SYNC_NOW_H__ */

