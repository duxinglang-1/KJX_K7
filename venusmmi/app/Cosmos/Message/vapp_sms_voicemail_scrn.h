/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_sms_voicemail_scrn.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  SMS setting for Venus UI
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
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifndef __VAPP_SMS_VOICEMAIL_SCRN_H__
#define __VAPP_SMS_VOICEMAIL_SCRN_H__
#include "MMI_features.h"
#include "vcp_include.h"
#include "vcp_form.h"
#include "vfx_mc_include.h"
#include "vapp_sms_util.h"
#include "vapp_sms_voicemail_core.h"

/***************************************************************************** 
 * Class 
 *****************************************************************************/

/***************************************************************************** 
 * Class VappVmServerListPage
 *****************************************************************************/
class VappVmServerListPage: public VfxPage, public IVcpListMenuContentProvider
{
    //VFX_DECLARE_CLASS(VappVmServerListPage);

    typedef VappVmServerListPage      Self;
    typedef VfxPage                   Super;

public:
    VappVmServerListPage(){}
    VappVmServerListPage(srv_sms_sim_enum simId): m_simId(simId){}
    virtual VfxU32 getCount() const;
    virtual VfxBool getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );
    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        );

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
    void onVmListItemTapped(VcpListMenu *sender, VfxU32 index);
    void onVmServerChanged(VfxObject *sender, VfxWString name, VfxWString number, VfxU8 index);
    void onCallButtonClicked(VcpListMenu *sender, VfxU32 index);

private:
    VcpListMenu *m_listMenu;
    VoicemailServerList *m_vmList;
    srv_sms_sim_enum m_simId;
};


/***************************************************************************** 
 * Class VappVmServerEditPage
 *****************************************************************************/
class VappVmServerEditPage: public VfxPage
{
    //VFX_DECLARE_CLASS(VappVmServerEditPage);

    typedef VappVmServerEditPage      Self;
    typedef VfxPage                   Super;

public:
    typedef struct
    {
        srv_sms_sim_enum simId;
        VfxU8 vmIndex;
    }VappSmsVmEditInitData;

public:
    VappVmServerEditPage(){}
    VappVmServerEditPage(VappSmsVmEditInitData data): 
        m_form(NULL),
        m_toolBar(NULL),
        m_vm(NULL),
        m_simId(data.simId),
        m_index(data.vmIndex)
    {
    }

protected:
    virtual void onInit();
    virtual void onDeinit();
    void onFunctionBarClicked(VfxObject *sender, VfxId id);
    void onBarSaveCommond();
    void onSetTextEditorState(VfxId id,VfxBool activated);
    void onTextActivated(VcpTextEditor *sender, VfxBool  activated);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

public:
    VfxSignal4<VfxObject*,
        VfxWString, // name
        VfxWString,  // number
        VfxU8 // Server index
    > m_signalVmServerChanged;

private:
    void onToolbarTapped(VfxObject *sender, VfxId id);

private:
    enum
    {
        ITEM_ID_TOOLBAR_SAVE,
        ITEM_ID_TOOLBAR_CANCLE,
        ITEM_ID_VM_NAME,
        ITEM_ID_VM_NUMBER,
        ITEM_ID_VM_EDITOR_NAME,
        ITEM_ID_VM_EDITOR_NUMBER,
        ITEM_ID_FUNCBAR_PREV,
        ITEM_ID_FUNCBAR_NEXT,
        ITEM_ID_FUNCBAR_SAVE,
        TTEM_ID_TOTAL
    };

	VcpForm *m_form;
    VcpToolBar *m_toolBar;
    VoicemailServer *m_vm;
    srv_sms_sim_enum m_simId;
    VfxU8 m_index;
};

#endif /* __VAPP_SMS_VOICEMAIL_SCRN_H__ */
