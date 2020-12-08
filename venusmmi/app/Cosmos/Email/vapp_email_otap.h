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
 *  Vapp_email_otap.h
 *
 * Project:
 * --------
 *  COSMOS Email Account OTAP
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_EMAIL_ATAP_H
#define VAPP_EMAIL_ATAP_H

#include "vfx_mc_include.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"

extern "C"{
#include "EmailSrvGprot.h"
}

class VappEmailOtap : public VfxObject
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappEmailOtap);

public:
    void handleNextProf(void);

    static void sysInit(void);
    static void mainProc(VfxU32 profNum);

public:
    srv_email_otap_prof_info_struct currProfInfo;
    srv_email_acct_info_struct currAcctInfo;
    
    EMAIL_SRV_HANDLE srvHandle;
    EMAIL_OTAP_HANDLE otapHandle;
    EMAIL_ACCT_HANDLE acctHandle;

    VfxU32 profIndex;
    VfxU32 profNum;
    VfxU32 acctNum;

    mmi_id cuiId;
    WCHAR acctName[SRV_EMAIL_MAX_ACCT_NAME_LEN + 1];
};


///////////////////////////////////////////////////
//////////////////// OTAP CUI /////////////////////
///////////////////////////////////////////////////
extern "C"
{
typedef enum
{
    EVT_ID_CUI_EMAIL_OTAP_BEGIN = VCUI_EMAIL_OTAP,

    EVT_ID_CUI_EMAIL_OTAP_RESULT, 

    EVT_ID_CUI_EMAIL_OTAP_TOTAL
} cui_email_otap_event_enum;

typedef struct 
{
    MMI_EVT_GROUP_PARAM_HEADER
} cui_email_otap_result_event_struct;

mmi_id cui_email_otap_create(mmi_id parent_id);
void cui_email_otap_run(mmi_id cui_id);
void cui_email_otap_close(mmi_id cui_id);
}

class VappEmailOtapCfmPop: public VcpConfirmPopup
{
protected:
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
};


///////////////////////////////////////////////////
///////////////// OTAP CUI CLASS //////////////////
///////////////////////////////////////////////////

class VcuiEmailOtapCui : public VfxCui
{
    VFX_DECLARE_CLASS(VcuiEmailOtapCui);

public:
    virtual void onRun(void* args, VfxU32 argSize);
};

class VappEmailOtapScrn : public VfxMainScr
{
public:
    VappEmailOtapScrn();
    virtual ~VappEmailOtapScrn();
    virtual void on1stReady();
    void handleBackKey();
    void setNoDestroy(void);
    void onConfirmChoosed(VfxObject *obj, VfxId id);
    
public:
    static void onOtapSaveProc(
        srv_email_result_struct *result,
        EMAIL_ACCT_ID,
        EMAIL_REQ_ID,
        void*);

public:
    VfxBool needDestroy;
    VfxBool isReplaceAcct;
    VcpIndicatorPopup *indicator_pop;
};

class VappEmailOtapProfInfoPage: public VfxPage
{
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
    virtual void onInit(void);    
    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {
    }
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

private:
    void onToolBarClick(VfxObject *obj, VfxId id);

    // compose the info to show
    void prepareProfInfo(VcpTextView *text);
};

class VappEmailOtapAcctListPage
    : public VfxPage, public IVcpListMenuContentProvider
{
public:
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {
    }
    virtual VfxBool getItemText(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxWString &text,
        VcpListMenuTextColorEnum &color);
    virtual VfxU32 getCount() const;
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

private:
    void initData();
    void onItemStateChanged(
        VcpListMenu *sender,
        VfxU32 index,
        VcpListMenuItemStateEnum newState);
    void onToolBarClick(VfxObject *obj, VfxId id);

private:
    VcpListMenu *m_menu;
    VcpToolBar *m_toolBar;
    VfxU32 m_selectedIndex;
    VfxU32 m_acctCount;
    EMAIL_ACCT_ID m_acctId[MMI_EMAIL_MAX_ACCTS];
};

#endif
