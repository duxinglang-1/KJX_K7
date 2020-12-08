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
 *  vapp_dtcnt_prov.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file is used to define for data account provisioning
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_DTCNT_PROV_H__
#define __VAPP_DTCNT_PROV_H__

#ifdef __TCPIP__
//#ifdef __CCA_SUPPORT__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vapp_dtcnt_ui.h" // will get the data part to other file future
extern "C"
{
#include "DtcntSrvIprot.h"
}
#include "vapp_dtcnt.h" 

#ifdef __COSMOS_DTCNT_CCA_SUPPORT__

/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Class VappDtcntProvReplacePage
 *****************************************************************************/

/*
 * DESCRIPTION
 *  page for provisioning replace.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappDtcntProvReplacePage : public VfxPage, public IVcpListMenuContentProvider
{

public:
    VappDtcntProvReplacePage() : 
        m_replaceIndex(0),
        m_listMenu(NULL),
        m_listCntx(NULL),
        m_provEvt(NULL)
    {
    }
    VappDtcntProvReplacePage(srv_dtcnt_prov_ind_evt_struct *provEvt) :
        m_replaceIndex(0),
        m_listMenu(NULL),
        m_listCntx(NULL),
        m_provEvt(provEvt)
    {
    }
    virtual ~VappDtcntProvReplacePage() {}

public:
    enum {
        REPLACE_PAGE_ID_TOOLBAR_REPLACE = 0,
        REPLACE_PAGE_ID_TOOLBAR_CANCEL
    } ;

// override from Provider
public:
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    virtual VfxU32 getCount() const;

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const ;

// override
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onBack();
    virtual void onQueryRotateEx(VfxScreenRotateParam & param){};
    void provCallback(srv_dtcnt_prov_cnf_enum provType, VfxU8 idx);
#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__    
    void onSimChangeEvt(VfxBool flag, mmi_sim_enum sim);
#endif

// signal
protected:
    // this signal is used to post evt to parent id when single select,
    // or update first or second account when choose dual account
    void onItemStateChanged(
        VcpListMenu *sender, 
        VfxU32 index, 
        VcpListMenuItemStateEnum newState
    ); 
    void onToolbarTapped(
        VfxObject* sender,  // sender
        VfxId id            // id
    );
    
    void onExitInstallConfirm(
        VfxObject* obj, 
        VfxId id
    );

// method
public:
    void provReplaceRSP();

private:
    VfxU32 m_replaceIndex;
    VcpListMenu *m_listMenu;
    VappDtcntListDisplayContext *m_listCntx;
    srv_dtcnt_prov_ind_evt_struct *m_provEvt; // provisioning evt
};

/***************************************************************************** 
 * Class VappDtcntProvInstallPage
 *****************************************************************************/

/*
 * DESCRIPTION
 *  page for provisioning install.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappDtcntProvInstallPage : public VfxPage
{

public:
    VappDtcntProvInstallPage() :
        m_provEvt(NULL)
    {
    }
    VappDtcntProvInstallPage(srv_dtcnt_prov_ind_evt_struct *provEvt) :
        m_provEvt(provEvt)
    {
    }
    virtual ~VappDtcntProvInstallPage() {}

public:
    enum {
        INSTALL_PAGE_ID_TOOLBAR_INSTALL = 0,
        INSTALL_PAGE_ID_TOOLBAR_SKIP
    } ;

    enum {
#if defined(__MMI_MAINLCD_320X480__)
        LEFT_GAPS = 8,
        RIGHT_GAPS = 8,
        TOP_GAPS = 8,
        BOTTOM_GAPS = 8
#elif defined(__MMI_MAINLCD_480X800__)
        LEFT_GAPS = 14,
        RIGHT_GAPS = 14,
        TOP_GAPS = 14,
        BOTTOM_GAPS = 14
#else
        LEFT_GAPS = 5,
        RIGHT_GAPS = 5,
        TOP_GAPS = 5,
        BOTTOM_GAPS = 5
#endif
    } ;

public:    
    virtual void onInit();
    virtual void onDeinit();
    virtual void onBack();
    virtual void onQueryRotateEx(VfxScreenRotateParam & param){};

public:
    void prepareProfInfo(VfxWChar *info);
    void provInstallRSP();
    void provSkipRSP();
    void provCallback(srv_dtcnt_prov_cnf_enum provType, VfxU8 idx);

protected:
    void onToolbarTapped(
        VfxObject* sender,  // sender
        VfxId id            // id
    );

    void onExitInstallConfirm(
        VfxObject* obj, 
        VfxId id
    );

private:
    srv_dtcnt_prov_ind_evt_struct *m_provEvt; // provisioning evt    
} ;
/***************************************************************************** 
 * Class VappDtcntProvScr
 *****************************************************************************/

/*
 * DESCRIPTION
 *  main screen of data account provisioning.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappDtcntProvScr : public VfxMainScr
{

public:
    // default constructor just use for VFX_IMPLEMENT_CLASS
    VappDtcntProvScr() :
        m_cuiId(0),
        m_provEvt(NULL)
    {
    }
    VappDtcntProvScr(mmi_id cuiId, srv_dtcnt_prov_ind_evt_struct *provEvt) :
        m_cuiId(cuiId),
        m_provEvt(provEvt)
    {
    }
    virtual ~VappDtcntProvScr() {}

// override
public:
    virtual void onInit(); // prepage list data
    virtual void onDeinit();
    virtual void on1stReady(); // display list
    virtual void onQueryRotateEx(VfxScreenRotateParam & param){};

// method
public:
    mmi_id getCuiId() {return m_cuiId;}
    srv_dtcnt_prov_ind_evt_struct *getDtcntProvEvt() {return m_provEvt;}

private:
    mmi_id m_cuiId; // use this to record group id
    srv_dtcnt_prov_ind_evt_struct *m_provEvt; // provisioning evt
};


/***************************************************************************** 
 * Class VappDtcntProvCui
 *****************************************************************************/

/*
 * DESCRIPTION
 *  data account provisioning cui.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappDtcntProvCui : public VfxCui
{
    VFX_DECLARE_CLASS(VappDtcntProvCui);

protected:
    using VfxApp::onProcessClose;

public:  
// Constructor / Destructor
    VappDtcntProvCui() : m_needAbortFlag(VFX_TRUE), m_mainScr(NULL), m_provEvt(NULL) {}
    virtual ~VappDtcntProvCui() {}
    
// Override
public:
    // initial parameter and entry main src
    virtual void onRun(
        void *arg,          // parameter
        VfxU32 argSize      // parameter size  
    ); 
    virtual mmi_ret onProc(
        mmi_event_struct * evt
    );

    virtual void onInit();

    virtual void onDeinit();

    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);

// Method
public:
    srv_dtcnt_prov_ind_evt_struct *getDtcntProvEvt() { return m_provEvt;}
    void setNeedAbortFlag(VfxBool flag) {m_needAbortFlag = flag;}
    void provAbortRSP();

// Implementation

private:
    VfxBool m_needAbortFlag;
    VappDtcntProvScr *m_mainScr;
    srv_dtcnt_prov_ind_evt_struct *m_provEvt;
};
#endif /* __CCA_SUPPORT__ */
#endif /* __TCPIP__ */
#endif /* __VAPP_DTCNT_PROV_H__ */
