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
 *  vapp_dm_session.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Device management download header file.
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_DM_DL_H__
#define __VAPP_DM_DL_H__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_tabctrl_page.h"
#include "vcp_list_menu.h"
extern "C"
{
#include "DmSrvIprot.h"
}
/***************************************************************************** 
 * Define
 *****************************************************************************/
/***************************************************************************** 
 * Function
 *****************************************************************************/

/***************************************************************************** 
 * Class VappDmDlProgressMainScrn
 *****************************************************************************/

class VappDmDlProgressMainScrn : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappDmDlProgressMainScrn);
// Constructor / Destructor
public:
    VappDmDlProgressMainScrn();
    ~VappDmDlProgressMainScrn() {}

// Method
public:
    virtual void on1stReady();
    void update(
        VfxFloat percent
    );
    void onCanceled(
        VfxObject* obj,
        VfxFloat curr_progress
    );

private:
    VcpIndicatorPopup *m_popup;
};


/***************************************************************************** 
 * Class VappDmDlProgress
 *****************************************************************************/

class VappDmDlProgress : public VfxApp
{
    VFX_DECLARE_CLASS(VappDmDlProgress);
// Constructor / Destructor
public:
    VappDmDlProgress() {}
    ~VappDmDlProgress() {}

// Method
public:
    void onRun(
        void *args,
        VfxU32 argSize
    );

    void update(
        VfxFloat percent
    );
private:
    VappDmDlProgressMainScrn *m_mainScrn;
};


/***************************************************************************** 
 * Class VappDmDlCtrler
 *****************************************************************************/

class VappDmDlCtrler : public VfxObject
{
    VFX_DECLARE_CLASS(VappDmDlCtrler);
// Constructor / Destructor
public:
    VappDmDlCtrler();
    ~VappDmDlCtrler() {}

// Method
public:
    void dlStartEvtHdlr(
        MMI_BOOL is_resume,
        MMI_BOOL auto_resume
    );

    void displayAutoResume();

    void displayResumeCnf();

    static void resumeCnfHdlr(
        VfxId id,
        void *userData
    );

    void dlProgressHdlr(
        U32 accSize,
        U32 totalSize
    );

    void dlFinishHdlr(
        srv_dm_app_adp_dl_finish_cause_enum cause
    );

// Variable
private:
    VfxWeakPtr<VappDmDlProgress> m_dlProgress;
    MMI_ID m_progressGId;
};

#endif /* __VAPP_DM_DL_H__ */

