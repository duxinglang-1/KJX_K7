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
 *  vapp_callset_cf.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Call forward UE flow
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_CALLSET_CF_H__
#define __VAPP_CALLSET_CF_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMIDataType.h" /* mmi_id */

extern "C" 
{
#include "CallSetSrvGprot.h"
#include "SsSrvGprot.h"
}


#include "vfx_datatype.h"
#include "vfx_page.h"


#include "vcp_list_menu.h"

#include "vapp_callset.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class VappCallSetPageCf
 *****************************************************************************/
class VappCallSetPageCf : public VappCallSetAsyncPage
{

public:
	VappCallSetPageCf();
    virtual void onResult(mmi_event_struct *info);

// Override
protected:
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);

private:
    void onItemTap(VcpFormItemCell *item, VfxId id);
    void onSwitch(VcpFormItemSwitchCell* item, VfxId id, VfxBool state);
    void onToolBarTapped(VfxObject* sender, VfxId id);
    void queryData(void);
    void deriveRes(srv_ss_call_forward_rsp_struct *rsp, VcpFormItemSwitchCell *swh, VfxU32 *time);
    void enableItems(void);
	void disableSwitchItem(VcpFormItemSwitchCell *cell, VfxWString &text);
	VfxU32 nextState(VfxU32 currState);
	void nextQuery(VfxU32 state);
	VfxBool checkWaitState(void);

    enum
    {
        STATE_GET_CFU = STATE_NONE + 1,
        STATE_GET_CFNRC,
        STATE_GET_CFNRY,
        STATE_GET_CFB,
        STATE_SET_CFU,
        STATE_SET_CFNRC,
        STATE_SET_CFNRY,
        STATE_SET_CFB,
        STATE_INVALID
    };

    VcpFormItemSwitchCell *m_cfu;
    VcpFormItemSwitchCell *m_cfnrc;
    VcpFormItemSwitchCell *m_cfnry;
    VcpFormItemLauncherCell *m_cfnryTime;
    VcpFormItemSwitchCell *m_cfb;

    VfxU32 m_waitState;

public:
	static const VfxResId s_callTypeRes[SRV_SS_ALL_CALL];
	static void sendSSReq(srv_ss_action_type_enum action, const VfxWChar *numPtr, VfxU32 noReplyTime);
};


/***************************************************************************** 
 * Class VappCallSetPageCfNum
 *****************************************************************************/
class VappCallSetPageCfNum : public VfxPage
{

// Override
protected:
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);

private:
    void onItemTap(VcpFormItemCell *item, VfxId id);
    void updateForm(void);

    VcpForm *m_form;
};


/***************************************************************************** 
 * Class VappCallSetPageCfNumEdit
 *****************************************************************************/
class VappCallSetPageCfNumEdit : public VappCallSetPageCommonInputAsync
{

public:
    virtual void onResult(mmi_event_struct *info);

// Override
protected:
    virtual void onInit();
    virtual void onExit(VfxBool isBackward);
    virtual mmi_ret onProc(mmi_event_struct *evt);
    virtual void onFuncBtnClicked(VfxObject* sender, VfxId id);

private:
    enum
    {
        STATE_GET = STATE_NONE + 1,
        STATE_SET,
        STATE_INVALID
    };

    void onConfirmClicked(VfxObject* sender, VfxId id);

    mmi_id m_phbId;

};


/***************************************************************************** 
 * Class VappCallSetPageCfNumEdit
 *****************************************************************************/
class VappCallSetPageCfnryTime : public VappCallSetAsyncPage, public IVcpListMenuContentProvider
{

// Override IVcpListMenuContentProvider
public:
    virtual VfxBool getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );
    virtual VfxU32 getCount() const;
    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   
        ) const;

// Override VappCallSetPageCommonInputAsync
public:
    virtual void onResult(mmi_event_struct *info);

// Override VappCallSetPageCommonInputAsync
protected:
    virtual void onInit();
    virtual void onExit(VfxBool isBackward);

private:
    enum
    {
        STATE_GET = STATE_NONE + 1,
        STATE_SET,
        STATE_INVALID
    };

    void onSelect(VcpListMenu* menu, VfxU32 index, VcpListMenuItemStateEnum state);
    void onConfirmClicked(VfxObject* sender, VfxId id);


    VfxU32 m_activateIndex;
    VfxU32 m_count;

};

#endif /* __VAPP_CALLSET_CF_H__ */

