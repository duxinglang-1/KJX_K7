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
 *  vapp_sync_remote_cui.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VCUI_SYNC_REMOTE_OTA_H__
#define __VCUI_SYNC_REMOTE_OTA_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "syncml_common_customize.h"

#include "vfx_cui.h"
#include "vfx_datatype.h"
#include "vfx_main_scr.h"
#include "vfx_page.h"
#include "vfx_signal.h"

#include "vcp_list_menu.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class VcuiSyncRemoteOta
 *****************************************************************************/
class VcuiSyncRemoteOta: public VfxCui
{
	VFX_DECLARE_CLASS(VcuiSyncRemoteOta);

public:
	VcuiSyncRemoteOta() : m_total(0) {}

	void setTotal(const VfxU16 &total) { m_total = total; }
	
protected:
	void onRun(void* args, VfxU32 argSize);
    VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);
	
private:
	VfxU16 m_total;
};


/***************************************************************************** 
 * Class VcuiSyncRemoteOtaScr
 *****************************************************************************/
class VcuiSyncRemoteOtaScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VcuiSyncRemoteOtaScr);

public:
    VcuiSyncRemoteOtaScr() : m_total(0) {};
	VcuiSyncRemoteOtaScr(const VfxU16 &total) : m_total(total) {};
    virtual ~VcuiSyncRemoteOtaScr() {};
    virtual void on1stReady();
	
private:
	VfxU16 m_total;
};


/***************************************************************************** 
 * Class VcuiSyncRemoteOtaInstallPage
 *****************************************************************************/
class VcpTextView;
class VcuiSyncRemoteOtaInstallPage: public VfxPage
{
    VFX_DECLARE_CLASS(VcuiSyncRemoteOtaInstallPage);

public:
	VcuiSyncRemoteOtaInstallPage();
	VcuiSyncRemoteOtaInstallPage(const VfxU16 &total);

public:
	enum
	{
#ifdef __MMI_MAINLCD_480X800__	/*WVGA*/
		TEXT_MARGIN = 14
#elif defined  __MMI_MAINLCD_320X480__ /* HVGA */
		TEXT_MARGIN = 8
#elif (defined  __MMI_MAINLCD_240X320__ || defined  __MMI_MAINLCD_240X400__ )/*QVGA * WQVGA*/
		TEXT_MARGIN = 5
#else //temp value
		TEXT_MARGIN = 5
#endif

	};
	
protected:
	void onInit(void);
	void onDeinit(void);
	void onBack(void);
	VfxScrRotateTypeEnum onQueryRotate(const VfxScreenRotateParam &param);
	
private:
    void onToolBarClick(VfxObject *obj, VfxId id);
    void fillTextInfo(void);
	void install(VfxU8 index, U16 status);
	VfxS8 findEmptySlot(void);
	
	void onQuitAskCallback(void);
	void onSelectCallback(VfxU8 index);
	void onBackConfirm(VfxObject* obj, VfxId id);
	void closeActiveAccnt(VfxU32 index);
	
private:
	VcpTextView *m_text;
	VfxU16 m_curr;
	VfxU16 m_dest;
	VfxU16 m_total;
	VfxBool m_bUpdate;
	VfxBool m_isSelfClose;
};


/***************************************************************************** 
 * Class VcuiSyncRemoteOtapAcctListPage
 *****************************************************************************/
class VcuiSyncRemoteOtapAcctListPage: public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VcuiSyncRemoteOtapAcctListPage);
    
public:
	VcuiSyncRemoteOtapAcctListPage();

	VfxSignal1<VfxU8>	m_signalSelect;
	VfxSignal0			m_signalQuitAsk;
	
protected:
    void onInit();
    void onEnter(VfxBool isBackward);
	void onBack(void);
    void onQueryRotateEx(VfxScreenRotateParam &param);
    //void setMenu(VcpListMenu *menu) {menu = m_menu;}
    VfxBool getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color);
    VfxU32 getCount() const { 	return m_total; }
    VcpListMenuItemStateEnum getItemState(VfxU32 index) const;

private:
    void onItemStateChanged(VcpListMenu *sender, VfxU32 index, VcpListMenuItemStateEnum newState);
    void onToolBarClick(VfxObject *obj, VfxId id);
	VfxU32 getTotalAccnt(void);
	
private:
    VcpListMenu *m_menu;
    VfxU32 m_selectedIndex;
    VfxU32 m_arrIdx[5];
	VfxU8  m_total;
};

#endif /* __VCUI_SYNC_REMOTE_OTA_H__ */

