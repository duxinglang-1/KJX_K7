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
 *  vapp_callset_cb.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  	Call Barr
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_CALLSET_CB_H__
#define __VAPP_CALLSET_CB_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMIDataType.h" /* mmi_id */

#include "vfx_datatype.h"
#include "vfx_page.h"

#include "vapp_callset.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/***************************************************************************** 
 * Class VappCallSetPageCb
 *****************************************************************************/
class VappCallSetPageCb : public VappCallSetAsyncPage
{

public:
    virtual void onResult(mmi_event_struct *info);

// Override
protected:
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);

private:
    void onSwitch(VcpFormItemSwitchCell* item, VfxId id, VfxBool state);
    void onToolBarTapped(VfxObject* sender, VfxId id);
    void queryData(void);
    VfxBool isOn(
        srv_ss_call_bar_type_enum type, 
        srv_ss_call_type_enum call_type,
        srv_ss_call_bar_rsp_struct *rsp);
	void disableAll(void);
	VfxU32 nextState(VfxU32 currState);

private:
    enum
    {
        STATE_GET_BAOC = STATE_NONE + 1,
        STATE_GET_BOIC,
        STATE_GET_BOICEXHC,
        STATE_GET_BAIC,
        STATE_GET_BAICROAM,
        STATE_SET_BAOC,
        STATE_SET_BOIC,
        STATE_SET_BOICEXHC,
        STATE_SET_BAIC,
        STATE_SET_BAICROAM,
        STATE_INVALID
    };

    VcpFormItemSwitchCell *m_baoc;
    VcpFormItemSwitchCell *m_boic;
    VcpFormItemSwitchCell *m_boicExHc;
    VcpFormItemSwitchCell *m_baic;
    VcpFormItemSwitchCell *m_baicRoam;
};


/***************************************************************************** 
 * Class VappCallSetPageCbPasswd
 *****************************************************************************/
class VappCallSetPageCbPasswd : public VappCallSetPageCommonInputAsync
{

public:
    virtual void onResult(mmi_event_struct *info);

// Override
protected:
    virtual void onInit();
    virtual void onExit(VfxBool isBackward);
    virtual void onTextChanged(VcpTextEditor* editor);
    virtual void onFuncBtnClicked(VfxObject* sender, VfxId id);

private:
    enum
    {
        STATE_ACT = STATE_NONE + 1,
        STATE_INVALID
    };

};


/***************************************************************************** 
 * Class VappCallSetPageCbChangePasswd
 *****************************************************************************/
class VappCallSetPageCbChangePasswd : public VappCallSetAsyncPage
{

// Override
public:
    virtual void onResult(mmi_event_struct *info);

// Override
protected:
    virtual void onInit();
    virtual void onExit(VfxBool isBackward);
    virtual void onTextChanged(VcpTextEditor* editor);

private:
    enum
    {
        STATE_ACT = STATE_NONE + 1,
        STATE_INVALID
    };

    enum
    {
        STATE_EDIT_INVALID = 0x00,
        STATE_EDIT_VALID_1 = 0x01,
        STATE_EDIT_VALID_2 = 0x02,
        STATE_EDIT_VALID_3 = 0x04,
    };
#define STATE_EDIT_VALID_ALL (STATE_EDIT_VALID_1|STATE_EDIT_VALID_2|STATE_EDIT_VALID_3)

    void onFuncBtnClicked(VfxObject* sender, VfxId id);
	void clearInput(void);
	void onDiffInputConfirmed(VfxObject *obj, VfxId id);
	VfxBool checkPwd(void);

	
    VcpTextEditor *m_oldPass;
    VcpTextEditor *m_newPass;
    VcpTextEditor *m_cnfPass;
    VcpFunctionBar *m_oldFb;
    VcpFunctionBar *m_newFb;
    VcpFunctionBar *m_cnfFb;

    VcpToolBar *m_toolBar;

    VfxU32 m_stateEdit;

};

#endif /* __VAPP_CALLSET_CB_H__ */

