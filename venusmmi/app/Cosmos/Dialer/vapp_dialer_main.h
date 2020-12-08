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
 *  vapp_dialer_main.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_DIALER_H__
#define __VAPP_DIALER_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_tabctrl_page.h"
#include "vapp_dialer_cp.h"
#include "vapp_dialer_cui.h"
#include "vapp_dialer_core.h"
#include "vapp_contact_list_ctrl.h"
#include "vapp_phb_list.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class VappDialerCalllogContactApp
 *****************************************************************************/
class VappDialerCalllogContactApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappDialerCalllogContactApp);

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
    void setSim(mmi_sim_enum type){m_sim = type;}
    mmi_sim_enum getSim(){return m_sim;}

private:
    mmi_sim_enum m_sim;
};


/***************************************************************************** 
 * Class VappDialerCalllogContactScreen
 *****************************************************************************/
class VappDialerCalllogContactScreen : public VfxMainScr
{
// Override
public:
    virtual void on1stReady();
};


/***************************************************************************** 
 * Class VappDialerCalllogContactPage
 *****************************************************************************/
class VappDialerCalllogContactPage : public VcpTabCtrlPage
{
// Override
public:
    virtual void onInit();
    virtual VfxPage *onCreateTabPage(VfxId tabId);

private:
    enum VcpPopupTypeEnum
    {
        DCC_PAGE_DIALER,
        DCC_PAGE_CALLLOG,
        DCC_PAGE_CONTACT,
        DCC_PAGE_END
    };
};


/***************************************************************************** 
 * Class VappDialerPage
 *****************************************************************************/
class VappDialerPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappDialerPage);

public:
    //override
    virtual void onInit();
    virtual void onDeinit();
    virtual mmi_ret onProc(mmi_event_struct *evt);
    virtual void onEntered();
    virtual void onEnter(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    VfxWChar *getDialerString() const;

private:
    VcpDialerPad *m_dialerPad;
#if defined (__MMI_DIALER_SLIM__) && defined (__MMI_MAINLCD_240X320__)
#else
    VcpListMenu *m_contactList;
    VappContactListMenuContentProvider *m_dataProvider;
#endif /* __MMI_DIALER_SLIM__ && __MMI_MAINLCD_240X320__ */
IDialerOperation *m_operate;

private:
    void placeComponent();
    void setComponentAction();
    void onPoundBtn(VcpDialerPad::VcpDialerButtonTypeEnum type, VfxWChar *str);
    VfxBool dialerProcessKeyCode(VfxKeyEvent &event);
    void onSaveToContact(VfxWChar *str);
    void onCallButtonClick(VcpGroupButton::VcpGroupButtonTypeEnum type);
#if defined (__MMI_DIALER_SLIM__) && defined (__MMI_MAINLCD_240X320__)
#else
    void onEditChange(VcpTextEditor *obj);
#endif /* __MMI_DIALER_SLIM_SEARCH__  && __MMI_MAINLCD_240X320__ */
    void onBeforeKeyInput(VcpTextEditor *editor, VfxKeyEvent &event, VfxBool &ret);
#if defined (__MMI_DIALER_SLIM__)  && defined ( __MMI_MAINLCD_240X320__)
#else
    void onItemClick(VcpListMenu * list, VfxU32 index);
#endif /* __MMI_DIALER_SLIM__  && __MMI_MAINLCD_240X320__ */
    void onBtnLongPress(VcpDialerPad::VcpDialerButtonTypeEnum btn, VfxWChar *ch);
    void voiceMailProcess();
    void onVoiceMailBtnClicked(VfxObject* obj, VfxId id);
#if defined (__MMI_DIALER_SLIM__) && defined (__MMI_MAINLCD_240X320__)
#else
    static void resetDialerList();
#endif /* __MMI_DIALER_SLIM__ && __MMI_MAINLCD_240X320__ */
    void regListener();
    void deregListener();
#if defined (__MMI_DIALER_SLIM__) && defined (__MMI_MAINLCD_240X320__)
#else
    static mmi_ret lisener(mmi_event_struct* evt);
    void onRefresh();
#endif /* __MMI_DIALER_SLIM__  && __MMI_MAINLCD_240X320__*/
    static mmi_ret refleshDialer(mmi_event_struct* evt);
    static mmi_ret refleshCallBtn(mmi_event_struct* evt);
    static mmi_ret onResetStorage(mmi_event_struct* evt);
	
    //VfxBool isNewCall();
};


/***************************************************************************** 
 * Class VappContactPageEx
 *****************************************************************************/
class VappContactPageEx : public VfxPage
{
// Override
public:
    virtual void onInit();

private:
    VappPhbListCp *phb_list;

private:
    void onItemClick(VcpGroupListMenu *obj, VcpMenuPos index);
};


#ifdef __cplusplus
extern "C"
{
#endif

extern MMI_ID vapp_dialer_classic_launch(void *param, U32 param_size);
extern MMI_ID vapp_dialer_launch_from_phb(void* args, U32 argSize);

#ifdef __cplusplus
}
#endif

#endif /* __VAPP_DIALER_H__ */

