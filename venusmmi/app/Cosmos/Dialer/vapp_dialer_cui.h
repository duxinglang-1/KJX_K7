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
 *  vapp_dialer_cui.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_DIALER_CUI_H__
#define __VAPP_DIALER_CUI_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_tabctrl_page.h"
#include "vapp_dialer_cp.h"
#include "vapp_dialer_core.h"
#include "vapp_dialer_gprot.h"
#include "vcui_dialer_gprot.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class VappDialerCUI
 *****************************************************************************/ 
class VappDialerCUI : public VfxCui
{
    VFX_DECLARE_CLASS(VappDialerCUI);

public:
    VappDialerCUI() : m_type(VCUI_DIALER_TYPE_CLASSIC), phb_data(NULL), dial_string(VFX_WSTR("")){}
    virtual void onRun(void* args, VfxU32 argSize);

public:
    void setCuiType(vcui_dialer_type_enum type){m_type = type;}
    vcui_dialer_type_enum getCuiType(){return m_type;}
    static void dialCallback(mmi_ucm_after_make_call_cb_struct* make_call_cb_para);

    void setType(vcui_dialer_type_enum type){m_type = type;}
    void setString(const VfxWString &str){dial_string = str;}
    const VfxWString& getString() const{return dial_string;}
    void setPhbData(void *data){phb_data = data;}
    void *getPhbData(){return phb_data;}

private:
    vcui_dialer_type_enum m_type;
    void*         phb_data;
    VfxWString    dial_string;
};


/***************************************************************************** 
 * Class VappDialerCuiMainScr
 *****************************************************************************/ 
class VappDialerCuiMainScr : public VfxMainScr
{
public:
    VappDialerCuiMainScr(){}
    VappDialerCuiMainScr(vcui_dialer_type_enum type) : m_dialerCuiType(type){}
    vcui_dialer_type_enum getType() const{return m_dialerCuiType;}

protected:
    virtual void on1stReady();
    virtual void on2ndReady();

private:
    vcui_dialer_type_enum m_dialerCuiType;
};


/***************************************************************************** 
 * Class VappDialerCuiPage
 *****************************************************************************/
class VappDialerCuiPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappDialerCuiPage);

public:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEntered();
    virtual void onEnter(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

public:
    VcpDialerPad     *m_dialPad;

private:
    IDialerOperation *m_operate;

private:
    void setComponentAction();
    void onCallButtonClick(VcpGroupButton::VcpGroupButtonTypeEnum type);
    void onDialerStringChange(VcpTextEditor *edit_box);
    static mmi_ret refleshCallBtn(mmi_event_struct* evt);
};


#ifdef __cplusplus
extern "C"
{
#endif

mmi_id vcui_dialer_create(mmi_id parent_id);
mmi_id vcui_dialer_create_ex(mmi_id parent_id, vcui_dialer_type_enum type);
void vcui_dialer_run(mmi_id cui_id);
void vcui_dialer_close(mmi_id cui_id);
void vcui_dialer_set_dial_string(mmi_id this_gid, const VfxWString &string);
const VfxWString &vcui_dialer_get_dial_string(mmi_id this_gid);
void vcui_dialer_set_phb_data(mmi_id this_gid, void *phb_data);
void *vcui_dialer_get_phb_data(mmi_id this_gid);

#ifdef __cplusplus
}
#endif

#endif /* __VAPP_DIALER_CUI_H__ */

